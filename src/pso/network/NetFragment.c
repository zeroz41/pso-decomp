#include "types.h"
#include "pso/network/BufferRef.h"
#include "pso/network/IPv6Send.h"
#include "pso/network/NetStackTypes.h"
#include "pso/network/NetworkDispatch.h"
#include "pso/network/netcfg.h"
#include "pso/network/TLobby_804050DC.h"
#include "pso/network/TLobby_8041112C.h"

s32 init_packet_fragment_pools(void);


NetFragPacket *TLobby__sub_8041955C(NetworkAddress *src, s32 ident, u8 ttl);
s32 TLobby__sub_80419470(NetworkAddress *src, u32 ident);
s16 TLobby__sub_80419374(NetFragPacket *pkt);
s32 TLobby__sub_8041979C(void);
saddr reassemble_fragment_packet(NetFragPacket *node, u8 *self, u16 hdr_len, u16 frag_off, u16 frag_len, u8 more, s16 iface);

/* Inline the helpers below; this applies to the rest of the file. */
#pragma dont_inline off
#pragma inline_depth(4)

s32 TLobby__sub_80418A7C(void) {
    NetFragPool *g = &packet_fragment_pool_state;
    NetUnregisterTimer(update_timeout_entries);
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
    NetRegisterTimer(1000, 1, update_timeout_entries);
    return 0;
}

/* Frees the buffers of a packet's fragments. */
s32 release_packet_fragments(NetPacket *a) {
    u32 i;
    NetPacket *b = a;
    for (i = 0; i < b->fragment_count; i++) {
        TLobby__sub_80406B6C(&b->fragments[i].buffer);
    }
    return 0;
}

s32 fragment_input(u8* self, u16 hdr_len, s16 frag_len, u8 ttl, u32 ident, NetworkAddress* src, u16 frag_off, u8 more, s16 iface)
{
    NetFragPacket *TLobby__sub_8041955C(NetworkAddress *, s32, u8); /* declared here with other parameter types; the definition is NetFragPacket * (NetworkAddress *, s32, s32) */
    NetFragPool* base = &packet_fragment_pool_state;
    s16 count;
    s32 ret;
    NetFragPacket* node;

    count = 0;
    node = base->head;
    while (node != NULL && count < base->npackets) {
        if (compare_sockaddr(&node->src, src) == 0 && node->ident == ident) {
            ret = reassemble_fragment_packet(node, self, hdr_len, frag_off, frag_len, more, iface);
            if (ret == 0) {
                return 0;
            }
            TLobby__sub_80419470(src, ident);
            return ret;
        }
        node = node->next;
        count++;
    }
    node = TLobby__sub_8041955C(src, ident, ttl);
    if (node == NULL) {
        return 0;
    }
    ret = reassemble_fragment_packet(node, self, hdr_len, frag_off, frag_len, more, iface);
    if (ret == 0) {
        return 0;
    }
    TLobby__sub_80419470(src, ident);
    return ret;
}

