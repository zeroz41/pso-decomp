#ifndef PSO_UNK_TEXT_803E2D70_H
#define PSO_UNK_TEXT_803E2D70_H

#include "types.h"
// The chunk-model renderer that follows this TU (text_803E2F28) is still reached through this header by its callers.
#include "pso/unk/text_803E2F28.h"

struct ProjectedStripVertex {
    f32 x, y, w;
    f32 u, v;
    u32 color;
};

LAYOUT_ASSERT(ProjectedStripVertex_size, sizeof(ProjectedStripVertex) == 0x18);

extern "C" {
void draw_projected_textured_strip(ProjectedStripVertex *vertices, s32 count);
void TLobby__sub_803E2EE4(s32 blended);
}

#endif
