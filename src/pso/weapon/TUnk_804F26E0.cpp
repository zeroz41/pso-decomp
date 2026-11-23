// S-rank knuckle weapon (TUnk_804F26E0): its own TU after TObjEneEpsilon's. Evidence: its float pool
// {1.0f, 1.2f} starts at the 8-aligned 0x805E0258 after a zero pad word that closes TObjEneEpsilon's pool,
// and its vtable (0x804F26E0) follows TObjEneEpsilon's at the end of that TU's .data.
#include "pso/effect/particle/ParticleFactory.h"
#include "types.h"
#include "pso/weapon/TUnk_804F26E0.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/PlayerAttackParams.h"
#include "pso/system/task/TMainTask.h"
#include "pso/effect/particle/TParticleCtrl.h"

extern "C" {
extern s32 knuckle_marker_joint_table[];
}

void TUnk_804F26E0::on_unequipped() {
    owner->attack_state.set_evp(1.0f);
}

// S-rank knuckle equip hook (was s_rank_knuckle_equip): sets the owner's EVP.
void TUnk_804F26E0::on_equipped() {
    owner->attack_state.set_evp(1.2f);
}

// S-rank knuckle marker (was s_rank_knuckle_marker): effect at the owner's knuckle joint.
void TUnk_804F26E0::vfunc_62() {
    u8 sp8[0x10];
    owner->get_anim_node_position(knuckle_marker_joint_table[(owner->has_valid_handle() * 3) + owner->attack_state.get_validated_attack_stage()], (Vec *)sp8);
    spawn_particle_effect((const Vec *)sp8, 0x1D0);
}

TUnk_804F26E0::TUnk_804F26E0(TObject *parent, u8 *item) : TUnk_804A4948(parent, item) {}

TItem *create_s_rank_knuckle(u8 *item) {
    if (item != NULL) {
        return new TUnk_804F26E0(tl_05, item);
    }
    return NULL;
}

TUnk_804F26E0::~TUnk_804F26E0() {}
