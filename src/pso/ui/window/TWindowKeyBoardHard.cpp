#include "types.h"
#include "pso/system/ControllerInput.h"
#include "pso/ui/window/TWindowKeyBoardBase.h"
#include "pso/ui/window/WindowDrawContext.h"
#include "pso/ui/keyboard/KeyboardCharacterMaps.h"
#include "pso/ui/keyboard/TKeyBoardControl.h"
#include "pso/ui/keyboard/KeyboardKeyState.h"
#include "pso/ui/window/TWindowKeyBoardHard.h"
#include "pso/ui/window/TWindowKeyBoardSoft.h"
#include "pso/ui/Language.h"
#include "pso/unk/WindowLayoutRecord.h"

const char *TWindowKeyBoardHard::class_name = "TWindowKeyBoardHard";
u8 keyboard_key_repeat_mask_table[4] = { 0x1D, 0x1F, 0x07, 0x00 };
// The vowels and N/Y that take an accent, upper and lower case in pairs.
const u8 *keyboard_accent_base_chars = (const u8 *)"AaEeIiOoUuNnYy";


void TWindowKeyBoardHard::sub_8025EC04() {
    m_68 = 0;
    input_flags |= 0x100;
}

s32 TWindowKeyBoardHard::is_printable_key(u8 key) {
    if (key == 0x52) {
        return 1;
    }
    if (key < 0x10U) {
        return 0;
    }
    return key <= 0x29U ? 1 : 0;
}

s32 TWindowKeyBoardHard::has_non_modifier_key() {
    u32 i;
    u32 n;
    u8 c;
    if (TKeyBoardControl__sub_801A58B0() != 0) {
        return 0;
    }
    n = hardware_keyboard_state.get_pending_count();
    for (i = 0; i < n; i++) {
        c = hardware_keyboard_state.get_pending_key(i);
        if (c != 0x61 && c != 0x4C && c != 0x50 && c != 0x5E && c != 0x5D && c != 0x5C && c != 0x5F) {
            return 1;
        }
    }
    if (hardware_keyboard_state.is_key_pressed(0x55) != 0) {
        return 1;
    }
    if (hardware_keyboard_state.is_key_pressed(0x54) != 0) {
        return 1;
    }
    if (hardware_keyboard_state.is_key_pressed(0x56) != 0) {
        return 1;
    }
    return hardware_keyboard_state.is_key_pressed(0x57) != 0 ? 1 : 0;
}

u16 TWindowKeyBoardHard::lookup_key_char(u8 key) {
    if (input_flags & 0x80) {
        return keyboard_kana_shifted_map[key];
    }
    return keyboard_kana_unshifted_map[key];
}

