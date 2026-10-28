#include "types.h"
#include "pso/protocol/protocol_types.h"
#include "pso/item/TItemObject.h"
#include "pso/system/byteswap.h"
#include "pso/protocol/subcmd_6x.h"
#include <stddef.h>
#include "pso/misc/TLobby.h"
#include "pso/item/TItemData.h"
#include "pso/player/TObjPlayer.h"

struct In_8010440C { u8 pad0; u8 idx; };

struct In_80104438 { u8 pad0; u8 idx; };

struct Ent_80103F68 { u8 pad[0x24]; };

#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off

struct Tbl_801044B8 { s32 v[17]; };

extern "C" {
void mem_free(void *p);
extern u32 TLobby__floor_item_entry_pool;
extern s32 floor_item_row_table;
extern s32 floor_item_counts_by_floor;
extern s32 floor_item_free_id_stack;
extern int floor_item_free_id_count;
extern s32 floor_item_next_sort_keys;
extern s32 lbl_805D5430;
s32 __construct_new_array(s32, s32 *, s32, s32, s32);
s32 mem_alloc(s32);
extern s32 __ct__9FloorItemFv[];
    extern int lbl_805D5868;
int read_be16_field2__10TObjPlayerFv(void*);
void TLobby__send_and_handle_60(u8 *arg0);
void TLobby__sub_801041BC(void *arg0);
void TLobby__sub_801041D8(void);
void bswap__9TItemDataFv(s32 arg0);
void TLobby__sub_80104350(void);
    extern int* item_sync_counter_table;
s32 get_item_icon_index();
    extern int lobby_drop_flag;
void TLobby__sub_80104464(void);
int fn_80077788(void);
int fn_80077790(void);
s32 fn_801058E8();
s32 get_char_index__23TAdSinglePlyChrSelectGCFUi(u32 arg0);
s32 is_locally_controlled__10TObjPlayerFPv();
void send_6x25_equip_item(void *arg0, s32 arg1, s32 arg2);
s32 get_player_by_client_id(u16);
s32 is_script_controlled__10TObjPlayerFv(s32);
s32 obj_isState3_324__13TUnk_804806E8Fv(s32);
extern s32 local_client_id;
extern s32 TLobby__designated_client_id;
void send_6x26_unequip_item__10TObjPlayerFPvPv(void *self, void *item);
u32 get_equip_field_d04__10TObjPlayerFl(s32, s32);
s32 get_item_id__5TItemFv();
int get_item_field_6__10TObjPlayerFPv(void *p);
extern void *item_tool_factory_table[];
void create__11TItemObjectFv();
void *TLobby__sub_8010440C(In_8010440C *arg0);
void *get_weapon_factory_for_item(In_80104438 *arg0);
int is_quest_active(void);
s32 TItemDropSub__sub_80107B74();
}
extern void *weapon_factory_table[];
s32 create_common_weapon(s32 arg0);
extern Tbl_801044B8 item_drop_area_remap_table;
void normalize_drop_area(s32 *p);
extern "C" {
void bswap_sync_item_state_header(G_SyncItemState_6x6D_Decompressed *header);
void TLobby::clear_object_count() { floor_item_free_id_count = 0; }

void TLobby::reset_floor_items() {
    s32 i;
    s32 j;
    s32 k;
    for (i = 0; i != 0xD80; i++) {
        if (*(Ent_80103F68 **)&TLobby__floor_item_entry_pool != NULL) {
            ((FloorItem *)(&(*(Ent_80103F68 **)&TLobby__floor_item_entry_pool)[i]))->clear();
        }
    }
    for (j = 0; j < 0x12; j++) {
        if (*(u16 **)&floor_item_next_sort_keys != NULL) {
            (*(u16 **)&floor_item_next_sort_keys)[j] = 0;
        }
    }
    for (k = 0; k < 0x12; k++) {
        if (*(Ent_80103F68 ***)&floor_item_row_table != NULL && *(Ent_80103F68 **)&TLobby__floor_item_entry_pool != NULL && *(s32 **)&floor_item_counts_by_floor != NULL) {
            (*(Ent_80103F68 ***)&floor_item_row_table)[k] = &(*(Ent_80103F68 **)&TLobby__floor_item_entry_pool)[k * 0xC0];
            (*(s32 **)&floor_item_counts_by_floor)[k] = 0;
        }
    }
    TLobby::clear_object_count();
}

void TLobby::free_boss_rocks() {
    mem_free((void *)floor_item_next_sort_keys);
    floor_item_next_sort_keys = 0;
    mem_free((void *)floor_item_free_id_stack);
    floor_item_free_id_stack = 0;
    (*(s32 *)&floor_item_free_id_count) = 0;
    mem_free((void *)floor_item_counts_by_floor);
    floor_item_counts_by_floor = 0;
    mem_free((void *)floor_item_row_table);
    floor_item_row_table = 0;
    if ((u32) TLobby__floor_item_entry_pool != 0U) {
        mem_free((void *)(TLobby__floor_item_entry_pool - 0x10));
    }
    TLobby__floor_item_entry_pool = 0U;
    ((TObjPlayer *)(&lbl_805D5430))->clear_id();
}
void TLobby::alloc_objects() {
    (*(s32 *)&TLobby__floor_item_entry_pool) = __construct_new_array(mem_alloc(0x1E610), __ct__9FloorItemFv, 0, 0x24, 0xD80);
    floor_item_row_table = mem_alloc(0x48);
    floor_item_counts_by_floor = mem_alloc(0x48);
    floor_item_free_id_stack = mem_alloc(0x40);
    (*(s32 *)&floor_item_free_id_count) = 0;
    floor_item_next_sort_keys = mem_alloc(0x24);
    ((TObjPlayer *)(&lbl_805D5430))->clear_id();
    TLobby::reset_floor_items();
}
int TLobby::get_lobby_flag() {  return lbl_805D5868; }
void TLobby::bswap_player_packet() { read_be16_field2__10TObjPlayerFv(this); bswap_32((u32 *)((char*)this + 0x4)); bswap_32((u32 *)((char*)this + 0x8)); }
void TLobby::update_and_send() { bswap_player_packet(); TLobby__send_and_handle_60((u8 *)this); }
void TLobby__sub_801041BC(void *arg0) {
    *(s32 *)((s8 *)arg0 + 4) = -1;
    *(s8 *)((s8 *)arg0 + 0) = 0x63;
    *(s8 *)((s8 *)arg0 + 1) = 3;
}
void TLobby__sub_801041D8(void) {
    ((TObjPlayer *)(&lbl_805D5430))->set_flags(1);
}
void TLobby::bswap_item() { bswap_16((u16 *)((char*)this + 0x2)); bswap_32((u32 *)((char*)this + 0x4)); bswap_32((u32 *)((char*)this + 0x8)); bswap_16((u16 *)((char*)this + 0xc)); bswap_16((u16 *)((char*)this + 0xe)); bswap__9TItemDataFv((s32)((char*)this + 0x10)); }

typedef char SyncItemHeaderPlayerIds[offsetof(G_SyncItemState_6x6D_Decompressed, next_item_id_per_player) == 0x20 ? 1 : -1];
typedef char SyncItemHeaderFloorCounts[offsetof(G_SyncItemState_6x6D_Decompressed, floor_item_count_per_floor) == 0x50 ? 1 : -1];
typedef char SyncItemHeaderSize[sizeof(G_SyncItemState_6x6D_Decompressed) == 0x8C ? 1 : -1];
void bswap_sync_item_state_header(G_SyncItemState_6x6D_Decompressed *header) {
    for (s32 i = 0; i < 16; ++i) {
        bswap_16((&header->next_drop_number_per_floor[i]));
    }
    for (s32 i = 0; i < 12; ++i) {
        bswap_32((&header->next_item_id_per_player[i]));
    }
    for (s32 i = 0; i < 15; ++i) {
        bswap_32((&header->floor_item_count_per_floor[i]));
    }
}

void TLobby__sub_80104350(void) {
    ((TObjPlayer *)(&lbl_805D5430))->init_forward();
}
void TLobby::set_boss_buf_entry(int a0, int a1) { item_sync_counter_table[(unsigned short)(a1)] = a0; }
int TLobby::get_sync_counter(int a0) {  return item_sync_counter_table[(unsigned short)(a0)]; }
s32 TLobby::get_item_data(u32 arg0) {
    if (arg0 != 0U) {
        return get_item_icon_index();
    }
    return 0;
}
void TLobby::forward_message(s32 buf, u32 arg1) {
    if (arg1 != 0U) {
        ((TItemData *)arg1)->format_item_name((char *)buf);
    }
}
void TLobby::mark_selected() { lobby_drop_flag = 1; }
int TLobby::get_drop_flag() {  return lobby_drop_flag; }

void *TLobby__sub_8010440C(In_8010440C *arg0) {
    u8 i = arg0->idx;
    if (i < 0x18) {
        return item_tool_factory_table[i];
    }
    return (void *)create__11TItemObjectFv;
}

void *get_weapon_factory_for_item(In_80104438 *arg0) {
    u8 i = arg0->idx;
    if (i < 0xAA) {
        return weapon_factory_table[i];
    }
    return (void *)create_common_weapon;
}

void TLobby__sub_80104464(void) {  }
void TLobby::handle_select_confirm() {
    if ((fn_80077790() == 1) || (fn_80077788() == 1)) {
        TLobby::mark_selected();
        if (get_char_index__23TAdSinglePlyChrSelectGCFUi(0xFFFF) != 0U) {
            fn_801058E8();
        }
    }
}
}

