#include "types.h"
#include "pso/ui/keyboard/TKeyBoardControl_8025CB70.h"
#include "pso/ui/window/TWindowSubMag_802627D8.h"
#include "pso/ui/window/TWindowSubStatusDisp_803DEE6C.h"
#include "pso/ui/window/TWindowKeyBoardSoft.h"
#include "pso/ui/window/TWindowKeyBoardSoft_8025B85C.h"
#include "pso/ui/window/TWindowChoiceSetting.h"
#include "pso/ui/frontend/TAdMultiPlyChrSelectGC.h"
#include "pso/ui/Language.h"
#include "pso/ui/window/TWindowKeyBoardBase.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/unk/text_80076BC4.h"
#include "pso/ui/window/TWindowSubStatusDisp_80144B14.h"
#include "pso/ui/window/TWindowCtrl_8024A054.h"
#include "pso/ui/window/TWindowKeyBoardSoft_80261440.h"
#include "pso/ui/window/TWindowDD.h"
#include "pso/unk/WindowLayoutRecord.h"
#include "pso/unk/text_8026C664.h"
#include "pso/object/ambient/TObjFish.h"

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

// TWindowKeyBoardSoft ctor descriptor; first object of the TU .data (0x804CFDE0).
WindowDescriptor soft_keyboard_window_and_action_data = { {307.0f, 161.0f}, 50040.0f, NULL, 0x803 };

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
void calc_cursor_step__19TWindowKeyBoardSoftFiPvPv(TWindowKeyBoardSoft *arg0, s32 *arg1, s32 *arg2);
f32 calc_key_x__19TWindowKeyBoardSoftFiii(TWindowKeyBoardSoft *arg0, s32 arg1, s32 arg2);
s32 calc_key_index__19TWindowKeyBoardSoftFiii(TWindowKeyBoardSoft *arg1, s32 arg2, s32 arg3);
f32 TWindowKeyBoardSoft__sub_802606E0(TWindowKeyBoardSoft *);
void TWindowKeyBoardSoft__sub_80260760(void *self, s32 key, s32 *count, u32 *color);
void TWindowKeyBoardSoft__sub_80260E30(void *self, s32 port);
void TWindowKeyBoardSoft__sub_80261134(void *self);
extern u8 lbl_8044F138[];
void TKeyBoardControl__sub_802613A4(TKeyBoardControl *arg0);
f32 TWindowKeyBoardSoft__sub_802614DC(u8 *, u8 *, f32, f32, f32, f32);
void TWindowKeyBoardSoft__sub_802616BC(TWindowKeyBoardSoft *, TWindowKeyBoardSoft *);
void TWindowKeyBoardSoft__sub_80261DD8(TWindowKeyBoardSoft *, TWindowKeyBoardSoft *);
void TWindowKeyBoardSoft__sub_8026227C(TWindowKeyBoardSoft *, TWindowKeyBoardSoft *);
extern s32 lbl_805D63F0;
s32 get_flag_bit5__19TWindowKeyBoardSoftFv();

extern RecoveredGlobal_8026062C_TWindowKeyBoardSoft__data_8044F124 TWindowKeyBoardSoft__data_8044F124;
extern RecoveredGlobal_8026062C_TWindowKeyBoardSoft__data_804CB7C8 TWindowKeyBoardSoft__data_804CB7C8;
extern u8 *TWindowKeyBoardSoft__language_text_resources;
extern RecoveredGlobal_80260808_lbl_8050E208 controller_input_state;
extern void *local_client_id;
void apply_context_transform_to_rect(void *, void *);
void draw_color_lines(Lines_80261DD8 *l, s32 n, s32 flags, f32 scale);
extern UV_80262038 keyboard_key_frame_uv_table[];

void calc_cursor_step__19TWindowKeyBoardSoftFiPvPv(TWindowKeyBoardSoft *arg0, s32 *arg1, s32 *arg2) {
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
    s32 idx = calc_key_index__19TWindowKeyBoardSoftFiii(this, (s32)(((Win_802605DC *)this)->f65), (s32)(((Win_802605DC *)this)->f66));
    return idx + ((s8 *)&TWindowKeyBoardSoft__data_8044F124)[((u8 *)&TWindowKeyBoardSoft__data_804CB7C8)[idx]];
}
#pragma pop

