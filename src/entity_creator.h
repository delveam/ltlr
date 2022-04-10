#pragma once

#include "common.h"

typedef struct
{
    f32 x;
    f32 y;
} EPlayerContext;

typedef struct
{
    f32 x;
    f32 y;
    f32 width;
    f32 height;
} EBlockContext;

typedef struct
{
    f32 x;
    f32 y;
} EWalkerContext;

typedef struct
{
    f32 centerX;
    f32 centerY;
    Vector2 direction;
} ECloudParticleContext;

typedef union
{
    EPlayerContext player;
    EBlockContext block;
    EWalkerContext walker;
    ECloudParticleContext cloudParticle;
} ECreatorContext;

struct Scene;

typedef usize (*ECreateFn)(struct Scene*, const ECreatorContext*);

typedef struct
{
    ECreateFn createFn;
    ECreatorContext context;
} ECreator;
