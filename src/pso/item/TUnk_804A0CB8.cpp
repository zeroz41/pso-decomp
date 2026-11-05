#include "types.h"
#include "pso/item/TUnk_804A0CB8.h"
#include "pso/item/TItemEquipVariant_80120CF8.h"
#include "pso/player/TObjPlayer.h"
#include "pso/item/TItem.h"
#include "pso/items/TItemWeapon.h"
#include "pso/system/FlagWord.h"

extern s32 __vt__13TUnk_804A0CB8[];

TUnk_804A0CB8::~TUnk_804A0CB8() {}

extern "C" {

void __ct__11TItemWeaponFP7TObjectPUc(void *);

extern const f32 lbl_805DACD4;

void *belra_cannon_ct(void *player) {
    __ct__11TItemWeaponFP7TObjectPUc(player);
    *(s32 **)((s8 *)player + 0x18) = __vt__13TUnk_804A0CB8;
    ((FlagWord *)((char *)player + 376))->set(32);
    *(f32 *)((s8 *)player + 0x1E4) = lbl_805DACD4;
    ((TItemWeapon *)player)->set_weapon_flags(2);
    *(u32 *)((s8 *)player + 0x1F8) = 1;
    return player;
}

}
