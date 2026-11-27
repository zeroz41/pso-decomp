#include "types.h"
#include "pso/weapon/TItemWeaponWand.h"
#include "pso/player/TObjPlayer.h"
#include "pso/weapon/TItemWeapon.h"
#include "pso/item/TItem.h"
#include "pso/system/task/TMainTask.h"
#include "pso/effect/item/TItemEffCane.h"

void TItemWeaponWand::emit_marker_effects() {
    if ((get_item_index() < 4U) && (get_attack_stage() == 0)) {
        TItemEffCane::spawn_pair(tl_05, this, 1, 2);
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
