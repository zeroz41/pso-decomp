#include "pso/render/ChunkVertexJob.h"
#include "dolphin/mtx.h"
#include "pso/render/DebugFont.h"

void cache_chunk_vertex_colors(ChunkVertexJob *job, GC_Mtx *) {
    s32 count = job->count;
    const ColoredChunkVertex *src = reinterpret_cast<const ColoredChunkVertex *>(job->src);
    CachedChunkVertex *dst = reinterpret_cast<CachedChunkVertex *>(job->dst);
    f32 normalY;
    f32 normalXZ;
    normalXZ = 0.0f;
    normalY = 1.0f;
    while (count-- > 0) {
        matrix_mult_vec(NULL, &src->position, &dst->position);
        dst->color = src->color;
        src++;
        dst->normal.x = normalXZ;
        dst->normal.y = normalY;
        dst->normal.z = normalXZ;
        dst++;
    }
}
