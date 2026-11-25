#include "types.h"
#include "pso/weapon/TItemWeapon.h"
#include "pso/weapon/TItemWeaponSRankWand.h"
#include "pso/player/TObjPlayer.h"
#include "pso/unk/text_80128440.h"
#include "pso/item/TItem.h"
#include "pso/system/task/TMainTask.h"
#include "pso/effect/item/TItemEffCane.h"

void TItemWeaponSRankWand::vfunc_62() {
    if (get_attack_stage() == 0) {
        TItemEffCane::spawn_pair(tl_05, this, 1, 2);
    }
}

TItemWeaponSRankWand::TItemWeaponSRankWand(TObject *parent, u8 *item) : TUnk_804A4948(parent, item) {}


TItem *TObjPlayer__sub_80128440(u8 *item) {
    if (item != NULL) {
        return new TItemWeaponSRankWand(tl_05, item);
    }
    return NULL;
}


TItemWeaponSRankWand::~TItemWeaponSRankWand() {}
