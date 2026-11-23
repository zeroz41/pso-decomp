#include "types.h"
#include "pso/weapon/TItemWeapon.h"
#include <stdlib.h>
#include "pso/weapon/TUnk_804A0BC0.h"
#include "pso/player/TObjPlayer.h"
#include "pso/technique/TTecFoie.h"
#include "pso/system/MatrixOps.h"
#include "pso/system/task/TMainTask.h"

void TUnk_804A0BC0::emit_marker_effects() {
    WeaponVector pos;
    TObjPlayer *player;

    if (is_mode_two_and_ready() != 0) {
        if (get_joint_position(0, &pos) != 0) {
            player = owner;
            TTecFoie::create(player, &pos, player->rotation_y, get_tp());
            roll_technique();
        }
    } else {
        ((TItemWeapon *)this)->update_active_game_effect();
    }
}

void TUnk_804A0BC0::vfunc_60() {
    if (TObjPlayer::get_player_list() == 1) {
        rotate_matrix_x(NULL, open_angle);
    }
}

void TUnk_804A0BC0::update_idle() {
    if (open_state == 3) {
        open_state = 1;
    }
    if ((open_state == 0) && ((3.0517578e-05f * (f32)rand()) < 0.1f)) {
        open_state = 2;
    }
}

void TUnk_804A0BC0::update_attack() {
    s32 state;

    state = open_state;
    if ((state == 1) || (state == 0)) {
        open_state = 2;
    }
}

void TUnk_804A0BC0::update_weapon() {
    s32 state;
    s32 angle;

    state = open_state;
    if (state == 2) {
        angle = open_angle;
        if (angle < 0x2AAA) {
            open_angle = angle + 0x888;
            if (open_angle >= 0x2AAA) {
                open_angle = 0x2AAA;
                open_state = 3;
            }
        }
    } else if (state == 1) {
        angle = open_angle;
        if (angle > 0) {
            open_angle = angle - 0x444;
            if (open_angle <= 0) {
                open_angle = 0;
                open_state = 0;
            }
        }
    }
}

void TUnk_804A0BC0::on_equipped() {
    roll_technique();
    roll_technique();
}

TUnk_804A0BC0::~TUnk_804A0BC0() {}

TUnk_804A0BC0::TUnk_804A0BC0(TObject *parent, u8 *item) : TItemWeapon(parent, item) {
    set_weapon_flags(34);
    open_angle = 0;
    open_state = 0;
    set_technique_roll_range(10);
}

TItem *TObjPlayer::create_enter_state_804A0BC0(u8 *item) {
    if (item != NULL) {
        return new TUnk_804A0BC0(tl_05, item);
    }
    return NULL;
}

saddr TItemWeapon::get_tp() { return (this->previous_technique_roll); }
void TItemWeapon::set_technique_roll_range(s32 range) { technique_roll_range = range; }
