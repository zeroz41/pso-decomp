#include "types.h"
#include "pso/ui/window/TWindowMenuIconLine.h"
#include "pso/ui/window/TWindowSubItem.h"
#include "pso/item/TItem.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TPlyItem.h"
#include "pso/player/PlayerSlots.h"

void TWindowMenuIconLine::refresh_trade_item_list(TradeItemEntry *entries) {
    save_cursor_selection();
    reset_list();
    fill_trade_item_list(entries);
    clamp_selection_to_valid_entry();
}

void TWindowMenuIconLine::refresh_usable_item_list() {
    save_cursor_selection();
    reset_list();
    build_usable_item_list();
    clamp_selection_to_valid_entry();
}

void TWindowMenuIconLine::refresh_battle_stat_list() {
    save_cursor_selection();
    reset_list();
    build_battle_stat_list();
    clamp_selection_to_valid_entry();
}

void TWindowMenuIconLine::refresh_item_shortcut_list() {
    save_cursor_selection();
    reset_list();
    build_item_shortcut_list();
    clamp_selection_to_valid_entry();
}

void TWindowMenuIconLine::refresh_weapon_shortcut_list() {
    save_cursor_selection();
    reset_list();
    build_weapon_shortcut_list();
    clamp_selection_to_valid_entry();
}

void TWindowMenuIconLine::refresh_armor_equip_list(u16 kind, u16 sub) {
    save_cursor_selection();
    reset_list();
    add_armor_equip_candidates(kind, sub);
    clamp_selection_to_valid_entry();
}

void TWindowMenuIconLine::refresh_mag_item_list(u16 kind) {
    save_cursor_selection();
    reset_list();
    build_mag_item_candidates(kind);
    clamp_selection_to_valid_entry();
}

void TWindowMenuIconLine::refresh_judgment_item_list() {
    save_cursor_selection();
    reset_list();
    populate_judgment_item_list();
    clamp_selection_to_valid_entry();
}

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
        count = player->inventory_objects->run_and_get_result(list);
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

void TWindowMenuIconLine::build_battle_stat_list() {
    u32 stat;

    stat = 0U;
    do {
        add_battle_stat_entry(stat, get_battle_item_id(stat), 1);
        stat += 1;
    } while (stat < 5U);
    if (entry_count <= 0) {
        advance_status_disp_entry(-1);
    }
    disable_decide_sound();
    calc_content_extent();
}

void TWindowMenuIconLine::build_item_shortcut_list() {
    u32 ids[32];
    TObjPlayer *player;
    u32 count;
    TItem *item;
    u32 i;
    player = get_player_by_client_id(client_index);
    if (player != NULL) {
        count = player->inventory_objects->run_and_get_result(reinterpret_cast<s32 *>(ids));
        for (i = 0; i < count; i++) {
            item = find_item_by_id(ids[i]);
            if (item != NULL && item->get_usable_action_flags(2, 0) != 0 && item->get_usable_action_flags(1, 0) == 0) {
                add_list_entry(item, ids[i]);
            }
        }
        if (entry_count <= 0) {
            add_list_entry(-1);
        }
        calc_content_extent();
    }
}

void TWindowMenuIconLine::build_weapon_shortcut_list() {
    s32 ids[30];
    s16 reason;
    s32 weapon_id;
    u32 count;
    TItem *weapon;
    TObjPlayer *player;
    TItem *item;
    u32 i;

    player = get_player_by_client_id(client_index);
    if (player != NULL) {
        count = player->inventory_objects->run_and_get_result(ids);
        for (i = 0; i < count; i++) {
            item = find_item_by_id(ids[i]);
            if (item != NULL && item->get_item_type() == 0 && item->check_equip_requirements(player, &reason) != 0 &&
                item->test_item_flags(8) == 0 && item->get_usable_action_flags(8, 0) != 0) {
                add_list_entry(item, ids[i]);
            }
        }
        // The equipped weapon (equip slot 6) is listed after the inventory.
        weapon = (TItem *)TObjPlayer::get_slot_value(player->equipped_items, 6);
        if (weapon != NULL) {
            weapon_id = weapon->get_item_id();
            add_list_entry(weapon, weapon_id);
        }
        if (entry_count <= 0) {
            add_list_entry(-1);
        }
        calc_content_extent();
    }
}

void TWindowMenuIconLine::add_armor_equip_candidates(u16 kind, u16 sub) {
    s32 ids[30];
    TItem *item;
    u32 n;
    u32 i;
    TObjPlayer *player;
    player = get_player_by_client_id(client_index);
    if (player != NULL) {
        n = player->inventory_objects->run_and_get_result(ids);
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
        n = player->inventory_objects->run_and_get_result(ids);
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
        count = player->inventory_objects->run_and_get_result(list);
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
