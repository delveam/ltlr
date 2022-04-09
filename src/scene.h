#pragma once

#include "common.h"
#include "components.h"
#include "events.h"
#include "input.h"
#include "level_segment.h"
#include "deque.h"

#define MAX_ENTITIES 1024
#define MAX_EVENTS 64

typedef struct
{
    u64 tags[MAX_ENTITIES];
    CPosition positions[MAX_ENTITIES];
    CDimension dimensions[MAX_ENTITIES];
    CColor colors[MAX_ENTITIES];
    CSprite sprites[MAX_ENTITIES];
    CKinetic kinetics[MAX_ENTITIES];
    CSmooth smooths[MAX_ENTITIES];
    CCollider colliders[MAX_ENTITIES];
    CPlayer players[MAX_ENTITIES];
    CMortal mortals[MAX_ENTITIES];
    CDamage damages[MAX_ENTITIES];
    CFleeting fleetings[MAX_ENTITIES];
} Components;

typedef struct
{
    Deque deferredDeallocations;
    // The next available index in the Components struct that has not been used before.
    usize nextFreshEntityIndex;
    // A stack of indices in the Components struct that are not currently allocated but were
    // previously deallocated (an entity once resided in these indices).
    Deque recycledEntityIndices;
} EntityManager;

typedef struct
{
    Event events[MAX_EVENTS];
    // The next available index in the events array that has not been used before.
    usize nextFreshEventIndex;
    // A stack of indices in the events array that are not currently raised but were once indices
    // of a consumed event.
    Deque recycledEventIndices;
} EventManager;

typedef struct
{
    Components components;
    EntityManager entityManager;
    EventManager eventManager;
    bool debugging;
    usize player;
    Rectangle bounds;
    Texture2D atlas;
    LevelSegment* segments;
    usize segmentsLength;
    Rectangle trueResolution;
    Rectangle renderResolution;
    RenderTexture2D rootLayer;
    RenderTexture2D backgroundLayer;
    RenderTexture2D targetLayer;
    RenderTexture2D foregroundLayer;
    // TODO(thismarvin): Should this exist in Scene?
    InputHandler input;
} Scene;

void SceneInit(Scene* self);
Components* SceneGetComponents(const Scene* self);
void SceneEnableComponent(Scene* self, usize entity, usize tag);
void SceneDisableComponent(Scene* self, usize entity, usize tag);
usize SceneAllocateEntity(Scene* self);
void SceneDeferDeallocateEntity(Scene* self, usize entity);
void SceneFlushEntities(Scene* self);
usize SceneGetEntityCount(const Scene* self);
usize SceneGetEventCount(const Scene* self);
void SceneRaiseEvent(Scene* self, const Event* event);
void SceneConsumeEvent(Scene* self, usize eventIndex);
void SceneUpdate(Scene* self);
void SceneDraw(const Scene* self);
void SceneReset(Scene* self);
void SceneDestroy(Scene* self);
