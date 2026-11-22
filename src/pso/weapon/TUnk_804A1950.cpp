#include "types.h"
#include "pso/weapon/TUnk_804A1950.h"
#include "pso/item/TItemEquipVariant_80120CF8.h"
#include "pso/player/TObjPlayer.h"
#include "pso/item/TItem.h"
#include "pso/system/task/TMainTask.h"

void TUnk_804A1950::emit_marker_effects() {
    saddr item = (saddr)this;
    if (this->get_attack_stage() == 0) {
        ((TObjPlayer *)tl_05)->spawn_cane_effect((TItem*)item, 1);
    }
}

TUnk_804A1950::~TUnk_804A1950() {}

TUnk_804A1950::TUnk_804A1950(TObject *parent, u8 *item) : TItemWeapon(parent, item) {}

TItem *TObjPlayer::create_set_vtable_state(u8 *item) {
    if (item != NULL) {
        return new TUnk_804A1950(tl_05, item);
    }
    return NULL;
}