s32 TWindowKeyBoardHard::translate_key_char(u8 key, u16 *out_char) {
    s32 shift;
    u32 f;
    u16 c;

    f = input_flags;
    if (f & 1) {
        shift = f & 0x20;
    } else if (is_printable_key(key) != 0) {
        shift = input_flags & 0x20;
    } else {
        shift = input_flags & 0x80;
    }
    if (!(m_control->composition_flags & 1) || hardware_keyboard_state.get_key_state() != 0) {
        switch (hardware_keyboard_state.get_key_state()) {
        case 0:
            if ((input_flags & 4) && current_language == LANGUAGE_JAPANESE) {
                *out_char = keyboard_jp_symbol_map[key];
            } else if (shift != 0) {
                *out_char = keyboard_jp_shifted_map[key];
            } else {
                *out_char = keyboard_jp_unshifted_map[key];
            }
            break;
        case 2:
            if (input_flags & 8) {
                *out_char = keyboard_fr_alternate_map[key];
            } else if (shift != 0) {
                *out_char = keyboard_fr_shifted_map[key];
            } else {
                *out_char = keyboard_fr_unshifted_map[key];
            }
            break;
        case 4:
            if (input_flags & 8) {
                *out_char = keyboard_es_alternate_map[key];
            } else if (shift != 0) {
                *out_char = keyboard_es_shifted_map[key];
            } else {
                *out_char = keyboard_es_unshifted_map[key];
            }
            break;
        case 3:
            if (input_flags & 8) {
                *out_char = keyboard_de_alternate_map[key];
            } else if (shift != 0) {
                *out_char = keyboard_de_shifted_map[key];
            } else {
                *out_char = keyboard_de_unshifted_map[key];
            }
            break;
        default:
            if (shift != 0) {
                *out_char = keyboard_us_shifted_map[key];
            } else {
                *out_char = keyboard_us_unshifted_map[key];
            }
            break;
        }
        if (m_control->composition_flags & 1) {
            return ((input_flags >> 7) & 1) ? 2 : 0;
        }
        return 1;
    }
    if (m_control->composition_flags & 2) {
        if (input_flags & 4) {
            *out_char = keyboard_jp_symbol_map[key];
        } else if (shift != 0) {
            *out_char = keyboard_jp_fullwidth_shifted_map[key];
        } else {
            *out_char = keyboard_jp_fullwidth_unshifted_map[key];
        }
        return 1;
    }
    if (m_control->composition_flags & 4) {
        if (is_printable_key(key) != 0) {
            if (input_flags & 4) {
                *out_char = keyboard_jp_symbol_map[key];
            } else if (shift != 0) {
                *out_char = keyboard_jp_shifted_map[key];
            } else {
                *out_char = keyboard_jp_unshifted_map[key];
            }
            return ((input_flags >> 7) & 1) ? 2 : 0;
        }
        if (input_flags & 4) {
            *out_char = keyboard_jp_symbol_map[key];
        } else if (shift != 0) {
            *out_char = keyboard_jp_fullwidth_shifted_map[key];
        } else {
            *out_char = keyboard_jp_fullwidth_unshifted_map[key];
        }
        return 1;
    }
    *out_char = lookup_key_char(key);
    if (!(m_control->composition_flags & 8)) {
        return 1;
    }
    c = *out_char;
    if (c < 0x829F) {
        return 1;
    }
    if (c > 0x82F1) {
        return 1;
    }
    if (c > 0x82DD) {
        *out_char = c + 1;
    }
    *out_char += 0xA1;
    return 1;
}

