#include "types.h"
#include "pso/unk/TUnk_804CF9C8.h"
#include "pso/ui/window/TWindowSubStatusDisp_8025995C.h"
#include "pso/ui/window/TWindowSubStatusDisp_802598E4.h"
#include "pso/ui/window/TWindowKeyBoardSoft.h"
#include "pso/system/memory.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"

struct Pos_80259A84
{
  f32 x;
  f32 y;
  u8 pad[0x18];
};

extern "C" {
u8 get_font_char_advance();
s32 map_char_to_font_code(s32);
u8 get_small_font_glyph_width();
s32 TWindowSubStatusDisp__sub_800FC248(s32);
s32 build_small_font_glyph_quad(s32, Pos_80259A84 *);
s32 set_glyph_quad_extents(s32, Pos_80259A84 *);
s32 calc_gauge_scale__20TWindowSubStatusDispFUsPvl(s32, Pos_80259A84 *, s32);
s32 try_open__19TWindowKeyBoardSoftFii(void *, Pos_80259A84 *);
void begin_screen_draw(s32 arg0);
s32 draw_textured_quad_at_depth(Pos_80259A84 *, f32);
void set_draw_texture_and_color(s32 idx, s32 arg1);

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

typedef struct Pos_80259A84 Pos_80259A84;
#pragma fp_contract on
void TUnk_804CF9C8::render(TWindowKeyBoardSoft *window_key_board_soft) {
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
  h = this->y;
  w = this->x;
  t = (h / 21.0f) + (w / (window_key_board_soft->inner_w));
  t *= 7.5f;
  t = 17.0f * (((f32) (window_key_board_soft->open_tick)) - t);
  if (t <= 0.0f)
  {
    return;
  }
  mode = (this->flags >> 2) & 1;
  n = this->value;
  x = (window_key_board_soft->inner_x) + w;
  y = (window_key_board_soft->inner_y) + h;
  scale = (-1.0f) / ((0.299f * this->depth) + (window_key_board_soft->depth));
  switch (mode)
  {
    case 0:
      TWindowSubStatusDisp::reset_gauge(0);
      window_key_board_soft = window_key_board_soft;
      break;
    case 1:
      begin_screen_draw(1);
      TWindowSubStatusDisp::render_forward();
      set_draw_texture_and_color(0, this->style);
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
          r = calc_gauge_scale__20TWindowSubStatusDispFUsPvl(((u8 (*)(u16)) map_char_to_font_code)(d + 0x30), &pos, this->style);
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
      TWindowSubStatusDisp::end_render_forward();
      break;
    case 1:
      TWindowSubStatusDisp::get_player();
      break;
  }
}

void TUnk_804CF9C8::update() {}

TUnk_804CF9C8::~TUnk_804CF9C8() {}

TUnk_804CF9C8::TUnk_804CF9C8(u8 *rec, s32 m_2) : TUnk_804CF998(m_2) {
    this->x = *(f32 *)(rec + 4);
    this->y = *(f32 *)(rec + 8);
    this->depth = *(f32 *)(rec + 0xC);
    this->flags = *(s32 *)(rec + 0x14);
    this->style = *(s32 *)(rec + 0x10);
    this->value = *(s32 *)(rec + 0x18);
}
