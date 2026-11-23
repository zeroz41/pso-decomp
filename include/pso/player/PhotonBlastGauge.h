#ifndef PSO_PLAYER_PHOTONBLASTGAUGE_H
#define PSO_PLAYER_PHOTONBLASTGAUGE_H

#include "types.h"

class TObjChara;

// One photon blast target: the entity id and its part index (find_entity_by_id
// and set_cursor_pos read them).
struct PhotonBlastTarget {
    u16 entity_id;
    s16 index;
};

// The 8-byte state at PhotonBlastGauge + 0x4C. draw_party_label (the 6x38
// donate path) sets the first word to 8 and adds one to the second; is_ready
// needs the second below 3 (inferred: a donation cooldown and count).
struct Obj_801D67D4 {
    void reset_fields();
    s32 get_state();
    s32 get_field_04();
    void set_target_count(s32 v);
    void set_target_index(s32 v);
    void fn_801D671C(int n);
    void *init_reset_fields();

    s32 state;
    s32 count;
};

// A player's photon blast state (TObjPlayer + 0x4AC): the charge the mag's
// support events and the photon blast window read.
struct PhotonBlastGauge {
    PhotonBlastGauge();
    ~PhotonBlastGauge();
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
    s32 fn_801D5DDC();
    s16 get_valid_index();
    void set_section_index(s16 count);
    void reinit_photon_blast_gauge();
    void send_6x3A_clear_photon_blast_ready_flag();
    void send_6x39_photon_blast_ready();
    s32 is_ready();
    void reset_targets();
    void draw_party_label(TObjChara *target, u16 effect);
    s32 subtract_photon_blast_charge(f32 amount);
    void add_photon_blast_charge(f32 amount);
    void send_photon_blast_ready();
    void update_if_ready();
    void reset_photon_blast_gauge();
    void reset_state();
    static int is_valid_index(s16 blast);
    void set_bit1_at_40();
    void update_ready();
    void check_flag_at_40();
    void set_flag_40_bit5();
    void update_field_40();
    void fn_801D677C();
    u16 get_type();
    s32 fn_801D67AC();
    void fn_801D67C8();
    void clear_photon_blast_state();
    void trigger_photon_blast();
    void check_photon_blast_flag();
    void set_field_3c(f32 v);
    void start_photon_blast_action();
    f32 get_dist();
    int query_field40();

    // The owner's client id, sent in the 6x39/6x3A packets.
    u16 client_id;
    // The blast in use (0-5, -1 for none; is_valid_index).
    s16 blast;
    // How many of targets are in use (0-10).
    s16 target_count;
    u8 pad_6[0x2];
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
    u8 pad_4a[0x2];
    Obj_801D67D4 donation;
};

LAYOUT_ASSERT(PhotonBlastGaugeSize, sizeof(PhotonBlastGauge) == 0x54);

#endif
