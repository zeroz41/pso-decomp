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
typedef struct TObjectFields {
    const char *m_name;
    u16 m_flags;
    u16 m_id;
    void *m_prev;
    void *m_next;
    void *m_up;
    void *m_down;
} TObjectFields;
typedef struct Hdr_8040B6E4 Hdr_8040B6E4;
typedef struct Pkt_8040B6E4 Pkt_8040B6E4;
typedef struct Q_8040B6E4 Q_8040B6E4;
typedef struct QT_8040B6E4 QT_8040B6E4;
typedef struct Hdr_8040B790 Hdr_8040B790;
typedef struct Pkt_8040B790 Pkt_8040B790;
typedef struct Q_8040B790 Q_8040B790;
typedef struct QT_8040B790 QT_8040B790;
s32 build_dns_query_a(void *self, u8 *name, s16 len);
s32 build_dns_query_aaaa(void *self, u8 *name, s16 len);
s32 close_and_reset_connection(void *self);
void complete_pending_request(s16 id);
void dispatch_request_callback(void *self, s16 status);
void tick_connection_timeouts(void);
s32 append_to_list(DnsHost *o, DnsAddr *n);
NetworkAddress *find_next_active_record(DnsQuery *a);
void reset_connection_requests(DnsPtr *o_, s16 arg1);

extern void TLobby__sub_8040B1C4(void *);
extern void TLobby__sub_8040BE40(DnsQuery *self, s16 a, s16 b);

#include <stddef.h>

typedef struct Hdr_8040B6E4 { u16 id; u8 f2; u8 f3; s16 qd; s16 an; s16 ns; s16 ar; u8 body[4]; } Hdr_8040B6E4;

typedef struct Pkt_8040B6E4 { u8 pad0[2]; s16 len; Hdr_8040B6E4 *hdr; } Pkt_8040B6E4;

typedef struct Q_8040B6E4 { u8 pad0[6]; u16 id; u8 pad8[0x10]; Pkt_8040B6E4 *pkt; } Q_8040B6E4;

typedef struct QT_8040B6E4 { s16 type; s16 cls; } QT_8040B6E4;

typedef struct Hdr_8040B790 { u16 id; u8 f2; u8 f3; s16 qd; s16 an; s16 ns; s16 ar; u8 body[4]; } Hdr_8040B790;

typedef struct Pkt_8040B790 { u8 pad0[2]; s16 len; Hdr_8040B790 *hdr; } Pkt_8040B790;

typedef struct Q_8040B790 { u8 pad0[6]; u16 id; u8 pad8[0x10]; Pkt_8040B790 *pkt; } Q_8040B790;

typedef struct QT_8040B790 { s16 type; s16 cls; } QT_8040B790;


#include "pso/network/IPv6Send.h"
#include "pso/network/NetStackTypes.h"

s32 TLobby__sub_8040C9E0(DnsAddr *arg0, DnsAddr *arg1);

s32 TLobby__sub_8040B838(u8 *dst, u8 *src, s32 max);

/* Inline the helpers below; this applies to the rest of the file. */
#pragma dont_inline off
#pragma inline_depth(4)

s32 TLobby__sub_8040A3C0(void) {
    s32 ret;
    s16 i;
    DnsResolverState *m = (DnsResolverState *)&dns_resolver_state;
    DnsQuery *e;

    ret = TLobby__sub_80421844((s32)((void *)tick_connection_timeouts));
    e = m->queries;
    i = 0;
    while (i < m->nqueries) {
        if (e->active != 0) {
            close_and_reset_connection((void *)e);
        }
        i++;
        e++;
    }
    TLobby__sub_803F86BC(m);
    return ret;
}

s16 TLobby__sub_804218AC(void (*)(void), int);

s16 init_net_tables(void) {
    DnsResolverState *g = &dns_resolver_state;
    s16 i;

    NetMemset(g, 0, sizeof(DnsResolverState));
    init_net_config(g);
    {
        DnsBuffer *p = g->buffers;
        i = 0;
        while (i < g->nbuffers) {
            p->used = 0;
            p->data = g->buffer_base + g->buffer_size * i;
            i++;
            p++;
        }
    }
    {
        NetworkAddress *p = g->servers;
        i = 0;
        while (i < g->nservers) {
            p->family = 0;
            i++;
            p++;
        }
    }
    {
        DnsAddr *p = g->addrs;
        i = 0;
        while (i < g->naddrs) {
            p->used = 0;
            i++;
            p->next = 0;
            p++;
        }
    }
    {
        DnsHost *p = g->hosts;
        i = 0;
        while (i < g->nhosts) {
            p->state = 0;
            i++;
            p->cname[0] = 0;
            p->naddrs = 0;
            p->addrs = 0;
            p++;
        }
    }
    {
        DnsPtr *p = g->ptrs;
        i = 0;
        while (i < g->nptrs) {
            p->state = 0;
            i++;
            p->ttl = 0;
            p->name[0] = 0;
            p++;
        }
    }
    {
        DnsQuery *p = g->queries;
        i = 0;
        while (i < g->nqueries) {
            p->index = i;
            i++;
            p->active = 0;
            p->socket = -1;
            p->id = 0;
            p->waiter = -1;
            p->status = -65;
            p->outstanding = 0;
            p->msg = 0;
            p->reply = 0;
            p->req.lookup.cb = 0;
            p->req.ptr.cb = 0;
            p++;
        }
    }
    return TLobby__sub_804218AC(tick_connection_timeouts, 1000);
}

#pragma push
#pragma opt_propagation off
s32 close_connection_by_index(s16 i) {
    DnsResolverState *g = (DnsResolverState *)&dns_resolver_state;
    DnsQuery *e;
    if (i < 0 || i > g->nqueries) { return -2; }
    e = (DnsQuery *)((u8 *)g->queries + i * 0x3C);
    if (e->active == 0) { return -2; }
    return close_and_reset_connection((void *)e);
}
#pragma pop

