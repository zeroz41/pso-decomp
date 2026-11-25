#include "types.h"
#include "pso/weapon/TItemWeaponSRankPunch.h"
#include "pso/weapon/TItemWeaponSRankMechgun.h"
#include "pso/player/TObjPlayer.h"
#include "pso/effect/item/TItemEffLandHit.h"
#include "pso/item/TItem.h"
#include "pso/system/task/TMainTask.h"

void TItemWeaponSRankMechgun::emit_marker_effects() {
    TObjPlayer__sub_80128A70();
    if (launch_shot((u8 *)&shot_origins[0], 0, 0, 1) != 0) {
        launch_shot((u8 *)&shot_origins[1], 0, 0, 0);
        return;
    }
    launch_shot((u8 *)&shot_origins[1], 0, 0, 1);
}

void TItemWeaponSRankMechgun::draw_held_model() {
    sample_dual_muzzles(&shot_origins[0], &shot_origins[1]);
}

TItemWeaponSRankMechgun::TItemWeaponSRankMechgun(TObject *parent, u8 *item) : TUnk_804A4948(parent, item) {
    set_weapon_flags(515);
    impact_callback = (WeaponHitCallback)spawn_weapon_impact_effect;
}

TItem *TObjPlayer::create_variant(u8 *item) {
    if (item != NULL) {
        return new TItemWeaponSRankMechgun(tl_05, item);
    }
    return NULL;
}

TItemWeaponSRankMechgun::~TItemWeaponSRankMechgun() {}
