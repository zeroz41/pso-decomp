#ifndef PSO_ITEM_SHOP_SHOPWEAPONSTOCK_H
#define PSO_ITEM_SHOP_SHOPWEAPONSTOCK_H

#include "types.h"

extern "C" {
s32 TLobby__sub_80224840(s32 arg0);
void TLobby__sub_80225238(int a0, int a1);
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
s32 TLobby__sub_80224840(s32 arg0);
void TLobby__sub_80225238(int a0, int a1);
}
// --- end of C functions

#endif