extern void TLobby__sub_8040C74C(DnsLookupRequest *p);
#pragma push
#pragma opt_propagation off
extern s16 TLobby__sub_8040A698(s16 idx, void *buf, s16 *len, void *buf2, s16 *len2, u32 mode) {
    DnsResolverState *g = &dns_resolver_state;
    DnsQuery *f;
    DnsQuery *e;
    DnsLookupRequest *req;
    s16 st;

    if (idx < 0 || idx >= g->nqueries) {
        return -2;
    }
    f = &g->queries[idx];
    e = (DnsQuery *)f;
    if (f->active == 0) {
        return -2;
    }
    if (e->kind != 1) {
        return -2;
    }
    if (len == NULL) {
        return -2;
    }
    if (buf != NULL && *len <= 0) {
        return -2;
    }
    if (buf2 != NULL && (len2 == NULL || *len2 < 0)) {
        return -2;
    }
    req = &e->req.lookup;
    req->addrs = buf;
    req->naddrs = *len;
    req->cname = buf2;
    if (len2 != NULL) {
        req->cname_len = *len2;
    } else {
        req->cname_len = 0;
    }
    req->cb = (DnsLookupCallback)mode;
    if (mode == 0) {
        TLobby__sub_80421814();
        if (e->status > 0 || e->outstanding > 0) {
            if (e->waiter != 0xFFFFFFFF) {
                TLobby__sub_804217E4();
                return -2;
            }
            NetStoreCurrentThread((s32 *)&e->waiter);
            TLobby__sub_804217E4();
            NetSuspendCurrentThread();
        } else {
            TLobby__sub_804217E4();
        }
        st = e->status;
        if (st < 0) {
            return st;
        }
    } else if (mode == 0xFFFFFFFF) {
        st = e->status;
        if (st > 0 || e->outstanding > 0) {
            return -1;
        }
        if (st < 0) {
            return st;
        }
    } else {
        if (e->status <= 0 && e->outstanding <= 0) {
            dispatch_request_callback((void *)e, 1);
        }
        return -1;
    }
    TLobby__sub_8040C74C(req);
    if (len2 != NULL) {
        *len2 = req->cname_len;
    }
    *len = req->naddrs;
    return 0;
}
#pragma pop

s16 TUdpSocket__sub_80421DEC(s16 a, void* b, void* c, u16 d, void* e, void* f);
s32 TLobby__sub_8040B4BC(s16 mode, UdpDatagram *req);
DnsHost *TLobby__sub_8040C09C(void);
static inline DnsHost *find_host_8040A8B0(DnsResolverState *base, u8 *self, s32 len) {
    DnsHost *p = base->hosts;
    s16 j;
    for (j = 0; j < base->nhosts; j++, p++) {
        if (p->state == 1 && NetMemcmp(p->name, self, len) == 0) {
            return p;
        }
    }
    return NULL;
}
static inline DnsBuffer *grab_slot_8040A8B0(DnsResolverState *base) {
    DnsBuffer *p = base->buffers;
    s16 i;
    for (i = 0; i < base->nbuffers; i++, p++) {
        if (p->used == 0) {
            p->used = 1;
            return p;
        }
    }
    return NULL;
}
static inline NetworkAddress *probe_8040A8B0(DnsResolverState *b, DnsQuery *e) {
    s16 i;
    NetworkAddress *ent;
    s16 n;
    for (i = 0; i < (n = b->nservers); i++) {
        ent = &b->servers[(e->server + e->status) % n];
        if (ent->family != 0) {
            if (e->status < b->max_tries) {
                return ent;
            }
            break;
        }
        e->status = e->status + 1;
    }
    return NULL;
}
#pragma push
#pragma opt_propagation off
#pragma opt_common_subs off
s32 TLobby__sub_8040A8B0(u8 *self, s16 idx, s32 type)
{
  s16 TUdpSocket__sub_80421BAC(s32, void *, void *, u16, void *, s8, send_buffs *); /* declared here with other parameter types; the definition is s16 (s32, u32 *, u32 *, u16, u32 *, s8, send_buffs *) */
  DnsResolverState *base = &dns_resolver_state;
  DnsLookupRequest *t;
  u32 ty;
  DnsHost *p;
  DnsBuffer *m;
  DnsQuery *e;
  s16 i;
  s16 j;
  if (self == ((void *) 0))
  {
    return -2;
  }
  if ((idx <= 0) || (idx > base->max_name))
  {
    return -2;
  }
  switch (type)
  {
    case 0:

    case 4:

    case 6:
      break;

    default:
      return -2;

  }

  if (((s32) self[idx - 1]) == '.')
  {
    idx--;
  }
  TLobby__sub_80421814();
  e = base->queries;
  for (i = 0; i < base->nqueries; i++, e++)
  {
    if (e->active == 0)
    {
      e->active = 1;
      break;
    }
  }

  TLobby__sub_804217E4();
  if (i == base->nqueries)
  {
    e = (void *) 0;
  }
  if (e == ((void *) 0))
  {
    return -0x40;
  }
  e->kind = 1;
  {
    long long len = idx;
    e->req.lookup.family = type;
    t = &e->req.lookup;
    p = find_host_8040A8B0(base, self, len);
    if (p != ((void *) 0))
    {
      e->status = 0;
      t->host = p;
      ty = t->family;
      if (ty == 0)
      {
        if (p->naddrs > 0)
        {
          return e->index;
        }
      }
      else
      {
        DnsAddr *node;
        for (node = p->addrs; node != ((void *) 0); node = node->next)
        {
          if (node->addr.family == ty)
          {
            return e->index;
          }
        }

      }
    }
    m = grab_slot_8040A8B0(base);
    e->msg = m;
    if (m == ((void *) 0))
    {
      close_and_reset_connection(e);
      return -0x43;
    }
    e->id = base->next_id++;
    e->timer = base->timeouts[0];
    e->server = base->server;
    e->status = 0;
    base = (DnsResolverState *) probe_8040A8B0(base, e);
    if (base == ((void *) 0))
    {
      close_and_reset_connection(e);
      return -0x44;
    }
    e->socket = TUdpSocket__sub_80421DEC(0, 0, 0, 0x35, complete_pending_request, TLobby__sub_8040B4BC);
    i = e->socket;
    if (i < 0)
    {
      close_and_reset_connection(e);
      return i;
    }
    if (t->host == ((void *) 0))
    {
      p = TLobby__sub_8040C09C();
      p->name_len = idx;
      NetMemcpy(p->name, self, len);
      t->host = p;
    }
    switch (t->family)
    {
      case 0:
      {
        send_buffs buf;
        build_dns_query_aaaa(e, self, idx);
        buf.len = e->msg->len;
        buf.buff = e->msg->data;
        i = TUdpSocket__sub_80421BAC(e->socket, (void *) 0, base, 0, (void *) 0, 1, &buf);
        if (i < 0)
        {
          e->timer = 1;
          e->status = e->status + 1;
        }
        else
        {
          e->timer = 2;
          e->outstanding = 1;
        }
        break;
      }

      case 4:
      {
        send_buffs buf;
        build_dns_query_a(e, self, idx);
        buf.len = e->msg->len;
        buf.buff = e->msg->data;
        i = TUdpSocket__sub_80421BAC(e->socket, (void *) 0, base, 0, (void *) 0, 1, &buf);
        if (i < 0)
        {
          e->timer = 1;
          e->status = e->status + 1;
        }
        break;
      }

      case 6:
      {
        send_buffs buf;
        build_dns_query_aaaa(e, self, idx);
        buf.len = e->msg->len;
        buf.buff = e->msg->data;
        i = TUdpSocket__sub_80421BAC(e->socket, (void *) 0, base, 0, (void *) 0, 1, &buf);
        if (i < 0)
        {
          e->timer = 1;
          e->status = e->status + 1;
        }
        break;
      }

    }

    {
      u32 pad[4];
    }
  }
  return e->index;
}
#pragma pop

