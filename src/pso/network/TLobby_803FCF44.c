/* The AVE-TCP net buffer setup (build_avetcp_net_buffer, which logs under the name "avetcp") and
 * PP_doppp_active (a C library, built with GC/1.2.5n). A file of its own: CHAP (TLobby_803FC178.c) defines
 * the .bss object lbl_805C02D0 before the functions that use it, while this code loads that address afresh at
 * each use. No name evidence for the module, so the file keeps its address name. */
#include "types.h"
#include "pso/network/TLobby_803FC178.h"
#include "pso/network/TLobby_803FCF44.h"
#include "pso/network/TLobby_804050DC.h"
#include "pso/network/TLobby_8041112C.h"
#include "pso/network/NetworkRuntime.h"
#include "pso/network/TLobby_804048E8.h"
#include "pso/network/NetworkTransport.h"

#include <stddef.h>
#include "pso/network/NetStackTypes.h"

#include "pso/network/PppBuffer.h"

PppFrame *build_avetcp_net_buffer(PppFsm *c)
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

s32 PP_doppp_active(void *self) {
    u8 *arg0 = (u8 *)self;
    *(u8 *)((s8 *)arg0 + 2) = (u8) (*(u8 *)((s8 *)arg0 + 2) & 0xFFFFFFBF);
    *(u8 *)((s8 *)arg0 + 2) = (u8) (*(u8 *)((s8 *)arg0 + 2) | 0x80);
    if ((u8) *(u8 *)((s8 *)arg0 + 0) < 1U) {
        *(u8 *)((s8 *)arg0 + 0) = 1U;
    }
    return 0;
}

/* CHAP's protocol name and the message it reports when authentication fails, which TLobby_803FC178.c's CHAP code
 * uses. They follow this file's "avetcp" in .sdata2, so this file defines them: literals of the CHAP file, which
 * links first, would come before it. Names from their contents. */
const char chap_protocol_name[] = "Chap";
const char chap_failure_message[] = "Fail!!";

