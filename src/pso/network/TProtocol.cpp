#include "types.h"
#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include "pso/network/TProtocol.h"
#include "pso/network/protocol/protocol.h"
#include "pso/network/PSOV3EncryptionTCP.h"
#include "pso/network/TProtocol_801E08CC.h"
#include "pso/player/TPlySmth.h"
#include "pso/quest/TQuestListOnline.h"
#include "pso/ui/window/TWindowSubComCard_8007A810.h"
#include "pso/unk/TLobby.h"
#include "pso/unk/text_801DF280.h"
#include "pso/player/TPlyClientConfig.h"
#include "pso/network/protocol/packet_classes.h"
#include "pso/player/TPlyGuildCardTag.h"
#include "pso/item/TItemData.h"
#include "pso/network/TPlyMeetUserExtension.h"

LAYOUT_ASSERT(TradeResultCallbackOffset, offsetof(TProtocol, m_recv_handlers.handle_D4_trade_result_packet) == 0xBC9C);
LAYOUT_ASSERT(TradeAdvanceCallbackOffset, offsetof(TProtocol, m_recv_handlers.handle_D1_advance_trade_state_packet) == 0xBCA0);
LAYOUT_ASSERT(ProtocolConnectedOffset, offsetof(TProtocol, m_connected) == 0x1910);
LAYOUT_ASSERT(PacketHeaderSize, sizeof(packet_header) == 4);
LAYOUT_ASSERT(PacketFlagsOffset, offsetof(packet_header, flags) == 1);
LAYOUT_ASSERT(PacketSizeOffset, offsetof(packet_header, size) == 2);

void TProtocol::send_keepalive() {
    packet_header header;
    header.command = 0x1D;
    header.flags = 0;
    header.size = sizeof(header);
    header.bswap();
    send((u8 *)&header, sizeof(header));
}

void TProtocol::handle_cmd_AC(packet &pkt) {
    if (pkt.pkt.header.flags == 0) {
        TQuestListOnline::handle_quest_ready();
        return;
    }
    m_is_invalid_packet = 1;
}

void TProtocol::send_quest_barrier() {
    packet_header header;
    header.command = 0xAC;
    header.flags = 0;
    header.size = sizeof(header);
    header.bswap();
    send((u8 *)&header, sizeof(header));
}

void TProtocol::handle_cmd_AB(packet &pkt) {
    TRecvQuestStats &stats = as(TRecvQuestStats &, pkt);

    stats.bswap();
    if (m_recv_handlers.handle_AB_quest_stats_response_packet != NULL) {
        m_recv_handlers.handle_AB_quest_stats_response_packet(stats.value);
    }
}

void TProtocol::send_statistic(u16 id, u16 first_label, u16 second_label, u32 *values) {
    TSendQuestStatistic pkt;
    s32 i;

    memset(&pkt, 0, sizeof(pkt));
    pkt.header.command = 0xAA;
    pkt.header.flags = 0;
    pkt.header.size = sizeof(pkt);
    pkt.id = id;
    pkt.unused = 0;
    pkt.first_label = first_label;
    pkt.second_label = second_label;
    for (i = 0; i < 8; i++) {
        pkt.values[i] = values[i];
    }
    pkt.bswap();
    send((u8 *)&pkt, sizeof(pkt));
}

void TProtocol::handle_cmd_9F(packet &) {
    TSendClientConfig reply;
    memset(&reply, 0, sizeof(reply));
    reply.header.command = 0x9F;
    reply.header.size = sizeof(reply);
    reply.config = m_client_config;
    reply.bswap();
    send((u8 *)&reply, sizeof(reply));
}

void TProtocol::handle_cmd_DA(packet &pkt) {
    packet_header header = pkt.pkt.header;
    header.bswap();
    if (m_recv_handlers.handle_DA_lobby_event_packet != NULL) {
        m_recv_handlers.handle_DA_lobby_event_packet(header.flags);
    }
}

void TProtocol::handle_cmd_D7(packet &) {
    set_lobby_count_value();
}

void TProtocol::send_download_head(u8 flags, const char *filename) {
    TSendDownloadHead pkt;
    memset(&pkt, 0, sizeof(pkt));
    pkt.header.command = 0xD7;
    pkt.header.flags = flags;
    strncpy(pkt.filename, filename, sizeof(pkt.filename));
    pkt.header.size = sizeof(pkt);
    strncpy(pkt.filename, filename, sizeof(pkt.filename));
    pkt.bswap();
    send((u8 *)&pkt, sizeof(pkt));
}

void TProtocol::send_message_box_closed() {
    packet_header header;
    header.command = 0xD6;
    header.flags = 0;
    header.size = sizeof(header);
    header.bswap();
    send((u8 *)&header, sizeof(header));
}

packet *server_packet;
u32 new_ip_addr;
u16 new_port;
s32 lobby_state_flags;
const char *lobby_server_greeting_text = "DreamCast Lobby Server. Copyright SEGA Enterprises. 1999";
const char *port_map_copyright = "DreamCast Port Map. Copyright SEGA Enterprises. 1999";
OBJECT_NAME(TProtocol);

