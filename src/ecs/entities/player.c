#include "../events.h"
#include "common.h"
#include "player.h"
#include <math.h>
#include <raymath.h>

static const f32 timeToSprint = CTX_DT * 6;
static const f32 timeToStop = CTX_DT * 6;

static void PlayerStandstill(CPlayer* player, CKinetic* kinetic)
{
    player->sprintTimer = 0;
    player->sprintState = SPRINT_STATE_NONE;
    player->sprintForce.x = 0;
    player->sprintDirection = DIR_NONE;
    kinetic->velocity.x = 0;
}

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

static void PlayerOnCollision(const OnCollisionParams* params)
{
    assert(ENTITY_HAS_DEPS(params->entity, TAG_PLAYER | TAG_MORTAL));

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

            return;
        }
    }
}

static OnResolutionResult PlayerOnResolution(const OnResolutionParams* params)
{
    assert(ENTITY_HAS_DEPS(params->entity, TAG_PLAYER | TAG_POSITION | TAG_KINETIC));

    CPlayer* player = GET_COMPONENT(player, params->entity);
    const CPosition* position = GET_COMPONENT(position, params->entity);
    CKinetic* kinetic = GET_COMPONENT(kinetic, params->entity);

    // Collision specific logic that will not resolve the player.
    {
        if (ENTITY_HAS_DEPS(params->otherEntity, TAG_WALKER))
        {
            return (OnResolutionResult)
            {
                .aabb = params->aabb,
            };
        }
    }

    // Collision leeway.
    {
        // Check if the player hit its head on the bottom of a collider.
        if (params->resolution.y > 0 && fabsf(params->overlap.width) <= 4)
        {
            Rectangle resolvedAabb = params->aabb;

            if (params->aabb.x < params->otherAabb.x)
            {
                resolvedAabb.x = RectangleLeft(params->otherAabb) - params->aabb.width;
            }
            else
            {
                resolvedAabb.x = RectangleRight(params->otherAabb);
            }

            return (OnResolutionResult)
            {
                .aabb = resolvedAabb,
            };
        }
    }

    // Make sure that landing on top of a one-way platform does not noticeably teleport the player.
    {
        if (kinetic->velocity.y > 0 && params->resolution.y < 0)
        {
            const f32 difference = fabsf(RectangleTop(params->otherAabb) - RectangleBottom(params->aabb));

            if (difference > 3.0f)
            {
                return (OnResolutionResult)
                {
                    .aabb = params->aabb,
                };
            }
        }
    }

    // Resolve collision.
    Rectangle resolvedAabb = ApplyResolutionPerfectly(params->aabb, params->otherAabb,
                             params->resolution);

    // Resolution specific player logic.
    {
        if ((params->resolution.x < 0 && kinetic->velocity.x > 0)
                || (params->resolution.x > 0 && kinetic->velocity.x < 0))
        {
            PlayerStandstill(player, kinetic);
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

    return (OnResolutionResult)
    {
        .aabb = resolvedAabb,
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
        .mirroring = FLIP_NONE,
    }));

    ADD_COMPONENT(CKinetic, ((CKinetic)
    {
        .velocity = VECTOR2_ZERO,
        .acceleration = VECTOR2_ZERO,
    }));

    ADD_COMPONENT(CSmooth, ((CSmooth)
    {
        .previous = position,
    }));

    ADD_COMPONENT(CCollider, ((CCollider)
    {
        .resolutionSchema = RESOLVE_NONE,
        .layer = LAYER_NONE,
        .mask = LAYER_TERRAIN | LAYER_LETHAL,
        .onCollision = PlayerOnCollision,
        .onResolution = PlayerOnResolution,
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
        .gravityForce = VECTOR2_ZERO,
        .invulnerableTimer = invulnerableDuration,
        .invulnerableDuration = invulnerableDuration,
        .initialDirection = DIR_NONE,
        .sprintDirection = DIR_NONE,
        .sprintState = SPRINT_STATE_NONE,
        .sprintTimer = 0,
        .sprintDuration = 0,
        .sprintForce = VECTOR2_ZERO,
    }));

    return (EntityBuilder)
    {
        .tags = tags,
        .components = components,
    };
}

