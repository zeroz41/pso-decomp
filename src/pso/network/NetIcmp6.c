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
/* The object header the stack's records share (laid out like TObject's fields). */
void release_entry(void *self);

#include <stddef.h>


#include "pso/network/IPv6Send.h"
#include "pso/network/NetStackTypes.h"

s16 TLobby__sub_80413D78();

/* Inline the helpers below; this applies to the rest of the file. */
#pragma dont_inline off
#pragma inline_depth(4)

/* Defined K&R with an s16 mtu (TLobby_8041112C.c). */
s32 TLobby__sub_80411DEC(IPv6Address *addr, s16 mtu);
extern s16 TLobby__sub_8040D718(u8 type, u8 code, u8 *src, u8 *dst, NetPacket *pkt, s16 idx);
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
extern s16 NetIPv6HandleIcmpMessage(NetPacket *pkt, u8 *src, u8 *dst, u8 hop_limit, s16 iface) {
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
    set_value_and_enable((&ref), (s32)&icmp);
    TLobby__sub_80406FD8(&ref, &body->buffer, 8);
    switch (icmp.type) {
    case 128:
        reply = (NetPacket *)alloc_free_entry();
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
        set_value_and_enable((&ref), (s32)&ip);
        TLobby__sub_80406FD8(&ref, &body->buffer, sizeof(ip));
        TLobby__sub_80406EB8(&body->buffer, sizeof(ip));
        switch (ip.next_header) {
        case 17:
            set_value_and_enable((&ref), (s32)&udp);
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
            set_value_and_enable((&ref), (s32)&ip);
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
    u8 buf[0x10];
    u8 *p;
    u8 *rec;
    s16 r;
    s16 t;
    s16 d;
    s32 len;

    if (NetIPv6IsUnspecified(src + 8) != 0 || NetIPv6IsMulticast(src + 8) != 0 ||
        TLobby__sub_80413D78(src + 8, flag) != 0) {
        return -1;
    }
    if (NetIPv6IsMulticast(src + 0x18) != 0) {
        switch (((u8 *)a)[0]) {
        case 2:
        case 4:
            break;
        default:
            return -1;
        }
        t = TLobby__sub_80411F1C(buf, src + 8, flag);
        if (t < 0) {
            return t;
        }
    } else {
        NetMemcpy(buf, src + 0x18, 0x10);
    }
    p = src + 8;
    rec = (u8 *)alloc_free_entry();
    if (rec == NULL) {
        return -1;
    }
    *(s32 *)(rec + 4) = 0;
    *(s32 *)(rec + 8) = c;
    ((struct { s16 len; u8 pad[10]; } *)(rec + 0xc))[*(s32 *)(rec + 4)].len = c;
    set_value_and_enable(rec + 0x10 + *(s32 *)(rec + 4) * 0xc, (s32)src);
    *(s32 *)(rec + 4) += 1;
    *(s32 *)(rec + 8) += 8;
    ((struct { s16 len; u8 pad[10]; } *)(rec + 0xc))[*(s32 *)(rec + 4)].len = 8;
    set_value_and_enable(rec + 0x10 + *(s32 *)(rec + 4) * 0xc, (s32)a);
    *(s32 *)(rec + 4) += 1;
    if (*(u32 *)(rec + 8) + 0x28 > 0x500) {
        d = len = *(u32 *)(rec + 8) - 0x4d8;
        if (d > *(s16 *)(rec + 0xc)) {
            return -1;
        }
        *(u32 *)(rec + 8) -= d;
        *(s16 *)(rec + 0xc) -= d;
    }
    *(s16 *)((u8 *)a + 2) = 0;
    *(s16 *)((u8 *)a + 2) = TLobby__sub_80411040((const IPv6Address *)buf, (const IPv6Address *)p, 0x3a, (const NetPacket *)rec, 1);
    r = TLobby__sub_80410A98((s32)rec, p, buf, 0, (void *)0x3a);
    release_entry(rec);
    return r;
}

typedef struct Icmp6MessageHeader {
    u8 type;
    u8 code;
    u16 checksum;
} Icmp6MessageHeader;
typedef char Icmp6MessageHeader_size_check[sizeof(Icmp6MessageHeader) == 4 ? 1 : -1];
extern s16 TLobby__sub_8040D718(u8 type, u8 code, u8 *src, u8 *dst, NetPacket *pkt, s16 idx) {
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
        set_value_and_enable((&pkt->fragments[pkt->fragment_count].buffer), (s32)&hdr);
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
