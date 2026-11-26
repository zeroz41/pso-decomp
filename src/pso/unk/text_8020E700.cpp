// ---- pso/unk/text_8020E700
#include "types.h"
#include <string.h>
#include "pso/network/protocol/protocol_types.h"
#include "pso/unk/text_8020E700.h"
#include "pso/item/shop/ShopPool.h"
#include "pso/network/TLobby.h"
#include "pso/unk/TLobby_8020E400.h"
#include "pso/item/TItemData.h"
#include "pso/object/base/TObjCharaHelpers.h"
#include <stdlib.h>

#pragma readonly_strings on
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
struct ByteBlock_14 { u8 bytes[0x14]; };

struct ClearShopEntryValueEntry { u8 pad[0x10]; s32 v; };

struct IsDuplicateShopShieldOrUnitItem { u8 b[0x14]; };


struct GenerateShopShieldPoolTable { u8 pad[8]; u8 *pairs; u8 count; };

struct GenerateShopUnitPoolTable { u8 pad[0x10]; u8 *pairs; u8 count; };

struct GenerateShopArmorPoolTable { u8 *pairs; u8 count; };

struct IsDuplicateShopArmorRecord { u8 a, b, c, d, e, f; u8 pad[0x14 - 6]; };

extern "C" {
// Per shop list (four in split screen): the stock array (0x1A4 bytes, allocated by load_armor_random_table),
// its entry count and whether it was generated.
s32 shop_armor_stock_generated_flags[4];
s32 shop_stock_counts[4];
saddr shop_stock_entries[4];
GenerateShopShieldPoolTable ** armor_random_rel;
s32 shop_player_level;
extern s32 shop_difficulty_tier;
}
s32 is_duplicate_shop_shield_or_unit(IsDuplicateShopShieldOrUnitItem *, s32);
s32 is_duplicate_shop_armor(IsDuplicateShopArmorRecord *item, s32 shop);
s32 is_duplicate_shop_armor(IsDuplicateShopArmorRecord *item, s32 shop) {
    s32 i;
    IsDuplicateShopArmorRecord *tbl = (IsDuplicateShopArmorRecord *)shop_stock_entries[shop];
    for (i = 0; i < shop_stock_counts[shop]; i++) {
        if (item->a == tbl[i].a && item->b == tbl[i].b && item->c == tbl[i].c && item->f == tbl[i].f) {
            return 0;
        }
    }
    return 1;
}

s32 is_duplicate_shop_shield_or_unit(IsDuplicateShopShieldOrUnitItem *item, s32 shop) {
    s32 i;
    IsDuplicateShopShieldOrUnitItem *tbl = (IsDuplicateShopShieldOrUnitItem *)shop_stock_entries[shop];
    for (i = 0; i < shop_stock_counts[shop]; i++) {
        if (item->b[0] == tbl[i].b[0] && item->b[1] == tbl[i].b[1] && item->b[2] == tbl[i].b[2]) {
            return 0;
        }
    }
    return 1;
}

void generate_shop_unit_pool(s32 shop) {
    IsDuplicateShopShieldOrUnitItem item;
    ShopPool ctr;
    IsDuplicateShopShieldOrUnitItem *dst;
    s32 cnt;
    s32 n;
    GenerateShopUnitPoolTable *tbl;
    u8 *p;
    s32 i;
    s32 b;
    s32 k;
    s32 grp;
    ctr.clear();
    dst = (IsDuplicateShopShieldOrUnitItem *)shop_stock_entries[shop];
    n = get_shop_unit_count(shop_player_level);
    if (n == 0) {
        return;
    }
    tbl = (GenerateShopUnitPoolTable *)*armor_random_rel;
    grp = TLobby::get_lobby_group(shop_player_level);
    cnt = tbl->count;
    p = tbl->pairs + grp * cnt * 2;
    i = 0;
    while (i++ < cnt) {
        for (k = p[1]; k != 0; k--) {
            ctr.push(p[0]);
        }
        p += 2;
    }
    ctr.shuffle_n_times(8);
    cnt = 0;
    while (cnt < n) {
        b = ctr.pop();
        if (b == -1) {
            continue;
        }
        ((TItemData *)(&item))->init();
        item.b[0] = 1;
        item.b[1] = 3;
        item.b[2] = b;
        if (is_duplicate_shop_shield_or_unit(&item, shop) == 1) {
            ((TItemData *)(&dst[shop_stock_counts[shop]++]))->copy_from((TItemData *)(&item));
            cnt++;
        }
    }
}

