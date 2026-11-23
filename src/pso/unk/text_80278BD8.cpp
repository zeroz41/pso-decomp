#include "types.h"
#include "pso/ui/window/TWindowMenuIconLine.h"
#include "pso/item/TItem.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TPlyItem.h"
#include "pso/player/PlayerSlots.h"

void TWindowMenuIconLine::add_armor_equip_candidates(u16 kind, u16 sub) {
    s32 ids[30];
    TItem *item;
    u32 n;
    u32 i;
    TObjPlayer *player;
    player = get_player_by_client_id(client_index);
    if (player != NULL) {
        n = player->inventory_objects->run_and_get_result((saddr)ids);
        for (i = 0; i < n; i++) {
            item = find_item_by_id(ids[i]);
            if (item != NULL && kind == item->get_item_type() && sub == item->get_item_group() &&
                item->get_usable_action_flags(8, 0) != 0) {
                add_list_entry(item, ids[i]);
            }
        }
        if (entry_count <= 0) {
            add_list_entry(-1);
        }
        calc_content_extent();
    }
}

void TWindowMenuIconLine::build_mag_item_candidates(u16 kind) {
    s32 ids[30];
    TItem *item;
    u32 n;
    u32 i;
    TObjPlayer *player;
    player = get_player_by_client_id(client_index);
    if (player != NULL) {
        n = player->inventory_objects->run_and_get_result((saddr)ids);
        for (i = 0; i < n; i++) {
            item = find_item_by_id(ids[i]);
            if ((item != NULL) && (kind == item->get_item_type()) && (item->get_usable_action_flags(8, 0) != 0U)) {
                add_list_entry(item, ids[i]);
            }
        }
        if (entry_count <= 0) {
            add_list_entry(-1);
        }
        calc_content_extent();
    }
}

void TWindowMenuIconLine::populate_judgment_item_list() {
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
            if (item != NULL) {
                add_list_entry(item, list[i]);
            }
        }
        if (entry_count <= 0) {
            add_list_entry(-1);
        }
        calc_content_extent();
    }
}
