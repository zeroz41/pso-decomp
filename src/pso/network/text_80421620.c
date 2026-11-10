/* The network stack's socket API and stack bring-up (a C library, built with GC/1.2.5n): stack init/shutdown, the
 * TCP calls (create, bind, connect, send, receive, stat, abort, delete) with their completion and socket-event
 * dispatch, UDP send/receive helpers, and the DHCP client's packets and timer. */
#include "pso/network/NetworkRuntime.h"
#include "pso/network/UdpRuntime.h"
#include "pso/network/SocketEvents.h"
#include "pso/network/NetTcpState.h"
#include "pso/network/NetworkDispatch.h"
#include "pso/network/text_80421620.h"
#include "types.h"
#include "pso/network/TLobby_804050DC.h"
#include "pso/network/TLobby_8041112C.h"
void release_entry(void *entry);

#include <stddef.h>
#include "pso/network/BufferRef.h"
typedef struct Stack_80421AD8 {
    s16 sp1C;
    s16 sp1E;
    s32 sp20;
    s32 sp24;
    s32 sp28;
} Stack_80421AD8;

typedef struct O_80421938 { u8 pad0[8]; s32 size; s16 used; } O_80421938;

typedef struct Stack_80421938 { s16 flags; s16 len; s32 zero; u8 src[0x10]; u8 dst[0x10]; } Stack_80421938;

typedef struct O_80421F10 { u8 pad0[8]; s32 size; s16 used; } O_80421F10;


typedef struct IpAddr_80422B8C { u32 family; u8 a[0xC]; } IpAddr_80422B8C;

typedef struct P_8042315C { s32 type; s32 a; s32 b; s32 c; s32 pad10; s16 n; s16 m; s32 d; s32 pad1C; } P_8042315C;



s32 TLobby__sub_8041112C(void);
void NetIPv6ShutdownNeighborDiscovery(void);
s32 TLobby__sub_80418A7C(void);
s32 TLobby__sub_8041A1D8(void);
s32 NetUnregisterTimer(void *);
void TLobby__sub_80421FB8(void *, void *, void *);
s32 TLobby__sub_80421AD8(u8 *arg0, s32 arg1, s32 arg2, u32 arg3, s32 arg4);
s32 TLobby__sub_804218AC(s32 arg0, s32 arg1);
s32 TLobby__sub_8040F9CC(void *, void *, void *, int);
s32 TLobby__sub_804219D0(s32 arg0, s32 arg1, s32 arg2);
s32 NetIPv4AddRoute(void *, void *, void *, s16, u8, u16); /* declared s32 here; the definition is s16 (u32, u32, u32, s16, u8, u16) */
s32 TLobby__sub_80421A50(s32 arg0, s32 arg1, s32 arg2);
s32 TLobby__sub_8041E780();
s32 tcp_create(void);
s32 mark_connection_closed(s32);
s32 tcp_delete(s32 a);
void TLobby__sub_80425288(s32, s32, void *);
s32 TLobby__sub_8042455C(void *a);
s16 TLobby__sub_8041DE1C(s16, s16, u32 *); /* declared s16 here; the definition returns s32 */
void TLobby__sub_8041E590(s16);
s32 get_tcp_stat(int, void *, void *, void *, void *);
s16 validate_tcp_handle(int);
s32 tcp_stat(s32 a, s16 *b, s16 *c, u32 *d, u32 *e);
s16 tcp_get_socket_handle(int);
s32 abort_tcp_connection(int);
s32 tcp_abort(s32 a);
s32 TLobby__sub_80421938(O_80421938 *o, void *src, void *dst, void *cb, s32 flags);
s32 TLobby__sub_80421F10(O_80421F10 *o, void *src, void *dst, s16 port, void *cb, s32 flags);
void OSReport(const char *, ...);
s16 reset_socket_table();
s16 TLobby__sub_80409AD8();
s16 init_ipv4_interfaces();
s16 TLobby__sub_8040ED70();
s16 NetIPv6Init();
s16 TUdpSocket__sub_8041118C();
s16 TLobby__sub_80415690(); /* declared s16 here; the definition returns s32 */
s16 NetIPv6InitNeighborDiscovery();
s16 init_packet_fragment_pools();
s16 TLobby__sub_80419A34(int); /* declared here with an int argument and an s16 return; the definition takes no arguments and returns s32 */
s16 NetInitializeDispatcher();
s16 NetTCPInit();
extern char lbl_804800F0[];
extern u32 TLobby__network_stack_init_count;
extern u8 *lbl_805E1188;
s16 TLobby__sub_8041DBD4(int, void *, s16, void *);
s16 tcp_receive(s32 a, void *cb, s32 len, void *buf);
void TLobby__sub_8041E2EC(int, void *, void *); /* declared here with an s32 1st argument; the definition takes s16 */
s32 tcp_connect_start(int, void *, u16);
s32 tcp_connect(s32 a, IpAddr_80422B8C *addr, u16 port, IpAddr_80422B8C *opt);
s32 TLobby__sub_8041E5E4(int, void *, u16);
s32 tcp_bind(s32 a, void *addr, u16 port);
s16 TLobby__sub_8040F00C(s16, void *, int, void *); /* declared s16 here; the definition is s32 (s16, NetBufferRef *, s16, s32) */
s16 TLobby__sub_80412058(s16, void *, int, void *);
s16 TLobby__sub_80422F70(s16 arg0, s32 arg1, s32 arg2, s32 arg3);
s32 OSDisableInterrupts();
s32 OSRestoreInterrupts(int);
s16 TLobby__sub_8040F1A0(s16);
s16 TLobby__sub_80412210(s16);
s16 TLobby__sub_8040F454(s32, s32, s32, s16);
s16 TLobby__sub_80412CA4(void *, s16, s16, s16, s32);
s16 TLobby__sub_8042315C(s16 arg0, P_8042315C *p);
u8 lbl_805C1E00[0x1194];
extern u8 lbl_805C2F94[0x100];
extern u8 dhcp_server_id[4];
s32 cleanup_subsystems(void) {
    TLobby__sub_80419A7C();
    TLobby__sub_80409AA8();
    NetIPv6ShutdownNeighborDiscovery();
    TLobby__sub_8041112C();
    TLobby__sub_8040ED28();
    NetIPv6Shutdown();
    TLobby__sub_8040DD68();
    TLobby__sub_80418A7C();
    reset_stack_module();
    TLobby__sub_8041A1D8();
    shutdown_network_handle();
    reset_net_value();
    TLobby__sub_80419A00();
    return 0;
}

