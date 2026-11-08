#include "pso/network/UdpRuntime.h"
#include "pso/network/SocketEvents.h"
#include "pso/network/NetworkDispatch.h"
#include "pso/network/NetworkRuntime.h"
#include "pso/network/TLobby_803FC178.h"
#include "pso/network/NetworkPacketPool.h"
#include "pso/network/netcfg.h"
#include "pso/network/BufferRef.h"
#include "pso/network/IPv6.h"

#include "types.h"
typedef struct Self_803FD85C Self_803FD85C;
typedef struct Tbl_803FD85C Tbl_803FD85C;
typedef struct Self_803FDA68 Self_803FDA68;
typedef struct Tbl_803FDA68 Tbl_803FDA68;
typedef struct V_803FE600 V_803FE600;
typedef struct O_803FE600 O_803FE600;
typedef struct E_8041A0C0 E_8041A0C0;
s32 release_slot_by_id(u16 a);

struct Self_803FD85C;
struct Tbl_803FD85C {
    u8 pad[0x14];
    void (*f14)(Self_803FD85C *, Tbl_803FD85C *);
    u8 pad18[8];
    void (*f20)(Self_803FD85C *, Tbl_803FD85C *);
};
struct Self_803FD85C {
    u8 f0; u8 f1; u8 f2; u8 f3; u8 f4; u8 f5; u8 f6; u8 f7;
    u8 pad8[8];
    u8 f10[0x1C];
    Tbl_803FD85C *tbl;
    void *f30;
};

#include <stddef.h>

#include "pso/network/IPv6Send.h"
#include "pso/network/NetStackTypes.h"
void TLobby__sub_80419A00(void);
s32 TLobby__sub_803F8E9C(void);
s32 TLobby__sub_80419A34(void);
s32 TLobby__sub_80419A7C(void);
void TLobby__sub_803F97E8(int);
void TLobby__sub_803F9344(s32, void *, s32);
void NetEnqueueProtocolMessage(s32 payload, s16 detail, s16 first, s16 second, u16 protocol);

struct Self_803FDA68;
struct Tbl_803FDA68 {
    u8 pad[0x14];
    void (*f14)(Self_803FDA68 *, Tbl_803FDA68 *);
    u8 pad18[0xC];
    void (*f24)(Self_803FDA68 *, Tbl_803FDA68 *);
    void *(*f28)(Self_803FDA68 *, Tbl_803FDA68 *);
};
struct Self_803FDA68 {
    u8 f0; u8 f1; u8 f2; u8 f3; u8 f4; u8 f5; u8 f6; u8 f7;
    s16 f8; u8 padA[6];
    u8 f10[0x1C];
    Tbl_803FDA68 *tbl;
    void *f30;
};

struct V_803FE600;
struct O_803FE600 {
    u8 b0; u8 b1; u8 b2; u8 b3; u8 b4; u8 b5; u8 b6; u8 b7;
    u8 pad8[0x2C - 8];
    V_803FE600 *p2C;
};
struct V_803FE600 {
    u8 pad[0x14];
    void (*fn)(O_803FE600 *, V_803FE600 *);
};

NetworkDispatchState network_dispatch_state;

s32 NetUnregisterTimer(void* p);

void TLobby__sub_80419A00(void) {
    NetMemset((void *) (&network_dispatch_state.lock_handle), 0, offsetof(NetworkDispatchState, unknown_F4));
    cancel_pending_alarms();
}
s32 TLobby__sub_80419A34(void) {
    NetMemset(&network_dispatch_state, 0, offsetof(NetworkDispatchState, unknown_F4));
    network_dispatch_state.interval = 0x1E;
    return TLobby__sub_803F8E9C();
}

#pragma push
#pragma opt_common_subs on
s32 TLobby__sub_80419A7C(void) {
    lock_mutex(network_dispatch_state.lock_handle);
    cancel_thread_if_running((void *)network_dispatch_state.thread_ids[1]);
    cancel_thread_if_running((void *)network_dispatch_state.thread_ids[0]);
    deactivate_entry_by_key(network_dispatch_state.thread_ids[1]);
    deactivate_entry_by_key(network_dispatch_state.thread_ids[0]);
    clear_slot_for_handle(network_dispatch_state.queue_handle);
    unlock_mutex(network_dispatch_state.lock_handle);
    NetReleaseMutex(network_dispatch_state.lock_handle);
    return 0;
}
#pragma pop

