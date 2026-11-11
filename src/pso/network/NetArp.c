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
NetPacket *alloc_packet_with_header(ArpFields *f, ArpIface *iface);
ArpEntry *find_free_peer_entry(void);
ArpEntry *find_oldest_peer_entry(s16 state);
ArpEntry *find_or_add_peer_entry(s16 handler, s32 socket, u8 plen, void *paddr, u8 hlen, void *haddr, s16 state);

#include <stddef.h>


#include "pso/network/IPv6Send.h"
#include "pso/network/NetStackTypes.h"

s32 TUdpSocket__sub_80407508(void);
void TLobby__sub_804073B8(void);
s32 TLobby__sub_80407C60(s16, s32);
s32 TLobby__sub_80407D98(s16, s32);
s16 TLobby__sub_80407F20(s16 a, s16 b, s16 c, s16 d, s16 e, s32 f, s16 g, s32 h);

/* Inline the helpers below; this applies to the rest of the file. */
#pragma dont_inline off
#pragma inline_depth(4)

s32 NetUnregisterTimer(void* p);
void TLobby__sub_804078B4(void);
s32 TLobby__sub_80407358(void) {
    ArpState *g = &lbl_805C1AB0;
    s32 tmp[2];
    release_slot_by_id(0x806);
    NetUnregisterTimer((void *)TLobby__sub_804078B4);
    TLobby__sub_803F8A24(g);
    g->nentries = 0;
    g->nifaces = 0;
    g->nholds = 0;
    g->naliases = 0;
    return 0;
}

void TLobby__sub_804073B8(void) {
    TUdpSocket__sub_80407508();
}

s32 dispatch_slot_a(s16 arg0, s32 arg1) {
    return TLobby__sub_80407C60(arg0, arg1);
}

s32 dispatch_slot_b(s16 arg0, s32 arg1) {
    return TLobby__sub_80407D98(arg0, arg1);
}

s32 TLobby__sub_80407418(s16 id) {
    ArpState *t = &lbl_805C1AB0;
    ArpIface *e;
    s16 ok;
    s32 tmp[2];

    e = t->ifaces;
    if (id >= 0 && id < t->nifaces) {
        ok = 1;
    } else {
        ok = -1;
    }
    if (ok >= 0) {
        e = &e[id];
    } else {
        e = NULL;
    }
    if (e == NULL) {
        return -2;
    }
    if (e->used == 0) {
        return -2;
    }
    call_entry_callback(e->handler, e->arp_socket);
    TLobby__sub_80408388(id);
    return 0;
}

s16 forward_net_op(s16 arg0, u8 *arg1, u8 *arg2) {
    return TLobby__sub_8040799C(arg0, arg1, arg2);
}

void forward_net_op_5args(s16 arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4, s32 arg5, s8 arg6, s32 arg7) {
    s16 TLobby__sub_80407F20(s16, s16, s16, s16, s16, s32, s8, s32);
    TLobby__sub_80407F20(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7);
}

extern s32 TLobby__sub_80407640(void *pkt, s16 a, s16 b, s16 c);
s32 TUdpSocket__sub_80407508(void)
{
    ArpState *tbl = &lbl_805C1AB0;
    s16 *step;
    ArpEntry *p;
    s16 j;
    ArpIface *p2;
    s16 i;
    ArpHold *q;
    s16 k;
    ArpAlias *p4;
    long sum;

    init_net_buffer_config(&lbl_805C1AB0);
    i = tbl->nentries;
    p = tbl->entries;
    for (; i > 0; i--) {
        NetMemset(p, 0, sizeof(ArpEntry));
        p->state = 0;
        p->hold = NULL;
        p++;
    }
    j = tbl->nifaces;
    p2 = tbl->ifaces;
    for (; j > 0; j--) {
        NetMemset(p2, 0, sizeof(ArpIface));
        p2++;
    }
    k = tbl->nholds;
    step = &tbl->hold_size;
    q = tbl->holds;
    sum = (long)tbl->hold_buffers;
    for (; k > 0; k--) {
        NetMemset(q, 0, sizeof(ArpHold));
        q->cap = *step;
        q->data = sum;
        q++;
        sum += *step;
    }
    j = tbl->naliases;
    p4 = tbl->aliases;
    for (; j > 0; j--) {
        NetMemset(p4, 0, sizeof(ArpAlias));
        p4++;
    }
    register_protocol_handler(0x806, (NetProtocolHandler)TLobby__sub_80407640);
    NetRegisterTimer(60000, 1, TLobby__sub_804078B4);
    return 0;
}