s32 TWindowKeyBoardHard::get_input_mode() {
    if (input_flags & 0x40) {
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
    return reinterpret_cast<saddr>(this);
}

s32 TWindowKeyBoardHard::poll_input() {

    if (input_flags & 0x40) {
        return 3;
    }
    switch ((s32) hardware_keyboard_state.get_key_state()) {
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

WindowDescriptor keyboard_hard_window_descriptor = { {0.0f, 0.0f}, 50030.0f, NULL, 0x823 };
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

u8 TWindowKeyBoardHard::apply_accent(u8 key) {
    u32 idx;
    s32 bit;
    const u8 *p;
    u32 i;
    u8 modes;
    u8 c;

    idx = accent_index;
    if (idx >= 7) {
        return key;
    }
    accent_index = 7;
    bit = get_input_mode();
    for (i = 0, p = keyboard_accent_base_chars; (s32)*p != 0; i++, p++) {
        if (key == *p) {
            modes = keyboard_layout_mode_table[i >> 1][idx];
            if (!(modes & (1 << bit))) {
                return key;
            }
            c = keyboard_accent_composed_chars[i >> 1][idx];
            if (i & 1) {
                return c + 0x20;
            }
            if (c == 0xDF) {
                return key;
            }
            return c;
        }
    }
    return key;
}

s32 TWindowKeyBoardHard::lookup_key_repeat_state(u8 key, u8 ch) {
    u32 st;
    u32 i;

    st = poll_input();
    if (st == 0U && key == 0x32) {
        return 0;
    }
    for (i = 0; i < 7; i++) {
        if (ch == keyboard_repeat_key_codes[i]) {
            if (!(keyboard_key_repeat_mask_table[st] & (1 << i))) {
                return 0;
            }
            if (accent_index == i) {
                accent_index = 7;
                return 0;
            }
            accent_index = i;
            return 1;
        }
    }
    return 0;
}

s32 TWindowKeyBoardHard::handle_control_key(u8 key) {
    static void (TWindowKeyBoardBase::*control_key_handlers[26])() = {
        &TWindowKeyBoardBase::key_enter,
        &TWindowKeyBoardBase::key_escape,
        &TWindowKeyBoardBase::key_f1,
        &TWindowKeyBoardBase::key_f2,
        &TWindowKeyBoardBase::key_f3,
        &TWindowKeyBoardBase::key_f4,
        &TWindowKeyBoardBase::key_f5,
        &TWindowKeyBoardBase::key_f6,
        &TWindowKeyBoardBase::key_f7,
        &TWindowKeyBoardBase::key_f8,
        &TWindowKeyBoardBase::key_f9,
        &TWindowKeyBoardBase::key_f10,
        &TWindowKeyBoardBase::key_f11,
        &TWindowKeyBoardBase::key_f12,
        &TWindowKeyBoardBase::sub_8025B928,
        &TWindowKeyBoardBase::key_home,
        &TWindowKeyBoardBase::key_end,
        &TWindowKeyBoardBase::sub_8025B92C,
        &TWindowKeyBoardBase::update_input_state,
        &TWindowKeyBoardBase::key_backspace,
        &TWindowKeyBoardBase::key_delete,
        &TWindowKeyBoardBase::key_right,
        &TWindowKeyBoardBase::key_left,
        &TWindowKeyBoardBase::key_up,
        &TWindowKeyBoardBase::key_down,
        &TWindowKeyBoardBase::key_space,
    };
    s32 busy;
    u32 t;
    TWindowKeyBoardBase *w;

    busy = current_language;
    switch (hardware_keyboard_state.get_key_state()) {
    case 0:
        key = keyboard_jp_unshifted_map[key];
        break;
    case 2:
        key = keyboard_fr_unshifted_map[key];
        break;
    case 4:
        key = keyboard_es_unshifted_map[key];
        break;
    case 3:
        key = keyboard_de_unshifted_map[key];
        break;
    default:
        key = keyboard_us_unshifted_map[key];
        break;
    }
    if (key > 31) {
        return 0;
    }
    if (key < 26) {
        (m_control->*control_key_handlers[key])();
        return 1;
    }
    switch (key) {
    case 30:
        t = input_flags;
        if (t & 1) {
            input_flags = t | 0x10;
        } else if (busy != 0 || (t & 0x80)) {
            input_flags = (t & ~0x10) | ~((t & 0x10) | 0xFFFF0000 | 0xFFEF);
        } else {
            m_control->composition_flags |= 2;
            TWindowKeyBoardHard::set_card_window_flag(client_index, 1);
        }
        break;
    case 26:
        if (busy == 0 && sub_8026042C() == 0) {
            w = m_control;
            t = w->composition_flags;
            if (t & 1) {
                w->composition_flags = t & ~1;
                TWindowKeyBoardHard::clear_card_window_flag(client_index, 0);
                m_control->init();
            } else {
                w->composition_flags = t | 1;
                TWindowKeyBoardHard::clear_card_window_flag(client_index, 1);
            }
        }
        break;
    case 27:
        if (sub_8026042C() == 0) {
            t = input_flags;
            if ((t & 0x84) != 0x84) {
                u32 u;
                w = m_control;
                u = w->composition_flags;
                if (u & 2) {
                    w->composition_flags = u & ~2;
                    TWindowKeyBoardHard::set_card_window_flag(client_index, 0);
                } else if (t & 4) {
                    w->composition_flags = (u & ~4) | ~((u & 4) | 0xFFFF0000 | 0xFFFB);
                    if (m_control->composition_flags & 4) {
                        TWindowKeyBoardHard::update_card_window_page_flags(client_index, 1);
                    } else {
                        TWindowKeyBoardHard::update_card_window_page_flags(client_index, 0);
                    }
                    break;
                }
                if (input_flags & 0x80) {
                    m_control->composition_flags |= 8;
                    TWindowKeyBoardHard::set_bits_shift7(client_index, 1);
                } else {
                    m_control->composition_flags &= ~8;
                    TWindowKeyBoardHard::set_bits_shift7(client_index, 0);
                }
            }
        }
        break;
    }
    return 1;
}

void TWindowKeyBoardHard::process_key_input(u8 key) {
    u16 ch;
    s32 mode;

    if (handle_control_key(key) != 0) {
        accent_index = 7;
        return;
    }
    mode = translate_key_char(key, &ch);
    if (ch == 0x1F) {
        accent_index = 7;
        return;
    }
    if (poll_input() < 3U) {
        if (lookup_key_repeat_state(key, (u8) ch) == 0) {
            ch = (u16) apply_accent((u8) ch);
            goto block_7;
        }
    } else {
block_7:
        if ((sub_80260438() != 0) && ((s32) ch >= 0x61) && ((s32) ch <= 0x7A)) {
            ch -= 0x20;
        }
        m_control->set_input_mode(mode);
        m_control->insert_character(ch);
    }
}

void TWindowKeyBoardHard::process_all_key_states() {
    s32 i;
    s32 n;
    if (!(input_flags & 2)) {
        n = hardware_keyboard_state.get_pending_count();
        for (i = 0; i < n; i++) {
            process_key_input(hardware_keyboard_state.get_pending_key(i));
        }
    }
}

void TWindowKeyBoardHard::update_modifier_flags() {
    if (hardware_keyboard_state.get_key_state() != 0) {
        if ((hardware_keyboard_state.is_key_pressed(0x56) != 0) || (hardware_keyboard_state.is_key_pressed(0x5B) != 0)) {
            input_flags |= 2;
        } else {
            input_flags &= 0xFFFFFFFD;
        }
    }
    if (hardware_keyboard_state.sub_801321B4() != 0) {
        input_flags |= 2;
    } else {
        input_flags &= 0xFFFFFFFD;
    }
    if (hardware_keyboard_state.is_key_57_pressed() != 0) {
        input_flags |= 4;
    } else {
        input_flags &= 0xFFFFFFFB;
    }
    if (hardware_keyboard_state.sub_80132274() != 0) {
        input_flags |= 8;
    } else {
        input_flags &= 0xFFFFFFF7;
    }
    if ((hardware_keyboard_state.get_key_state() == 2) || (hardware_keyboard_state.get_key_state() == 3)) {
        input_flags |= 1;
    } else {
        input_flags &= 0xFFFFFFFE;
    }
    if ((hardware_keyboard_state.is_key_pressed(0x54) != 0) || (hardware_keyboard_state.is_key_pressed(0x55) != 0)) {
        input_flags |= 0x80;
    } else {
        input_flags &= 0xFFFFFF7F;
    }
    if ((input_flags & 0x80) && (input_flags & 1)) {
        input_flags &= ~0x10;
    }
    if (((input_flags & 0x80) && !(input_flags & 0x10)) || ((input_flags & 0x10) && !(input_flags & 0x80))) {
        input_flags |= 0x20;
    } else {
        input_flags &= ~0x20;
    }
    if (input_flags & 0x80) {
        m_control->composition_flags |= 0x20;
        return;
    }
    m_control->composition_flags &= ~0x20;
}

void TWindowKeyBoardHard::set_mode3() {
    if (m_control != NULL) {
        input_flags |= 0x1000;
        m_control->set_mode3();
        set_mode0();
    }
}

void TWindowKeyBoardHard::set_mode2() {
    if (m_control != NULL) {
        input_flags |= 0x800;
        m_control->set_mode2();
        set_mode0();
    }
}

void TWindowKeyBoardHard::set_mode1() {
    if (m_control != NULL) {
        input_flags |= 0x400;
        m_control->set_mode1();
        set_mode0();
    }
}



void TWindowKeyBoardHard::set_mode0() {
    if (m_control != NULL) {
        input_flags |= 0x40;
        m_control->set_mode0();
        switch (current_language) {
        case LANGUAGE_JAPANESE:
        case LANGUAGE_ENGLISH:
            break;
        case LANGUAGE_GERMAN:
        case LANGUAGE_FRENCH:
        case LANGUAGE_SPANISH:
            accent_index = 7;
            break;
        }
    }
}


#include "pso/ui/window/TWindowSubStatusDisp_8024FBA8.h"


#include "pso/ui/window/TWindowDD.h"
#include "pso/system/NinjaTypes.h"


#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off


void TWindowKeyBoardHard::release_keyboard() {
    if (m_control != NULL) {
        m_control->sub_8025CC48();
    }
}

#pragma pool_data off
void TWindowKeyBoardHard::draw_status_text(WindowDrawContext *ctx) {
    s32 flags;
    if (m_control != NULL && current_language == LANGUAGE_JAPANESE) {
        f32 inv = -1.0f / ctx->depth;
        NJS_POINT2 pt;
        pt.x = ctx->inner_x;
        pt.y = ctx->inner_y;
        set_text_draw_params(ctx, 0, 0, (f32)inv, 100000.0f);
        flags = m_control->composition_flags;
        if (!(flags & 1)) {
            draw_window_text((f32 *)&pt, "\x94\xBC\x89\x70\x90\x94", -1, 0, 1000000.0f); // 半英数
        } else if (flags & 2) {
            draw_window_text((f32 *)&pt, "\x91\x53\x89\x70\x90\x94", -1, 0, 1000000.0f); // 全英数
        } else if (flags & 4) {
            if (flags & 8) {
                draw_window_text((f32 *)&pt, "\x91\x53\x83\x8D\x81\x5B\x83\x7D\x83\x4A\x83\x69", -1, 0, 1000000.0f); // 全ローマカナ
            } else {
                draw_window_text((f32 *)&pt, "\x91\x53\x83\x8D\x81\x5B\x83\x7D\x82\xA9\x82\xC8", -1, 0, 1000000.0f); // 全ローマかな
            }
        } else if (flags & 8) {
            draw_window_text((f32 *)&pt, "\x91\x53\x83\x4A\x83\x69", -1, 0, 1000000.0f); // 全カナ
        } else {
            draw_window_text((f32 *)&pt, "\x91\x53\x82\xA9\x82\xC8", -1, 0, 1000000.0f); // 全かな
        }
    }
}
#pragma pool_data reset

void TWindowKeyBoardHard::render() {
    if ((m_68 > 0) && (is_key_active() == 0)) {
        WindowDrawContext *context = draw_default_entry();
        draw_status_text(context);
    }
}




#include "pso/ui/window/TWindowBase.h"
#include "pso/ui/window/WindowLayout.h"




void TWindowKeyBoardHard::run_task() {
    s32 delay;

    if (m_control != NULL) {
        if ((is_key_active() == 0) && (m_control->is_confirmed() == 0)) {
            if (has_non_modifier_key() != 0) {
                if (current_language == LANGUAGE_JAPANESE) {
                    this->m_68 = 0x3C;
                }
                this->input_flags = (s32) (this->input_flags & 0xFFFFFEFF);
                m_control->composition_flags &= ~0x40;
                if (!(this->input_flags & 0x40)) {
                    m_control->sub_8025CC48();
                }
            }
            update_modifier_flags();
            process_all_key_states();
        }
        delay = this->m_68;
        if (delay > 0) {
            this->m_68 = (delay - 1);
        }
        update_window();
        update_fade();
    }
}

TWindowKeyBoardHard::~TWindowKeyBoardHard() {}
TWindowKeyBoardHard::TWindowKeyBoardHard(TWindowKeyBoardBase *control) : TWindowBase((u8 *)&keyboard_hard_window_descriptor, (s16)(4), (u8 *)(get_window_layout_position(0xB9))) {
    this->m_name = TWindowKeyBoardHard::class_name;
    this->input_flags = 0;
    m_control = control;
    this->m_64 = 0;
    this->m_68 = 0;
    this->accent_index = 7;
    this->release_keyboard();
}



void TWindowKeyBoardHard::set_bits_shift7(saddr client_id, s32 value) {
    TWindowKeyBoardHard::set_card_window_flags((void *)client_id, (s32)(value << 7), -0x81);
}
void TWindowKeyBoardHard::update_card_window_page_flags(saddr client_id, s32 value) {
    TWindowKeyBoardHard::set_card_window_flags((void *)client_id, (s32)(value << 6), -0x41);
}
void TWindowKeyBoardHard::clear_card_window_flag(saddr client_id, s32 value) {
    TWindowKeyBoardHard::set_card_window_flags((void *)client_id, (s32)(value << 4), -0x11);
}
void TWindowKeyBoardHard::set_card_window_flag(saddr client_id, s32 value) {
    TWindowKeyBoardHard::set_card_window_flags((void *)client_id, (s32)(value << 5), -0x21);
}
int TWindowKeyBoardHard::sub_8026042C() { return (this->input_flags >> 6) & 0x1; }
int TWindowKeyBoardHard::sub_80260438() { return (this->input_flags >> 10) & 0x1; }
int TWindowKeyBoardHard::is_key_active() { return this->input_flags & 0x200; }
