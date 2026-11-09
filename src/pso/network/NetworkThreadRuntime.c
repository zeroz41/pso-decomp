/* The network stack's OS layer, second file (a C library, built with GC/1.2.5n): the thread helpers, sleeping on an
 * alarm of NetworkRuntime.c's alarm table, the string helpers, and a few configure-option helpers of the PPP IPv6
 * control protocol. Split from NetworkRuntime.c: signal_alarm_queue addresses the alarm table as an extern while
 * the functions before it pool the tables as their own file's data. */
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
#include "pso/network/TLobby_803FAEA0.h"

s32 TLobby__sub_80428358(void);

s16 TLobby__sub_80401BCC(void *, void *, int);

#define PCO_RD16(p) (TLobby__sub_80401BCC((p), lbl_805D7A70, 2) != 2 ? -1 : read_network_u16_be(lbl_805D7A70))
#define PCO_RD32(p) (TLobby__sub_80401BCC((p), lbl_805D7A70, 4) != 4 ? 0 : TLobby__sub_80402AFC(lbl_805D7A70))
#define PCO_RD8(p) (TLobby__sub_80401BCC((p), lbl_805D7A74, 1) != 1 ? -1 : (s16)lbl_805D7A74[0])

void NetStoreCurrentThread(s32 *thread) {
    *thread = (s32)OSGetCurrentThread();
}

void TLobby__sub_803F97E8(s32 ms) {
    s32 level;
    s32 i;
    NetworkAlarmSlot *slot;
    OSAlarm *alarm;
    s64 ticks;
    level = OSDisableInterrupts();
    for (i = 0; i < 0x40; i++) {
        if (lobby_alarm_slot_table[i].active == 0) {
            break;
        }
    }
    if (i >= 0x40) {
        OSRestoreInterrupts(level);
        return;
    }
    slot = &lobby_alarm_slot_table[i];
    alarm = &slot->alarm;
    slot->active = 1;
    OSCreateAlarm(alarm);
    ticks = ms * ((*(u32 *)0x800000F8 >> 2) / 1000);
    OSSetAlarm(alarm, ticks, (OSAlarmHandler)signal_alarm_queue);
    OSRestoreInterrupts(level);
    OSReceiveMessage(&slot->queue, NULL, 1);
    level = OSDisableInterrupts();
    slot->active = 0;
    OSRestoreInterrupts(level);
}

void signal_alarm_queue(void *alarm) {
    s32 i;
    NetworkAlarmSlot *s;

    for (i = 0; i < 0x40; i++) {
        if (&lobby_alarm_slot_table[i].alarm == alarm) {
            break;
        }
    }
    if (i < 0x40) {
        s = &lobby_alarm_slot_table[i];
        if (s->active != 0) {
            OSSendMessage(&s->queue, NULL, 0);
        }
    }
}

void NetYieldThread(void) {
    OSYieldThread();
}

void resume_thread(s32 thread) {
    OSResumeThread((OSThread*)thread);
}

void NetSuspendCurrentThread(void) {
    OSSuspendThread(OSGetCurrentThread());
}

/* Cancels the thread unless it already terminated. */
void cancel_thread_if_running(void *thread) {
    s32 handle = (s32)thread;
    if (OSIsThreadTerminated((OSThread*)thread) == 0) {
        OSCancelThread((OSThread*)handle);
    }
}

void NetResumeThread(u32 thread) {
    OSResumeThread((OSThread*)thread);
}

void deactivate_entry_by_key(u32 key) {
    Ent_803F9B48 *p;
    u16 n = lobby_thread_pool_count;
    Ent_803F9B48 *base = lobby_thread_pool_base;
    s32 i;
    p = base;
    for (i = 0; i < n; i++) {
        if (key == p->key) break;
        p++;
    }
    if (i < n) {
        base[i].active = 0;
    }
}

s32 TLobby__sub_803F9B94(s32 fn, s32 *out_key) {
    u16 n = lobby_thread_pool_count;
    Ent_803F9B48 *tbl = lobby_thread_pool_base;
    s32 i;
    for (i = 0; i < n; i++) {
        if (tbl[i].active == 0) {
            break;
        }
    }
    if (i >= n) {
        return -1;
    }
    {
        s32 off = i * 0x328;
        u8 *e = (u8 *)tbl + off;
        *(s32 *)(e + 0x318) = fn;
        e = (u8 *)lobby_thread_pool_base + off;
        if (OSCreateThread((OSThread *)((u8 *)lobby_thread_pool_base + off + 8), (void *(*)(void *))run_current_thread_callback, 0, *(u8 **)(e + 0x320) + *(s32 *)(e + 0x31c), *(u32 *)(e + 0x31c), lbl_805D4810, 1) == 1) {
            lobby_thread_pool_base[i].active = 1;
            *out_key = (s32)lobby_thread_pool_base[i].key;
            return 0;
        }
    }
    return -1;
}

