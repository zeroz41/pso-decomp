#include "types.h"
#include "pso/player/TPlyDispData.h"
#include "pso/ui/hud/TLockOnCursor_8013ED0C.h"
#include "pso/player/TPlyDispConfig_80071F1C.h"
#include "pso/system/memory.h"

extern "C" {
s32 __destroy_arr(s32, s32 *, s32, s32);
extern s32 TLockOnCursor__sub_8013EDC4[];

s32 __dt_deleting__13TLockOnCursorFis(s32 arg0, s16 arg1) {
    if (arg0 != 0) {
        TLockOnCursor__sub_8013ED68(arg0 + 0x9C, (s16)(-1));
        TPlyDispConfig::free_if_valid(arg0, -1);
        if (arg1 > 0) {
            ::operator delete((void *)arg0);
        }
    }
    return arg0;
}
s32 TLockOnCursor__sub_8013ED68(s32 arg0, s16 arg1) {
    if (arg0 != 0) {
        __destroy_arr(arg0 + 0x4, TLockOnCursor__sub_8013EDC4, 0xc, 0xb);
        if (arg1 > 0) {
            ::operator delete((void *)arg0);
        }
    }
    return arg0;
}

}
