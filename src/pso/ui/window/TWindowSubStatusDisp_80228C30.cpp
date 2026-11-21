#include "types.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/ui/window/TWindowKeyBoardSoft.h"

s32 measure_string_len(const char *str) {
    return TWindowKeyBoardSoft::strnlen((s8 *)str, (u32)0x100);
}
