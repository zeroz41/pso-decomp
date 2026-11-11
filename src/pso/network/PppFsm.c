/* The PPP option-negotiation state machine that LCP, IPCP and PAP drive, and its jump tables at 804FD5A8
 * (a C library, built with GC/1.2.5n). PppFsm is an inferred name; no string names this module. */
#include "types.h"
#include "pso/network/TLobby_803FC178.h"
#include "pso/network/TLobby_803FCF44.h"
#include "pso/network/TLobby_804050DC.h"
#include "pso/network/TLobby_8041112C.h"
typedef struct Src_803FC178 Src_803FC178;
/* This file's functions. */
u16 get_field_4(void *self);
s32 read_2_bytes(void *self, void *src);
u8 *write_network_u32_be(u8 *p, u32 v);
#include "pso/network/NetworkRuntime.h"
#include "pso/network/TLobby_804048E8.h"
#include "pso/network/NetworkTransport.h"

struct Self_803FD74C;

struct Self_803FD85C;

struct Src_803FC178 { u32 f0; u32 f4; u16 f8; u16 fA; u16 fC; u16 fE; u8 pad10; u8 f11; u8 f12; u8 f13; u8 f14; u8 f15; u8 f16; u8 f17; u8 f18[0x2C]; };

#include <stddef.h>
#include "pso/network/NetStackTypes.h"

#include "pso/network/PppBuffer.h"


void update_countdown_state(void *);

void TLobby__sub_803FD694(u8 *arg0) {
    s8 var_r0;
    u8 *temp_r31;
    u8 *temp_r4;

    temp_r31 = (u8 *)(arg0 + 0x10);
    *(u8 *)((s8 *)arg0 + 4) = (u8) *(u8 *)((s8 *)(*(u8 **)((s8 *)arg0 + 0x2C)) + 9);
    *(u8 *)((s8 *)arg0 + 7) = (u8) *(u8 *)((s8 *)(*(u8 **)((s8 *)arg0 + 0x2C)) + 0xA);
    *(u8 *)((s8 *)arg0 + 5) = (u8) *(u8 *)((s8 *)(*(u8 **)((s8 *)arg0 + 0x2C)) + 0xB);
    if (*(u8 *)((s8 *)arg0 + 2) & 0xC0) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    *(s8 *)((s8 *)arg0 + 0) = var_r0;
    *(u8 *)((s8 *)arg0 + 3) = (u8) *(u8 *)((s8 *)arg0 + 4);
    *(u8 *)((s8 *)arg0 + 6) = (u8) *(u8 *)((s8 *)arg0 + 7);
    temp_r4 = (u8 *)(*(u8 **)((s8 *)arg0 + 0x2C));
    (*(s32 (**)(void *, void *))((s8 *)temp_r4 + 0x14))(arg0, temp_r4);
    *(void **)((s8 *)temp_r31 + 0x10) = (void *)update_countdown_state;
    *(u8 **)((s8 *)temp_r31 + 0x14) = arg0;
    TLobby__sub_80405298((N_80405298 *) (temp_r31), (s32) (*(s32 *)((s8 *)(*(u8 **)((s8 *)arg0 + 0x2C)) + 0xC)));
}

#define self ((Self_803FD74C *)arg0)
void update_connection_state(int arg0) {
    if (self->f30 == 0) {
        return;
    }
    switch (self->f0) {
    case 5:
        self->tbl->f20(self);
    case 4:
        self->f3 = self->f5;
        if (self->f3 != 0) {
            self->f3--;
            TLobby__sub_80405328(self->f10);
            TLobby__sub_803FE6CC(self, 5, 0, 0);
        }
        self->f0 = 6;
        break;
    case 2:
    case 3:
        self->f3 = 0;
        self->f0 = 6;
        break;
    case 1:
        if (lbl_805D7A90 & 2) {
            if (self->f3 != 0) {
            self->f3--;
            TLobby__sub_80405328(self->f10);
            TLobby__sub_803FE6CC(self, 5, 0, 0);
        }
        }
        self->f0 = 0;
        break;
    case 6:
        break;
    }
}
#undef self

