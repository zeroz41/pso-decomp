#include "pso/math/ClampedStep.h"
#include "types.h"
#include "pso/weapon/TItemWeaponHolyRay.h"
#include "pso/player/TObjPlayer.h"
#include "pso/weapon/TItemWeapon.h"
#include "pso/item/TItem.h"
#include "pso/weapon/shoot/TItemShoot.h"
#include "pso/effect/item/TItemEffNeedle.h"
#include "pso/system/task/TMainTask.h"
#include "pso/system/MatrixOps.h"


void TItemWeaponHolyRay::update_idle() { ::add_angle_clamped(&rotation_x, -910, -7281); ::add_angle_clamped(&rotation_z, -910, -9102); }

void TItemWeaponHolyRay::update_attack() { ::add_angle_clamped(&rotation_x, 1820, 0); ::add_angle_clamped(&rotation_z, 1820, 0); }

void TItemWeaponHolyRay::transform_model_node() {
    s32 player_list;

    player_list = TObjPlayer::get_player_list();
    switch (player_list) {
    case 1:
        rotate_matrix_z(0, -rotation_z);
        return;
    case 2:
        rotate_matrix_z(0, rotation_z);
        return;
    case 3:
        rotate_matrix_x(0, rotation_x);
        return;
    }
}

TItemWeaponHolyRay::TItemWeaponHolyRay(TObject *parent, u8 *item) : TItemWeapon(parent, item) {
    shot_callback = (WeaponShotCallback)TItemShoot::spawn_shoot_particle_attached;
    hit_callback = (WeaponHitCallback)spawn_target_needle;
    impact_callback = (WeaponHitCallback)spawn_needle_wall_impact;
    rotation_z = 0;
    rotation_x = 0;
}


TItem *TItemWeaponHolyRay::create(u8 *item) {
    if (item != NULL) {
        return new TItemWeaponHolyRay(tl_05, item);
    }
    return NULL;
}


TItemWeaponHolyRay::~TItemWeaponHolyRay() {}
