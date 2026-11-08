/* The network stack's UDP layer and TCP receive helpers (a C library, built with GC/1.2.5n): UDP control blocks
 * (create, bind, connect, close, input, sendto, ephemeral ports) and the TCP receive-queue, reassembly-range and
 * SACK-list helpers. */
#include "pso/network/NetworkRuntime.h"
#include "pso/network/UdpRuntime.h"
#include "types.h"
#include "pso/network/BufferRef.h"
#include "pso/network/NetTcpState.h"
#include "pso/network/text_80421620.h"

typedef struct Hdr_80420DE4 { u16 src; u16 dst; u16 len; u16 sum; } Hdr_80420DE4;

typedef struct O_80420DE4 { u8 pad0[8]; s32 f8; u8 padC[0xC]; s16 f18; u8 pad1A[2]; u8 f1C[4]; } O_80420DE4;

/* An entry of a TCB's send ring while f204_b7 is set: a queued user buffer and its completion callback. */
typedef struct TcpSendEntry {
    NetBufferRef ref;
    s16 len;
    s16 off;
    void (*done)(s16, s16, s32);
} TcpSendEntry;
typedef char TcpSendEntry_size_check[sizeof(TcpSendEntry) == 0x10 ? 1 : -1];

void set_value_and_enable(void *self, s32 value);

void TLobby__sub_803F87C8(u8 *arg0);
s32 TLobby__sub_803F87C4(void *);
void TLobby__sub_8041FDA0(TcpTcb *o, s16 idx, s32 a, s32 b);
void TLobby__sub_8041FED4(TcpTcb *tcb);
s32 TLobby__sub_80420D38(u16 arg0, u8 arg1);
s16 dispatch_by_addr_family(void *, void *, void *, s32, s32, int);
s16 TLobby__sub_8040D8F0(void *, void *, int, void *, int);
s16 select_source_address(void *, void *);
s16 TLobby__sub_8040DA54(void *, void *);
s16 is_addr_unspecified(void *);
s16 udp_sendto(s16 id, NetPacket *pkt, NetworkAddress *src, NetworkAddress *dst, u16 port, s32 arg5);
void TLobby__sub_8041F66C(TcpTcb *o);
void TLobby__sub_80406FD8(void *a, void *b, s32 v);
s16 compare_sockaddr(void *, void *);
s16 is_multicast_address(void *, s32);
s16 TLobby__sub_80421F10(void *, void *, void *, u16, s32, s16);
s32 udp_input(O_80420DE4 *arg0, NetworkAddress *src, NetworkAddress *dst, s32 arg3);
UdpRuntimeState udp_runtime_state;

s32 TLobby__sub_8041ED8C(TcpTcb *self, void *data, u32 len, s32 arg3) {
    s32 set_slot_state_and_resume(s16 idx, void (*cb)(s16, s16), s16 state); /* declared here with an s16 index; the definition takes s32 */
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
    self->recv_done = (void (*)(s16, s16))arg3;
    NetMemcpy(&self->rcv_user, data, 8);
    self->fEC = len;
    m = 0;
    self->fF0 = m;
    if (self->fD8 == 0) {
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
        m = (s32)(self->fD8 > self->fEC ? self->fEC : self->fD8);
        self->fF0 = m;
        NetMemcpy(&src, &self->rcv_buf, 8);
        TLobby__sub_80406EB8(&src, self->fDC);
        NetMemcpy(&dst, &self->rcv_user, 8);
        if (self->fDC + m > self->f534) {
            k = self->f534 - self->fDC;
            TLobby__sub_80406FD8(&dst, &src, k);
            TLobby__sub_80406EB8(&dst, k);
            m -= k;
            self->fD8 -= k;
            self->fDC = 0;
            NetMemcpy(&src, &self->rcv_buf, 8);
        }
        TLobby__sub_80406FD8(&dst, &src, m);
        self->fD8 -= m;
        self->fDC += m;
        if (self->fDC >= self->f534) {
            self->fDC -= self->f534;
        }
        self->rcv_user.kind = 0;
        set_slot_state_and_resume(idx, self->recv_done, self->fF0);
    } while (self->rcv_user.kind != 0 && self->fD8 != 0);
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
    if (self->fD8 == 0 && (self->flags & 8) && !(self->flags & 0x20)) {
        NetDispatchSocketEvent((s16)(self - tcp_protocol_state.tcbs), self->event_ctx, 3, 3);
        self->flags |= 0x20;
    }
    return 0;
}

s32 TLobby__sub_8041F11C(TcpTcb *self) {
    s32 set_slot_state_and_resume(s16 idx, void (*cb)(s16, s16), s16 state); /* declared here with an s16 index; the definition takes s32 */
    s16 idx = self - tcp_protocol_state.tcbs;
    while (self->rcv_user.kind != 0) {
        self->rcv_user.kind = 0;
        set_slot_state_and_resume(idx, self->recv_done, -7);
    }
    if (self->fD8 == 0 && !(self->flags & 0x20)) {
        NetDispatchSocketEvent((s16)(self - tcp_protocol_state.tcbs), self->event_ctx, 3, 3);
        self->flags |= 0x20;
    }
    return 0;
}

