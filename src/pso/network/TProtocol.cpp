#include <global_types.h>
#include "pso/network/TProtocol_801DFCAC.h"
#include "pso/misc/TPlyJoinLobbyEntry.h"
#include "pso/network/TProtocol.h"
#include "pso/unk/text_801DFC3C.h"
#include "pso/system/byteswap.h"
#include "pso/misc/TLobby.h"
#include "pso/ui/TAdSinglePlyChrSelectGC.h"
#include <string.h>
#include <stdio.h>
#include <stddef.h>
#include "pso/forward.h"
#include "pso/macros.h"
#include "pso/TMainTask.h"
#include "pso/TMenuList.h"
#include "pso/TPlyCharData.h"
#include "pso/TPlyDispData.h"
#include "pso/TPlyInventory.h"
#include "pso/TObject.h"
#include "pso/TProtocol.h"
#include "pso/TSocket.h"

extern packet *server_packet;
extern const char *port_map_copyright;

#include "types.h"
#include "pso/item/TItem.h"
struct RecoveredFields_801DD33C_arg0 {
    u8 field_0;
    u8 field_1;
    u16 field_2;
    s32 field_4;
};

struct RecoveredFields_801DD33C_arg1 {
    u8 field_0;
    u8 field_1;
    u16 field_2;
    s32 field_4;
};

extern "C" {
u8 *__ct__15TRecvGenerateIDFRC15TRecvGenerateID(u8 *arg0, u8 *arg1);
void __ct__16TGenGuildCardTagFRC16TGenGuildCardTag(u8 *arg0, u8 *arg1);
}

void TProtocol::recv_pso_regist_check(packet &pkt) {
	packet_header tmp = pkt.pkt.header;
	tmp.bswap();
	m_regist_state = tmp.flags;
	if (m_recv_handlers.handle_18_90_9A_recv_pso_regist_check != nullptr) {
		m_recv_handlers.handle_18_90_9A_recv_pso_regist_check(tmp.flags);
	}
}

void TProtocol::recv_pso_regist_connect(packet &pkt) {
	TRecvPsoRegistConnect tmp = as(TRecvPsoRegistConnect &, pkt);
	tmp.bswap();
	if (!strcmp(port_map_copyright, tmp.copyright)) {
		TSendPsoRegistConnect tmp2;
		m_recv_crypt.reset(tmp.server_key);
		m_send_crypt.reset(tmp.client_key);
		m_is_encrypted = true;
		memset(&tmp2, 0, sizeof(tmp2));
		tmp2.header.command = 0x90;
		tmp2.header.size = sizeof(tmp2);
		strncpy(tmp2.serial_number, m_serial_number_v1, sizeof(tmp2.serial_number)-1);
		strncpy(tmp2.access_key, m_access_key_v1, sizeof(tmp2.access_key)-1);
		tmp2.bswap();
		send(as(u8 *, &tmp2), sizeof(tmp2));
	} else {
		close();
	}
}

void TProtocol::recv_exit_lobby(packet &pkt) {
	TRecvExit<true> tmp = as(TRecvExit<true> &, pkt);
	tmp.bswap();

	if (m_recv_handlers.handle_69_recv_exit_lobby != nullptr) {
		m_recv_handlers.handle_69_recv_exit_lobby(tmp.client_id, tmp.leader_id);
	}
}

void TProtocol::recv_burst_lobby(packet &pkt) {
	TPlyJoinLobby tmp = as(TPlyJoinLobby &, pkt);
	tmp.bswap();

	if (m_recv_handlers.handle_68_recv_burst_lobby != nullptr) {
		m_recv_handlers.handle_68_recv_burst_lobby(tmp.entries, tmp.leader_id);
	}
}

void TProtocol::recv_exit_game(packet &pkt) {
	TRecvExit<false> tmp = as(TRecvExit<false> &, pkt);
	tmp.bswap();

	if (m_recv_handlers.handle_66_recv_exit_game != nullptr) {
		m_recv_handlers.handle_66_recv_exit_game(tmp.client_id, tmp.leader_id, tmp.disable_udp);
	}
}

void TProtocol::recv_burst_game(packet &pkt) {
	TPlyJoinLobby tmp = as(TPlyJoinLobby &, pkt);
	tmp.bswap();

	if (m_recv_handlers.handle_65_recv_burst_game != nullptr) {
		m_recv_handlers.handle_65_recv_burst_game(tmp.entries, tmp.leader_id, tmp.disable_udp);
	}
}

void TProtocol::send_create_game(char *name, char *password, u8 difficulty, u8 battle_mode, u8 challenge_mode, u8 episode) {
	if (m_connected) {
		TCreateGame tmp;
		tmp.header.command = 0xC1;
		tmp.header.flags = 3;
		tmp.header.size = sizeof(tmp);
		tmp.tag = TPlyGuildCardTag(0, 0);
		tmp.difficulty = difficulty;
		tmp.battle_mode = battle_mode;
		tmp.challenge_mode = challenge_mode;
		tmp.episode = episode;
		strncpy(tmp.name, name, sizeof(tmp.name));
		strncpy(tmp.password, password, sizeof(tmp.password));
		tmp.bswap();
		send(as(u8 *, &tmp), sizeof(tmp));
	}
}

void TProtocol::send_find_user(TPlyGuildCardTag &tag, u32 gc_num) {
	if (m_connected) {
		TFindUser tmp;
		memset(&tmp, 0, sizeof(tmp));
		tmp.header.command = 0x40;
		tmp.header.size = sizeof(tmp);
		tmp.tag = tag;
		tmp.target_gc = gc_num;
		tmp.bswap();
		send(as(u8 *, &tmp), sizeof(tmp));
	}
}

void TProtocol::send_room_change(int idx) {
	if (m_connected) {
		TRoomChange tmp;
		tmp.header.command = 0x84;
		tmp.header.flags = 0;
		tmp.header.size = sizeof(tmp);
		tmp.tag = m_lobby_entries[idx].tag;
		tmp.bswap();
		send(as(u8 *, &tmp), sizeof(tmp));
	}
}

