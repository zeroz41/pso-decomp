#ifndef PSO_PLAYER_TPLYDISPCONFIG_H
#define PSO_PLAYER_TPLYDISPCONFIG_H

#include "types.h"
#include "pso/player/TPlyGuildCardTag.h"

class TObjPlayer;

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
    s32 get_bank();
    // The tags of the row of the bank shown.
    gc_tag *get_current_row();
    s32 is_channel_active_at(s32 row, s32 index);
    s32 is_channel_active(s32 index);
    void set_tag(s32 row, s32 index, s32 mode, u16 slot);
    // set_tag; used to lay out the default palette (TObjPlayer::setup_effect_slots).
    void init_tag(s32 row, s32 index, s32 mode, u16 slot);
    void set_tag_slot(s32 row, s32 index, u16 slot);
    void set_tag_mode(s32 row, s32 index, s32 mode);
    u16 get_tag_slot(s32 row, s32 index);
    u16 get_current_tag_slot(s32 index);
    u16 get_tag_mode(s32 row, s32 index);
    u16 get_current_tag_mode(s32 index);
    // The slot (0-3) of the given row whose tag shows the action `type` (mode 1 tags match their mode,
    // the others their type and enabled flag), or -1; the player's lock-on palette override, when
    // active, is checked first and counts as slot 0.
    s32 find_action_slot(TObjPlayer *player, s16 type, s32 enabled, s32 row);
    // find_action_slot on the row of the bank shown.
    s32 find_action_slot_for_target(TObjPlayer *player, s16 type, s32 enabled);
    // Whether every tag of the given row (bank) is mode 0.
    int is_bank_empty(s32 bank);
public:
    s32 bank;  // the bank shown: 0 or 1
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
    int is_secondary_bank_empty(s32 bank);
};

#endif
