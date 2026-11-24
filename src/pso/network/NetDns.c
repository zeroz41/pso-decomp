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
void complete_pending_request(s16 id, s16 event);
void tick_connection_timeouts(void);
s32 append_to_list(DnsHost *o, DnsAddr *n);
NetworkAddress *find_next_active_record(DnsQuery *a);
void reset_connection_requests(DnsPtr *o_, s16 arg1);

extern void TLobby__sub_8040B1C4(void *);
extern void TLobby__sub_8040BE40(DnsQuery *self, s16 a, s16 b);

#include <stddef.h>


#include "pso/network/IPv6Send.h"
#include "pso/network/NetStackTypes.h"

typedef struct DnsQueryHeader {
    u16 id;
    u8 flags_high;
    u8 flags_low;
    s16 qd;
    s16 an;
    s16 ns;
    s16 ar;
} DnsQueryHeader;

typedef struct DnsQuestion {
    s16 type;
    s16 cls;
} DnsQuestion;

LAYOUT_ASSERT(DnsQueryHeader_size_check, sizeof(DnsQueryHeader) == DNS_HEADER_SIZE);
LAYOUT_ASSERT(DnsQuestion_size_check, sizeof(DnsQuestion) == DNS_QUESTION_FIXED_SIZE);

s32 dns_compare_addr(DnsAddr *arg0, DnsAddr *arg1);

s32 TLobby__sub_8040B838(u8 *dst, char *src, s32 max);

/* Inline the helpers below; this applies to the rest of the file. */
#pragma dont_inline off
#pragma inline_depth(4)

s32 dns_term(void) {
    s32 ret;
    s16 i;
    DnsResolverState *m = (DnsResolverState *)&dns_resolver_state;
    DnsQuery *e;

    ret = net_unregister_timer(tick_connection_timeouts);
    e = m->queries;
    i = 0;
    while (i < m->nqueries) {
        if (e->active != 0) {
            close_and_reset_connection(e);
        }
        i++;
        e++;
    }
    TLobby__sub_803F86BC(m);
    return ret;
}

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
    return net_register_timer(tick_connection_timeouts, 1000);
}

#pragma push
#pragma opt_propagation off
s32 close_connection_by_index(s16 i) {
    DnsResolverState *g = (DnsResolverState *)&dns_resolver_state;
    DnsQuery *e;
    if (i < 0 || i > g->nqueries) { return -2; }
    e = (DnsQuery *)((u8 *)g->queries + i * 0x3C);
    if (e->active == 0) { return -2; }
    return close_and_reset_connection(e);
}
#pragma pop