s32 clear_all_used_records(void) {
    DnsResolverState *g = (DnsResolverState *)&dns_resolver_state;
    s32 cnt;
    s16 i;
    NetworkAddress *r;

    TLobby__sub_80421814();
    g->server = 0;
    cnt = 0;
    i = 0;
    r = g->servers;
    while (i < g->nservers) {
        if (r->family != 0) {
            r->family = 0;
            cnt++;
        }
        i++;
        r++;
    }
    TLobby__sub_804217E4();
    return cnt;
}

inline s32 cmpfam_8040ADE8(u32 family, u8 *a, u8 *b) {
    switch (family) {
    case 4:
        if (*(u32 *)b != 4) {
            return -1;
        }
        return NetMemcmp(a + 4, b + 4, 4);
    case 6:
        if (*(u32 *)b != 6) {
            return -1;
        }
        return NetMemcmp(a + 4, b + 4, 0x10);
    default:
    case 0:
        return -1;
    }
}
extern s16 TLobby__sub_8040ADE8(u8 *self) {
    u8 *g;
    s16 ret;
    s16 i;
    u8 *p;
    u8 *slot;
    u32 family;

    switch (*(u32 *)self) {
    case 4:
    case 6:
        break;
    default:
    case 0:
        return -2;
    }
    TLobby__sub_80421814();
    g = (u8 *)&dns_resolver_state;
    p = *(u8 **)(g + 0x14);
    slot = NULL;
    for (i = 0; i < *(s16 *)(g + 0x10); i++, p += 0x14) {
        if (*(u32 *)p == 0) {
            if (slot == NULL) {
                ret = i;
                slot = p;
            }
            continue;
        }
        family = *(u32 *)self;
        if (family != *(u32 *)p) {
            continue;
        }
        if (cmpfam_8040ADE8(family, self, p) == 0) {
            ret = -2;
            slot = NULL;
            break;
        }
    }
    if (slot != NULL) {
        NetMemcpy(slot, self, 0x14);
    } else {
        ret = -2;
    }
    TLobby__sub_804217E4();
    return ret;
}

extern void TLobby__sub_8040C178(DnsHost *self, s32 x);
void TLobby__sub_8040AFE0(void);
void TLobby__sub_8040B3B4(void);

void tick_connection_timeouts(void) {
    DnsResolverState *g;
    DnsPtr *c;
    s16 i;

    TLobby__sub_8040B3B4();
    g = (DnsResolverState *)&dns_resolver_state;
    c = g->ptrs;
    i = 0;
    while (i < g->nptrs) {
        if (c->state == 1 && c->ttl > 0) {
            if (--c->ttl <= 0) {
                reset_connection_requests(c, 0);
            }
        }
        i++;
        c++;
    }
    TLobby__sub_8040AFE0();
}

extern void TLobby__sub_8040AFE0(void)
{
    s16 TUdpSocket__sub_80421BAC(s32, s32, s32, u16, s32, s8, void *); /* declared here with other parameter types; the definition is s16 (s32, u32 *, u32 *, u16, u32 *, s8, send_buffs *) */
    DnsResolverState *base = (DnsResolverState *)&dns_resolver_state;
    s32 found;
    s16 *dp;
    s16 cnt;
    DnsQuery *e;
    s16 buf[8];
    send_buffs tmp;
    s16 val;
    s16 ret;
    s32 f2;
    s32 f3;

    dp = &base->nservers;
    for (cnt = 0, e = base->queries; cnt < base->nqueries; cnt++, e++) {
        if (e->active != 1) continue;
        if (e->socket < 0) continue;
        if (!(e->status > 0 || e->outstanding > 0)) continue;
        if (--e->timer > 0) continue;
        if (e->status >= base->max_tries) {
            base->server = 0;
            TLobby__sub_8040BE40(e, -0x45, 0);
            continue;
        }
        if (e->outstanding != 0) {
            found = (s32)find_next_active_record((DnsQuery *)e);
            if (found == 0) {
                TLobby__sub_8040BE40(e, -0x44, 0);
                continue;
            }
            base->server = e->status % *dp;
            e->timer = base->timeouts[e->status / *dp];
            buf[0] = 1;
            NetMemcpy((u8 *)e->msg->data + e->msg->len - 4, &buf[0], 2);
            f2 = found;
            tmp.len = e->msg->len;
            tmp.buff = e->msg->data;
            ret = TUdpSocket__sub_80421BAC(e->socket, 0, f2, 0, 0, 1, &tmp);
            val = 0x1c;
            NetMemcpy((u8 *)e->msg->data + e->msg->len - 4, &val, 2);
            if (ret < 0) {
                e->timer = 1;
            }
            e->outstanding = 0;
            e->status = e->status + 1;
        } else {
            TLobby__sub_8040B1C4(e);
        }
    }
}

