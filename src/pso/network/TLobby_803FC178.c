#include "types.h"
#include "pso/network/TLobby_803FC178.h"
#include "pso/network/TLobby_803FCF44.h"
#include "pso/network/TLobby_804050DC.h"
/* This file's functions. */
u8 * alloc_from_buffer(void *self, s16 arg1);
s32 clear_socket_slot(s16 i);
s32 configure_mode_by_type(void *self, s16 type);
void dispatch_received_packet(void *self, s32 arg1);
void free_field_98(void *self);
void free_field_98_and_clear(void *self);
s16 get_checked_status_value(s16 arg0);
u16 get_field_4(void *self);
void handle_request_timeout(void *self);
void init_md5_state(void *self);
void init_net_block_620(void);
s32 init_net_block_620_secondary(void);
void init_net_state_a(void);
s32 init_net_state_b(void);
void init_net_state_c(void);
s32 init_net_subsystem_block(void);
s32 mark_ready(void *self);
s32 mark_sub_ready(void *obj);
s16 parse_lcp_option(s32 arg0, u8 *arg1, u8 *arg2, u8 *arg3, s16 arg4);
void queue_command_81(void);
s32 read_2_bytes(void *self, void *src);
void reset_connection_slot(void *self);
void reset_connection_state(void *self);
void save_timer_state(void *self);
void set_active(void *self);
s32 set_active_flag(void *self);
s32 set_flags_and_state(void *self);
void update_connection_state(int arg0);
void MD5Transform(u32 *state, u8 *block);
u8 *write_network_u32_be(u8 *p, u32 v);
#include "pso/network/NetworkRuntime.h"
#include "pso/network/TLobby_804048E8.h"
extern s32 is_timed_out(void);
extern void set_ppp_auth_protocol(u16 protocol);
#include "pso/network/NetworkTransport.h"

struct Self_803FD74C;

struct Self_803FD85C;

#include <stddef.h>
#include "pso/network/NetStackTypes.h"

extern RecoveredGlobal_804050DC_lbl_805C18A0 lbl_805C18A0;
extern RecoveredGlobal_803FD520_lbl_805C0310 lobby_net_buffer_desc_b;
void TLobby__sub_803F76F0(void *); /* declared with 1 parameter; the definition is void (void) */
s32 TLobby__sub_803F79BC(void *);
s32 TLobby__sub_803F778C(void *);
s32 TLobby__sub_804036FC(u8 *arg0);
s32 TLobby__sub_80403DA8();
void TLobby__sub_803F8A08(void *);
void TLobby__sub_803F8A9C(void *);
s32 send_network_frame(u16, u8 *);
s32 TLobby__sub_804037B0(s32 arg0, u16 arg1);
void TLobby__sub_803F892C(void *);
void TLobby__sub_803F8958(void *);
void TLobby__sub_803F87DC(void *);
void TLobby__sub_803F89D8(void *);
extern Tbl_80408718 lbl_805C1AB0;
void TLobby__sub_803F97E8(int);
extern u8 lbl_805C0038[];
s16 TLobby__sub_80401BCC(void *self, void *dst, u16 n);
s32 TLobby__sub_80403730(u8 *dst, unsigned short n);

void init_net_state_a(void) {
    TLobby__sub_803F76F0((void *)&lbl_805C02D0);
}

s32 init_net_state_b(void) {
    init_net_buffer_table((void *)&lbl_805C02D0);
    return 0;
}

