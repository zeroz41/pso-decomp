#include "pso/misc/TLobby_801E43E4.h"
#include "types.h"
#include "pso/player/TObjPlayer_80120FC4.h"
#include "pso/system/FlagWord.h"
#include "pso/protocol/protocol_types.h"
#include "pso/item/TItemObject.h"
#include "pso/system/byteswap.h"
#include "pso/protocol/subcmd_6x.h"
#include <stddef.h>
#include "pso/misc/TLobby.h"
#include "pso/item/TItemData.h"
#include "pso/player/TObjPlayer.h"
#include "pso/item/TUnk_8049F770.h"
#include "pso/item/TUnk_8049FE00.h"
#include "pso/item/TUnk_8049FC90.h"
#include "pso/item/TUnk_8049FA50.h"
#include "pso/item/TUnk_8049F8E0.h"
#include "pso/item/TUnk_8049FB08.h"
#include "pso/item/TUnk_8049F998.h"
#include "pso/item/TUnk_8049FD48.h"
#include "pso/item/TUnk_8049FED0.h"
#include "pso/item/TUnk_8049FF88.h"
#include "pso/unk/TUnk_8049FBC0.h"
#include "pso/item/TUnk_8049F828.h"
#include "pso/enemy/TUnk_804E6FA8.h"
#include "pso/item/TUnk_804F112C.h"
#include "pso/unk/TUnk_804F0C48.h"
#include "pso/item/TUnk_804F0D34.h"
#include "pso/unk/TUnk_804F0FF0.h"
#include "pso/item/TItem.h"
#include "pso/unk/text_801036CC.h"

struct In_8010440C { u8 pad0; u8 idx; };

struct In_80104438 { u8 pad0; u8 idx; };

struct Ent_80103F68 { u8 pad[0x24]; };

struct Base_80103748 { char pad[0x18]; };
struct VObj_80103748 : Base_80103748 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual void m8();
    virtual void m9();
    virtual void m10();
    virtual void m11();
    virtual void m12();
    virtual void m13();
    virtual void m14();
    virtual void m15();
    virtual void m16();
    virtual void m17();
    virtual void m18();
    virtual void m19();
    virtual void m20();
    virtual void m21();
    virtual void m22();
    virtual void m23();
    virtual void m24();
    virtual void m25();
    virtual void m26();
    virtual void m27();
};

struct Player_801036CC { u8 pad[0x10]; void *owner; };

struct Ent_801037A0 { u8 pad0[0xE]; u16 key; u8 padx[0xC]; s32 item_id; u8 pad2[4]; };

struct Msg_801037A0 { u32 hdr; s32 v; s32 who; };

struct Save_80103890 {
    u16 slots[0x10];
    s32 boss[0xC];
    s32 counts[0xF];
    Ent_801037A0 items[1];
};

struct Ent_80103DD8 { s8 n; u8 pad1[0xD]; u16 key; u8 padx[0xC]; s32 val; u8 pad2[4]; };

struct Save_801039BC {
    u16 slots[0x10];
    s32 boss[0xC];
    s32 counts[0xF];
    Ent_801037A0 items[1];
};

extern "C" {
void mem_free(void *p);
extern u32 TLobby__floor_item_entry_pool;
extern Ent_801037A0 **floor_item_row_table;
extern s32 floor_item_counts_by_floor;
extern s32 floor_item_free_id_stack;
extern int floor_item_free_id_count;
extern u16 *floor_item_next_sort_keys;
extern s32 lbl_805D5430;
s32 __construct_new_array(s32, s32 *, s32, s32, s32);
s32 mem_alloc(s32);
extern s32 __ct__9FloorItemFv[];
    extern int lbl_805D5868;
void TLobby__sub_801041BC(void *arg0);
void TLobby__sub_801041D8(void);
void bswap_sync_item_state_header(G_SyncItemState_6x6D_Decompressed *header);
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
s32 obj_isState3_324__9TObjCharaFv(s32);
extern s32 local_client_id;
extern s32 TLobby__designated_client_id;
void send_6x26_unequip_item__10TObjPlayerFPvPv(void *self, void *item);
s32 get_item_id__5TItemFv();
int get_item_field_6__10TObjPlayerFPv(void *p);
void *TLobby__sub_8010440C(In_8010440C *arg0);
void *get_weapon_factory_for_item(In_80104438 *arg0);
int is_quest_active(void);
s32 TItemDropSub__sub_80107B74();
}

