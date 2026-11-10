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
typedef struct Arg_804162A4 Arg_804162A4;
typedef struct Ent_80416678 Ent_80416678;
typedef struct Hdr_804177A0 Hdr_804177A0;
typedef struct Arg_80417D1C Arg_80417D1C;
typedef struct Arg_80417E60 Arg_80417E60;
typedef struct Stack_80416008 Stack_80416008;
typedef struct Na_804179A4 Na_804179A4;
typedef struct Arg2_80415B38 Arg2_80415B38;
typedef struct Msg_80416994 Msg_80416994;
typedef struct Item_80416994 Item_80416994;
typedef struct Pkt_80416994 Pkt_80416994;
typedef struct Arg_80416994 Arg_80416994;
typedef struct Arg3_80417494 Arg3_80417494;
s32 compare_sockaddr(void *self, u8 *arg1);
s32 init_packet_fragment_pools(void);
void release_entry(void *self);

struct Self_803FD85C;

#include <stddef.h>
struct Stack_80416008 {
    s32 sp10;
    u8 pad_14[0xC];
    s32 sp20;
    u8 trailing_storage[0x14];
};

#include "pso/network/IPv6Send.h"
#include "pso/network/NetStackTypes.h"

typedef struct Na_804179A4 { u8 type; u8 code; s16 cksum; u8 flags; u8 rsv[3]; u8 target[16]; } Na_804179A4;

u16 TLobby__sub_8040D8F0(u8 *arg0, u8 *arg1, s8 arg2, u8 *arg3, s16 arg4);

s16 TLobby__sub_80413D78(); /* declared without a parameter list; the definition is s16 (self, idx) */
s16 TLobby__sub_80413F0C(); /* declared without a parameter list; the definition is s16 (self, id) */
s16 NetIPv6HandleNeighborSolicitation(u8 *arg0, void *arg1, void *arg2, void *arg3);

struct N_80405298;

struct Self_803FDA68;

struct V_803FE600;

u16 TUdpSocket__sub_80419864(); /* declared without a parameter list; the definition is u16 (p, n) */

s32 NetUnregisterTimer(void* p);

s32 TLobby__sub_80409CE0(s16 arg0, s32 arg1, s32 arg2, s32 arg3);

s32 TLobby__sub_80409D7C(s16 arg0, s32 arg1, s32 arg2, s32 arg3);

s32 TLobby__sub_80409E18(s16 arg0, s32 arg1, s32 arg2);

s32 TLobby__sub_80409EB0(s16 arg0, s32 arg1);

s32 TLobby__sub_8040A0C0(s16 idx, void *a);

/* Inline the helpers below; this applies to the rest of the file. */
#pragma dont_inline off
#pragma inline_depth(4)

s32 TUdpSocket__sub_8040CE58(u8 *p, u8 *b, s16 x, s16 id);

s16 NetIPv6HandleRouterSolicitation(u8 *o, s32 arg1, s32 arg2, s32 arg3);
s16 NetIPv6HandleRouterAdvertisement(u8 *arg0, u8 *arg1, s32 arg2, void *arg3);
s16 NetIPv6HandleNeighborAdvertisement(u8 *arg0, void *arg1, void *arg2, s16 arg3);
s16 NetIPv6HandleRedirect(u8 *arg0, u8 *arg1, void *arg2, s32 arg3);
extern s32 TLobby__sub_80411DEC(IPv6Address *addr, s32 mtu);

s16 TLobby__sub_8040D510(void *a, u8 *src, s16 c, s16 flag);

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

