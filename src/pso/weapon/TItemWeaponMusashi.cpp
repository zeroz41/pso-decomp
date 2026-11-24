#include "types.h"
#include "pso/weapon/TItemWeaponMusashi.h"
#include "pso/system/task/TMainTask.h"
#include "pso/unk/text_80120908.h"

void TItemWeaponMusashi::reserved_53() {
    NJS_OBJECT *second;
    NJS_OBJECT *model;
    saddr weapon = (saddr)this;

    draw_weapon_at_joint(weapon, 0x30);
    update_trail_slot(0);
    second = second_model;
    model = item_model;
    if (second != NULL) {
        item_model = second;
    }
    draw_weapon_at_joint(weapon, 0x23);
    update_trail_slot(1);
    item_model = model;
}

TItemWeaponMusashi::TItemWeaponMusashi(TObject *parent, u8 *item) : TItemWeapon(parent, item) {
    set_weapon_flags(513);
}

TItem *TItemWeaponMusashi::create(u8 *item) {
    if (item != NULL) {
        return new TItemWeaponMusashi(tl_05, item);
    }
    return NULL;
}

TItemWeaponMusashi::~TItemWeaponMusashi() {}
