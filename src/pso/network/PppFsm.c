/* The PPP option-negotiation state machine that LCP, IPCP and PAP drive (a C library, built with GC/1.2.5n). PppFsm is an inferred name; no string names this module. */
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
#include "pso/network/PppFsm.h"
#include "pso/network/IPv4Header.h"

void update_countdown_state(void *);

void TLobby__sub_803FD694(u8 *arg0) {
    PppFsmTimer *timer;
    PppFsm *fsm;

    fsm = (PppFsm *)arg0;
    timer = &fsm->timer;
    fsm->f4 = fsm->proto->b9;
    fsm->f7 = fsm->proto->bA;
    fsm->f5 = fsm->proto->bB;
    fsm->state = (fsm->f2 & 0xC0) ? 1 : 0;
    fsm->retries = fsm->f4;
    fsm->f6 = fsm->f7;
    fsm->proto->f14(fsm, fsm->proto);
    timer->callback = (PppFsmTimerCallback)update_countdown_state;
    timer->arg = fsm;
    TLobby__sub_80405298((N_80405298 *)timer, fsm->proto->timeout);
}

void update_connection_state(int arg0) {
    PppFsm *fsm;

    fsm = (PppFsm *)arg0;
    if (fsm->opts == 0) {
        return;
    }
    switch (fsm->state) {
    case 5:
        fsm->proto->f20(fsm, fsm->proto);
    case 4:
        fsm->retries = fsm->f5;
        if (fsm->retries != 0) {
            fsm->retries--;
            TLobby__sub_80405328((u8 *)&fsm->timer);
            TLobby__sub_803FE6CC((void *)arg0, 5, 0, 0);
        }
        fsm->state = 6;
        break;
    case 2:
    case 3:
        fsm->retries = 0;
        fsm->state = 6;
        break;
    case 1:
        if (lbl_805D7A90 & 2) {
            if (fsm->retries != 0) {
                fsm->retries--;
                TLobby__sub_80405328((u8 *)&fsm->timer);
                TLobby__sub_803FE6CC((void *)arg0, 5, 0, 0);
            }
        }
        fsm->state = 0;
        break;
    case 6:
        break;
    }
}

void TLobby__sub_803FD85C(void *arg0) {
    PppFsm *fsm;

    fsm = (PppFsm *)arg0;
    if (fsm->opts != NULL) {
        switch (fsm->state) {
        case 2:
        case 3:
        case 4:
            TLobby__sub_80405304(&fsm->timer);
            fsm->state = (fsm->f2 & 0xC0) ? 1 : 0;
            fsm->retries = fsm->f4;
            fsm->f6 = fsm->f7;
            fsm->proto->f14(arg0, fsm->proto);
            break;
        case 5:
            fsm->proto->f20(fsm, fsm->proto);
        case 6:
            fsm->state = (fsm->f2 & 0xC0) ? 1 : 0;
            fsm->retries = fsm->f4;
            fsm->f6 = fsm->f7;
            fsm->proto->f14(fsm, fsm->proto);
            break;
        }
    }
}

void TLobby__sub_803FD958(u8 *arg0) {
    PppFsm *fsm;

    fsm = (PppFsm *)arg0;
    if (fsm->opts != NULL && (fsm->f2 & 0xC0)) {
        switch (fsm->state) {
        case 0:
        case 1:
        case 6:
            fsm->proto->f18(fsm, fsm->proto);
            fsm->state = (fsm->f2 & 0xC0) ? 1 : 0;
            fsm->retries = fsm->f4;
            fsm->f6 = fsm->f7;
            fsm->proto->f14(fsm, fsm->proto);
            if (fsm->f2 & 0x80) {
                if (fsm->retries != 0) {
                    fsm->retries--;
                    TLobby__sub_80405328((u8 *)&fsm->timer);
                    TLobby__sub_803FE6CC(arg0, 1, 0, fsm->proto->f28(fsm, fsm->proto));
                }
                fsm->state = 2;
            }
            break;
        }
    }
}

