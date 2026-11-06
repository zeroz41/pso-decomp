#ifndef PSO_UI_FONT_TFONTSMALLLOBBY_H
#define PSO_UI_FONT_TFONTSMALLLOBBY_H

#include "types.h"

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
    static void send_photon_blast_ready();
    void update_if_ready();
    void reset_state();
    static int is_valid_index(s16 arg0);
    void reset_fields();
    int set_bit1_at_40();
    void*clear_photon_blast_ready_flag();
    int update_ready();
    s32 get_state();
    s32 get_field_04();
    int check_flag_at_40();
    void set_target_count(s32 v);
    void set_target_index(s32 v);
    int set_flag_40_bit5();
    int update_field_40();
    void*init_reset_fields();
    void init_pkt_cmd_3B();
    void update_and_send();
    void init_6x3A_packet();
    void draw_and_send();
    void init_6x39_packet();
    void update_and_send_60();
    void bswap_fields();
    void*copy_packet_header_6x38(void* a1);
    void send_state();
    void*handle_photon_blast_ready();
    static void *create(void *arg0);
    s16 get_valid_index();
    void set_section_index(s16 arg1);
    s32 is_ready();
    void reset_targets();
    s32 construct_pb_controller();
    static s32 disable_stealth_suit_effect(s32 arg0, void * _w1);
};

#endif
