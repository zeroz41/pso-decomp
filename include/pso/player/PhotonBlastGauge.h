#ifndef PSO_PLAYER_PHOTONBLASTGAUGE_H
#define PSO_PLAYER_PHOTONBLASTGAUGE_H

#include "types.h"

// One photon blast target: the entity id and its part index (find_entity_by_id
// and set_cursor_pos read them).
struct PhotonBlastTarget {
    u16 entity_id;
    s16 index;
};

// A player's photon blast state (TObjPlayer + 0x4AC): the charge the mag's
// support events and the photon blast window read.
struct PhotonBlastGauge {
    // Empties the charge.
    void clear_charge();
    f32 get_charge();
    // The equipped mag's level for blast (0-5), -1 when no mag holds it.
    void set_blast_level(s16 blast, s8 level);
    int check_flag_clear();
    int fn_801D2A50();
    void fn_801D2A78(f32 threshold);
    s32 fn_801D2A80();
    void fn_801D2A88();
    f32 fn_801D2A98();
    void set_field_0c(f32 v);
    void set_field8(s32 v);
    PhotonBlastTarget *fn_801D2AB0(s32 i);
    int fn_801C1F50();

    u8 pad_0[0x8];
    // Loaded from the blast's table entry, counted down each frame of the blast.
    s32 countdown;
    // Added to the player's motion frame each frame of the blast.
    f32 frame_step;
    // Set from get_photon_blast_complete_threshold() when the blast ends.
    f32 complete_threshold;
    PhotonBlastTarget targets[10];
    f32 charge;
    s32 flags;
    s8 blast_levels[6];
    u8 pad_4a[0xA];
};

LAYOUT_ASSERT(PhotonBlastGaugeSize, sizeof(PhotonBlastGauge) == 0x54);

#endif
