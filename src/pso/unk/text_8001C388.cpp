#include "types.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/ui/window/TWindowSubStatusDisp_803DEE6C.h"
#include "pso/object/ambient/TObjFish.h"

struct TitleBackgroundTile {
    u32 x;
    u32 y;
    u32 w;
    u32 h;
    s32 tex;
};

extern TitleBackgroundTile lbl_80480BC8[8];

extern "C" void draw_title_background_quads(s32 texture_list, s32 tex_base, s32 color, s32 mode, f32 depth) {
    static f32 s_offset_x0 = 0.0f;
    static f32 s_offset_y0 = 0.0f;
    static f32 s_offset_x1 = 0.0f;
    static f32 s_offset_y1 = 0.0f;
    f32 q[8];
    int i;

    begin_screen_draw(mode);
    TObjFish::set_global_param(texture_list);
    for (i = 0; i < 8; i++) {
        set_draw_texture_and_color(tex_base + lbl_80480BC8[i].tex, color);
        q[0] = s_offset_x0 + (f32)lbl_80480BC8[i].x;
        q[1] = s_offset_y0 + (f32)lbl_80480BC8[i].y;
        q[2] = s_offset_x1 + ((f32)lbl_80480BC8[i].x + (f32)lbl_80480BC8[i].w);
        q[3] = s_offset_y1 + ((f32)lbl_80480BC8[i].y + (f32)lbl_80480BC8[i].h);
        q[4] = 0.0f;
        q[5] = 0.0f;
        q[6] = 1.0f;
        q[7] = 1.0f;
        draw_textured_quad_at_depth(q, -1.0f / depth);
    }
    TWindowSubStatusDisp::get_player();
}

TitleBackgroundTile lbl_80480BC8[8] = {
    { 0x200, 0x180, 0x80, 0x80, 7 },
    { 0x200, 0x100, 0x80, 0x80, 6 },
    { 0x200, 0x80, 0x80, 0x80, 5 },
    { 0x200, 0x0, 0x80, 0x80, 4 },
    { 0x0, 0x100, 0x100, 0x100, 1 },
    { 0x0, 0x0, 0x100, 0x100, 0 },
    { 0x100, 0x100, 0x100, 0x100, 3 },
    { 0x100, 0x0, 0x100, 0x100, 2 },
};
