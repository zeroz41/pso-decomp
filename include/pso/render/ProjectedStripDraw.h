#ifndef PSO_RENDER_PROJECTEDSTRIPDRAW_H
#define PSO_RENDER_PROJECTEDSTRIPDRAW_H

#include "types.h"
// The chunk-model renderer that follows this TU (text_803E2F28) is still reached through this header by its callers.
#include "pso/render/ChunkModelDraw.h"

struct ProjectedStripVertex {
    f32 x, y, w;
    f32 u, v;
    u32 color;
};

LAYOUT_ASSERT(ProjectedStripVertex_size, sizeof(ProjectedStripVertex) == 0x18);

// Ends a strip drawn after begin_screen_textured_draw.
void end_screen_textured_draw(void);
void draw_projected_textured_strip(ProjectedStripVertex *vertices, s32 count);
void begin_screen_textured_draw(s32 blended);

#endif
