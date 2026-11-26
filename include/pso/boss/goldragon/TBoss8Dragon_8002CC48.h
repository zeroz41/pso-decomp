#ifndef PSO_BOSS_GOLDRAGON_TBOSS8DRAGON_8002CC48_H
#define PSO_BOSS_GOLDRAGON_TBOSS8DRAGON_8002CC48_H

#include "types.h"
#include "pso/system/NinjaTypes.h"

struct Vec;

// A chunk mesh built at run time: `width` x (`strips` + 1) vertices joined by `strips` triangle strips,
// drawn through its own NJS_CNK_MODEL and NJS_OBJECT.
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

f32 random_range(f32 lo, f32 hi);
f32 rand_signed_unit(void);

#endif