void TProtocol::send_pso_data_long2(char flags, long_game_command &packet, size_t size) {
	const int header_size = sizeof(packet_header);
	const int command_size = sizeof(long_game_command);
	if (m_connected) {
		TRecvPsoDataLong *tmp = (TRecvPsoDataLong *)::operator new(sizeof(TRecvPsoDataLong));
		u8 *pkt = as(u8 *, tmp);
		int packet_size;
		int cmd_count;
		int leftover;
		int offset;

		memcpy(tmp->data.bytes, &packet, size);
		tmp->header.command = 0x6d;
		tmp->header.flags = flags;
		tmp->header.size = size + header_size;
		tmp->bswap();

		packet_size = (int)size + header_size;
		cmd_count = packet_size/command_size;
		leftover = packet_size - (cmd_count * command_size);

		for (offset = 0; cmd_count > 0; --cmd_count, offset += command_size) {
			if (test_connection()) {
				goto end;
			} else {
				send(&pkt[offset], command_size);
			}
		}

		if (!test_connection() && leftover > 0) {
			send(&pkt[offset], leftover);
		}

		end:
		delete tmp;
	}
}

struct VBase_18_801DC084 { char pad[0x18]; };
struct VObj_18_801DC084 : VBase_18_801DC084 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual void m8(void *, u16);
};

struct Pkt_801DC084 {
    u8 cmd;
    u8 flag;
    u16 size;
    u8 data[0x400];
};

extern "C" {
void bswap__12TRecvPsoDataFv(void *);
extern char TProtocol__send_pso_data2_log_format[];
extern char TProtocol__send_pso_data_log_format[];

void TProtocol::send_subcommand_to_client(s32 flag, s8 *src, s32 len) {
    char buf[0x80];
    sprintf(buf, TProtocol__send_pso_data2_log_format, *src, len, flag);
    if (this->m_connected != 0) {
        Pkt_801DC084 pkt;
        int size;
        pkt.cmd = 0x62;
        pkt.flag = flag;
        pkt.size = len + 4;
        size = pkt.size;
        memcpy(pkt.data, src, len);
        bswap__12TRecvPsoDataFv(&pkt);
        this->send((u8 *)&pkt, size);
    }
}

void TProtocol__send_60(VObj_18_801DC084 *obj, s8 *src, u32 len) {
    char buf[0x80];
    sprintf(buf, TProtocol__send_pso_data_log_format, *src, len);
    if (*(s32 *)((char *)obj + 0x1910) != 0) {
        Pkt_801DC084 pkt;
        int size;
        pkt.cmd = 0x60;
        pkt.flag = 0;
        pkt.size = len + 4;
        size = pkt.size;
        memcpy(pkt.data, src, len);
        bswap__12TRecvPsoDataFv(&pkt);
        obj->m8(&pkt, size);
    }
}

struct Join_801DC1E4 {
    u8 command;
    u8 flags;
    u16 size;
    u8 char_data[0x41C];
    u8 challenge[0x11C];
    u8 choice_search_config[0x18];
    char info_board[0xAC];
    u32 blocked_senders[30];
    u32 auto_reply_enabled;
    char auto_reply[0x200];
};
struct List_801DC1E4 { u8 command; u8 flags; u16 size; u32 entries[30]; };
struct Text_801DC1E4 { u8 command; u8 flags; u16 size; char text[0x200]; };
struct Proto_801DC1E4 { u8 pad[0x1910]; s32 connected; u8 pad1914[0x74]; u8 char_data[0x41C]; };

void TProtocol__sub_801DF774(void *, void *);
}
s32 validate_player_visual_record(void *arg0);
extern "C" {

void send_player_data_98__9TProtocolFPvPvPvPvPvPvPv(Proto_801DC1E4 *self, u8 *char_data, void *challenge, void *choice_search_config,
                               List_801DC1E4 *blocked_senders, Text_801DC1E4 *auto_reply, char *info_board) {
    if (self->connected) {
        validate_player_visual_record(char_data + 0x370);
        copy_player_data__9TProtocolFPvPv(self->char_data, char_data);
        Join_801DC1E4 tmp;
        ((TProtocol *)(&tmp))->init_char_data();
        memset(&tmp, 0, sizeof(tmp));
        tmp.command = 0x98;
        tmp.flags = 3;
        tmp.size = sizeof(tmp);
        copy_player_data__9TProtocolFPvPv(tmp.char_data, self->char_data);
        ((TLobby *)(tmp.challenge))->copy_player_record((u8 *)challenge);
        TProtocol__sub_801DF774(tmp.choice_search_config, choice_search_config);
        strncpy(tmp.info_board, info_board, sizeof(tmp.info_board));
        for (int i = 0; i < blocked_senders->flags; ++i) {
            tmp.blocked_senders[i] = blocked_senders->entries[i];
        }
        tmp.auto_reply_enabled = auto_reply->flags;
        strncpy(tmp.auto_reply, auto_reply->text, sizeof(tmp.auto_reply) - 1);
        const int packet_size = strlen(tmp.auto_reply) + 0x680;
        tmp.size = packet_size & ~3;
        encode_uploaded_player_inventory(tmp.char_data);
        bswap_player_record_upload((u8 *)&tmp);
        ((TProtocol *)self)->send((u8 *)&tmp, packet_size & ~3);
        destroy__9TProtocolFis((s32)&tmp, -1);
    }
}

struct Join_801DC34C {
    u8 command;
    u8 flags;
    u16 size;
    u8 char_data[0x41C];
    u8 challenge[0x11C];
    u8 choice_search_config[0x18];
    char info_board[0xAC];
    u32 blocked_senders[30];
    u32 auto_reply_enabled;
    char auto_reply[0x200];
};
struct List_801DC34C { u8 command; u8 flags; u16 size; u32 entries[30]; };
struct Text_801DC34C { u8 command; u8 flags; u16 size; char text[0x200]; };
struct Proto_801DC34C { u8 pad[0x1910]; s32 connected; u8 pad1914[0x74]; u8 char_data[0x41C]; };

void send_player_data_61__9TProtocolFPvPvPvPvPvPvPv(Proto_801DC34C *self, u8 *char_data, void *challenge, void *choice_search_config,
                               List_801DC34C *blocked_senders, Text_801DC34C *auto_reply, char *info_board) {
    if (self->connected) {
        validate_player_visual_record(char_data + 0x370);
        copy_player_data__9TProtocolFPvPv(self->char_data, char_data);
        Join_801DC34C tmp;
        ((TProtocol *)(&tmp))->init_char_data();
        memset(&tmp, 0, sizeof(tmp));
        tmp.command = 0x61;
        tmp.flags = 3;
        tmp.size = sizeof(tmp);
        copy_player_data__9TProtocolFPvPv(tmp.char_data, self->char_data);
        ((TLobby *)(tmp.challenge))->copy_player_record((u8 *)challenge);
        TProtocol__sub_801DF774(tmp.choice_search_config, choice_search_config);
        strncpy(tmp.info_board, info_board, sizeof(tmp.info_board));
        for (int i = 0; i < blocked_senders->flags; ++i) {
            tmp.blocked_senders[i] = blocked_senders->entries[i];
        }
        tmp.auto_reply_enabled = auto_reply->flags;
        strncpy(tmp.auto_reply, auto_reply->text, sizeof(tmp.auto_reply) - 1);
        const int packet_size = strlen(tmp.auto_reply) + 0x680;
        tmp.size = packet_size & ~3;
        encode_uploaded_player_inventory(tmp.char_data);
        bswap_player_record_upload((u8 *)&tmp);
        ((TProtocol *)self)->send((u8 *)&tmp, packet_size & ~3);
        destroy__9TProtocolFis((s32)&tmp, -1);
    }
}
}