inline NetworkAddress *fnar_8040B1C4(DnsResolverState *g, DnsQuery *a) {
    s16 t, n, i;
    for (i = 0; i < (n = g->nservers); i++) {
        NetworkAddress *r = &g->servers[(a->server + (t = a->status)) % n];
        if (r->family != 0) {
            if (t < g->max_tries) {
                return r;
            }
            break;
        }
        a->status = t + 1;
    }
    return 0;
}

extern void TLobby__sub_8040B1C4(void *arg)
{
    s16 TUdpSocket__sub_80421BAC(s32, s32, s32, u16, s32, s8, void *); /* declared here with other parameter types; the definition is s16 (s32, u32 *, u32 *, u16, u32 *, s8, send_buffs *) */
    DnsQuery *e = (DnsQuery *)arg;
    DnsResolverState *base;
    NetworkAddress *found;
    u8 y[4];
    send_buffs tmp;
    u8 x[4];
    s16 ret;
    s16 *dp;

    base = (DnsResolverState *)&dns_resolver_state;
    if ((found = fnar_8040B1C4((DnsResolverState *)base, (DnsQuery *)e)) == NULL) {
        TLobby__sub_8040BE40(e, -0x44, 0);
        return;
    }
    dp = &base->nservers;
    base->server = e->status % *dp;
    e->timer = base->timeouts[e->status / *dp];
    tmp.len = e->msg->len;
    tmp.buff = e->msg->data;
    ret = TUdpSocket__sub_80421BAC(e->socket, 0, (s32)found, 0, 0, 1, &tmp);
    if (ret < 0) {
        e->timer = 1;
        e->status = e->status + 1;
        return;
    }
    if (*(s16 *)((u8 *)e + 8) == 1 && *(u32 *)((u8 *)e + 0x20) == 0) {
        e->timer = 2;
        e->outstanding = 1;
        return;
    }
    e->status = e->status + 1;
}

NetworkAddress *find_next_active_record(DnsQuery *a) {
    DnsResolverState *g = &dns_resolver_state;
    s16 n, t, i;
    for (i = 0; i < (n = g->nservers); i++) {
        NetworkAddress *r = &g->servers[(a->server + (t = a->status)) % n];
        if (r->family != 0) {
            if (t < g->max_tries) {
                return r;
            }
            break;
        }
        a->status = t + 1;
    }
    return 0;
}

extern void TLobby__sub_8040B3B4(void) {
    s16 i;
    s16 n;
    s16 count;
    DnsAddr *prev;
    DnsAddr *removed;
    DnsAddr *node;
    DnsResolverState *base;
    DnsHost *e;

    base = (DnsResolverState *)&dns_resolver_state;
    e = base->hosts;
    i = 0;
    while (i < base->nhosts) {
        if (e->state == 1 && (n = e->naddrs) != 0) {
            prev = NULL;
            node = e->addrs;
            count = 0;
            while (count < n && node != NULL) {
                if (--node->ttl > 0) {
                    prev = node;
                    node = node->next;
                } else {
                    removed = node;
                    node = node->next;
                    if (prev != NULL) {
                        prev->next = node;
                    } else {
                        e->addrs = node;
                    }
                    e->naddrs--;
                    removed->used = 0;
                    removed->next = NULL;
                }
                count++;
            }
            if (e->naddrs <= 0) {
                TLobby__sub_8040C178(e, 0);
            }
        }
        i++;
        e++;
    }
}

extern s32 TLobby__sub_8040B8BC(DnsQuery *self);
inline DnsQuery *find_8040B4BC(DnsResolverState *base, UdpDatagram *req) {
    s16 count;
    s16 key;
    s16 i;
    DnsQuery *e;
    i = 0;
    key = req->socket;
    e = base->queries;
    count = base->nqueries;
    while (i < count) {
        if (e->active == 1 && key == e->socket) {
            return e;
        }
        i++;
        e++;
    }
    return NULL;
}
inline DnsBuffer *slot_8040B4BC(DnsResolverState *base) {
    s16 i;
    s16 count;
    DnsBuffer *s;
    i = 0;
    s = base->buffers;
    count = base->nbuffers;
    for (; i < count; i++, s++) {
        if (s->used == 0) {
            s->used = 1;
            return s;
        }
    }
    return NULL;
}

s32 TLobby__sub_8040B4BC(s16 mode, UdpDatagram *req)
{
  DnsResolverState *base = &dns_resolver_state;
  DnsQuery *e;
  s16 new_var;
  DnsBuffer *s;
  s32 pad[2];
  s16 TLobby__sub_8040B8BC(DnsQuery *); /* declared s16 here; the definition returns s32 */
  if (req->port != 0x35)
  {
    return 1;
  }
  e = find_8040B4BC(base, req);
  if (e == ((void *) 0))
  {
    return 1;
  }
  if (e->status < 0)
  {
    return 1;
  }
  new_var = req->len;
  if (new_var > base->buffer_size)
  {
    return 1;
  }
  switch (mode)
  {
    case 0:
      s = slot_8040B4BC(base);
      e->reply = s;
      if (s == ((void *) 0))
    {
      return 1;
    }
      req->buf = e->reply->data;
      return 0;

  }

  e->reply->len = new_var;
  if (TLobby__sub_8040B8BC(e) < 0)
  {
    e->reply->used = 0;
    e->reply = (void *) 0;
    return 1;
  }
  e->reply->used = 0;
  e->reply = (void *) 0;
  if (e->outstanding == 0)
  {
    e->status = 0;
    dispatch_request_callback((void *) e, 0);
  }
  return 0;
}

inline DnsQuery *find_8040B654(s16 id) {
    DnsResolverState *g = (DnsResolverState *)&dns_resolver_state;
    s16 n;
    DnsQuery *e;
    s16 i;

    e = g->queries;
    n = g->nqueries;
    for (i = 0; i < n; i++, e++) {
        if (e->active == 1 && id == e->socket) {
            return e;
        }
    }
    return NULL;
}

void complete_pending_request(s16 id) {
    DnsQuery *e;

    if ((e = find_8040B654(id)) != NULL) {
        e->timer = 1;
        if (e->status < 0) {
            dispatch_request_callback((void *)e, 0);
        }
    }
}

