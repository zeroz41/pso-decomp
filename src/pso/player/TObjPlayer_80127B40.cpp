#include "types.h"
#include "pso/item/TUnk_804A3548.h"
#include "pso/player/TObjPlayer.h"

extern "C" {

void __ct__11TItemWeaponFP7TObjectPUc(void *);

extern s32 lbl_804A3548[];

void *TUnk_804A3548::init_vtable_804A3548() {
    __ct__11TItemWeaponFP7TObjectPUc(this);
    *(s32 **)((s8 *)this + 0x18) = lbl_804A3548;
    set_weapon_flags(34);
    return this;
}

}
