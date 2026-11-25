#include "pso/ui/window/TWindowCtrlMain_8024674C.h"
#include "types.h"
#include "pso/ui/window/WindowDrawContext.h"
#include "pso/ui/window/TWindowSubStatusDisp_80287570.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/ui/window/TWindowSubStatusDisp_8024FBA8.h"
#include "pso/ui/window/TWindowSubStatusDisp_803DEE6C.h"
#include "pso/system/NinjaTypes.h"

// A heading line of a window (text, position, width) that reveals its text over time.
struct HeadingEntry {
    saddr text;
    f32 x;
    f32 y;
    f32 width;
    f32 text_width;
    u32 color;
    u8 state;
    u8 flags;
    u8 pad_1A[2];
    f32 reveal_pos;
    f32 reveal_step;
};

typedef struct UV_80287580 {
    f32 u, v;
} UV_80287580;

extern "C" {
u32 calc_text_width(char *s);
const UV_80287580 window_tab_uv_table[4] = {{0.0f, 98.0f}, {0.0f, 125.0f}, {0.0f, 152.0f}, {80.0f, 98.0f}};
void __dl__FPv(void);

f32 TWindowSubStatusDisp__sub_80287570(void *heading) {
    return (1.6e+02f) + ((HeadingEntry *)heading)->width;
}

void draw_window_tab(WindowDrawContext *context, f32 *pos, u8 idx, f32 width) {
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
    TWindowSubStatusDisp::get_player();
}

f32 TWindowSubStatusDisp::get_base_y(f32 width) {
    return (1.6e+02f) + width;
}

f32 TWindowSubStatusDisp__sub_802877A4(f32 text_width) {
    f32 extra = (16.0f + text_width) - 160.0f;
    if (extra < 0.0f) {
        extra = 0.0f;
    }
    return extra;
}

void TWindowSubStatusDisp::update_entry_color() {
    HeadingEntry *e = (HeadingEntry *)this;
    switch (e->state) {
    case 0:
        if (((s32 (*)(u8 *))TWindowSubStatusDisp__sub_80287AC4)((u8 *)e) != 0) {
            e->color = 0xFFFFFFFF;
        } else {
            e->color = 0xFF909090;
        }
        break;
    case 1:
    case 2:
        e->color = 0xFF000000;
        break;
    }
}

void TWindowSubStatusDisp::set_entry_state(s8 entry_state) {
    ((HeadingEntry *)this)->state = entry_state;
    update_entry_color();
}

#pragma fp_contract on

void TWindowSubStatusDisp::draw_entry_tab(void *context) {
    HeadingEntry *e = (HeadingEntry *)this;
    f32 pos[2];
    pos[0] = ((f32 *)context)[0] + e->x;
    pos[1] = ((f32 *)context)[1] + e->y;
    ((void (*)(f32, WindowDrawContext *, f32 *, u8))draw_window_tab)(e->width, (WindowDrawContext *)context, pos, e->state);
}

void TWindowSubStatusDisp__sub_802878B8(HeadingEntry *heading, WindowDrawContext *context) {
  NJS_POINT2 pos;
  if (context->open_tick >= 0)
  {
    pos.x = -((0.5f * heading->text_width) - ((0.5f * (1.6e+02f + heading->width)) + (context->x + heading->x)));
    pos.y = 4.0f + (context->y + heading->y);
    set_text_draw_params(context, 0, 1, (f32) (-1.0f / (0.0598f + context->depth)), 100000.0f);
    draw_window_text(&pos.x, (const char *)heading->text, heading->color, 1, heading->reveal_pos);
  }
}

void TWindowSubStatusDisp::update(void* a1) { draw_entry_tab(a1); TWindowSubStatusDisp__sub_802878B8((HeadingEntry *)this, (WindowDrawContext *)a1); }

void TWindowSubStatusDisp__sub_802879B0(void *heading) {
    HeadingEntry *e = (HeadingEntry *)heading;
    e->reveal_pos = (f32) (e->reveal_pos + e->reveal_step);
}

s32 TWindowSubStatusDisp::deleting_destructor(s32 object, s16 delete_flag) {
    if ((object != 0) && (delete_flag > 0)) {
        __dl__FPv();
    }
    return object;
}

u8 *init_heading_entry__20TWindowSubStatusDispFPvPvici(u8 *window_sub_status_disp, u8 *position, saddr title, s8 entry_state, s32 client_id) {
    HeadingEntry *e = (HeadingEntry *)window_sub_status_disp;
    e->x = (f32) *(f32 *)((s8 *)position + 0);
    e->y = (f32) *(f32 *)((s8 *)position + 4);
    e->text_width = (f32) calc_text_width((char *)(title));
    e->width = TWindowSubStatusDisp__sub_802877A4(e->text_width);
    e->text = title;
    e->flags = 0;
    e->reveal_pos = (f32) (0.0f);
    ((TWindowSubStatusDisp *)window_sub_status_disp)->set_entry_state(entry_state);
    e->reveal_step = TWindowSubStatusDisp::get_card_window_scale(client_id);
    if (e->reveal_step <= (0.0f)) {
        e->reveal_pos = (f32) (1e+05f);
    }
    return window_sub_status_disp;
}

u8 TWindowSubStatusDisp__sub_80287AC4(u8 *heading) {
    return (u8) ((u32) __cntlzw(((HeadingEntry *)heading)->flags & 1) >> 5);
}
}
