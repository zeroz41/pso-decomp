#include "types.h"
#include "pso/item/TUnk_804A1950.h"
#include "pso/item/TItemEquipVariant_80120CF8.h"
#include "pso/player/TObjPlayer.h"
#include "pso/item/TItem.h"
#include "pso/TMainTask.h"

void TUnk_804A1950::emit_marker_effects() {
    s32 item = (s32)this;
    if (((TItemWeapon *)this)->get_attack_stage() == 0) {
        ((TObjPlayer *)tl_05)->spawn_cane_effect((TItem*)item, 1);
    }
}

TUnk_804A1950::~TUnk_804A1950() {}

TUnk_804A1950::TUnk_804A1950(TObject *parent, u8 *item) : TItemWeapon(parent, item) {}

u8 *TObjPlayer::create_set_vtable_state(u8 *arg0) {
    if (arg0 != NULL) {
        return (u8 *)new TUnk_804A1950(tl_05, arg0);
    }
    return NULL;
}
