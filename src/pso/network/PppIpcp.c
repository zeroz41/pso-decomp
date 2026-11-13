/* PPP IPCP, the protocol that names itself "IPcp" (805E1170), and its state object (.bss 805C0328) (a C
 * library, built with GC/1.2.5n). */
#include "types.h"
#include "pso/network/TLobby_803FC178.h"
#include "pso/network/TLobby_803FCF44.h"
#include "pso/network/TLobby_804050DC.h"
#include "pso/network/TLobby_8041112C.h"
#include "pso/network/PppIpcp.h"
typedef struct Self_803FF698 Self_803FF698;
typedef struct P_803FF48C P_803FF48C;
/* This file's functions. */
void free_field_98(void *self);
void free_field_98_and_clear(void *self);
u16 get_field_4(void *self);
s32 read_2_bytes(void *self, void *src);
s32 set_flags_and_state(void *self);
u8 *write_network_u32_be(u8 *p, u32 v);
#include "pso/network/NetworkRuntime.h"
#include "pso/network/TLobby_804048E8.h"
extern s32 is_timed_out(void);
#include "pso/network/NetworkTransport.h"

extern IpcpState lbl_805C0328;

struct Self_803FF698 { u8 f0; u8 f1; u8 pad2[0x2E]; IpcpConfig *f30; };

#include <stddef.h>
#include "pso/network/NetStackTypes.h"

extern u8 lbl_805C0038[];
void TLobby__sub_803F97E8(int);
#include "pso/network/PppBuffer.h"

extern s32 lbl_805D7AA0;
s16 TLobby__sub_803FED78(u8 *self) {
    u8 *p;
    NetThreadState *pd;
    u8 *obj;
    s16 st;
    s16 *ps;
    s16 check_connection_status(void *); /* declared s16 here; the definition returns s32 */
    st = 1;
    obj = *(u8 **)(self + 0xc);
    *(s16 *)(self + 8) = 0;
    ps = (s16 *)(lbl_805C0038 + 0xd4);
    ps[4] = 0;
    p = (u8 *)ps;
    pd = &lbl_805C18A0;
    goto test;
    while (1) {
        if (is_timed_out() != 0 || obj[0] == 4) {
            update_connection_state((int)(self));
            *(s16 *)(self + 8) = 0;
            *(s16 *)(p + 8) = 0;
            return -1;
        }
        if (*(s16 *)(self + 8) != 0) goto after;
        st = check_connection_status((void *)p);
        unlock_mutex(pd->mutex);
        TLobby__sub_803F97E8(0x64);
        process_expired_timers();
        lock_mutex(pd->mutex);
test:
        if (self[0] == 5) goto after;
        if (lbl_805D7AA0 >= 2) goto after;
    }
after:
    if (lbl_805D7A7C != 6 && (s16)(s32)lbl_805D7A7C) {
        if (*(s16 *)(self + 8) != 0) {
            *(s16 *)(p + 8) = 0;
            *(s16 *)(self + 8) = 0;
            return -1;
        }
        *(s16 *)(p + 8) = 0;
        *(s16 *)(self + 8) = 0;
        return 0;
    }
    pd = &lbl_805C18A0;
    while (st > 0) {
        st = check_connection_status((void *)p);
        unlock_mutex(pd->mutex);
        TLobby__sub_803F97E8(0x64);
        process_expired_timers();
        lock_mutex(pd->mutex);
    }
    switch (st) {
    case 0:
        *(s16 *)(self + 8) = 0;
        *(s16 *)(p + 8) = 0;
        return 0;
    case -2:
        if (*(s16 *)(self + 8) == 0) {
            *(s16 *)(self + 8) = 0;
            *(s16 *)(p + 8) = 0;
            return 0;
        }
        break;
    }
    update_connection_state((int)(self));
    *(s16 *)(p + 8) = 0;
    *(s16 *)(self + 8) = 0;
    return -1;
}

