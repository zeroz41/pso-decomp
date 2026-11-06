#include "types.h"
#include "pso/unk/text_803E29B0.h"
#include "pso/effect/TParticleCtrl.h"
extern "C" {
void TParticleCtrl__sub_803E2A1C(void *, void *);
}
void draw_particle_strip(void *arg0, void *arg1, void *arg2) {
    TParticleCtrl::setup_particle_draw((s32)arg2);
    TParticleCtrl__sub_803E2A1C(arg0, arg1);
    TParticleCtrl::reset_particles();
}
