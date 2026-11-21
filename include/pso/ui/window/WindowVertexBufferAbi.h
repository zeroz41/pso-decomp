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

typedef char WindowVertexSize[sizeof(WindowVertex) == 24 ? 1 : -1];
typedef char WindowVertexUVOffset[offsetof(WindowVertex, u) == 12 ? 1 : -1];
typedef char WindowVertexColorOffset[offsetof(WindowVertex, color) == 20 ? 1 : -1];

#endif
