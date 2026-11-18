/* The network stack's TCP buffer helpers (a C library, built with GC/1.2.5n): the receive queue (user reads, segment
 * input), the reassembly-range and SACK-list helpers, and the send queue (releasing acknowledged data, queueing user
 * buffers, gathering a segment's data, queueing a send request). */
#include "pso/network/NetworkRuntime.h"
#include "pso/network/UdpRuntime.h"
#include "types.h"
#include "pso/network/TLobby_804050DC.h"
#include "pso/network/BufferRef.h"
#include "pso/network/NetTcpState.h"
#include "pso/network/text_80421620.h"

void TLobby__sub_8041FDA0(TcpTcb *o, s16 idx, s32 a, s32 b);
void TLobby__sub_8041FED4(TcpTcb *tcb);
void TLobby__sub_8041F66C(TcpTcb *o);

s32 TLobby__sub_8041ED8C(TcpTcb *self, NetBufferRef *destination, u32 len, TcpCompletion callback) {
    s16 idx = self - tcp_protocol_state.tcbs;
    s32 m;
    u32 k;
    NetBufferRef src;
    NetBufferRef dst;
    if (self->rcv_user.kind != 0) {
        return -4;
    }
    if (self->f204_b6) {
        return -4;
    }
    self->recv_done = callback;
    NetMemcpy(&self->rcv_user, destination, sizeof(*destination));
    self->fEC = len;
    m = 0;
    self->fF0 = m;
    if (self->rcv_count == 0) {
        switch (self->t_state) {
        case 0:
        case 5:
        case 7:
        case 8:
        case 10:
            self->rcv_user.kind = m;
            set_slot_state_and_resume(idx, self->recv_done, -7);
            while (self->rcv_user.kind != 0) {
                self->rcv_user.kind = m;
                set_slot_state_and_resume(idx, self->recv_done, -7);
            }
            return 0;
        case -1:
            self->rcv_user.kind = m;
            set_slot_state_and_resume(idx, self->recv_done, -11);
            while (self->rcv_user.kind != 0) {
                self->rcv_user.kind = m;
                set_slot_state_and_resume(idx, self->recv_done, -11);
            }
            return 0;
        default:
            return 0;
        }
    }
    do {
        m = (s32)(self->rcv_count > self->fEC ? self->fEC : self->rcv_count);
        self->fF0 = m;
        NetMemcpy(&src, &self->rcv_buf, 8);
        netbuf_ref_advance(&src, self->rcv_head);
        NetMemcpy(&dst, &self->rcv_user, 8);
        if (self->rcv_head + m > self->rcv_bufsize) {
            k = self->rcv_bufsize - self->rcv_head;
            netbuf_copy_by_ref(&dst, &src, k);
            netbuf_ref_advance(&dst, k);
            m -= k;
            self->rcv_count -= k;
            self->rcv_head = 0;
            NetMemcpy(&src, &self->rcv_buf, 8);
        }
        netbuf_copy_by_ref(&dst, &src, m);
        self->rcv_count -= m;
        self->rcv_head += m;
        if (self->rcv_head >= self->rcv_bufsize) {
            self->rcv_head -= self->rcv_bufsize;
        }
        self->rcv_user.kind = 0;
        set_slot_state_and_resume(idx, self->recv_done, self->fF0);
    } while (self->rcv_user.kind != 0 && self->rcv_count != 0);
    if (self->f53C == 0) {
        self->flags &= ~1;
    }
    if (self->t_state != -1 && self->t_state != 0) {
        TLobby__sub_8041A9AC(self);
    }
    if (self->rcv_user.kind != 0) {
        switch (self->t_state) {
        case 0:
        case 5:
        case 7:
        case 8:
        case 10:
            set_slot_state_and_resume(idx, self->recv_done, -7);
            break;
        case -1:
            set_slot_state_and_resume(idx, self->recv_done, -11);
            break;
        default:
            return 0;
        }
    }
    if (self->rcv_count == 0 && (self->flags & 8) && !(self->flags & 0x20)) {
        NetDispatchSocketEvent((s16)(self - tcp_protocol_state.tcbs), self->event_ctx, 3, 3);
        self->flags |= 0x20;
    }
    return 0;
}

