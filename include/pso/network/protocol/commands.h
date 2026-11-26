/* The lobby server commands of Episode I & II Plus on GameCube, and the types that carry them.
 *
 * Every command starts with a packet_header (protocol.h): the command number, a flags byte whose
 * meaning depends on the command, and the size in bytes with the header. TProtocol::handle_command
 * (TProtocol.cpp) looks a received command up in its handler table. The handler copies the packet
 * into its type, swaps the bytes and passes it to the callback in TProtocol::m_recv_handlers, which
 * the TLobby constructor installs. The client sends its commands with the TProtocol::send_*
 * functions. The game subcommands that 60, 62, 6C and 6D carry are in subcmd_6x.h.
 *
 * The types are our own (TProtocol.h, packet_classes.h, choice_search.h); their comments give the
 * details. Their sizes agree with newserv (MIT licence, Copyright (c) 2024 Martin Michelsen; see
 * third_party/LICENSES/newserv-MIT.txt) except where our code says otherwise. Commands this client
 * neither sends nor handles are not listed.
 *
 * Received (handler table of TProtocol::handle_command):
 *   01        TMessageBox           recv_error -> handle_error
 *   02        TRecvPsoRegistConnect handle_cmd_02 (lobby server greeting; answered with 9E)
 *   03        packet_header         recv_regist -> TLobby::handle_register_name_result (flags)
 *   04        TPlyRecvLogin         recv_login -> TLobby::handle_login_result (flags: error code)
 *   05        packet_header         recv_logout -> TLobby::queue_static_object_destruction
 *   06        TMessageBox           recv_chat -> TWindowCtrl::handle_recv_chat
 *   07 A0 A1  TMenuList<GameListEntry, 64, 1>  recv_dir_list -> TLobby::open_ship_block_select_menu
 *   08        TMenuList<GameListEntry, 64, 1>  recv_game_list -> handle_game_list
 *   0E        TPlyStartGame         recv_start_game (no handler installed)
 *   11        TMessageBox           recv_message -> handle_server_message
 *   12 16 1C 14                     recv_banner, recv_banner_head, recv_system_file, recv_upload: empty
 *   13 A7     TRecvDownload         recv_download, recv_vm_download (acknowledged with TSendDownloadHead)
 *   17 9B     TRecvPsoRegistConnect handle_cmd_9B (port map greeting; answered with DB)
 *   18 90 9A  packet_header         handle_cmd_90, handle_cmd_9A -> TLobby::handle_verify_result (flags)
 *   19        TRecvPort             recv_port (reconnect to the address it carries)
 *   1A D5     TPlyText<1024>, TPlyText<0x1000>  recv_text, handle_cmd_D5 -> TLobby::open_scroll_text_window
 *   1B        packet_header         recv_battle_data (ignored)
 *   1D        packet_header         recv_ping (answered with 1D)
 *   1F        TMenuList<GameListEntry, 64, 1>  recv_text_list -> TLobby::open_information_list
 *   41        TUserAns              recv_user_ans -> handle_user_search_answer
 *   44 A6     TRecvDownloadHead     recv_download_head, recv_vm_download_head (acknowledged)
 *   60 62     TRecvPsoData          recv_pso_data (game subcommand)
 *   6C 6D     TRecvPsoDataLong      recv_pso_data_long (long game subcommand)
 *   64        TPlyJoinGame          recv_start_game3 -> TLobby::handle_game_join
 *   65 68     TPlyJoinLobby         recv_burst_game, recv_burst_lobby -> TLobby::on_game_player_add,
 *                                   TLobby::on_lobby_player_add
 *   66 69     TRecvExit             recv_exit_game, recv_exit_lobby -> TLobby::remove_player,
 *                                   TLobby::retire_lobby_player
 *   67        TPlyJoinLobby         recv_start_lobby2 -> TLobby::handle_lobby_enter
 *   80        TRecvGenerateID       recv_generate_id -> handle_generate_id
 *   81        TChatMessage          recv_chat_message -> receive_short_mail
 *   83        TMenuList<LobbyListEntry, 16, 0>  recv_room_info (keeps the lobby list)
 *   88        TArrowColorList       handle_cmd_88 -> apply_arrow_colors
 *   8A        TRecvLobbyName        handle_cmd_8A -> receive_lobby_name
 *   91        TRecvPsoRegistConnect recv_pso_regist_connect (port map greeting; answered with 90)
 *   92 9C     packet_header         handle_cmd_92, handle_cmd_9C -> TLobby::handle_register_result (flags)
 *   95        packet_header         handle_cmd_95 -> TLobby::send_selected_character (sends 61)
 *   97        packet_header         handle_cmd_97 -> TLobby::handle_state (flags)
 *   9F        packet_header         handle_cmd_9F (answered with TSendClientConfig)
 *   A2 A4     TMenuList<QuestListEntry, 30, 0>  recv_quest_menu_list, recv_quest_list ->
 *                                   copy_quest_list_data, TLobby::open_download_list_window
 *   A3 A5     TPlyText<288>         recv_quest_menu_info, recv_quest_info ->
 *                                   TQuestListOnline::receive_quest_info, show_card_list_message
 *   AB        TRecvQuestStats       handle_cmd_AB -> the lobby's AB handler
 *   AC        packet_header         handle_cmd_AC -> TQuestListOnline::handle_quest_ready (flags 0)
 *   B0        TMessageBox           recv_emergency_call -> TLobby::disable_window_flags
 *   B1        TRecvServerTime       handle_cmd_B1 -> TLobby::reset_lobby_state
 *   C0        TRecvChoiceSearchOptions  handle_cmd_C0 -> TLobby::handle_choice_search_options
 *   C4        ChoiceSearchResultList    handle_cmd_C4 -> TLobby::handle_choice_search_results
 *   C5        TRecvChallengeData    handle_cmd_C5 -> TLobby::copy_player_records
 *   D1 D4     packet_header         recv_advance_trade_state, recv_trade_result -> TLobby::apply_trade_items,
 *                                   TLobby::handle_reset_choice (flags)
 *   D3        TTradeList            handle_cmd_D3 -> handle_trade_received_items
 *   D7        packet_header         handle_cmd_D7 (sets lobby_count_value)
 *   D8        TRecvInfoBoard        handle_cmd_D8 -> TLobby::handle_info_board
 *   DA        packet_header         handle_cmd_DA -> TLobby::set_lobby_event_theme (flags: theme)
 *
 * Sent (TProtocol):
 *   03 04     TRegister             send_regist, send_login2
 *   05        packet_header         send_logout
 *   06        TMessageBox           send_chat
 *   08 1F     packet_header         send_game_list, send_text_list
 *   09 10     TSendAction           send_info, send_action
 *   13 44 A6 A7  TSendDownloadHead  acknowledgements from the download handlers
 *   1D        packet_header         send_keepalive, recv_ping
 *   40        TFindUser             send_find_user
 *   60 62     TRecvPsoData          send_pso_data, send_pso_data2
 *   61 98     TPlyJoinData          send_chara_data_v2, send_update_chara_data_v2
 *   6D        TRecvPsoDataLong      send_pso_data_long2
 *   6F        packet_header         send_6F_burst_done
 *   81        TChatMessage          send_simple_mail
 *   84        TRoomChange           send_room_change
 *   89        packet_header         send_lobby_arrow (flags: arrow colour)
 *   8A        packet_header         send_lobby_name_request
 *   90        TSendPsoRegistConnect recv_pso_regist_connect
 *   96        CharacterSaveInfoPacket  send_character_save_info
 *   99        packet_header         send_server_time_accepted
 *   9C        TSendPsoRegist        send_register_9c
 *   9E        TSendLogin            send_login_9e_extended, handle_cmd_02
 *   9F        TSendClientConfig     handle_cmd_9F
 *   A0 A1     ChangeShipOrBlockPacket  send_ship_list_request, send_block_list_request
 *   A2 A9     packet_header         send_quest_menu_request, send_quest_menu_closed
 *   AA        TSendQuestStatistic   send_statistic
 *   AC        packet_header         send_quest_barrier
 *   B1        packet_header         send_server_time_request
 *   C0 C8     packet_header         send_choice_search_options_request, send_disable_auto_reply
 *   C1        TCreateGame           send_create_game
 *   C2 C3     ChoiceSearchPacket    send_choice_search_parameters, send_choice_search
 *   C6        TBlockedSenders       send_c6_packet
 *   C7        TPlyText<512>         send_text_packet_c7
 *   D0        TTradeList            send_trade_list
 *   D2 D4 D6  packet_header         send_trade_ready, send_cancel_trade, send_message_box_closed
 *   D7        TSendDownloadHead     send_download_head
 *   D8        packet_header         send_info_board_request
 *   D9        TPlyText<172>         send_text_packet_D9
 *   DB        TSendVerifyLicense    handle_cmd_9B
 */

#ifndef PSO_PROTOCOL_COMMANDS_H
#define PSO_PROTOCOL_COMMANDS_H

#endif