s32 run_current_thread_callback(void) {
    u32 key = (u32)OSGetCurrentThread();
    Ent_803F9C78 *p;
    u16 n = lobby_thread_pool_count;
    Ent_803F9C78 *base = (*(Ent_803F9C78 * *)&lobby_thread_pool_base);
    s32 i;
    p = base;
    for (i = 0; i < n; i++) {
        if (key == p->key) break;
        p++;
    }
    if (i >= n) {
        return 0;
    }
    {
        Ent_803F9C78 *e = &base[i];
        e->fn(e);
    }
    return 0;
}

s32 NetSetDefaultThreadPriority(s32 priority) {
    if ((priority < 0) || (priority > 0x1F)) {
        return -1;
    }
    lbl_805D4810 = priority;
    return 0;
}

char* NetAppendString(char* destination, const char* source) {
    return strcat(destination, source);
}

s32 NetCompareStringsCaseInsensitiveN(u8* a, u8* b, u32 n) {
    s32 i;
    s32 c1;
    s32 c2;
    u8 t1;
    u8 t2;
    s16 si;

    for (i = 0; (si = (s16)i) < n && (t1 = *a) != 0 && (t2 = *b) != 0; i++, a++, b++) {
        c1 = t1;
        c2 = t2;
        if (TAdEndText__sub_8039994C(c1)) {
            c1 = TAdEndText__sub_80399904(c1);
        }
        if (TAdEndText__sub_8039994C(c2)) {
            c2 = TAdEndText__sub_80399904(c2);
        }
        if (c1 != c2) {
            return c1 - c2;
        }
    }
    if (*a == 0 && *b == 0) {
        return 0;
    }
    if (si == n) {
        return 0;
    }
    return 1;
}

s32 NetCompareStringsN(const char* left, const char* right, u32 size) {
    return strncmp(left, right, size);
}

s32 NetCompareStrings(const char* left, const char* right) {
    return strcmp(left, right);
}

char* NetCopyString(char* destination, const char* source) {
    return strcpy(destination, source);
}

u32 NetStringLength(const char* text) {
    return strlen(text);
}

void* NetMemmove(void* destination, const void* source, u32 size) {
    return memmove(destination, source, size);
}

s32 NetMemcmp(void* left, void* right, int size) {
    return memcmp(left, right, size);
}

void NetMemset(void* destination, int value, int size) {
    memset(destination, value, size);
}

void NetMemcpy(void* destination, void* source, int size) {
    memcpy(destination, source, size);
}

s32 check_connection_status(void *connection) {
    u8 *conn = (u8 *)connection;
    typedef struct Fields_arg0 { u8 field_0; u8 pad_1[7]; s16 field_8; u8 pad_A[2]; u8 * field_C; } Fields_arg0;
    typedef struct Fields_temp_r31 { u8 field_0; } Fields_temp_r31;
    u8 *peer;
    peer = (u8 *)(((Fields_arg0*)conn)->field_C);
    if ((is_timed_out() != 0) || (((Fields_temp_r31*)peer)->field_0 == 4)) {
        ((Fields_arg0*)conn)->field_8 = 0;
        return -1;
    }
    if (((Fields_arg0*)conn)->field_8 != 0) {
        return -2;
    }
    if (((Fields_arg0*)conn)->field_0 != 5) {
        return 1;
    }
    return 0;
}

