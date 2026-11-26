#include "pso/unk/TWindowLayoutEntry.h"
#include "pso/ui/ItemListRow.h"
#include "types.h"
#include "pso/ui/window/TWindowMenuIconLine.h"
#include "pso/item/TItem.h"
#include "pso/unk/text_80278460.h"
#include "pso/ui/window/TWindowSubItem.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/ui/window/TWindowSubEquipKind.h"
#include "pso/player/PlayerSlots.h"

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
        row = (ItemListRow *)window->get_array_entry(i);
        if ((row->is_flag_4_set() != 0) && (item == row->get_item())) {
            row->category_style = 0xFFAAAAAA;
            row->style = 0xFF909090;
            row->suffix_style = 0xFF909090;
            row->flags |= 0x80;
        }
    }
}
