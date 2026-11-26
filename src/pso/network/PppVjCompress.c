/* The network stack's connection list (a C library, built with GC/1.2.5n): the list header and its two pools of
 * 0x8C-byte nodes, the second chained into a free list. */
#include "types.h"
#include "pso/network/Ppp.h"
#include "pso/network/PppVj.h"
#include "pso/network/NetArp.h"
#include "pso/network/PppBuffer.h"
#include "pso/network/NetworkRuntime.h"

#pragma push
#pragma cplusplus on
PppVjCompressionState vj_comp;
PppVjConnectionState vj_rstate[16];
PppVjConnectionState vj_tstate[16];
u8 vj_new_seq[16];
#pragma pop


#pragma push
#pragma dont_inline off
#pragma inline_depth(4)
static inline u8 *vj_encode(u8 *cp, u32 n) {
    if ((u16)n >= 256 || (u16)n == 0) {
        *cp++ = 0;
        cp = write_network_u16_be(cp, n);
    } else {
        *cp++ = (s8)(u16)n;
    }
    return cp;
}

s32 sl_compress_tcp(PppVjCompressionState *state, PppFrame **frame, s16 compress_cid) {
    PppVjConnectionState *cs;
    PppVjConnectionState *lastcs;
    PppVjConnectionState *lcs;
    ParsedTcpHeader *oth;
    u32 deltaS;
    u32 deltaA;
    s16 changes;
    u8 *cp;
    s32 hlen;
    ParsedTcpHeader b;
    ParsedIpHeader a;

    cp = vj_new_seq;
    changes = 0;
    lastcs = &state->tstate[state->last_cs];
    cs = lastcs->next;
    lcs = lastcs;
    hlen = NetIPv4ReadHeader(&a, frame);
    if (a.proto != 6 || a.frag != 0 || a.mf != 0) {
        if (a.proto != 6) {
            state->out_not_tcp++;
        } else {
            state->out_not_compressible++;
        }
        *frame = NetIPv4WriteHeader(&a, *frame, 1);
        return 0x40;
    }
    hlen += NetTcpReadHeader(&b, frame);
    if (b.syn || b.fin || b.rst || !b.ack_flag) {
        state->out_not_compressible++;
        *frame = NetTcpWriteHeader(&b, *frame, NULL);
        *frame = NetIPv4WriteHeader(&a, *frame, 1);
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
        state->searches++;
    }
    state->misses++;
    state->last_cs = lcs->id;
    goto uncompressed;

found:
    if (lcs != lastcs) {
        if (cs == lastcs) {
            state->last_cs = lcs->id;
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
            cp = vj_new_seq;
        }
        break;
    case 8:
        if (deltaS == cs->a.len - (s16)hlen) {
            changes = 15;
            cp = vj_new_seq;
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
    deltaS = cp - vj_new_seq;
    if (compress_cid == 0 || state->last_xmit != cs->id) {
        cp = (*frame = alloc_from_buffer(*frame, deltaS + 4))->data;
        *cp++ = changes | 0x40;
        *cp++ = cs->id;
        state->last_xmit = cs->id;
    } else {
        cp = (*frame = alloc_from_buffer(*frame, deltaS + 3))->data;
        *cp++ = (s8)changes;
    }
    cp = write_network_u16_be(cp, deltaA);
    NetMemcpy(cp, vj_new_seq, (s16)deltaS);
    state->out_compressed++;
    return 0x80;

uncompressed:
    a.proto = cs->id;
    cs->a = a;
    cs->b = b;
    state->last_xmit = cs->id;
    state->out_uncompressed++;
    *frame = NetTcpWriteHeader(&b, *frame, NULL);
    *frame = NetIPv4WriteHeader(&a, *frame, 1);
    return 0x70;
}
#pragma pop

void vj_release_state(PppVjCompressionState *state) {
    if (state == NULL) {
        return;
    }
}

PppVjCompressionState *init_net_list(s16 count1, s16 count2) {
    PppVjConnectionState *base;
    s16 i;
    PppVjCompressionState *p = &vj_comp;

    if (count1 > 0 && count1 <= 0x10) {
        p->rstate = vj_rstate;
        p->max = count1 - 1;
    }
    if (count2 > 0 && count2 <= 0x10) {
        p->tstate = vj_tstate;
        p->max_tx = count2 - 1;
    }
    p->last_cs = 0;
    p->last_xmit = 0xFF;
    p->cur = 0xFF;
    if (count2 > 0) {
        base = p->tstate;
        for (i = p->max_tx; i > 0; i--) {
            base[i].id = i;
            base[i].next = &base[i - 1];
        }
        base[0].next = &base[p->max_tx];
        base[0].id = 0;
    }
    return p;
}

NetThreadState net_thread_state;
