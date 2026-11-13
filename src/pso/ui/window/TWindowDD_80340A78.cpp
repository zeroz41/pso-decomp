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
    x0 = c - t;
    v = verts;
    for (i = 0; i < 4; i++) {
        v[0].a = x0;
        v[1].a = x0 + step;
        v += 2;
    }
    half = 0.5f * lbl_805DFB38 * rect->scale[0];
    quad[0] = c - half;
    quad[2] = c + half;
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

extern const f32 lbl_805DFC6C;
}

void TWindowDD::init() { initialize_subwindow(); ((TWindowBase *)this)->update_fade(); }

void TWindowDD::set_value_f32(s32 arg1) {
    *(f32 *)&this->m_88 = (f32) arg1;
}

void TWindowDD::set_scale(s32 arg1, s32 arg2) {
    *(f32 *)&this->m_80 = (f32) arg1;
    *(f32 *)&this->m_84 = (f32) arg2;
    *(f32 *)&this->m_7c = (f32) (lbl_805DFC6C / *(f32 *)&this->m_80);
}
