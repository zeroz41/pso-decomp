#include "types.h"
#include "pso/weapon/TItemWeaponSRankPunch.h"
#include "pso/weapon/TItemWeaponSRankPsychogun.h"
#include "pso/player/TObjPlayer.h"
#include "pso/effect/item/TItemEffLandHit.h"
#include "pso/weapon/shoot/TItemShoot.h"
#include "pso/item/TItem.h"
#include "pso/system/task/TMainTask.h"

void TItemWeaponSRankPsychogun::emit_marker_effects() {
    debug_weapon_attack_hook();
    if (launch_shot(&shot_origins[0], 0, 0, 1) != 0) {
        launch_shot(&shot_origins[1], 0, 0, 0);
        return;
    }
    launch_shot(&shot_origins[1], 0, 0, 1);
}

void TItemWeaponSRankPsychogun::draw_held_model() {
    sample_dual_muzzles(&shot_origins[0], &shot_origins[1]);
}

TItemWeaponSRankPsychogun::~TItemWeaponSRankPsychogun() {}

TItemWeaponSRankPsychogun::TItemWeaponSRankPsychogun(TObject *parent, u8 *item) : TItemWeaponSRank(parent, item) {
    set_weapon_flags(547);
    shot_callback = create_gun_shot;
    impact_callback = spawn_weapon_impact_effect;
}

TItem *TItemWeaponSRankPsychogun::create(u8 *item) {
    if (item != NULL) {
        return new TItemWeaponSRankPsychogun(tl_05, item);
    }
    return NULL;
}
