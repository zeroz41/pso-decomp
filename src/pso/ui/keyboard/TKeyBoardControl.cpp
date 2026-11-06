#include "types.h"
#include "pso/ui/keyboard/TKeyBoardControl_8025CB70.h"
#include "pso/ui/window/TWindowSubMag_802627D8.h"
#include "pso/ui/window/TWindowSubStatusDisp_803DEE6C.h"
#include "pso/ui/window/TWindowKeyBoardSoft.h"
#include "pso/ui/window/TWindowKeyBoardSoft_8025B85C.h"
#include "pso/ui/window/TWindowChoiceSetting.h"
#include "pso/ui/frontend/TAdMultiPlyChrSelectGC.h"
#include "pso/ui/Language.h"

struct UV_80262038 {
    f32 u;
    f32 v;
};

struct Quad_80262038 {
    f32 x;
    f32 y;
    f32 x2;
    f32 y2;
    f32 u;
    f32 v;
    f32 u2;
    f32 v2;
};

#include <stddef.h>
#include "pso/ui/keyboard/TKeyBoardControl.h"
#include "pso/ui/window/TWindowEffectLight.h"
#include "pso/ui/window/TWindowSubComCard.h"
#include "pso/ui/window/TWindowSubMag.h"
struct RecoveredGlobal_8026088C_lbl_8050E208 {
    s32 value;
    u8 remaining[0x1AC];
};

struct RecoveredFields_8026088C_arg0 {
    u8 unknown_0[0x60];
    s32 field_60;
    u8 unknown_64[0x8];
    u32 field_6C;
};

