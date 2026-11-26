#include "types.h"
#include "pso/render/ScreenPrimitiveDraw.h"
#include "pso/render/ProjectedStripDraw.h"
#include "pso/player/TObjPlayer.h"
#define PSO_SDK_COMPACT_MATH
#include <dolphin/gx.h>
#undef PSO_SDK_COMPACT_MATH

void end_screen_textured_draw(void) {
    end_primitive_draw();
}

#pragma push
#pragma dont_inline off
#pragma inline_depth(4)
void draw_projected_textured_strip(ProjectedStripVertex *vertices, s32 count) {
    f32 inv;
    u32 c;
    GXBegin(GX_TRIANGLESTRIP, GX_VTXFMT4, count);
    for (; count > 0; count--) {
        inv = -1.0f / vertices->w;
        GXPosition3f32(vertices->x * inv, vertices->y * inv, inv);
        c = vertices->color;
        GXColor1u32(((c & 0xFFFFFF) << 8) | ((c & 0xFF000000) >> 24));
        GXTexCoord2f32(vertices->u, vertices->v);
        vertices++;
    }
}
#pragma pop

void begin_screen_textured_draw(s32 blended) {
    load_screen_space_matrix();
    if (blended != 0) {
        setup_blended_textured_draw();
    } else {
        setup_opaque_textured_draw();
    }
    load_context_texture_obj();
}
