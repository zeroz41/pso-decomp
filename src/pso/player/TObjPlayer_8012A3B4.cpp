#include "types.h"
#include "pso/items/TItemWeapon.h"
#include "pso/player/TObjPlayer_8012A3B4.h"
#include "pso/player/TObjPlayer.h"

extern "C" {

void construct_srank_weapon(void *);

extern s32 s_rank_windmill_weapon_vtable[];

void *TObjPlayer__sub_8012A3B4(void *player) {
    construct_srank_weapon(player);
    *(s32 **)((s8 *)player + 0x18) = s_rank_windmill_weapon_vtable;
    ((TItemWeapon *)player)->set_weapon_flags(35);
    *(u32 *)((s8 *)player + 0x1FC) = 0;
    *(u32 *)((s8 *)player + 0x200) = 3276;
    *(u32 *)((s8 *)player + 0x204) = 0;
    *(u32 *)((s8 *)player + 0x208) = 1;
    return player;
}

}
