#include "types.h"
#include "pso/player/TUnk_804A3358.h"
#include "pso/player/TObjPlayer.h"

extern "C" {

void __ct__11TItemWeaponFP7TObjectPUc(void *);

extern s32 lbl_804A3358[];

void *TUnk_804A3358::init_variant_34() {
    __ct__11TItemWeaponFP7TObjectPUc(this);
    *(s32 **)((s8 *)this + 0x18) = lbl_804A3358;
    set_weapon_flags(34);
    return this;
}

}
