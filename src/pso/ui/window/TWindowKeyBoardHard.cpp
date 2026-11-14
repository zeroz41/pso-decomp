#include "types.h"
#include "pso/ui/keyboard/TKeyBoardControl_8025CB70.h"
#include "pso/ui/keyboard/TKeyBoardControl_8025EC04.h"
#include "pso/unk/text_8025FF8C.h"
#include "pso/ui/window/TWindowKeyBoardBase.h"
#include "pso/ui/keyboard/KeyboardCharacterMaps.h"
#include "pso/ui/keyboard/TKeyBoardControl.h"
#include "pso/ui/window/TWindowKeyBoardHard.h"
#include "pso/ui/window/TWindowKeyBoardSoft.h"
#include "pso/ui/Language.h"
#include "pso/unk/WindowLayoutRecord.h"

const char *TWindowKeyBoardHard__name = "TWindowKeyBoardHard";
u8 keyboard_key_repeat_mask_table[4] = { 0x1D, 0x1F, 0x07, 0x00 };
// The vowels and N/Y that take an accent, upper and lower case in pairs.
const u8 *keyboard_accent_base_chars = (const u8 *)"AaEeIiOoUuNnYy";

struct RecoveredFields_8025FC60_arg0 {
    u8 unknown_0[0x60];
    s32 field_60;
    u8 unknown_64[0xC];
    u8 * field_70;
};

struct RecoveredGlobal_8025FC60_TKeyBoardControl__data_80506270 {
    s32 value;
    u8 remaining[0xAC];
};

struct Sub_8025EDB4 {
    u8 pad[0xB4];
    s32 flags;
};

struct Ctl_8025EDB4 {
    u8 pad[0x60];
    u32 flags;
    u8 pad64[0xC];
    Sub_8025EDB4 *sub;
};

struct Ctl_8025F21C { u8 p0[0x60]; u32 f60; };

struct TWindowKeyBoardSoft_8025F4A0 {
    u8 pad0[0xB4];
    u32 fB4;
};

struct Ctl_8025F4A0 {
    u8 pad0[0x20];
    s16 f20;
    u8 pad22[0x60 - 0x22];
    u32 f60;
    u8 pad64[0x70 - 0x64];
    TWindowKeyBoardSoft_8025F4A0 *f70;
};

