#include "types.h"
#include "pso/item/TUnk_804A0EA8.h"
#include "pso/player/TObjPlayer.h"

extern "C" {

void draw_weapon_at_joint(s32 arg0, s8 arg1);

void TUnk_804A0EA8::reserved_53() {
    s32 temp_r31;

    temp_r31 = *(s32 *)((s8 *)((u8 *)this) + 0xF4);
    draw_weapon_model();
    ((TItemWeapon *)((u8 *)this))->get_gun_point((((u8 *)this) + 0x1F8));
    *(s32 *)((s8 *)((u8 *)this) + 0xF4) = (s32) *(s32 *)((s8 *)((u8 *)this) + 0x180);
    draw_weapon_at_joint((s32)this, 0x23);
    ((TItemWeapon *)((u8 *)this))->get_gun_point((((u8 *)this) + 0x204));
    *(s32 *)((s8 *)((u8 *)this) + 0xF4) = temp_r31;
}

}
