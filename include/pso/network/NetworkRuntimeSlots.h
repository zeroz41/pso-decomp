#ifndef PSO_NETWORK_NETWORKRUNTIMESLOTS_H
#define PSO_NETWORK_NETWORKRUNTIMESLOTS_H
#include "types.h"
#include <stddef.h>
#include "pso/network/NetworkRuntime.h"
#include "dolphin/os/OSThread.h"
#include "dolphin/os/OSMessage.h"

struct NetworkThreadSlot {
    s32 active;
    NetThreadHandle key;
    OSThread thread;
    NetThreadEntry entry;
    u32 stack_size;
    u8 *stack;
    u8 pad_324[4];
};

LAYOUT_ASSERT(NetworkThreadSlot_size, sizeof(NetworkThreadSlot) == 0x328);
LAYOUT_ASSERT(NetworkThreadSlot_thread_offset, offsetof(NetworkThreadSlot, thread) == 0x08);
LAYOUT_ASSERT(NetworkThreadSlot_entry_offset, offsetof(NetworkThreadSlot, entry) == 0x318);
LAYOUT_ASSERT(NetworkThreadSlot_stack_offset, offsetof(NetworkThreadSlot, stack) == 0x320);
#include "dolphin/os/OSMutex.h"
#include "dolphin/os/OSAlarm.h"

typedef struct NetworkAlarmSlot {
    s32 active;
    OSAlarm alarm;
    OSMessageQueue queue;
    OSMessage message;
} NetworkAlarmSlot;
typedef struct NetworkMutexSlot {
    s32 active;
    u32 handle;
    OSMutex mutex;
} NetworkMutexSlot;
typedef struct NetworkMessageSlot {
    s32 active;
    u8 data[20];
} NetworkMessageSlot;
typedef struct NetworkMessageQueueSlot {
    s32 active;
    u32 handle;
    OSMessageQueue queue;
    NetworkMessageSlot messages[32];
    OSMessage pending[32];
} NetworkMessageQueueSlot;

LAYOUT_ASSERT(NetworkAlarmSlot_size, sizeof(NetworkAlarmSlot) == 0x58);
LAYOUT_ASSERT(NetworkAlarmSlot_queue_offset, offsetof(NetworkAlarmSlot, queue) == 0x30);
LAYOUT_ASSERT(NetworkAlarmSlot_message_offset, offsetof(NetworkAlarmSlot, message) == 0x50);
LAYOUT_ASSERT(NetworkMutexSlot_size, sizeof(NetworkMutexSlot) == 0x20);
LAYOUT_ASSERT(NetworkMessageQueueSlot_size, sizeof(NetworkMessageQueueSlot) == 0x3A8);
LAYOUT_ASSERT(NetworkMutexSlot_mutex_offset, offsetof(NetworkMutexSlot, mutex) == 8);
LAYOUT_ASSERT(NetworkMessageQueueSlot_queue_offset, offsetof(NetworkMessageQueueSlot, queue) == 8);
#ifdef __cplusplus
extern "C" {
#endif
s16 TLobby__sub_803F96AC(s32 *out);
extern NetworkAlarmSlot lobby_alarm_slot_table[64];
extern NetworkMutexSlot network_mutex_slot_table[8];
extern NetworkMessageQueueSlot network_message_queue_slot_table[2];
#ifdef __cplusplus
}
#endif
#endif