extern void NetRunProtocolDispatchLoop(void);
extern void NetRunTimerDispatchLoop(void);
extern s16 TLobby__sub_803F94F0(void *);
extern s16 TLobby__sub_803F96AC(void *);
extern s16 TLobby__sub_803F9B94(void *, void *);
extern s32 NetInitializeDispatcher(void) {
    s32 *p4 = &network_dispatch_state.queue_handle;
    s32 *p8;
    s32 *p12;
    if (TLobby__sub_803F94F0(p4) < 0) {
        return -0x100;
    }
    if (TLobby__sub_803F96AC(&network_dispatch_state) < 0) {
        clear_slot_for_handle(*p4);
        return -0x100;
    }
    p8 = (s32 *)&network_dispatch_state.thread_ids[0];
    if (TLobby__sub_803F9B94((void *)NetRunProtocolDispatchLoop, p8) < 0) {
        clear_slot_for_handle(*p4);
        NetReleaseMutex(network_dispatch_state.lock_handle);
        return -0x100;
    }
    p12 = (s32 *)&network_dispatch_state.thread_ids[1];
    if (TLobby__sub_803F9B94((void *)NetRunTimerDispatchLoop, p12) < 0) {
        deactivate_entry_by_key(*p8);
        clear_slot_for_handle(*p4);
        NetReleaseMutex(network_dispatch_state.lock_handle);
        return -0x100;
    }
    NetResumeThread(*p8);
    NetResumeThread(*p12);
    return 0;
}

extern void NetYieldOutsideDispatcherThread(void) {
    NetworkDispatchState *g = &network_dispatch_state;
    s32 self;

    NetStoreCurrentThread(&self);
    if (self != g->thread_ids[0] && self != g->thread_ids[1]) {
        unlock_mutex(g->lock_handle);
        NetYieldThread();
        lock_mutex(g->lock_handle);
    }
}

#pragma push
#pragma opt_common_subs on
extern void NetRunTimerDispatchLoop(void) {
    NetworkDispatchState *g = &network_dispatch_state;
    s32 now;
    s16 i;
    s16 j;
    s16 due;
    u32 next;

    for (;;) {
        TLobby__sub_803F97E8(network_dispatch_state.interval);
        for (i = 0; i < 10; i++) {
            if (g->timers[i].active == 0 || g->timers[i].fn == NULL) {
                continue;
            }
            get_time_ms(&now);
            due = 0;
            if (g->timers[i].last < g->timers[i].next) {
                if (g->timers[i].next <= now || now < g->timers[i].last) {
                    due = 1;
                }
            } else if (g->timers[i].next <= now && now < g->timers[i].last) {
                due = 1;
            }
            if (due == 0) {
                continue;
            }
            if (g->timers[i].lock_callback != 0) {
                lock_mutex(network_dispatch_state.lock_handle);
            }
            g->timers[i].fn();
            if (g->timers[i].lock_callback != 0) {
                unlock_mutex(network_dispatch_state.lock_handle);
            }
            next = now + g->timers[i].period;
            if (g->timers[i].period > network_dispatch_state.interval) {
                for (j = 0; j < 10; j++) {
                    if (i != j && g->timers[j].active != 0 && g->timers[j].next == next &&
                        g->timers[j].period > network_dispatch_state.interval) {
                        next += network_dispatch_state.interval;
                    }
                }
            }
            g->timers[i].last = now;
            g->timers[i].next = next;
        }
    }
}
#pragma pop

extern s32 NetUnregisterTimer(void *fn) {
    NetworkDispatchState *g = &network_dispatch_state;
    s16 i;

    if (fn == NULL) {
        return -0x100;
    }
    for (i = 0; i < 10; i++) {
        if (network_dispatch_state.timers[i].active != 0 && (void *)network_dispatch_state.timers[i].fn == fn) {
            g->timers[i].active = 0;
            g->timers[i].fn = NULL;
            g->timers[i].lock_callback = 0;
            g->timers[i].period = 0;
            g->timers[i].last = 0;
            g->timers[i].next = 0;
            return 0;
        }
    }
    return -0x100;
}

