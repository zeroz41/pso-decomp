#include "pso/network/UdpRuntime.h"
#include "pso/network/SocketEvents.h"
#include "pso/network/NetworkDispatch.h"
#include "pso/network/NetworkRuntime.h"
#include "pso/network/PppVj.h"
#include "pso/network/PppChap.h"
#include "pso/network/NetworkPacketPool.h"
#include "pso/network/netcfg.h"
#include "pso/network/BufferRef.h"
#include "pso/network/IPv6.h"
#include "pso/network/NetIPv6NeighborDiscovery.h"

#include "types.h"
#include "pso/network/Ppp.h"
#include "pso/network/NetStack.h"
#include "pso/network/NetIpv6Route.h"
#include "pso/network/NetApi.h"

#include <stddef.h>

#include "pso/network/IPv6Send.h"
#include "pso/network/NetStackTypes.h"

s16 NetIPv6IsAnycastAddress(void *self, s16 idx);
s16 NetIPv6IsSolicitedNodeAddress(void *self, s16 id);




/* Inline the helpers below; this applies to the rest of the file. */
#pragma dont_inline off
#pragma inline_depth(4)


void NetIPv6TickAddresses(void);
s32 NetIPv6ShutdownRouting(void) {
    Ipv6State *g = &ipv6_address_routing_state;
    NetUnregisterTimer(NetIPv6TickAddresses);
    NetUnregisterTimer(tick_entry_timers);
    term_ipv6_routing_config(g);
    g->route_count = 0;
    g->count = 0;
    g->max_addrs = 0;
    return 0;
}

s16 NetIPv6InitRouting(void) {
    init_udp_socket_config(&ipv6_address_routing_state);
    NetMemset(ipv6_address_routing_state.routes, 0, ipv6_address_routing_state.route_count * sizeof(Ipv6Route));
    /* Clears count * sizeof(Ipv6Route) bytes of the interface table, not count * sizeof(Ipv6Iface). */
    NetMemset(ipv6_address_routing_state.ifaces, 0, ipv6_address_routing_state.count * sizeof(Ipv6Route));
    NetMemset(ipv6_address_routing_state.addr_pool, 0, ipv6_address_routing_state.max_addrs * sizeof(Ipv6AddrNode));
    NetMemset(ipv6_address_routing_state.pmtu, 0, ipv6_address_routing_state.pmtu_count * sizeof(Ipv6PmtuEntry));
    NetRegisterTimer(0x3E8, (s16)(1), (NetTimerCallback)(NetIPv6TickAddresses));
    NetRegisterTimer(0x3E8, (s16)(1), (NetTimerCallback)(tick_entry_timers));
    return 0;
}

s16 NetIPv6OutputToLinkAddress(NetPacket *packet, u8 *link_address, s16 iface) {
    Ipv6Iface *ifc;
    if ((iface < 0) || (iface >= ipv6_address_routing_state.count)) {
        return -0x10A;
    }
    ifc = &ipv6_address_routing_state.ifaces[iface];
    if (ifc->state != 1) {
        return -6;
    }
    return call_handler_by_index(iface, ifc->handle, 0, link_address, packet);
}

s16 NetIPv6OutputToDestination(NetPacket *packet, IPv6Address *destination, s16 iface) {
    Ipv6Iface *ifc;
    if ((iface < 0) || (iface >= ipv6_address_routing_state.count)) {
        return -0x10A;
    }
    ifc = &ipv6_address_routing_state.ifaces[iface];
    if (ifc->state != 1) {
        return -6;
    }
    return call_handler_by_index(iface, ifc->handle, 2, destination, packet);
}

s32 NetIPv6HandleRoutingEvent(s16 id, int n, void *pp);
s16 NetIPv6AutoconfigurePrefix(Ipv6NdPrefixEvent *pi, s16 idx);
void NetIPv6TickAddresses(void) {
    Ipv6State *g = &ipv6_address_routing_state;
    s16 i;
    s16 j;
    Ipv6Iface *ifc;
    Ipv6AddrNode *a;
    Ipv6NdEvent ev;

    ifc = g->ifaces;
    for (i = 0; i < g->count; i++, ifc++) {
        if (ifc->state != 1 || i == 0) {
            continue;
        }
        switch (ifc->dad_state) {
        case 1:
            if (ifc->dad_count > 0) {
                if (ifc->dad_timer > 0) {
                    ifc->dad_timer--;
                } else {
                    NetIPv6SendUnspecifiedSourceNeighborSolicitation(ifc->addr, i);
                    ifc->dad_count--;
                    ifc->dad_timer = g->dad_interval;
                }
            } else {
                if (ifc->autoconf == 0) {
                    ifc->dad_state = 4;
                } else {
                    ifc->dad_state = 3;
                }
                ev.addr = ifc->addr;
                ev.prefix_len = ifc->prefix_len;
                NetIPv6HandleRoutingEvent(i, 0, &ev);
            }
            break;
        }
        if (ifc->rs_count > 0 && ifc->dad_state != 0) {
            if (ifc->rs_timer > 0) {
                ifc->rs_timer--;
            } else {
                NetIPv6SendRouterSolicitation(i);
                ifc->rs_count--;
                ifc->rs_timer = g->rs_interval;
            }
        }
        a = ifc->addrs;
        for (j = 0; a != NULL && j < g->max_addrs; j++) {
            switch (a->state) {
            case 0:
                break;
            case 1:
                if (a->dad_count > 0) {
                    if (a->dad_timer > 0) {
                        a->dad_timer--;
                    } else {
                        NetIPv6SendUnspecifiedSourceNeighborSolicitation(a->addr, i);
                        a->dad_count--;
                        a->dad_timer = g->dad_interval;
                    }
                } else {
                    if (a->autoconf == 0) {
                        a->state = 4;
                    } else {
                        a->state = 3;
                    }
                    ev.addr = a->addr;
                    ev.prefix_len = a->prefix_len;
                    NetIPv6HandleRoutingEvent(i, 0, &ev);
                }
                break;
            case 3:
                if (a->preferred_lifetime != 0xFFFFFFFF && a->preferred_lifetime != 0) {
                    a->preferred_lifetime--;
                    if (a->preferred_lifetime == 0) {
                        a->state = 2;
                    }
                }
                if (a->valid_lifetime != 0xFFFFFFFF && a->valid_lifetime != 0) {
                    a->valid_lifetime--;
                    if (a->valid_lifetime == 0) {
                        a->state = 0;
                    }
                }
                break;
            case 2:
                if (a->valid_lifetime != 0xFFFFFFFF && a->valid_lifetime != 0) {
                    a->valid_lifetime--;
                    if (a->valid_lifetime == 0) {
                        a->state = 0;
                    }
                }
                break;
            case 4:
                break;
            }
            a = a->next;
        }
    }
}

void NetIPv6CopyPrefix(u8* dst, s16 bits, u8* src);

inline s16 ipv6_addr_compare(void *a, void *b) {
    s32 t = NetMemcmp(a, b, 16);
    if (t < 0) {
        return -1;
    }
    if (t > 0) {
        return 1;
    }
    return 0;
}

