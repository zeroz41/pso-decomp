#include "types.h"
#include "pso/effect/TUnk_80494968.h"
#include "pso/system/task/TMainTask.h"

TUnk_80494968 *TUnk_80494968::create(u32 color_a, u32 color_b) {
    return new TUnk_80494968(tl_05, color_a, color_b);
}
