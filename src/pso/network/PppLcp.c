/* PPP LCP, the protocol that names itself "Lcp" (805E1178), and its state object (.bss 805C0400) (a C library,
 * built with GC/1.2.5n). */
#include "types.h"
#include "pso/network/TLobby_803FC178.h"
#include "pso/network/TLobby_803FCF44.h"
#include "pso/network/PppFsm.h"
#include "pso/network/TLobby_804050DC.h"
#include "pso/network/TLobby_8041112C.h"
#include "pso/network/PppLcp.h"
typedef struct St_8040098C St_8040098C;
#include "pso/network/NetworkRuntime.h"
#include "pso/network/TLobby_804048E8.h"
extern s32 is_timed_out(void);
extern void ppp_set_auth(u16 protocol);
#include "pso/network/NetworkTransport.h"

struct St_8040098C { s8 f0; u8 f1; u8 f2; u8 pad3[0x69]; u8 f6C[0x9C]; s32 f108; s32 f10C; };

#include <stddef.h>
#include "pso/network/NetStackTypes.h"

void net_sleep_ms(s32 ms);
#include "pso/network/PppBuffer.h"

/* The option values both sides start from: MRU 1500 and a full async control-character map (.rodata 8047FE50). */
const LcpVals lbl_8047FE50 = {0, 1500, 0xFFFFFFFF};
/* Each option's length, by option type (.rodata 8047FE68). */
const u8 lbl_8047FE68[16] = {4, 4, 6, 4, 4, 6, 6, 2, 2};
/* The option readers' scratch bytes (.sbss 805D7AB0), in reverse definition order. */
u8 lobby_read_byte_buffer[1];
u8 lcp_read_value_buffer[4];


s16 wait_for_connection(PppFsm *c) {
    NetThreadState *g;
    u8 *sub;
    sub = c->sub;
    g = &lbl_805C18A0;
    c->abort = 0;
    while (c->state != 5) {
        if (is_timed_out() != 0 || c->abort != 0 || *sub == 4) {
            update_connection_state(c);
            c->abort = 0;
            return -1;
        }
        unlock_mutex(g->mutex);
        net_sleep_ms(100);
        process_expired_timers();
        lock_mutex(g->mutex);
    }
    c->abort = 0;
    return 0;
}

PppFrame *TLobby__sub_8040172C(PppFsm *c);
s16 recv_lcp_config_reject(PppFsm *fsm, PppHeader *msg, PppFrame *src);
s16 recv_lcp_config_nak(PppFsm *fsm, PppHeader *msg, PppFrame *src);
s16 recv_lcp_config_request(PppFsm *fsm, PppHeader *msg, PppFrame *src);
s16 verify_lcp_config_ack(PppFsm *fsm, PppHeader *msg, PppFrame *expected);

void init_lcp_protocol(u8 *conn)
{
  PppFsmProtocol *proto = &lbl_805C0400.proto;
  PppFsm *e = (PppFsm *)(conn + 4);
  LcpOpts *area = &lbl_805C0400.opts;
  const LcpVals *tbl = &lbl_8047FE50;
  proto->name = "Lcp";
  proto->proto = 0xC021;
  proto->h6 = 0xFFE;
  proto->tx_counter_index = 0;
  proto->max_request_attempts = 20;
  proto->max_peer_attempts = 10;
  proto->max_terminate_attempts = 3;
  proto->timeout = 1000;
  proto->release_resources = lcp_noop_callback;
  proto->reset_options = reset_lcp_options;
  proto->start_negotiation = mark_lcp_starting;
  proto->link_opened = setup_auth_after_lcp_negotiation;
  proto->link_closed = reset_connection_slot;
  proto->finish_termination = queue_command_81;
  proto->build_config_request = TLobby__sub_8040172C;
  proto->check_config_request = recv_lcp_config_request;
  proto->check_config_ack = verify_lcp_config_ack;
  proto->check_config_nak = recv_lcp_config_nak;
  proto->check_config_reject = recv_lcp_config_reject;
  e->sub = conn;
  e->proto = proto;
  e->opts = area;
  area->local.want = *tbl;
  area->local.mask = 0x1AE;
  area->remote.want = *tbl;
  area->remote.got = *tbl;
  area->remote.mask = 0x1AE;
  TLobby__sub_803FD694(e);
}

