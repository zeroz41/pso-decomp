#include "types.h"
#include "pso/weapon/TItemWeaponMonkeyKingBar.h"
#include "pso/player/TObjPlayer.h"
#include "pso/item/TItemEquipVariant_80120CF8.h"
#include "pso/system/MatrixStack.h"
#include "pso/system/task/TMainTask.h"
#include "pso/item/TItem.h"

void TItemWeaponMonkeyKingBar::update_idle() {
    if (0.08f < scale.z) {
        scale.z -= 0.3f;
        if (scale.z < 0.08f) {
            scale.z = 0.08f;
        }
    }
}

void TItemWeaponMonkeyKingBar::update_attack() {
    if (scale.z < 1.0f) {
        scale.z += 0.3f;
        if (1.0f < scale.z) {
            scale.z = 1.0f;
        }
    }
}

void TItemWeaponMonkeyKingBar::transform_model_node() {
    if (TObjPlayer::get_player_list() == 0) {
        scale_current_matrix(&scale.x);
    }
}

TItemWeaponMonkeyKingBar::~TItemWeaponMonkeyKingBar() {}

TItemWeaponMonkeyKingBar::TItemWeaponMonkeyKingBar(TObject *parent, u8 *item) : TItemWeapon(parent, item) {
    scale.x = scale.y = scale.z = 1.0f;
}

TItem *TObjPlayer::create_shot_params_state(u8 *item) {
    if (item != NULL) {
        return new TItemWeaponMonkeyKingBar(tl_05, item);
    }
    return NULL;
}
