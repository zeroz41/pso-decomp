#ifndef PSO_NETWORK_NETDNS_H
#define PSO_NETWORK_NETDNS_H
/* The DNS resolver (dns_resolver_state, src/pso/network/TLobby_804050DC.c).  init_net_config sets its limits and
 * carves its pools out of one static block; init_net_tables clears them. */
#include "types.h"
#include "pso/network/UdpRuntime.h"

#ifdef __cplusplus
extern "C" {
#endif

/* A message buffer of DnsResolverState.buffer_size bytes. */
typedef struct DnsBuffer {
    s16 used;
    s16 len;                    /* 0x02 */
    u8 *data;                   /* 0x04 */
} DnsBuffer;

/* An address of a DnsHost, from an A or AAAA answer. */
typedef struct DnsAddr {
    s16 used;
    u8 pad2[2];
    NetworkAddress addr;        /* 0x04: family 4 IPv4, 6 IPv6 */
    u16 rtype;                  /* 0x18: record type, 1 A, 0x1C AAAA */
    u8 pad1A[2];
    s32 ttl;                    /* 0x1C: seconds; counted down by TLobby__sub_8040B3B4, dropped at 0 */
    struct DnsAddr *next;       /* 0x20 */
    struct DnsHost *host;       /* 0x24 */
} DnsAddr;

/* A host name and the addresses found for it. */
typedef struct DnsHost {
    s16 state;                  /* 1 = in use */
    u8 name[0x100];             /* 0x002 */
    s16 name_len;               /* 0x102 */
    u8 cname[0x100];            /* 0x104: from a CNAME answer */
    s16 naddrs;                 /* 0x204 */
    u8 pad206[2];
    DnsAddr *addrs;             /* 0x208 */
} DnsHost;

/* The answer of a PTR query (kind 12). */
typedef struct DnsPtr {
    s16 state;                  /* 1 = in use */
    u8 pad2[0x16];
    s32 ttl;                    /* 0x18: seconds; at 0 its queries are reset (reset_connection_requests) */
    u8 name[0x100];             /* 0x1C: wire format */
} DnsPtr;

/* The fixed part of a resource record of an answer (copied out of the message). */
typedef struct DnsRrHeader {
    u16 type;                   /* 1 A, 5 CNAME, 12 PTR, 0x1C AAAA */
    u16 rclass;                 /* 0x02: 1 IN */
    s32 ttl;                    /* 0x04 */
    u16 rdlength;               /* 0x08 */
} DnsRrHeader;

typedef void (*DnsLookupCallback)(s16 id, NetworkAddress *addrs, s16 naddrs, u8 *cname, s16 cname_len);
typedef void (*DnsPtrCallback)(s16 id, u8 *name, s16 len);

/* Request of a query of kind 1 (A): look a host name up. */
typedef struct DnsLookupRequest {
    u32 family;                 /* 0 both (AAAA, then A), 4 IPv4 (A), 6 IPv6 (AAAA) */
    NetworkAddress *addrs;      /* 0x04: the addresses found are copied here */
    s16 naddrs;                 /* 0x08: room in addrs; then the count, or the error */
    u8 padA[2];
    u8 *cname;                  /* 0x0C: the canonical name is copied here */
    s16 cname_len;              /* 0x10: room in cname; then its length */
    u8 pad12[2];
    DnsLookupCallback cb;       /* 0x14: NULL = the caller waits, -1 = nobody */
    DnsHost *host;              /* 0x18 */
} DnsLookupRequest;

/* Request of a query of kind 12 (PTR): look an address up. */
typedef struct DnsPtrRequest {
    u8 *name;                   /* 0x00: the answer's name is copied here; NULL = only its length */
    s16 len;                    /* 0x04: room in name; then the length, or the error */
    u8 pad6[2];
    DnsPtrCallback cb;          /* 0x08: NULL = the caller waits, -1 = nobody */
    DnsPtr *entry;              /* 0x0C */
} DnsPtrRequest;

/* A query (the handle the resolver's callers get is its index). */
typedef struct DnsQuery {
    s16 active;
    s16 index;                  /* 0x02 */
    s16 socket;                 /* 0x04: UDP socket, -1 = none */
    s16 id;                     /* 0x06: transaction id */
    s16 kind;                   /* 0x08: the DNS query type, 1 A or 12 PTR */
    s16 timer;                  /* 0x0A: seconds to the next retry */
    u32 waiter;                 /* 0x0C: thread waiting for the answer, -1 = none */
    s16 status;                 /* 0x10: tries while running, the error once failed (< 0) */
    s16 outstanding;            /* 0x12 */
    s16 server;                 /* 0x14 */
    u8 pad16[2];
    DnsBuffer *msg;             /* 0x18: the query */
    DnsBuffer *reply;           /* 0x1C */
    union {
        DnsLookupRequest lookup;
        DnsPtrRequest ptr;
    } req;                      /* 0x20 */
} DnsQuery;

typedef struct DnsResolverState {
    s16 next_id;                /* 0x00: transaction id of the next query */
    s16 f2;
    s16 max_name;               /* 0x04 */
    s16 msg_size;               /* 0x06 */
    s16 f8;
    s16 ntimeouts;              /* 0x0A */
    s16 *timeouts;              /* 0x0C: seconds, one per try */
    s16 nservers;               /* 0x10 */
    u8 pad12[2];
    NetworkAddress *servers;    /* 0x14: family 0 = unused */
    s16 server;                 /* 0x18: the server tried first */
    s16 max_tries;              /* 0x1A */
    s16 buffer_size;            /* 0x1C */
    u8 pad1E[2];
    u8 *buffer_base;            /* 0x20 */
    s16 nbuffers;               /* 0x24 */
    u8 pad26[2];
    DnsBuffer *buffers;         /* 0x28 */
    s16 naddrs;                 /* 0x2C */
    s16 nhosts;                 /* 0x2E */
    s16 nptrs;                  /* 0x30 */
    u8 pad32[2];
    DnsAddr *addrs;             /* 0x34 */
    DnsHost *hosts;             /* 0x38 */
    DnsPtr *ptrs;               /* 0x3C */
    s16 nqueries;               /* 0x40 */
    u8 pad42[2];
    DnsQuery *queries;          /* 0x44 */
} DnsResolverState;

typedef char DnsBuffer_size_check[sizeof(DnsBuffer) == 8 ? 1 : -1];
typedef char DnsAddr_size_check[sizeof(DnsAddr) == 0x28 ? 1 : -1];
typedef char DnsHost_size_check[sizeof(DnsHost) == 0x20C ? 1 : -1];
typedef char DnsPtr_size_check[sizeof(DnsPtr) == 0x11C ? 1 : -1];
typedef char DnsQuery_size_check[sizeof(DnsQuery) == 0x3C ? 1 : -1];
typedef char DnsResolverState_size_check[sizeof(DnsResolverState) == 0x48 ? 1 : -1];

extern DnsResolverState dns_resolver_state;


#ifdef __cplusplus
}
#endif

#endif