extern u32 ppp_ipv6cp_protocol_state[0x2A];
extern u8 lbl_805E1150;
extern u8 lbl_804FD380[];
extern s16 lbl_805D4818;
void *TLobby__sub_803FABDC(void *self);
s32 TLobby__sub_803FA4A4(u8 *self, u8 *src, s32 h);
s32 TLobby__sub_803FA7B0(u8 *self, u8 *src, void *h);
s32 TLobby__sub_803FA318(u8* self, u8* src, s32 n);
void TLobby__sub_803FD694(u8 *arg0);
s32 verify_message_sequence();
void TLobby__sub_803F9FAC(u8 *ctx) {
    Blk_803FA2A8 *src = (Blk_803FA2A8 *)lbl_804FD380;
    u8 *base = (u8 *)ppp_ipv6cp_protocol_state;
    u8 *sub;
    u8 *blk;

    *(u32 *)(base + 0x0) = (u32)&lbl_805E1150;
    *(u16 *)(base + 0x4) = 0x8057;
    *(s16 *)(base + 0x6) = 0xFE;
    base[0x8] = 4;
    base[0x9] = 5;
    base[0xA] = 5;
    base[0xB] = 5;
    *(u32 *)(base + 0xC) = 0xBB8;
    *(void **)(base + 0x10) = (void *)&TLobby__sub_803FA234;
    *(void **)(base + 0x14) = (void *)&TLobby__sub_803FA2A8;
    *(void **)(base + 0x18) = (void *)&TLobby__sub_803FA238;
    *(void **)(base + 0x1C) = (void *)&init_net_state_entry;
    *(void **)(base + 0x20) = (void *)&TLobby__sub_803FA280;
    *(void **)(base + 0x24) = (void *)&NetIPv6CPCancelTimer;
    *(void **)(base + 0x28) = (void *)&TLobby__sub_803FABDC;
    *(void **)(base + 0x2C) = (void *)&TLobby__sub_803FA7B0;
    *(void **)(base + 0x30) = (void *)&verify_message_sequence;
    *(void **)(base + 0x34) = (void *)&TLobby__sub_803FA4A4;
    *(void **)(base + 0x38) = (void *)&TLobby__sub_803FA318;

    sub = ctx + 0xd4;
    *(u8 **)(ctx + 0xe0) = ctx;
    *(u8 **)(sub + 0x2c) = base;
    blk = base + 0x3c;
    *(u8 **)(sub + 0x30) = blk;

    *(Blk_803FA2A8 *)(blk + 0x4) = *src;
    *(s16 *)(blk + 0x0) = lbl_805D4818;
    *(Blk_803FA2A8 *)(blk + 0x38) = *src;
    *(Blk_803FA2A8 *)(blk + 0x50) = *src;
    *(s16 *)(blk + 0x34) = lbl_805D4818;
    TLobby__sub_803FD694(sub);
}

s32 clear_flag_bit4(s32 unused, u8 *opts) {
    *(s16 *)((s8 *)opts + 4) = (s16) (*(s16 *)((s8 *)opts + 4) & 0xFFFFFFFB);
    *(s16 *)((s8 *)opts + 0) = (s16) (*(s16 *)((s8 *)opts + 0) & 0xFFFFFFFB);
    *(s16 *)((s8 *)opts + 0x1C) = (s16) (*(s16 *)((s8 *)opts + 0x1C) & 0xFFFFFFFB);
    return 0;
}

s32 NetIPv6CPSetInterfaceIdentifier(u8 *state, s32 ident) {
    typedef struct Fields_arg0 { u8 pad_0[4]; s16 field_4; u8 pad_6[2]; s32 field_8; s32 field_C; } Fields_arg0;
    s32 sp18;
    s32 sp14;
    s32 sp10;
    NetMemset(&sp18, 0xFF, 8);
    if (NetMemcmp((void *)ident, (void *)((void *)&sp18), 8) != 0) {
        NetMemcpy((void *)((void *)&sp14), (void *)ident, 4);
        NetMemcpy((void *)&sp10, (void *)(ident + 4), 4);
        ((Fields_arg0*)state)->field_8 = sp14;
        ((Fields_arg0*)state)->field_C = sp10;
        ((Fields_arg0*)state)->field_4 = (s16) (((Fields_arg0*)state)->field_4 | 2);
    } else {
        ((Fields_arg0*)state)->field_8 = 0;
        ((Fields_arg0*)state)->field_C = 0;
        ((Fields_arg0*)state)->field_4 = (s16) (((Fields_arg0*)state)->field_4 & 0xFFFFFFFD);
    }
    return 0;
}

void TLobby__sub_803FA234(void) {

}

void TLobby__sub_803FA238(u8 *entry) {
    *(s8 *)((s8 *)entry + 0xA) = 0;
    *(s8 *)((s8 *)entry + 0xB) = 0;
}

