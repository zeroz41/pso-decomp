#include "pso/network/NetworkRuntimeSlots.h"
/* The network stack's configuration: the stack (a C library, built with GC/1.2.5n) calls these at start-up to
 * fill its configuration records with counts, sizes and the static buffers below. */
#include "types.h"
#include "pso/network/NetworkRuntime.h"
#include "pso/network/UdpRuntime.h"
#include "pso/network/NetworkTransport.h"
#include "pso/network/TLobby_803F86BC.h"
#include <stddef.h>
#include "pso/network/netcfg.h"
#include "pso/network/IPv6.h"
#include "pso/network/NetDns.h"
#include "pso/network/NetArp.h"
#include "pso/network/NetIpv4.h"
#include "pso/network/NetEthernet.h"
#include "pso/network/TLobby_804050DC.h"
#include "pso/network/TLobby_8041112C.h"
#include "pso/network/NetworkMessageTransport.h"

typedef struct Big_803F8AD8 {
    u8 pad0[0xB7A0];
    EthFrameSlot eth_slots[8];  /* 0xB7A0 */
    EthSocket eth_sockets[3];   /* 0xE760 */
    EthLink eth_link;           /* 0xE790 */
    EthDriver bba;              /* 0xE7A0 */
} Big_803F8AD8;


/* The start-up parameters AT_SetInitParam stores (one per NetTransportParams field) with their
 * defaults, and the thread priority NetSetDefaultThreadPriority sets. */
s16 net_param_a = 1;
u16 net_param_player_count = 8;
u16 net_param_room_count = 8;
s32 net_param_word_e = 0x2000;
s16 net_param_b = 1;
s32 net_param_word_f = 0x2000;
s32 net_param_ring_buffer_size = 0x2000;
s32 net_default_thread_priority = 0x10;

/* CodeWarrior emits these .sbss globals in reverse order of definition. */
NetworkThreadSlot *lobby_thread_pool_base;
u16 lobby_thread_pool_count;
LobbyBufferSlot *lobby_buffer_slots;
u16 lobby_buffer_slot_count;
s32 lbl_805D7A5C;
s32 lbl_805D7A58;
s16 dns_resolver_timeouts[3];
u32 net_param_word_i;
u32 net_param_word_h;
u32 net_transport_buffer_ptr_b;
u32 net_transport_buffer_ptr_a;
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
static u8 lbl_805B54BC[0x4000] ATTRIBUTE_ALIGN(4);
static NetBufferPoolEntry lbl_805B94BC[2];
static s32 lbl_805B9534[1059];
static s32 lbl_805BA5C0[3115];
static s32 lobby_net_recv_desc[641];

void TLobby__sub_803F86BC(void *cfg) {
}

void init_net_config(DnsResolverState *c) {
    u8 *buf = (u8 *)lobby_net_config_block;
    c->next_id = 0;
    c->f2 = 0x3F;
    c->max_name = 0xFF;
    c->msg_size = 0x200;
    c->ntimeouts = 3;
    c->timeouts = dns_resolver_timeouts;
    dns_resolver_timeouts[0] = 2;
    dns_resolver_timeouts[1] = 4;
    dns_resolver_timeouts[2] = 8;
    c->nservers = 2;
    c->servers = (NetworkAddress *)(buf + 0x49A0);
    c->max_tries = 6;
    c->buffer_size = 0x200;
    c->buffer_base = buf + 0x39A0;
    c->nbuffers = 8;
    c->buffers = (DnsBuffer *)(buf + 0x3960);
    c->naddrs = 0x20;
    c->addrs = (DnsAddr *)(buf + 0x3460);
    c->nhosts = 0x10;
    c->hosts = (DnsHost *)(buf + 0x13A0);
    c->nptrs = 0x10;
    c->ptrs = (DnsPtr *)(buf + 0x1E0);
    c->nqueries = 8;
    c->queries = (DnsQuery *)buf;
}

void TLobby__sub_803F8794(void *cfg) {
}

void init_params(NetParamCfg *cfg) {
    cfg->count = net_param_room_count;
    cfg->f8 = net_param_word_e;
    cfg->fC = net_param_word_e;
    cfg->fA0 = 0x64;
    cfg->buffer = net_transport_buffer_ptr_b;
}

void TLobby__sub_803F87C4(void *cfg) {
}

