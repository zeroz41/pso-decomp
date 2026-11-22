#include "types.h"
#include "pso/ui/window/TWindowSubStatusDisp_80144B14.h"
#include "pso/ui/window/KeyboardTextBuffer.h"
#include "pso/quest/TQuestVmDownLoadServer.h"
#include "pso/ui/Language.h"

u16 keyboard_dakuten_kana_sjis[20] = {33449, 33451, 33453, 33455, 33457, 33459, 33461, 33463, 33465, 33467, 33469, 33471, 33474, 33476, 33478, 33485, 33488, 33491, 33494, 33497};
u16 keyboard_handakuten_kana_sjis[6] = {33485, 33488, 33491, 33494, 33497, 0};
u16 keyboard_small_kana_sjis[10] = {33440, 33442, 33444, 33446, 33448, 33474, 33506, 33508, 33510, 33517};

void KeyboardTextBuffer::append_text(u8 *text) {
    u8 c;

    if (text == NULL) {
        return;
    }
    while ((s8)*text != 0) {
        c = *text++;
        if (would_overflow_with((s32)c) != 0) {
            break;
        }
        insert_char_slot();
        buffer[cursor] = c;
        cursor++;
    }
}

void KeyboardTextBuffer::set_text_from_string(char *s) {
    u16 *dst;
    s32 jp;
    s32 c;
    dst = buffer;
    length = 0;
    cursor = length;
    if (s == NULL) {
        return;
    }
    jp = current_language == LANGUAGE_JAPANESE ? 1 : 0;
    if (*s == 9) {
        s += 2;
        switch (s[-1]) {
        case 'J':
            if (jp == 0) {
                return;
            }
            break;
        case 'E':
            if (jp == 1) {
                return;
            }
            break;
        }
    }
    while (*s != 0) {
        c = *(u8 *)s++;
        if (jp != 0) {
            if ((c & 0xE0) == 0x80 || (c & 0xE0) == 0xE0) {
                c = ((u8)c << 8) | *(u8 *)s++;
            }
        }
        *dst++ = c;
        length++;
    }
    *dst = 0;
    cursor = length;
}

void KeyboardTextBuffer::insert_char(u16 ch) {
    switch (ch) {
    case 0x814A:
        if (apply_dakuten_to_last_char() != 0) {
            return;
        }
        break;
    case 0x814B:
        if (apply_handakuten_to_last_char() != 0) {
            return;
        }
        break;
    case 0xFF20:
        make_last_char_small_kana();
        return;
    }
    if (would_overflow_with(ch) == 0) {
        insert_char_slot();
        buffer[cursor] = ch;
        cursor++;
    }
}

s32 KeyboardTextBuffer::is_buffer_blank() {
    u16 *p;
    if (buffer == NULL) {
        return 1;
    }
    p = buffer;
    while ((s32)*p != 0) {
        if ((s32)*p++ != 0x20) {
            return 0;
        }
    }
    return 1;
}

s32 KeyboardTextBuffer::make_last_char_small_kana() {
    u16 *p;
    u16 c;
    s32 i;
    if (cursor == 0) {
        return 0;
    }
    p = buffer + cursor;
    c = p[-1];
    if (c >= 0x8340) {
        c -= 0xA1;
    }
    for (i = 0; i < 10; i++) {
        if (c == keyboard_small_kana_sjis[i]) {
            p[-1]--;
            return 1;
        }
    }
    if (c == 0x82A9) {
        p[-1] = 0x8395;
        return 1;
    }
    if (c == 0x82AF) {
        p[-1] = 0x8396;
        return 1;
    }
    return 0;
}

s32 KeyboardTextBuffer::apply_handakuten_to_last_char() {
    u16 *last;
    u16 c;
    s32 i;
    if (cursor == 0) {
        return 0;
    }
    last = &buffer[cursor];
    c = last[-1];
    if (c >= 0x8340) {
        c -= 0xA1;
    }
    for (i = 0; i < 5; i++) {
        if (c == keyboard_handakuten_kana_sjis[i]) {
            last[-1] += 2;
            return 1;
        }
    }
    return 0;
}

