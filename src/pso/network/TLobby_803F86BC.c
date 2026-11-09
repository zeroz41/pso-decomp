/* The network stack's configuration: the stack (a C library, built with GC/1.2.5n) calls these at start-up to
 * fill its configuration records with counts, sizes and the static buffers below. */
#include "types.h"
#include "pso/network/NetworkRuntime.h"
#include "pso/network/NetworkTransport.h"
#include "pso/network/TLobby_803F86BC.h"
#include <stddef.h>
#include "pso/network/netcfg.h"
#include "pso/network/IPv6.h"
#include "pso/network/TLobby_8041112C.h"
#include "pso/network/NetworkMessageTransport.h"

typedef struct Big_803F8AD8 {
    u8 pad0[0xB7A0];
    u8 bufB7A0[0x2FC0];
    u8 bufE760[0x30];
    u8 bufE790[0x10];
    void *funcs[7];
} Big_803F8AD8;

typedef struct Ent_803F8BA4 { u8 pad[0x31C]; s32 size; u8 *buf; u8 pad2[4]; } Ent_803F8BA4;

s32 lbl_805D7A58;
extern u8 *lobby_second_buffer_pool_base;

static u32 lobby_net_config_block[4722];
static Ipv6Header ipv6_interface_config;
static Ipv6RawSocket lbl_805B38A0[1];
static u32 lbl_805B38D4[50];
static u32 lbl_805B399C[99];
static u32 lbl_805B3B28[36];
static u32 lbl_805B3BB8[1267];
static s32 lbl_805B4F84[212];
static NetFragment lbl_805B52D4[0x10];
static NetFragPacket lbl_805B5454[2];
static s32 lbl_805B54BC[4096];
static NetBufferPoolEntry lbl_805B94BC[2];
static s32 lbl_805B9534[1059];
static s32 lbl_805BA5C0[3115];
static s32 lobby_net_recv_desc[641];

extern NetSizes lbl_805D7A50;

void TLobby__sub_803F86BC(void *cfg) {
}

void init_net_config(NetConfig *c) {
    u8 *buf = (u8 *)lobby_net_config_block;
    c->f0 = 0;
    c->f2 = 0x3F;
    c->f4 = 0xFF;
    c->f6 = 0x200;
    c->fA = 3;
    c->fC = &lbl_805D7A50;
    lbl_805D7A50.a = 2;
    lbl_805D7A50.b = 4;
    lbl_805D7A50.c = 8;
    c->f10 = 2;
    c->f14 = buf + 0x49A0;
    c->f1A = 6;
    c->f1C = 0x200;
    c->f20 = buf + 0x39A0;
    c->f24 = 8;
    c->f28 = buf + 0x3960;
    c->f2C = 0x20;
    c->f34 = buf + 0x3460;
    c->f2E = 0x10;
    c->f38 = buf + 0x13A0;
    c->f30 = 0x10;
    c->f3C = buf + 0x1E0;
    c->f40 = 8;
    c->f44 = buf;
}

void TLobby__sub_803F8794(void *cfg) {
}

void init_params(NetParamCfg *cfg) {
    cfg->count = net_param_room_count;
    cfg->f8 = lbl_805D4800;
    cfg->fC = lbl_805D4800;
    cfg->fA0 = 0x64;
    cfg->buffer = net_transport_buffer_ptr_b;
}

void TLobby__sub_803F87C4(void *cfg) {
}

void TLobby__sub_803F87C8(u8 *cfg) {
    *(s16 *)(cfg + 0) = net_param_player_count;
    *(s32 *)(cfg + 8) = net_transport_buffer_ptr_a;
}

void TLobby__sub_803F87DC(void *cfg) {
}

void init_ipv6_interface_config(Ipv6ProtocolState *cfg) {
    cfg->nsockets = 1;
    cfg->traffic_class = 0;
    cfg->flow_label = 0;
    cfg->hop_limit = 0x40;
    cfg->sockets = lbl_805B38A0;
    cfg->hdr = ipv6_interface_config;
}

void TLobby__sub_803F8864(void *cfg) {
}

