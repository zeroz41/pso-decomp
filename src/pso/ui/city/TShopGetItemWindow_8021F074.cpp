#include "types.h"
#include "pso/item/shop/ShopWeaponStock.h"
#include "pso/ui/city/TShopGetItemWindow_8021F074.h"
#include "pso/unk/text_8020E700.h"
#include "pso/unk/text_80223B98.h"

    extern int lbl_805D6244;
void clear_all_shop_stock(void) { clear_shop_weapon_flags(); clear_shop_armor_flags(); clear_shop_tool_flags(); lbl_805D6244 = 0; }
