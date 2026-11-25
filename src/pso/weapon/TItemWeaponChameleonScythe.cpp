#include "pso/math/ClampedStep.h"
#include "types.h"
#include "pso/weapon/TItemWeaponChameleonScythe.h"
#include "pso/player/TObjPlayer.h"
#include "pso/item/TItem.h"
#include "pso/system/MatrixStack.h"
#include "pso/system/task/TMainTask.h"

void TItemWeaponChameleonScythe::transform_model_node() {
    if (TObjPlayer::get_player_list() == 2) {
        scale_current_matrix(&scale.x);
    }
}

void TItemWeaponChameleonScythe::update_idle() {
    ::approach_value(&scale.z, -0.6f, 1.0f);
}

void TItemWeaponChameleonScythe::update_attack() {
    ::approach_value(&scale.z, 0.6f, 4.0f);
}

void TItemWeaponChameleonScythe::on_equipped() {}

TItemWeaponChameleonScythe::~TItemWeaponChameleonScythe() {}

TItemWeaponChameleonScythe::TItemWeaponChameleonScythe(TObject *parent, u8 *item) : TItemWeapon(parent, item) {
    scale.x = scale.y = scale.z = 1.0f;
}

TItem *TObjPlayer::create_effect_state(u8 *item) {
    if (item != NULL) {
        return new TItemWeaponChameleonScythe(tl_05, item);
    }
    return NULL;
}
