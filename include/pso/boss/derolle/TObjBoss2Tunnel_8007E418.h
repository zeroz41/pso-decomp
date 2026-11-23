#ifndef PSO_BOSS_DEROLLE_TOBJBOSS2TUNNEL_8007E418_H
#define PSO_BOSS_DEROLLE_TOBJBOSS2TUNNEL_8007E418_H

#include "types.h"

struct Vec;
struct NJS_CAMERA;
struct CameraMatrix;

extern "C" {
// True when b lies clockwise of a in the XZ plane (a.z * b.x - a.x * b.z < 0).
s32 is_vec_xz_cross_negative(const Vec *a, const Vec *b);
void rotate_vec_xz(void *arg0, void *arg1, s32 angle);
void rotate_xz_pair_by_angle(f32 *x, f32 *z, s32 angle);
}

// Carries in through the current matrix and then TCameraCtrl's view matrix into out.
// camera is not read.
void transform_vec_by_camera(NJS_CAMERA *camera, const Vec *in, Vec *out);
// Stores the inverse of the current matrix in view. camera is not read.
void store_inverse_current_matrix(NJS_CAMERA *camera, CameraMatrix *view);

#endif
