#include "types.h"
#include "pso/weapon/TItemWeaponGuldMilla.h"
#include "pso/weapon/TItemWeapon.h"
#include "pso/item/TItem.h"
#include "pso/player/TObjPlayer.h"
#include "pso/effect/item/TItemEffLandHit.h"
#include "pso/weapon/shoot/TItemShoot.h"
#include "pso/unk/text_80120908.h"
#include "pso/system/task/TMainTask.h"

void TItemWeaponGuldMilla::emit_marker_effects() {
    if (is_mode_two_and_ready() != 0) {
        shot_callback = (WeaponShotCallback)create_shoot_model_rot_z;
        impact_callback = NULL;
    } else {
        shot_callback = (WeaponShotCallback)create_gun_shot;
        impact_callback = (WeaponHitCallback)spawn_weapon_impact_effect;
    }
    if (launch_shot(&gun_point, 0, 0, 1) != 0) {
        launch_shot(&second_gun_point, 0, 0, 0);
    } else {
        launch_shot(&second_gun_point, 0, 0, 1);
    }
}

void TItemWeaponGuldMilla::draw_held_model() {
    NJS_OBJECT *model;

    model = item_model;
    draw_weapon_model();
    get_gun_point(&gun_point);
    item_model = (NJS_OBJECT *)model_data[0];
    draw_weapon_at_joint(this, 0x23);
    get_gun_point(&second_gun_point);
    item_model = model;
}

TItemWeaponGuldMilla::~TItemWeaponGuldMilla() {}

TItemWeaponGuldMilla::TItemWeaponGuldMilla(TObject *parent, u8 *item) : TItemWeapon(parent, item) {
    set_weapon_flags(515);
    impact_callback = (WeaponHitCallback)spawn_weapon_impact_effect;
}

TItem *TItemWeaponGuldMilla::create(u8 *item) {
    if (item != NULL) {
        return new TItemWeaponGuldMilla(tl_05, item);
    }
    return NULL;
}
