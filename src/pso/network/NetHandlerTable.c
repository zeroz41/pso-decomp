#include "pso/network/UdpRuntime.h"
#include "pso/network/SocketEvents.h"
#include "pso/network/NetworkDispatch.h"
#include "pso/network/NetworkRuntime.h"
#include "pso/network/TLobby_804048E8.h"
#include "pso/network/TLobby_804050DC.h"
#include "pso/network/TLobby_803FC178.h"
#include "pso/network/NetworkPacketPool.h"
#include "pso/network/netcfg.h"
#include "pso/network/BufferRef.h"
#include "pso/network/IPv6.h"

#include "types.h"
#include "pso/network/NetworkTransport.h"
#include "pso/network/TLobby_803FAEA0.h"
#include "pso/network/TLobby_803FCF44.h"
#include "pso/network/TLobby_8041112C.h"
#include "pso/network/text_80421620.h"
typedef struct LobbyHandler LobbyHandler;
typedef struct LobbyHandlerTable LobbyHandlerTable;
s32 dispatch_handler_by_id(s16 arg0, s32 arg1, s32 arg2);

#include <stddef.h>

/* A link-layer driver, registered by TLobby__sub_8040A2BC from 11 functions: loopback (TLobby__sub_8041510C,
   always entry 0), PPP (TLobby__sub_803FD10C) and Ethernet (init_net_sockets).  Each function is called by one
   dispatcher (named after the slot); op14..op20 only when flags & 4. */
struct LobbyHandler {
    s16 active;
    s16 flags;                                     /* 0x02: as registered: 1 loopback, 2 PPP, 0x7C Ethernet */
    s32 (*get_interface_id)(s16 idx, void *dst);   /* 0x04: TLobby__sub_8040A0C0 */
    s32 (*op08)(s16 idx, u32 a, s32 b, u32 *c);    /* 0x08: TLobby__sub_8040A044 */
    s32 (*op0C)(s32);                              /* 0x0C: call_entry_callback */
    s32 (*op10)(s32);                              /* 0x10: invoke_socket_callback */
    s32 (*op14)(s32);                              /* 0x14: TLobby__sub_80409EB0 */
    s32 (*op18)(s32, s32);                         /* 0x18: TLobby__sub_80409E18 */
    s32 (*op1C)(s32, s32, s32);                    /* 0x1C: TLobby__sub_80409D7C */
    s32 (*op20)(s32, s32, s32);                    /* 0x20: TLobby__sub_80409CE0 */
    s32 (*op24)(s32, s32);                         /* 0x24: dispatch_handler_by_id; TLobby__sub_80409818 calls it
                                                      as void (s16, s32) */
    s16 (*op28)(s32, s32, s32);                    /* 0x28: dispatch_handler_by_index */
    s16 (*output)(s32, s32, s32, s32);             /* 0x2C: call_handler_by_index */
};
typedef char LobbyHandler_size_check[sizeof(LobbyHandler) == 0x30 ? 1 : -1];

typedef struct LobbyHandlerTable { s16 count; LobbyHandler *list; } LobbyHandlerTable;
extern LobbyHandlerTable lobby_handler_table_desc; /* defined at the end of the file */
typedef char LobbyHandlerTable_size_check[sizeof(LobbyHandlerTable) == 8 ? 1 : -1];

#include "pso/network/IPv6Send.h"
#include "pso/network/NetStackTypes.h"

s16 TLobby__sub_8040A2BC(Fn_8040881C *fns, s16 kind);
s32 TLobby__sub_80409AD8(void);

/* Inline the helpers below; this applies to the rest of the file. */
#pragma dont_inline off
#pragma inline_depth(4)

