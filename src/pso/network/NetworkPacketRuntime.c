/* The network stack's packet buffers (a C library, built with GC/1.2.5n): the pool of 0x600-byte packet buffers
 * shared by the receive path, taken and released under network_packet_mutex. Its .bss starts at the descriptor
 * table: the code addresses it at offset 0 of the file's .bss, so the DHCP client before it is another file. */
#include "pso/network/NetworkRuntimeSlots.h"
#include "pso/network/NetworkPacketPool.h"
#include <stddef.h>
#include "pso/network/NetworkTransport.h"

#include "types.h"
#include "pso/network/text_80421620.h"

#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off

NetworkPacketBufferDescriptor network_packet_buffer_descriptors[NETWORK_PACKET_BUFFER_COUNT];
u8 network_packet_buffers[NETWORK_PACKET_BUFFER_COUNT][NETWORK_PACKET_BUFFER_BYTES];
s32 network_packet_mutex;

#pragma push
#pragma dont_inline off
#pragma inline_depth(4)
static inline NetworkPacketBufferDescriptor *find_804253F8(u8 *packet) {
    s32 i;
    for (i = 0; i < 0x20; i++) {
        if (network_packet_buffer_descriptors[i].in_use != 0 && network_packet_buffer_descriptors[i].data <= packet &&
            packet < network_packet_buffer_descriptors[i].data + 0x600) {
            break;
        }
    }
    if (i >= 0x20) {
        return NULL;
    }
    return &network_packet_buffer_descriptors[i];
}

void clear_message_entry(u8 *packet) {
    NetworkPacketBufferDescriptor *entry;
    u8 unused[8];
    lock_mutex((saddr)network_packet_mutex);
    entry = find_entry_by_address(packet);
    unlock_mutex((saddr)network_packet_mutex);
    if (entry != NULL) {
        entry->in_use = 0;
        entry->queued_length = 0;
    }
}

void release_entry_by_id(u8 *packet) {
    NetworkPacketBufferDescriptor *e = find_804253F8(packet);
    if (e != NULL) {
        e->in_use = 0;
        e->queued_length = 0;
    }
}

static inline u8 *alloc_packet_buffer(u32 size) {
    s16 i;
    u8 *buf = NULL;
    if (size > NETWORK_PACKET_BUFFER_BYTES) {
        return NULL;
    }
    for (i = 0; i < NETWORK_PACKET_BUFFER_COUNT; i++) {
        if (network_packet_buffer_descriptors[i].in_use == 0) {
            network_packet_buffer_descriptors[i].in_use = 1;
            buf = network_packet_buffer_descriptors[i].data;
            break;
        }
    }
    if (i >= NETWORK_PACKET_BUFFER_COUNT) {
        return NULL;
    }
    return buf;
}

u8 *TLobby__sub_8042558C(u32 size) {
    u8 *buf;
    lock_mutex((saddr)network_packet_mutex);
    buf = alloc_packet_buffer(size);
    unlock_mutex((saddr)network_packet_mutex);
    return buf;
}

u8 *TLobby__sub_80425640(u32 size) {
    s16 i;
    u8 *buf = NULL;
    if (size > NETWORK_PACKET_BUFFER_BYTES) {
        return NULL;
    }
    for (i = 0; i < NETWORK_PACKET_BUFFER_COUNT; i++) {
        if (network_packet_buffer_descriptors[i].in_use == 0) {
            network_packet_buffer_descriptors[i].in_use = 1;
            buf = network_packet_buffer_descriptors[i].data;
            break;
        }
    }
    if (i >= NETWORK_PACKET_BUFFER_COUNT) {
        return NULL;
    }
    return buf;
}

NetworkPacketBufferDescriptor *TLobby__sub_804256B8(u8 *packet) {
    NetworkPacketBufferDescriptor *e;
    lock_mutex((saddr)network_packet_mutex);
    e = find_804253F8(packet);
    unlock_mutex((saddr)network_packet_mutex);
    return e;
}
#pragma pop

NetworkPacketBufferDescriptor *find_entry_by_address(u8 *packet) {
    s32 i;
    for (i = 0; i < 32; i++) {
        if (network_packet_buffer_descriptors[i].in_use != 0 && network_packet_buffer_descriptors[i].data <= packet && packet < network_packet_buffer_descriptors[i].data + 0x600) {
            break;
        }
    }
    if (i >= 32) {
        return NULL;
    }
    return &network_packet_buffer_descriptors[i];
}

void cancel_alarm_a(void) {
    NetReleaseMutex(network_packet_mutex);
}

s16 initialize_network_packet_pool(void) {
    s32 i;
    if (TLobby__sub_803F96AC(&network_packet_mutex) < 0) {
        return -1;
    } else {
    for (i = 0; (0x20) > (i); i++) {
        network_packet_buffer_descriptors[i].in_use = 0;
        network_packet_buffer_descriptors[i].queued_length = 0;
        network_packet_buffer_descriptors[i].data = network_packet_buffers[i];
    }
    }
    return 0;
}


LAYOUT_ASSERT(NetworkPacketDescriptorSize, sizeof(NetworkPacketBufferDescriptor)==12);
LAYOUT_ASSERT(NetworkPacketInUseOffset, offsetof(NetworkPacketBufferDescriptor,in_use)==0);
LAYOUT_ASSERT(NetworkPacketLengthOffset, offsetof(NetworkPacketBufferDescriptor,queued_length)==4);
LAYOUT_ASSERT(NetworkPacketDataOffset, offsetof(NetworkPacketBufferDescriptor,data)==8);
