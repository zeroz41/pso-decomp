#include "types.h"
#include "pso/weapon/TItemWeaponEggBlaster.h"
#include "pso/player/TObjPlayer.h"
#include "pso/weapon/shoot/TItemShoot.h"
#include "pso/system/task/TMainTask.h"
#include "pso/weapon/TItemWeapon.h"
#include "pso/item/TItem.h"

TItemWeaponEggBlaster::TItemWeaponEggBlaster(TObject *parent, u8 *item) : TItemWeapon(parent, item) {
    shot_callback = spawn_shoot_particle_9f;
    shot_speed = 11.0f;
}


TItem *TItemWeaponEggBlaster::create(u8 *item) {
    if (item != NULL) {
        return new TItemWeaponEggBlaster(tl_05, item);
    }
    return NULL;
}


TItemWeaponEggBlaster::~TItemWeaponEggBlaster() {}
