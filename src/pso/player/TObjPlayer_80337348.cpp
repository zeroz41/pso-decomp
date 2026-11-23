#include "types.h"
#include "pso/player/TObjPlayer_80337348.h"
#include "pso/player/TObjPlayer.h"

struct T_803374C4 { u8 b[8]; void *p; };

extern char lbl_804C3E44[];
extern "C" {
T_803374C4 *TObjPlayer__sub_803374C4(T_803374C4 *self);
s32 MaterialUsage::try_add_item_count(s32 class_index, s32 index, u8 amount) {
    u8 total_materials_used;

    total_materials_used = get_total_materials_used();
    if ((u8) (total_materials_used + amount) > get_material_limit_for_class(class_index)) {
        return 0;
    }
    fn_803374F0(index, (u8) (amount + fn_803374F8(index)));
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
    sum = fn_801BED90();
    sum += fn_801BED88();
    sum += fn_801BED80();
    sum += fn_801BED78();
    sum += fn_801BED70();
    return sum;
}

u8 get_material_limit_for_class(s32 arg0) {
    switch ((s8)arg0) {
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

T_803374C4 *TObjPlayer__sub_803374C4(T_803374C4 *self) {
    s32 i;
    self->p = lbl_804C3E44;
    for (i = 0; i < 8; i++) {
        self->b[i] = 0;
    }
    return self;
}
