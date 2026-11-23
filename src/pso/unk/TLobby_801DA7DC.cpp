#include "types.h"
#include <string.h>
#include "pso/player/TPlySmth.h"
#include "pso/unk/TLobby_801DEFC4.h"
#include "pso/player/TPlyGuildCardTag_8007B434.h"
#include "pso/unk/TLobby.h"
#include "pso/network/TProtocol.h"
#include "pso/network/protocol/protocol.h"
#include "pso/network/PSOV3EncryptionTCP.h"

struct Pkt_801DA8C4 {
    u8 cmd;
    u8 flag;
    u16 size;
    u8 tag[8];
    u8 smth[8];
    u32 f14;
    u8 pad18;
    u8 f19;
    u8 pad1A[2];
    char name1[0x10];
    char name2[0x10];
    char name3[0x10];
    char name4[0x10];
    char desc1[0x30];
    char desc2[0x30];
    char name5[0x10];
    u8 config[0x150 - 0xCC];
};

struct Pkt_801DAA70 {
    u8 cmd;
    u8 flag;
    u16 size;
    u8 tag[8];
    u8 smth[8];
    u32 f14;
    u8 f18;
    u8 f19;
    u8 pad1A[2];
    char name1[0x10];
    char name2[0x10];
    char name3[0x10];
    char name4[0x10];
    char desc1[0x30];
    char desc2[0x30];
    char name5[0x10];
    u8 config[0x20];
    u8 ext[0x150 - 0xEC];
};

extern "C" {
s32 __as__16TPlyClientConfigFRC16TPlyClientConfig(void *, void *);
s32 __as__21TPlyMeetUserExtensionFRC21TPlyMeetUserExtension(void *, void *);
void TProtocol::send_c6_packet(void *lobby) {
    if (m_connected != 0) {
        *(u8 *)((s8 *)lobby + 0) = 0xC6;
        *(s16 *)((s8 *)lobby + 2) = 0x7C;
        ((TLobby *)lobby)->bswap_c6_packet();
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
    Pkt_801DA8C4 pkt;
    memset(m_player_name, 0, 0x10);
    strncpy(m_player_name, (const char *)player_name, 0x10);
    m_udp_disabled = udp_disabled;
    ((TPlySmth *)(&pkt))->construct();
    memset(&pkt, 0, 0x150);
    pkt.cmd = 0x9E;
    pkt.flag = m_udp_disabled;
    pkt.size = 0x150;
    __as__16TPlyGuildCardTagFRC16TPlyGuildCardTag(pkt.tag, &m_guildcard_tag);
    __as__8TPlySmthFRC8TPlySmth((saddr)pkt.smth, (saddr)&m_smth);
    pkt.f14 = m_sub_version;
    pkt.f19 = m_language;
    __as__16TPlyClientConfigFRC16TPlyClientConfig(pkt.config, &m_client_config);
    strncpy(pkt.name1, m_serial_number_v1, 0x10);
    strncpy(pkt.name2, m_access_key_v1, 0x10);
    strncpy(pkt.name3, m_serial_number2, 0x10);
    strncpy(pkt.name4, m_access_key2, 0x10);
    strncpy(pkt.desc1, m_serial_number, 0x30);
    strncpy(pkt.desc2, m_access_key, 0x30);
    strncpy(pkt.name5, m_player_name, 0x10);
    ((TLobby *)(&pkt))->bswap_guild_card_meet_user();
    send((u8 *)&pkt, 0x150);
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
    Pkt_801DAA70 tmp2;
    tmp.bswap();
    if (!strcmp(lobby_server_greeting_text, tmp.copyright)) {
        m_recv_crypt.reset(tmp.server_key);
        m_send_crypt.reset(tmp.client_key);
        m_is_encrypted = true;
        ((TPlySmth *)(&tmp2))->construct();
        memset(&tmp2, 0, sizeof(tmp2));
        tmp2.cmd = 0x9E;
        tmp2.flag = m_udp_disabled;
        __as__16TPlyGuildCardTagFRC16TPlyGuildCardTag(tmp2.tag, &m_guildcard_tag);
        __as__8TPlySmthFRC8TPlySmth((saddr)tmp2.smth, (saddr)&m_smth);
        tmp2.f14 = m_sub_version;
        tmp2.f19 = m_language;
        strncpy(tmp2.name1, m_serial_number_v1, 0x10);
        strncpy(tmp2.name2, m_access_key_v1, 0x10);
        strncpy(tmp2.name3, m_serial_number2, 0x10);
        strncpy(tmp2.name4, m_access_key2, 0x10);
        strncpy(tmp2.desc1, m_serial_number, 0x30);
        strncpy(tmp2.desc2, m_access_key, 0x30);
        strncpy(tmp2.name5, m_player_name, 0x10);
        __as__16TPlyClientConfigFRC16TPlyClientConfig(tmp2.config, &m_client_config);
        if (m_has_meet_user_settings != 0) {
            tmp2.f18 = 1;
            __as__21TPlyMeetUserExtensionFRC21TPlyMeetUserExtension(tmp2.ext, &meet_user_settings);
            tmp2.size = 0x150;
            ((TLobby *)(&tmp2))->bswap_guild_card_meet_user();
            send((u8 *)&tmp2, 0x150);
        } else {
            tmp2.size = 0xEC;
            ((TLobby *)(&tmp2))->bswap_guild_card_meet_user();
            send((u8 *)&tmp2, 0xEC);
        }
    } else {
        close();
    }
    m_has_meet_user_settings = 0;
}

}
