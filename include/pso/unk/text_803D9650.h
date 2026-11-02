#ifndef PSO_UNK_TEXT_803D9650_H
#define PSO_UNK_TEXT_803D9650_H

#include "types.h"
#include <dolphin/mtx.h>

extern "C" {
// Moves m's translation by m's rotation applied to (x, y, z) (hand-written
// assembly; translate_matrix's worker).
void matrix_apply_translation(MtxP m, f32 x, f32 y, f32 z);
}

#endif