extern "C" {

s32 TKeyBoardControl__sub_801321B4(void *);
s32 TKeyBoardControl__sub_80132274(void *);
s32 is_key_57_pressed__16TKeyBoardControlFi(void *);
s32 TKeyBoardControl__sub_801323C8(void *, int);
u8 get_key_state__16TKeyBoardControlFPv(s32 *);
extern s32 TKeyBoardControl__global_key_state[];
u8 TKeyBoardControl__sub_8013239C(void *, u8);
s32 TKeyBoardControl__sub_801A58B0(void);
s32 set_input_mode__20TWindowSubStatusDispFUc(s32, s32);

void TKeyBoardControl__sub_8025EC04(u8 *arg0) {
    *(s32 *)((s8 *)arg0 + 0x68) = 0;
    *(s32 *)((s8 *)arg0 + 0x60) = (s32) (*(s32 *)((s8 *)arg0 + 0x60) | 0x100);
}

s32 TKeyBoardControl::is_printable_key(void *arg0, u8 arg1) {
    if (arg1 == 0x52) {
        return 1;
    }
    if (arg1 < 0x10U) {
        return 0;
    }
    return arg1 <= 0x29U ? 1 : 0;
}

s32 TKeyBoardControl::has_non_modifier_key() {
    u32 i;
    u32 n;
    u8 c;
    if (TKeyBoardControl__sub_801A58B0() != 0) {
        return 0;
    }
    n = ((TKeyBoardControl *)TKeyBoardControl__global_key_state)->get_key_state_2();
    for (i = 0; i < n; i++) {
        c = TKeyBoardControl__sub_8013239C(TKeyBoardControl__global_key_state, i);
        if (c != 0x61 && c != 0x4C && c != 0x50 && c != 0x5E && c != 0x5D && c != 0x5C && c != 0x5F) {
            return 1;
        }
    }
    if (TKeyBoardControl__sub_801323C8(TKeyBoardControl__global_key_state, 0x55) != 0) {
        return 1;
    }
    if (TKeyBoardControl__sub_801323C8(TKeyBoardControl__global_key_state, 0x54) != 0) {
        return 1;
    }
    if (TKeyBoardControl__sub_801323C8(TKeyBoardControl__global_key_state, 0x56) != 0) {
        return 1;
    }
    return TKeyBoardControl__sub_801323C8(TKeyBoardControl__global_key_state, 0x57) != 0 ? 1 : 0;
}

u16 TWindowKeyBoardHard::lookup_key_char(u8 arg1) {
    u8 *arg0 = (u8 *)this;
    if (*(s32 *)((s8 *)arg0 + 0x60) & 0x80) {
        return keyboard_kana_shifted_map[arg1];
    }
    return keyboard_kana_unshifted_map[arg1];
}

#define arg0 ((Ctl_8025EDB4 *)arg0_)
s32 TKeyBoardControl::translate_key_char(void *arg0_, u8 arg1, u16 *arg2) {
    s32 shift;
    u32 f;
    u16 c;

    f = arg0->flags;
    if (f & 1) {
        shift = f & 0x20;
    } else if (TKeyBoardControl::is_printable_key(arg0, arg1) != 0) {
        shift = arg0->flags & 0x20;
    } else {
        shift = arg0->flags & 0x80;
    }
    if (!(arg0->sub->flags & 1) || get_key_state__16TKeyBoardControlFPv(TKeyBoardControl__global_key_state) != 0) {
        switch (get_key_state__16TKeyBoardControlFPv(TKeyBoardControl__global_key_state)) {
        case 0:
            if ((arg0->flags & 4) && current_language == LANGUAGE_JAPANESE) {
                *arg2 = keyboard_jp_symbol_map[arg1];
            } else if (shift != 0) {
                *arg2 = keyboard_jp_shifted_map[arg1];
            } else {
                *arg2 = keyboard_jp_unshifted_map[arg1];
            }
            break;
        case 2:
            if (arg0->flags & 8) {
                *arg2 = keyboard_fr_alternate_map[arg1];
            } else if (shift != 0) {
                *arg2 = keyboard_fr_shifted_map[arg1];
            } else {
                *arg2 = keyboard_fr_unshifted_map[arg1];
            }
            break;
        case 4:
            if (arg0->flags & 8) {
                *arg2 = keyboard_es_alternate_map[arg1];
            } else if (shift != 0) {
                *arg2 = keyboard_es_shifted_map[arg1];
            } else {
                *arg2 = keyboard_es_unshifted_map[arg1];
            }
            break;
        case 3:
            if (arg0->flags & 8) {
                *arg2 = keyboard_de_alternate_map[arg1];
            } else if (shift != 0) {
                *arg2 = keyboard_de_shifted_map[arg1];
            } else {
                *arg2 = keyboard_de_unshifted_map[arg1];
            }
            break;
        default:
            if (shift != 0) {
                *arg2 = keyboard_us_shifted_map[arg1];
            } else {
                *arg2 = keyboard_us_unshifted_map[arg1];
            }
            break;
        }
        if (arg0->sub->flags & 1) {
            return ((arg0->flags >> 7) & 1) ? 2 : 0;
        }
        return 1;
    }
    if (arg0->sub->flags & 2) {
        if (arg0->flags & 4) {
            *arg2 = keyboard_jp_symbol_map[arg1];
        } else if (shift != 0) {
            *arg2 = keyboard_jp_fullwidth_shifted_map[arg1];
        } else {
            *arg2 = keyboard_jp_fullwidth_unshifted_map[arg1];
        }
        return 1;
    }
    if (arg0->sub->flags & 4) {
        if (TKeyBoardControl::is_printable_key(arg0, arg1) != 0) {
            if (arg0->flags & 4) {
                *arg2 = keyboard_jp_symbol_map[arg1];
            } else if (shift != 0) {
                *arg2 = keyboard_jp_shifted_map[arg1];
            } else {
                *arg2 = keyboard_jp_unshifted_map[arg1];
            }
            return ((arg0->flags >> 7) & 1) ? 2 : 0;
        }
        if (arg0->flags & 4) {
            *arg2 = keyboard_jp_symbol_map[arg1];
        } else if (shift != 0) {
            *arg2 = keyboard_jp_fullwidth_shifted_map[arg1];
        } else {
            *arg2 = keyboard_jp_fullwidth_unshifted_map[arg1];
        }
        return 1;
    }
    *arg2 = ((TWindowKeyBoardHard *)arg0)->lookup_key_char(arg1);
    if (!(arg0->sub->flags & 8)) {
        return 1;
    }
    c = *arg2;
    if (c < 0x829F) {
        return 1;
    }
    if (c > 0x82F1) {
        return 1;
    }
    if (c > 0x82DD) {
        *arg2 = c + 1;
    }
    *arg2 += 0xA1;
    return 1;
}
#undef arg0

s32 TKeyBoardControl::get_input_mode() {
    Ctl_8025F21C *c = (Ctl_8025F21C *)this;
    if (c->f60 & 0x40) {
        return 3;
    }
    switch (current_language) {
    case LANGUAGE_ENGLISH:
    case LANGUAGE_FRENCH:
        return 0;
    case LANGUAGE_SPANISH:
        return 1;
    case LANGUAGE_GERMAN:
        return 2;
    case LANGUAGE_JAPANESE:
        return 3;
    }
    return (s32)c;
}

s32 TWindowKeyBoardHard::poll_input() {

    if (*(s32 *)((s8 *)this + 0x60) & 0x40) {
        return 3;
    }
    switch ((s32) get_key_state__16TKeyBoardControlFPv(TKeyBoardControl__global_key_state)) {
    case 4:
        return 1;
    case 2:
        return 0;
    case 3:
        return 2;
    default:
        return 3;
    }
}

WindowDescriptor lbl_804CFAD0 = { {0.0f, 0.0f}, 50030.0f, NULL, 0x823 };
__declspec(section ".data") u8 keyboard_repeat_key_codes[7] = { 0x60, 0xB4, 0x5E, 0x7E, 0xA8, 0xB0, 0xB8 };
u8 keyboard_layout_mode_table[7][7] = {
    { 0x07, 0x07, 0x07, 0x07, 0x07, 0x00, 0x00 },
    { 0x07, 0x07, 0x07, 0x00, 0x07, 0x00, 0x00 },
    { 0x07, 0x07, 0x07, 0x00, 0x07, 0x00, 0x00 },
    { 0x07, 0x07, 0x07, 0x07, 0x07, 0x00, 0x00 },
    { 0x07, 0x07, 0x07, 0x00, 0x07, 0x00, 0x00 },
    { 0x00, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00 },
    { 0x00, 0x07, 0x00, 0x00, 0x07, 0x00, 0x00 },
};
u8 keyboard_accent_composed_chars[7][7] = {
    { 0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0xC5, 0x00 },
    { 0xC8, 0xC9, 0xCA, 0x00, 0xCB, 0x00, 0x00 },
    { 0xCC, 0xCD, 0xCE, 0x00, 0xCF, 0x00, 0x00 },
    { 0xD2, 0xD3, 0xD4, 0xD5, 0xD6, 0x00, 0x00 },
    { 0xD9, 0xDA, 0xDB, 0x00, 0xDC, 0x00, 0x00 },
    { 0x00, 0x00, 0x00, 0xD1, 0x00, 0x00, 0x00 },
    { 0x00, 0xDD, 0x00, 0x00, 0xDF, 0x00, 0x00 },
};

u8 TWindowKeyBoardHard::sub_8025F2F8(u8 arg1) {
    u32 idx;
    s32 bit;
    const u8 *p;
    u32 i;
    u8 modes;
    u8 c;

    idx = *(u32 *)((u8 *)this + 0x6C);
    if (idx >= 7) {
        return arg1;
    }
    *(u32 *)((u8 *)this + 0x6C) = 7;
    bit = ((TKeyBoardControl *)this)->get_input_mode();
    for (i = 0, p = keyboard_accent_base_chars; (s32)*p != 0; i++, p++) {
        if (arg1 == *p) {
            modes = keyboard_layout_mode_table[i >> 1][idx];
            if (!(modes & (1 << bit))) {
                return arg1;
            }
            c = keyboard_accent_composed_chars[i >> 1][idx];
            if (i & 1) {
                return c + 0x20;
            }
            if (c == 0xDF) {
                return arg1;
            }
            return c;
        }
    }
    return arg1;
}

s32 TWindowKeyBoardHard::lookup_key_repeat_state(u8 arg1, u8 arg2) {
    u32 st;
    u32 i;

    st = poll_input();
    if (st == 0U && arg1 == 0x32) {
        return 0;
    }
    for (i = 0; i < 7; i++) {
        if (arg2 == keyboard_repeat_key_codes[i]) {
            if (!(keyboard_key_repeat_mask_table[st] & (1 << i))) {
                return 0;
            }
            if (*(u32 *)((s8 *)this + 0x6C) == i) {
                *(u32 *)((s8 *)this + 0x6C) = 7;
                return 0;
            }
            *(u32 *)((s8 *)this + 0x6C) = i;
            return 1;
        }
    }
    return 0;
}
extern u8 keyboard_jp_unshifted_map[];
extern u8 keyboard_us_unshifted_map[];
extern u8 keyboard_fr_unshifted_map[];
extern u8 keyboard_de_unshifted_map[];
extern u8 keyboard_es_unshifted_map[];

s32 TWindowKeyBoardHard::sub_8025F4A0(u8 arg1) {
    static void (TWindowKeyBoardSoft::*control_key_handlers[26])() = {
        &TWindowKeyBoardSoft::vt0,
        &TWindowKeyBoardSoft::vt21,
        &TWindowKeyBoardSoft::vt3,
        &TWindowKeyBoardSoft::vt4,
        &TWindowKeyBoardSoft::vt5,
        &TWindowKeyBoardSoft::vt6,
        &TWindowKeyBoardSoft::vt7,
        &TWindowKeyBoardSoft::vt8,
        &TWindowKeyBoardSoft::vt9,
        &TWindowKeyBoardSoft::vt10,
        &TWindowKeyBoardSoft::vt11,
        &TWindowKeyBoardSoft::vt12,
        &TWindowKeyBoardSoft::vt13,
        &TWindowKeyBoardSoft::vt14,
        &TWindowKeyBoardSoft::sub_8025B928,
        &TWindowKeyBoardSoft::sub_8025BA44,
        &TWindowKeyBoardSoft::sub_8025BA28,
        &TWindowKeyBoardSoft::sub_8025B92C,
        &TWindowKeyBoardSoft::update_input_state,
        &TWindowKeyBoardSoft::vt1,
        &TWindowKeyBoardSoft::vt20,
        &TWindowKeyBoardSoft::vt15,
        &TWindowKeyBoardSoft::vt16,
        &TWindowKeyBoardSoft::vt17,
        &TWindowKeyBoardSoft::vt18,
        &TWindowKeyBoardSoft::vt19,
    };
    s32 busy;
    u32 t;
    TWindowKeyBoardSoft_8025F4A0 *w;

    busy = current_language;
    switch (get_key_state__16TKeyBoardControlFPv(TKeyBoardControl__global_key_state)) {
    case 0:
        arg1 = keyboard_jp_unshifted_map[arg1];
        break;
    case 2:
        arg1 = keyboard_fr_unshifted_map[arg1];
        break;
    case 4:
        arg1 = keyboard_es_unshifted_map[arg1];
        break;
    case 3:
        arg1 = keyboard_de_unshifted_map[arg1];
        break;
    default:
        arg1 = keyboard_us_unshifted_map[arg1];
        break;
    }
    if (arg1 > 31) {
        return 0;
    }
    if (arg1 < 26) {
        (((TWindowKeyBoardSoft *)((Ctl_8025F4A0 *)this)->f70)->*control_key_handlers[arg1])();
        return 1;
    }
    switch (arg1) {
    case 30:
        t = ((Ctl_8025F4A0 *)this)->f60;
        if (t & 1) {
            ((Ctl_8025F4A0 *)this)->f60 = t | 0x10;
        } else if (busy != 0 || (t & 0x80)) {
            ((Ctl_8025F4A0 *)this)->f60 = (t & ~0x10) | ~((t & 0x10) | 0xFFFF0000 | 0xFFEF);
        } else {
            ((Ctl_8025F4A0 *)this)->f70->fB4 |= 2;
            TWindowKeyBoardHard::set_card_window_flag(((Ctl_8025F4A0 *)this)->f20, 1);
        }
        break;
    case 26:
        if (busy == 0 && sub_8026042C() == 0) {
            w = ((Ctl_8025F4A0 *)this)->f70;
            t = w->fB4;
            if (t & 1) {
                w->fB4 = t & ~1;
                TWindowKeyBoardHard::clear_card_window_flag(((Ctl_8025F4A0 *)this)->f20, 0);
                ((TWindowKeyBoardSoft *)(((Ctl_8025F4A0 *)this)->f70))->init();
            } else {
                w->fB4 = t | 1;
                TWindowKeyBoardHard::clear_card_window_flag(((Ctl_8025F4A0 *)this)->f20, 1);
            }
        }
        break;
    case 27:
        if (sub_8026042C() == 0) {
            t = ((Ctl_8025F4A0 *)this)->f60;
            if ((t & 0x84) != 0x84) {
                u32 u;
                w = ((Ctl_8025F4A0 *)this)->f70;
                u = w->fB4;
                if (u & 2) {
                    w->fB4 = u & ~2;
                    TWindowKeyBoardHard::set_card_window_flag(((Ctl_8025F4A0 *)this)->f20, 0);
                } else if (t & 4) {
                    w->fB4 = (u & ~4) | ~((u & 4) | 0xFFFF0000 | 0xFFFB);
                    if (((Ctl_8025F4A0 *)this)->f70->fB4 & 4) {
                        TWindowKeyBoardHard::update_card_window_page_flags(((Ctl_8025F4A0 *)this)->f20, 1);
                    } else {
                        TWindowKeyBoardHard::update_card_window_page_flags(((Ctl_8025F4A0 *)this)->f20, 0);
                    }
                    break;
                }
                if (((Ctl_8025F4A0 *)this)->f60 & 0x80) {
                    ((Ctl_8025F4A0 *)this)->f70->fB4 |= 8;
                    TWindowKeyBoardHard::set_bits_shift7(((Ctl_8025F4A0 *)this)->f20, 1);
                } else {
                    ((Ctl_8025F4A0 *)this)->f70->fB4 &= ~8;
                    TWindowKeyBoardHard::set_bits_shift7(((Ctl_8025F4A0 *)this)->f20, 0);
                }
            }
        }
        break;
    }
    return 1;
}

void TWindowKeyBoardHard::process_key_input(u8 arg1) {
    u16 sp8;
    s32 temp_r31;

    if (sub_8025F4A0(arg1) != 0) {
        *(s32 *)((s8 *)this + 0x6C) = 7;
        return;
    }
    temp_r31 = TKeyBoardControl::translate_key_char(this, arg1, &sp8);
    if (sp8 == 0x1F) {
        *(s32 *)((s8 *)this + 0x6C) = 7;
        return;
    }
    if (poll_input() < 3U) {
        if (lookup_key_repeat_state(arg1, (u8) sp8) == 0) {
            sp8 = (u16) sub_8025F2F8((u8) sp8);
            goto block_7;
        }
    } else {
block_7:
        if ((sub_80260438() != 0) && ((s32) sp8 >= 0x61) && ((s32) sp8 <= 0x7A)) {
            sp8 -= 0x20;
        }
        set_input_mode__20TWindowSubStatusDispFUc(*(s32 *)((s8 *)this + 0x70), temp_r31);
        ((TWindowKeyBoardBase *)(*(s32 *)((s8 *)this + 0x70)))->insert_character(sp8);
    }
}

void TWindowKeyBoardHard::process_all_key_states() {
    Ctl_8025F21C *c = (Ctl_8025F21C *)this;
    s32 i;
    s32 n;
    if (!(c->f60 & 2)) {
        n = ((TKeyBoardControl *)TKeyBoardControl__global_key_state)->get_key_state_2();
        for (i = 0; i < n; i++) {
            process_key_input(TKeyBoardControl__sub_8013239C(TKeyBoardControl__global_key_state, i));
        }
    }
}

typedef char RecoveredGlobal_8025FC60_TKeyBoardControl__data_80506270_size[sizeof(RecoveredGlobal_8025FC60_TKeyBoardControl__data_80506270) == 0xB0 ? 1 : -1];
void TWindowKeyBoardHard::update_modifier_flags() {
    struct RecoveredFields_8025FC60_arg0 *arg0 = (struct RecoveredFields_8025FC60_arg0 *)this;
    s32 temp_r3;
    s32 temp_r3_2;
    u32 temp_r4;
    u8 *temp_r3_3;
    u8 *temp_r3_4;
    if (get_key_state__16TKeyBoardControlFPv((s32 *)(&(*(RecoveredGlobal_8025FC60_TKeyBoardControl__data_80506270 *)&TKeyBoardControl__global_key_state).value)) != 0) {
        if ((TKeyBoardControl__sub_801323C8(&(*(RecoveredGlobal_8025FC60_TKeyBoardControl__data_80506270 *)&TKeyBoardControl__global_key_state).value, 0x56) != 0) || (TKeyBoardControl__sub_801323C8(&(*(RecoveredGlobal_8025FC60_TKeyBoardControl__data_80506270 *)&TKeyBoardControl__global_key_state).value, 0x5B) != 0)) {
            arg0->field_60 |= 2;
        } else {
            arg0->field_60 &= 0xFFFFFFFD;
        }
    }
    if (TKeyBoardControl__sub_801321B4(&(*(RecoveredGlobal_8025FC60_TKeyBoardControl__data_80506270 *)&TKeyBoardControl__global_key_state).value) != 0) {
        arg0->field_60 |= 2;
    } else {
        arg0->field_60 &= 0xFFFFFFFD;
    }
    if (is_key_57_pressed__16TKeyBoardControlFi(&(*(RecoveredGlobal_8025FC60_TKeyBoardControl__data_80506270 *)&TKeyBoardControl__global_key_state).value) != 0) {
        arg0->field_60 |= 4;
    } else {
        arg0->field_60 &= 0xFFFFFFFB;
    }
    if (TKeyBoardControl__sub_80132274(&(*(RecoveredGlobal_8025FC60_TKeyBoardControl__data_80506270 *)&TKeyBoardControl__global_key_state).value) != 0) {
        arg0->field_60 |= 8;
    } else {
        arg0->field_60 &= 0xFFFFFFF7;
    }
    if ((get_key_state__16TKeyBoardControlFPv((s32 *)(&(*(RecoveredGlobal_8025FC60_TKeyBoardControl__data_80506270 *)&TKeyBoardControl__global_key_state).value)) == 2) || (get_key_state__16TKeyBoardControlFPv((s32 *)(&(*(RecoveredGlobal_8025FC60_TKeyBoardControl__data_80506270 *)&TKeyBoardControl__global_key_state).value)) == 3)) {
        arg0->field_60 |= 1;
    } else {
        arg0->field_60 &= 0xFFFFFFFE;
    }
    if ((TKeyBoardControl__sub_801323C8(&(*(RecoveredGlobal_8025FC60_TKeyBoardControl__data_80506270 *)&TKeyBoardControl__global_key_state).value, 0x54) != 0) || (TKeyBoardControl__sub_801323C8(&(*(RecoveredGlobal_8025FC60_TKeyBoardControl__data_80506270 *)&TKeyBoardControl__global_key_state).value, 0x55) != 0)) {
        arg0->field_60 |= 0x80;
    } else {
        arg0->field_60 &= 0xFFFFFF7F;
    }
    temp_r3 = arg0->field_60;
    if ((temp_r3 & 0x80) && (temp_r3 & 1)) {
        arg0->field_60 = temp_r3 & 0xFFFFFFEF;
    }
    temp_r3_2 = arg0->field_60;
    temp_r4 = temp_r3_2 & 0x80;
    if (((temp_r4 != 0) && !(temp_r3_2 & 0x10)) || ((temp_r3_2 & 0x10) && (temp_r4 == 0))) {
        arg0->field_60 |= 0x20;
    } else {
        arg0->field_60 &= 0xFFFFFFDF;
    }
    if (arg0->field_60 & 0x80) {
        temp_r3_3 = arg0->field_70;
        *(s32 *)((s8 *)temp_r3_3 + 0xB4) = (s32) (*(s32 *)((s8 *)temp_r3_3 + 0xB4) | 0x20);
        return;
    }
    temp_r3_4 = arg0->field_70;
    *(s32 *)((s8 *)temp_r3_4 + 0xB4) = (s32) (*(s32 *)((s8 *)temp_r3_4 + 0xB4) & 0xFFFFFFDF);
}

void TKeyBoardControl::enable_keyboard_led() {
    if ((u32) *(u32 *)((s8 *)this + 0x70) != 0U) {
        *(s32 *)((s8 *)this + 0x60) = (s32) (*(s32 *)((s8 *)this + 0x60) | 0x1000);
        TKeyBoardControl__sub_8025CBC0((void *)(*(u32 *)((s8 *)this + 0x70)));
        fn_8025FF8C(this);
    }
}

void TKeyBoardControl::enable_kana_led() {
    if ((u32) *(u32 *)((s8 *)this + 0x70) != 0U) {
        *(s32 *)((s8 *)this + 0x60) = (s32) (*(s32 *)((s8 *)this + 0x60) | 0x800);
        TKeyBoardControl__sub_8025CBCC((u8 *)(*(u32 *)((s8 *)this + 0x70)));
        fn_8025FF8C(this);
    }
}

void TKeyBoardControl::enable_caps_led() {
    if ((u32) *(u32 *)((s8 *)this + 0x70) != 0U) {
        *(s32 *)((s8 *)this + 0x60) = (s32) (*(s32 *)((s8 *)this + 0x60) | 0x400);
        TKeyBoardControl__sub_8025CC04((u8 *)(*(u32 *)((s8 *)this + 0x70)));
        fn_8025FF8C(this);
    }
}

}


