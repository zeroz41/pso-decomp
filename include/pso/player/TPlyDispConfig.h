#ifndef PSO_PLAYER_TPLYDISPCONFIG_H
#define PSO_PLAYER_TPLYDISPCONFIG_H

#include "types.h"
#include "pso/player/TPlyGuildCardTag.h"

// One action palette: the bank it shows and the guild-card tags of its two
// rows of slots.
class TPlyDispConfigSmth {
public:
    TPlyDispConfigSmth() { bank = 0; };
    void bswap();
    TPlyDispConfigSmth *copy(TPlyDispConfigSmth *src);
    void clear_bank();
    void set_bank();
public:
    u32 bank;  // the bank shown: 0 or 1
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
    TPlyDispConfig *copy_full(TPlyDispConfig *src);
    void clear_secondary_bank();
    void clear_primary_bank();
    void set_secondary_bank();
    void set_primary_bank();
    TPlyDispConfigSmth *ref_primary_palette();
    TPlyDispConfigSmth *ref_secondary_palette();
    int test_photon_blast_modifier();
};

#endif