inline void remove_prefix_route(Ipv6State *g, s16 len, u8 *addr, void *src) {
    u8 grp[16];
    s16 n;
    Ipv6Route *e;
    NetIPv6CopyPrefix(grp, len, addr);
    n = g->route_count;
    e = g->routes;
    for (; n > 0; n--, e++) {
        if (e->state == 1 && e->prefix_len == len && ipv6_addr_compare(e->prefix, grp) == 0 && ipv6_addr_compare(e->gateway, src) == 0) {
            e->state = 0;
            return;
        }
    }
}

s32 NetIPv6HandleRoutingEvent(s16 id, int n, void *pp)
{
  Ipv6EventCallback h;
  s16 i;
  Ipv6State *g = &ipv6_address_routing_state;
  Ipv6Route *ent;
  s16 t;
  Ipv6Iface *e;
  Ipv6RoutingEvent *p = (Ipv6RoutingEvent *) pp;
  u8 a92[16];
  s32 ret;
  s16 err;
  if ((id < 0) || (id >= g->count))
  {
    return -266;
  }
  e = g->ifaces;
  e += id;
  if (e->state != 1)
  {
    return -2;
  }
  t = 1;
  if ((h = e->callback) != 0)
  {
    t = invoke_routing_event_callback(id, n, p, h);
  }
  switch (n)
  {
    case 0:
      ent = g->routes;
      for (i = 0; i < g->route_count; i++, ent++)
    {
      if ((ent->state == 1) && (ent->type == 0))
      {
        if (ent->prefix_len == p->address.prefix_len)
        {
          if (ipv6_addr_compare(&ent->gateway, p->address.addr) == 0)
          {
            ent->type = 1;
          }
        }
        else
          if (ent->prefix_len == 128)
        {
          if (ipv6_addr_compare(&ent->prefix, p->address.addr) == 0)
          {
            ent->type = 1;
          }
        }
      }
    }

      break;

    case 1:
      if (e->dad_timer > 0)
    {
      e->dad_timer = 0;
    }
      break;

    case 2:
      if (t == 1)
    {
      err = NetIPv6AutoconfigurePrefix(&p->prefix, id);
    }
      break;

    case 3:
      ipv6_protocol_state.hop_limit = p->hop_limit.hop_limit;
      break;

    case 4:
      e->mtu = p->mtu.mtu;
      break;

    case 5:
      if (t == 1)
    {
      NetMemset(a92, 0, 16);
      ret = NetIPv6AddRoute(a92, 0, p->router.addr, id, 2, 4);
    }
      break;

    case 6:
      if (t == 1)
    {
      NetMemset(a92, 0, 16);
      remove_prefix_route(g, 0, a92, p->router.addr);
    }
      break;

    case 7:
      if (t == 1)
    {
      NetMemset(a92, 0, 16);
      remove_prefix_route(g, 0, a92, p->router.addr);
      ret = NetIPv6AddRoute(a92, 0, p->router.next_router, id, 2, 4);
    }
      break;

    case 8:

    case 11:

    case 12:
      break;

    case 9:
      if (t == 1)
    {
      NetMemset(a92, 0, 16);
      remove_prefix_route(g, 0, a92, p->router.addr);
    }
      break;

    case 10:
      if (t == 1)
    {
      remove_prefix_route(g, p->redirect.prefix_len, p->redirect.destination, p->redirect.old_router);
      ret = NetIPv6AddRoute(p->redirect.destination, 128, p->redirect.new_router, id, 3, 4);
    }
      break;

  }

  return 0;
}

void tick_entry_timers(void) {
    Ipv6State *G = &ipv6_address_routing_state;
    s16 i;
    Ipv6PmtuEntry *e = G->pmtu;
    for (i = 0; i < G->pmtu_count; i++, e++) {
        if (e->state == 1) {
            if (e->timer > 0) {
                e->timer--;
            } else {
                e->state = 0;
            }
        }
    }
}

inline Ipv6Iface *ipv6_iface_at(Ipv6State *g, s16 idx) {
    return &g->ifaces[idx];
}
inline s16 ipv6_is_link_local(u8 *a) {
    u8 b;

    if (a[0] != 0xFE) {
        return 0;
    }
    b = a[1];
    if (!(b & 0x80) || (b & 0x40)) {
        return 0;
    }
    return 1;
}
s16 NetIPv6GetPathMtu(u8 *addr, s16 idx) {
    Ipv6State *g = &ipv6_address_routing_state;
    Ipv6Iface *ifc = ipv6_iface_at(g, idx);
    Ipv6PmtuEntry *slot = NULL;
    s16 i;
    Ipv6PmtuEntry *e;
    Ipv6PmtuEntry *oldest = NULL;

    if (ipv6_is_link_local(addr)) {
        return ifc->mtu;
    }
    e = g->pmtu;
    for (i = 0; i < g->pmtu_count; i++, e++) {
        if (e->state != 1) {
            if (slot == NULL) {
                slot = e;
            }
        } else {
            if (ipv6_addr_compare(&e->addr, addr) == 0) {
                if (e->mtu > ifc->mtu) {
                    if (ifc->mtu < 40) {
                        return -6;
                    }
                    e->mtu = ifc->mtu;
                }
                e->timer = g->pmtu_lifetime;
                return e->mtu;
            }
            if (oldest == NULL) {
                oldest = e;
            } else if (e->timer < oldest->timer) {
                oldest = e;
            }
        }
    }
    if (slot == NULL) {
        slot = oldest;
    }
    if (ifc->mtu < 40) {
        return -6;
    }
    slot->state = 1;
    slot->timer = g->pmtu_lifetime;
    NetMemcpy(&slot->addr, addr, sizeof(IPv6Address));
    slot->mtu = ifc->mtu;
    return slot->mtu;
}

/* Path MTU report for addr: restarts its cache entry's lifetime and lowers its MTU to mtu when mtu is 1280 or more.
   Returns 0, or -1 when mtu is below 40 or addr has no cache entry. */
s32 NetIPv6UpdatePathMtu(IPv6Address *addr, s16 mtu)
{
    Ipv6State *G = &ipv6_address_routing_state;
    s16 i;
    Ipv6PmtuEntry *e;
    s32 r;
    s16 c;

    if (mtu < 0x28) {
        return -1;
    }
    e = G->pmtu;
    for (i = 0; i < G->pmtu_count; i++, e++) {
        if (e->state != 1) {
            continue;
        }
        r = NetMemcmp(&e->addr, addr, sizeof(IPv6Address));
        if (r < 0) {
            c = -1;
        } else if (r > 0) {
            c = 1;
        } else {
            c = 0;
        }
        if (c != 0) {
            continue;
        }
        if (mtu >= 0x500 && mtu < e->mtu) {
            e->mtu = mtu;
        }
        e->timer = G->pmtu_lifetime;
        return 0;
    }
    return -1;
}

s16 get_iface_mtu(s16 iface) {
    Ipv6Iface *ifc;
    if ((iface < 0) || (iface >= ipv6_address_routing_state.count)) {
        return -0x10A;
    }
    ifc = &ipv6_address_routing_state.ifaces[iface];
    if (ifc->state != 1) {
        return -2;
    }
    return ifc->mtu;
}

