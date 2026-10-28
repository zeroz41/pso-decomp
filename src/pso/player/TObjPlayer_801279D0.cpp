#include "types.h"
#include "pso/items/TItemWeapon.h"
#include "pso/player/TObjPlayer.h"

extern "C" {

void __ct__11TItemWeaponFP7TObjectPUc(void *);

extern s32 lbl_804A3450[];

void *TObjPlayer::init_substate_b() {
    __ct__11TItemWeaponFP7TObjectPUc(this);
    *(s32 **)((s8 *)this + 0x18) = lbl_804A3450;
    ((TItemWeapon *)this)->set_weapon_flags(34);
    set_effect_state(2);
    return this;
}

}