inline NetFragment *frag_pool_take_entry(NetFragment **pb, s16 *pn) {
    s16 n;
    s16 i;
    NetFragment *ent;
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
inline s16 frag_chain_contig_check(NetFragPacket *node, s16 *pn, NetFragPool *g) {
    s16 lim;
    NetFragment *f;
    u32 acc;
    s16 n;
    s16 cnt;
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
   packet once every fragment is there, else 0.  f is the second fragment where the search for the new one's place
   starts, then walks the fragments to copy them into the packet.  pkt holds the chain's last fragment until the
   packet is allocated. */
saddr reassemble_fragment_packet(NetFragPacket *node, u8 *self, u16 hdr_len, u16 frag_off, u16 frag_len, u8 more, s16 iface) {
    NetBufferRef src;
    s16 i;
    NetFragment *f;
    s16 first_len;
    s16 *nfrags;
    NetFragment *frag;
    NetPacket *pkt;
    u32 cur_off;
    NetFragment *first;
    NetFragment **pool_frags;
    NetPacketFragment *second;
    u32 off;
    NetFragment *cur;
    NetFragment *next;
    s32 len;
    s16 slot;
    NetFragPool *g = &packet_fragment_pool_state;
    NetFragment **frags;
    s32 total;
    s16 cnt;

    if (frag_off == 0) {
        node->hdr_len = hdr_len;
        node->iface = iface;
    } else {
        self += hdr_len;
    }
    pool_frags = &g->frags;
    if ((frag = frag_pool_take_entry(frags = pool_frags, nfrags = &g->nfrags)) == 0) {
        reset_other_connection_lists(node);
        if ((frag = frag_pool_take_entry(frags, nfrags)) == 0) {
            return 0;
        }
    }
    frag->offset = frag_off;
    frag->len = frag_len;
    set_value_and_enable(&src, (saddr)self);
    if (frag_off == 0) {
        first_len = (total = frag_len + hdr_len);
        if (TLobby__sub_80415954(&frag->data, first_len, 2) < 0) {
            reset_other_connection_lists(node);
            if (TLobby__sub_80415954(&frag->data, first_len, 2) < 0) {
                frag->used = 0;
                frag->next = 0;
                return 0;
            }
        }
        netbuf_copy_by_ref(&frag->data, &src, total);
    } else {
        len = frag_len;
        if (TLobby__sub_80415954(&frag->data, len, 2) < 0) {
            reset_other_connection_lists(node);
            if (TLobby__sub_80415954(&frag->data, len, 2) < 0) {
                frag->used = 0;
                frag->next = 0;
                return 0;
            }
        }
        netbuf_copy_by_ref(&frag->data, &src, frag_len);
    }
    frag->next = 0;
    first = node->first;
    if (first == 0) {
        node->last = frag;
        node->first = frag;
    } else {
        pkt = (NetPacket *)node->last;
        off = frag->offset;
        if (off > ((NetFragment *)pkt)->offset) {
            ((NetFragment *)pkt)->next = frag;
            node->last = frag;
        } else if (off < first->offset) {
            frag->next = first;
            node->first = frag;
        } else {
            f = first->next;
            cnt = *nfrags;
            cur = first;
            next = f;
            if (f == 0) {
                TLobby__sub_80406B6C(&frag->data);
                frag->used = 0;
                frag->next = 0;
                return 0;
            }
            while (next != 0 && cnt > 0) {
                cur_off = cur->offset;
                if (off > cur_off && off < next->offset) {
                    frag->next = next;
                    cur->next = frag;
                    break;
                }
                if (off == cur_off) {
                    TLobby__sub_80406B6C(&frag->data);
                    frag->used = 0;
                    frag->next = 0;
                    break;
                }
                cur = cur->next;
                cnt--;
                next = next->next;
            }
        }
    }
    if (node->have_last == 0) {
        if (more != 0) {
            return 0;
        }
        node->have_last = 1;
    }
    if (frag_chain_contig_check(node, nfrags, g) < 0) {
        return 0;
    }
    pkt = (NetPacket *)alloc_free_entry();
    if (pkt == 0) {
        TLobby__sub_8041979C();
        return 0;
    }
    pkt->fragment_count = 0;
    pkt->total_bytes = 0;
    second = &pkt->fragments[1];
    slot = 0;
    i = 0;
    f = node->first;
    cnt = *nfrags;
    while (f != 0 && cnt > 0) {
        if (i == 0) {
            NetMemcpy(&pkt->fragments[0].buffer, &f->data, 8);
            pkt->fragment_count = 1;
            i++;
            pkt->total_bytes = node->hdr_len;
            pkt->fragments[0].length = node->hdr_len;
            NetMemcpy(&second->buffer, &f->data, 8);
            pkt->fragment_count += 1;
            pkt->total_bytes += f->len;
            second->length = f->len;
            slot = 2;
            netbuf_ref_advance(&second->buffer, node->hdr_len);
        } else {
            NetMemcpy(&pkt->fragments[slot].buffer, &f->data, 8);
            pkt->fragment_count += 1;
            pkt->total_bytes += f->len;
            pkt->fragments[i].length = f->len;
            slot++;
        }
        cur = f;
        f = f->next;
        cur->used = 0;
        cnt--;
        i++;
        cur->next = 0;
    }
    return (saddr)pkt;
}

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
s16 TLobby__sub_80419374(NetFragPacket *pkt) {
    u8 *q;
    s32 type;
    s16 total;

    if (pkt->first == NULL) {
        return 0;
    }
    if (pkt->first->offset != 0) {
        return 0;
    }
    q = netbuf_ref_data(&pkt->first->data);
    if (q == NULL) {
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
        return icmp_send_error((u8 *)&msg, q, total, pkt->iface);
    }
    case 6: {
        NetIcmpv6Header msg;
        msg.type = 3;
        msg.code = 1;
        msg.reserved = 0;
        return icmp6_send_error(&msg, q, total, pkt->iface);
    }
    default:
        return -1;
    }
}

s32 TLobby__sub_80419470(NetworkAddress *src, u32 ident) {
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
        if (compare_sockaddr(&node->src, src) == 0 && node->ident == ident) {
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

#pragma push
#pragma opt_propagation off
/* Takes a free datagram for (src, ident), freeing everything else if none is left, and appends it to the list. */
NetFragPacket *TLobby__sub_8041955C(NetworkAddress *src, s32 ident, u8 ttl) {
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
    while (i < count) {
        if (e->used == 0) {
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
    if (e == 0) {
        TLobby__sub_8041979C();
        e = *ent;
        n2 = base->npackets;
        i = 0;
        while (i < n2) {
            if (e->used == 0) {
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
        if (!e) {
            return 0;
        }
    }

    t = &base->head;
    if (*t == 0) {
        base->tail = e;
        *t = e;
    } else {
        base->tail->next = e;
        base->tail = e;
    }
    NetMemcpy(&e->src, src, sizeof(NetworkAddress));
    e->ident = ident;
    e->have_last = 0;
    e->ttl = (u8)ttl;
    e->next = 0;
    e->last = 0;
    e->first = 0;
    r = e;
    return r;
}
#pragma pop
/* Frees every other datagram being reassembled to make room for self, which becomes the only one in the list. */
s32 reset_other_connection_lists(NetFragPacket *self) {
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

u16 ones_complement_sum(void *data, s16 n) {
    u8 *p = data;
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
    if ((uaddr)p & 1) {
        ((u8*)tmp)[1] = *p;
        p++;
        n--;
        odd = 1;
    }
    while (n > 0) {
        if ((((uaddr)p & 0xF) == 0) && (n >= 8)) {
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
            u16 *w = (u16 *)p;
            sum += w[4];
            sum += w[1];
            sum += w[2];
            sum += w[3];
            sum += w[8];
            sum += w[5];
            sum += w[6];
            sum += w[7];
            p += 16;
            n -= 8;
        }
        p += 2;
    }
    while (n >= 8) {
        u16 *w = (u16 *)p;
        sum += w[0];
        sum += w[1];
        sum += w[2];
        sum += w[3];
        sum += w[4];
        sum += w[5];
        sum += w[6];
        sum += w[7];
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