#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off

extern "C" {
int get_player_data__10TObjPlayerFi(int a0);
s32 test_elt_flag__13TUnk_80493450Fll(void *p, s32 a, s32 mask);
void queue_destruction__7TObjectFv(void *);
extern void *tl_05;
void TLobby__sub_801036CC(void);
void set_boss_buf_entry__6TLobbyFii(s32, u16);
s32 test_flags_any(void *, s32);
extern s32 lbl_805D5440;
void *memcpy(void *, const void *, u32);
void spawn_dropped_item_from_msg(void *, s32);
s32 get_sync_counter__6TLobbyFi(u16);
s32 bswap_player_packet__6TLobbyFv();

void TLobby__sub_801036CC(void) {
    s32 i;
    Player_801036CC *p;
    for (i = 0; i != TLobby::get_lobby_flag(); i++) {
        p = (Player_801036CC *)get_player_data__10TObjPlayerFi(i);
        if (p != NULL && test_elt_flag__13TUnk_80493450Fll(p, 0, 0x20000) != 0 && p->owner == tl_05) {
            queue_destruction__7TObjectFv(p);
        }
    }
    TLobby::reset_floor_items();
}
}
void evict_lowest_key_floor_item(s32 n);
void handle_6x63_destroy_floor_item(void *arg0) {
    struct VObj_80103748 *o;

    bswap_player_packet__6TLobbyFv();
    remove_item_condition((s32)(*(s32 *)((s8 *)arg0 + 8)), (s32)(*(s32 *)((s8 *)arg0 + 4)));
    o = (struct VObj_80103748 *)find_item_by_id(*(s32 *)((s8 *)arg0 + 4));
    if (o != NULL) {
        o->m27();
    }
}

void evict_lowest_key_floor_item(s32 n) {
    Msg_801037A0 m;
    s32 best;
    u16 bestKey;
    s32 i;
    s32 v;
    if (local_client_id == TLobby__designated_client_id) {
        bestKey = 0xFFFF;
        best = 0;
        for (i = 0; i != (*(s32 * *)&floor_item_counts_by_floor)[n]; i++) {
            if (floor_item_row_table[n][i].key < bestKey) {
                best = i;
                bestKey = floor_item_row_table[n][i].key;
            }
        }
        v = floor_item_row_table[n][best].item_id;
        TLobby__sub_801041BC(&m);
        m.v = v;
        m.who = n;
        ((TLobby *)(&m))->update_and_send();
    }
}

s32 TLobby::is_stat_over_limit(s32 arg0) {
    if ((arg0 >= 0) && (arg0 < 0x12) && ((s32) *(s32 *)((s8 *)floor_item_counts_by_floor + (arg0 * 4)) < 0x32)) {
        return 0;
    }
    return 1;
}

void TLobby::apply_sync_item_state() {
    s32 i;
    u16 b;
    s32 k;
    s32 j;
    s32 count;
    Ent_801037A0 *p;
    s32 n;
    TLobby::reset_floor_items();
    bswap_sync_item_state_header((G_SyncItemState_6x6D_Decompressed *)this);
    for (i = 0; i < 0x10; i++) {
        floor_item_next_sort_keys[i] = ((Save_80103890 *)this)->slots[i];
    }
    for (b = 0; b != 0xC; b++) {
        set_boss_buf_entry__6TLobbyFii(((Save_80103890 *)this)->boss[b], b);
    }
    for (i = 0; i < 0xF; i++) {
        (*(s32 **)&floor_item_counts_by_floor)[i] = ((Save_80103890 *)this)->counts[i];
    }
    k = 0;
    for (j = 0; j != 0xF; j++) {
        count = (*(s32 **)&floor_item_counts_by_floor)[j];
        p = floor_item_row_table[j];
        for (n = 0; n != count; n++, p++) {
            TLobby::copy_floor_item_entry((TLobbyFloorItemEntry *)p, (TLobbyFloorItemEntry *)&((Save_80103890 *)this)->items[k++]);
            ((TLobby *)p)->bswap_item();
            ((TItemData *)((u8 *)p + 0x10))->decode_from_network();
        }
    }
    if (test_flags_any(&lbl_805D5440, 1) != 0) {
        TLobby::respawn_missing_floor_items(0);
    }
    TLobby__sub_801041D8();
}

