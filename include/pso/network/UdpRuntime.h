#ifndef PSO_NETWORK_UDP_RUNTIME_H
#define PSO_NETWORK_UDP_RUNTIME_H

#include "types.h"
#include <stddef.h>
#include "pso/network/SocketEvents.h"
#include "pso/network/IPv6Send.h"

typedef struct NetworkAddress {
    u32 family;
    union {
        u8 address[16];
        u32 ipv4;
    };
} NetworkAddress;

typedef struct UdpControlBlock {
    char signature[3];
    u8 index;
    u16 active;
    u16 sourcePort;
    u16 destinationPort;
    u16 length;
    u16 checksum;
    u16 localPort;
    u16 remotePort;
    NetworkAddress localAddress;
    NetworkAddress remoteAddress;
    u32 receiveCallback;
    s32 eventCallback;
} UdpControlBlock;

/* The IP options of one udp_send: the address family they are for, then that family's options as
   dispatch_by_addr_family hands them on (AT_IP4_Send's ttl, tos and df bytes, or the IPv6 send options). */
typedef struct UdpSendOptions {
    u32 family;
    union {
        u8 ipv4[3];
        NetIPv6SendOptions ipv6;
    };
} UdpSendOptions;
LAYOUT_ASSERT(UdpSendOptions_size_check, sizeof(UdpSendOptions) == 0x10);

/* One piece of the data to send (tcp_send, udp_send). */
typedef struct send_buffs {
    short len;
    u8 *buff; /* 0x04 */
} send_buffs;
LAYOUT_ASSERT(send_buffs_size_check, sizeof(send_buffs) == 8);

/* A received datagram, as TLobby__sub_80421F10 hands it to the socket's receive callback: first with mode 0 (the
   callback sets buf, or returns nonzero to drop it), then with mode 1 once len bytes are copied to buf. */
typedef struct UdpDatagram {
    s16 socket;             /* 0x00: the socket's handle */
    s16 len;                /* 0x02 */
    u8 *buf;                /* 0x04 */
    NetworkAddress src;     /* 0x08 */
    NetworkAddress dst;     /* 0x1C */
    u16 port;               /* 0x30: source port */
} UdpDatagram;
LAYOUT_ASSERT(UdpDatagram_size_check, sizeof(UdpDatagram) == 0x34);

LAYOUT_ASSERT(UdpDatagram_socket_check, offsetof(UdpDatagram, socket) == 0);
LAYOUT_ASSERT(UdpDatagram_length_check, offsetof(UdpDatagram, len) == 2);
LAYOUT_ASSERT(UdpDatagram_buffer_check, offsetof(UdpDatagram, buf) == 4);

typedef s32 (*NetUdpReceiveCallback)(s16 mode, UdpDatagram *datagram);

typedef struct UdpRuntimeState {
    s16 count;
    u16 ephemeralPort;
    u16 ephemeralPortEnd;
    u16 ephemeralPortStart;
    UdpControlBlock* entries;
    u32 m_c;
} UdpRuntimeState;

/* SocketProtocolRuntime.c: UDP control blocks and the TCP receive-queue/SACK helpers. */
#ifdef __cplusplus
extern "C" {
#endif
extern UdpRuntimeState udp_runtime_state;
s32 NetUdpClose(s16 handle);
s16 NetUdpConnect(s16 handle, NetworkAddress* remoteAddress, s32 port,
                  s32 eventCallback, u32 receiveCallback);
s16 udp_open(void *src, s32 sport, void *dst, s32 dport, s32 eventCallback, NetUdpReceiveCallback callback);
s16 udp_send(s32 handle, NetworkAddress *src, NetworkAddress *dst, u16 port, UdpSendOptions *options, s8 count,
             send_buffs *buffers);
s32 TLobby__sub_80420D38(u16 src_port, u8 code);
s16 NetUdpCreate(void);
s16 NetUdpBind(s16 handle, NetworkAddress* localAddress, s32 port);
u16 NetUdpAllocateEphemeralPort(void);
s16 NetValidateLocalAddress(NetworkAddress* address);
s16 compare_sockaddr(NetworkAddress *a, NetworkAddress *b);
s32 reset_stack_module(void);
s16 init_ucb_entries(void);
#ifdef __cplusplus
}
#endif

#endif
