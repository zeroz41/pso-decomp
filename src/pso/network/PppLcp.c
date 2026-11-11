/* PPP LCP, the protocol that names itself "Lcp" (805E1178), and its state object (.bss 805C0400) (a C library,
 * built with GC/1.2.5n). */
#include "types.h"
#include "pso/network/TLobby_803FC178.h"
#include "pso/network/TLobby_803FCF44.h"
#include "pso/network/TLobby_804050DC.h"
#include "pso/network/TLobby_8041112C.h"
typedef struct St_8040098C St_8040098C;
typedef struct Ent_80400744 Ent_80400744;
typedef struct Self_80400744 Self_80400744;
typedef struct Msg_80400744 Msg_80400744;
/* This file's functions. */
s32 configure_mode_by_type(void *self, s16 type);
u16 get_field_4(void *self);
s32 mark_ready(void *self);
s32 mark_sub_ready(void *obj);
void queue_command_81(void);
s32 read_2_bytes(void *self, void *src);
void reset_connection_slot(void *self);
void reset_connection_state(void *self);
void reset_lcp_options(void *self);
void set_active(void *self);
s32 set_active_flag(void *self);
s32 set_flags_and_state(void *self);
u8 *write_network_u32_be(u8 *p, u32 v);
#include "pso/network/NetworkRuntime.h"
#include "pso/network/TLobby_804048E8.h"
extern s32 is_timed_out(void);
extern void set_ppp_auth_protocol(u16 protocol);
#include "pso/network/NetworkTransport.h"

typedef struct LcpState {
    Obj_803FEF4C proto;
    u8 data[0xA8 - sizeof(Obj_803FEF4C)];
} LcpState;

/* LCP option values; mask has bit N set for option type N. */
typedef struct LcpVals {
    s16 mask;
    u16 mru;
    u32 accm;
    u16 auth_proto;
    u8 pad0A[2];
    s32 magic;
    u8 pad10[4];
    u8 chap_alg;
    u8 f15;
    u8 pad16[2];
} LcpVals;
typedef char LcpVals_size_check[sizeof(LcpVals) == 0x18 ? 1 : -1];

/* One side of the LCP negotiation: the options wanted and the ones agreed. */
typedef struct LcpSide {
    s16 mask;
    u8 pad2[2];
    LcpVals want;
    LcpVals got;
} LcpSide;
typedef char LcpSide_size_check[sizeof(LcpSide) == 0x34 ? 1 : -1];

/* The LCP options object (fsm->p30, lbl_805C0400's opts). */
typedef struct LcpOpts {
    LcpSide local;
    LcpSide remote;
} LcpOpts;
typedef char LcpOpts_size_check[sizeof(LcpOpts) == 0x68 ? 1 : -1];
struct St_8040098C { s8 f0; u8 f1; u8 f2; u8 pad3[0x69]; u8 f6C[0x9C]; s32 f108; s32 f10C; };

#include <stddef.h>
#include "pso/network/NetStackTypes.h"

typedef struct Ent_80400744 { s16 f0; s16 f2; s16 f4; s16 f6; u32 f8; u32 fC; u32 f10; } Ent_80400744;
struct Self_80400744 { u8 pad[0xC]; u8 *f0C; u8 pad10[0x20]; Ent_80400744 *f30; };
struct Msg_80400744 { u32 f0; s16 f4; u16 f6; u32 f8; u16 fC; s16 fE; };

typedef struct Cfg_804019A8 {
    u8 pad[4];
    s16 flags;
    u8 pad6[6];
    u16 mode;
    u8 padE[0xA];
    u8 b18;
    u8 b19;
} Cfg_804019A8;

void TLobby__sub_803F97E8(int);
#include "pso/network/PppBuffer.h"


