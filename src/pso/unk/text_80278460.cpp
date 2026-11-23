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

extern "C" {
void mark_unequippable_items(TWindowSubEquipKind *window);
void mark_unequippable_items(TWindowSubEquipKind *window) {
    u8 sp8[8];
    s16 i;
    u8 *item;
    u16 *e;
    uaddr t;
    item = (u8 *)get_player_by_client_id(window->client_index);
    if (item != NULL) {
        for (i = 0; i < window->entry_capacity; i++) {
            e = static_cast<u16 *>(window->get_array_entry(i));
            if (e != NULL && ((TWindowLayoutEntry *)e)->is_flag_4_set() != 0 && ((TWindowSubStatusDisp *)e)->is_flag80_set() == 0) {
                if ((t = (uaddr)find_item_by_id(((ItemListRow *)e)->get_item())) != 0 && ((TItem *)t)->check_equip_requirements((TObjPlayer *)item, (s16 *)sp8) == 0) {
                    *e |= 0x80;
                }
            }
        }
    }
}
void fn_80278518(void *qst_pack_select_window, s32 arg1) {
    s32 i;
    u16 *temp_r30;
    for (i = 0; i < *(s16 *)((s8 *)qst_pack_select_window + 0x76); i++) {
        temp_r30 = (u16 *)((TWindowBase *)qst_pack_select_window)->get_array_entry(i);
        if ((((TWindowLayoutEntry *)temp_r30)->is_flag_4_set() != 0) && (arg1 == ((ItemListRow *)temp_r30)->get_item())) {
            ((ItemListRow *)temp_r30)->category_style = 0xFFAAAAAA;
            ((ItemListRow *)temp_r30)->style = 0xFF909090;
            ((ItemListRow *)temp_r30)->suffix_style = 0xFF909090;
            *(u16 *)((s8 *)temp_r30 + 0) = (u16) (*(u16 *)((s8 *)temp_r30 + 0) | 0x80);
        }
    }
}

}
