#include "types.h"
#include "pso/item/TItemEquipVariant_80120CF8.h"
#include "pso/player/TObjPlayer.h"
#include "pso/item/TItem.h"
#include "pso/item/TUnk_804A69DC.h"

extern s32 lbl_804A69DC[];

void *__dt__13TUnk_804A69DCFv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = lbl_804A69DC;
        __dt__11TItemWeaponFv(arg0, 0);
        if (arg1 > 0) {
            TItem::operator delete(arg0);
        }
    }
    return arg0;
}

extern "C" {

void __ct__11TItemWeaponFP7TObjectPUc(void *);

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
