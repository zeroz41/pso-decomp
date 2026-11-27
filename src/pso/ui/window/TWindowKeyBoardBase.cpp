#include <dolphin/ar.h>
#include "pso/ui/font/TNECFontEORFunction.h"
#include "pso/player/LocalClientId.h"
#include "pso/quest/QuestDownloadAramFile.h"
#include "pso/ui/window/WindowDrawContext.h"
#include "pso/render/ScreenSpriteDraw.h"
#include "pso/system/ResourceFile.h"
#include "pso/system/TGStream.h"
#include "types.h"
#include "pso/render/Draw2D.h"
#include "pso/ui/window/TWindowKeyBoardBase.h"
#include <stddef.h>
#include "pso/ui/window/TWindowKeyBoardSoft.h"
#include "pso/ui/window/TWindowKeyBoardHard.h"
#include "pso/quest/QuestDownloadRequests.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/ui/charcreate/TObjCMHairMenu.h"
#include "pso/quest/AskDicFile.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/network/TLobby.h"
#include "pso/ui/window/TWindowDD.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/ui/Language.h"
#include "pso/unk/WindowLayoutRecord.h"
#include "pso/system/memory.h"
#include "pso/system/AramPool.h"
#include <string.h>
#include "pso/ui/window/WindowLayout.h"
#include "pso/ui/window/TWindowSubStatusDisp_803DEE6C.h"
#include "pso/ui/chat/ChatShortcuts.h"
#include "pso/ui/window/TWindowCtrl.h"
#include "pso/ui/window/TextBuilder.h"
#include "pso/ui/chat/TWindowChat.h"
#include "pso/ui/window/TWindowSubComCard.h"
#include "pso/enemy/BattleParamTables.h"

#pragma push
#pragma readonly_strings on
const char *TWindowKeyBoardBase::class_name = "TWindowKeyBoardBase";
#pragma pop

WindowDescriptor TWindowKeyBoardBase::window_descriptor = {
    {0.0f, 0.0f}, 50026.0f, NULL, 0x23,
};
u32 keyboard_key_colors[3] = { 0x00000000, 0xC03040C0, 0x1030A0C0 };
// Shift-JIS characters, zero-terminated, scanned by TWindowKeyBoardBase::add_conversion_candidate.
u16 soft_keyboard_conversion_exclusions[20] = {
    0x8141, 0x8142, 0x8145, 0x8158, 0x815B, 0x815F, 0x8175, 0x8176, 0x8177, 0x8178,
    0x818F, 0x8191, 0x8192, 0x81CA, 0x8396, 0x8199, 0x8163, 0x81F4, 0x0000, 0x0000,
};

