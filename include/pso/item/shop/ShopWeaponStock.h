#ifndef PSO_ITEM_SHOP_SHOPWEAPONSTOCK_H
#define PSO_ITEM_SHOP_SHOPWEAPONSTOCK_H

#include "types.h"

s32 TLobby__sub_80224840(s32 shop_weapon_stock_level);
void TLobby__sub_80225238(int tbl, int a1);
void clear_shop_weapon_flags(void);
void generate_shop_weapon_stock(s32 tbl);
void load_weapon_random_tables(void);

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
    WeaponRandomTier *tiers;                // by TLobby::get_level_tier
    WeaponRandomWeight *first_bonus_types;  // 6 per TLobby::get_level_bracket
    WeaponRandomWeight *second_bonus_types; // 6 per TLobby::classify_level_bracket_wide
    WeaponRandomRange *first_bonus_ranges;
    WeaponRandomRange *second_bonus_ranges;
    WeaponRandomWeight *specials;           // 3 per bracket: none, channel 0, channel 1
    WeaponRandomRange *grinds;              // by TLobby::classify_level_bracket_narrow
    WeaponRandomRange *favored_grinds;      // weapons of the section ID's favoured group
};

// shop_weapon_stock_generated_flags: layout known from its uses only.
struct ShopWeaponStockGeneratedFlags { s32 value; u8 remaining[0xC]; };
extern ShopWeaponStockGeneratedFlags shop_weapon_stock_generated_flags;

#endif