extern s16 get_remaining(s32 x);
s16 TLobby__sub_803FC1CC(Conn_804004DC *c, s32 timeout) {
    PppChap *auth;
    u8 *sub;
    RecoveredGlobal_804050DC_lbl_805C18A0 *g;

    sub = c->sub;
    auth = (PppChap *)c->opts;
    if (lbl_805D7A90 & 2) {
        auth->active = 1;
        TLobby__sub_803FE820((s32)c);
        TLobby__sub_803FE6CC(c, 1, 0, TLobby__sub_803FCF44(c));
    } else {
        auth->active = 0;
    }
    g = &lbl_805C18A0;
    c->abort = 0;
    while (c->state != 5) {
        if (is_timed_out() != 0 || c->abort != 0 || *sub == 4) {
            c->abort = 0;
            if (lbl_805D7A80 != 0) {
                lbl_805D7A82 = 6;
            } else {
                lbl_805D7A82 = 5;
            }
            lobby_modem_connect_state = 8;
            return -1;
        }
        if (get_remaining(timeout) != 0) {
            return -0x12;
        }
        unlock_mutex(g->value);
        TLobby__sub_803F97E8(100);
        process_expired_timers();
        lock_mutex(g->value);
    }
    c->abort = 0;
    return 0;
}

struct Buf_803FC684;
struct N_80405298;
Buf_803FC684 lbl_805C0180;
PppAuthState lbl_805C02D0;
typedef struct Proto3_803FC318 {
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
} Proto3_803FC318;
typedef struct Buf3_803FC318 { char a[0x80]; char b[0x80]; u8 opts[0x14]; Proto3_803FC318 proto; } Buf3_803FC318;
typedef struct Timer3_803FC318 {
    u8 pad0[0x10];
    void *callback;
    void *arg;
    u8 pad18[4];
} Timer3_803FC318;
typedef struct Self3_803FC318 {
    u8 f0; u8 f1; u8 f2; u8 f3; u8 f4; u8 f5; u8 f6; u8 f7;
    u8 pad8[4];
    u8 *sub;
    Timer3_803FC318 timer;
    Proto3_803FC318 *proto;
    void *opts;
} Self3_803FC318;
#define BUF3_803FC318 (*(Buf3_803FC318 *)&lbl_805C0180)
extern void TLobby__sub_803FC318(u8 *conn) {
    Self3_803FC318 *fsm = (Self3_803FC318 *)(conn + 0xA0);
    Timer3_803FC318 *timer;

    if (fsm->opts == NULL) {
        timer = &fsm->timer;
        BUF3_803FC318.proto.name = (const char *)&lbl_805E1160;
        BUF3_803FC318.proto.proto = 0xC223;
        BUF3_803FC318.proto.h6 = 0x70;
        BUF3_803FC318.proto.b8 = 3;
        BUF3_803FC318.proto.bB = 0;
        BUF3_803FC318.proto.b9 = lbl_805C02D0.f36;
        BUF3_803FC318.proto.bA = lbl_805C02D0.f37;
        BUF3_803FC318.proto.timeout = lbl_805C02D0.f38 * 1000;
        BUF3_803FC318.proto.f10 = (void *)TLobby__sub_803FE84C;
        BUF3_803FC318.proto.f14 = (void *)TLobby__sub_803FE84C;
        BUF3_803FC318.proto.f18 = (void *)TLobby__sub_803FE84C;
        BUF3_803FC318.proto.f1C = (void *)TLobby__sub_803FE84C;
        BUF3_803FC318.proto.f20 = (void *)TLobby__sub_803FE84C;
        BUF3_803FC318.proto.f24 = (void *)TLobby__sub_803FE84C;
        BUF3_803FC318.proto.f28 = (void *)TLobby__sub_803FCF44;
        BUF3_803FC318.proto.f2C = (void *)TLobby__sub_803FE844;
        BUF3_803FC318.proto.f30 = (void *)TLobby__sub_803FE844;
        BUF3_803FC318.proto.f34 = (void *)TLobby__sub_803FE844;
        BUF3_803FC318.proto.f38 = (void *)TLobby__sub_803FE844;
        fsm->sub = conn;
        fsm->proto = &BUF3_803FC318.proto;
        fsm->opts = BUF3_803FC318.opts;
        fsm->f4 = fsm->proto->b9;
        fsm->f7 = fsm->proto->bA;
        fsm->f5 = fsm->proto->bB;
        fsm->f0 = 0;
        fsm->f3 = fsm->f4;
        fsm->f6 = fsm->f7;
        timer->callback = (void *)TLobby__sub_803FC728;
        timer->arg = fsm;
        TLobby__sub_80405298((N_80405298 *)timer, fsm->proto->timeout);
    }
}

