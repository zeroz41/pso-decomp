#ifndef PSO_PLAYER_PLAYERSTATS_H
#define PSO_PLAYER_PLAYERSTATS_H

#include "types.h"
#include <stddef.h>
#include "pso/system/byteswap.h"

struct stats {
    void bswap();

    short atp;
    short mst;
    short evp;
    short hp;
    short dfp;
    short ata;
    short lck;
};

struct player_stats {
    void bswap();
    player_stats &operator=(player_stats &src);
    void clear();

    struct stats stats;
    short esp;
    float proportions;
    float knockback_resist;
    int level;
    int exp;
    int meseta;
};

LAYOUT_ASSERT(PlayerBaseStatsSize, sizeof(player_stats) == 0x24);
LAYOUT_ASSERT(PlayerBaseStatsProportionsOffset, offsetof(player_stats, proportions) == 0x10);
LAYOUT_ASSERT(PlayerBaseStatsLevelOffset, offsetof(player_stats, level) == 0x18);
LAYOUT_ASSERT(PlayerBaseStatsMesetaOffset, offsetof(player_stats, meseta) == 0x20);

#endif
