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


/* Inline the helpers below; this applies to the rest of the file. */
#pragma dont_inline off
#pragma inline_depth(4)

u16 TUdpSocket__sub_80419864();

s32 NetIPv6Shutdown(void) {
    release_slot_by_id(0x86DD);
    TLobby__sub_803F87DC(&ipv6_protocol_state);
    ipv6_protocol_state.nsockets = 0;
    return 0;
}

s32 TLobby__sub_8040FFF8(u8 *ip, int len, s16 id);
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
    register_protocol_handler(0x86DD, (NetProtocolHandler)TLobby__sub_8040FFF8);
    return 0;
}

inline s16 opts_8040FFF8(u8 *p, s16 rem, u8 *ip, s16 m, s16 id) {
    s16 TLobby__sub_80410958(u8 *, s16, u8 *, s16, s16);
    s16 n;
    u8 *d;
    d = p + 2;
    n = ((p[1] + 1) << 3) - 2;
    if (n > rem) {
        return -1;
    }
    if (TLobby__sub_80410958(d, n, ip, m, id) < 0) {
        return -1;
    }
    return 0;
}

struct IC_8040FFF8 { u8 type; u8 code; s32 w; };
inline u8 *frag_8040FFF8(u8 *ip, u8 *p, s32 rem, s16 m, s16 id, void *sa, struct IC_8040FFF8 *ic) {
    s32 TLobby__sub_80418C40(u8 *, u8 *, s16, u8, u32, void *, u16, u8, s16);
    u32 fl;
    u32 mf;
    u32 off;
    fl = *((u16 *) (p + 2));
    mf = fl & 1;
    off = (fl >> 3) & 0x1FFF;
    if (((u8) fl & 1) && (((rem - 8) & 7) != 0)) {
        if (off == 0) {
            ic->type = 4;
            ic->code = 0;
            ic->w = 4;
            TLobby__sub_8040D510(ic, ip, m, id);
        }
        return 0;
    }
    return (u8 *) TLobby__sub_80418C40(ip, (u8 *) (m - (rem - 8)), rem - 8, 60, *((u32 *) (p + 4)), sa, off, mf, id);
}
inline s32 min_8040FFF8(s32 a, s32 b) {
    if (a < b) {
        return a;
    }
    return b;
}

inline u8 *buildrec_8040FFF8(u8 *ip, s16 m, u8 *p, s32 rem) {
    u8 *rec = alloc_free_entry();
    if (rec == 0) {
        return 0;
    }
    *(s32 *)(rec + 4) = 0;
    *(s32 *)(rec + 8) = m;
    ((struct { u16 v; u8 pad[10]; } *)(rec + 0xc))[*(s32 *)(rec + 4)].v = m - rem;
    set_value_and_enable(rec + 0x10 + *(s32 *)(rec + 4) * 12, (s32)ip);
    *(s32 *)(rec + 4) += 1;
    ((struct { u16 v; u8 pad[10]; } *)(rec + 0xc))[*(s32 *)(rec + 4)].v = rem;
    set_value_and_enable(rec + 0x10 + *(s32 *)(rec + 4) * 12, (s32)p);
    *(s32 *)(rec + 4) += 1;
    return rec;
}

