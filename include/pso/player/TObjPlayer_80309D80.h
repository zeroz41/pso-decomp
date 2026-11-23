#ifndef PSO_PLAYER_TOBJPLAYER_80309D80_H
#define PSO_PLAYER_TOBJPLAYER_80309D80_H

#include "types.h"
#include <dolphin/mtx/GeoTypes.h>
#include "pso/player/PlayerFollowParticles.h"

class TParticleCtrl;

extern "C" {
TParticleCtrl *create_attached_oneshot_emitter(void *owner, u16 target_id, s32 id);
}
void emit_idle_water_splash(s32 owner, s32 position);
s32 emit_player_model_particle(saddr owner, saddr position, saddr entry, s32 model);
extern "C" {
TParticleCtrl *emit_player_particle(void *owner, const Vec *position, s32 id);
}
void emit_player_sprite_particle(s32 owner, saddr position, s32 id);
void emit_sand_step_particles(saddr owner, saddr position);
void emit_water_step_particles(saddr owner, saddr position);

#endif