#pragma push
#pragma opt_common_subs on
s32 NetRegisterTimer(s32 period, s16 locked, NetTimerCallback fn) {
    u32 now;
    s32 *pint;
    s16 slot;
    s16 i;
    u32 cur;
    s32 iv;
    s16 j;
    u32 nxt;
    if (fn == NULL) {
        return -0x100;
    }
    pint = &network_dispatch_state.interval;
    if (period < network_dispatch_state.interval) {
        period = network_dispatch_state.interval;
    }
    slot = -1;
    i = 0;
    while (i < 10) {
        if (network_dispatch_state.timers[i].active != 0) {
            if (network_dispatch_state.timers[i].fn == fn) {
                return -0x100;
            }
        } else if (slot < 0) {
            slot = i;
        }
        i++;
    }
    if (slot < 0 || slot >= 10) {
        return -0x100;
    }
    get_time_ms((s32 *)&now);
    iv = *pint;
    cur = now;
    nxt = cur + period;
    if (period > iv) {
        j = 0;
        while (j < 10) {
            if (network_dispatch_state.timers[j].active != 0 && network_dispatch_state.timers[j].next == nxt && network_dispatch_state.timers[j].period > iv) {
                nxt += iv;
            }
            j++;
        }
    }
    network_dispatch_state.timers[slot].period = period;
    network_dispatch_state.timers[slot].last = cur;
    network_dispatch_state.timers[slot].next = nxt;
    network_dispatch_state.timers[slot].lock_callback = locked;
    network_dispatch_state.timers[slot].fn = fn;
    network_dispatch_state.timers[slot].active = 1;
    return 0;
}
#pragma pop

void NetEnqueueProtocolMessage(s32 payload, s16 detail, s16 first, s16 second, u16 protocol) {
    NetProtocolMessage message;
    message.first = first;
    message.second = second;
    message.protocol = protocol;
    message.detail = detail;
    message.payload = payload;
    TLobby__sub_803F9344(network_dispatch_state.queue_handle, &message, 0xC);
}

s32 dispatch_handler_by_id(s16 a, s32 b, void* e); /* declared here with other parameter types; the definition is s32 (s16, s32, s32) */
#pragma push
#pragma dont_inline off
#pragma inline_depth(4)
void NetRunProtocolDispatchLoop(void) {
    NetProtocolMessage msg;
    u8 *base = (u8 *)&network_dispatch_state;
    u8* p;
    u16 key;
    s16 i;

    while (1) {
        NetReceiveMessage(*(s32 *)(base + offsetof(NetworkDispatchState, queue_handle)), &msg, sizeof(msg));
        lock_mutex(network_dispatch_state.lock_handle);
        key = msg.protocol;
        for (i = 0, p = base; i < 3; p += sizeof(NetProtocolHandlerEntry), i++) {
            if (*(s16*)(p + offsetof(NetworkDispatchState, handlers[0].used)) != 0 && *(u16*)(p + offsetof(NetworkDispatchState, handlers[0].type)) == key) {
                NetProtocolHandler h = *(NetProtocolHandler *)(base + i * sizeof(NetProtocolHandlerEntry) + offsetof(NetworkDispatchState, handlers[0].fn));
                if (h != NULL) {
                    h(msg.payload, msg.detail, msg.first, msg.second);
                }
                break;
            }
        }
        unlock_mutex(*(s32 *)(base + offsetof(NetworkDispatchState, lock_handle)));
        dispatch_handler_by_id(msg.first, msg.second, (void *)msg.payload);
        NetYieldThread();
    }
}
#pragma pop

struct E_8041A0C0 { u8 pad[0x14]; s16 f14; u16 f16; s32 f18; };
s32 release_slot_by_id(u16 a) {
    E_8041A0C0 *g = (E_8041A0C0 *)&network_dispatch_state;
    E_8041A0C0 *p = g;
    s16 i;
    for (i = 0; i < 3; p = (E_8041A0C0 *)((u8 *)p + 8), i++) {
        if (p->f14 != 0 && p->f16 == a) {
            E_8041A0C0 *q = (E_8041A0C0 *)((u8 *)g + i * 8);
            q->f14 = 0;
            q->f16 = 0;
            q->f18 = 0;
            return 0;
        }
    }
    return -0x100;
}

s32 register_protocol_handler(u16 type, NetProtocolHandler fn) {
    NetworkDispatchState *g = &network_dispatch_state;
    s16 i;
    s16 freei;

    if (fn == NULL) {
        return -0x100;
    }
    freei = -1;
    for (i = 0; i < 3; i++) {
        if (network_dispatch_state.handlers[i].used != 0) {
            if (network_dispatch_state.handlers[i].type == type) {
                return -0x100;
            }
        } else if (freei < 0) {
            freei = i;
        }
    }
    if (freei < 0 || freei >= 3) {
        return -0x100;
    }
    g->handlers[freei].used = 1;
    g->handlers[freei].type = type;
    g->handlers[freei].fn = fn;
    return 0;
}

