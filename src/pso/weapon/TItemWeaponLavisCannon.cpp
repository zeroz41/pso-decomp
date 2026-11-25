#include "types.h"
#include "pso/weapon/TItemWeapon.h"
#include "pso/weapon/TItemWeaponLavisCannon.h"
#include "pso/item/TItemMenuCtrl_80115AF0.h"
#include "pso/player/TObjPlayer.h"
#include "pso/item/TItem.h"
#include "pso/effect/item/TItemEffLavis.h"
#include "pso/system/MatrixOps.h"
#include "pso/system/task/TMainTask.h"

void TItemWeaponLavisCannon::emit_marker_effects() {
    if (is_mode_two_and_ready() != 0) {
        ((TItemWeapon *)this)->drain_owner_hp_fraction(0.05f);
        ((TItemWeapon *)this)->launch_rare_weapon_special(0, 1, 1.0f);
        return;
    }
    ((TItemWeapon *)this)->update_active_game_effect();
}

void TItemWeaponLavisCannon::transform_model_node() {
    if (TObjPlayer::get_player_list() == 2) {
        rotate_matrix_z(NULL, rotation_z);
        advance_angle_wrap(&rotation_z, 0x1999);
    }
}

TItemWeaponLavisCannon::TItemWeaponLavisCannon(TObject *parent, u8 *item) : TItemWeapon(parent, item) {
    set_weapon_flags(34);
    shot_callback = (WeaponShotCallback)create_lavis_shot;
    shot_speed = 10.0f;
    rotation_z = 0;
}


TItem *TItemWeaponLavisCannon::create(u8 *item) {
    if (item != NULL) {
        return new TItemWeaponLavisCannon(tl_05, item);
    }
    return NULL;
}

TItemWeaponLavisCannon::~TItemWeaponLavisCannon() {}
