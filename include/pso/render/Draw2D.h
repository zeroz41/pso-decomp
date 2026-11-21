#ifndef PSO_RENDER_DRAW2D_H
#define PSO_RENDER_DRAW2D_H

#include "types.h"
#include "pso/system/NinjaTypes.h"

// Draw a 2D polygon (a triangle fan of count points) at a depth.
void draw_polygon_2d(NJS_POINT2COL *poly, s32 count, u32 flags, f32 depth);

#endif
