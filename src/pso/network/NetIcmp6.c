#include "types.h"
#include "pso/network/BufferRef.h"
#include "pso/network/IPv6.h"
#include "pso/network/IPv6Send.h"
#include "pso/network/NetStackTypes.h"
#include "pso/network/NetworkRuntime.h"
#include "pso/network/TLobby_804050DC.h"
#include "pso/network/TLobby_8041112C.h"

/* Defined K&R with an s16 mtu (TLobby_8041112C.c). */
s32 TLobby__sub_80411DEC(IPv6Address *addr, s16 mtu);
s16 TLobby__sub_8040D718(u8 type, u8 code, u8 *src, u8 *dst, NetPacket *pkt, s16 idx);
typedef struct Icmp6ErrorInfo {
    u8 type;
    u8 code;
    u16 checksum;
    s32 pointer;
} Icmp6ErrorInfo;
typedef char Icmp6ErrorInfo_size_check[sizeof(Icmp6ErrorInfo) == 8 ? 1 : -1];
typedef struct UdpHeader {
    u16 src_port;
    u16 dst_port;
    u16 length;
    u16 checksum;
} UdpHeader;
typedef char UdpHeader_size_check[sizeof(UdpHeader) == 8 ? 1 : -1];
s16 NetIPv6HandleIcmpMessage(NetPacket *pkt, u8 *src, u8 *dst, u8 hop_limit, s16 iface) {
    /* The handlers are defined in TLobby_8041112C.c with their own parameter types (s32/void * for some
       arguments); this caller declares them with an s16 iface. */
    s16 NetIPv6HandleRouterSolicitation(NetPacket *pkt, u8 *src, u8 *dst, s16 iface);
    s16 NetIPv6HandleRouterAdvertisement(NetPacket *pkt, u8 *src, u8 *dst, s16 iface);
    s16 NetIPv6HandleNeighborSolicitation(NetPacket *pkt, u8 *src, u8 *dst, s16 iface);
    s16 NetIPv6HandleNeighborAdvertisement(NetPacket *pkt, u8 *src, u8 *dst, s16 iface);
    s16 NetIPv6HandleRedirect(NetPacket *pkt, u8 *src, u8 *dst, s16 iface);
    NetBufferRef ref;
    Ipv6Header ip;
    Icmp6ErrorInfo icmp;
    UdpHeader udp;
    NetPacketFragment *from;
    NetBufferRef *buf;
    s32 mtu;
    s16 r;
    u32 i;
    NetPacketFragment *body;
    NetPacket *reply;

    if (TLobby__sub_80411040((const IPv6Address *)src, (const IPv6Address *)dst, 0x3A, pkt, 0)) {
        return -1;
    }
    body = &pkt->fragments[1];
    set_value_and_enable(&ref, (s32)&icmp);
    TLobby__sub_80406FD8(&ref, &body->buffer, 8);
    switch (icmp.type) {
    case 128:
        reply = alloc_free_entry();
        if (reply == NULL) {
            return -257;
        }
        reply->fragment_count = pkt->fragment_count - 1;
        reply->total_bytes = pkt->total_bytes - pkt->fragments[0].length;
        from = &pkt->fragments[pkt->fragment_count] - 1;
        for (i = 0; i < reply->fragment_count; i++) {
            reply->fragments[i].length = from->length;
            buf = &from->buffer;
            from--;
            NetMemcpy(&reply->fragments[i].buffer, buf, 8);
        }
        r = TLobby__sub_8040D718(0x81, 0, dst, src, reply, iface);
        release_entry(reply);
        return r;
    case 1:
        TLobby__sub_80406EB8(&body->buffer, 8);
        set_value_and_enable(&ref, (s32)&ip);
        TLobby__sub_80406FD8(&ref, &body->buffer, sizeof(ip));
        TLobby__sub_80406EB8(&body->buffer, sizeof(ip));
        switch (ip.next_header) {
        case 17:
            set_value_and_enable(&ref, (s32)&udp);
            TLobby__sub_80406FD8(&ref, &body->buffer, sizeof(udp));
            TLobby__sub_80420D38(udp.src_port, icmp.code);
            break;
        case 6:
            break;
        }
        return 0;
    case 2:
        mtu = icmp.pointer;
        if (mtu > 0 && mtu < 0x8000) {
            TLobby__sub_80406EB8(&body->buffer, 8);
            set_value_and_enable(&ref, (s32)&ip);
            TLobby__sub_80406FD8(&ref, &body->buffer, sizeof(ip));
            TLobby__sub_80411DEC(&ip.dst, mtu);
        }
        return 0;
    case 133:
        if (hop_limit != 255) {
            return -1;
        }
        switch (icmp.code) {
        case 0:
            r = NetIPv6HandleRouterSolicitation(pkt, src, dst, iface);
            if (r < 0) {
                return r;
            }
            break;
        }
        return 0;
    case 134:
        if (hop_limit != 255) {
            return -1;
        }
        switch (icmp.code) {
        case 0:
            r = NetIPv6HandleRouterAdvertisement(pkt, src, dst, iface);
            if (r < 0) {
                return r;
            }
            break;
        }
        return 0;
    case 135:
        if (hop_limit != 255) {
            return -1;
        }
        switch (icmp.code) {
        case 0:
            r = NetIPv6HandleNeighborSolicitation(pkt, src, dst, iface);
            if (r < 0) {
                return r;
            }
            break;
        }
        return 0;
    case 136:
        if (hop_limit != 255) {
            return -1;
        }
        switch (icmp.code) {
        case 0:
            r = NetIPv6HandleNeighborAdvertisement(pkt, src, dst, iface);
            if (r < 0) {
                return r;
            }
            break;
        }
        return 0;
    case 137:
        if (hop_limit != 255) {
            return -1;
        }
        switch (icmp.code) {
        case 0:
            r = NetIPv6HandleRedirect(pkt, src, dst, iface);
            if (r < 0) {
                return r;
            }
            break;
        }
        return 0;
    case 3:
    case 4:
    case 129:
        break;
    default:
        return 0;
    }
    return 0;
}

