#include "types.h"
#include "pso/enemy/morfos/TWindowSubTradeMain.h"
#include "pso/ui/city/TShopArmorListWindow.h"
#include "pso/ui/window/TWindowMenuIconLine.h"

extern "C" {

int fill_trade_item_list(void*, void*);

void TWindowSubTradeMain::refresh_item_list(void* a1) { ((TShopArmorListWindow *)this)->save_cursor_selection(); ((TWindowMenuIconLine *)this)->reset_list(); fill_trade_item_list(this, a1); ((TShopArmorListWindow *)this)->clamp_selection_to_valid_entry(); }

}
