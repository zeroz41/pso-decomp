#include "pso/math/ClampedStep.h"
#include "types.h"
#include <stddef.h>
#include "pso/weapon/TItemWeaponGAssassinsSabers.h"
#include "pso/player/TObjPlayer.h"
#include "pso/system/MatrixOps.h"
#include "pso/system/task/TMainTask.h"

void TItemWeaponGAssassinsSabers::transform_model_node() {
    switch (TObjPlayer::get_player_list()) {
    case 1:
        rotate_matrix_x(NULL, pad_1f8);
        return;
    case 2:
        rotate_matrix_x(NULL, pad_1fc);
        return;
    }
}

void TItemWeaponGAssassinsSabers::update_idle() {
    ::add_angle_clamped(&pad_1f8, 0x71C, 0x4000);
    if (pad_1f8 == 0x4000) {
        ::add_angle_clamped(&pad_1fc, 0x71C, 0x4000);
    }
}

void TItemWeaponGAssassinsSabers::update_attack() {
    ::add_angle_clamped(&pad_1fc, -0xAAA, 0);
    if (pad_1fc == 0) {
        ::add_angle_clamped(&pad_1f8, -0xAAA, 0);
    }
}

TItemWeaponGAssassinsSabers::~TItemWeaponGAssassinsSabers() {}

TItemWeaponGAssassinsSabers::TItemWeaponGAssassinsSabers(TObject *parent, u8 *item) : TItemWeapon(parent, item) {
    set_weapon_flags(1536);
    pad_1f8 = 0;
    pad_1fc = 0;
}

TItem *TItemWeaponGAssassinsSabers::create(u8 *item) {
    if (item != NULL) {
        return new TItemWeaponGAssassinsSabers(tl_05, item);
    }
    return NULL;
}
