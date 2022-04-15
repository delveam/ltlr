#include "collider.h"
#include "components.h"
#include "context.h"
#include "entities.h"
#include "raymath.h"
#include "systems.h"
#include <assert.h>

#define REQUIRE_DEPS(mDependencies) if ((scene->components.tags[entity] & (mDependencies)) != (mDependencies)) return
#define ENTITY_HAS_DEPS(mEntity, mDependencies) ((scene->components.tags[mEntity] & (mDependencies)) == (mDependencies))
#define GET_COMPONENT(mValue, mEntity) SCENE_GET_COMPONENT_PTR(scene, mEntity, mValue)

typedef struct
{
    bool xAxisResolved;
    bool yAxisResolved;
} CollisionResult;

#define COLLISION_RESULT_NONE (CollisionResult) { false, false }

typedef struct
{
    usize entity;
    usize otherEntity;
    Rectangle aabb;
    Rectangle otherAabb;
    Vector2 resolution;
} CollisionParams;

static i8 sign(const f32 value)
{
    if (value < 0)
    {
        return  -1;
    }

    if (value > 0)
    {
        return  1;
    }

    return 0;
}

void SSmoothUpdate(Scene* scene, const usize entity)
{
    REQUIRE_DEPS(TAG_POSITION | TAG_SMOOTH);

    const CPosition* position = GET_COMPONENT(position, entity);
    CSmooth* smooth = GET_COMPONENT(smooth, entity);

    smooth->previous = position->value;
}

void SKineticUpdate(Scene* scene, const usize entity)
{
    REQUIRE_DEPS(TAG_POSITION | TAG_KINETIC);

    CPosition* position = GET_COMPONENT(position, entity);
    CKinetic* kinetic = GET_COMPONENT(kinetic, entity);

    kinetic->velocity.x += kinetic->acceleration.x * CTX_DT;
    kinetic->velocity.y += kinetic->acceleration.y * CTX_DT;

    position->value.x += kinetic->velocity.x * CTX_DT;
    position->value.y += kinetic->velocity.y * CTX_DT;
}

void SCollisionUpdate(Scene* scene, const usize entity)
{
    REQUIRE_DEPS(TAG_POSITION | TAG_DIMENSION | TAG_COLLIDER);

    const CPosition* position = GET_COMPONENT(position, entity);
    const CDimension* dimension = GET_COMPONENT(dimension, entity);
    const CCollider* collider = GET_COMPONENT(collider, entity);

    Rectangle aabb = (Rectangle)
    {
        .x = position->value.x,
        .y = position->value.y,
        .width = dimension->width,
        .height = dimension->height
    };

    for (usize i = 0; i < SceneGetEntityCount(scene); ++i)
    {
        if (i == entity || !ENTITY_HAS_DEPS(i, TAG_POSITION | TAG_DIMENSION | TAG_COLLIDER))
        {
            continue;
        }

        const CPosition* otherPosition = GET_COMPONENT(otherPosition, i);
        const CDimension* otherDimensions = GET_COMPONENT(otherDimensions, i);
        const CCollider* otherCollider = GET_COMPONENT(otherCollider, i);

        if ((collider->mask & otherCollider->layer) == 0)
        {
            continue;
        }

        Rectangle otherAabb = (Rectangle)
        {
            .x = otherPosition->value.x,
            .y = otherPosition->value.y,
            .width = otherDimensions->width,
            .height = otherDimensions->height
        };

        if (CheckCollisionRecs(aabb, otherAabb))
        {
            Event event;
            EventCollisionInit(&event, entity, i);
            SceneRaiseEvent(scene, &event);
        }
    }
}

