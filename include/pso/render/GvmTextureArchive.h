#ifndef PSO_RENDER_GVMTEXTUREARCHIVE_H
#define PSO_RENDER_GVMTEXTUREARCHIVE_H

#include "types.h"

struct GinjaTextureEntry;
struct GinjaTextureList;

extern "C" {
s32 load_gvm_texture_archive(void *archive, GinjaTextureList *list);
void TObjPlayer__sub_803DD5E8(GinjaTextureList *list, GinjaTextureEntry *entries, u32 names, s32 count);
}

#endif
