#include "types.h"
#include "pso/item/TItemProArmor.h"
#include "pso/player/TObjPlayer_80126278.h"

extern "C" {

s32 get_owner_client__5TItemFv(void *);
s32 freeze_curse_timer_ct(s32, u32, s32, s32, f32);
s32 __nw__15TItemHeapObjectFUl(s32);
}

extern f32 lbl_805DAD74;

void frozen_shooter_start_curse(void *item_pro_armor) {
    s32 temp_r3;

    if ((u32) ((TItemProArmor *)item_pro_armor)->effect_objects != 0U) {
        temp_r3 = __nw__15TItemHeapObjectFUl(0x30);
        if (temp_r3 != 0) {
            freeze_curse_timer_ct(temp_r3, (u32)((TItemProArmor *)item_pro_armor)->effect_objects, get_owner_client__5TItemFv(item_pro_armor), 0xE10, lbl_805DAD74);
        }
    }
}
