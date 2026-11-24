#include "types.h"
#include "pso/render/Draw2D.h"
#include "pso/unk/text_8034960C.h"
#include "pso/ui/charcreate/TObjCMHairMenu.h"
#include "pso/system/NinjaTypes.h"
struct Desc_80349844 {
    f32 *pos;
    s32 *col;
    s32 a;
    s32 b;
};

// Top-left corner and size of the two black bars draw_quest_load_letterbox_bars fills
// (quest_load_letterbox_bar_positions and _sizes are inferred names).
static const NJS_POINT2 quest_load_letterbox_bar_positions[2] = {{0.0f, 0.0f}, {0.0f, 416.0f}};
static const NJS_POINT2 quest_load_letterbox_bar_sizes[2] = {{640.0f, 64.0f}, {640.0f, 64.0f}};
// Top-left corner and size of the two panels draw_quest_load_panel_overlays shades
// (quest_load_panel_overlay_positions is an inferred name).
static const NJS_POINT2 quest_load_panel_overlay_positions[2] = {{31.0f, 73.0f}, {543.0f, 75.0f}};
static const NJS_POINT2 quest_load_panel_overlay_offsets[2] = {{455.0f, 332.0f}, {72.0f, 332.0f}};

// TAdLoadQuestCellGC's code follows these functions in the same translation unit; its name
// string sits after the tables above in .rodata.
const char *TAdLoadQuestCellGC__name = "TAdLoadQuestCellGC";

extern "C" {
void draw_color_lines(Desc_80349844 *, s32, s32, f32);
}

void draw_quest_load_panel_overlays(void) {
    NJS_POINT2 pos[4];
    NJS_POINT2COL d;
    NJS_COLOR col[4];
    u32 i;
    d.p = pos;
    d.col = col;
    d.tex = NULL;
    d.num = 4;
    i = 0;
    do {
        d.p[0].x = quest_load_panel_overlay_positions[i].x;
        d.p[0].y = quest_load_panel_overlay_positions[i].y;
        d.col[0].color = 0x77;
        d.p[1].x = quest_load_panel_overlay_positions[i].x;
        d.p[1].y = d.p[0].y + quest_load_panel_overlay_offsets[i].y;
        d.col[1].color = 0x77;
        d.p[2].x = d.p[0].x + quest_load_panel_overlay_offsets[i].x;
        d.p[2].y = d.p[0].y + quest_load_panel_overlay_offsets[i].y;
        d.col[2].color = 0x77;
        d.p[3].x = d.p[0].x + quest_load_panel_overlay_offsets[i].x;
        d.p[3].y = d.p[0].y;
        d.col[3].color = 0x77;
        draw_polygon_2d(&d, 4, 7, (-490.0f));
        i++;
    } while (i < 2);
}

void draw_quest_load_letterbox_bars(void) {
    NJS_POINT2 pos[4];
    NJS_POINT2COL d;
    NJS_COLOR col[4];
    u32 i;
    d.p = pos;
    d.col = col;
    d.tex = NULL;
    d.num = 4;
    i = 0;
    do {
        d.p[0].x = quest_load_letterbox_bar_positions[i].x;
        d.p[0].y = quest_load_letterbox_bar_positions[i].y;
        d.col[0].color = 0xFF;
        d.p[1].x = quest_load_letterbox_bar_positions[i].x;
        d.p[1].y = d.p[0].y + quest_load_letterbox_bar_sizes[i].y;
        d.col[1].color = 0xFF;
        d.p[2].x = d.p[0].x + quest_load_letterbox_bar_sizes[i].x;
        d.p[2].y = d.p[0].y + quest_load_letterbox_bar_sizes[i].y;
        d.col[2].color = 0xFF;
        d.p[3].x = d.p[0].x + quest_load_letterbox_bar_sizes[i].x;
        d.p[3].y = d.p[0].y;
        d.col[3].color = 0xFF;
        draw_polygon_2d(&d, 4, 3, (-490.0f));
        i++;
    } while (i < 2);
}

void fn_80349844(void) {
    f32 pos[8];
    Desc_80349844 d;
    s32 col[4];
    u32 i;
    f32 y;
    f32 y2;
    d.pos = pos;
    d.col = col;
    d.a = 0;
    d.b = 4;
    for (i = 0; i < 0x78; i++) {
        d.pos[0] = 0.0f;
        y = 8.0f * (f32) i;
        d.pos[1] = y;
        d.col[0] = 0xFF001A36;
        d.pos[2] = 640.0f;
        y2 = 4.0f + y;
        d.pos[3] = y;
        d.col[1] = 0xFF001A36;
        d.pos[4] = 640.0f;
        d.pos[5] = y2;
        d.col[2] = 0xFF001A36;
        d.pos[6] = 640.0f;
        d.pos[7] = y2;
        d.col[3] = 0xFF001A36;
        draw_color_lines(&d, 4, 3, (-500.0f));
    }
}
