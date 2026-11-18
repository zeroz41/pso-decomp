/* The network stack's TCP buffer helpers (a C library, built with GC/1.2.5n): the receive queue (user reads, segment
 * input), the reassembly-range and SACK-list helpers, and the send queue (releasing acknowledged data, queueing user
 * buffers, gathering a segment's data, queueing a send request). */
#include "pso/network/NetworkRuntime.h"
#include "types.h"
#include "pso/network/TLobby_804050DC.h"
#include "pso/network/BufferRef.h"
#include "pso/network/NetTcpState.h"
#include "pso/network/text_80421620.h"

void TLobby__sub_8041FDA0(TcpTcb *o, s16 idx, u32 start, u32 end);
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

#pragma push
#pragma dont_inline off
#pragma inline_depth(4)
static inline u32 reassembly_length(const TcpSeqRange *range) {
    return range->end - range->start;
}

void TLobby__sub_8041F66C(TcpTcb *o) {
    s16 i;
    s16 cnt;
    s16 j;
    s32 d;
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
        o->reasm_total -= reassembly_length(&o->reasm[j]);
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

inline void sack_remove_8041F914(TcpTcb *o, s16 idx) {
    s16 j;
    if (idx < 0 || o->reasm_n < 0 || idx > o->reasm_n) {
        return;
    }
    o->reasm_total -= reassembly_length(&o->reasm[idx]);
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
    u32 seq;
    u32 end;
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
        if ((n = pkt->fragments[i].length - skip) > o->rcv_bufsize - o->rcv_count) {
            n = o->rcv_bufsize - o->rcv_count;
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
        if ((s32)(seq - o->reasm[0].start) <= 0) {
            TLobby__sub_8041FDA0(o, 0, seq, end);
            j = 0;
        } else {
            for (j = 1; j <= o->reasm_n; j++) {
                if ((s32)(seq - o->reasm[j].start) <= 0) {
                    if ((s32)(seq - o->reasm[j - 1].end) <= 0) {
                        grow = (s32)(end - o->reasm[j - 1].end);
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
                if ((s32)(seq - o->reasm[j - 1].end) <= 0) {
                    grow = (s32)(end - o->reasm[j - 1].end);
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
        while (j + 1 <= o->reasm_n && (s32)(o->reasm[j].end - o->reasm[j + 1].start) >= 0) {
            if ((s32)(o->reasm[j].end - o->reasm[j + 1].end) >= 0) {
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

void TLobby__sub_8041FDA0(TcpTcb *o, s16 idx, u32 start, u32 end) {
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
    o->reasm[idx].start = start;
    o->reasm[idx].end = end;
    o->reasm_n++;
    o->reasm_total += end - start;
}

void expire_timeout_entries(TcpTcb *o) {
    const s16 count = sizeof(o->sack) / sizeof(o->sack[0]);
    s16 i;
    s16 j;
    i = 0;
    while (i < count) {
        if (o->sack[i].start == o->sack[i].end) {
            return;
        }
        if ((s32)(o->sack[i].end - o->rcv_nxt) <= 0) {
            for (j = i; j < count - 1; j++) {
                o->sack[j] = o->sack[j + 1];
            }
            o->sack[count - 1].start = 0;
            o->sack[count - 1].end = 0;
        } else {
            i++;
        }
    }
}

void TLobby__sub_8041FED4(TcpTcb *tcb) {
    const s16 last = sizeof(tcb->sack) / sizeof(tcb->sack[0]) - 1;
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
    for (i = last; i > 0; i--) {
        tcb->sack[i] = tcb->sack[i - 1];
    }
    tcb->sack[0].start = start;
    tcb->sack[0].end = end;
    for (i = last; i > 0; i--) {
        if (tcb->sack[i].start == tcb->sack[i].end) {
            continue;
        }
        for (j = i - 1; j >= 0; j--) {
            if ((s32)(tcb->sack[i].start - tcb->sack[j].start) >= 0 && (s32)(tcb->sack[i].end - tcb->sack[j].end) <= 0) {
#if defined(__MWERKS__) && !defined(PSO_SOCKET_BOUNDED_SACK)
                /* Retail runs one extra iteration before clearing the final slot. */
                for (k = i; k < last + 1; k++) {
#else
                for (k = i; k < last; k++) {
#endif
                    tcb->sack[k] = tcb->sack[k + 1];
                }
                tcb->sack[last].start = 0;
                tcb->sack[last].end = 0;
                break;
            }
        }
    }
}

#pragma push
#pragma dont_inline on
#pragma opt_lifetimes off
s32 TLobby__sub_8041FFF8(u32 acknowledged, TcpTcb *control) {
    struct SendRingPosition { s32 read_index; } ring;
    TcpSendRequest request;
    NetBufferRef cursor;
    struct Acknowledgement {
        s16 handle;
        u32 remaining;
    } ack;
    NetBufferRef request_ref;
    NetBufferRef destination;
    s16 fragment_index;
    NetPacketFragment *copy_fragment;
    u32 available;
    NetPacketFragment *ack_fragment;
    s16 length;

    ack.handle = control - tcp_protocol_state.tcbs;
    if ((u32)control->f204_b7 == 1) {
        cursor.kind = 1;
        ack.remaining = acknowledged;
        request_ref.kind = 1;
        if (acknowledged != 0 && control->snd_count != 0) {
            set_value_and_enable(&request_ref, (s32)&request);
            NetMemcpy(&cursor, &control->snd_buf, 8);
            if ((s32)control->snd_head != 0) {
                netbuf_ref_advance(&cursor, control->snd_head * sizeof(request));
            }
            netbuf_copy_by_ref(&request_ref, &cursor, sizeof(request));
            while (request.length <= ack.remaining && control->snd_count != 0) {
                control->snd_count--;
                ack.remaining -= request.length;
                control->req.total_bytes -= request.length;
                if ((u32)control->snd_head < 64) {
                    control->snd_head++;
                } else {
                    control->snd_head = 0;
                }
                if (control->snd_count == 0) {
                    control->snd_tail = 0;
                    control->snd_head = 0;
                    control->f204_b7 = 0;
                }
                complete_request_callback(ack.handle, request.callback, 0, &request);
                // Completion can reenter the socket and move the head of its send queue.
                ring.read_index = control->snd_head;
                NetMemcpy(&cursor, &control->snd_buf, 8);
                if ((s32)ring.read_index != 0) {
                    netbuf_ref_advance(&cursor, ring.read_index * sizeof(request));
                }
                netbuf_copy_by_ref(&request_ref, &cursor, sizeof(request));
            }
            if (ack.remaining != 0 && control->snd_count != 0) {
                control->req.total_bytes -= ack.remaining;
                length = ack.remaining;
                request.length -= length;
                request.offset += length;
                netbuf_copy_by_ref(&cursor, &request_ref, sizeof(request));
            }
        }
        return 0;
    }
    if (acknowledged != 0) {
        if (acknowledged <= control->snd_count) {
            control->snd_count -= acknowledged;
            control->snd_head += acknowledged;
            if ((u32)control->snd_head >= control->snd_bufsize) {
                control->snd_head -= control->snd_bufsize;
            }
        } else {
            acknowledged = acknowledged - control->snd_count;
            control->snd_count = 0;
            control->snd_head = control->snd_tail;
            control->req.total_bytes -= acknowledged;
            ack_fragment = control->req.fragments;
            for (fragment_index = 0; (u32)fragment_index < (u32)control->req.fragment_count && acknowledged != 0; ++fragment_index) {
                if (acknowledged >= ack_fragment->length) {
                    acknowledged -= ack_fragment->length;
                    ack_fragment->length = 0;
                } else {
                    ack_fragment->length -= acknowledged;
                    netbuf_ref_advance(&ack_fragment->buffer, acknowledged);
                    acknowledged = 0;
                }
                ack_fragment++;
            }
        }
    }
    if (control->req.total_bytes != 0 && control->req.total_bytes <= control->snd_bufsize - control->snd_count) {
        NetMemcpy(&destination, &control->snd_buf, sizeof(destination));
        netbuf_ref_advance(&destination, control->snd_tail);
        for (fragment_index = 0, copy_fragment = control->req.fragments; (u32)fragment_index < (u32)control->req.fragment_count; fragment_index++) {
            if (copy_fragment->length > 0) {
                control->snd_count += copy_fragment->length;
                if (copy_fragment->length > (available = control->snd_bufsize - control->snd_tail)) {
                    netbuf_copy_by_ref(&destination, &copy_fragment->buffer, available);
                    netbuf_ref_advance(&copy_fragment->buffer, available);
                    copy_fragment->length -= available;
                    control->req.total_bytes -= available;
                    control->snd_tail = 0;
                    NetMemcpy(&destination, &control->snd_buf, sizeof(destination));
                }
                length = copy_fragment->length;
                netbuf_copy_by_ref(&destination, &copy_fragment->buffer, length);
                control->snd_tail += length;
                netbuf_ref_advance(&destination, length);
                control->req.total_bytes -= length;
                copy_fragment->length = 0;
            }
            copy_fragment++;
        }
        if (control->req.total_bytes != 0) {
            return 0;
        }
        control->req.total_bytes = 0;
        control->req.fragment_count = 0;
        set_thread_state_and_resume(ack.handle, control->send_done, 0);
    } else if (control->req.total_bytes == 0) {
        set_thread_state_and_resume(ack.handle, control->send_done, 0);
    }
    return 0;
}
#pragma pop

#pragma push
#pragma opt_propagation off
s32 tcp_gather_send_data(u32 offset, u32 length, NetPacket *packet, TcpTcb *control) {
    s32 ring_index;
    s32 shift_count;
    TcpSendRequest request;
    u32 bytes_to_end;
    NetBufferRef ring_cursor;
    u32 ring_position;
    s32 swapped_length;
    u32 remaining;
    s32 first_fragment;
    s32 appended_count;
    u16 skip_in_fragment;
    NetBufferRef buffer_cursor;
    s32 left_index;
    u16 ring_offset;
    s32 right_index;
    s32 partial_fragment;
    NetPacketFragment *output_fragment;
    NetBufferRef request_ref;
    s32 output_count;
    s32 fragment_length;
    s32 request_index;
    NetPacketFragment *queued_fragment;
    s32 destination_index;
    NetPacketFragment *source_end;
    NetBufferRef swap_buffer;
    NetPacketFragment *output_tail;

    if (control->f204_b7 == 1) {
        ring_cursor.kind = 1;
        buffer_cursor.kind = 1;
        request_ref.kind = 1;
        remaining = length;
        if (length != 0 && control->snd_count != 0) {
            set_value_and_enable(&request_ref, (s32)&request);
            ring_index = control->snd_head;
            NetMemcpy(&ring_cursor, &control->snd_buf, sizeof(NetBufferRef));
            if (ring_index != 0) {
                netbuf_ref_advance(&ring_cursor, ring_index * sizeof(TcpSendRequest));
            }
            netbuf_copy_by_ref(&request_ref, &ring_cursor, sizeof(request));
            if (offset != 0) {
                while ((u32)request.length <= offset) {
                    offset -= request.length;
                    if (ring_index < 64) {
                        ring_index++;
                    } else {
                        ring_index = 0;
                    }
                    NetMemcpy(&ring_cursor, &control->snd_buf, sizeof(NetBufferRef));
                    if (ring_index != 0) {
                        netbuf_ref_advance(&ring_cursor, ring_index * sizeof(TcpSendRequest));
                    }
                    netbuf_copy_by_ref(&request_ref, &ring_cursor, sizeof(request));
                }
                NetMemcpy(&buffer_cursor, &request.buffer, sizeof(NetBufferRef));
                request.length -= (s16)offset;
                netbuf_ref_advance(&buffer_cursor, request.offset);
                netbuf_ref_advance(&buffer_cursor, offset);
            } else {
                NetMemcpy(&buffer_cursor, &request.buffer, sizeof(NetBufferRef));
                netbuf_ref_advance(&buffer_cursor, request.offset);
            }
            first_fragment = packet->fragment_count;
            while (remaining != 0) {
                output_fragment = &packet->fragments[packet->fragment_count];
                if (remaining >= (u32)request.length) {
                    packet->total_bytes += output_fragment->length = request.length;
                    remaining -= request.length;
                } else {
                    output_fragment->length = remaining;
                    packet->total_bytes += remaining;
                    remaining = 0;
                }
                NetMemcpy(&output_fragment->buffer, &buffer_cursor, sizeof(NetBufferRef));
                packet->fragment_count++;
                if (remaining != 0) {
                    if (ring_index < 64) {
                        ring_index++;
                    } else {
                        ring_index = 0;
                    }
                    NetMemcpy(&ring_cursor, &control->snd_buf, sizeof(NetBufferRef));
                    if (ring_index != 0) {
                        netbuf_ref_advance(&ring_cursor, ring_index * sizeof(TcpSendRequest));
                    }
                    netbuf_copy_by_ref(&request_ref, &ring_cursor, sizeof(request));
                    NetMemcpy(&buffer_cursor, &request.buffer, sizeof(NetBufferRef));
                }
            }
            appended_count = packet->fragment_count - first_fragment;
            left_index = (appended_count - 2) / 2;
            right_index = (appended_count + 1) / 2;
            // The reverse copy restores only the value word of the left descriptor.
            while (left_index >= 0 && right_index < appended_count) {
                NetMemcpy(&swap_buffer, &packet->fragments[right_index].buffer, sizeof(NetBufferRef));
                NetMemcpy(&packet->fragments[right_index].buffer, &packet->fragments[left_index].buffer, sizeof(NetBufferRef));
                NetMemcpy(&packet->fragments[left_index].buffer.value, &swap_buffer.value, sizeof(swap_buffer.value));
                swapped_length = packet->fragments[right_index].length;
                packet->fragments[right_index].length = packet->fragments[left_index].length;
                packet->fragments[left_index].length = swapped_length;
                left_index--;
                right_index++;
            }
            return 0;
        }
        return -1;
    }

    ring_offset = offset;
    partial_fragment = -1;
    ring_position = ring_offset + control->snd_head;
    output_count = 0;
    if (offset >= control->snd_count + control->req.total_bytes) {
        return -1;
    }
    if (offset < control->snd_count) {
        if (length + offset <= control->snd_count) {
            if (control->snd_head + offset < control->snd_bufsize) {
                if (length + (control->snd_head + offset) <= control->snd_bufsize) {
                    packet->fragment_count = 1;
                    NetMemcpy(&packet->fragments[0].buffer, &control->snd_buf, sizeof(NetBufferRef));
                    netbuf_ref_advance(&packet->fragments[0].buffer, ring_position);
                    packet->fragments[0].length = length;
                } else {
                    packet->fragment_count = 2;
                    NetMemcpy(&packet->fragments[0].buffer, &control->snd_buf, sizeof(NetBufferRef));
                    NetMemcpy(&packet->fragments[1].buffer, &control->snd_buf, sizeof(NetBufferRef));
                    netbuf_ref_advance(&packet->fragments[1].buffer, ring_position);
                    bytes_to_end = control->snd_bufsize - ring_position;
                    packet->fragments[1].length = (u16)bytes_to_end;
                    packet->fragments[0].length = length - bytes_to_end;
                }
            } else {
                packet->fragment_count = 1;
                NetMemcpy(&packet->fragments[0].buffer, &control->snd_buf, sizeof(NetBufferRef));
                netbuf_ref_advance(&packet->fragments[0].buffer, ring_position - control->snd_bufsize);
                packet->fragments[0].length = length;
            }
            packet->total_bytes = length;
            return 0;
        }
        length -= control->snd_count - ring_offset;
    } else {
        offset -= control->snd_count;
        queued_fragment = control->req.fragments;
        for (request_index = 0; request_index < (u32)control->req.fragment_count; request_index++) {
            if (offset < (u32)queued_fragment->length) {
                packet->fragment_count = 1;
                partial_fragment = request_index;
                skip_in_fragment = offset;
                NetMemcpy(&packet->fragments[0].buffer, &queued_fragment->buffer, sizeof(NetBufferRef));
                netbuf_ref_advance(&packet->fragments[0].buffer, skip_in_fragment);
                packet->total_bytes = length;
                packet->fragments[0].length = length;
                if (length + offset <= (u32)queued_fragment->length) {
                    packet->total_bytes = length;
                    packet->fragments[0].length = length;
                    return 0;
                }
                fragment_length = queued_fragment->length - skip_in_fragment;
                packet->total_bytes = fragment_length;
                packet->fragments[0].length = fragment_length;
                for (request_index++; request_index < (u32)control->req.fragment_count; request_index++) {
                    shift_count = request_index - partial_fragment;
                    destination_index = shift_count;
                    left_index = shift_count - 1;
                    while (destination_index > 0) {
                        NetMemcpy(&packet->fragments[destination_index].buffer, &packet->fragments[left_index].buffer, sizeof(NetBufferRef));
                        packet->fragments[destination_index].length = packet->fragments[left_index].length;
                        destination_index--;
                        left_index--;
                    }
                    packet->fragment_count++;
                    queued_fragment++;
                    length -= fragment_length;
                    NetMemcpy(&packet->fragments[0].buffer, &queued_fragment->buffer, sizeof(NetBufferRef));
                    if ((s32)length <= queued_fragment->length) {
                        packet->fragments[0].length = length;
                        packet->total_bytes += length;
                        return 0;
                    }
                    packet->fragments[0].length = queued_fragment->length;
                    packet->total_bytes += queued_fragment->length;
                    fragment_length = queued_fragment->length;
                }
                packet->total_bytes = 0;
                packet->fragments[0].length = 0;
                packet->fragments[1].length = 0;
                break;
            }
            offset -= queued_fragment->length;
            queued_fragment++;
        }
        return 0;
    }

    request_index = 0;
    source_end = &control->req.fragments[request_index];
    for (; request_index < (u32)control->req.fragment_count; request_index++) {
        if (length <= (u32)source_end->length) {
            packet->fragment_count = 1;
            NetMemcpy(&packet->fragments[0].buffer, &source_end->buffer, sizeof(NetBufferRef));
            packet->total_bytes = length;
            packet->fragments[0].length = length;
            output_count = 1;
            break;
        }
        length -= source_end->length;
        source_end++;
    }
#if defined(__MWERKS__) && !defined(PSO_SOCKET_BOUNDED_GATHER)
    /* The matching loop pre-decrements its cursor even when the prefix is empty. */
    source_end--;
#endif
    request_index--;
    while (request_index > -1) {
#if !defined(__MWERKS__) || defined(PSO_SOCKET_BOUNDED_GATHER)
        source_end = &control->req.fragments[request_index];
#endif
        packet->fragment_count++;
        NetMemcpy(&packet->fragments[output_count].buffer, &source_end->buffer, sizeof(NetBufferRef));
        packet->total_bytes += packet->fragments[output_count].length = source_end->length;
        output_count++;
#if defined(__MWERKS__) && !defined(PSO_SOCKET_BOUNDED_GATHER)
        source_end--;
#endif
        request_index--;
    }
    output_tail = &packet->fragments[output_count];
    if (partial_fragment < 0) {
        ring_position = ring_offset + control->snd_head;
        if (ring_position < control->snd_bufsize) {
            if (control->snd_head + control->snd_count <= control->snd_bufsize) {
                packet->fragment_count++;
                NetMemcpy(&output_tail->buffer, &control->snd_buf, 8);
                netbuf_ref_advance(&output_tail->buffer, ring_position);
                output_tail->length = control->snd_count - ring_offset;
            } else {
                packet->fragment_count += 2;
                NetMemcpy(&output_tail->buffer, &control->snd_buf, 8);
                NetMemcpy(&output_tail[1].buffer, &control->snd_buf, 8);
                netbuf_ref_advance(&output_tail[1].buffer, ring_position);
                output_tail->length = control->snd_count - ring_offset - (output_tail[1].length = control->snd_bufsize - ring_position);
            }
        } else {
            packet->fragment_count++;
            NetMemcpy(&output_tail->buffer, &control->snd_buf, 8);
            netbuf_ref_advance(&output_tail->buffer, ring_position - control->snd_bufsize);
            output_tail->length = control->snd_count - ring_offset;
        }
        packet->total_bytes += control->snd_count - ring_offset;
    } else {
        // Unreachable in retail: every path here has partial_fragment == -1.
        u16 partial_length;
        u32 partial_total;
        packet->fragment_count++;
        NetMemcpy(&output_tail->buffer, &control->req.fragments[partial_fragment].buffer, 4);
        netbuf_ref_advance(&output_tail->buffer, ring_offset);
        partial_length = control->req.in_use - ring_offset;
        partial_total = packet->total_bytes;
        output_tail->length = (u16)partial_length;
        packet->total_bytes = partial_total + (s16)partial_length;
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
