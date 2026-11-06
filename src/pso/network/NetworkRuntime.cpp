#include "types.h"
#include "string.h"
#include "pso/unk/TLobby.h"
#include "pso/network/NetworkRuntime.h"
#include "pso/network/NetworkRuntimeSlots.h"
#include "dolphin/os/OSInterrupt.h"

#include "pso/network/TUdpSocket.h"

struct Ent_803F9B48 {
    s32 active;
    u32 key;
    OSThread thread;
    void (*func)(Ent_803F9B48 *);
    u32 stack_size;
    u8 *stack;
    u8 pad[4];
};

struct Ent_803F9C78 { s32 active; u32 key; u8 pad[0x318 - 8]; void (*fn)(Ent_803F9C78 *); u8 pad2[0x328 - 0x31C]; };

struct Blk_803FA2A8 { s32 w[6]; };

union U_803FA2A8 { s16 h4; Blk_803FA2A8 src; };

struct Q_803FA2A8 {
    s16 h0; s16 h2;
    U_803FA2A8 u;
    Blk_803FA2A8 dst;
    s16 h34; s16 h36; s16 h38; s16 h3A;
    s32 w3C; s32 w40;
    u8 pad44[0x50 - 0x44];
    s16 h50;
};

struct P_803FA2A8 { u8 pad[0x30]; Q_803FA2A8 *q; };

typedef struct B_803FADA0 { u8 *buf; u16 len; } B_803FADA0;

typedef struct A_803FADA0 { u8 pad0[4]; u32 a; u32 b; } A_803FADA0;

extern "C" {
u8 *write_network_u16_be(u8 *p, u16 v);

s32 TLobby__sub_80405304(void *arg0);
extern u16 lbl_805D7A68;
extern Ent_803F9B48 *lbl_805D7A6C;
void TLobby__sub_803FA2A8(P_803FA2A8 *o);
s32 TLobby__sub_80428358(void);

s16 TLobby__sub_80401BCC(void *, void *, int);

B_803FADA0 *init_net_buffer_entry__6TLobbyFUs(s32);
extern u8 lbl_805D7A74[1];
extern u8 lbl_805D7A70[4];
u16 read_network_u16_be(u8 *p);
u32 TLobby__sub_80402AFC(u8 *p);
void TLobby__sub_803FADA0(B_803FADA0 **arg0, A_803FADA0 *arg1, s32 arg2, s32 arg3, void *arg4);

extern s32 lbl_805D4810;

struct Obj_803FA664;
struct Msg_803FA664;

void TLobby__sub_803F9FAC(u8 *obj);
s32 TLobby__sub_803FA318(Obj_803FA664 *fsm, Msg_803FA664 *msg, u32 src);
s32 TLobby__sub_803FA4A4(Obj_803FA664 *fsm, Msg_803FA664 *msg, u32 src);
s16 TLobby__sub_803FA7B0(Obj_803FA664 *fsm, Msg_803FA664 *msg, u32 src);
B_803FADA0 *TLobby__sub_803FABDC(Obj_803FA664 *fsm);
s32 verify_message_sequence__6TLobbyFPvPvUi(Obj_803FA664 *arg0, Msg_803FA664 *arg1, u32 arg2);
void init_net_state_entry__6TLobbyFv(TLobby *obj);
void TLobby__sub_803FD694(u8 *entry);
extern const char lbl_805E1150[7];
extern s16 lbl_805D4818[4];
extern u32 lbl_804FD380[6];

s32 TLobby__sub_803FE6CC(void *, u8, u8, void *);
s32 TLobby__sub_803F9B94(void (*func)(Ent_803F9B48 *), u32 *out);
s32 NetCompareStringsCaseInsensitiveN(u8 *a, u8 *b, u32 n);
s32 TAdEndText__sub_8039994C(s32 c);
u32 TAdEndText__sub_80399904(s32 c);

NetworkAlarmSlot lobby_alarm_slot_table[0x40];
NetworkMutexSlot network_mutex_slot_table[8];
NetworkMessageQueueSlot network_message_queue_slot_table[2];
u32 ppp_ipv6cp_protocol_state[0x2A];

#pragma pool_data off

s32 TLobby::cancel_pending_alarms() {
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
    TLobby::cancel_alarm_a();
    TLobby::cancel_alarm_b();
    return 0;
}

void TLobby::get_time_seconds(s32 *out) {
    s64 t = OSGetTime();
    *out = (s32)(t / (s64)(*(u32 *)0x800000F8 >> 2));
}

void TLobby::get_time_ms(s32 *out) {
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
        OSReceiveMessage(&network_message_queue_slot_table[index].queue, &message, OS_MESSAGE_BLOCK);
        NetworkMessageSlot* slot = (NetworkMessageSlot*)message;
        NetMemcpy((void *)(destination), (void *)(slot->data), (int)(size));
        slot->active = 0;
    }
}

