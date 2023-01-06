#include "./ecs/events.h"
#include "./palette/p8.h"
#include "context.h"
#include "menu.h"
#include "sprites_generated.h"
#include <raymath.h>

void MenuInit(Menu* self, const Atlas* atlas)
{
    self->atlas = (Atlas*)atlas;

    // Setup input.
    {
        self->defaultMenuProfile = InputProfileCreate(1);

        // Keyboard.
        {
            {
                KeyboardBinding binding = KeyboardBindingCreate("select", 2);

                KeyboardBindingAddKey(&binding, KEY_SPACE);
                KeyboardBindingAddKey(&binding, KEY_ENTER);

                InputProfileAddKeyboardBinding(&self->defaultMenuProfile, binding);
            }
        }

        // Gamepad.
        {
            {
                GamepadBinding binding = GamepadBindingCreate("select", 1);

                GamepadBindingAddButton(&binding, GAMEPAD_BUTTON_MIDDLE_LEFT);

                InputProfileAddGamepadBinding(&self->defaultMenuProfile, binding);
            }
        }

        self->input = InputHandlerCreate(0);

        InputHandlerSetProfile(&self->input, &self->defaultMenuProfile);
    }

    self->onReady = EventHandlerCreate();

    // Setup RenderTargets.
    {
        self->rootLayer = LoadRenderTexture(1, 1);
        self->targetLayer = LoadRenderTexture(CTX_VIEWPORT_WIDTH, CTX_VIEWPORT_HEIGHT);
    }
}

void MenuUpdate(Menu* self)
{
    InputHandlerUpdate(&self->input);

    if (InputHandlerPressed(&self->input, "select"))
    {
        InputHandlerConsume(&self->input, "select");

        EventHandlerRaise(&self->onReady, NULL);
    }
}

static void RenderRootLayer(UNUSED const RenderFnParams* params)
{
    ClearBackground(P8_BLUE);
}

static void RenderTargetLayer(const RenderFnParams* params)
{
    const Menu* scene = (Menu*)params->scene;

    ClearBackground(COLOR_TRANSPARENT);

    const Rectangle intramural = (Rectangle)
    {
        .x = 0,
        .y = 0,
        .width = 138,
        .height = 112,
    };
    const AtlasDrawParams drawParams = (AtlasDrawParams)
    {
        .sprite = SPRITE_LOGO,
        .position = (Vector2) { 32, (180.0 - 112) / 2 },
        .intramural = intramural,
        .reflection = REFLECTION_NONE,
        .tint = COLOR_WHITE,
    };
    AtlasDraw(scene->atlas, &drawParams);
}

void MenuDraw(const Menu* self)
{
    const RenderFnParams stationaryCameraParams = (RenderFnParams)
    {
        .scene = (void*)self,
        .cameraBounds = CTX_VIEWPORT,
    };

    RenderLayer(&self->rootLayer, RenderRootLayer, &stationaryCameraParams);
    RenderLayer(&self->targetLayer, RenderTargetLayer, &stationaryCameraParams);

    {
        const Rectangle screenResolution = GetScreenResolution();

        f32 zoom = CalculateZoom(CTX_VIEWPORT, screenResolution);

        // TODO(thismarvin): Expose "preferIntegerScaling" option.
        // Prefer integer scaling.
        zoom = floor(zoom);

        const i32 width = CTX_VIEWPORT_WIDTH * zoom;
        const i32 height = CTX_VIEWPORT_HEIGHT * zoom;

        const Rectangle destination = (Rectangle)
        {
            .x = floor(screenResolution.width * 0.5),
            .y = floor(screenResolution.height * 0.5),
            .width = width,
            .height = height,
        };

        const Vector2 origin = (Vector2)
        {
            .x = floor(width * 0.5),
            .y = floor(height * 0.5),
        };

        BeginDrawing();
        {
            ClearBackground(COLOR_BLACK);

            const RenderTexture renderTextures[2] =
            {
                self->rootLayer,
                self->targetLayer,
            };

            for (usize i = 0; i < 5; ++i)
            {
                const RenderTexture* renderTexture = &renderTextures[i];

                Rectangle source = RectangleFromRenderTexture(renderTexture);
                source.height *= -1;

                DrawTexturePro(renderTexture->texture, source, destination, origin, 0, COLOR_WHITE);
            }
        }
        EndDrawing();
    }
}

void MenuDestroy(Menu* self)
{
    EventHandlerDestroy(&self->onReady);

    UnloadRenderTexture(self->rootLayer);
    UnloadRenderTexture(self->targetLayer);

    InputProfileDestroy(&self->defaultMenuProfile);
}
