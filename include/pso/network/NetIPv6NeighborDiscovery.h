#ifndef PSO_NETWORK_NETIPV6NEIGHBORDISCOVERY_H
#define PSO_NETWORK_NETIPV6NEIGHBORDISCOVERY_H

#include "types.h"
#include "pso/network/IPv6Send.h"

/* ICMPv6 type 0x88. flags: 0x80 router, 0x40 solicited, 0x20 override. */
typedef struct NetIcmpv6NeighborAdvertisement {
    u8 type;
    u8 code;
    u16 checksum;
    u8 flags;
    u8 reserved[3];
    IPv6Address target;
} NetIcmpv6NeighborAdvertisement;
typedef char NetIcmpv6NeighborAdvertisement_size_check[sizeof(NetIcmpv6NeighborAdvertisement) == 0x18 ? 1 : -1];

/* ICMPv6 type 0x89. */
typedef struct NetIcmpv6Redirect {
    NetIcmpv6Header header;
    IPv6Address target;
    IPv6Address destination;
} NetIcmpv6Redirect;
typedef char NetIcmpv6Redirect_size_check[sizeof(NetIcmpv6Redirect) == 0x28 ? 1 : -1];

/* The record neighbour discovery passes to TLobby__sub_80411604 for events 1, 6, 7, 8 and 9. Event 7 (a router went
   away) removes the route through addr and adds a default route through next_router; the others read addr only. */
typedef struct Ipv6NdAddrEvent {
    u8 *addr;
    u8 *next_router;
} Ipv6NdAddrEvent;
typedef char Ipv6NdAddrEvent_size_check[sizeof(Ipv6NdAddrEvent) == 8 ? 1 : -1];

/* Event 3: a router advertisement's current hop limit. */
typedef struct Ipv6NdHopLimitEvent {
    u8 *router;
    u8 hop_limit;
} Ipv6NdHopLimitEvent;
typedef char Ipv6NdHopLimitEvent_size_check[sizeof(Ipv6NdHopLimitEvent) == 8 ? 1 : -1];

/* Neighbour discovery option 3 (prefix information, 32 bytes): a router advertisement's on-link prefix. */
typedef struct Ipv6NdPrefixInfoOption {
    u8 type;
    u8 length;
    u8 prefix_len;
    u8 flags;
    s32 valid_lifetime;
    s32 preferred_lifetime;
    u8 reserved[4];
    IPv6Address prefix;
} Ipv6NdPrefixInfoOption;
typedef char Ipv6NdPrefixInfoOption_size_check[sizeof(Ipv6NdPrefixInfoOption) == 0x20 ? 1 : -1];

/* Neighbour discovery option 5 (MTU, 8 bytes). */
typedef struct Ipv6NdMtuOption {
    u8 type;
    u8 length;
    u16 reserved;
    s32 mtu;
} Ipv6NdMtuOption;
typedef char Ipv6NdMtuOption_size_check[sizeof(Ipv6NdMtuOption) == 8 ? 1 : -1];

/* Event 2: a prefix information option, passed on to TLobby__sub_80412618. */
typedef struct Ipv6NdPrefixEvent {
    u8 *prefix;
    s16 prefix_len;
    s32 preferred_lifetime;
    s32 valid_lifetime;
} Ipv6NdPrefixEvent;
typedef char Ipv6NdPrefixEvent_size_check[sizeof(Ipv6NdPrefixEvent) == 0x10 ? 1 : -1];

/* Event 4: an MTU option; TLobby__sub_80411604 stores mtu in the interface. */
typedef struct Ipv6NdMtuEvent {
    u8 *router;
    s32 mtu;
} Ipv6NdMtuEvent;
typedef char Ipv6NdMtuEvent_size_check[sizeof(Ipv6NdMtuEvent) == 8 ? 1 : -1];

#endif
