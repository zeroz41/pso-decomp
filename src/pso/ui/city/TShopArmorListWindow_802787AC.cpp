#include "types.h"
#include "pso/ui/window/TWindowMenuIconLine.h"
#include "pso/ui/city/TShopArmorListWindow.h"

extern "C" {

int populate_judgment_item_list(void*);

void TShopArmorListWindow::save_and_close() { save_cursor_selection(); ((TWindowMenuIconLine *)this)->reset_list(); populate_judgment_item_list(this); clamp_selection_to_valid_entry(); }

}
