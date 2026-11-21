#ifndef PSO_NETWORK_IPV4HEADER_H
#define PSO_NETWORK_IPV4HEADER_H

#include "types.h"

/* An IPv4 header as it is on the wire (RFC 791), without options. */
typedef struct IPv4Header {
    u8 ver_ihl;
    u8 tos;
    u16 len;
    u16 id;
    u16 frag;
    u8 ttl;
    u8 proto;
    u16 cksum;
    u32 src;
    u32 dst;
} IPv4Header;
LAYOUT_ASSERT(IPv4Header_size_check, sizeof(IPv4Header) == 0x14);

#endif
