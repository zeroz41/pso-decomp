#include "types.h"
#include "pso/ui/window/TWindowAddition.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/ui/window/TWindowChoiceSetting.h"
#include "pso/ui/window/TWindowSubComCard.h"
#include "pso/enemy/morfos/TWindowSubTradeMain.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"

void TWindowSubStatusDisp::add_text_entry(s32 arg1, s32 arg2) {
    s16 temp_r4;

    temp_r4 = *(s16 *)((s8 *)this + 0x72);
    if (temp_r4 < (s16) *(s16 *)((s8 *)this + 0x76)) {
        ((TWindowSubStatusDisp *)(get_array_entry(temp_r4)))->set_text(arg1, arg2);
        *(s16 *)((s8 *)this + 0x72) = (s16) (*(s16 *)((s8 *)this + 0x72) + 1);
    }
}