#pragma push
#pragma opt_propagation off
s32 TLobby::write_sync_item_state() {
    s32 i;
    u16 b;
    Save_801039BC *dst = (Save_801039BC *)this;
    s32 k;
    Ent_801037A0 *d;
    s32 j;
    s32 count;
    Ent_801037A0 *p;
    s32 n;
    for (i = 0; i < 0x10; i++) {
        dst->slots[i] = floor_item_next_sort_keys[i];
    }
    for (b = 0; b != 0xC; b++) {
        dst->boss[b] = get_sync_counter__6TLobbyFi(b);
    }
    for (i = 0; i < 0xF; i++) {
        dst->counts[i] = (*(s32 **)&floor_item_counts_by_floor)[i];
    }
    d = dst->items;
    k = 0;
    for (j = 0; j != 0xF; j++) {
        count = (*(s32 **)&floor_item_counts_by_floor)[j];
        p = floor_item_row_table[j];
        for (n = 0; n != count; n++, p++, k++) {
            TLobby::copy_floor_item_entry((TLobbyFloorItemEntry *)d, (TLobbyFloorItemEntry *)p);
            ((TItemData *)((u8 *)d + 0x10))->encode_for_network();
            ((TLobby *)d)->bswap_item();
            d++;
        }
    }
    i = k * 0x24 + 0x8C;
    bswap_sync_item_state_header((G_SyncItemState_6x6D_Decompressed *)dst);
    return i;
}
#pragma pop

u16 pop_free_entity_id() {
    s32 temp_r0;
    if ((s32) floor_item_free_id_count != 0) {
        temp_r0 = floor_item_free_id_count - 1;
        floor_item_free_id_count = temp_r0;
        return *(u16 *)((s8 *)(floor_item_free_id_stack + (temp_r0 * 2)) + 0);
    }
    return 0xFFFFU;
}

s32 push_free_entity_id(u16 id) {
  if ((floor_item_free_id_count < 0x20) && (id != (((((((((-1) & 0xFFFF) & 0xFFFF) & 0xFFFF) & 0xFFFF) & 0xFFFF) & 0xFFFF) & 0xFFFF) & 0xFFFF)))
  {
    *((u16 *) (((s8 *) (floor_item_free_id_stack + (floor_item_free_id_count * 2))) + 0)) = id;
    floor_item_free_id_count += 1;
    return 1;
  }
  return 0;
}

s32 TLobby::is_entry_valid(s32 arg0) {
    if (((s32) *(s32 *)((s8 *)floor_item_counts_by_floor + (arg0 * 4)) < 0xC0) && (arg0 < 0x12)) {
        return 1;
    }
    return 0;
}

void TLobby::respawn_missing_floor_items(s32 n) {
    s32 i;
    if (n < 0x12) {
        if (floor_item_row_table[n] != 0) {
            for (i = 0; i != (*(s32 **)&floor_item_counts_by_floor)[n]; i++) {
                Ent_801037A0 *e = &floor_item_row_table[n][i];
                if (find_item_by_id(e->item_id) == 0) {
                    spawn_dropped_item_from_msg(e, 1);
                }
            }
        }
    }
}