s32 TLobby__sub_8041F11C(TcpTcb *self) {
    s16 idx = self - tcp_protocol_state.tcbs;
    while (self->rcv_user.kind != 0) {
        self->rcv_user.kind = 0;
        set_slot_state_and_resume(idx, self->recv_done, -7);
    }
    if (self->rcv_count == 0 && !(self->flags & 0x20)) {
        NetDispatchSocketEvent((s16)(self - tcp_protocol_state.tcbs), self->event_ctx, 3, 3);
        self->flags |= 0x20;
    }
    return 0;
}

s32 TLobby__sub_8041F204(NetPacket *pkt, u16 x, TcpTcb *self)
{
    s16 idx;
    s16 i;
    u32 n;
    u32 rem;
    u32 len;
    u32 avail;
    u32 want;
    NetBufferRef dst;
    NetBufferRef src;

    idx = self - tcp_protocol_state.tcbs;
    if (!self->f204_b6) {
        rem = 0;
        i = 1;
        while (i < pkt->fragment_count) {
            if ((u16)pkt->fragments[i].length > x) {
                rem = x;
                break;
            }
            x -= pkt->fragments[i].length;
            i++;
        }
        if (i == pkt->fragment_count) {
            return 0;
        }
        if (self->rcv_user.kind) {
            NetMemcpy(&dst, &self->rcv_user, 8);
            while (i < pkt->fragment_count) {
                NetMemcpy(&src, &pkt->fragments[i].buffer, 8);
                if (rem != 0) {
                    netbuf_ref_advance(&src, rem);
                }
                n = (want = self->fEC) - self->fF0;
                if (n >= (len = pkt->fragments[i].length - rem)) {
                    n = len;
                    netbuf_copy_by_ref(&dst, &src, n);
                    self->fF0 += len;
                    self->rcv_head += len;
                    if (self->rcv_head >= self->rcv_bufsize) {
                        self->rcv_head -= self->rcv_bufsize;
                    }
                    self->rcv_tail += len;
                    if (self->rcv_tail >= self->rcv_bufsize) {
                        self->rcv_tail -= self->rcv_bufsize;
                    }
                    netbuf_ref_advance(&dst, n);
                    rem = 0;
                    i++;
                } else {
                    netbuf_copy_by_ref(&dst, &src, n);
                    self->fF0 += n;
                    self->rcv_head += n;
                    if (self->rcv_head >= self->rcv_bufsize) {
                        self->rcv_head -= self->rcv_bufsize;
                    }
                    self->rcv_tail += n;
                    if (self->rcv_tail >= self->rcv_bufsize) {
                        self->rcv_tail -= self->rcv_bufsize;
                    }
                    rem += n;
                }
                if (self->fEC == self->fF0) {
                    self->rcv_user.kind = 0;
                    set_slot_state_and_resume(idx, self->recv_done, (s16)self->fF0);
                    if (!self->rcv_user.kind) {
                        goto zero;
                    }
                    NetMemcpy(&dst, &self->rcv_user, 8);
                    if (i < pkt->fragment_count) {
                        continue;
                    }
                    switch (self->t_state) {
                    case 0:
                    case 5:
                    case 7:
                    case 8:
                    case 10:
                        self->rcv_user.kind = 0;
                        set_slot_state_and_resume(idx, self->recv_done, -7);
                        break;
                    }
                    goto fin;
                }
            }
            self->rcv_user.kind = 0;
            set_slot_state_and_resume(idx, self->recv_done, (s16)self->fF0);
            while (self->rcv_user.kind != 0) {
                switch (self->t_state) {
                case 0:
                case 5:
                case 7:
                case 8:
                case 10:
                    self->rcv_user.kind = 0;
                    set_slot_state_and_resume(idx, self->recv_done, -7);
                    break;
                }
                goto fin;
            }
            goto fin;
        }
zero:
        NetMemcpy(&dst, &self->rcv_buf, 8);
        netbuf_ref_advance(&dst, self->rcv_tail);
        while (i < pkt->fragment_count) {
            NetMemcpy(&src, &pkt->fragments[i].buffer, 8);
            if (rem != 0) {
                netbuf_ref_advance(&src, rem);
            }
            n = pkt->fragments[i].length - rem;
            avail = self->rcv_bufsize - self->rcv_count;
            if (n > avail) {
                n = avail;
            }
            self->rcv_count += n;
            if (self->rcv_tail + n >= self->rcv_bufsize) {
                netbuf_copy_by_ref(&dst, &src, self->rcv_bufsize - self->rcv_tail);
                NetMemcpy(&dst, &self->rcv_buf, 8);
                netbuf_ref_advance(&src, self->rcv_bufsize - self->rcv_tail);
                n -= self->rcv_bufsize - self->rcv_tail;
                self->rcv_tail = 0;
            }
            if (n != 0) {
                netbuf_copy_by_ref(&dst, &src, n);
                self->rcv_tail += n;
                netbuf_ref_advance(&dst, n);
            }
            rem = 0;
            i++;
        }
fin:
        TLobby__sub_8041F66C(self);
        return 0;
    }
    return -1;
}

