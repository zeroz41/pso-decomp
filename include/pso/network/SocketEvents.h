#ifndef PSO_NETWORK_SOCKET_EVENTS_H
#define PSO_NETWORK_SOCKET_EVENTS_H

#include "types.h"

#ifdef __cplusplus
extern "C" {
#endif
/* A socket's event callback: NetDispatchSocketEvent calls it with the tagged socket handle and the event code. */
typedef void (*NetSocketEventCallback)(s16 handle, s16 event);
void NetDispatchSocketEvent(s16 handle, NetSocketEventCallback callback, s32 protocol, s16 event);
typedef void (*TcpAcceptCallback)(s16 accepted, s16 listener, s32 address, s32 port);
s32 TLobby__sub_80422AB8(s16 listener, TcpAcceptCallback callback, s16 accepted, s32 address, s32 local_port, s32 remote_port);
#ifdef __cplusplus
}
#endif

#endif
