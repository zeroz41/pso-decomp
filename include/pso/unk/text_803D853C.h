#ifndef PSO_UNK_TEXT_803D853C_H
#define PSO_UNK_TEXT_803D853C_H

#include "types.h"
#include <dolphin/mtx/GeoTypes.h>

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
void init_debug_text_buffer(DebugTextRecord *p, s32 n, s32 x);
}

// Queues text for render_debug_text at position (x << 16 | y in glyph cells, see pack_debug_text_position),
// copying it into the text pool.
void queue_debug_text(s32 position, const char *text);

// Queues val with prec digits before the point (zero padded) and five after it as debug text at position.
void print_float_padded(s32 position, s32 prec, f32 val);

// Copies the top of the matrix stack into dest. NULL copies it onto itself.
void get_current_matrix(GC_Mtx *dest);
extern "C" {
// dst = m * src; m is the current matrix when NULL.
void matrix_mult_vec(f32 (*m)[4], const struct Vec *src, struct Vec *dst);
}
extern "C" {
// Transforms count vectors from src into dst by m; m is the current matrix when NULL.
void matrix_mult_vec_array(f32 (*m)[4], const struct Vec *src, struct Vec *dst, u32 count);
}
void rotate_matrix_yxz(MtxP matrix, s32 x, s32 y, s32 z);
extern "C" {
// Prints a formatted line on the debug screen at slot `id`.
void debug_printf_at(s32 id, const char *fmt, ...);
// a . b
f32 vec3_dot(const struct Vec *a, const struct Vec *b);
// out = a x b; returns |out| (hand-written assembly, estimate precision).
f32 vec3_cross(const struct Vec *a, const struct Vec *b, struct Vec *out);
}
void rotate_matrix_zyx(MtxP matrix, s32 x, s32 y, s32 z);
extern "C" {
// vsprintf into a 128-byte buffer queued as debug text at pos.
void debug_printf_at(s32 pos, const char *format, ...);
}

#endif
