#include "pso/unk/text_803D9650.h"

// 1.0f in .sdata, read by the assembly below (not yet split into this unit).
extern "C" f32 lbl_805D46B4;

asm void matrix_apply_translation(MtxP m, f32 x, f32 y, f32 z) {
#include "orig_asm/pso/unk/text_803D9650/matrix_apply_translation.inc"
}
