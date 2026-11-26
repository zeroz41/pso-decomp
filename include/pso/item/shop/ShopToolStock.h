#ifndef PSO_ITEM_SHOP_SHOPTOOLSTOCK_H
#define PSO_ITEM_SHOP_SHOPTOOLSTOCK_H

#include "types.h"

struct TItemData;

// A tool's item code bytes (item data1[1] and data1[2]): the kinds ToolRandom.rel lists.
struct ShopToolCode {
    s32 group;
    s32 subtype;
};

// The tools always stocked: `count` tool ids per classify_tool_shop_level_bracket row, 0xF for none.
struct ShopToolCommonTable {
    u8 *ids;
    u8 count;
};

// A tool of shop_tool_group_subtype_table (or a technique of shop_technique_pool_table) and
// how many times it goes into the draw pool.
struct ShopToolPoolEntry {
    u8 id;
    u8 weight;
};

// The rare tool pool (`rare_ents`) and the technique pool (`technique_ents`), `*_count` columns
// per get_tool_pool_table_row row each.
struct ShopToolPoolTable {
    ShopToolPoolEntry *rare_ents;
    u8 rare_count;
    ShopToolPoolEntry *technique_ents;
    u8 technique_count;
};

// How a technique's level is rolled: kind 0 gives level 1, kind 1 the shop level divided by
// `base`, kind 2 a random level up to `range` but not below `base`.
struct ShopTechniqueLevelEntry {
    u8 kind;
    u8 base;
    u8 range;
};

// One level row's technique level rules: `count` per get_tool_pool_table_row row.
struct ShopTechniqueLevelTable {
    ShopTechniqueLevelEntry *ents;
    u8 count;
};

// ToolRandom.rel, loaded by load_tool_random_rel: what the tool shop stocks at each level bracket.
struct ShopToolRandomTables {
    ShopToolCommonTable *common;                // by classify_tool_shop_level_bracket
    ShopToolPoolTable *pools;
    ShopTechniqueLevelTable *technique_levels;  // by get_tool_pool_table_row
};

void load_tool_random_rel(void);
void free_tool_random_rel(void);

s32 get_shop_technique_pool_count(s32 shop_tool_stock_level);
s32 get_shop_rare_tool_pool_count(s32 shop_tool_stock_level);
s32 classify_tool_shop_level_bracket(s32 shop_tool_stock_level);
s32 get_tool_pool_table_row(s32 shop_tool_stock_level);
s32 shop_stock_lacks_technique(TItemData *item, s32 shop);
s32 shop_stock_lacks_tool(TItemData *item, s32 shop);
void roll_shop_technique_level(TItemData *item, s32 technique);
void generate_shop_technique_pool(s32 shop);
void generate_shop_rare_tool_pool(s32 shop);
void generate_shop_common_tool_pool(s32 shop);
void clear_shop_tool_flags(void);
void get_shop_tool_stock_item(TItemData *dst, s32 index, s32 shop);
void mark_shop_tool_sold_out(s32 index, s32 shop);
void generate_shop_tool_stock_at_level(s32 shop, s32 level);
void generate_shop_tool_stock(s32 shop);

#endif