static Vector2 ExtractResolution(const Vector2 resolution, const u64 layers)
{
    Vector2 result = VECTOR2_ZERO;

    if ((layers & layerLeft) != 0 && resolution.x < 0)
    {
        result.x = resolution.x;
    }

    if ((layers & layerRight) != 0 && resolution.x > 0)
    {
        result.x = resolution.x;
    }

    if ((layers & layerUp) != 0 && resolution.y < 0)
    {
        result.y = resolution.y;
    }

    if ((layers & layerDown) != 0 && resolution.y > 0)
    {
        result.y = resolution.y;
    }

    return result;
}

void SPlayerInputUpdate(Scene* scene, const usize entity)
{
    REQUIRE_DEPS(TAG_PLAYER | TAG_KINETIC);

    CPlayer* player = GET_COMPONENT(player, entity);
    CKinetic* kinetic = GET_COMPONENT(kinetic, entity);

    if (player->dead)
    {
        return;
    }

    bool coyoteTimeActive = player->coyoteTimer < player->coyoteDuration;

    // Maintenance.
    {
        if (player->grounded)
        {
            kinetic->velocity.y = 0;
            player->jumping = false;
        }

        Vector2 gravityForce = Vector2Create(0, player->defaultGravity);

        if (player->jumping && kinetic->velocity.y < player->jumpVelocity)
        {
            gravityForce.y = player->jumpGravity;
        }

        kinetic->acceleration = gravityForce;

        if (coyoteTimeActive)
        {
            player->coyoteTimer += CTX_DT;
        }
    }

    // Lateral Movement.
    {
        i8 strafe = 0;

        if (InputHandlerPressing(&scene->input, "left"))
        {
            strafe = -1;
        }

        if (InputHandlerPressing(&scene->input, "right"))
        {
            strafe = 1;
        }

        kinetic->velocity.x = strafe * player->moveSpeed;
    }

    // Jumping.
    {
        if ((player->grounded || coyoteTimeActive) && !player->jumping
                && InputHandlerPressed(&scene->input, "jump"))
        {
            InputHandlerConsume(&scene->input, "jump");

            player->grounded = false;
            player->jumping = true;
            kinetic->velocity.y = -player->jumpVelocity;

            u16 particleCount = GetRandomValue(10, 25);
            Event particleEvent;
            EventCloudParticleInit(&particleEvent, entity, particleCount);
            SceneRaiseEvent(scene, &particleEvent);
        }

        // Variable Jump Height.
        if (InputHandlerReleased(&scene->input, "jump") && kinetic->velocity.y < 0)
        {
            InputHandlerConsume(&scene->input, "jump");

            player->jumping = false;
            kinetic->velocity.y = MAX(kinetic->velocity.y, -player->jumpVelocity * 0.5);
        }
    }
}

static bool PlayerIsVulnerable(const CPlayer* player)
{
    return player->invulnerableTimer >= player->invulnerableDuration;
}

