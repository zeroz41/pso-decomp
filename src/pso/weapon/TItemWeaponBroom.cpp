#include "types.h"
#include "pso/weapon/TItemWeaponBroom.h"
#include "pso/weapon/TItemWeapon.h"
#include "pso/player/TObjPlayer.h"
#include "pso/item/TItem.h"
#include "pso/system/task/TMainTask.h"
#include "pso/effect/item/TItemEffCane.h"

void TItemWeaponBroom::emit_marker_effects() {
    saddr item = (saddr)this;
    if (this->get_attack_stage() == 0) {
        TItemEffCane::spawn(tl_05, (TItem*)item, 1);
    }
}

TItemWeaponBroom::~TItemWeaponBroom() {}
TItemWeaponBroom::TItemWeaponBroom(TObject *parent, u8 *item) : TItemWeapon(parent, item) {}

TItem *TItemWeaponBroom::create(u8 *item) {
    if (item != NULL) {
        return new TItemWeaponBroom(tl_05, item);
    }
    return NULL;
}
