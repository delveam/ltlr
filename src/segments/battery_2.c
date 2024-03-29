// This file was auto-generated; any changes you make may be overwritten.

#include "../ecs/entities.h"
#include "../segments_generated.h"
#include "../segments_helper.h"

LevelSegmentBuilder LevelSegmentBuilderCreate_battery_2(Scene* scene, const Vector2 offset)
{
	CREATE_SOLID_BLOCK(0, 160, 128, 96);
	CREATE_SOLID_BLOCK(192, 160, 48, 96);
	CREATE_SOLID_BLOCK(288, 144, 48, 112);
	CREATE_SOLID_BLOCK(384, 112, 48, 144);
	CREATE_SOLID_BLOCK(480, 160, 64, 96);
	CREATE_SOLID_BLOCK(48, -64, 32, 96);
	CREATE_SOLID_BLOCK(80, -64, 16, 128);
	CREATE_SOLID_BLOCK(96, -64, 112, 160);
	CREATE_SOLID_BLOCK(208, -64, 64, 144);
	CREATE_SOLID_BLOCK(272, -64, 16, 128);
	CREATE_SOLID_BLOCK(288, -64, 80, 112);
	CREATE_SOLID_BLOCK(368, -64, 32, 96);
	CREATE_SOLID_BLOCK(32, -64, 16, 80);
	CREATE_BATTERY(400, 64);

	return (LevelSegmentBuilder) {
		.width = 544,
	};
}

