#include "types.h"
#include "pso/item/shop/ShopStockCount.h"
#include "pso/ui/window/TWindowHelpItem.h"
#include "pso/item/shop/ShopArmorStock.h"

void TWindowHelpItem::set_scale(f32 x, f32 y) { scale_x = x; scale_y = y; }

int get_shop_stock_count(int base) { return shop_armor_stock_counts[base]; }