s32 KeyboardTextBuffer::apply_dakuten_to_last_char() {
    u16 *p;
    u16 c;
    s32 i;
    if (cursor == 0) {
        return 0;
    }
    p = buffer + cursor;
    c = p[-1];
    if (c >= 0x8340) {
        c -= 0xA1;
    }
    for (i = 0; i < 20; i++) {
        if (c == keyboard_dakuten_kana_sjis[i]) {
            p[-1]++;
            return 1;
        }
    }
    if (c == 0x82A4) {
        p[-1] = 0x8394;
        return 1;
    }
    return 0;
}

void KeyboardTextBuffer::delete_chars(s32 pos, s32 n) {
    u16 *src;
    u16 *dst;
    u16 c;

    dst = (u16 *)((saddr)buffer + pos * 2);
    if ((s32) *dst != 0) {
        src = dst + n;
        do {
            *dst = *src;
            dst += 1;
            c = *src;
            src += 1;
        } while ((s32) c != 0);
        length -= n;
    }
}

void KeyboardTextBuffer::delete_char() {
    u16 *src;
    u16 *dst;
    u16 c;

    dst = buffer + cursor;
    if ((s32) *dst != 0) {
        src = dst + 1;
        do {
            *dst = *src;
            dst += 1;
            c = *src;
            src += 1;
        } while ((s32) c != 0);
        length -= 1;
    }
}

void KeyboardTextBuffer::make_room_in_buffer(s32 pos, s32 n) {
    u32 len;
    u16 *p;
    u16 *q;
    p = &buffer[pos];
    len = 0;
    while ((s32)*p != 0) {
        p++;
        len++;
    }
    q = p + n;
    do {
        *q-- = *p--;
    } while (len-- != 0);
    length += n;
}

void KeyboardTextBuffer::insert_char_slot() {
    u32 len;
    u16 *p;
    u16 *q;
    p = &buffer[cursor];
    len = 0;
    while ((s32)*p != 0) {
        p++;
        len++;
    }
    q = p + 1;
    do {
        *q-- = *p--;
    } while (len-- != 0);
    length++;
}

s32 KeyboardTextBuffer::measure_char_overflow(u16 code, u32 *x, u32 *y, u32 *count) {
    u8 w;
    code = map_char_to_font_code(code);
    (*count)++;
    if (code & 0xFF00) {
        (*count)++;
    }
    if (*count > capacity) {
        return 1;
    }
    if (line_pixels == 0) {
        return 0;
    }
    w = get_font_char_advance(code);
    *x += w;
    if (*x <= width) {
        return 0;
    }
    *y += 0x14;
    *x = w;
    return (*y >= line_pixels) ? 1 : 0;
}

s32 KeyboardTextBuffer::check_text_overflow(u16 *buf) {
    u32 x;
    u32 y;
    u32 count;
    u16 *p;
    s32 n;
    s32 c;
    count = 0;
    y = 0;
    x = 0;
    p = buffer;
    n = cursor;
    while (n > 0) {
        if (measure_char_overflow(*p, &x, &y, &count) != 0) {
            *p = 0;
            *buf = 0;
            cursor -= n;
            length -= n;
            return 1;
        }
        p++;
        n--;
    }
    for (p = buf; (c = *p) != 0; p++) {
        if (measure_char_overflow(c, &x, &y, &count) != 0) {
            *p = 0;
            buffer[cursor] = 0;
            length = cursor;
            return 1;
        }
    }
    p = &buffer[cursor];
    n = length - cursor;
    while (n > 0) {
        if (measure_char_overflow(*p, &x, &y, &count) != 0) {
            *p = 0;
            length -= n;
            return 1;
        }
        p++;
        n--;
    }
    return 0;
}

s32 KeyboardTextBuffer::would_overflow_with(u16 ch) {
    u32 n;
    u32 x;
    u32 y;
    u32 count;
    u16 *p;
    u16 c;

    x = y = count = n = 0;
    p = buffer;
    while ((s32)*p != 0 || n == cursor) {
        if (n == cursor) {
            c = ch;
        } else {
            c = *p++;
        }
        n++;
        if (measure_char_overflow(c, &x, &y, &count) != 0) {
            return 1;
        }
    }
    return 0;
}

void KeyboardTextBuffer::reset_state() {
    cursor = 0;
    length = 0;
    if (buffer != NULL) {
        *buffer = 0;
    }
}
