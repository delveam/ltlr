#pragma once

#include "common.h"
#include "entity_creator.h"
#include "scene.h"

usize ECreatePlayer(Scene* scene, const ECreatorContext* createContext);
usize ECreateBlock(Scene* scene, const ECreatorContext* createContext);
usize ECreateWalker(Scene* scene, const ECreatorContext* createContext);
usize ECreateCloudParticle(Scene* scene, const ECreatorContext* createContext);
