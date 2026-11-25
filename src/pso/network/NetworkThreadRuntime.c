/* The network stack's OS layer, second file (a C library, built with GC/1.2.5n): the thread helpers, sleeping on an
 * alarm of NetworkRuntime.c's alarm table, the string helpers, and a few configure-option helpers of the PPP IPv6
 * control protocol. Split from NetworkRuntime.c: signal_alarm_queue addresses the alarm table as an extern while
 * the functions before it pool the tables as their own file's data. */
#include "types.h"
#include "pso/network/NetConfig.h"
#include "pso/network/Ppp.h"
#include "pso/network/NetStack.h"
#include "pso/network/PppChap.h"
#include "string.h"
#include <ctype.h>
#include "dolphin/os/OSThread.h"
#include "dolphin/os/OSAlarm.h"
#include "dolphin/os/OSTime.h"
#include "dolphin/os/OSInterrupt.h"
#include "pso/network/NetworkRuntime.h"
#include "pso/network/PppFsm.h"
#include "pso/network/NetworkRuntimeSlots.h"
#include "pso/network/NetworkPacketPool.h"
#include "pso/network/ModemSession.h"
#include "pso/network/PppApi.h"


#include "pso/network/PppBuffer.h"

/* The scratch bytes the configure-option readers below read a 16/32-bit or 8-bit field into. */
u8 ppp_option_byte_buf[1];
u8 ppp_option_word_buf[4];

#define PCO_RD16(p) (ppp_buffer_read((p), ppp_option_word_buf, 2) != 2 ? -1 : read_network_u16_be(ppp_option_word_buf))
#define PCO_RD32(p) (ppp_buffer_read((p), ppp_option_word_buf, 4) != 4 ? 0 : read_network_u32_be(ppp_option_word_buf))
#define PCO_RD8(p) (ppp_buffer_read((p), ppp_option_byte_buf, 1) != 1 ? -1 : (s16)ppp_option_byte_buf[0])

void NetStoreCurrentThread(NetThreadHandle *thread) {
    *thread = OSGetCurrentThread();
}

void net_sleep_ms(s32 ms) {
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

void resume_thread(NetThreadHandle thread) {
    OSResumeThread(thread);
}

void NetSuspendCurrentThread(void) {
    OSSuspendThread(OSGetCurrentThread());
}

/* Cancels the thread unless it already terminated. */
void AT_TerminateTask(NetThreadHandle thread) {
    if (OSIsThreadTerminated(thread) == 0) {
        OSCancelThread(thread);
    }
}

void AT_StartTask(NetThreadHandle thread) {
    OSResumeThread(thread);
}

void AT_DeleteTask(NetThreadHandle thread) {
    NetworkThreadSlot *p;
    u16 n = lobby_thread_pool_count;
    NetworkThreadSlot *base = lobby_thread_pool_base;
    s32 i;
    p = base;
    for (i = 0; i < n; i++) {
        if (thread == p->key) break;
        p++;
    }
    if (i < n) {
        base[i].active = 0;
    }
}

s16 AT_CreateTask(NetThreadEntry entry, NetThreadHandle *out_key) {
    u16 n = lobby_thread_pool_count;
    NetworkThreadSlot *tbl = lobby_thread_pool_base;
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
        s32 off = i * sizeof(NetworkThreadSlot);
        NetworkThreadSlot *slot = (NetworkThreadSlot *)((u8 *)tbl + off);
        slot->entry = entry;
        slot = (NetworkThreadSlot *)((u8 *)lobby_thread_pool_base + off);
        if (OSCreateThread((OSThread *)((u8 *)lobby_thread_pool_base + off + offsetof(NetworkThreadSlot, thread)), run_current_thread_callback, NULL,
                           slot->stack + slot->stack_size, slot->stack_size, net_default_thread_priority, 1) == 1) {
            lobby_thread_pool_base[i].active = 1;
            *out_key = lobby_thread_pool_base[i].key;
            return 0;
        }
    }
    return -1;
}