void TLobby__sub_80409818(s32 msg, s16 len, s16 idx, s16 arg3, u16 type) {
    void NetEnqueueProtocolMessage(s32 msg, s16 len, s16 idx, s16 arg3, u16 type);
    if (idx < 0 || idx >= lobby_handler_table_desc.count) {
        return;
    }
    switch (type) {
    default:
        ((void (*)(s16, s32))lobby_handler_table_desc.list[idx].op24)(arg3, msg);
        break;
    case 0x800:
    case 0x806:
    case 0x86DD:
        NetEnqueueProtocolMessage(msg, len, idx, arg3, type);
        break;
    }
}

inline s16 packet_length_804098B4(NetPacket *pkt) {
    NetPacketFragment *f;
    s16 n;
    s16 total = 0;
    n = pkt->fragment_count;
    f = &pkt->fragments[n] - 1;
    for (; n > 0; n--) {
        total += f->length;
        f--;
    }
    if (total != (s16)pkt->total_bytes) {
        return total;
    }
    return pkt->total_bytes;
}
s16 TLobby__sub_804098B4(void *pkt) {
    return packet_length_804098B4(pkt);
}

inline s32 calc_80409908(void *self, u8 *arr) {
    u8 tmp[0x10];
    u8 *p;
    s32 acc;
    s16 n;
    s32 sum;
    sum = 0;
    n = (s16)*(s32 *)(arr + 4);
    acc = (s32)self;
    p = arr + n * 12;
    while (n > 0) {
        set_value_and_enable(tmp, acc);
        TLobby__sub_80406FD8(tmp, arr + (n - 1) * 12 + 0x10, *(s16 *)p);
        acc += *(s16 *)p;
        sum += *(s16 *)p;
        p -= 12;
        n--;
    }
    if ((s16)sum != (s16)*(s32 *)(arr + 8)) return sum;
    return (s16)*(s32 *)(arr + 8);
}

s32 TLobby__sub_80409908(void *self, void *arr_) {
    return calc_80409908(self, arr_);
}
s32 clear_table_entry_locked(s16 arg0) {
    s32 ret;
    lock_mutex(network_dispatch_state.lock_handle);
    if (arg0 < 0 || arg0 > lobby_handler_table_desc.count) {
        ret = -0x10F;
    } else {
        LobbyHandler *e = lobby_handler_table_desc.list;
        e += arg0;
        NetMemset(e, 0, sizeof(LobbyHandler));
        ret = 0;
    }
    unlock_mutex(network_dispatch_state.lock_handle);
    return ret;
}

s16 TLobby__sub_80409A3C(u8 *arg0, s16 arg1) {
    s16 temp_r31;
    lock_mutex(network_dispatch_state.lock_handle);
    temp_r31 = TLobby__sub_8040A2BC((Fn_8040881C *)(arg0), arg1);
    unlock_mutex(network_dispatch_state.lock_handle);
    return temp_r31;
}

s32 TLobby__sub_80409AA8(void) {
    TLobby__sub_803F8A9C(&lobby_handler_table_desc);
    lobby_handler_table_desc.count = 0;
    return 0;
}

s32 TLobby__sub_80409AD8(void) {
    s16 i;
    LobbyHandler *e;
    TLobby__sub_803F8AA0((u8 *)&lobby_handler_table_desc);
    e = lobby_handler_table_desc.list;
    i = 0;
    while (i < lobby_handler_table_desc.count) {
        NetMemset(e, 0, sizeof(LobbyHandler));
        i++;
        e++;
    }
    return 0;
}

s16 call_handler_by_index(s16 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    LobbyHandler *e;
    s16 (*fn)(s32, s32, s32, s32);
    if (arg0 < 0 || arg0 > lobby_handler_table_desc.count) {
        return -0x10F;
    }
    e = lobby_handler_table_desc.list;
    e += arg0;
    if (e->active == 0) {
        return -2;
    }
    fn = e->output;
    if (fn == NULL) {
        return -2;
    }
    return fn(arg1, arg2, arg3, arg4);
}