s16 apply_lcp_config_to_sides(PppFsm *state, LcpConfig *config) {
    s32 pad[2];
    s32 *pp;
    /* Preserve the original argument and local register allocation. */
    PppFsm *s = (PppFsm *)(u8 *)state;
    LcpConfig *msg = (LcpConfig *)(u8 *)config;
    LcpSide *p;
    LcpSide *q;
    LcpSide *t;
    u16 m6;
    u32 id;
    s32 sid;
    u32 v;
    u32 w;
    pp = pad;

    TLobby__sub_803FE600((O_803FE600 *)s);
    PP_doppp_active(s);
    *s->sub = 1;
    if (*s->sub >= 1) {
        id = msg->mru;
        p = t = s->opts;
        sid = (s16)id;
        if (sid >= 0x80 && sid <= 0x1000) {
            t->want.mask |= 2;
            t->want.mru = (u16)id;
        }
        p->want.accm = msg->accm;
        if (p->want.accm != 0xffffffff) {
            p->want.mask |= 4;
            p->mask |= 4;
        } else {
            p->want.mask &= ~4;
            p->mask &= ~4;
        }
        m6 = msg->auth_mode;
        if ((m6 & 0x80) || m6 == 4) {
            configure_mode_by_type(p + 1, m6 & 0x7f);
            if (lbl_805D7A90 & 2) {
                configure_mode_by_type(p, msg->auth_mode & 0x7f);
            }
        } else {
            configure_mode_by_type(p + 1, m6);
            configure_mode_by_type(p, (s16)msg->auth_mode);
        }
        v = msg->magic;
        if (v != 0) {
            p->want.mask |= 0x20;
        } else {
            p->want.mask &= ~0x20;
        }
        p->want.magic = v;
        if (msg->fE == 0) {
            p->mask |= 0x80;
        } else {
            p->mask &= ~0x80;
        }
        if (msg->f4 == 0) {
            p->mask |= 0x100;
        } else {
            p->mask &= ~0x100;
        }
        q = p + 1;
        w = msg->magic;
        if (w != 0) {
            q->want.mask |= 0x20;
        } else {
            q->want.mask &= ~0x20;
        }
        q->want.magic = w;
        q = p + 1;
        if (msg->fE == 0) {
            q->mask |= 0x80;
        } else {
            q->mask &= ~0x80;
        }
        q = p + 1;
        if (msg->f4 == 0) {
            q->mask |= 0x100;
        } else {
            q->mask &= ~0x100;
        }
        TLobby__sub_803FD958((u8 *)s);
    }
    return 0;
}

void lcp_noop_callback(PppFsm *fsm) {

}

void setup_auth_after_lcp_negotiation(PppFsm *c) {
    LcpOpts *info = c->opts;
    St_8040098C *st;
    u32 now;

    ((St_8040098C *)c->sub)->f0 = 2;
    ((St_8040098C *)c->sub)->f2 &= ~0x30;
    ((St_8040098C *)c->sub)->f10C = 0;
    if (info->local.got.mask & 8) {
        switch (info->local.got.auth_proto) {
        case 0xC023:
            set_active(c->sub);
            break;
        case 0xC223:
            mark_sub_ready(c->sub);
            set_active_flag(c->sub);
            break;
        }
    }
    if (info->remote.got.mask & 8) {
        switch (info->remote.got.auth_proto) {
        case 0xC023:
            mark_ready(c->sub);
            break;
        case 0xC223:
            set_active_flag(c->sub);
            mark_sub_ready(c->sub);
            break;
        }
    }
    st = (St_8040098C *)c->sub;
    if (!(st->f2 & 0x30)) {
        st->f0 = 3;
        get_time_ms((s32 *)&now);
        st->f108 = (s16)(now / 1000);
        TLobby__sub_803FD958(st->f6C);
    }
}

void start_ipcp_after_auth(O_80400ACC *o) {
    u32 t;
    if ((o->b2 & 0x30) == 0) {
        o->b0 = 3;
        get_time_ms((s32 *)&t);
        o->f108 = (s16)(t / 1000);
        TLobby__sub_803FD958((u8 *)o + 0x6C);
    }
}

void reset_connection_slot(PppFsm *self) {
    s8 *sub;
    sub = (s8 *)self->sub;
    *sub = 4;
    TLobby__sub_803FD85C(sub + 0x6C);
    PP_pap_down((void *)(sub + 0x38));
}

void queue_command_81(PppFsm *fsm) {
    TLobby__sub_804062A0(0x81);
}

void mark_lcp_starting(PppFsm *arg0) {
    *arg0->sub = 1;
}

void reset_lcp_options(PppFsm *self) {
    LcpOpts *s;
    s32 t;
    s = self->opts;
    if (s->local.want.mask & 0x20) {
        get_time_ms(&t);
        s->local.want.magic += t;
    }
    s->local.got = s->local.want;
    s->local.mask |= s->local.want.mask;
    s->remote.got.mask = 0;
    s->remote.mask |= s->remote.want.mask;
}

