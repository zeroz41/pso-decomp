#ifndef PSO_NETWORK_NETWORKRUNTIMESLOTS_H
#define PSO_NETWORK_NETWORKRUNTIMESLOTS_H
#include "types.h"
#include <stddef.h>
#include "dolphin/os/OSMessage.h"
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

typedef char NetworkAlarmSlot_size[(sizeof(NetworkAlarmSlot) == 0x58) ? 1 : -1];
typedef char NetworkMutexSlot_size[(sizeof(NetworkMutexSlot) == 0x20) ? 1 : -1];
typedef char NetworkMessageQueueSlot_size[(sizeof(NetworkMessageQueueSlot) == 0x3A8) ? 1 : -1];
typedef char NetworkMutexSlot_mutex_offset[(offsetof(NetworkMutexSlot, mutex) == 8) ? 1 : -1];
typedef char NetworkMessageQueueSlot_queue_offset[(offsetof(NetworkMessageQueueSlot, queue) == 8) ? 1 : -1];
#ifdef __cplusplus
extern "C" {
#endif
extern NetworkAlarmSlot lobby_alarm_slot_table[64];
extern NetworkMutexSlot network_mutex_slot_table[8];
extern NetworkMessageQueueSlot network_message_queue_slot_table[2];
#ifdef __cplusplus
}
#endif
#endif
