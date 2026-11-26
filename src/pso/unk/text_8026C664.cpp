#include "pso/ui/window/TWindowCtrlMain_8024674C.h"
#include "pso/system/SoundEffect.h"
#include "types.h"
#include "pso/ui/window/WindowDrawContext.h"
#include "pso/ui/window/TWindowSubStatusDisp_803DEE6C.h"
#include "pso/unk/text_8026C664.h"
#include "pso/unk/TLobby_8001D6A0.h"
#include "pso/ui/window/TWindowSubStatusDisp_8024FBA8.h"
#include "pso/unk/text_8026C7AC.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/ui/window/TWindowSubStatusDisp_80144B14.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/ui/window/TWindowCtrl_8024A054.h"
#include "pso/quest/TQuestListVM_8007EAF8.h"
#include "pso/ui/window/PageIndicator.h"
#include "pso/system/ControllerInput.h"
#include "pso/ui/window/TWindowSubStatusDisp_80228F5C.h"

extern "C" {
void fn_8026C664(u8 *window_draw_context, f32 x, f32 y, f32 depth, f32 arrow_offset) {
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
  ((WindowDrawContext *)window_draw_context)->transform_quad(&quad);
  draw_textured_quad_at_depth(&quad.x0, depth);
}
typedef struct Stack_8026C708 Stack_8026C708;
void fn_8026C708(u8 *window_draw_context, f32 x, f32 y, f32 depth, f32 arrow_offset) {
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
  ((WindowDrawContext *)window_draw_context)->transform_quad(&quad);
  draw_textured_quad_at_depth(&quad.x0, depth);
}

}


s32 fn_8026C7AC(void *state, s8 value) {
    *(s8 *)((s8 *)state + 0) = 0;
    *(s8 *)((s8 *)state + 1) = value;
    return 1;
}

s32 fn_8026C7C0(void *state, s8 target) {
    u8 current;

    current = *(u8 *)((s8 *)state + 0);
    if (target == (s8) current) {
        return 0;
    }
    if (target > (s8) current) {
        *(f32 *)((s8 *)state + 8) = (f32) 1e+01f;
    } else {
        *(f32 *)((s8 *)state + 8) = (f32) (-1e+01f);
    }
    *(u8 *)((s8 *)state + 0) = (u8) target;
    return 1;
}
#pragma push
#pragma fp_contract on
#pragma readonly_strings on
void draw_list_page_indicator(PageIndicator *self, WindowDrawContext *r) {
    NJS_POINT2 pos;
    f32 scale;
    if (r->open_tick < 0) {
        return;
    }
    pos.x = (r->x + r->w) - 79.0f;
    pos.y = (r->y + r->h) - 22.0f;
    scale = (-1.0f) / (0.1495f + r->depth);
    begin_screen_draw(1);
    TObjFish::set_global_param(hud_texlist);
    set_draw_texture_and_color(0, -1);
    fn_8026C708((u8 *)r, (f32)(4e+01f + pos.x), (f32)(2.0f + pos.y), scale, (f32)self->arrow_offset);
    fn_8026C664((u8 *)r, (f32)(pos.x - 69.0f), (f32)(2.0f + pos.y), scale, (f32)self->arrow_offset);
    TWindowSubStatusDisp::get_player();
    set_text_draw_params(reinterpret_cast<WindowDrawContext *>(r), 0, 1, scale, (f32)1e+05f);
    text_builder_reset();
    text_builder_append_int(self->page + 1);
    pos.x -= (f32)calc_text_width(reinterpret_cast<char *>(get_shared_text_buffer()));
    u8 advance = get_font_char_advance(map_char_to_font_code('/'));
    pos.x -= 0.5f * (f32)advance;
    text_builder_append((u8 *)"/");
    text_builder_append_int(self->count);
    draw_window_text((f32 *)&pos, (const char *)(get_shared_text_buffer()), -1, 0, (f32)1e+05f);
}
#pragma pop
#pragma push
#pragma fp_contract on
void decay_page_arrow_offset(PageIndicator *o) {
    o->arrow_offset -= 0.15f * o->arrow_offset;
}
#pragma pop


s32 handle_list_page_flip_input(PageIndicator *page_indicator) {
    void *pad;
    s8 cur;
    decay_page_arrow_offset(page_indicator);
    cur = page_indicator->page;
    pad = &controller_input_state.controllers[is_player_input_active(page_indicator->input_port)];
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
        cur = page_indicator->count - 1;
    }
    if (cur >= page_indicator->count) {
        cur = 0;
    }
    if (cur == page_indicator->page) {
        return 0;
    }
    page_indicator->page = cur;
    if (test_pressed_buttons_packed(pad, 0x10000) != 0) {
        page_indicator->arrow_offset = 1e+01f;
    } else {
        page_indicator->arrow_offset = (-1e+01f);
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
