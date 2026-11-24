#include "pso/network/UdpRuntime.h"
#include "pso/network/SocketEvents.h"
#include "pso/network/NetworkDispatch.h"
#include "pso/network/NetworkRuntime.h"
#include "pso/network/TLobby_804048E8.h"
#include "pso/network/TLobby_804050DC.h"
#include "pso/network/TLobby_803FC178.h"
#include "pso/network/NetworkPacketPool.h"
#include "pso/network/netcfg.h"
#include "pso/network/BufferRef.h"
#include "pso/network/IPv6.h"

#include "types.h"
#include "pso/network/NetworkTransport.h"
#include "pso/network/TLobby_803FAEA0.h"
#include "pso/network/TLobby_803FCF44.h"
#include "pso/network/TLobby_8041112C.h"
#include "pso/network/text_80421620.h"
#include "pso/network/IPv6Send.h"
#include "pso/network/NetStackTypes.h"
#include "pso/network/NetIpv4.h"
#include <stddef.h>


u16 calc_pseudo_header_checksum(s32 src, s32 dst, s8 proto, NetPacket *pkt, s16 flag);

/* Inline the helpers below; this applies to the rest of the file. */
#pragma dont_inline off
#pragma inline_depth(4)

s16 dispatch_by_addr_family(NetPacket *pkt, NetworkAddress *dst, NetworkAddress *src, u8 *ip4_opts, void *ip6_opts,
                            u8 proto) {
    switch (src->family) {
    case 4:
        return AT_IP4_Send(pkt, dst->ipv4, src->ipv4, ip4_opts[0], ip4_opts[1], ip4_opts[2], proto);
    case 6:
        return ipv6_output(pkt, dst->address, src->address, ip6_opts, proto);
    case 0:
    default:
        return -2;
    }
}

u16 calc_transport_checksum(NetworkAddress *src, NetworkAddress *dst, s8 proto, NetPacket *pkt, s16 flag) {
    switch (src->family) {
    case 4:
        return calc_pseudo_header_checksum(src->ipv4, dst->ipv4, proto, pkt, flag);
    case 6:
        return calc_ipv6_pseudo_header_checksum((const IPv6Address *)src->address, (const IPv6Address *)dst->address, proto, pkt, flag);
    case 0:
    default:
        return 0xFFFEU;
    }
}

s16 AT_IP_SetSrcFromDst(NetworkAddress *src, NetworkAddress *dst) {
    Ipv4Route *rt;
    s16 ok;

    switch (dst->family) {
    case 4:
        {
        u32 v = src->ipv4;
        if (v != 0) {
            return 0;
        }
        rt = AT_IP4_RouteSearch(dst->ipv4, v);
        if (rt == NULL) {
            return -6;
        }
        src->family = 4;
        return AT_IP4_SrcAddrSel(&src->ipv4, rt->gateway, rt->iface);
        }
    case 6:
        ok = NetIPv6IsUnspecified(src->address);
        if (ok == 0) {
            return 0;
        }
        {
        Ipv6Route *rt = NetIPv6LookupRoute(dst->address, src->address);
        if (rt == NULL) {
            return -6;
        }
        src->family = 6;
        return NetIPv6SelectSourceAddress(src->address, dst->address, rt->iface);
        }
    case 0:
    default:
        return -2;
    }
}

s16 AT_IP_IsReachable(NetworkAddress *dst, NetworkAddress *src) {
    switch (dst->family) {
    case 4:
        return AT_IP4_IsReachable(dst->ipv4, src->ipv4);
    case 6:
        return NetIPv6IsReachable(dst->address, (saddr)src->address);
    default:
    case 0:
        return -2;
    }
}

s16 NetValidateLocalAddress(NetworkAddress* address) {
    u32 ip;
    switch ((s32)address->family) {
    case 0:
        return 0;
    case 4:
        ip = address->ipv4;
        if (ip != 0) {
            return ipv4_iface_for_address(ip);
        }
        return 0;
    case 6:
        return ipv6_iface_for_address(address->address);
    default:
        return -2;
    }
}

s16 is_multicast_address(NetworkAddress *addr, s16 iface) {
    switch (addr->family) {
    case 4:
        return NetIPv4IsBroadcast(addr->ipv4, iface);
    case 6:
        return NetIPv6IsMulticast(addr->address);
    case 0:
    default:
        return 0;
    }
}

s16 is_addr_unspecified(NetworkAddress *addr) {
    switch (addr->family) {
    case 0:
        return 1;
    case 4:
        return NetIPv4IsUnspecified(addr->ipv4);
    case 6:
        return NetIPv6IsUnspecified(addr->address);
    default:
        return 0;
    }
}

s16 compare_sockaddr(NetworkAddress *a, NetworkAddress *b) {
    switch (a->family) {
    case 4:
        if (b->family != 4) {
            return -1;
        }
        return compare_ipv4_addr(a->ipv4, b->ipv4);
    case 6:
        if (b->family != 6) {
            return -1;
        }
        return NetIPv6CompareAddresses(a->address, b->address);
    default:
    case 0:
        return -1;
    }
}

s16 AT_IP_GetMssFromDstSrc(NetworkAddress *remote, NetworkAddress *local) {
    s16 mtu;
    u32 family;
    Ipv4Route *rt4;
    Ipv6Route *rt;
    family = remote->family;
    if (local->family != family) {
        return -2;
    }
    switch ((s32)family) {
    case 4:
        rt4 = AT_IP4_RouteSearch(remote->ipv4, local->ipv4);
        if (rt4 == NULL) {
            return -6;
        }
        mtu = get_ipv4_interface_mtu(rt4->iface);
        if (mtu < 0x28) {
            return -6;
        }
        return mtu - 0x28;
    case 6:
        rt = NetIPv6LookupRoute(remote->address, local->address);
        if (rt == NULL) {
            return -6;
        }
        mtu = get_iface_mtu(rt->iface);
        if (mtu < 0x3C) {
            return -6;
        }
        return mtu - 0x3C;
    case 0:
    default:
        return -2;
    }
}
