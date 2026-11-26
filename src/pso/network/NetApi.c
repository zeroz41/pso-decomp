/* The network stack's socket API and stack bring-up (a C library, built with GC/1.2.5n): stack init/shutdown, the
 * TCP calls (create, bind, connect, send, receive, stat, abort, delete) with their completion and socket-event
 * dispatch, UDP send/receive helpers, and the interface address/route calls. The DHCP client that follows in .text
 * is its own file (NetDhcp.c). */
#include "pso/network/NetworkRuntime.h"
#include "pso/network/UdpRuntime.h"
#include "pso/network/SocketEvents.h"
#include "pso/network/NetTcpState.h"
#include "pso/network/NetworkDispatch.h"
#include "pso/network/NetApi.h"
#include "pso/network/IPv6Send.h"
#include "types.h"
#include "pso/network/NetStack.h"
#include "pso/network/NetIpv6Route.h"

#include <stddef.h>
#include <dolphin/os/OSInterrupt.h>
#include "pso/network/BufferRef.h"
#include "pso/network/NetIpv4.h"
enum SocketHandleTag {
    TCP_SOCKET_TAG = 0,
    UDP_SOCKET_TAG = 0x400,
    SOCKET_TAG_MASK = 0xC00
};

/* What a raw socket callback receives with a packet: the receive prefix and the packet's addresses. */
typedef struct RawIpv4Receive {
    NetworkReceivePrefix receive;
    s32 src; /* the IPv4 source and destination addresses */
    s32 dst;
} RawIpv4Receive;

typedef struct RawIpv6Receive {
    NetworkReceivePrefix receive;
    u8 src[0x10];
    u8 dst[0x10];
} RawIpv6Receive;

LAYOUT_ASSERT(RawIpv6Receive_src_offset, offsetof(RawIpv6Receive, src) == 8);
LAYOUT_ASSERT(RawIpv6Receive_dst_offset, offsetof(RawIpv6Receive, dst) == 0x18);
LAYOUT_ASSERT(RawIpv6Receive_size, sizeof(RawIpv6Receive) == 0x28);


/* The IP options tcp_connect takes (AVE-TCP at_ip_option, see TTcpSocket.cpp): family 4 or 6, then the options. */
typedef struct NetIpOption {
    u32 family;
    u8 opts[0xC];
} NetIpOption;



void deliver_to_receive_callback(NetworkReceiveCallback cb, NetworkReceivePrefix *hdr, NetPacket *pkt);
s32 route4_del(saddr dst, saddr mask, saddr gateway);
s32 route4_add(saddr dst, saddr mask, saddr gateway);
void OSReport(const char *, ...);
/* The avetcp.a version strings; avetcp_init checks the banner's leading '\n' through avetcp_version_banner_ptr. */
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
const char avetcp_version[] = "<< Network SDK - avetcp.a  Ver.1.16.1 build:Oct 23 2002 17:47:54>>\n";
u32 network_stack_init_count;
/* How this API file calls into the TCP, UDP and route modules. These prototypes differ from the definitions
 * (handle width, halfword arguments, result width), and the code here is built against them, so they cannot
 * share a header with the definitions. */
s16 tcp_start_receive(s32 nh, NetBufferRef *destination, s16 len, TcpCompletion callback);
s16 AT_TCP_Connect(s32 nh, NetworkAddress *addr, s16 port);
s32 tcp_pcbbind(s32 nh, NetworkAddress *addr, u16 port);
s16 AT_UDP_Send(s32 nh, NetPacket *pkt, NetworkAddress *src, NetworkAddress *dst, u16 port, UdpSendOptions *opt);
s32 NetIPv4AddRoute(u32 dst, u32 mask, u32 gateway, s16 origin, u8 type, u16 flags);
s16 copy_ipv4_interface_addresses(s16 iface, NetBufferRef *out, s32 len, void *buf);
s16 copy_ipv6_interface_addresses(s16 iface, NetBufferRef *out, s32 len, void *buf);
s32 avetcp_term(void) {
    dispatcher_term();
    handler_table_term();
    NetIPv6ShutdownNeighborDiscovery();
    NetIPv6ShutdownRouting();
    shutdown_ipv4_routing();
    NetIPv6Shutdown();
    ipv4_term();
    fragment_term();
    reset_stack_module();
    tcp_term();
    shutdown_network_handle();
    reset_net_value();
    rtos_term();
    return 0;
}

