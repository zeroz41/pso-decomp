#ifndef PSO_NETWORK_SOCKET_EVENTS_H
#define PSO_NETWORK_SOCKET_EVENTS_H

#include "types.h"

#ifdef __cplusplus
extern "C" {
#endif
void NetDispatchSocketEvent(s16 handle, s32 callback, s32 protocol, s16 event);
#ifdef __cplusplus
}
#endif

#endif
