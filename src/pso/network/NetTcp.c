#include "pso/network/UdpRuntime.h"
#include "pso/network/SocketEvents.h"
#include "pso/network/NetworkDispatch.h"
#include "pso/network/NetworkRuntime.h"
#include "pso/network/TLobby_803FC178.h"
#include "pso/network/NetworkPacketPool.h"
#include "pso/network/netcfg.h"
#include "pso/network/BufferRef.h"
#include "pso/network/IPv6.h"

#include "types.h"
#include "pso/network/TLobby_803FCF44.h"
#include "pso/network/TLobby_804050DC.h"
#include "pso/network/TLobby_8041112C.h"
struct Self_803FD85C;

#include <stddef.h>

#include "pso/network/IPv6Send.h"
#include "pso/network/NetStackTypes.h"
#include "pso/network/NetTcpState.h"
#include "pso/network/text_80421620.h"

/* This file's functions. */
s32 abort_tcp_connection(s16 arg0);
void clear_position(TcpTcb *tcb);
s32 close_if_open(TcpTcb *tcb);
s32 compare_sockaddr(void *self, u8 *arg1);
s32 get_field_534(TcpTcb *tcb);
s32 get_field_d8(TcpTcb *tcb);
s32 get_queue_diff(TcpTcb *tcb);
s32 get_score(TcpTcb *tcb);
s32 get_tcp_stat(s16 arg0, s16 *arg1, s16 *arg2, s32 *arg3, s32 *arg4);
void insert_item_at(TcpTcb *tcb, s16 idx, s32 a, s32 b);
s32 mark_connection_closed(s16 arg0);
void release_entry(void *self);
void reset_slot_index(TcpTcb *tcb);
s16 tcp_connect_start(s16 arg0, s32 arg1, s16 arg2);
s16 tcp_get_socket_handle(s16 i);
s16 validate_tcp_handle(s16 i);

u16 TLobby__sub_8040D8F0(u8 *arg0, u8 *arg1, s8 arg2, u8 *arg3, s16 arg4);
s32 TLobby__sub_8041D368(TcpTcb *tcb);
s32 get_adjusted_slot_count(TcpTcb *tcb);
TcpTcb *TLobby__sub_8041B5C0(TcpTcb *tcb);

s32 TLobby__sub_8041EB74(TcpTcb *tcb);
s32 TLobby__sub_8041ECA4(TcpTcb *tcb);
void TLobby__sub_8041A3CC(void);
void TLobby__sub_8041A5B4(void);
s32 NetTCPInit(void);

struct Self_803FDA68;

struct V_803FE600;

TcpState tcp_protocol_state;

s32 NetUnregisterTimer(void* p);

/* Inline the helpers below; this applies to the rest of the file. */
#pragma dont_inline off
#pragma inline_depth(4)

#pragma push
#pragma opt_common_subs on
s32 NetTCPInit(void) {
    s16 n;
    s16 i;
    TcpTcb *e;
    init_params((NetParamCfg *)((u8 *)&tcp_protocol_state));
    e = tcp_protocol_state.tcbs;
    for (i = 0; i < (n = tcp_protocol_state.count); i++) {
        e->listener = -1;
        e->state = 0;
        e->tag[0] = 0x54;
        e->tag[1] = 0x43;
        e->tag[2] = 0x42;
        e->index = i;
        e++;
    }
    tcp_protocol_state.freed = n;
    tcp_protocol_state.port = 0;
    NetStoreTick((s32 *)&tcp_protocol_state.iss);
    tcp_protocol_state.port_max = 0x7FF;
    tcp_protocol_state.port_min = 0x400;
    tcp_protocol_state.keepidle = 0x3840;
    tcp_protocol_state.keepintvl = 0x96;
    tcp_protocol_state.rexmtthresh = 3;
    tcp_protocol_state.sack_flags = 0;
    tcp_protocol_state.sack_flags |= 1;
    tcp_protocol_state.fA2 = 2;
    tcp_protocol_state.outflags[0] = 0x14;
    tcp_protocol_state.outflags[1] = 0;
    tcp_protocol_state.outflags[2] = 2;
    tcp_protocol_state.outflags[3] = 0x12;
    tcp_protocol_state.outflags[4] = 0x10;
    tcp_protocol_state.outflags[5] = 0x10;
    tcp_protocol_state.outflags[6] = 0x11;
    tcp_protocol_state.outflags[7] = 0x11;
    tcp_protocol_state.outflags[8] = 0x11;
    tcp_protocol_state.outflags[9] = 0x10;
    tcp_protocol_state.outflags[10] = 0x10;
    tcp_protocol_state.backoff[0] = 1;
    tcp_protocol_state.backoff[1] = 2;
    tcp_protocol_state.backoff[2] = 4;
    tcp_protocol_state.backoff[3] = 8;
    tcp_protocol_state.backoff[4] = 0x10;
    tcp_protocol_state.backoff[5] = 0x20;
    tcp_protocol_state.backoff[6] = 0x40;
    tcp_protocol_state.backoff[7] = 0x40;
    tcp_protocol_state.backoff[8] = 0x40;
    tcp_protocol_state.backoff[9] = 0x40;
    tcp_protocol_state.backoff[10] = 0x40;
    tcp_protocol_state.backoff[11] = 0x40;
    tcp_protocol_state.backoff[12] = 0x40;
    NetRegisterTimer(500, (s16)(1), (NetTimerCallback)(TLobby__sub_8041A5B4));
    NetRegisterTimer(100, (s16)(1), (NetTimerCallback)(TLobby__sub_8041A3CC));
    return 0;
}
#pragma pop

extern void TLobby__sub_8041A3CC(void) {
    TcpState *g = &tcp_protocol_state;
    s16 i;
    TcpTcb *e;

    e = g->tcbs;
    for (i = 0; i < g->count; e++, i++) {
        if (e->state != 0 && e->ack_delay != 0) {
            e->ack_delay--;
            if (e->ack_delay == 0) {
                e->ack_delay = g->ack_ticks / 100;
                e->flags |= 1;
                TLobby__sub_8041A9AC(e);
            }
        }
    }
}

void clear_position(TcpTcb *tcb) {
    tcb->timers[0] = 0;
    tcb->timers[1] = 0;
    tcb->timers[2] = 0;
    tcb->timers[3] = 0;
}

