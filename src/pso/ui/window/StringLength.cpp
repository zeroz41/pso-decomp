#include "types.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/ui/window/TWindowKeyBoardSoft.h"
#include "pso/ui/window/BoundedStrlen.h"

s32 measure_string_len(const char *str) {
    return bounded_strlen(str, (u32)0x100);
}
