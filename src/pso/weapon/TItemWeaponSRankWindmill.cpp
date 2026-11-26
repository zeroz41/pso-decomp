#include "types.h"
#include "pso/weapon/TItemWeapon.h"
#include "pso/item/TItemMenuCtrl.h"
#include "pso/unk/text_80120908.h"
#include "pso/weapon/TItemWeaponSRankWindmill.h"
#include "pso/player/TObjPlayer.h"
#include "pso/item/TItem.h"
#include "pso/weapon/TItemWeaponSRank.h"
#include "pso/system/MatrixOps.h"
#include "pso/system/task/TMainTask.h"

// Turns the blade by blade_angle (the name s_rank_windmill_turn_blade was inferred).
void TItemWeaponSRankWindmill::transform_model_node() {
    if (TObjPlayer::get_player_list() == 3) {
        rotate_matrix_x(NULL, blade_angle);
    }
}

void TItemWeaponSRankWindmill::draw_held_model() {
    NJS_OBJECT *blend_node;

    if (owner != NULL) {
        blend_node = item_model->child->sibling->sibling;
        if (blend_off == 0) {
            blend_node->evalflags |= 0x10;
        }
        draw_weapon_model();
        this->update_trail_slot(0);
        if (blend_off == 0) {
            blend_node->evalflags &= 0xFFFFFFEF;
        }
    }
}

void TItemWeaponSRankWindmill::update_idle() {
    s32 speed;

    speed = blade_speed;
    if (speed > 0xCCC) {
        blade_speed = speed - 0xB6;
    }
}

void TItemWeaponSRankWindmill::update_attack() {
    s32 speed;

    attack_frames++;
    if (!(attack_frames & 3)) {
        speed = blade_speed;
        if (speed < 0x3333) {
            blade_speed = speed + 0xB6;
        }
    }
}

void TItemWeaponSRankWindmill::update_weapon() {
    advance_angle_wrap(&blade_angle, blade_speed);
}

TItemWeaponSRankWindmill::~TItemWeaponSRankWindmill() {}

TItemWeaponSRankWindmill::TItemWeaponSRankWindmill(TObject *parent, u8 *item) : TItemWeaponSRank(parent, item) {
    set_weapon_flags(35);
    blade_angle = 0;
    blade_speed = 3276;
    attack_frames = 0;
    blend_off = 1;
}

TItem *TItemWeaponSRankWindmill::create(u8 *item) {
    if (item != NULL) {
        return new TItemWeaponSRankWindmill(tl_05, item);
    }
    return NULL;
}
