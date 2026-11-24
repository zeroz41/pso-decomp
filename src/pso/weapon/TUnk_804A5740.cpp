#include "pso/math/ClampedStep.h"
#include "types.h"
#include "pso/weapon/TUnk_804A5740.h"
#include "pso/player/TObjPlayer.h"
#include "pso/item/TItem.h"
#include "pso/system/MatrixOps.h"
#include "pso/system/task/TMainTask.h"

void TUnk_804A5740::update_idle() { ::add_angle_clamped(&rotation_x, 1820, 10922); }

void TUnk_804A5740::update_attack() { ::add_angle_clamped(&rotation_x, -1820, 0); }

void TUnk_804A5740::vfunc_60() {
    if (TObjPlayer::get_player_list() > 0) {
        rotate_matrix_x(NULL, rotation_x);
    }
}

TUnk_804A5740::TUnk_804A5740(TObject *parent, u8 *item) : TItemWeapon(parent, item) {
    rotation_x = 10922;
    set_weapon_flags(1536);
}


TItem *TObjPlayer__sub_8012CF84(u8 *item) {
    if (item != NULL) {
        return new TUnk_804A5740(tl_05, item);
    }
    return NULL;
}

TUnk_804A5740::~TUnk_804A5740() {}
