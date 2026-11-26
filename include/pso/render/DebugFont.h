#ifndef PSO_RENDER_DEBUG_FONT_H
#define PSO_RENDER_DEBUG_FONT_H
#include "types.h"
#include <dolphin/mtx/GeoTypes.h>

enum DebugFontTexture { DEBUG_FONT_WIDTH = 128, DEBUG_FONT_HEIGHT = 128,
                       DEBUG_FONT_TEXTURE_BYTES = DEBUG_FONT_WIDTH * DEBUG_FONT_HEIGHT / 2 };
struct _GXTexObj;
extern u8 debug_font_texture_i4[DEBUG_FONT_TEXTURE_BYTES];
extern struct _GXTexObj debug_font_texture_object;
void render_debug_text(u32 enabled);

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

// Sets up the debug text buffer: record_count records at records, the text pool of pool_size bytes after them;
// 16-pixel glyphs, white text.
void init_debug_text_buffer(DebugTextRecord *records, s32 record_count, s32 pool_size);

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
// Inverts matrix in place; NULL inverts the current matrix.
void invert_matrix_in_place(MtxP matrix);

// Sets the size of queued debug text glyphs in pixels.
void set_debug_text_scale(u16 scale);
// Sets the colour (0xAARRGGBB) of the debug text queued after it.
void set_debug_text_color(s32 color);

#endif
