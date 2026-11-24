#include "types.h"
#include "pso/ui/window/TWindowSubComCard.h"
#define PSO_SDK_COMPACT_MATH
#include <math.h>
#undef PSO_SDK_COMPACT_MATH

extern "C" {
#pragma push
#pragma scheduling off
f32 TWindowSubComCard::trunc_float(f32 value) {
    if (value < 0.0f) {
        return -(f32) floor(-value);
    }
    return (f32) floor((f64) value);
}
#pragma pop

}
