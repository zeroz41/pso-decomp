#include "types.h"
#include "pso/render/ScreenPrimitiveDraw.h"
#include "pso/render/ProjectedColorDraw.h"
#define PSO_SDK_COMPACT_MATH
#include <dolphin/gx.h>
#undef PSO_SDK_COMPACT_MATH

#pragma scheduling off


void end_projected_color_draw() {
    end_primitive_draw();
}

#pragma push
#pragma scheduling off
#pragma dont_inline off
#pragma inline_depth(4)
void draw_projected_quads(ProjectedVertex *vertices, s32 n) {
    s32 i;
    f32 one;
    GXBegin(GX_TRIANGLESTRIP, GX_VTXFMT4, n);
    one = -1.0f;
    for (i = 0; i != n; i++) {
        f32 x;
        f32 y;
        f32 w;
        u32 c;
        w = one / vertices->z;
        y = vertices->y * w;
        x = vertices->x * w;
        GXPosition3f32(x, y, w);
        c = vertices->color;
        GXColor1u32(((c & 0xFFFFFF) << 8) | ((c & 0xFF000000) >> 24));
        vertices++;
    }
}
#pragma pop

void setup_projected_color_draw(s32 mode) {
    load_screen_space_matrix();
    if (mode != 0) {
        setup_blended_color_draw();
        return;
    }
    setup_opaque_color_draw();
}
