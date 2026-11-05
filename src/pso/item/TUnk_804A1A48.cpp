#include "types.h"
#include "pso/item/TUnk_804A1A48.h"
#include "pso/item/TItemEquipVariant_80120CF8.h"
#include "pso/player/TObjPlayer.h"
#include "pso/item/TItem.h"

extern s32 __vt__13TUnk_804A1A48[];

TUnk_804A1A48::~TUnk_804A1A48() {}

extern "C" {

void __ct__11TItemWeaponFP7TObjectPUc(void *);


void *TUnk_804A1A48::init_state_1() {
    __ct__11TItemWeaponFP7TObjectPUc(this);
    *(s32 **)((s8 *)this + 0x18) = __vt__13TUnk_804A1A48;
    set_weapon_flags(1);
    *(u32 *)((s8 *)this + 0x1F8) = 0;
    *(u32 *)&(this->m_1fc) = 1;
    return this;
}

}