s32 TLobby__sub_8041D460(TcpTcb *tcb, s32 *p1, s32 *p2);
void TLobby__sub_8041D398();
#pragma push
#pragma opt_common_subs on
#pragma opt_propagation off
s16 TLobby__sub_8041A9AC(TcpTcb *tp)
{
    TcpHdr *th = &tp->hdr;
    TcpState *ts = &tcp_protocol_state;
    u8 *opt;
    NetPacket *m;
    TcpTcb *q;
    u8 *optp;
    s32 idle, win;
    u16 i, sackoff, optlen;
    s32 fin, mss, sendalot, recwin, flags, off, len;
    s32 t, u, lim, avail;
    s16 a;
    u16 b;
    s32 pa0, pa1, pa2;
    s32 sack_start, sack_end;
    u16 tmp;
    s32 tmp4, tmp4b;
    s32 pb0, pb1;

    if (tp->t_state < 0) {
        return -1;
    }
    if (TLobby__sub_8040DA54(tp->remote, tp->local) == 0) {
        NetDispatchSocketEvent((s16)(tp - ts->tcbs), tp->event_ctx, 3, 0xc);
        return -6;
    }
    a = TLobby__sub_8040DC8C(tp->remote, tp->local);
    b = tp->maxseg;
    mss = (s16)(b < a ? (s16)b : a);
    if ((s16)mss < 0) {
        return mss;
    }
    idle = !(tp->snd_una - tp->snd_max);
    if (tp->snd_max == tp->snd_una && tp->idle >= tp->rxtcur) {
        switch (tp->f540) {
        case 1:
            tp->snd_cwnd = b;
            break;
        case 2:
            tp->snd_cwnd = b * 2;
            break;
        case 3:
            tp->snd_cwnd = ((s32)(b * 4) < (((s32)(b * 2) > 0x111c) ? (s32)(b * 2) : 0x111c)) ? (b * 4) : ((((s32)(b * 2) > 0x111c) ? (s32)(b * 2) : 0x111c));
            break;
        default:
            tp->snd_cwnd = get_adjusted_slot_count(tp);
            break;
        }
    }
    for (;;) {
        opt = ts->opts;
        sendalot = 0;
        len = 0;
        if (tp->f2F4 != tp->snd_una) {
            len = TLobby__sub_8041D460(tp, &sack_start, &sack_end);
            if (len != 0) {
                sendalot = 1;
                off = sack_start - tp->snd_una;
            } else {
                off = tp->snd_nxt - tp->snd_una;
            }
        } else {
            off = tp->snd_nxt - tp->snd_una;
        }
        flags = ts->outflags[tp->t_state];
        win = tp->snd_wnd;
        if (tp->force != 0) {
            if (win == 0) {
                win = 1;
            } else {
                tp->timers[1] = 0;
                tp->rxtshift = 0;
            }
        }
        if (len == 0) {
            len = ((u32)get_score(tp) < (u32)win ? get_score(tp) : win) - off;
        }
        t = tp->snd_cwnd - tp->f2F0;
        if (tp->f2F4 == tp->snd_una) {
            t -= tp->snd_nxt - tp->snd_una;
        }
        if (t < 0) {
            t = 0;
        }
        if (len > t) {
            len = t;
            sendalot = 0;
        }
        if (off + len < get_score(tp)) {
            flags &= ~1;
        }
        if (len < 0) {
            len = 0;
            if (win == 0) {
                tp->timers[0] = 0;
                tp->snd_nxt = tp->snd_una;
            }
        }
        if ((u32)len > tp->maxseg) {
            len = tp->maxseg;
            sendalot = 1;
        }
        if ((s32)((tp->snd_nxt + len) - (tp->snd_una + get_score(tp))) < 0) {
            flags &= ~1;
        }
        recwin = get_queue_diff(tp);
        fin = flags & 1;

        if (fin != 0) {
            if ((tp->flags & 0x10) == 0) {
                goto send;
            }
            if (tp->snd_nxt == tp->snd_una) {
                goto send;
            }
        }
        if (tp->flags & 1) {
            goto send;
        }
        if (flags & 6) {
            goto send;
        }
        if ((s32)(tp->snd_up - tp->snd_una) > 0) {
            goto send;
        }
        if (len != 0) {
            if ((u32)len == tp->maxseg) {
                goto send;
            }
            if (sendalot != 0) {
                goto send;
            }
            if ((u32)tp->f204_b7 == 1) {
                t = get_score(tp);
            } else {
                t = ((u32)get_score(tp) < tp->f530) ? get_score(tp) : tp->f530;
            }
            if ((idle != 0 || (tp->flags & 4)) && len + off >= t) {
                goto send;
            }
            if (tp->force != 0) {
                goto send;
            }
            if ((u32)len >= tp->max_sndwnd >> 1) {
                goto send;
            }
            if ((s32)(tp->snd_nxt - tp->snd_max) < 0) {
                goto send;
            }
        }
        if (recwin > 0) {
            win = recwin - (s32)(tp->rcv_adv - tp->rcv_nxt);
            if (win < 0) {
                win = -win;
            }
            lim = ((tp->maxseg > 0x28) ? (tp->maxseg - 0x28) : 1) << 1;
            if ((u32)win >= (u32)lim) {
                goto send;
            }
        }
        if (win * 2 >= get_field_534(tp)) {
            goto send;
        }
        if ((u32)get_score(tp) != 0 && tp->timers[0] == 0 && tp->timers[1] == 0) {
            tp->rxtshift = 0;
            t = ((tp->srtt >> 2) + tp->rttvar) >> 1;
            tp->timers[1] = t * ts->backoff[tp->rxtshift];
            if (tp->timers[1] < 10) {
                tp->timers[1] = 10;
            } else if (tp->timers[1] > 0x78) {
                tp->timers[1] = 0x78;
            }
            if (tp->rxtshift < 0xc) {
                tp->rxtshift++;
            }
        }
        return 0;

send:
        if (fin != 0 && (tp->flags & 0x10) && tp->snd_nxt == tp->snd_max) {
            tp->snd_nxt = tp->snd_nxt - 1;
            off -= 1;
        }
        th->seq = tp->snd_una + off;
        optp = 0;
        optlen = 0;
        th->ack = tp->rcv_nxt;
        if (flags & 2) {
            tp->f2EC = 0;
            reset_slot_index(tp);
            opt[0] = 2;
            optp = opt;
            opt[1] = 4;
            tmp = (tp->f534 < (u32)mss) ? tp->f534 : mss;
            NetMemcpy(optp + 2, &tmp, 2);
            optlen = 4;
            if (tp->sack_flags & 1) {
                optp[4] = 4;
                optp[5] = 2;
                optp[6] = 1;
                optp[7] = 1;
                optlen = 8;
            }
        }
        if ((tp->sack_flags & 2) && tp->sack[0].start != tp->sack[0].end) {
            opt[optlen++] = 1;
            opt[optlen++] = 1;
            opt[optlen] = 5;
            sackoff = optlen + 1;
            optp = opt;
            q = tp;
            win = 2;
            i = 0;
            optlen += 2;
            while (i < 5 && q->sack[0].start != q->sack[0].end && (s32)optlen + 8 <= 0x28) {
                tmp4 = q->sack[0].start;
                tmp4b = q->sack[0].end;
                NetMemcpy(optp + optlen, &tmp4, 4);
                NetMemcpy(optp + (u16)(optlen + 4), &tmp4b, 4);
                optlen += 8;
                win += 8;
                q = (TcpTcb *)((u8 *)q + sizeof(TcpSeqRange));
                i++;
            }
            opt[sackoff] = (u8)win;
        }
        while ((optlen % 4) != 0) {
            opt[optlen] = 1;
            optlen++;
        }
        i = optlen;
        avail = tp->maxseg - i;
        if (len > avail) {
            len = avail;
            flags &= ~1;
            sendalot = 1;
        }
        th->flags = flags;
        if ((u32)recwin < ((u32)get_field_534(tp) >> 2) && (u32)recwin < tp->maxseg) {
            recwin = 0;
        }
        if (recwin < (s32)(tp->rcv_adv - tp->rcv_nxt)) {
            recwin = tp->rcv_adv - tp->rcv_nxt;
        }
        if ((u32)recwin > tp->f534) {
            recwin = tp->f534;
        }
        th->win = recwin;
        if ((s32)(tp->snd_up - tp->snd_nxt) > 0) {
            th->urp = tp->snd_up - tp->snd_nxt;
            flags |= 0x20;
        } else {
            tp->snd_up = tp->snd_una;
        }
        if (len != 0 && off + len == get_score(tp)) {
            flags |= 8;
        }
        win = 0;
        th->sum = win;
        th->flags = flags;
        th->off = (((i + (s32)sizeof(TcpHdr)) >> 2) << 4) & 0xf0;
        m = (NetPacket *)alloc_free_entry();
        if (m == 0) {
            return -0x101;
        }
        m->fragment_count = 0;
        m->total_bytes = 0;
        if (TLobby__sub_80420410(off, len, m, tp) < 0) {
            m->fragment_count = 0;
            m->total_bytes = 0;
        }
        if (optlen != 0) {
            m->total_bytes += optlen;
            m->fragments[m->fragment_count].length = optlen;
            set_value_and_enable(&m->fragments[m->fragment_count].buffer, (s32)optp);
            m->fragment_count++;
        }
        m->total_bytes += sizeof(TcpHdr);
        m->fragments[m->fragment_count].length = sizeof(TcpHdr);
        set_value_and_enable(&m->fragments[m->fragment_count].buffer, (s32)th);
        m->fragment_count++;
        th->sum = TLobby__sub_8040D8F0(tp->local, tp->remote, 6, (u8 *)m, 1);
        if (tp->force == 0 || tp->timers[1] == 0) {
            win = tp->snd_nxt;
            if (flags & 2) {
                tp->snd_nxt = win + 1;
            }
            if (flags & 1) {
                tp->snd_nxt += 1;
                tp->flags |= 0x10;
            }
            if (tp->snd_una != tp->f2F4) {
                tp->f2F0 += len;
            }
            if (len > 0) {
                if ((s32)(off + len + tp->snd_una - tp->snd_nxt) > 0) {
                    tp->snd_nxt += len;
                } else {
                    TLobby__sub_8041D398(tp);
                }
            }
            if ((s32)(tp->snd_nxt - tp->snd_max) > 0) {
                tp->snd_max = tp->snd_nxt;
                if (tp->rtt == 0) {
                    tp->rtt = 1;
                    tp->rtseq = win;
                }
            }
            if (tp->timers[0] == 0 && tp->snd_nxt != tp->snd_una) {
                tp->timers[0] = tp->rxtcur;
                if (tp->timers[1] != 0) {
                    tp->timers[1] = 0;
                    tp->rxtshift = 0;
                }
            }
        } else if ((s32)(tp->snd_nxt + len - tp->snd_max) > 0) {
            tp->snd_max = tp->snd_nxt + len;
        }
        {
            s16 rc = dispatch_by_addr_family((s32)m, (NetworkAddress *)tp->remote, (NetworkAddress *)tp->local, tp->f2D6, tp->f2DC, (void *)6);
            release_entry(m);
            if (rc < 0) {
                return rc;
            }
        }
        if (recwin > 0) {
            if ((s32)(tp->rcv_nxt + recwin - tp->rcv_adv) > 0) {
                tp->rcv_adv = tp->rcv_nxt + recwin;
            }
        }
        tp->flags &= ~1;
        tp->ack_delay = 0;
        if (sendalot == 0) {
            break;
        }
        NetYieldOutsideDispatcherThread();
    }
    return 0;
}
#pragma pop
s32 TLobby__sub_8041B3D4(void* a, void* b, s16 c, s16 d, s32 e, s32 f, u8 g_m) {
    struct {
        s16 s0;
        s16 s1;
        u32 w0;
        u32 w1;
        u8 b0;
        u8 b1;
        s16 h0;
        s16 h1;
        s16 h2;
    } src;
    struct {
        s16 s0;
        s16 s1;
        u32 w0;
        u32 w1;
        u8 b0;
        u8 b1;
        s16 h0;
        s16 h1;
        s16 h2;
    } hdr;
    void *p1;
    void *p2;
    void *p3;
    void *p4;
    void *p5;
    void *p6;
    void *p7;
    void *p8;
    void *ph;
    u8 *ctx;
    u8 buf[0x10];

    NetMemset((void *)(buf), (int)(0), (int)(0x10));
    if (!TLobby__sub_8040DA54((u8 *)(a), (u8 *)(b))) {
        return -1;
    }
    src.s0 = c;
    src.s1 = d;
    p1 = &src.s1;
    p2 = &src.w0;
    src.w0 = e;
    p3 = &src.w1;
    p4 = &src.b0;
    src.w1 = f;
    p5 = &src.b1;
    p8 = &src.h2;
    src.b0 = 0x50;
    p7 = &src.h1;
    p6 = &src.h0;
    src.b1 = g_m;
    src.h2 = 0;
    src.h1 = 0;
    src.h0 = 0;
    ctx = alloc_free_entry();
    if (ctx == NULL) {
        return -0x101;
    }
    *(u32*)(ctx + 4) = 1;
    *(u32*)(ctx + 8) = 0x14;
    *(s16*)(ctx + 0xc) = 0x14;
    NetMemcpy((void *)(&hdr.s0), (void *)(&src.s0), (int)(2));
    NetMemcpy((void *)(&hdr.s1), p1, (int)(2));
    NetMemcpy((void *)(&hdr.w0), p2, (int)(4));
    NetMemcpy((void *)(&hdr.w1), p3, (int)(4));
    NetMemcpy((void *)(&hdr.b0), p4, (int)(1));
    NetMemcpy((void *)(&hdr.b1), p5, (int)(1));
    NetMemcpy((void *)(&hdr.h0), p6, (int)(2));
    ph = &hdr.h1;
    NetMemcpy(ph, p7, (int)(2));
    NetMemcpy((void *)(&hdr.h2), p8, (int)(2));
    set_value_and_enable(ctx + 0x10, (s32)&hdr);
    src.h1 = ((s16)TLobby__sub_8040D8F0((u8 *)(b), (u8 *)(a), (s8)(6), (u8 *)(ctx), (s16)(1)));
    NetMemcpy(ph, (void *)(&src.h1), (int)(2));
    if (dispatch_by_addr_family((s32)ctx, (NetworkAddress *)a, (NetworkAddress *)b, buf + 4, buf + 4, (void *)6) < 0) {
        release_entry((void*)(ctx));
        return -1;
    }
    release_entry((void*)(ctx));
    return 0;
}

extern TcpTcb *TLobby__sub_8041B5C0(TcpTcb *arg0) {
    TcpTcb *self;
    TcpState *g = &tcp_protocol_state;
    s16 idx;
    s32 tmp;
    s32 pad[2];

    (void)pad;
    if ((self = arg0) == NULL) {
        return NULL;
    }
    if (self->flags & 0x80) {
        if (!(self->flags & 0x20)) {
            idx = (s16)(self - g->tcbs);
            NetDispatchSocketEvent(idx, self->event_ctx, 3, 3);
            self->flags |= 0x20;
        }
        close_if_open(self);
        TLobby__sub_8041EB74(self);
        idx = self->listener;
        tmp = (u32)idx;
        if (tmp != 0xffff) {
            TcpTcb *e;
            e = g->tcbs;
            e += idx;
            if (e->state == 1) {
                e->pending -= 1;
            }
        }
        NetDispatchSocketEvent((s16)(self - g->tcbs), self->event_ctx, 3, 0xff);
        *(s16 *)&self->state = 0;
        g->freed = (s16)(self - g->tcbs);
        return NULL;
    }
    self->t_state = 0;
    self->timers[0] = 0;
    self->timers[1] = 0;
    self->timers[2] = 0;
    self->timers[3] = 0;
    return self;
}

