#include "types.h"
#include "pso/weapon/TItemWeaponHeartOfPoumn.h"
#include "pso/item/TItemEquipVariant_80120CF8.h"
#include "pso/player/TObjPlayer.h"
#include "pso/item/TItem.h"
#include "pso/weapon/TItemWeapon.h"
#include "pso/weapon/TItemWeaponMonkeyKingBar.h"
#include "pso/system/task/TMainTask.h"

extern "C" {
s32 draw_weapon_at_joint(void *, int);
}


void TItemWeaponHeartOfPoumn::draw_held_model() {
    NJS_OBJECT *saved_model;
    draw_weapon_at_joint(this, 0x31);
    update_trail_slot(0);
    update_trail_slot(1);
    saved_model = item_model;
    item_model = second_model;
    draw_weapon_at_joint(this, 0x24);
    item_model = saved_model;
    update_trail_slot(2);
    update_trail_slot(3);
}

TItemWeaponHeartOfPoumn::~TItemWeaponHeartOfPoumn() {}

TItemWeaponHeartOfPoumn::TItemWeaponHeartOfPoumn(TObject *parent, u8 *item) : TItemWeapon(parent, item) {
    set_weapon_trail_joints(this, 2, 1, 2);
    set_weapon_trail_joints(this, 3, 3, 4);
    set_weapon_flags(513);
}

TItem *TItemWeaponHeartOfPoumn::create(u8 *item) {
    if (item != NULL) {
        return new TItemWeaponHeartOfPoumn(tl_05, item);
    }
    return NULL;
}
