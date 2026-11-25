#ifndef PSO_PLAYER_PLAYERTELEPIPE_H
#define PSO_PLAYER_PLAYERTELEPIPE_H

#include <stddef.h>
#include "types.h"
#include "pso/macros.h"
#include "pso/network/protocol/protocol_types.h"
#include "pso/system/data/FlagWord.h"

// The player's own telepipe: where it stands, as the 6x70 record carries it, and its flags.
struct PlayerTelepipe {
    TelepipeState state;
    s32 flags;  // FlagWord bits; init builds the word in place

    PlayerTelepipe &operator=(PlayerTelepipe &src);
    // No telepipe: owner 0xFFFF, floor 0, at the origin.
    PlayerTelepipe *init();
};

LAYOUT_ASSERT(PlayerTelepipeFlagsOffset, offsetof(PlayerTelepipe, flags) == 0x18);
LAYOUT_ASSERT(PlayerTelepipeSize, sizeof(PlayerTelepipe) == 0x1C);

#endif
