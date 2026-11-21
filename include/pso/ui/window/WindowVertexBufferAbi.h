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

#endif
