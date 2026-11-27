#include "types.h"
#include <string.h>
#include <stdlib.h>
#include "pso/item/shop/ShopArmorStock.h"
#include "pso/item/shop/ShopPool.h"
#include "pso/item/TItemData.h"
#include "pso/network/TLobby.h"
#include "pso/object/base/TObjCharaHelpers.h"
#include "pso/system/memory.h"
#include "pso/ui/city/TShopGetItemWindow.h"
#include "pso/system/MallocLoadFilePrc.h"

#pragma readonly_strings on
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off

s32 get_armor_pool_table_row(s32 shop_armor_stock_level) {
    if ((shop_armor_stock_level >= 1) && (shop_armor_stock_level <= 0xA)) {
        return 0;
    }
    if ((shop_armor_stock_level >= 0xB) && (shop_armor_stock_level <= 0x19)) {
        return 1;
    }
    if ((shop_armor_stock_level >= 0x1A) && (shop_armor_stock_level <= 0x2A)) {
        return 2;
    }
    if ((shop_armor_stock_level >= 0x2B) && (shop_armor_stock_level <= 0x3C)) {
        return 3;
    }
    if ((shop_armor_stock_level >= 0x3D) && (shop_armor_stock_level <= 0x64)) {
        return 4;
    }
    if (shop_armor_stock_level >= 0x65) {
        return 4;
    }
    return -1;
}

s32 get_shop_unit_count(s32 shop_armor_stock_level) {
    if ((shop_armor_stock_level >= 1) && (shop_armor_stock_level <= 0xA)) {
        return 0;
    }
    if ((shop_armor_stock_level >= 0xB) && (shop_armor_stock_level <= 0x19)) {
        return 3;
    }
    if ((shop_armor_stock_level >= 0x1A) && (shop_armor_stock_level <= 0x2A)) {
        return 5;
    }
    if ((shop_armor_stock_level >= 0x2B) && (shop_armor_stock_level <= 0x3C)) {
        return 6;
    }
    if ((shop_armor_stock_level >= 0x3D) && (shop_armor_stock_level <= 0x64)) {
        return 6;
    }
    if (shop_armor_stock_level >= 0x65) {
        return 6;
    }
    return -1;
}

s32 get_shop_shield_count(s32 shop_armor_stock_level) {
    if ((shop_armor_stock_level >= 1) && (shop_armor_stock_level <= 0xA)) {
        return 4;
    }
    if ((shop_armor_stock_level >= 0xB) && (shop_armor_stock_level <= 0x19)) {
        return 5;
    }
    if ((shop_armor_stock_level >= 0x1A) && (shop_armor_stock_level <= 0x2A)) {
        return 6;
    }
    if ((shop_armor_stock_level >= 0x2B) && (shop_armor_stock_level <= 0x3C)) {
        return 7;
    }
    if ((shop_armor_stock_level >= 0x3D) && (shop_armor_stock_level <= 0x64)) {
        return 7;
    }
    if (shop_armor_stock_level >= 0x65) {
        return 7;
    }
    return -1;
}

s32 get_shop_armor_count(s32 shop_armor_stock_level) {
    if ((shop_armor_stock_level >= 1) && (shop_armor_stock_level <= 0xA)) {
        return 4;
    }
    if ((shop_armor_stock_level >= 0xB) && (shop_armor_stock_level <= 0x19)) {
        return 6;
    }
    if ((shop_armor_stock_level >= 0x1A) && (shop_armor_stock_level <= 0x2A)) {
        return 7;
    }
    if ((shop_armor_stock_level >= 0x2B) && (shop_armor_stock_level <= 0x3C)) {
        return 8;
    }
    if ((shop_armor_stock_level >= 0x3D) && (shop_armor_stock_level <= 0x64)) {
        return 8;
    }
    if (shop_armor_stock_level >= 0x65) {
        return 8;
    }
    return -1;
}

s32 shop_armor_stock_generated_flags[4];
s32 shop_armor_stock_counts[4];
TItemData *shop_armor_stock_buffers[4];
ArmorRandomTables *armor_random_rel;
s32 shop_armor_stock_level;

// A frame matches on its kind and its slot count (data1[5]).
s32 shop_stock_lacks_armor(TItemData *item, s32 shop) {
    s32 i;
    TItemData *stock = shop_armor_stock_buffers[shop];
    for (i = 0; i < shop_armor_stock_counts[shop]; i++) {
        if (item->data1.data_u8[0] == stock[i].data1.data_u8[0] &&
            item->data1.data_u8[1] == stock[i].data1.data_u8[1] &&
            item->data1.data_u8[2] == stock[i].data1.data_u8[2] &&
            item->data1.data_u8[5] == stock[i].data1.data_u8[5]) {
            return 0;
        }
    }
    return 1;
}

