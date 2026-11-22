#include "types.h"
#include "pso/math/FloatRounding.h"
#include <math.h>

extern "C" {
f32 ceil_to_float(f32 value) {
    return (f32)ceil((f64)value);
}
}
