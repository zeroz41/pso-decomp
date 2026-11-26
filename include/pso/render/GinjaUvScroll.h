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

// Adds (du, dv) mod 256 to the uvs of every strip after each texture-id chunk
// (type 8) for texture_id in a Ninja chunk polygon list.
void scroll_chunk_plist_uvs(s16 *plist, s16 du, s16 dv, u16 texture_id);
// Moves *plist past one chunk: bits chunks (0-5) and the end chunk take one
// s16, a texture-id chunk two, any other chunk its header, size and size s16s.
void advance_chunk_plist(s16 **plist);

#endif
