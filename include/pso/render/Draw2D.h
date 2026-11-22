#ifndef PSO_RENDER_DRAW2D_H
#define PSO_RENDER_DRAW2D_H

#include "types.h"
#include "pso/system/NinjaTypes.h"

// A screen rectangle in 32-pixel tiles.
struct TileRect {
    f32 x0;
    f32 y0;
    f32 x1;
    f32 y1;
};

// Draw a 2D polygon (a triangle fan of count points) at a depth.
void draw_polygon_2d(NJS_POINT2COL *poly, s32 count, u32 flags, f32 depth);
// Mode 2 clips to rect, offset by the screen center; any other mode clips to
// the full 640x480 screen.
void set_viewport_scissor(int mode, const TileRect *rect);
// The screen center set_viewport_scissor offsets its rectangle by.
void set_screen_center(f32 x, f32 y);

extern "C" {
// Would set camera's view angle up for drawing; empty.
void camera_renderer_setup_nop(NJS_CAMERA *camera, s32 angle);
}

#endif
