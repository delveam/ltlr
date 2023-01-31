#pragma once

#include "./collections/deque.h"
#include "./ecs/components.h"
#include "atlas.h"
#include "common.h"
#include "fader.h"
#include "input.h"
#include "level.h"

#define MAX_ENTITIES (1024)

#define MAX_SCORE_DIGITS (6 + 1)
#define MAX_SCORE (999999)

typedef void (*OnDefer)(Scene*, const void*);

typedef enum
{
	SCENE_STATE_MENU,
	SCENE_STATE_ACTION,
} SceneState;

typedef enum
{
	DIRECTOR_STATE_ENTRANCE,
	DIRECTOR_STATE_SUPERVISE,
	DIRECTOR_STATE_EXIT,
} DirectorState;

typedef struct
{
	u64 tags[MAX_ENTITIES];
	CIdentifier identifiers[MAX_ENTITIES];
	CPosition positions[MAX_ENTITIES];
	CDimension dimensions[MAX_ENTITIES];
	CColor colors[MAX_ENTITIES];
	CSprite sprites[MAX_ENTITIES];
	CAnimation animations[MAX_ENTITIES];
	CKinetic kinetics[MAX_ENTITIES];
	CSmooth smooths[MAX_ENTITIES];
	CCollider colliders[MAX_ENTITIES];
	CMortal mortals[MAX_ENTITIES];
	CDamage damages[MAX_ENTITIES];
	CFleeting fleetings[MAX_ENTITIES];
	CPlayer players[MAX_ENTITIES];
} Components;

typedef struct
{
	// The next available index in the Components struct that has not been used before.
	usize m_nextFreshEntityIndex;
	// A stack of indices in the Components struct that are not currently allocated but were
	// previously deallocated (an entity once resided in these indices). `Deque<usize>`
	Deque m_recycledEntityIndices;
} EntityManager;

struct Scene
{
	SceneState state;
	Components components;
	EntityManager m_entityManager;
	bool debugging;
	u32 score;
	f32 scoreBufferTimerDuration;
	f32 scoreBufferTimer;
	i32 scoreBuffer;
	char scoreString[MAX_SCORE_DIGITS];
	usize player;
	usize fog;
	usize lakitu;
	Rectangle bounds;
	Atlas atlas;
	Level level;
	u8 stage;
	DirectorState director;
	Fader fader;
	RenderTexture2D rootLayer;
	RenderTexture2D backgroundLayer;
	RenderTexture2D targetLayer;
	RenderTexture2D foregroundLayer;
	RenderTexture2D interfaceLayer;
	RenderTexture2D transitionLayer;
	RenderTexture2D debugLayer;
	InputProfile defaultMenuProfile;
	InputProfile defaultActionProfile;
	InputHandler input;
	bool resetRequested;
	bool advanceStageRequested;
	Vector2 actionCameraPosition;
	RenderTexture2D treeTexture;
	// `Deque<Vector2>`
	Deque treePositionsBack;
	// `Deque<Vector2>`
	Deque treePositionsFront;
	// `Deque<SceneDeferParams>`
	Deque deferred;
};

void SceneInit(Scene* self);

usize SceneAllocateEntity(Scene* self);
usize SceneGetTotalAllocatedEntities(const Scene* self);
bool SceneEntityHasDependencies(const Scene* self, usize entity, u64 dependencies);
bool SceneEntityIs(const Scene* self, usize entity, EntityType type);

void SceneIncrementScore(Scene* self, u32 value);

void SceneDefer(Scene* self, const OnDefer fn, const void* params);
void SceneDeferDeallocateEntity(Scene* self, usize entity);
void SceneDeferEnableTag(Scene* self, usize entity, u64 tag);
void SceneDeferDisableTag(Scene* self, usize entity, u64 tag);
void SceneDeferSetTag(Scene* self, usize entity, u64 tag);
void SceneDeferReset(Scene* self);
void SceneDeferAdvanceStage(Scene* self);

void SceneUpdate(Scene* self);
void SceneDraw(Scene* self);

void SceneDestroy(Scene* self);
