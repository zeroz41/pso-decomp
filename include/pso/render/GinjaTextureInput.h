#ifndef PSO_RENDER_GINJATEXTUREINPUT_H
#define PSO_RENDER_GINJATEXTUREINPUT_H

#include "pso/render/GinjaMaterialState.h"
#include <stddef.h>

// A texture entry references this record until the loader binds its texture.
struct GinjaTextureInput {
    void *data;
    s32 format;
    u8 unknown08[8];
    s32 width;
    s32 height;
    u8 unknown18[0xC];

    void set_render_rect(void *pixels, s32 format, s32 width, s32 height);
};

LAYOUT_ASSERT(GinjaTextureInput_size, sizeof(GinjaTextureInput) == 0x24);
LAYOUT_ASSERT(GinjaTextureInput_width_offset, offsetof(GinjaTextureInput, width) == 0x10);
LAYOUT_ASSERT(GinjaTextureInput_height_offset, offsetof(GinjaTextureInput, height) == 0x14);

extern "C" void set_texture_name(NJS_TEXNAME *entry, GinjaTextureInput *input, u32 index, u32 attributes);

#endif
