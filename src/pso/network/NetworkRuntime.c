/* The network stack's OS layer, first file (a C library, built with GC/1.2.5n): the alarm, mutex and message-queue
 * slot tables over the Dolphin OS, their setup and teardown, the time helpers. The thread helpers, sleeping on an
 * alarm, the string helpers and the IPv6CP option helpers are the next file, NetworkThreadRuntime.c. */
#include "types.h"
#include "pso/network/TLobby_803F86BC.h"
#include "pso/network/TLobby_803FCF44.h"
#include "pso/network/TLobby_804050DC.h"
#include "pso/network/TLobby_803FC178.h"
#include "string.h"
#include "dolphin/os/OSThread.h"
#include "dolphin/os/OSAlarm.h"
#include "dolphin/os/OSTime.h"
#include "dolphin/os/OSInterrupt.h"
#include "pso/network/NetworkRuntime.h"
#include "pso/network/NetworkRuntimeSlots.h"
#include "pso/network/NetworkPacketPool.h"
#include "pso/network/TLobby_80428374.h"
#include "pso/network/TLobby_80426CAC.h"
#include "pso/network/TLobby_803FAEA0.h"

NetworkAlarmSlot lobby_alarm_slot_table[0x40];
NetworkMutexSlot network_mutex_slot_table[8];

s32 cancel_pending_alarms(void) {
    s32 i;
    s32 lvl;
    NetworkAlarmSlot *s;
    lvl = OSDisableInterrupts();
    for (i = 0; i < 0x40; i++) {
        s = &lobby_alarm_slot_table[i];
        if (s->active != 0) {
            OSCancelAlarm(&s->alarm);
            OSSendMessage(&s->queue, NULL, 0);
        }
    }
    OSRestoreInterrupts(lvl);
    TLobby__sub_80428358();
    cancel_alarm_a();
    cancel_alarm_b();
    return 0;
}

s16 TLobby__sub_803F8E9C(void)
{
  s32 i;
  /* These retained locals preserve the retail stack frame. */
  s32 off;
  s32 cnt;
  NetworkMutexSlot *first_mutex;
  s32 zero;
  uaddr message_queue_base;
  NetworkAlarmSlot *alarm;
  NetworkMutexSlot *mutex;
  NetworkMutexSlot *third_mutex;
  NetworkMutexSlot *fourth_mutex;
  NetworkThreadSlot *slot;
  NetworkMessageQueueSlot *message_queue;
  u8 *alarm_base;
  enum {
    MUTEX_SLOTS_OFFSET = sizeof(lobby_alarm_slot_table),
    MESSAGE_QUEUE_SLOTS_OFFSET = MUTEX_SLOTS_OFFSET + sizeof(network_mutex_slot_table)
  };
  alarm_base = (u8 *) lobby_alarm_slot_table;
  /* These three tables occupy consecutive BSS ranges. Retail addresses them from the alarm table base. */
  message_queue_base = (uaddr)alarm_base;
  message_queue_base = message_queue_base + MESSAGE_QUEUE_SLOTS_OFFSET;
  if ((lobby_thread_pool_base == 0) || (lobby_buffer_slots == 0))
  {
    return -1;
  }
  for (i = 0; i < lobby_thread_pool_count; i++)
  {
    lobby_thread_pool_base[i].active = 0;
    slot = &lobby_thread_pool_base[i];
    slot->key = (NetThreadHandle)&slot->thread;
  }

  for (i = 0; i < 0x40; i++)
  {
    alarm = &((NetworkAlarmSlot *)alarm_base)[i];
    alarm->active = 0;
    OSInitMessageQueue(&alarm->queue, &alarm->message, 1);
  }

  mutex = (NetworkMutexSlot *) network_mutex_slot_table;
  /* Keep the first table address assignment in the store to preserve register allocation. */
  (first_mutex = network_mutex_slot_table)->active = 0;
  network_mutex_slot_table[0].handle = (uaddr)&mutex->mutex;
  mutex = (NetworkMutexSlot *)((uaddr)alarm_base + (MUTEX_SLOTS_OFFSET + sizeof(NetworkMutexSlot)));
  mutex->active = 0;
  third_mutex = (NetworkMutexSlot *)((uaddr)alarm_base + (MUTEX_SLOTS_OFFSET + 2 * sizeof(NetworkMutexSlot)));
  mutex->handle = (uaddr)&mutex->mutex;
  mutex = third_mutex;
  fourth_mutex = (NetworkMutexSlot *)((uaddr)alarm_base + (MUTEX_SLOTS_OFFSET + 3 * sizeof(NetworkMutexSlot)));
  mutex->active = 0;
  mutex->handle = (uaddr)&mutex->mutex;
  mutex = fourth_mutex;
  mutex->active = 0;
  mutex->handle = (uaddr)&mutex->mutex;
  mutex = (NetworkMutexSlot *)((uaddr)alarm_base + (MUTEX_SLOTS_OFFSET + 4 * sizeof(NetworkMutexSlot)));
  mutex->active = 0;
  mutex->handle = (uaddr)&mutex->mutex;
  mutex = (NetworkMutexSlot *)((uaddr)alarm_base + (MUTEX_SLOTS_OFFSET + 5 * sizeof(NetworkMutexSlot)));
  mutex->active = 0;
  mutex->handle = (uaddr)&mutex->mutex;
  mutex = (NetworkMutexSlot *)((uaddr)alarm_base + (MUTEX_SLOTS_OFFSET + 6 * sizeof(NetworkMutexSlot)));
  mutex->active = 0;
  mutex->handle = (uaddr)&mutex->mutex;
  mutex = (NetworkMutexSlot *)((uaddr)alarm_base + (MUTEX_SLOTS_OFFSET + 7 * sizeof(NetworkMutexSlot)));
  mutex->active = 0;
  mutex->handle = (uaddr)&mutex->mutex;
  message_queue = (NetworkMessageQueueSlot *)message_queue_base;
  message_queue->active = 0;
  message_queue->handle = (uaddr)&message_queue->queue;
  message_queue = (NetworkMessageQueueSlot *)((uaddr)alarm_base + (MESSAGE_QUEUE_SLOTS_OFFSET + sizeof(NetworkMessageQueueSlot)));
  message_queue->active = 0;
  message_queue->handle = (uaddr)&message_queue->queue;
  for (i = 0; i < lobby_buffer_slot_count; i++)
  {
    lobby_buffer_slots[i].active = 0;
  }

  if (init_buffer_pool() < 0)
  {
    return -1;
  }
  if (initialize_network_packet_pool() < 0)
  {
    return -1;
  }
  if (TLobby__sub_80428360(0) < 0)
  {
    return -1;
  }
  return 0;
}

