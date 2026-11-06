#include "types.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TObjPlayer_80128A70.h"
#include "pso/unk/text_80087278.h"
#include "pso/weapon/TUnk_804A444C.h"
#include "pso/unk/text_80129AB0.h"
#include "pso/unk/text_8011B620.h"
#include "pso/system/MatrixOps.h"
#include "pso/item/TItem.h"
#include "pso/system/task/TMainTask.h"

// The spread of the five shots (launch_shot angles).
s32 s_rank_shot_marker_offsets[5] = {0, 0x888, -0x888, 0x11C7, -0x11C7};

// Spins the barrels by barrel_angle (the name s_rank_shot_turn_barrels was inferred).
void TUnk_804A444C::vfunc_60() {
    if (TObjPlayer::get_player_list() == 1) {
        rotate_matrix_z(NULL, barrel_angle);
    }
    if (TObjPlayer::get_player_list() == 4) {
        rotate_matrix_z(NULL, -barrel_angle);
    }
}

void TUnk_804A444C::emit_marker_effects() {
    WeaponVector pos;
    TObjPlayer__sub_80128A70();
    get_joint_position(7, &pos);
    spawn_particle_effect(&pos, 9);
    launch_shot((u8 *)&pos, 0, s_rank_shot_marker_offsets[0], 1);
    get_joint_position(3, &pos);
    launch_shot((u8 *)&pos, 1, s_rank_shot_marker_offsets[1], 1);
    get_joint_position(5, &pos);
    launch_shot((u8 *)&pos, 2, s_rank_shot_marker_offsets[2], 1);
    get_joint_position(2, &pos);
    launch_shot((u8 *)&pos, 3, s_rank_shot_marker_offsets[3], 1);
    get_joint_position(6, &pos);
    launch_shot((u8 *)&pos, 4, s_rank_shot_marker_offsets[4], 1);
}

void TUnk_804A444C::update_idle() {
    if (barrel_angle < 0x2000) {
        TObjPlayer::add_angle_clamped(&barrel_angle, 0x2D8, 0x2000);
    }
}

void TUnk_804A444C::update_attack() {
    if (barrel_angle > 0) {
        TObjPlayer::add_angle_clamped(&barrel_angle, -0x2000, 0);
    }
}

TUnk_804A444C::TUnk_804A444C(TObject *parent, u8 *item) : TUnk_804A4948(parent, item) {
    barrel_angle = 0x2000;
    set_weapon_flags(2);
    shot_callback = (WeaponShotCallback)create_gun_shot;
    shot_speed = 15.0f;
}

u8 *create_s_rank_shot(s32 arg0) {
    if (arg0 != 0) {
        return (u8 *)new TUnk_804A444C(tl_05, (u8 *)arg0);
    }
    return NULL;
}

TUnk_804A444C::~TUnk_804A444C() {}