void fn_8025FF8C(void *arg0) {
    if ((u32) *(u32 *)((s8 *)arg0 + 0x70) != 0U) {
        *(s32 *)((s8 *)arg0 + 0x60) = (s32) (*(s32 *)((s8 *)arg0 + 0x60) | 0x40);
        TKeyBoardControl__sub_8025CC3C((void *)(*(u32 *)((s8 *)arg0 + 0x70)));
        switch (current_language) {
        case LANGUAGE_JAPANESE:
        case LANGUAGE_ENGLISH:
            break;
        case LANGUAGE_GERMAN:
        case LANGUAGE_FRENCH:
        case LANGUAGE_SPANISH:
            *(s32 *)((s8 *)arg0 + 0x6C) = 7;
            break;
        }
    }
}

#include "types.h"
#include "pso/ui/window/TWindowSubStatusDisp_8024FBA8.h"
#include "pso/ui/keyboard/TKeyBoardControl_8025CB70.h"
#include "pso/ui/window/TWindowKeyBoardHard.h"
#include "pso/ui/window/TWindowDD.h"
#include "pso/ui/Language.h"

extern const char lbl_8044F0CC[];
extern const char lbl_8044F0D4[];
extern const char keyboard_hard_status_text_a[];
extern const char keyboard_hard_status_text_b[];
extern const char lbl_8044F0FC[];
extern const char lbl_8044F104[];
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
struct Pt_80260020 { f32 x, y; };

