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
    TPlyDispConfig *copy_full(TPlyDispConfig *src);
    TPlyDispConfigSmth *get_primary();
    TPlyDispConfigSmth *get_secondary();
    int is_primary_first_bank();
    int is_secondary_first_bank();
    void clear_primary_bank();
    void clear_secondary_bank();
    void set_primary_bank();
    void set_secondary_bank();
};

#endif
