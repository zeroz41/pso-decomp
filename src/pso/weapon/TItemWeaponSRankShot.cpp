#include "pso/math/ClampedStep.h"
#include "pso/effect/particle/ParticleFactory.h"
#include "types.h"
#include "pso/player/TObjPlayer.h"
#include "pso/weapon/TItemWeaponSRankPunch.h"
#include "pso/weapon/TItemWeaponSRankShot.h"
#include "pso/unk/text_80129AB0.h"
#include "pso/weapon/shoot/TItemShoot.h"
#include "pso/system/MatrixOps.h"
#include "pso/item/TItem.h"
#include "pso/system/task/TMainTask.h"

// The spread of the five shots (launch_shot angles).
s32 s_rank_shot_marker_offsets[5] = {0, 0x888, -0x888, 0x11C7, -0x11C7};

// Spins the barrels by barrel_angle (the name s_rank_shot_turn_barrels was inferred).
void TItemWeaponSRankShot::transform_model_node() {
    if (get_model_node_counter() == 1) {
        rotate_matrix_z(NULL, barrel_angle);
    }
    if (get_model_node_counter() == 4) {
        rotate_matrix_z(NULL, -barrel_angle);
    }
}

void TItemWeaponSRankShot::emit_marker_effects() {
    Vec pos;
    debug_weapon_attack_hook();
    get_joint_position(7, &pos);
    spawn_particle_effect(&pos, 9);
    launch_shot(&pos, 0, s_rank_shot_marker_offsets[0], 1);
    get_joint_position(3, &pos);
    launch_shot(&pos, 1, s_rank_shot_marker_offsets[1], 1);
    get_joint_position(5, &pos);
    launch_shot(&pos, 2, s_rank_shot_marker_offsets[2], 1);
    get_joint_position(2, &pos);
    launch_shot(&pos, 3, s_rank_shot_marker_offsets[3], 1);
    get_joint_position(6, &pos);
    launch_shot(&pos, 4, s_rank_shot_marker_offsets[4], 1);
}

void TItemWeaponSRankShot::update_idle() {
    if (barrel_angle < 0x2000) {
        ::add_angle_clamped(&barrel_angle, 0x2D8, 0x2000);
    }
}

void TItemWeaponSRankShot::update_attack() {
    if (barrel_angle > 0) {
        ::add_angle_clamped(&barrel_angle, -0x2000, 0);
    }
}

TItemWeaponSRankShot::TItemWeaponSRankShot(TObject *parent, u8 *item) : TItemWeaponSRank(parent, item) {
    barrel_angle = 0x2000;
    set_weapon_flags(2);
    shot_callback = (WeaponShotCallback)create_gun_shot;
    shot_speed = 15.0f;
}

TItem *TItemWeaponSRankShot::create(u8 *item) {
    if (item != NULL) {
        return new TItemWeaponSRankShot(tl_05, item);
    }
    return NULL;
}

TItemWeaponSRankShot::~TItemWeaponSRankShot() {}
