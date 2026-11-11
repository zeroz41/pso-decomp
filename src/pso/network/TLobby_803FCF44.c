/* The AVE-TCP net buffer setup (build_avetcp_net_buffer, which logs under the name "avetcp" at 805E1158) and
 * set_flags_and_state (a C library, built with GC/1.2.5n). A file of its own: CHAP (TLobby_803FC178.c) defines
 * the .bss object at 805C02D0 before the functions that use it, while this code loads that address afresh at
 * each use. No name evidence for the module, so the file keeps its address name. */
#include "types.h"
#include "pso/network/TLobby_803FC178.h"
#include "pso/network/TLobby_803FCF44.h"
#include "pso/network/TLobby_804050DC.h"
#include "pso/network/TLobby_8041112C.h"
/* This file's functions. */
s32 set_flags_and_state(void *self);
#include "pso/network/NetworkRuntime.h"
#include "pso/network/TLobby_804048E8.h"
#include "pso/network/NetworkTransport.h"

#include <stddef.h>
#include "pso/network/NetStackTypes.h"

#include "pso/network/PppBuffer.h"

inline s32 chap_rbs_803FC820(PppFrame **src) {
    if (TLobby__sub_80401BCC(src, &lbl_805D7A98, 1) != 1) {
        return -1;
    }
    return (s16)lbl_805D7A98;
}
inline s32 chap_rb_803FC820(PppFrame **src) {
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
        return *(*src)->data++;
    }
    return chap_rbs_803FC820(src);
}

inline s32 rd_803FCC10(PppFrame **pp) {
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
void *build_avetcp_net_buffer(Conn_804004DC *c)
{
  PppChap *chap = c->opts;
  s32 tick;
  char name[] = "avetcp";
  PppFrame *buf;
  u8 *p;
  s16 i;
  u16 len;
  s16 n;
  s16 lim;

  if (chap->name == NULL || chap->secret == NULL)
  {
    return NULL;
  }
  buf = init_net_buffer_entry(0);
  if (buf == NULL)
  {
    return NULL;
  }
  p = buf->data;
  NetStoreTick(&tick);
  lbl_805D7A9A = (tick & 0x1F) + 0x10;
  *p++ = lbl_805D7A9A;
  NetStoreTick(&tick);
  for (i = 0; i < lbl_805D7A9A; i++)
  {
    *p++ = tick;
  }
  NetCopyString((char *)p, name);
  buf->len += lbl_805D7A9A + (u16)NetStringLength(name) + 1;
  len = buf->len;
  lim = lbl_805C02D0.size8;
  n = len;
  if ((s16)len > lim)
  {
    n = lim;
  }
  NetMemcpy(lbl_805C02D0.p8, buf->data, n);
  return buf;
}

s32 set_flags_and_state(void *self) {
    u8 *arg0 = (u8 *)self;
    *(u8 *)((s8 *)arg0 + 2) = (u8) (*(u8 *)((s8 *)arg0 + 2) & 0xFFFFFFBF);
    *(u8 *)((s8 *)arg0 + 2) = (u8) (*(u8 *)((s8 *)arg0 + 2) | 0x80);
    if ((u8) *(u8 *)((s8 *)arg0 + 0) < 1U) {
        *(u8 *)((s8 *)arg0 + 0) = 1U;
    }
    return 0;
}