void TLobby__sub_8041F66C(TcpTcb *o) {
    s16 i;
    s16 cnt;
    s16 j;
    s32 d;
    u8 unused[8];
    if (o->reasm_n == -1) {
        return;
    }
    for (i = 0; i <= o->reasm_n; i++) {
        if ((s32)(o->rcv_nxt - o->reasm[i].end) < 0) {
            break;
        }
    }
    if (i <= o->reasm_n && (s32)(o->rcv_nxt - o->reasm[i].start) >= 0) {
        d = o->reasm[i].end - o->rcv_nxt;
        o->rcv_tail += d;
        if (o->rcv_tail >= o->rcv_bufsize) {
            o->rcv_tail -= o->rcv_bufsize;
        }
        cnt = i + 1;
        o->rcv_count += d;
        o->rcv_nxt = o->reasm[i].end;
    } else {
        cnt = i;
    }
    expire_timeout_entries(o);
    if (cnt <= 0) {
        return;
    }
    o->reasm_n -= cnt;
    for (j = 0; j < cnt; j++) {
        o->reasm_total -= o->reasm[j].end - o->reasm[j].start;
    }
    for (j = 0; j <= o->reasm_n; j++) {
        o->reasm[j] = o->reasm[j + cnt];
    }
    if (o->reasm_n == -1) {
        o->last_reasm = -1;
    } else {
        o->last_reasm = 0;
    }
}

#pragma push
#pragma dont_inline off
#pragma inline_depth(4)
inline void sack_remove_8041F914(TcpTcb *o, s16 idx) {
    s16 j;
    s32 len;
    if (idx < 0 || o->reasm_n < 0 || idx > o->reasm_n) {
        return;
    }
    len = o->reasm[idx].end - o->reasm[idx].start;
    o->reasm_total -= len;
    for (j = idx; j < o->reasm_n; j++) {
        o->reasm[j] = o->reasm[j + 1];
    }
    o->reasm_n--;
}

/* Queues an out-of-order segment: copies it into the receive ring at its sequence offset and merges its range into
   the SACK/reassembly list.  Returns -1 when the connection no longer receives (f204_b6). */
