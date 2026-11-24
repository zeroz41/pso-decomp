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

#include <stddef.h>


#include "pso/network/IPv6Send.h"
#include "pso/network/NetStackTypes.h"


/* Inline the helpers below; this applies to the rest of the file. */
#pragma dont_inline off
#pragma inline_depth(4)


s32 NetIPv6Shutdown(void) {
    release_slot_by_id(0x86DD);
    TLobby__sub_803F87DC(&ipv6_protocol_state);
    ipv6_protocol_state.nsockets = 0;
    return 0;
}

s32 ipv6_input(u8 *ip, int len, s16 id);
s32 NetIPv6Init(void) {
    s16 i;
    Ipv6RawSocket *e;
    Ipv6ProtocolState *g = &ipv6_protocol_state;

    init_ipv6_interface_config(g);
    e = g->sockets;
    for (i = 0; i < g->nsockets; i++) {
        e->tag[0] = 'I';
        e->tag[1] = 'P';
        e->tag[2] = '6';
        e->index = i;
        e->used = 0;
        e++;
    }
    g->ident = 1;
    register_protocol_handler(0x86DD, (NetProtocolHandler)ipv6_input);
    return 0;
}

inline s16 process_options_header(u8 *ext, s16 rem, u8 *ip, s16 len, s16 iface) {
    s32 options_len;
    u8 *options;
    options = ext + 2;
    options_len = ((ext[1] + 1) << 3) - 2;
    if ((s16)options_len > rem) {
        return -1;
    }
    if (ipv6_process_options(options, options_len, ip, len, iface) < 0) {
        return -1;
    }
    return 0;
}

inline NetPacket *input_fragment_header(u8 *ip, Ipv6FragmentHeader *frag, s32 remaining, s16 total_len, s16 iface, NetworkAddress *src, NetIcmpv6Header *error) {
    saddr fragment_input(u8 *, u16, s16, u8, u32, NetworkAddress *, u16, u8, s16);
    u32 offset_flags;
    u32 more;
    u32 offset;
    offset_flags = frag->offset_flags;
    more = offset_flags & 1;
    offset = (offset_flags >> 3) & 0x1FFF;
    if (((u8) offset_flags & 1) && (((remaining - sizeof(Ipv6FragmentHeader)) & 7) != 0)) {
        if (offset == 0) {
            error->type = ICMP6_PARAM_PROB;
            error->code = ICMP6_PARAMPROB_HEADER;
            error->reserved = offsetof(Ipv6Header, payload_length);
            icmp6_send_error(error, ip, total_len, iface);
        }
        return 0;
    }
    return (NetPacket *) fragment_input(ip, total_len - (remaining - sizeof(Ipv6FragmentHeader)), remaining - sizeof(Ipv6FragmentHeader), IPV6_REASSEMBLY_TIMEOUT, frag->ident, src, offset, more, iface);
}
inline s32 min_s32(s32 a, s32 b) {
    if (a < b) {
        return a;
    }
    return b;
}

inline NetPacket *make_input_packet(u8 *ip, s16 total_len, u8 *payload, s32 payload_len) {
    NetPacket *pkt = alloc_free_entry();
    if (pkt == 0) {
        return 0;
    }
    pkt->fragment_count = 0;
    pkt->total_bytes = total_len;
    pkt->fragments[pkt->fragment_count].length = total_len - payload_len;
    set_value_and_enable(&pkt->fragments[pkt->fragment_count].buffer, (saddr)ip);
    pkt->fragment_count += 1;
    pkt->fragments[pkt->fragment_count].length = (u16)payload_len;
    set_value_and_enable(&pkt->fragments[pkt->fragment_count].buffer, (saddr)payload);
    pkt->fragment_count += 1;
    return pkt;
}

