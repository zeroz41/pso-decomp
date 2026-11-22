#include "types.h"
#include "pso/effect/item/TItemEffLandHit.h"
#include "pso/unk/text_801094D8.h"
#include "pso/weapon/TItemAttacker.h"
#include "pso/system/task/TObject.h"
extern u8 invoke_menu_callback_if_set__10TObjPlayerFUl[];
void spawn_land_hit_effect(saddr parent, uaddr item, uaddr arg2, uaddr arg3, s32 frames) {
    if ((parent != 0) && (arg2 != 0U) && (arg3 != 0U) && (item != 0U)) {
        TItemAttacker::spawn_item_timer(new TItemEffLandHit((TObject *)parent, (TItem *)item, (Vec *)arg2, (Vec *)arg3), (ItemTimerCallback)invoke_menu_callback_if_set__10TObjPlayerFUl, frames);
    }
}
