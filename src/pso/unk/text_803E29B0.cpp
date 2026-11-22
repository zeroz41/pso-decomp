#include "types.h"
#include "pso/unk/text_803E29B0.h"
#include "pso/effect/particle/TParticleCtrl.h"
extern "C" {
void emit_particle_strip_vertices(void *, void *);
}
void draw_particle_strip(void *verts, void *arg1, void *arg2) {
    TParticleCtrl::setup_particle_draw((saddr)arg2);
    emit_particle_strip_vertices(verts, arg1);
    TParticleCtrl::reset_particles();
}
