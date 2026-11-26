#ifndef PSO_ENEMY_DARKGUNNER_DARKGUNNER_H
#define PSO_ENEMY_DARKGUNNER_DARKGUNNER_H

#include "types.h"

void load_darkgunner_effect_resources(void);

// The four ripple offsets spawn_hamon_effects puts around the gunner.
struct HamonOffset {
    f32 x, z;
};
struct HamonOffsets {
    HamonOffset v[4];
};

#endif