s32 remove_item_condition(s32 floor, s32 item_id) {
    Ent_801037A0 *list;
    s32 count;
    s32 lo;
    s32 mid;
    s32 hi;
    if (floor >= 0x12) {
        return 0;
    }
    list = floor_item_row_table[floor];
    if (list != NULL) {
        count = (*(s32 **)&floor_item_counts_by_floor)[floor];
        if (count == 0) {
            return 0;
        }
        hi = count - 1;
        lo = 0;
        while (lo < hi) {
            mid = (lo + hi) / 2;
            if (list[mid].item_id < item_id) {
                lo = mid + 1;
            } else {
                hi = mid;
            }
        }
        if (item_id == list[lo].item_id) {
            memcpy(&list[lo], &list[lo + 1], (count - (lo + 1)) * 0x24);
            (*(s32 **)&floor_item_counts_by_floor)[floor]--;
            ((FloorItem *)(&list[(*(s32 **)&floor_item_counts_by_floor)[floor]]))->clear();
            return 1;
        }
        return 0;
    }
    TLobby::debug_print("ItemCondition AreaOffset Lost");
    return 0;
}
FloorItemEntry *find_item_condition(s32 floor, s32 item_id) {
    Ent_801037A0 *list;
    s32 count;
    s32 lo;
    s32 mid;
    s32 hi;
    Ent_801037A0 *p;
    if (floor >= 0x12) {
        return NULL;
    }
    list = floor_item_row_table[floor];
    if (list != NULL) {
        count = (*(s32 **)&floor_item_counts_by_floor)[floor];
        if (count == 0) {
            return NULL;
        }
        hi = count - 1;
        lo = 0;
        while (lo < hi) {
            mid = (lo + hi) >> 1;
            if (list[mid].item_id < item_id) {
                lo = mid + 1;
            } else {
                hi = mid;
            }
        }
        p = &list[lo];
        if (item_id == p->item_id) {
            return (FloorItemEntry *)p;
        }
        return NULL;
    }
    TLobby::debug_print("ItemCondition AreaOffset Lost");
    return NULL;
}
s32 insert_item_condition(FloorItem *item) {
    s32 *counts;
    s32 idx;
    Ent_80103DD8 *list;
    s32 lo;
    s32 mid;
    s32 n;
    s32 val;
    s32 hi;
    Ent_80103DD8 *p;
    if (item != NULL) {
        if (TLobby::is_stat_over_limit(item->floor) != 0) {
            evict_lowest_key_floor_item(item->floor);
        }
        if (item->floor < 0x12 && TLobby::is_entry_valid(item->floor) != 0) {
            idx = item->floor;
            list = (*(Ent_80103DD8 ** *)&floor_item_row_table)[idx];
            if (list != NULL) {
                counts = *(s32 **)&floor_item_counts_by_floor;
                val = item->item.id;
                n = counts[idx];
                hi = n - 1;
                if (hi > -1 && val < list[hi].val) {
                    lo = 0;
                    while (lo < hi) {
                        mid = (lo + hi) / 2;
                        if (list[mid].val < val) {
                            lo = mid + 1;
                        } else {
                            hi = mid;
                        }
                    }
                    p = &list[lo];
                    if (val == p->val) {
                        return 0;
                    }
                    memcpy(p + 1, p, (n - lo) * sizeof(Ent_80103DD8));
                } else {
                    lo = n;
                }
                item->drop_number = floor_item_next_sort_keys[item->floor];
                if (floor_item_next_sort_keys[item->floor] != 0xFFFF) {
                    floor_item_next_sort_keys[item->floor]++;
                }
                TLobby::copy_floor_item_entry((TLobbyFloorItemEntry *)&list[lo], (TLobbyFloorItemEntry *)item);
                counts[idx]++;
                return 1;
            }
        }
    }
    return 0;
}


extern void *weapon_factory_table[];
// Tool item factories, indexed by the tool type byte (TLobby__sub_8010440C).
void *item_tool_factory_table[24] = {
    (void *)TUnk_8049F770::create,
    (void *)TUnk_8049FE00::create,
    (void *)create_technique_disk_item,
    (void *)create_sol_atomizer_item,
    (void *)create_moon_atomizer_item,
    (void *)create_star_atomizer_item,
    (void *)create_status_cure_item,
    (void *)create_telepipe_item,
    (void *)TUnk_8049FED0::create,
    (void *)TItemObject::create,
    (void *)create_item_grinder,
    (void *)create_material_item,
    (void *)TUnk_8049F828::create,
    (void *)TItemObject::create,
    (void *)TItemObject::create,
    (void *)create_add_slot_item,
    (void *)TItemObject::create,
    (void *)TItemObject::create,
    (void *)TItemObject::create,
    (void *)TItemObject::create,
    (void *)TUnk_804F112C::create,
    (void *)TUnk_804F0C48::create,
    (void *)TUnk_804F0D34::create,
    (void *)TUnk_804F0FF0::create,
};

