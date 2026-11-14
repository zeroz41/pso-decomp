#include "types.h"
#include <stddef.h>
#include "pso/weapon/TUnk_804ED390.h"
#include "pso/player/TObjPlayer.h"
#include "pso/effect/item/TItemEffOrgaFlowShot.h"
#include "pso/system/MatrixOps.h"
#include "pso/system/task/TMainTask.h"

void TUnk_804ED390::vfunc_60() {
    switch (TObjPlayer::get_player_list()) {
    case 1:
    case 2:
        scale_matrix(NULL, 1.0f, pad_1f8, pad_1f8);
        TItem::begin_effect_render();
        break;
    }
}

void TUnk_804ED390::update_idle() {
    TItemEffOrgaFlowShot::approach_value(&pad_1f8, 0.1f, 0.0f);
}

void TUnk_804ED390::update_attack() {
    TItemEffOrgaFlowShot::approach_value(&pad_1f8, 0.3f, 1.0f);
}

TUnk_804ED390::~TUnk_804ED390() {}

TUnk_804ED390::TUnk_804ED390(TObject *parent, u8 *item) : TItemWeapon(parent, item) {
    pad_1f8 = 1.0f;
}

u8 *TObjPlayer::create_vtable_1f8_state() {
    if (this != NULL) {
        return (u8 *)new TUnk_804ED390(tl_05, (u8 *)this);
    }
    return NULL;
}
