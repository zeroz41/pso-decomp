#ifndef PSO_PLAYER_PLAYERPKSTATE_H
#define PSO_PLAYER_PLAYERPKSTATE_H

#include "types.h"

// TObjPlayer + 0x828: player-killing state. The 6x1B/6x1C enable/disable PK mode packets set
// and clear enabled; team is the battle team compared before damage is credited.
struct PlayerPkState {
    s32 enabled;
    s32 team;

    PlayerPkState &operator=(PlayerPkState &src);
    s32 get_team();
    s32 is_enabled();
    void set_team(s32 id);
    void disable();
    void enable();
    PlayerPkState *init();
    void reset();
};

LAYOUT_ASSERT(PlayerPkState_size, sizeof(PlayerPkState) == 0x8);

#endif
