// ---- pso/ui/window/TWindowSubStatusDisp_80228CC0
#include "types.h"
#include <string.h>
#include "pso/ui/window/TWindowSubStatusDisp_80228CC0.h"
#include "pso/ui/window/TWindowSubStatusDisp_80228F5C.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"

char * text_builder_write_cursor;
char text_builder_buffer[0x100];
extern s32 lbl_805DC790;
extern s32 lbl_805DC794;

void TWindowSubStatusDisp::append_play_time(u32 arg0) {
    u32 h = arg0 / 3600U;
    u32 rem = arg0 % 3600U;
    if (h > 99U) {
        text_builder_append((u8 *)"99'59\"59");
        return;
    }
    append_padded_number(h, 2);
    text_builder_append((u8 *)&lbl_805DC790);
    u32 m = rem / 60U;
    rem = rem % 60U;
    append_padded_number(m, 2);
    text_builder_append((u8 *)&lbl_805DC794);
    append_padded_number(rem, 2);
}

void TWindowSubStatusDisp::append_comma() {
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

// ---- pso/unk/text_80228E98
#include "types.h"
#include "pso/unk/text_80228E98.h"

char *fn_80228E98(s32 v, char *out) {
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

// ---- pso/ui/window/TWindowSubStatusDisp_80228F5C
#include "types.h"
#include "pso/unk/text_80228E98.h"
#include "pso/ui/window/TWindowSubStatusDisp_80228F5C.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/ui/window/TWindowKeyBoardSoft.h"
#include "pso/ui/Language.h"

extern "C" {
char *parse_text_control_codes(char *p, s32 *a, s32 *b);
void TWindowSubStatusDisp__sub_80228F5C(s32 arg0) {
    text_builder_write_cursor = fn_80228E98(arg0, text_builder_write_cursor);
}

s8 *TWindowSubStatusDisp::copy_message_page_text() {
    s8 *s = (s8 *)this;
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
        s = (s8 *)parse_text_control_codes((char *)s, &sjis, (s32 *)(0));
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
    return s + 2;
}

void text_builder_append(u8 *str) {
  s32 temp_r3;
  temp_r3 = TWindowKeyBoardSoft::strnlen((s8 *)str, (u32)0xFFU);
  strncpy(text_builder_write_cursor, (char *)str, temp_r3);
  text_builder_write_cursor[temp_r3] = 0;
  text_builder_write_cursor += temp_r3;
}
}
void text_builder_reset(void) {
    text_builder_write_cursor = text_builder_buffer;
    text_builder_buffer[0] = 0;
}