void update_countdown_state(void *arg0) {
    PppFsm *fsm = (PppFsm *)arg0;
    switch (fsm->state) {
    case 2:
    case 3:
    case 4:
        if (fsm->retries != 0) {
            if (fsm->retries > 0) {
                fsm->retries--;
                TLobby__sub_80405328((u8 *)&fsm->timer);
                TLobby__sub_803FE6CC(fsm, 1, 0, fsm->proto->f28(fsm, fsm->proto));
            }
            if (fsm->state == 3) {
                fsm->state = 2;
            }
        } else {
            fsm->state = (fsm->f2 & 0xC0) ? 1 : 0;
            fsm->retries = fsm->f4;
            fsm->f6 = fsm->f7;
            fsm->proto->f14(fsm, fsm->proto);
            fsm->f8 = 1;
        }
        break;
    case 6:
        if (fsm->retries != 0) {
            if (fsm->retries > 0) {
                fsm->retries--;
                TLobby__sub_80405328((u8 *)&fsm->timer);
                TLobby__sub_803FE6CC(fsm, 5, 0, 0);
            }
        } else {
            fsm->proto->f24(fsm, fsm->proto);
            fsm->state = (fsm->f2 & 0xC0) ? 1 : 0;
            fsm->retries = fsm->f4;
            fsm->f6 = fsm->f7;
            fsm->proto->f14(fsm, fsm->proto);
            fsm->f8 = 1;
        }
        break;
    }
}

static inline s16 read_packet_header(Hdr_803FC4B4 *dst, void *src, s32 with_ext) {
    u8 ext[8];
    u8 buf[4];
    if (dst == 0) {
        return -1;
    }
    if (TLobby__sub_80401BCC(src, buf, 4) < 4) {
        return -1;
    }
    dst->type = buf[0];
    dst->flag = buf[1];
    dst->len = read_network_u16_be(buf + 2);
    if (with_ext && TLobby__sub_80401BCC(src, ext, 8) < 8) {
        return -1;
    }
    return 0;
}

