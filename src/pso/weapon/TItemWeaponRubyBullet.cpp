#include "types.h"
#include "pso/item/TItemEquipVariant_80120CF8.h"
#include "pso/weapon/TItemWeaponRubyBullet.h"
#include "pso/player/TObjPlayer.h"
#include "pso/item/TItem.h"
#include "pso/weapon/TItemWeapon.h"
#include "pso/system/task/TMainTask.h"

TItemWeaponRubyBullet::~TItemWeaponRubyBullet() {}

TItemWeaponRubyBullet::TItemWeaponRubyBullet(TObject *parent, u8 *item) : TItemWeapon(parent, item) {
    set_weapon_flags(0x8000);
}

TItem *TItemWeaponRubyBullet::create(u8 *item) {
    if (item != NULL) {
        return new TItemWeaponRubyBullet(tl_05, item);
    }
    return NULL;
}