void TProtocol::send_text_list() {
	if (m_connected) {
		packet_header tmp;

		tmp.command = 0x1F;
		tmp.flags = 0;
		tmp.size = sizeof(tmp);

		tmp.bswap();
		send(as(u8 *, &tmp), sizeof(tmp));
	}
}

void TProtocol::send_game_list() {
	if (m_connected) {
		packet_header tmp;

		tmp.command = 0x08;
		tmp.flags = 0;
		tmp.size = sizeof(tmp);

		tmp.bswap();
		send(as(u8 *, &tmp), sizeof(tmp));
	}
}

void TProtocol::send_info(TPlyGuildCardTag &tag) {
	if (m_connected) {
		TSendAction<0> tmp;

		tmp.header.command = 0x09;
		tmp.header.flags = 0;
		tmp.header.size = sizeof(tmp);
		tmp.tag = tag;

		tmp.bswap();
		send(as(u8 *, &tmp), sizeof(tmp));
	}
}
void TProtocol::send_action(GameListEntry &selection, u8 flags, char *action_name, char *password) {
	if (m_connected) {
		switch (selection.flags & 3) {
			case 0: {
				TSendAction<0> action;

				action.header.command = 0x10;
				action.header.flags = flags;
				action.header.size = sizeof(action);
				action.tag = selection.tag;

				action.bswap();
				send(as(u8 *, &action), sizeof(action));
				break;
			}
			case 1: {
				TSendAction<1> action;

				action.header.command = 0x10;
				action.header.flags = 1;
				action.header.size = sizeof(action);
				action.tag = selection.tag;
				strncpy(action.name, action_name, sizeof(action.name));

				action.bswap();
				send(as(u8 *, &action), sizeof(action));
				break;
			}
			case 2: {
				TSendAction<2> action;

				action.header.command = 0x10;
				action.header.flags = 2;
				action.header.size = sizeof(action);
				action.tag = selection.tag;
				strncpy(action.password, password, sizeof(action.password));

				action.bswap();
				send(as(u8 *, &action), sizeof(action));
				break;
			}
			case 3: {
				TSendAction<3> action;

				action.header.command = 0x10;
				action.header.flags = 3;
				action.header.size = sizeof(action);
				action.tag = selection.tag;
				strncpy(action.name, action_name, sizeof(action.name));
				strncpy(action.password, password, sizeof(action.password));

				action.bswap();
				send(as(u8 *, &action), sizeof(action));
				break;
			}
		}
	}
}

void TProtocol::send_action(GameListEntry &selection, char *action_name, char *password) {
	if (m_connected) {
		switch (selection.flags & 3) {
			case 0: {
				TSendAction<0> action;

				action.header.command = 0x10;
				action.header.flags = 0;
				action.header.size = sizeof(action);
				action.tag = selection.tag;

				action.bswap();
				send(as(u8 *, &action), sizeof(action));
				break;
			}
			case 1: {
				TSendAction<1> action;

				action.header.command = 0x10;
				action.header.flags = 1;
				action.header.size = sizeof(action);
				action.tag = selection.tag;
				strncpy(action.name, action_name, sizeof(action.name));

				action.bswap();
				send(as(u8 *, &action), sizeof(action));
				break;
			}
			case 2: {
				TSendAction<2> action;

				action.header.command = 0x10;
				action.header.flags = 2;
				action.header.size = sizeof(action);
				action.tag = selection.tag;
				strncpy(action.password, password, sizeof(action.password));

				action.bswap();
				send(as(u8 *, &action), sizeof(action));
				break;
			}
			case 3: {
				TSendAction<3> action;

				action.header.command = 0x10;
				action.header.flags = 3;
				action.header.size = sizeof(action);
				action.tag = selection.tag;
				strncpy(action.name, action_name, sizeof(action.name));
				strncpy(action.password, password, sizeof(action.password));

				action.bswap();
				send(as(u8 *, &action), sizeof(action));
				break;
			}
		}
	}
}

void TProtocol::send_chat(TPlyGuildCardTag &tag, char *mesg) {
	if (m_connected) {
		TMessageBox tmp;

		memset(&tmp, 0, sizeof(tmp));
		tmp.header.command = 0x06;
		tmp.header.flags = 0;
		tmp.tag = tag;
		strncpy(tmp.mesg, mesg, sizeof(tmp.mesg) - 1);
		tmp.header.size = (strlen(tmp.mesg) + 16) & ~3;
		const u16 size = tmp.header.size;

		tmp.bswap();

		send(as(u8 *, &tmp), size);
	}
}

void TProtocol::send_logout() {
	packet_header tmp;
	tmp.command = 0x05;
	tmp.flags = 0;
	tmp.size = sizeof(tmp);
	tmp.bswap();

	send(as(u8 *, &tmp), sizeof(tmp));
	m_connected = 0;
}

int TProtocol::send_login3() {
	int ret;
	set_ip_address(new_ip_addr);
	set_port((short)new_port);

	if (open() >= 0) {
		ret = 0;
	} else {
		return 1;
	}
	return ret;
}

int TProtocol::send_login2(int disable_udp) {
	m_udp_disabled = disable_udp;
	TRegister tmp;

	memset(&tmp, 0, sizeof(tmp));
	tmp.header.command = 0x04;
	tmp.header.flags = m_udp_disabled;
	tmp.header.size = sizeof(tmp);
	tmp.smth = m_smth;
	tmp.sub_version = m_sub_version;
	tmp.language = m_language;
	strncpy(tmp.serial_number, m_serial_number, sizeof(tmp.serial_number));
	strncpy(tmp.access_key, m_access_key, sizeof(tmp.access_key));

	tmp.bswap();
	send(as(u8 *, &tmp), sizeof(tmp));
	return 0;
}

