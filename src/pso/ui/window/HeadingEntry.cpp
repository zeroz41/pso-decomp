#include "pso/ui/window/TWindowBase.h"
#include "types.h"
#include "pso/ui/window/WindowDrawContext.h"
#include "pso/ui/window/HeadingEntry.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/render/TextureState.h"
#include "pso/ui/window/WindowTextDraw.h"
#include "pso/ui/window/ScreenQuadDraw.h"
#include "pso/system/NinjaTypes.h"
#include "pso/ui/font/MenuFontGlyphs.h"

const WindowTabUV window_tab_uv_table[4] = {{0.0f, 98.0f}, {0.0f, 125.0f}, {0.0f, 152.0f}, {80.0f, 98.0f}};

f32 get_heading_frame_width(HeadingEntry *heading) {
    return (1.6e+02f) + heading->width;
}

void draw_window_tab(WindowDrawContext *context, f32 *pos, f32 width, u8 idx) {
    TexturedQuad right_cap;
    TexturedQuad middle;
    TexturedQuad left_cap;
    f32 scale;
    f32 w;
    scale = -1.0f / (0.0299f + context->depth);
    w = width;
    w += (8e+01f);
    begin_screen_draw(1);
    set_texture_list(hud_texlist);
    set_draw_texture_and_color(1, context->color);
    left_cap.x0 = pos[0];
    left_cap.y0 = pos[1];
    left_cap.x1 = 40.0f + pos[0];
    left_cap.y1 = 27.0f + pos[1];
    left_cap.u0 = window_tab_uv_table[idx].u / 256.0f;
    left_cap.v0 = window_tab_uv_table[idx].v / 256.0f;
    left_cap.u1 = (40.0f + window_tab_uv_table[idx].u) / 256.0f;
    left_cap.v1 = (27.0f + window_tab_uv_table[idx].v) / 256.0f;
    context->transform_quad(&left_cap);
    draw_textured_quad_at_depth(&left_cap.x0, scale);
    middle.x0 = 40.0f + pos[0];
    middle.y0 = pos[1];
    middle.x1 = middle.x0 + w;
    middle.y1 = 27.0f + pos[1];
    middle.u0 = ((40.0f + window_tab_uv_table[idx].u) - 20.0f) / 256.0f;
    middle.v0 = window_tab_uv_table[idx].v / 256.0f;
    middle.u1 = (20.0f + (40.0f + window_tab_uv_table[idx].u)) / 256.0f;
    middle.v1 = (27.0f + window_tab_uv_table[idx].v) / 256.0f;
    context->transform_quad(&middle);
    draw_textured_quad_at_depth(&middle.x0, scale);
    right_cap.x0 = 40.0f + (pos[0] + w);
    right_cap.y0 = pos[1];
    right_cap.x1 = 40.0f + right_cap.x0;
    right_cap.y1 = 27.0f + pos[1];
    right_cap.u0 = (40.0f + window_tab_uv_table[idx].u) / 256.0f;
    right_cap.v0 = window_tab_uv_table[idx].v / 256.0f;
    right_cap.u1 = (80.0f + window_tab_uv_table[idx].u) / 256.0f;
    right_cap.v1 = (27.0f + window_tab_uv_table[idx].v) / 256.0f;
    context->transform_quad(&right_cap);
    draw_textured_quad_at_depth(&right_cap.x0, scale);
    end_screen_draw();
}

f32 get_base_y(f32 width) {
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

HeadingEntry::HeadingEntry(f32 *position, const char *title, s8 entry_state, s32 client_id) {
    x = position[0];
    y = position[1];
    text_width = calc_text_width(title);
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
