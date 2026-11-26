#include "pso/math/ClampedStep.h"
#include "types.h"
#include "pso/weapon/TItemWeaponCane.h"
#include "pso/player/TObjPlayer.h"
#include "pso/item/TItem.h"
#include "pso/weapon/TItemWeapon.h"
#include "pso/system/MatrixOps.h"
#include "pso/system/task/TMainTask.h"
#include "pso/effect/item/TItemEffCane.h"

void TItemWeaponCane::transform_model_node() {
    if (get_item_index() == 5) {
        switch (get_model_node_counter()) {
        case 1:
            scale_matrix(NULL, scale, scale, scale);
            break;
        }
    }
}

void TItemWeaponCane::update_idle() {
    if (attack_spawned == 1) {
        attack_spawned = 0;
    }
    if (get_item_index() == 5) {
        ::approach_value(&scale, -0.2f, 0.6f);
    }
}

void TItemWeaponCane::update_attack() {
    if (attack_spawned == 0) {
        switch ((s32)get_item_index()) {
        case 5:
            break;
        case 4:
            if (get_attack_stage() == 0) {
                TItemEffCane::create(tl_05, this, 1, 0x1AE);
            }
            break;
        case 6:
            if (get_attack_stage() == 0) {
                TItemEffCane::create(tl_05, this, 2, 0x101);
            }
            break;
        }
        attack_spawned = 1;
    }
    if (get_item_index() == 5) {
        ::approach_value(&scale, 0.1f, 1.0f);
    }
}

TItemWeaponCane::~TItemWeaponCane() {}

TItemWeaponCane::TItemWeaponCane(TObject *parent, u8 *item) : TItemWeapon(parent, item) {
    scale = 1.0f;
    attack_spawned = 0;
    if (item[2] >= 4U) {
        set_color_node(-1);
    }
}

TItem *TItemWeaponCane::create(u8 *item) {
    if (item != NULL) {
        return new TItemWeaponCane(tl_05, item);
    }
    return NULL;
}
