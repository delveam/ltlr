#include "./ecs/events.h"
#include "./palette/p8.h"
#include "context.h"
#include "menu.h"
#include "sprites_generated.h"
#include <raymath.h>

typedef struct
{
    Menu* scene;
    Rectangle cameraBounds;
} RenderFnParams;

typedef void (*RenderFn)(const RenderFnParams*);

static Rectangle RectangleFromRenderTexture(const RenderTexture renderTexture)
{
    return (Rectangle)
    {
        .x = 0,
        .y = 0,
        .width = renderTexture.texture.width,
        .height = renderTexture.texture.height,
    };
}

// Returns the maximum value the dimensions of a given region can be multiplied by and still fit
// within a given container.
static f32 CalculateZoom(const Rectangle region, const Rectangle container)
{
    // Assume we need letterboxing.
    f32 zoom = container.width / region.width;

    // Check if pillarboxing is more appropriate.
    if (region.height * zoom > container.height)
    {
        zoom = container.height / region.height;
    }

    return zoom;
}

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
        self->trueResolution = (Rectangle)
        {
            .x = 0,
            .y = 0,
            .width = CTX_VIEWPORT_WIDTH,
            .height = CTX_VIEWPORT_HEIGHT,
        };

        // TODO(thismarvin): Expose a "Render Resolution" option.

        // Use the monitor's resolution as the default render resolution.
        const int currentMonitor = GetCurrentMonitor();
        int width = GetMonitorWidth(currentMonitor);
        int height = GetMonitorHeight(currentMonitor);

        // The following is always true for every platform except desktop.
        if (width == 0 || height == 0)
        {
            width = DEFAULT_WINDOW_WIDTH;
            height = DEFAULT_WINDOW_HEIGHT;
        }

        const Rectangle renderResolution = (Rectangle)
        {
            .x = 0,
            .y = 0,
            .width = width,
            .height = height,
        };

        f32 zoom = CalculateZoom(self->trueResolution, renderResolution);

        // Ensure that the render resolution uses integer scaling.
        zoom = floor(zoom);

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

        EventHandlerRaise(&self->onReady, 0);
    }
}

static void SceneRenderLayer
(
    const RenderTexture* renderTexture,
    const RenderFn fn,
    const RenderFnParams* params
)
{
    const Rectangle bounds = RectangleFromRenderTexture(*renderTexture);
    const f32 zoom = CalculateZoom(params->scene->trueResolution, bounds);

    const Vector2 cameraCenter = (Vector2)
    {
        .x = params->cameraBounds.x + CTX_VIEWPORT_WIDTH * 0.5,
        .y = params->cameraBounds.y + CTX_VIEWPORT_HEIGHT * 0.5,
    };

    const Camera2D camera = (Camera2D)
    {
        .zoom = zoom,
        .offset = Vector2Scale(cameraCenter, -zoom),
        .target = (Vector2)
        {
            .x = -CTX_VIEWPORT_WIDTH * 0.5,
            .y = -CTX_VIEWPORT_HEIGHT * 0.5,
        },
        .rotation = 0,
    };

    BeginTextureMode(*renderTexture);
    BeginMode2D(camera);
    {
        fn(params);
    }
    EndMode2D();
    EndTextureMode();
}

static void RenderRootLayer(UNUSED const RenderFnParams* params)
{
    ClearBackground(P8_BLUE);
}

static void RenderTargetLayer(const RenderFnParams* params)
{
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
    AtlasDraw(params->scene->atlas, &drawParams);
}

void MenuDraw(const Menu* self)
{
    const RenderFnParams stationaryCameraParams = (RenderFnParams)
    {
        .scene = (Menu*)self,
        .cameraBounds = (Rectangle) { 0, 0, CTX_VIEWPORT_WIDTH, CTX_VIEWPORT_HEIGHT },
    };

    SceneRenderLayer(&self->rootLayer, RenderRootLayer, &stationaryCameraParams);
    SceneRenderLayer(&self->targetLayer, RenderTargetLayer, &stationaryCameraParams);

    {
        BeginDrawing();

        const Rectangle screenResolution = (Rectangle)
        {
            .x = 0,
            .y = 0,
            .width = GetScreenWidth(),
            .height = GetScreenHeight(),
        };

        f32 zoom = CalculateZoom(self->trueResolution, screenResolution);

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

        ClearBackground(BLACK);

        // Draw root layer.
        {
            Rectangle source = RectangleFromRenderTexture(self->rootLayer);
            source.height *= -1;

            DrawTexturePro(self->rootLayer.texture, source, destination, origin, 0, WHITE);
        }
        // Draw target layer.
        {
            Rectangle source = RectangleFromRenderTexture(self->targetLayer);
            source.height *= -1;

            DrawTexturePro(self->targetLayer.texture, source, destination, origin, 0, WHITE);
        }

        EndDrawing();
    }
}

void MenuDestroy(Menu* self)
{
    EventHandlerDestroy(&self->onReady);

    UnloadRenderTexture(self->targetLayer);

    InputProfileDestroy(&self->defaultMenuProfile);
}