void TProtocol::handle_cmd_D5(packet &pkt) {
    TPlyText<0x1000> tmp = as(TPlyText<0x1000> &, pkt);
    if (m_recv_handlers.handle_1A_D5_recv_text != NULL) {
        m_recv_handlers.handle_1A_D5_recv_text(tmp.text);
    }
}

void TProtocol::send_cancel_trade() {
    packet_header header;
    header.command = 0xD4;
    header.flags = 0;
    header.size = sizeof(header);
    header.bswap();
    send((u8*)&header, sizeof(header));
}

void TProtocol::recv_trade_result(packet &pkt) {
    packet_header header = pkt.pkt.header;
    header.bswap();
    if (m_recv_handlers.handle_D4_trade_result_packet != 0) {
        m_recv_handlers.handle_D4_trade_result_packet(header.flags);
    }
}

void TProtocol::handle_cmd_D3(packet &pkt) {
    char message[0x80];
    TTradeList trade_list = as(TTradeList &, pkt);
    trade_list.bswap();
    sprintf(message, "RcvTradeList %d %d", trade_list.item_count, trade_list.target_client_id);
    if (m_recv_handlers.handle_D3_execute_trade_packet != NULL) {
        m_recv_handlers.handle_D3_execute_trade_packet(&trade_list);
    }
}
void TProtocol::send_trade_ready() {
    packet_header header;
    header.command = 0xD2;
    header.flags = 0;
    header.size = sizeof(header);
    header.bswap();
    send((u8*)&header, sizeof(header));
}

void TProtocol::recv_advance_trade_state(packet &pkt) {
    packet_header header = pkt.pkt.header;
    header.bswap();
    if (m_recv_handlers.handle_D1_advance_trade_state_packet != 0) {
        m_recv_handlers.handle_D1_advance_trade_state_packet(header.flags);
    }
}

void TProtocol::send_trade_list(TTradeList *list) {
    char message[0x80];
    sprintf(message, "SndTradeList %d %d", list->item_count, list->target_client_id);
    TTradeList pkt = *list;
    pkt.header.command = 0xD0;
    pkt.header.flags = 0;
    pkt.header.size = sizeof(pkt);
    pkt.bswap();
    send((u8 *)&pkt, sizeof(pkt));
}

void TProtocol::send_text_packet_D9(char *str) {
    TPlyText<172> pkt;
    s32 n;
    memset(&pkt, 0, sizeof(pkt));
    pkt.header.command = 0xD9;
    pkt.header.flags = 0;
    char *t = pkt.text;
    strncpy(t, str, sizeof(pkt.text));
    n = (strlen(t) + 8) & ~3;
    pkt.header.size = n;
    pkt.bswap();
    send((u8 *)&pkt, n);
}

void TProtocol::handle_cmd_D8(packet &pkt) {
    TRecvInfoBoard tmp = as(TRecvInfoBoard &, pkt);
    tmp.bswap();
    if (m_recv_handlers.handle_D8_infoboard_packet != NULL) {
        m_recv_handlers.handle_D8_infoboard_packet(&tmp);
    }
}

void TProtocol::send_info_board_request() {
    packet_header header;
    memset(&header, 0, sizeof(header));
    header.command = 0xD8;
    header.flags = 0;
    header.size = sizeof(header);
    header.bswap();
    send((u8*)&header, sizeof(header));
}

void TProtocol::send_disable_auto_reply() {
    packet_header header;
    header.command = 0xC8;
    header.flags = 0;
    header.size = sizeof(header);
    header.bswap();
    send((u8*)&header, sizeof(header));
}
void TProtocol::send_text_packet_c7(char *str) {
    if (m_connected != 0) {
    TPlyText<512> pkt;
    s32 n;
    memset(&pkt, 0, sizeof(pkt));
    pkt.header.command = 0xC7;
    pkt.header.flags = 0;
    char *t = pkt.text;
    strncpy(t, str, sizeof(pkt.text) - 1);
    n = (strlen(t) + 8) & ~3;
    pkt.header.size = n;
    pkt.bswap();
    send((u8 *)&pkt, n);
    }
}

void TProtocol::send_c6_packet(TBlockedSenders *senders) {
    if (m_connected != 0) {
        senders->header.command = 0xC6;
        senders->header.size = sizeof(*senders);
        senders->bswap();
        send((u8 *)senders, sizeof(*senders));
    }
}

void TProtocol::handle_cmd_C5(packet &pkt) {
    TRecvChallengeData tmp = as(TRecvChallengeData &, pkt);
    tmp.bswap();
    if (m_recv_handlers.handle_C5_player_challenge_data_packet != NULL) {
        m_recv_handlers.handle_C5_player_challenge_data_packet(tmp.records, tmp.header.flags);
    }
}