#pragma push
#pragma opt_propagation off
s32 build_dns_query_aaaa(void *self, u8 *name, s16 len) {
    s32 TLobby__sub_8040B838(u8 *dst, u8 *src, s16 len);
    Q_8040B6E4 *q = (Q_8040B6E4 *)self;
    Hdr_8040B6E4 *h;
    u8 *body;
    s32 n;
    s16 total;
    QT_8040B6E4 qt;
    h = q->pkt->hdr;
    h->id = q->id;
    body = h->body;
    h->f2 = 1;
    h->f3 = 0;
    h->qd = 1;
    h->an = 0;
    h->ns = 0;
    h->ar = 0;
    n = TLobby__sub_8040B838(body, name, len);
    qt.type = 0x1C;
    body += (s16)n;
    qt.cls = 1;
    total = n + 0xC;
    NetMemcpy(body, &qt, 4);
    q->pkt->len = total + 4;
    return 0;
}
#pragma pop

#pragma push
#pragma opt_propagation off
s32 build_dns_query_a(void *self, u8 *name, s16 len) {
    s32 TLobby__sub_8040B838(u8 *dst, u8 *src, s16 len);
    Q_8040B790 *q = (Q_8040B790 *)self;
    Hdr_8040B790 *h;
    u8 *body;
    s32 n;
    s16 total;
    QT_8040B790 qt;
    h = q->pkt->hdr;
    h->id = q->id;
    body = h->body;
    h->f2 = 1;
    h->f3 = 0;
    h->qd = 1;
    h->an = 0;
    h->ns = 0;
    h->ar = 0;
    n = TLobby__sub_8040B838(body, name, len);
    qt.type = 1;
    body += (s16)n;
    qt.cls = 1;
    total = n + 0xC;
    NetMemcpy(body, &qt, 4);
    q->pkt->len = total + 4;
    return 0;
}
#pragma pop

s32 TLobby__sub_8040B838(u8 *dst, u8 *src, s32 max)
{
    s8 c;
    s16 i;
    u8 n;
    u8 *len;
    s32 ret;
    len = dst;
    n = 0;
    i = 0;
    dst++;
    while (i < (s16)max) {
        c = *src;
        if (c == '.') {
            *len = n;
            len = dst;
            n = 0;
        } else {
            *dst = c;
            n++;
        }
        i++;
        dst++;
        src++;
    }
    if (n != 0) {
        *len = n;
        *dst = 0;
        ret = max + 2;
    } else {
        dst[-1] = 0;
        ret = max + 1;
    }
    return ret;
}

extern DnsAddr *TLobby__sub_8040C248(DnsHost *self);
extern s32 TLobby__sub_8040BD40(DnsQuery *self, u8 *p, s32 n, u8 *dst);
extern s32 TLobby__sub_8040BA38(DnsQuery *self, u8 *p, s32 n);
#pragma push
#pragma opt_propagation off
s32 TLobby__sub_8040B8BC(DnsQuery *self)
{
  volatile u32 pad[2];
  s32 len;
  DnsQuery *s;
  DnsBuffer *p;
  u8 *hdr;
  u8 *new_var;
  u16 cnt;
  s16 n;
  u16 t;
  u8 *cur;
  s32 op;
  s32 r;
  s = self;
  p = s->reply;
  hdr = p->data;
  len = p->len;
  if ((*((u16 *) hdr)) != (u16) s->id)
  {
    return -1;
  }
  if (!(hdr[2] & 0x80))
  {
    return -1;
  }
  op = hdr[3] & 0xF;
  switch (op)
  {
    case 1:
      TLobby__sub_8040BE40(s, -0x46, 0);
      return -1;

    case 3:
      TLobby__sub_8040BE40(s, -0x47, 0);
      return -1;

    case 2:

    case 4:

    case 5:

    default:
      s->timer = 1;
      return -1;

    case 0:
      if ((*((u16 *) (hdr + 6))) == 0)
    {
      s->timer = 1;
      return -1;
    }
      break;

  }

  cur = hdr + 0xc;
  len -= 0xc;
  t = *((u16 *) (hdr + 4));
  if (t != 0)
  {
    n = t;
    while (n > 0)
    {
      new_var = cur;
      r = TLobby__sub_8040BD40(s, new_var, len, 0) + 4;
      len -= r;
      cur += (s16) r;
      n--;
    }

  }
  cnt = *((u16 *) (hdr + 6));
  if (cnt != 0)
  {
    while (((s16) cnt) > 0)
    {
      r = TLobby__sub_8040BA38(s, cur, len);
      len -= r;
      cur += (s16) r;
      cnt--;
    }

  }
  return 0;
}
#pragma pop
inline DnsAddr *find_8040BA38(DnsHost *obj, DnsAddr *rec) {
    s16 cnt;
    DnsAddr *node;
    if (obj == 0 || rec == 0) {
        return 0;
    }
    for (node = obj->addrs, cnt = 0; node != 0 && cnt < dns_resolver_state.naddrs; node = node->next, cnt++) {
        if (TLobby__sub_8040C9E0(node, rec) == 0) {
            return node;
        }
    }
    return 0;
}
extern s32 TLobby__sub_8040BA38(DnsQuery *self, u8 *p, s32 n)
{
  DnsRrHeader hdr;
  DnsAddr rec;
  DnsAddr *found;
  s32 ret;
  s32 l;
  u8 *rr;
  ret = TLobby__sub_8040BD40(self, p, n, 0);
  rr = p + (s16) ret;
  if ((s16) n < (s16) ret + 10)
  {
    return n;
  }
  NetMemcpy(&hdr, rr, 10);
  ret += 10;
  l = hdr.rdlength;
  if ((s16) n < (s16) ret + (s16) l)
  {
    return n;
  }
  ret += l;
  switch (hdr.rclass)
  {
  case 1:
  switch (hdr.type)
  {
    case 1:
    {
      DnsHost *obj = self->req.lookup.host;
      if (obj == 0)
      {
        break;
      }
      rec.rtype = 1;
      rec.addr.family = 4;
      NetMemcpy(rec.addr.address, rr + 10, 4);
      if ((found = find_8040BA38(obj, &rec)) == 0)
      {
        found = TLobby__sub_8040C248(obj);
        if (found == 0)
        {
          break;
        }
        found->used = 1;
        found->rtype = 1;
        found->addr.family = 4;
        NetMemcpy(found->addr.address, rr + 10, 4);
        found->host = obj;
        append_to_list(obj, found);
      }
      found->ttl = hdr.ttl;
      break;
    }
    case 5:
    {
      DnsHost *o = self->req.lookup.host;
      if (o != 0 && (s8) o->cname[0] == 0)
      {
        TLobby__sub_8040BD40(self, rr + 10, l, o->cname);
      }
      break;
    }
    case 0x1c:
    {
      DnsHost *obj = self->req.lookup.host;
      if (obj == 0)
      {
        break;
      }
      rec.rtype = 0x1c;
      rec.addr.family = 6;
      NetMemcpy(rec.addr.address, rr + 10, 0x10);
      found = find_8040BA38(obj, &rec);
      if (found == 0)
      {
        found = TLobby__sub_8040C248(obj);
        if (found == 0)
        {
          break;
        }
        found->used = 1;
        found->rtype = 0x1c;
        found->addr.family = 6;
        NetMemcpy(found->addr.address, rr + 10, 0x10);
        found->host = obj;
        append_to_list(obj, found);
      }
      found->ttl = hdr.ttl;
      break;
    }
    case 0xc:
    {
      DnsPtr *o = self->req.ptr.entry;
      if (o != 0)
      {
        o->ttl = hdr.ttl;
        TLobby__sub_8040BD40(self, rr + 10, l, o->name);
      }
      break;
    }
  }
  break;
  }
  return ret;
}
extern s32 TLobby__sub_8040BD40(DnsQuery *self, u8 *p, s32 n, u8 *dst)
{
  s16 new_var2;
  u8 c2;
  u8 c;
  int new_var3;
  u8 *q;
  s32 len;
  s32 count = 0;
  int new_var;
  new_var2 = (s16) n;
  while (((s16) count) < new_var2)
  {
    c = *p;
    if (!c)
    {
      count++;
      break;
    }
    if (c & 0xC0)
    {
      q = self->reply->data;
      q += (u16) (((new_var = c & (~0xC0)) << 8) | p[1]);
      new_var3 = 0;
      c2 = *q;
      p = q;
      while (c2 != new_var3)
      {
        if (dst != 0)
        {
          len = (c2 & 0xFF) + 1;
          NetMemcpy(dst, p, len);
          dst += len;
        }
        p += c2 + 1;
        c2 = *p;
      }

      count += 2;
      break;
    }
    if (dst != 0)
    {
      len = c + 1;
      NetMemcpy(dst, p, len);
      dst += len;
    }
    count = c;
    p += count + 1;
    count += c + 1;
  }

  return count;
}

