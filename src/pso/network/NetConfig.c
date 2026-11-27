#include "pso/network/NetworkRuntimeSlots.h"
/* The network stack's configuration: the stack (a C library, built with GC/1.2.5n) calls these at start-up to
 * fill its configuration records with counts, sizes and the static buffers below. */
#include "types.h"
#include "pso/network/NetworkRuntime.h"
#include "pso/network/UdpRuntime.h"
#include "pso/network/NetworkTransport.h"
#include "pso/network/NetConfig.h"
#include "pso/network/ModemSession.h"
#include <stddef.h>
#include "pso/network/netcfg.h"
#include "pso/network/NetTcpState.h"
#include "pso/network/IPv6.h"
#include "pso/network/NetDns.h"
#include "pso/network/NetArp.h"
#include "pso/network/NetIpv4.h"
#include "pso/network/NetEthernet.h"
#include "pso/network/NetStack.h"
#include "pso/network/NetIpv6Route.h"
#include "pso/network/NetworkMessageTransport.h"



/* The start-up parameters AT_SetInitParam stores (one per NetTransportParams field) with their
 * defaults, and the thread priority NetSetDefaultThreadPriority sets. */
s16 net_param_with_ethernet = 1;
u16 net_param_udp_socket_count = 8;
u16 net_param_tcp_socket_count = 8;
s32 net_param_tcp_buffer_size = 0x2000;
s16 net_param_with_ppp = 1;
s32 net_param_thread_stack_size = 0x2000;
s32 net_param_ring_buffer_size = 0x2000;
s32 net_default_thread_priority = 0x10;

/* CodeWarrior emits these .sbss globals in reverse order of definition. */
NetworkThreadSlot *lobby_thread_pool_base;
u16 lobby_thread_pool_count;
LobbyBufferSlot *lobby_buffer_slots;
u16 lobby_buffer_slot_count;
s32 lbl_805D7A5C;
s16 loopback_slot_used[2];
s16 dns_resolver_timeouts[3];
u32 net_param_modem_ring_size;
u32 net_param_buffer_pool_size;
void *net_tcp_socket_storage;
void *net_udp_socket_storage;

static DnsQuery dns_queries[8];
static DnsPtr dns_ptrs[16];
static DnsHost dns_hosts[16];
static DnsAddr dns_addrs[32];
static DnsBuffer dns_buffers[8];
static u8 dns_buffer_data[8 * 0x200];
static NetworkAddress dns_servers[2];
static Ipv6Header ipv6_interface_config;
static Ipv6RawSocket ipv6_raw_sockets[1];
static Ipv6PmtuEntry ipv6_pmtu_storage[9];
static Ipv6AddrNode ipv6_addr_pool_storage[9];
static Ipv6Iface ipv6_iface_storage[3];
static Ipv6Route ipv6_route_storage[0x1A];
static u8 ipv6_nd_buffers[2 * 1500];
static Ipv6NdRouter ipv6_nd_routers[8];
static Ipv6NdNeighbor ipv6_nd_neighbors[8];
static Ipv6NdPending ipv6_nd_pending[2];
static Ipv4RawSocket ipv4_raw_sockets[1];
static Ipv4Alias ipv4_alias_pool[9];
static Ipv4Iface ipv4_iface_storage[3];
static Ipv4Route ipv4_routes[0x1A];
static NetFragment ip_fragments[0x10];
static NetFragPacket ip_frag_packets[2];
static u8 net_buffer_pool_data[0x4000] ATTRIBUTE_ALIGN(4);
static NetBufferPoolEntry net_buffer_pool_entries[2];
static NetPacket net_packets[5];
static u8 arp_packet[0x1C];
static u8 arp_hold_buffers[2 * 0x5DC];
static ArpAlias arp_aliases[9];
static ArpHold arp_holds[2];
static ArpIface arp_ifaces[3];
static ArpEntry arp_entries[8];
static LobbyHandler lobby_handlers[3];
static EthFrameSlot eth_slots[8];
static EthSocket eth_sockets[3];
static EthLink eth_link;
static EthDriver eth_driver;
static u8 loopback_slots[2 * 0x500];

void term_dns_config(DnsResolverState *cfg) {
}