void TProtocol::send_regist() {
	TRegister tmp;

	memset(&tmp, 0, sizeof(tmp));
	tmp.header.command = 0x03;
	tmp.header.size = sizeof(tmp);
	tmp.smth = m_smth;
	tmp.sub_version = m_sub_version;
	tmp.language = m_language;
	strncpy(tmp.serial_number, m_serial_number, sizeof(tmp.serial_number));
	strncpy(tmp.access_key, m_access_key, sizeof(tmp.access_key));

	tmp.bswap();
	send(as(u8 *, &tmp), sizeof(tmp));
}

void TProtocol::recv_emergency_call(packet &pkt) {
	TMessageBox tmp = as(TMessageBox &, pkt);
	tmp.bswap();
	if (m_recv_handlers.handle_B0_recv_emergency_call != nullptr) {
		m_recv_handlers.handle_B0_recv_emergency_call(tmp.mesg);
	}
};

void TProtocol::recv_quest_info(packet &pkt) {
	TPlyText<288> tmp = as(TPlyText<288> &, pkt);
	tmp.bswap();

	if (m_recv_handlers.handle_A5_recv_quest_info != nullptr) {
		m_recv_handlers.handle_A5_recv_quest_info(tmp);
	}
};

void TProtocol::recv_quest_list(packet &pkt) {
	typedef TMenuList<QuestListEntry, 30, 0> quest_list;
	quest_list tmp = as(quest_list &, pkt);
	tmp.bswap();

	m_entry_count = tmp.header.flags;

	for (int i = 0; i < m_entry_count; ++i) {
		m_quest_entries[i] = tmp.entries[i];
	}

	if (m_recv_handlers.handle_A4_recv_quest_list != nullptr) {
		m_recv_handlers.handle_A4_recv_quest_list(tmp.header.flags, tmp);
	}
};

void TProtocol::recv_quest_menu_info(packet &pkt) {
	TPlyText<288> tmp = as(TPlyText<288> &, pkt);
	tmp.bswap();

	if (m_recv_handlers.handle_A3_recv_quest_menu_info != nullptr) {
		m_recv_handlers.handle_A3_recv_quest_menu_info(tmp);
	}
};

void TProtocol::recv_quest_menu_list(packet &pkt) {
	typedef TMenuList<QuestListEntry, 30, 0> quest_list;
	quest_list tmp = as(quest_list &, pkt);
	tmp.bswap();

	if (m_recv_handlers.handle_A2_recv_quest_menu_list != nullptr) {
		m_recv_handlers.handle_A2_recv_quest_menu_list(tmp);
	}
};

void TProtocol::recv_chat_message(packet &pkt) {
	TChatMessage tmp = as(TChatMessage &, pkt);
	tmp.bswap();

	if (m_recv_handlers.handle_81_recv_chat_message != nullptr) {
		m_recv_handlers.handle_81_recv_chat_message(tmp);
	}
};

void TProtocol::recv_ping(packet &pkt) {
	packet_header tmp;
	tmp.command = 0x1D;
	tmp.flags = 0;
	tmp.size = sizeof(tmp);
	tmp.bswap();

	send(as(u8 *, &tmp), sizeof(tmp));
};

void TProtocol::recv_user_ans(packet &pkt) {
	TUserAns tmp = as(TUserAns &, pkt);
	tmp.bswap();

	if (m_recv_handlers.handle_41_recv_user_ans != nullptr) {
		m_recv_handlers.handle_41_recv_user_ans(tmp);
	}
};

struct ByteBlock_C { u8 bytes[0xc]; };

void TProtocol::recv_room_info(packet &pkt) {
	typedef TMenuList<LobbyListEntry, 16, 0> lobby_list;
	lobby_list tmp = as(lobby_list &, pkt);
	tmp.bswap();

	m_lobby_list_count = tmp.header.flags;

	if (enable_v2_features) {
		for (int i = 0; i < m_lobby_list_count; ++i) {
			__as__14LobbyListEntryFRC14LobbyListEntry(&m_lobby_entries[i], &tmp.entries[i]);
		}
	} else {
		for (int i = 0; i < 10; ++i) {
			__as__14LobbyListEntryFRC14LobbyListEntry(&m_lobby_entries[i], &tmp.entries[i]);
		}
	}
};

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma scheduling off
u8 *__as__14LobbyListEntryFRC14LobbyListEntry(void *arg0, const void *arg1) {
    *(ByteBlock_C *)(arg0) = *(const ByteBlock_C *)(arg1);
    return (u8 *)arg0;
}
struct ByteBlock_C;
#pragma pop

void TProtocol::recv_generate_id(packet &pkt) {
	TRecvGenerateID tmp = as(TRecvGenerateID &, pkt);
	tmp.bswap();

	if (m_recv_handlers.handle_80_recv_generate_id != nullptr) {
		m_recv_handlers.handle_80_recv_generate_id(tmp);
	}
};

u8 *__ct__15TRecvGenerateIDFRC15TRecvGenerateID(u8 *arg0, u8 *arg1) {
    *(s32 *)((s8 *)arg0 + 0) = (s32) *(s32 *)((s8 *)arg1 + 0);
    *(s32 *)((s8 *)arg0 + 4) = (s32) *(s32 *)((s8 *)arg1 + 4);
    __ct__16TGenGuildCardTagFRC16TGenGuildCardTag(arg0 + 8, arg1 + 8);
    return arg0;
}
void __ct__16TGenGuildCardTagFRC16TGenGuildCardTag(u8 *arg0, u8 *arg1) {
    ((RecoveredFields_801DD33C_arg0 *)arg0)->field_0 = (u8) ((RecoveredFields_801DD33C_arg1 *)arg1)->field_0;
    ((RecoveredFields_801DD33C_arg0 *)arg0)->field_1 = (u8) ((RecoveredFields_801DD33C_arg1 *)arg1)->field_1;
    ((RecoveredFields_801DD33C_arg0 *)arg0)->field_2 = (u16) ((RecoveredFields_801DD33C_arg1 *)arg1)->field_2;
    ((RecoveredFields_801DD33C_arg0 *)arg0)->field_4 = (s32) ((RecoveredFields_801DD33C_arg1 *)arg1)->field_4;
}
void TProtocol::recv_pso_data_long(packet &pkt) {
	TRecvPsoDataLong &tmp = as(TRecvPsoDataLong &, pkt);
	tmp.bswap();
	tmp.data.recv_pso_data_buf(tmp.header.size - sizeof(packet_header));
};