s16 TLobby__sub_8040D510(void *a, u8 *src, s16 c, s16 flag) {
    s16 TLobby__sub_80413D78(void *, s16);
    NetIcmpv6Header *msg = a;
    Ipv6Header *ip = (Ipv6Header *)src;
    IPv6Address buf;
    IPv6Address *p;
    NetPacket *pkt;
    s16 r;
    s16 t;
    s16 d;
    s32 len;

    if (NetIPv6IsUnspecified(ip->src.bytes) != 0 ||
        NetIPv6IsMulticast(ip->src.bytes) != 0 ||
        TLobby__sub_80413D78(ip->src.bytes, flag) != 0) {
        return -1;
    }
    if (NetIPv6IsMulticast(ip->dst.bytes) != 0) {
        switch (msg->type) {
        case 2:
        case 4:
            break;
        default:
            return -1;
        }
        t = TLobby__sub_80411F1C(&buf, ip->src.bytes, flag);
        if (t < 0) {
            return t;
        }
    } else {
        NetMemcpy(&buf, &ip->dst, sizeof(buf));
    }
    p = &ip->src;
    pkt = alloc_free_entry();
    if (pkt == NULL) {
        return -1;
    }
    pkt->fragment_count = 0;
    pkt->total_bytes = c;
    pkt->fragments[pkt->fragment_count].length = c;
    set_value_and_enable(&pkt->fragments[pkt->fragment_count].buffer, (s32)src);
    pkt->fragment_count += 1;
    pkt->total_bytes += 8;
    pkt->fragments[pkt->fragment_count].length = 8;
    set_value_and_enable(&pkt->fragments[pkt->fragment_count].buffer, (s32)a);
    pkt->fragment_count += 1;
    if (pkt->total_bytes + 0x28 > 0x500) {
        d = len = pkt->total_bytes - 0x4d8;
        if (d > pkt->fragments[0].length) {
            return -1;
        }
        pkt->total_bytes -= d;
        pkt->fragments[0].length -= d;
    }
    msg->checksum = 0;
    msg->checksum = TLobby__sub_80411040(&buf, p, 0x3a, pkt, 1);
    r = TLobby__sub_80410A98((s32)pkt, p, &buf, 0, (void *)0x3a);
    release_entry(pkt);
    return r;
}

typedef struct Icmp6MessageHeader {
    u8 type;
    u8 code;
    u16 checksum;
} Icmp6MessageHeader;
typedef char Icmp6MessageHeader_size_check[sizeof(Icmp6MessageHeader) == 4 ? 1 : -1];
s16 TLobby__sub_8040D718(u8 type, u8 code, u8 *src, u8 *dst, NetPacket *pkt, s16 idx) {
    Icmp6MessageHeader hdr;
    s16 r;

    if (NetIPv6IsMulticast(src) || NetIPv6IsUnspecified(src)) {
        r = TLobby__sub_80411F1C(src, dst, idx);
        if (r < 0) {
            return r;
        }
    }
    switch (type) {
    case 0x81:
        TLobby__sub_80406EB8(&pkt->fragments[pkt->fragment_count - 1].buffer, sizeof(hdr));
        pkt->fragments[pkt->fragment_count - 1].length -= sizeof(hdr);
        pkt->fragments[pkt->fragment_count].length = sizeof(hdr);
        set_value_and_enable(&pkt->fragments[pkt->fragment_count].buffer, (s32)&hdr);
        pkt->fragment_count++;
        break;
    default:
        return -1;
    }
    hdr.type = type;
    hdr.code = code;
    hdr.checksum = 0;
    hdr.checksum = TLobby__sub_80411040((const IPv6Address *)src, (const IPv6Address *)dst, 0x3A, pkt, 1);
    if (TLobby__sub_80410A98((s32)pkt, dst, src, NULL, (void *)0x3A)) {
        return -1;
    }
    return 0;
}
