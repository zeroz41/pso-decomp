#include "types.h"
#include <string.h>
#include "pso/player/TPlySmth.h"
#include "pso/network/TRecvPsoRegistConnect.h"
#include "pso/unk/TLobby_801DEFC4.h"
#include "pso/player/TPlyGuildCardTag_8007B434.h"
#include "pso/unk/TLobby.h"
#include "pso/network/TProtocol.h"
#include "pso/network/protocol/protocol.h"
#include "pso/network/PSOV3EncryptionTCP.h"

struct Pkt_801DA848 { u8 hdr[4]; u8 body[0xD50]; };

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

struct Base_801DAA70 { char pad[0x18]; };

struct VObj_801DAA70 : Base_801DAA70 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual s32 m_call(void *a1, s32 a2);
};

struct Recv_801DAA70 {
    u32 hdr;
    char name[0x40];
    u32 key1;
    u32 key2;
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
void handle_cmd_C5__9TProtocolFR6packet(u8 *arg0, Pkt_801DA848 *arg1);
s32 __as__16TPlyClientConfigFRC16TPlyClientConfig(void *, void *);
s32 __as__21TPlyMeetUserExtensionFRC21TPlyMeetUserExtension(void *, void *);
extern char *lobby_server_greeting_text;
void handle_cmd_02__9TProtocolFR6packet(u8 *arg0, Recv_801DAA70 *arg1);
void TProtocol::send_c6_packet(void *lobby) {
    if (m_connected != 0) {
        *(u8 *)((s8 *)lobby + 0) = 0xC6;
        *(s16 *)((s8 *)lobby + 2) = 0x7C;
        ((TLobby *)lobby)->bswap_c6_packet();
        send((u8 *)lobby, 0x7C);
    }
}

typedef void (*Fn_801DA848)(void *, u8);
void handle_cmd_C5__9TProtocolFR6packet(u8 *arg0, Pkt_801DA848 *arg1) {
    Pkt_801DA848 tmp = *arg1;
    bswap_cmd_c5(&tmp);
    Fn_801DA848 f = *(Fn_801DA848 *)(arg0 + 0xBC8C);
    if (f != NULL) {
        f(tmp.body, tmp.hdr[1]);
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
void handle_cmd_02__9TProtocolFR6packet(u8 *arg0, Recv_801DAA70 *arg1) {
    Recv_801DAA70 r = *arg1;
    Pkt_801DAA70 pkt;
    bswap__21TRecvPsoRegistConnectFv((saddr)&r);
    if (strcmp(lobby_server_greeting_text, r.name) == 0) {
        ((PSOV3EncryptionTCP *)(arg0 + 0x10BC))->reset(r.key1);
        ((PSOV3EncryptionTCP *)(arg0 + 0x884))->reset(r.key2);
        *(s32 *)(arg0 + 0x18F4) = 1;
        ((TPlySmth *)(&pkt))->construct();
        memset(&pkt, 0, 0x150);
        pkt.cmd = 0x9E;
        pkt.flag = *(s32 *)(arg0 + 0x1930);
        __as__16TPlyGuildCardTagFRC16TPlyGuildCardTag(pkt.tag, arg0 + 0x1900);
        __as__8TPlySmthFRC8TPlySmth((saddr)pkt.smth, (saddr)(arg0 + 0x18F8));
        pkt.f14 = *(u16 *)(arg0 + 0x1908);
        pkt.f19 = *(s32 *)(arg0 + 0x1934);
        strncpy(pkt.name1, (const char *)(arg0 + 0x3EB8), 0x10);
        strncpy(pkt.name2, (const char *)(arg0 + 0x3EC9), 0x10);
        strncpy(pkt.name3, (const char *)(arg0 + 0x3F8A), 0x10);
        strncpy(pkt.name4, (const char *)(arg0 + 0x3F9B), 0x10);
        strncpy(pkt.desc1, (const char *)(arg0 + 0x3EDA), 0x30);
        strncpy(pkt.desc2, (const char *)(arg0 + 0x3F0A), 0x30);
        strncpy(pkt.name5, (const char *)(arg0 + 0x3F7A), 0x10);
        __as__16TPlyClientConfigFRC16TPlyClientConfig(pkt.config, arg0 + 0x3FAC);
        if (*(s32 *)(arg0 + 0x1918) != 0) {
            pkt.f18 = 1;
            __as__21TPlyMeetUserExtensionFRC21TPlyMeetUserExtension(pkt.ext, &meet_user_settings);
            pkt.size = 0x150;
            ((TLobby *)(&pkt))->bswap_guild_card_meet_user();
            ((VObj_801DAA70 *)arg0)->m_call(&pkt, 0x150);
        } else {
            pkt.size = 0xEC;
            ((TLobby *)(&pkt))->bswap_guild_card_meet_user();
            ((VObj_801DAA70 *)arg0)->m_call(&pkt, 0xEC);
        }
    } else {
        ((VObj_801DAA70 *)arg0)->m5();
    }
    *(s32 *)(arg0 + 0x1918) = 0;
}

}