extern s16 TLobby__sub_8041B724(TcpTcb *tp) {
    s32 mss = TLobby__sub_8040DC8C(tp->remote, tp->local);

    return tp->maxseg < mss ? tp->maxseg : mss;
}

extern s32 TLobby__sub_8041E780(void);
s32 TLobby__sub_8041EC14(TcpTcb *tcb);
extern TcpTcb *TLobby__sub_8041B774(TcpTcb *self, TcpHdr *th, u8 *a, u8 *b) {
    u16 v;
    TcpTcb *dst;
    s32 w;
    s32 n;
    s16 idx;
    u8 *sp;
    s16 TLobby__sub_8041ECA4(TcpTcb *tcb); /* declared s16 here; the definition returns s32 */
    s16 TLobby__sub_8041EC14(TcpTcb *tcb); /* declared s16 here; the definition returns s32 */
    s16 TLobby__sub_8041E780(void); /* declared s16 here; the definition returns s32 */

    if (self->f2C4 <= self->pending) return NULL;
    idx = TLobby__sub_8041E780();
    if (idx < 0) return NULL;

    dst = tcp_protocol_state.tcbs;
    dst += idx;
    dst->hdr.sport = self->hdr.sport;
    v = self->hdr.dport;
    if (v == 0) {
        v = th->sport;
        dst->hdr.dport = v;
    } else {
        dst->hdr.dport = v;
    }

    if (is_addr_unspecified(self->remote)) {
        NetMemcpy(dst->remote, a, sizeof(dst->remote));
    } else {
        NetMemcpy(dst->remote, self->remote, sizeof(dst->remote));
    }
    NetMemcpy(dst->local, b, sizeof(dst->local));
    NetMemcpy(dst->f2D6, self->f2D6, 3);
    NetMemcpy(dst->f2DC, self->f2DC, 12);

    n = TLobby__sub_8040DC8C(dst->remote, dst->local);
    w = dst->maxseg;
    w = (w < n) ? w : n;
    if ((s16)w < 0) {
        *(s16 *)&dst->state = 0;
        return NULL;
    }

    dst->f530 = self->f530;
    dst->f534 = self->f534;
    if (TLobby__sub_8041ECA4(dst) < 0) {
        *(s16 *)&dst->state = 0;
        return NULL;
    }
    if (TLobby__sub_8041EC14(dst) < 0) {
        close_if_open(dst);
        *(s16 *)&dst->state = 0;
        return NULL;
    }

    *(u32 *)&dst->event_ctx = *(u32 *)&self->event_ctx;
    dst->listener = (s16)(self - tcp_protocol_state.tcbs);
    self->pending += 1;
    dst->sack_flags = self->sack_flags;
    dst->f53C = self->f53C;
    *(u32 *)&dst->f540 = *(u32 *)&self->f540;
    dst->flags = self->flags;
    dst->maxseg = self->maxseg;
    return dst;
}
extern s32 TLobby__sub_8041D0C8(TcpTcb *self, u8 *data, s16 total, u8 *p6);
void TLobby__sub_8041A498(TcpTcb *arg0, s16 arg1);
#define TCP_IDX(tp) ((s16)((TcpTcb *)(tp) - tcp_protocol_state.tcbs))
#define TCP_MIN(a, b) ((a) < (b) ? (a) : (b))
#define TCP_MAX(a, b) ((a) > (b) ? (a) : (b))
#define TCP_REXMTTHRESH (tcp_protocol_state.rexmtthresh)
#pragma push
#pragma pool_data off
#pragma push
#pragma opt_propagation off
#pragma opt_common_subs on
inline s32 imax(s32 a, s32 b) { return a > b ? a : b; }
extern s32 TLobby__sub_8041B974(u8 *pkt, u8 *a, u8 *b) {
    s32 changed = 0;
    u32 flag = 0;
    u32 total = 0;
    TcpTcb *found = 0;
    s16 kind;
    s16 ti_flags;
    s16 blen;
    TcpHdr *ti;
    s32 st;
    u32 tmp;
    TcpHdr hdr;
    u8 *p = pkt + offsetof(NetPacket, fragments[1]);
    u8 *src;
    u8 *body;
    u16 len;
    u16 rem;
    TcpTcb *ent_new;
    s32 todrop;
    s32 acked;
    s32 ourfinisacked;
    s32 ack;
    s16 rtt;
    s16 srtt;
    s32 TLobby__sub_80422AB8(s32, void (*)(s16, s16, s32, s32), s16, s32, s32, s32);
    s16 compare_sockaddr(void *, u8 *); /* declared s16 here; the definition returns s32 */
    s16 TLobby__sub_8041B3D4(void *, void *, u16, u16, s32, s32, u8); /* declared s16 here; the definition is s32 (void *, void *, s16, s16, s32, s32, u8) */
    s16 TLobby__sub_8041D368(TcpTcb *tcb); /* declared s16 here; the definition returns s32 */

    *(s32 *)(pkt + offsetof(NetPacket, total_bytes)) = *(s32 *)(pkt + offsetof(NetPacket, total_bytes)) - *(s16 *)(pkt + offsetof(NetPacket, fragments[0].length));
    *(s16 *)(pkt + offsetof(NetPacket, fragments[0].length)) = 0;
    src = TLobby__sub_80406F0C(p + offsetof(NetPacketFragment, buffer));
    NetMemcpy(&hdr.sport, src, 2);
    NetMemcpy(&hdr.dport, src + offsetof(TcpHdr, dport), 2);
    NetMemcpy(&hdr.seq, src + offsetof(TcpHdr, seq), 4);
    NetMemcpy(&hdr.ack, src + offsetof(TcpHdr, ack), 4);
    NetMemcpy(&hdr.off, src + offsetof(TcpHdr, off), 1);
    NetMemcpy(&hdr.flags, src + offsetof(TcpHdr, flags), 1);
    NetMemcpy(&hdr.win, src + offsetof(TcpHdr, win), 2);
    NetMemcpy(&hdr.sum, src + offsetof(TcpHdr, sum), 2);
    NetMemcpy(&hdr.urp, src + offsetof(TcpHdr, urp), 2);
    ti = &hdr;
    kind = ti->flags;
    ti_flags = kind;
    len = ti->off >> 2;
    if ((u32)*(s32 *)(pkt + offsetof(NetPacket, total_bytes)) < sizeof(TcpHdr)) {
        return -1;
    }
    if ((u16)TLobby__sub_8040D8F0(a, b, 6, pkt, 0)) {
        goto drop;
    }
    blen = (s16)(len - sizeof(TcpHdr));
    if (blen != 0) {
        body = TLobby__sub_80406F0C(p + offsetof(NetPacketFragment, buffer)) + sizeof(TcpHdr);
    } else {
        body = 0;
    }
    if (len < 0x14) {
        goto drop;
    }
    if ((u16)*(s32 *)(pkt + offsetof(NetPacket, total_bytes)) < len) {
        goto drop;
    }
    NetMemcpy(&tmp, &ti->seq, 4);
    NetMemcpy(&ti->seq, &tmp, 4);
    NetMemcpy(&tmp, &ti->ack, 4);
    NetMemcpy(&ti->ack, &tmp, 4);
    rem = *(s32 *)(pkt + offsetof(NetPacket, total_bytes)) - len;
retry:
    found = 0;
    {
        TcpTcb *ent = tcp_protocol_state.tcbs;
        s16 i;
        for (i = 0; i < tcp_protocol_state.count; ent++, i++) {
            if (ent->state == 0) {
                continue;
            }
            if (ent->t_state == 1) {
                continue;
            }
            if (ent->t_state == -1) {
                continue;
            }
            if (compare_sockaddr(ent->remote, a)) {
                continue;
            }
            if (ent->hdr.dport != hdr.sport) {
                continue;
            }
            if (ent->hdr.sport != hdr.dport) {
                continue;
            }
            found = ent;
            break;
        }
    }
    if (found == 0) {
        TcpTcb *ent = tcp_protocol_state.tcbs;
        s16 i;
        for (i = 0; i < tcp_protocol_state.count; ent++, i++) {
            if (ent->state == 0) {
                continue;
            }
            if (ent->t_state != 1) {
                continue;
            }
            if (ent->hdr.sport != hdr.dport) {
                continue;
            }
            if (compare_sockaddr(ent->remote, a)) {
                if (!is_addr_unspecified(ent->remote)) {
                    continue;
                }
            }
            if (ent->hdr.dport == hdr.sport || ent->hdr.dport == 0) {
                found = ent;
                break;
            }
        }
    }
    if (found == 0) {
        goto dropwithreset;
    }
    st = found->t_state;
    if (!(s16)st) {
        if (found->flags & 0x80) {
            goto drop;
        }
        if (found->fA & 0x4) {
            goto drop;
        }
    }
    if (st != 1) {
        found->idle = 0;
        found->timers[2] = found->keepidle;
    }
    if (body != 0 && found->t_state != 1) {
        TLobby__sub_8041D0C8(found, body, blen, (u8 *)ti);
    }
    found->rcv_wnd = (u16)(found->rcv_adv - found->rcv_nxt);
    switch (found->t_state) {
    case 1:
        if (kind & 4) {
            NetDispatchSocketEvent(TCP_IDX(found), found->event_ctx, 3, 0xa);
            goto drop;
        }
        if (kind & 0x10) {
            goto dropwithreset;
        }
        if (!(kind & 2)) {
            goto drop;
        }
        if (is_multicast_address((void *)b, 0) == 1) {
            goto drop;
        }
        ent_new = TLobby__sub_8041B774(found, ti, a, b);
        if (ent_new == 0) {
            goto drop;
        }
        if (body != 0) {
            TLobby__sub_8041D0C8(ent_new, body, blen, (u8 *)ti);
        }
        if (flag) {
            ent_new->iss = flag;
        } else {
            ent_new->iss = tcp_protocol_state.iss;
        }
        tcp_protocol_state.iss += 0xFA00;
        ent_new->irs = hdr.seq;
        ent_new->snd_una = ent_new->snd_nxt = ent_new->snd_max =
            ent_new->snd_up = ent_new->f2F4 = *(u32 *)&ent_new->una =
            ent_new->iss;
        ent_new->rcv_adv = ent_new->rcv_nxt = ent_new->irs + 1;
        ent_new->flags |= 1;
        ent_new->t_state = 3;
        ent_new->timers[2] = 0x96;
        switch (ent_new->f540) {
        case 1:
            ent_new->snd_cwnd = ent_new->maxseg;
            break;
        case 2:
            ent_new->snd_cwnd = ent_new->maxseg * 2;
            break;
        case 3:
            {
                s32 m = ent_new->maxseg;
                ent_new->snd_cwnd = TCP_MIN(m * 4, imax(m * 2, 0x111c));
            }
            break;
        default:
            ent_new->snd_cwnd = get_adjusted_slot_count(ent_new);
            break;
        }
        *(u32 *)&ent_new->event_ctx = *(u32 *)&found->accept_ctx;
        *(u32 *)&found->accept_ctx = 0;
        TLobby__sub_80422AB8(TCP_IDX(found),
                             found->accept_cb,
                             (s16)(ent_new - tcp_protocol_state.tcbs), (s32)(ent_new->remote),
                             (s32)ent_new->hdr.sport, (s32)ent_new->hdr.dport);
        found = ent_new;
        goto trimthenstep6;
    case 2:
        ack = kind & 0x10;
        if ((ack && (s32)(ti->ack - found->iss) <= 0) || (s32)(ti->ack - found->snd_max) > 0) {
            NetDispatchSocketEvent(TCP_IDX(found), found->event_ctx, 3, 0xe);
            goto dropwithreset;
        }
        if (kind & 4) {
            NetDispatchSocketEvent(TCP_IDX(found), found->event_ctx, 3, 0xa);
            if (ack) {
                TLobby__sub_8041A498(found, 1);
            }
            goto drop;
        }
        if (!(kind & 2)) {
            goto drop;
        }
        if (ack) {
            found->snd_una = ti->ack;
            found->f2F4 = ti->ack;
            if ((s32)(found->snd_nxt - found->snd_una) < 0) {
                found->snd_nxt = found->snd_una;
            }
        }
        found->timers[0] = 0;
        found->irs = hdr.seq;
        found->rcv_adv = found->rcv_nxt = found->irs + 1;
        found->flags |= 1;
        if (ack && (s32)(found->snd_una - found->iss) > 0) {
            NetDispatchSocketEvent(TCP_IDX(found), found->event_ctx, 3, 1);
            found->t_state = 4;
            found->maxseg = TLobby__sub_8041B724(found);
            switch (found->f540) {
            case 1:
                found->snd_cwnd = found->maxseg;
                break;
            case 2:
                found->snd_cwnd = found->maxseg * 2;
                break;
            case 3:
                {
                    s32 m = found->maxseg;
                    found->snd_cwnd = TCP_MIN(m * 4, imax(m * 2, 0x111c));
                }
                break;
            default:
                found->snd_cwnd = get_adjusted_slot_count(found);
                break;
            }
            if ((rtt = found->rtt) != 0) {
                found->srtt = rtt << 3;
                found->rttvar = found->rtt << 1;
                found->rxtcur = (found->srtt >> 3) + found->rttvar;
                if (found->rxtcur < 2) {
                    found->rxtcur = 2;
                } else if (found->rxtcur > 0x80) {
                    found->rxtcur = 0x80;
                }
                found->rtt = 0;
            }
        } else {
            found->t_state = 3;
        }
    trimthenstep6:
        hdr.seq++;
        if (rem > found->rcv_wnd) {
            rem = found->rcv_wnd;
            kind &= ~1;
        }
        found->snd_wl1 = hdr.seq - 1;
        found->rcv_up = hdr.seq;
        goto step6;
    }
    todrop = found->rcv_nxt - hdr.seq;
    if (todrop > 0) {
        if (kind & 2) {
            hdr.seq++;
            kind &= ~2;
            if (hdr.urp > 1) {
                hdr.urp--;
            } else {
                kind &= ~0x20;
            }
            todrop--;
        }
        if (todrop > rem || (todrop == rem && !(kind & 1))) {
            if (!(kind & 1) || todrop != rem + 1) {
                goto dropafterack;
            }
            todrop = rem;
            kind &= ~1;
            found->flags |= 1;
        }
        total += todrop;
        hdr.seq += todrop;
        rem -= (u16)todrop;
        if (hdr.urp > (u16)todrop) {
            hdr.urp -= (u16)todrop;
        } else {
            hdr.urp = 0;
            kind &= ~0x20;
        }
    }
    todrop = (hdr.seq + rem) - (found->rcv_nxt + found->rcv_wnd);
    if (todrop > 0) {
        if (todrop >= rem) {
            if ((kind & 2) && found->t_state == 10 && found->fD8 == 0 &&
                (s32)(hdr.seq - found->rcv_nxt) > 0) {
                flag = found->rcv_nxt + 0x1F400;
                NetDispatchSocketEvent(TCP_IDX(found), found->event_ctx, 3, 4);
                found->flags |= 0x80;
                TLobby__sub_8041B5C0(found);
                goto retry;
            }
            if (found->rcv_wnd == 0 && hdr.seq == found->rcv_nxt) {
                found->flags |= 1;
            } else {
                goto dropafterack;
            }
        }
        rem -= (u16)todrop;
        kind &= ~(8 | 1);
    }
    if (kind & 4) {
        NetDispatchSocketEvent(TCP_IDX(found), found->event_ctx, 3, 0xa);
        switch (found->t_state) {
        case 3:
        case 4:
        case 5:
        case 6:
        case 9:
            found->t_state = 0;
            NetDispatchSocketEvent(TCP_IDX(found), found->event_ctx, 3, 4);
            set_thread_state_and_resume(TCP_IDX(found), found->send_done, -5);
            set_slot_state_and_resume(TCP_IDX(found), found->recv_done, -5);
            if (TLobby__sub_8041B5C0(found) != 0) {
                found->t_state = -1;
            }
            goto drop;
        case 7:
        case 8:
        case 10:
            NetDispatchSocketEvent(TCP_IDX(found), found->event_ctx, 3, 4);
            found->flags |= 0x80;
            TLobby__sub_8041B5C0(found);
            goto drop;
        }
    }
    if (kind & 2) {
        goto dropafterack;
    }
    if (!(kind & 0x10)) {
        goto drop;
    }
    switch (found->t_state) {
    case 3:
        if ((s32)(found->snd_una - hdr.ack) > 0 || (s32)(hdr.ack - found->snd_max) > 0) {
            goto dropwithreset;
        }
        NetDispatchSocketEvent(TCP_IDX(found), found->event_ctx, 3, 1);
        found->t_state = 4;
        found->maxseg = TLobby__sub_8041B724(found);
        switch (found->f540) {
        case 1:
            found->snd_cwnd = found->maxseg;
            break;
        case 2:
            found->snd_cwnd = found->maxseg * 2;
            break;
        case 3:
            {
                s32 m = found->maxseg;
                found->snd_cwnd = TCP_MIN(m * 4, imax(m * 2, 0x111c));
            }
            break;
        default:
            found->snd_cwnd = get_adjusted_slot_count(found);
            break;
        }
        found->snd_cwnd -= found->maxseg;
        found->snd_wl1 = hdr.seq - 1;
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
        if ((s32)(hdr.ack - found->snd_una) <= 0 && found->snd_una == found->f2F4) {
            if (rem == 0 && hdr.win == found->snd_wnd) {
                if (found->timers[0] == 0 || hdr.ack != found->snd_una) {
                    found->dupacks = 0;
                } else if (++found->dupacks == (u8)TCP_REXMTTHRESH) {
                    u32 onxt = found->snd_nxt;
                    u32 win = TCP_MIN(found->snd_wnd, found->snd_cwnd) / 2 / found->maxseg;

                    if (TLobby__sub_8041D368(found) == 0) {
                        found->f2F4 = found->snd_nxt;
                        found->dupacks--;
                        goto newreno;
                    }
                    if (win < 2) {
                        win = 2;
                    }
                    found->snd_ssthresh = win * found->maxseg;
                    found->timers[0] = 0;
                    found->rtt = 0;
                    found->snd_nxt = hdr.ack;
                    found->snd_cwnd = found->maxseg;
                    TLobby__sub_8041A9AC(found);
                    found->snd_cwnd = found->snd_ssthresh + found->maxseg * found->dupacks;
                    if ((s32)(onxt - found->snd_nxt) > 0) {
                        found->snd_nxt = onxt;
                    }
                    goto drop;
                } else if (found->dupacks > (u8)TCP_REXMTTHRESH) {
                    found->snd_cwnd += found->maxseg;
                    TLobby__sub_8041A9AC(found);
                    goto drop;
                }
            } else {
                found->dupacks = 0;
            }
            break;
        }
    newreno:
        if ((s32)(found->snd_una - found->f2F4) < 0 && (s32)(hdr.ack - found->f2F4) < 0) {
            if (rem == 0 && hdr.win <= found->snd_wnd) {
                if (hdr.ack != found->snd_una) {
                    acked = hdr.ack - found->snd_una;
                    TLobby__sub_8041FFF8(acked, found);
                    found->snd_wnd -= acked;
                    if (hdr.win > found->snd_wnd) {
                        found->snd_wnd = hdr.win;
                    }
                    found->snd_una = hdr.ack;
                }
                if (++found->dupacks == (u8)TCP_REXMTTHRESH) {
                    u32 win = TCP_MIN(found->snd_wnd, found->snd_cwnd) / 2 / found->maxseg;

                    found->f2F0 = found->snd_nxt - found->snd_una -
                                              found->maxseg * found->dupacks - found->maxseg;
                    if (found->f2F0 < 0) {
                        found->f2F0 = 0;
                    }
                    if (win < 2) {
                        win = 2;
                    }
                    found->snd_ssthresh = win * found->maxseg;
                    found->timers[0] = 0;
                    found->rtt = 0;
                    found->snd_cwnd = found->f2F0 + found->maxseg;
                    TLobby__sub_8041A9AC(found);
                    found->snd_cwnd = found->snd_ssthresh;
                    goto drop;
                } else if (found->dupacks > (u8)TCP_REXMTTHRESH) {
                    found->f2F0 -= found->maxseg;
                    TLobby__sub_8041A9AC(found);
                    goto drop;
                }
            } else if (hdr.win > found->snd_wnd) {
                found->snd_wnd = hdr.win;
            } else {
                found->dupacks = 0;
            }
            break;
        }
        reset_slot_index((void *)found);
        found->f2F0 = 0;
        found->f2F4 = hdr.ack;
        if (found->dupacks > TCP_REXMTTHRESH && found->snd_cwnd > found->snd_ssthresh) {
            found->snd_cwnd = found->snd_ssthresh;
        }
        found->dupacks = 0;
        if ((s32)(hdr.ack - found->snd_max) > 0) {
            goto dropafterack;
        }
        acked = hdr.ack - found->snd_una;
        if ((rtt = found->rtt) != 0 && (s32)(hdr.ack - found->rtseq) > 0) {
            s16 delta;

            if ((srtt = found->srtt) != 0) {
                delta = rtt - 1 - (srtt >> 3);
                if ((found->srtt += delta) <= 0) {
                    found->srtt = 1;
                }
                if (delta < 0) {
                    delta = -delta;
                }
                delta -= found->rttvar >> 2;
                if ((found->rttvar += delta) <= 0) {
                    found->rttvar = 1;
                }
            } else {
                found->srtt = rtt << 3;
                found->rttvar = found->rtt << 1;
            }
            found->rtt = 0;
        }
        if (acked > 0 && found->rxtshift != 0) {
            found->rxtshift = 0;
            found->rxtcur = (found->srtt >> 3) + found->rttvar;
            if (found->rxtcur < 2) {
                found->rxtcur = 2;
            } else if (found->rxtcur > 0x80) {
                found->rxtcur = 0x80;
            }
        }
        if (hdr.ack == found->snd_max) {
            if (found->timers[0] != 0) {
                found->timers[0] = 0;
                found->rxtshift = 0;
            }
            changed = 1;
        } else if (found->timers[1] == 0) {
            found->timers[0] = found->rxtcur;
        }
        if (acked == 0) {
            break;
        }
        {
            u32 cw = found->snd_cwnd;
            u16 incr = found->maxseg;

            if (cw > found->snd_ssthresh) {
                incr = TCP_MAX(incr * incr / cw, 1);
            }
            found->snd_cwnd = (u16)TCP_MIN((s32)(cw + incr), 0xFFFF);
        }
        {
            s32 n = get_score((void *)found);

            if (acked > n) {
                ourfinisacked = 1;
            } else {
                n = acked;
                ourfinisacked = 0;
            }
            TLobby__sub_8041FFF8(n, found);
            found->snd_wnd -= (u16)n;
        }
        found->snd_una = hdr.ack;
        if ((s32)(found->snd_nxt - found->snd_una) < 0) {
            found->snd_nxt = found->snd_una;
        }
        switch (found->t_state) {
        case 6:
            if (ourfinisacked) {
                if (found->fA & 4) {
                    found->timers[3] = tcp_protocol_state.maxidle;
                }
                found->t_state = 9;
            }
            break;
        case 7:
            if (ourfinisacked) {
                found->t_state = 10;
                if ((u32)get_score((void *)found) == 0) {
                    close_if_open((void *)found);
                }
                if ((u32)get_field_d8((void *)found) == 0) {
                    TLobby__sub_8041EB74(found);
                }
                clear_position((void *)found);
                found->timers[3] = 0x78;
            }
            break;
        case 8:
            if (ourfinisacked) {
                NetDispatchSocketEvent(TCP_IDX(found), found->event_ctx, 3, 4);
                TLobby__sub_8041B5C0(found);
                goto drop;
            }
            break;
        case 10:
            found->timers[3] = 0x78;
            goto dropafterack;
        }
        break;
    }
step6:
    if ((kind & 0x10) &&
        ((s32)(found->snd_wl1 - hdr.seq) < 0 ||
         (found->snd_wl1 == hdr.seq &&
          ((s32)(found->snd_wl2 - hdr.ack) < 0 ||
           (found->snd_wl2 == hdr.ack && hdr.win > found->snd_wnd))))) {
        found->snd_wnd = hdr.win;
        found->snd_wl1 = hdr.seq;
        found->snd_wl2 = hdr.ack;
        if (found->snd_wnd > found->max_sndwnd) {
            found->max_sndwnd = found->snd_wnd;
        }
        changed = 1;
    }
    if ((kind & 0x20) && hdr.urp != 0 && !(found->flags & 0x08)) {
        if ((u32)get_queue_diff((void *)found) + hdr.urp > 0x10000) {
            hdr.urp = 0;
            kind &= ~0x20;
        } else {
            if ((s32)(hdr.seq + hdr.urp - found->rcv_up) > 0) {
                found->rcv_up = hdr.seq + hdr.urp;
            }
        }
    } else if (found->rcv_nxt != found->rcv_up) {
        found->rcv_up = found->rcv_nxt;
    }
    if ((rem != 0 || (kind & 1)) && !(found->flags & 0x08)) {
        if (hdr.seq == found->rcv_nxt && (found->t_state == 4 || (found->fA & 0x0c))) {
            s32 off;

            kind = ti_flags & 1;
            found->rcv_nxt += rem;
            off = len + total;
            if (!(found->fA & 0x04)) {
                TLobby__sub_8041F204((NetPacket *)pkt, off, found);
            }
            if (found->f53C == 0) {
                if (found->ack_delay == 0) {
                    found->ack_delay = (s16)(tcp_protocol_state.ack_ticks / 100);
                }
            } else {
                found->flags |= 1;
            }
            goto L1397;
        } else if ((s32)(hdr.seq - found->rcv_nxt) > 0) {
            TLobby__sub_8041F914((NetPacket *)pkt, (u16)(s32)(len + total), found, ti);
            kind &= ~1;
            found->flags |= 1;
            goto L1397;
        }
    }
    kind &= ~1;
L1397:
    if (!(kind & 1)) {
        goto L1469;
    }
    NetDispatchSocketEvent(TCP_IDX(found), found->event_ctx, 3, 2);
    if (!(found->flags & 0x08)) {
        TLobby__sub_8041F11C(found);
    }
    found->flags |= 1;
    found->rcv_nxt += 1;
    found->flags |= 8;
    switch (found->t_state) {
    case 3:
    case 4:
        found->t_state = 5;
        break;
    case 6:
        found->t_state = 7;
        break;
    case 9:
        found->t_state = 10;
        if ((u32)get_score((void *)found) == 0) {
            close_if_open((void *)found);
        }
        if ((u32)get_field_d8((void *)found) == 0) {
            TLobby__sub_8041EB74(found);
        }
        clear_position((void *)found);
        found->timers[3] = 0x78;
        break;
    case 10:
        found->timers[3] = 0x78;
        break;
    }
L1469:
    if (changed != 0 || (found->flags & 1)) {
        TLobby__sub_8041A9AC(found);
    }
    return 0;

dropafterack:
    if (kind & 4) {
        goto drop;
    }
    found->flags |= 1;
    TLobby__sub_8041A9AC(found);
    return 0;

dropwithreset:
    if (kind & 4) {
        goto drop;
    }
    if (is_multicast_address((void *)b, 0) == 1) {
        goto drop;
    }
    if (kind & 0x10) {
        if (TLobby__sub_8041B3D4(a, b, hdr.dport, hdr.sport, hdr.ack, 0, 4) < 0) {
            return -1;
        }
    } else {
        if (kind & 2) {
            rem++;
        }
        if (TLobby__sub_8041B3D4(a, b, hdr.dport, hdr.sport, 0, rem + hdr.seq, 0x14) < 0) {
            return -1;
        }
    }
    return 0;

drop:
    return 0;
}
#pragma pop
#pragma pop

