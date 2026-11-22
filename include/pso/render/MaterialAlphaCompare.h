#ifndef PSO_RENDER_MATERIALALPHACOMPARE_H
#define PSO_RENDER_MATERIALALPHACOMPARE_H

#include "types.h"

// The alpha compare reference Ginja materials draw with (0xBF at boot).
extern s32 material_alpha_compare_reference;

extern "C" {
void set_material_alpha_compare_reference(s32 reference);
}

#endif
