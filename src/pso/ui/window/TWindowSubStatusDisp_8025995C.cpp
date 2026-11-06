#include "types.h"
#include "pso/ui/window/TWindowSubStatusDisp_802598E4.h"
#include "pso/ui/window/TWindowKeyBoardSoft.h"
#include "pso/system/memory.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"

struct RecoveredGlobal_80259D3C_lbl_804CF9C8 {
    s32 value;
    u8 remaining[0x14];
};

struct Pos_80259A84
{
  f32 x;
  f32 y;
  u8 pad[0x18];
};

extern "C" {
void reset_entry__20TWindowSubStatusDispFPv(void*, int);
u8 get_font_char_advance();
s32 map_char_to_font_code(s32);
u8 get_small_font_glyph_width();
s32 TWindowSubStatusDisp__sub_800FC248(s32);
s32 build_small_font_glyph_quad(s32, Pos_80259A84 *);
s32 render_forward__20TWindowSubStatusDispFPv();
s32 set_glyph_quad_extents(s32, Pos_80259A84 *);
s32 calc_gauge_scale__20TWindowSubStatusDispFPvPvi(s32, Pos_80259A84 *, s32);
s32 end_render_forward__20TWindowSubStatusDispFPv();
s32 try_open__19TWindowKeyBoardSoftFii(void *, Pos_80259A84 *);
void begin_screen_draw(s32 arg0);
s32 draw_textured_quad_at_depth(Pos_80259A84 *, f32);
void set_draw_texture_and_color(s32 idx, s32 arg1);
extern s32 lbl_804CF9C8[];

void draw_right_aligned_number(void *arg0) {
    s32 n;
    n = *(s32 *)((s8 *)arg0 + 0x20);
    if (*(u16 *)((s8 *)arg0 + 0) & 4) {
        n /= 10;
        *(f32 *)((s8 *)arg0 + 0x10) = 10.0f;
        *(f32 *)((s8 *)arg0 + 0x14) = 13.0f;
        while (n > 0) {
            n /= 10;
            *(f32 *)((s8 *)arg0 + 0x10) += 10.0f;
        }
        return;
    }
    *(f32 *)((s8 *)arg0 + 0x14) = 18.0f;
    if (n <= 0) {
        map_char_to_font_code(0x30);
        *(f32 *)((s8 *)arg0 + 0x10) = get_font_char_advance();
        return;
    }
    *(f32 *)((s8 *)arg0 + 0x10) = 0.0f;
    while (n > 0) {
        map_char_to_font_code((u16)(n % 10) + 0x30);
        *(f32 *)((s8 *)arg0 + 0x10) += get_font_char_advance();
        n /= 10;
    }
}
}

