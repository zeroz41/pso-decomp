/* The CHAP challenge this side sends (a random-length run of the tick count followed by the name "avetcp") and
 * PP_doppp_active, which marks the PPP link for an active open (a C library, built with GC/1.2.5n). */
#include "types.h"
#include "pso/network/PppChap.h"
#include "pso/network/Ppp.h"
#include "pso/network/NetStack.h"
#include "pso/network/NetIpv6Route.h"
#include "pso/network/NetworkRuntime.h"
#include "pso/network/PppVj.h"
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
  chap_challenge_length = (tick & 0x1F) + 0x10;
  *p++ = chap_challenge_length;
  NetStoreTick(&tick);
  for (i = 0; i < chap_challenge_length; i++)
  {
    *p++ = tick;
  }
  NetCopyString((char *)p, name);
  buf->len += chap_challenge_length + (u16)NetStringLength(name) + 1;
  len = buf->len;
  lim = chap_state.tx_challenge_size;
  n = len;
  if ((s16)len > lim)
  {
    n = lim;
  }
  NetMemcpy(chap_state.tx_challenge, buf->data, n);
  return buf;
}

s32 PP_doppp_active(PppFsm *fsm) {
    fsm->flags &= ~0x40;
    fsm->flags |= 0x80;
    if (fsm->state < 1) {
        fsm->state = 1;
    }
    return 0;
}

/* CHAP's protocol name and the message it reports when authentication fails, which PppChap.c's CHAP code
 * uses. They follow this file's "avetcp" in .sdata2, so this file defines them: literals of the CHAP file, which
 * links first, would come before it. Names from their contents. */
const char chap_protocol_name[] = "Chap";
const char chap_failure_message[] = "Fail!!";

