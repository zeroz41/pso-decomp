#include "pso/network/UdpRuntime.h"
#include "pso/network/SocketEvents.h"
#include "pso/network/NetworkDispatch.h"
#include "pso/network/NetworkRuntime.h"
#include "pso/network/TLobby_804048E8.h"
#include "pso/network/TLobby_803FC178.h"
#include "pso/network/NetworkPacketPool.h"
#include "pso/network/netcfg.h"
#include "pso/network/BufferRef.h"
#include "pso/network/IPv6.h"

#include "types.h"
#include "pso/network/TLobby_803FCF44.h"
#include "pso/network/TLobby_804050DC.h"
#include "pso/network/TLobby_8041112C.h"
s32 compare_sockaddr(NetworkAddress *a, NetworkAddress *b);
s32 init_packet_fragment_pools(void);

#include <stddef.h>

#include "pso/network/IPv6Send.h"
#include "pso/network/NetStackTypes.h"

u16 TUdpSocket__sub_80419864(); /* declared without a parameter list; the definition is u16 (p, n) */

s32 NetUnregisterTimer(void* p);

/* Inline the helpers below; this applies to the rest of the file. */
#pragma dont_inline off
#pragma inline_depth(4)

s32 TUdpSocket__sub_8040CE58(u8 *p, u8 *b, s16 x, s16 id);

s16 TLobby__sub_8040D510(void *a, u8 *src, s16 c, s16 flag);

s32 TLobby__sub_80418A7C(void) {
    NetFragPool *g = &packet_fragment_pool_state;
    NetUnregisterTimer((void *)update_timeout_entries);
    TLobby__sub_803F89A0(g);
    g->npackets = 0;
    g->nfrags = 0;
    return 0;
}

s32 init_packet_fragment_pools(void) {
    s16 i;
    NetFragPacket *a;
    NetFragment *b;
    NetFragPool *g = &packet_fragment_pool_state;

    TLobby__sub_803F89A4(&packet_fragment_pool_state);
    g->tail = 0;
    g->head = 0;
    a = g->packets;
    for (i = 0; i < g->npackets; i++) {
        NetMemset(a, 0, sizeof(NetFragPacket));
        a->tag[0] = 'F';
        a->tag[1] = 'P';
        a->tag[2] = 'K';
        a->index = i;
        a->used = 0;
        a++;
    }
    b = g->frags;
    for (i = 0; i < g->nfrags; i++) {
        NetMemset(b, 0, sizeof(NetFragment));
        b->tag[0] = 'F';
        b->tag[1] = 'R';
        b->tag[2] = 'G';
        b->index = i;
        b->used = 0;
        b++;
    }
    NetRegisterTimer(1000, (s16)(1), (NetTimerCallback)(update_timeout_entries));
    return 0;
}

/* Frees the buffers of a packet's fragments. */
s32 TUdpSocket__sub_80418BD8(NetPacket *a) {
    u32 i;
    NetPacket *b = a;
    for (i = 0; i < b->fragment_count; i++) {
        TLobby__sub_80406B6C(&b->fragments[i].buffer);
    }
    return 0;
}

NetFragPacket *TLobby__sub_8041955C(NetworkAddress *src, s32 ident, s32 ttl);
s32 TLobby__sub_80419470(void* a, void* b);
s32 TLobby__sub_80418C40(u8* self, void* p1, s16 p2, u8 p3, u32 p4, void* p5, u16 p6, u8 p7, s16 p8)
{
    NetFragPacket* TLobby__sub_8041955C(NetworkAddress *, u32, u8); /* declared here with other parameter types; the definition is NetFragPacket * (NetworkAddress *, s32, s32) */
    s32 TLobby__sub_80418D7C(NetFragPacket*, u8*, void*, u16, u16, u8, s16); /* declared here with other parameter types; the definition is s32 (NetFragPacket *, u8 *, u16, u16, u16, u8, s16) */
    s16 compare_sockaddr(NetworkAddress *, NetworkAddress *); /* declared s16 here; the definition returns s32 */
    NetFragPool* base = &packet_fragment_pool_state;
    s16 count;
    s32 ret;
    NetFragPacket* node;

    count = 0;
    node = base->head;
    while (node != NULL && count < base->npackets) {
        if (compare_sockaddr(&node->src, p5) == 0 && node->ident == p4) {
            ret = TLobby__sub_80418D7C(node, self, p1, p6, p2, p7, p8);
            if (ret == 0) {
                return 0;
            }
            TLobby__sub_80419470(p5, (void*)p4);
            return ret;
        }
        node = node->next;
        count++;
    }
    node = TLobby__sub_8041955C(p5, p4, p3);
    if (node == NULL) {
        return 0;
    }
    ret = TLobby__sub_80418D7C(node, self, p1, p6, p2, p7, p8);
    if (ret == 0) {
        return 0;
    }
    TLobby__sub_80419470(p5, (void*)p4);
    return ret;
}

