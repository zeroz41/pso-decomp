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

s16 NetIPv4AddRoute(u32, u32, u32, s16, u8, u16);

#include <stddef.h>


#include "pso/network/IPv6Send.h"
#include "pso/network/NetStackTypes.h"

s32 init_ipv4_routing(void);

/* Inline the helpers below; this applies to the rest of the file. */
#pragma dont_inline off
#pragma inline_depth(4)

s32 shutdown_ipv4_routing(void) {
    TLobby__sub_803F8958((void *)&ipv4_address_routing_state);
    ipv4_address_routing_state.nroutes = 0;
    ipv4_address_routing_state.nifaces = 0;
    ipv4_address_routing_state.max_aliases = 0;
    return 0;
}
s32 init_ipv4_routing(void) {
    init_buffer_descriptor_a(&ipv4_address_routing_state);
    NetMemset(ipv4_address_routing_state.routes, 0, ipv4_address_routing_state.nroutes * sizeof(Ipv4Route));
    /* Sized with Ipv4Route (0x14 bytes), not Ipv4Iface (0x1C): the last 8 bytes of each entry are not cleared. */
    NetMemset(ipv4_address_routing_state.ifaces, 0, ipv4_address_routing_state.nifaces * sizeof(Ipv4Route));
    NetMemset(ipv4_address_routing_state.alias_pool, 0, ipv4_address_routing_state.max_aliases * sizeof(Ipv4Alias));
    return 0;
}

inline s16 chk_8040EDE4(s16 id, u32 k) {
    Ipv4Iface *p;
    p = (Ipv4Iface *)get_active_entry_by_index(id);
    if (p == NULL) {
        return 0;
    }
    if (p->addr == 0 || k == 0xFFFFFFFF || k == p->broadcast) {
        return 1;
    }
    return 0;
}

extern s16 AT_IP4_PktSend(NetPacket *self, u32 key, s16 id) {
    Ipv4Iface *e;

    if (id < 0 || id >= ipv4_address_routing_state.nifaces) {
        return -0x109;
    }
    e = ipv4_address_routing_state.ifaces;
    e += id;
    if (e->state != 1) {
        return -6;
    }
    if (key == 0 || chk_8040EDE4(id, key)) {
        return call_handler_by_index(id, e->handle, 1, (saddr)&key, (saddr)self);
    }
    return dispatch_handler_by_index(id, e->handle, (saddr)&key, (saddr)self);
}
#pragma push
#pragma opt_common_subs on
s16 get_ipv4_interface_mtu(s16 arg0) {
    Ipv4Iface *ifc;
    if ((arg0 < 0) || (arg0 >= ipv4_address_routing_state.nifaces)) {
        return -0x109;
    }
    ifc = &ipv4_address_routing_state.ifaces[arg0];
    if (ifc->state != 1) {
        return -2;
    }
    return ifc->mtu;
}
#pragma pop

inline s16 getfirst_8040F1A0(s16 *pn, Ipv4Iface **pb, u32 *out) {
    if (*pn <= 0) {
        return 0;
    }
    if ((*pb)->state != 1) {
        return 0;
    }
    *out = (*pb)->addr;
    return 1;
}

inline void drop_8040F1A0(Ipv4RoutingState *g, u32 k1, u32 k2) {
    s16 i;
    Ipv4Route *e;
    e = g->routes;
    for (i = 0; i < g->nroutes; i++, e++) {
            if ((e->flags & 1) && e->dst == k1 && e->gateway == k2 && (e->type & 1) == 1) {
            e->flags = 0;
            break;
        }
    }
}

extern s16 AT_IP4_SrcAddrSel(u32 *out, u32 dst, s16 c)
{
  s16 n;
  u32 new_var;
  Ipv4RoutingState *tbl;
  Ipv4Iface *new_var2;
  Ipv4Iface *e;
  s16 i;
  Ipv4Alias *node;
  u32 m;
  tbl = &ipv4_address_routing_state;
  if ((c < 0) || (c >= tbl->nifaces))
  {
    return -6;
  }
  e = (new_var2 = tbl->ifaces);
  e += c;
  if (e->state == 1)
  {
    u32 a = e->addr;
    m = e->mask;
    if ((m & a) == (m & dst))
    {
      *out = a;
      return 0;
    }
    node = e->aliases;
    n = tbl->max_aliases;
    for (i = 0; (node != NULL) && (i < n); i++)
    {
      m = node->mask;
      new_var = node->addr;
      if ((m & new_var) == (m & dst))
      {
        *out = new_var;
        return 0;
      }
      node = node->next;
    }

  }
  return -6;
}

