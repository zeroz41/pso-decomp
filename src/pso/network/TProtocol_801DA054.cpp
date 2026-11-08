#include "types.h"
#include "pso/network/TProtocol_801DA054.h"
#include "pso/network/protocol/protocol.h"

struct VBase_18 { char pad[0x18]; };

struct VObj_18 : VBase_18 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual s32 m8(s8 *, s32);
};

struct Cfg_801DA054 { u32 w[8]; };

struct Pkt_801DA054 { u8 cmd; u8 flag; u16 size; struct Cfg_801DA054 cfg; };

extern "C" {
s32 bswap_packet_header__9TProtocolFv(void *);
s32 __as__16TPlyClientConfigFRC16TPlyClientConfig(void *, void *);
s32 memset(void *, int, int);
int set_lobby_count_value(void*);

void handle_cmd_9F__9TProtocolFR6packet(u8 *arg0) {
    struct Pkt_801DA054 pkt;
    memset(&pkt, 0, 0x24);
    pkt.cmd = 0x9F;
    pkt.size = 0x24;
    __as__16TPlyClientConfigFRC16TPlyClientConfig(&pkt.cfg, arg0 + 0x3FAC);
    bswap_packet_header__9TProtocolFv(&pkt);
    ((VObj_18 *)(arg0))->m8((s8 *)&pkt, 0x24);
}

void handle_cmd_DA__9TProtocolFR6packet(u8 *arg0, s32 *arg1) {
    s32 sp8;
    s32 (*temp_r12)(u8);
    sp8 = *(s32 *)((s8 *)arg1 + 0);
    ((packet_header *)(&sp8))->bswap();
    temp_r12 = *(s32 (**)(u8))((s8 *)arg0 + 0xBC90);
    if (temp_r12 != NULL) {
        temp_r12(*(u8 *)((s8 *)&sp8 + 0x1));
    }
}

int handle_cmd_D7__9TProtocolFR6packet(void* p) { return set_lobby_count_value(p); }

}
