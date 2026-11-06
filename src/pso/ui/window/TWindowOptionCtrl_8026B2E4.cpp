#include "types.h"
#include "pso/ui/window/TWindowOptionCtrl.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"

s16 TWindowOptionCtrl::get_option_field_C() {
    return *(s16 *)((s8 *)(TAdSinglePlyChrSelectGC::get_global_state()) + 0xC);
}
