#include "types.h"
#include "pso/items/TItemWeapon.h"
#include "pso/player/TObjPlayer_8012AE00.h"
#include "pso/player/TObjPlayer.h"

extern "C" {

void __ct__11TItemWeaponFP7TObjectPUc(void *);
void TObjPlayer__sub_8012AF00(void *);

extern s32 heaven_punisher_weapon_vtable[];

void *heaven_punisher_ct(void *player) {
    __ct__11TItemWeaponFP7TObjectPUc(player);
    *(s32 **)((s8 *)player + 0x18) = heaven_punisher_weapon_vtable;
    TObjPlayer__sub_8012AF00((void *)((char *)player + 504));
    ((TItemWeapon *)player)->set_weapon_flags(34);
    return player;
}

}
