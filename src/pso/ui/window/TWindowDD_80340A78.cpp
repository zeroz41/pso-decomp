#include "pso/ui/window/TWindowDD.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/system/task/TObject.h"
#include "pso/ui/window/TWindowDD_WS_ScrollBar.h"
#include "pso/object/ambient/TObjFish.h"
#include "types.h"
#include "pso/ui/window/TWindowDD_803488A8.h"
#include "pso/ui/window/TWindowKeyBoardSoft.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/ui/window/TWindowSubStatusDisp_803DEE6C.h"
#include "pso/ui/window/TWindowDD_80340EA8.h"
#include "pso/ui/window/TWindowDD_WS_String.h"

struct E_803403F8 { f32 a; f32 b; f32 c; f32 d; f32 e; s32 f; };
struct Src_80348A9C { f32 x; f32 y; };

extern "C" {

extern s32 lbl_805D63F0;

extern f32 lbl_805D6DC0;
extern f32 lbl_805D6DC4;
extern f32 lbl_805D6DCC;
extern f32 lbl_805D6DD0;
extern f32 lbl_805D6DD4;
extern f32 lbl_805D6DD8;
extern f32 lbl_805D6DDC;
extern f32 lbl_805D6DE0;
extern f32 lbl_805D6DE4;
extern f32 lbl_805D6DE8;
extern f32 lbl_805D6DEC;
extern f32 lbl_805D6DF0;
extern f32 lbl_805D6DF4;
extern f32 lbl_805D6DF8;
extern f32 lbl_805D6DFC;
extern f32 lbl_805D6E00;
extern const f32 lbl_805DFB24;
extern const f32 lbl_805DFB28;
extern const f32 lbl_805DFB38;
extern const f32 lbl_805DFBCC;
extern Src_80348A9C TWindowDD__data_805434E8[7][8];

#pragma push
#pragma dont_inline off
#pragma inline_depth(4)
// Edges of a span around its centre.
// inferred: span_start/span_end (names guessed); the original computes the bar's x edges through
// an inline helper, whose return value schedules differently from a plain `c - t`.
static inline f32 span_start(f32 center, f32 half_extent) { return center - half_extent; }
static inline f32 span_end(f32 center, f32 half_extent) { return center + half_extent; }
void TWindowDD__sub_80340A78(TWindowDD_WS_ScrollBar *self) {
    TWindowKeyBoardSoft *rect = (TWindowKeyBoardSoft *)TWindowDD::draw_default_entry((s32)self);
    E_803403F8 verts[8];
    f32 quad[8];
    s32 tex;
    s32 i;
    Src_80348A9C *uv;
    E_803403F8 *v;
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

    self->calc_inner_rect((u8 *)rect);
    tex = TWindowDD::get_draw_count((void **)lbl_805D63F0);
    ((TWindowDD *)verts)->reset_entries(TWindowDD__sub_80348AD4(self->pad_54, 0.0f), -1);
    uv = TWindowDD__data_805434E8[6];
    s = rect->scale[1];
    v = verts;
    for (i = 0; i < 8; i++) {
        v->d = uv->x;
        v->e = uv->y;
        uv++;
        v++;
    }

    half = 0.5f * self->pad_4C;
    t = half * s;
    c = self->pad_44 + half;
    lo = c - t;
    hi = c + t;
    if (t < lbl_805DFB28) {
        d = (hi - lo) / 3.0f;
    } else {
        d = 16.0f;
    }
    verts[0].b = verts[1].b = lo;
    verts[2].b = verts[3].b = lo + d;
    verts[4].b = verts[5].b = hi - d;
    verts[6].b = verts[7].b = hi;

    half = 0.5f * self->pad_48;
    c = self->pad_40 + half;
    step = lbl_805DFB24 * rect->scale[0];
    t = half * rect->scale[0];
    x0 = span_start(c, t);
    v = verts;
    for (i = 0; i < 4; i++) {
        v[0].a = x0;
        v[1].a = x0 + step;
        v += 2;
    }
    half = 0.5f * lbl_805DFB38 * rect->scale[0];
    quad[0] = span_start(c, half);
    quad[2] = span_end(c, half);
    ((TWindowDD *)verts)->draw_transformed_primitive((void *)8, (void *)tex, (void *)1);

    z = TWindowDD__sub_80348AD4(self->pad_54, 0.1f);
    TObjFish::set_global_param(lbl_805D63F0);
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

}

void TWindowDD::init() { initialize_subwindow(); ((TWindowBase *)this)->update_fade(); }

void TWindowDD::set_value_f32(s32 arg1) {
    *(f32 *)&this->m_88 = (f32) arg1;
}

void TWindowDD::set_scale(s32 arg1, s32 arg2) {
    *(f32 *)&this->m_80 = (f32) arg1;
    *(f32 *)&this->m_84 = (f32) arg2;
    *(f32 *)&this->m_7c = (f32) (1.0f / *(f32 *)&this->m_80);
}

extern "C" {

void *dt__22TWindowDD_WS_ScrollBarFs(void *arg0, s16 arg1);
s32 draw_visible_window_entries(s32, s32, void *, f32);
int update_window_entry_list__11TWindowBaseFPv(void*, void*);
void __dl__7TObjectFPv(void *);
void *__nw__7TObjectFUl(int);
void *draw_default_entry__9TWindowDDFl();
int update_fade__11TWindowBaseFv(void*);

extern "C" void init__9TWindowDDFv();
extern "C" void render_shadows__7TObjectFv();
struct W_80340F00 { s32 f0; u8 pad4[0x14]; void *p18; u8 pad1c[0x5C - 0x1C]; s32 f5c; u8 pad60[4]; f32 f64; f32 f68; f32 f6c; };
extern s32 lbl_805D42D0;
__declspec(section ".data") void *lbl_804EFBC8[2] = {
    (void *)0x0, (void *)0x0,
};
void *lbl_804EFBD0[5] = {
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x3,
};
void *lbl_804EFBE4[7] = {
    (void *)0x0, (void *)0x0, (void *)&dt__22TWindowDD_WS_ScrollBarFs, (void *)&init__9TWindowDDFv,
    (void *)&TWindowDD__sub_80340A78, (void *)&render_shadows__7TObjectFv, (void *)0x0,
};

#define lbl_804EFBE4 ((s32 *)lbl_804EFBE4)
W_80340F00 *construct_variant_b__9TWindowDDFPv(W_80340F00 *arg0);

void *TWindowDD_WS_ScrollBar::dt(s16 arg1) {
    if (this != NULL) {
        *(s32 **)((s8 *)this + 0x18) = lbl_804EFBE4;
        ((TWindowDD *)this)->destroy_window_base(0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(this);
        }
    }
    return this;
}

W_80340F00 *construct_variant_b__9TWindowDDFPv(W_80340F00 *arg0) {
    ((TWindowDD *)arg0)->construct_base((u8 *)lbl_804EFBD0, (s16)4, (u8 *)lbl_804EFBC8);
    arg0->p18 = lbl_804EFBE4;
    arg0->f0 = lbl_805D42D0;
    arg0->f64 = 6.0f;
    arg0->f68 = 6.0f;
    arg0->f6c = 0.0f;
    arg0->f5c = 0x01000000;
    return arg0;
}

void *TWindowDD__sub_80340F70(void) {
    void *o = __nw__7TObjectFUl(0x70);
    if (o != NULL) {
        o = (void *)construct_variant_b__9TWindowDDFPv((W_80340F00 *)o);
    }
    return o;
}

extern const f32 TWindowDD__data_805DFB18;
extern const f32 lbl_805DFBCC;
extern const f32 lbl_805DFB34;
extern const f32 lbl_805DFB3C;
extern const f32 lbl_805DFB2C;
extern const f32 lbl_805DFB38;
extern const f32 lbl_805DFB30;
extern const f32 lbl_805DFBC4;
extern const f32 lbl_805DFBBC;
extern const f32 lbl_805DFBC8;
extern const f32 lbl_805DFBC0;
extern const f32 lbl_805DFC24;
extern f32 lbl_805D6DC0;
extern f32 lbl_805D6DC4;
f32 lbl_805D6DC8;
extern f32 lbl_805D6DCC;
extern f32 lbl_805D6DD0;
extern f32 lbl_805D6DD4;
extern f32 lbl_805D6DD8;
extern f32 lbl_805D6DDC;
extern f32 lbl_805D6DE0;
extern f32 lbl_805D6DE4;
extern f32 lbl_805D6DE8;
extern f32 lbl_805D6DEC;
extern f32 lbl_805D6DF0;
extern f32 lbl_805D6DF4;
extern f32 lbl_805D6DF8;
extern f32 lbl_805D6DFC;
extern f32 lbl_805D6E00;

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

}
