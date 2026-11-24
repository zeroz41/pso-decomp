#ifndef PSO_SYSTEM_SUBTRACTIVERNG_H
#define PSO_SYSTEM_SUBTRACTIVERNG_H

#include "types.h"

// A subtractive random number generator: 55 words of lagged state and the
// seed. The constructor seeds it with 0.
struct SubtractiveRng {
    SubtractiveRng();
    SubtractiveRng *reseed(u32 seed);
    u32 state[58];
};
LAYOUT_ASSERT(SubtractiveRng_size, sizeof(SubtractiveRng) == 0xE8);

extern "C" void subtractive_rng_seed(void *rng, s32 seed);
extern "C" f32 calc_random_ratio__10TObjPlayerFv(SubtractiveRng *rng);

#endif