s32 TLobby__sub_8041F914(NetPacket *pkt, u16 x, TcpTcb *o, TcpHdr *th) {
    if (!o->f204_b6) {
    u32 i;
    u32 skip;
    u32 n;
    u32 pos;
    s32 total;
    s32 d;
    u32 room;
    s32 seq;
    s32 end;
    s16 j;
    s32 grow;
    NetBufferRef dst;
    NetBufferRef src;
    u32 len;
    skip = 0;
    total = 0;
    d = th->seq - o->rcv_nxt;
    if (d <= 0) {
        return 0;
    }
    len = pkt->total_bytes - x;
    if (d + len > o->rcv_bufsize - o->rcv_count) {
        return 0;
    }
    for (i = 0; i < pkt->fragment_count; i++) {
        if ((u16)pkt->fragments[i].length > x) {
            skip = x;
            break;
        }
        x -= pkt->fragments[i].length;
    }
    if (i == pkt->fragment_count) {
        return 0;
    }
    pos = o->rcv_tail + d;
    if (pos > o->rcv_bufsize) {
        pos -= o->rcv_bufsize;
    }
    NetMemcpy(&dst, &o->rcv_buf, 8);
    netbuf_ref_advance(&dst, pos);
    for (; i < pkt->fragment_count; i++) {
        NetMemcpy(&src, &pkt->fragments[i].buffer, 8);
        if (skip != 0) {
            netbuf_ref_advance(&src, skip);
        }
        n = pkt->fragments[i].length - skip;
        room = o->rcv_bufsize - o->rcv_count;
        if (!o && !o) {
        }
        if (n > room) {
            n = room;
        }
        total += n;
        if (pos + n >= o->rcv_bufsize) {
            netbuf_copy_by_ref(&dst, &src, o->rcv_bufsize - pos);
            NetMemcpy(&dst, &o->rcv_buf, 8);
            netbuf_ref_advance(&src, o->rcv_bufsize - pos);
            n -= o->rcv_bufsize - pos;
        }
        if (n != 0) {
            netbuf_copy_by_ref(&dst, &src, n);
            netbuf_ref_advance(&dst, (s16)n);
        }
        skip = 0;
    }
    seq = th->seq;
    end = seq + total;
    if (o->reasm_n == -1) {
        TLobby__sub_8041FDA0(o, 0, seq, end);
        o->last_reasm = 0;
    } else {
        if (seq - o->reasm[0].start <= 0) {
            TLobby__sub_8041FDA0(o, 0, seq, end);
            j = 0;
        } else {
            for (j = 1; j <= o->reasm_n; j++) {
                if (seq - o->reasm[j].start <= 0) {
                    if (seq - o->reasm[j - 1].end <= 0) {
                        grow = end - o->reasm[j - 1].end;
                        if (grow < 0) {
                            goto done;
                        }
                        o->reasm_total += grow;
                        o->reasm[j - 1].end = end;
                        j--;
                    } else {
                        TLobby__sub_8041FDA0(o, j, seq, end);
                    }
                    break;
                }
            }
            if (j == o->reasm_n + 1) {
                if (seq - o->reasm[j - 1].end <= 0) {
                    grow = end - o->reasm[j - 1].end;
                    if (grow < 0) {
                        goto done;
                    }
                    o->reasm_total += grow;
                    o->reasm[j - 1].end = end;
                    j--;
                } else {
                    TLobby__sub_8041FDA0(o, j, seq, end);
                }
            }
        }
        o->last_reasm = j;
        while (j + 1 <= o->reasm_n && o->reasm[j].end - o->reasm[j + 1].start >= 0) {
            if (o->reasm[j].end - o->reasm[j + 1].end >= 0) {
                sack_remove_8041F914(o, j + 1);
            } else {
                o->reasm_total += o->reasm[j + 1].end - o->reasm[j].end;
                o->reasm[j].end = o->reasm[j + 1].end;
                sack_remove_8041F914(o, j + 1);
            }
        }
    }
done:
    TLobby__sub_8041FED4(o);
    return 0;
    }
    return -1;
}
#pragma pop

void TLobby__sub_8041FDA0(TcpTcb *o, s16 idx, s32 a, s32 b) {
    s16 i;
    if (idx < 0) {
        return;
    }
    if (idx > o->reasm_n + 1) {
        return;
    }
    if (idx > 0x1F) {
        return;
    }
    if (o->reasm_n >= 0x1F) {
        o->reasm_n = 0x1E;
    }
    for (i = o->reasm_n; i >= idx; i--) {
        o->reasm[i + 1] = o->reasm[i];
    }
    o->reasm[idx].start = a;
    o->reasm[idx].end = b;
    o->reasm_n++;
    o->reasm_total += b - a;
}

