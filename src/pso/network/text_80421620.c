/* The network stack's socket API and stack bring-up (a C library, built with GC/1.2.5n): stack init/shutdown, the
 * TCP calls (create, bind, connect, send, receive, stat, abort, delete) with their completion and socket-event
 * dispatch, UDP send/receive helpers, and the interface address/route calls. The DHCP client that follows in .text
 * is its own file (NetDhcp.c). */
#include "pso/network/NetworkRuntime.h"
#include "pso/network/UdpRuntime.h"
#include "pso/network/SocketEvents.h"
#include "pso/network/NetTcpState.h"
#include "pso/network/NetworkDispatch.h"
#include "pso/network/text_80421620.h"
#include "pso/network/IPv6Send.h"
#include "types.h"
#include "pso/network/TLobby_804050DC.h"
#include "pso/network/TLobby_8041112C.h"

#include <stddef.h>
#include "pso/network/BufferRef.h"
enum SocketHandleTag {
    TCP_SOCKET_TAG = 0,
    UDP_SOCKET_TAG = 0x400,
    SOCKET_TAG_MASK = 0xC00
};

typedef struct Stack_80421AD8 {
    NetworkReceivePrefix receive;
    s32 sp24;
    s32 sp28;
} Stack_80421AD8;

typedef struct Stack_80421938 {
    NetworkReceivePrefix receive;
    u8 src[0x10];
    u8 dst[0x10];
} Stack_80421938;

LAYOUT_ASSERT(Stack_80421938_src_offset, offsetof(Stack_80421938, src) == 8);
LAYOUT_ASSERT(Stack_80421938_dst_offset, offsetof(Stack_80421938, dst) == 0x18);
LAYOUT_ASSERT(Stack_80421938_size, sizeof(Stack_80421938) == 0x28);


typedef struct IpAddr_80422B8C { u32 family; u8 a[0xC]; } IpAddr_80422B8C;

typedef struct P_8042315C { s32 type; s32 a; s32 b; s32 c; s32 pad10; s16 n; s16 m; s32 d; s32 pad1C; } P_8042315C;


s32 TLobby__sub_8041112C(void);
void NetIPv6ShutdownNeighborDiscovery(void);
s32 TLobby__sub_80418A7C(void);
s32 TLobby__sub_8041A1D8(void);
void TLobby__sub_80421FB8(NetworkReceiveCallback cb, NetworkReceivePrefix *hdr, NetPacket *pkt);
s32 TLobby__sub_8040F9CC(void *, void *, void *, int);
s32 route4_del(saddr dst, saddr mask, saddr gateway);
s32 NetIPv4AddRoute(void *, void *, void *, s16, u8, u16); /* declared s32 here; the definition is s16 (u32, u32, u32, s16, u8, u16) */
s32 route4_add(saddr dst, saddr mask, saddr gateway);
s32 mark_connection_closed(s32);
s16 TLobby__sub_8041DE1C(s16, s16, u32 *); /* declared s16 here; the definition returns s32 */
void TLobby__sub_8041E590(s16);
s32 get_tcp_stat(int, void *, void *, void *, void *);
s16 validate_tcp_handle(int);
s32 tcp_stat(s32 a, s16 *b, s16 *c, u32 *d, u32 *e);
s16 tcp_get_socket_handle(int);
s32 abort_tcp_connection(int);
void OSReport(const char *, ...);
s16 reset_socket_table();
s16 TLobby__sub_80409AD8();
s16 init_ipv4_interfaces();
s16 init_ipv4_routing();
s16 NetIPv6Init();
s16 TUdpSocket__sub_8041118C();
s16 NetIPv6InitNeighborDiscovery();
s16 init_packet_fragment_pools();
s16 NetTCPInit();
/* inferred: the avetcp.a version strings (names from their contents); avetcp_init checks the banner's
   leading '\n' through avetcp_version_banner_ptr */
