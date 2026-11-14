/* The network stack's packet buffers (a C library, built with GC/1.2.5n): the pool of 0x600-byte packet buffers
 * shared by the receive path, taken and released under network_packet_mutex. Its .bss starts at the descriptor
 * table: the code addresses it at offset 0 of the file's .bss, so the DHCP client before it is another file. */
#include "pso/network/NetworkRuntime.h"
#include "pso/network/NetworkPacketPool.h"
#include <stddef.h>
#include "pso/network/NetworkTransport.h"

#include "types.h"
#include "pso/network/text_80421620.h"

#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off

typedef struct R_804253A0 { s32 a; s32 b; } R_804253A0;

NetworkPacketBufferDescriptor network_packet_buffer_descriptors[NETWORK_PACKET_BUFFER_COUNT];
u8 network_packet_buffers[NETWORK_PACKET_BUFFER_COUNT][NETWORK_PACKET_BUFFER_BYTES];
u32 network_packet_mutex;
s16 TLobby__sub_803F96AC(u32*);

#pragma push
#pragma dont_inline off
#pragma inline_depth(4)
static inline NetworkPacketBufferDescriptor *find_804253F8(u32 arg0) {
    s32 i;
    for (i = 0; i < 0x20; i++) {
        if (network_packet_buffer_descriptors[i].in_use != 0 && (u32)network_packet_buffer_descriptors[i].data <= arg0 &&
            arg0 < (u32)network_packet_buffer_descriptors[i].data + 0x600) {
            break;
        }
    }
    if (i >= 0x20) {
        return NULL;
    }
    return &network_packet_buffer_descriptors[i];
}

void clear_message_entry(s32 a) {
    R_804253A0 *r;
    u8 unused[8];
    lock_mutex((int)((void *)network_packet_mutex));
    r = (R_804253A0 *)find_entry_by_address(a);
    unlock_mutex((int)((void *)network_packet_mutex));
    if (r != 0) {
        r->a = 0;
        r->b = 0;
    }
}

void release_entry_by_id(u32 arg0) {
    NetworkPacketBufferDescriptor *e = find_804253F8(arg0);
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
    lock_mutex((int)((void *)network_packet_mutex));
    buf = alloc_packet_buffer(size);
    unlock_mutex((int)((void *)network_packet_mutex));
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

NetworkPacketBufferDescriptor *TLobby__sub_804256B8(u32 addr) {
    NetworkPacketBufferDescriptor *e;
    lock_mutex((int)((void *)network_packet_mutex));
    e = find_804253F8(addr);
    unlock_mutex((int)((void *)network_packet_mutex));
    return e;
}
#pragma pop

u8 *find_entry_by_address(s32 arg0) {
    s32 i;
    for (i = 0; i < 32; i++) {
        if (((NetworkPacketBufferDescriptor *)&network_packet_buffer_descriptors)[i].in_use != 0 && (u32)((NetworkPacketBufferDescriptor *)&network_packet_buffer_descriptors)[i].data <= (u32)arg0 && (u32)arg0 < (u32)((NetworkPacketBufferDescriptor *)&network_packet_buffer_descriptors)[i].data + 0x600) {
            break;
        }
    }
    if (i >= 32) {
        return NULL;
    }
    return (u8 *)&((NetworkPacketBufferDescriptor *)&network_packet_buffer_descriptors)[i];
}

void cancel_alarm_a(void) {
    NetReleaseMutex(network_packet_mutex);
}

s32 initialize_network_packet_pool(void) {
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


typedef char NetworkPacketDescriptorSize[sizeof(NetworkPacketBufferDescriptor)==12 ? 1 : -1];
typedef char NetworkPacketInUseOffset[offsetof(NetworkPacketBufferDescriptor,in_use)==0 ? 1 : -1];
typedef char NetworkPacketLengthOffset[offsetof(NetworkPacketBufferDescriptor,queued_length)==4 ? 1 : -1];
typedef char NetworkPacketDataOffset[offsetof(NetworkPacketBufferDescriptor,data)==8 ? 1 : -1];
