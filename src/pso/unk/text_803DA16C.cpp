#include "pso/system/GinjaTexture.h"

extern "C" {
extern GinjaTextureError lbl_8058D470;

#pragma push
#pragma use_lmw_stmw off
s32 release_texture_list(GinjaTextureList *textures) {
    u32 i;
    s32 result = 1;
    for (i = 0; i < textures->count; ++i) {
        if (textures->entries[i].texture != NULL &&
            TObjPlayer__sub_803DAE98(textures->entries[i].texture) < 0) {
            lbl_8058D470.entry_index = i;
            result = -1;
        }
        textures->entries[i].texture = NULL;
    }
    return result;
}
#pragma pop
}
