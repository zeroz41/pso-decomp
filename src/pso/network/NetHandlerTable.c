#include "pso/network/UdpRuntime.h"
#include "pso/network/SocketEvents.h"
#include "pso/network/NetworkDispatch.h"
#include "pso/network/NetworkRuntime.h"
#include "pso/network/PppVj.h"
#include "pso/network/NetStack.h"
#include "pso/network/PppChap.h"
#include "pso/network/NetworkPacketPool.h"
#include "pso/network/netcfg.h"
#include "pso/network/BufferRef.h"
#include "pso/network/IPv6.h"

#include "types.h"
#include "pso/network/NetworkTransport.h"
#include "pso/network/PppApi.h"
#include "pso/network/Ppp.h"
#include "pso/network/NetIpv6Route.h"
#include "pso/network/NetApi.h"

#include <stddef.h>


extern LobbyHandlerTable lobby_handler_table_desc; /* defined at the end of the file */

#include "pso/network/IPv6Send.h"
#include "pso/network/NetStackTypes.h"

s16 insert_link_handler(NetLinkDriverFn *fns, s16 kind);

/* Inline the helpers below; this applies to the rest of the file. */
#pragma dont_inline off
#pragma inline_depth(4)

void link_input(u8 *msg, s16 len, s16 idx, s16 second, u16 type) {
    if (idx < 0 || idx >= lobby_handler_table_desc.count) {
        return;
    }
    switch (type) {
    default:
        ((void (*)(s16, u8 *))lobby_handler_table_desc.list[idx].release_frame)(second, msg);
        break;
    case 0x800:
    case 0x806:
    case 0x86DD:
        NetEnqueueProtocolMessage(msg, len, idx, second, type);
        break;
    }
}