inline NetFragment *take_80418D7C(NetFragment **pb, s16 *pn) {
    s16 n;
    s16 i;
    NetFragment *ent;
    ent = *pb;
    n = *pn;
    for (i = 0; i < n; i++) {
        if (ent->used == 0) {
            ent->used = 1;
            ent->offset = 0;
            ent->len = 0;
            ent->next = 0;
            return ent;
        }
        ent++;
    }
    return 0;
}
inline s16 contig_80418D7C(NetFragPacket *node, s16 *pn, NetFragPool *g) {
    s16 lim;
    NetFragment *f;
    u32 acc;
    s16 n;
    s16 cnt;
    acc = 0;
    f = node->first;
    cnt = *pn;
    n = 0;
    lim = g->max_frags;
    while (f != 0 && cnt > 0) {
        if (f->offset != (u16)acc) {
            return -1;
        }
        n++;
        if (n > lim) {
            return -1;
        }
        acc += f->len / 8;
        cnt--;
        f = f->next;
    }
    return 0;
}
/* Adds a fragment (frag_off in 8-byte units; more = the more-fragments flag) to node; returns the reassembled
   packet once every fragment is there, else 0.  tail holds the last fragment and then the new packet, and self
   the data and then the fragment being copied: separate typed variables colour differently. */
