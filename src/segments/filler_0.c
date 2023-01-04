// This file was auto-generated; any changes you make may be overwritten.

#include "../ecs/entities.h"
#include "../segments_generated.h"
#include "../segments_helper.h"

LevelSegmentBuilder LevelSegmentBuilderCreate_filler_0(const Vector2 offset)
{
    Deque entities = DEQUE_WITH_CAPACITY(EntityBuilder, 27);
    CREATE_SOLID_BLOCK(0, 160, 192, 96);
    CREATE_SOLID_BLOCK(192, 96, 48, 160);
    CREATE_SOLID_BLOCK(304, 128, 48, 128);
    CREATE_SOLID_BLOCK(400, 128, 48, 128);
    CREATE_SOLID_BLOCK(496, 96, 48, 160);
    CREATE_SOLID_BLOCK(544, 160, 96, 96);
    CREATE_ONE_WAY_BLOCK(176, 48, 192, 16);
    CREATE_ONE_WAY_BLOCK(96, 128, 96, 16);
    CREATE_ONE_WAY_BLOCK(544, 128, 64, 16);
    CREATE_SPIKE(240, 112, SPIKE_ROTATE_90);
    CREATE_SPIKE(240, 128, SPIKE_ROTATE_90);
    CREATE_SPIKE(160, 144, SPIKE_ROTATE_0);
    CREATE_SPIKE(176, 144, SPIKE_ROTATE_0);
    CREATE_SPIKE(240, 144, SPIKE_ROTATE_90);
    CREATE_SPIKE(288, 144, SPIKE_ROTATE_270);
    CREATE_SPIKE(384, 144, SPIKE_ROTATE_270);
    CREATE_SPIKE(240, 160, SPIKE_ROTATE_90);
    CREATE_SPIKE(288, 160, SPIKE_ROTATE_270);
    CREATE_SPIKE(352, 160, SPIKE_ROTATE_90);
    CREATE_SPIKE(384, 160, SPIKE_ROTATE_270);
    CREATE_SPIKE(448, 160, SPIKE_ROTATE_90);
    CREATE_SPIKE(240, 176, SPIKE_ROTATE_90);
    CREATE_SPIKE(288, 176, SPIKE_ROTATE_270);
    CREATE_SPIKE(352, 176, SPIKE_ROTATE_90);
    CREATE_SPIKE(384, 176, SPIKE_ROTATE_270);
    CREATE_SPIKE(448, 176, SPIKE_ROTATE_90);
    CREATE_SPIKE(480, 176, SPIKE_ROTATE_270);
    const u16 width = 640;
    return (LevelSegmentBuilder)
    {
        .entities = entities,
        .width = width,
    };
}

