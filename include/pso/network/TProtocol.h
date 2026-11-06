#ifndef PSO_NETWORK_TPROTOCOL_H
#define PSO_NETWORK_TPROTOCOL_H

#include "types.h"
#include <string.h>
#include "pso/macros.h"
#include "pso/forward.h"
#include "pso/packet_classes.h"
#include "pso/protocol.h"
#include "pso/protocol/choice_search.h"
#include "pso/PSOV3EncryptionTCP.h"
#include "pso/THeap.h"
#include "pso/TMainTask.h"
#include "pso/TMenuList.h"
#include "pso/TObject.h"
#include "pso/player/TPlyCharData.h"
#include "pso/player/TPlyClientConfig.h"
#include "pso/player/TPlyGuildCardTag.h"
#include "pso/player/TPlySmth.h"
#include "pso/TSocket.h"
#include "pso/network/TTcpSocket.h"

/* TProtocol - PSO network protocol handler.
 * Derived from pso-gc-reference decomp (mrb0nk500).
 * Adapted for GPOE8P (PSO EP I&II Plus, MWCC 2.6).
 */


EXTERN_OBJECT_NAME(TProtocol);
extern int enable_v2_features;
extern u32 new_ip_addr;
extern u16 new_port;
extern TPlyMeetUserExtension meet_user_settings;
extern u32 game_variations[16][2];
extern void copy_packet(struct packet *pkt);

class TBlockedSenders {
public:
    packet_header header;
    u32 blocked_senders[30];
public:
    void bswap() {
        header.bswap();
        for (int i = 0; i < 30; ++i) {
            bswap_32(&blocked_senders[i]);
        }
    };
};

class TSendPsoRegistConnect {
public:
    packet_header header;
    char serial_number[17];
    char access_key[17];
    u16 padding;
public:
    void bswap();
};

class TRecvPsoRegistConnect {
public:
    packet_header header;
    char copyright[64];
    u32 server_key;
    u32 client_key;
public:
    void bswap() {
        header.bswap();
        bswap_32(&server_key);
        bswap_32(&client_key);
    };
};

struct _packet {
    void bswap() {
        header.bswap();
    };
    packet_header header;
    u8 data[];
};

template<size_t n = 0>
union flex_packet {
    struct _packet pkt;
    u8 bytes[(n) ? n : sizeof(packet_header)];
};

struct packet : public flex_packet<0x7c00> {};

#define RECV_PACKET_HANDLERS \
    o(handle_unused_login, void) \
    o(handle_03_recv_regist, u8 state) \
    o(handle_04_recv_login, u8 error_code) \
    o(handle_05_recv_logout, void) \
    o(handle_07_A0_A1_recv_dir_list, int entry_count, GameListEntry *entries, GameListEntry &entry_0) \
    o(handle_08_recv_game_list, int entry_count, GameListEntry *entries, GameListEntry &entry_0) \
    o(handle_01_recv_error, char *mesg) \
    o(handle_06_recv_chat, TPlyGuildCardTag &tag, char *mesg) \
    o(handle_11_recv_message, char *mesg, u8 unused) \
    o(handle_1A_D5_recv_text, char *text) \
    o(handle_0E_recv_start_game, TPlyJoinLobbyData *entries, u8 entry_count, int lobby_entry_idx) \
    o(unused7, void) \
    o(handle_64_recv_start_game3, TPlyJoinGame &join_data) \
    o(unused8, void) \
    o(handle_67_recv_start_lobby2, TPlyJoinLobbyEntry *entries, u8 entry_count, int client_id, int leader_id, int lobby_number, int block_number, int smth, int event) \
    o(handle_80_recv_generate_id, TRecvGenerateID gen_id) \
    o(unused9, void) \
    o(handle_65_recv_burst_game, TPlyJoinLobbyEntry *entries, int leader_id, int disable_udp) \
    o(handle_66_recv_exit_game, int client_id, int leader_id, int disable_udp) \
    o(handle_68_recv_burst_lobby, TPlyJoinLobbyEntry *entries, int leader_id) \
    o(handle_69_recv_exit_lobby, int client_id, int leader_id) \
    o(handle_18_90_9A_recv_pso_regist_check, u8 state) \
    o(handle_92_9C_register_response_packet, void) \
    o(unused10, void) \
    o(handle_95_request_character_data_packet, void) \
    o(handle_81_recv_chat_message, TChatMessage &chat_message) \
    o(handle_41_recv_user_ans, TUserAns &user_ans) \
    o(send_96_unused, void) \
    o(handle_97_checksum_reply_packet, void) \
    o(handle_B1_current_time_packet, void) \
    o(handle_C0_choice_search_option_packet, void) \
    o(handle_C4_choice_search_reply_packet, void) \
    o(handle_D8_infoboard_packet, void) \
    o(handle_A2_recv_quest_menu_list, TMenuList<QuestListEntry, 30, 0> &quest_list) \
    o(handle_A3_recv_quest_menu_info, TPlyText<288> &info) \
    o(handle_44_recv_download_head, TRecvDownloadHead &download_head) \
    o(handle_13_recv_download, TRecvDownload &download) \
    o(handle_A4_recv_quest_list, u8 entry_count, TMenuList<QuestListEntry, 30, 0> &quest_list) \
    o(handle_A5_recv_quest_info, TPlyText<288> &info) \
    o(handle_A6_recv_vm_download_head, TRecvDownloadHead &download_head) \
    o(handle_A7_recv_vm_download, TRecvDownload &download) \
    o(unused11, void) \
    o(handle_1F_recv_text_list, int entry_count, GameListEntry *entries, GameListEntry &entry_0) \
    o(handle_B0_recv_emergency_call, char *mesg) \
    o(handle_88_player_arrow_color_list_packet, void) \
    o(handle_8A_lobby_name_packet, void) \
    o(handle_C5_player_challenge_data_packet, void) \
    o(handle_DA_lobby_event_packet, void) \
    o(handle_AB_quest_stats_response_packet, void) \
    o(handle_D3_execute_trade_packet, void) \
    o(handle_D4_trade_result_packet, u8 state) \
    o(handle_D1_advance_trade_state_packet, u8 state)

