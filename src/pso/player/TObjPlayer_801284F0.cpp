#include "types.h"
#include "pso/player/TObjPlayer_801284F0.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TUnk_804A3C20.h"

extern "C" {

void draw_weapon_at_joint(s32 arg0, s8 arg1);
void construct_srank_weapon(void *);

void TUnk_804A3C20::reserved_53() { draw_weapon_at_joint((s32)this, (s8)((void*)49)); ((TItemWeapon *)this)->update_trail_slot(0); ((TItemWeapon *)this)->update_trail_slot(1); }

extern s32 lbl_804A3C20[];

void *TObjPlayer__sub_80128538(void *player) {
    construct_srank_weapon(player);
    *(s32 **)((s8 *)player + 0x18) = lbl_804A3C20;
    ((TItemWeapon *)player)->set_weapon_flags(1);
    return player;
}

}
