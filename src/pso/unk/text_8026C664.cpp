#include "types.h"
#include "pso/misc/TWindowSubStatusDisp_803DEE6C.h"
#include "pso/unk/text_8026C664.h"
#include "pso/misc/TLobby_8001D6A0.h"
#include "pso/misc/TWindowSubStatusDisp_8024FBA8.h"
#include "pso/unk/text_8026C7AC.h"
#include "pso/misc/TWindowSubStatusDisp.h"
#include "pso/object/TObjFish.h"
#include "pso/misc/TWindowCtrl_8024A054.h"
#include "pso/quest/TQuestListVM_8007EAF8.h"
#include "pso/misc/TWindowSubComCardList_8026CB08.h"
#include "pso/misc/TWindowSubComCardList.h"

struct Stack_8026C708
{
  f32 sp8;
  f32 spC;
  f32 sp10;
  f32 sp14;
  f32 sp18;
  f32 sp1C;
  f32 sp20;
  f32 sp24;
};

extern "C" {
void apply_context_transform_to_rect(void *, void *);
void fn_8026C664(u8 *arg0, f32 farg0, f32 farg1, f32 farg2, f32 farg3) {
  f32 buffer_8[8];
  buffer_8[0] = farg0;
  buffer_8[1] = farg1;
  if (farg3 < 0.0f)
  {
    buffer_8[0] = ((f32) ((double) farg0)) + farg3;
  }
  buffer_8[2] = 29.0f + buffer_8[0];
  buffer_8[3] = 15.0f + buffer_8[1];
  buffer_8[4] = 0.72265625f;
  buffer_8[5] = 0.3984375f;
  buffer_8[6] = 0.8359375f;
  buffer_8[7] = 0.45703125f;
  apply_context_transform_to_rect(arg0, &buffer_8[0]);
  draw_textured_quad_at_depth(&buffer_8[0], farg2);
}
typedef struct Stack_8026C708 Stack_8026C708;
void fn_8026C708(u8 *arg0, f32 farg0, f32 farg1, f32 farg2, f32 farg3) {
  float new_var;
  Stack_8026C708 stack;
  stack.sp8 = farg0;
  stack.spC = farg1;
  if (farg3 > 0.0f)
  {
    stack.sp8 = ((f32) ((double) farg0)) + farg3;
  }
  stack.sp10 = 29.0f + stack.sp8;
  new_var = 15.0f + stack.spC;
  stack.sp14 = new_var;
  stack.sp18 = 0.84375f;
  stack.sp1C = 0.3984375f;
  stack.sp20 = 0.95703125f;
  stack.sp24 = 0.45703125f;
  apply_context_transform_to_rect(arg0, &stack.sp8);
  draw_textured_quad_at_depth(&stack.sp8, farg2);
}

}

typedef struct Vec2_8026C800 { f32 x, y; } Vec2_8026C800;

typedef struct Rect_8026C800 { f32 x, y, w, h; u8 pad10[0x20]; s32 f30; u8 pad34[4]; f32 f38; } Rect_8026C800;

typedef struct Self_8026C800 { s8 page; s8 count; u8 pad2[6]; f32 phase; } Self_8026C800;

extern "C" {
u32 calc_text_width(void);
u8 get_font_char_advance(void);
u16 map_char_to_font_code(u16 c);
void TWindowSubStatusDisp__sub_80228F5C(s32);
void text_builder_append(u8 *str);
}
void text_builder_reset(void);
extern s32 lbl_805D63F0;

