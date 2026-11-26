#include "types.h"
#include "pso/weapon/TItemWeaponWand.h"
#include "pso/player/TObjPlayer.h"
#include "pso/weapon/TItemWeapon.h"
#include "pso/item/TItem.h"
#include "pso/system/task/TMainTask.h"
#include "pso/effect/item/TItemEffCane.h"

void TItemWeaponWand::emit_marker_effects() {
    saddr item = (saddr)this;
    if ((get_item_index() < 4U) && (((TItemWeapon *)item)->get_attack_stage() == 0)) {
        TItemEffCane::spawn_pair(tl_05, (TItem*)item, 1, 2);
    }
}

TItemWeaponWand::TItemWeaponWand(TObject *parent, u8 *item) : TItemWeapon(parent, item) {}

TItem *TItemWeaponWand::create(u8 *item) {
    if (item != NULL) {
        return new TItemWeaponWand(tl_05, item);
    }
    return NULL;
}

TItemWeaponWand::~TItemWeaponWand() {}
