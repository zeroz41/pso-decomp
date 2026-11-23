#define PSO_SDK_COMPACT_MATH
#include <dolphin/gx.h>
#undef PSO_SDK_COMPACT_MATH
#include "types.h"
#include "pso/effect/particle/ParticleStrip.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TObjPlayer_803E20B0.h"
#include "pso/player/TObjPlayer_803E21B8.h"

void draw_particle_strip(ParticleStripVertex *vertices, s32 count, s32 blended) {
    TParticleCtrl::setup_particle_draw(blended);
    emit_particle_strip_vertices(vertices, count);
    TParticleCtrl::reset_particles();
}

void TParticleCtrl::reset_particles() {
    end_primitive_draw();
}

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
        GXWGFifo.f32 = x;
        GXWGFifo.f32 = y;
        GXWGFifo.f32 = z;
        color = vertices->color;
        GXWGFifo.u32 = ((color & 0xFFFFFF) << 8) | ((color & 0xFF000000) >> 24);
        v = vertices->v;
        u = vertices->u;
        GXWGFifo.f32 = u;
        GXWGFifo.f32 = v;
        vertices++;
    }
}

void TParticleCtrl::setup_particle_draw(s32 blended) {
    load_camera_view_matrix();
    if (blended != 0) {
        setup_blended_textured_draw();
    } else {
        TObjPlayer::setup_render();
    }
    load_context_texture_obj();
}