s16 NetIPv6CommonPrefixLength(void *, void *);
s16 NetIPv6SelectSourceAddress(void *out, void *dst, s16 idx) {
    Ipv6State *g = &ipv6_address_routing_state;
    u8 *sel = NULL;
    s16 best = 0;
    s16 scope;
    Ipv6Iface *ifc;
    s16 n;
    Ipv6AddrNode *node;
    s16 score;

    if (idx < 0 || idx >= g->count) {
        return -6;
    }
    ifc = g->ifaces + idx;
    scope = NetIPv6GetAddressScopeClass(dst);
    if (ifc->state == 1) {
        if (ifc->scope == scope) {
            score = NetIPv6CommonPrefixLength(ifc->addr, dst);
            if (score > 0) {
                best = score;
                sel = ifc->addr;
            }
        } else {
            best = 0;
            sel = ifc->addr;
        }
        node = ifc->addrs;
        for (n = 0; node != NULL && n < g->max_addrs; n++) {
            if (node->scope == scope) {
                score = NetIPv6CommonPrefixLength(node->addr, dst);
                if (score > best) {
                    best = score;
                    sel = node->addr;
                }
            }
            node = node->next;
        }
    }
    if (sel == NULL) {
        return -6;
    }
    NetMemcpy(out, sel, 16);
    return 0;
}

extern s32 copy_ipv6_interface_addresses(s16 id, NetBufferRef *self, s32 len, u8 *out) {
    struct Ipv6IfaceAddrRecord { /* as Ipv4IfaceAddrRecord, kind 6 */
        u32 kind;
        u8 addr[0x10];
        s16 prefix_len;
        s16 flags;
        Ipv6EventCallback callback;
    };
    s16 n;
    s32 i;
    struct Ipv6IfaceAddrRecord rec;
    Ipv6Iface *ent;
    NetBufferRef ref;
    Ipv6AddrNode *cur;
    Ipv6State *st;

    st = &ipv6_address_routing_state;
    if (id < 0 || id >= st->count) {
        return -0x10A;
    }
    ent = st->ifaces;
    ent += id;
    if (ent->state != 1) {
        return -2;
    }
    if ((u32)(s16)len < 0x1C) {
        return -2;
    }
    rec.kind = 6;
    NetMemcpy(rec.addr, ent->addr, 0x10);
    rec.prefix_len = ent->prefix_len;
    rec.flags = ent->flags;
    rec.callback = ent->callback;
    set_value_and_enable(&ref, &rec);
    netbuf_copy_by_ref(self, &ref, 0x1C);
    netbuf_ref_advance(self, 0x1C);
    cur = ent->addrs;
    i = 1;
    n = 0;
    len -= 0x1C;
    while ((u32)(s16)len >= 0x1C && cur != NULL && n < st->max_addrs) {
        rec.kind = 6;
        NetMemcpy(rec.addr, &cur->addr, 0x10);
        rec.prefix_len = cur->prefix_len;
        rec.flags = cur->flags;
        rec.callback = 0;
        set_value_and_enable(&ref, &rec);
        netbuf_copy_by_ref(self, &ref, 0x1C);
        netbuf_ref_advance(self, 0x1C);
        cur = cur->next;
        i++;
        n++;
        len -= 0x1C;
    }
    if (link_get_address_length(id, ent->handle) <= 6) {
        link_get_address(id, ent->handle, out);
    }
    return i;
}

inline s16 first_iface_addr(s16 *n, Ipv6Iface **ifs, void *out) {
    if (*n <= 0) {
        return 0;
    }
    if ((*ifs)->state != 1) {
        return 0;
    }
    NetMemcpy(out, (*ifs)->addr, 16);
    return 1;
}

inline void remove_host_route(Ipv6State *g, void *grp, void *src) {
    s16 n = g->route_count;
    Ipv6Route *e = g->routes;
    for (; n > 0; n--, e++) {
        if (e->state == 1 && e->prefix_len == 0x80 && ipv6_addr_compare(e->prefix, grp) == 0 && ipv6_addr_compare(e->gateway, src) == 0) {
            e->state = 0;
            return;
        }
    }
}

s16 bring_down_ipv6_interface(s16 idx) {
    Ipv6State *g;
    u8 d[16];
    u8 c[16];
    u8 b[16];
    u8 a[16];
    s16 *pn;
    Ipv6Iface **pifs;
    s16 count;
    Ipv6Iface *ifc;
    Ipv6AddrNode *grp;
    g = &ipv6_address_routing_state;

    if (idx < 0 || idx >= *(pn = &g->count)) {
        return -0x10A;
    }
    ifc = *(pifs = &g->ifaces);
    ifc += idx;
    if (ifc->state != 1) {
        return 0;
    }
    grp = ifc->addrs;
    count = 0;
    while (grp != NULL && count < g->max_addrs) {
        Ipv6AddrNode *next;
        if (link_is_loopback(idx) == 0 && first_iface_addr(pn, pifs, d)) {
            NetIPv6CopyPrefix(b, 0x80, grp->addr);
            remove_host_route(g, b, d);
        }
        link_update_address(idx, ifc->handle, 2, grp->addr);
        NetIPv6MakeSolicitedNodeMulticastAddress(c, grp->addr);
        link_update_multicast(idx, ifc->handle, 2, c);
        next = grp->next;
        grp->in_use = 0;
        NetMemset(grp->addr, 0, 16);
        grp->prefix_len = 0;
        count++;
        grp->next = NULL;
        grp = next;
    }
    if (link_is_loopback(idx) == 0 && first_iface_addr(pn, pifs, d)) {
        NetIPv6CopyPrefix(a, 0x80, ifc->addr);
        remove_host_route(g, a, d);
    }
    {
        Ipv6Route *e;
        s16 n;
        n = g->route_count;
        e = g->routes;
        for (; n > 0; n--, e++) {
            if (e->state == 1 && e->iface == idx) {
                e->state = 0;
            }
        }
    }
    NetIPv6MakeSolicitedNodeMulticastAddress(c, ifc->addr);
    link_update_multicast(idx, ifc->handle, 2, c);
    init_ipv6_all_nodes_multicast_address(c, (s8)(2));
    link_update_multicast(idx, ifc->handle, 2, c);
    init_ipv6_all_nodes_multicast_address(c, (s8)(1));
    link_update_multicast(idx, ifc->handle, 2, c);
    call_entry_callback(idx, ifc->handle);
    ifc->state = 0;
    ifc->handle = 0;
    ifc->mtu = 0;
    NetMemset(ifc->addr, 0, 16);
    ifc->prefix_len = 0;
    ifc->addrs = NULL;
    ifc->callback = 0;
    return 0;
}

