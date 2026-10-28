#include "types.h"
#include "pso/item/TItem.h"
#include "pso/unk/text_80278460.h"
#include "pso/misc/TWindowSubItem.h"
#include "pso/misc/TWindowSubStatusDisp.h"

struct Wn_80278460 { u8 pad0[0x20]; s16 f20; u8 pad22[0x54]; s16 f76; };

extern "C" {
s32 check_equip_requirements__5TItemFP10TObjPlayerPs(u32, void *, void *);
void *get_player_by_client_id(s32 i);
u16 *get_array_entry__13TUnk_804CE018Fi(void *, s16);
s32 is_flag_4_set__20TWindowSubStatusDispFv();
void mark_unequippable_items(Wn_80278460 *arg0);
void mark_unequippable_items(Wn_80278460 *arg0) {
    u8 sp8[8];
    s32 i;
    u8 *item;
    u16 *e;
    u32 t;
    item = (u8 *)get_player_by_client_id(arg0->f20);
    if (item != NULL) {
        for (i = 0; (s16)i < arg0->f76; i++) {
            e = get_array_entry__13TUnk_804CE018Fi(arg0, i);
            if (e != NULL && is_flag_4_set__20TWindowSubStatusDispFv() != 0 && ((TWindowSubStatusDisp *)e)->is_flag80_set() == 0) {
                if ((t = (u32)find_item_by_id(((TWindowSubItem *)e)->get_cursor_pos())) != 0 && check_equip_requirements__5TItemFP10TObjPlayerPs(t, item, sp8) == 0) {
                    *e |= 0x80;
                }
            }
        }
    }
}
void fn_80278518(void *arg0, s32 arg1) {
    s32 i;
    u16 *temp_r30;
    for (i = 0; i < *(s16 *)((s8 *)arg0 + 0x76); i++) {
        temp_r30 = ((u16 *(*)(void *, s32)) get_array_entry__13TUnk_804CE018Fi)(arg0, i);
        if ((is_flag_4_set__20TWindowSubStatusDispFv() != 0) && (arg1 == ((TWindowSubItem *)temp_r30)->get_cursor_pos())) {
            ((TWindowSubItem *)temp_r30)->m_2c = 0xFFAAAAAA;
            ((TWindowSubItem *)temp_r30)->m_30 = 0xFF909090;
            ((TWindowSubItem *)temp_r30)->m_34 = 0xFF909090;
            *(u16 *)((s8 *)temp_r30 + 0) = (u16) (*(u16 *)((s8 *)temp_r30 + 0) | 0x80);
        }
    }
}

}
