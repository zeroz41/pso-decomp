#include "pso/math/ClampedStep.h"
#include "types.h"
#include "pso/player/TObjPlayer.h"
#include "pso/weapon/TItemWeapon.h"
#include "pso/weapon/TItemWeaponDarkMeteor.h"
#include "pso/weapon/shoot/TItemShoot.h"
#include "pso/item/TItem.h"
#include "pso/system/MatrixOps.h"
#include "pso/effect/item/TItemEffOrgaFlowShot.h"
#include "pso/system/task/TMainTask.h"

// Written last-to-first: the TU was compiled with deferred codegen (its vtable comes before
// transform_model_node's jump table in .data), which emits functions in reverse order of definition.
#pragma defer_codegen on

TItem *create_dark_meteor_weapon(u8 *item) {
    if (item != NULL) {
        return new TItemWeaponDarkMeteor(tl_05, item);
    }
    return NULL;
}

TItemWeaponDarkMeteor::TItemWeaponDarkMeteor(TObject *parent, u8 *item) : TItemWeapon(parent, item) {
    set_weapon_flags(34);
    rotation_z = 0;
    shot_callback = (WeaponShotCallback)TItemShoot::spawn_shoot_particle;
}

TItemWeaponDarkMeteor::~TItemWeaponDarkMeteor() {}

void TItemWeaponDarkMeteor::update_attack() { ::add_angle_clamped(&rotation_z, -3640, 0); }

void TItemWeaponDarkMeteor::update_idle() { ::add_angle_clamped(&rotation_z, 1820, 8192); }

void TItemWeaponDarkMeteor::transform_model_node() {
    u32 player_list;
    player_list = TObjPlayer::get_player_list();
    switch (player_list) {
    case 2:
    case 5:
    case 8:
        TItem::begin_effect_render();
        return;
    case 1:
        rotate_matrix_z(0, rotation_z);
        return;
    case 7:
        rotate_matrix_z(0, -rotation_z);
    default:
        return;
    }
}

void TItemWeaponDarkMeteor::emit_marker_effects() {
    OrgaFlowShotParams info;
    Vec origin;
    if (is_mode_two_and_ready() != 0) {
        remap_extra_attack_type();
        info.reset_defaults();
        fill_status_info(&info);
        get_joint_position(4, &info.joints[0]);
        get_joint_position(3, &info.joints[1]);
        get_joint_position(6, &info.joints[2]);
        get_joint_position(9, &info.joints[3]);
        get_joint_position(0xA, &info.joints[4]);
        info.rotation_y = owner->rotation_y;
        info.hits = 0xA;
        TItemEffOrgaFlowShot::create(tl_05, &info);
        restore_action_type();
        return;
    }
    get_joint_position(6, &origin);
    launch_shot((u8 *)&origin, 0, 0, 1);
    get_joint_position(9, &origin);
    launch_shot((u8 *)&origin, 1, 0x11C7, 1);
    get_joint_position(3, &origin);
    launch_shot((u8 *)&origin, 2, -0x11C7, 1);
    get_joint_position(0xA, &origin);
    launch_shot((u8 *)&origin, 3, 0x2000, 1);
    get_joint_position(4, &origin);
    launch_shot((u8 *)&origin, 4, -0x2000, 1);
}

void TItemWeaponDarkMeteor::init_weapon_effect_descriptor(WeaponEffectDescriptor *desc) {
    desc->flags |= 0x400;
    desc->particle = 0x12;
}

OrgaFlowShotParams *OrgaFlowShotParams::reset_defaults() {
    reset_attack_params(this);
    rotation_y = 0;
    return this;
}
