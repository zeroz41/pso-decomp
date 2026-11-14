#include "types.h"
#include "pso/ui/window/TWindowSubMag.h"
#include "pso/ui/city/TShopArmorListWindow.h"
#include "pso/ui/window/TWindowMenuIconLine.h"

extern "C" {

int build_mag_item_candidates(void*, void*);

void TWindowSubMag::init_and_setup(void* a1) { ((TShopArmorListWindow *)this)->save_cursor_selection(); ((TWindowMenuIconLine *)this)->reset_list(); build_mag_item_candidates(this, a1); ((TShopArmorListWindow *)this)->clamp_selection_to_valid_entry(); }

}
