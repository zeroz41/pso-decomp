#include "types.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/math/AngleLookup.h"
#include <math.h>

#pragma push
#pragma scheduling off
f32 TWindowSubStatusDisp::round_away_from_zero(f32 value) {
    if (value < 0.0f) {
        return -(f32) ceil(-value);
    }
    return (f32) ceil((f64) value);
}
#pragma pop

asm f32 sin_table_lookup(s32 angle) {
#include "orig_asm/pso/unk/text_803D647C/sin_table_lookup.inc"
}

asm f32 cos_table_lookup(s32 angle) {
#include "orig_asm/pso/unk/text_803D647C/cos_table_lookup.inc"
}
