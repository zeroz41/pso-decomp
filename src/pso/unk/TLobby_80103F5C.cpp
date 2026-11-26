#include "pso/network/protocol/ItemDropPacket.h"
#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/system/memory.h"
#include <string.h>
#include "pso/unk/TLobby_801E43E4.h"
#include "types.h"
#include "pso/unk/TLobby_80103F5C.h"
#include "pso/weapon/TItemWeapon.h"
#include "pso/system/data/FlagWord.h"
#include "pso/network/protocol/protocol_types.h"
#include "pso/item/TItemObject.h"
#include "pso/system/byteswap.h"
#include "pso/network/protocol/subcmd_6x.h"
#include <stddef.h>
#include "pso/network/TLobby.h"
#include "pso/item/TItemData.h"
#include "pso/player/TObjPlayer.h"
#include "pso/item/TItemToolMate.h"
#include "pso/item/TItemToolFluid.h"
#include "pso/item/TItemToolTechniqueDisk.h"
#include "pso/item/TItemToolSolAtomizer.h"
#include "pso/item/TItemToolMoonAtomizer.h"
#include "pso/item/TItemToolStarAtomizer.h"
#include "pso/item/TItemToolStatusCure.h"
#include "pso/item/TItemToolTelepipe.h"
#include "pso/item/TItemToolTrapVision.h"
#include "pso/item/TItemToolGrinder.h"
#include "pso/item/TItemToolMaterial.h"
#include "pso/item/TItemToolMagCell.h"
#include "pso/item/TItemToolAddSlot.h"
#include "pso/item/TUnk_804F112C.h"
#include "pso/item/TItemToolRandomItem.h"
#include "pso/item/TItemToolQuestBgm.h"
#include "pso/item/TItemToolKillCounter.h"
#include "pso/item/TItem.h"
#include "pso/unk/text_801036CC.h"
#include "pso/system/task/TObject.h"

#include "pso/object/base/TObjChara.h"
#include "pso/enemy/TObjEneBeastBase.h"
#include "pso/object/base/CollisionActorLookup.h"
#include "pso/network/client_id.h"
#include "pso/item/item_create.h"
#include "pso/unk/TLobby_80103F5C.h"










extern "C" {
FloorItem *floor_item_entry_pool;
ApplySyncItemStateEntry **floor_item_row_table;
s32 *floor_item_counts_by_floor;
u16 *floor_item_free_id_stack;
int floor_item_free_id_count;
u16 *floor_item_next_sort_keys;
FlagWord lbl_805D5430;
void *__construct_new_array(void *block, void *ctor, void *dtor, size_t size, size_t n);
void __ct__9FloorItemFv(FloorItem *item, s32 mode);
}
void build_6x63_packet(void *packet);
extern "C" {
void TLobby__sub_801041D8(void);
}
void bswap_sync_item_state_header(G_SyncItemState_6x6D_Decompressed *header);
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
extern "C" {
extern void *tl_05;
}
extern "C" {
extern s32 lbl_805D5440;
void spawn_dropped_item_from_msg(void *, s32);
}

void reset_map(void) {
    s32 i;
    TLobbyPlayer *p;
    for (i = 0; i != TLobby::get_lobby_flag(); i++) {
        p = (TLobbyPlayer *)TObjPlayer::get_player_data(i);
        if (p != NULL && ((TObjEneBeastBase *)p)->test_elt_flag(0, 0x20000) != 0 && p->owner == tl_05) {
            ((TObject *)p)->queue_destruction();
        }
    }
    TLobby::reset_floor_items();
}
void evict_lowest_key_floor_item(s32 n);
void handle_6x63_destroy_floor_item(void *command) {
    TItem *o;
    G_DestroyFloorItem_6x5C_6x63 *destroy = (G_DestroyFloorItem_6x5C_6x63 *)command;

    ((TLobby *)command)->bswap_player_packet();
    remove_item_condition((s32)destroy->floor, (s32)destroy->item_id);
    o = find_item_by_id(destroy->item_id);
    if (o != NULL) {
        o->destroy();
    }
}

void evict_lowest_key_floor_item(s32 n) {
    EvictLowestKeyFloorItemMsg m;
    s32 best;
    u16 bestKey;
    s32 i;
    s32 v;
    if (local_client_id == designated_client_id) {
        bestKey = 0xFFFF;
        best = 0;
        for (i = 0; i != floor_item_counts_by_floor[n]; i++) {
            if (floor_item_row_table[n][i].key < bestKey) {
                best = i;
                bestKey = floor_item_row_table[n][i].key;
            }
        }
        v = floor_item_row_table[n][best].item_id;
        build_6x63_packet(&m);
        m.v = v;
        m.who = n;
        ((TLobby *)(&m))->update_and_send();
    }
}