s32 TLobby__sub_804082AC(ArpIface *iface, ArpFields *f, void *haddr);
inline ArpIface *FindHit_80407640(ArpState *t, s16 b, s16 c) {
    ArpIface *hit;
    s16 i;
    s16 n;
    if (b < 0) {
        return NULL;
    }
    hit = t->ifaces;
    n = t->nifaces;
    for (i = 0; i < n; i++, hit++) {
        if (hit->used == 1 && hit->handler == b && hit->arp_socket == c) {
            return hit;
        }
    }
    return NULL;
}

inline s16 CheckPkt_80407640(ArpHeader *pkt, ArpIface *hit) {
    if (NetMemcmp(pkt, &hit->htype, 6) == 0) {
        if (pkt->op == 1 || pkt->op == 2) {
            return 1;
        }
    }
    return -1;
}

inline ArpEntry *FindPeer_80407640(ArpEntry *peer, s16 n, u8 ff, u8 *p2) {
    for (; n > 0; n--, peer++) {
        if (peer->plen == ff && peer->state != 0 && NetMemcmp(peer->paddr, p2, peer->plen) == 0) {
            return peer;
        }
    }
    return 0;
}
#pragma push
#pragma opt_common_subs on
extern s32 TLobby__sub_80407640(void *pkt, s16 a, s16 b, s16 c)
{
  s32 call_handler_by_index(s16 arg0, s16 arg1, s32 arg2, s32 arg3, s32 arg4); /* declared here with an s16 2nd argument; the definition takes s32 */
  s16 TLobby__sub_804082AC(ArpIface *, ArpFields *, void *); /* declared here with an s16 result; the definition returns s32 */
  ArpState *t = &lbl_805C1AB0;
  ArpHeader *pp;
  ArpIface *hit;
  ArpEntry *peer;
  u8 *p2;
  ArpFields in;
  u8 buf[8];
  ArpFields out;
  NetPacket *r;
  if (a < 8) {
    return -1;
  }
  if (b < 0) {
    return -1;
  }
  hit = FindHit_80407640(t, b, c);
  if (hit == NULL) {
    return -1;
  }
  pp = (ArpHeader *) pkt;
  if (CheckPkt_80407640(pp, hit) < 0) {
    return -1;
  }
  in.hdr = pp;
  p2 = (u8 *)pp + sizeof(ArpHeader);
  in.sha = p2;
  p2 += hit->hlen;
  in.spa = p2;
  p2 += hit->plen;
  in.tha = p2;
  p2 += hit->hlen;
  in.tpa = p2;
  peer = FindPeer_80407640(t->entries, t->nentries, hit->plen, in.spa);
  if (peer != NULL) {
    find_or_add_peer_entry(hit->handler, hit->socket, hit->plen, in.spa, hit->hlen, in.sha, 2);
  }
  if (pp->op == 1) {
    if (TLobby__sub_804082AC(hit, &in, buf) > 0) {
      r = alloc_packet_with_header(&out, hit);
      if (r != NULL) {
        out.hdr->op = 2;
        NetMemcpy(out.sha, buf, hit->hlen);
        NetMemcpy(out.tha, in.sha, hit->hlen);
        NetMemcpy(out.spa, in.tpa, hit->plen);
        NetMemcpy(out.tpa, in.spa, hit->plen);
        call_handler_by_index(hit->handler, c, 0, (s32)in.sha, (s32)r);
        if (r != NULL) {
          release_entry((void *)r);
        }
      }
    }
  }
  return 0;
}
#pragma pop
void TLobby__sub_804078B4(void) {
    ArpEntry* p;
    s16 n;
    n = lbl_805C1AB0.nentries;
    p = lbl_805C1AB0.entries;
    for (; n > 0; n--, p++) {
        if (p->state != 0) {
            if (p->timer != 0) {
                p->timer--;
            }
            if (p->timer == 0 && p->state != 4 && p->state != 8) {
                if (p->hold != NULL) {
                    if (p->hold != NULL) {
                        p->hold->entry = NULL;
                        p->hold->len = 0;
                        p->hold->used = 0;
                    }
                    p->hold = NULL;
                }
                p->state = 0;
                p->timer = 0;
                NetMemset(p->haddr, 0, sizeof(p->haddr));
                NetMemset(p->paddr, 0, sizeof(p->paddr));
            }
        }
    }
}

