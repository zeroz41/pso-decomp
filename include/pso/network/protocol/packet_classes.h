#ifndef PSO_NETWORK_PROTOCOL_PACKET_CLASSES_H
#define PSO_NETWORK_PROTOCOL_PACKET_CLASSES_H

#include "types.h"
#include <string.h>
#include "pso/macros.h"
#include "pso/forward.h"
#include "pso/network/protocol/protocol.h"
#include "pso/quest/challenge/ChallengeRecord.h"
#include "pso/ui/TMenuList.h"
#include "pso/player/TPlyCharData.h"
#include "pso/player/TPlyClientConfig.h"
#include "pso/player/TPlyGuildCardTag.h"
#include "pso/player/TPlySmth.h"
#include "pso/network/TPlyMeetUserExtension.h"

// The header of a game subcommand (6x) inside a 60, 62, 6C or 6D command. The handlers of
// pso_command_dispatch_table take it.
struct game_command_header {
    char command;
    u8 size;  // in 4-byte words; 0 for an extended command (size in the extended header)
    u16 id;

    void bswap() {
        bswap_16(&id);
    };
};

// The header of a subcommand whose game_command_header size is 0: size is the whole subcommand in
// bytes. TPsoDataBuf::recv_pso_data_buf steps over such a subcommand by it.
struct extended_game_command_header {
    game_command_header header;
    u32 size;

    void bswap() {
        bswap_16(&header.id);
        bswap_32(&size);
    };
};

// One 0x5B4-byte piece of a long subcommand; TProtocol::send_pso_data_long2 sends 6D in pieces of this size.
struct long_game_command {
    game_command_header header;
    u8 data[1460-sizeof(game_command_header)];

    void bswap() {
        header.bswap();
    };
};
LAYOUT_ASSERT(long_game_commandSize, sizeof(long_game_command) == 0x5B4);

// One 0x5B4-byte piece of an extended long subcommand.
struct extended_long_game_command {
    extended_game_command_header header;
    u8 data[1460-sizeof(extended_game_command_header)];

    void bswap() {
        header.bswap();
    };
};

// A game subcommand of up to 0x400 bytes as TProtocol::send_pso_data (60) and send_pso_data2 (62) send it.
struct game_command {
    game_command_header header;
    u8 data[1024-sizeof(game_command_header)];

    void bswap() {
        header.bswap();
    };
    // Sends the subcommand to one client; this console's own id runs it here instead.
    void send_to_client(u32 client_id);
    // Sends the subcommand to the other clients without running it here.
    void send();
};

// An extended game subcommand of up to 0x400 bytes.
struct extended_game_command {
    extended_game_command_header header;
    u8 data[1024-sizeof(extended_game_command_header)];

    void bswap() {
        header.bswap();
    };
};

TMenuListEntry(GameListEntry,
    GameListEntry();
    GameListEntry(const GameListEntry &other);
    GameListEntry &operator=(const GameListEntry &other);

    s8 difficulty_tag; // the difficulty + 0x22
    u8 num_players;
    char name[16];
    u8 episode;
    s8 flags;
);

TMenuListEntry(LobbyListEntry,
    LobbyListEntry() {}
    LobbyListEntry(const LobbyListEntry &other);
    LobbyListEntry &operator=(const LobbyListEntry &other);

    u32 smth;
);

TMenuListEntry(QuestListEntry,
    QuestListEntry() {}
    QuestListEntry(const QuestListEntry &other);

    char name[32];
    char short_description[112];
);

union game_command_union {
    struct game_command game_cmd;
    struct extended_game_command ext_game_cmd;
    u8 bytes[1024];
};

union long_game_command_union {
    struct long_game_command game_cmd;
    struct extended_long_game_command ext_game_cmd;
    u8 bytes[1460];

    // Sends an extended subcommand (header already byte-swapped) to one client; this
    // console's own id runs it here instead.
    void send_to_client(u32 client_id);
};

// A command that carries only a text. 1A and D5: the text TProtocol::recv_text and handle_cmd_D5 pass to
// TLobby::open_scroll_text_window. A3 and A5 (288 characters): the quest description that
// TProtocol::recv_quest_menu_info and recv_quest_info pass to receive_quest_info and
// show_card_list_message. D9 (172 characters): the info board text the client sends
// (TProtocol::send_text_packet_D9). C7 (512 characters): the auto-reply the client sends
// (TProtocol::send_text_packet_c7). TPlyJoinData takes header.flags of the client's copy as
// auto_reply_enabled.
template<size_t size>
struct TPlyText {
    packet_header header;
    char text[size];

