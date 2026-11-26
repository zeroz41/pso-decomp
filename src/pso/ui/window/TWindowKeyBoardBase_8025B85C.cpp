#include "pso/ui/chat/ChatShortcuts.h"
#include "types.h"
#include "pso/ui/window/TWindowCtrl.h"
#include "pso/ui/window/TWindowSubStatusDisp_80144B14.h"
#include "pso/ui/window/TextBuilder.h"
#include "pso/ui/window/TWindowKeyBoardBase.h"
#include "pso/ui/window/TWindowKeyBoardSoft.h"
#include "pso/quest/QuestDownloadRequests.h"
#include "pso/ui/chat/TWindowChat.h"
#include "pso/ui/window/TWindowSubComCard.h"
#include "pso/ui/Language.h"
#include "pso/enemy/BattleParamTables.h"

#pragma readonly_strings on

extern "C" {

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
            if (!(state_flags & 0x10)) {
                do {
                    this->candidate_count = count;
                    count = ime_request_extend_segment(name, text);
                } while (count != 0);
                add_conversion_candidate(name);
                name[0] = 0;
                write_name_and_text(name, name);
                goto block_5;
            }
        } else {
block_5:
            if ((s32) this->candidate_index != 0xF1) {
                set_kana_mode();
                return;
            }
            set_kanji_mode();
        }
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
                if (!(state_flags & 0x10)) {
                    do {
                        this->candidate_count = count;
                        count = ime_request_extend_segment(name, text);
                    } while (count != 0);
                    add_conversion_candidate(name);
                    name[0] = 0;
                    write_name_and_text(name, name);
                    goto block_6;
                }
            } else {
block_6:
                set_kana_mode();
            }
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
                if (!(state_flags & 0x10)) {
                    do {
                        this->candidate_count = count;
                        count = ime_request_extend_segment(name, text);
                    } while (count != 0);
                    add_conversion_candidate(name);
                    name[0] = 0;
                    write_name_and_text(name, name);
                    goto block_6;
                }
            } else {
block_6:
                set_kanji_mode();
            }
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
                text_builder_append((const char *)name);
            } else {
                text_builder_append(" ");
                text_builder_append((const char *)name);
                text_builder_append(" ");
            }
        } else {
            text_builder_append((const char *)name);
            if (m_text.length != 0U) {
                text_builder_append(" ");
            }
        }
        m_text.append_text((u8 *)get_shared_text_buffer());
    }
}

void TWindowKeyBoardBase::set_text(char *s) { m_text.set_text_from_string(s); }

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

}
