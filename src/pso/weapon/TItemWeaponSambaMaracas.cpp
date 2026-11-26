#include "types.h"
#include "pso/weapon/TItemWeaponSambaMaracas.h"
#include "pso/player/TObjPlayer.h"
#include "pso/item/TItem.h"
#include "pso/weapon/shoot/TItemShoot.h"
#include "pso/system/task/TMainTask.h"

void TItemWeaponSambaMaracas::emit_marker_effects() {
    if (launch_shot((u8 *)&shot_origins[0], 0, 0, 1) != 0) {
        launch_shot((u8 *)&shot_origins[1], 0, 0, 0);
    } else {
        launch_shot((u8 *)&shot_origins[1], 0, 0, 1);
    }
}

void TItemWeaponSambaMaracas::draw_held_model() {
    sample_dual_muzzles(&shot_origins[0], &shot_origins[1]);
}

TItemWeaponSambaMaracas::~TItemWeaponSambaMaracas() {}

TItemWeaponSambaMaracas::TItemWeaponSambaMaracas(TObject *parent, u8 *item) : TItemWeapon(parent, item) {
    set_weapon_flags(515);
    shot_callback = (WeaponShotCallback)spawn_shoot_particle_9f;
    shot_speed = 11.0f;
}


TItem *TItemWeaponSambaMaracas::create(u8 *item) {
    if (item != NULL) {
        return new TItemWeaponSambaMaracas(tl_05, item);
    }
    return NULL;
}