struct P_803FF48C;
void TLobby__sub_803FF48C(P_803FF48C *);
extern s32 TLobby__sub_803FF50C(Self_803FF698 *self, u8 *item, s32 arg);
extern s32 TLobby__sub_803FF698(Self_803FF698 *self, u8 *item, s32 arg);
extern s32 TLobby__sub_803FF9A4(void *self, u8 *src, u32 bits);
extern PppFrame *TLobby__sub_80400174(void *self);
void TLobby__sub_803FEF4C(u8 *self) {
    IpcpOptions *src = (IpcpOptions *)lbl_8047FE18;
    u8 *o = (u8 *)&lbl_805C0328;
    u8 *sub;
    u8 *p;
    *(u32 *)o = (u32)&lbl_805E1170;
    sub = self + 0x6c;
    p = o + 0x3c;
    *(u16 *)(o + 0x4) = 0x8021;
    *(s16 *)(o + 0x6) = 0xfe;
    o[0x8] = 2;
    o[0x9] = 0x14;
    o[0xa] = 10;
    o[0xb] = 10;
    *(u32 *)(o + 0xc) = 0xbb8;
    *(void **)(o + 0x10) = (void *)free_field_98;
    *(void **)(o + 0x14) = (void *)TLobby__sub_803FF48C;
    *(void **)(o + 0x18) = (void *)TLobby__sub_803FF374;
    *(void **)(o + 0x1c) = (void *)TLobby__sub_803FF384;
    *(void **)(o + 0x20) = (void *)free_field_98_and_clear;
    *(void **)(o + 0x24) = (void *)TLobby__sub_803FF468;
    *(void **)(o + 0x28) = (void *)TLobby__sub_80400174;
    *(void **)(o + 0x2c) = (void *)TLobby__sub_803FF9A4;
    *(void **)(o + 0x30) = (void *)TLobby__sub_803FF858;
    *(void **)(o + 0x34) = (void *)TLobby__sub_803FF698;
    *(void **)(o + 0x38) = (void *)TLobby__sub_803FF50C;
    *(u8 **)(sub + 0xc) = self;
    *(u8 **)(sub + 0x2c) = o;
    *(u8 **)(sub + 0x30) = p;
    ((IpcpState *)o)->config.local.want = *src;
    ((IpcpState *)o)->config.local.flags = 6;
    ((IpcpState *)o)->config.peer.want = *src;
    ((IpcpConfig *)p)->peer.got = *src;
    ((IpcpConfig *)p)->peer.flags = 6;
    TLobby__sub_803FD694(sub);
}

s32 ipcp_set_vj_compression(s16 disabled, IpcpSide *side) {
    if (disabled == 0) {
        side->want.vj_protocol = 0x2D;
        side->want.vj_slots = 0x10;
        side->want.vj_comp_slot = 1;
        side->want.flags |= 4;
        side->got.flags |= 4;
        side->flags |= 4;
    } else if (disabled != 0) {
        side->want.flags &= ~4;
        side->flags &= ~4;
        side->got.flags &= ~4;
    }
    return 0;
}

s32 ipcp_set_peer_secondary_dns(IpcpSide *side, s32 addr) {
    if (addr == -1) {
        side->want.dns[1] = 0;
        side->want.flags &= ~0x800;
    } else {
        side->want.dns[1] = addr;
        side->want.flags |= 0x800;
    }
    return 0;
}

s32 ipcp_set_peer_primary_dns(IpcpSide *side, s32 addr) {
    if (addr == -1) {
        side->want.dns[0] = 0;
        side->want.flags &= ~0x200;
    } else {
        side->want.dns[0] = addr;
        side->want.flags |= 0x200;
    }
    return 0;
}

s32 ipcp_set_local_secondary_dns(IpcpSide *side, s32 addr) {
    if (addr == -1) {
        side->want.dns[1] = 0;
        side->want.flags &= ~0x800;
    } else {
        side->want.dns[1] = addr;
        side->want.flags |= 0x800;
    }
    return 0;
}

s32 ipcp_set_local_primary_dns(IpcpSide *side, s32 addr) {
    if (addr == -1) {
        side->want.dns[0] = 0;
        side->want.flags &= ~0x200;
    } else {
        side->want.dns[0] = addr;
        side->want.flags |= 0x200;
    }
    return 0;
}