s32 TLobby__sub_8041D524(TcpTcb *tcb, s32 x);
s32 TLobby__sub_8041D0C8(TcpTcb *self, u8 *data, s16 total, u8 *p6)
{
  void TLobby__sub_8041D584(TcpTcb *self, u8 *p6, u8 *tbl, s16 n); /* declared here with other parameter types; the definition is void (TcpTcb *, Th_8041D584 *, Sack_8041D584 *, s16) */
  s16 TLobby__sub_8041D524(TcpTcb *, s32); /* declared s16 here; the definition is s32 (TcpTcb *, s32) */
  s32 n;
  s16 done = 0;
  u8 sz;
  s16 k;
  s32 last;
  u8 *p;
  u8 *e;
  u16 tmp16;
  u32 tmp;
  while (done < total)
  {
    if (data[0] == 0)
    {
      break;
    }
    if (data[0] == 1)
    {
      sz = 1;
    }
    else
    {
      sz = data[1];
      switch (data[0])
      {
        case 2:
          e = p6;
          if ((sz == 4) && (e[0xd] & 2))
        {
          NetMemcpy(&tmp16, data + 2, 2);
          self->peer_mss = tmp16;
        }
          break;

        case 4:
          if ((sz == 2) && (self->sack_flags & 1))
        {
          self->sack_flags |= 2;
        }
          break;

        case 5:
        {
          u8 *tbl = (*((u8 (*)[]) (&tcp_protocol_state))) + offsetof(TcpState, sack_opt);
          last = *(s32 *)&self->snd_una;
          if (((sz - 2) % 8) != 0)
          {
            break;
          }
          if ((sz > 0x22) || (sz < 0xa))
          {
            break;
          }
          e = tbl;
          p = data + 2;
          n = (sz - 2) / 8;
          for (k = 0; k < n; k++)
          {
            NetMemcpy(&tmp, p, 4);
            *((u32 *) e) = tmp;
            NetMemcpy(&tmp, p + 4, 4);
            p += 8;
            *((u32 *) (e + 4)) = tmp;
            if (((*((s32 *) (e + 4))) - last) > 0)
            {
              last = *((s32 *) (e + 4));
            }
            e += 8;
          }

          TLobby__sub_8041D584(self, e, tbl, (s16) n);
          if (TLobby__sub_8041D524(self, last) != 0)
          {
            self->edge = *(s32 *)&self->snd_una;
          }
        }
          break;

      }

    }
    done += sz;
    data += sz;
  }

  self->maxseg = ((self->peer_mss) < ((s16) TLobby__sub_8041B724(self))) ? (self->peer_mss) : ((s16) TLobby__sub_8041B724(self));
  return 0;
}

