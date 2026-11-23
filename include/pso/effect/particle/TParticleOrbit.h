#ifndef PSO_EFFECT_PARTICLE_TPARTICLEORBIT_H
#define PSO_EFFECT_PARTICLE_TPARTICLEORBIT_H
#include "types.h"
#include "pso/effect/particle/TParticle.h"

class TParticleOrbit : public TParticle {
public:
    virtual ~TParticleOrbit();
    virtual void run_task();
    TParticleOrbit(ParticleParam *entry, Vec *position, ParticleAngles *direction, TObject *parent, u16 particle_flags,
                  u16 target);
    TParticleOrbit(void *param, void *pos, void *dir, void *parent);
    void retire_orbit_particle();
    virtual void render();
    f32 orbit_center_x;        // 0xC4
    f32 orbit_center_z;        // 0xC8
    u8 pad_cc[0x4];
    f32 orbit_radius;          // 0xD0
    f32 orbit_height;          // 0xD4
    s32 orbit_angle;           // 0xD8
    s32 pulse_angle;           // 0xDC, size pulse phase
};

#endif
