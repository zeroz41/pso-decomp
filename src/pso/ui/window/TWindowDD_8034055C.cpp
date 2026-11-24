#include "pso/ui/window/TWindowCtrlMain_8024674C.h"
#include "pso/ui/window/WindowVertexBufferAbi.h"
#pragma defer_codegen on
#include "pso/ui/window/TWindowDD.h"
#include "pso/system/task/TObject.h"
#include "pso/ui/window/TWindowWordSelectMode.h"

#include "types.h"
#include "pso/ui/window/TWindowDD_803488A8.h"
#include "pso/ui/window/WindowDrawContext.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/ui/window/TWindowSubStatusDisp_803DEE6C.h"


extern "C" {
extern const f32 TWindowDD__data_805DFBFC;
extern const f32 lbl_805DFC00;
extern const f32 lbl_805DFC04;
extern const f32 lbl_805DFC08;
extern const f32 lbl_805DFC2C;
extern const f32 TWindowDD__data_805DFB20;
extern const f32 lbl_805DFB48;
extern const f32 lbl_805DFB4C;

struct Quad_8034055C { f32 x0, y0, x1, y1, u0, v0, u1, v1; };

struct TWindowPlacement { f32 x; f32 y; f32 depth; s32 entry_count; s32 flags; };

__declspec(section ".data") f32 TWindowDD__layout_constant_pair[2] = { TWindowDD__data_805DFBFC, lbl_805DFC00 };
TWindowPlacement TWindowDD__layout_constants = { lbl_805DFC04, lbl_805DFC08, lbl_805DFC2C, 0, 3 };

void *TWindowDD::create() { return new TWindowWordSelectMode; }

TWindowWordSelectMode::TWindowWordSelectMode()
    : TWindowBase((u8 *)&TWindowDD__layout_constants, 4, (u8 *)TWindowDD__layout_constant_pair) {
    pad_60 = 1;
    pad_64 = 2;
    pad_68 = 2;
    open_tick = 0x01000000;
}

TWindowWordSelectMode::~TWindowWordSelectMode() {}

void TWindowDD::set_clamped_selection(s32 clamped_selection) {
    s32 temp_r0;
    s32 var_r4;
    var_r4 = clamped_selection;
    temp_r0 = this->m_64[0];
    if (var_r4 < temp_r0) {
        var_r4 = temp_r0;
    } else if (var_r4 >= 3) {
        var_r4 = 2;
    }
    this->m_64[1] = var_r4;
    this->m_44[7] = 0;
}

void TWindowDD__sub_80340910(void *p) { ((TWindowWordSelectMode *)p)->pad_60 = 1; }

#pragma push
#pragma opt_common_subs off
void TWindowDD::handle_input() {
    u8 *arg0 = (u8 *)this;
    s32 temp_r0;
    s32 temp_r31;
    s32 temp_r3;
    temp_r31 = this->m_64[1];
    if (TWindowDD::apply_both_choices((saddr)(arg0 + 0x60), 0x10) != 0) {
        this->m_64[1] = (this->m_64[1] - 1);
    } else if (TWindowDD::apply_both_choices((saddr)(arg0 + 0x60), 0x20) != 0) {
        this->m_64[1] = (this->m_64[1] + 1);
    } else if (TWindowDD::apply_both_choices((saddr)(arg0 + 0x60), 0x20000) != 0) {
        this->m_64[1] = 0;
    } else if (TWindowDD::apply_both_choices((saddr)(arg0 + 0x60), 0x10000) != 0) {
        this->m_64[1] = 2;
    }
    temp_r0 = this->m_64[1];
    temp_r3 = this->m_64[0];
    if (temp_r0 < temp_r3) {
        this->m_64[1] = temp_r3;
    } else if (temp_r0 >= 3) {
        this->m_64[1] = 2;
    }
    if ((s32) this->m_64[1] != temp_r31) {
        TWindowDD::spawn_window();
    }
}
#pragma pop

s32 TWindowDD__sub_80340820(void *p) { return ((TWindowWordSelectMode *)p)->pad_68; }

void TWindowDD::set_clamped_page(s32 clamped_page) {
    if (clamped_page < 0) {
        this->m_64[0] = 0;
        return;
    }
    if (clamped_page >= 3) {
        this->m_64[0] = 2;
        return;
    }
    this->m_64[0] = clamped_page;
}

void TWindowWordSelectMode::run_task() {
    ((TWindowDD *)this)->initialize_subwindow();
    update_fade();
}

void TWindowWordSelectMode::render() {
    WindowVertex points[8];
    Quad_8034055C q;
    s32 count;
    WindowDrawContext *ctx;
    s32 sel;
    s32 i;
    f32 depth;
    f32 step;
    f32 dv;
    f32 h;
    u32 color;

    ctx = this->draw_default_entry();
    if (ctx->open_tick < 0) {
        return;
    }
    this->calc_inner_rect(ctx);
    ((TWindowDD *)points)->reset_entries(TWindowDD__sub_80348AD4(this->draw_depth, 0.0f), -1);
    ((TWindowDD *)points)->copy_point_table(0);
    TWindowDD__sub_80348A2C(ctx, points);
    TWindowDD__sub_803489B8(ctx, points, 0);
    count = TWindowDD::get_draw_count(hud_texlist);
    if (this->pad_60 == 0) {
        sel = this->pad_68;
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
    depth = TWindowDD__sub_80348AD4(this->draw_depth, 0.2f);
    TWindowDD__sub_803489B8(ctx, points, 0);
    h = ctx->scale[1];
    step = TWindowDD__data_805DFB20 * h;
    dv = lbl_805DFB4C * lbl_805DFB48;
    q.x0 = points[0].x;
    q.x1 = points[7].x;
    q.y0 = points[0].y + h;
    q.y1 = points[7].y - h;
    q.u0 = 0.0f;
    q.u1 = 1.0f;
    q.v0 = q.u0;
    q.v1 = dv;
    TWindowSubStatusDisp::begin_render();
    begin_screen_draw(1);
    set_draw_texture_and_color(4, -1);
    for (s32 j = 0; j < 3; j++) {
        if (j == this->pad_68 && this->pad_60 == 0) {
            color = 0xFF000000;
        } else if (this->pad_64 <= j) {
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
}