#define self ((Self_803FD85C *)arg0)
void TLobby__sub_803FD85C(void *arg0) {
    if (self->f30 != NULL) {
        switch (self->f0) {
        case 2:
        case 3:
        case 4:
            TLobby__sub_80405304(self->f10);
            self->f0 = (self->f2 & 0xC0) ? 1 : 0;
            self->f3 = self->f4;
            self->f6 = self->f7;
            self->tbl->f14(self, self->tbl);
            break;
        case 5:
            self->tbl->f20(self, self->tbl);
        case 6:
            self->f0 = (self->f2 & 0xC0) ? 1 : 0;
            self->f3 = self->f4;
            self->f6 = self->f7;
            self->tbl->f14(self, self->tbl);
            break;
        }
    }
}
#undef self

void TLobby__sub_803FD958(u8 *arg0) {
  u8 temp_r0;
  u8 temp_r3;
  u8 var_r0;
  int new_var;
  u8 *temp_r4;
  u8 *temp_r4_2;
  u8 *temp_r4_3;
  if ((((u32) (*((u32 *) (((s8 *) arg0) + 0x30)))) != 0U) && ((*((u8 *) (((s8 *) arg0) + 2))) & 0xC0))
  {
    temp_r0 = *((u8 *) (((s8 *) arg0) + 0));
    if (((s32) temp_r0) != 6)
    {
      if ((((s32) temp_r0) < 6) && (((s32) temp_r0) < 2))
      {
        if (((s32) temp_r0) < 0)
        {
          return;
          if (((!temp_r0) && (!temp_r0)) && (!temp_r0))
          {
          }
        }
        goto block_7;
      }
    }
    else
    {
      new_var = 0x18;
      block_7:
      temp_r4 = (u8 *) (*((u8 **) (((s8 *) arg0) + 0x2C)));
      (*((s32 (**)(void *, void *)) (((s8 *) temp_r4) + new_var)))(arg0, temp_r4);
      if ((*((u8 *) (((s8 *) arg0) + 2))) & 0xC0)
      {
        var_r0 = 1;
      }
      else
      {
        var_r0 = 0;
      }
      *((u8 *) (((s8 *) arg0) + 0)) = var_r0;
      *((u8 *) (((s8 *) arg0) + 3)) = (u8) (*((u8 *) (((s8 *) arg0) + 4)));
      *((u8 *) (((s8 *) arg0) + 6)) = (u8) (*((u8 *) (((s8 *) arg0) + 7)));
      temp_r4_2 = (u8 *) (*((u8 **) (((s8 *) arg0) + 0x2C)));
      (*((s32 (**)(void *, void *)) (((s8 *) temp_r4_2) + 0x14)))(arg0, temp_r4_2);
      if ((*((u8 *) (((s8 *) arg0) + 2))) & 0x80)
      {
        temp_r3 = *((u8 *) (((s8 *) arg0) + 3));
        if (temp_r3 != 0)
        {
          *((u8 *) (((s8 *) arg0) + 3)) = (u8) (temp_r3 - 1);
          TLobby__sub_80405328((u8 *)((void *) (((u8 *) arg0) + 0x10)));
          temp_r4_3 = (u8 *) (*((u8 **) (((s8 *) arg0) + 0x2C)));
          TLobby__sub_803FE6CC((void *) arg0, 1, 0, (void *) (*((s32 (**)(void *, void *)) (((s8 *) temp_r4_3) + 0x28)))(arg0, temp_r4_3));
        }
        *((u8 *) (((s8 *) arg0) + 0)) = 2U;
      }
    }
  }
}

struct Self_803FDA68;