s32 TProtocol::send_login_9e_extended(void *player_name, int udp_disabled) {
    memset(m_player_name, 0, 0x10);
    strncpy(m_player_name, (const char *)player_name, 0x10);
    m_udp_disabled = udp_disabled;
    TSendLogin pkt;
    memset(&pkt, 0, sizeof(pkt));
    pkt.header.command = 0x9E;
    pkt.header.flags = m_udp_disabled;
    pkt.header.size = sizeof(pkt);
    __as__16TPlyGuildCardTagFRC16TPlyGuildCardTag(&pkt.tag, &m_guildcard_tag);
    pkt.hardware_id = m_smth;
    pkt.sub_version = m_sub_version;
    pkt.language = m_language;
    pkt.client_config = m_client_config;
    strncpy(pkt.serial_number_v1, m_serial_number_v1, sizeof(pkt.serial_number_v1));
    strncpy(pkt.access_key_v1, m_access_key_v1, sizeof(pkt.access_key_v1));
    strncpy(pkt.serial_number, m_serial_number2, sizeof(pkt.serial_number));
    strncpy(pkt.access_key, m_access_key2, sizeof(pkt.access_key));
    strncpy(pkt.serial_number2, m_serial_number, sizeof(pkt.serial_number2));
    strncpy(pkt.access_key2, m_access_key, sizeof(pkt.access_key2));
    strncpy(pkt.name, m_player_name, sizeof(pkt.name));
    pkt.bswap();
    send((u8 *)&pkt, sizeof(pkt));
    return 0;
}

void TProtocol::handle_cmd_9C(packet &pkt) {
    packet_header header = pkt.pkt.header;
    header.bswap();
    m_regist_state = header.flags;
    if (m_recv_handlers.handle_92_9C_register_response_packet != NULL) {
        m_recv_handlers.handle_92_9C_register_response_packet(header.flags);
    }
}
void TProtocol::handle_cmd_02(packet &pkt) {
    TRecvPsoRegistConnect tmp = as(TRecvPsoRegistConnect &, pkt);
    tmp.bswap();
    if (!strcmp(lobby_server_greeting_text, tmp.copyright)) {
        m_recv_crypt.reset(tmp.server_key);
        m_send_crypt.reset(tmp.client_key);
        m_is_encrypted = true;
        TSendLogin tmp2;
        memset(&tmp2, 0, sizeof(tmp2));
        tmp2.header.command = 0x9E;
        tmp2.header.flags = m_udp_disabled;
        __as__16TPlyGuildCardTagFRC16TPlyGuildCardTag(&tmp2.tag, &m_guildcard_tag);
        tmp2.hardware_id = m_smth;
        tmp2.sub_version = m_sub_version;
        tmp2.language = m_language;
        strncpy(tmp2.serial_number_v1, m_serial_number_v1, sizeof(tmp2.serial_number_v1));
        strncpy(tmp2.access_key_v1, m_access_key_v1, sizeof(tmp2.access_key_v1));
        strncpy(tmp2.serial_number, m_serial_number2, sizeof(tmp2.serial_number));
        strncpy(tmp2.access_key, m_access_key2, sizeof(tmp2.access_key));
        strncpy(tmp2.serial_number2, m_serial_number, sizeof(tmp2.serial_number2));
        strncpy(tmp2.access_key2, m_access_key, sizeof(tmp2.access_key2));
        strncpy(tmp2.name, m_player_name, sizeof(tmp2.name));
        tmp2.client_config = m_client_config;
        if (m_has_meet_user_settings != 0) {
            tmp2.is_extended = 1;
            tmp2.extension = meet_user_settings;
            tmp2.header.size = sizeof(tmp2);
            tmp2.bswap();
            send((u8 *)&tmp2, sizeof(tmp2));
        } else {
            tmp2.header.size = offsetof(TSendLogin, extension);
            tmp2.bswap();
            send((u8 *)&tmp2, offsetof(TSendLogin, extension));
        }
    } else {
        close();
    }
    m_has_meet_user_settings = 0;
}

void TProtocol::handle_cmd_9A(packet &pkt) {
    packet_header header = pkt.pkt.header;
    header.bswap();
    m_regist_state = header.flags;
    if (m_recv_handlers.handle_18_90_9A_recv_pso_regist_check != NULL) {
        m_recv_handlers.handle_18_90_9A_recv_pso_regist_check(header.flags);
    }
}

void TProtocol::handle_cmd_9B(packet &pkt) {
    TRecvPsoRegistConnect tmp = as(TRecvPsoRegistConnect &, pkt);
    tmp.bswap();
    if (!strcmp(port_map_copyright, tmp.copyright)) {
        m_recv_crypt.reset(tmp.server_key);
        m_send_crypt.reset(tmp.client_key);
        m_is_encrypted = true;
        TSendVerifyLicense tmp2;
        memset(&tmp2, 0, sizeof(tmp2));
        tmp2.header.command = 0xDB;
        tmp2.header.size = sizeof(tmp2);
        strncpy(tmp2.serial_number_v1, m_serial_number_v1, sizeof(tmp2.serial_number_v1));
        strncpy(tmp2.access_key_v1, m_access_key_v1, sizeof(tmp2.access_key_v1));
        strncpy(tmp2.serial_number, m_serial_number2, sizeof(tmp2.serial_number));
        strncpy(tmp2.access_key, m_access_key2, sizeof(tmp2.access_key));
        tmp2.hardware_id = m_smth;
        tmp2.sub_version = m_sub_version;
        strncpy(tmp2.serial_number2, m_serial_number, sizeof(tmp2.serial_number2));
        strncpy(tmp2.access_key2, m_access_key, sizeof(tmp2.access_key2));
        strncpy(tmp2.password, m_password, sizeof(tmp2.password));
        tmp2.bswap();
        send(as(u8 *, &tmp2), sizeof(tmp2));
    } else {
        close();
    }
}

