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
void release_entry(void *self);

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

s16 TLobby__sub_80413D78(); /* declared without a parameter list; the definition is s16 (self, idx) */
s16 TLobby__sub_80413F0C(); /* declared without a parameter list; the definition is s16 (self, id) */
s16 NetIPv6HandleNeighborSolicitation(u8 *arg0, void *arg1, void *arg2, void *arg3);

s32 NetUnregisterTimer(void* p);

/* Inline the helpers below; this applies to the rest of the file. */
#pragma dont_inline off
#pragma inline_depth(4)

s16 NetIPv6HandleRouterSolicitation(u8 *o, s32 arg1, s32 arg2, s32 arg3);
s16 NetIPv6HandleRouterAdvertisement(u8 *arg0, u8 *arg1, s32 arg2, void *arg3);
s16 NetIPv6HandleNeighborAdvertisement(u8 *arg0, void *arg1, void *arg2, s16 arg3);
s16 NetIPv6HandleRedirect(u8 *arg0, u8 *arg1, void *arg2, s32 arg3);

s32 TLobby__sub_80411604(int, int, void *);
s32 NetIPv6SendRouterSolicitation(s32 arg0);

s16 TLobby__sub_804137FC(void *self, s16 idx);

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

Ipv6NdState ipv6_neighbor_discovery_state;
