#include "types.h"
#include <string.h>
#include <stdlib.h>
#include "pso/item/shop/ShopToolStock.h"
#include "pso/item/shop/ShopPool.h"
#include "pso/item/TItemData.h"
#include "pso/network/TLobby.h"
#include "pso/object/base/TObjCharaHelpers.h"
#include "pso/system/memory.h"
#include "pso/unk/text_800F9B84.h"

extern "C" {
void sort_shop_items(TItemData *items, s32 count, s32 mode);
}

// Per shop list (four in split screen): the stock array (18 items, allocated by
// load_tool_random_rel), its item count and whether it was generated.
ToolRandomTables *lobby_tool_random_rel;
int shop_tool_stock_level;
s32 shop_tool_stock_counts[4];
s32 shop_tool_stock_table[4];
s32 shop_tool_flags[4];
TItemData *shop_tool_stock_buffers[4];

#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off

const ShopToolCode shop_tool_group_subtype_table[16] = {
    { 0, 0 }, { 0, 1 }, { 0, 2 }, { 1, 0 }, { 1, 1 }, { 1, 2 }, { 6, 0 }, { 6, 1 },
    { 3, 0 }, { 4, 0 }, { 5, 0 }, { 7, 0 }, { 8, 0 }, { 9, 0 }, { 10, 0 }, { -1, -1 },
};
// The technique (item data1[4]) of each technique pool kind.
const s32 shop_technique_pool_table[19] = {
    0, 3, 6, 15, 16, 13, 10, 11, 12, 1, 4, 7, 14, 17, 2, 5, 8, 9, 18,
};

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
        if (item->data1.data_u8[0] == stock[i].data1.data_u8[0] &&
            item->data1.data_u8[1] == stock[i].data1.data_u8[1] &&
            item->data1.data_u8[2] == stock[i].data1.data_u8[2] &&
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
        if (item->data1.data_u8[0] == stock[i].data1.data_u8[0] &&
            item->data1.data_u8[1] == stock[i].data1.data_u8[1] &&
            item->data1.data_u8[2] == stock[i].data1.data_u8[2]) {
            return 0;
        }
    }
    return 1;
}

void roll_shop_technique_level(TItemData *item, s32 technique) {
    ToolRandomTechniqueLevels *t = lobby_tool_random_rel->technique_levels;
    s32 idx = get_tool_pool_table_row(shop_tool_stock_level);
    ToolRandomTechniqueLevel *e;
    s32 level;
    idx *= t->count;
    e = &t->levels[idx + technique];
    level = shop_tool_stock_level;
    if (level > 99) {
        level = 99;
    }
    switch (e->mode) {
    case 0:
        item->data1.data_s8[2] = 0;
        break;
    case 1: {
        s8 v = level / e->base - 1;
        if (v < 0) {
            v = 0;
        }
        if (v > 14) {
            v = 14;
        }
        item->data1.data_s8[2] = v;
        break;
    }
    case 2: {
        s32 lo;
        s8 v = (s8)((f32)e->range * ((1.0f / 32768.0f) * (f32)rand()));
        lo = e->base - 1;
        if (v < lo) {
            v = lo;
        }
        if (v < 0) {
            v = 0;
        }
        if (v > 14) {
            v = 14;
        }
        item->data1.data_s8[2] = v;
        break;
    }
    }
}

