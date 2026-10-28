#include "types.h"
#include "pso/items/TItemWeapon.h"
#include "pso/item/TItemEquipBase.h"
#include "pso/item/TItemProShield.h"

void TItemProShield::vfunc_26() {
    s32 temp_r31;
    if (this->m_19c & 8) {
        this->deactivate_shield_effect(0x13);
        temp_r31 = this->item_model;
        this->item_model = (s32) this->m_188;
        this->deactivate_shield_effect(0xA);
        this->item_model = temp_r31;
        return;
    }
    ((TItemProShield *)((u8 *)this))->deactivate_shield_effect((s32) ((TItemWeapon *)((u8 *)this))->get_attach_joint());
}
