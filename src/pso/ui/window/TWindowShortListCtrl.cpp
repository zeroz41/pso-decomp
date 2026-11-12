#include "types.h"
#include "pso/unk/text_80278964.h"
#include "pso/unk/text_802789E0.h"
#include "pso/ui/window/TWindowShortListCtrl.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/city/TShopArmorListWindow.h"
#include "pso/ui/window/TWindowMenuIconLine.h"

extern "C" {

void TWindowShortListCtrl::update_variant_a() { ((TShopArmorListWindow *)this)->save_cursor_selection(); ((TWindowMenuIconLine *)this)->reset_list(); refresh_battle_stat_list(this); ((TShopArmorListWindow *)this)->clamp_selection_to_valid_entry(); }

void TWindowShortListCtrl::update_variant_b() { ((TShopArmorListWindow *)this)->save_cursor_selection(); ((TWindowMenuIconLine *)this)->reset_list(); fn_802789E0((u8 *)this); ((TShopArmorListWindow *)this)->clamp_selection_to_valid_entry(); }

void TWindowShortListCtrl::update_variant_c() { ((TShopArmorListWindow *)this)->save_cursor_selection(); ((TWindowMenuIconLine *)this)->reset_list(); ((TObjPlayer *)this)->build_shop_item_list(); ((TShopArmorListWindow *)this)->clamp_selection_to_valid_entry(); }

}