extern void TLobby__sub_8040C74C(DnsLookupRequest *p);
#pragma push
#pragma opt_propagation off
extern s16 TLobby__sub_8040A698(s16 idx, void *buf, s16 *len, void *buf2, s16 *len2, uaddr mode) {
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
        net_lock();
        if (e->status > 0 || e->outstanding > 0) {
            if (e->waiter != 0xFFFFFFFF) {
                net_unlock();
                return -2;
            }
            NetStoreCurrentThread((s32 *)&e->waiter);
            net_unlock();
            NetSuspendCurrentThread();
        } else {
            net_unlock();
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
            dispatch_request_callback(e, 1);
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

s16 AT_DNS_UdpReceiver(s16 mode, NetworkReceivePrefix *req);
DnsHost *dns_alloc_host(void);
static inline DnsHost *dns_find_host(DnsResolverState *g, char *name, s16 len) {
    s16 j;
    DnsHost *p;
    j = 0;
    p = g->hosts;
    for (; j < g->nhosts; j++, p++) {
        if (p->state == 1 && NetMemcmp(p->name, name, len) == 0) {
            return p;
        }
    }
    return NULL;
}
static inline DnsBuffer *dns_alloc_buffer(DnsResolverState *g) {
    s16 i;
    DnsBuffer *p;
    i = 0;
    p = g->buffers;
    for (; i < g->nbuffers; i++, p++) {
        if (p->used == 0) {
            p->used = 1;
            return p;
        }
    }
    return NULL;
}
inline NetworkAddress *dns_next_server(DnsResolverState *g, DnsQuery *a) {
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
static inline DnsQuery *dns_alloc_query(DnsResolverState *g) {
    DnsQuery *e;
    s16 k;
    net_lock();
    k = 0;
    e = g->queries;
    for (; k < g->nqueries; k++, e++) {
        if (e->active == 0) {
            e->active = 1;
            break;
        }
    }
    net_unlock();
    if (k == g->nqueries) {
        return NULL;
    }
    return e;
}
static inline s16 dns_open_socket(DnsQuery *e) {
    e->socket = udp_open(0, 0, 0, 0x35, complete_pending_request, AT_DNS_UdpReceiver);
    return e->socket;
}
static inline s16 dns_send_query(DnsQuery *e, NetworkAddress *dst) {
    send_buffs buf;
    s16 r;
    buf.len = e->msg->len;
    buf.buff = e->msg->data;
    r = udp_send(e->socket, NULL, dst, 0, NULL, 1, &buf);
    return r;
}
#pragma push
#pragma opt_common_subs on
s16 dns_open_addr(char *name, s16 len, s32 type)
{
  DnsResolverState *g;
  DnsQuery *q;
  DnsLookupRequest *req;
  DnsHost *host;
  DnsAddr *node;
  NetworkAddress *server;
  s16 r;
  g = &dns_resolver_state;
  if (name == NULL) {
    return -2;
  }
  if (len <= 0 || len > g->max_name) {
    return -2;
  }
  switch (type) {
    case 0:
    case 4:
    case 6:
      break;
    default:
      return -2;
  }
  if (name[len - 1] == '.') {
    len--;
  }
  q = dns_alloc_query(g);
  if (q == NULL) {
    return -0x40;
  }
  q->kind = 1;
  req = &q->req.lookup;
  req->family = type;
  host = dns_find_host(g, name, len);
  if (host != NULL) {
    q->status = 0;
    req->host = host;
    if (req->family == 0) {
      if (host->naddrs > 0) {
        return q->index;
      }
    } else {
      for (node = host->addrs; node != NULL; node = node->next) {
        if (node->addr.family == req->family) {
          return q->index;
        }
      }
    }
  }
  if ((q->msg = dns_alloc_buffer(g)) == NULL) {
    close_and_reset_connection(q);
    return -0x43;
  }
  q->id = g->next_id++;
  q->timer = g->timeouts[0];
  q->server = g->server;
  q->status = 0;
  if ((server = dns_next_server(g, q)) == NULL) {
    close_and_reset_connection(q);
    return -0x44;
  }
  r = dns_open_socket(q);
  if (r < 0) {
    close_and_reset_connection(q);
    return r;
  }
  if (req->host == NULL) {
    host = dns_alloc_host();
    host->name_len = len;
    NetMemcpy(host->name, name, len);
    req->host = host;
  }
  switch (req->family) {
    case 0:
      build_dns_query_aaaa(q, name, len);
      if (dns_send_query(q, server) < 0) {
        q->timer = 1;
        q->status++;
      } else {
        q->timer = 2;
        q->outstanding = 1;
      }
      break;
    case 4:
      build_dns_query_a(q, name, len);
      if (dns_send_query(q, server) < 0) {
        q->timer = 1;
      }
      q->status++;
      break;
    case 6:
      build_dns_query_aaaa(q, name, len);
      if (dns_send_query(q, server) < 0) {
        q->timer = 1;
      }
      q->status++;
      break;
  }
  return q->index;
}
#pragma pop

s32 clear_all_used_records(void) {
    DnsResolverState *g = (DnsResolverState *)&dns_resolver_state;
    s32 cnt;
    s16 i;
    NetworkAddress *r;

    net_lock();
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
    net_unlock();
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
    DnsResolverState *g;
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
    net_lock();
    g = &dns_resolver_state;
    p = (u8 *)g->servers;
    slot = NULL;
    for (i = 0; i < g->nservers; i++, p += 0x14) {
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
    net_unlock();
    return ret;
}

extern void TLobby__sub_8040C178(DnsHost *self, s16 x);
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
    DnsResolverState *base = (DnsResolverState *)&dns_resolver_state;
    NetworkAddress *found;
    s16 *dp;
    s16 cnt;
    DnsQuery *e;
    s16 buf[8];
    send_buffs tmp;
    s16 val;
    s16 ret;
    NetworkAddress *dst;
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
            found = find_next_active_record(e);
            if (found == NULL) {
                TLobby__sub_8040BE40(e, -0x44, 0);
                continue;
            }
            base->server = e->status % *dp;
            e->timer = base->timeouts[e->status / *dp];
            buf[0] = DNS_TYPE_A;
            NetMemcpy((u8 *)e->msg->data + e->msg->len - DNS_QUESTION_FIXED_SIZE, &buf[0], 2);
            dst = found;
            tmp.len = e->msg->len;
            tmp.buff = e->msg->data;
            ret = udp_send(e->socket, NULL, dst, 0, NULL, 1, &tmp);
            val = DNS_TYPE_AAAA;
            NetMemcpy((u8 *)e->msg->data + e->msg->len - DNS_QUESTION_FIXED_SIZE, &val, 2);
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

extern void TLobby__sub_8040B1C4(void *arg)
{
    DnsQuery *e = (DnsQuery *)arg;
    DnsResolverState *base;
    NetworkAddress *found;
    u8 y[4];
    send_buffs tmp;
    u8 x[4];
    s16 ret;
    s16 *dp;

    base = (DnsResolverState *)&dns_resolver_state;
    if ((found = dns_next_server((DnsResolverState *)base, (DnsQuery *)e)) == NULL) {
        TLobby__sub_8040BE40(e, -0x44, 0);
        return;
    }
    dp = &base->nservers;
    base->server = e->status % *dp;
    e->timer = base->timeouts[e->status / *dp];
    tmp.len = e->msg->len;
    tmp.buff = e->msg->data;
    ret = udp_send(e->socket, NULL, found, 0, NULL, 1, &tmp);
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

extern s16 dns_parse_reply(DnsQuery *self);
inline DnsQuery *find_8040B4BC(DnsResolverState *base, NetworkReceivePrefix *req) {
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

s16 AT_DNS_UdpReceiver(s16 mode, NetworkReceivePrefix *req)
{
  DnsResolverState *base = &dns_resolver_state;
  DnsQuery *e;
  s16 new_var;
  DnsBuffer *s;
  s32 pad[2];
  s16 dns_parse_reply(DnsQuery *); /* declared s16 here; the definition returns s32 */
  if (((UdpDatagram *)req)->port != 0x35)
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
      s = dns_alloc_buffer(base);
      e->reply = s;
      if (s == ((void *) 0))
    {
      return 1;
    }
      req->buf = e->reply->data;
      return 0;

  }

  e->reply->len = new_var;
  if (dns_parse_reply(e) < 0)
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
    dispatch_request_callback(e, 0);
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

void complete_pending_request(s16 id, s16 event) {
    DnsQuery *e;

    if ((e = find_8040B654(id)) != NULL) {
        e->timer = 1;
        if (e->status < 0) {
            dispatch_request_callback(e, 0);
        }
    }
}

#pragma push
#pragma opt_propagation off
s32 build_dns_query_aaaa(DnsQuery *q, char *name, s16 len) {
    s32 TLobby__sub_8040B838(u8 *dst, char *src, s16 len);
    DnsQueryHeader *h;
    u8 *body;
    s32 n;
    s16 total;
    DnsQuestion qt;
    h = (DnsQueryHeader *)q->msg->data;
    h->id = q->id;
    body = (u8 *)h + DNS_HEADER_SIZE;
    h->flags_high = 1;
    h->flags_low = 0;
    h->qd = 1;
    h->an = 0;
    h->ns = 0;
    h->ar = 0;
    n = TLobby__sub_8040B838(body, name, len);
    qt.type = DNS_TYPE_AAAA;
    body += (s16)n;
    qt.cls = DNS_CLASS_IN;
    total = n + DNS_HEADER_SIZE;
    NetMemcpy(body, &qt, DNS_QUESTION_FIXED_SIZE);
    q->msg->len = total + DNS_QUESTION_FIXED_SIZE;
    return 0;
}
#pragma pop

#pragma push
#pragma opt_propagation off
s32 build_dns_query_a(DnsQuery *q, char *name, s16 len) {
    s32 TLobby__sub_8040B838(u8 *dst, char *src, s16 len);
    DnsQueryHeader *h;
    u8 *body;
    s32 n;
    s16 total;
    DnsQuestion qt;
    h = (DnsQueryHeader *)q->msg->data;
    h->id = q->id;
    body = (u8 *)h + DNS_HEADER_SIZE;
    h->flags_high = 1;
    h->flags_low = 0;
    h->qd = 1;
    h->an = 0;
    h->ns = 0;
    h->ar = 0;
    n = TLobby__sub_8040B838(body, name, len);
    qt.type = DNS_TYPE_A;
    body += (s16)n;
    qt.cls = DNS_CLASS_IN;
    total = n + DNS_HEADER_SIZE;
    NetMemcpy(body, &qt, DNS_QUESTION_FIXED_SIZE);
    q->msg->len = total + DNS_QUESTION_FIXED_SIZE;
    return 0;
}
#pragma pop

s32 TLobby__sub_8040B838(u8 *dst, char *src, s32 max)
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

extern DnsAddr *dns_alloc_addr(DnsHost *self);
extern s32 dns_expand_name(DnsQuery *self, u8 *p, s32 n, u8 *dst);
extern s32 dns_parse_answer_record(DnsQuery *self, u8 *rr, s32 avail);
#pragma push
#pragma opt_propagation off
s16 dns_parse_reply(DnsQuery *self)
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
  s32 rcode;
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
  rcode = hdr[3] & 0xF;
  switch (rcode)
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
      if ((*((u16 *)(hdr + 6))) == 0)
    {
      s->timer = 1;
      return -1;
    }
      break;

  }

  cur = hdr + DNS_HEADER_SIZE;
  len -= DNS_HEADER_SIZE;
  t = *((u16 *)(hdr + 4));
  if (t != 0)
  {
    n = t;
    while (n > 0)
    {
      new_var = cur;
      r = dns_expand_name(s, new_var, len, 0) + DNS_QUESTION_FIXED_SIZE;
      len -= r;
      cur += (s16) r;
      n--;
    }

  }
  cnt = *((u16 *)(hdr + 6));
  if (cnt != 0)
  {
    while (((s16) cnt) > 0)
    {
      r = dns_parse_answer_record(s, cur, len);
      len -= r;
      cur += (s16) r;
      cnt--;
    }

  }
  return 0;
}
#pragma pop
inline DnsAddr *find_host_addr(DnsHost *host, DnsAddr *rec) {
    s16 cnt;
    DnsAddr *node;
    if (host == 0 || rec == 0) {
        return 0;
    }
    for (node = host->addrs, cnt = 0; node != 0 && cnt < dns_resolver_state.naddrs; node = node->next, cnt++) {
        if (dns_compare_addr(node, rec) == 0) {
            return node;
        }
    }
    return 0;
}
#pragma push
#pragma opt_propagation off
extern s32 dns_parse_answer_record(DnsQuery *self, u8 *rr, s32 avail) {
    DnsRrHeader hdr;
    DnsAddr rec;
    DnsAddr *found;
    s16 m;
    DnsHost *host;
    s32 ret;
    s32 rdlength;

    ret = dns_expand_name(self, rr, avail, 0);
    m = (s16) ret;
    rr += m;
    m = (s16) avail;
    if (m < (s16) ret + DNS_RR_HEADER_SIZE) {
        return avail;
    }
    NetMemcpy(&hdr, rr, DNS_RR_HEADER_SIZE);
    ret += DNS_RR_HEADER_SIZE;
    rdlength = hdr.rdlength;
    if (m < (s16) ret + (s16) rdlength) {
        return avail;
    }
    ret += rdlength;
    switch (hdr.rclass) {
    case DNS_CLASS_IN:
        switch (hdr.type) {
        case DNS_TYPE_A: {
            host = self->req.lookup.host;
            if (host == 0) {
                break;
            }
            rec.rtype = DNS_TYPE_A;
            rec.addr.family = 4;
            NetMemcpy(rec.addr.address, rr + DNS_RR_HEADER_SIZE, 4);
            found = find_host_addr(host, &rec);
            if (found == 0) {
                found = dns_alloc_addr(host);
                if (found == 0) {
                    break;
                }
                found->used = 1;
                found->rtype = DNS_TYPE_A;
                found->addr.family = 4;
                NetMemcpy(found->addr.address, rr + DNS_RR_HEADER_SIZE, 4);
                found->host = host;
                append_to_list(host, found);
            }
            found->ttl = hdr.ttl;
            break;
        }
        case DNS_TYPE_CNAME: {
            host = self->req.lookup.host;
            if (host != 0 && (s8) host->cname[0] == 0) {
                dns_expand_name(self, rr + DNS_RR_HEADER_SIZE, rdlength, host->cname);
            }
            break;
        }
        case DNS_TYPE_AAAA: {
            host = self->req.lookup.host;
            if (host == 0) {
                break;
            }
            rec.rtype = DNS_TYPE_AAAA;
            rec.addr.family = 6;
            NetMemcpy(rec.addr.address, rr + DNS_RR_HEADER_SIZE, 0x10);
            found = find_host_addr(host, &rec);
            if (found == 0) {
                found = dns_alloc_addr(host);
                if (found == 0) {
                    break;
                }
                found->used = 1;
                found->rtype = DNS_TYPE_AAAA;
                found->addr.family = 6;
                NetMemcpy(found->addr.address, rr + DNS_RR_HEADER_SIZE, 0x10);
                found->host = host;
                append_to_list(host, found);
            }
            found->ttl = hdr.ttl;
            break;
        }
        case DNS_TYPE_PTR: {
            DnsPtr *ptr = self->req.ptr.entry;
            if (ptr != 0) {
                ptr->ttl = hdr.ttl;
                dns_expand_name(self, rr + DNS_RR_HEADER_SIZE, rdlength, ptr->name);
            }
            break;
        }
        }
        break;
    }
    return ret;
}
#pragma pop
#pragma push
#pragma opt_lifetimes off
extern s32 dns_expand_name(DnsQuery *self, u8 *p, s32 n, u8 *dst)
{
  s32 offset;
  s32 count;
  s16 limit;
  u8 *data;
  u8 c;
  u8 *d;
  u8 c2;
  u8 *s;
  s32 len;
  count = 0;
  limit = (s16) n;
  while ((s16) count < limit)
  {
    c = *p;
    if (c == 0)
    {
      count++;
      break;
    }
    if (c & 0xC0)
    {
      limit = offset = ((c & ~0xC0) << 8) | p[1];
      s = data = self->reply->data;
      s += (u16) limit;
      c2 = *s;
      d = dst;
      while (c2 != 0)
      {
        if (d != 0)
        {
          len = c2 + 1;
          NetMemcpy(d, s, len);
          d += len;
        }
        s += c2 + 1;
        c2 = *s;
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
    count += c;
    p += c + 1;
    count++;
  }
  return count;
}
#pragma pop

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

inline s32 close_8040BF38(DnsQuery *query, s32 id) {
    s32 r;
    if ((s16)id < 0) {
        return 0;
    }
    r = udp_close(id);
    query->socket = -1;
    return r;
}
s32 close_and_reset_connection(DnsQuery *self) {
    DnsBuffer *message;
    DnsBuffer *reply;
    s32 temp_r3;
    s32 var_r31;
    var_r31 = close_8040BF38(self, self->socket);
    net_lock();
    message = self->msg;
    if (message != NULL) {
        message->used = 0;
        self->msg = NULL;
    }
    reply = self->reply;
    if (reply != NULL) {
        reply->used = 0;
        self->reply = NULL;
    }
    self->req.lookup.cb = NULL;
    self->req.ptr.cb = NULL;
    self->req.lookup.host = NULL;
    self->req.ptr.entry = NULL;
    self->active = 0;
    self->kind = 0;
    self->status = -0x41;
    self->outstanding = 0;
    if (self->waiter != 0xFFFFFFFFU) {
        resume_thread(self->waiter);
        self->waiter = -1;
    }
    net_unlock();
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
            dispatch_request_callback(e, arg1);
        }
        i++;
        e++;
    }
}

DnsHost *dns_alloc_host(void) {
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

void TLobby__sub_8040C178(DnsHost *self, s16 x)
{
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

extern s16 dns_remove_addr(DnsHost *self_m, DnsAddr *arg);
extern DnsAddr *dns_alloc_addr(DnsHost *self)
{
    s16 n;
    s16 i;
    DnsAddr *best;
    DnsAddr *e;
    s16 dns_remove_addr(DnsHost *, DnsAddr *); /* declared s16 here; the definition returns s32 */
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
    if (dns_remove_addr(best->host, best) < 0) {
        return NULL;
    }
    best->used = 1;
    best->next = NULL;
    return best;
}

extern s16 dns_remove_addr(DnsHost *self_m, DnsAddr *arg) {
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
r = NetMemcmp(node->addr.address, key, 4);
}
break;
case 6:
if (arg->addr.family != 6)
{
r = -1;
}
else
{
r = NetMemcmp(node->addr.address, key, 0x10);
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

void dispatch_request_callback(DnsQuery *connection, s16 status) {
    DnsLookupRequest *a;
    DnsPtrRequest *b;
    s32 err;

    switch (connection->kind) {
    case 1:
        a = &connection->req.lookup;
        if ((uaddr)a->cb == 0xFFFFFFFFU) {
            return;
        }
        if (a->cb == NULL) {
            if (status != 0) {
                net_lock();
                if (connection->waiter != 0xFFFFFFFFU) {
                    resume_thread(connection->waiter);
                    connection->waiter = -1;
                }
                net_unlock();
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
        if ((uaddr)b->cb == 0xFFFFFFFFU) {
            return;
        }
        if (b->cb == NULL) {
            if (status != 0) {
                net_lock();
                if (connection->waiter != 0xFFFFFFFFU) {
                    resume_thread(connection->waiter);
                    connection->waiter = -1;
                }
                net_unlock();
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

s32 dns_compare_addr(DnsAddr *node, DnsAddr *rec) {
    s32 var_r5;
    u8 *var_r3;
    u8 *right;
    switch (node->rtype) {
    case DNS_TYPE_A:
        if ((u16) rec->rtype != DNS_TYPE_A) {
            var_r3 = (u8 *)((void *)-1);
            return -1;
        }
        switch ((s32) node->addr.family) {
        case 4:
            if ((u32) rec->addr.family != 4U) {
                var_r3 = (u8 *)((void *)-1);
                return -1;
            }
            var_r3 = node->addr.address;
            right = rec->addr.address;
            var_r5 = 4;
            return NetMemcmp(var_r3, right, 4);
        case 6:
            if ((u32) rec->addr.family != 6U) {
                var_r3 = (u8 *)((void *)-1);
                return -1;
            }
            var_r3 = node->addr.address;
            right = rec->addr.address;
            var_r5 = 0x10;
            return NetMemcmp(var_r3, right, 0x10);
        default:
        case 0:
            var_r3 = (u8 *)((void *)-1);
            return -1;
        }
        break;
    case DNS_TYPE_AAAA:
        if ((u16) rec->rtype != DNS_TYPE_AAAA) {
            var_r3 = (u8 *)((void *)-1);
            return -1;
        }
        switch ((s32) node->addr.family) {
        case 4:
            if ((u32) rec->addr.family != 4U) {
                var_r3 = (u8 *)((void *)-1);
                return -1;
            }
            var_r3 = node->addr.address;
            right = rec->addr.address;
            var_r5 = 4;
            return NetMemcmp(var_r3, right, 4);
        case 6:
            if ((u32) rec->addr.family != 6U) {
                var_r3 = (u8 *)((void *)-1);
                return -1;
            }
            var_r3 = node->addr.address;
            right = rec->addr.address;
            var_r5 = 0x10;
            return NetMemcmp(var_r3, right, 0x10);
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
