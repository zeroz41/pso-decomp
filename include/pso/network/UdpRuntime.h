#ifndef PSO_NETWORK_UDP_RUNTIME_H
#define PSO_NETWORK_UDP_RUNTIME_H

#include "types.h"
#include "pso/network/SocketEvents.h"

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

/* One piece of the data to send (tcp_send, TUdpSocket__sub_80421BAC). */
typedef struct send_buffs {
    short len;
    u8 *buff; /* 0x04 */
} send_buffs;
typedef char send_buffs_size_check[(sizeof(send_buffs) == 8) ? 1 : -1];

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
typedef char UdpDatagram_size_check[(sizeof(UdpDatagram) == 0x34) ? 1 : -1];

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
s16 NetUdpCreate(void);
s16 NetUdpBind(s16 handle, NetworkAddress* localAddress, s32 port);
u16 NetUdpAllocateEphemeralPort(void);
s16 NetValidateLocalAddress(NetworkAddress* address);
s32 reset_stack_module(void);
s32 init_ucb_entries(void);
void expire_timeout_entries(void* tcb);
#ifdef __cplusplus
}
#endif

#endif