static CollisionResult PlayerOnCollision(Scene* scene, const CollisionParams* params)
{
    assert(ENTITY_HAS_DEPS(params->entity, TAG_PLAYER | TAG_POSITION | TAG_KINETIC));
    assert(ENTITY_HAS_DEPS(params->otherEntity, TAG_COLLIDER));

    CPlayer* player = GET_COMPONENT(player, params->entity);
    CPosition* position = GET_COMPONENT(position, params->entity);
    CKinetic* kinetic = GET_COMPONENT(kinetic, params->entity);

    const CCollider* otherCollider = GET_COMPONENT(otherCollider, params->otherEntity);

    // Collision specific logic that will not resolve the player.
    {
        if (ENTITY_HAS_DEPS(params->entity, TAG_MORTAL)
                && ENTITY_HAS_DEPS(params->otherEntity, TAG_WALKER | TAG_DAMAGE))
        {
            if (PlayerIsVulnerable(player))
            {
                Event event;
                EventDamageInit(&event, params->entity, params->otherEntity);
                SceneRaiseEvent(scene, &event);
                player->invulnerableTimer = 0;
            }

            return COLLISION_RESULT_NONE;
        }
    }

    Vector2 resolution = ExtractResolution(params->resolution, otherCollider->layer);

    if (resolution.x == 0 && resolution.y == 0)
    {
        return COLLISION_RESULT_NONE;
    }

    Rectangle overlap = GetCollisionRec(params->aabb, params->otherAabb);

    // Make sure that the resolution is part of the axis with the least overlap.
    {
        if (resolution.x != 0 && overlap.width > overlap.height)
        {
            return COLLISION_RESULT_NONE;
        }

        if (resolution.y != 0 && overlap.height > overlap.width)
        {
            return COLLISION_RESULT_NONE;
        }
    }

    // Make sure that the resolution points in the direction of the minimum offset.
    {
        f32 left = RectangleLeft(params->aabb);
        f32 top = RectangleTop(params->aabb);

        f32 otherLeft = RectangleLeft(params->otherAabb);
        f32 otherRight = RectangleRight(params->otherAabb);
        f32 otherTop = RectangleTop(params->otherAabb);
        f32 otherBottom = RectangleBottom(params->otherAabb);

        f32 offsetLeft = (otherLeft - params->aabb.width) - left;
        f32 offsetRight = otherRight - left;
        f32 offsetDown = otherBottom - top;
        f32 offsetUp = (otherTop - params->aabb.height) - top;

        if (resolution.x < 0 && fabsf(offsetLeft) > fabsf(offsetRight))
        {
            return COLLISION_RESULT_NONE;
        }

        if (resolution.x > 0 && fabsf(offsetRight) > fabsf(offsetLeft))
        {
            return COLLISION_RESULT_NONE;
        }

        if (resolution.y < 0 && fabsf(offsetUp) > fabsf(offsetDown))
        {
            return COLLISION_RESULT_NONE;
        }

        if (resolution.y > 0 && fabsf(offsetDown) > fabsf(offsetUp))
        {
            return COLLISION_RESULT_NONE;
        }
    }

    // Collision leeway.
    {
        // Check if the player hit its head on the bottom of a collider.
        if (resolution.y > 0 && fabsf(overlap.width) <= 4)
        {
            if (params->aabb.x < params->otherAabb.x)
            {
                position->value.x = RectangleLeft(params->otherAabb) - params->aabb.width;
            }
            else
            {
                position->value.x = RectangleRight(params->otherAabb);
            }

            return (CollisionResult)
            {
                .xAxisResolved = true,
                .yAxisResolved = false,
            };
        }
    }

    bool xAxisResolved = resolution.x != 0;
    bool yAxisResolved = resolution.y != 0;

    // Resolve collision.
    {
        if (resolution.x < 0)
        {
            position->value.x = RectangleLeft(params->otherAabb) - params->aabb.width;
        }
        else if (resolution.x > 0)
        {
            position->value.x = RectangleRight(params->otherAabb);
        }

        if (resolution.y < 0)
        {
            position->value.y = RectangleTop(params->otherAabb) - params->aabb.height;
        }
        else if (resolution.y > 0)
        {
            position->value.y = RectangleBottom(params->otherAabb);
        }
    }

    // Resolution specific player logic.
    {
        if ((resolution.x < 0 && kinetic->velocity.x > 0)
                || (resolution.x > 0 && kinetic->velocity.x < 0))
        {
            kinetic->velocity.x = 0;
        }

        if ((resolution.y < 0 && kinetic->velocity.y > 0)
                || (resolution.y > 0 && kinetic->velocity.y < 0))
        {
            kinetic->velocity.y = 0;
        }

        if (resolution.y < 0)
        {
            player->grounded = true;
        }
    }

    return (CollisionResult)
    {
        .xAxisResolved = xAxisResolved,
        .yAxisResolved = yAxisResolved,
    };

}

