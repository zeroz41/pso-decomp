#include "types.h"
#include "pso/math/InverseTrig.h"
#include "pso/math/MatrixTransforms.h"
#include "pso/player/TObjPlayer.h"
#include "pso/render/RenderSbssGlobals.h"
#include <dolphin/mtx.h>
#include "pso/system/MatrixOps.h"
#include "pso/unk/text_803D8F74.h"

extern "C" {

#pragma push
#pragma dont_inline off
#pragma inline_depth(4)
static inline f32 sqrtf_803D8F74(f32 x) {
    if (x > (0.0f)) {
        f64 guess = __frsqrte((f64)x);
        guess = (0.5) * guess * ((3.0) - guess * guess * x);
        guess = (0.5) * guess * ((3.0) - guess * guess * x);
        guess = (0.5) * guess * ((3.0) - guess * guess * x);
        volatile f32 y = (f32)(x * guess);
        return y;
    }
    return x;
}

static inline f32 acosf_803D8F74(f32 v) {
    return (f32)acos(v);
}

void reflect_matrix_in_plane(MtxP matrix, const ReflectionPlane *plane)
{
    f32 xz = sqrtf_803D8F74(plane->normal.x * plane->normal.x + plane->normal.z * plane->normal.z);
    f32 len = sqrtf_803D8F74(plane->normal.y * plane->normal.y + xz * xz);
    s32 rx;
    s32 ry;
    if (plane->normal.y >= (0.0f)) {
        rx = -(s32)((10430.38043493439) * acosf_803D8F74(xz / len));
    }
    if (plane->normal.y < (0.0f)) {
        rx = (s32)((10430.38043493439) * acosf_803D8F74(xz / len));
    }
    if (plane->normal.x >= (0.0f)) {
        ry = (s32)((10430.38043493439) * acosf_803D8F74(plane->normal.z / xz));
    }
    if (plane->normal.x < (0.0f)) {
        ry = -(s32)((10430.38043493439) * acosf_803D8F74(plane->normal.z / xz));
    }
    translate_matrix(matrix, plane->point.x, plane->point.y, plane->point.z);
    rotate_matrix_y(matrix, ry);
    rotate_matrix_x(matrix, rx);
    scale_matrix(matrix, 1.0f, 1.0f, -1.0f);
    rotate_matrix_x(matrix, -rx);
    rotate_matrix_y(matrix, -ry);
    translate_matrix(matrix, -plane->point.x, -plane->point.y, -plane->point.z);
}
#pragma pop

void rotate_matrix_y(MtxP matrix, s32 angle) {
    GC_Mtx rotation;
    MtxP selected;
    if (angle != 0) {
        if (matrix == NULL) selected = *current_matrix;
        else selected = matrix;
        PSMTXRotRad(rotation, 'y', (f32)((9.587378008291125e-05) * (f64)angle));
        PSMTXConcat(selected, rotation, selected);
    }
}

}
