/* The network stack's connection list (a C library, built with GC/1.2.5n): the list header and its two pools of
 * 0x8C-byte nodes, the second chained into a free list. */
#include "types.h"
#include "pso/network/TLobby_804048E8.h"

typedef struct Node_80405008 {
    u8 id;
    u8 pad1[3];
    struct Node_80405008 *next;
    u8 rest[0x84];
} Node_80405008;

typedef struct List_80405008 {
    Node_80405008 *list;
    Node_80405008 *list2;
    u8 n2;
    u8 n1;
    u8 a;
    u8 b;
    u8 c;
    u8 pad[0x2B];
} List_80405008;

#pragma push
#pragma cplusplus on
u32 lbl_805C06D8[14];
u32 lbl_805C0710[560];
u32 lbl_805C0FD0[560];
u32 lbl_805C1890[4];
#pragma pop

s32 TLobby__sub_804053B8(B_80403F4C *, Strm_80405A74 **);
u8 *TLobby__sub_8040555C(B_80403F4C *, u8 *, s32);
u8 *GXLoadTexObjPreLoaded(A_80403F4C *, u8 *, s32);
u8 *write_network_u16_be(u8 *p, u16 v);
s32 NetMemcmp(void *, void *, int);
void NetMemcpy(void *, void *, int);
u8 *alloc_from_buffer(void *self, s16 arg1);

#pragma push
#pragma dont_inline off
#pragma inline_depth(4)
#pragma opt_common_subs on
inline u8 *vj_encode(u8 *cp, u32 n) {
    if ((u16)n >= 256 || (u16)n == 0) {
        *cp++ = 0;
        cp = write_network_u16_be(cp, n);
    } else {
        *cp++ = (s8)(u16)n;
    }
    return cp;
}

