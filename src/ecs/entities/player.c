#include "../events.h"
#include "common.h"
#include <math.h>
#include <raymath.h>

static bool PlayerIsVulnerable(const CPlayer* player)
{
    return player->invulnerableTimer >= player->invulnerableDuration;
}

static void PlayerOnDamage(const OnDamageParams* params)
{
    assert(ENTITY_HAS_DEPS(params->entity, TAG_PLAYER | TAG_MORTAL));

    CPlayer* player = GET_COMPONENT(player, params->entity);
    CMortal* mortal = GET_COMPONENT(mortal, params->entity);

    const CDamage* otherDamage = GET_COMPONENT(otherDamage, params->otherEntity);

    if (!PlayerIsVulnerable(player))
    {
        return;
    }

    mortal->hp -= otherDamage->value;
    player->invulnerableTimer = 0;
}

static OnCollisionResult PlayerOnCollision(const OnCollisionParams* params)
{
    assert(ENTITY_HAS_DEPS(params->entity, TAG_PLAYER | TAG_POSITION | TAG_KINETIC | TAG_MORTAL));

    CPlayer* player = GET_COMPONENT(player, params->entity);
    CPosition* position = GET_COMPONENT(position, params->entity);
    CKinetic* kinetic = GET_COMPONENT(kinetic, params->entity);
    const CMortal* mortal = GET_COMPONENT(mortal, params->entity);

    // Collision specific logic that will not resolve the player.
    {
        if (ENTITY_HAS_DEPS(params->otherEntity, TAG_WALKER | TAG_DAMAGE))
        {
            OnDamageParams onDamageParams = (OnDamageParams)
            {
                .scene = params->scene,
                .entity = params->entity,
                .otherEntity = params->otherEntity,
            };

            mortal->onDamage(&onDamageParams);

            return ON_COLLISION_RESULT_NONE;
        }
    }

    // Collision leeway.
    {
        // Check if the player hit its head on the bottom of a collider.
        if (params->resolution.y > 0 && fabsf(params->overlap.width) <= 4)
        {
            if (params->aabb.x < params->otherAabb.x)
            {
                position->value.x = RectangleLeft(params->otherAabb) - params->aabb.width;
            }
            else
            {
                position->value.x = RectangleRight(params->otherAabb);
            }

            return (OnCollisionResult)
            {
                .xAxisResolved = true,
                .yAxisResolved = false,
            };
        }
    }

    // Resolve collision.
    ApplyResolutionPerfectly(position, params->aabb, params->otherAabb, params->resolution);

    // Resolution specific player logic.
    {
        if ((params->resolution.x < 0 && kinetic->velocity.x > 0)
                || (params->resolution.x > 0 && kinetic->velocity.x < 0))
        {
            kinetic->velocity.x = 0;
        }

        if ((params->resolution.y < 0 && kinetic->velocity.y > 0)
                || (params->resolution.y > 0 && kinetic->velocity.y < 0))
        {
            kinetic->velocity.y = 0;
        }

        if (params->resolution.y < 0)
        {
            player->grounded = true;
        }
    }

    return (OnCollisionResult)
    {
        .xAxisResolved = params->resolution.x != 0,
        .yAxisResolved = params->resolution.y != 0,
    };
}

EntityBuilder PlayerCreate(const f32 x, const f32 y)
{
    Deque components = DEQUE_OF(Component);

    const u64 tags =
        TAG_NONE
        | TAG_POSITION
        | TAG_DIMENSION
        | TAG_COLOR
        | TAG_SPRITE
        | TAG_KINETIC
        | TAG_SMOOTH
        | TAG_COLLIDER
        | TAG_PLAYER
        | TAG_MORTAL;

    Vector2 position = Vector2Create(x, y);

    ADD_COMPONENT(CPosition, ((CPosition)
    {
        .value = position,
    }));

    ADD_COMPONENT(CDimension, ((CDimension)
    {
        .width = 15,
        .height = 35,
    }));

    ADD_COMPONENT(CColor, ((CColor)
    {
        .value = COLOR_WHITE,
    }));

    ADD_COMPONENT(CSprite, ((CSprite)
    {
        .source = (Rectangle) { 16, 0, 32, 48 },
        .offset = Vector2Create(-8, -13),
    }));

    ADD_COMPONENT(CKinetic, ((CKinetic)
    {
        .velocity = VECTOR2_ZERO,
        .acceleration = Vector2Create(0, 1000),
    }));

    ADD_COMPONENT(CSmooth, ((CSmooth)
    {
        .previous = position,
    }));

    ADD_COMPONENT(CCollider, ((CCollider)
    {
        .layer = LAYER_NONE,
        .mask = LAYER_ALL,
        .onCollision = PlayerOnCollision,
    }));

    ADD_COMPONENT(CMortal, ((CMortal)
    {
        .hp = 2,
        .onDamage = PlayerOnDamage,
    }));

    f32 jumpHeight = 16 * 3 + 6;
    f32 jumpDuration = 0.4;

    f32 jumpGravity = (2 * jumpHeight) / (jumpDuration * jumpDuration);
    f32 defaultGravity = jumpGravity * 1.5;

    f32 jumpVelocity = jumpGravity * jumpDuration;

    f32 coyoteDuration = CTX_DT * 6;
    f32 invulnerableDuration = 1.5f;

    ADD_COMPONENT(CPlayer, ((CPlayer)
    {
        .groundedLastFrame = false,
        .grounded = false,
        .coyoteTimer = coyoteDuration,
        .coyoteDuration = coyoteDuration,
        .moveSpeed = 200,
        .jumping = false,
        .dead = false,
        .jumpVelocity = jumpVelocity,
        .jumpGravity = jumpGravity,
        .defaultGravity = defaultGravity,
        .invulnerableTimer = invulnerableDuration,
        .invulnerableDuration = invulnerableDuration,
    }));

    return (EntityBuilder)
    {
        .tags = tags,
        .components = components,
    };
}