/* Brings up the network stack subsystems in order, stopping at the first failure (result < 0). */
s16 init_network_stack(void) {
    s16 init_ucb_entries(void);
    s16 result;
    u32 count;
    if ((s32) *lbl_805E1188 != 0xA) {
        return -1;
    }
    if ((u32) TLobby__network_stack_init_count == 0U) {
        OSReport(lbl_804800F0);
    }
    count = TLobby__network_stack_init_count;
    TLobby__network_stack_init_count = count + 1;
    result = TLobby__sub_80419A34(count);
    if (result >= 0) {
        result = TLobby__sub_80415690();
        if (result >= 0) {
            result = reset_socket_table();
            if (result >= 0) {
                result = NetTCPInit();
                if (result >= 0) {
                    result = init_ucb_entries();
                    if (result >= 0) {
                        result = init_packet_fragment_pools();
                        if (result >= 0) {
                            result = init_ipv4_interfaces();
                            if (result >= 0) {
                                result = NetIPv6Init();
                                if (result >= 0) {
                                    result = TLobby__sub_8040ED70();
                                    if (result >= 0) {
                                        result = TUdpSocket__sub_8041118C();
                                        if (result >= 0) {
                                            result = NetIPv6InitNeighborDiscovery();
                                            if (result >= 0) {
                                                result = TLobby__sub_80409AD8();
                                                if (result >= 0) {
                                                    result = NetInitializeDispatcher();
                                                    if (result >= 0) {
                                                        return 0;
                                                    }
                                                    TLobby__sub_80409AA8();
                                                    goto block_19;
                                                }
block_19:
                                                NetIPv6ShutdownNeighborDiscovery();
                                                goto block_20;
                                            }
block_20:
                                            TLobby__sub_8041112C();
                                            goto block_21;
                                        }
block_21:
                                        TLobby__sub_8040ED28();
                                        goto block_22;
                                    }
block_22:
                                    NetIPv6Shutdown();
                                    goto block_23;
                                }
block_23:
                                TLobby__sub_8040DD68();
                                goto block_24;
                            }
block_24:
                            TLobby__sub_80418A7C();
                            goto block_25;
                        }
block_25:
                        reset_stack_module();
                        goto block_26;
                    }
block_26:
                    TLobby__sub_8041A1D8();
                    goto block_27;
                }
block_27:
                shutdown_network_handle();
                goto block_28;
            }
block_28:
            reset_net_value();
            goto block_29;
        }
block_29:
        TLobby__sub_80419A00();
        goto block_30;
    }
block_30:
    return result;
}

s32 TLobby__sub_804217E4(void) {
    unlock_mutex(network_dispatch_state.lock_handle);
    return 0;
}
s32 TLobby__sub_80421814(void) {
    lock_mutex(network_dispatch_state.lock_handle);
    return 0;
}
s32 TLobby__sub_80421844(s32 timer) {
    s32 result;
    if (timer == 0) {
        return -2;
    }
    lock_mutex(network_dispatch_state.lock_handle);
    result = NetUnregisterTimer((void *)timer);
    unlock_mutex(network_dispatch_state.lock_handle);
    return result;
}

s32 TLobby__sub_804218AC(s32 callback, s32 interval) {
    s32 result;
    if (callback == 0) {
        return -2;
    }
    if (interval <= 0) {
        return -2;
    }
    lock_mutex(network_dispatch_state.lock_handle);
    result = NetRegisterTimer(interval, 0, (NetTimerCallback)callback);
    unlock_mutex(network_dispatch_state.lock_handle);
    return result;
}

s32 TLobby__sub_80421938(O_80421938 *o, void *src, void *dst, void *cb, s32 flags) {
    Stack_80421938 s;
    s.flags = flags | 0xC00;
    s.len = o->size - o->used;
    s.zero = 0;
    NetMemcpy(s.src, src, 0x10);
    NetMemcpy(s.dst, dst, 0x10);
    if (cb != NULL) {
        TLobby__sub_80421FB8(cb, &s, o);
    }
    return 0;
}

s32 TLobby__sub_804219D0(s32 arg0, s32 arg1, s32 arg2) {
    s32 result;
    lock_mutex(network_dispatch_state.lock_handle);
    result = TLobby__sub_8040F9CC((void *)arg0, (void *)arg1, (void *)arg2, 0);
    unlock_mutex(network_dispatch_state.lock_handle);
    return result;
}

s32 TLobby__sub_80421A50(s32 arg0, s32 arg1, s32 arg2) {
    s32 result;
    lock_mutex(network_dispatch_state.lock_handle);
    result = NetIPv4AddRoute((void *)arg0, (void *)arg1, (void *)arg2, 1, (int) (0U), (int) (0U));
    unlock_mutex(network_dispatch_state.lock_handle);
    return result;
}

s32 TLobby__sub_80421AD8(u8 *sock, s32 src, s32 dst, u32 cb, s32 flags) {
    typedef struct SockFields { u8 pad_0[8]; s32 field_8; s16 field_C; } SockFields;
    typedef char sp1C_offset[(offsetof(Stack_80421AD8, sp1C) == 0x0) ? 1 : -1];
    typedef char sp1E_offset[(offsetof(Stack_80421AD8, sp1E) == 0x2) ? 1 : -1];
    typedef char sp20_offset[(offsetof(Stack_80421AD8, sp20) == 0x4) ? 1 : -1];
    typedef char sp24_offset[(offsetof(Stack_80421AD8, sp24) == 0x8) ? 1 : -1];
    typedef char sp28_offset[(offsetof(Stack_80421AD8, sp28) == 0xC) ? 1 : -1];
    Stack_80421AD8 stack;
    stack.sp1C = flags | 0x800;
    stack.sp1E = ((SockFields*)sock)->field_8 - ((SockFields*)sock)->field_C;
    stack.sp20 = 0;
    stack.sp24 = src;
    stack.sp28 = dst;
    if (cb != 0U) {
        TLobby__sub_80421FB8((void *)cb, &stack.sp1C, (void *)sock);
    }
    return 0;
}

s32 TLobby__sub_80421B3C(s32 a) {
    s32 r;
    NetworkDispatchState *g;
    s16 m;
    if ((a & 0xC00) != 0x400) { return -4; }
    g = &network_dispatch_state;
    m = a & 0xFFFFF3FF;
    lock_mutex(g->lock_handle);
    r = NetUdpClose(m);
    unlock_mutex(g->lock_handle);
    return r;
}

s16 udp_sendto(s32 id, NetPacket *pkt, NetworkAddress *src, NetworkAddress *dst, u16 port, s32 opt); /* declared here with an s32 handle; the definition takes s16 */

s16 TUdpSocket__sub_80421BAC(s32 h, u32 *src, u32 *dst, u16 port, u32 *opt, s8 n, send_buffs *bufs) {
    u32 any_addr[5];
    u32 any_opt[4];
    u16 i;
    NetPacket *pkt;
    s16 r;
    if ((h & 0xC00) != 0x400) {
        return -4;
    }
    h = h & 0xFFFFF3FF;
    NetMemset(any_addr, 0, 0x14);
    if (dst != NULL) {
        if (*dst == 0) {
            return -2;
        }
    } else {
        dst = any_addr;
    }
    if (src == NULL) {
        src = any_addr;
    }
    if (opt != NULL && *opt != 0) {
        if (*opt != *dst) {
            return -2;
        }
    } else {
        NetMemset(any_opt, 0, 0x10);
        opt = any_opt;
    }
    lock_mutex(network_dispatch_state.lock_handle);
    if (n > 3) {
        unlock_mutex(network_dispatch_state.lock_handle);
        return -2;
    }
    pkt = (NetPacket *)alloc_free_entry();
    if (pkt == NULL) {
        unlock_mutex(network_dispatch_state.lock_handle);
        return -0x101;
    }
    pkt->fragment_count = 0;
    pkt->total_bytes = 0;
    for (i = n; i != 0; i--) {
        if (bufs[i - 1].len < 0) {
            release_entry((void *)pkt);
            unlock_mutex(network_dispatch_state.lock_handle);
            return -2;
        }
        pkt->total_bytes += bufs[i - 1].len;
        pkt->fragments[pkt->fragment_count].length = bufs[i - 1].len;
        init_packet_header((void *)&pkt->fragments[pkt->fragment_count].buffer, (s32)bufs[i - 1].buff);
        pkt->fragment_count++;
    }
    if (pkt->total_bytes > 0x7FE3) {
        release_entry((void *)pkt);
        unlock_mutex(network_dispatch_state.lock_handle);
        return -2;
    }
    if (pkt->total_bytes == 0) {
        release_entry((void *)pkt);
        unlock_mutex(network_dispatch_state.lock_handle);
        return 0;
    }
    r = udp_sendto(h, pkt, (NetworkAddress *)src, (NetworkAddress *)dst, port, (s32)opt);
    release_entry((void *)pkt);
    unlock_mutex(network_dispatch_state.lock_handle);
    return r;
}

