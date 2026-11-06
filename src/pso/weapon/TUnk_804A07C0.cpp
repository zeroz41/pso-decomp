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

extern "C" {
u8 *TObjPlayer__sub_80121318(u8 *arg0) {
    if (arg0 != NULL) {
        return (u8 *)new TUnk_804A07C0(tl_05, arg0);
    }
    return NULL;
}

}
