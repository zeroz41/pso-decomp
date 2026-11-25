#ifndef PSO_RENDER_GVMTEXTUREARCHIVE_H
#define PSO_RENDER_GVMTEXTUREARCHIVE_H

#include "types.h"

struct NJS_TEXNAME;
struct NJS_TEXLIST;

s32 load_gvm_texture_archive(void *archive, NJS_TEXLIST *list);
void bind_texture_name_table(NJS_TEXLIST *list, NJS_TEXNAME *entries, uaddr names, s32 count);

#endif
