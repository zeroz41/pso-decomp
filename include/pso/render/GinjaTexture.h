#ifndef PSO_RENDER_GINJATEXTURE_H
#define PSO_RENDER_GINJATEXTURE_H

#include "pso/render/GinjaMaterialState.h"

struct GinjaTextureError {
    s32 entry_index;
    s32 pad_04;
    s32 code;
    s32 pad_0C;
    s32 pad_10;
};

LAYOUT_ASSERT(GinjaTextureErrorPrefixSize, sizeof(GinjaTextureError) == 0x14);

extern GinjaTextureError lbl_8058D470;
// The loaded textures: one GinjaTextureState per slot, record_array_count slots.
extern GinjaTextureState *record_array_ptr;

extern "C" {
s32 TObjPlayer__sub_803DAE98(GinjaTextureState *texture);
// Clears the texture's surface slot once nothing references it, then the texture entry itself.
void clear_unreferenced_texture_entry(GinjaTextureState *texture);
// Releases every loaded texture in `texlist`; -1 if one failed, else 1.
s32 release_texture_list(NJS_TEXLIST *texlist);
s32 find_texture_entry_by_name(const NJS_TEXLIST *texlist, const char *name);
}

#endif
