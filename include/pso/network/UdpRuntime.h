#ifndef PSO_NETWORK_UDP_RUNTIME_H
#define PSO_NETWORK_UDP_RUNTIME_H

#include "types.h"
#include <stddef.h>
#include "pso/network/SocketEvents.h"
#include "pso/network/IPv6Send.h"
#include "pso/network/NetworkReceiveCallback.h"

typedef struct NetworkAddress {
    u32 family;
    union {
        u8 address[16];
        u32 ipv4;
    };
} NetworkAddress;

/* A UDP header (RFC 768). */
typedef struct UdpHeader {
    u16 src_port;
    u16 dst_port;
    u16 length;
    u16 checksum;
} UdpHeader;
LAYOUT_ASSERT(UdpHeader_size_check, sizeof(UdpHeader) == 8);

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
    NetworkReceiveCallback receiveCallback;
    NetSocketEventCallback eventCallback;
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

/* A received datagram, as udp_deliver hands it to the socket's receive callback: first with mode 0 (the
   callback sets buf, or returns nonzero to drop it), then with mode 1 once len bytes are copied to buf. */
typedef struct UdpDatagram {
    NetworkReceivePrefix receive;
    NetworkAddress src;     /* 0x08 */
    NetworkAddress dst;     /* 0x1C */
    u16 port;               /* 0x30: source port */
} UdpDatagram;
LAYOUT_ASSERT(UdpDatagram_size_check, sizeof(UdpDatagram) == 0x34);

LAYOUT_ASSERT(UdpDatagram_receive_check, offsetof(UdpDatagram, receive) == 0);
LAYOUT_ASSERT(UdpDatagram_src_check, offsetof(UdpDatagram, src) == 0x08);
LAYOUT_ASSERT(UdpDatagram_dst_check, offsetof(UdpDatagram, dst) == 0x1C);
LAYOUT_ASSERT(UdpDatagram_port_check, offsetof(UdpDatagram, port) == 0x30);

typedef NetworkReceiveCallback NetUdpReceiveCallback;

typedef struct UdpRuntimeState {
    s16 count;
    u16 ephemeralPort;
    u16 ephemeralPortEnd;
    u16 ephemeralPortStart;
    UdpControlBlock* entries;
    u8 pad_C[4];
} UdpRuntimeState;
LAYOUT_ASSERT(UdpRuntimeState_entries_offset, offsetof(UdpRuntimeState, entries) == 8);

/* SocketProtocolRuntime.c: UDP control blocks and the TCP receive-queue/SACK helpers. */
#ifdef __cplusplus
extern "C" {
#endif
extern UdpRuntimeState udp_runtime_state;
struct NetPacket;
s16 udp_input(struct NetPacket *pkt, NetworkAddress *src, NetworkAddress *dst, s16 iface);
s16 udp_deliver(struct NetPacket *pkt, NetworkAddress *src, NetworkAddress *dst,
                           u16 port, NetUdpReceiveCallback cb, s16 socket_index);
s32 NetUdpClose(s16 handle);
s16 NetUdpConnect(s16 handle, NetworkAddress* remoteAddress, s32 port,
                  NetSocketEventCallback eventCallback, NetUdpReceiveCallback receiveCallback);
s16 udp_open(void *src, s32 sport, void *dst, s32 dport, NetSocketEventCallback eventCallback,
             NetUdpReceiveCallback callback);
s16 udp_send(s32 handle, NetworkAddress *src, NetworkAddress *dst, u16 port, UdpSendOptions *options, s8 count,
             send_buffs *buffers);
s32 udp_ctlinput(u16 src_port, u8 code);
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
