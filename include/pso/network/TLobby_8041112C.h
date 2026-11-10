#ifndef PSO_NETWORK_TLOBBY_8041112C_H
#define PSO_NETWORK_TLOBBY_8041112C_H

#include "types.h"
#include "pso/network/IPv6Send.h"
#include "pso/network/UdpRuntime.h"

/* TLobby_8041112C.c: IPv6 neighbour discovery, routing and packet fragments. */
typedef struct RecoveredFields_804143BC_arg0 RecoveredFields_804143BC_arg0;
typedef struct Ipv6NdPending Ipv6NdPending;
typedef struct Ipv6NdNeighbor Ipv6NdNeighbor;
typedef struct Ipv6NdRouter Ipv6NdRouter;
typedef struct Ipv6NdState Ipv6NdState;
typedef struct NetFragment NetFragment;
typedef struct NetFragPacket NetFragPacket;
typedef struct NetFragPool NetFragPool;
/* network_loopback_state: the loopback interface; init_net_recv_desc fills 0x0A-0x17. */
typedef struct LoopbackProto {
    s16 used;
    u16 type;
} LoopbackProto;
typedef struct LoopbackState {
    s16 handler;             /* 0x00: dispatcher handler id */
    LoopbackProto protos[2]; /* 0x02 */
    s16 slot_size;           /* 0x0A */
    s16 slot_count;          /* 0x0C */
    u8 padE[2];
    s16 *slot_used;          /* 0x10 */
    u8 *slots;               /* 0x14: slot_count slots of slot_size bytes */
} LoopbackState;
typedef char LoopbackState_size_check[sizeof(LoopbackState) == 0x18 ? 1 : -1];
/* network_buffer_pool_state: init_buffer_desc_a fills 0x00-0x0B.  A NetBufferRef of kind 2 names a segment as
   (entry << 24) + (segment << 16) + offset into it. */
typedef struct NetBufferSegment {
    s16 owner;  /* 0: unused, -1: free */
    u16 offset; /* in the entry's buffer */
    u16 len;
} NetBufferSegment;
typedef struct NetBufferPoolEntry {
    u8 *buf;                  /* 0x00 */
    s32 free_segs;            /* 0x04 */
    s32 free_bytes;           /* 0x08 */
    NetBufferSegment segs[8]; /* 0x0C */
} NetBufferPoolEntry;
typedef struct NetBufferPool {
    s16 count;                /* 0x00 */
    s16 size;                 /* 0x02: bytes per entry */
    NetBufferPoolEntry *ents; /* 0x04 */
    u8 *data;                 /* 0x08: count buffers of size bytes */
    u8 padC[4];
} NetBufferPool;
typedef char NetBufferPoolEntry_size_check[sizeof(NetBufferPoolEntry) == 0x3C ? 1 : -1];
typedef char NetBufferPool_size_check[sizeof(NetBufferPool) == 0x10 ? 1 : -1];
struct RecoveredFields_804143BC_arg0 {
    u8 field_0;
    u8 field_1;
};
/* A packet queued until its next hop's link-layer address is known (tag "PEN"). */
struct Ipv6NdPending {
    u8 tag[3];
    u8 used;
    s16 ttl;                      /* 0x04: counted down while the neighbour is resolved; the lowest is reused first */
    u8 pad6[2];
    NetIPv6SendParameters params; /* 0x08 */
    s16 len;                      /* 0x30 */
    u8 pad32[2];
    u8 *data;                     /* 0x34: a buffer of Ipv6NdState.mtu bytes */
};
/* A neighbour cache entry (tag "NCE"). */
struct Ipv6NdNeighbor {
    u8 tag[3];
    u8 used;
    s16 nud;                /* 0x04: 0 incomplete, 1 reachable, 2 stale, 3 delay, 4 probe */
    s16 match;              /* 0x06: set by NetIPv6FindOrSelectNeighborCacheEntry: 0 free entry, 1 reused entry,
                               2 found with another link-layer address, 3 found with the same one */
    s16 iface;              /* 0x08 */
    s16 timer;              /* 0x0A: seconds left in this state */
    u8 flags;               /* 0x0C: 0x80 = the neighbour is a router */
    u8 padD[3];
    Ipv6NdPending *pending; /* 0x10 */
    s16 probes;             /* 0x14 */
    u8 addr[0x10];          /* 0x16 */
    s16 lladdr_len;         /* 0x26 */
    u8 lladdr[0x20];        /* 0x28 */
};
/* A default router list entry (tag "DLE"). */
struct Ipv6NdRouter {
    u8 tag[3];
    u8 used;
    s16 iface;          /* 0x04 */
    s16 uses;           /* 0x06: times NetIPv6SelectDefaultRouter returned it */
    s16 lifetime;       /* 0x08: seconds */
    u8 padA[2];
    s32 reachable_time; /* 0x0C: ms, from the router advertisement */
    s32 retrans_timer;  /* 0x10: ms, from the router advertisement */
    u8 addr[0x10];      /* 0x14 */
};
/* ipv6_neighbor_discovery_state: init_buffer_descriptor_b fills 0x00-0x1B and
   NetIPv6ApplyNeighborDiscoveryDefaults the rest (times in seconds). */
