#include "types.h"
#include "pso/weapon/TItemWeaponSpecialGun.h"
#include "pso/weapon/TItemWeapon.h"
#include "pso/player/TObjPlayer.h"
#include "pso/item/TItem.h"
#include "pso/effect/item/TItemEffLandHit.h"
#include "pso/system/task/TMainTask.h"

TItemWeaponSpecialGun::~TItemWeaponSpecialGun() {}

TItemWeaponSpecialGun::TItemWeaponSpecialGun(TObject *parent, u8 *item) : TItemWeapon(parent, item) {
    impact_callback = spawn_weapon_impact_effect;
}


TItem *TItemWeaponSpecialGun::create(u8 *item) {
    if (item != NULL) {
        return new TItemWeaponSpecialGun(tl_05, item);
    }
    return NULL;
}

