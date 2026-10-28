#include "types.h"
#include "pso/item/TUnk_804A69DC.h"
#include "pso/player/TObjPlayer.h"

extern "C" {

void __ct__11TItemWeaponFP7TObjectPUc(void *);

extern s32 lbl_804A69DC[];
extern s32 create_shoot_model__10TObjPlayerFiiif[];

void *TUnk_804A69DC::init_state_35() {
    __ct__11TItemWeaponFP7TObjectPUc(this);
    *(s32 **)((s8 *)this + 0x18) = lbl_804A69DC;
    set_weapon_flags(35);
    *(s32 **)((s8 *)this + 0x1F0) = create_shoot_model__10TObjPlayerFiiif;
    *(u32 *)((s8 *)this + 0x1F8) = 0;
    *(u32 *)&(this->m_1fc) = 3276;
    *(u32 *)((s8 *)this + 0x200) = 0;
    *(u32 *)&(this->m_204) = 1;
    return this;
}

}
