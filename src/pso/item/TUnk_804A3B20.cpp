#include "types.h"
#include "pso/items/TItemWeapon.h"
#include "pso/player/TUnk_804A3B20.h"
#include "pso/player/TObjPlayer.h"
#include "pso/unk/text_80128440.h"
#include "pso/item/TItem.h"
#include "pso/TMainTask.h"

void TUnk_804A3B20::vfunc_62() {
    if (get_attack_stage() == 0) {
        ((TObjPlayer *)tl_05)->spawn_cane_effects(this, 1, 2);
    }
}

TUnk_804A3B20::TUnk_804A3B20(TObject *parent, u8 *item) : TUnk_804A4948(parent, item) {}

extern "C" {
u8 *TObjPlayer__sub_80128440(u8 *arg0) {
    if (arg0 != NULL) {
        return (u8 *)new TUnk_804A3B20(tl_05, arg0);
    }
    return NULL;
}

}

TUnk_804A3B20::~TUnk_804A3B20() {}
