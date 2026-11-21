#include "types.h"
#include "pso/weapon/TUnk_804A3A20.h"
#include "pso/player/TObjPlayer.h"
#include "pso/unk/text_80128308.h"
#include "pso/item/TItem.h"
#include "pso/system/task/TMainTask.h"

TUnk_804A3A20::TUnk_804A3A20(TObject *parent, u8 *item) : TUnk_804A4948(parent, item) {
    set_weapon_flags(1536);
}


TItem *TObjPlayer__sub_80128308(u8 *item) {
    if (item != NULL) {
        return new TUnk_804A3A20(tl_05, item);
    }
    return NULL;
}


TUnk_804A3A20::~TUnk_804A3A20() {}

void TUnk_804A4948::vfunc_62() {}
