/* Ninja's texture reload: only textures already in memory can be reloaded. */
#define PSO_SDK_COMPACT_MATH
#include <dolphin/os.h>
#include "types.h"
#include "pso/render/nuReLoadTexture.h"
#include "pso/system/NinjaTypes.h"
#include "pso/render/TextureState.h"

void reload_texture_num(s32 n, const void *texaddr, u32 attr, u32 lod) {
    const void *src;
    if ((attr & NJD_TEXATTR_TYPE_MEMORY) != 0) {
        src = texaddr;
    } else {
        OSPanic("nuReLoadTexture.c", 48, "sorry");
    }
    reload_list_texture_pixels(n, src, lod);
}
