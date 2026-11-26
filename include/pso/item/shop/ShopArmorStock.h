#ifndef PSO_ITEM_SHOP_SHOPARMORSTOCK_H
#define PSO_ITEM_SHOP_SHOPARMORSTOCK_H

#include "types.h"

struct TItemData;

// A frame, shield or unit kind (item data1[2]) and how many times it goes into the draw pool.
struct ArmorRandomKind {
    u8 kind;
    u8 weight;
};

// One level row's kinds: `count` per get_armor_pool_table_row row.
struct ArmorRandomPool {
    ArmorRandomKind *kinds;
    u8 count;
};

// ArmorRandom.rel: what the armor shop stocks at each level bracket.
struct ArmorRandomTables {
    ArmorRandomPool *pools; // [0] frames, [1] shields, [2] units
};

// Per shop list (four in split screen): the stock array (21 items, allocated by
// load_armor_random_table), its item count and whether it was generated.
extern s32 shop_armor_stock_generated_flags[4];
extern s32 shop_armor_stock_counts[4];
extern TItemData *shop_armor_stock_buffers[4];

s32 get_armor_pool_table_row(s32 shop_armor_stock_level);
s32 get_shop_unit_count(s32 shop_armor_stock_level);
s32 get_shop_shield_count(s32 shop_armor_stock_level);
s32 get_shop_armor_count(s32 shop_armor_stock_level);
s32 shop_stock_lacks_armor(TItemData *item, s32 shop);
s32 shop_stock_lacks_shield_or_unit(TItemData *item, s32 shop);
void generate_shop_unit_pool(s32 shop);
void generate_shop_shield_pool(s32 shop);
void generate_shop_armor_pool(s32 shop);
void mark_shop_armor_sold_out(s32 index, s32 shop);
void clear_shop_armor_flags(void);
void get_shop_armor_stock_item(TItemData *dst, s32 index, s32 shop);
void generate_shop_armor_stock_at_level(s32 shop, s32 level);
void generate_shop_armor_stock(s32 shop);
void free_armor_random_table(void);
void load_armor_random_table(void);

#endif
