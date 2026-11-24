#ifndef PSO_PLAYER_BATTLERANKING_H
#define PSO_PLAYER_BATTLERANKING_H
#include "types.h"

// One row of a battle ranking: place 0 is first.
struct BattleRanking {
    u16 client_id;
    s16 place;
    s32 score;
};

#endif
