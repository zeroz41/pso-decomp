#ifndef PSO_BOSS_VOLOPT_TBOSS3VOLOPT_800D8ACC_H
#define PSO_BOSS_VOLOPT_TBOSS3VOLOPT_800D8ACC_H

#include "types.h"

struct Vec;

// Particles 251, 252 and 227 at pos; the break-apart and death states call it.
void trigger_dell_biter_events(const Vec *pos);
// A timed emitter of particle 0xE5 (spawn_effect_at_ground: 0xE4) on the ground
// under pos.
void spawn_ground_effect(const Vec *pos, s32 duration);
void spawn_effect_at_ground(const Vec *pos, s32 duration);

extern "C" {
void TBoss3Volopt__sub_800D8D88(saddr position);
void spawn_particles_at__12TBoss3VoloptFi(saddr position);
}

#endif
