#include "context.h"
#include <raymath.h>

static f64 totalTime;
static f32 alpha;

static Rectangle monitorResolution;

void ContextInit(void)
{
    totalTime = 0.0;
    alpha = 0.0;

    // Calculate the monitor's resolution.
    {
        const int currentMonitor = GetCurrentMonitor();

        int width = GetMonitorWidth(currentMonitor);
        int height = GetMonitorHeight(currentMonitor);

        // For every platform except desktop, the following is always true
        if (width == 0 || height == 0)
        {
            width = DEFAULT_WINDOW_WIDTH;
            height = DEFAULT_WINDOW_HEIGHT;
        }

        monitorResolution = (Rectangle)
        {
            .x = 0,
            .y = 0,
            .width = width,
            .height = height,
        };
    }
}

f64 ContextGetTotalTime(void)
{
    return totalTime;
}

void ContextSetTotalTime(const f64 value)
{
    totalTime = value;
}

f32 ContextGetAlpha(void)
{
    return alpha;
}

void ContextSetAlpha(const f32 value)
{
    alpha = value;
}

Rectangle GetMonitorResolution()
{
    return monitorResolution;
}

Rectangle GetScreenResolution()
{
    return (Rectangle)
    {
        .x = 0,
        .y = 0,
        .width = GetScreenWidth(),
        .height = GetScreenHeight(),
    };
}

Rectangle RectangleFromRenderTexture(const RenderTexture* renderTexture)
{
    return (Rectangle)
    {
        .x = 0,
        .y = 0,
        .width = renderTexture->texture.width,
        .height = renderTexture->texture.height,
    };
}

// Returns the maximum value the dimensions of a given region can be multiplied by and still fit
// within a given container.
f32 CalculateZoom(const Rectangle region, const Rectangle container)
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

void RenderLayer
(
    const RenderTexture* renderTexture,
    const RenderFn fn,
    const RenderFnParams* params
)
{
    const Rectangle bounds = RectangleFromRenderTexture(renderTexture);
    const f32 zoom = CalculateZoom(CTX_VIEWPORT, bounds);

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
