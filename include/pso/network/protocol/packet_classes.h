#ifndef PSO_NETWORK_PROTOCOL_PACKET_CLASSES_H
#define PSO_NETWORK_PROTOCOL_PACKET_CLASSES_H

#include "types.h"
#include <string.h>
#include "pso/macros.h"
#include "pso/forward.h"
#include "pso/network/protocol/protocol.h"
#include "pso/ui/TMenuList.h"
#include "pso/player/TPlyCharData.h"
#include "pso/player/TPlyClientConfig.h"
#include "pso/player/TPlyGuildCardTag.h"
#include "pso/player/TPlySmth.h"
#include "pso/network/TPlyMeetUserExtension.h"

struct game_command_header {
    char command;
    u8 size;  // in 4-byte words; 0 for an extended command (size in the extended header)
    u16 id;

    void bswap() {
        bswap_16(&id);
    };
};

struct extended_game_command_header {
    game_command_header header;
    u32 size;

    void bswap() {
        bswap_16(&header.id);
        bswap_32(&size);
    };
};

struct long_game_command {
    game_command_header header;
    u8 data[1460-sizeof(game_command_header)];

    void bswap() {
        header.bswap();
    };
};

struct extended_long_game_command {
    extended_game_command_header header;
    u8 data[1460-sizeof(extended_game_command_header)];

    void bswap() {
        header.bswap();
    };
};

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

struct extended_game_command {
    extended_game_command_header header;
    u8 data[1024-sizeof(extended_game_command_header)];

    void bswap() {
        header.bswap();
    };
};

TMenuListEntry(GameListEntry,
    GameListEntry();
    GameListEntry &operator=(const GameListEntry &other);

    u8 difficulty_tag;
    u8 num_players;
    char name[16];
    u8 episode;
    u8 flags;
);

TMenuListEntry(LobbyListEntry,
    LobbyListEntry &operator=(const LobbyListEntry &other);

    u32 smth;
);

TMenuListEntry(QuestListEntry,
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

class TPlyJoinLobbyData {
public:
    TPlyJoinLobbyData();

    TPlyGuildCardTag tag;
    u32 ip_addr;
    u32 client_id;
    char name[16];
public:
    void bswap() {
        tag.bswap();
        bswap_32(&ip_addr);
        bswap_32(&client_id);
    };
};

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
    void bswap() {
        tag.bswap();
        bswap_32(&ip_addr);
        bswap_32(&client_id);
        char_data.bswap();
    };
};

class TGenGuildCardTag {
public:
    u8 tag0;
    u8 tag1;
    u16 tag2;
    u32 guildcard_number;
public:
    TGenGuildCardTag() {};

    void bswap() {
        bswap_32(&guildcard_number);
        bswap_16(&tag2);
    };
};

class TRecvGenerateID {
public:
    packet_header header;
    u32 client_id;
    TGenGuildCardTag tag;
public:
    void bswap() {
        header.bswap();
        bswap_32(&client_id);
        tag.bswap();
    };
};

class TChatMessage {
public:
    packet_header header;
    TPlyGuildCardTag tag;
    char name[16];
    u32 to_guildcard_number;
    char text[512];
public:
    void bswap() {
        header.bswap();
        tag.bswap();
        bswap_32(&to_guildcard_number);
    };
};

class TUserAns {
public:
    packet_header header;
    TPlyGuildCardTag tag;
    u32 found_guildcard;
    struct {
        packet_header header;
        u32 ip_addr;
        short port;
        void bswap() {
            header.bswap();
            bswap_32(&ip_addr);
            bswap_16(as(u16 *, &port));
        };
    } recv_port;
    char location[68];
    TPlyMeetUserExtension extension;
public:
    void bswap() {
        header.bswap();
        tag.bswap();
        bswap_32(&found_guildcard);
        recv_port.bswap();
        extension.bswap();
    };
};

class TRecvDownload {
public:
    packet_header header;
    char filename[16];
    u8 data[1024];
    u32 data_size;
public:
    void bswap() {
        header.bswap();
        bswap_32(&data_size);
    };
};

class TRecvDownloadHead {
public:
    packet_header header;
    char path[32];
    u16 unused;
    u16 flags;
    char filename[16];
    u32 file_size;
public:
    void bswap() {
        header.bswap();
        bswap_32(&file_size);
    };
};

class TPlyJoinLobby {
public:
    packet_header header;
    char client_id;
    char leader_id;
    char disable_udp;
    char lobby_number;
    char block_number;
    char unknown1;
    char event;
    char unknown2;
    char unused[4];
    TPlyJoinLobbyEntry entries[12];
public:
    void bswap();
};

class TPlyJoinGame {
public:
    TPlyJoinGame();

    packet_header header;
    u32 variations[16][2];
    TPlyJoinLobbyData lobby_data[4];
    u8 client_id;
    u8 leader_id;
    u8 disable_udp;
    u8 difficulty;
    u8 battle_mode;
    u8 event;
    u8 section_id;
    u8 challenge_mode;
    u32 rare_seed;
    u8 episode;
    u8 unknown1;
    u8 solo_mode;
    u8 unknown2;
public:
    void bswap() {
        header.bswap();
        for (int i = 0; i < 16; ++i) {
            for (int j = 0; j < 2; ++j) {
                bswap_32(&variations[i][j]);
            }
        }
        bswap_32(&rare_seed);
    };
};

