#ifndef PSO_UI_WINDOW_WINDOWVERTEXBUFFERABI_H
#define PSO_UI_WINDOW_WINDOWVERTEXBUFFERABI_H

#include "types.h"
#include <stddef.h>

struct WindowVertex {
    f32 x;
    f32 y;
    f32 depth;
    f32 u;
    f32 v;
    u32 color;
};

LAYOUT_ASSERT(WindowVertexSize, sizeof(WindowVertex) == 24);
LAYOUT_ASSERT(WindowVertexUVOffset, offsetof(WindowVertex, u) == 12);
LAYOUT_ASSERT(WindowVertexColorOffset, offsetof(WindowVertex, color) == 20);

struct NJS_POINT2;

// Sets the eight vertices of a window strip to the origin at depth `depth` with colour `color`.
void reset_window_vertices(WindowVertex *vertices, f32 depth, s32 color);
// Copies the texture coordinates of point table `index` into the eight vertices.
void copy_window_point_table(WindowVertex *vertices, s32 index);
// Fills a table of eight texture points for the rectangle (x, y, width) of a window strip.
void fill_window_point_table(NJS_POINT2 *points, f32 x, f32 y, f32 width);
// Selects the texture with the given surface id and draws the vertices as a strip.
void draw_window_vertices(WindowVertex *vertices, s32 count, u32 surface_id, s32 blended);

#endif