void normalize_drop_area(s32 *p) {
    s32 v;
    if (is_quest_active() != 0 && p != NULL) {
        switch (*p) {
        case 0x10:
        case 0x11:
            *p = TItemDropSub__sub_80107B74();
            return;
        }
    }
    if (TLobby::get_instance() == 0) {
        if (p != NULL) {
            v = *p;
            if (v > 10) {
                switch (v) {
                case 11:
                    *p = 3;
                    break;
                case 12:
                    *p = 6;
                    break;
                case 13:
                    *p = 8;
                    break;
                default:
                    *p = 10;
                    break;
                }
            } else if (v < 1) {
                *p = 1;
            }
        }
    } else if (p != NULL) {
        v = *p;
        if (v >= 0x13 && v < 0x24) {
            Tbl_801044B8 t = item_drop_area_remap_table;
            *p = t.v[(u32)(v - 0x13)];
        }
    }
}

void TLobby::forward_to_player(int arg0, void *item) {
    s32 player;
    if (item != NULL) {
        player = get_player_by_client_id(arg0);
        if ((player != 0) && ((is_locally_controlled__10TObjPlayerFPv() == 1) || ((obj_isState3_324__13TUnk_804806E8Fv(player) == 1) && ((s32) local_client_id == (s32) TLobby__designated_client_id)) || ((is_script_controlled__10TObjPlayerFv(player) == 1) && ((s32) local_client_id == (s32) TLobby__designated_client_id)))) {
            ((TObjPlayer *)player)->request_inventory_item((TItemData*)item);
            send_6x25_equip_item((void *)player, *(s32 *)((s8 *)item + 0xC), 0);
        }
    }
}
void TLobby::handle_player_event(s32 arg0, s32 arg1) {
    s32 player;
    u32 var_r3;
    player = get_player_by_client_id((u16)arg0);
    if ((player != 0) && ((is_locally_controlled__10TObjPlayerFPv() == 1) || ((obj_isState3_324__13TUnk_804806E8Fv(player) == 1) && ((s32) local_client_id == (s32) TLobby__designated_client_id)) || ((is_script_controlled__10TObjPlayerFv(player) == 1) && ((s32) local_client_id == (s32) TLobby__designated_client_id)))) {
        var_r3 = 0U;
        switch (arg1) {
        case 0:
            var_r3 = get_item_field_6__10TObjPlayerFPv((void *)player);
            break;
        case 1:
            var_r3 = ((TItemData *)player)->get_item_field_2();
            break;
        case 2:
            var_r3 = ((TItemData *)player)->test_flag3();
            break;
        case 3:
            var_r3 = ((TObjPlayer *)player)->activate_d04_slot();
            break;
        case 4:
        case 5:
        case 6:
        case 7:
            var_r3 = get_equip_field_d04__10TObjPlayerFl(player, arg1 + 5);
            break;
        default:
            break;
        }
        if (var_r3 != 0U) {
            send_6x26_unequip_item__10TObjPlayerFPvPv((void *)player, (void *)(get_item_id__5TItemFv()));
        }
    }
}
