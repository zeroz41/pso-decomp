#include "types.h"
#include "pso/weapon/TItemWeaponSRankPunch.h"
#include "pso/weapon/TItemWeaponSRankPsychogun.h"
#include "pso/player/TObjPlayer.h"
#include "pso/effect/item/TItemEffLandHit.h"
#include "pso/unk/text_8011B620.h"
#include "pso/item/TItem.h"
#include "pso/system/task/TMainTask.h"

void TItemWeaponSRankPsychogun::emit_marker_effects() {
    TObjPlayer__sub_80128A70();
    if (launch_shot((u8 *)&shot_origins[0], 0, 0, 1) != 0) {
        launch_shot((u8 *)&shot_origins[1], 0, 0, 0);
        return;
    }
    launch_shot((u8 *)&shot_origins[1], 0, 0, 1);
}

void TItemWeaponSRankPsychogun::draw_held_model() {
    sample_dual_muzzles(&shot_origins[0], &shot_origins[1]);
}

TItemWeaponSRankPsychogun::~TItemWeaponSRankPsychogun() {}

TItemWeaponSRankPsychogun::TItemWeaponSRankPsychogun(TObject *parent, u8 *item) : TItemWeaponSRank(parent, item) {
    set_weapon_flags(547);
    shot_callback = (WeaponShotCallback)create_gun_shot;
    impact_callback = (WeaponHitCallback)spawn_weapon_impact_effect;
}

TItem *TItemWeaponSRankPsychogun::create(u8 *item) {
    if (item != NULL) {
        return new TItemWeaponSRankPsychogun(tl_05, item);
    }
    return NULL;
}