inline void cancel_8040BE40(DnsPtr *o, s16 b) {
    DnsResolverState *base = &dns_resolver_state;
    s16 i;
    DnsQuery *e;
    i = 0;
    e = base->queries;
    while (i < base->nqueries) {
        if (e->req.ptr.entry == o) {
            e->status = -0x42;
            e->outstanding = 0;
            e->req.ptr.entry = NULL;
            dispatch_request_callback(e, b);
        }
        i++;
        e++;
    }
}
extern void TLobby__sub_8040BE40(DnsQuery *self, s16 a, s16 b)
{
    void TLobby__sub_8040C178(DnsHost *self, s16 x); /* declared here with an s16 2nd argument; the definition takes s32 */
    DnsPtr *o;
    DnsHost *p;
    switch (self->kind) {
    case 1:
        p = self->req.lookup.host;
        if (p != NULL) {
            self->req.lookup.host = NULL;
            TLobby__sub_8040C178(p, b);
        }
        break;
    case 12:
        o = self->req.ptr.entry;
        if (o != NULL) {
            self->req.ptr.entry = NULL;
            o->state = 0;
            o->ttl = 0;
            o->name[0] = 0;
            cancel_8040BE40(o, b);
        }
        break;
    }
    self->status = a;
    self->outstanding = 0;
    dispatch_request_callback(self, b);
}

inline s32 close_8040BF38(u8 *p, s32 id) {
    s32 r;
    if ((s16)id < 0) {
        return 0;
    }
    r = TLobby__sub_80421B3C(id);
    *(s16 *)((s8 *)p + 4) = -1;
    return r;
}
s32 close_and_reset_connection(void *self) {
    u8 *arg0 = (u8 *)self;
    s16 *temp_r3_2;
    s16 *temp_r3_3;
    s32 temp_r3;
    s32 var_r31;
    var_r31 = close_8040BF38(arg0, *(s16 *)&((TObjectFields *)self)->m_flags);
    TLobby__sub_80421814();
    temp_r3_2 = (s16 *)(*(s16 **)((s8 *)arg0 + 0x18));
    if (temp_r3_2 != NULL) {
        *(s16 *)((s8 *)temp_r3_2 + 0) = 0;
        *(s16 **)((s8 *)arg0 + 0x18) = NULL;
    }
    temp_r3_3 = (s16 *)(*(s16 **)((s8 *)arg0 + 0x1C));
    if (temp_r3_3 != NULL) {
        *(s16 *)((s8 *)temp_r3_3 + 0) = 0;
        *(s16 **)((s8 *)arg0 + 0x1C) = NULL;
    }
    *(s32 *)((s8 *)arg0 + 0x34) = 0;
    *(s32 *)((s8 *)arg0 + 0x28) = 0;
    *(s32 *)((s8 *)arg0 + 0x38) = 0;
    *(s32 *)((s8 *)arg0 + 0x2C) = 0;
    *(s16 *)&((TObjectFields *)self)->m_name = 0;
    *(s16 *)&((TObjectFields *)self)->m_prev = 0;
    *(s16 *)&((TObjectFields *)self)->m_up = -0x41;
    *(s16 *)((s8 *)arg0 + 0x12) = 0;
    if (*(u32 *)&((TObjectFields *)self)->m_next != 0xFFFFFFFFU) {
        resume_thread((s32)((TObjectFields *)self)->m_next);
        *(s32 *)&((TObjectFields *)self)->m_next = -1;
    }
    TLobby__sub_804217E4();
    return var_r31;
}

void reset_connection_requests(DnsPtr *o, s16 arg1) {
    s16 i;
    DnsQuery *e;

    o->state = 0;
    o->ttl = 0;
    o->name[0] = 0;
    i = 0;
    e = dns_resolver_state.queries;
    while (i < dns_resolver_state.nqueries) {
        if (e->req.ptr.entry == o) {
            e->status = -0x42;
            e->outstanding = 0;
            e->req.ptr.entry = 0;
            dispatch_request_callback((void *)e, arg1);
        }
        i++;
        e++;
    }
}