s32 TProtocol::set_server_info(const char *serial_v1, const char *access_key_v1, const char *serial,
                               const char *access_key, const char *host, u16 port) {
    s32 error;

    error = resolve_domain(host);
    set_port(port);
    if (error != 0) {
        return 2;
    }
    memset(m_serial_number_v1, 0, 0x11);
    memset(m_access_key_v1, 0, 0x11);
    memset(m_serial_number2, 0, 0x11);
    memset(m_access_key2, 0, 0x11);
    strncpy(m_serial_number_v1, serial_v1, 8);
    strncpy(m_access_key_v1, access_key_v1, 0xC);
    strncpy(m_serial_number2, serial, 8);
    strncpy(m_access_key2, access_key, 0xC);
    if (open() < 0) {
        return 1;
    }
    recv();
    return 0;
}

void TProtocol::send_lobby_name_request() {
    packet_header header;
    header.command = 0x8A;
    header.flags = 0;
    header.size = sizeof(header);
    header.bswap();
    send((u8*)&header, sizeof(header));
}

void TProtocol::handle_cmd_8A(packet &pkt) {
    TRecvLobbyName tmp = as(TRecvLobbyName &, pkt);
    bswap_cmd_8a_header(&tmp);
    if (m_recv_handlers.handle_8A_lobby_name_packet != NULL) {
        m_recv_handlers.handle_8A_lobby_name_packet(tmp.name);
    }
}

void TProtocol::send_lobby_arrow(int arrow) {
    packet_header header;
    header.command = 0x89;
    header.flags = arrow;
    header.size = sizeof(header);
    header.bswap();
    send((u8*)&header, sizeof(header));
}

// The lobby registers a no-argument function as the 88 handler; the protocol passes it the list.
typedef void (*arrow_color_list_handler)(void *list);

void TProtocol::handle_cmd_88(packet &pkt) {
    char list[0xC4];
    arrow_color_list_handler handler;

    copy_entry_table((s32 *)list, (s32 *)&pkt);
    bswap_cmd_88_body(list);
    handler = (arrow_color_list_handler)m_recv_handlers.handle_88_player_arrow_color_list_packet;
    if (handler != NULL) {
        handler(list);
    }
}

void TProtocol::handle_cmd_C4(packet &pkt) {
    char results[sizeof(ChoiceSearchResultList)];

    copy_cmd_c4_entry_table((s32 *)results, (s32 *)&pkt);
    bswap_cmd_c4_body(results);
    if (m_recv_handlers.handle_C4_choice_search_reply_packet != NULL) {
        m_recv_handlers.handle_C4_choice_search_reply_packet((ChoiceSearchResultList *)results);
    }
}

void TProtocol::send_choice_search(TPlyChoiceSearchConfig &parameters) {
    ChoiceSearchPacket packet;
    if (m_connected != 0) {
        memset(&packet, 0, sizeof(packet));
        packet.header.command = 0xC3;
        packet.header.flags = 0;
        packet.header.size = sizeof(packet);
        copy_choice_search_parameters(&packet.parameters, &parameters);
        packet.bswap();
        send((u8*)&packet, sizeof(packet));
    }
}

void TProtocol::send_choice_search_parameters(TPlyChoiceSearchConfig &parameters) {
    ChoiceSearchPacket packet;
    if (m_connected != 0) {
        memset(&packet, 0, sizeof(packet));
        packet.header.command = 0xC2;
        packet.header.flags = 0;
        packet.header.size = sizeof(packet);
        copy_choice_search_parameters(&packet.parameters, &parameters);
        packet.bswap();
        send((u8*)&packet, sizeof(packet));
    }
}

void TProtocol::handle_cmd_C0(packet &pkt) {
    TRecvChoiceSearchOptions tmp = as(TRecvChoiceSearchOptions &, pkt);
    bswap_c0_lobby_entries(&tmp);
    if (m_recv_handlers.handle_C0_choice_search_option_packet != NULL) {
        m_recv_handlers.handle_C0_choice_search_option_packet(&tmp);
    }
}

void TProtocol::send_choice_search_options_request() {
    packet_header header;
    if (m_connected != 0) {
        memset(&header, 0, sizeof(header));
        header.command = 0xC0;
        header.flags = 0;
        header.size = sizeof(header);
        header.bswap();
        send((u8*)&header, sizeof(header));
    }
}

// The lobby registers a no-argument function as the B1 handler; the protocol passes it the time text.
typedef void (*server_time_handler)(char *time);

