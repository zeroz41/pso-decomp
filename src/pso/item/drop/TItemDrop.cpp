#include "types.h"
#include "pso/item/drop/TItemDrop.h"

extern "C" {

s32 subtractive_rng_seed();

s32 TItemDrop::run_step(s32 arg0) {
    subtractive_rng_seed();
    return arg0;
}

}
