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
