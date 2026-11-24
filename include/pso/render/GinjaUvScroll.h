#ifndef PSO_RENDER_GINJAUVSCROLL_H
#define PSO_RENDER_GINJAUVSCROLL_H

#include "types.h"

struct GinjaDrawRecord;
struct GinjaModel;

extern "C" {
s32 has_texture_scroll_entry(const GinjaDrawRecord *record, u16 texture);
void set_ginja_texture_wrap_repeat(GinjaDrawRecord *record);
void collect_scroll_uv_entries__19TOComputerMachine01FiPvi(s32 arg0, GinjaModel *model, s32 texture);
// Scrolls the UVs of one mesh of a Ginja model; rewrite != 0 also patches
// the model's display list. The coordinate sums wrap at 16 bits.
void scroll_ginja_mesh_uvs(GinjaModel *model, s32 du, s32 dv, u16 mesh, s32 rewrite);
}

#endif
