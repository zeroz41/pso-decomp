#include "types.h"
#include "pso/ui/window/TWindowMenuIconLine.h"
#include "pso/ui/city/TShopArmorListWindow.h"

extern "C" {

int build_usable_item_list(void*);

void TShopArmorListWindow::close_list() { save_cursor_selection(); ((TWindowMenuIconLine *)this)->reset_list(); build_usable_item_list(this); clamp_selection_to_valid_entry(); }

}
