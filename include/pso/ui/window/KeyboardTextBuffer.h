#ifndef PSO_UI_WINDOW_KEYBOARDTEXTBUFFER_H
#define PSO_UI_WINDOW_KEYBOARDTEXTBUFFER_H

#include "types.h"

// An editable wide-character line of the keyboard window (descriptive name: the binary has no name for it).
// TWindowKeyBoardBase holds two.
struct KeyboardTextBuffer {
    u16 *buffer;
    u32 cursor;
    u32 width;
    u32 line_pixels;
    s32 length;
    u32 capacity;

    KeyboardTextBuffer();
    ~KeyboardTextBuffer();
    void init(u32 width, u32 lines);
    void append_text(u8 *text);
    void set_text_from_string(char *s);
    void insert_char(u16 ch);
    s32 is_buffer_blank();
    s32 make_last_char_small_kana();
    s32 apply_handakuten_to_last_char();
    s32 apply_dakuten_to_last_char();
    void delete_chars(s32 pos, s32 n);
    void delete_char();
    void make_room_in_buffer(s32 pos, s32 n);
    void insert_char_slot();
    s32 measure_char_overflow(u16 code, u32 *x, u32 *y, u32 *count);
    s32 check_text_overflow(u16 *buf);
    s32 would_overflow_with(u16 ch);
    void reset_state();
};

LAYOUT_ASSERT(KeyboardTextBuffer_size, sizeof(KeyboardTextBuffer) == 0x18);

#endif
