#include "types.h"
#include "pso/menu/TAdRicoRing_8001BEE8.h"
#include "pso/system/FlagWord.h"
#include "pso/TAdRicoRing.h"
#include "pso/player/TObjPlayer.h"

void FlagWord::clear(u32 mask) { bits &= ~mask; }

s32 test_flags_any(s32 *flags, s32 mask) {
    return (*flags & mask) != 0;
}