    void bswap();
};

// Out of line with the protocol's other packet helpers: info board text (D9), quest info (A3/A5), auto-reply (C7).
template <> void TPlyText<172>::bswap();
template <> void TPlyText<288>::bswap();
template <> void TPlyText<512>::bswap();
LAYOUT_ASSERT(TPlyText172Size, sizeof(TPlyText<172>) == 0xB0);
LAYOUT_ASSERT(TPlyText288Size, sizeof(TPlyText<288>) == 0x124);
LAYOUT_ASSERT(TPlyText512Size, sizeof(TPlyText<512>) == 0x204);
LAYOUT_ASSERT(TPlyText1024Size, sizeof(TPlyText<1024>) == 0x404);
LAYOUT_ASSERT(TPlyText4096Size, sizeof(TPlyText<0x1000>) == 0x1004);

// One player of a 0E or 64 game join: the guild card tag, address, client id and name.
class TPlyJoinLobbyData {
public:
    TPlyJoinLobbyData();
    TPlyJoinLobbyData(const TPlyJoinLobbyData &other);

    TPlyGuildCardTag tag;
    u32 ip_addr;
    u32 client_id;
    char name[16];
public:
    void bswap();
};
LAYOUT_ASSERT(TPlyJoinLobbyDataSize, sizeof(TPlyJoinLobbyData) == 0x20);

// One player of a 65, 67 or 68 join: the TPlyJoinLobbyData fields and the character.
class TPlyJoinLobbyEntry {
public:
    TPlyJoinLobbyEntry();
    ~TPlyJoinLobbyEntry();

    TPlyGuildCardTag tag;
    u32 ip_addr;
    u32 client_id;
    char name[16];
    TPlyCharData char_data;
public:
    void bswap();
};

// The guild card tag the server hands out with 80.
class TGenGuildCardTag {
public:
    u8 tag0;
    u8 tag1;
    u16 tag2;
    u32 guildcard_number;
public:
    TGenGuildCardTag() {};

    void bswap();
};
LAYOUT_ASSERT(TGenGuildCardTagSize, sizeof(TGenGuildCardTag) == 0x8);

// 80: the client id and guild card tag the server gives the client. TProtocol::recv_generate_id passes it
// to handle_generate_id.
class TRecvGenerateID {
public:
    packet_header header;
    u32 client_id;
    TGenGuildCardTag tag;
public:
    void bswap();
};
LAYOUT_ASSERT(TRecvGenerateIDSize, sizeof(TRecvGenerateID) == 0x10);

// The lobby's 80 handler; it ignores the packet.
void handle_generate_id(TRecvGenerateID gen_id);

// 81: simple mail. TProtocol::send_simple_mail sends it (0x220 bytes); TProtocol::recv_chat_message passes
// it to receive_short_mail.
class TChatMessage {
public:
    packet_header header;
    TPlyGuildCardTag tag;
    char name[16];
    u32 to_guildcard_number;
    char text[512];
public:
    TChatMessage();
    void bswap();
    s32 is_text_too_long();
};
LAYOUT_ASSERT(TChatMessageSize, sizeof(TChatMessage) == 0x220);

// 19: the address and port of the server to move to. TProtocol::recv_port closes the connection and connects
// there. TUserAns carries one for the server a found player is on.
class TRecvPort {
public:
    packet_header header;
    u32 ip_addr;
    short port;
public:
    void bswap();
};
LAYOUT_ASSERT(TRecvPortSize, sizeof(TRecvPort) == 0xC);

// 41: the answer to a 40 user search: where the player is and how to reach them.
// TProtocol::recv_user_ans passes it to handle_user_search_answer.
class TUserAns {
public:
    packet_header header;
    TPlyGuildCardTag tag;
    u32 found_guildcard;
    TRecvPort recv_port;
    char location[68];
    TPlyMeetUserExtension extension;
public:
    void bswap();
};
LAYOUT_ASSERT(TUserAnsSize, sizeof(TUserAns) == 0xC4);