void TProtocol::recv_pso_data(packet &pkt) {
	TRecvPsoData tmp = as(TRecvPsoData &, pkt);
	tmp.bswap();
	tmp.data.recv_pso_data_buf(tmp.header.size - sizeof(packet_header));
};

void TProtocol::recv_system_file(packet &pkt) {};

void TProtocol::recv_battle_data(packet &pkt) {
	packet_header tmp = pkt.pkt.header;
	tmp.bswap();
};

void TProtocol::seq_jump(u8 *some_struct, TPlyMeetUserExtension &extension) {
	TRecvPort *port_info = (TRecvPort *)some_struct;

	new_ip_addr = port_info->ip_addr;
	new_port = port_info->port;
	meet_user_settings = extension;

	close();
	m_is_encrypted = false;
	m_connected = false;
	m_has_meet_user_settings = true;
	m_packet_offset = 0;
	m_packet_size = 0;

	if (send_login3()) {
		m_is_invalid_packet = true;
	} else {
		recv();
	}
}

void TProtocol::recv_port(packet &pkt) {
	TRecvPort tmp = as(TRecvPort &, pkt);
	tmp.bswap();

	new_ip_addr = tmp.ip_addr;
	new_port = tmp.port;

	close();
	m_is_encrypted = false;
	m_connected = false;
	m_packet_offset = 0;
	m_packet_size = 0;

	if (send_login3()) {
		m_is_invalid_packet = true;
	}
};

void TProtocol::recv_message(packet &pkt) {
	TMessageBox tmp = as(TMessageBox &, pkt);
	tmp.bswap();
	if (m_recv_handlers.handle_11_recv_message != nullptr) {
		m_recv_handlers.handle_11_recv_message(tmp.mesg, tmp.header.flags);
	}
};

void TProtocol::recv_upload(packet &pkt) {};

void TProtocol::recv_download(packet &pkt) {
	TSendDownloadHead tmp2;
	TRecvDownload tmp = as(TRecvDownload &, pkt);
	tmp.bswap();

	tmp2.header.command = tmp.header.command;
	tmp2.header.flags = tmp.header.flags;
	tmp2.header.size = sizeof(tmp2);
	strncpy(tmp2.filename, tmp.filename, sizeof(tmp2.filename));
	tmp2.bswap();

	if (m_recv_handlers.handle_13_recv_download != nullptr) {
		m_recv_handlers.handle_13_recv_download(tmp);
	}

	send(reinterpret_cast<u8 *>(&tmp2), sizeof(tmp2));
};

void TProtocol::recv_vm_download(packet &pkt) {
	TSendDownloadHead tmp2;
	TRecvDownload tmp = as(TRecvDownload &, pkt);
	tmp.bswap();

	tmp2.header.command = tmp.header.command;
	tmp2.header.flags = tmp.header.flags;
	tmp2.header.size = sizeof(tmp2);
	strncpy(tmp2.filename, tmp.filename, sizeof(tmp2.filename));
	tmp2.bswap();

	if (m_recv_handlers.handle_A7_recv_vm_download != nullptr) {
		m_recv_handlers.handle_A7_recv_vm_download(tmp);
	}

	send(reinterpret_cast<u8 *>(&tmp2), sizeof(tmp2));
};

void TProtocol::recv_vm_download_head(packet &pkt) {
	TSendDownloadHead tmp2;
	TRecvDownloadHead tmp = as(TRecvDownloadHead &, pkt);
	tmp.bswap();

	tmp2.header.command = tmp.header.command;
	tmp2.header.flags = tmp.header.flags;
	tmp2.header.size = sizeof(tmp2);
	strncpy(tmp2.filename, tmp.filename, sizeof(tmp2.filename));
	tmp2.bswap();

	if (m_recv_handlers.handle_A6_recv_vm_download_head != nullptr) {
		m_recv_handlers.handle_A6_recv_vm_download_head(tmp);
	}

	send(reinterpret_cast<u8 *>(&tmp2), sizeof(tmp2));
};

void TProtocol::recv_download_head(packet &pkt) {
	TSendDownloadHead tmp2;
	TRecvDownloadHead tmp = as(TRecvDownloadHead &, pkt);
	tmp.bswap();

	tmp2.header.command = tmp.header.command;
	tmp2.header.flags = tmp.header.flags;
	tmp2.header.size = sizeof(tmp2);
	strncpy(tmp2.filename, tmp.filename, sizeof(tmp2.filename));
	tmp2.bswap();

	if (m_recv_handlers.handle_44_recv_download_head != nullptr) {
		m_recv_handlers.handle_44_recv_download_head(tmp);
	}

	send(reinterpret_cast<u8 *>(&tmp2), sizeof(tmp2));
};

void TProtocol::recv_banner_head(packet &pkt) {};
void TProtocol::recv_banner(packet &pkt) {};

void TProtocol::recv_start_lobby2(packet &pkt) {
	TPlyJoinLobby tmp = as(TPlyJoinLobby &, pkt);
	tmp.bswap();

	m_joined_game = true;

	if (m_recv_handlers.handle_67_recv_start_lobby2 != nullptr) {
		m_recv_handlers.handle_67_recv_start_lobby2(tmp.entries, tmp.header.flags, tmp.client_id, tmp.leader_id, tmp.lobby_number, tmp.block_number, tmp.unknown1, tmp.event);
	}
};

void TProtocol::recv_start_game3(packet &pkt) {
	TPlyJoinGame tmp = as(TPlyJoinGame &, pkt);
	tmp.bswap();

	memcpy(game_variations, tmp.variations, sizeof(game_variations));
	m_joined_game = true;

	if (m_recv_handlers.handle_64_recv_start_game3 != nullptr) {
		m_recv_handlers.handle_64_recv_start_game3(tmp);
	}
};

