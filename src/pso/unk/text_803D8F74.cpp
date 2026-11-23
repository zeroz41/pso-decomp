#include "types.h"
#include "pso/math/InverseTrig.h"
#include "pso/math/MatrixTransforms.h"
#include "pso/player/TObjPlayer.h"
#include "pso/render/RenderSbssGlobals.h"
#include <dolphin/mtx.h>

struct Matrix34 { f32 elements[3][4]; };
struct ReflectionPlane { f32 origin[3]; f32 normal[3]; };

extern "C" {
void rotate_matrix_y(Matrix34* matrix, s32 angle);

void scale_matrix(u32, f32, f32, f32);

void rotate_matrix_x(u32, s32);

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

void reflect_matrix_in_plane(uaddr matrix, const ReflectionPlane *plane)
{
    f32 xz = sqrtf_803D8F74(plane->normal[0] * plane->normal[0] + plane->normal[2] * plane->normal[2]);
    f32 len = sqrtf_803D8F74(plane->normal[1] * plane->normal[1] + xz * xz);
    s32 rx;
    s32 ry;
    if (plane->normal[1] >= (0.0f)) {
        rx = -(s32)((10430.38043493439) * acosf_803D8F74(xz / len));
    }
    if (plane->normal[1] < (0.0f)) {
        rx = (s32)((10430.38043493439) * acosf_803D8F74(xz / len));
    }
    if (plane->normal[0] >= (0.0f)) {
        ry = (s32)((10430.38043493439) * acosf_803D8F74(plane->normal[2] / xz));
    }
    if (plane->normal[0] < (0.0f)) {
        ry = -(s32)((10430.38043493439) * acosf_803D8F74(plane->normal[2] / xz));
    }
    translate_matrix(matrix, plane->origin[0], plane->origin[1], plane->origin[2]);
    rotate_matrix_y((Matrix34*)matrix, ry);
    rotate_matrix_x(matrix, rx);
    scale_matrix(matrix, 1.0f, 1.0f, -1.0f);
    rotate_matrix_x(matrix, -rx);
    rotate_matrix_y((Matrix34*)matrix, -ry);
    translate_matrix(matrix, -plane->origin[0], -plane->origin[1], -plane->origin[2]);
}
#pragma pop

void rotate_matrix_y(Matrix34* matrix, s32 angle) {
    Matrix34 rotation;
    Matrix34* selected;
    if (angle != 0) {
        if (matrix == NULL) selected = (Matrix34*)current_matrix;
        else selected = matrix;
        PSMTXRotRad(rotation.elements, 'y', (f32)((9.587378008291125e-05) * (f64)angle));
        PSMTXConcat(selected->elements, rotation.elements, selected->elements);
    }
}

}
