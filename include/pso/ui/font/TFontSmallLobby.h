#ifndef PSO_UI_FONT_TFONTSMALLLOBBY_H
#define PSO_UI_FONT_TFONTSMALLLOBBY_H

#include "types.h"

// Class name of the lobby player label TObject (TObjPlayer checks its m_54c object by it).
extern const char *TFontSmallLobby__name;

struct TFontSmallLobby
{
    u8 _pad1C[0x40C];
    void* m_428;
    u8 _pad42C[0x80];
    void* m_4ac;
    u8 _pad4B0[0x9C];
    u32 m_54c;
    u8 _pad550[0x60];
    void* m_5b0;
    void init_packet_6x9b_level_up();
    void bswap_battle_damage_packet();
    void init_packet_6x8f_battle_damage();
    void bswap_6x90_set_player_battle_team();
    void send_font_state_msg();
    void send_photon_blast_ready();
    void update_if_ready();
    void reset_state();
    static int is_valid_index(s16 arg0);
    void reset_fields();
    void set_bit1_at_40();
    void *clear_photon_blast_ready_flag(void *src);
    void update_ready();
    s32 get_state();
    s32 get_field_04();
    void check_flag_at_40();
    void set_target_count(s32 v);
    void set_target_index(s32 v);
    void set_flag_40_bit5();
    void update_field_40();
    void*init_reset_fields();
    void init_pkt_cmd_3B();
    void update_and_send();
    void init_6x3A_packet();
    void draw_and_send();
    void init_6x39_packet();
    void update_and_send_60();
    void bswap_fields();
    void*copy_packet_header_6x38(void* source);
    void send_state();
    void *handle_photon_blast_ready(void *src);
    static void *create(s32 id);
    s16 get_valid_index();
    void set_section_index(s16 count);
    s32 is_ready();
    void reset_targets();
    s32 construct_pb_controller();
    static s32 disable_stealth_suit_effect(s32 arg0, void * _w1);
    static s32 is_lobby_floor_15();
    static void draw_small_label(int);
    static s32 draw_party_label(int, unsigned int, u16);
    static u16 get_type(void* p);
};

extern "C" {
// Sends 6x39 for the gauge's client id: its photon blast is ready.
void send_6x39_photon_blast_ready(u16 *client_id);
// Sends 6x3A for the gauge's client id: its photon blast is no longer ready.
void send_6x3A_clear_photon_blast_ready_flag(u16 *client_id);
}

#endif
