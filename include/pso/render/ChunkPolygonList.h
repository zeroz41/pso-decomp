#ifndef PSO_RENDER_CHUNKPOLYGONLIST_H
#define PSO_RENDER_CHUNKPOLYGONLIST_H

#include "types.h"

struct ChunkColorVertex {
    f32 x, y, z;
    u8 pad0C[0x18 - 0x0C];
    u32 color;
    u32 pad1C;
};

// Saved polygon-list positions, indexed by the chunk cache command's slot.
extern s16 *chunk_polygon_list_cache[126];
void dispatch_chunk_polygon_list(s16 *list, s32 buffer);
extern "C" void draw_chunk_color_tex_strips(s16 *list, ChunkColorVertex *vertices, u32 info, s32 large);

#endif
