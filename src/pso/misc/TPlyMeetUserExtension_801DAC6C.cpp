#include "types.h"
#include "pso/player/TPlySmth.h"
#include "pso/misc/TRecvPsoRegistConnect.h"
#include "pso/misc/TPlyMeetUserExtension_801DAC6C.h"
#include "pso/unk/text_801DF280.h"
#include "pso/protocol.h"

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
void reset__18PSOV3EncryptionTCPFUl(void *, u32);
s32 strcmp(const char *, const char *);
s32 strncpy(void *, s32, s32);
s32 memset(void *, s32, s32);
extern char *port_map_copyright;
void handle_cmd_9B__9TProtocolFR6packet(u8 *arg0, Regist_801DAD38 *arg1);
s32 set_port__7TSocketFUl(void *, s16);
s32 resolve_domain__7TSocketFPc(void *, s32);

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
Ext_801DAC6C *__as__21TPlyMeetUserExtensionFRC21TPlyMeetUserExtension(Ext_801DAC6C *arg0, const Ext_801DAC6C *arg1) {
    arg0->tags = arg1->tags;
    arg0->m = arg1->m;
    arg0->a = arg1->a;
    arg0->b = arg1->b;
    return arg0;
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
    bswap__21TRecvPsoRegistConnectFv((s32)&r);
    if (strcmp(port_map_copyright, r.copyright) == 0) {
        reset__18PSOV3EncryptionTCPFUl(arg0 + 0x10BC, r.key0);
        reset__18PSOV3EncryptionTCPFUl(arg0 + 0x884, r.key1);
        *(s32 *)(arg0 + 0x18F4) = 1;
        fn_801DF2BC((s32)&pkt);
        memset((void *)&pkt, 0, 0xE0);
        pkt.cmd = 0xDB;
        pkt.size = 0xE0;
        strncpy(pkt.a, (s32)((s32)(arg0 + 0x3EB8)), 0x10);
        strncpy(pkt.b, (s32)((s32)(arg0 + 0x3EC9)), 0x10);
        strncpy(pkt.c, (s32)((s32)(arg0 + 0x3F8A)), 0x10);
        strncpy(pkt.d, (s32)((s32)(arg0 + 0x3F9B)), 0x10);
        __as__8TPlySmthFRC8TPlySmth((s32)pkt.smth, (s32)(arg0 + 0x18F8));
        pkt.port = *(u16 *)(arg0 + 0x1908);
        strncpy(pkt.e, (s32)((s32)(arg0 + 0x3EDA)), 0x30);
        strncpy(pkt.f, (s32)((s32)(arg0 + 0x3F0A)), 0x30);
        strncpy(pkt.g, (s32)((s32)(arg0 + 0x3F3A)), 0x30);
        fn_801DF280((packet_header *)&pkt);
        ((VObjDAD38 *)arg0)->m8(&pkt, 0xE0);
    } else {
        ((VObjDAD38 *)arg0)->m5();
    }
}

s32 socket_set_server_info(u8 *socket, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6) {
    s32 temp_r31;

    temp_r31 = resolve_domain__7TSocketFPc(socket, arg5);
    set_port__7TSocketFUl(socket, arg6);
    if (temp_r31 != 0) {
        return 2;
    }
    memset(socket + 0x3EB8, 0, 0x11);
    memset(socket + 0x3EC9, 0, 0x11);
    memset(socket + 0x3F8A, 0, 0x11);
    memset(socket + 0x3F9B, 0, 0x11);
    strncpy(socket + 0x3EB8, arg1, 8);
    strncpy(socket + 0x3EC9, arg2, 0xC);
    strncpy(socket + 0x3F8A, arg3, 8);
    strncpy(socket + 0x3F9B, arg4, 0xC);
    if (((VObjDA *)socket)->m4() < 0) {
        return 1;
    }
    ((VObjDA *)socket)->m6();
    return 0;
}

}
