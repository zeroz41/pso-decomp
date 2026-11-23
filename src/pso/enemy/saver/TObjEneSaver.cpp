#include "types.h"
#include "pso/effect/TAttackTrace.h"
#include "pso/system/task/TMainTask.h"

TAttackTraceStrip *TAttackTraceStrip::create(u32 color_a, u32 color_b) {
    return new TAttackTraceStrip(tl_05, color_a, color_b);
}
