#include "types.h"
#include "pso/unk/text_802789E0.h"
#include "pso/ui/window/TWindowShortListCtrl.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/city/TShopArmorListWindow.h"
#include "pso/ui/window/TWindowMenuIconLine.h"


void TWindowShortListCtrl::update_variant_a() { ((TWindowMenuIconLine *)this)->save_cursor_selection(); ((TWindowMenuIconLine *)this)->reset_list(); ((TWindowMenuIconLine *)this)->refresh_battle_stat_list(); ((TWindowMenuIconLine *)this)->clamp_selection_to_valid_entry(); }

void TWindowShortListCtrl::update_variant_b() { ((TWindowMenuIconLine *)this)->save_cursor_selection(); ((TWindowMenuIconLine *)this)->reset_list(); fn_802789E0((u8 *)this); ((TWindowMenuIconLine *)this)->clamp_selection_to_valid_entry(); }

void TWindowShortListCtrl::update_variant_c() { ((TWindowMenuIconLine *)this)->save_cursor_selection(); ((TWindowMenuIconLine *)this)->reset_list(); ((TObjPlayer *)this)->build_shop_item_list(); ((TWindowMenuIconLine *)this)->clamp_selection_to_valid_entry(); }