void get_time_seconds(s32 *out) {
    s64 t = OSGetTime();
    *out = (s32)(t / (s64)(*(u32 *)0x800000F8 >> 2));
}

void get_time_ms(s32 *out) {
    s64 t = OSGetTime();
    *out = (s32)(t / (s64)((*(u32 *)0x800000F8 >> 2) / 1000));
}

void NetStoreTick(s32 *tick) {
    *tick = OSGetTick();
}

void NetReceiveMessage(u32 handle, void* destination, s32 size) {
    s32 slotIndex;
    OSMessage message;
    s32 index;
    for (index = 0; index < 2; index++) {
        slotIndex = index;
        if (handle == network_message_queue_slot_table[slotIndex].handle) break;
    }
    if (index < 2) {
        NetworkMessageSlot* slot;
        OSReceiveMessage(&network_message_queue_slot_table[index].queue, &message, OS_MESSAGE_BLOCK);
        slot = (NetworkMessageSlot*)message;
        NetMemcpy(destination, slot->data, size);
        slot->active = 0;
    }
}

#pragma push
#pragma opt_common_subs on
#pragma opt_dead_assignments off
void TLobby__sub_803F9344(u32 handle, void *source, s32 size)
{
  u8 *base;
  u8 *slot;
  s32 index;
  s32 i;
  base = (u8 *) lobby_alarm_slot_table;
  for (index = 0; index < 2; index++)
  {
    if (handle == ((NetworkMessageQueueSlot *) (base + 0x1700))[index].handle)
    {
      break;
    }
  }

  if (index < 2)
  {
    for (i = 0; i < 32; i++)
    {
      if (((NetworkMessageQueueSlot *) (base + 0x1700))[index].messages[i].active == 0)
      {
        break;
      }
    }

    if (i < 32)
    {
      slot = base + (index * 0x3a8);
      {
        u8 *p2 = slot;
        p2 += i * 0x18;
        *((s32 *)(p2 + 0x1728)) = 1;
      }
      NetMemcpy(((NetworkMessageQueueSlot *) (base + 0x1700))[index].messages[i].data, source, size);
      OSSendMessage(&((NetworkMessageQueueSlot *) (base + 0x1700))[index].queue, &((NetworkMessageQueueSlot *) (base + 0x1700))[index].messages[i], 0);
    }
  }
}
#pragma pop

void clear_slot_for_handle(u32 handle) {
    s32 index;
    index = 0;
    if (handle != network_message_queue_slot_table[0].handle) {
        index = 1;
        if (handle != network_message_queue_slot_table[1].handle) {
            index = 2;
        }
    }
    if (index < 2) {
        network_message_queue_slot_table[index].active = 0;
    }
}

NetworkMessageQueueSlot network_message_queue_slot_table[2];

#pragma push
#pragma optimize_for_size off
#pragma use_lmw_stmw off
s16 TLobby__sub_803F94F0(s32 *out) {
    NetworkMessageQueueSlot *s;
    s32 i;
    s32 off;
    for (i = 0; i < 2; i++) {
        if (network_message_queue_slot_table[i].active == 0) break;
    }
    if (i >= 2) {
        return -1;
    }
    off = i * sizeof(NetworkMessageQueueSlot);
    s = (NetworkMessageQueueSlot *)((u8 *)network_message_queue_slot_table + off);
    OSInitMessageQueue(&s->queue, s->pending, 0x20);
    s->active = 1;
    *out = ((NetworkMessageQueueSlot *)((u8 *)network_message_queue_slot_table + off))->handle;
    return 0;
}
#pragma pop

void unlock_mutex(saddr mutex) {
    OSUnlockMutex((OSMutex*)mutex);
}

void lock_mutex(saddr mutex) {
    OSLockMutex((OSMutex*)mutex);
}

void NetReleaseMutex(u32 handle) {
    s32 index;
    for (index = 0; index < 8; index++) {
        if (handle == network_mutex_slot_table[index].handle) break;
    }
    if (index < 8) network_mutex_slot_table[index].active = 0;
}

s16 TLobby__sub_803F96AC(s32 *out) {
    NetworkMutexSlot *m;
    s32 i;
    s32 off;
    for (i = 0; i < 8; i++) {
        if (network_mutex_slot_table[i].active == 0) break;
    }
    if (i >= 8) {
        return -1;
    }
    off = i * sizeof(NetworkMutexSlot);
    m = (NetworkMutexSlot *)((u8 *)network_mutex_slot_table + off);
    OSInitMutex(&m->mutex);
    m->active = 1;
    *out = ((NetworkMutexSlot *)((u8 *)network_mutex_slot_table + off))->handle;
    return 0;
}
