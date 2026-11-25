#include "types.h"
#include <stddef.h>
#include "pso/weapon/TItemWeaponMorningGlory.h"
#include "pso/item/TItemEquipBase.h"
#include "pso/weapon/TItemWeapon.h"
#include "pso/unk/text_80120908.h"
#include "pso/system/task/TMainTask.h"

void TItemWeaponMorningGlory::update_weapon() {
    refresh_owner_stats();
}

void TItemWeaponMorningGlory::draw_held_model() {
    draw_weapon_at_joint((saddr)this, 0x30);
    update_trail_slot(0);
    update_trail_slot(1);
    update_trail_slot(2);
}

TItemWeaponMorningGlory::TItemWeaponMorningGlory(TObject *parent, u8 *item) : TItemWeapon(parent, item) {
    set_weapon_trail_joints(this, 2, 6, 5);
    set_weapon_flags(1);
}

TItem *create_morning_glory(u8 *item) {
    if (item != NULL) {
        return new TItemWeaponMorningGlory(tl_05, item);
    }
    return NULL;
}
