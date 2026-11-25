#ifndef PSO_UNK_TEXT_803D8F74_H
#define PSO_UNK_TEXT_803D8F74_H

#include "types.h"
#include <dolphin/mtx.h>

// A plane through point, facing along normal.
struct ReflectionPlane {
    Vec point;
    Vec normal;
};

extern "C" {
// Mirrors matrix (the current matrix when NULL) in plane.
void reflect_matrix_in_plane(MtxP matrix, const ReflectionPlane *plane);
// Rotates `matrix` (the current matrix when NULL) about y.
void rotate_matrix_y(MtxP matrix, s32 angle);
}

#endif
