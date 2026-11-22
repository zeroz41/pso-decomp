#ifndef PSO_NETWORK_NETIPV6NEIGHBORDISCOVERY_H
#define PSO_NETWORK_NETIPV6NEIGHBORDISCOVERY_H

#include "types.h"
#include "pso/network/IPv6Send.h"
#include "pso/network/TLobby_8041112C.h"

/* ICMPv6 type 0x88. flags: 0x80 router, 0x40 solicited, 0x20 override. */
typedef struct NetIcmpv6NeighborAdvertisement {
    u8 type;
    u8 code;
    u16 checksum;
    u8 flags;
    u8 reserved[3];
    IPv6Address target;
} NetIcmpv6NeighborAdvertisement;
LAYOUT_ASSERT(NetIcmpv6NeighborAdvertisement_size_check, sizeof(NetIcmpv6NeighborAdvertisement) == 0x18);

/* ICMPv6 type 0x89. */
typedef struct NetIcmpv6Redirect {
    NetIcmpv6Header header;
    IPv6Address target;
    IPv6Address destination;
} NetIcmpv6Redirect;
LAYOUT_ASSERT(NetIcmpv6Redirect_size_check, sizeof(NetIcmpv6Redirect) == 0x28);

/* The record neighbour discovery passes to TLobby__sub_80411604 for events 1, 6, 7, 8 and 9. Event 7 (a router went
   away) removes the route through addr and adds a default route through next_router; the others read addr only. */
typedef struct Ipv6NdAddrEvent {
    u8 *addr;
    u8 *next_router;
} Ipv6NdAddrEvent;
LAYOUT_ASSERT(Ipv6NdAddrEvent_size_check, sizeof(Ipv6NdAddrEvent) == 8);

/* Event 3: a router advertisement's current hop limit. */
typedef struct Ipv6NdHopLimitEvent {
    u8 *router;
    u8 hop_limit;
} Ipv6NdHopLimitEvent;
LAYOUT_ASSERT(Ipv6NdHopLimitEvent_size_check, sizeof(Ipv6NdHopLimitEvent) == 8);

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
LAYOUT_ASSERT(Ipv6NdPrefixInfoOption_size_check, sizeof(Ipv6NdPrefixInfoOption) == 0x20);

/* Neighbour discovery option 5 (MTU, 8 bytes). */
typedef struct Ipv6NdMtuOption {
    u8 type;
    u8 length;
    u16 reserved;
    s32 mtu;
} Ipv6NdMtuOption;
LAYOUT_ASSERT(Ipv6NdMtuOption_size_check, sizeof(Ipv6NdMtuOption) == 8);

/* Event 2: a prefix information option, passed on to TLobby__sub_80412618. */
typedef struct Ipv6NdPrefixEvent {
    u8 *prefix;
    s16 prefix_len;
    u32 preferred_lifetime;
    u32 valid_lifetime;
} Ipv6NdPrefixEvent;
LAYOUT_ASSERT(Ipv6NdPrefixEvent_size_check, sizeof(Ipv6NdPrefixEvent) == 0x10);

/* Event 4: an MTU option; TLobby__sub_80411604 stores mtu in the interface. */
typedef struct Ipv6NdMtuEvent {
    u8 *router;
    s32 mtu;
} Ipv6NdMtuEvent;
LAYOUT_ASSERT(Ipv6NdMtuEvent_size_check, sizeof(Ipv6NdMtuEvent) == 8);

s16 NetIPv6SendRouterSolicitation(s16 iface);
s16 NetIPv6ParseRedirectOptions(NetPacketFragment *frag, s32 n, NetIcmpv6Redirect *msg, s32 opts, s16 *optlen, s16 iface);
s16 NetIPv6ApplyNeighborAdvertisement(NetIcmpv6NeighborAdvertisement *msg, u8 *lladdr, s16 lladdr_len, s32 src, s32 address,
                                      s16 iface);
s16 TLobby__sub_80417494(NetIcmpv6RouterAdvertisement *ra, u8 *src, s16 iface);
s16 TLobby__sub_80417868(NetPacketFragment *opts, u32 len, u8 *src, s16 iface);
s16 NetIPv6SendMulticastNeighborProbe(Ipv6NdNeighbor *e);
s16 NetIPv6SendUnicastNeighborProbe(Ipv6NdNeighbor *e);
Ipv6NdNeighbor *TLobby__sub_804182DC(void *addr, void *lladdr, s16 lladdr_len, s16 iface);
Ipv6NdNeighbor *NetIPv6FindOrSelectNeighborCacheEntry(u8 *addr, u8 *key, s16 klen);
Ipv6NdRouter *NetIPv6SelectDefaultRouter(void *addr);
Ipv6NdPending *NetIPv6SelectPendingPacketSlot(void);

#endif
