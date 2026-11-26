#include "types.h"
#include "pso/system/MainPhaseCheck.h"

u8 fn_8000F740(s32 *p) {
    s32 r = 0;
    s32 v = *p;
    if (v == 14 || v == 15) {
        r = 1;
    }
    return r;
}
