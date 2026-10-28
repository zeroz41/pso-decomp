#include "types.h"
#include "pso/items/TItemWeapon.h"
#include "pso/player/TObjPlayer_8012B0F8.h"
#include "pso/player/TObjPlayer.h"

extern "C" {

void __ct__11TItemWeaponFP7TObjectPUc(void *);

extern s32 p_arms_blade_weapon_vtable[];

void *TObjPlayer__sub_8012B0F8(void *player) {
    __ct__11TItemWeaponFP7TObjectPUc(player);
    *(s32 **)((s8 *)player + 0x18) = p_arms_blade_weapon_vtable;
    ((TItemWeapon *)player)->set_weapon_flags(513);
    return player;
}

}
