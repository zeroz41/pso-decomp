#include "pso/network/protocol/ItemDropPacket.h"
#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/system/memory.h"
#include <string.h>
#include "pso/network/TGameProtocol.h"
#include "types.h"
#include "pso/item/FloorItemSync.h"
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
#include "pso/item/ItemUseEffects.h"
#include "pso/item/TItemToolRandomItem.h"
#include "pso/item/TItemToolQuestBgm.h"
#include "pso/item/TItemToolKillCounter.h"
#include "pso/item/TItem.h"
#include "pso/system/task/TObject.h"

#include "pso/object/base/TObjChara.h"
#include "pso/enemy/TObjEneBeastBase.h"
#include "pso/object/base/CollisionActorLookup.h"
#include "pso/network/client_id.h"
#include "pso/item/item_create.h"
#include "pso/system/task/TMainTask.h"
#include "pso/system/FileExtension.h"

extern "C" {
FloorItem *floor_item_entry_pool;
FloorItem **floor_item_row_table;
s32 *floor_item_counts_by_floor;
u16 *floor_item_free_id_stack;
int floor_item_free_id_count;
u16 *floor_item_next_sort_keys;
FlagWord floor_items_synced_flags;
}
extern "C" {
void set_floor_items_synced_flag(void);
}
void bswap_sync_item_state_header(G_SyncItemState_6x6D_Decompressed *header);
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
void reset_map(void) {
    s32 i;
    TLobbyPlayer *p;
    for (i = 0; i != TLobby::get_lobby_flag(); i++) {
        p = (TLobbyPlayer *)TObjPlayer::get_player_data(i);
        if (p != NULL && ((TObjEneBeastBase *)p)->test_elt_flag(0, 0x20000) != 0 && p->owner == tl_05) {
            ((TObject *)p)->queue_destruction();
        }
    }
    reset_floor_items();
}
void evict_lowest_key_floor_item(s32 n);
void handle_6x63_destroy_floor_item(G_DestroyFloorItem_6x63 *destroy) {
    TItem *o;

    destroy->bswap();
    remove_item_condition((s32)destroy->floor, (s32)destroy->item_id);
    o = find_item_by_id(destroy->item_id);
    if (o != NULL) {
        o->destroy();
    }
}

void evict_lowest_key_floor_item(s32 n) {
    G_DestroyFloorItem_6x63 m;
    s32 best;
    u16 bestKey;
    s32 i;
    s32 v;
    if (local_client_id == designated_client_id) {
        bestKey = 0xFFFF;
        best = 0;
        for (i = 0; i != floor_item_counts_by_floor[n]; i++) {
            if (floor_item_row_table[n][i].drop_number < bestKey) {
                best = i;
                bestKey = floor_item_row_table[n][i].drop_number;
            }
        }
        v = floor_item_row_table[n][best].item.id;
        build_6x63_packet(&m);
        m.item_id = v;
        m.floor = n;
        m.send();
    }
}

s32 is_stat_over_limit(s32 floor) {
    if ((floor >= 0) && (floor < 0x12) && ((s32) floor_item_counts_by_floor[floor] < 0x32)) {
        return 0;
    }
    return 1;
}

void G_SyncItemState_6x6D_Decompressed::apply() {
    s32 i;
    u16 b;
    s32 k;
    s32 j;
    s32 count;
    FloorItem *p;
    s32 n;
    reset_floor_items();
    bswap_sync_item_state_header(this);
    for (i = 0; i < 0x10; i++) {
        floor_item_next_sort_keys[i] = next_drop_number_per_floor[i];
    }
    for (b = 0; b != 0xC; b++) {
        set_boss_buf_entry(next_item_id_per_player[b], b);
    }
    for (i = 0; i < 0xF; i++) {
        floor_item_counts_by_floor[i] = floor_item_count_per_floor[i];
    }
    k = 0;
    for (j = 0; j != 0xF; j++) {
        count = floor_item_counts_by_floor[j];
        p = floor_item_row_table[j];
        for (n = 0; n != count; n++, p++) {
            copy_floor_item_entry(p, &items[k++]);
            bswap_item(p);
            p->item.decode_from_network();
        }
    }
    if (pioneer2_item_respawn_flags.test_flags_any(1) != 0) {
        respawn_missing_floor_items(0);
    }
    set_floor_items_synced_flag();
}

