#include "types.h"
#include "pso/item/TItem.h"
#include "pso/ui/window/TWindowShortListCtrl.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/PlayerSlots.h"


extern "C" {


void TWindowShortListCtrl::assign_shortcut(s32 slot, saddr item, s32 client_id) {
    uaddr slot_value;
    saddr player;
    saddr item_id;
    uaddr temp_r3b;

    player = (saddr)get_player_by_client_id(client_id);
    if (player != 0) {
        slot_value = TObjPlayer::get_slot_value((s32 *)(player + 0xD04), slot);
        temp_r3b = (uaddr)find_item_by_id(item);
        if (slot_value == temp_r3b) {
            TObjPlayer::send_6x26_unequip_item((TObjPlayer *)player, item);
            return;
        }
        if (((TItem *)temp_r3b)->test_item_flags(8) != 0U) {
            TObjPlayer::send_6x26_unequip_item((TObjPlayer *)player, item);
        }
        if (slot_value != 0U) {
            item_id = ((TItem *)slot_value)->get_item_id();
            TObjPlayer::send_6x26_unequip_item((TObjPlayer *)player, item_id);
        }
        send_6x25_equip_item((TObjPlayer *)player, item, slot);
    }
}

}
