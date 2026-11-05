#include "types.h"
#include "pso/item/TUnk_804A2358.h"
#include "pso/item/TItemEquipVariant_80120CF8.h"
#include "pso/player/TObjPlayer.h"
#include "pso/item/TItem.h"
#include "pso/items/TItemWeapon.h"
#include "pso/player/TObjPlayer_8012105C.h"

extern s32 __vt__13TUnk_804A2358[];

TUnk_804A2358::~TUnk_804A2358() {}

extern "C" {

void __ct__11TItemWeaponFP7TObjectPUc(void *);


void *TObjPlayer::init_and_configure() {
    __ct__11TItemWeaponFP7TObjectPUc(this);
    *(s32 **)((s8 *)this + 0x18) = __vt__13TUnk_804A2358;
    set_weapon_trail_joints((s32)this, 2, 6, 5);
    ((TItemWeapon *)this)->set_weapon_flags(35);
    set_effect_state(13);
    return this;
}

}
