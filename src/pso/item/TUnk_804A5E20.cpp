#include "types.h"
#include "pso/player/TUnk_804A5E20.h"
#include "pso/player/TObjPlayer.h"
#include "pso/item/TItem.h"
#include "pso/item/TItemEffNeedle.h"
#include "pso/unk/text_8011BA54.h"
#include "pso/TMainTask.h"

// launch_shot angles of the five shots (straight, then two pairs fanned out).
const s32 five_joint_shot_angle_table[5] = {0, 0x888, -0x888, 0x11C7, -0x11C7};

void TUnk_804A5E20::emit_marker_effects() {
    WeaponVector pos;

    get_joint_position(1, &pos);
    launch_shot((u8 *)&pos, 0, five_joint_shot_angle_table[0], 1);
    get_joint_position(1, &pos);
    launch_shot((u8 *)&pos, 1, five_joint_shot_angle_table[1], 1);
    get_joint_position(1, &pos);
    launch_shot((u8 *)&pos, 2, five_joint_shot_angle_table[2], 1);
    get_joint_position(1, &pos);
    launch_shot((u8 *)&pos, 3, five_joint_shot_angle_table[3], 1);
    get_joint_position(1, &pos);
    launch_shot((u8 *)&pos, 4, five_joint_shot_angle_table[4], 1);
}

TUnk_804A5E20::TUnk_804A5E20(TObject *parent, u8 *item) : TItemWeapon(parent, item) {
    set_weapon_flags(2);
    hit_callback = (WeaponHitCallback)spawn_target_needle;
    impact_callback = (WeaponHitCallback)spawn_needle_wall_impact;
    shot_callback = (WeaponShotCallback)create_shoot_model__10TObjPlayerFUiiif;
}

u8 *TObjPlayer::create_init_state_2(u8 *item) {
    if (item != NULL) {
        return (u8 *)new TUnk_804A5E20(tl_05, item);
    }
    return NULL;
}

TUnk_804A5E20::~TUnk_804A5E20() {}
