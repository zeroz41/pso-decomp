/* The PPP link layer (named after NetPppLink.h): its state lobby_net_buffer_desc_b and the framing around it
 * (a C library, built with GC/1.2.5n). */
#include "types.h"
#include "pso/network/TLobby_803FC178.h"
#include "pso/network/TLobby_803FCF44.h"
#include "pso/network/TLobby_804050DC.h"
#include "pso/network/TLobby_8041112C.h"
#include "pso/network/NetworkRuntime.h"
#include "pso/network/TLobby_804048E8.h"
#include "pso/network/NetworkTransport.h"

#include "pso/network/NetStackTypes.h"
#include "pso/network/PppFsm.h"
#include "pso/network/TLobby_803FAEA0.h"
#include "pso/network/NetPppLink.h"



void ppp_link_term(void) {
    PppLink *g = &lobby_net_buffer_desc_b;
    clear_table_entry_locked(g->id);
    g->id = -1;
    g->count = 0;
    term_ppp_link_config(g);
}

s32 ppp_link_free_buffer(s16 ch, u8 *addr);
s32 ppp_link_get_interface_id(s16 ch, u8 *dst);

s16 ppp_link_init(void) {
    NetLinkDriverFn fns[11];
    s16 r;
    s16 i;
    s16 *p;

    init_buffer_desc_b(&lobby_net_buffer_desc_b);
    fns[0] = (NetLinkDriverFn)ppp_link_get_interface_id;
    fns[1] = (NetLinkDriverFn)ppp_link_attach_protocol;
    fns[2] = (NetLinkDriverFn)clear_socket_slot;
    fns[3] = (NetLinkDriverFn)get_checked_status_value;
    fns[4] = (NetLinkDriverFn)ppp_link_get_address_length;
    fns[5] = (NetLinkDriverFn)ppp_link_get_address;
    fns[6] = (NetLinkDriverFn)ppp_link_update_address;
    fns[7] = (NetLinkDriverFn)ppp_link_update_multicast;
    fns[8] = (NetLinkDriverFn)ppp_link_free_buffer;
    fns[9] = (NetLinkDriverFn)ppp_link_forward_packet;
    fns[10] = (NetLinkDriverFn)ppp_link_send_packet;
    r = register_link_handler(fns, 2);
    if (r < 0) {
        return r;
    }
    lobby_net_buffer_desc_b.id = r;
    lobby_net_buffer_desc_b.protocols[0].used = 0;
    lobby_net_buffer_desc_b.protocols[0].type = 0;
    lobby_net_buffer_desc_b.protocols[1].used = 0;
    lobby_net_buffer_desc_b.protocols[1].type = 0;
    p = lobby_net_buffer_desc_b.used;
    i = 0;
    while (i < lobby_net_buffer_desc_b.count) {
        *p = 0;
        i++;
        p++;
    }
    return r;
}

#pragma push
#pragma optimization_level 3
s32 ppp_link_send_packet(s16 ch, s32 mode, s32 addr, u8 *packet) {
    s16 len;
    PppFrame *pkt;
    if ((ch != 0) && (ch != 1)) {
        return -0x112;
    }
    pkt = ppp_buffers.ip_out;
    len = link_packet_length(packet);
    if (lobby_net_buffer_desc_b.size < len) {
        return -0x112;
    }
    lock_mutex(net_thread_state.mutex);
    if ((s16) lobby_modem_connect_state == 4) {
        pkt->data = (u8 *)ppp_buffers.ip_out + ((ppp_buffers.headroom + 0x83) & 0xFFFFFFFC);
        pkt->len = len;
        link_packet_copy(pkt->data, packet);
        ppp_output_datagram(pkt, lobby_net_buffer_desc_b.protocols[ch].type);
    }
    unlock_mutex(net_thread_state.mutex);
    return 0;
}
#pragma pop

