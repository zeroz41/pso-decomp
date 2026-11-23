#include "types.h"
#include "pso/ui/window/WindowScrollBar.h"
#include "pso/ui/window/WindowDrawContext.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/ui/window/TWindowSubStatusDisp_803DEE6C.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/render/render_util.h"
#include "pso/system/NinjaTypes.h"

// Scroll-list helpers shared by the window menus: a TU of its own between TWindowRoom and TWindowSetLevelUp.
// Its .sdata2 pool (0.0f of clamp_list_scroll_offset, then draw_window_scrollbar's floats) starts at the
// 8-aligned 0x805DD2F8 and is padded to 0x805DD338, where TWindowSetLevelUp's " +" starts the next TU's pool.


struct Ctx_8026D790 {
    f32 x, y, width, height;
    u8 pad10[0x1C - 0x10];
    f32 clip_height;
    u8 pad20[0x30 - 0x20];
    s32 x30;
    u8 pad34[4];
    f32 x38;
};


extern "C" {
void __dl__FPv(void);
void draw_window_scrollbar(WindowScrollBar *scroll, Ctx_8026D790 *c, f32 *offset);
extern void *hud_texlist;

s32 clamp_list_scroll_offset(WindowScrollBar *scroll, NJS_POINT2 *offset, NJS_POINT2 *range) {
    f32 room;
    if (scroll->height < range->y || offset->y < 0.0f) {
        offset->y = 0.0f;
        return 1;
    }
    room = scroll->height - range->y;
    if (offset->y > room) {
        offset->y = room;
        return 1;
    }
    return 0;
}
}

void draw_window_scrollbar(WindowScrollBar *scroll, Ctx_8026D790 *c, f32 *offset) {
    TexturedQuad q;
    f32 depth;
    f32 x;
    f32 y;
    f32 t;
    if (c->x30 < 0) {
        return;
    }
    if (scroll->height <= c->clip_height) {
        return;
    }
    if (c->height < 35.0f) {
        return;
    }
    x = c->x + c->width - 7.0f;
    y = 17.0f + c->y;
    begin_screen_draw(0);
    TObjFish::set_global_param(reinterpret_cast<NJS_TEXLIST *>(hud_texlist));
    set_draw_texture_and_color(0, 0xFF646464);
    depth = -1.0f / (0.1196f + c->x38);
    q.x0 = x;
    q.x1 = q.x0 + 3.0f;
    q.y0 = y;
    q.y1 = (y + c->height) - 34.0f;
    q.u0 = 0.9375f;
    q.v0 = 0.23046875f;
    q.u1 = 0.94921875f;
    q.v1 = 0.25f;
    ((WindowDrawContext *)c)->transform_quad(&q);
    draw_textured_quad_at_depth(&q.x0, depth);
    set_constant_material_color(calc_pulse_flash_color(0x86, 0xFF, 0x41, scroll->frame, 0x1C2, 0x12C, 0x13B, 0x14A));
    depth = -1.0f / (0.1495f + c->x38);
    t = c->height;
    if (t >= 35.0f) {
        t -= 34.0f;
        if (scroll->height <= t) {
            q.y0 = y;
            q.y1 = y + t;
        } else {
            q.y0 = y + offset[1] * t / scroll->height;
            q.y1 = q.y0 + c->clip_height * t / scroll->height;
        }
    }
    q.x0 = x;
    q.x1 = q.x0 + 3.0f;
    q.u0 = 0.96484375f;
    q.v0 = 0.23046875f;
    q.u1 = 0.9765625f;
    q.v1 = 0.25f;
    ((WindowDrawContext *)c)->transform_quad(&q);
    draw_textured_quad_at_depth(&q.x0, depth);
    TWindowSubStatusDisp::get_player();
}

void TWindowSubStatusDisp::increment_counter() {
    *(s32 *)&this->m_prev = (s32) (*(s32 *)&this->m_prev + 1);
}

s32 TWindowSubStatusDisp::destroy_allocation(s32 arg0, s16 arg1) {
    if ((arg0 != 0) && (arg1 > 0)) {
        __dl__FPv();
    }
    return arg0;
}

WindowScrollBar::WindowScrollBar(void *pair) {
    copy_position(pair);
    frame = 0;
}
