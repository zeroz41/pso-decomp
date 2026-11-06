#include "types.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/ui/window/TWindowKeyBoardSoft.h"

void TWindowSubStatusDisp::measure_string_len() {
    TWindowKeyBoardSoft::strnlen((s8 *)this, (u32)0x100);
}
