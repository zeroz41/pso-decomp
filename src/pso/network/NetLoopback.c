#include "types.h"
#include "pso/network/NetStackTypes.h"
#include "pso/network/netcfg.h"
#include "pso/network/NetStack.h"
#include "pso/network/NetIpv6Route.h"

s32 send_loopback_frame(s16 idx, s16 mode, u8 *addr, void *pkt);
s32 forward_loopback_packet(s32 id, s32 unused, u8 *arr);
s32 release_loopback_slot(s16 id, u8 *addr);

/* Inline the helpers below; this applies to the rest of the file. */
#pragma dont_inline off
#pragma inline_depth(4)

s32 loopback_shutdown(void) {
    u8 unused[8];
    clear_table_entry_locked(network_loopback_state.handler);
    network_loopback_state.handler = -1;
    term_loopback_config(&network_loopback_state);
    network_loopback_state.slot_count = 0;
    return 0;
}

s16 init_loopback(void) {
    return register_loopback_handlers();
}

s16 register_loopback_handlers(void)
{
    NetLinkDriverFn tbl[11];
    u8* base;
    LoopbackState* p;
    s16 r;
    s16 i;
    s16* e;

    base = (u8*)&network_loopback_state;
    p = (LoopbackState*)base;
    tbl[0] = (NetLinkDriverFn)fill_reply_buffer;
    tbl[1] = (NetLinkDriverFn)alloc_conn_slot;
    tbl[2] = (NetLinkDriverFn)clear_conn_slot;
    tbl[3] = (NetLinkDriverFn)get_slot_offset_or_default;
    tbl[4] = (NetLinkDriverFn)loopback_get_address_length;
    tbl[5] = (NetLinkDriverFn)loopback_get_address;
    tbl[6] = (NetLinkDriverFn)loopback_update_address;
    tbl[7] = (NetLinkDriverFn)loopback_update_multicast;
    tbl[8] = (NetLinkDriverFn)release_loopback_slot;
    tbl[9] = (NetLinkDriverFn)forward_loopback_packet;
    tbl[10] = (NetLinkDriverFn)send_loopback_frame;

    r = register_link_handler(tbl, 1);
    if (r < 0) {
        return r;
    }
    init_net_recv_desc((LoopbackState *)base);
    p->handler = r;
    p->protos[0].used = 0;
    p->protos[0].type = 0;
    p->protos[1].used = 0;
    p->protos[1].type = 0;
    e = p->slot_used;
    i = 0;
    while (i < p->slot_count) {
        *e = 0;
        i++;
        e++;
    }
    return r;
}

s32 send_loopback_frame(s16 idx, s16 mode, u8 *addr, void *pkt) {
    LoopbackState *g = &network_loopback_state;
    u8 *slot;
    s16 len;
    s16 i;
    s16 *used;

    if (idx != 0 && idx != 1) {
        return -0x110;
    }
    len = link_packet_length(pkt);
    if (g->slot_size < len) {
        return -0x110;
    }
    used = g->slot_used;
    slot = g->slots;
    for (i = 0; i < g->slot_count; i++, used++) {
        if (*used == 0) {
            *used = 1;
            link_packet_copy(slot, pkt);
            link_input(slot, len, g->handler, idx, g->protos[idx].type);
            return 0;
        }
        slot += g->slot_size;
    }
    return -0x110;
}

s32 forward_loopback_packet(id, unused, arr)
    s16 id;
    s32 unused;
    u8 *arr;
{
    LoopbackState *p = &network_loopback_state;
    u8 *base;
    s16 len;
    s16 i;
    s16 *cnt;
    s16 sz;

    if (id != 0 && id != 1) {
        return -0x110;
    }
    len = link_packet_length(arr);
    if (p->slot_size < len) {
        return -0x110;
    }
    sz = p->slot_size;
    cnt = p->slot_used;
    base = p->slots;
    for (i = 0; i < p->slot_count; i++, cnt++) {
        if (*cnt == 0) {
            *cnt = 1;
            link_packet_copy(base, arr);
            link_input(base, len, p->handler, id, p->protos[id].type);
            return 0;
        }
        base += sz;
    }
    return -0x110;
}

s32 release_loopback_slot(s16 id, u8 *addr) {
    LoopbackState *p = &network_loopback_state;
    s16 size;
    s16 count;
    s16 i;
    s16 *used;
    s16 step;
    u8 *base;

    if (id != 0 && id != 1) {
        return -0x110;
    }
    used = p->slot_used;
    i = 0;
    base = p->slots;
    size = p->slot_size;
    count = p->slot_count;
    for (; i < count; i++, used++) {
        if (*used != 0 && base <= addr && addr < base + size) {
            *used = 0;
            return 0;
        }
        base += (step = size);
    }
    return -0x110;
}

s32 loopback_update_multicast(s16 idx) {
    if ((idx != 0) && (idx != 1)) {
        return -0x110;
    }
    return 0;
}

s32 loopback_update_address(s16 idx) {
    if ((idx != 0) && (idx != 1)) {
        return -0x110;
    }
    return 0;
}

s32 loopback_get_address(s16 idx) {
    if ((idx != 0) && (idx != 1)) {
        return -0x110;
    }
    return 0;
}

s32 loopback_get_address_length(s16 idx) {
    if ((idx != 0) && (idx != 1)) {
        return -0x110;
    }
    return 0;
}
s16 get_slot_offset_or_default(s16 idx) {
    if ((idx != 0) && (idx != 1)) {
        return -0x110;
    }
    return network_loopback_state.slot_size;
}

s32 clear_conn_slot(s16 i) {
    LoopbackState *g;
    if (i != 0 && i != 1) { return -0x110; }
    g = &network_loopback_state;
    g->protos[i].used = 0;
    g->protos[i].type = 0;
    return 0;
}

s16 alloc_conn_slot(s16 h, s16 v) {
    s16 r;
    LoopbackState *g = &network_loopback_state;
    if (h != g->handler) { return -0x110; }
    if (g->protos[0].used == 0) {
        r = 0;
    } else if (g->protos[1].used == 0) {
        r = 1;
    } else {
        return -0x110;
    }
    g->protos[r].used = 1;
    g->protos[r].type = v;
    return r;
}

s32 fill_reply_buffer(s16 h, u8 *p) {
    if (h != network_loopback_state.handler) { return -0x110; }
    p[0] = 0;
    *++p = 0;
    p[1] = 0;
    p[2] = 0;
    p[3] = 0;
    p[4] = 0;
    p[5] = 0;
    p[6] = 1;
    return 0;
}

LoopbackState network_loopback_state;
