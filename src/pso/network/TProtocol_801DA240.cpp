#include <stdio.h>
#include "pso/network/TProtocol.h"
#include "pso/unk/TLobby.h"
#include <stddef.h>
LAYOUT_ASSERT(TradeResultCallbackOffset, offsetof(TProtocol, m_recv_handlers) + offsetof(recv_packet_handlers, handle_D4_trade_result_packet) == 0xBC9C);
LAYOUT_ASSERT(TradeAdvanceCallbackOffset, offsetof(TProtocol, m_recv_handlers) + offsetof(recv_packet_handlers, handle_D1_advance_trade_state_packet) == 0xBCA0);
LAYOUT_ASSERT(TradeHeaderSize, sizeof(packet_header) == 4);
LAYOUT_ASSERT(TradeStateOffset, offsetof(packet_header, flags) == 1);

/* TProtocol's globals. Its code is split over several files; this is the first whose data sits where these do (the
 * strings ahead of its trade-list log formats in .rodata). */
packet *server_packet;
u32 new_ip_addr;
u16 new_port;
s32 lobby_state_flags;
const char *lobby_server_greeting_text = "DreamCast Lobby Server. Copyright SEGA Enterprises. 1999";
const char *port_map_copyright = "DreamCast Port Map. Copyright SEGA Enterprises. 1999";
OBJECT_NAME(TProtocol);


#include "types.h"
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
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


#include <string.h>
extern "C" {
void send_trade_list__6TLobbyFPvPv(VObj_18_801DA4A0 *obj, TTradeList *src);

void TProtocol::handle_cmd_D5(packet &pkt) {
    TPlyText<0x1000> tmp = as(TPlyText<0x1000> &, pkt);
    if (m_recv_handlers.handle_1A_D5_recv_text != NULL) {
        m_recv_handlers.handle_1A_D5_recv_text(tmp.text);
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

extern "C" {

void send_trade_list__6TLobbyFPvPv(VObj_18_801DA4A0 *obj, TTradeList *src) {
    char message[0x80];
    sprintf(message, "SndTradeList %d %d", src->item_count, src->target_client_id);
    TTradeList pkt = *src;
    pkt.header.command = 0xD0;
    pkt.header.flags = 0;
    pkt.header.size = sizeof(pkt);
    pkt.bswap();
    obj->m8(&pkt, sizeof(pkt));
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
