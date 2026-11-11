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
u16 calc_ip_checksum(void *self, s16 b);
u16 calc_pseudo_header_checksum(s32 src, s32 dst, s8 proto, void *pkt, s16 flag);
s32 init_ipv4_interfaces(void);
void release_entry(void *self);

#include <stddef.h>


#include "pso/network/IPv6Send.h"
#include "pso/network/NetStackTypes.h"

extern RecoveredGlobal_8040DD68_lbl_805C1B38 ipv4_protocol_state;

/* Inline the helpers below; this applies to the rest of the file. */
#pragma dont_inline off
#pragma inline_depth(4)

u16 TUdpSocket__sub_80419864();

s32 TLobby__sub_8040DD68(void) {
    release_slot_by_id(0x800);
    TLobby__sub_803F892C((void *)((void *) (&ipv4_protocol_state.value)));
    ipv4_protocol_state.value = 0;
    return 0;
}

s32 TUdpSocket__sub_8040DE4C(u8 *ip, s16 x, s16 id);
s32 init_ipv4_interfaces(void) {
    s16 i;
    E_8040DDB0 *e;
    RecoveredGlobal_8040DD68_lbl_805C1B38 *g = &ipv4_protocol_state;

    TLobby__sub_803F8930((u8 *)&g->value);
    e = g->ents;
    for (i = 0; i < g->value; i++) {
        e->c0 = 0x49;
        e->c1 = 0x50;
        e->c2 = 0x34;
        e->c3 = i;
        e->f4 = 0;
        e++;
    }
    g->f8 = 1;
    register_protocol_handler(0x800, (NetProtocolHandler)TUdpSocket__sub_8040DE4C);
    return 0;
}

