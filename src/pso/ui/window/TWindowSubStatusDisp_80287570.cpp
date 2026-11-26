#include "pso/ui/window/TWindowCtrlMain_8024674C.h"
#include "types.h"
#include "pso/ui/window/WindowDrawContext.h"
#include "pso/ui/window/TWindowSubStatusDisp_80287570.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/ui/window/TWindowSubStatusDisp_8024FBA8.h"
#include "pso/ui/window/TWindowSubStatusDisp_803DEE6C.h"
#include "pso/system/NinjaTypes.h"
#include "pso/ui/window/TWindowSubStatusDisp_80144B14.h"

struct WindowTabUV {
    f32 u, v;
};

const WindowTabUV window_tab_uv_table[4] = {{0.0f, 98.0f}, {0.0f, 125.0f}, {0.0f, 152.0f}, {80.0f, 98.0f}};

f32 get_heading_frame_width(HeadingEntry *heading) {
    return (1.6e+02f) + heading->width;
}

void draw_window_tab(WindowDrawContext *context, f32 *pos, f32 width, u8 idx) {
    TexturedQuad r3;
    TexturedQuad r2;
    TexturedQuad r1;
    f32 scale;
    f32 w;
    scale = -1.0f / (0.0299f + context->depth);
    w = width;
    w += (8e+01f);
    begin_screen_draw(1);
    TObjFish::set_global_param(hud_texlist);
    set_draw_texture_and_color(1, context->color);
    r1.x0 = pos[0];
    r1.y0 = pos[1];
    r1.x1 = 40.0f + pos[0];
    r1.y1 = 27.0f + pos[1];
    r1.u0 = window_tab_uv_table[idx].u / 256.0f;
    r1.v0 = window_tab_uv_table[idx].v / 256.0f;
    r1.u1 = (40.0f + window_tab_uv_table[idx].u) / 256.0f;
    r1.v1 = (27.0f + window_tab_uv_table[idx].v) / 256.0f;
    context->transform_quad(&r1);
    draw_textured_quad_at_depth((f32 *)&r1, scale);
    r2.x0 = 40.0f + pos[0];
    r2.y0 = pos[1];
    r2.x1 = r2.x0 + w;
    r2.y1 = 27.0f + pos[1];
    r2.u0 = ((40.0f + window_tab_uv_table[idx].u) - 20.0f) / 256.0f;
    r2.v0 = window_tab_uv_table[idx].v / 256.0f;
    r2.u1 = (20.0f + (40.0f + window_tab_uv_table[idx].u)) / 256.0f;
    r2.v1 = (27.0f + window_tab_uv_table[idx].v) / 256.0f;
    context->transform_quad(&r2);
    draw_textured_quad_at_depth((f32 *)&r2, scale);
    r3.x0 = 40.0f + (pos[0] + w);
    r3.y0 = pos[1];
    r3.x1 = 40.0f + r3.x0;
    r3.y1 = 27.0f + pos[1];
    r3.u0 = (40.0f + window_tab_uv_table[idx].u) / 256.0f;
    r3.v0 = window_tab_uv_table[idx].v / 256.0f;
    r3.u1 = (80.0f + window_tab_uv_table[idx].u) / 256.0f;
    r3.v1 = (27.0f + window_tab_uv_table[idx].v) / 256.0f;
    context->transform_quad(&r3);
    draw_textured_quad_at_depth((f32 *)&r3, scale);
    end_screen_draw();
}

f32 TWindowSubStatusDisp::get_base_y(f32 width) {
    return (1.6e+02f) + width;
}

f32 calc_title_overflow_width(f32 text_width) {
    f32 extra = (16.0f + text_width) - 160.0f;
    if (extra < 0.0f) {
        extra = 0.0f;
    }
    return extra;
}

void HeadingEntry::update_color() {
    switch (state) {
    case 0:
        if (is_enabled() != 0) {
            color = 0xFFFFFFFF;
        } else {
            color = 0xFF909090;
        }
        break;
    case 1:
    case 2:
        color = 0xFF000000;
        break;
    }
}

void HeadingEntry::set_state(s8 entry_state) {
    state = entry_state;
    update_color();
}

#pragma fp_contract on

void HeadingEntry::draw_tab(WindowDrawContext *context) {
    f32 pos[2];
    pos[0] = context->x + x;
    pos[1] = context->y + y;
    draw_window_tab(context, pos, width, state);
}

void draw_heading_text(HeadingEntry *heading, WindowDrawContext *context) {
  NJS_POINT2 pos;
  if (context->open_tick >= 0)
  {
    pos.x = -((0.5f * heading->text_width) - ((0.5f * (1.6e+02f + heading->width)) + (context->x + heading->x)));
    pos.y = 4.0f + (context->y + heading->y);
    set_text_draw_params(context, 0, 1, (f32) (-1.0f / (0.0598f + context->depth)), 100000.0f);
    draw_window_text(&pos.x, (const char *)heading->text, heading->color, 1, heading->reveal_pos);
  }
}

void HeadingEntry::draw(WindowDrawContext *context) {
    draw_tab(context);
    draw_heading_text(this, context);
}

void HeadingEntry::advance_reveal() {
    reveal_pos = reveal_pos + reveal_step;
}

HeadingEntry::~HeadingEntry() {}

HeadingEntry::HeadingEntry(f32 *position, saddr title, s8 entry_state, s32 client_id) {
    x = position[0];
    y = position[1];
    text_width = calc_text_width((char *)title);
    width = calc_title_overflow_width(text_width);
    text = title;
    flags = 0;
    reveal_pos = 0.0f;
    set_state(entry_state);
    reveal_step = TWindowSubStatusDisp::get_card_window_scale(client_id);
    if (reveal_step <= 0.0f) {
        reveal_pos = 1e+05f;
    }
}

s32 HeadingEntry::is_enabled() {
    return !(flags & 1);
}