#pragma push
#pragma fp_contract on
f32 calc_key_x__19TWindowKeyBoardSoftFiii(TWindowKeyBoardSoft *arg0, s32 arg1, s32 arg2) {
  f32 new_var;
  s32 sp8;
  s32 temp_r31;
  s32 temp_r3;
  temp_r3 = calc_key_index__19TWindowKeyBoardSoftFiii(arg0, arg1, arg2);
  temp_r31 = arg1 + ((s8) (*((u8 *) (((s8 *) (((u8 *)&TWindowKeyBoardSoft__data_8044F124.value) + (*((u8 *) (((s8 *) (((u8 *)&TWindowKeyBoardSoft__data_804CB7C8.value) + temp_r3)) + 0))))) + 0))));
  TWindowKeyBoardSoft__sub_80260760((void *) arg0, (int) temp_r3, &sp8, NULL);
  new_var = TWindowKeyBoardSoft::calc_key_coord((s32)arg0, sp8);
  return 1.0f + ((19.0f * ((f32) temp_r31)) + (0.5f * new_var));
}
#pragma pop

#pragma push
#pragma fp_contract on
s32 calc_key_index__19TWindowKeyBoardSoftFiii(TWindowKeyBoardSoft *arg1, s32 arg2, s32 arg3) {
    return arg2 + (arg3 * 0x10);
}
#pragma pop

#pragma push
#pragma fp_contract on
#pragma fp_contract on
f32 TWindowKeyBoardSoft__sub_802606E0(TWindowKeyBoardSoft *) {
    return -((0.5f * (f32) (*(u8 *)((s8 *)TWindowKeyBoardSoft__language_text_resources + 0) * *(u8 *)((s8 *)TWindowKeyBoardSoft__language_text_resources + 1))) - 153.0f);
}
#pragma pop

#pragma push
#pragma fp_contract on
#pragma fp_contract on
f32 TWindowKeyBoardSoft::calc_key_coord(s32 arg0, s32 arg1) {
    return (19.0f * (f32) arg1) + 1.0f;
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
    s8 layout;
    s8 cursor_x;
    s8 cursor_y;
    u8 pad_67;
    f32 pad_68; /* inferred: decaying tab-bar fade, 0.0 in the ctor */
    TWindowKeyBoardSoft *child;
};

/* Layout table of the soft keyboard: one 16-column key-code grid per page. */
struct SoftKeyLayout_80260904 {
    u8 page_count; /* inferred: bound of the page-tab loop */
    u8 tab_width;  /* inferred: page tab width in pixels */
    u8 pad_2[2];
    u16 **pages;
};