s16 TUdpSocket__sub_80421DEC(void *src, s32 sport, void *dst, s32 dport, s32 arg4, void *cb) {
    u8 any[0x14];
    s16 h;
    s16 r;
    NetMemset(any, 0, 0x14);
    if (cb == NULL) {
        return -2;
    }
    if (src == NULL) {
        src = any;
    }
    if (dst == NULL) {
        dst = any;
    }
    lock_mutex(network_dispatch_state.lock_handle);
    h = NetUdpCreate();
    if (h < 0) {
        unlock_mutex(network_dispatch_state.lock_handle);
        return h;
    }
    r = NetUdpBind(h, (NetworkAddress*)src, sport);
    if (r < 0) {
        NetUdpClose(h);
        unlock_mutex(network_dispatch_state.lock_handle);
        return r;
    }
    r = NetUdpConnect(h, (NetworkAddress*)dst, dport, arg4, (u32)cb);
    if (r < 0) {
        NetUdpClose(h);
        unlock_mutex(network_dispatch_state.lock_handle);
        return r;
    }
    h |= 0x400;
    unlock_mutex(network_dispatch_state.lock_handle);
    return h;
}

s32 TLobby__sub_80421F10(O_80421F10 *o, void *src, void *dst, s16 port, void *cb, s32 flags) {
    UdpDatagram s;
    s.socket = flags | 0x400;
    s.len = o->size - o->used;
    s.buf = 0;
    NetMemcpy(&s.src, src, sizeof(NetworkAddress));
    NetMemcpy(&s.dst, dst, sizeof(NetworkAddress));
    s.port = port;
    if (cb != NULL) {
        TLobby__sub_80421FB8(cb, &s, o);
    }
    return 0;
}

typedef s16 (*PktCb_80421FB8)(s32, UdpDatagram *);

void TLobby__sub_80421FB8(void *cb, void *hdr_, void *o_) {
    s32 i;
    u8 *buf;
    s16 len;
    NetBufferRef pkt;
    s16 chunk;
    UdpDatagram *hdr;
    NetPacket *o;
    hdr = (UdpDatagram *)hdr_;
    o = (NetPacket *)o_;
    len = hdr->len;
    if (((PktCb_80421FB8)cb)(0, hdr) == 0) {
        if (hdr->len >= len) {
            hdr->len = len;
        }
        len = hdr->len;
        if (len == 0 || hdr->buf == NULL) {
            return;
        }
        buf = hdr->buf;
        init_packet_header(&pkt, (s32)buf);
        for (i = 1; len > 0; i++) {
            if (len > o->fragments[i].length) {
                chunk = o->fragments[i].length;
            } else {
                chunk = len;
            }
            TLobby__sub_80406FD8(&pkt, &o->fragments[i].buffer, chunk);
            TLobby__sub_80406EB8(&pkt, (u32)chunk);
            len -= chunk;
        }
        ((PktCb_80421FB8)cb)(1, hdr);
    }
}

s32 complete_request_callback(s32 idx_, void (*cb)(s16, s16, s32), s16 code, s32 *extra) {
    s16 idx = idx_;
    TcpTcb *s = tcp_protocol_state.tcbs;
    s += idx;
    if (cb != NULL && !(s->waits[1].flags & 8)) {
        cb(code, idx, *extra);
    } else if (!(s->waits[2].flags & 4)) {
        s->waits[1].status = code;
        s->waits[2].flags |= 4;
        s->send_done = 0;
    }
    s->waits[1].count--;
    return 0;
}

s16 tcp_receive(s32 a, void *cb, s32 len, void *buf) {
    u8 hdr[8];
    s16 r;
    NetworkDispatchState *g;
    TcpTcb *s;
    if (a & 0xC00) {
        return -4;
    }
    g = &network_dispatch_state;
    a = a & 0xFFFFF3FF;
    lock_mutex(g->lock_handle);
    if (validate_tcp_handle(a) < 0) {
        unlock_mutex(g->lock_handle);
        return -4;
    }
    if (tcp_get_socket_handle(a) == 1) {
        unlock_mutex(g->lock_handle);
        return -9;
    }
    s = tcp_protocol_state.tcbs;
    s += (s16)a;
    if (s->waits[0].flags & 3) {
        unlock_mutex(g->lock_handle);
        return -9;
    }
    init_packet_header((void *)hdr, (s32)buf);
    NetMemset(&s->waits[0].flags, 0, 8);
    s->waits[0].flags |= 1;
    if (s->flags & 0x40) {
        s->waits[0].flags |= 8;
        r = TLobby__sub_8041DBD4(a, hdr, len, cb);
        s->waits[0].flags &= ~8;
    } else {
        r = TLobby__sub_8041DBD4(a, hdr, len, cb);
    }
    if (r < 0) {
        s->waits[0].flags &= ~1;
        unlock_mutex(network_dispatch_state.lock_handle);
        return r;
    }
    if (cb != NULL && (!(s->flags & 0x40) || !(s->waits[0].flags & 4))) {
        unlock_mutex(network_dispatch_state.lock_handle);
        return -1;
    }
    if (s->waits[0].flags & 4) {
        r = s->waits[0].status;
        unlock_mutex(network_dispatch_state.lock_handle);
        return r;
    }
    NetStoreCurrentThread(&s->waits[0].thread);
    s->waits[0].flags |= 2;
    unlock_mutex(network_dispatch_state.lock_handle);
    NetSuspendCurrentThread();
    lock_mutex(network_dispatch_state.lock_handle);
    s->waits[0].flags &= ~2;
    r = s->waits[0].status;
    s->waits[0].flags &= ~1;
    unlock_mutex(network_dispatch_state.lock_handle);
    return r;
}

s32 set_slot_state_and_resume(s32 idx, void (*cb)(s16, s16), s16 state) {
  TcpTcb *s = tcp_protocol_state.tcbs;
  s16 new_var;
  s += (s16) idx;
  if ((cb != 0) && (!(s->waits[0].flags & 8)))
  {
    new_var = (s16) idx;
    cb(state, new_var);
    s->waits[0].status = state;
    s->waits[0].flags &= ~1;
    s->waits[0].flags |= 4;
    s->recv_done = 0;
  }
  else
    if ((s->waits[0].flags & 1) && (!(s->waits[0].flags & 4)))
  {
    if (s->waits[0].flags & 2)
    {
      resume_thread(s->waits[0].thread);
    }
    s->waits[0].status = state;
    s->waits[0].flags &= ~1;
    s->waits[0].flags |= 4;
    s->recv_done = 0;
  }
  return 0;
}