#pragma push
#pragma opt_common_subs on
#pragma dont_inline off
#pragma inline_depth(4)
void TLobby__sub_803FDBF8(PppFsm *fsm, void *arg1)
{
    s16 TLobby__sub_803FE6CC(); /* declared without a parameter list; the definition is s32 (void *, int, int, void *) */
    extern s32 lbl_805D7AA0;
    Hdr_803FC4B4 hdr;
    s16 rc;
    u8 *newbuf;
    u8 *dp;

    rc = read_packet_header(&hdr, &arg1, 0);
    if (rc != 0) {
        return;
    }
    hdr.len -= 4;
    TLobby__sub_80401CAC((PppFrame **)&arg1, hdr.len);
    switch (hdr.type) {
    case 1:
        switch (fsm->state) {
        case 5:
            fsm->proto->f20(fsm, fsm->proto);
            fsm->state = ((fsm->f2 & 0xC0) != 0) ? 1 : 0;
            fsm->retries = fsm->f4;
            fsm->f6 = fsm->f7;
            fsm->proto->f14(fsm, fsm->proto);
        case 1:
            fsm->proto->f18(fsm, fsm->proto);
            if (fsm->retries != 0) {
                fsm->retries--;
                TLobby__sub_80405328((u8 *)&fsm->timer);
                TLobby__sub_803FE6CC(fsm, 1, 0, fsm->proto->f28(fsm, fsm->proto));
            }
        case 2:
        case 4:
            if (fsm->proto->f2C(fsm, &hdr, arg1) == 0) {
                fsm->state = 4;
            } else {
                fsm->state = 2;
            }
            break;
        case 3:
            if (fsm->proto->f2C(fsm, &hdr, arg1) == 0) {
                TLobby__sub_80405304(&fsm->timer);
                fsm->proto->f1C(fsm, fsm->proto);
                fsm->state = 5;
                lbl_805D7AA0++;
            } else {
                TLobby__sub_80405328((u8 *)&fsm->timer);
            }
            break;
        case 0:
            TLobby__sub_803FE6CC(fsm, 6, hdr.flag, 0);
            break;
        case 6:
            break;
        }
        break;
    case 2:
        switch (fsm->state) {
        case 2:
            if (fsm->proto->f30(fsm, &hdr, arg1) == 0) {
                fsm->state = 3;
            }
            break;
        case 4:
            if (fsm->proto->f30(fsm, &hdr, arg1) == 0) {
                TLobby__sub_80405304(&fsm->timer);
                fsm->proto->f1C(fsm, fsm->proto);
                fsm->state = 5;
                lbl_805D7AA0++;
            }
            break;
        case 5:
            fsm->proto->f20(fsm, fsm->proto);
            fsm->proto->f18(fsm, fsm->proto);
            fsm->state = ((fsm->f2 & 0xC0) != 0) ? 1 : 0;
            fsm->retries = fsm->f4;
            fsm->f6 = fsm->f7;
            fsm->proto->f14(fsm, fsm->proto);
        case 3:
            if (fsm->retries != 0) {
                fsm->retries--;
                TLobby__sub_80405328((u8 *)&fsm->timer);
                TLobby__sub_803FE6CC(fsm, 1, 0, fsm->proto->f28(fsm, fsm->proto));
            }
            fsm->state = 2;
            break;
        case 0:
        case 1:
            TLobby__sub_803FE6CC(fsm, 6, hdr.flag, 0);
            break;
        case 6:
            break;
        }
        break;
    case 3:
        switch (fsm->state) {
        case 2:
        case 4:
            if (fsm->proto->f34(fsm, &hdr, arg1) == 0) {
                if (fsm->retries != 0) {
                    fsm->retries--;
                    TLobby__sub_80405328((u8 *)&fsm->timer);
                    TLobby__sub_803FE6CC(fsm, 1, 0, fsm->proto->f28(fsm, fsm->proto));
                }
            }
            break;
        case 5:
            fsm->proto->f20(fsm, fsm->proto);
            fsm->proto->f18(fsm, fsm->proto);
            fsm->state = ((fsm->f2 & 0xC0) != 0) ? 1 : 0;
            fsm->retries = fsm->f4;
            fsm->f6 = fsm->f7;
            fsm->proto->f14(fsm, fsm->proto);
        case 3:
            if (fsm->retries != 0) {
                fsm->retries--;
                TLobby__sub_80405328((u8 *)&fsm->timer);
                TLobby__sub_803FE6CC(fsm, 1, 0, fsm->proto->f28(fsm, fsm->proto));
            }
            fsm->state = 2;
            break;
        case 0:
        case 1:
            TLobby__sub_803FE6CC(fsm, 6, hdr.flag, 0);
            break;
        case 6:
            break;
        }
        break;
    case 4:
        switch (fsm->state) {
        case 2:
        case 4:
            if (fsm->proto->f38(fsm, &hdr, arg1) == 0) {
                if (fsm->retries != 0) {
                    fsm->retries--;
                    TLobby__sub_80405328((u8 *)&fsm->timer);
                    TLobby__sub_803FE6CC(fsm, 1, 0, fsm->proto->f28(fsm, fsm->proto));
                }
            }
            break;
        case 5:
            fsm->proto->f20(fsm, fsm->proto);
            fsm->proto->f18(fsm, fsm->proto);
            fsm->state = ((fsm->f2 & 0xC0) != 0) ? 1 : 0;
            fsm->retries = fsm->f4;
            fsm->f6 = fsm->f7;
            fsm->proto->f14(fsm, fsm->proto);
        case 3:
            if (fsm->retries != 0) {
                fsm->retries--;
                TLobby__sub_80405328((u8 *)&fsm->timer);
                TLobby__sub_803FE6CC(fsm, 1, 0, fsm->proto->f28(fsm, fsm->proto));
            }
            fsm->state = 2;
            break;
        case 0:
        case 1:
            TLobby__sub_803FE6CC(fsm, 6, hdr.flag, 0);
            break;
        case 6:
            break;
        }
        break;
    case 5:
        switch (fsm->state) {
        case 5:
            TLobby__sub_803FE6CC(fsm, 6, hdr.flag, 0);
            fsm->proto->f20(fsm, fsm->proto);
            fsm->proto->f24(fsm, fsm->proto);
            fsm->state = ((fsm->f2 & 0xC0) != 0) ? 1 : 0;
            fsm->retries = fsm->f4;
            fsm->f6 = fsm->f7;
            fsm->proto->f14(fsm, fsm->proto);
            break;
        case 3:
        case 4:
            fsm->state = 2;
        case 0:
        case 1:
        case 2:
        case 6:
            TLobby__sub_803FE6CC(fsm, 6, hdr.flag, 0);
            break;
        }
        break;
    case 6:
        switch (fsm->state) {
        case 6:
            TLobby__sub_80405304(&fsm->timer);
            fsm->proto->f24(fsm, fsm->proto);
            fsm->state = ((fsm->f2 & 0xC0) != 0) ? 1 : 0;
            fsm->retries = fsm->f4;
            fsm->f6 = fsm->f7;
            fsm->proto->f14(fsm, fsm->proto);
            break;
        case 5:
            fsm->proto->f20(fsm, fsm->proto);
            fsm->state = ((fsm->f2 & 0xC0) != 0) ? 1 : 0;
            fsm->retries = fsm->f4;
            fsm->f6 = fsm->f7;
            fsm->proto->f14(fsm, fsm->proto);
            if (fsm->retries == 0) {
                rc = -1;
            } else {
                fsm->retries--;
                TLobby__sub_80405328((u8 *)&fsm->timer);
                rc = TLobby__sub_803FE6CC(fsm, 1, 0, fsm->proto->f28(fsm, fsm->proto));
            }
            if (rc == 0) {
                fsm->state = 2;
            }
            break;
        case 3:
        case 4:
            fsm->state = 2;
            break;
        }
        break;
    case 7:
        fsm->proto->f24(fsm, fsm->proto);
        fsm->state = ((fsm->f2 & 0xC0) != 0) ? 1 : 0;
        fsm->retries = fsm->f4;
        fsm->f6 = fsm->f7;
        fsm->proto->f14(fsm, fsm->proto);
        break;
    case 9:
        switch (fsm->state) {
        case 5:
            TLobby__sub_803FE6CC(fsm, 10, hdr.flag, arg1);
            break;
        case 2:
        case 3:
        case 4:
            break;
        case 0:
        case 1:
            TLobby__sub_803FE6CC(fsm, 6, hdr.flag, 0);
            break;
        case 6:
            break;
        }
        break;
    case 8:
    case 10:
    case 11:
    case 12:
        break;
    case 0:
    default:
        hdr.len += 4;
        newbuf = alloc_from_buffer(arg1, 4);
        dp = ((PppFrame *)newbuf)->data;
        *dp++ = hdr.type;
        *dp++ = hdr.flag;
        write_network_u16_be(dp, hdr.len);
        arg1 = newbuf;
        TLobby__sub_803FE6CC(fsm, 7, hdr.flag, arg1);
        switch (fsm->state) {
        case 6:
            break;
        case 2:
        case 3:
        case 4:
        case 5:
            fsm->state = 1;
            break;
        }
        break;
    }
}
#pragma pop
void TLobby__sub_803FE600(O_803FE600 *o) {
    PppFsm *fsm = (PppFsm *)o;

    fsm->state = (fsm->f2 & 0xC0) ? 1 : 0;
    fsm->retries = fsm->f4;
    fsm->f6 = fsm->f7;
    fsm->proto->f14(fsm, fsm->proto);
}