const u8 avetcp_version_banner[] =
    "\nAVE-TCPv6.0 for GC Ver 1.16.1 Build:Oct 23 2002 17:47:54 SDKVER 12Dec2001Patch3\n";
const char avetcp_sdk_release[] = "AVE-TCPv6.0 SDK Release 2.0";
const char avetcp_copyright[] =
    "Copyright (C) 1992-2001 ACCESS CO.,LTD. All rights are reserved by ACCESS CO.,LTD., whether the whole or part "
    "of the source code including any modifications is concerned. ";
const char avetcp_build_date[] = "Built on Oct 23 2002 17:47:54.";
const char avetcp_module_list[] =
    "The AVE-TCPv6.0 contains loopback dix arp ppp ipv4 ipv4_forward ipv6 ipv6_forward tcp_fast_recovery "
    "tcp_keep_ooo_segment tcp_sack tcp_large_window dns module(s).";
const u8 *const avetcp_version_banner_ptr = avetcp_version_banner;
const char lbl_804800F0[] = "<< Network SDK - avetcp.a  Ver.1.16.1 build:Oct 23 2002 17:47:54>>\n";
u32 network_stack_init_count;
/* This C library caller passes a full register for the handle and a signed halfword length. */
s16 TLobby__sub_8041DBD4(s32 handle, NetBufferRef *destination, s16 len, TcpCompletion callback);
void TLobby__sub_8041E2EC(int, void *, void *); /* declared here with an s32 1st argument; the definition takes s16 */
s32 AT_TCP_Connect(int, void *, s16); /* declared here with an s32 return and 1st argument; the definition is s16 (s16, void *, s16) */
s32 tcp_connect(s32 a, IpAddr_80422B8C *addr, u16 port, IpAddr_80422B8C *opt);
s32 TLobby__sub_8041E5E4(int, void *, u16);
s16 copy_ipv4_interface_addresses(s16, void *, int, void *); /* declared s16 here; the definition is s32 (s16, NetBufferRef *, s16, s32) */
s16 TLobby__sub_80412058(s16, void *, int, void *);
s16 TLobby__sub_80422F70(s16 arg0, s32 hdr_src, s32 len, saddr arg3);
s32 OSDisableInterrupts();
s32 OSRestoreInterrupts(int);
s16 bring_down_ipv4_interface(s16);
s16 TLobby__sub_80412210(s16);
s16 AT_IP4_IfUp(s32, s32, s32, s16);
s16 TLobby__sub_80412CA4(void *, s16, s16, s16, s32);
s16 if_config(s16 arg0, P_8042315C *p);
s32 avetcp_term(void) {
    TLobby__sub_80419A7C();
    TLobby__sub_80409AA8();
    NetIPv6ShutdownNeighborDiscovery();
    TLobby__sub_8041112C();
    shutdown_ipv4_routing();
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
s16 avetcp_init(void) {
    s16 init_ucb_entries(void);
    s16 result;
    if ((s32) *avetcp_version_banner_ptr != 0xA) {
        return -1;
    }
    if ((u32) network_stack_init_count == 0U) {
        OSReport(lbl_804800F0);
    }
    ++network_stack_init_count;
    result = TLobby__sub_80419A34();
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
                                    result = init_ipv4_routing();
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
                                        shutdown_ipv4_routing();
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

s32 net_unlock(void) {
    unlock_mutex(network_dispatch_state.lock_handle);
    return 0;
}
s32 net_lock(void) {
    lock_mutex(network_dispatch_state.lock_handle);
    return 0;
}
s32 net_unregister_timer(NetTimerCallback timer) {
    s32 result;
    if (timer == 0) {
        return -2;
    }
    lock_mutex(network_dispatch_state.lock_handle);
    result = NetUnregisterTimer(timer);
    unlock_mutex(network_dispatch_state.lock_handle);
    return result;
}

s16 net_register_timer(NetTimerCallback callback, s32 interval) {
    s16 result;
    if (callback == 0) {
        return -2;
    }
    if (interval <= 0) {
        return -2;
    }
    lock_mutex(network_dispatch_state.lock_handle);
    result = NetRegisterTimer(interval, 0, callback);
    unlock_mutex(network_dispatch_state.lock_handle);
    return result;
}

s32 raw_socket_deliver(NetPacket *pkt, u8 *src, u8 *dst, NetworkReceiveCallback cb, s16 index) {
    Stack_80421938 s;
    s.receive.socket = index | 0xC00;
    s.receive.len = pkt->total_bytes - pkt->fragments[0].length;
    s.receive.buf = NULL;
    NetMemcpy(s.src, src, 0x10);
    NetMemcpy(s.dst, dst, 0x10);
    if (cb != NULL) {
        TLobby__sub_80421FB8(cb, &s.receive, pkt);
    }
    return 0;
}

s32 route4_del(saddr dst, saddr mask, saddr gateway) {
    s32 result;
    lock_mutex(network_dispatch_state.lock_handle);
    result = TLobby__sub_8040F9CC((void *)dst, (void *)mask, (void *)gateway, 0);
    unlock_mutex(network_dispatch_state.lock_handle);
    return result;
}

s32 route4_add(saddr dst, saddr mask, saddr gateway) {
    s32 result;
    lock_mutex(network_dispatch_state.lock_handle);
    result = NetIPv4AddRoute((void *)dst, (void *)mask, (void *)gateway, 1, (int) (0U), (int) (0U));
    unlock_mutex(network_dispatch_state.lock_handle);
    return result;
}

s32 raw_socket_deliver_ipv4(NetPacket *pkt, u32 src, u32 dst, NetworkReceiveCallback cb, s16 flags) {
    LAYOUT_ASSERT(Stack_80421AD8_receive_offset, offsetof(Stack_80421AD8, receive) == 0);
    LAYOUT_ASSERT(Stack_80421AD8_size, sizeof(Stack_80421AD8) == 0x10);
    LAYOUT_ASSERT(sp24_offset, offsetof(Stack_80421AD8, sp24) == 0x8);
    LAYOUT_ASSERT(sp28_offset, offsetof(Stack_80421AD8, sp28) == 0xC);
    Stack_80421AD8 stack;
    stack.receive.socket = flags | 0x800;
    stack.receive.len = pkt->total_bytes - pkt->fragments[0].length;
    stack.receive.buf = NULL;
    stack.sp24 = src;
    stack.sp28 = dst;
    if (cb != NULL) {
        TLobby__sub_80421FB8(cb, &stack.receive, pkt);
    }
    return 0;
}

s32 udp_close(s32 a) {
    s32 r;
    NetworkDispatchState *g;
    s16 m;
    if ((a & SOCKET_TAG_MASK) != UDP_SOCKET_TAG) { return -4; }
    g = &network_dispatch_state;
    m = a & ~SOCKET_TAG_MASK;
    lock_mutex(g->lock_handle);
    r = NetUdpClose(m);
    unlock_mutex(g->lock_handle);
    return r;
}

s16 AT_UDP_Send(s32 id, NetPacket *pkt, NetworkAddress *src, NetworkAddress *dst, u16 port, UdpSendOptions *opt); /* declared here with an s32 handle; the definition takes s16 */

s16 udp_send(s32 h, NetworkAddress *src, NetworkAddress *dst, u16 port, UdpSendOptions *opt, s8 n, send_buffs *bufs) {
    NetworkAddress any_addr;
    UdpSendOptions any_opt;
    u16 i;
    NetPacket *pkt;
    s16 r;
    if ((h & SOCKET_TAG_MASK) != UDP_SOCKET_TAG) {
        return -4;
    }
    h = h & ~SOCKET_TAG_MASK;
    NetMemset(&any_addr, 0, sizeof(NetworkAddress));
    if (dst != NULL) {
        if (dst->family == 0) {
            return -2;
        }
    } else {
        dst = &any_addr;
    }
    if (src == NULL) {
        src = &any_addr;
    }
    if (opt != NULL && opt->family != 0) {
        if (opt->family != dst->family) {
            return -2;
        }
    } else {
        NetMemset(&any_opt, 0, sizeof(UdpSendOptions));
        opt = &any_opt;
    }
    lock_mutex(network_dispatch_state.lock_handle);
    if (n > 3) {
        unlock_mutex(network_dispatch_state.lock_handle);
        return -2;
    }
    pkt = alloc_free_entry();
    if (pkt == NULL) {
        unlock_mutex(network_dispatch_state.lock_handle);
        return -0x101;
    }
    pkt->fragment_count = 0;
    pkt->total_bytes = 0;
    for (i = n; i != 0; i--) {
        if (bufs[i - 1].len < 0) {
            release_entry(pkt);
            unlock_mutex(network_dispatch_state.lock_handle);
            return -2;
        }
        pkt->total_bytes += bufs[i - 1].len;
        pkt->fragments[pkt->fragment_count].length = bufs[i - 1].len;
        init_packet_header((NetBufferRef *)&pkt->fragments[pkt->fragment_count].buffer, (saddr)bufs[i - 1].buff);
        pkt->fragment_count++;
    }
    if (pkt->total_bytes > 0x7FE3) {
        release_entry(pkt);
        unlock_mutex(network_dispatch_state.lock_handle);
        return -2;
    }
    if (pkt->total_bytes == 0) {
        release_entry(pkt);
        unlock_mutex(network_dispatch_state.lock_handle);
        return 0;
    }
    r = AT_UDP_Send(h, pkt, src, dst, port, opt);
    release_entry(pkt);
    unlock_mutex(network_dispatch_state.lock_handle);
    return r;
}

s16 udp_open(void *src, s32 sport, void *dst, s32 dport, NetSocketEventCallback eventCallback, NetUdpReceiveCallback cb) {
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
    r = NetUdpConnect(h, (NetworkAddress*)dst, dport, eventCallback, cb);
    if (r < 0) {
        NetUdpClose(h);
        unlock_mutex(network_dispatch_state.lock_handle);
        return r;
    }
    h |= UDP_SOCKET_TAG;
    unlock_mutex(network_dispatch_state.lock_handle);
    return h;
}

s16 TLobby__sub_80421F10(NetPacket *pkt, NetworkAddress *src, NetworkAddress *dst,
                           u16 port, NetUdpReceiveCallback cb, s16 socket_index) {
    UdpDatagram s;
    s.receive.socket = socket_index | UDP_SOCKET_TAG;
    s.receive.len = pkt->total_bytes - pkt->fragments[0].length;
    s.receive.buf = NULL;
    NetMemcpy(&s.src, src, sizeof(NetworkAddress));
    NetMemcpy(&s.dst, dst, sizeof(NetworkAddress));
    s.port = port;
    if (cb != NULL) {
        TLobby__sub_80421FB8(cb, &s.receive, pkt);
    }
    return 0;
}

void TLobby__sub_80421FB8(NetworkReceiveCallback cb, NetworkReceivePrefix *hdr, NetPacket *o) {
    s32 i;
    u8 *buf;
    s16 len;
    NetBufferRef pkt;
    s16 chunk;
    len = hdr->len;
    if (cb(0, hdr) == 0) {
        if (hdr->len >= len) {
            hdr->len = len;
        }
        len = hdr->len;
        if (len == 0 || hdr->buf == NULL) {
            return;
        }
        buf = hdr->buf;
        init_packet_header(&pkt, (saddr)buf);
        for (i = 1; len > 0; i++) {
            if (len > o->fragments[i].length) {
                chunk = o->fragments[i].length;
            } else {
                chunk = len;
            }
            netbuf_copy_by_ref(&pkt, &o->fragments[i].buffer, chunk);
            netbuf_ref_advance(&pkt, (u32)chunk);
            len -= chunk;
        }
        cb(1, hdr);
    }
}

s32 complete_request_callback(s16 handle, TcpSendCallback cb, s16 code, const TcpSendRequest *request) {
    s32 idx = handle;
    TcpTcb *s = tcp_protocol_state.tcbs;
    s += idx;
    if (cb != NULL && !(s->waits[1].flags & 8)) {
        cb(code, idx, request->buffer.value);
    } else if (!(s->waits[2].flags & 4)) {
        s->waits[1].status = code;
        s->waits[2].flags |= 4;
        s->send_done = 0;
    }
    s->waits[1].count--;
    return 0;
}

s16 tcp_receive(s32 a, TcpCompletion cb, s32 len, void *buf) {
    NetBufferRef destination;
    s16 r;
    NetworkDispatchState *g;
    TcpTcb *s;
    if (a & SOCKET_TAG_MASK) {
        return -4;
    }
    g = &network_dispatch_state;
    a = a & ~SOCKET_TAG_MASK;
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
    init_packet_header(&destination, (saddr)buf);
    NetMemset(&s->waits[0].flags, 0, 8);
    s->waits[0].flags |= 1;
    if (s->flags & 0x40) {
        s->waits[0].flags |= 8;
        r = TLobby__sub_8041DBD4(a, &destination, len, cb);
        s->waits[0].flags &= ~8;
    } else {
        r = TLobby__sub_8041DBD4(a, &destination, len, cb);
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

s32 set_slot_state_and_resume(s16 idx, TcpCompletion cb, s16 state) {
  TcpTcb *s = tcp_protocol_state.tcbs;
  s16 socket;
  s += idx;
  if ((cb != 0) && (!(s->waits[0].flags & 8)))
  {
    socket = (s16)(idx | TCP_SOCKET_TAG);
    cb(state, socket);
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

s16 tcp_send(s32 a, TcpCompletion notify, char bufnum, struct send_buffs *sb) {
    TcpTcb *s;
    NetPacket *entry;
    struct send_buffs *p;
    u8 *cur;
    s16 r;
    s16 n;
    s16 ret;
    s16 tcp_start_send(s32, NetPacket *, void (*)(s16, s16), u8); /* declared here with an s32 handle; the definition takes an s16 handle */
    if (bufnum > 3) {
        return -2;
    }
    if (a & SOCKET_TAG_MASK) {
        return -4;
    }
    a = a & ~SOCKET_TAG_MASK;
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
    entry = alloc_free_entry();
    if (entry == NULL) {
        unlock_mutex(network_dispatch_state.lock_handle);
        return -0x101;
    }
    entry->fragment_count = (u16)bufnum;
    n = bufnum;
    p = sb + (u16)n;
    /* The matching loop advances the packet base by one fragment at a time. */
    cur = (u8 *)entry + (entry->total_bytes = 0) * sizeof(NetPacketFragment);
    while ((u16)n != 0) {
        p--;
        n--;
        if (p->len < 0) {
            release_entry(entry);
            unlock_mutex(network_dispatch_state.lock_handle);
            return -2;
        }
        init_packet_header(&((NetPacketFragment *)(cur + offsetof(NetPacket, fragments)))->buffer, (saddr)p->buff);
        ((NetPacketFragment *)(cur + offsetof(NetPacket, fragments)))->length = p->len;
        entry->total_bytes += ((NetPacketFragment *)(cur + offsetof(NetPacket, fragments)))->length;
        cur += sizeof(NetPacketFragment);
    }
    if (entry->total_bytes == 0) {
        release_entry(entry);
        unlock_mutex(network_dispatch_state.lock_handle);
        return -2;
    }
    NetMemset(&s->waits[2].flags, 0, 8);
    s->waits[2].flags |= 1;
    if (s->flags & 0x40) {
        s->waits[2].flags |= 8;
        ret = tcp_start_send(a, entry, notify, 0);
        s->waits[2].flags &= ~8;
    } else {
        ret = tcp_start_send(a, entry, notify, 0);
    }
    release_entry(entry);
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

s32 set_thread_state_and_resume(s32 idx, TcpCompletion cb, s16 state) {
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
    if (nh & SOCKET_TAG_MASK) {
        return -2;
    }
    nh &= ~SOCKET_TAG_MASK;
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
    if (a & SOCKET_TAG_MASK) { return -4; }
    g = &network_dispatch_state;
    a = a & ~SOCKET_TAG_MASK;
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
    if (a & SOCKET_TAG_MASK) { return -4; }
    g = &network_dispatch_state;
    m = a & ~SOCKET_TAG_MASK;
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
    if (a & SOCKET_TAG_MASK) { return -4; }
    g = &network_dispatch_state;
    m = a & ~SOCKET_TAG_MASK;
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

s32 TLobby__sub_80422AB8(s16 idx, TcpAcceptCallback cb, s16 code, s32 name, s32 local_port, s32 remote_port) {
    TcpTcb *s = tcp_protocol_state.tcbs;
    s16 i2;
    s16 v;
    s += idx;
    if (cb != NULL && !(s->waits[3].flags & 8)) {
        i2 = (int)idx;
        if (code >= 0) {
            v = (s32)code;
            TLobby__sub_8041E590(code);
        } else {
            v = code;
        }
        cb(v, i2, name, remote_port);
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
    if (a & SOCKET_TAG_MASK) {
        return -4;
    }
    a = a & ~SOCKET_TAG_MASK;
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
    r = AT_TCP_Connect(a, addr, port);
    unlock_mutex(g->lock_handle);
    return r;
}

s32 tcp_bind(s32 a, void *addr, u16 port) {
    u8 tmp[0x14];
    s32 r;
    NetworkDispatchState *g;
    if (a & SOCKET_TAG_MASK) { return -4; }
    a = a & ~SOCKET_TAG_MASK;
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

s16 tcp_create(void) {
    s16 handle;
    lock_mutex(network_dispatch_state.lock_handle);
    handle = TLobby__sub_8041E780();
    unlock_mutex(network_dispatch_state.lock_handle);
    return handle;
}

void NetDispatchSocketEvent(s16 v, NetSocketEventCallback cb, s32 type, s16 code) {
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
        v |= UDP_SOCKET_TAG;
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
    if (cb != NULL) {
        cb(v, code);
    }
}

s16 TLobby__sub_80422F70(s16 iface, s32 hdr_src, s32 len, saddr buf) {
    NetBufferRef ref;
    s16 first;
    s16 second;
    s16 total;
    if (iface < 0) {
        return -2;
    }
    total = 0;
    lock_mutex(network_dispatch_state.lock_handle);
    init_packet_header(&ref, hdr_src);
    first = copy_ipv4_interface_addresses(iface, &ref, (int)len, (void *)buf);
    if (first > 0) {
        total = first;
        len -= first * 0x1C;
    }
    second = TLobby__sub_80412058(iface, &ref, (int)len, (void *)buf);
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

s16 if_down(s16 idx, s32 op) {
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
        tmp = bring_down_ipv4_interface(idx);
        if (tmp < 0) {
            result = tmp;
        }
        tmp2 = TLobby__sub_80412210(idx);
        if (tmp2 < 0) {
            result = tmp2;
        }
        break;
    case 4:
        result = bring_down_ipv4_interface(idx);
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

s16 if_config(s16 iface, P_8042315C *p) {
    s16 result;
    s32 intr;
    if (iface < 0) {
        return -2;
    }
    lock_mutex(network_dispatch_state.lock_handle);
    intr = OSDisableInterrupts();
    switch (p->type) {
    case 4:
        result = AT_IP4_IfUp(p->a, p->b, p->c, iface);
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
