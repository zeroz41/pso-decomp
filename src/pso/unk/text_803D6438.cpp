#include "types.h"
#include "pso/misc/TWindowSubComCard.h"
#include "pso/misc/TWindowSubStatusDisp.h"

extern "C" {
f64 floor(f64);
f64 ceil(f64);
#pragma push
#pragma scheduling off
f32 TWindowSubComCard::trunc_float(f32 farg0) {
    if (farg0 < 0.0f) {
        return -(f32) floor(-farg0);
    }
    return (f32) floor((f64) farg0);
}
#pragma pop

#pragma push
#pragma scheduling off
f32 TWindowSubStatusDisp::round_away_from_zero(f32 farg0) {
    if (farg0 < 0.0f) {
        return -(f32) ceil(-farg0);
    }
    return (f32) ceil((f64) farg0);
}
#pragma pop

}
