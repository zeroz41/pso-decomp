#include "types.h"
#include "pso/weapon/TUnk_804A5C18.h"
#include "pso/math/MatrixTransforms.h"
#include "pso/system/MatrixOps.h"
#include "pso/player/TObjPlayer.h"
#include "pso/unk/text_80087278.h"
#include "pso/effect/item/TItemEffOrgaFlowShot.h"
#include "pso/player/TObjPlayer_80109344.h"
#include "pso/unk/text_8011B620.h"
#include "pso/item/TItem.h"
#include "pso/system/task/TMainTask.h"

void TUnk_804A5C18::vfunc_60() {
    s32 node;
    s32 angle;

    node = TObjPlayer::get_player_list();
    if (get_item_index() != 6) {
        if (node == slide_node) {
            translate_matrix(0, 0.0f, slide_offset, 0.0f);
        }
        angle = barrel_angle;
    } else {
        if (node == slide_node) {
            rotate_matrix_x(NULL, -barrel_angle);
        }
        angle = (barrel_angle * 2) / 3;
    }
    if (node == barrel_nodes[0] || node == barrel_nodes[2]) {
        rotate_matrix_z(NULL, angle);
    }
    if (node == barrel_nodes[1] || node == barrel_nodes[3]) {
        rotate_matrix_z(NULL, -angle);
    }
}

extern "C" s32 basic_shot_angle_table[];

void TUnk_804A5C18::emit_marker_effects() {
    s32 pos[3];
    s32 i;

    // signed i but an unsigned != loop test (cmpwi i,0 / cmplwi i,5), as in the tree
    for (i = 0; (u32)i != 5U; i++) {
        get_joint_position(muzzle_joints[i], pos);
        launch_shot((u8 *)pos, i, basic_shot_angle_table[i], 1);
        if (i == 0) {
            spawn_particle_effect(pos, 9);
        }
    }
}

void TUnk_804A5C18::update_idle() {
    if (barrel_angle < 0x2000) {
        TObjPlayer::add_angle_clamped(&barrel_angle, 0x2D8, 0x2000);
    }
    TItemEffOrgaFlowShot::approach_value(&slide_offset, -0.4f, -1.2f);
}

void TUnk_804A5C18::update_attack() {
    if (barrel_angle > 0) {
        TObjPlayer::add_angle_clamped(&barrel_angle, -0x2000, 0);
    }
    TItemEffOrgaFlowShot::approach_value(&slide_offset, 0.6f, 0.0f);
}

TUnk_804A5C18::TUnk_804A5C18(TObject *parent, u8 *item) : TItemWeapon(parent, item) {
    set_weapon_flags(2);
    shot_callback = (WeaponShotCallback)create_gun_shot;
    impact_callback = (WeaponHitCallback)spawn_weapon_impact_effect;
    shot_speed = 15.0f;
    barrel_angle = 0x2000;
    slide_offset = 0.0f;
    barrel_nodes[2] = -1;
    barrel_nodes[3] = -1;
    barrel_angle = -1;  // the original stores 0x220 again here, not slide_node
    switch (item[2]) {
    case 5:
        muzzle_joints[0] = 9;
        muzzle_joints[1] = 4;
        muzzle_joints[2] = 8;
        muzzle_joints[3] = 3;
        muzzle_joints[4] = 7;
        barrel_nodes[0] = 1;
        barrel_nodes[1] = 5;
        break;
    case 6:
        muzzle_joints[0] = 10;
        muzzle_joints[1] = 8;
        muzzle_joints[2] = 4;
        muzzle_joints[3] = 7;
        muzzle_joints[4] = 3;
        barrel_nodes[0] = 5;
        barrel_nodes[1] = 1;
        slide_node = 9;
        break;
    case 7:
        muzzle_joints[0] = 19;
        muzzle_joints[1] = 14;
        muzzle_joints[2] = 10;
        muzzle_joints[3] = 6;
        muzzle_joints[4] = 2;
        barrel_nodes[0] = 3;
        barrel_nodes[1] = 11;
        barrel_nodes[2] = 7;
        barrel_nodes[3] = 15;
        slide_node = 1;
        break;
    default:
        muzzle_joints[0] = 7;
        muzzle_joints[1] = 3;
        muzzle_joints[2] = 5;
        muzzle_joints[3] = 2;
        muzzle_joints[4] = 6;
        barrel_nodes[0] = 1;
        barrel_nodes[1] = 4;
        break;
    }
    if (item[2] >= 5) {
        ((TObjPlayer *)this)->set_atp(-1);
    }
}

u8 *create_shot_weapon(u8 *item) {
    if (item != NULL) {
        return (u8 *)new TUnk_804A5C18(tl_05, item);
    }
    return NULL;
}

TUnk_804A5C18::~TUnk_804A5C18() {}
