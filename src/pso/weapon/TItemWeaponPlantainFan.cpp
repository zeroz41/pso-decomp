#include "types.h"
#include "pso/weapon/TItemWeapon.h"
#include "pso/weapon/TItemWeaponPlantainFan.h"
#include "pso/player/TObjPlayer.h"
#include "pso/system/task/TMainTask.h"

void TItemWeaponPlantainFan::emit_marker_effects() {
    Vec pos;

    if (is_mode_two_and_ready() != 0) {
        get_gun_point(&pos);
        launch_shot((u8 *)&pos, 0, 0, 1);
        return;
    }
    ((TItemWeapon *)this)->update_active_game_effect();
}

TItemWeaponPlantainFan::~TItemWeaponPlantainFan() {}

TItemWeaponPlantainFan::TItemWeaponPlantainFan(TObject *parent, u8 *item) : TItemWeapon(parent, item) {
    set_weapon_flags(34);
    shot_callback = (WeaponShotCallback)TObjPlayer::create_item_shoot_model;
    shot_speed = 10.0f;
}

TItem *TObjPlayer::create_substate(u8 *item) {
    if (item != NULL) {
        return new TItemWeaponPlantainFan(tl_05, item);
    }
    return NULL;
}
