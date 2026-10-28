#include "types.h"
#include "pso/item/TItem.h"
#include "pso/misc/TWindowShortListCtrl.h"
#include "pso/player/TObjPlayer.h"

extern "C" {

void *get_player_by_client_id(s32 i);
void send_6x26_unequip_item__10TObjPlayerFPvPv(void *self, void *item);
void send_6x25_equip_item(void *arg0, s32 arg1, s32 arg2);
s32 get_slot_value__10TObjPlayerFPvi(s32 *arg0, s32 arg1);

void TWindowShortListCtrl::assign_shortcut(s32 arg0, s32 item, s32 arg2) {
    u32 temp_r31;
    s32 temp_r3;
    s32 temp_r0;
    u32 temp_r3b;

    temp_r3 = (s32)get_player_by_client_id(arg2);
    if (temp_r3 != 0) {
        temp_r31 = get_slot_value__10TObjPlayerFPvi((s32 *)(temp_r3 + 0xD04), arg0);
        temp_r3b = (u32)find_item_by_id(item);
        if (temp_r31 == temp_r3b) {
            send_6x26_unequip_item__10TObjPlayerFPvPv((void *)temp_r3, (void *)item);
            return;
        }
        if (((TItem *)temp_r3b)->test_item_flags(8) != 0U) {
            send_6x26_unequip_item__10TObjPlayerFPvPv((void *)temp_r3, (void *)item);
        }
        if (temp_r31 != 0U) {
            temp_r0 = ((TItem *)temp_r31)->get_item_id();
            send_6x26_unequip_item__10TObjPlayerFPvPv((void *)temp_r3, (void *)temp_r0);
        }
        send_6x25_equip_item((void *)temp_r3, item, arg0);
    }
}

}
