#include "types.h"
#include <string.h>
#include "pso/item/shop/ShopToolStock.h"
#include "pso/item/shop/ShopPool.h"
#include "pso/unk/text_80223B98.h"
#include "pso/network/TLobby.h"
#include "pso/item/TItemData.h"
#include "pso/ui/window/TWindowSubComCard.h"
#include "pso/network/protocol/protocol_types.h"
#include "pso/unk/text_8020EEFC.h"
#include "pso/object/base/TObjCharaHelpers.h"
#include <stdlib.h>
#include "pso/boss/darkfalz/TOBoss4Rock.h"
#include "pso/unk/text_800F9B84.h"

struct SRock_80224544_8022448C;


extern "C" {
void sort_shop_items(s32, s32, s32);
ShopToolRandomTables *lobby_tool_random_rel;
int shop_tool_stock_level;
s32 shop_tool_stock_counts[4];
s32 shop_tool_stock_table[4];
s32 shop_tool_flags[4];
TItemData *shop_tool_stock_buffers[4];

}

#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
struct ByteBlock_14 { u8 bytes[0x14]; };

struct ShopToolGroupSubtype { s32 a; s32 b; };

const ShopToolGroupSubtype shop_tool_group_subtype_table[16] = {
    { 0, 0 }, { 0, 1 }, { 0, 2 }, { 1, 0 }, { 1, 1 }, { 1, 2 }, { 6, 0 }, { 6, 1 },
    { 3, 0 }, { 4, 0 }, { 5, 0 }, { 7, 0 }, { 8, 0 }, { 9, 0 }, { 10, 0 }, { -1, -1 },
};
const s32 shop_technique_pool_table[19] = {
    0, 3, 6, 15, 16, 13, 10, 11, 12, 1, 4, 7, 14, 17, 2, 5, 8, 9, 18,
};

extern "C" {
void roll_shop_technique_level(TItemData *item, s32 arg1);
void push_shop_pool_entry(void *, u8);
s32 shop_stock_lacks_technique(TItemData *, s32);
s32 shop_stock_lacks_tool(TItemData *, s32);
}
s32 get_shop_technique_pool_count(s32 shop_tool_stock_level) {
    if ((shop_tool_stock_level >= 1) && (shop_tool_stock_level <= 0xA)) {
        return 4;
    }
    if ((shop_tool_stock_level >= 0xB) && (shop_tool_stock_level <= 0x19)) {
        return 5;
    }
    if ((shop_tool_stock_level >= 0x1A) && (shop_tool_stock_level <= 0x2A)) {
        return 5;
    }
    if ((shop_tool_stock_level >= 0x2B) && (shop_tool_stock_level <= 0x3C)) {
        return 7;
    }
    if ((shop_tool_stock_level >= 0x3D) && (shop_tool_stock_level <= 0x64)) {
        return 7;
    }
    if (shop_tool_stock_level >= 0x65) {
        return 7;
    }
    return -1;
}

s32 get_shop_rare_tool_pool_count(s32 shop_tool_stock_level) {
    if ((shop_tool_stock_level >= 1) && (shop_tool_stock_level <= 0xA)) {
        return 0;
    }
    if ((shop_tool_stock_level >= 0xB) && (shop_tool_stock_level <= 0x19)) {
        return 2;
    }
    if ((shop_tool_stock_level >= 0x1A) && (shop_tool_stock_level <= 0x2A)) {
        return 2;
    }
    if ((shop_tool_stock_level >= 0x2B) && (shop_tool_stock_level <= 0x3C)) {
        return 2;
    }
    if ((shop_tool_stock_level >= 0x3D) && (shop_tool_stock_level <= 0x64)) {
        return 2;
    }
    if (shop_tool_stock_level >= 0x65) {
        return 2;
    }
    return -1;
}

s32 classify_tool_shop_level_bracket(s32 shop_tool_stock_level) {
    if ((shop_tool_stock_level >= 1) && (shop_tool_stock_level <= 0xA)) {
        return 0;
    }
    if ((shop_tool_stock_level >= 0xB) && (shop_tool_stock_level <= 0x19)) {
        return 1;
    }
    if ((shop_tool_stock_level >= 0x1A) && (shop_tool_stock_level <= 0x2A)) {
        return 2;
    }
    if ((shop_tool_stock_level >= 0x2B) && (shop_tool_stock_level <= 0x3C)) {
        return 3;
    }
    if ((shop_tool_stock_level >= 0x3D) && (shop_tool_stock_level <= 0x63)) {
        return 4;
    }
    if (shop_tool_stock_level >= 0x64) {
        return 5;
    }
    return -1;
}

