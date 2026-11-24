/* PPP IPCP, the protocol that names itself "IPcp" (805E1170), and its state object (.bss 805C0328) (a C
 * library, built with GC/1.2.5n). */
#include "types.h"
#include "pso/network/TLobby_803FC178.h"
#include "pso/network/TLobby_803FCF44.h"
#include "pso/network/PppFsm.h"
#include "pso/network/TLobby_804050DC.h"
#include "pso/network/TLobby_8041112C.h"
#include "pso/network/PppIpcp.h"
typedef struct P_803FF48C P_803FF48C;
/* This file's functions. */
void free_field_98(PppFsm *self);
void free_field_98_and_clear(PppFsm *self);
s32 read_2_bytes(void *self, void *src);
u8 *write_network_u32_be(u8 *p, u32 v);
#include "pso/network/NetworkRuntime.h"
#include "pso/network/TLobby_804048E8.h"
extern s32 is_timed_out(void);
#include "pso/network/NetworkTransport.h"

extern IpcpState lbl_805C0328;


#include <stddef.h>
#include "pso/network/NetStackTypes.h"

void net_sleep_ms(int);
#include "pso/network/PppBuffer.h"
#include "pso/network/TLobby_803FAEA0.h"

/* The empty option set each IPCP side starts from (.rodata 8047FE18). */
const IpcpOptions lbl_8047FE18 = {0};
/* Each option's length by flag bit: option 1 (two addresses) 10, options 2 and 3 6, options 0x81 and 0x83
 * (RFC 1877 name servers, bits 9 and 11) 6. */
const u8 lbl_8047FE3C[20] = {0, 10, 6, 6, 0, 0, 0, 0, 0, 6, 0, 6};
/* The option readers' scratch bytes (.sbss 805D7AA8), in reverse definition order. */
u8 lcp_read_byte_buffer;
u8 lbl_805D7AA8[4];
s16 TLobby__sub_803FED78(PppFsm *self) {
    PppFsm *p;
    void *ipv6cp_state;
    PppFsm *ipv6cp;
    NetThreadState *pd;
    u8 *obj;
    s16 st;
    s16 check_connection_status(void *); /* declared s16 here; the definition returns s32 */
    st = 1;
    obj = self->sub;
    self->abort = 0;
    ipv6cp_state = &ppp_proto_blocks.ipv6cp;
    ipv6cp = (PppFsm *)ipv6cp_state;
    ipv6cp->abort = 0;
    p = (PppFsm *)ipv6cp_state;
    pd = &lbl_805C18A0;
    goto test;
    while (1) {
        if (is_timed_out() != 0 || obj[0] == 4) {
            update_connection_state(self);
            self->abort = 0;
            p->abort = 0;
            return -1;
        }
        if (self->abort != 0) goto after;
        st = check_connection_status(p);
        unlock_mutex(pd->mutex);
        net_sleep_ms(0x64);
        process_expired_timers();
        lock_mutex(pd->mutex);
test:
        if (self->state == 5) goto after;
        if (lbl_805D7AA0 >= 2) goto after;
    }
after:
    if (lbl_805D7A7C != 6 && (s16)(s32)lbl_805D7A7C) {
        if (self->abort != 0) {
            p->abort = 0;
            self->abort = 0;
            return -1;
        }
        p->abort = 0;
        self->abort = 0;
        return 0;
    }
    pd = &lbl_805C18A0;
    while (st > 0) {
        st = check_connection_status(p);
        unlock_mutex(pd->mutex);
        net_sleep_ms(0x64);
        process_expired_timers();
        lock_mutex(pd->mutex);
    }
    switch (st) {
    case 0:
        self->abort = 0;
        p->abort = 0;
        return 0;
    case -2:
        if (self->abort == 0) {
            self->abort = 0;
            p->abort = 0;
            return 0;
        }
        break;
    }
    update_connection_state(self);
    p->abort = 0;
    self->abort = 0;
    return -1;
}

