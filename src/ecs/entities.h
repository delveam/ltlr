#pragma once

#include "entity_builder.h"

EntityBuilder ECreatePlayer(f32 x, f32 y);
EntityBuilder ECreateBlock(f32 x, f32 y, f32 width, f32 height);
EntityBuilder ECreateWalker(f32 x, f32 y);
EntityBuilder ECreateCloudParticle(f32 centerX, f32 centerY, Vector2 direction);