struct Ctx_80260020 { u8 pad0[0x10]; Pt_80260020 pos; u8 pad18[0x38 - 0x18]; f32 scale; };

struct State_80260020 { u8 pad0[0xB4]; s32 flags; };

struct Win_80260020 { u8 pad0[0x70]; State_80260020 *state; };

extern "C" {
s32 is_key_active__19TWindowKeyBoardHardFv();

void TWindowKeyBoardHard::release_keyboard() { void* m = *(void* *)&this->m_70; if (m) TWindowKeyBoardHard__sub_8025CC48(m); }

void TWindowKeyBoardHard::draw_status_text(void *ctx) {
    s32 flags;
    if (((Win_80260020 *)this)->state != NULL && current_language == LANGUAGE_JAPANESE) {
        f32 inv = -1.0f / ((Ctx_80260020 *)ctx)->scale;
        Pt_80260020 pt;
        pt.x = ((Ctx_80260020 *)ctx)->pos.x;
        pt.y = ((Ctx_80260020 *)ctx)->pos.y;
        set_text_draw_params((s32)((Ctx_80260020 *)ctx), 0, 0, (f32)inv, 100000.0f);
        flags = ((Win_80260020 *)this)->state->flags;
        if (!(flags & 1)) {
            draw_window_text((f32 *)&pt, lbl_8044F0CC, -1, 0, 1000000.0f);
        } else if (flags & 2) {
            draw_window_text((f32 *)&pt, lbl_8044F0D4, -1, 0, 1000000.0f);
        } else if (flags & 4) {
            if (flags & 8) {
                draw_window_text((f32 *)&pt, keyboard_hard_status_text_a, -1, 0, 1000000.0f);
            } else {
                draw_window_text((f32 *)&pt, keyboard_hard_status_text_b, -1, 0, 1000000.0f);
            }
        } else if (flags & 8) {
            draw_window_text((f32 *)&pt, lbl_8044F0FC, -1, 0, 1000000.0f);
        } else {
            draw_window_text((f32 *)&pt, lbl_8044F104, -1, 0, 1000000.0f);
        }
    }
}

void TWindowKeyBoardHard::render() {
    s32 temp;
    if (((s32) this->m_68 > 0) && (is_key_active__19TWindowKeyBoardHardFv() == 0)) {
        temp = TWindowDD::draw_default_entry((s32)this);
        draw_status_text((Ctx_80260020 *)(temp));
    }
}

}