void TLobby__sub_803FF48C(PppFsm *o);
s16 TLobby__sub_803FF50C(PppFsm *self, PppHeader *item, PppFrame *arg);
s16 TLobby__sub_803FF698(PppFsm *self, PppHeader *item, PppFrame *arg);
s16 TLobby__sub_803FF9A4(PppFsm *self, PppHeader *src, PppFrame *bits);
PppFrame *build_ipcp_config_request(PppFsm *self);
void TLobby__sub_803FEF4C(PppProtoBlocks *connection) {
    const IpcpOptions *src = &lbl_8047FE18;
    void *state_address = &lbl_805C0328;
    IpcpState *state = (IpcpState *)state_address;
    PppFsmProtocol *protocol = (PppFsmProtocol *)state_address;
    PppFsm *fsm;
    IpcpConfig *config;
    protocol->name = "IPcp";
    fsm = &connection->ipcp;
    config = &state->config;
    protocol->proto = 0x8021;
    protocol->h6 = 0xfe;
    protocol->tx_counter_index = 2;
    protocol->max_request_attempts = 0x14;
    protocol->max_peer_attempts = 10;
    protocol->max_terminate_attempts = 10;
    protocol->timeout = 0xbb8;
    protocol->release_resources = free_field_98;
    protocol->reset_options = TLobby__sub_803FF48C;
    protocol->start_negotiation = TLobby__sub_803FF374;
    protocol->link_opened = ipcp_opening;
    protocol->link_closed = free_field_98_and_clear;
    protocol->finish_termination = TLobby__sub_803FF468;
    protocol->build_config_request = build_ipcp_config_request;
    protocol->check_config_request = TLobby__sub_803FF9A4;
    protocol->check_config_ack = TLobby__sub_803FF858;
    protocol->check_config_nak = TLobby__sub_803FF698;
    protocol->check_config_reject = TLobby__sub_803FF50C;
    fsm->sub = (u8 *)connection;
    fsm->proto = protocol;
    fsm->opts = config;
    state->config.local.want = *src;
    state->config.local.flags = 6;
    state->config.peer.want = *src;
    config->peer.got = *src;
    config->peer.flags = 6;
    TLobby__sub_803FD694(fsm);
}