s16 tcp_send(s32 a, void (*notify)(s16, s16), char bufnum, struct send_buffs *sb) {
    TcpTcb *s;
    s32 *entry;
    struct send_buffs *p;
    u8 *cur;
    s16 r;
    s16 n;
    s16 ret;
    s16 tcp_start_send(s32, NetPacket *, void (*)(s16, s16), u8); /* declared here with an s32 handle and an s16 return; the definition takes s16 and returns s32 */
    if (bufnum > 3) {
        return -2;
    }
    if (a & 0xC00) {
        return -4;
    }
    a = a & 0xFFFFF3FF;
    lock_mutex(network_dispatch_state.lock_handle);
    if (validate_tcp_handle(a) < 0) {
        unlock_mutex(network_dispatch_state.lock_handle);
        return -4;
    }
    r = tcp_get_socket_handle(a);
    if (r == -1 || r == 1) {
        unlock_mutex(network_dispatch_state.lock_handle);
        return -9;
    }
    s = tcp_protocol_state.tcbs;
    s += (s16)a;
    if ((s->waits[2].flags & 3) || s->waits[1].count != 0) {
        unlock_mutex(network_dispatch_state.lock_handle);
        return -9;
    }
    entry = (s32 *)alloc_free_entry();
    if (entry == NULL) {
        unlock_mutex(network_dispatch_state.lock_handle);
        return -0x101;
    }
    entry[1] = (u16)bufnum;
    n = bufnum;
    p = sb + (u16)n;
    cur = (u8 *)entry + (entry[2] = 0) * 12;
    while ((u16)n != 0) {
        p--;
        n--;
        if (p->len < 0) {
            release_entry((void *)entry);
            unlock_mutex(network_dispatch_state.lock_handle);
            return -2;
        }
        init_packet_header((void *)(cur + 0x10), (s32)p->buff);
        *(s16 *)(cur + 0xc) = p->len;
        entry[2] += *(s16 *)(cur + 0xc);
        cur += 0xc;
    }
    if ((u32)entry[2] == 0) {
        release_entry((void *)entry);
        unlock_mutex(network_dispatch_state.lock_handle);
        return -2;
    }
    NetMemset(&s->waits[2].flags, 0, 8);
    s->waits[2].flags |= 1;
    if (s->flags & 0x40) {
        s->waits[2].flags |= 8;
        ret = tcp_start_send(a, (NetPacket *)entry, notify, 0);
        s->waits[2].flags &= ~8;
    } else {
        ret = tcp_start_send(a, (NetPacket *)entry, notify, 0);
    }
    release_entry((void *)entry);
    if (ret < 0) {
        s->waits[2].flags &= ~1;
        unlock_mutex(network_dispatch_state.lock_handle);
        return ret;
    }
    if (notify != NULL && (!(s->flags & 0x40) || !(s->waits[2].flags & 4))) {
        unlock_mutex(network_dispatch_state.lock_handle);
        return -1;
    }
    if (s->waits[2].flags & 4) {
        r = s->waits[2].status;
        unlock_mutex(network_dispatch_state.lock_handle);
        return r;
    }
    NetStoreCurrentThread(&s->waits[2].thread);
    s->waits[2].flags |= 2;
    unlock_mutex(network_dispatch_state.lock_handle);
    NetSuspendCurrentThread();
    lock_mutex(network_dispatch_state.lock_handle);
    s->waits[2].flags &= ~2;
    r = s->waits[2].status;
    s->waits[2].flags &= ~1;
    unlock_mutex(network_dispatch_state.lock_handle);
    return r;
}

s32 set_thread_state_and_resume(s32 idx, void (*cb)(s16, s16), s16 state) {
  TcpTcb *s = tcp_protocol_state.tcbs;
  s16 new_var;
  s += (s16) idx;
  if ((cb != 0) && (!(s->waits[2].flags & 8)))
  {
    new_var = (s16) idx;
    cb(state, new_var);
    s->waits[2].status = state;
    s->waits[2].flags &= ~1;
    s->waits[2].flags |= 4;
    s->send_done = 0;
  }
  else
    if ((s->waits[2].flags & 1) && (!(s->waits[2].flags & 4)))
  {
    if (s->waits[2].flags & 2)
    {
      resume_thread(s->waits[2].thread);
    }
    s->waits[2].status = state;
    s->waits[2].flags &= ~1;
    s->waits[2].flags |= 4;
    s->send_done = 0;
  }
  return 0;
}

s16 tcp_get_opt(s16 nh, s16 type, u32 *opt) {
    s16 r;
    if (nh & 0xC00) {
        return -2;
    }
    nh &= 0xFFFFF3FF;
    if (opt == NULL) {
        return -2;
    }
    lock_mutex(network_dispatch_state.lock_handle);
    r = TLobby__sub_8041DE1C(nh, type, opt);
    unlock_mutex(network_dispatch_state.lock_handle);
    return r;
}

s32 tcp_stat(s32 a, s16 *b, s16 *c, u32 *d, u32 *e) {
    s32 r;
    NetworkDispatchState *g;
    if (a & 0xC00) { return -4; }
    g = &network_dispatch_state;
    a = a & 0xFFFFF3FF;
    lock_mutex(g->lock_handle);
    if (validate_tcp_handle(a) < 0) {
        unlock_mutex(g->lock_handle);
        return -4;
    }
    r = get_tcp_stat(a, b, c, d, e);
    unlock_mutex(g->lock_handle);
    return r;
}

s32 tcp_delete(s32 a) {
    s32 r;
    NetworkDispatchState *g;
    s32 m;
    if (a & 0xC00) { return -4; }
    g = &network_dispatch_state;
    m = a & 0xFFFFF3FF;
    lock_mutex(g->lock_handle);
    r = mark_connection_closed(m);
    unlock_mutex(g->lock_handle);
    return r;
}

s32 tcp_abort(s32 a) {
    s32 r;
    NetworkDispatchState *g;
    s32 m;
    s16 st;
    if (a & 0xC00) { return -4; }
    g = &network_dispatch_state;
    m = a & 0xFFFFF3FF;
    lock_mutex(g->lock_handle);
    if (validate_tcp_handle(m) < 0) {
        unlock_mutex(g->lock_handle);
        return -4;
    }
    st = tcp_get_socket_handle(m);
    if (st == -1 || st == 1) {
        unlock_mutex(network_dispatch_state.lock_handle);
        return -9;
    }
    r = abort_tcp_connection(m);
    unlock_mutex(g->lock_handle);
    return r;
}

