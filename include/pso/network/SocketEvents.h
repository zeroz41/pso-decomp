#ifndef PSO_NETWORK_SOCKET_EVENTS_H
#define PSO_NETWORK_SOCKET_EVENTS_H

#include "types.h"

#ifdef __cplusplus
extern "C" {
#endif
void NetDispatchSocketEvent(s16 handle, saddr callback, s32 protocol, s16 event);
typedef void (*TcpAcceptCallback)(s16 accepted, s16 listener, s32 address, s32 port);
s32 TLobby__sub_80422AB8(s16 listener, TcpAcceptCallback callback, s16 accepted, s32 address, s32 local_port, s32 remote_port);
#ifdef __cplusplus
}
#endif

#endif