s32 wait_for_connection(Conn_804004DC *c) {
    NetThreadState *g;
    u8 *sub;
    sub = c->sub;
    g = &lbl_805C18A0;
    c->abort = 0;
    while (c->state != 5) {
        if (is_timed_out() != 0 || c->abort != 0 || *sub == 4) {
            update_connection_state((int)c);
            c->abort = 0;
            return -1;
        }
        unlock_mutex(g->mutex);
        TLobby__sub_803F97E8(100);
        process_expired_timers();
        lock_mutex(g->mutex);
    }
    c->abort = 0;
    return 0;
}

extern u8 lbl_805E1178;
extern LcpState lbl_805C0400;
extern s32 TLobby__sub_8040172C(Conn_804004DC *c);
extern s32 TLobby__sub_80400C4C(Conn_804004DC *fsm, Msg_803FA664 *msg, s32 src);
extern s32 TLobby__sub_80400DA8(Conn_804004DC *fsm, Msg_803FA664 *msg, s32 src);
s16 TLobby__sub_804010A0(Obj_803FF858 *fsm, Msg_803FA664 *msg, u32 src);
s32 TLobby__sub_80400F1C(Obj_803FF858 *arg0, Msg_803FA664 *arg1, u32 arg2);
typedef struct LcpProto_8040059C {
    const char *name;
    u16 proto;
    u16 h6;
    u8 b8;
    u8 b9;
    u8 bA;
    u8 bB;
    s32 timeout;
    void *f10;
    void *f14;
    void *f18;
    void *f1C;
    void *f20;
    void *f24;
    void *f28;
    void *f2C;
    void *f30;
    void *f34;
    void *f38;
} LcpProto_8040059C;
typedef struct LcpState_8040059C { LcpProto_8040059C proto; LcpOpts opts; u8 pad_a4[4]; } LcpState_8040059C;
typedef char LcpState_8040059C_size_check[sizeof(LcpState_8040059C) == 0xA8 ? 1 : -1];

void TLobby__sub_8040059C(u8 *conn)
{
  LcpProto_8040059C *proto = &((LcpState_8040059C *)&lbl_805C0400)->proto;
  Conn_804004DC *e = (Conn_804004DC *)(conn + 4);
  LcpOpts *area = &((LcpState_8040059C *)&lbl_805C0400)->opts;
  const LcpVals *tbl = (const LcpVals *)&lbl_8047FE50;
  proto->name = (const char *)&lbl_805E1178;
  proto->proto = 0xC021;
  proto->h6 = 0xFFE;
  proto->b8 = 0;
  proto->b9 = 20;
  proto->bA = 10;
  proto->bB = 3;
  proto->timeout = 1000;
  proto->f10 = (void *)TLobby__sub_80400988;
  proto->f14 = (void *)reset_lcp_options;
  proto->f18 = (void *)TLobby__sub_80400B98;
  proto->f1C = (void *)TLobby__sub_8040098C;
  proto->f20 = (void *)reset_connection_slot;
  proto->f24 = (void *)queue_command_81;
  proto->f28 = (void *)TLobby__sub_8040172C;
  proto->f2C = (void *)TLobby__sub_804010A0;
  proto->f30 = (void *)TLobby__sub_80400F1C;
  proto->f34 = (void *)TLobby__sub_80400DA8;
  proto->f38 = (void *)TLobby__sub_80400C4C;
  e->sub = conn;
  e->proto = proto;
  e->opts = area;
  area->local.want = *tbl;
  area->local.mask = 0x1AE;
  area->remote.want = *tbl;
  area->remote.got = *tbl;
  area->remote.mask = 0x1AE;
  TLobby__sub_803FD694((u8 *)e);
}

