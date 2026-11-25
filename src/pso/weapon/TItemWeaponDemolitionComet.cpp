#include "pso/math/ClampedStep.h"
#include "types.h"
#include <stddef.h>
#include "pso/weapon/TItemWeaponDemolitionComet.h"
#include "pso/player/TObjPlayer.h"
#include "pso/math/MatrixTransforms.h"
#include "pso/system/task/TMainTask.h"

void TItemWeaponDemolitionComet::transform_model_node() {
    switch (TObjPlayer::get_player_list()) {
    case 2: {
        NJS_ARGB color = { pad_1fc, 0.0f, 0.0f, 0.0f };
        TItem::begin_offset_material_color(&color);
        break;
    }
    case 3:
        translate_matrix(0, 0.0f, 0.0f, -pad_1f8);
        break;
    case 4:
        translate_matrix(0, 0.0f, 0.0f, pad_1f8);
        break;
    }
}

void TItemWeaponDemolitionComet::update_idle() {
    ::approach_value(&pad_1f8, 0.5f, 5.0f);
    ::approach_value(&pad_1fc, -0.1f, -1.0f);
}

void TItemWeaponDemolitionComet::update_attack() {
    ::approach_value(&pad_1f8, -1.0f, 0.0f);
    ::approach_value(&pad_1fc, 0.2f, 0.0f);
}

TItemWeaponDemolitionComet::~TItemWeaponDemolitionComet() {}

TItemWeaponDemolitionComet::TItemWeaponDemolitionComet(TObject *parent, u8 *item) : TItemWeapon(parent, item) {
    pad_1f8 = 0.0f;
    pad_1fc = 1.0f;
}

TItem *TItemWeaponDemolitionComet::create(u8 *item) {
    if (item != NULL) {
        return new TItemWeaponDemolitionComet(tl_05, item);
    }
    return NULL;
}
