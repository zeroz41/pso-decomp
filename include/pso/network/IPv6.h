#ifndef PSO_NETWORK_IPV6_H
#define PSO_NETWORK_IPV6_H

#include "types.h"
#include <stddef.h>

typedef struct IPv6Address {
    u8 bytes[16];
} IPv6Address;

typedef struct IPv6NeighborSolicitation {
    u8 header[8];
    IPv6Address target;
} IPv6NeighborSolicitation;

typedef char IPv6Address_size_check[(sizeof(IPv6Address) == 16) ? 1 : -1];
typedef char IPv6NeighborSolicitation_size_check[
    (sizeof(IPv6NeighborSolicitation) == 24) ? 1 : -1];
typedef char IPv6NeighborSolicitation_target_check[
    (offsetof(IPv6NeighborSolicitation, target) == 8) ? 1 : -1];

/* ipv6_address_routing_state and its tables (TLobby_8041112C.c). */
typedef struct Ipv6AddrNode Ipv6AddrNode;
struct Ipv6AddrNode {
    s16 in_use;
    u8 addr[16];
    s16 prefix_len;
    s16 state;
    s16 f16;
    s16 f18;
    s16 scope;
    s16 dad_count;
    s16 dad_timer;
    u32 valid_lifetime;
    u32 preferred_lifetime;
    Ipv6AddrNode *next;
};
typedef char Ipv6AddrNode_size_check[sizeof(Ipv6AddrNode) == 0x2C ? 1 : -1];
typedef struct Ipv6Route {
    s16 state;
    s16 type;
    s16 f4;
    s16 iface;
    u8 prefix[16];
    u8 gateway[16];
    s16 prefix_len;
} Ipv6Route;
typedef char Ipv6Route_size_check[sizeof(Ipv6Route) == 0x2A ? 1 : -1];
typedef struct Ipv6Iface {
    s16 state;
    s16 handle;
    u8 addr[16];
    s16 prefix_len;
    s16 dad_state;
    s16 f18;
    s16 f1A;
    s16 scope;
    s16 dad_count;
    s16 dad_timer;
    s16 rs_count;
    s16 rs_timer;
    s16 mtu;
    void *f28;
    Ipv6AddrNode *addrs;
} Ipv6Iface;
typedef char Ipv6Iface_size_check[sizeof(Ipv6Iface) == 0x30 ? 1 : -1];
typedef struct Ipv6PmtuEntry {
    s16 state;
    IPv6Address addr;
    s16 mtu;
    s16 timer;
} Ipv6PmtuEntry;
typedef char Ipv6PmtuEntry_size_check[sizeof(Ipv6PmtuEntry) == 0x16 ? 1 : -1];
typedef struct Ipv6State {
    s16 route_count;
    s16 count;
    s16 max_addrs;
    s16 dad_timer_init;
    s16 dad_count_init;
    s16 dad_interval;
    s16 rs_timer_init;
    s16 rs_count_init;
    s16 rs_interval;
    s16 min_mtu;
    s16 pmtu_count;
    s16 pmtu_lifetime;
    Ipv6Route *routes;
    Ipv6Iface *ifaces;
    Ipv6AddrNode *addr_pool;
    Ipv6PmtuEntry *pmtu;
} Ipv6State;
typedef char Ipv6State_size_check[sizeof(Ipv6State) == 0x28 ? 1 : -1];
#ifdef __cplusplus
extern "C" {
#endif
extern Ipv6State ipv6_address_routing_state;
/* The MTU of interface `iface`. */
s16 get_iface_mtu(s16 iface);
#ifdef __cplusplus
}
#endif

#endif
