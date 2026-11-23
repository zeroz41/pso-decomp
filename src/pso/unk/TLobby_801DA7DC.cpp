#include "types.h"
#include <string.h>
#include "pso/player/TPlySmth.h"
#include "pso/player/TPlyGuildCardTag_8007B434.h"
#include "pso/unk/TLobby.h"
#include "pso/network/TProtocol.h"
#include "pso/network/protocol/protocol.h"
#include "pso/network/PSOV3EncryptionTCP.h"

void TProtocol::send_c6_packet(void *lobby) {
    if (m_connected != 0) {
        *(u8 *)((s8 *)lobby + 0) = 0xC6;
        *(s16 *)((s8 *)lobby + 2) = 0x7C;
        ((TBlockedSenders *)lobby)->bswap();
        send((u8 *)lobby, 0x7C);
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

extern "C" void set_port__7TSocketFUl(TSocket *socket, s16 port);

s32 TProtocol::set_server_info(const char *serial_v1, const char *access_key_v1, const char *serial,
                               const char *access_key, const char *host, u16 port) {
    s32 error;

    error = resolve_domain((char *)host);
    set_port__7TSocketFUl(this, port);
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