s32 TUdpSocket__sub_8040DE4C(u8 *ip, s16 x, s16 id)
{
  u8 *p;
  u8 *g;
  u8 hl;
  s16 r;
  s16 n;
  s16 found;
  s16 i;
  u32 tl;
  s32 rr;
  u32 fl;
  int new_var2;
  unsigned char mf;
  u32 s;
  s16 TLobby__sub_8040FE40(s16); /* declared s16 here; the definition returns s32 */
  s32 TLobby__sub_80418C40(u8* self, void* p1, s16 p2, u8 p3, u32 p4, void* p5, u16 p6, u8 p7, s16 p8);
  s16 TLobby__sub_8041B974(void *, void *, void *); /* declared s16 here; the definition is s32 (u8 *, u8 *, u8 *) */
  s16 udp_input(void *, void *, void *, s16); /* declared s16 here; the definition is s32 (O_80420DE4 *, NetworkAddress *, NetworkAddress *, s32) */
  s32 TLobby__sub_80421AD8(u8 *, u32, u32, u32, s16); /* declared here with other parameter types; the definition is s32 (u8 *, s32, s32, u32, s32) */
  u16 TUdpSocket__sub_80419864(void *, s16);
  struct 
  {
    s32 t;
    u32 a;
    u8 pad[0xC];
  } src;
  struct 
  {
    s32 t;
    u32 a;
    u8 pad[0xC];
  } dst;
  struct 
  {
    u8 type;
    u8 code;
    s32 w;
  } ic;
  u8 padx[12];
  if (x < 5)
  {
    return -1;
  }
  if (get_active_entry_by_index(id) == 0)
  {
    return -1;
  }
  src.t = 4;
  NetMemcpy(&src.a, ip + 12, 4);
  dst.t = 4;
  NetMemcpy(&dst.a, ip + 16, 4);
  hl = (ip[0] << 2) & 0x3C;
  tl = *((u16 *) (ip + 2));
  n = tl - hl;
  if (hl < 20)
  {
    return -1;
  }
  if ((ip[0] >> 4) != 4)
  {
    return -1;
  }
  s = TUdpSocket__sub_80419864(ip, (s16) (hl >> 1));
  s = (s >> 16) + (s & 0xFFFF);
  s += s >> 16;
  if (((u16) (~s)) != 0)
  {
    return -1;
  }
  if (tl < hl)
  {
    return -1;
  }
  if (id != 0)
  {
    if (TLobby__sub_8040FCEC(dst.a) < 0)
    {
      if (TLobby__sub_8040FDA0(dst.a, id) == 0)
      {
        if (TLobby__sub_8040FE40(id) != 0)
        {
          r = TUdpSocket__sub_8040E354((u8 *) dst.a, src.a, ip, x, id);
          if (0 > r)
          {
            return -1;
          }
          return -1;
        }
      }
    }
  }
  fl = *((u16 *) (ip + 6));
  if (fl & (~0x4000))
  {
    mf = (fl & 0x2000) ? (1) : (0);
    ip = (u8 *) TLobby__sub_80418C40(ip, (void *) hl, n, ip[8], *((u16 *) (ip + 4)), &src, fl & 0x1FFF, mf, id);
    if (ip == 0)
    {
      return 0;
    }
    n = 1;
  }
  else
  {
    ip = alloc_free_entry();
    if (ip == 0)
    {
      return -257;
    }
    *((s32 *) (ip + 4)) = (new_var2 = 0);
    *((s32 *) (ip + 8)) = tl;
    ((struct 
    {
      s16 v;
      u8 pad[10];
    } *) (ip + 0xc))[*((s32 *) (ip + 4))].v = hl;
    set_value_and_enable((ip + 0x10) + ((*((s32 *) (ip + 4))) * 12), (s32) ip);
    *((s32 *) (ip + 4)) += 1;
    ((struct 
    {
      s16 v;
      u8 pad[10];
    } *) (ip + 0xc))[*((s32 *) (ip + 4))].v = n;
    set_value_and_enable((ip + 0x10) + ((*((s32 *) (ip + 4))) * 12), (s32) (ip + hl));
    *((s32 *) (ip + 4)) += 1;
    n = 0;
  }
  switch (ip[9])
  {
    case 1:
      found = 1;
      r = TLobby__sub_8040CB44(ip, src.a, dst.a);
      if (r < 0)
    {
      if (n == 1)
      {
        TUdpSocket__sub_80418BD8((NetPacket *) ip);
      }
      release_entry(ip);
      return -1;
    }
      if (n == 1)
    {
      TUdpSocket__sub_80418BD8((NetPacket *) ip);
    }
      release_entry(ip);
      break;

    case 6:
      r = TLobby__sub_8041B974(ip, &src, &dst);
      if (r < 0)
    {
      if (n == 1)
      {
        TUdpSocket__sub_80418BD8((NetPacket *) ip);
      }
      release_entry(ip);
      return -1;
    }
      if (n == 1)
    {
      TUdpSocket__sub_80418BD8((NetPacket *) ip);
    }
      release_entry(ip);
      return 0;

    case 17:
      r = udp_input(ip, &src, &dst, id);
      if (r < 0)
    {
      switch (r)
      {
        case -2:
          ic.type = 3;
          ic.code = 3;
          ic.w = 0;
          rr = TUdpSocket__sub_8040CE58((u8 *) (&ic), ip, x, id);
          if (n == 1)
        {
          TUdpSocket__sub_80418BD8((NetPacket *) ip);
        }
          release_entry(ip);
          return rr;

        default:
          if (n == 1)
        {
          TUdpSocket__sub_80418BD8((NetPacket *) ip);
        }
          release_entry(ip);
          return -1;

      }

    }
      if (n == 1)
    {
      TUdpSocket__sub_80418BD8((NetPacket *) ip);
    }
      release_entry(ip);
      return 0;

    default:
      found = 0;
      break;

  }

  g = (u8 *) (&ipv4_protocol_state);
  p = *((u8 **) (g + 4));
  for (i = 0; i < (*((s16 *) g)); i++)
  {
    if ((*((u16 *) (p + 4))) == 1)
    {
      if (((*((u32 *) (p + 8))) == 0) || ((*((u32 *) (p + 8))) == src.a))
      {
        if ((*((u8 *) (p + 24))) == ip[9])
        {
          if ((*((u32 *) (p + 16))) != 0)
          {
            TLobby__sub_80421AD8(ip, src.a, dst.a, *((u32 *) (p + 16)), i);
            found = 1;
          }
        }
      }
    }
    p += 28;
  }

  if (found == 1)
  {
    if (n == 1)
    {
      TUdpSocket__sub_80418BD8((NetPacket *) ip);
    }
    release_entry(ip);
    return 0;
  }
  ic.type = 3;
  ic.code = 2;
  ic.w = 0;
  TUdpSocket__sub_8040CE58((u8 *) (&ic), ip, x, id);
  if (n == 1)
  {
    TUdpSocket__sub_80418BD8((NetPacket *) ip);
  }
  release_entry(ip);
  return -1;
}

