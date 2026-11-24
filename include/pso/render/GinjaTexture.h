#ifndef PSO_RENDER_GINJATEXTURE_H
#define PSO_RENDER_GINJATEXTURE_H

#include "pso/render/GinjaMaterialState.h"

typedef struct GinjaTextureError {
    s32 entry_index;
    s32 pad_04;
    s32 code;
    s32 pad_0C;
    s32 pad_10;
    s32 pad_14[3];
} GinjaTextureError;

LAYOUT_ASSERT(GinjaTextureErrorSize, sizeof(GinjaTextureError) == 0x20);

// The last texture error: code, and the texture list entry it happened at.
extern GinjaTextureError texture_error;
// The loaded textures (texture_state_count slots) and the surfaces they share (texture_surface_count slots).
extern GinjaTextureState *texture_states;
extern s32 texture_state_count;
extern GinjaSurfaceState *texture_surfaces;
extern s32 texture_surface_count;

#ifdef __cplusplus
// GinjaTextureTable.cpp
void init_texture_tables(GinjaTextureState *states, s32 count, GinjaSurfaceState *surfaces, s32 surface_count);
void init_texture_states(GinjaTextureState *states, s32 count);
void init_texture_surfaces(GinjaSurfaceState *surfaces, s32 count);
// The texture slot whose surface has this id, or -1.
s32 find_texture_by_surface_id(u32 id);
// The texture slot whose surface has this id and whose palette bank is tlut_name, or -1.
s32 find_texture_by_surface_and_tlut(u32 id, u32 tlut_name);
// A free texture slot and, when surface is not NULL, a free surface; the texture slot's index or -1.
s32 find_free_texture_slot(GinjaTextureState **texture, GinjaSurfaceState **surface);
// Clears the texture's surface slot once nothing references it, then the texture entry itself.
void clear_unreferenced_texture_entry(GinjaTextureState *texture);
#endif

#ifdef __cplusplus
extern "C" {
#endif
s32 TObjPlayer__sub_803DAE98(GinjaTextureState *texture);
// Releases every loaded texture in `texlist`; -1 if one failed, else 1.
s32 release_texture_list(NJS_TEXLIST *texlist);
s32 find_texture_entry_by_name(const NJS_TEXLIST *texlist, const char *name);
#ifdef __cplusplus
}
#endif

#endif