void generate_shop_shield_pool(s32 shop) {
    IsDuplicateShopShieldOrUnitItem item;
    ShopPool ctr;
    IsDuplicateShopShieldOrUnitItem *dst;
    s32 n;
    GenerateShopShieldPoolTable *tbl;
    u8 *p;
    s32 i;
    s32 b;
    s32 *counts;
    s32 cnt;
    s32 j;
    s32 k;
    s32 grp;
    ctr.clear();
    dst = (IsDuplicateShopShieldOrUnitItem *)shop_stock_entries[shop];
    n = TLobby::get_shield_shop_tier_for_level(shop_player_level);
    tbl = *armor_random_rel;
    grp = TLobby::get_lobby_group(shop_player_level);
    cnt = tbl->count;
    p = tbl->pairs + grp * cnt * 2;
    i = 0;
    while (i++ < cnt) {
        for (k = p[1]; k != 0; k--) {
            ctr.push(p[0]);
        }
        p += 2;
    }
    ctr.shuffle_n_times(8);
    j = 0;
    counts = shop_stock_counts;
    while (j < n) {
        b = ctr.pop();
        if (b == -1) {
            continue;
        }
        ((TItemData *)(&item))->init();
        item.b[0] = 1;
        item.b[1] = 2;
        if (shop_difficulty_tier != 3) {
            item.b[2] = b;
        } else if (shop_player_level >= 1 && shop_player_level <= 99) {
            item.b[2] = b;
        } else if (shop_player_level >= 100 && shop_player_level <= 150) {
            item.b[2] = b + 2;
        } else if (shop_player_level >= 151 && shop_player_level <= 200) {
            item.b[2] = b + 3;
        } else {
            item.b[2] = b;
        }
        if (is_duplicate_shop_shield_or_unit(&item, shop) == 1) {
            ((TItemData *)(&dst[counts[shop]++]))->copy_from((TItemData *)(&item));
            j++;
        }
    }
}


void generate_shop_armor_pool(s32 shop) {
    IsDuplicateShopShieldOrUnitItem item;
    ShopPool ctr;
    IsDuplicateShopShieldOrUnitItem *dst;
    s32 n;
    s32 cnt;
    s32 i;
    GenerateShopArmorPoolTable *tbl;
    u8 *p;
    s32 b;
    s32 *counts;
    s32 j;
    s32 k;
    s32 grp;
    ctr.clear();
    dst = (IsDuplicateShopShieldOrUnitItem *)shop_stock_entries[shop];
    n = TLobby::get_armor_shop_tier_for_level(shop_player_level);
    tbl = *(GenerateShopArmorPoolTable **)armor_random_rel;
    grp = TLobby::get_lobby_group(shop_player_level);
    cnt = tbl->count;
    grp *= cnt;
    p = tbl->pairs + grp * 2;
    i = 0;
    while (i++ < cnt) {
        for (k = p[1]; k != 0; k--) {
            ctr.push(p[0]);
        }
        p += 2;
    }
    ctr.shuffle_n_times(8);
    j = 0;
    counts = shop_stock_counts;
    while (j < n) {
        b = ctr.pop();
        if (b == -1) {
            continue;
        }
        ((TItemData *)(&item))->init();
        item.b[0] = 1;
        item.b[1] = 1;
        if (shop_difficulty_tier != 3) {
            item.b[2] = b;
        } else if (shop_player_level >= 1 && shop_player_level <= 99) {
            item.b[2] = b;
        } else if (shop_player_level >= 100 && shop_player_level <= 150) {
            item.b[2] = b + 2;
        } else if (shop_player_level >= 151 && shop_player_level <= 200) {
            item.b[2] = b + 3;
        } else {
            item.b[2] = b;
        }
        ((TItemData *)&item)->register_drop();
        if (is_duplicate_shop_armor((IsDuplicateShopArmorRecord *)&item, shop) == 1) {
            ((TItemData *)(&dst[counts[shop]++]))->copy_from((TItemData *)(&item));
            j++;
        }
    }
}

