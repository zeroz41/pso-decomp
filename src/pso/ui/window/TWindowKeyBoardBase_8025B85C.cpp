#include "types.h"
#include "pso/ui/window/TWindowCtrl_8024B7D4.h"
#include "pso/ui/window/TWindowSubStatusDisp_80144B14.h"
#include "pso/ui/window/TWindowSubStatusDisp_80228F5C.h"
#include "pso/ui/window/TWindowKeyBoardBase.h"
#include "pso/ui/window/TWindowKeyBoardSoft.h"
#include "pso/ui/chat/TWindowChat.h"
#include "pso/ui/window/TWindowSubComCard.h"
#include "pso/ui/Language.h"

#pragma readonly_strings on

extern "C" {
s32 is_chat_shortcut_set(int);
s32 TWindowKeyBoardSoft__sub_803E67D4(void *, void *);
saddr get_shared_text_buffer();

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

void TWindowKeyBoardBase::sub_8025B928() {  }

void TWindowKeyBoardBase::sub_8025B92C() {
    s8 text[0x100];
    s8 name[0x100];
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
                    count = TWindowKeyBoardSoft__sub_803E67D4(name, text);
                } while (count != 0);
                sub_8025CFA8((s32 *)name);
                name[0] = 0;
                write_name_and_text((char *)name, (char *)name);
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
    KeyboardTextBuffer *text;
    if (!(state_flags & 4)) {
        text = active_text;
        text->cursor = text->length;
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
    s8 text[0x100];
    s8 name[0x100];
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
                        count = TWindowKeyBoardSoft__sub_803E67D4(name, text);
                    } while (count != 0);
                    sub_8025CFA8((s32 *)name);
                    name[0] = 0;
                    write_name_and_text((char *)name, (char *)name);
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
    s8 text[0x100];
    s8 name[0x100];
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
                        count = TWindowKeyBoardSoft__sub_803E67D4(name, text);
                    } while (count != 0);
                    sub_8025CFA8((s32 *)name);
                    name[0] = 0;
                    write_name_and_text((char *)name, (char *)name);
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
            sub_8025C51C(2);
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
            sub_8025C51C(1);
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
            sub_8025C51C(0);
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
        sub_8025D664();
    }
}

void TWindowKeyBoardBase::key_left() {
    u32 cursor;
    KeyboardTextBuffer *text;
    if (state_flags & 4) {
        if ((request_flags & 1) && !((s32)composition_flags & 0x20)) {
            process_input();
            return;
        }
        sub_8025D7FC();
        return;
    }
    text = active_text;
    cursor = text->cursor;
    if (cursor != 0U) {
        text->cursor = cursor - 1;
    }
}

void TWindowKeyBoardBase::key_right() {
    u32 cursor;
    KeyboardTextBuffer *text;
    if (state_flags & 4) {
        if ((request_flags & 1) && !((s32)composition_flags & 0x20)) {
            sub_8025D664();
            return;
        }
        sub_8025D8C8();
        return;
    }
    text = active_text;
    cursor = text->cursor;
    if (cursor < (u32)text->length) {
        text->cursor = cursor + 1;
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
    if ((state_flags & 2) && ((u32)active_text->length == 0U)) {
        init();
    }
}

void TWindowKeyBoardBase::handle_backspace() {
    u32 *cursor;
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
    cursor = &active_text->cursor;
    if (*cursor == 0U) {
        state_flags = (u16) (flags | 0x20);
        return;
    }
    *cursor = *cursor - 1;
    active_text->delete_char();
    if ((state_flags & 2) && ((u32)active_text->length == 0U)) {
        init();
    }
}

void TWindowKeyBoardBase::key_backspace() {
    u16 flags;
    u32 cursor;
    KeyboardTextBuffer *text;
    flags = state_flags;
    if (flags & 4) {
        if (request_flags & 1) {
            update();
            return;
        }
        state_flags = (u16) (flags & 0xFFFFFFFB);
        return;
    }
    text = active_text;
    cursor = text->cursor;
    if (cursor != 0U) {
        text->cursor = cursor - 1;
        active_text->delete_char();
        if ((state_flags & 2) && ((u32)active_text->length == 0U)) {
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

void TWindowKeyBoardBase::sub_8025C51C(s32 slot) {
    s32 *str;
    u16 flags;
    u32 cursor;
    flags = state_flags;
    if (flags & 2) {
        if (flags & 4) {
            sub_8025DBDC(1);
        }
        commit_composition_text();
    }
    str = (s32 *)TWindowCtrl__sub_8024B7D4(slot);
    if (str != NULL) {
        text_builder_reset();
        cursor = m_text.cursor;
        if (cursor != 0U) {
            if (cursor == (u32)m_text.length) {
                text_builder_append((u8 *)" > ");
                text_builder_append((u8 *)str);
            } else {
                text_builder_append((u8 *)" ");
                text_builder_append((u8 *)str);
                text_builder_append((u8 *)" ");
            }
        } else {
            text_builder_append((u8 *)str);
            if ((u32)m_text.length != 0U) {
                text_builder_append((u8 *)" ");
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
    if (!(state_flags & 0x80) && this->m_input_mode >= 1U) {
        sub_8025DBDC(1);
        if (this->m_input_mode == 2) {
            state_flags |= 0x80;
        }
        if (this->m_input_mode == 3 && (state_flags & 2)) {
            commit_composition_text();
        }
    }
    if ((state_flags & 4) || ((s32)composition_flags & 0x40)) {
        commit_composition_text();
    }
    f = (s32)composition_flags;
    if ((f & 0x10) && code >= 0x80U) {
        return;
    }
    if ((f & 0x80) && !((s32)code >= 0x41 && (s32)code <= 0x5A)) {
        return;
    }
    if ((f & 0x100) && TWindowKeyBoardBase::is_alnum(code) == 0) {
        return;
    }
    f = (s32)composition_flags;
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
    if (this->m_input_mode == 0 && !(state_flags & 0x80)) {
        sub_8025DBDC(0);
    }
}

void TWindowKeyBoardBase::init() {
    this->m_text2.reset_state();
    active_text = &m_text;
    state_flags = (u16) (state_flags & ~0x86);
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
        sub_8025DBDC(1);
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
