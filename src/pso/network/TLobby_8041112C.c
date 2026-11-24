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
#include "pso/network/NetIPv6NeighborDiscovery.h"

#include "types.h"
#include "pso/network/TLobby_803FCF44.h"
#include "pso/network/TLobby_804050DC.h"
#include "pso/network/TLobby_8041112C.h"

#include <stddef.h>

#include "pso/network/IPv6Send.h"
#include "pso/network/NetStackTypes.h"

s16 TLobby__sub_80413D78(void *self, s16 idx);
s16 TLobby__sub_80413F0C(void *self, s16 id);


s32 TLobby__sub_80409E18(s16 arg0, s32 arg1, s32 arg2);


/* Inline the helpers below; this applies to the rest of the file. */
#pragma dont_inline off
#pragma inline_depth(4)

extern s32 TLobby__sub_80411DEC(IPv6Address *addr, s32 mtu);

void TLobby__sub_80411334(void);
s32 TLobby__sub_8041112C(void) {
    Ipv6State *g = &ipv6_address_routing_state;
    NetUnregisterTimer(TLobby__sub_80411334);
    NetUnregisterTimer(tick_entry_timers);
    TLobby__sub_803F8864(g);
    g->route_count = 0;
    g->count = 0;
    g->max_addrs = 0;
    return 0;
}

s32 TUdpSocket__sub_8041118C(void) {
    init_udp_socket_config(&ipv6_address_routing_state);
    NetMemset(ipv6_address_routing_state.routes, 0, ipv6_address_routing_state.route_count * sizeof(Ipv6Route));
    /* Clears count * sizeof(Ipv6Route) bytes of the interface table, not count * sizeof(Ipv6Iface). */
    NetMemset(ipv6_address_routing_state.ifaces, 0, ipv6_address_routing_state.count * sizeof(Ipv6Route));
    NetMemset(ipv6_address_routing_state.addr_pool, 0, ipv6_address_routing_state.max_addrs * sizeof(Ipv6AddrNode));
    NetMemset(ipv6_address_routing_state.pmtu, 0, ipv6_address_routing_state.pmtu_count * sizeof(Ipv6PmtuEntry));
    NetRegisterTimer(0x3E8, (s16)(1), (NetTimerCallback)(TLobby__sub_80411334));
    NetRegisterTimer(0x3E8, (s16)(1), (NetTimerCallback)(tick_entry_timers));
    return 0;
}

s16 TLobby__sub_8041123C(NetPacket *packet, u8 *link_address, s16 iface) {
    Ipv6Iface *ifc;
    if ((iface < 0) || (iface >= ipv6_address_routing_state.count)) {
        return -0x10A;
    }
    ifc = &ipv6_address_routing_state.ifaces[iface];
    if (ifc->state != 1) {
        return -6;
    }
    return call_handler_by_index(iface, ifc->handle, 0, (saddr)link_address, (saddr)packet);
}

s16 TLobby__sub_804112B8(NetPacket *packet, IPv6Address *destination, s16 iface) {
    Ipv6Iface *ifc;
    if ((iface < 0) || (iface >= ipv6_address_routing_state.count)) {
        return -0x10A;
    }
    ifc = &ipv6_address_routing_state.ifaces[iface];
    if (ifc->state != 1) {
        return -6;
    }
    return call_handler_by_index(iface, ifc->handle, 2, (saddr)destination, (saddr)packet);
}

