#include "pso/network/NetworkRuntime.h"
#include "pso/network/UdpRuntime.h"
#include "types.h"
#include "pso/unk/TLobby.h"

struct P_8041FDA0 { s32 a; s32 b; };

struct O_8041FDA0 { u8 pad0[0xF4]; s32 total; s16 n; u8 padFA[2]; P_8041FDA0 items[32]; };

struct P_8041FE44 { u32 a; u32 b; };

struct O_8041FE44 { u8 pad0[0x228]; u32 now; u8 pad22C[0x2F8 - 0x22C]; P_8041FE44 items[5]; };

struct S_80420BD0 {
    u8 pad0[0x20]; s32 f20; u8 pad24[8]; u8 data2C[8]; u32 f34;
    u8 pad38[0x1FC - 0x38]; s32 f1FC; u8 pad200[4];
    u8 flag : 1; u8 rest : 7;
};

struct Item_80420FC8 { s16 len; u8 pad2[2]; u8 data[8]; };

struct Pkt_80420FC8 { u8 pad0[4]; s32 count; s32 len; Item_80420FC8 items[1]; };

struct P_8041F66C { s32 a; s32 b; };

struct O_8041F66C {
    u8 pad0[0xD8]; s32 fD8; u8 padDC[4]; u32 fE0; u8 padE4[0xF4 - 0xE4];
    s32 total; s16 n; s16 fFA; P_8041F66C items[32]; u8 pad1FC[0x228 - 0x1FC]; s32 now;
    u8 pad22C[0x534 - 0x22C]; u32 f534;
};

struct Obj_8041ED8C {
    u8 pad0[6];
    s16 f6;
    u8 pad8[3];
    u8 fB;
    u8 padC[0xC8 - 0xC];
    u8 fC8[8];
    u8 padD0[0xD8 - 0xD0];
    u32 fD8;
    u32 fDC;
    u8 padE0[4];
    u8 fE4[4];
    u8 fE8;
    u8 padE9[3];
    u32 fEC;
    s32 fF0;
    u8 padF4[0x200 - 0xF4];
    s32 f200;
    u8 f204;
    u8 pad205[0x2D0 - 0x205];
    s32 f2D0;
    u8 pad2D4[0x534 - 0x2D4];
    u32 f534;
    u8 pad538[4];
    u32 f53C;
    u8 pad540[4];
};

struct G_8041ED8C { Obj_8041ED8C *p; s16 n; u8 pad[0xA2]; };

struct Buf_8041ED8C { u8 b[8]; };

struct Obj_8041F11C {
    u8 pad0[6];
    s16 f6;
    u8 pad8[3];
    u8 fB;
    u8 padC[0xD8 - 0xC];
    u32 fD8;
    u8 padDC[0xE8 - 0xDC];
    u8 fE8;
    u8 padE9[0x200 - 0xE9];
    s32 f200;
    u8 pad204[0x2D0 - 0x204];
    s32 f2D0;
    u8 pad2D4[0x544 - 0x2D4];
};

struct G_8041F11C { Obj_8041F11C *p; s16 n; u8 pad[0xA2]; };

struct Hdr_80420DE4 { u16 src; u16 dst; u16 len; u16 sum; };

struct O_80420DE4 { u8 pad0[8]; s32 f8; u8 padC[0xC]; s16 f18; u8 pad1A[2]; u8 f1C[4]; };

struct TcpSeqRange { u32 start; u32 end; };

struct TcpSackView { u8 pad0[0xFA]; s16 last_reasm; TcpSeqRange reasm[32]; u8 pad1FC[0x2F8 - 0x1FC]; TcpSeqRange sack[5]; };

