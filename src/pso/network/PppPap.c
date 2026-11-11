/* PPP PAP, the protocol that names itself "Pap" (805E1180), and its state objects (.bss 805C04D8 and 805C0620)
 * (a C library, built with GC/1.2.5n). */
#include "types.h"
#include "pso/network/TLobby_803FC178.h"
#include "pso/network/TLobby_803FCF44.h"
#include "pso/network/TLobby_804050DC.h"
#include "pso/network/TLobby_8041112C.h"
/* This file's functions. */
u16 get_field_4(void *self);
void handle_request_timeout(void *self);
void init_net_block_620(void);
s32 init_net_block_620_secondary(void);
s32 mark_ready(void *self);
void reset_connection_state(void *self);
void set_active(void *self);
#include "pso/network/NetworkRuntime.h"
#include "pso/network/TLobby_804048E8.h"
extern s32 is_timed_out(void);
#include "pso/network/NetworkTransport.h"

#include <stddef.h>
#include "pso/network/NetStackTypes.h"

s32 TLobby__sub_803F778C(void *);
void TLobby__sub_803F97E8(int);
#include "pso/network/PppBuffer.h"

extern s16 get_remaining(s32 x);



void init_net_block_620(void) {
    TLobby__sub_803F778C(&lbl_805C0620);
}

s32 init_net_block_620_secondary(void) {
    init_net_block_620_params(&lbl_805C0620);
    return 0;
}

extern s16 TLobby__sub_80402BB4(void *arg0, u32 timeout) {
    Conn_804004DC *c = (Conn_804004DC *)arg0;
    NetThreadState *g;
    u8 *sub;

    sub = c->sub;
    g = &lbl_805C18A0;
    c->abort = 0;
    while (c->state != 5) {
        if (is_timed_out() != 0 || c->abort != 0 || *sub == 4) {
            update_connection_state((int)c);
            update_connection_state((int)(c->sub + 4));
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
            update_connection_state((int)c);
            update_connection_state((int)(c->sub + 4));
            return -0x12;
        }
        unlock_mutex(g->mutex);
        TLobby__sub_803F97E8(100);
        process_expired_timers();
        lock_mutex(g->mutex);
    }
    c->abort = 0;
    return 0;
}

extern s32 TLobby__sub_80403634(u8 *self_m);
extern u8 lbl_805E1180;
extern void TLobby__sub_80402CE0(u8 *arg0) {
    struct P_80402CE0 {
        void *name;
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
    };
    struct S_80402CE0;
    struct T_80402CE0 {
        u8 pad0[0x10];
        void *callback;
        struct S_80402CE0 *arg;
        u8 pad18[4];
    };
    struct S_80402CE0 {
        u8 f0; u8 f1; u8 f2; u8 f3; u8 f4; u8 f5; u8 f6; u8 f7;
        u8 pad8[4];
        u8 *sub;
        struct T_80402CE0 timer;
        struct P_80402CE0 *proto;
        u8 *opts;
    };
    u8 *g;
    struct P_80402CE0 *p;
    struct S_80402CE0 *fsm;
    struct T_80402CE0 *timer;

    g = (u8 *)&lbl_805C04D8;
    p = (struct P_80402CE0 *)g;
    fsm = (struct S_80402CE0 *)(arg0 + 0x38);
    if (fsm->opts == NULL) {
        timer = &fsm->timer;
        p->name = (void *)&lbl_805E1180;
        p->proto = 0xC023;
        p->h6 = 0xE;
        p->b8 = 1;
        p->bB = 0;
        p->b9 = g[0x15A];
        p->bA = g[0x15B];
        p->timeout = *(u16 *)(g + 0x15C) * 1000;
        p->f10 = (void *)TLobby__sub_803FE84C;
        p->f14 = (void *)TLobby__sub_803FE84C;
        p->f18 = (void *)TLobby__sub_803FE84C;
        p->f1C = (void *)TLobby__sub_803FE84C;
        p->f20 = (void *)TLobby__sub_803FE84C;
        p->f24 = (void *)TLobby__sub_803FE84C;
        p->f28 = (void *)TLobby__sub_80403634;
        p->f2C = (void *)TLobby__sub_803FE844;
        p->f30 = (void *)TLobby__sub_803FE844;
        p->f34 = (void *)TLobby__sub_803FE844;
        p->f38 = (void *)TLobby__sub_803FE844;
        fsm->sub = arg0;
        fsm->proto = p;
        fsm->opts = g + 0x3C;
        fsm->f4 = fsm->proto->b9;
        fsm->f7 = fsm->proto->bA;
        fsm->f5 = fsm->proto->bB;
        fsm->f0 = 0;
        fsm->f3 = fsm->f4;
        fsm->f6 = fsm->f7;
        timer->callback = (void *)handle_request_timeout;
        timer->arg = fsm;
        TLobby__sub_80405298((N_80405298 *)timer, fsm->proto->timeout);
    }
}