#pragma push
#pragma opt_loop_invariants off
s32 TLobby__sub_8040FFF8(u8 *ip, int len, s16 id)
{
  s16 TLobby__sub_8040D510(void *, u8 *, s32, s16); /* declared here with an s32 3rd argument; the definition takes s16 */
  s16 TLobby__sub_804105E0(u8 *, u8 *, s16, s16); /* declared s16 here; the definition returns s32 */
  s16 TLobby__sub_804136CC(s16); /* declared s16 here; the definition returns void */
  s16 TLobby__sub_804136EC(void *); /* declared s16 here; the definition returns s32 */
  s16 NetIPv6CompareAddresses(void *, void *); /* declared s16 here; the definition is s32 (s32, s32) */
  s16 TLobby__sub_8041B974(void *, void *, void *); /* declared s16 here; the definition is s32 (u8 *, u8 *, u8 *) */
  s16 udp_input(void *, void *, void *, s16); /* declared s16 here; the definition is s32 (O_80420DE4 *, NetworkAddress *, NetworkAddress *, s32) */
  s32 TLobby__sub_80421938(void *, void *, void *, u32, s16); /* declared here with other parameter types; the definition is s32 (O_80421938 *, void *, void *, void *, s32) */
  struct 
  {
    s32 t;
    u8 a[16];
  } sa;
  struct 
  {
    s32 t;
    u8 a[16];
  } da;
  struct 
  {
    u8 type;
    u8 code;
    s32 w;
  } ic44;
  struct 
  {
    u8 type;
    u8 code;
    s32 w;
  } ic36;
  struct IC_8040FFF8 ic28;
  u8 *p;
  u8 *new_var2;
  u8 *rec;
  s16 m;
  Ipv6RawSocket *ent;
  s16 i;
  s32 rem;
  u8 *new_var4;
  u8 *new_var3;
  s16 new_var;
  s16 res;
  u8 *last;
  s16 reasm;
  Ipv6ProtocolState *g;
  u8 *src;
  u8 nh;
  s16 r;
  s16 found;
  u8 *dst;
  new_var = id;
  if (((s16) len) < 40)
  {
    goto ret;
  }
  if (get_valid_entry(new_var) == 0)
  {
    goto ret;
  }
  if ((ip[0] & 0xF0) != 0x60)
  {
    return -1;
  }
  m = min_8040FFF8((*((u16 *) (ip + 4))) + 40, (s16) len);
  if (TLobby__sub_804136CC(new_var) == 0)
  {
    if (TLobby__sub_804136EC(ip + 24) < ((char) 0))
    {
      if (NetIPv6IsMulticast(ip + 24) == 0)
      {
        if (TLobby__sub_804105E0(ip, ip, m, new_var) == 0)
        {
          return 0;
        }
        return -1;
      }
    }
  }
  sa.t = 6;
  new_var3 = ip + 8;
  src = sa.a;
  NetMemcpy(src, new_var3, 16);
  da.t = 6;
  dst = da.a;
  NetMemcpy(dst, ip + 24, 16);
  nh = ip[6];
  rem = m - 40;
  new_var2 = ip;
  p = new_var2 + 40;
  last = new_var2 + 6;
  reasm = 0;
  new_var4 = dst;
  found = 0;
  for (;;)
  {
    if (nh == 59)
    {
      return 0;
    }
    if (((s16) rem) < 8)
    {
      ic44.type = 4;
      ic44.code = 1;
      ic44.w = last - new_var2;
      TLobby__sub_8040D510(&ic44, new_var2, m, new_var);
      goto ret;
    }
    switch (nh)
    {
      case 0:
        if (m != (((s16) rem) + 40))
      {
        ic36.type = 4;
        ic36.code = 1;
        ic36.w = last - new_var2;
        TLobby__sub_8040D510(&ic36, new_var2, m, new_var);
        res = -1;
      }
      else
      {
        res = opts_8040FFF8(p, rem, new_var2, m, new_var);
      }
        if (res < 0)
      {
        goto ret;
      }
        goto adv;

      case 1:

      case 4:

      case 50:

      case 51:

      case 44:
        rec = frag_8040FFF8(new_var2, p, rem, m, new_var, &sa, &ic28);
        if (rec == 0)
      {
        return -1;
      }
        nh = p[0];
        reasm = 1;
        goto payload;

      case 60:
        res = opts_8040FFF8(p, rem, new_var2, m, new_var);
        if (res < 0)
      {
        goto ret;
      }

      case 43:
        adv:
      last = p;

        nh = p[0];
        rem -= (p[1] + 1) << 3;
        p += (p[1] + 1) << 3;
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
  if (reasm == 0)
  {
    rec = buildrec_8040FFF8(new_var2, m, p, rem);
    if (rec == 0)
    {
      return -257;
    }
  }

  switch (nh)
  {
    case 58:
      r = NetIPv6HandleIcmpMessage((NetPacket *)(rec), src, dst, new_var2[7], new_var);
      if (r < 0)
    {
      goto fail;
    }
      found = 1;
      break;

    case 6:
      r = TLobby__sub_8041B974(rec, &sa, &da);
      if (r < 0)
    {
      goto fail;
    }
      goto ok;

    case 17:
      r = udp_input(rec, &sa, &da, new_var);
      if (r >= 0)
    {
      goto ok;
    }
      switch (r)
    {
      case -2:
        ic44.type = 1;
        ic44.code = 4;
        ic44.w = 0;
        TLobby__sub_8040D510(&ic44, new_var2, m, new_var);
        goto fail;

      default:
        goto fail;

    }

    default:
      break;

  }

  g = &ipv6_protocol_state;
  ent = g->sockets;
  for (i = 0; i < g->nsockets; i++)
  {
    if (((ent->used == 1) && (ent->proto == nh)) && (ent->owner != 0))
    {
      if ((NetIPv6IsUnspecified(ent->local) != 0) || (NetIPv6CompareAddresses(ent->local, src) == 0))
      {
        if ((NetIPv6IsUnspecified(ent->remote) != 0) || (NetIPv6CompareAddresses(ent->remote, new_var4) == 0))
        {
          TLobby__sub_80421938(rec, src, dst, ent->owner, i);
          found = 1;
        }
      }
    }
    ent++;
  }

  if (found == 1)
  {
    ok:
    if (reasm == 1)
    {
      TUdpSocket__sub_80418BD8((NetPacket *) rec);
    }

    release_entry(rec);
    return 0;
  }
  if (reasm != 1)
  {
    ic44.type = 4;
    ic44.code = 1;
    ic44.w = last - new_var2;
    TLobby__sub_8040D510(&ic44, new_var2, m, new_var);
  }
  fail:
  if (reasm == 1)
  {
    TUdpSocket__sub_80418BD8((NetPacket *) rec);
  }

  release_entry(rec);
  ret:
  return -1;

}
#pragma pop

extern s32 TLobby__sub_80410958(u8* p, s16 n, u8* self, s16 c, s16 d);
static inline s16 chk_804105E0(u8 *p, s16 lim, s16 ctx, s16 l, s16 rem, u8 *q, u8 *prev) {
    s16 TLobby__sub_80410958(u8 *, s16, u8 *, s16, s16);
    u8 err4[8];
    s32 n;
    u8 *d;
    if (l != rem + 0x28) {
        err4[0] = 4;
        err4[1] = 1;
        *(s32 *)(err4 + 4) = prev - p;
        TLobby__sub_8040D510(err4, p, lim, ctx);
        return -1;
    }
    d = q + 2;
    n = ((q[1] + 1) << 3) - 2;
    if ((s16)n > rem) {
        return -1;
    }
    if (TLobby__sub_80410958(d, n, p, lim, ctx) < 0) {
        return -1;
    }
    return 0;
}
#pragma push
#pragma opt_common_subs on
#pragma opt_propagation off
extern s32 TLobby__sub_804105E0(u8 *self, u8 *p, s16 lim, s16 ctx)
{
  s32 TLobby__sub_80410BA8(void *, void *, s16, void *); /* declared s32 here; the definition returns s16 */
  s32 TLobby__sub_80415D0C(u8 *a, u8 *b, u8 *c, s16 d); /* declared s32 here; the definition is s16 (NetPacket *, u8 *, NetIPv6SendParameters *, s16) */
  s16 TLobby__sub_804136AC(s16); /* declared s16 here; the definition returns s32 */
  u8 loc[8];
  u8 out2[0x10];
  u8 out1[0x10];
  u8 err[8];
  s32 tot;
  u8 *e;
  s16 rem;
  u8 *q;
  Ipv6Route *hit;
  u8 *new_var;
  u8 *prev;
  s16 l;
  s16 flag;
  s16 h6;
  u16 flags;
  u8 state;
  u8 *dst;
  s32 adv;
  s32 r21;
  l = lim;
  tot = l - 0x28;
  new_var = &loc[6];
  rem = tot;
  q = p + 0x28;
  prev = p + 6;
  flag = 0;
  *((s32 *) loc) = *((s32 *) self);
  *((u16 *) (loc + 4)) = *((u16 *) self);
  loc[7] = self[6];
  state = self[7];
  loc[6] = state;
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

  if (((*new_var) == 0) || ((--loc[6]) == 0))
  {
    if ((flag == 0) || (flags == 0))
    {
      err[0] = 3;
      err[1] = 0;
      *((s32 *) (err + 4)) = 0;
      TLobby__sub_8040D510(err, p, lim, ctx);
    }
    return -1;
  }
  hit = TLobby__sub_80413264(self + 0x18, self + 8);
  if (hit == ((void *) 0))
  {
    if ((flag == 0) || (flags == 0))
    {
      err[0] = 1;
      err[1] = 0;
      *((s32 *) (err + 4)) = 0;
      TLobby__sub_8040D510(err, p, lim, ctx);
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
      err[0] = 2;
      err[1] = 0;
      *((s32 *) (err + 4)) = h6;
      TLobby__sub_8040D510(err, p, lim, ctx);
    }
    return -1;
  }
  e = alloc_free_entry();
  if (e == ((void *) 0))
  {
    return -1;
  }
  *((s32 *) (e + 4)) = 0;
  *((s32 *) (e + 8)) = tot;
  ((struct 
  {
    s16 v;
    u8 pad[10];
  } *) (e + 0xc))[*((s32 *) (e + 4))].v = (s16) tot;
  set_value_and_enable((void *) ((e + ((*((s32 *) (e + 4))) * 12)) + 0x10), (s32) (p + 0x28));
  *((s32 *) (e + 4)) = (*((s32 *) (e + 4))) + 1;
  NetMemcpy(out1, self + 8, 0x10);
  NetMemcpy(out2, self + 0x18, 0x10);
  if ((NetIPv6IsMulticast(dst) == 0) && (TLobby__sub_804136AC(hit->iface) != 0))
  {
    r21 = TLobby__sub_80415D0C(e, dst, out1, hit->iface);
  }
  else
  {
    r21 = TLobby__sub_80410BA8(e, out1, hit->iface, 0);
  }
  release_entry((void *) e);
  return r21;
}
#pragma pop
s32 TLobby__sub_80410958(u8* p, s16 n, u8* self, s16 c, s16 d) {
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
                    u8 pad[2];
                    u32 c;
                } msg;

                msg.a = 4;
                msg.b = 2;
                msg.c = cur - self;
                TLobby__sub_8040D510(&msg, self, c, d);
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

s16 TLobby__sub_80410A98(s32 arg0, void *arg1, void *arg2, void *arg3, void *arg4)
{
  u8 tmp[12];
  volatile struct 
  {
    s32 x;
    s16 h;
    u8 y;
    u8 d;
  } rec;
  u8 *new_var;
  u8 buf2[16];
  u8 buf1[16];
  Ipv6Route *p;
  u8 *q;
  s16 TLobby__sub_804136AC(s16); /* declared s16 here; the definition returns s32 */
  p = TLobby__sub_80413264(arg1, arg2);
  if (p == ((void *) 0))
  {
    return -6;
  }
  if (p->type == 1)
  {
    q = (u8 *) arg1;
  }
  else
  {
    q = p->gateway;
  }
  if (arg3 == ((void *) 0))
  {
    NetMemset(tmp, 0, 0xc);
    arg3 = tmp;
  }
  rec.x = *((s32 *) (((u8 *) arg3) + 4));
  new_var = q;
  rec.h = ((u8 *) arg3)[0];
  rec.y = ((u8 *) arg3)[8];
  rec.d = (u8) ((s32) arg4);
  NetMemcpy(buf1, arg2, 0x10);
  NetMemcpy(buf2, arg1, 0x10);
  if ((!NetIPv6IsMulticast(q)) && TLobby__sub_804136AC(p->iface))
  {
    return TLobby__sub_80415D0C((NetPacket *) arg0, new_var, (NetIPv6SendParameters *) buf1, p->iface);
  }
  return TLobby__sub_80410BA8((void *) arg0, buf1, p->iface, (void *) 0);
}

s16 TLobby__sub_80410D6C(u8 *ctx, u8 *hdr, s16 a5, s32 a6, u32 len);
s16 TLobby__sub_80410BA8(void *self, void *a, s16 c, void *d)
{
  Ipv6ProtocolState *base = &ipv6_protocol_state;
  s32 new_var;
  u32 used = ((NetPacket *) self)->total_bytes;
  Ipv6Header *slot = &base->hdr;
  s32 n;
  s32 off;
  s16 ret;
  s32 pad2[2];
  if (used == 0)
  {
    return 0;
  }
  slot->version_class_flow = 0;
  if (((NetIPv6SendParameters *) a)->flow_label)
  {
    slot->version_class_flow = (((NetIPv6SendParameters *) a)->flow_label) & 0xFFFFF;
  }
  else
  {
    slot->version_class_flow = base->flow_label;
  }
  if (((NetIPv6SendParameters *) a)->traffic_class_bits)
  {
    *((u16 *) slot) |= (((NetIPv6SendParameters *) a)->traffic_class_bits) & 0xFF0;
  }
  else
  {
    *((u16 *) slot) |= base->traffic_class;
  }
  *((u8 *) slot) = 0x60;
  slot->payload_length = used;
  slot->next_header = ((NetIPv6SendParameters *) a)->next_header;
  if (((NetIPv6SendParameters *) a)->hop_limit)
  {
    slot->hop_limit = ((NetIPv6SendParameters *) a)->hop_limit;
  }
  else
  {
    slot->hop_limit = base->hop_limit;
  }
  NetMemcpy(&slot->src, &((NetIPv6SendParameters *) a)->source, sizeof(IPv6Address));
  NetMemcpy(&slot->dst, &((NetIPv6SendParameters *) a)->destination, sizeof(IPv6Address));
  ret = TLobby__sub_80411C44(((NetIPv6SendParameters *) a)->destination.bytes, c);
  if (ret < 0)
  {
    return ret;
  }
  n = ret - (s32)sizeof(Ipv6Header);
  base->ident += 1;
  new_var = n;
  if (used > ((u32) n))
  {
    return TLobby__sub_80410D6C((u8 *) self, (u8 *) slot, c, (s32) d, new_var);
  }
  ((NetPacket *) self)->total_bytes += sizeof(Ipv6Header);
  ((NetPacketFragment *) (((u8 *) self) + offsetof(NetPacket, fragments)))[((NetPacket *) self)->fragment_count].length = sizeof(Ipv6Header);
  off = ((NetPacket *) self)->fragment_count * (s32)sizeof(NetPacketFragment);
  set_value_and_enable((((u8 *) self) + off) + offsetof(NetPacket, fragments[0].buffer), (s32) slot);
  ((NetPacket *) self)->fragment_count += 1;
  if (NetIPv6IsMulticast(((NetIPv6SendParameters *) a)->destination.bytes))
  {
    return TLobby__sub_804112B8((s32) self, (s32) &((NetIPv6SendParameters *) a)->destination, c);
  }
  return TLobby__sub_8041123C((s32) self, (s32) d, c);
}

#pragma push
#pragma opt_common_subs on
extern s16 TLobby__sub_80410D6C(u8 *ctx, u8 *hdr, s16 a5, s32 a6, u32 len)
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
    NetPacket *pc;
    s32 flen;
    s16 r;

    pc = (NetPacket *)ctx;
    if (len < 8) {
        return -6;
    }
    fh.next_header = hdr[offsetof(Ipv6Header, next_header)];
    fh.reserved = 0;
    fh.offset_flags = 0;
    fh.ident = ipv6_protocol_state.ident;
    hdr[offsetof(Ipv6Header, next_header)] = 0x2c;
    limit = len - 8;
    limit &= 0xFFF8;
    iovp = &iov;
    off = 0;
    while (pc->total_bytes != 0) {
        iov.total_bytes = 0;
        iov.fragment_count = 0;
        for (i = pc->fragment_count - 1; i >= 0; i--) {
            if (iov.total_bytes + (flen = pc->fragments[i].length) < limit) {
                iov.total_bytes += pc->fragments[i].length;
                iov.fragment_count++;
            } else {
                iov.total_bytes = limit;
                iov.fragment_count++;
                break;
            }
        }
        k = iov.fragment_count - 1;
        j = pc->fragment_count - 1;
        rem = iov.total_bytes;
        while (k >= 0 && rem > 0) {
            NetMemcpy(&iovp->fragments[k].buffer, &pc->fragments[j].buffer, sizeof(NetBufferRef));
            if (rem < pc->fragments[j].length) {
                iovp->fragments[k].length = rem;
                pc->total_bytes -= rem;
                pc->fragments[j].length -= rem;
                TLobby__sub_80406EB8(&pc->fragments[j].buffer, rem);
                break;
            }
            iovp->fragments[k].length = pc->fragments[j].length;
            rem -= pc->fragments[j].length;
            pc->total_bytes -= pc->fragments[j].length;
            pc->fragments[j].length = 0;
            pc->fragment_count--;
            k--;
            j--;
        }
        fh.offset_flags = off & 0xFFF8;
        if (pc->total_bytes != 0) {
            fh.offset_flags |= 1;
        }
        off += (s16)iov.total_bytes;
        iov.total_bytes += 8;
        iovp->fragments[iov.fragment_count].length = 8;
        set_value_and_enable(&iovp->fragments[iov.fragment_count].buffer, (s32)&fh);
        iov.fragment_count++;
        *(u16 *)(hdr + offsetof(Ipv6Header, payload_length)) = iov.total_bytes;
        iov.total_bytes += 40;
        iovp->fragments[iov.fragment_count].length = 40;
        set_value_and_enable(&iovp->fragments[iov.fragment_count].buffer, (s32)hdr);
        iov.fragment_count++;
        if (NetIPv6IsMulticast(hdr + offsetof(Ipv6Header, dst))) {
            r = TLobby__sub_804112B8((s32)iovp, (s32)(hdr + offsetof(Ipv6Header, dst)), a5);
        } else {
            r = TLobby__sub_8041123C((s32)iovp, a6, a5);
        }
        if (r < 0) {
            break;
        }
    }
    return r;
}
#pragma pop

typedef struct PH_80411040 { IPv6Address src; IPv6Address dst; u32 len; u8 zero[3]; u8 next_header; } PH_80411040;
typedef char PH_80411040_size_check[sizeof(PH_80411040) == 0x28 ? 1 : -1];
extern u16 TLobby__sub_80411040(const struct IPv6Address *src, const struct IPv6Address *dst, u8 next_header, const struct NetPacket *pkt, s16 flag) {
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
    sum = TUdpSocket__sub_80419864(&ph, sizeof(ph) / 2);
    sum += TLobby__sub_80406BD8(pkt, flag);
    sum = (sum >> 16) + (sum & 0xFFFF);
    sum += sum >> 16;
    return ~sum;
}

Ipv6ProtocolState ipv6_protocol_state;
