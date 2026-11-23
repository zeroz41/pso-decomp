#ifndef PSO_PLAYER_PLAYERSTATS_H
#define PSO_PLAYER_PLAYERSTATS_H

#include "types.h"
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
    void bswap() {
        bswap_16((u16 *)&stats.atp);
        bswap_16((u16 *)&stats.mst);
        bswap_16((u16 *)&stats.evp);
        bswap_16((u16 *)&stats.hp);
        bswap_16((u16 *)&stats.dfp);
        bswap_16((u16 *)&stats.ata);
        bswap_16((u16 *)&stats.lck);
        bswap_16((u16 *)&mbr_0xe);
        bswap_32((u32 *)&proportions);
        bswap_32((u32 *)&mbr_0x14);
        bswap_32((u32 *)&level);
        bswap_32((u32 *)&exp);
        bswap_32((u32 *)&meseta);
    };

    struct stats stats;
    short mbr_0xe;
    float proportions;
    float mbr_0x14;
    int level;
    int exp;
    int meseta;
};

#endif