void init_net_state_entry(void *entry) {
    s8 *entry_s8 = (s8 *)entry;
  s8 *new_var;
  new_var = (s8 *) (((s8 *) entry_s8) + ((0, 0)));
  TLobby__sub_80405304((void *)((void *) (((u8 *) entry_s8) + 0x10)));
  *new_var = 5;
}

void TLobby__sub_803FA280(void) {

}

void NetIPv6CPCancelTimer(s32 entry_addr) {
    TLobby__sub_80405304((void *)(entry_addr + 0x10));
}

void TLobby__sub_803FA2A8(P_803FA2A8 *o) {
    Q_803FA2A8 *q = o->q;
    q->dst = q->u.src;
    q->dst.w[3] = q->w3C;
    q->dst.w[4] = q->w40;
    q->h0 = q->h0 | q->u.h4;
    q->h50 = 0;
    q->h34 = q->h34 | q->h38;
}

#pragma push
#pragma dont_inline off
#pragma inline_depth(4)
inline u32 optbit_803FA318(u32 bit) {
    s32 f;
    if (bit < 8) {
        return bit;
    }
    f = 0;
    if (bit >= 0x80 && bit < 0x90) {
        f = 1;
    }
    if (f) {
        bit -= 0x78;
    } else {
        bit = 0;
    }
    return bit;
}
s32 TLobby__sub_803FA318(u8* self, u8* src, s32 h) {
    u8* m = *(u8**)(self + 0x30);
    s32 cnt = *(s16*)(src + 2);
    s16 k;
    s32 r;
    u32 bit;
    s32 len;
    s32 pad;
    u8 pair[2];

    if (src[1] != self[1]) {
        return -1;
    }
    while (cnt > 0 && (s16)read_2_bytes(pair, &h) != -1) {
        len = pair[1];
        cnt -= len;
        if (cnt < 0) {
            return -1;
        }
        bit = optbit_803FA318(pair[0]);
        if (!(*(s16*)(m + 0x1c) & (1 << bit))) {
            return -1;
        }
        for (k = len - 2; k-- > 0;) {
            r = (TLobby__sub_80401BCC(&h, &(*(u8*)&lbl_805D7A74), 1) != 1) ? -1 : (s16)(*(u8*)&lbl_805D7A74);
            if (r == -1) {
                return -1;
            }
        }
        bit = optbit_803FA318(pair[0]);
        *(s16*)(m + 0x1c) &= ~(1 << bit);
    }
    return 0;
}
#pragma pop

s32 NetIPv6CPParseConfigureOption(void *self, u8 *out, u8 *src, u8 *c, s16 flag);
#pragma push
#pragma dont_inline off
#pragma inline_depth(4)
#pragma opt_common_subs on
s32 TLobby__sub_803FA4A4(u8 *self, u8 *src, s32 h) {
    u8 *bits;
    u8 *p;
    s32 cnt;
    u32 m;
    s16 r;
    u32 bit;
    s32 f;
    u8 pair[2];
    m = *(u32 *)(self + 0x30);
    cnt = *(s16 *)(src + 2);
    bits = (u8 *)m;
    p = (u8 *)m;
    if (src[1] != self[1]) {
        return -1;
    }
    while (cnt > 0 && (s16)read_2_bytes(pair, &h) != -1) {
        cnt -= pair[1];
        if (cnt < 0) {
            return -1;
        }
        if (pair[0] < 8) { bit = pair[0]; } else { f = 0; if (pair[0] >= 0x80 && pair[0] < 0x90) { f = 1; } if (f) { bit = pair[0] - 0x78; } else { bit = 0; } }
        if (!(*(s16 *)(bits + 0x1c) & (1 << bit))) {
            bit = optbit_803FA318(pair[0]);
            *(s16 *)(bits + 0x1c) |= 1 << bit;
        }
        r = NetIPv6CPParseConfigureOption(&h, bits, p, pair, 0);
        if (r == -1) {
            return -1;
        }
        if (r == 4) {
            bit = optbit_803FA318(pair[0]);
            *(s16 *)(bits + 0x1c) &= ~(1 << bit);
        }
    }
    return 0;
}
#pragma pop
typedef struct Sub_803FA664 { u8 pad0[0x1C]; s16 h1C; } Sub_803FA664;
typedef struct Obj_803FA664 { u8 pad0; u8 b1; u8 pad2[9]; u8 bB; u8 padC[0x24]; Sub_803FA664 *p30; } Obj_803FA664;

