#include "types.h"
#include "pso/weapon/TItemWeaponHarisenBattleFan.h"
#include "pso/player/TObjPlayer.h"
#include "pso/system/MatrixStack.h"
#include "pso/system/task/TMainTask.h"

void TItemWeaponHarisenBattleFan::transform_model_node() {
    if (TObjPlayer::get_player_list() == 1) {
        scale_current_matrix(&scale.x);
    }
}

void TItemWeaponHarisenBattleFan::emit_marker_effects() { scale.y = 0.1f; }

void TItemWeaponHarisenBattleFan::update_weapon() {
    if (scale.y < 1.0f) {
        scale.y += 0.1f;
        if (1.0f <= scale.y) {
            scale.y = 1.0f;
        }
    }
}

TItemWeaponHarisenBattleFan::~TItemWeaponHarisenBattleFan() {}

TItemWeaponHarisenBattleFan::TItemWeaponHarisenBattleFan(TObject *parent, u8 *item) : TItemWeapon(parent, item) {
    scale.x = scale.y = scale.z = 1.0f;
}

TItem *TItemWeaponHarisenBattleFan::create(u8 *item) {
    if (item != NULL) {
        return new TItemWeaponHarisenBattleFan(tl_05, item);
    }
    return NULL;
}