s32 mark_ready(void *self) {
    u8 *arg0 = (u8 *)self;
    *(s8 *)((s8 *)arg0 + 0x38) = 2;
    *(u8 *)((s8 *)arg0 + 0x3A) = (u8) (*(u8 *)((s8 *)arg0 + 0x3A) | 0x20);
    *(u8 *)((s8 *)arg0 + 2) = (u8) (*(u8 *)((s8 *)arg0 + 2) | 0x20);
    return 0;
}

void set_active(void *self) {
    u8 *arg0 = (u8 *)self;
    *(s8 *)((s8 *)arg0 + 0x38) = 1;
    *(u8 *)((s8 *)arg0 + 0x3A) = (u8) (*(u8 *)((s8 *)arg0 + 0x3A) | 0x10);
    *(u8 *)((s8 *)arg0 + 2) = (u8) (*(u8 *)((s8 *)arg0 + 2) | 0x10);
    *(u8 *)((s8 *)arg0 + 0x3B) = (u8) *(u8 *)((s8 *)arg0 + 0x3C);
}

extern u8 lbl_805D7AB8[8];
static inline s16 read_text_field(u8 *self, Hdr_803FC4B4 *hdr, s32 src) {
    s32 ret;
    u8 **pdst;
    s32 rv;
    s16 fld;
    s16 n;
    u8 *obj;
    obj = *(u8 **)(self + 0x30);
    if (hdr->flag != self[1]) {
        return -1;
    }
    n = (TLobby__sub_80401BCC(&src, lbl_805D7AB8, 1) != 1) ? -1 : (s16)lbl_805D7AB8[0];
    if (n != -1) {
        if (n != 0) {
            fld = (s16)get_field_4((void *)src);
            pdst = &lbl_805C0620.message;
            rv = TLobby__sub_80401ABC((u8 *)src, *pdst, n);
            (*pdst)[(s16)rv] = 0;
            *(u8 **)(obj + 8) = *pdst;
            ret = 1;
            if ((s16)rv < n || n < fld) {
            } else {
                ret = 0;
            }
            return ret;
        }
        return 0;
    }
    return -1;
}

static inline void finish_pending_step(u8 *self, u8 bit) {
    u8 *link;
    link = *(u8 **)(self + 0xC);
    self[2] &= ~bit;
    if (!(self[2] & 0x30)) {
        self[0] = 5;
    }
    TLobby__sub_80405304(self + 0x10);
    link[2] &= ~bit;
    TLobby__sub_80400ACC((O_80400ACC *)link);
}

