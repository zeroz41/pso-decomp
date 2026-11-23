#ifndef PSO_PLAYER_TPLYDISPCONFIG_H
#define PSO_PLAYER_TPLYDISPCONFIG_H

#include "types.h"
#include "pso/player/TPlyGuildCardTag.h"

// One action palette: the bank it shows and the guild-card tags of its two
// rows of slots.
class TPlyDispConfigSmth {
public:
    TPlyDispConfigSmth() { m_mbr_0x0 = 0; };
    void bswap();
public:
    u32 m_mbr_0x0;
    gc_tag m_tags[4];
    gc_tag m_tags1[4];
};

// The player's two action palettes (primary and secondary).
class TPlyDispConfig {
public:
    TPlyDispConfig();
    ~TPlyDispConfig();
    void bswap();
public:
    TPlyDispConfigSmth m_smth;
    TPlyDispConfigSmth m_smth1;
public:
    void bswap_pair();
};

#endif
