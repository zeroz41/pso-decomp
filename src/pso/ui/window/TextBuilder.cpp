#include "pso/ui/font/TNECFontEORFunction.h"
#include "types.h"
#include <string.h>
#include "pso/ui/window/TextBuilder.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/ui/window/TWindowSubStatusDisp_80144B14.h"
#include "pso/ui/window/BoundedStrlen.h"

char * text_builder_write_cursor;
char text_builder_buffer[0x100];

void TWindowSubStatusDisp::append_play_time(u32 time) {
    u32 h = time / 3600U;
    u32 rem = time % 3600U;
    if (h > 99U) {
        text_builder_append("99'59\"59");
        return;
    }
    append_padded_number(h, 2);
    text_builder_append("'");
    u32 m = rem / 60U;
    rem = rem % 60U;
    append_padded_number(m, 2);
    text_builder_append("\"");
    append_padded_number(rem, 2);
}

void append_comma() {
    if (text_builder_write_cursor != text_builder_buffer) {
        *text_builder_write_cursor++ = 0x2c;
        *text_builder_write_cursor = 0;
    }
}
void append_text_space(void) {
    if (text_builder_write_cursor != text_builder_buffer) {
        *text_builder_write_cursor++ = 0x20;
        *text_builder_write_cursor = 0;
    }
}
void append_padded_number(s32 v, u8 n) {
    char buf[16];
    u32 i;
    if (v == 0) {
        for (i = 0; i < n; i++) {
            *text_builder_write_cursor++ = '0';
        }
        *text_builder_write_cursor = 0;
        return;
    }
    if (v < 0) {
        v *= -1;
        *text_builder_write_cursor++ = '-';
    }
    for (i = 0; i < n; i++) {
        buf[i] = v % 10;
        v /= 10;
    }
    for (i = 0; i < n; i++) {
        *text_builder_write_cursor++ = buf[n - i - 1] + '0';
    }
    *text_builder_write_cursor = 0;
}


char *format_int_decimal(s32 v, char *out) {
    u8 digits[16];
    u32 n;
    u32 i;
    if (v == 0) {
        *out = '0';
        *++out = 0;
        return out;
    }
    if (v < 0) {
        *out = '-';
        v *= -1;
        out++;
    }
    n = 0;
    for (i = 0; i < 16; i++) {
        digits[n] = v % 10;
        v /= 10;
        if (v <= 0) {
            break;
        }
        n++;
    }
    if (n >= 16) {
        n = 15;
    }
    for (i = 0; i < n + 1; i++) {
        *out = digits[n - i] + '0';
        out++;
    }
    *out = 0;
    return out;
}

#include "pso/ui/window/TWindowKeyBoardSoft.h"
#include "pso/ui/Language.h"

void text_builder_append_int(s32 value) {
    text_builder_write_cursor = format_int_decimal(value, text_builder_write_cursor);
}

s8 *copy_message_page_text(const s8 *text) {
    const s8 *s = text;
    s32 sjis;
    s8 *d;
    sjis = 0;
    if (current_language == LANGUAGE_JAPANESE) {
        sjis = 1;
    }
    d = (s8 *)text_builder_write_cursor;
    while (*s != 0) {
        if (*s == 9 && ((u8 *)s)[1] == 'P') {
            break;
        }
        s = reinterpret_cast<const s8 *>(parse_text_control_codes(reinterpret_cast<const char *>(s), &sjis, NULL));
        s32 t = *(u8 *)s;
        if (t == 9 && ((u8 *)s)[1] == 'P') {
            continue;
        }
        if ((s8)t == 0) {
            continue;
        }
        *d = *s++;
        if (sjis != 0) {
            s32 c = *(u8 *)d & 0xe0;
            if (c == 0x80 || c == 0xe0) {
                *++d = *s++;
            }
        }
        d++;
    }
    text_builder_write_cursor = (char *)d;
    *d = 0;
    if (*s == 0) {
        return 0;
    }
    return const_cast<s8 *>(s + 2);
}

void text_builder_append(const char *str) {
  s32 num;
  num = bounded_strlen(str, (u32)0xFFU);
  strncpy(text_builder_write_cursor, str, num);
  text_builder_write_cursor[num] = 0;
  text_builder_write_cursor += num;
}
void text_builder_reset(void) {
    text_builder_write_cursor = text_builder_buffer;
    text_builder_buffer[0] = 0;
}
