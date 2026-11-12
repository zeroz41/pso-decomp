#include "types.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/ui/city/TShopEquipmentSellWindow.h"
#include "pso/ui/window/TWindowCost.h"
#include "pso/boss/barbaray/TBoss7Crawfish.h"
#include "pso/ui/window/TWindowDD.h"

extern "C" {

int fn_80269078(void*);

int TShopEquipmentSellWindow::get_item_count() { return fn_80269078(this); }
void TWindowCost::run_task() { ((TWindowDD *)this)->initialize_subwindow(); update_window_entry_list((char*)this + 0x24); }

}
