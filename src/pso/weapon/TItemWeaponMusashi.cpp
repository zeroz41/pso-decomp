#include "types.h"
#include "pso/weapon/TItemWeaponMusashi.h"
#include "pso/system/task/TMainTask.h"

void TItemWeaponMusashi::draw_held_model() {
    NJS_OBJECT *second;
    NJS_OBJECT *model;

    draw_weapon_at_joint(0x30);
    update_trail_slot(0);
    second = second_model;
    model = item_model;
    if (second != NULL) {
        item_model = second;
    }
    draw_weapon_at_joint(0x23);
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