extern s16 TLobby__sub_80400744(int a0, void *a1) {
    s32 pad[2];
    s32 *pp;
    void *self = (void *)a0;
    Msg_80400744 *msg = (Msg_80400744 *)a1;
    Ent_80400744 *p;
    Ent_80400744 *q;
    Self_80400744 *s = (Self_80400744 *)self;
    Ent_80400744 *t;
    u16 m6;
    u32 id;
    s32 sid;
    u32 v;
    u32 w;
    pp = pad;

    TLobby__sub_803FE600((O_803FE600 *)self);
    set_flags_and_state(self);
    *s->f0C = 1;
    if (*s->f0C >= 1) {
        id = msg->fC;
        p = t = s->f30;
        sid = (s16)id;
        if (sid >= 0x80 && sid <= 0x1000) {
            t->f4 |= 2;
            t->f6 = (u16)id;
        }
        p->f8 = msg->f0;
        if (p->f8 != 0xffffffff) {
            p->f4 |= 4;
            p->f0 |= 4;
        } else {
            p->f4 &= ~4;
            p->f0 &= ~4;
        }
        m6 = msg->f6;
        if ((m6 & 0x80) || m6 == 4) {
            configure_mode_by_type((void *)((u8 *)p + 0x34), m6 & 0x7f);
            if (lbl_805D7A90 & 2) {
                configure_mode_by_type((void *)p, msg->f6 & 0x7f);
            }
        } else {
            configure_mode_by_type((void *)((u8 *)p + 0x34), m6);
            configure_mode_by_type((void *)p, (s16)msg->f6);
        }
        v = msg->f8;
        if (v != 0) {
            p->f4 |= 0x20;
        } else {
            p->f4 &= ~0x20;
        }
        p->f10 = v;
        if (msg->fE == 0) {
            p->f0 |= 0x80;
        } else {
            p->f0 &= ~0x80;
        }
        if (msg->f4 == 0) {
            p->f0 |= 0x100;
        } else {
            p->f0 &= ~0x100;
        }
        q = (Ent_80400744 *)((u8 *)p + 0x34);
        w = msg->f8;
        if (w != 0) {
            q->f4 |= 0x20;
        } else {
            q->f4 &= ~0x20;
        }
        q->f10 = w;
        q = (Ent_80400744 *)((u8 *)p + 0x34);
        if (msg->fE == 0) {
            q->f0 |= 0x80;
        } else {
            q->f0 &= ~0x80;
        }
        q = (Ent_80400744 *)((u8 *)p + 0x34);
        if (msg->f4 == 0) {
            q->f0 |= 0x100;
        } else {
            q->f0 &= ~0x100;
        }
        TLobby__sub_803FD958((u8 *)self);
    }
    return 0;
}

void TLobby__sub_80400988(void) {

}

void TLobby__sub_8040098C(Conn_804004DC *c) {
    LcpOpts *info = c->opts;
    St_8040098C *st;
    u32 now;

    ((St_8040098C *)c->sub)->f0 = 2;
    ((St_8040098C *)c->sub)->f2 &= ~0x30;
    ((St_8040098C *)c->sub)->f10C = 0;
    if (info->local.got.mask & 8) {
        switch (info->local.got.auth_proto) {
        case 0xC023:
            set_active(c->sub);
            break;
        case 0xC223:
            mark_sub_ready(c->sub);
            set_active_flag(c->sub);
            break;
        }
    }
    if (info->remote.got.mask & 8) {
        switch (info->remote.got.auth_proto) {
        case 0xC023:
            mark_ready(c->sub);
            break;
        case 0xC223:
            set_active_flag(c->sub);
            mark_sub_ready(c->sub);
            break;
        }
    }
    st = (St_8040098C *)c->sub;
    if (!(st->f2 & 0x30)) {
        st->f0 = 3;
        get_time_ms((s32 *)&now);
        st->f108 = (s16)(now / 1000);
        TLobby__sub_803FD958(st->f6C);
    }
}

void TLobby__sub_80400ACC(O_80400ACC *o) {
    u32 t;
    if ((o->b2 & 0x30) == 0) {
        o->b0 = 3;
        get_time_ms((s32 *)&t);
        o->f108 = (s16)(t / 1000);
        TLobby__sub_803FD958((u8 *)o + 0x6C);
    }
}