s16 TUdpSocket__sub_8040E354(u8 *self, u32 key, u8 *pkt, s16 total, s16 id)
{
  s16 TLobby__sub_8040EF00(s16);
  u16 TUdpSocket__sub_80419864(void *, s16);
  s16 cnt8;
  u8 *rt;
  u32 s;
  u8 hdr;
  int fl;
  s16 off;
  s16 mtu;
  s16 ifidx;
  u8 *target;
  u8 *rec;
  u16 flagsHi;
  s16 units;
  s32 frag;
  s16 cnt;
  s16 rem;
  s32 hl;
  s32 df;
  u8 *payload;
  u16 t46;
  u16 t44;
  u16 g1[2];
  s16 t36;
  u16 t34;
  s16 r;
  u8 g2[10];
  s16 len;
  hdr = (pkt[0] << 2) & 0x3C;
  if (hdr == 20)
  {
    len = total - 20;
  }
  else
  {
    len = total - hdr;
  }
  if (len <= 0)
  {
    return -1;
  }
  NetMemcpy(&t46, pkt + 6, 2);
  frag = t46;
  flagsHi = frag & (~0x1FFF);
  t46 = flagsHi;
  df = frag & 0x4000;
  off = frag & 0xFF;
  if (((u8) (pkt[8] - 1)) < 1)
  {
    return -1;
  }
  pkt[8] = pkt[8] - 1;
  rt = TLobby__sub_8040F76C((u32) self, key);
  if (rt == 0)
  {
    return -6;
  }
  ifidx = *((s16 *) (rt + 2));
  if ((*((s16 *) (rt + 18))) == 1)
  {
    target = self;
  }
  else
  {
    target = *((u8 **) (rt + 12));
  }
  mtu = TLobby__sub_8040EF00(ifidx);
  if (mtu < 0)
  {
    return mtu;
  }
  if (mtu < (hdr + len))
  {
    if (df & 0xFF)
    {
      return -1;
    }
    rec = alloc_free_entry();
    if (rec == 0)
    {
      return -257;
    }
    rem = len;
    payload = pkt + hdr;
    units = (mtu - hdr) / 8;
    do
    {
      if (mtu > (rem + (hl = hdr)))
      {
        t46 = flagsHi;
        cnt8 = rem % 8;
        cnt = rem / 8;
        mtu = rem;
      }
      else
      {
        t46 |= 0x2000;
        cnt = units;
        cnt8 = 0;
      }
      t36 = off;
      t36 |= t46;
      NetMemcpy(pkt + 6, &t36, 2);
      fl = cnt8 + (cnt << 3);
      t34 = hl + fl;
      NetMemcpy(pkt + 2, &t34, 2);
      NetMemset(pkt + 10, 0, 2);
      s = TUdpSocket__sub_80419864(pkt, hl / 2);
      s = (s >> 16) + (s & 0xFFFF);
      s += s >> 16;
      t44 = ~s;
      NetMemcpy(pkt + 10, &t44, 2);
      *((s32 *) (rec + 4)) = 0;
      *((s32 *) (rec + 8)) = (u16) fl;
      *((s16 *) ((rec + ((*((s32 *) (rec + 4))) * 12)) + 12)) = fl;
      set_value_and_enable((rec + 0x10) + ((*((s32 *) (rec + 4))) * 12), (s32) payload);
      *((s32 *) (rec + 4)) += 1;
      *((s32 *) (rec + 8)) += hdr;
      *((s16 *) ((rec + ((*((s32 *) (rec + 4))) * 12)) + 12)) = hdr;
      set_value_and_enable((rec + 0x10) + ((*((s32 *) (rec + 4))) * 12), (s32) pkt);
      *((s32 *) (rec + 4)) += 1;
      r = TLobby__sub_8040EDE4(rec, (u32) target, ifidx);
      if (r < 0)
      {
        release_entry(rec);
        break;
      }
      off += cnt;
      payload += cnt << 3;
      hdr = 20;
      if (mtu == rem)
      {
        rem = 0;
      }
      else
      {
        rem = rem - fl;
      }
    }
    while (rem > 0);
    release_entry(rec);
  }
  else
  {
    NetMemset(pkt + 10, 0, 2);
    s = TUdpSocket__sub_80419864(pkt, hdr / 2);
    s = (s >> 16) + (s & 0xFFFF);
    s += s >> 16;
    t44 = ~s;
    NetMemcpy(pkt + 10, &t44, 2);
    rec = alloc_free_entry();
    if (rec == 0)
    {
      return -257;
    }
    *((s32 *) (rec + 4)) = 0;
    *((s32 *) (rec + 8)) = len;
    ((struct 
    {
      s16 v;
      u8 pad[10];
    } *) (rec + 0xc))[*((s32 *) (rec + 4))].v = len;
    set_value_and_enable((rec + 0x10) + ((*((s32 *) (rec + 4))) * 12), (s32) (pkt + hdr));
    *((s32 *) (rec + 4)) += 1;
    *((s32 *) (rec + 8)) += hdr;
    ((struct 
    {
      s16 v;
      u8 pad[10];
    } *) (rec + 0xc))[*((s32 *) (rec + 4))].v = hdr;
    set_value_and_enable((rec + 0x10) + ((*((s32 *) (rec + 4))) * 12), (s32) pkt);
    *((s32 *) (rec + 4)) += 1;
    r = TLobby__sub_8040EDE4(rec, (u32) target, ifidx);
    release_entry(rec);
  }
  return r;
}

