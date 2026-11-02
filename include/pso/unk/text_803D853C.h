#ifndef PSO_UNK_TEXT_803D853C_H
#define PSO_UNK_TEXT_803D853C_H

#include "types.h"

// One queued debug text line: screen position, glyph size, vertex colour and the text, which lives in the pool
// that follows the records (render_debug_text draws them).
struct DebugTextRecord {
    s16 x;
    s16 y;
    u16 size;
    s16 pad_6;
    u32 color;
    char *text;
};

extern "C" {
// Sets up the debug text buffer: n records at p, the text pool after them; 16-pixel glyphs, white text.
void fn_803D8030(DebugTextRecord *p, s32 n, s32 x);
}

void get_current_matrix(void *m);
extern "C" {
// dst = m * src; m is the current matrix when NULL.
void matrix_mult_vec(f32 (*m)[4], const struct Vec *src, struct Vec *dst);
}
void rotate_matrix_yxz(s32 matrix, s32 arg1, s32 arg2, s32 arg3);
extern "C" {
// Prints a formatted line on the debug screen at slot `id`.
void debug_printf_at(s32 id, const char *fmt, ...);
// a . b
f32 vec3_dot(const struct Vec *a, const struct Vec *b);
// out = a x b; returns |out| (hand-written assembly, estimate precision).
f32 vec3_cross(const struct Vec *a, const struct Vec *b, struct Vec *out);
void rotate_matrix_zyx(void *m, s32 x, s32 y, s32 z);
// vsprintf into a 128-byte buffer queued as debug text at pos.
void debug_printf_at(s32 pos, const char *format, ...);
}

#endif
