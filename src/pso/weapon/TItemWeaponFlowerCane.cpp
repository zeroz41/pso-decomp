#include "types.h"
#include "pso/weapon/TItemWeaponFlowerCane.h"
#include "pso/player/TObjPlayer.h"
#include "pso/item/TItem.h"
#include "pso/weapon/TItemWeaponFlameVisit.h"
#include "pso/weapon/TItemWeapon.h"
#include "pso/effect/item/TItemEffFlame.h"
#include "pso/item/armor/TItemProShield.h"
#include "pso/system/task/TMainTask.h"
#include "pso/effect/item/TItemEffCane.h"

void TItemWeaponFlowerCane::emit_marker_effects() {
    if (get_attack_stage() == 0) {
        TItemEffCane::spawn(tl_05, this, 1);
    }
}

TItemWeaponFlowerCane::~TItemWeaponFlowerCane() {}

TItemWeaponFlowerCane::TItemWeaponFlowerCane(TObject *parent, u8 *item) : TItemWeapon(parent, item) {}

TItem *TItemWeaponFlowerCane::create(u8 *item) {
    if (item != NULL) {
        return new TItemWeaponFlowerCane(tl_05, item);
    }
    return NULL;
}
