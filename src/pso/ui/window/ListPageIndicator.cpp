#include "pso/ui/window/TWindowBase.h"
#include "pso/system/SoundEffect.h"
#include "types.h"
#include "pso/ui/window/WindowDrawContext.h"
#include "pso/ui/window/ScreenQuadDraw.h"
#include "pso/ui/window/ListPageIndicator.h"
#include "pso/enemy/BattleParamTables.h"
#include "pso/ui/window/WindowTextDraw.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/ui/font/MenuFontGlyphs.h"
#include "pso/render/TextureState.h"
#include "pso/ui/window/TWindowCtrl.h"
#include "pso/quest/GlobalNewDelete.h"
#include "pso/ui/window/PageIndicator.h"
#include "pso/system/ControllerInput.h"
#include "pso/ui/window/TextBuilder.h"

void draw_page_arrow_left(WindowDrawContext *context, f32 x, f32 y, f32 depth, f32 arrow_offset) {
  TexturedQuad quad;
  quad.x0 = x;
  quad.y0 = y;
  if (arrow_offset < 0.0f)
  {
    quad.x0 = ((f32) ((double) x)) + arrow_offset;
  }
  quad.x1 = 29.0f + quad.x0;
  quad.y1 = 15.0f + quad.y0;
  quad.u0 = 0.72265625f;
  quad.v0 = 0.3984375f;
  quad.u1 = 0.8359375f;
  quad.v1 = 0.45703125f;
  context->transform_quad(&quad);
  draw_textured_quad_at_depth(&quad.x0, depth);
}
void draw_page_arrow_right(WindowDrawContext *context, f32 x, f32 y, f32 depth, f32 arrow_offset) {
  float bottom;
  TexturedQuad quad;
  quad.x0 = x;
  quad.y0 = y;
  if (arrow_offset > 0.0f)
  {
    quad.x0 = ((f32) ((double) x)) + arrow_offset;
  }
  quad.x1 = 29.0f + quad.x0;
  bottom = 15.0f + quad.y0;
  quad.y1 = bottom;
  quad.u0 = 0.84375f;
  quad.v0 = 0.3984375f;
  quad.u1 = 0.95703125f;
  quad.v1 = 0.45703125f;
  context->transform_quad(&quad);
  draw_textured_quad_at_depth(&quad.x0, depth);
}


s32 PageIndicator::reset(s8 new_count) {
    page = 0;
    count = new_count;
    return 1;
}

s32 PageIndicator::turn_to(s8 new_page) {
    if (new_page == page) {
        return 0;
    }
    if (new_page > page) {
        arrow_offset = 1e+01f;
    } else {
        arrow_offset = -1e+01f;
    }
    page = new_page;
    return 1;
}
#pragma push
#pragma fp_contract on
#pragma readonly_strings on
void PageIndicator::draw(WindowDrawContext *context) {
    NJS_POINT2 pos;
    f32 scale;
    if (context->open_tick < 0) {
        return;
    }
    pos.x = (context->x + context->w) - 79.0f;
    pos.y = (context->y + context->h) - 22.0f;
    scale = (-1.0f) / (0.1495f + context->depth);
    begin_screen_draw(1);
    set_texture_list(hud_texlist);
    set_draw_texture_and_color(0, -1);
    draw_page_arrow_right(context, 40.0f + pos.x, 2.0f + pos.y, scale, arrow_offset);
    draw_page_arrow_left(context, pos.x - 69.0f, 2.0f + pos.y, scale, arrow_offset);
    end_screen_draw();
    set_text_draw_params(context, 0, 1, scale, (f32)1e+05f);
    text_builder_reset();
    text_builder_append_int(page + 1);
    pos.x -= (f32)calc_text_width(reinterpret_cast<char *>(get_shared_text_buffer()));
    u8 advance = get_font_char_advance(map_char_to_font_code('/'));
    pos.x -= 0.5f * (f32)advance;
    text_builder_append("/");
    text_builder_append_int(count);
    draw_window_text((f32 *)&pos, get_shared_text_buffer(), -1, 0, (f32)1e+05f);
}
#pragma pop
#pragma push
#pragma fp_contract on
void PageIndicator::decay_arrow_offset() {
    arrow_offset -= 0.15f * arrow_offset;
}
#pragma pop


s32 PageIndicator::handle_flip_input() {
    ControllerInputContext *pad;
    s8 cur;
    decay_arrow_offset();
    cur = page;
    pad = &controller_input_state.controllers[is_player_input_active(input_port)];
    if (test_pressed_buttons_packed(pad, 0x30000) == 0) {
        return 0;
    }
    play_sound_effect(0x54100, 0, 0, 0);
    if (test_pressed_buttons_packed(pad, 0x10000) != 0) {
        cur++;
    }
    if (test_pressed_buttons_packed(pad, 0x20000) != 0) {
        cur--;
    }
    if (cur < 0) {
        cur = count - 1;
    }
    if (cur >= count) {
        cur = 0;
    }
    if (cur == page) {
        return 0;
    }
    page = cur;
    if (test_pressed_buttons_packed(pad, 0x10000) != 0) {
        arrow_offset = 1e+01f;
    } else {
        arrow_offset = (-1e+01f);
    }
    return 1;
}

void *delete_if_allocated(void *storage, s16 release) {
    if (storage != NULL && release > 0) {
        ::operator delete(storage);
    }
    return storage;
}

PageIndicator::PageIndicator(s8 current, s8 pages, s32 client)
    : page(current), count(pages), input_port(client), arrow_offset(0.0f) {}
