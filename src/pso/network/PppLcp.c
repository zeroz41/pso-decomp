/* PPP LCP, the protocol that names itself "Lcp", and its state object (a C library, built with GC/1.2.5n). */
#include "types.h"
#include "pso/network/PppChap.h"
#include "pso/network/Ppp.h"
#include "pso/network/PppFsm.h"
#include "pso/network/PppApi.h"
#include "pso/network/NetStack.h"
#include "pso/network/NetIpv6Route.h"
#include "pso/network/PppLcp.h"
#include "pso/network/NetworkRuntime.h"
#include "pso/network/PppVj.h"
#include "pso/network/NetworkTransport.h"


#include <stddef.h>
#include "pso/network/NetStackTypes.h"

#include "pso/network/PppBuffer.h"

/* The option values both sides start from: MRU 1500 and a full async control-character map. */
const LcpVals lcp_default_values = {0, 1500, 0xFFFFFFFF};
/* Each option's length, by option type. */
const u8 lcp_option_lengths[16] = {4, 4, 6, 4, 4, 6, 6, 2, 2};
/* The option readers' scratch bytes, in reverse definition order. */
u8 lobby_read_byte_buffer[1];
u8 lcp_read_value_buffer[4];


s16 wait_for_connection(PppFsm *c) {
    NetThreadState *g;
    PppProtoBlocks *blocks;
    blocks = c->blocks;
    g = &net_thread_state;
    c->abort = 0;
    while (c->state != 5) {
        if (is_timed_out() != 0 || c->abort != 0 || blocks->phase == 4) {
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

PppFrame *build_lcp_config_request(PppFsm *c);
s16 recv_lcp_config_reject(PppFsm *fsm, PppHeader *msg, PppFrame *src);
s16 recv_lcp_config_nak(PppFsm *fsm, PppHeader *msg, PppFrame *src);
s16 recv_lcp_config_request(PppFsm *fsm, PppHeader *msg, PppFrame *src);
s16 verify_lcp_config_ack(PppFsm *fsm, PppHeader *msg, PppFrame *expected);

void init_lcp_protocol(PppProtoBlocks *conn)
{
  PppFsmProtocol *proto = &lcp_state.proto;
  PppFsm *e = &conn->lcp;
  LcpOpts *area = &lcp_state.opts;
  const LcpVals *tbl = &lcp_default_values;
  proto->name = "Lcp";
  proto->proto = 0xC021;
  proto->code_mask = 0xFFE;
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
  proto->build_config_request = build_lcp_config_request;
  proto->check_config_request = recv_lcp_config_request;
  proto->check_config_ack = verify_lcp_config_ack;
  proto->check_config_nak = recv_lcp_config_nak;
  proto->check_config_reject = recv_lcp_config_reject;
  e->blocks = conn;
  e->proto = proto;
  e->opts = area;
  area->local.want = *tbl;
  area->local.mask = 0x1AE;
  area->remote.want = *tbl;
  area->remote.got = *tbl;
  area->remote.mask = 0x1AE;
  fsm_init(e);
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

    fsm_reset(s);
    PP_doppp_active(s);
    s->blocks->phase = 1;
    if (s->blocks->phase >= 1) {
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
            if (lobby_session_flags & 2) {
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
        if (msg->no_pfc == 0) {
            p->mask |= 0x80;
        } else {
            p->mask &= ~0x80;
        }
        if (msg->no_acfc == 0) {
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
        if (msg->no_pfc == 0) {
            q->mask |= 0x80;
        } else {
            q->mask &= ~0x80;
        }
        q = p + 1;
        if (msg->no_acfc == 0) {
            q->mask |= 0x100;
        } else {
            q->mask &= ~0x100;
        }
        fsm_open(s);
    }
    return 0;
}

void lcp_noop_callback(PppFsm *fsm) {

}

void setup_auth_after_lcp_negotiation(PppFsm *c) {
    LcpOpts *info = c->opts;
    PppProtoBlocks *st;
    u32 now;

    c->blocks->phase = 2;
    c->blocks->auth_pending &= ~0x30;
    c->blocks->pap_peer_id = 0;
    if (info->local.got.mask & 8) {
        switch (info->local.got.auth_proto) {
        case 0xC023:
            PP_pap_local(c->blocks);
            break;
        case 0xC223:
            PP_chap_local(c->blocks);
            PP_chap_remote(c->blocks);
            break;
        }
    }
    if (info->remote.got.mask & 8) {
        switch (info->remote.got.auth_proto) {
        case 0xC023:
            PP_pap_remote(c->blocks);
            break;
        case 0xC223:
            PP_chap_remote(c->blocks);
            PP_chap_local(c->blocks);
            break;
        }
    }
    st = c->blocks;
    if (!(st->auth_pending & 0x30)) {
        st->phase = 3;
        get_time_ms((s32 *)&now);
        st->network_time = (s16)(now / 1000);
        fsm_open(&st->ipcp);
    }
}

void start_ipcp_after_auth(PppProtoBlocks *blocks) {
    u32 t;
    if ((blocks->auth_pending & 0x30) == 0) {
        blocks->phase = 3;
        get_time_ms((s32 *)&t);
        blocks->network_time = (s16)(t / 1000);
        fsm_open(&blocks->ipcp);
    }
}

void reset_connection_slot(PppFsm *self) {
    PppProtoBlocks *sub;
    sub = self->blocks;
    sub->phase = 4;
    fsm_lowerdown(&sub->ipcp);
    PP_pap_down(&sub->pap);
}

void queue_command_81(PppFsm *fsm) {
    ppp_link_event(0x81);
}

void mark_lcp_starting(PppFsm *fsm) {
    fsm->blocks->phase = 1;
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
        r = parse_lcp_option(&src, opts, local, hdr, 0);
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
void append_lcp_option(PppFrame **pbuf, LcpVals *vals, u8 type, u8 len, PppFrame **src);
inline void add_lcp_options(PppFrame **pbuf, LcpVals *vals, s16 mask) {
    s16 i;
    i = 1;
    while (i <= 8) {
        if (mask & (1 << i)) {
            append_lcp_option(pbuf, vals, i, lcp_option_lengths[i], 0);
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
inline PppFrame *build_requested_options(PppFsm *fsm) {
    LcpOpts *o = (LcpOpts *)fsm->opts;
    PppFrame *t = 0;
    t = init_net_buffer_entry(0);
    if (t == 0) {
        return 0;
    }
    add_lcp_options(&t, &o->local.got, o->local.got.mask);
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
        PppFrame *cur = build_requested_options(fsm);
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
    if (opts->remote.want.auth_negotiable != 0) {
        opts->remote.got.auth_proto = 0;
        opts->remote.got.mask |= 8;
    }
    while (remaining > 0 && (s16)read_2_bytes(hdr, &src) != -1) {
        remaining -= hdr[1];
        if (remaining < 0) {
            return -1;
        }
        r = parse_lcp_option(&src, opts, &opts->remote, hdr, 1);
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
        append_lcp_option(&reply, &opts->remote.got, hdr[0], hdr[1], &src);
        if (r >= 3) {
            ppp_fsm_send_packet(fsm, status, msg->id, reply);
        }
    }
    missing = opts->remote.want.mask & ~opts->remote.got.mask;
    if (status == 3) {
        if (fsm->peer_attempts_left != 0) {
            add_lcp_options(&reply, &opts->remote.got, missing);
            fsm->peer_attempts_left--;
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

/* Read an option value from the frame: -1 (0 for 32 bits) when the frame is too short. */
#define READ_OPTION_U16(src) (ppp_buffer_read(src, lcp_read_value_buffer, 2) != 2 ? -1 : read_network_u16_be(lcp_read_value_buffer))
#define READ_OPTION_U32(src) (ppp_buffer_read(src, lcp_read_value_buffer, 4) != 4 ? 0 : read_network_u32_be(lcp_read_value_buffer))
#define READ_OPTION_U8(src) (ppp_buffer_read(src, lobby_read_byte_buffer, 1) != 1 ? -1 : (s16)lobby_read_byte_buffer[0])
s16 parse_lcp_option(PppFrame **src, LcpOpts *opts, LcpSide *side, u8 *hdr, s16 remote) {
    s16 len;
    s16 res;
    s32 t;
    s16 lim;
    res = 2;
    len = hdr[1] - 2;
    switch (hdr[0]) {
    case 1:
        side->got.mru = READ_OPTION_U16(src);
        len -= 2;
        if (side->got.mru < 0x80) {
            side->got.mru = 0x80;
            res = 3;
        } else if (side->got.mru > 0x1000) {
            side->got.mru = 0x1000;
            res = 3;
        }
        if (remote != 0 && (side->want.mask & 2) && side->got.mru > (lim = side->want.mru)) {
            side->got.mru = lim;
            res = 3;
        }
        break;
    case 2:
        side->got.accm = READ_OPTION_U32(src);
        len -= 4;
        if (ppp_use_pppoe != 0) {
            res = 4;
        } else if (remote == 0 || (side->want.mask & 4)) {
            u32 v = side->got.accm | side->want.accm;
            if (side->got.accm != v) {
                side->got.accm = v;
                res = 3;
            }
        }
        break;
    case 3:
        side->got.auth_proto = READ_OPTION_U16(src);
        len -= 2;
        if (side->got.auth_proto == 0xC223) {
            side->got.chap_alg = (s8)READ_OPTION_U8(src);
            len -= 1;
        }
        if (side->want.auth_negotiable != 0) {
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
                    if (READ_OPTION_U8(src) == -1) {
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
        side->got.magic = READ_OPTION_U32(src);
        len -= 4;
        if (side->got.magic == 0 || opts->remote.got.magic == opts->local.got.magic) {
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
        if (ppp_use_pppoe != 0) {
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
    if (remote == 0 && len > 0) {
        while (len-- > 0) {
            if (READ_OPTION_U8(src) == -1) {
                return -1;
            }
        }
    }
    return res;
}

#pragma push
#pragma dont_inline off
#pragma inline_depth(4)
PppFrame *build_lcp_config_request(PppFsm *c) {
    PppFrame *obj;
    LcpOpts *s;
    s = c->opts;
    obj = 0;
    obj = init_net_buffer_entry(0);
    if (obj == 0) {
        return 0;
    }
    add_lcp_options(&obj, &s->local.got, s->local.got.mask);
    return obj;
}
#pragma pop

void append_lcp_option(PppFrame **pbuf, LcpVals *vals, u8 type, u8 len, PppFrame **src) {
    PppFrame *p;
    u8 *out;
    u8 *cnt;
    int c;
    s16 rem;
    rem = len - 2;
    if (*pbuf == NULL) {
        *pbuf = init_net_buffer_entry(1);
        if (*pbuf == NULL) {
            return;
        }
    }
    p = *pbuf;
    out = p->data;
    out = out + p->len;
    *(out++) = type;
    cnt = out;
    *(out++) = len;
    switch (type) {
    case 1:
        out = write_network_u16_be(out, vals->mru);
        rem -= 2;
        break;
    case 2:
        out = write_network_u32_be(out, vals->accm);
        rem -= 4;
        break;
    case 3:
        out = write_network_u16_be(out, vals->auth_proto);
        rem -= 2;
        if (vals->auth_proto == 0xc223) {
            *cnt = 5;
            *(out++) = vals->chap_alg;
            if (len == 4) {
                len++;
            }
            rem = 0;
        }
        if (vals->auth_proto == 0xc023) {
            *cnt = 4;
            if (len == 5) {
                len--;
            }
            rem = 0;
        }
        break;
    case 5:
        out = write_network_u32_be(out, vals->magic);
        rem -= 4;
        break;
    case 4:
    case 6:
    case 7:
    case 8:
        break;
    }
    while ((rem--) > 0) {
        if ((s16)ppp_buffer_read(src, lobby_read_byte_buffer, 1) != 1) {
            c = -1;
        } else {
            c = (s16)lobby_read_byte_buffer[0];
        }
        *(out++) = c;
    }
    p->len += len;
}

s32 configure_mode_by_type(void *self, s16 type) {
    LcpSide *c = (LcpSide *)self;
    if (type == 0) {
        c->want.mask |= 8;
        c->want.auth_proto = 0xC023;
    } else if (type == 1) {
        c->want.mask &= ~8;
        c->want.auth_negotiable = 0;
    } else if (type == 2) {
        c->want.mask |= 8;
        c->want.auth_proto = 0xC223;
        c->want.chap_alg = 5;
        c->want.auth_negotiable = 0;
    } else if (type == 4) {
        c->want.mask |= 8;
        c->want.auth_proto = 0xC223;
        c->want.chap_alg = 5;
        c->want.auth_negotiable = 1;
    } else {
        return 1;
    }
    return 0;
}

LcpState lcp_state;