void TProtocol::handle_cmd_B1(packet &pkt) {
    TRecvServerTime recv = as(TRecvServerTime &, pkt);
    server_time_handler handler;
    s32 low = recv.time_flags_low;
    s32 mid = recv.time_flags_mid;
    s32 high = recv.time_flags_high;

    lobby_state_flags = 0;
    lobby_state_flags = (lobby_state_flags & ~0xFF) | (low & 0xFF);
    lobby_state_flags = (lobby_state_flags & ~0xFF00) | ((mid << 8) & 0xFF00);
    lobby_state_flags = (lobby_state_flags & ~0xFF0000) | ((high << 16) & 0xFF0000);
    bswap_packet_header_cmd_b1(&recv);
    handler = (server_time_handler)m_recv_handlers.handle_B1_current_time_packet;
    if (handler != NULL) {
        handler(recv.time);
    }
}

// ---- pso/network/TProtocol_801DB474
#include "pso/network/TProtocol.h"

void TProtocol::send_server_time_request() {
    packet_header header;
    if (m_connected != 0) {
        header.command = 0xB1;
        header.flags = 0;
        header.size = sizeof(header);
        header.bswap();
        send((u8*)&header, sizeof(header));
    }
}

void TProtocol::send_server_time_accepted() {
    packet_header header;
    if (m_connected != 0) {
        header.command = 0x99;
        header.flags = 0;
        header.size = sizeof(header);
        header.bswap();
        send((u8*)&header, sizeof(header));
    }
}

// ---- pso/unk/text_801DB554
#include "types.h"
#include "pso/unk/TLobby.h"
#include "pso/network/protocol/protocol.h"

void TProtocol::send_6F_burst_done() {
    packet_header header;
    if (m_connected != 0) {
        header.command = 0x6F;
        header.flags = 0;
        header.size = sizeof(header);
        header.bswap();
        send((u8 *)&header, sizeof(header));
    }
}

// ---- pso/network/TProtocol_801DB5C4


void TProtocol::send_quest_menu_closed() {
    packet_header header;
    memset(&header, 0, sizeof(header));
    header.command = 0xA9;
    header.size = sizeof(header);
    header.bswap();
    send((u8*)&header, sizeof(header));
}

// ---- pso/network/TProtocol_801DB630


void TProtocol::handle_cmd_97(packet &pkt) {
    packet_header header = pkt.pkt.header;
    header.bswap();
    u8 flags = header.flags;
    if (m_recv_handlers.handle_97_checksum_reply_packet != NULL) {
        m_recv_handlers.handle_97_checksum_reply_packet(flags);
    }
}

// ---- pso/network/TProtocol_801DB684

#include "pso/ui/chat/TChatMessage.h"
#include "pso/ui/window/TWindowSubComCard_8007A810.h"
#include "pso/unk/text_801DF280.h"
#include <stddef.h>

struct CharacterSaveInfoPacket {
    packet_header header;
    C_CharSaveInfo_DCv2_PC_V3_BB_96 payload;
};

struct ChangeShipOrBlockPacket {
    packet_header header;
    C_ChangeShipOrBlock_A0_A1 payload;
};

LAYOUT_ASSERT(CharacterSaveInfoPacket_size, sizeof(CharacterSaveInfoPacket) == 0xC);
LAYOUT_ASSERT(ChangeShipOrBlockPacket_size, sizeof(ChangeShipOrBlockPacket) == 0x1C);
LAYOUT_ASSERT(TProtocol_connected_offset, offsetof(TProtocol, m_connected) == 0x1910);
LAYOUT_ASSERT(TProtocol_guildcard_offset, offsetof(TProtocol, m_guildcard_tag) == 0x1900);

void TProtocol::send_character_save_info(int creation_timestamp, int event_counter) {
    CharacterSaveInfoPacket packet;
    packet.header.command = 0x96;
    packet.header.flags = 0;
    packet.header.size = sizeof(packet);
    packet.payload.creation_timestamp = creation_timestamp;
    packet.payload.event_counter = event_counter;
    bswap_save_packet((saddr)&packet);
    send((u8 *)&packet, sizeof(packet));
}

void TProtocol::send_quest_menu_request() {
    packet_header header;
    if (m_connected != 0) {
        header.command = 0xA2;
        header.flags = 0;
        header.size = sizeof(header);
        header.bswap();
        send((u8 *)&header, sizeof(header));
    }
}

void TProtocol::send_block_list_request() {
    ChangeShipOrBlockPacket packet;
    u8 pad[8];
    if (m_connected != 0) {
        construct_change_ship_block_packet((saddr)&packet);
        memset(&packet, 0, sizeof(packet));
        packet.header.command = 0xA1;
        packet.header.size = sizeof(packet);
        __as__16TPlyGuildCardTagFRC16TPlyGuildCardTag(&packet.payload, &m_guildcard_tag);
        bswap_change_ship_block_packet(&packet);
        send((u8 *)&packet, sizeof(packet));
    }
}

void TProtocol::send_ship_list_request() {
    ChangeShipOrBlockPacket packet;
    u8 pad[8];
    if (m_connected != 0) {
        construct_change_ship_block_packet((saddr)&packet);
        memset(&packet, 0, sizeof(packet));
        packet.header.command = 0xA0;
        packet.header.size = sizeof(packet);
        __as__16TPlyGuildCardTagFRC16TPlyGuildCardTag(&packet.payload, &m_guildcard_tag);
        bswap_change_ship_block_packet(&packet);
        send((u8 *)&packet, sizeof(packet));
    }
}

