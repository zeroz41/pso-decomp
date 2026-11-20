#include "types.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/ui/window/TWindowKeyBoardSoft.h"

s32 TWindowSubStatusDisp::measure_string_len() {
    return TWindowKeyBoardSoft::strnlen((s8 *)this, (u32)0x100);
}
