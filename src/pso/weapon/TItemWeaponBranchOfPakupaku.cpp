#include "types.h"
#include "pso/weapon/TItemWeaponBranchOfPakupaku.h"
#include "pso/weapon/TItemWeapon.h"
#include "pso/player/TObjPlayer.h"
#include "pso/item/TItem.h"
#include "pso/system/task/TMainTask.h"
#include "pso/effect/item/TItemEffCane.h"

void TItemWeaponBranchOfPakupaku::emit_marker_effects() {
    if (this->get_attack_stage() == 0) {
        TItemEffCane::spawn(tl_05, this, 1);
    }
}

TItemWeaponBranchOfPakupaku::~TItemWeaponBranchOfPakupaku() {}

TItemWeaponBranchOfPakupaku::TItemWeaponBranchOfPakupaku(TObject *parent, u8 *item) : TItemWeapon(parent, item) {}

TItem *TItemWeaponBranchOfPakupaku::create(u8 *item) {
    if (item != NULL) {
        return new TItemWeaponBranchOfPakupaku(tl_05, item);
    }
    return NULL;
}
