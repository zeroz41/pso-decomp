#ifndef PSO_UI_WINDOW_SCREENQUADDRAW_H
#define PSO_UI_WINDOW_SCREENQUADDRAW_H

#include "types.h"

// Draws a rotated textured quad: q holds a corner, its two screen edges and the
// texture corner with its uv edges.
void draw_rotated_quad(f32 *q);

u32 get_coarse_time(void);
// Difference between two get_coarse_time values.
s32 calc_delta(s32 start, s32 end);
// Converts a get_coarse_time difference to microseconds.
u32 coarse_time_to_usec(u32 x);
extern "C" {
void begin_screen_draw(s32 mode);
void end_screen_draw(void);
void draw_textured_quad_at_depth(f32 *q, f32 depth);
}
void set_constant_material_color(u32 x);
extern "C" {
void set_draw_texture_and_color(s32 idx, s32 color);
}

union GxFifoValue { u8 u8v; u16 u16v; u32 u32v; s32 s32v; f32 f32v; };

#endif
