#include "types.h"
#include "pso/item/TItemProArmor.h"
#include "pso/player/TObjPlayer_80127DC4.h"

extern "C" {

s32 get_owner_client__5TItemFv(void *);
s32 confusion_curse_timer_ct(s32, u32, s32, s32, f32);
s32 __nw__15TItemHeapObjectFUl(s32);
s32 ct__13TUnk_804A0688Fv(s32, u32, s32, s32);
}

extern f32 lbl_805DADD8;

void yamigarasu_start_timers(void *item_pro_armor) {
    s32 temp_r3;
    s32 temp_r3_2;

    if ((u32) ((TItemProArmor *)item_pro_armor)->m_174 != 0U) {
        temp_r3 = __nw__15TItemHeapObjectFUl(0x30);
        if (temp_r3 != 0) {
            confusion_curse_timer_ct(temp_r3, ((TItemProArmor *)item_pro_armor)->m_174, get_owner_client__5TItemFv(item_pro_armor), 0xE10, lbl_805DADD8);
        }
        temp_r3_2 = __nw__15TItemHeapObjectFUl(0x2C);
        if (temp_r3_2 != 0) {
            ct__13TUnk_804A0688Fv(temp_r3_2, ((TItemProArmor *)item_pro_armor)->m_174, get_owner_client__5TItemFv(item_pro_armor), 0x5A);
        }
    }
}
