#include "types.h"
#include "pso/weapon/TItemWeaponSpreadNeedle.h"
#include "pso/player/TObjPlayer.h"
#include "pso/item/TItem.h"
#include "pso/effect/item/TItemEffNeedle.h"
#include "pso/system/task/TMainTask.h"

// launch_shot angles of the five shots (straight, then two pairs fanned out).
const s32 five_joint_shot_angle_table[5] = {0, 0x888, -0x888, 0x11C7, -0x11C7};

void TItemWeaponSpreadNeedle::emit_marker_effects() {
    Vec pos;

    get_joint_position(1, &pos);
    launch_shot(&pos, 0, five_joint_shot_angle_table[0], 1);
    get_joint_position(1, &pos);
    launch_shot(&pos, 1, five_joint_shot_angle_table[1], 1);
    get_joint_position(1, &pos);
    launch_shot(&pos, 2, five_joint_shot_angle_table[2], 1);
    get_joint_position(1, &pos);
    launch_shot(&pos, 3, five_joint_shot_angle_table[3], 1);
    get_joint_position(1, &pos);
    launch_shot(&pos, 4, five_joint_shot_angle_table[4], 1);
}

TItemWeaponSpreadNeedle::TItemWeaponSpreadNeedle(TObject *parent, u8 *item) : TItemWeapon(parent, item) {
    set_weapon_flags(2);
    hit_callback = (WeaponHitCallback)spawn_target_needle;
    impact_callback = (WeaponHitCallback)spawn_needle_wall_impact;
    shot_callback = TObjPlayer::create_shoot_model;
}

TItem *TItemWeaponSpreadNeedle::create(u8 *item) {
    if (item != NULL) {
        return new TItemWeaponSpreadNeedle(tl_05, item);
    }
    return NULL;
}

TItemWeaponSpreadNeedle::~TItemWeaponSpreadNeedle() {}
