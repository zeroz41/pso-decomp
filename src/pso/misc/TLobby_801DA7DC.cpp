#include "types.h"
#include "pso/player/TPlySmth.h"
#include "pso/misc/TRecvPsoRegistConnect.h"
#include "pso/misc/TLobby_801DA7DC.h"
#include "pso/misc/TLobby_801DEFC4.h"
#include "pso/misc/TPlyGuildCardTag_8007B434.h"
#include "pso/misc/TLobby.h"
#include "pso/protocol.h"

struct Base_801DA7DC { char pad[0x18]; };
struct VObj_801DA7DC : Base_801DA7DC {
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

struct Pkt_801DA848 { u8 hdr[4]; u8 body[0xD50]; };

struct Base_801DA8C4 { char pad[0x18]; };

struct VObj_801DA8C4 : Base_801DA8C4 {
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
s32 strncpy(void *, void *, int);
s32 memset(void *, int, int);
s32 reset__18PSOV3EncryptionTCPFUl(void *, u32);
s32 __as__21TPlyMeetUserExtensionFRC21TPlyMeetUserExtension(void *, void *);
s32 strcmp(const char *, const char *);
extern u8 meet_user_settings[];
extern char *lobby_server_greeting_text;
void handle_cmd_02__9TProtocolFR6packet(u8 *arg0, Recv_801DAA70 *arg1);
void TLobby::send_c6_packet(void *lobby) {
    if ((s32) *(s32 *)((s8 *)this + 0x1910) != 0) {
        *(u8 *)((s8 *)lobby + 0) = 0xC6;
        *(s16 *)((s8 *)lobby + 2) = 0x7C;
        ((TLobby *)lobby)->bswap_c6_packet();
        ((VObj_801DA7DC *)this)->m_call(lobby, 0x7C);
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

s32 send_login_9e_extended__6TLobbyFPvPvi(u8 *arg0, u8 *arg1, s32 arg2) {
    Pkt_801DA8C4 pkt;
    memset(arg0 + 0x3F7A, 0, 0x10);
    strncpy(arg0 + 0x3F7A, arg1, 0x10);
    *(s32 *)(arg0 + 0x1930) = arg2;
    ((TPlySmth *)(&pkt))->construct();
    memset(&pkt, 0, 0x150);
    pkt.cmd = 0x9E;
    pkt.flag = *(s32 *)(arg0 + 0x1930);
    pkt.size = 0x150;
    __as__16TPlyGuildCardTagFRC16TPlyGuildCardTag(pkt.tag, arg0 + 0x1900);
    __as__8TPlySmthFRC8TPlySmth((s32)pkt.smth, (s32)(arg0 + 0x18F8));
    pkt.f14 = *(u16 *)(arg0 + 0x1908);
    pkt.f19 = *(s32 *)(arg0 + 0x1934);
    __as__16TPlyClientConfigFRC16TPlyClientConfig(pkt.config, arg0 + 0x3FAC);
    strncpy(pkt.name1, arg0 + 0x3EB8, 0x10);
    strncpy(pkt.name2, arg0 + 0x3EC9, 0x10);
    strncpy(pkt.name3, arg0 + 0x3F8A, 0x10);
    strncpy(pkt.name4, arg0 + 0x3F9B, 0x10);
    strncpy(pkt.desc1, arg0 + 0x3EDA, 0x30);
    strncpy(pkt.desc2, arg0 + 0x3F0A, 0x30);
    strncpy(pkt.name5, arg0 + 0x3F7A, 0x10);
    ((TLobby *)(&pkt))->bswap_guild_card_meet_user();
    ((VObj_801DA8C4 *)arg0)->m_call(&pkt, 0x150);
    return 0;
}

void handle_cmd_9C__9TProtocolFR6packet(u8 *arg0, s32 *arg1) {
    s32 sp8;
    s32 (*temp_r12)(u8);
    sp8 = *(s32 *)((s8 *)arg1 + 0);
    ((packet_header *)(&sp8))->bswap();
    *(s32 *)((s8 *)arg0 + 0x190C) = (s32) *(u8 *)((s8 *)&sp8 + 0x1);
    temp_r12 = *(s32 (**)(u8))((s8 *)arg0 + 0xBC2C);
    if (temp_r12 != NULL) {
        temp_r12(*(u8 *)((s8 *)&sp8 + 0x1));
    }
}
void handle_cmd_02__9TProtocolFR6packet(u8 *arg0, Recv_801DAA70 *arg1) {
    Recv_801DAA70 r = *arg1;
    Pkt_801DAA70 pkt;
    bswap__21TRecvPsoRegistConnectFv((s32)&r);
    if (strcmp(lobby_server_greeting_text, r.name) == 0) {
        reset__18PSOV3EncryptionTCPFUl(arg0 + 0x10BC, r.key1);
        reset__18PSOV3EncryptionTCPFUl(arg0 + 0x884, r.key2);
        *(s32 *)(arg0 + 0x18F4) = 1;
        ((TPlySmth *)(&pkt))->construct();
        memset(&pkt, 0, 0x150);
        pkt.cmd = 0x9E;
        pkt.flag = *(s32 *)(arg0 + 0x1930);
        __as__16TPlyGuildCardTagFRC16TPlyGuildCardTag(pkt.tag, arg0 + 0x1900);
        __as__8TPlySmthFRC8TPlySmth((s32)pkt.smth, (s32)(arg0 + 0x18F8));
        pkt.f14 = *(u16 *)(arg0 + 0x1908);
        pkt.f19 = *(s32 *)(arg0 + 0x1934);
        strncpy(pkt.name1, arg0 + 0x3EB8, 0x10);
        strncpy(pkt.name2, arg0 + 0x3EC9, 0x10);
        strncpy(pkt.name3, arg0 + 0x3F8A, 0x10);
        strncpy(pkt.name4, arg0 + 0x3F9B, 0x10);
        strncpy(pkt.desc1, arg0 + 0x3EDA, 0x30);
        strncpy(pkt.desc2, arg0 + 0x3F0A, 0x30);
        strncpy(pkt.name5, arg0 + 0x3F7A, 0x10);
        __as__16TPlyClientConfigFRC16TPlyClientConfig(pkt.config, arg0 + 0x3FAC);
        if (*(s32 *)(arg0 + 0x1918) != 0) {
            pkt.f18 = 1;
            __as__21TPlyMeetUserExtensionFRC21TPlyMeetUserExtension(pkt.ext, meet_user_settings);
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