// TODO(thismarvin): Is it possible to have an `OnCollision` callback as a parameter?
static CollisionResult SimulateCollisionOnAxis
(
    Scene* scene,
    const usize entity,
    const Vector2 delta,
    const u8 step
)
{
    // It is important that `delta` only consists of one axis, not both.
    assert(delta.x == 0 || delta.y == 0);

    assert(ENTITY_HAS_DEPS(entity, TAG_POSITION | TAG_DIMENSION));

    const CPosition* positionPointer = GET_COMPONENT(positionPointer, entity);

    CPosition position = *positionPointer;
    const CDimension* dimension = GET_COMPONENT(dimension, entity);

    Rectangle aabb = (Rectangle)
    {
        .x = position.value.x,
        .y = position.value.y,
        .width = dimension->width,
        .height = dimension->height,
    };

    Vector2 direction = Vector2Create(sign(delta.x), sign(delta.y));
    Vector2 remainder = Vector2Create(fabsf(delta.x), fabsf(delta.y));

    bool xAxisResolved = false;
    bool yAxisResolved = false;

    while (remainder.x > 0 || remainder.y > 0)
    {
        remainder.x -= step * fabsf(direction.x);
        remainder.y -= step * fabsf(direction.y);

        position.value.x += step * direction.x;
        position.value.y += step * direction.y;

        aabb.x = position.value.x;
        aabb.y = position.value.y;

        for (usize i = 0; i < SceneGetEventCount(scene); ++i)
        {
            const Event* event = SceneGetEvent(scene, i);

            if (event->entity != entity || event->tag != EVENT_COLLISION)
            {
                continue;
            }

            const EventCollisionInner* collisionInner = &event->collisionInner;

            assert(ENTITY_HAS_DEPS(collisionInner->otherEntity, TAG_POSITION | TAG_DIMENSION | TAG_COLLIDER));

            const CPosition* otherPosition = GET_COMPONENT(otherPosition, collisionInner->otherEntity);
            const CDimension* otherDimensions = GET_COMPONENT(otherDimensions, collisionInner->otherEntity);

            Rectangle otherAabb = (Rectangle)
            {
                .x = otherPosition->value.x,
                .y = otherPosition->value.y,
                .width = otherDimensions->width,
                .height = otherDimensions->height
            };

            if (CheckCollisionRecs(aabb, otherAabb))
            {
                CollisionParams params = (CollisionParams)
                {
                    .entity = entity,
                    .otherEntity = collisionInner->otherEntity,
                    .aabb = aabb,
                    .otherAabb = otherAabb,
                    .resolution = Vector2Create(-direction.x, -direction.y),
                };

                CollisionResult result = PlayerOnCollision(scene, &params);

                xAxisResolved |= result.xAxisResolved;
                yAxisResolved |= result.yAxisResolved;

                if ((direction.x != 0 && xAxisResolved) || (direction.y != 0 && yAxisResolved))
                {
                    return (CollisionResult)
                    {
                        .xAxisResolved = xAxisResolved,
                        .yAxisResolved = yAxisResolved,
                    };
                }
            }
        }
    }

    return (CollisionResult)
    {
        .xAxisResolved = xAxisResolved,
        .yAxisResolved = yAxisResolved,
    };
}

