#include "types.h"
#include <string.h>
#include "pso/player/TPlySmth.h"
#include "pso/network/TRecvPsoRegistConnect.h"
#include "pso/network/TPlyMeetUserExtension_801DAC6C.h"
#include "pso/unk/text_801DF280.h"
#include "pso/network/protocol/protocol.h"
#include "pso/network/PSOV3EncryptionTCP.h"
#include "pso/network/TSocket.h"
#include "pso/network/TProtocol.h"

struct Tags_801DAC6C { u32 w[16]; };

struct Nm_801DAC6C { char c[16]; };

struct Ext_801DAC6C { Tags_801DAC6C tags; u32 m; Nm_801DAC6C a; Nm_801DAC6C b; };

struct Regist_801DAD38 {
    u32 hdr;
    char copyright[0x40];
    u32 key0;
    u32 key1;
};

struct Pkt_801DAD38 {
    u8 cmd;
    u8 flag;
    u16 size;
    char a[16];
    char b[16];
    char c[16];
    char d[16];
    u8 smth[8];
    u32 port;
    char e[0x30];
    char f[0x30];
    char g[0x30];
};

struct BaseDAD38 { char pad[0x18]; };

struct VObjDAD38 : BaseDAD38 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual void m8(void *, s32);
};

extern "C" {
Ext_801DAC6C *__as__21TPlyMeetUserExtensionFRC21TPlyMeetUserExtension(Ext_801DAC6C *arg0, const Ext_801DAC6C *arg1);
extern char *port_map_copyright;
void handle_cmd_9B__9TProtocolFR6packet(u8 *arg0, Regist_801DAD38 *arg1);
s32 set_port__7TSocketFUl(void *, s16);

struct BaseDA { char pad[0x18]; };
struct VObjDA : BaseDA {
    virtual s32 m0();
    virtual s32 m1();
    virtual s32 m2();
    virtual s32 m3();
    virtual s32 m4();
    virtual s32 m5();
    virtual s32 m6();
};

#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
Ext_801DAC6C *__as__21TPlyMeetUserExtensionFRC21TPlyMeetUserExtension(Ext_801DAC6C *ext, const Ext_801DAC6C *arg1) {
    ext->tags = arg1->tags;
    ext->m = arg1->m;
    ext->a = arg1->a;
    ext->b = arg1->b;
    return ext;
}

void handle_cmd_9A__9TProtocolFR6packet(u8 *arg0, s32 *arg1) {
    s32 sp8;
    s32 (*temp_r12)(u8);
    sp8 = *(s32 *)((s8 *)arg1 + 0);
    ((packet_header *)(&sp8))->bswap();
    *(s32 *)((s8 *)arg0 + 0x190C) = (s32) *(u8 *)((s8 *)&sp8 + 0x1);
    temp_r12 = *(s32 (**)(u8))((s8 *)arg0 + 0xBC28);
    if (temp_r12 != NULL) {
        temp_r12(*(u8 *)((s8 *)&sp8 + 0x1));
    }
}

void handle_cmd_9B__9TProtocolFR6packet(u8 *arg0, Regist_801DAD38 *arg1) {
    Regist_801DAD38 r = *arg1;
    Pkt_801DAD38 pkt;
    bswap__21TRecvPsoRegistConnectFv((saddr)&r);
    if (strcmp(port_map_copyright, r.copyright) == 0) {
        ((PSOV3EncryptionTCP *)(arg0 + 0x10BC))->reset(r.key0);
        ((PSOV3EncryptionTCP *)(arg0 + 0x884))->reset(r.key1);
        *(s32 *)(arg0 + 0x18F4) = 1;
        construct_cmd_db_regist_connect_reply((saddr)&pkt);
        memset((void *)&pkt, 0, 0xE0);
        pkt.cmd = 0xDB;
        pkt.size = 0xE0;
        strncpy(pkt.a, (const char *)(arg0 + 0x3EB8), 0x10);
        strncpy(pkt.b, (const char *)(arg0 + 0x3EC9), 0x10);
        strncpy(pkt.c, (const char *)(arg0 + 0x3F8A), 0x10);
        strncpy(pkt.d, (const char *)(arg0 + 0x3F9B), 0x10);
        __as__8TPlySmthFRC8TPlySmth((saddr)pkt.smth, (saddr)(arg0 + 0x18F8));
        pkt.port = *(u16 *)(arg0 + 0x1908);
        strncpy(pkt.e, (const char *)(arg0 + 0x3EDA), 0x30);
        strncpy(pkt.f, (const char *)(arg0 + 0x3F0A), 0x30);
        strncpy(pkt.g, (const char *)(arg0 + 0x3F3A), 0x30);
        bswap_cmd_db_regist_connect_reply((packet_header *)&pkt);
        ((VObjDAD38 *)arg0)->m8(&pkt, 0xE0);
    } else {
        ((VObjDAD38 *)arg0)->m5();
    }
}

s32 socket_set_server_info(TProtocol *protocol, const char *serial_v1, const char *access_key_v1, const char *serial,
                           const char *access_key, const char *host, u16 port) {
    s32 error;

    error = protocol->resolve_domain((char *)host);
    set_port__7TSocketFUl(protocol, port);
    if (error != 0) {
        return 2;
    }
    memset(protocol->m_serial_number_v1, 0, 0x11);
    memset(protocol->m_access_key_v1, 0, 0x11);
    memset(protocol->m_serial_number2, 0, 0x11);
    memset(protocol->m_access_key2, 0, 0x11);
    strncpy(protocol->m_serial_number_v1, serial_v1, 8);
    strncpy(protocol->m_access_key_v1, access_key_v1, 0xC);
    strncpy(protocol->m_serial_number2, serial, 8);
    strncpy(protocol->m_access_key2, access_key, 0xC);
    if (protocol->open() < 0) {
        return 1;
    }
    protocol->recv();
    return 0;
}

}