void TWindowKeyBoardSoft__sub_80260904(void *self, s32 port) {
    KeyCursor_80260E30 *kb = (KeyCursor_80260E30 *)self;
    SoftKeyLayout_80260904 *layout = (SoftKeyLayout_80260904 *)TWindowKeyBoardSoft__language_text_resources;
    static void (TWindowKeyBoardSoft::*key_actions[])() = {
        &TWindowKeyBoardSoft::vt0,  &TWindowKeyBoardSoft::vt1,  &TWindowKeyBoardSoft::vt2,
        &TWindowKeyBoardSoft::vt3,  &TWindowKeyBoardSoft::vt4,  &TWindowKeyBoardSoft::vt5,
        &TWindowKeyBoardSoft::vt6,  &TWindowKeyBoardSoft::vt7,  &TWindowKeyBoardSoft::vt8,
        &TWindowKeyBoardSoft::vt9,  &TWindowKeyBoardSoft::vt10, &TWindowKeyBoardSoft::vt11,
        &TWindowKeyBoardSoft::vt12, &TWindowKeyBoardSoft::vt13, &TWindowKeyBoardSoft::vt14,
        &TWindowKeyBoardSoft::vt15, &TWindowKeyBoardSoft::vt16, &TWindowKeyBoardSoft::vt17,
        &TWindowKeyBoardSoft::vt18, &TWindowKeyBoardSoft::vt19, &TWindowKeyBoardSoft::vt20,
        &TWindowKeyBoardSoft::vt21,
    };
    u16 code;

    if (TWindowShortListCtrl__check_controller_button((u8 *)&controller_input_state.value + port * 0x50 + 0x20, 4, port * 0x50) == 0) {
        return;
    }
    if (kb->child == NULL) {
        return;
    }
    if (!(kb->flags & 1)) {
        ((TWindowKeyBoardSoft *)self)->update_focus_flags();
    }
    ((TWindowKeyBoardSoft *)self)->spawn_key_effect(kb->cursor_x, kb->cursor_y);
    if (kb->flags & 0x10) {
        kb->child->vt0();
        if (kb->child->is_key_state_2() == 0) {
            kb->flags &= ~0x10;
        }
        return;
    }
    code = *(layout->pages[kb->layout] + kb->cursor_x + kb->cursor_y * 16);
    if (code >= 3 && code <= 14) {
        if (TWindowSubMag__sub_80262808(kb->child) != 0) {
            play_sound_effect(0x53F06, 0, 0, 0);
        } else if (*(u32 *)get_chat_shortcut(code + 5) != 3) {
            play_sound_effect(0x52D01, 0, 0, 0);
        }
    } else if (code == 2 && (kb->flags & 8)) {
        play_sound_effect(0x53F06, 0, 0, 0);
    } else {
        play_sound_effect(0x52D01, 0, 0, 0);
    }
    if (code < 0x20) {
        if (code < 22) {
            (kb->child->*key_actions[code])();
        }
        return;
    }
    if (((TWindowKeyBoardSoft *)self)->get_flag_bit5() != 0 && (code < 'A' || code > 'Z')) {
        return;
    }
    if (((TWindowKeyBoardSoft *)self)->get_flag_bit6() != 0 && TWindowKeyBoardSoft::is_alnum(code) == 0) {
        return;
    }
    if (((TWindowKeyBoardSoft *)self)->is_cursor_locked() != 0 && (code < '0' || code > '9')) {
        return;
    }
    ((TWindowSubStatusDisp *)kb->child)->set_input_mode(2);
    ((TWindowKeyBoardBase *)kb->child)->insert_character(code);
}

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
        calc_cursor_step__19TWindowKeyBoardSoftFiPvPv(this, &spC, &sp8);
        if (((s32 (*)(int, int))TWindowShortListCtrl__check_controller_button)((int)temp_r30, 0x10000) != 0) {
            *(f32 *)((s8 *)((u8 *)this) + 0x68) = 10.0f;
            *(u8 *)((s8 *)((u8 *)this) + 0x64) = (u8) (*(u8 *)((s8 *)((u8 *)this) + 0x64) + 1);
        }
        if (((s32 (*)(int, int))TWindowShortListCtrl__check_controller_button)((int)temp_r30, 0x20000) != 0) {
            *(f32 *)((s8 *)((u8 *)this) + 0x68) = -10.0f;
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
    return TWindowKeyBoardSoft__sub_802614DC(arg0, arg1, temp_f5 - *(f32 *)((s8 *)arg1 + 0), temp_f3 - *(f32 *)((s8 *)arg1 + 4), *(f32 *)((s8 *)arg2 + 8) - temp_f5, *(f32 *)((s8 *)arg2 + 0xC) - temp_f3) >= 1.0f;
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

    ((void (*)(void *, s32, s32 *, s32))TWindowKeyBoardSoft__sub_80260760)(this, calc_key_index__19TWindowKeyBoardSoftFiii(this, arg1, arg2), &type, 0);
    pos.x = *(f32 *)(((u8 *)this) + 0x40) + calc_key_x__19TWindowKeyBoardSoftFiii(this, arg1, arg2);
    pos.y = 26.0f + (10.0f + (19.0f * (f32)arg2 + *(f32 *)(((u8 *)this) + 0x44)));
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

/* Function keys below the character grid: grid cell, size and texture origin. */
extern const Vec2_802615B8 lbl_8044F164[10];
extern const Vec2_802615B8 lbl_8044F1B4[10];
extern const UV_80262038 lbl_8044F204[10];

#pragma push
#pragma fp_contract on
void TWindowKeyBoardSoft__sub_802616BC(TWindowKeyBoardSoft *self, TWindowKeyBoardSoft *ctx) {
    u32 tab_color;
    u32 page;
    s32 cursor;
    s32 first_page;
    u32 i;
    u32 row;
    s32 last_page;
    KeyCursor_80260E30 *kb;
    u16 *keys;
    u32 col;
    f32 depth;
    SoftKeyLayout_80260904 *layout;
    s32 key;
    f32 tab_x;
    Quad_80262038 q;
    u32 color;

    kb = (KeyCursor_80260E30 *)self;
    layout = (SoftKeyLayout_80260904 *)TWindowKeyBoardSoft__language_text_resources;
    depth = -1.0f / (0.1196f + ctx->depth);
    cursor = self->sub_802605DC();
    keys = layout->pages[kb->layout];
    TWindowSubStatusDisp::reset_gauge(NULL);
    for (row = 0; row < 7; row++) {
        for (col = 0; col < 16; col++) {
            u16 code = *keys++;
            if (code < 0x20) {
                continue;
            }
            if (self->get_flag_bit5() != 0 && (code < 'A' || code > 'Z')) {
                code = 22;
            }
            if (self->get_flag_bit6() != 0 && TWindowKeyBoardSoft::is_alnum(code) == 0) {
                code = 22;
            }
            if (self->is_cursor_locked() != 0 && (code < '0' || code > '9')) {
                code = 22;
            }
            if (code != 22) {
                u8 width;
                code = map_char_to_font_code(code);
                key = calc_key_index__19TWindowKeyBoardSoftFiii(self, col, row);
                color = key == cursor ? 0xFF000000 : 0xFF999999;
                q.x = 1.0f + (1.0f + (19.0f * (f32)col + ctx->x));
                q.y = 1.0f + (26.0f + (ctx->y + 19.0f * (f32)row));
                width = calc_gauge_scale__20TWindowSubStatusDispFPvPvi(code, &q, color);
                q.x = 0.5f * (f32)(18 - width) + q.x;
                set_glyph_quad_extents(width, (u8 *)&q);
                if (self->hit_test_relative((u8 *)ctx, (u8 *)&q) != 0) {
                    apply_context_transform_to_rect(ctx, &q);
                    draw_textured_quad_at_depth((f32 *)&q, depth);
                }
            }
        }
    }
    TWindowSubStatusDisp::end_render_forward();
    begin_screen_draw(1);
    TWindowSubStatusDisp::render_forward();
    set_draw_texture_and_color(0, 0xFF999999);

    key = calc_key_index__19TWindowKeyBoardSoftFiii(self, 2, 0);
    for (i = 0; i < 12; i++, key++) {
        q.x = 1.0f + (1.0f + (19.0f * (f32)(i + 2) + ctx->x));
        q.y = 1.0f + (26.0f + ctx->y);
        q.x2 = 18.0f + q.x;
        q.y2 = 18.0f + q.y;
        q.u = 18.0f * (f32)i / 256.0f;
        q.v = 0.0f;
        q.u2 = 18.0f * (f32)(i + 1) / 256.0f;
        q.v2 = 18.0f / 256.0f;
        if (self->hit_test_relative((u8 *)ctx, (u8 *)&q) != 0) {
            set_constant_material_color(key == cursor ? 0xFF000000 : 0xFF999999);
            apply_context_transform_to_rect(ctx, &q);
            draw_textured_quad_at_depth((f32 *)&q, depth);
        }
    }
    TWindowSubStatusDisp::begin_render();
    set_draw_texture_and_color(3, 0xFF999999);

    tab_x = TWindowKeyBoardSoft__sub_802606E0(self);
    calc_cursor_step__19TWindowKeyBoardSoftFiPvPv(self, &first_page, &last_page);
    for (page = 0; page < layout->page_count; page++) {
        if (page == kb->layout) {
            tab_color = 0xFF000000;
        } else if (page < first_page) {
            tab_color = 0xFF646464;
        } else if (page > last_page) {
            tab_color = 0xFF646464;
        } else {
            tab_color = 0xFF999999;
        }
        q.x = 1.0f + (ctx->x + tab_x);
        q.y = 1.0f + (-1.0f + ctx->y);
        q.x2 = (q.x + (f32)layout->tab_width) - 2.0f;
        q.y2 = 18.0f + q.y;
        q.u = 0.0f;
        q.v = 18.0f * (f32)page / 128.0f;
        q.u2 = ((f32)layout->tab_width - 2.0f) / 128.0f;
        q.v2 = 18.0f * (f32)(page + 1) / 128.0f;
        if (self->hit_test_relative((u8 *)ctx, (u8 *)&q) != 0) {
            apply_context_transform_to_rect(ctx, &q);
            set_constant_material_color(tab_color);
            draw_textured_quad_at_depth((f32 *)&q, depth);
        }
        tab_x += (f32)layout->tab_width;
    }

    for (i = 0; i < 10; i++) {
        f32 x;
        key = calc_key_index__19TWindowKeyBoardSoftFiii(self, (s32)lbl_8044F164[i].x, (s32)lbl_8044F164[i].y);
        color = key == cursor ? 0xFF000000 : 0xFF999999;
        x = ctx->x + calc_key_x__19TWindowKeyBoardSoftFiii(self, (s32)lbl_8044F164[i].x, (s32)lbl_8044F164[i].y);
        q.x = x - 0.5f * lbl_8044F1B4[i].x;
        q.y = 1.0f + (26.0f + (19.0f * lbl_8044F164[i].y + ctx->y));
        q.x2 = q.x + lbl_8044F1B4[i].x;
        q.y2 = q.y + lbl_8044F1B4[i].y;
        q.u = lbl_8044F204[i].u / 128.0f;
        q.v = lbl_8044F204[i].v / 128.0f;
        q.u2 = (lbl_8044F204[i].u + lbl_8044F1B4[i].x) / 128.0f;
        q.v2 = (lbl_8044F204[i].v + lbl_8044F1B4[i].y) / 128.0f;
        if (self->hit_test_relative((u8 *)ctx, (u8 *)&q) != 0) {
            set_constant_material_color(color);
            apply_context_transform_to_rect(ctx, &q);
            draw_textured_quad_at_depth((f32 *)&q, depth);
        }
    }
    TWindowSubStatusDisp::get_player();
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

void TWindowKeyBoardSoft::draw_key_frame(void *self, f32 *rect, f32 x0, f32 y, f32 w, f32 scale, u32 color, s32 idx) {
    Quad_80262038 q;
    f32 v;
    f32 y2;
    f32 x2;
    f32 x3;
    f32 x4;
    UV_80262038 *uv;

    v = ((f32 (*)(void *, f32, f32, f32, f32))TWindowKeyBoardSoft__sub_802614DC)(self, x0, y, w, 20.0f);
    if (v <= 0.0f) {
        return;
    }
    if (v < 1.0f) {
        color = ((u32)(255.0f * v) << 24) | (color & 0x00FFFFFF);
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

#pragma push
#pragma fp_contract on
/* Key frames of the character grid and the page tabs, then the tab bar ends. */
void TWindowKeyBoardSoft__sub_8026227C(TWindowKeyBoardSoft *self, TWindowKeyBoardSoft *ctx) {
    KeyCursor_80260E30 *kb = (KeyCursor_80260E30 *)self;
    s32 cursor;
    SoftKeyLayout_80260904 *layout = (SoftKeyLayout_80260904 *)TWindowKeyBoardSoft__language_text_resources;
    f32 depth = -1.0f / ctx->depth;
    s32 i;
    s32 j;
    s32 key;
    s32 count;
    u32 color;
    s32 frame;
    f32 tab_x;
    s32 first_page;
    s32 last_page;

    cursor = self->sub_802605DC();
    begin_screen_draw(1);
    TObjFish::set_global_param(lbl_805D63F0);
    set_draw_texture_and_color(0, -1);
    for (j = 0; j < 7; j++) {
        for (i = 0; i < 16; i += count) {
            key = calc_key_index__19TWindowKeyBoardSoftFiii(self, i, j);
            TWindowKeyBoardSoft__sub_80260760(self, key, &count, &color);
            f32 w = TWindowKeyBoardSoft::calc_key_coord((s32)self, count);
            if (key == cursor) {
                color = 0xFFFFFFFF;
                frame = 1;
            } else {
                frame = 0;
            }
            TWindowKeyBoardSoft::draw_key_frame(self, (f32 *)ctx, 19.0f * (f32)i + 1.0f, 19.0f * (f32)j + 26.0f, w, depth, color, frame);
        }
    }

    tab_x = TWindowKeyBoardSoft__sub_802606E0(self);
    calc_cursor_step__19TWindowKeyBoardSoftFiPvPv(self, &first_page, &last_page);
    for (i = 0; i < layout->page_count; i++) {
        if (i == kb->layout) {
            color = 0xFFFFFFFF;
            frame = 2;
        } else {
            if (i < first_page) {
                color = 0xFF4D4D4D;
            } else if (i > last_page) {
                color = 0xFF4D4D4D;
            } else {
                color = 0xFF0C5B38;
            }
            frame = 0;
        }
        TWindowKeyBoardSoft::draw_key_frame(self, (f32 *)ctx, tab_x, -1.0f, (f32)(layout->tab_width + 1), depth, color, frame);
        tab_x += (f32)layout->tab_width;
    }

    set_constant_material_color(ctx->color);
    tab_x = TWindowKeyBoardSoft__sub_802606E0(self);
    fn_8026C664((u8 *)ctx, (ctx->x + tab_x) - 34.0f, 3.0f + (-1.0f + ctx->y), depth, kb->pad_68);
    tab_x += 1.0f + (f32)(layout->tab_width * layout->page_count);
    fn_8026C708((u8 *)ctx, 5.0f + (ctx->x + tab_x),
                3.0f + (-1.0f + ctx->y), depth, kb->pad_68);
    TWindowSubStatusDisp::get_player();
}
#pragma pop

void TWindowKeyBoardSoft::render() {
    s32 temp_r3;
    temp_r3 = draw_default_entry__9TWindowDDFl();
    TWindowKeyBoardSoft__sub_8026227C(this, (TWindowKeyBoardSoft *)temp_r3);
    TWindowKeyBoardSoft__sub_80261DD8(this, (TWindowKeyBoardSoft *)temp_r3);
    TWindowKeyBoardSoft__sub_802616BC(this, (TWindowKeyBoardSoft *)temp_r3);
}

}

#pragma push
#pragma fp_contract on

extern "C" {

s32 sub_80244994__11TWindowBaseFv();
s32 update_fade__11TWindowBaseFv(void *);
s32 initialize_subwindow__9TWindowDDFv(void *);


void TWindowKeyBoardSoft::run_task() {
    f32 temp_f0;
    s32 temp_r3;

    if ((u32) *(u32 *)((s8 *)this + 0x6C) != 0U) {
        if ((sub_80244994__11TWindowBaseFv() != 0) && (((TKeyBoardControl *)(*(u32 *)((s8 *)this + 0x6C)))->is_key_active() == 0)) {
            temp_r3 = is_player_input_active(*(s16 *)((s8 *)this + 0x20));
            handle_page_cycle_input(temp_r3);
            TWindowKeyBoardSoft__sub_80260E30(this, temp_r3);
            TWindowKeyBoardSoft__sub_80260904(this, temp_r3);
            update_keyboard_child_input_from_controller(temp_r3);
            sub_80260808(temp_r3);
        }
        initialize_subwindow__9TWindowDDFv(this);
        update_fade__11TWindowBaseFv(this);
        *(f32 *)((s8 *)this + 0x68) -= 0.15f * *(f32 *)((s8 *)this + 0x68);
    }
}

}

#pragma pop

struct RecoveredGlobal_80262740_lbl_804D0004 {
    s32 value;
    u8 remaining[0x18];
};

extern "C" {
s32 construct_base__9TWindowDDFPUcsPUc(void *, void *, void *, int);
s32 get_window_layout_position(int);
extern s32 __vt__19TWindowKeyBoardSoft[];
extern s32 keyboard_soft_type_name_pointer;
void __dl__7TObjectFPv(void *);

void *__dt__19TWindowKeyBoardSoftFv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__19TWindowKeyBoardSoft;
        ((TWindowDD *)arg0)->destroy_window_base(0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}
typedef char RecoveredGlobal_80262740_lbl_804D0004_size[sizeof(RecoveredGlobal_80262740_lbl_804D0004) == 0x1C ? 1 : -1];
u8 *TWindowKeyBoardSoft__ct(u8 *arg0, s32 arg1, s16 arg2) {
    construct_base__9TWindowDDFPUcsPUc((void *)arg0, &soft_keyboard_window_and_action_data, (void *)arg2, (int) (get_window_layout_position(0xBA)));
    *(s32 **)((s8 *)arg0 + 0x18) = &(*(RecoveredGlobal_80262740_lbl_804D0004 *)&__vt__19TWindowKeyBoardSoft).value;
    *(s32 *)((s8 *)arg0 + 0) = (s32) keyboard_soft_type_name_pointer;
    *(s32 *)((s8 *)arg0 + 0x60) = 0;
    *(s8 *)((s8 *)arg0 + 0x64) = 0;
    *(s8 *)((s8 *)arg0 + 0x65) = 2;
    *(s8 *)((s8 *)arg0 + 0x66) = 1;
    *(f32 *)((s8 *)arg0 + 0x68) = 0.0f;
    *(s32 *)((s8 *)arg0 + 0x6C) = arg1;
    ((TWindowKeyBoardSoft *)arg0)->close();
    return arg0;
}

}