void generate_shop_technique_pool(s32 shop) {
    TItemData it;
    ShopPool pool;
    ToolRandomKind *e;
    s32 n;
    TItemData *arr;
    ToolRandomPool *t;
    s32 i;
    s32 c;
    u8 k;
    arr = shop_tool_stock_buffers[shop];
    n = get_shop_technique_pool_count(shop_tool_stock_level);
    if (n > 0) {
        pool.clear();
        i = get_tool_pool_table_row(shop_tool_stock_level);
        t = &lobby_tool_random_rel->pools[1];
        e = &t->kinds[i * t->count];
        c = 0;
        while (c++ < t->count) {
            k = e->weight;
            while (k-- != 0) {
                pool.push(e->kind);
            }
            e++;
        }
        pool.shuffle_n_times(5);
        i = 0;
        while (i < n) {
            s32 b = pool.pop();
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
    ShopPool pool;
    ToolRandomPool *t;
    s32 j;
    TItemData *arr;
    s32 n;
    ToolRandomKind *e;
    s32 orig;
    s32 i;
    s32 b;
    s32 c;
    u8 k;
    arr = shop_tool_stock_buffers[shop];
    n = get_shop_rare_tool_pool_count(shop_tool_stock_level);
    if (n > 0) {
        pool.clear();
        i = get_tool_pool_table_row(shop_tool_stock_level);
        t = lobby_tool_random_rel->pools;
        e = &t->kinds[i * t->count];
        c = 0;
        while (c++ < t->count) {
            k = e->weight;
            while (k-- != 0) {
                pool.push(e->kind);
            }
            e++;
        }
        pool.shuffle_n_times(8);
        {
            orig = n;
            j = 0;
            while (n > j) {
                b = pool.pop();
                if (b == 0xF) {
                    if (orig == n) {
                        n--;
                    }
                } else if (b != -1) {
                    it.init();
                    it.data1.data_u8[0] = 3;
                    it.data1.data_u8[1] = shop_tool_group_subtype_table[b].group;
                    it.data1.data_u8[2] = shop_tool_group_subtype_table[b].subtype;
                    if (shop_stock_lacks_tool(&it, shop) == 1) {
                        arr[shop_tool_stock_counts[shop]++].copy_from(&it);
                        j++;
                    }
                }
            }
        }
    }
}

void generate_shop_common_tool_pool(s32 shop) {
    TItemData it;
    TItemData *arr;
    ToolRandomCommon *t;
    u8 *p;
    s32 i;
    s32 row;
    arr = shop_tool_stock_buffers[shop];
    row = classify_tool_shop_level_bracket(shop_tool_stock_level);
    if (row >= 0) {
        t = lobby_tool_random_rel->common;
        row *= t->count;
        p = t->kinds + row;
        for (i = 0; i < t->count; i++, p++) {
            if (*p != 0xf) {
                it.init();
                it.data1.data_u8[0] = 3;
                it.data1.data_u8[1] = shop_tool_group_subtype_table[*p].group;
                it.data1.data_u8[2] = shop_tool_group_subtype_table[*p].subtype;
                arr[shop_tool_stock_counts[shop]++].copy_from(&it);
            }
        }
    }
}

void clear_shop_tool_flags(void) {
    memset(shop_tool_flags, 0, 0x10);
}

struct ByteBlock_14 { u8 bytes[0x14]; };

void get_shop_tool_stock_item(TItemData *dst, s32 index, s32 shop) {
    *(ByteBlock_14 *)dst = ((ByteBlock_14 *)shop_tool_stock_buffers[shop])[index];
}

void mark_shop_tool_sold_out(s32 index, s32 shop) {
    TItemData *arr = shop_tool_stock_buffers[shop];
    if (index >= 0 && index <= 0x11) {
        if (arr[index].data2.price != -1) {
            arr[index].data2.price = -1;
        }
    }
}

void generate_shop_tool_stock_at_level(s32 shop, s32 level) {
    shop_tool_stock_level = level;
    generate_shop_tool_stock(shop);
}

void generate_shop_tool_stock(s32 shop) {
    if (lobby_tool_random_rel != NULL) {
        if (shop_tool_flags[shop] == 0) {
            shop_tool_flags[shop] = 1;
            shop_tool_stock_counts[shop] = 0;
            shop_tool_stock_table[shop] = 0;
            generate_shop_common_tool_pool(shop);
            generate_shop_rare_tool_pool(shop);
            generate_shop_technique_pool(shop);
            sort_shop_items(shop_tool_stock_buffers[shop], shop_tool_stock_counts[shop], 2);
        }
    }
}

void free_tool_random_rel(void) {
    s32 i = 3;
    TItemData **buffers = shop_tool_stock_buffers;
    TItemData *none = NULL;
    s32 index = 3;
    do {
        TItemData *buffer = buffers[index];
        if (buffer != NULL) {
            mem_free(buffer);
            buffers[index] = none;
        }
        i -= 1;
        index -= 1;
    } while (i >= 0);
    if (lobby_tool_random_rel != NULL) {
        TLobby::free_nodes_with_id(reinterpret_cast<uaddr>(lobby_tool_random_rel));
        lobby_tool_random_rel = NULL;
    }
}

void load_tool_random_rel(void) {
    s32 i;
    lobby_tool_random_rel = static_cast<ToolRandomTables *>(create_named_object("ToolRandom.rel"));
    for (i = 0; i < 4; i++) {
        shop_tool_stock_buffers[i] = NULL;
    }
    if (is_split_screen() == 1) {
        for (i = 0; i < 4; i++) {
            shop_tool_stock_buffers[i] = static_cast<TItemData *>(mem_alloc(18 * sizeof(TItemData)));
        }
    } else {
        shop_tool_stock_buffers[0] = static_cast<TItemData *>(mem_alloc(18 * sizeof(TItemData)));
    }
    shop_tool_stock_level = 0;
}
