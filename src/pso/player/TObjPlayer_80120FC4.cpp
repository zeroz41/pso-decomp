#include "types.h"
#include "pso/unk/text_80120D50.h"
#include "pso/player/TObjPlayer_80120FC4.h"

extern "C" {

s32 __nw__5TItemFUl(s32);
}

extern s32 tl_05;

s32 create_common_weapon(s32 item) {
    s32 temp_r0;

    temp_r0 = __nw__5TItemFUl(0x1F8);
    if (temp_r0 != 0) {
        temp_r0 = (s32)TItemWeapon__ct((TItemWeapon *)((u8 *)temp_r0), (void *)tl_05, (u8 *)item);
    }
    return temp_r0;
}
