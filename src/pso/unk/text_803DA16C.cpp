#include "pso/render/GinjaTexture.h"


extern GinjaTextureError lbl_8058D470;

#pragma push
#pragma use_lmw_stmw off
s32 release_texture_list(NJS_TEXLIST *textures) {
    u32 i;
    s32 result = 1;
    for (i = 0; i < textures->nbTexture; ++i) {
        if (textures->textures[i].texture != NULL &&
            TObjPlayer__sub_803DAE98(textures->textures[i].texture) < 0) {
            lbl_8058D470.entry_index = i;
            result = -1;
        }
        textures->textures[i].texture = NULL;
    }
    return result;
}
#pragma pop
