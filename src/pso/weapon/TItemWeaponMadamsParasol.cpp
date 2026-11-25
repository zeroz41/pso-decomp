#include "types.h"
#include "pso/weapon/TItemWeaponMadamsParasol.h"
#include "pso/item/TItemHeapObject.h"
#include "pso/item/TUnk_804A0648.h"
#include "pso/player/TObjPlayer.h"
#include "pso/system/MatrixStack.h"
#include "pso/system/SoundEffect.h"
#include "pso/system/task/TMainTask.h"

void TItemWeaponMadamsParasol::transform_model_node() {
    if (TObjPlayer::get_player_list() == 2) {
        scale_current_matrix(&scale.x);
    }
}

// Starts a 90-frame timer event on the effect objects (named
// madam_parasol_start_regen before; vtable slot 57).
void TItemWeaponMadamsParasol::on_equipped() {
    if (effect_objects != NULL) {
        new TUnk_804A0648(effect_objects, get_owner_client(), 0x5A);
    }
}

#pragma push
#pragma dont_inline off
#pragma inline_depth(1)
void TItemWeaponMadamsParasol::update_idle() {
    if (scale.open() == 1) {
        play_sound_effect(0x4001AA24, &owner->position, 0, 0);
    }
}

void TItemWeaponMadamsParasol::update_attack() {
    scale.close();
}
#pragma pop

TItemWeaponMadamsParasol::~TItemWeaponMadamsParasol() {}

TItemWeaponMadamsParasol::TItemWeaponMadamsParasol(TObject *parent, u8 *item) : TItemWeapon(parent, item) {
    scale.x = scale.y = scale.z = 1.0f;
}

TItem *TObjPlayer__sub_8012F298(u8 *item) {
    if (item != NULL) {
        return new TItemWeaponMadamsParasol(tl_05, item);
    }
    return NULL;
}
