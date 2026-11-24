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
#include "pso/network/NetEthernet.h"

/* TLobby_804050DC.c: connection records, the DNS resolver tables and socket start-up. */
typedef struct Ipv4RawSocket Ipv4RawSocket;
typedef struct Ipv4ProtocolState Ipv4ProtocolState;
typedef struct N_80405298 N_80405298;
typedef struct In_8040D95C In_8040D95C;
typedef struct Out_8040D95C Out_8040D95C;
typedef void (*Fn_8040881C)(void); /* a link-layer driver entry (NetHandlerTable.c) */
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
struct N_80405298 { N_80405298 *next; s32 f4; u8 pad8[0x18 - 8]; u8 b18; };
struct In_8040D95C { s32 type; s32 f4; };
struct Out_8040D95C { s32 type; u32 f4; };
#ifdef __cplusplus
extern "C" {
#endif

u16 calc_ip_checksum(NetPacket *packet, s16 flag);
s16 run_connect_step(void);
void flush_flags_step(void);
s16 init_net_tables(void);
s32 clear_all_used_records(void);
s32 close_connection_by_index(s16 i);
NetPacket *alloc_free_entry(void);
void release_entry(NetPacket *pkt);
s32 call_entry_callback(s16 i, s16 arg);
s16 call_handler_by_index(s16 arg0, s32 arg1, s32 detail, s32 first, s32 second);
s32 clear_table_entry_locked(s16 arg0);
void init_net_block_18A0(void);
s16 invoke_socket_callback(s16 i, s32 arg);
s16 is_entry_flag10_set(s16 i);
s16 is_slot_flag_0x20_set(s16 i);
s16 is_slot_flag_0x40_set(s16 i);
void process_expired_timers(void);
s32 run_net_init_step(void);
s32 shutdown_network_handle(void);
s16 is_socket_flag_set(s16 i);
s16 TLobby__sub_8040A044(s16 idx, u32 a, s16 b, u32 *c);
void TLobby__sub_804050DC(s16 arg0);
s32 TLobby__sub_804062A0(s16 arg0);
s16 TLobby__sub_80406624(s32 a, s32 b, u16 code, PppFrame *frame);
s16 reset_network_timer_list(void);
s16 arp_resolve_and_send(s16 idx, void *name, void *arg2);
s32 TLobby__sub_80409AA8(void);
s16 NetIPv4IsBroadcast(u32 arg0, s16 arg1);
void lobby_timer_start(u8 *arg0);
s16 ipv4_iface_for_address(u32 ip);
s32 TLobby__sub_8040DD68(void);
s32 shutdown_ipv4_routing(void);
s32 NetIPv6Shutdown(void);
s16 TLobby__sub_80409A3C(Fn_8040881C *fns, s16 kind);
void lobby_timer_stop(void *arg0);
s16 AT_IP_GetMssFromDstSrc(u8 *remote, u8 *local);
void netbuf_copy_by_ref(void *a, void *b, s32 v);
s16 TLobby__sub_80410BA8(NetPacket *packet, NetIPv6SendParameters *params, s16 iface, u8 *link_address);
u16 calc_ipv6_pseudo_header_checksum(const struct IPv6Address *src, const struct IPv6Address *dst, u8 next_header, const struct NetPacket *pkt, s16 flag);
void lobby_timer_add(N_80405298 *o, s32 v);
void TLobby__sub_80409818(s32 msg, s16 len, s16 idx, s16 second, u16 type);
s32 TLobby__sub_80408388(s16 id);
s16 TLobby__sub_804098B4(void *pkt);
s32 TLobby__sub_80409908(void *self, void *arr_);
u8 *netbuf_ref_data(void *self);
s16 TLobby__sub_80406328(saddr self, s16 type);
s16 dispatch_handler_by_index(s16 id, s32 arg1, s32 arg2, s32 arg3);
s16 dispatch_by_addr_family(NetPacket *pkt, NetworkAddress *dst, NetworkAddress *src, u8 *ip4_opts, void *ip6_opts, u8 proto);
s16 AT_IP_SetSrcFromDst(Out_8040D95C *arg0, In_8040D95C *arg1);
s16 is_multicast_address(NetworkAddress *addr, s16 arg1);
s16 is_addr_unspecified(u8 *arg0);
s16 AT_IP4_IsReachable(u32 ipv4, u32 arg1);
s16 TLobby__sub_8040DA54(u8 *dst, u8 *src);
s16 AT_IP4_Send(NetPacket *pkt, u32 dst, u32 src, u8 ttl, u8 tos, u8 df, u8 proto);
s16 AT_IP4_Forward(u32 dst, u32 src, u8 *pkt, s16 len, s16 iface);
s16 AT_IP4_PktSend(NetPacket *self, u32 key, s16 id);
s16 AT_IP4_SrcAddrSel(u32 *out, u32 dst, s16 c);
s16 TLobby__sub_80410A98(NetPacket *pkt, void *dst, void *src, NetIPv6SendOptions *opts, u8 proto);
extern NetPacketPool lobby_udp_socket_table;
/* Shared by the modules cut out of this unit; each is defined in the file named in its comment. */
u16 packet_ones_complement_sum(struct NetPacket *, s16); /* TLobby_804050DC.c */
s32 dispatch_slot_a(s16, s32);                       /* NetArp.c */
s32 dispatch_slot_b(s16, s32);                       /* NetArp.c */
s16 forward_net_op(s16, u8 *, u8 *);                 /* NetArp.c */
s16 *get_active_entry_by_index(s16);                 /* NetIpv4Route.c */
Ipv4Route *AT_IP4_RouteSearch(u32, u32);             /* NetIpv4Route.c */
s16 NetIPv4IsInterfaceUp(s16);                       /* NetIpv4Route.c */
s16 TLobby__sub_8040FEE4(s32, s32);                  /* NetIpv4Route.c */
s16 get_ipv4_interface_mtu(s16);                       /* NetIpv4Route.c */
/* Point the routes through old_gateway that cover dst/mask at new_gateway (an ICMP redirect). */
s32 TLobby__sub_8040F8A4(u32 dst, u32 new_gateway, u32 mask, u32 flags, u32 old_gateway); /* NetIpv4Route.c */
/* ARP (src/pso/network/NetArp.c). */
s32 TLobby__sub_80407418(s16 id);
s16 forward_net_op_5args(s16, s16, s16, s16, s16, s32, s16, s32);
/* The handler table (src/pso/network/NetHandlerTable.c). */
s16 TLobby__sub_80409CE0(s16 idx, s32 handle, s32 op, void *addr);
s16 TLobby__sub_80409D7C(s16 idx, s32 handle, s32 op, void *addr);
s16 TLobby__sub_8040A0C0(s16 idx, void *dst);
s32 TLobby__sub_80409E18(s16, s32, s32);
s16 TLobby__sub_80409EB0(s16, s32);
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