#pragma push
#pragma optimization_level 3
s32 ppp_link_forward_packet(s16 ch, s32 addr, u8 *packet) {
    s16 len;
    PppFrame *pkt;
    if ((ch != 0) && (ch != 1)) {
        return -0x112;
    }
    pkt = ppp_buffers.ip_out;
    len = link_packet_length(packet);
    if (lobby_net_buffer_desc_b.size < len) {
        return -0x112;
    }
    lock_mutex(net_thread_state.mutex);
    if ((s16) lobby_modem_connect_state == 4) {
        pkt->data = (u8 *)ppp_buffers.ip_out + ((ppp_buffers.headroom + 0x83) & 0xFFFFFFFC);
        pkt->len = len;
        link_packet_copy(pkt->data, packet);
        ppp_output_datagram(pkt, lobby_net_buffer_desc_b.protocols[ch].type);
    }
    unlock_mutex(net_thread_state.mutex);
    return 0;
}
#pragma pop

s32 ppp_link_free_buffer(s16 ch, u8 *addr) {
    PppLink *p = &lobby_net_buffer_desc_b;
    s16 size;
    s16 i;
    s16 *used;
    u8 *base;
    s16 count;
    if ((ch != 0) && (ch != 1))
    {
        return -0x112;
    }
    used = p->used;
    base = p->buffers;
    size = p->size;
    count = p->count;
    for (i = 0; i < count; i++, used++)
    {
        if ((((*used) != 0) && (base <= addr)) && (addr < (base + size)))
        {
            *used = 0;
            return 0;
        }
        base += (s16)size;
    }

    return -0x112;
}

s32 ppp_link_update_multicast(s16 ch) {
    if ((ch != 0) && (ch != 1)) {
        return -0x112;
    }
    return 0;
}

s32 ppp_link_update_address(s16 ch) {
    if ((ch != 0) && (ch != 1)) {
        return -0x112;
    }
    return 0;
}

s32 ppp_link_get_address(s16 ch) {
    if ((ch != 0) && (ch != 1)) {
        return -0x112;
    }
    return 0;
}

s32 ppp_link_get_address_length(s16 ch) {
    if ((ch != 0) && (ch != 1)) {
        return -0x112;
    }
    return 0;
}

s16 get_checked_status_value(s16 ch) {
    if ((ch != 0) && (ch != 1)) {
        return -0x112;
    }
    if (ppp_use_pppoe != 0) {
        return 0x5AE;
    }
    return lobby_net_buffer_desc_b.size;
}

s32 clear_socket_slot(s16 i) {
    PppLink *g;
    if (i != 0 && i != 1) {
        return -0x112;
    }
    g = &lobby_net_buffer_desc_b;
    g->protocols[i].used = 0;
    g->protocols[i].type = 0;
    return 0;
}

s16 ppp_link_attach_protocol(s16 h, s16 v) {
    s16 r;
    PppLink *g = &lobby_net_buffer_desc_b;
    if (h != g->id) { return -274; }
    if (g->protocols[0].used == 0) {
        r = 0;
    } else if (g->protocols[1].used == 0) {
        r = 1;
    } else {
        return -274;
    }
    g->protocols[r].used = 1;
    g->protocols[r].type = v;
    return r;
}

s32 ppp_link_get_interface_id(s16 ch, u8 *dst) {
    PppFsm *fsm;
    Ipv6cpConfig *e;
    u16 low;
    u32 a;
    u32 b;
    u8 *p;
    if (ch != lobby_net_buffer_desc_b.id) {
        return -0x112;
    }
    fsm = &ppp_proto_blocks.ipv6cp;
    e = fsm->opts;
    if (fsm->state != 5) {
        return -0x112;
    }
    a = e->local.current.words[0];
    b = e->local.current.words[1];
    p = dst + 1;
    dst[0] = a >> 24;
    low = a;
    p[0] = a >> 16;
    p[1] = low >> 8;
    p[2] = low;
    p[3] = b >> 24;
    p[4] = b >> 16;
    p[5] = b >> 8;
    p[6] = b;
    return 0;
}

PppLink lobby_net_buffer_desc_b;