void expire_timeout_entries(void *tcb) {
    TcpTcb *o = (TcpTcb *)tcb;
    s16 i;
    s16 j;
    i = 0;
    while (i < 5) {
        if (o->sack[i].start == o->sack[i].end) {
            return;
        }
        if ((s32)(o->sack[i].end - o->rcv_nxt) <= 0) {
            for (j = i; j < 4; j++) {
                o->sack[j] = o->sack[j + 1];
            }
            o->sack[4].start = 0;
            o->sack[4].end = 0;
        } else {
            i++;
        }
    }
}

void TLobby__sub_8041FED4(TcpTcb *tcb) {
    u32 start;
    u32 end;
    s16 i;
    s16 j;
    s16 k;
    if (tcb->last_reasm == -1) {
        return;
    }
    start = tcb->reasm[tcb->last_reasm].start;
    end = tcb->reasm[tcb->last_reasm].end;
    for (i = 4; i > 0; i--) {
        tcb->sack[i] = tcb->sack[i - 1];
    }
    tcb->sack[0].start = start;
    tcb->sack[0].end = end;
    for (i = 4; i > 0; i--) {
        if (tcb->sack[i].start == tcb->sack[i].end) {
            continue;
        }
        for (j = i - 1; j >= 0; j--) {
            if ((s32)(tcb->sack[i].start - tcb->sack[j].start) >= 0 && (s32)(tcb->sack[i].end - tcb->sack[j].end) <= 0) {
                for (k = i; k < 5; k++) {
                    tcb->sack[k] = tcb->sack[k + 1];
                }
                tcb->sack[4].start = 0;
                tcb->sack[4].end = 0;
                break;
            }
        }
    }
}

#pragma push
#pragma opt_loop_invariants off
s32 TLobby__sub_8041FFF8(u32 len, TcpTcb *self) {
    s32 n;
    s16 idx;
    u32 rem;
    s16 j;
    NetPacketFragment *p;
    s16 i;
    NetPacketFragment *q;
    u32 k;
    TcpSendRequest rec;
    NetBufferRef a;
    u8 unused[8];
    NetBufferRef b;
    NetBufferRef d;
    idx = self - tcp_protocol_state.tcbs;
    if (self->f204_b7 == 1) {
        a.kind = 1;
        rem = len;
        b.kind = 1;
        if (rem != 0 && self->snd_count != 0) {
            set_value_and_enable(&b, (s32)&rec);
            NetMemcpy(&a, &self->snd_buf, sizeof(NetBufferRef));
            n = self->snd_head;
            if (n != 0) {
                netbuf_ref_advance(&a, n * sizeof(TcpSendRequest));
            }
            netbuf_copy_by_ref(&b, &a, sizeof(TcpSendRequest));
            while (rec.length <= rem && self->snd_count != 0) {
                self->snd_count--;
                rem -= rec.length;
                self->req.total_bytes -= rec.length;
                if (self->snd_head < 64) {
                    self->snd_head++;
                } else {
                    self->snd_head = 0;
                }
                if (self->snd_count == 0) {
                    self->snd_tail = 0;
                    self->snd_head = 0;
                    self->f204_b7 = 0;
                }
                complete_request_callback(idx, rec.callback, 0, &rec);
                /* Completion can reenter the socket and move the ring head. */
                n = self->snd_head;
                NetMemcpy(&a, &self->snd_buf, sizeof(NetBufferRef));
                if (n != 0) {
                    netbuf_ref_advance(&a, n * sizeof(TcpSendRequest));
                }
                netbuf_copy_by_ref(&b, &a, sizeof(TcpSendRequest));
            }
            if (rem != 0 && self->snd_count != 0) {
                self->req.total_bytes -= rem;
                rec.length -= (s16)rem;
                rec.offset += (s16)rem;
                netbuf_copy_by_ref(&a, &b, sizeof(TcpSendRequest));
            }
        }
        return 0;
    }
    if (len != 0) {
        if (len <= self->snd_count) {
            self->snd_count -= len;
            self->snd_head += len;
            if (self->snd_head >= self->snd_bufsize) {
                self->snd_head -= self->snd_bufsize;
            }
        } else {
            len -= self->snd_count;
            self->snd_count = 0;
            p = self->req.fragments;
            self->snd_head = self->snd_tail;
            self->req.total_bytes -= len;
            for (i = 0; i < self->req.fragment_count && len != 0; p++, i++) {
                if (len >= p->length) {
                    len -= p->length;
                    p->length = 0;
                } else {
                    p->length -= len;
                    netbuf_ref_advance(&p->buffer, len);
                    len = 0;
                }
            }
        }
    }
    if (self->req.total_bytes != 0 && self->req.total_bytes <= self->snd_bufsize - self->snd_count) {
        NetMemcpy(&d, &self->snd_buf, sizeof(NetBufferRef));
        netbuf_ref_advance(&d, self->snd_tail);
        q = self->req.fragments;
        for (j = 0; j < self->req.fragment_count; q++, j++) {
            if (q->length > 0) {
                self->snd_count += q->length;
                if (q->length > (k = self->snd_bufsize - self->snd_tail)) {
                    netbuf_copy_by_ref(&d, &q->buffer, k);
                    netbuf_ref_advance(&q->buffer, k);
                    q->length -= k;
                    self->req.total_bytes -= k;
                    self->snd_tail = 0;
                    NetMemcpy(&d, &self->snd_buf, sizeof(NetBufferRef));
                }
                k = q->length;
                netbuf_copy_by_ref(&d, &q->buffer, k);
                self->snd_tail += k;
                netbuf_ref_advance(&d, k);
                self->req.total_bytes -= k;
                q->length = 0;
            }
        }
        if (self->req.total_bytes != 0) {
            return 0;
        }
        self->req.total_bytes = 0;
        self->req.fragment_count = 0;
        set_thread_state_and_resume(idx, self->send_done, 0);
    } else if (self->req.total_bytes == 0) {
        set_thread_state_and_resume(idx, self->send_done, 0);
    }
    return 0;
}
#pragma pop

