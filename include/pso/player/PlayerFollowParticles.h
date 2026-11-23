#ifndef PSO_PLAYER_PLAYERFOLLOWPARTICLES_H
#define PSO_PLAYER_PLAYERFOLLOWPARTICLES_H

#include "types.h"
#include <dolphin/mtx/GeoTypes.h>

class TPlyPtclObjectLeftHand;
class TPlyPtclObjectRightHand;

// The empty base of PlayerHandParticles.
struct PlayerHandParticlesBase {
    PlayerHandParticlesBase();
    ~PlayerHandParticlesBase();
};

// The hand particle followers a player keeps (created together by update_child).
struct PlayerHandParticles : PlayerHandParticlesBase {
    PlayerHandParticles();
    ~PlayerHandParticles();
    void prepare_heavy_attack_particles();
    void emit_jellen_support_effect();
    void emit_shifta_support_effect();

    TPlyPtclObjectLeftHand *left_hand;
    TPlyPtclObjectRightHand *right_hand;
};

// Follow-particle state embedded in TObjPlayer at 0x384.
struct PlayerFollowParticles {
    u16 owner_id; // get_entity_id of the player that owns the followers
    u16 pad_2;
    PlayerHandParticles hands;
    Vec pad_C[3];

    PlayerFollowParticles();
    ~PlayerFollowParticles();
    void set_owner_id(u16 id);
    void prepare_heavy_attack_particles_default();
    void emit_jellen_support_effect_default();
    void emit_shifta_support();
};

LAYOUT_ASSERT(PlayerFollowParticles_size, sizeof(PlayerFollowParticles) == 0x30);

#endif
