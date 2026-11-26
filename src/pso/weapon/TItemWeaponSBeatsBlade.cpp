#include "pso/math/ClampedStep.h"
#include "types.h"
#include "pso/weapon/TItemWeaponSBeatsBlade.h"
#include "pso/player/TObjPlayer.h"
#include "pso/item/TItem.h"
#include "pso/system/MatrixOps.h"
#include "pso/system/task/TMainTask.h"

void TItemWeaponSBeatsBlade::update_idle() { ::add_angle_clamped(&rotation_x, 1820, 10922); }

void TItemWeaponSBeatsBlade::update_attack() { ::add_angle_clamped(&rotation_x, -1820, 0); }

void TItemWeaponSBeatsBlade::transform_model_node() {
    if (get_model_node_counter() > 0) {
        rotate_matrix_x(NULL, rotation_x);
    }
}

TItemWeaponSBeatsBlade::TItemWeaponSBeatsBlade(TObject *parent, u8 *item) : TItemWeapon(parent, item) {
    rotation_x = 10922;
    set_weapon_flags(1536);
}


TItem *TItemWeaponSBeatsBlade::create(u8 *item) {
    if (item != NULL) {
        return new TItemWeaponSBeatsBlade(tl_05, item);
    }
    return NULL;
}

TItemWeaponSBeatsBlade::~TItemWeaponSBeatsBlade() {}
