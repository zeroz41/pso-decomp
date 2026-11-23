#include "types.h"
#include "pso/item/TItem.h"
#include "pso/ui/window/TWindowSubEquip.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/window/TWindowMenuIconLine.h"
#include "pso/ui/window/TWindowHelpItem_802540AC.h"
#include "pso/ui/window/TWindowHelpItem.h"
#include "pso/player/PlayerSlots.h"

extern "C" {


void TWindowSubEquip::update_displayed_item() {
    s32 temp_r3;

    temp_r3 = ((TWindowMenuIconLine *)this->equip_kind_list)->get_cursor_value();
    if (temp_r3 != (s32) this->m_24) {
        this->m_24 = temp_r3;
        this->window_help_item->set_displayed_item_by_id(temp_r3);
    }
}

void TWindowSubEquip::update() {
    saddr player;
    s32 item_id;
    s32 slot;

    player = (saddr)get_player_by_client_id(this->client_id);
    if (player != 0) {
        slot = ((TWindowMenuIconLine *)this->equip_list)->get_cursor_value();
        TItem *item = (TItem *)TObjPlayer::get_slot_value((s32 *)(player + 0xD04), slot);
        if (item == NULL) {
            item_id = -1;
        } else {
            item_id = item->get_item_id();
        }
        if (item_id != (s32) this->m_20) {
            this->m_20 = item_id;
            show_item_by_id__15TWindowHelpItemFPvi((u8 *)this->window_help_item, item_id);
        }
    }
}

}
