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




struct TWindowPlacement { f32 x; f32 y; f32 depth; s32 entry_count; s32 flags; };

__declspec(section ".data") f32 TWindowDD__layout_constant_pair[2] = { mode_window_x, mode_window_y };
TWindowPlacement TWindowDD__layout_constants = { mode_window_placement_x, mode_window_placement_y, mode_window_depth, 0, 3 };

TWindowWordSelectMode *TWindowWordSelectMode::create() { return new TWindowWordSelectMode; }

TWindowWordSelectMode::TWindowWordSelectMode()
    : TWindowBase((u8 *)&TWindowDD__layout_constants, 4, (u8 *)TWindowDD__layout_constant_pair) {
    highlight_hidden = 1;
    grey_row_count = 2;
    selected_row = 2;
    open_tick = 0x01000000;
}

TWindowWordSelectMode::~TWindowWordSelectMode() {}

void TWindowWordSelectMode::set_clamped_selection(s32 clamped_selection) {
    if (clamped_selection < grey_row_count) {
        clamped_selection = grey_row_count;
    } else if (clamped_selection >= 3) {
        clamped_selection = 2;
    }
    selected_row = clamped_selection;
    highlight_hidden = 0;
}

void TWindowWordSelectMode::hide_selection() { highlight_hidden = 1; }

#pragma push
#pragma opt_common_subs off
void TWindowWordSelectMode::handle_input() {
    s32 previous_row = selected_row;
    if (TWindowDD::apply_both_choices(&highlight_hidden, 0x10) != 0) {
        selected_row--;
    } else if (TWindowDD::apply_both_choices(&highlight_hidden, 0x20) != 0) {
        selected_row++;
    } else if (TWindowDD::apply_both_choices(&highlight_hidden, 0x20000) != 0) {
        selected_row = 0;
    } else if (TWindowDD::apply_both_choices(&highlight_hidden, 0x10000) != 0) {
        selected_row = 2;
    }
    s32 row = selected_row;
    s32 min_row = grey_row_count;
    if (row < min_row) {
        selected_row = min_row;
    } else if (row >= 3) {
        selected_row = 2;
    }
    if (selected_row != previous_row) {
        TWindowDD::spawn_window();
    }
}
#pragma pop

s32 TWindowWordSelectMode::get_selected_row() { return selected_row; }

void TWindowWordSelectMode::set_clamped_page(s32 clamped_page) {
    if (clamped_page < 0) {
        grey_row_count = 0;
        return;
    }
    if (clamped_page >= 3) {
        grey_row_count = 2;
        return;
    }
    grey_row_count = clamped_page;
}

void TWindowWordSelectMode::run_task() {
    update_window();
    update_fade();
}

void TWindowWordSelectMode::render() {
    WindowVertex points[8];
    TexturedQuad q;
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
    reset_window_vertices(points, word_select_inverse_depth(this->draw_depth, 0.0f), -1);
    copy_window_point_table(points, 0);
    TWindowDD__sub_80348A2C(ctx, points);
    TWindowDD__sub_803489B8(ctx, points, 0);
    count = TWindowDD::get_draw_count(hud_texlist);
    if (this->highlight_hidden == 0) {
        sel = this->selected_row;
    } else {
        sel = -1;
    }
    for (i = 0; i < 3; i++) {
        TWindowDD__sub_803489B8(ctx, points, i);
        if (i == sel) {
            copy_window_point_table(points, 1);
            draw_window_vertices(points, 8, count, 1);
            copy_window_point_table(points, 0);
        } else {
            draw_window_vertices(points, 8, count, 1);
        }
    }
    depth = word_select_inverse_depth(this->draw_depth, 0.2f);
    TWindowDD__sub_803489B8(ctx, points, 0);
    h = ctx->scale[1];
    step = window_dd_row_height * h;
    dv = mode_row_texture_height * mode_texel_scale;
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
        if (j == this->selected_row && this->highlight_hidden == 0) {
            color = 0xFF000000;
        } else if (this->grey_row_count <= j) {
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
    end_screen_draw();
}