s32 TLobby__sub_80422AB8(s32 idx, void (*cb)(s16, s16, s32, s32), s16 code, s32 arg3, s32 arg4, s32 arg5) {
    TcpTcb *s = tcp_protocol_state.tcbs;
    s16 i2;
    s16 v;
    s += (s16)idx;
    if (cb != NULL && !(s->waits[3].flags & 8)) {
        i2 = (s16)idx;
        if (code >= 0) {
            v = (s32)code;
            TLobby__sub_8041E590(code);
        } else {
            v = code;
        }
        cb(v, i2, arg3, arg5);
        s->accept_cb = 0;
    } else {
        s->waits[3].status = code;
        if (s->waits[3].flags & 2) {
            resume_thread(s->waits[3].thread);
        }
    }
    s->waits[3].flags &= ~1;
    s->waits[3].flags |= 4;
    return 0;
}

s32 tcp_connect(s32 a, IpAddr_80422B8C *addr, u16 port, IpAddr_80422B8C *opt) {
    IpAddr_80422B8C tmp;
    s32 r;
    NetworkDispatchState *g;
    void *p;
    if (a & 0xC00) {
        return -4;
    }
    a = a & 0xFFFFF3FF;
    if (addr != NULL) {
        if (addr->family == 0) {
            return -2;
        }
    } else {
        return -2;
    }
    NetMemset(&tmp, 0, 0x10);
    if (opt != NULL && opt->family != 0) {
        if (opt->family != addr->family) {
            return -2;
        }
    } else {
        opt = &tmp;
    }
    switch (addr->family) {
    case 4:
        p = opt->a;
        opt = (IpAddr_80422B8C *)tmp.a;
        break;
    case 6:
        p = tmp.a;
        opt = (IpAddr_80422B8C *)opt->a;
        break;
    case 5:
    default:
        return -2;
    }
    g = &network_dispatch_state;
    lock_mutex(g->lock_handle);
    if (validate_tcp_handle(a) < 0) {
        unlock_mutex(g->lock_handle);
        return -4;
    }
    if (tcp_get_socket_handle(a) != 0) {
        unlock_mutex(g->lock_handle);
        return -9;
    }
    TLobby__sub_8041E2EC(a, p, opt);
    r = tcp_connect_start(a, addr, port);
    unlock_mutex(g->lock_handle);
    return r;
}

s32 tcp_bind(s32 a, void *addr, u16 port) {
    u8 tmp[0x14];
    s32 r;
    NetworkDispatchState *g;
    if (a & 0xC00) { return -4; }
    a = a & 0xFFFFF3FF;
    if (addr == NULL) {
        NetMemset(tmp, 0, 0x14);
        addr = tmp;
    }
    g = &network_dispatch_state;
    lock_mutex(g->lock_handle);
    if (validate_tcp_handle(a) < 0) {
        unlock_mutex(g->lock_handle);
        return -4;
    }
    if (tcp_get_socket_handle(a) != 0) {
        unlock_mutex(g->lock_handle);
        return -9;
    }
    r = TLobby__sub_8041E5E4(a, addr, port);
    unlock_mutex(g->lock_handle);
    return r;
}

s32 tcp_create(void) {
    s32 handle;
    lock_mutex(network_dispatch_state.lock_handle);
    handle = TLobby__sub_8041E780();
    unlock_mutex(network_dispatch_state.lock_handle);
    return handle;
}

void NetDispatchSocketEvent(s16 v, s32 cb_, s32 type, s16 code) {
    s16 validate_tcp_handle(s16 handle);
    TcpTcb *s;
    switch ((s16)type) {
    case 1:
        v |= 0x800;
        break;
    case 6:
        v |= 0xC00;
        break;
    case 2:
        v |= 0x400;
        break;
    case 3:
        if (validate_tcp_handle(v) < 0) {
            return;
        }
        s = tcp_protocol_state.tcbs;
        s += (s16)v;
        if ((u16)(code - 10) <= 1 || code == 4) {
            if (s->waits[2].flags & 2) {
                s->waits[2].status = -5;
                s->waits[2].flags &= ~1;
                resume_thread(s->waits[2].thread);
            }
            if (s->waits[0].flags & 2) {
                s->waits[0].status = -5;
                s->waits[0].flags &= ~1;
                resume_thread(s->waits[0].thread);
            }
        }
        break;
    default:
        return;
    }
    if ((void *)cb_ != NULL) {
        ((void (*)(s16, s16))cb_)(v, code);
    }
}

s16 TLobby__sub_80422F70(s16 iface, s32 hdr_src, s32 len, s32 buf) {
    s32 sp18;
    s16 first;
    s16 second;
    s16 total;
    if (iface < 0) {
        return -2;
    }
    total = 0;
    lock_mutex(network_dispatch_state.lock_handle);
    init_packet_header((void *)(&sp18), hdr_src);
    first = TLobby__sub_8040F00C(iface, &sp18, (int)len, (void *)buf);
    if (first > 0) {
        total = first;
        len -= first * 0x1C;
    }
    second = TLobby__sub_80412058(iface, &sp18, (int)len, (void *)buf);
    if (second > 0) {
        total += second;
    }
    unlock_mutex(network_dispatch_state.lock_handle);
    if (total == 0) {
        if (first < second) {
            return first;
        }
        return second;
    }
    return total;
}

s16 TLobby__sub_80423064(s16 idx, s32 op) {
    s16 tmp;
    s16 tmp2;
    s16 result;
    s32 level;
    if (idx < 0) {
        return -2;
    }
    lock_mutex(network_dispatch_state.lock_handle);
    level = OSDisableInterrupts();
    switch (op) {
    case 0:
        result = 0;
        tmp = TLobby__sub_8040F1A0(idx);
        if (tmp < 0) {
            result = tmp;
        }
        tmp2 = TLobby__sub_80412210(idx);
        if (tmp2 < 0) {
            result = tmp2;
        }
        break;
    case 4:
        result = TLobby__sub_8040F1A0(idx);
        break;
    case 6:
        result = TLobby__sub_80412210(idx);
        break;
    default:
        result = -2;
        break;
    }
    OSRestoreInterrupts(level);
    unlock_mutex(network_dispatch_state.lock_handle);
    return result;
}

s16 TLobby__sub_8042315C(s16 iface, P_8042315C *p) {
    s16 result;
    s32 intr;
    if (iface < 0) {
        return -2;
    }
    lock_mutex(network_dispatch_state.lock_handle);
    intr = OSDisableInterrupts();
    switch (p->type) {
    case 4:
        result = TLobby__sub_8040F454(p->a, p->b, p->c, iface);
        break;
    case 6:
        if (p->n < 0 || p->n > 0x80) {
            result = -2;
        } else {
            result = TLobby__sub_80412CA4(&p->a, p->n, p->m, iface, p->d);
        }
        break;
    case 5:
    default:
        result = -2;
        break;
    }
    OSRestoreInterrupts(intr);
    unlock_mutex(network_dispatch_state.lock_handle);
    return result;
}

s32 TLobby__sub_8042325C(s32 a, s32 b, s32 c, s32 (*fn)(s32, s32, s32)) {
    s32 r = 0;
    if (fn != NULL) {
        r = fn(a, b, c);
    }
    return r;
}

