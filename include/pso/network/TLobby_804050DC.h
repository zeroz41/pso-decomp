#ifndef PSO_NETWORK_TLOBBY_804050DC_H
#define PSO_NETWORK_TLOBBY_804050DC_H

#include "types.h"
#include "pso/network/NetworkReceiveCallback.h"
#include "pso/network/BufferRef.h"
#include "pso/network/UdpRuntime.h"
#include "pso/network/IPv6.h"
#include "pso/network/IPv6Send.h"
#include "pso/network/NetDns.h"
#include "pso/network/NetArp.h"
#include "pso/network/NetIpv4.h"
#include "pso/network/IPv4Header.h"
#include "pso/network/PppFsm.h"
#include "pso/network/NetEthernet.h"

/* TLobby_804050DC.c: connection records, the DNS resolver tables and socket start-up. */
typedef struct Ipv4RawSocket Ipv4RawSocket;
typedef struct Ipv4ProtocolState Ipv4ProtocolState;
typedef void (*NetLinkDriverFn)(void); /* one of the 11 entries of a link-layer driver (NetHandlerTable.c) */
/* A raw IPv4 socket: ipv4_input hands it every packet of its protocol. */
struct Ipv4RawSocket {
    u8 tag[3];                  /* 0x00: "IP4" */
    u8 index;
    u16 state;                  /* 0x04: 1 = open */
    u8 pad6[2];
    u32 addr;                   /* 0x08: source filter; 0 = any */
    u8 padC[4];
    NetworkReceiveCallback callback;             /* 0x10 */
    u8 pad14[4];
    u8 proto;                   /* 0x18 */
    u8 pad19[3];
};
struct Ipv4ProtocolState {
    s16 nsockets;
    u8 pad2[2];
    Ipv4RawSocket *sockets;
    u16 id;                     /* 0x08: next IP identification */
    u8 def_tos;
    u8 def_ttl;
    IPv4Header hdr;             /* 0x0C: header template of AT_IP4_Send */
    u8 pad20[8];
};
#ifdef __cplusplus
extern "C" {
#endif

u16 calc_ip_checksum(NetPacket *packet, s16 flag);
s16 dix_init(void);
void dix_term(void);
s16 dns_init(void);
s32 dns_clear_server(void);
s32 dns_close(s16 i);
NetPacket *alloc_free_entry(void);
void release_entry(NetPacket *pkt);
s32 call_entry_callback(s16 i, s16 arg);
s16 call_handler_by_index(s16 idx, s32 handle, s32 mode, s32 addr, s32 pkt);
s32 clear_table_entry_locked(s16 idx);
void init_net_block_18A0(void);
s16 invoke_socket_callback(s16 i, s32 arg);
s16 is_entry_flag10_set(s16 i);
s16 is_slot_flag_0x20_set(s16 i);
s16 is_slot_flag_0x40_set(s16 i);
void process_expired_timers(void);
s32 run_net_init_step(void);
s32 shutdown_network_handle(void);
s16 is_socket_flag_set(s16 i);
s16 link_attach_protocol(s16 idx, u32 a, s16 b, u32 *c);
void set_net_poll_interval(s16 poll_ms);
s32 ppp_link_event(s16 command);
s16 ppp_output_protocol(s32 a, s32 b, u16 code, PppFrame *frame);
s16 reset_network_timer_list(void);
s16 arp_resolve_and_send(s16 idx, void *name, void *pkt);
s32 handler_table_term(void);
s16 NetIPv4IsBroadcast(u32 address, s16 iface);
void lobby_timer_start(PppFsmTimer *timer);
s16 ipv4_iface_for_address(u32 ip);
s32 ipv4_term(void);
s32 shutdown_ipv4_routing(void);
s32 NetIPv6Shutdown(void);
s16 reset_socket_table(void);
s16 NetTCPInit(void);
s32 tcp_term(void);
s16 init_packet_fragment_pools(void);
s32 fragment_term(void);
s16 init_ipv4_interfaces(void);
s16 init_ipv4_routing(void);
s16 NetIPv6Init(void);
s16 NetIPv6InitRouting(void);
s32 NetIPv6ShutdownRouting(void);
s16 NetIPv6InitNeighborDiscovery(void);
void NetIPv6ShutdownNeighborDiscovery(void);
s16 handler_table_init(void);
s16 register_link_handler(NetLinkDriverFn *fns, s16 kind);
void lobby_timer_stop(PppFsmTimer *timer);
s16 AT_IP_GetMssFromDstSrc(NetworkAddress *remote, NetworkAddress *local);
void netbuf_copy_by_ref(NetBufferRef *a, void *b, s32 v);
s16 ipv6_transmit(NetPacket *packet, NetIPv6SendParameters *params, s16 iface, u8 *link_address);
u16 calc_ipv6_pseudo_header_checksum(const struct IPv6Address *src, const struct IPv6Address *dst, u8 next_header, const struct NetPacket *pkt, s16 flag);
void lobby_timer_add(PppFsmTimer *timer, s32 period);
void link_input(s32 msg, s16 len, s16 idx, s16 second, u16 type);
s32 arp_free_interface(s16 id);
s16 link_packet_length(void *pkt);
s32 link_packet_copy(void *self, void *arr_);
u8 *netbuf_ref_data(NetBufferRef *self);
s16 ppp_output_datagram(saddr self, s16 type);
s16 dispatch_handler_by_index(s16 idx, s32 handle, s32 addr, s32 pkt);
s16 dispatch_by_addr_family(NetPacket *pkt, NetworkAddress *dst, NetworkAddress *src, u8 *ip4_opts, void *ip6_opts, u8 proto);
s16 AT_IP_SetSrcFromDst(NetworkAddress *src, NetworkAddress *dst);
s16 is_multicast_address(NetworkAddress *addr, s16 iface);
s16 is_addr_unspecified(NetworkAddress *addr);
s16 AT_IP4_IsReachable(u32 dst, u32 src);
s16 AT_IP_IsReachable(NetworkAddress *dst, NetworkAddress *src);
u16 calc_transport_checksum(NetworkAddress *src, NetworkAddress *dst, s8 proto, NetPacket *pkt, s16 flag);
s16 AT_IP4_Send(NetPacket *pkt, u32 dst, u32 src, u8 ttl, u8 tos, u8 df, u8 proto);
s16 AT_IP4_Forward(u32 dst, u32 src, u8 *pkt, s16 len, s16 iface);
s16 AT_IP4_PktSend(NetPacket *self, u32 key, s16 id);
s16 AT_IP4_SrcAddrSel(u32 *out, u32 dst, s16 c);
s16 ipv6_output(NetPacket *pkt, void *dst, void *src, NetIPv6SendOptions *opts, u8 proto);
extern NetPacketPool lobby_udp_socket_table;
/* Shared by the modules cut out of this unit; each is defined in the file named in its comment. */
u16 packet_ones_complement_sum(struct NetPacket *, s16); /* TLobby_804050DC.c */
s32 dispatch_slot_a(s16, s32);                       /* NetArp.c */
s32 dispatch_slot_b(s16, s32);                       /* NetArp.c */
s16 forward_net_op(s16, u8 *, u8 *);                 /* NetArp.c */
s16 *get_active_entry_by_index(s16);                 /* NetIpv4Route.c */
Ipv4Route *AT_IP4_RouteSearch(u32 dst, u32 src);     /* NetIpv4Route.c */
s16 NetIPv4IsInterfaceUp(s16);                       /* NetIpv4Route.c */
s16 compare_ipv4_addr(s32, s32);                  /* NetIpv4Route.c */
s16 get_ipv4_interface_mtu(s16);                       /* NetIpv4Route.c */
/* Point the routes through old_gateway that cover dst/mask at new_gateway (an ICMP redirect). */
s32 route4_redirect(u32 dst, u32 new_gateway, u32 mask, u32 flags, u32 old_gateway); /* NetIpv4Route.c */
/* ARP (src/pso/network/NetArp.c). */
s32 unregister_arp_interface(s16 id);
s16 forward_net_op_5args(s16 handler, s16 socket, s16 htype, s16 ptype, s16 hlen, s32 haddr, s16 plen, s32 paddr);
/* The handler table (src/pso/network/NetHandlerTable.c). */
s16 link_update_multicast(s16 idx, s32 handle, s32 op, void *addr);
s16 link_update_address(s16 idx, s32 handle, s32 op, void *addr);
s16 link_get_interface_id(s16 idx, void *dst);
s32 link_get_address(s16, s32, s32);
s16 link_get_address_length(s16, s32);
/* ICMP (src/pso/network/NetIcmp.c). */
s16 icmp_input(u8 *self, u32 d, u32 c);
s16 icmp_send_error(u8 *p, u8 *b, s16 x, s16 id);
u16 ones_complement_sum(void *data, s16 n);
/* ICMPv6 (src/pso/network/NetIcmp6.c). */
s16 NetIPv6HandleIcmpMessage(struct NetPacket *pkt, u8 *src, u8 *dst, u8 hop_limit, s16 iface);
s16 icmp6_send_error(void *a, u8 *src, s16 c, s16 flag);
/* IPv6 input (src/pso/network/NetIpv6.c). */
s16 ipv6_process_options(u8 *p, s16 n, u8 *self, s16 c, s16 d);
s16 ipv6_forward(u8 *self, u8 *p, s16 lim, s16 ctx);
#ifdef __cplusplus
}
#endif

#endif