s16 NetIPv6AutoconfigurePrefix(Ipv6NdPrefixEvent *pi, s16 idx)
{
    Ipv6State *g = &ipv6_address_routing_state;
    u8 *pfx;
    Ipv6AddrNode *slot;
    Ipv6Route *route;
    u32 v;
    s16 rem;
    u8 *q;
    Ipv6Iface *e;
    u8 mask;
    s32 plen;
    Ipv6AddrNode *cur;
    s16 r;
    s16 *pc;
    s16 n8;
    s16 fl;
    s16 found;
    s16 i;
    u8 new_addr[16];
    u8 iface0_addr[16];
    u8 solicited[16];
    s16 err;
    Ipv6AddrNode *node;

    if (idx <= 0 || idx >= *(s16 *)((u8 *)g + offsetof(Ipv6State, count))) {
        return -266;
    }
    e = *(Ipv6Iface **)((u8 *)g + offsetof(Ipv6State, ifaces));
    e += idx;
    if (e->state != 1) {
        return -2;
    }
    NetMemset(new_addr, 0, 8);
    r = link_get_interface_id(idx, new_addr + 8);
    if (r < 0) {
        return r;
    }
    plen = pi->prefix_len;
    if ((pfx && pfx) && pfx) {
    }
    pfx = pi->prefix;
    if ((s16)plen > 0) {
        n8 = plen / 8;
        NetMemcpy(new_addr, pfx, n8);
        if ((rem = plen % 8) != 0) {
            q = new_addr + n8;
            mask = 255 >> rem;
            *q = (mask & *q) | (pfx[n8] & ~mask);
        }
    }
    if (ipv6_addr_compare(new_addr, e->addr) == 0) {
        return 0;
    }
    if (e->addrs != 0) {
        node = e->addrs;
        found = 0;
        i = 0;
        for (; node != 0 && i < g->max_addrs; node = node->next, i++) {
            if (node->autoconf == 0) {
                if (ipv6_addr_compare(new_addr, node->addr) == 0) {
                    found = 1;
                }
            } else if (pi->prefix_len == node->prefix_len) {
                if (NetCompareBitPrefix(pi->prefix, node->addr, pi->prefix_len) == 0) {
                    found = 1;
                    v = pi->valid_lifetime;
                    if (v > 7200 || v > node->valid_lifetime) {
                        node->valid_lifetime = v;
                        node->preferred_lifetime = pi->preferred_lifetime;
                    } else if (node->valid_lifetime > 7200 || v > node->valid_lifetime) {
                        node->valid_lifetime = 7200;
                    }
                }
            }
        }

        if (found) {
            return 0;
        }
    }
    pc = (s16 *)((u8 *)g + offsetof(Ipv6State, max_addrs));
    slot = g->addr_pool;
    r = *(s16 *)((u8 *)g + offsetof(Ipv6State, max_addrs));
    for (i = 0; i < r; i++, slot++) {
        if (slot->in_use == 0) {
            slot->in_use = 1;
            break;
        }
    }

    if (i >= *pc) {
        return -266;
    }
    r = link_update_address(idx, e->handle, 1, new_addr);
    if (r < 0) {
        slot->in_use = 0;
        return r;
    }
    NetMemcpy(slot->addr, new_addr, 16);
    slot->prefix_len = pi->prefix_len;
    fl = 1;
    slot->autoconf = fl;
    slot->flags = 0;
    slot->scope = NetIPv6GetAddressScopeClass(new_addr);
    if (link_does_dad(idx) != 0) {
        slot->state = fl;
        fl = 0;
        slot->dad_count = g->dad_count_init;
        slot->dad_timer = g->dad_timer_init;
    } else {
        slot->state = 3;
        fl = 1;
        slot->dad_count = 0;
        slot->dad_timer = 0;
    }
    slot->valid_lifetime = pi->valid_lifetime;
    slot->preferred_lifetime = pi->preferred_lifetime;
    slot->next = NULL;
    if (e->addrs == 0) {
        e->addrs = slot;
    } else {
        cur = e->addrs;
        for (i = 0; i < *pc; i++) {
            if (cur->next == 0) {
                break;
            }
            cur = cur->next;
        }

        if (cur->next == 0) {
            cur->next = slot;
        }
    }
    found = first_iface_addr((s16 *)((u8 *)g + offsetof(Ipv6State, count)), (Ipv6Iface **)((u8 *)g + offsetof(Ipv6State, ifaces)), iface0_addr);
    if (found != 0) {
        r = NetIPv6AddRoute(new_addr, 128, iface0_addr, 0, 3, 1);
        if (r < 0) {
            goto release;
        }
    }
    route = NetIPv6LookupRoute(new_addr, new_addr);
    if (route != 0 && route->prefix_len == pi->prefix_len) {
        if (route->iface != idx) {
            goto drop_route;
        }
    } else {
        r = NetIPv6AddRoute(new_addr, pi->prefix_len, new_addr, idx, fl, 1);
        if (r < 0) {
            goto drop_route;
        }
    }
    NetIPv6MakeSolicitedNodeMulticastAddress(solicited, new_addr);
    r = link_update_multicast(idx, e->handle, 1, solicited);
    if (r >= 0) {
        return 0;
    }
    remove_prefix_route(g, pi->prefix_len, new_addr, new_addr);
drop_route:
    if (link_is_loopback(idx) == 0) {
        remove_prefix_route(g, 128, new_addr, iface0_addr);
    }

release:
    err = link_update_address(idx, e->handle, 2, new_addr);

    if (e->addrs == slot) {
        e->addrs = 0;
    } else {
        cur->next = 0;
    }
    return r;
}

s16 bring_up_ipv6_interface(u8 *addr, s16 plen, s16 flags, s16 idx, Ipv6EventCallback callback)
{
    Ipv6State *g = &ipv6_address_routing_state;
    s16 *pn;
    Ipv6Iface **pifs;
    Ipv6Iface *e;
    s16 r;
    s16 ret;
    s16 found;
    s16 fl;
    s16 n8;
    s16 rem;
    u8 *q;
    u8 mask;
    u8 tmp[16];
    u8 ll[16];
    u8 mcast[16];
    s32 err;

    if (idx < 0 || idx >= *(pn = &g->count)) {
        return -266;
    }
    e = *(pifs = &g->ifaces);
    e += idx;
    if (e->state == 1) {
        return -2;
    }
    e->state = 1;
    NetMemset(tmp, 0, 16);
    if (NetCompareBitsBackward(tmp + 15, addr + 15, 128 - plen) != 0) {
        NetMemcpy(tmp, addr, 16);
    } else {
        r = link_get_interface_id(idx, tmp + 8);
        if (r < 0) {
            e->state = 0;
            return r;
        }
        if (plen > 0) {
            n8 = plen / 8;
            NetMemcpy(tmp, addr, n8);
            rem = plen % 8;
            if (rem != 0) {
                q = tmp + n8;
                mask = 255 >> rem;
                *q = (mask & *q) | (addr[n8] & ~mask);
            }
        }
    }
    e->handle = link_attach_protocol(idx, 0x86DD, 16, (u32 *)tmp);
    if (e->handle < 0) {
        e->state = 0;
        return e->handle;
    }
    r = invoke_socket_callback(idx, e->handle);
    if (r < g->min_mtu) {
        e->state = 0;
        return -6;
    }
    e->mtu = r;
    NetMemcpy(e->addr, tmp, 16);
    e->prefix_len = plen;
    e->autoconf = 0;
    e->flags = flags;
    e->scope = NetIPv6GetAddressScopeClass(tmp);
    if (link_does_dad(idx)) {
        e->dad_state = 1;
        fl = 0;
        e->dad_count = g->dad_count_init;
        e->dad_timer = g->dad_timer_init;
    } else {
        e->dad_state = 4;
        fl = 1;
        e->dad_count = 0;
        e->dad_timer = 0;
    }
    if (link_solicits_routers(idx)) {
        e->rs_count = g->rs_count_init;
        e->rs_timer = g->rs_timer_init;
    } else {
        e->rs_count = 0;
        e->rs_timer = 0;
    }
    e->callback = callback;
    e->addrs = NULL;
    if (!link_is_loopback(idx)) {
        found = first_iface_addr(pn, pifs, ll);
        if (found) {
            ret = NetIPv6AddRoute(tmp, 128, ll, 0, 3, 1);
            if (ret < 0) {
                goto release;
            }
        }
        ret = NetIPv6AddRoute(tmp, plen, tmp, idx, fl, 1);
        if (ret < 0) {
            goto remove_ll;
        }
    } else {
        ret = NetIPv6AddRoute(tmp, plen, tmp, idx, fl, 1);
        if (ret < 0) {
            goto remove_ll;
        }
    }
    init_ipv6_all_nodes_multicast_address(mcast, 1);
    ret = link_update_multicast(idx, e->handle, 1, mcast);
    if (ret < 0) {
        goto remove;
    }
    init_ipv6_all_nodes_multicast_address(mcast, 2);
    ret = link_update_multicast(idx, e->handle, 1, mcast);
    if (ret < 0) {
        goto remove;
    }
    NetIPv6MakeSolicitedNodeMulticastAddress(mcast, tmp);
    ret = link_update_multicast(idx, e->handle, 1, mcast);
    if (ret >= 0) {
        return 0;
    }
remove:
    remove_prefix_route(g, plen, tmp, tmp);
remove_ll:
    if (!link_is_loopback(idx)) {
        remove_prefix_route(g, 128, tmp, ll);
    }
release:
    err = call_entry_callback(idx, e->handle);
    e->state = 0;
    e->handle = 0;
    e->mtu = 0;
    NetMemset(e->addr, 0, 16);
    e->prefix_len = 0;
    return ret;
}