struct Ipv6NdState {
    s16 npending;              /* 0x00 */
    s16 nneighbors;            /* 0x02 */
    s16 nrouters;              /* 0x04 */
    u8 pad6[2];
    Ipv6NdPending *pending;    /* 0x08 */
    Ipv6NdNeighbor *neighbors; /* 0x0C */
    Ipv6NdRouter *routers;     /* 0x10 */
    s16 mtu;                   /* 0x14: size of each pending packet buffer */
    u8 pad16[2];
    u8 *buffers;               /* 0x18: npending buffers of mtu bytes */
    s16 max_multicast_solicit; /* 0x1C */
    s16 max_unicast_solicit;   /* 0x1E */
    s16 max_anycast_delay;     /* 0x20 */
    s16 max_neighbor_adverts;  /* 0x22 */
    s16 stale_time;            /* 0x24: also the largest timer value */
    s16 reachable_time;        /* 0x26 */
    s16 retrans_timer;         /* 0x28 */
    s16 retrans_ticks;         /* 0x2A: retrans_timer + 1 */
    s16 delay_first_probe;     /* 0x2C */
    u8 pad2E[2];
};
typedef char Ipv6NdPending_size_check[sizeof(Ipv6NdPending) == 0x38 ? 1 : -1];
typedef char Ipv6NdNeighbor_size_check[sizeof(Ipv6NdNeighbor) == 0x48 ? 1 : -1];
typedef char Ipv6NdRouter_size_check[sizeof(Ipv6NdRouter) == 0x24 ? 1 : -1];
typedef char Ipv6NdState_size_check[sizeof(Ipv6NdState) == 0x30 ? 1 : -1];
/* A received fragment (tag "FRG"). */
struct NetFragment {
    u8 tag[3];
    s8 index;
    s16 used;          /* 0x04 */
    u8 pad6[2];
    NetBufferRef data; /* 0x08 */
    u16 offset;        /* 0x10: in 8-byte units */
    u16 len;           /* 0x12 */
    NetFragment *next; /* 0x14: in offset order */
};
/* A datagram being reassembled (tag "FPK"). */
struct NetFragPacket {
    u8 tag[3];
    s8 index;
    s16 used;            /* 0x04 */
    u8 pad6[2];
    NetworkAddress src;  /* 0x08 */
    u32 ident;           /* 0x1C */
    u16 hdr_len;         /* 0x20: bytes before the fragmentable part, from the first fragment */
    u8 ttl;              /* 0x22: seconds left */
    u8 have_last;        /* 0x23: the fragment without the more-fragments flag has arrived */
    s16 iface;           /* 0x24 */
    u8 pad26[2];
    NetFragPacket *next; /* 0x28 */
    NetFragment *first;  /* 0x2C */
    NetFragment *last;   /* 0x30 */
};
/* packet_fragment_pool_state: TLobby__sub_803F89A4 fills 0x00-0x0F. */
struct NetFragPool {
    s16 npackets;           /* 0x00 */
    s16 nfrags;             /* 0x02 */
    s16 max_frags;          /* 0x04: fragments per datagram */
    u8 pad6[2];
    NetFragPacket *packets; /* 0x08 */
    NetFragment *frags;     /* 0x0C */
    NetFragPacket *head;    /* 0x10: datagrams being reassembled */
    NetFragPacket *tail;    /* 0x14 */
};
typedef char NetFragment_size_check[sizeof(NetFragment) == 0x18 ? 1 : -1];
typedef char NetFragPacket_size_check[sizeof(NetFragPacket) == 0x34 ? 1 : -1];
typedef char NetFragPool_size_check[sizeof(NetFragPool) == 0x18 ? 1 : -1];

