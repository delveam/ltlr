#pragma once

#include "./collections/deque.h"
#include "atlas.h"
#include "common.h"

#define MAX_LEVEL_SEGMENTS (8)

typedef struct
{
    // `Deque<EntityBuilder>`
    Deque entities;
    u16 width;
} LevelSegmentBuilder;

typedef struct
{
    u16 type;
    u16 width;
} LevelSegment;

typedef struct
{
    LevelSegment segments[MAX_LEVEL_SEGMENTS];
    usize segmentsLength;
} Level;

LevelSegmentBuilder LevelSegmentBuilderCreate(u16 type, Vector2 offset);

void LevelSegmentDraw(const LevelSegment* self, const Atlas* atlas, Vector2 offset);