void TLobby__sub_803F87C8(UdpRuntimeState *cfg) {
    cfg->count = net_param_player_count;
    cfg->entries = (UdpControlBlock *)net_transport_buffer_ptr_a;
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
void TLobby__sub_803F8930(Ipv4ProtocolState *cfg) {
    cfg->nsockets = 1;
    cfg->def_tos = 0;
    cfg->def_ttl = 0x78;
    cfg->sockets = (Ipv4RawSocket *)lbl_805B4F84;
}
#pragma pop

void TLobby__sub_803F8958(void *cfg) {
}

void init_buffer_descriptor_a(Ipv4RoutingState *cfg) {
    cfg->nroutes = 0x1A;
    cfg->nifaces = 3;
    cfg->max_aliases = 9;
    cfg->min_mtu = 0x240;
    cfg->routes = (Ipv4Route *)((u8 *)lobby_net_config_block + 0x621C);
    cfg->ifaces = (Ipv4Iface *)((u8 *)lobby_net_config_block + 0x61C8);
    cfg->alias_pool = (Ipv4Alias *)((u8 *)lobby_net_config_block + 0x60F0);
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
    cfg->data = lbl_805B54BC;
}

void TLobby__sub_803F8A08(void *cfg) {
}

void TLobby__sub_803F8A0C(NetPacketPool *cfg) {
    cfg->count = 5;
    cfg->packets = (NetPacket *)lbl_805B9534;
}

void TLobby__sub_803F8A24(void *cfg) {
}

void init_net_buffer_config(ArpState *cfg) {
    cfg->nentries = 8;
    cfg->nifaces = 3;
    cfg->nholds = 2;
    cfg->hold_size = 0x5DC;
    cfg->naliases = 9;
    cfg->timeout = 0x14;
    cfg->retry = 3;
    cfg->entries = (ArpEntry *)((u8 *)lobby_net_config_block + 0xB650);
    cfg->ifaces = (ArpIface *)((u8 *)lobby_net_config_block + 0xB5F0);
    cfg->holds = (ArpHold *)((u8 *)lobby_net_config_block + 0xB5D0);
    cfg->aliases = (ArpAlias *)((u8 *)lobby_net_config_block + 0xB564);
    cfg->hold_buffers = (u8 *)lobby_net_config_block + 0xA9AC;
    cfg->packet = (u8 *)lobby_net_config_block + 0xA990;
}

void TLobby__sub_803F8A9C(void *cfg) {
}

void TLobby__sub_803F8AA0(LobbyHandlerTable *cfg) {
    cfg->count = 3;
    cfg->list = (struct LobbyHandler *)lbl_805BA5C0;
}

void TLobby__sub_803F8AB8(void *cfg) {
    reset_message_thread();
}

void init_net_func_table(EthernetState *cfg) {
    Big_803F8AD8 *g = (Big_803F8AD8 *)lobby_net_config_block;
    g->bba.init = (s16 (*)(s16))TLobby__sub_80426B88;
    g->bba.open = (s16 (*)(s16, u16))open_channel_checked;
    g->bba.close = remove_rec_by_handle;
    g->bba.add_multicast = add_multicast_address;
    g->bba.remove_multicast = consume_item_count_by_id;
    g->bba.get_address = (s16 (*)(s16, void *))get_local_address;
    g->bba.send = queue_timeout_message;
    cfg->ndrivers = 1;
    cfg->nlinks = 1;
    cfg->nsockets = 3;
    cfg->nslots = 8;
    cfg->drivers = &g->bba;
    cfg->links = &g->eth_link;
    cfg->sockets = g->eth_sockets;
    cfg->slots = g->eth_slots;
}

void TLobby__sub_803F8B78(void *cfg) {
}

void init_net_recv_desc(LoopbackState *cfg) {
    cfg->slot_size = 0x500;
    cfg->slot_count = 2;
    cfg->slot_used = (s16 *)&lbl_805D7A58;
    cfg->slots = (u8 *)lobby_net_recv_desc;
}

u8 *layout_buffers(NetTransportParams *h, u8 *p, u8 *end) {
    LobbyBufferSlot *e;
    NetworkThreadSlot *f;
    s32 i;
    u16 n = h->room_count;
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
        e->size = h->e;
        e->addr = (uaddr)p;
        p += h->e;
        if (p > end) {
            return NULL;
        }
    }
    lobby_thread_pool_base = (NetworkThreadSlot *)p;
    p += lobby_thread_pool_count * sizeof(NetworkThreadSlot);
    if (p > end) {
        return NULL;
    }
    f = lobby_thread_pool_base;
    for (i = 0; i < lobby_thread_pool_count; i++, f++) {
        f->stack_size = h->f;
        f->stack = p;
        p += h->f;
        if (p > end) {
            return NULL;
        }
    }
    if (h->h != 0) {
        lobby_buffer_pool_base = p;
        p += h->h;
        if (p > end) {
            return NULL;
        }
        lobby_second_buffer_pool_base = p;
        p += h->h;
        if (p > end) {
            return NULL;
        }
        lobby_buffer_pool_size = h->h;
    }
    if (h->i != 0) {
        lbl_805D7C04 = p;
        p += h->i;
        if (p > end) {
            return NULL;
        }
        lbl_805D7C08 = h->i;
    }
    return p;
}

s32 TLobby__sub_803F8D24(NetTransportParams *h) {
    s32 n = 2;
    s32 size;
    if (h->a != 0) {
        n = 3;
    }
    if (h->b != 0) {
        n += 2;
    }
    size = (h->f + 0x328) * n;
    size += (h->e + 12) * h->room_count * 2;
    size += h->h * 2;
    size += h->i;
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
