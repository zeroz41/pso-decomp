#ifndef PSO_RENDER_GINJATEXTUREALLOC_H
#define PSO_RENDER_GINJATEXTUREALLOC_H

#include "types.h"

struct GinjaTextureHeader;

extern "C" {
// init_ginja_texture_header, then allocates the texel buffer when that succeeds (returns 0).
s32 init_texture_header_and_alloc(GinjaTextureHeader *header, u32 width, u32 height, u32 format);
}

#endif
