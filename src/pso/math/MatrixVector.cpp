#include "types.h"
#include "pso/math/MatrixVector.h"
#include "pso/math/MatrixTransforms.h"
#include "pso/system/MatrixOps.h"
#include "pso/render/RenderSbssGlobals.h"

extern "C" {
void GXGetProjectionv(f32 *p);
void GXGetViewportv(f32 *vp);
void GXProject(f32 x, f32 y, f32 z, f32 mtx[3][4], f32 *pm, f32 *vp, f32 *sx, f32 *sy, f32 *sz);
void project_world_to_screen(u8 *mtx, Vec *pos, f32 *out);

void scale_matrix_vec3(u8 *matrix, u8 *arg1) {
    const Vec *scale = (const Vec *)arg1;
    scale_matrix((MtxP)matrix, scale->x, scale->y, scale->z);
}

asm f32 vector_length(const Vec *v) {
#include "orig_asm/pso/math/MatrixVector/vector_length.inc"
}

#pragma push
#pragma scheduling off
void rotate_matrix_about_axis(u8 *arg0, saddr arg1, s32 angle) {
    GC_Mtx rotation;
    MtxP m;
    if (arg0 == 0) {
        m = *current_matrix;
    } else {
        m = (MtxP)arg0;
    }
    if (angle != 0) {
        PSMTXRotAxisRad(rotation, (Vec *)arg1, 9.587378008291125e-05 * angle);
        PSMTXConcat(m, rotation, m);
    }
}
#pragma pop

void translate_matrix_vec3(u8 *matrix, u8 *arg1) {
    const Vec *offset = (const Vec *)arg1;
    translate_matrix((uaddr)matrix, offset->x, offset->y, offset->z);
}

// {0.0f, 1.0f}: matrix_identity reads its 1.0f (the Dolphin SDK keeps the same table as Unit01 in mtx.c).
static f32 Unit01[] = {0.0f, 1.0f};

asm void matrix_identity(MtxP m) {
#include "orig_asm/pso/math/MatrixVector/matrix_identity.inc"
}

#pragma push
#pragma scheduling off
void set_matrix_identity(u8 *matrix) {
    MtxP m = (MtxP)matrix;
    if (m == NULL) {
        m = *current_matrix;
    }
    matrix_identity(m);
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

void project_world_to_screen(u8 *mtx, Vec *pos, f32 *out) {
    f32 proj[7];
    f32 vp[6];
    f32 sz;
    f32 sy;
    f32 sx;
    MtxP m;
    GXGetProjectionv(proj);
    GXGetViewportv(vp);
    if (mtx == 0) {
        m = *current_matrix;
    } else {
        m = (MtxP)mtx;
    }
    GXProject(pos->x, pos->y, pos->z, m, proj, vp, &sx, &sy, &sz);
    out[0] = sx;
    out[1] = sy;
}

#pragma push
#pragma scheduling off
void rotate_vector_by_matrix(uaddr matrix, const Vec *src, Vec *dst) {
    MtxP m = (MtxP)matrix;
    if (m == NULL) {
        m = *current_matrix;
    }
    PSMTXMultVecSR(m, src, dst);
}
#pragma pop

}