s32 TLobby__sub_803FE658(u8 *arg0) {
    PppFsm *fsm;
    u8 count;

    fsm = (PppFsm *)arg0;
    count = fsm->retries;
    if (count == 0) {
        return -1;
    }
    fsm->retries = count - 1;
    TLobby__sub_80405328((u8 *)&fsm->timer);
    return TLobby__sub_803FE6CC(arg0, 1, 0, fsm->proto->f28(fsm, fsm->proto));
}

s32 TLobby__sub_80406624(s32 a, s32 b, u16 code, void *self);
#pragma push
#pragma opt_lifetimes off
s32 TLobby__sub_803FE6CC(void *self, int a, int b, void *c) {
    PppFsm *fsm = (PppFsm *)self;
    u8 pad[8];
    PppFrame *buf;
    u8 *link = fsm->sub;
    s32 cmd;
    s32 id;
    u16 n;

    if ((buf = (PppFrame *)c) == 0) {
        PppFrame *q = lbl_805C04A8.reply;
        q->data = (u8 *)q + ((lbl_805C04A8.headroom + 0x83) & ~3);
        q->len = 0;
        buf = q;
    }
    switch (cmd = (u8)a) {
    case 1:
    case 5:
    case 9:
        fsm->f1 = link[1];
    case 8:
    case 11:
        id = link[1];
        link[1] = id + 1;
        break;
    case 2:
    case 3:
    case 4:
    case 6:
    case 7:
    case 10:
        id = b;
        break;
    default:
        return -1;
    }

    switch (cmd) {
    case 9:
    case 10:
    case 11:
        write_network_u32_be(buf->data, *(u32 *)(fsm->opts + 0x28));
        break;
    }
    n = get_field_4((void *)buf) + 4;
    {
        PppFrame *out = (PppFrame *)alloc_from_buffer((0, (void *)buf), 4);
        u8 *dp = out->data;
        *dp++ = a;
        *dp++ = id;
        write_network_u16_be(dp, n);
        buf = out;
    }
    if (buf == 0) {
        return -1;
    }
    {
        u8 *counter = link + (fsm->proto->b8 << 1);
        s16 v = *(s16 *)(counter + 0x118);
        *(s16 *)(counter + 0x118) = v + 1;
    }
    return TLobby__sub_80406624(0, 0, fsm->proto->proto, buf);
}
#pragma pop
void TLobby__sub_803FE820(s32 arg0) {
    TLobby__sub_80405328((u8 *)&((PppFsm *)arg0)->timer);
}