void init_net_config(DnsResolverState *c) {
    c->next_id = 0;
    c->max_label = 0x3F;
    c->max_name = 0xFF;
    c->msg_size = 0x200;
    c->ntimeouts = 3;
    c->timeouts = dns_resolver_timeouts;
    dns_resolver_timeouts[0] = 2;
    dns_resolver_timeouts[1] = 4;
    dns_resolver_timeouts[2] = 8;
    c->nservers = 2;
    c->servers = dns_servers;
    c->max_tries = 6;
    c->buffer_size = 0x200;
    c->buffer_base = dns_buffer_data;
    c->nbuffers = 8;
    c->buffers = dns_buffers;
    c->naddrs = 0x20;
    c->addrs = dns_addrs;
    c->nhosts = 0x10;
    c->hosts = dns_hosts;
    c->nptrs = 0x10;
    c->ptrs = dns_ptrs;
    c->nqueries = 8;
    c->queries = dns_queries;
}

void term_tcp_config(TcpState *cfg) {
}

void init_params(TcpState *cfg) {
    cfg->count = net_param_tcp_socket_count;
    cfg->snd_bufsize = net_param_tcp_buffer_size;
    cfg->rcv_bufsize = net_param_tcp_buffer_size;
    cfg->ack_ticks = 0x64;
    cfg->tcbs = net_tcp_socket_storage;
}

void term_udp_config(UdpRuntimeState *cfg) {
}

void init_udp_control_config(UdpRuntimeState *cfg) {
    cfg->count = net_param_udp_socket_count;
    cfg->entries = net_udp_socket_storage;
}

void term_ipv6_config(Ipv6ProtocolState *cfg) {
}

void init_ipv6_interface_config(Ipv6ProtocolState *cfg) {
    cfg->nsockets = 1;
    cfg->traffic_class = 0;
    cfg->flow_label = 0;
    cfg->hop_limit = 0x40;
    cfg->sockets = ipv6_raw_sockets;
    cfg->hdr = ipv6_interface_config;
}

void term_ipv6_routing_config(Ipv6State *cfg) {
}

/* Fills ipv6_address_routing_state. */
void init_udp_socket_config(Ipv6State *cfg) {
    cfg->route_count = 0x1A;
    cfg->count = 3;
    cfg->max_addrs = 9;
    cfg->pmtu_count = 9;
    cfg->dad_timer_init = 1;
    cfg->dad_interval = 1;
    cfg->dad_count_init = 1;
    cfg->rs_timer_init = 1;
    cfg->rs_interval = 1;
    cfg->rs_count_init = 2;
    cfg->pmtu_lifetime = 0x1E;
    cfg->min_mtu = 0x500;
    cfg->routes = ipv6_route_storage;
    cfg->ifaces = ipv6_iface_storage;
    cfg->addr_pool = ipv6_addr_pool_storage;
    cfg->pmtu = ipv6_pmtu_storage;
}

void term_ipv6_nd_config(Ipv6NdState *cfg) {
}

void init_buffer_descriptor_b(Ipv6NdState *cfg) {
    cfg->npending = 2;
    cfg->nneighbors = 8;
    cfg->nrouters = 8;
    cfg->mtu = 1500;
    cfg->pending = ipv6_nd_pending;
    cfg->neighbors = ipv6_nd_neighbors;
    cfg->routers = ipv6_nd_routers;
    cfg->buffers = ipv6_nd_buffers;
}

void term_ipv4_config(Ipv4ProtocolState *cfg) {
}

#pragma push
#pragma opt_common_subs on
void init_ipv4_raw_socket_config(Ipv4ProtocolState *cfg) {
    cfg->nsockets = 1;
    cfg->def_tos = 0;
    cfg->def_ttl = 0x78;
    cfg->sockets = ipv4_raw_sockets;
}
#pragma pop

void term_ipv4_routing_config(Ipv4RoutingState *cfg) {
}

void init_buffer_descriptor_a(Ipv4RoutingState *cfg) {
    cfg->nroutes = 0x1A;
    cfg->nifaces = 3;
    cfg->max_aliases = 9;
    cfg->min_mtu = 0x240;
    cfg->routes = ipv4_routes;
    cfg->ifaces = ipv4_iface_storage;
    cfg->alias_pool = ipv4_alias_pool;
}

void term_fragment_config(NetFragPool *cfg) {
}

void init_fragment_pool_config(NetFragPool *cfg) {
    cfg->npackets = 2;
    cfg->nfrags = 0x10;
    cfg->max_frags = 8;
    cfg->packets = ip_frag_packets;
    cfg->frags = ip_fragments;
}

void term_buffer_pool_config(NetBufferPool *cfg) {
}

