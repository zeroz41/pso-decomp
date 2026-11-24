#include "pso/ui/window/TWindowCtrlMain_8024674C.h"
#include "types.h"
#include "pso/ui/window/WindowDrawContext.h"
#include "pso/ui/window/TWindowSubStatusDisp_80287570.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/ui/window/TWindowSubStatusDisp_8024FBA8.h"
#include "pso/ui/window/TWindowSubStatusDisp_803DEE6C.h"
#include "pso/system/NinjaTypes.h"

typedef struct Entry_802877C8 {
    u8 pad0[0x14];
    u32 color;
    u8 state;
} Entry_802877C8;

typedef struct Entry_80287860 {
    u8 pad0[4];
    f32 x;
    f32 y;
    f32 width;
    u8 pad10[8];
    u8 state;
} Entry_80287860;

typedef struct UV_80287580 {
    f32 u, v;
} UV_80287580;

extern "C" {
u32 calc_text_width(char *s);
const UV_80287580 window_tab_uv_table[4] = {{0.0f, 98.0f}, {0.0f, 125.0f}, {0.0f, 152.0f}, {80.0f, 98.0f}};
void __dl__FPv(void);

f32 TWindowSubStatusDisp__sub_80287570(void *arg0) {
    return (1.6e+02f) + *(f32 *)((s8 *)arg0 + 0xC);
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

f32 TWindowSubStatusDisp__sub_802877A4(f32 farg0) {
  float new_var;
  f32 temp_f1;
  f32 temp_f2;
  f32 temp_f0;
  temp_f0 = (16.0f);
  temp_f1 = (1.6e+02f);
  temp_f2 = temp_f1;
  new_var = temp_f0 + farg0;
  temp_f1 = new_var;
  temp_f0 = (0.0f);
  temp_f1 = temp_f1 - temp_f2;
  if (temp_f1 < temp_f0)
  {
    temp_f1 = temp_f0;
  }
  return temp_f1;
}

void TWindowSubStatusDisp::update_entry_color() {
    Entry_802877C8 *e = (Entry_802877C8 *)this;
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
    *(s8 *)((s8 *)this + 0x18) = entry_state;
    update_entry_color();
}

#pragma fp_contract on

void TWindowSubStatusDisp::draw_entry_tab(void *arg1) {
    Entry_80287860 *e = (Entry_80287860 *)this;
    f32 pos[2];
    pos[0] = ((f32 *)arg1)[0] + e->x;
    pos[1] = ((f32 *)arg1)[1] + e->y;
    ((void (*)(f32, WindowDrawContext *, f32 *, u8))draw_window_tab)(e->width, (WindowDrawContext *)arg1, pos, e->state);
}

void TWindowSubStatusDisp__sub_802878B8(u8 *arg0, u8 *arg1) {
  NJS_POINT2 pos;
  if (((s32) (*((s32 *) (((s8 *) arg1) + 0x30)))) >= 0)
  {
    pos.x = -(((0.5f) * (*((f32 *) (((s8 *) arg0) + 0x10)))) - (((0.5f) * ((1.6e+02f) + (*((f32 *) (((s8 *) arg0) + 0xC))))) + ((*((f32 *) (((s8 *) arg1) + 0))) + (*((f32 *) (((s8 *) arg0) + 4))))));
    pos.y = (4.0f) + (*((f32 *) (((s8 *) arg1) + 4)) + (*((f32 *) (((s8 *) arg0) + 8))));
    set_text_draw_params(reinterpret_cast<WindowDrawContext *>(arg1), 0, 1, (f32) ((-1.0f) / ((0.0598f) + (*((f32 *) (((s8 *) arg1) + 0x38))))), 100000.0f);
    draw_window_text(&pos.x, (const char *)(*((saddr *) (((s8 *) arg0) + 0))), (*((s32 *) (((s8 *) arg0) + 0x14))), 1, *((f32 *) (((s8 *) arg0) + 0x1C)));
  }
}

void TWindowSubStatusDisp::update(void* a1) { draw_entry_tab((void *)a1); TWindowSubStatusDisp__sub_802878B8((u8 *)this, (u8 *)a1); }

void TWindowSubStatusDisp__sub_802879B0(void *arg0) {
    *(f32 *)((s8 *)arg0 + 0x1C) = (f32) (*(f32 *)((s8 *)arg0 + 0x1C) + *(f32 *)((s8 *)arg0 + 0x20));
}

s32 TWindowSubStatusDisp::deleting_destructor(s32 arg0, s16 arg1) {
    if ((arg0 != 0) && (arg1 > 0)) {
        __dl__FPv();
    }
    return arg0;
}

u8 *init_heading_entry__20TWindowSubStatusDispFPvPvici(u8 *window_sub_status_disp, u8 *arg1, saddr title, s8 entry_state, s32 client_id) {
    *(f32 *)((s8 *)window_sub_status_disp + 4) = (f32) *(f32 *)((s8 *)arg1 + 0);
    *(f32 *)((s8 *)window_sub_status_disp + 8) = (f32) *(f32 *)((s8 *)arg1 + 4);
    *(f32 *)((s8 *)window_sub_status_disp + 0x10) = (f32) calc_text_width((char *)(title));
    *(f32 *)((s8 *)window_sub_status_disp + 0xC) = TWindowSubStatusDisp__sub_802877A4(*(f32 *)((s8 *)window_sub_status_disp + 0x10));
    *(s32 *)((s8 *)window_sub_status_disp + 0) = title;
    *(s8 *)((s8 *)window_sub_status_disp + 0x19) = 0;
    *(f32 *)((s8 *)window_sub_status_disp + 0x1C) = (f32) (0.0f);
    ((TWindowSubStatusDisp *)window_sub_status_disp)->set_entry_state(entry_state);
    *(f32 *)((s8 *)window_sub_status_disp + 0x20) = TWindowSubStatusDisp::get_card_window_scale(client_id);
    if (*(f32 *)((s8 *)window_sub_status_disp + 0x20) <= (0.0f)) {
        *(f32 *)((s8 *)window_sub_status_disp + 0x1C) = (f32) (1e+05f);
    }
    return window_sub_status_disp;
}

u8 TWindowSubStatusDisp__sub_80287AC4(u8 *arg0) {
    return (u8) ((u32) __cntlzw(*(u8 *)((s8 *)arg0 + 0x19) & 1) >> 5);
}
}