// 13 and A7: one chunk of a file download.
// TProtocol::recv_download and recv_vm_download acknowledge each chunk with a TSendDownloadHead of the
// same command and pass it to the lobby's quest download chunk handler and
// TQuestVmDownLoadServer::receive_file_chunk.
class TRecvDownload {
public:
    packet_header header;
    char filename[16];
    u8 data[1024];
    u32 data_size;
public:
    void bswap();
};
LAYOUT_ASSERT(TRecvDownloadSize, sizeof(TRecvDownload) == 0x418);

// 44 and A6: the start of a file download: the file's name and size. TProtocol::recv_download_head and
// recv_vm_download_head acknowledge it with a TSendDownloadHead of the same command and pass it to
// begin_file_download and TQuestVmDownLoadServer::begin_file_download.
// download_kind (A6 only, not byte-swapped) says which files make up the download:
// 0 = .dat and .bin, 1 = .dat, .bin and .pvr, 2 = .gba.
class TRecvDownloadHead {
public:
    packet_header header;
    char path[32];
    u16 unused;
    char download_kind;
    u8 pad_27;
    char filename[16];
    u32 file_size;
public:
    void bswap();
};
LAYOUT_ASSERT(TRecvDownloadHeadSize, sizeof(TRecvDownloadHead) == 0x3C);

// 67: the client joins a lobby; 65 and 68: players join the game or lobby the client is in.
// TProtocol::recv_start_lobby2, recv_burst_game and recv_burst_lobby pass it to TLobby::handle_lobby_enter,
// TLobby::on_game_player_add and TLobby::on_lobby_player_add.
class TPlyJoinLobby {
public:
    packet_header header;
    char client_id;
    char leader_id;
    char disable_udp;
    char lobby_number;
    char block_number;
    char enable_battle_mode;
    char event;
    char enable_voice_chat;
    char unused[4];
    TPlyJoinLobbyEntry entries[12];
public:
    ~TPlyJoinLobby();
    void bswap();
};
LAYOUT_ASSERT(TPlyJoinLobbyEntrySize, sizeof(TPlyJoinLobbyEntry) == 0x43C);
LAYOUT_ASSERT(TPlyJoinLobbyEntriesOffset, offsetof(TPlyJoinLobby, entries) == 0x10);
LAYOUT_ASSERT(TPlyJoinLobbySize, sizeof(TPlyJoinLobby) == 0x32E0);

// 64: the client joins a game: the variations of each area, the players, the game settings and the rare
// item seed. TProtocol::recv_start_game3 passes it to TLobby::handle_game_join.
class TPlyJoinGame {
public:
    TPlyJoinGame();

    packet_header header;
    u32 variations[16][2];
    TPlyJoinLobbyData lobby_data[4];
    char client_id;
    char leader_id;
    char disable_udp;
    char difficulty;
    char battle_mode;
    char event;
    char section_id;
    char challenge_mode;
    u32 rare_seed;
    u8 episode;
    u8 unused1;
    u8 solo_mode;
    u8 unused2;
public:
    void bswap();
};
LAYOUT_ASSERT(TPlyJoinGameSize, sizeof(TPlyJoinGame) == 0x114);

// 03 and 04: the serial number and access key the client registers (TProtocol::send_regist) or logs in
// with (TProtocol::send_login2); header.flags of 04 says whether UDP is off.
class TRegister {
public:
	TRegister();

	packet_header header;
	TPlySmth smth;
	u32 sub_version;
	u8 is_extended;
	u8 language;
	u16 unused;
	char serial_number[16];
	char access_key[16];
public:
	void bswap();
};
LAYOUT_ASSERT(TRegisterSize, sizeof(TRegister) == 0x34);

// 9C: the account registration with serial number, access key and password
// (TProtocol::send_register_9c). The server answers with 9C, which TProtocol::handle_cmd_9C passes to
// TLobby::handle_register_result.
class TSendPsoRegist {
public:
	TSendPsoRegist();

	packet_header header;
	TPlySmth smth;
	u32 sub_version;
	u8 is_extended;
	u8 language;
	u16 unused;
	char serial_number[48];
	char access_key[48];
	char password[48];
public:
	void bswap();
};
LAYOUT_ASSERT(TSendPsoRegistSize, sizeof(TSendPsoRegist) == 0xA4);

// 66 and 69: a player left the game or the lobby. TProtocol::recv_exit_game and recv_exit_lobby pass it to
// TLobby::remove_player and TLobby::retire_lobby_player.
template<bool is_lobby>
class TRecvExit {
public:
	packet_header header;
	char client_id;
	char leader_id;
	char disable_udp;
public:
	void bswap();
};

