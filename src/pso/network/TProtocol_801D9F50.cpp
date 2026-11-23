// ---- pso/network/TProtocol_801D9F50
#include "types.h"
#include <string.h>
#include "pso/network/TProtocol.h"

void TProtocol::handle_cmd_AB(packet &pkt) {
    void *protocol = &pkt;
    s32 (*temp_r12)(u16);

    ((TProtocol *)protocol)->bswap_cmd_AB();
    temp_r12 = *(s32 (**)(u16))((s8 *)this + 0xBC94);
    if (temp_r12 != NULL) {
        temp_r12(((TProtocol *)protocol)->m_flags);
    }
}

// ---- pso/unk/text_801D9FA0

struct VBase_18_801D9FA0 { char pad[0x18]; };

struct VObj_18_801D9FA0 : VBase_18_801D9FA0 {
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

struct Pkt_801D9FA0 {
    u8 cmd;
    u8 flag;
    u16 size;
    s16 a;
    s16 b;
    s16 c;
    s16 d;
    u32 data[8];
};

extern "C" {
void send_statistic_aa(VObj_18_801D9FA0 *obj, s16 a, s16 c, s16 d, u32 *src);
void send_statistic_aa(VObj_18_801D9FA0 *obj, s16 a, s16 c, s16 d, u32 *src) {
    Pkt_801D9FA0 pkt;
    s32 i;
    memset(&pkt, 0, 0x2C);
    pkt.cmd = 0xAA;
    pkt.flag = 0;
    pkt.size = 0x2C;
    pkt.a = a;
    pkt.b = 0;
    pkt.c = c;
    pkt.d = d;
    for (i = 0; i < 8; i++) {
        pkt.data[i] = src[i];
    }
    ((TProtocol *)(&pkt))->bswap_packet();
    obj->m8(&pkt, 0x2C);
}

}

// ---- pso/network/TProtocol_801DA054

#include "pso/network/protocol/protocol.h"
#include "pso/network/TProtocol_801E08CC.h"

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
