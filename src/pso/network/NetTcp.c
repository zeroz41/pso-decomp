#include "pso/network/UdpRuntime.h"
#include "pso/network/SocketEvents.h"
#include "pso/network/NetworkDispatch.h"
#include "pso/network/NetworkRuntime.h"
#include "pso/network/PppChap.h"
#include "pso/network/NetworkPacketPool.h"
#include "pso/network/netcfg.h"
#include "pso/network/BufferRef.h"
#include "pso/network/IPv6.h"

#include "types.h"
#include "pso/network/Ppp.h"
#include "pso/network/NetStack.h"
#include "pso/network/NetIpv6Route.h"

#include <stddef.h>

#include "pso/network/IPv6Send.h"
#include "pso/network/NetStackTypes.h"
#include "pso/network/NetTcpState.h"
#include "pso/network/NetApi.h"

/* This file's functions. */
void clear_position(TcpTcb *tcb);
s32 close_if_open(TcpTcb *tcb);
s32 get_rcv_bufsize(TcpTcb *tcb);
s32 get_rcv_count(TcpTcb *tcb);
s32 get_rcv_space(TcpTcb *tcb);
s32 get_snd_queued(TcpTcb *tcb);
void insert_item_at(TcpTcb *tcb, s16 idx, s32 a, s32 b);
void reset_slot_index(TcpTcb *tcb);

s16 tcp_sack_empty(TcpTcb *tcb);
s32 get_snd_space(TcpTcb *tcb);
TcpTcb *tcp_close(TcpTcb *tcb);

s32 tcp_free_rcv_buf(TcpTcb *tcb);
s16 tcp_alloc_snd_buf(TcpTcb *tcb);
void tcp_fasttimo(void);
void tcp_slowtimo(void);
s32 tcp_timers(TcpTcb *tcb, s16 timer);
s16 tcp_respond(NetworkAddress *dst, NetworkAddress *src_addr, u16 sport, u16 dport, s32 seq, s32 ack, u8 flags);
void tcp_init_tcb(s16 idx);
void tcp_sack_doack(TcpTcb *tcb, TcpHdr *th, TcpSeqRange *blocks, s16 n);



TcpState tcp_protocol_state;


/* Inline the helpers below; this applies to the rest of the file. */
#pragma dont_inline off
#pragma inline_depth(4)

s32 tcp_term(void) {
    NetUnregisterTimer(tcp_slowtimo);
    NetUnregisterTimer(tcp_fasttimo);
    term_tcp_config(&tcp_protocol_state);
    tcp_protocol_state.count = 0;
    return 0;
}

#pragma push
#pragma opt_common_subs on
s16 NetTCPInit(void) {
    s16 n;
    s16 i;
    TcpTcb *e;
    init_params(&tcp_protocol_state);
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
    tcp_protocol_state.initial_window = 2;
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
    NetRegisterTimer(500, (s16)(1), (NetTimerCallback)(tcp_slowtimo));
    NetRegisterTimer(100, (s16)(1), (NetTimerCallback)(tcp_fasttimo));
    return 0;
}
#pragma pop

extern void tcp_fasttimo(void) {
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
                AT_TCP_Rawsend(e);
            }
        }
    }
}

void tcp_drop(TcpTcb *tcp_tcb, s16 error) {
    s16 idx = tcp_tcb - tcp_protocol_state.tcbs;

    if (tcp_tcb->t_state >= 3) {
        tcp_tcb->t_state = 0;
        AT_TCP_Rawsend(tcp_tcb);
    }
    tcp_tcb->error = error;
    switch (error) {
    case 4:
        set_thread_state_and_resume(idx, tcp_tcb->send_done, -8);
        set_slot_state_and_resume(idx, tcp_tcb->recv_done, -8);
        NetDispatchSocketEvent(idx, tcp_tcb->event_ctx, 3, 0xB);
        break;
    default:
        set_thread_state_and_resume(idx, tcp_tcb->send_done, -5);
        set_slot_state_and_resume(idx, tcp_tcb->recv_done, -5);
        NetDispatchSocketEvent(idx, tcp_tcb->event_ctx, 3, 0xA);
        break;
    }
    if (tcp_close(tcp_tcb) != 0) {
        tcp_tcb->t_state = -1;
    }
}

