#include "pso/effect/TEffHit.h"
#include "libs/dolphin/include/dolphin/mtx/GeoTypes.h"
extern "C" void create_hit_effect__10TObjPlayerFPv(const Vec* position) {
    new TEffHit(position);
}
