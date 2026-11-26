#ifndef PSO_ITEM_SHOP_SHOPTOOLSTOCK_H
#define PSO_ITEM_SHOP_SHOPTOOLSTOCK_H

#include "types.h"

void load_tool_random_rel(void);

s32 get_shop_rare_tool_pool_count(s32 shop_tool_stock_level);
s32 get_shop_technique_pool_count(s32 shop_tool_stock_level);
s32 get_tool_pool_table_row(s32 shop_tool_stock_level);

#endif
