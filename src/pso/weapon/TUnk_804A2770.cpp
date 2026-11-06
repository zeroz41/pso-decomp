#include "types.h"
#include "pso/weapon/TUnk_804A2770.h"
#include "pso/player/TObjPlayer.h"
#include "pso/item/TItem.h"
#include "pso/weapon/TUnk_804A2868.h"
#include "pso/weapon/TItemWeapon.h"
#include "pso/effect/item/TItemEffFlame.h"
#include "pso/item/armor/TItemProShield.h"
#include "pso/system/task/TMainTask.h"

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