s16 dispatch_handler_by_index(s16 arg0, s32 arg1, s32 arg2, s32 arg3) {
    LobbyHandler *e;
    s16 (*fn)(s32, s32, s32);
    if (arg0 < 0 || arg0 > lobby_handler_table_desc.count) {
        return -0x10F;
    }
    e = lobby_handler_table_desc.list;
    e += arg0;
    if (e->active == 0) {
        return -2;
    }
    fn = e->op28;
    if (fn == NULL) {
        return -2;
    }
    return fn(arg1, arg2, arg3);
}

s32 dispatch_handler_by_id(s16 arg0, s32 arg1, s32 arg2) {
    LobbyHandler *e;
    s32 (*fn)(s32, s32);

    if (arg0 < 0 || arg0 > lobby_handler_table_desc.count) {
        return -0x10F;
    }
    e = lobby_handler_table_desc.list;
    e += arg0;
    if (e->active == 0) {
        return -2;
    }
    fn = e->op24;
    if (fn == NULL) {
        return -2;
    }
    return fn(arg1, arg2);
}

s32 TLobby__sub_80409CE0(s16 arg0, s32 arg1, s32 arg2, s32 arg3) {
    LobbyHandler *e;
    s32 (*fn)(s32, s32, s32);

    if (arg0 < 0 || arg0 > lobby_handler_table_desc.count) {
        return -0x10F;
    }
    e = lobby_handler_table_desc.list;
    e += arg0;
    if (e->active == 0) {
        return -2;
    }
    if (!(e->flags & 4)) {
        return 0;
    }
    fn = e->op20;
    if (fn == NULL) {
        return -2;
    }
    return fn(arg1, arg2, arg3);
}

s32 TLobby__sub_80409D7C(s16 arg0, s32 arg1, s32 arg2, s32 arg3) {
    LobbyHandler *e;
    s32 (*fn)(s32, s32, s32);

    if (arg0 < 0 || arg0 > lobby_handler_table_desc.count) {
        return -0x10F;
    }
    e = lobby_handler_table_desc.list;
    e += arg0;
    if (e->active == 0) {
        return -2;
    }
    if (!(e->flags & 4)) {
        return 0;
    }
    fn = e->op1C;
    if (fn == NULL) {
        return -2;
    }
    return fn(arg1, arg2, arg3);
}

s32 TLobby__sub_80409E18(s16 arg0, s32 arg1, s32 arg2) {
    LobbyHandler *e;
    s32 (*fn)(s32, s32);

    if (arg0 < 0 || arg0 > lobby_handler_table_desc.count) {
        return -0x10F;
    }
    e = lobby_handler_table_desc.list;
    e += arg0;
    if (e->active == 0) {
        return -2;
    }
    if (!(e->flags & 4)) {
        return 0;
    }
    fn = e->op18;
    if (fn == NULL) {
        return -2;
    }
    return fn(arg1, arg2);
}

s32 TLobby__sub_80409EB0(s16 arg0, s32 arg1) {
    LobbyHandler *e;
    s32 (*fn)(s32);

    if (arg0 < 0 || arg0 > lobby_handler_table_desc.count) {
        return -0x10F;
    }
    e = lobby_handler_table_desc.list;
    e += arg0;
    if (e->active == 0) {
        return -2;
    }
    if (!(e->flags & 4)) {
        return 0;
    }
    fn = e->op14;
    if (fn == NULL) {
        return -2;
    }
    return fn(arg1);
}

#pragma push
#pragma opt_propagation off
s32 invoke_socket_callback(s16 i, s32 arg) {
    LobbyHandler *e;
    if (i < 0 || i > lobby_handler_table_desc.count) {
        return -0x10F;
    }
    e = lobby_handler_table_desc.list + i;
    if (e->active == 0) {
        return -2;
    }
    if (e->op10 == 0) {
        return -2;
    }
    return e->op10(arg);
}
#pragma pop

