#include "types.h"
#include "pso/weapon/TUnk_804A1478.h"
#include "pso/item/TItemEquipVariant_80120CF8.h"
#include "pso/player/TObjPlayer.h"
#include "pso/weapon/TItemWeapon.h"
#include "pso/item/TItem.h"
#include "pso/system/task/TMainTask.h"

void TUnk_804A1478::emit_marker_effects() {
    s32 item = (s32)this;
    if ((get_item_index() < 4U) && (((TItemWeapon *)item)->get_attack_stage() == 0)) {
        ((TObjPlayer *)tl_05)->spawn_cane_effects((TItem*)item, 1, 2);
    }
}

TUnk_804A1478::TUnk_804A1478(TObject *parent, u8 *item) : TItemWeapon(parent, item) {}

u8 *create_wand_weapon(u8 *arg0) {
    if (arg0 != NULL) {
        return (u8 *)new TUnk_804A1478(tl_05, arg0);
    }
    return NULL;
}

TUnk_804A1478::~TUnk_804A1478() {}