void LevelSegmentDraw_filler_0(const Atlas* atlas, const Vector2 offset)
{
    DRAW_SPRITE(SPRITE_BLOCK_7_0012, 80, 16);
    DRAW_SPRITE(SPRITE_BLOCK_7_0006, 96, 16);
    DRAW_SPRITE(SPRITE_BLOCK_7_0013, 80, 32);
    DRAW_SPRITE(SPRITE_BLOCK_7_0015, 96, 32);
    DRAW_SPRITE(SPRITE_BLOCK_7_0006, 112, 32);
    DRAW_SPRITE(SPRITE_BLOCK_7_0013, 80, 48);
    DRAW_SPRITE(SPRITE_BLOCK_7_0015, 96, 48);
    DRAW_SPRITE(SPRITE_BLOCK_7_0003, 112, 48);
    DRAW_SPRITE(SPRITE_BLOCK_7_0013, 80, 64);
    DRAW_SPRITE(SPRITE_BLOCK_7_0003, 96, 64);
    DRAW_SPRITE(SPRITE_BLOCK_2_0012, 112, 64);
    DRAW_COVER_UP(122, 74, COLOR_BLACK);
    DRAW_SPRITE(SPRITE_BLOCK_2_0014, 128, 64);
    DRAW_COVER_UP(128, 74, COLOR_BLACK);
    DRAW_COVER_UP(138, 74, COLOR_BLACK);
    DRAW_SPRITE(SPRITE_BLOCK_2_0006, 144, 64);
    DRAW_COVER_UP(144, 74, COLOR_BLACK);
    DRAW_SPRITE(SPRITE_BLOCK_7_0001, 80, 80);
    DRAW_SPRITE(SPRITE_BLOCK_2_0012, 96, 80);
    DRAW_COVER_UP(106, 90, COLOR_BLACK);
    DRAW_SPRITE(SPRITE_BLOCK_2_0015, 112, 80);
    DRAW_COVER_UP(112, 90, COLOR_BLACK);
    DRAW_COVER_UP(122, 90, COLOR_BLACK);
    DRAW_COVER_UP(122, 80, COLOR_BLACK);
    DRAW_SPRITE(SPRITE_BLOCK_2_0015, 128, 80);
    DRAW_COVER_UP(128, 80, COLOR_BLACK);
    DRAW_COVER_UP(128, 90, COLOR_BLACK);
    DRAW_COVER_UP(138, 90, COLOR_BLACK);
    DRAW_COVER_UP(138, 80, COLOR_BLACK);
    DRAW_SPRITE(SPRITE_BLOCK_2_0007, 144, 80);
    DRAW_COVER_UP(144, 80, COLOR_BLACK);
    DRAW_COVER_UP(144, 90, COLOR_BLACK);
    DRAW_SPRITE(SPRITE_BLOCK_2_0012, 352, 80);
    DRAW_COVER_UP(362, 90, COLOR_BLACK);
    DRAW_SPRITE(SPRITE_BLOCK_2_0006, 368, 80);
    DRAW_COVER_UP(368, 90, COLOR_BLACK);
    DRAW_SPRITE(SPRITE_BLOCK_2_0012, 64, 96);
    DRAW_COVER_UP(74, 106, COLOR_BLACK);
    DRAW_SPRITE(SPRITE_BLOCK_2_0014, 80, 96);
    DRAW_COVER_UP(80, 106, COLOR_BLACK);
    DRAW_COVER_UP(90, 106, COLOR_BLACK);
    DRAW_SPRITE(SPRITE_BLOCK_2_0015, 96, 96);
    DRAW_COVER_UP(96, 106, COLOR_BLACK);
    DRAW_COVER_UP(106, 106, COLOR_BLACK);
    DRAW_COVER_UP(106, 96, COLOR_BLACK);
    DRAW_SPRITE(SPRITE_BLOCK_2_0015, 112, 96);
    DRAW_COVER_UP(112, 96, COLOR_BLACK);
    DRAW_COVER_UP(112, 106, COLOR_BLACK);
    DRAW_COVER_UP(122, 106, COLOR_BLACK);
    DRAW_COVER_UP(122, 96, COLOR_BLACK);
    DRAW_SPRITE(SPRITE_BLOCK_2_0015, 128, 96);
    DRAW_COVER_UP(128, 96, COLOR_BLACK);
    DRAW_COVER_UP(128, 106, COLOR_BLACK);
    DRAW_COVER_UP(138, 106, COLOR_BLACK);
    DRAW_COVER_UP(138, 96, COLOR_BLACK);
    DRAW_SPRITE(SPRITE_BLOCK_2_0015, 144, 96);
    DRAW_COVER_UP(144, 96, COLOR_BLACK);
    DRAW_COVER_UP(144, 106, COLOR_BLACK);
    DRAW_COVER_UP(154, 106, COLOR_BLACK);
    DRAW_SPRITE(SPRITE_BLOCK_2_0006, 160, 96);
    DRAW_COVER_UP(160, 106, COLOR_BLACK);
    DRAW_SPRITE(SPRITE_BLOCK_2_0012, 304, 96);
    DRAW_COVER_UP(314, 106, COLOR_BLACK);
    DRAW_SPRITE(SPRITE_BLOCK_2_0014, 320, 96);
    DRAW_COVER_UP(320, 106, COLOR_BLACK);
    DRAW_COVER_UP(330, 106, COLOR_BLACK);
    DRAW_SPRITE(SPRITE_BLOCK_2_0014, 336, 96);
    DRAW_COVER_UP(336, 106, COLOR_BLACK);
    DRAW_COVER_UP(346, 106, COLOR_BLACK);
    DRAW_SPRITE(SPRITE_BLOCK_2_0015, 352, 96);
    DRAW_COVER_UP(352, 106, COLOR_BLACK);
    DRAW_COVER_UP(362, 106, COLOR_BLACK);
    DRAW_COVER_UP(362, 96, COLOR_BLACK);
    DRAW_SPRITE(SPRITE_BLOCK_2_0007, 368, 96);
    DRAW_COVER_UP(368, 96, COLOR_BLACK);
    DRAW_COVER_UP(368, 106, COLOR_BLACK);
    DRAW_SPRITE(SPRITE_BLOCK_2_0012, 48, 112);
    DRAW_COVER_UP(58, 122, COLOR_BLACK);
    DRAW_SPRITE(SPRITE_BLOCK_2_0015, 64, 112);
    DRAW_COVER_UP(64, 122, COLOR_BLACK);
    DRAW_COVER_UP(74, 122, COLOR_BLACK);
    DRAW_COVER_UP(74, 112, COLOR_BLACK);
    DRAW_SPRITE(SPRITE_BLOCK_2_0015, 80, 112);
    DRAW_COVER_UP(80, 112, COLOR_BLACK);
    DRAW_COVER_UP(80, 122, COLOR_BLACK);
    DRAW_COVER_UP(90, 122, COLOR_BLACK);
    DRAW_COVER_UP(90, 112, COLOR_BLACK);
    DRAW_SPRITE(SPRITE_BLOCK_2_0015, 96, 112);
    DRAW_COVER_UP(96, 112, COLOR_BLACK);
    DRAW_COVER_UP(96, 122, COLOR_BLACK);
    DRAW_COVER_UP(106, 122, COLOR_BLACK);
    DRAW_COVER_UP(106, 112, COLOR_BLACK);
    DRAW_SPRITE(SPRITE_BLOCK_2_0015, 112, 112);
    DRAW_COVER_UP(112, 112, COLOR_BLACK);
    DRAW_COVER_UP(112, 122, COLOR_BLACK);
    DRAW_COVER_UP(122, 122, COLOR_BLACK);
    DRAW_COVER_UP(122, 112, COLOR_BLACK);
    DRAW_SPRITE(SPRITE_BLOCK_2_0015, 128, 112);
    DRAW_COVER_UP(128, 112, COLOR_BLACK);
    DRAW_COVER_UP(128, 122, COLOR_BLACK);
    DRAW_COVER_UP(138, 122, COLOR_BLACK);
    DRAW_COVER_UP(138, 112, COLOR_BLACK);
    DRAW_SPRITE(SPRITE_BLOCK_2_0015, 144, 112);
    DRAW_COVER_UP(144, 112, COLOR_BLACK);
    DRAW_COVER_UP(144, 122, COLOR_BLACK);
    DRAW_COVER_UP(154, 122, COLOR_BLACK);
    DRAW_COVER_UP(154, 112, COLOR_BLACK);
    DRAW_SPRITE(SPRITE_BLOCK_2_0007, 160, 112);
    DRAW_COVER_UP(160, 112, COLOR_BLACK);
    DRAW_COVER_UP(160, 122, COLOR_BLACK);
    DRAW_SPRITE(SPRITE_BLOCK_2_0012, 288, 112);
    DRAW_COVER_UP(298, 122, COLOR_BLACK);
    DRAW_SPRITE(SPRITE_BLOCK_2_0015, 304, 112);
    DRAW_COVER_UP(304, 122, COLOR_BLACK);
    DRAW_COVER_UP(314, 122, COLOR_BLACK);
    DRAW_COVER_UP(314, 112, COLOR_BLACK);
    DRAW_SPRITE(SPRITE_BLOCK_2_0015, 320, 112);
    DRAW_COVER_UP(320, 112, COLOR_BLACK);
    DRAW_COVER_UP(320, 122, COLOR_BLACK);
    DRAW_COVER_UP(330, 122, COLOR_BLACK);
    DRAW_COVER_UP(330, 112, COLOR_BLACK);
    DRAW_SPRITE(SPRITE_BLOCK_2_0015, 336, 112);
    DRAW_COVER_UP(336, 112, COLOR_BLACK);
    DRAW_COVER_UP(336, 122, COLOR_BLACK);
    DRAW_COVER_UP(346, 122, COLOR_BLACK);
    DRAW_COVER_UP(346, 112, COLOR_BLACK);
    DRAW_SPRITE(SPRITE_BLOCK_2_0015, 352, 112);
    DRAW_COVER_UP(352, 112, COLOR_BLACK);
    DRAW_COVER_UP(352, 122, COLOR_BLACK);
    DRAW_COVER_UP(362, 122, COLOR_BLACK);
    DRAW_COVER_UP(362, 112, COLOR_BLACK);
    DRAW_SPRITE(SPRITE_BLOCK_2_0007, 368, 112);
    DRAW_COVER_UP(368, 112, COLOR_BLACK);
    DRAW_COVER_UP(368, 122, COLOR_BLACK);
    DRAW_SPRITE(SPRITE_BLOCK_2_0013, 48, 128);
    DRAW_COVER_UP(58, 138, COLOR_BLACK);
    DRAW_COVER_UP(58, 128, COLOR_BLACK);
    DRAW_SPRITE(SPRITE_BLOCK_2_0015, 64, 128);
    DRAW_COVER_UP(64, 128, COLOR_BLACK);
    DRAW_COVER_UP(64, 138, COLOR_BLACK);
    DRAW_COVER_UP(74, 138, COLOR_BLACK);
    DRAW_COVER_UP(74, 128, COLOR_BLACK);
    DRAW_SPRITE(SPRITE_BLOCK_2_0015, 80, 128);
    DRAW_COVER_UP(80, 128, COLOR_BLACK);
    DRAW_COVER_UP(80, 138, COLOR_BLACK);
    DRAW_COVER_UP(90, 138, COLOR_BLACK);
    DRAW_COVER_UP(90, 128, COLOR_BLACK);
    DRAW_SPRITE(SPRITE_BLOCK_2_0015, 96, 128);
    DRAW_COVER_UP(96, 128, COLOR_BLACK);
    DRAW_COVER_UP(96, 138, COLOR_BLACK);
    DRAW_COVER_UP(106, 138, COLOR_BLACK);
    DRAW_COVER_UP(106, 128, COLOR_BLACK);
    DRAW_SPRITE(SPRITE_BLOCK_2_0015, 112, 128);
    DRAW_COVER_UP(112, 128, COLOR_BLACK);
    DRAW_COVER_UP(112, 138, COLOR_BLACK);
    DRAW_COVER_UP(122, 138, COLOR_BLACK);
    DRAW_COVER_UP(122, 128, COLOR_BLACK);
    DRAW_SPRITE(SPRITE_BLOCK_2_0015, 128, 128);
    DRAW_COVER_UP(128, 128, COLOR_BLACK);
    DRAW_COVER_UP(128, 138, COLOR_BLACK);
    DRAW_COVER_UP(138, 138, COLOR_BLACK);
    DRAW_COVER_UP(138, 128, COLOR_BLACK);
    DRAW_SPRITE(SPRITE_BLOCK_2_0015, 144, 128);
    DRAW_COVER_UP(144, 128, COLOR_BLACK);
    DRAW_COVER_UP(144, 138, COLOR_BLACK);
    DRAW_COVER_UP(154, 138, COLOR_BLACK);
    DRAW_COVER_UP(154, 128, COLOR_BLACK);
    DRAW_SPRITE(SPRITE_BLOCK_2_0007, 160, 128);
    DRAW_COVER_UP(160, 128, COLOR_BLACK);
    DRAW_COVER_UP(160, 138, COLOR_BLACK);
    DRAW_SPRITE(SPRITE_BLOCK_2_0013, 288, 128);
    DRAW_COVER_UP(298, 138, COLOR_BLACK);
    DRAW_COVER_UP(298, 128, COLOR_BLACK);
    DRAW_SPRITE(SPRITE_BLOCK_2_0015, 304, 128);
    DRAW_COVER_UP(304, 128, COLOR_BLACK);
    DRAW_COVER_UP(304, 138, COLOR_BLACK);
    DRAW_COVER_UP(314, 138, COLOR_BLACK);
    DRAW_COVER_UP(314, 128, COLOR_BLACK);
    DRAW_SPRITE(SPRITE_BLOCK_2_0015, 320, 128);
    DRAW_COVER_UP(320, 128, COLOR_BLACK);
    DRAW_COVER_UP(320, 138, COLOR_BLACK);
    DRAW_COVER_UP(330, 138, COLOR_BLACK);
    DRAW_COVER_UP(330, 128, COLOR_BLACK);
    DRAW_SPRITE(SPRITE_BLOCK_2_0015, 336, 128);
    DRAW_COVER_UP(336, 128, COLOR_BLACK);
    DRAW_COVER_UP(336, 138, COLOR_BLACK);
    DRAW_COVER_UP(346, 138, COLOR_BLACK);
    DRAW_COVER_UP(346, 128, COLOR_BLACK);
    DRAW_SPRITE(SPRITE_BLOCK_2_0015, 352, 128);
    DRAW_COVER_UP(352, 128, COLOR_BLACK);
    DRAW_COVER_UP(352, 138, COLOR_BLACK);
    DRAW_COVER_UP(362, 138, COLOR_BLACK);
    DRAW_COVER_UP(362, 128, COLOR_BLACK);
    DRAW_SPRITE(SPRITE_BLOCK_2_0007, 368, 128);
    DRAW_COVER_UP(368, 128, COLOR_BLACK);
    DRAW_COVER_UP(368, 138, COLOR_BLACK);
    DRAW_SPRITE(SPRITE_BLOCK_2_0012, 496, 128);
    DRAW_COVER_UP(506, 138, COLOR_BLACK);
    DRAW_SPRITE(SPRITE_BLOCK_2_0006, 512, 128);
    DRAW_COVER_UP(512, 138, COLOR_BLACK);
    DRAW_SPRITE(SPRITE_BLOCK_2_0012, 32, 144);
    DRAW_COVER_UP(42, 154, COLOR_BLACK);
    DRAW_SPRITE(SPRITE_BLOCK_2_0015, 48, 144);
    DRAW_COVER_UP(48, 154, COLOR_BLACK);
    DRAW_COVER_UP(58, 154, COLOR_BLACK);
    DRAW_COVER_UP(58, 144, COLOR_BLACK);
    DRAW_SPRITE(SPRITE_BLOCK_2_0015, 64, 144);
    DRAW_COVER_UP(64, 144, COLOR_BLACK);
    DRAW_COVER_UP(64, 154, COLOR_BLACK);
    DRAW_COVER_UP(74, 154, COLOR_BLACK);
    DRAW_COVER_UP(74, 144, COLOR_BLACK);
    DRAW_SPRITE(SPRITE_BLOCK_2_0015, 80, 144);
    DRAW_COVER_UP(80, 144, COLOR_BLACK);
    DRAW_COVER_UP(80, 154, COLOR_BLACK);
    DRAW_COVER_UP(90, 154, COLOR_BLACK);
    DRAW_COVER_UP(90, 144, COLOR_BLACK);
    DRAW_SPRITE(SPRITE_BLOCK_2_0015, 96, 144);
    DRAW_COVER_UP(96, 144, COLOR_BLACK);
    DRAW_COVER_UP(96, 154, COLOR_BLACK);
    DRAW_COVER_UP(106, 154, COLOR_BLACK);
    DRAW_COVER_UP(106, 144, COLOR_BLACK);
    DRAW_SPRITE(SPRITE_BLOCK_2_0015, 112, 144);
    DRAW_COVER_UP(112, 144, COLOR_BLACK);
    DRAW_COVER_UP(112, 154, COLOR_BLACK);
    DRAW_COVER_UP(122, 154, COLOR_BLACK);
    DRAW_COVER_UP(122, 144, COLOR_BLACK);
    DRAW_SPRITE(SPRITE_BLOCK_2_0015, 128, 144);
    DRAW_COVER_UP(128, 144, COLOR_BLACK);
    DRAW_COVER_UP(128, 154, COLOR_BLACK);
    DRAW_COVER_UP(138, 154, COLOR_BLACK);
    DRAW_COVER_UP(138, 144, COLOR_BLACK);
    DRAW_SPRITE(SPRITE_BLOCK_2_0015, 144, 144);
    DRAW_COVER_UP(144, 144, COLOR_BLACK);
    DRAW_COVER_UP(144, 154, COLOR_BLACK);
    DRAW_COVER_UP(154, 154, COLOR_BLACK);
    DRAW_COVER_UP(154, 144, COLOR_BLACK);
    DRAW_SPRITE(SPRITE_BLOCK_2_0015, 160, 144);
    DRAW_COVER_UP(160, 144, COLOR_BLACK);
    DRAW_COVER_UP(160, 154, COLOR_BLACK);
    DRAW_COVER_UP(170, 154, COLOR_BLACK);
    DRAW_SPRITE(SPRITE_BLOCK_2_0014, 176, 144);
    DRAW_COVER_UP(176, 154, COLOR_BLACK);
    DRAW_COVER_UP(186, 154, COLOR_BLACK);
    DRAW_SPRITE(SPRITE_BLOCK_2_0014, 192, 144);
    DRAW_COVER_UP(192, 154, COLOR_BLACK);
    DRAW_COVER_UP(202, 154, COLOR_BLACK);
    DRAW_SPRITE(SPRITE_BLOCK_2_0014, 208, 144);
    DRAW_COVER_UP(208, 154, COLOR_BLACK);
    DRAW_COVER_UP(218, 154, COLOR_BLACK);
    DRAW_SPRITE(SPRITE_BLOCK_2_0006, 224, 144);
    DRAW_COVER_UP(224, 154, COLOR_BLACK);
    DRAW_SPRITE(SPRITE_BLOCK_2_0012, 272, 144);
    DRAW_COVER_UP(282, 154, COLOR_BLACK);
    DRAW_SPRITE(SPRITE_BLOCK_2_0015, 288, 144);
    DRAW_COVER_UP(288, 154, COLOR_BLACK);
    DRAW_COVER_UP(298, 154, COLOR_BLACK);
    DRAW_COVER_UP(298, 144, COLOR_BLACK);
    DRAW_SPRITE(SPRITE_BLOCK_2_0015, 304, 144);
    DRAW_COVER_UP(304, 144, COLOR_BLACK);
    DRAW_COVER_UP(304, 154, COLOR_BLACK);
    DRAW_COVER_UP(314, 154, COLOR_BLACK);
    DRAW_COVER_UP(314, 144, COLOR_BLACK);
    DRAW_SPRITE(SPRITE_BLOCK_2_0015, 320, 144);
    DRAW_COVER_UP(320, 144, COLOR_BLACK);
    DRAW_COVER_UP(320, 154, COLOR_BLACK);
    DRAW_COVER_UP(330, 154, COLOR_BLACK);
    DRAW_COVER_UP(330, 144, COLOR_BLACK);
    DRAW_SPRITE(SPRITE_BLOCK_2_0015, 336, 144);
    DRAW_COVER_UP(336, 144, COLOR_BLACK);
    DRAW_COVER_UP(336, 154, COLOR_BLACK);
    DRAW_COVER_UP(346, 154, COLOR_BLACK);
    DRAW_COVER_UP(346, 144, COLOR_BLACK);
    DRAW_SPRITE(SPRITE_BLOCK_2_0015, 352, 144);
    DRAW_COVER_UP(352, 144, COLOR_BLACK);
    DRAW_COVER_UP(352, 154, COLOR_BLACK);
    DRAW_COVER_UP(362, 154, COLOR_BLACK);
    DRAW_COVER_UP(362, 144, COLOR_BLACK);
    DRAW_SPRITE(SPRITE_BLOCK_2_0015, 368, 144);
    DRAW_COVER_UP(368, 144, COLOR_BLACK);
    DRAW_COVER_UP(368, 154, COLOR_BLACK);
    DRAW_COVER_UP(378, 154, COLOR_BLACK);
    DRAW_SPRITE(SPRITE_BLOCK_2_0006, 384, 144);
    DRAW_COVER_UP(384, 154, COLOR_BLACK);
    DRAW_SPRITE(SPRITE_BLOCK_2_0012, 464, 144);
    DRAW_COVER_UP(474, 154, COLOR_BLACK);
    DRAW_SPRITE(SPRITE_BLOCK_2_0014, 480, 144);
    DRAW_COVER_UP(480, 154, COLOR_BLACK);
    DRAW_COVER_UP(490, 154, COLOR_BLACK);
    DRAW_SPRITE(SPRITE_BLOCK_2_0015, 496, 144);
    DRAW_COVER_UP(496, 154, COLOR_BLACK);
    DRAW_COVER_UP(506, 154, COLOR_BLACK);
    DRAW_COVER_UP(506, 144, COLOR_BLACK);
    DRAW_SPRITE(SPRITE_BLOCK_2_0007, 512, 144);
    DRAW_COVER_UP(512, 144, COLOR_BLACK);
    DRAW_COVER_UP(512, 154, COLOR_BLACK);
    DRAW_SPRITE(SPRITE_BLOCK_2_0013, 32, 160);
    DRAW_COVER_UP(42, 170, COLOR_BLACK);
    DRAW_COVER_UP(42, 160, COLOR_BLACK);
    DRAW_SPRITE(SPRITE_BLOCK_2_0015, 48, 160);
    DRAW_COVER_UP(48, 160, COLOR_BLACK);
    DRAW_COVER_UP(48, 170, COLOR_BLACK);
    DRAW_COVER_UP(58, 170, COLOR_BLACK);
    DRAW_COVER_UP(58, 160, COLOR_BLACK);
    DRAW_SPRITE(SPRITE_BLOCK_2_0015, 64, 160);
    DRAW_COVER_UP(64, 160, COLOR_BLACK);
    DRAW_COVER_UP(64, 170, COLOR_BLACK);
    DRAW_COVER_UP(74, 170, COLOR_BLACK);
    DRAW_COVER_UP(74, 160, COLOR_BLACK);
    DRAW_SPRITE(SPRITE_BLOCK_2_0015, 80, 160);
    DRAW_COVER_UP(80, 160, COLOR_BLACK);
    DRAW_COVER_UP(80, 170, COLOR_BLACK);
    DRAW_COVER_UP(90, 170, COLOR_BLACK);
    DRAW_COVER_UP(90, 160, COLOR_BLACK);
    DRAW_SPRITE(SPRITE_BLOCK_2_0015, 96, 160);
    DRAW_COVER_UP(96, 160, COLOR_BLACK);
    DRAW_COVER_UP(96, 170, COLOR_BLACK);
    DRAW_COVER_UP(106, 170, COLOR_BLACK);
    DRAW_COVER_UP(106, 160, COLOR_BLACK);
    DRAW_SPRITE(SPRITE_BLOCK_2_0015, 112, 160);
    DRAW_COVER_UP(112, 160, COLOR_BLACK);
    DRAW_COVER_UP(112, 170, COLOR_BLACK);
    DRAW_COVER_UP(122, 170, COLOR_BLACK);
    DRAW_COVER_UP(122, 160, COLOR_BLACK);
    DRAW_SPRITE(SPRITE_BLOCK_2_0015, 128, 160);
    DRAW_COVER_UP(128, 160, COLOR_BLACK);
    DRAW_COVER_UP(128, 170, COLOR_BLACK);
    DRAW_COVER_UP(138, 170, COLOR_BLACK);
    DRAW_COVER_UP(138, 160, COLOR_BLACK);
    DRAW_SPRITE(SPRITE_BLOCK_2_0015, 144, 160);
    DRAW_COVER_UP(144, 160, COLOR_BLACK);
    DRAW_COVER_UP(144, 170, COLOR_BLACK);
    DRAW_COVER_UP(154, 170, COLOR_BLACK);
    DRAW_COVER_UP(154, 160, COLOR_BLACK);
    DRAW_SPRITE(SPRITE_BLOCK_2_0015, 160, 160);
    DRAW_COVER_UP(160, 160, COLOR_BLACK);
    DRAW_COVER_UP(160, 170, COLOR_BLACK);
    DRAW_COVER_UP(170, 170, COLOR_BLACK);
    DRAW_COVER_UP(170, 160, COLOR_BLACK);
    DRAW_SPRITE(SPRITE_BLOCK_2_0015, 176, 160);
    DRAW_COVER_UP(176, 160, COLOR_BLACK);
    DRAW_COVER_UP(176, 170, COLOR_BLACK);
    DRAW_COVER_UP(186, 170, COLOR_BLACK);
    DRAW_COVER_UP(186, 160, COLOR_BLACK);
    DRAW_SPRITE(SPRITE_BLOCK_2_0015, 192, 160);
    DRAW_COVER_UP(192, 160, COLOR_BLACK);
    DRAW_COVER_UP(192, 170, COLOR_BLACK);
    DRAW_COVER_UP(202, 170, COLOR_BLACK);
    DRAW_COVER_UP(202, 160, COLOR_BLACK);
    DRAW_SPRITE(SPRITE_BLOCK_2_0015, 208, 160);
    DRAW_COVER_UP(208, 160, COLOR_BLACK);
    DRAW_COVER_UP(208, 170, COLOR_BLACK);
    DRAW_COVER_UP(218, 170, COLOR_BLACK);
    DRAW_COVER_UP(218, 160, COLOR_BLACK);
    DRAW_SPRITE(SPRITE_BLOCK_2_0015, 224, 160);
    DRAW_COVER_UP(224, 160, COLOR_BLACK);
    DRAW_COVER_UP(224, 170, COLOR_BLACK);
    DRAW_COVER_UP(234, 170, COLOR_BLACK);
    DRAW_SPRITE(SPRITE_BLOCK_2_0014, 240, 160);
    DRAW_COVER_UP(240, 170, COLOR_BLACK);
    DRAW_COVER_UP(250, 170, COLOR_BLACK);
    DRAW_SPRITE(SPRITE_BLOCK_2_0014, 256, 160);
    DRAW_COVER_UP(256, 170, COLOR_BLACK);
    DRAW_COVER_UP(266, 170, COLOR_BLACK);
    DRAW_SPRITE(SPRITE_BLOCK_2_0015, 272, 160);
    DRAW_COVER_UP(272, 170, COLOR_BLACK);
    DRAW_COVER_UP(282, 170, COLOR_BLACK);
    DRAW_COVER_UP(282, 160, COLOR_BLACK);
    DRAW_SPRITE(SPRITE_BLOCK_2_0015, 288, 160);
    DRAW_COVER_UP(288, 160, COLOR_BLACK);
    DRAW_COVER_UP(288, 170, COLOR_BLACK);
    DRAW_COVER_UP(298, 170, COLOR_BLACK);
    DRAW_COVER_UP(298, 160, COLOR_BLACK);
    DRAW_SPRITE(SPRITE_BLOCK_2_0015, 304, 160);
    DRAW_COVER_UP(304, 160, COLOR_BLACK);
    DRAW_COVER_UP(304, 170, COLOR_BLACK);
    DRAW_COVER_UP(314, 170, COLOR_BLACK);
    DRAW_COVER_UP(314, 160, COLOR_BLACK);
    DRAW_SPRITE(SPRITE_BLOCK_2_0015, 320, 160);
    DRAW_COVER_UP(320, 160, COLOR_BLACK);
    DRAW_COVER_UP(320, 170, COLOR_BLACK);
    DRAW_COVER_UP(330, 170, COLOR_BLACK);
    DRAW_COVER_UP(330, 160, COLOR_BLACK);
    DRAW_SPRITE(SPRITE_BLOCK_2_0015, 336, 160);
    DRAW_COVER_UP(336, 160, COLOR_BLACK);
    DRAW_COVER_UP(336, 170, COLOR_BLACK);
    DRAW_COVER_UP(346, 170, COLOR_BLACK);
    DRAW_COVER_UP(346, 160, COLOR_BLACK);
    DRAW_SPRITE(SPRITE_BLOCK_2_0015, 352, 160);
    DRAW_COVER_UP(352, 160, COLOR_BLACK);
    DRAW_COVER_UP(352, 170, COLOR_BLACK);
    DRAW_COVER_UP(362, 170, COLOR_BLACK);
    DRAW_COVER_UP(362, 160, COLOR_BLACK);
    DRAW_SPRITE(SPRITE_BLOCK_2_0015, 368, 160);
    DRAW_COVER_UP(368, 160, COLOR_BLACK);
    DRAW_COVER_UP(368, 170, COLOR_BLACK);
    DRAW_COVER_UP(378, 170, COLOR_BLACK);
    DRAW_COVER_UP(378, 160, COLOR_BLACK);
    DRAW_SPRITE(SPRITE_BLOCK_2_0015, 384, 160);
    DRAW_COVER_UP(384, 160, COLOR_BLACK);
    DRAW_COVER_UP(384, 170, COLOR_BLACK);
    DRAW_COVER_UP(394, 170, COLOR_BLACK);
    DRAW_SPRITE(SPRITE_BLOCK_2_0014, 400, 160);
    DRAW_COVER_UP(400, 170, COLOR_BLACK);
    DRAW_COVER_UP(410, 170, COLOR_BLACK);
    DRAW_SPRITE(SPRITE_BLOCK_2_0014, 416, 160);
    DRAW_COVER_UP(416, 170, COLOR_BLACK);
    DRAW_COVER_UP(426, 170, COLOR_BLACK);
    DRAW_SPRITE(SPRITE_BLOCK_2_0014, 432, 160);
    DRAW_COVER_UP(432, 170, COLOR_BLACK);
    DRAW_COVER_UP(442, 170, COLOR_BLACK);
    DRAW_SPRITE(SPRITE_BLOCK_2_0014, 448, 160);
    DRAW_COVER_UP(448, 170, COLOR_BLACK);
    DRAW_COVER_UP(458, 170, COLOR_BLACK);
    DRAW_SPRITE(SPRITE_BLOCK_2_0015, 464, 160);
    DRAW_COVER_UP(464, 170, COLOR_BLACK);
    DRAW_COVER_UP(474, 170, COLOR_BLACK);
    DRAW_COVER_UP(474, 160, COLOR_BLACK);
    DRAW_SPRITE(SPRITE_BLOCK_2_0015, 480, 160);
    DRAW_COVER_UP(480, 160, COLOR_BLACK);
    DRAW_COVER_UP(480, 170, COLOR_BLACK);
    DRAW_COVER_UP(490, 170, COLOR_BLACK);
    DRAW_COVER_UP(490, 160, COLOR_BLACK);
    DRAW_SPRITE(SPRITE_BLOCK_2_0015, 496, 160);
    DRAW_COVER_UP(496, 160, COLOR_BLACK);
    DRAW_COVER_UP(496, 170, COLOR_BLACK);
    DRAW_COVER_UP(506, 170, COLOR_BLACK);
    DRAW_COVER_UP(506, 160, COLOR_BLACK);
    DRAW_SPRITE(SPRITE_BLOCK_2_0007, 512, 160);
    DRAW_COVER_UP(512, 160, COLOR_BLACK);
    DRAW_COVER_UP(512, 170, COLOR_BLACK);
    DRAW_SPRITE(SPRITE_BLOCK_2_0009, 32, 176);
    DRAW_COVER_UP(42, 176, COLOR_BLACK);
    DRAW_SPRITE(SPRITE_BLOCK_2_0011, 48, 176);
    DRAW_COVER_UP(48, 176, COLOR_BLACK);
    DRAW_COVER_UP(58, 176, COLOR_BLACK);
    DRAW_SPRITE(SPRITE_BLOCK_2_0011, 64, 176);
    DRAW_COVER_UP(64, 176, COLOR_BLACK);
    DRAW_COVER_UP(74, 176, COLOR_BLACK);
    DRAW_SPRITE(SPRITE_BLOCK_2_0011, 80, 176);
    DRAW_COVER_UP(80, 176, COLOR_BLACK);
    DRAW_COVER_UP(90, 176, COLOR_BLACK);
    DRAW_SPRITE(SPRITE_BLOCK_2_0011, 96, 176);
    DRAW_COVER_UP(96, 176, COLOR_BLACK);
    DRAW_COVER_UP(106, 176, COLOR_BLACK);
    DRAW_SPRITE(SPRITE_BLOCK_2_0011, 112, 176);
    DRAW_COVER_UP(112, 176, COLOR_BLACK);
    DRAW_COVER_UP(122, 176, COLOR_BLACK);
    DRAW_SPRITE(SPRITE_BLOCK_2_0011, 128, 176);
    DRAW_COVER_UP(128, 176, COLOR_BLACK);
    DRAW_COVER_UP(138, 176, COLOR_BLACK);
    DRAW_SPRITE(SPRITE_BLOCK_2_0011, 144, 176);
    DRAW_COVER_UP(144, 176, COLOR_BLACK);
    DRAW_COVER_UP(154, 176, COLOR_BLACK);
    DRAW_SPRITE(SPRITE_BLOCK_2_0011, 160, 176);
    DRAW_COVER_UP(160, 176, COLOR_BLACK);
    DRAW_COVER_UP(170, 176, COLOR_BLACK);
    DRAW_SPRITE(SPRITE_BLOCK_2_0011, 176, 176);
    DRAW_COVER_UP(176, 176, COLOR_BLACK);
    DRAW_COVER_UP(186, 176, COLOR_BLACK);
    DRAW_SPRITE(SPRITE_BLOCK_2_0011, 192, 176);
    DRAW_COVER_UP(192, 176, COLOR_BLACK);
    DRAW_COVER_UP(202, 176, COLOR_BLACK);
    DRAW_SPRITE(SPRITE_BLOCK_2_0011, 208, 176);
    DRAW_COVER_UP(208, 176, COLOR_BLACK);
    DRAW_COVER_UP(218, 176, COLOR_BLACK);
    DRAW_SPRITE(SPRITE_BLOCK_2_0011, 224, 176);
    DRAW_COVER_UP(224, 176, COLOR_BLACK);
    DRAW_COVER_UP(234, 176, COLOR_BLACK);
    DRAW_SPRITE(SPRITE_BLOCK_2_0011, 240, 176);
    DRAW_COVER_UP(240, 176, COLOR_BLACK);
    DRAW_COVER_UP(250, 176, COLOR_BLACK);
    DRAW_SPRITE(SPRITE_BLOCK_2_0011, 256, 176);
    DRAW_COVER_UP(256, 176, COLOR_BLACK);
    DRAW_COVER_UP(266, 176, COLOR_BLACK);
    DRAW_SPRITE(SPRITE_BLOCK_2_0011, 272, 176);
    DRAW_COVER_UP(272, 176, COLOR_BLACK);
    DRAW_COVER_UP(282, 176, COLOR_BLACK);
    DRAW_SPRITE(SPRITE_BLOCK_2_0011, 288, 176);
    DRAW_COVER_UP(288, 176, COLOR_BLACK);
    DRAW_COVER_UP(298, 176, COLOR_BLACK);
    DRAW_SPRITE(SPRITE_BLOCK_2_0011, 304, 176);
    DRAW_COVER_UP(304, 176, COLOR_BLACK);
    DRAW_COVER_UP(314, 176, COLOR_BLACK);
    DRAW_SPRITE(SPRITE_BLOCK_2_0011, 320, 176);
    DRAW_COVER_UP(320, 176, COLOR_BLACK);
    DRAW_COVER_UP(330, 176, COLOR_BLACK);
    DRAW_SPRITE(SPRITE_BLOCK_2_0011, 336, 176);
    DRAW_COVER_UP(336, 176, COLOR_BLACK);
    DRAW_COVER_UP(346, 176, COLOR_BLACK);
    DRAW_SPRITE(SPRITE_BLOCK_2_0011, 352, 176);
    DRAW_COVER_UP(352, 176, COLOR_BLACK);
    DRAW_COVER_UP(362, 176, COLOR_BLACK);
    DRAW_SPRITE(SPRITE_BLOCK_2_0011, 368, 176);
    DRAW_COVER_UP(368, 176, COLOR_BLACK);
    DRAW_COVER_UP(378, 176, COLOR_BLACK);
    DRAW_SPRITE(SPRITE_BLOCK_2_0011, 384, 176);
    DRAW_COVER_UP(384, 176, COLOR_BLACK);
    DRAW_COVER_UP(394, 176, COLOR_BLACK);
    DRAW_SPRITE(SPRITE_BLOCK_2_0011, 400, 176);
    DRAW_COVER_UP(400, 176, COLOR_BLACK);
    DRAW_COVER_UP(410, 176, COLOR_BLACK);
    DRAW_SPRITE(SPRITE_BLOCK_2_0011, 416, 176);
    DRAW_COVER_UP(416, 176, COLOR_BLACK);
    DRAW_COVER_UP(426, 176, COLOR_BLACK);
    DRAW_SPRITE(SPRITE_BLOCK_2_0011, 432, 176);
    DRAW_COVER_UP(432, 176, COLOR_BLACK);
    DRAW_COVER_UP(442, 176, COLOR_BLACK);
    DRAW_SPRITE(SPRITE_BLOCK_2_0011, 448, 176);
    DRAW_COVER_UP(448, 176, COLOR_BLACK);
    DRAW_COVER_UP(458, 176, COLOR_BLACK);
    DRAW_SPRITE(SPRITE_BLOCK_2_0011, 464, 176);
    DRAW_COVER_UP(464, 176, COLOR_BLACK);
    DRAW_COVER_UP(474, 176, COLOR_BLACK);
    DRAW_SPRITE(SPRITE_BLOCK_2_0011, 480, 176);
    DRAW_COVER_UP(480, 176, COLOR_BLACK);
    DRAW_COVER_UP(490, 176, COLOR_BLACK);
    DRAW_SPRITE(SPRITE_BLOCK_2_0011, 496, 176);
    DRAW_COVER_UP(496, 176, COLOR_BLACK);
    DRAW_COVER_UP(506, 176, COLOR_BLACK);
    DRAW_SPRITE(SPRITE_BLOCK_2_0003, 512, 176);
    DRAW_COVER_UP(512, 176, COLOR_BLACK);
    DRAW_SPRITE(SPRITE_BLOCK_3_0012, 96, 128);
    DRAW_COVER_UP(106, 138, COLOR_BLACK);
    DRAW_SPRITE(SPRITE_BLOCK_3_0014, 112, 128);
    DRAW_COVER_UP(112, 138, COLOR_BLACK);
    DRAW_COVER_UP(122, 138, COLOR_BLACK);
    DRAW_SPRITE(SPRITE_BLOCK_3_0014, 128, 128);
    DRAW_COVER_UP(128, 138, COLOR_BLACK);
    DRAW_COVER_UP(138, 138, COLOR_BLACK);
    DRAW_SPRITE(SPRITE_BLOCK_3_0014, 144, 128);
    DRAW_COVER_UP(144, 138, COLOR_BLACK);
    DRAW_COVER_UP(154, 138, COLOR_BLACK);
    DRAW_SPRITE(SPRITE_BLOCK_3_0014, 160, 128);
    DRAW_COVER_UP(160, 138, COLOR_BLACK);
    DRAW_COVER_UP(170, 138, COLOR_BLACK);
    DRAW_SPRITE(SPRITE_BLOCK_3_0006, 176, 128);
    DRAW_COVER_UP(176, 138, COLOR_BLACK);
    DRAW_SPRITE(SPRITE_BLOCK_3_0012, 544, 128);
    DRAW_COVER_UP(554, 138, COLOR_BLACK);
    DRAW_SPRITE(SPRITE_BLOCK_3_0014, 560, 128);
    DRAW_COVER_UP(560, 138, COLOR_BLACK);
    DRAW_COVER_UP(570, 138, COLOR_BLACK);
    DRAW_SPRITE(SPRITE_BLOCK_3_0014, 576, 128);
    DRAW_COVER_UP(576, 138, COLOR_BLACK);
    DRAW_COVER_UP(586, 138, COLOR_BLACK);
    DRAW_SPRITE(SPRITE_BLOCK_3_0006, 592, 128);
    DRAW_COVER_UP(592, 138, COLOR_BLACK);
    DRAW_SPRITE(SPRITE_BLOCK_3_0013, 96, 144);
    DRAW_COVER_UP(106, 154, COLOR_BLACK);
    DRAW_COVER_UP(106, 144, COLOR_BLACK);
    DRAW_SPRITE(SPRITE_BLOCK_3_0015, 112, 144);
    DRAW_COVER_UP(112, 144, COLOR_BLACK);
    DRAW_COVER_UP(112, 154, COLOR_BLACK);
    DRAW_COVER_UP(122, 154, COLOR_BLACK);
    DRAW_COVER_UP(122, 144, COLOR_BLACK);
    DRAW_SPRITE(SPRITE_BLOCK_3_0015, 128, 144);
    DRAW_COVER_UP(128, 144, COLOR_BLACK);
    DRAW_COVER_UP(128, 154, COLOR_BLACK);
    DRAW_COVER_UP(138, 154, COLOR_BLACK);
    DRAW_COVER_UP(138, 144, COLOR_BLACK);
    DRAW_SPRITE(SPRITE_BLOCK_3_0015, 144, 144);
    DRAW_COVER_UP(144, 144, COLOR_BLACK);
    DRAW_COVER_UP(144, 154, COLOR_BLACK);
    DRAW_COVER_UP(154, 154, COLOR_BLACK);
    DRAW_COVER_UP(154, 144, COLOR_BLACK);
    DRAW_SPRITE(SPRITE_BLOCK_3_0015, 160, 144);
    DRAW_COVER_UP(160, 144, COLOR_BLACK);
    DRAW_COVER_UP(160, 154, COLOR_BLACK);
    DRAW_COVER_UP(170, 154, COLOR_BLACK);
    DRAW_COVER_UP(170, 144, COLOR_BLACK);
    DRAW_SPRITE(SPRITE_BLOCK_3_0007, 176, 144);
    DRAW_COVER_UP(176, 144, COLOR_BLACK);
    DRAW_COVER_UP(176, 154, COLOR_BLACK);
    DRAW_SPRITE(SPRITE_BLOCK_3_0013, 544, 144);
    DRAW_COVER_UP(554, 154, COLOR_BLACK);
    DRAW_COVER_UP(554, 144, COLOR_BLACK);
    DRAW_SPRITE(SPRITE_BLOCK_3_0015, 560, 144);
    DRAW_COVER_UP(560, 144, COLOR_BLACK);
    DRAW_COVER_UP(560, 154, COLOR_BLACK);
    DRAW_COVER_UP(570, 154, COLOR_BLACK);
    DRAW_COVER_UP(570, 144, COLOR_BLACK);
    DRAW_SPRITE(SPRITE_BLOCK_3_0015, 576, 144);
    DRAW_COVER_UP(576, 144, COLOR_BLACK);
    DRAW_COVER_UP(576, 154, COLOR_BLACK);
    DRAW_COVER_UP(586, 154, COLOR_BLACK);
    DRAW_COVER_UP(586, 144, COLOR_BLACK);
    DRAW_SPRITE(SPRITE_BLOCK_3_0007, 592, 144);
    DRAW_COVER_UP(592, 144, COLOR_BLACK);
    DRAW_COVER_UP(592, 154, COLOR_BLACK);
    DRAW_SPRITE(SPRITE_BLOCK_3_0013, 96, 160);
    DRAW_COVER_UP(106, 170, COLOR_BLACK);
    DRAW_COVER_UP(106, 160, COLOR_BLACK);
    DRAW_SPRITE(SPRITE_BLOCK_3_0015, 112, 160);
    DRAW_COVER_UP(112, 160, COLOR_BLACK);
    DRAW_COVER_UP(112, 170, COLOR_BLACK);
    DRAW_COVER_UP(122, 170, COLOR_BLACK);
    DRAW_COVER_UP(122, 160, COLOR_BLACK);
    DRAW_SPRITE(SPRITE_BLOCK_3_0015, 128, 160);
    DRAW_COVER_UP(128, 160, COLOR_BLACK);
    DRAW_COVER_UP(128, 170, COLOR_BLACK);
    DRAW_COVER_UP(138, 170, COLOR_BLACK);
    DRAW_COVER_UP(138, 160, COLOR_BLACK);
    DRAW_SPRITE(SPRITE_BLOCK_3_0015, 144, 160);
    DRAW_COVER_UP(144, 160, COLOR_BLACK);
    DRAW_COVER_UP(144, 170, COLOR_BLACK);
    DRAW_COVER_UP(154, 170, COLOR_BLACK);
    DRAW_COVER_UP(154, 160, COLOR_BLACK);
    DRAW_SPRITE(SPRITE_BLOCK_3_0015, 160, 160);
    DRAW_COVER_UP(160, 160, COLOR_BLACK);
    DRAW_COVER_UP(160, 170, COLOR_BLACK);
    DRAW_COVER_UP(170, 170, COLOR_BLACK);
    DRAW_COVER_UP(170, 160, COLOR_BLACK);
    DRAW_SPRITE(SPRITE_BLOCK_3_0007, 176, 160);
    DRAW_COVER_UP(176, 160, COLOR_BLACK);
    DRAW_COVER_UP(176, 170, COLOR_BLACK);
    DRAW_SPRITE(SPRITE_BLOCK_3_0013, 544, 160);
    DRAW_COVER_UP(554, 170, COLOR_BLACK);
    DRAW_COVER_UP(554, 160, COLOR_BLACK);
    DRAW_SPRITE(SPRITE_BLOCK_3_0015, 560, 160);
    DRAW_COVER_UP(560, 160, COLOR_BLACK);
    DRAW_COVER_UP(560, 170, COLOR_BLACK);
    DRAW_COVER_UP(570, 170, COLOR_BLACK);
    DRAW_COVER_UP(570, 160, COLOR_BLACK);
    DRAW_SPRITE(SPRITE_BLOCK_3_0015, 576, 160);
    DRAW_COVER_UP(576, 160, COLOR_BLACK);
    DRAW_COVER_UP(576, 170, COLOR_BLACK);
    DRAW_COVER_UP(586, 170, COLOR_BLACK);
    DRAW_COVER_UP(586, 160, COLOR_BLACK);
    DRAW_SPRITE(SPRITE_BLOCK_3_0007, 592, 160);
    DRAW_COVER_UP(592, 160, COLOR_BLACK);
    DRAW_COVER_UP(592, 170, COLOR_BLACK);
    DRAW_SPRITE(SPRITE_BLOCK_3_0009, 96, 176);
    DRAW_COVER_UP(106, 176, COLOR_BLACK);
    DRAW_SPRITE(SPRITE_BLOCK_3_0011, 112, 176);
    DRAW_COVER_UP(112, 176, COLOR_BLACK);
    DRAW_COVER_UP(122, 176, COLOR_BLACK);
    DRAW_SPRITE(SPRITE_BLOCK_3_0011, 128, 176);
    DRAW_COVER_UP(128, 176, COLOR_BLACK);
    DRAW_COVER_UP(138, 176, COLOR_BLACK);
    DRAW_SPRITE(SPRITE_BLOCK_3_0011, 144, 176);
    DRAW_COVER_UP(144, 176, COLOR_BLACK);
    DRAW_COVER_UP(154, 176, COLOR_BLACK);
    DRAW_SPRITE(SPRITE_BLOCK_3_0011, 160, 176);
    DRAW_COVER_UP(160, 176, COLOR_BLACK);
    DRAW_COVER_UP(170, 176, COLOR_BLACK);
    DRAW_SPRITE(SPRITE_BLOCK_3_0003, 176, 176);
    DRAW_COVER_UP(176, 176, COLOR_BLACK);
    DRAW_SPRITE(SPRITE_BLOCK_3_0009, 544, 176);
    DRAW_COVER_UP(554, 176, COLOR_BLACK);
    DRAW_SPRITE(SPRITE_BLOCK_3_0011, 560, 176);
    DRAW_COVER_UP(560, 176, COLOR_BLACK);
    DRAW_COVER_UP(570, 176, COLOR_BLACK);
    DRAW_SPRITE(SPRITE_BLOCK_3_0011, 576, 176);
    DRAW_COVER_UP(576, 176, COLOR_BLACK);
    DRAW_COVER_UP(586, 176, COLOR_BLACK);
    DRAW_SPRITE(SPRITE_BLOCK_3_0003, 592, 176);
    DRAW_COVER_UP(592, 176, COLOR_BLACK);
    DRAW_SPRITE(SPRITE_ONE_WAY_TOP, 176, 48);
    DRAW_SPRITE(SPRITE_ONE_WAY_BASE, 192, 48);
    DRAW_SPRITE(SPRITE_ONE_WAY_TOP, 240, 48);
    DRAW_SPRITE(SPRITE_ONE_WAY_TOP, 256, 48);
    DRAW_SPRITE(SPRITE_ONE_WAY_TOP, 272, 48);
    DRAW_SPRITE(SPRITE_ONE_WAY_TOP, 288, 48);
    DRAW_SPRITE(SPRITE_ONE_WAY_BASE, 304, 48);
    DRAW_SPRITE(SPRITE_ONE_WAY_TOP, 352, 48);
    DRAW_SPRITE(SPRITE_ONE_WAY_PILLAR, 208, 80);
    DRAW_SPRITE(SPRITE_ONE_WAY_PILLAR, 320, 80);
    DRAW_SPRITE(SPRITE_BLOCK_6_0012, 192, 96);
    DRAW_SPRITE(SPRITE_BLOCK_6_0014, 208, 96);
    DRAW_SPRITE(SPRITE_BLOCK_6_0006, 224, 96);
    DRAW_SPRITE(SPRITE_ONE_WAY_PILLAR, 320, 96);
    DRAW_SPRITE(SPRITE_BLOCK_6_0012, 496, 96);
    DRAW_SPRITE(SPRITE_BLOCK_6_0014, 512, 96);
    DRAW_SPRITE(SPRITE_BLOCK_6_0006, 528, 96);
    DRAW_SPRITE(SPRITE_BLOCK_6_0013, 192, 112);
    DRAW_SPRITE(SPRITE_BLOCK_6_0015, 208, 112);
    DRAW_SPRITE(SPRITE_BLOCK_6_0007, 224, 112);
    DRAW_SPRITE(SPRITE_ONE_WAY_PILLAR, 320, 112);
    DRAW_SPRITE(SPRITE_BLOCK_6_0013, 496, 112);
    DRAW_SPRITE(SPRITE_BLOCK_6_0015, 512, 112);
    DRAW_SPRITE(SPRITE_BLOCK_6_0007, 528, 112);
    DRAW_SPRITE(SPRITE_BLOCK_6_0013, 192, 128);
    DRAW_SPRITE(SPRITE_BLOCK_6_0015, 208, 128);
    DRAW_SPRITE(SPRITE_BLOCK_6_0007, 224, 128);
    DRAW_SPRITE(SPRITE_BLOCK_6_0012, 304, 128);
    DRAW_SPRITE(SPRITE_BLOCK_6_0014, 320, 128);
    DRAW_SPRITE(SPRITE_BLOCK_6_0006, 336, 128);
    DRAW_SPRITE(SPRITE_BLOCK_6_0012, 400, 128);
    DRAW_SPRITE(SPRITE_BLOCK_6_0014, 416, 128);
    DRAW_SPRITE(SPRITE_BLOCK_6_0006, 432, 128);
    DRAW_SPRITE(SPRITE_BLOCK_6_0009, 496, 128);
    DRAW_SPRITE(SPRITE_BLOCK_6_0011, 512, 128);
    DRAW_SPRITE(SPRITE_BLOCK_6_0003, 528, 128);
    DRAW_SPRITE(SPRITE_BLOCK_6_0013, 192, 144);
    DRAW_SPRITE(SPRITE_BLOCK_6_0015, 208, 144);
    DRAW_SPRITE(SPRITE_BLOCK_6_0007, 224, 144);
    DRAW_SPRITE(SPRITE_BLOCK_6_0013, 304, 144);
    DRAW_SPRITE(SPRITE_BLOCK_6_0015, 320, 144);
    DRAW_SPRITE(SPRITE_BLOCK_6_0007, 336, 144);
    DRAW_SPRITE(SPRITE_BLOCK_6_0013, 400, 144);
    DRAW_SPRITE(SPRITE_BLOCK_6_0015, 416, 144);
    DRAW_SPRITE(SPRITE_BLOCK_6_0007, 432, 144);
    DRAW_SPRITE(SPRITE_BLOCK_4_0008, 496, 144);
    DRAW_SPRITE(SPRITE_BLOCK_4_0010, 512, 144);
    DRAW_SPRITE(SPRITE_BLOCK_4_0002, 528, 144);
    DRAW_SPRITE(SPRITE_BLOCK_0_0012, 0, 160);
    DRAW_SPRITE(SPRITE_BLOCK_0_0014, 16, 160);
    DRAW_SPRITE(SPRITE_BLOCK_0_0014, 32, 160);
    DRAW_SPRITE(SPRITE_BLOCK_0_0014, 48, 160);
    DRAW_SPRITE(SPRITE_BLOCK_0_0014, 64, 160);
    DRAW_SPRITE(SPRITE_BLOCK_0_0014, 80, 160);
    DRAW_SPRITE(SPRITE_BLOCK_0_0014, 96, 160);
    DRAW_SPRITE(SPRITE_BLOCK_0_0014, 112, 160);
    DRAW_SPRITE(SPRITE_BLOCK_0_0014, 128, 160);
    DRAW_SPRITE(SPRITE_BLOCK_0_0014, 144, 160);
    DRAW_SPRITE(SPRITE_BLOCK_0_0014, 160, 160);
    DRAW_SPRITE(SPRITE_BLOCK_0_0006, 176, 160);
    DRAW_SPRITE(SPRITE_BLOCK_6_0013, 192, 160);
    DRAW_SPRITE(SPRITE_BLOCK_6_0015, 208, 160);
    DRAW_SPRITE(SPRITE_BLOCK_6_0007, 224, 160);
    DRAW_SPRITE(SPRITE_BLOCK_6_0009, 304, 160);
    DRAW_SPRITE(SPRITE_BLOCK_6_0011, 320, 160);
    DRAW_SPRITE(SPRITE_BLOCK_6_0003, 336, 160);
    DRAW_SPRITE(SPRITE_BLOCK_6_0013, 400, 160);
    DRAW_SPRITE(SPRITE_BLOCK_6_0015, 416, 160);
    DRAW_SPRITE(SPRITE_BLOCK_6_0007, 432, 160);
    DRAW_SPRITE(SPRITE_BLOCK_6_0012, 496, 160);
    DRAW_SPRITE(SPRITE_BLOCK_6_0014, 512, 160);
    DRAW_SPRITE(SPRITE_BLOCK_6_0006, 528, 160);
    DRAW_SPRITE(SPRITE_BLOCK_0_0012, 544, 160);
    DRAW_SPRITE(SPRITE_BLOCK_0_0014, 560, 160);
    DRAW_SPRITE(SPRITE_BLOCK_0_0014, 576, 160);
    DRAW_SPRITE(SPRITE_BLOCK_0_0014, 592, 160);
    DRAW_SPRITE(SPRITE_BLOCK_0_0014, 608, 160);
    DRAW_SPRITE(SPRITE_BLOCK_0_0006, 624, 160);
    DRAW_SPRITE(SPRITE_BLOCK_0_0009, 0, 176);
    DRAW_SPRITE(SPRITE_BLOCK_0_0011, 16, 176);
    DRAW_SPRITE(SPRITE_BLOCK_0_0011, 32, 176);
    DRAW_SPRITE(SPRITE_BLOCK_0_0011, 48, 176);
    DRAW_SPRITE(SPRITE_BLOCK_0_0011, 64, 176);
    DRAW_SPRITE(SPRITE_BLOCK_0_0011, 80, 176);
    DRAW_SPRITE(SPRITE_BLOCK_0_0011, 96, 176);
    DRAW_SPRITE(SPRITE_BLOCK_0_0011, 112, 176);
    DRAW_SPRITE(SPRITE_BLOCK_0_0011, 128, 176);
    DRAW_SPRITE(SPRITE_BLOCK_0_0011, 144, 176);
    DRAW_SPRITE(SPRITE_BLOCK_0_0011, 160, 176);
    DRAW_SPRITE(SPRITE_BLOCK_0_0003, 176, 176);
    DRAW_SPRITE(SPRITE_BLOCK_6_0009, 192, 176);
    DRAW_SPRITE(SPRITE_BLOCK_6_0011, 208, 176);
    DRAW_SPRITE(SPRITE_BLOCK_6_0003, 224, 176);
    DRAW_SPRITE(SPRITE_BLOCK_4_0008, 304, 176);
    DRAW_SPRITE(SPRITE_BLOCK_4_0010, 320, 176);
    DRAW_SPRITE(SPRITE_BLOCK_4_0002, 336, 176);
    DRAW_SPRITE(SPRITE_BLOCK_6_0009, 400, 176);
    DRAW_SPRITE(SPRITE_BLOCK_6_0011, 416, 176);
    DRAW_SPRITE(SPRITE_BLOCK_6_0003, 432, 176);
    DRAW_SPRITE(SPRITE_BLOCK_6_0009, 496, 176);
    DRAW_SPRITE(SPRITE_BLOCK_6_0011, 512, 176);
    DRAW_SPRITE(SPRITE_BLOCK_6_0003, 528, 176);
    DRAW_SPRITE(SPRITE_BLOCK_0_0009, 544, 176);
    DRAW_SPRITE(SPRITE_BLOCK_0_0011, 560, 176);
    DRAW_SPRITE(SPRITE_BLOCK_0_0011, 576, 176);
    DRAW_SPRITE(SPRITE_BLOCK_0_0011, 592, 176);
    DRAW_SPRITE(SPRITE_BLOCK_0_0011, 608, 176);
    DRAW_SPRITE(SPRITE_BLOCK_0_0003, 624, 176);

    DRAW_SPRITE(SPRITE_BLOCK_0_0014, 0, 160);
    DRAW_SPRITE(SPRITE_BLOCK_0_0015, 0, 176);
    DRAW_SPRITE(SPRITE_BLOCK_0_0014, 624, 160);
    DRAW_SPRITE(SPRITE_BLOCK_0_0015, 624, 176);
}
