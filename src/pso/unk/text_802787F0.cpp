#include "types.h"
#include "pso/ui/window/TWindowMenuIconLine.h"
#include "pso/ui/window/TWindowSubStatusDisp_802671F0.h"
#include "pso/item/TItem.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TPlyItem.h"
#include "pso/player/PlayerSlots.h"

void TWindowMenuIconLine::fill_trade_item_list(TradeItemEntry *entries) {
    s32 sid;
    u32 i;
    s32 count;
    TradeItemEntry *p;
    TItem *item;
    if (entries != NULL) {
        p = entries;
        i = 0;
        do {
            count = p->count;
            u32 id = p->id;
            if (count > 0) {
                if (id == 0xFFFFFF01) {
                    push_status_disp_entry(count, id);
                } else {
                    sid = id;
                    item = find_item_by_id(sid);
                    if (item != NULL) {
                        add_inventory_item(item, count, sid);
                    }
                }
            }
            i++;
            p++;
        } while (i < 0x1F);
        if (entry_count <= 0) {
            add_list_entry(-1);
        }
        calc_content_extent();
    }
}

void TWindowMenuIconLine::build_usable_item_list() {
    s32 list[0x20];
    TItem *item;
    u32 i;
    u32 count;
    TObjPlayer *player;
    player = get_player_by_client_id(client_index);
    if (player != NULL) {
        count = player->inventory_objects->run_and_get_result((saddr)list);
        for (i = 0; i < count; i++) {
            item = find_item_by_id(list[i]);
            if (item != NULL && item->get_usable_action_flags(4, 0) != 0) {
                add_list_entry(item, list[i]);
            }
        }
        if (entry_count <= 0) {
            add_list_entry(-1);
        }
        calc_content_extent();
    }
}