void SPlayerCollisionUpdate(Scene* scene, const usize entity)
{
    REQUIRE_DEPS(TAG_PLAYER | TAG_SMOOTH | TAG_POSITION | TAG_DIMENSION | TAG_COLLIDER | TAG_KINETIC);

    CPlayer* player = GET_COMPONENT(player, entity);
    const CSmooth* smooth = GET_COMPONENT(smooth, entity);
    CPosition* position = GET_COMPONENT(position, entity);
    const CDimension* dimension = GET_COMPONENT(dimension, entity);

    bool groundedLastFrame = player->grounded;

    // General purpose player specific collision logic.
    {
        // Assume that the player is not grounded; prove that it is later.
        player->grounded = false;

        // Keep the player's x within the scene's bounds.
        if (position->value.x < scene->bounds.x)
        {
            position->value.x = scene->bounds.x;
        }
        else if (position->value.x + dimension->width > RectangleRight(scene->bounds))
        {
            position->value.x = RectangleRight(scene->bounds) - dimension->width;
        }
    }

    // TODO(thismarvin): Look into integer based collision.
    Vector2 current = position->value;
    Vector2 previous = smooth->previous;

    Vector2 delta = Vector2Subtract(current, previous);
    i8 step = 1;

    Vector2 original = position->value;
    position->value = previous;

    bool xAxisResolved = false;
    bool yAxisResolved = false;

    // Resolve collision in the x-axis.
    {
        CollisionResult result = SimulateCollisionOnAxis(scene, entity, Vector2Create(delta.x, 0), step);

        xAxisResolved |= result.xAxisResolved;
        yAxisResolved |= result.yAxisResolved;

        if (!xAxisResolved)
        {
            position->value.x = original.x;
        }
    }

    // Resolve collision in the y-axis.
    {
        CollisionResult result = SimulateCollisionOnAxis(scene, entity, Vector2Create(0, delta.y), step);

        xAxisResolved |= result.xAxisResolved;
        yAxisResolved |= result.yAxisResolved;

        if (!yAxisResolved)
        {
            position->value.y = original.y;
        }
    }

    // Enable "Coyote Time" if the player walked off an edge.
    if (groundedLastFrame && !player->grounded)
    {
        player->coyoteTimer = 0;
    }

    // Consume Collision events.
    {
        for (usize i = 0; i < SceneGetEventCount(scene); ++i)
        {
            const Event* event = SceneGetEvent(scene, i);

            if (event->entity != entity || event->tag != EVENT_COLLISION)
            {
                continue;
            }

            SceneConsumeEvent(scene, i);
        }
    }
}

static void PlayerFlashingLogic(Scene* scene, const usize entity)
{
    assert(ENTITY_HAS_DEPS(entity, TAG_PLAYER));

    CPlayer* player = GET_COMPONENT(player, entity);

    player->invulnerableTimer += CTX_DT;

    const u32 totalFlashes = 5;
    f32 timeSlice = player->invulnerableDuration / (totalFlashes * 2.0f);

    if (!player->dead && !PlayerIsVulnerable(player))
    {
        u32 passedSlices = (u32)(player->invulnerableTimer / timeSlice);

        if (passedSlices % 2 == 0)
        {
            SceneDeferDisableComponent(scene, entity, TAG_SPRITE);
        }
        else
        {
            SceneDeferEnableComponent(scene, entity, TAG_SPRITE);
        }
    }
    else
    {
        // This is a pre-caution to make sure the last state isn't off.
        SceneDeferEnableComponent(scene, entity, TAG_SPRITE);
    }
}
void SPlayerMortalUpdate(Scene* scene, const usize entity)
{
    REQUIRE_DEPS(TAG_PLAYER | TAG_POSITION | TAG_KINETIC | TAG_MORTAL);

    CPlayer* player = GET_COMPONENT(player, entity);
    CKinetic* kinetic = GET_COMPONENT(kinetic, entity);
    CMortal* mortal = GET_COMPONENT(mortal, entity);

    if (scene->components.positions[entity].value.y > CTX_VIEWPORT_HEIGHT * 2)
    {
        SceneReset(scene);

        return;
    }

    for (usize i = 0; i < SceneGetEventCount(scene); ++i)
    {
        const Event* event = SceneGetEvent(scene, i);

        if (event->entity != entity || event->tag != EVENT_DAMAGE)
        {
            continue;
        }

        SceneConsumeEvent(scene, i);

        const EventDamageInner* damageInner = &event->damageInner;
        usize otherEntity = damageInner->otherEntity;

        assert(ENTITY_HAS_DEPS(otherEntity, TAG_DAMAGE));

        const CDamage* otherDamage = GET_COMPONENT(otherDamage, otherEntity);

        mortal->hp -= otherDamage->value;
        player->invulnerableTimer = 0;

        if (mortal->hp == 0)
        {
            player->dead = true;

            SceneDeferDisableComponent(scene, entity, TAG_COLLIDER);

            kinetic->velocity = (Vector2)
            {
                .x = kinetic->velocity.x < 0 ? -50 : 50,
                .y = -250,
            };
        }
    }

    PlayerFlashingLogic(scene, entity);
}