void TLobby__sub_80408060(ArpEntry *entry, NetPacket *pkt);

inline ArpIface *Lookup_8040799C(ArpState *t, s16 idx) {
    ArpIface *list = t->ifaces;
    s16 ok;
    if (idx >= 0 && idx < t->nifaces) {
        ok = 1;
    } else {
        ok = -1;
    }
    if (ok >= 0) {
        return &list[idx];
    }
    return NULL;
}

inline ArpEntry *Find_8040799C(ArpState *t, u8 k, void *name) {
    s16 n = t->nentries;
    ArpEntry *p = t->entries;
    for (; n > 0; n--, p++) {
        if (p->plen == k && p->state != 0 && NetMemcmp(p->paddr, name, p->plen) == 0) {
            return p;
        }
    }
    return NULL;
}

inline void Clear_8040799C(ArpEntry *p) {
    if (p->hold != NULL) {
        p->hold->entry = NULL;
        p->hold->len = 0;
        p->hold->used = 0;
    }
}

inline void Send_8040799C(ArpIface *e, void *name) {
    ArpFields o;
    NetPacket *r = alloc_packet_with_header(&o, e);
    if (r != NULL) {
        o.hdr->op = 1;
        NetMemcpy(o.sha, e->haddr, e->hlen);
        NetMemcpy(o.spa, e->paddr, e->plen);
        NetMemset(o.tha, 0, e->hlen);
        NetMemcpy(o.tpa, name, e->plen);
        call_handler_by_index(e->handler, e->arp_socket, 1, 0, (s32)r);
        if (r != NULL) {
            release_entry((void *)r);
        }
    }
}

s16 TLobby__sub_8040799C(s16 idx, void *name, void *arg2) {
    ArpState *t = &lbl_805C1AB0;
    ArpIface *e;
    ArpEntry *p;
    s16 ret;
    ArpEntry *np;

    e = Lookup_8040799C(t, idx);
    if (e == NULL) {
        return -2;
    }
    ret = 0;
    p = Find_8040799C(t, e->plen, name);
    if (p != NULL) {
        p->timer = t->timeout;
        if (p->state != 1) {
            ret = call_handler_by_index(e->handler, e->socket, 0, (s32)p->haddr, (s32)arg2);
        } else {
            if (p->hold != NULL) {
                Clear_8040799C(p);
                p->hold = NULL;
            }
            TLobby__sub_80408060(p, arg2);
            Send_8040799C(e, name);
            p->timer = t->retry;
        }
    } else {
        u8 buf[6];
        NetMemset(buf, 0, 6);
        np = find_or_add_peer_entry(e->handler, e->socket, e->plen, name, e->hlen, buf, 1);
        TLobby__sub_80408060(np, arg2);
        Send_8040799C(e, name);
        np->timer = t->retry;
    }
    return ret;
}

