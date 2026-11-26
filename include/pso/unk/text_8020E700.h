#ifndef PSO_UNK_TEXT_8020E700_H
#define PSO_UNK_TEXT_8020E700_H

#include "types.h"

void clear_shop_armor_flags(void);
void generate_shop_shield_pool(s32 shop);

void generate_armor_shop_stock(s32 shop);
void generate_shop_armor_pool(s32 shop);
void generate_shop_unit_pool(s32 shop);

struct ClearShopEntryValueEntry { u8 pad[0x10]; s32 v; };

struct IsDuplicateShopShieldOrUnitItem { u8 b[0x14]; };

#include "pso/item/shop/ShopPool.h"

struct GenerateShopShieldPoolTable { u8 pad[8]; u8 *pairs; u8 count; };

struct GenerateShopUnitPoolTable { u8 pad[0x10]; u8 *pairs; u8 count; };

struct GenerateShopArmorPoolTable { u8 *pairs; u8 count; };

struct IsDuplicateShopArmorRecord { u8 a, b, c, d, e, f; u8 pad[0x14 - 6]; };

#endif