s16 NetIPv6IsReachable(u8 *dst, u8 *src) {
    if (NetIPv6LookupRoute(dst, src) != NULL) {
        return 1;
    }
    return 0;
}

s16 NetIPv6IsOwnAddress(void *self, s16 idx);
inline s16 ipv6_is_multicast(u8 *a) {
    if (a[0] == 0xFF) {
        return 1;
    }
    return 0;
}
inline Ipv6Route *ipv6_routes(Ipv6State *g) {
    return g->routes;
}
Ipv6Route *NetIPv6LookupRoute(void *dst, void *src) {
    Ipv6State *g = &ipv6_address_routing_state;
    s16 i;
    Ipv6Route *rt;
    Ipv6Route *host = NULL;
    Ipv6Route *prefix = NULL;
    Ipv6Route *deflt = NULL;

    rt = ipv6_routes(g);
    for (i = 0; i < g->route_count; i++, rt++) {
        if (rt->state != 1) {
            continue;
        }
        switch (rt->type) {
        case 3:
            if (NetCompareBitPrefix(rt->prefix, (u8 *)dst, rt->prefix_len) == 0) {
                return rt;
            }
            break;
        case 1:
            if (ipv6_is_multicast((u8 *)dst)) {
                if (NetIPv6IsOwnAddress((u8 *)src, rt->iface) != 0) {
                    host = rt;
                }
            } else if (NetCompareBitPrefix(rt->prefix, (u8 *)dst, rt->prefix_len) == 0) {
                if (ipv6_is_link_local((u8 *)dst)) {
                    if (NetIPv6IsOwnAddress((u8 *)src, rt->iface) != 0) {
                        host = rt;
                    }
                } else if (host == NULL) {
                    host = rt;
                } else if (rt->prefix_len > host->prefix_len) {
                    host = rt;
                }
            }
            break;
        case 2:
            if (NetIPv6IsUnspecified(rt->prefix)) {
                if (deflt == NULL) {
                    deflt = rt;
                }
            } else if (NetCompareBitPrefix(rt->prefix, (u8 *)dst, rt->prefix_len) == 0) {
                if (prefix == NULL) {
                    prefix = rt;
                } else if (rt->prefix_len > prefix->prefix_len) {
                    prefix = rt;
                }
            }
            break;
        }
    }
    if (host != NULL) {
        return host;
    }
    if (prefix != NULL) {
        return prefix;
    }
    if (deflt != NULL) {
        return deflt;
    }
    return NULL;
}

s16 NetIPv6AddRoute(u8 *prefix, s16 prefix_len, u8 *gateway, s16 iface, s16 type, s16 origin) {
    Ipv6State *tbl = &ipv6_address_routing_state;
    s16 i;
    Ipv6Route *e;
    Ipv6Route *found;
    s16 plen;
    u8 buf[16];

    if (prefix_len < 0 || prefix_len > 0x80) {
        return -2;
    }
    if (iface < 0 || iface >= tbl->count) {
        return -2;
    }
    if (type != 1 && type != 2 && type != 3 && type != 0) {
        return -2;
    }
    if (origin != 1 && origin != 2 && origin != 3 && origin != 4) {
        return -2;
    }
    NetIPv6CopyPrefix(buf, prefix_len, prefix);
    e = tbl->routes;
    plen = prefix_len;
    found = NULL;
    i = 0;
    for (; i < tbl->route_count; i++, e++) {
        if (e->state == 1) {
            if (e->prefix_len == plen && ipv6_addr_compare(e->prefix, buf) == 0) {
                if (!ipv6_is_link_local(buf) || ipv6_addr_compare(e->gateway, gateway) == 0) {
                    return -2;
                }
            }
        } else {
            found = e;
            break;
        }
    }
    if (found == NULL) {
        return -0x108;
    }
    found->state = 1;
    NetMemcpy(found->prefix, buf, 16);
    NetMemcpy(found->gateway, gateway, 16);
    found->type = type;
    found->origin = origin;
    found->prefix_len = prefix_len;
    found->iface = iface;
    return 0;
}

s16 NetIPv6InterfaceNeedsResolution(s16 i)
{
    return link_needs_resolution(i);
}

s16 NetIPv6IsLoopbackInterface(s16 i) {
    return link_is_loopback(i);
}

s16 ipv6_iface_for_address(void *self) {
    Ipv6State *base = &ipv6_address_routing_state;
    s16 i;
    s16 j;
    Ipv6Iface *e;
    Ipv6AddrNode *n;
    s32 r;
    s16 c;
    for (i = 0, e = base->ifaces; i < base->count; i++, e++) {
        if (*(s16 *)e == 1) {
            r = NetMemcmp(&e->addr, self, 0x10);
            if (r < 0) c = -1;
            else if (r > 0) c = 1;
            else c = 0;
            if (c == 0) {
                return i;
            }
            for (n = e->addrs, j = 0; n != 0 && j < base->max_addrs; n = n->next, j++) {
                r = NetMemcmp(&n->addr, self, 0x10);
                if (r < 0) c = -1;
                else if (r > 0) c = 1;
                else c = 0;
                if (c == 0) {
                    return i;
                }
            }
        }
    }
    return -6;
}