void TProtocol::recv_start_game(packet &pkt) {
	int lobby_entry_idx;
	TPlyStartGame tmp = as(TPlyStartGame &, pkt);
	tmp.bswap();

	meet_user_settings = tmp.extension;

	lobby_entry_idx = -1;
	for (int i = 0; i < tmp.header.flags && i < 4; ++i) {
		if ((tmp.lobby_data[i].tag == m_guildcard_tag) == 1) {
			lobby_entry_idx = i;
		}
	}

	if (lobby_entry_idx == -1) {
		for (;;) {}
	} else {
		m_joined_game = true;
		if (m_recv_handlers.handle_0E_recv_start_game != nullptr) {
			m_recv_handlers.handle_0E_recv_start_game(tmp.lobby_data, tmp.header.flags, lobby_entry_idx);
		}
	}

};

struct Tag_801DDB44 { u8 c[8]; };
struct Name_801DDB44 { char c[16]; };
struct Game_801DDB44 { Tag_801DDB44 tag; u8 difficulty_tag; u8 num_players; Name_801DDB44 name; u8 episode; u8 flags; };
extern "C" Game_801DDB44 *__as__13GameListEntryFRC13GameListEntry(void *arg0, const void *arg1);

void TProtocol::recv_text_list(packet &pkt) {
	typedef TMenuList<GameListEntry, 64, 1> text_list;
	text_list tmp = as(text_list &, pkt);
	tmp.bswap();

	m_entry_count = tmp.header.flags;

	for (int i = 0; i < m_entry_count; ++i) {
		__as__13GameListEntryFRC13GameListEntry(&m_game_entries[i], &tmp.entries[i]);
	}

	if (m_recv_handlers.handle_1F_recv_text_list != nullptr) {
		m_recv_handlers.handle_1F_recv_text_list(m_entry_count, m_game_entries, tmp.pad_entries[0]);
	}
};

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma scheduling off
#define arg0 ((Game_801DDB44 *)arg0_)
#define arg1 ((const Game_801DDB44 *)arg1_)
Game_801DDB44 *__as__13GameListEntryFRC13GameListEntry(void *arg0_, const void *arg1_) {
    arg0->tag = arg1->tag;
    arg0->difficulty_tag = arg1->difficulty_tag;
    arg0->num_players = arg1->num_players;
    arg0->name = arg1->name;
    arg0->episode = arg1->episode;
    arg0->flags = arg1->flags;
    return arg0;
}
#undef arg0
#undef arg1
struct Game_801DDB44;
#pragma pop

void TProtocol::recv_game_list(packet &pkt) {
	typedef TMenuList<GameListEntry, 64, 1> game_list;
	game_list tmp = as(game_list &, pkt);
	tmp.bswap();

	m_entry_count = tmp.header.flags;

	for (int i = 0; i < m_entry_count; ++i) {
		__as__13GameListEntryFRC13GameListEntry(&m_game_entries[i], &tmp.entries[i]);
	}

	if (m_recv_handlers.handle_08_recv_game_list != nullptr) {
		m_recv_handlers.handle_08_recv_game_list(m_entry_count, m_game_entries, tmp.pad_entries[0]);
	}
};

void TProtocol::recv_dir_list(packet &pkt) {
	typedef TMenuList<GameListEntry, 64, 1> dir_list;
	dir_list tmp = as(dir_list &, pkt);
	tmp.bswap();

	m_entry_count = tmp.header.flags;

	for (int i = 0; i < m_entry_count; ++i) {
		__as__13GameListEntryFRC13GameListEntry(&m_game_entries[i], &tmp.entries[i]);
	}

	if (m_recv_handlers.handle_07_A0_A1_recv_dir_list != nullptr) {
		m_recv_handlers.handle_07_A0_A1_recv_dir_list(m_entry_count, m_game_entries, tmp.pad_entries[0]);
	}
};

void TProtocol::recv_chat(packet &pkt) {
	TMessageBox tmp = as(TMessageBox &, pkt);
	tmp.bswap();
	if (m_recv_handlers.handle_06_recv_chat != nullptr) {
		m_recv_handlers.handle_06_recv_chat(tmp.tag, tmp.mesg);
	}
};

void TProtocol::recv_logout(packet &pkt) {
	close();

	m_is_encrypted = false;
	m_connected = false;
	m_packet_offset = 0;
	m_packet_size = 0;

	if (m_recv_handlers.handle_05_recv_logout != nullptr) {
		m_recv_handlers.handle_05_recv_logout();
	}
};

void TProtocol::recv_login(packet &pkt) {
	TPlyRecvLogin tmp = as(TPlyRecvLogin &, pkt);
	tmp.bswap();
	if (!tmp.header.flags) {
		m_guildcard_tag = tmp.tag;
		m_client_config = tmp.client_config;
		m_connected = true;
	}

	if (m_recv_handlers.handle_04_recv_login != nullptr) {
		m_recv_handlers.handle_04_recv_login(tmp.header.flags);
	}
};

void TProtocol::recv_regist(packet &pkt) {
	packet_header tmp = pkt.pkt.header;
	tmp.bswap();
	m_regist_state = tmp.flags;
	if (m_recv_handlers.handle_03_recv_regist != nullptr) {
		m_recv_handlers.handle_03_recv_regist(tmp.flags);
	}
};

void TProtocol::recv_text(packet &pkt) {
	TPlyText<1024> tmp = as(TPlyText<1024> &, pkt);
	if (m_recv_handlers.handle_1A_D5_recv_text != nullptr) {
		m_recv_handlers.handle_1A_D5_recv_text(tmp.text);
	}
};

void TProtocol::recv_error(packet &pkt) {
	TMessageBox tmp = as(TMessageBox &, pkt);
	tmp.bswap();
	if (m_recv_handlers.handle_01_recv_error != nullptr) {
		m_recv_handlers.handle_01_recv_error(tmp.mesg);
	}
};

