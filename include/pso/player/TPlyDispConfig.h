#ifndef PSO_PLAYER_TPLYDISPCONFIG_H
#define PSO_PLAYER_TPLYDISPCONFIG_H

#include "types.h"
#include "pso/player/TPlyGuildCardTag.h"

// One action palette: the bank it shows and the guild-card tags of its two
// rows of slots.
class TPlyDispConfigSmth {
public:
    TPlyDispConfigSmth() { bank = 0; };
    // Shows bank 0 and clears every tag.
    void init();
    void bswap();
    TPlyDispConfigSmth *copy(TPlyDispConfigSmth *src);
    int is_first_bank();
    void clear_bank();
    void set_bank();
    // The tags of row 0 or row 1.
    gc_tag *get_row(s32 row);
    s32 is_channel_active_at(s32 row, s32 index);
    s32 is_channel_active(s32 index);
    void set_tag(s32 row, s32 index, s32 mode, u16 slot);
    void set_tag_slot(s32 row, s32 index, s32 slot);
    void set_tag_mode(s32 row, s32 index, s32 mode);
    u16 get_tag_slot(s32 row, s32 index);
    u16 get_current_tag_slot(s32 index);
    u16 get_tag_mode(s32 row, s32 index);
    u16 get_current_tag_mode(s32 index);
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
    TPlyDispConfig *copy_full(TPlyDispConfig *src);
    // Initialises both palettes.
    void init();
    TPlyDispConfigSmth *ref_primary_palette();
    TPlyDispConfigSmth *ref_secondary_palette();
    int is_primary_first_bank();
    int test_photon_blast_modifier();
    void clear_primary_bank();
    void clear_secondary_bank();
    void set_primary_bank();
    void set_secondary_bank();
};

#endif
