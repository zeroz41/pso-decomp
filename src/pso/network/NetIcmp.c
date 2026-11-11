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
u16 calc_ip_checksum(void *self, s16 b);
void release_entry(void *self);

#include <stddef.h>


#include "pso/network/IPv6Send.h"
#include "pso/network/NetStackTypes.h"

/* Inline the helpers below; this applies to the rest of the file. */
#pragma dont_inline off
#pragma inline_depth(4)

s16 TLobby__sub_8040CB44(u8 *self, u32 d, u32 c)
{
  s16 TLobby__sub_8040CFE8(u8 type, u8 code, u32 src, u32 dst, NetPacket *pkt);
  s32 TLobby__sub_8040F8A4(u32, void *, u32, u32, u32);
  u8 *p;
  u8 stream[0xc];
  u8 hdr[8];
  u32 *new_var;
  u8 ip[24];
  u8 udp[8];
  u8 addr[4];
  u8 pad[12];
  u8 *q;
  s16 r;
  u32 i;
  u8 *rec;
  u8 *out;
  unsigned int a;
  u32 net;
  u32 mask;
  rec = self + 0x18;
  set_value_and_enable(stream, (s32) hdr);
  TLobby__sub_80406FD8(stream, rec + 4, 8);
  if (calc_ip_checksum(self, 0) != 0)
  {
    return -1;
  }
  switch (hdr[0])
  {
    case 0:

    case 4:

    case 11:

    case 12:

    case 13:

    case 14:

    case 17:

    case 18:
      break;

    case 8:
      out = alloc_free_entry();
      if (out == ((void *) 0))
    {
      return -0x101;
    }
      *((s32 *) (out + 4)) = (*((s32 *) (self + 4))) - 1;
      *((s32 *) (out + 8)) = (*((s32 *) (self + 8))) - (*((s16 *) (self + 0xc)));
      p = self + (*((s32 *) (self + 4))) * 12;
      for (i = 0, q = out; i < (*((u32 *) (out + 4))); i++)
    {
      *((s16 *) (q + 0xc)) = *((s16 *) p);
      NetMemcpy(q + 0x10, (p -= 12) + 16, 8);
      q += 12;
    }

      r = TLobby__sub_8040CFE8(0, 0, c, d, (NetPacket *)(out));
      if (r < 0)
    {
      release_entry(out);
      return r;
    }
      release_entry(out);
      return 0;

    case 3:
      TLobby__sub_80406EB8((NetBufferRef *)(rec + 4), 8);
      set_value_and_enable(stream, (s32) ip);
      TLobby__sub_80406FD8(stream, rec + 4, 20);
      TLobby__sub_80406EB8((NetBufferRef *)(rec + 4), (ip[0] & 0xf) << 2);
      switch (ip[9])
    {
      case 6:
        break;

      case 17:
        set_value_and_enable(stream, (s32) udp);
        TLobby__sub_80406FD8(stream, rec + 4, 8);
        TLobby__sub_80420D38(*((u16 *) udp), hdr[1]);
        break;

    }

      return 0;

    case 5:
      TLobby__sub_80406EB8((NetBufferRef *)(rec + 4), 8);
      set_value_and_enable(stream, (s32) ip);
      TLobby__sub_80406FD8(stream, rec + 4, 20);
      switch (hdr[1])
    {
      case 0:

      case 2:
        NetMemcpy(addr, hdr + 4, 4);
        a = *((u32 *) (ip + 16));
        net = ((a & 0x80000000) == 0) ? (a & 0xFF000000) : (((a & 0xC0000000) == 0x80000000) ? (a & 0xFFFF0000) : (((a & 0xE0000000) == 0xC0000000) ? (a & 0xFFFFFF00) : (0)));
        new_var = (u32 *) addr;
        mask = ((a & 0x80000000) == 0) ? (0xFF000000) : (((a & 0xC0000000) == 0x80000000) ? (0xFFFF0000) : (((a & 0xE0000000) == 0xC0000000) ? (0xFFFFFF00) : (0)));
        TLobby__sub_8040F8A4(net, (void *) (*new_var), mask, 2, d);
        break;

      case 1:

      case 3:
        NetMemcpy(addr, hdr + 4, 4);
        TLobby__sub_8040F8A4(*((u32 *) (ip + 16)), (void *) (*((u32 *) addr)), -1, 6, d);
        break;

    }

      return 0;

    default:
      return -1;

  }

  return 0;
}

s32 TUdpSocket__sub_8040CE58(u8 *p, u8 *b, s16 x, s16 id)
{
  s32 TLobby__sub_8040E780(u8 *rec, u32 dst, u32 src, u8 ttl, u8 tos, u8 df, void *proto); /* declared s32 here; the definition returns s16 */
  u8 *h;
  s32 lim;
  s32 r;
  if ((NetIPv4IsUnspecified(*((u32 *) (b + 0xc))) || NetIPv4IsLoopback(*((s32 *) (b + 0xc)))) || (TLobby__sub_8040FDA0(*((u32 *) (b + 0xc)), id) != 0))
  {
    return -1;
  }
  if (TLobby__sub_8040FDA0(*((u32 *) (b + 0x10)), id))
  {
    return -1;
  }
  h = alloc_free_entry();
  if (h == ((void *) 0))
  {
    return -1;
  }
  lim = (s16) ((b[0] << 2) & 0x3C);
  lim = lim + 8;
  x = (x < lim) ? (x) : (lim);
  *((s32 *) (h + 4)) = 0;
  *((s32 *) (h + 8)) = x;
  ((struct 
  {
    s16 v;
    u8 pad[10];
  } *) (h + 0xc))[*((s32 *) (h + 4))].v = x;
  set_value_and_enable(&(h + 0x10)[(*((s32 *) (h + 4))) * 12], (s32) b);
  *((s32 *) (h + 4)) += 1;
  *((s32 *) (h + 8)) += 8;
  ((struct 
  {
    s16 v;
    u8 pad[10];
  } *) (h + 0xc))[*((s32 *) (h + 4))].v = 8;
  set_value_and_enable(&(h + 0x10)[(*((s32 *) (h + 4))) * 12], (s32) p);
  *((s32 *) (h + 4)) += 1;
  *((u16 *) (p + 2)) = 0;
  *((u16 *) (p + 2)) = calc_ip_checksum(h, 1);
  r = TLobby__sub_8040E780(h, *((u32 *) (b + 0xc)), *((u32 *) (b + 0x10)), 0, 0, 0, (void *) 1);
  release_entry(h);
  return r;
}

typedef struct Icmp4Header {
    u8 type;
    u8 code;
    u16 checksum;
    u8 rest[4];
} Icmp4Header;
typedef char Icmp4Header_size_check[sizeof(Icmp4Header) == 8 ? 1 : -1];
s16 TLobby__sub_8040CFE8(u8 type, u8 code, u32 src, u32 dst, NetPacket *pkt) {
    NetBufferRef ref;
    Icmp4Header hdr;

    switch (type) {
    case 0:
        set_value_and_enable((&ref), (s32)&hdr);
        TLobby__sub_80406FD8(&ref, &pkt->fragments[pkt->fragment_count - 1].buffer, sizeof(hdr));
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
    hdr.checksum = calc_ip_checksum((pkt), 1);
    if (TLobby__sub_8040E780((u8 *)pkt, dst, src, 0, 0, 0, (void *)1)) {
        return -1;
    }
    return 0;
}
