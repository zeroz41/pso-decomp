#include "types.h"
#include "pso/weapon/TItemWeapon.h"
#include "pso/weapon/TItemWeaponHildebluesCane.h"
#include "pso/player/TObjPlayer.h"
#include "pso/technique/TTecGiBarta.h"
#include "pso/system/task/TMainTask.h"
#include "pso/system/MatrixOps.h"
#include <stdlib.h>

void TItemWeaponHildebluesCane::emit_marker_effects() {
    Vec sp8;
    TObjPlayer *owner;

    if (is_mode_two_and_ready() != 0) {
        if (get_joint_position(0, &sp8) != 0) {
            owner = this->owner;
            TTecGiBarta::create_ex(owner, &sp8, owner->rotation_y, (((TItemWeapon *)this)->get_tp()));
            roll_technique();
        }
    } else {
        ((TItemWeapon *)this)->update_active_game_effect();
    }
}
void TItemWeaponHildebluesCane::transform_model_node() { if (TObjPlayer::get_player_list() == 1) { rotate_matrix_x(0, this->open_angle); } }


void TItemWeaponHildebluesCane::update_idle() {
    if (this->open_state == 3) {
        this->open_state = 1;
    }
    if ((this->open_state == 0) && ((3.0517578e-05f * (f32) rand()) < 0.1f)) {
        this->open_state = 2;
    }
}

void TItemWeaponHildebluesCane::update_attack() {
    s32 open_state;

    open_state = this->open_state;
    if ((open_state == 1) || (open_state == 0)) {
        this->open_state = 2;
    }
}

void TItemWeaponHildebluesCane::update_weapon() {
    s32 open_state;
    s32 open_angle;
    s32 angle;
    open_state = this->open_state;
    if (open_state == 2) {
        open_angle = this->open_angle;
        if (open_angle < 0x2AAA) {
            this->open_angle = (open_angle + 0x888);
            if (this->open_angle >= 0x2AAA) {
                this->open_angle = 0x2AAA;
                this->open_state = 3;
            }
        }
    } else if (open_state == 1) {
        angle = this->open_angle;
        if (angle > 0) {
            this->open_angle = (angle - 0x444);
            if (this->open_angle <= 0) {
                this->open_angle = 0;
                this->open_state = 0;
            }
        }
    }
}

void TItemWeaponHildebluesCane::on_equipped() { roll_technique(); roll_technique(); }

TItemWeaponHildebluesCane::~TItemWeaponHildebluesCane() {}

TItemWeaponHildebluesCane::TItemWeaponHildebluesCane(TObject *parent, u8 *item) : TItemWeapon(parent, item) {
    set_weapon_flags(34);
    open_angle = 0;
    open_state = 0;
    set_technique_roll_range(10);
}

TItem *TItemWeaponHildebluesCane::create(u8 *item) {
    if (item != NULL) {
        return new TItemWeaponHildebluesCane(tl_05, item);
    }
    return NULL;
}
