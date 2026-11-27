#define PSO_SDK_COMPACT_MATH
#include <dolphin/gx.h>
#undef PSO_SDK_COMPACT_MATH
#include "types.h"
#include "pso/effect/particle/ParticleStrip.h"
#include "pso/render/ScreenPrimitiveDraw.h"

void draw_particle_strip(ParticleStripVertex *vertices, s32 count, s32 blended) {
    setup_particle_draw(blended);
    emit_particle_strip_vertices(vertices, count);
    end_particle_draw();
}

void end_particle_draw() {
    end_primitive_draw();
}

#pragma push
#pragma dont_inline off
#pragma inline_depth(4)
void emit_particle_strip_vertices(ParticleStripVertex *vertices, s32 count) {
    s32 i;
    GXBegin(GX_TRIANGLESTRIP, GX_VTXFMT4, count);
    for (i = 0; i < count; i++) {
        f32 x;
        f32 y;
        f32 z;
        u32 color;
        f32 u;
        f32 v;
        z = vertices->z;
        y = vertices->y;
        x = vertices->x;
        GXPosition3f32(x, y, z);
        color = vertices->color;
        GXColor1u32(((color & 0xFFFFFF) << 8) | ((color & 0xFF000000) >> 24));
        v = vertices->v;
        u = vertices->u;
        GXTexCoord2f32(u, v);
        vertices++;
    }
}
#pragma pop

void setup_particle_draw(s32 blended) {
    load_camera_view_matrix();
    if (blended != 0) {
        setup_blended_textured_draw();
    } else {
        setup_opaque_textured_draw();
    }
    load_context_texture_obj();
}
