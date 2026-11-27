#include "types.h"
#include "pso/weapon/TItemWeaponPanthersClaw.h"
#include "pso/weapon/TItemWeapon.h"
#include "pso/player/TObjPlayer.h"
#include "pso/item/TItem.h"
#include "pso/system/task/TMainTask.h"
#include "pso/system/MatrixStack.h"

void TItemWeaponPanthersClaw::transform_model_node() { if (get_model_node_counter() == 1) { scale_current_matrix(&scale.x); } }

void TItemWeaponPanthersClaw::update_idle() {
    if (1e-05f < scale.z) {
        scale.z -= 0.3f;
        if (scale.z < 1e-05f) {
            scale.z = 1e-05f;
        }
        scale.x = scale.y = scale.z;
    }
}

void TItemWeaponPanthersClaw::update_attack() {
    if (scale.z < 1.0f) {
        scale.z += 0.3f;
        if (1.0f < scale.z) {
            scale.z = 1.0f;
        }
        scale.x = scale.y = scale.z;
    }
}


void TItemWeaponPanthersClaw::draw_held_model() {
  NJS_OBJECT *saved_model;
  saved_model = item_model;
  draw_weapon_at_joint(0x2F);
  update_trail_slot(0);
  update_trail_slot(1);
  item_model = second_model;
  draw_weapon_at_joint(0x22);
  item_model = saved_model;
}

TItemWeaponPanthersClaw::~TItemWeaponPanthersClaw() {}

TItemWeaponPanthersClaw::TItemWeaponPanthersClaw(TObject *parent, u8 *item) : TItemWeapon(parent, item) {
    set_weapon_flags(513);
    scale.x = scale.y = scale.z = 0.0f;
}

TItem *TItemWeaponPanthersClaw::create(u8 *item) {
    if (item != NULL) {
        return new TItemWeaponPanthersClaw(tl_05, item);
    }
    return NULL;
}
