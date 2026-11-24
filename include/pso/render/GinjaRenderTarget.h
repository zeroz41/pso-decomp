#ifndef PSO_RENDER_GINJARENDERTARGET_H
#define PSO_RENDER_GINJARENDERTARGET_H

#include "pso/render/GinjaMaterialState.h"
#include <stddef.h>

struct GinjaRenderTarget {
    u8 unknown_00[0x10];
    NJS_TEXNAME texture_entry;
    NJS_TEXLIST texture_list;
    s32 load_result;

    void init_render_target();
    void release_texture();
    void copy_efb_to_texture();
};

LAYOUT_ASSERT(GinjaRenderTarget_size, sizeof(GinjaRenderTarget) == 0x28);
LAYOUT_ASSERT(GinjaRenderTarget_texture_entry, offsetof(GinjaRenderTarget, texture_entry) == 0x10);
LAYOUT_ASSERT(GinjaRenderTarget_texture_list, offsetof(GinjaRenderTarget, texture_list) == 0x1C);
LAYOUT_ASSERT(GinjaRenderTarget_load_result, offsetof(GinjaRenderTarget, load_result) == 0x24);

#endif