void TProtocol::send_simple_mail(TChatMessage &message) {
    if (m_connected != 0) {
        message.header.command = 0x81;
        message.header.flags = 0;
        message.header.size = 0x220;
        bswap__12TChatMessageFv((saddr)&message);
        send((u8 *)&message, 0x220);
    }
}

// ---- pso/network/TProtocol_801DB8EC


void TProtocol::handle_cmd_95(packet &pkt) {
    packet_header header = pkt.pkt.header;
    header.bswap();
    if (m_recv_handlers.handle_95_request_character_data_packet != NULL) {
        m_recv_handlers.handle_95_request_character_data_packet();
    }
}
void TProtocol::handle_cmd_92(packet &pkt) {
    packet_header header = pkt.pkt.header;
    header.bswap();
    m_regist_state = header.flags;
    if (m_recv_handlers.handle_92_9C_register_response_packet != NULL) {
        m_recv_handlers.handle_92_9C_register_response_packet(header.flags);
    }
}

// ---- pso/unk/text_801DB998

#include "pso/player/TPlySmth.h"
#include "pso/ui/chat/TChatMessage_801DF918.h"

struct Stack_801DB998 {
    u8 sp8;
    u8 pad_9[0x1];
    s16 spA;
    u8 spC[8];
    s32 sp14;
    u8 pad_18[0x1];
    s8 sp19;
    u8 pad_1A[0x2];
    char sp1C[0x30];
    char sp4C[0x30];
    char sp7C[0x30];
};

void TProtocol::send_register_9c() {
    Stack_801DB998 stack;
    construct_cmd_9c_send_pso_regist((&stack.sp8));
    memset(&stack.sp8, 0, 0xA4);
    stack.sp8 = 0x9C;
    stack.spA = 0xA4;
    __as__8TPlySmthFRC8TPlySmth((saddr)&stack.spC, (saddr)&m_smth);
    stack.sp14 = (s32)m_sub_version;
    stack.sp19 = (s8)m_language;
    strncpy(stack.sp1C, m_serial_number, 0x30);
    strncpy(stack.sp4C, m_access_key, 0x30);
    strncpy(stack.sp7C, m_password, 0x30);
    bswap_cmd_9c_send_pso_regist((&stack.sp8));
    send(&stack.sp8, 0xA4);
}

// ---- pso/network/TProtocol_801DBA58


void TProtocol::handle_cmd_90(packet &pkt) {
    packet_header header = pkt.pkt.header;
    header.bswap();
    m_regist_state = header.flags;
    if (m_recv_handlers.handle_18_90_9A_recv_pso_regist_check != NULL) {
        m_recv_handlers.handle_18_90_9A_recv_pso_regist_check(header.flags);
    }
}

// ---- pso/network/TProtocol
#include <global_types.h>
#include "pso/network/TPlyJoinLobbyEntry.h"

#include "pso/system/byteswap.h"

#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include <string.h>
#include <stdio.h>
#include <stddef.h>
#include "pso/forward.h"
#include "pso/macros.h"
#include "pso/system/task/TMainTask.h"
#include "pso/ui/TMenuList.h"
#include "pso/player/TPlyCharData.h"
#include "pso/player/TPlyDispData.h"
#include "pso/player/TPlyInventory.h"
#include "pso/system/task/TObject.h"
#include "pso/network/TSocket.h"

extern packet *server_packet;


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