s32 TLobby__sub_804048E8(Obj_80403F4C *comp, Strm_80405A74 **m, s16 compress_cid) {
    Ent_80403F4C *cs;
    Ent_80403F4C *lastcs;
    Ent_80403F4C *lcs;
    B_80403F4C *oth;
    u32 deltaS;
    u32 deltaA;
    s16 changes;
    u8 *cp;
    s32 hlen;
    B_80403F4C b;
    A_80403F4C a;

    cp = (u8 *)lbl_805C1890;
    changes = 0;
    lastcs = &comp->tstate[comp->last_cs];
    cs = lastcs->next;
    lcs = lastcs;
    hlen = TLobby__sub_803FEA88(&a, m);
    if (a.proto != 6 || a.frag != 0 || a.mf != 0) {
        if (a.proto != 6) {
            comp->n10++;
        } else {
            comp->n14++;
        }
        *m = (Strm_80405A74 *)GXLoadTexObjPreLoaded(&a, (u8 *)*m, 1);
        return 0x40;
    }
    hlen += TLobby__sub_804053B8(&b, m);
    if (b.syn || b.fin || b.rst || !b.ack_flag) {
        comp->n14++;
        *m = (Strm_80405A74 *)TLobby__sub_8040555C(&b, (u8 *)*m, 0);
        *m = (Strm_80405A74 *)GXLoadTexObjPreLoaded(&a, (u8 *)*m, 1);
        return 0x40;
    }
    for (;;) {
        if (a.src == cs->a.src && a.dst == cs->a.dst && b.src_port == cs->b.src_port &&
            b.dst_port == cs->b.dst_port) {
            goto found;
        }
        if (cs == lastcs) {
            break;
        }
        lcs = cs;
        cs = cs->next;
        comp->n20++;
    }
    comp->n24++;
    comp->last_cs = lcs->id;
    goto uncompressed;

found:
    if (lcs != lastcs) {
        if (cs == lastcs) {
            comp->last_cs = lcs->id;
        } else {
            lcs->next = cs->next;
            cs->next = lastcs->next;
            lastcs->next = cs;
        }
    }

    oth = &cs->b;
    if (a.version != cs->a.version || a.optlen != cs->a.optlen || a.tos != cs->a.tos ||
        a.df != cs->a.df || a.ttl != cs->a.ttl || b.option_len != cs->b.option_len ||
        (a.optlen != 0 && NetMemcmp(a.opts, cs->a.opts, a.optlen) != 0) ||
        (b.option_len != 0 && NetMemcmp(b.options, cs->b.options, b.option_len) != 0)) {
        goto uncompressed;
    }

    if (b.urg) {
        cp = vj_encode(cp, b.urgent);
        changes |= 1;
    } else if (b.urgent != oth->urgent) {
        goto uncompressed;
    }
    if ((deltaS = b.window - oth->window) != 0) {
        cp = vj_encode(cp, deltaS);
        changes |= 2;
    }
    if ((deltaA = b.ack - oth->ack) != 0) {
        if (deltaA > 0xFFFF) {
            goto uncompressed;
        }
        cp = vj_encode(cp, deltaA);
        changes |= 4;
    }
    if ((deltaS = b.seq - oth->seq) != 0) {
        if (deltaS > 0xFFFF) {
            goto uncompressed;
        }
        cp = vj_encode(cp, deltaS);
        changes |= 8;
    }

    switch (changes) {
    case 0:
        if (a.len != cs->a.len && cs->a.len == (s16)hlen) {
            break;
        }
        goto uncompressed;
    case 11:
    case 15:
        goto uncompressed;
    case 12:
        if (deltaS == deltaA && deltaS == cs->a.len - (s16)hlen) {
            changes = 11;
            cp = (u8 *)lbl_805C1890;
        }
        break;
    case 8:
        if (deltaS == cs->a.len - (s16)hlen) {
            changes = 15;
            cp = (u8 *)lbl_805C1890;
        }
        break;
    }

    deltaS = a.id - cs->a.id;
    if (deltaS != 1) {
        cp = vj_encode(cp, deltaS);
        changes |= 0x20;
    }
    if (b.psh) {
        changes |= 0x10;
    }
    deltaA = b.checksum;
    cs->a = a;
    cs->b = b;
    deltaS = cp - (u8 *)lbl_805C1890;
    if (compress_cid == 0 || comp->last_xmit != cs->id) {
        cp = (*m = (Strm_80405A74 *)alloc_from_buffer(*m, deltaS + 4))->p;
        *cp++ = changes | 0x40;
        *cp++ = cs->id;
        comp->last_xmit = cs->id;
    } else {
        cp = (*m = (Strm_80405A74 *)alloc_from_buffer(*m, deltaS + 3))->p;
        *cp++ = (s8)changes;
    }
    cp = write_network_u16_be(cp, deltaA);
    NetMemcpy(cp, lbl_805C1890, (s16)deltaS);
    comp->n1C++;
    return 0x80;

uncompressed:
    a.proto = cs->id;
    cs->a = a;
    cs->b = b;
    comp->last_xmit = cs->id;
    comp->n18++;
    *m = (Strm_80405A74 *)TLobby__sub_8040555C(&b, (u8 *)*m, 0);
    *m = (Strm_80405A74 *)GXLoadTexObjPreLoaded(&a, (u8 *)*m, 1);
    return 0x70;
}
#pragma pop

void TLobby__sub_80405000(u32 mode) {
    if (mode == 0) {
        return;
    }
}

s32 init_net_list(s16 count1, s16 count2) {
    Node_80405008 *n;
    Node_80405008 *base;
    s16 i;
    List_80405008 *p = (List_80405008 *)lbl_805C06D8;

    if (count1 > 0 && count1 <= 0x10) {
        p->list2 = (Node_80405008 *)lbl_805C0710;
        p->n1 = count1 - 1;
    }
    if (count2 > 0 && count2 <= 0x10) {
        p->list = (Node_80405008 *)lbl_805C0FD0;
        p->n2 = count2 - 1;
    }
    p->a = 0;
    p->b = 0xFF;
    p->c = 0xFF;
    if (count2 > 0) {
        base = p->list;
        n = &base[(s16)p->n2];
        i = p->n2;
        while (i > 0) {
            n->id = i;
            n->next = &base[i - 1];
            n--;
            i--;
        }
        base->next = &base[p->n2];
        base->id = 0;
    }
    return (s32)p;
}

u32 lbl_805C1AB0[0x28 / 4];
u8 lbl_805C18B0[0x200];
u32 lbl_805C18A0[4];
