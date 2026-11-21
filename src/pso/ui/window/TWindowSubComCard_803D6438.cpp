#include "types.h"
#include "pso/ui/window/TWindowSubComCard.h"

extern "C" {
f64 floor(f64);
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
