#include "pso/math/ClampedStep.h"
#include "types.h"
#include <stddef.h>
#include "pso/weapon/TItemWeaponGAssassinsSabers.h"
#include "pso/player/TObjPlayer.h"
#include "pso/system/MatrixOps.h"
#include "pso/system/task/TMainTask.h"

void TItemWeaponGAssassinsSabers::transform_model_node() {
    switch (get_model_node_counter()) {
    case 1:
        rotate_matrix_x(NULL, pass1_angle);
        return;
    case 2:
        rotate_matrix_x(NULL, pass2_angle);
        return;
    }
}

void TItemWeaponGAssassinsSabers::update_idle() {
    ::add_angle_clamped(&pass1_angle, 0x71C, 0x4000);
    if (pass1_angle == 0x4000) {
        ::add_angle_clamped(&pass2_angle, 0x71C, 0x4000);
    }
}

void TItemWeaponGAssassinsSabers::update_attack() {
    ::add_angle_clamped(&pass2_angle, -0xAAA, 0);
    if (pass2_angle == 0) {
        ::add_angle_clamped(&pass1_angle, -0xAAA, 0);
    }
}

TItemWeaponGAssassinsSabers::~TItemWeaponGAssassinsSabers() {}

TItemWeaponGAssassinsSabers::TItemWeaponGAssassinsSabers(TObject *parent, u8 *item) : TItemWeapon(parent, item) {
    set_weapon_flags(1536);
    pass1_angle = 0;
    pass2_angle = 0;
}

TItem *TItemWeaponGAssassinsSabers::create(u8 *item) {
    if (item != NULL) {
        return new TItemWeaponGAssassinsSabers(tl_05, item);
    }
    return NULL;
}
