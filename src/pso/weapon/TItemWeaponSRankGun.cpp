#include "types.h"
#include "pso/weapon/TItemWeaponSRankGun.h"
#include "pso/player/TObjPlayer.h"
#include "pso/effect/item/TItemEffLandHit.h"
#include "pso/item/TItem.h"
#include "pso/system/task/TMainTask.h"

TItemWeaponSRankGun::TItemWeaponSRankGun(TObject *parent, u8 *item) : TItemWeaponSRank(parent, item) {
    impact_callback = (WeaponHitCallback)spawn_weapon_impact_effect;
}

TItem *TItemWeaponSRankGun::create(u8 *item) {
    if (item != NULL) {
        return new TItemWeaponSRankGun(tl_05, item);
    }
    return NULL;
}

TItemWeaponSRankGun::~TItemWeaponSRankGun() {}
