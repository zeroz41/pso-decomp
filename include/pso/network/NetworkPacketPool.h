#ifndef PSO_NETWORK_NETWORK_PACKET_POOL_H
#define PSO_NETWORK_NETWORK_PACKET_POOL_H
#include "types.h"

enum { NETWORK_PACKET_BUFFER_COUNT = 32, NETWORK_PACKET_BUFFER_BYTES = 0x600 };
typedef struct NetworkPacketBufferDescriptor {
    s32 in_use;
    s32 queued_length;
    u8 *data;
} NetworkPacketBufferDescriptor;

/* NetworkPacketRuntime.c: the packet buffer pool. */
#ifdef __cplusplus
extern "C" {
#endif
s16 initialize_network_packet_pool(void);
extern NetworkPacketBufferDescriptor network_packet_buffer_descriptors[NETWORK_PACKET_BUFFER_COUNT];
extern u8 network_packet_buffers[NETWORK_PACKET_BUFFER_COUNT][NETWORK_PACKET_BUFFER_BYTES];
/* packet: an address inside one of the pool's buffers. */
void clear_message_entry(u8 *packet);
void release_entry_by_id(u8 *packet);
u8 *alloc_packet_buffer_locked(u32 size);
u8 *alloc_rx_packet_buffer(u32 size);
NetworkPacketBufferDescriptor *find_packet_buffer_locked(u8 *packet);
NetworkPacketBufferDescriptor *find_entry_by_address(u8 *packet);
void cancel_alarm_a(void);
#ifdef __cplusplus
}
#endif
#endif
