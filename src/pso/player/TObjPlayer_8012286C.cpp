#include "types.h"
#include "pso/items/TItemWeapon.h"
#include "pso/player/TObjPlayer.h"

extern "C" {

void __ct__11TItemWeaponFP7TObjectPUc(void *);

extern s32 lbl_804A1098[];

void *TObjPlayer::init_substate_a() {
    __ct__11TItemWeaponFP7TObjectPUc(this);
    *(s32 **)((s8 *)this + 0x18) = lbl_804A1098;
    ((TItemWeapon *)this)->set_weapon_flags(34);
    *(u32 *)&this->unk_1F8 = 0;
    this->m_1fc = 0;
    set_effect_state(10);
    return this;
}

}
