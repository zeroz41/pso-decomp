#include "types.h"
#include "pso/item/TUnk_804A2E80.h"
#include "pso/player/TObjPlayer.h"
#include "pso/system/MatrixStack.h"
#include "pso/TMainTask.h"

void TUnk_804A2E80::vfunc_60() {
    if (TObjPlayer::get_player_list() == 1) {
        scale_current_matrix(&scale.x);
    }
}

void TUnk_804A2E80::emit_marker_effects() { scale.y = 0.1f; }

void TUnk_804A2E80::update_weapon() {
    if (scale.y < 1.0f) {
        scale.y += 0.1f;
        if (1.0f <= scale.y) {
            scale.y = 1.0f;
        }
    }
}

TUnk_804A2E80::~TUnk_804A2E80() {}

TUnk_804A2E80::TUnk_804A2E80(TObject *parent, u8 *item) : TItemWeapon(parent, item) {
    scale.x = scale.y = scale.z = 1.0f;
}

u8 *TObjPlayer::create_shot_effect_state(s32 arg0) {
    if (arg0 != 0) {
        return (u8 *)new TUnk_804A2E80(tl_05, (u8 *)arg0);
    }
    return NULL;
}
