#include "types.h"
#include "pso/item/TItem.h"
#include "pso/ui/window/TWindowSubEquip.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/window/TWindowMenuIconLine.h"
#include "pso/ui/window/TWindowHelpItem_802540AC.h"

extern "C" {

void *get_player_by_client_id(s32 i);

void TWindowSubEquip::update_displayed_item() {
    s32 temp_r3;

    temp_r3 = ((TWindowMenuIconLine *)this->m_38)->get_cursor_value();
    if (temp_r3 != (s32) this->m_24) {
        this->m_24 = temp_r3;
        TWindowHelpItem__set_displayed_item_by_id((u8 *)this->m_30, temp_r3);
    }
}

void TWindowSubEquip::update() {
    saddr player;
    s32 var_r3;
    s32 slot;

    player = (saddr)get_player_by_client_id(this->m_28);
    if (player != 0) {
        slot = ((TWindowMenuIconLine *)this->m_34)->get_cursor_value();
        TItem *item = (TItem *)TObjPlayer::get_slot_value((s32 *)(player + 0xD04), slot);
        if (item == NULL) {
            var_r3 = -1;
        } else {
            var_r3 = item->get_item_id();
        }
        if (var_r3 != (s32) this->m_20) {
            this->m_20 = var_r3;
            show_item_by_id__15TWindowHelpItemFPvi((u8 *)this->m_30, var_r3);
        }
    }
}

}
