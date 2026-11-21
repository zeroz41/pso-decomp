#ifndef PSO_SYSTEM_TRAILSTRIP_H
#define PSO_SYSTEM_TRAILSTRIP_H

#include "types.h"
#include <stddef.h>

struct TrailStripVertex {
    f32 x, y, z;
    u32 color;
};
typedef char TrailStripVertex_size[sizeof(TrailStripVertex) == 0x10 ? 1 : -1];
typedef char TrailStripVertex_color[offsetof(TrailStripVertex, color) == 0xC ? 1 : -1];

// The renderer borrows a contiguous array of positions and packed ARGB colors.
extern "C" void draw_trail_strip(void *vertices, s32 count, s32 mode);
void draw_untextured_trail_strip(void *vertices, int count);

#endif
