#include "pso/ui/window/TWindowCtrlMain_8024674C.h"
#include "types.h"
#include "pso/ui/window/WindowScrollBar.h"
#include "pso/ui/window/WindowDrawContext.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/ui/window/TWindowSubStatusDisp_803DEE6C.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/render/render_util.h"
#include "pso/system/NinjaTypes.h"

// Scroll-list helpers shared by the window menus: a TU of its own between TWindowRoom and TWindowSetLevelUp.
// Its .sdata2 pool (0.0f of WindowScrollBar::clamp_offset, then draw_window_scrollbar's floats) starts at the
// 8-aligned 0x805DD2F8 and is padded to 0x805DD338, where TWindowSetLevelUp's " +" starts the next TU's pool.


extern "C" {
void __dl__FPv(void);
}

s32 WindowScrollBar::clamp_offset(f32 *offset, const NJS_POINT2 *visible) const {
    f32 room;
    if (extent.y < visible->y || offset[1] < 0.0f) {
        offset[1] = 0.0f;
        return 1;
    }
    room = extent.y - visible->y;
    if (offset[1] > room) {
        offset[1] = room;
        return 1;
    }
    return 0;
}

void draw_window_scrollbar(const WindowScrollBar *scroll, WindowDrawContext *context, const f32 *offset) {
    TexturedQuad q;
    f32 depth;
    f32 x;
    f32 y;
    f32 t;
    if (context->open_tick < 0) {
        return;
    }
    if (scroll->extent.y <= context->inner_h) {
        return;
    }
    if (context->h < 35.0f) {
        return;
    }
    x = context->x + context->w - 7.0f;
    y = 17.0f + context->y;
    begin_screen_draw(0);
    TObjFish::set_global_param(hud_texlist);
    set_draw_texture_and_color(0, 0xFF646464);
    depth = -1.0f / (0.1196f + context->depth);
    q.x0 = x;
    q.x1 = q.x0 + 3.0f;
    q.y0 = y;
    q.y1 = (y + context->h) - 34.0f;
    q.u0 = 0.9375f;
    q.v0 = 0.23046875f;
    q.u1 = 0.94921875f;
    q.v1 = 0.25f;
    context->transform_quad(&q);
    draw_textured_quad_at_depth(&q.x0, depth);
    set_constant_material_color(calc_pulse_flash_color(0x86, 0xFF, 0x41, scroll->frame, 0x1C2, 0x12C, 0x13B, 0x14A));
    depth = -1.0f / (0.1495f + context->depth);
    t = context->h;
    if (t >= 35.0f) {
        t -= 34.0f;
        if (scroll->extent.y <= t) {
            q.y0 = y;
            q.y1 = y + t;
        } else {
            q.y0 = y + offset[1] * t / scroll->extent.y;
            q.y1 = q.y0 + context->inner_h * t / scroll->extent.y;
        }
    }
    q.x0 = x;
    q.x1 = q.x0 + 3.0f;
    q.u0 = 0.96484375f;
    q.v0 = 0.23046875f;
    q.u1 = 0.9765625f;
    q.v1 = 0.25f;
    context->transform_quad(&q);
    draw_textured_quad_at_depth(&q.x0, depth);
    TWindowSubStatusDisp::get_player();
}

void WindowScrollBar::increment_counter() {
    frame++;
}

s32 TWindowSubStatusDisp::destroy_allocation(s32 arg0, s16 arg1) {
    if ((arg0 != 0) && (arg1 > 0)) {
        __dl__FPv();
    }
    return arg0;
}

WindowScrollBar::WindowScrollBar(const NJS_POINT2 *extent) {
    set_extent(extent);
    frame = 0;
}
