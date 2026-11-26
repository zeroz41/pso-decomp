#include "pso/ui/font/TNECFontEORFunction.h"
#include "types.h"
#include "pso/ui/window/WindowDrawContext.h"
#include "pso/unk/TWindowLayoutNumber.h"
#include "pso/ui/window/TWindowSubStatusDisp_80144B14.h"
#include "pso/ui/window/TWindowKeyBoardSoft.h"
#include "pso/system/memory.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/ui/window/TWindowSubStatusDisp_803DEE6C.h"

extern "C" {
extern "C" u8 bind_menu_font_glyph(u16 glyph, TexturedQuad *quad, s32 color);
u8 get_small_font_glyph_width();
s32 get_small_font_glyph_id(s32);
s32 build_small_font_glyph_quad(s32, TexturedQuad *);
}

void TWindowLayoutNumber::calc_size() {
    s32 n;
    n = this->value;
    if (this->flags & 4) {
        n /= 10;
        this->width = 10.0f;
        this->height = 13.0f;
        while (n > 0) {
            n /= 10;
            this->width += 10.0f;
        }
        return;
    }
    this->height = 18.0f;
    if (n <= 0) {
        this->width = (u8)get_font_char_advance(map_char_to_font_code(0x30));
        return;
    }
    this->width = 0.0f;
    while (n > 0) {
        u16 glyph = ((u16 (*)(s32))map_char_to_font_code)((u16)(n % 10) + 0x30);
        this->width += (u8)get_font_char_advance(glyph);
        n /= 10;
    }
}

#pragma fp_contract on
void TWindowLayoutNumber::render(WindowDrawContext *context) {
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
      set_draw_texture_and_color(0, this->color);
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
          r = bind_menu_font_glyph(((u8 (*)(u16)) map_char_to_font_code)(d + 0x30), &pos, this->color);
          pos.y0 = y;
          x -= r;
          pos.x0 = x;
          set_glyph_quad_extents(r, &pos);
          break;
      }
      case 1:
        g = get_small_font_glyph_id(d + 0x30);
        x -= get_small_font_glyph_width();
        pos.y0 = y;
        pos.x0 = x;
        build_small_font_glyph_quad(g, &pos);
        break;
    }
    if (context->clip_and_transform_quad(&pos) != 0)
    {
      draw_textured_quad_at_depth(&pos.x0, scale);
    }
  }
  while ((n /= 10) > 0);
  switch (mode)
  {
    case 0:
      TWindowSubStatusDisp::end_render_forward();
      break;
    case 1:
      end_screen_draw();
      break;
  }
}

void TWindowLayoutNumber::update() {}

TWindowLayoutNumber::~TWindowLayoutNumber() {}

TWindowLayoutNumber::TWindowLayoutNumber(ValueLayoutRecord *rec, s32 client) : TWindowLayoutRect(client) {
    this->x = rec->pos[0];
    this->y = rec->pos[1];
    this->depth = rec->depth;
    this->flags = rec->flags;
    this->color = rec->color;
    this->value = rec->value;
}
