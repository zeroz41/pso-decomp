#include "types.h"
#include "pso/weapon/TItemWeaponSRankPunch.h"
#include "pso/weapon/TItemWeaponSRankNeedle.h"
#include "pso/player/TObjPlayer.h"
#include "pso/effect/item/TItemEffNeedle.h"
#include "pso/item/TItem.h"
#include "pso/system/task/TMainTask.h"


// The spread of the five needles (launch_shot angles).
const s32 needle_spread_angles[6] = {0, 2184, -2184, 4551, -4551, 0};

void TItemWeaponSRankNeedle::emit_marker_effects() {
    Vec pos;
    debug_weapon_attack_hook();
    get_joint_position(1, &pos);
    launch_shot(&pos, 0, needle_spread_angles[0], 1);
    get_joint_position(1, &pos);
    launch_shot(&pos, 1, needle_spread_angles[1], 1);
    get_joint_position(1, &pos);
    launch_shot(&pos, 2, needle_spread_angles[2], 1);
    get_joint_position(1, &pos);
    launch_shot(&pos, 3, needle_spread_angles[3], 1);
    get_joint_position(1, &pos);
    launch_shot(&pos, 4, needle_spread_angles[4], 1);
}

TItemWeaponSRankNeedle::TItemWeaponSRankNeedle(TObject *parent, u8 *item) : TItemWeaponSRank(parent, item) {
    set_weapon_flags(2);
    hit_callback = (WeaponHitCallback)spawn_target_needle;
    impact_callback = (WeaponHitCallback)spawn_needle_wall_impact;
    shot_callback = TObjPlayer::create_shoot_model;
}

TItem *TItemWeaponSRankNeedle::create(u8 *item) {
    if (item != NULL) {
        return new TItemWeaponSRankNeedle(tl_05, item);
    }
    return NULL;
}

TItemWeaponSRankNeedle::~TItemWeaponSRankNeedle() {}
