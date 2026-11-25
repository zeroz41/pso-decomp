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

#include "types.h"
#include "pso/network/Ppp.h"
#include "pso/network/NetStack.h"
#include "pso/network/NetIpv6Route.h"

#include <stddef.h>

#include "pso/network/IPv6Send.h"
#include "pso/network/NetStackTypes.h"
#include "pso/network/NetIPv6NeighborDiscovery.h"



/* Inline the helpers below; this applies to the rest of the file. */
#pragma dont_inline off
#pragma inline_depth(4)



void NetIPv6ShutdownNeighborDiscovery(void) {
    Ipv6NdState *g = &ipv6_neighbor_discovery_state;
    NetUnregisterTimer(NetIPv6TickNeighborDiscovery);
    term_ipv6_nd_config(g);
    g->nneighbors = 0;
    g->nrouters = 0;
}


s16 NetIPv6InitNeighborDiscovery(void) {
    s16 n;
    u8 *buf;
    Ipv6NdPending *a;
    Ipv6NdRouter *c;
    Ipv6NdNeighbor *b;
    Ipv6NdRouter *r;
    Ipv6NdState *g;
    s16 mtu;
    Ipv6NdAddrEvent a2;
    Ipv6NdAddrEvent a1;

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
                NetIPv6HandleRoutingEvent(b->iface, 6, &a1);
            } else {
                a2.next_router = r->addr;
                a2.addr = b->addr;
                NetIPv6HandleRoutingEvent(b->iface, 7, &a2);
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
    NetIPv6TickRouters();
}

s16 NetIPv6NeighborOutput(NetPacket *a, u8 *b, NetIPv6SendParameters *c, s16 d) {
    Ipv6NdState *g;
    Ipv6NdAddrEvent pb;
    Ipv6NdAddrEvent pa;
    NetBufferRef cur;
    Ipv6NdAddrEvent pb2;
    Ipv6NdAddrEvent pa2;
    Ipv6NdNeighbor *e;
    s16 ret;
    u8 *src;
    u32 n;
    Ipv6NdPending *q;
    NetPacketFragment *seg;
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
            return ipv6_transmit(a, c, d, e->lladdr);
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
                pa.addr = e->addr;
                NetIPv6HandleRoutingEvent(e->iface, 6, &pa);
            } else {
                pb.next_router = t->addr;
                pb.addr = e->addr;
                NetIPv6HandleRoutingEvent(e->iface, 7, &pb);
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
        set_value_and_enable(&cur, src);
        netbuf_copy_by_ref(&cur, &a->fragments[n - 1].buffer, l);
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
                pa2.addr = e->addr;
                NetIPv6HandleRoutingEvent(e->iface, 6, &pa2);
            } else {
                pb2.next_router = t->addr;
                pb2.addr = e->addr;
                NetIPv6HandleRoutingEvent(e->iface, 7, &pb2);
            }
        }
        e->used = 0;
        e->lladdr_len = 0;
        return ret;
    }
    NetMemcpy(&e->pending->params, c, 0x28);
    e->timer = g->retrans_ticks;
    e->pending->ttl = e->timer;
    e->probes = 0;
    return NetIPv6SendMulticastNeighborProbe(e);
}

s16 NetIPv6SendUnspecifiedSourceNeighborSolicitation(u8 *addr, s16 idx) {
    NetIPv6SendParameters params;
    s16 ret;
    NetPacket *free_entry;
    if (NetIPv6IsAnycastAddress(addr, idx) != 0) {
        return -0x10E;
    }
    free_entry = alloc_free_entry();
    if (free_entry == NULL) {
        return -0x10E;
    }
    free_entry->fragment_count = 0;
    free_entry->total_bytes = 0;
    NetMemset(&params.source, 0, 0x10);
    NetIPv6MakeSolicitedNodeMulticastAddress(params.destination.bytes, addr);
    ret = NetIPv6EmitNeighborSolicitation(free_entry, addr, &params, idx, NULL);
    release_entry(free_entry);
    return ret;
}

s16 NetIPv6SendRouterSolicitation(s16 iface) {
    NetIPv6SendParameters params;
    s16 result;
    NetPacket *free_entry;

    free_entry = alloc_free_entry();
    if (free_entry == NULL) {
        return -0x10E;
    }
    free_entry->fragment_count = 0;
    free_entry->total_bytes = 0;
    init_ipv6_all_routers_multicast_address(params.destination.bytes, 2);
    if (NetIPv6GetLinkLocalAddress(&params.source, iface) < 0) {
        NetMemset(&params.source, 0, 0x10);
    }
    result = NetIPv6EmitRouterSolicitation(free_entry, &params, iface);
    release_entry(free_entry);
    return result;
}