#pragma push
#pragma opt_loop_invariants off
#pragma opt_strength_reduction off
s32 ipv6_input(u8 *ip, int len, s16 id) {
    s16 tcp_input(NetPacket *pkt, NetworkAddress *src, NetworkAddress *dst); /* the definition takes (u8 *, u8 *, u8 *) */
    NetworkAddress src_addr;
    NetworkAddress dst_addr;
    NetIcmpv6Header error;
    NetIcmpv6Header options_error;
    NetIcmpv6Header frag_error;
    s16 total_len;
    s16 iface;
    u8 next_header;
    s16 i;
    s32 remaining;
    u8 *ext;
    u8 *next_header_field;
    u8 *src;
    Ipv6ProtocolState *state;
    u8 *hdr;
    s16 result;
    u8 *dst_cmp;
    s16 status;
    u8 *dst;
    s16 delivered;
    NetPacket *pkt;
    s16 reassembled;
    Ipv6RawSocket *sock;

    if (((s16) len) < (s32) sizeof(Ipv6Header)) {
        goto ret;
    }
    iface = id;
    if (get_valid_entry(iface) == 0) {
        goto ret;
    }
    if ((ip[0] & 0xF0) != 0x60) {
        return -1;
    }
    total_len = min_s32(((Ipv6Header *) ip)->payload_length + sizeof(Ipv6Header), (s16) len);
    if (TLobby__sub_804136CC(iface) == 0) {
        if (ipv6_iface_for_address(((Ipv6Header *) ip)->dst.bytes) < 0) {
            if (NetIPv6IsMulticast(((Ipv6Header *) ip)->dst.bytes) == 0) {
                if (ipv6_forward(ip, ip, total_len, iface) == 0) {
                    return 0;
                }
                return -1;
            }
        }
    }
    src_addr.family = 6;
    src = src_addr.address;
    NetMemcpy(src, ((Ipv6Header *) ip)->src.bytes, 16);
    dst_addr.family = 6;
    dst = dst_addr.address;
    NetMemcpy(dst, ((Ipv6Header *) ip)->dst.bytes, 16);
    next_header = ((Ipv6Header *) ip)->next_header;
    remaining = total_len - sizeof(Ipv6Header);
    hdr = ip;
    ext = hdr + sizeof(Ipv6Header);
    next_header_field = hdr + offsetof(Ipv6Header, next_header);
    reassembled = 0;
    dst_cmp = dst;
    delivered = 0;
    for (;;) {
        if (next_header == IPV6_NH_NONE) {
            return 0;
        }
        if (((s16) remaining) < 8) {
            error.type = ICMP6_PARAM_PROB;
            error.code = ICMP6_PARAMPROB_NEXTHEADER;
            error.reserved = next_header_field - hdr;
            icmp6_send_error(&error, hdr, total_len, id);
            goto ret;
        }
        switch (next_header) {
        case IPV6_NH_HOP_BY_HOP:
            if (total_len != (((s16) remaining) + (s32) sizeof(Ipv6Header))) {
                options_error.type = ICMP6_PARAM_PROB;
                options_error.code = ICMP6_PARAMPROB_NEXTHEADER;
                options_error.reserved = next_header_field - hdr;
                icmp6_send_error(&options_error, hdr, total_len, id);
                status = -1;
            } else {
                status = process_options_header(ext, remaining, hdr, total_len, iface);
            }
            if (status < 0) {
                goto ret;
            }
            goto adv;

        case IPV6_NH_ICMP:
        case IPV6_NH_IPV4:
        case IPV6_NH_ESP:
        case IPV6_NH_AH:
            goto ret;

        case IPV6_NH_FRAGMENT:
            pkt = input_fragment_header(hdr, (Ipv6FragmentHeader *) ext, remaining, total_len, iface, &src_addr, &frag_error);
            if (pkt == 0) {
                return -1;
            }
            next_header = ext[0];
            reassembled = 1;
            goto payload;

        case IPV6_NH_DEST_OPTIONS:
            status = process_options_header(ext, remaining, hdr, total_len, iface);
            if (status < 0) {
                goto ret;
            }
            /* fallthrough */
        case IPV6_NH_ROUTING:
        adv:
            next_header_field = ext;
            next_header = ext[0];
            remaining -= (ext[1] + 1) << 3;
            ext += (ext[1] + 1) << 3;
            continue;

        case 10:
        case 20:
        case 30:
        case 40:
            break;
        }
        break;
    }

payload:
    if (reassembled == 0) {
        pkt = make_input_packet(hdr, total_len, ext, remaining);
        if (pkt == 0) {
            return -257;
        }
    }

    switch (next_header) {
    case IPV6_NH_ICMPV6:
        result = NetIPv6HandleIcmpMessage(pkt, src, dst, ((Ipv6Header *) hdr)->hop_limit, iface);
        iface = id;
        if (result < 0) {
            goto fail;
        }
        delivered = 1;
        break;

    case IPV6_NH_TCP:
        result = tcp_input(pkt, &src_addr, &dst_addr);
        if (result < 0) {
            goto fail;
        }
        goto ok;

    case IPV6_NH_UDP:
        result = udp_input(pkt, &src_addr, &dst_addr, iface);
        if (result >= 0) {
            goto ok;
        }
        switch (result) {
        case -2:
            error.type = ICMP6_DST_UNREACH;
            error.code = ICMP6_DST_UNREACH_NOPORT;
            error.reserved = 0;
            icmp6_send_error(&error, hdr, total_len, iface);
            goto fail;

        default:
            goto fail;
        }

    default:
        break;
    }

    state = &ipv6_protocol_state;
    sock = state->sockets;
    for (i = 0; i < state->nsockets; i++, sock++) {
        if (((sock->used == 1) && (sock->proto == next_header)) && (sock->owner != 0)) {
            if ((NetIPv6IsUnspecified(sock->local) != 0) || (NetIPv6CompareAddresses(sock->local, src) == 0)) {
                if ((NetIPv6IsUnspecified(sock->remote) != 0) || (NetIPv6CompareAddresses(sock->remote, dst_cmp) == 0)) {
                    raw_socket_deliver(pkt, src, dst, sock->owner, i);
                    delivered = 1;
                }
            }
        }
    }

    if (delivered == 1) {
    ok:
        if (reassembled == 1) {
            release_packet_fragments(pkt);
        }
        release_entry(pkt);
        return 0;
    }
    if (reassembled != 1) {
        error.type = ICMP6_PARAM_PROB;
        error.code = ICMP6_PARAMPROB_NEXTHEADER;
        error.reserved = next_header_field - hdr;
        icmp6_send_error(&error, hdr, total_len, iface);
    }
fail:
    if (reassembled == 1) {
        release_packet_fragments(pkt);
    }
    release_entry(pkt);
ret:
    return -1;
}
#pragma pop

