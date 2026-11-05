#include "types.h"
#include "pso/item/TUnk_804A0EA8.h"
#include "pso/item/TItemEquipVariant_80120CF8.h"
#include "pso/player/TObjPlayer.h"
#include "pso/item/TItem.h"
#include "pso/items/TItemWeapon.h"

extern s32 __vt__13TUnk_804A0EA8[];

TUnk_804A0EA8::~TUnk_804A0EA8() {}

extern "C" {

void __ct__11TItemWeaponFP7TObjectPUc(void *);

extern s32 spawn_weapon_impact_effect[];

void *guld_milla_ct(void *player) {
    __ct__11TItemWeaponFP7TObjectPUc(player);
    *(s32 **)((s8 *)player + 0x18) = __vt__13TUnk_804A0EA8;
    ((TItemWeapon *)player)->set_weapon_flags(515);
    *(s32 **)((s8 *)player + 0x1EC) = spawn_weapon_impact_effect;
    return player;
}

}