typedef struct Ipv4IfaceAddrRecord {
    s32 kind;
    u32 addr;
    u32 mask;
    u32 broadcast;
    u8 pad10[0xC];
} Ipv4IfaceAddrRecord;
LAYOUT_ASSERT(Ipv4IfaceAddrRecord_size_check, sizeof(Ipv4IfaceAddrRecord) == 0x1C);
extern s32 copy_ipv4_interface_addresses(s16 idx, NetBufferRef *out, s16 len, s32 buf) {
    Ipv4RoutingState *g = &ipv4_address_routing_state;
    Ipv4Iface *ifc;
    s16 n;
    s32 count;
    Ipv4Alias *alias;
    Ipv4IfaceAddrRecord rec;
    NetBufferRef ref;

    if (idx < 0 || idx >= g->nifaces) {
        return -0x109;
    }
    ifc = g->ifaces;
    ifc += idx;
    if (ifc->state != 1) {
        return -2;
    }
    if ((u32)len < sizeof(rec)) {
        return -2;
    }
    rec.kind = 4;
    rec.addr = ifc->addr;
    rec.mask = ifc->mask;
    rec.broadcast = ifc->broadcast;
    set_value_and_enable((&ref), (saddr)&rec);
    netbuf_copy_by_ref(out, &ref, sizeof(rec));
    netbuf_ref_advance(out, sizeof(rec));
    alias = ifc->aliases;
    count = 1;
    n = 0;
    len -= sizeof(rec);
    while (len >= sizeof(rec) && alias != NULL && n < g->max_aliases) {
        rec.kind = 4;
        rec.addr = alias->addr;
        rec.mask = alias->mask;
        rec.broadcast = alias->broadcast;
        set_value_and_enable((&ref), (saddr)&rec);
        netbuf_copy_by_ref(out, &ref, sizeof(rec));
        netbuf_ref_advance(out, sizeof(rec));
        alias = alias->next;
        count++;
        n++;
        len -= sizeof(rec);
    }
    if (TLobby__sub_80409EB0(idx, ifc->handle) <= 6) {
        TLobby__sub_80409E18(idx, ifc->handle, buf);
    }
    return count;
}

extern s32 bring_down_ipv4_interface(s16 id) {
    Ipv4RoutingState *g;
    s16 *pn;
    Ipv4Iface **pb;
    s16 cnt;
    Ipv4Iface *b;
    Ipv4Alias *nd;
    u32 addr;
    g = &ipv4_address_routing_state;

    if (id < 0 || id >= *(pn = &g->nifaces)) {
        return -0x109;
    }
    b = *(pb = &g->ifaces);
    b += id;
    if (b->state != 1) {
        return 0;
    }
    nd = b->aliases;
    cnt = 0;
    while (nd != NULL && cnt < g->max_aliases) {
        if (is_socket_flag_set(id) == 0 && getfirst_8040F1A0(pn, pb, &addr)) {
            drop_8040F1A0(g, nd->addr, addr);
        }
        TLobby__sub_80409D7C(id, b->handle, 2, &nd->addr);
        {
            Ipv4Alias *next = nd->next;
            nd->f0 = 0;
            nd->addr = 0;
            nd->network = 0;
            nd->broadcast = 0;
            nd->mask = 0;
            nd->next = NULL;
            cnt++;
            nd = next;
        }
    }
    if (is_socket_flag_set(id) == 0 && getfirst_8040F1A0(pn, pb, &addr)) {
        drop_8040F1A0(g, b->addr, addr);
    }
    {
        Ipv4Route *e;
        s16 n;
        n = g->nroutes;
        e = g->routes;
        for (; n > 0; n--, e++) {
            if ((e->flags & 1) && e->iface == id) {
                e->flags = 0;
            }
        }
    }
    call_entry_callback(id, b->handle);
    b->state = 0;
    b->handle = 0;
    b->mtu = 0;
    b->addr = 0;
    b->network = 0;
    b->broadcast = 0;
    b->mask = 0;
    b->aliases = NULL;
    return 0;
}

