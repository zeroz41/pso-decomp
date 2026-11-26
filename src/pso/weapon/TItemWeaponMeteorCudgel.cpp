#include "types.h"
#include "pso/weapon/TItemWeaponMeteorCudgel.h"
#include "pso/player/TObjPlayer.h"
#include "pso/weapon/TItemWeapon.h"
#include "pso/item/TItem.h"
#include "pso/system/MatrixStack.h"
#include "pso/system/task/TMainTask.h"

void TItemWeaponMeteorCudgel::update_idle() {
    if (0.3f < scale.z) {
        scale.z -= 0.2f;
        if (scale.z < 0.3f) {
            scale.z = 0.3f;
        }
    }
}

void TItemWeaponMeteorCudgel::update_attack() {
    if (scale.z < 1.0f) {
        scale.z += 0.2f;
        if (1.0f < scale.z) {
            scale.z = 1.0f;
        }
    }
}

void TItemWeaponMeteorCudgel::transform_model_node() {
    if (get_model_node_counter() == 0) {
        scale_current_matrix(&scale.x);
    }
}

TItemWeaponMeteorCudgel::~TItemWeaponMeteorCudgel() {}

TItemWeaponMeteorCudgel::TItemWeaponMeteorCudgel(TObject *parent, u8 *item) : TItemWeapon(parent, item) {
    set_weapon_trail_joints(this, 0, 3, 2);
    set_weapon_trail_joints(this, 1, 4, 5);
    scale.x = scale.y = scale.z = 1.0f;
}

TItem *TItemWeaponMeteorCudgel::create(u8 *item) {
    if (item != NULL) {
        return new TItemWeaponMeteorCudgel(tl_05, item);
    }
    return NULL;
}
