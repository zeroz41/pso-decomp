#ifndef PSO_UNK_TEXT_803D8DE0_H
#define PSO_UNK_TEXT_803D8DE0_H

#include "types.h"
#include <dolphin/mtx.h>

// --- C functions defined in text_803D8DE0.cpp ---
extern "C" {
// Transforms count vectors by the rotation part of matrix (the current one
// for 0), src and dst may be the same array.
void fn_803D8DE0(u32 matrix, Vec *src, Vec *dst, u32 count);
}
// --- end of C functions

#endif