static void PlayerDecelerate(CPlayer* player, const CKinetic* kinetic)
{
    if (kinetic->velocity.x == 0)
    {
        player->sprintTimer = 0;
        player->sprintState = SPRINT_STATE_NONE;
        player->sprintForce.x = 0;
        player->sprintDirection = DIR_NONE;

        return;
    }

    const f32 delta = fabsf(kinetic->velocity.x);

    const f32 vf = 0;
    const f32 vo = kinetic->velocity.x;
    const f32 t = delta * timeToStop / player->moveSpeed;

    player->sprintTimer = 0;
    player->sprintDuration = t;
    player->sprintState = SPRINT_STATE_DECELERATING;
    // vf = vo + a * t
    // a = (vf - vo) / t
    player->sprintForce.x = (vf - vo) / t;
    player->sprintDirection = DIR_NONE;
}

static void PlayerAccelerate(CPlayer* player, const CKinetic* kinetic, const Direction direction)
{
    if ((direction == DIR_LEFT && kinetic->velocity.x <= -player->moveSpeed)
            || (direction == DIR_RIGHT && kinetic->velocity.x >= player->moveSpeed))
    {
        player->sprintTimer = 0;
        player->sprintState = SPRINT_STATE_TERMINAL;
        player->sprintForce.x = 0;
        player->sprintDirection = direction;

        return;
    }

    f32 delta = player->moveSpeed;

    if ((direction == DIR_LEFT && kinetic->velocity.x < 0)
            || (direction == DIR_RIGHT && kinetic->velocity.x > 0))
    {
        delta -= fabsf(kinetic->velocity.x);
    }
    else if ((direction == DIR_LEFT && kinetic->velocity.x > 0)
             || (direction == DIR_RIGHT && kinetic->velocity.x < 0))
    {
        delta += fabsf(kinetic->velocity.x);
    }

    const i8 sign = direction == DIR_LEFT ? -1 : 1;

    const f32 vf = player->moveSpeed * sign;
    const f32 vo = kinetic->velocity.x;
    const f32 t = delta * timeToSprint / player->moveSpeed;

    player->sprintTimer = 0;
    player->sprintDuration = t;
    player->sprintState = SPRINT_STATE_ACCELERATING;
    // vf = vo + a * t
    // a = (vf - vo) / t
    player->sprintForce.x = (vf - vo) / t;
    player->sprintDirection = direction;
}

static void PlayerLateralMovementLogic(const Scene* scene, CPlayer* player, CKinetic* kinetic)
{
    Direction strafe = DIR_NONE;

    // Input.
    if (!InputHandlerPressing(&scene->input, "right")
            && InputHandlerPressing(&scene->input, "left"))
    {
        player->initialDirection = DIR_LEFT;
        strafe = DIR_LEFT;
    }
    else if (!InputHandlerPressing(&scene->input, "left")
             && InputHandlerPressing(&scene->input, "right"))
    {
        player->initialDirection = DIR_RIGHT;
        strafe = DIR_RIGHT;
    }
    else if (player->initialDirection == DIR_RIGHT && InputHandlerPressing(&scene->input, "left"))
    {
        strafe = DIR_LEFT;
    }
    else if (player->initialDirection == DIR_LEFT && InputHandlerPressing(&scene->input, "right"))
    {
        strafe = DIR_RIGHT;
    }

    // Handle sprint state.
    switch (player->sprintState)
    {
        case SPRINT_STATE_NONE:
        {
            if (strafe == DIR_NONE)
            {
                player->sprintForce.x = 0;

                break;
            }

            PlayerAccelerate(player, kinetic, strafe);

            break;
        }

        case SPRINT_STATE_ACCELERATING:
        {
            if (strafe == DIR_NONE)
            {
                PlayerDecelerate(player, kinetic);

                break;
            }

            if ((player->sprintDirection == DIR_LEFT && strafe == DIR_RIGHT)
                    || (player->sprintDirection == DIR_RIGHT && strafe == DIR_LEFT))
            {
                PlayerAccelerate(player, kinetic, strafe);

                break;
            }

            player->sprintTimer += CTX_DT;

            if (player->sprintTimer >= player->sprintDuration)
            {
                player->sprintTimer = 0;
                player->sprintState = SPRINT_STATE_TERMINAL;
                player->sprintForce.x = 0;

                // const i8 sign = strafe == DIR_RIGHT ? 1 : -1;
                // kinetic->velocity.x = player->moveSpeed * sign;
            }

            break;
        }

        case SPRINT_STATE_TERMINAL:
        {
            if ((player->sprintDirection == DIR_LEFT && strafe == DIR_RIGHT)
                    || (player->sprintDirection == DIR_RIGHT && strafe == DIR_LEFT))
            {
                PlayerAccelerate(player, kinetic, strafe);

                break;
            }

            if (strafe == DIR_NONE)
            {
                PlayerDecelerate(player, kinetic);
            }

            break;
        }

        case SPRINT_STATE_DECELERATING:
        {
            if (strafe != DIR_NONE)
            {
                PlayerAccelerate(player, kinetic, strafe);

                break;
            }

            player->sprintTimer += CTX_DT;

            if (player->sprintTimer > player->sprintDuration)
            {
                PlayerStandstill(player, kinetic);
            }

            break;
        }
    }
}