s32 get_tool_pool_table_row(s32 shop_tool_stock_level) {
    if ((shop_tool_stock_level >= 1) && (shop_tool_stock_level <= 0xA)) {
        return 0;
    }
    if ((shop_tool_stock_level >= 0xB) && (shop_tool_stock_level <= 0x19)) {
        return 1;
    }
    if ((shop_tool_stock_level >= 0x1A) && (shop_tool_stock_level <= 0x2A)) {
        return 2;
    }
    if ((shop_tool_stock_level >= 0x2B) && (shop_tool_stock_level <= 0x3C)) {
        return 3;
    }
    if ((shop_tool_stock_level >= 0x3D) && (shop_tool_stock_level <= 0x64)) {
        return 4;
    }
    if (shop_tool_stock_level >= 0x65) {
        return 4;
    }
    return -1;
}
s32 shop_stock_lacks_technique(TItemData *item, s32 shop) {
    TItemData *stock = shop_tool_stock_buffers[shop];
    s32 i = 0;
    while (i++ < shop_tool_stock_counts[shop]) {
        if (item->data1.data_u8[0] == stock[i].data1.data_u8[0] && item->data1.data_u8[1] == stock[i].data1.data_u8[1] && item->data1.data_u8[2] == stock[i].data1.data_u8[2] &&
            item->data1.data_u8[4] == stock[i].data1.data_u8[4]) {
            return 0;
        }
    }
    return 1;
}

s32 shop_stock_lacks_tool(TItemData *item, s32 shop) {
    TItemData *stock = shop_tool_stock_buffers[shop];
    s32 i = 0;
    while (i++ < shop_tool_stock_counts[shop]) {
        if (item->data1.data_u8[0] == stock[i].data1.data_u8[0] && item->data1.data_u8[1] == stock[i].data1.data_u8[1] && item->data1.data_u8[2] == stock[i].data1.data_u8[2]) {
            return 0;
        }
    }
    return 1;
}


void roll_shop_technique_level(TItemData *item, s32 arg1) {
    ShopTechniqueLevelTable *t = lobby_tool_random_rel->technique_levels;
    s32 idx = get_tool_pool_table_row(shop_tool_stock_level);
    ShopTechniqueLevelEntry *e;
    s32 level;
    idx *= t->count;
    e = &t->ents[idx + arg1];
    level = shop_tool_stock_level;
    if (level > 99) {
        level = 99;
    }
    switch (e->kind) {
    case 0:
        item->data1.data_u8[2] = 0;
        break;
    case 1: {
        s8 v = level / e->a - 1;
        if (v < 0) {
            v = 0;
        }
        if (v > 14) {
            v = 14;
        }
        item->data1.data_u8[2] = v;
        break;
    }
    case 2: {
        s32 lo;
        s8 v = (s8)((f32)e->b * ((1.0f / 32768.0f) * (f32)rand()));
        lo = e->a - 1;
        if (v < lo) {
            v = lo;
        }
        if (v < 0) {
            v = 0;
        }
        if (v > 14) {
            v = 14;
        }
        item->data1.data_u8[2] = v;
        break;
    }
    }
}

void generate_shop_technique_pool(s32 shop) {
    TItemData it;
    ShopPool ctr;
    ShopToolPoolEntry *e;
    s32 n;
    TItemData *arr;
    ShopToolPoolTable *t;
    s32 i;
    s32 c;
    u8 k;
    arr = shop_tool_stock_buffers[shop];
    n = get_shop_technique_pool_count(shop_tool_stock_level);
    if (n > 0) {
        ((TLobby *)(&ctr))->reset_counter_64();
        i = get_tool_pool_table_row(shop_tool_stock_level);
        t = lobby_tool_random_rel->pools;
        e = &t->technique_ents[i * t->technique_count];
        c = 0;
        while (c++ < t->technique_count) {
            k = e->n;
            while (k-- != 0) {
                push_shop_pool_entry(&ctr, e->id);
            }
            e++;
        }
        shuffle_shop_pool_n_times(&ctr, 5);
        i = 0;
        while (i < n) {
            s32 b = ((TLobby *)(&ctr))->pop_byte();
            if (b != -1) {
                it.init();
                it.data1.data_u8[0] = 3;
                it.data1.data_u8[1] = 2;
                it.data1.data_u8[4] = shop_technique_pool_table[b];
                roll_shop_technique_level(&it, b);
                if (shop_stock_lacks_technique(&it, shop) == 1) {
                    arr[shop_tool_stock_counts[shop]++].copy_from(&it);
                    i++;
                }
            }
        }
    }
}

