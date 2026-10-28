#include "types.h"
#include "pso/system/FlagWord.h"

void FlagWord::set(u32 mask) { bits |= mask; }