extern "C" {
void draw_list_page_indicator(Self_8026C800 *self, Rect_8026C800 *r);
s32 fn_8026C7AC(void *arg0, s8 arg1) {
    *(s8 *)((s8 *)arg0 + 0) = 0;
    *(s8 *)((s8 *)arg0 + 1) = arg1;
    return 1;
}

s32 fn_8026C7C0(void *arg0, s8 arg1) {
    u8 temp_r0;

    temp_r0 = *(u8 *)((s8 *)arg0 + 0);
    if (arg1 == (s8) temp_r0) {
        return 0;
    }
    if (arg1 > (s8) temp_r0) {
        *(f32 *)((s8 *)arg0 + 8) = (f32) 1e+01f;
    } else {
        *(f32 *)((s8 *)arg0 + 8) = (f32) (-1e+01f);
    }
    *(u8 *)((s8 *)arg0 + 0) = (u8) arg1;
    return 1;
}
#pragma push
#pragma fp_contract on
#pragma readonly_strings on
void draw_list_page_indicator(Self_8026C800 *self, Rect_8026C800 *r) {
    Vec2_8026C800 pos;
    f32 scale;
    if (r->f30 < 0) {
        return;
    }
    pos.x = (r->x + r->w) - 79.0f;
    pos.y = (r->y + r->h) - 22.0f;
    scale = (-1.0f) / (0.1495f + r->f38);
    begin_screen_draw(1);
    TObjFish::set_global_param(lbl_805D63F0);
    set_draw_texture_and_color(0, -1);
    fn_8026C708((u8 *)r, (f32)(4e+01f + pos.x), (f32)(2.0f + pos.y), (f32)scale, (f32)self->phase);
    fn_8026C664((u8 *)r, (f32)(pos.x - 69.0f), (f32)(2.0f + pos.y), (f32)scale, (f32)self->phase);
    TWindowSubStatusDisp::get_player();
    set_text_draw_params((s32)r, 0, 1, (f32)scale, (f32)1e+05f);
    text_builder_reset();
    TWindowSubStatusDisp__sub_80228F5C(self->page + 1);
    get_shared_text_buffer();
    pos.x -= (f32)calc_text_width();
    map_char_to_font_code(0x2F);
    { u32 adv = get_font_char_advance(); pos.x -= 0.5f * (f32)adv; }
    text_builder_append((u8 *)"/");
    TWindowSubStatusDisp__sub_80228F5C(self->count);
    draw_window_text((f32 *)&pos, (const char *)(get_shared_text_buffer()), -1, 0, (f32)1e+05f);
}
}
#pragma pop

struct Ctl_8026C9DC {
    s8 cur;
    s8 count;
    u8 pad2[2];
    s32 port;
    f32 speed;
};

extern "C" {

#pragma push
#pragma fp_contract on
void decay_page_arrow_offset(Ctl_8026C9DC *o) {
    o->speed -= 0.15f * o->speed;
}
#pragma pop

}

struct Pad_8026C9DC {
    u8 pad0[0x20];
    u8 buttons[0x30];
};

extern "C" {
s32 TWindowShortListCtrl__check_controller_button(void *, u32);
void play_sound_effect(s32, s32, s32, s32);
extern Pad_8026C9DC controller_input_state[];

s32 handle_list_page_flip_input(Ctl_8026C9DC *arg0) {
    void *pad;
    s8 cur;
    decay_page_arrow_offset(arg0);
    cur = arg0->cur;
    pad = controller_input_state[is_player_input_active(arg0->port)].buttons;
    if (TWindowShortListCtrl__check_controller_button(pad, 0x30000) == 0) {
        return 0;
    }
    play_sound_effect(0x54100, 0, 0, 0);
    if (TWindowShortListCtrl__check_controller_button(pad, 0x10000) != 0) {
        cur++;
    }
    if (TWindowShortListCtrl__check_controller_button(pad, 0x20000) != 0) {
        cur--;
    }
    if (cur < 0) {
        cur = arg0->count - 1;
    }
    if (cur >= arg0->count) {
        cur = 0;
    }
    if (cur == arg0->cur) {
        return 0;
    }
    arg0->cur = cur;
    if (TWindowShortListCtrl__check_controller_button(pad, 0x10000) != 0) {
        arg0->speed = 1e+01f;
    } else {
        arg0->speed = (-1e+01f);
    }
    return 1;
}

}

s32 delete_if_allocated(s32 arg0, s16 arg1) {
    if ((arg0 != 0) && (arg1 > 0)) {
        __dl__FPv();
    }
    return arg0;
}

void TWindowSubComCardList::init(int a1, int a2, int a3) { *(unsigned char *)&this->m_name = a1; *(unsigned char*)((char*)this + 0x1) = a2; *(int *)&this->m_flags = a3; *(float *)&this->m_prev = 0.0f; }
