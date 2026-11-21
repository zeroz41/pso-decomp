#include "types.h"
#include "pso/weapon/TUnk_804A07C0.h"
#include "pso/item/TItemEquipVariant_80120CF8.h"
#include "pso/player/TObjPlayer.h"
#include "pso/item/TItem.h"
#include "pso/player/TObjPlayer_80109344.h"
#include "pso/system/task/TMainTask.h"

TUnk_804A07C0::~TUnk_804A07C0() {}

TUnk_804A07C0::TUnk_804A07C0(TObject *parent, u8 *item) : TItemWeapon(parent, item) {
    impact_callback = (WeaponHitCallback)spawn_weapon_impact_effect;
}


TItem *TObjPlayer__sub_80121318(u8 *item) {
    if (item != NULL) {
        return new TUnk_804A07C0(tl_05, item);
    }
    return NULL;
}

