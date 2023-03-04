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

		monitorResolution = (Rectangle) {
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

Rectangle GetMonitorResolution(void)
{
	return monitorResolution;
}

Rectangle GetRenderResolution(void)
{
	return (Rectangle) {
		.x = 0,
		.y = 0,
		.width = GetRenderWidth(),
		.height = GetRenderHeight(),
	};
}

Rectangle RectangleFromRenderTexture(const RenderTexture* renderTexture)
{
	return (Rectangle) {
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

void RenderLayer(
	const RenderTexture* renderTexture,
	const RenderFn fn,
	const RenderFnParams* params
)
{
	const Rectangle bounds = RectangleFromRenderTexture(renderTexture);
	const f32 zoom = CalculateZoom(CTX_VIEWPORT, bounds);

	const Vector2 cameraCenter = (Vector2) {
		.x = params->cameraBounds.x + CTX_VIEWPORT_WIDTH * 0.5,
		.y = params->cameraBounds.y + CTX_VIEWPORT_HEIGHT * 0.5,
	};

	const Camera2D camera = (Camera2D) {
		.zoom = zoom,
		.offset = Vector2Scale(cameraCenter, -zoom),
		.target =
			(Vector2) {
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

void DrawLayers(const RenderTexture* renderTextures, const usize renderTexturesLength)
{
	const Rectangle renderResolution = GetRenderResolution();

	f32 zoom = CalculateZoom(CTX_VIEWPORT, renderResolution);

	// TODO(thismarvin): Expose "preferIntegerScaling" option.
	// Prefer integer scaling.
	zoom = floor(zoom);

	const i32 width = CTX_VIEWPORT_WIDTH * zoom;
	const i32 height = CTX_VIEWPORT_HEIGHT * zoom;

	const Rectangle destination = (Rectangle) {
		.x = floor(renderResolution.width * 0.5),
		.y = floor(renderResolution.height * 0.5),
		.width = width,
		.height = height,
	};

	const Vector2 origin = (Vector2) {
		.x = floor(width * 0.5),
		.y = floor(height * 0.5),
	};

	BeginDrawing();
	{
		ClearBackground(COLOR_BLACK);

		for (usize i = 0; i < renderTexturesLength; ++i)
		{
			const RenderTexture* renderTexture = &renderTextures[i];

			Rectangle source = RectangleFromRenderTexture(renderTexture);
			source.height *= -1;

			DrawTexturePro(renderTexture->texture, source, destination, origin, 0, WHITE);
		}
	}
	EndDrawing();
}
