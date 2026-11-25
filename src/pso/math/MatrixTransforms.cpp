#include "pso/system/MatrixStack.h"
#include "types.h"
#include "pso/math/MatrixTransforms.h"
#include "pso/math/AngleLookup.h"
#include "pso/unk/text_803D9650.h"
#include "dolphin/mtx.h"
#include "pso/render/RenderSbssGlobals.h"
#include "pso/system/MatrixOps.h"

extern "C" {
void rotate_matrix_z(MtxP matrix, s32 angle) {
    // Game angles have 65536 units per turn. The original uses a single-precision pi.
    const f64 radians_per_angle_unit = 2.0 * 3.141592f / 65536.0;
    GC_Mtx rotation;
    MtxP selected;
    if (angle != 0) {
        if (matrix == NULL) selected = *current_matrix;
        else selected = matrix;
        PSMTXRotRad(rotation, 'z', (f32)(radians_per_angle_unit * (f64)angle));
        PSMTXConcat(selected, rotation, selected);
    }
}

#pragma push
#pragma peephole off
void copy_matrix(MtxP dest, const f32 (*source)[4]) {
    MtxP dst;
    uaddr source_address;
    if (dest == NULL) {
        dst = *current_matrix;
    } else {
        dst = dest;
    }
    // Keep the source address in the original register across the null fallback.
    if (source == NULL) {
        source_address = reinterpret_cast<uaddr>(*current_matrix);
    } else {
        source_address = reinterpret_cast<uaddr>(source);
    }
    PSMTXCopy(reinterpret_cast<const f32 (*)[4]>(source_address), dst);
}
}
#pragma pop

asm void subtract_vector(Vec *v, const Vec *sub) {
#include "orig_asm/pso/math/MatrixTransforms/subtract_vector.inc"
}

void euler_zyx_to_quaternion(const s32 *ang, f32 *quat) {
    f32 cos_z;
    f32 sin_x;
    f32 cos_x;
    f32 sin_y;
    f32 cos_y;
    f32 sin_z;
    sin_x = sin_table_lookup(ang[0] >> 1);
    cos_x = cos_table_lookup(ang[0] >> 1);
    sin_y = sin_table_lookup(ang[1] >> 1);
    cos_y = cos_table_lookup(ang[1] >> 1);
    sin_z = sin_table_lookup(ang[2] >> 1);
    cos_z = cos_table_lookup(ang[2] >> 1);
    quat[0] = (cos_z * (cos_x * cos_y)) + (sin_z * (sin_x * sin_y));
    quat[1] = (sin_z * (-cos_x * sin_y)) + (cos_z * (sin_x * cos_y));
    quat[2] = (sin_x * (cos_y * sin_z)) + (cos_x * (sin_y * cos_z));
    quat[3] = (sin_y * (-cos_z * sin_x)) + (cos_y * (sin_z * cos_x));
}

void euler_yxz_to_quaternion(const s32 *ang, f32 *quat) {
    f32 cos_z;
    f32 sin_x;
    f32 cos_x;
    f32 sin_y;
    f32 cos_y;
    f32 sin_z;
    sin_x = sin_table_lookup(ang[0] >> 1);
    cos_x = cos_table_lookup(ang[0] >> 1);
    sin_y = sin_table_lookup(ang[1] >> 1);
    cos_y = cos_table_lookup(ang[1] >> 1);
    sin_z = sin_table_lookup(ang[2] >> 1);
    cos_z = cos_table_lookup(ang[2] >> 1);
    quat[0] = (cos_z * (cos_x * cos_y)) + (sin_z * (sin_x * sin_y));
    quat[1] = (sin_z * (cos_x * sin_y)) + (cos_z * (sin_x * cos_y));
    quat[2] = (sin_x * (-cos_y * sin_z)) + (cos_x * (sin_y * cos_z));
    quat[3] = (sin_y * (-cos_z * sin_x)) + (cos_y * (sin_z * cos_x));
}

void translate_matrix(MtxP matrix, f32 x, f32 y, f32 z) {
    if (matrix == NULL) {
        matrix = *current_matrix;
    }
    matrix_apply_translation(matrix, x, y, z);
}