void SWalkerCollisionUpdate(Scene* scene, const usize entity)
{
    REQUIRE_DEPS(TAG_WALKER | TAG_POSITION | TAG_DIMENSION | TAG_COLLIDER | TAG_KINETIC);

    CPosition* position = GET_COMPONENT(position, entity);
    const CDimension* dimension = GET_COMPONENT(dimension, entity);
    CKinetic* kinetic = GET_COMPONENT(kinetic, entity);

    Rectangle aabb = (Rectangle)
    {
        .x = position->value.x,
        .y = position->value.y,
        .width = dimension->width,
        .height = dimension->height,
    };

    // TODO(thismarvin): A lot of this is copied from Player...

    // Consume Collision event.
    for (usize i = 0; i < SceneGetEventCount(scene); ++i)
    {
        const Event* event = SceneGetEvent(scene, i);

        if (event->entity != entity || event->tag != EVENT_COLLISION)
        {
            continue;
        }

        SceneConsumeEvent(scene, i);

        const EventCollisionInner* collisionInner = &event->collisionInner;

        assert(ENTITY_HAS_DEPS(collisionInner->otherEntity, TAG_POSITION | TAG_DIMENSION | TAG_COLLIDER));

        const CPosition* otherPosition = GET_COMPONENT(otherPosition, collisionInner->otherEntity);
        const CDimension* otherDimension = GET_COMPONENT(otherDimension, collisionInner->otherEntity);
        const CCollider* otherCollider = GET_COMPONENT(otherCollider, collisionInner->otherEntity);

        Rectangle otherAabb = (Rectangle)
        {
            .x = otherPosition->value.x,
            .y = otherPosition->value.y,
            .width = otherDimension->width,
            .height = otherDimension->height,
        };

        Vector2 rawResolution = RectangleRectangleResolution(aabb, otherAabb);
        Vector2 resolution = ExtractResolution(rawResolution, otherCollider->layer);

        position->value = Vector2Add(position->value, resolution);

        aabb.x += resolution.x;
        aabb.y += resolution.y;

        // Walk side to side.
        if (resolution.x != 0)
        {
            kinetic->velocity.x *= -1;
        }

        if (resolution.y != 0)
        {
            kinetic->velocity.y = 0;
        }
    }
}

void SFleetingUpdate(Scene* scene, const usize entity)
{
    REQUIRE_DEPS(TAG_FLEETING);

    CFleeting* fleeting = GET_COMPONENT(fleeting, entity);

    fleeting->age += CTX_DT;

    if (fleeting->age > fleeting->lifetime)
    {
        SceneDeferDeallocateEntity(scene, entity);
    }
}

void SGenericCollisionUpdate(Scene* scene, const usize entity)
{
    REQUIRE_DEPS(TAG_POSITION | TAG_DIMENSION | TAG_COLLIDER);

    CPosition* position = GET_COMPONENT(position, entity);
    const CDimension* dimension = GET_COMPONENT(dimension, entity);

    Rectangle aabb = (Rectangle)
    {
        .x = position->value.x,
        .y = position->value.y,
        .width = dimension->width,
        .height = dimension->height,
    };

    // Consume Collision event.
    for (usize i = 0; i < SceneGetEventCount(scene); ++i)
    {
        const Event* event = SceneGetEvent(scene, i);

        if (event->entity != entity || event->tag != EVENT_COLLISION)
        {
            continue;
        }

        SceneConsumeEvent(scene, i);

        const EventCollisionInner* collisionInner = &event->collisionInner;

        assert(ENTITY_HAS_DEPS(collisionInner->otherEntity, TAG_POSITION | TAG_DIMENSION | TAG_COLLIDER));

        const CPosition* otherPosition = GET_COMPONENT(otherPosition, collisionInner->otherEntity);
        const CDimension* otherDimension = GET_COMPONENT(otherDimension, collisionInner->otherEntity);
        const CCollider* otherCollider = GET_COMPONENT(otherCollider, collisionInner->otherEntity);

        Rectangle otherAabb = (Rectangle)
        {
            .x = otherPosition->value.x,
            .y = otherPosition->value.y,
            .width = otherDimension->width,
            .height = otherDimension->height,
        };

        Vector2 rawResolution = RectangleRectangleResolution(aabb, otherAabb);
        Vector2 resolution = ExtractResolution(rawResolution, otherCollider->layer);

        position->value = Vector2Add(position->value, resolution);

        aabb.x += resolution.x;
        aabb.y += resolution.y;
    }
}