s32 TLobby__sub_8041F204(NetPacket *pkt, u16 x, TcpTcb *self)
{
    s32 set_slot_state_and_resume(s16 idx, void (*cb)(s16, s16), s16 state); /* declared here with an s16 index; the definition takes s32 */
    s16 idx;
    s16 i;
    u32 n;
    u32 rem;
    u32 n2;
    u32 avail;
    u32 cnt;
    u8 *p; /* (u8 *)pkt + i * sizeof(NetPacketFragment), so fragments[i] is at p + offsetof(NetPacket, fragments) */
    u8 buf1c[8];
    u8 buf14[8];

    idx = (s16)(self - tcp_protocol_state.tcbs);
    if (!self->f204_b6) {
        cnt = pkt->fragment_count;
        p = (u8 *)pkt + sizeof(NetPacketFragment);
        rem = 0;
        i = 1;
        while (i < cnt) {
            if ((u16)*(s16 *)(p + offsetof(NetPacket, fragments[0].length)) > (u16)x) {
                rem = x;
                break;
            }
            x -= *(s16 *)(p + offsetof(NetPacket, fragments[0].length));
            p += sizeof(NetPacketFragment);
            i++;
        }
        if (i == cnt) {
            return 0;
        }
        if (self->rcv_user.kind) {
            NetMemcpy(buf1c, &self->rcv_user, 8);
            p = (u8 *)pkt + (s16)i * sizeof(NetPacketFragment);
            while (i < pkt->fragment_count) {
                NetMemcpy(buf14, p + offsetof(NetPacket, fragments[0].buffer), 8);
                if (rem != 0) {
                    TLobby__sub_80406EB8((NetBufferRef *)buf14, rem);
                }
                n2 = *(s16 *)(p + offsetof(NetPacket, fragments[0].length));
                n2 -= rem;
                n = self->fEC;
                n -= self->fF0;
                if (n >= n2) {
                    n = n2;
                    TLobby__sub_80406FD8(buf1c, buf14, n);
                    self->fF0 += n2;
                    self->fDC += n2;
                    if (self->fDC >= self->f534) {
                        self->fDC -= self->f534;
                    }
                    self->fE0 += n2;
                    if (self->fE0 >= self->f534) {
                        self->fE0 -= self->f534;
                    }
                    TLobby__sub_80406EB8((NetBufferRef *)buf1c, n);
                    rem = 0;
                    p += sizeof(NetPacketFragment);
                    i++;
                } else {
                    TLobby__sub_80406FD8(buf1c, buf14, n);
                    self->fF0 += n;
                    self->fDC += n;
                    if (self->fDC >= self->f534) {
                        self->fDC -= self->f534;
                    }
                    self->fE0 += n;
                    if (self->fE0 >= self->f534) {
                        self->fE0 -= self->f534;
                    }
                    rem += n;
                }
                if (self->fEC == self->fF0) {
                    self->rcv_user.kind = 0;
                    set_slot_state_and_resume(idx, self->recv_done, (s16)self->fF0);
                    if (!self->rcv_user.kind) {
                        goto zero;
                    }
                    NetMemcpy(buf1c, &self->rcv_user, 8);
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
        NetMemcpy(buf1c, &self->rcv_buf, 8);
        TLobby__sub_80406EB8((NetBufferRef *)buf1c, self->fE0);
        p = (u8 *)pkt + (s16)i * sizeof(NetPacketFragment);
        while (i < pkt->fragment_count) {
            NetMemcpy(buf14, p + offsetof(NetPacket, fragments[0].buffer), 8);
            if (rem != 0) {
                TLobby__sub_80406EB8((NetBufferRef *)buf14, rem);
            }
            n = *(s16 *)(p + offsetof(NetPacket, fragments[0].length)) - rem;
            avail = self->f534 - self->fD8;
            if (n > avail) {
                n = avail;
            }
            self->fD8 += n;
            if (self->fE0 + n >= self->f534) {
                TLobby__sub_80406FD8(buf1c, buf14, self->f534 - self->fE0);
                NetMemcpy(buf1c, &self->rcv_buf, 8);
                TLobby__sub_80406EB8((NetBufferRef *)buf14, self->f534 - self->fE0);
                n -= self->f534 - self->fE0;
                self->fE0 = 0;
            }
            if (n != 0) {
                TLobby__sub_80406FD8(buf1c, buf14, n);
                self->fE0 += n;
                TLobby__sub_80406EB8((NetBufferRef *)buf1c, n);
            }
            rem = 0;
            p += sizeof(NetPacketFragment);
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
        o->fE0 += d;
        if (o->fE0 >= o->f534) {
            o->fE0 -= o->f534;
        }
        cnt = i + 1;
        o->fD8 += d;
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

inline void sack_remove_8041F914(TcpTcb *o, s16 idx) {
    s16 nn = o->reasm_n;
    s16 j;
    if (idx < 0 || nn < 0 || idx > nn) {
        return;
    }
    o->reasm_total -= o->reasm[idx].end - o->reasm[idx].start;
    for (j = idx; j < o->reasm_n; j++) {
        o->reasm[j] = o->reasm[j + 1];
    }
    o->reasm_n--;
}

s32 TLobby__sub_8041F914(NetPacket *pkt, u16 x, TcpTcb *o, TcpHdr *th) {
    u8 *p; /* (u8 *)pkt + i * sizeof(NetPacketFragment), so fragments[i] is at p + offsetof(NetPacket, fragments) */
    u32 cnt;
    s32 n;
    s16 kk;
    u32 rem;
    u32 k;
    s32 sum;
    s32 delta;
    s32 s;
    u32 i;
    u8 buf1[8];
    u8 buf2[8];

    if (!o->f204_b6) {
        rem = 0;
        sum = 0;
        delta = th->seq - o->rcv_nxt;
        if (delta <= 0) {
            return 0;
        }
        if ((u32)(pkt->total_bytes - x + delta) > (u32)(o->f534 - o->fD8)) {
            return 0;
        }
        cnt = pkt->fragment_count;
        i = 0;
        p = (u8 *)pkt;
        for (; i < cnt; p += sizeof(NetPacketFragment), i++) {
            if ((u16)*(s16 *)(p + offsetof(NetPacket, fragments[0].length)) > (u16)x) {
                rem = (u16)x;
                break;
            }
            x -= *(s16 *)(p + offsetof(NetPacket, fragments[0].length));
        }
        if (i == cnt) {
            return 0;
        }
        k = o->fE0 + delta;
        if (k > o->f534) {
            k -= o->f534;
        }
        NetMemcpy(buf1, &o->rcv_buf, 8);
        TLobby__sub_80406EB8((NetBufferRef *)buf1, k);
        for (p = (u8 *)pkt + i * sizeof(NetPacketFragment); i < pkt->fragment_count; p += sizeof(NetPacketFragment), i++) {
            NetMemcpy(buf2, p + offsetof(NetPacket, fragments[0].buffer), 8);
            if (rem != 0) {
                TLobby__sub_80406EB8((NetBufferRef *)buf2, rem);
            }
            rem = *(s16 *)(p + offsetof(NetPacket, fragments[0].length)) - rem;
            if ((u32)rem > o->f534 - o->fD8) {
                rem = o->fD8;
            }
            sum += rem;
            if (k + rem >= o->f534) {
                TLobby__sub_80406FD8(buf1, buf2, o->f534 - k);
                NetMemcpy(buf1, &o->rcv_buf, 8);
                TLobby__sub_80406EB8((NetBufferRef *)buf2, o->f534 - k);
                rem -= o->f534 - k;
            }
            if (rem != 0) {
                TLobby__sub_80406FD8(buf1, buf2, rem);
                TLobby__sub_80406EB8((NetBufferRef *)buf1, (s16)rem);
            }
            rem = 0;
        }
        s = th->seq;
        sum += s;
        if (o->reasm_n == -1) {
            TLobby__sub_8041FDA0(o, 0, s, sum);
            o->last_reasm = 0;
        } else {
            if (s - o->reasm[0].start <= 0) {
                TLobby__sub_8041FDA0(o, 0, s, sum);
                kk = 0;
            } else {
                /* Not a TCB: e moves one range (8 bytes) per kk, so e->reasm[0] is o->reasm[kk]. Only e->reasm is read. */
                TcpTcb *e = (TcpTcb *)((u8 *)o + sizeof(TcpReasmRange));
                for (kk = 1; kk <= o->reasm_n; e = (TcpTcb *)((u8 *)e + sizeof(TcpReasmRange)), kk++) {
                    if (s - e->reasm[0].start <= 0) {
                        n = o->reasm[kk - 1].end;
                        if (s - n <= 0) {
                            delta = sum - n;
                            if (delta < 0) {
                                goto fin;
                            }
                            o->reasm_total += delta;
                            o->reasm[kk - 1].end = sum;
                            kk--;
                        } else {
                            TLobby__sub_8041FDA0(o, kk, s, sum);
                        }
                        break;
                    }
                }
                if (kk == o->reasm_n + 1) {
                    n = o->reasm[kk - 1].end;
                    if (s - n <= 0) {
                        delta = sum - n;
                        if (delta < 0) {
                            goto fin;
                        }
                        o->reasm_total += delta;
                        o->reasm[kk - 1].end = sum;
                        kk--;
                    } else {
                        TLobby__sub_8041FDA0(o, kk, s, sum);
                    }
                }
            }
            o->last_reasm = kk;
            while (kk + 1 <= o->reasm_n && o->reasm[kk].end - o->reasm[kk + 1].start >= 0) {
                if (o->reasm[kk].end - o->reasm[kk + 1].end >= 0) {
                    {
                        s16 idx = kk + 1;
                        s16 nn = o->reasm_n;
                        s16 j;
                        if (!(idx < 0 || nn < 0 || idx > nn)) {
                            o->reasm_total -= o->reasm[idx].end - o->reasm[idx].start;
                            for (j = idx; j < o->reasm_n; j++) {
                                o->reasm[j] = o->reasm[j + 1];
                            }
                            o->reasm_n--;
                        }
                    }
                } else {
                    o->reasm_total += o->reasm[kk + 1].end - o->reasm[kk].end;
                    o->reasm[kk].end = o->reasm[kk + 1].end;
                    {
                        s16 idx = kk + 1;
                        s16 nn = o->reasm_n;
                        s16 j;
                        if (!(idx < 0 || nn < 0 || idx > nn)) {
                            o->reasm_total -= o->reasm[idx].end - o->reasm[idx].start;
                            for (j = idx; j < o->reasm_n; j++) {
                                o->reasm[j] = o->reasm[j + 1];
                            }
                            o->reasm_n--;
                        }
                    }
                }
            }
        }
fin:
        TLobby__sub_8041FED4(o);
        return 0;
    }
    return -1;
}

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

s32 TLobby__sub_8041FFF8(u32 len, TcpTcb *self) {
    u32 t;
    s16 idx = (s16)(self - tcp_protocol_state.tcbs);
    u8 e[12];
    u8 c_pad[8];
    TcpSendEntry c;
    u8 b[8];
    u8 pad[8];
    u8 a[8];
    u8 d[8];
    u32 n;
    NetPacketFragment *it;
    s16 i;
    s16 L;

    if (self->f204_b7 == 1) {
        b[4] = 1;
        n = len;
        a[4] = 1;
        if (n != 0 && self->f20 != 0) {
            set_value_and_enable(a, (s32)&c);
            NetMemcpy(b, &self->snd_buf, 8);
            if ((s32)self->f24 != 0) {
                TLobby__sub_80406EB8((NetBufferRef *)b, self->f24 << 4);
            }
            TLobby__sub_80406FD8(a, b, 16);
            while ((u32)c.len <= n && self->f20 != 0) {
                self->f20--;
                n -= c.len;
                self->req.total_bytes -= c.len;
                if (self->f24 < 0x40) {
                    self->f24 = self->f24 + 1;
                } else {
                    self->f24 = 0;
                }
                if (self->f20 == 0) {
                    self->f28 = 0;
                    self->f24 = 0;
                    self->f204_b7 = 0;
                }
                complete_request_callback(idx, c.done, 0, (s32 *)&c);
                t = self->f24;
                NetMemcpy(b, &self->snd_buf, 8);
                if (t != 0) {
                    TLobby__sub_80406EB8((NetBufferRef *)b, t << 4);
                }
                TLobby__sub_80406FD8(a, b, 16);
            }
            if (n != 0 && self->f20 != 0) {
                L = n;
                self->req.total_bytes -= n;
                c.len -= L;
                c.off += L;
                TLobby__sub_80406FD8(b, a, 16);
            }
        }
        return 0;
    }

    if (len != 0) {
        if (len <= self->f20) {
            self->f20 -= len;
            self->f24 += len;
            if (self->f24 >= self->f530) {
                self->f24 -= self->f530;
            }
        } else {
            n = len - self->f20;
            self->f20 = 0;
            self->f24 = self->f28;
            self->req.total_bytes -= n;
            it = self->req.fragments;
            for (i = 0; i < self->req.fragment_count && n != 0; i++, it++) {
                if (n < it->length) {
                    it->length -= n;
                    TLobby__sub_80406EB8(&it->buffer, n);
                    n = 0;
                } else {
                    n -= it->length;
                    it->length = 0;
                }
            }
        }
    }

    if (self->req.total_bytes != 0) {
        if (self->req.total_bytes > self->f530 - self->f20) {
            return 0;
        }
        NetMemcpy(d, &self->snd_buf, 8);
        TLobby__sub_80406EB8((NetBufferRef *)d, self->f28);
        i = 0;
        it = self->req.fragments;
        while (i < self->req.fragment_count) {
            if (it->length > 0) {
                self->f20 += it->length;
                n = self->f530 - self->f28;
                if (it->length > n) {
                    TLobby__sub_80406FD8(d, &it->buffer, n);
                    TLobby__sub_80406EB8(&it->buffer, n);
                    it->length -= n;
                    self->req.total_bytes -= n;
                    self->f28 = 0;
                    NetMemcpy(d, &self->snd_buf, 8);
                }
                L = it->length;
                TLobby__sub_80406FD8(d, &it->buffer, L);
                self->f28 += L;
                TLobby__sub_80406EB8((NetBufferRef *)d, L);
                self->req.total_bytes -= L;
                it->length = 0;
            }
            i++;
            it++;
        }
        if (self->req.total_bytes != 0) {
            return 0;
        }
        self->req.total_bytes = 0;
        self->req.fragment_count = 0;
    }
    if (self->req.total_bytes != 0) {
        return 0;
    }
    set_thread_state_and_resume(idx, self->send_done, 0);
    return 0;
}

#pragma push
#pragma opt_propagation off
s32 TLobby__sub_80420410(s32 arg0, s32 arg1, NetPacket *pkt, TcpTcb *o) {
    TcpSendEntry d;
    NetBufferRef c;
    NetBufferRef b;
    NetBufferRef a;
    NetBufferRef tmp;
    u32 n;
    s32 m;
    s32 start;
    s32 cnt;
    s32 g;
    s32 i;
    s32 k;
    s32 lo;
    s32 j;
    s32 hi;
    u32 t;
    u32 off;
    u32 r31v;
    NetPacketFragment *it;
    NetPacketFragment *pa;
    NetPacketFragment *pb;
    NetPacket *qa;
    NetPacket *qb;
    NetPacketFragment *slot;

    if (o->f204_b7 == 1) {
        a.kind = 1;
        n = arg1;
        b.kind = 1;
        c.kind = 1;
        if ((u32)arg1 == 0) {
            goto neg1;
        }
        if (o->f20 == 0) {
            goto neg1;
        }
        set_value_and_enable(&a, (s32)&d);
        m = o->f24;
        NetMemcpy(&c, &o->snd_buf, 8);
        if (m != 0) {
            TLobby__sub_80406EB8(&c, m << 4);
        }
        TLobby__sub_80406FD8(&a, &c, 16);
        if ((u32)arg0 != 0) {
            while ((u32)d.len <= (u32)arg0) {
                arg0 -= d.len;
                if (m < 64) {
                    m++;
                } else {
                    m = 0;
                }
                NetMemcpy(&c, &o->snd_buf, 8);
                if (m != 0) {
                    TLobby__sub_80406EB8(&c, m << 4);
                }
                TLobby__sub_80406FD8(&a, &c, 16);
            }
            NetMemcpy(&b, &d.ref, 8);
            d.len -= (s16)arg0;
            TLobby__sub_80406EB8(&b, d.off);
            TLobby__sub_80406EB8(&b, arg0);
        } else {
            NetMemcpy(&b, &d.ref, 8);
            TLobby__sub_80406EB8(&b, d.off);
        }
        start = pkt->fragment_count;
        while (n != 0) {
            pa = &pkt->fragments[pkt->fragment_count];
            if (n >= (u32)d.len) {
                pa->length = d.len;
                pkt->total_bytes += d.len;
                n -= d.len;
            } else {
                pa->length = n;
                pkt->total_bytes += n;
                n = 0;
            }
            NetMemcpy(&pa->buffer, &b, 8);
            pkt->fragment_count++;
            if (n != 0) {
                if (m < 64) {
                    m++;
                } else {
                    m = 0;
                }
                NetMemcpy(&c, &o->snd_buf, 8);
                if (m != 0) {
                    TLobby__sub_80406EB8(&c, m << 4);
                }
                TLobby__sub_80406FD8(&a, &c, 16);
                NetMemcpy(&b, &d.ref, 8);
            }
        }
        cnt = pkt->fragment_count - start;
        hi = (cnt - 2) / 2;
        lo = (cnt + 1) / 2;
        /* Reverses the order of the fragments by swapping them from the middle outwards. The indexes count from
           fragments[0], not from start. qa/qb are NetPacket pointers stepped one fragment at a time, so
           q->fragments[0] is fragments[hi]/fragments[lo]. Only the 4-byte value of the saved buffer reference is
           copied into fragments[hi], which keeps its own kind byte. */
        qb = (NetPacket *)((u8 *)pkt + lo * sizeof(NetPacketFragment));
        qa = (NetPacket *)((u8 *)pkt + hi * sizeof(NetPacketFragment));
        for (; hi >= 0 && lo < cnt; hi--, lo++) {
            NetMemcpy(&tmp, &qb->fragments[0].buffer, 8);
            NetMemcpy(&qb->fragments[0].buffer, &qa->fragments[0].buffer, 8);
            NetMemcpy(&qa->fragments[0].buffer, &tmp, 4);
            j = qb->fragments[0].length;
            qb->fragments[0].length = qa->fragments[0].length;
            qa->fragments[0].length = j;
            qb = (NetPacket *)((u8 *)qb + sizeof(NetPacketFragment));
            qa = (NetPacket *)((u8 *)qa - sizeof(NetPacketFragment));
        }
        return 0;
neg1:
        return -1;
    }

    off = (u16)arg0;
    g = -1;
    r31v = off + o->f24;
    k = 0;
    if ((u32)arg0 >= o->f20 + o->req.total_bytes) {
        return -1;
    }
    if ((u32)arg0 < o->f20) {
        if ((u32)(arg1 + arg0) > o->f20) {
            goto adj;
        }
        if (o->f24 + arg0 < o->f530) {
            if (arg1 + (o->f24 + arg0) <= o->f530) {
                pkt->fragment_count = 1;
                NetMemcpy(&pkt->fragments[0].buffer, &o->snd_buf, 8);
                TLobby__sub_80406EB8(&pkt->fragments[0].buffer, r31v);
                pkt->fragments[0].length = arg1;
            } else {
                pkt->fragment_count = 2;
                NetMemcpy(&pkt->fragments[0].buffer, &o->snd_buf, 8);
                NetMemcpy(&pkt->fragments[1].buffer, &o->snd_buf, 8);
                TLobby__sub_80406EB8(&pkt->fragments[1].buffer, r31v);
                t = o->f530 - r31v;
                pkt->fragments[1].length = t;
                pkt->fragments[0].length = arg1 - t;
            }
        } else {
            pkt->fragment_count = 1;
            NetMemcpy(&pkt->fragments[0].buffer, &o->snd_buf, 8);
            TLobby__sub_80406EB8(&pkt->fragments[0].buffer, r31v - o->f530);
            pkt->fragments[0].length = arg1;
        }
        pkt->total_bytes = arg1;
        return 0;
adj:
        arg1 -= o->f20 - off;
        goto tail;
    }
    arg0 -= o->f20;
    it = o->req.fragments;
    for (i = 0; (u32)i < o->req.fragment_count; it++, i++) {
        if ((u32)arg0 < (u32)(s32)it->length) {
            pkt->fragment_count = 1;
            k = i;
            off = (u16)arg0;
            NetMemcpy(&pkt->fragments[0].buffer, &it->buffer, 8);
            TLobby__sub_80406EB8(&pkt->fragments[0].buffer, off);
            pkt->total_bytes = arg1;
            pkt->fragments[0].length = arg1;
            if ((u32)(arg1 + arg0) <= (u32)(s32)it->length) {
                pkt->total_bytes = arg1;
                pkt->fragments[0].length = arg1;
                return 0;
            }
            m = it->length - off;
            pkt->total_bytes = m;
            pkt->fragments[0].length = m;
            i++;
            while ((u32)i < o->req.fragment_count) {
                cnt = i - k;
                qa = (NetPacket *)((u8 *)pkt + (cnt - 1) * sizeof(NetPacketFragment));
                qb = (NetPacket *)((u8 *)pkt + cnt * sizeof(NetPacketFragment));
                for (j = cnt; j > 0; j--) {
                    NetMemcpy(&qb->fragments[0].buffer, &qa->fragments[0].buffer, 8);
                    qb->fragments[0].length = qa->fragments[0].length;
                    qa = (NetPacket *)((u8 *)qa - sizeof(NetPacketFragment));
                    qb = (NetPacket *)((u8 *)qb - sizeof(NetPacketFragment));
                }
                pkt->fragment_count++;
                it++;
                NetMemcpy(&pkt->fragments[0].buffer, &it->buffer, 8);
                arg1 -= m;
                if (arg1 <= (s32)it->length) {
                    pkt->fragments[0].length = arg1;
                    pkt->total_bytes += arg1;
                    return 0;
                }
                pkt->fragments[0].length = it->length;
                i++;
                pkt->total_bytes += it->length;
                m = it->length;
            }
            pkt->total_bytes = 0;
            pkt->fragments[0].length = 0;
            pkt->fragments[1].length = 0;
            return 0;
        }
        arg0 -= it->length;
    }
    return 0;
tail:
    i = 0;
    it = &o->req.fragments[i];
    for (; (u32)i < o->req.fragment_count; it++, i++) {
        if ((u32)arg1 <= (u32)(s32)it->length) {
            pkt->fragment_count = 1;
            NetMemcpy(&pkt->fragments[0].buffer, &it->buffer, 8);
            pkt->total_bytes = arg1;
            pkt->fragments[0].length = arg1;
            k = 1;
            break;
        }
        arg1 -= it->length;
    }
    qa = (NetPacket *)((u8 *)pkt + k * sizeof(NetPacketFragment));
    it--;
    i--;
    while (i > -1) {
        pkt->fragment_count++;
        NetMemcpy(&qa->fragments[0].buffer, &it->buffer, 8);
        k++;
        m = it->length;
        it--;
        i--;
        qa->fragments[0].length = m;
        pkt->total_bytes += m;
        qa = (NetPacket *)((u8 *)qa + sizeof(NetPacketFragment));
    }
    slot = &pkt->fragments[k];
    if (g < 0) {
        t = off + o->f24;
        if (t < o->f530) {
            if (o->f24 + o->f20 <= o->f530) {
                pkt->fragment_count++;
                NetMemcpy(&slot->buffer, &o->snd_buf, 8);
                TLobby__sub_80406EB8(&slot->buffer, t);
                slot->length = o->f20 - off;
            } else {
                pkt->fragment_count += 2;
                NetMemcpy(&slot->buffer, &o->snd_buf, 8);
                NetMemcpy(&slot[1].buffer, &o->snd_buf, 8);
                TLobby__sub_80406EB8(&slot[1].buffer, t);
                slot[1].length = o->f530 - t;
                slot->length = o->f20 - off - (s16)slot[1].length;
            }
        } else {
            pkt->fragment_count++;
            NetMemcpy(&slot->buffer, &o->snd_buf, 8);
            TLobby__sub_80406EB8(&slot->buffer, t - o->f530);
            slot->length = o->f20 - off;
        }
        pkt->total_bytes += o->f20 - off;
    } else {
        /* Unreachable: g is only ever -1. */
        pkt->fragment_count++;
        NetMemcpy(&slot->buffer, &o->req.fragments[g].buffer, 4);
        TLobby__sub_80406EB8(&slot->buffer, off);
        m = o->req.in_use - off;
        slot->length = m;
        pkt->total_bytes += (s16)m;
    }
    return 0;
}
#pragma pop
s32 TLobby__sub_80420BD0(NetPacket *req, TcpTcb *s, void (*done)(s16, s16)) {
    u32 v;
    if (s->f204_b7 == 1) {
        /* The inner test repeats the outer one, so the else never runs. */
        if (s->f204_b7) {
            v = s->req.total_bytes;
        } else {
            v = s->f20 + s->req.total_bytes;
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

s32 reset_stack_module(void) {
    TLobby__sub_803F87C4(&udp_runtime_state.count);
    udp_runtime_state.count = 0;
    return 0;
}
s32 init_ucb_entries(void) {
    s16 i;
    UdpControlBlock *e;

    TLobby__sub_803F87C8((u8 *)&udp_runtime_state);
    e = udp_runtime_state.entries;
    i = 0;
    while (i < udp_runtime_state.count) {
        e->signature[0] = 0x55;
        e->signature[1] = 0x43;
        e->signature[2] = 0x42;
        e->index = i;
        e->active = 0;
        i++;
        e++;
    }
    udp_runtime_state.ephemeralPort = 0;
    udp_runtime_state.ephemeralPortEnd = 0x7FF;
    udp_runtime_state.ephemeralPortStart = 0x400;
    return 0;
}
s32 TLobby__sub_80420D38(u16 arg0, u8 arg1) {
    s16 i;
    UdpControlBlock *e;
    UdpRuntimeState *g = &udp_runtime_state;
    for (i = 0, e = g->entries; i < g->count; i++, e++) {
        if (e->active != 0 && e->localPort == arg0) {
            s16 f = 0;
            if ((u8)(arg1 - 2) <= 1) {
                f = 0x81;
            } else if (arg1 <= 1) {
                f = 0x80;
            }
            if (f != 0) {
                NetDispatchSocketEvent(i, e->eventCallback, 2, f);
            }
            break;
        }
    }
    return 0;
}
#pragma push
#pragma dont_inline off
#pragma inline_depth(4)
inline void add_item_80420FC8(NetPacket *pkt, void *data, s32 len) {
    s32 n = pkt->fragment_count;
    s32 off = pkt->total_bytes;
    pkt->fragments[n].length = len;
    pkt->total_bytes = off + len;
    set_value_and_enable(&pkt->fragments[n].buffer, (s32)data);
    pkt->fragment_count++;
}

s32 udp_input(O_80420DE4 *arg0, NetworkAddress *src, NetworkAddress *dst, s32 arg3) {
    u8 sp20[8];
    Hdr_80420DE4 hdr;
    UdpRuntimeState *g;
    s16 i;
    s16 *plen;
    UdpControlBlock *e;
    plen = &arg0->f18;
    set_value_and_enable(sp20, (s32)&hdr);
    TLobby__sub_80406FD8(sp20, plen + 2, 8);
    if (hdr.sum != 0 && (u16)TLobby__sub_8040D8F0(src, dst, 0x11, arg0, 0) != 0) {
        return -1;
    }
    g = &udp_runtime_state;
    e = g->entries;
    i = 0;
    while (i < g->count) {
        if (e->active == 0) {
            goto next;
        }
        if (is_addr_unspecified(&e->remoteAddress) != 0) {
            if (e->remoteAddress.family != 0 && e->remoteAddress.family != src->family) {
                goto next;
            }
        } else if (compare_sockaddr(&e->remoteAddress, src) != 0) {
            goto next;
        }
        if (is_addr_unspecified(&e->localAddress) != 0) {
            if (e->localAddress.family != 0 && e->localAddress.family != dst->family) {
                goto next;
            }
        } else if (compare_sockaddr(&e->localAddress, dst) != 0) {
            goto next;
        }
        if (e->remotePort != 0 && e->remotePort != hdr.src) {
            goto next;
        }
        if (e->localPort != hdr.dst) {
            goto next;
        }
        arg0->f8 -= 8;
        *plen -= 8;
        TLobby__sub_80406EB8((NetBufferRef *)(plen + 2), 8);
        if (TLobby__sub_80421F10(arg0, src, dst, hdr.src, e->receiveCallback, i) != 0) {
            return -1;
        }
        return 0;
    next:
        i++;
        e++;
    }
    if (is_multicast_address(dst, arg3) == 1) {
        return 0;
    }
    return -2;
}

s16 udp_sendto(s16 id, NetPacket *pkt, NetworkAddress *src, NetworkAddress *dst, u16 port, s32 arg5) {
    s16 r;
    UdpControlBlock *e;
    if (id < 0 || id >= udp_runtime_state.count) {
        return -4;
    }
    e = udp_runtime_state.entries;
    e += id;
    if (e->active == 0) {
        return -4;
    }
    if (is_addr_unspecified(&e->remoteAddress) == 0) {
        dst = &e->remoteAddress;
    }
    if (e->localAddress.family != 0) {
        src = &e->localAddress;
    }
    if (src->family != 0 && src->family != dst->family) {
        return -2;
    }
    if (e->remotePort != 0) {
        e->destinationPort = e->remotePort;
    } else {
        e->destinationPort = port;
    }
    if (TLobby__sub_8040DA54(dst, src) == 0) {
        NetDispatchSocketEvent(id, e->eventCallback, 2, 0x80);
        return -6;
    }
    r = select_source_address(src, dst);
    if (r < 0) {
        return r;
    }
    e->length = pkt->total_bytes + 8;
    add_item_80420FC8(pkt, &e->sourcePort, 8);
    e->checksum = 0;
    e->checksum = TLobby__sub_8040D8F0(src, dst, 0x11, pkt, 1);
    return dispatch_by_addr_family(pkt, dst, src, arg5 + 4, arg5 + 4, 0x11);
}
#pragma pop

s32 NetUdpClose(s16 id) {
    UdpControlBlock* entry;
    if (id < 0 || id >= udp_runtime_state.count) return -4;
    entry = udp_runtime_state.entries;
    entry += id;
    if (!entry->active) return -4;
    NetDispatchSocketEvent(id, entry->eventCallback, 2, 0xFF);
    entry->active = 0;
    return 0;
}
s16 NetUdpConnect(s16 id, NetworkAddress* remoteAddress, s32 port, s32 eventCallback, u32 receiveCallback) {
    UdpControlBlock* entry;
    if (id < 0 || id >= udp_runtime_state.count) return -4;
    entry = udp_runtime_state.entries;
    entry += id;
    if (!entry->active) return -4;
    if (entry->receiveCallback != 0) return -4;
    if (remoteAddress->family != 0) {
        NetMemcpy(&entry->remoteAddress, remoteAddress, sizeof(NetworkAddress));
    } else {
        NetMemset(&entry->remoteAddress, 0, sizeof(NetworkAddress));
    }
    entry->remotePort = port;
    entry->destinationPort = port;
    entry->eventCallback = eventCallback;
    entry->receiveCallback = receiveCallback;
    return 0;
}

s16 NetUdpBind(s16 id, NetworkAddress* localAddress, s32 port) {
    UdpControlBlock* entry;
    if (id < 0 || id >= udp_runtime_state.count) return -4;
    if (localAddress != NULL && NetValidateLocalAddress(localAddress) < 0) return -4;
    entry = udp_runtime_state.entries;
    entry += id;
    if (!entry->active) return -4;
    if ((u16)port != 0) {
        s16 index = 0;
        UdpControlBlock* other = udp_runtime_state.entries;
        for (; index < udp_runtime_state.count; index++, other++) {
            if (other->active && other->localPort == (u16)port) return -3;
        }
    }
    /* Dereferences localAddress even when it is NULL. */
    if (localAddress->family != 0) {
        NetMemcpy(&entry->localAddress, localAddress, sizeof(NetworkAddress));
    } else {
        NetMemset(&entry->localAddress, 0, sizeof(NetworkAddress));
    }
        if ((u16)(s16)port != 0) {
        entry->localPort = port;
    } else {
        entry->localPort = NetUdpAllocateEphemeralPort();
    }
    entry->sourcePort = entry->localPort;
    return 0;
}

#pragma push
#pragma opt_dead_assignments off
s16 NetUdpCreate(void) {
    s16 index = 0;
    UdpControlBlock* entry = udp_runtime_state.entries;
    for (; index < udp_runtime_state.count; index++, entry++) {
        if (!entry->active) {
            entry->signature[0] = 'U';
            entry->signature[1] = 'C';
            entry->signature[2] = 'B';
            entry->index = index;
            entry->active = 1;
            entry->sourcePort = 0;
            entry->destinationPort = 0;
            entry->length = 0;
            entry->checksum = 0;
            entry->localPort = 0;
            entry->remotePort = 0;
            NetMemset(&entry->remoteAddress, 0, sizeof(NetworkAddress));
            NetMemset(&entry->localAddress, 0, sizeof(NetworkAddress));
            entry->receiveCallback = 0;
            entry->eventCallback = 0;
            return index;
        }
    }
    return -0x104;
}

#pragma pop

#pragma push
#pragma dont_inline off
#pragma inline_depth(4)
inline s16 IsUdpPortInUse(u16 port) {
    s16 index = 0;
    UdpControlBlock* entry = udp_runtime_state.entries;
    for (; index < udp_runtime_state.count; index++, entry++) {
        if (entry->active == 1 && port == entry->localPort) return 1;
    }
    return 0;
}

u16 NetUdpAllocateEphemeralPort(void) {
    if (!udp_runtime_state.ephemeralPort) {
        s32 tick;
        NetStoreTick(&tick);
        udp_runtime_state.ephemeralPort = udp_runtime_state.ephemeralPortStart;
        udp_runtime_state.ephemeralPort |= tick & 0x3FF;
    } else if (udp_runtime_state.ephemeralPort < udp_runtime_state.ephemeralPortEnd) {
        udp_runtime_state.ephemeralPort++;
    } else {
        udp_runtime_state.ephemeralPort = udp_runtime_state.ephemeralPortStart;
    }
    while (IsUdpPortInUse(udp_runtime_state.ephemeralPort)) {
        if (udp_runtime_state.ephemeralPort < udp_runtime_state.ephemeralPortEnd) {
            udp_runtime_state.ephemeralPort++;
        } else {
            udp_runtime_state.ephemeralPort = udp_runtime_state.ephemeralPortStart;
        }
    }
    return udp_runtime_state.ephemeralPort;
}
#pragma pop