void PlayerInputUpdate(Scene* scene, const usize entity)
{
    const u64 dependencies = TAG_PLAYER | TAG_POSITION | TAG_DIMENSION | TAG_KINETIC;

    if (!SceneEntityHasDependencies(scene, entity, dependencies))
    {
        return;
    }

    CPlayer* player = SCENE_GET_COMPONENT_PTR(scene, player, entity);
    const CPosition* position = SCENE_GET_COMPONENT_PTR(scene, position, entity);
    const CDimension* dimension = SCENE_GET_COMPONENT_PTR(scene, dimension, entity);
    CKinetic* kinetic = SCENE_GET_COMPONENT_PTR(scene, kinetic, entity);

    if (player->dead)
    {
        return;
    }

    const bool coyoteTimeActive = player->coyoteTimer < player->coyoteDuration;

    // Maintenance.
    {
        player->groundedLastFrame = player->grounded;

        if (player->grounded)
        {
            kinetic->velocity.y = 0;
            player->jumping = false;
        }

        player->gravityForce.y = player->defaultGravity;

        if (player->jumping && kinetic->velocity.y < player->jumpVelocity)
        {
            player->gravityForce.y = player->jumpGravity;
        }

        if (coyoteTimeActive)
        {
            player->coyoteTimer += CTX_DT;
        }
    }

    PlayerLateralMovementLogic(scene, player, kinetic);

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

    // Calculate Net Force.
    {
        kinetic->acceleration = (Vector2)
        {
            .x = player->gravityForce.x + player->sprintForce.x,
            .y = player->gravityForce.y + player->sprintForce.y,
        };
    }
}

void PlayerPostCollisionUpdate(Scene* scene, const usize entity)
{
    const u64 dependencies = TAG_PLAYER | TAG_POSITION | TAG_DIMENSION | TAG_KINETIC;

    if (!SceneEntityHasDependencies(scene, entity, dependencies))
    {
        return;
    }

    CPlayer* player = SCENE_GET_COMPONENT_PTR(scene, player, entity);
    CPosition* position = SCENE_GET_COMPONENT_PTR(scene, position, entity);
    const CDimension* dimension = SCENE_GET_COMPONENT_PTR(scene, dimension, entity);
    CKinetic* kinetic = SCENE_GET_COMPONENT_PTR(scene, kinetic, entity);

    // General purpose player specific collision logic.
    {
        // Keep the player's x within the scene's bounds.
        if (position->value.x < scene->bounds.x)
        {
            position->value.x = scene->bounds.x;
            PlayerStandstill(player, kinetic);
        }
        else if (position->value.x + dimension->width > RectangleRight(scene->bounds))
        {
            position->value.x = RectangleRight(scene->bounds) - dimension->width;
            PlayerStandstill(player, kinetic);
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
    CPlayer* player = SCENE_GET_COMPONENT_PTR(scene, player, entity);

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

    CPlayer* player = SCENE_GET_COMPONENT_PTR(scene, player, entity);
    const CMortal* mortal = SCENE_GET_COMPONENT_PTR(scene, mortal, entity);
    const CPosition* position = SCENE_GET_COMPONENT_PTR(scene, position, entity);
    CKinetic* kinetic = SCENE_GET_COMPONENT_PTR(scene, kinetic, entity);

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