void SCloudParticleCollisionUpdate(Scene* scene, const usize entity)
{
    REQUIRE_DEPS(TAG_POSITION | TAG_DIMENSION | TAG_COLLIDER | TAG_FLEETING);

    CPosition* position = GET_COMPONENT(position, entity);
    const CDimension* dimension = GET_COMPONENT(dimension, entity);
    const CFleeting* fleeting = GET_COMPONENT(fleeting, entity);

    const f32 collisionSize = dimension->width * (fleeting->lifetime - fleeting->age) /
                              fleeting->lifetime;

    Rectangle aabb = (Rectangle)
    {
        .x = position->value.x + dimension->width * 0.5f - collisionSize * 0.5f,
        .y = position->value.y + dimension->height * 0.5f - collisionSize * 0.5f,
        .width = collisionSize,
        .height = collisionSize,
    };

    // Consume Collision event.
    for (usize i = 0; i < SceneGetEventCount(scene); ++i)
    {
        const Event* event = SceneGetEvent(scene, i);

        if (event->entity != entity || event->tag != EVENT_COLLISION)
        {
            continue;
        }

        SceneConsumeEvent(scene, i);

        const EventCollisionInner* collisionInner = &event->collisionInner;

        assert(ENTITY_HAS_DEPS(collisionInner->otherEntity, TAG_POSITION | TAG_DIMENSION | TAG_COLLIDER));

        const CPosition* otherPosition = GET_COMPONENT(otherPosition, collisionInner->otherEntity);
        const CDimension* otherDimension = GET_COMPONENT(otherDimension, collisionInner->otherEntity);
        const CCollider* otherCollider = GET_COMPONENT(otherCollider, collisionInner->otherEntity);

        Rectangle otherAabb = (Rectangle)
        {
            .x = otherPosition->value.x,
            .y = otherPosition->value.y,
            .width = otherDimension->width,
            .height = otherDimension->height,
        };

        Rectangle overlap = GetCollisionRec(aabb, otherAabb);

        // If the aabb is completely within another collider then remove it.
        if (overlap.width >= aabb.width && overlap.height >= aabb.height)
        {
            SceneDeferDeallocateEntity(scene, entity);

            return;
        }

        Vector2 rawResolution = RectangleRectangleResolution(aabb, otherAabb);
        Vector2 resolution = ExtractResolution(rawResolution, otherCollider->layer);

        position->value = Vector2Add(position->value, resolution);

        aabb.x += resolution.x;
        aabb.y += resolution.y;
    }
}

