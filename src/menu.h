#pragma once

#include "./ecs/events.h"
#include "atlas.h"
#include "common.h"
#include "input.h"

typedef struct
{
    InputProfile defaultMenuProfile;
    InputHandler input;
    EventHandler onReady;
    Atlas* atlas;

    Rectangle trueResolution;
    RenderTexture2D rootLayer;
    RenderTexture2D targetLayer;
} Menu;

void MenuInit(Menu* self, const Atlas* atlas);
void MenuUpdate(Menu* self);
void MenuDraw(const Menu* self);
void MenuDestroy(Menu* self);
