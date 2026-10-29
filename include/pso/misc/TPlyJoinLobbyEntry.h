#ifndef PSO_MISC_TPLYJOINLOBBYENTRY_H
#define PSO_MISC_TPLYJOINLOBBYENTRY_H

#include "types.h"

extern "C" {
extern s32 TLobby__date_seconds;
extern s32 TLobby__event_theme_id;
u8 *TLobby__ct(u8 *arg0, void *arg1);
u8 *TLobby__sub_80135198(u8 *arg0, s32 arg1);
void TLobby__sub_80135FFC(void);
void TLobby__sub_801371B0(s32 arg0);
void TLobby__sub_80137228(s32 arg0);
void TLobby__sub_80137C10(s32 arg0);
void TLobby__sub_801384E4(void);
void TLobby__sub_80139094(void *self);
void TLobby__sub_801397E8(s32 arg0);
void TLobby__sub_80139894(s32 arg0);
void TLobby__sub_8013A16C(void);
s32 TLobby__sub_8013A23C(s32 arg0);
void TLobby__sub_8013A2DC(void);
void TLobby__sub_8013A578(void *p);
void *TObjPlayer__sub_8013A748(void *arg0, void *arg1);
void *TObjPlayer__sub_8013A788(void *p, void *a1);
void TObjPlayer__sub_8013A820(void *arg0, void *arg1);
s32 __ct__13GameListEntryFv(s32 arg0);
s32 __dt__18TPlyJoinLobbyEntryFv(s32 arg0, s16 arg1);
u8 *__dt__6TLobbyFv(u8 *arg0, s16 arg1);
void bswap_6x6E_sync_game_state__6TLobbyFPv(void *p);
void bswap_and_handle_packet__6TLobbyFii(s32 arg0, s32 arg1);
void bswap_and_send_extended_subcommand(void *p, void *a1);
void bswap_extended_subcommand_header(void *p);
void bswap_header_fields__6TLobbyFi(s32 arg0);
void bswap_inventory__6TLobbyFPv(void *p);
void bswap_player_data__6TLobbyFi(s32 arg0);
int close_all_windows__6TLobbyFPv(void *p);
void close_all_windows__6TLobbyFv(void);
void close_and_send_text_list__6TLobbyFv(void);
void close_and_set_state_12__6TLobbyFv(void);
void close_and_set_state_13__6TLobbyFv(void);
void close_com_card_window__6TLobbyFv(void);
void close_menu_windows__6TLobbyFv(void);
void construct_global_arrays__6TLobbyFv(void);
u8 *copy_player_data__9TProtocolFPvPv(u8 *arg0, u8 *arg1);
void create_warp_menu__6TLobbyFv(void);
void destroy_all_objects__6TLobbyFv(void);
void destroy_join_entries__6TLobbyFv(void);
void destroy_lobby_ui__6TLobbyFv(void);
void disable_window_flags__6TLobbyFPv(void *a0);
int get_seq_phase__6TLobbyFPv(void *p);
}
void handle_6x6F_set_quest_flags_v2(s32 arg0);
void handle_6x71_unblock_game_join(void);
void handle_6x72_done_loading_into_game(void);
extern "C" {
void handle_com_card__6TLobbyFv(void);
void handle_comcard_window__6TLobbyFv(void);
void handle_create_game_window__6TLobbyFv(void);
void handle_game_list_select__6TLobbyFv(void);
void handle_login_result__6TLobbyFUi(u32 arg0);
void handle_regist_check__6TLobbyFi(s32 ok);
void handle_register_name_result__6TLobbyFi(s32 ok);
void handle_register_result__6TLobbyFi(s32 arg0);
void handle_short_list_input__6TLobbyFv(void);
void handle_state__6TLobbyFi(s32 arg0);
void handle_team_select__6TLobbyFv(void);
void handle_verify_result__6TLobbyFUi(u32 arg0);
void handle_warp_menu_input__6TLobbyFv(void);
void init_6x72_resume_packet(void *p);
void *init_char_data__6TLobbyFPv(void *p);
void init_player_window_effect__6TLobbyFv(void);
void on_game_player_add__6TLobbyFiii(s32 arg0, s32 arg1, s32 arg2);
void on_lobby_player_add__6TLobbyFii(s32 arg0, s32 arg1);
void open_city_warp_menu__6TLobbyFv(void);
void open_hard_keyboard__6TLobbyFPv(void *p);
void open_keyboard_window__6TLobbyFv(void);
void open_lobby_warp_menu__6TLobbyFv(void);
void open_make_team_window__6TLobbyFi(s32 arg0);
void open_menu_window__6TLobbyFv(void);
void open_warp_menu__6TLobbyFv(void);
void process_deferred_player_setup__6TLobbyFv(void);
void queue_static_object_destruction__6TLobbyFv(void);
void remove_player__6TLobbyFUiii(u32 arg0, s32 arg1, s32 arg2);
void request_game_list__6TLobbyFv(void);
void reset_state__6TLobbyFv(void);
void reset_state_flags__6TLobbyFv(void);
void retire_lobby_player__6TLobbyFii(s32 idx, s32 v);
void return_to_main_menu__6TLobbyFv(void);
void run_join_lobby_connect__6TLobbyFi(s32 arg0);
void run_task__6TLobbyFv(void *self);
void send_6x6E_sync_game_state__6TLobbyFi(s32 arg0);
}
void send_6x6F_quest_flags(s32 arg0);
extern "C" {
void send_6x70_player_data__6TLobbyFi(s32 arg0);
void send_cmd_6B__6TLobbyFv(s32 arg0);
void send_compressed_packet_6c__6TLobbyFv(s32 arg0);
void send_logout__6TLobbyFv(void);
void send_packet_60__6TLobbyFi(s32 arg0);
void send_position_update__6TLobbyFv(void);
void send_room_change__6TLobbyFi(s32 arg0);
void send_selected_character__6TLobbyFv(void);
void set_menu_mode_0__6TLobbyFv(void);
void set_menu_mode_1__6TLobbyFv(void);
void set_menu_mode_2__6TLobbyFv(void);
void set_player_count__6TLobbyFi(int a0);
void show_seq_phase_message__6TLobbyFi(s32 arg0);
void update__6TLobbyFv(void);
void update_block_jump_list__6TLobbyFv(void);
void update_card_list_window__6TLobbyFv(void);
void update_com_card_window__6TLobbyFv(void);
void update_game_list_menu__6TLobbyFv(void);
void update_idle_timeout__6TLobbyFPv(u8 *arg0);
void update_make_team_menu__6TLobbyFv(void);
void update_menu_window__6TLobbyFv(void);
void update_player_window__6TLobbyFv(void);
void update_scroll_close__6TLobbyFv(void);
void update_ship_select_window__6TLobbyFv(void);
void update_short_list__6TLobbyFv(void);
void update_state__6TLobbyFv(void);
}

#endif