static inline s16 chk_804105E0(u8 *p, s16 lim, s16 ctx, s16 l, s16 rem, u8 *q, u8 *prev) {
    NetIcmpv6Header error;
    if (l != rem + 0x28) {
        error.type = ICMP6_PARAM_PROB;
        error.code = ICMP6_PARAMPROB_NEXTHEADER;
        error.reserved = prev - p;
        icmp6_send_error(&error, p, lim, ctx);
        return -1;
    }
    return process_options_header(q, rem, p, lim, ctx);
}
#pragma push
#pragma opt_common_subs on
#pragma opt_propagation off
extern s16 ipv6_forward(u8 *self, u8 *p, s16 lim, s16 ctx)
{
  NetIPv6SendParameters params;
  NetIcmpv6Header error;
  s32 tot;
  NetPacket *e;
  s16 rem;
  u8 *q;
  Ipv6Route *hit;
  u8 *hop_limit;
  u8 *prev;
  s16 l;
  s16 flag;
  s16 h6;
  u16 flags;
  u8 state;
  u8 *dst;
  s32 adv;
  s16 r21;
  l = lim;
  tot = l - 0x28;
  hop_limit = &params.hop_limit;
  rem = tot;
  q = p + 0x28;
  prev = p + 6;
  flag = 0;
  params.flow_label = *((u32 *) self);
  params.traffic_class_bits = *((u16 *) self);
  params.next_header = self[6];
  state = self[7];
  params.hop_limit = state;
  state = self[6];
  while (rem >= 8)
  {
    switch (state)
    {
      case 0:
        if (chk_804105E0(p, lim, ctx, l, rem, q, prev) < 0)
      {
        return -1;
      }
        prev = q;
        state = q[0];
        adv = (q[1] + 1) << 3;
        rem -= adv;
        q += adv;
        break;

      case 0x2c:
        flags = (*((u16 *) (q + 2))) & 0xFFF8;
        flag = 1;

      default:
        rem = 0;
        break;

    }

  }

  if (((*hop_limit) == 0) || ((--params.hop_limit) == 0))
  {
    if ((flag == 0) || (flags == 0))
    {
      error.type = ICMP6_TIME_EXCEEDED;
      error.code = ICMP6_TIME_EXCEED_TRANSIT;
      error.reserved = 0;
      icmp6_send_error(&error, p, lim, ctx);
    }
    return -1;
  }
  hit = TLobby__sub_80413264(self + 0x18, self + 8);
  if (hit == ((void *) 0))
  {
    if ((flag == 0) || (flags == 0))
    {
      error.type = ICMP6_DST_UNREACH;
      error.code = ICMP6_DST_UNREACH_NOROUTE;
      error.reserved = 0;
      icmp6_send_error(&error, p, lim, ctx);
    }
    return -1;
  }
  switch (hit->type)
  {
    case 1:
      dst = self + 0x18;
      break;

    case 2:

    case 3:
      dst = hit->gateway;
      break;

  }

  if (lim > (h6 = get_iface_mtu(hit->iface)))
  {
    if ((flag == 0) || (flags == 0))
    {
      error.type = ICMP6_PACKET_TOO_BIG;
      error.code = 0;
      error.reserved = h6;
      icmp6_send_error(&error, p, lim, ctx);
    }
    return -1;
  }
  e = alloc_free_entry();
  if (e == ((void *) 0))
  {
    return -1;
  }
  e->fragment_count = 0;
  e->total_bytes = tot;
  e->fragments[e->fragment_count].length = (s16) tot;
  set_value_and_enable(&e->fragments[e->fragment_count].buffer, (saddr) (p + 0x28));
  e->fragment_count = e->fragment_count + 1;
  NetMemcpy(&params.source, self + 8, sizeof(params.source));
  NetMemcpy(&params.destination, self + 0x18, sizeof(params.destination));
  if ((NetIPv6IsMulticast(dst) == 0) && (TLobby__sub_804136AC(hit->iface) != 0))
  {
    r21 = TLobby__sub_80415D0C(e, dst, &params, hit->iface);
  }
  else
  {
    r21 = TLobby__sub_80410BA8(e, &params, hit->iface, 0);
  }
  release_entry(e);
  return r21;
}
#pragma pop
s16 ipv6_process_options(u8* p, s16 n, u8* self, s16 c, s16 d) {
    u8* cur = p;
    s32 len;

    while (n > 0) {
        switch (*cur) {
        case 0:
            n--;
            cur++;
            break;
        case 1:
            len = cur[1] + 2;
            n -= len;
            cur += len;
            break;
        default:
            switch (*cur & 0xC0) {
            case 0x00:
                len = cur[1] + 2;
                n -= len;
                cur += len;
                break;
            case 0xC0:
                if (NetIPv6IsMulticast(self + 0x18)) {
                    return -1;
                }
                /* fallthrough */
            case 0x80: {
                struct {
                    u8 a;
                    u8 b;
                    u32 c;
                } msg;

                msg.a = ICMP6_PARAM_PROB;
                msg.b = ICMP6_PARAMPROB_OPTION;
                msg.c = cur - self;
                icmp6_send_error(&msg, self, c, d);
            }
            case 0x40:
            default:
                return -1;
            }
            break;
        }
    }
    if (n != 0) {
        return -1;
    }
    return 0;
}

