#ifndef PSO_ITEM_SHOP_SHOPWEAPONSTOCK_H
#define PSO_ITEM_SHOP_SHOPWEAPONSTOCK_H

#include "types.h"

struct TItemData;

void load_weapon_random_tables(void);
void free_weapon_random_tables(void);

s32 classify_level_bracket_wide(s32 shop_weapon_stock_level);
s32 get_level_bracket(s32 shop_weapon_stock_level);
s32 get_special_level_bracket(s32 shop_weapon_stock_level);
s32 classify_level_bracket_narrow(s32 shop_weapon_stock_level);
s32 get_level_tier(s32 level);
s32 level_to_reward(s32 shop_weapon_stock_level);
s32 is_duplicate_shop_weapon(TItemData *item, s32 shop);
void roll_shop_weapon_second_bonus(TItemData *item);
void roll_shop_weapon_first_bonus(TItemData *item);
void roll_shop_weapon_special(TItemData *item);
void roll_shop_weapon_grind(TItemData *item);
void generate_shop_weapon_stock_at_level(s32 shop, s32 level);
void generate_shop_weapon_stock(s32 shop);
void get_shop_weapon_stock_item(TItemData *dst, s32 index, s32 shop);
void clear_shop_weapon_flags(void);
void mark_shop_weapon_sold_out(s32 index, s32 shop);

// Per shop list (four in split screen): the stock array (16 items, allocated by
// load_weapon_random_tables) and its item count.
extern TItemData *shop_weapon_stock_buffers[4];
extern s32 shop_weapon_stock_counts[4];

// A weapon's item code bytes (item data1[1] and data1[2]) as the shop tables list them.
struct ShopWeaponCode {
    s32 group;
    s32 subtype;
};

// The weapon shop's .rodata tables (ShopWeaponTables.cpp).
extern const ShopWeaponCode shop_weapon_group_subtype_table[72];
extern const ShopWeaponCode shop_section_id_weapon_table_a[10];
extern const ShopWeaponCode shop_section_id_weapon_table_b[10];
extern const s32 shop_weapon_bonus_table[20];

// A value of WeaponRandom*.rel and how many times it goes into the draw pool.
struct WeaponRandomWeight {
    s32 value;
    s32 weight;
};

// The lowest and highest roll of a bonus or a grind.
struct WeaponRandomRange {
    s32 min;
    s32 max;
};

// A weapon of shop_weapon_group_subtype_table and how many times it goes
// into the draw pool.
struct WeaponRandomKind {
    u8 kind;
    u8 weight;
};

// One level tier's weapons: `count` kinds for each section ID.
struct WeaponRandomTier {
    WeaponRandomKind *kinds;
    u8 count;
};

// WeaponRandomNormal/Hard/VeryHard/Ultimate.rel: what the weapon shop stocks
// at each level bracket.
struct WeaponRandomTables {
    WeaponRandomTier *tiers;                // by get_level_tier
    WeaponRandomWeight *first_bonus_types;  // 6 per get_level_bracket
    WeaponRandomWeight *second_bonus_types; // 6 per classify_level_bracket_wide
    WeaponRandomRange *first_bonus_ranges;
    WeaponRandomRange *second_bonus_ranges;
    WeaponRandomWeight *specials;           // 3 per get_special_level_bracket: none, channel 0, channel 1
    WeaponRandomRange *grinds;              // by classify_level_bracket_narrow
    WeaponRandomRange *favored_grinds;      // weapons of the section ID's favoured group
};


#endif
