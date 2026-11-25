#include "types.h"
#include "pso/weapon/TItemWeaponClaw.h"
#include "pso/item/TItemEquipVariant_80120CF8.h"
#include "pso/player/TObjPlayer.h"
#include "pso/item/TItem.h"
#include "pso/system/task/TMainTask.h"
#include "pso/unk/text_80120908.h"

void TItemWeaponClaw::draw_held_model() { draw_weapon_at_joint((saddr)this, (s8)49); update_trail_slot(0); update_trail_slot(1); }

TItemWeaponClaw::TItemWeaponClaw(TObject *parent, u8 *item) : TItemWeapon(parent, item) {
    set_weapon_flags(1);
}

TItem *TItemWeaponClaw::create(u8 *item) {
    if (item != NULL) {
        return new TItemWeaponClaw(tl_05, item);
    }
    return NULL;
}

TItemWeaponClaw::~TItemWeaponClaw() {}
