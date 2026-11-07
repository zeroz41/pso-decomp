#ifndef PSO_UI_FONT_TFONTSMALLLOBBY_801C013C_H
#define PSO_UI_FONT_TFONTSMALLLOBBY_801C013C_H

#include "types.h"

extern "C" {
int TFontSmallLobby__sub_801C013C(void *p);
void *TFontSmallLobby__sub_801C0164(void *arg0);
void bswap_g_client_id_header(void *p);
void *TFontSmallLobby__sub_801C01DC(void *arg0, void *arg1);
void *TFontSmallLobby__sub_801C0228(void *p, void *_w1);
void TFontSmallLobby__sub_801C0258(void *p, void *q);
void send_6x9B_level_up_all_techniques(void *p);
void *TFontSmallLobby__sub_801C030C(void *p, void *a1);
void send_6x8F_add_battle_damage_scores(void *p);
void *TFontSmallLobby__sub_801C03E0(void *arg0, void *arg1);
void init_packet_6x90_set_player_battle_team(u8 *arg0);
void init_packet_6x82_enable_drop_weapon_on_death(void *p);
void send_6x82_enable_drop_weapon_on_death(void *p);
void init_packet_6x81_disable_drop_weapon_on_death(void *p);
void init_packet_6x7B_disable_stealth_suit_effect(void *p);
void *TObjPlayer__sub_801C06BC(void *arg0, void *arg1);
void TObjPlayer__sub_801C0734(void *p);
u8 *TObjPlayer__sub_801C07B4(u8 *arg0, u8 *arg1);
void send_6x7B_disable_stealth_suit_effect(void *p);
void init_packet_6x7A_enable_stealth_suit_effect(void *p);
void init_packet_6x1C_disable_pk_mode_for_player(void *p);
void send_6x1C_disable_pk_mode_for_player(void *p);
void init_packet_6x1B_enable_pk_mode_for_player(void *p);
void send_6x1B_enable_pk_mode_for_player(void *p);
void init_packet_6x23_set_player_visible(void *p);
void send_6x23_set_player_visible(void *p);
void fn_801C0630(void *p);
void fn_801C0644(void *p);
}

#endif