/* Brings up the network stack subsystems in order, stopping at the first failure (result < 0). */
s16 avetcp_init(void) {
    s16 result;
    if ((s32) *avetcp_version_banner_ptr != '\n') {
        return -1;
    }
    if (network_stack_init_count == 0) {
        OSReport(avetcp_version);
    }
    ++network_stack_init_count;
    result = rtos_init();
    if (result < 0) {
        goto done;
    }
    result = buffer_pool_init();
    if (result < 0) {
        goto undo_rtos;
    }
    result = reset_socket_table();
    if (result < 0) {
        goto undo_buffer_pool;
    }
    result = NetTCPInit();
    if (result < 0) {
        goto undo_socket_table;
    }
    result = init_ucb_entries();
    if (result < 0) {
        goto undo_tcp;
    }
    result = init_packet_fragment_pools();
    if (result < 0) {
        goto undo_ucb;
    }
    result = init_ipv4_interfaces();
    if (result < 0) {
        goto undo_fragments;
    }
    result = NetIPv6Init();
    if (result < 0) {
        goto undo_ipv4;
    }
    result = init_ipv4_routing();
    if (result < 0) {
        goto undo_ipv6;
    }
    result = NetIPv6InitRouting();
    if (result < 0) {
        goto undo_ipv4_routing;
    }
    result = NetIPv6InitNeighborDiscovery();
    if (result < 0) {
        goto undo_ipv6_routing;
    }
    result = handler_table_init();
    if (result < 0) {
        goto undo_neighbor_discovery;
    }
    result = NetInitializeDispatcher();
    if (result >= 0) {
        return 0;
    }
    handler_table_term();
undo_neighbor_discovery:
    NetIPv6ShutdownNeighborDiscovery();
undo_ipv6_routing:
    NetIPv6ShutdownRouting();
undo_ipv4_routing:
    shutdown_ipv4_routing();
undo_ipv6:
    NetIPv6Shutdown();
undo_ipv4:
    ipv4_term();
undo_fragments:
    fragment_term();
undo_ucb:
    reset_stack_module();
undo_tcp:
    tcp_term();
undo_socket_table:
    shutdown_network_handle();
undo_buffer_pool:
    reset_net_value();
undo_rtos:
    rtos_term();
done:
    return result;
}

s32 unlock_at_sem(void) {
    unlock_mutex(network_dispatch_state.lock_handle);
    return 0;
}
s32 lock_at_sem(void) {
    lock_mutex(network_dispatch_state.lock_handle);
    return 0;
}
s32 reset_at_timer(NetTimerCallback timer) {
    s32 result;
    if (timer == 0) {
        return -2;
    }
    lock_mutex(network_dispatch_state.lock_handle);
    result = NetUnregisterTimer(timer);
    unlock_mutex(network_dispatch_state.lock_handle);
    return result;
}

s16 set_at_timer(NetTimerCallback callback, s32 interval) {
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
    RawIpv6Receive s;
    s.receive.socket = index | 0xC00;
    s.receive.len = pkt->total_bytes - pkt->fragments[0].length;
    s.receive.buf = NULL;
    NetMemcpy(s.src, src, 0x10);
    NetMemcpy(s.dst, dst, 0x10);
    if (cb != NULL) {
        deliver_to_receive_callback(cb, &s.receive, pkt);
    }
    return 0;
}

s32 route4_del(saddr dst, saddr mask, saddr gateway) {
    s32 result;
    lock_mutex(network_dispatch_state.lock_handle);
    result = ipv4_route_delete(dst, mask, gateway, 0);
    unlock_mutex(network_dispatch_state.lock_handle);
    return result;
}

s32 route4_add(saddr dst, saddr mask, saddr gateway) {
    s32 result;
    lock_mutex(network_dispatch_state.lock_handle);
    result = NetIPv4AddRoute(dst, mask, gateway, 1, 0, 0);
    unlock_mutex(network_dispatch_state.lock_handle);
    return result;
}

s32 raw_socket_deliver_ipv4(NetPacket *pkt, u32 src, u32 dst, NetworkReceiveCallback cb, s16 flags) {
    LAYOUT_ASSERT(RawIpv4Receive_receive_offset, offsetof(RawIpv4Receive, receive) == 0);
    LAYOUT_ASSERT(RawIpv4Receive_size, sizeof(RawIpv4Receive) == 0x10);
    LAYOUT_ASSERT(RawIpv4Receive_src_offset, offsetof(RawIpv4Receive, src) == 0x8);
    LAYOUT_ASSERT(RawIpv4Receive_dst_offset, offsetof(RawIpv4Receive, dst) == 0xC);
    RawIpv4Receive stack;
    stack.receive.socket = flags | 0x800;
    stack.receive.len = pkt->total_bytes - pkt->fragments[0].length;
    stack.receive.buf = NULL;
    stack.src = src;
    stack.dst = dst;
    if (cb != NULL) {
        deliver_to_receive_callback(cb, &stack.receive, pkt);
    }
    return 0;
}