s16 NetIPv6IsOwnAddress(void *addr, s16 idx) {
    Ipv6State *g = &ipv6_address_routing_state;
    Ipv6Iface *ifc;
    s16 n;
    Ipv6AddrNode *node;

    if (idx < 0 || idx >= g->count) {
        return 0;
    }
    ifc = g->ifaces;
    ifc += idx;
    if (ifc->state != 1) {
        return 0;
    }
    if (ipv6_addr_compare(ifc->addr, addr) == 0) {
        return 1;
    }
    node = ifc->addrs;
    for (n = 0; node != NULL && n < g->max_addrs; n++) {
        if (ipv6_addr_compare(node->addr, addr) == 0) {
            return 1;
        }
        node = node->next;
    }
    return 0;
}

inline Ipv6Iface *ipv6_get_iface(Ipv6State *g, s16 idx) {
    Ipv6Iface *ifc;

    if (idx < 0 || idx >= g->count) {
        return NULL;
    }
    ifc = g->ifaces;
    ifc += idx;
    if (ifc->state != 1) {
        return NULL;
    }
    return ifc;
}
extern s16 NetIPv6IsPreferredAddress(void *addr, s16 idx) {
    Ipv6State *g = &ipv6_address_routing_state;
    Ipv6Iface *ifc;
    s16 n;
    Ipv6AddrNode *node;

    ifc = ipv6_get_iface(g, idx);
    if (ifc == NULL) {
        return 0;
    }
    if (ipv6_addr_compare(ifc->addr, addr) == 0) {
        if (ifc->dad_state < 3) {
            return 0;
        }
        return 1;
    }
    node = ifc->addrs;
    for (n = 0; node != NULL && n < g->max_addrs; n++) {
        if (ipv6_addr_compare(node->addr, addr) == 0) {
            if (node->state < 3) {
                return 0;
            }
            return 1;
        }
        node = node->next;
    }
    return 0;
}

s16 NetIPv6IsValidAddress(void *self, s16 id) {
    Ipv6State *tbl = &ipv6_address_routing_state;
    Ipv6Iface *e = NULL;
    s16 i;
    Ipv6AddrNode *p;
    s16 c;
    s32 r;
    if (id < 0 || id >= tbl->count) {
        e = NULL;
    } else {
        e = tbl->ifaces;
        e += id;
        if (*(s16 *)e != 1) {
            e = NULL;
        }
    }
    if (e == NULL) {
        return 0;
    }
    r = NetMemcmp(&e->addr, self, 16);
    if (r < 0) {
        c = -1;
    } else if (r > 0) {
        c = 1;
    } else {
        c = 0;
    }
    if (c == 0) {
        if (e->dad_state < 2) {
            return 0;
        }
        return 1;
    }
    p = e->addrs;
    i = 0;
    while (p != NULL && i < tbl->max_addrs) {
        r = NetMemcmp(&p->addr, self, 16);
        if (r < 0) {
            c = -1;
        } else if (r > 0) {
            c = 1;
        } else {
            c = 0;
        }
        if (c == 0) {
            if (p->state < 2) {
                return 0;
            }
            return 1;
        }
        p = p->next;
        i++;
    }
    return 0;
}

s16 NetIPv6IsTentativeAddress(void *self, s16 id) {
    Ipv6State *tbl = &ipv6_address_routing_state;
    Ipv6Iface *e = NULL;
    s32 i;
    Ipv6AddrNode *p;
    s16 c;
    s32 r;
    if (id < 0 || id >= tbl->count) {
        e = NULL;
    } else {
        e = tbl->ifaces;
        e += id;
        if (*(s16 *)e != 1) {
            e = NULL;
        }
    }
    if (e == NULL) {
        return 0;
    }
    r = NetMemcmp(&e->addr, self, 16);
    if (r < 0) {
        c = -1;
    } else if (r > 0) {
        c = 1;
    } else {
        c = 0;
    }
    if (c == 0) {
        if (e->dad_state == 1) {
            return 1;
        }
        return 0;
    }
    p = e->addrs;
    i = 0;
    while (p != NULL && (s16)i < tbl->max_addrs) {
        r = NetMemcmp(&p->addr, self, 16);
        if (r < 0) {
            c = -1;
        } else if (r > 0) {
            c = 1;
        } else {
            c = 0;
        }
        if (c == 0) {
            if (p->state == 1) {
                return 1;
            }
            return 0;
        }
        p = p->next;
        i++;
    }
    return 0;
}

s16 NetIPv6IsAnycastAddress(void *self, s16 idx) {
    Ipv6State *tbl = &ipv6_address_routing_state;
    Ipv6Iface *e = NULL;
    s32 i;
    Ipv6AddrNode *p;
    s32 r;
    s16 c;
    s16 ok;

    if (*(u8 *)self == 0xff) {
        ok = 1;
    } else {
        ok = 0;
    }
    if (ok) {
        return 0;
    }
    if ((s16)idx < 0 || idx >= tbl->count) {
        e = NULL;
    } else {
        e = tbl->ifaces;
        e += idx;
        if (*(s16 *)e != 1) {
            e = NULL;
        }
    }
    if (e == NULL) {
        return 0;
    }
    r = NetMemcmp(&e->addr, self, 16);
    if (r < 0) {
        c = -1;
    } else if (r > 0) {
        c = 1;
    } else {
        c = 0;
    }
    if (c == 0) {
        if ((e->flags & 1) == 0) {
            return 0;
        }
        return 1;
    }
    p = e->addrs;
    i = 0;
    while (p != NULL && (s16)i < tbl->max_addrs) {
        r = NetMemcmp(&p->addr, self, 16);
        if (r < 0) {
            c = -1;
        } else if (r > 0) {
            c = 1;
        } else {
            c = 0;
        }
        if (c == 0) {
            if ((p->flags & 1) == 0) {
                return 0;
            }
            return 1;
        }
        p = p->next;
        i++;
    }
    return 0;
}

s16 NetIPv6IsSolicitedNodeAddress(void *self, s16 id)
{
    Ipv6State *base = &ipv6_address_routing_state;
    Ipv6Iface *e = NULL;
    s16 i;
    Ipv6AddrNode *p;
    u8 buf[16];
    s16 c;
    s32 r;
    s16 ok;

    if (*(u8 *)self == 0xff) {
        ok = 1;
    } else {
        ok = 0;
    }
    if (!ok) {
        return 0;
    }
    if (id < 0 || id >= base->count) {
        e = NULL;
    } else {
        e = base->ifaces;
        e += id;
        if (e->state != 1) {
            e = NULL;
        }
    }
    if (e == NULL) {
        return 0;
    }
    NetIPv6MakeSolicitedNodeMulticastAddress(buf, e->addr);
    r = NetMemcmp(buf, self, 16);
    if (r < 0) {
        c = -1;
    } else if (r > 0) {
        c = 1;
    } else {
        c = 0;
    }
    if (c == 0) {
        return 1;
    }
    p = e->addrs;
    i = 0;
    while (p != NULL && i < base->max_addrs) {
        NetIPv6MakeSolicitedNodeMulticastAddress(buf, p->addr);
        r = NetMemcmp(buf, self, 16);
        if (r < 0) {
            c = -1;
        } else if (r > 0) {
            c = 1;
        } else {
            c = 0;
        }
        if (c == 0) {
            return 1;
        }
        p = p->next;
        i++;
    }
    return 0;
}

