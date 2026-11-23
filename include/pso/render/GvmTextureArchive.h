#ifndef PSO_RENDER_GVMTEXTUREARCHIVE_H
#define PSO_RENDER_GVMTEXTUREARCHIVE_H

#include "types.h"

struct NJS_TEXNAME;
struct NJS_TEXLIST;

extern "C" {
s32 load_gvm_texture_archive(void *archive, NJS_TEXLIST *list);
void TObjPlayer__sub_803DD5E8(NJS_TEXLIST *list, NJS_TEXNAME *entries, uaddr names, s32 count);
}

#endif
