#ifndef PSO_BOSS_DRAGON_TOBJBOSS1MOKOHILL_H
#define PSO_BOSS_DRAGON_TOBJBOSS1MOKOHILL_H

#include "types.h"

f32 rand_signed_unit(void);
f32 random_range(f32 lo, f32 hi);

// A texture coordinate of the trail model as load_resources saved it, one per strip index.
struct TrailUV {
    s16 u;
    s16 v;
};
// A trail model vertex higher than 15 that bobs while the mound is active (load_resources lists them).
struct TrailRaisedVertex {
    f32 *dst;
    f32 base;
    f32 ofs;
    s32 state; // 0 sinking, 1 rising, else frames left to wait
};

#endif