s32 udp_close(s32 nh) {
    s32 r;
    NetworkDispatchState *g;
    s16 handle;
    if ((nh & SOCKET_TAG_MASK) != UDP_SOCKET_TAG) { return -4; }
    g = &network_dispatch_state;
    handle = nh & ~SOCKET_TAG_MASK;
    lock_mutex(g->lock_handle);
    r = NetUdpClose(handle);
    unlock_mutex(g->lock_handle);
    return r;
}


s16 udp_send(s32 nh, NetworkAddress *src, NetworkAddress *dst, u16 port, UdpSendOptions *opt, s8 count, send_buffs *bufs) {
    NetworkAddress any_addr;
    UdpSendOptions any_opt;
    u16 i;
    NetPacket *pkt;
    s16 r;
    if ((nh & SOCKET_TAG_MASK) != UDP_SOCKET_TAG) {
        return -4;
    }
    nh = nh & ~SOCKET_TAG_MASK;
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
    if (count > 3) {
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
    for (i = count; i != 0; i--) {
        if (bufs[i - 1].len < 0) {
            release_entry(pkt);
            unlock_mutex(network_dispatch_state.lock_handle);
            return -2;
        }
        pkt->total_bytes += bufs[i - 1].len;
        pkt->fragments[pkt->fragment_count].length = bufs[i - 1].len;
        init_packet_header((NetBufferRef *)&pkt->fragments[pkt->fragment_count].buffer, bufs[i - 1].buff);
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
    r = AT_UDP_Send(nh, pkt, src, dst, port, opt);
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

s16 udp_deliver(NetPacket *pkt, NetworkAddress *src, NetworkAddress *dst,
                           u16 port, NetUdpReceiveCallback cb, s16 socket_index) {
    UdpDatagram s;
    s.receive.socket = socket_index | UDP_SOCKET_TAG;
    s.receive.len = pkt->total_bytes - pkt->fragments[0].length;
    s.receive.buf = NULL;
    NetMemcpy(&s.src, src, sizeof(NetworkAddress));
    NetMemcpy(&s.dst, dst, sizeof(NetworkAddress));
    s.port = port;
    if (cb != NULL) {
        deliver_to_receive_callback(cb, &s.receive, pkt);
    }
    return 0;
}

void deliver_to_receive_callback(NetworkReceiveCallback cb, NetworkReceivePrefix *hdr, NetPacket *packet) {
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
        init_packet_header(&pkt, buf);
        for (i = 1; len > 0; i++) {
            if (len > packet->fragments[i].length) {
                chunk = packet->fragments[i].length;
            } else {
                chunk = len;
            }
            netbuf_copy_by_ref(&pkt, &packet->fragments[i].buffer, chunk);
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

s16 tcp_receive(s32 nh, TcpCompletion cb, s32 len, void *buf) {
    NetBufferRef destination;
    s16 r;
    NetworkDispatchState *g;
    TcpTcb *s;
    if (nh & SOCKET_TAG_MASK) {
        return -4;
    }
    g = &network_dispatch_state;
    nh = nh & ~SOCKET_TAG_MASK;
    lock_mutex(g->lock_handle);
    if (validate_tcp_handle(nh) < 0) {
        unlock_mutex(g->lock_handle);
        return -4;
    }
    if (tcp_get_socket_handle(nh) == 1) {
        unlock_mutex(g->lock_handle);
        return -9;
    }
    s = tcp_protocol_state.tcbs;
    s += (s16)nh;
    if (s->waits[0].flags & 3) {
        unlock_mutex(g->lock_handle);
        return -9;
    }
    init_packet_header(&destination, buf);
    NetMemset(&s->waits[0].flags, 0, 8);
    s->waits[0].flags |= 1;
    if (s->flags & 0x40) {
        s->waits[0].flags |= 8;
        r = tcp_start_receive(nh, &destination, len, cb);
        s->waits[0].flags &= ~8;
    } else {
        r = tcp_start_receive(nh, &destination, len, cb);
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

s16 tcp_send(s32 nh, TcpCompletion notify, char bufnum, struct send_buffs *sb) {
    TcpTcb *s;
    NetPacket *entry;
    struct send_buffs *p;
    u8 *cur;
    s16 r;
    s16 n;
    s16 ret;
    if (bufnum > 3) {
        return -2;
    }
    if (nh & SOCKET_TAG_MASK) {
        return -4;
    }
    nh = nh & ~SOCKET_TAG_MASK;
    lock_mutex(network_dispatch_state.lock_handle);
    if (validate_tcp_handle(nh) < 0) {
        unlock_mutex(network_dispatch_state.lock_handle);
        return -4;
    }
    r = tcp_get_socket_handle(nh);
    if (r == -1 || r == 1) {
        unlock_mutex(network_dispatch_state.lock_handle);
        return -9;
    }
    s = tcp_protocol_state.tcbs;
    s += (s16)nh;
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
    /* Each pass advances the packet base by one fragment. */
    cur = (u8 *)entry + (entry->total_bytes = 0) * sizeof(NetPacketFragment);
    while ((u16)n != 0) {
        p--;
        n--;
        if (p->len < 0) {
            release_entry(entry);
            unlock_mutex(network_dispatch_state.lock_handle);
            return -2;
        }
        init_packet_header(&((NetPacketFragment *)(cur + offsetof(NetPacket, fragments)))->buffer, p->buff);
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
        ret = tcp_start_send(nh, entry, notify, 0);
        s->waits[2].flags &= ~8;
    } else {
        ret = tcp_start_send(nh, entry, notify, 0);
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
  s16 nh;
  s += (s16) idx;
  if ((cb != 0) && (!(s->waits[2].flags & 8)))
  {
    nh = (s16) idx;
    cb(state, nh);
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
    r = tcp_set_option(nh, type, opt);
    unlock_mutex(network_dispatch_state.lock_handle);
    return r;
}

s32 tcp_stat(s32 nh, s16 *stat, s16 *backlog, u32 *sendwin, u32 *recvwin) {
    s32 r;
    NetworkDispatchState *g;
    if (nh & SOCKET_TAG_MASK) { return -4; }
    g = &network_dispatch_state;
    nh = nh & ~SOCKET_TAG_MASK;
    lock_mutex(g->lock_handle);
    if (validate_tcp_handle(nh) < 0) {
        unlock_mutex(g->lock_handle);
        return -4;
    }
    r = get_tcp_stat(nh, stat, backlog, sendwin, recvwin);
    unlock_mutex(g->lock_handle);
    return r;
}

s32 tcp_delete(s32 nh) {
    s32 r;
    NetworkDispatchState *g;
    s32 handle;
    if (nh & SOCKET_TAG_MASK) { return -4; }
    g = &network_dispatch_state;
    handle = nh & ~SOCKET_TAG_MASK;
    lock_mutex(g->lock_handle);
    r = mark_connection_closed(handle);
    unlock_mutex(g->lock_handle);
    return r;
}

s32 tcp_abort(s32 nh) {
    s32 r;
    NetworkDispatchState *g;
    s32 handle;
    s16 st;
    if (nh & SOCKET_TAG_MASK) { return -4; }
    g = &network_dispatch_state;
    handle = nh & ~SOCKET_TAG_MASK;
    lock_mutex(g->lock_handle);
    if (validate_tcp_handle(handle) < 0) {
        unlock_mutex(g->lock_handle);
        return -4;
    }
    st = tcp_get_socket_handle(handle);
    if (st == -1 || st == 1) {
        unlock_mutex(network_dispatch_state.lock_handle);
        return -9;
    }
    r = abort_tcp_connection(handle);
    unlock_mutex(g->lock_handle);
    return r;
}

s32 complete_accept_request(s16 idx, TcpAcceptCallback cb, s16 code, NetworkAddress *name, s32 local_port, s32 remote_port) {
    TcpTcb *s = tcp_protocol_state.tcbs;
    s16 i2;
    s16 v;
    s += idx;
    if (cb != NULL && !(s->waits[3].flags & 8)) {
        i2 = (int)idx;
        if (code >= 0) {
            v = (s32)code;
            tcp_unlink_listener(code);
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

s16 tcp_connect(s32 nh, NetworkAddress *addr, u16 port, NetIpOption *opt) {
    NetIpOption tmp;
    s16 r;
    NetworkDispatchState *g;
    void *p;
    if (nh & SOCKET_TAG_MASK) {
        return -4;
    }
    nh = nh & ~SOCKET_TAG_MASK;
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
        p = opt->opts;
        opt = (NetIpOption *)tmp.opts;
        break;
    case 6:
        p = tmp.opts;
        opt = (NetIpOption *)opt->opts;
        break;
    case 5:
    default:
        return -2;
    }
    g = &network_dispatch_state;
    lock_mutex(g->lock_handle);
    if (validate_tcp_handle(nh) < 0) {
        unlock_mutex(g->lock_handle);
        return -4;
    }
    if (tcp_get_socket_handle(nh) != 0) {
        unlock_mutex(g->lock_handle);
        return -9;
    }
    tcp_set_ip_options(nh, p, opt);
    r = AT_TCP_Connect(nh, addr, port);
    unlock_mutex(g->lock_handle);
    return r;
}

s32 tcp_bind(s32 nh, void *addr, u16 port) {
    u8 tmp[0x14];
    s32 r;
    NetworkDispatchState *g;
    if (nh & SOCKET_TAG_MASK) { return -4; }
    nh = nh & ~SOCKET_TAG_MASK;
    if (addr == NULL) {
        NetMemset(tmp, 0, 0x14);
        addr = tmp;
    }
    g = &network_dispatch_state;
    lock_mutex(g->lock_handle);
    if (validate_tcp_handle(nh) < 0) {
        unlock_mutex(g->lock_handle);
        return -4;
    }
    if (tcp_get_socket_handle(nh) != 0) {
        unlock_mutex(g->lock_handle);
        return -9;
    }
    r = tcp_pcbbind(nh, addr, port);
    unlock_mutex(g->lock_handle);
    return r;
}

s16 tcp_create(void) {
    s16 handle;
    lock_mutex(network_dispatch_state.lock_handle);
    handle = tcp_alloc_tcb();
    unlock_mutex(network_dispatch_state.lock_handle);
    return handle;
}

void NetDispatchSocketEvent(s16 handle, NetSocketEventCallback callback, s32 protocol, s16 event) {
    s16 validate_tcp_handle(s16 handle);
    TcpTcb *s;
    switch ((s16)protocol) {
    case 1:
        handle |= 0x800;
        break;
    case 6:
        handle |= 0xC00;
        break;
    case 2:
        handle |= UDP_SOCKET_TAG;
        break;
    case 3:
        if (validate_tcp_handle(handle) < 0) {
            return;
        }
        s = tcp_protocol_state.tcbs;
        s += handle;
        if ((u16)(event - 10) <= 1 || event == 4) {
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
    if (callback != NULL) {
        callback(handle, event);
    }
}

s16 if_get(s16 iface, void *hdr_src, s32 len, void *buf) {
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
    first = copy_ipv4_interface_addresses(iface, &ref, len, buf);
    if (first > 0) {
        total = first;
        len -= first * 0x1C;
    }
    second = copy_ipv6_interface_addresses(iface, &ref, len, buf);
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
        tmp2 = bring_down_ipv6_interface(idx);
        if (tmp2 < 0) {
            result = tmp2;
        }
        break;
    case 4:
        result = bring_down_ipv4_interface(idx);
        break;
    case 6:
        result = bring_down_ipv6_interface(idx);
        break;
    default:
        result = -2;
        break;
    }
    OSRestoreInterrupts(level);
    unlock_mutex(network_dispatch_state.lock_handle);
    return result;
}

s16 if_config(s16 iface, IfConfigRequest *req) {
    s16 result;
    s32 intr;
    if (iface < 0) {
        return -2;
    }
    lock_mutex(network_dispatch_state.lock_handle);
    intr = OSDisableInterrupts();
    switch (req->family) {
    case 4:
        result = AT_IP4_IfUp(req->ipv4.addr, req->ipv4.mask, req->ipv4.broadcast, iface);
        break;
    case 6:
        if (req->ipv6.prefix_len < 0 || req->ipv6.prefix_len > 0x80) {
            result = -2;
        } else {
            result = bring_up_ipv6_interface(req->ipv6.addr, req->ipv6.prefix_len, req->ipv6.flags, iface, req->ipv6.callback);
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

s16 invoke_routing_event_callback(s16 iface, s32 event, void *data, Ipv6EventCallback fn) {
    s16 r = 0;
    if (fn != NULL) {
        r = fn(iface, event, data);
    }
    return r;
}