#pragma push
#pragma opt_propagation off
s32 tcp_gather_send_data(u32 off, u32 len, NetPacket *pkt, TcpTcb *tp) {
    s32 rec_idx;
    s32 shift;
    s32 first_qi;
    TcpSendRequest rec;
    u32 tail;
    NetBufferRef ring;
    u32 pos;
    s32 swap_len;
    u32 rem;
    s32 first_frag;
    s32 count;
    u16 skip;
    NetBufferRef data;
    s32 hi;
    u16 off16;
    s32 lo;
    s32 ic;
    s32 g;
    NetPacketFragment *frag;
    NetBufferRef rec_ref;
    s32 nfrag;
    s32 chunk;
    s32 qi;
    NetPacketFragment *qf;
    s32 jb;
    NetPacketFragment *itc;
    NetBufferRef tmp;
    NetPacketFragment *slot;

    if (tp->f204_b7 == 1) {
        ring.kind = 1;
        data.kind = 1;
        rec_ref.kind = 1;
        rem = len;
        if (len != 0 && tp->snd_count != 0) {
            set_value_and_enable(&rec_ref, (s32)&rec);
            rec_idx = tp->snd_head;
            NetMemcpy(&ring, &tp->snd_buf, 8);
            if (rec_idx != 0) {
                netbuf_ref_advance(&ring, rec_idx << 4);
            }
            netbuf_copy_by_ref(&rec_ref, &ring, 16);
            if (off != 0) {
                while ((u32)rec.length <= off) {
                    off -= rec.length;
                    if (rec_idx < 64) {
                        rec_idx++;
                    } else {
                        rec_idx = 0;
                    }
                    NetMemcpy(&ring, &tp->snd_buf, 8);
                    if (rec_idx != 0) {
                        netbuf_ref_advance(&ring, rec_idx << 4);
                    }
                    netbuf_copy_by_ref(&rec_ref, &ring, 16);
                }
                NetMemcpy(&data, &rec.buffer, 8);
                rec.length -= (s16)off;
                netbuf_ref_advance(&data, rec.offset);
                netbuf_ref_advance(&data, off);
            } else {
                NetMemcpy(&data, &rec.buffer, 8);
                netbuf_ref_advance(&data, rec.offset);
            }
            first_frag = pkt->fragment_count;
            while (rem != 0) {
                frag = &pkt->fragments[pkt->fragment_count];
                if (rem >= (u32)rec.length) {
                    pkt->total_bytes += frag->length = rec.length;
                    rem -= rec.length;
                } else {
                    frag->length = rem;
                    pkt->total_bytes += rem;
                    rem = 0;
                }
                NetMemcpy(&frag->buffer, &data, 8);
                pkt->fragment_count++;
                if (rem != 0) {
                    if (rec_idx < 64) {
                        rec_idx++;
                    } else {
                        rec_idx = 0;
                    }
                    NetMemcpy(&ring, &tp->snd_buf, 8);
                    if (rec_idx != 0) {
                        netbuf_ref_advance(&ring, rec_idx << 4);
                    }
                    netbuf_copy_by_ref(&rec_ref, &ring, 16);
                    NetMemcpy(&data, &rec.buffer, 8);
                }
            }
            count = pkt->fragment_count - first_frag;
            hi = (count - 2) / 2;
            lo = (count + 1) / 2;
            while (hi >= 0 && lo < count) {
                NetMemcpy(&tmp, &pkt->fragments[lo].buffer, 8);
                NetMemcpy(&pkt->fragments[lo].buffer, &pkt->fragments[hi].buffer, 8);
                NetMemcpy(&pkt->fragments[hi].buffer, &tmp, 4);
                swap_len = pkt->fragments[lo].length;
                pkt->fragments[lo].length = pkt->fragments[hi].length;
                pkt->fragments[hi].length = swap_len;
                hi--;
                lo++;
            }
            return 0;
        }
        return -1;
    }

    off16 = off;
    g = -1;
    pos = off16 + tp->snd_head;
    nfrag = 0;
    if (off >= tp->snd_count + tp->req.total_bytes) {
        return -1;
    }
    if (off < tp->snd_count) {
        if (len + off <= tp->snd_count) {
            if (tp->snd_head + off < tp->snd_bufsize) {
                if (len + (tp->snd_head + off) <= tp->snd_bufsize) {
                    pkt->fragment_count = 1;
                    NetMemcpy(&pkt->fragments[0].buffer, &tp->snd_buf, 8);
                    netbuf_ref_advance(&pkt->fragments[0].buffer, pos);
                    pkt->fragments[0].length = len;
                } else {
                    pkt->fragment_count = 2;
                    NetMemcpy(&pkt->fragments[0].buffer, &tp->snd_buf, 8);
                    NetMemcpy(&pkt->fragments[1].buffer, &tp->snd_buf, 8);
                    netbuf_ref_advance(&pkt->fragments[1].buffer, pos);
                    tail = tp->snd_bufsize - pos;
                    pkt->fragments[1].length = (u16)tail;
                    pkt->fragments[0].length = len - tail;
                }
            } else {
                pkt->fragment_count = 1;
                NetMemcpy(&pkt->fragments[0].buffer, &tp->snd_buf, 8);
                netbuf_ref_advance(&pkt->fragments[0].buffer, pos - tp->snd_bufsize);
                pkt->fragments[0].length = len;
            }
            pkt->total_bytes = len;
            return 0;
        }
        len -= tp->snd_count - off16;
    } else {
        off -= tp->snd_count;
        qf = tp->req.fragments;
        for (qi = 0; qi < tp->req.fragment_count; qi++) {
            if (off < (u32)qf->length) {
                pkt->fragment_count = 1;
                first_qi = qi;
                skip = off;
                NetMemcpy(&pkt->fragments[0].buffer, &qf->buffer, 8);
                netbuf_ref_advance(&pkt->fragments[0].buffer, skip);
                pkt->total_bytes = len;
                pkt->fragments[0].length = len;
                if (len + off <= (u32)qf->length) {
                    pkt->total_bytes = len;
                    pkt->fragments[0].length = len;
                    return 0;
                }
                chunk = qf->length - skip;
                pkt->total_bytes = chunk;
                pkt->fragments[0].length = chunk;
                for (qi++; qi < tp->req.fragment_count; qi++) {
                    shift = qi - first_qi;
                    jb = shift;
                    hi = shift - 1;
                    while (jb > 0) {
                        NetMemcpy(&pkt->fragments[jb].buffer, &pkt->fragments[hi].buffer, 8);
                        pkt->fragments[jb].length = pkt->fragments[hi].length;
                        jb--;
                        hi--;
                    }
                    pkt->fragment_count++;
                    qf++;
                    len -= chunk;
                    NetMemcpy(&pkt->fragments[0].buffer, &qf->buffer, 8);
                    if ((s32)len <= qf->length) {
                        pkt->fragments[0].length = len;
                        pkt->total_bytes += len;
                        return 0;
                    }
                    pkt->fragments[0].length = qf->length;
                    pkt->total_bytes += qf->length;
                    chunk = qf->length;
                }
                pkt->total_bytes = 0;
                pkt->fragments[0].length = 0;
                pkt->fragments[1].length = 0;
                break;
            }
            off -= qf->length;
            qf++;
        }
        return 0;
    }

    ic = 0;
    itc = &tp->req.fragments[ic];
    for (; ic < tp->req.fragment_count; ic++) {
        if (len <= (u32)itc->length) {
            pkt->fragment_count = 1;
            NetMemcpy(&pkt->fragments[0].buffer, &itc->buffer, 8);
            pkt->total_bytes = len;
            pkt->fragments[0].length = len;
            nfrag = 1;
            break;
        }
        len -= itc->length;
        itc++;
    }
    itc--;
    ic--;
    while (ic > -1) {
        pkt->fragment_count++;
        NetMemcpy(&pkt->fragments[nfrag].buffer, &itc->buffer, 8);
        pkt->total_bytes += pkt->fragments[nfrag].length = itc->length;
        nfrag++;
        itc--;
        ic--;
    }
    slot = &pkt->fragments[nfrag];
    if (g < 0) {
        pos = off16 + tp->snd_head;
        if (pos < tp->snd_bufsize) {
            if (tp->snd_head + tp->snd_count <= tp->snd_bufsize) {
                pkt->fragment_count++;
                NetMemcpy(&slot->buffer, &tp->snd_buf, 8);
                netbuf_ref_advance(&slot->buffer, pos);
                slot->length = tp->snd_count - off16;
            } else {
                pkt->fragment_count += 2;
                NetMemcpy(&slot->buffer, &tp->snd_buf, 8);
                NetMemcpy(&slot[1].buffer, &tp->snd_buf, 8);
                netbuf_ref_advance(&slot[1].buffer, pos);
                slot->length = tp->snd_count - off16 - (slot[1].length = tp->snd_bufsize - pos);
            }
        } else {
            pkt->fragment_count++;
            NetMemcpy(&slot->buffer, &tp->snd_buf, 8);
            netbuf_ref_advance(&slot->buffer, pos - tp->snd_bufsize);
            slot->length = tp->snd_count - off16;
        }
        pkt->total_bytes += tp->snd_count - off16;
    } else {
        pkt->fragment_count++;
        NetMemcpy(&slot->buffer, &tp->req.fragments[g].buffer, 4);
        netbuf_ref_advance(&slot->buffer, off16);
        pkt->total_bytes += slot->length = tp->req.in_use - off16;
    }
    return 0;
}
#pragma pop
s32 TLobby__sub_80420BD0(NetPacket *req, TcpTcb *s, TcpCompletion done) {
    u32 v;
    if (s->f204_b7 == 1) {
        /* The inner test repeats the outer one, so the else never runs. */
        if (s->f204_b7) {
            v = s->req.total_bytes;
        } else {
            v = s->snd_count + s->req.total_bytes;
        }
        if (v != 0) {
            return -1;
        }
    }
    s->send_done = done;
    NetMemcpy(&s->req, req, sizeof(NetPacket));
    s->f204_b7 = 0;
    return 0;
}
