#ifndef PSO_RENDER_DRAW2D_H
#define PSO_RENDER_DRAW2D_H

#include "types.h"
#include "pso/system/NinjaTypes.h"

// Draw a 2D polygon (a triangle fan of count points) at a depth.
void draw_polygon_2d(NJS_POINT2COL *poly, s32 count, u32 flags, f32 depth);
// Mode 2 clips to rect (x0, y0, x1, y1 in 32-pixel tiles, offset by the
// screen center); any other mode clips to the full 640x480 screen.
void set_viewport_scissor(int mode, void *rect);
// The screen center set_viewport_scissor offsets its rectangle by.
void set_screen_center(f32 x, f32 y);

#endif