s32 TLobby__sub_8041A1D8(void) {
    NetUnregisterTimer((void *)TLobby__sub_8041A5B4);
    NetUnregisterTimer((void *)TLobby__sub_8041A3CC);
    TLobby__sub_803F8794((void *)&tcp_protocol_state);
    tcp_protocol_state.count = 0;
    return 0;
}

void TLobby__sub_8041A498(TcpTcb *arg0, s16 arg1) {
    s16 idx = arg0 - tcp_protocol_state.tcbs;

    if (arg0->t_state >= 3) {
        arg0->t_state = 0;
        TLobby__sub_8041A9AC(arg0);
    }
    arg0->error = arg1;
    switch (arg1) {
    case 4:
        set_thread_state_and_resume(idx, arg0->send_done, -8);
        set_slot_state_and_resume(idx, arg0->recv_done, -8);
        NetDispatchSocketEvent(idx, arg0->event_ctx, 3, 0xB);
        break;
    default:
        set_thread_state_and_resume(idx, arg0->send_done, -5);
        set_slot_state_and_resume(idx, arg0->recv_done, -5);
        NetDispatchSocketEvent(idx, arg0->event_ctx, 3, 0xA);
        break;
    }
    if (TLobby__sub_8041B5C0(arg0) != 0) {
        arg0->t_state = -1;
    }
}

