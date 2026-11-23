#ifndef PSO_NETWORK_NETWORK_DISPATCH_H
#define PSO_NETWORK_NETWORK_DISPATCH_H

#include "types.h"
#include "pso/network/NetworkRuntime.h"
#include "pso/network/NetworkTimer.h"
#include <stddef.h>

/* A protocol handler: NetRunProtocolDispatchLoop passes it a message's payload, detail, first and second fields. */
typedef void (*NetProtocolHandler)(s32, s16, s16, s16);

typedef struct NetProtocolHandlerEntry {
    s16 used;
    u16 type;
    NetProtocolHandler fn;
} NetProtocolHandlerEntry;

typedef struct NetTimerRecord {
    s16 active;
    s16 lock_callback;
    s32 period;
    u32 last;
    u32 next;
    NetTimerCallback fn;
} NetTimerRecord;

typedef struct NetworkDispatchState {
    s32 lock_handle;
    s32 queue_handle;
    NetThreadHandle thread_ids[2]; /* protocol and timer dispatch threads */
    s32 interval;
    NetProtocolHandlerEntry handlers[3];
    NetTimerRecord timers[10];
    u8 unknown_F4[4];
} NetworkDispatchState;
#ifdef __cplusplus
extern "C" {
#endif
extern NetworkDispatchState network_dispatch_state;
s32 register_protocol_handler(u16 type, NetProtocolHandler fn);
s32 release_slot_by_id(u16 a);
void TLobby__sub_80419A00(void);
s16 TLobby__sub_80419A34(void);
s16 NetInitializeDispatcher(void);
void NetYieldOutsideDispatcherThread(void);
void NetRunProtocolDispatchLoop(void);
void NetRunTimerDispatchLoop(void);
void NetEnqueueProtocolMessage(s32 payload, s16 detail, s16 first, s16 second, u16 protocol);
s32 dispatch_handler_by_id(s16 first, s32 second, s32 payload);
s32 TLobby__sub_80419A7C(void);
#ifdef __cplusplus
}
#endif

typedef struct NetProtocolMessage {
    s16 first;
    s16 second;
    u16 protocol;
    s16 detail;
    s32 payload;
} NetProtocolMessage;

#define NET_DISPATCH_OFFSET(type, member, value) \
    LAYOUT_ASSERT(type##_##member##_offset, offsetof(type, member) == value)
NET_DISPATCH_OFFSET(NetProtocolHandlerEntry, used, 0x00);
NET_DISPATCH_OFFSET(NetProtocolHandlerEntry, type, 0x02);
NET_DISPATCH_OFFSET(NetProtocolHandlerEntry, fn, 0x04);
NET_DISPATCH_OFFSET(NetTimerRecord, active, 0x00);
NET_DISPATCH_OFFSET(NetTimerRecord, lock_callback, 0x02);
NET_DISPATCH_OFFSET(NetTimerRecord, period, 0x04);
NET_DISPATCH_OFFSET(NetTimerRecord, last, 0x08);
NET_DISPATCH_OFFSET(NetTimerRecord, next, 0x0C);
NET_DISPATCH_OFFSET(NetTimerRecord, fn, 0x10);
NET_DISPATCH_OFFSET(NetworkDispatchState, lock_handle, 0x00);
NET_DISPATCH_OFFSET(NetworkDispatchState, queue_handle, 0x04);
NET_DISPATCH_OFFSET(NetworkDispatchState, thread_ids, 0x08);
NET_DISPATCH_OFFSET(NetworkDispatchState, interval, 0x10);
NET_DISPATCH_OFFSET(NetworkDispatchState, handlers, 0x14);
NET_DISPATCH_OFFSET(NetworkDispatchState, timers, 0x2C);
NET_DISPATCH_OFFSET(NetworkDispatchState, unknown_F4, 0xF4);
NET_DISPATCH_OFFSET(NetProtocolMessage, first, 0x00);
NET_DISPATCH_OFFSET(NetProtocolMessage, second, 0x02);
NET_DISPATCH_OFFSET(NetProtocolMessage, protocol, 0x04);
NET_DISPATCH_OFFSET(NetProtocolMessage, detail, 0x06);
NET_DISPATCH_OFFSET(NetProtocolMessage, payload, 0x08);
#undef NET_DISPATCH_OFFSET

LAYOUT_ASSERT(NetProtocolHandlerEntry_size, sizeof(NetProtocolHandlerEntry) == 8);
LAYOUT_ASSERT(NetTimerRecord_size, sizeof(NetTimerRecord) == 0x14);
LAYOUT_ASSERT(NetworkDispatchState_size, sizeof(NetworkDispatchState) == 0xF8);
LAYOUT_ASSERT(NetProtocolMessage_size, sizeof(NetProtocolMessage) == 0x0C);

#endif