s32 TLobby__sub_803FE844(void) {
    return 0;
}

void TLobby__sub_803FE84C(void) {

}

s32 read_2_bytes(void *self, void *src) {
    u8 *dst = (u8 *)self;
    u8 buf[2];
    if (dst == 0) {
        return -1;
    }
    if (TLobby__sub_80401BCC(src, buf, 2) < 2) {
        return -1;
    }
    dst[0] = buf[0];
    dst[1] = buf[1];
    return 0;
}

s32 TLobby__sub_803FE8BC(u8 *dst, void *src) {
    u8 buf[4];
    if (dst == 0) {
        return -1;
    }
    if (TLobby__sub_80401BCC(src, buf, 4) < 4) {
        return -1;
    }
    dst[0] = buf[0];
    dst[1] = buf[1];
    *(u16 *)(dst + 2) = read_network_u16_be(buf + 2);
    return 0;
}

u16 TLobby__sub_803FE934(u8* p, PppFrame *buf, u16 count) {
    u32 sum = 0;
    s32 i;
    if (p != NULL) {
        i = 6; while (i--) { sum += *p++ << 8; sum += *p++; }
    }
    sum = TLobby__sub_803FE9F8(sum, buf, count);
    sum = (sum >> 16) + (sum & 0xFFFF);
    sum += sum >> 16;
    return ~sum & 0xFFFF;
}