void reset_connection_slot(void *self) {
    u8 *arg0 = (u8 *)self;
    typedef struct Fields_arg0 { u8 pad_0[12]; s8 * field_C; } Fields_arg0;
    s8 *temp_r31;
    temp_r31 = (s8 *)(((Fields_arg0*)arg0)->field_C);
    *temp_r31 = 4;
    TLobby__sub_803FD85C(temp_r31 + 0x6C);
    reset_connection_state((void *)(temp_r31 + 0x38));
}

void queue_command_81(void) {
    TLobby__sub_804062A0(0x81);
}

void TLobby__sub_80400B98(u8 *arg0) {
    **(s8 **)((s8 *)arg0 + 0xC) = 1;
}

void reset_lcp_options(void *self) {
    LcpOpts *s;
    s32 t;
    s = ((Conn_804004DC *)self)->opts;
    if (s->local.want.mask & 0x20) {
        get_time_ms(&t);
        s->local.want.magic += t;
    }
    s->local.got = s->local.want;
    s->local.mask |= s->local.want.mask;
    s->remote.got.mask = 0;
    s->remote.mask |= s->remote.want.mask;
}

extern s32 TLobby__sub_80400C4C(Conn_804004DC *fsm, Msg_803FA664 *msg, s32 src) {
    s16 last = 0;
    LcpOpts *o = fsm->opts;
    s32 left = msg->h2;
    u8 opt[12];
    s16 n;
    u8 len;
    u8 type;

    if (msg->b1 != fsm->id) {
        return -1;
    }
    while (left > 0 && (s16)read_2_bytes((opt), &src) != -1) {
        len = opt[1];
        left -= len;
        if (left < 0) {
            return -1;
        }
        if (opt[0] <= 8 && (opt[0] < last || !(o->local.got.mask & (1 << opt[0])))) {
            return -1;
        }
        for (n = len - 2; n-- > 0;) {
            if ((TLobby__sub_80401BCC(&src, lobby_read_byte_buffer, 1) != 1 ? -1 : (s16)lobby_read_byte_buffer[0]) == -1) {
                return -1;
            }
        }
        last = type = opt[0];
        if (type <= 8 && (type != 3 || !(o->local.got.mask & (1 << type)))) {
            o->local.got.mask &= ~(1 << type);
        }
    }
    return 0;
}

#pragma push
#pragma opt_common_subs on
extern s32 TLobby__sub_80400DA8(Conn_804004DC *fsm, Msg_803FA664 *msg, s32 src) {
    LcpOpts *opts = fsm->opts;
    LcpSide *local = &opts->local;
    s32 remaining = msg->h2;
    s16 last = 0;
    u8 hdr[2];
    s16 r;
    if (msg->b1 != fsm->id) {
        return -1;
    }
    while (remaining > 0 && (s16)read_2_bytes((hdr), &src) != -1) {
        remaining -= hdr[1];
        if (remaining < 0) {
            return -1;
        }
        if (hdr[0] <= 8) {
            if (hdr[0] < last || (opts->local.got.mask & (1 << hdr[0])) == 0) {
                if (opts->local.got.mask & (1 << hdr[0])) {
                    return -1;
                }
                opts->local.got.mask |= 1 << hdr[0];
                last = 9;
            } else {
                last = hdr[0];
            }
        }
        r = parse_lcp_option((s32)&src, (u8 *)opts, (u8 *)local, hdr, 0);
        if (r == -1) {
            return -1;
        }
        if (r == 4 && hdr[0] <= 8 && (hdr[0] != 3 || (opts->local.got.mask & (1 << hdr[0])) == 0)) {
            opts->local.got.mask &= ~(1 << hdr[0]);
        }
    }
    return 0;
}
#pragma pop
extern u8 lbl_8047FE68[];
extern void TLobby__sub_804017D8(u32 *self_m, void *src, u8 idx, u8 val, s32 *flag);
inline void loop_8040172C(u32 *self, void *src, s16 mask) {
    s16 i;
    i = 1;
    while (i <= 8) {
        if (mask & (1 << i)) {
            TLobby__sub_804017D8(self, src, i, lbl_8047FE68[i], 0);
        }
        i++;
    }
}
inline s32 read_80400F1C(u32 *p) {
    if (TLobby__sub_80401BCC(p, lobby_read_byte_buffer, 1) != 1) {
        return -1;
    }
    return (s16)lobby_read_byte_buffer[0];
}
#pragma push
#pragma dont_inline off
#pragma inline_depth(4)
inline u32 first2_80400F1C(Obj_803FF858 *fsm) {
    u8 *o = (u8 *)fsm->p30;
    u32 t = 0;
    t = (u32)init_net_buffer_entry(0);
    if (t == 0) {
        return 0;
    }
    loop_8040172C(&t, o + 0x1c, *(s16 *)(o + 0x1c));
    return t;
}
s32 TLobby__sub_80400F1C(Obj_803FF858 *arg0, Msg_803FA664 *arg1, u32 arg2) {
    s16 err;
    s16 a;
    s16 b;
    err = 0;
    if (arg1->b1 != arg0->b1) {
        return -1;
    }
    {
        u32 cur = first2_80400F1C(arg0);
        if (arg1->h2 != get_field_4((void *)cur)) {
            err = 1;
        } else {
            while ((a = read_80400F1C(&cur)) != -1) {
                b = read_80400F1C(&arg2);
                if (b == -1 || b != a) {
                    err = 1;
                    break;
                }
            }
        }
    }
    if (err != 0) {
        return -1;
    }
    return 0;
}
#pragma pop