#pragma push
#pragma opt_propagation off
s32 G_SyncItemState_6x6D_Decompressed::write() {
    s32 i;
    u16 b;
    G_SyncItemState_6x6D_Decompressed *dst = this;
    s32 k;
    FloorItem *d;
    s32 j;
    s32 count;
    FloorItem *p;
    s32 n;
    for (i = 0; i < 0x10; i++) {
        dst->next_drop_number_per_floor[i] = floor_item_next_sort_keys[i];
    }
    for (b = 0; b != 0xC; b++) {
        dst->next_item_id_per_player[b] = get_sync_counter(b);
    }
    for (i = 0; i < 0xF; i++) {
        dst->floor_item_count_per_floor[i] = floor_item_counts_by_floor[i];
    }
    d = dst->items;
    k = 0;
    for (j = 0; j != 0xF; j++) {
        count = floor_item_counts_by_floor[j];
        p = floor_item_row_table[j];
        for (n = 0; n != count; n++, p++, k++) {
            copy_floor_item_entry(d, p);
            d->item.encode_for_network();
            bswap_item(d);
            d++;
        }
    }
    i = k * 0x24 + 0x8C;
    bswap_sync_item_state_header(dst);
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

s32 is_entry_valid(s32 floor) {
    if (((s32) floor_item_counts_by_floor[floor] < 0xC0) && (floor < 0x12)) {
        return 1;
    }
    return 0;
}

void respawn_missing_floor_items(s32 floor) {
    s32 i;
    if (floor < 0x12) {
        if (floor_item_row_table[floor] != 0) {
            for (i = 0; i != floor_item_counts_by_floor[floor]; i++) {
                FloorItem *e = &floor_item_row_table[floor][i];
                if (find_item_by_id(e->item.id) == 0) {
                    spawn_dropped_item_from_msg(e, 1);
                }
            }
        }
    }
}

s32 remove_item_condition(s32 floor, s32 item_id) {
    FloorItem *list;
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
            if ((s32)list[mid].item.id < item_id) {
                lo = mid + 1;
            } else {
                hi = mid;
            }
        }
        if (item_id == (s32)list[lo].item.id) {
            memcpy(&list[lo], &list[lo + 1], (count - (lo + 1)) * 0x24);
            floor_item_counts_by_floor[floor]--;
            list[floor_item_counts_by_floor[floor]].clear();
            return 1;
        }
        return 0;
    }
    file_debug_printf("ItemCondition AreaOffset Lost");
    return 0;
}
FloorItem *find_item_condition(s32 floor, s32 item_id) {
    FloorItem *list;
    s32 count;
    s32 lo;
    s32 mid;
    s32 hi;
    FloorItem *p;
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
            if ((s32)list[mid].item.id < item_id) {
                lo = mid + 1;
            } else {
                hi = mid;
            }
        }
        p = &list[lo];
        if (item_id == (s32)p->item.id) {
            return p;
        }
        return NULL;
    }
    file_debug_printf("ItemCondition AreaOffset Lost");
    return NULL;
}
s32 insert_item_condition(FloorItem *item) {
    s32 *counts;
    s32 idx;
    FloorItem *list;
    s32 lo;
    s32 mid;
    s32 n;
    s32 val;
    s32 hi;
    FloorItem *p;
    if (item != NULL) {
        if (is_stat_over_limit(item->floor) != 0) {
            evict_lowest_key_floor_item(item->floor);
        }
        if (item->floor < 0x12 && is_entry_valid(item->floor) != 0) {
            idx = item->floor;
            list = floor_item_row_table[idx];
            if (list != NULL) {
                counts = *(s32 **)&floor_item_counts_by_floor;
                val = item->item.id;
                n = counts[idx];
                hi = n - 1;
                if (hi > -1 && val < (s32)list[hi].item.id) {
                    lo = 0;
                    while (lo < hi) {
                        mid = (lo + hi) / 2;
                        if ((s32)list[mid].item.id < val) {
                            lo = mid + 1;
                        } else {
                            hi = mid;
                        }
                    }
                    p = &list[lo];
                    if (val == (s32)p->item.id) {
                        return 0;
                    }
                    memcpy(p + 1, p, (n - lo) * sizeof(FloorItem));
                } else {
                    lo = n;
                }
                item->drop_number = floor_item_next_sort_keys[item->floor];
                if (floor_item_next_sort_keys[item->floor] != 0xFFFF) {
                    floor_item_next_sort_keys[item->floor]++;
                }
                copy_floor_item_entry(&list[lo], item);
                counts[idx]++;
                return 1;
            }
        }
    }
    return 0;
}

