#include "types.h"
#include "pso/misc/TWindowSubMag.h"

extern "C" {

int clamp_selection_to_valid_entry__20TShopArmorListWindowFv(void*);
int save_cursor_selection__20TShopArmorListWindowFv(void*);
int reset_list__19TWindowMenuIconLineFv(void*);
int build_mag_item_candidates(void*, void*);

void TWindowSubMag::init_and_setup(void* a1) { save_cursor_selection__20TShopArmorListWindowFv(this); reset_list__19TWindowMenuIconLineFv(this); build_mag_item_candidates(this, a1); clamp_selection_to_valid_entry__20TShopArmorListWindowFv(this); }

}
