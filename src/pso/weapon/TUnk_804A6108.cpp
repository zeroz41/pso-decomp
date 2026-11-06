#include "types.h"
#include "pso/weapon/TUnk_804A6108.h"
#include "pso/item/TItem.h"
#include "pso/item/TItemMenuCtrl_80115AF0.h"
#include "pso/player/TObjPlayer.h"
#include "pso/system/MatrixOps.h"
#include "pso/system/task/TMainTask.h"

void TUnk_804A6108::vfunc_60() {
    switch (TObjPlayer::get_player_list()) {
    case 1:
        TItem::begin_effect_render();
        rotate_matrix_z(NULL, rotation_z);
        return;
    case 2:
        TItem::begin_effect_render();
        rotate_matrix_z(NULL, -rotation_z);
        return;
    case 3:
        TItem::begin_effect_render();
        return;
    }
}

void TUnk_804A6108::update_weapon() { advance_angle_wrap(&rotation_z, 3276); }

TUnk_804A6108::TUnk_804A6108(TObject *parent, u8 *item) : TItemWeapon(parent, item) {
    rotation_z = 0;
}

extern "C" {
u8 *TObjPlayer__sub_8012EFAC(u8 *item) {
    if (item != NULL) {
        return (u8 *)new TUnk_804A6108(tl_05, item);
    }
    return NULL;
}
}

TUnk_804A6108::~TUnk_804A6108() {}
