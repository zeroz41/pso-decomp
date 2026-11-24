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

#include <stddef.h>

/* A link-layer driver, registered by insert_link_handler from 11 functions: loopback (register_loopback_handlers,
   always entry 0), PPP (ppp_link_init) and Ethernet (init_net_sockets).  Each function is called by one
   dispatcher (named after the slot); get_lladdr_len..multicast_ctl only when flags & 4. */
struct LobbyHandler {
    s16 active;
    s16 flags;                                     /* 0x02: as registered: 1 loopback, 2 PPP, 0x7C Ethernet */
    s16 (*get_interface_id)(s16 idx, void *dst);   /* 0x04: link_get_interface_id */
    s16 (*open)(s16 idx, u32 a, s16 b, u32 *c);    /* 0x08: link_attach_protocol; opens a channel for an EtherType */
    s32 (*close)(s16);                             /* 0x0C: call_entry_callback; frees the channel */
    s16 (*get_mtu)(s32);                           /* 0x10: invoke_socket_callback; Ethernet 1500 */
    s16 (*get_lladdr_len)(s32);                    /* 0x14: link_get_address_length; Ethernet 6 */
    s32 (*get_lladdr)(s32, s32);                   /* 0x18: link_get_address; copies the MAC */
    s16 (*alias_ctl)(s32, s32, void *);            /* 0x1C: link_update_address; 1 adds, 2 removes an ARP alias */
    s16 (*multicast_ctl)(s32, s32, void *);        /* 0x20: link_update_multicast; 1 joins, 2 leaves a multicast group */
    s32 (*release_frame)(s32, s32);                /* 0x24: dispatch_handler_by_id; frees a received frame; link_input calls it
                                                      as void (s16, s32) */
    s16 (*forward)(s32, s32, s32);                 /* 0x28: dispatch_handler_by_index; sends an IPv4 packet to a
                                                      unicast next hop (ppp_link_forward_packet, forward_loopback_packet) */
    s16 (*output)(s32, s32, s32, s32);             /* 0x2C: call_handler_by_index */
};
LAYOUT_ASSERT(LobbyHandler_size_check, sizeof(LobbyHandler) == 0x30);

extern LobbyHandlerTable lobby_handler_table_desc; /* defined at the end of the file */

#include "pso/network/IPv6Send.h"
#include "pso/network/NetStackTypes.h"

s16 insert_link_handler(NetLinkDriverFn *fns, s16 kind);
s32 handler_table_init(void);

/* Inline the helpers below; this applies to the rest of the file. */
#pragma dont_inline off
#pragma inline_depth(4)

void link_input(s32 msg, s16 len, s16 idx, s16 second, u16 type) {
    if (idx < 0 || idx >= lobby_handler_table_desc.count) {
        return;
    }
    switch (type) {
    default:
        ((void (*)(s16, s32))lobby_handler_table_desc.list[idx].release_frame)(second, msg);
        break;
    case 0x800:
    case 0x806:
    case 0x86DD:
        NetEnqueueProtocolMessage(msg, len, idx, second, type);
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
s16 link_packet_length(void *pkt) {
    return packet_length_804098B4(pkt);
}

inline s32 calc_80409908(void *self, NetPacket *pkt) {
    u8 tmp[0x10];
    NetPacketFragment *p;
    saddr acc;
    s16 n;
    s32 sum;
    sum = 0;
    n = (s16)pkt->fragment_count;
    acc = (saddr)self;
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
    return calc_80409908(self, arr_);
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

s32 handler_table_init(void) {
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

s16 call_handler_by_index(s16 idx, s32 handle, s32 mode, s32 addr, s32 pkt) {
    LobbyHandler *e;
    s16 (*fn)(s32, s32, s32, s32);
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

s16 dispatch_handler_by_index(s16 idx, s32 handle, s32 addr, s32 pkt) {
    LobbyHandler *e;
    s16 (*fn)(s32, s32, s32);
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

s32 dispatch_handler_by_id(s16 first, s32 second, s32 payload) {
    LobbyHandler *e;
    s32 (*fn)(s32, s32);

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

s32 link_get_address(s16 idx, s32 handle, s32 dst) {
    LobbyHandler *e;
    s32 (*fn)(s32, s32);

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
s16 is_slot_flag_0x40_set(s16 i) {
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
s16 is_slot_flag_0x20_set(s16 i) {
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
s16 is_entry_flag10_set(s16 i) {
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
s16 is_socket_flag_set(s16 i) {
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
