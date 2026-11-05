#include "types.h"
#include "pso/item/TUnk_804A0BC0.h"
#include "pso/items/TItemWeapon.h"
#include "pso/player/TObjPlayer.h"

TUnk_804A0BC0::~TUnk_804A0BC0() {

}

extern "C" {

void __ct__11TItemWeaponFP7TObjectPUc(void *);

extern s32 __vt__13TUnk_804A0BC0[];

void *TObjPlayer::enter_state_804A0BC0() {
    __ct__11TItemWeaponFP7TObjectPUc(this);
    *(s32 **)((s8 *)this + 0x18) = __vt__13TUnk_804A0BC0;
    ((TItemWeapon *)this)->set_weapon_flags(34);
    *(u32 *)&this->unk_1F8 = 0;
    this->m_1fc = 0;
    set_effect_state(10);
    return this;
}

}
