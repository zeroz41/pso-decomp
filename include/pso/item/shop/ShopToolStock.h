#ifndef PSO_ITEM_SHOP_SHOPTOOLSTOCK_H
#define PSO_ITEM_SHOP_SHOPTOOLSTOCK_H

#include "types.h"

void load_tool_random_rel(void);

s32 get_shop_rare_tool_pool_count(s32 shop_tool_stock_level);
s32 get_shop_technique_pool_count(s32 shop_tool_stock_level);
s32 get_tool_pool_table_row(s32 shop_tool_stock_level);

// The common tool table: `count` columns of tool ids per level bracket.
struct ShopToolCommonTable {
    u8 *ids;
    u8 count;
};

// A pool entry: tool or technique `id` is put in the pool `n` times.
struct ShopToolPoolEntry {
    u8 id;
    u8 n;
};

// The rare tool pool (`rare_ents`) and the technique pool (`technique_ents`), `*_count` columns
// per level bracket each.
struct ShopToolPoolTable {
    ShopToolPoolEntry *rare_ents;
    u8 rare_count;
    ShopToolPoolEntry *technique_ents;
    u8 technique_count;
};

// How a technique's level is rolled (kind 0: level 1; 1: level / a; 2: random from a to b).
struct ShopTechniqueLevelEntry {
    u8 kind;
    u8 a;
    u8 b;
};

struct ShopTechniqueLevelTable {
    ShopTechniqueLevelEntry *ents;
    u8 count;
};

// ToolRandom.rel, loaded by load_tool_random_rel.
struct ShopToolRandomTables {
    ShopToolCommonTable *common;
    ShopToolPoolTable *pools;
    ShopTechniqueLevelTable *technique_levels;
};

#endif
