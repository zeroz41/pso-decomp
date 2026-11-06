#ifndef PSO_UNK_TLOBBY_801C25B4_H
#define PSO_UNK_TLOBBY_801C25B4_H

#include "types.h"

class TPlayerBattleCtrl;
extern "C" {
u8 TLobby__sub_801C2614(void);
s32 TLobby__sub_801C2678(void);
s32 TLobby__sub_801C26A8(void);
void TLobby__sub_801C2C34(void);
void TLobby__sub_801C36E4(void *arg0, void *arg1);
void TLobby__sub_801C38A4(void);
void TLobby__sub_801C38E8(void *arg0);
void TLobby__sub_801C3A40(void);
s32 TLobby__sub_801C417C(void);
void *__dt__13TUnk_804C3E88Fv(void *arg0, s16 arg1);
void apply_game_settings__6TLobbyFii(s32 arg0, s32 arg1);
s32 assign_player_id__6TLobbyFv(void);
s32 check_all_battle_flags__6TLobbyFv(void);
s32 check_all_players_ready__6TLobbyFv(void);
u8 check_battle_end__6TLobbyFv(void);
u8 check_timeout__6TLobbyFPv(void *arg0);
void clear_battle_player_ready_flags(void);
void clear_counter__6TLobbyFPv(void *a0);
void close_and_play_effect__6TLobbyFii(int arg0, s32 arg1);
void destroy_matching_children__6TLobbyFv(void *arg0);
void end_battle_mode_cleanup__6TLobbyFPv(void *arg0);
void finish_chr_select_scene_init__6TLobbyFv(void);
s32 fn_801C4CE0(TPlayerBattleCtrl *arg0);
void handle_6x7E(void);
void handle_6x7F_battle_scores(s32 arg0);
void handle_battle_result__6TLobbyFii(int arg0, s32 arg1);
void init__6TLobbyFPv(void *arg0);
void init_and_set_flag__6TLobbyFv(void);
void init_battle_ctrl__6TLobbyFii(s32 arg0, s32 arg1);
void init_battle_round__17TPlayerBattleCtrlFv(void *arg0);
void init_char_slots__6TLobbyFv(void);
void *init_with_name__6TLobbyFPvPvPvPv(void *arg0, void *arg1, void *arg2, void *arg3);
s32 record_local_battle_placement(void *arg0);
void release_ref__6TLobbyFPv(u8 *arg0);
void send_6x7D_set_battle_mode_data(void);
void send_battle_mode_params__6TLobbyFcii(s8 arg0, s32 arg1, s32 arg2);
void send_battle_mode_state__6TLobbyFPv(void *self);
void send_neg50__6TLobbyFPvPv(void *p, void *a1);
void set_flag_270__6TLobbyFPv(void *arg0);
void show_score_results__6TLobbyFPv(void *self);
void update_duel_result__6TLobbyFPv(u8 *arg0);
void update_player_battle_ctrl_state(void *arg0);
}

#endif
