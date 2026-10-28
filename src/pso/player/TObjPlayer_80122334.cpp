#include "types.h"
#include "pso/items/TItemWeapon.h"
#include "pso/player/TObjPlayer_80122334.h"
#include "pso/player/TObjPlayer.h"

extern "C" {

void __ct__11TItemWeaponFP7TObjectPUc(void *);

extern s32 lbl_804A0EA8[];
extern s32 spawn_weapon_impact_effect[];

void *guld_milla_ct(void *player) {
    __ct__11TItemWeaponFP7TObjectPUc(player);
    *(s32 **)((s8 *)player + 0x18) = lbl_804A0EA8;
    ((TItemWeapon *)player)->set_weapon_flags(515);
    *(s32 **)((s8 *)player + 0x1EC) = spawn_weapon_impact_effect;
    return player;
}

}
