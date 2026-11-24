#define _MATH_H_

#include "PowerPC_EABI_Support/MetroTRK/trk.h"

asm void TRK_flush_cache(register void* address, register int size) {
#include "orig_asm/TRK_MINNOW_DOLPHIN/flush_cache/TRK_flush_cache.inc"
}