void normalize_drop_area(s32 *p);
extern "C" {
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
        if (floor_item_next_sort_keys != NULL) {
            floor_item_next_sort_keys[j] = 0;
        }
    }
    for (k = 0; k < 0x12; k++) {
        if (floor_item_row_table != NULL && *(Ent_80103F68 **)&TLobby__floor_item_entry_pool != NULL && *(s32 **)&floor_item_counts_by_floor != NULL) {
            floor_item_row_table[k] = (Ent_801037A0 *)&(*(Ent_80103F68 **)&TLobby__floor_item_entry_pool)[k * 0xC0];
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
    ((FlagWord *)(&lbl_805D5430))->reset();
}
void TLobby::alloc_objects() {
    (*(s32 *)&TLobby__floor_item_entry_pool) = __construct_new_array(mem_alloc(0x1E610), __ct__9FloorItemFv, 0, 0x24, 0xD80);
    floor_item_row_table = (Ent_801037A0 **)mem_alloc(0x48);
    floor_item_counts_by_floor = mem_alloc(0x48);
    floor_item_free_id_stack = mem_alloc(0x40);
    (*(s32 *)&floor_item_free_id_count) = 0;
    floor_item_next_sort_keys = (u16 *)mem_alloc(0x24);
    ((FlagWord *)(&lbl_805D5430))->reset();
    TLobby::reset_floor_items();
}
int TLobby::get_lobby_flag() {  return lbl_805D5868; }
void TLobby::bswap_player_packet() { ((G_ClientIDHeader *)this)->bswap(); bswap_32((u32 *)((char*)this + 0x4)); bswap_32((u32 *)((char*)this + 0x8)); }
void TLobby::update_and_send() { bswap_player_packet(); send_subcommand((u8 *)this); }
void TLobby__sub_801041BC(void *arg0) {
    *(s32 *)((s8 *)arg0 + 4) = -1;
    *(s8 *)((s8 *)arg0 + 0) = 0x63;
    *(s8 *)((s8 *)arg0 + 1) = 3;
}
void TLobby__sub_801041D8(void) {
    ((FlagWord *)(&lbl_805D5430))->set(1);
}
void TLobby::bswap_item() { bswap_16((u16 *)((char*)this + 0x2)); bswap_32((u32 *)((char*)this + 0x4)); bswap_32((u32 *)((char*)this + 0x8)); bswap_16((u16 *)((char*)this + 0xc)); bswap_16((u16 *)((char*)this + 0xe)); bswap__9TItemDataFv((s32)((char*)this + 0x10)); }

TLobbyFloorItemEntry *TLobby::copy_floor_item_entry(TLobbyFloorItemEntry *dst, TLobbyFloorItemEntry *src) {
    *dst = *src;
    return dst;
}

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
    __ct__8FlagWordFv((&lbl_805D5430));
}

__declspec(section ".ctors") static void *const __sinit_TLobby_80103F5C_cpp_ref = (void *)TLobby__sub_80104350;

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
    return (void *)TItemObject::create;
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
            s32 remap[17] = { 1, 2, 3, 4, 8, 5, 6, 7, 8, 9, 10, 9, 10, 3, 5, 8, 10 };
            *p = remap[(u32)(v - 0x13)];
        }
    }
}

void TLobby::forward_to_player(int arg0, void *item) {
    s32 player;
    if (item != NULL) {
        player = get_player_by_client_id(arg0);
        if ((player != 0) && ((is_locally_controlled__10TObjPlayerFPv() == 1) || ((obj_isState3_324__9TObjCharaFv(player) == 1) && ((s32) local_client_id == (s32) TLobby__designated_client_id)) || ((is_script_controlled__10TObjPlayerFv(player) == 1) && ((s32) local_client_id == (s32) TLobby__designated_client_id)))) {
            ((TObjPlayer *)player)->request_inventory_item((TItemData*)item);
            send_6x25_equip_item((void *)player, *(s32 *)((s8 *)item + 0xC), 0);
        }
    }
}
void TLobby::handle_player_event(s32 arg0, s32 arg1) {
    s32 player;
    u32 var_r3;
    player = get_player_by_client_id((u16)arg0);
    if ((player != 0) && ((is_locally_controlled__10TObjPlayerFPv() == 1) || ((obj_isState3_324__9TObjCharaFv(player) == 1) && ((s32) local_client_id == (s32) TLobby__designated_client_id)) || ((is_script_controlled__10TObjPlayerFv(player) == 1) && ((s32) local_client_id == (s32) TLobby__designated_client_id)))) {
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
            var_r3 = (u32)((TObjPlayer *)player)->get_equipped_item(arg1 + 5);
            break;
        default:
            break;
        }
        if (var_r3 != 0U) {
            send_6x26_unequip_item__10TObjPlayerFPvPv((void *)player, (void *)(get_item_id__5TItemFv()));
        }
    }
}
