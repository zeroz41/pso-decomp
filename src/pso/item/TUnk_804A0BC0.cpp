#include "types.h"
#include <stdlib.h>
#include "pso/item/TUnk_804A0BC0.h"
#include "pso/player/TObjPlayer.h"
#include "pso/misc/TTecFoie.h"
#include "pso/system/MatrixOps.h"
#include "pso/TMainTask.h"

void TUnk_804A0BC0::emit_marker_effects() {
    WeaponVector pos;
    TObjPlayer *player;

    if (is_mode_two_and_ready() != 0) {
        if (get_joint_position(0, &pos) != 0) {
            player = owner;
            TTecFoie::create(player, &pos, (void *)(*(s32 *)((s8 *)player + 0x60)), (void *)(((TObjPlayer *)this)->get_tp()));
            roll_technique();
        }
    } else {
        ((TObjPlayer *)this)->update_active_game_effect();
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

void TUnk_804A0BC0::vfunc_57() {
    roll_technique();
    roll_technique();
}

TUnk_804A0BC0::~TUnk_804A0BC0() {}

TUnk_804A0BC0::TUnk_804A0BC0(TObject *parent, u8 *item) : TItemWeapon(parent, item) {
    set_weapon_flags(34);
    open_angle = 0;
    open_state = 0;
    ((TObjPlayer *)this)->set_effect_state(10);
}

u8 *TObjPlayer::create_enter_state_804A0BC0(u8 *arg0) {
    if (arg0 != NULL) {
        return (u8 *)new TUnk_804A0BC0(tl_05, arg0);
    }
    return NULL;
}

s32 TObjPlayer::get_tp() { return this->m_1c0; }
void TObjPlayer::set_effect_state(s32 v) { *(s32 *)&this->unk_1C4 = v; }
