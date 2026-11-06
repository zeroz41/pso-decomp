#include "pso/network/TProtocol.h"
#include "pso/misc/TLobby_801DEFC4.h"
#include "pso/misc/TLobby.h"
#include <stddef.h>
typedef char TradeResultCallbackOffset[(offsetof(TProtocol, m_recv_handlers) + offsetof(recv_packet_handlers, handle_D4_trade_result_packet) == 0xBC9C) ? 1 : -1];
typedef char TradeAdvanceCallbackOffset[(offsetof(TProtocol, m_recv_handlers) + offsetof(recv_packet_handlers, handle_D1_advance_trade_state_packet) == 0xBCA0) ? 1 : -1];
typedef char TradeHeaderSize[sizeof(packet_header) == 4 ? 1 : -1];
typedef char TradeStateOffset[offsetof(packet_header, flags) == 1 ? 1 : -1];

struct Text_801DA240 { u32 hdr; char text[0x1000]; };
struct Pkt_801DA5E4 { u32 hdr; u8 body[0x8D0]; };

#include "types.h"
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
struct Pkt_801DA35C {
    u8 bytes[0x288];
};

struct PktHdr_801DA35C {
    u8 cmd;
    u8 flag;
    u16 size;
    u16 a;
    u16 b;
};

#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
struct VBase_18_801DA4A0 { char pad[0x18]; };

struct VObj_18_801DA4A0 : VBase_18_801DA4A0 {
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

struct Pkt_801DA4A0 {
    u8 bytes[0x288];
};

struct PktHdr_801DA4A0 {
    u8 cmd;
    u8 flag;
    u16 size;
    u16 a;
    u16 b;
};

#include <string.h>
struct VBase_18_801DA548 { char pad[0x18]; };

struct VObj_18_801DA548 : VBase_18_801DA548 {
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

struct Pkt_801DA548 {
    u8 cmd;
    u8 flag;
    u16 size;
    char text[0xac];
};

struct VBase_18_801DA734 { char pad[0x18]; };

struct VObj_18_801DA734 : VBase_18_801DA734 {
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

struct Pkt_801DA734 {
    u8 cmd;
    u8 flag;
    u16 size;
    char text[0x1fc];
};

extern "C" {
int sprintf(char *, const char *, ...);
void handle_cmd_D3__9TProtocolFR6packet(u8 *arg0, Pkt_801DA35C *src);
void send_trade_list__6TLobbyFPvPv(VObj_18_801DA4A0 *obj, Pkt_801DA4A0 *src);
typedef void (*Fn_801DA240)(char *);
typedef void (*Fn_801DA5E4)(void *);

void handle_cmd_D5__9TProtocolFR6packet(u8 *arg0, Text_801DA240 *arg1) {
    Text_801DA240 tmp = *arg1;
    Fn_801DA240 f = *(Fn_801DA240 *)(arg0 + 0xBBF8);
    if (f != NULL) {
        f(tmp.text);
    }
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

void handle_cmd_D3__9TProtocolFR6packet(u8 *arg0, Pkt_801DA35C *src) {
    char buf[0x80];
    Pkt_801DA35C pkt;
    void (*cb)(void *);
    pkt = *src;
    bswap_cmd_D3_item_bank(&pkt);
    sprintf(buf, "RcvTradeList %d %d", ((PktHdr_801DA35C *)&pkt)->b, ((PktHdr_801DA35C *)&pkt)->a);
    cb = *(void (**)(void *))(arg0 + 0xBC98);
    if (cb != NULL) {
        cb(&pkt);
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

extern "C" {

void send_trade_list__6TLobbyFPvPv(VObj_18_801DA4A0 *obj, Pkt_801DA4A0 *src) {
    char buf[0x80];
    Pkt_801DA4A0 pkt;
    sprintf(buf, "SndTradeList %d %d", ((PktHdr_801DA4A0 *)src)->b, ((PktHdr_801DA4A0 *)src)->a);
    pkt = *src;
    ((PktHdr_801DA4A0 *)&pkt)->cmd = 0xD0;
    ((PktHdr_801DA4A0 *)&pkt)->flag = 0;
    ((PktHdr_801DA4A0 *)&pkt)->size = 0x288;
    bswap_cmd_D3_item_bank(&pkt);
    obj->m8(&pkt, 0x288);
}

void TLobby::send_text_packet_D9(char *str) {
    VObj_18_801DA548 *obj = (VObj_18_801DA548 *)this;
    Pkt_801DA548 pkt;
    s32 n;
    memset(&pkt, 0, 0xB0);
    pkt.cmd = 0xD9;
    pkt.flag = 0;
    char *t = pkt.text;
    strncpy(t, str, 0xAC);
    n = (strlen(t) + 8) & ~3;
    pkt.size = n;
    TLobby__sub_801DF024(&pkt);
    obj->m8(&pkt, n);
}

void handle_cmd_D8__9TProtocolFR6packet(u8 *arg0, Pkt_801DA5E4 *arg1) {
    Pkt_801DA5E4 tmp = *arg1;
    ((TLobby *)(&tmp))->bswap_cmd_d8_header();
    Fn_801DA5E4 f = *(Fn_801DA5E4 *)(arg0 + 0xBC54);
    if (f != NULL) {
        f(&tmp);
    }
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
void TLobby::send_text_packet_c7(char *str) {
    if (*(s32 *)((char *)this + 0x1910) != 0) {
    Pkt_801DA734 pkt;
    s32 n;
    memset(&pkt, 0, 0x204);
    pkt.cmd = 0xC7;
    pkt.flag = 0;
    char *t = pkt.text;
    strncpy(t, str, 0x1FF);
    n = (strlen(t) + 8) & ~3;
    pkt.size = n;
    TLobby__sub_801DF064(&pkt);
    ((VObj_18_801DA734 *)this)->m8(&pkt, n);
    }
}
