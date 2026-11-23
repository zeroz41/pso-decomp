#include "types.h"
#include "pso/player/TObjPlayer_80128A70.h"
#include "pso/weapon/TUnk_804A4648.h"
#include "pso/player/TObjPlayer.h"
#include "pso/effect/item/TItemEffNeedle.h"
#include "pso/item/TItem.h"
#include "pso/system/task/TMainTask.h"


// The spread of the five needles (launch_shot angles).
const s32 needle_spread_angles[6] = {0, 2184, -2184, 4551, -4551, 0};

void TUnk_804A4648::emit_marker_effects() {
    WeaponVector pos;
    TObjPlayer__sub_80128A70();
    get_joint_position(1, &pos);
    launch_shot((u8 *)&pos, 0, needle_spread_angles[0], 1);
    get_joint_position(1, &pos);
    launch_shot((u8 *)&pos, 1, needle_spread_angles[1], 1);
    get_joint_position(1, &pos);
    launch_shot((u8 *)&pos, 2, needle_spread_angles[2], 1);
    get_joint_position(1, &pos);
    launch_shot((u8 *)&pos, 3, needle_spread_angles[3], 1);
    get_joint_position(1, &pos);
    launch_shot((u8 *)&pos, 4, needle_spread_angles[4], 1);
}

TUnk_804A4648::TUnk_804A4648(TObject *parent, u8 *item) : TUnk_804A4948(parent, item) {
    set_weapon_flags(2);
    hit_callback = (WeaponHitCallback)spawn_target_needle;
    impact_callback = (WeaponHitCallback)spawn_needle_wall_impact;
    shot_callback = (WeaponShotCallback)TObjPlayer::create_shoot_model;
}

TItem *TObjPlayer::create_state_2(u8 *item) {
    if (item != NULL) {
        return new TUnk_804A4648(tl_05, item);
    }
    return NULL;
}

TUnk_804A4648::~TUnk_804A4648() {}
