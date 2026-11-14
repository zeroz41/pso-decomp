#include "pso/ui/window/TWindowDD.h"
#include "pso/system/task/TObject.h"
#include "pso/ui/window/TUnk_804EFBAC.h"

#include "types.h"
#include "pso/ui/window/TWindowDD_803488A8.h"
#include "pso/ui/window/TWindowKeyBoardSoft.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/ui/window/TWindowSubStatusDisp_803DEE6C.h"

struct E_803403F8 { f32 a; f32 b; f32 c; f32 d; f32 e; s32 f; };

extern "C" {
extern const f32 TWindowDD__data_805DFBFC;
extern const f32 lbl_805DFC00;
extern const f32 lbl_805DFC04;
extern const f32 lbl_805DFC08;
extern const f32 lbl_805DFC2C;
void __dl__7TObjectFPv(void *);
void *__nw__7TObjectFUl(int);
}

extern "C" {

void TWindowDD__sub_803489B8(void *ctx, E_803403F8 *points, s32 row);
extern s32 lbl_805D63F0;
extern const f32 TWindowDD__data_805DFB20;
extern const f32 lbl_805DFB48;
extern const f32 lbl_805DFB4C;

struct Quad_8034055C { f32 x0, y0, x1, y1, u0, v0, u1, v1; };

void TWindowDD__sub_8034055C(TUnk_804EFBAC *self) {
    E_803403F8 points[8];
    Quad_8034055C q;
    s32 count;
    TWindowKeyBoardSoft *ctx;
    s32 sel;
    s32 i;
    f32 depth;
    f32 step;
    f32 dv;
    f32 h;
    u32 color;

    ctx = (TWindowKeyBoardSoft *)TWindowDD::draw_default_entry((s32)self);
    if (ctx->open_tick < 0) {
        return;
    }
    self->calc_inner_rect((u8 *)ctx);
    ((TWindowDD *)points)->reset_entries(TWindowDD__sub_80348AD4(self->pad_54, 0.0f), -1);
    ((TWindowDD *)points)->copy_point_table(0);
    TWindowDD__sub_80348A2C(ctx, points);
    TWindowDD__sub_803489B8(ctx, points, 0);
    count = TWindowDD::get_draw_count((void **)lbl_805D63F0);
    if (self->pad_60 == 0) {
        sel = self->pad_68;
    } else {
        sel = -1;
    }
    for (i = 0; i < 3; i++) {
        TWindowDD__sub_803489B8(ctx, points, i);
        if (i == sel) {
            ((TWindowDD *)points)->copy_point_table(1);
            ((TWindowDD *)points)->draw_transformed_primitive(8, count, 1);
            ((TWindowDD *)points)->copy_point_table(0);
        } else {
            ((TWindowDD *)points)->draw_transformed_primitive(8, count, 1);
        }
    }
    depth = TWindowDD__sub_80348AD4(self->pad_54, 0.2f);
    TWindowDD__sub_803489B8(ctx, points, 0);
    h = ctx->scale[1];
    step = TWindowDD__data_805DFB20 * h;
    dv = lbl_805DFB4C * lbl_805DFB48;
    q.x0 = points[0].a;
    q.x1 = points[7].a;
    q.y0 = points[0].b + h;
    q.y1 = points[7].b - h;
    q.u0 = 0.0f;
    q.u1 = 1.0f;
    q.v0 = q.u0;
    q.v1 = dv;
    TWindowSubStatusDisp::begin_render();
    begin_screen_draw(1);
    set_draw_texture_and_color(4, -1);
    for (s32 j = 0; j < 3; j++) {
        if (j == self->pad_68 && self->pad_60 == 0) {
            color = 0xFF000000;
        } else if (self->pad_64 <= j) {
            color = 0xFFFFFFFF;
        } else {
            color = 0xFF808080;
        }
        set_constant_material_color(color);
        draw_textured_quad_at_depth((f32 *)&q, depth);
        q.y0 += step;
        q.y1 += step;
        q.v0 = q.v1;
        q.v1 += dv;
    }
    TWindowSubStatusDisp::get_player();
}

void update_draw__9TWindowDDFPv(void *p) { ((TWindowDD *)p)->initialize_subwindow(); ((TWindowBase *)p)->update_fade(); }

void TWindowDD::set_clamped_page(s32 arg1) {
    if (arg1 < 0) {
        this->m_80 = 0;
        return;
    }
    if (arg1 >= 3) {
        this->m_80 = 2;
        return;
    }
    this->m_80 = arg1;
}

s32 TWindowDD__sub_80340820(void *p) { return ((TUnk_804EFBAC *)p)->pad_68; }

#pragma push
#pragma opt_common_subs off
void TWindowDD::handle_input() {
    u8 *arg0 = (u8 *)this;
    s32 temp_r0;
    s32 temp_r31;
    s32 temp_r3;
    temp_r31 = this->m_84;
    if (TWindowDD::apply_both_choices((s32)(arg0 + 0x60), 0x10) != 0) {
        this->m_84 = (this->m_84 - 1);
    } else if (TWindowDD::apply_both_choices((s32)(arg0 + 0x60), 0x20) != 0) {
        this->m_84 = (this->m_84 + 1);
    } else if (TWindowDD::apply_both_choices((s32)(arg0 + 0x60), 0x20000) != 0) {
        this->m_84 = 0;
    } else if (TWindowDD::apply_both_choices((s32)(arg0 + 0x60), 0x10000) != 0) {
        this->m_84 = 2;
    }
    temp_r0 = this->m_84;
    temp_r3 = this->m_80;
    if (temp_r0 < temp_r3) {
        this->m_84 = temp_r3;
    } else if (temp_r0 >= 3) {
        this->m_84 = 2;
    }
    if ((s32) this->m_84 != temp_r31) {
        TWindowDD::spawn_window();
    }
}
#pragma pop

void TWindowDD__sub_80340910(void *p) { ((TUnk_804EFBAC *)p)->pad_60 = 1; }

void render_shadows__7TObjectFv();
// Window placement read by TWindowBase::sub_80244F2C: position, depth, layout
// entry count and window flags.
struct TWindowPlacement { f32 x; f32 y; f32 depth; s32 entry_count; s32 flags; };

__declspec(section ".data") f32 TWindowDD__layout_constant_pair[2] = { TWindowDD__data_805DFBFC, lbl_805DFC00 };
TWindowPlacement TWindowDD__layout_constants = { lbl_805DFC04, lbl_805DFC08, lbl_805DFC2C, 0, 3 };
void *lbl_804EFBAC[7] = {
    (void *)0x0, (void *)0x0, (void *)&__dt__13TUnk_804EFBACFv, (void *)&update_draw__9TWindowDDFPv,
    (void *)&TWindowDD__sub_8034055C, (void *)&render_shadows__7TObjectFv, (void *)0x0,
};
#define lbl_804EFBAC ((s32 *)lbl_804EFBAC)

void TWindowDD::set_clamped_selection(s32 arg1) {
    s32 temp_r0;
    s32 var_r4;
    var_r4 = arg1;
    temp_r0 = this->m_80;
    if (var_r4 < temp_r0) {
        var_r4 = temp_r0;
    } else if (var_r4 >= 3) {
        var_r4 = 2;
    }
    this->m_84 = var_r4;
    this->m_7c = 0;
}

void *__dt__13TUnk_804EFBACFv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = lbl_804EFBAC;
        ((TWindowDD *)arg0)->destroy_window_base(0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

struct W_803409A4 { u8 pad0[0x18]; void *p18; u8 pad1c[0x5C - 0x1C]; s32 f5c; s32 f60; s32 f64; s32 f68; };

void *TWindowDD::construct_variant_a(void *arg0v) {
    W_803409A4 *w = (W_803409A4 *)arg0v;
    ((TWindowDD *)w)->construct_base((u8 *)&TWindowDD__layout_constants, (s16)4, (u8 *)TWindowDD__layout_constant_pair);
    w->p18 = lbl_804EFBAC;
    w->f60 = 1;
    w->f64 = 2;
    w->f68 = 2;
    w->f5c = 0x01000000;
    return w;
}

void *TWindowDD::create() {
    void *o = __nw__7TObjectFUl(0x6C);
    if (o != NULL) {
        o = TWindowDD::construct_variant_a(o);
    }
    return o;
}
}