#pragma push
#pragma opt_common_subs on
extern s16 AT_IP4_IfUp(u32 addr, u32 mask, u32 broadcast, s16 idx) {
    Ipv4RoutingState *g = &ipv4_address_routing_state;
    s16 *pn;
    Ipv4Iface **pifs;
    s16 unspecified;
    Ipv4Iface *ifc;
    s16 r;
    s16 err;
    s16 found;
    u32 gateway;

    if (idx < 0 || idx >= *(pn = &g->nifaces)) {
        return -0x109;
    }
    ifc = *(pifs = &g->ifaces);
    ifc += idx;
    if (ifc->state == 1) {
        return -2;
    }
    ifc->state = 1;
    ifc->handle = TLobby__sub_8040A044(idx, 0x800, 4, &addr);
    if (ifc->handle < 0) {
        ifc->state = 0;
        return ifc->handle;
    }
    if (addr == 0 && mask == 0xFFFFFFFF) {
        unspecified = 1;
    } else {
        unspecified = 0;
    }
    ifc->addr = addr;
    ifc->network = addr & mask;
    if (broadcast != 0) {
        ifc->broadcast = broadcast;
    } else {
        ifc->broadcast = ifc->network | ~mask;
    }
    ifc->mask = mask;
    r = invoke_socket_callback(idx, ifc->handle);
    if (r < g->min_mtu) {
        ifc->state = 0;
        return -6;
    }
    ifc->mtu = r;
    found = 0;
    ifc->aliases = NULL;
    gateway = 0xFFFFFFFF;
    if (is_socket_flag_set(idx) == 0 && !unspecified) {
        found = getfirst_8040F1A0(pn, pifs, &gateway);
        if (found) {
            found = NetIPv4AddRoute(addr, 0xFFFFFFFF, gateway, 0, 1, 0);
            if (found < 0) {
                call_entry_callback(idx, ifc->handle);
                ifc->state = 0;
                ifc->handle = 0;
                ifc->mtu = 0;
                ifc->addr = 0;
                ifc->network = 0;
                ifc->broadcast = 0;
                ifc->mask = 0;
                return found;
            }
        }
    }
    err = NetIPv4AddRoute(addr & mask, mask, addr, 0, 1, 0);
    if (err < 0) {
        if (is_socket_flag_set(idx) == 0 && gateway != 0xFFFFFFFF && !unspecified) {
            drop_8040F1A0(g, addr, gateway);
        }
        call_entry_callback(idx, ifc->handle);
        ifc->state = 0;
        ifc->handle = 0;
        ifc->mtu = 0;
        ifc->addr = 0;
        ifc->network = 0;
        ifc->broadcast = 0;
        ifc->mask = 0;
        return err;
    }
    return 0;
}
#pragma pop
s16 AT_IP4_IsReachable(u32 ipv4, u32 arg1) {
    if (AT_IP4_RouteSearch(ipv4, arg1) != NULL) {
        return 1;
    }
    return 0;
}

Ipv4Route *AT_IP4_RouteSearch(u32 a0, u32 a1) {
    u32 t;
    u16 flags;
    s16 i;
    Ipv4Route *e;
    Ipv4Route *m1;
    Ipv4Route *m2;
    Ipv4Route *m3;

    m1 = NULL;
    m2 = NULL;
    m3 = NULL;
    e = ipv4_address_routing_state.routes;
    for (i = 0; i < ipv4_address_routing_state.nroutes; i++, e++) {
        flags = e->flags;
        t = a0 & e->mask;
        if (!(flags & 1)) {
            continue;
        }
        if ((flags & 4) && e->dst == a0) {
            return e;
        }
        if ((flags & 8) && e->type == 1) {
            if (a0 == 0xFFFFFFFF || a0 == 0) {
                if (e->gateway == a1) {
                    m1 = e;
                    continue;
                }
            } else if (e->dst == t) {
                m1 = e;
                continue;
            }
        }
        if (!(flags & 2)) {
            continue;
        }
        if (e->dst == 0) {
            if (m3 == NULL) {
                m3 = e;
            }
        } else if (e->dst == t) {
            if (m2 == NULL) {
                m2 = e;
            }
        }
    }
    if (m1 != NULL) {
        return m1;
    }
    if (m2 != NULL) {
        return m2;
    }
    if (m3 != NULL) {
        return m3;
    }
    return NULL;
}

