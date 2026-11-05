#include "types.h"
#include "pso/item/TUnk_804A07C0.h"
#include "pso/item/TItemEquipVariant_80120CF8.h"
#include "pso/player/TObjPlayer.h"
#include "pso/item/TItem.h"
#include "pso/player/TObjPlayer_80109344.h"

TUnk_804A07C0::~TUnk_804A07C0() {}

TUnk_804A07C0::TUnk_804A07C0(TObject *parent, u8 *item) : TItemWeapon(parent, item) {
    impact_callback = (WeaponHitCallback)spawn_weapon_impact_effect;
}
