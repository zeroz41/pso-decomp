#include "types.h"
#include "pso/misc/TWindowAddition.h"
#include "pso/misc/TWindowSubStatusDisp.h"
#include "pso/misc/TWindowChoiceSetting.h"
#include "pso/misc/TWindowSubComCard.h"
#include "pso/misc/TWindowSubTradeMain.h"
#include "pso/ui/TAdSinglePlyChrSelectGC.h"

void TWindowSubStatusDisp::add_text_entry(s32 arg1, s32 arg2) {
    s16 temp_r4;

    temp_r4 = *(s16 *)((s8 *)this + 0x72);
    if (temp_r4 < (s16) *(s16 *)((s8 *)this + 0x76)) {
        ((TWindowSubStatusDisp *)(get_array_entry(temp_r4)))->set_text(arg1, arg2);
        *(s16 *)((s8 *)this + 0x72) = (s16) (*(s16 *)((s8 *)this + 0x72) + 1);
    }
}
