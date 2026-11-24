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
#include "pso/ui/window/TWindowDD_80340EA8.h"
#include "pso/ui/window/TWindowDD_WS_String.h"

#pragma readonly_strings on


// Screen positions and scales of the word-select quad sets (TWindowDD__data_805434E8), set up by
// TWindowDD__sub_80344114. inferred: names from that use.
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
extern const f32 lbl_805DFB24;
extern const f32 lbl_805DFB28;
extern const f32 lbl_805DFB38;
extern const f32 lbl_805DFBCC;

__declspec(section ".data") void *lbl_804EFBC8[2] = {
    (void *)0x0, (void *)0x0,
};
void *lbl_804EFBD0[5] = {
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x3,
};
extern const f32 TWindowDD__data_805DFB18;
extern const f32 lbl_805DFB34;
extern const f32 lbl_805DFB3C;
extern const f32 lbl_805DFB2C;
extern const f32 lbl_805DFB30;
extern const f32 lbl_805DFBC4;
extern const f32 lbl_805DFBBC;
extern const f32 lbl_805DFBC8;
extern const f32 lbl_805DFBC0;
extern const f32 lbl_805DFC24;

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
    ((TWindowDD *)verts)->reset_entries(TWindowDD__sub_80348AD4(self->draw_depth, 0.0f), -1);
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
    if (t < lbl_805DFB28) {
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
    step = lbl_805DFB24 * rect->scale[0];
    t = half * rect->scale[0];
    x0 = span_start(c, t);
    v = verts;
    for (i = 0; i < 4; i++) {
        v[0].x = x0;
        v[1].x = x0 + step;
        v += 2;
    }
    half = 0.5f * lbl_805DFB38 * rect->scale[0];
    quad[0] = span_start(c, half);
    quad[2] = span_end(c, half);
    ((TWindowDD *)verts)->draw_transformed_primitive(8, tex, 1);

    z = TWindowDD__sub_80348AD4(self->draw_depth, 0.1f);
    TObjFish::set_global_param(hud_texlist);
    begin_screen_draw(1);
    set_draw_texture_and_color(0, -1);

    quad[5] = lbl_805D6DCC;
    quad[7] = lbl_805D6DD0;
    quad[4] = lbl_805D6DD4;
    quad[6] = lbl_805D6DD8;
    quad[1] = lbl_805DFBCC * s + lo;
    quad[3] = s * (lbl_805DFBCC + lbl_805DFB38) + lo;
    draw_textured_quad_at_depth(quad, z);

    quad[4] = lbl_805D6DDC;
    quad[6] = lbl_805D6DE0;
    quad[1] = hi - s * (lbl_805DFBCC + lbl_805DFB38);
    quad[3] = hi - lbl_805DFBCC * s;
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
    if (self->pad_64 <= self->pad_68) {
        quad[1] = top;
        quad[3] = bot;
    } else {
        range = self->pad_60 * (bot - top);
        len = range * self->pad_68;
        if (len < 2.0f) {
            len = 2.0f;
        }
        quad[1] = range * self->pad_6C + top;
        quad[3] = quad[1] + len;
    }
    draw_textured_quad_at_depth(quad, z);
    TWindowSubStatusDisp::get_player();
}
#pragma pop

// Defer the remaining functions to preserve the original vtable and constructor layout.
#pragma defer_codegen on

void __sinit_TWindowDD_80340A78_cpp(void) {
    lbl_805D6DC0 = 17.0f + lbl_805DFBCC;
    lbl_805D6DC4 = 14.0f + (17.0f + lbl_805DFBCC);
    lbl_805D6DC8 = TWindowDD__data_805DFB18;
    lbl_805D6DCC = lbl_805DFB34 * lbl_805D6DC8;
    lbl_805D6DD0 = lbl_805D6DC8 * (lbl_805DFB34 + lbl_805DFB3C);
    lbl_805D6DD4 = lbl_805DFB2C * lbl_805D6DC8;
    lbl_805D6DD8 = lbl_805D6DC8 * (lbl_805DFB2C + lbl_805DFB38);
    lbl_805D6DDC = lbl_805DFB30 * lbl_805D6DC8;
    lbl_805D6DE0 = lbl_805D6DC8 * (lbl_805DFB30 + lbl_805DFB38);
    lbl_805D6DE4 = 224.0f * lbl_805D6DC8;
    lbl_805D6DE8 = 238.0f * lbl_805D6DC8;
    lbl_805D6DEC = 58.0f * lbl_805D6DC8;
    lbl_805D6DF0 = 72.0f * lbl_805D6DC8;
    lbl_805D6DF4 = 86.0f * lbl_805D6DC8;
    lbl_805D6DF8 = 100.0f * lbl_805D6DC8;
    lbl_805D6DFC = 72.0f * lbl_805D6DC8;
    lbl_805D6E00 = 86.0f * lbl_805D6DC8;
    ((f32 *)lbl_804EFBC8)[0] = lbl_805DFBC4;
    ((f32 *)lbl_804EFBC8)[1] = lbl_805DFBC8;
    ((f32 *)lbl_804EFBD0)[0] = lbl_805DFBBC;
    ((f32 *)lbl_804EFBD0)[1] = lbl_805DFBC0;
    ((f32 *)lbl_804EFBD0)[2] = lbl_805DFC24;
}

__declspec(section ".ctors") static void *const __sinit_TWindowDD_80340A78_cpp_ref = (void *)__sinit_TWindowDD_80340A78_cpp;

void *TWindowDD__sub_80340F70(void) { return new TWindowDD_WS_ScrollBar; }

TWindowDD_WS_ScrollBar::TWindowDD_WS_ScrollBar()
    : TWindowBase((u8 *)lbl_804EFBD0, 4, (u8 *)lbl_804EFBC8) {
    m_name = TWindowDD_WS_ScrollBar__class_name;
    pad_64 = 6.0f;
    pad_68 = 6.0f;
    pad_6C = 0.0f;
    open_tick = 0x01000000;
}

TWindowDD_WS_ScrollBar::~TWindowDD_WS_ScrollBar() {}

void TWindowDD::set_scale(s32 arg1, s32 arg2) {
    *(f32 *)&this->m_64[0] = (f32) arg1;
    *(f32 *)&this->m_64[1] = (f32) arg2;
    *(f32 *)&this->m_44[7] = (f32) (1.0f / *(f32 *)&this->m_64[0]);
}

void TWindowDD::set_value_f32(s32 arg1) {
    *(f32 *)&this->m_64[2] = (f32) arg1;
}

void TWindowDD_WS_ScrollBar::run_task() {
    ((TWindowDD *)this)->initialize_subwindow();
    update_fade();
}

}
