#include "pso/render/ChunkVertexJob.h"
struct Src_803E4CE8 { u8 pad[0xC]; s32 xc; };

struct Dst_803E4CE8 { u8 pad[0xC]; f32 xc; f32 x10; f32 x14; s32 x18; u8 pad1c[4]; };

extern "C" {
void matrix_mult_vec(s32, Src_803E4CE8 *, Dst_803E4CE8 *);
void cache_chunk_vertex_colors(ChunkVertexJob *job, s32) {
    s32 n = job->count;
    Src_803E4CE8 *src = (Src_803E4CE8 *)job->src;
    Dst_803E4CE8 *dst = (Dst_803E4CE8 *)job->dst;
    f32 b;
    f32 a;
    a = 0.0f;
    b = 1.0f;
    while (n-- > 0) {
        matrix_mult_vec(0, src, dst);
        dst->x18 = src->xc;
        src++;
        dst->xc = a;
        dst->x10 = b;
        dst->x14 = a;
        dst++;
    }
}

}
