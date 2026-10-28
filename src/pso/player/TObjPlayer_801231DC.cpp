#include "types.h"
#include "pso/items/TItemWeapon.h"
#include "pso/player/TObjPlayer_801231DC.h"
#include "pso/player/TObjPlayer.h"

extern "C" {

void __ct__11TItemWeaponFP7TObjectPUc(void *);

extern s32 lbl_804A1760[];

void *construct_twin_chakram(void *player) {
    __ct__11TItemWeaponFP7TObjectPUc(player);
    *(s32 **)((s8 *)player + 0x18) = lbl_804A1760;
    ((TItemWeapon *)player)->set_weapon_flags(1536);
    return player;
}

}