template<> void TRecvExit<true>::bswap();
template<> void TRecvExit<false>::bswap();

// C1: create a game with a name, password, difficulty, battle and challenge mode and episode
// (TProtocol::send_create_game).
class TCreateGame {
public:
    TCreateGame();
	packet_header header;
	TPlyGuildCardTag tag;
	char name[16];
	char password[16];
	u8 difficulty;
	u8 battle_mode;
	u8 challenge_mode;
	u8 episode;
public:
	void bswap();
};
LAYOUT_ASSERT(TCreateGameSize, sizeof(TCreateGame) == 0x30);

// 40: look for a player by guild card number (TProtocol::send_find_user); the server answers with 41
// (TUserAns).
class TFindUser {
public:
    packet_header header;
    TPlyGuildCardTag tag;
    u32 target_gc;

    TFindUser();
    void bswap();
};
LAYOUT_ASSERT(TFindUserSize, sizeof(TFindUser) == 0x10);

// 84: move to another lobby of the 83 lobby list (TProtocol::send_room_change).
class TRoomChange {
public:
    TRoomChange();
	packet_header header;
	TPlyGuildCardTag tag;
public:
	void bswap();
};
LAYOUT_ASSERT(TRoomChangeSize, sizeof(TRoomChange) == 0xC);

typedef void (*PsoCommandFn)(game_command_header *);

// One entry of pso_command_dispatch_table (TGameProtocol.cpp): a 6x subcommand, the floor
// areas it runs in (subcommand_area_masks) and its handler.
struct PsoCommandHandler {
    u16 command;
    u16 area_mask;
    PsoCommandFn handle;
};

LAYOUT_ASSERT(PsoCommandHandler_size, sizeof(PsoCommandHandler) == 8);

// The subcommands of a received 60, 62, 6C or 6D command. recv_pso_data_buf runs each through
// pso_command_dispatch_table, the handlers allowed on the current floor area only.
class TPsoDataBuf {
public:
	void recv_pso_data_buf(size_t size);
};

// The subcommand of a 6C or 6D command, up to 0x8000 bytes.
class TPsoDataLong : public TPsoDataBuf {
public:
	union {
		union long_game_command_union pkt;
		u8 bytes[0x8000];
	};
};

// The subcommand of a 60 or 62 command.
class TPsoData : public TPsoDataBuf {
public:
	union game_command_union pkt;
};

// 6C and 6D: a long game subcommand. TProtocol::send_pso_data_long2 sends 6D to one client (header.flags
// is the client, long_game_command_union::send_to_client); TProtocol::recv_pso_data_long hands the subcommand to
// TPsoDataBuf::recv_pso_data_buf.
class TRecvPsoDataLong {
public:
	packet_header header;
	TPsoDataLong data;
public:
	void bswap();
};
LAYOUT_ASSERT(TRecvPsoDataLongSize, sizeof(TRecvPsoDataLong) == 0x8004);

// 60 and 62: a game subcommand to every client (60) or one (62, header.flags is the client).
// TProtocol::send_pso_data and send_pso_data2 send them; TProtocol::recv_pso_data hands the subcommand to
// TPsoDataBuf::recv_pso_data_buf.
class TRecvPsoData {
public:
	packet_header header;
	TPsoData data;
public:
	void bswap();
};
LAYOUT_ASSERT(TRecvPsoDataSize, sizeof(TRecvPsoData) == 0x404);

// 09 (TProtocol::send_info: ask for a menu entry's info) and 10 (TProtocol::send_action: pick a menu entry).
// The low two bits of the entry's flags choose the form: 1 adds a name, 2 a password, 3 both.
template<int action_type = 0>
class TSendAction {
public:
	packet_header header;
	TPlyGuildCardTag tag;
public:
	TSendAction();
	void bswap();
};

template<> TSendAction<0>::TSendAction();
template<> void TSendAction<0>::bswap();

template<>
class TSendAction<1> {
public:
	packet_header header;
	TPlyGuildCardTag tag;
	char name[16];
public:
	TSendAction();
	void bswap();
};

template<>
class TSendAction<2> {
public:
	packet_header header;
	TPlyGuildCardTag tag;
	char password[16];
public:
	TSendAction();
	void bswap();
};

template<>
class TSendAction<3> {
public:
	packet_header header;
	TPlyGuildCardTag tag;
	char name[16];
	char password[16];
public:
	TSendAction();
	void bswap();
};