s32 ipcp_set_peer_address(IpcpSide *side, s32 addr) {
    if (addr == -1) {
        side->want.our_addr = 0;
        side->want.flags &= ~8;
    } else {
        side->want.our_addr = addr;
        side->want.flags |= 8;
    }
    return 0;
}

s32 ipcp_set_local_address(IpcpSide *side, s32 addr) {
    if (addr == -1) {
        side->want.our_addr = 0;
        side->want.flags &= ~8;
    } else {
        side->want.our_addr = addr;
        side->want.flags |= 8;
    }
    return 0;
}

s16 TLobby__sub_803FF304(u8 *lobby) {
    typedef struct Fields_arg0 { u8 pad_0[12]; u8 * field_C; } Fields_arg0;
    set_flags_and_state((void *)lobby);
    if ((u8) *((Fields_arg0*)lobby)->field_C == 3) {
        TLobby__sub_803FD958((u8 *)(lobby));
    }
    return 0;
}

void free_field_98(void *self) {
    u8 *arg0 = (u8 *)self;
    TLobby__sub_80405000((*(IpcpConfig **)(arg0 + 0x30))->net_list);
}

void TLobby__sub_803FF374(u8 *arg0) {
    *(s8 *)((s8 *)arg0 + 0xA) = 0;
    *(s8 *)((s8 *)arg0 + 0xB) = 0;
}

void TLobby__sub_803FF384(u8 *arg0) {
    IpcpConfig *p;
    s16 a;
    s16 b;
    a = 0;
    b = 0;
    p = *(IpcpConfig **)((s8 *)arg0 + 0x30);
    TLobby__sub_80405000(p->net_list);
    p->net_list = 0;
    if (p->local.got.flags & 4) {
        a = p->local.got.vj_slots;
    }
    if (p->peer.got.flags & 4) {
        b = p->peer.got.vj_slots;
    }
    if (a != 0 || b != 0) {
        p->net_list = init_net_list(a, b);
    }
    TLobby__sub_80405304(arg0 + 0x10);
    *(s8 *)((s8 *)arg0 + 0) = 5;
}

void free_field_98_and_clear(void *self) {
    u8 *arg0 = (u8 *)self;
    IpcpConfig *config;
    config = *(IpcpConfig **)(arg0 + 0x30);
    TLobby__sub_80405000(config->net_list);
    config->net_list = 0;
}

void TLobby__sub_803FF468(s32 arg0) {
    TLobby__sub_80405304((void *)((void *) (arg0 + 0x10)));
}

struct P_803FF48C { u8 pad[0x30]; IpcpConfig *q; };
void TLobby__sub_803FF48C(P_803FF48C *o) {
    IpcpConfig *q = o->q;
    q->local.got = q->local.want;
    q->local.got.his_addr = q->peer.want.our_addr;
    q->local.flags = q->local.flags | q->local.want.flags;
    q->peer.got.flags = 0;
    q->peer.flags = q->peer.flags | q->peer.want.flags;
}

inline u32 optbit_803FF50C(u32 bit) {
    s32 f;
    if (bit < 8) {
        return bit;
    }
    f = 0;
    if (bit >= 0x80 && bit < 0x90) {
        f = 1;
    }
    if (f) {
        bit -= 0x78;
    } else {
        bit = 0;
    }
    return bit;
}

