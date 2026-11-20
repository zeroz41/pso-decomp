#ifndef PSO_NETWORK_NETETHERNET_H
#define PSO_NETWORK_NETETHERNET_H
/* The Ethernet layer (lbl_805C1AD8, src/pso/network/TLobby_804050DC.c): its drivers, one link per driver (registered
 * with the dispatcher by init_net_sockets), the EtherTypes bound on the links and the received-frame buffers.
 * init_net_func_table sets the counts and the arrays. */
#include "types.h"

#ifdef __cplusplus
extern "C" {
#endif

/* A driver (the BBA's, TLobby_80426CAC.c).  dev is the driver's index. */
typedef struct EthDriver {
    s16 (*init)(s16 dev);
    s16 (*open)(s16 dev, u16 type);                  /* 0x04: receive frames of an EtherType */
    s32 (*close)(s16 dev, u16 type);                 /* 0x08 */
    s32 (*add_multicast)(s16 dev, void *addr);       /* 0x0C */
    s32 (*remove_multicast)(s16 dev, void *addr);    /* 0x10 */
    s16 (*get_address)(s16 dev, void *addr);         /* 0x14: returns the address length (6) */
    s32 (*send)(s16 dev, s32 frame, s16 len);        /* 0x18 */
} EthDriver;

/* A driver as registered with the dispatcher. */
typedef struct EthLink {
    s16 used;
    s16 id;                     /* 0x02: its handler index (TLobby__sub_80409A3C) */
    s16 dev;                    /* 0x04 */
    u8 mac[6];                  /* 0x06 */
    u8 *frame;                  /* 0x0C: the frame being sent */
} EthLink;

/* An EtherType bound on a link (TLobby__sub_804094B8). */
typedef struct EthSocket {
    s16 used;
    s16 link;                   /* 0x02: EthLink.id */
    s16 dev;                    /* 0x04 */
    u16 type;                   /* 0x06: 0x800 IPv4, 0x806 ARP, 0x86DD IPv6 */
    s16 iface;                  /* 0x08: the IPv4 interface, -1 = none */
    u8 padA[2];
    struct EthFrameSlot *slot;  /* 0x0C: the frame being received */
} EthSocket;

/* A received frame. */
typedef struct EthFrameSlot {
    s16 used;
    s16 dev;                    /* 0x02 */
    s16 socket;                 /* 0x04: EthSocket index */
    s16 link;                   /* 0x06 */
    s16 len;                    /* 0x08 */
    u8 frame[0x5EE];            /* 0x0A: the Ethernet header, then the payload */
} EthFrameSlot;

typedef struct EthernetState {
    s16 ndrivers;
    s16 nlinks;                 /* 0x02 */
    s16 nsockets;               /* 0x04 */
    s16 nslots;                 /* 0x06 */
    EthDriver *drivers;         /* 0x08 */
    EthLink *links;             /* 0x0C */
    EthSocket *sockets;         /* 0x10 */
    EthFrameSlot *slots;        /* 0x14 */
} EthernetState;

typedef char EthDriver_size_check[sizeof(EthDriver) == 0x1C ? 1 : -1];
typedef char EthLink_size_check[sizeof(EthLink) == 0x10 ? 1 : -1];
typedef char EthSocket_size_check[sizeof(EthSocket) == 0x10 ? 1 : -1];
typedef char EthFrameSlot_size_check[sizeof(EthFrameSlot) == 0x5F8 ? 1 : -1];
typedef char EthernetState_size_check[sizeof(EthernetState) == 0x18 ? 1 : -1];

extern EthernetState lbl_805C1AD8;

#ifdef __cplusplus
}
#endif

#endif