extern "C" {
s32 map_char_to_font_code(u16);
u8 get_font_char_advance(s32);
extern "C" u8 bind_menu_font_glyph(s32 glyph, TexturedQuad *quad, s32 color);

#pragma push
#pragma readonly_strings on
int TWindowKeyBoardBase::is_alnum(u16 code) {
    if ((s32) code < 0x30) {
        return 0;
    }
    if ((s32) code <= 0x39) {
        return 1;
    }
    if ((s32) code < 0x41) {
        return 0;
    }
    if ((s32) code <= 0x5A) {
        return 1;
    }
    if ((s32) code < 0x61) {
        return 0;
    }
    if ((s32) code <= 0x7A) {
        return 1;
    }
    return 0;
}

s32 TWindowKeyBoardBase::get_state() { return m_text.cursor; }

void TWindowKeyBoardBase::key_clear() {
    if (state_flags & 2) {
        init();
    }
    if ((u32)m_text.length != 0U) {
        this->m_text.reset_state();
    }
    state_flags = (u16) (state_flags | 0x20);
}

void TWindowKeyBoardBase::key_none() {  }

void TWindowKeyBoardBase::convert_composition() {
    char text[0x100];
    char name[0x100];
    s32 count;
    u16 flags;
    flags = state_flags;
    if (flags & 2) {
        if (!(flags & 4)) {
            convert_input_text();
            count = this->candidate_count;
            if (state_flags & 0x10) {
                return;
            }
            do {
                this->candidate_count = count;
                count = ime_request_extend_segment(name, text);
            } while (count != 0);
            add_conversion_candidate(name);
            name[0] = 0;
            write_name_and_text(name, name);
        }
        if ((s32) this->candidate_index != 0xF1) {
            set_kana_mode();
            return;
        }
        set_kanji_mode();
    }
}

void TWindowKeyBoardBase::update_input_state() {
    u16 flags;

    flags = state_flags;
    if (flags & 4) {
        if ((s32)composition_flags & 0x20) {
            update();
            return;
        }
        select_next();
        return;
    }
    if (flags & 2) {
        convert_input_text();
    }
}

void TWindowKeyBoardBase::key_end() {
    if (!(state_flags & 4)) {
        active_text->cursor = active_text->length;
    }
}

void TWindowKeyBoardBase::key_home() {
    if (!(state_flags & 4)) {
        active_text->cursor = 0;
    }
}

void TWindowKeyBoardBase::key_f12() {
    if (!(request_flags & 8) && !((s32)composition_flags & 0x20) && !(state_flags & 2) && (is_chat_shortcut_set(0x13) != 0)) {
        active_input_mode = 0x13;
        state_flags = (u16) (state_flags | 0x41);
    }
}

void TWindowKeyBoardBase::key_f11() {
    if (!(request_flags & 8) && !((s32)composition_flags & 0x20) && !(state_flags & 2) && (is_chat_shortcut_set(0x12) != 0)) {
        active_input_mode = 0x12;
        state_flags = (u16) (state_flags | 0x41);
    }
}

void TWindowKeyBoardBase::key_f10() {
    if (!(request_flags & 8) && !((s32)composition_flags & 0x20) && !(state_flags & 2) && (is_chat_shortcut_set(0x11) != 0)) {
        active_input_mode = 0x11;
        state_flags = (u16) (state_flags | 0x41);
    }
}

void TWindowKeyBoardBase::key_f9() {
    if (!(request_flags & 8) && !((s32)composition_flags & 0x20) && !(state_flags & 2) && (is_chat_shortcut_set(0x10) != 0)) {
        active_input_mode = 0x10;
        state_flags = (u16) (state_flags | 0x41);
    }
}

void TWindowKeyBoardBase::key_f8() {
    if (!(request_flags & 8) && !((s32)composition_flags & 0x20) && !(state_flags & 2) && (is_chat_shortcut_set(0xF) != 0)) {
        active_input_mode = 0xF;
        state_flags = (u16) (state_flags | 0x41);
    }
}

void TWindowKeyBoardBase::key_f7() {
    char text[0x100];
    char name[0x100];
    s32 count;
    u16 flags;
    if (!((s32)composition_flags & 0x20)) {
        flags = state_flags;
        if (flags & 2) {
            if (!(flags & 4)) {
                convert_input_text();
                count = this->candidate_count;
                if (state_flags & 0x10) {
                    return;
                }
                do {
                    this->candidate_count = count;
                    count = ime_request_extend_segment(name, text);
                } while (count != 0);
                add_conversion_candidate(name);
                name[0] = 0;
                write_name_and_text(name, name);
            }
            set_kana_mode();
        } else if (!(request_flags & 8) && (is_chat_shortcut_set(0xE) != 0)) {
            active_input_mode = 0xE;
            state_flags = (u16) (state_flags | 0x41);
        }
    }
}

void TWindowKeyBoardBase::key_f6() {
    char text[0x100];
    char name[0x100];
    s32 count;
    u16 flags;
    if (!((s32)composition_flags & 0x20)) {
        flags = state_flags;
        if (flags & 2) {
            if (!(flags & 4)) {
                convert_input_text();
                count = this->candidate_count;
                if (state_flags & 0x10) {
                    return;
                }
                do {
                    this->candidate_count = count;
                    count = ime_request_extend_segment(name, text);
                } while (count != 0);
                add_conversion_candidate(name);
                name[0] = 0;
                write_name_and_text(name, name);
            }
            set_kanji_mode();
        } else if (!(request_flags & 8) && (is_chat_shortcut_set(0xD) != 0)) {
            active_input_mode = 0xD;
            state_flags = (u16) (state_flags | 0x41);
        }
    }
}

void TWindowKeyBoardBase::key_f5() {
    if (!(request_flags & 8) && !((s32)composition_flags & 0x20) && !(state_flags & 2) && (is_chat_shortcut_set(0xC) != 0)) {
        active_input_mode = 0xC;
        state_flags = (u16) (state_flags | 0x41);
    }
}

void TWindowKeyBoardBase::key_f4() {
    if (!(request_flags & 8) && !((s32)composition_flags & 0x20) && !(state_flags & 2) && (is_chat_shortcut_set(0xB) != 0)) {
        active_input_mode = 0xB;
        state_flags = (u16) (state_flags | 0x41);
    }
}

void TWindowKeyBoardBase::key_f3() {
    if (!(request_flags & 8)) {
        if ((s32)composition_flags & 0x20) {
            insert_party_member_name(2);
            return;
        }
        if (!(state_flags & 2) && (is_chat_shortcut_set(0xA) != 0)) {
            active_input_mode = 0xA;
            state_flags = (u16) (state_flags | 0x41);
        }
    }
}

void TWindowKeyBoardBase::key_f2() {
    if (!(request_flags & 8)) {
        if ((s32)composition_flags & 0x20) {
            insert_party_member_name(1);
            return;
        }
        if (!(state_flags & 2) && (is_chat_shortcut_set(9) != 0)) {
            active_input_mode = 9;
            state_flags = (u16) (state_flags | 0x41);
        }
    }
}

void TWindowKeyBoardBase::key_f1() {
    if (!(request_flags & 8)) {
        if ((s32)composition_flags & 0x20) {
            insert_party_member_name(0);
            return;
        }
        if (!(state_flags & 2) && (is_chat_shortcut_set(8) != 0)) {
            active_input_mode = 8;
            state_flags = (u16) (state_flags | 0x41);
        }
    }
}

void TWindowKeyBoardBase::key_up() {
    if (state_flags & 4) {
        if (request_flags & 1) {
            update();
            return;
        }
        process_input();
    }
}

void TWindowKeyBoardBase::key_down() {
    if (state_flags & 4) {
        if (request_flags & 1) {
            select_next();
            return;
        }
        select_next_segment();
    }
}

void TWindowKeyBoardBase::key_left() {
    if (state_flags & 4) {
        if ((request_flags & 1) && !(composition_flags & 0x20)) {
            process_input();
            return;
        }
        shrink_segment();
        return;
    }
    if (active_text->cursor != 0) {
        active_text->cursor--;
    }
}

void TWindowKeyBoardBase::key_right() {
    if (state_flags & 4) {
        if ((request_flags & 1) && !((s32)composition_flags & 0x20)) {
            select_next_segment();
            return;
        }
        extend_segment();
        return;
    }
    if (active_text->cursor < active_text->length) {
        active_text->cursor++;
    }
}

void TWindowKeyBoardBase::key_delete() {
    u16 flags;
    flags = state_flags;
    if (flags & 4) {
        state_flags = (u16) (flags & 0xFFFFFFFB);
        return;
    }
    active_text->delete_char();
    if ((state_flags & 2) && active_text->length == 0U) {
        init();
    }
}

void TWindowKeyBoardBase::handle_backspace() {
    u16 flags;
    flags = state_flags;
    if (flags & 4) {
        if (request_flags & 1) {
            this->update();
            return;
        }
        state_flags = (u16) (flags & 0xFFFFFFFB);
        return;
    }
    if (active_text->cursor == 0) {
        state_flags = (u16) (flags | 0x20);
        return;
    }
    active_text->cursor--;
    active_text->delete_char();
    if ((state_flags & 2) && active_text->length == 0U) {
        init();
    }
}

void TWindowKeyBoardBase::key_backspace() {
    u16 flags;
    flags = state_flags;
    if (flags & 4) {
        if (request_flags & 1) {
            update();
            return;
        }
        state_flags = (u16) (flags & 0xFFFFFFFB);
        return;
    }
    if (active_text->cursor != 0) {
        active_text->cursor--;
        active_text->delete_char();
        if ((state_flags & 2) && active_text->length == 0U) {
            init();
        }
    }
}

void TWindowKeyBoardBase::key_escape() {
    u16 flags;
    flags = state_flags;
    if (flags & 4) {
        state_flags = (u16) (flags & 0xFFFFFFFB);
        return;
    }
    if (flags & 2) {
        init();
        return;
    }
    if ((u32)m_text.length != 0U) {
        this->m_text.reset_state();
        return;
    }
    state_flags = (u16) (flags | 0x20);
}

void TWindowKeyBoardBase::update_input_state2() {
    u16 flags;

    flags = state_flags;
    if (flags & 4) {
        if ((s32)composition_flags & 0x20) {
            update();
            return;
        }
        select_next();
        return;
    }
    if (flags & 2) {
        convert_input_text();
    }
}

void TWindowKeyBoardBase::key_space() {
    s32 mode_flags;
    u16 flags;
    flags = state_flags;
    if (flags & 4) {
        if ((s32)composition_flags & 0x20) {
            update();
            return;
        }
        select_next();
        return;
    }
    if (flags & 2) {
        convert_input_text();
        return;
    }
    mode_flags = (s32)composition_flags;
    if (!(mode_flags & 0x80) && !(mode_flags & 0x100) && !(mode_flags & 0x200)) {
        active_text->insert_char(0x20);
    }
}

void TWindowKeyBoardBase::key_enter() {
    if (!(state_flags & 2)) {
        if (!(request_flags & 4) || (this->m_text.is_buffer_blank() == 0)) {
            state_flags = (u16) (state_flags | 1);
        }
    } else {
        commit_composition_text();
    }
}

void TWindowKeyBoardBase::insert_party_member_name(s32 slot) {
    const char *name;
    u16 flags;
    u32 cursor;
    flags = state_flags;
    if (flags & 2) {
        if (flags & 4) {
            convert_trailing_romaji(1);
        }
        commit_composition_text();
    }
    name = (const char *)get_party_member_name(slot);
    if (name != NULL) {
        text_builder_reset();
        cursor = m_text.cursor;
        if (cursor != 0U) {
            if (cursor == m_text.length) {
                text_builder_append(" > ");
                text_builder_append(name);
            } else {
                text_builder_append(" ");
                text_builder_append(name);
                text_builder_append(" ");
            }
        } else {
            text_builder_append(name);
            if (m_text.length != 0U) {
                text_builder_append(" ");
            }
        }
        m_text.append_text((u8 *)get_shared_text_buffer());
    }
}

void TWindowKeyBoardBase::set_text(const char *s) { m_text.set_text_from_string(s); }

void TWindowKeyBoardBase::insert_character(u16 code) {
    s32 f;
    if (current_language == LANGUAGE_JAPANESE && code >= 0x80U && code < 0x100U) {
        return;
    }
    if (!(state_flags & 0x80) && m_input_mode >= 1U) {
        convert_trailing_romaji(1);
        if (m_input_mode == 2) {
            state_flags |= 0x80;
        }
        if (m_input_mode == 3 && (state_flags & 2)) {
            commit_composition_text();
        }
    }
    if ((state_flags & 4) || (composition_flags & 0x40)) {
        commit_composition_text();
    }
    f = composition_flags;
    if ((f & 0x10) && code >= 0x80U) {
        return;
    }
    if ((f & 0x80) && !((s32)code >= 0x41 && (s32)code <= 0x5A)) {
        return;
    }
    if ((f & 0x100) && TWindowKeyBoardBase::is_alnum(code) == 0) {
        return;
    }
    f = composition_flags;
    if ((f & 0x200) && !((s32)code >= 0x30 && (s32)code <= 0x39)) {
        return;
    }
    if (!(f & 1)) {
        active_text->insert_char(code);
        return;
    }
    if (!(state_flags & 2)) {
        active_text = &m_text2;
        state_flags |= 2;
    }
    active_text->insert_char(code);
    if (m_input_mode == 0 && !(state_flags & 0x80)) {
        convert_trailing_romaji(0);
    }
}

void TWindowKeyBoardBase::init() {
    m_text2.reset_state();
    active_text = &m_text;
    state_flags &= ~0x86;
}

#pragma push
#pragma opt_propagation off
void TWindowKeyBoardBase::commit_composition_text() {
    s32 n;
    s32 nx;
    s8 *src;
    u16 *dst;
    u16 c;
    u32 cnt;
    u32 i;
    u16 *s;
    u16 *d;
    if (state_flags & 4) {
        convert_trailing_romaji(1);
        src = reinterpret_cast<s8 *>(candidate_buffer);
        i = 0;
        dst = m_text2.buffer;
        while (*src != 0) {
            cnt = src[1];
            src += 3;
            while (cnt-- != 0 && i < m_text2.capacity) {
                c = *src++;
                if ((c & 0xE0) == 0x80 || (c & 0xE0) == 0xE0) {
                    c = (u8)c << 8;
                    c |= *src & 0xFF;
                    cnt--;
                    src++;
                }
                *dst++ = c;
                i++;
            }
        }
        *dst = 0;
        m_text2.length = i;
        state_flags &= ~4;
    }
    m_text.check_text_overflow(m_text2.buffer);
    s = m_text2.buffer;
    n = 0;
    while ((s32)*s != 0) {
        s++;
        n++;
    }
    if (n > 0) {
        m_text.make_room_in_buffer(m_text.cursor, n);
        s = m_text2.buffer;
        d = m_text.buffer + m_text.cursor;
        while ((s32)*s != 0) {
            *d++ = *s++;
        }
        m_text.cursor += n;
    }
    init();
}
#pragma pop

void TWindowKeyBoardBase::export_text(char *out) {
    u32 a = 0;
    u32 b = 0;
    u32 c = 0;
    u16 code;
    u16 *in = m_text.buffer;
    if (!(composition_flags & 0x10) && (s32)*in != 0) {
        out[0] = 9;
        if (current_language == LANGUAGE_JAPANESE) {
            out[1] = 'J';
            out += 2;
        } else {
            out[1] = 'E';
            out += 2;
        }
    }
    while ((s32)*in != 0) {
        code = *in++;
        get_font_char_advance(map_char_to_font_code(code));
        if (m_text.measure_char_overflow(code, &a, &b, &c)) {
            *out = 0;
            return;
        }
        if (code & 0xFF00) {
            *out++ = (code >> 8) & 0xFF;
        }
        *out++ = code;
    }
    *out = 0;
}

s32 TWindowKeyBoardBase::measure_text_overflow() {
    u32 a = 0;
    u32 b = 0;
    u32 c = 0;
    u16 ch;
    u16 *p = m_text.buffer;
    while ((s32)*p != 0) {
        ch = *p++;
        if (m_text.measure_char_overflow(ch, &a, &b, &c) != 0) {
            break;
        }
    }
    c += 1;
    if (!(composition_flags & 0x10)) {
        c += 2;
    }
    return c;
}

int TWindowKeyBoardBase::is_key_state_2() { return (state_flags >> 2) & 1; }
#pragma pop

#pragma push
#pragma bool off
s32 TWindowKeyBoardBase::has_text() {
    if ((u32) this->m_text.length != 0U) {
        return 1;
    }
    return this->m_text2.length != 0;
}
#pragma pop

void TWindowKeyBoardBase::flush_if_flagged() { if (get_flag() != 0) { reset_input(); } }

void TWindowKeyBoardBase::reset_input() {
    m_text.reset_state();
    m_text2.reset_state();
    active_text = &m_text;
    state_flags = 0;
    current_candidate = NULL;
    last_candidate = NULL;
}

void TWindowKeyBoardBase::set_mode3() {
    composition_flags = 530;
}

void TWindowKeyBoardBase::set_mode2() {
    set_mode0();
    composition_flags |= 0x100;
}

void TWindowKeyBoardBase::set_mode1() {
    set_mode0();
    composition_flags |= 0x80;
}

void TWindowKeyBoardBase::set_mode0() {
    composition_flags = 18;
}

void TWindowKeyBoardBase::load_input_mode_options() {
    switch (current_language) {
    case LANGUAGE_JAPANESE:
        composition_flags = 0;
        if (test_keyboard_card_flag_16(client_index) != 0) {
            composition_flags = (s32)(composition_flags | 1);
        }
        if (test_keyboard_card_flag_32(client_index) != 0) {
            composition_flags = (s32)(composition_flags | 2);
        }
        if (test_keyboard_card_flag_64(client_index) != 0) {
            composition_flags = (s32)(composition_flags | 4);
        }
        if (test_keyboard_card_flag_128(client_index) != 0) {
            composition_flags = (s32)(composition_flags | 8);
        }
        break;
    case LANGUAGE_ENGLISH:
    case LANGUAGE_GERMAN:
    case LANGUAGE_FRENCH:
    case LANGUAGE_SPANISH:
        composition_flags = 6;
        break;
    }
}

void TWindowKeyBoardBase::update_close_mode() {
    switch (current_language) {
    case LANGUAGE_JAPANESE:
        composition_flags = 5;
        break;
    case LANGUAGE_ENGLISH:
    case LANGUAGE_GERMAN:
    case LANGUAGE_FRENCH:
    case LANGUAGE_SPANISH:
        composition_flags = 6;
        break;
    }
}


void TWindowKeyBoardBase::init_keyboard_text_field(u32 width, u32 lines) {
    if (lines == 0) {
        this->target_size[0] = 100000.0f;
        this->target_size[1] = 38.0f;
    } else {
        this->target_size[0] = (f32) (0.1f + (8.0f + (f32) width));
        this->target_size[1] = (f32) (20.0f + (f32) (lines * 0x14));
    }
    this->frame_size[0] = (f32) this->target_size[0];
    this->frame_size[1] = (f32) this->target_size[1];
    m_text.init(width, lines);
    active_text = &m_text;
    this->state_flags = 0;
}

s32 TWindowKeyBoardBase::has_unconvertible_char(u8 *text) {
    char *p = (char *)text;
    u16 ch;

    while (*p != 0) {
        ch = *p++;
        if ((ch & 0xE0) == 0x80 || (ch & 0xE0) == 0xE0) {
            ch <<= 8;
            ch |= *p++ & 0xFF;
        }
        if (ch == 0x814A) {
            return 1;
        }
        if (ch == 0x814B) {
            return 1;
        }
        if (ch == 0x819B) {
            return 1;
        }
        if (ch == 0x817E) {
            return 1;
        }
        if (ch == 0x81A8) {
            return 1;
        }
        if (ch == 0x81A9) {
            return 1;
        }
        if (ch == 0x81AA) {
            return 1;
        }
        if (ch == 0x81AB) {
            return 1;
        }
        if (ch == 0x8163) {
            return 1;
        }
        if (ch == 0x81A2) {
            return 1;
        }
        if (ch == 0x81A4) {
            return 1;
        }
        if (ch == 0x81F4) {
            return 1;
        }
        if (ch == 0x8199) {
            return 1;
        }
        if (ch >= 0xE000) {
            return 1;
        }
        if (ch >= 0xE0 && ch <= 0xFF) {
            return 1;
        }
    }
    return 0;
}

void TWindowKeyBoardBase::skip_ime_candidates(int count) {
    char tmp[0x100];
    char out[0x100];
    u32 i;

    if (count != 0xF1 && count != 0xF0) {
        for (i = 1; i < count; i++) {
            ime_request_next_candidate(out, tmp);
        }
    }
}

void TWindowKeyBoardBase::add_conversion_candidate(char *text) {
    char out[0x100];
    char tmp[0x100];
    char *p;
    u16 ch;
    s32 c;
    s32 c2;
    u16 *t;

    p = text;
    while (*p != 0) {
        ch = *p++;
        if ((ch & 0xE0) == 0x80 || (ch & 0xE0) == 0xE0) {
            ch <<= 8;
            ch |= *p++ & 0xFF;
        }
        if ((s32)(u16)ch == 0x5C) {
            return;
        }
        if (ch >= 0xA0 && ch <= 0xFF) {
            return;
        }
    }
    ime_request_convert_to_katakana(out, tmp);
    if (strcmp(text, out) != 0) {
        candidate_index++;
        candidate_count++;
        ime_request_next_candidate(out, tmp);
        return;
    }
    ime_request_convert_to_hiragana(out, tmp);
    if (strcmp(text, out) != 0) {
        candidate_index++;
        candidate_count++;
        ime_request_next_candidate(out, tmp);
        return;
    }
    ime_request_convert_to_fullwidth(out, tmp);
    if (strcmp(text, out) != 0) {
        candidate_index++;
        candidate_count++;
        ime_request_next_candidate(out, tmp);
        return;
    }
    p = text;
    while (*p != 0) {
        ch = *p++;
        if ((ch & 0xE0) == 0x80 && (ch & 0xE0) == 0x80) {
            ch <<= 8;
            ch |= *p++ & 0xFF;
            for (t = soft_keyboard_conversion_exclusions; *t != 0; t++) {
                if (ch == *t) {
                    return;
                }
            }
        }
    }
    ime_request_convert_to_halfwidth_kana(out, tmp);
    if (strcmp(text, out) != 0) {
        candidate_index++;
        candidate_count++;
        ime_request_next_candidate(out, tmp);
    }
}

void TWindowKeyBoardBase::remove_candidate(void *record) {
    s8 *src = (s8 *)record;
    s8 *dst = src;
    s32 len = src[1];
    s8 n;

    src += len + 3;
    *src = *dst;
    while (*src != 0) {
        CandidateRecord *from = (CandidateRecord *)src;
        CandidateRecord *to = (CandidateRecord *)dst;
        to->prev_len = from->prev_len;
        to->len = n = from->len;
        to->candidate_index = from->candidate_index;
        src += 3;
        dst += 3;
        while (n-- != 0) {
            *dst++ = *src++;
        }
    }
    *dst = *src;
    candidate_bytes_remaining += len + 3;
    if (last_candidate > current_candidate) {
        last_candidate -= len + 3;
    }
}

#pragma push
#pragma opt_propagation off
void TWindowKeyBoardBase::insert_string(char *src) {
    s32 n;
    u8 *p = current_candidate;
    s8 len = measure_string_len(src);
    CandidateRecord *rec;
    u8 *dst;
    s8 total;
    s8 *q;
    u8 saved = p[0];
    total = 0;
    p[0] = len;
    while ((s8)p[0] != 0) {
        s8 step = p[1] + 3;
        p += step;
        total += step;
    }
    n = len + 3;
    dst = p + n;
    do {
        *dst-- = *p--;
    } while (total-- != 0);
    q = (s8 *)current_candidate;
    q[0] = saved;
    q[1] = len;
    q[2] = candidate_index;
    q += 3;
    strncpy((char *)q, src, len);
    candidate_bytes_remaining -= n;
    if (last_candidate > current_candidate) {
        last_candidate += n;
    }
}
#pragma pop

void TWindowKeyBoardBase::update_input(void* a1) { remove_candidate(current_candidate); insert_string((char *)(a1)); }

#pragma push
#pragma optimization_level 2
s32 TWindowKeyBoardBase::can_fit_candidate(void *window_sub_status_disp) {
    s32 len = ((CandidateRecord *)current_candidate)->len;
    s32 need = measure_string_len(reinterpret_cast<const char *>(window_sub_status_disp));

    return (candidate_bytes_remaining >= need - len) ? 1 : 0;
}
#pragma pop

void TWindowKeyBoardBase::append_text_entry(u8 *text) {
    CandidateRecord *rec;
    s32 idx;
    s32 n;
    u8 *p;
    rec = reinterpret_cast<CandidateRecord *>(current_candidate);
    idx = rec->len;
    p = (u8 *)(idx + (saddr)rec);
    n = TWindowKeyBoardSoft::strnlen((const char *)text, 0x100);
    p[3] = idx;
    p[4] = n;
    p[5] = 1;
    p += 6;
    strncpy((char *)p, (const char *)text, n);
    p += n;
    *p++ = 0;
    candidate_bytes_remaining = 0x94 - (p - candidate_buffer);
    if (candidate_bytes_remaining < 0) {
        state_flags |= 0x10;
    }
    last_candidate = current_candidate;
}

void TWindowKeyBoardBase::write_name_and_text(char *name, char *text) {
    u8 *p = current_candidate;
    s32 n1 = TWindowKeyBoardSoft::strnlen(name, 0x100);
    s32 n2;
    p[1] = n1;
    p[2] = candidate_index;
    p += 3;
    strncpy((char *)p, name, n1);
    p += n1;
    n1 = (s8)n1;
    n2 = TWindowKeyBoardSoft::strnlen(text, 0x100);
    p[0] = n1;
    p[1] = n2;
    p[2] = 1;
    p += 3;
    strncpy((char *)p, text, n2);
    p += n2;
    *p++ = 0;
    candidate_bytes_remaining = 0x94 - (p - candidate_buffer);
    last_candidate = current_candidate;
}

#pragma push
#pragma optimization_level 2
s32 TWindowKeyBoardBase::candidate_fits(char *name, char *text) {
    s32 name_len = TWindowKeyBoardSoft::strnlen(name, 0x100);
    s32 text_len = TWindowKeyBoardSoft::strnlen(text, 0x100);
    s32 room = 0x94 - (current_candidate - candidate_buffer);

    room -= 3;
    room -= name_len;
    room -= 3;
    room -= text_len;
    room -= 1;
    return (room >= 0) ? 1 : 0;
}
#pragma pop

void TWindowKeyBoardBase::set_kanji_mode() {
    char buffers[2][0x100];

    if (!(state_flags & 0x10)) {
        ime_request_convert_to_hiragana(buffers[0], buffers[1]);
        candidate_index = 0xF0;
        update_input(buffers[0]);
    }
}

void TWindowKeyBoardBase::set_kana_mode() {
    char buffers[2][0x100];

    if (!(state_flags & 0x10)) {
        ime_request_convert_to_katakana(buffers[0], buffers[1]);
        candidate_index = 0xF1;
        update_input(buffers[0]);
    }
}

void TWindowKeyBoardBase::select_next_segment() {
    char text[0x100];
    char name[0x100];
    s32 count;
    u8 *rec;
    s32 i;
    u8 kind;

    if (state_flags & 0x10) {
        return;
    }
    count = ime_request_next_segment(name, text);
    if (count == 0) {
        return;
    }
    rec = current_candidate;
    current_candidate += ((CandidateRecord *)rec)->len + 3;
    if (current_candidate > last_candidate) {
        i = 1;
        add_conversion_candidate(name);
        while (candidate_fits(name, text) == 0) {
            ime_request_next_candidate(name, text);
            i++;
            if (i > count) {
                current_candidate = rec;
                ime_request_prev_segment(name, text);
                skip_ime_candidates(candidate_index);
                return;
            }
        }
        rec[2] = candidate_index;
        candidate_index = i;
        write_name_and_text(name, text);
    } else {
        kind = current_candidate[2];
        rec[2] = candidate_index;
        candidate_index = kind;
        skip_ime_candidates(kind);
    }
    candidate_count = count;
}

void TWindowKeyBoardBase::process_input() {
    char text[0x100];
    char name[0x100];
    s32 count;
    u8 *cand;

    if (!(state_flags & 0x10)) {
        count = ime_request_prev_segment(name, text);
        if (count != 0) {
            candidate_count = count;
            current_candidate[2] = (u8) candidate_index;
            cand = current_candidate;
            current_candidate = cand - (static_cast<s8>(cand[0]) + 3);
            candidate_index = (s32) current_candidate[2];
            this->skip_ime_candidates((int) (candidate_index));
        }
    }
}

void TWindowKeyBoardBase::shrink_segment() {
    char text[0x100];
    char name[0x100];
    s32 n;
    s32 i;
    if (state_flags & 0x10) {
        return;
    }
    n = ime_request_shrink_segment(name, text);
    if (n == 0) {
        return;
    }
    i = 1;
    add_conversion_candidate(name);
    while (candidate_fits(name, text) == 0) {
        ime_request_next_candidate(name, text);
        i++;
        if (i > n) {
            ime_request_extend_segment(name, text);
            skip_ime_candidates(candidate_index);
            append_text_entry((u8 *)text);
            return;
        }
    }
    candidate_index = i;
    candidate_count = n;
    write_name_and_text(name, text);
}

void TWindowKeyBoardBase::extend_segment() {
    char text[0x100];
    char name[0x100];
    s32 n;
    s32 i;
    if (state_flags & 0x10) {
        return;
    }
    n = ime_request_extend_segment(name, text);
    if (n == 0) {
        return;
    }
    i = 1;
    add_conversion_candidate(name);
    while (candidate_fits(name, text) == 0) {
        ime_request_next_candidate(name, text);
        i++;
        if (i > n) {
            ime_request_shrink_segment(name, text);
            skip_ime_candidates(candidate_index);
            append_text_entry((u8 *)text);
            return;
        }
    }
    candidate_index = i;
    candidate_count = n;
    write_name_and_text(name, text);
}

void TWindowKeyBoardBase::select_next() {
    char text[0x100];
    char name[0x100];

    if (!(state_flags & 0x10)) {
        do {
            ime_request_next_candidate(name, text);
            candidate_index = (s32) (candidate_index + 1);
            if ((s32) candidate_index > (s32) candidate_count) {
                candidate_index = 1;
            }
        } while (can_fit_candidate(name) == 0);
        update_input(name);
    }
}

void TWindowKeyBoardBase::update() {
    char text[0x100];
    char name[0x100];

    if (!(state_flags & 0x10)) {
        do {
            ime_request_prev_candidate(name, text);
            candidate_index = (s32) (candidate_index - 1);
            if ((s32) candidate_index <= 0) {
                candidate_index = (s32) candidate_count;
            }
        } while (can_fit_candidate(name) == 0);
        update_input(name);
    }
}

void TWindowKeyBoardBase::convert_input_text() {
    char text[0x100];
    char name[0x100];
    u16 *src;
    int code;
    u8 *dst;

    if (!(state_flags & 0x80)) {
        convert_trailing_romaji(1);
    }
    src = this->m_text2.buffer;
    dst = candidate_buffer;
    while ((code = *src) != 0) {
        *dst = (u8) (code >> 8);
        if ((s8) *dst != 0) {
            dst += 1;
        }
        code = *src;
        src++;
        *dst = (u8) code;
        dst += 1;
    }
    *dst = 0;
    current_candidate = candidate_buffer;
    if (has_unconvertible_char(candidate_buffer) != 0) {
        state_flags = (u16) (state_flags | 0x10);
        candidate_count = 1;
        candidate_index = 1;
        strncpy(name, (const char *)candidate_buffer, 0x100);
        text[0] = 0;
    } else {
        state_flags = (u16) (state_flags & 0xFFFFFFEF);
        candidate_count = ime_request_convert(candidate_buffer, name, text);
        candidate_index = 1;
        add_conversion_candidate(name);
    }
    candidate_bytes_remaining = 0x94;
    if (candidate_fits(name, text) != 0) {
        write_name_and_text(name, text);
        state_flags = (u16) (state_flags | 4);
    }
}

void TWindowKeyBoardBase::convert_trailing_romaji(s32 finalize) {
    u16 *p;
    s32 lim; u32 n; s32 j; s32 rb; s32 ret; char c; char *q;
    u32 cnt;
    char out[5]; char scratch[8];
    cnt = m_text2.cursor;
    if (cnt == 0) return;
    p = m_text2.buffer + cnt - 1;
    lim = cnt;
    n = 0;
    if ((s32)cnt > 4) lim = 4;
    while (is_alpha_char(*p) != 0) { lim--; p--; n++; if (lim <= 0) break; }
    p++; j = 0;
    while (j < n) { out[j] = (u8)*p; j++; p++; }
    out[j] = 0;
    q = out;
    for (;;) {
        rb = n * 2;
        if (n == 0) break;
        if (finalize == 0 && n == 1) { c = *q; if (c == 'n' || c == 'N') return; }
        if (composition_flags & 8) { ret = ime_request_romaji_to_katakana(q, scratch); } else { ret = ime_request_romaji_to_hiragana(q, scratch); }
        if (ret != 0 && n > 1 && q[0] == q[1]) {
            if (composition_flags & 8) {
                *(u16 *)((s8*)m_text2.buffer + m_text2.cursor * 2 - rb) = 0x8362;
            } else {
                *(u16 *)((s8*)m_text2.buffer + m_text2.cursor * 2 - rb) = 0x82C1;
            }
        }
        q++; n--; rb -= 2;
        if (ret != 0) continue;
        s32 bytes = 0;
        char *w = scratch;
        u16 *dst = (u16 *)((char *)m_text2.buffer + m_text2.cursor * 2 - ((n + 1) * 2));
        u16 v;
        while (*w != 0) {
            v = *w++;
            bytes++;
            v <<= 8;
            v |= *w & 0xFF;
            w++;
            *dst = v;
            dst++;
        }
        s32 m = (n + 1) - bytes;
        m_text2.delete_chars(m_text2.cursor - m, m);
        m_text2.cursor = m_text2.cursor - m;
        break;
    }
}

}
void draw_text_cursor(WindowDrawContext *context, NJS_POINT2 *cursor) {
    NJS_POINT2 pos[4];
    NJS_POINT2COL d;
    NJS_COLOR col[4];
    f32 bottom;
    f32 depth;

    if (actor_frame_tick & 0x10) {
        return;
    }
    depth = 0.1794f + context->depth;
    d.p = pos;
    d.col = col;
    d.tex = NULL;
    d.num = 4;
    d.col[0].color = 0xFF0080;
    d.col[1].color = 0xFF0080;
    d.col[2].color = 0xFF0080;
    d.col[3].color = 0xFF0080;
    pos[0].x = cursor->x;
    pos[0].y = cursor->y;
    pos[1].x = 5.0f + pos[0].x;
    pos[1].y = pos[0].y;
    pos[2].x = 5.0f + pos[0].x;
    bottom = 18.0f + pos[0].y;
    pos[2].y = bottom;
    pos[3].x = pos[0].x;
    pos[3].y = bottom;
    draw_polygon_2d(&d, 4, 6, depth);
}
extern "C" {

void TWindowKeyBoardBase::draw_text_glyphs(WindowDrawContext *context, NJS_POINT2 *cursor) {
    TexturedQuad q;
    NJS_POINT2 pos[4];
    NJS_POINT2COL d;
    NJS_COLOR col[4];
    f32 depth;
    u8 adv;
    u8 n;
    u16 ch;
    char *p;
    s32 ci;
    p = reinterpret_cast<char *>(candidate_buffer);
    if (p == NULL) {
        return;
    }
    depth = 0.0598f + context->depth;
    d.p = pos;
    d.col = col;
    d.tex = NULL;
    d.num = 4;
    while (*p != 0) {
        ci = (p == reinterpret_cast<char *>(current_candidate)) ? 1 : 2;
        n = p[1];
        p += 3;
        while (n-- != 0) {
            ch = *p++;
            if ((ch & 0xE0) == 0x80 || (ch & 0xE0) == 0xE0) {
                ch <<= 8;
                n--;
                ch |= *p++ & 0xFF;
            }
            adv = get_font_char_advance(map_char_to_font_code(ch));
            if (cursor->x + (f32)adv > context->inner_x + context->inner_w) {
                cursor->x = context->inner_x;
                cursor->y += 20.0f;
            }
            if ((s32)ch == 0x20) {
                cursor->x += (f32)(s32)adv;
            } else {
                q.x0 = cursor->x;
                q.y0 = cursor->y;
                set_glyph_quad_extents(adv, &q);
                context->transform_quad(&q);
                d.col[0].color = keyboard_key_colors[ci];
                d.col[1].color = d.col[0].color;
                d.col[2].color = d.col[0].color;
                d.col[3].color = d.col[0].color;
                pos[0].x = q.x0;
                pos[0].y = q.y0;
                pos[1].x = q.x1;
                pos[1].y = q.y0;
                pos[2].x = q.x1;
                pos[2].y = q.y1;
                pos[3].x = q.x0;
                pos[3].y = q.y1;
                draw_polygon_2d(&d, 4, 6, depth);
                cursor->x += (f32)(s32)adv;
            }
        }
    }
}

void TWindowKeyBoardBase::draw_composition_background(WindowDrawContext *box, NJS_POINT2 *cursor, u16 *text, u32 count) {
    TexturedQuad q;
    NJS_POINT2 pos[4];
    NJS_POINT2COL d;
    NJS_COLOR col[4];
    f32 depth;
    u16 ch;
    u8 adv;

    depth = 0.0598f + box->depth;
    d.p = pos;
    d.col = col;
    d.tex = NULL;
    d.num = 4;
    d.col[0].color = keyboard_key_colors[2];
    d.col[1].color = d.col[0].color;
    d.col[2].color = d.col[0].color;
    d.col[3].color = d.col[0].color;
    while ((s32)*text != 0 && count-- != 0) {
        ch = *text++;
        adv = get_font_char_advance(map_char_to_font_code(ch));
        if (cursor->x + (f32)adv > box->inner_x + box->inner_w) {
            cursor->x = box->inner_x;
            cursor->y += 20.0f;
        }
        if ((s32)ch == 0x20) {
            cursor->x += (f32)(s32)adv;
        } else {
            q.x0 = cursor->x;
            q.y0 = cursor->y;
            set_glyph_quad_extents(adv, &q);
            box->transform_quad(&q);
            pos[0].x = q.x0;
            pos[0].y = q.y0;
            pos[1].x = q.x1;
            pos[1].y = q.y0;
            pos[2].x = q.x1;
            pos[2].y = q.y1;
            pos[3].x = q.x0;
            pos[3].y = q.y1;
            draw_polygon_2d(&d, 4, 6, depth);
            cursor->x += (f32)adv;
        }
    }
}

void TWindowKeyBoardBase::draw_wrapped_text(WindowDrawContext *context, NJS_POINT2 *cursor) {
    TexturedQuad q;
    f32 scale;
    u8 n;
    char *p;
    u16 ch;
    u8 adv;

    p = reinterpret_cast<char *>(candidate_buffer);
    if (p == NULL) {
        return;
    }
    scale = -1.0f / (0.0897f + context->depth);
    while (*p != 0) {
        n = p[1];
        p += 3;
        while (n-- != 0) {
            ch = *p++;
            if ((ch & 0xE0) == 0x80 || (ch & 0xE0) == 0xE0) {
                ch <<= 8;
                n--;
                ch |= *p++ & 0xFF;
            }
            adv = bind_menu_font_glyph(map_char_to_font_code(ch), &q, -1);
            if (cursor->x + (f32)adv > context->inner_x + context->inner_w) {
                cursor->x = context->inner_x;
                cursor->y += 20.0f;
            }
            if ((s32)ch == 0x20) {
                cursor->x += (f32)(s32)adv;
            } else {
                q.x0 = cursor->x;
                q.y0 = cursor->y;
                set_glyph_quad_extents(adv, &q);
                context->transform_quad(&q);
                draw_textured_quad_at_depth(&q.x0, scale);
                cursor->x += (f32)(s32)adv;
            }
        }
    }
}

void TWindowKeyBoardBase::layout_wrapped_glyphs(WindowDrawContext *box, NJS_POINT2 *cursor, u16 *text, u32 count, s32 scaled) {
    TexturedQuad q;
    f32 depth;
    s32 code;
    u16 ch;
    u8 adv;

    depth = -1.0f / (0.0897f + box->depth);
    while ((s32)*text != 0 && count-- != 0) {
        ch = *text++;
        code = map_char_to_font_code(ch);
        if (scaled != 0) {
            adv = bind_menu_font_glyph(code, &q, -1);
        } else {
            adv = get_font_char_advance(code);
        }
        if (cursor->x + (f32)adv > box->inner_x + box->inner_w) {
            cursor->x = box->inner_x;
            cursor->y += 20.0f;
        }
        if ((s32)ch == 0x20) {
            cursor->x += (f32)(s32)adv;
        } else {
            if (scaled != 0) {
                q.x0 = cursor->x;
                q.y0 = cursor->y;
                set_glyph_quad_extents(adv, &q);
                box->transform_quad(&q);
                draw_textured_quad_at_depth(&q.x0, depth);
            }
            cursor->x += (f32)adv;
        }
    }
}

#pragma push
#pragma opt_common_subs off
void TWindowKeyBoardBase::draw_input_text(WindowDrawContext *ctx) {
    InputTextCursors stack;
    s32 composing_cursor;
    s32 text_cursor;
    s32 composing_remaining;
    s32 text_remaining;
    s32 draw_caret;
    u16 flags;
    u16 flags_again;
    draw_caret = 1;
    if (!(this->request_flags & 2) || (ctx->open_tick >= 0)) {
        stack.cursor.x = ctx->inner_x;
        stack.cursor.y = ctx->inner_y;
        layout_wrapped_glyphs(ctx, &stack.cursor, this->m_text.buffer, this->m_text.cursor, 0);
        flags = this->state_flags;
        if (flags & 2) {
            if (flags & 4) {
                this->draw_text_glyphs(ctx, &stack.cursor);
                draw_caret = 0;
            } else {
                draw_composition_background(ctx, &stack.cursor, this->m_text2.buffer, this->m_text2.length);
            }
        }
        reset_gauge(0);
        stack.cursor.x = ctx->inner_x;
        stack.cursor.y = ctx->inner_y;
        layout_wrapped_glyphs(ctx, &stack.cursor, this->m_text.buffer, this->m_text.cursor, 1);
        flags_again = this->state_flags;
        if (flags_again & 2) {
            if (flags_again & 4) {
                this->draw_wrapped_text(ctx, &stack.cursor);
            } else {
                layout_wrapped_glyphs(ctx, &stack.cursor, this->m_text2.buffer, this->m_text2.cursor, 1);
                stack.caret.x = stack.cursor.x;
                stack.caret.y = stack.cursor.y;
                composing_cursor = this->m_text2.cursor;
                composing_remaining = this->m_text2.length - composing_cursor;
                if (composing_remaining != 0) {
                    layout_wrapped_glyphs(ctx, &stack.cursor, this->m_text2.buffer + composing_cursor, composing_remaining, 1);
                }
            }
        } else {
            stack.caret.x = stack.cursor.x;
            stack.caret.y = stack.cursor.y;
        }
        text_cursor = this->m_text.cursor;
        text_remaining = this->m_text.length - text_cursor;
        if (text_remaining != 0) {
            layout_wrapped_glyphs(ctx, &stack.cursor, this->m_text.buffer + text_cursor, text_remaining, 1);
        }
        end_render_forward();
        if ((draw_caret != 0) && !(this->window_flags & 2)) {
            draw_text_cursor(ctx, &stack.caret);
        }
    }
}
#pragma pop

}
extern "C" {

void TWindowKeyBoardBase::render() {
    if ((is_state_flag_8_set() == 0) && ((has_text() != 0) || (this->request_flags & 2))) {
        WindowDrawContext *context = draw_default_entry();
        if (this->request_flags & 2) {
            draw_window_frame(context);
        }
        draw_input_text(context);
    }
}

void TWindowKeyBoardBase::run_task() {
    update_window();
    update_fade();
}

TWindowKeyBoardBase::~TWindowKeyBoardBase() {
    mem_free(candidate_buffer);
}
TWindowKeyBoardBase::TWindowKeyBoardBase() : TWindowBase((u8 *)&TWindowKeyBoardBase::window_descriptor, (s16)(4), (u8 *)(get_window_layout_position(0xB7))) {
    s32 language;

    this->m_name = class_name;
    language = current_language;
    this->init_keyboard_text_field(0, 0);
    m_text2.init(0, 0);
    active_text = &m_text;
    composition_flags = 0;
    request_flags = 0;
    active_input_mode = -1;
    candidate_buffer = 0;
    current_candidate = 0;
    last_candidate = 0;
    candidate_index = 0;
    candidate_count = 0;
    if (language == 0) {
        m_text2.init(0x24, 0);
        candidate_buffer = (u8 *)mem_alloc(0x194);
        candidate_bytes_remaining = 0x94;
    }
}

const char ask_dictionary_file[10] = "Ask_n.dic";

}
void load_ask_dictionary() {
    u8 *data;
    s32 size;
    s32 aligned;
    s32 aram;
    size = TGStream::get_resource_file_size((const char *)ask_dictionary_file);
    aligned = (size + 0x1F) & ~0x1F;
    aram = ARAlloc(aligned);
    data = load_disc_file(ask_dictionary_file);
    aram_transfer_sync(3, data, aram, aligned);
    safe_free(data);
    aram_dma_setup(aram, size, 3, 1, 0x2710);
    start_askdic();
}

int TWindowKeyBoardBase::is_state_flag_8_set() { return (this->state_flags >> 3) & 0x1; }
int test_keyboard_card_flag_128(s32 client) { return TWindowKeyBoardHard::test_card_flag(client, 128); }
int test_keyboard_card_flag_64(s32 client) { return TWindowKeyBoardHard::test_card_flag(client, 64); }
int test_keyboard_card_flag_32(s32 client) { return TWindowKeyBoardHard::test_card_flag(client, 32); }
int test_keyboard_card_flag_16(s32 client) { return TWindowKeyBoardHard::test_card_flag(client, 16); }
