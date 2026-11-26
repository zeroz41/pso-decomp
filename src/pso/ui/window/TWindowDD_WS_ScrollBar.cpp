#include "pso/ui/window/TWindowCtrlMain_8024674C.h"
#include "pso/ui/window/WindowVertexBufferAbi.h"
#include "pso/ui/window/TWindowDD.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/system/task/TObject.h"
#include "pso/ui/window/TWindowDD_WS_ScrollBar.h"
#include "pso/object/ambient/TObjFish.h"
#include "types.h"
#include "pso/ui/window/TWindowDD_803488A8.h"
#include "pso/ui/window/WindowDrawContext.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/ui/window/TWindowSubStatusDisp_803DEE6C.h"
#include "pso/ui/window/TWindowDD_WS_String.h"

#pragma readonly_strings on


// Screen positions and scales of the word-select quad sets (TWindowDD__data_805434E8), set up by
// load_word_select_data. inferred: names from that use.
extern const NJS_POINT2 window_dd_quad_positions[7] = {
    {72.0f, 199.0f}, {122.0f, 199.0f}, {72.0f, 219.0f}, {122.0f, 219.0f},
    {172.0f, 199.0f}, {172.0f, 219.0f}, {222.0f, 199.0f},
};
extern const f32 window_dd_quad_scales[8] = {16.0f, 16.0f, 16.0f, 16.0f, 20.0f, 20.0f, 16.0f, 0.0f};

const char *TWindowDD_WS_ScrollBar__class_name = "TWindowDD_WS_ScrollBar";