s32 set_active_flag(void *self) {
    u8 *arg0 = (u8 *)self;
    *(s8 *)((s8 *)arg0 + 0xA0) = 2;
    *(u8 *)((s8 *)arg0 + 0xA2) = (u8) (*(u8 *)((s8 *)arg0 + 0xA2) | 0x20);
    *(u8 *)((s8 *)arg0 + 2) = (u8) (*(u8 *)((s8 *)arg0 + 2) | 0x20);
    return 0;
}

s32 mark_sub_ready(void *obj) {
    Obj_803FC480 *self = (Obj_803FC480 *)obj;
    Sub_803FC480 *s = &self->sub;
    s->f0 = 1;
    s->f2 |= 0x10;
    self->f2 |= 0x10;
    s->f3 = s->f4;
    return 0;
}

struct O_80400ACC;
struct Outer_80401CAC;

void dispatch_received_packet(void *self, s32 arg1) {
    u8 *arg0 = (u8 *)self;
    Hdr_803FC4B4 hdr;
    u8 temp_r0;
    u8 temp_r0_2;
    u8 temp_r0_3;
    u8 *temp_r30;
    u8 *temp_r30_2;
    u8 *temp_r30_3;
    u8 *temp_r30_4;

    if ((s16)TLobby__sub_803FE8BC((u8 *)&hdr, &arg1) != -1) {
        hdr.len -= 4;
        TLobby__sub_80401CAC((Outer_80401CAC *)&arg1, hdr.len);
        switch (hdr.type) {
        case 1:
            TLobby__sub_803FCC10((void *) (arg0), (void *)&hdr, (int) (arg1));
            return;
        case 2:
            if (TLobby__sub_803FC820((void *) (arg0), (void *)&hdr, (int) (arg1)) == 0) {
                if (lbl_805D7A90 & 2) {
                    temp_r30 = (u8 *)(*(u8 **)((s8 *)arg0 + 0xC));
                    TLobby__sub_80405304((void *) ((u8 *)(arg0) + 0x10));
                    temp_r0 = *(u8 *)((s8 *)arg0 + 2) & 0xFFFFFFEF;
                    *(u8 *)((s8 *)arg0 + 2) = temp_r0;
                    if (!(temp_r0 & 0x10)) {
                        *(s8 *)((s8 *)arg0 + 0) = 5;
                    }
                    *(u8 *)((s8 *)temp_r30 + 2) = (u8) (*(u8 *)((s8 *)temp_r30 + 2) & 0xFFFFFFEF);
                    *(u8 *)((s8 *)temp_r30 + 2) = (u8) (*(u8 *)((s8 *)temp_r30 + 2) & 0xFFFFFFDF);
                    TLobby__sub_80400ACC((O_80400ACC *) (temp_r30));
                    return;
                }
                temp_r30_2 = (u8 *)(*(u8 **)((s8 *)arg0 + 0xC));
                TLobby__sub_80405304((void *) ((u8 *)(arg0) + 0x10));
                temp_r0_2 = *(u8 *)((s8 *)arg0 + 2) & 0xFFFFFFDF;
                *(u8 *)((s8 *)arg0 + 2) = temp_r0_2;
                if (!(temp_r0_2 & 0x10)) {
                    *(s8 *)((s8 *)arg0 + 0) = 5;
                }
                *(u8 *)((s8 *)temp_r30_2 + 2) = (u8) (*(u8 *)((s8 *)temp_r30_2 + 2) & 0xFFFFFFDF);
                TLobby__sub_80400ACC((O_80400ACC *) (temp_r30_2));
                return;
            }
            break;
        case 3:
            TLobby__sub_80405304((void *) ((u8 *)(arg0) + 0x10));
            temp_r30_3 = (u8 *)(*(u8 **)((s8 *)arg0 + 0xC));
            TLobby__sub_80405304((void *) ((u8 *)(arg0) + 0x10));
            temp_r0_3 = *(u8 *)((s8 *)arg0 + 2) & 0xFFFFFFEF;
            *(u8 *)((s8 *)arg0 + 2) = temp_r0_3;
            if (!(temp_r0_3 & 0x10)) {
                *(s8 *)((s8 *)arg0 + 0) = 5;
            }
            *(u8 *)((s8 *)temp_r30_3 + 2) = (u8) (*(u8 *)((s8 *)temp_r30_3 + 2) & 0xFFFFFFEF);
            *(u8 *)((s8 *)temp_r30_3 + 2) = (u8) (*(u8 *)((s8 *)temp_r30_3 + 2) & 0xFFFFFFDF);
            TLobby__sub_80400ACC((O_80400ACC *) (temp_r30_3));
            return;
        case 4:
            TLobby__sub_80405304((void *) ((u8 *)(arg0) + 0x10));
            temp_r30_4 = (u8 *)(*(u8 **)((s8 *)arg0 + 0xC));
            update_connection_state((int) ((u8 *)(temp_r30_4) + 0xA0));
            update_connection_state((int) ((u8 *)(temp_r30_4) + 4));
            *(s16 *)((s8 *)arg0 + 8) = 1;
            lbl_805D7A80 = 1;
            break;
        }
    }
}

