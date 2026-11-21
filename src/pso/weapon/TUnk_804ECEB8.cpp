#include "types.h"
#include <stddef.h>
#include "pso/weapon/TUnk_804ECEB8.h"
#include "pso/weapon/shoot/TItemShootGun.h"
#include "pso/player/TObjPlayer.h"
#include "pso/system/task/TMainTask.h"

TUnk_804ECEB8::~TUnk_804ECEB8() {}

TUnk_804ECEB8::TUnk_804ECEB8(TObject *parent, u8 *item) : TItemWeapon(parent, item) {
    shot_callback = (WeaponShotCallback)TItemShootGun::create;
}

TItem *TObjPlayer::create_vtable_variant(u8 *item) {
    if (item != NULL) {
        return new TUnk_804ECEB8(tl_05, item);
    }
    return NULL;
}