s32 TLobby__sub_80418D7C(NetFragPacket *node, u8 *self, u16 hdr_len, u16 frag_off, u16 frag_len, u8 more, s16 iface)
{
  s32 TLobby__sub_8041979C(void);
  NetFragment **new_var;
  NetFragPool *g = &packet_fragment_pool_state;
  u32 c16;
  NetFragment **pb;
  s16 *pn;
  NetFragment *e;
  u8 *tail;
  NetFragment *head;
  NetFragment *cur;
  NetFragment *n0;
  s16 i;
  s16 n;
  s16 res;
  s32 len;
  s16 ls;
  s32 sum;
  NetPacketFragment *ep;
  u32 off;
  NetFragment *nx;
  s16 cnt;
  NetBufferRef tmp;
  if (frag_off == 0)
  {
    node->hdr_len = hdr_len;
    node->iface = iface;
  }
  else
  {
    self += hdr_len;
  }
  new_var = &g->frags;
  if ((e = take_80418D7C(pb = new_var, pn = &g->nfrags)) == 0)
  {
    reset_other_connection_lists(node);
    if ((e = take_80418D7C(pb, pn)) == 0)
    {
      return 0;
    }
  }
  e->offset = frag_off;
  e->len = frag_len;
  set_value_and_enable(&tmp, (s32) self);
  if (frag_off == 0)
  {
    ls = (sum = frag_len + hdr_len);
    if (TLobby__sub_80415954(&e->data, ls, 2) < 0)
    {
      reset_other_connection_lists(node);
      if (TLobby__sub_80415954(&e->data, ls, 2) < 0)
      {
        e->used = 0;
        e->next = 0;
        return 0;
      }
    }
    TLobby__sub_80406FD8(&e->data, &tmp, sum);
  }
  else
  {
    len = frag_len;
    if (TLobby__sub_80415954(&e->data, len, 2) < 0)
    {
      reset_other_connection_lists(node);
      if (TLobby__sub_80415954(&e->data, len, 2) < 0)
      {
        e->used = 0;
        e->next = 0;
        return 0;
      }
    }
    TLobby__sub_80406FD8(&e->data, &tmp, frag_len);
  }
  e->next = 0;
  head = node->first;
  if (head == 0)
  {
    node->last = e;
    node->first = e;
  }
  else
  {
    tail = (u8 *)node->last;
    off = e->offset;
    if (off > *(u16 *)(tail + offsetof(NetFragment, offset)))
    {
      *(NetFragment **)(tail + offsetof(NetFragment, next)) = e;
      node->last = e;
    }
    else
      if (off < head->offset)
    {
      e->next = head;
      node->first = e;
    }
    else
    {
      n0 = head->next;
      cnt = *pn;
      cur = head;
      nx = n0;
      if (n0 == 0)
      {
        TLobby__sub_80406B6C(&e->data);
        e->used = 0;
        e->next = 0;
        return 0;
      }
      while ((nx != 0) && (cnt > 0))
      {
        c16 = cur->offset;
        if ((off > c16) && (off < nx->offset))
        {
          e->next = nx;
          cur->next = e;
          break;
        }
        if (off == c16)
        {
          TLobby__sub_80406B6C(&e->data);
          e->used = 0;
          e->next = 0;
          break;
        }
        cur = cur->next;
        cnt--;
        nx = nx->next;
      }

    }
  }
  if (node->have_last == 0)
  {
    if (more != 0)
    {
      return 0;
    }
    node->have_last = 1;
  }
  res = contig_80418D7C(node, pn, g);
  if (res < 0)
  {
    return 0;
  }
  tail = (u8 *)alloc_free_entry();
  if (tail == 0)
  {
    TLobby__sub_8041979C();
    return 0;
  }
  *(u32 *)(tail + offsetof(NetPacket, fragment_count)) = 0;
  *(u32 *)(tail + offsetof(NetPacket, total_bytes)) = 0;
  ep = (NetPacketFragment *)(tail + offsetof(NetPacket, fragments[1]));
  n = 0;
  i = 0;
  self = (u8 *)node->first;
  cnt = *pn;
  while ((self != 0) && (cnt > 0))
  {
    if (i == 0)
    {
      NetMemcpy(tail + offsetof(NetPacket, fragments[0].buffer), self + offsetof(NetFragment, data), 8);
      *(u32 *)(tail + offsetof(NetPacket, fragment_count)) = 1;
      i++;
      *(u32 *)(tail + offsetof(NetPacket, total_bytes)) = node->hdr_len;
      *(s16 *)(tail + offsetof(NetPacket, fragments[0].length)) = node->hdr_len;
      NetMemcpy(&ep->buffer, self + offsetof(NetFragment, data), 8);
      *(u32 *)(tail + offsetof(NetPacket, fragment_count)) += 1;
      *(u32 *)(tail + offsetof(NetPacket, total_bytes)) += *(u16 *)(self + offsetof(NetFragment, len));
      ep->length = *(s16 *)(self + offsetof(NetFragment, len));
      n = 2;
      TLobby__sub_80406EB8(&ep->buffer, node->hdr_len);
    }
    else
    {
      NetMemcpy(tail + offsetof(NetPacket, fragments[0].buffer) + n * sizeof(NetPacketFragment), self + offsetof(NetFragment, data), 8);
      *(u32 *)(tail + offsetof(NetPacket, fragment_count)) += 1;
      *(u32 *)(tail + offsetof(NetPacket, total_bytes)) += *(u16 *)(self + offsetof(NetFragment, len));
      *(s16 *)(tail + offsetof(NetPacket, fragments[0].length) + i * sizeof(NetPacketFragment)) = *(s16 *)(self + offsetof(NetFragment, len));
      n++;
    }
    cur = (NetFragment *)self;
    self = *(u8 **)(self + offsetof(NetFragment, next));
    cur->used = 0;
    cnt--;
    i++;
    cur->next = 0;
  }

  return (s32) tail;
}

s32 TLobby__sub_80419374(NetFragPacket *pkt);

/* Once a second: datagrams whose time ran out are dropped (after an ICMP time-exceeded message). */
void update_timeout_entries(void) {
    NetFragPool *g;
    NetFragPacket **head;
    NetFragPacket **tail;
    s16 n;
    s16 m;
    NetFragment *p;
    NetFragment *q;
    NetFragPacket *e;
    NetFragPacket *cur;
    NetFragPacket *prev;

    g = &packet_fragment_pool_state;
    head = &g->head;
    tail = &g->tail;

    prev = NULL;
    n = 0;
    cur = *head;
    while (cur != NULL && n < g->npackets) {
        if (cur->ttl != 0) {
            cur->ttl--;
        }
        if (cur->ttl != 0) {
            prev = cur;
            cur = cur->next;
        } else {
            TLobby__sub_80419374(cur);
            p = cur->first;
            m = 0;
            while (p != NULL && m < g->nfrags) {
                q = p;
                p = p->next;
                TLobby__sub_80406B6C(&q->data);
                q->used = 0;
                m++;
                q->next = 0;
            }
            if (prev != NULL) {
                prev->next = cur->next;
            } else {
                *head = cur->next;
            }
            if (*tail == cur) {
                *tail = prev;
            }
            e = cur;
            cur = cur->next;
            e->used = 0;
            e->next = 0;
            e->iface = 0;
        }
        n++;
    }
}

