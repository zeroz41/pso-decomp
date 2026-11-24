#ifndef PSO_RENDER_NURELOADTEXTURE_H
#define PSO_RENDER_NURELOADTEXTURE_H

#include "types.h"

#ifdef __cplusplus
extern "C" {
#endif

// Reloads the pixels of texture n from texaddr; attr must be NJD_TEXATTR_TYPE_MEMORY.
void reload_texture_num(s32 n, saddr texaddr, u32 attr, u32 lod);

#ifdef __cplusplus
}
#endif

#endif
