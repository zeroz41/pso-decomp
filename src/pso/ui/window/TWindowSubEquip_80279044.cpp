#include "types.h"
#include "pso/ui/window/TWindowSubEquip.h"
#include "pso/ui/city/TShopArmorListWindow.h"
#include "pso/ui/window/TWindowMenuIconLine.h"

struct Item_80279098 { u8 pad[0x34]; u32 flags; };


void TWindowMenuIconLine::disable_decide_sound() {
    state_flags |= 0x100;
}

void TWindowSubEquip::update_window() { ((TWindowMenuIconLine *)this)->save_cursor_selection(); ((TWindowMenuIconLine *)this)->reset_list(); build_equipment_list(); ((TWindowMenuIconLine *)this)->clamp_selection_to_valid_entry(); }
s32 get_class_weapon_icon_index(void *self, u8 *p) {
    Item_80279098 *it = (Item_80279098 *)(p + 0x85c);
    if (it == 0) return 0x33;
    if (it->flags & 0x20) return 0;
    if (it->flags & 0x40) return 1;
    return 2;
}