void generate_shop_rare_tool_pool(s32 shop) {
    TItemData it;
    ShopPool ctr;
    ShopToolPoolTable *t;
    s32 j;
    TItemData *arr;
    s32 n;
    ShopToolPoolEntry *e;
    s32 orig;
    s32 i;
    s32 b;
    s32 c;
    u8 k;
    arr = shop_tool_stock_buffers[shop];
    n = get_shop_rare_tool_pool_count(shop_tool_stock_level);
    if (n > 0) {
        ((TLobby *)(&ctr))->reset_counter_64();
        i = get_tool_pool_table_row(shop_tool_stock_level);
        t = lobby_tool_random_rel->pools;
        e = &t->rare_ents[i * t->rare_count];
        c = 0;
        while (c++ < t->rare_count) {
            k = e->n;
            while (k-- != 0) {
                push_shop_pool_entry(&ctr, e->id);
            }
            e++;
        }
        shuffle_shop_pool_n_times(&ctr, 8);
        {
            orig = n;
            j = 0;
            while (n > j) {
                b = ((TLobby *)(&ctr))->pop_byte();
                if (b == 0xF) {
                    if (orig == n) {
                        n--;
                    }
                } else if (b != -1) {
                    it.init();
                    it.data1.data_u8[0] = 3;
                    it.data1.data_u8[1] = shop_tool_group_subtype_table[b].a;
                    it.data1.data_u8[2] = shop_tool_group_subtype_table[b].b;
                    if (shop_stock_lacks_tool(&it, shop) == 1) {
                        arr[shop_tool_stock_counts[shop]++].copy_from(&it);
                        j++;
                    }
                }
            }
        }
    }
}

void generate_shop_common_tool_pool(s32 idx) {
    TItemData it;
    TItemData *arr;
    ShopToolCommonTable *t;
    u8 *p;
    s32 i;
    s32 row;
    arr = shop_tool_stock_buffers[idx];
    row = classify_tool_shop_level_bracket(shop_tool_stock_level);
    if (row >= 0) {
        t = lobby_tool_random_rel->common;
        row *= t->count;
        p = t->ids + row;
        for (i = 0; i < t->count; i++, p++) {
            if (*p != 0xf) {
                it.init();
                it.data1.data_u8[0] = 3;
                it.data1.data_u8[1] = shop_tool_group_subtype_table[*p].a;
                it.data1.data_u8[2] = shop_tool_group_subtype_table[*p].b;
                arr[shop_tool_stock_counts[idx]++].copy_from(&it);
            }
        }
    }
}

void clear_shop_tool_flags(void) {
    memset(shop_tool_flags, 0, 0x10);
}

void TLobby::copy_shop_item_entry(s32 index, s32 buffer) {
    saddr arg0 = (saddr)this;
    *(ByteBlock_14 *)(arg0) = *(const ByteBlock_14 *)((saddr)shop_tool_stock_buffers[buffer] + (index * 0x14));
}
void mark_shop_tool_sold_out(s32 a, s32 b) {
    TItemData *arr = shop_tool_stock_buffers[b];
    if (a >= 0 && a <= 0x11) {
        if (arr[a].data2.price != -1) {
            arr[a].data2.price = -1;
        }
    }
}


void TLobby::generate_shop_inventory_at_level(int slot, int level) { shop_tool_stock_level = level; TLobby::generate_shop_inventory(slot); }

void TLobby::generate_shop_inventory(s32 idx) {
    if (lobby_tool_random_rel != NULL) {
        if (shop_tool_flags[idx] == 0) {
            shop_tool_flags[idx] = 1;
            shop_tool_stock_counts[idx] = 0;
            shop_tool_stock_table[idx] = 0;
            generate_shop_common_tool_pool(idx);
            generate_shop_rare_tool_pool(idx);
            generate_shop_technique_pool(idx);
            sort_shop_items((saddr)shop_tool_stock_buffers[idx], shop_tool_stock_counts[idx], 2);
        }
    }
}

void TLobby::free_all_rocks() {
    s32 i = 3;
    TItemData **buffers = shop_tool_stock_buffers;
    s32 var_r30 = 0;
    s32 var_r31 = 3;
    do {
        TItemData *v = buffers[var_r31];
        if (v != NULL) {
            mem_free(v);
            buffers[var_r31] = NULL;
        }
        i -= 1;
        var_r31 -= 1;
    } while (i >= 0);
    if (lobby_tool_random_rel != NULL) {
        TLobby::free_nodes_with_id(reinterpret_cast<uaddr>(lobby_tool_random_rel));
        lobby_tool_random_rel = NULL;
    }
}
void load_tool_random_rel(void) {
    s32 i;
    lobby_tool_random_rel = (ShopToolRandomTables *)create_named_object("ToolRandom.rel");
    for (i = 0; i < 4; i++) {
        shop_tool_stock_buffers[i] = NULL;
    }
    if (is_split_screen() == 1) {
        for (i = 0; i < 4; i++) {
            shop_tool_stock_buffers[i] = (TItemData *)mem_alloc(0x168);
        }
    } else {
        shop_tool_stock_buffers[0] = (TItemData *)mem_alloc(0x168);
    }
    (*(s32 *)&shop_tool_stock_level) = 0;
}
