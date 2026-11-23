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
typedef struct PH_8040EC38 PH_8040EC38;
typedef struct P_8040EC38 P_8040EC38;
u16 calc_pseudo_header_checksum(s32 src, s32 dst, s8 proto, void *pkt, s16 flag);
s32 init_ipv4_interfaces(void);

#include <stddef.h>


#include "pso/network/IPv6Send.h"
#include "pso/network/NetStackTypes.h"

extern Ipv4ProtocolState ipv4_protocol_state;

/* Inline the helpers below; this applies to the rest of the file. */
#pragma dont_inline off
#pragma inline_depth(4)


s32 TLobby__sub_8040DD68(void) {
    release_slot_by_id(0x800);
    TLobby__sub_803F892C((void *)(&ipv4_protocol_state.nsockets));
    ipv4_protocol_state.nsockets = 0;
    return 0;
}

s16 ipv4_input(u8 *ip, s16 len, s16 iface);
s32 init_ipv4_interfaces(void) {
    s16 i;
    Ipv4RawSocket *e;
    Ipv4ProtocolState *g = &ipv4_protocol_state;

    TLobby__sub_803F8930(g);
    e = g->sockets;
    for (i = 0; i < g->nsockets; i++) {
        e->tag[0] = 'I';
        e->tag[1] = 'P';
        e->tag[2] = '4';
        e->index = i;
        e->state = 0;
        e++;
    }
    g->id = 1;
    register_protocol_handler(0x800, (NetProtocolHandler)ipv4_input);
    return 0;
}

inline u16 ip_header_checksum(void *p, s16 n)
{
  u32 s = ones_complement_sum(p, n);
  s = (s >> 16) + (s & 0xFFFF);
  s += s >> 16;
  return ~s;
}

#pragma push
#pragma opt_propagation off
#pragma opt_common_subs on