#pragma push
#pragma dont_inline off
#pragma inline_depth(4)
inline void add_lcp_options(PppFrame **pbuf, s16 *vals, s16 mask) {
    s16 i;

    for (i = 1; i <= 8; i++) {
        if (mask & (1 << i)) {
            TLobby__sub_804017D8((u32 *)pbuf, vals, i, lbl_8047FE68[i], NULL);
        }
    }
}

s16 TLobby__sub_804010A0(Obj_803FF858 *fsm, Msg_803FA664 *msg, u32 src) {
    LcpOpts *opts;
    s32 remaining;
    s16 status;
    s16 r;
    PppFrame *reply;
    u8 hdr[2];
    s16 missing;
    s32 TLobby__sub_803FE6CC(void *, u8, u8, void *); /* declared here with other parameter types; the definition is s32 (void *, int, int, void *) */

    status = 2;
    opts = (LcpOpts *)fsm->p30;
    remaining = msg->h2;
    reply = NULL;
    opts->remote.got.mask = 0;
    reply = init_net_buffer_entry(1);
    if (opts->remote.want.f15 != 0) {
        opts->remote.got.auth_proto = 0;
        opts->remote.got.mask |= 8;
    }
    while (remaining > 0 && (s16)read_2_bytes(hdr, &src) != -1) {
        remaining -= hdr[1];
        if (remaining < 0) {
            return -1;
        }
        r = parse_lcp_option((s32)&src, (u8 *)opts, (u8 *)&opts->remote, hdr, 1);
        if (r == -1) {
            return -1;
        }
        if (r < status) {
            continue;
        }
        if (r > status) {
            reply = NULL;
            status = r;
        }
        if (r != 4 && hdr[0] <= 8) {
            opts->remote.got.mask |= 1 << hdr[0];
        }
        TLobby__sub_804017D8((u32 *)&reply, &opts->remote.got.mask, hdr[0], hdr[1], (s32 *)&src);
        if (r >= 3) {
            TLobby__sub_803FE6CC(fsm, status, msg->b1, reply);
        }
    }
    missing = opts->remote.want.mask & ~opts->remote.got.mask;
    if (status == 3) {
        if (fsm->b6 != 0) {
            add_lcp_options(&reply, &opts->remote.got.mask, missing);
            fsm->b6--;
        } else {
            status = 4;
            TLobby__sub_803FE6CC(fsm, 4, msg->b1, reply);
        }
    }
    if (status >= 3) {
        return status != 2;
    }
    TLobby__sub_803FE6CC(fsm, status, msg->b1, reply);
    return status != 2;
}
#pragma pop

