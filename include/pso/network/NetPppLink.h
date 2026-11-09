#ifndef PSO_NETWORK_NETPPPLINK_H
#define PSO_NETWORK_NETPPPLINK_H
/* The PPP link as the dispatcher sees it (lobby_net_buffer_desc_b, src/pso/network/TLobby_803FCF44.c).
 * TLobby__sub_803FD10C registers it; TLobby__sub_803FD5A4 binds an EtherType on it; TLobby__sub_804060B8 copies each
 * received packet into a free buffer and passes it to the protocol bound for its type. */
#include "types.h"

#ifdef __cplusplus
extern "C" {
#endif

/* An EtherType bound on the link. */
typedef struct PppLinkProtocol {
    s16 used;
    u16 type;                   /* 0x02: 0x800 IPv4, 0x86DD IPv6 */
} PppLinkProtocol;

typedef struct PppLink {
    s16 id;                     /* its handler index (TLobby__sub_80409A3C), -1 = closed */
    PppLinkProtocol protocols[2]; /* 0x02 */
    u8 padA[2];
    s16 *used;                  /* 0x0C: one flag per receive buffer */
    u8 *buffers;                /* 0x10: count buffers of size bytes */
    s16 size;                   /* 0x14: also the link's MTU (1500) */
    s16 count;                  /* 0x16 */
} PppLink;

typedef char PppLinkProtocol_size_check[sizeof(PppLinkProtocol) == 4 ? 1 : -1];
typedef char PppLink_size_check[sizeof(PppLink) == 0x18 ? 1 : -1];

extern PppLink lobby_net_buffer_desc_b;

void init_buffer_desc_b(PppLink *link);

#ifdef __cplusplus
}
#endif

#endif
