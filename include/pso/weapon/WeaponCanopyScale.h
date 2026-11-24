#ifndef PSO_WEAPON_WEAPON_CANOPY_SCALE_H
#define PSO_WEAPON_WEAPON_CANOPY_SCALE_H
#include "types.h"
#include "pso/math/ClampedStep.h"

// Canopy scale shared by Madam's Parasol and Madam's Umbrella.
struct WeaponCanopyScale {
    f32 x;
    f32 y;
    f32 z;

    s32 open() {
        s32 reached_limit = 0;
        if (x < 1.0f) {
            x += 0.14f;
            if (1.0f <= x) {
                x = 1.0f;
                reached_limit = 1;
            }
        }
        approach_value(&y, -0.04000001f, 1.0f);
        approach_value(&z, 0.14f, 1.0f);
        return reached_limit;
    }

    void close() {
        approach_value(&x, -0.14f, 0.3f);
        approach_value(&y, 0.04000001f, 1.2f);
        approach_value(&z, -0.14f, 0.3f);
    }
};
LAYOUT_ASSERT(WeaponCanopyScaleSize, sizeof(WeaponCanopyScale) == 0xC);
#endif