static inline u8 *find_neighbor_slot(Ipv6NdState *g, u8 *addr) {
    s16 n = g->nneighbors;
    Ipv6NdNeighbor *nb = g->neighbors;
    for (; n > 0; n--, nb++) {
        if (nb->used == 1 && NetMemcmp(nb->addr, addr, 0x10) == 0) {
            return (u8 *)nb;
        }
    }
    return NULL;
}
extern void NetIPv6TickRouters(void) {
    Ipv6NdState *g = &ipv6_neighbor_discovery_state;
    Ipv6NdNeighbor *nb;
    s16 n;
    Ipv6NdRouter *r;
    Ipv6NdRouter *alive = NULL;
    Ipv6NdRouter *expired = NULL;
    Ipv6NdAddrEvent a6;
    Ipv6NdAddrEvent a7;

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
    nb = (Ipv6NdNeighbor *)find_neighbor_slot(g, expired->addr);
    if (nb != NULL) {
        nb->flags &= ~0x80;
    }
    if (alive != NULL) {
        a7.addr = expired->addr;
        a7.next_router = alive->addr;
        NetIPv6HandleRoutingEvent(alive->iface, 7, &a7);
    } else {
        a6.addr = expired->addr;
        NetIPv6HandleRoutingEvent(expired->iface, 6, &a6);
    }
}

