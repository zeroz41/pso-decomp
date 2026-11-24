#ifndef PSO_MATH_CURVE_PATH_POINT_H
#define PSO_MATH_CURVE_PATH_POINT_H

#include "types.h"
#include <dolphin/mtx/GeoTypes.h>
#include <stddef.h>

// The path readers use the segment length to advance between control points.
// The Bezier evaluator uses the positions alone.
struct CurvePathPoint {
    Vec pos;
    f32 length;
};

LAYOUT_ASSERT(CurvePathPointSize, sizeof(CurvePathPoint) == 0x10);
LAYOUT_ASSERT(CurvePathPointLengthOffset, offsetof(CurvePathPoint, length) == 0xC);

extern "C" {
s32 fn_8034D3D0(CurvePathPoint *points, f32 scale, s32 count, s32 step, s32 closed, Vec *out, s32);
s32 fn_8034D790(CurvePathPoint *points, f32 scale, s32 count, s32 step, s32 closed, Vec *out);
}

#endif