#include "types.h"
#include "pso/ui/keyboard/TKeyBoardControl_8025CB70.h"
#include "pso/ui/window/TWindowKeyBoardHard_802601D4.h"
#include "pso/ui/keyboard/TKeyBoardControl.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/ui/window/TWindowKeyBoardHard.h"
#include "pso/ui/window/TWindowDD.h"
#include "pso/ui/Language.h"

extern "C" {
s32 get_window_layout_position(int);
extern s32 __vt__19TWindowKeyBoardHard[];
s32 is_key_active__19TWindowKeyBoardHardFv();
void __dl__7TObjectFPv(void *);
s32 has_non_modifier_key__16TKeyBoardControlFv(void *);


void TWindowKeyBoardHard::run_task() {
    s32 temp_r3_2;
    void *temp_r3;

    if ((void *) this->m_70 != NULL) {
        if ((is_key_active__19TWindowKeyBoardHardFv() == 0) && (((TKeyBoardControl *)(this->m_70))->is_key_active() == 0)) {
            if (has_non_modifier_key__16TKeyBoardControlFv(this) != 0) {
                if (current_language == LANGUAGE_JAPANESE) {
                    this->m_68 = 0x3C;
                }
                this->m_60 = (s32) (this->m_60 & 0xFFFFFEFF);
                temp_r3 = *(void * *)&this->m_70;
                *(s32 *)((s8 *)temp_r3 + 0xB4) = (s32) (*(s32 *)((s8 *)temp_r3 + 0xB4) & 0xFFFFFFBF);
                if (!(this->m_60 & 0x40)) {
                    TWindowKeyBoardHard__sub_8025CC48(*(void * *)&this->m_70);
                }
            }
            update_modifier_flags();
            process_all_key_states();
        }
        temp_r3_2 = this->m_68;
        if (temp_r3_2 > 0) {
            this->m_68 = (temp_r3_2 - 1);
        }
        ((TWindowDD *)this)->initialize_subwindow();
        update_fade();
    }
}

void *__dt__19TWindowKeyBoardHardFv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__19TWindowKeyBoardHard;
        ((TWindowDD *)arg0)->destroy_window_base(0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}
u8 *TWindowKeyBoardHard__ct(TWindowKeyBoardHard *window_key_board_hard, s32 arg1) {
    ((TWindowDD *)window_key_board_hard)->construct_base((u8 *)&lbl_804CFAD0, (s16)(4), (u8 *)(get_window_layout_position(0xB9)));
    *(s32 **)((s8 *)window_key_board_hard + 0x18) = __vt__19TWindowKeyBoardHard;
    window_key_board_hard->m_name = TWindowKeyBoardHard__name;
    window_key_board_hard->m_60 = 0;
    window_key_board_hard->m_70 = arg1;
    window_key_board_hard->m_64 = 0;
    window_key_board_hard->m_68 = 0;
    window_key_board_hard->m_6c = 7;
    window_key_board_hard->release_keyboard();
    return (u8 *)window_key_board_hard;
}

}

