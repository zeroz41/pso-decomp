#include "pso/system/MatrixStack.h"
#include "types.h"
#include "pso/math/MatrixTransforms.h"
#include "pso/unk/text_803D9650.h"
#include "dolphin/mtx.h"
#include "pso/render/RenderSbssGlobals.h"
#include "pso/system/MatrixOps.h"

extern "C" {
f32 sin_table_lookup(int);
f32 cos_table_lookup(int);

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

void euler_zyx_to_quaternion(u8 *arg0, u8 *arg1) {
    f32 temp_f1;
    f32 temp_f27;
    f32 temp_f28;
    f32 temp_f29;
    f32 temp_f30;
    f32 temp_f31;
    temp_f27 = sin_table_lookup((int) ((s32) *(s32 *)((s8 *)arg0 + 0) >> 1));
    temp_f28 = cos_table_lookup((int) ((s32) *(s32 *)((s8 *)arg0 + 0) >> 1));
    temp_f29 = sin_table_lookup((int) ((s32) *(s32 *)((s8 *)arg0 + 4) >> 1));
    temp_f30 = cos_table_lookup((int) ((s32) *(s32 *)((s8 *)arg0 + 4) >> 1));
    temp_f31 = sin_table_lookup((int) ((s32) *(s32 *)((s8 *)arg0 + 8) >> 1));
    temp_f1 = cos_table_lookup((int) ((s32) *(s32 *)((s8 *)arg0 + 8) >> 1));
    *(f32 *)((s8 *)arg1 + 0) = (f32) ((temp_f1 * (temp_f28 * temp_f30)) + (temp_f31 * (temp_f27 * temp_f29)));
    *(f32 *)((s8 *)arg1 + 4) = (f32) ((temp_f31 * (-temp_f28 * temp_f29)) + (temp_f1 * (temp_f27 * temp_f30)));
    *(f32 *)((s8 *)arg1 + 8) = (f32) ((temp_f27 * (temp_f30 * temp_f31)) + (temp_f28 * (temp_f29 * temp_f1)));
    *(f32 *)((s8 *)arg1 + 0xC) = (f32) ((temp_f29 * (-temp_f1 * temp_f27)) + (temp_f30 * (temp_f31 * temp_f28)));
}

void euler_yxz_to_quaternion(u8 *arg0, u8 *arg1) {
    f32 temp_f1;
    f32 temp_f27;
    f32 temp_f28;
    f32 temp_f29;
    f32 temp_f30;
    f32 temp_f31;
    temp_f27 = sin_table_lookup((int) ((s32) *(s32 *)((s8 *)arg0 + 0) >> 1));
    temp_f28 = cos_table_lookup((int) ((s32) *(s32 *)((s8 *)arg0 + 0) >> 1));
    temp_f29 = sin_table_lookup((int) ((s32) *(s32 *)((s8 *)arg0 + 4) >> 1));
    temp_f30 = cos_table_lookup((int) ((s32) *(s32 *)((s8 *)arg0 + 4) >> 1));
    temp_f31 = sin_table_lookup((int) ((s32) *(s32 *)((s8 *)arg0 + 8) >> 1));
    temp_f1 = cos_table_lookup((int) ((s32) *(s32 *)((s8 *)arg0 + 8) >> 1));
    *(f32 *)((s8 *)arg1 + 0) = (f32) ((temp_f1 * (temp_f28 * temp_f30)) + (temp_f31 * (temp_f27 * temp_f29)));
    *(f32 *)((s8 *)arg1 + 4) = (f32) ((temp_f31 * (temp_f28 * temp_f29)) + (temp_f1 * (temp_f27 * temp_f30)));
    *(f32 *)((s8 *)arg1 + 8) = (f32) ((temp_f27 * (-temp_f30 * temp_f31)) + (temp_f28 * (temp_f29 * temp_f1)));
    *(f32 *)((s8 *)arg1 + 0xC) = (f32) ((temp_f29 * (-temp_f1 * temp_f27)) + (temp_f30 * (temp_f31 * temp_f28)));
}

#pragma push

void translate_matrix(uaddr arg0, f32 x, f32 y, f32 z) {
    MtxP m = (MtxP)arg0;
    if (m == NULL) {
        m = *current_matrix;
    }
    matrix_apply_translation(m, x, y, z);
}
#pragma pop