#pragma push
#pragma opt_common_subs on
s16 TLobby__sub_8040E780(u8 *rec, u32 dst, u32 src, u8 ttl, u8 tos, u8 df, void *proto)
{
  s16 tot;
  u8 *g;
  u8 *ent;
  u8 *ip;
  u8 *target;
  s16 ifidx;
  s16 mtu;
  s32 idx;
  s16 chunk;
  s32 units;
  s16 rem;
  s32 off;
  s16 last;
  s32 k;
  s32 i2;
  u8 *data;
  u8 *p;
  u8 *q;
  s32 j;
  s16 *lp;
  s16 r;
  u8 *new_var;
  u32 s;
  s16 TLobby__sub_8040EF00(s16); /* declared s16 here; the definition returns s32 */
  struct 
  {
    s64 a;
    u8 b[0x98];
  } loc;
  g = (u8 *) (&ipv4_protocol_state);
  ent = TLobby__sub_8040F76C(dst, src);
  if ((ent == 0) != 0)
  {
    return -6;
  }
  if (src == 0)
  {
    r = TLobby__sub_8040EF50(&src, *((u32 *) (ent + 12)), *((s16 *) (ent + 2)));
    if (r < 0)
    {
      return r;
    }
  }
  if (TLobby__sub_8040FDA0(src, *((s16 *) (ent + 2))) != 0)
  {
    r = TLobby__sub_8040EF50(&src, *((u32 *) (ent + 12)), *((s16 *) (ent + 2)));
    if (r < 0)
    {
      return r;
    }
  }
  ifidx = *((s16 *) (ent + 2));
  if ((*((s16 *) (ent + 18))) == 1)
  {
    target = (u8 *) dst;
  }
  else
  {
    target = *((u8 **) (ent + 12));
  }
  g[12] = 0x40;
  ip = g + 12;
  g[12] |= 5;
  if (tos != 0)
  {
    ip[1] = tos;
  }
  else
  {
    ip[1] = g[10];
  }
  if (ttl != 0)
  {
    ip[8] = ttl;
  }
  else
  {
    ip[8] = g[11];
  }
  tot = *((s32 *) (rec + 8));
  if (tot == 0)
  {
    return 0;
  }
  tot = tot + 20;
  *((s16 *) (ip + 2)) = tot;
  *((u16 *) (g + 8)) += 1;
  ip[9] = (u8) ((s32) proto);
  *((u16 *) (ip + 4)) = *((u16 *) (g + 8));
  NetMemcpy(ip + 12, &src, 4);
  NetMemcpy(ip + 16, &dst, 4);
  mtu = TLobby__sub_8040EF00(ifidx);
  if (mtu < 0)
  {
    return mtu;
  }
  if (tot <= mtu)
  {
    *((u16 *) (ip + 6)) = 0;
    if (df != 0)
    {
      *((u16 *) (ip + 6)) = 0x4000;
    }
    *((u16 *) (ip + 10)) = 0;
    if (!j)
    {
    }
    s = TUdpSocket__sub_80419864(ip, 10);
    s = (s >> 16) + (s & 0xFFFF);
    s += s >> 16;
    *((u16 *) (ip + 10)) = ~s;
    *((s32 *) (rec + 8)) += 20;
    ((struct 
    {
      s16 v;
      u8 pad[10];
    } *) (rec + 0xc))[*((s32 *) (rec + 4))].v = 20;
    set_value_and_enable((rec + 0x10) + ((*((s32 *) (rec + 4))) * 12), (s32) ip);
    *((s32 *) (rec + 4)) += 1;
    return TLobby__sub_8040EDE4(rec, (u32) target, ifidx);
  }
  off = 0;
  if (df != 0)
  {
    return -2;
  }
  chunk = (mtu - 20) / 8;
  chunk *= 8;
  units = chunk / 8;
  *((u16 *) (ip + 6)) = 0;
  ent = (u8 *) (&loc);
  do
  {
    *((s32 *) (ent + 4)) = 0;
    *((s32 *) (ent + 8)) = 0;
    rem = chunk;
    k = 0;
    j = (idx = (*((s32 *) (rec + 4))) - 1);
    p = rec + (j * 12);
    while ((rem > 0) && (j >= 0))
    {
      k++;
      p -= 12;
      rem -= *((s16 *) (p + 24));
      j--;
    }

    i2 = idx;
    j = (s16) k;
    j = j - 1;
    rem = chunk;
    last = 0;
    while ((rem > 0) && (j >= 0))
    {
      p = rec + (i2 * 12);
      q = ent + (((((((((((j * 12) & 0xFFFFFFFFFFFFFFFF) & 0xFFFFFFFFFFFFFFFF) & 0xFFFFFFFFFFFFFFFF) & 0xFFFFFFFFFFFFFFFF) & 0xFFFFFFFFFFFFFFFF) & 0xFFFFFFFFFFFFFFFF) & 0xFFFFFFFFFFFFFFFF) & 0xFFFFFFFFFFFFFFFF) & 0xFFFFFFFFFFFFFFFF) & 0xFFFFFFFFFFFFFFFF);
      data = p + 16;
      NetMemcpy(q + 16, data, 8);
      new_var = p + 12;
      lp = (s16 *) new_var;
      if ((*((s16 *) new_var)) > rem)
      {
        *((s16 *) (q + 12)) = rem;
        *((s32 *) (ent + 8)) += rem;
        *lp -= rem;
        *((s32 *) (rec + 8)) -= rem;
        TLobby__sub_80406EB8((NetBufferRef *)(data), rem);
        rem = 0;
      }
      else
      {
        *((s16 *) (q + 12)) = *((s16 *) new_var);
        *((s32 *) (ent + 8)) += *lp;
        *((s32 *) (rec + 8)) -= *lp;
        rem -= *lp;
        if (i2 == 0)
        {
          rem = *lp;
          last = 1;
          j--;
          i2--;
        }
        else
        {
          *((s32 *) (rec + 4)) -= 1;
          i2--;
          j--;
        }
      }
      *((s32 *) (ent + 4)) += 1;
    }

    if (last == 1)
    {
      *((u16 *) (ip + 6)) = 0;
    }
    else
    {
      *((u16 *) (ip + 6)) = 0x2000;
    }
    *((u16 *) (ip + 6)) |= off;
    *((u16 *) (ip + 2)) = (*((s32 *) (ent + 8))) + 20;
    *((u16 *) (ip + 10)) = 0;
    s = TUdpSocket__sub_80419864(ip, 10);
    s = (s >> 16) + (s & 0xFFFF);
    s += s >> 16;
    *((u16 *) (ip + 10)) = ~s;
    *((s32 *) (ent + 8)) += 20;
    *((s16 *) ((ent + ((*((s32 *) (ent + 4))) * 12)) + 12)) = 20;
    set_value_and_enable((ent + 0x10) + ((*((s32 *) (ent + 4))) * 12), (s32) ip);
    *((s32 *) (ent + 4)) += 1;
    r = TLobby__sub_8040EDE4(ent, (u32) target, ifidx);
    if (r < 0)
    {
      return r;
    }
    off += units;
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
    sum = TUdpSocket__sub_80419864(&ph, 6);
    sum += TLobby__sub_80406BD8(pkt, flag);
    sum = (sum >> 16) + (sum & 0xFFFF);
    sum += sum >> 16;
    return ~sum;
}

u16 calc_ip_checksum(void *self, s16 b) {
    u32 s = TLobby__sub_80406BD8(self, b);
    s = (s >> 16) + (s & 0xFFFF);
    s += (s >> 16);
    return ~s;
}

RecoveredGlobal_8040DD68_lbl_805C1B38 ipv4_protocol_state;