void TProtocol::send_pso_data_long2(u32 flags, long_game_command &packet, size_t size) {
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


void TProtocol::send_pso_data2(u32 flags, game_command &packet, u32 size) {
    char buf[0x80];
    sprintf(buf, "SndPsoData2 %d %d %d", packet.header.command, size, flags);
    if (this->m_connected != 0) {
        TRecvPsoData pkt;
        int packet_size;
        pkt.header.command = 0x62;
        pkt.header.flags = flags;
        pkt.header.size = size + 4;
        packet_size = pkt.header.size;
        memcpy(&pkt.data.pkt, &packet, size);
        pkt.bswap();
        this->send((u8 *)&pkt, packet_size);
    }
}

void TProtocol::send_pso_data(game_command &packet, u32 size) {
    char buf[0x80];
    sprintf(buf, "SndPsoData %d %d", packet.header.command, size);
    if (this->m_connected != 0) {
        TRecvPsoData pkt;
        int packet_size;
        pkt.header.command = 0x60;
        pkt.header.flags = 0;
        pkt.header.size = size + 4;
        packet_size = pkt.header.size;
        memcpy(&pkt.data.pkt, &packet, size);
        pkt.bswap();
        this->send((u8 *)&pkt, packet_size);
    }
}

struct List_801DC1E4 { u8 command; u8 flags; u16 size; u32 entries[30]; };
struct Text_801DC1E4 { u8 command; u8 flags; u16 size; char text[0x200]; };
struct Proto_801DC1E4 { u8 pad[0x1910]; s32 connected; u8 pad1914[0x74]; u8 char_data[0x41C]; };

s32 validate_player_visual_record(void *arg0);
extern "C" {

void send_player_data_98__9TProtocolFPvPvPvPvPvPvPv(Proto_801DC1E4 *self, u8 *char_data, TPlyChallenge *challenge, TPlyChoiceSearchConfig *choice_search_config,
                               List_801DC1E4 *blocked_senders, Text_801DC1E4 *auto_reply, char *info_board) {
    if (self->connected) {
        validate_player_visual_record(char_data + 0x370);
        TProtocol::copy_player_data(self->char_data, char_data);
        TPlyJoinData tmp;
        memset(&tmp, 0, sizeof(tmp));
        tmp.header.command = 0x98;
        tmp.header.flags = 3;
        tmp.header.size = sizeof(tmp);
        TProtocol::copy_player_data(&tmp.char_data, self->char_data);
        tmp.challenge = *challenge;
        copy_choice_search_parameters(&tmp.choice_search_config, choice_search_config);
        strncpy(tmp.info_board, info_board, sizeof(tmp.info_board));
        for (int i = 0; i < blocked_senders->flags; ++i) {
            tmp.blocked_senders[i] = blocked_senders->entries[i];
        }
        tmp.auto_reply_enabled = auto_reply->flags;
        strncpy(tmp.auto_reply, auto_reply->text, sizeof(tmp.auto_reply) - 1);
        const int packet_size = strlen(tmp.auto_reply) + 0x680;
        tmp.header.size = packet_size & ~3;
        encode_uploaded_player_inventory(&tmp.char_data);
        tmp.bswap();
        ((TProtocol *)self)->send((u8 *)&tmp, packet_size & ~3);
    }
}

struct List_801DC34C { u8 command; u8 flags; u16 size; u32 entries[30]; };
struct Text_801DC34C { u8 command; u8 flags; u16 size; char text[0x200]; };
struct Proto_801DC34C { u8 pad[0x1910]; s32 connected; u8 pad1914[0x74]; u8 char_data[0x41C]; };

void send_player_data_61__9TProtocolFPvPvPvPvPvPvPv(Proto_801DC34C *self, u8 *char_data, TPlyChallenge *challenge, TPlyChoiceSearchConfig *choice_search_config,
                               List_801DC34C *blocked_senders, Text_801DC34C *auto_reply, char *info_board) {
    if (self->connected) {
        validate_player_visual_record(char_data + 0x370);
        TProtocol::copy_player_data(self->char_data, char_data);
        TPlyJoinData tmp;
        memset(&tmp, 0, sizeof(tmp));
        tmp.header.command = 0x61;
        tmp.header.flags = 3;
        tmp.header.size = sizeof(tmp);
        TProtocol::copy_player_data(&tmp.char_data, self->char_data);
        tmp.challenge = *challenge;
        copy_choice_search_parameters(&tmp.choice_search_config, choice_search_config);
        strncpy(tmp.info_board, info_board, sizeof(tmp.info_board));
        for (int i = 0; i < blocked_senders->flags; ++i) {
            tmp.blocked_senders[i] = blocked_senders->entries[i];
        }
        tmp.auto_reply_enabled = auto_reply->flags;
        strncpy(tmp.auto_reply, auto_reply->text, sizeof(tmp.auto_reply) - 1);
        const int packet_size = strlen(tmp.auto_reply) + 0x680;
        tmp.header.size = packet_size & ~3;
        encode_uploaded_player_inventory(&tmp.char_data);
        tmp.bswap();
        ((TProtocol *)self)->send((u8 *)&tmp, packet_size & ~3);
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
	set_port(new_port);

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


void TProtocol::recv_room_info(packet &pkt) {
	typedef TMenuList<LobbyListEntry, 16, 0> lobby_list;
	lobby_list tmp = as(lobby_list &, pkt);
	tmp.bswap();

	m_lobby_list_count = tmp.header.flags;

	if (enable_v2_features) {
		for (int i = 0; i < m_lobby_list_count; ++i) {
			m_lobby_entries[i] = tmp.entries[i];
		}
	} else {
		for (int i = 0; i < 10; ++i) {
			m_lobby_entries[i] = tmp.entries[i];
		}
	}
};

#pragma push
#pragma scheduling off
LobbyListEntry &LobbyListEntry::operator=(const LobbyListEntry &other) {
#ifdef __MWERKS__
    __memcpy(&tag, &other.tag, sizeof(tag));
#else
    tag = other.tag;
#endif
    smth = other.smth;
    return *this;
}
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

void TProtocol::recv_text_list(packet &pkt) {
	typedef TMenuList<GameListEntry, 64, 1> text_list;
	text_list tmp = as(text_list &, pkt);
	tmp.bswap();

	m_entry_count = tmp.header.flags;

	for (int i = 0; i < m_entry_count; ++i) {
		m_game_entries[i] = tmp.entries[i];
	}

	if (m_recv_handlers.handle_1F_recv_text_list != nullptr) {
		m_recv_handlers.handle_1F_recv_text_list(m_entry_count, m_game_entries, tmp.pad_entries[0]);
	}
};

#pragma push
#pragma scheduling off
GameListEntry &GameListEntry::operator=(const GameListEntry &other) {
#ifdef __MWERKS__
    __memcpy(&tag, &other.tag, sizeof(tag));
#else
    tag = other.tag;
#endif
    difficulty_tag = other.difficulty_tag;
    num_players = other.num_players;
#ifdef __MWERKS__
    __memcpy(name, other.name, sizeof(name));
#else
    memmove(name, other.name, sizeof(name));
#endif
    episode = other.episode;
    flags = other.flags;
    return *this;
}
#pragma pop

void TProtocol::recv_game_list(packet &pkt) {
	typedef TMenuList<GameListEntry, 64, 1> game_list;
	game_list tmp = as(game_list &, pkt);
	tmp.bswap();

	m_entry_count = tmp.header.flags;

	for (int i = 0; i < m_entry_count; ++i) {
		m_game_entries[i] = tmp.entries[i];
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
		m_game_entries[i] = tmp.entries[i];
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

int TProtocol::handle_command(union packet *pkt) {
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
	const int max_packet_size = sizeof(union packet);
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
			union packet *pkt = &m_packet;
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

LAYOUT_ASSERT(RecoveredFields_801DD33C_arg0_0_offset, offsetof(RecoveredFields_801DD33C_arg0, field_0) == 0x0);
LAYOUT_ASSERT(RecoveredFields_801DD33C_arg0_1_offset, offsetof(RecoveredFields_801DD33C_arg0, field_1) == 0x1);
LAYOUT_ASSERT(RecoveredFields_801DD33C_arg0_2_offset, offsetof(RecoveredFields_801DD33C_arg0, field_2) == 0x2);
LAYOUT_ASSERT(RecoveredFields_801DD33C_arg0_4_offset, offsetof(RecoveredFields_801DD33C_arg0, field_4) == 0x4);
LAYOUT_ASSERT(RecoveredFields_801DD33C_arg1_0_offset, offsetof(RecoveredFields_801DD33C_arg1, field_0) == 0x0);
LAYOUT_ASSERT(RecoveredFields_801DD33C_arg1_1_offset, offsetof(RecoveredFields_801DD33C_arg1, field_1) == 0x1);
LAYOUT_ASSERT(RecoveredFields_801DD33C_arg1_2_offset, offsetof(RecoveredFields_801DD33C_arg1, field_2) == 0x2);
LAYOUT_ASSERT(RecoveredFields_801DD33C_arg1_4_offset, offsetof(RecoveredFields_801DD33C_arg1, field_4) == 0x4);

void TRecvQuestStats::bswap() {
    header.bswap();
    bswap_16(&value);
}

void TSendQuestStatistic::bswap() {
    int i;

    header.bswap();
    bswap_16(&id);
    bswap_16(&unused);
    bswap_16(&first_label);
    bswap_16(&second_label);
    for (i = 0; i < 8; i++) {
        bswap_32(&values[i]);
    }
}

void TSendClientConfig::bswap() {
    header.bswap();
}

#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off

struct ClientConfigBytes { u8 bytes[0x20]; };

TPlyClientConfig& TPlyClientConfig::operator=(const TPlyClientConfig& other) {
    *reinterpret_cast<ClientConfigBytes*>(this) =
        *reinterpret_cast<const ClientConfigBytes*>(&other);
    return *this;
}

void TSendDownloadHead::bswap() {
    header.bswap();
}

void TTradeList::bswap() {
    header.bswap();
    bswap_16(&target_client_id);
    bswap_16(&item_count);
    for (int i = 0; i < 32; i++) {
        items[i].bswap();
    }
}
template <> void TPlyText<172>::bswap() { header.bswap(); }
void TRecvInfoBoard::bswap() { header.bswap(); }
template <> void TPlyText<512>::bswap() { header.bswap(); }
void TBlockedSenders::bswap() {
    header.bswap();
    for (int i = 0; i < 30; ++i) {
        bswap_32(&blocked_senders[i]);
    }
}
void TRecvChallengeData::bswap() {
    header.bswap();
    for (int i = 0; i < 12; i++) {
        records[i].bswap();
    }
}
void TPlyChallenge::bswap() {
    bswap_32(&client_id);
    ((TLobby *)&challenge)->bswap_challenge_battle_records();
    bswap_16(&battle_place_count_1);
    bswap_16(&battle_place_count_2);
    bswap_16(&battle_place_count_3);
    bswap_16(&battle_place_count_4);
    bswap_16(&battle_disconnect_count);
    bswap_16(&pad_10E);
    bswap_16(&pad_110);
    bswap_16(&pad_112);
    bswap_32(&pad_114);
    bswap_32(&pad_118);
}
void TSendLogin::bswap() {
    header.bswap();
    tag.bswap();
    bswap_ply_smth_pair(&hardware_id);
    bswap_32(&sub_version);
    extension.bswap();
}

void TPlyMeetUserExtension::bswap() {
    for (int i = 0; i < 8; ++i) {
        tags[i].bswap();
    }
    bswap_32(&mbr_0x40);
}

void TRecvPsoRegistConnect::bswap() {
    header.bswap();
    bswap_32(&server_key);
    bswap_32(&client_key);
}
