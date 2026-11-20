#ifndef PSO_RENDER_GVMTEXTUREARCHIVELOOKUP_H
#define PSO_RENDER_GVMTEXTUREARCHIVELOOKUP_H

#include "types.h"

struct GinjaTextureList;

extern "C" s32 find_texture_entry_by_name(const GinjaTextureList *list, const char *name);

#endif
