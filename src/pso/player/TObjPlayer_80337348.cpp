#include "types.h"
#include "pso/player/TObjPlayer_80337348.h"
#include "pso/player/TObjPlayer.h"

extern "C" {
s32 MaterialUsage::try_add_item_count(s32 class_index, s32 index, u8 amount) {
    u8 total_materials_used;

    total_materials_used = get_total_materials_used();
    if ((u8) (total_materials_used + amount) > get_material_limit_for_class(class_index)) {
        return 0;
    }
    set_count(index, (u8) (amount + get_count(index)));
    return 1;
}

s32 MaterialUsage::can_use_more_materials(s32 class_index) {
    u8 t = get_total_materials_used();
    if (t >= get_material_limit_for_class(class_index)) {
        return 1;
    }
    return 0;
}
}

u8 MaterialUsage::get_total_materials_used() {
    u8 sum;
    sum = get_power_used();
    sum += get_mind_used();
    sum += get_evade_used();
    sum += get_def_used();
    sum += get_luck_used();
    return sum;
}

u8 get_material_limit_for_class(s32 class_index) {
    switch ((s8)class_index) {
    case 0:
    case 3:
    case 6:
    case 10:
    case 11:
        return 0xFA;
    case 1:
    case 7:
    case 8:
        return 0x96;
    case 2:
    case 4:
    case 5:
    case 9:
        return 0x96;
    }
    return 0xFA;
}

MaterialUsage::MaterialUsage() {
    s32 i;
    for (i = 0; i < 8; i++) {
        counts[i] = 0;
    }
}