// A guild card tag and a text: 01 (error), 06 (chat), 11 (message box) and B0 (emergency call).
// TProtocol::recv_error, recv_chat, recv_message and recv_emergency_call pass the text on (to handle_error,
// TWindowCtrl::handle_recv_chat once construct_lobby_players installs it, handle_server_message and
// TLobby::disable_window_flags); TProtocol::send_chat sends 06.
class TMessageBox {
public:
    TMessageBox();
	packet_header header;
	TPlyGuildCardTag tag;
	char mesg[512];
public:
	void bswap();
};
LAYOUT_ASSERT(TMessageBoxSize, sizeof(TMessageBox) == 0x20C);

// A file name. The client acknowledges 13, 44, A6 and A7 with it (same command and flags), and asks for a
// file with D7 (TProtocol::send_download_head, the quest opcode file_dl_req).
class TSendDownloadHead {
public:
	packet_header header;
	char filename[16];
public:
	void bswap();
};
LAYOUT_ASSERT(TSendDownloadHeadSize, sizeof(TSendDownloadHead) == 0x14);

// A command header and a guild card tag.
class TPlyGuildCardTagPacket {
public:
	TPlyGuildCardTagPacket(const TPlyGuildCardTagPacket &other);

	packet_header header;
	TPlyGuildCardTag tag;
};
LAYOUT_ASSERT(TPlyGuildCardTagPacketSize, sizeof(TPlyGuildCardTagPacket) == 0xC);

// 04: the server's answer to a login. header.flags is the error code; when it is 0 TProtocol::recv_login
// keeps the guild card tag and client config. TLobby::handle_login_result gets the code.
class TPlyRecvLogin : public TPlyGuildCardTagPacket {
public:
	TPlyRecvLogin(const TPlyRecvLogin &other);

	TPlyClientConfig client_config;
public:
	void bswap();
};
LAYOUT_ASSERT(TPlyRecvLoginSize, sizeof(TPlyRecvLogin) == 0x2C);

// 0E: a game start with up to four players (TProtocol::recv_start_game); the lobby installs no 0E handler.
class TPlyStartGame {
public:
	packet_header header;
	TPlyJoinLobbyData lobby_data[4];
	TPlyMeetUserExtension extension;
	u8 unused[4];
public:
	void bswap();
};
LAYOUT_ASSERT(TPlyStartGameSize, sizeof(TPlyStartGame) == 0xEC);

// One player's records as the C5 packet and the 61/98 player data carry them
// (newserv PlayerRecordsEntry_V3). The battle counts are separate fields.
struct TPlyChallenge {
	u32 client_id;
	ChallengeRecord challenge;  // newserv PlayerRecordsChallengeV3
	u16 battle_place_count_1;
	u16 battle_place_count_2;
	u16 battle_place_count_3;
	u16 battle_place_count_4;
	u16 battle_disconnect_count;
	u16 battle_reserved_count_1;  // BattleRecord::reserved_counts
	u16 battle_reserved_count_2;
	u16 battle_reserved_count_3;
	u32 battle_reserved_value_1;  // BattleRecord::reserved_values
	u32 battle_reserved_value_2;
	void bswap();
};
LAYOUT_ASSERT(TPlyChallengeSize, sizeof(TPlyChallenge) == 0x11C);

// The player's choice search settings (newserv ChoiceSearchConfig); sent alone in C2/C3.
struct TPlyChoiceSearchConfig {
	u32 disabled;
	struct Entry {
		u16 parent_choice_id;
		u16 choice_id;

		void bswap();
	} entries[5];

	void bswap();
};

// 61 and 98: the player's character, challenge records, choice search settings, info board, blocked
// senders and auto-reply. TLobby::send_selected_character sends 61 when the server asks with 95;
// TLobby::send_game_character sends 98. Both go through TProtocol::send_chara_data_v2 and
// send_update_chara_data_v2, which send only the auto-reply text that is used.
class TPlyJoinData {
public:
	TPlyJoinData();
	~TPlyJoinData();

	packet_header header;
	TPlyCharData char_data;
	TPlyChallenge challenge;
	TPlyChoiceSearchConfig choice_search_config;
	char info_board[172];
	u32 blocked_senders[30];
	u32 auto_reply_enabled;
	char auto_reply[512];
public:
	void bswap();
};

#endif