s32 TLobby__sub_80411604(s16 id, int n, void *pp);
s16 TLobby__sub_80412618(Ipv6NdPrefixEvent *pi, s16 idx);
typedef struct Ipv6NdEvent {
    u8 *addr;
    s16 prefix_len;
} Ipv6NdEvent;
LAYOUT_ASSERT(Ipv6NdEvent_size_check, sizeof(Ipv6NdEvent) == 8);
void TLobby__sub_80411334(void) {
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
                if (ifc->f18 == 0) {
                    ifc->dad_state = 4;
                } else {
                    ifc->dad_state = 3;
                }
                ev.addr = ifc->addr;
                ev.prefix_len = ifc->prefix_len;
                TLobby__sub_80411604(i, 0, &ev);
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
                    if (a->f16 == 0) {
                        a->state = 4;
                    } else {
                        a->state = 3;
                    }
                    ev.addr = a->addr;
                    ev.prefix_len = a->prefix_len;
                    TLobby__sub_80411604(i, 0, &ev);
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

void TLobby__sub_80414B98(u8* dst, s16 bits, u8* src);

inline s16 cmp16_80411604(void *a, void *b) {
    s32 t = NetMemcmp(a, b, 16);
    if (t < 0) {
        return -1;
    }
    if (t > 0) {
        return 1;
    }
    return 0;
}

inline void remove_80411604(Ipv6State *g, s16 len, u8 *addr, void *src) {
    u8 grp[16];
    s16 n;
    Ipv6Route *e;
    TLobby__sub_80414B98(grp, len, addr);
    n = g->route_count;
    e = g->routes;
    for (; n > 0; n--, e++) {
        if (e->state == 1 && e->prefix_len == len && cmp16_80411604(e->prefix, grp) == 0 && cmp16_80411604(e->gateway, src) == 0) {
            e->state = 0;
            return;
        }
    }
}

s32 TLobby__sub_80411604(s16 id, int n, void *pp)
{
  s16 TLobby__sub_8042325C(s16, s32, void *, void *); /* declared with 4 parameters; the definition is s32 (s32, s32, s32, s32 (*fn)(s32, s32, s32)) */
  void *h;
  s16 i;
  Ipv6State *g = &ipv6_address_routing_state;
  u8 *ent;
  s16 t;
  u8 *e;
  u8 *p = (u8 *) pp;
  u8 a92[16];
  s32 ret; /* results of the adds below, never checked; the original frame keeps both slots */
  s16 err;
  if ((id < 0) || (id >= (*((s16 *) (((u8 *) g) + offsetof(Ipv6State, count))))))
  {
    return -266;
  }
  e = *((u8 **) (((u8 *) g) + offsetof(Ipv6State, ifaces)));
  e += id * sizeof(Ipv6Iface);
  if ((*((s16 *) e)) != 1)
  {
    return -2;
  }
  t = 1;
  if ((h = *((void **) (e + offsetof(Ipv6Iface, callback)))) != 0)
  {
    t = TLobby__sub_8042325C(id, n, p, h);
  }
  switch (n)
  {
    case 0:
      ent = (u8 *)g->routes;
      for (i = 0; i < g->route_count; i++, ent += sizeof(Ipv6Route))
    {
      if (((*((s16 *) ent)) == 1) && ((*((s16 *) (ent + offsetof(Ipv6Route, type)))) == 0))
      {
        if ((*((s16 *) (ent + offsetof(Ipv6Route, prefix_len)))) == (*((s16 *) (p + 4))))
        {
          if (cmp16_80411604(ent + offsetof(Ipv6Route, gateway), *((void **) p)) == 0)
          {
            *((s16 *) (ent + offsetof(Ipv6Route, type))) = 1;
          }
        }
        else
          if ((*((s16 *) (ent + offsetof(Ipv6Route, prefix_len)))) == 128)
        {
          if (cmp16_80411604(ent + offsetof(Ipv6Route, prefix), *((void **) p)) == 0)
          {
            *((s16 *) (ent + offsetof(Ipv6Route, type))) = 1;
          }
        }
      }
    }

      break;

    case 1:
      if ((*((s16 *) (e + offsetof(Ipv6Iface, dad_timer)))) > 0)
    {
      *((s16 *) (e + offsetof(Ipv6Iface, dad_timer))) = 0;
    }
      break;

    case 2:
      if (t == 1)
    {
      err = TLobby__sub_80412618((Ipv6NdPrefixEvent *) p, id);
    }
      break;

    case 3:
      ipv6_protocol_state.hop_limit = p[4];
      break;

    case 4:
      *((s16 *) (e + offsetof(Ipv6Iface, mtu))) = *((s32 *) (p + 4));
      break;

    case 5:
      if (t == 1)
    {
      NetMemset(a92, 0, 16);
      ret = TLobby__sub_8041347C(a92, 0, *((u8 **) p), id, 2, 4);
    }
      break;

    case 6:
      if (t == 1)
    {
      NetMemset(a92, 0, 16);
      remove_80411604(g, 0, a92, *((u8 **) p));
    }
      break;

    case 7:
      if (t == 1)
    {
      NetMemset(a92, 0, 16);
      remove_80411604(g, 0, a92, *((u8 **) p));
      ret = TLobby__sub_8041347C(a92, 0, *((u8 **) (p + 4)), id, 2, 4);
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
      remove_80411604(g, 0, a92, *((u8 **) p));
    }
      break;

    case 10:
      if (t == 1)
    {
      remove_80411604(g, *((s16 *) (p + 4)), *((u8 **) p), *((u8 **) (p + 8)));
      ret = TLobby__sub_8041347C(*((u8 **) p), 128, *((u8 **) (p + 12)), id, 3, 4);
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

inline s16 ipv6_addr_compare(void *a, void *b) {
    s32 r = NetMemcmp(a, b, sizeof(IPv6Address));

    if (r < 0) {
        return -1;
    } else if (r > 0) {
        return 1;
    }
    return 0;
}
inline Ipv6Iface *iface_80411C44(Ipv6State *g, s16 idx) {
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
s16 TLobby__sub_80411C44(u8 *addr, s16 idx) {
    Ipv6State *g = &ipv6_address_routing_state;
    Ipv6Iface *ifc = iface_80411C44(g, idx);
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
s32 TLobby__sub_80411DEC(addr, mtu)
IPv6Address *addr;
s16 mtu;
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

s16 TLobby__sub_80414218(void *, void *);
s16 TLobby__sub_80411F1C(void *out, void *dst, s16 idx) {
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
            score = TLobby__sub_80414218(ifc->addr, dst);
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
                score = TLobby__sub_80414218(node->addr, dst);
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

extern s32 TLobby__sub_80412058(s16 id, u8 *self, s32 len, u8 *out) {
    struct AddrRec_80412058 {
        u32 kind;
        u8 addr[0x10];
        s16 a;
        s16 b;
        u32 c;
    };
    s16 n;
    s32 i;
    struct AddrRec_80412058 rec;
    u8 *ent;
    u8 ref[8];
    u8 *cur;
    u8 *st;

    st = (u8 *)&ipv6_address_routing_state;
    if (id < 0 || id >= *(s16 *)(st + offsetof(Ipv6State, count))) {
        return -0x10A;
    }
    ent = *(u8 **)(st + offsetof(Ipv6State, ifaces));
    ent += id * sizeof(Ipv6Iface);
    if (*(s16 *)ent != 1) {
        return -2;
    }
    if ((u32)(s16)len < 0x1C) {
        return -2;
    }
    rec.kind = 6;
    NetMemcpy(rec.addr, ent + offsetof(Ipv6Iface, addr), 0x10);
    rec.a = *(s16 *)(ent + offsetof(Ipv6Iface, prefix_len));
    rec.b = *(s16 *)(ent + offsetof(Ipv6Iface, flags));
    rec.c = *(u32 *)(ent + offsetof(Ipv6Iface, callback));
    set_value_and_enable((NetBufferRef *)ref, (saddr)&rec);
    netbuf_copy_by_ref(self, ref, 0x1C);
    netbuf_ref_advance((NetBufferRef *)self, 0x1C);
    cur = *(u8 **)(ent + offsetof(Ipv6Iface, addrs));
    i = 1;
    n = 0;
    len -= 0x1C;
    while ((u32)(s16)len >= 0x1C && cur != NULL && n < *(s16 *)(st + offsetof(Ipv6State, max_addrs))) {
        rec.kind = 6;
        NetMemcpy(rec.addr, cur + offsetof(Ipv6AddrNode, addr), 0x10);
        rec.a = *(s16 *)(cur + offsetof(Ipv6AddrNode, prefix_len));
        rec.b = *(s16 *)(cur + offsetof(Ipv6AddrNode, f18));
        rec.c = 0;
        set_value_and_enable((NetBufferRef *)ref, (saddr)&rec);
        netbuf_copy_by_ref(self, ref, 0x1C);
        netbuf_ref_advance((NetBufferRef *)self, 0x1C);
        cur = *(u8 **)(cur + offsetof(Ipv6AddrNode, next));
        i++;
        n++;
        len -= 0x1C;
    }
    if (TLobby__sub_80409EB0(id, *(s16 *)(ent + offsetof(Ipv6Iface, handle))) <= 6) {
        TLobby__sub_80409E18(id, *(s16 *)(ent + offsetof(Ipv6Iface, handle)), (saddr)out);
    }
    return i;
}

inline s16 cmp_8041347C(void *a, void *b) {
    s32 r = NetMemcmp(a, b, 16);
    if (r < 0) {
        return -1;
    }
    if (r > 0) {
        return 1;
    }
    return 0;
}

inline s16 ll_8041347C(u8 *a) {
    s16 r;
    if (a[0] != 0xfe) {
        r = 0;
    } else if ((a[1] & 0x80) == 0 || (a[1] & 0x40) != 0) {
        r = 0;
    } else {
        r = 1;
    }
    return r;
}

inline s16 cmp_80412210(void *a, void *b) {
    s32 r = NetMemcmp(a, b, 16);
    if (r < 0) {
        return -1;
    }
    if (r > 0) {
        return 1;
    }
    return 0;
}

inline s16 getaddr_80412210(s16 *n, Ipv6Iface **ifs, void *out) {
    if (*n <= 0) {
        return 0;
    }
    if ((*ifs)->state != 1) {
        return 0;
    }
    NetMemcpy(out, (*ifs)->addr, 16);
    return 1;
}

inline void remove_80412210(Ipv6State *g, void *grp, void *src) {
    s16 n = g->route_count;
    Ipv6Route *e = g->routes;
    for (; n > 0; n--, e++) {
        if (e->state == 1 && e->prefix_len == 0x80 && cmp_80412210(e->prefix, grp) == 0 && cmp_80412210(e->gateway, src) == 0) {
            e->state = 0;
            return;
        }
    }
}

s16 TLobby__sub_80412210(s16 idx) {
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
        if (is_socket_flag_set(idx) == 0 && getaddr_80412210(pn, pifs, d)) {
            TLobby__sub_80414B98(b, 0x80, grp->addr);
            remove_80412210(g, b, d);
        }
        TLobby__sub_80409D7C(idx, ifc->handle, 2, grp->addr);
        NetIPv6MakeSolicitedNodeMulticastAddress(c, grp->addr);
        TLobby__sub_80409CE0(idx, ifc->handle, 2, c);
        next = grp->next;
        grp->in_use = 0;
        NetMemset(grp->addr, 0, 16);
        grp->prefix_len = 0;
        count++;
        grp->next = NULL;
        grp = next;
    }
    if (is_socket_flag_set(idx) == 0 && getaddr_80412210(pn, pifs, d)) {
        TLobby__sub_80414B98(a, 0x80, ifc->addr);
        remove_80412210(g, a, d);
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
    TLobby__sub_80409CE0(idx, ifc->handle, 2, c);
    init_ipv6_all_nodes_multicast_address(c, (s8)(2));
    TLobby__sub_80409CE0(idx, ifc->handle, 2, c);
    init_ipv6_all_nodes_multicast_address(c, (s8)(1));
    TLobby__sub_80409CE0(idx, ifc->handle, 2, c);
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

inline s16 cmp16_80412618(void *a, void *b) {
    s32 t = NetMemcmp(a, b, 16);
    if (t < 0) {
        return -1;
    }
    if (t > 0) {
        return 1;
    }
    return 0;
}

inline s16 getaddr_80412618(s16 *n, u8 **ents, void *out) {
    if (*n <= 0) {
        return 0;
    }
    if (*(s16 *)*ents != 1) {
        return 0;
    }
    NetMemcpy(out, *ents + 4, 16);
    return 1;
}

inline void remove_80412618(Ipv6State *g, s16 len, u8 *addr, void *src) {
    u8 grp[16];
    s16 n;
    Ipv6Route *e;
    TLobby__sub_80414B98(grp, len, addr);
    n = g->route_count;
    e = g->routes;
    for (; n > 0; n--, e++) {
        if (e->state == 1 && e->prefix_len == len && cmp16_80412618(e->prefix, grp) == 0 && cmp16_80412618(e->gateway, src) == 0) {
            e->state = 0;
            return;
        }
    }
}

s16 TLobby__sub_80412618(Ipv6NdPrefixEvent *pi, s16 idx)
{
    Ipv6State *g = &ipv6_address_routing_state;
    u8 *pfx;
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
    r = TLobby__sub_8040A0C0(idx, new_addr + 8);
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
    if (cmp16_80412618(new_addr, e->addr) == 0) {
        return 0;
    }
    if (e->addrs != 0) {
        node = e->addrs;
        found = 0;
        i = 0;
        for (; node != 0 && i < g->max_addrs; node = node->next, i++) {
            if (node->f16 == 0) {
                if (cmp16_80412618(new_addr, node->addr) == 0) {
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
    pfx = (u8 *)g->addr_pool;
    r = *(s16 *)((u8 *)g + offsetof(Ipv6State, max_addrs));
    for (i = 0; i < r; i++, pfx += sizeof(Ipv6AddrNode)) {
        if (*(s16 *)pfx == 0) {
            *(s16 *)pfx = 1;
            break;
        }
    }

    if (i >= *pc) {
        return -266;
    }
    r = TLobby__sub_80409D7C(idx, e->handle, 1, new_addr);
    if (r < 0) {
        *(s16 *)pfx = 0;
        return r;
    }
    NetMemcpy(pfx + offsetof(Ipv6AddrNode, addr), new_addr, 16);
    *(s16 *)(pfx + offsetof(Ipv6AddrNode, prefix_len)) = pi->prefix_len;
    fl = 1;
    *(s16 *)(pfx + offsetof(Ipv6AddrNode, f16)) = fl;
    *(s16 *)(pfx + offsetof(Ipv6AddrNode, f18)) = 0;
    *(u16 *)(pfx + offsetof(Ipv6AddrNode, scope)) = NetIPv6GetAddressScopeClass(new_addr);
    if (is_entry_flag10_set(idx) != 0) {
        *(s16 *)(pfx + offsetof(Ipv6AddrNode, state)) = fl;
        fl = 0;
        *(s16 *)(pfx + offsetof(Ipv6AddrNode, dad_count)) = g->dad_count_init;
        *(s16 *)(pfx + offsetof(Ipv6AddrNode, dad_timer)) = g->dad_timer_init;
    } else {
        *(s16 *)(pfx + offsetof(Ipv6AddrNode, state)) = 3;
        fl = 1;
        *(s16 *)(pfx + offsetof(Ipv6AddrNode, dad_count)) = 0;
        *(s16 *)(pfx + offsetof(Ipv6AddrNode, dad_timer)) = 0;
    }
    *(u32 *)(pfx + offsetof(Ipv6AddrNode, valid_lifetime)) = pi->valid_lifetime;
    *(u32 *)(pfx + offsetof(Ipv6AddrNode, preferred_lifetime)) = pi->preferred_lifetime;
    *(u8 **)(pfx + offsetof(Ipv6AddrNode, next)) = 0;
    if (e->addrs == 0) {
        e->addrs = (Ipv6AddrNode *)pfx;
    } else {
        cur = e->addrs;
        for (i = 0; i < *pc; i++) {
            if (cur->next == 0) {
                break;
            }
            cur = cur->next;
        }

        if (cur->next == 0) {
            cur->next = (Ipv6AddrNode *)pfx;
        }
    }
    found = getaddr_80412618((s16 *)((u8 *)g + offsetof(Ipv6State, count)),
                             (u8 **)((u8 *)g + offsetof(Ipv6State, ifaces)), iface0_addr);
    if (found != 0) {
        r = TLobby__sub_8041347C(new_addr, 128, iface0_addr, 0, 3, 1);
        if (r < 0) {
            goto release;
        }
    }
    route = TLobby__sub_80413264(new_addr, new_addr);
    if (route != 0 && route->prefix_len == pi->prefix_len) {
        if (route->iface != idx) {
            goto drop_route;
        }
    } else {
        r = TLobby__sub_8041347C(new_addr, pi->prefix_len, new_addr, idx, fl, 1);
        if (r < 0) {
            goto drop_route;
        }
    }
    NetIPv6MakeSolicitedNodeMulticastAddress(solicited, new_addr);
    r = TLobby__sub_80409CE0(idx, e->handle, 1, solicited);
    if (r >= 0) {
        return 0;
    }
    remove_80412618(g, pi->prefix_len, new_addr, new_addr);
drop_route:
    if (is_socket_flag_set(idx) == 0) {
        remove_80412618(g, 128, new_addr, iface0_addr);
    }

release:
    err = TLobby__sub_80409D7C(idx, e->handle, 2, new_addr);

    if (e->addrs == (Ipv6AddrNode *)pfx) {
        e->addrs = 0;
    } else {
        cur->next = 0;
    }
    return r;
}

s16 TLobby__sub_80412CA4(u8 *addr, s16 plen, s16 x, s16 idx, saddr y)
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
    s32 err; /* release-path callback result, never checked (80411604 keeps such results too) */

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
        r = TLobby__sub_8040A0C0(idx, tmp + 8);
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
    e->handle = TLobby__sub_8040A044(idx, 0x86DD, 16, (u32 *)tmp);
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
    e->f18 = 0;
    e->flags = x;
    e->scope = NetIPv6GetAddressScopeClass(tmp);
    if (is_entry_flag10_set(idx)) {
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
    if (is_slot_flag_0x40_set(idx)) {
        e->rs_count = g->rs_count_init;
        e->rs_timer = g->rs_timer_init;
    } else {
        e->rs_count = 0;
        e->rs_timer = 0;
    }
    e->callback = (void *)y;
    e->addrs = NULL;
    if (!is_socket_flag_set(idx)) {
        found = getaddr_80412210(pn, pifs, ll);
        if (found) {
            ret = TLobby__sub_8041347C(tmp, 128, ll, 0, 3, 1);
            if (ret < 0) {
                goto release;
            }
        }
        ret = TLobby__sub_8041347C(tmp, plen, tmp, idx, fl, 1);
        if (ret < 0) {
            goto remove_ll;
        }
    } else {
        ret = TLobby__sub_8041347C(tmp, plen, tmp, idx, fl, 1);
        if (ret < 0) {
            goto remove_ll;
        }
    }
    init_ipv6_all_nodes_multicast_address(mcast, 1);
    ret = TLobby__sub_80409CE0(idx, e->handle, 1, mcast);
    if (ret < 0) {
        goto remove;
    }
    init_ipv6_all_nodes_multicast_address(mcast, 2);
    ret = TLobby__sub_80409CE0(idx, e->handle, 1, mcast);
    if (ret < 0) {
        goto remove;
    }
    NetIPv6MakeSolicitedNodeMulticastAddress(mcast, tmp);
    ret = TLobby__sub_80409CE0(idx, e->handle, 1, mcast);
    if (ret >= 0) {
        return 0;
    }
remove:
    remove_80412618(g, plen, tmp, tmp);
remove_ll:
    if (!is_socket_flag_set(idx)) {
        remove_80412618(g, 128, tmp, ll);
    }
release:
    /* result never read: the original frame keeps its 4-byte slot (release-dead check) */
    err = call_entry_callback(idx, e->handle);
    e->state = 0;
    e->handle = 0;
    e->mtu = 0;
    NetMemset(e->addr, 0, 16);
    e->prefix_len = 0;
    return ret;
}

s16 TLobby__sub_80413230(u8 *dst, saddr src) {
    if (TLobby__sub_80413264(dst, (void *)src) != NULL) {
        return 1;
    }
    return 0;
}

s16 TLobby__sub_804137FC(void *self, s16 idx);
inline s16 is_multicast_80413264(const IPv6Address *a) {
    if (a->bytes[0] == 0xFF) {
        return 1;
    }
    return 0;
}
inline Ipv6Route *routes_80413264(Ipv6State *g) {
    return g->routes;
}
Ipv6Route *TLobby__sub_80413264(void *dst, void *src) {
    Ipv6State *g = &ipv6_address_routing_state;
    s16 i;
    Ipv6Route *rt;
    Ipv6Route *host = NULL;
    Ipv6Route *prefix = NULL;
    Ipv6Route *deflt = NULL;

    rt = routes_80413264(g);
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
            if (is_multicast_80413264((IPv6Address *)dst)) {
                if (TLobby__sub_804137FC((u8 *)src, rt->iface) != 0) {
                    host = rt;
                }
            } else if (NetCompareBitPrefix(rt->prefix, (u8 *)dst, rt->prefix_len) == 0) {
                if (ipv6_is_link_local((u8 *)dst)) {
                    if (TLobby__sub_804137FC((u8 *)src, rt->iface) != 0) {
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

extern s16 TLobby__sub_8041347C(u8 *src, s16 id, u8 *key, s16 a, s16 b, s16 c) {
    Ipv6State *tbl = &ipv6_address_routing_state;
    s16 i;
    Ipv6Route *e;
    Ipv6Route *found;
    s16 sid;
    u8 buf[16];

    if (id < 0 || id > 0x80) {
        return -2;
    }
    if (a < 0 || a >= tbl->count) {
        return -2;
    }
    if (b != 1 && b != 2 && b != 3 && b != 0) {
        return -2;
    }
    if (c != 1 && c != 2 && c != 3 && c != 4) {
        return -2;
    }
    TLobby__sub_80414B98(buf, id, src);
    e = tbl->routes;
    sid = id;
    found = NULL;
    i = 0;
    for (; i < tbl->route_count; i++, e++) {
        if (e->state == 1) {
            if (e->prefix_len == sid && cmp_8041347C(e->prefix, buf) == 0) {
                if (!ll_8041347C(buf) || cmp_8041347C(e->gateway, key) == 0) {
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
    NetMemcpy(found->gateway, key, 16);
    found->type = b;
    found->f4 = c;
    found->prefix_len = id;
    found->iface = a;
    return 0;
}

s16 TLobby__sub_804136AC(s16 i)
{
    return is_slot_flag_0x20_set(i);
}

s16 TLobby__sub_804136CC(s16 i) {
    return is_socket_flag_set(i);
}

s16 ipv6_iface_for_address(void *self) {
    Ipv6State *base = &ipv6_address_routing_state;
    s16 i;
    s16 j;
    u8 *e;
    u8 *n;
    s32 r;
    s16 c;
    for (i = 0, e = (u8 *)base->ifaces; i < base->count; i++, e += sizeof(Ipv6Iface)) {
        if (*(s16 *)e == 1) {
            r = NetMemcmp(e + offsetof(Ipv6Iface, addr), self, 0x10);
            if (r < 0) c = -1;
            else if (r > 0) c = 1;
            else c = 0;
            if (c == 0) {
                return i;
            }
            for (n = *(u8 **)(e + offsetof(Ipv6Iface, addrs)), j = 0; n != 0 && j < base->max_addrs; n = *(u8 **)(n + offsetof(Ipv6AddrNode, next)), j++) {
                r = NetMemcmp(n + offsetof(Ipv6AddrNode, addr), self, 0x10);
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

s16 TLobby__sub_804137FC(void *addr, s16 idx) {
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
extern s32 TLobby__sub_80413934(u8 *addr, s16 idx) {
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

s16 TLobby__sub_80413AA0(void *self, s16 id) {
    u8 *tbl = (u8 *)&ipv6_address_routing_state;
    u8 *e = NULL;
    s16 i;
    u8 *p;
    s16 c;
    s32 r;
    if (id < 0 || id >= *(s16 *)(tbl + offsetof(Ipv6State, count))) {
        e = NULL;
    } else {
        e = *(u8 **)(tbl + offsetof(Ipv6State, ifaces));
        e += id * sizeof(Ipv6Iface);
        if (*(s16 *)e != 1) {
            e = NULL;
        }
    }
    if (e == NULL) {
        return 0;
    }
    r = NetMemcmp(e + offsetof(Ipv6Iface, addr), self, 16);
    if (r < 0) {
        c = -1;
    } else if (r > 0) {
        c = 1;
    } else {
        c = 0;
    }
    if (c == 0) {
        if (*(s16 *)(e + offsetof(Ipv6Iface, dad_state)) < 2) {
            return 0;
        }
        return 1;
    }
    p = *(u8 **)(e + offsetof(Ipv6Iface, addrs));
    i = 0;
    while (p != NULL && i < *(s16 *)(tbl + offsetof(Ipv6State, max_addrs))) {
        r = NetMemcmp(p + offsetof(Ipv6AddrNode, addr), self, 16);
        if (r < 0) {
            c = -1;
        } else if (r > 0) {
            c = 1;
        } else {
            c = 0;
        }
        if (c == 0) {
            if (*(s16 *)(p + offsetof(Ipv6AddrNode, state)) < 2) {
                return 0;
            }
            return 1;
        }
        p = *(u8 **)(p + offsetof(Ipv6AddrNode, next));
        i++;
    }
    return 0;
}

s16 TLobby__sub_80413C0C(void *self, s16 id) {
    u8 *tbl = (u8 *)&ipv6_address_routing_state;
    u8 *e = NULL;
    s32 i;
    u8 *p;
    s16 c;
    s32 r;
    if (id < 0 || id >= *(s16 *)(tbl + offsetof(Ipv6State, count))) {
        e = NULL;
    } else {
        e = *(u8 **)(tbl + offsetof(Ipv6State, ifaces));
        e += id * sizeof(Ipv6Iface);
        if (*(s16 *)e != 1) {
            e = NULL;
        }
    }
    if (e == NULL) {
        return 0;
    }
    r = NetMemcmp(e + offsetof(Ipv6Iface, addr), (u8 *)self, 16);
    if (r < 0) {
        c = -1;
    } else if (r > 0) {
        c = 1;
    } else {
        c = 0;
    }
    if (c == 0) {
        if (*(s16 *)(e + offsetof(Ipv6Iface, dad_state)) == 1) {
            return 1;
        }
        return 0;
    }
    p = *(u8 **)(e + offsetof(Ipv6Iface, addrs));
    i = 0;
    while (p != NULL && (s16)i < *(s16 *)(tbl + offsetof(Ipv6State, max_addrs))) {
        r = NetMemcmp(p + offsetof(Ipv6AddrNode, addr), (u8 *)self, 16);
        if (r < 0) {
            c = -1;
        } else if (r > 0) {
            c = 1;
        } else {
            c = 0;
        }
        if (c == 0) {
            if (*(s16 *)(p + offsetof(Ipv6AddrNode, state)) == 1) {
                return 1;
            }
            return 0;
        }
        p = *(u8 **)(p + offsetof(Ipv6AddrNode, next));
        i++;
    }
    return 0;
}

s16 TLobby__sub_80413D78(void *self, s16 idx) {
    u8 *tbl = (u8 *)&ipv6_address_routing_state;
    u8 *e = NULL;
    s32 i;
    u8 *p;
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
    if ((s16)idx < 0 || idx >= *(s16 *)(tbl + offsetof(Ipv6State, count))) {
        e = NULL;
    } else {
        e = *(u8 **)(tbl + offsetof(Ipv6State, ifaces));
        e += idx * sizeof(Ipv6Iface);
        if (*(s16 *)e != 1) {
            e = NULL;
        }
    }
    if (e == NULL) {
        return 0;
    }
    r = NetMemcmp(e + offsetof(Ipv6Iface, addr), self, 16);
    if (r < 0) {
        c = -1;
    } else if (r > 0) {
        c = 1;
    } else {
        c = 0;
    }
    if (c == 0) {
        if ((*(s16 *)(e + offsetof(Ipv6Iface, flags)) & 1) == 0) {
            return 0;
        }
        return 1;
    }
    p = *(u8 **)(e + offsetof(Ipv6Iface, addrs));
    i = 0;
    while (p != NULL && (s16)i < *(s16 *)(tbl + offsetof(Ipv6State, max_addrs))) {
        r = NetMemcmp(p + offsetof(Ipv6AddrNode, addr), self, 16);
        if (r < 0) {
            c = -1;
        } else if (r > 0) {
            c = 1;
        } else {
            c = 0;
        }
        if (c == 0) {
            if ((*(s16 *)(p + offsetof(Ipv6AddrNode, f18)) & 1) == 0) {
                return 0;
            }
            return 1;
        }
        p = *(u8 **)(p + offsetof(Ipv6AddrNode, next));
        i++;
    }
    return 0;
}

s16 TLobby__sub_80413F0C(void *self, s16 id)
{
    Ipv6State *base = &ipv6_address_routing_state;
    u8 *e = NULL;
    s16 i;
    u8 *p;
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
    if (id < 0 || (s16)id >= base->count) {
        e = NULL;
    } else {
        e = (u8 *)base->ifaces;
        e += (s16)id * sizeof(Ipv6Iface);
        if (*(s16 *)e != 1) {
            e = NULL;
        }
    }
    if (e == NULL) {
        return 0;
    }
    NetIPv6MakeSolicitedNodeMulticastAddress(buf, e + offsetof(Ipv6Iface, addr));
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
    p = *(u8 **)(e + offsetof(Ipv6Iface, addrs));
    i = 0;
    while (p != NULL && i < base->max_addrs) {
        NetIPv6MakeSolicitedNodeMulticastAddress(buf, p + offsetof(Ipv6AddrNode, addr));
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
        p = *(u8 **)(p + offsetof(Ipv6AddrNode, next));
        i++;
    }
    return 0;
}

inline Ipv6Iface *lookup_iface_804136EC(Ipv6State *g, s16 idx) {
    return ipv6_get_iface(g, idx);
}
extern s32 TLobby__sub_80414090(u8 *addr, s16 idx) {
    Ipv6State *g = &ipv6_address_routing_state;
    Ipv6Iface *ifc;
    s16 n;
    Ipv6AddrNode *node;

    if (!ipv6_is_link_local(addr)) {
        return 0;
    }
    ifc = lookup_iface_804136EC(g, idx);
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

s16 TLobby__sub_80414218(void* p, void* q) {
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
inline s16 ipv6_is_multicast(u8 *a) {
    if (a[0] == 0xFF) {
        return 1;
    }
    return 0;
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

inline Ipv6Iface *find_80414504(s16 id) {
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

s16 NetIPv6GetInterfaceLinkLayerAddress(s32 arg0, s16 arg1, s16 id) {
    Ipv6Iface *e;
    s16 r;

    e = find_80414504(id);
    if (e == NULL) {
        return -0x10A;
    }
    r = TLobby__sub_80409EB0(id, e->handle);
    if (r < 0) {
        return r;
    }
    if (r > arg1) {
        return -2;
    }
    TLobby__sub_80409E18(id, e->handle, arg0);
    return r;
}

s16 TLobby__sub_804145D4(void *out, s16 idx) {
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
    s16 *temp_r3;
    if ((iface < 0) || (iface >= ipv6_address_routing_state.count)) {
        return NULL;
    }
    temp_r3 = (s16 *)&ipv6_address_routing_state.ifaces[iface];
    if ((s16) *temp_r3 != 1) {
        return NULL;
    }
    return temp_r3;
}

s32 NetIPv6MakeSolicitedNodeMulticastAddress(u8 *arg0, u8 *addr) {
    *(u8 *)((s8 *)arg0 + 0) = 0xFF;
    *(s8 *)((s8 *)arg0 + 1) = 2;
    *(s8 *)((s8 *)arg0 + 2) = 0;
    *(s8 *)((s8 *)arg0 + 3) = 0;
    *(s8 *)((s8 *)arg0 + 4) = 0;
    *(s8 *)((s8 *)arg0 + 5) = 0;
    *(s8 *)((s8 *)arg0 + 6) = 0;
    *(s8 *)((s8 *)arg0 + 7) = 0;
    *(s8 *)((s8 *)arg0 + 8) = 0;
    *(s8 *)((s8 *)arg0 + 9) = 0;
    *(s8 *)((s8 *)arg0 + 0xA) = 0;
    *(s8 *)((s8 *)arg0 + 0xB) = 1;
    *(u8 *)((s8 *)arg0 + 0xC) = 0xFF;
    *(u8 *)((s8 *)arg0 + 0xD) = (u8) *(u8 *)((s8 *)addr + 0xD);
    *(u8 *)((s8 *)arg0 + 0xE) = (u8) *(u8 *)((s8 *)addr + 0xE);
    *(u8 *)((s8 *)arg0 + 0xF) = (u8) *(u8 *)((s8 *)addr + 0xF);
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

s16 NetIPv6IsLinkLocal(u8 *arg0) {
    u8 temp_r3;

    if ((u8) *(u8 *)((s8 *)arg0 + 0) != 0xFE) {
        return 0;
    }
    temp_r3 = *(u8 *)((s8 *)arg0 + 1);
    if (!(temp_r3 & 0x80) || (temp_r3 & 0x40)) {
        return 0;
    }
    return 1;
}

s16 NetIPv6IsLoopback(u8 *arg0) {
    typedef struct Fields_arg0 { u8 field_0; u8 field_1; u8 field_2; u8 field_3; u8 field_4; u8 field_5; u8 field_6; u8 field_7; u8 field_8; u8 field_9; u8 field_A; u8 field_B; u8 field_C; u8 field_D; u8 field_E; u8 field_F; } Fields_arg0;
    if ((u8) ((Fields_arg0*)arg0)->field_0 != 0) {
        return 0;
    }
    if ((u8) ((Fields_arg0*)arg0)->field_1 != 0) {
        return 0;
    }
    if ((u8) ((Fields_arg0*)arg0)->field_2 != 0) {
        return 0;
    }
    if ((u8) ((Fields_arg0*)arg0)->field_3 != 0) {
        return 0;
    }
    if ((u8) ((Fields_arg0*)arg0)->field_4 != 0) {
        return 0;
    }
    if ((u8) ((Fields_arg0*)arg0)->field_5 != 0) {
        return 0;
    }
    if ((u8) ((Fields_arg0*)arg0)->field_6 != 0) {
        return 0;
    }
    if ((u8) ((Fields_arg0*)arg0)->field_7 != 0) {
        return 0;
    }
    if ((u8) ((Fields_arg0*)arg0)->field_8 != 0) {
        return 0;
    }
    if ((u8) ((Fields_arg0*)arg0)->field_9 != 0) {
        return 0;
    }
    if ((u8) ((Fields_arg0*)arg0)->field_A != 0) {
        return 0;
    }
    if ((u8) ((Fields_arg0*)arg0)->field_B != 0) {
        return 0;
    }
    if ((u8) ((Fields_arg0*)arg0)->field_C != 0) {
        return 0;
    }
    if ((u8) ((Fields_arg0*)arg0)->field_D != 0) {
        return 0;
    }
    if ((u8) ((Fields_arg0*)arg0)->field_E != 0) {
        return 0;
    }
    if ((u8) ((Fields_arg0*)arg0)->field_F == 1) {
        return 1;
    }
    return 0;
}

s16 NetIPv6IsMulticast(u8 *address) {
    if ((u8) *address == 0xFF) {
        return 1;
    }
    return 0;
}

s16 NetIPv6IsUnspecified(u8 *bytes) {
    typedef struct Fields_arg0 { u8 field_0; u8 field_1; u8 field_2; u8 field_3; u8 field_4; u8 field_5; u8 field_6; u8 field_7; u8 field_8; u8 field_9; u8 field_A; u8 field_B; u8 field_C; u8 field_D; u8 field_E; u8 field_F; } Fields_arg0;
    if ((u8) ((Fields_arg0*)bytes)->field_0 != 0) {
        return 0;
    }
    if ((u8) ((Fields_arg0*)bytes)->field_1 != 0) {
        return 0;
    }
    if ((u8) ((Fields_arg0*)bytes)->field_2 != 0) {
        return 0;
    }
    if ((u8) ((Fields_arg0*)bytes)->field_3 != 0) {
        return 0;
    }
    if ((u8) ((Fields_arg0*)bytes)->field_4 != 0) {
        return 0;
    }
    if ((u8) ((Fields_arg0*)bytes)->field_5 != 0) {
        return 0;
    }
    if ((u8) ((Fields_arg0*)bytes)->field_6 != 0) {
        return 0;
    }
    if ((u8) ((Fields_arg0*)bytes)->field_7 != 0) {
        return 0;
    }
    if ((u8) ((Fields_arg0*)bytes)->field_8 != 0) {
        return 0;
    }
    if ((u8) ((Fields_arg0*)bytes)->field_9 != 0) {
        return 0;
    }
    if ((u8) ((Fields_arg0*)bytes)->field_A != 0) {
        return 0;
    }
    if ((u8) ((Fields_arg0*)bytes)->field_B != 0) {
        return 0;
    }
    if ((u8) ((Fields_arg0*)bytes)->field_C != 0) {
        return 0;
    }
    if ((u8) ((Fields_arg0*)bytes)->field_D != 0) {
        return 0;
    }
    if ((u8) ((Fields_arg0*)bytes)->field_E != 0) {
        return 0;
    }
    if ((u8) ((Fields_arg0*)bytes)->field_F != 0) {
        return 0;
    }
    return 1;
}

s16 NetIPv6CompareAddresses(u8 *a, u8 *b) {
    s32 temp_r3;
    temp_r3 = NetMemcmp(a, b, 0x10);
    if (temp_r3 < 0) {
        return -1;
    }
    if (temp_r3 > 0) {
        return 1;
    }
    return 0;
}

void TLobby__sub_80414B98(u8 *dst, s16 bits, u8 *src)
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

s16 NetCompareBitsBackward(u8 *arg0, u8 *arg1, s16 arg2) {
    s16 n;
    s16 rem;
    s32 a;
    s32 b;
    if (arg2 <= 0) {
        return 0;
    }
    rem = arg2 % 8;
    n = arg2 / 8;
    while (n > 0) {
        if (*arg0 != *arg1) {
            return *arg0 - *arg1;
        }
        arg0--;
        arg1--;
        n--;
    }
    switch (rem) {
    case 1:
        a = *arg0 & 1;
        b = *arg1 & 1;
        if (a != b) {
            return a - b;
        }
        return 0;
    case 2:
        a = *arg0 & 3;
        b = *arg1 & 3;
        if (a != b) {
            return a - b;
        }
        return 0;
    case 3:
        a = *arg0 & 7;
        b = *arg1 & 7;
        if (a != b) {
            return a - b;
        }
        return 0;
    case 4:
        a = *arg0 & 0xF;
        b = *arg1 & 0xF;
        if (a != b) {
            return a - b;
        }
        return 0;
    case 5:
        a = *arg0 & 0x1F;
        b = *arg1 & 0x1F;
        if (a != b) {
            return a - b;
        }
        return 0;
    case 6:
        a = *arg0 & 0x3F;
        b = *arg1 & 0x3F;
        if (a != b) {
            return a - b;
        }
        return 0;
    case 7:
        a = *arg0 & 0x7F;
        b = *arg1 & 0x7F;
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
