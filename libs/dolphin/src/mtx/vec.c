#include <dolphin.h>
#include <dolphin/mtx.h>

const f32 lbl_805E0480 = 0.5f;
const f32 lbl_805E0484 = 3.0f;

asm void PSVECNormalize(const register Vec* vec1, register Vec* dst) {
#include "orig_asm/mtx/vec/PSVECNormalize.inc"
}

asm void PSVECCrossProduct(register Vec* vec1, register Vec* vec2,
                           register Vec* dst) {
#include "orig_asm/mtx/vec/PSVECCrossProduct.inc"
}

asm f32 PSVECDistance(const register Vec* vec1, const register Vec* vec2) {
#include "orig_asm/mtx/vec/PSVECDistance.inc"
}
