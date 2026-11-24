#include "pso/system/SubtractiveRng.h"

SubtractiveRng *SubtractiveRng::reseed(u32 seed) {
    subtractive_rng_seed(this, (s32)seed);
    return this;
}