void TLobby__sub_803FACD8(u32 *self, void *src, s32 mask);
#pragma push
#pragma opt_lifetimes off
#pragma opt_dead_assignments off
#pragma dont_inline off
#pragma inline_depth(4)
inline u32 first_803FA664(Sub_803FA664 *s) {
    u32 t;
    u32 v = 0;
    t = v;
    t = (u32)init_net_buffer_entry(0);
    if (t == 0) {
        return v;
    }
    TLobby__sub_803FACD8(&t, &s->h1C, s->h1C);
    v = t;
    return v;
}

inline s32 read_803FA664(u32 *p) {
    if (TLobby__sub_80401BCC(p, lbl_805D7A74, 1) != 1) {
        return -1;
    }
    return (s16)lbl_805D7A74[0];
}

s32 verify_message_sequence(Obj_803FA664 *obj, Msg_803FA664 *msg, u32 expected) {
    s16 err;
    s16 a;
    s16 b;
    u32 cur;

    err = 0;
    if (msg->b1 != obj->b1) {
        return -1;
    }
    cur = first_803FA664(obj->p30);
    if (msg->h2 != get_field_4((void *)cur)) {
        err = 1;
    } else {
        while ((a = read_803FA664(&cur)) != -1) {
            b = read_803FA664(&expected);
            if (b == -1 || b != a) {
                err = 1;
                break;
            }
        }
    }
    if (err != 0) {
        return -1;
    }
    obj->bB++;
    return 0;
}
#pragma pop

#pragma push
#pragma dont_inline off
#pragma inline_depth(4)
s32 TLobby__sub_803FA7B0(u8 *self, u8 *src, void *h)
{
  u32 sh;
  PppFrame *blk;
  u8 *m;
  s32 cnt;
  s16 r;
  u8 pair[2];
  s16 state;
  s16 res;
  u8 *new_var;
  s32 TLobby__sub_803FE6CC(void *, u8, u8, void *); /* declared here with other parameter types; the definition is s32 (void *, int, int, void *) */
  s16 NetIPv6CPParseConfigureOption(void *self, u8 *out, u8 *src, u8 *c, s16 flag); /* declared s16 here; the definition returns s32 */
  self = self;
  new_var = *((u8 **) (self + 0x30));
  m = new_var;
  cnt = *((s16 *) (src + 2));
  state = 2;
  blk = 0;
  *((s16 *) (m + 0x50)) = 0;
  while ((cnt > 0) && (((s16) read_2_bytes(pair, &h)) != (-1)))
  {
    cnt -= pair[1];
    if (cnt < 0)
    {
      return -1;
    }
    res = NetIPv6CPParseConfigureOption(&h, m, m + 0x34, pair, 1);
    if (res == (-1))
    {
      return -1;
    }
    if (res < state)
    {
      continue;
    }
    if (res > state)
    {
      blk = 0;
      state = res;
    }
    if (res != 4)
    {
      sh = optbit_803FA318(pair[0]);
      *((s16 *) (m + 0x50)) |= 1 << sh;
    }
    TLobby__sub_803FADA0(&blk, (A_803FADA0 *) (m + 0x50), pair[0], pair[1], &h);
    if (res > 3)
    {
      TLobby__sub_803FE6CC(self, state, src[1], blk);
    }
  }

  if (state == 3)
  {
    if (self[6] != 0)
    {
      self[6]--;
    }
    else
    {
      state = 4;
      TLobby__sub_803FE6CC(self, 4, src[1], blk);
    }
  }
  if (state > 3)
  {
    return (s16) (2 != state);
  }
  TLobby__sub_803FE6CC(self, state, src[1], blk);
  return (s16) (2 != state);
}
#pragma pop
s32 NetIPv6CPParseConfigureOption(void *self, u8 *out, u8 *src, u8 *c, s16 flag) {
    s16 rem;
    s32 r = 2;
    u32 idx;
    rem = c[1] - 2;
    switch (c[0]) {
    case 2:
        *(s16 *)(src + 0x30) = PCO_RD16(self);
        r = 4;
        rem -= 2;
        break;
    case 1:
        *(u32 *)(src + 0x20) = PCO_RD32(self);
        *(u32 *)(src + 0x24) = PCO_RD32(self);
        rem -= 8;
        if (flag == 0) {
            *(u32 *)(out + 8) = *(u32 *)(src + 0x20);
            *(u32 *)(out + 0xc) = *(u32 *)(src + 0x24);
            *(u32 *)(out + 0x44) = *(u32 *)(src + 0x20);
            *(u32 *)(out + 0x48) = *(u32 *)(src + 0x24);
        } else {
            s32 a = *(s32 *)(src + 0x20);
            if (a != 0 || *(s32 *)(src + 0x24) != 0) {
                *(u32 *)(out + 0x3c) = a;
                *(u32 *)(out + 0x40) = *(u32 *)(src + 0x24);
                *(u32 *)(out + 0x10) = *(u32 *)(src + 0x20);
                *(u32 *)(out + 0x14) = *(u32 *)(src + 0x24);
            } else {
                r = 3;
                *(u32 *)(out + 0x54) = *(u32 *)(out + 0x3c);
                *(u32 *)(out + 0x58) = *(u32 *)(out + 0x40);
            }
        }
        break;
    default:
        r = 4;
        break;
    }
    idx = c[0];
    if (idx < 8) {
        idx = c[0];
    } else {
        s32 ok = 0;
        if (idx >= 0x80 && idx < 0x90) {
            ok = 1;
        }
        if (ok) {
            idx -= 0x78;
        } else {
            idx = 0;
        }
    }
    if (!(*(s16 *)src & (1 << idx))) {
        r = 4;
    }
    if (rem < 0) {
        return -1;
    }
    if (flag == 0 && rem > 0) {
        while (rem-- > 0) {
            if (PCO_RD8(self) == -1) {
                return -1;
            }
        }
    }
    return r;
}

