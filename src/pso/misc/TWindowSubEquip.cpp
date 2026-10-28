#include "types.h"
#include "pso/misc/TWindowSubEquip.h"

extern "C" {

void *get_player_by_client_id(s32 i);
s32 get_item_id__5TItemFv();
s32 get_slot_value__10TObjPlayerFPvi(s32 *arg0, s32 arg1);
void TWindowHelpItem__set_displayed_item_by_id(u8 *arg0, s32 arg1);
void show_item_by_id__15TWindowHelpItemFPvi(u8 *arg0, s32 arg1);
s32 select_cursor_entry__22TWindowSubShortCutListFv(s32);

void TWindowSubEquip::update_displayed_item() {
    s32 temp_r3;

    temp_r3 = select_cursor_entry__22TWindowSubShortCutListFv(this->m_38);
    if (temp_r3 != (s32) this->m_24) {
        this->m_24 = temp_r3;
        TWindowHelpItem__set_displayed_item_by_id((u8 *)this->m_30, temp_r3);
    }
}

void TWindowSubEquip::update() {
    s32 player;
    s32 var_r3;
    s32 temp_r0;

    player = (s32)get_player_by_client_id(this->m_28);
    if (player != 0) {
        temp_r0 = select_cursor_entry__22TWindowSubShortCutListFv(this->m_34);
        if (get_slot_value__10TObjPlayerFPvi((s32 *)(player + 0xD04), temp_r0) == 0U) {
            var_r3 = -1;
        } else {
            var_r3 = get_item_id__5TItemFv();
        }
        if (var_r3 != (s32) this->m_20) {
            this->m_20 = var_r3;
            show_item_by_id__15TWindowHelpItemFPvi((u8 *)this->m_30, var_r3);
        }
    }
}

}
