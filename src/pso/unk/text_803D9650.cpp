#include "pso/unk/text_803D9650.h"

// {0.0f, 1.0f}: matrix_apply_translation reads its 1.0f (the Dolphin SDK keeps the same table as Unit01 in mtx.c).
static f32 Unit01[] = {0.0f, 1.0f};

asm void matrix_apply_translation(MtxP m, f32 x, f32 y, f32 z) {
#include "orig_asm/pso/unk/text_803D9650/matrix_apply_translation.inc"
}
