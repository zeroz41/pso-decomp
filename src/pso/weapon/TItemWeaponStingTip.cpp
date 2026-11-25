#include "types.h"
#include "pso/weapon/TItemWeaponStingTip.h"
#include "pso/item/TItem.h"
#include "pso/item/TItemMenuCtrl_80115AF0.h"
#include "pso/player/TObjPlayer.h"
#include "pso/system/MatrixOps.h"
#include "pso/system/task/TMainTask.h"

void TItemWeaponStingTip::transform_model_node() {
    switch (TObjPlayer::get_player_list()) {
    case 1:
        TItem::begin_effect_render();
        rotate_matrix_z(NULL, rotation_z);
        return;
    case 2:
        TItem::begin_effect_render();
        rotate_matrix_z(NULL, -rotation_z);
        return;
    case 3:
        TItem::begin_effect_render();
        return;
    }
}

void TItemWeaponStingTip::update_weapon() { advance_angle_wrap(&rotation_z, 3276); }

TItemWeaponStingTip::TItemWeaponStingTip(TObject *parent, u8 *item) : TItemWeapon(parent, item) {
    rotation_z = 0;
}


TItem *TItemWeaponStingTip::create(u8 *item) {
    if (item != NULL) {
        return new TItemWeaponStingTip(tl_05, item);
    }
    return NULL;
}

TItemWeaponStingTip::~TItemWeaponStingTip() {}
