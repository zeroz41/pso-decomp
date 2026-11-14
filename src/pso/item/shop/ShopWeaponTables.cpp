#include "pso/item/shop/ShopWeaponStock.h"

// inferred: a data-only unit. ShopWeaponStock reaches each table with its own lis/addi while it
// reaches its own .bss off one shared base, so the tables were not defined in that file.

const ShopWeaponCode shop_weapon_group_subtype_table[72] = {
    { 1, 0 }, { 1, 1 }, { 1, 2 }, { 1, 3 }, { 1, 4 }, { 3, 0 }, { 3, 1 }, { 3, 2 },
    { 3, 3 }, { 3, 4 }, { 2, 0 }, { 2, 1 }, { 2, 2 }, { 2, 3 }, { 2, 4 }, { 5, 0 },
    { 5, 1 }, { 5, 2 }, { 5, 3 }, { 5, 4 }, { 4, 0 }, { 4, 1 }, { 4, 2 }, { 4, 3 },
    { 4, 4 }, { 6, 0 }, { 6, 1 }, { 6, 2 }, { 6, 3 }, { 6, 4 }, { 7, 0 }, { 7, 1 },
    { 7, 2 }, { 7, 3 }, { 7, 4 }, { 8, 0 }, { 8, 1 }, { 8, 2 }, { 8, 3 }, { 8, 4 },
    { 9, 0 }, { 9, 1 }, { 9, 2 }, { 9, 3 }, { 9, 4 }, { 10, 0 }, { 10, 1 }, { 10, 2 },
    { 10, 3 }, { 11, 0 }, { 11, 1 }, { 11, 2 }, { 11, 3 }, { 12, 0 }, { 12, 1 }, { 12, 2 },
    { 12, 3 }, { -1, -1 }, { -1, -1 }, { 1, 5 }, { 2, 5 }, { 6, 5 }, { 8, 5 }, { 10, 4 },
    { 12, 4 }, { 11, 4 }, { 1, 6 }, { 3, 5 }, { 7, 5 }, { 10, 5 }, { 12, 5 }, { 11, 5 },
};
const ShopWeaponCode shop_section_id_weapon_table_a[10] = {
    { 0x28, 0 }, { 0x2A, 0 }, { 0x2B, 0 }, { 0x35, 0 }, { 0x52, 0 },
    { 0x48, 0 }, { 0x64, 0 }, { 0x59, 0 }, { 0x8A, 0 }, { 0x99, 0 },
};
const ShopWeaponCode shop_section_id_weapon_table_b[10] = {
    { 0x99, 0 }, { 0x64, 0 }, { 0x8A, 0 }, { 0x28, 0 }, { 0x59, 0 },
    { 0x2B, 0 }, { 0x52, 0 }, { 0x2A, 0 }, { 0x48, 0 }, { 0x35, 0 },
};
const s32 shop_weapon_bonus_table[20] = {
    -50, -45, -40, -35, -30, -25, -20, -15, -10, -5, 5, 10, 15, 20, 25, 30, 35, 40, 45, 50,
};
