#ifndef PSO_RENDER_CHUNKVERTEXJOB_H
#define PSO_RENDER_CHUNKVERTEXJOB_H

#include "types.h"
#include <dolphin/mtx/GeoTypes.h>

// The chunk dispatcher selects the record format from the vertex-list header.
struct ChunkVertexJob {
    u8 *dst;
    u8 *src;
    s32 count;
};

// The vertex formats cache_chunk_vertex_colors reads (src) and writes (dst).
struct ColoredChunkVertex {
    Vec position;
    u32 color;
};

struct CachedChunkVertex {
    Vec position;
    Vec normal;
    u32 color;
    u32 padding;
};

LAYOUT_ASSERT(ColoredChunkVertexSize, sizeof(ColoredChunkVertex) == 0x10);
LAYOUT_ASSERT(CachedChunkVertexSize, sizeof(CachedChunkVertex) == 0x20);

// The dispatcher passes the matrix in r4; this format uses the current matrix
// through matrix_mult_vec(NULL, ...), so the second argument is unused.
void cache_chunk_vertex_colors(ChunkVertexJob *job, GC_Mtx *matrix);

#endif
