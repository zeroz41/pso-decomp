#ifndef PSO_EFFECT_PARTICLE_TPARTICLEBALLISTIC_H
#define PSO_EFFECT_PARTICLE_TPARTICLEBALLISTIC_H
#include "types.h"
#include "pso/effect/particle/TParticle.h"

class TParticleBallistic : public TParticle {
public:
    virtual ~TParticleBallistic();
    virtual void run_task();
    TParticleBallistic(ParticleParam *entry, Vec *position, ParticleAngles *direction, TObject *parent, u16 particle_flags,
                  u16 target);
    TParticleBallistic(void *param, void *pos, void *parent);
    void retire_ballistic_particle_if_done();
    void draw_sprite_quad(s32);
    virtual void render();
    Vec velocity;              // 0xC4, step after rotation
};

#endif