extern "C" {
void TLobby__sub_803F87C8(u8 *arg0);
s32 TLobby__sub_803F87C4(void *);
void TLobby__sub_8041FDA0(O_8041FDA0 *o, s16 idx, s32 a, s32 b);
void TLobby__sub_8041FED4(TcpSackView *tcb);
void NetMemcpy(void *_w0, void *_w1, int _w2);
s32 TLobby__sub_80420BD0(void *arg0, S_80420BD0 *s, s32 arg2);
s32 TLobby__sub_80420D38(u16 arg0, u8 arg1);
s16 dispatch_by_addr_family__6TLobbyFlPUcPUcPUcPvPv(void *, void *, void *, s32, s32, int);
s16 TLobby__sub_8040D8F0(void *, void *, int, void *, int);
s16 select_source_address__6TLobbyFPvPv(void *, void *);
s16 TLobby__sub_8040DA54(void *, void *);
s16 is_addr_unspecified__6TLobbyFPv(void *);
s16 udp_sendto__6TLobbyFsPvPvPvUsi(s16 id, Pkt_80420FC8 *pkt, NetworkAddress *src, NetworkAddress *dst, u16 port, s32 arg5);
void TLobby__sub_8041F66C(O_8041F66C *o);
void set_slot_state_and_resume__6TLobbyFv(s16, s32, s16);
void TLobby__sub_80406EB8(void *, u32);
void TLobby__sub_80406FD8(void *, void *, u32);
void TLobby__sub_8041A9AC(Obj_8041ED8C *);
extern G_8041ED8C tcp_protocol_state;
s32 TLobby__sub_8041ED8C(Obj_8041ED8C *self, void *data, u32 len, s32 arg3);
s32 TLobby__sub_8041F11C(Obj_8041F11C *self);
s16 compare_sockaddr__6TLobbyFPUc(void *, void *);
s16 is_multicast_address__6TLobbyFs(void *, s32);
s16 TLobby__sub_80421F10(void *, void *, void *, u16, s32, s16);
s32 udp_input__6TLobbyFPvPvPvi(O_80420DE4 *arg0, NetworkAddress *src, NetworkAddress *dst, s32 arg3);
UdpRuntimeState udp_runtime_state;

struct O_8041FE44;

s32 TLobby__sub_8041ED8C(Obj_8041ED8C *self, void *data, u32 len, s32 arg3) {
    s16 idx = self - tcp_protocol_state.p;
    s32 m;
    u32 k;
    Buf_8041ED8C src;
    Buf_8041ED8C dst;
    if (self->fE8 != 0) {
        return -4;
    }
    if ((self->f204 >> 6) & 1) {
        return -4;
    }
    self->f200 = arg3;
    NetMemcpy(self->fE4, data, 8);
    self->fEC = len;
    m = 0;
    self->fF0 = m;
    if (self->fD8 == 0) {
        switch (self->f6) {
        case 0:
        case 5:
        case 7:
        case 8:
        case 10:
            self->fE8 = m;
            set_slot_state_and_resume__6TLobbyFv(idx, self->f200, -7);
            while (self->fE8 != 0) {
                self->fE8 = m;
                set_slot_state_and_resume__6TLobbyFv(idx, self->f200, -7);
            }
            return 0;
        case -1:
            self->fE8 = m;
            set_slot_state_and_resume__6TLobbyFv(idx, self->f200, -11);
            while (self->fE8 != 0) {
                self->fE8 = m;
                set_slot_state_and_resume__6TLobbyFv(idx, self->f200, -11);
            }
            return 0;
        default:
            return 0;
        }
    }
    do {
        m = (s32)(self->fD8 > self->fEC ? self->fEC : self->fD8);
        self->fF0 = m;
        NetMemcpy(&src, self->fC8, 8);
        TLobby__sub_80406EB8(&src, self->fDC);
        NetMemcpy(&dst, self->fE4, 8);
        if (self->fDC + m > self->f534) {
            k = self->f534 - self->fDC;
            TLobby__sub_80406FD8(&dst, &src, k);
            TLobby__sub_80406EB8(&dst, k);
            m -= k;
            self->fD8 -= k;
            self->fDC = 0;
            NetMemcpy(&src, self->fC8, 8);
        }
        TLobby__sub_80406FD8(&dst, &src, m);
        self->fD8 -= m;
        self->fDC += m;
        if (self->fDC >= self->f534) {
            self->fDC -= self->f534;
        }
        self->fE8 = 0;
        set_slot_state_and_resume__6TLobbyFv(idx, self->f200, self->fF0);
    } while (self->fE8 != 0 && self->fD8 != 0);
    if (self->f53C == 0) {
        self->fB &= ~1;
    }
    if (self->f6 != -1 && self->f6 != 0) {
        TLobby__sub_8041A9AC(self);
    }
    if (self->fE8 != 0) {
        switch (self->f6) {
        case 0:
        case 5:
        case 7:
        case 8:
        case 10:
            set_slot_state_and_resume__6TLobbyFv(idx, self->f200, -7);
            break;
        case -1:
            set_slot_state_and_resume__6TLobbyFv(idx, self->f200, -11);
            break;
        default:
            return 0;
        }
    }
    if (self->fD8 == 0 && (self->fB & 8) && !(self->fB & 0x20)) {
        NetDispatchSocketEvent((s16)(self - tcp_protocol_state.p), self->f2D0, 3, 3);
        self->fB |= 0x20;
    }
    return 0;
}

s32 TLobby__sub_8041F11C(Obj_8041F11C *self) {
    s16 idx = self - (*(G_8041F11C *)&tcp_protocol_state).p;
    while (self->fE8 != 0) {
        self->fE8 = 0;
        set_slot_state_and_resume__6TLobbyFv(idx, self->f200, -7);
    }
    if (self->fD8 == 0 && !(self->fB & 0x20)) {
        NetDispatchSocketEvent((s16)(self - (*(G_8041F11C *)&tcp_protocol_state).p), self->f2D0, 3, 3);
        self->fB |= 0x20;
    }
    return 0;
}

void TLobby__sub_8041F66C(O_8041F66C *o) {
    s16 i;
    s16 cnt;
    s16 j;
    s32 d;
    u8 unused[8];
    if (o->n == -1) {
        return;
    }
    for (i = 0; i <= o->n; i++) {
        if (o->now - o->items[i].b < 0) {
            break;
        }
    }
    if (i <= o->n && o->now - o->items[i].a >= 0) {
        d = o->items[i].b - o->now;
        o->fE0 += d;
        if (o->fE0 >= o->f534) {
            o->fE0 -= o->f534;
        }
        cnt = i + 1;
        o->fD8 += d;
        o->now = o->items[i].b;
    } else {
        cnt = i;
    }
    ((TLobby *)o)->expire_timeout_entries();
    if (cnt <= 0) {
        return;
    }
    o->n -= cnt;
    for (j = 0; j < cnt; j++) {
        o->total -= o->items[j].b - o->items[j].a;
    }
    for (j = 0; j <= o->n; j++) {
        o->items[j] = o->items[j + cnt];
    }
    if (o->n == -1) {
        o->fFA = -1;
    } else {
        o->fFA = 0;
    }
}

void TLobby__sub_8041FDA0(O_8041FDA0 *o, s16 idx, s32 a, s32 b) {
    s16 i;
    if (idx < 0) {
        return;
    }
    if (idx > o->n + 1) {
        return;
    }
    if (idx > 0x1F) {
        return;
    }
    if (o->n >= 0x1F) {
        o->n = 0x1E;
    }
    for (i = o->n; i >= idx; i--) {
        o->items[i + 1] = o->items[i];
    }
    o->items[idx].a = a;
    o->items[idx].b = b;
    o->n++;
    o->total += b - a;
}

void TLobby::expire_timeout_entries() {
    O_8041FE44 *o = (O_8041FE44 *)this;
    s16 i;
    s16 j;
    i = 0;
    while (i < 5) {
        if (o->items[i].a == o->items[i].b) {
            return;
        }
        if ((s32)(o->items[i].b - o->now) <= 0) {
            for (j = i; j < 4; j++) {
                o->items[j] = o->items[j + 1];
            }
            o->items[4].a = 0;
            o->items[4].b = 0;
        } else {
            i++;
        }
    }
}

void TLobby__sub_8041FED4(TcpSackView *tcb) {
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

s32 TLobby__sub_80420BD0(void *arg0, S_80420BD0 *s, s32 arg2) {
    u32 v;
    if (s->flag == 1) {
        if (s->flag) {
            v = s->f34;
        } else {
            v = s->f20 + s->f34;
        }
        if (v != 0) {
            return -1;
        }
    }
    s->f1FC = arg2;
    NetMemcpy(s->data2C, arg0, 0x9C);
    s->flag = 0;
    return 0;
}

s32 TLobby::reset_stack_module() {
    TLobby__sub_803F87C4(&udp_runtime_state.count);
    udp_runtime_state.count = 0;
    return 0;
}
s32 TLobby::init_ucb_entries() {
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
inline void add_item_80420FC8(Pkt_80420FC8 *pkt, void *data, s32 len) {
    s32 n = pkt->count;
    s32 off = pkt->len;
    pkt->items[n].len = len;
    pkt->len = off + len;
    ((TLobby *)(pkt->items[n].data))->set_value_and_enable((s32)data);
    pkt->count++;
}

s32 udp_input__6TLobbyFPvPvPvi(O_80420DE4 *arg0, NetworkAddress *src, NetworkAddress *dst, s32 arg3) {
    u8 sp20[8];
    Hdr_80420DE4 hdr;
    UdpRuntimeState *g;
    s16 i;
    s16 *plen;
    UdpControlBlock *e;
    plen = &arg0->f18;
    ((TLobby *)sp20)->set_value_and_enable((s32)&hdr);
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
        if (is_addr_unspecified__6TLobbyFPv(&e->remoteAddress) != 0) {
            if (e->remoteAddress.family != 0 && e->remoteAddress.family != src->family) {
                goto next;
            }
        } else if (compare_sockaddr__6TLobbyFPUc(&e->remoteAddress, src) != 0) {
            goto next;
        }
        if (is_addr_unspecified__6TLobbyFPv(&e->localAddress) != 0) {
            if (e->localAddress.family != 0 && e->localAddress.family != dst->family) {
                goto next;
            }
        } else if (compare_sockaddr__6TLobbyFPUc(&e->localAddress, dst) != 0) {
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
        TLobby__sub_80406EB8(plen + 2, 8);
        if (TLobby__sub_80421F10(arg0, src, dst, hdr.src, e->receiveCallback, i) != 0) {
            return -1;
        }
        return 0;
    next:
        i++;
        e++;
    }
    if (is_multicast_address__6TLobbyFs(dst, arg3) == 1) {
        return 0;
    }
    return -2;
}

s16 udp_sendto__6TLobbyFsPvPvPvUsi(s16 id, Pkt_80420FC8 *pkt, NetworkAddress *src, NetworkAddress *dst, u16 port, s32 arg5) {
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
    if (is_addr_unspecified__6TLobbyFPv(&e->remoteAddress) == 0) {
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
    r = select_source_address__6TLobbyFPvPv(src, dst);
    if (r < 0) {
        return r;
    }
    e->length = pkt->len + 8;
    add_item_80420FC8(pkt, &e->sourcePort, 8);
    e->checksum = 0;
    e->checksum = TLobby__sub_8040D8F0(src, dst, 0x11, pkt, 1);
    return dispatch_by_addr_family__6TLobbyFlPUcPUcPUcPvPv(pkt, dst, src, arg5 + 4, arg5 + 4, 0x11);
}
#pragma pop

}

extern "C" {
s32 NetUdpClose(s16 id) {
    if (id < 0 || id >= udp_runtime_state.count) return -4;
    UdpControlBlock* entry = udp_runtime_state.entries;
    entry += id;
    if (!entry->active) return -4;
    NetDispatchSocketEvent(id, entry->eventCallback, 2, 0xFF);
    entry->active = 0;
    return 0;
}
s16 NetUdpConnect(s16 id, NetworkAddress* remoteAddress, s32 port, s32 eventCallback, u32 receiveCallback) {
    if (id < 0 || id >= udp_runtime_state.count) return -4;
    UdpControlBlock* entry = udp_runtime_state.entries;
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
    if (id < 0 || id >= udp_runtime_state.count) return -4;
    if (localAddress != NULL && NetValidateLocalAddress(localAddress) < 0) return -4;
    UdpControlBlock* entry = udp_runtime_state.entries;
    entry += id;
    if (!entry->active) return -4;
    if ((u16)port != 0) {
        s16 index = 0;
        UdpControlBlock* other = udp_runtime_state.entries;
        for (; index < udp_runtime_state.count; index++, other++) {
            if (other->active && other->localPort == (u16)port) return -3;
        }
    }
    if (localAddress->family != 0) {
        NetMemcpy(&entry->localAddress, localAddress, sizeof(NetworkAddress));
    } else {
        NetMemset(&entry->localAddress, 0, sizeof(NetworkAddress));
    }
    // Keep both narrowing casts to preserve MWCC's register allocation.
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

u16 NetUdpAllocateEphemeralPort() {
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

}
