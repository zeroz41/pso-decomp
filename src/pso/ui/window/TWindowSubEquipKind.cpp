#include "types.h"
#include "pso/ui/font/MenuFontGlyphs.h"
#include "pso/ui/window/TWindowSubEquipKind.h"
#include "pso/ui/window/WindowTextDraw.h"
#include "pso/ui/window/HeadingEntry.h"
#include "pso/ui/window/WindowDrawContext.h"
#include "pso/enemy/morfos/TWindowSubTradeMain.h"
#include "pso/system/NinjaTypes.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/unk/TWindowLayoutEntry.h"
#include "pso/ui/ItemListRow.h"
#include "pso/item/TItem.h"
#include "pso/ui/window/TWindowSubItem.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/player/PlayerSlots.h"
#include "pso/ui/window/TWindowMenuIconLine.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TPlyItem.h"
#include "pso/ui/window/WindowScrollBar.h"
#include "pso/ui/window/WindowLayoutEntries.h"
#include "pso/system/task/TObject.h"

#pragma readonly_strings on

const char *TWindowSubEquipKind::class_name = "TWindowSubEquipKind";

// Message ids of the four status-display tab labels, indexed by the selected tab (f88).
extern const s32 status_disp_tab_label_message_ids[4] = {0xE2, 0xE0, 0xE1, 0xF5};

extern "C" {

static const u8 equip_kind_tab_label_colors[4] = {1, 2, 2, 1};
void TWindowSubEquipKind::set_trade_state(s16 trade_state) {
    this->trade_state = trade_state;
    if (this->trade_state == 3) {
        state_timer = 60;
    }
}

#pragma push
#pragma fp_contract on
void TWindowSubEquipKind::draw_tab_label(WindowDrawContext *context) {
    NJS_POINT2 pos;
    const char *msg;
    s16 fl;
    u8 col;

    if (context->open_tick >= 0) {
        pos.x = context->x + get_heading_frame_width(status_display);
        pos.y = context->y - 13.0f;
        col = equip_kind_tab_label_colors[trade_state];
        fl = state_timer;
        if (fl != 0) {
            if (fl & 4) {
                col = 1;
            } else {
                col = 2;
            }
        }
        draw_window_tab(context, &pos.x, 0.0f, col);
        pos.x += 80.0f;
        pos.y += 4.0f;
        set_text_draw_params(context, 0, 0, (f32)(-1.0f / (0.1794f + context->depth)), 100000.0f);
        msg = TWindowSubStatusDisp::get_message_10(status_disp_tab_label_message_ids[trade_state]);
        pos.x -= 0.5f * (f32)calc_text_width(msg);
        draw_window_text((f32 *)&pos, msg, (0xFF000000), 0, 100000.0f);
    }
}
#pragma pop

}

void mark_unequippable_items(TWindowSubEquipKind *window) {
    u8 equip_buf[8];
    s16 i;
    u8 *item;
    ItemListRow *e;
    uaddr t;
    item = (u8 *)get_player_by_client_id(window->client_index);
    if (item != NULL) {
        for (i = 0; i < window->entry_capacity; i++) {
            e = static_cast<ItemListRow *>(window->get_array_entry(i));
            if (e != NULL && e->is_flag_4_set() != 0 && e->is_flag80_set() == 0) {
                if ((t = (uaddr)find_item_by_id(e->get_item())) != 0 && ((TItem *)t)->check_equip_requirements((TObjPlayer *)item, (s16 *)equip_buf) == 0) {
                    e->flags |= 0x80;
                }
            }
        }
    }
}
void disable_pack_item_rows(TWindowMenuIconLine *window, s32 item) {
    s32 i;
    ItemListRow *row;
    for (i = 0; i < window->entry_capacity; i++) {
        row = static_cast<ItemListRow *>(window->get_array_entry(i));
        if (row->is_flag_4_set() != 0 && item == row->get_item()) {
            row->category_style = 0xFFAAAAAA;
            row->style = 0xFF909090;
            row->suffix_style = 0xFF909090;
            row->flags |= 0x80;
        }
    }
}

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
                    add_meseta_entry(count, id);
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
        weapon = TObjPlayer::get_slot_value(player->equipped_items.items, 6);
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

TWindowSubEquipKind *create_equip_kind_window(const NJS_POINT2 *position, const NJS_POINT2 *size, s32 client) {
    set_menu_icon_line_params(size, 0x1F);
    return new TWindowSubEquipKind((u8 *)position, client);
}


void TWindowSubEquipKind::render() {
    WindowDrawContext *context;

    context = get_draw_context();
    draw_window_frame(context);
    draw_visible_window_entries(this, &entry_list, context);
    draw_selected_list_entry(context);
    if (trade_state != 4) {
        draw_tab_label(context);
    }
    if (status_display != NULL) {
        status_display->render(context);
    }
    if (scroll_bar != NULL) {
        draw_window_scrollbar(scroll_bar, context, scroll_offset);
    }
}

void TWindowSubEquipKind::run_task() {
    int count;

    TWindowMenuIconLine::run_task();
    count = state_timer;
    if (count != 0) {
        state_timer = count - 1;
    }
}

TWindowSubEquipKind::~TWindowSubEquipKind() {}

TWindowSubEquipKind::TWindowSubEquipKind(u8 *parent, s32 client) : TWindowMenuIconLine(parent, 0x1F, client) {
    m_name = TWindowSubEquipKind::class_name;
    create_menu_scroll_bar();
    trade_state = 4;
    state_timer = 0;
}
