#ifndef PSO_NETWORK_IPV6SEND_H
#define PSO_NETWORK_IPV6SEND_H

#include "types.h"
#include "pso/network/BufferRef.h"
#include "pso/network/IPv6.h"

typedef struct NetPacketFragment {
    s16 length;
    u8 padding_02[2];
    NetBufferRef buffer;
} NetPacketFragment;

typedef struct NetPacket {
    s16 in_use;
    u8 padding_02[2];
    u32 fragment_count;
    u32 total_bytes;
    NetPacketFragment fragments[12];
} NetPacket;

/* The packet records (alloc_free_entry, release_entry); TLobby__sub_803F8A0C sets the count and the array. */
typedef struct NetPacketPool {
    s16 count;
    u8 pad2[2];
    NetPacket *packets;         /* 0x04: in_use 1 = allocated */
} NetPacketPool;
typedef char NetPacketPool_size_check[sizeof(NetPacketPool) == 8 ? 1 : -1];
typedef char NetPacket_size_check[sizeof(NetPacket) == 0x9C ? 1 : -1];

typedef struct NetIPv6SendParameters {
    IPv6Address source;
    IPv6Address destination;
    u32 flow_label;
    u16 traffic_class_bits;
    u8 hop_limit;
    u8 next_header;
} NetIPv6SendParameters;

typedef struct NetLinkLayerAddressBuffer {
    u8 bytes[32];
} NetLinkLayerAddressBuffer;

typedef struct NetSourceLinkLayerOption {
    u8 type;
    u8 length_units;
    NetLinkLayerAddressBuffer address;
} NetSourceLinkLayerOption;

typedef struct NetIcmpv6Header {
    u8 type;
    u8 code;
    u16 checksum;
    u32 reserved;
} NetIcmpv6Header;

typedef struct NetIcmpv6NeighborSolicitation {
    NetIcmpv6Header header;
    IPv6Address target;
} NetIcmpv6NeighborSolicitation;

typedef struct NetIcmpv6RouterSolicitation {
    NetIcmpv6Header header;
} NetIcmpv6RouterSolicitation;

typedef struct NetIcmpv6RouterAdvertisement {
    u8 type;
    u8 code;
    u16 checksum;
    u8 cur_hop_limit;
    u8 flags;
    u16 router_lifetime; /* seconds */
    u32 reachable_time;  /* ms */
    u32 retrans_timer;   /* ms */
} NetIcmpv6RouterAdvertisement;

#endif
