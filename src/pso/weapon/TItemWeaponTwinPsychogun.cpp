#include "types.h"
#include "pso/weapon/TItemWeapon.h"
#include "pso/weapon/TItemWeaponTwinPsychogun.h"
#include "pso/weapon/SpecialProjectileWeapons.h"
#include "pso/effect/item/TItemEffLandHit.h"
#include "pso/weapon/shoot/TItemShoot.h"
#include "pso/player/TObjPlayer.h"
#include "pso/system/task/TMainTask.h"

void TItemWeaponTwinPsychogun::emit_marker_effects() {
    PlayerAttackController *attack_state;
    s32 i;
    if (is_mode_two_and_ready() != 0) {
        attack_state = &owner->attack_state;
        for (i = 0; i != 2; i++) {
            attack_state->increment_burst_counter();
        }
        shot_callback = create_shoot_model_rot_z;
        impact_callback = spawn_weapon_impact_effect;
        ((TItemWeapon *)this)->launch_rare_weapon_special(&gun_point, 1, 3.0f);
        ((TItemWeapon *)this)->launch_rare_weapon_special(&second_gun_point, 0, 3.0f);
    } else {
        shot_callback = create_gun_shot;
        impact_callback = spawn_weapon_impact_effect;
        if (launch_shot(&gun_point, 0, 0, 1) != 0) {
            launch_shot(&second_gun_point, 0, 0, 0);
        } else {
            launch_shot(&second_gun_point, 0, 0, 1);
        }
    }
}

void TItemWeaponTwinPsychogun::draw_held_model() {
    sample_dual_muzzles(&gun_point, &second_gun_point);
}

TItemWeaponTwinPsychogun::~TItemWeaponTwinPsychogun() {}

TItemWeaponTwinPsychogun::TItemWeaponTwinPsychogun(TObject *parent, u8 *item) : TItemWeapon(parent, item) {
    set_weapon_flags(547);
}

TItem *TItemWeaponTwinPsychogun::create(u8 *item) {
    if (item != NULL) {
        return new TItemWeaponTwinPsychogun(tl_05, item);
    }
    return NULL;
}
