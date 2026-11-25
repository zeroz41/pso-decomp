#include "types.h"
#include <stddef.h>
#include "pso/weapon/TItemWeaponAngelHarp.h"
#include "pso/weapon/shoot/TItemShootGun.h"
#include "pso/player/TObjPlayer.h"
#include "pso/system/task/TMainTask.h"

TItemWeaponAngelHarp::~TItemWeaponAngelHarp() {}

TItemWeaponAngelHarp::TItemWeaponAngelHarp(TObject *parent, u8 *item) : TItemWeapon(parent, item) {
    shot_callback = (WeaponShotCallback)TItemShootGun::create;
}

TItem *TItemWeaponAngelHarp::create(u8 *item) {
    if (item != NULL) {
        return new TItemWeaponAngelHarp(tl_05, item);
    }
    return NULL;
}