inline s16 packet_length(NetPacket *pkt) {
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
s16 link_packet_length(void *pkt) {
    return packet_length(pkt);
}

inline s32 copy_packet_out(void *self, NetPacket *pkt) {
    u8 tmp[0x10];
    NetPacketFragment *p;
    u8 *acc;
    s16 n;
    s32 sum;
    sum = 0;
    n = (s16)pkt->fragment_count;
    acc = self;
    p = pkt->fragments + n - 1;
    while (n > 0) {
        set_value_and_enable((NetBufferRef *)tmp, acc);
        netbuf_copy_by_ref((NetBufferRef *)tmp, &pkt->fragments[n - 1].buffer, p->length);
        acc += p->length;
        sum += p->length;
        p--;
        n--;
    }
    if ((s16)sum != (s16)pkt->total_bytes) return sum;
    return (s16)pkt->total_bytes;
}

s32 link_packet_copy(void *self, void *arr_) {
    return copy_packet_out(self, arr_);
}
s32 clear_table_entry_locked(s16 idx) {
    s32 ret;
    lock_mutex(network_dispatch_state.lock_handle);
    if (idx < 0 || idx > lobby_handler_table_desc.count) {
        ret = -0x10F;
    } else {
        LobbyHandler *e = lobby_handler_table_desc.list;
        e += idx;
        NetMemset(e, 0, sizeof(LobbyHandler));
        ret = 0;
    }
    unlock_mutex(network_dispatch_state.lock_handle);
    return ret;
}

s16 register_link_handler(NetLinkDriverFn *fns, s16 kind) {
    s16 id;
    lock_mutex(network_dispatch_state.lock_handle);
    id = insert_link_handler(fns, kind);
    unlock_mutex(network_dispatch_state.lock_handle);
    return id;
}

s32 handler_table_term(void) {
    term_handler_table_config(&lobby_handler_table_desc);
    lobby_handler_table_desc.count = 0;
    return 0;
}

s16 handler_table_init(void) {
    s16 i;
    LobbyHandler *e;
    init_handler_table_config(&lobby_handler_table_desc);
    e = lobby_handler_table_desc.list;
    i = 0;
    while (i < lobby_handler_table_desc.count) {
        NetMemset(e, 0, sizeof(LobbyHandler));
        i++;
        e++;
    }
    return 0;
}

s16 call_handler_by_index(s16 idx, s32 handle, s32 mode, void *addr, void *pkt) {
    LobbyHandler *e;
    s16 (*fn)(s32, s32, void *, void *);
    if (idx < 0 || idx > lobby_handler_table_desc.count) {
        return -0x10F;
    }
    e = lobby_handler_table_desc.list;
    e += idx;
    if (e->active == 0) {
        return -2;
    }
    fn = e->output;
    if (fn == NULL) {
        return -2;
    }
    return fn(handle, mode, addr, pkt);
}

s16 dispatch_handler_by_index(s16 idx, s32 handle, void *addr, void *pkt) {
    LobbyHandler *e;
    s16 (*fn)(s32, void *, void *);
    if (idx < 0 || idx > lobby_handler_table_desc.count) {
        return -0x10F;
    }
    e = lobby_handler_table_desc.list;
    e += idx;
    if (e->active == 0) {
        return -2;
    }
    fn = e->forward;
    if (fn == NULL) {
        return -2;
    }
    return fn(handle, addr, pkt);
}

s32 dispatch_handler_by_id(s16 first, s32 second, u8 *payload) {
    LobbyHandler *e;
    s32 (*fn)(s32, u8 *);

    if (first < 0 || first > lobby_handler_table_desc.count) {
        return -0x10F;
    }
    e = lobby_handler_table_desc.list;
    e += first;
    if (e->active == 0) {
        return -2;
    }
    fn = e->release_frame;
    if (fn == NULL) {
        return -2;
    }
    return fn(second, payload);
}

s16 link_update_multicast(s16 idx, s32 def, s32 op, void *tex) {
    LobbyHandler *e;
    s16 (*fn)(s32, s32, void *);

    if (idx < 0 || idx > lobby_handler_table_desc.count) {
        return -0x10F;
    }
    e = lobby_handler_table_desc.list;
    e += idx;
    if (e->active == 0) {
        return -2;
    }
    if (!(e->flags & 4)) {
        return 0;
    }
    fn = e->multicast_ctl;
    if (fn == NULL) {
        return -2;
    }
    return fn(def, op, tex);
}

s16 link_update_address(s16 idx, s32 def, s32 op, void *tex) {
    LobbyHandler *e;
    s16 (*fn)(s32, s32, void *);

    if (idx < 0 || idx > lobby_handler_table_desc.count) {
        return -0x10F;
    }
    e = lobby_handler_table_desc.list;
    e += idx;
    if (e->active == 0) {
        return -2;
    }
    if (!(e->flags & 4)) {
        return 0;
    }
    fn = e->alias_ctl;
    if (fn == NULL) {
        return -2;
    }
    return fn(def, op, tex);
}

s32 link_get_address(s16 idx, s32 handle, void *dst) {
    LobbyHandler *e;
    s32 (*fn)(s32, void *);

    if (idx < 0 || idx > lobby_handler_table_desc.count) {
        return -0x10F;
    }
    e = lobby_handler_table_desc.list;
    e += idx;
    if (e->active == 0) {
        return -2;
    }
    if (!(e->flags & 4)) {
        return 0;
    }
    fn = e->get_lladdr;
    if (fn == NULL) {
        return -2;
    }
    return fn(handle, dst);
}

s16 link_get_address_length(s16 idx, s32 handle) {
    LobbyHandler *e;
    s16 (*fn)(s32);

    if (idx < 0 || idx > lobby_handler_table_desc.count) {
        return -0x10F;
    }
    e = lobby_handler_table_desc.list;
    e += idx;
    if (e->active == 0) {
        return -2;
    }
    if (!(e->flags & 4)) {
        return 0;
    }
    fn = e->get_lladdr_len;
    if (fn == NULL) {
        return -2;
    }
    return fn(handle);
}

#pragma push
#pragma opt_propagation off
s16 invoke_socket_callback(s16 i, s32 arg) {
    LobbyHandler *e;
    if (i < 0 || i > lobby_handler_table_desc.count) {
        return -0x10F;
    }
    e = lobby_handler_table_desc.list + i;
    if (e->active == 0) {
        return -2;
    }
    if (e->get_mtu == 0) {
        return -2;
    }
    return e->get_mtu(arg);
}
#pragma pop

#pragma push
#pragma opt_propagation off
s32 call_entry_callback(s16 i, s16 arg) {
    LobbyHandler *e;
    if (i < 0 || i > lobby_handler_table_desc.count) {
        return -0x10F;
    }
    e = lobby_handler_table_desc.list + i;
    if (e->active == 0) {
        return -2;
    }
    if (e->close == 0) {
        return -2;
    }
    return e->close(arg);
}
#pragma pop

s16 link_attach_protocol(s16 idx, u32 a, s16 b, u32 *c) {
    LobbyHandler *e;
    if (idx < 0 || idx > lobby_handler_table_desc.count) {
        return -0x10F;
    }
    e = lobby_handler_table_desc.list;
    e += idx;
    if (e->active == 0) {
        return -2;
    }
    if (e->open == 0) {
        return -2;
    }
    return e->open(idx, a, b, c);
}

s16 link_get_interface_id(s16 idx, void *a)
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
s16 link_solicits_routers(s16 i) {
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
s16 link_needs_resolution(s16 i) {
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
s16 link_does_dad(s16 i) {
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
s16 link_is_loopback(s16 i) {
    LobbyHandler *e;
    if (i < 0 || i > lobby_handler_table_desc.count) { return 0; }
    e = lobby_handler_table_desc.list;
    if (e[i].active == 0) { return 0; }
    if (e[i].flags & 1) { return 1; }
    return 0;
}
#pragma pop

extern s16 insert_link_handler(NetLinkDriverFn *fns, s16 kind) {
    LobbyHandler *e;
    s16 i;

    if (fns == NULL || fns[1] == NULL) {
        return -2;
    }
    switch (kind) {
    case 1:
        e = lobby_handler_table_desc.list;
        if (e->active == 0) {
            NetMemcpy(&e->get_interface_id, fns, 11 * sizeof(NetLinkDriverFn));
            e->flags = kind;
            e->active = 1;
            return 0;
        }
        return -2;
    default:
        for (i = 1, e = lobby_handler_table_desc.list + 1; i < lobby_handler_table_desc.count; i++, e++) {
            if (e->active == 0) {
                NetMemcpy(&e->get_interface_id, fns, 11 * sizeof(NetLinkDriverFn));
                e->flags = kind;
                e->active = 1;
                return i;
            }
        }
        return -0x10F;
    }
}

LobbyHandlerTable lobby_handler_table_desc;
