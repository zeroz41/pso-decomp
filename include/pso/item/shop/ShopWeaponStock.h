#ifndef PSO_ITEM_SHOP_SHOPWEAPONSTOCK_H
#define PSO_ITEM_SHOP_SHOPWEAPONSTOCK_H

#include "types.h"

extern "C" {
s32 TLobby__sub_80224840(s32 shop_weapon_stock_level);
void TLobby__sub_80225238(int tbl, int a1);
}
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

// --- C functions defined in ShopWeaponStock.cpp ---
extern "C" {
s32 TLobby__sub_80224840(s32 shop_weapon_stock_level);
void TLobby__sub_80225238(int tbl, int a1);
}
// --- end of C functions

// An entry of a WeaponRandom*.rel table: `id` is put in the pool `n` times.
struct ShopPoolEntry {
    s32 id;
    s32 n;
};

// The lowest and highest roll of a bracket.
struct ShopRollRange {
    s32 min;
    s32 max;
};

// A stock tier's entry: weapon `id` is put in the pool `count` times.
struct ShopStockEntry {
    u8 id;
    u8 count;
};

struct ShopStockTier {
    ShopStockEntry *ents;
    u8 n;
};

// The weapon shop's random tables (WeaponRandomNormal/Hard/VeryHard/Ultimate.rel),
// loaded by load_weapon_random_tables.
struct ShopWeaponRandomTables {
    ShopStockTier *stock_tiers;
    ShopPoolEntry *first_bonus_ents;
    ShopPoolEntry *second_bonus_ents;
    ShopRollRange *first_bonus_ranges;
    ShopRollRange *second_bonus_ranges;
    ShopPoolEntry *special_ents;
    ShopRollRange *grind_ranges;
    ShopRollRange *favored_grind_ranges;
};

// shop_weapon_stock_generated_flags: layout known from its uses only.
struct ShopWeaponStockGeneratedFlags { s32 value; u8 remaining[0xC]; };
extern ShopWeaponStockGeneratedFlags shop_weapon_stock_generated_flags;

#endif
