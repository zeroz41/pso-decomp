#include "types.h"
#include "pso/unk/TLobby_8021B268.h"
#include "pso/ui/window/TWindowHelpItem.h"

void TWindowHelpItem::set_scale(f32 x, f32 y) { scale_x = x; scale_y = y; }

    extern int shop_stock_counts[];
int get_shop_stock_count(int base) {  return shop_stock_counts[base]; }
