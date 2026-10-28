#ifndef PSO_SYSTEM_GINJATEXTURE_H
#define PSO_SYSTEM_GINJATEXTURE_H

#include "pso/system/GinjaMaterialState.h"

struct GinjaTextureError {
    s32 entry_index;
    s32 field_04;
    s32 code;
    s32 field_0c;
    s32 field_10;
};

typedef char GinjaTextureErrorPrefixSize[sizeof(GinjaTextureError) == 0x14 ? 1 : -1];

extern "C" {
s32 TObjPlayer__sub_803DAE98(GinjaTextureState *texture);
// Releases every loaded texture in `texlist`; -1 if one failed, else 1.
s32 release_texture_list(GinjaTextureList *texlist);
}

#endif
