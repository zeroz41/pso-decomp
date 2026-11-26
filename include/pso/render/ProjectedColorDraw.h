#ifndef PSO_RENDER_PROJECTEDCOLORDRAW_H
#define PSO_RENDER_PROJECTEDCOLORDRAW_H

#include "types.h"

// Vertex of draw_projected_quads: a view-space position and an RGBA colour.
struct ProjectedVertex {
    f32 x;
    f32 y;
    f32 z;
    u32 color;
};

// Ends a projected colour draw.
void end_projected_color_draw();
// Draws n vertices as a triangle strip, dividing x and y by -z.
void draw_projected_quads(ProjectedVertex *vertices, s32 n);
// Loads the screen-space matrix and the colour vertex state for draw_projected_quads,
// blended when mode != 0.
void setup_projected_color_draw(s32 mode);

#endif