s32 TLobby__sub_80407C60(s16 id, s32 key) {
    ArpState *tbl = &lbl_805C1AB0;
    ArpIface *base = tbl->ifaces;
    s16 ok;
    ArpIface *e;
    ArpAlias *p;
    ArpAlias *prev;
    s16 i;
    u8 pad[8];
    if (id >= 0 && id < tbl->nifaces) {
        ok = 1;
    } else {
        ok = -1;
    }
    if (ok >= 0) {
        e = base + id;
    } else {
        e = NULL;
    }
    if (e == NULL) {
        return -1;
    }
    if (e->used == 0) {
        return -1;
    }
    if (e->aliases == NULL) {
        return -1;
    }
    p = e->aliases;
    i = 0;
    while (p->next != NULL) {
        i++;
        if (tbl->naliases <= i) {
            return -1;
        }
        if (NetMemcmp(p->addr, (void *)key, 4) == 0) {
            if (e->aliases == p) {
                e->aliases = p->next;
            } else {
                prev->next = p->next;
            }
            p->next = NULL;
            p->used = 0;
            return 0;
        }
        prev = p;
        p = p->next;
    }
    return -1;
}

inline ArpIface *lookup2_80407D98(ArpState *t, s16 idx) {
    ArpIface *list = t->ifaces;
    s16 ok;
    if (idx >= 0 && idx < t->nifaces) {
        ok = 1;
    } else {
        ok = -1;
    }
    if (ok >= 0) {
        return list + idx;
    }
    return NULL;
}
inline ArpAlias *alloc2_80407D98(ArpState *t, s16 *count) {
    ArpAlias *p = t->aliases;
    s16 n = *count;
    for (; n > 0; n--, p++) {
        if (p->used == 0) {
            p->used = 1;
            p->next = NULL;
            NetMemset(p->addr, 0, 4);
            return p;
        }
    }
    return NULL;
}
s32 TLobby__sub_80407D98(s16 id, s32 pkey) {
    s16 lim;
    ArpAlias *next;
    ArpAlias *p;
    ArpIface *e;
    ArpAlias *node;
    s16 *max;
    ArpState *t = &lbl_805C1AB0;
    s16 k;

    e = lookup2_80407D98(t, id);
    if (e == NULL) {
        return -1;
    }
    if (e->used == 0) {
        return -1;
    }
    node = alloc2_80407D98(t, max = &t->naliases);
    if (node == NULL) {
        return -1;
    }
    NetMemcpy(node->addr, (void *)pkey, 4);
    node->used = 1;
    node->next = NULL;
    if (e->aliases == NULL) {
        e->aliases = node;
    } else {
        lim = *max;
        p = e->aliases;
        k = 0;
        while ((next = p->next) != NULL) {
            k++;
            if (lim <= k) {
                return -1;
            }
            p = next;
        }
        p->next = node;
    }
    return 0;
}

inline ArpIface *findfree_80407F20(ArpIface *base) {
    ArpIface *p;
    s16 i;
    p = base;
    for (i = 0; i < lbl_805C1AB0.nifaces; i++, p++) {
        if (p->used == 0) {
            return p;
        }
    }
    return NULL;
}

