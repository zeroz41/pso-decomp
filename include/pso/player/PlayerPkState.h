#ifndef PSO_PLAYER_PLAYERPKSTATE_H
#define PSO_PLAYER_PLAYERPKSTATE_H

#include "types.h"

// TObjPlayer + 0x828: player-killing state. The 6x1B/6x1C enable/disable PK mode packets set
// and clear enabled; team is the battle team compared before damage is credited.
struct PlayerPkState {
    s32 enabled;
    s32 team;
};

#endif