#define _gc_tag_packet_templ(name, members)	\
template<bool has_gc_tag = false>		\
struct name {					\
	packet_header header;			\
	members					\
};						\
						\
template<>					\
struct name<true> {				\
	packet_header header;			\
	TPlyGuildCardTag tag;			\
	members					\
}

_gc_tag_packet_templ(regist,
	TPlySmth smth;
	u32 sub_version;
	u8 is_extended;
	u8 language;
);

class TRegister : public regist<false> {
public:
	char serial_number[16];
	char access_key[16];
public:
	void bswap() {
		header.bswap();
		smth.bswap();
		bswap_32(&sub_version);
	};
};

class TSendPsoRegist : public regist<false> {
public:
	char serial_number[48];
	char access_key[48];
	char password[48];
public:
	void bswap() {
		header.bswap();
		smth.bswap();
		bswap_32(&sub_version);
	};
};

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

class TFindUser {
public:
    packet_header header;
    TPlyGuildCardTag tag;
    u32 target_gc;

    TFindUser();
    void bswap();
};

class TRoomChange {
public:
    TRoomChange();
	packet_header header;
	TPlyGuildCardTag tag;
public:
	void bswap();
};

typedef void (*PsoCommandFn)(game_command_header *);

// One entry of pso_command_dispatch_table (TGameProtocol.cpp): a 6x subcommand, the floor
// areas it runs in (subcommand_area_masks) and its handler.
struct PsoCommandHandler {
    u16 command;
    u16 area_mask;
    PsoCommandFn handle;
};

LAYOUT_ASSERT(PsoCommandHandler_size, sizeof(PsoCommandHandler) == 8);

class TPsoDataBuf {
public:
	void recv_pso_data_buf(size_t size);
};

class TPsoDataLong : public TPsoDataBuf {
public:
	union {
		union long_game_command_union pkt;
		u8 bytes[0x8000];
	};
};

class TPsoData : public TPsoDataBuf {
public:
	union game_command_union pkt;
};

class TRecvPsoDataLong {
public:
	packet_header header;
	TPsoDataLong data;
public:
	void bswap() {
		header.bswap();
	};
};

class TRecvPsoData {
public:
	packet_header header;
	TPsoData data;
public:
	void bswap() {
		header.bswap();
	};
};

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

class TMessageBox {
public:
    TMessageBox();
	packet_header header;
	TPlyGuildCardTag tag;
	char mesg[512];
public:
	void bswap() {
		header.bswap();
		tag.bswap();
	};
};

class TRecvPort {
public:
	packet_header header;
	u32 ip_addr;
	short port;
public:
	void bswap() {
		header.bswap();
		bswap_32(&ip_addr);
		bswap_16(as(u16 *, &port));
	};
};

class TSendDownloadHead {
public:
	packet_header header;
	char filename[16];
public:
	void bswap() {
		header.bswap();
	};
};

class TPlyGuildCardTagPacket {
public:
	packet_header header;
	TPlyGuildCardTag tag;
};

class TPlyRecvLogin : public TPlyGuildCardTagPacket {
public:
	TPlyClientConfig client_config;
public:
	void bswap() {
		header.bswap();
		tag.bswap();
	};
public:
    s32 *copy_with_guild_card_tag(s32 *arg1);
};

class TPlyStartGame {
public:
	packet_header header;
	TPlyJoinLobbyData lobby_data[4];
	TPlyMeetUserExtension extension;
	u8 mbr_0xe8[4];
public:
	void bswap() {
		header.bswap();
		for (int i = 0; i < 4; ++i) {
			lobby_data[i].bswap();
		}
		extension.bswap();
	};
};

// A player's challenge-mode records (newserv PlayerRecordsChallengeV3).
struct TPlyChallengeRecords {
	u8 pad_0[0x100];
};

// One player's records as the C5 packet and the 61/98 player data carry them
// (newserv PlayerRecordsEntry_V3). The battle counts are separate fields.
struct TPlyChallenge {
	u32 client_id;
	TPlyChallengeRecords challenge;
	u16 battle_place_count_1;
	u16 battle_place_count_2;
	u16 battle_place_count_3;
	u16 battle_place_count_4;
	u16 battle_disconnect_count;
	u16 pad_10E;
	u16 pad_110;
	u16 pad_112;
	u32 pad_114;
	u32 pad_118;
	void bswap();
};
LAYOUT_ASSERT(TPlyChallengeSize, sizeof(TPlyChallenge) == 0x11C);

// The player's choice search settings (newserv ChoiceSearchConfig); sent alone in C2/C3.
struct TPlyChoiceSearchConfig {
	u32 disabled;
	struct Entry {
		u16 parent_choice_id;
		u16 choice_id;
	} entries[5];

	void bswap();
};

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
