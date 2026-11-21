#ifndef PSO_RENDER_TRIANGLEFAN3D_H
#define PSO_RENDER_TRIANGLEFAN3D_H

#include "pso/system/NinjaTypes.h"
#include <stddef.h>

typedef char NJS_TEX_size[sizeof(NJS_TEX) == 4 ? 1 : -1];
typedef char NJS_POINT3COL_size[sizeof(NJS_POINT3COL) == 0x10 ? 1 : -1];
typedef char NJS_POINT3COL_colors_offset[offsetof(NJS_POINT3COL, col) == 4 ? 1 : -1];
typedef char NJS_POINT3COL_uv_offset[offsetof(NJS_POINT3COL, tex) == 8 ? 1 : -1];

void draw_tri_fan_3d(NJS_POINT3COL *fan, s32 count, u32 flags);

#endif