DnsHost *TLobby__sub_8040C09C(void) {
    DnsResolverState *dns = &dns_resolver_state;
    DnsHost *p = dns->hosts;
    DnsHost *found = NULL;
    s16 count = dns->nhosts;
    s16 i;

    for (i = 0; i < count; i++, p++) {
        if (p->state == 0) {
            p->state = 1;
            return p;
        } else if (found == NULL) {
            found = p;
        } else if (found->naddrs != 0 && p->naddrs != 0) {
            if (p->addrs->ttl < found->addrs->ttl) {
                found = p;
            }
        } else if (p->naddrs != 0) {
            found = p;
        }
    }
    TLobby__sub_8040C178(found, 1);
    found->state = 1;
    return found;
}

void TLobby__sub_8040C178(DnsHost *self, s32 x)
{
    void dispatch_request_callback(void* p, s32 x); /* declared here with an s32 2nd argument; the definition takes s16 */
  DnsResolverState *base;
  DnsAddr *e;
  s16 j;
  DnsAddr *p;
  DnsHost *new_var;
  DnsQuery *q;
  self->state = 0;
  j = 0;
  base = &dns_resolver_state;
  self->cname[0] = 0;
  self->naddrs = 0;
  p = self->addrs;
  while ((p != ((void *) 0)) && (j < base->naddrs))
  {
    e = p;
    p = e->next;
    j++;
    e->used = 0;
    e->next = (void *) 0;
  }

  (new_var = self)->addrs = (void *) 0;
  q = base->queries;
  for (j = 0; j < base->nqueries; j++, q++)
  {
    if (q->req.lookup.host == new_var)
    {
      q->status = -0x42;
      q->outstanding = 0;
      q->req.lookup.host = (void *) 0;
      dispatch_request_callback(q, x);
    }
  }

}

extern s32 TLobby__sub_8040C340(DnsHost *self_m, DnsAddr *arg);
extern DnsAddr *TLobby__sub_8040C248(DnsHost *self)
{
    s16 n;
    s16 i;
    DnsAddr *best;
    DnsAddr *e;
    s16 TLobby__sub_8040C340(DnsHost *, DnsAddr *); /* declared s16 here; the definition returns s32 */
    if (self == NULL) {
        return NULL;
    }
    e = dns_resolver_state.addrs;
    n = dns_resolver_state.naddrs;
    best = NULL;
    for (i = 0; i < n; i++, e++) {
        if (e->used == 0) {
            e->used = 1;
            e->next = NULL;
            return e;
        }
        if (e->host != self) {
            if (best == NULL) {
                best = e;
            } else if (e->ttl < best->ttl) {
                best = e;
            }
        }
    }
    if (best == NULL) {
        return NULL;
    }
    if (TLobby__sub_8040C340(best->host, best) < 0) {
        return NULL;
    }
    best->used = 1;
    best->next = NULL;
    return best;
}

extern s32 TLobby__sub_8040C340(DnsHost *self_m, DnsAddr *arg) {
DnsResolverState *tbl;
DnsAddr *node;
DnsAddr *prev;
u8 *key;
s16 i;
s32 r;
if (arg == ((void *) 0))
{
return -1;
}
if (self_m == ((void *) 0))
{
return -1;
}
if ((self_m->state == 0) || (self_m->addrs == ((void *) 0)))
{
return -1;
}
node = self_m->addrs;
tbl = &dns_resolver_state;
key = arg->addr.address;
prev = (DnsAddr *)((void *) 0);
for (i = 0; (node != ((void *) 0)) && (i < tbl->naddrs); node = node->next, (unsigned long long) (i++))
{
switch ((s32) node->addr.family)
{
case 4:
if (arg->addr.family != 4)
{
r = -1;
}
else
{
r = NetMemcmp((void *)(node->addr.address), (void *)(key), (int)(4));
}
break;
case 6:
if (arg->addr.family != 6)
{
r = -1;
}
else
{
r = NetMemcmp((void *)(node->addr.address), (void *)(key), (int)(0x10));
}
break;
case 0:
default:
r = -1;
break;
}
if (r != 0)
{
prev = node;
}
else
{
self_m->naddrs--;
if (prev == ((void *) 0))
{
self_m->addrs = node->next;
}
else
{
prev->next = node->next;
}
node->used = 0;
node->next = (DnsAddr *)((void *) 0);
return 0;
}
}
return -1;
}

s32 append_to_list(DnsHost *o, DnsAddr *n) {
    s16 i;
    DnsAddr *p;

    if (o == NULL || n == NULL) {
        return -1;
    }
    if (o->addrs == NULL) {
        o->naddrs = 1;
        o->addrs = n;
        return 0;
    }
    for (p = o->addrs, i = 0; i < ((DnsResolverState *)&dns_resolver_state)->naddrs; i++) {
        if (p->next == NULL) {
            o->naddrs++;
            p->next = n;
            return 0;
        }
        p = p->next;
    }
    return -1;
}

s16 TLobby__sub_8040C8A8(u8 *, u8 *, s16);
s16 TLobby__sub_8040C978(void *);