#ifdef __cplusplus
extern "C" {
#endif
extern LoopbackState network_loopback_state;
extern NetBufferPool network_buffer_pool_state;
extern Ipv6NdState ipv6_neighbor_discovery_state;
extern NetFragPool packet_fragment_pool_state;
s16 alloc_conn_slot(s16 h, s16 v);
s32 clear_conn_slot(s16 i);
s32 fill_reply_buffer(s16 h, u8 *p);
s16 get_slot_offset_or_default(s16 arg0);
s16 *get_valid_entry(s16 arg0);
s32 reset_net_value(void);
s32 reset_other_connection_lists(void *obj);
s32 TUdpSocket__sub_80418BD8(NetPacket *a);
void tick_entry_timers(void);
void update_timeout_entries(void);
void NetIPv6ApplyNeighborDiscoveryDefaults(Ipv6NdState *nd);
s16 TLobby__sub_80413230(u8 *arg0, s32 arg1);
s32 TLobby__sub_804136AC(s16 i);
void TLobby__sub_804136CC(s16 i);
s16 NetIPv6IsLoopback(u8 *arg0);
s16 NetIPv6IsUnspecified(u8 *arg0);
s32 NetIPv6CompareAddresses(s32 arg0, s32 arg1);
s16 TLobby__sub_8041510C(void);
void TLobby__sub_804150EC(void);
void TLobby__sub_8041615C(void);
void NetIPv6TickNeighborCache(void);
void NetIPv6TickNeighborDiscovery(void);
s16 NetIPv6EmitNeighborSolicitation(int arg0, void *arg1, void *arg2, s16 arg3, int arg4);
s32 NetIPv6SendUnspecifiedSourceNeighborSolicitation(s32 arg0, s16 arg1);
s16 TLobby__sub_804112B8(s32 arg0, s32 arg1, s16 arg2);
s16 TLobby__sub_8041123C(s32 arg0, s32 arg1, s16 arg2);
s32 TLobby__sub_804136EC(void *self);
s16 TLobby__sub_8041579C(NetBufferRef *self);
s16 TLobby__sub_80415954(void *out_, int size, s16 owner);
s32 NetCompareBitsBackward(u8 *arg0, u8 *arg1, s16 arg2);
s32 NetCompareBitPrefix(u8 *a, u8 *b, s16 bits);
s32 NetIPv6MakeSolicitedNodeMulticastAddress(u8 *arg0, u8 *arg1);
s32 TLobby__sub_8041509C(void);
s32 init_ipv6_all_routers_multicast_address(u8 *address, s8 scope);
u8 init_ipv6_all_nodes_multicast_address(u8 *address, s8 scope);
s16 TLobby__sub_80416F58(u8 *self, s32 n, void *out, void *arg_);
s16 TLobby__sub_80417028(void *self, void *a, void *b, void *d);
s32 NetIPv6EmitRouterSolicitation(NetPacket *net_packet, NetIPv6SendParameters *addr, s32 arg2);
s16 NetIPv6GetInterfaceLinkLayerAddress(s32 arg0, s16 arg1, s16 id);
s16 NetIPv6SendNeighborAdvertisement(NetPacket *arg0, u8 *address, u8 arg2, NetIPv6SendParameters *arg3, s16 arg4);
s32 NetIPv6IsLinkLocal(u8 *arg0);
s32 TLobby__sub_8041549C(s16 arg0);
s32 TLobby__sub_804154C0(s16 arg0);
s32 TLobby__sub_804154E4(s16 arg0);
s32 TLobby__sub_80415508(s16 arg0);
s16 TLobby__sub_80411F1C(void *out, void *dst, s16 idx);
s16 TLobby__sub_80415D0C(NetPacket *a, u8 *b, NetIPv6SendParameters *c, s16 d);
s16 TLobby__sub_80411C44(u8 *addr, s16 idx);
#ifdef __cplusplus
}
#endif

#endif