/* Sends the ICMP (family 4) or ICMPv6 (family 6) "fragment reassembly time exceeded" error for pkt, if its
   first fragment has arrived. */
s32 TLobby__sub_80419374(NetFragPacket *pkt) {
/* declared here with an s32 length and result; the definitions take an s16 length and TLobby__sub_8040D510 returns s16 */
s32 TLobby__sub_8040D510(void *a, u8 *src, s32 c, s16 flag);
s32 TUdpSocket__sub_8040CE58(u8 *p, u8 *b, s32 x, s16 id); /* declared here with an s32 3rd argument; the definition takes s16 */
void* q;
s32 type;
s32 total;
if (pkt->first == NULL) {
return 0;
}
if (pkt->first->offset != 0) {
return 0;
}
q = TLobby__sub_80406F0C(&pkt->first->data);
if (q == ((void*)0) ) {
return -1;
}
type = pkt->src.family;
total = pkt->hdr_len + pkt->first->len;
switch (type) {
case 4: {
struct {
u8 type;
u8 code;
u16 checksum;
u32 unused;
} msg;
msg.type = 0xb;
msg.code = 1;
msg.unused = 0;
return TUdpSocket__sub_8040CE58((void*)(&msg), (u8*)(q), (s32)(total), pkt->iface);
}
case 6: {
NetIcmpv6Header msg;
msg.type = 3;
msg.code = 1;
msg.reserved = 0;
return TLobby__sub_8040D510((void*)(&msg), (u8*)(q), (s32)(total), pkt->iface);
}
default:
return -1;
}
}

s32 TLobby__sub_80419470(void* a, void* b) {
    s16 compare_sockaddr(NetworkAddress *, NetworkAddress *); /* declared s16 here; the definition returns s32 */
    NetFragPool* tbl = &packet_fragment_pool_state;
    NetFragPacket** headp;
    s16 count;
    NetFragPacket* node;
    NetFragPacket* prev;

    if (*(headp = &tbl->head) == NULL) {
        return -1;
    }
    node = *headp;
    prev = NULL;
    count = 0;
    while (node != NULL && count < tbl->npackets) {
        if (compare_sockaddr(&node->src, a) == 0 && node->ident == (u32)b) {
            NetFragPacket** tp;
            if (prev != NULL) {
                prev->next = node->next;
            } else {
                *headp = node->next;
            }
            if (*(tp = &tbl->tail) == node) {
                *tp = prev;
            }
            node->used = 0;
            node->next = NULL;
            node->iface = 0;
            return 0;
        }
        prev = node;
        node = node->next;
        count++;
    }
    return -1;
}

