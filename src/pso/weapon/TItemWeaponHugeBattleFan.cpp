#include "types.h"
#include "pso/weapon/TItemWeaponHugeBattleFan.h"
#include "pso/player/TObjPlayer.h"
#include "pso/item/TItem.h"
#include "pso/system/MatrixStack.h"
#include "pso/system/task/TMainTask.h"


void belra_cannon_return_timer(void *arg0) {
    if (arg0 != NULL) {
        *(s32 *)((s8 *)arg0 + 0x1F8) = 1;
    }
}

void TItemWeaponHugeBattleFan::transform_model_node() {
    if (TObjPlayer::get_player_list() == 1) {
        scale_current_matrix(&scale.x);
    }
}

void TItemWeaponHugeBattleFan::emit_marker_effects() { scale.y = 0.1f; }

void TItemWeaponHugeBattleFan::update_weapon() {
    f32 y;

    y = scale.y;
    if (y < 1.0f) {
        scale.y += 0.1f;
        if (1.0f <= scale.y) {
            scale.y = 1.0f;
        }
    }
}

TItemWeaponHugeBattleFan::~TItemWeaponHugeBattleFan() {}

TItemWeaponHugeBattleFan::TItemWeaponHugeBattleFan(TObject *parent, u8 *item) : TItemWeapon(parent, item) {
    scale.x = scale.y = scale.z = 1.0f;
}

TItem *TObjPlayer::create_state_vector_state(u8 *item) {
    if (item != NULL) {
        return new TItemWeaponHugeBattleFan(tl_05, item);
    }
    return NULL;
}
