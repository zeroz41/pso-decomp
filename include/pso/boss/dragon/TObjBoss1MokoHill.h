#ifndef PSO_BOSS_DRAGON_TOBJBOSS1MOKOHILL_H
#define PSO_BOSS_DRAGON_TOBJBOSS1MOKOHILL_H

#include "types.h"
#include "pso/system/NinjaTypes.h"

f32 rand_signed_unit(void);
f32 random_range(f32 lo, f32 hi);

// A texture coordinate of the trail model as load_resources saved it, one per strip index.
struct TrailUV {
    s16 u;
    s16 v;
};
// A trail model vertex higher than 15 that bobs while the mound is active (load_resources lists them).
struct TrailRaisedVertex {
    f32 *dst;
    f32 base;
    f32 ofs;
    s32 state; // 0 sinking, 1 rising, else frames left to wait
};

struct Vec;

// A chunk mesh built at run time: `width` x (`strips` + 1) vertices joined by `strips` triangle strips,
// drawn through its own NJS_CNK_MODEL and NJS_OBJECT (0x68 bytes, no vtable).
// Polygon list: the copied material words, a strip chunk head (0x242), its size, the strip count, then
// per strip its index count and (index, u, v) triples. Vertex list: head word, count word, vertices.
class ChunkStripGrid {
public:
    // One entry of the vertex list as the constructor lays it out.
    struct Vertex {
        NJS_POINT3 pos;
        NJS_POINT3 normal;
    };

    ChunkStripGrid(s32 width, s32 strips, s32 materialWords, s16 *material);
    ~ChunkStripGrid();
    s16 *get_strips();
    Vertex *get_vertices();

    s32 width;
    s32 strips;
    s32 stripWords;
    s32 materialWords;
    u32 *vertices;
    s16 *polygons;
    NJS_CNK_MODEL model;
    NJS_OBJECT object;
};

LAYOUT_ASSERT(DragonTrailGridVertex_size, sizeof(ChunkStripGrid::Vertex) == 0x18);
LAYOUT_ASSERT(ChunkStripGrid_size, sizeof(ChunkStripGrid) == 0x68);

f32 apply_default_velocity_scale(Vec *vector);
f32 apply_velocity_scale(Vec *vector, f32 radius, f32 height);

#endif
