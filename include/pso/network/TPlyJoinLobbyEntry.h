#ifndef PSO_NETWORK_TPLYJOINLOBBYENTRY_H
#define PSO_NETWORK_TPLYJOINLOBBYENTRY_H

#include "types.h"

extern "C" {
extern s32 TLobby__date_seconds;
extern s32 TLobby__event_theme_id;
u8 *TLobby__ct(u8 *arg0, void *arg1);
u8 *init_idle_timeout_timer(u8 *arg0, saddr arg1);
void TLobby__sub_80135FFC(void);
void TLobby__sub_801371B0(s32 arg0);
void TLobby__sub_80137228(s32 arg0);
void TLobby__sub_80137C10(s32 arg0);
void TLobby__sub_801384E4(void);
void queue_join_entry_exit_on_input(void *self);
void show_join_entry_message(s32 arg0);
void show_dialog_value_line(saddr arg0);
void TLobby__sub_8013A16C(void);
s32 TLobby__sub_8013A23C(s32 arg0);
void TLobby__sub_8013A2DC(void);
void TLobby__sub_8013A578(void *p);
void *TObjPlayer__sub_8013A748(void *arg0, void *arg1);
void *TObjPlayer__sub_8013A788(void *p, void *a1);
void TObjPlayer__sub_8013A820(void *arg0, void *arg1);
s32 __ct__13GameListEntryFv(s32 arg0);
s32 __dt__18TPlyJoinLobbyEntryFv(saddr arg0, s16 arg1);
u8 *__dt__6TLobbyFv(u8 *arg0, s16 arg1);
void bswap_and_send_extended_subcommand(void *p, void *a1);
void bswap_extended_subcommand_header(void *p);
u8 *copy_player_data__9TProtocolFPvPv(u8 *arg0, u8 *arg1);
}
void handle_6x6F_set_quest_flags_v2(saddr arg0);
void handle_6x71_unblock_game_join(void);
void handle_6x72_done_loading_into_game(void);
extern "C" {
void init_6x72_resume_packet(void *p);
void open_lobby_warp_menu__6TLobbyFv(void);
void process_deferred_player_setup__6TLobbyFv(void);
void reset_state_flags__6TLobbyFv(void);
void run_task__6TLobbyFv(void *self);
}
void send_6x6F_quest_flags(saddr arg0);
extern "C" {
void set_player_count__6TLobbyFi(int a0);
}

#endif