s16 ipv4_input(u8 *ip, s16 len, s16 iface)
{
  saddr fragment_input(u8 *self, u16 hdr_len, s16 frag_len, u8 ttl, u32 ident, NetworkAddress *src, u16 frag_off, u8 more, s16 iface);
  s16 tcp_input(NetPacket *pkt, NetworkAddress *src, NetworkAddress *dst); /* the definition takes (u8 *, u8 *, u8 *) */
  u16 total_len;
  u16 hlen;
  NetPacket *pkt;
  u16 frag_off;
  s16 i;
  IPv4Header *h;
  s16 data_len;
  s16 reassembled;
  Ipv4RawSocket *sock;
  s16 found;
  NetworkAddress src;
  NetworkAddress dst;
  struct
  {
    u8 type;
    u8 code;
    s32 unused;
  } err;
  u8 *dp;
  s16 r;
  u8 *data;
  u8 more_frags;
  s16 z;
  found = 0;
  if (len < 5)
  {
    return -1;
  }
  if (get_active_entry_by_index(iface) == 0)
  {
    return -1;
  }
  h = (IPv4Header *) ip;
  src.family = 4;
  NetMemcpy(&src.ipv4, &h->src, 4);
  dst.family = 4;
  NetMemcpy(&dst.ipv4, &h->dst, 4);
  hlen = (h->ver_ihl & 0xF) * 4;
  total_len = h->len;
  data_len = total_len - hlen;
  if (hlen < 20)
  {
    return -1;
  }
  if ((h->ver_ihl >> 4) != 4)
  {
    return -1;
  }
  if (ip_header_checksum(h, (s16) (hlen >> 1)) != 0)
  {
    return -1;
  }
  if (total_len < hlen)
  {
    return -1;
  }
  if (iface != 0)
  {
    i = ipv4_iface_for_address(dst.ipv4);
    if (i < 0)
    {
      if (NetIPv4IsBroadcast(dst.ipv4, iface) == 0)
      {
        if (NetIPv4IsInterfaceUp(iface) != 0)
        {
          if (AT_IP4_Forward(dst.ipv4, src.ipv4, ip, len, iface) < 0)
          {
            return -1;
          }
          return -1;
        }
      }
    }
  }
  frag_off = h->frag;
  if (frag_off & (~0x4000))
  {
    if (frag_off & 0x2000)
    {
      more_frags = 1;
    }
    else
    {
      more_frags = 0;
    }
    frag_off = frag_off & 0x1FFF;
    pkt = (NetPacket *) fragment_input(ip, hlen, data_len, h->ttl, h->id, &src, frag_off, more_frags, iface);
    if (pkt == 0)
    {
      return 0;
    }
    reassembled = 1;
  }
  else
  {
    pkt = alloc_free_entry();
    if (pkt == 0)
    {
      return -257;
    }
    pkt->fragment_count = 0;
    pkt->total_bytes = total_len;
    pkt->fragments[pkt->fragment_count].length = hlen;
    set_value_and_enable(&pkt->fragments[pkt->fragment_count].buffer, (saddr) ip);
    pkt->fragment_count++;
    pkt->fragments[pkt->fragment_count].length = data_len;
    set_value_and_enable(&pkt->fragments[pkt->fragment_count].buffer, (saddr) (ip + hlen));
    pkt->fragment_count++;
    reassembled = 0;
  }
  switch (h->proto)
  {
    case 1:
      found = 1;
      if (icmp_input((u8 *) pkt, src.ipv4, dst.ipv4) < 0)
      {
        if (reassembled == 1)
        {
          release_packet_fragments(pkt);
        }
        release_entry(pkt);
        return -1;
      }
      if (reassembled == 1)
      {
        release_packet_fragments(pkt);
      }
      release_entry(pkt);
      break;

    case 6:
      found = 1;
      if (tcp_input(pkt, &src, &dst) < 0)
      {
        if (reassembled == 1)
        {
          release_packet_fragments(pkt);
        }
        release_entry(pkt);
        return -1;
      }
      if (reassembled == 1)
      {
        release_packet_fragments(pkt);
      }
      release_entry(pkt);
      return 0;

    case 17:
      found = 1;
      r = udp_input(pkt, &src, &dst, iface);
      if (r < 0)
      {
        switch (r)
        {
          case -2:
            err.type = 3;
            err.code = 3;
            err.unused = 0;
            r = icmp_send_error((u8 *) (&err), ip, len, iface);
            if (reassembled == 1)
            {
              release_packet_fragments(pkt);
            }
            release_entry(pkt);
            return r;

          default:
            if (reassembled == 1)
            {
              release_packet_fragments(pkt);
            }
            release_entry(pkt);
            return -1;
        }
      }
      if (reassembled == 1)
      {
        release_packet_fragments(pkt);
      }
      release_entry(pkt);
      return 0;

    default:
      found = 0;
      break;
  }

  sock = ipv4_protocol_state.sockets;
  for (i = 0; i < ipv4_protocol_state.nsockets; i++)
  {
    if (sock->state == 1)
    {
      if ((sock->addr == 0) || (sock->addr == src.ipv4))
      {
        if (sock->proto == h->proto)
        {
          if (sock->callback != 0)
          {
            raw_socket_deliver_ipv4(pkt, src.ipv4, dst.ipv4, sock->callback, i);
            found = 1;
          }
        }
      }
    }
    sock++;
  }

  if (found == 1)
  {
    if (reassembled == 1)
    {
      release_packet_fragments(pkt);
    }
    release_entry(pkt);
    return 0;
  }
  err.type = 3;
  err.code = 2;
  err.unused = 0;
  icmp_send_error((u8 *) (&err), ip, len, iface);
  if (reassembled == 1)
  {
    release_packet_fragments(pkt);
  }
  release_entry(pkt);
  return -1;
}
#pragma pop

