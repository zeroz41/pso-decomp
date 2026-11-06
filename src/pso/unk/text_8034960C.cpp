#include "types.h"
#include "pso/unk/text_8034960C.h"
#include "pso/ui/charcreate/TObjCMHairMenu.h"
struct Desc_80349844 {
    f32 *pos;
    s32 *col;
    s32 a;
    s32 b;
};

struct Desc_80349728 {
    f32 *pos;
    s32 *col;
    s32 a;
    s32 b;
};

struct Vec2_80349728 {
    f32 x;
    f32 y;
};

struct Desc_8034960C {
    f32 *pos;
    s32 *col;
    s32 a;
    s32 b;
};

struct Vec2_8034960C {
    f32 x;
    f32 y;
};

extern "C" {
void draw_color_lines(Desc_80349844 *, s32, s32, f32);
}
extern const f32 lbl_805DFD04;
extern const f32 lbl_805DFD08;
extern const f32 lbl_805DFD0C;
extern const f32 lbl_805DFD10;
extern const f32 lbl_805DFD14;
extern const Vec2_80349728 lbl_80478718[2];
extern const Vec2_80349728 lbl_80478728[2];
extern const f32 lbl_805DFD00;
extern const Vec2_8034960C lbl_80478738[2];
extern const Vec2_8034960C quest_load_panel_overlay_offsets[2];

void draw_quest_load_panel_overlays(void) {
    f32 pos[8];
    Desc_8034960C d;
    s32 col[4];
    u32 i;
    d.pos = pos;
    d.col = col;
    d.a = 0;
    d.b = 4;
    i = 0;
    do {
        d.pos[0] = lbl_80478738[i].x;
        d.pos[1] = lbl_80478738[i].y;
        d.col[0] = 0x77;
        d.pos[2] = lbl_80478738[i].x;
        d.pos[3] = d.pos[1] + quest_load_panel_overlay_offsets[i].y;
        d.col[1] = 0x77;
        d.pos[4] = d.pos[0] + quest_load_panel_overlay_offsets[i].x;
        d.pos[5] = d.pos[1] + quest_load_panel_overlay_offsets[i].y;
        d.col[2] = 0x77;
        d.pos[6] = d.pos[0] + quest_load_panel_overlay_offsets[i].x;
        d.pos[7] = d.pos[1];
        d.col[3] = 0x77;
        ((TObjCMHairMenu *)(&d))->draw_tri_fan_2d(4, 7, lbl_805DFD00);
        i++;
    } while (i < 2);
}

void draw_quest_load_letterbox_bars(void) {
    f32 pos[8];
    Desc_80349728 d;
    s32 col[4];
    u32 i;
    d.pos = pos;
    d.col = col;
    d.a = 0;
    d.b = 4;
    i = 0;
    do {
        d.pos[0] = lbl_80478718[i].x;
        d.pos[1] = lbl_80478718[i].y;
        d.col[0] = 0xFF;
        d.pos[2] = lbl_80478718[i].x;
        d.pos[3] = d.pos[1] + lbl_80478728[i].y;
        d.col[1] = 0xFF;
        d.pos[4] = d.pos[0] + lbl_80478728[i].x;
        d.pos[5] = d.pos[1] + lbl_80478728[i].y;
        d.col[2] = 0xFF;
        d.pos[6] = d.pos[0] + lbl_80478728[i].x;
        d.pos[7] = d.pos[1];
        d.col[3] = 0xFF;
        ((TObjCMHairMenu *)(&d))->draw_tri_fan_2d(4, 3, lbl_805DFD00);
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
        d.pos[0] = lbl_805DFD04;
        y = lbl_805DFD08 * (f32) i;
        d.pos[1] = y;
        d.col[0] = 0xFF001A36;
        d.pos[2] = lbl_805DFD0C;
        y2 = lbl_805DFD10 + y;
        d.pos[3] = y;
        d.col[1] = 0xFF001A36;
        d.pos[4] = lbl_805DFD0C;
        d.pos[5] = y2;
        d.col[2] = 0xFF001A36;
        d.pos[6] = lbl_805DFD0C;
        d.pos[7] = y2;
        d.col[3] = 0xFF001A36;
        draw_color_lines(&d, 4, 3, lbl_805DFD14);
    }
}