s32 TLobby__sub_803FC684(u8 *arg0, u8 *arg1, u8 *arg2) {
    char **p = *(char ***)(arg2 + 0x30);

    if (NetStringLength((const char *)((void *)arg0)) >= 0x80) {
        arg0[0x7F] = 0;
    }
    if (NetStringLength((const char *)((void *)arg1)) >= 0x80) {
        arg1[0x7F] = 0;
    }
    NetCopyString((char *)((lbl_805C0180.a)), (const char *)(arg0));
    NetCopyString((char *)((lbl_805C0180.b)), (const char *)(arg1));
    p[0] = lbl_805C0180.a;
    p[1] = lbl_805C0180.b;
    return 0;
}

void TLobby__sub_803FC728(Conn_804004DC *c) {
    B_803FADA0 *buf;
    PppChap *chap = (PppChap *)c->opts;
    u8 *sub;

    if (chap->active != 0) {
        if (c->retries != 0) {
            chap->msg = (void *)(lbl_8047FDE0);
            TLobby__sub_803FE658((u8 *)c);
            return;
        }
        chap->msg = (void *)(lbl_8047FDF0);
        sub = c->sub;
        update_connection_state((int)(sub + 0xA0));
        update_connection_state((int)(sub + 4));
        c->abort = 1;
        return;
    }
    if (c->retries != 0) {
        buf = (void *)(TLobby__sub_80401B20(lbl_805C02D0.p1C, chap->len));
        TLobby__sub_803FE6CC(c, 2, chap->id, buf);
        TLobby__sub_80405328(c->timer);
        c->retries--;
        return;
    }
    sub = c->sub;
    update_connection_state((int)(sub + 0xA0));
    update_connection_state((int)(sub + 4));
    c->abort = 1;
}

