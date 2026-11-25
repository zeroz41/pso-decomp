#include "types.h"
#include "pso/weapon/TItemWeaponRod.h"
#include "pso/player/TObjPlayer.h"
#include "pso/weapon/TItemWeapon.h"
#include "pso/system/task/TMainTask.h"

TItemWeaponRod::~TItemWeaponRod() {}

TItemWeaponRod::TItemWeaponRod(TObject *parent, u8 *item) : TItemWeapon(parent, item) {
    switch (item[2]) {
    case 5:
    case 6:
        set_weapon_trail_joints(this, 0, 3, 2);
        break;
    case 4:
        set_weapon_trail_joints(this, 0, 2, 1);
        break;
    default:
        set_weapon_trail_joints(this, 0, 2, 3);
        break;
    }
    if (item[2] >= 4U) {
        set_color_node(-1);
    }
}

TItem *TItemWeaponRod::create(u8 *item) {
    if (item != NULL) {
        return new TItemWeaponRod(tl_05, item);
    }
    return NULL;
}
