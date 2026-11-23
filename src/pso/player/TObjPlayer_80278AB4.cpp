#include "types.h"
#include "pso/ui/window/TWindowMenuIconLine.h"
#include "pso/item/TItem.h"
#include "pso/ui/city/TShopJudgmentItemWindow.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/player/PlayerSlots.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TPlyItem.h"

extern "C" {

void TObjPlayer::build_shop_item_list() {
    s32 spC[30];
    s32 sp8;
    s32 temp_r5;
    u32 temp_r30;
    saddr slot_value;
    TObjPlayer *player;
    saddr temp_r3_2;
    u32 i;

    player = get_player_by_client_id(*(s16 *)&this->m_20);
    if (player != NULL) {
        temp_r30 = player->inventory_objects->run_and_get_result(spC);
        for (i = 0; i < temp_r30; i++) {
            temp_r3_2 = (saddr)find_item_by_id(spC[i]);
            if ((temp_r3_2 != 0) && (((TItem *)temp_r3_2)->get_item_type() == 0) && (((TItem *)temp_r3_2)->check_equip_requirements(player, (s16 *)(&sp8)) != 0) && (((TItem *)temp_r3_2)->test_item_flags(8) == 0U) && (((TItem *)temp_r3_2)->get_usable_action_flags(8, 0) != 0U)) {
                ((TShopJudgmentItemWindow *)((u8 *)this))->add_list_entry(temp_r3_2, spC[i]);
            }
        }
        slot_value = TObjPlayer::get_slot_value(player->equipped_items, 6);
        if (slot_value != 0) {
            temp_r5 = ((TItem *)slot_value)->get_item_id();
            ((TShopJudgmentItemWindow *)((u8 *)this))->add_list_entry(slot_value, temp_r5);
        }
        if (*(s16 *)((s8 *)((u8 *)this) + 0x72) <= 0) {
            ((TWindowSubStatusDisp *)((u8 *)this))->add_list_entry(-1);
        }
        ((TWindowMenuIconLine *)this)->calc_content_extent();
    }
}

}