s16 recv_lcp_config_reject(PppFsm *fsm, PppHeader *msg, PppFrame *src) {
    s16 last = 0;
    LcpOpts *o = fsm->opts;
    s32 left = msg->len;
    u8 opt[12];
    s16 n;
    u8 len;
    u8 type;

    if (msg->id != fsm->id) {
        return -1;
    }
    while (left > 0 && (s16)read_2_bytes((opt), &src) != -1) {
        len = opt[1];
        left -= len;
        if (left < 0) {
            return -1;
        }
        if (opt[0] <= 8 && (opt[0] < last || !(o->local.got.mask & (1 << opt[0])))) {
            return -1;
        }
        for (n = len - 2; n-- > 0;) {
            if ((ppp_buffer_read(&src, lobby_read_byte_buffer, 1) != 1 ? -1 : (s16)lobby_read_byte_buffer[0]) == -1) {
                return -1;
            }
        }
        last = type = opt[0];
        if (type <= 8 && (type != 3 || !(o->local.got.mask & (1 << type)))) {
            o->local.got.mask &= ~(1 << type);
        }
    }
    return 0;
}

#pragma push
#pragma opt_common_subs on
s16 recv_lcp_config_nak(PppFsm *fsm, PppHeader *msg, PppFrame *src) {
    LcpOpts *opts = fsm->opts;
    LcpSide *local = &opts->local;
    s32 remaining = msg->len;
    s16 last = 0;
    u8 hdr[2];
    s16 r;
    if (msg->id != fsm->id) {
        return -1;
    }
    while (remaining > 0 && (s16)read_2_bytes((hdr), &src) != -1) {
        remaining -= hdr[1];
        if (remaining < 0) {
            return -1;
        }
        if (hdr[0] <= 8) {
            if (hdr[0] < last || (opts->local.got.mask & (1 << hdr[0])) == 0) {
                if (opts->local.got.mask & (1 << hdr[0])) {
                    return -1;
                }
                opts->local.got.mask |= 1 << hdr[0];
                last = 9;
            } else {
                last = hdr[0];
            }
        }
        r = parse_lcp_option((saddr)&src, (u8 *)opts, (u8 *)local, hdr, 0);
        if (r == -1) {
            return -1;
        }
        if (r == 4 && hdr[0] <= 8 && (hdr[0] != 3 || (opts->local.got.mask & (1 << hdr[0])) == 0)) {
            opts->local.got.mask &= ~(1 << hdr[0]);
        }
    }
    return 0;
}
#pragma pop
extern void TLobby__sub_804017D8(uaddr *self_m, void *src, u8 idx, u8 val, s32 *flag);
inline void loop_8040172C(uaddr *self, void *src, s16 mask) {
    s16 i;
    i = 1;
    while (i <= 8) {
        if (mask & (1 << i)) {
            TLobby__sub_804017D8(self, src, i, lbl_8047FE68[i], 0);
        }
        i++;
    }
}
inline s32 read_option_byte(void *p) {
    if (ppp_buffer_read(p, lobby_read_byte_buffer, 1) != 1) {
        return -1;
    }
    return (s16)lobby_read_byte_buffer[0];
}
#pragma push
#pragma dont_inline off
#pragma inline_depth(4)
inline uaddr build_requested_options(PppFsm *fsm) {
    LcpOpts *o = (LcpOpts *)fsm->opts;
    uaddr t = 0;
    t = (uaddr)init_net_buffer_entry(0);
    if (t == 0) {
        return 0;
    }
    loop_8040172C(&t, &o->local.got, o->local.got.mask);
    return t;
}
s16 verify_lcp_config_ack(PppFsm *fsm, PppHeader *msg, PppFrame *expected) {
    s16 err;
    s16 a;
    s16 b;
    err = 0;
    if (msg->id != fsm->id) {
        return -1;
    }
    {
        uaddr cur = build_requested_options(fsm);
        if (msg->len != (u16)get_field_4((PppFrame *)cur)) {
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
    }
    if (err != 0) {
        return -1;
    }
    return 0;
}
#pragma pop

#pragma push
#pragma dont_inline off
#pragma inline_depth(4)
inline void add_lcp_options(PppFrame **pbuf, s16 *vals, s16 mask) {
    s16 i;

    for (i = 1; i <= 8; i++) {
        if (mask & (1 << i)) {
            TLobby__sub_804017D8((uaddr *)pbuf, vals, i, lbl_8047FE68[i], NULL);
        }
    }
}

s16 recv_lcp_config_request(PppFsm *fsm, PppHeader *msg, PppFrame *src) {
    LcpOpts *opts;
    s32 remaining;
    s16 status;
    s16 r;
    PppFrame *reply;
    u8 hdr[2];
    s16 missing;

    status = 2;
    opts = (LcpOpts *)fsm->opts;
    remaining = msg->len;
    reply = NULL;
    opts->remote.got.mask = 0;
    reply = init_net_buffer_entry(1);
    if (opts->remote.want.f15 != 0) {
        opts->remote.got.auth_proto = 0;
        opts->remote.got.mask |= 8;
    }
    while (remaining > 0 && (s16)read_2_bytes(hdr, &src) != -1) {
        remaining -= hdr[1];
        if (remaining < 0) {
            return -1;
        }
        r = parse_lcp_option((saddr)&src, (u8 *)opts, (u8 *)&opts->remote, hdr, 1);
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
        if (r != 4 && hdr[0] <= 8) {
            opts->remote.got.mask |= 1 << hdr[0];
        }
        TLobby__sub_804017D8((uaddr *)&reply, &opts->remote.got.mask, hdr[0], hdr[1], (s32 *)&src);
        if (r >= 3) {
            ppp_fsm_send_packet(fsm, status, msg->id, reply);
        }
    }
    missing = opts->remote.want.mask & ~opts->remote.got.mask;
    if (status == 3) {
        if (fsm->f6 != 0) {
            add_lcp_options(&reply, &opts->remote.got.mask, missing);
            fsm->f6--;
        } else {
            status = 4;
            ppp_fsm_send_packet(fsm, 4, msg->id, reply);
        }
    }
    if (status >= 3) {
        return status != 2;
    }
    ppp_fsm_send_packet(fsm, status, msg->id, reply);
    return status != 2;
}
#pragma pop

#define rd16_804012E0(src) (ppp_buffer_read((void *)(src), lcp_read_value_buffer, 2) != 2 ? -1 : read_network_u16_be(lcp_read_value_buffer))
#define rd32_804012E0(src) (ppp_buffer_read((void *)(src), lcp_read_value_buffer, 4) != 4 ? 0 : TLobby__sub_80402AFC(lcp_read_value_buffer))
#define rd8_804012E0(src) (ppp_buffer_read((void *)(src), lobby_read_byte_buffer, 1) != 1 ? -1 : (s16)lobby_read_byte_buffer[0])
s16 parse_lcp_option(saddr arg0, u8 *opts, u8 *arg2, u8 *hdr, s16 arg4) {
    s16 len;
    s16 res;
    s32 t;
    s16 lim;
    LcpSide *side = (LcpSide *)arg2;
    res = 2;
    len = hdr[1] - 2;
    switch (hdr[0]) {
    case 1:
        side->got.mru = rd16_804012E0(arg0);
        len -= 2;
        if (side->got.mru < 0x80) {
            side->got.mru = 0x80;
            res = 3;
        } else if (side->got.mru > 0x1000) {
            side->got.mru = 0x1000;
            res = 3;
        }
        if (arg4 != 0 && (side->want.mask & 2) && side->got.mru > (lim = side->want.mru)) {
            side->got.mru = lim;
            res = 3;
        }
        break;
    case 2:
        side->got.accm = rd32_804012E0(arg0);
        len -= 4;
        if (lbl_805D7A7A != 0) {
            res = 4;
        } else if (arg4 == 0 || (side->want.mask & 4)) {
            u32 v = side->got.accm | side->want.accm;
            if (side->got.accm != v) {
                side->got.accm = v;
                res = 3;
            }
        }
        break;
    case 3:
        side->got.auth_proto = rd16_804012E0(arg0);
        len -= 2;
        if (side->got.auth_proto == 0xC223) {
            side->got.chap_alg = (s8)rd8_804012E0(arg0);
            len -= 1;
        }
        if (side->want.f15 != 0) {
            u16 v = side->got.auth_proto;
            if (v == 0xC023 || (v == 0xC223 && (s32)side->got.chap_alg == 5)) {
                side->want.auth_proto = v;
                side->want.chap_alg = side->got.chap_alg;
            } else {
                side->got.auth_proto = 0xC023;
                side->got.chap_alg = 0;
                res = 3;
                hdr[1] = 4;
                while (len > 0) {
                    len--;
                    if (rd8_804012E0(arg0) == -1) {
                        return -1;
                    }
                }
            }
        } else {
            u16 a = side->got.auth_proto;
            u16 b = side->want.auth_proto;
            if (a != b || (a == 0xC223 && (s8)side->got.chap_alg != (s8)side->want.chap_alg)) {
                side->got.auth_proto = b;
                res = 3;
                side->got.chap_alg = side->want.chap_alg;
            }
        }
        if (res == 2) {
            ppp_set_auth(side->got.auth_proto);
        }
        break;
    case 5:
        side->got.magic = rd32_804012E0(arg0);
        len -= 4;
        if (side->got.magic == 0 || ((LcpOpts *)opts)->remote.got.magic == ((LcpOpts *)opts)->local.got.magic) {
            get_time_ms(&t);
            res = 3;
            side->got.magic += t;
        }
        break;
    case 7:
        if (!(side->mask & 0x80)) {
            res = 4;
        }
        break;
    case 8:
        if (lbl_805D7A7A != 0) {
            res = 4;
        } else if (!(side->mask & 0x100)) {
            res = 4;
        }
        break;
    case 0:
        res = 4;
        break;
    default:
        res = 4;
        break;
    }
    if (hdr[0] > 8 || !(side->mask & (1 << hdr[0]))) {
        res = 4;
    }
    if (len < 0) {
        return -1;
    }
    if (arg4 == 0 && len > 0) {
        while (len-- > 0) {
            if (rd8_804012E0(arg0) == -1) {
                return -1;
            }
        }
    }
    return res;
}

#pragma push
#pragma dont_inline off
#pragma inline_depth(4)
PppFrame *TLobby__sub_8040172C(PppFsm *c) {
    uaddr obj;
    LcpOpts *s;
    s = c->opts;
    obj = 0;
    obj = (uaddr)init_net_buffer_entry(0);
    if (obj == 0) {
        return 0;
    }
    loop_8040172C(&obj, &s->local.got, s->local.got.mask);
    return (PppFrame *)obj;
}
#pragma pop

extern void TLobby__sub_804017D8(uaddr *self_m, void *src, u8 idx, u8 val, s32 *flag) {
p803FE518_UnkBuf803FF344 *p;
p803FE518_UnkSrc803FE518 *s;
u8 *out;
u8 *cnt;
int c;
s16 rem;
rem = ((u8) val) - 2;
if ((*((p803FE518_UnkBuf803FF344 **) self_m)) == ((void *) 0))
{
*((p803FE518_UnkBuf803FF344 **) self_m) = (p803FE518_UnkBuf803FF344 *)(((void*)init_net_buffer_entry((u16)(1))));
if ((*((p803FE518_UnkBuf803FF344 **) self_m)) == ((void *) 0))
{
return;
}
}
p = *((p803FE518_UnkBuf803FF344 **) self_m);
s = (p803FE518_UnkSrc803FE518 *)(src);
out = p->data;
out = out + p->len;
*(out++) = idx;
cnt = out;
*(out++) = val;
switch (idx)
{
case 1:
out = write_network_u16_be((u8 *)(out), (u16)(s->w2));
rem -= 2;
break;
case 2:
out = write_network_u32_be((u8 *)(out), (u32)(s->w4));
rem -= 4;
break;
case 3:
out = write_network_u16_be((u8 *)(out), (u16)(s->h8));
rem -= 2;
if (s->h8 == 0xc223)
{
*cnt = 5;
*(out++) = s->b14;
if (val == 4)
{
val++;
}
rem = 0;
}
if (s->h8 == 0xc023)
{
*cnt = 4;
if (val == 5)
{
val--;
}
rem = 0;
}
break;
case 5:
out = write_network_u32_be((u8 *)(out), (u32)(s->wc));
rem -= 4;
break;
case 4:
case 6:
case 7:
case 8:
break;
}
while ((rem--) > 0)
{
if (((s16) (ppp_buffer_read((void *)((u8 *) flag), (void *)lobby_read_byte_buffer, 1))) != 1)
{
c = -1;
}
else
{
c = (s16) lobby_read_byte_buffer[0];
}
*(out++) = c;
}
p->len += val;
}

s32 configure_mode_by_type(void *self, s16 type) {
    LcpSide *c = (LcpSide *)self;
    if (type == 0) {
        c->want.mask |= 8;
        c->want.auth_proto = 0xC023;
    } else if (type == 1) {
        c->want.mask &= ~8;
        c->want.f15 = 0;
    } else if (type == 2) {
        c->want.mask |= 8;
        c->want.auth_proto = 0xC223;
        c->want.chap_alg = 5;
        c->want.f15 = 0;
    } else if (type == 4) {
        c->want.mask |= 8;
        c->want.auth_proto = 0xC223;
        c->want.chap_alg = 5;
        c->want.f15 = 1;
    } else {
        return 1;
    }
    return 0;
}

LcpState lbl_805C0400;
