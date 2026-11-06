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

// --- C functions defined in ShopWeaponStock.cpp ---
extern "C" {
s32 TLobby__sub_80224840(s32 arg0);
void TLobby__sub_80225238(int a0, int a1);
}
// --- end of C functions

#endif