#pragma push
#pragma opt_propagation off
s32 call_entry_callback(s16 i, s32 arg) {
    LobbyHandler *e;
    if (i < 0 || i > lobby_handler_table_desc.count) {
        return -0x10F;
    }
    e = lobby_handler_table_desc.list + i;
    if (e->active == 0) {
        return -2;
    }
    if (e->op0C == 0) {
        return -2;
    }
    return e->op0C(arg);
}
#pragma pop

s32 TLobby__sub_8040A044(s16 idx, u32 a, s32 b, u32 *c) {
    LobbyHandler *e;
    if (idx < 0 || idx > lobby_handler_table_desc.count) {
        return -0x10F;
    }
    e = lobby_handler_table_desc.list;
    e += idx;
    if (e->active == 0) {
        return -2;
    }
    if (e->op08 == 0) {
        return -2;
    }
    return e->op08(idx, a, b, c);
}

s32 TLobby__sub_8040A0C0(s16 idx, void *a)
{
    LobbyHandler *e;

    if (idx < 0 || idx > lobby_handler_table_desc.count) {
        return -0x10f;
    }
    e = lobby_handler_table_desc.list;
    e += idx;
    if (e->active == 0) {
        return -2;
    }
    if (e->get_interface_id == NULL) {
        return -2;
    }
    return e->get_interface_id(idx, a);
}

#pragma push
#pragma optimization_level 2
s32 is_slot_flag_0x40_set(s16 i) {
    LobbyHandler *e;
    if (i < 0 || i > lobby_handler_table_desc.count) { return 0; }
    e = lobby_handler_table_desc.list;
    if (e[i].active == 0) { return 0; }
    if (e[i].flags & 0x40) { return 1; }
    return 0;
}
#pragma pop

#pragma push
#pragma optimization_level 2
s32 is_slot_flag_0x20_set(s16 i) {
    LobbyHandler *e;
    if (i < 0 || i > lobby_handler_table_desc.count) { return 0; }
    e = lobby_handler_table_desc.list;
    if (e[i].active == 0) { return 0; }
    if (e[i].flags & 0x20) { return 1; }
    return 0;
}
#pragma pop

#pragma push
#pragma optimization_level 2
s32 is_entry_flag10_set(s16 i) {
    LobbyHandler *e;
    if (i < 0 || i > lobby_handler_table_desc.count) { return 0; }
    e = lobby_handler_table_desc.list;
    if (e[i].active == 0) { return 0; }
    if (e[i].flags & 0x10) { return 1; }
    return 0;
}
#pragma pop

#pragma push
#pragma optimization_level 2
s32 is_socket_flag_set(s16 i) {
    LobbyHandler *e;
    if (i < 0 || i > lobby_handler_table_desc.count) { return 0; }
    e = lobby_handler_table_desc.list;
    if (e[i].active == 0) { return 0; }
    if (e[i].flags & 1) { return 1; }
    return 0;
}
#pragma pop

extern s16 TLobby__sub_8040A2BC(Fn_8040881C *fns, s16 kind) {
    LobbyHandler *e;
    s16 i;

    if (fns == NULL || fns[1] == NULL) {
        return -2;
    }
    switch (kind) {
    case 1:
        e = lobby_handler_table_desc.list;
        if (e->active == 0) {
            NetMemcpy(&e->get_interface_id, fns, 11 * sizeof(Fn_8040881C));
            e->flags = kind;
            e->active = 1;
            return 0;
        }
        return -2;
    default:
        for (i = 1, e = lobby_handler_table_desc.list + 1; i < lobby_handler_table_desc.count; i++, e++) {
            if (e->active == 0) {
                NetMemcpy(&e->get_interface_id, fns, 11 * sizeof(Fn_8040881C));
                e->flags = kind;
                e->active = 1;
                return i;
            }
        }
        return -0x10F;
    }
}

LobbyHandlerTable lobby_handler_table_desc;