u32 TLobby__sub_803FE9F8(u32 sum, PppFrame* buf, u16 count) {
    s16 n;
    u16 last;
    s32 odd;
    s16 half;
    s16 i;
    u8* data;
    data = buf->data;
    n = buf->len < count ? buf->len : count;
    if (n & 1) {
        odd = 1;
        last = data[n - 1];
        n--;
    } else {
        odd = 0;
        last = 0;
    }
    half = n >> 1;
    for (i = half; i > 0; i--) {
        sum += data[0] << 8;
        sum += data[1];
        data += 2;
    }
    if (odd) {
        sum += last << 8;
    }
    return sum;
}

s32 TLobby__sub_803FEA88(A_80403F4C *out, PppFrame **src) {
    PppFrame *e = *src;
    IPv4Header h;
    u32 hl;
    u16 frag;
    u32 optlen;
    IPv4Header *wire;

    wire = &h;
    if (TLobby__sub_80401BCC(src, wire, 20) != 20) {
        return 0xFFFF;
    }
    out->version = (h.ver_ihl >> 4) & 0xF;
    out->tos = h.tos;
    out->len = h.len;
    out->id = h.id;
    frag = h.frag;
    out->frag = (frag & 0x1FFF) << 3;
    if (frag & 0x2000) {
        out->mf = 1;
    } else {
        out->mf = 0;
    }
    if (frag & 0x4000) {
        out->df = 1;
    } else {
        out->df = 0;
    }
    out->ttl = h.ttl;
    out->proto = h.proto;
    out->cksum = h.cksum;
    out->src = h.src;
    out->dst = h.dst;
    if (out->len - 20 < e->len) {
        e->len = out->len - 20;
    }
    hl = (h.ver_ihl & 0xF) * 4;
    if (hl < 20) {
        out->optlen = 0;
        return 0xFFFF;
    }
    optlen = hl - 20;
    out->optlen = optlen;
    if (out->optlen != 0 && TLobby__sub_80401BCC(src, out->opts, out->optlen) < out->optlen) {
        return 0xFFFF;
    }
    return hl;
}

u8 *NetIPv4WriteHeader(A_80403F4C *ip, u8 *arg1, s32 arg2) {
    u16 n;
    u8 buf[0x40];
    u8 *hdr = buf;
    u8 *data;
    u32 sum;
    u16 f;
    u32 tmp;
    u8 pad[0x8];

    tmp = ip->optlen + 0x14;
    n = tmp;
    if (n > 0x40) {
        n = 0x40;
    }
    arg1 = alloc_from_buffer(arg1, n);
    data = ((PppFrame *)arg1)->data;

    hdr[0] = (ip->version << 4) | (n >> 2);
    hdr[1] = ip->tos;
    *(u16 *)&hdr[2] = ip->len;
    *(u16 *)&hdr[4] = ip->id;
    f = (s32)ip->frag >> 3;
    if (ip->df != 0) {
        f |= 0x4000;
    }
    if (ip->mf != 0) {
        f |= 0x2000;
    }
    *(u16 *)&hdr[6] = f;
    hdr[8] = ip->ttl;
    hdr[9] = ip->proto;
    if ((u16)arg2 != 0) {
        *(u16 *)&hdr[10] = ip->cksum;
    } else {
        *(u16 *)&hdr[10] = 0;
    }
    *(u32 *)&hdr[12] = ip->src;
    *(u32 *)&hdr[16] = ip->dst;

    if (ip->optlen != 0) {
        NetMemcpy(hdr + 0x14, ip->opts, (ip->optlen < 0x2C) ? ip->optlen : 0x2C);
    }
    {
        u32 m = (u16)n;
        NetMemcpy(data, hdr, m);
        if ((u16)arg2 == 0) {
            sum = TLobby__sub_803FE9F8(0, (PppFrame *)arg1, n);
            sum = (sum >> 16) + (sum & 0xFFFF);
            sum = (sum >> 16) + sum;
            *(u16 *)&hdr[10] = ~sum;
        }
        NetMemcpy(data, hdr, m);
    }
    return arg1;
}