#include "types.h"
#include "pso/ui/window/TWindowKeyBoardHard.h"

void TWindowKeyBoardHard::set_bits_shift7(s32 arg0, s32 arg1) {
    TWindowKeyBoardHard::set_card_window_flags((void *)arg0, (s32)(arg1 << 7), -0x81);
}
void TWindowKeyBoardHard::update_card_window_page_flags(s32 arg0, s32 arg1) {
    TWindowKeyBoardHard::set_card_window_flags((void *)arg0, (s32)(arg1 << 6), -0x41);
}
void TWindowKeyBoardHard::clear_card_window_flag(s32 arg0, s32 arg1) {
    TWindowKeyBoardHard::set_card_window_flags((void *)arg0, (s32)(arg1 << 4), -0x11);
}
void TWindowKeyBoardHard::set_card_window_flag(s32 arg0, s32 arg1) {
    TWindowKeyBoardHard::set_card_window_flags((void *)arg0, (s32)(arg1 << 5), -0x21);
}
int TWindowKeyBoardHard::sub_8026042C() { return (this->m_60 >> 6) & 0x1; }
int TWindowKeyBoardHard::sub_80260438() { return (this->m_60 >> 10) & 0x1; }
int TWindowKeyBoardHard::is_key_active() { return this->m_60 & 0x200; }