void init_buffer_desc_a(NetBufferPool *cfg) {
    cfg->count = 2;
    cfg->size = 0x2000;
    cfg->ents = net_buffer_pool_entries;
    cfg->data = net_buffer_pool_data;
}

void term_packet_pool_config(NetPacketPool *cfg) {
}

void init_packet_pool_config(NetPacketPool *cfg) {
    cfg->count = 5;
    cfg->packets = net_packets;
}

void term_arp_config(ArpState *cfg) {
}

void init_net_buffer_config(ArpState *cfg) {
    cfg->nentries = 8;
    cfg->nifaces = 3;
    cfg->nholds = 2;
    cfg->hold_size = 0x5DC;
    cfg->naliases = 9;
    cfg->timeout = 0x14;
    cfg->retry = 3;
    cfg->entries = arp_entries;
    cfg->ifaces = arp_ifaces;
    cfg->holds = arp_holds;
    cfg->aliases = arp_aliases;
    cfg->hold_buffers = arp_hold_buffers;
    cfg->packet = arp_packet;
}

void term_handler_table_config(LobbyHandlerTable *cfg) {
}

void init_handler_table_config(LobbyHandlerTable *cfg) {
    cfg->count = 3;
    cfg->list = lobby_handlers;
}

void term_dix_config(EthernetState *cfg) {
    reset_message_thread();
}

void init_net_func_table(EthernetState *cfg) {
    eth_driver.init = open_ethernet_device;
    eth_driver.open = open_channel_checked;
    eth_driver.close = remove_rec_by_handle;
    eth_driver.add_multicast = add_multicast_address;
    eth_driver.remove_multicast = consume_item_count_by_id;
    eth_driver.get_address = get_local_address;
    eth_driver.send = queue_timeout_message;
    cfg->ndrivers = 1;
    cfg->nlinks = 1;
    cfg->nsockets = 3;
    cfg->nslots = 8;
    cfg->drivers = &eth_driver;
    cfg->links = &eth_link;
    cfg->sockets = eth_sockets;
    cfg->slots = eth_slots;
}

void term_loopback_config(LoopbackState *cfg) {
}

void init_net_recv_desc(LoopbackState *cfg) {
    cfg->slot_size = 0x500;
    cfg->slot_count = 2;
    cfg->slot_used = loopback_slot_used;
    cfg->slots = loopback_slots;
}

u8 *layout_buffers(NetTransportParams *h, u8 *p, u8 *end) {
    LobbyBufferSlot *e;
    NetworkThreadSlot *f;
    s32 i;
    u16 n = h->tcp_socket_count;
    lobby_thread_pool_count = 2;
    lobby_buffer_slot_count = n * 2;
    if (h->with_ethernet != 0) {
        lobby_thread_pool_count += 1;
    }
    if (h->with_ppp != 0) {
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
        e->size = h->tcp_buffer_size;
        e->addr = (uaddr)p;
        p += h->tcp_buffer_size;
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
        f->stack_size = h->thread_stack_size;
        f->stack = p;
        p += h->thread_stack_size;
        if (p > end) {
            return NULL;
        }
    }
    if (h->buffer_pool_size != 0) {
        lobby_buffer_pool_base = p;
        p += h->buffer_pool_size;
        if (p > end) {
            return NULL;
        }
        lobby_second_buffer_pool_base = p;
        p += h->buffer_pool_size;
        if (p > end) {
            return NULL;
        }
        lobby_buffer_pool_size = h->buffer_pool_size;
    }
    if (h->modem_ring_size != 0) {
        lobby_modem_ring_base = p;
        p += h->modem_ring_size;
        if (p > end) {
            return NULL;
        }
        lobby_modem_ring_size = h->modem_ring_size;
    }
    return p;
}

s32 calc_work_area_size(NetTransportParams *h) {
    s32 n = 2;
    s32 size;
    if (h->with_ethernet != 0) {
        n = 3;
    }
    if (h->with_ppp != 0) {
        n += 2;
    }
    size = (h->thread_stack_size + 0x328) * n;
    size += (h->tcp_buffer_size + 12) * h->tcp_socket_count * 2;
    size += h->buffer_pool_size * 2;
    size += h->modem_ring_size;
    return size;
}

void free_buffer_slot(u32 key) {
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

saddr alloc_buffer_slot(s32 size) {
    LobbyBufferSlot *e = lobby_buffer_slots;
    s32 i;
    saddr r = 0;
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