s32 TLobby::is_stat_over_limit(s32 floor) {
    if ((floor >= 0) && (floor < 0x12) && ((s32) floor_item_counts_by_floor[floor] < 0x32)) {
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
    ApplySyncItemStateEntry *p;
    s32 n;
    TLobby::reset_floor_items();
    bswap_sync_item_state_header((G_SyncItemState_6x6D_Decompressed *)this);
    for (i = 0; i < 0x10; i++) {
        floor_item_next_sort_keys[i] = ((ApplySyncItemStateSave *)this)->slots[i];
    }
    for (b = 0; b != 0xC; b++) {
        set_boss_buf_entry(((ApplySyncItemStateSave *)this)->boss[b], b);
    }
    for (i = 0; i < 0xF; i++) {
        floor_item_counts_by_floor[i] = ((ApplySyncItemStateSave *)this)->counts[i];
    }
    k = 0;
    for (j = 0; j != 0xF; j++) {
        count = floor_item_counts_by_floor[j];
        p = floor_item_row_table[j];
        for (n = 0; n != count; n++, p++) {
            TLobby::copy_floor_item_entry((TLobbyFloorItemEntry *)p, (TLobbyFloorItemEntry *)&((ApplySyncItemStateSave *)this)->items[k++]);
            bswap_item__6TLobbyFv(p);
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
    WriteSyncItemStateSave *dst = (WriteSyncItemStateSave *)this;
    s32 k;
    ApplySyncItemStateEntry *d;
    s32 j;
    s32 count;
    ApplySyncItemStateEntry *p;
    s32 n;
    for (i = 0; i < 0x10; i++) {
        dst->slots[i] = floor_item_next_sort_keys[i];
    }
    for (b = 0; b != 0xC; b++) {
        dst->boss[b] = TLobby::get_sync_counter(b);
    }
    for (i = 0; i < 0xF; i++) {
        dst->counts[i] = floor_item_counts_by_floor[i];
    }
    d = dst->items;
    k = 0;
    for (j = 0; j != 0xF; j++) {
        count = floor_item_counts_by_floor[j];
        p = floor_item_row_table[j];
        for (n = 0; n != count; n++, p++, k++) {
            TLobby::copy_floor_item_entry((TLobbyFloorItemEntry *)d, (TLobbyFloorItemEntry *)p);
            ((TItemData *)((u8 *)d + 0x10))->encode_for_network();
            bswap_item__6TLobbyFv(d);
            d++;
        }
    }
    i = k * 0x24 + 0x8C;
    bswap_sync_item_state_header((G_SyncItemState_6x6D_Decompressed *)dst);
    return i;
}
#pragma pop

u16 pop_free_entity_id() {
    s32 count;
    if (floor_item_free_id_count != 0) {
        count = floor_item_free_id_count - 1;
        floor_item_free_id_count = count;
        return floor_item_free_id_stack[count];
    }
    return 0xFFFFU;
}

s32 push_free_entity_id(u16 id) {
  if ((floor_item_free_id_count < 0x20) && (id != 0xFFFF))
  {
    floor_item_free_id_stack[floor_item_free_id_count] = id;
    floor_item_free_id_count += 1;
    return 1;
  }
  return 0;
}

s32 TLobby::is_entry_valid(s32 floor) {
    if (((s32) floor_item_counts_by_floor[floor] < 0xC0) && (floor < 0x12)) {
        return 1;
    }
    return 0;
}

void TLobby::respawn_missing_floor_items(s32 n) {
    s32 i;
    if (n < 0x12) {
        if (floor_item_row_table[n] != 0) {
            for (i = 0; i != floor_item_counts_by_floor[n]; i++) {
                ApplySyncItemStateEntry *e = &floor_item_row_table[n][i];
                if (find_item_by_id(e->item_id) == 0) {
                    spawn_dropped_item_from_msg(e, 1);
                }
            }
        }
    }
}

s32 remove_item_condition(s32 floor, s32 item_id) {
    ApplySyncItemStateEntry *list;
    s32 count;
    s32 lo;
    s32 mid;
    s32 hi;
    if (floor >= 0x12) {
        return 0;
    }
    list = floor_item_row_table[floor];
    if (list != NULL) {
        count = floor_item_counts_by_floor[floor];
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
            floor_item_counts_by_floor[floor]--;
            ((FloorItem *)(&list[floor_item_counts_by_floor[floor]]))->clear();
            return 1;
        }
        return 0;
    }
    TLobby::debug_print("ItemCondition AreaOffset Lost");
    return 0;
}
FloorItemEntry *find_item_condition(s32 floor, s32 item_id) {
    ApplySyncItemStateEntry *list;
    s32 count;
    s32 lo;
    s32 mid;
    s32 hi;
    ApplySyncItemStateEntry *p;
    if (floor >= 0x12) {
        return NULL;
    }
    list = floor_item_row_table[floor];
    if (list != NULL) {
        count = floor_item_counts_by_floor[floor];
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
    InsertItemConditionEntry *list;
    s32 lo;
    s32 mid;
    s32 n;
    s32 val;
    s32 hi;
    InsertItemConditionEntry *p;
    if (item != NULL) {
        if (TLobby::is_stat_over_limit(item->floor) != 0) {
            evict_lowest_key_floor_item(item->floor);
        }
        if (item->floor < 0x12 && TLobby::is_entry_valid(item->floor) != 0) {
            idx = item->floor;
            list = (*(InsertItemConditionEntry ** *)&floor_item_row_table)[idx];
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
                    memcpy(p + 1, p, (n - lo) * sizeof(InsertItemConditionEntry));
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

void TLobby::clear_object_count() { floor_item_free_id_count = 0; }

void TLobby::reset_floor_items() {
    s32 i;
    s32 j;
    s32 k;
    for (i = 0; i != 0xD80; i++) {
        if (floor_item_entry_pool != NULL) {
            floor_item_entry_pool[i].clear();
        }
    }
    for (j = 0; j < 0x12; j++) {
        if (floor_item_next_sort_keys != NULL) {
            floor_item_next_sort_keys[j] = 0;
        }
    }
    for (k = 0; k < 0x12; k++) {
        if (floor_item_row_table != NULL && floor_item_entry_pool != NULL && floor_item_counts_by_floor != NULL) {
            floor_item_row_table[k] = (ApplySyncItemStateEntry *)&floor_item_entry_pool[k * 0xC0];
            floor_item_counts_by_floor[k] = 0;
        }
    }
    TLobby::clear_object_count();
}

void TLobby::free_boss_rocks() {
    mem_free((void *)floor_item_next_sort_keys);
    floor_item_next_sort_keys = 0;
    mem_free(floor_item_free_id_stack);
    floor_item_free_id_stack = NULL;
    floor_item_free_id_count = 0;
    mem_free((void *)floor_item_counts_by_floor);
    floor_item_counts_by_floor = 0;
    mem_free((void *)floor_item_row_table);
    floor_item_row_table = 0;
    if (floor_item_entry_pool != NULL) {
        mem_free((char *)floor_item_entry_pool - 0x10);
    }
    floor_item_entry_pool = NULL;
    lbl_805D5430.reset();
}
void TLobby::alloc_objects() {
    floor_item_entry_pool = static_cast<FloorItem *>(
        __construct_new_array(mem_alloc(0x1E610), reinterpret_cast<void *>(__ct__9FloorItemFv), NULL, 0x24, 0xD80));
    floor_item_row_table = static_cast<ApplySyncItemStateEntry **>(mem_alloc(0x48));
    floor_item_counts_by_floor = static_cast<s32 *>(mem_alloc(0x48));
    floor_item_free_id_stack = static_cast<u16 *>(mem_alloc(0x40));
    floor_item_free_id_count = 0;
    floor_item_next_sort_keys = static_cast<u16 *>(mem_alloc(0x24));
    lbl_805D5430.reset();
    TLobby::reset_floor_items();
}
int TLobby::get_lobby_flag() {  return entity_table_count; }
void TLobby::bswap_player_packet() { ((G_ClientIDHeader *)this)->bswap(); bswap_32((u32 *)((char*)this + 0x4)); bswap_32((u32 *)((char*)this + 0x8)); }
void TLobby::update_and_send() { bswap_player_packet(); send_subcommand((u8 *)this); }
void build_6x63_packet(void *packet) {
    G_DestroyFloorItem_6x5C_6x63 *destroy = (G_DestroyFloorItem_6x5C_6x63 *)packet;
    destroy->item_id = -1;
    destroy->header.subcommand = 0x63;
    destroy->header.size = 3;
}
void TLobby__sub_801041D8(void) {
    lbl_805D5430.set(1);
}
void bswap_item__6TLobbyFv(void *record) {
    u8 *bytes = static_cast<u8 *>(record);
    bswap_16(reinterpret_cast<u16 *>(bytes + 2));
    bswap_32(reinterpret_cast<u32 *>(bytes + 4));
    bswap_32(reinterpret_cast<u32 *>(bytes + 8));
    bswap_16(reinterpret_cast<u16 *>(bytes + 0xC));
    bswap_16(reinterpret_cast<u16 *>(bytes + 0xE));
    reinterpret_cast<TItemData *>(bytes + 0x10)->bswap();
}

TLobbyFloorItemEntry *TLobby::copy_floor_item_entry(TLobbyFloorItemEntry *dst, TLobbyFloorItemEntry *src) {
    *dst = *src;
    return dst;
}

LAYOUT_ASSERT(SyncItemHeaderPlayerIds, offsetof(G_SyncItemState_6x6D_Decompressed, next_item_id_per_player) == 0x20);
LAYOUT_ASSERT(SyncItemHeaderFloorCounts, offsetof(G_SyncItemState_6x6D_Decompressed, floor_item_count_per_floor) == 0x50);
LAYOUT_ASSERT(SyncItemHeaderSize, sizeof(G_SyncItemState_6x6D_Decompressed) == 0x8C);
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
