#include "types.h"
#include "pso/weapon/TUnk_804A3928.h"
#include "pso/player/TObjPlayer.h"
#include "pso/item/TItemEquipVariant_80120CF8.h"
#include "pso/system/MatrixStack.h"
#include "pso/system/task/TMainTask.h"
#include "pso/item/TItem.h"

void TUnk_804A3928::update_idle() {
    if (0.08f < scale.z) {
        scale.z -= 0.3f;
        if (scale.z < 0.08f) {
            scale.z = 0.08f;
        }
    }
}

void TUnk_804A3928::update_attack() {
    if (scale.z < 1.0f) {
        scale.z += 0.3f;
        if (1.0f < scale.z) {
            scale.z = 1.0f;
        }
    }
}

void TUnk_804A3928::vfunc_60() {
    if (TObjPlayer::get_player_list() == 0) {
        scale_current_matrix(&scale.x);
    }
}

TUnk_804A3928::~TUnk_804A3928() {}

TUnk_804A3928::TUnk_804A3928(TObject *parent, u8 *item) : TItemWeapon(parent, item) {
    scale.x = scale.y = scale.z = 1.0f;
}

u8 *TObjPlayer::create_shot_params_state(s32 item) {
    if (item != 0) {
        return (u8 *)new TUnk_804A3928(tl_05, (u8 *)item);
    }
    return NULL;
}
