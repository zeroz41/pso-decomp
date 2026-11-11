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
typedef struct RtEntry_8040F8A4 RtEntry_8040F8A4;

s16 NetIPv4AddRoute(u32, u32, u32, s16, u8, u16);

#include <stddef.h>

typedef struct RtEntry_8040F8A4 { u16 flags; u8 pad2[2]; u32 id; u32 mask; u32 owner; u8 pad10[4]; } RtEntry_8040F8A4;


#include "pso/network/IPv6Send.h"
#include "pso/network/NetStackTypes.h"

s32 TLobby__sub_8040ED70(void);

/* Inline the helpers below; this applies to the rest of the file. */
#pragma dont_inline off
#pragma inline_depth(4)

s32 TLobby__sub_8040ED28(void) {
    TLobby__sub_803F8958((void *)&ipv4_address_routing_state);
    ipv4_address_routing_state.nroutes = 0;
    ipv4_address_routing_state.nifaces = 0;
    ipv4_address_routing_state.max_aliases = 0;
    return 0;
}
s32 TLobby__sub_8040ED70(void) {
    init_buffer_descriptor_a(&ipv4_address_routing_state);
    NetMemset(ipv4_address_routing_state.routes, 0, ipv4_address_routing_state.nroutes * sizeof(Ipv4Route));
    /* Sized with Ipv4Route (0x14 bytes), not Ipv4Iface (0x1C): the last 8 bytes of each entry are not cleared. */
    NetMemset(ipv4_address_routing_state.ifaces, 0, ipv4_address_routing_state.nifaces * sizeof(Ipv4Route));
    NetMemset(ipv4_address_routing_state.alias_pool, 0, ipv4_address_routing_state.max_aliases * sizeof(Ipv4Alias));
    return 0;
}

inline s16 chk_8040EDE4(s16 id, u32 k) {
    s16 *p;
    p = get_active_entry_by_index(id);
    if (p == NULL) {
        return 0;
    }
    if (*(u32 *)((s8 *)p + 8) == 0 || k == 0xFFFFFFFF || k == *(u32 *)((s8 *)p + 0xC)) {
        return 1;
    }
    return 0;
}

