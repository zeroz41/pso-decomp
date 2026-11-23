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


u16 calc_pseudo_header_checksum(s32 src, s32 dst, s8 proto, void *pkt, s16 flag);

/* Inline the helpers below; this applies to the rest of the file. */
#pragma dont_inline off
#pragma inline_depth(4)

s16 dispatch_by_addr_family(NetPacket *pkt, NetworkAddress *dst, NetworkAddress *src, u8 *ip4_opts, void *ip6_opts,
                            u8 proto) {
    switch (src->family) {
    case 4:
        return AT_IP4_Send(pkt, dst->ipv4, src->ipv4, ip4_opts[0], ip4_opts[1], ip4_opts[2], proto);
    case 6:
        return TLobby__sub_80410A98(pkt, dst->address, src->address, ip6_opts, proto);
    case 0:
    default:
        return -2;
    }
}

u16 TLobby__sub_8040D8F0(u8 *arg0, u8 *arg1, s8 proto, u8 *pkt, s16 flag) {
    NetworkAddress *src = (NetworkAddress *)arg0;
    NetworkAddress *dst = (NetworkAddress *)arg1;
    switch (src->family) {
    case 4:
        return calc_pseudo_header_checksum(src->ipv4, dst->ipv4, proto, pkt, flag);
    case 6:
        return calc_ipv6_pseudo_header_checksum((const IPv6Address *)src->address, (const IPv6Address *)dst->address, proto, (const NetPacket *)pkt, flag);
    case 0:
    default:
        return 0xFFFEU;
    }
}

s16 AT_IP_SetSrcFromDst(Out_8040D95C *out_8040_d95_c, In_8040D95C *in_8040_d95_c) {
    Ipv4Route *rt;
    s16 ok;

    switch (in_8040_d95_c->type) {
    case 4:
        {
        u32 v = out_8040_d95_c->f4;
        if (v != 0) {
            return 0;
        }
        rt = AT_IP4_RouteSearch(in_8040_d95_c->f4, v);
        if (rt == NULL) {
            return -6;
        }
        out_8040_d95_c->type = 4;
        return AT_IP4_SrcAddrSel(&out_8040_d95_c->f4, rt->gateway, rt->iface);
        }
    case 6:
        ok = NetIPv6IsUnspecified((u8 *)&out_8040_d95_c->f4);
        if (ok == 0) {
            return 0;
        }
        {
        Ipv6Route *rt = TLobby__sub_80413264(&in_8040_d95_c->f4, &out_8040_d95_c->f4);
        if (rt == NULL) {
            return -6;
        }
        out_8040_d95_c->type = 6;
        return TLobby__sub_80411F1C(&out_8040_d95_c->f4, &in_8040_d95_c->f4, rt->iface);
        }
    case 0:
    default:
        return -2;
    }
}

s16 TLobby__sub_8040DA54(u8 *dst, u8 *src) {
    NetworkAddress *a = (NetworkAddress *)dst;
    NetworkAddress *b = (NetworkAddress *)src;
    switch (a->family) {
    case 4:
        return AT_IP4_IsReachable(a->ipv4, b->ipv4);
    case 6:
        return TLobby__sub_80413230(a->address, (saddr)b->address);
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

s16 is_multicast_address(NetworkAddress *addr, s16 arg1) {
    switch (addr->family) {
    case 4:
        return NetIPv4IsBroadcast(addr->ipv4, arg1);
    case 6:
        return NetIPv6IsMulticast(addr->address);
    case 0:
    default:
        return 0;
    }
}

s16 is_addr_unspecified(u8 *arg0) {
    NetworkAddress *addr = (NetworkAddress *)arg0;
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
        return TLobby__sub_8040FEE4(a->ipv4, b->ipv4);
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

s16 AT_IP_GetMssFromDstSrc(u8 *remote, u8 *local) {
    NetworkAddress *a = (NetworkAddress *)remote;
    NetworkAddress *b = (NetworkAddress *)local;
    s16 mtu;
    u32 family;
    Ipv4Route *rt4;
    Ipv6Route *rt;
    family = a->family;
    if (b->family != family) {
        return -2;
    }
    switch ((s32)family) {
    case 4:
        rt4 = AT_IP4_RouteSearch(a->ipv4, b->ipv4);
        if (rt4 == NULL) {
            return -6;
        }
        mtu = get_ipv4_interface_mtu(rt4->iface);
        if (mtu < 0x28) {
            return -6;
        }
        return mtu - 0x28;
    case 6:
        rt = TLobby__sub_80413264(a->address, b->address);
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