extern "C" {


f32 lbl_805D6DC0;
f32 lbl_805D6DC4;
f32 lbl_805D6DC8;
f32 lbl_805D6DCC;
f32 lbl_805D6DD0;
f32 lbl_805D6DD4;
f32 lbl_805D6DD8;
f32 lbl_805D6DDC;
f32 lbl_805D6DE0;
f32 lbl_805D6DE4;
f32 lbl_805D6DE8;
f32 lbl_805D6DEC;
f32 lbl_805D6DF0;
f32 lbl_805D6DF4;
f32 lbl_805D6DF8;
f32 lbl_805D6DFC;
f32 lbl_805D6E00;

__declspec(section ".data") void *lbl_804EFBC8[2] = {
    (void *)0x0, (void *)0x0,
};
void *lbl_804EFBD0[5] = {
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x3,
};

#pragma push
#pragma dont_inline off
#pragma inline_depth(4)
// Edges of a span around its centre.
// inferred: span_start/span_end (names guessed); the original computes the bar's x edges through
// an inline helper, whose return value schedules differently from a plain `c - t`.
static inline f32 span_start(f32 center, f32 half_extent) { return center - half_extent; }
static inline f32 span_end(f32 center, f32 half_extent) { return center + half_extent; }
void TWindowDD_WS_ScrollBar::render() {
    TWindowDD_WS_ScrollBar *self = this;
    WindowDrawContext *rect = self->draw_default_entry();
    WindowVertex verts[8];
    f32 quad[8];
    s32 tex;
    s32 i;
    WindowTexturePoint *uv;
    WindowVertex *v;
    f32 z;
    f32 s;
    f32 half;
    f32 t;
    f32 c;
    f32 lo;
    f32 hi;
    f32 d;
    f32 x0;
    f32 step;
    f32 top;
    f32 bot;
    f32 range;
    f32 len;

    self->calc_inner_rect(rect);
    tex = TWindowDD::get_draw_count(hud_texlist);
    reset_window_vertices(verts, word_select_inverse_depth(self->draw_depth, 0.0f), -1);
    uv = TWindowDD__data_805434E8[6];
    s = rect->scale[1];
    v = verts;
    for (i = 0; i < 8; i++) {
        v->u = uv->x;
        v->v = uv->y;
        uv++;
        v++;
    }

    half = 0.5f * self->frame_size[1];
    t = half * s;
    c = self->frame_position[1] + half;
    lo = c - t;
    hi = c + t;
    if (t < scroll_bar_tile_height) {
        d = (hi - lo) / 3.0f;
    } else {
        d = 16.0f;
    }
    verts[0].y = verts[1].y = lo;
    verts[2].y = verts[3].y = lo + d;
    verts[4].y = verts[5].y = hi - d;
    verts[6].y = verts[7].y = hi;

    half = 0.5f * self->frame_size[0];
    c = self->frame_position[0] + half;
    step = scroll_bar_tile_width * rect->scale[0];
    t = half * rect->scale[0];
    x0 = span_start(c, t);
    v = verts;
    for (i = 0; i < 4; i++) {
        v[0].x = x0;
        v[1].x = x0 + step;
        v += 2;
    }
    half = 0.5f * scroll_arrow_size * rect->scale[0];
    quad[0] = span_start(c, half);
    quad[2] = span_end(c, half);
    draw_window_vertices(verts, 8, tex, 1);

    z = word_select_inverse_depth(self->draw_depth, 0.1f);
    TObjFish::set_global_param(hud_texlist);
    begin_screen_draw(1);
    set_draw_texture_and_color(0, -1);

    quad[5] = lbl_805D6DCC;
    quad[7] = lbl_805D6DD0;
    quad[4] = lbl_805D6DD4;
    quad[6] = lbl_805D6DD8;
    quad[1] = scroll_arrow_margin * s + lo;
    quad[3] = s * (scroll_arrow_margin + scroll_arrow_size) + lo;
    draw_textured_quad_at_depth(quad, z);

    quad[4] = lbl_805D6DDC;
    quad[6] = lbl_805D6DE0;
    quad[1] = hi - s * (scroll_arrow_margin + scroll_arrow_size);
    quad[3] = hi - scroll_arrow_margin * s;
    draw_textured_quad_at_depth(quad, z);

    quad[4] = lbl_805D6DE4;
    quad[6] = lbl_805D6DE8;
    quad[5] = lbl_805D6DEC;
    quad[7] = lbl_805D6DF0;
    quad[1] = lbl_805D6DC0 * s + lo;
    quad[3] = s * (14.0f + lbl_805D6DC0) + lo;
    draw_textured_quad_at_depth(quad, z);

    quad[5] = lbl_805D6DF4;
    quad[7] = lbl_805D6DF8;
    quad[1] = hi - s * (14.0f + lbl_805D6DC0);
    quad[3] = hi - lbl_805D6DC0 * s;
    draw_textured_quad_at_depth(quad, z);

    top = lo + lbl_805D6DC4 * s;
    bot = hi - lbl_805D6DC4 * s;
    quad[5] = lbl_805D6DFC;
    quad[7] = lbl_805D6E00;
    if (self->count <= self->visible_count) {
        quad[1] = top;
        quad[3] = bot;
    } else {
        range = self->inverse_count * (bot - top);
        len = range * self->visible_count;
        if (len < 2.0f) {
            len = 2.0f;
        }
        quad[1] = range * self->first_index + top;
        quad[3] = quad[1] + len;
    }
    draw_textured_quad_at_depth(quad, z);
    end_screen_draw();
}
#pragma pop

// Defer the remaining functions to preserve the original vtable and constructor layout.
#pragma defer_codegen on

void __sinit_TWindowDD_WS_ScrollBar_cpp(void) {
    lbl_805D6DC0 = 17.0f + scroll_arrow_margin;
    lbl_805D6DC4 = 14.0f + (17.0f + scroll_arrow_margin);
    lbl_805D6DC8 = window_dd_texel_scale;
    lbl_805D6DCC = scroll_arrow_v * lbl_805D6DC8;
    lbl_805D6DD0 = lbl_805D6DC8 * (scroll_arrow_v + scroll_arrow_texture_height);
    lbl_805D6DD4 = scroll_arrow_up_u * lbl_805D6DC8;
    lbl_805D6DD8 = lbl_805D6DC8 * (scroll_arrow_up_u + scroll_arrow_size);
    lbl_805D6DDC = scroll_arrow_down_u * lbl_805D6DC8;
    lbl_805D6DE0 = lbl_805D6DC8 * (scroll_arrow_down_u + scroll_arrow_size);
    lbl_805D6DE4 = 224.0f * lbl_805D6DC8;
    lbl_805D6DE8 = 238.0f * lbl_805D6DC8;
    lbl_805D6DEC = 58.0f * lbl_805D6DC8;
    lbl_805D6DF0 = 72.0f * lbl_805D6DC8;
    lbl_805D6DF4 = 86.0f * lbl_805D6DC8;
    lbl_805D6DF8 = 100.0f * lbl_805D6DC8;
    lbl_805D6DFC = 72.0f * lbl_805D6DC8;
    lbl_805D6E00 = 86.0f * lbl_805D6DC8;
    ((f32 *)lbl_804EFBC8)[0] = scroll_bar_x;
    ((f32 *)lbl_804EFBC8)[1] = scroll_bar_y;
    ((f32 *)lbl_804EFBD0)[0] = scroll_bar_width;
    ((f32 *)lbl_804EFBD0)[1] = scroll_bar_height;
    ((f32 *)lbl_804EFBD0)[2] = scroll_bar_depth;
}

__declspec(section ".ctors") static void *const __sinit_TWindowDD_WS_ScrollBar_cpp_ref = (void *)__sinit_TWindowDD_WS_ScrollBar_cpp;

TWindowDD_WS_ScrollBar *TWindowDD_WS_ScrollBar::create() { return new TWindowDD_WS_ScrollBar; }

TWindowDD_WS_ScrollBar::TWindowDD_WS_ScrollBar()
    : TWindowBase((u8 *)lbl_804EFBD0, 4, (u8 *)lbl_804EFBC8) {
    m_name = TWindowDD_WS_ScrollBar__class_name;
    count = 6.0f;
    visible_count = 6.0f;
    first_index = 0.0f;
    open_tick = 0x01000000;
}

TWindowDD_WS_ScrollBar::~TWindowDD_WS_ScrollBar() {}

void TWindowDD_WS_ScrollBar::set_range(s32 total, s32 visible) {
    count = total;
    visible_count = visible;
    inverse_count = 1.0f / count;
}

void TWindowDD_WS_ScrollBar::set_first_index(s32 index) {
    first_index = index;
}

void TWindowDD_WS_ScrollBar::run_task() {
    update_window();
    update_fade();
}

}