void LevelSegmentDraw_battery_2(const Atlas* atlas, const Vector2 offset)
{
	DRAW_SPRITE(SPRITE_BLOCK_2_0012, 112, 0);
	DRAW_COVER_UP(122, 10, COLOR_BLACK);
	DRAW_SPRITE(SPRITE_BLOCK_2_0014, 128, 0);
	DRAW_COVER_UP(128, 10, COLOR_BLACK);
	DRAW_COVER_UP(138, 10, COLOR_BLACK);
	DRAW_SPRITE(SPRITE_BLOCK_2_0014, 144, 0);
	DRAW_COVER_UP(144, 10, COLOR_BLACK);
	DRAW_COVER_UP(154, 10, COLOR_BLACK);
	DRAW_SPRITE(SPRITE_BLOCK_2_0014, 160, 0);
	DRAW_COVER_UP(160, 10, COLOR_BLACK);
	DRAW_COVER_UP(170, 10, COLOR_BLACK);
	DRAW_SPRITE(SPRITE_BLOCK_2_0014, 176, 0);
	DRAW_COVER_UP(176, 10, COLOR_BLACK);
	DRAW_COVER_UP(186, 10, COLOR_BLACK);
	DRAW_SPRITE(SPRITE_BLOCK_2_0014, 192, 0);
	DRAW_COVER_UP(192, 10, COLOR_BLACK);
	DRAW_COVER_UP(202, 10, COLOR_BLACK);
	DRAW_SPRITE(SPRITE_BLOCK_2_0014, 208, 0);
	DRAW_COVER_UP(208, 10, COLOR_BLACK);
	DRAW_COVER_UP(218, 10, COLOR_BLACK);
	DRAW_SPRITE(SPRITE_BLOCK_2_0014, 224, 0);
	DRAW_COVER_UP(224, 10, COLOR_BLACK);
	DRAW_COVER_UP(234, 10, COLOR_BLACK);
	DRAW_SPRITE(SPRITE_BLOCK_2_0014, 240, 0);
	DRAW_COVER_UP(240, 10, COLOR_BLACK);
	DRAW_COVER_UP(250, 10, COLOR_BLACK);
	DRAW_SPRITE(SPRITE_BLOCK_2_0014, 256, 0);
	DRAW_COVER_UP(256, 10, COLOR_BLACK);
	DRAW_COVER_UP(266, 10, COLOR_BLACK);
	DRAW_SPRITE(SPRITE_BLOCK_2_0014, 272, 0);
	DRAW_COVER_UP(272, 10, COLOR_BLACK);
	DRAW_COVER_UP(282, 10, COLOR_BLACK);
	DRAW_SPRITE(SPRITE_BLOCK_2_0014, 288, 0);
	DRAW_COVER_UP(288, 10, COLOR_BLACK);
	DRAW_COVER_UP(298, 10, COLOR_BLACK);
	DRAW_SPRITE(SPRITE_BLOCK_2_0014, 304, 0);
	DRAW_COVER_UP(304, 10, COLOR_BLACK);
	DRAW_COVER_UP(314, 10, COLOR_BLACK);
	DRAW_SPRITE(SPRITE_BLOCK_2_0014, 320, 0);
	DRAW_COVER_UP(320, 10, COLOR_BLACK);
	DRAW_COVER_UP(330, 10, COLOR_BLACK);
	DRAW_SPRITE(SPRITE_BLOCK_2_0014, 336, 0);
	DRAW_COVER_UP(336, 10, COLOR_BLACK);
	DRAW_COVER_UP(346, 10, COLOR_BLACK);
	DRAW_SPRITE(SPRITE_BLOCK_2_0014, 352, 0);
	DRAW_COVER_UP(352, 10, COLOR_BLACK);
	DRAW_COVER_UP(362, 10, COLOR_BLACK);
	DRAW_SPRITE(SPRITE_BLOCK_2_0006, 368, 0);
	DRAW_COVER_UP(368, 10, COLOR_BLACK);
	DRAW_SPRITE(SPRITE_BLOCK_2_0013, 112, 16);
	DRAW_COVER_UP(122, 26, COLOR_BLACK);
	DRAW_COVER_UP(122, 16, COLOR_BLACK);
	DRAW_SPRITE(SPRITE_BLOCK_2_0015, 128, 16);
	DRAW_COVER_UP(128, 16, COLOR_BLACK);
	DRAW_COVER_UP(128, 26, COLOR_BLACK);
	DRAW_COVER_UP(138, 26, COLOR_BLACK);
	DRAW_COVER_UP(138, 16, COLOR_BLACK);
	DRAW_SPRITE(SPRITE_BLOCK_2_0015, 144, 16);
	DRAW_COVER_UP(144, 16, COLOR_BLACK);
	DRAW_COVER_UP(144, 26, COLOR_BLACK);
	DRAW_COVER_UP(154, 26, COLOR_BLACK);
	DRAW_COVER_UP(154, 16, COLOR_BLACK);
	DRAW_SPRITE(SPRITE_BLOCK_2_0015, 160, 16);
	DRAW_COVER_UP(160, 16, COLOR_BLACK);
	DRAW_COVER_UP(160, 26, COLOR_BLACK);
	DRAW_COVER_UP(170, 26, COLOR_BLACK);
	DRAW_COVER_UP(170, 16, COLOR_BLACK);
	DRAW_SPRITE(SPRITE_BLOCK_2_0015, 176, 16);
	DRAW_COVER_UP(176, 16, COLOR_BLACK);
	DRAW_COVER_UP(176, 26, COLOR_BLACK);
	DRAW_COVER_UP(186, 26, COLOR_BLACK);
	DRAW_COVER_UP(186, 16, COLOR_BLACK);
	DRAW_SPRITE(SPRITE_BLOCK_2_0015, 192, 16);
	DRAW_COVER_UP(192, 16, COLOR_BLACK);
	DRAW_COVER_UP(192, 26, COLOR_BLACK);
	DRAW_COVER_UP(202, 26, COLOR_BLACK);
	DRAW_COVER_UP(202, 16, COLOR_BLACK);
	DRAW_SPRITE(SPRITE_BLOCK_2_0015, 208, 16);
	DRAW_COVER_UP(208, 16, COLOR_BLACK);
	DRAW_COVER_UP(208, 26, COLOR_BLACK);
	DRAW_COVER_UP(218, 26, COLOR_BLACK);
	DRAW_COVER_UP(218, 16, COLOR_BLACK);
	DRAW_SPRITE(SPRITE_BLOCK_2_0015, 224, 16);
	DRAW_COVER_UP(224, 16, COLOR_BLACK);
	DRAW_COVER_UP(224, 26, COLOR_BLACK);
	DRAW_COVER_UP(234, 26, COLOR_BLACK);
	DRAW_COVER_UP(234, 16, COLOR_BLACK);
	DRAW_SPRITE(SPRITE_BLOCK_2_0015, 240, 16);
	DRAW_COVER_UP(240, 16, COLOR_BLACK);
	DRAW_COVER_UP(240, 26, COLOR_BLACK);
	DRAW_COVER_UP(250, 26, COLOR_BLACK);
	DRAW_COVER_UP(250, 16, COLOR_BLACK);
	DRAW_SPRITE(SPRITE_BLOCK_2_0015, 256, 16);
	DRAW_COVER_UP(256, 16, COLOR_BLACK);
	DRAW_COVER_UP(256, 26, COLOR_BLACK);
	DRAW_COVER_UP(266, 26, COLOR_BLACK);
	DRAW_COVER_UP(266, 16, COLOR_BLACK);
	DRAW_SPRITE(SPRITE_BLOCK_2_0015, 272, 16);
	DRAW_COVER_UP(272, 16, COLOR_BLACK);
	DRAW_COVER_UP(272, 26, COLOR_BLACK);
	DRAW_COVER_UP(282, 26, COLOR_BLACK);
	DRAW_COVER_UP(282, 16, COLOR_BLACK);
	DRAW_SPRITE(SPRITE_BLOCK_2_0015, 288, 16);
	DRAW_COVER_UP(288, 16, COLOR_BLACK);
	DRAW_COVER_UP(288, 26, COLOR_BLACK);
	DRAW_COVER_UP(298, 26, COLOR_BLACK);
	DRAW_COVER_UP(298, 16, COLOR_BLACK);
	DRAW_SPRITE(SPRITE_BLOCK_2_0015, 304, 16);
	DRAW_COVER_UP(304, 16, COLOR_BLACK);
	DRAW_COVER_UP(304, 26, COLOR_BLACK);
	DRAW_COVER_UP(314, 26, COLOR_BLACK);
	DRAW_COVER_UP(314, 16, COLOR_BLACK);
	DRAW_SPRITE(SPRITE_BLOCK_2_0015, 320, 16);
	DRAW_COVER_UP(320, 16, COLOR_BLACK);
	DRAW_COVER_UP(320, 26, COLOR_BLACK);
	DRAW_COVER_UP(330, 26, COLOR_BLACK);
	DRAW_COVER_UP(330, 16, COLOR_BLACK);
	DRAW_SPRITE(SPRITE_BLOCK_2_0015, 336, 16);
	DRAW_COVER_UP(336, 16, COLOR_BLACK);
	DRAW_COVER_UP(336, 26, COLOR_BLACK);
	DRAW_COVER_UP(346, 26, COLOR_BLACK);
	DRAW_COVER_UP(346, 16, COLOR_BLACK);
	DRAW_SPRITE(SPRITE_BLOCK_2_0015, 352, 16);
	DRAW_COVER_UP(352, 16, COLOR_BLACK);
	DRAW_COVER_UP(352, 26, COLOR_BLACK);
	DRAW_COVER_UP(362, 26, COLOR_BLACK);
	DRAW_COVER_UP(362, 16, COLOR_BLACK);
	DRAW_SPRITE(SPRITE_BLOCK_2_0007, 368, 16);
	DRAW_COVER_UP(368, 16, COLOR_BLACK);
	DRAW_COVER_UP(368, 26, COLOR_BLACK);
	DRAW_SPRITE(SPRITE_BLOCK_2_0013, 112, 32);
	DRAW_COVER_UP(122, 42, COLOR_BLACK);
	DRAW_COVER_UP(122, 32, COLOR_BLACK);
	DRAW_SPRITE(SPRITE_BLOCK_2_0015, 128, 32);
	DRAW_COVER_UP(128, 32, COLOR_BLACK);
	DRAW_COVER_UP(128, 42, COLOR_BLACK);
	DRAW_COVER_UP(138, 42, COLOR_BLACK);
	DRAW_COVER_UP(138, 32, COLOR_BLACK);
	DRAW_SPRITE(SPRITE_BLOCK_2_0015, 144, 32);
	DRAW_COVER_UP(144, 32, COLOR_BLACK);
	DRAW_COVER_UP(144, 42, COLOR_BLACK);
	DRAW_COVER_UP(154, 42, COLOR_BLACK);
	DRAW_COVER_UP(154, 32, COLOR_BLACK);
	DRAW_SPRITE(SPRITE_BLOCK_2_0015, 160, 32);
	DRAW_COVER_UP(160, 32, COLOR_BLACK);
	DRAW_COVER_UP(160, 42, COLOR_BLACK);
	DRAW_COVER_UP(170, 42, COLOR_BLACK);
	DRAW_COVER_UP(170, 32, COLOR_BLACK);
	DRAW_SPRITE(SPRITE_BLOCK_2_0015, 176, 32);
	DRAW_COVER_UP(176, 32, COLOR_BLACK);
	DRAW_COVER_UP(176, 42, COLOR_BLACK);
	DRAW_COVER_UP(186, 42, COLOR_BLACK);
	DRAW_COVER_UP(186, 32, COLOR_BLACK);
	DRAW_SPRITE(SPRITE_BLOCK_2_0015, 192, 32);
	DRAW_COVER_UP(192, 32, COLOR_BLACK);
	DRAW_COVER_UP(192, 42, COLOR_BLACK);
	DRAW_COVER_UP(202, 42, COLOR_BLACK);
	DRAW_COVER_UP(202, 32, COLOR_BLACK);
	DRAW_SPRITE(SPRITE_BLOCK_2_0015, 208, 32);
	DRAW_COVER_UP(208, 32, COLOR_BLACK);
	DRAW_COVER_UP(208, 42, COLOR_BLACK);
	DRAW_COVER_UP(218, 42, COLOR_BLACK);
	DRAW_COVER_UP(218, 32, COLOR_BLACK);
	DRAW_SPRITE(SPRITE_BLOCK_2_0015, 224, 32);
	DRAW_COVER_UP(224, 32, COLOR_BLACK);
	DRAW_COVER_UP(224, 42, COLOR_BLACK);
	DRAW_COVER_UP(234, 42, COLOR_BLACK);
	DRAW_COVER_UP(234, 32, COLOR_BLACK);
	DRAW_SPRITE(SPRITE_BLOCK_2_0015, 240, 32);
	DRAW_COVER_UP(240, 32, COLOR_BLACK);
	DRAW_COVER_UP(240, 42, COLOR_BLACK);
	DRAW_COVER_UP(250, 42, COLOR_BLACK);
	DRAW_COVER_UP(250, 32, COLOR_BLACK);
	DRAW_SPRITE(SPRITE_BLOCK_2_0015, 256, 32);
	DRAW_COVER_UP(256, 32, COLOR_BLACK);
	DRAW_COVER_UP(256, 42, COLOR_BLACK);
	DRAW_COVER_UP(266, 42, COLOR_BLACK);
	DRAW_COVER_UP(266, 32, COLOR_BLACK);
	DRAW_SPRITE(SPRITE_BLOCK_2_0015, 272, 32);
	DRAW_COVER_UP(272, 32, COLOR_BLACK);
	DRAW_COVER_UP(272, 42, COLOR_BLACK);
	DRAW_COVER_UP(282, 42, COLOR_BLACK);
	DRAW_COVER_UP(282, 32, COLOR_BLACK);
	DRAW_SPRITE(SPRITE_BLOCK_2_0015, 288, 32);
	DRAW_COVER_UP(288, 32, COLOR_BLACK);
	DRAW_COVER_UP(288, 42, COLOR_BLACK);
	DRAW_COVER_UP(298, 42, COLOR_BLACK);
	DRAW_COVER_UP(298, 32, COLOR_BLACK);
	DRAW_SPRITE(SPRITE_BLOCK_2_0015, 304, 32);
	DRAW_COVER_UP(304, 32, COLOR_BLACK);
	DRAW_COVER_UP(304, 42, COLOR_BLACK);
	DRAW_COVER_UP(314, 42, COLOR_BLACK);
	DRAW_COVER_UP(314, 32, COLOR_BLACK);
	DRAW_SPRITE(SPRITE_BLOCK_2_0015, 320, 32);
	DRAW_COVER_UP(320, 32, COLOR_BLACK);
	DRAW_COVER_UP(320, 42, COLOR_BLACK);
	DRAW_COVER_UP(330, 42, COLOR_BLACK);
	DRAW_COVER_UP(330, 32, COLOR_BLACK);
	DRAW_SPRITE(SPRITE_BLOCK_2_0015, 336, 32);
	DRAW_COVER_UP(336, 32, COLOR_BLACK);
	DRAW_COVER_UP(336, 42, COLOR_BLACK);
	DRAW_COVER_UP(346, 42, COLOR_BLACK);
	DRAW_COVER_UP(346, 32, COLOR_BLACK);
	DRAW_SPRITE(SPRITE_BLOCK_2_0015, 352, 32);
	DRAW_COVER_UP(352, 32, COLOR_BLACK);
	DRAW_COVER_UP(352, 42, COLOR_BLACK);
	DRAW_COVER_UP(362, 42, COLOR_BLACK);
	DRAW_COVER_UP(362, 32, COLOR_BLACK);
	DRAW_SPRITE(SPRITE_BLOCK_2_0007, 368, 32);
	DRAW_COVER_UP(368, 32, COLOR_BLACK);
	DRAW_COVER_UP(368, 42, COLOR_BLACK);
	DRAW_SPRITE(SPRITE_BLOCK_2_0013, 112, 48);
	DRAW_COVER_UP(122, 58, COLOR_BLACK);
	DRAW_COVER_UP(122, 48, COLOR_BLACK);
	DRAW_SPRITE(SPRITE_BLOCK_2_0015, 128, 48);
	DRAW_COVER_UP(128, 48, COLOR_BLACK);
	DRAW_COVER_UP(128, 58, COLOR_BLACK);
	DRAW_COVER_UP(138, 58, COLOR_BLACK);
	DRAW_COVER_UP(138, 48, COLOR_BLACK);
	DRAW_SPRITE(SPRITE_BLOCK_2_0015, 144, 48);
	DRAW_COVER_UP(144, 48, COLOR_BLACK);
	DRAW_COVER_UP(144, 58, COLOR_BLACK);
	DRAW_COVER_UP(154, 58, COLOR_BLACK);
	DRAW_COVER_UP(154, 48, COLOR_BLACK);
	DRAW_SPRITE(SPRITE_BLOCK_2_0015, 160, 48);
	DRAW_COVER_UP(160, 48, COLOR_BLACK);
	DRAW_COVER_UP(160, 58, COLOR_BLACK);
	DRAW_COVER_UP(170, 58, COLOR_BLACK);
	DRAW_COVER_UP(170, 48, COLOR_BLACK);
	DRAW_SPRITE(SPRITE_BLOCK_2_0015, 176, 48);
	DRAW_COVER_UP(176, 48, COLOR_BLACK);
	DRAW_COVER_UP(176, 58, COLOR_BLACK);
	DRAW_COVER_UP(186, 58, COLOR_BLACK);
	DRAW_COVER_UP(186, 48, COLOR_BLACK);
	DRAW_SPRITE(SPRITE_BLOCK_2_0015, 192, 48);
	DRAW_COVER_UP(192, 48, COLOR_BLACK);
	DRAW_COVER_UP(192, 58, COLOR_BLACK);
	DRAW_COVER_UP(202, 58, COLOR_BLACK);
	DRAW_COVER_UP(202, 48, COLOR_BLACK);
	DRAW_SPRITE(SPRITE_BLOCK_2_0015, 208, 48);
	DRAW_COVER_UP(208, 48, COLOR_BLACK);
	DRAW_COVER_UP(208, 58, COLOR_BLACK);
	DRAW_COVER_UP(218, 58, COLOR_BLACK);
	DRAW_COVER_UP(218, 48, COLOR_BLACK);
	DRAW_SPRITE(SPRITE_BLOCK_2_0015, 224, 48);
	DRAW_COVER_UP(224, 48, COLOR_BLACK);
	DRAW_COVER_UP(224, 58, COLOR_BLACK);
	DRAW_COVER_UP(234, 48, COLOR_BLACK);
	DRAW_SPRITE(SPRITE_BLOCK_2_0011, 240, 48);
	DRAW_COVER_UP(240, 48, COLOR_BLACK);
	DRAW_COVER_UP(250, 48, COLOR_BLACK);
	DRAW_SPRITE(SPRITE_BLOCK_2_0011, 256, 48);
	DRAW_COVER_UP(256, 48, COLOR_BLACK);
	DRAW_COVER_UP(266, 48, COLOR_BLACK);
	DRAW_SPRITE(SPRITE_BLOCK_2_0011, 272, 48);
	DRAW_COVER_UP(272, 48, COLOR_BLACK);
	DRAW_COVER_UP(282, 48, COLOR_BLACK);
	DRAW_SPRITE(SPRITE_BLOCK_2_0011, 288, 48);
	DRAW_COVER_UP(288, 48, COLOR_BLACK);
	DRAW_COVER_UP(298, 48, COLOR_BLACK);
	DRAW_SPRITE(SPRITE_BLOCK_2_0015, 304, 48);
	DRAW_COVER_UP(304, 48, COLOR_BLACK);
	DRAW_COVER_UP(314, 58, COLOR_BLACK);
	DRAW_COVER_UP(314, 48, COLOR_BLACK);
	DRAW_SPRITE(SPRITE_BLOCK_2_0015, 320, 48);
	DRAW_COVER_UP(320, 48, COLOR_BLACK);
	DRAW_COVER_UP(320, 58, COLOR_BLACK);
	DRAW_COVER_UP(330, 58, COLOR_BLACK);
	DRAW_COVER_UP(330, 48, COLOR_BLACK);
	DRAW_SPRITE(SPRITE_BLOCK_2_0015, 336, 48);
	DRAW_COVER_UP(336, 48, COLOR_BLACK);
	DRAW_COVER_UP(336, 58, COLOR_BLACK);
	DRAW_COVER_UP(346, 58, COLOR_BLACK);
	DRAW_COVER_UP(346, 48, COLOR_BLACK);
	DRAW_SPRITE(SPRITE_BLOCK_2_0015, 352, 48);
	DRAW_COVER_UP(352, 48, COLOR_BLACK);
	DRAW_COVER_UP(352, 58, COLOR_BLACK);
	DRAW_COVER_UP(362, 48, COLOR_BLACK);
	DRAW_SPRITE(SPRITE_BLOCK_2_0003, 368, 48);
	DRAW_COVER_UP(368, 48, COLOR_BLACK);
	DRAW_SPRITE(SPRITE_BLOCK_2_0013, 112, 64);
	DRAW_COVER_UP(122, 74, COLOR_BLACK);
	DRAW_COVER_UP(122, 64, COLOR_BLACK);
	DRAW_SPRITE(SPRITE_BLOCK_2_0015, 128, 64);
	DRAW_COVER_UP(128, 64, COLOR_BLACK);
	DRAW_COVER_UP(128, 74, COLOR_BLACK);
	DRAW_COVER_UP(138, 74, COLOR_BLACK);
	DRAW_COVER_UP(138, 64, COLOR_BLACK);
	DRAW_SPRITE(SPRITE_BLOCK_2_0015, 144, 64);
	DRAW_COVER_UP(144, 64, COLOR_BLACK);
	DRAW_COVER_UP(144, 74, COLOR_BLACK);
	DRAW_COVER_UP(154, 74, COLOR_BLACK);
	DRAW_COVER_UP(154, 64, COLOR_BLACK);
	DRAW_SPRITE(SPRITE_BLOCK_2_0015, 160, 64);
	DRAW_COVER_UP(160, 64, COLOR_BLACK);
	DRAW_COVER_UP(160, 74, COLOR_BLACK);
	DRAW_COVER_UP(170, 74, COLOR_BLACK);
	DRAW_COVER_UP(170, 64, COLOR_BLACK);
	DRAW_SPRITE(SPRITE_BLOCK_2_0015, 176, 64);
	DRAW_COVER_UP(176, 64, COLOR_BLACK);
	DRAW_COVER_UP(176, 74, COLOR_BLACK);
	DRAW_COVER_UP(186, 74, COLOR_BLACK);
	DRAW_COVER_UP(186, 64, COLOR_BLACK);
	DRAW_SPRITE(SPRITE_BLOCK_2_0015, 192, 64);
	DRAW_COVER_UP(192, 64, COLOR_BLACK);
	DRAW_COVER_UP(192, 74, COLOR_BLACK);
	DRAW_COVER_UP(202, 74, COLOR_BLACK);
	DRAW_COVER_UP(202, 64, COLOR_BLACK);
	DRAW_SPRITE(SPRITE_BLOCK_2_0015, 208, 64);
	DRAW_COVER_UP(208, 64, COLOR_BLACK);
	DRAW_COVER_UP(208, 74, COLOR_BLACK);
	DRAW_COVER_UP(218, 64, COLOR_BLACK);
	DRAW_SPRITE(SPRITE_BLOCK_2_0003, 224, 64);
	DRAW_COVER_UP(224, 64, COLOR_BLACK);
	DRAW_SPRITE(SPRITE_BLOCK_2_0009, 304, 64);
	DRAW_COVER_UP(314, 64, COLOR_BLACK);
	DRAW_SPRITE(SPRITE_BLOCK_2_0015, 320, 64);
	DRAW_COVER_UP(320, 64, COLOR_BLACK);
	DRAW_COVER_UP(330, 74, COLOR_BLACK);
	DRAW_COVER_UP(330, 64, COLOR_BLACK);
	DRAW_SPRITE(SPRITE_BLOCK_2_0015, 336, 64);
	DRAW_COVER_UP(336, 64, COLOR_BLACK);
	DRAW_COVER_UP(336, 74, COLOR_BLACK);
	DRAW_COVER_UP(346, 74, COLOR_BLACK);
	DRAW_COVER_UP(346, 64, COLOR_BLACK);
	DRAW_SPRITE(SPRITE_BLOCK_2_0007, 352, 64);
	DRAW_COVER_UP(352, 64, COLOR_BLACK);
	DRAW_COVER_UP(352, 74, COLOR_BLACK);
	DRAW_SPRITE(SPRITE_BLOCK_2_0013, 112, 80);
	DRAW_COVER_UP(122, 90, COLOR_BLACK);
	DRAW_COVER_UP(122, 80, COLOR_BLACK);
	DRAW_SPRITE(SPRITE_BLOCK_2_0015, 128, 80);
	DRAW_COVER_UP(128, 80, COLOR_BLACK);
	DRAW_COVER_UP(128, 90, COLOR_BLACK);
	DRAW_COVER_UP(138, 90, COLOR_BLACK);
	DRAW_COVER_UP(138, 80, COLOR_BLACK);
	DRAW_SPRITE(SPRITE_BLOCK_2_0015, 144, 80);
	DRAW_COVER_UP(144, 80, COLOR_BLACK);
	DRAW_COVER_UP(144, 90, COLOR_BLACK);
	DRAW_COVER_UP(154, 90, COLOR_BLACK);
	DRAW_COVER_UP(154, 80, COLOR_BLACK);
	DRAW_SPRITE(SPRITE_BLOCK_2_0015, 160, 80);
	DRAW_COVER_UP(160, 80, COLOR_BLACK);
	DRAW_COVER_UP(160, 90, COLOR_BLACK);
	DRAW_COVER_UP(170, 90, COLOR_BLACK);
	DRAW_COVER_UP(170, 80, COLOR_BLACK);
	DRAW_SPRITE(SPRITE_BLOCK_2_0015, 176, 80);
	DRAW_COVER_UP(176, 80, COLOR_BLACK);
	DRAW_COVER_UP(176, 90, COLOR_BLACK);
	DRAW_COVER_UP(186, 90, COLOR_BLACK);
	DRAW_COVER_UP(186, 80, COLOR_BLACK);
	DRAW_SPRITE(SPRITE_BLOCK_2_0015, 192, 80);
	DRAW_COVER_UP(192, 80, COLOR_BLACK);
	DRAW_COVER_UP(192, 90, COLOR_BLACK);
	DRAW_COVER_UP(202, 90, COLOR_BLACK);
	DRAW_COVER_UP(202, 80, COLOR_BLACK);
	DRAW_SPRITE(SPRITE_BLOCK_2_0007, 208, 80);
	DRAW_COVER_UP(208, 80, COLOR_BLACK);
	DRAW_COVER_UP(208, 90, COLOR_BLACK);
	DRAW_SPRITE(SPRITE_BLOCK_2_0013, 320, 80);
	DRAW_COVER_UP(330, 90, COLOR_BLACK);
	DRAW_COVER_UP(330, 80, COLOR_BLACK);
	DRAW_SPRITE(SPRITE_BLOCK_2_0015, 336, 80);
	DRAW_COVER_UP(336, 80, COLOR_BLACK);
	DRAW_COVER_UP(336, 90, COLOR_BLACK);
	DRAW_COVER_UP(346, 90, COLOR_BLACK);
	DRAW_COVER_UP(346, 80, COLOR_BLACK);
	DRAW_SPRITE(SPRITE_BLOCK_2_0007, 352, 80);
	DRAW_COVER_UP(352, 80, COLOR_BLACK);
	DRAW_COVER_UP(352, 90, COLOR_BLACK);
	DRAW_SPRITE(SPRITE_BLOCK_7_0004, 464, 80);
	DRAW_SPRITE(SPRITE_BLOCK_2_0009, 112, 96);
	DRAW_COVER_UP(122, 96, COLOR_BLACK);
	DRAW_SPRITE(SPRITE_BLOCK_2_0015, 128, 96);
	DRAW_COVER_UP(128, 96, COLOR_BLACK);
	DRAW_COVER_UP(138, 106, COLOR_BLACK);
	DRAW_COVER_UP(138, 96, COLOR_BLACK);
	DRAW_SPRITE(SPRITE_BLOCK_2_0015, 144, 96);
	DRAW_COVER_UP(144, 96, COLOR_BLACK);
	DRAW_COVER_UP(144, 106, COLOR_BLACK);
	DRAW_COVER_UP(154, 106, COLOR_BLACK);
	DRAW_COVER_UP(154, 96, COLOR_BLACK);
	DRAW_SPRITE(SPRITE_BLOCK_2_0015, 160, 96);
	DRAW_COVER_UP(160, 96, COLOR_BLACK);
	DRAW_COVER_UP(160, 106, COLOR_BLACK);
	DRAW_COVER_UP(170, 106, COLOR_BLACK);
	DRAW_COVER_UP(170, 96, COLOR_BLACK);
	DRAW_SPRITE(SPRITE_BLOCK_2_0015, 176, 96);
	DRAW_COVER_UP(176, 96, COLOR_BLACK);
	DRAW_COVER_UP(176, 106, COLOR_BLACK);
	DRAW_COVER_UP(186, 106, COLOR_BLACK);
	DRAW_COVER_UP(186, 96, COLOR_BLACK);
	DRAW_SPRITE(SPRITE_BLOCK_2_0015, 192, 96);
	DRAW_COVER_UP(192, 96, COLOR_BLACK);
	DRAW_COVER_UP(192, 106, COLOR_BLACK);
	DRAW_COVER_UP(202, 106, COLOR_BLACK);
	DRAW_COVER_UP(202, 96, COLOR_BLACK);
	DRAW_SPRITE(SPRITE_BLOCK_2_0007, 208, 96);
	DRAW_COVER_UP(208, 96, COLOR_BLACK);
	DRAW_COVER_UP(208, 106, COLOR_BLACK);
	DRAW_SPRITE(SPRITE_BLOCK_2_0013, 320, 96);
	DRAW_COVER_UP(330, 106, COLOR_BLACK);
	DRAW_COVER_UP(330, 96, COLOR_BLACK);
	DRAW_SPRITE(SPRITE_BLOCK_2_0015, 336, 96);
	DRAW_COVER_UP(336, 96, COLOR_BLACK);
	DRAW_COVER_UP(336, 106, COLOR_BLACK);
	DRAW_COVER_UP(346, 106, COLOR_BLACK);
	DRAW_COVER_UP(346, 96, COLOR_BLACK);
	DRAW_SPRITE(SPRITE_BLOCK_2_0007, 352, 96);
	DRAW_COVER_UP(352, 96, COLOR_BLACK);
	DRAW_COVER_UP(352, 106, COLOR_BLACK);
	DRAW_SPRITE(SPRITE_BLOCK_7_0013, 464, 96);
	DRAW_SPRITE(SPRITE_BLOCK_7_0006, 480, 96);
	DRAW_SPRITE(SPRITE_BLOCK_2_0009, 128, 112);
	DRAW_COVER_UP(138, 112, COLOR_BLACK);
	DRAW_SPRITE(SPRITE_BLOCK_2_0015, 144, 112);
	DRAW_COVER_UP(144, 112, COLOR_BLACK);
	DRAW_COVER_UP(154, 122, COLOR_BLACK);
	DRAW_COVER_UP(154, 112, COLOR_BLACK);
	DRAW_SPRITE(SPRITE_BLOCK_2_0015, 160, 112);
	DRAW_COVER_UP(160, 112, COLOR_BLACK);
	DRAW_COVER_UP(160, 122, COLOR_BLACK);
	DRAW_COVER_UP(170, 122, COLOR_BLACK);
	DRAW_COVER_UP(170, 112, COLOR_BLACK);
	DRAW_SPRITE(SPRITE_BLOCK_2_0015, 176, 112);
	DRAW_COVER_UP(176, 112, COLOR_BLACK);
	DRAW_COVER_UP(176, 122, COLOR_BLACK);
	DRAW_COVER_UP(186, 122, COLOR_BLACK);
	DRAW_COVER_UP(186, 112, COLOR_BLACK);
	DRAW_SPRITE(SPRITE_BLOCK_2_0015, 192, 112);
	DRAW_COVER_UP(192, 112, COLOR_BLACK);
	DRAW_COVER_UP(192, 122, COLOR_BLACK);
	DRAW_COVER_UP(202, 122, COLOR_BLACK);
	DRAW_COVER_UP(202, 112, COLOR_BLACK);
	DRAW_SPRITE(SPRITE_BLOCK_2_0007, 208, 112);
	DRAW_COVER_UP(208, 112, COLOR_BLACK);
	DRAW_COVER_UP(208, 122, COLOR_BLACK);
	DRAW_SPRITE(SPRITE_BLOCK_2_0013, 320, 112);
	DRAW_COVER_UP(330, 122, COLOR_BLACK);
	DRAW_COVER_UP(330, 112, COLOR_BLACK);
	DRAW_SPRITE(SPRITE_BLOCK_2_0015, 336, 112);
	DRAW_COVER_UP(336, 112, COLOR_BLACK);
	DRAW_COVER_UP(336, 122, COLOR_BLACK);
	DRAW_COVER_UP(346, 122, COLOR_BLACK);
	DRAW_COVER_UP(346, 112, COLOR_BLACK);
	DRAW_SPRITE(SPRITE_BLOCK_2_0007, 352, 112);
	DRAW_COVER_UP(352, 112, COLOR_BLACK);
	DRAW_COVER_UP(352, 122, COLOR_BLACK);
	DRAW_SPRITE(SPRITE_BLOCK_7_0013, 464, 112);
	DRAW_SPRITE(SPRITE_BLOCK_7_0003, 480, 112);
	DRAW_SPRITE(SPRITE_BLOCK_2_0013, 144, 128);
	DRAW_COVER_UP(154, 138, COLOR_BLACK);
	DRAW_COVER_UP(154, 128, COLOR_BLACK);
	DRAW_SPRITE(SPRITE_BLOCK_2_0015, 160, 128);
	DRAW_COVER_UP(160, 128, COLOR_BLACK);
	DRAW_COVER_UP(160, 138, COLOR_BLACK);
	DRAW_COVER_UP(170, 138, COLOR_BLACK);
	DRAW_COVER_UP(170, 128, COLOR_BLACK);
	DRAW_SPRITE(SPRITE_BLOCK_2_0015, 176, 128);
	DRAW_COVER_UP(176, 128, COLOR_BLACK);
	DRAW_COVER_UP(176, 138, COLOR_BLACK);
	DRAW_COVER_UP(186, 138, COLOR_BLACK);
	DRAW_COVER_UP(186, 128, COLOR_BLACK);
	DRAW_SPRITE(SPRITE_BLOCK_2_0015, 192, 128);
	DRAW_COVER_UP(192, 128, COLOR_BLACK);
	DRAW_COVER_UP(192, 138, COLOR_BLACK);
	DRAW_COVER_UP(202, 138, COLOR_BLACK);
	DRAW_COVER_UP(202, 128, COLOR_BLACK);
	DRAW_SPRITE(SPRITE_BLOCK_2_0015, 208, 128);
	DRAW_COVER_UP(208, 128, COLOR_BLACK);
	DRAW_COVER_UP(208, 138, COLOR_BLACK);
	DRAW_COVER_UP(218, 138, COLOR_BLACK);
	DRAW_SPRITE(SPRITE_BLOCK_2_0006, 224, 128);
	DRAW_COVER_UP(224, 138, COLOR_BLACK);
	DRAW_SPRITE(SPRITE_BLOCK_2_0013, 320, 128);
	DRAW_COVER_UP(330, 138, COLOR_BLACK);
	DRAW_COVER_UP(330, 128, COLOR_BLACK);
	DRAW_SPRITE(SPRITE_BLOCK_2_0015, 336, 128);
	DRAW_COVER_UP(336, 128, COLOR_BLACK);
	DRAW_COVER_UP(336, 138, COLOR_BLACK);
	DRAW_COVER_UP(346, 138, COLOR_BLACK);
	DRAW_COVER_UP(346, 128, COLOR_BLACK);
	DRAW_SPRITE(SPRITE_BLOCK_2_0007, 352, 128);
	DRAW_COVER_UP(352, 128, COLOR_BLACK);
	DRAW_COVER_UP(352, 138, COLOR_BLACK);
	DRAW_SPRITE(SPRITE_BLOCK_7_0001, 464, 128);
	DRAW_SPRITE(SPRITE_BLOCK_2_0004, 480, 128);
	DRAW_SPRITE(SPRITE_BLOCK_2_0013, 144, 144);
	DRAW_COVER_UP(154, 154, COLOR_BLACK);
	DRAW_COVER_UP(154, 144, COLOR_BLACK);
	DRAW_SPRITE(SPRITE_BLOCK_2_0015, 160, 144);
	DRAW_COVER_UP(160, 144, COLOR_BLACK);
	DRAW_COVER_UP(160, 154, COLOR_BLACK);
	DRAW_COVER_UP(170, 154, COLOR_BLACK);
	DRAW_COVER_UP(170, 144, COLOR_BLACK);
	DRAW_SPRITE(SPRITE_BLOCK_2_0015, 176, 144);
	DRAW_COVER_UP(176, 144, COLOR_BLACK);
	DRAW_COVER_UP(176, 154, COLOR_BLACK);
	DRAW_COVER_UP(186, 154, COLOR_BLACK);
	DRAW_COVER_UP(186, 144, COLOR_BLACK);
	DRAW_SPRITE(SPRITE_BLOCK_2_0015, 192, 144);
	DRAW_COVER_UP(192, 144, COLOR_BLACK);
	DRAW_COVER_UP(192, 154, COLOR_BLACK);
	DRAW_COVER_UP(202, 154, COLOR_BLACK);
	DRAW_COVER_UP(202, 144, COLOR_BLACK);
	DRAW_SPRITE(SPRITE_BLOCK_2_0015, 208, 144);
	DRAW_COVER_UP(208, 144, COLOR_BLACK);
	DRAW_COVER_UP(208, 154, COLOR_BLACK);
	DRAW_COVER_UP(218, 154, COLOR_BLACK);
	DRAW_COVER_UP(218, 144, COLOR_BLACK);
	DRAW_SPRITE(SPRITE_BLOCK_2_0015, 224, 144);
	DRAW_COVER_UP(224, 144, COLOR_BLACK);
	DRAW_COVER_UP(224, 154, COLOR_BLACK);
	DRAW_COVER_UP(234, 154, COLOR_BLACK);
	DRAW_SPRITE(SPRITE_BLOCK_2_0006, 240, 144);
	DRAW_COVER_UP(240, 154, COLOR_BLACK);
	DRAW_SPRITE(SPRITE_BLOCK_2_0012, 304, 144);
	DRAW_COVER_UP(314, 154, COLOR_BLACK);
	DRAW_SPRITE(SPRITE_BLOCK_2_0015, 320, 144);
	DRAW_COVER_UP(320, 154, COLOR_BLACK);
	DRAW_COVER_UP(330, 154, COLOR_BLACK);
	DRAW_COVER_UP(330, 144, COLOR_BLACK);
	DRAW_SPRITE(SPRITE_BLOCK_2_0015, 336, 144);
	DRAW_COVER_UP(336, 144, COLOR_BLACK);
	DRAW_COVER_UP(336, 154, COLOR_BLACK);
	DRAW_COVER_UP(346, 154, COLOR_BLACK);
	DRAW_COVER_UP(346, 144, COLOR_BLACK);
	DRAW_SPRITE(SPRITE_BLOCK_2_0007, 352, 144);
	DRAW_COVER_UP(352, 144, COLOR_BLACK);
	DRAW_COVER_UP(352, 154, COLOR_BLACK);
	DRAW_SPRITE(SPRITE_BLOCK_2_0012, 464, 144);
	DRAW_COVER_UP(474, 154, COLOR_BLACK);
	DRAW_SPRITE(SPRITE_BLOCK_2_0015, 480, 144);
	DRAW_COVER_UP(480, 154, COLOR_BLACK);
	DRAW_COVER_UP(490, 154, COLOR_BLACK);
	DRAW_SPRITE(SPRITE_BLOCK_2_0006, 496, 144);
	DRAW_COVER_UP(496, 154, COLOR_BLACK);
	DRAW_SPRITE(SPRITE_BLOCK_2_0013, 144, 160);
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
	DRAW_COVER_UP(234, 160, COLOR_BLACK);
	DRAW_SPRITE(SPRITE_BLOCK_2_0015, 240, 160);
	DRAW_COVER_UP(240, 160, COLOR_BLACK);
	DRAW_COVER_UP(240, 170, COLOR_BLACK);
	DRAW_COVER_UP(250, 170, COLOR_BLACK);
	DRAW_SPRITE(SPRITE_BLOCK_2_0006, 256, 160);
	DRAW_COVER_UP(256, 170, COLOR_BLACK);
	DRAW_SPRITE(SPRITE_BLOCK_2_0013, 304, 160);
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
	DRAW_SPRITE(SPRITE_BLOCK_2_0007, 352, 160);
	DRAW_COVER_UP(352, 160, COLOR_BLACK);
	DRAW_COVER_UP(352, 170, COLOR_BLACK);
	DRAW_SPRITE(SPRITE_BLOCK_2_0012, 448, 160);
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
	DRAW_SPRITE(SPRITE_BLOCK_2_0007, 496, 160);
	DRAW_COVER_UP(496, 160, COLOR_BLACK);
	DRAW_COVER_UP(496, 170, COLOR_BLACK);
	DRAW_SPRITE(SPRITE_BLOCK_2_0009, 144, 176);
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
	DRAW_SPRITE(SPRITE_BLOCK_2_0003, 256, 176);
	DRAW_COVER_UP(256, 176, COLOR_BLACK);
	DRAW_SPRITE(SPRITE_BLOCK_2_0009, 304, 176);
	DRAW_COVER_UP(314, 176, COLOR_BLACK);
	DRAW_SPRITE(SPRITE_BLOCK_2_0011, 320, 176);
	DRAW_COVER_UP(320, 176, COLOR_BLACK);
	DRAW_COVER_UP(330, 176, COLOR_BLACK);
	DRAW_SPRITE(SPRITE_BLOCK_2_0011, 336, 176);
	DRAW_COVER_UP(336, 176, COLOR_BLACK);
	DRAW_COVER_UP(346, 176, COLOR_BLACK);
	DRAW_SPRITE(SPRITE_BLOCK_2_0003, 352, 176);
	DRAW_COVER_UP(352, 176, COLOR_BLACK);
	DRAW_SPRITE(SPRITE_BLOCK_2_0008, 432, 176);
	DRAW_SPRITE(SPRITE_BLOCK_2_0011, 448, 176);
	DRAW_COVER_UP(458, 176, COLOR_BLACK);
	DRAW_SPRITE(SPRITE_BLOCK_2_0011, 464, 176);
	DRAW_COVER_UP(464, 176, COLOR_BLACK);
	DRAW_COVER_UP(474, 176, COLOR_BLACK);
	DRAW_SPRITE(SPRITE_BLOCK_2_0011, 480, 176);
	DRAW_COVER_UP(480, 176, COLOR_BLACK);
	DRAW_COVER_UP(490, 176, COLOR_BLACK);
	DRAW_SPRITE(SPRITE_BLOCK_2_0003, 496, 176);
	DRAW_COVER_UP(496, 176, COLOR_BLACK);
	DRAW_SPRITE(SPRITE_BLOCK_1_0008, 32, 0);
	DRAW_SPRITE(SPRITE_BLOCK_1_0014, 48, 0);
	DRAW_COVER_UP(58, 10, COLOR_WHITE);
	DRAW_SPRITE(SPRITE_BLOCK_1_0006, 64, 0);
	DRAW_COVER_UP(64, 10, COLOR_WHITE);
	DRAW_SPRITE(SPRITE_BLOCK_7_0008, 80, 0);
	DRAW_SPRITE(SPRITE_BLOCK_7_0010, 96, 0);
	DRAW_SPRITE(SPRITE_BLOCK_7_0014, 112, 0);
	DRAW_SPRITE(SPRITE_BLOCK_7_0014, 128, 0);
	DRAW_SPRITE(SPRITE_BLOCK_7_0014, 144, 0);
	DRAW_SPRITE(SPRITE_BLOCK_7_0014, 160, 0);
	DRAW_SPRITE(SPRITE_BLOCK_7_0014, 176, 0);
	DRAW_SPRITE(SPRITE_BLOCK_7_0014, 192, 0);
	DRAW_SPRITE(SPRITE_BLOCK_7_0014, 208, 0);
	DRAW_SPRITE(SPRITE_BLOCK_7_0014, 224, 0);
	DRAW_SPRITE(SPRITE_BLOCK_7_0014, 240, 0);
	DRAW_SPRITE(SPRITE_BLOCK_7_0014, 256, 0);
	DRAW_SPRITE(SPRITE_BLOCK_7_0010, 272, 0);
	DRAW_SPRITE(SPRITE_BLOCK_7_0010, 288, 0);
	DRAW_SPRITE(SPRITE_BLOCK_7_0010, 304, 0);
	DRAW_SPRITE(SPRITE_BLOCK_7_0010, 320, 0);
	DRAW_SPRITE(SPRITE_BLOCK_7_0014, 336, 0);
	DRAW_SPRITE(SPRITE_BLOCK_7_0002, 352, 0);
	DRAW_SPRITE(SPRITE_BLOCK_1_0012, 368, 0);
	DRAW_COVER_UP(378, 10, COLOR_WHITE);
	DRAW_SPRITE(SPRITE_BLOCK_1_0006, 384, 0);
	DRAW_COVER_UP(384, 10, COLOR_WHITE);
	DRAW_SPRITE(SPRITE_BLOCK_1_0009, 48, 16);
	DRAW_COVER_UP(58, 16, COLOR_WHITE);
	DRAW_SPRITE(SPRITE_BLOCK_1_0011, 64, 16);
	DRAW_COVER_UP(64, 16, COLOR_WHITE);
	DRAW_SPRITE(SPRITE_BLOCK_1_0014, 80, 16);
	DRAW_COVER_UP(90, 26, COLOR_WHITE);
	DRAW_SPRITE(SPRITE_BLOCK_1_0006, 96, 16);
	DRAW_COVER_UP(96, 26, COLOR_WHITE);
	DRAW_SPRITE(SPRITE_BLOCK_7_0013, 112, 16);
	DRAW_SPRITE(SPRITE_BLOCK_7_0015, 128, 16);
	DRAW_SPRITE(SPRITE_BLOCK_7_0015, 144, 16);
	DRAW_SPRITE(SPRITE_BLOCK_7_0015, 160, 16);
	DRAW_SPRITE(SPRITE_BLOCK_7_0015, 176, 16);
	DRAW_SPRITE(SPRITE_BLOCK_7_0015, 192, 16);
	DRAW_SPRITE(SPRITE_BLOCK_7_0015, 208, 16);
	DRAW_SPRITE(SPRITE_BLOCK_7_0011, 224, 16);
	DRAW_SPRITE(SPRITE_BLOCK_7_0011, 240, 16);
	DRAW_SPRITE(SPRITE_BLOCK_7_0003, 256, 16);
	DRAW_SPRITE(SPRITE_BLOCK_1_0012, 272, 16);
	DRAW_COVER_UP(282, 26, COLOR_WHITE);
	DRAW_SPRITE(SPRITE_BLOCK_1_0014, 288, 16);
	DRAW_COVER_UP(288, 26, COLOR_WHITE);
	DRAW_COVER_UP(298, 26, COLOR_WHITE);
	DRAW_SPRITE(SPRITE_BLOCK_1_0014, 304, 16);
	DRAW_COVER_UP(304, 26, COLOR_WHITE);
	DRAW_COVER_UP(314, 26, COLOR_WHITE);
	DRAW_SPRITE(SPRITE_BLOCK_1_0006, 320, 16);
	DRAW_COVER_UP(320, 26, COLOR_WHITE);
	DRAW_SPRITE(SPRITE_BLOCK_7_0001, 336, 16);
	DRAW_SPRITE(SPRITE_BLOCK_1_0012, 352, 16);
	DRAW_SPRITE(SPRITE_BLOCK_1_0011, 368, 16);
	DRAW_COVER_UP(378, 16, COLOR_WHITE);
	DRAW_SPRITE(SPRITE_BLOCK_1_0003, 384, 16);
	DRAW_COVER_UP(384, 16, COLOR_WHITE);
	DRAW_SPRITE(SPRITE_BLOCK_1_0013, 80, 32);
	DRAW_COVER_UP(90, 42, COLOR_WHITE);
	DRAW_COVER_UP(90, 32, COLOR_WHITE);
	DRAW_SPRITE(SPRITE_BLOCK_1_0007, 96, 32);
	DRAW_COVER_UP(96, 32, COLOR_WHITE);
	DRAW_COVER_UP(96, 42, COLOR_WHITE);
	DRAW_SPRITE(SPRITE_BLOCK_7_0009, 112, 32);
	DRAW_SPRITE(SPRITE_BLOCK_7_0015, 128, 32);
	DRAW_SPRITE(SPRITE_BLOCK_7_0015, 144, 32);
	DRAW_SPRITE(SPRITE_BLOCK_7_0015, 160, 32);
	DRAW_SPRITE(SPRITE_BLOCK_7_0015, 176, 32);
	DRAW_SPRITE(SPRITE_BLOCK_7_0015, 192, 32);
	DRAW_SPRITE(SPRITE_BLOCK_7_0007, 208, 32);
	DRAW_SPRITE(SPRITE_BLOCK_1_0008, 224, 32);
	DRAW_SPRITE(SPRITE_BLOCK_1_0010, 240, 32);
	DRAW_SPRITE(SPRITE_BLOCK_1_0014, 256, 32);
	DRAW_COVER_UP(266, 42, COLOR_WHITE);
	DRAW_SPRITE(SPRITE_BLOCK_1_0015, 272, 32);
	DRAW_COVER_UP(272, 42, COLOR_WHITE);
	DRAW_COVER_UP(282, 32, COLOR_WHITE);
	DRAW_SPRITE(SPRITE_BLOCK_1_0011, 288, 32);
	DRAW_COVER_UP(288, 32, COLOR_WHITE);
	DRAW_COVER_UP(298, 32, COLOR_WHITE);
	DRAW_SPRITE(SPRITE_BLOCK_1_0011, 304, 32);
	DRAW_COVER_UP(304, 32, COLOR_WHITE);
	DRAW_COVER_UP(314, 32, COLOR_WHITE);
	DRAW_SPRITE(SPRITE_BLOCK_1_0011, 320, 32);
	DRAW_COVER_UP(320, 32, COLOR_WHITE);
	DRAW_SPRITE(SPRITE_BLOCK_1_0010, 336, 32);
	DRAW_SPRITE(SPRITE_BLOCK_1_0003, 352, 32);
	DRAW_SPRITE(SPRITE_BLOCK_1_0009, 80, 48);
	DRAW_COVER_UP(90, 48, COLOR_WHITE);
	DRAW_SPRITE(SPRITE_BLOCK_1_0015, 96, 48);
	DRAW_COVER_UP(96, 48, COLOR_WHITE);
	DRAW_SPRITE(SPRITE_BLOCK_1_0002, 112, 48);
	DRAW_SPRITE(SPRITE_BLOCK_7_0013, 128, 48);
	DRAW_SPRITE(SPRITE_BLOCK_7_0011, 144, 48);
	DRAW_SPRITE(SPRITE_BLOCK_7_0015, 160, 48);
	DRAW_SPRITE(SPRITE_BLOCK_7_0015, 176, 48);
	DRAW_SPRITE(SPRITE_BLOCK_7_0011, 192, 48);
	DRAW_SPRITE(SPRITE_BLOCK_7_0011, 208, 48);
	DRAW_SPRITE(SPRITE_BLOCK_7_0010, 224, 48);
	DRAW_SPRITE(SPRITE_BLOCK_7_0002, 240, 48);
	DRAW_SPRITE(SPRITE_BLOCK_1_0013, 256, 48);
	DRAW_COVER_UP(266, 48, COLOR_WHITE);
	DRAW_SPRITE(SPRITE_BLOCK_1_0003, 272, 48);
	DRAW_COVER_UP(272, 48, COLOR_WHITE);
	DRAW_SPRITE(SPRITE_BLOCK_1_0005, 96, 64);
	DRAW_SPRITE(SPRITE_BLOCK_7_0008, 112, 64);
	DRAW_SPRITE(SPRITE_BLOCK_7_0003, 128, 64);
	DRAW_SPRITE(SPRITE_BLOCK_1_0004, 144, 64);
	DRAW_SPRITE(SPRITE_BLOCK_7_0009, 160, 64);
	DRAW_SPRITE(SPRITE_BLOCK_7_0003, 176, 64);
	DRAW_SPRITE(SPRITE_BLOCK_1_0012, 192, 64);
	DRAW_SPRITE(SPRITE_BLOCK_1_0010, 208, 64);
	DRAW_SPRITE(SPRITE_BLOCK_1_0010, 224, 64);
	DRAW_SPRITE(SPRITE_BLOCK_1_0010, 240, 64);
	DRAW_SPRITE(SPRITE_BLOCK_1_0003, 256, 64);
	DRAW_SPRITE(SPRITE_BLOCK_1_0009, 96, 80);
	DRAW_SPRITE(SPRITE_BLOCK_1_0010, 112, 80);
	DRAW_SPRITE(SPRITE_BLOCK_1_0010, 128, 80);
	DRAW_SPRITE(SPRITE_BLOCK_1_0011, 144, 80);
	DRAW_SPRITE(SPRITE_BLOCK_1_0010, 160, 80);
	DRAW_SPRITE(SPRITE_BLOCK_1_0010, 176, 80);
	DRAW_SPRITE(SPRITE_BLOCK_1_0003, 192, 80);
	DRAW_SPRITE(SPRITE_BLOCK_4_0012, 384, 112);
	DRAW_SPRITE(SPRITE_BLOCK_4_0014, 400, 112);
	DRAW_SPRITE(SPRITE_BLOCK_4_0006, 416, 112);
	DRAW_SPRITE(SPRITE_BLOCK_4_0009, 384, 128);
	DRAW_SPRITE(SPRITE_BLOCK_4_0011, 400, 128);
	DRAW_SPRITE(SPRITE_BLOCK_4_0003, 416, 128);
	DRAW_SPRITE(SPRITE_BLOCK_4_0012, 288, 144);
	DRAW_SPRITE(SPRITE_BLOCK_4_0014, 304, 144);
	DRAW_SPRITE(SPRITE_BLOCK_4_0006, 320, 144);
	DRAW_SPRITE(SPRITE_BLOCK_6_0012, 384, 144);
	DRAW_SPRITE(SPRITE_BLOCK_6_0014, 400, 144);
	DRAW_SPRITE(SPRITE_BLOCK_6_0006, 416, 144);
	DRAW_SPRITE(SPRITE_BLOCK_0_0012, 0, 160);
	DRAW_SPRITE(SPRITE_BLOCK_0_0014, 16, 160);
	DRAW_SPRITE(SPRITE_BLOCK_0_0014, 32, 160);
	DRAW_SPRITE(SPRITE_BLOCK_0_0014, 48, 160);
	DRAW_SPRITE(SPRITE_BLOCK_0_0014, 64, 160);
	DRAW_SPRITE(SPRITE_BLOCK_0_0014, 80, 160);
	DRAW_SPRITE(SPRITE_BLOCK_0_0014, 96, 160);
	DRAW_SPRITE(SPRITE_BLOCK_0_0006, 112, 160);
	DRAW_SPRITE(SPRITE_BLOCK_4_0012, 192, 160);
	DRAW_SPRITE(SPRITE_BLOCK_4_0014, 208, 160);
	DRAW_SPRITE(SPRITE_BLOCK_4_0006, 224, 160);
	DRAW_SPRITE(SPRITE_BLOCK_4_0009, 288, 160);
	DRAW_SPRITE(SPRITE_BLOCK_4_0011, 304, 160);
	DRAW_SPRITE(SPRITE_BLOCK_4_0003, 320, 160);
	DRAW_SPRITE(SPRITE_BLOCK_6_0013, 384, 160);
	DRAW_SPRITE(SPRITE_BLOCK_6_0015, 400, 160);
	DRAW_SPRITE(SPRITE_BLOCK_6_0007, 416, 160);
	DRAW_SPRITE(SPRITE_BLOCK_0_0012, 480, 160);
	DRAW_SPRITE(SPRITE_BLOCK_0_0014, 496, 160);
	DRAW_SPRITE(SPRITE_BLOCK_0_0014, 512, 160);
	DRAW_SPRITE(SPRITE_BLOCK_0_0006, 528, 160);
	DRAW_SPRITE(SPRITE_BLOCK_0_0009, 0, 176);
	DRAW_SPRITE(SPRITE_BLOCK_0_0011, 16, 176);
	DRAW_SPRITE(SPRITE_BLOCK_0_0011, 32, 176);
	DRAW_SPRITE(SPRITE_BLOCK_0_0011, 48, 176);
	DRAW_SPRITE(SPRITE_BLOCK_0_0011, 64, 176);
	DRAW_SPRITE(SPRITE_BLOCK_0_0011, 80, 176);
	DRAW_SPRITE(SPRITE_BLOCK_0_0011, 96, 176);
	DRAW_SPRITE(SPRITE_BLOCK_0_0003, 112, 176);
	DRAW_SPRITE(SPRITE_BLOCK_4_0009, 192, 176);
	DRAW_SPRITE(SPRITE_BLOCK_4_0011, 208, 176);
	DRAW_SPRITE(SPRITE_BLOCK_4_0003, 224, 176);
	DRAW_SPRITE(SPRITE_BLOCK_6_0008, 288, 176);
	DRAW_SPRITE(SPRITE_BLOCK_6_0010, 304, 176);
	DRAW_SPRITE(SPRITE_BLOCK_6_0002, 320, 176);
	DRAW_SPRITE(SPRITE_BLOCK_6_0009, 384, 176);
	DRAW_SPRITE(SPRITE_BLOCK_6_0011, 400, 176);
	DRAW_SPRITE(SPRITE_BLOCK_6_0003, 416, 176);
	DRAW_SPRITE(SPRITE_BLOCK_0_0009, 480, 176);
	DRAW_SPRITE(SPRITE_BLOCK_0_0011, 496, 176);
	DRAW_SPRITE(SPRITE_BLOCK_0_0011, 512, 176);
	DRAW_SPRITE(SPRITE_BLOCK_0_0003, 528, 176);

	DRAW_SPRITE(SPRITE_BLOCK_0_0014, 0, 160);
	DRAW_SPRITE(SPRITE_BLOCK_0_0015, 0, 176);
	DRAW_SPRITE(SPRITE_BLOCK_0_0014, 528, 160);
	DRAW_SPRITE(SPRITE_BLOCK_0_0015, 528, 176);
}