void render_numeric_digit_entries(u8 *arg0, u8 *arg1);
typedef struct Pos_80259A84 Pos_80259A84;
#pragma fp_contract on
void render_numeric_digit_entries(u8 *arg0, u8 *window_key_board_soft) {
  f32 t;
  Pos_80259A84 pos;
  f32 x;
  f32 y;
  f32 scale;
  s32 n;
  s32 mode;
  s32 g;
  s32 r;
  u8 d;
  f32 w;
  f32 h;
  h = *((f32 *) (((s8 *) arg0) + 0xC));
  w = *((f32 *) (((s8 *) arg0) + 8));
  t = (h / 21.0f) + (w / (*((f32 *) (((s8 *) window_key_board_soft) + 0x18))));
  t *= 7.5f;
  t = 17.0f * (((f32) (*((s32 *) (((s8 *) window_key_board_soft) + 0x30)))) - t);
  if (t <= 0.0f)
  {
    return;
  }
  mode = ((*((u16 *) (((s8 *) arg0) + 0))) >> 2) & 1;
  n = *((s32 *) (((s8 *) arg0) + 0x20));
  x = (*((f32 *) (((s8 *) window_key_board_soft) + 0x10))) + w;
  y = (*((f32 *) (((s8 *) window_key_board_soft) + 0x14))) + h;
  scale = (-1.0f) / ((0.299f * (*((f32 *) (((s8 *) arg0) + 0x18)))) + (*((f32 *) (((s8 *) window_key_board_soft) + 0x38))));
  switch (mode)
  {
    case 0:
      TWindowSubStatusDisp::reset_gauge(0);
      window_key_board_soft = window_key_board_soft;
      break;
    case 1:
      begin_screen_draw(1);
      render_forward__20TWindowSubStatusDispFPv();
      set_draw_texture_and_color(0, *((s32 *) (((s8 *) arg0) + 0x1C)));
      break;
  }
  do
  {
    if (n < 0)
    {
      n = 0;
    }
    d = n % 10;
    switch (mode)
    {
      if (1)
      {
        case 0:
          r = calc_gauge_scale__20TWindowSubStatusDispFPvPvi(((u8 (*)(u16)) map_char_to_font_code)(d + 0x30), &pos, *((s32 *) (((s8 *) arg0) + 0x1C)));
          pos.y = y;
          x -= (u8) r;
          pos.x = x;
          set_glyph_quad_extents(r, &pos);
          break;
      }
      case 1:
        g = TWindowSubStatusDisp__sub_800FC248(d + 0x30);
        x -= get_small_font_glyph_width();
        pos.y = y;
        pos.x = x;
        build_small_font_glyph_quad(g, &pos);
        break;
    }
    if (try_open__19TWindowKeyBoardSoftFii(window_key_board_soft, &pos) != 0)
    {
      draw_textured_quad_at_depth(&pos, scale);
    }
  }
  while ((n /= 10) > 0);
  switch (mode)
  {
    case 0:
      end_render_forward__20TWindowSubStatusDispFPv();
      break;
    case 1:
      TWindowSubStatusDisp::get_player();
      break;
  }
}

void TWindowSubStatusDisp__sub_80259CE0(void) {  }

void *TWindowSubStatusDisp__sub_80259CE4(void *window_sub_status_disp, s16 arg1) {
    if (window_sub_status_disp != NULL) {
        *(s32 **)((s8 *)window_sub_status_disp + 4) = lbl_804CF9C8;
        ((TWindowSubStatusDisp *)window_sub_status_disp)->deleting_destructor(0);
        if (arg1 > 0) {
            ::operator delete(window_sub_status_disp);
        }
    }
    return window_sub_status_disp;
}

typedef char RecoveredGlobal_80259D3C_lbl_804CF9C8_size[sizeof(RecoveredGlobal_80259D3C_lbl_804CF9C8) == 0x18 ? 1 : -1];
u8 *TWindowSubStatusDisp__sub_80259D3C(u8 *arg0, u8 *arg1, s32 arg2) {
    reset_entry__20TWindowSubStatusDispFPv(arg0, arg2);
    *(s32 **)((s8 *)arg0 + 4) = &(*(RecoveredGlobal_80259D3C_lbl_804CF9C8 *)&lbl_804CF9C8).value;
    *(f32 *)((s8 *)arg0 + 8) = (f32) *(f32 *)((s8 *)arg1 + 4);
    *(f32 *)((s8 *)arg0 + 0xC) = (f32) *(f32 *)((s8 *)arg1 + 8);
    *(f32 *)((s8 *)arg0 + 0x18) = (f32) *(f32 *)((s8 *)arg1 + 0xC);
    *(s16 *)((s8 *)arg0 + 0) = (s16) *(s32 *)((s8 *)arg1 + 0x14);
    *(s32 *)((s8 *)arg0 + 0x1C) = (s32) *(s32 *)((s8 *)arg1 + 0x10);
    *(s32 *)((s8 *)arg0 + 0x20) = (s32) *(s32 *)((s8 *)arg1 + 0x18);
    return arg0;
}