inline u32 optbit_803FFB84(u16 bit) {
    if (bit < 8) {
        return bit;
    }
    return (bit >= 0x80 && bit < 0x90) ? bit - 0x78 : 0;
}
#pragma push
#pragma dont_inline off
#pragma inline_depth(4)
extern s32 TLobby__sub_803FF50C(Self_803FF698 *self, u8 *item, s32 arg) {
    IpcpConfig *bits = self->f30;
    s32 count = *(s16 *)(item + 2);
    s16 k;
    s32 r;
    u32 bit;
    s32 len;
    s32 pad;
    u8 hdr[2];

    if (item[1] != self->f1) {
        return -1;
    }
    while (count > 0 && (s16)read_2_bytes((void *)hdr, &arg) != -1) {
        len = hdr[1];
        count -= len;
        if (count < 0) {
            return -1;
        }
        bit = optbit_803FF50C(hdr[0]);
        if (!(bits->local.got.flags & (1 << bit))) {
            return -1;
        }
        for (k = len - 2; k-- > 0;) {
            r = (TLobby__sub_80401BCC(&arg, &lcp_read_byte_buffer, 1) != 1) ? -1 : (s16)lcp_read_byte_buffer;
            if (r == -1) {
                return -1;
            }
        }
        bit = optbit_803FF50C(hdr[0]);
        bits->local.got.flags &= ~(1 << bit);
    }
    return 0;
}
#pragma pop
#pragma push
#pragma dont_inline off
#pragma inline_depth(4)
#pragma opt_common_subs on
extern s32 TLobby__sub_803FF698(Self_803FF698 *self, u8 *item, s32 arg) {
    IpcpConfig *bits;
    IpcpSide *p;
    s32 count;
    u8 *m;
    s16 r;
    u32 bit;
    s32 f;
    u8 hdr[2];
    m = (u8 *)self->f30;
    count = *(s16 *)(item + 2);
    bits = (IpcpConfig *)m;
    p = (IpcpSide *)m;
    if (item[1] != self->f1) {
        return -1;
    }
    while (count > 0 && (s16)read_2_bytes((void *)hdr, &arg) != -1) {
        count -= hdr[1];
        if (count < 0) {
            return -1;
        }
        if (hdr[0] < 8) { bit = hdr[0]; } else { f = 0; if (hdr[0] >= 0x80 && hdr[0] < 0x90) { f = 1; } if (f) { bit = hdr[0] - 0x78; } else { bit = 0; } }
        if (!(bits->local.got.flags & (1 << bit))) {
            bit = optbit_803FF50C(hdr[0]);
            bits->local.got.flags |= 1 << bit;
        }
        r = TLobby__sub_803FFB84(&arg, bits, p, hdr, 0);
        if (r == -1) {
            return -1;
        }
        if (r == 4) {
            bit = optbit_803FF50C(hdr[0]);
            bits->local.got.flags &= ~(1 << bit);
        }
    }
    return 0;
}
#pragma pop

#pragma push
#pragma opt_lifetimes off
#pragma opt_dead_assignments off
#pragma push
#pragma dont_inline off
#pragma inline_depth(4)
inline u32 first_803FA664(Sub_803FF858 *s) {
    u32 t;
    u32 v = 0;
    t = v;
    t = ((u32)init_net_buffer_entry((u16)(0)));
    if (t == 0) {
        return v;
    }
    TLobby__sub_80400270(&t, &s->h1C, s->h1C);
    v = t;
    return v;
}
inline s32 read_803FA664(u32 *p) {
    if (TLobby__sub_80401BCC(p, &lcp_read_byte_buffer, 1) != 1) {
        return -1;
    }
    return (s16)lcp_read_byte_buffer;
}
s32 TLobby__sub_803FF858(Obj_803FF858 *arg0, Msg_803FA664 *arg1, u32 arg2) {
    u32 cur;
    s16 err;
    s16 a;
    s16 b;
    err = 0;
    if (arg1->b1 != arg0->b1) {
        return -1;
    }
    cur = first_803FA664(arg0->p30);
    if (arg1->h2 != get_field_4((void *)cur)) {
        err = 1;
    } else {
        while ((a = read_803FA664(&cur)) != -1) {
            b = read_803FA664(&arg2);
            if (b == -1 || b != a) {
                err = 1;
                break;
            }
        }
    }
    if (err != 0) {
        return -1;
    }
    arg0->bB++;
    return 0;
}
#pragma pop
#pragma pop

