#include "pso/math/ClampedStep.h"
#include "types.h"
#include "pso/weapon/TItemWeapon.h"
#include "pso/weapon/TItemWeaponSRedsBlade.h"
#include "pso/item/TItem.h"
#include "pso/player/TObjPlayer.h"
#include "pso/technique/TTecDeband.h"
#include "pso/technique/TTecSifta.h"
#include "pso/system/MatrixOps.h"
#include "pso/system/task/TMainTask.h"

void TItemWeaponSRedsBlade::emit_marker_effects() {
    if (is_mode_two_and_ready() != 0) {
        if (((TItemWeapon *)this)->get_tp() == 0) {
            TTecDeband::create(owner, &owner->position, 2);
        } else {
            TTecSifta::create(owner, &owner->position, 2);
        }
        roll_technique();
        return;
    }
    ((TItemWeapon *)this)->update_active_game_effect();
}

void TItemWeaponSRedsBlade::update_idle() {
    ::add_angle_clamped(&rotation_x, 1820, 10922);
}

void TItemWeaponSRedsBlade::update_attack() {
    ::add_angle_clamped(&rotation_x, -1820, 0);
}

void TItemWeaponSRedsBlade::on_equipped() {
    roll_technique();
    roll_technique();
}

void TItemWeaponSRedsBlade::transform_model_node() {
    if (get_model_node_counter() == 1) {
        rotate_matrix_x(NULL, rotation_x);
    }
}

TItemWeaponSRedsBlade::TItemWeaponSRedsBlade(TObject *parent, u8 *item) : TItemWeapon(parent, item) {
    rotation_x = 10922;
    set_weapon_flags(1570);
    set_technique_roll_range(2);
}

TItem *TItemWeaponSRedsBlade::create(u8 *item) {
    if (item != NULL) {
        return new TItemWeaponSRedsBlade(tl_05, item);
    }
    return NULL;
}

TItemWeaponSRedsBlade::~TItemWeaponSRedsBlade() {}
