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

#include <stddef.h>

#include "pso/network/IPv6Send.h"
#include "pso/network/NetStackTypes.h"

s16 TLobby__sub_80413D78(); /* declared without a parameter list; the definition is s16 (self, idx) */
s16 TLobby__sub_80413F0C(); /* declared without a parameter list; the definition is s16 (self, id) */

s32 NetUnregisterTimer(void* p);

s32 TLobby__sub_80409CE0(s16 arg0, s32 arg1, s32 arg2, s32 arg3);

s32 TLobby__sub_80409D7C(s16 arg0, s32 arg1, s32 arg2, s32 arg3);

s32 TLobby__sub_80409E18(s16 arg0, s32 arg1, s32 arg2);

s32 TLobby__sub_80409EB0(s16 arg0, s32 arg1);

s32 TLobby__sub_8040A0C0(s16 idx, void *a);

/* Inline the helpers below; this applies to the rest of the file. */
#pragma dont_inline off
#pragma inline_depth(4)

extern s32 TLobby__sub_80411DEC(IPv6Address *addr, s32 mtu);

void TLobby__sub_80411334(void);
s32 TLobby__sub_8041112C(void) {
    Ipv6State *g = &ipv6_address_routing_state;
    NetUnregisterTimer((void *)TLobby__sub_80411334);
    NetUnregisterTimer((void *)tick_entry_timers);
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

#pragma push
#pragma opt_common_subs on
s16 TLobby__sub_8041123C(s32 arg0, s32 arg1, s16 arg2) {
    Ipv6Iface *ifc;
    if ((arg2 < 0) || (arg2 >= ipv6_address_routing_state.count)) {
        return -0x10A;
    }
    ifc = &ipv6_address_routing_state.ifaces[arg2];
    if (ifc->state != 1) {
        return -6;
    }
    return call_handler_by_index(arg2, ifc->handle, 0, arg1, arg0);
}
#pragma pop

#pragma push
#pragma opt_common_subs on
s16 TLobby__sub_804112B8(s32 arg0, s32 arg1, s16 arg2) {
    Ipv6Iface *ifc;
    if ((arg2 < 0) || (arg2 >= ipv6_address_routing_state.count)) {
        return -0x10A;
    }
    ifc = &ipv6_address_routing_state.ifaces[arg2];
    if (ifc->state != 1) {
        return -6;
    }
    return call_handler_by_index(arg2, ifc->handle, 2, arg1, arg0);
}
#pragma pop

s32 TLobby__sub_80411604(int, int, void *);
s32 NetIPv6SendRouterSolicitation(s32 arg0);
typedef struct Ipv6NdEvent {
    u8 *addr;
    s16 prefix_len;
} Ipv6NdEvent;
typedef char Ipv6NdEvent_size_check[sizeof(Ipv6NdEvent) == 8 ? 1 : -1];
void TLobby__sub_80411334(void) {
    s32 NetIPv6SendUnspecifiedSourceNeighborSolicitation(u8 *, s16); /* the definition takes the address as s32 */
    s32 NetIPv6SendRouterSolicitation(s16); /* declared here with an s16 1st argument; the definition takes s32 */
    s32 TLobby__sub_80411604(s16, int, void *); /* defined K&R with an s16 id */
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

s32 TLobby__sub_80411604(id, n, pp)
s16 id;
int n;
void *pp;
{
  s16 TLobby__sub_8042325C(s16, s32, void *, void *); /* declared with 4 parameters; the definition is s32 (s32, s32, s32, s32 (*fn)(s32, s32, s32)) */
  s32 TLobby__sub_8041347C(u8 *src, s16 id, u8 *key, s16 a, s16 b, s16 c);
  s16 TLobby__sub_80412618(void *, s16);
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
  if ((h = *((void **) (e + offsetof(Ipv6Iface, f28)))) != 0)
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
      err = TLobby__sub_80412618(p, id);
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
#pragma push
#pragma opt_common_subs on
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
#pragma pop

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

#pragma push
#pragma opt_common_subs on
s16 get_iface_mtu(s16 arg0) {
    Ipv6Iface *ifc;
    if ((arg0 < 0) || (arg0 >= ipv6_address_routing_state.count)) {
        return -0x10A;
    }
    ifc = &ipv6_address_routing_state.ifaces[arg0];
    if (ifc->state != 1) {
        return -2;
    }
    return ifc->mtu;
}
#pragma pop

s16 TLobby__sub_80414218(void *, void *);
s32 NetIPv6GetAddressScopeClass(u8 *arg0);
s16 TLobby__sub_80411F1C(void *out, void *dst, s16 idx) {
    Ipv6State *g = &ipv6_address_routing_state;
    u8 *sel = NULL;
    s16 best = 0;
    s16 scope;
    Ipv6Iface *ifc;
    s16 n;
    Ipv6AddrNode *node;
    s16 score;
    s16 NetIPv6GetAddressScopeClass(u8 *); /* declared s16 here; the definition returns s32 */

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

#pragma push
#pragma opt_common_subs on
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
    rec.b = *(s16 *)(ent + offsetof(Ipv6Iface, f1A));
    rec.c = *(u32 *)(ent + offsetof(Ipv6Iface, f28));
    set_value_and_enable((void *)ref, (s32)&rec);
    TLobby__sub_80406FD8(self, ref, 0x1C);
    TLobby__sub_80406EB8((NetBufferRef *)self, 0x1C);
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
        set_value_and_enable((void *)ref, (s32)&rec);
        TLobby__sub_80406FD8(self, ref, 0x1C);
        TLobby__sub_80406EB8((NetBufferRef *)self, 0x1C);
        cur = *(u8 **)(cur + offsetof(Ipv6AddrNode, next));
        i++;
        n++;
        len -= 0x1C;
    }
    if ((s16)TLobby__sub_80409EB0(id, *(s16 *)(ent + offsetof(Ipv6Iface, handle))) <= 6) {
        TLobby__sub_80409E18(id, *(s16 *)(ent + offsetof(Ipv6Iface, handle)), (s32)out);
    }
    return i;
}
#pragma pop

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
    s16 is_socket_flag_set(s16); /* declared s16 here; the definition returns s32 */
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
        TLobby__sub_80409D7C(idx, ifc->handle, 2, (s32)grp->addr);
        NetIPv6MakeSolicitedNodeMulticastAddress(c, grp->addr);
        TLobby__sub_80409CE0(idx, ifc->handle, 2, (s32)c);
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
    TLobby__sub_80409CE0(idx, ifc->handle, 2, (s32)c);
    init_ipv6_all_nodes_multicast_address(c, (s8)(2));
    TLobby__sub_80409CE0(idx, ifc->handle, 2, (s32)c);
    init_ipv6_all_nodes_multicast_address(c, (s8)(1));
    TLobby__sub_80409CE0(idx, ifc->handle, 2, (s32)c);
    call_entry_callback(idx, ifc->handle);
    ifc->state = 0;
    ifc->handle = 0;
    ifc->mtu = 0;
    NetMemset(ifc->addr, 0, 16);
    ifc->prefix_len = 0;
    ifc->addrs = NULL;
    ifc->f28 = 0;
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

#pragma push
#pragma opt_common_subs on
s16 TLobby__sub_80412618(pi, idx)
u8 *pi;
s16 idx;
{
  s16 TLobby__sub_8040A0C0(s16, void *); /* declared s16 here; the definition returns s32 */
  s16 TLobby__sub_80409D7C(s16, s32, s32, void *); /* declared s16 here; the definition is s32 (s16, s32, s32, s32) */
  s16 TLobby__sub_80409CE0(s16, s32, s32, s32); /* declared s16 here; the definition returns s32 */
  s16 NetCompareBitPrefix(void *, void *, s16); /* declared s16 here; the definition returns s32 */
  s16 is_entry_flag10_set(s16); /* declared s16 here; the definition returns s32 */
  s16 is_socket_flag_set(s16); /* declared s16 here; the definition returns s32 */
  s16 TLobby__sub_8041347C(u8 *, s16, u8 *, s16, s16, s16); /* declared s16 here; the definition returns s32 */
  Ipv6State *g = &ipv6_address_routing_state;
  s16 *pn;
  u8 *pfx;
  Ipv6Route *ent;
  u32 v;
  s16 rem;
  u8 *q;
  u8 *e;
  u8 mask;
  s32 plen;
  u8 *cur;
  u8 **pe;
  s16 r;
  s16 *pc;
  s16 n8;
  s16 fl;
  s16 found;
  s16 i;
  u8 tmp[16];
  u8 a68[16];
  u8 a52[16];
  s16 err;
  u8 *node;
  if ((idx <= 0) || (idx >= (*(pn = &g->count))))
  {
    return -266;
  }
  pe = (u8 **) (((u8 *) g) + offsetof(Ipv6State, ifaces));
  e = *((u8 **) (((u8 *) g) + offsetof(Ipv6State, ifaces)));
  e += idx * 48;
  if ((*((s16 *) e)) != 1)
  {
    return -2;
  }
  NetMemset(tmp, 0, 8);
  r = TLobby__sub_8040A0C0(idx, tmp + 8);
  if (r < 0)
  {
    return r;
  }
  plen = *((s16 *) (pi + 4));
  if ((pfx && pfx) && pfx)
  {
  }
  pfx = *((u8 **) pi);
  if (((s16) plen) > 0)
  {
    n8 = plen / 8;
    NetMemcpy(tmp, pfx, n8);
    if ((rem = plen % 8) != 0)
    {
      q = tmp + n8;
      mask = 255 >> rem;
      *q = (mask & (*q)) | (pfx[n8] & (~mask));
    }
  }
  if (cmp16_80412618(tmp, e + offsetof(Ipv6Iface, addr)) == 0)
  {
    return 0;
  }
  if ((*((u8 **) (e + offsetof(Ipv6Iface, addrs)))) != 0)
  {
    node = *((u8 **) (e + offsetof(Ipv6Iface, addrs)));
    found = 0;
    i = 0;
    for (; (node != 0) && (i < ((s16 *) g)[2]); node = *((u8 **) (node + offsetof(Ipv6AddrNode, next))), i++)
    {
      if ((*((s16 *) (node + offsetof(Ipv6AddrNode, f16)))) == 0)
      {
        if (cmp16_80412618(tmp, node + offsetof(Ipv6AddrNode, addr)) == 0)
        {
          found = 1;
        }
      }
      else
        if ((*((s16 *) (pi + 4))) == (*((s16 *) (node + offsetof(Ipv6AddrNode, prefix_len)))))
      {
        if (NetCompareBitPrefix(*((void **) pi), node + offsetof(Ipv6AddrNode, addr), *((s16 *) (pi + 4))) == 0)
        {
          found = 1;
          v = *((u32 *) (pi + 12));
          if ((v > 7200) || (v > (*((u32 *) (node + offsetof(Ipv6AddrNode, valid_lifetime))))))
          {
            *((u32 *) (node + offsetof(Ipv6AddrNode, valid_lifetime))) = v;
            *((u32 *) (node + offsetof(Ipv6AddrNode, preferred_lifetime))) = *((u32 *) (pi + 8));
          }
          else
            if (((*((u32 *) (node + offsetof(Ipv6AddrNode, valid_lifetime)))) > 7200) || (v > (*((u32 *) (node + offsetof(Ipv6AddrNode, valid_lifetime))))))
          {
            *((u32 *) (node + offsetof(Ipv6AddrNode, valid_lifetime))) = 7200;
          }
        }
      }
    }

    if (found)
    {
      return 0;
    }
  }
  pc = (s16 *) (((u8 *) g) + offsetof(Ipv6State, max_addrs));
  pfx = *((u8 **) (((u8 *) g) + offsetof(Ipv6State, addr_pool)));
  r = *((s16 *) (((u8 *) g) + offsetof(Ipv6State, max_addrs)));
  for (i = 0; i < r; i++, pfx += 44)
  {
    if ((*((s16 *) pfx)) == 0)
    {
      *((s16 *) pfx) = 1;
      break;
    }
  }

  if (i >= (*pc))
  {
    return -266;
  }
  r = TLobby__sub_80409D7C(idx, *((s16 *) (e + offsetof(Ipv6Iface, handle))), 1, tmp);
  if (r < 0)
  {
    *((s16 *) pfx) = 0;
    return r;
  }
  NetMemcpy(pfx + offsetof(Ipv6AddrNode, addr), tmp, 16);
  *((s16 *) (pfx + offsetof(Ipv6AddrNode, prefix_len))) = *((s16 *) (pi + 4));
  fl = 1;
  *((s16 *) (pfx + offsetof(Ipv6AddrNode, f16))) = fl;
  *((s16 *) (pfx + offsetof(Ipv6AddrNode, f18))) = 0;
  *((u16 *) (pfx + offsetof(Ipv6AddrNode, scope))) = NetIPv6GetAddressScopeClass(tmp);
  pe = (u8 **) (((u8 *) g) + offsetof(Ipv6State, ifaces));
  if (is_entry_flag10_set(idx) != 0)
  {
    *((s16 *) (pfx + offsetof(Ipv6AddrNode, state))) = fl;
    fl = 0;
    *((s16 *) (pfx + offsetof(Ipv6AddrNode, dad_count))) = *((s16 *) (((u8 *) g) + offsetof(Ipv6State, dad_count_init)));
    *((s16 *) (pfx + offsetof(Ipv6AddrNode, dad_timer))) = *((s16 *) (((u8 *) g) + offsetof(Ipv6State, dad_timer_init)));
  }
  else
  {
    *((s16 *) (pfx + offsetof(Ipv6AddrNode, state))) = 3;
    fl = 1;
    *((s16 *) (pfx + offsetof(Ipv6AddrNode, dad_count))) = 0;
    *((s16 *) (pfx + offsetof(Ipv6AddrNode, dad_timer))) = 0;
  }
  *((u32 *) (pfx + offsetof(Ipv6AddrNode, valid_lifetime))) = *((u32 *) (pi + 12));
  *((u32 *) (pfx + offsetof(Ipv6AddrNode, preferred_lifetime))) = *((u32 *) (pi + 8));
  *((u32 *) (pfx + offsetof(Ipv6AddrNode, next))) = 0;
  if ((*((u8 **) (e + offsetof(Ipv6Iface, addrs)))) == 0)
  {
    *((u8 **) (e + offsetof(Ipv6Iface, addrs))) = pfx;
  }
  else
  {
    cur = *((u8 **) (e + offsetof(Ipv6Iface, addrs)));
    for (i = 0; i < (*pc); i++)
    {
      if ((*((u8 **) (cur + offsetof(Ipv6AddrNode, next)))) == 0)
      {
        break;
      }
      cur = *((u8 **) (cur + offsetof(Ipv6AddrNode, next)));
    }

    if ((*((u8 **) (cur + offsetof(Ipv6AddrNode, next)))) == 0)
    {
      *((u8 **) (cur + offsetof(Ipv6AddrNode, next))) = pfx;
    }
  }
  found = getaddr_80412618(pn, pe, a68);
  if (found != 0)
  {
    r = TLobby__sub_8041347C(tmp, 128, a68, 0, 3, 1);
    if (r < 0)
    {
      goto L400;
    }
  }
  ent = TLobby__sub_80413264(tmp, tmp);
  if ((ent != 0) && (ent->prefix_len == (*((s16 *) (pi + 4)))))
  {
    if (ent->iface != idx)
    {
      goto L348;
    }
  }
  else
  {
    r = TLobby__sub_8041347C(tmp, *((s16 *) (pi + 4)), tmp, idx, fl, 1);
    if (r < 0)
    {
      goto L348;
    }
  }
  NetIPv6MakeSolicitedNodeMulticastAddress(a52, tmp);
  r = TLobby__sub_80409CE0(idx, *((s16 *) (e + offsetof(Ipv6Iface, handle))), 1, (s32) a52);
  if (r >= 0)
  {
    return 0;
  }
  n8 = *((s16 *) (pi + 4));
  remove_80412618(g, n8, tmp, tmp);
  L348:
  if (is_socket_flag_set(idx) == 0)
  {
    remove_80412618(g, 128, tmp, a68);
  }

  L400:
  err = TLobby__sub_80409D7C(idx, *((s16 *) (e + offsetof(Ipv6Iface, handle))), 2, tmp);

  if ((*((u8 **) (e + offsetof(Ipv6Iface, addrs)))) == pfx)
  {
    *((u8 **) (e + offsetof(Ipv6Iface, addrs))) = 0;
  }
  else
  {
    *((u8 **) (cur + offsetof(Ipv6AddrNode, next))) = 0;
  }
  return r;
}
#pragma pop

inline s16 cmp16_80412CA4(void *a, void *b) {
    s32 t = NetMemcmp(a, b, 16);
    if (t < 0) {
        return -1;
    }
    if (t > 0) {
        return 1;
    }
    return 0;
}

inline s16 getaddr_80412CA4(s16 *n, u8 **ents, void *out) {
    if (*n <= 0) {
        return 0;
    }
    if (*(s16 *)*ents != 1) {
        return 0;
    }
    NetMemcpy(out, *ents + 4, 16);
    return 1;
}

inline void remove_80412CA4(Ipv6State *g, s16 len, void *grp, void *src) {
    s16 n = g->route_count;
    Ipv6Route *e = g->routes;
    for (; n > 0; n--, e++) {
        if (e->state == 1 && e->prefix_len == len && cmp16_80412CA4(e->prefix, grp) == 0 && cmp16_80412CA4(e->gateway, src) == 0) {
            e->state = 0;
            return;
        }
    }
}

s16 TLobby__sub_80412CA4(u8 *addr, s32 plen, s16 x, s16 idx, s32 y)
{
  s16 TLobby__sub_8040A0C0(s16, void *); /* declared s16 here; the definition returns s32 */
  s16 TLobby__sub_8040A044(s16, u32, s32, u32 *); /* declared s16 here; the definition returns s32 */
  s16 invoke_socket_callback(s16); /* declared with 1 parameter, so calls here pass 1 argument; the definition is s32 (s16, s32) */
  s16 is_entry_flag10_set(s16); /* declared s16 here; the definition returns s32 */
  s16 is_slot_flag_0x40_set(s16); /* declared s16 here; the definition returns s32 */
  s16 is_socket_flag_set(s16); /* declared s16 here; the definition returns s32 */
  s16 TLobby__sub_8041347C(u8 *, s16, u8 *, s16, s16, s16); /* declared s16 here; the definition returns s32 */
  s16 TLobby__sub_80409CE0(s16, s32, s32, s32); /* declared s16 here; the definition returns s32 */
  s16 NetCompareBitsBackward(u8 *, u8 *, s16); /* declared s16 here; the definition returns s32 */
  void TLobby__sub_80414B98(u8 *, s32, u8 *); /* declared here with an s32 2nd argument; the definition takes s16 */
  s16 NetIPv6GetAddressScopeClass(u8 *); /* declared s16 here; the definition returns s32 */
  int new_var2;
  Ipv6State *g = &ipv6_address_routing_state;
  u8 **pe;
  int new_var3;
  u8 *e;
  s16 r;
  s16 found;
  s16 new_var[2];
  s16 fl;
  s16 rem;
  s16 *pn;
  u8 *q;
  u8 mask;
  u8 tmp[16];
  u8 a76[16];
  u8 a60[16];
  s32 h;
  u8 a40[16];
  u8 a24[16];
  if ((idx < 0) || (idx >= (*(pn = &g->count))))
  {
    return -266;
  }
  e = *(pe = (u8 **) (((u8 *) g) + offsetof(Ipv6State, ifaces)));
  e += idx * 48;
  if ((*((s16 *) e)) == 1)
  {
    return -2;
  }
  *((s16 *) e) = 1;
  NetMemset(tmp, 0, 16);
  new_var[1] = plen;
  if (NetCompareBitsBackward(tmp + 15, addr + 15, 128 - new_var[1]) != 0)
  {
    NetMemcpy(tmp, addr, 16);
  }
  else
  {
    r = TLobby__sub_8040A0C0(idx, tmp + 8);
    if (r < 0)
    {
      *((s16 *) e) = 0;
      return r;
    }
    if (((s16) (plen & 0xFFFFFFFFFFFFFFFFu)) > 0)
    {
      new_var[0] = new_var[1] / 8;
      NetMemcpy(tmp, addr, new_var[0]);
      if ((rem = new_var[1] % 8) != 0)
      {
        q = tmp + new_var[0];
        mask = 255 >> rem;
        *q = (mask & (*q)) | (addr[new_var[0]] & (~mask));
      }
    }
  }
  *((s16 *) (e + offsetof(Ipv6Iface, handle))) = TLobby__sub_8040A044(idx, 0x86DD, 16, (u32 *) tmp);
  h = *((s16 *) (e + offsetof(Ipv6Iface, handle)));
  if (((s16) h) < 0)
  {
    *((s16 *) e) = 0;
    return *((s16 *) (e + offsetof(Ipv6Iface, handle)));
  }
  r = invoke_socket_callback(idx);
  if (r < (*((s16 *) (((u8 *) g) + offsetof(Ipv6State, min_mtu)))))
  {
    *((s16 *) e) = 0;
    return -6;
  }
  *((s16 *) (e + offsetof(Ipv6Iface, mtu))) = r;
  NetMemcpy(e + offsetof(Ipv6Iface, addr), tmp, 16);
  *((s16 *) (e + offsetof(Ipv6Iface, prefix_len))) = new_var[1];
  found = 0;
  *((s16 *) (e + offsetof(Ipv6Iface, f18))) = 0;
  *((s16 *) (e + offsetof(Ipv6Iface, f1A))) = x;
  *((s16 *) (e + offsetof(Ipv6Iface, scope))) = NetIPv6GetAddressScopeClass(tmp);
  if (is_entry_flag10_set(idx) != 0)
  {
    *((s16 *) (e + offsetof(Ipv6Iface, dad_state))) = 1;
    fl = 0;
    *((s16 *) (e + offsetof(Ipv6Iface, dad_count))) = *((s16 *) (((u8 *) g) + offsetof(Ipv6State, dad_count_init)));
    *((s16 *) (e + offsetof(Ipv6Iface, dad_timer))) = *((s16 *) (((u8 *) g) + offsetof(Ipv6State, dad_timer_init)));
  }
  else
  {
    *((s16 *) (e + offsetof(Ipv6Iface, dad_state))) = 4;
    fl = 1;
    *((s16 *) (e + offsetof(Ipv6Iface, dad_count))) = found;
    *((s16 *) (e + offsetof(Ipv6Iface, dad_timer))) = found;
  }
  if (is_slot_flag_0x40_set(idx) != 0)
  {
    *((s16 *) (e + offsetof(Ipv6Iface, rs_count))) = *((s16 *) (((u8 *) g) + offsetof(Ipv6State, rs_count_init)));
    *((s16 *) (e + offsetof(Ipv6Iface, rs_timer))) = *((s16 *) (((u8 *) g) + offsetof(Ipv6State, rs_timer_init)));
  }
  else
  {
    *((s16 *) (e + offsetof(Ipv6Iface, rs_count))) = 0;
    *((s16 *) (e - (-36))) = 0;
  }
  *((s32 *) (e + offsetof(Ipv6Iface, f28))) = y;
  found = 0;
  *((s32 *) (e + offsetof(Ipv6Iface, addrs))) = found;
  if (is_socket_flag_set(idx) == 0)
  {
    found = getaddr_80412CA4(pn, pe, a76);
    if (found != 0)
    {
      r = TLobby__sub_8041347C(tmp, 128, a76, 0, 3, 1);
      if (r < 0)
      {
        goto L337;
      }
    }
    r = TLobby__sub_8041347C(tmp, new_var[1], tmp, idx, fl, 1);
    if (r < 0)
    {
      goto L285;
    }
  }
  else
  {
    r = TLobby__sub_8041347C(tmp, new_var[1], tmp, idx, fl, 1);
    if (r < 0)
    {
      goto L285;
    }
  }
  init_ipv6_all_nodes_multicast_address(a60, 1);
  r = TLobby__sub_80409CE0(idx, *((s16 *) (e + offsetof(Ipv6Iface, handle))), 1, (s32) a60);
  if (r < 0)
  {
    goto L236;
  }
  init_ipv6_all_nodes_multicast_address(a60, 2);
  r = TLobby__sub_80409CE0(idx, *((s16 *) (e + offsetof(Ipv6Iface, handle))), 1, (s32) a60);
  if (r < 0)
  {
    goto L236;
  }
  NetIPv6MakeSolicitedNodeMulticastAddress(a60, tmp);
  r = TLobby__sub_80409CE0(idx, *((s16 *) (e + offsetof(Ipv6Iface, handle))), 1, (s32) a60);
  new_var3 = r < 0;
  if (new_var3)
  {
    goto L236;
  }
  return 0;
  L236:
  TLobby__sub_80414B98(a40, plen, tmp);

  remove_80412CA4(g, plen, a40, tmp);
  L285:
  if (is_socket_flag_set(idx) == 0)
  {
    TLobby__sub_80414B98(a24, 128, tmp);
    remove_80412CA4(g, 128, a24, a76);
  }

  L337:
  call_entry_callback(idx, *((s16 *) (e + offsetof(Ipv6Iface, handle))));

  found = 0;
  *((s16 *) e) = found;
  *((s16 *) (e + offsetof(Ipv6Iface, handle))) = found;
  *((s16 *) (e + offsetof(Ipv6Iface, mtu))) = found;
  new_var2 = 4;
  NetMemset(e + new_var2, 0, 16);
  *((s16 *) (e + offsetof(Ipv6Iface, prefix_len))) = found;
  return r;
}

s16 TLobby__sub_80413230(u8 *arg0, s32 arg1) {
    if (TLobby__sub_80413264(arg0, (void *)arg1) != NULL) {
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
    /* declared s16 here; the definitions return s32 */
    s16 NetCompareBitPrefix(u8 *a, u8 *b, s16 bits);
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

extern s32 TLobby__sub_8041347C(u8 *src, s16 id, u8 *key, s16 a, s16 b, s16 c) {
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

s32 TLobby__sub_804136AC(s16 i)
{
    return is_slot_flag_0x20_set(i);
}

void TLobby__sub_804136CC(s16 i) {
    is_socket_flag_set(i);
}

s32 TLobby__sub_804136EC(void *self) {
    Ipv6State *base = &ipv6_address_routing_state;
    s32 i;
    s32 j;
    u8 *e;
    u8 *n;
    s32 r;
    s16 c;
    for (i = 0, e = (u8 *)base->ifaces; (s16)i < base->count; i++, e += sizeof(Ipv6Iface)) {
        if (*(s16 *)e == 1) {
            r = NetMemcmp(e + offsetof(Ipv6Iface, addr), self, 0x10);
            if (r < 0) c = -1;
            else if (r > 0) c = 1;
            else c = 0;
            if (c == 0) {
                return i;
            }
            for (n = *(u8 **)(e + offsetof(Ipv6Iface, addrs)), j = 0; n != 0 && (s16)j < base->max_addrs; n = *(u8 **)(n + offsetof(Ipv6AddrNode, next)), j++) {
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

s16 TLobby__sub_80413F0C(self, id)
    void *self;
    s16 id;
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

s16 TLobby__sub_80413AA0(self, id) void *self; s16 id; {
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

s16 TLobby__sub_80413C0C(self, id) void *self; s16 id; {
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

s16 TLobby__sub_80413D78(self, idx)
void *self;
s16 idx;
{
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
        if ((*(s16 *)(e + offsetof(Ipv6Iface, f1A)) & 1) == 0) {
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

s32 NetIPv6GetAddressScopeClass(u8 *arg0) {
    s16 var_r0;
    s16 var_r0_2;
    s16 var_r0_3;
    s16 var_r0_4;
    s32 var_r3;
    u8 var_r4;
    u8 var_r5;

    var_r5 = ((RecoveredFields_804143BC_arg0 *)arg0)->field_0;
    if (var_r5 != 0xFE) {
        var_r0 = 0;
    } else {
        var_r4 = ((RecoveredFields_804143BC_arg0 *)arg0)->field_1;
        if (!(var_r4 & 0x80) || (var_r4 & 0x40)) {
            var_r0 = 0;
        } else {
            var_r0 = 1;
        }
    }
    if (var_r0 != 0) {
        var_r3 = 2;
        return 2;
    }
    if (var_r5 != 0xFE) {
        var_r0_2 = 0;
    } else {
        var_r4 = ((RecoveredFields_804143BC_arg0 *)arg0)->field_1;
        if (!(var_r4 & 0x80) || !(var_r4 & 0x40)) {
            var_r0_2 = 0;
        } else {
            var_r0_2 = 1;
        }
    }
    if (var_r0_2 != 0) {
        var_r3 = 3;
        return 3;
    }
    if ((s32) (var_r5 & 0xE0) != 0x20) {
        var_r0_3 = 0;
    } else {
        var_r0_3 = 1;
    }
    if (var_r0_3 != 0) {
        var_r3 = 4;
        return 4;
    }
    if (var_r5 == 0xFF) {
        var_r0_4 = 1;
    } else {
        var_r0_4 = 0;
    }
    if (var_r0_4 != 0) {
        switch (((RecoveredFields_804143BC_arg0 *)arg0)->field_1 & 0xF) {
        case 1:
            var_r3 = 1;
            return 1;
        case 2:
            var_r3 = 2;
            return 2;
        case 5:
            var_r3 = 3;
            return 3;
        default:
            var_r3 = 4;
            return 4;
        }
    } else {
        if (NetIPv6IsLoopback(arg0) != 0) {
            var_r3 = 1;
            return 1;
        }
        var_r3 = 0;
        return 0;
    }
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
    s16 TLobby__sub_80409EB0(s16 arg0, s32 arg1); /* declared s16 here; the definition returns s32 */

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

#pragma push
#pragma opt_common_subs on
s16 *get_valid_entry(s16 arg0) {
    s16 *temp_r3;
    if ((arg0 < 0) || (arg0 >= ipv6_address_routing_state.count)) {
        return NULL;
    }
    temp_r3 = (s16 *)&ipv6_address_routing_state.ifaces[arg0];
    if ((s16) *temp_r3 != 1) {
        return NULL;
    }
    return temp_r3;
}
#pragma pop

s32 NetIPv6MakeSolicitedNodeMulticastAddress(u8 *arg0, u8 *arg1) {
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
    *(u8 *)((s8 *)arg0 + 0xD) = (u8) *(u8 *)((s8 *)arg1 + 0xD);
    *(u8 *)((s8 *)arg0 + 0xE) = (u8) *(u8 *)((s8 *)arg1 + 0xE);
    *(u8 *)((s8 *)arg0 + 0xF) = (u8) *(u8 *)((s8 *)arg1 + 0xF);
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

s32 NetIPv6IsLinkLocal(u8 *arg0) {
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

s16 NetIPv6IsMulticast(u8 *arg0) {
    if ((u8) *arg0 == 0xFF) {
        return 1;
    }
    return 0;
}

s16 NetIPv6IsUnspecified(u8 *arg0) {
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
    if ((u8) ((Fields_arg0*)arg0)->field_F != 0) {
        return 0;
    }
    return 1;
}

s32 NetIPv6CompareAddresses(s32 arg0, s32 arg1) {
    s32 temp_r3;
    temp_r3 = NetMemcmp((void *)arg0, (void *)arg1, 0x10);
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
  if ((!i) && (!i))
  {
  }
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

s32 NetCompareBitsBackward(u8 *arg0, u8 *arg1, s16 arg2) {
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

s32 NetCompareBitPrefix(u8 *a, u8 *b, s16 bits) {
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
