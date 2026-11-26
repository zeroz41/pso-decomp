#include "types.h"
#include "pso/math/FloatRound.h"
#define PSO_SDK_COMPACT_MATH
#include <math.h>
#undef PSO_SDK_COMPACT_MATH

#pragma push
#pragma scheduling off
f32 trunc_float(f32 value) {
    if (value < 0.0f) {
        return -(f32) floor(-value);
    }
    return (f32) floor((f64) value);
}
#pragma pop