s32 dhcp_discover_step(void);
s32 dhcp_request_step(void);
s32 dhcp_release_step(void);
void TLobby__sub_80423298(void) {
    s32 now;
    s32 elapsed;
    u32 secs;
    dhcp_error = 0;
    if (dhcp_state == 1) {
        dhcp_discover_step();
        return;
    }
    if (dhcp_state == 2) {
        dhcp_request_step();
        return;
    }
    if (dhcp_state == 6) {
        dhcp_release_step();
        return;
    }
    if ((dhcp_state != 3 && dhcp_state != 4 && dhcp_state != 5) || dhcp_lease_time == 0xFFFFFFFF) {
        return;
    }
    get_time_ms(&now);
    elapsed = now - dhcp_last_tick_ms;
    dhcp_last_tick_ms = now;
    dhcp_elapsed_ms += elapsed;
    secs = dhcp_elapsed_ms / 1000;
    dhcp_lease_elapsed += secs;
    dhcp_elapsed_ms %= 1000;
    if (dhcp_lease_elapsed >= dhcp_lease_time) {
        if (dhcp_socket > -1) {
            TLobby__sub_80421B3C(dhcp_socket);
            dhcp_socket = -1;
        }
        dhcp_state = -1;
        dhcp_error = 9;
        return;
    }
    if (dhcp_state != 5 && dhcp_lease_elapsed >= dhcp_rebinding_time) {
        dhcp_state = 5;
        dhcp_step = 0;
    }
    if (dhcp_state != 4 && dhcp_state != 5 && dhcp_lease_elapsed >= dhcp_renewal_time) {
        dhcp_state = 4;
        dhcp_step = 0;
    }
    if (dhcp_state == 4) {
        dhcp_request_step();
        return;
    }
    if (dhcp_state == 5) {
        dhcp_request_step();
    }
}

extern s32 lbl_805D7B2C;
extern s32 lbl_805D7B30;
extern s32 lbl_805D7B80;
s32 find_dhcp_option(u8 *p, u8 tag, u8 **out);
void parse_dhcp_lease_times(u8 *packet);

s32 TLobby__sub_80423440(u8 *pkt) {
    u8 *opts = pkt + 0xEC;
    u8 *p;
    s32 net;
    s32 w;
    u32 mask;
    u32 n;
    TLobby__sub_80425288(0xF, 4, pkt + 0x10);
    lbl_805D7B80 = 0;
    if (find_dhcp_option(opts, 1, &p) == 4) {
        lbl_805D7B80++;
        TLobby__sub_80425288(1, 4, p);
    } else {
        if (!(lbl_805D7B28 & 0x80000000)) {
            mask = 0xFF000000;
        } else if ((lbl_805D7B28 & 0xC0000000) == 0x80000000) {
            mask = 0xFFFF0000;
        } else if ((lbl_805D7B28 & 0xE0000000) == 0xC0000000) {
            mask = 0xFFFFFF00;
        } else {
            mask = 0;
        }
        TLobby__sub_80425288(1, 0, NULL);
        lbl_805D7B2C = mask;
    }
    if (find_dhcp_option(opts, 0x1C, &p) == 4) {
        lbl_805D7B80++;
        TLobby__sub_80425288(2, 4, p);
    } else {
        TLobby__sub_80425288(2, 0, NULL);
        net = lbl_805D7B28 & lbl_805D7B2C;
        lbl_805D7B30 = net | (lbl_805D7B2C ^ 0xFFFFFFFF);
    }
    if (lbl_805D7B40 != NULL) {
        *lbl_805D7B40 = lbl_805D7B28;
        lbl_805D7B40 = NULL;
    }
    if (lbl_805D7B44 != NULL) {
        *lbl_805D7B44 = lbl_805D7B2C;
        lbl_805D7B44 = NULL;
    }
    if (lbl_805D7B48 != NULL) {
        *lbl_805D7B48 = lbl_805D7B30;
        lbl_805D7B48 = NULL;
    }
    parse_dhcp_lease_times((u8 *)opts);
    n = find_dhcp_option(opts, 0xF, &p);
    if (n != 0) {
        TLobby__sub_80425288(3, (s16)n, p);
    } else {
        TLobby__sub_80425288(3, 1, NULL);
    }
    n = find_dhcp_option(opts, 6, &p);
    if (n >= 4 && (n & 3) == 0) {
        TLobby__sub_80425288(4, 4, p);
        if (n > 4) {
            TLobby__sub_80425288(5, 4, p + 4);
        } else {
            TLobby__sub_80425288(5, 4, NULL);
        }
    } else {
        TLobby__sub_80425288(4, 4, NULL);
        TLobby__sub_80425288(5, 4, NULL);
    }
    n = find_dhcp_option(opts, 3, &p);
    if (n >= 4 && (n & 3) == 0) {
        TLobby__sub_80425288(6, 4, p);
    } else {
        TLobby__sub_80425288(6, 4, NULL);
    }
    return 0;
}

/* Builds a DHCP release packet into packet. */
s32 build_dhcp_release(u8 *packet) {
    s32 m;
    u8 *p;
    u16 len;
    NetMemset(packet, 0, 0x5DC);
    ((u8 *)packet)[0] = 1;
    ((u8 *)packet)[1] = 1;
    ((u8 *)packet)[2] = 6;
    ((u8 *)packet)[3] = 0;
    get_time_ms((s32 *)&dhcp_last_tick_ms);
    lbl_805D7B50 = dhcp_last_tick_ms;
    NetMemcpy(((u8 *)packet) + 4, &lbl_805D7B50, 4);
    *(s32 *)(((u8 *)packet) + 0xC) = lbl_805D7B28;
    NetMemcpy(((u8 *)packet) + 0x1C, lbl_805D7B1C, 6);
    p = ((u8 *)packet) + 0xEC;
    *(s32 *)p = lbl_805D7B4C;
    p += 4;
    *p++ = 0x35;
    *p++ = 1;
    *p++ = 7;
    *p++ = 0x3D;
    *p++ = 7;
    *p++ = 1;
    NetMemcpy(p, lbl_805D7B1C, 6);
    p += 6;
    *p++ = 0x36;
    *p++ = 4;
    NetMemcpy(p, dhcp_server_id, 4);
    p += 4;
    len = NetStringLength((const char*)dhcp_hostname);
    if (len != 0) {
        *p++ = 0xC;
        m = len + 1;
        *p++ = m;
        NetMemcpy(p, dhcp_hostname, m);
        p += m;
    }
    *p++ = 0xFF;
    return p - ((u8 *)packet);
}

