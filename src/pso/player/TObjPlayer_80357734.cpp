#include "types.h"
#include "pso/player/TObjPlayer.h"
#include "pso/weapon/TItemWeapon.h"
#include "pso/weapon/TUnk_804F14A8.h"
#include "pso/weapon/shoot/TItemShoot.h"
#include "pso/item/TItem.h"
#include "pso/system/MatrixOps.h"
#include "pso/effect/item/TItemEffOrgaFlowShot.h"
#include "pso/system/task/TMainTask.h"

// Written last-to-first: the TU was compiled with deferred codegen (its vtable comes before
// vfunc_60's jump table in .data), which emits functions in reverse order of definition.
#pragma defer_codegen on

u8 *TObjPlayer::create_state_34_alt() {
    if (this != NULL) {
        return (u8 *)new TUnk_804F14A8(tl_05, (u8 *)this);
    }
    return NULL;
}

TUnk_804F14A8::TUnk_804F14A8(TObject *parent, u8 *item) : TItemWeapon(parent, item) {
    set_weapon_flags(34);
    rotation_z = 0;
    shot_callback = (WeaponShotCallback)TItemShoot::spawn_shoot_particle;
}

TUnk_804F14A8::~TUnk_804F14A8() {}

void TUnk_804F14A8::update_attack() { TObjPlayer::add_angle_clamped(&rotation_z, -3640, 0); }

void TUnk_804F14A8::update_idle() { TObjPlayer::add_angle_clamped(&rotation_z, 1820, 8192); }

void TUnk_804F14A8::vfunc_60() {
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

void TUnk_804F14A8::emit_marker_effects() {
    S_80357734 info;
    Vec sp8;
    if (is_mode_two_and_ready() != 0) {
        remap_extra_attack_type();
        info.reset_field28();
        ((TObjPlayer *)this)->fill_status_info(&info);
        get_joint_position(4, &info.joints[0]);
        get_joint_position(3, &info.joints[1]);
        get_joint_position(6, &info.joints[2]);
        get_joint_position(9, &info.joints[3]);
        get_joint_position(0xA, &info.joints[4]);
        info.rotation_y = *(s32 *)((s8 *)this->owner + 0x60);
        info.hits = 0xA;
        TItemEffOrgaFlowShot::create(tl_05, &info);
        restore_action_type();
        return;
    }
    get_joint_position(6, &sp8);
    launch_shot((u8 *)&sp8, 0, 0, 1);
    get_joint_position(9, &sp8);
    launch_shot((u8 *)&sp8, 1, 0x11C7, 1);
    get_joint_position(3, &sp8);
    launch_shot((u8 *)&sp8, 2, -0x11C7, 1);
    get_joint_position(0xA, &sp8);
    launch_shot((u8 *)&sp8, 3, 0x2000, 1);
    get_joint_position(4, &sp8);
    launch_shot((u8 *)&sp8, 4, -0x2000, 1);
}

void TUnk_804F14A8::init_weapon_effect_descriptor(Desc_8011E5C4 *desc) {
    desc->flags |= 0x400;
    desc->pad_78 = 0x12;
}

S_80357734 *S_80357734::reset_field28() {
    TObjPlayer__sub_802E451C(this);
    rotation_y = 0;
    return this;
}