#define rd16_804012E0(src) (TLobby__sub_80401BCC((void *)(src), lcp_read_value_buffer, 2) != 2 ? -1 : read_network_u16_be(lcp_read_value_buffer))
#define rd32_804012E0(src) (TLobby__sub_80401BCC((void *)(src), lcp_read_value_buffer, 4) != 4 ? 0 : TLobby__sub_80402AFC(lcp_read_value_buffer))
#define rd8_804012E0(src) (TLobby__sub_80401BCC((void *)(src), lobby_read_byte_buffer, 1) != 1 ? -1 : (s16)lobby_read_byte_buffer[0])
#define F(t, o) (*(t *)((s8 *)(arg2) + (o)))
s16 parse_lcp_option(s32 arg0, u8 *arg1, u8 *arg2, u8 *arg3, s16 arg4) {
    s16 len;
    s16 res;
    s32 t;
    s16 lim;
    res = 2;
    len = arg3[1] - 2;
    switch (arg3[0]) {
    case 1:
        F(s16, 0x1E) = rd16_804012E0(arg0);
        len -= 2;
        if (F(s16, 0x1E) < 0x80) {
            F(s16, 0x1E) = 0x80;
            res = 3;
        } else if (F(s16, 0x1E) > 0x1000) {
            F(s16, 0x1E) = 0x1000;
            res = 3;
        }
        if (arg4 != 0 && (F(s16, 4) & 2) && F(s16, 0x1E) > (lim = F(s16, 6))) {
            F(s16, 0x1E) = lim;
            res = 3;
        }
        break;
    case 2:
        F(u32, 0x20) = rd32_804012E0(arg0);
        len -= 4;
        if (lbl_805D7A7A != 0) {
            res = 4;
        } else if (arg4 == 0 || (F(s16, 4) & 4)) {
            u32 v = F(u32, 0x20) | F(u32, 8);
            if (F(u32, 0x20) != v) {
                F(u32, 0x20) = v;
                res = 3;
            }
        }
        break;
    case 3:
        F(u16, 0x24) = rd16_804012E0(arg0);
        len -= 2;
        if (F(u16, 0x24) == 0xC223) {
            F(s8, 0x30) = rd8_804012E0(arg0);
            len -= 1;
        }
        if (F(u8, 0x19) != 0) {
            u16 v = F(u16, 0x24);
            if (v == 0xC023 || (v == 0xC223 && (s32)F(u8, 0x30) == 5)) {
                F(u16, 0xC) = v;
                F(u8, 0x18) = F(u8, 0x30);
            } else {
                F(u16, 0x24) = 0xC023;
                F(s8, 0x30) = 0;
                res = 3;
                arg3[1] = 4;
                while (len > 0) {
                    len--;
                    if (rd8_804012E0(arg0) == -1) {
                        return -1;
                    }
                }
            }
        } else {
            u16 a = F(u16, 0x24);
            u16 b = F(u16, 0xC);
            if (a != b || (a == 0xC223 && F(s8, 0x30) != F(s8, 0x18))) {
                F(u16, 0x24) = b;
                res = 3;
                F(u8, 0x30) = F(u8, 0x18);
            }
        }
        if (res == 2) {
            set_ppp_auth_protocol(F(u16, 0x24));
        }
        break;
    case 5:
        F(u32, 0x28) = rd32_804012E0(arg0);
        len -= 4;
        if (F(u32, 0x28) == 0 || *(u32 *)((s8 *)arg1 + 0x5C) == *(u32 *)((s8 *)arg1 + 0x28)) {
            get_time_ms(&t);
            res = 3;
            F(u32, 0x28) += t;
        }
        break;
    case 7:
        if (!(F(s16, 0) & 0x80)) {
            res = 4;
        }
        break;
    case 8:
        if (lbl_805D7A7A != 0) {
            res = 4;
        } else if (!(F(s16, 0) & 0x100)) {
            res = 4;
        }
        break;
    case 0:
        res = 4;
        break;
    default:
        res = 4;
        break;
    }
    if (arg3[0] > 8 || !(F(s16, 0) & (1 << arg3[0]))) {
        res = 4;
    }
    if (len < 0) {
        return -1;
    }
    if (arg4 == 0 && len > 0) {
        while (len-- > 0) {
            if (rd8_804012E0(arg0) == -1) {
                return -1;
            }
        }
    }
    return res;
}