s16 ipcp_set_vj_compression(s16 disabled, IpcpSide *side) {
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

s16 ipcp_set_peer_secondary_dns(IpcpSide *side, s32 addr) {
    if (addr == -1) {
        side->want.dns[1] = 0;
        side->want.flags &= ~0x800;
    } else {
        side->want.dns[1] = addr;
        side->want.flags |= 0x800;
    }
    return 0;
}

s16 ipcp_set_peer_primary_dns(IpcpSide *side, s32 addr) {
    if (addr == -1) {
        side->want.dns[0] = 0;
        side->want.flags &= ~0x200;
    } else {
        side->want.dns[0] = addr;
        side->want.flags |= 0x200;
    }
    return 0;
}

s16 ipcp_set_local_secondary_dns(IpcpSide *side, s32 addr) {
    if (addr == -1) {
        side->want.dns[1] = 0;
        side->want.flags &= ~0x800;
    } else {
        side->want.dns[1] = addr;
        side->want.flags |= 0x800;
    }
    return 0;
}

s16 ipcp_set_local_primary_dns(IpcpSide *side, s32 addr) {
    if (addr == -1) {
        side->want.dns[0] = 0;
        side->want.flags &= ~0x200;
    } else {
        side->want.dns[0] = addr;
        side->want.flags |= 0x200;
    }
    return 0;
}

s16 ipcp_set_peer_address(IpcpSide *side, s32 addr) {
    if (addr == -1) {
        side->want.our_addr = 0;
        side->want.flags &= ~8;
    } else {
        side->want.our_addr = addr;
        side->want.flags |= 8;
    }
    return 0;
}

s16 ipcp_set_local_address(IpcpSide *side, s32 addr) {
    if (addr == -1) {
        side->want.our_addr = 0;
        side->want.flags &= ~8;
    } else {
        side->want.our_addr = addr;
        side->want.flags |= 8;
    }
    return 0;
}

s16 TLobby__sub_803FF304(PppFsm *fsm) {
    PP_doppp_active(fsm);
    if (*fsm->sub == 3) {
        TLobby__sub_803FD958((u8 *)fsm);
    }
    return 0;
}

void free_field_98(PppFsm *self) {
    TLobby__sub_80405000(((IpcpConfig *)self->opts)->net_list);
}

void TLobby__sub_803FF374(PppFsm *arg0) {
    *(s8 *)((s8 *)arg0 + 0xA) = 0;
    *(s8 *)((s8 *)arg0 + 0xB) = 0;
}

void ipcp_opening(PppFsm *arg0) {
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
    lobby_timer_stop(&arg0->timer);
    *(s8 *)((s8 *)arg0 + 0) = 5;
}

void free_field_98_and_clear(PppFsm *self) {
    IpcpConfig *config = (IpcpConfig *)self->opts;
    TLobby__sub_80405000(config->net_list);
    config->net_list = 0;
}

void TLobby__sub_803FF468(PppFsm *arg0) {
    lobby_timer_stop(&arg0->timer);
}

void TLobby__sub_803FF48C(PppFsm *o) {
    IpcpConfig *q = o->opts;
    q->local.got = q->local.want;
    q->local.got.his_addr = q->peer.want.our_addr;
    q->local.flags = q->local.flags | q->local.want.flags;
    q->peer.got.flags = 0;
    q->peer.flags = q->peer.flags | q->peer.want.flags;
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
s16 TLobby__sub_803FF50C(PppFsm *self, PppHeader *item, PppFrame *arg) {
    IpcpConfig *bits = (IpcpConfig *)self->opts;
    s32 count = item->len;
    s16 k;
    s32 r;
    u32 bit;
    s32 len;
    s32 pad;
    u8 hdr[2];

    if (item->id != self->id) {
        return -1;
    }
    while (count > 0 && (s16)read_2_bytes((void *)hdr, &arg) != -1) {
        len = hdr[1];
        count -= len;
        if (count < 0) {
            return -1;
        }
        bit = ppp_configure_option_bit(hdr[0]);
        if (!(bits->local.got.flags & (1 << bit))) {
            return -1;
        }
        for (k = len - 2; k-- > 0;) {
            r = (ppp_buffer_read(&arg, &lcp_read_byte_buffer, 1) != 1) ? -1 : (s16)lcp_read_byte_buffer;
            if (r == -1) {
                return -1;
            }
        }
        bit = ppp_configure_option_bit(hdr[0]);
        bits->local.got.flags &= ~(1 << bit);
    }
    return 0;
}
#pragma pop
#pragma push
#pragma dont_inline off
#pragma inline_depth(4)
#pragma opt_common_subs on
s16 TLobby__sub_803FF698(PppFsm *self, PppHeader *item, PppFrame *arg) {
    IpcpConfig *bits;
    IpcpSide *p;
    s32 count;
    u8 *m;
    s16 r;
    u32 bit;
    s32 f;
    u8 hdr[2];
    m = (u8 *)self->opts;
    count = item->len;
    bits = (IpcpConfig *)m;
    p = (IpcpSide *)m;
    if (item->id != self->id) {
        return -1;
    }
    while (count > 0 && (s16)read_2_bytes((void *)hdr, &arg) != -1) {
        count -= hdr[1];
        if (count < 0) {
            return -1;
        }
        if (hdr[0] < 8) { bit = hdr[0]; } else { f = 0; if (hdr[0] >= 0x80 && hdr[0] < 0x90) { f = 1; } if (f) { bit = hdr[0] - 0x78; } else { bit = 0; } }
        if (!(bits->local.got.flags & (1 << bit))) {
            bit = ppp_configure_option_bit(hdr[0]);
            bits->local.got.flags |= 1 << bit;
        }
        r = ipcp_merge_config_options(&arg, bits, p, hdr, 0);
        if (r == -1) {
            return -1;
        }
        if (r == 4) {
            bit = ppp_configure_option_bit(hdr[0]);
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
inline uaddr build_requested_options(IpcpConfig *opts) {
    uaddr t;
    uaddr v = 0;
    t = v;
    t = ((uaddr)init_net_buffer_entry((u16)(0)));
    if (t == 0) {
        return v;
    }
    append_masked_ipcp_options(&t, &opts->local.got, opts->local.got.flags);
    v = t;
    return v;
}
inline s32 read_option_byte(void *p) {
    if (ppp_buffer_read(p, &lcp_read_byte_buffer, 1) != 1) {
        return -1;
    }
    return (s16)lcp_read_byte_buffer;
}
s16 TLobby__sub_803FF858(PppFsm *fsm, PppHeader *msg, PppFrame *expected) {
    uaddr cur;
    s16 err;
    s16 a;
    s16 b;
    err = 0;
    if (msg->id != fsm->id) {
        return -1;
    }
    cur = build_requested_options((IpcpConfig *)fsm->opts);
    if (msg->len != (u16)get_field_4((PppFrame *)cur)) {
        err = 1;
    } else {
        while ((a = read_option_byte(&cur)) != -1) {
            b = read_option_byte(&expected);
            if (b == -1 || b != a) {
                err = 1;
                break;
            }
        }
    }
    if (err != 0) {
        return -1;
    }
    fsm->ack_count++;
    return 0;
}
#pragma pop
#pragma pop

s16 TLobby__sub_803FF9A4(PppFsm *self, PppHeader *src, PppFrame *bits) {
    u32 sh;
    void *buf;
    unsigned int new_var;
    IpcpConfig *base;
    s32 n;
    s16 r;
    u8 hdr[2];
    s16 k;
    s16 res;
    void append_ipcp_option(PppFrame **pbuf, IpcpOptions *opt, s32 type, s32 len, void *src);
    base = (IpcpConfig *)self->opts;
    n = src->len;
    k = 2;
    buf = 0;
    base->peer.got.flags = 0;
    while (n > 0 && (s16)read_2_bytes((void *)hdr, &bits) != -1) {
        n -= hdr[1];
        if (n < 0) {
            return -1;
        }
        res = ipcp_merge_config_options(&bits, base, &base->peer, hdr, 1);
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
        append_ipcp_option((PppFrame **)&buf, &base->peer.got, hdr[0], hdr[1], &bits);
        if (res > 3) {
            ppp_fsm_send_packet(self, k, src->id, buf);
        }
    }

    if (k == 3) {
        if (self->f6 != 0) {
            self->f6--;
        } else {
            k = 4;
            ppp_fsm_send_packet(self, 4, src->id, buf);
        }
    }
    if (k > 3) {
        return (s16)(2 != k);
    }
    ppp_fsm_send_packet(self, k, src->id, buf);
    return (s16)(2 != k);
}
#pragma push
#pragma dont_inline off
#pragma inline_depth(4)
s16 ipcp_merge_config_options(void *cursor, IpcpConfig *cfg, IpcpSide *side, u8 *hdr, s16 c) {
    s16 len;
    s16 res;
    s16 ch;
    res = 2;
    len = hdr[1] - 2;
    switch (hdr[0]) {
    case 1:
        side->got.our_addr = (ppp_buffer_read(cursor, lbl_805D7AA8, 4) != 4) ? 0 : TLobby__sub_80402AFC(lbl_805D7AA8);
        side->got.his_addr = (ppp_buffer_read(cursor, lbl_805D7AA8, 4) != 4) ? 0 : TLobby__sub_80402AFC(lbl_805D7AA8);
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
        side->got.vj_protocol = (s16)((ppp_buffer_read(cursor, lbl_805D7AA8, 2) != 2) ? -1 : read_network_u16_be(lbl_805D7AA8));
        len -= 2;
        if (!(side->flags & 4)) {
            if (side->got.vj_protocol == 0x2d) {
                ch = (ppp_buffer_read(cursor, &lcp_read_byte_buffer, 1) != 1) ? -1 : (s16)lcp_read_byte_buffer;
                if (ch == -1) {
                    return -1;
                }
                side->got.vj_slots = ch + 1;
                ch = (ppp_buffer_read(cursor, &lcp_read_byte_buffer, 1) != 1) ? -1 : (s16)lcp_read_byte_buffer;
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
                ch = (ppp_buffer_read(cursor, &lcp_read_byte_buffer, 1) != 1) ? -1 : (s16)lcp_read_byte_buffer;
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
                ch = (ppp_buffer_read(cursor, &lcp_read_byte_buffer, 1) != 1) ? -1 : (s16)lcp_read_byte_buffer;
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
        side->got.our_addr = (ppp_buffer_read(cursor, lbl_805D7AA8, 4) != 4) ? 0 : TLobby__sub_80402AFC(lbl_805D7AA8);
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
        side->got.dns[0] = (ppp_buffer_read(cursor, lbl_805D7AA8, 4) != 4) ? 0 : TLobby__sub_80402AFC(lbl_805D7AA8);
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
        side->got.dns[1] = (ppp_buffer_read(cursor, lbl_805D7AA8, 4) != 4) ? 0 : TLobby__sub_80402AFC(lbl_805D7AA8);
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
            if (((ppp_buffer_read(cursor, &lcp_read_byte_buffer, 1) != 1) ? -1 : (s16)lcp_read_byte_buffer) == -1) {
                return -1;
            }
        }
    }
    return res;
}
#pragma pop

void append_ipcp_option(PppFrame **pbuf, IpcpOptions *opt, s32 type, s32 len, void *src);
PppFrame *build_ipcp_config_request(PppFsm *self) {
    PppFrame *blk;
    s16 i;
    s16 flags;
    u8 *p;
    IpcpConfig *base;
    base = self->opts;
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
            append_ipcp_option(&blk, &base->local.got, (i < 8) ? i : ((i < 0x20) ? i + 0x78 : 0), *p, 0);
        }
        p++;
    }
done:
    return blk;
}

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
void append_masked_ipcp_options(uaddr *self, void *opt, s32 mask) {
    s16 new_var;
    s16 i;
    s32 m;
    if (*self == 0) {
        *self = (uaddr)init_net_buffer_entry(0);
        if (*self == 0) {
            return;
        }
    }
    m = (new_var = (s16)mask);
    for (i = 1; i < 0x20; i++) {
        if (m & (1 << i)) {
            append_ipcp_option((PppFrame **)self, (IpcpOptions *)opt, optnum_80400270(i), lbl_8047FE3C[i], 0);
        }
    }
}
#pragma pop
void append_ipcp_option(PppFrame **pbuf, IpcpOptions *opt, s32 type, s32 len, void *src) {
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
        *p++ = ppp_buffer_read(src, &lcp_read_byte_buffer, 1) != 1 ? -1 : (s16)lcp_read_byte_buffer;
    }
    buf->len += len;
}

IpcpState lbl_805C0328;