#pragma push
#pragma opt_common_subs on
s16 AT_IP4_Forward(u32 dst, u32 src, u8 *pkt, s16 len, s16 iface)
{
  u16 frag;
  u8 df;
  u8 ttl;
  u16 cksum;
  u8 *opt;
  s16 optlen;
  Ipv4Route *rt;
  u8 hlen;
  s16 frag_off;
  s16 mtu;
  s16 ifidx;
  u32 target;
  NetPacket *rec;
  u16 flags;
  s16 max_units;
  s16 nunits;
  s16 rem;
  u8 *ip;
  s16 tail;
  u8 *payload;
  s16 r;
  s16 frag_word;
  s16 len_word;
  s16 first;
  hlen = pkt[0];
  hlen = (hlen & 0xF) * 4;
  if (hlen == 20)
  {
    opt = 0;
    optlen = 0;
    len -= 20;
  }
  else
  {
    opt = pkt + 20;
    optlen = hlen - 20;
    len -= hlen;
  }
  if (len <= 0)
  {
    return -1;
  }
  NetMemcpy(&frag, pkt + 6, 2);
  flags = frag & (~0x1FFF);
  df = frag & 0x4000;
  frag_off = (u8) (frag & 0x1FFF);
  frag &= ~0x1FFF;
  ttl = pkt[8];
  ttl -= 1;
  if (ttl < 1)
  {
    return -1;
  }
  pkt[8] = ttl;
  if ((rt = AT_IP4_RouteSearch(dst, src)) == 0)
  {
    return -6;
  }
  ifidx = rt->iface;
  if ((rt->type) == 1)
  {
    target = dst;
  }
  else
  {
    target = rt->gateway;
  }
  mtu = get_ipv4_interface_mtu(ifidx);
  if (mtu < 0)
  {
    return mtu;
  }
  if (mtu < (hlen + len))
  {
    if (df)
    {
      return -1;
    }
    rec = alloc_free_entry();
    if (rec == 0)
    {
      return -257;
    }
    ip = pkt;
    payload = ip + hlen;
    first = 1;
    rem = len;
    max_units = (mtu - hlen) / 8;
    do
    {
      if (mtu > (rem + hlen))
      {
        mtu = rem;
        tail = mtu % 8;
        frag = flags;
        nunits = rem / 8;
      }
      else
      {
        tail = 0;
        nunits = max_units;
        frag |= 0x2000;
      }
      frag_word = frag_off;
      frag_word |= frag;
      NetMemcpy(ip + 6, &frag_word, 2);
      len_word = tail + (nunits * 8) + hlen;
      NetMemcpy(ip + 2, &len_word, 2);
      NetMemset(ip + 10, 0, 2);
      cksum = ip_header_checksum(ip, hlen / 2);
      NetMemcpy(ip + 10, &cksum, 2);
      rec->fragment_count = 0;
      rec->total_bytes = (u16) (tail + (nunits * 8));
      rec->fragments[rec->fragment_count].length = tail + (nunits * 8);
      set_value_and_enable(&rec->fragments[rec->fragment_count].buffer, (saddr) payload);
      rec->fragment_count += 1;
      rec->total_bytes += hlen;
      rec->fragments[rec->fragment_count].length = hlen;
      set_value_and_enable(&rec->fragments[rec->fragment_count].buffer, (saddr) ip);
      rec->fragment_count += 1;
      r = AT_IP4_PktSend(rec, target, ifidx);
      if (r < 0)
      {
        release_entry(rec);
        break;
      }
      if (first)
      {
        hlen = 20;
      }
      frag_off += nunits;
      payload += nunits << 3;
      if (mtu == rem)
      {
        rem = 0;
      }
      else
      {
        rem -= tail + (nunits * 8);
      }
    }
    while (rem > 0);
    release_entry(rec);
  }
  else
  {
    NetMemset(pkt + 10, 0, 2);
    cksum = ip_header_checksum(pkt, hlen / 2);
    NetMemcpy(pkt + 10, &cksum, 2);
    rec = alloc_free_entry();
    if (rec == 0)
    {
      return -257;
    }
    rec->fragment_count = 0;
    rec->total_bytes = len;
    rec->fragments[rec->fragment_count].length = len;
    set_value_and_enable(&rec->fragments[rec->fragment_count].buffer, (saddr) (pkt + hlen));
    rec->fragment_count += 1;
    rec->total_bytes += hlen;
    rec->fragments[rec->fragment_count].length = hlen;
    set_value_and_enable(&rec->fragments[rec->fragment_count].buffer, (saddr) pkt);
    rec->fragment_count += 1;
    r = AT_IP4_PktSend(rec, target, ifidx);
    release_entry(rec);
  }
  return r;
}
#pragma pop