extern void TLobby__sub_8041A5B4(void) {
    s32 TLobby__sub_8041A6A4(TcpTcb *tcb, s32 timer); /* declared here with an s32 timer; the definition takes s16 */
    s16 *t;
    TcpState *g = (TcpState *)&tcp_protocol_state;
    TcpTcb *tcb;
    s16 i;
    s32 j;

    g->maxidle = g->keepintvl << 3;
    tcb = g->tcbs;
    for (i = 0; i < g->count; tcb++, i++) {
        if (tcb->state != 0 && tcb->state == 1) {
            t = (s16 *)tcb;
            for (j = 0; (s16)j < 4; t++, j++) {
                if (t[offsetof(TcpTcb, timers) / sizeof(s16)] > 0) {
                    t[offsetof(TcpTcb, timers) / sizeof(s16)]--;
                    if (t[offsetof(TcpTcb, timers) / sizeof(s16)] == 0) {
                        TLobby__sub_8041A6A4(tcb, j);
                    }
                }
            }
            tcb->idle++;
            if (tcb->rtt != 0) {
                tcb->rtt++;
            }
        }
    }
    g->iss += 0x10000 - 0x600;
}

#pragma push
#pragma opt_common_subs on
extern s32 TLobby__sub_8041A6A4(TcpTcb *tcb, s16 timer) {
    s32 TLobby__sub_8041B3D4(void*, void*, u16, u16, u32, u32, s32); /* declared here with other parameter types; the definition is s32 (void *, void *, s16, s16, s32, s32, u8) */
    TcpState *g = &tcp_protocol_state;
    s16 keep;
    s32 win;
    s32 rexmt;
    s32 t;

    switch (timer) {
    case 3:
        if (tcb->t_state != 10 && tcb->idle <= g->maxidle) {
            tcb->timers[3] = g->keepintvl;
        } else {
            TLobby__sub_8041B5C0(tcb);
        }
        break;
    case 0:
        tcb->rxtshift++;
        if (tcb->rxtshift > 12) {
            tcb->rxtshift = 12;
            TLobby__sub_8041A498(tcb, 4);
            break;
        }
        rexmt = (tcb->srtt >> 3) + tcb->rttvar;
        rexmt *= g->backoff[tcb->rxtshift];
        tcb->rxtcur = rexmt;
        if (tcb->rxtcur < 2) {
            tcb->rxtcur = 2;
        } else if (tcb->rxtcur > 128) {
            tcb->rxtcur = 128;
        }
        tcb->timers[0] = tcb->rxtcur;
        if (tcb->rxtshift > 3) {
            tcb->rttvar += tcb->srtt >> 3;
            tcb->srtt = 0;
        }
        reset_slot_index((void *)tcb);
        tcb->f2EC = 0;
        tcb->f2F0 = 0;
        tcb->f2F4 = tcb->snd_una;
        tcb->snd_nxt = tcb->snd_una;
        tcb->rtt = 0;
        win = ((tcb->snd_wnd < tcb->snd_cwnd) ? tcb->snd_wnd : tcb->snd_cwnd) / 2 / tcb->maxseg;
        if (win < 2) {
            win = 2;
        }
        tcb->snd_cwnd = tcb->maxseg;
        tcb->snd_ssthresh = win * tcb->maxseg;
        TLobby__sub_8041A9AC(tcb);
        break;
    case 1:
        t = ((tcb->srtt >> 2) + tcb->rttvar) >> 1;
        tcb->timers[1] = t * g->backoff[tcb->rxtshift];
        if (tcb->timers[1] < 10) {
            tcb->timers[1] = 10;
        } else if (tcb->timers[1] > 120) {
            tcb->timers[1] = 120;
        }
        if (tcb->rxtshift < 12) {
            tcb->rxtshift++;
        }
        tcb->force = 1;
        TLobby__sub_8041A9AC(tcb);
        tcb->force = 0;
        break;
    case 2:
        if (tcb->t_state < 4) {
            goto drop;
        }
        keep = tcb->keepidle;
        if (keep != 0 && tcb->t_state <= 5) {
            if (tcb->idle >= keep + ((g->maxidle < keep * 8) ? g->maxidle : keep * 8)) {
                goto drop;
            }
            TLobby__sub_8041B3D4(tcb->remote, tcb->local, tcb->hdr.sport, tcb->hdr.dport, tcb->snd_una - 1, tcb->rcv_nxt, 16);
            tcb->timers[2] = (g->keepintvl < tcb->keepidle) ? g->keepintvl : tcb->keepidle;
        } else if (keep != 0) {
            tcb->timers[2] = keep;
        } else {
            tcb->timers[2] = g->keepidle;
        }
        break;
    drop:
        TLobby__sub_8041A498(tcb, 4);
        break;
    }
    return 0;
}
#pragma pop

void insert_item_at(TcpTcb *o, s16 idx, s32 a, s32 b) {
    s16 i;
    s16 n;
    if (idx < 0) {
        return;
    }
    n = o->seg_top;
    if (idx > n + 1) {
        return;
    }
    if (idx > 0x1F) {
        return;
    }
    if (n >= 0x1F) {
        o->seg_top = 0x1E;
    }
    for (i = o->seg_top; i >= idx; i--) {
        o->segs[i + 1] = o->segs[i];
    }
    o->segs[idx].start = a;
    o->segs[idx].end = b;
    o->segs[idx].edge = b;
    o->segs[idx].stamp = o->snd_max;
    o->seg_top++;
}

s32 TLobby__sub_8041D368(TcpTcb *tcb) {
    if (tcb->seg_top == -1) {
        return 1;
    }
    return 0;
}

void reset_slot_index(TcpTcb *tcb) {
    tcb->seg_top = -1;
    tcb->edge = tcb->una;
}

void TLobby__sub_8041D398(u8* self, s32 a, s32 b) {
    u8* p = self;
    u8* q = self;
    s16 i;
    s32 key;
    *(s32*)(self + offsetof(TcpTcb, f2EC)) += b - a;
    for (i = 0; i <= *(s16*)(self + offsetof(TcpTcb, seg_top)); p += 0x10, q += 0x10, i++) {
        key = *(s32*)(p + offsetof(TcpTcb, segs[0].start));
        if (a - key < 0) {
            if (i == 0) {
                if (b - key <= 0) {
                    if (b - *(s32*)(self + offsetof(TcpTcb, edge)) < 0) {
                        return;
                    }
                    *(s32*)(self + offsetof(TcpTcb, edge)) = b;
                    *(s32*)(self + offsetof(TcpTcb, stamp)) = *(s32*)(self + offsetof(TcpTcb, snd_max));
                    return;
                } else {
                    *(s32*)(self + offsetof(TcpTcb, edge)) = key;
                    *(s32*)(self + offsetof(TcpTcb, stamp)) = *(s32*)(self + offsetof(TcpTcb, snd_max));
                }
            } else {
                if (b - key <= 0) {
                    u8* e = self;
                    s32 off = i * 16;
                    e += off;
                    if (b - *(s32*)(e += 0x328) < 0) {
                        return;
                    }
                    *(s32*)e = b;
                    e = self;
                    e += off;
                    *(s32*)(e + offsetof(TcpTcb, stamp)) = *(s32*)(self + offsetof(TcpTcb, snd_max));
                    return;
                } else {
                    *(s32*)(q + offsetof(TcpTcb, edge)) = key;
                    *(s32*)(q + offsetof(TcpTcb, stamp)) = *(s32*)(self + offsetof(TcpTcb, snd_max));
                }
            }
        }
    }
}

s32 TLobby__sub_8041D460(TcpTcb *tp, s32 *start, s32 *end) {
    s16 n = tp->seg_top;
    s16 i;

    if (n == -1) {
        *end = 0;
        *start = 0;
        return 0;
    }
    if (tp->edge - tp->segs[0].start < 0) {
        *start = tp->edge;
        *end = tp->segs[0].start;
        return *end - *start;
    }
    for (i = 0; i < n; i++) {
        if (tp->segs[i].edge - tp->segs[i + 1].start < 0) {
            *start = tp->segs[i].edge;
            *end = tp->segs[i + 1].start;
            return *end - *start;
        }
    }
    *end = 0;
    *start = 0;
    return 0;
}

s32 TLobby__sub_8041D524(TcpTcb *tcb, s32 x) {
    s16 n = tcb->seg_top;
    s16 i;
    if (n == -1) { return 0; }
    if (tcb->stamp - x < 0) { return 1; }
    for (i = 0; i < n; i++) {
        if (tcb->segs[i].stamp - x < 0) { return 1; }
    }
    return 0;
}