#pragma push
#pragma dont_inline off
#pragma inline_depth(4)
s32 TLobby__sub_8040172C(Conn_804004DC *c) {
    u32 obj;
    LcpOpts *s;
    s = c->opts;
    obj = 0;
    obj = (u32)init_net_buffer_entry(0);
    if (obj == 0) {
        return 0;
    }
    loop_8040172C(&obj, &s->local.got, s->local.got.mask);
    return obj;
}
#pragma pop

extern void TLobby__sub_804017D8(u32 *self_m, void *src, u8 idx, u8 val, s32 *flag) {
p803FE518_UnkBuf803FF344 *p;
p803FE518_UnkSrc803FE518 *s;
u8 *out;
u8 *cnt;
int c;
s16 rem;
rem = ((u8) val) - 2;
if ((*((p803FE518_UnkBuf803FF344 **) self_m)) == ((void *) 0))
{
*((p803FE518_UnkBuf803FF344 **) self_m) = (p803FE518_UnkBuf803FF344 *)(((void*)init_net_buffer_entry((u16)(1))));
if ((*((p803FE518_UnkBuf803FF344 **) self_m)) == ((void *) 0))
{
return;
}
}
p = *((p803FE518_UnkBuf803FF344 **) self_m);
s = (p803FE518_UnkSrc803FE518 *)(src);
out = p->data;
out = out + p->len;
*(out++) = idx;
cnt = out;
*(out++) = val;
switch (idx)
{
case 1:
out = write_network_u16_be((u8 *)(out), (u16)(s->w2));
rem -= 2;
break;
case 2:
out = write_network_u32_be((u8 *)(out), (u32)(s->w4));
rem -= 4;
break;
case 3:
out = write_network_u16_be((u8 *)(out), (u16)(s->h8));
rem -= 2;
if (s->h8 == 0xc223)
{
*cnt = 5;
*(out++) = s->b14;
if (val == 4)
{
val++;
}
rem = 0;
}
if (s->h8 == 0xc023)
{
*cnt = 4;
if (val == 5)
{
val--;
}
rem = 0;
}
break;
case 5:
out = write_network_u32_be((u8 *)(out), (u32)(s->wc));
rem -= 4;
break;
case 4:
case 6:
case 7:
case 8:
break;
}
while ((rem--) > 0)
{
if (((s16) (TLobby__sub_80401BCC((void *)((u8 *) flag), (void *)(&(*(u8*)&lobby_read_byte_buffer)), (int)(1)))) != 1)
{
c = -1;
}
else
{
c = (s16) (*(u8*)&lobby_read_byte_buffer);
}
*(out++) = c;
}
p->len += val;
}

s32 configure_mode_by_type(void *self, s16 type) {
    Cfg_804019A8 *c = (Cfg_804019A8 *)self;
    if (type == 0) {
        c->flags |= 8;
        c->mode = 0xC023;
    } else if (type == 1) {
        c->flags &= ~8;
        c->b19 = 0;
    } else if (type == 2) {
        c->flags |= 8;
        c->mode = 0xC223;
        c->b18 = 5;
        c->b19 = 0;
    } else if (type == 4) {
        c->flags |= 8;
        c->mode = 0xC223;
        c->b18 = 5;
        c->b19 = 1;
    } else {
        return 1;
    }
    return 0;
}

LcpState lbl_805C0400;