s32 shop_stock_lacks_shield_or_unit(TItemData *item, s32 shop) {
    s32 i;
    TItemData *stock = shop_armor_stock_buffers[shop];
    for (i = 0; i < shop_armor_stock_counts[shop]; i++) {
        if (item->data1.data_u8[0] == stock[i].data1.data_u8[0] &&
            item->data1.data_u8[1] == stock[i].data1.data_u8[1] &&
            item->data1.data_u8[2] == stock[i].data1.data_u8[2]) {
            return 0;
        }
    }
    return 1;
}

void generate_shop_unit_pool(s32 shop) {
    TItemData item;
    ShopPool pool;
    TItemData *stock;
    s32 cnt;
    s32 n;
    ArmorRandomPool *t;
    ArmorRandomKind *e;
    s32 i;
    s32 b;
    s32 k;
    s32 row;
    pool.clear();
    stock = shop_armor_stock_buffers[shop];
    n = get_shop_unit_count(shop_armor_stock_level);
    if (n == 0) {
        return;
    }
    t = armor_random_rel->pools;
    row = get_armor_pool_table_row(shop_armor_stock_level);
    cnt = t[2].count;
    e = &t[2].kinds[row * cnt];
    i = 0;
    while (i++ < cnt) {
        for (k = e->weight; k != 0; k--) {
            pool.push(e->kind);
        }
        e++;
    }
    pool.shuffle_n_times(8);
    cnt = 0;
    while (cnt < n) {
        b = pool.pop();
        if (b == -1) {
            continue;
        }
        item.init();
        item.data1.data_u8[0] = 1;
        item.data1.data_u8[1] = 3;
        item.data1.data_u8[2] = b;
        if (shop_stock_lacks_shield_or_unit(&item, shop) == 1) {
            stock[shop_armor_stock_counts[shop]++].copy_from(&item);
            cnt++;
        }
    }
}

void generate_shop_shield_pool(s32 shop) {
    TItemData item;
    ShopPool pool;
    TItemData *stock;
    s32 n;
    ArmorRandomPool *t;
    ArmorRandomKind *e;
    s32 i;
    s32 b;
    s32 *counts;
    s32 cnt;
    s32 j;
    s32 k;
    s32 row;
    pool.clear();
    stock = shop_armor_stock_buffers[shop];
    n = get_shop_shield_count(shop_armor_stock_level);
    t = &armor_random_rel->pools[1];
    row = get_armor_pool_table_row(shop_armor_stock_level);
    cnt = t->count;
    e = &t->kinds[row * cnt];
    i = 0;
    while (i++ < cnt) {
        for (k = e->weight; k != 0; k--) {
            pool.push(e->kind);
        }
        e++;
    }
    pool.shuffle_n_times(8);
    j = 0;
    counts = shop_armor_stock_counts;
    while (j < n) {
        b = pool.pop();
        if (b == -1) {
            continue;
        }
        item.init();
        item.data1.data_u8[0] = 1;
        item.data1.data_u8[1] = 2;
        if (shop_difficulty_tier != 3) {
            item.data1.data_u8[2] = b;
        } else if (shop_armor_stock_level >= 1 && shop_armor_stock_level <= 99) {
            item.data1.data_u8[2] = b;
        } else if (shop_armor_stock_level >= 100 && shop_armor_stock_level <= 150) {
            item.data1.data_u8[2] = b + 2;
        } else if (shop_armor_stock_level >= 151 && shop_armor_stock_level <= 200) {
            item.data1.data_u8[2] = b + 3;
        } else {
            item.data1.data_u8[2] = b;
        }
        if (shop_stock_lacks_shield_or_unit(&item, shop) == 1) {
            stock[counts[shop]++].copy_from(&item);
            j++;
        }
    }
}

