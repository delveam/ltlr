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

void MenuDraw(const Menu* self)
{
    const f32 zoom = 3;

    const Vector2 cameraCenter = (Vector2)
    {
        .x = CTX_VIEWPORT_WIDTH * 0.5,
        .y = CTX_VIEWPORT_HEIGHT * 0.5,
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

    BeginMode2D(camera);
    {
        ClearBackground(P8_BLUE);

        const Rectangle intramural = (Rectangle)
        {
            .x = 0,
            .y = 0,
            .width = 138,
            .height = 112,
        };

        const AtlasDrawParams params = (AtlasDrawParams)
        {
            .sprite = SPRITE_LOGO,
            .position = (Vector2) { 32, (180.0 - 112) / 2 },
            .intramural = intramural,
            .reflection = REFLECTION_NONE,
            .tint = COLOR_WHITE,
        };
        AtlasDraw(self->atlas, &params);
    }
    EndMode2D();
}

void MenuDestroy(Menu* self)
{
    EventHandlerDestroy(&self->onReady);

    InputProfileDestroy(&self->defaultMenuProfile);
}
