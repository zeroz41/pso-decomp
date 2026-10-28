#ifndef DOLPHIN_MTX_GEOTYPES_H
#define DOLPHIN_MTX_GEOTYPES_H

#include "types.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct Vec {
	f32 x, y, z;
} Vec, *VecPtr, Point3d, *Point3dPtr;

typedef f32 Mtx34[3][4];
typedef f32 Mtx23[2][3];
typedef f32 Mtx33[3][3];
typedef f32 Mtx44[4][4];
typedef f32 (*MtxP)[4];
typedef f32 PSQuaternion[4];
typedef Mtx34 GC_Mtx;

typedef struct Quaternion {
    f32 x, y, z, w;
} Quaternion;

#ifdef __cplusplus
}
#endif

#endif