void clear_object_count() { floor_item_free_id_count = 0; }

void reset_floor_items() {
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
            floor_item_row_table[k] = &floor_item_entry_pool[k * 0xC0];
            floor_item_counts_by_floor[k] = 0;
        }
    }
    clear_object_count();
}

void free_boss_rocks() {
    mem_free(floor_item_next_sort_keys);
    floor_item_next_sort_keys = 0;
    mem_free(floor_item_free_id_stack);
    floor_item_free_id_stack = NULL;
    floor_item_free_id_count = 0;
    mem_free(floor_item_counts_by_floor);
    floor_item_counts_by_floor = 0;
    mem_free(floor_item_row_table);
    floor_item_row_table = 0;
    if (floor_item_entry_pool != NULL) {
        mem_free((char *)floor_item_entry_pool - 0x10);
    }
    floor_item_entry_pool = NULL;
    floor_items_synced_flags.reset();
}
void alloc_objects() {
    floor_item_entry_pool = new FloorItem[0xD80];
    floor_item_row_table = static_cast<FloorItem **>(mem_alloc(0x48));
    floor_item_counts_by_floor = static_cast<s32 *>(mem_alloc(0x48));
    floor_item_free_id_stack = static_cast<u16 *>(mem_alloc(0x40));
    floor_item_free_id_count = 0;
    floor_item_next_sort_keys = static_cast<u16 *>(mem_alloc(0x24));
    floor_items_synced_flags.reset();
    reset_floor_items();
}
int TLobby::get_lobby_flag() {  return entity_table_count; }
void G_DestroyFloorItem_6x63::bswap() {
    header.bswap();
    bswap_32(&item_id);
    bswap_32(&floor);
}

void G_DestroyFloorItem_6x63::send() {
    bswap();
    send_subcommand(this);
}

void build_6x63_packet(G_DestroyFloorItem_6x63 *destroy) {
    destroy->item_id = -1;
    destroy->header.subcommand = 0x63;
    destroy->header.size = sizeof(G_DestroyFloorItem_6x63) / 4;
}
void set_floor_items_synced_flag(void) {
    floor_items_synced_flags.set(1);
}
void bswap_item(FloorItem *item) {
    bswap_16(reinterpret_cast<u16 *>(&item->entity_index));
    bswap_32(reinterpret_cast<u32 *>(&item->x));
    bswap_32(reinterpret_cast<u32 *>(&item->z));
    bswap_16(reinterpret_cast<u16 *>(&item->room_id));
    bswap_16(&item->drop_number);
    item->item.bswap();
}

FloorItem *copy_floor_item_entry(FloorItem *dst, FloorItem *src) {
    *dst = *src;
    return dst;
}

LAYOUT_ASSERT(SyncItemHeaderPlayerIds, offsetof(G_SyncItemState_6x6D_Decompressed, next_item_id_per_player) == 0x20);
LAYOUT_ASSERT(SyncItemHeaderFloorCounts, offsetof(G_SyncItemState_6x6D_Decompressed, floor_item_count_per_floor) == 0x50);
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
