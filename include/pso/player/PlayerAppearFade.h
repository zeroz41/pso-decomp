#ifndef PSO_PLAYER_PLAYERAPPEARFADE_H
#define PSO_PLAYER_PLAYERAPPEARFADE_H

#include "types.h"

// TObjPlayer + 0x634: the fade-in of a player who appears. update counts delay down in
// WAITING and starts the fade, raises the alpha by 0.1 a frame in FADING_IN and ends in
// SHOWN. The body stays hidden and without collision until the fade starts.
struct PlayerAppearFade {
    enum State {
        WAITING = 0,
        FADING_IN = 1,
        SHOWN = 2,
    };

    u16 client_id;
    s16 delay;
    s32 state;

    void begin();
    void update();
    BOOL is_fading();
};

#endif
