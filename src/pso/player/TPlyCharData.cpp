#include "types.h"
#include "pso/player/TPlyCharData.h"
#include "pso/player/TPlyDispConfig.h"
#include "pso/system/memory.h"

s32 __dt__12TPlyCharDataFv(s32 arg0, s16 arg1) {
    if (arg0 != 0) {
        __dt__14TPlyDispConfigFv(arg0 + 0x3C0, -1);
        if (arg1 > 0) {
            ::operator delete((void *)arg0);
        }
    }
    return arg0;
}
