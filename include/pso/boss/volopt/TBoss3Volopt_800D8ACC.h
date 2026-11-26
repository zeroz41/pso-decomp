#ifndef PSO_BOSS_VOLOPT_TBOSS3VOLOPT_800D8ACC_H
#define PSO_BOSS_VOLOPT_TBOSS3VOLOPT_800D8ACC_H

#include "types.h"
#include <dolphin/mtx.h>

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

// Photon blast summons switch the player particle effects off while they hold the scene.
void disable_player_particle_effect(void);
void enable_player_particle_effect(void);

extern "C" {
void TObjPlayer__sub_800D93F0(const Vec *point, s32 selector, s32 delay, f32 maxScale);
void *__dt__17MaterialColorFadeFv(void *object, s16 delete_flag);
}
extern "C" {
}
// Dead-stripped (no code in the DOL); names inferred, see TBoss3Volopt_800D8ACC.cpp.

extern "C" void fn_800D911C(Vec *position);

// Particle 0xF8 at pos for duration frames, with a TDeadSpotEmitter of radius on it.
void create_dead_spot(Vec *pos, s32 duration, f32 radius);
// Particle 0xF8 at pos for duration frames.
void spawn_effect_f8(Vec *pos, s32 duration);
// create_dead_spot with particle 0xE4.
void create_dead_spot_e4(Vec *pos, s32 duration, f32 radius);
// Particle `particle` at pos for duration frames, with a TDeadSpotGroundEmitter of radius on it.
void create_dead_spot(Vec *pos, s32 particle, s32 duration, f32 radius);

#endif