s16 TLobby__sub_80410A98(NetPacket *pkt, void *dst, void *src, NetIPv6SendOptions *opts, u8 proto) {
    NetIPv6SendOptions defaults;
    NetIPv6SendParameters params;
    Ipv6Route *route;
    u8 *next_hop;

    route = TLobby__sub_80413264(dst, src);
    if (route == NULL) {
        return -6;
    }
    if (route->type == 1) {
        next_hop = dst;
    } else {
        next_hop = route->gateway;
    }
    if (opts == NULL) {
        NetMemset(&defaults, 0, sizeof(defaults));
        opts = &defaults;
    }
    params.flow_label = opts->flow_label;
    params.traffic_class_bits = opts->traffic_class_bits;
    params.hop_limit = opts->hop_limit;
    params.next_header = proto;
    NetMemcpy(&params.source, src, sizeof(params.source));
    NetMemcpy(&params.destination, dst, sizeof(params.destination));
    if (!NetIPv6IsMulticast(next_hop) && TLobby__sub_804136AC(route->iface)) {
        return TLobby__sub_80415D0C(pkt, next_hop, &params, route->iface);
    }
    return TLobby__sub_80410BA8(pkt, &params, route->iface, NULL);
}

s16 TLobby__sub_80410D6C(NetPacket *packet, Ipv6Header *hdr, s16 iface, u8 *link_address, u32 room);
s16 TLobby__sub_80410BA8(NetPacket *packet, NetIPv6SendParameters *params, s16 iface, u8 *link_address)
{
  Ipv6ProtocolState *base = &ipv6_protocol_state;
  s32 new_var;
  u32 used = packet->total_bytes;
  Ipv6Header *slot = &base->hdr;
  s32 n;
  s16 ret;
  s32 pad2[2];
  if (used == 0)
  {
    return 0;
  }
  slot->version_class_flow = 0;
  if (params->flow_label)
  {
    slot->version_class_flow = (params->flow_label) & 0xFFFFF;
  }
  else
  {
    slot->version_class_flow = base->flow_label;
  }
  if (params->traffic_class_bits)
  {
    *((u16 *) slot) |= (params->traffic_class_bits) & 0xFF0;
  }
  else
  {
    *((u16 *) slot) |= base->traffic_class;
  }
  *((u8 *) slot) = 0x60;
  slot->payload_length = used;
  slot->next_header = params->next_header;
  if (params->hop_limit)
  {
    slot->hop_limit = params->hop_limit;
  }
  else
  {
    slot->hop_limit = base->hop_limit;
  }
  NetMemcpy(&slot->src, &params->source, sizeof(IPv6Address));
  NetMemcpy(&slot->dst, &params->destination, sizeof(IPv6Address));
  ret = TLobby__sub_80411C44(params->destination.bytes, iface);
  if (ret < 0)
  {
    return ret;
  }
  n = ret - (s32)sizeof(Ipv6Header);
  base->ident += 1;
  new_var = n;
  if (used > ((u32) n))
  {
    return TLobby__sub_80410D6C(packet, slot, iface, link_address, new_var);
  }
  packet->total_bytes += sizeof(Ipv6Header);
  packet->fragments[packet->fragment_count].length = sizeof(Ipv6Header);
  set_value_and_enable(&packet->fragments[packet->fragment_count].buffer, (saddr) slot);
  packet->fragment_count += 1;
  if (NetIPv6IsMulticast(params->destination.bytes))
  {
    return TLobby__sub_804112B8(packet, &params->destination, iface);
  }
  return TLobby__sub_8041123C(packet, link_address, iface);
}

