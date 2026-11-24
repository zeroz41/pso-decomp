#include "pso/ui/font/TNECFontEORFunction.h"
#include "types.h"
#include "pso/ui/window/WindowDrawContext.h"
#include "pso/unk/TUnk_804CF9C8.h"
#include "pso/ui/window/TWindowSubStatusDisp_8025995C.h"
#include "pso/ui/window/TWindowSubStatusDisp_80144B14.h"
#include "pso/ui/window/TWindowSubStatusDisp_802598E4.h"
#include "pso/ui/window/TWindowKeyBoardSoft.h"
#include "pso/system/memory.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"

extern "C" {
u8 get_small_font_glyph_width();
s32 TWindowSubStatusDisp__sub_800FC248(s32);
s32 build_small_font_glyph_quad(s32, TexturedQuad *);
void begin_screen_draw(s32 mode);
s32 draw_textured_quad_at_depth(TexturedQuad *, f32);
void set_draw_texture_and_color(s32 idx, s32 color);

void draw_right_aligned_number(void *arg0) {
    TUnk_804CF9C8 *digit = static_cast<TUnk_804CF9C8 *>(arg0);
    s32 n;
    n = digit->value;
    if (digit->flags & 4) {
        n /= 10;
        digit->width = 10.0f;
        digit->height = 13.0f;
        while (n > 0) {
            n /= 10;
            digit->width += 10.0f;
        }
        return;
    }
    digit->height = 18.0f;
    if (n <= 0) {
        digit->width = (u8)get_font_char_advance(map_char_to_font_code(0x30));
        return;
    }
    digit->width = 0.0f;
    while (n > 0) {
        u16 glyph = ((u16 (*)(s32))map_char_to_font_code)((u16)(n % 10) + 0x30);
        digit->width += (u8)get_font_char_advance(glyph);
        n /= 10;
    }
}
}

#pragma fp_contract on
void TUnk_804CF9C8::render(WindowDrawContext *context) {
  f32 t;
  TexturedQuad pos;
  f32 x;
  f32 y;
  f32 scale;
  s32 n;
  s32 mode;
  s32 g;
  u8 r;
  u8 d;
  f32 w;
  f32 h;
  h = this->y;
  w = this->x;
  t = (h / 21.0f) + (w / (context->inner_w));
  t *= 7.5f;
  t = 17.0f * (((f32) (context->open_tick)) - t);
  if (t <= 0.0f)
  {
    return;
  }
  mode = (this->flags >> 2) & 1;
  n = this->value;
  x = (context->inner_x) + w;
  y = (context->inner_y) + h;
  scale = (-1.0f) / ((0.299f * this->depth) + (context->depth));
  switch (mode)
  {
    case 0:
      TWindowSubStatusDisp::reset_gauge(0);
      context = context;
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
          pos.y0 = y;
          x -= (u8) r;
          pos.x0 = x;
          set_glyph_quad_extents(r, &pos);
          break;
      }
      case 1:
        g = TWindowSubStatusDisp__sub_800FC248(d + 0x30);
        x -= get_small_font_glyph_width();
        pos.y0 = y;
        pos.x0 = x;
        build_small_font_glyph_quad(g, &pos);
        break;
    }
    if (context->clip_and_transform_quad(&pos) != 0)
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