inline void remove_80411604(Ipv6State *g, s16 len, void *grp, void *src) {
    s16 n = g->route_count;
    Ipv6Route *e = g->routes;
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
  void TLobby__sub_80414B98(u8 *, s16, u8 *);
  u8 *new_var;
  s16 TLobby__sub_80412618(void *, s16);
  u8 *k;
  void *h;
  s16 len;
  s16 i;
  Ipv6State *g = &ipv6_address_routing_state;
  u8 *ent;
  s16 t;
  u8 *e;
  u8 *p = (u8 *) pp;
  u8 a92[16];
  u8 padm[8];
  u8 a68[16];
  u8 a52[16];
  u8 a36[16];
  u8 a20[16];
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
      TLobby__sub_80412618(p, id);
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
      TLobby__sub_8041347C(a92, 0, *((u8 **) p), id, 2, 4);
    }
      break;

    case 6:
      if (t == 1)
    {
      NetMemset(a92, 0, 16);
      k = *((u8 **) p);
      TLobby__sub_80414B98(a68, 0, a92);
      remove_80411604(g, 0, a68, k);
    }
      break;

    case 7:
      if (t == 1)
    {
      NetMemset(a92, 0, 16);
      k = *((u8 **) p);
      TLobby__sub_80414B98(a52, 0, a92);
      remove_80411604(g, 0, a52, k);
      TLobby__sub_8041347C(a92, 0, *((u8 **) (p + 4)), id, 2, 4);
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
      k = *((u8 **) p);
      TLobby__sub_80414B98(a36, 0, a92);
      remove_80411604(g, 0, a36, k);
    }
      break;

    case 10:
      if (t == 1)
    {
      new_var = *((u8 **) p);
      len = *((s16 *) (p + 4));
      k = *((u8 **) (p + 8));
      TLobby__sub_80414B98(a20, len, new_var);
      remove_80411604(g, len, a20, k);
      TLobby__sub_8041347C(*((u8 **) p), 128, *((u8 **) (p + 12)), id, 3, 4);
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

void TLobby__sub_80414B98(u8* dst, s16 bits, u8* src);

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

inline void remove_80412618(Ipv6State *g, s16 len, void *grp, void *src) {
    s16 n = g->route_count;
    Ipv6Route *e = g->routes;
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
  s16 NetCompareBitPrefix(void *, void *); /* declared with 2 parameters, so calls here pass 2 arguments; the definition is s32 (u8 *, u8 *, s16) */
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
  u8 pad4[4];
  u8 a32[16];
  u8 a16[16];
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
    cur = *((u8 **) (e + offsetof(Ipv6Iface, addrs)));
    found = 0;
    i = 0;
    for (; (cur != 0) && (i < ((s16 *) g)[2]); cur = *((u8 **) (cur + offsetof(Ipv6AddrNode, next))), i++)
    {
      if ((*((s16 *) (cur + offsetof(Ipv6AddrNode, f16)))) == 0)
      {
        if (cmp16_80412618(tmp, cur + offsetof(Ipv6AddrNode, addr)) == 0)
        {
          found = 1;
        }
      }
      else
        if ((*((s16 *) (pi + 4))) == (*((s16 *) (cur + offsetof(Ipv6AddrNode, prefix_len)))))
      {
        if (NetCompareBitPrefix(*((void **) pi), cur + offsetof(Ipv6AddrNode, addr)) == 0)
        {
          found = 1;
          v = *((u32 *) (pi + 12));
          if ((v > 7200) || (v > (*((u32 *) (cur + offsetof(Ipv6AddrNode, valid_lifetime))))))
          {
            *((u32 *) (cur + offsetof(Ipv6AddrNode, valid_lifetime))) = v;
            *((u32 *) (cur + offsetof(Ipv6AddrNode, preferred_lifetime))) = *((u32 *) (pi + 8));
          }
          else
            if (((*((u32 *) (cur + offsetof(Ipv6AddrNode, valid_lifetime)))) > 7200) || (v > (*((u32 *) (cur + offsetof(Ipv6AddrNode, valid_lifetime))))))
          {
            *((u32 *) (cur + offsetof(Ipv6AddrNode, valid_lifetime))) = 7200;
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
  TLobby__sub_80414B98(a32, n8, tmp);
  remove_80412618(g, n8, a32, tmp);
  L348:
  if (is_socket_flag_set(idx) == 0)
  {
    TLobby__sub_80414B98(a16, 128, tmp);
    remove_80412618(g, 128, a16, a68);
  }

  L400:
  TLobby__sub_80409D7C(idx, *((s16 *) (e + offsetof(Ipv6Iface, handle))), 2, tmp);

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

s32 TLobby__sub_8041509C(void) {
    u8 unused[8];
    clear_table_entry_locked(network_loopback_state.handler);
    network_loopback_state.handler = -1;
    TLobby__sub_803F8B78(&network_loopback_state);
    network_loopback_state.slot_count = 0;
    return 0;
}

void TLobby__sub_804150EC(void) {
    TLobby__sub_8041510C();
}

extern s32 TLobby__sub_80415410(s16 id, u32 addr);
s32 TLobby__sub_80415320(s32 id, s32 unused, u8 *arr);
s32 TLobby__sub_80415230(s16 idx, s16 mode, u8 *addr, void *pkt);
s16 TLobby__sub_8041510C(void)
{
    s16 TLobby__sub_80409A3C(void*, s16); /* declared here with other parameter types; the definition is s16 (u8 *, s16) */
    void* tbl[11];
    u8* base;
    LoopbackState* p;
    s16 r;
    s16 i;
    s16* e;

    base = (u8*)&network_loopback_state;
    p = (LoopbackState*)base;
    tbl[0] = fill_reply_buffer;
    tbl[1] = alloc_conn_slot;
    tbl[2] = clear_conn_slot;
    tbl[3] = get_slot_offset_or_default;
    tbl[4] = TLobby__sub_80415508;
    tbl[5] = TLobby__sub_804154E4;
    tbl[6] = TLobby__sub_804154C0;
    tbl[7] = TLobby__sub_8041549C;
    tbl[8] = TLobby__sub_80415410;
    tbl[9] = TLobby__sub_80415320;
    tbl[10] = TLobby__sub_80415230;

    r = TLobby__sub_80409A3C(tbl, 1);
    if (r < 0) {
        return r;
    }
    init_net_recv_desc((LoopbackState *)base);
    p->handler = r;
    p->protos[0].used = 0;
    p->protos[0].type = 0;
    p->protos[1].used = 0;
    p->protos[1].type = 0;
    e = p->slot_used;
    i = 0;
    while (i < p->slot_count) {
        *e = 0;
        i++;
        e++;
    }
    return r;
}

#pragma push
#pragma opt_common_subs on
s32 TLobby__sub_80415230(s16 idx, s16 mode, u8 *addr, void *pkt) {
    LoopbackState *g = &network_loopback_state;
    u8 *slot;
    s16 len;
    s16 i;
    s16 *used;

    if (idx != 0 && idx != 1) {
        return -0x110;
    }
    len = TLobby__sub_804098B4(pkt);
    if (g->slot_size < len) {
        return -0x110;
    }
    used = g->slot_used;
    slot = g->slots;
    for (i = 0; i < g->slot_count; i++, used++) {
        if (*used == 0) {
            *used = 1;
            TLobby__sub_80409908(slot, pkt);
            TLobby__sub_80409818((s32)slot, len, g->handler, idx, g->protos[idx].type);
            return 0;
        }
        slot += g->slot_size;
    }
    return -0x110;
}
#pragma pop

s32 TLobby__sub_80415320(id, unused, arr)
    s16 id;
    s32 unused;
    u8 *arr;
{
    s32 TLobby__sub_804098B4(void *); /* declared s32 here; the definition returns s16 */
    s32 TLobby__sub_80409908(s32, void *); /* declared here with other parameter types; the definition is s32 (void *, void *) */
    void TLobby__sub_80409818(s32, s32, s16, s16, u16); /* declared here with an s32 2nd argument; the definition takes s16 */
  LoopbackState *p = &network_loopback_state;
  s32 base;
  s32 sum;
  s16 i;
  s16 *cnt;
  s16 sz;
  if (id != 0 && id != 1)
  {
    return -0x110;
  }
  sum = TLobby__sub_804098B4(arr);
  if (p->slot_size < ((s16) sum))
  {
    return -0x110;
  }
  sz = p->slot_size;
  cnt = p->slot_used;
  base = (s32)p->slots;
  for (i = 0; i < p->slot_count; i++, cnt++)
  {
    if ((*cnt) == 0)
    {
      *cnt = 1;
      TLobby__sub_80409908(base, arr);
      TLobby__sub_80409818(base, sum, p->handler, id, p->protos[id].type);
      return 0;
    }
    base += sz;
  }

  return -0x110;
}

extern s32 TLobby__sub_80415410(s16 id, u32 addr) {
  LoopbackState *p = &network_loopback_state;
  s16 size;
  s16 count;
  s16 i;
  s16 *used;
  s16 new_var;
  u32 base;
  if ((id != 0) && (id != 1))
  {
    return -0x110;
  }
  used = p->slot_used;
  i = 0;
  base = (u32)p->slots;
  size = p->slot_size;
  count = p->slot_count;
  for (; i < count; i++, used++)
  {
    if ((((*used) != 0) && (base <= addr)) && (addr < (base + size)))
    {
      *used = 0;
      return 0;
    }
    base += (new_var = size);
  }

  return -0x110;
}

s32 TLobby__sub_8041549C(s16 arg0) {
    if ((arg0 != 0) && (arg0 != 1)) {
        return -0x110;
    }
    return 0;
}

s32 TLobby__sub_804154C0(s16 arg0) {
    if ((arg0 != 0) && (arg0 != 1)) {
        return -0x110;
    }
    return 0;
}

s32 TLobby__sub_804154E4(s16 arg0) {
    if ((arg0 != 0) && (arg0 != 1)) {
        return -0x110;
    }
    return 0;
}

s32 TLobby__sub_80415508(s16 arg0) {
    if ((arg0 != 0) && (arg0 != 1)) {
        return -0x110;
    }
    return 0;
}
s16 get_slot_offset_or_default(s16 arg0) {
    if ((arg0 != 0) && (arg0 != 1)) {
        return -0x110;
    }
    return network_loopback_state.slot_size;
}

s32 clear_conn_slot(s16 i) {
    LoopbackState *g;
    if (i != 0 && i != 1) { return -0x110; }
    g = &network_loopback_state;
    g->protos[i].used = 0;
    g->protos[i].type = 0;
    return 0;
}

s16 alloc_conn_slot(s16 h, s16 v) {
    s16 r;
    LoopbackState *g = &network_loopback_state;
    if (h != g->handler) { return -0x110; }
    if (g->protos[0].used == 0) {
        r = 0;
    } else if (g->protos[1].used == 0) {
        r = 1;
    } else {
        return -0x110;
    }
    g->protos[r].used = 1;
    g->protos[r].type = v;
    return r;
}

s32 fill_reply_buffer(s16 h, u8 *p) {
    if (h != network_loopback_state.handler) { return -0x110; }
    p[0] = 0;
    *++p = 0;
    p[1] = 0;
    p[2] = 0;
    p[3] = 0;
    p[4] = 0;
    p[5] = 0;
    p[6] = 1;
    return 0;
}
s32 reset_net_value(void) {
    TLobby__sub_803F89D8(&network_buffer_pool_state);
    network_buffer_pool_state.count = 0;
    return 0;
}

/* Each entry starts as one free segment over its whole buffer. */
s32 TLobby__sub_80415690(void) {
    NetBufferPool* p;
    s16* step;
    u32 cursor;
    s16 i;
    NetBufferPoolEntry* out;
    s32 tmp;

    init_buffer_desc_a(&network_buffer_pool_state);
    p = &network_buffer_pool_state;
    cursor = (u32)p->data;
    step = &p->size;
    out = p->ents;
    for (i = 0; i < p->count; i++) {
        out->buf = (u8*)cursor;
        tmp = *step;
        cursor += (u16)tmp;
        out->free_segs = 8;
        out->free_bytes = *step;
        out->segs[0].owner = -1;
        out->segs[0].offset = 0;
        out->segs[0].len = (u16)*step;
        out->segs[1].owner = 0;
        out->segs[1].offset = (u16)*step;
        out->segs[1].len = 0;
        out->segs[2].owner = 0;
        out->segs[2].offset = (u16)*step;
        out->segs[2].len = 0;
        out->segs[3].owner = 0;
        out->segs[3].offset = (u16)*step;
        out->segs[3].len = 0;
        out->segs[4].owner = 0;
        out->segs[4].offset = (u16)*step;
        out->segs[4].len = 0;
        out->segs[5].owner = 0;
        out->segs[5].offset = (u16)*step;
        out->segs[5].len = 0;
        out->segs[6].owner = 0;
        out->segs[6].offset = (u16)*step;
        out->segs[6].len = 0;
        out->segs[7].owner = 0;
        out->segs[7].offset = (u16)*step;
        out->segs[7].len = 0;
        out++;
    }
    return 0;
}

s16 TLobby__sub_8041579C(NetBufferRef *self)
{
  s32 pos;
  s16 f;
  u8 *a;
  long long new_var;
  s16 id1;
  u8 *b;
  s16 id2;
  u8 *e;
  s16 m;
  u8 *rec;
  int new_var2;
  u32 word;
  if (self->kind == 4)
  {
    TLobby__sub_803F8D84(self->value);
    return 0;
  }
  word = self->value;
  id1 = (s16) (word >> 24);
  id2 = (s16) ((word >> 16) & 0xff);
  if ((id1 < 0) || (id2 < 0))
  {
    return -1;
  }
  if (id1 > network_buffer_pool_state.count)
  {
    return -1;
  }
  if (id2 > 8)
  {
    return -1;
  }
  rec = (u8 *)network_buffer_pool_state.ents;
  rec += id1 * (s32)sizeof(NetBufferPoolEntry);
  new_var = id2 * (s32)sizeof(NetBufferSegment);
  e = rec + new_var;
  if ((*((s16 *) (e += offsetof(NetBufferPoolEntry, segs)))) == (-1))
  {
    return -1;
  }
  *((s16 *) e) = -1;
  *((s32 *) (rec + offsetof(NetBufferPoolEntry, free_segs))) += 1;
  *((s32 *) (rec + offsetof(NetBufferPoolEntry, free_bytes))) += *((u16 *) ((e = rec + (id2 * (s32)sizeof(NetBufferSegment))) + offsetof(NetBufferPoolEntry, segs[0].len)));
  if ((id2 == 7) || ((*((s16 *) (e + offsetof(NetBufferPoolEntry, segs[1].owner)))) != (-1)))
  {
    pos = (u16) id2;
  }
  else
  {
    pos = id2 + 1;
  }
  pos = (s16) pos;
  new_var2 = pos - 1;
  m = new_var2;
  a = rec + (m * (s32)sizeof(NetBufferSegment));
  b = rec + (pos * (s32)sizeof(NetBufferSegment));
  while ((m >= 0) && ((f = *((s16 *) (a + offsetof(NetBufferPoolEntry, segs[0].owner)))) <= 0))
  {
    if (f == 0)
    {
      *((s16 *) (a + offsetof(NetBufferPoolEntry, segs[0].owner))) = -1;
      *((s16 *) (b + offsetof(NetBufferPoolEntry, segs[0].owner))) = 0;
      *((u16 *) (a + offsetof(NetBufferPoolEntry, segs[0].offset))) = *((u16 *) (b + offsetof(NetBufferPoolEntry, segs[0].offset)));
      *((u16 *) (a + offsetof(NetBufferPoolEntry, segs[0].len))) = *((u16 *) (b + offsetof(NetBufferPoolEntry, segs[0].len)));
      *((u16 *) (b + offsetof(NetBufferPoolEntry, segs[0].offset))) = (*((u16 *) (b + offsetof(NetBufferPoolEntry, segs[0].offset)))) + (*((u16 *) (a + offsetof(NetBufferPoolEntry, segs[0].len))));
      *((u16 *) (b + offsetof(NetBufferPoolEntry, segs[0].len))) = 0;
    }
    else
      if (f == (-1))
    {
      *((s16 *) (b + offsetof(NetBufferPoolEntry, segs[0].owner))) = 0;
      *((u16 *) (a + offsetof(NetBufferPoolEntry, segs[0].len))) = (*((u16 *) (a + offsetof(NetBufferPoolEntry, segs[0].len)))) + (*((u16 *) (b + offsetof(NetBufferPoolEntry, segs[0].len))));
      *((u16 *) (b + offsetof(NetBufferPoolEntry, segs[0].len))) = 0;
      *((u16 *) (b + offsetof(NetBufferPoolEntry, segs[0].offset))) = (*((u16 *) (a + offsetof(NetBufferPoolEntry, segs[0].offset)))) + (*((u16 *) (a + offsetof(NetBufferPoolEntry, segs[0].len))));
    }
    else
    {
      break;
    }
    b = b - (s32)sizeof(NetBufferSegment);
    a = a - (s32)sizeof(NetBufferSegment);
    m--;
  }

  return 0;
}

#pragma push
#pragma opt_common_subs on
/* Allocates size bytes: owner 1 from the transport buffers, else a segment of an entry (at least 0x400 bytes). */
s16 TLobby__sub_80415954(void *out_, int size, s16 owner) {
    NetBufferRef *ref = (NetBufferRef *)out_;
    NetBufferPool *pool;
    NetBufferPoolEntry *e;
    u32 p;
    s16 i;
    s16 j;

    if (owner == 1) {
        p = alloc_buffer_slot(size);
        if (p == 0) {
            return -1;
        }
        ref->kind = 4;
        ref->value = p;
        return 0;
    }
    if (size < 0x400) {
        size = 0x400;
    }
    pool = &network_buffer_pool_state;
    e = pool->ents;
    for (i = 0; i < pool->count; i++, e++) {
        if (e->free_segs == 0 || size > e->free_bytes) {
            continue;
        }
        for (j = 0; j < 8; j++) {
            if (e->segs[j].owner != 0 && e->segs[j].owner == -1 && e->segs[j].len >= (u16)size) {
                ref->value = (i << 24) + (j << 16);
                ref->kind = 2;
                e->segs[j].owner = owner;
                if (j + 1 < 8 && e->segs[j].len - (u16)size != 0 && e->segs[j + 1].owner == 0) {
                    e->segs[j + 1].offset = e->segs[j].offset + size;
                    e->segs[j + 1].len = e->segs[j].len - size;
                    e->segs[j + 1].owner = -1;
                    e->segs[j].len = size;
                }
                e->free_segs--;
                e->free_bytes -= e->segs[j].len;
                return 0;
            }
        }
    }
    return -1;
}
#pragma pop
void NetIPv6ShutdownNeighborDiscovery(void) {
    Ipv6NdState *g = &ipv6_neighbor_discovery_state;
    NetUnregisterTimer((void *)NetIPv6TickNeighborDiscovery);
    TLobby__sub_803F88E0(g);
    g->nneighbors = 0;
    g->nrouters = 0;
}

typedef struct Arg2_80415B38 { u8 *addr; u8 *val; } Arg2_80415B38;
Ipv6NdRouter *NetIPv6SelectDefaultRouter(void *arg0);

s32 NetIPv6InitNeighborDiscovery(void) {
    s16 n;
    u8 *buf;
    Ipv6NdPending *a;
    Ipv6NdRouter *c;
    Ipv6NdNeighbor *b;
    Ipv6NdRouter *r;
    Ipv6NdState *g;
    s16 mtu;
    Arg2_80415B38 a2;
    Arg2_80415B38 a1;

    g = &ipv6_neighbor_discovery_state;
    NetMemset(g, 0, sizeof(Ipv6NdState));
    init_buffer_descriptor_b(g);
    NetIPv6ApplyNeighborDiscoveryDefaults(g);
    n = g->npending;
    a = g->pending;
    buf = g->buffers;
    mtu = g->mtu;
    for (; n > 0; n--) {
        a->tag[0] = 'P';
        a->tag[1] = 'E';
        a->tag[2] = 'N';
        a->data = buf;
        buf += mtu;
        a->used = 0;
        a++;
    }
    n = g->nrouters;
    c = g->routers;
    for (; n > 0; n--) {
        c->tag[0] = 'D';
        c->tag[1] = 'L';
        c->tag[2] = 'E';
        c->used = 0;
        c->uses = 0;
        c++;
    }
    n = g->nneighbors;
    b = g->neighbors;
    for (; n > 0; n--) {
        b->tag[0] = 'N';
        b->tag[1] = 'C';
        b->tag[2] = 'E';
        b->flags = 0;
        b->pending = NULL;
        if (b->pending != NULL) {
            b->pending->used = 0;
            b->pending = NULL;
        }
        if (b->flags & 0x80) {
            r = NetIPv6SelectDefaultRouter(b->addr);
            if (r == NULL) {
                a1.addr = b->addr;
                TLobby__sub_80411604(b->iface, 6, &a1);
            } else {
                a2.val = r->addr;
                a2.addr = b->addr;
                TLobby__sub_80411604(b->iface, 7, &a2);
            }
        }
        b->used = 0;
        b->lladdr_len = 0;
        b++;
    }
    NetRegisterTimer(1000, (s16)(1), (NetTimerCallback)(NetIPv6TickNeighborDiscovery));
    return 0;
}

void NetIPv6TickNeighborDiscovery(void) {
    NetIPv6TickNeighborCache();
    TLobby__sub_8041615C();
}

s16 TLobby__sub_80415D0C(NetPacket *a, u8 *b, NetIPv6SendParameters *c, s16 d) {
    Ipv6NdState *g;
    void *pb[2];
    void *pa[2];
    NetBufferRef cur;
    void *pb2[2];
    void *pa2[2];
    Ipv6NdNeighbor *e;
    s16 ret;
    u8 *src;
    u32 n;
    Ipv6NdPending *q;
    NetPacketFragment *seg;
    s16 NetIPv6SendMulticastNeighborProbe(u8 *arg0); /* declared s16 here; the definition returns s32 */
    Ipv6NdPending *NetIPv6SelectPendingPacketSlot(void); /* declared with no parameters, so calls here pass none; the definition takes (s32, s32, s32, s32, s32, Ipv6NdPending *) */
    Ipv6NdNeighbor *NetIPv6FindOrSelectNeighborCacheEntry(u8 *, int, s16); /* declared with an int second parameter here; the definition takes u8 * */
    g = &ipv6_neighbor_discovery_state;
    if (NetIPv6IsMulticast(b)) {
        return -2;
    }
    e = NetIPv6FindOrSelectNeighborCacheEntry(b, 0, 0);
    if (e == NULL) {
        return -0x10E;
    }
    switch (e->match) {
    case 2:
        switch (e->nud) {
        case 0:
            break;
        case 2:
            e->iface = d;
            e->nud = 3;
            e->timer = g->delay_first_probe;
        case 1:
        case 3:
        case 4:
            return TLobby__sub_80410BA8(a, c, d, e->lladdr);
        }
        break;
    case 0:
    case 1:
    case 3:
        if (e->pending != NULL) {
            e->pending->used = 0;
            e->pending = NULL;
        }
        if (e->flags & 0x80) {
            Ipv6NdRouter *t = NetIPv6SelectDefaultRouter(e->addr);
            if (t == NULL) {
                pa[0] = e->addr;
                TLobby__sub_80411604(e->iface, 6, pa);
            } else {
                pb[1] = (void *)t->addr;
                pb[0] = e->addr;
                TLobby__sub_80411604(e->iface, 7, pb);
            }
        }
        e->used = 0;
        e->lladdr_len = 0;
        e->used = 1;
        e->iface = d;
        NetMemcpy(e->addr, b, 0x10);
        e->nud = 0;
        break;
    default:
        return -0x10E;
    }
    if (e->pending == NULL) {
        e->pending = NetIPv6SelectPendingPacketSlot();
    }
    q = e->pending;
    n = a->fragment_count;
    src = q->data;
    q->len = 0;
    seg = (NetPacketFragment *)a + n; /* &a->fragments[n - 1]: the 12-byte header is one fragment long */
    while (n != 0) {
        s16 l = seg->length;
        q->len += l;
        if (q->len > g->mtu) {
            ret = -0x10E;
            goto done;
        }
        set_value_and_enable(&cur, (s32)src);
        TLobby__sub_80406FD8(&cur, &a->fragments[n - 1].buffer, l);
        src += l;
        seg--;
        n--;
    }
    ret = 0;
done:
    if (ret < 0) {
        if (e->pending != NULL) {
            e->pending->used = 0;
            e->pending = NULL;
        }
        if (e->flags & 0x80) {
            Ipv6NdRouter *t = NetIPv6SelectDefaultRouter(e->addr);
            if (t == NULL) {
                pa2[0] = e->addr;
                TLobby__sub_80411604(e->iface, 6, pa2);
            } else {
                pb2[1] = (void *)t->addr;
                pb2[0] = e->addr;
                TLobby__sub_80411604(e->iface, 7, pb2);
            }
        }
        e->used = 0;
        e->lladdr_len = 0;
        return ret;
    }
    NetMemcpy((u8 *)&e->pending->params, c, 0x28);
    e->timer = g->retrans_ticks;
    e->pending->ttl = e->timer;
    e->probes = 0;
    return NetIPv6SendMulticastNeighborProbe((u8 *)e);
}

s32 NetIPv6SendUnspecifiedSourceNeighborSolicitation(s32 arg0, s16 arg1) {
    typedef struct Fields_temp_r3 { u8 pad_0[4]; s32 field_4; s32 field_8; } Fields_temp_r3;
    typedef char sp10_offset[(offsetof(Stack_80416008, sp10) == 0x0) ? 1 : -1];
    typedef char sp20_offset[(offsetof(Stack_80416008, sp20) == 0x10) ? 1 : -1];
    Stack_80416008 stack;
    s32 temp_r31;
    u8 *free_entry;
    s32 NetIPv6EmitNeighborSolicitation(int, void *, void *, s16, int);
    if (TLobby__sub_80413D78() != 0) {
        return -0x10E;
    }
    free_entry = (u8 *)(alloc_free_entry());
    if (free_entry == NULL) {
        return -0x10E;
    }
    ((Fields_temp_r3*)free_entry)->field_4 = 0;
    ((Fields_temp_r3*)free_entry)->field_8 = 0;
    NetMemset((void *) (&stack.sp10), 0, 0x10);
    NetIPv6MakeSolicitedNodeMulticastAddress((u8 *)((void *) (&stack.sp20)), (u8 *)(arg0));
    temp_r31 = NetIPv6EmitNeighborSolicitation((int)free_entry, (void *)arg0, (void *) (&stack.sp10), arg1, 0);
    release_entry((void *)free_entry);
    return temp_r31;
}

s32 NetIPv6SendRouterSolicitation(s32 arg0) {
    u8 address[0x1C];
    u8 addr[0x10];
    s32 temp_r31;
    u8 *free_entry;
    s16 TLobby__sub_804145D4(void *, void *); /* declared here with other parameter types; the definition is s16 (void *, s16) */

    free_entry = (u8 *)(alloc_free_entry());
    if (free_entry == NULL) {
        return -0x10E;
    }
    *(s32 *)((s8 *)free_entry + 4) = 0;
    *(s32 *)((s8 *)free_entry + 8) = 0;
    init_ipv6_all_routers_multicast_address((u8 *)(address), (s8)(2));
    if (TLobby__sub_804145D4((void *)addr, (void *)arg0) < 0) {
        NetMemset(addr, 0, 0x10);
    }
    temp_r31 = NetIPv6EmitRouterSolicitation((NetPacket *)(free_entry), (NetIPv6SendParameters *)(addr), (s32)(arg0));
    release_entry((void *)free_entry);
    return temp_r31;
}

inline u8 *find_nbr_8041615C(Ipv6NdState *g, u8 *addr) {
    s16 n = g->nneighbors;
    Ipv6NdNeighbor *nb = g->neighbors;
    for (; n > 0; n--, nb++) {
        if (nb->used == 1 && NetMemcmp(nb->addr, addr, 0x10) == 0) {
            return (u8 *)nb;
        }
    }
    return NULL;
}
extern void TLobby__sub_8041615C(void) {
    Ipv6NdState *g = &ipv6_neighbor_discovery_state;
    Ipv6NdNeighbor *nb;
    s16 n;
    Ipv6NdRouter *r;
    Ipv6NdRouter *alive = NULL;
    Ipv6NdRouter *expired = NULL;
    Arg2_80415B38 a6;
    Arg2_80415B38 a7;

    n = g->nrouters;
    r = g->routers;
    for (; n > 0; n--, r++) {
        if (r->used == 1) {
            if (r->lifetime > 1) {
                r->lifetime--;
                alive = r;
            } else {
                r->used = 0;
                expired = r;
                r->uses = 0;
            }
        }
    }
    if (expired == NULL) {
        return;
    }
    nb = (Ipv6NdNeighbor *)find_nbr_8041615C(g, expired->addr);
    if (nb != NULL) {
        nb->flags &= ~0x80;
    }
    if (alive != NULL) {
        a7.addr = expired->addr;
        a7.val = alive->addr;
        TLobby__sub_80411604(alive->iface, 7, &a7);
    } else {
        a6.addr = expired->addr;
        TLobby__sub_80411604(expired->iface, 6, &a6);
    }
}
struct Arg_804162A4 { u8 *p; s32 v; };
s32 NetIPv6SendMulticastNeighborProbe(u8 *arg0);
s32 NetIPv6SendUnicastNeighborProbe(u8 *arg0);

void NetIPv6TickNeighborCache(void) {
    Arg_804162A4 a7;
    Arg_804162A4 a6;
    Arg_804162A4 a7b;
    Arg_804162A4 a6b;
    Ipv6NdState *g = &ipv6_neighbor_discovery_state;
    s16 n;
    Ipv6NdNeighbor *e;
    Ipv6NdRouter *r;

    n = g->nneighbors;
    e = g->neighbors;
    while (n > 0) {
        if (e->used == 1) {
            if (e->timer > 1) {
                e->timer--;
                if (e->pending != NULL) {
                    e->pending->ttl--;
                }
            } else {
                switch (e->nud) {
                case 0:
                    if (++e->probes < g->max_multicast_solicit) {
                        NetIPv6SendMulticastNeighborProbe((u8 *)e);
                        e->timer = g->retrans_timer;
                    } else {
                        if (e->pending != NULL) {
                            e->pending->used = 0;
                            e->pending = NULL;
                        }
                        if (e->flags & 0x80) {
                            r = NetIPv6SelectDefaultRouter(e->addr);
                            if (r == NULL) {
                                a6.p = e->addr;
                                TLobby__sub_80411604(e->iface, 6, &a6);
                            } else {
                                a7.v = (s32)r->addr;
                                a7.p = e->addr;
                                TLobby__sub_80411604(e->iface, 7, &a7);
                            }
                        }
                        e->used = 0;
                        e->lladdr_len = 0;
                    }
                    break;
                case 1:
                    e->nud = 2;
                    e->timer = g->stale_time;
                    break;
                case 2:
                    e->timer = 0;
                    break;
                case 3:
                    NetIPv6SendUnicastNeighborProbe((u8 *)e);
                    e->nud = 4;
                    e->timer = g->retrans_timer;
                    e->probes = 0;
                    break;
                case 4:
                    if (++e->probes < g->max_unicast_solicit) {
                        NetIPv6SendUnicastNeighborProbe((u8 *)e);
                        e->timer = g->retrans_timer;
                    } else {
                        if (e->pending != NULL) {
                            e->pending->used = 0;
                            e->pending = NULL;
                        }
                        if (e->flags & 0x80) {
                            r = NetIPv6SelectDefaultRouter(e->addr);
                            if (r == NULL) {
                                a6b.p = e->addr;
                                TLobby__sub_80411604(e->iface, 6, &a6b);
                            } else {
                                a7b.v = (s32)r->addr;
                                a7b.p = e->addr;
                                TLobby__sub_80411604(e->iface, 7, &a7b);
                            }
                        }
                        e->used = 0;
                        e->lladdr_len = 0;
                    }
                    break;
                }
            }
        }
        n--;
        e++;
    }
}

#pragma push
#pragma opt_propagation off
s16 NetIPv6HandleRedirect(u8 *arg0, u8 *arg1, void *arg2, s32 arg3) {
    u8 ref[8];
    struct { u8 hdr[8]; u8 target[0x10]; u8 dest[0x10]; } msg;
    u8 opts[0x38];
    s16 optlen;
    struct { u8 *p; s16 h; u8 *a; u8 *b; } rec;
    Ipv6Route *e;
    u8 *dest;
    u8 *target;
    u32 len;
    u8 *frag;
    s16 r;
    s16 NetIPv6IsLinkLocal(u8 *); /* declared s16 here; the definition returns s32 */
    s16 NetIPv6ParseRedirectOptions(u8 *, s32, u8 *, s32, s16 *, s32); /* declared s16 here with an s32 6th argument; the definition takes s16 and returns s32 */

    frag = arg0 + 0x18;
    optlen = 0x38;
    len = *(s16 *)(arg0 + 0x18);
    if (len < 0x28) {
        return -1;
    }
    if (NetIPv6IsLinkLocal(arg1) == 0) {
        return -1;
    }
    set_value_and_enable((void *)ref, (s32)&msg);
    TLobby__sub_80406FD8(ref, frag + 4, 0x28);
    dest = msg.dest;
    if (NetIPv6IsMulticast(dest) != 0) {
        return -1;
    }
    target = msg.target;
    if (NetIPv6IsLinkLocal(target) == 0 && NetMemcmp(target, dest, 0x10) != 0) {
        return -1;
    }
    e = TLobby__sub_80413264(dest, arg1);
    if (e == NULL || NetMemcmp(e->gateway, arg1, 0x10) != 0) {
        return -1;
    }
    len -= 0x28;
    if (len >= 8) {
        TLobby__sub_80406EB8((NetBufferRef *)(frag + 4), 0x28);
        r = NetIPv6ParseRedirectOptions(frag, len, (u8 *)&msg, (s32)opts, &optlen, arg3);
        if (r < 0) {
            return r;
        }
    }
    rec.p = dest;
    rec.h = e->prefix_len;
    rec.a = e->gateway;
    rec.b = target;
    TLobby__sub_80411604(arg3, 0xa, &rec);
    return 0;
}
#pragma pop
struct Ent_80416678 { u8 pad0[0xC]; u8 fC; };
s32 NetIPv6ParseRedirectOptions(u8 *arg0, s32 n, u8 *arg2, s32 arg3, s16 *arg4, s16 arg5) {
    u8 sp20[8];
    u8 *h;
    s16 len;
    Ent_80416678 *e;
    void *TLobby__sub_804182DC(void *, void *, s32, s16); /* declared here with an s32 3rd argument; the definition takes s16 */

    while (n >= 8) {
        h = TLobby__sub_80406F0C(arg0 + 4);
        if (h[1] == 0) {
            return -0x10E;
        }
        len = h[1] * 8;
        n -= len;
        if (n < 0) {
            return -0x10E;
        }
        switch (h[0]) {
        case 1:
        case 3:
        case 5:
        default:
            TLobby__sub_80406EB8((NetBufferRef *)(arg0 + 4), len);
            break;
        case 4:
            *arg4 = (*arg4 < len) ? *arg4 : len;
            set_value_and_enable((void *)sp20, arg3);
            TLobby__sub_80406FD8(sp20, arg0 + 4, *arg4);
            TLobby__sub_80406EB8((NetBufferRef *)(arg0 + 4), len);
            break;
        case 2: {
            u8 *p = h + 2;
            s32 l = len - 2;
            e = TLobby__sub_804182DC(arg2 + 8, p, l, arg5);
            if (e != NULL && NetMemcmp(arg2 + 8, arg2 + 0x18, 0x10) != 0) {
                e->fC |= 0x80;
            }
            TLobby__sub_80406EB8((NetBufferRef *)(arg0 + 4), len);
            break;
        }
        }
    }
    return 0;
}

s16 NetIPv6HandleNeighborAdvertisement(u8 *arg0, void *arg1, void *arg2, s16 arg3) {
    NetBufferRef sp30;
    IPv6NeighborSolicitation sp18;
    u8 *lladdr;
    s16 lladlen;
    u8 *hdr;
    u32 len;
    s16 r;
    s16 NetIPv6FindTargetLinkLayerAddressOption(u8 *o, s32 len, u8 **out, s16 *outlen); /* declared s16 here; the definition returns s32 */
    s16 NetIPv6ApplyNeighborAdvertisement(Msg_80416994 *, u8 *name, s16 len, s32 arg3, s32 arg4, s16 id); /* declared s16 here with an s16 6th argument; the definition takes s32 and returns s32 */
    lladdr = 0;
    lladlen = 0;

    hdr = arg0 + 0x18;
    len = *(s16 *)(arg0 + 0x18);
    if (len < 0x18) {
        return -1;
    }
    set_value_and_enable((void *)((u8 *)&sp30), (s32)&sp18);
    TLobby__sub_80406FD8(&sp30, hdr + 4, 0x18);
    if ((s16)NetIPv6IsMulticast(sp18.target.bytes)) {
        return -1;
    }
    len -= 0x18;
    if (len >= 8) {
        TLobby__sub_80406EB8((NetBufferRef *)(hdr + 4), 24);
        r = NetIPv6FindTargetLinkLayerAddressOption(hdr, len, &lladdr, &lladlen);
        if (r < 0) {
            return r;
        }
    }
    if ((s16)NetIPv6IsMulticast((u8 *)arg2)) {
        if ((*((u8 *)&sp18 + 4) & 0x40) || lladlen == 0) {
            return -1;
        }
    }
    return NetIPv6ApplyNeighborAdvertisement((struct Msg_80416994 *)&sp18, lladdr, lladlen, (s32)arg1, (s32)arg2, arg3);
}

s32 NetIPv6FindTargetLinkLayerAddressOption(u8 *o, s32 len, u8 **out, s16 *outlen) {
    u8 *p;
    s16 sz;

    while (len >= 8) {
        p = TLobby__sub_80406F0C(o + 4);
        if (p[1] == 0) {
            return -0x10E;
        }
        sz = p[1] << 3;
        len -= sz;
        if (len < 0) {
            return -0x10E;
        }
        if ((s32)p[0] != 2) {
            TLobby__sub_80406EB8((NetBufferRef *)(o + 4), sz);
        } else {
            *out = p + 2;
            *outlen = sz - 2;
            TLobby__sub_80406EB8((NetBufferRef *)(o + 4), sz);
        }
    }
    return 0;
}

struct Msg_80416994 { u8 pad0[4]; u8 flags; u8 pad5[3]; u8 name[0x10]; };
struct Item_80416994 { s16 port; u8 pad2[2]; u8 val[8]; };
struct Pkt_80416994 { u8 pad0[4]; s32 n; s32 port; Item_80416994 items[1]; };
struct Arg_80416994 { u8 *p; s32 v; };

s16 TLobby__sub_80413C0C(void *, s32);
s16 TLobby__sub_80413AA0(void *, s32);

inline Ipv6NdNeighbor *FindEnt_80416994(Ipv6NdState *g, void *name) {
    s16 n = g->nneighbors;
    Ipv6NdNeighbor *e = g->neighbors;
    for (; n > 0; n--, e++) {
        if (e->used == 1 && NetMemcmp(e->addr, name, 0x10) == 0) {
            return e;
        }
    }
    return 0;
}

inline void ClearPeer_80416994(Ipv6NdRouter *p) {
    p->used = 0;
    p->uses = 0;
}

inline Ipv6NdRouter *ScanPeers_80416994(Ipv6NdState *g, void *name) {
    s16 m;
    Ipv6NdRouter *p;
    Ipv6NdRouter *hit;
    hit = 0;
    m = g->nrouters;
    p = g->routers;
    for (; m > 0; m--, p++) {
        if (p->used == 1) {
            if (NetMemcmp(p->addr, name, 0x10) == 0) {
                ClearPeer_80416994(p);
            } else {
                hit = p;
            }
        }
    }
    return hit;
}

s32 NetIPv6ApplyNeighborAdvertisement(Msg_80416994 *msg, u8 *name, s16 len, s32 arg3, s32 arg4, s32 id) {
    s32 TLobby__sub_80410BA8(void *, void *, s16, void *); /* declared s32 here; the definition returns s16 */
    Arg_80416994 a;
    Arg_80416994 b;
    Ipv6NdState *g = &ipv6_neighbor_discovery_state;
    Ipv6NdNeighbor *e;

    if (TLobby__sub_80413C0C(msg->name, id) != 0) {
        a.p = msg->name;
        TLobby__sub_80411604(id, 1, &a);
        return 0;
    }
    if (TLobby__sub_80413AA0(msg->name, id) != 0) {
        return 0;
    }
    e = FindEnt_80416994(g, msg->name);
    if (e == 0) {
        return 0;
    }
    if ((e->flags ^ msg->flags) & 0x80) {
        if (len == 0 || name == 0 || (e->lladdr_len == len && NetMemcmp(e->lladdr, name, len) == 0) || (msg->flags & 0x20)) {
            if (msg->flags & 0x80) {
                e->flags |= 0x80;
                a.p = msg->name;
                TLobby__sub_80411604(id, 8, &a);
            } else {
                Ipv6NdRouter *hit;
                e->flags |= ~0x80;
                hit = ScanPeers_80416994(g, msg->name);
                if (hit == 0) {
                    a.p = msg->name;
                    TLobby__sub_80411604(id, 9, &a);
                } else {
                    b.v = (s32)hit->addr;
                    b.p = msg->name;
                    TLobby__sub_80411604(id, 7, &b);
                }
            }
        }
    }
    switch (e->nud) {
    case 0:
        if (len != 0 && name != 0) {
            e->lladdr_len = ((u32)len > 0x20) ? 0x20 : len;
            NetMemcpy(e->lladdr, name, e->lladdr_len);
            if (msg->flags & 0x40) {
                e->nud = 1;
                e->timer = g->reachable_time;
            } else {
                e->nud = 2;
                e->timer = g->stale_time;
            }
            e->flags = msg->flags;
            if (e->pending != 0) {
                Pkt_80416994 *pkt = (Pkt_80416994 *)alloc_free_entry();
                s32 ret;
                if (pkt == 0) {
                    ret = -0x10E;
                } else {
                    pkt->n = 0;
                    pkt->port = e->pending->len;
                    pkt->items[pkt->n].port = e->pending->len;
                    set_value_and_enable((void *)(pkt->items[pkt->n].val), (s32)e->pending->data);
                    pkt->n++;
                    ret = TLobby__sub_80410BA8((u8 *)pkt, &e->pending->params, e->iface, e->lladdr);
                    release_entry((void *)pkt);
                }
                e->pending->used = 0;
                e->pending = 0;
                return ret;
            }
        }
        break;
    case 1:
        if (len != 0 && name != 0 && (e->lladdr_len != len || NetMemcmp(e->lladdr, name, len) != 0)) {
            if (msg->flags & 0x20) {
                e->lladdr_len = ((u32)len > 0x20) ? 0x20 : len;
                NetMemcpy(e->lladdr, name, e->lladdr_len);
                e->flags = msg->flags;
                if (msg->flags & 0x40) {
                    e->nud = 1;
                    e->timer = g->reachable_time;
                    break;
                }
            }
            e->nud = 2;
            e->timer = g->stale_time;
        }
        break;
    case 2:
    case 3:
    case 4:
        if (len != 0 && name != 0 && (e->lladdr_len != len || NetMemcmp(e->lladdr, name, len) != 0)) {
            if (msg->flags & 0x20) {
                e->lladdr_len = ((u32)len > 0x20) ? 0x20 : len;
                NetMemcpy(e->lladdr, name, e->lladdr_len);
                if (msg->flags & 0x40) {
                    e->nud = 1;
                    e->timer = g->reachable_time;
                } else {
                    e->nud = 2;
                    e->timer = g->stale_time;
                }
                e->flags = msg->flags;
            }
        } else if (msg->flags & 0x40) {
            e->nud = 1;
            e->timer = g->reachable_time;
            e->flags = msg->flags;
        }
        break;
    }
    return 0;
}

struct Arg3_80417494 { u8 *p; u8 v; };

inline Ipv6NdRouter *FindPeer2_80417494(s16 *cnt, Ipv6NdRouter **list, void *name) {
    s16 n = *cnt;
    Ipv6NdRouter *p = *list;
    for (; n > 0; n--, p++) {
        if (p->used == 1 && NetMemcmp(p->addr, name, 0x10) == 0) {
            return p;
        }
    }
    return 0;
}

inline Ipv6NdRouter *ScanPeers2_80417494(s16 *cnt, Ipv6NdRouter **list, void *name) {
    s16 m;
    Ipv6NdRouter *p;
    Ipv6NdRouter *hit;
    hit = 0;
    m = *cnt;
    p = *list;
    for (; m > 0; m--, p++) {
        if (p->used == 1) {
            if (NetMemcmp(p->addr, name, 0x10) == 0) {
                p->used = 0;
                p->uses = 0;
            } else {
                hit = p;
            }
        }
    }
    return hit;
}

s16 TLobby__sub_80417294(u8 *self, s32 n, u8 *dst, void *id);
s16 TLobby__sub_80417494(void *, u8 *, s16);

s16 NetIPv6HandleNeighborSolicitation(u8 *arg0, void *arg1, void *arg2, void *arg3) {
    NetBufferRef sp30;
    IPv6NeighborSolicitation sp18;
    u8 *hdr;
    u32 len;
    s16 r;
    hdr = arg0 + 0x18;
    len = *(s16 *)(arg0 + 0x18);
    if (len < 0x18) {
        return -1;
    }
    if ((s16)NetIPv6IsUnspecified((u8 *)arg1) && TLobby__sub_80413F0C(arg2, arg3) == 0) {
        return -1;
    }
    set_value_and_enable((void *)((u8 *)&sp30), (s32)&sp18);
    TLobby__sub_80406FD8(&sp30, hdr + 4, 0x18);
    if ((s16)NetIPv6IsMulticast(sp18.target.bytes)) {
        return -1;
    }
    len -= 0x18;
    if (len >= 8) {
        TLobby__sub_80406EB8((NetBufferRef *)(hdr + 4), 24);
        r = TLobby__sub_80416F58(hdr, len, arg1, arg3);
        if (r < 0) {
            return r;
        }
    }
    return TLobby__sub_80417028(&sp18, arg1, arg2, arg3);
}

extern s16 TLobby__sub_80416F58(u8 *self, s32 n, void *out, void *arg_)
{
  void *TLobby__sub_804182DC(void *, void *, s16, s32); /* declared here with an s32 4th argument; the definition takes s16 */
  u8 *p;
  s16 step;
  short new_var;
  u8 *q;
  while (n >= 8)
  {
    p = TLobby__sub_80406F0C(self + 4);
    if (p[1] == 0)
    {
      return -0x10E;
    }
    step = (s16) (p[1] << 3);
    if ((n -= step) < 0)
    {
      return -0x10E;
    }
    if (((s32) p[0]) != 1)
    {
      TLobby__sub_80406EB8((NetBufferRef *)(self + 4), step);
      continue;
    }
    if (NetIPv6IsUnspecified(out))
    {
      return -0x10E;
    }
    q = p + 2;
    TLobby__sub_804182DC(out, q, new_var = step - 2, (s32)arg_);
    TLobby__sub_80406EB8((NetBufferRef *)(self + 4), step);
  }

  return 0;
}

s16 TLobby__sub_80417028(void *self, void *a, void *b, void *d) {
    u8 opt[0x28];
    s32 pad2[2];
    u8 buf30[16];
    u8 buf20[16];
    s32 pad;
    u8 *local;
    u8 *p;
    u8 *ent;
    s32 flags;
    s16 n;
    s16 len;
    s16 r;
    s16 NetIPv6GetInterfaceLinkLayerAddress(s32, s32, s32); /* declared here with other parameter types; the definition is s16 (s32, s16, s16) */
    s16 NetIPv6SendNeighborAdvertisement(u8 *, void *, s32, u8 *, s32); /* declared here with other parameter types; the definition is s16 (NetPacket *, u8 *, u8, NetIPv6SendParameters *, s16) */

    flags = 0;
    if (TLobby__sub_80413C0C((u8 *)self + offsetof(IPv6NeighborSolicitation, target), (int)d)) {
        local = (u8 *)self + offsetof(IPv6NeighborSolicitation, target);
        TLobby__sub_80411604((int)d, 1, &local);
        return 0;
    }
    if (!TLobby__sub_80413AA0((u8 *)self + offsetof(IPv6NeighborSolicitation, target), (int)d)) {
        return 0;
    }
    NetMemcpy(buf20, (u8 *)self + offsetof(IPv6NeighborSolicitation, target), 0x10);
    p = alloc_free_entry();
    if (p == NULL) {
        return -0x10e;
    }
    *(s32 *)(p + offsetof(NetPacket, fragment_count)) = 0;
    *(s32 *)(p + offsetof(NetPacket, total_bytes)) = 0;
    if (NetIPv6IsUnspecified(a)) {
        init_ipv6_all_nodes_multicast_address(buf30, 2);
    } else {
        NetMemcpy(buf30, a, 0x10);
    }
    if (NetIPv6IsMulticast(b)) {
        n = NetIPv6GetInterfaceLinkLayerAddress((s32)(opt + 2), 0x20, (s32)d);
        if (n > 0) {
            len = n + 2;
            opt[0] = 2;
            opt[1] = len >> 3;
            *(s32 *)(p + offsetof(NetPacket, total_bytes)) += len;
            ent = p;
            ent += *(s32 *)(p + offsetof(NetPacket, fragment_count)) * (s32)sizeof(NetPacketFragment);
            *(s16 *)(ent + offsetof(NetPacket, fragments[0].length)) = n + 2;
            set_value_and_enable(p + *(s32 *)(p + offsetof(NetPacket, fragment_count)) * (s32)sizeof(NetPacketFragment) + offsetof(NetPacket, fragments[0].buffer), (s32)opt);
            flags |= 0x20;
            *(s32 *)(p + offsetof(NetPacket, fragment_count)) += 1;
        }
    }
    r = NetIPv6SendNeighborAdvertisement((u8 *)p, (u8 *)self + offsetof(IPv6NeighborSolicitation, target), flags, buf20, (s32)d);
    release_entry(p);
    return r;
}

s16 NetIPv6HandleRouterAdvertisement(u8 *arg0, u8 *arg1, s32 arg2, void *arg3) {
    u8 sp28[8];
    u8 sp18[16];
    u32 n;
    u8 *p;
    s16 r;
    s16 NetIPv6IsLinkLocal(u8 *arg0); /* declared s16 here; the definition returns s32 */
    s16 TLobby__sub_80417494(void *, u8 *, void *); /* declared here with other parameter types; the definition is s16 (void *, u8 *, s16) */

    p = arg0 + offsetof(NetPacket, fragments[1]);
    n = *(s16 *)(arg0 + offsetof(NetPacket, fragments[1].length));
    if (n < 0x10U) {
        return -1;
    }
    r = NetIPv6IsLinkLocal(arg1);
    if (r == 0) {
        return -1;
    }
    set_value_and_enable((void *)sp28, (s32)sp18);
    TLobby__sub_80406FD8(sp28, p + offsetof(NetPacketFragment, buffer), 0x10);
    n -= 0x10;
    if (n >= 8U) {
        TLobby__sub_80406EB8((NetBufferRef *)(p + offsetof(NetPacketFragment, buffer)), 0x10);
        r = TLobby__sub_80417294(p, n, arg1, arg3);
        if (r < 0) {
            return r;
        }
    }
    return TLobby__sub_80417494(sp18, arg1, arg3);
}

#pragma push
#pragma opt_dead_assignments off
#pragma opt_loop_invariants off
extern s16 TLobby__sub_80417294(u8 *self, s32 n, u8 *dst, void *id)
{
  void *TLobby__sub_804182DC(void *, void *, s16, void *); /* declared here with other parameter types; the definition is void * (void *, void *, s16, s16) */
  u8 buf58[8];
  u8 *new_var3;
  u8 buf38[32];
  struct 
  {
    u8 *q;
    s16 a;
    s32 b;
    s32 c;
  } buf28;
  s32 buf20[2];
  s32 buf18[2];
  long long new_var;
  u8 *payload = (void *) 0;
  s16 len;
  u8 *new_var2;
  while (n >= 8)
  {
    u8 *p = TLobby__sub_80406F0C(self + 4);
    if (p[1] == 0)
    {
      return -0x10E;
    }
    len = (s16) (p[1] << 3);
    n -= len;
    if (n < 0)
    {
      do
      {
        return -0x10E;
      }
      while (0);
    }
    switch (p[0])
    {
      default:
        TLobby__sub_80406EB8((NetBufferRef *)(self + 4), len);
        break;

      case 1:
        new_var = len - 2;
        payload = p + 2;
        ((u8 *) TLobby__sub_804182DC(dst, payload, new_var, id))[0xC] |= 0x80;
        TLobby__sub_80406EB8((NetBufferRef *)(self + 4), len);
        break;

      case 3:
        if (len == 0x20U)
      {
        set_value_and_enable((void *) buf58, (s32) buf38);
        new_var3 = buf38 + 16;
        TLobby__sub_80406FD8(buf58, self + 4, 0x20);
        buf28.q = (new_var2 = new_var3);
        buf28.a = buf38[2];
        buf28.b = *((s32 *) (buf38 + 8));
        buf28.c = *((s32 *) (buf38 + 4));
        TLobby__sub_80411604((int) id, 2, &buf28);
      }
        TLobby__sub_80406EB8((NetBufferRef *)(self + 4), len);
        break;

      case 5:
        if (len == 8U)
      {
        set_value_and_enable((void *) buf58, (s32) buf20);
        TLobby__sub_80406FD8(buf58, self + 4, 8);
        *((u8 **) buf18) = dst;
        buf18[1] = buf20[1];
        TLobby__sub_80411604((int) id, 4, buf18);
      }
        TLobby__sub_80406EB8((NetBufferRef *)(self + 4), len);
        break;

    }

  }

  if (payload == ((void *) 0))
  {
    Ipv6NdNeighbor *e2 = FindEnt_80416994(&ipv6_neighbor_discovery_state, dst);
    if (e2 != 0)
    {
      e2->flags |= 0x80;
    }
  }
  return 0;
}
#pragma pop
s32 TLobby__sub_80418734(void *addr, NetIcmpv6RouterAdvertisement *ra, s16 iface);
#pragma push
#pragma opt_propagation off
s16 TLobby__sub_80417494(void *buf, u8 *a, s16 c) {
    Ipv6NdState *g = &ipv6_neighbor_discovery_state;
    s16 *pc = &g->nrouters;
    Ipv6NdRouter **pl = &g->routers;
    s16 cc;
    u8 *aa;
    NetIcmpv6RouterAdvertisement *m;
    Ipv6NdRouter *p;
    Ipv6NdNeighbor *e;
    s32 TLobby__sub_80411604(s16, int, void *); /* defined K&R with an s16 id */
    s32 padx[2];
    struct {
        s32 pad[2];
        Arg3_80417494 s3;
        Arg_80416994 s2;
        u8 *s1;
    } loc;

    m = (NetIcmpv6RouterAdvertisement *)buf;
    aa = a;
    cc = c;
    p = FindPeer2_80417494(pc, pl, aa);
    if (p == 0) {
        if (m->router_lifetime != 0) {
            TLobby__sub_80418734(aa, m, cc);
            loc.s1 = aa;
            TLobby__sub_80411604(cc, 5, &loc.s1);
        } else {
            e = FindEnt_80416994(g, aa);
            if (e != 0) {
                e->flags &= ~0x80;
            }
            loc.s1 = aa;
            TLobby__sub_80411604(cc, 6, &loc.s1);
        }
    } else if (m->router_lifetime != 0) {
        loc.s1 = aa;
        TLobby__sub_80411604(cc, 5, &loc.s1);
        p->iface = cc;
        p->lifetime = m->router_lifetime;
        if (m->reachable_time != 0) {
            p->reachable_time = m->reachable_time;
            g->reachable_time = p->reachable_time / 1000;
        }
        if (m->retrans_timer != 0) {
            p->retrans_timer = m->retrans_timer;
            g->retrans_timer = p->retrans_timer / 1000;
            g->retrans_ticks = p->retrans_timer / 1000 + 1;
        }
    } else {
        Ipv6NdRouter *hit;
        e = FindEnt_80416994(g, aa);
        if (e != 0) {
            e->flags &= ~0x80;
        }
        if ((hit = ScanPeers2_80417494(pc, pl, aa)) == 0) {
            loc.s1 = aa;
            TLobby__sub_80411604(cc, 6, &loc.s1);
        } else {
            loc.s2.v = (s32)hit->addr;
            loc.s2.p = aa;
            TLobby__sub_80411604(cc, 7, &loc.s2);
        }
    }
    if (m->cur_hop_limit != 0) {
        loc.s3.p = aa;
        loc.s3.v = m->cur_hop_limit;
        TLobby__sub_80411604(cc, 3, &loc.s3);
    }
    return 0;
}
#pragma pop

struct Hdr_804177A0 {
    s16 len;
    u8 pad[2];
    u8 data[8];
};
s16 TLobby__sub_80417868(void *, u32, s32, s32);
s16 NetIPv6HandleRouterSolicitation(u8 *o, s32 arg1, s32 arg2, s32 arg3) {
    u8 b[8];
    u8 a[8];
    s32 pad;
    s32 v;
    Hdr_804177A0 *h = (Hdr_804177A0 *)(o + 0x18);
    u32 len = h->len;
    s16 r;

    if (len < 8) {
        return -1;
    }
    set_value_and_enable((void *)b, (s32)a);
    TLobby__sub_80406FD8(b, h->data, 8);
    len -= 8;
    if (len >= 8) {
        TLobby__sub_80406EB8((NetBufferRef *)h->data, 8);
        r = TLobby__sub_80417868(h, len, arg1, arg3);
        if (r < 0) {
            return r;
        }
    }
    v = arg1;
    TLobby__sub_80411604(arg3, 0xC, &v);
    return 0;
}

s16 TLobby__sub_80417868(void *arg0, u32 arg1, s32 arg2, s32 arg3)
{
  void *TLobby__sub_804182DC(void *, void *, s16, s32); /* declared here with an s32 4th argument; the definition takes s16 */
  s16 i;
  s32 step;
  u8 *self;
  u8 *q;
  s32 arg_;
  void *out;
  s32 n;
  u8 *p;
  self = (u8 *) arg0;
  n = arg1;
  out = (void *) arg2;
  arg_ = arg3;
  q = (void *) 0;
  while (n >= 8)
  {
    p = TLobby__sub_80406F0C(self + 4);
    if (p[1] == 0)
    {
      return -0x10E;
    }
    step = p[1];
    step <<= 3;
    step = (s16) step;
    if ((n -= step) < 0)
    {
      return -0x10E;
    }
    if (((s32) p[0]) != 1)
    {
      TLobby__sub_80406EB8((NetBufferRef *)(self + 4), step);
      continue;
    }
    if (!NetIPv6IsUnspecified(out))
    {
      s16 t = step - 2;
      q = p + 2;
      TLobby__sub_804182DC(out, q, t, arg_);
    }
    TLobby__sub_80406EB8((NetBufferRef *)(self + 4), step);
  }

  if (q != ((void *) 0))
  {
    i = ipv6_neighbor_discovery_state.nneighbors;
    p = (u8 *) ipv6_neighbor_discovery_state.neighbors;
    for (; i > 0; i--, p += sizeof(Ipv6NdNeighbor))
    {
      if ((((Ipv6NdNeighbor *) p)->used == 1) && (NetMemcmp(((Ipv6NdNeighbor *) p)->addr, out, 0x10) == 0))
      {
        ((Ipv6NdNeighbor *) p)->used += 0;
        goto found;
      }
    }

    p = (void *) 0;
    found:
    if (p != ((void *) 0))
    {
      ((Ipv6NdNeighbor *) p)->flags &= ~0x80;
    }

  }
  return 0;
}

typedef struct Arg_80417D1C { u8 *p; s32 v; } Arg_80417D1C;

#pragma push
#pragma opt_propagation off
#pragma opt_common_subs on
s16 NetIPv6SendNeighborAdvertisement(NetPacket *arg0, u8 *address, u8 arg2, NetIPv6SendParameters *arg3, s16 arg4) {
    Na_804179A4 na;
    NetBufferRef cur;
    Ipv6NdNeighbor *e;
    void *p6;
    void TLobby__sub_80406FD8(void *, void *, int);
    u16 TLobby__sub_80411040(void *, void *, u8, void *, s16); /* declared here with other parameter types; the definition is u16 (const IPv6Address *, const IPv6Address *, u8, const NetPacket *, s16) */
    s16 TLobby__sub_804136AC(s16 arg0); /* declared s16 here; the definition returns s32 */
    s16 TLobby__sub_80413934(void *, s16); /* declared s16 here; the definition is s32 (u8 *, s16) */
    s16 NetIPv6SendMulticastNeighborProbe(u8 *arg0); /* declared s16 here; the definition returns s32 */
    Ipv6NdNeighbor *NetIPv6FindOrSelectNeighborCacheEntry(u8 *, int, s16); /* declared with an int second parameter here; the definition takes u8 * */
    Ipv6NdPending *NetIPv6SelectPendingPacketSlot(void); /* declared with no parameters, so calls here pass none; the definition takes (s32, s32, s32, s32, s32, Ipv6NdPending *) */
    if (NetIPv6IsMulticast(address) != 0) {
        return -0x10E;
    }
    if (NetIPv6IsUnspecified(arg3->source.bytes) != 0) {
        s16 r = TLobby__sub_804145D4(arg3, arg4);
        if (r < 0) {
            return r;
        }
    } else if (TLobby__sub_80413934(arg3, arg4) == 0) {
        return -0x10E;
    }
    arg3->traffic_class_bits = 0;
    arg3->flow_label = 0;
    arg3->next_header = 0x3A;
    arg3->hop_limit = 0xFF;
    arg0->total_bytes += 0x18;
    arg0->fragments[arg0->fragment_count].length = 0x18;
    set_value_and_enable(&arg0->fragments[arg0->fragment_count].buffer, (s32)&na);
    arg0->fragment_count++;
    na.type = 0x88;
    na.code = 0;
    na.flags = arg2;
    NetMemset(na.rsv, 0, 3);
    NetMemcpy(na.target, address, 0x10);
    if (NetIPv6IsMulticast(arg3->destination.bytes) != 0 || TLobby__sub_804136AC(arg4) == 0) {
        na.flags |= 0xFFBF;
        na.cksum = 0;
        na.cksum = TLobby__sub_80411040(arg3, arg3->destination.bytes, arg3->next_header, arg0, 1);
        p6 = NULL;
    } else {
        e = NetIPv6FindOrSelectNeighborCacheEntry(arg3->destination.bytes, 0, 0);
        if (e == NULL) {
            return -0x10E;
        }
        na.flags |= 0x40;
        na.cksum = 0;
        na.cksum = TLobby__sub_80411040(arg3, arg3->destination.bytes, arg3->next_header, arg0, 1);
        switch (e->match) {
        case 1:
            break;
        case 3:
            break;
        case 2:
            p6 = e->lladdr;
            goto tail;
        }
        {
            s16 ret;
            u8 *src;
            u32 n;
            Ipv6NdPending *q;
            void *b[2];
            void *a[2];
            NetPacketFragment *seg;
            e->iface = arg4;
            e->nud = 0;
            e->timer = ipv6_neighbor_discovery_state.retrans_ticks;
            e->probes = 0;
            NetMemcpy(e->addr, arg3->destination.bytes, 0x10);
            if (e->pending == NULL) {
                e->pending = NetIPv6SelectPendingPacketSlot();
            }
            q = e->pending;
            n = arg0->fragment_count;
            src = q->data;
            q->len = 0;
            seg = (NetPacketFragment *)arg0 + n; /* &arg0->fragments[n - 1]: the 12-byte header is one fragment long */
            while (n != 0) {
                s16 l = seg->length;
                q->len += l;
                if (q->len > ipv6_neighbor_discovery_state.mtu) {
                    ret = -0x10E;
                    goto done;
                }
                set_value_and_enable(&cur, (s32)src);
                TLobby__sub_80406FD8(&cur, &arg0->fragments[n - 1].buffer, l);
                src += l;
                seg--;
                n--;
            }
            ret = 0;
done:
            if (ret < 0) {
                if (e->pending != NULL) {
                    e->pending->used = 0;
                    e->pending = NULL;
                }
                if (e->flags & 0x80) {
                    Ipv6NdRouter *t = NetIPv6SelectDefaultRouter(e->addr);
                    if (t == NULL) {
                        a[0] = e->addr;
                        TLobby__sub_80411604(e->iface, 6, a);
                    } else {
                        b[1] = t->addr;
                        b[0] = e->addr;
                        TLobby__sub_80411604(e->iface, 7, b);
                    }
                }
                e->used = 0;
                e->lladdr_len = 0;
                return ret;
            }
            NetMemcpy((u8 *)&e->pending->params, arg3, 0x28);
            return NetIPv6SendMulticastNeighborProbe((u8 *)e);
        }
    }
tail:
    return TLobby__sub_80410BA8(arg0, arg3, arg4, p6);
}
#pragma pop

s32 NetIPv6SendMulticastNeighborProbe(u8 *arg0) {
    u8 sp2C[0x18];
    u8 sp1C[0x10];
    Arg_80417D1C a7;
    Arg_80417D1C a6;
    s32 temp_r31;
    s32 NetIPv6EmitNeighborSolicitation(int, void *, void *, s16, int); /* declared s32 here; the definition returns s16 */
    Ipv6NdRouter *temp_r3_3;
    u8 *free_entry;
    u8 *temp_r3_2;
    u8 *temp_r3_4;

    free_entry = alloc_free_entry();
    if (free_entry == NULL) {
        temp_r3_2 = *(u8 **)((s8 *)arg0 + 0x10);
        if (temp_r3_2 != NULL) {
            *(s8 *)((s8 *)temp_r3_2 + 3) = 0;
            *(u8 **)((s8 *)arg0 + 0x10) = NULL;
        }
        if (*(u8 *)((s8 *)arg0 + 0xC) & 0x80) {
            temp_r3_3 = NetIPv6SelectDefaultRouter(arg0 + 0x16);
            if (temp_r3_3 == NULL) {
                a6.p = arg0 + 0x16;
                TLobby__sub_80411604(*(s16 *)((s8 *)arg0 + 8), 6, &a6);
            } else {
                a7.v = (s32)temp_r3_3->addr;
                a7.p = arg0 + 0x16;
                TLobby__sub_80411604(*(s16 *)((s8 *)arg0 + 8), 7, &a7);
            }
        }
        *(s8 *)((s8 *)arg0 + 3) = 0;
        *(s16 *)((s8 *)arg0 + 0x26) = 0;
        return -0x10E;
    }
    *(s32 *)((s8 *)free_entry + 4) = 0;
    *(s32 *)((s8 *)free_entry + 8) = 0;
    temp_r3_4 = *(u8 **)((s8 *)arg0 + 0x10);
    if (temp_r3_4 != NULL && TLobby__sub_804137FC(temp_r3_4 + 8, *(s16 *)((s8 *)arg0 + 8)) != 0) {
        NetMemcpy(sp1C, *(u8 **)((s8 *)arg0 + 0x10) + 8, 0x10);
    } else {
        TLobby__sub_804145D4(sp1C, *(s16 *)((s8 *)arg0 + 8));
    }
    NetIPv6MakeSolicitedNodeMulticastAddress(sp2C, (u8 *)(arg0 + 0x16));
    temp_r31 = NetIPv6EmitNeighborSolicitation((int)free_entry, arg0 + 0x16, sp1C, *(s16 *)((s8 *)arg0 + 8), 0);
    release_entry((void *)free_entry);
    return temp_r31;
}

typedef struct Arg_80417E60 { u8 *p; s32 v; } Arg_80417E60;

s32 NetIPv6SendUnicastNeighborProbe(u8 *arg0) {
    u8 sp2C[0x18];
    u8 sp1C[0x10];
    Arg_80417E60 a7;
    Arg_80417E60 a6;
    s32 temp_r31;
    s32 NetIPv6EmitNeighborSolicitation(int, void *, void *, s16, int); /* declared s32 here; the definition returns s16 */
    Ipv6NdRouter *temp_r3_3;
    u8 *free_entry;
    u8 *temp_r3_2;
    u8 *temp_r3_4;

    free_entry = alloc_free_entry();
    if (free_entry == NULL) {
        temp_r3_2 = *(u8 **)((s8 *)arg0 + 0x10);
        if (temp_r3_2 != NULL) {
            *(s8 *)((s8 *)temp_r3_2 + 3) = 0;
            *(u8 **)((s8 *)arg0 + 0x10) = NULL;
        }
        if (*(u8 *)((s8 *)arg0 + 0xC) & 0x80) {
            temp_r3_3 = NetIPv6SelectDefaultRouter(arg0 + 0x16);
            if (temp_r3_3 == NULL) {
                a6.p = arg0 + 0x16;
                TLobby__sub_80411604(*(s16 *)((s8 *)arg0 + 8), 6, &a6);
            } else {
                a7.v = (s32)temp_r3_3->addr;
                a7.p = arg0 + 0x16;
                TLobby__sub_80411604(*(s16 *)((s8 *)arg0 + 8), 7, &a7);
            }
        }
        *(s8 *)((s8 *)arg0 + 3) = 0;
        *(s16 *)((s8 *)arg0 + 0x26) = 0;
        return -0x10E;
    }
    *(s32 *)((s8 *)free_entry + 4) = 0;
    *(s32 *)((s8 *)free_entry + 8) = 0;
    temp_r3_4 = *(u8 **)((s8 *)arg0 + 0x10);
    if (temp_r3_4 != NULL && TLobby__sub_804137FC(temp_r3_4 + 8, *(s16 *)((s8 *)arg0 + 8)) != 0) {
        NetMemcpy(sp1C, *(u8 **)((s8 *)arg0 + 0x10) + 8, 0x10);
    } else {
        TLobby__sub_804145D4(sp1C, *(s16 *)((s8 *)arg0 + 8));
    }
    NetMemcpy(sp2C, arg0 + 0x16, 0x10);
    temp_r31 = NetIPv6EmitNeighborSolicitation((int)free_entry, arg0 + 0x16, sp1C, *(s16 *)((s8 *)arg0 + 8), (int)(arg0 + 0x28));
    release_entry((void *)free_entry);
    return temp_r31;
}

s16 NetIPv6EmitNeighborSolicitation(int arg0, void *arg1, void *arg2, s16 arg3, int arg4) {
    s32 d;
    s16 b;
    NetIPv6SendParameters *addr;
    u8 *target;
    NetPacket *net_packet;
    NetIcmpv6NeighborSolicitation message;
    NetSourceLinkLayerOption option;
    s16 temp_r3;
    s16 temp_r5;
    s16 r;
    s16 TLobby__sub_80414090(u8 *, s16); /* declared s16 here; the definition returns s32 */
    net_packet = (NetPacket *)arg0;
    target = (u8 *)arg1;
    addr = (NetIPv6SendParameters *)arg2;
    b = arg3;
    d = arg4;

    if (NetIPv6IsMulticast(target) != 0) {
        return -0x10E;
    }
    if (NetIPv6IsMulticast((u8 *)(&addr->destination)) != 0) {
        d = 0;
    }
    if (NetIPv6IsUnspecified((u8 *)(&addr->source)) == 0) {
        r = TLobby__sub_80414090((u8 *)addr, b);
        if (r < 0) {
            return r;
        }
        temp_r3 = NetIPv6GetInterfaceLinkLayerAddress((s32)(&option.address), 0x20, b);
        if (temp_r3 > 0) {
            temp_r5 = temp_r3 + 2;
            option.type = 1;
            option.length_units = (u8)(temp_r5 >> 3);
            net_packet->total_bytes += temp_r5;
            net_packet->fragments[net_packet->fragment_count].length = temp_r5;
            set_value_and_enable((void *)(&net_packet->fragments[net_packet->fragment_count].buffer), (s32)(&option));
            net_packet->fragment_count += 1;
        }
    }
    addr->traffic_class_bits = 0;
    addr->flow_label = 0;
    addr->next_header = 0x3A;
    addr->hop_limit = 0xFF;
    net_packet->total_bytes += 0x18;
    net_packet->fragments[net_packet->fragment_count].length = 0x18;
    set_value_and_enable((void *)(&net_packet->fragments[net_packet->fragment_count].buffer), (s32)(&message));
    net_packet->fragment_count += 1;
    message.header.type = 0x87;
    message.header.code = 0;
    message.header.reserved = 0;
    NetMemcpy(&message.target, target, 0x10);
    message.header.checksum = 0;
    message.header.checksum = TLobby__sub_80411040(&addr->source, &addr->destination, addr->next_header, net_packet, 1);
    return TLobby__sub_80410BA8(net_packet, addr, b, (void *)d);
}

#pragma push
#pragma optimization_level 3
s32 NetIPv6EmitRouterSolicitation(NetPacket *net_packet, NetIPv6SendParameters *addr, s32 arg2) {
    s32 TLobby__sub_80410BA8(void *, void *, s32, void *);
    NetIcmpv6RouterSolicitation message;
    NetSourceLinkLayerOption option;
    s16 temp_r3;
    s16 temp_r5;
    s16 NetIPv6GetInterfaceLinkLayerAddress(s32, s16, s32);
    if ((NetIPv6IsMulticast((u8 *)(&addr->destination))) == 0) {
        return -0x10E;
    }
    if ((NetIPv6IsUnspecified((u8 *)(&addr->source))) == 0) {
        temp_r3 = NetIPv6GetInterfaceLinkLayerAddress((s32)(&option.address), (s16)(0x20), arg2);
        if (temp_r3 > 0) {
            temp_r5 = temp_r3 + 2;
            option.type = 1;
            option.length_units = (u8) (temp_r5 >> 3);
            net_packet->total_bytes += temp_r5;
            net_packet->fragments[net_packet->fragment_count].length = temp_r5;
            set_value_and_enable((void *)(&net_packet->fragments[net_packet->fragment_count].buffer), (s32)(&option));
            net_packet->fragment_count += 1;
        }
    }
    addr->traffic_class_bits = 0;
    addr->flow_label = 0;
    addr->next_header = 0x3A;
    addr->hop_limit = 0xFF;
    net_packet->total_bytes += 8;
    net_packet->fragments[net_packet->fragment_count].length = 8;
    set_value_and_enable((void *)(&net_packet->fragments[net_packet->fragment_count].buffer), (s32)(&message));
    net_packet->fragment_count += 1;
    message.header.type = 0x85;
    message.header.code = 0;
    message.header.reserved = 0;
    message.header.checksum = 0;
    message.header.checksum = TLobby__sub_80411040((const IPv6Address *)(&addr->source), (const IPv6Address *)(&addr->destination), addr->next_header, (const NetPacket *)(net_packet), (s16)(1));
    return TLobby__sub_80410BA8(net_packet, addr, arg2, NULL);
}
#pragma pop

inline s32 notify_804182DC(Ipv6NdNeighbor *e) {
    NetPacket *nw;
    nw = (NetPacket *)alloc_free_entry();
    if (nw == 0) {
        return (s32)e;
    }
    nw->fragment_count = 0;
    nw->total_bytes = e->pending->len;
    nw->fragments[nw->fragment_count].length = e->pending->len;
    set_value_and_enable(&nw->fragments[nw->fragment_count].buffer, (s32)e->pending->data);
    nw->fragment_count++;
    TLobby__sub_80410BA8(nw, &e->pending->params, e->iface, e->lladdr);
    release_entry(nw);
    return 1;
}

extern void *TLobby__sub_804182DC(void *a, void *b, s16 len, s16 val) {
    s32 n;
    Ipv6NdNeighbor *e;

    Ipv6NdNeighbor *NetIPv6FindOrSelectNeighborCacheEntry(void *, int, s16); /* declared with void * and int parameters here; the definition takes (u8 *, u8 *, s16) */

    if (a == 0) {
        return 0;
    }
    if (len == 0 || b == 0) {
        return 0;
    }
    e = NetIPv6FindOrSelectNeighborCacheEntry(a, (int)b, len);
    if (e == 0) {
        return 0;
    }
    switch (e->match) {
    case 0:
        e->used = 1;
    case 1:
        NetMemcpy(e->addr, a, 0x10);
        n = len;
        if ((u32)n > 0x20) {
            n = 0x20;
        }
        e->lladdr_len = n;
        NetMemcpy(e->lladdr, b, e->lladdr_len);
        e->nud = 2;
        e->timer = ipv6_neighbor_discovery_state.stale_time;
        e->iface = val;
        break;
    case 2:
        n = len;
        if ((u32)n > 0x20) {
            n = 0x20;
        }
        e->lladdr_len = n;
        NetMemcpy(e->lladdr, b, e->lladdr_len);
        if (e->nud == 0 && e->pending != 0) {
            notify_804182DC(e);
            e->pending->used = 0;
            e->pending = 0;
        }
        e->nud = 2;
        e->timer = ipv6_neighbor_discovery_state.stale_time;
        e->iface = val;
        break;
    case 3:
        e->iface = val;
        break;
    default:
        break;
    }
    return e;
}
Ipv6NdNeighbor *NetIPv6FindOrSelectNeighborCacheEntry(u8 *addr, u8 *key, s16 klen) {
    Ipv6NdNeighbor *e;
    s16 n;
    Ipv6NdNeighbor *oldest_b;
    Ipv6NdNeighbor *oldest_a;
    Ipv6NdNeighbor *empty;
    s16 age_b;
    s16 age_a;

    oldest_a = NULL;
    empty = NULL;
    {
        s16 m = ipv6_neighbor_discovery_state.stale_time;
        age_b = m;
        age_a = m;
    }
    if (addr == NULL) {
        return NULL;
    }
    n = ipv6_neighbor_discovery_state.nneighbors;
    e = ipv6_neighbor_discovery_state.neighbors;
    while (n > 0) {
        if (e->used != 1) {
            if (empty == NULL) {
                empty = e;
            }
        } else if (NetMemcmp(e->addr, addr, 0x10) == 0) {
            if (klen == 0) {
                if (e->lladdr_len != 0) {
                    e->match = 2;
                } else {
                    e->match = 3;
                }
            } else if (e->lladdr_len != klen || NetMemcmp(e->lladdr, key, klen) != 0) {
                e->match = 2;
            } else {
                e->match = 3;
            }
            return e;
        } else {
            switch (e->nud) {
            case 2:
                if (e->timer < age_a) {
                    oldest_a = e;
                    age_a = e->timer;
                }
                break;
            default:
                if (e->timer < age_b) {
                    oldest_b = e;
                    age_b = e->timer;
                }
                break;
            }
        }
        n--;
        e++;
    }
    if (empty != NULL) {
        empty->match = 0;
        return empty;
    }
    if (oldest_a != NULL) {
        oldest_a->match = 1;
        return oldest_a;
    }
    oldest_b->match = 1;
    return oldest_b;
}

Ipv6NdRouter *NetIPv6SelectDefaultRouter(void *arg0) {
    s16 n;
    Ipv6NdRouter *e;
    Ipv6NdRouter *found;
    Ipv6NdRouter *best;

    found = NULL;
    best = NULL;
    n = ipv6_neighbor_discovery_state.nrouters;
    e = ipv6_neighbor_discovery_state.routers;
    while (n > 0) {
        if (e->used == 1) {
            if (NetMemcmp(e->addr, arg0, 0x10) == 0) {
                found = e;
                e->uses++;
            } else if (best == NULL) {
                best = e;
            } else if (e->uses <= best->uses) {
                best = e;
            }
        }
        n--;
        e++;
    }
    if (best == NULL) {
        return found;
    }
    return best;
}

extern s32 TLobby__sub_80418734(void *addr, NetIcmpv6RouterAdvertisement *ra, s16 iface) {
  Ipv6NdState *g;
  s16 count;
  Ipv6NdRouter *e;
  Ipv6NdRouter *best;
  Ipv6NdRouter *first = NULL;
  s16 lim;
  u32 w;
  g = &ipv6_neighbor_discovery_state;
  lim = g->stale_time;
  count = g->nrouters;
  e = g->routers;
  while (count > 0)
  {
    if (e->used != 1)
    {
      if (first == NULL)
      {
        first = e;
      }
    }
    else
    {
      if (NetMemcmp(e->addr, addr, 0x10) == 0)
      {
        e->iface = iface;
        e->lifetime = ra->router_lifetime;
        w = ra->reachable_time;
        if (w != 0)
        {
          e->reachable_time = w;
        }
        w = ra->retrans_timer;
        if (w != 0)
        {
          e->retrans_timer = w;
        }
        return 0;
      }
      if (e->lifetime < lim)
      {
        best = e;
        lim = e->lifetime;
      }
    }
    count--;
    e++;
  }

  if (first != NULL)
  {
    first->used = 1;
    e = first;
  }
  else
    if (best != NULL)
  {
    e = best;
  }
  else
  {
    return -0x10e;
  }
  NetMemcpy(e->addr, addr, 0x10);
  e->iface = iface;
  e->lifetime = ra->router_lifetime;
  w = ra->reachable_time;
  if (w != 0)
  {
    e->reachable_time = w;
    g->reachable_time = e->reachable_time / 1000;
  }
  w = ra->retrans_timer;
  if (w != 0)
  {
    e->retrans_timer = w;
    g->retrans_timer = e->retrans_timer / 1000;
    g->retrans_ticks = (e->retrans_timer / 1000) + 1;
  }
  return 0;
}

inline Ipv6NdNeighbor *find_804188E4(Ipv6NdState *g, Ipv6NdPending *e) {
    s16 n = g->nneighbors;
    Ipv6NdNeighbor *r = g->neighbors;
    while (n > 0) {
        if (r->used == 1 && r->pending == e) {
            return r;
        }
        n--;
        r++;
    }
    return NULL;
}

Ipv6NdPending *NetIPv6SelectPendingPacketSlot(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4, Ipv6NdPending *best) {
    Ipv6NdPending *free_;
    Ipv6NdState *g = &ipv6_neighbor_discovery_state;
    s16 v;
    s16 n;
    Ipv6NdPending *e;
    s16 bestv;
    Ipv6NdNeighbor *r;

    bestv = g->stale_time;
    free_ = NULL;
    n = g->npending;
    e = g->pending;
    while (n > 0) {
        if (e->used != 1) {
            if (free_ == NULL) {
                free_ = e;
            }
        } else {
            v = e->ttl;
            if (v < bestv) {
                best = e;
                bestv = v;
            }
        }
        n--;
        e++;
    }
    if (free_ != NULL) {
        free_->used = 1;
        return free_;
    }
    r = find_804188E4(g, best);
    if (r != NULL) {
        r->pending = NULL;
    }
    return best;
}

void NetIPv6ApplyNeighborDiscoveryDefaults(Ipv6NdState *nd) {
    if (nd->mtu == 0) {
        nd->mtu = 1500;
    }
    if (nd->max_multicast_solicit == 0) {
        nd->max_multicast_solicit = 3;
    }
    if (nd->max_unicast_solicit == 0) {
        nd->max_unicast_solicit = 3;
    }
    if (nd->max_anycast_delay == 0) {
        nd->max_anycast_delay = 1;
    }
    if (nd->max_neighbor_adverts == 0) {
        nd->max_neighbor_adverts = 3;
    }
    if (nd->stale_time == 0) {
        nd->stale_time = 6400;
    }
    if (nd->reachable_time == 0) {
        nd->reachable_time = 30;
    }
    if (nd->retrans_timer == 0) {
        nd->retrans_timer = 1;
    }
    if (nd->retrans_ticks == 0) {
        nd->retrans_ticks = nd->retrans_timer + 1;
    }
    if (nd->delay_first_probe == 0) {
        nd->delay_first_probe = 6;
    }
}

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
    s16 compare_sockaddr(void*, u8 *); /* declared s16 here; the definition returns s32 */
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
    NetFragment *ent;
    s16 i;
    s16 n;
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
    NetFragment *f;
    s16 cnt;
    s16 n;
    s16 lim;
    u32 acc;
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
  s16 cnt;
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
  u32 c16;
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
  tail = alloc_free_entry();
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
    s16 compare_sockaddr(void*, u8 *); /* declared s16 here; the definition returns s32 */
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
Ipv6NdState ipv6_neighbor_discovery_state;
NetBufferPool network_buffer_pool_state;
LoopbackState network_loopback_state;
Ipv6State ipv6_address_routing_state;