s32 TLobby__sub_8040F8A4(u32 a1, u32 new_gateway, u32 a3, u32 a4, u32 old_gateway)
{
  Ipv4RoutingState *tbl = &ipv4_address_routing_state;
  u32 new_var;
  u16 f;
  s16 i;
  s16 found = 0;
  Ipv4Route *e;
  s16 NetIPv4AddRoute(u32, u32, u32, int, int, int); /* declared here with promoted parameter types; the definition is s16 (u32, u32, u32, s16, u8, u16) */
  for (i = 0, e = tbl->routes; i < tbl->nroutes; i++, e++)
  {
    if (!(e->flags & 1))
    {
      continue;
    }
    if (e->gateway != old_gateway)
    {
      continue;
    }
    new_var = e->dst;
    if (new_var == 0)
    {
      a4 |= 2;
      found = 1;
      continue;
    }
    f = (u16) a4;
    if (a4 & 4)
    {
      if (((!e->flags) & 4) || (new_var != a1))
      {
        continue;
      }
      e->flags = f | 0x20;
      e->gateway = new_gateway;
      return 0;
    }
    if (e->flags & 4)
    {
      continue;
    }
    if ((a1 & e->mask) != (new_var & a3))
    {
      continue;
    }
    e->flags = f | 0x10;
    e->gateway = new_gateway;
    return 0;
  }

  if (found != 0)
  {
    if (NetIPv4AddRoute(a1, a3, new_gateway, 1, 2, a4) != 0)
    {
      return -1;
    }
  }
  return 0;
}

extern s32 TLobby__sub_8040F9CC(void *a, void *unused, void *b, s32 flag) {
    Ipv4RoutingState *tbl = &ipv4_address_routing_state;
    Unk805BDD60Entry *e = (Unk805BDD60Entry *)tbl->routes;
    s16 i;
    u8 f = (u8)flag & 1;
    for (i = 0; i < tbl->nroutes; i++, e++) {
        if (!(e->flags & 1)) {
            continue;
        }
        if (e->f4 != (uaddr)a) {
            continue;
        }
        if (e->fC != (uaddr)b) {
            continue;
        }
        if (f != (e->f12 & 1)) {
            continue;
        }
        e->flags = 0;
        return 0;
    }
    return -2;
}

inline s16 find_iface_by_addr_8040FA48(Ipv4Iface *ifaces, s16 n, s16 m, u32 addr) {
    s16 i;
    s16 j;
    Ipv4Iface *ifc;
    Ipv4Alias *a;

    ifc = ifaces;

    for (i = 0; i < n; i++, ifc++) {
        if (ifc->state == 1) {
            if (ifc->addr == addr) {
                return i;
            }
            for (a = ifc->aliases, j = 0; a != NULL && j < m; j++) {
                if (a->addr == addr) {
                    return i;
                }
                a = a->next;
            }
        }
    }
    return -1;
}
inline s16 find_iface_by_network_8040FA48(Ipv4Iface *ifaces, s16 n, s16 m, u32 addr) {
    s16 i;
    s16 j;
    Ipv4Iface *ifc;
    Ipv4Alias *a;

    ifc = ifaces;

    for (i = 0; i < n; i++, ifc++) {
        if (ifc->state == 1) {
            if (ifc->network == (ifc->mask & addr)) {
                return i;
            }
            for (a = ifc->aliases, j = 0; a != NULL && j < m; j++) {
                if (a->network == (a->mask & addr)) {
                    return i;
                }
                a = a->next;
            }
        }
    }
    return -1;
}
inline Ipv4Iface *get_ifaces_8040FA48(Ipv4RoutingState *g) {
    return g->ifaces;
}
#pragma push
#pragma opt_common_subs on
s16 NetIPv4AddRoute(u32 dst, u32 mask, u32 gateway, s16 f10, u8 type, u16 flags) {
    Ipv4RoutingState *g = &ipv4_address_routing_state;
    Ipv4Iface *ifaces;
    s16 m;
    s16 n;
    s16 idx;
    s16 i;
    Ipv4Route *e;
    Ipv4Route *slot;

    ifaces = get_ifaces_8040FA48(g);
    m = g->max_aliases;
    n = g->nifaces;
    idx = find_iface_by_addr_8040FA48(ifaces, n, m, gateway);
    if (idx < 0) {
        idx = find_iface_by_network_8040FA48(ifaces, n, m, gateway);
        if (idx < 0) {
            return -2;
        }
    }
    e = g->routes;
    slot = NULL;
    for (i = 0; i < g->nroutes; i++, e++) {
        if (e->flags & 1) {
            if (e->dst == dst && (dst != 0 || mask != 0 || gateway != 0 || type != 1)) {
                return -2;
            }
        } else {
            slot = e;
            break;
        }
    }
    if (slot == NULL) {
        return -0x107;
    }
    slot->dst = dst;
    slot->gateway = gateway;
    slot->type = type;
    slot->f10 = f10;
    slot->iface = idx;
    switch (type) {
    case 1:
        if (mask == 0xFFFFFFFF) {
            slot->flags = 0xD;
        } else {
            slot->flags = 9;
        }
        slot->mask = mask;
        break;
    case 2:
        slot->flags = flags | 1;
        if (flags & 4) {
            slot->mask = 0xFFFFFFFF;
        } else {
            slot->mask = mask;
        }
        break;
    case 3:
        slot->flags = 0xB;
        slot->mask = mask;
        break;
    default:
        if (mask == 0xFFFFFFFF) {
            slot->flags = 0xF;
        } else {
            slot->flags = 0xB;
        }
        slot->mask = mask;
        break;
    }
    return 0;
}
#pragma pop