inline Ipv6Iface *lookup_ipv6_iface(Ipv6State *g, s16 idx) {
    return ipv6_get_iface(g, idx);
}
extern s16 NetIPv6IsOwnLinkLocalAddress(u8 *addr, s16 idx) {
    Ipv6State *g = &ipv6_address_routing_state;
    Ipv6Iface *ifc;
    s16 n;
    Ipv6AddrNode *node;

    if (!ipv6_is_link_local(addr)) {
        return 0;
    }
    ifc = lookup_ipv6_iface(g, idx);
    if (ifc == NULL) {
        return 0;
    }
    if (ipv6_addr_compare(ifc->addr, addr) == 0) {
        return 1;
    }
    node = ifc->addrs;
    for (n = 0; node != NULL && n < g->max_addrs; n++) {
        if (ipv6_addr_compare(node->addr, addr) == 0) {
            return 1;
        }
        node = node->next;
    }
    return 0;
}

s16 NetIPv6CommonPrefixLength(void* p, void* q) {
    u8* a = p;
    u8* b = q;
    s16 j;
    s16 i;
    s16 n = 0;
    for (j = 0; j < 16; j++, a++, b++) {
        for (i = 0; i < 8; i++) {
            switch (i) {
            case 0:
                if ((a[0] & 0x80) != (b[0] & 0x80)) return n;
                n++;
                break;
            case 1:
                if ((a[0] & 0x40) != (b[0] & 0x40)) return n;
                n++;
                break;
            case 2:
                if ((a[0] & 0x20) != (b[0] & 0x20)) return n;
                n++;
                break;
            case 3:
                if ((a[0] & 0x10) != (b[0] & 0x10)) return n;
                n++;
                break;
            case 4:
                if ((a[0] & 0x08) != (b[0] & 0x08)) return n;
                n++;
                break;
            case 5:
                if ((a[0] & 0x04) != (b[0] & 0x04)) return n;
                n++;
                break;
            case 6:
                if ((a[0] & 0x02) != (b[0] & 0x02)) return n;
                n++;
                break;
            case 7:
                if ((a[0] & 0x01) != (b[0] & 0x01)) return n;
                n++;
                break;
            }
        }
    }
    return n;
}

inline s16 ipv6_is_site_local(u8 *a) {
    u8 b;

    if (a[0] != 0xFE) {
        return 0;
    }
    b = a[1];
    if (!(b & 0x80) || !(b & 0x40)) {
        return 0;
    }
    return 1;
}
inline s16 ipv6_is_global_unicast(u8 *a) {
    if ((a[0] & 0xE0) != 0x20) {
        return 0;
    }
    return 1;
}

s16 NetIPv6GetAddressScopeClass(u8 *a) {
    if (ipv6_is_link_local(a)) {
        return 2;
    }
    if (ipv6_is_site_local(a)) {
        return 3;
    }
    if (ipv6_is_global_unicast(a)) {
        return 4;
    }
    if (ipv6_is_multicast(a)) {
        switch (a[1] & 0xF) {
        case 1:
            return 1;
        case 2:
            return 2;
        case 5:
            return 3;
        default:
            return 4;
        }
    }
    if (NetIPv6IsLoopback(a)) {
        return 1;
    }
    return 0;
}

inline Ipv6Iface *ipv6_active_iface(s16 id) {
    Ipv6State *g;
    Ipv6Iface *e;

    if (id < 0 || id >= (g = &ipv6_address_routing_state)->count) {
        return NULL;
    }
    e = g->ifaces;
    e += id;
    if (e->state != 1) {
        return NULL;
    }
    return e;
}

s16 NetIPv6GetInterfaceLinkLayerAddress(void *dst, s16 dst_size, s16 id) {
    Ipv6Iface *e;
    s16 r;

    e = ipv6_active_iface(id);
    if (e == NULL) {
        return -0x10A;
    }
    r = link_get_address_length(id, e->handle);
    if (r < 0) {
        return r;
    }
    if (r > dst_size) {
        return -2;
    }
    link_get_address(id, e->handle, dst);
    return r;
}

s16 NetIPv6GetLinkLocalAddress(void *out, s16 idx) {
    Ipv6State *g = &ipv6_address_routing_state;
    Ipv6Iface *ifc;
    s16 n;
    Ipv6AddrNode *node;
    u8 *addr;
    s16 max_nodes;

    ifc = ipv6_get_iface(g, idx);
    if (ifc == NULL) {
        return -0x10A;
    }
    addr = ifc->addr;
    if (ipv6_is_link_local(addr)) {
        NetMemcpy(out, ifc->addr, 16);
        return 0;
    }
    node = ifc->addrs;
    n = 0;
    max_nodes = g->max_addrs;
    for (; node != NULL && n < max_nodes; n++) {
        addr = node->addr;
        if (ipv6_is_link_local(addr)) {
            NetMemcpy(out, node->addr, 16);
            return 0;
        }
        node = node->next;
    }
    return -0x10A;
}

s16 *get_valid_entry(s16 iface) {
    s16 *state;
    if ((iface < 0) || (iface >= ipv6_address_routing_state.count)) {
        return NULL;
    }
    state = (s16 *)&ipv6_address_routing_state.ifaces[iface];
    if ((s16) *state != 1) {
        return NULL;
    }
    return state;
}

s32 NetIPv6MakeSolicitedNodeMulticastAddress(u8 *dst, u8 *addr) {
    dst[0] = 0xFF;
    dst[1] = 2;
    dst[2] = 0;
    dst[3] = 0;
    dst[4] = 0;
    dst[5] = 0;
    dst[6] = 0;
    dst[7] = 0;
    dst[8] = 0;
    dst[9] = 0;
    dst[0xA] = 0;
    dst[0xB] = 1;
    dst[0xC] = 0xFF;
    dst[0xD] = addr[0xD];
    dst[0xE] = addr[0xE];
    dst[0xF] = addr[0xF];
    return 0;
}

s32 init_ipv6_all_routers_multicast_address(u8 *address, s8 scope) {
    address[0] = 0xFF;
    address[1] = scope;
    address[2] = 0;
    address[3] = 0;
    address[4] = 0;
    address[5] = 0;
    address[6] = 0;
    address[7] = 0;
    address[8] = 0;
    address[9] = 0;
    address[0xA] = 0;
    address[0xB] = 0;
    address[0xC] = 0;
    address[0xD] = 0;
    address[0xE] = 0;
    address[0xF] = 2;
    return 0;
}

u8 init_ipv6_all_nodes_multicast_address(u8 *address, s8 scope) {
    address[0] = 0xFF;
    address[1] = scope;
    address[2] = 0;
    address[3] = 0;
    address[4] = 0;
    address[5] = 0;
    address[6] = 0;
    address[7] = 0;
    address[8] = 0;
    address[9] = 0;
    address[0xA] = 0;
    address[0xB] = 0;
    address[0xC] = 0;
    address[0xD] = 0;
    address[0xE] = 0;
    address[0xF] = 1;
    return 0;
}

