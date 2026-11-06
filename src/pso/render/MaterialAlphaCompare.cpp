#include "types.h"
#include "pso/render/MaterialAlphaCompare.h"

extern s32 material_alpha_compare_reference;

void set_material_alpha_compare_reference(s32 reference) {
    material_alpha_compare_reference = reference;
}