void PlayerInputUpdate(Scene* scene, const usize entity)
{
    u64 dependencies = TAG_PLAYER | TAG_POSITION | TAG_DIMENSION | TAG_KINETIC;

    if (!SceneEntityHasDependencies(scene, entity, dependencies))
    {
        return;
    }

    CPlayer* player = SCENE_GET_COMPONENT_PTR(scene, entity, player);
    const CPosition* position = SCENE_GET_COMPONENT_PTR(scene, entity, position);
    const CDimension* dimension = SCENE_GET_COMPONENT_PTR(scene, entity, dimension);
    CKinetic* kinetic = SCENE_GET_COMPONENT_PTR(scene, entity, kinetic);

    if (player->dead)
    {
        return;
    }

    bool coyoteTimeActive = player->coyoteTimer < player->coyoteDuration;

    // Maintenance.
    {
        player->groundedLastFrame = player->grounded;

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

            // Spawn cloud particles.
            {
                const Vector2 bottomCenter = (Vector2)
                {
                    .x = position->value.x + dimension->width * 0.5f,
                    .y = position->value.y + dimension->height
                };

                Vector2 anchorOffset = VECTOR2_ZERO;

                if (kinetic->velocity.x > 0)
                {
                    anchorOffset.x = -dimension->width * 0.5f;
                }

                if (kinetic->velocity.x < 0)
                {
                    anchorOffset.x = dimension->width * 0.5f;
                }

                const Vector2 anchor = Vector2Add(bottomCenter, anchorOffset);

                Vector2 direction = Vector2Normalize(kinetic->velocity);
                direction.x *= -1;

                const EventCloudParticleParams params = (EventCloudParticleParams)
                {
                    .scene = scene,
                    .entity = entity,
                    .anchor = anchor,
                    .direction = direction,
                    .spawnCount = GetRandomValue(10, 25),
                    .spread = dimension->width,
                };

                SpawnCloudParticles(&params);
            }
        }

        // Variable Jump Height.
        if (InputHandlerReleased(&scene->input, "jump") && kinetic->velocity.y < 0)
        {
            InputHandlerConsume(&scene->input, "jump");

            player->jumping = false;
            kinetic->velocity.y = MAX(kinetic->velocity.y, -player->jumpVelocity * 0.5);
        }
    }

    // Assume that the player is not grounded; prove that it is later.
    player->grounded = false;

    // TODO(thismarvin): Should grounded logic really be in Input?
}

void PlayerPostCollisionUpdate(Scene* scene, const usize entity)
{
    u64 dependencies = TAG_PLAYER | TAG_POSITION | TAG_DIMENSION;

    if (!SceneEntityHasDependencies(scene, entity, dependencies))
    {
        return;
    }

    CPlayer* player = SCENE_GET_COMPONENT_PTR(scene, entity, player);
    CPosition* position = SCENE_GET_COMPONENT_PTR(scene, entity, position);
    const CDimension* dimension = SCENE_GET_COMPONENT_PTR(scene, entity, dimension);

    // General purpose player specific collision logic.
    {
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

    // Enable "Coyote Time" if the player walked off an edge.
    if (player->groundedLastFrame && !player->grounded)
    {
        player->coyoteTimer = 0;
    }
}

static void PlayerFlashingLogic(Scene* scene, const usize entity)
{
    CPlayer* player = SCENE_GET_COMPONENT_PTR(scene, entity, player);

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

void PlayerMortalUpdate(Scene* scene, const usize entity)
{
    u64 dependencies = TAG_PLAYER | TAG_MORTAL | TAG_POSITION | TAG_KINETIC;

    if (!SceneEntityHasDependencies(scene, entity, dependencies))
    {
        return;
    }

    CPlayer* player = SCENE_GET_COMPONENT_PTR(scene, entity, player);
    const CMortal* mortal = SCENE_GET_COMPONENT_PTR(scene, entity, mortal);
    const CPosition* position = SCENE_GET_COMPONENT_PTR(scene, entity, position);
    CKinetic* kinetic = SCENE_GET_COMPONENT_PTR(scene, entity, kinetic);

    if (position->value.y > CTX_VIEWPORT_HEIGHT * 2)
    {
        // TODO(thismarvin): Defer resetting the Scene somehow...
        SceneReset(scene);

        return;
    }

    if (!player->dead && mortal->hp <= 0)
    {
        player->dead = true;

        SceneDeferDisableComponent(scene, entity, TAG_COLLIDER);

        kinetic->velocity = (Vector2)
        {
            .x = kinetic->velocity.x,
            .y = -250,
        };
    }

    PlayerFlashingLogic(scene, entity);
}
