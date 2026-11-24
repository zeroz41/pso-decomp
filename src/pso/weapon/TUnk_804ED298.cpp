#include "pso/math/ClampedStep.h"
#include "types.h"
#include <stddef.h>
#include "pso/weapon/TUnk_804ED298.h"
#include "pso/player/TObjPlayer.h"
#include "pso/math/MatrixTransforms.h"
#include "pso/system/task/TMainTask.h"

void TUnk_804ED298::vfunc_60() {
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

void TUnk_804ED298::update_idle() {
    ::approach_value(&pad_1f8, 0.5f, 5.0f);
    ::approach_value(&pad_1fc, -0.1f, -1.0f);
}

void TUnk_804ED298::update_attack() {
    ::approach_value(&pad_1f8, -1.0f, 0.0f);
    ::approach_value(&pad_1fc, 0.2f, 0.0f);
}

TUnk_804ED298::~TUnk_804ED298() {}

TUnk_804ED298::TUnk_804ED298(TObject *parent, u8 *item) : TItemWeapon(parent, item) {
    pad_1f8 = 0.0f;
    pad_1fc = 1.0f;
}

TItem *TObjPlayer::create_mode_floats_state(u8 *item) {
    if (item != NULL) {
        return new TUnk_804ED298(tl_05, item);
    }
    return NULL;
}
