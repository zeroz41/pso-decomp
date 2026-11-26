#include "pso/math/ClampedStep.h"
#include "types.h"
#include <stddef.h>
#include "pso/weapon/TItemWeaponPartisanOfLightning.h"
#include "pso/player/TObjPlayer.h"
#include "pso/system/MatrixOps.h"
#include "pso/system/task/TMainTask.h"

void TItemWeaponPartisanOfLightning::transform_model_node() {
    switch (get_model_node_counter()) {
    case 1:
    case 2:
        scale_matrix(NULL, 1.0f, effect_thickness, effect_thickness);
        TItem::begin_effect_render();
        break;
    }
}

void TItemWeaponPartisanOfLightning::update_idle() {
    ::approach_value(&effect_thickness, 0.1f, 0.0f);
}

void TItemWeaponPartisanOfLightning::update_attack() {
    ::approach_value(&effect_thickness, 0.3f, 1.0f);
}

TItemWeaponPartisanOfLightning::~TItemWeaponPartisanOfLightning() {}

TItemWeaponPartisanOfLightning::TItemWeaponPartisanOfLightning(TObject *parent, u8 *item) : TItemWeapon(parent, item) {
    effect_thickness = 1.0f;
}

TItem *TItemWeaponPartisanOfLightning::create(u8 *item) {
    if (item != NULL) {
        return new TItemWeaponPartisanOfLightning(tl_05, item);
    }
    return NULL;
}