typedef struct Th_8041D584 {
    u8 pad0[8];
    s32 ack;
} Th_8041D584;
typedef struct Sack_8041D584 {
    s32 start;
    s32 end;
} Sack_8041D584;
inline void remove_8041D584(TcpTcb *tcb, s16 idx) {
    s16 n = tcb->seg_top;
    s16 i;
    if (n >= 0 && idx >= 0 && idx <= n) {
        for (i = idx; i < tcb->seg_top; i++) {
            tcb->segs[i] = tcb->segs[i + 1];
        }
        tcb->seg_top--;
    }
}
#pragma push
#pragma opt_common_subs on
void TLobby__sub_8041D584(TcpTcb *tcb, Th_8041D584 *th, Sack_8041D584 *blocks, s16 n) {
    s16 i;
    s16 j;
    s32 d;

    if (th->ack - tcb->una > 0) {
        for (;;) {
            if (tcb->seg_top < 0) {
                break;
            }
            if (th->ack - tcb->edge > 0) {
                tcb->f2EC -= tcb->edge - tcb->una;
                tcb->edge = th->ack;
                if (tcb->f2EC < 0) {
                    tcb->f2EC = 0;
                }
            } else {
                tcb->f2EC -= th->ack - tcb->una;
                if (tcb->f2EC < 0) {
                    tcb->f2EC = 0;
                }
            }
            if (th->ack - tcb->segs[0].end >= 0) {
                tcb->edge = tcb->segs[0].edge;
                tcb->stamp = tcb->segs[0].stamp;
                tcb->una = tcb->segs[0].end;
                remove_8041D584(tcb, 0);
                continue;
            }
            if (th->ack - tcb->segs[0].start >= 0) {
                tcb->seg_top = -1;
                tcb->edge = tcb->una;
            }
            break;
        }
        tcb->una = th->ack;
    }

    for (i = 0; i < n; i++) {
        s32 end = blocks[i].end;
        s32 start = blocks[i].start;
        Sack_8041D584 *b = &blocks[i];
        if (start - end >= 0) {
            continue;
        }
        if (tcb->seg_top == -1) {
            tcb->edge = th->ack;
            tcb->stamp = tcb->snd_max;
            insert_item_at(tcb, 0, b->start, b->end);
            continue;
        }
        if (end - tcb->una <= 0) {
            continue;
        }
        if (start - tcb->una <= 0) {
            tcb->seg_top = -1;
            tcb->edge = tcb->una;
            continue;
        }
        if (start - tcb->segs[0].start <= 0) {
            if (start - tcb->edge < 0) {
                tcb->f2EC -= tcb->edge - start;
                tcb->edge = b->start;
                if (tcb->f2EC < 0) {
                    tcb->f2EC = 0;
                }
            }
            insert_item_at(tcb, 0, b->start, b->end);
            j = 0;
        } else {
            for (j = 1; j <= tcb->seg_top; j++) {
                if (b->start - tcb->segs[j].start > 0) {
                    continue;
                }
                if (b->start - tcb->segs[j - 1].end < 0) {
                    if (b->end - tcb->segs[j - 1].end < 0) {
                        continue;
                    }
                    if (end - tcb->segs[j - 1].edge > 0) {
                        tcb->f2EC -= tcb->segs[j - 1].edge - tcb->segs[j - 1].end;
                        tcb->segs[j - 1].end = b->end;
                        tcb->segs[j - 1].edge = b->end;
                        if (tcb->f2EC < 0) {
                            tcb->f2EC = 0;
                        }
                    } else {
                        tcb->f2EC -= end - tcb->segs[j - 1].end;
                        tcb->segs[j - 1].end = b->end;
                        if (tcb->f2EC < 0) {
                            tcb->f2EC = 0;
                        }
                    }
                    j = j - 1;
                } else {
                    if (start - tcb->segs[j - 1].edge < 0) {
                        tcb->f2EC -= tcb->segs[j - 1].edge - start;
                        tcb->segs[j - 1].edge = b->start;
                        if (tcb->f2EC < 0) {
                            tcb->f2EC = 0;
                        }
                    }
                    insert_item_at(tcb, j, b->start, b->end);
                }
                break;
            }
            if (j == tcb->seg_top + 1) {
                insert_item_at(tcb, j, b->start, b->end);
                continue;
            }
        }
        while (j + 1 <= tcb->seg_top && tcb->segs[j].end - tcb->segs[j + 1].start >= 0) {
            d = tcb->segs[j].end - tcb->segs[j + 1].end;
            if (0 <= d) {
                if (tcb->segs[j + 1].edge - tcb->segs[j].end > 0) {
                    tcb->f2EC -= d;
                    tcb->segs[j].edge = tcb->segs[j + 1].edge;
                    remove_8041D584(tcb, j + 1);
                    if (tcb->f2EC < 0) {
                        tcb->f2EC = 0;
                    }
                } else {
                    tcb->f2EC -= tcb->segs[j + 1].edge - tcb->segs[j + 1].end;
                    remove_8041D584(tcb, j + 1);
                    if (tcb->f2EC < 0) {
                        tcb->f2EC = 0;
                    }
                }
            } else {
                tcb->segs[j].end = tcb->segs[j + 1].end;
                tcb->segs[j].edge = tcb->segs[j + 1].edge;
                remove_8041D584(tcb, j + 1);
            }
        }
    }
}
#pragma pop

#pragma push
#pragma pool_data off
s16 tcp_get_socket_handle(s16 i) {
    s16 r;
    if (i < 0 || i >= tcp_protocol_state.count) {
        r = -4;
    } else if (tcp_protocol_state.tcbs[i].state != 1) {
        r = -4;
    } else {
        r = 0;
    }
    if (r < 0) { return -4; }
    return tcp_protocol_state.tcbs[i].t_state;
}
#pragma pop

#pragma push
#pragma pool_data off
s32 TLobby__sub_8041DBD4(s16 arg0, s32 arg1, s32 len, s32 arg3) {
    s16 r;
    TcpTcb *e;

    if (arg0 < 0 || arg0 >= tcp_protocol_state.count) {
        r = -4;
    } else if (tcp_protocol_state.tcbs[arg0].state != 1) {
        r = -4;
    } else {
        r = 0;
    }
    if (r < 0) {
        return -4;
    }
    e = tcp_protocol_state.tcbs;
    e += arg0;
    switch (e->t_state) {
    case 0:
    case 4: case 5: case 6: case 7: case 8: case 9: case 10:
        if ((e->fA & 4) && (e->rcv_buf.kind == 0 || (u32)get_field_d8((void *)e) == 0)) {
            return -4;
        }
        break;
    }
    return TLobby__sub_8041ED8C(e, (void *)arg1, len, arg3);
}
#pragma pop

#pragma push
#pragma pool_data off
s16 tcp_start_send(s16 arg0, NetPacket *arg1, void (*completion)(s16, s16), u8 arg3) {
    s16 r;
    s16 v;
    s16 ret;
    TcpTcb *e;
    if (arg0 < 0 || arg0 >= tcp_protocol_state.count) {
        r = -4;
    } else if (tcp_protocol_state.tcbs[arg0].state != 1) {
        r = -4;
    } else {
        r = 0;
    }
    if (r < 0) {
        return -4;
    }
    e = tcp_protocol_state.tcbs;
    e += arg0;
    v = e->t_state;
    if (v <= 1) {
        return -4;
    }
    if (v < 4) {
        return -4;
    }
    if (v > 5 && (e->fA & 8)) {
        return -4;
    }
    TLobby__sub_80420BD0(arg1, e, completion);
    if (arg3 != 0) {
        e->snd_up = e->snd_nxt + arg1->total_bytes;
    }
    ret = TLobby__sub_8041A9AC(e);
    TLobby__sub_8041FFF8(0, e);
    return ret;
}
#pragma pop

#pragma push
#pragma pool_data off
s32 TLobby__sub_8041DE1C(s16 i, s16 opt, u32 *val) {
    s16 r;
    TcpState *g;
    TcpTcb *tcb;
    u16 seg;

    if (i < 0 || i >= tcp_protocol_state.count) {
        r = -4;
    } else if (tcp_protocol_state.tcbs[i].state != 1) {
        r = -4;
    } else {
        r = 0;
    }
    if (r < 0) {
        return -4;
    }
    g = &tcp_protocol_state;
    tcb = g->tcbs;
    tcb += i;
    switch (opt) {
    case 0x8:
        tcb->keepidle = *val * 2;
        tcb->timers[2] = tcb->keepidle;
        tcb->idle = 0;
        break;
    case 0x1001:
        if (*val > g->f8) {
            return -2;
        }
        tcb->f530 = *val;
        break;
    case 0x1002:
        if (*val > g->fC) {
            return -2;
        }
        tcb->f534 = *val;
        break;
    case 0x2001:
        if (*val != 0) {
            tcb->f53C = 1;
        } else {
            tcb->f53C = 0;
        }
        break;
    case 0x2002:
        if (*val != 0) {
            tcb->sack_flags |= 1;
        } else {
            tcb->sack_flags &= ~1;
        }
        break;
    case 0x2004:
        if (*val > 3) {
            return -2;
        }
        tcb->f540 = *val;
        break;
    case 0x2008:
        if (*val != 0) {
            tcb->flags |= 4;
        } else {
            tcb->flags &= ~4;
        }
        break;
    case 0x2010:
        seg = *val;
        if (seg < 40 || seg > tcb->maxseg) {
            return -2;
        }
        tcb->maxseg = seg;
        break;
    case 0x2020:
        if (*val != 0) {
            tcb->flags |= 0x40;
        } else {
            tcb->flags &= ~0x40;
        }
        break;
    default:
        return -2;
    }
    return 0;
}
#pragma pop

#pragma push
#pragma pool_data off
s32 get_tcp_stat(s16 arg0, s16 *arg1, s16 *arg2, s32 *arg3, s32 *arg4) {
    s16 r;
    TcpTcb *e;

    if (arg0 < 0 || arg0 >= tcp_protocol_state.count) {
        r = -4;
    } else if (tcp_protocol_state.tcbs[arg0].state != 1) {
        r = -4;
    } else {
        r = 0;
    }
    if (r < 0) {
        return -4;
    }
    e = tcp_protocol_state.tcbs;
    e += arg0;
    if (arg1 != NULL) {
        *arg1 = e->t_state;
    }
    if (arg2 != NULL) {
        if (e->t_state == 1) {
            *arg2 = e->pending;
        } else {
            *arg2 = 0;
        }
    }
    if (arg3 != NULL) {
        *arg3 = get_adjusted_slot_count(e);
    }
    if (arg4 != NULL) {
        *arg4 = get_field_d8((void *)e);
    }
    return 0;
}
#pragma pop

#pragma push
#pragma pool_data off
s32 mark_connection_closed(s16 arg0) {
    s16 r;
    TcpTcb *e;

    if (arg0 < 0 || arg0 >= tcp_protocol_state.count) {
        r = -4;
    } else if (tcp_protocol_state.tcbs[arg0].state != 1) {
        r = -4;
    } else {
        r = 0;
    }
    if (r < 0) {
        return -4;
    }
    e = tcp_protocol_state.tcbs;
    e += arg0;
    e->t_state = 0;
    e->flags |= 0x80;
    TLobby__sub_8041B5C0(e);
    return 0;
}
#pragma pop

#pragma push
#pragma pool_data off
s32 abort_tcp_connection(s16 arg0) {
    s16 r;
    TcpTcb *e;

    if (arg0 < 0 || arg0 >= tcp_protocol_state.count) {
        r = -4;
    } else if (tcp_protocol_state.tcbs[arg0].state != 1) {
        r = -4;
    } else {
        r = 0;
    }
    if (r < 0) {
        return -4;
    }
    e = tcp_protocol_state.tcbs;
    e += arg0;
    if (e->t_state < 4) {
        e->t_state = 0;
    } else {
        e->t_state = 0;
        TLobby__sub_8041A9AC(e);
    }
    clear_position((void *)e);
    return 0;
}
#pragma pop

extern void TLobby__sub_8041E2EC(s16 idx, void *a, void *b) {
    TcpTcb *e;

    e = tcp_protocol_state.tcbs;
    e += idx;
    NetMemcpy(e->f2D6, a, sizeof(e->f2D6));
    NetMemcpy(e->f2DC, b, sizeof(e->f2DC));
}

