#include "types.h"
#include "pso/misc/TWindowSubStatusDisp_80228CC0.h"
#include "pso/misc/TWindowSubStatusDisp_80228F5C.h"
#include "pso/misc/TWindowSubStatusDisp.h"

extern char *text_builder_write_cursor;
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
