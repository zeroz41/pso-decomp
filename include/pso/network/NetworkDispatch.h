#ifndef PSO_NETWORK_NETWORK_DISPATCH_H
#define PSO_NETWORK_NETWORK_DISPATCH_H

#include "types.h"
#include <stddef.h>

typedef void (*NetTimerCallback)(void);

#ifdef __cplusplus
extern "C" {
#endif
s32 NetRegisterTimer(s32 period, s16 locked, NetTimerCallback fn);
#ifdef __cplusplus
}
#endif

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
    u32 thread_ids[2]; /* protocol and timer dispatch threads */
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
    typedef char type##_##member##_offset[(offsetof(type, member) == value) ? 1 : -1]
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
NET_DISPATCH_OFFSET(NetworkDispatchState, interval, 0x10);
NET_DISPATCH_OFFSET(NetworkDispatchState, handlers, 0x14);
NET_DISPATCH_OFFSET(NetworkDispatchState, timers, 0x2C);
NET_DISPATCH_OFFSET(NetProtocolMessage, first, 0x00);
NET_DISPATCH_OFFSET(NetProtocolMessage, second, 0x02);
NET_DISPATCH_OFFSET(NetProtocolMessage, protocol, 0x04);
NET_DISPATCH_OFFSET(NetProtocolMessage, detail, 0x06);
NET_DISPATCH_OFFSET(NetProtocolMessage, payload, 0x08);
#undef NET_DISPATCH_OFFSET

typedef char NetProtocolHandlerEntry_size[(sizeof(NetProtocolHandlerEntry) == 8) ? 1 : -1];
typedef char NetTimerRecord_size[(sizeof(NetTimerRecord) == 0x14) ? 1 : -1];
typedef char NetworkDispatchState_size[(sizeof(NetworkDispatchState) == 0xF8) ? 1 : -1];
typedef char NetProtocolMessage_size[(sizeof(NetProtocolMessage) == 0x0C) ? 1 : -1];

#endif
