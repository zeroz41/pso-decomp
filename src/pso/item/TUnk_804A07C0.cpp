#include "types.h"
#include "pso/item/TUnk_804A07C0.h"
#include "pso/item/TItemEquipVariant_80120CF8.h"
#include "pso/player/TObjPlayer.h"
#include "pso/item/TItem.h"

extern s32 __vt__13TUnk_804A07C0[];

TUnk_804A07C0::~TUnk_804A07C0() {}

extern "C" {

void __ct__11TItemWeaponFP7TObjectPUc(void *);

extern s32 spawn_weapon_impact_effect[];

void *TUnk_804A07C0::init_vtable() {
    __ct__11TItemWeaponFP7TObjectPUc(this);
    *(s32 **)((s8 *)this + 0x18) = __vt__13TUnk_804A07C0;
    (*(s32 * *)((u8 *)this + 0x1EC)) = spawn_weapon_impact_effect;
    return this;
}

}
