#ifndef PSO_NETWORK_NET_DHCP_H
#define PSO_NETWORK_NET_DHCP_H
#include "types.h"

/* NetDhcp.c: the network stack's DHCP client. */
#ifdef __cplusplus
extern "C" {
#endif
s32 get_task_count(void);
void parse_dhcp_lease_times(u8 *packet);
s16 validate_slot_buffers(s32 unused, void *option3, void *option4, void *option5);
u8 find_dhcp_option(u8 *packet, u8 tag, u8 **out);
#ifdef __cplusplus
}
#endif
#endif
