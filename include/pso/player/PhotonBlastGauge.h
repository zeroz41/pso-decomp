#ifndef PSO_PLAYER_PHOTONBLASTGAUGE_H
#define PSO_PLAYER_PHOTONBLASTGAUGE_H

#include "types.h"
#include "pso/system/data/FlagWord.h"
#include <stddef.h>

class TObjChara;

// One photon blast target: the entity id and its part index (find_entity_by_id
// and set_cursor_pos read them).
struct PhotonBlastTarget {
    PhotonBlastTarget();
    // No target: entity_id 0xFFFF, part 0.
    void reset();
    void set_entity_id(s32 id);
    void set_index(s16 part);
    void bswap();

    u16 entity_id;
    s16 index;
};

void copy_tech_params(PhotonBlastTarget *dst, PhotonBlastTarget *src);

// The photon blast donation state at PhotonBlastGauge + 0x4C. draw_party_label
// (the 6x38 donate path) sets state to 8 and adds one to count; is_ready needs
// count below 3.
struct PhotonBlastDonation {
    void reset_fields();
    s32 get_state();
    s32 get_field_04();
    void set_target_count(s32 v);
    void set_target_index(s32 v);
    void add_count(int n);
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
    int is_blast_launched();
    void set_complete_threshold(f32 threshold);
    s32 get_countdown();
    void decrement_countdown();
    f32 get_frame_step();
    void set_field_0c(f32 v);
    void set_field8(s32 v);
    PhotonBlastTarget *get_target(s32 i);
    int has_ready_flag();
    s32 get_target_count();
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
    static int is_valid_index(s16 index);
    void set_bit1_at_40();
    void update_ready();
    void check_flag_at_40();
    void set_flag_40_bit5();
    void update_field_40();
    void set_charge_capped();
    u16 get_type();
    s32 is_photon_blast_charge_full();
    void reset_blast();
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
    FlagWord flags;
    s8 blast_levels[6];
    u8 pad_4a[0x2];
    PhotonBlastDonation donation;
};

LAYOUT_ASSERT(PhotonBlastGaugeFlagOffset, offsetof(PhotonBlastGauge, flags) == 0x40);
LAYOUT_ASSERT(PhotonBlastGaugeSize, sizeof(PhotonBlastGauge) == 0x54);

extern "C" void add_photon_blast_chain_charge(PhotonBlastGauge *gauge, f32 amount);

#endif
