#include "types.h"
#include "pso/unk/text_801095EC.h"
#include "pso/unk/text_801094D8.h"
#include "pso/weapon/TItemAttacker.h"
extern "C" {
void *__nw__7TObjectFUl(u32);
}
extern u8 invoke_menu_callback_if_set__10TObjPlayerFUl[];
void spawn_land_hit_effect(s32 arg0, u32 item, u32 arg2, u32 arg3, s32 arg4) {
    void *p;
    if ((arg0 != 0) && (arg2 != 0U) && (arg3 != 0U) && (item != 0U)) {
        p = __nw__7TObjectFUl(0x3C);
        if (p != 0) {
            p = TItemEffLandHit__ct((u8 *)p, (u8 *)arg0, (u8 *)item, (u8 *)arg2, (u8 *)arg3);
        }
        TItemAttacker::spawn_item_timer((TObject *)p, (ItemTimerCallback)invoke_menu_callback_if_set__10TObjPlayerFUl, arg4);
    }
}