#pragma push
#pragma opt_common_subs on
s16 AT_IP4_Send(NetPacket *pkt, u32 dst, u32 src, u8 ttl, u8 tos, u8 df, u8 proto)
{
  s16 rem;
  Ipv4ProtocolState *g;
  s16 len;
  s16 mtu;
  Ipv4Route *rt;
  u8 hlen;
  NetPacket piece;
  s16 r;
  s16 ifidx;
  IPv4Header *ip;
  u32 target;
  s16 chunk;
  s16 frag_off;
  NetPacket *pp;
  s16 count;
  s16 last;
  s32 i;
  s32 j;
  g = &ipv4_protocol_state;
  hlen = 5;
  if ((rt = AT_IP4_RouteSearch(dst, src)) == 0)
  {
    return -6;
  }
  if (src == 0)
  {
    r = AT_IP4_SrcAddrSel(&src, rt->gateway, rt->iface);
    if (r < 0)
    {
      return r;
    }
  }
  if (NetIPv4IsBroadcast(src, rt->iface) != 0)
  {
    r = AT_IP4_SrcAddrSel(&src, rt->gateway, rt->iface);
    if (r < 0)
    {
      return r;
    }
  }
  ifidx = rt->iface;
  if ((rt->type) == 1)
  {
    target = dst;
  }
  else
  {
    target = rt->gateway;
  }
  ip = &g->hdr;
  ip->ver_ihl = 0x40;
  ip->ver_ihl |= hlen;
  if (tos != 0)
  {
    ip->tos = tos;
  }
  else
  {
    ip->tos = g->def_tos;
  }
  if (ttl != 0)
  {
    ip->ttl = ttl;
  }
  else
  {
    ip->ttl = g->def_ttl;
  }
  if ((len = pkt->total_bytes) == 0)
  {
    return 0;
  }
  len += hlen << 2;
  ip->len = len;
  g->id += 1;
  ip->proto = proto;
  ip->id = g->id;
  NetMemcpy(&ip->src, &src, 4);
  NetMemcpy(&ip->dst, &dst, 4);
  if ((mtu = get_ipv4_interface_mtu(ifidx)) < 0)
  {
    return mtu;
  }
  if (len <= mtu)
  {
    ip->frag = 0;
    if (df != 0)
    {
      ip->frag = 0x4000;
    }
    ip->cksum = 0;
    ip->cksum = ip_header_checksum(ip, 10);
    pkt->total_bytes += hlen << 2;
    pkt->fragments[pkt->fragment_count].length = hlen * 4;
    set_value_and_enable(&pkt->fragments[pkt->fragment_count].buffer, (saddr) ip);
    pkt->fragment_count++;
    r = AT_IP4_PktSend(pkt, target, ifidx);
    return r;
  }
  frag_off = 0;
  count = 0;
  if (df != 0)
  {
    return -2;
  }
  ip->frag = 0;
  chunk = (mtu - (hlen << 2)) / 8;
  chunk *= 8;
  do
  {
    pp = &piece;
    pp->fragment_count = 0;
    pp->total_bytes = 0;
    rem = chunk;
    j = pkt->fragment_count - 1;
    count = 0;
    while ((rem > 0) && (j >= 0))
    {
      rem -= pkt->fragments[j].length;
      j--;
      count++;
    }
    rem = chunk;
    j = count - 1;
    i = pkt->fragment_count - 1;
    last = 0;
    while ((rem > 0) && (j >= 0))
    {
      NetMemcpy(&pp->fragments[j].buffer, &pkt->fragments[i].buffer, 8);
      if (pkt->fragments[i].length > rem)
      {
        pp->fragments[j].length = rem;
        pp->total_bytes += rem;
        pkt->fragments[i].length -= rem;
        pkt->total_bytes -= rem;
        netbuf_ref_advance(&pkt->fragments[i].buffer, rem);
        rem = 0;
      }
      else
      {
        pp->fragments[j].length = pkt->fragments[i].length;
        pp->total_bytes += pkt->fragments[i].length;
        pkt->total_bytes -= pkt->fragments[i].length;
        rem -= pkt->fragments[i].length;
        if (i == 0)
        {
          rem = pkt->fragments[i].length;
          last = 1;
          j--;
          i--;
        }
        else
        {
          pkt->fragment_count--;
          j--;
          i--;
        }
      }
      pp->fragment_count++;
    }
    if (last == 1)
    {
      ip->frag = 0;
    }
    else
    {
      rem = chunk;
      ip->frag = 0x2000;
    }
    ip->frag |= frag_off;
    rem = pp->total_bytes;
    rem += hlen << 2;
    ip->len = rem;
    ip->cksum = 0;
    ip->cksum = ip_header_checksum(ip, 10);
    pp->total_bytes += hlen << 2;
    pp->fragments[pp->fragment_count].length = hlen * 4;
    set_value_and_enable(&pp->fragments[pp->fragment_count].buffer, (saddr) ip);
    pp->fragment_count++;
    r = AT_IP4_PktSend(pp, target, ifidx);
    if (r < 0)
    {
      return r;
    }
    frag_off += chunk / 8;
  }
  while (last != 1);
  return 0;
}
#pragma pop
typedef struct PH_8040EC38 { s32 src; s32 dst; u8 zero; s8 proto; u16 len; } PH_8040EC38;
struct P_8040EC38 { u8 pad0[8]; s32 f8; s16 fC; };

u16 calc_pseudo_header_checksum(s32 src, s32 dst, s8 proto, void *pkt, s16 flag) {
    PH_8040EC38 ph;
    u32 sum;

    ph.src = src;
    ph.dst = dst;
    ph.zero = 0;
    ph.proto = proto;
    if (flag == 0) {
        ph.len = ((P_8040EC38 *)pkt)->f8 - ((P_8040EC38 *)pkt)->fC;
    } else {
        ph.len = ((P_8040EC38 *)pkt)->f8;
    }
    sum = ones_complement_sum(&ph, 6);
    sum += packet_ones_complement_sum(pkt, flag);
    sum = (sum >> 16) + (sum & 0xFFFF);
    sum += sum >> 16;
    return ~sum;
}

u16 calc_ip_checksum(NetPacket *self, s16 b) {
    u32 s = packet_ones_complement_sum(self, b);
    s = (s >> 16) + (s & 0xFFFF);
    s += (s >> 16);
    return ~s;
}

Ipv4ProtocolState ipv4_protocol_state;