struct Ent_80401B20;
#pragma push
#pragma opt_common_subs on
#pragma dont_inline off
#pragma inline_depth(4)
inline s32 chap_rbs_803FC820(B_803FADA0 **src) {
    if (TLobby__sub_80401BCC(src, &lbl_805D7A98, 1) != 1) {
        return -1;
    }
    return (s16)lbl_805D7A98;
}
inline s32 chap_rb_803FC820(B_803FADA0 **src) {
    s32 fast = 0;
    s32 valid = 0;
    if (src != NULL && *src != NULL) {
        valid = 1;
    }
    if (valid && (*src)->len > 1) {
        fast = 1;
    }
    if (fast) {
        (*src)->len--;
        return *(*src)->buf++;
    }
    return chap_rbs_803FC820(src);
}
extern s16 TLobby__sub_803FC820(Conn_804004DC *c, u8 *hdr, int v) {
    s16 total;
    s32 TLobby__sub_803FE6CC(void *, u8, u8, void *); /* declared here with other parameter types; the definition is s32 (void *, int, int, void *) */
    PppChap *chap;
    u8 *name;
    u8 *value;
    s16 n;
    const char *secret;
    s32 i;
    u8 *p;
    s16 m;
    s32 j;
    u8 *q;
    s16 len;
    s32 code;
    s16 ret;
    Ent_80401B20 *reply;
    u8 ctx[0x58];

    name = NULL;
    value = NULL;
    secret = NULL;
    chap = c->opts;

    if (hdr[1] != c->id) {
        return -1;
    }
    total = *(s16 *)(hdr + 2);
    n = chap_rbs_803FC820((B_803FADA0 **)&v);
    if (n != -1) {
        p = value = lbl_805C02D0.p10;
        for (i = 0; i < n; i++) {
            *p++ = chap_rb_803FC820((B_803FADA0 **)&v);
        }
    }
    m = total - n - 1;
    if (m < 0) {
        m = 0;
    }
    if (m >= 0x80) {
        m = 0x7F;
    }
    if (m != 0) {
        q = name = lbl_805C02D0.p4;
        for (j = 0; j < m; j++) {
            *q++ = chap_rb_803FC820((B_803FADA0 **)&v);
        }
        *q = 0;
    }
    if (lbl_805D7A90 & 2) {
        secret = (const char *)TLobby__sub_803F7684(name);
        if (secret == NULL) {
            NetCopyString(lbl_805C02D0.p20, (const char *)&lbl_805E1168);
            reply = TLobby__sub_80401B20(lbl_805C02D0.p20, NetStringLength(lbl_805C02D0.p20));
            TLobby__sub_803FE6CC(c, 4, hdr[1], reply);
            return -1;
        }
    }
    *lbl_805C02D0.p18 = hdr[1];
    if (lbl_805D7A90 & 2) {
        NetCopyString((char *)lbl_805C02D0.p18 + 1, secret);
    } else {
        NetCopyString((char *)lbl_805C02D0.p18 + 1, chap->secret);
    }
    if (lbl_805D7A90 & 2) {
        len = NetStringLength(secret);
    } else {
        len = NetStringLength(chap->secret);
    }
    init_md5_state((void *)ctx);
    TLobby__sub_80401EB8(ctx, lbl_805C02D0.p18, len + 1);
    TLobby__sub_80401EB8(ctx, lbl_805C02D0.p8 + 1, lbl_805D7A9A);
    TLobby__sub_80401D2C((u8 *)lbl_805C02D0.p20, (u32 *)ctx);
    if (NetMemcmp(lbl_805C02D0.p20, value, 0x10) == 0) {
        NetCopyString(lbl_805C02D0.p20, (const char *)lbl_8047FE08);
        code = 3;
        ret = 0;
    } else if (lbl_805D7A90 & 2) {
        NetCopyString(lbl_805C02D0.p20, (const char *)&lbl_805E1168);
        code = 4;
        ret = -1;
    } else {
        NetCopyString(lbl_805C02D0.p20, (const char *)lbl_8047FE08);
        code = 3;
        ret = 0;
    }
    reply = TLobby__sub_80401B20(lbl_805C02D0.p20, NetStringLength(lbl_805C02D0.p20));
    TLobby__sub_803FE6CC(c, code, hdr[1], reply);
    return ret;
}
#pragma pop

