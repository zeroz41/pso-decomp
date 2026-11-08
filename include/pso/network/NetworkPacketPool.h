#ifndef PSO_NETWORK_NETWORK_PACKET_POOL_H
#define PSO_NETWORK_NETWORK_PACKET_POOL_H
#include "types.h"

enum { NETWORK_PACKET_BUFFER_COUNT = 32, NETWORK_PACKET_BUFFER_BYTES = 0x600 };
typedef struct NetworkPacketBufferDescriptor {
    s32 in_use;
    s32 queued_length;
    u8 *data;
} NetworkPacketBufferDescriptor;

/* NetworkPacketRuntime.c: the packet buffer pool, the DHCP client's state and its option table. */
#ifdef __cplusplus
extern "C" {
#endif
s32 initialize_network_packet_pool(void);
extern NetworkPacketBufferDescriptor network_packet_buffer_descriptors[NETWORK_PACKET_BUFFER_COUNT];
extern u8 network_packet_buffers[NETWORK_PACKET_BUFFER_COUNT][NETWORK_PACKET_BUFFER_BYTES];
s32 get_task_count(void);
void parse_dhcp_lease_times(u8 *packet);
s16 validate_slot_buffers(s32 unused, void *option3, void *option4, void *option5);
void clear_message_entry(s32 address);
void release_entry_by_id(u32 address);
u8 *find_entry_by_address(s32 address);
void cancel_alarm_a(void);
u8 find_dhcp_option(u8 *packet, u8 tag, u8 **out);
#ifdef __cplusplus
}
#endif
#endif