s16 TLobby__sub_80407F20(s16 a, s16 b, s16 c, s16 d, s16 e, s32 f, s16 g, s32 h)
{
    ArpIface *base;
    ArpIface *slot;
    s16 res;
    s16 idx;
    s16 TLobby__sub_8040A044(s16, u32, s16, u32 *); /* declared here with an s16 result and 3rd argument; the definition is s32 (s16, u32, s32, u32 *) */
    s32 call_entry_callback(s16, s16); /* declared here with an s16 2nd argument; the definition takes s32 */

    if (a < 0) {
        return -1;
    }
    res = TLobby__sub_8040A044(a, 0x806, g, (u32 *)h);
    if (res < 0) {
        return res;
    }
    base = lbl_805C1AB0.ifaces;
    slot = findfree_80407F20(base);
    if (slot == NULL) {
        call_entry_callback(a, res);
        return -0x10d;
    }
    slot->used = 1;
    idx = (s16)(slot - base);
    slot->handler = a;
    slot->socket = b;
    slot->arp_socket = res;
    slot->index = idx;
    slot->htype = c;
    slot->ptype = d;
    slot->hlen = e;
    slot->plen = g;
    slot->f10 = 0;
    NetMemcpy(slot->haddr, (void *)f, e);
    NetMemcpy(slot->paddr, (void *)h, g);
    slot->aliases = NULL;
    return idx;
}
extern void TLobby__sub_80408060(ArpEntry *entry, NetPacket *pkt) {
u8 tmp[0x8];
ArpHold *found;
s16 sum = 0;
ArpHold *best = NULL;
ArpHold *e = lbl_805C1AB0.holds;
s16 n = lbl_805C1AB0.nholds;
found = NULL;
while (n > 0)
{
if (e->used == 0)
{
found = e;
break;
}
if (best == NULL)
{
best = e;
}
else
if (e->entry->timer < best->entry->timer)
{
best = e;
}
e++;
n--;
}
if (found == NULL)
{
ArpEntry *o_m = best->entry;
if (o_m->hold != NULL)
{
o_m->hold->entry = NULL;
o_m->hold->len = 0;
o_m->hold->used = 0;
}
o_m->hold = NULL;
found = best;
}
if (found->cap < ((s16) pkt->total_bytes))
{
return;
}
{
NetPacketFragment *p;
s16 k;
s32 src;
found->used = 1;
k = (s16) pkt->fragment_count;
src = found->data;
p = pkt->fragments + k - 1;
while (k > 0)
{
set_value_and_enable(tmp, src);
TLobby__sub_80406FD8((void *)(tmp), (void *)&pkt->fragments[k - 1].buffer, (s32)p->length);
src += p->length;
sum += p->length;
p--;
k--;
}
}
found->len = sum;
found->entry = entry;
entry->hold = found;
}

NetPacket *alloc_packet_with_header(ArpFields *f, ArpIface *iface) {
    s16 len;
    NetPacket *pkt;
    u8 *buf;
    u16 t;
    u8 *q;
    t = iface->hlen * 2 + 8;
    t += iface->plen * 2;
    len = t;
    if ((u32)len > 0x1CU) {
        return NULL;
    }
    pkt = (NetPacket *)alloc_free_entry();
    if (pkt == NULL) {
        return NULL;
    }
    pkt->fragment_count = 1;
    pkt->total_bytes = len;
    buf = (u8 *)&lbl_805C1AB0.packet;
    pkt->fragments[0].length = t;
    set_value_and_enable(&pkt->fragments[0].buffer, (s32)*(u8 **)buf);
    buf = *(u8 **)buf;
    NetMemset(buf, 0, len);
    NetMemcpy(buf, &iface->htype, 6);
    f->hdr = (ArpHeader *)buf;
    q = buf + sizeof(ArpHeader);
    f->sha = q;
    q += iface->hlen;
    f->spa = q;
    q += iface->plen;
    f->tha = q;
    q += iface->hlen;
    f->tpa = q;
    return pkt;
}

s32 TLobby__sub_804082AC(ArpIface *iface, ArpFields *f, void *haddr) {
    s16 i;
    ArpAlias *p;

    if (NetMemcmp(iface->paddr, f->tpa, iface->plen) == 0) {
        NetMemcpy(haddr, iface->haddr, iface->hlen);
        return 1;
    }
    if (iface->aliases != NULL) {
        p = iface->aliases;
        i = 0;
        while (p != NULL) {
            i++;
            if (lbl_805C1AB0.naliases <= i) {
                return -1;
            }
            if (NetMemcmp(p->addr, f->tpa, iface->plen) == 0) {
                NetMemcpy(haddr, iface->haddr, iface->hlen);
                return 1;
            }
            p = p->next;
        }
    }
    return -1;
}