/* Fills ipv6_address_routing_state. */
void init_udp_socket_config(Ipv6State *o) {
    o->route_count = 0x1A;
    o->count = 3;
    o->max_addrs = 9;
    o->pmtu_count = 9;
    o->dad_timer_init = 1;
    o->dad_interval = 1;
    o->dad_count_init = 1;
    o->rs_timer_init = 1;
    o->rs_interval = 1;
    o->rs_count_init = 2;
    o->pmtu_lifetime = 0x1E;
    o->min_mtu = 0x500;
    o->routes = (Ipv6Route *)lbl_805B3BB8;
    o->ifaces = (Ipv6Iface *)lbl_805B3B28;
    o->addr_pool = (Ipv6AddrNode *)lbl_805B399C;
    o->pmtu = (Ipv6PmtuEntry *)lbl_805B38D4;
}

void TLobby__sub_803F88E0(void *cfg) {
}

void init_buffer_descriptor_b(Ipv6NdState *cfg) {
    u8 *block;
    cfg->npending = 2;
    block = (u8 *)lobby_net_config_block;
    cfg->nneighbors = 8;
    cfg->nrouters = 8;
    cfg->mtu = 1500;
    cfg->pending = (Ipv6NdPending *)(block + 0x6064);
    cfg->neighbors = (Ipv6NdNeighbor *)(block + 0x5E24);
    cfg->routers = (Ipv6NdRouter *)(block + 0x5D04);
    cfg->buffers = (u8 *)lobby_net_config_block + 0x514C;
}

void TLobby__sub_803F892C(void *cfg) {
}

#pragma push
#pragma opt_common_subs on
void TLobby__sub_803F8930(u8 *cfg) {
    *(s16 *)(cfg + 0) = 1;
    *(s8 *)(cfg + 0xA) = 0;
    *(s8 *)(cfg + 0xB) = 0x78;
    *(s32 **)(cfg + 4) = lbl_805B4F84;
}
#pragma pop

void TLobby__sub_803F8958(void *cfg) {
}

void init_buffer_descriptor_a(NetBufDescA *cfg) {
    cfg->f0 = 0x1A;
    cfg->f2 = 3;
    cfg->f4 = 9;
    cfg->f6 = 0x240;
    cfg->f8 = (u8 *)lobby_net_config_block + 0x621C;
    cfg->fC = (u8 *)lobby_net_config_block + 0x61C8;
    cfg->f10 = (u8 *)lobby_net_config_block + 0x60F0;
}

void TLobby__sub_803F89A0(NetFragPool *cfg) {
}

void TLobby__sub_803F89A4(NetFragPool *cfg) {
    cfg->npackets = 2;
    cfg->nfrags = 0x10;
    cfg->max_frags = 8;
    cfg->packets = lbl_805B5454;
    cfg->frags = lbl_805B52D4;
}

void TLobby__sub_803F89D8(NetBufferPool *cfg) {
}

void init_buffer_desc_a(NetBufferPool *cfg) {
    cfg->count = 2;
    cfg->size = 0x2000;
    cfg->ents = lbl_805B94BC;
    cfg->data = (u8 *)lbl_805B54BC;
}

void TLobby__sub_803F8A08(void *cfg) {
}

void TLobby__sub_803F8A0C(u8 *cfg) {
    *(s16 *)(cfg + 0) = 5;
    *(s32 **)(cfg + 4) = lbl_805B9534;
}

void TLobby__sub_803F8A24(void *cfg) {
}

void init_net_buffer_config(NetBufferCfg *cfg) {
    cfg->f0 = 8;
    cfg->f2 = 3;
    cfg->f4 = 2;
    cfg->f6 = 0x5DC;
    cfg->f8 = 9;
    cfg->fA = 0x14;
    cfg->fC = 3;
    cfg->f10 = (u8 *)lobby_net_config_block + 0xB650;
    cfg->f14 = (u8 *)lobby_net_config_block + 0xB5F0;
    cfg->f1C = (u8 *)lobby_net_config_block + 0xB5D0;
    cfg->f18 = (u8 *)lobby_net_config_block + 0xB564;
    cfg->f20 = (u8 *)lobby_net_config_block + 0xA9AC;
    cfg->f24 = (u8 *)lobby_net_config_block + 0xA990;
}

void TLobby__sub_803F8A9C(void *cfg) {
}

void TLobby__sub_803F8AA0(u8 *cfg) {
    *(s16 *)(cfg + 0) = 3;
    *(s32 **)(cfg + 4) = lbl_805BA5C0;
}