void update_countdown_state(void *arg0) {
    Self_803FDA68 *self = (Self_803FDA68 *)arg0;
    switch (self->f0) {
    case 2:
    case 3:
    case 4:
        if (self->f3 != 0) {
            if (self->f3 > 0) {
                self->f3--;
                TLobby__sub_80405328(self->f10);
                TLobby__sub_803FE6CC(self, 1, 0, self->tbl->f28(self, self->tbl));
            }
            if (self->f0 == 3) {
                self->f0 = 2;
            }
        } else {
            self->f0 = (self->f2 & 0xC0) ? 1 : 0;
            self->f3 = self->f4;
            self->f6 = self->f7;
            self->tbl->f14(self, self->tbl);
            self->f8 = 1;
        }
        break;
    case 6:
        if (self->f3 != 0) {
            if (self->f3 > 0) {
                self->f3--;
                TLobby__sub_80405328(self->f10);
                TLobby__sub_803FE6CC(self, 5, 0, 0);
            }
        } else {
            self->tbl->f24(self, self->tbl);
            self->f0 = (self->f2 & 0xC0) ? 1 : 0;
            self->f3 = self->f4;
            self->f6 = self->f7;
            self->tbl->f14(self, self->tbl);
            self->f8 = 1;
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
void TLobby__sub_803FDBF8(u8 *self, void *arg1)
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
        switch (self[0]) {
        case 5:
            (*(void (**)(void *))(*(u8 **)(self + 0x2c) + 0x20))(self);
            self[0] = ((self[2] & 0xC0) != 0) ? 1 : 0;
            self[3] = self[4];
            self[6] = self[7];
            (*(void (**)(void *))(*(u8 **)(self + 0x2c) + 0x14))(self);
        case 1:
            (*(void (**)(void *))(*(u8 **)(self + 0x2c) + 0x18))(self);
            if (self[3] != 0) {
                self[3]--;
                TLobby__sub_80405328(self + 0x10);
                TLobby__sub_803FE6CC(self, 1, 0, (*(void *(**)(void *))(*(u8 **)(self + 0x2c) + 0x28))(self));
            }
        case 2:
        case 4:
            if ((*(s16 (**)(void *, void *, void *))(*(u8 **)(self + 0x2c) + 0x2c))(self, &hdr, arg1) == 0) {
                self[0] = 4;
            } else {
                self[0] = 2;
            }
            break;
        case 3:
            if ((*(s16 (**)(void *, void *, void *))(*(u8 **)(self + 0x2c) + 0x2c))(self, &hdr, arg1) == 0) {
                TLobby__sub_80405304(self + 0x10);
                (*(void (**)(void *))(*(u8 **)(self + 0x2c) + 0x1c))(self);
                self[0] = 5;
                lbl_805D7AA0++;
            } else {
                TLobby__sub_80405328(self + 0x10);
            }
            break;
        case 0:
            TLobby__sub_803FE6CC(self, 6, hdr.flag, 0);
            break;
        case 6:
            break;
        }
        break;
    case 2:
        switch (self[0]) {
        case 2:
            if ((*(s16 (**)(void *, void *, void *))(*(u8 **)(self + 0x2c) + 0x30))(self, &hdr, arg1) == 0) {
                self[0] = 3;
            }
            break;
        case 4:
            if ((*(s16 (**)(void *, void *, void *))(*(u8 **)(self + 0x2c) + 0x30))(self, &hdr, arg1) == 0) {
                TLobby__sub_80405304(self + 0x10);
                (*(void (**)(void *))(*(u8 **)(self + 0x2c) + 0x1c))(self);
                self[0] = 5;
                lbl_805D7AA0++;
            }
            break;
        case 5:
            (*(void (**)(void *))(*(u8 **)(self + 0x2c) + 0x20))(self);
            (*(void (**)(void *))(*(u8 **)(self + 0x2c) + 0x18))(self);
            self[0] = ((self[2] & 0xC0) != 0) ? 1 : 0;
            self[3] = self[4];
            self[6] = self[7];
            (*(void (**)(void *))(*(u8 **)(self + 0x2c) + 0x14))(self);
        case 3:
            if (self[3] != 0) {
                self[3]--;
                TLobby__sub_80405328(self + 0x10);
                TLobby__sub_803FE6CC(self, 1, 0, (*(void *(**)(void *))(*(u8 **)(self + 0x2c) + 0x28))(self));
            }
            self[0] = 2;
            break;
        case 0:
        case 1:
            TLobby__sub_803FE6CC(self, 6, hdr.flag, 0);
            break;
        case 6:
            break;
        }
        break;
    case 3:
        switch (self[0]) {
        case 2:
        case 4:
            if ((*(s16 (**)(void *, void *, void *))(*(u8 **)(self + 0x2c) + 0x34))(self, &hdr, arg1) == 0) {
                if (self[3] != 0) {
                    self[3]--;
                    TLobby__sub_80405328(self + 0x10);
                    TLobby__sub_803FE6CC(self, 1, 0, (*(void *(**)(void *))(*(u8 **)(self + 0x2c) + 0x28))(self));
                }
            }
            break;
        case 5:
            (*(void (**)(void *))(*(u8 **)(self + 0x2c) + 0x20))(self);
            (*(void (**)(void *))(*(u8 **)(self + 0x2c) + 0x18))(self);
            self[0] = ((self[2] & 0xC0) != 0) ? 1 : 0;
            self[3] = self[4];
            self[6] = self[7];
            (*(void (**)(void *))(*(u8 **)(self + 0x2c) + 0x14))(self);
        case 3:
            if (self[3] != 0) {
                self[3]--;
                TLobby__sub_80405328(self + 0x10);
                TLobby__sub_803FE6CC(self, 1, 0, (*(void *(**)(void *))(*(u8 **)(self + 0x2c) + 0x28))(self));
            }
            self[0] = 2;
            break;
        case 0:
        case 1:
            TLobby__sub_803FE6CC(self, 6, hdr.flag, 0);
            break;
        case 6:
            break;
        }
        break;
    case 4:
        switch (self[0]) {
        case 2:
        case 4:
            if ((*(s16 (**)(void *, void *, void *))(*(u8 **)(self + 0x2c) + 0x38))(self, &hdr, arg1) == 0) {
                if (self[3] != 0) {
                    self[3]--;
                    TLobby__sub_80405328(self + 0x10);
                    TLobby__sub_803FE6CC(self, 1, 0, (*(void *(**)(void *))(*(u8 **)(self + 0x2c) + 0x28))(self));
                }
            }
            break;
        case 5:
            (*(void (**)(void *))(*(u8 **)(self + 0x2c) + 0x20))(self);
            (*(void (**)(void *))(*(u8 **)(self + 0x2c) + 0x18))(self);
            self[0] = ((self[2] & 0xC0) != 0) ? 1 : 0;
            self[3] = self[4];
            self[6] = self[7];
            (*(void (**)(void *))(*(u8 **)(self + 0x2c) + 0x14))(self);
        case 3:
            if (self[3] != 0) {
                self[3]--;
                TLobby__sub_80405328(self + 0x10);
                TLobby__sub_803FE6CC(self, 1, 0, (*(void *(**)(void *))(*(u8 **)(self + 0x2c) + 0x28))(self));
            }
            self[0] = 2;
            break;
        case 0:
        case 1:
            TLobby__sub_803FE6CC(self, 6, hdr.flag, 0);
            break;
        case 6:
            break;
        }
        break;
    case 5:
        switch (self[0]) {
        case 5:
            TLobby__sub_803FE6CC(self, 6, hdr.flag, 0);
            (*(void (**)(void *))(*(u8 **)(self + 0x2c) + 0x20))(self);
            (*(void (**)(void *))(*(u8 **)(self + 0x2c) + 0x24))(self);
            self[0] = ((self[2] & 0xC0) != 0) ? 1 : 0;
            self[3] = self[4];
            self[6] = self[7];
            (*(void (**)(void *))(*(u8 **)(self + 0x2c) + 0x14))(self);
            break;
        case 3:
        case 4:
            self[0] = 2;
        case 0:
        case 1:
        case 2:
        case 6:
            TLobby__sub_803FE6CC(self, 6, hdr.flag, 0);
            break;
        }
        break;
    case 6:
        switch (self[0]) {
        case 6:
            TLobby__sub_80405304(self + 0x10);
            (*(void (**)(void *))(*(u8 **)(self + 0x2c) + 0x24))(self);
            self[0] = ((self[2] & 0xC0) != 0) ? 1 : 0;
            self[3] = self[4];
            self[6] = self[7];
            (*(void (**)(void *))(*(u8 **)(self + 0x2c) + 0x14))(self);
            break;
        case 5:
            (*(void (**)(void *))(*(u8 **)(self + 0x2c) + 0x20))(self);
            self[0] = ((self[2] & 0xC0) != 0) ? 1 : 0;
            self[3] = self[4];
            self[6] = self[7];
            (*(void (**)(void *))(*(u8 **)(self + 0x2c) + 0x14))(self);
            if (self[3] == 0) {
                rc = -1;
            } else {
                self[3]--;
                TLobby__sub_80405328(self + 0x10);
                rc = TLobby__sub_803FE6CC(self, 1, 0, (*(void *(**)(void *))(*(u8 **)(self + 0x2c) + 0x28))(self));
            }
            if (rc == 0) {
                self[0] = 2;
            }
            break;
        case 3:
        case 4:
            self[0] = 2;
            break;
        }
        break;
    case 7:
        (*(void (**)(void *))(*(u8 **)(self + 0x2c) + 0x24))(self);
        self[0] = ((self[2] & 0xC0) != 0) ? 1 : 0;
        self[3] = self[4];
        self[6] = self[7];
        (*(void (**)(void *))(*(u8 **)(self + 0x2c) + 0x14))(self);
        break;
    case 9:
        switch (self[0]) {
        case 5:
            TLobby__sub_803FE6CC(self, 10, hdr.flag, arg1);
            break;
        case 2:
        case 3:
        case 4:
            break;
        case 0:
        case 1:
            TLobby__sub_803FE6CC(self, 6, hdr.flag, 0);
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
        dp = *(u8 **)newbuf;
        *dp++ = hdr.type;
        *dp++ = hdr.flag;
        write_network_u16_be(dp, hdr.len);
        arg1 = newbuf;
        TLobby__sub_803FE6CC(self, 7, hdr.flag, arg1);
        switch (self[0]) {
        case 6:
            break;
        case 2:
        case 3:
        case 4:
        case 5:
            self[0] = 1;
            break;
        }
        break;
    }
}
#pragma pop
void TLobby__sub_803FE600(O_803FE600 *o) {
    o->b0 = (o->b2 & 0xC0) ? 1 : 0;
    o->b3 = o->b4;
    o->b6 = o->b7;
    o->p2C->fn(o, o->p2C);
}

s32 TLobby__sub_803FE658(u8 *arg0) {
    typedef struct Fields_arg0 { u8 pad_0[3]; u8 field_3; u8 pad_4[40]; u8 * field_2C; } Fields_arg0;
    u8 temp_r3;
    u8 *temp_r4;
    temp_r3 = ((Fields_arg0*)arg0)->field_3;
    if (temp_r3 == 0) {
        return -1;
    }
    ((Fields_arg0*)arg0)->field_3 = (u8) (temp_r3 - 1);
    TLobby__sub_80405328((u8 *)((void *) (arg0 + 0x10)));
    temp_r4 = (u8 *)(((Fields_arg0*)arg0)->field_2C);
    return TLobby__sub_803FE6CC((void *) (arg0), 1, 0, (void *) ((*(s32 (**)(void *, void *))((s8 *)temp_r4 + 0x28))(arg0, temp_r4)));
}

s32 TLobby__sub_80406624(s32 a, s32 b, u16 code, void *self);
#pragma push
#pragma opt_lifetimes off
extern s32 TLobby__sub_803FE6CC(void *self, int a, int b, void *c)
{
  PppBuffers *new_var;
  u8 *new_var2;
  PppFrame *buf;
  u8 *r31 = *((u8 **) (((u8 *) self) + 0xc));
  s32 cmd;
  u8 *new_var3;
  s32 r27;
  u16 n;
  if ((buf = (PppFrame *) c) == 0)
  {
    PppFrame *q = lbl_805C04A8.reply;
    q->data = ((u8 *) q) + (((*(new_var = &lbl_805C04A8)).headroom + 0x83) & (~3));
    q->len = 0;
    buf = q;
  }
  switch (cmd = (u8) a)
  {
    case 1:

    case 5:

    case 9:
      ((u8 *) self)[1] = r31[1];

    case 8:

    case 11:
      r27 = r31[1];
      r31[1] = r27 + 1;
      break;

    case 2:

    case 3:

    case 4:

    case 6:

    case 7:

    case 10:
      r27 = b;
      break;

    default:
      return -1;

  }

  switch (cmd)
  {
    case 9:
    case 10:
    case 11:
      write_network_u32_be(buf->data, *((u32 *) ((*((u8 **) (((u8 *) self) + 0x30))) + 0x28)));
      break;
  }
  n = get_field_4((void *) buf) + 4;
  {
    PppFrame *out = (PppFrame *) alloc_from_buffer((0, (void *) buf), 4);
    u8 *dp = out->data;
    *dp++ = a;
    *dp++ = r27;
    write_network_u16_be(dp, n);
    buf = out;
  }
  if (buf == 0)
  {
    return -1;
  }
  {
    u8 *r7 = r31 + ((*((u8 **) (((u8 *) self) + 0x2c)))[8] << 1);
    s16 v = *((s16 *) (r7 + 0x118));
    *((s16 *) (r7 + 0x118)) = v + 1;
  }
  return TLobby__sub_80406624(0, 0, (*((PppFrame **) (((u8 *) self) + 0x2c)))->len, buf);
}
#pragma pop
void TLobby__sub_803FE820(s32 arg0) {
    TLobby__sub_80405328((u8 *)((void *) (arg0 + 0x10)));
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

extern u16 TLobby__sub_803FE934(u8* p, PppFrame *buf, u16 count) {
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

extern u32 TLobby__sub_803FE9F8(u32 sum, PppFrame* buf, u16 count) {
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

typedef struct IpHdr_803FEA88 { u8 ver_ihl; u8 tos; u16 len; u16 id; u16 frag; u8 ttl; u8 proto; u16 cksum; u32 src; u32 dst; } IpHdr_803FEA88;
typedef char IpHdr_803FEA88_size_check[sizeof(IpHdr_803FEA88) == 0x14 ? 1 : -1];
s32 TLobby__sub_803FEA88(A_80403F4C *out, PppFrame **src) {
    PppFrame *e = *src;
    IpHdr_803FEA88 h;
    u32 hl;
    u16 frag;
    u32 optlen;
    IpHdr_803FEA88 *raw;

    raw = &h;
    if (TLobby__sub_80401BCC(src, raw, 20) != 20) {
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

u8 *NetIPv4WriteHeader(A_80403F4C *arg0, u8 *arg1, s32 arg2) {
    Src_803FC178 *src = (Src_803FC178 *)arg0;
    u16 n;
    u8 buf[0x40];
    u8 *hdr = buf;
    u8 *data;
    u32 sum;
    u16 f;
    u32 tmp;
    u8 pad[0x8];

    tmp = src->f17 + 0x14;
    n = tmp;
    if (n > 0x40) {
        n = 0x40;
    }
    arg1 = alloc_from_buffer((void *)arg1, n);
    data = *(u8 **)arg1;

    hdr[0] = (src->f13 << 4) | (n >> 2);
    hdr[1] = src->f14;
    *(u16 *)&hdr[2] = src->f8;
    *(u16 *)&hdr[4] = src->fA;
    f = (s32)src->fC >> 3;
    if (src->f11 != 0) {
        f |= 0x4000;
    }
    if (src->f12 != 0) {
        f |= 0x2000;
    }
    *(u16 *)&hdr[6] = f;
    hdr[8] = src->f15;
    hdr[9] = src->f16;
    if ((u16)arg2 != 0) {
        *(u16 *)&hdr[10] = src->fE;
    } else {
        *(u16 *)&hdr[10] = 0;
    }
    *(u32 *)&hdr[12] = src->f0;
    *(u32 *)&hdr[16] = src->f4;

    if (src->f17 != 0) {
        NetMemcpy(hdr + 0x14, src->f18, (src->f17 < 0x2C) ? src->f17 : 0x2C);
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
