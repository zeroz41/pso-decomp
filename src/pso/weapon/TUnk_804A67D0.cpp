#include "types.h"
#include "pso/weapon/TUnk_804A67D0.h"
#include "pso/item/TItemHeapObject.h"
#include "pso/item/TUnk_804A0628.h"
#include "pso/player/TObjPlayer.h"
#include "pso/system/MatrixStack.h"
#include "pso/system/SoundEffect.h"
#include "pso/system/task/TMainTask.h"

void TUnk_804A67D0::vfunc_60() {
    if (TObjPlayer::get_player_list() == 2) {
        scale_current_matrix(&scale.x);
    }
}

// Starts a 90-frame timer event on the effect objects (named
// madam_umbrella_start_regen before; vtable slot 57).
void TUnk_804A67D0::on_equipped() {
    if (effect_objects != NULL) {
        new TUnk_804A0628(effect_objects, get_owner_client(), 0x5A);
    }
}

#pragma push
#pragma dont_inline off
#pragma inline_depth(1)
void TUnk_804A67D0::update_idle() {
    if (scale.open() == 1) {
        play_sound_effect(0x4001AA24, &owner->position, 0, 0);
    }
}

void TUnk_804A67D0::update_attack() {
    scale.close();
}
#pragma pop

TUnk_804A67D0::~TUnk_804A67D0() {}

TUnk_804A67D0::TUnk_804A67D0(TObject *parent, u8 *item) : TItemWeapon(parent, item) {
    scale.x = scale.y = scale.z = 1.0f;
}

TItem *TObjPlayer::create_fields_state(u8 *item) {
    if (item != NULL) {
        return new TUnk_804A67D0(tl_05, item);
    }
    return NULL;
}
