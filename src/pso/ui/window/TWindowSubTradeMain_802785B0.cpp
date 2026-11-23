#include "types.h"
#include "pso/ui/window/TWindowMenuIconLine.h"

void TWindowMenuIconLine::refresh_trade_item_list(TradeItemEntry *entries) { save_cursor_selection(); reset_list(); fill_trade_item_list(entries); clamp_selection_to_valid_entry(); }