s32 TLobby__sub_80408388(s16 id) {
    ArpState *t = &lbl_805C1AB0;
    ArpIface *e;
    ArpAlias *n;
    ArpAlias *next;
    s16 ok;

    e = t->ifaces;
    if (id >= 0 && id < t->nifaces) {
        ok = 1;
    } else {
        ok = -1;
    }
    if (ok >= 0) {
        e = &e[id];
        for (n = e->aliases; n != NULL; n = next) {
            next = n->next;
            n->next = NULL;
            n->used = 0;
        }
        NetMemset(e, 0, sizeof(ArpIface));
        return 1;
    }
    return -1;
}

inline ArpEntry *find_80408428(ArpState *t, u8 plen, void *paddr) {
    s16 n = t->nentries;
    ArpEntry *e = t->entries;
    while (n > 0) {
        if (e->plen == plen && e->state != 0 && NetMemcmp(e->paddr, paddr, e->plen) == 0) {
            return e;
        }
        n--;
        e++;
    }
    return NULL;
}

inline void detach_80408428(ArpEntry *e) {
    if (e->hold != NULL) {
        e->hold->entry = NULL;
        e->hold->len = 0;
        e->hold->used = 0;
    }
    e->hold = NULL;
}

ArpEntry *find_or_add_peer_entry(s16 handler, s32 socket, u8 plen, void *paddr, u8 hlen, void *haddr, s16 state) {
    ArpState *t = &lbl_805C1AB0;
    ArpEntry *e;
    NetPacket *p;

    e = find_80408428(t, plen, paddr);
    if (e != NULL) {
        e->timer = t->timeout;
        if (haddr == NULL) {
            return e;
        }
        if (e->state != 1) {
            int n2 = hlen;
            if (NetMemcmp(e->haddr, haddr, n2) != 0) {
                NetMemcpy(e->haddr, haddr, n2);
                e->state = state;
            }
            return e;
        }
        NetMemcpy(e->haddr, haddr, hlen);
        e->state = state;
        if (e->hold != NULL) {
            p = (NetPacket *)alloc_free_entry();
            if (p != NULL) {
                p->fragment_count = 1;
                p->total_bytes = e->hold->len;
                p->fragments[0].length = e->hold->len;
                set_value_and_enable(&p->fragments[0].buffer, e->hold->data);
                call_handler_by_index(handler, socket, 0, (s32)e->haddr, (s32)p);
                release_entry((void *)p);
            }
        }
        detach_80408428(e);
        return e;
    }
    if (haddr == NULL) {
        return NULL;
    }
    e = find_free_peer_entry();
    if (e == NULL) {
        e = find_oldest_peer_entry(4);
        if (e == NULL) {
            e = find_oldest_peer_entry(0);
        }
        if (e->hold != NULL) {
            detach_80408428(e);
        }
        e->state = 0;
        e->timer = 0;
        NetMemset(e->haddr, 0, sizeof(e->haddr));
        NetMemset(e->paddr, 0, sizeof(e->paddr));
    }
    if (haddr != NULL) {
        NetMemcpy(e->haddr, haddr, hlen);
    }
    NetMemcpy(e->paddr, paddr, plen);
    e->hlen = hlen;
    e->plen = plen;
    e->state = state;
    e->timer = t->timeout;
    e->hold = NULL;
    return e;
}

ArpEntry *find_oldest_peer_entry(s16 state) {
    ArpEntry *best = 0;
    ArpEntry *p;
    s16 n = lbl_805C1AB0.nentries;
    s32 v;
    p = lbl_805C1AB0.entries;
    for (; n > 0; n--, p++) {
        v = p->state;
        if ((s16)v != 0 && v != state) {
            if (best == 0) {
                best = p;
            } else if (best->timer > p->timer) {
                best = p;
            }
        }
    }
    return best;
}

ArpEntry *find_free_peer_entry(void) {
    s16 n = lbl_805C1AB0.nentries;
    ArpEntry *e = lbl_805C1AB0.entries;
    while (n > 0) {
        if (e->state == 0) {
            return e;
        }
        n--;
        e++;
    }
    return NULL;
}

ArpState lbl_805C1AB0;