#pragma push
#pragma opt_propagation off
void *run_current_thread_callback(void *unused) {
    NetThreadHandle key = OSGetCurrentThread();
    NetworkThreadSlot *p;
    u16 n = lobby_thread_pool_count;
    NetworkThreadSlot *base = lobby_thread_pool_base;
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
        NetworkThreadSlot *e = &base[i];
        NetThreadEntry entry = e->entry;
        entry();
    }
    return 0;
}
#pragma pop

s32 NetSetDefaultThreadPriority(s32 priority) {
    if ((priority < 0) || (priority > 0x1F)) {
        return -1;
    }
    net_default_thread_priority = priority;
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
        if (islower(c1)) {
            c1 = toupper(c1);
        }
        if (islower(c2)) {
            c2 = toupper(c2);
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

s32 NetMemcmp(const void *left, const void *right, int size) {
    return memcmp(left, right, size);
}

void NetMemset(void* destination, int value, int size) {
    memset(destination, value, size);
}

void NetMemcpy(void *destination, const void *source, int size) {
    memcpy(destination, source, size);
}

s16 check_connection_status(PppFsm *fsm) {
    PppProtoBlocks *blocks;
    blocks = fsm->blocks;
    if ((is_timed_out() != 0) || (blocks->phase == 4)) {
        fsm->abort = 0;
        return -1;
    }
    if (fsm->abort != 0) {
        return -2;
    }
    if (fsm->state != 5) {
        return 1;
    }
    return 0;
}

typedef struct Ipv6cpProtocolState {
    PppFsmProtocol proto;
    Ipv6cpConfig config;
    u8 padA4[4];
} Ipv6cpProtocolState;
LAYOUT_ASSERT(Ipv6cpProtocolState_size, sizeof(Ipv6cpProtocolState) == 0xA8);
extern Ipv6cpProtocolState ppp_ipv6cp_protocol_state;
Ipv6cpOptionSet ipv6cp_default_options = {0};
/* inferred: the default option mask of both IPv6CP option blocks, one bit per option type (6: types 1 and 2, the
 * types ipv6cp_option_lengths gives lengths 10 and 6, Interface-Identifier and IPv6-Compression-Protocol). */
s16 ipv6cp_default_option_flags = 6;
PppFrame *build_ipv6cp_config_request(PppFsm *self);
s16 recv_ipv6cp_config_nak(PppFsm *self, PppHeader *src, PppFrame *h);
s16 recv_ipv6cp_config_request(PppFsm *self, PppHeader *src, PppFrame *h);
s16 recv_ipv6cp_config_reject(PppFsm *self, PppHeader *src, PppFrame *h);
void init_ipv6cp_protocol(PppProtoBlocks *connection) {
    Ipv6cpOptionSet *src = &ipv6cp_default_options;
    PppFsmProtocol *base = &ppp_ipv6cp_protocol_state.proto;
    PppFsm *sub;
    Ipv6cpConfig *blk;

    base->name = "IPv6cp";
    base->proto = 0x8057;
    base->code_mask = 0xFE;
    base->tx_counter_index = 4;
    base->max_request_attempts = 5;
    base->max_peer_attempts = 5;
    base->max_terminate_attempts = 5;
    base->timeout = 0xBB8;
    base->release_resources = ipv6cp_release_resources;
    base->reset_options = ipv6cp_reset_options;
    base->start_negotiation = ipv6cp_start_negotiation;
    base->link_opened = ipv6cp_opening;
    base->link_closed = ipv6cp_link_closed;
    base->finish_termination = NetIPv6CPCancelTimer;
    base->build_config_request = build_ipv6cp_config_request;
    base->check_config_request = recv_ipv6cp_config_request;
    base->check_config_ack = verify_message_sequence;
    base->check_config_nak = recv_ipv6cp_config_nak;
    base->check_config_reject = recv_ipv6cp_config_reject;

    sub = &connection->ipv6cp;
    sub->blocks = connection;
    sub->proto = base;
    blk = &ppp_ipv6cp_protocol_state.config;
    sub->opts = blk;
    blk->local.current = *src;
    blk->local.flags = ipv6cp_default_option_flags;
    blk->peer.current = *src;
    blk->peer.requested = *src;
    blk->peer.flags = ipv6cp_default_option_flags;
    fsm_init(sub);
}

s16 clear_flag_bit4(s32 unused, Ipv6cpOptions *opts) {
    opts->current.mask &= ~4;
    opts->flags &= ~4;
    opts->requested.mask &= ~4;
    return 0;
}

s16 NetIPv6CPSetInterfaceIdentifier(Ipv6cpOptions *state, u8 *ident) {
    u8 all_ones[8];
    s32 high;
    s32 low;
    NetMemset(all_ones, 0xFF, 8);
    if (NetMemcmp(ident, all_ones, 8) != 0) {
        NetMemcpy(&high, ident, 4);
        NetMemcpy(&low, ident + 4, 4);
        state->current.words[0] = high;
        state->current.words[1] = low;
        state->current.mask = (s16) (state->current.mask | 2);
    } else {
        state->current.words[0] = 0;
        state->current.words[1] = 0;
        state->current.mask = (s16) (state->current.mask & 0xFFFFFFFD);
    }
    return 0;
}

void ipv6cp_release_resources(PppFsm *fsm) {

}

void ipv6cp_start_negotiation(PppFsm *entry) {
    entry->padA = 0;
    entry->ack_count = 0;
}

void ipv6cp_opening(PppFsm *entry) {
    PppFsm *fsm = entry;
    u8 *state = &fsm->state;
    lobby_timer_stop(&entry->timer);
    *state = 5;
}

void ipv6cp_link_closed(PppFsm *fsm) {

}

void NetIPv6CPCancelTimer(PppFsm *entry) {
    lobby_timer_stop(&entry->timer);
}

void ipv6cp_reset_options(PppFsm *o) {
    Ipv6cpConfig *q = o->opts;
    q->local.requested = q->local.current;
    q->local.requested.words[2] = q->peer.current.words[0];
    q->local.requested.words[3] = q->peer.current.words[1];
    q->local.flags = q->local.flags | q->local.current.mask;
    q->peer.requested.mask = 0;
    q->peer.flags = q->peer.flags | q->peer.current.mask;
}

#pragma push
#pragma dont_inline off
#pragma inline_depth(4)
s16 recv_ipv6cp_config_reject(PppFsm *self, PppHeader *src, PppFrame *h) {
    Ipv6cpConfig *m = self->opts;
    s32 cnt = src->len;
    s16 k;
    s32 r;
    u32 bit;
    s32 len;
    s32 pad;
    u8 pair[2];

    if (src->id != self->id) {
        return -1;
    }
    while (cnt > 0 && (s16)read_2_bytes(pair, &h) != -1) {
        len = pair[1];
        cnt -= len;
        if (cnt < 0) {
            return -1;
        }
        bit = ppp_configure_option_bit(pair[0]);
        if (!(m->local.requested.mask & (1 << bit))) {
            return -1;
        }
        for (k = len - 2; k-- > 0;) {
            r = PCO_RD8(&h);
            if (r == -1) {
                return -1;
            }
        }
        bit = ppp_configure_option_bit(pair[0]);
        m->local.requested.mask &= ~(1 << bit);
    }
    return 0;
}
#pragma pop

s16 NetIPv6CPParseConfigureOption(PppFrame **self, Ipv6cpConfig *out, Ipv6cpOptions *src, u8 *c, s16 flag);
#pragma push
#pragma dont_inline off
#pragma inline_depth(4)
#pragma opt_common_subs on
s16 recv_ipv6cp_config_nak(PppFsm *self, PppHeader *src, PppFrame *h) {
    Ipv6cpConfig *bits;
    Ipv6cpOptions *p;
    s32 cnt;
    uaddr m;
    s16 r;
    u32 bit;
    s32 f;
    u8 pair[2];
    m = (uaddr)self->opts;
    cnt = src->len;
    bits = (Ipv6cpConfig *)m;
    p = (Ipv6cpOptions *)m;
    if (src->id != self->id) {
        return -1;
    }
    while (cnt > 0 && (s16)read_2_bytes(pair, &h) != -1) {
        cnt -= pair[1];
        if (cnt < 0) {
            return -1;
        }
        if (pair[0] < 8) { bit = pair[0]; } else { f = 0; if (pair[0] >= 0x80 && pair[0] < 0x90) { f = 1; } if (f) { bit = pair[0] - 0x78; } else { bit = 0; } }
        if (!(bits->local.requested.mask & (1 << bit))) {
            bit = ppp_configure_option_bit(pair[0]);
            bits->local.requested.mask |= 1 << bit;
        }
        r = NetIPv6CPParseConfigureOption(&h, bits, p, pair, 0);
        if (r == -1) {
            return -1;
        }
        if (r == 4) {
            bit = ppp_configure_option_bit(pair[0]);
            bits->local.requested.mask &= ~(1 << bit);
        }
    }
    return 0;
}
#pragma pop

#pragma push
#pragma opt_lifetimes off
#pragma opt_dead_assignments off
#pragma dont_inline off
#pragma inline_depth(4)
static inline PppFrame *build_requested_options(Ipv6cpOptions *opts) {
    PppFrame *t;
    PppFrame *v = NULL;
    t = v;
    t = init_net_buffer_entry(0);
    if (t == NULL) {
        return v;
    }
    append_masked_ipv6cp_options(&t, &opts->requested, opts->requested.mask);
    v = t;
    return v;
}

static inline s32 read_option_byte(PppFrame **p) {
    if (ppp_buffer_read(p, ppp_option_byte_buf, 1) != 1) {
        return -1;
    }
    return (s16)ppp_option_byte_buf[0];
}

s16 verify_message_sequence(PppFsm *fsm, PppHeader *msg, PppFrame *expected) {
    s16 err;
    s16 a;
    s16 b;
    PppFrame *cur;

    err = 0;
    if (msg->id != fsm->id) {
        return -1;
    }
    cur = build_requested_options((Ipv6cpOptions *)fsm->opts);
    if (msg->len != (u16)ppp_frame_length(cur)) {
        err = 1;
    } else {
        while ((a = read_option_byte(&cur)) != -1) {
            b = read_option_byte(&expected);
            if (b == -1 || b != a) {
                err = 1;
                break;
            }
        }
    }
    if (err != 0) {
        return -1;
    }
    fsm->ack_count++;
    return 0;
}
#pragma pop

#pragma push
#pragma dont_inline off
#pragma inline_depth(4)
s16 recv_ipv6cp_config_request(PppFsm *self, PppHeader *src, PppFrame *h)
{
  u32 sh;
  PppFrame *blk;
  Ipv6cpConfig *m;
  s32 cnt;
  s16 r;
  u8 pair[2];
  s16 state;
  s16 res;
  Ipv6cpConfig *new_var;
  new_var = self->opts;
  m = new_var;
  cnt = src->len;
  state = 2;
  blk = 0;
  m->peer.requested.mask = 0;
  while ((cnt > 0) && (((s16) read_2_bytes(pair, &h)) != (-1)))
  {
    cnt -= pair[1];
    if (cnt < 0)
    {
      return -1;
    }
    res = NetIPv6CPParseConfigureOption(&h, m, &m->peer, pair, 1);
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
      sh = ppp_configure_option_bit(pair[0]);
      m->peer.requested.mask |= 1 << sh;
    }
    append_ipv6cp_option(&blk, &m->peer.requested, pair[0], pair[1], &h);
    if (res > 3)
    {
      ppp_fsm_send_packet(self, state, src->id, blk);
    }
  }

  if (state == 3)
  {
    if (self->peer_attempts_left != 0)
    {
      self->peer_attempts_left--;
    }
    else
    {
      state = 4;
      ppp_fsm_send_packet(self, 4, src->id, blk);
    }
  }
  if (state > 3)
  {
    return (s16) (2 != state);
  }
  ppp_fsm_send_packet(self, state, src->id, blk);
  return (s16) (2 != state);
}
#pragma pop
s16 NetIPv6CPParseConfigureOption(PppFrame **self, Ipv6cpConfig *out, Ipv6cpOptions *src, u8 *c, s16 flag) {
    s16 rem;
    s16 r = 2;
    u32 idx;
    rem = c[1] - 2;
    switch (c[0]) {
    case 2:
        src->requested.compression_protocol = PCO_RD16(self);
        r = 4;
        rem -= 2;
        break;
    case 1:
        src->requested.words[0] = PCO_RD32(self);
        src->requested.words[1] = PCO_RD32(self);
        rem -= 8;
        if (flag == 0) {
            out->local.current.words[0] = src->requested.words[0];
            out->local.current.words[1] = src->requested.words[1];
            out->peer.current.words[2] = src->requested.words[0];
            out->peer.current.words[3] = src->requested.words[1];
        } else {
            s32 a = (s32)src->requested.words[0];
            if (a != 0 || (s32)src->requested.words[1] != 0) {
                out->peer.current.words[0] = a;
                out->peer.current.words[1] = src->requested.words[1];
                out->local.current.words[2] = src->requested.words[0];
                out->local.current.words[3] = src->requested.words[1];
            } else {
                r = 3;
                out->peer.requested.words[0] = out->peer.current.words[0];
                out->peer.requested.words[1] = out->peer.current.words[1];
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
    if (!(src->flags & (1 << idx))) {
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

/* Option lengths indexed by IPv6CP option number. */
u8 ipv6cp_option_lengths[16] = {0x00, 0x0A, 0x06, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x00, 0x06, 0x00, 0x00, 0x00, 0x00};
PppFrame *build_ipv6cp_config_request(PppFsm *self) {
    s16 i;
    s16 bits;
    u8 *s;
    Ipv6cpConfig *p;
    PppFrame *obj;

    p = self->opts;
    obj = 0;
    obj = init_net_buffer_entry(0);
    if (obj == NULL) {
        return NULL;
    }
    bits = p->local.requested.mask;
    if (obj == NULL) {
        obj = init_net_buffer_entry(0);
        if (obj == NULL) {
            goto done;
        }
    }
    s = ipv6cp_option_lengths + 1;
    for (i = 1; i < 0x20; i++) {
        if (bits & (1 << i)) {
            append_ipv6cp_option(&obj, &p->local.requested, (i < 8) ? i : ((i < 0x20) ? i + 0x78 : 0), *s, NULL);
        }
        s++;
    }
done:
    return obj;
}

static inline s32 ppp_option_type(s32 bit) {
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
void append_masked_ipv6cp_options(PppFrame **self, Ipv6cpOptionSet *opts, s32 mask)
{
  s16 new_var;
  s16 i;
  s32 m;
  if ((*self) == NULL)
  {
    *self = init_net_buffer_entry(0);
    if ((*self) == NULL)
    {
      return;
    }
  }
  m = (new_var = (s16) mask);
  for (i = 1; i < 0x20; i++)
  {
    if (m & (1 << i))
    {
      append_ipv6cp_option(self, opts, ppp_option_type(i), ipv6cp_option_lengths[i], 0);
    }
  }

}
#pragma pop
void append_ipv6cp_option(PppFrame **pbuf, Ipv6cpOptionSet *opts, s32 type, s32 total_len, PppFrame **src) {
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
        p = write_network_u32_be(write_network_u32_be(p, opts->words[0]), opts->words[1]);
        n -= 8;
        break;
    }
    while (n-- > 0) {
        *p++ = ppp_buffer_read(src, ppp_option_byte_buf, 1) != 1 ? -1 : (s16)ppp_option_byte_buf[0];
    }
    b->len += total_len;
}

Ipv6cpProtocolState ppp_ipv6cp_protocol_state;
