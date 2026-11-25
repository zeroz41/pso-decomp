#ifndef PSO_PLAYER_PLAYERFOLLOWPARTICLES_H
#define PSO_PLAYER_PLAYERFOLLOWPARTICLES_H

#include "types.h"
#include <dolphin/mtx/GeoTypes.h>

class TObjBase;
class TPlyPtclObjectLeftHand;
class TPlyPtclObjectRightHand;
class TParticleCtrl;

// The empty base of PlayerHandParticles.
struct PlayerHandParticlesBase {
    PlayerHandParticlesBase();
    ~PlayerHandParticlesBase();
};

// The hand particle followers a player keeps (created together by create_hand_particles).
struct PlayerHandParticles : PlayerHandParticlesBase {
    PlayerHandParticles();
    ~PlayerHandParticles();
    void prepare_heavy_attack_particles();
    void emit_jellen_support_effect();
    void emit_shifta_support_effect();
    void create_left_hand(TObjBase *owner);
    void create_right_hand(TObjBase *owner);
    int emit_movement_effect(u16 target_id);
    int emit_deband_support_effect(u16 target_id);
    TParticleCtrl *emit_zalure_support_effect(u16 target_id);
    TParticleCtrl *emit_grass_footstep_particle(const Vec *position);

    TPlyPtclObjectLeftHand *left_hand;
    TPlyPtclObjectRightHand *right_hand;
};

// Follow-particle state embedded in TObjPlayer at 0x384.
struct PlayerFollowParticles {
    u16 owner_id; // get_entity_id of the player that owns the followers
    u16 pad_2;
    PlayerHandParticles hands;
    Vec contact_points[3]; // hit contact points the followers start from

    PlayerFollowParticles();
    ~PlayerFollowParticles();
    void set_owner_id(u16 id);
    void prepare_heavy_attack_particles_default();
    void emit_jellen_support_effect_default();
    void emit_shifta_support();
    void create_hand_particles(TObjBase *owner);
    void set_owner(TObjBase *owner);
    int emit_movement_effect();
    int emit_deband_support();
    TParticleCtrl *emit_zalure_support();
};

LAYOUT_ASSERT(PlayerFollowParticles_size, sizeof(PlayerFollowParticles) == 0x30);

#endif
