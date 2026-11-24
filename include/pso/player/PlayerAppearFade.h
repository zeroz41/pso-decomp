#ifndef PSO_PLAYER_PLAYERAPPEARFADE_H
#define PSO_PLAYER_PLAYERAPPEARFADE_H

#include "types.h"

// TObjPlayer + 0x634: the fade-in of a player who appears. update_player_appear_fade counts
// delay down in state 0 and starts the fade (state 1), raises the alpha by 0.1 a frame in
// state 1 and ends in state 2 (shown).
struct PlayerAppearFade {
    u16 client_id;
    s16 delay;
    s32 state;
};

#endif
