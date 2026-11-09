#include "types.h"
#include "pso/unk/TLobby.h"
#include "pso/item/drop/TItemDrop_80105D0C.h"

extern "C" {
extern s32 item_drop_rng;
}

// A random value in [0, max) from the item drop RNG, raised to at least min.
u32 TLobby::clamp_min_drop(u32 min, u32 max) {
    u32 value;

    value = item_drop_rng_below(item_drop_rng, max);
    if (value < min) {
        value = min;
    }
    return value;
}
