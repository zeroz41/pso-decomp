#ifndef PSO_NETWORK_NET_DHCP_H
#define PSO_NETWORK_NET_DHCP_H
#include "types.h"
#include <stddef.h>

/* NetDhcp.c: the network stack's DHCP client. */
#ifdef __cplusplus
extern "C" {
#endif
// RFC 951 BOOTP header; the DHCP magic cookie precedes the option bytes.
typedef struct BootpPacket {
    u8 op;
    u8 htype;
    u8 hlen;
    u8 hops;
    u32 xid;
    u16 secs;
    u16 flags;
    s32 ciaddr;
    u32 yiaddr;
    u32 siaddr;
    u32 giaddr;
    u8 chaddr[16];
    u8 sname[64];
    u8 file[128];
    u32 cookie;
} BootpPacket;

LAYOUT_ASSERT(BootpPacket_size, sizeof(BootpPacket) == 0xF0);
LAYOUT_ASSERT(BootpPacket_flags, offsetof(BootpPacket, flags) == 0xA);
LAYOUT_ASSERT(BootpPacket_ciaddr, offsetof(BootpPacket, ciaddr) == 0xC);
LAYOUT_ASSERT(BootpPacket_chaddr, offsetof(BootpPacket, chaddr) == 0x1C);
LAYOUT_ASSERT(BootpPacket_cookie, offsetof(BootpPacket, cookie) == 0xEC);

typedef struct DhcpMessage {
    BootpPacket hdr;
    u8 options[0x5DC - sizeof(BootpPacket)];
} DhcpMessage;

LAYOUT_ASSERT(DhcpMessage_size, sizeof(DhcpMessage) == 0x5DC);

// The UDP callback receives into scratch, then copies accepted replies into
// reply. Each region owns one 1500-byte message (0x804249F0 / 0x80424A48).
typedef struct DhcpClientBuffers {
    DhcpMessage outgoing;
    DhcpMessage reply;
    DhcpMessage received;
} DhcpClientBuffers;

LAYOUT_ASSERT(DhcpClientBuffers_outgoing, offsetof(DhcpClientBuffers, outgoing) == 0);
LAYOUT_ASSERT(DhcpClientBuffers_reply, offsetof(DhcpClientBuffers, reply) == 0x5DC);
LAYOUT_ASSERT(DhcpClientBuffers_received, offsetof(DhcpClientBuffers, received) == 0xBB8);
LAYOUT_ASSERT(DhcpClientBuffers_size, sizeof(DhcpClientBuffers) == 0x1194);

s32 get_task_count(void);
s32 DHCP_request(s16 iface, s32 arg1, s32 lease_time, void *arg3,
                 s32 *address, s32 *netmask, s32 *broadcast, s32 retries);
s16 dhcp_discover_and_request(s16 iface, s32 arg1, s32 lease_time, void *arg3,
                               s32 *address, s32 *netmask, s32 *broadcast, s32 retries);
void parse_dhcp_lease_times(u8 *packet);
s32 dhcp_set_option(s16 id, s16 len, void *value);
s16 DHCP_hostname(char *hostname);
s16 TLobby__sub_8042474C(s32 *lease, s32 *renew, s32 *rebind);
s16 DHCP_get_gateway(void *arg0, s32 *router);
s16 DHCP_get_dns(void *arg0, char *domain, s32 *dns1, s32 *dns2);
s32 find_dhcp_option(u8 *packet, u8 tag, u8 **out);
#ifdef __cplusplus
}
#endif
#endif