void SCloudParticleSpawnUpdate(Scene* scene, const usize entity)
{
    REQUIRE_DEPS(TAG_POSITION | TAG_DIMENSION | TAG_KINETIC);

    const CPosition* position = GET_COMPONENT(position, entity);
    const CDimension* dimension = GET_COMPONENT(dimension, entity);
    const CKinetic* kinetic = GET_COMPONENT(kinetic, entity);

    for (usize i = 0; i < SceneGetEventCount(scene); ++i)
    {
        const Event* event = SceneGetEvent(scene, i);

        if (event->entity != entity || event->tag != EVENT_CLOUD_PARTICLE)
        {
            continue;
        }

        SceneConsumeEvent(scene, i);

        const EventCloudParticleInner* cloudInner = &event->cloudParticleInner;

        // Set offset anchor point to left, middle, or right depending on movement direction.
        f32 anchor = kinetic->velocity.x == 0 ? dimension->width * 0.5f :
                     kinetic->velocity.x > 0 ? 0 : dimension->width;

        i32 spreadFactor = 14;

        for (usize j = 0; j < cloudInner->spawnCount; ++j)
        {
            f32 xOffset = (f32)GetRandomValue(-spreadFactor, spreadFactor);
            Vector2 offset = Vector2Create(anchor + xOffset, dimension->height);
            Vector2 startingPosition = Vector2Add(position->value, offset);

            Vector2 direction = Vector2Normalize(Vector2Negate(kinetic->velocity));
            direction.y *= -1;
            f32 directionOffset = (f32)GetRandomValue(DEG2RAD * -45, DEG2RAD * 45);
            direction = Vector2Rotate(direction, directionOffset);
            SceneDeferAddEntity(scene, ECreateCloudParticle(startingPosition.x, startingPosition.y, direction));
        }
    }
}

void SCloudParticleDraw(const Scene* scene, const usize entity)
{
    REQUIRE_DEPS(TAG_POSITION | TAG_DIMENSION | TAG_FLEETING | TAG_COLOR | TAG_SMOOTH);

    const CPosition* position = GET_COMPONENT(position, entity);
    const CColor* color = GET_COMPONENT(color, entity);
    const CFleeting* fleeting = GET_COMPONENT(fleeting, entity);
    const CDimension* dimension = GET_COMPONENT(dimension, entity);
    const CSmooth* smooth = GET_COMPONENT(smooth, entity);

    const f32 drawSize = dimension->width * (fleeting->lifetime - fleeting->age) / fleeting->lifetime;

    Vector2 interpolated = Vector2Lerp(smooth->previous, position->value, ContextGetAlpha());

    Vector2 center = (Vector2)
    {
        .x = interpolated.x + dimension->width * 0.5f,
        .y = interpolated.y + dimension->height * 0.5f,
    };

    DrawCircleV(center, drawSize * 0.5f, color->value);
}

void SSpriteDraw(const Scene* scene, const usize entity)
{
    REQUIRE_DEPS(TAG_POSITION | TAG_COLOR | TAG_SPRITE);

    const CPosition* position = GET_COMPONENT(position, entity);
    const CColor* color = GET_COMPONENT(color, entity);
    const CSprite* sprite = GET_COMPONENT(sprite, entity);

    if (ENTITY_HAS_DEPS(entity, TAG_SMOOTH))
    {
        const CSmooth* smooth = GET_COMPONENT(smooth, entity);

        Vector2 interpolated = Vector2Lerp(smooth->previous, position->value, ContextGetAlpha());
        Vector2 drawPosition = Vector2Add(interpolated, sprite->offset);

        DrawTextureRec(scene->atlas, sprite->source, drawPosition, color->value);
    }
    else
    {
        Vector2 drawPosition = Vector2Add(position->value, sprite->offset);

        DrawTextureRec(scene->atlas, sprite->source, drawPosition, color->value);
    }
}

void SDebugDraw(const Scene* scene, const usize entity)
{
    REQUIRE_DEPS(TAG_POSITION | TAG_DIMENSION);

    const CPosition* position = GET_COMPONENT(position, entity);
    const CDimension* dimension = GET_COMPONENT(dimension, entity);

    Rectangle bounds = (Rectangle)
    {
        .x = position->value.x,
        .y = position->value.y,
        .width = dimension->width,
        .height = dimension->height
    };

    DrawRectangleLinesEx(bounds, 4, COLOR_RED);
}