extern s32 TLobby__sub_803FF9A4(void *self, u8 *src, u32 bits) {
    u32 sh;
    void *buf;
    unsigned int new_var;
    IpcpConfig *base;
    s32 n;
    s16 r;
    u8 hdr[2];
    s16 k;
    s16 res;
    s32 TLobby__sub_803FE6CC(void *, u8, u8, void *); /* declared here with other parameter types; the definition is s32 (void *, int, int, void *) */
    void TLobby__sub_80400338(PppFrame **pbuf, IpcpOptions *opt, s32 type, s32 len, void *src);
    base = *(IpcpConfig **)((u8 *)self + 0x30);
    n = *(s16 *)(src + 2);
    k = 2;
    buf = 0;
    base->peer.got.flags = 0;
    while (n > 0 && (s16)read_2_bytes((void *)hdr, &bits) != -1) {
        n -= hdr[1];
        if (n < 0) {
            return -1;
        }
        res = TLobby__sub_803FFB84(&bits, base, &base->peer, hdr, 1);
        if (res == -1) {
            return -1;
        }
        if (res < k) {
            continue;
        }
        if (res > k) {
            buf = 0;
            k = res;
        }
        if (res != 4) {
            sh = (hdr[0] < 8) ? hdr[0] : (((new_var = hdr[0]) >= 0x80 && new_var < 0x90) ? new_var - 0x78 : 0);
            base->peer.got.flags |= 1 << sh;
        }
        TLobby__sub_80400338((PppFrame **)&buf, &base->peer.got, hdr[0], hdr[1], &bits);
        if (res > 3) {
            TLobby__sub_803FE6CC(self, k, src[1], buf);
        }
    }

    if (k == 3) {
        if (((u8 *)self)[6] != 0) {
            ((u8 *)self)[6]--;
        } else {
            k = 4;
            TLobby__sub_803FE6CC(self, 4, src[1], buf);
        }
    }
    if (k > 3) {
        return (s16)(2 != k);
    }
    TLobby__sub_803FE6CC(self, k, src[1], buf);
    return (s16)(2 != k);
}
#pragma push
#pragma dont_inline off
#pragma inline_depth(4)
s16 TLobby__sub_803FFB84(void *cursor, IpcpConfig *cfg, IpcpSide *side, u8 *hdr, s16 c) {
    s16 len;
    s16 res;
    s16 ch;
    res = 2;
    len = hdr[1] - 2;
    switch (hdr[0]) {
    case 1:
        side->got.our_addr = (TLobby__sub_80401BCC(cursor, lbl_805D7AA8, 4) != 4) ? 0 : TLobby__sub_80402AFC(lbl_805D7AA8);
        side->got.his_addr = (TLobby__sub_80401BCC(cursor, lbl_805D7AA8, 4) != 4) ? 0 : TLobby__sub_80402AFC(lbl_805D7AA8);
        len -= 8;
        if (c == 0) {
            if (cfg->peer.want.our_addr != 0) {
                cfg->local.got.his_addr = cfg->peer.want.our_addr;
            }
            if (cfg->local.want.our_addr != 0) {
                cfg->local.got.our_addr = cfg->local.want.our_addr;
            }
        } else {
            s32 v54;
            s32 v78;
            v78 = cfg->peer.got.our_addr;
            v54 = cfg->peer.want.our_addr;
            if (v78 == v54) {
                if (v54 == 0) {
                    res = 4;
                }
            } else if (v54 == 0) {
                cfg->local.got.his_addr = v78;
            } else {
                cfg->peer.got.our_addr = v54;
                res = 3;
            }
            {
                s32 v8;
                s32 v7C;
                v7C = cfg->peer.got.his_addr;
                v8 = cfg->local.want.our_addr;
                if (v7C == v8) {
                    if (v8 == 0) {
                        res = 4;
                    }
                } else if (v8 == 0) {
                    cfg->local.got.our_addr = v7C;
                } else {
                    cfg->peer.got.his_addr = v8;
                    res = 3;
                }
            }
        }
        break;

    case 2:
        side->got.vj_protocol = (s16)((TLobby__sub_80401BCC(cursor, lbl_805D7AA8, 2) != 2) ? -1 : read_network_u16_be(lbl_805D7AA8));
        len -= 2;
        if (!(side->flags & 4)) {
            if (side->got.vj_protocol == 0x2d) {
                ch = (TLobby__sub_80401BCC(cursor, &lcp_read_byte_buffer, 1) != 1) ? -1 : (s16)lcp_read_byte_buffer;
                if (ch == -1) {
                    return -1;
                }
                side->got.vj_slots = ch + 1;
                ch = (TLobby__sub_80401BCC(cursor, &lcp_read_byte_buffer, 1) != 1) ? -1 : (s16)lcp_read_byte_buffer;
                if (ch == -1) {
                    return -1;
                }
                side->got.vj_comp_slot = ch;
            }
            side->got.flags = side->want.flags | 4;
            res = 4;
        } else {
            switch (side->got.vj_protocol) {
            case 0x2d:
                ch = (TLobby__sub_80401BCC(cursor, &lcp_read_byte_buffer, 1) != 1) ? -1 : (s16)lcp_read_byte_buffer;
                if (ch == -1) {
                    return -1;
                }
                if ((side->got.vj_slots = ch + 1) < 1) {
                    side->got.vj_slots = 1;
                    res = 3;
                } else if (side->got.vj_slots > 0x10) {
                    side->got.vj_slots = 0x10;
                    res = 3;
                }
                ch = (TLobby__sub_80401BCC(cursor, &lcp_read_byte_buffer, 1) != 1) ? -1 : (s16)lcp_read_byte_buffer;
                if (ch == -1) {
                    return -1;
                }
                side->got.vj_comp_slot = ch;
                if ((u8)ch > 1) {
                    side->got.vj_comp_slot = 1;
                    res = 3;
                }
                len -= 2;
                break;

            default:
                if (side->want.flags & 4) {
                    side->got.vj_protocol = side->want.vj_protocol;
                    side->got.vj_slots = side->want.vj_slots;
                    side->got.vj_comp_slot = side->want.vj_comp_slot;
                } else {
                    side->got.vj_protocol = 0x2d;
                    side->got.vj_slots = 0x10;
                    side->got.vj_comp_slot = 1;
                }
                res = 3;
            }
        }
        break;

    case 3:
        side->got.our_addr = (TLobby__sub_80401BCC(cursor, lbl_805D7AA8, 4) != 4) ? 0 : TLobby__sub_80402AFC(lbl_805D7AA8);
        len -= 4;
        if (c == 0) {
            cfg->local.want.our_addr = side->got.our_addr;
            cfg->peer.want.his_addr = side->got.our_addr;
        } else if (side->got.our_addr != 0) {
            cfg->peer.want.our_addr = side->got.our_addr;
            cfg->local.want.his_addr = side->got.our_addr;
        } else {
            cfg->peer.got.our_addr = cfg->peer.want.our_addr;
            res = 3;
        }
        break;

    case 0x81:
        side->got.dns[0] = (TLobby__sub_80401BCC(cursor, lbl_805D7AA8, 4) != 4) ? 0 : TLobby__sub_80402AFC(lbl_805D7AA8);
        len -= 4;
        if (c == 0) {
            cfg->local.want.dns[0] = side->got.dns[0];
            cfg->peer.want.his_dns[0] = side->got.dns[0];
        } else if (side->got.dns[0] != 0) {
            cfg->peer.want.dns[0] = side->got.dns[0];
            cfg->local.want.his_dns[0] = side->got.dns[0];
        } else {
            cfg->peer.got.dns[0] = cfg->peer.want.dns[0];
            res = 3;
        }
        break;

    case 0x83:
        side->got.dns[1] = (TLobby__sub_80401BCC(cursor, lbl_805D7AA8, 4) != 4) ? 0 : TLobby__sub_80402AFC(lbl_805D7AA8);
        len -= 4;
        if (c == 0) {
            cfg->local.want.dns[1] = side->got.dns[1];
            cfg->peer.want.his_dns[1] = side->got.dns[1];
        } else if (side->got.dns[1] != 0) {
            cfg->peer.want.dns[1] = side->got.dns[1];
            cfg->local.want.his_dns[1] = side->got.dns[1];
        } else {
            cfg->peer.got.dns[1] = cfg->peer.want.dns[1];
            res = 3;
        }
        break;

    default:
        res = 4;
        break;
    }

    if (!(side->flags & (1 << optbit_803FFB84(hdr[0])))) {
        res = 4;
    }
    if (len < 0) {
        return -1;
    }
    if (c == 0 && len > 0) {
        while (len-- > 0) {
            if (((TLobby__sub_80401BCC(cursor, &lcp_read_byte_buffer, 1) != 1) ? -1 : (s16)lcp_read_byte_buffer) == -1) {
                return -1;
            }
        }
    }
    return res;
}
#pragma pop

