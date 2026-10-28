#include "types.h"
#include "pso/player/TUnk_804A63F0.h"
#include "pso/player/TObjPlayer.h"

extern "C" {

void __ct__11TItemWeaponFP7TObjectPUc(void *);

extern s32 technical_crozier_weapon_vtable[];

void *TUnk_804A63F0::init_vtable_804A63F0() {
    __ct__11TItemWeaponFP7TObjectPUc(this);
    *(s32 **)((s8 *)this + 0x18) = technical_crozier_weapon_vtable;
    set_weapon_flags(34);
    return this;
}

}
