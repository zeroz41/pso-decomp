#include "types.h"
#include "pso/ui/window/TWindowOptionCtrl.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"

void TWindowOptionCtrl::set_field_value(s32 arg0, s16 arg1) {
    *(s16 *)((s8 *)(TAdSinglePlyChrSelectGC::get_global_state()) + 0xC) = arg1;
}
