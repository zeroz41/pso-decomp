#include "types.h"
#include "pso/math/MatrixVector.h"

struct Vec_803D8D1C { f32 x, y, z; };

extern "C" {
extern u8 *current_matrix;
void GXGetProjectionv(f32 *p);
void GXGetViewportv(f32 *vp);
void GXProject(f32 x, f32 y, f32 z, u8 *mtx, f32 *pm, f32 *vp, f32 *sx, f32 *sy, f32 *sz);
void project_world_to_screen(u8 *mtx, Vec_803D8D1C *pos, f32 *out);
s32 scale_matrix(f32, f32, f32);
s32 translate_matrix(f32, f32, f32);

void scale_matrix_vec3(u8 *arg0, u8 *arg1) {
    scale_matrix((f32) (*(f32 *)((s8 *)arg1 + 0)), (f32) (*(f32 *)((s8 *)arg1 + 4)), (f32) (*(f32 *)((s8 *)arg1 + 8)));
}

asm f32 vector_length(const Vec *v) {
#include "orig_asm/pso/math/MatrixVector/vector_length.inc"
}

#pragma push
#pragma scheduling off
void rotate_matrix_about_axis(u8 *arg0, s32 arg1, s32 arg2) {
    u8 sp8[0x30];
    u8 *m;
    if (arg0 == 0) {
        m = current_matrix;
    } else {
        m = arg0;
    }
    if (arg2 != 0) {
        PSMTXRotAxisRad((MtxP)sp8, (Vec *)arg1, 9.587378008291125e-05 * arg2);
        PSMTXConcat((MtxP)m, (MtxP)sp8, (MtxP)m);
    }
}
#pragma pop

void translate_matrix_vec3(u8 *arg0, u8 *arg1) {
    translate_matrix((f32) (*(f32 *)((s8 *)arg1 + 0)), (f32) (*(f32 *)((s8 *)arg1 + 4)), (f32) (*(f32 *)((s8 *)arg1 + 8)));
}

// 1.0f in .sdata, read by the assembly below (not yet split into this unit).
extern f32 lbl_805D46AC;

asm void matrix_identity(MtxP m) {
#include "orig_asm/pso/math/MatrixVector/matrix_identity.inc"
}

#pragma push
#pragma scheduling off
void set_matrix_identity(u8 *arg0) {
    u8 *var_r3;
    var_r3 = arg0;
    if (var_r3 == NULL) {
        var_r3 = current_matrix;
    }
    matrix_identity((MtxP)var_r3);
}
#pragma pop

#pragma push
#pragma fp_contract on
f32 vec_squared_length(const Vec *v) {
    f32 x = v->x;
    f32 y = v->y;
    f32 sum = x * x;
    f32 z = v->z;
    sum = (y * y) + sum;
    return (z * z) + sum;
}
#pragma pop

#pragma push
#pragma scheduling off
void project_world_to_screen(u8 *mtx, Vec_803D8D1C *pos, f32 *out) {
    f32 proj[7];
    f32 vp[6];
    f32 sz;
    f32 sy;
    f32 sx;
    u8 *m;
    GXGetProjectionv(proj);
    GXGetViewportv(vp);
    if (mtx == 0) {
        m = current_matrix;
    } else {
        m = mtx;
    }
    GXProject(pos->x, pos->y, pos->z, m, proj, vp, &sx, &sy, &sz);
    out[0] = sx;
    out[1] = sy;
}
#pragma pop

#pragma push
#pragma scheduling off
void rotate_vector_by_matrix(u32 arg0, const Vec *src, Vec *dst) {
    u32 var_r3;
    var_r3 = arg0;
    if (var_r3 == 0U) {
        var_r3 = (*(u32 *)&current_matrix);
    }
    PSMTXMultVecSR((MtxP)var_r3, src, dst);
}
#pragma pop

}
