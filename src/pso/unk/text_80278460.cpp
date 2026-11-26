#include "pso/unk/TWindowLayoutEntry.h"
#include "pso/ui/ItemListRow.h"
#include "types.h"
#include "pso/item/TItem.h"
#include "pso/unk/text_80278460.h"
#include "pso/ui/window/TWindowSubItem.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/ui/window/TWindowSubEquipKind.h"
#include "pso/player/PlayerSlots.h"

void mark_unequippable_items(TWindowSubEquipKind *window);
void mark_unequippable_items(TWindowSubEquipKind *window) {
    u8 sp8[8];
    s16 i;
    u8 *item;
    ItemListRow *e;
    uaddr t;
    item = (u8 *)get_player_by_client_id(window->client_index);
    if (item != NULL) {
        for (i = 0; i < window->entry_capacity; i++) {
            e = static_cast<ItemListRow *>(window->get_array_entry(i));
            if (e != NULL && e->is_flag_4_set() != 0 && e->is_flag80_set() == 0) {
                if ((t = (uaddr)find_item_by_id(e->get_item())) != 0 && ((TItem *)t)->check_equip_requirements((TObjPlayer *)item, (s16 *)sp8) == 0) {
                    e->flags |= 0x80;
                }
            }
        }
    }
}
void disable_pack_item_rows(void *qst_pack_select_window, s32 item) {
    s32 i;
    u16 *row;
    for (i = 0; i < *(s16 *)((s8 *)qst_pack_select_window + 0x76); i++) {
        row = (u16 *)((TWindowBase *)qst_pack_select_window)->get_array_entry(i);
        if ((((TWindowLayoutEntry *)row)->is_flag_4_set() != 0) && (item == ((ItemListRow *)row)->get_item())) {
            ((ItemListRow *)row)->category_style = 0xFFAAAAAA;
            ((ItemListRow *)row)->style = 0xFF909090;
            ((ItemListRow *)row)->suffix_style = 0xFF909090;
            *(u16 *)((s8 *)row + 0) = (u16) (*(u16 *)((s8 *)row + 0) | 0x80);
        }
    }
}
