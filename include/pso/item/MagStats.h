#ifndef PSO_ITEM_MAGSTATS_H
#define PSO_ITEM_MAGSTATS_H

#include "types.h"

// A mag's stats as the game keeps them (TItemMag + 0x198, and the copies
// TItemData::deserialize_mag unpacks from an item's data). DEF, POW, DEX
// and MIND count in hundredths: the hundreds are the stat's level, the rest
// its progress to the next one, and the four levels add up to the mag's
// level (at most 200).
struct MagStats {
    // Clears the stats; returns this.
    MagStats *init();
    // A new mag: level 5 DEF, 0 IQ, 40% synchro, colour 18.
    void clear();
    s16 get_level();
    s16 get_def_level();
    s16 get_pow_level();
    s16 get_dex_level();
    s16 get_mind_level();
    s16 get_def_progress();
    s16 get_pow_progress();
    s16 get_dex_progress();
    s16 get_mind_progress();
    // Feeding: a stat may not drop below its level, and at level 200 it
    // may only fill up to its next level.
    void add_def(s16 amount);
    void add_pow(s16 amount);
    void add_dex(s16 amount);
    void add_mind(s16 amount);
    // IQ stays within 0-200, synchro within 0-120.
    void add_iq(s32 amount);
    void add_synchro(s32 amount);
    s16 get_iq();
    s16 get_synchro();
    u8 get_color();
    // The photon blast in slot 0-2 (left, right, centre), -1 for none.
    s32 get_photon_blast(s32 slot);
    s32 has_photon_blast(u8 blast);
    // Puts blast (0-5) in the first free slot, unless the mag has it.
    void add_photon_blast(u8 blast);

    s16 iq;
    s16 synchro;
    s16 def;
    s16 pow;
    s16 dex;
    s16 mind;
    // Bits 0-2: slots 0-2 hold a blast. The centre slot stores the blast's
    // rank among the four the other two slots leave.
    u8 photon_blast_flags;
    u8 photon_blasts;
    u8 color;
    u8 pad_f;
};

// The photon_blasts field of each slot, and its photon_blast_flags bit
// (TItemMagSub.cpp).
extern const u8 photon_blast_masks[3];
extern const u8 photon_blast_slots[3];

LAYOUT_ASSERT(MagStatsSize, sizeof(MagStats) == 0x10);

#endif