#pragma push
#pragma pool_data on
#pragma opt_common_subs on
void TLobby__sub_803F9344(u32 handle, void *src, s32 len) {
    s32 i;
    s32 j;
    for (i = 0; i < 2; i++) {
        if (handle == network_message_queue_slot_table[i].handle) {
            break;
        }
    }
    if (i < 2) {
        for (j = 0; j < 32; j++) {
            if (network_message_queue_slot_table[i].messages[j].active == 0) {
                break;
            }
        }
        if (j < 32) {
            network_message_queue_slot_table[i].messages[j].active = 1;
            NetMemcpy(network_message_queue_slot_table[i].messages[j].data, src, len);
            OSSendMessage(&network_message_queue_slot_table[i].queue, &network_message_queue_slot_table[i].messages[j], 0);
        }
    }
}
#pragma pop

void TLobby::clear_slot_for_handle(u32 handle) {
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

#pragma push
#pragma pool_data on
#pragma opt_common_subs on
s32 TLobby__sub_803F94F0(u32 *out) {
    s32 i;
    for (i = 0; i < 2; i++) {
        if (network_message_queue_slot_table[i].active == 0) {
            break;
        }
    }
    if (i >= 2) {
        return -1;
    }
    OSInitMessageQueue(&network_message_queue_slot_table[i].queue, network_message_queue_slot_table[i].pending, 32);
    network_message_queue_slot_table[i].active = 1;
    *out = network_message_queue_slot_table[i].handle;
    return 0;
}
#pragma pop

void TUdpSocket::unlock_mutex(int _w0) {
    OSUnlockMutex((OSMutex*)_w0);
}

void TLobby::lock_mutex(int _w0) {
    OSLockMutex((OSMutex*)_w0);
}

void NetReleaseMutex(u32 handle) {
    s32 index;
    for (index = 0; index < 8; index++) {
        if (handle == network_mutex_slot_table[index].handle) break;
    }
    if (index < 8) network_mutex_slot_table[index].active = 0;
}

#pragma push
#pragma pool_data on
#pragma opt_common_subs on
s32 TLobby__sub_803F96AC(u32 *out) {
    s32 i;
    for (i = 0; i < 8; i++) {
        if (network_mutex_slot_table[i].active == 0) {
            break;
        }
    }
    if (i >= 8) {
        return -1;
    }
    OSInitMutex(&network_mutex_slot_table[i].mutex);
    network_mutex_slot_table[i].active = 1;
    *out = network_mutex_slot_table[i].handle;
    return 0;
}
#pragma pop

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
    OSSetAlarm(alarm, ticks, (OSAlarmHandler)TLobby::signal_alarm_queue);
    OSRestoreInterrupts(level);
    OSReceiveMessage(&slot->queue, NULL, 1);
    level = OSDisableInterrupts();
    slot->active = 0;
    OSRestoreInterrupts(level);
}
}
u8 *write_network_u32_be(u8 *p, u32 v);
void TLobby::signal_alarm_queue(void *alarm) {
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
s32 NetSetDefaultThreadPriority(s32 arg0);
void NetYieldThread(void) {
    OSYieldThread();
}

void TLobby::resume_thread(s32 thread) {
    OSResumeThread((OSThread*)thread);
}

void NetSuspendCurrentThread(void) {
    OSSuspendThread(OSGetCurrentThread());
}

void TLobby::cancel_thread_if_running() {
    s32 arg0 = (s32)this;
    if (OSIsThreadTerminated((OSThread*)this) == 0) {
        OSCancelThread((OSThread*)arg0);
    }
}

void NetResumeThread(u32 thread) {
    OSResumeThread((OSThread*)thread);
}

void TLobby::deactivate_entry_by_key(u32 key) {
    Ent_803F9B48 *p;
    u16 n = lbl_805D7A68;
    Ent_803F9B48 *base = lbl_805D7A6C;
    p = base;
    s32 i;
    for (i = 0; i < n; i++) {
        if (key == p->key) break;
        p++;
    }
    if (i < n) {
        base[i].active = 0;
    }
}

s32 TLobby__sub_803F9B94(void (*func)(Ent_803F9B48 *), u32 *out) {
    Ent_803F9B48 *p;
    u16 n = lbl_805D7A68;
    Ent_803F9B48 *base = lbl_805D7A6C;
    s32 i;
    p = base;
    for (i = 0; i < n; i++) {
        if (p->active == 0) break;
        p++;
    }
    if (i >= n) {
        return -1;
    }
    base[i].func = func;
    if (OSCreateThread(&lbl_805D7A6C[i].thread, (void *(*)(void *))TLobby::run_current_thread_callback, NULL,
                       lbl_805D7A6C[i].stack + lbl_805D7A6C[i].stack_size, lbl_805D7A6C[i].stack_size,
                       lbl_805D4810, 1) == 1) {
        lbl_805D7A6C[i].active = 1;
        *out = lbl_805D7A6C[i].key;
        return 0;
    }
    return -1;
}

s32 TLobby::run_current_thread_callback() {
    u32 key = (u32)OSGetCurrentThread();
    Ent_803F9C78 *p;
    u16 n = lbl_805D7A68;
    Ent_803F9C78 *base = (*(Ent_803F9C78 * *)&lbl_805D7A6C);
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

s32 NetSetDefaultThreadPriority(s32 arg0) {
    if ((arg0 < 0) || (arg0 > 0x1F)) {
        return -1;
    }
    lbl_805D4810 = arg0;
    return 0;
}

extern "C" {
char* NetAppendString(char* destination, const char* source) {
    return strcat(destination, source);
}

#pragma push
#pragma opt_common_subs on
s32 NetCompareStringsCaseInsensitiveN(u8 *a, u8 *b, u32 n) {
    s16 i;
    s32 ca;
    s32 cb;
    for (i = 0; i < n && *a != 0 && *b != 0; i++, a++, b++) {
        ca = *a;
        cb = *b;
        if (TAdEndText__sub_8039994C(ca) != 0) {
            ca = TAdEndText__sub_80399904(ca);
        }
        if (TAdEndText__sub_8039994C(cb) != 0) {
            cb = TAdEndText__sub_80399904(cb);
        }
        if (ca != cb) {
            return ca - cb;
        }
    }
    if (*a == 0 && *b == 0) {
        return 0;
    }
    if (i == n) {
        return 0;
    }
    return 1;
}
#pragma pop

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
}

s16 TLobby::check_connection_status() {
    u8 *arg0 = (u8 *)this;
    struct Fields_arg0 { u8 field_0; u8 pad_1[7]; s16 field_8; u8 pad_A[2]; u8 * field_C; };
    struct Fields_temp_r31 { u8 field_0; };
    u8 *temp_r31;
    temp_r31 = (u8 *)(((Fields_arg0*)arg0)->field_C);
    if ((TLobby::is_timed_out() != 0) || (((Fields_temp_r31*)temp_r31)->field_0 == 4)) {
        ((Fields_arg0*)arg0)->field_8 = 0;
        return -1;
    }
    if (((Fields_arg0*)arg0)->field_8 != 0) {
        return -2;
    }
    if (((Fields_arg0*)arg0)->field_0 != 5) {
        return 1;
    }
    return 0;
}

#pragma push
#pragma opt_propagation off
struct Proto_803F9FAC {
    const char *name;
    u16 proto;
    u16 h6;
    u8 b8;
    u8 b9;
    u8 bA;
    u8 bB;
    s32 timeout;
    void (*f10)(void);
    void (*f14)(P_803FA2A8 *);
    void (*f18)(u8 *);
    void (*f1C)(TLobby *);
    void (*f20)(void);
    void (*f24)(s32);
    B_803FADA0 *(*f28)(Obj_803FA664 *);
    s16 (*f2C)(Obj_803FA664 *, Msg_803FA664 *, u32);
    s32 (*f30)(Obj_803FA664 *, Msg_803FA664 *, u32);
    s32 (*f34)(Obj_803FA664 *, Msg_803FA664 *, u32);
    s32 (*f38)(Obj_803FA664 *, Msg_803FA664 *, u32);
};

struct Pair_803F9FAC {
    u32 w[2];
};

struct Opts_803F9FAC {
    s16 h0;
    u8 pad2[2];
    Pair_803F9FAC w4[3];
    u8 pad1C[0x34 - 0x1C];
    s16 h34;
    u8 pad36[2];
    Pair_803F9FAC w38[3];
    Pair_803F9FAC w50[3];
};

struct Entry_803F9FAC {
    u8 pad0[0xC];
    u8 *sub;
    u8 pad10[0x2C - 0x10];
    Proto_803F9FAC *proto;
    Opts_803F9FAC *opts;
};

void TLobby__sub_803F9FAC(u8 *conn) {
    Proto_803F9FAC *proto = (Proto_803F9FAC *)ppp_ipv6cp_protocol_state;
    Entry_803F9FAC *e = (Entry_803F9FAC *)(conn + 0xD4);
    Opts_803F9FAC *area = (Opts_803F9FAC *)&ppp_ipv6cp_protocol_state[15];
    const Pair_803F9FAC *tbl = (const Pair_803F9FAC *)lbl_804FD380;
    proto->name = lbl_805E1150;
    proto->proto = 0x8057;
    proto->h6 = 0xFE;
    proto->b8 = 4;
    proto->b9 = 5;
    proto->bA = 5;
    proto->bB = 5;
    proto->timeout = 3000;
    proto->f10 = TLobby__sub_803FA234;
    proto->f14 = TLobby__sub_803FA2A8;
    proto->f18 = TLobby__sub_803FA238;
    proto->f1C = init_net_state_entry__6TLobbyFv;
    proto->f20 = TLobby__sub_803FA280;
    proto->f24 = NetIPv6CPCancelTimer;
    proto->f28 = TLobby__sub_803FABDC;
    proto->f2C = TLobby__sub_803FA7B0;
    proto->f30 = verify_message_sequence__6TLobbyFPvPvUi;
    proto->f34 = TLobby__sub_803FA4A4;
    proto->f38 = TLobby__sub_803FA318;
    e->sub = conn;
    e->proto = proto;
    e->opts = area;
    area->w4[0] = tbl[0];
    area->w4[1] = tbl[1];
    area->w4[2] = tbl[2];
    area->h0 = lbl_805D4818[0];
    area->w38[0] = tbl[0];
    area->w38[1] = tbl[1];
    area->w38[2] = tbl[2];
    area->w50[0] = tbl[0];
    area->w50[1] = tbl[1];
    area->w50[2] = tbl[2];
    area->h34 = lbl_805D4818[0];
    TLobby__sub_803FD694((u8 *)e);
}
#pragma pop

s32 TLobby::clear_flag_bit4(s32 arg0, u8 *arg1) {
    *(s16 *)((s8 *)arg1 + 4) = (s16) (*(s16 *)((s8 *)arg1 + 4) & 0xFFFFFFFB);
    *(s16 *)((s8 *)arg1 + 0) = (s16) (*(s16 *)((s8 *)arg1 + 0) & 0xFFFFFFFB);
    *(s16 *)((s8 *)arg1 + 0x1C) = (s16) (*(s16 *)((s8 *)arg1 + 0x1C) & 0xFFFFFFFB);
    return 0;
}

s32 NetIPv6CPSetInterfaceIdentifier(u8 *arg0, s32 arg1) {
    struct Fields_arg0 { u8 pad_0[4]; s16 field_4; u8 pad_6[2]; s32 field_8; s32 field_C; };
    s32 sp18;
    s32 sp14;
    s32 sp10;
    NetMemset(&sp18, 0xFF, 8);
    if (NetMemcmp((void *)arg1, (void *)((void *)&sp18), 8) != 0) {
        NetMemcpy((void *)((void *)&sp14), (void *)arg1, 4);
        NetMemcpy((void *)&sp10, (void *)(arg1 + 4), 4);
        ((Fields_arg0*)arg0)->field_8 = sp14;
        ((Fields_arg0*)arg0)->field_C = sp10;
        ((Fields_arg0*)arg0)->field_4 = (s16) (((Fields_arg0*)arg0)->field_4 | 2);
    } else {
        ((Fields_arg0*)arg0)->field_8 = 0;
        ((Fields_arg0*)arg0)->field_C = 0;
        ((Fields_arg0*)arg0)->field_4 = (s16) (((Fields_arg0*)arg0)->field_4 & 0xFFFFFFFD);
    }
    return 0;
}

void TLobby__sub_803FA234(void) {

}

void TLobby__sub_803FA238(u8 *arg0) {
    *(s8 *)((s8 *)arg0 + 0xA) = 0;
    *(s8 *)((s8 *)arg0 + 0xB) = 0;
}

void TLobby::init_net_state_entry() {
    s8 *arg0 = (s8 *)this;
  s8 *new_var;
  new_var = (s8 *) (((s8 *) arg0) + ((0, 0)));
  TLobby__sub_80405304((void *)((void *) (((u8 *) arg0) + 0x10)));
  *new_var = 5;
}

void TLobby__sub_803FA280(void) {

}

void NetIPv6CPCancelTimer(s32 arg0) {
    TLobby__sub_80405304((void *)(arg0 + 0x10));
}
extern "C" {

void TLobby__sub_803FA2A8(P_803FA2A8 *o) {
    Q_803FA2A8 *q = o->q;
    q->dst = q->u.src;
    q->dst.w[3] = q->w3C;
    q->dst.w[4] = q->w40;
    q->h0 = q->h0 | q->u.h4;
    q->h50 = 0;
    q->h34 = q->h34 | q->h38;
}

struct Sub_803FA664 { u8 pad0[0x1C]; s16 h1C; u8 pad1E[0x34 - 0x1E]; u8 peer[0x50 - 0x34]; s16 h50; };
struct Obj_803FA664 { u8 pad0; u8 b1; u8 pad2[4]; u8 b6; u8 pad7[4]; u8 bB; u8 padC[0x24]; Sub_803FA664 *p30; };
struct Msg_803FA664 { u8 pad0; u8 b1; s16 h2; };

struct Opts_803FA990 {
    s16 h0;
    u8 pad2[0x8 - 0x2];
    s32 w8;
    s32 wC;
    s32 w10;
    s32 w14;
    u8 pad18[0x20 - 0x18];
    s32 w20;
    s32 w24;
    u8 pad28[0x30 - 0x28];
    s16 h30;
    u8 pad32[0x3C - 0x32];
    s32 w3C;
    s32 w40;
    s32 w44;
    s32 w48;
    u8 pad4C[0x54 - 0x4C];
    s32 w54;
    s32 w58;
};

s16 NetIPv6CPParseConfigureOption(u32 *src, Sub_803FA664 *a, Sub_803FA664 *b, u8 *hdr, s16 flag);

#pragma push
#pragma opt_common_subs on
#pragma dont_inline off
#pragma inline_depth(4)
inline s32 ipv6cp_is_extended_option(u8 type) {
    s32 result = 0;
    if (type >= 0x80 && type < 0x90) {
        result = 1;
    }
    return result;
}

inline s32 ipv6cp_option_bit(u8 type) {
    if (type < 8) {
        return type;
    }
    if (ipv6cp_is_extended_option(type)) {
        return type - 120;
    }
    return 0;
}

inline s32 ipv6cp_read_byte(u32 *src) {
    if (TLobby__sub_80401BCC(src, lbl_805D7A74, 1) != 1) {
        return -1;
    }
    return (s16)lbl_805D7A74[0];
}

s32 TLobby__sub_803FA318(Obj_803FA664 *fsm, Msg_803FA664 *msg, u32 src) {
    Sub_803FA664 *opts = fsm->p30;
    Sub_803FA664 *peer = opts;
    s32 remaining = msg->h2;
    u8 hdr[2];
    s16 n;
    if (msg->b1 != fsm->b1) {
        return -1;
    }
    while (remaining > 0 && (s16)((TLobby *)hdr)->read_2_bytes(&src) != -1) {
        remaining -= hdr[1];
        if (remaining < 0) {
            return -1;
        }
        if ((opts->h1C & (1 << ipv6cp_option_bit(hdr[0]))) == 0) {
            return -1;
        }
        n = hdr[1] - 2;
        while (n-- > 0) {
            if (ipv6cp_read_byte(&src) == -1) {
                return -1;
            }
        }
        opts->h1C &= ~(1 << ipv6cp_option_bit(hdr[0]));
    }
    return 0;
}

s32 TLobby__sub_803FA4A4(Obj_803FA664 *fsm, Msg_803FA664 *msg, u32 src) {
    Sub_803FA664 *opts = fsm->p30;
    Sub_803FA664 *peer = opts;
    s32 remaining = msg->h2;
    u8 hdr[2];
    s16 r;
    if (msg->b1 != fsm->b1) {
        return -1;
    }
    while (remaining > 0 && (s16)((TLobby *)hdr)->read_2_bytes(&src) != -1) {
        remaining -= hdr[1];
        if (remaining < 0) {
            return -1;
        }
        if ((opts->h1C & (1 << ipv6cp_option_bit(hdr[0]))) == 0) {
            opts->h1C |= 1 << ipv6cp_option_bit(hdr[0]);
        }
        r = NetIPv6CPParseConfigureOption(&src, opts, peer, hdr, 0);
        if (r == -1) {
            return -1;
        }
        if (r == 4) {
            opts->h1C &= ~(1 << ipv6cp_option_bit(hdr[0]));
        }
    }
    return 0;
}
#pragma pop

void TLobby__sub_803FACD8(B_803FADA0 **, A_803FADA0 *, s16);
#pragma push
#pragma opt_lifetimes off
#pragma opt_dead_assignments off
#pragma dont_inline off
#pragma inline_depth(4)
inline u32 first_803FA664(Sub_803FA664 *s) {
    u32 t;
    u32 v = 0;
    t = v;
    t = (u32)init_net_buffer_entry__6TLobbyFUs(0);
    if (t == 0) {
        return v;
    }
    TLobby__sub_803FACD8((B_803FADA0 **)&t, (A_803FADA0 *)&s->h1C, s->h1C);
    v = t;
    return v;
}

inline s32 read_803FA664(u32 *p) {
    if (TLobby__sub_80401BCC(p, lbl_805D7A74, 1) != 1) {
        return -1;
    }
    return (s16)lbl_805D7A74[0];
}

s32 verify_message_sequence__6TLobbyFPvPvUi(Obj_803FA664 *arg0, Msg_803FA664 *arg1, u32 arg2) {
    s16 err;
    s16 a;
    s16 b;

    err = 0;
    if (arg1->b1 != arg0->b1) {
        return -1;
    }
    u32 cur = first_803FA664(arg0->p30);
    if (arg1->h2 != ((TLobby *)cur)->get_field_4()) {
        err = 1;
    } else {
        while ((a = read_803FA664(&cur)) != -1) {
            b = read_803FA664(&arg2);
            if (b == -1 || b != a) {
                err = 1;
                break;
            }
        }
    }
    if (err != 0) {
        return -1;
    }
    arg0->bB++;
    return 0;
}
#pragma pop

#pragma push
#pragma opt_common_subs on
#pragma bool off
#pragma dont_inline off
#pragma inline_depth(4)
s16 TLobby__sub_803FA7B0(Obj_803FA664 *fsm, Msg_803FA664 *msg, u32 src) {
    Sub_803FA664 *opts;
    s32 remaining;
    s16 status;
    s16 r;
    B_803FADA0 *reply;
    u8 hdr[2];
    status = 2;
    opts = fsm->p30;
    remaining = msg->h2;
    reply = NULL;
    opts->h50 = 0;
    while (remaining > 0 && (s16)((TLobby *)hdr)->read_2_bytes(&src) != -1) {
        remaining -= hdr[1];
        if (remaining < 0) {
            return -1;
        }
        r = NetIPv6CPParseConfigureOption(&src, opts, (Sub_803FA664 *)opts->peer, hdr, 1);
        if (r == -1) {
            return -1;
        }
        if (r < status) {
            continue;
        }
        if (r > status) {
            reply = NULL;
            status = r;
        }
        if (r != 4) {
            opts->h50 |= 1 << ipv6cp_option_bit(hdr[0]);
        }
        TLobby__sub_803FADA0(&reply, (A_803FADA0 *)&opts->h50, hdr[0], hdr[1], &src);
        if (r > 3) {
            TLobby__sub_803FE6CC(fsm, status, msg->b1, reply);
        }
    }
    if (status == 3) {
        if (fsm->b6 != 0) {
            fsm->b6--;
        } else {
            status = 4;
            TLobby__sub_803FE6CC(fsm, 4, msg->b1, reply);
        }
    }
    if (status > 3) {
        return status != 2;
    }
    TLobby__sub_803FE6CC(fsm, status, msg->b1, reply);
    return status != 2;
}
#pragma pop

#pragma push
#pragma dont_inline off
#pragma inline_depth(4)
inline s32 ipv6cp_read_u16(u32 *src) {
    if (TLobby__sub_80401BCC(src, lbl_805D7A70, 2) != 2) {
        return -1;
    }
    return read_network_u16_be(lbl_805D7A70);
}

inline u32 ipv6cp_read_u32(u32 *src) {
    if (TLobby__sub_80401BCC(src, lbl_805D7A70, 4) != 4) {
        return 0;
    }
    return TLobby__sub_80402AFC(lbl_805D7A70);
}

s16 NetIPv6CPParseConfigureOption(u32 *src, Sub_803FA664 *a, Sub_803FA664 *b, u8 *hdr, s16 flag) {
    Opts_803FA990 *local = (Opts_803FA990 *)a;
    Opts_803FA990 *peer = (Opts_803FA990 *)b;
    s16 len;
    s16 status = 2;
    s32 id;
    len = hdr[1] - 2;
    switch (hdr[0]) {
    case 2:
        peer->h30 = ipv6cp_read_u16(src);
        status = 4;
        len -= 2;
        break;
    case 1:
        peer->w20 = ipv6cp_read_u32(src);
        peer->w24 = ipv6cp_read_u32(src);
        len -= 8;
        if (flag == 0) {
            local->w8 = peer->w20;
            local->wC = peer->w24;
            local->w44 = peer->w20;
            local->w48 = peer->w24;
        } else {
            id = peer->w20;
            if (id != 0 || peer->w24 != 0) {
                local->w3C = id;
                local->w40 = peer->w24;
                local->w10 = peer->w20;
                local->w14 = peer->w24;
            } else {
                status = 3;
                local->w54 = local->w3C;
                local->w58 = local->w40;
            }
        }
        break;
    default:
        status = 4;
        break;
    }
    if (!(peer->h0 & (1 << ipv6cp_option_bit(hdr[0])))) {
        status = 4;
    }
    if (len < 0) {
        return -1;
    }
    if (flag == 0 && len > 0) {
        while (len-- > 0) {
            if (ipv6cp_read_byte(src) == -1) {
                return -1;
            }
        }
    }
    return status;
}
#pragma pop

extern u8 lbl_804FD398[];

#pragma defer_codegen on
#pragma push
#pragma dont_inline off
#pragma inline_depth(4)
void TLobby__sub_803FADA0(B_803FADA0 **arg0, A_803FADA0 *arg1, s32 arg2, s32 arg3, void *arg4) {
    u8 *p;
    B_803FADA0 *b;
    s16 n;
    n = arg3 - 2;
    if (*arg0 != NULL) {
        b = *arg0;
    } else {
        b = init_net_buffer_entry__6TLobbyFUs(0);
        if (b == NULL) {
            return;
        }
        *arg0 = b;
    }
    p = b->buf + b->len;
    p[0] = arg2;
    p[1] = arg3;
    p += 2;
    switch (arg2) {
    case 2:
        break;
    case 1:
        p = write_network_u32_be(write_network_u32_be(p, arg1->a), arg1->b);
        n -= 8;
        break;
    }
    while (n-- > 0) {
        *p++ = TLobby__sub_80401BCC(arg4, lbl_805D7A74, 1) != 1 ? -1 : (s16)lbl_805D7A74[0];
    }
    b->len += arg3;
}

inline void TLobby__sub_803FACD8(B_803FADA0 **pbuf, A_803FADA0 *opts, s16 mask) {
    s16 i;
    u8 len;
    if (*pbuf == NULL) {
        *pbuf = init_net_buffer_entry__6TLobbyFUs(0);
        if (*pbuf == NULL) {
            return;
        }
    }
    for (i = 1; i < 32; i++) {
        if (mask & (1 << i)) {
            TLobby__sub_803FADA0(pbuf, opts, i < 8 ? i : (i < 32 ? i + 120 : 0), len = lbl_804FD398[i], NULL);
        }
    }
}

B_803FADA0 *TLobby__sub_803FABDC(Obj_803FA664 *fsm) {
    Sub_803FA664 *opts = fsm->p30;
    B_803FADA0 *buf = NULL;
    buf = init_net_buffer_entry__6TLobbyFUs(0);
    if (buf == NULL) {
        return NULL;
    }
    TLobby__sub_803FACD8(&buf, (A_803FADA0 *)&opts->h1C, opts->h1C);
    return buf;
}
#pragma defer_codegen off
#pragma pop

s32 TLobby__sub_80405304(void *);

typedef void (*Fn_803FD10C)(void);

#pragma opt_propagation off
#pragma opt_propagation reset

typedef struct A_80403F4C {
    u8 pad0[0x16];
    u8 count;
    u8 pad17[0x40 - 0x17];
} A_80403F4C;

typedef struct B_80403F4C {
    u8 bytes[0x44];
} B_80403F4C;

typedef struct Ent_80403F4C {
    u8 pad0[8];
    A_80403F4C a;
    B_80403F4C b;
} Ent_80403F4C;

typedef struct Obj_80403F4C {
    u8 pad0[4];
    Ent_80403F4C *ents;
    u8 pad8;
    u8 max;
    u8 padA[2];
    u8 cur;
    u8 flags;
    u8 padE[0x28 - 0xE];
    s32 n28;
    u8 pad2C[4];
    s32 n30;
} Obj_80403F4C;

#define o ((Obj_80403F4C *)ov)

#undef o

#pragma dont_inline off
#pragma inline_depth(4)

struct Ent_80408428;
struct Ent_80408428 *find_or_add_peer_entry__6TLobbyFsiUcPvUcPvs(s16, s32, u8, void *, u8, void *, s16);

typedef struct Sub_80408428 {
    s32 f0;
    s16 f4;
    s16 f6;
    u8 pad8[4];
    s32 fC;
} Sub_80408428;

typedef struct Ent_80408428 {
    s16 state;
    s16 stamp;
    u8 type4;
    u8 type5;
    u8 pad6[2];
    Sub_80408428 *sub;
    u8 addrC[6];
    u8 addr12[6];
} Ent_80408428;

#pragma push
#pragma inline_depth(4)
#pragma dont_inline off

Ent_80408428 *find_or_add_peer_entry__6TLobbyFsiUcPvUcPvs(s16 arg0, s32 arg1, u8 type, void *addr, u8 type2, void *addr2, s16 state);

#pragma pop

typedef s32 (*SendFn_80408C24)(s16, u8 *, s16);

#pragma dont_inline off
#pragma inline_depth(4)

typedef void (*CbA_8040C540)(s16, s32, s16, s32, s16);
typedef void (*CbB_8040C540)(s16, u32, s16);

typedef void (*Handler_8041A130)(s32, s16, s16, s16);

}
