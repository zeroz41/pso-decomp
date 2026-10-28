#include "types.h"
#include "pso/items/TItemWeapon.h"
#include "pso/player/TObjPlayer.h"

extern "C" {

void __ct__11TItemWeaponFP7TObjectPUc(void *);

extern s32 lbl_804A2678[];

void *TObjPlayer::init_state_vt2678() {
    __ct__11TItemWeaponFP7TObjectPUc(this);
    *(s32 **)((s8 *)this + 0x18) = lbl_804A2678;
    ((TItemWeapon *)this)->set_weapon_flags(34);
    set_effect_state(10);
    *(u32 *)&this->unk_1F8 = -1;
    return this;
}

}
