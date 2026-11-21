#include "types.h"
#include "pso/player/TObjPlayer_80337348.h"
#include "pso/player/TObjPlayer.h"

struct T_803374C4 { u8 b[8]; void *p; };

extern char lbl_804C3E44[];
extern "C" {
T_803374C4 *TObjPlayer__sub_803374C4(T_803374C4 *self);
s32 get_byte_4__10TObjPlayerFPv(s32);
s32 get_byte_3__10TObjPlayerFPv(s32);
s32 get_byte_2__10TObjPlayerFPv(s32);
s32 get_byte_1__10TObjPlayerFPv(s32);
s32 get_byte_0__10TObjPlayerFPv();
int fn_803374F0(s32, s32, u8);
s32 fn_803374F8(s32, s32);

s32 TObjPlayer::try_add_item_count(s32 arg0, s32 arg1, s32 arg2, u8 arg3) {
    s32 total_materials_used;

    total_materials_used = get_total_materials_used(arg0);
    if ((u8) (total_materials_used + arg3) > get_material_limit_for_class(arg1)) {
        return 0;
    }
    fn_803374F0(arg0, arg2, (u8) (arg3 + fn_803374F8(arg0, arg2)));
    return 1;
}

s32 TObjPlayer::can_use_more_materials(s32 arg1) {
    s32 arg0 = (saddr)this;
    s32 t = get_total_materials_used(arg0);
    if ((u8)t >= get_material_limit_for_class(arg1)) {
        return 1;
    }
    return 0;
}
}

s32 get_total_materials_used(s32 arg0) {
    s32 sum;
    sum = get_byte_0__10TObjPlayerFPv();
    sum += get_byte_1__10TObjPlayerFPv(arg0);
    sum += get_byte_2__10TObjPlayerFPv(arg0);
    sum += get_byte_3__10TObjPlayerFPv(arg0);
    sum += get_byte_4__10TObjPlayerFPv(arg0);
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