s32 dhcp_build_packet(u8 *packet) {
    s32 m;
    u8 *p;
    u16 len;
    u32 tmp;
    NetMemset(packet, 0, 0x5DC);
    ((u8 *)packet)[0] = 1;
    ((u8 *)packet)[1] = 1;
    ((u8 *)packet)[2] = 6;
    ((u8 *)packet)[3] = 0;
    NetMemcpy(((u8 *)packet) + 4, &lbl_805D7B50, 4);
    *(u16 *)(((u8 *)packet) + 0xA) = 0;
    if (dhcp_state == 4 || dhcp_state == 5) {
        *(s32 *)(((u8 *)packet) + 0xC) = lbl_805D7B28;
    }
    NetMemcpy(((u8 *)packet) + 0x1C, lbl_805D7B1C, 6);
    p = ((u8 *)packet) + 0xEC;
    *(s32 *)p = (*(s32 *)&lbl_805D7B4C);
    p += 4;
    *p++ = 0x35;
    *p++ = 1;
    *p++ = 3;
    *p++ = 0x3D;
    *p++ = 7;
    *p++ = 1;
    NetMemcpy(p, lbl_805D7B1C, 6);
    p += 6;
    *p++ = 0x37;
    *p++ = 5;
    *p++ = 1;
    *p++ = 3;
    *p++ = 6;
    *p++ = 0xF;
    *p++ = 0x1C;
    if (dhcp_state != 4 && dhcp_state != 5) {
        *p++ = 0x36;
        *p++ = 4;
        NetMemcpy(p, dhcp_server_id, 4);
        p += 4;
    }
    if (lbl_805D7B58 != 0) {
        *p++ = 0x33;
        *p++ = 4;
        tmp = lbl_805D7B58;
        NetMemcpy(p, &tmp, 4);
        p += 4;
    }
    if (dhcp_state != 4 && dhcp_state != 5) {
        *p++ = 0x32;
        *p++ = 4;
        NetMemcpy(p, &lbl_805D7B28, 4);
        p += 4;
    }
    len = NetStringLength((const char*)&dhcp_hostname);
    if (len != 0) {
        *p++ = 0xC;
        m = len + 1;
        *p++ = m;
        NetMemcpy(p, ((char *)&dhcp_hostname), m);
        p += m;
    }
    *p++ = 0xFF;
    return p - ((u8 *)packet);
}

s32 build_dhcp_discover_packet(u8 *packet) {
    u32 spC;
    u8 *p;
    u16 len;
    s32 n;
    NetMemset(packet, 0, 0x5DC);
    ((u8 *)packet)[0] = 1;
    ((u8 *)packet)[1] = 1;
    ((u8 *)packet)[2] = 6;
    ((u8 *)packet)[3] = 0;
    get_time_ms((s32 *)&dhcp_last_tick_ms);
    lbl_805D7B50 = dhcp_last_tick_ms;
    NetMemcpy(((u8 *)packet) + 4, &lbl_805D7B50, 4);
    *(s16 *)(((u8 *)packet) + 0xA) = 0;
    NetMemcpy(((u8 *)packet) + 0x1C, lbl_805D7B1C, 6);
    p = ((u8 *)packet) + 0xEC;
    *(u32 *)p = lbl_805D7B4C;
    p += 4;
    *p++ = 0x35;
    *p++ = 1;
    *p++ = 1;
    *p++ = 0x3D;
    *p++ = 7;
    *p++ = 1;
    NetMemcpy(p, lbl_805D7B1C, 6);
    p += 6;
    *p++ = 0x37;
    *p++ = 5;
    *p++ = 1;
    *p++ = 3;
    *p++ = 6;
    *p++ = 0xF;
    *p++ = 0x1C;
    if (lbl_805D7B58 != 0) {
        *p++ = 0x33;
        *p++ = 4;
        spC = lbl_805D7B58;
        NetMemcpy(p, &spC, 4);
        p += 4;
    }
    len = NetStringLength((const char*)dhcp_hostname);
    if (len != 0) {
        *p++ = 0xC;
        n = len + 1;
        *p++ = n;
        NetMemcpy(p, dhcp_hostname, n);
        p += n;
    }
    *p++ = 0xFF;
    return p - ((u8 *)packet);
}

extern u32 lbl_805D7B98;
extern s32 lbl_805D7B9C;
s32 TLobby__sub_804250A8(s32);
s32 TLobby__sub_80424FE0(void);

extern s32 dhcp_retries_left;
extern s32 dhcp_send_time;

s32 dhcp_release_step(void) {
    s32 now;
    P_8042315C opt;
    send_buffs buf;
    u32 dst[5];
    u32 src[5];
    s32 len;
    u32 pad[3];
    s16 sock;
    get_time_ms(&now);
    switch (dhcp_step) {
    case 0:
        TLobby__sub_80421B3C(dhcp_socket);
        dhcp_socket = -1;
        if (dhcp_state == 1 || dhcp_state == 2 || dhcp_state == 6) {
            lbl_805D7B14 = TLobby__sub_804250A8(0);
        }
        opt.type = 4;
        opt.a = 0;
        opt.b = -1;
        opt.c = -1;
        if (TLobby__sub_8042315C(dhcp_iface, &opt) != 0) {
            dhcp_error = 3;
            dhcp_step = -1;
            dhcp_state = -2;
            break;
        }
        lbl_805D7B14 = 1;
        if (TLobby__sub_80424FE0() != 0) {
            break;
        }
        lbl_805D7B9C = dhcp_max_retries;
    case 1:
        if (dhcp_step == 0) {
            dhcp_step = 1;
        } else if (now - lbl_805D7B98 < 300) {
            break;
        }
        len = build_dhcp_release((u8 *)lbl_805C1E00);
        src[0] = 4;
        dst[0] = 4;
        src[1] = 0;
        dst[1] = -1;
        sock = dhcp_socket;
        len = len > 300 ? len : 300;
        buf.len = len;
        buf.buff = lbl_805C1E00;
        if (TUdpSocket__sub_80421BAC(sock, src, dst, 0x43, NULL, 1, &buf) < 0) {
            TLobby__sub_80421B3C(dhcp_socket);
            dhcp_socket = -1;
            if (dhcp_state == 1 || dhcp_state == 2 || dhcp_state == 6) {
                lbl_805D7B14 = TLobby__sub_804250A8(0);
            }
            dhcp_error = 5;
            dhcp_step = -1;
            dhcp_state = -2;
        } else {
            lbl_805D7B98 = now;
            lbl_805D7B9C--;
            if (lbl_805D7B9C <= 0) {
                TLobby__sub_80421B3C(dhcp_socket);
                dhcp_socket = -1;
                if (dhcp_state == 1 || dhcp_state == 2 || dhcp_state == 6) {
                    lbl_805D7B14 = TLobby__sub_804250A8(0);
                }
                dhcp_state = 0;
                dhcp_step = 0;
                TLobby__sub_80425288(0xF, 0, NULL);
                TLobby__sub_80425288(0xE, 0, NULL);
            }
        }
        break;
    }
    return dhcp_state;
}