s16 NetIPv6IsLinkLocal(u8 *address) {
    u8 second;

    if (address[0] != 0xFE) {
        return 0;
    }
    second = address[1];
    if (!(second & 0x80) || (second & 0x40)) {
        return 0;
    }
    return 1;
}

s16 NetIPv6IsLoopback(u8 *address) {
    if (address[0] != 0) {
        return 0;
    }
    if (address[1] != 0) {
        return 0;
    }
    if (address[2] != 0) {
        return 0;
    }
    if (address[3] != 0) {
        return 0;
    }
    if (address[4] != 0) {
        return 0;
    }
    if (address[5] != 0) {
        return 0;
    }
    if (address[6] != 0) {
        return 0;
    }
    if (address[7] != 0) {
        return 0;
    }
    if (address[8] != 0) {
        return 0;
    }
    if (address[9] != 0) {
        return 0;
    }
    if (address[10] != 0) {
        return 0;
    }
    if (address[11] != 0) {
        return 0;
    }
    if (address[12] != 0) {
        return 0;
    }
    if (address[13] != 0) {
        return 0;
    }
    if (address[14] != 0) {
        return 0;
    }
    if (address[15] == 1) {
        return 1;
    }
    return 0;
}

s16 NetIPv6IsMulticast(u8 *address) {
    if (*address == 0xFF) {
        return 1;
    }
    return 0;
}

s16 NetIPv6IsUnspecified(u8 *address) {
    if (address[0] != 0) {
        return 0;
    }
    if (address[1] != 0) {
        return 0;
    }
    if (address[2] != 0) {
        return 0;
    }
    if (address[3] != 0) {
        return 0;
    }
    if (address[4] != 0) {
        return 0;
    }
    if (address[5] != 0) {
        return 0;
    }
    if (address[6] != 0) {
        return 0;
    }
    if (address[7] != 0) {
        return 0;
    }
    if (address[8] != 0) {
        return 0;
    }
    if (address[9] != 0) {
        return 0;
    }
    if (address[10] != 0) {
        return 0;
    }
    if (address[11] != 0) {
        return 0;
    }
    if (address[12] != 0) {
        return 0;
    }
    if (address[13] != 0) {
        return 0;
    }
    if (address[14] != 0) {
        return 0;
    }
    if (address[15] != 0) {
        return 0;
    }
    return 1;
}

s16 NetIPv6CompareAddresses(u8 *a, u8 *b) {
    s32 order;
    order = NetMemcmp(a, b, 0x10);
    if (order < 0) {
        return -1;
    }
    if (order > 0) {
        return 1;
    }
    return 0;
}

void NetIPv6CopyPrefix(u8 *dst, s16 bits, u8 *src)
{
  s16 i;
  s16 n;
  s16 rem;
  s16 end;
  s32 b;
  if ((bits < 0) || ((b = bits) > 0x80))
  {
    return;
  }
  n = b / 8;
  rem = b % 8;
  i = 0;
  if (n > 0)
  {
    end = n - 8;
    if (n > 8)
    {
      for (; i < end; i += 8)
      {
        dst[0] = src[0];
        dst[1] = src[1];
        dst[2] = src[2];
        dst[3] = src[3];
        dst[4] = src[4];
        dst[5] = src[5];
        dst[6] = src[6];
        dst[7] = src[7];
        src += 8;
        dst += 8;
      }

    }
    for (; i < n; i++)
    {
      *(dst++) = *(src++);
    }

  }
  switch (rem)
  {
    case 7:
      *(dst++) = (*src) & 0xFE;
      n++;
      break;

    case 6:
      *(dst++) = (*src) & 0xFC;
      n++;
      break;

    case 5:
      *(dst++) = (*src) & 0xF8;
      n++;
      break;

    case 4:
      *(dst++) = (*src) & 0xF0;
      n++;
      break;

    case 3:
      *(dst++) = (*src) & 0xE0;
      n++;
      break;

    case 2:
      *(dst++) = (*src) & 0xC0;
      n++;
      break;

    case 1:
      *(dst++) = (*src) & 0x80;
      n++;
      break;

  }

  for (; n < 16; n++)
  {
    *(dst++) = 0;
  }

}

s16 NetCompareBitsBackward(u8 *lhs, u8 *rhs, s16 bits) {
    s16 n;
    s16 rem;
    s32 a;
    s32 b;
    if (bits <= 0) {
        return 0;
    }
    rem = bits % 8;
    n = bits / 8;
    while (n > 0) {
        if (*lhs != *rhs) {
            return *lhs - *rhs;
        }
        lhs--;
        rhs--;
        n--;
    }
    switch (rem) {
    case 1:
        a = *lhs & 1;
        b = *rhs & 1;
        if (a != b) {
            return a - b;
        }
        return 0;
    case 2:
        a = *lhs & 3;
        b = *rhs & 3;
        if (a != b) {
            return a - b;
        }
        return 0;
    case 3:
        a = *lhs & 7;
        b = *rhs & 7;
        if (a != b) {
            return a - b;
        }
        return 0;
    case 4:
        a = *lhs & 0xF;
        b = *rhs & 0xF;
        if (a != b) {
            return a - b;
        }
        return 0;
    case 5:
        a = *lhs & 0x1F;
        b = *rhs & 0x1F;
        if (a != b) {
            return a - b;
        }
        return 0;
    case 6:
        a = *lhs & 0x3F;
        b = *rhs & 0x3F;
        if (a != b) {
            return a - b;
        }
        return 0;
    case 7:
        a = *lhs & 0x7F;
        b = *rhs & 0x7F;
        if (a != b) {
            return a - b;
        }
        return 0;
    }
    return 0;
}

s16 NetCompareBitPrefix(u8 *a, u8 *b, s16 bits) {
    s16 n;
    s16 rem;
    if (bits <= 0) {
        return 0;
    }
    rem = bits % 8;
    n = bits / 8;
    for (; n > 0; n--) {
        if (*a != *b) {
            return *a - *b;
        }
        a++;
        b++;
    }
    switch (rem) {
    case 1:
        if ((*a & 0x80) != (*b & 0x80)) return (*a & 0x80) - (*b & 0x80);
        return 0;
    case 2:
        if ((*a & 0xC0) != (*b & 0xC0)) return (*a & 0xC0) - (*b & 0xC0);
        return 0;
    case 3:
        if ((*a & 0xE0) != (*b & 0xE0)) return (*a & 0xE0) - (*b & 0xE0);
        return 0;
    case 4:
        if ((*a & 0xF0) != (*b & 0xF0)) return (*a & 0xF0) - (*b & 0xF0);
        return 0;
    case 5:
        if ((*a & 0xF8) != (*b & 0xF8)) return (*a & 0xF8) - (*b & 0xF8);
        return 0;
    case 6:
        if ((*a & 0xFC) != (*b & 0xFC)) return (*a & 0xFC) - (*b & 0xFC);
        return 0;
    case 7:
        if ((*a & 0xFE) != (*b & 0xFE)) return (*a & 0xFE) - (*b & 0xFE);
        return 0;
    case 0:
    default:
        return 0;
    }
}

Ipv6State ipv6_address_routing_state;
