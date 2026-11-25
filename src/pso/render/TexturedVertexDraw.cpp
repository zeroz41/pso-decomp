#define PSO_SDK_COMPACT_MATH
#include <dolphin/gx.h>
#undef PSO_SDK_COMPACT_MATH
#include "types.h"
#include "pso/render/ScreenPrimitiveDraw.h"

// Own TU: its .sdata2 pool holds a second -1.0f, padded to 8, right after
// ScreenPrimitiveDraw's.

#pragma scheduling off
#pragma dont_inline off
#pragma inline_depth(4)
void draw_screen_textured_strip(ScreenTexturedVertex *vertices, s32 count, s32 blended) {
    f32 inv_w;
    u32 color;
    load_screen_space_matrix();
    if (blended != 0) {
        setup_blended_textured_draw();
    } else {
        setup_opaque_textured_draw();
    }
    load_context_texture_obj();
    GXBegin(GX_TRIANGLESTRIP, GX_VTXFMT4, count);
    for (; count > 0; count--) {
        inv_w = -1.0f / vertices->w;
        GXPosition3f32(vertices->x * inv_w, vertices->y * inv_w, inv_w);
        color = vertices->color;
        GXColor1u32(((color & 0xFFFFFF) << 8) | ((color & 0xFF000000) >> 24));
        GXTexCoord2f32(vertices->s, vertices->t);
        vertices++;
    }
    end_primitive_draw();
}
