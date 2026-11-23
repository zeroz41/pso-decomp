#ifndef PSO_PLAYER_TOBJPLAYER_80309D80_H
#define PSO_PLAYER_TOBJPLAYER_80309D80_H

#include "types.h"
#include <dolphin/mtx/GeoTypes.h>

class TParticleCtrl;
class TPlyPtclObjectLeftHand;
class TPlyPtclObjectRightHand;

// The hand particle followers a player keeps (created together by update_child).
struct PlayerHandParticles {
    TPlyPtclObjectLeftHand *left_hand;
    TPlyPtclObjectRightHand *right_hand;
};

// Follow-particle state embedded in TObjPlayer at 0x384.
struct PlayerFollowParticles {
    u16 owner_id; // set_type stores get_entity_id(owner) here
    u16 pad_2;
    PlayerHandParticles hands;
    Vec pad_C[3];
};

extern "C" {
s32 destroy_follow_particle_state(saddr self, s16 flags);
PlayerFollowParticles *init_follow_particle_state(PlayerFollowParticles *state);
TParticleCtrl *create_attached_oneshot_emitter(void *owner, s32 target_id, s32 id);
}
void emit_idle_water_splash(s32 owner, s32 position);
s32 emit_player_model_particle(saddr owner, saddr position, saddr entry, s32 model);
extern "C" {
TParticleCtrl *emit_player_particle(void *owner, const Vec *position, s32 id);
}
void emit_player_sprite_particle(s32 arg0, saddr arg1, s32 arg2);
void emit_sand_step_particles(saddr owner, saddr position);
void emit_water_step_particles(saddr owner, saddr position);

#endif
