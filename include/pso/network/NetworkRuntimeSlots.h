#ifndef PSO_NETWORK_NETWORKRUNTIMESLOTS_H
#define PSO_NETWORK_NETWORKRUNTIMESLOTS_H
#include "types.h"
#include "dolphin/os/OSMessage.h"
#include "dolphin/os/OSMutex.h"
#include "dolphin/os/OSAlarm.h"

struct NetworkAlarmSlot {
    s32 active;
    OSAlarm alarm;
    OSMessageQueue queue;
    OSMessage message;
};
struct NetworkMutexSlot {
    s32 active;
    u32 handle;
    OSMutex mutex;
};
struct NetworkMessageSlot {
    s32 active;
    u8 data[20];
};
struct NetworkMessageQueueSlot {
    s32 active;
    u32 handle;
    OSMessageQueue queue;
    NetworkMessageSlot messages[32];
    OSMessage pending[32];
};
extern "C" {
extern NetworkAlarmSlot lobby_alarm_slot_table[64];
extern NetworkMutexSlot network_mutex_slot_table[8];
extern NetworkMessageQueueSlot network_message_queue_slot_table[2];
}
#endif