#pragma push
#pragma dont_inline off
#pragma inline_depth(4)
void PADRead(u8 *self, s32 arg1)
{
  Hdr_803FC4B4 hdr;
  u8 *f30;
  extern s16 TLobby__sub_803FE8BC(u8 *, void *); /* declared s16 here; the definition returns s32 */
  extern s16 TLobby__sub_80403308(u8 *, u8 *, PppFrame *);
  f30 = *((u8 **) (self + 0x30));
  if (TLobby__sub_803FE8BC((u8 *) (&hdr), &arg1))
  {
    return;
  }
  hdr.len -= 4;
  TLobby__sub_80401CAC((PppFrame **) (&arg1), hdr.len);
  switch (hdr.type)
  {
    case 1:
      if (TLobby__sub_80403308(self, (u8 *) (&hdr), (PppFrame *) arg1))
    {
      return;
    }
      finish_pending_step(self, 0x10);
      return;

    case 2:
      if (read_text_field(self, &hdr, arg1) != 0)
    {
      return;
    }
      finish_pending_step(self, 0x20);
      return;

    case 3:
      if (read_text_field(self, &hdr, arg1) != 0)
    {
      return;
    }
      TLobby__sub_80405304(self + 0x10);
      *((s32 *) f30) = 0;
      *((s32 *) (f30 + 4)) = 0;
      *((s16 *) (self + 8)) = 1;
      self[0] = 0;
      lbl_805D7A80 = 1;
      return;

  }

}
#pragma pop

s32 TLobby__sub_80403168(u8 *arg0, u8 *arg1, u8 *arg2) {
    Names_80403168 *g;
    u8 **p;
    u32 n;
    u32 m;
    p = *(u8 ***)(arg2 + 0x30);
    g = &lbl_805C04D8;
    n = NetStringLength((const char *)((void *)(arg0)));
    if (n >= 0x80) {
        n = 0x7F;
    }
    NetMemcpy(g->a, arg0, n);
    g->a[n] = 0;
    m = NetStringLength((const char *)((void *)(arg1)));
    if (m >= 0x80) {
        m = 0x7F;
    }
    NetMemcpy(g->b, arg1, m);
    g->b[m] = 0;
    p[0] = g->a;
    p[1] = g->b;
    return 0;
}

void reset_connection_state(void *self) {
    u8 *arg0 = (u8 *)self;
    typedef struct Fields_arg0 { u8 field_0; u8 pad_1[1]; s8 field_2; u8 pad_3[45]; u32 field_30; } Fields_arg0;
    u8 temp_r0;
    if ((u32) ((Fields_arg0*)arg0)->field_30 != 0U) {
        ((Fields_arg0*)arg0)->field_2 = 0;
        temp_r0 = ((Fields_arg0*)arg0)->field_0;
        if ((s32) temp_r0 != 2) {
            if ((s32) temp_r0 < 2) {
                if ((s32) temp_r0 != 0) {
                    if ((s32) temp_r0 < 0) {
                        return;
                    }
                    goto block_10;
                }
            } else if ((s32) temp_r0 < 7) {
                if ((s32) temp_r0 < 5) {
                    return;
                }
                goto block_10;
            }
        } else {
            TLobby__sub_80405304((void *)((void *) ((u8 *)(arg0) + 0x10)));
block_10:
            ((Fields_arg0*)arg0)->field_0 = 0U;
        }
    }
}

void handle_request_timeout(void *self) {
    u8 *arg0 = (u8 *)self;
    u8 *temp_r4;
    temp_r4 = (u8 *)(*(u8 **)((s8 *)arg0 + 0x30));
    if ((u8) *(u8 *)((s8 *)arg0 + 3) != 0) {
        *(s32 **)((s8 *)temp_r4 + 8) = lbl_8047FEB8;
        TLobby__sub_803FE658((u8 *)((void *) (arg0)));
        return;
    }
    *(s32 **)((s8 *)temp_r4 + 8) = lbl_8047FEC8;
    update_connection_state((int) (*(s32 *)((s8 *)arg0 + 0xC) + 4));
    *(s16 *)((s8 *)arg0 + 8) = 1;
}