#define recv_packet_handler(name) recv_packet_handler_##name

#define o(name, ...) typedef void (*recv_packet_handler(name))(__VA_ARGS__);
RECV_PACKET_HANDLERS;
#undef o

struct recv_packet_handlers {
    #define o(name, ...) recv_packet_handler(name) name;
    RECV_PACKET_HANDLERS;
    #undef o
};

typedef void (TProtocol::*command_handler)(packet &pkt);

struct command_handler_entry {
    int command;
    command_handler handler;
};

class TProtocol : public TTcpSocket {
public:
    TPlySmth m_smth;
    TPlyGuildCardTag m_guildcard_tag;
    u16 m_sub_version;
    int m_regist_state;
    int m_connected;
    int m_joined_game;
    int m_has_meet_user_settings;
    int m_handle_pings_only;
    int m_entry_count;
    int m_unused;
    int m_lobby_list_count;
    int m_unused2;
    int m_udp_disabled;
    int m_language;
    u8 m_unused3[80];
    TPlyCharData m_character_data;
    u32 m_unused4;
    GameListEntry m_game_entries[64];
    GameListEntry m_game_entries2[64];
    LobbyListEntry m_lobby_entries[16];
    QuestListEntry m_quest_entries[30];
    u8 m_unused5[128];
    char m_serial_number_v1[17];
    char m_access_key_v1[17];
    char m_serial_number[48];
    char m_access_key[48];
    char m_password[64];
    char m_player_name[16];
    char m_serial_number2[17];
    char m_access_key2[17];
    TPlyClientConfig m_client_config;
    int m_packet_offset;
    int m_packet_size;
    struct packet m_packet;
    struct recv_packet_handlers m_recv_handlers;
private:
    static void operator delete(void *ptr) { obj_heap->heap_free(ptr); };
public:
    TProtocol(TObject *parent, u16 sub_version, int language, char *serial_number, char *access_key, char *password);
    virtual ~TProtocol();
    const u8 next();

    virtual void run_task();
    virtual short send(u8 *data, size_t size);

    void some_stub();
    void handle_cmd_90(packet &pkt);
    void handle_cmd_9B(packet &pkt);
    void handle_cmd_88(packet &pkt);
    void handle_cmd_8A(packet &pkt);
    void handle_cmd_92(packet &pkt);
    void handle_cmd_95(packet &pkt);
    void handle_cmd_97(packet &pkt);
    void handle_cmd_B1(packet &pkt);
    void handle_cmd_C0(packet &pkt);
    void handle_cmd_C4(packet &pkt);
    void handle_cmd_02(packet &pkt);
    void handle_cmd_9A(packet &pkt);
    void handle_cmd_9C(packet &pkt);
    void handle_cmd_C5(packet &pkt);
    void handle_cmd_D3(packet &pkt);
    void handle_cmd_D5(packet &pkt);
    void handle_cmd_D7(packet &pkt);
    void handle_cmd_D8(packet &pkt);
    void handle_cmd_DA(packet &pkt);
    void handle_cmd_9F(packet &pkt);
    void handle_cmd_AB(packet &pkt);
    void handle_cmd_AC(packet &pkt);
    int handle_command(struct packet *pkt);
    void parse_packet();
    void seq_jump(u8 *some_struct, TPlyMeetUserExtension &extension);

