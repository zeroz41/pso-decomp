#ifndef PSO_NETWORK_NETIPV4_H
#define PSO_NETWORK_NETIPV4_H
/* IPv4 routing (ipv4_address_routing_state, src/pso/network/TLobby_804050DC.c): the routing table, the interfaces and
 * their extra addresses. init_buffer_descriptor_a sets the counts and the arrays. */
#include "types.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Another address of an interface (from Ipv4RoutingState.alias_pool). */
typedef struct Ipv4Alias Ipv4Alias;
struct Ipv4Alias {
    s16 f0;
    u8 pad2[2];
    u32 addr;
    u32 broadcast;
    u32 network;
    u32 mask;
    Ipv4Alias *next;
};
LAYOUT_ASSERT(Ipv4Alias_size_check, sizeof(Ipv4Alias) == 0x18);
/* An interface IPv4 runs on (AT_IP4_IfUp brings it up, bring_down_ipv4_interface down). */
typedef struct Ipv4Iface {
    s16 state;                  /* 1 = up */
    s16 handle;                 /* 0x02: the link's IPv4 socket (EtherType 0x800) */
    s16 mtu;                    /* 0x04 */
    u8 pad6[2];
    u32 addr;
    u32 broadcast;
    u32 network;
    u32 mask;
    Ipv4Alias *aliases;
} Ipv4Iface;
LAYOUT_ASSERT(Ipv4Iface_size_check, sizeof(Ipv4Iface) == 0x1C);
/* A routing table entry. */
typedef struct Ipv4Route {
    u16 flags;
    s16 iface;
    u32 dst;
    u32 mask;
    u32 gateway;
    s16 f10;
    s16 type;
} Ipv4Route;
LAYOUT_ASSERT(Ipv4Route_size_check, sizeof(Ipv4Route) == 0x14);
typedef struct Ipv4RoutingState {
    s16 nroutes;
    s16 nifaces;
    s16 max_aliases;
    s16 min_mtu;                /* 0x06: an interface with a smaller MTU is refused */
    Ipv4Route *routes;
    Ipv4Iface *ifaces;
    Ipv4Alias *alias_pool;
    u8 pad14[4];
} Ipv4RoutingState;
LAYOUT_ASSERT(Ipv4RoutingState_size_check, sizeof(Ipv4RoutingState) == 0x18);
extern Ipv4RoutingState ipv4_address_routing_state;

#ifdef __cplusplus
}
#endif

#endif