extern u8 lbl_8047FEE0[];
extern u8 lbl_8047FEEC[];
#pragma push
#pragma dont_inline off
#pragma inline_depth(4)
inline s32 valid_80403308(PppFrame **s) {
    s32 r = 0;
    if (s != NULL && *s != NULL) {
        r = 1;
    }
    return r;
}
inline s32 avail_80403308(PppFrame **s) {
    s32 r = 0;
    if (valid_80403308(s) && (*s)->len > 1) {
        r = 1;
    }
    return r;
}
inline s32 get_80403308(PppFrame **s) {
    if (avail_80403308(s)) {
        (*s)->len--;
        return *(*s)->data++;
    }
    if (TLobby__sub_80401BCC(s, lbl_805D7AB8, 1) != 1) {
        return -1;
    }
    return (s16)lbl_805D7AB8[0];
}
extern s16 TLobby__sub_80403308(u8 *self, u8 *src, PppFrame *val) {
    s32 TLobby__sub_803FE6CC(void *, u8, u8, void *); /* declared here with other parameter types; the definition is s32 (void *, int, int, void *) */
    u8 *p1 = 0;
    u8 *p2 = 0;
    s16 ch;
    s16 res;
    s32 t;
    s16 st;
    u8 *ptr;
    s16 n;
    u8 *ent;

    ch = (TLobby__sub_80401BCC(&val, lbl_805D7AB8, 1) != 1) ? -1 : (s16)lbl_805D7AB8[0];
    if (ch != -1) {
        s16 cnt;
        u8 *out;
        p1 = lbl_805C0620.peer_id;
        out = p1;
        for (cnt = ch; cnt-- > 0;) {
            *out++ = get_80403308(&val);
        }
        *out = 0;
    }

    ch = (TLobby__sub_80401BCC(&val, lbl_805D7AB8, 1) != 1) ? -1 : (s16)lbl_805D7AB8[0];
    if (ch != -1) {
        s16 cnt;
        u8 *out;
        p2 = lbl_805C0620.password;
        out = p2;
        for (cnt = ch; cnt-- > 0;) {
            *out++ = get_80403308(&val);
        }
        *out = 0;
    }

    if (lbl_805D7A90 & 2) {
        t = TLobby__sub_803F7684(p1);
        if (t == 0) {
            res = -1;
        } else if (NetCompareStrings((const char *)(p2), (const char *)t) != 0) {
            res = -1;
        } else {
            goto zero;
        }
    } else {
zero:
        res = 0;
    }

    if (res == 0) {
        *(u8 **)(*(u8 **)(self + 0xc) + 0x10c) = p1;
        ptr = lbl_8047FEE0;
        st = 2;
    } else {
        ptr = lbl_8047FEEC;
        st = 3;
    }
    n = (s16)NetStringLength((const char *)(ptr));
    ent = (u8 *)TLobby__sub_80401B20(ptr, n);
    *(*(u8 **)ent) = (u8)(n - 1);
    TLobby__sub_803FE6CC(self, st, src[1], ent);

    if (st == 3) {
        if (self[6] != 0) {
            self[6]--;
        } else {
            update_connection_state((int)(*(u8 **)(self + 0xc) + 4));
        }
    }
    return st != 2;
}
#pragma pop

#pragma push
#pragma opt_common_subs on
s32 TLobby__sub_80403634(u8 *self_m)
{
  u8 *blk;
  u32 *p;
  u8 *buf;
  s32 n1;
  s32 n2;
  s32 len;
  u16 old;
  p = *((u32 **) (self_m + 0x30));
  if ((p[0] == 0) || (p[1] == 0))
  {
    return 0;
  }
  blk = ((void*)init_net_buffer_entry((u16)(0)));
  if (blk == ((void *) 0))
  {
    return 0;
  }
  buf = *((u8 **) blk);
  n1 = NetStringLength((const char *)((void*)((void *) p[0])));
  *(buf++) = n1;
  NetMemcpy((void *)(buf), (void *)((void *) p[0]), (int)(n1));
  buf += n1;
  n2 = NetStringLength((const char *)((void*)((void *) p[1])));
  *(buf++) = n2;
  NetMemcpy((void *)(buf), (void *)((void *) p[1]), (int)(n2));
  old = *((u16 *) (blk + 4));
  len = n1 + n2;
  if ((!len) && (!len))
  {
  }
  len += old;
  *((u16 *) (blk + 4)) = len + 2;
  return (s32) blk;
}
#pragma pop

PppPapState lbl_805C0620;
Names_80403168 lbl_805C04D8;
