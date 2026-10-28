#include "types.h"
#include "pso/player/TUnk_804A3A20.h"
#include "pso/player/TObjPlayer.h"

extern "C" {

void construct_srank_weapon(void *);

extern s32 lbl_804A3A20[];

void *TUnk_804A3A20::init_mode() {
    construct_srank_weapon(this);
    *(s32 **)((s8 *)this + 0x18) = lbl_804A3A20;
    ((TItemWeapon *)this)->set_weapon_flags(1536);
    return this;
}

}