extern u8 lbl_804FD398[];
void *TLobby__sub_803FABDC(void *self) {
    s16 i;
    s16 bits;
    u8 *s;
    u8 *p;
    PppFrame *obj;

    p = *(u8 **)((u8 *)self + 0x30);
    obj = 0;
    obj = init_net_buffer_entry(0);
    if (obj == NULL) {
        return NULL;
    }
    bits = *(s16 *)(p + 0x1C);
    if (obj == NULL) {
        obj = init_net_buffer_entry(0);
        if (obj == NULL) {
            goto done;
        }
    }
    s = lbl_804FD398 + 1;
    for (i = 1; i < 0x20; i++) {
        if (bits & (1 << i)) {
            TLobby__sub_803FADA0(&obj, (A_803FADA0 *)(p + 0x1C), (i < 8) ? i : ((i < 0x20) ? i + 0x78 : 0), *s, NULL);
        }
        s++;
    }
done:
    return obj;
}

inline s32 optnum_803FACD8(s32 bit) {
    if (bit < 8) {
        return bit;
    }
    if (bit < 0x20) {
        bit += 0x78;
        return bit;
    }
    return 0;
}
#pragma push
#pragma dont_inline off
#pragma inline_depth(4)
void TLobby__sub_803FACD8(u32 *self, void *src, s32 mask)
{
  s16 new_var;
  s16 i;
  s32 m;
  if ((*self) == 0)
  {
    *self = (u32) init_net_buffer_entry(0);
    if ((*self) == 0)
    {
      return;
    }
  }
  m = (new_var = (s16) mask);
  for (i = 1; i < 0x20; i++)
  {
    if (m & (1 << i))
    {
      TLobby__sub_803FADA0((PppFrame **) self, (A_803FADA0 *) src, optnum_803FACD8(i), lbl_804FD398[i], 0);
    }
  }

}
#pragma pop
void TLobby__sub_803FADA0(PppFrame **pbuf, A_803FADA0 *hdr, s32 type, s32 total_len, void *src) {
    u8 *p;
    PppFrame *b;
    s16 n;
    n = total_len - 2;
    if (*pbuf != NULL) {
        b = *pbuf;
    } else {
        b = init_net_buffer_entry(0);
        if (b == NULL) {
            return;
        }
        *pbuf = b;
    }
    p = b->data + b->len;
    p[0] = type;
    p[1] = total_len;
    p += 2;
    switch (type) {
    case 2:
        break;
    case 1:
        p = write_network_u32_be(write_network_u32_be(p, hdr->a), hdr->b);
        n -= 8;
        break;
    }
    while (n-- > 0) {
        *p++ = TLobby__sub_80401BCC(src, lbl_805D7A74, 1) != 1 ? -1 : (s16)lbl_805D7A74[0];
    }
    b->len += total_len;
}

u32 ppp_ipv6cp_protocol_state[0x2A];