void generate_shop_armor_pool(s32 shop) {
    TItemData item;
    ShopPool pool;
    TItemData *stock;
    s32 n;
    s32 cnt;
    s32 i;
    ArmorRandomPool *t;
    ArmorRandomKind *e;
    s32 b;
    s32 *counts;
    s32 j;
    s32 k;
    s32 row;
    pool.clear();
    stock = shop_armor_stock_buffers[shop];
    n = get_shop_armor_count(shop_armor_stock_level);
    t = armor_random_rel->pools;
    row = get_armor_pool_table_row(shop_armor_stock_level);
    cnt = t->count;
    row *= cnt;
    e = &t->kinds[row];
    i = 0;
    while (i++ < cnt) {
        for (k = e->weight; k != 0; k--) {
            pool.push(e->kind);
        }
        e++;
    }
    pool.shuffle_n_times(8);
    j = 0;
    counts = shop_armor_stock_counts;
    while (j < n) {
        b = pool.pop();
        if (b == -1) {
            continue;
        }
        item.init();
        item.data1.data_u8[0] = 1;
        item.data1.data_u8[1] = 1;
        if (shop_difficulty_tier != 3) {
            item.data1.data_u8[2] = b;
        } else if (shop_armor_stock_level >= 1 && shop_armor_stock_level <= 99) {
            item.data1.data_u8[2] = b;
        } else if (shop_armor_stock_level >= 100 && shop_armor_stock_level <= 150) {
            item.data1.data_u8[2] = b + 2;
        } else if (shop_armor_stock_level >= 151 && shop_armor_stock_level <= 200) {
            item.data1.data_u8[2] = b + 3;
        } else {
            item.data1.data_u8[2] = b;
        }
        item.register_drop();
        if (shop_stock_lacks_armor(&item, shop) == 1) {
            stock[counts[shop]++].copy_from(&item);
            j++;
        }
    }
}

void mark_shop_armor_sold_out(s32 index, s32 shop) {
    TItemData *stock = shop_armor_stock_buffers[shop];
    if (index >= 0 && index <= 0x14) {
        if (stock[index].data2.price != -1) {
            stock[index].data2.price = -1;
        }
    }
}

void clear_shop_armor_flags(void) {
    memset(shop_armor_stock_generated_flags, 0, 0x10);
}

struct ByteBlock_14 { u8 bytes[0x14]; };

void get_shop_armor_stock_item(TItemData *dst, s32 index, s32 shop) {
    *(ByteBlock_14 *)dst = ((ByteBlock_14 *)shop_armor_stock_buffers[shop])[index];
}

void generate_shop_armor_stock_at_level(s32 shop, s32 level) {
    shop_armor_stock_level = level;
    generate_shop_armor_stock(shop);
}

void generate_shop_armor_stock(s32 shop) {
    if (armor_random_rel != NULL) {
        if (shop_armor_stock_generated_flags[shop] == 0) {
            shop_armor_stock_generated_flags[shop] = 1;
            shop_armor_stock_counts[shop] = 0;
            generate_shop_armor_pool(shop);
            generate_shop_shield_pool(shop);
            generate_shop_unit_pool(shop);
        }
    }
}

void free_armor_random_table(void) {
    s32 i = 3;
    TItemData **buffers = shop_armor_stock_buffers;
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
    if (armor_random_rel != NULL) {
        TLobby::free_nodes_with_id(armor_random_rel);
        armor_random_rel = NULL;
    }
}

// Dead-stripped from the DOL: no code of it survives, only its literals. The TU's int-to-float
// constant (0x4330000080000000) is pooled ahead of "ArmorRandom.rel"
// yet load_armor_random_table is compiled before ShopPool::shuffle, the constant's
// one surviving user: a function compiled ahead of it converted an int. This reconstruction draws
// a random pool index the way ShopPool::shuffle (and ShopToolStock's roll_shop_technique_level)
// draws.
s32 draw_shop_pool_index(s32 count) {
    return (s32)((f32)count * (3.0517578e-05f * (f32)rand()));
}

void load_armor_random_table(void) {
    s32 i;
    armor_random_rel = static_cast<ArmorRandomTables *>(create_named_object("ArmorRandom.rel"));
    for (i = 0; i < 4; i++) {
        shop_armor_stock_buffers[i] = NULL;
    }
    if (is_split_screen() == 1) {
        for (i = 0; i < 4; i++) {
            shop_armor_stock_buffers[i] = static_cast<TItemData *>(mem_alloc(21 * sizeof(TItemData)));
        }
    } else {
        shop_armor_stock_buffers[0] = static_cast<TItemData *>(mem_alloc(21 * sizeof(TItemData)));
    }
    shop_armor_stock_level = 0;
}

// Takes the last entry, or -1 when the pool is empty.
s32 ShopPool::pop() {
    s32 n = count;

    if (n > 0) {
        s32 last = n - 1;
        count = last;
        return entries[last];
    }
    return -1;
}

void ShopPool::shuffle_n_times(s32 times) {
    while (times-- > 0) {
        shuffle();
    }
}

void ShopPool::shuffle() {
    s32 i;
    s32 k;
    u8 t;
    for (i = 0; i < count; i++) {
        k = (s32)((f32)count * (3.0517578e-05f * (f32)rand()));
        t = entries[i];
        entries[i] = entries[k];
        entries[k] = t;
    }
}

void ShopPool::push(u8 entry) {
    s32 n = count;
    if (n < 100) {
        count = n + 1;
        entries[n] = entry;
    }
}

void ShopPool::clear() { count = 0; }