extern s32 TLobby__sub_8041979C(void);
#pragma push
#pragma opt_propagation off
/* Takes a free datagram for (src, ident), freeing everything else if none is left, and appends it to the list. */
NetFragPacket *TLobby__sub_8041955C(NetworkAddress *src, s32 ident, s32 ttl)
{
  NetFragPacket *e;
  NetFragPacket **ent;
  NetFragPool *base;
  NetFragPacket **t;
  s16 count;
  s16 n2;
  s16 i;
  NetFragPacket *r;
  base = &packet_fragment_pool_state;
  ent = &base->packets;
  count = base->npackets;
  e = *ent;
  i = 0;
  while (i < count)
  {
    if (e->used == 0)
    {
      e->used = 1;
      e->hdr_len = 0;
      e->ident = 0;
      NetMemset(&e->src, 0, sizeof(NetworkAddress));
      e->ttl = 0;
      e->have_last = 0;
      e->next = 0;
      e->last = 0;
      e->first = 0;
      goto found;
    }
    i++;
    e++;
  }

  e = 0;
  found:
  if (e == 0)
  {
    TLobby__sub_8041979C();
    e = *ent;
    n2 = base->npackets;
    i = 0;
    while (i < n2)
    {
      if (e->used == 0)
      {
        e->used = 1;
        e->hdr_len = 0;
        e->ident = 0;
        NetMemset(&e->src, 0, sizeof(NetworkAddress));
        e->ttl = 0;
        e->have_last = 0;
        e->next = 0;
        e->last = 0;
        e->first = 0;
        goto found2;
      }
      i++;
      e++;
    }

    e = 0;
    found2:
    if (!e)
    {
      return 0;
    }
  }

  t = &base->head;
  if (*t == 0)
  {
    base->tail = e;
    *t = e;
  }
  else
  {
    base->tail->next = e;
    base->tail = e;
  }
  NetMemcpy(&e->src, src, sizeof(NetworkAddress));
  e->ident = ident;
  e->have_last = 0;
  e->ttl = (u8) ttl;
  e->next = 0;
  e->last = 0;
  e->first = 0;
  r = e;
  return r;
}
#pragma pop
/* Frees every other datagram being reassembled to make room for self, which becomes the only one in the list. */
s32 reset_other_connection_lists(void *obj) {
    NetFragPacket *self = (NetFragPacket *)obj;
    NetFragPool *g = &packet_fragment_pool_state;
    NetFragment *p;
    NetFragment *cur;
    NetFragPacket *e;
    s16 n;

    n = g->npackets;
    e = g->packets;
    for (; n > 0; n--, e++) {
        if (e->used == 1 && e != self) {
            p = e->first;
            while (p != NULL) {
                cur = p;
                p = p->next;
                TLobby__sub_80406B6C(&cur->data);
                cur->used = 0;
                cur->next = 0;
            }
            e->used = 0;
            e->next = 0;
            e->iface = 0;
        }
    }
    self->next = 0;
    g->head = self;
    g->tail = self;
    return 0;
}

/* Frees every datagram and fragment. */
s32 TLobby__sub_8041979C(void) {
    NetFragPacket *e;
    s16 n;
    s16 n2;
    NetFragment *e2;
    NetFragPool *base;
    base = &packet_fragment_pool_state;
    n = base->npackets;
    e = base->packets;
    while (n > 0) {
        if (e->used == 1) {
            e->used = 0;
            e->next = 0;
            e->iface = 0;
        }
        n--;
        e++;
    }
    n2 = base->nfrags;
    e2 = base->frags;
    while (n2 > 0) {
        if (e2->used == 1) {
            TLobby__sub_80406B6C(&e2->data);
            e2->used = 0;
            e2->next = 0;
        }
        n2--;
        e2++;
    }
    base->head = 0;
    base->tail = 0;
    return 0;
}

u16 TUdpSocket__sub_80419864(p, n)
    u8 *p;
    s16 n;
{
    u16 tmp[2];
    u32 sum;
    u32 odd;
    u32 hi;
    if (n <= 0) {
        return 0;
    }
    tmp[0] = 0;
    odd = 0;
    sum = 0;
    if ((u32)p & 1) {
        ((u8*)tmp)[1] = *p;
        p++;
        n--;
        odd = 1;
    }
    while (n > 0) {
        if ((((u32)p & 0xF) == 0) && (n >= 8)) {
            break;
        }
        sum += *(u16*)p;
        p += 2;
        n--;
    }
    if (n > 8) {
        sum += *(u16*)p;
        n--;
        while (n > 8) {
            sum += *(u16*)(p + 8);
            sum += *(u16*)(p + 2);
            sum += *(u16*)(p + 4);
            sum += *(u16*)(p + 6);
            sum += *(u16*)(p + 16);
            sum += *(u16*)(p + 10);
            sum += *(u16*)(p + 12);
            sum += *(u16*)(p + 14);
            p += 16;
            n -= 8;
        }
        p += 2;
    }
    while (n >= 8) {
        sum += *(u16*)(p + 0);
        sum += *(u16*)(p + 2);
        sum += *(u16*)(p + 4);
        sum += *(u16*)(p + 6);
        sum += *(u16*)(p + 8);
        sum += *(u16*)(p + 10);
        sum += *(u16*)(p + 12);
        sum += *(u16*)(p + 14);
        p += 16;
        n -= 8;
    }
    while (n > 0) {
        sum += *(u16*)p;
        p += 2;
        n--;
    }
    if (odd) {
        ((u8*)tmp)[0] = *p;
        sum += tmp[0];
        hi = sum >> 24;
        sum <<= 8;
        sum |= hi;
    }
    sum = (sum >> 16) + (sum & 0xFFFF);
    sum += sum >> 16;
    return (u16)sum;
}

NetFragPool packet_fragment_pool_state;
