#ifndef PSO_RENDER_CHUNKVERTEXJOB_H
#define PSO_RENDER_CHUNKVERTEXJOB_H

#include "types.h"

// The chunk dispatcher selects the record format from the vertex-list header.
struct ChunkVertexJob {
    u8 *dst;
    u8 *src;
    s32 count;
};

extern "C" {
// The dispatcher passes the matrix in r4; this format uses the current matrix
// through matrix_mult_vec(NULL, ...), so the second argument is unused.
void cache_chunk_vertex_colors(ChunkVertexJob *job, s32 matrix);
}

#endif