void TLobby::clear_shop_entry_value(s32 i, s32 j) {
    ClearShopEntryValueEntry *e = (ClearShopEntryValueEntry *)shop_stock_entries[j];
    if (i >= 0 && i <= 0x14) {
        if (e[i].v != -1) e[i].v = -1;
    }
}

void clear_shop_armor_flags(void) {
    memset(shop_armor_stock_generated_flags, 0, 0x10);
}

void TLobby::copy_armor_shop_entry(s32 index, s32 base) {
    saddr arg0 = (saddr)this;
    *(ByteBlock_14 *)(arg0) = ((const ByteBlock_14 *)shop_stock_entries[base])[index];
}

// ---- pso/unk/TLobby_8020ED20


void TLobby::set_shop_armor_list_flag(int a0, int a1) { shop_player_level = a1; generate_armor_shop_stock(a0); }


// ---- pso/unk/text_8020ED44


#include "pso/unk/text_8020ED44.h"

void generate_armor_shop_stock(s32 shop) {
    if (armor_random_rel != NULL) {
        if (shop_armor_stock_generated_flags[shop] == 0) {
            shop_armor_stock_generated_flags[shop] = 1;
            shop_stock_counts[shop] = 0;
            generate_shop_armor_pool(shop);
            generate_shop_shield_pool(shop);
            generate_shop_unit_pool(shop);
        }
    }
}
extern "C" {

// ---- pso/unk/TLobby_8020EDBC
void mem_free(void *allocation);
}

void TLobby::free_rocks() {
    s32 i = 3;
    saddr *entries = shop_stock_entries;
    saddr null_entry = 0;
    s32 index = 3;
    do {
        uaddr v = (u32)entries[index];
        if (v != 0U) {
            mem_free((void *)v);
            entries[index] = null_entry;
        }
        i -= 1;
        index -= 1;
    } while (i >= 0);
    if (armor_random_rel != NULL) {
        TLobby::free_nodes_with_id((uaddr)armor_random_rel);
        armor_random_rel = (GenerateShopShieldPoolTable **)null_entry;
    }
}

// ---- pso/unk/text_8020EE2C

#include "pso/unk/text_8020EE2C.h"
#include "pso/unk/text_800F9B84.h"
extern "C" {
s32 mem_alloc(s32);
}

// Dead-stripped from the DOL: no code of it survives, only its literals. The TU's int-to-float
// constant (0x4330000080000000, .rodata 0x8044BC38) is pooled ahead of "ArmorRandom.rel"
// (0x8044BC40), yet load_armor_random_table is compiled before ShopPool::shuffle, the constant's
// one surviving user: a function compiled ahead of it converted an int. This reconstruction draws
// a random pool index the way ShopPool::shuffle (and ShopToolStock's roll_shop_technique_level)
// draws. Name inferred.
s32 draw_shop_pool_index(s32 count) {
    return (s32)((f32)count * (3.0517578e-05f * (f32)rand()));
}

void load_armor_random_table(void) {
    s32 i;
    armor_random_rel = static_cast<GenerateShopShieldPoolTable **>(create_named_object("ArmorRandom.rel"));
    for (i = 0; i < 4; i++) {
        shop_stock_entries[i] = 0;
    }
    if (is_split_screen() == 1) {
        for (i = 0; i < 4; i++) {
            shop_stock_entries[i] = mem_alloc(0x1A4);
        }
    } else {
        shop_stock_entries[0] = mem_alloc(0x1A4);
    }
    shop_player_level = 0;
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
