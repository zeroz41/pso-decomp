#include "types.h"
#include "pso/ui/window/WindowLayoutEntries.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/ui/city/TShopEquipmentSellWindow.h"
#include "pso/ui/window/TWindowCost.h"
#include "pso/boss/barbaray/TBoss7Crawfish.h"
#include "pso/ui/window/TWindowDD.h"


void TWindowCost::set_cost(s32 cost) { set_value(cost); }
void TWindowCost::run_task() { update_window(); update_window_entry_list(reinterpret_cast<const WindowLayoutEntries *>((char*)this + 0x24)); }

