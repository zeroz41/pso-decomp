#ifndef PSO_RENDER_GINJAUVSCROLL_H
#define PSO_RENDER_GINJAUVSCROLL_H

#include "types.h"

extern "C" {
// Scrolls the UVs of one mesh of a Ginja model; rewrite != 0 also patches
// the model's display list. The coordinate sums wrap at 16 bits.
void scroll_ginja_mesh_uvs(void *model, s32 du, s32 dv, u16 mesh, s32 rewrite);
}

#endif
