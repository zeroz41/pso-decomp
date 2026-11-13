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

s16 dispatch_by_addr_family(s32 arg0, NetworkAddress *arg1, NetworkAddress *arg2, u8 *arg3, void *arg4, void *arg5) {
    switch (arg2->family) {
    case 4:
        return TLobby__sub_8040E780((u8 *)arg0, arg1->ipv4, arg2->ipv4, arg3[0], arg3[1], arg3[2], arg5);
    case 6:
        return TLobby__sub_80410A98(arg0, arg1->address, arg2->address, arg4, arg5);
    case 0:
    default:
        return -2;
    }
}

u16 TLobby__sub_8040D8F0(u8 *arg0, u8 *arg1, s8 arg2, u8 *pkt, s16 flag) {
    NetworkAddress *src = (NetworkAddress *)arg0;
    NetworkAddress *dst = (NetworkAddress *)arg1;
    switch (src->family) {
    case 4:
        return calc_pseudo_header_checksum(src->ipv4, dst->ipv4, arg2, pkt, flag);
    case 6:
        return TLobby__sub_80411040((const IPv6Address *)src->address, (const IPv6Address *)dst->address, arg2, (const NetPacket *)pkt, flag);
    case 0:
    default:
        return 0xFFFEU;
    }
}

s16 select_source_address(Out_8040D95C *arg0, In_8040D95C *arg1) {
    Ipv4Route *rt;
    s16 ok;

    switch (arg1->type) {
    case 4:
        {
        u32 v = arg0->f4;
        if (v != 0) {
            return 0;
        }
        rt = (Ipv4Route *)TLobby__sub_8040F76C(arg1->f4, v);
        if (rt == NULL) {
            return -6;
        }
        arg0->type = 4;
        return TLobby__sub_8040EF50(&arg0->f4, rt->gateway, rt->iface);
        }
    case 6:
        ok = NetIPv6IsUnspecified((u8 *)&arg0->f4);
        if (ok == 0) {
            return 0;
        }
        {
        Ipv6Route *rt = TLobby__sub_80413264(&arg1->f4, &arg0->f4);
        if (rt == NULL) {
            return -6;
        }
        arg0->type = 6;
        return TLobby__sub_80411F1C(&arg0->f4, &arg1->f4, rt->iface);
        }
    case 0:
    default:
        return -2;
    }
}

s16 TLobby__sub_8040DA54(u8 *arg0, u8 *arg1) {
    NetworkAddress *a = (NetworkAddress *)arg0;
    NetworkAddress *b = (NetworkAddress *)arg1;
    switch (a->family) {
    case 4:
        return is_lookup_found(a->ipv4, b->ipv4);
    case 6:
        return TLobby__sub_80413230(a->address, (s32)b->address);
    default:
    case 0:
        return -2;
    }
}

s16 NetValidateLocalAddress(NetworkAddress* address) {
    s16 TLobby__sub_804136EC(s32);
    u32 ip;
    switch ((s32)address->family) {
    case 0:
        return 0;
    case 4:
        ip = address->ipv4;
        if (ip != 0) {
            return TLobby__sub_8040FCEC(ip);
        }
        return 0;
    case 6:
        return TLobby__sub_804136EC((s32)address->address);
    default:
        return -2;
    }
}

s16 is_multicast_address(void *self, s16 arg1) {
    NetworkAddress *addr = (NetworkAddress *)self;
    switch (addr->family) {
    case 4:
        return TLobby__sub_8040FDA0(addr->ipv4, arg1);
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

s32 compare_sockaddr(NetworkAddress *a, NetworkAddress *b) {
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
        return NetIPv6CompareAddresses((s32)a->address, (s32)b->address);
    default:
    case 0:
        return -1;
    }
}

s16 TLobby__sub_8040DC8C(u8 *arg0, u8 *arg1) {
    s16 TLobby__sub_8040EF00(s16); /* declared s16 here; the definition returns s32 */
    NetworkAddress *a = (NetworkAddress *)arg0;
    NetworkAddress *b = (NetworkAddress *)arg1;
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
        rt4 = (Ipv4Route *)TLobby__sub_8040F76C(a->ipv4, b->ipv4);
        if (rt4 == NULL) {
            return -6;
        }
        mtu = TLobby__sub_8040EF00(rt4->iface);
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