#pragma push
#pragma opt_common_subs on
s16 TLobby__sub_80410D6C(NetPacket *packet, Ipv6Header *hdr, s16 iface, u8 *link_address, u32 room)
{
    NetPacket iov;
    Ipv6FragmentHeader fh;
    s16 i;
    s16 k;
    s16 j;
    s32 off;
    s16 rem;
    NetPacket *iovp;
    u32 limit;
    s32 flen;
    s16 r;

    if (room < sizeof(Ipv6FragmentHeader)) {
        return -6;
    }
    fh.next_header = hdr->next_header;
    fh.reserved = 0;
    fh.offset_flags = 0;
    fh.ident = ipv6_protocol_state.ident;
    hdr->next_header = 0x2c;
    limit = room - sizeof(Ipv6FragmentHeader);
    limit &= 0xFFF8;
    iovp = &iov;
    off = 0;
    while (packet->total_bytes != 0) {
        iov.total_bytes = 0;
        iov.fragment_count = 0;
        for (i = packet->fragment_count - 1; i >= 0; i--) {
            if (iov.total_bytes + (flen = packet->fragments[i].length) < limit) {
                iov.total_bytes += packet->fragments[i].length;
                iov.fragment_count++;
            } else {
                iov.total_bytes = limit;
                iov.fragment_count++;
                break;
            }
        }
        k = iov.fragment_count - 1;
        j = packet->fragment_count - 1;
        rem = iov.total_bytes;
        while (k >= 0 && rem > 0) {
            NetMemcpy(&iovp->fragments[k].buffer, &packet->fragments[j].buffer, sizeof(NetBufferRef));
            if (rem < packet->fragments[j].length) {
                iovp->fragments[k].length = rem;
                packet->total_bytes -= rem;
                packet->fragments[j].length -= rem;
                netbuf_ref_advance(&packet->fragments[j].buffer, rem);
                break;
            }
            iovp->fragments[k].length = packet->fragments[j].length;
            rem -= packet->fragments[j].length;
            packet->total_bytes -= packet->fragments[j].length;
            packet->fragments[j].length = 0;
            packet->fragment_count--;
            k--;
            j--;
        }
        fh.offset_flags = off & 0xFFF8;
        if (packet->total_bytes != 0) {
            fh.offset_flags |= 1;
        }
        off += (s16)iov.total_bytes;
        iov.total_bytes += 8;
        iovp->fragments[iov.fragment_count].length = 8;
        set_value_and_enable(&iovp->fragments[iov.fragment_count].buffer, (saddr)&fh);
        iov.fragment_count++;
        hdr->payload_length = iov.total_bytes;
        iov.total_bytes += 40;
        iovp->fragments[iov.fragment_count].length = 40;
        set_value_and_enable(&iovp->fragments[iov.fragment_count].buffer, (saddr)hdr);
        iov.fragment_count++;
        if (NetIPv6IsMulticast(hdr->dst.bytes)) {
            r = TLobby__sub_804112B8(iovp, &hdr->dst, iface);
        } else {
            r = TLobby__sub_8041123C(iovp, link_address, iface);
        }
        if (r < 0) {
            break;
        }
    }
    return r;
}
#pragma pop