void NetIPv6TickNeighborCache(void) {
    Ipv6NdAddrEvent a7;
    Ipv6NdAddrEvent a6;
    Ipv6NdAddrEvent a7b;
    Ipv6NdAddrEvent a6b;
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
                        NetIPv6SendMulticastNeighborProbe(e);
                        e->timer = g->retrans_timer;
                    } else {
                        if (e->pending != NULL) {
                            e->pending->used = 0;
                            e->pending = NULL;
                        }
                        if (e->flags & 0x80) {
                            r = NetIPv6SelectDefaultRouter(e->addr);
                            if (r == NULL) {
                                a6.addr = e->addr;
                                NetIPv6HandleRoutingEvent(e->iface, 6, &a6);
                            } else {
                                a7.next_router = r->addr;
                                a7.addr = e->addr;
                                NetIPv6HandleRoutingEvent(e->iface, 7, &a7);
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
                    NetIPv6SendUnicastNeighborProbe(e);
                    e->nud = 4;
                    e->timer = g->retrans_timer;
                    e->probes = 0;
                    break;
                case 4:
                    if (++e->probes < g->max_unicast_solicit) {
                        NetIPv6SendUnicastNeighborProbe(e);
                        e->timer = g->retrans_timer;
                    } else {
                        if (e->pending != NULL) {
                            e->pending->used = 0;
                            e->pending = NULL;
                        }
                        if (e->flags & 0x80) {
                            r = NetIPv6SelectDefaultRouter(e->addr);
                            if (r == NULL) {
                                a6b.addr = e->addr;
                                NetIPv6HandleRoutingEvent(e->iface, 6, &a6b);
                            } else {
                                a7b.next_router = r->addr;
                                a7b.addr = e->addr;
                                NetIPv6HandleRoutingEvent(e->iface, 7, &a7b);
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
s16 NetIPv6HandleRedirect(NetPacket *pkt, u8 *right, u8 *dst, s16 iface) {
    NetBufferRef ref;
    NetIcmpv6Redirect msg;
    u8 opts[0x38];
    s16 optlen;
    struct { u8 *p; s16 h; u8 *a; u8 *b; } rec;
    Ipv6Route *e;
    u8 *dest;
    u8 *target;
    u32 len;
    NetPacketFragment *frag;
    s16 r;

    frag = &pkt->fragments[1];
    optlen = 0x38;
    len = pkt->fragments[1].length;
    if (len < 0x28) {
        return -1;
    }
    if (NetIPv6IsLinkLocal(right) == 0) {
        return -1;
    }
    set_value_and_enable(&ref, &msg);
    netbuf_copy_by_ref(&ref, &frag->buffer, 0x28);
    dest = msg.destination.bytes;
    if (NetIPv6IsMulticast(dest) != 0) {
        return -1;
    }
    target = msg.target.bytes;
    if (NetIPv6IsLinkLocal(target) == 0 && NetMemcmp(target, dest, 0x10) != 0) {
        return -1;
    }
    e = NetIPv6LookupRoute(dest, right);
    if (e == NULL || NetMemcmp(e->gateway, right, 0x10) != 0) {
        return -1;
    }
    len -= 0x28;
    if (len >= 8) {
        netbuf_ref_advance(&frag->buffer, 0x28);
        r = NetIPv6ParseRedirectOptions(frag, len, &msg, opts, &optlen, iface);
        if (r < 0) {
            return r;
        }
    }
    rec.p = dest;
    rec.h = e->prefix_len;
    rec.a = e->gateway;
    rec.b = target;
    NetIPv6HandleRoutingEvent(iface, 0xa, &rec);
    return 0;
}
#pragma pop
s16 NetIPv6ParseRedirectOptions(NetPacketFragment *frag, s32 n, NetIcmpv6Redirect *msg, void *opts, s16 *optlen, s16 iface) {
    NetBufferRef ref;
    u8 *h;
    s16 len;
    Ipv6NdNeighbor *e;

    while (n >= 8) {
        h = netbuf_ref_data(&frag->buffer);
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
            netbuf_ref_advance(&frag->buffer, len);
            break;
        case 4:
            *optlen = (*optlen < len) ? *optlen : len;
            set_value_and_enable(&ref, opts);
            netbuf_copy_by_ref(&ref, &frag->buffer, *optlen);
            netbuf_ref_advance(&frag->buffer, len);
            break;
        case 2: {
            u8 *p = h + 2;
            s16 l = len - 2;
            e = NetIPv6UpdateNeighborLinkAddress(msg->target.bytes, p, l, iface);
            if (e != NULL && NetMemcmp(msg->target.bytes, msg->destination.bytes, 0x10) != 0) {
                e->flags |= 0x80;
            }
            netbuf_ref_advance(&frag->buffer, len);
            break;
        }
        }
    }
    return 0;
}

s16 NetIPv6HandleNeighborAdvertisement(NetPacket *pkt, u8 *src, u8 *address, s16 id) {
    NetBufferRef ref;
    NetIcmpv6NeighborAdvertisement msg;
    u8 *lladdr;
    s16 lladlen;
    NetPacketFragment *hdr;
    u32 len;
    s16 r;
    lladdr = 0;
    lladlen = 0;

    hdr = &pkt->fragments[1];
    len = pkt->fragments[1].length;
    if (len < 0x18) {
        return -1;
    }
    set_value_and_enable(&ref, &msg);
    netbuf_copy_by_ref(&ref, &hdr->buffer, 0x18);
    if ((s16)NetIPv6IsMulticast(msg.target.bytes)) {
        return -1;
    }
    len -= 0x18;
    if (len >= 8) {
        netbuf_ref_advance(&hdr->buffer, 24);
        r = NetIPv6FindTargetLinkLayerAddressOption(hdr, len, &lladdr, &lladlen);
        if (r < 0) {
            return r;
        }
    }
    if ((s16)NetIPv6IsMulticast(address)) {
        if ((msg.flags & 0x40) || lladlen == 0) {
            return -1;
        }
    }
    return NetIPv6ApplyNeighborAdvertisement(&msg, lladdr, lladlen, src, address, id);
}

s16 NetIPv6FindTargetLinkLayerAddressOption(NetPacketFragment *o, s32 len, u8 **out, s16 *outlen) {
    u8 *p;
    s16 sz;

    while (len >= 8) {
        p = netbuf_ref_data(&o->buffer);
        if (p[1] == 0) {
            return -0x10E;
        }
        sz = p[1] << 3;
        len -= sz;
        if (len < 0) {
            return -0x10E;
        }
        if ((s32)p[0] != 2) {
            netbuf_ref_advance(&o->buffer, sz);
        } else {
            *out = p + 2;
            *outlen = sz - 2;
            netbuf_ref_advance(&o->buffer, sz);
        }
    }
    return 0;
}

static inline Ipv6NdNeighbor *find_neighbor(Ipv6NdState *g, void *name) {
    s16 n = g->nneighbors;
    Ipv6NdNeighbor *e = g->neighbors;
    for (; n > 0; n--, e++) {
        if (e->used == 1 && NetMemcmp(e->addr, name, 0x10) == 0) {
            return e;
        }
    }
    return 0;
}

static inline void clear_router(Ipv6NdRouter *p) {
    p->used = 0;
    p->uses = 0;
}

static inline Ipv6NdRouter *forget_router(Ipv6NdState *g, void *name) {
    s16 m;
    Ipv6NdRouter *p;
    Ipv6NdRouter *hit;
    hit = 0;
    m = g->nrouters;
    p = g->routers;
    for (; m > 0; m--, p++) {
        if (p->used == 1) {
            if (NetMemcmp(p->addr, name, 0x10) == 0) {
                clear_router(p);
            } else {
                hit = p;
            }
        }
    }
    return hit;
}

s16 NetIPv6ApplyNeighborAdvertisement(NetIcmpv6NeighborAdvertisement *msg, u8 *name, s16 len, u8 *src, u8 *address, s16 id) {
    Ipv6NdAddrEvent a;
    Ipv6NdAddrEvent b;
    Ipv6NdState *g = &ipv6_neighbor_discovery_state;
    Ipv6NdNeighbor *e;

    if (NetIPv6IsTentativeAddress(msg->target.bytes, id) != 0) {
        a.addr = msg->target.bytes;
        NetIPv6HandleRoutingEvent(id, 1, &a);
        return 0;
    }
    if (NetIPv6IsValidAddress(msg->target.bytes, id) != 0) {
        return 0;
    }
    e = find_neighbor(g, msg->target.bytes);
    if (e == 0) {
        return 0;
    }
    if ((e->flags ^ msg->flags) & 0x80) {
        if (len == 0 || name == 0 || (e->lladdr_len == len && NetMemcmp(e->lladdr, name, len) == 0) || (msg->flags & 0x20)) {
            if (msg->flags & 0x80) {
                e->flags |= 0x80;
                a.addr = msg->target.bytes;
                NetIPv6HandleRoutingEvent(id, 8, &a);
            } else {
                Ipv6NdRouter *hit;
                e->flags |= ~0x80;
                hit = forget_router(g, msg->target.bytes);
                if (hit == 0) {
                    a.addr = msg->target.bytes;
                    NetIPv6HandleRoutingEvent(id, 9, &a);
                } else {
                    b.next_router = hit->addr;
                    b.addr = msg->target.bytes;
                    NetIPv6HandleRoutingEvent(id, 7, &b);
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
                NetPacket *pkt = alloc_free_entry();
                s16 ret;
                if (pkt == 0) {
                    ret = -0x10E;
                } else {
                    pkt->fragment_count = 0;
                    pkt->total_bytes = e->pending->len;
                    pkt->fragments[pkt->fragment_count].length = e->pending->len;
                    set_value_and_enable(&pkt->fragments[pkt->fragment_count].buffer, e->pending->data);
                    pkt->fragment_count++;
                    ret = ipv6_transmit(pkt, &e->pending->params, e->iface, e->lladdr);
                    release_entry(pkt);
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

static inline Ipv6NdRouter *find_router_in(s16 *cnt, Ipv6NdRouter **list, void *name) {
    s16 n = *cnt;
    Ipv6NdRouter *p = *list;
    for (; n > 0; n--, p++) {
        if (p->used == 1 && NetMemcmp(p->addr, name, 0x10) == 0) {
            return p;
        }
    }
    return 0;
}

static inline Ipv6NdRouter *forget_router_in(s16 *cnt, Ipv6NdRouter **list, void *name) {
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

s16 NetIPv6ParseRouterAdvertisementOptions(NetPacketFragment *self, s32 n, u8 *dst, s16 iface);

s16 NetIPv6HandleNeighborSolicitation(NetPacket *pkt, u8 *src, u8 *dst, s16 iface) {
    NetBufferRef ref;
    IPv6NeighborSolicitation ns;
    NetPacketFragment *hdr;
    u32 len;
    s16 r;
    hdr = &pkt->fragments[1];
    len = pkt->fragments[1].length;
    if (len < 0x18) {
        return -1;
    }
    if ((s16)NetIPv6IsUnspecified(src) && NetIPv6IsSolicitedNodeAddress(dst, iface) == 0) {
        return -1;
    }
    set_value_and_enable(&ref, &ns);
    netbuf_copy_by_ref(&ref, &hdr->buffer, 0x18);
    if ((s16)NetIPv6IsMulticast(ns.target.bytes)) {
        return -1;
    }
    len -= 0x18;
    if (len >= 8) {
        netbuf_ref_advance(&hdr->buffer, 24);
        r = NetIPv6ParseNeighborSolicitationOptions(hdr, len, src, iface);
        if (r < 0) {
            return r;
        }
    }
    return NetIPv6AnswerNeighborSolicitation(&ns, src, dst, iface);
}

extern s16 NetIPv6ParseNeighborSolicitationOptions(NetPacketFragment *self, s32 n, void *out, s16 iface)
{
  u8 *p;
  s16 step;
  s16 lladdr_len;
  u8 *q;
  while (n >= 8)
  {
    p = netbuf_ref_data(&self->buffer);
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
      netbuf_ref_advance(&self->buffer, step);
      continue;
    }
    if (NetIPv6IsUnspecified(out))
    {
      return -0x10E;
    }
    q = p + 2;
    lladdr_len = step - 2;
    NetIPv6UpdateNeighborLinkAddress(out, q, lladdr_len, iface);
    netbuf_ref_advance(&self->buffer, step);
  }

  return 0;
}

s16 NetIPv6AnswerNeighborSolicitation(IPv6NeighborSolicitation *ns, void *a, void *b, s16 iface) {
    u8 opt[0x28];
    NetIPv6SendParameters params;
    Ipv6NdAddrEvent event;
    NetPacket *p;
    u8 flags;
    s16 n;
    s16 len;
    s16 r;

    flags = 0;
    if (NetIPv6IsTentativeAddress(ns->target.bytes, iface)) {
        event.addr = ns->target.bytes;
        NetIPv6HandleRoutingEvent(iface, 1, &event);
        return 0;
    }
    if (!NetIPv6IsValidAddress(ns->target.bytes, iface)) {
        return 0;
    }
    NetMemcpy(params.source.bytes, ns->target.bytes, 0x10);
    p = alloc_free_entry();
    if (p == NULL) {
        return -0x10e;
    }
    p->fragment_count = 0;
    p->total_bytes = 0;
    if (NetIPv6IsUnspecified(a)) {
        init_ipv6_all_nodes_multicast_address(params.destination.bytes, 2);
    } else {
        NetMemcpy(params.destination.bytes, a, 0x10);
    }
    if (NetIPv6IsMulticast(b)) {
        n = NetIPv6GetInterfaceLinkLayerAddress(opt + 2, 0x20, iface);
        if (n > 0) {
            len = n + 2;
            opt[0] = 2;
            opt[1] = len >> 3;
            p->total_bytes += len;
            p->fragments[p->fragment_count].length = n + 2;
            set_value_and_enable(&p->fragments[p->fragment_count].buffer, opt);
            flags |= 0x20;
            p->fragment_count += 1;
        }
    }
    r = NetIPv6SendNeighborAdvertisement(p, ns->target.bytes, flags, &params, iface);
    release_entry(p);
    return r;
}

s16 NetIPv6HandleRouterAdvertisement(NetPacket *pkt, u8 *src, u8 *dst, s16 iface) {
    NetBufferRef ref;
    NetIcmpv6RouterAdvertisement ra;
    u32 n;
    NetPacketFragment *p;
    s16 r;

    p = &pkt->fragments[1];
    n = pkt->fragments[1].length;
    if (n < 0x10U) {
        return -1;
    }
    r = NetIPv6IsLinkLocal(src);
    if (r == 0) {
        return -1;
    }
    set_value_and_enable(&ref, &ra);
    netbuf_copy_by_ref(&ref, &p->buffer, 0x10);
    n -= 0x10;
    if (n >= 8U) {
        netbuf_ref_advance(&p->buffer, 0x10);
        r = NetIPv6ParseRouterAdvertisementOptions(p, n, src, iface);
        if (r < 0) {
            return r;
        }
    }
    return NetIPv6UpdateDefaultRouter(&ra, src, iface);
}

#pragma push
#pragma opt_dead_assignments off
#pragma opt_loop_invariants off
extern s16 NetIPv6ParseRouterAdvertisementOptions(NetPacketFragment *self, s32 n, u8 *dst, s16 iface)
{
  NetBufferRef ref;
  u8 *prefix;
  Ipv6NdPrefixInfoOption prefix_opt;
  Ipv6NdPrefixEvent prefix_event;
  Ipv6NdMtuOption mtu_opt;
  Ipv6NdMtuEvent mtu_event;
  long long new_var;
  u8 *payload = (void *) 0;
  s16 len;
  while (n >= 8)
  {
    u8 *p = netbuf_ref_data(&self->buffer);
    if (p[1] == 0)
    {
      return -0x10E;
    }
    len = (s16) (p[1] << 3);
    n -= len;
    if (n < 0)
    {
      return -0x10E;
    }
    switch (p[0])
    {
      default:
        netbuf_ref_advance(&self->buffer, len);
        break;

      case 1:
        new_var = len - 2;
        payload = p + 2;
        NetIPv6UpdateNeighborLinkAddress(dst, payload, new_var, iface)->flags |= 0x80;
        netbuf_ref_advance(&self->buffer, len);
        break;

      case 3:
        if (len == 0x20U)
      {
        set_value_and_enable(&ref, &prefix_opt);
        prefix = prefix_opt.prefix.bytes;
        netbuf_copy_by_ref(&ref, &self->buffer, 0x20);
        prefix_event.prefix = prefix;
        prefix_event.prefix_len = prefix_opt.prefix_len;
        prefix_event.preferred_lifetime = prefix_opt.preferred_lifetime;
        prefix_event.valid_lifetime = prefix_opt.valid_lifetime;
        NetIPv6HandleRoutingEvent(iface, 2, &prefix_event);
      }
        netbuf_ref_advance(&self->buffer, len);
        break;

      case 5:
        if (len == 8U)
      {
        set_value_and_enable(&ref, &mtu_opt);
        netbuf_copy_by_ref(&ref, &self->buffer, 8);
        mtu_event.router = dst;
        mtu_event.mtu = mtu_opt.mtu;
        NetIPv6HandleRoutingEvent(iface, 4, &mtu_event);
      }
        netbuf_ref_advance(&self->buffer, len);
        break;

    }

  }

  if (payload == ((void *) 0))
  {
    Ipv6NdNeighbor *e2 = find_neighbor(&ipv6_neighbor_discovery_state, dst);
    if (e2 != 0)
    {
      e2->flags |= 0x80;
    }
  }
  return 0;
}
#pragma pop
s32 NetIPv6UpdateRouterEntry(void *addr, NetIcmpv6RouterAdvertisement *ra, s16 iface);
#pragma push
#pragma opt_propagation off
s16 NetIPv6UpdateDefaultRouter(NetIcmpv6RouterAdvertisement *ra, u8 *src, s16 iface) {
    Ipv6NdState *g = &ipv6_neighbor_discovery_state;
    s16 *pc = &g->nrouters;
    Ipv6NdRouter **pl = &g->routers;
    s16 cc;
    u8 *aa;
    NetIcmpv6RouterAdvertisement *m;
    Ipv6NdRouter *p;
    Ipv6NdNeighbor *e;
    s32 padx[2];
    struct {
        s32 pad[2];
        Ipv6NdHopLimitEvent s3;
        Ipv6NdAddrEvent s2;
        u8 *s1;
    } loc;

    m = ra;
    aa = src;
    cc = iface;
    p = find_router_in(pc, pl, aa);
    if (p == 0) {
        if (m->router_lifetime != 0) {
            NetIPv6UpdateRouterEntry(aa, m, cc);
            loc.s1 = aa;
            NetIPv6HandleRoutingEvent(cc, 5, &loc.s1);
        } else {
            e = find_neighbor(g, aa);
            if (e != 0) {
                e->flags &= ~0x80;
            }
            loc.s1 = aa;
            NetIPv6HandleRoutingEvent(cc, 6, &loc.s1);
        }
    } else if (m->router_lifetime != 0) {
        loc.s1 = aa;
        NetIPv6HandleRoutingEvent(cc, 5, &loc.s1);
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
        e = find_neighbor(g, aa);
        if (e != 0) {
            e->flags &= ~0x80;
        }
        if ((hit = forget_router_in(pc, pl, aa)) == 0) {
            loc.s1 = aa;
            NetIPv6HandleRoutingEvent(cc, 6, &loc.s1);
        } else {
            loc.s2.next_router = hit->addr;
            loc.s2.addr = aa;
            NetIPv6HandleRoutingEvent(cc, 7, &loc.s2);
        }
    }
    if (m->cur_hop_limit != 0) {
        loc.s3.router = aa;
        loc.s3.hop_limit = m->cur_hop_limit;
        NetIPv6HandleRoutingEvent(cc, 3, &loc.s3);
    }
    return 0;
}
#pragma pop

s16 NetIPv6HandleRouterSolicitation(NetPacket *pkt, u8 *src, u8 *dst, s16 iface) {
    NetBufferRef b;
    NetIcmpv6RouterSolicitation a;
    s32 pad;
    u8 *v;
    NetPacketFragment *h = &pkt->fragments[1];
    u32 len = h->length;
    s16 r;

    if (len < 8) {
        return -1;
    }
    set_value_and_enable(&b, &a);
    netbuf_copy_by_ref(&b, &h->buffer, 8);
    len -= 8;
    if (len >= 8) {
        netbuf_ref_advance(&h->buffer, 8);
        r = NetIPv6ParseRouterSolicitationOptions(h, len, src, iface);
        if (r < 0) {
            return r;
        }
    }
    v = src;
    NetIPv6HandleRoutingEvent(iface, 0xC, &v);
    return 0;
}

s16 NetIPv6ParseRouterSolicitationOptions(NetPacketFragment *opts, u32 len, u8 *src, s16 iface)
{
  s16 i;
  s32 step;
  NetPacketFragment *self;
  u8 *q;
  s16 arg_;
  void *out;
  s32 n;
  u8 *p;
  self = opts;
  n = len;
  out = src;
  arg_ = iface;
  q = (void *) 0;
  while (n >= 8)
  {
    p = netbuf_ref_data(&self->buffer);
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
      netbuf_ref_advance(&self->buffer, step);
      continue;
    }
    if (!NetIPv6IsUnspecified(out))
    {
      s16 t = step - 2;
      q = p + 2;
      NetIPv6UpdateNeighborLinkAddress(out, q, t, arg_);
    }
    netbuf_ref_advance(&self->buffer, step);
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

#pragma push
#pragma opt_propagation off
#pragma opt_common_subs on
s16 NetIPv6SendNeighborAdvertisement(NetPacket *pkt, u8 *address, u8 flags, NetIPv6SendParameters *params, s16 iface) {
    NetIcmpv6NeighborAdvertisement na;
    NetBufferRef cur;
    Ipv6NdNeighbor *e;
    u8 *p6;
    void netbuf_copy_by_ref(NetBufferRef *, NetBufferRef *, int);
    if (NetIPv6IsMulticast(address) != 0) {
        return -0x10E;
    }
    if (NetIPv6IsUnspecified(params->source.bytes) != 0) {
        s16 r = NetIPv6GetLinkLocalAddress(params, iface);
        if (r < 0) {
            return r;
        }
    } else if (NetIPv6IsPreferredAddress(params, iface) == 0) {
        return -0x10E;
    }
    params->traffic_class_bits = 0;
    params->flow_label = 0;
    params->next_header = 0x3A;
    params->hop_limit = 0xFF;
    pkt->total_bytes += 0x18;
    pkt->fragments[pkt->fragment_count].length = 0x18;
    set_value_and_enable(&pkt->fragments[pkt->fragment_count].buffer, &na);
    pkt->fragment_count++;
    na.type = 0x88;
    na.code = 0;
    na.flags = flags;
    NetMemset(na.reserved, 0, 3);
    NetMemcpy(na.target.bytes, address, 0x10);
    if (NetIPv6IsMulticast(params->destination.bytes) != 0 || NetIPv6InterfaceNeedsResolution(iface) == 0) {
        na.flags |= 0xFFBF;
        na.checksum = 0;
        na.checksum = calc_ipv6_pseudo_header_checksum(&params->source, &params->destination, params->next_header, pkt, 1);
        p6 = NULL;
    } else {
        e = NetIPv6FindOrSelectNeighborCacheEntry(params->destination.bytes, 0, 0);
        if (e == NULL) {
            return -0x10E;
        }
        na.flags |= 0x40;
        na.checksum = 0;
        na.checksum = calc_ipv6_pseudo_header_checksum(&params->source, &params->destination, params->next_header, pkt, 1);
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
            Ipv6NdAddrEvent b;
            Ipv6NdAddrEvent a;
            NetPacketFragment *seg;
            e->iface = iface;
            e->nud = 0;
            e->timer = ipv6_neighbor_discovery_state.retrans_ticks;
            e->probes = 0;
            NetMemcpy(e->addr, params->destination.bytes, 0x10);
            if (e->pending == NULL) {
                e->pending = NetIPv6SelectPendingPacketSlot();
            }
            q = e->pending;
            n = pkt->fragment_count;
            src = q->data;
            q->len = 0;
            seg = (NetPacketFragment *)pkt + n; /* &arg0->fragments[n - 1]: the 12-byte header is one fragment long */
            while (n != 0) {
                s16 l = seg->length;
                q->len += l;
                if (q->len > ipv6_neighbor_discovery_state.mtu) {
                    ret = -0x10E;
                    goto done;
                }
                set_value_and_enable(&cur, src);
                netbuf_copy_by_ref(&cur, &pkt->fragments[n - 1].buffer, l);
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
                        a.addr = e->addr;
                        NetIPv6HandleRoutingEvent(e->iface, 6, &a);
                    } else {
                        b.next_router = t->addr;
                        b.addr = e->addr;
                        NetIPv6HandleRoutingEvent(e->iface, 7, &b);
                    }
                }
                e->used = 0;
                e->lladdr_len = 0;
                return ret;
            }
            NetMemcpy(&e->pending->params, params, 0x28);
            return NetIPv6SendMulticastNeighborProbe(e);
        }
    }
tail:
    return ipv6_transmit(pkt, params, iface, p6);
}
#pragma pop

s16 NetIPv6SendMulticastNeighborProbe(Ipv6NdNeighbor *e) {
    NetIPv6SendParameters params;
    Ipv6NdAddrEvent a7;
    Ipv6NdAddrEvent a6;
    s16 ret;
    Ipv6NdRouter *router;
    NetPacket *pkt;
    Ipv6NdPending *pending;
    Ipv6NdPending *queued;

    pkt = alloc_free_entry();
    if (pkt == NULL) {
        pending = e->pending;
        if (pending != NULL) {
            pending->used = 0;
            e->pending = NULL;
        }
        if (e->flags & 0x80) {
            router = NetIPv6SelectDefaultRouter(e->addr);
            if (router == NULL) {
                a6.addr = e->addr;
                NetIPv6HandleRoutingEvent(e->iface, 6, &a6);
            } else {
                a7.next_router = router->addr;
                a7.addr = e->addr;
                NetIPv6HandleRoutingEvent(e->iface, 7, &a7);
            }
        }
        e->used = 0;
        e->lladdr_len = 0;
        return -0x10E;
    }
    pkt->fragment_count = 0;
    pkt->total_bytes = 0;
    queued = e->pending;
    if (queued != NULL && NetIPv6IsOwnAddress(&queued->params, e->iface) != 0) {
        NetMemcpy(&params.source, &e->pending->params, 0x10);
    } else {
        NetIPv6GetLinkLocalAddress(&params, e->iface);
    }
    NetIPv6MakeSolicitedNodeMulticastAddress(params.destination.bytes, e->addr);
    ret = NetIPv6EmitNeighborSolicitation(pkt, e->addr, &params, e->iface, NULL);
    release_entry(pkt);
    return ret;
}

s16 NetIPv6SendUnicastNeighborProbe(Ipv6NdNeighbor *e) {
    NetIPv6SendParameters params;
    Ipv6NdAddrEvent a7;
    Ipv6NdAddrEvent a6;
    s16 ret;
    Ipv6NdRouter *router;
    NetPacket *pkt;
    Ipv6NdPending *pending;
    Ipv6NdPending *queued;

    pkt = alloc_free_entry();
    if (pkt == NULL) {
        pending = e->pending;
        if (pending != NULL) {
            pending->used = 0;
            e->pending = NULL;
        }
        if (e->flags & 0x80) {
            router = NetIPv6SelectDefaultRouter(e->addr);
            if (router == NULL) {
                a6.addr = e->addr;
                NetIPv6HandleRoutingEvent(e->iface, 6, &a6);
            } else {
                a7.next_router = router->addr;
                a7.addr = e->addr;
                NetIPv6HandleRoutingEvent(e->iface, 7, &a7);
            }
        }
        e->used = 0;
        e->lladdr_len = 0;
        return -0x10E;
    }
    pkt->fragment_count = 0;
    pkt->total_bytes = 0;
    queued = e->pending;
    if (queued != NULL && NetIPv6IsOwnAddress(&queued->params, e->iface) != 0) {
        NetMemcpy(&params.source, &e->pending->params, 0x10);
    } else {
        NetIPv6GetLinkLocalAddress(&params, e->iface);
    }
    NetMemcpy(&params.destination, e->addr, 0x10);
    ret = NetIPv6EmitNeighborSolicitation(pkt, e->addr, &params, e->iface, e->lladdr);
    release_entry(pkt);
    return ret;
}

s16 NetIPv6EmitNeighborSolicitation(NetPacket *pkt, u8 *target, NetIPv6SendParameters *params, s16 iface, u8 *lladdr) {
    NetIcmpv6NeighborSolicitation message;
    NetSourceLinkLayerOption option;
    s16 addr_len;
    s16 length;
    s16 r;

    if (NetIPv6IsMulticast(target) != 0) {
        return -0x10E;
    }
    if (NetIPv6IsMulticast(params->destination.bytes) != 0) {
        lladdr = NULL;
    }
    if (NetIPv6IsUnspecified(params->source.bytes) == 0) {
        r = NetIPv6IsOwnLinkLocalAddress((u8 *)params, iface);
        if (r < 0) {
            return r;
        }
        addr_len = NetIPv6GetInterfaceLinkLayerAddress(&option.address, 0x20, iface);
        if (addr_len > 0) {
            length = addr_len + 2;
            option.type = 1;
            option.length_units = (u8)(length >> 3);
            pkt->total_bytes += length;
            pkt->fragments[pkt->fragment_count].length = length;
            set_value_and_enable(&pkt->fragments[pkt->fragment_count].buffer, &option);
            pkt->fragment_count += 1;
        }
    }
    params->traffic_class_bits = 0;
    params->flow_label = 0;
    params->next_header = 0x3A;
    params->hop_limit = 0xFF;
    pkt->total_bytes += 0x18;
    pkt->fragments[pkt->fragment_count].length = 0x18;
    set_value_and_enable(&pkt->fragments[pkt->fragment_count].buffer, &message);
    pkt->fragment_count += 1;
    message.header.type = 0x87;
    message.header.code = 0;
    message.header.reserved = 0;
    NetMemcpy(&message.target, target, 0x10);
    message.header.checksum = 0;
    message.header.checksum = calc_ipv6_pseudo_header_checksum(&params->source, &params->destination, params->next_header, pkt, 1);
    return ipv6_transmit(pkt, params, iface, lladdr);
}

#pragma push
#pragma optimization_level 3
s16 NetIPv6EmitRouterSolicitation(NetPacket *net_packet, NetIPv6SendParameters *addr, s16 id) {
    NetIcmpv6RouterSolicitation message;
    NetSourceLinkLayerOption option;
    s16 addr_len;
    s16 length;
    if ((NetIPv6IsMulticast(addr->destination.bytes)) == 0) {
        return -0x10E;
    }
    if ((NetIPv6IsUnspecified(addr->source.bytes)) == 0) {
        addr_len = NetIPv6GetInterfaceLinkLayerAddress(&option.address, 0x20, id);
        if (addr_len > 0) {
            length = addr_len + 2;
            option.type = 1;
            option.length_units = (u8) (length >> 3);
            net_packet->total_bytes += length;
            net_packet->fragments[net_packet->fragment_count].length = length;
            set_value_and_enable(&net_packet->fragments[net_packet->fragment_count].buffer, &option);
            net_packet->fragment_count += 1;
        }
    }
    addr->traffic_class_bits = 0;
    addr->flow_label = 0;
    addr->next_header = 0x3A;
    addr->hop_limit = 0xFF;
    net_packet->total_bytes += 8;
    net_packet->fragments[net_packet->fragment_count].length = 8;
    set_value_and_enable(&net_packet->fragments[net_packet->fragment_count].buffer, &message);
    net_packet->fragment_count += 1;
    message.header.type = 0x85;
    message.header.code = 0;
    message.header.reserved = 0;
    message.header.checksum = 0;
    message.header.checksum = calc_ipv6_pseudo_header_checksum(&addr->source, &addr->destination, addr->next_header, net_packet, 1);
    return ipv6_transmit(net_packet, addr, id, NULL);
}
#pragma pop

static inline saddr send_pending_packet(Ipv6NdNeighbor *e) {
    NetPacket *nw;
    nw = alloc_free_entry();
    if (nw == 0) {
        return (saddr)e;
    }
    nw->fragment_count = 0;
    nw->total_bytes = e->pending->len;
    nw->fragments[nw->fragment_count].length = e->pending->len;
    set_value_and_enable(&nw->fragments[nw->fragment_count].buffer, e->pending->data);
    nw->fragment_count++;
    ipv6_transmit(nw, &e->pending->params, e->iface, e->lladdr);
    release_entry(nw);
    return 1;
}

Ipv6NdNeighbor *NetIPv6UpdateNeighborLinkAddress(void *addr, void *lladdr, s16 lladdr_len, s16 iface) {
    s32 n;
    Ipv6NdNeighbor *e;


    if (addr == 0) {
        return 0;
    }
    if (lladdr_len == 0 || lladdr == 0) {
        return 0;
    }
    e = NetIPv6FindOrSelectNeighborCacheEntry(addr, lladdr, lladdr_len);
    if (e == 0) {
        return 0;
    }
    switch (e->match) {
    case 0:
        e->used = 1;
    case 1:
        NetMemcpy(e->addr, addr, 0x10);
        n = lladdr_len;
        if ((u32)n > 0x20) {
            n = 0x20;
        }
        e->lladdr_len = n;
        NetMemcpy(e->lladdr, lladdr, e->lladdr_len);
        e->nud = 2;
        e->timer = ipv6_neighbor_discovery_state.stale_time;
        e->iface = iface;
        break;
    case 2:
        n = lladdr_len;
        if ((u32)n > 0x20) {
            n = 0x20;
        }
        e->lladdr_len = n;
        NetMemcpy(e->lladdr, lladdr, e->lladdr_len);
        if (e->nud == 0 && e->pending != 0) {
            send_pending_packet(e);
            e->pending->used = 0;
            e->pending = 0;
        }
        e->nud = 2;
        e->timer = ipv6_neighbor_discovery_state.stale_time;
        e->iface = iface;
        break;
    case 3:
        e->iface = iface;
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

Ipv6NdRouter *NetIPv6SelectDefaultRouter(void *right) {
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
            if (NetMemcmp(e->addr, right, 0x10) == 0) {
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

extern s32 NetIPv6UpdateRouterEntry(void *addr, NetIcmpv6RouterAdvertisement *ra, s16 iface) {
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

static inline Ipv6NdNeighbor *find_pending_owner(Ipv6NdState *g, Ipv6NdPending *e) {
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

Ipv6NdPending *NetIPv6SelectPendingPacketSlot(void) {
    Ipv6NdPending *free_;
    Ipv6NdState *g = &ipv6_neighbor_discovery_state;
    s16 v;
    s16 n;
    Ipv6NdPending *e;
    Ipv6NdPending *best;
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
    r = find_pending_owner(g, best);
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
