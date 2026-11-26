#include "types.h"
#include "pso/weapon/TItemWeaponSRankHarisen.h"
#include "pso/player/TObjPlayer.h"
#include "pso/system/MatrixStack.h"
#include "pso/system/task/TMainTask.h"

void TItemWeaponSRankHarisen::transform_model_node() {
    if (get_model_node_counter() == 1) {
        scale_current_matrix(&scale.x);
    }
}

void TItemWeaponSRankHarisen::start_attack_effect() { scale.y = 0.1f; }

void TItemWeaponSRankHarisen::update_weapon() {
    if (scale.y < 1.0f) {
        scale.y += 0.1f;
        if (1.0f <= scale.y) {
            scale.y = 1.0f;
        }
    }
}

TItemWeaponSRankHarisen::~TItemWeaponSRankHarisen() {}

TItemWeaponSRankHarisen::TItemWeaponSRankHarisen(TObject *parent, u8 *item) : TItemWeaponSRank(parent, item) {
    scale.x = scale.y = scale.z = 1.0f;
}

TItem *TItemWeaponSRankHarisen::create(u8 *item) {
    if (item != NULL) {
        return new TItemWeaponSRankHarisen(tl_05, item);
    }
    return NULL;
}