typedef struct PH_80411040 { IPv6Address src; IPv6Address dst; u32 len; u8 zero[3]; u8 next_header; } PH_80411040;
LAYOUT_ASSERT(PH_80411040_size_check, sizeof(PH_80411040) == 0x28);
extern u16 calc_ipv6_pseudo_header_checksum(const struct IPv6Address *src, const struct IPv6Address *dst, u8 next_header, const struct NetPacket *pkt, s16 flag) {
    PH_80411040 ph;
    u32 sum;

    NetMemcpy(&ph.src, (void *)src, sizeof(IPv6Address));
    NetMemcpy(&ph.dst, (void *)dst, sizeof(IPv6Address));
    ph.zero[0] = 0;
    ph.zero[1] = 0;
    ph.zero[2] = 0;
    ph.next_header = next_header;
    if (flag == 0) {
        ph.len = (u16)(pkt->total_bytes - pkt->fragments[0].length);
    } else {
        ph.len = (u16)pkt->total_bytes;
    }
    sum = ones_complement_sum(&ph, sizeof(ph) / 2);
    sum += packet_ones_complement_sum(pkt, flag);
    sum = (sum >> 16) + (sum & 0xFFFF);
    sum += sum >> 16;
    return ~sum;
}

Ipv6ProtocolState ipv6_protocol_state;