    void recv_error(packet &pkt);
    void recv_text(packet &pkt);
    void recv_regist(packet &pkt);
    void recv_login(packet &pkt);
    void recv_logout(packet &pkt);
    void recv_chat(packet &pkt);
    void recv_dir_list(packet &pkt);
    void recv_game_list(packet &pkt);
    void recv_text_list(packet &pkt);
    void recv_start_game(packet &pkt);
    void recv_start_game3(packet &pkt);
    void recv_start_lobby2(packet &pkt);
    void recv_banner(packet &pkt);
    void recv_banner_head(packet &pkt);
    void recv_download_head(packet &pkt);
    void recv_vm_download_head(packet &pkt);
    void recv_vm_download(packet &pkt);
    void recv_download(packet &pkt);
    void recv_upload(packet &pkt);
    void recv_message(packet &pkt);
    void recv_port(packet &pkt);
    void recv_battle_data(packet &pkt);
    void recv_system_file(packet &pkt);
    void recv_pso_data(packet &pkt);
    void recv_pso_data_long(packet &pkt);
    void recv_generate_id(packet &pkt);
    void recv_room_info(packet &pkt);
    void recv_user_ans(packet &pkt);
    void recv_ping(packet &pkt);
    void recv_chat_message(packet &pkt);
    void recv_quest_menu_list(packet &pkt);
    void recv_quest_menu_info(packet &pkt);
    void recv_quest_list(packet &pkt);
    void recv_quest_info(packet &pkt);
    void recv_emergency_call(packet &pkt);
    void recv_burst_game(packet &pkt);
    void recv_exit_game(packet &pkt);
    void recv_burst_lobby(packet &pkt);
    void recv_exit_lobby(packet &pkt);
    void recv_pso_regist_connect(packet &pkt);
    void recv_pso_regist_check(packet &pkt);
    void recv_trade_result(packet &pkt);
    void recv_advance_trade_state(packet &pkt);

    void send_character_save_info(int creation_timestamp, int event_counter);
    void send_quest_menu_request();
    void send_block_list_request();
    void send_ship_list_request();
    void send_simple_mail(TChatMessage &message);

    void send_quest_barrier();
    void send_message_box_closed();
    void send_cancel_trade();
    void send_trade_ready();
    void send_info_board_request();
    void send_disable_auto_reply();
    void send_lobby_name_request();
    void send_lobby_arrow(u8 arrow);
    void send_choice_search_options_request();
    void send_choice_search(ChoiceSearchParameters &parameters);
    void send_choice_search_parameters(ChoiceSearchParameters &parameters);
    void send_server_time_request();
    void send_server_time_accepted();
    void send_quest_menu_closed();

    void send_regist();
    int send_login2(int disable_udp);
    int send_login3();
    void send_logout();
    void send_chat(TPlyGuildCardTag &tag, char *mesg);
    void send_action(GameListEntry &selection, char *action_name, char *password);
    void send_action(GameListEntry &selection, u8 flags, char *action_name, char *password);
    void send_info(TPlyGuildCardTag &tag);
    void send_game_list();
    void send_text_list();
    void send_chara_data_v2(TPlyCharData &char_data, TPlyChallenge &challenge, TPlyChoiceSearchConfig &choice_search_config, TBlockedSenders &blocked_senders, TPlyText<512> &auto_reply, char *info_board);
    void send_update_chara_data_v2(TPlyCharData &char_data, TPlyChallenge &challenge, TPlyChoiceSearchConfig &choice_search_config, TBlockedSenders &blocked_senders, TPlyText<512> &auto_reply, char *info_board);
    void send_pso_data(game_command &packet, u32 size);
    void send_pso_data2(u32 flags, game_command &packet, u32 size);
    void send_pso_data_long2(char flags, long_game_command &packet, size_t size);
    void send_room_change(int idx);
    void send_find_user(TPlyGuildCardTag &tag, u32 gc_num);
    void send_create_game(char *name, char *password, u8 difficulty, u8 battle_mode, u8 challenge_mode, u8 episode);
public:
    void bswap_packet();
    int bswap_packet_header();
    s32 init_char_data();
public:
    void send_subcommand_to_client(s32 flag, s8 *src, s32 len);
public:
    void bswap_cmd_AB();
};

extern "C" {
u8 *__as__14LobbyListEntryFRC14LobbyListEntry(void *arg0, const void *arg1);
void bswap_cmd_AB__9TProtocolFv(void *p);
}

#endif
