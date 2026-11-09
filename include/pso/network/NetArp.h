#ifndef PSO_NETWORK_NETARP_H
#define PSO_NETWORK_NETARP_H
/* ARP (lbl_805C1AB0, src/pso/network/TLobby_804050DC.c): the address cache, the interfaces ARP runs on, the packets
 * held until their next hop's address is known and the other protocol addresses an interface answers for.
 * init_net_buffer_config sets the counts and the arrays; TLobby__sub_804078B4 ages the cache once a minute. */
#include "types.h"

#ifdef __cplusplus
extern "C" {
#endif

/* The fixed part of an ARP packet; the sender's and the target's addresses follow it. */
typedef struct ArpHeader {
    u16 htype;                  /* hardware type */
    u16 ptype;                  /* 0x02: protocol type */
    u8 hlen;                    /* 0x04: hardware address length */
    u8 plen;                    /* 0x05: protocol address length */
    u16 op;                     /* 0x06: 1 request, 2 reply */
} ArpHeader;

/* Where the fields of an ARP packet being built or read are. */
typedef struct ArpFields {
    ArpHeader *hdr;
    u8 *sha;                    /* 0x04: sender hardware address */
    u8 *spa;                    /* 0x08: sender protocol address */
    u8 *tha;                    /* 0x0C: target hardware address */
    u8 *tpa;                    /* 0x10: target protocol address */
} ArpFields;

struct ArpEntry;

/* A packet held until its next hop's hardware address is known (one per cache entry). */
typedef struct ArpHold {
    struct ArpEntry *entry;     /* NULL = free */
    s16 used;                   /* 0x04 */
    s16 len;                    /* 0x06 */
    s16 cap;                    /* 0x08: ArpState.hold_size */
    u8 padA[2];
    s32 data;                   /* 0x0C: its buffer, as a NetBufferRef value */
} ArpHold;

/* An address cache entry. */
typedef struct ArpEntry {
    s16 state;                  /* 0 free, 1 request sent, 2 resolved; 4 and 8 never expire */
    s16 timer;                  /* 0x02: minutes left */
    u8 hlen;                    /* 0x04 */
    u8 plen;                    /* 0x05 */
    u8 pad6[2];
    ArpHold *hold;              /* 0x08 */
    u8 haddr[6];                /* 0x0C */
    u8 paddr[4];                /* 0x12 */
    u8 pad16[2];
} ArpEntry;

/* Another protocol address an interface answers requests for. */
typedef struct ArpAlias {
    struct ArpAlias *next;
    s16 used;                   /* 0x04 */
    u8 addr[4];                 /* 0x06 */
    u8 padA[2];
} ArpAlias;

/* An interface ARP runs on (registered by TLobby__sub_80407F20). */
typedef struct ArpIface {
    s16 used;
    s16 handler;                /* 0x02: the link's handler index (LobbyHandler) */
    s16 socket;                 /* 0x04: the socket the packets for resolved addresses are sent on */
    s16 arp_socket;             /* 0x06: the link's ARP socket (EtherType 0x806) */
    s16 index;                  /* 0x08 */
    u16 htype;                  /* 0x0A: htype .. plen are the fixed part of its packets (ArpHeader) */
    u16 ptype;                  /* 0x0C */
    u8 hlen;                    /* 0x0E */
    u8 plen;                    /* 0x0F */
    s16 f10;                    /* 0x10: cleared at registration */
    u8 haddr[6];                /* 0x12 */
    u8 paddr[4];                /* 0x18 */
    ArpAlias *aliases;          /* 0x1C */
} ArpIface;

typedef struct ArpState {
    s16 nentries;
    s16 nifaces;                /* 0x02 */
    s16 nholds;                 /* 0x04 */
    s16 hold_size;              /* 0x06 */
    s16 naliases;               /* 0x08: also the longest alias list */
    s16 timeout;                /* 0x0A: minutes a resolved entry stays */
    s16 retry;                  /* 0x0C: minutes an unanswered request stays */
    u8 padE[2];
    ArpEntry *entries;          /* 0x10 */
    ArpIface *ifaces;           /* 0x14 */
    ArpAlias *aliases;          /* 0x18 */
    ArpHold *holds;             /* 0x1C */
    u8 *hold_buffers;           /* 0x20: nholds buffers of hold_size bytes */
    u8 *packet;                 /* 0x24: the buffer requests and replies are built in */
} ArpState;

typedef char ArpHeader_size_check[sizeof(ArpHeader) == 8 ? 1 : -1];
typedef char ArpHold_size_check[sizeof(ArpHold) == 0x10 ? 1 : -1];
typedef char ArpEntry_size_check[sizeof(ArpEntry) == 0x18 ? 1 : -1];
typedef char ArpAlias_size_check[sizeof(ArpAlias) == 0xC ? 1 : -1];
typedef char ArpIface_size_check[sizeof(ArpIface) == 0x20 ? 1 : -1];
typedef char ArpState_size_check[sizeof(ArpState) == 0x28 ? 1 : -1];

extern ArpState lbl_805C1AB0;

#ifdef __cplusplus
}
#endif

#endif