void TLobby__sub_803F8AB8(void *cfg) {
    reset_message_thread();
}

void init_net_func_table(NetFuncTableCfg *cfg) {
    Big_803F8AD8 *g = (Big_803F8AD8 *)lobby_net_config_block;
    g->funcs[0] = (void *)TLobby__sub_80426B88;
    g->funcs[1] = (void *)open_channel_checked;
    g->funcs[2] = (void *)remove_rec_by_handle;
    g->funcs[3] = (void *)add_multicast_address;
    g->funcs[4] = (void *)consume_item_count_by_id;
    g->funcs[5] = (void *)get_local_address;
    g->funcs[6] = (void *)queue_timeout_message;
    cfg->a = 1;
    cfg->b = 1;
    cfg->c = 3;
    cfg->d = 8;
    cfg->funcs = g->funcs;
    cfg->x = g->bufE790;
    cfg->y = g->bufE760;
    cfg->z = g->bufB7A0;
}

void TLobby__sub_803F8B78(void *cfg) {
}

void init_net_recv_desc(LoopbackState *cfg) {
    cfg->slot_size = 0x500;
    cfg->slot_count = 2;
    cfg->slot_used = (s16 *)&lbl_805D7A58;
    cfg->slots = (u8 *)lobby_net_recv_desc;
}

u8 *layout_buffers(NetBufferLayout *h, u8 *p, u8 *end) {
    LobbyBufferSlot *e;
    Ent_803F8BA4 *f;
    s32 i;
    u16 n = h->n2;
    lobby_thread_pool_count = 2;
    lobby_buffer_slot_count = n * 2;
    if (h->a != 0) {
        lobby_thread_pool_count += 1;
    }
    if (h->b != 0) {
        lobby_thread_pool_count += 2;
    }
    lobby_buffer_slots = (LobbyBufferSlot *)p;
    p += lobby_buffer_slot_count * 12;
    if (p > end) {
        return NULL;
    }
    e = lobby_buffer_slots;
    for (i = 0; i < lobby_buffer_slot_count; i++, e++) {
        e->active = 0;
        e->size = h->c;
        e->addr = (u32)p;
        p += h->c;
        if (p > end) {
            return NULL;
        }
    }
    *(u8 **)&lobby_thread_pool_base = p;
    p += lobby_thread_pool_count * 0x328;
    if (p > end) {
        return NULL;
    }
    f = *(Ent_803F8BA4 **)&lobby_thread_pool_base;
    for (i = 0; i < lobby_thread_pool_count; i++, f++) {
        f->size = h->d;
        f->buf = p;
        p += h->d;
        if (p > end) {
            return NULL;
        }
    }
    if (h->f != 0) {
        lobby_buffer_pool_base = p;
        p += h->f;
        if (p > end) {
            return NULL;
        }
        lobby_second_buffer_pool_base = p;
        p += h->f;
        if (p > end) {
            return NULL;
        }
        lobby_buffer_pool_size = h->f;
    }
    if (h->g != 0) {
        lbl_805D7C04 = p;
        p += h->g;
        if (p > end) {
            return NULL;
        }
        lbl_805D7C08 = h->g;
    }
    return p;
}

s32 TLobby__sub_803F8D24(NetBufferLayout *h) {
    s32 n = 2;
    s32 size;
    if (h->a != 0) {
        n = 3;
    }
    if (h->b != 0) {
        n += 2;
    }
    size = (h->d + 0x328) * n;
    size += (h->c + 12) * h->n2 * 2;
    size += h->f * 2;
    size += h->g;
    return size;
}

void TLobby__sub_803F8D84(u32 key) {
    LobbyBufferSlot *e = lobby_buffer_slots;
    s32 i;
    for (i = 0; i < lobby_buffer_slot_count; i++) {
        if (e->addr == key) {
            e->active = 0;
            return;
        }
        e++;
    }
}

s32 alloc_buffer_slot(s32 size) {
    LobbyBufferSlot *e = lobby_buffer_slots;
    s32 i;
    s32 r = 0;
    for (i = 0; i < lobby_buffer_slot_count; i++) {
        if (e->active == 0 && e->size >= size) {
            e->active = size;
            r = e->addr;
            break;
        }
        e++;
    }
    return r;
}