void dispatch_request_callback(void *self, s16 status) {
    DnsQuery *connection = (DnsQuery *)self;
    DnsLookupRequest *a;
    DnsPtrRequest *b;
    s32 err;

    switch (connection->kind) {
    case 1:
        a = &connection->req.lookup;
        if ((u32)a->cb == 0xFFFFFFFFU) {
            return;
        }
        if (a->cb == NULL) {
            if (status != 0) {
                TLobby__sub_80421814();
                if (connection->waiter != 0xFFFFFFFFU) {
                    resume_thread(connection->waiter);
                    connection->waiter = -1;
                }
                TLobby__sub_804217E4();
                return;
            }
            if (connection->waiter != 0xFFFFFFFFU) {
                resume_thread(connection->waiter);
                connection->waiter = -1;
            }
            return;
        }
        err = connection->status;
        if ((s16)err < 0) {
            a->cb(connection->index, a->addrs, err, a->cname, 0);
        } else {
            TLobby__sub_8040C74C(a);
            a->cb(connection->index, a->addrs, a->naddrs, a->cname, a->cname_len);
        }
        a->cb = NULL;
        break;
    case 12:
        b = &connection->req.ptr;
        if ((u32)b->cb == 0xFFFFFFFFU) {
            return;
        }
        if (b->cb == NULL) {
            if (status != 0) {
                TLobby__sub_80421814();
                if (connection->waiter != 0xFFFFFFFFU) {
                    resume_thread(connection->waiter);
                    connection->waiter = -1;
                }
                TLobby__sub_804217E4();
                return;
            }
            if (connection->waiter != 0xFFFFFFFFU) {
                resume_thread(connection->waiter);
                connection->waiter = -1;
            }
            return;
        }
        err = connection->status;
        if ((s16)err < 0) {
            b->cb(connection->index, b->name, err);
        } else {
            if (b->entry == NULL) {
                b->len = -0x42;
            } else if (b->name == NULL) {
                b->len = TLobby__sub_8040C978(b->entry->name);
            } else {
                b->len = TLobby__sub_8040C8A8(b->name, b->entry->name, b->len);
            }
            b->cb(connection->index, b->name, b->len);
        }
        b->cb = NULL;
        break;
    }
}

void TLobby__sub_8040C74C(DnsLookupRequest *self) {
    s16 n;
    s8 *s;
    s32 len;
    s16 j;
    DnsHost *obj;
    s16 cnt;
    NetworkAddress *cur;
    DnsAddr *ent;
    s16 v;

    obj = self->host;
    if (obj == NULL) {
        self->naddrs = -0x42;
        return;
    }
    if ((s8)obj->cname[0] != 0 && (v = self->cname_len) != 0) {
        if (self->cname == NULL) {
            s = (s8 *)obj->cname;
            n = 0;
            while (n < 0xff) {
                s8 c = *s++;
                if (c == 0) {
                    n--;
                    break;
                }
                len = c;
                if (n + len + 1 <= 0xff) {
                    s += len;
                } else {
                    n = 0xff;
                    break;
                }
                n += len + 1;
            }
            self->cname_len = n;
        } else {
            self->cname_len = TLobby__sub_8040C8A8(self->cname, obj->cname, v);
        }
    } else {
        self->cname_len = 0;
    }
    cur = self->addrs;
    cnt = 0;
    ent = obj->addrs;
    for (j = 0; j < obj->naddrs; j++, ent = ent->next) {
        if (self->family == 0 || self->family == ent->addr.family) {
            cnt++;
            if (cur != NULL) {
                NetMemcpy(cur, &ent->addr, sizeof(NetworkAddress));
                cur++;
                if (cnt >= self->naddrs) {
                    break;
                }
            }
        }
    }
    self->naddrs = cnt;
}

#pragma push
#pragma optimization_level 2
#pragma opt_common_subs off
extern s16 TLobby__sub_8040C8A8(u8 *dst, u8 *src, s16 max) {
    s32 limit = max;
    s32 n;
    s16 len = 0;

    while (len < limit) {
        s8 c = *src++;
        if (c == 0) {
            *dst = 0;
            return --len;
        }
        n = c;
        if (limit >= len + n + 1) {
            NetMemcpy(dst, src, n);
            dst += n;
            *dst = '.';
            src += n;
            dst++;
        } else {
            NetMemcpy(dst, src, limit - len);
            return max;
        }
        len += n + 1;
    }
    return len;
}
#pragma pop

s16 TLobby__sub_8040C978(void *arg)
{
  int new_var;
  u8 *s;
  s16 i;
  s8 c;
  s8 n;
  i = 0;
  s = (u8 *) arg;
  while (i < 0xff)
  {
    c = *(s++);
    if (c == 0)
    {
      return --i;
    }
    n = c;
    new_var = n;
    if (((((s32) i) + new_var) + 1) <= 0xff)
    {
      s += new_var;
    }
    else
    {
      return 0xff;
    }
    i = new_var + i;
    i++;
  }

  return i;
}

s32 TLobby__sub_8040C9E0(DnsAddr *arg0, DnsAddr *arg1) {
    s32 var_r5;
    u8 *var_r3;
    u8 *var_r4;
    switch ((s32) (arg0->rtype)) {
    case 1:
        if ((u16) arg1->rtype != 1) {
            var_r3 = (u8 *)((void *)-1);
            return -1;
        }
        switch ((s32) arg0->addr.family) {
        case 4:
            if ((u32) arg1->addr.family != 4U) {
                var_r3 = (u8 *)((void *)-1);
                return -1;
            }
            var_r3 = arg0->addr.address;
            var_r4 = arg1->addr.address;
            var_r5 = 4;
            return NetMemcmp((void *)(var_r3), (void *)(var_r4), 4);
        case 6:
            if ((u32) arg1->addr.family != 6U) {
                var_r3 = (u8 *)((void *)-1);
                return -1;
            }
            var_r3 = arg0->addr.address;
            var_r4 = arg1->addr.address;
            var_r5 = 0x10;
            return NetMemcmp((void *)(var_r3), (void *)(var_r4), 0x10);
        default:
        case 0:
            var_r3 = (u8 *)((void *)-1);
            return -1;
        }
        break;
    case 28:
        if ((u16) arg1->rtype != 0x1C) {
            var_r3 = (u8 *)((void *)-1);
            return -1;
        }
        switch ((s32) arg0->addr.family) {
        case 4:
            if ((u32) arg1->addr.family != 4U) {
                var_r3 = (u8 *)((void *)-1);
                return -1;
            }
            var_r3 = arg0->addr.address;
            var_r4 = arg1->addr.address;
            var_r5 = 4;
            return NetMemcmp((void *)(var_r3), (void *)(var_r4), 4);
        case 6:
            if ((u32) arg1->addr.family != 6U) {
                var_r3 = (u8 *)((void *)-1);
                return -1;
            }
            var_r3 = arg0->addr.address;
            var_r4 = arg1->addr.address;
            var_r5 = 0x10;
            return NetMemcmp((void *)(var_r3), (void *)(var_r4), 0x10);
        default:
        case 0:
            var_r3 = (u8 *)((void *)-1);
            return -1;
        }
        break;
    default:
        var_r3 = (u8 *)((void *)-1);
        return -1;
    }
}

DnsResolverState dns_resolver_state;
