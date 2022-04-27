#include "common.h"
#include "context.h"
#include "scene.h"
#include <math.h>

#if defined(PLATFORM_WEB)
    #include <emscripten/emscripten.h>
#endif

static void Initialize(void);
static void Update(void);
static void Draw(void);

static const f32 targetFrameTime = CTX_DT;
static const u8 maxFrameSkip = 25;
static const f32 maxDeltaTime = maxFrameSkip * targetFrameTime;
static f32 accumulator = 0.0;
static f64 previousTime = 0.0;

static Scene scene;

static void Timestep(void)
{
    f64 currentTime = GetTime();

    f32 deltaTime = currentTime - previousTime;

    // Set a maximum delta time in order to avoid a "spiral of death."
    if (deltaTime > maxDeltaTime)
    {
        deltaTime = maxDeltaTime;
    }

    previousTime = currentTime;

    accumulator += deltaTime;

    while (accumulator >= targetFrameTime)
    {
        Update();

        accumulator -= targetFrameTime;
        ContextSetTotalTime(ContextGetTotalTime() + targetFrameTime);

        PollInputEvents();
    }

    ContextSetAlpha(accumulator / targetFrameTime);

    Draw();

    SwapScreenBuffer();
}

int main(void)
{
    // TODO(thismarvin): Incorporate a config file or cli options for window resolution.
    InitWindow(DEFAULT_WINDOW_WIDTH, DEFAULT_WINDOW_HEIGHT, "LTL");
    InitAudioDevice();

    SetWindowState(FLAG_VSYNC_HINT | FLAG_WINDOW_RESIZABLE);
    SetWindowMinSize(CTX_VIEWPORT_WIDTH, CTX_VIEWPORT_HEIGHT);

    Initialize();

    previousTime = GetTime();

#if defined(PLATFORM_WEB)
    emscripten_set_main_loop(Timestep, 0, 1);
#else

    while (!WindowShouldClose()) // Detect window close button or ESC key
    {
        Timestep();
    }

#endif

    SceneDestroy(&scene);

    CloseAudioDevice();
    CloseWindow();

    return 0;
}

static void Initialize(void)
{
    SceneInit(&scene);
}

static void Update(void)
{
    SceneUpdate(&scene);
}

static void Draw(void)
{
    SceneDraw(&scene);
}
