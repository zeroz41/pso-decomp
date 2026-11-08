/* The network stack's OS layer, first file (a C library, built with GC/1.2.5n): the alarm, mutex and message-queue
 * slot tables over the Dolphin OS, their setup and teardown, the time helpers. The thread helpers, sleeping on an
 * alarm, the string helpers and the IPv6CP option helpers are the next file, NetworkThreadRuntime.c. */
#include "types.h"
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
#include "pso/network/TLobby_803FAEA0.h"
typedef struct Ent_803F9B48 { s32 active; u32 key; u8 pad[0x328 - 8]; } Ent_803F9B48;

typedef struct Ent_803F9C78 { s32 active; u32 key; u8 pad[0x318 - 8]; void (*fn)(struct Ent_803F9C78 *); u8 pad2[0x328 - 0x31C]; } Ent_803F9C78;

typedef struct Blk_803FA2A8 { s32 w[6]; } Blk_803FA2A8;

typedef union U_803FA2A8 { s16 h4; Blk_803FA2A8 src; } U_803FA2A8;

typedef struct Q_803FA2A8 {
    s16 h0; s16 h2;
    U_803FA2A8 u;
    Blk_803FA2A8 dst;
    s16 h34; s16 h36; s16 h38; s16 h3A;
    s32 w3C; s32 w40;
    u8 pad44[0x50 - 0x44];
    s16 h50;
} Q_803FA2A8;

typedef struct P_803FA2A8 { u8 pad[0x30]; Q_803FA2A8 *q; } P_803FA2A8;

typedef struct B_803FADA0 { u8 *buf; u16 len; } B_803FADA0;

typedef struct A_803FADA0 { u8 pad0[4]; u32 a; u32 b; } A_803FADA0;


u8 *write_network_u16_be(u8 *p, u16 v);

s32 TLobby__sub_80405304(void *arg0);
extern u16 lbl_805D7A68;
extern Ent_803F9B48 *lbl_805D7A6C;
void TLobby__sub_803FA2A8(P_803FA2A8 *o);
s32 TLobby__sub_80428358(void);

s16 TLobby__sub_80401BCC(void *, void *, int);

B_803FADA0 *init_net_buffer_entry(s32);
extern u8 lbl_805D7A70[1];
extern u8 lbl_805D7A74[1];
u16 read_network_u16_be(u8 *p);
u32 TLobby__sub_80402AFC(u8 *p);
#define PCO_RD16(p) (TLobby__sub_80401BCC((p), lbl_805D7A70, 2) != 2 ? -1 : read_network_u16_be(lbl_805D7A70))
#define PCO_RD32(p) (TLobby__sub_80401BCC((p), lbl_805D7A70, 4) != 4 ? 0 : TLobby__sub_80402AFC(lbl_805D7A70))
#define PCO_RD8(p) (TLobby__sub_80401BCC((p), lbl_805D7A74, 1) != 1 ? -1 : (s16)lbl_805D7A74[0])
void TLobby__sub_803FADA0(B_803FADA0 **arg0, A_803FADA0 *arg1, s32 arg2, s32 arg3, void *arg4);

extern s32 lbl_805D4810;

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

extern u8 *lbl_805D7A64;
extern u16 lbl_805D7A60;
s32 TLobby__sub_803F8E9C(void)
{
  s16 init_buffer_pool(void);
  s16 initialize_network_packet_pool(void);
  s16 TLobby__sub_80428360();
  s32 i;
  s32 off;
  s32 cnt;
  u8 *new_var4;
  s32 zero;
  u8 *new_var3;
  NetworkAlarmSlot *s;
  s32 *q;
  s32 *new_var;
  s32 *new_var2;
  u8 *tbl;
  tbl = (u8 *) lobby_alarm_slot_table;
  new_var3 = tbl;
  new_var3 = new_var3 + 0x1700;
  if ((lbl_805D7A6C == 0) || (lbl_805D7A64 == 0))
  {
    return -1;
  }
  for (i = 0; i < lbl_805D7A68; i++)
  {
    lbl_805D7A6C[i].active = 0;
    q = (s32 *) (&lbl_805D7A6C[i]);
    q[1] = (s32) (q + 2);
  }

  for (i = 0; i < 0x40; i++)
  {
    ((NetworkAlarmSlot *) tbl)[i].active = 0;
    OSInitMessageQueue((void *) (((u8 *) (&((NetworkAlarmSlot *) tbl)[i])) + 0x30), (void *) (((u8 *) (&((NetworkAlarmSlot *) tbl)[i])) + 0x50), 1);
  }

  q = (s32 *) network_mutex_slot_table;
  ((s32 *) (new_var4 = (u8 *) network_mutex_slot_table))[0] = 0;
  ((s32 *) network_mutex_slot_table)[1] = (s32) (q + 2);
  q = (s32 *) (tbl + 0x1620);
  q[0] = 0;
  new_var = (s32 *) (tbl + 0x1640);
  q[1] = (s32) (q + 2);
  q = new_var;
  new_var2 = (s32 *) (tbl + 0x1660);
  q[0] = 0;
  q[1] = (s32) (q + 2);
  q = new_var2;
  q[0] = 0;
  q[1] = (s32) (q + 2);
  q = (s32 *) (tbl + 0x1680);
  q[0] = 0;
  q[(((1 & 0xFFFF) & 0xFFFF) & 0xFFFF) & 0xFFFF] = (s32) (q + 2);
  q = (s32 *) (tbl + 0x16a0);
  q[0] = 0;
  q[1] = (s32) (q + 2);
  q = (s32 *) (tbl + 0x16c0);
  q[0] = 0;
  q[1] = (s32) (q + 2);
  q = (s32 *) (tbl + 0x16e0);
  q[0] = 0;
  q[1] = (s32) (q + 2);
  q = (s32 *) new_var3;
  q[0] = 0;
  q[1] = (s32) (q + 2);
  q = (s32 *) (tbl + 0x1aa8);
  q[0] = 0;
  q[1] = (s32) (q + 2);
  for (i = 0; i < lbl_805D7A60; i++)
  {
    *((s32 *) (lbl_805D7A64 + (i * 0xc))) = 0;
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
        NetMemcpy((void *)(destination), (void *)(slot->data), (int)(size));
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
        *((s32 *) (p2 + 0x1728)) = 1;
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
s32 TLobby__sub_803F94F0(s32 *out) {
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

void unlock_mutex(int _w0) {
    OSUnlockMutex((OSMutex*)_w0);
}

void lock_mutex(int _w0) {
    OSLockMutex((OSMutex*)_w0);
}

void NetReleaseMutex(u32 handle) {
    s32 index;
    for (index = 0; index < 8; index++) {
        if (handle == network_mutex_slot_table[index].handle) break;
    }
    if (index < 8) network_mutex_slot_table[index].active = 0;
}

s32 TLobby__sub_803F96AC(s32 *out) {
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
