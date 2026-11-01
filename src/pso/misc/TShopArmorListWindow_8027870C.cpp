#include "types.h"
#include "pso/misc/TWindowMenuIconLine.h"
#include "pso/misc/TShopArmorListWindow.h"

extern "C" {

int add_armor_equip_candidates(void*, void*, void*);

void TShopArmorListWindow::save_and_refresh_cursor(void* a1, void* a2) { save_cursor_selection(); ((TWindowMenuIconLine *)this)->reset_list(); add_armor_equip_candidates(this, a1, a2); clamp_selection_to_valid_entry(); }

}