s16 ipv4_iface_for_address(u32 ip) {
    Ipv4RoutingState *g;
    s16 m;
    s16 n;
    s16 i;
    s16 j;
    Ipv4Iface *e;
    Ipv4Alias *a;

    g = &ipv4_address_routing_state;
    e = g->ifaces;
    i = 0;
    m = g->max_aliases;
    n = g->nifaces;

    for (; i < n; i++, e++) {
        if (e->state == 1) {
            if (e->addr == ip) {
                return i;
            }
            for (a = e->aliases, j = 0; a != NULL && j < m; j++) {
                if (a->addr == ip) {
                    return i;
                }
                a = a->next;
            }
        }
    }
    return -1;
}

s16 NetIPv4IsLoopback(s32 address) {
    if ((u32) ((address & 0xFF000000) + 0x81000000) == 0U) {
        return 1;
    }
    return 0;
}

s16 NetIPv4IsBroadcast(u32 arg0, s16 arg1) {
    Ipv4Iface *e;
    if (arg1 < 0 || arg1 >= ipv4_address_routing_state.nifaces) {
        e = NULL;
    } else {
        e = ipv4_address_routing_state.ifaces;
        e += arg1;
        if (e->state != 1) {
            e = NULL;
        }
    }
    if (e == NULL) {
        return 0;
    }
    if (e->addr == 0 || arg0 == 0xFFFFFFFF || arg0 == e->broadcast) {
        return 1;
    }
    return 0;
}

s16 NetIPv4IsUnspecified(u32 address) {
    if (address == 0U) {
        return 1;
    }
    return 0;
}

#pragma push
#pragma opt_common_subs on
s16 NetIPv4IsInterfaceUp(s16 iface) {
    Ipv4Iface *ifc;
    if ((iface < 0) || (iface >= ipv4_address_routing_state.nifaces)) {
        ifc = NULL;
    } else {
        ifc = &ipv4_address_routing_state.ifaces[iface];
        if (ifc->state != 1) {
            ifc = NULL;
        }
    }
    if (ifc != NULL) {
        return 1;
    }
    return 0;
}
#pragma pop

#pragma push
#pragma opt_common_subs on
s16 *get_active_entry_by_index(s16 arg0) {
    Ipv4Iface *ifc;
    if ((arg0 < 0) || (arg0 >= ipv4_address_routing_state.nifaces)) {
        return NULL;
    }
    ifc = &ipv4_address_routing_state.ifaces[arg0];
    if (ifc->state != 1) {
        return NULL;
    }
    return (s16 *)ifc;
}
#pragma pop

s16 TLobby__sub_8040FEE4(s32 ipv4, s32 arg1) {
    s32 temp_r0;
    temp_r0 = ipv4 - arg1;
    if (temp_r0 < 0) {
        return -1;
    }
    if (temp_r0 > 0) {
        return 1;
    }
    return 0;
}

Ipv4RoutingState ipv4_address_routing_state;
