#define PSO_SDK_COMPACT_MATH
#include "pso/system/TrailStrip.h"
#include "types.h"
#include "pso/render/ScreenPrimitiveDraw.h"
#include <dolphin/gx.h>


#pragma scheduling off


void draw_trail_strip(void *vertices, s32 count, s32 mode) {
    setup_world_color_draw(mode);
    draw_untextured_trail_strip(vertices, count);
    reset_player_transform();
}

void reset_player_transform(void) {
    end_primitive_draw();
}

#pragma push
#pragma dont_inline off
#pragma inline_depth(4)
void draw_untextured_trail_strip(void *vertices, int count) {
    s32 n;
    TrailStripVertex *v;
    u32 c;
    v = (TrailStripVertex *)vertices;
    n = (s32)count;
    GXBegin(GX_TRIANGLESTRIP, GX_VTXFMT4, n);
    for (; n != 0; n--) {
        GXPosition3f32(v->x, v->y, v->z);
        c = v->color;
        GXColor1u32(((c & 0xFFFFFF) << 8) | ((c & 0xFF000000) >> 24));
        v++;
    }
}
#pragma pop


void setup_world_color_draw(s32 blended) {
    load_camera_view_matrix();
    if (blended != 0) {
        setup_blended_color_draw();
        return;
    }
    setup_opaque_color_draw();
}
