#ifndef PSO_SYSTEM_BMLACCESSORS_H
#define PSO_SYSTEM_BMLACCESSORS_H

#include "types.h"

struct BmlResource;
struct GinjaTextureList;
struct NJS_OBJECT;

extern "C" {
NJS_OBJECT *get_bml_model(BmlResource *resource, s32 index);
GinjaTextureList *get_bml_texlist(BmlResource *resource, s32 index);
}

#endif
