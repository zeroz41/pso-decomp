#include "types.h"
#include "pso/misc/TWindowSubTradeMain.h"

extern "C" {

int save_cursor_selection__20TShopArmorListWindowFv(void*);
int clamp_selection_to_valid_entry__20TShopArmorListWindowFv(void*);
int reset_list__19TWindowMenuIconLineFv(void*);
int fill_trade_item_list(void*, void*);

void TWindowSubTradeMain::refresh_item_list(void* a1) { save_cursor_selection__20TShopArmorListWindowFv(this); reset_list__19TWindowMenuIconLineFv(this); fill_trade_item_list(this, a1); clamp_selection_to_valid_entry__20TShopArmorListWindowFv(this); }

}