extern s16 TLobby__sub_8040EDE4(void *self, u32 key, s16 id) {
    s16 *e;

    if (id < 0 || id >= ipv4_address_routing_state.nifaces) {
        return -0x109;
    }
    e = (s16 *)ipv4_address_routing_state.ifaces;
    e += id * 14;
    if (e[0] != 1) {
        return -6;
    }
    if (key == 0 || chk_8040EDE4(id, key)) {
        return call_handler_by_index(id, e[1], 1, (s32)&key, (s32)self);
    }
    return dispatch_handler_by_index(id, e[1], (s32)&key, (s32)self);
}
#pragma push
#pragma opt_common_subs on
s32 TLobby__sub_8040EF00(s16 arg0) {
    typedef struct Fields_temp_r3 { s16 field_0; u8 pad_2[2]; s16 field_4; } Fields_temp_r3;
    u8 *temp_r3;
    if ((arg0 < 0) || (arg0 >= ipv4_address_routing_state.nifaces)) {
        return -0x109;
    }
    temp_r3 = (u8 *)&ipv4_address_routing_state.ifaces[arg0];
    if ((s16) ((Fields_temp_r3*)temp_r3)->field_0 != 1) {
        return -2;
    }
    return ((Fields_temp_r3*)temp_r3)->field_4;
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

extern s16 TLobby__sub_8040EF50(u32 *out, u32 mask, s16 c)
{
  s16 n;
  u32 new_var;
  u8 *tbl;
  u8 *new_var2;
  u8 *e;
  s16 i;
  u8 *node;
  u32 m;
  tbl = (u8 *) (&ipv4_address_routing_state);
  if ((c < 0) || (c >= (*((s16 *) (tbl + 0x2)))))
  {
    return -6;
  }
  e = (new_var2 = *((u8 **) (tbl + 0xc)));
  e += c * 0x1c;
  if ((*((s16 *) e)) == 1)
  {
    u32 a = *((u32 *) (e + 0x8));
    m = *((u32 *) (e + 0x14));
    if ((m & a) == (m & mask))
    {
      *out = a;
      return 0;
    }
    node = *((u8 **) (e + 0x18));
    n = *((s16 *) (tbl + 0x4));
    for (i = 0; (node != ((void *) 0)) && (i < n); i++)
    {
      m = *((u32 *) (0x10 + node));
      new_var = *((u32 *) (node + 0x4));
      if ((m & new_var) == (m & mask))
      {
        *out = new_var;
        return 0;
      }
      node = *((u8 **) (node + 0x14));
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
typedef char Ipv4IfaceAddrRecord_size_check[sizeof(Ipv4IfaceAddrRecord) == 0x1C ? 1 : -1];
extern s32 TLobby__sub_8040F00C(s16 idx, NetBufferRef *out, s16 len, s32 arg3) {
    s16 TLobby__sub_80409EB0(s16 arg0, s32 arg1); /* declared s16 here; the definition returns s32 */
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
    set_value_and_enable((&ref), (s32)&rec);
    TLobby__sub_80406FD8(out, &ref, sizeof(rec));
    TLobby__sub_80406EB8(out, sizeof(rec));
    alias = ifc->aliases;
    count = 1;
    n = 0;
    len -= sizeof(rec);
    while (len >= sizeof(rec) && alias != NULL && n < g->max_aliases) {
        rec.kind = 4;
        rec.addr = alias->addr;
        rec.mask = alias->mask;
        rec.broadcast = alias->broadcast;
        set_value_and_enable((&ref), (s32)&rec);
        TLobby__sub_80406FD8(out, &ref, sizeof(rec));
        TLobby__sub_80406EB8(out, sizeof(rec));
        alias = alias->next;
        count++;
        n++;
        len -= sizeof(rec);
    }
    if (TLobby__sub_80409EB0(idx, ifc->handle) <= 6) {
        TLobby__sub_80409E18(idx, ifc->handle, arg3);
    }
    return count;
}

extern s32 TLobby__sub_8040F1A0(s16 id) {
    Ipv4RoutingState *g;
    s16 *pn;
    Ipv4Iface **pb;
    s16 cnt;
    Ipv4Iface *b;
    Ipv4Alias *nd;
    u32 addr;
    s16 is_socket_flag_set(s16); /* declared s16 here; the definition returns s32 */
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
        TLobby__sub_80409D7C(id, b->handle, 2, (s32)&nd->addr);
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
extern s16 TLobby__sub_8040F454(u32 addr, u32 mask, u32 broadcast, s16 idx) {
    Ipv4RoutingState *g = &ipv4_address_routing_state;
    s16 *pn;
    Ipv4Iface **pifs;
    s16 unspecified;
    Ipv4Iface *ifc;
    s16 r;
    s16 err;
    s16 found;
    u32 gateway;
    s16 is_socket_flag_set(s16); /* declared s16 here; the definition returns s32 */
    s16 invoke_socket_callback(s16, s32); /* declared s16 here; the definition returns s32 */
    s16 TLobby__sub_8040A044(s16, u32, s32, u32 *); /* declared s16 here; the definition returns s32 */

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
s16 is_lookup_found(u32 arg0, u32 arg1) {
    if (TLobby__sub_8040F76C(arg0, arg1) != NULL) {
        return 1;
    }
    return 0;
}

u8 * TLobby__sub_8040F76C(a0, a1)
u32 a0;
u32 a1;
{
    u32 t;
    u16 flags;
    s16 i;
    u8 *e;
    u8 *m1;
    u8 *m2;
    u8 *m3;

    m1 = NULL;
    m2 = NULL;
    m3 = NULL;
    e = (u8 *)ipv4_address_routing_state.routes;
    for (i = 0; i < ipv4_address_routing_state.nroutes; i++, e += 0x14) {
        flags = *(u16 *)e;
        t = a0 & *(u32 *)(e + 8);
        if (!(flags & 1)) {
            continue;
        }
        if ((flags & 4) && *(u32 *)(e + 4) == a0) {
            return e;
        }
        if ((flags & 8) && *(s16 *)(e + 0x12) == 1) {
            if (a0 == 0xFFFFFFFF || a0 == 0) {
                if (*(u32 *)(e + 0xC) == a1) {
                    m1 = e;
                    continue;
                }
            } else if (*(u32 *)(e + 4) == t) {
                m1 = e;
                continue;
            }
        }
        if (!(flags & 2)) {
            continue;
        }
        if (*(u32 *)(e + 4) == 0) {
            if (m3 == NULL) {
                m3 = e;
            }
        } else if (*(u32 *)(e + 4) == t) {
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

extern s32 TLobby__sub_8040F8A4(u32 a1, void *a2, u32 a3, u32 a4, u32 a5)
{
  Ipv4RoutingState *tbl = &ipv4_address_routing_state;
  u32 new_var;
  u16 f;
  s16 i;
  s16 found = 0;
  RtEntry_8040F8A4 *e;
  s16 NetIPv4AddRoute(void *, void *, void *, int, int, int); /* declared here with other parameter types; the definition is s16 (u32, u32, u32, s16, u8, u16) */
  for (i = 0, e = (RtEntry_8040F8A4 *)tbl->routes; i < tbl->nroutes; i++, e++)
  {
    if (!(e->flags & 1))
    {
      continue;
    }
    if (e->owner != a5)
    {
      continue;
    }
    new_var = e->id;
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
      e->owner = (u32) a2;
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
    e->owner = (u32) a2;
    return 0;
  }

  if (found != 0)
  {
    if (NetIPv4AddRoute((void *) a1, (void *) a3, a2, 1, 2, a4) != 0)
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
        if (e->f4 != (u32)a) {
            continue;
        }
        if (e->fC != (u32)b) {
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

inline s16 trk_find1(u8 *p, s16 cntB, s16 cntC, u32 a)
{
    u8 *node;
    s16 i;
    s16 j;

    for (i = 0; i < cntB; i++, p += 0x1c) {
        if (*(s16 *)p == 1) {
            if (*(u32 *)(p + 8) == a) {
                return i;
            }
            node = *(u8 **)(p + 0x18);
            j = 0;
            while (node != 0 && j < cntC) {
                if (*(u32 *)(node + 4) == a) {
                    return i;
                }
                node = *(u8 **)(node + 0x14);
                j++;
            }
        }
    }
    return -1;
}

inline s16 trk_find2(u8 *p, s16 cntB, s16 cntC, u32 a)
{
    u8 *node;
    s16 i;
    s16 j;

    for (i = 0; i < cntB; i++, p += 0x1c) {
        if (*(s16 *)p == 1) {
            if (*(u32 *)(p + 0x10) == (*(u32 *)(p + 0x14) & a)) {
                return i;
            }
            node = *(u8 **)(p + 0x18);
            j = 0;
            while (node != 0 && j < cntC) {
                if (*(u32 *)(node + 0xC) == (*(u32 *)(node + 0x10) & a)) {
                    return i;
                }
                node = *(u8 **)(node + 0x14);
                j++;
            }
        }
    }
    return -1;
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

s16 TLobby__sub_8040FCEC(u32 ip) {
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

s16 NetIPv4IsLoopback(s32 arg0) {
    if ((u32) ((arg0 & 0xFF000000) + 0x81000000) == 0U) {
        return 1;
    }
    return 0;
}

s16 TLobby__sub_8040FDA0(u32 arg0, s16 arg1) {
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

s16 NetIPv4IsUnspecified(u32 arg0) {
    if (arg0 == 0U) {
        return 1;
    }
    return 0;
}

#pragma push
#pragma opt_common_subs on
s32 TLobby__sub_8040FE40(s16 arg0) {
    typedef struct Fields_var_r3 { s16 field_0; } Fields_var_r3;
    s16 *var_r3;
    if ((arg0 < 0) || (arg0 >= ipv4_address_routing_state.nifaces)) {
        var_r3 = (s16 *)(NULL);
    } else {
        var_r3 = (s16 *)&ipv4_address_routing_state.ifaces[arg0];
        if ((s16) ((Fields_var_r3*)var_r3)->field_0 != 1) {
            var_r3 = (s16 *)(NULL);
        }
    }
    if (var_r3 != NULL) {
        return 1;
    }
    return 0;
}
#pragma pop

#pragma push
#pragma opt_common_subs on
s16 *get_active_entry_by_index(s16 arg0) {
    s16 *temp_r3;
    if ((arg0 < 0) || (arg0 >= ipv4_address_routing_state.nifaces)) {
        return NULL;
    }
    temp_r3 = (s16 *)&ipv4_address_routing_state.ifaces[arg0];
    if ((s16) *temp_r3 != 1) {
        return NULL;
    }
    return temp_r3;
}
#pragma pop

s32 TLobby__sub_8040FEE4(s32 arg0, s32 arg1) {
    s32 temp_r0;
    temp_r0 = arg0 - arg1;
    if (temp_r0 < 0) {
        return -1;
    }
    if (temp_r0 > 0) {
        return 1;
    }
    return 0;
}

Ipv4RoutingState ipv4_address_routing_state;
