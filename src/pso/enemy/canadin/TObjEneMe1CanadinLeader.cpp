#include "types.h"
#include "pso/math/FloatRounding.h"

extern "C" {
f64 ceil(f64);

f32 ceil_to_float(f32 value) {
    return (f32)ceil((f64)value);
}
}
