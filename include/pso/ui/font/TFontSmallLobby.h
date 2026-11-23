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
    static void *create(s32 id);
    static s32 disable_stealth_suit_effect(s32 client_addr, void *command);
    static s32 is_lobby_floor_15();
    static void draw_small_label(int line);
};


#endif