extern "C" {
s32 TWindowShortListCtrl__check_controller_button(void *, int, int);
struct RecoveredGlobal_80260808_lbl_8050E208 {
    s32 value;
    u8 remaining[0x1AC];
};

struct RecoveredGlobal_8026062C_TWindowKeyBoardSoft__data_8044F124
{
  s32 value;
  u8 remaining[0x10];
};

struct RecoveredGlobal_8026062C_TWindowKeyBoardSoft__data_804CB7C8
{
  s32 value;
  u8 remaining[0x6C];
};

struct Win_802605DC { u8 p0[0x65]; s8 f65; s8 f66; };

typedef struct RecoveredGlobal_8026062C_TWindowKeyBoardSoft__data_8044F124 RecoveredGlobal_8026062C_TWindowKeyBoardSoft__data_8044F124;

typedef struct RecoveredGlobal_8026062C_TWindowKeyBoardSoft__data_804CB7C8 RecoveredGlobal_8026062C_TWindowKeyBoardSoft__data_804CB7C8;

typedef char RecoveredGlobal_8026062C_TWindowKeyBoardSoft__data_8044F124_size[((sizeof(RecoveredGlobal_8026062C_TWindowKeyBoardSoft__data_8044F124)) == 0x14) ? (1) : (-1)];

typedef char RecoveredGlobal_8026062C_TWindowKeyBoardSoft__data_804CB7C8_size[((sizeof(RecoveredGlobal_8026062C_TWindowKeyBoardSoft__data_804CB7C8)) == 0x70) ? (1) : (-1)];

typedef char RecoveredGlobal_80260808_lbl_8050E208_size[sizeof(RecoveredGlobal_80260808_lbl_8050E208) == 0x1B0 ? 1 : -1];

struct Vec2_802615B8 {
    f32 x;
    f32 y;
};

struct Lines_80261DD8 {
    Vec2_802615B8 *verts;
    u32 *colors;
    s32 f8;
    s32 count;
};

s32 play_sound_effect(int, int, int, int);
s32 draw_default_entry__9TWindowDDFl();
int update_keyboard_close_mode(void*);
void calc_cursor_step__19TWindowKeyBoardSoftFiPvPv(s32 arg0, s32 *arg1, s32 *arg2);
f32 calc_key_x__19TWindowKeyBoardSoftFiii(s32 arg0, s32 arg1, s32 arg2);
s32 calc_key_index__19TWindowKeyBoardSoftFiii(s32 arg1, s32 arg2, s32 arg3);
f32 TWindowKeyBoardSoft__sub_802606E0(TWindowKeyBoardSoft *);
void TWindowKeyBoardSoft__sub_80260760(void *self, s32 key, s32 *count, u32 *color);
void TWindowKeyBoardSoft__sub_80260E30(void *self, s32 port);
void TWindowKeyBoardSoft__sub_80261134(void *self);
extern u8 lbl_8044F138[];
void TKeyBoardControl__sub_802613A4(TKeyBoardControl *arg0);
f32 TWindowKeyBoardSoft__sub_802614DC(u8 *, u8 *, f32, f32, f32, f32);
s32 TWindowKeyBoardSoft__sub_802616BC(void *, int);
void TWindowKeyBoardSoft__sub_80261DD8(TWindowKeyBoardSoft *, TWindowKeyBoardSoft *);
s32 TWindowKeyBoardSoft__sub_8026227C(void *, int);
s32 get_flag_bit5__19TWindowKeyBoardSoftFv();

extern RecoveredGlobal_8026062C_TWindowKeyBoardSoft__data_8044F124 TWindowKeyBoardSoft__data_8044F124;
extern RecoveredGlobal_8026062C_TWindowKeyBoardSoft__data_804CB7C8 TWindowKeyBoardSoft__data_804CB7C8;
extern u8 *TWindowKeyBoardSoft__language_text_resources;
extern const f32 TWindowKeyBoardSoft__data_805DD078;
extern const f32 TWindowKeyBoardSoft__data_805DD07C;
extern const f32 TWindowKeyBoardSoft__data_805DD080;
extern const f32 TWindowKeyBoardSoft__data_805DD088;
extern const f32 TWindowKeyBoardSoft__data_805DD094;
extern RecoveredGlobal_80260808_lbl_8050E208 controller_input_state;
extern void *local_client_id;
extern const f32 lbl_805DD084;
extern const f32 lbl_805DD08C;
void apply_context_transform_to_rect(void *, void *);
void draw_color_lines(Lines_80261DD8 *l, s32 n, s32 flags, f32 scale);
extern UV_80262038 keyboard_key_frame_uv_table[];
extern const f32 TWindowKeyBoardSoft__data_805DD090;
extern const f32 lbl_805DD0C8;

void calc_cursor_step__19TWindowKeyBoardSoftFiPvPv(s32 arg0, s32 *arg1, s32 *arg2) {
    switch (current_language) {
    case LANGUAGE_JAPANESE:
        if ((get_flag_bit5__19TWindowKeyBoardSoftFv() != 0) || (((TWindowKeyBoardSoft *)arg0)->get_flag_bit6() != 0) || (((TWindowKeyBoardSoft *)arg0)->is_cursor_locked() != 0)) {
            *arg1 = 4;
            *arg2 = 4;
            return;
        }
        if (TWindowSubMag__sub_802627D8((void *)arg0) != 0) {
            *arg1 = 4;
            *arg2 = 5;
            return;
        }
        *arg1 = 0;
        *arg2 = 5;
        return;
    case LANGUAGE_ENGLISH:
        if ((get_flag_bit5__19TWindowKeyBoardSoftFv() != 0) || (((TWindowKeyBoardSoft *)arg0)->get_flag_bit6() != 0) || (((TWindowKeyBoardSoft *)arg0)->is_cursor_locked() != 0)) {
            *arg1 = 0;
            *arg2 = 0;
            return;
        }
        *arg1 = 0;
        *arg2 = 1;
        return;
    case LANGUAGE_GERMAN:
    case LANGUAGE_FRENCH:
    case LANGUAGE_SPANISH:
        if ((get_flag_bit5__19TWindowKeyBoardSoftFv() != 0) || (((TWindowKeyBoardSoft *)arg0)->get_flag_bit6() != 0) || (((TWindowKeyBoardSoft *)arg0)->is_cursor_locked() != 0)) {
            *arg1 = 0;
            *arg2 = 0;
            return;
        }
        if (TWindowSubMag__sub_802627D8((void *)arg0) != 0) {
            *arg1 = 0;
            *arg2 = 1;
            return;
        }
        *arg1 = 0;
        *arg2 = 2;
        return;
    }
}

#pragma push
#pragma fp_contract on
s32 TWindowKeyBoardSoft::sub_802605DC() {
    s32 idx = calc_key_index__19TWindowKeyBoardSoftFiii((s32)(((Win_802605DC *)this)), (s32)(((Win_802605DC *)this)->f65), (s32)(((Win_802605DC *)this)->f66));
    return idx + ((s8 *)&TWindowKeyBoardSoft__data_8044F124)[((u8 *)&TWindowKeyBoardSoft__data_804CB7C8)[idx]];
}
#pragma pop

#pragma push
#pragma fp_contract on
f32 calc_key_x__19TWindowKeyBoardSoftFiii(s32 arg0, s32 arg1, s32 arg2) {
  f32 new_var;
  s32 sp8;
  s32 temp_r31;
  s32 temp_r3;
  temp_r3 = calc_key_index__19TWindowKeyBoardSoftFiii(arg0, arg1, arg2);
  temp_r31 = arg1 + ((s8) (*((u8 *) (((s8 *) (((u8 *)&TWindowKeyBoardSoft__data_8044F124.value) + (*((u8 *) (((s8 *) (((u8 *)&TWindowKeyBoardSoft__data_804CB7C8.value) + temp_r3)) + 0))))) + 0))));
  TWindowKeyBoardSoft__sub_80260760((void *) arg0, (int) temp_r3, &sp8, NULL);
  new_var = TWindowKeyBoardSoft::calc_key_coord(arg0, sp8);
  return TWindowKeyBoardSoft__data_805DD078 + ((TWindowKeyBoardSoft__data_805DD07C * ((f32) temp_r31)) + (TWindowKeyBoardSoft__data_805DD080 * new_var));
}
#pragma pop

#pragma push
#pragma fp_contract on
s32 calc_key_index__19TWindowKeyBoardSoftFiii(s32 arg1, s32 arg2, s32 arg3) {
    return arg2 + (arg3 * 0x10);
}
#pragma pop

#pragma push
#pragma fp_contract on
#pragma fp_contract on
f32 TWindowKeyBoardSoft__sub_802606E0(TWindowKeyBoardSoft *) {
    return -((TWindowKeyBoardSoft__data_805DD080 * (f32) (*(u8 *)((s8 *)TWindowKeyBoardSoft__language_text_resources + 0) * *(u8 *)((s8 *)TWindowKeyBoardSoft__language_text_resources + 1))) - lbl_805DD084);
}
#pragma pop

#pragma push
#pragma fp_contract on
#pragma fp_contract on
f32 TWindowKeyBoardSoft::calc_key_coord(s32 arg0, s32 arg1) {
    return (TWindowKeyBoardSoft__data_805DD07C * (f32) arg1) + TWindowKeyBoardSoft__data_805DD078;
}
#pragma pop

void TWindowKeyBoardSoft__sub_80260760(void *self, s32 key, s32 *count, u32 *color) {
    s32 n;
    u32 c;
    switch (((u8 *)&TWindowKeyBoardSoft__data_804CB7C8.value)[key]) {
    case 0:
        n = 1;
        c = 0xFF173D84;
        break;
    case 1:
        n = 1;
        c = 0xFF621784;
        break;
    case 2:
    case 3:
        n = 2;
        c = 0xFF6A6E13;
        break;
    case 4:
    case 5:
    case 6:
    case 7:
        n = 4;
        c = 0xFF4F700C;
        break;
    case 8:
    case 9:
    case 10:
    case 11:
    case 12:
    case 13:
    case 14:
    case 15:
    case 16:
    case 17:
        n = 10;
        c = 0xFF842317;
        break;
    }
    if (count != NULL) {
        *count = n;
    }
    if (color != NULL) {
        *color = c;
    }
}

#pragma push
#pragma fp_contract on
void TWindowKeyBoardSoft::sub_80260808(s32 arg1) {
    s32 temp_r5;
    temp_r5 = arg1 * 0x50;
    if ((TWindowShortListCtrl__check_controller_button((void *) ((u8 *)&controller_input_state.value + temp_r5 + 0x20), 2, temp_r5) != 0) && ((u32) *(u32 *)((s8 *)((u8 *)this) + 0x6C) != 0U)) {
        this->m_7c = (s32) (this->m_7c & 0xFFFFFFEF);
        play_sound_effect(0x52F16, 0, 0, 0);
        ((TWindowKeyBoardSoft *)(*(u32 *)((s8 *)((u8 *)this) + 0x6C)))->handle_backspace();
    }
}
#pragma pop

typedef char RecoveredGlobal_8026088C_lbl_8050E208_size[sizeof(RecoveredGlobal_8026088C_lbl_8050E208) == 0x1B0 ? 1 : -1];
typedef char RecoveredFields_8026088C_arg0_60_offset[offsetof(RecoveredFields_8026088C_arg0, field_60) == 0x60 ? 1 : -1];
typedef char RecoveredFields_8026088C_arg0_6C_offset[offsetof(RecoveredFields_8026088C_arg0, field_6C) == 0x6C ? 1 : -1];
void TWindowKeyBoardSoft::update_keyboard_child_input_from_controller(s32 arg1) {
    u32 temp_r3;
    if (((s32 (*)(void *, int))TWindowShortListCtrl__check_controller_button)((void *)((void *) ((u8 *)&(*(RecoveredGlobal_8026088C_lbl_8050E208 *)&controller_input_state).value + (arg1 * 0x50) + 0x20)), 0x400) != 0) {
        temp_r3 = ((RecoveredFields_8026088C_arg0 *)((u8 *)this))->field_6C;
        if (temp_r3 != 0U) {
            ((TWindowKeyBoardSoft *)temp_r3)->update_input_state2();
            if (((TWindowKeyBoardSoft *)(((RecoveredFields_8026088C_arg0 *)((u8 *)this))->field_6C))->is_key_state_2() != 0) {
                ((RecoveredFields_8026088C_arg0 *)((u8 *)this))->field_60 = (s32) (((RecoveredFields_8026088C_arg0 *)((u8 *)this))->field_60 | 0x10);
            }
        }
    }
}

struct KeyCursor_80260E30 {
    u8 pad0[0x60];
    u32 flags;
    u8 layout;
    u8 cursor_x;
    u8 cursor_y;
    u8 pad67[0x6C - 0x67];
    TWindowKeyBoardSoft *child;
};

void TWindowKeyBoardSoft__sub_80260E30(void *self, s32 port) {
    KeyCursor_80260E30 *kb = (KeyCursor_80260E30 *)self;
    s8 dx = 0;
    s8 dy = 0;
    s32 input;
    if (kb->flags & 2) {
        input = (s32)((u8 *)&controller_input_state.value + port * 0x50 + 0x20);
        if (TWindowChoiceSetting::apply_choice(input, 0xF0, 6, 2) == 0) {
            return;
        }
        if (TWindowChoiceSetting::apply_choice(input, 0x10, 6, 2) != 0) {
            dy = -1;
        }
        if (TWindowChoiceSetting::apply_choice(input, 0x20, 6, 2) != 0) {
            dy++;
        }
        if (TWindowChoiceSetting::apply_choice(input, 0x40, 6, 2) != 0) {
            dx = -1;
        }
        if (TWindowChoiceSetting::apply_choice(input, 0x80, 6, 2) != 0) {
            dx++;
        }
    } else {
        input = (s32)((u8 *)&controller_input_state.value + port * 0x50 + 0x20);
        if (TAdMultiPlyChrSelectGC::dispatch_draw_command(input, 0xF0, 6, 2) == 0) {
            return;
        }
        if (TAdMultiPlyChrSelectGC::dispatch_draw_command(input, 0x10, 6, 2) != 0) {
            dy = -1;
        }
        if (TAdMultiPlyChrSelectGC::dispatch_draw_command(input, 0x20, 6, 2) != 0) {
            dy++;
        }
        if (TAdMultiPlyChrSelectGC::dispatch_draw_command(input, 0x40, 6, 2) != 0) {
            dx = -1;
        }
        if (TAdMultiPlyChrSelectGC::dispatch_draw_command(input, 0x80, 6, 2) != 0) {
            dx++;
        }
    }
    play_sound_effect(0x54100, 0, 0, 0);
    if (kb->flags & 0x10) {
        if (dx > 0) {
            kb->child->vt15();
        } else if (dx < 0) {
            kb->child->vt16();
        }
        if (dy > 0) {
            kb->child->vt18();
        } else if (dy < 0) {
            kb->child->vt17();
        }
        return;
    }
    if (dx > 0) {
        kb->cursor_x += lbl_8044F138[((u8 *)&TWindowKeyBoardSoft__data_804CB7C8.value)[(s8)kb->cursor_x + (s8)kb->cursor_y * 16]] + 1;
    }
    if (dx < 0) {
        kb->cursor_x += ((u8 *)&TWindowKeyBoardSoft__data_8044F124.value)[((u8 *)&TWindowKeyBoardSoft__data_804CB7C8.value)[(s8)kb->cursor_x + (s8)kb->cursor_y * 16]] - 1;
    }
    kb->cursor_y += dy;
    if ((s8)kb->cursor_x < 0) {
        kb->cursor_x += 16;
    }
    if ((s8)kb->cursor_x >= 16) {
        kb->cursor_x -= 16;
    }
    if ((s8)kb->cursor_y < 0) {
        kb->cursor_y += 7;
    }
    if ((s8)kb->cursor_y >= 7) {
        kb->cursor_y -= 7;
    }
}

void TWindowKeyBoardSoft__sub_80261134(void *self) {
    KeyCursor_80260E30 *kb = (KeyCursor_80260E30 *)self;
    switch (current_language) {
    case LANGUAGE_JAPANESE:
        kb->layout = 4;
        break;
    case LANGUAGE_ENGLISH:
        kb->layout = 0;
        break;
    case LANGUAGE_GERMAN:
    case LANGUAGE_FRENCH:
    case LANGUAGE_SPANISH:
        kb->layout = 0;
        break;
    }
    ((TWindowKeyBoardSoft *)self)->update_focus_flags();
}

#pragma push
#pragma fp_contract on
void TWindowKeyBoardSoft::update_focus_flags() {
    void *temp_r3;
    void *temp_r3_2;
    void *temp_r4;
    void *temp_r4_2;

    if (current_language != LANGUAGE_JAPANESE) {
        if ((s32) current_language < 0) {
            return;
        }
        return;
    }
    if ((s8) *(u8 *)((s8 *)this + 0x64) == 0) {
        temp_r4 = *(void **)((s8 *)this + 0x6C);
        *(s32 *)((s8 *)temp_r4 + 0xB4) = (s32) (*(s32 *)((s8 *)temp_r4 + 0xB4) | 1);
        temp_r3 = *(void **)((s8 *)this + 0x6C);
        *(s32 *)((s8 *)temp_r3 + 0xB4) = (s32) (*(s32 *)((s8 *)temp_r3 + 0xB4) & 0xFFFFFFBF);
        return;
    }
    temp_r4_2 = *(void **)((s8 *)this + 0x6C);
    *(s32 *)((s8 *)temp_r4_2 + 0xB4) = (s32) (*(s32 *)((s8 *)temp_r4_2 + 0xB4) & 0xFFFFFFFE);
    temp_r3_2 = *(void **)((s8 *)this + 0x6C);
    *(s32 *)((s8 *)temp_r3_2 + 0xB4) = (s32) (*(s32 *)((s8 *)temp_r3_2 + 0xB4) | 0x40);
}
#pragma pop

#pragma push
#pragma fp_contract on
void TWindowKeyBoardSoft::handle_page_cycle_input(s32 arg1) {
    s32 spC;
    s32 sp8;
    u8 *temp_r30;
    temp_r30 = (u8 *)&controller_input_state.value + (arg1 * 0x50) + 0x20;
    if (((s32 (*)(int, int))TWindowShortListCtrl__check_controller_button)((int)temp_r30, 0x30000) != 0) {
        play_sound_effect(0x54100, 0, 0, 0);
        calc_cursor_step__19TWindowKeyBoardSoftFiPvPv((s32)this, &spC, &sp8);
        if (((s32 (*)(int, int))TWindowShortListCtrl__check_controller_button)((int)temp_r30, 0x10000) != 0) {
            *(f32 *)((s8 *)((u8 *)this) + 0x68) = (f32) TWindowKeyBoardSoft__data_805DD088;
            *(u8 *)((s8 *)((u8 *)this) + 0x64) = (u8) (*(u8 *)((s8 *)((u8 *)this) + 0x64) + 1);
        }
        if (((s32 (*)(int, int))TWindowShortListCtrl__check_controller_button)((int)temp_r30, 0x20000) != 0) {
            *(f32 *)((s8 *)((u8 *)this) + 0x68) = (f32) lbl_805DD08C;
            *(u8 *)((s8 *)((u8 *)this) + 0x64) = (u8) (*(u8 *)((s8 *)((u8 *)this) + 0x64) - 1);
        }
        if ((s8) *(u8 *)((s8 *)((u8 *)this) + 0x64) < spC) {
            *(u8 *)((s8 *)((u8 *)this) + 0x64) = (u8) sp8;
        }
        if ((s8) *(u8 *)((s8 *)((u8 *)this) + 0x64) > sp8) {
            *(u8 *)((s8 *)((u8 *)this) + 0x64) = (u8) spC;
        }
        this->update_focus_flags();
    }
}
#pragma pop

void TKeyBoardControl::close() {
    void *temp_r3;
    *(s32 *)((s8 *)this + 0x60) = (s32) (*(s32 *)((s8 *)this + 0x60) | 0x80);
    temp_r3 = *(void **)((s8 *)this + 0x6C);
    if (temp_r3 != NULL) {
        TKeyBoardControl__sub_8025CBC0(temp_r3);
        release();
    }
}

void TKeyBoardControl::release_input() {
    void *temp_r3;
    *(s32 *)((s8 *)this + 0x60) = (s32) (*(s32 *)((s8 *)this + 0x60) | 0x40);
    temp_r3 = *(void **)((s8 *)this + 0x6C);
    if (temp_r3 != NULL) {
        TKeyBoardControl__sub_8025CBCC((u8 *)temp_r3);
        release();
    }
}

void TKeyBoardControl__sub_802613A4(TKeyBoardControl *key_board_control) {
    *(s32 *)((s8 *)key_board_control + 0x60) = (s32) (*(s32 *)((s8 *)key_board_control + 0x60) | 0x20);
    if (*(void **)((s8 *)key_board_control + 0x6C) != NULL) {
        TKeyBoardControl__sub_8025CC04((u8 *)(*(void **)((s8 *)key_board_control + 0x6C)));
        key_board_control->release();
    }
}

void TKeyBoardControl::release() {
    if ((u32) *(u32 *)((s8 *)this + 0x6C) != 0U) {
        *(s32 *)((s8 *)this + 0x60) = (s32) (*(s32 *)((s8 *)this + 0x60) | 1);
        TKeyBoardControl__sub_8025CC3C((void *)(*(u32 *)((s8 *)this + 0x6C)));
        TWindowKeyBoardSoft__sub_80261134(this);
    }
}

void TWindowKeyBoardSoft::close() { if (*(unsigned int*)((char*)this + 0x6c) != 0) { update_keyboard_close_mode(*(void**)((char*)this + 0x6c)); update_focus_flags(); } }

s32 TWindowKeyBoardSoft::hit_test_relative(u8 *arg1, u8 *arg2) {
    u8 *arg0 = (u8 *)this;
    f32 temp_f3;
    f32 temp_f5;
    temp_f3 = *(f32 *)((s8 *)arg2 + 4);
    temp_f5 = *(f32 *)((s8 *)arg2 + 0);
    return TWindowKeyBoardSoft__sub_802614DC(arg0, arg1, temp_f5 - *(f32 *)((s8 *)arg1 + 0), temp_f3 - *(f32 *)((s8 *)arg1 + 4), *(f32 *)((s8 *)arg2 + 8) - temp_f5, *(f32 *)((s8 *)arg2 + 0xC) - temp_f3) >= TWindowKeyBoardSoft__data_805DD078;
}

f32 TWindowKeyBoardSoft__sub_802614DC(u8 *window_sub_com_card, u8 *arg1, f32 farg0, f32 farg1, f32 farg2, f32 farg3) {
    f32 t;
    f32 v;

    t = ((TWindowSubComCard *)window_sub_com_card)->get_normalized_progress();
    if (t >= 1.0f) {
        return 1.0f;
    }
    v = (t * (*(f32 *)((s8 *)arg1 + 8) + *(f32 *)((s8 *)arg1 + 0xC))) - (farg0 + farg1);
    if (v <= 0.0f) {
        return 0.0f;
    }
    v = v / (farg2 + farg3);
    if (v >= 1.0f) {
        v = 1.0f;
    }
    return v;
}

#pragma push
#pragma fp_contract on
void TWindowKeyBoardSoft::spawn_key_effect(s32 arg1, s32 arg2) {
    s32 type;
    Vec2_802615B8 pos;
    s32 kind;

    ((void (*)(void *, s32, s32 *, s32))TWindowKeyBoardSoft__sub_80260760)(this, ((s32 (*)(void *, s32, s32))calc_key_index__19TWindowKeyBoardSoftFiii)(this, arg1, arg2), &type, 0);
    pos.x = *(f32 *)(((u8 *)this) + 0x40) + ((f32 (*)(void *, s32, s32))calc_key_x__19TWindowKeyBoardSoftFiii)(this, arg1, arg2);
    pos.y = TWindowKeyBoardSoft__data_805DD094 + (TWindowKeyBoardSoft__data_805DD088 + (TWindowKeyBoardSoft__data_805DD07C * (f32)arg2 + *(f32 *)(((u8 *)this) + 0x44)));
    switch (type) {
    case 1:
        kind = 3;
        break;
    case 2:
        kind = 4;
        break;
    case 4:
        kind = 5;
        break;
    case 10:
        kind = 6;
        break;
    }
    TWindowEffectLight::create(&pos, (void *)kind, (void *)local_client_id);
}
#pragma pop

void TWindowKeyBoardSoft__sub_80261DD8(TWindowKeyBoardSoft *self, TWindowKeyBoardSoft *ctx) {
    Vec2_802615B8 v[5];
    u32 col[5];
    Lines_80261DD8 d;
    f32 depth;
    u8 *res;

    depth = 0.0598f + ctx->depth;
    res = TWindowKeyBoardSoft__language_text_resources;
    d.verts = v;
    d.colors = col;
    d.f8 = 0;
    d.colors[0] = (ctx->color & 0xFF000000) | 0xA6B3;
    d.colors[1] = d.colors[0];
    d.colors[2] = d.colors[0];
    d.colors[3] = d.colors[0];
    d.colors[4] = d.colors[0];
    d.count = 5;
    v[0].x = (1.0f + ctx->x) - 1.0f;
    v[0].y = (26.0f + ctx->y) - 1.0f;
    v[1].x = 3.0f + (304.0f + v[0].x);
    v[1].y = v[0].y;
    v[2].x = v[1].x;
    v[2].y = 3.0f + (133.0f + v[0].y);
    v[3].x = v[0].x;
    v[3].y = v[2].y;
    ctx->scale_point_about_pivot(&v[0].x);
    ctx->scale_point_about_pivot(&v[1].x);
    ctx->scale_point_about_pivot(&v[2].x);
    ctx->scale_point_about_pivot(&v[3].x);
    v[4].x = v[0].x;
    v[4].y = v[0].y;
    draw_color_lines(&d, 5, 0x14, depth);
    v[0].x = (ctx->x + TWindowKeyBoardSoft__sub_802606E0(self)) - 1.0f;
    v[0].y = (-1.0f + ctx->y) - 1.0f;
    v[1].x = 3.0f + (v[0].x + (f32)(res[0] * res[1]));
    v[1].y = v[0].y;
    v[2].x = 3.0f + (v[0].x + (f32)(res[0] * res[1]));
    v[2].y = 2.0f + (20.0f + v[0].y);
    v[3].x = v[0].x;
    v[3].y = v[2].y;
    ctx->scale_point_about_pivot(&v[0].x);
    ctx->scale_point_about_pivot(&v[1].x);
    ctx->scale_point_about_pivot(&v[2].x);
    ctx->scale_point_about_pivot(&v[3].x);
    v[4].x = v[0].x;
    v[4].y = v[0].y;
    draw_color_lines(&d, 5, 0x14, depth);
}

void TWindowKeyBoardSoft::draw_key_frame(void *self, f32 *rect, u32 color, s32 idx, f32 x0, f32 y, f32 w, f32 scale) {
    Quad_80262038 q;
    f32 v;
    f32 y2;
    f32 x2;
    f32 x3;
    f32 x4;
    UV_80262038 *uv;

    v = ((f32 (*)(void *, f32, f32, f32, f32))TWindowKeyBoardSoft__sub_802614DC)(self, x0, y, w, 20.0f);
    if (v <= TWindowKeyBoardSoft__data_805DD090) {
        return;
    }
    if (v < TWindowKeyBoardSoft__data_805DD078) {
        color = ((u32)(lbl_805DD0C8 * v) << 24) | (color & 0x00FFFFFF);
    }
    x0 += rect[0];
    y += rect[1];
    uv = &keyboard_key_frame_uv_table[idx];
    set_constant_material_color(color);
    x2 = 10.0f + x0;
    y2 = 20.0f + y;
    q.x = x0;
    q.y = y;
    q.x2 = x2;
    q.y2 = y2;
    q.u = uv->u / 256.0f;
    q.v = uv->v / 256.0f;
    q.u2 = (10.0f + uv->u) / 256.0f;
    q.v2 = (20.0f + uv->v) / 256.0f;
    apply_context_transform_to_rect(rect, &q);
    draw_textured_quad_at_depth((f32 *)&q, scale);
    x3 = x0 + w;
    x4 = x3 - 10.0f;
    q.x = x4;
    q.y = y;
    q.x2 = x3;
    q.y2 = y2;
    q.u = (10.0f + uv->u) / 256.0f;
    q.v = uv->v / 256.0f;
    q.u2 = (20.0f + uv->u) / 256.0f;
    q.v2 = (20.0f + uv->v) / 256.0f;
    apply_context_transform_to_rect(rect, &q);
    draw_textured_quad_at_depth((f32 *)&q, scale);
    if (w <= 20.0f) {
        return;
    }
    q.x = x2;
    q.y = y;
    q.x2 = x4;
    q.y2 = y2;
    q.u = (10.0f + uv->u) / 256.0f;
    q.v = uv->v / 256.0f;
    q.u2 = (10.0f + uv->u) / 256.0f;
    q.v2 = (20.0f + uv->v) / 256.0f;
    apply_context_transform_to_rect(rect, &q);
    draw_textured_quad_at_depth((f32 *)&q, scale);
}

void TWindowKeyBoardSoft::render() {
    s32 temp_r3;
    temp_r3 = draw_default_entry__9TWindowDDFl();
    TWindowKeyBoardSoft__sub_8026227C(this, (int)temp_r3);
    TWindowKeyBoardSoft__sub_80261DD8(this, (TWindowKeyBoardSoft *)temp_r3);
    TWindowKeyBoardSoft__sub_802616BC(this, (int)temp_r3);
}

}
