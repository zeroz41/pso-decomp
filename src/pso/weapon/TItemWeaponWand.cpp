#include "types.h"
#include "pso/weapon/TUnk_804A1478.h"
#include "pso/item/TItemEquipVariant_80120CF8.h"
#include "pso/player/TObjPlayer.h"
#include "pso/weapon/TItemWeapon.h"
#include "pso/item/TItem.h"
#include "pso/system/task/TMainTask.h"
#include "pso/effect/item/TItemEffCane.h"

void TUnk_804A1478::emit_marker_effects() {
    saddr item = (saddr)this;
    if ((get_item_index() < 4U) && (((TItemWeapon *)item)->get_attack_stage() == 0)) {
        TItemEffCane::spawn_pair(tl_05, (TItem*)item, 1, 2);
    }
}

TUnk_804A1478::TUnk_804A1478(TObject *parent, u8 *item) : TItemWeapon(parent, item) {}

TItem *create_wand_weapon(u8 *item) {
    if (item != NULL) {
        return new TUnk_804A1478(tl_05, item);
    }
    return NULL;
}

TUnk_804A1478::~TUnk_804A1478() {}
