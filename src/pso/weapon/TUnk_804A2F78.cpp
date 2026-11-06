#include "types.h"
#include "pso/weapon/TUnk_804A2F78.h"
#include "pso/player/TObjPlayer.h"
#include "pso/effect/item/TItemEffOrgaFlowShot.h"
#include "pso/item/TItem.h"
#include "pso/system/MatrixStack.h"
#include "pso/system/task/TMainTask.h"

void TUnk_804A2F78::vfunc_60() {
    if (TObjPlayer::get_player_list() == 2) {
        scale_current_matrix(&scale.x);
    }
}

void TUnk_804A2F78::update_idle() {
    TItemEffOrgaFlowShot::approach_value(&scale.z, -0.6f, 1.0f);
}

void TUnk_804A2F78::update_attack() {
    TItemEffOrgaFlowShot::approach_value(&scale.z, 0.6f, 4.0f);
}

void TUnk_804A2F78::vfunc_57() {}

TUnk_804A2F78::~TUnk_804A2F78() {}

TUnk_804A2F78::TUnk_804A2F78(TObject *parent, u8 *item) : TItemWeapon(parent, item) {
    scale.x = scale.y = scale.z = 1.0f;
}

u8 *TObjPlayer::create_effect_state(s32 item) {
    if (item != 0) {
        return (u8 *)new TUnk_804A2F78(tl_05, (u8 *)item);
    }
    return NULL;
}
