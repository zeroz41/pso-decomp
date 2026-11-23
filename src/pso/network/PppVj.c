/* Van Jacobson TCP/IP header compression (a C library, built with GC/1.2.5n). PppVj is an inferred name, from
 * the vj_ helpers it calls. */
#include "types.h"
#include "pso/network/TLobby_803FC178.h"
#include "pso/network/TLobby_803FCF44.h"
#include "pso/network/TLobby_804050DC.h"
#include "pso/network/TLobby_8041112C.h"
#include "pso/network/NetworkRuntime.h"
#include "pso/network/TLobby_804048E8.h"
#include "pso/network/NetworkTransport.h"

#include "pso/network/NetStackTypes.h"

#include "pso/network/PppBuffer.h"

u8 lbl_805D7AC4[1];
u8 lbl_805D7AC0[2];

s16 TLobby__sub_80403F4C(PppVjCompressionState *o, PppFrame **spp) {
    A_80403F4C a;
    B_80403F4C b;
    PppVjConnectionState *e;
    u8 c;

    TLobby__sub_803FEA88(&a, spp);
    TLobby__sub_804053B8(&b, spp);
    c = a.proto;
    if (c > o->max) {
        o->n30++;
        if (o == NULL) {
            return 0;
        }
        o->flags |= 1;
        return 0;
    }
    e = &o->ents[c];
    o->cur = c;
    o->flags &= ~1;
    a.proto = 6;
    e->a = a;
    e->b = b;
    *spp = TLobby__sub_8040555C(&b, *spp, NULL);
    *spp = NetIPv4WriteHeader(&a, *spp, 1);
    o->n28++;
    return (s16)(s64)get_field_4(*spp);
}

#pragma push
#pragma dont_inline off
#pragma inline_depth(4)
inline s32 vj_buffer_valid(PppFrame **src) {
    s32 valid = 0;
    if (src != NULL && *src != NULL) {
        valid = 1;
    }
    return valid;
}
inline s32 vj_read_byte(PppFrame **src) {
    if (ppp_buffer_read(src, lbl_805D7AC4, 1) != 1) {
        return -1;
    }
    return (s16)lbl_805D7AC4[0];
}
inline s32 vj_next_byte(PppFrame **src) {
    s32 fast = 0;
    if (vj_buffer_valid(src) && (*src)->len > 1) {
        fast = 1;
    }
    if (fast) {
        (*src)->len--;
        return *(*src)->data++;
    }
    return vj_read_byte(src);
}
inline s32 vj_read_u16(PppFrame **src) {
    if (ppp_buffer_read(src, lbl_805D7AC0, 2) != 2) {
        return -1;
    }
    return read_network_u16_be(lbl_805D7AC0);
}
s16 TLobby__sub_804040E0(PppVjCompressionState *comp, PppFrame **src) {
    B_80403F4C *th;
    PppVjConnectionState *cs;
    s16 changes;
    s32 v;
    s16 len;

    comp->n2C++;
    if ((u16)get_field_4(*src) < 3) {
        comp->n30++;
        return 0;
    }
    changes = vj_next_byte(src);
    if (changes & 0x40) {
        v = vj_next_byte(src);
        if (v < 0 || v > comp->max) {
            goto bad;
        }
        comp->flags &= ~1;
        comp->cur = v;
    } else if (comp->flags & 1) {
        comp->n34++;
        return 0;
    }
    if (comp->cur > comp->max) {
        comp->n34++;
        return 0;
    }
    th = &(cs = &comp->ents[comp->cur])->b;
    v = vj_read_u16(src);
    if (v == -1) {
        goto bad;
    }
    th->checksum = v;
    th->psh = (changes & 0x10) ? 1 : 0;
    switch (changes & 0xF) {
    case 0xB: {
        s16 i = cs->a.len;
        i -= cs->a.optlen + 40;
        th->ack += i;
        th->seq += i;
        break;
    }
    case 0xF:
        th->seq += cs->a.len - (cs->a.optlen + 40);
        break;
    default:
        if (changes & 1) {
            th->urg = 1;
            v = vj_next_byte(src);
            if (v == 0) {
                v = vj_read_u16(src);
            }
            if (v == -1) {
                goto bad;
            }
            th->urgent = v;
        } else {
            th->urg = 0;
        }
        if (changes & 2) {
            v = vj_next_byte(src);
            if (v == 0) {
                v = vj_read_u16(src);
            }
            if (v == -1) {
                goto bad;
            }
            th->window += (s16)v;
        }
        if (changes & 4) {
            v = vj_next_byte(src);
            if (v == 0) {
                v = vj_read_u16(src);
            }
            if (v == -1) {
                goto bad;
            }
            th->ack += v;
        }
        if (changes & 8) {
            v = vj_next_byte(src);
            if (v == 0) {
                v = vj_read_u16(src);
            }
            if (v == -1) {
                goto bad;
            }
            th->seq += v;
        }
        break;
    }
    if (changes & 0x20) {
        v = vj_next_byte(src);
        if (v == 0) {
            v = vj_read_u16(src);
        }
        if (v == -1) {
            goto bad;
        }
        cs->a.id += v;
    } else {
        cs->a.id++;
    }
    len = get_field_4(*src) + 40 + cs->a.optlen;
    cs->a.len = len;
    *src = TLobby__sub_8040555C(th, *src, NULL);
    *src = NetIPv4WriteHeader(&cs->a, *src, 0);
    return len;

bad:
    comp->n30++;
    if (comp == NULL) {
        return 0;
    }
    comp->flags |= 1;
    return 0;
}
#pragma pop

