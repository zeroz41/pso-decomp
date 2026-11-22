#include "pso/network/NetworkRuntime.h"
#include "pso/network/UdpRuntime.h"
#include "pso/network/text_80421620.h"
#include "pso/unk/TLobby_801461EC.h"
#include "pso/network/TLobby_804050DC.h"
#include "types.h"
#include "pso/system/byteswap.h"
#include <string.h>
#include "pso/macros.h"
#include "pso/system/task/TObject.h"
#include "pso/network/TSocket.h"
#include "pso/network/TTcpSocket.h"
#include "pso/network/TUdpSocket.h"
#include "pso/unk/TLobby.h"

#pragma readonly_strings on

// The socket class names: TTcpSocket's and TUdpSocket's constructors store them in m_name. Both strings open this
// file's .rodata and both pointers sit in its .sdata; the TCP socket table and the status names are in its .data
// too, ahead of the UDP vtable.
OBJECT_NAME(TTcpSocket)
OBJECT_NAME(TUdpSocket)

struct Q_80078110 { s32 len; s32 v; u8 pad[0xc]; };

struct R_80078110 { s16 a; saddr b; };

struct C_80078110 { s32 len; s8 a; s8 b; s8 c; u8 pad[8]; };

struct Q_800781B8 { s32 len; s32 v; u8 pad[0xc]; };

struct R_800781B8 { s16 a; saddr b; };

struct C_800781B8 { s32 len; s8 a; s8 b; s8 c; u8 pad[8]; };

struct Q_800782B8 { s32 len; s32 v; u8 pad[0xc]; };

struct Q2_800782B8 { s32 len; s32 v; u8 pad[0xc]; };

extern "C" {
UdpSocketEventRecord *copy_udp_socket_event_record(UdpSocketEventRecord *dst, UdpSocketEventRecord *src);
s16 udp_send(int, void *, void *, int, void *, int, void *);
}
TTcpSocket *tcp_socket_table[16] = {0};
TUdpSocket *udp_socket_slots[16] = {0};
const char *sock_status_names[17] = {
    "SUCCESS", "API_PENDING", "API_PORTFULL", "API_DUPSOCK", "API_INVALIDHANDLE",
    "API_SENDPENDING", "API_CONNRESET", "API_UNREACHABLE", "API_RECVFIN",
    "API_RECVPENDING", "API_PORTCLOSED", "API_TIMEOUT", "API_NOBUF", "API_BADOPT",
    "API_dummy1", "API_dummy2", "API_GENERAL",
};

TUdpSocket::~TUdpSocket() {
    close();
}

void TUdpSocket::recv() {
    memset(m_packet_buffer, 0, sizeof(m_packet_buffer));
    m_buffer_cleared = true;
}

short TUdpSocket::send(u8 *data, size_t size) {
    Q_80078110 q2;
    Q_80078110 q1;
    C_80078110 c;
    R_80078110 r;
    u16 port;
    q1.len = 4;
    q1.v = m_dst_addr.addr;
    TLobby__sub_8014672C((s32 *)&m_src_addr);
    q2.len = 4;
    q2.v = m_src_addr.addr;
    c.len = 4;
    c.a = 0x78;
    c.b = 0;
    c.c = 0;
    r.b = (saddr)data;
    r.a = size;
    port = m_dst_port;
    bswap_16(&port);
    return udp_send(m_sock_fd, &q2, &q1, port, &c, 1, &r);
}

short TUdpSocket::send(u8 *data) {
    Q_800781B8 q2;
    Q_800781B8 q1;
    C_800781B8 c;
    R_800781B8 r;
    u16 port;
    q1.len = 4;
    q1.v = m_dst_addr.addr;
    TLobby__sub_8014672C((s32 *)&m_src_addr);
    q2.len = 4;
    q2.v = m_src_addr.addr;
    c.len = 4;
    c.a = 0x78;
    c.b = 0;
    c.c = 0;
    r.b = (saddr)data;
    r.a = strlen((const char *)data);
    port = m_dst_port;
    bswap_16(&port);
    return udp_send(m_sock_fd, &q2, &q1, port, &c, 1, &r);
}

void TUdpSocket::close() {
    if (m_sock_fd >= 0x400) {
        udp_close(m_sock_fd);
        udp_socket_slots[m_sock_fd - 0x400] = NULL;
    }
}

int TUdpSocket::open() {
    Q_800782B8 q1;
    Q2_800782B8 q2;
    u16 pb;
    u16 pa;
    s32 i;
    q1.len = 4;
    q1.v = 0;
    q2.len = 4;
    q2.v = m_dst_addr.addr;
    for (i = 0; i < 30001; i++) {
    }
    pa = m_src_port;
    pb = m_dst_port;
    bswap_16(&pa);
    bswap_16(&pb);
    m_sock_fd = udp_open(&q1, pa, &q2, pb, 0, handle_socket_event);
    if (m_sock_fd < 0) {
        return -1;
    }
    udp_socket_slots[m_sock_fd - 0x400] = this;
    return m_sock_fd;
}

s32 TUdpSocket::handle_socket_event(s16 received, UdpDatagram *event) {
    int slot = event->socket - 0x400;
    TUdpSocket *socket = udp_socket_slots[slot];
    if (socket == NULL) {
        return 1;
    }
    if (received == 0) {
        event->buf = socket->m_packet_buffer;
        copy_udp_socket_event_record(&socket->m_event, (UdpSocketEventRecord *)event);
        event->len = 0x800;
    } else {
        socket->m_buffer_cleared = false;
        socket->m_buffer_offset = 0;
        socket->m_size = event->len;
        if (socket->m_callback != NULL) {
            socket->m_callback(socket);
        }
    }
    return 0;
}

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
extern "C" {

UdpSocketEventRecord *copy_udp_socket_event_record(UdpSocketEventRecord *dst, UdpSocketEventRecord *src) {
    dst->ab = src->ab;
    dst->c = src->c;
    dst->d = src->d;
    dst->e = src->e;
    return dst;
}

}
#pragma pop
