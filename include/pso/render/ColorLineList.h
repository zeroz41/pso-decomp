#ifndef PSO_RENDER_COLOR_LINE_LIST_H
#define PSO_RENDER_COLOR_LINE_LIST_H

#include "types.h"
#include "pso/system/NinjaTypes.h"
#include <stddef.h>

struct ColorLineVertex {
    f32 x, y;
};

struct ColorLineList {
    ColorLineVertex *verts;
    u32 *colors;
    NJS_TEX *tex;  // optional texture coordinates, NULL for flat lines
    s32 count;

    void draw_strip_swap_color(s32 count, s32 flags, f32 scale);
};

LAYOUT_ASSERT(ColorLineVertexSize, sizeof(ColorLineVertex) == 8);
LAYOUT_ASSERT(ColorLineListSize, sizeof(ColorLineList) == 0x10);
LAYOUT_ASSERT(ColorLineVertexOffset, offsetof(ColorLineList, verts) == 0);
LAYOUT_ASSERT(ColorLineColorOffset, offsetof(ColorLineList, colors) == 4);
LAYOUT_ASSERT(ColorLineCountOffset, offsetof(ColorLineList, count) == 0xC);

extern "C" void draw_color_lines(ColorLineList *lines, s32 count, s32 flags, f32 scale);

#endif