extern s32 lbl_805D7B8C;
extern s32 lbl_805D7B94;
extern s32 lbl_805D7B90;
/* One step of the DHCP request state machine (dhcp_step). */
s32 dhcp_request_step(void) {
    s32 now;
    s32 x;
    send_buffs buf;
    u32 dst[5];
    u32 src[5];
    u32 pad[3];
    s32 len;
    s16 sock;
    u32 d;
    s32 id;
    u32 t;
    get_time_ms(&now);
    switch (dhcp_step) {
    case 0:
        lbl_805D7B50 = now;
        if (dhcp_state == 2) {
            lbl_805D7B90 = dhcp_max_retries;
        }
        if (TLobby__sub_80424FE0() != 0) {
            break;
        }
        dhcp_step = 1;
    case 1:
        len = dhcp_build_packet(lbl_805C1E00);
        *(volatile s32 *)&dhcp_reply_received = 0;
        if (dhcp_state == 4) {
            id = *(s32 *)dhcp_server_id;
        } else {
            id = -1;
        }
        sock = dhcp_socket;
        dst[0] = 4;
        src[0] = 4;
        src[1] = 0;
        dst[1] = id;
        len = len > 300 ? len : 300;
        buf.len = len;
        buf.buff = lbl_805C1E00;
        if (TUdpSocket__sub_80421BAC(sock, src, dst, 0x43, NULL, 1, &buf) < 0) {
            TLobby__sub_80421B3C(dhcp_socket);
            dhcp_socket = -1;
            if (dhcp_state == 1 || dhcp_state == 2 || dhcp_state == 6) {
                lbl_805D7B14 = TLobby__sub_804250A8(0);
            }
            dhcp_error = 5;
            dhcp_step = -1;
            dhcp_state = -2;
            break;
        }
        lbl_805D7B8C = now;
        if (dhcp_state == 4) {
            d = dhcp_rebinding_time - dhcp_lease_elapsed;
            if (d >= 120) {
                lbl_805D7B94 = (d >> 1) * 1000;
            } else {
                lbl_805D7B94 = 0;
            }
        } else if (dhcp_state == 5) {
            d = dhcp_lease_time - dhcp_lease_elapsed;
            if (d >= 120) {
                lbl_805D7B94 = (d >> 1) * 1000;
            } else {
                lbl_805D7B94 = 0;
            }
        }
        dhcp_step = 2;
        break;
    case 2:
        if (dhcp_reply_received != 0) {
            if (dhcp_state == 4 || dhcp_state == 5) {
                parse_dhcp_lease_times(lbl_805C1E00 + 0x6C8);
                dhcp_lease_elapsed = 0;
            }
            TLobby__sub_80421B3C(dhcp_socket);
            dhcp_socket = -1;
            if (dhcp_state == 1 || dhcp_state == 2 || dhcp_state == 6) {
                lbl_805D7B14 = TLobby__sub_804250A8(0);
            }
            TLobby__sub_80423440(lbl_805C1E00 + 0x5DC);
            dhcp_step = 0;
            dhcp_state = 3;
        } else if (dhcp_state == 2) {
            if ((u32)(now - lbl_805D7B8C) >= 3000) {
                lbl_805D7B90--;
                if (lbl_805D7B90 <= 0) {
                    TLobby__sub_80421B3C(dhcp_socket);
                    dhcp_socket = -1;
                    if (dhcp_state == 1 || dhcp_state == 2 || dhcp_state == 6) {
                        lbl_805D7B14 = TLobby__sub_804250A8(0);
                    }
                    dhcp_state = -1;
                    dhcp_step = -1;
                    dhcp_error = 7;
                } else {
                    dhcp_step = 1;
                }
            }
        } else if (dhcp_state == 4) {
            t = lbl_805D7B94;
            if (t != 0 && (u32)(now - lbl_805D7B8C) >= t) {
                dhcp_step = 1;
            } else {
                dhcp_error = 8;
            }
        } else if (dhcp_state == 5) {
            t = lbl_805D7B94;
            if (t != 0 && (u32)(now - lbl_805D7B8C) >= t) {
                dhcp_step = 1;
            } else {
                dhcp_error = 9;
            }
        }
        break;
    }
    return dhcp_state;
}
s32 dhcp_handle_reply(s16 arg0, void *arg1);
/* One step of the DHCP discover state machine (dhcp_step). */
s32 dhcp_discover_step(void) {
    s32 now;
    P_8042315C req;
    P_8042315C req2;
    u32 pad2[3];
    u32 buf[2];
    u32 pad1[1];
    send_buffs rd;
    u32 dst[5];
    u32 src[5];
    s32 len;
    s16 sock;
    u32 pad[4];
    get_time_ms(&now);
    switch (dhcp_step) {
    case 0:
        TLobby__sub_80421B3C(dhcp_socket);
        dhcp_socket = -1;
        if (dhcp_state == 1 || dhcp_state == 2 || dhcp_state == 6) {
            lbl_805D7B14 = TLobby__sub_804250A8(0);
        }
        req.type = 4;
        req.a = 0;
        req.b = -1;
        req.c = -1;
        if (TLobby__sub_8042315C(dhcp_iface, &req) != 0) {
            TLobby__sub_80423064(dhcp_iface, 4);
            req2.type = 4;
            req2.a = 0;
            req2.b = -1;
            req2.c = -1;
            if (TLobby__sub_8042315C(dhcp_iface, &req2) != 0) {
                dhcp_step = -1;
                dhcp_state = -2;
                dhcp_error = 3;
                break;
            }
        }
        lbl_805D7B14 = 1;
        buf[0] = 4;
        buf[1] = 0;
        sock = TUdpSocket__sub_80421DEC(NULL, 0x44, buf, 0x43, 0, dhcp_handle_reply);
        dhcp_socket = sock;
        if (sock < 0) {
            TLobby__sub_80423064(dhcp_iface, 4);
            lbl_805D7B14 = 0;
            dhcp_step = -1;
            dhcp_state = -2;
            dhcp_error = 4;
            break;
        }
        dhcp_retries_left = dhcp_max_retries;
        dhcp_step = 1;
    case 1:
        len = build_dhcp_discover_packet((u8 *)lbl_805C1E00);
        dhcp_reply_received = 0;
        src[0] = 4;
        dst[0] = 4;
        src[1] = 0;
        dst[1] = -1;
        sock = dhcp_socket;
        len = len > 300 ? len : 300;
        rd.len = len;
        rd.buff = lbl_805C1E00;
        if (TUdpSocket__sub_80421BAC(sock, src, dst, 0x43, NULL, 1, &rd) < 0) {
            TLobby__sub_80421B3C(dhcp_socket);
            dhcp_socket = -1;
            if (dhcp_state == 1 || dhcp_state == 2 || dhcp_state == 6) {
                lbl_805D7B14 = TLobby__sub_804250A8(0);
            }
            dhcp_error = 5;
            dhcp_step = -1;
            dhcp_state = -2;
            break;
        }
        dhcp_send_time = now;
        dhcp_step = 2;
        break;
    case 2:
        if (dhcp_reply_received != 0) {
            dhcp_step = 0;
            dhcp_state = 2;
            break;
        }
        if ((u32)(now - dhcp_send_time) < 3000) {
            break;
        }
        dhcp_retries_left--;
        if (dhcp_retries_left <= 0) {
            TLobby__sub_80421B3C(dhcp_socket);
            dhcp_socket = -1;
            if (dhcp_state == 1 || dhcp_state == 2 || dhcp_state == 6) {
                lbl_805D7B14 = TLobby__sub_804250A8(0);
            }
            dhcp_state = -1;
            dhcp_step = -1;
            dhcp_error = 6;
            break;
        }
        dhcp_step = 1;
        break;
    }
    return dhcp_state;
}

s32 TLobby__sub_8042455C(void *a) {
    u32 length;
    dhcp_error = 0;
    if (a == 0) {
        dhcp_error = 1;
        return -1;
    }
    length = NetStringLength((const char*)a);
    if ((u16)length < 0x20 && (u16)length != 0) {
        TLobby__sub_80425288(0x10, (u16)length, a);
        return 0;
    }
    dhcp_error = 1;
    return -1;
}

u8 dhcp_hostname[0x2C];
u8 lbl_805C2F94[0x100];
