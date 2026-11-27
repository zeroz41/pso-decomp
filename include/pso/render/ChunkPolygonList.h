#ifndef PSO_RENDER_CHUNKPOLYGONLIST_H
#define PSO_RENDER_CHUNKPOLYGONLIST_H

#include "types.h"

// Saved polygon-list positions, indexed by the chunk cache command's slot.
extern s16 *chunk_polygon_list_cache[126];
#ifdef __cplusplus
struct ChunkCachedVertex;
void dispatch_chunk_polygon_list(s16 *list, ChunkCachedVertex *vertex_buffer);
void draw_chunk_color_tex_strips(s16 *list, ChunkCachedVertex *vertices, u32 info, s32 large);
#endif

#endif
