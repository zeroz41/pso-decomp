#include "types.h"
#include "pso/ui/window/TWindowMenuIconLine.h"
#include "pso/ui/window/ItemListRow.h"
#include "pso/item/TItem.h"
#include "pso/item/TItemData.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/PlayerSlots.h"
#include "pso/ui/charcreate/CharacterAppearance.h"


void TWindowMenuIconLine::disable_decide_sound() {
    state_flags |= 0x100;
}

void TWindowMenuIconLine::refresh_equipment_list() {
    save_cursor_selection();
    reset_list();
    build_equipment_list();
    clamp_selection_to_valid_entry();
}

u8 TWindowMenuIconLine::get_class_weapon_icon_index(TObjPlayer *player) {
    CharacterAppearanceFields *appearance = &player->appearance;
    if (appearance == NULL) return 0x33;
    if (appearance->classFlags & 0x20) return 0;
    if (appearance->classFlags & 0x40) return 1;
    return 2;
}

void TWindowMenuIconLine::add_status_line(u8 category_icon, TItem *item, s32 slot) {
    ItemListRow *row = (ItemListRow *)get_array_entry(entry_count);
    if (item == NULL) {
        row->init_status_entry(category_icon, 0, slot);
        row->x += 18.0f;
        row->category_style = 0xFFAAAAAA;
    } else {
        row->init_item_row(item, slot);
    }
    if (category_icon == 4) {
        row->x += 18.0f;
    }
    entry_count++;
}

// The equip menu's list: weapon, armor and the units in its slots, shield,
// mag.
void TWindowMenuIconLine::build_equipment_list() {
    TItemData data;
    TItem *item;
    s32 i;
    s32 slots;
    u8 weapon_icon;
    TObjPlayer *player;

    player = get_player_by_client_id(client_index);
    if (player != NULL) {
        weapon_icon = get_class_weapon_icon_index(player);
        item = TObjPlayer::get_slot_value(player->equipped_items.items, 6);
        add_status_line(weapon_icon, item, 6);
        item = TObjPlayer::get_slot_value(player->equipped_items.items, 2);
        add_status_line(0xb, item, 2);
        if (item != NULL) {
            item->copy_to_item_data(&data);
            slots = (s8)data.data1.data_u8[5];
            for (i = 0; i < slots; i++) {
                item = TObjPlayer::get_slot_value(player->equipped_items.items, i + 9);
                add_status_line(4, item, i + 9);
            }
        }
        item = TObjPlayer::get_slot_value(player->equipped_items.items, 3);
        add_status_line(0xa, item, 3);
        item = TObjPlayer::get_slot_value(player->equipped_items.items, 1);
        add_status_line(3, item, 1);
    }
}
