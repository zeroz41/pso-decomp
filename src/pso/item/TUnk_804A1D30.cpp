#include "types.h"
#include "pso/item/TUnk_804A1D30.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TObjPlayer_8012105C.h"
#include "pso/item/TItem.h"
#include "pso/system/MatrixStack.h"
#include "pso/TMainTask.h"

void TUnk_804A1D30::update_idle() {
    if (0.3f < scale.z) {
        scale.z -= 0.2f;
        if (scale.z < 0.3f) {
            scale.z = 0.3f;
        }
    }
}

void TUnk_804A1D30::update_attack() {
    if (scale.z < 1.0f) {
        scale.z += 0.2f;
        if (1.0f < scale.z) {
            scale.z = 1.0f;
        }
    }
}

void TUnk_804A1D30::vfunc_60() {
    if (TObjPlayer::get_player_list() == 0) {
        scale_current_matrix(&scale.x);
    }
}

TUnk_804A1D30::~TUnk_804A1D30() {}

TUnk_804A1D30::TUnk_804A1D30(TObject *parent, u8 *item) : TItemWeapon(parent, item) {
    set_weapon_trail_joints((s32)this, 0, 3, 2);
    set_weapon_trail_joints((s32)this, 1, 4, 5);
    scale.x = scale.y = scale.z = 1.0f;
}

u8 *TObjPlayer::create_state(s32 item) {
    if (item != 0) {
        return (u8 *)new TUnk_804A1D30(tl_05, (u8 *)item);
    }
    return NULL;
}
