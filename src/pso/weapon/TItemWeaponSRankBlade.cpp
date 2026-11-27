#include "types.h"
#include "pso/weapon/TItemWeaponSRankBlade.h"
#include "pso/player/TObjPlayer.h"
#include "pso/item/TItem.h"
#include "pso/system/task/TMainTask.h"

TItemWeaponSRankBlade::TItemWeaponSRankBlade(TObject *parent, u8 *item) : TItemWeaponSRank(parent, item) {
    set_weapon_flags(1536);
}


TItem *TItemWeaponSRankBlade::create(u8 *item) {
    if (item != NULL) {
        return new TItemWeaponSRankBlade(tl_05, item);
    }
    return NULL;
}


TItemWeaponSRankBlade::~TItemWeaponSRankBlade() {}

void TItemWeaponSRank::start_attack_effect() {}
