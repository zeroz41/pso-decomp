#include "types.h"
#include "pso/ui/hud/TMainCursor_8013DF5C.h"
#include "pso/player/TObjPlayer_801D84A8.h"
#include "pso/ui/hud/TMainCursor.h"

extern "C" {

s32 TWindowActionPalette__sub_801C1C68(s32, s32);

s32 TMainCursor::find_action_slot(s32 arg0, void *arg1, s16 arg2, s32 arg3, s32 arg4) {
    s32 temp_r31;
    s32 var_r30;
    s32 var_r29;
    u32 temp_r3;

    if (arg1 != NULL) {
        temp_r3 = *(u32 *)((s8 *)arg1 + 0x424);
        if (temp_r3 != 0U) {
            temp_r31 = temp_r3 + 0x520;
            if (TObjPlayer__sub_801D84F0((void *)temp_r31) != 0) {
                if (((TMainCursor *)temp_r31)->get_type() == 1) {
                    if (arg2 == (s32) ((TMainCursor *)temp_r31)->get_type()) {
                        return 0;
                    }
                    goto block_8;
                }
                if (matches_type_and_enabled__11TMainCursorFiUcUc(temp_r31, (u8) arg2, (u8) arg3) != 0) {
                    return 0;
                }
                goto block_8;
            }
        }
    }
block_8:
    var_r29 = TWindowActionPalette__sub_801C1C68(arg0, arg4);
    var_r30 = 0;
loop_9:
    if (((TMainCursor *)var_r29)->get_type() == 1) {
        if (arg2 == (s32) ((TMainCursor *)var_r29)->get_type()) {
            return var_r30;
        }
        goto block_14;
    }
    if (matches_type_and_enabled__11TMainCursorFiUcUc(var_r29, (u8) arg2, (u8) arg3) != 0) {
        return var_r30;
    }
block_14:
    var_r30 += 1;
    var_r29 += 4;
    if (var_r30 >= 4) {
        return -1;
    }
    goto loop_9;
}

}
