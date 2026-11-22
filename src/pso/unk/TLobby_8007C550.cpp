#include "types.h"
#include "pso/unk/TLobby_8007C550.h"

extern "C" {
u32 subtractive_rng_next(void *self);
s32 subtractive_rng_seed(void*, int);

s32 __ct__14SubtractiveRngFv(void* rng) {
    subtractive_rng_seed(rng, 0);
    return (saddr)rng;
}
u16 TAdSinglePlyChrSelectGC__sub_8007C584(void *self, u16 x) {
    return (x * (subtractive_rng_next(self) >> 16)) >> 16;
}

}
