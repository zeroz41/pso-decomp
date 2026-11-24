#ifndef PSO_NETWORK_TPLYJOINLOBBYENTRY_H
#define PSO_NETWORK_TPLYJOINLOBBYENTRY_H

#include "types.h"
#include "pso/unk/TLobby.h"

class TProtocol;
struct TAdScrollWinGC;
struct TKeyBoardControl;
struct TLobby;
struct TWindowMakeTeam;
struct TWindowMenu;

extern TWindowMenu *TLobby_warp_menu_window;
extern TWindowMenu *lobby_com_card_window;
extern TWindowMenu *lobby_make_team_menu_window;
extern TWindowMakeTeam *lobby_make_team_window;
extern TWindowMenu *lobby_keyboard_prompt_window;
extern TKeyBoardControl *lobby_keyboard_controller;
extern TAdScrollWinGC *lobby_scroll_text_window;
// The idle-timeout warning window TLobby::update_idle_timeout opens.
extern TWindowMessage *TLobby__idle_timeout_object;

void handle_generate_id(void);
void handle_lobby_text(s32 text);
void handle_server_message(s32 text);
void handle_error(s32 text);
void update_state_with_location(void);
void lobby_init_hook(void);
void render_idle_timeout(void);
void init_6x6F_quest_flags_packet(void *p);
void *copy_disp_config(void *dst, void *src);
void *copy_disp_config_palette(void *p, void *a1);

extern "C" {
u8 *init_idle_timeout_timer(u8 *timer, saddr parent);
void queue_join_entry_exit_on_input(void *self);
void show_join_entry_message(s32 id);
void show_dialog_value_line(saddr text);
void *__ct__17TPlyJoinLobbyDataFv(void *self);
void copy_gc_tag(void *dst, void *src);
void *__ct__13GameListEntryFv(void *entry);
void *__ct__18TPlyJoinLobbyEntryFv(void *self);
void *__dt__18TPlyJoinLobbyEntryFv(void *self, s16 del);
void bswap_and_send_extended_subcommand(void *p, u32 size);
void bswap_extended_subcommand_header(void *p);
u8 *copy_player_data__9TProtocolFPvPv(u8 *arg0, u8 *arg1);
}
void handle_6x6F_set_quest_flags_v2(saddr pkt);
void handle_6x71_unblock_game_join(void);
void handle_6x72_done_loading_into_game(void);
extern "C" {
void init_6x72_resume_packet(void *p);
void open_lobby_warp_menu__6TLobbyFv(void);
void process_deferred_player_setup__6TLobbyFv(void);
void reset_state_flags__6TLobbyFv(void);
}
void send_6x6F_quest_flags(saddr size);
extern "C" {
void set_player_count__6TLobbyFi(int a0);
}

extern char lobby_ship_name[0x28];

// Lobby log lines, window titles and messages; defined at the end of TPlyJoinLobbyEntry.cpp,
// after the code that uses them.
extern const char lobby_debug_udp_open_format[];
extern const char lobby_debug_make_player_format[];
extern const char lobby_debug_burst_player_format[];
extern const char lobby_debug_duplicate_player_format[];
extern const char lobby_debug_create_player_format[];
extern const char lobby_debug_rcv_set_flag_format[];
extern const char lobby_debug_rcv_item_condition_format[];
extern const char lobby_debug_rcv_object_condition_format[];
extern const char lobby_debug_rcv_enemy_condition_format[];
extern const char lobby_window_title_download[];
extern const char lobby_debug_player_exit_format[];
extern const char lobby_debug_burst_overwrite_format[];
extern const char lobby_debug_delete_player_format[];
extern const char lobby_debug_udp_close_ip_format[];
extern const char lobby_debug_udp_close_player_format[];
extern const char lobby_debug_my_player_format[];
extern const char lobby_list_savedata_format[];
extern const char lobby_list_duplicate_my_player_format[];
extern const char lobby_list_block_range_format[];
extern const char lobby_debug_lobby_start_format[];
extern const char lobby_debug_game_start_format[];
extern const char lobby_msg_information_counter[];
extern const char lobby_window_title_information[];
extern const char lobby_window_title_ship_select[];
extern const char lobby_window_title_block_select[];
extern const char lobby_list_header_block[];
extern const char lobby_msg_login_success[];
extern const char lobby_msg_registed[];
extern const char lobby_msg_name_taken[];
extern const char lobby_msg_regist_check_ok[];
extern const char lobby_window_title_block_jump[];
extern const char lobby_window_title_ship_jump[];
extern const char lobby_window_title_taisen_team[];

#endif
