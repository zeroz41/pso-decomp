#include "types.h"
#include "pso/menu/TAdRicoRing_8001BEE8.h"
#include "pso/TAdRicoRing.h"
#include "pso/player/TObjPlayer.h"

void TAdRicoRing::clear_flags(u32 v) { *(u32 *)&this->m_name &= ~v; }

s32 test_flags_any(s32 *flags, s32 mask) {
    return (*flags & mask) != 0;
}
