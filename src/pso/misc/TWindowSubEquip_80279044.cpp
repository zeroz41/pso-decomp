#include "types.h"
#include "pso/misc/TWindowSubEquip_80279044.h"
#include "pso/misc/TWindowSubEquip.h"

struct Item_80279098 { u8 pad[0x34]; u32 flags; };

extern "C" {
int clamp_selection_to_valid_entry__20TShopArmorListWindowFv(void*);
int reset_list__19TWindowMenuIconLineFv(void*);
int save_cursor_selection__20TShopArmorListWindowFv(void*);

void TWindowSubEquip__sub_80279044(void* p) { *(u16*)((char*)p + 0x70) |= 0x100; }

void TWindowSubEquip::update_window() { save_cursor_selection__20TShopArmorListWindowFv(this); reset_list__19TWindowMenuIconLineFv(this); build_equipment_list(); clamp_selection_to_valid_entry__20TShopArmorListWindowFv(this); }
}
s32 get_class_weapon_icon_index(void *self, u8 *p) {
    Item_80279098 *it = (Item_80279098 *)(p + 0x85c);
    if (it == 0) return 0x33;
    if (it->flags & 0x20) return 0;
    if (it->flags & 0x40) return 1;
    return 2;
}
