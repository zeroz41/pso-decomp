#include "types.h"
#include "pso/item/TUnk_804A1B40.h"

extern "C" {

void draw_weapon_at_joint(s32 arg0, s8 arg1);

void TUnk_804A1B40::reserved_53() {
    s32 temp_r31;

    temp_r31 = *(s32 *)((s8 *)((u8 *)this) + 0xF4);
    ((TItemWeapon *)this)->draw_weapon_model();
    *(s32 *)((s8 *)((u8 *)this) + 0xF4) = (s32) this->second_model;
    draw_weapon_at_joint((s32)this, 0x23);
    *(s32 *)((s8 *)((u8 *)this) + 0xF4) = temp_r31;
}

}