u16 TLobby__sub_8041EA14(void);
#pragma push
#pragma opt_propagation off
#pragma push
#pragma pool_data off
s16 tcp_connect_start(s16 arg0, s32 arg1, s16 arg2) {
    s16 r;
    TcpTcb *e;
    s16 TLobby__sub_8041EC14(TcpTcb *tcb); /* declared s16 here; the definition returns s32 */
    s16 TLobby__sub_8041ECA4(TcpTcb *tcb); /* declared s16 here; the definition returns s32 */
    u16 get_adjusted_slot_count(TcpTcb *tcb); /* declared u16 here; the definition returns s32 */
    void NetDispatchSocketEvent(s16, s32, s32, s16);

    if (arg0 < 0 || arg0 >= tcp_protocol_state.count) {
        r = -4;
    } else if (tcp_protocol_state.tcbs[arg0].state != 1) {
        r = -4;
    } else {
        r = 0;
    }
    if (r < 0) {
        return -4;
    }
    e = tcp_protocol_state.tcbs;
    e += arg0;
    if (TLobby__sub_8040DA54((u8 *)arg1, e->local) == 0) {
        NetDispatchSocketEvent((s16)(e - tcp_protocol_state.tcbs), e->event_ctx, 3, 0xC);
        return -6;
    }
    if (is_addr_unspecified(e->local) != 0 && select_source_address((Out_8040D95C *)e->local, (In_8040D95C *)arg1) < 0) {
        NetDispatchSocketEvent((s16)(e - tcp_protocol_state.tcbs), e->event_ctx, 3, 0xC);
        return -6;
    }
    if (e->hdr.sport == 0) {
        e->hdr.sport = TLobby__sub_8041EA14();
    }
    NetMemcpy(e->remote, (void *)arg1, sizeof(e->remote));
    e->hdr.dport = arg2;
    if (TLobby__sub_8041B724(e) < 0) {
        return -6;
    }
    r = TLobby__sub_8041ECA4(e);
    if (r < 0) {
        return r;
    }
    r = TLobby__sub_8041EC14(e);
    if (r < 0) {
        close_if_open((void *)e);
        return r;
    }
    e->snd_cwnd = get_adjusted_slot_count(e);
    e->t_state = 2;
    e->timers[2] = 0x96;
    {
        u32 *t = &tcp_protocol_state.iss;
        u32 v = *t;
        e->iss = v;
        e->una = v;
        e->f2F4 = v;
        e->snd_up = v;
        e->snd_max = v;
        e->snd_nxt = v;
        e->snd_una = v;
        *t += 0xFA00;
    }
    return TLobby__sub_8041A9AC(e);
}
#pragma pop

extern s32 TLobby__sub_8041E590(s16 idx) {
    TcpTcb *ents;
    s16 l;
    TcpTcb *t;
    TcpTcb *e;

    ents = tcp_protocol_state.tcbs;
    e = ents;
    e += idx;
    if ((l = e->listener) >= 0) {
        t = ents;
        t += l;
        if (t->state == 1) {
            t->pending--;
        }
    }
    e->listener = -1;
    return 0;
}

extern s32 TLobby__sub_8041E5E4(s16 idx, u8 *a, u16 id) {
    s16 compare_sockaddr(void *, u8 *); /* declared s16 here; the definition returns s32 */
    s16 i;
    TcpTcb *e;
    TcpState *g;
    TcpTcb *p;
    s16 rc;
    s32 k;

    if (idx < 0 || idx >= (g = &tcp_protocol_state)->count) {
        rc = -4;
    } else {
        TcpTcb *p;
        p = g->tcbs + idx;
        if (p->state != 1) {
            rc = -4;
        } else {
            rc = 0;
        }
    }
    if (rc < 0) {
        return -4;
    }
    g = &tcp_protocol_state;
    e = g->tcbs;
    e += idx;
    if (e->hdr.sport != 0) {
        return -3;
    }
    if (NetValidateLocalAddress((NetworkAddress *)a) < 0) {
        return -6;
    }
    if (id == 0) {
        e->hdr.sport = TLobby__sub_8041EA14();
    } else {
        p = g->tcbs;
        for (i = 0; i < g->count; i++) {
            if (p->state != 0 && p != e && p->hdr.sport == id) {
                if (is_addr_unspecified(a) != 0 || is_addr_unspecified(p->local) != 0 ||
                    compare_sockaddr(p->local, a) == 0) {
                    if (p->t_state == 10 && (p->flags & 0x80) != 0) {
                        TLobby__sub_8041B5C0(p);
                    } else {
                        return -3;
                    }
                }
            }
            p++;
        }
        e->hdr.sport = id;
    }
    NetMemcpy(e->local, a, sizeof(e->local));
    return 0;
}
extern void TLobby__sub_8041E8A8(s16 idx);
extern s32 TLobby__sub_8041E780(void)
{
    void TLobby__sub_8041E8A8(s32); /* declared here with an s32 1st argument; the definition takes s16 */
  TcpState *g_m = (TcpState *) (*(u8(*)[])&tcp_protocol_state);
  TcpTcb *rec;
  s32 bestIdx = 0;
  TcpTcb *best = NULL;
  s32 idx;
  s16 count;
  TcpTcb *new_var;
  TcpTcb *entries;
  s16 i = 0;
  idx = g_m->freed;
  count = g_m->count;
  entries = g_m->tcbs;
  for (; i < count; i++)
  {
    idx++;
    if (count <= ((s16) idx))
    {
      idx = 0;
    }
    rec = (TcpTcb *) (((u8 *) (new_var = entries)) + (((s16) idx) * sizeof(TcpTcb)));
    if (rec->state == 0)
    {
      NetMemset(rec, 0, sizeof(TcpTcb));
      TLobby__sub_8041E8A8(idx);
      return idx;
    }
    if ((rec->t_state == 10) && ((rec->flags & 0x80) != 0))
    {
      if (best != NULL)
      {
        if (rec->timers[3] < best->timers[3])
        {
          best = rec;
          bestIdx = idx;
        }
      }
      else
      {
        best = rec;
        bestIdx = idx;
      }
    }
  }

  if (best != NULL)
  {
    TLobby__sub_8041B5C0(best);
    NetMemset(best, 0, sizeof(TcpTcb));
    TLobby__sub_8041E8A8(bestIdx);
    return bestIdx;
  }
  return -0x103;
}

#pragma pop

#pragma push
#pragma pool_data off
void TLobby__sub_8041E8A8(s16 idx) {
    TcpTcb *t;
    TcpSeqRange *p;
    s16 i;

    t = tcp_protocol_state.tcbs;
    t += idx;
    t->tag[0] = 'T';
    t->tag[1] = 'C';
    t->tag[2] = 'B';
    t->index = idx;
    t->state = 1;
    t->t_state = 0;
    t->maxseg = 0x7FFF;
    t->peer_mss = 0x218;
    t->flags = 0;
    t->fA = 0;
    t->srtt = 0;
    t->rttvar = 24;
    t->rxtcur = 12;
    if (t->rxtcur < 2) {
        t->rxtcur = 2;
    } else if (t->rxtcur > 128) {
        t->rxtcur = 128;
    }
    t->snd_ssthresh = 0xFFFF;
    t->listener = -1;
    clear_position((t));
    NetMemset(t->f2D6, 0, sizeof(t->f2D6));
    NetMemset(t->f2DC, 0, sizeof(t->f2DC));
    t->sack_flags = tcp_protocol_state.sack_flags;
    p = t->sack;
    for (i = 0; i < 5; i++, p++) {
        p->end = 0;
        p->start = 0;
    }
    t->seg_top = -1;
    t->f530 = tcp_protocol_state.f8;
    t->f534 = tcp_protocol_state.fC;
    t->event_ctx = 0;
    t->f53C = tcp_protocol_state.f26;
    t->ack_delay = 0;
    t->f540 = tcp_protocol_state.fA2;
}
#pragma pop

u16 TLobby__sub_8041EA14(void)
{
    s32 tmp;
    TcpTcb *e;
    s16 i;
    s16 n;
    s16 found;
    u16 *x;
    u16 cur;
    TcpState *h;
    TcpState *g = (TcpState *)&tcp_protocol_state;

    x = &g->port;
    if (g->port == 0) {
        NetStoreTick(&tmp);
        *x = g->port_min;
        *x |= tmp & 0x3FF;
    } else if (g->port < g->port_max) {
        *x = g->port + 1;
    } else {
        *x = g->port_min;
    }
    found = 0;
    h = &tcp_protocol_state;
    goto search;
    do {
        if (cur < h->port_max) {
            *x = *x + 1;
        } else {
            *x = h->port_min;
        }
    search:
        cur = *x;
        e = h->tcbs;
        n = h->count;
        for (i = 0; i < n; i++, e++) {
            if (e->state == 1 && cur == e->hdr.sport) {
                found = 1;
                goto out;
            }
        }
        found = 0;
    out:;
    } while (found != 0);
    return cur;
}

s16 validate_tcp_handle(s16 i) {
    if (i < 0 || i >= tcp_protocol_state.count) { return -4; }
    if (tcp_protocol_state.tcbs[i].state != 1) { return -4; }
    return 0;
}

s32 TLobby__sub_8041EB74(TcpTcb *tcb) {
    if (tcb->rcv_buf.kind == 0) {
        return -1;
    }
    TLobby__sub_8041579C(&tcb->rcv_alloc);
    tcb->rcv_buf.kind = 0;
    return 0;
}

s32 close_if_open(TcpTcb *tcb) {
    if (tcb->snd_buf.kind == 0) {
        return -1;
    }
    TLobby__sub_8041579C(&tcb->snd_alloc);
    tcb->snd_buf.kind = 0;
    return 0;
}

s32 TLobby__sub_8041EC14(TcpTcb *tcb) {
    s32 spC[3];

    if (tcb->rcv_buf.kind == 0) {
        if (TLobby__sub_80415954(&spC[0], tcb->f534, 1) < 0) {
            return -0x102;
        }
        init_msg(&tcb->rcv_alloc, spC[0]);
        set_value_and_enable(&tcb->rcv_buf, spC[0]);
    }
    tcb->fD8 = 0;
    tcb->fDC = 0;
    tcb->fE0 = 0;
    tcb->reasm_total = 0;
    tcb->reasm_n = -1;
    tcb->last_reasm = -1;
    return 0;
}

s32 TLobby__sub_8041ECA4(TcpTcb *tcb) {
    unsigned char off;
    s32 spC;

    if (tcb->snd_buf.kind == 0) {
        if (TLobby__sub_80415954(&spC, tcb->f530, 1) < 0) {
            return -0x102;
        }
        init_msg(&tcb->snd_alloc, spC);
        set_value_and_enable(&tcb->snd_buf, spC);
    }
    tcb->f20 = 0;
    off = offsetof(TcpTcb, f24);
    *(s32 *)((u8 *)tcb + off) = 0;
    tcb->f28 = 0;
    return 0;
}

s32 get_field_534(TcpTcb *tcb) {
    return tcb->f534;
}

s32 get_field_d8(TcpTcb *tcb) {
    return tcb->fD8;
}

s32 get_score(TcpTcb *tcb) {
    if (tcb->f204_b7) {
        return tcb->req.total_bytes;
    }
    return tcb->f20 + tcb->req.total_bytes;
}

s32 get_queue_diff(TcpTcb *tcb) {
    return tcb->f534 - tcb->fD8;
}

s32 get_adjusted_slot_count(TcpTcb *tcb) {
    if (tcb->f204_b7) {
        return tcb->f530;
    }
    return tcb->f530 - tcb->f20;
}