extern void tcp_slowtimo(void) {
    TcpState *g = &tcp_protocol_state;
    TcpTcb *tcb;
    s16 i;
    s16 j;

    g->maxidle = g->keepintvl << 3;
    tcb = g->tcbs;
    for (i = 0; i < g->count; tcb++, i++) {
        if (tcb->state != 0 && tcb->state == 1) {
            for (j = 0; j < 4; j++) {
                if (tcb->timers[j] > 0) {
                    tcb->timers[j]--;
                    if (tcb->timers[j] == 0) {
                        tcp_timers(tcb, j);
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
extern s32 tcp_timers(TcpTcb *tcb, s16 timer) {
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
            tcp_close(tcb);
        }
        break;
    case 0:
        tcb->rxtshift++;
        if (tcb->rxtshift > 12) {
            tcb->rxtshift = 12;
            tcp_drop(tcb, 4);
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
        reset_slot_index(tcb);
        tcb->rexmit_bytes = 0;
        tcb->pipe = 0;
        tcb->recover = tcb->snd_una;
        tcb->snd_nxt = tcb->snd_una;
        tcb->rtt = 0;
        win = ((tcb->snd_wnd < tcb->snd_cwnd) ? tcb->snd_wnd : tcb->snd_cwnd) / 2 / tcb->maxseg;
        if (win < 2) {
            win = 2;
        }
        tcb->snd_cwnd = tcb->maxseg;
        tcb->snd_ssthresh = win * tcb->maxseg;
        AT_TCP_Rawsend(tcb);
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
        AT_TCP_Rawsend(tcb);
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
            tcp_respond(&tcb->remote, &tcb->local, tcb->hdr.sport, tcb->hdr.dport, tcb->snd_una - 1, tcb->rcv_nxt, 16);
            tcb->timers[2] = (g->keepintvl < tcb->keepidle) ? g->keepintvl : tcb->keepidle;
        } else if (keep != 0) {
            tcb->timers[2] = keep;
        } else {
            tcb->timers[2] = g->keepidle;
        }
        break;
    drop:
        tcp_drop(tcb, 4);
        break;
    }
    return 0;
}
#pragma pop

void clear_position(TcpTcb *tcb) {
    tcb->timers[0] = 0;
    tcb->timers[1] = 0;
    tcb->timers[2] = 0;
    tcb->timers[3] = 0;
}

s32 tcp_sack_next_hole(TcpTcb *tcb, s32 *p1, s32 *p2);
#pragma push
#pragma opt_common_subs on
#pragma opt_propagation off
#pragma opt_loop_invariants off
s16 AT_TCP_Rawsend(TcpTcb *tp)
{
    TcpTcb *q;
    u16 header_bytes;
    s32 lim;
    s32 sendalot;
    s32 avail;
    int win;
    s32 fin;
    s32 t;
    u8 *optp;
    u16 b;
    s32 retransmit_length;
    u8 *opt;
    TcpHdr *th = &tp->hdr;
    int len;
    s16 mss;
    u16 optlen;
    NetPacket *m;
    s32 idle;
    u16 sackoff;
    TcpState *ts = &tcp_protocol_state;
    int off;
    s32 flags;
    s32 recwin;
    u16 i;
    int sack_length;
    u32 pad0[4];
    s32 sack_start;
    s32 sack_end;
    u16 tmp;
    s32 tmp4;
    s32 tmp4b;
    u32 pad1[2];

    if (tp->t_state < 0) {
        return -1;
    }
    if (AT_IP_IsReachable(&tp->remote, &tp->local) == 0) {
        NetDispatchSocketEvent((s16)(tp - ts->tcbs), tp->event_ctx, 3, 0xc);
        return -6;
    }
    mss = (s16)AT_IP_GetMssFromDstSrc(&tp->remote, &tp->local);
    b = tp->maxseg;
    mss = (s16)(b < mss ? b : mss);
    if (mss < 0) {
        return mss;
    }
    idle = (u32)__cntlzw(tp->snd_una - tp->snd_max) >> 5;
    if (tp->snd_max == tp->snd_una && tp->idle >= tp->rxtcur) {
        switch (tp->initial_window) {
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
            tp->snd_cwnd = get_snd_space(tp);
            break;
        }
    }
    for (;;) {
        opt = ts->opts;
        sendalot = 0;
        len = 0;
        if (tp->recover != tp->snd_una) {
            retransmit_length = tcp_sack_next_hole(tp, &sack_start, &sack_end);
            len = retransmit_length;
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
            len = ((u32)get_snd_queued(tp) < (u32)win ? get_snd_queued(tp) : win) - off;
        }
        t = tp->snd_cwnd - tp->pipe;
        if (tp->recover == tp->snd_una) {
            t -= tp->snd_nxt - tp->snd_una;
        }
        if (t < 0) {
            t = 0;
        }
        if (len > t) {
            len = t;
            sendalot = 0;
        }
        if (off + len < get_snd_queued(tp)) {
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
        if ((s32)((tp->snd_nxt + len) - (tp->snd_una + get_snd_queued(tp))) < 0) {
            flags &= ~1;
        }
        recwin = get_rcv_space(tp);
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
                t = get_snd_queued(tp);
            } else {
                t = ((u32)get_snd_queued(tp) < tp->snd_bufsize) ? get_snd_queued(tp) : tp->snd_bufsize;
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
            if (win * 2 >= get_rcv_bufsize(tp)) {
                goto send;
            }
        }
        if ((u32)get_snd_queued(tp) != 0 && tp->timers[0] == 0 && tp->timers[1] == 0) {
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
            tp->rexmit_bytes = 0;
            reset_slot_index(tp);
            opt[0] = 2;
            optp = opt;
            opt[1] = 4;
            tmp = (tp->rcv_bufsize < (u32)mss) ? tp->rcv_bufsize : mss;
            NetMemcpy(optp + 2, &tmp, 2);
            optlen = 4;
            if (tp->sack_flags & 1) {
                opt[4] = 4;
                opt[5] = 2;
                opt[6] = 1;
                opt[7] = 1;
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
            sack_length = 2;
            i = 0;
            optlen += 2;
            while (i < 5 && q->sack[0].start != q->sack[0].end && (s32)optlen + 8 <= 0x28) {
                tmp4 = q->sack[0].start;
                tmp4b = q->sack[0].end;
                NetMemcpy(optp + optlen, &tmp4, 4);
                NetMemcpy(optp + (u16)(optlen + 4), &tmp4b, 4);
                optlen += 8;
                sack_length += 8;
                q = (TcpTcb *)((u8 *)q + sizeof(TcpSeqRange));
                i++;
            }
            opt[sackoff] = (u8)sack_length;
        }
        while ((optlen % 4) != 0) {
            optp[optlen] = 1;
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
        if ((u32)recwin < ((u32)get_rcv_bufsize(tp) >> 2) && (u32)recwin < tp->maxseg) {
            recwin = 0;
        }
        if (recwin < (s32)(tp->rcv_adv - tp->rcv_nxt)) {
            recwin = tp->rcv_adv - tp->rcv_nxt;
        }
        if ((u32)recwin > tp->rcv_bufsize) {
            recwin = tp->rcv_bufsize;
        }
        th->win = recwin;
        if ((s32)(tp->snd_up - tp->snd_nxt) > 0) {
            th->urp = tp->snd_up - tp->snd_nxt;
            flags |= 0x20;
        } else {
            tp->snd_up = tp->snd_una;
        }
        if (len != 0 && off + len == get_snd_queued(tp)) {
            flags |= 8;
        }
        win = 0;
        th->sum = win;
        th->flags = flags;
        th->off = (((i + (s32)sizeof(TcpHdr)) >> 2) << 4) & 0xf0;
        m = alloc_free_entry();
        if (m == 0) {
            return -0x101;
        }
        m->fragment_count = 0;
        m->total_bytes = 0;
        if (tcp_gather_send_data(off, len, m, tp) < 0) {
            m->fragment_count = 0;
            m->total_bytes = 0;
        }
        if (optlen != 0) {
            m->total_bytes += optlen;
            m->fragments[m->fragment_count].length = optlen;
            set_value_and_enable(&m->fragments[m->fragment_count].buffer, optp);
            m->fragment_count++;
        }
        header_bytes = sizeof(TcpHdr);
        m->total_bytes += header_bytes;
        m->fragments[m->fragment_count].length = header_bytes;
        set_value_and_enable(&m->fragments[m->fragment_count].buffer, th);
        m->fragment_count++;
        th->sum = calc_transport_checksum(&tp->local, &tp->remote, 6, m, 1);
        if (tp->force == 0 || tp->timers[1] == 0) {
            win = tp->snd_nxt;
            if (flags & 2) {
                tp->snd_nxt = win + 1;
            }
            if (flags & 1) {
                tp->snd_nxt += 1;
                tp->flags |= 0x10;
            }
            if (tp->snd_una != tp->recover) {
                tp->pipe += len;
            }
            if (len > 0) {
                s32 first = tp->snd_una + off;
                s32 last = len + first;
                if ((s32)(last - tp->snd_nxt) > 0) {
                    tp->snd_nxt += len;
                } else {
                    tcp_sack_mark_rexmit(tp, first, last);
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
            s16 rc = dispatch_by_addr_family(m, &tp->remote, &tp->local, tp->ip4_opts, tp->ip6_opts, 6);
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
s16 tcp_respond(NetworkAddress *dst, NetworkAddress *src_addr, u16 sport, u16 dport, s32 seq, s32 ack, u8 flags) {
    TcpHdr src;
    TcpHdr hdr;
    void *p1;
    void *p2;
    void *p3;
    void *p4;
    void *p5;
    void *p6;
    void *p7;
    void *p8;
    void *ph;
    NetPacket *pkt;
    u8 buf[0x10];

    NetMemset(buf, 0, 0x10);
    if (!AT_IP_IsReachable(dst, src_addr)) {
        return -1;
    }
    src.sport = sport;
    src.dport = dport;
    p1 = &src.dport;
    p2 = &src.seq;
    src.seq = seq;
    p3 = &src.ack;
    p4 = &src.off;
    src.ack = ack;
    p5 = &src.flags;
    p8 = &src.urp;
    src.off = 0x50;
    p7 = &src.sum;
    p6 = &src.win;
    src.flags = flags;
    src.urp = 0;
    src.sum = 0;
    src.win = 0;
    pkt = alloc_free_entry();
    if (pkt == NULL) {
        return -0x101;
    }
    pkt->fragment_count = 1;
    pkt->total_bytes = 0x14;
    pkt->fragments[0].length = 0x14;
    NetMemcpy(&hdr.sport, &src.sport, 2);
    NetMemcpy(&hdr.dport, p1, 2);
    NetMemcpy(&hdr.seq, p2, 4);
    NetMemcpy(&hdr.ack, p3, 4);
    NetMemcpy(&hdr.off, p4, 1);
    NetMemcpy(&hdr.flags, p5, 1);
    NetMemcpy(&hdr.win, p6, 2);
    ph = &hdr.sum;
    NetMemcpy(ph, p7, 2);
    NetMemcpy(&hdr.urp, p8, 2);
    set_value_and_enable(&pkt->fragments[0].buffer, &hdr);
    src.sum = ((s16)calc_transport_checksum(src_addr, dst, (s8)(6), pkt, (s16)(1)));
    NetMemcpy(ph, &src.sum, 2);
    if (dispatch_by_addr_family(pkt, dst, src_addr, buf + 4, buf + 4, 6) < 0) {
        release_entry(pkt);
        return -1;
    }
    release_entry(pkt);
    return 0;
}

extern TcpTcb *tcp_close(TcpTcb *self) {
    TcpState *g = &tcp_protocol_state;
    s16 idx;
    s32 tmp;
    s32 pad[2];

    (void)pad;
    if (self == NULL) {
        return NULL;
    }
    if (self->flags & 0x80) {
        if (!(self->flags & 0x20)) {
            idx = (s16)(self - g->tcbs);
            NetDispatchSocketEvent(idx, self->event_ctx, 3, 3);
            self->flags |= 0x20;
        }
        close_if_open(self);
        tcp_free_rcv_buf(self);
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
        self->state = 0;
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

extern s16 AT_TCP_Mss(TcpTcb *tp) {
    s32 mss = AT_IP_GetMssFromDstSrc(&tp->remote, &tp->local);

    return tp->maxseg < mss ? tp->maxseg : mss;
}

s16 tcp_alloc_rcv_buf(TcpTcb *tcb);
extern TcpTcb *tcp_newconn(TcpTcb *self, TcpHdr *th, NetworkAddress *a, NetworkAddress *b) {
    u16 v;
    TcpTcb *dst;
    s32 w;
    s32 n;
    s16 idx;
    u8 *sp;

    if (self->backlog <= self->pending) return NULL;
    idx = tcp_alloc_tcb();
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

    if (is_addr_unspecified(&self->remote)) {
        NetMemcpy(&dst->remote, a, sizeof(dst->remote));
    } else {
        NetMemcpy(&dst->remote, &self->remote, sizeof(dst->remote));
    }
    NetMemcpy(&dst->local, b, sizeof(dst->local));
    NetMemcpy(dst->ip4_opts, self->ip4_opts, 3);
    NetMemcpy(dst->ip6_opts, self->ip6_opts, 12);

    n = AT_IP_GetMssFromDstSrc(&dst->remote, &dst->local);
    w = dst->maxseg;
    w = (w < n) ? w : n;
    if ((s16)w < 0) {
        dst->state = 0;
        return NULL;
    }

    dst->snd_bufsize = self->snd_bufsize;
    dst->rcv_bufsize = self->rcv_bufsize;
    if (tcp_alloc_snd_buf(dst) < 0) {
        dst->state = 0;
        return NULL;
    }
    if (tcp_alloc_rcv_buf(dst) < 0) {
        close_if_open(dst);
        dst->state = 0;
        return NULL;
    }

    dst->event_ctx = self->event_ctx;
    dst->listener = (s16)(self - tcp_protocol_state.tcbs);
    self->pending += 1;
    dst->sack_flags = self->sack_flags;
    dst->ack_now = self->ack_now;
    dst->initial_window = self->initial_window;
    dst->flags = self->flags;
    dst->maxseg = self->maxseg;
    return dst;
}
extern s32 tcp_dooptions(TcpTcb *self, u8 *data, s16 total, TcpHdr *th);
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
s16 tcp_input(NetPacket *pkt, NetworkAddress *remote, NetworkAddress *local) {
    s32 changed = 0;
    u32 flag = 0;
    u32 total = 0;
    TcpTcb *found = 0;
    s16 kind;
    s16 ti_flags;
    s32 blen;
    s16 option_bytes;
    TcpHdr *ti;
    s32 st;
    u32 tmp;
    TcpHdr hdr;
    NetPacketFragment *p = &pkt->fragments[1];
    TcpHdr *src;
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

    pkt->total_bytes = pkt->total_bytes - pkt->fragments[0].length;
    pkt->fragments[0].length = 0;
    src = (TcpHdr *)netbuf_ref_data(&p->buffer);
    NetMemcpy(&hdr.sport, &src->sport, 2);
    NetMemcpy(&hdr.dport, &src->dport, 2);
    NetMemcpy(&hdr.seq, &src->seq, 4);
    NetMemcpy(&hdr.ack, &src->ack, 4);
    NetMemcpy(&hdr.off, &src->off, 1);
    NetMemcpy(&hdr.flags, &src->flags, 1);
    NetMemcpy(&hdr.win, &src->win, 2);
    NetMemcpy(&hdr.sum, &src->sum, 2);
    NetMemcpy(&hdr.urp, &src->urp, 2);
    ti = &hdr;
    kind = ti->flags;
    ti_flags = kind;
    len = ti->off >> 2;
    if ((u32)pkt->total_bytes < sizeof(TcpHdr)) {
        return -1;
    }
    if (calc_transport_checksum(remote, local, 6, pkt, 0)) {
        goto drop;
    }
    option_bytes = (s16)(len - (s32)sizeof(TcpHdr));
    blen = option_bytes;
    if ((s16)blen != 0) {
        body = netbuf_ref_data(&p->buffer) + sizeof(TcpHdr);
    } else {
        body = 0;
    }
    if (len < 0x14) {
        goto drop;
    }
    if ((u16)pkt->total_bytes < len) {
        goto drop;
    }
    NetMemcpy(&tmp, &ti->seq, 4);
    NetMemcpy(&ti->seq, &tmp, 4);
    NetMemcpy(&tmp, &ti->ack, 4);
    NetMemcpy(&ti->ack, &tmp, 4);
    rem = pkt->total_bytes - len;
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
            if (compare_sockaddr(&ent->remote, remote)) {
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
            if (compare_sockaddr(&ent->remote, remote)) {
                if (!is_addr_unspecified(&ent->remote)) {
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
        if (found->shutdown & 0x4) {
            goto drop;
        }
    }
    if (st != 1) {
        found->idle = 0;
        found->timers[2] = found->keepidle;
    }
    if (body != 0 && found->t_state != 1) {
        tcp_dooptions(found, body, blen, ti);
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
        if (is_multicast_address(local, 0) == 1) {
            goto drop;
        }
        ent_new = tcp_newconn(found, ti, remote, local);
        if (ent_new == 0) {
            goto drop;
        }
        if (body != 0) {
            tcp_dooptions(ent_new, body, blen, ti);
        }
        if (flag) {
            ent_new->iss = flag;
        } else {
            ent_new->iss = tcp_protocol_state.iss;
        }
        tcp_protocol_state.iss += 0xFA00;
        ent_new->irs = hdr.seq;
        ent_new->snd_una = ent_new->snd_nxt = ent_new->snd_max =
            ent_new->snd_up = ent_new->recover = ent_new->una =
            ent_new->iss;
        ent_new->rcv_adv = ent_new->rcv_nxt = ent_new->irs + 1;
        ent_new->flags |= 1;
        ent_new->t_state = 3;
        ent_new->timers[2] = 0x96;
        switch (ent_new->initial_window) {
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
            ent_new->snd_cwnd = get_snd_space(ent_new);
            break;
        }
        {
            ent_new->event_ctx = found->accept_ctx;
            found->accept_ctx = 0;
            {
                int listener_index = found - tcp_protocol_state.tcbs;
                int accepted_index = ent_new - tcp_protocol_state.tcbs;
                complete_accept_request(listener_index,
                                     found->accept_cb,
                                     accepted_index, &ent_new->remote,
                                     (s32)(ent_new)->hdr.sport, (s32)(ent_new)->hdr.dport);
            }
        }
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
                tcp_drop(found, 1);
            }
            goto drop;
        }
        if (!(kind & 2)) {
            goto drop;
        }
        if (ack) {
            found->snd_una = ti->ack;
            found->recover = ti->ack;
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
            found->maxseg = AT_TCP_Mss(found);
            switch (found->initial_window) {
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
                found->snd_cwnd = get_snd_space(found);
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
            if (!(kind & 1) || todrop != (u16)rem + 1) {
                goto dropafterack;
            }
            todrop = (int)rem;
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
        u16 segment_bytes = rem;
        if (todrop >= segment_bytes) {
            if ((kind & 2) && found->t_state == 10 && found->rcv_count == 0 &&
                (s32)(hdr.seq - found->rcv_nxt) > 0) {
                flag = found->rcv_nxt + 0x1F400;
                NetDispatchSocketEvent(TCP_IDX(found), found->event_ctx, 3, 4);
                found->flags |= 0x80;
                tcp_close(found);
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
            if (tcp_close(found) != 0) {
                found->t_state = -1;
            }
            goto drop;
        case 7:
        case 8:
        case 10:
            NetDispatchSocketEvent(TCP_IDX(found), found->event_ctx, 3, 4);
            found->flags |= 0x80;
            tcp_close(found);
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
        found->maxseg = AT_TCP_Mss(found);
        switch (found->initial_window) {
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
            found->snd_cwnd = get_snd_space(found);
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
        if ((s32)(hdr.ack - found->snd_una) <= 0 && found->snd_una == found->recover) {
            if (rem == 0 && hdr.win == found->snd_wnd) {
                if (found->timers[0] == 0 || hdr.ack != found->snd_una) {
                    found->dupacks = 0;
                } else if (++found->dupacks == (u8)TCP_REXMTTHRESH) {
                    u32 onxt = found->snd_nxt;
                    u32 win = TCP_MIN(found->snd_wnd, found->snd_cwnd) / 2 / found->maxseg;

                    if (tcp_sack_empty(found) == 0) {
                        found->recover = found->snd_nxt;
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
                    AT_TCP_Rawsend(found);
                    found->snd_cwnd = found->snd_ssthresh + found->maxseg * found->dupacks;
                    if ((s32)(onxt - found->snd_nxt) > 0) {
                        found->snd_nxt = onxt;
                    }
                    goto drop;
                } else if (found->dupacks > (u8)TCP_REXMTTHRESH) {
                    found->snd_cwnd += found->maxseg;
                    AT_TCP_Rawsend(found);
                    goto drop;
                }
            } else {
                found->dupacks = 0;
            }
            break;
        }
    newreno:
        if ((s32)(found->snd_una - found->recover) < 0 && (s32)(hdr.ack - found->recover) < 0) {
            if (rem == 0 && hdr.win <= found->snd_wnd) {
                if (hdr.ack != found->snd_una) {
                    acked = hdr.ack - found->snd_una;
                    tcp_drop_acked_data(acked, found);
                    found->snd_wnd -= acked;
                    if (hdr.win > found->snd_wnd) {
                        found->snd_wnd = hdr.win;
                    }
                    found->snd_una = hdr.ack;
                }
                if (++found->dupacks == (u8)TCP_REXMTTHRESH) {
                    u32 win = TCP_MIN(found->snd_wnd, found->snd_cwnd) / 2 / found->maxseg;

                    found->pipe = found->snd_nxt - found->snd_una -
                                              found->maxseg * found->dupacks - found->maxseg;
                    if (found->pipe < 0) {
                        found->pipe = 0;
                    }
                    if (win < 2) {
                        win = 2;
                    }
                    found->snd_ssthresh = win * found->maxseg;
                    found->timers[0] = 0;
                    found->rtt = 0;
                    found->snd_cwnd = found->pipe + found->maxseg;
                    AT_TCP_Rawsend(found);
                    found->snd_cwnd = found->snd_ssthresh;
                    goto drop;
                } else if (found->dupacks > (u8)TCP_REXMTTHRESH) {
                    found->pipe -= found->maxseg;
                    AT_TCP_Rawsend(found);
                    goto drop;
                }
            } else if (hdr.win > found->snd_wnd) {
                found->snd_wnd = hdr.win;
            } else {
                found->dupacks = 0;
            }
            break;
        }
        reset_slot_index(found);
        found->pipe = 0;
        found->recover = hdr.ack;
        if (found->dupacks > TCP_REXMTTHRESH && found->snd_cwnd > found->snd_ssthresh) {
            found->snd_cwnd = found->snd_ssthresh;
        }
        found->dupacks = 0;
        if ((s32)(hdr.ack - found->snd_max) > 0) {
            goto dropafterack;
        }
        acked = hdr.ack - found->snd_una;
        if ((rtt = found->rtt) != 0 && (s32)(hdr.ack - found->rtseq) > 0) {
            s32 delta;

            if ((srtt = found->srtt) != 0) {
                delta = (s16)(rtt - 1 - (srtt >> 3));
                if ((found->srtt += delta) <= 0) {
                    found->srtt = 1;
                }
                if ((s32)(s16)delta < 0L) {
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
            s32 n = get_snd_queued(found);

            if (acked > n) {
                ourfinisacked = 1;
            } else {
                n = acked;
                ourfinisacked = 0;
            }
            tcp_drop_acked_data(n, found);
            found->snd_wnd -= (u16)n;
        }
        found->snd_una = hdr.ack;
        if ((s32)(found->snd_nxt - found->snd_una) < 0) {
            found->snd_nxt = found->snd_una;
        }
        switch (found->t_state) {
        case 6:
            if (ourfinisacked) {
                if (found->shutdown & 4) {
                    found->timers[3] = tcp_protocol_state.maxidle;
                }
                found->t_state = 9;
            }
            break;
        case 7:
            if (ourfinisacked) {
                found->t_state = 10;
                if ((u32)get_snd_queued(found) == 0) {
                    close_if_open(found);
                }
                if ((u32)get_rcv_count(found) == 0) {
                    tcp_free_rcv_buf(found);
                }
                clear_position(found);
                found->timers[3] = 0x78;
            }
            break;
        case 8:
            if (ourfinisacked) {
                NetDispatchSocketEvent(TCP_IDX(found), found->event_ctx, 3, 4);
                tcp_close(found);
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
        if ((u32)get_rcv_space(found) + hdr.urp > 0x10000) {
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
        if (hdr.seq == found->rcv_nxt && (found->t_state == 4 || (found->shutdown & 0x0c))) {
            s32 off;

            kind = ti_flags & 1;
            found->rcv_nxt += rem;
            off = len + total;
            if (!(found->shutdown & 0x04)) {
                tcp_append_rcvbuf(pkt, off, found);
            }
            if (found->ack_now == 0) {
                if (found->ack_delay == 0) {
                    found->ack_delay = (s16)(tcp_protocol_state.ack_ticks / 100);
                }
            } else {
                found->flags |= 1;
            }
            goto fin_check;
        } else {
            if ((s32)(hdr.seq - found->rcv_nxt) > 0) {
                tcp_reass(pkt, (len + total) & 0xffff, found, ti);
            }
            kind &= ~1;
            found->flags |= 1;
            goto fin_check;
        }
    }
    kind &= ~1;
fin_check:
    if (!(kind & 1)) {
        goto send_pending;
    }
    NetDispatchSocketEvent(TCP_IDX(found), found->event_ctx, 3, 2);
    if (!(found->flags & 0x08)) {
        tcp_notify_receiver(found);
        found->flags |= 1;
        found->rcv_nxt += 1;
    }
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
        if ((u32)get_snd_queued(found) == 0) {
            close_if_open(found);
        }
        if ((u32)get_rcv_count(found) == 0) {
            tcp_free_rcv_buf(found);
        }
        clear_position(found);
        found->timers[3] = 0x78;
        break;
    case 10:
        found->timers[3] = 0x78;
        break;
    }
send_pending:
    if (changed != 0 || (found->flags & 1)) {
        AT_TCP_Rawsend(found);
    }
    return 0;

dropafterack:
    if (kind & 4) {
        goto drop;
    }
    found->flags |= 1;
    AT_TCP_Rawsend(found);
    return 0;

dropwithreset:
    if (kind & 4) {
        goto drop;
    }
    if (is_multicast_address(local, 0) == 1) {
        goto drop;
    }
    if (kind & 0x10) {
        if (tcp_respond(remote, local, hdr.dport, hdr.sport, hdr.ack, 0, 4) < 0) {
            return -1;
        }
    } else {
        if (kind & 2) {
            rem++;
        }
        {
            u32 reset_ack = rem + hdr.seq;
            if (tcp_respond(remote, local, hdr.dport, hdr.sport, 0, reset_ack, 0x14) < 0) {
                return -1;
            }
        }
    }
    return 0;

drop:
    return 0;
}
#pragma pop
#pragma pop

s16 tcp_sack_rexmit_before(TcpTcb *tcb, s32 x);
#pragma push
#pragma opt_common_subs on
s32 tcp_dooptions(TcpTcb *self, u8 *data, s16 total, TcpHdr *th)
{
  s32 n;
  s16 done = 0;
  u8 sz;
  s16 k;
  s32 last;
  u8 *p;
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
          if ((sz == 4) && (th->flags & 2))
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
          TcpSeqRange *tbl = tcp_protocol_state.sack_opt;
          last = self->snd_una;
          if (((sz - 2) % 8) != 0)
          {
            break;
          }
          if ((sz > 0x22) || (sz < 0xa))
          {
            break;
          }
          p = data + 2;
          n = (sz - 2) / 8;
          for (k = 0; k < n; k++)
          {
            NetMemcpy(&tmp, p, 4);
            tbl[k].start = tmp;
            NetMemcpy(&tmp, p + 4, 4);
            p += 8;
            tbl[k].end = tmp;
            if ((s32)(tbl[k].end - last) > 0)
            {
              last = tbl[k].end;
            }
          }

          tcp_sack_doack(self, th, tbl, n);
          if (tcp_sack_rexmit_before(self, last) != 0)
          {
            self->edge = self->snd_una;
          }
        }
          break;

      }

    }
    done += sz;
    data += sz;
  }

  self->maxseg = ((self->peer_mss) < ((s16) AT_TCP_Mss(self))) ? (self->peer_mss) : ((s16) AT_TCP_Mss(self));
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

s16 tcp_sack_empty(TcpTcb *tcb) {
    if (tcb->seg_top == -1) {
        return 1;
    }
    return 0;
}

void reset_slot_index(TcpTcb *tcb) {
    tcb->seg_top = -1;
    tcb->edge = tcb->una;
}

void tcp_sack_mark_rexmit(TcpTcb *tp, s32 first, s32 last) {
    s16 i;
    s32 start;

    tp->rexmit_bytes += last - first;
    for (i = 0; i <= tp->seg_top; i++) {
        start = tp->segs[i].start;
        if (first - start < 0) {
            if (i == 0) {
                if (last - start <= 0) {
                    if (last - tp->edge < 0) {
                        return;
                    }
                    tp->edge = last;
                    tp->stamp = tp->snd_max;
                    return;
                }
                tp->edge = start;
                tp->stamp = tp->snd_max;
            } else {
                if (last - start <= 0) {
                    u8 *e = (u8 *)tp;
                    s32 off = i * 16;
                    e += off;
                    if (last - *(s32 *)(e += offsetof(TcpTcb, edge)) < 0) {
                        return;
                    }
                    *(s32 *)e = last;
                    e = (u8 *)tp;
                    e += off;
                    *(s32 *)(e + offsetof(TcpTcb, stamp)) = tp->snd_max;
                    return;
                }
                tp->segs[i - 1].edge = start;
                tp->segs[i - 1].stamp = tp->snd_max;
            }
        }
    }
}

s32 tcp_sack_next_hole(TcpTcb *tp, s32 *start, s32 *end) {
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

s16 tcp_sack_rexmit_before(TcpTcb *tcb, s32 x) {
    s16 n = tcb->seg_top;
    s16 i;
    if (n == -1) { return 0; }
    if (tcb->stamp - x < 0) { return 1; }
    for (i = 0; i < n; i++) {
        if (tcb->segs[i].stamp - x < 0) { return 1; }
    }
    return 0;
}

inline void scoreboard_remove(TcpTcb *tcb, s16 idx) {
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
void tcp_sack_doack(TcpTcb *tcb, TcpHdr *th, TcpSeqRange *blocks, s16 n) {
    s16 i;
    s16 j;
    s32 d;

    if (SEQ_GT(th->ack, tcb->una)) {
        for (;;) {
            if (tcb->seg_top < 0) {
                break;
            }
            if (SEQ_GT(th->ack, tcb->edge)) {
                tcb->rexmit_bytes -= tcb->edge - tcb->una;
                tcb->edge = th->ack;
                if (tcb->rexmit_bytes < 0) {
                    tcb->rexmit_bytes = 0;
                }
            } else {
                tcb->rexmit_bytes -= th->ack - tcb->una;
                if (tcb->rexmit_bytes < 0) {
                    tcb->rexmit_bytes = 0;
                }
            }
            if (SEQ_GEQ(th->ack, tcb->segs[0].end)) {
                tcb->edge = tcb->segs[0].edge;
                tcb->stamp = tcb->segs[0].stamp;
                tcb->una = tcb->segs[0].end;
                scoreboard_remove(tcb, 0);
                continue;
            }
            if (SEQ_GEQ(th->ack, tcb->segs[0].start)) {
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
        TcpSeqRange *b = &blocks[i];
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
                tcb->rexmit_bytes -= tcb->edge - start;
                tcb->edge = b->start;
                if (tcb->rexmit_bytes < 0) {
                    tcb->rexmit_bytes = 0;
                }
            }
            insert_item_at(tcb, 0, b->start, b->end);
            j = 0;
        } else {
            for (j = 1; j <= tcb->seg_top; j++) {
                if (SEQ_GT(b->start, tcb->segs[j].start)) {
                    continue;
                }
                if (SEQ_LT(b->start, tcb->segs[j - 1].end)) {
                    if (SEQ_LT(b->end, tcb->segs[j - 1].end)) {
                        continue;
                    }
                    if (end - tcb->segs[j - 1].edge > 0) {
                        tcb->rexmit_bytes -= tcb->segs[j - 1].edge - tcb->segs[j - 1].end;
                        tcb->segs[j - 1].end = b->end;
                        tcb->segs[j - 1].edge = b->end;
                        if (tcb->rexmit_bytes < 0) {
                            tcb->rexmit_bytes = 0;
                        }
                    } else {
                        tcb->rexmit_bytes -= end - tcb->segs[j - 1].end;
                        tcb->segs[j - 1].end = b->end;
                        if (tcb->rexmit_bytes < 0) {
                            tcb->rexmit_bytes = 0;
                        }
                    }
                    j = j - 1;
                } else {
                    if (start - tcb->segs[j - 1].edge < 0) {
                        tcb->rexmit_bytes -= tcb->segs[j - 1].edge - start;
                        tcb->segs[j - 1].edge = b->start;
                        if (tcb->rexmit_bytes < 0) {
                            tcb->rexmit_bytes = 0;
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
                    tcb->rexmit_bytes -= d;
                    tcb->segs[j].edge = tcb->segs[j + 1].edge;
                    scoreboard_remove(tcb, j + 1);
                    if (tcb->rexmit_bytes < 0) {
                        tcb->rexmit_bytes = 0;
                    }
                } else {
                    tcb->rexmit_bytes -= tcb->segs[j + 1].edge - tcb->segs[j + 1].end;
                    scoreboard_remove(tcb, j + 1);
                    if (tcb->rexmit_bytes < 0) {
                        tcb->rexmit_bytes = 0;
                    }
                }
            } else {
                tcb->segs[j].end = tcb->segs[j + 1].end;
                tcb->segs[j].edge = tcb->segs[j + 1].edge;
                scoreboard_remove(tcb, j + 1);
            }
        }
    }
}
#pragma pop

#pragma push
#pragma pool_data off
s16 tcp_get_socket_handle(i)
s16 i;
{
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
s32 tcp_start_receive(s16 handle, NetBufferRef *destination, s32 len, TcpCompletion callback) {
    s16 r;
    TcpTcb *e;

    if (handle < 0 || handle >= tcp_protocol_state.count) {
        r = -4;
    } else if (tcp_protocol_state.tcbs[handle].state != 1) {
        r = -4;
    } else {
        r = 0;
    }
    if (r < 0) {
        return -4;
    }
    e = tcp_protocol_state.tcbs;
    e += handle;
    switch (e->t_state) {
    case 0:
    case 4: case 5: case 6: case 7: case 8: case 9: case 10:
        if ((e->shutdown & 4) && (e->rcv_buf.kind == 0 || (u32)get_rcv_count(e) == 0)) {
            return -4;
        }
        break;
    }
    return tcp_user_receive(e, destination, len, callback);
}
#pragma pop

#pragma push
#pragma pool_data off
s16 tcp_start_send(id, req, completion, urgent)
s16 id;
NetPacket *req;
TcpCompletion completion;
u8 urgent;
{
    s16 r;
    s16 v;
    s16 ret;
    TcpTcb *e;
    if (id < 0 || id >= tcp_protocol_state.count) {
        r = -4;
    } else if (tcp_protocol_state.tcbs[id].state != 1) {
        r = -4;
    } else {
        r = 0;
    }
    if (r < 0) {
        return -4;
    }
    e = tcp_protocol_state.tcbs;
    e += id;
    v = e->t_state;
    if (v <= 1) {
        return -4;
    }
    if (v < 4) {
        return -4;
    }
    if (v > 5 && (e->shutdown & 8)) {
        return -4;
    }
    tcp_queue_send_request(req, e, completion);
    if (urgent != 0) {
        e->snd_up = e->snd_nxt + req->total_bytes;
    }
    ret = AT_TCP_Rawsend(e);
    tcp_drop_acked_data(0, e);
    return ret;
}
#pragma pop

#pragma push
#pragma pool_data off
s16 tcp_set_option(s16 i, s16 opt, u32 *val) {
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
        if (*val > g->snd_bufsize) {
            return -2;
        }
        tcb->snd_bufsize = *val;
        break;
    case 0x1002:
        if (*val > g->rcv_bufsize) {
            return -2;
        }
        tcb->rcv_bufsize = *val;
        break;
    case 0x2001:
        if (*val != 0) {
            tcb->ack_now = 1;
        } else {
            tcb->ack_now = 0;
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
        tcb->initial_window = *val;
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
s32 get_tcp_stat(id, state, pending, snd_space, rcv_count)
s16 id;
s16 *state;
s16 *pending;
u32 *snd_space;
u32 *rcv_count;
{
    s16 r;
    TcpTcb *e;

    if (id < 0 || id >= tcp_protocol_state.count) {
        r = -4;
    } else if (tcp_protocol_state.tcbs[id].state != 1) {
        r = -4;
    } else {
        r = 0;
    }
    if (r < 0) {
        return -4;
    }
    e = tcp_protocol_state.tcbs;
    e += id;
    if (state != NULL) {
        *state = e->t_state;
    }
    if (pending != NULL) {
        if (e->t_state == 1) {
            *pending = e->pending;
        } else {
            *pending = 0;
        }
    }
    if (snd_space != NULL) {
        *snd_space = get_snd_space(e);
    }
    if (rcv_count != NULL) {
        *rcv_count = get_rcv_count(e);
    }
    return 0;
}
#pragma pop

#pragma push
#pragma pool_data off
s32 mark_connection_closed(id)
s16 id;
{
    s16 r;
    TcpTcb *e;

    if (id < 0 || id >= tcp_protocol_state.count) {
        r = -4;
    } else if (tcp_protocol_state.tcbs[id].state != 1) {
        r = -4;
    } else {
        r = 0;
    }
    if (r < 0) {
        return -4;
    }
    e = tcp_protocol_state.tcbs;
    e += id;
    e->t_state = 0;
    e->flags |= 0x80;
    tcp_close(e);
    return 0;
}
#pragma pop

#pragma push
#pragma pool_data off
s32 abort_tcp_connection(id)
s16 id;
{
    s16 r;
    TcpTcb *e;

    if (id < 0 || id >= tcp_protocol_state.count) {
        r = -4;
    } else if (tcp_protocol_state.tcbs[id].state != 1) {
        r = -4;
    } else {
        r = 0;
    }
    if (r < 0) {
        return -4;
    }
    e = tcp_protocol_state.tcbs;
    e += id;
    if (e->t_state < 4) {
        e->t_state = 0;
    } else {
        e->t_state = 0;
        AT_TCP_Rawsend(e);
    }
    clear_position(e);
    return 0;
}
#pragma pop

void tcp_set_ip_options(idx, a, b)
s16 idx;
void *a;
void *b;
{
    TcpTcb *e;

    e = tcp_protocol_state.tcbs;
    e += idx;
    NetMemcpy(e->ip4_opts, a, sizeof(e->ip4_opts));
    NetMemcpy(e->ip6_opts, b, sizeof(e->ip6_opts));
}

u16 tcp_next_ephemeral_port(void);
#pragma push
#pragma opt_propagation off
#pragma push
#pragma pool_data off
s16 AT_TCP_Connect(s16 handle, NetworkAddress *addr, s16 port) {
    s16 r;
    TcpTcb *e;

    if (handle < 0 || handle >= tcp_protocol_state.count) {
        r = -4;
    } else if (tcp_protocol_state.tcbs[handle].state != 1) {
        r = -4;
    } else {
        r = 0;
    }
    if (r < 0) {
        return -4;
    }
    e = tcp_protocol_state.tcbs;
    e += handle;
    if (AT_IP_IsReachable(addr, &e->local) == 0) {
        NetDispatchSocketEvent((s16)(e - tcp_protocol_state.tcbs), e->event_ctx, 3, 0xC);
        return -6;
    }
    if (is_addr_unspecified(&e->local) != 0 && AT_IP_SetSrcFromDst(&e->local, addr) < 0) {
        NetDispatchSocketEvent((s16)(e - tcp_protocol_state.tcbs), e->event_ctx, 3, 0xC);
        return -6;
    }
    if (e->hdr.sport == 0) {
        e->hdr.sport = tcp_next_ephemeral_port();
    }
    NetMemcpy(&e->remote, addr, sizeof(e->remote));
    e->hdr.dport = port;
    if (AT_TCP_Mss(e) < 0) {
        return -6;
    }
    r = tcp_alloc_snd_buf(e);
    if (r < 0) {
        return r;
    }
    r = tcp_alloc_rcv_buf(e);
    if (r < 0) {
        close_if_open(e);
        return r;
    }
    e->snd_cwnd = (u16)get_snd_space(e);
    e->t_state = 2;
    e->timers[2] = 0x96;
    {
        u32 *t = &tcp_protocol_state.iss;
        u32 v = *t;
        e->iss = v;
        e->una = v;
        e->recover = v;
        e->snd_up = v;
        e->snd_max = v;
        e->snd_nxt = v;
        e->snd_una = v;
        *t += 0xFA00;
    }
    return AT_TCP_Rawsend(e);
}
#pragma pop

extern s32 tcp_unlink_listener(s16 idx) {
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

s32 tcp_pcbbind(s16 idx, NetworkAddress *a, u16 id) {
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
    if (NetValidateLocalAddress(a) < 0) {
        return -6;
    }
    if (id == 0) {
        e->hdr.sport = tcp_next_ephemeral_port();
    } else {
        p = g->tcbs;
        for (i = 0; i < g->count; i++) {
            if (p->state != 0 && p != e && p->hdr.sport == id) {
                if (is_addr_unspecified(a) != 0 || is_addr_unspecified(&p->local) != 0 ||
                    compare_sockaddr(&p->local, a) == 0) {
                    if (p->t_state == 10 && (p->flags & 0x80) != 0) {
                        tcp_close(p);
                    } else {
                        return -3;
                    }
                }
            }
            p++;
        }
        e->hdr.sport = id;
    }
    NetMemcpy(&e->local, a, sizeof(e->local));
    return 0;
}
s16 tcp_alloc_tcb(void)
{
  TcpState *g_m = (TcpState *) (*(u8(*)[])&tcp_protocol_state);
  TcpTcb *rec;
  s16 bestIdx = 0;
  TcpTcb *best = NULL;
  s16 idx;
  s16 count;
  TcpTcb *entries;
  s16 i = 0;
  idx = g_m->freed;
  count = g_m->count;
  entries = g_m->tcbs;
  for (; i < count; i++)
  {
    idx++;
    if (count <= idx)
    {
      idx = 0;
    }
    rec = entries + idx;
    if (rec->state == 0)
    {
      NetMemset(rec, 0, sizeof(TcpTcb));
      tcp_init_tcb(idx);
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
    tcp_close(best);
    NetMemset(best, 0, sizeof(TcpTcb));
    tcp_init_tcb(bestIdx);
    return bestIdx;
  }
  return -0x103;
}

#pragma pop

#pragma push
#pragma pool_data off
void tcp_init_tcb(s16 idx) {
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
    t->shutdown = 0;
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
    NetMemset(t->ip4_opts, 0, sizeof(t->ip4_opts));
    NetMemset(t->ip6_opts, 0, sizeof(t->ip6_opts));
    t->sack_flags = tcp_protocol_state.sack_flags;
    p = t->sack;
    for (i = 0; i < 5; i++, p++) {
        p->end = 0;
        p->start = 0;
    }
    t->seg_top = -1;
    t->snd_bufsize = tcp_protocol_state.snd_bufsize;
    t->rcv_bufsize = tcp_protocol_state.rcv_bufsize;
    t->event_ctx = 0;
    t->ack_now = tcp_protocol_state.ack_now;
    t->ack_delay = 0;
    t->initial_window = tcp_protocol_state.initial_window;
}
#pragma pop

u16 tcp_next_ephemeral_port(void)
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

s16 validate_tcp_handle(i)
s16 i;
{
    if (i < 0 || i >= tcp_protocol_state.count) { return -4; }
    if (tcp_protocol_state.tcbs[i].state != 1) { return -4; }
    return 0;
}

s32 tcp_free_rcv_buf(TcpTcb *tcb) {
    if (tcb->rcv_buf.kind == 0) {
        return -1;
    }
    buffer_pool_free(&tcb->rcv_alloc);
    tcb->rcv_buf.kind = 0;
    return 0;
}

s32 close_if_open(TcpTcb *tcb) {
    if (tcb->snd_buf.kind == 0) {
        return -1;
    }
    buffer_pool_free(&tcb->snd_alloc);
    tcb->snd_buf.kind = 0;
    return 0;
}

s16 tcp_alloc_rcv_buf(TcpTcb *tcb) {
    NetBufferRef buf;

    if (tcb->rcv_buf.kind == 0) {
        if (buffer_pool_alloc(&buf, tcb->rcv_bufsize, 1) < 0) {
            return -0x102;
        }
        init_msg(&tcb->rcv_alloc, buf.data);
        set_value_and_enable(&tcb->rcv_buf, buf.data);
    }
    tcb->rcv_count = 0;
    tcb->rcv_head = 0;
    tcb->rcv_tail = 0;
    tcb->reasm_total = 0;
    tcb->reasm_n = -1;
    tcb->last_reasm = -1;
    return 0;
}

s16 tcp_alloc_snd_buf(TcpTcb *tcb) {
    unsigned char off;
    NetBufferRef buf;

    if (tcb->snd_buf.kind == 0) {
        if (buffer_pool_alloc(&buf, tcb->snd_bufsize, 1) < 0) {
            return -0x102;
        }
        init_msg(&tcb->snd_alloc, buf.data);
        set_value_and_enable(&tcb->snd_buf, buf.data);
    }
    tcb->snd_count = 0;
    off = offsetof(TcpTcb, snd_head);
    *(s32 *)((u8 *)tcb + off) = 0;
    tcb->snd_tail = 0;
    return 0;
}

s32 get_rcv_bufsize(TcpTcb *tcb) {
    return tcb->rcv_bufsize;
}

s32 get_rcv_count(TcpTcb *tcb) {
    return tcb->rcv_count;
}

s32 get_snd_queued(TcpTcb *tcb) {
    if (tcb->f204_b7) {
        return tcb->req.total_bytes;
    }
    return tcb->snd_count + tcb->req.total_bytes;
}

s32 get_rcv_space(TcpTcb *tcb) {
    return tcb->rcv_bufsize - tcb->rcv_count;
}

s32 get_snd_space(TcpTcb *tcb) {
    if (tcb->f204_b7) {
        return tcb->snd_bufsize;
    }
    return tcb->snd_bufsize - tcb->snd_count;
}