int TProtocol::handle_command(struct packet *pkt) {
	static const command_handler_entry handlers[] = {
		{ 0x01, &TProtocol::recv_error },
		{ 0x03, &TProtocol::recv_regist },
		{ 0x04, &TProtocol::recv_login },
		{ 0x05, &TProtocol::recv_logout },
		{ 0x06, &TProtocol::recv_chat },
		{ 0x07, &TProtocol::recv_dir_list },
		{ 0x08, &TProtocol::recv_game_list },
		{ 0x0E, &TProtocol::recv_start_game },
		{ 0x64, &TProtocol::recv_start_game3 },
		{ 0x12, &TProtocol::recv_banner },
		{ 0x16, &TProtocol::recv_banner_head },
		{ 0x44, &TProtocol::recv_download_head },
		{ 0x13, &TProtocol::recv_download },
		{ 0x14, &TProtocol::recv_upload },
		{ 0x11, &TProtocol::recv_message },
		{ 0x18, &TProtocol::handle_cmd_90 },
		{ 0x17, &TProtocol::handle_cmd_9B },
		{ 0x19, &TProtocol::recv_port },
		{ 0x1A, &TProtocol::recv_text },
		{ 0x1B, &TProtocol::recv_battle_data },
		{ 0x1C, &TProtocol::recv_system_file },
		{ 0x60, &TProtocol::recv_pso_data },
		{ 0x62, &TProtocol::recv_pso_data },
		{ 0x6C, &TProtocol::recv_pso_data_long },
		{ 0x6D, &TProtocol::recv_pso_data_long },
		{ 0x81, &TProtocol::recv_chat_message },
		{ 0x41, &TProtocol::recv_user_ans },
		{ 0x88, &TProtocol::handle_cmd_88 },
		{ 0x8A, &TProtocol::handle_cmd_8A },
		{ 0x80, &TProtocol::recv_generate_id },
		{ 0x67, &TProtocol::recv_start_lobby2 },
		{ 0x83, &TProtocol::recv_room_info },
		{ 0x1D, &TProtocol::recv_ping },
		{ 0x65, &TProtocol::recv_burst_game },
		{ 0x66, &TProtocol::recv_exit_game },
		{ 0x68, &TProtocol::recv_burst_lobby },
		{ 0x69, &TProtocol::recv_exit_lobby },
		{ 0x90, &TProtocol::handle_cmd_90 },
		{ 0x91, &TProtocol::recv_pso_regist_connect },
		{ 0x92, &TProtocol::handle_cmd_92 },
		{ 0x95, &TProtocol::handle_cmd_95 },
		{ 0xA0, &TProtocol::recv_dir_list },
		{ 0xA1, &TProtocol::recv_dir_list },
		{ 0xA2, &TProtocol::recv_quest_menu_list },
		{ 0xA3, &TProtocol::recv_quest_menu_info },
		{ 0xA4, &TProtocol::recv_quest_list },
		{ 0xA5, &TProtocol::recv_quest_info },
		{ 0xA6, &TProtocol::recv_vm_download_head },
		{ 0xA7, &TProtocol::recv_vm_download },
		{ 0x97, &TProtocol::handle_cmd_97 },
		{ 0xB0, &TProtocol::recv_emergency_call },
		{ 0x1F, &TProtocol::recv_text_list },
		{ 0xB1, &TProtocol::handle_cmd_B1 },
		{ 0xC0, &TProtocol::handle_cmd_C0 },
		{ 0xC4, &TProtocol::handle_cmd_C4 },
		{ 0x02, &TProtocol::handle_cmd_02 },
		{ 0x9A, &TProtocol::handle_cmd_9A },
		{ 0x9B, &TProtocol::handle_cmd_9B },
		{ 0x9C, &TProtocol::handle_cmd_9C },
		{ 0xC5, &TProtocol::handle_cmd_C5 },
		{ 0xD1, &TProtocol::recv_advance_trade_state },
		{ 0xD4, &TProtocol::recv_trade_result },
		{ 0xD3, &TProtocol::handle_cmd_D3 },
		{ 0xD5, &TProtocol::handle_cmd_D5 },
		{ 0xD7, &TProtocol::handle_cmd_D7 },
		{ 0xD8, &TProtocol::handle_cmd_D8 },
		{ 0xDA, &TProtocol::handle_cmd_DA },
		{ 0x9F, &TProtocol::handle_cmd_9F },
		{ 0xAB, &TProtocol::handle_cmd_AB },
		{ 0xAC, &TProtocol::handle_cmd_AC },
		{ 0, nullptr }
	};
	u8 command = pkt->pkt.header.command;
	for (int i = 0; handlers[i].command; ++i) {
		if (command == handlers[i].command) {
			(this->*handlers[i].handler)(*pkt);
			return 0;
		}
	}
	m_is_invalid_packet = true;
	return 1;
}

void TProtocol::parse_packet() {
	const int max_packet_size = sizeof(struct packet);
	while (!is_empty()) {
		m_packet.bytes[m_packet_offset++] = next();
		if (m_packet_offset == sizeof(packet_header)) {
			if (m_is_encrypted) {
				m_recv_crypt.encrypt(&m_packet.pkt.header, sizeof(packet_header));
			}
			const int &packet_size = m_packet_size = to_be_uint16_t(m_packet.pkt.header.size);
			if (packet_size > max_packet_size || !packet_size) {
				m_packet_size = 0;
				m_packet_offset = 0;
				m_is_invalid_packet = true;
				break;
			}
		}

		if (m_packet_size > 0 && m_packet_offset >= m_packet_size) {
			if (m_is_encrypted) {
				m_recv_crypt.encrypt(&m_packet.pkt.data, m_packet_size-sizeof(packet_header));
			}
			struct packet *pkt = &m_packet;
			m_packet_size = 0;
			m_packet_offset = 0;
			if (m_handle_pings_only) {
				if (pkt->pkt.header.command == 0x1d) {
					if (!handle_command(pkt)) {
						continue;
					} else {
						break;
					}
				} else {
					copy_packet(pkt);
				}
			} else if (handle_command(pkt)) {
				break;
			}
		}
	}
}

short TProtocol::send(u8 *data, size_t size) {
	const short ret = TTcpSocket::send(data, size);
	return ret;
}

void TProtocol::run_task() {
	TTcpSocket::some_stub();
	some_stub();
	if (m_is_invalid_packet) {
		close();
		m_is_encrypted = 0;
		m_connected = 0;
		m_packet_offset = 0;
		m_packet_size = 0;
	} else if (!m_buffer_cleared) {
		server_packet = &m_packet;
		parse_packet();
		recv();
	}
}

void TProtocol::some_stub() {}

TProtocol::~TProtocol() {

}

#define fill_with(name, value) memset(&m_##name, value, sizeof(m_##name))
#define copy(name) strncpy(m_##name, name, sizeof(m_##name))

