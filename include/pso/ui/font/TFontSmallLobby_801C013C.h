#ifndef PSO_UI_FONT_TFONTSMALLLOBBY_801C013C_H
#define PSO_UI_FONT_TFONTSMALLLOBBY_801C013C_H

#include "types.h"

struct G_ChangePlayerHP_6x2F;
struct G_LevelUpAllTechniques_6x9B;
struct G_SetPlayerBattleTeam_6x90;

extern "C" {
void TFontSmallLobby__sub_801C013C(void *flags);
void bswap_g_client_id_header(void *header);
void *TFontSmallLobby__sub_801C01DC(G_LevelUpAllTechniques_6x9B *dst, G_LevelUpAllTechniques_6x9B *src);
void *copy_subcommand_header(void *dst, void *src);
void assign_subcommand_header(void *dst, void *src);
void send_6x9B_level_up_all_techniques(void *packet);
void *TFontSmallLobby__sub_801C030C(void *dst, void *src);
void send_6x8F_add_battle_damage_scores(void *packet);
void *TFontSmallLobby__sub_801C03E0(G_SetPlayerBattleTeam_6x90 *dst, G_SetPlayerBattleTeam_6x90 *src);
void init_packet_6x90_set_player_battle_team(u8 *packet);
void init_packet_6x82_enable_drop_weapon_on_death(void *packet);
void send_6x82_enable_drop_weapon_on_death(void *packet);
void init_packet_6x81_disable_drop_weapon_on_death(void *packet);
void init_packet_6x7B_disable_stealth_suit_effect(void *packet);
void *TObjPlayer__sub_801C06BC(G_ChangePlayerHP_6x2F *dst, G_ChangePlayerHP_6x2F *src);
void TObjPlayer__sub_801C0734(void *player);
u8 *TObjPlayer__sub_801C07B4(u8 *dst, u8 *src);
void send_6x7B_disable_stealth_suit_effect(void *packet);
void init_packet_6x7A_enable_stealth_suit_effect(void *packet);
void init_packet_6x1C_disable_pk_mode_for_player(void *packet);
void send_6x1C_disable_pk_mode_for_player(void *packet);
void init_packet_6x1B_enable_pk_mode_for_player(void *packet);
void send_6x1B_enable_pk_mode_for_player(void *packet);
void init_packet_6x23_set_player_visible(void *packet);
void send_6x23_set_player_visible(void *packet);
void fn_801C0630(void *packet);
void fn_801C0644(void *packet);
}

#endif