void TLobby__sub_80400338(PppFrame **pbuf, IpcpOptions *opt, s32 type, s32 len, void *src);
extern PppFrame *TLobby__sub_80400174(void *self) {
    PppFrame *blk;
    s16 i;
    s16 flags;
    u8 *p;
    IpcpConfig *base;
    extern u8 lbl_8047FE3C[];
    base = *(IpcpConfig **)((u8 *)self + 0x30);
    blk = 0;

    blk = init_net_buffer_entry(0);
    if (blk == 0) {
        return 0;
    }
    flags = base->local.got.flags;
    if (blk == 0) {
        blk = init_net_buffer_entry(0);
        if (blk == 0) {
            goto done;
        }
    }
    p = lbl_8047FE3C + 1;
    for (i = 1; i < 0x20; i++) {
        if (flags & (1 << i)) {
            TLobby__sub_80400338(&blk, &base->local.got, (i < 8) ? i : ((i < 0x20) ? i + 0x78 : 0), *p, 0);
        }
        p++;
    }
done:
    return blk;
}

extern u8 lbl_8047FE3C[];
inline s32 optnum_80400270(s32 bit) {
    if (bit < 8) {
        return bit;
    }
    if (bit < 0x20) {
        bit += 0x78;
        return bit;
    }
    return 0;
}
#pragma push
#pragma dont_inline off
#pragma inline_depth(4)
void TLobby__sub_80400270(u32 *self, void *opt, s32 mask) {
    s16 new_var;
    s16 i;
    s32 m;
    if (*self == 0) {
        *self = (u32)init_net_buffer_entry(0);
        if (*self == 0) {
            return;
        }
    }
    m = (new_var = (s16)mask);
    for (i = 1; i < 0x20; i++) {
        if (m & (1 << i)) {
            TLobby__sub_80400338((PppFrame **)self, (IpcpOptions *)opt, optnum_80400270(i), lbl_8047FE3C[i], 0);
        }
    }
}
#pragma pop
void TLobby__sub_80400338(PppFrame **pbuf, IpcpOptions *opt, s32 type, s32 len, void *src) {
    PppFrame *buf;
    s16 n;
    u8 *p;
    u8 *q;
    s16 k;

    n = len - 2;
    if (*pbuf != NULL) {
        buf = *pbuf;
    } else {
        buf = init_net_buffer_entry(0);
        if (buf == NULL) {
            return;
        }
        *pbuf = buf;
    }
    p = buf->data + buf->len;
    p[0] = type;
    p[1] = len;
    p += 2;
    switch (type) {
    case 1:
        p = write_network_u32_be(write_network_u32_be(p, opt->our_addr), opt->his_addr);
        n -= 8;
        break;
    case 2:
        k = opt->vj_protocol;
        if (k == 0x2D) {
            p = write_network_u16_be(p, k);
            *p++ = opt->vj_slots - 1;
            n -= 4;
            *p++ = opt->vj_comp_slot;
        }
        break;
    case 3:
        p = write_network_u32_be(p, opt->our_addr);
        n -= 4;
        break;
    case 0x81:
        p = write_network_u32_be(p, opt->dns[0]);
        n -= 4;
        break;
    case 0x83:
        p = write_network_u32_be(p, opt->dns[1]);
        n -= 4;
        break;
    }
    while (n-- > 0) {
        *p++ = TLobby__sub_80401BCC(src, &lcp_read_byte_buffer, 1) != 1 ? -1 : (s16)lcp_read_byte_buffer;
    }
    buf->len += len;
}

IpcpState lbl_805C0328;