TProtocol::TProtocol(TObject *parent, u16 sub_version, int language, char *serial_number, char *access_key, char *password) : TTcpSocket(parent) {
	u8 thing[6];
	m_name = TProtocol_name;
	memset(thing, 0, sizeof(thing));
	{
		int i = 0;
		int j = 0;
		m_smth.m_smth[i++] = 0;
		m_smth.m_smth[i++] = 0;
		m_smth.m_smth[i++] = thing[j++];
		m_smth.m_smth[i++] = thing[j++];
		i = 0;
		m_smth.m_smth1[i++] = thing[j++];
		m_smth.m_smth1[i++] = thing[j++];
		m_smth.m_smth1[i++] = thing[j++];
		m_smth.m_smth1[i++] = thing[j++];
	}
	m_guildcard_tag = TPlyGuildCardTag(-1, -1);
	m_regist_state = 0;
	m_connected = 0;
	m_joined_game = 0;
	m_has_meet_user_settings = 0;
	m_handle_pings_only = false;
	m_entry_count = 0;
	m_unused = 0;
	m_lobby_list_count = 0;
	m_unused5[0] = 0;
	m_unused2 = 0;
	m_udp_disabled = 0;
	m_packet_offset = 0;
	m_packet_size = 0;
	m_sub_version = sub_version;
	m_language = language;

	fill_with(serial_number, 0);
	fill_with(access_key, 0);
	fill_with(password, 0);

	copy(serial_number);
	copy(access_key);
	strncpy(m_password, password, sizeof(m_serial_number));

	fill_with(client_config, 0);

	m_recv_handlers.handle_unused_login = nullptr;
	m_recv_handlers.handle_03_recv_regist = nullptr;
	m_recv_handlers.handle_04_recv_login = nullptr;
	m_recv_handlers.handle_05_recv_logout = nullptr;
	m_recv_handlers.handle_07_A0_A1_recv_dir_list = nullptr;
	m_recv_handlers.handle_01_recv_error = nullptr;
	m_recv_handlers.handle_06_recv_chat = nullptr;
	m_recv_handlers.handle_11_recv_message = nullptr;
	m_recv_handlers.handle_0E_recv_start_game = nullptr;
	m_recv_handlers.unused7 = nullptr;
	m_recv_handlers.handle_64_recv_start_game3 = nullptr;
	m_recv_handlers.unused8 = nullptr;
	m_recv_handlers.handle_67_recv_start_lobby2 = nullptr;
	m_recv_handlers.handle_13_recv_download = nullptr;
	m_recv_handlers.handle_80_recv_generate_id = nullptr;
	m_recv_handlers.unused9 = nullptr;
	m_recv_handlers.handle_65_recv_burst_game = nullptr;
	m_recv_handlers.handle_66_recv_exit_game = nullptr;
	m_recv_handlers.handle_68_recv_burst_lobby = nullptr;
	m_recv_handlers.handle_69_recv_exit_lobby = nullptr;
	m_recv_handlers.handle_92_9C_register_response_packet = nullptr;
	m_recv_handlers.unused10 = nullptr;
	m_recv_handlers.handle_81_recv_chat_message = nullptr;
	m_recv_handlers.handle_41_recv_user_ans = nullptr;
	m_recv_handlers.handle_A2_recv_quest_menu_list = nullptr;
	m_recv_handlers.handle_A3_recv_quest_menu_info = nullptr;
	m_recv_handlers.handle_44_recv_download_head = nullptr;
	m_recv_handlers.handle_13_recv_download = nullptr;
	m_recv_handlers.handle_A4_recv_quest_list = nullptr;
	m_recv_handlers.handle_A5_recv_quest_info = nullptr;
	m_recv_handlers.unused11 = nullptr;
	m_recv_handlers.handle_97_checksum_reply_packet = nullptr;
	m_recv_handlers.handle_B0_recv_emergency_call = nullptr;
	m_recv_handlers.handle_1F_recv_text_list = nullptr;
	m_recv_handlers.handle_88_player_arrow_color_list_packet = nullptr;
	m_recv_handlers.handle_8A_lobby_name_packet = nullptr;
	m_recv_handlers.handle_C5_player_challenge_data_packet = nullptr;
	m_recv_handlers.handle_D3_execute_trade_packet = nullptr;
	m_recv_handlers.handle_D4_trade_result_packet = nullptr;
	m_recv_handlers.handle_D1_advance_trade_state_packet = nullptr;
	m_recv_handlers.handle_D8_infoboard_packet = nullptr;
	m_recv_handlers.handle_DA_lobby_event_packet = nullptr;
	m_recv_handlers.handle_AB_quest_stats_response_packet = nullptr;
}

#undef fill_with
#undef copy

void packet_header::bswap() {
    bswap_16(&size);
}

typedef char RecoveredFields_801DD33C_arg0_0_offset[offsetof(RecoveredFields_801DD33C_arg0, field_0) == 0x0 ? 1 : -1];
typedef char RecoveredFields_801DD33C_arg0_1_offset[offsetof(RecoveredFields_801DD33C_arg0, field_1) == 0x1 ? 1 : -1];
typedef char RecoveredFields_801DD33C_arg0_2_offset[offsetof(RecoveredFields_801DD33C_arg0, field_2) == 0x2 ? 1 : -1];
typedef char RecoveredFields_801DD33C_arg0_4_offset[offsetof(RecoveredFields_801DD33C_arg0, field_4) == 0x4 ? 1 : -1];
typedef char RecoveredFields_801DD33C_arg1_0_offset[offsetof(RecoveredFields_801DD33C_arg1, field_0) == 0x0 ? 1 : -1];
typedef char RecoveredFields_801DD33C_arg1_1_offset[offsetof(RecoveredFields_801DD33C_arg1, field_1) == 0x1 ? 1 : -1];
typedef char RecoveredFields_801DD33C_arg1_2_offset[offsetof(RecoveredFields_801DD33C_arg1, field_2) == 0x2 ? 1 : -1];
typedef char RecoveredFields_801DD33C_arg1_4_offset[offsetof(RecoveredFields_801DD33C_arg1, field_4) == 0x4 ? 1 : -1];

void TProtocol::bswap_cmd_AB() {
	((packet_header *)this)->bswap();
	bswap_16((u16 *)((char *)this + 4));
}

extern "C" {

int bswap__13packet_headerFv(void*);

void TProtocol::bswap_packet() { bswap__13packet_headerFv(this); bswap_16((u16 *)((char*)this + 0x4)); bswap_16((u16 *)((char*)this + 0x6)); bswap_16((u16 *)((char*)this + 0x8)); bswap_16((u16 *)((char*)this + 0xa)); { int i; for (i = 0; i < 8; i++) { bswap_32((u32 *)((char*)this + 0xc + i * 4)); } } }
int TProtocol::bswap_packet_header() { return bswap__13packet_headerFv(this); }

}
