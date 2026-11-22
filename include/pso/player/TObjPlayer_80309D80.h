#ifndef PSO_PLAYER_TOBJPLAYER_80309D80_H
#define PSO_PLAYER_TOBJPLAYER_80309D80_H

#include "types.h"

extern "C" {
s32 destroy_follow_particle_state(saddr arg0, s16 arg1);
s32 create_attached_oneshot_emitter(unsigned long long arg1, s32 arg2);
}
void emit_idle_water_splash(s32 owner, s32 position);
s32 emit_player_model_particle(saddr owner, saddr position, saddr entry, s32 model);
extern "C" {
s32 emit_player_particle(void *p, void *a1, void *a2);
}
void emit_player_sprite_particle(s32 arg0, saddr arg1, s32 arg2);
void emit_sand_step_particles(saddr owner, saddr position);
void emit_water_step_particles(saddr owner, saddr position);

#endif
