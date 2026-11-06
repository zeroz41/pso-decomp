#include "types.h"
#include "pso/item/TUnk_804A3E20.h"
#include "pso/player/TObjPlayer.h"
#include "pso/system/MatrixStack.h"
#include "pso/TMainTask.h"

void TUnk_804A3E20::vfunc_60() {
    if (TObjPlayer::get_player_list() == 1) {
        scale_current_matrix(&scale.x);
    }
}

void TUnk_804A3E20::vfunc_62() { scale.y = 0.1f; }

void TUnk_804A3E20::update_weapon() {
    if (scale.y < 1.0f) {
        scale.y += 0.1f;
        if (1.0f <= scale.y) {
            scale.y = 1.0f;
        }
    }
}

TUnk_804A3E20::~TUnk_804A3E20() {}

TUnk_804A3E20::TUnk_804A3E20(TObject *parent, u8 *item) : TUnk_804A4948(parent, item) {
    scale.x = scale.y = scale.z = 1.0f;
}

u8 *TObjPlayer::create_shot_state(u8 *arg0) {
    if (arg0 != NULL) {
        return (u8 *)new TUnk_804A3E20(tl_05, arg0);
    }
    return NULL;
}
