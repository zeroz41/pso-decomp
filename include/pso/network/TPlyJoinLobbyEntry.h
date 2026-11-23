#ifndef PSO_NETWORK_TPLYJOINLOBBYENTRY_H
#define PSO_NETWORK_TPLYJOINLOBBYENTRY_H

#include "types.h"

class TProtocol;
struct TAdScrollWinGC;
struct TKeyBoardControl;
struct TLobby;
struct TWindowMakeTeam;
struct TWindowMenu;

extern TProtocol *TLobby__protocol_instance;
extern TLobby *TLobby__join_lobby_controller;
extern TWindowMenu *TLobby_warp_menu_window;
extern TWindowMenu *lobby_com_card_window;
extern TWindowMenu *lobby_make_team_menu_window;
extern TWindowMakeTeam *lobby_make_team_window;
extern TWindowMenu *lobby_keyboard_prompt_window;
extern TKeyBoardControl *lobby_keyboard_controller;
extern TAdScrollWinGC *lobby_scroll_text_window;

extern "C" {
extern s32 TLobby__date_seconds;
extern s32 TLobby__event_theme_id;
u8 *init_idle_timeout_timer(u8 *arg0, saddr parent);
void TLobby__sub_80135FFC(void);
void TLobby__sub_801371B0(s32 arg0);
void TLobby__sub_80137228(s32 arg0);
void TLobby__sub_80137C10(s32 arg0);
void TLobby__sub_801384E4(void);
void queue_join_entry_exit_on_input(void *self);
void show_join_entry_message(s32 arg0);
void show_dialog_value_line(saddr arg0);
void TLobby__sub_8013A16C(void);
void *TLobby__sub_8013A23C(void *record);
void TLobby__sub_8013A2DC(void);
void TLobby__sub_8013A578(void *p);
void *TObjPlayer__sub_8013A748(void *arg0, void *arg1);
void *TObjPlayer__sub_8013A788(void *p, void *a1);
void TObjPlayer__sub_8013A820(void *arg0, void *arg1);
void *__ct__13GameListEntryFv(void *entry);
s32 __dt__18TPlyJoinLobbyEntryFv(saddr arg0, s16 arg1);
void bswap_and_send_extended_subcommand(void *p, u32 size);
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
}
void send_6x6F_quest_flags(saddr arg0);
extern "C" {
void set_player_count__6TLobbyFi(int a0);
}

#endif
