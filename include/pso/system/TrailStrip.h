#ifndef PSO_SYSTEM_TRAILSTRIP_H
#define PSO_SYSTEM_TRAILSTRIP_H

#include "types.h"
#include <stddef.h>

struct TrailStripVertex {
    f32 x, y, z;
    u32 color;
};
LAYOUT_ASSERT(TrailStripVertex_size, sizeof(TrailStripVertex) == 0x10);
LAYOUT_ASSERT(TrailStripVertex_color, offsetof(TrailStripVertex, color) == 0xC);

// The renderer borrows a contiguous array of positions and packed ARGB colors.
void draw_trail_strip(void *vertices, s32 count, s32 mode);
void draw_untextured_trail_strip(void *vertices, int count);
// Loads the camera view matrix, then sets up untextured colour drawing, blended when `blended`.
void setup_world_color_draw(s32 blended);
void reset_player_transform(void);

#endif
