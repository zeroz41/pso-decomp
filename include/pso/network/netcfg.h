#ifndef PSO_NETWORK_NETCFG_H
#define PSO_NETWORK_NETCFG_H
/* The network stack's configuration (src/pso/network/NetConfig.c). The stack is a C library built with
 * GC/1.2.5n, separate from the game's C++: each function here fills one of its configuration records with
 * counts, sizes and static buffers. Record and field names are ours (no symbols survive). */
#include "types.h"
#include <stddef.h>
#include "pso/network/NetworkTransport.h"

#ifdef __cplusplus
extern "C" {
#endif

struct DnsResolverState;
struct UdpRuntimeState;
struct Ipv4ProtocolState;
struct TcpState;

/* A link-layer driver, registered by insert_link_handler from 11 functions: loopback (register_loopback_handlers,
   always entry 0), PPP (ppp_link_init) and Ethernet (init_net_sockets).  Each function is called by one
   dispatcher (named after the slot); get_lladdr_len..multicast_ctl only when flags & 4. */
typedef struct LobbyHandler {
    s16 active;
    s16 flags;                                     /* 0x02: as registered: 1 loopback, 2 PPP, 0x7C Ethernet */
    s16 (*get_interface_id)(s16 idx, void *dst);   /* 0x04: link_get_interface_id */
    s16 (*open)(s16 idx, u32 a, s16 b, u32 *c);    /* 0x08: link_attach_protocol; opens a channel for an EtherType */
    s32 (*close)(s16);                             /* 0x0C: call_entry_callback; frees the channel */
    s16 (*get_mtu)(s32);                           /* 0x10: invoke_socket_callback; Ethernet 1500 */
    s16 (*get_lladdr_len)(s32);                    /* 0x14: link_get_address_length; Ethernet 6 */
    s32 (*get_lladdr)(s32, void *);                /* 0x18: link_get_address; copies the MAC */
    s16 (*alias_ctl)(s32, s32, void *);            /* 0x1C: link_update_address; 1 adds, 2 removes an ARP alias */
    s16 (*multicast_ctl)(s32, s32, void *);        /* 0x20: link_update_multicast; 1 joins, 2 leaves a multicast group */
    s32 (*release_frame)(s32, s32);                /* 0x24: dispatch_handler_by_id; frees a received frame; link_input calls it
                                                      as void (s16, s32) */
    s16 (*forward)(s32, void *, void *);           /* 0x28: dispatch_handler_by_index; sends an IPv4 packet to a
                                                      unicast next hop (ppp_link_forward_packet, forward_loopback_packet) */
    s16 (*output)(s32, s32, void *, void *);       /* 0x2C: call_handler_by_index */
} LobbyHandler;
LAYOUT_ASSERT(LobbyHandler_size_check, sizeof(LobbyHandler) == 0x30);

typedef struct LobbyHandlerTable {
    s16 count;
    LobbyHandler *list;
} LobbyHandlerTable;
LAYOUT_ASSERT(LobbyHandlerTable_size_check, sizeof(LobbyHandlerTable) == 8);
LAYOUT_ASSERT(LobbyHandlerTable_list_offset, offsetof(LobbyHandlerTable, list) == 4);


void term_dns_config(void *cfg);
void init_net_config(struct DnsResolverState *cfg);
void term_tcp_config(struct TcpState *cfg);
void init_params(struct TcpState *cfg);
void term_udp_config(void *cfg);
void init_udp_control_config(struct UdpRuntimeState *cfg);
void term_ipv6_config(void *cfg);
struct Ipv6ProtocolState;
void init_ipv6_interface_config(struct Ipv6ProtocolState *cfg);
void term_ipv6_routing_config(void *cfg);
struct Ipv6State;
void init_udp_socket_config(struct Ipv6State *cfg);
void term_ipv6_nd_config(void *cfg);
struct Ipv6NdState;
void init_buffer_descriptor_b(struct Ipv6NdState *cfg);
void term_ipv4_config(void *cfg);
void init_ipv4_raw_socket_config(struct Ipv4ProtocolState *cfg);
void term_ipv4_routing_config(void *cfg);
struct Ipv4RoutingState;
void init_buffer_descriptor_a(struct Ipv4RoutingState *cfg);
struct NetFragPool;
void term_fragment_config(struct NetFragPool *cfg);
void init_fragment_pool_config(struct NetFragPool *cfg);
struct NetBufferPool;
void term_buffer_pool_config(struct NetBufferPool *cfg);
void init_buffer_desc_a(struct NetBufferPool *cfg);
void term_packet_pool_config(void *cfg);
struct NetPacketPool;
void init_packet_pool_config(struct NetPacketPool *cfg);
void term_arp_config(void *cfg);
struct ArpState;
void init_net_buffer_config(struct ArpState *cfg);
void term_handler_table_config(void *cfg);
void init_handler_table_config(LobbyHandlerTable *cfg);
void term_dix_config(void *cfg);
struct EthernetState;
void init_net_func_table(struct EthernetState *cfg);
void term_loopback_config(void *cfg);
struct LoopbackState;
void init_net_recv_desc(struct LoopbackState *cfg);
u8 *layout_buffers(NetTransportParams *h, u8 *p, u8 *end);
s32 calc_work_area_size(NetTransportParams *h);
void free_buffer_slot(u32 key);
s32 alloc_buffer_slot(s32 size);

#ifdef __cplusplus
}
#endif

#endif