inline s32 rd_803FCC10(UnkSumBuf **pp) {
    s32 ok1;
    s32 ok2;
    ok2 = 0;
    ok1 = 0;
    if (pp != 0) {
        if (*pp != 0) ok1 = 1;
    }
    if (ok1) {
        if ((*pp)->len > 1) ok2 = 1;
    }
    if (ok2) {
        (*pp)->len -= 1;
        return *(*pp)->data++;
    }
    return (TLobby__sub_80401BCC(pp, &lbl_805D7A98, 1) != 1) ? -1 : (s16)lbl_805D7A98;
}
#pragma push
#pragma dont_inline off
#pragma inline_depth(4)
extern void TLobby__sub_803FCC10(void *self_, void *src_, int v)
{
  u8 *g;
  u8 *src;
  int new_var4[2];
  u8 *r28;
  u8 ctx[0x58];
  u8 *new_var;
  u8 *dst1;
  u8 *out;
  u8 **pp;
  u8 **pq;
  void *ent;
  s16 len;
  s16 cnt;
  s32 i;
  s32 n;
  void *new_var3;
  u32 l1;
  u16 rem;
  u16 r22;
  g = (u8 *) (&lbl_805C0180);
  new_var3 = self_;
  src = (u8 *) src_;
  dst1 = 0;
  r28 = *((u8 **) (((u8 *) new_var3) + 0x30));
  len = *((s16 *) (src + 2));
  cnt = (TLobby__sub_80401BCC((UnkSumBuf **) (&v), &lbl_805D7A98, 1) != 1) ? (-1) : ((s16) lbl_805D7A98);
  if (cnt != (-1))
  {
    dst1 = *((u8 **) (g + 0x15c));
    out = dst1;
    for (i = 0; i < cnt; i++)
    {
      *(out++) = rd_803FCC10((UnkSumBuf **) (&v));
    }

  }
  n = (len - cnt) - 1;
  rem = n;
  if (rem >= 0x80)
  {
    rem = 0x7f;
  }
  new_var4[0] = rem;
  if (new_var4[0] != 0)
  {
    u8 *p = *((u8 **) (g + 0x150));
    for (i = 0; i < new_var4[0]; i++)
    {
      do
      {
        *(p++) = rd_803FCC10((UnkSumBuf **) (&v));
      }
      while (0);
    }

    *p = 0;
  }
  pp = (u8 **) (g + 0x164);
  *(*pp) = src[1];
  NetCopyString((char *) ((*pp) + 1), (const char *) (*((void **) (r28 + 4))));
  l1 = (u16) NetStringLength((const char *) (*((void **) (r28 + 4))));
  r22 = (u16) NetStringLength((const char *) (*((void **) r28)));
  n = l1 + 1;
  NetMemcpy((*pp) + n, dst1, cnt);
  pq = (u8 **) (g + 0x16c);
  NetMemset(*pq, 0, *((s16 *) (g + 0x182)));
  *(*pq) = 0x10;
  init_md5_state((void *) ctx);
  TLobby__sub_80401EB8(ctx, *pp, (u32) (n + cnt));
  TLobby__sub_80401D2C((*pq) + 1, (u32 *) ctx);
  NetMemcpy((*pq) + 0x11, *((void **) r28), r22);
  r28[0xe] = src[1];
  *((u16 *) (r28 + 0x10)) = r22 + 0x11;
  ent = TLobby__sub_80401B20(*pq, *((u16 *) (r28 + 0x10)));
  TLobby__sub_803FE6CC((u8 *) new_var3, 2, r28[0xe], ent);
  TLobby__sub_80405328(((u8 *) new_var3) + (new_var4[1] = 0x10));
  ((u8 *) new_var3)[3] -= 1;
  if (((u8 *) new_var3)[6] != 0)
  {
    ((u8 *) new_var3)[6] -= 1;
  }
  else
  {
    u8 *cc = new_var = *((u8 **) (((u8 *) new_var3) + 0xc));
    update_connection_state((int) (cc + 0xa0));
    update_connection_state((int) (cc + 4));
  }
}
#pragma pop
