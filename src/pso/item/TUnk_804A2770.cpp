#include "types.h"
#include "pso/item/TUnk_804A2770.h"
#include "pso/player/TObjPlayer.h"
#include "pso/item/TItem.h"
#include "pso/item/TUnk_804A2868.h"
#include "pso/items/TItemWeapon.h"
#include "pso/item/TItemEffFlame.h"
#include "pso/item/TItemProShield.h"
#include "pso/TMainTask.h"

void TUnk_804A2770::emit_marker_effects() {
    if (get_attack_stage() == 0) {
        ((TObjPlayer *)tl_05)->spawn_cane_effect(this, 1);
    }
}

TUnk_804A2770::~TUnk_804A2770() {}

TUnk_804A2770::TUnk_804A2770(TObject *parent, u8 *item) : TItemWeapon(parent, item) {}

u8 *TObjPlayer::create_obj_80125F60(u8 *item) {
    if (item != NULL) {
        return (u8 *)new TUnk_804A2770(tl_05, item);
    }
    return NULL;
}
