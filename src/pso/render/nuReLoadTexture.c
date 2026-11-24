/* Ninja's texture reload: only textures already in memory can be reloaded. */
#include <dolphin/os.h>
#include "types.h"
#include "pso/render/nuReLoadTexture.h"
#include "pso/system/NinjaTypes.h"
#include "pso/unk/text_803DA798.h"

void reload_texture_num(s32 n, saddr texaddr, u32 attr, u32 lod) {
    saddr src;
    if ((attr & NJD_TEXATTR_TYPE_MEMORY) != 0) {
        src = texaddr;
    } else {
        OSPanic("nuReLoadTexture.c", 48, "sorry");
    }
    TObjPlayer__sub_803DAE1C(n, src, lod);
}
