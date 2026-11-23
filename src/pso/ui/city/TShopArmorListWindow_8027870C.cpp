#include "types.h"
#include "pso/ui/window/TWindowMenuIconLine.h"
#include "pso/ui/city/TShopArmorListWindow.h"

extern "C" {

int add_armor_equip_candidates(void*, void*, void*);

void TShopArmorListWindow::save_and_refresh_cursor(void* kind, void* sub) { save_cursor_selection(); ((TWindowMenuIconLine *)this)->reset_list(); add_armor_equip_candidates(this, kind, sub); clamp_selection_to_valid_entry(); }

}
