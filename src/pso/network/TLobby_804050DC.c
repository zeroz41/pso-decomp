#include "pso/network/UdpRuntime.h"
#include "pso/network/SocketEvents.h"
#include "pso/network/NetworkDispatch.h"
#include "pso/network/NetworkRuntime.h"
#include "pso/network/TLobby_804048E8.h"
#include "pso/network/TLobby_804050DC.h"
#include "pso/network/TLobby_803FC178.h"
#include "pso/network/NetworkPacketPool.h"
#include "pso/network/netcfg.h"
#include "pso/network/BufferRef.h"
#include "pso/network/IPv6.h"

#include "types.h"
#include "pso/network/NetworkTransport.h"
#include "pso/network/TLobby_803FAEA0.h"
#include "pso/network/TLobby_803FCF44.h"
#include "pso/network/TLobby_8041112C.h"
#include "pso/network/text_80421620.h"
/* The object header the stack's records share (laid out like TObject's fields). */
typedef struct Timer_804051CC Timer_804051CC;
typedef struct Lobby_804062A0 Lobby_804062A0;
typedef struct Obj_80405304 Obj_80405304;
s32 reset_socket_table(void);
void run_net_thread_loop(void);
void ppp_input_packet(PppFrame *arg0);

extern PppFrame *ppp_rx_frame_ptr;
extern s32 lbl_805D7A94;
extern u8 *lbl_805D7ADC;
extern u8 *lbl_805D7AE0;
extern u32 lbl_805D7AE4;
extern u16 lbl_805D7AE8;
extern u16 lbl_804FD3A8[];
extern u8 lbl_805C18B0[];
extern s16 TLobby__sub_804290D4(s32 idx);

#include <stddef.h>

typedef struct Obj_80405304 { u8 pad[0x18]; u8 f18; } Obj_80405304;


#include "pso/network/IPv6Send.h"
#include "pso/network/NetStackTypes.h"

s32 TLobby__sub_803F79AC(void *);

void TLobby__sub_803F97E8(int);
extern u8 lbl_805C0038[];
s16 TLobby__sub_80401BCC(void *, void *, int);
void TLobby__sub_803FDBF8(u8 *self, void *arg1);
void PADRead(u8 *, PppFrame *); /* declared here with other parameter types; the definition is void (u8 *, s32) */
s16 TLobby__sub_804040E0(void *self, void *arg);
s32 TLobby__sub_804060B8(u8 *, u16, int);
extern u8 ppp_input_byte;

struct N_80405298;

void TLobby__sub_804050DC(s16 arg0) {
    lbl_805C18A0.poll_ms = arg0;
}
void init_net_block_18A0(void) {
    TLobby__sub_803F79AC(&lbl_805C18A0);
}
s32 run_net_init_step(void) {
    TLobby__sub_803F79B0(&lbl_805C18A0);
    return 0;
}

s16 reset_network_timer_list(void) {
    lobby_timer_list_head = 0;
    return 0;
}

s32 TLobby__sub_803FB6A0(void);
void TLobby__sub_803FB7A4(void);
void run_net_thread_loop(void) {
    NetThreadState *g = &lbl_805C18A0;
    for (;;) {
        if (lobby_modem_abort_flag != 0) {
            lock_mutex(g->mutex);
            TLobby__sub_803FB6A0();
            unlock_mutex(g->mutex);
            continue;
        }
        if (lbl_805D7A88 != 0) {
            lock_mutex(g->mutex);
            TLobby__sub_803FB7A4();
            unlock_mutex(g->mutex);
            continue;
        }
        TLobby__sub_803F97E8(g->poll_ms);
        if (lbl_805D7A84 != 0) {
            process_expired_timers();
        }
    }
}

struct Timer_804051CC {
    struct Timer_804051CC *next;
    u8 pad4[4];
    u32 f8;
    s32 fC;
    void (*f10)(s32);
    s32 f14;
    u8 f18;
};

s32 TLobby__sub_80405700();

void process_expired_timers(void) {
    s32 now;
    Timer_804051CC *t;

    lock_mutex(lbl_805C18A0.mutex);
    TLobby__sub_80405700();
    get_time_ms(&now);
    t = (Timer_804051CC *)lobby_timer_list_head;
    while (t != NULL) {
        if (t->f18 == 1 && (u32)(now - t->fC) > t->f8) {
            if (t != NULL && t->f18 == 1) {
                t->f18 = 0;
            }
            t->f18 = 2;
            if (t->f10 != NULL) {
                t->f18 = 0;
                t->f10(t->f14);
            }
        }
        t = t->next;
    }
    unlock_mutex(lbl_805C18A0.mutex);
}

#define HEAD_80405298 (*(N_80405298 **)&lobby_timer_list_head)
void TLobby__sub_80405298(N_80405298 *o, s32 v) {
    N_80405298 *p, *n;
    if (o == 0) {
        return;
    }
    o->f4 = v;
    if (HEAD_80405298 == 0) {
        HEAD_80405298 = o;
        o->next = 0;
    } else {
        p = HEAD_80405298;
        while ((n = p->next) != 0) {
            if (p == o) {
                o->b18 = 0;
                return;
            }
            p = n;
        }
        p->next = o;
        o->next = 0;
    }
    o->b18 = 0;
}

s32 TLobby__sub_80405304(void *arg0) {
    Obj_80405304 *o = (Obj_80405304 *)arg0;
    if (o == NULL || o->f18 != 1) {
        return;
    }
    o->f18 = 0;
}

void TLobby__sub_80405328(u8 *arg0) {
    typedef struct Fields_arg0 { u8 pad_0[4]; u32 field_4; u32 field_8; u8 pad_C[4]; u32 field_10; u8 pad_14[4]; u8 field_18; } Fields_arg0;
    u32 temp_r0_2;
    u8 temp_r0;
    if (arg0 != NULL) {
        temp_r0 = ((Fields_arg0*)arg0)->field_18;
        if ((temp_r0 == 1) && (arg0 != NULL) && (temp_r0 == 1)) {
            ((Fields_arg0*)arg0)->field_18 = 0U;
        }
        temp_r0_2 = ((Fields_arg0*)arg0)->field_4;
        if (temp_r0_2 != 0U) {
            ((Fields_arg0*)arg0)->field_8 = temp_r0_2;
            if ((u32) ((Fields_arg0*)arg0)->field_8 == 0U) {
                ((Fields_arg0*)arg0)->field_8 = 1U;
            }
            get_time_ms((s32 *)((void *) (arg0 + 0xC)));
            if ((u32) ((Fields_arg0*)arg0)->field_10 != 0U) {
                ((Fields_arg0*)arg0)->field_18 = 1U;
            }
        }
    }
}

extern s32 TLobby__sub_804053B8(void *self, u8 **pp)
{
  struct Hdr_804053B8
  {
    u16 h0;
    u16 h2;
    u32 h4;
    u32 h8;
    u8 hc;
    u8 hd;
    u16 he;
    u16 h10;
    u16 h12;
  } hdr;
  u8 *b = (u8 *) self;
  u8 *p;
  u16 size;
  u16 rem;
  u8 flags;
  u8 cb;
  u32 pad;
  s32 ret;
  u8 c;
  u32 n;
  ret = TLobby__sub_80401BCC(pp, &hdr, 0x14);
  (void) (&pad);
  *((u16 *) b) = hdr.h0;
  *((u16 *) (b + 0x2)) = hdr.h2;
  *((u32 *) (b + 0x4)) = hdr.h4;
  *((u32 *) (b + 0x8)) = hdr.h8;
  flags = hdr.hd;
  cb = hdr.hc;
  b[0x15] = flags & 0x20;
  b[0x16] = flags & 0x10;
  b[0x17] = flags & 0x8;
  b[0x18] = flags & 0x4;
  b[0x19] = flags & 0x2;
  b[0x1a] = flags & 0x1;
  cb = (cb & 0xf0) >> 2;
  *((u16 *) (b + 0xc)) = hdr.he;
  *((u16 *) (b + 0xe)) = hdr.h10;
  *((u16 *) (b + 0x10)) = hdr.h12;
  *((u16 *) (b + 0x12)) = 0;
  b[0x1b] = cb - 0x14;
  if ((((u16) ret) < 0x14) || (0x14 > cb))
  {
    return 0;
  }
  if (b[0x1b] == 0)
  {
    return cb;
  }
  if (b[0x1b] > get_field_4((void *) (*pp)))
  {
    return 0;
  }
  TLobby__sub_80401BCC(pp, b + 0x1c, b[0x1b]);
  rem = b[0x1b];
  p = b + 0x1c;
  while (rem != 0)
  {
    c = p[0];
    if (c == 0)
    {
      break;
    }
    if (c == 1)
    {
      size = 1;
    }
    else
    {
      n = p[1];
      size = n;
      if (n == 0)
        break;
    }
    switch (c)
    {
      case 2:
        if (size == 4)
      {
        *((u16 *) (b + 0x12)) = (p[2] << 8) | p[3];
      }
        break;

    }

    rem -= size;
    p += size;
  }

  return cb;
}

extern u16 TLobby__sub_803FE934(u8 *obj, u8 *buf, u16 n); /* declared here with other parameter types; the definition is u16 (u8 *, PppFrame *, u16) */
extern u8 *TLobby__sub_8040555C(u8 *self, void *lobby, u8 *obj) {
    u8 hdr[0x3c];
    u32 n = 0;
    u8 *buf;
    u8 *hp;
    u8 *dst;
    u8 flags;
    u32 len;

    if (self[0x1b] != 0 && self[0x1b] <= 0x28) {
        n = self[0x1b];
    } else if (*(u16 *)(self + 0x12) != 0) {
        n = 4;
    }
    buf = alloc_from_buffer(lobby, n + 0x14);
    if (buf == NULL) {
        return NULL;
    }
    dst = *(u8 **)buf;
    hp = hdr;
    flags = 0;
    *(u16 *)(hp + 0) = *(u16 *)(self + 0);
    *(u16 *)(hp + 2) = *(u16 *)(self + 2);
    *(u32 *)(hp + 4) = *(u32 *)(self + 4);
    *(u32 *)(hp + 8) = *(u32 *)(self + 8);
    hp[0xc] = (u8)((n + 0x14) << 2);
    if (self[0x15]) {
        flags |= 0x20;
    }
    if (self[0x16]) {
        flags |= 0x10;
    }
    if (self[0x17]) {
        flags |= 0x8;
    }
    if (self[0x18]) {
        flags |= 0x4;
    }
    if (self[0x19]) {
        flags |= 0x2;
    }
    if (self[0x1a]) {
        flags |= 0x1;
    }
    hp[0xd] = flags;
    *(u16 *)(hp + 0xe) = *(u16 *)(self + 0xc);
    if (obj == NULL) {
        *(u16 *)(hp + 0x10) = *(u16 *)(self + 0xe);
    } else {
        *(u16 *)(hp + 0x10) = 0;
    }
    *(u16 *)(hp + 0x12) = *(u16 *)(self + 0x10);
    len = 0;
    if ((u16)n > len) {
        NetMemcpy(hp + 0x14, self + 0x1c, self[0x1b]);
    }
    len = (u16)(n + 0x14);
    NetMemcpy(dst, hp, len);
    if (obj != NULL) {
        *(u16 *)(hp + 0x10) = TLobby__sub_803FE934(obj, buf, *(u16 *)(obj + 0xa));
    }
    NetMemcpy(dst, hp, len);
    return buf;
}

#pragma push
#pragma opt_common_subs on
s32 TLobby__sub_80405700()
{
  PppFrame *frame;
  u32 b;
  u16 id;
  u8 c;
  PppFrame **new_var;
  u16 st;
  u16 n;
  PppBuffers *base;
  u8 *buf = lbl_805C18B0;
  u16 is_transport_connected(void); /* declared u16 here; the definition returns s32 */
  if (lobby_modem_connect_state == 10)
  {
    if (TLobby__sub_804290D4(0x7fff) == 0)
    {
      lobby_modem_connect_state = 1;
    }
    return 0;
  }
  if (lbl_805D7A7A != 0)
  {
    base = &lbl_805C04A8;
    for (;;)
    {
      new_var = &base->frame_in;
      ppp_rx_frame_ptr = (frame = *new_var);
      ppp_rx_frame_ptr->data = ((u8 *) frame) + ((base->headroom + 0x83) & (~3));
      ppp_rx_frame_ptr->len = 0;
      if ((recv_network_frame(0x5d6, ppp_rx_frame_ptr->data, &ppp_rx_frame_ptr->len) != 0) || (ppp_rx_frame_ptr->len < 1))
      {
        break;
      }
      get_time_ms(&lbl_805D7A94);
      frame = ppp_rx_frame_ptr;
      b = (frame->data[0] & 0xFFFFFFFFFFFFFFFFu);
      id = b;
      if (!(b & 1))
      {
        id = (b << 8) | frame->data[1];
      }
      ppp_input_packet(frame);
      if (((id != 0x21) && (id != 0x2d)) && (id != 0x2f))
      {
        break;
      }
    }

    if ((lobby_modem_connect_state == 4) && (is_transport_connected() == 0))
    {
      lobby_modem_connect_state = 5;
    }
    return 0;
  }
  if (lbl_805D7ADC == 0)
  {
    lbl_805D7ADC = buf;
    ppp_rx_frame_ptr = 0;
    lbl_805D7AE8 = 0xffff;
    lbl_805D7AE4 = 0;
    lbl_805D7AE0 = buf;
  }
  base = &lbl_805C04A8;
  for (;;)
  {
    if (lbl_805D7ADC == lbl_805D7AE0)
    {
      if ((recv_network_frame(0x200, buf, &st) != 0) || (st < 1))
      {
        goto tail;
      }
      lbl_805D7ADC = buf;
      lbl_805D7AE0 = buf + st;
    }
    c = *(lbl_805D7ADC++);
    if (c == 0x7e)
    {
      if (((ppp_rx_frame_ptr != 0) && (ppp_rx_frame_ptr->len < 0x800)) && (lbl_805D7AE8 == 0xf0b8))
      {
        n = get_field_4((void *) ppp_rx_frame_ptr) - 2;
        TLobby__sub_80401CAC(&ppp_rx_frame_ptr, n);
        get_time_ms(&lbl_805D7A94);
        ppp_input_packet(ppp_rx_frame_ptr);
        ppp_rx_frame_ptr = 0;
        return 1;
      }
      ppp_rx_frame_ptr = 0;
      continue;
    }
    if ((c == 0x7d) != 0U)
    {
      lbl_805D7AE4 |= 1;
      continue;
    }
    if (ppp_rx_frame_ptr == 0)
    {
      ppp_rx_frame_ptr = (frame = base->frame_in);
      ppp_rx_frame_ptr->data = ((u8 *) frame) + ((base->headroom + 0x83) & (~3));
      ppp_rx_frame_ptr->len = 0;
      lbl_805D7AE4 = 0;
      lbl_805D7AE8 = 0xffff;
    }
    if (lbl_805D7AE4 & 1)
    {
      lbl_805D7AE4 &= ~1;
      c ^= 0x20;
    }
    if (ppp_rx_frame_ptr->len >= 0x800)
    {
      continue;
    }
    ppp_rx_frame_ptr->data[ppp_rx_frame_ptr->len++] = c;
    lbl_805D7AE8 = (lbl_805D7AE8 >> 8) ^ lbl_804FD3A8[(lbl_805D7AE8 ^ c) & 0xff];
  }

  tail:
  if ((((u16) (lobby_modem_connect_state - 3)) <= 1) && (is_transport_connected() == 0))
  {
    if ((((u32) lbl_805D7A8C) != 0) && (lobby_modem_connect_state == 4))
    {
      unlock_mutex(lbl_805C18A0.mutex);
      ((void (*)(s32, s32)) lbl_805D7A8C)(-1, 0);
      lock_mutex(lbl_805C18A0.mutex);
    }
    lobby_modem_connect_state = 5;
  }

  return 0;
}
#pragma pop
struct Lobby_804062A0 {
    u8 state;
    u8 pad[3];
    u8 sub[0x140];
};
/* Inline the helpers below; this applies to the rest of the file. */
#pragma dont_inline off
#pragma inline_depth(4)
inline s32 valid_80405A74(PppFrame **s) {
    s32 r = 0;
    if (s != NULL && *s != NULL) {
        r = 1;
    }
    return r;
}
inline s32 avail_80405A74(PppFrame **s) {
    s32 r = 0;
    if (valid_80405A74(s) && (*s)->len > 1) {
        r = 1;
    }
    return r;
}
inline s32 get_80405A74(PppFrame **s) {
    if (avail_80405A74(s)) {
        (*s)->len--;
        return *(*s)->data++;
    }
    if (TLobby__sub_80401BCC(s, &ppp_input_byte, 1) != 1) {
        return -1;
    }
    return (s16)ppp_input_byte;
}
#define FWD_80405A74()                                                       \
    (*(s16 *)(G + 0x13A))++;                                            \
    t = (PppFrame *)alloc_from_buffer((void *)arg0, 4); \
    p = t->data;                                                             \
    *p++ = 0xFF;                                                             \
    *p++ = 3;                                                                \
    write_network_u16_be(p, code);                                           \
    u = t;                                                                   \
    if (u == NULL) {                                                         \
        (*(s16 *)(G + 0x142))++;                                        \
        return;                                                              \
    }                                                                        \
    if (TLobby__sub_80401BCC(&u, &lobby_ppp_read_buf, 2) == 2) {                   \
        read_network_u16_be(&lobby_ppp_read_buf);                                 \
    }                                                                        \
    TLobby__sub_803FE6CC(G + 4, 8, 0, u);                                    \
    return;
void ppp_input_packet(PppFrame *arg0) {
    u16 code;
    u8 *G;
    PppFrame *t;
    u8 *p;
    PppFrame *u;
    u8 pad[0x24];
    if (arg0 == NULL) {
        return;
    }
    G = lbl_805C0038;
    if (lbl_805D7A7A == 0 && arg0->data[0] == 0xFF && arg0->data[1] == 3 &&
        TLobby__sub_80401BCC(&arg0, &lobby_ppp_read_buf, 2) == 2) {
        read_network_u16_be(&lobby_ppp_read_buf);
    }
    code = (u16)get_80405A74(&arg0);
    if (!(code & 1)) {
        code = (code << 8) | get_80405A74(&arg0);
    }
    switch (code) {
    case 0x21:
        if (*(u8 *)((s8 *)G + 0x6C) != 5) {
            (*(s16 *)((s8 *)G + 0x140))++;
            return;
        }
        TLobby__sub_804060B8(arg0->data, arg0->len, 0x800);
        return;
    case 0x57:
        if (*(u8 *)((s8 *)G + 0xD4) != 5) {
            (*(s16 *)((s8 *)G + 0x140))++;
            return;
        }
        TLobby__sub_804060B8(arg0->data, arg0->len, -0x7923);
        return;
    case 0x2D:
        if (*(u8 *)((s8 *)G + 0x6C) != 5) {
            (*(s16 *)((s8 *)G + 0x140))++;
            return;
        }
        if (!(*(s16 *)((s8 *)(*(u8 **)((s8 *)G + 0x9C)) + 0x28) & 4)) {
            (*(s16 *)((s8 *)G + 0x140))++;
            return;
        }
        if (TLobby__sub_804040E0(*(void **)((s8 *)(*(u8 **)((s8 *)G + 0x9C)) + 0x98), &arg0) <= 0) {
            (*(s16 *)((s8 *)G + 0x140))++;
            return;
        }
        TLobby__sub_804060B8(arg0->data, arg0->len, 0x800);
        return;
    case 0x2F:
        if (*(u8 *)((s8 *)G + 0x6C) != 5) {
            (*(s16 *)((s8 *)G + 0x140))++;
            return;
        }
        if (!(*(s16 *)((s8 *)(*(u8 **)((s8 *)G + 0x9C)) + 0x28) & 4)) {
            (*(s16 *)((s8 *)G + 0x140))++;
            return;
        }
        if (TLobby__sub_80403F4C(*(void **)((s8 *)(*(u8 **)((s8 *)G + 0x9C)) + 0x98), &arg0) <= 0) {
            (*(s16 *)((s8 *)G + 0x140))++;
            return;
        }
        TLobby__sub_804060B8(arg0->data, arg0->len, 0x800);
        return;
    case 0xC021:
        (*(s16 *)((s8 *)G + 0x130))++;
        TLobby__sub_803FDBF8(G + 4, arg0);
        return;
    case 0xC023:
        if (G[0] != 2 && G[0] != 3) {
            (*(s16 *)((s8 *)G + 0x140))++;
            if (G[0] == 0) {
                TLobby__sub_8040098C((Conn_804004DC *)(G + 4));
            }
            return;
        }
        (*(s16 *)((s8 *)G + 0x132))++;
        PADRead(G + 0x38, arg0);
        return;
    case 0xC223:
        if (G[0] != 2 && G[0] != 3) {
            (*(s16 *)((s8 *)G + 0x140))++;
            if (G[0] == 0) {
                TLobby__sub_8040098C((Conn_804004DC *)(G + 4));
            }
            return;
        }
        (*(s16 *)((s8 *)G + 0x136))++;
        dispatch_received_packet((void *)(G + 0xA0), (s32)arg0);
        return;
    case 0x8021:
        if (G[0] != 3) {
            (*(s16 *)((s8 *)G + 0x140))++;
            return;
        }
        (*(s16 *)((s8 *)G + 0x134))++;
        TLobby__sub_803FDBF8(G + 0x6C, arg0);
        return;
    case 0x8057:
        if (G[0] != 3) {
            (*(s16 *)((s8 *)G + 0x140))++;
            return;
        }
        if (lbl_805D7A7C != 6 && (s16)(s32)lbl_805D7A7C) {
            FWD_80405A74()
        }
        (*(s16 *)((s8 *)G + 0x138))++;
        TLobby__sub_803FDBF8(G + 0xD4, arg0);
        return;
    default:
        FWD_80405A74()
    }
}

#pragma push
#pragma opt_common_subs on
s32 TLobby__sub_804060B8(u8 *src, u16 len, int id) {
    int i;
    int idx;
    s32 n;
    s32 t;
    s16 *lim;
    s16 j;
    s16 *flags;
    u8 *dst;
    s16 stride;
    void TLobby__sub_80409818(void *, s32, s16, s32, u16); /* declared here with other parameter types; the definition is void (s32, s16, s16, s16, u16) */
    void NetMemcpy(void *, void *, s16); /* declared here with an s16 3rd argument; the definition takes int */

    for (i = 0; (s16)i < 2; i++) {
        if (lobby_net_buffer_desc_b.protocols[i].used != 0 && lobby_net_buffer_desc_b.protocols[i].type == (u16)id) {
            idx = i;
            break;
        }
    }
    if ((s16)i >= 2) {
        return 0;
    }
    lim = &lobby_net_buffer_desc_b.size;
    flags = lobby_net_buffer_desc_b.used;
    dst = lobby_net_buffer_desc_b.buffers;
    stride = lim[0];
    for (j = 0; j < lobby_net_buffer_desc_b.count; j++) {
        if (*flags == 0) {
            *flags = 1;
            if ((s16)len < *lim) {
                t = (s16)len;
            } else {
                t = *lim;
            }
            n = t;
            NetMemcpy(dst, src, n);
            TLobby__sub_80409818(dst, n, lobby_net_buffer_desc_b.id, idx, lobby_net_buffer_desc_b.protocols[(s16)idx].type);
            return 0;
        }
        flags++;
        dst += stride;
    }
    return 0;
}
#pragma pop
void TLobby__sub_8040059C(void* self);
void TLobby__sub_80402CE0(void* self);
void TLobby__sub_803FC318(void* self);
void TLobby__sub_803FEF4C(void* self);
void TLobby__sub_803F9FAC(void* self);
s32 TLobby__sub_804061FC(void)
{
  u8 *p;
  s32 z;
  u8 *new_var;
  u8 *q;
  z = 0;
  lbl_805D7ADC = (u8 *) z;
  p = lbl_805C0038;
  q = p;
  new_var = q;
  NetMemset(q, 0, 0x144);
  p[0] = z;
  TLobby__sub_8040059C(new_var);
  TLobby__sub_80402CE0(new_var);
  TLobby__sub_803FC318(new_var);
  TLobby__sub_803FEF4C(new_var);
  TLobby__sub_803F9FAC(new_var);
  if (p[0] == 0)
  {
    p[0] = 1;
  }
  TLobby__sub_803FD958(p + 4);
  return 0;
}

s32 TLobby__sub_804062A0(s16 arg0) {
    Lobby_804062A0 *l = (Lobby_804062A0 *)lbl_805C0038;

    switch (arg0) {
    case 0x82:
        if (l->state == 0) {
            l->state = 1;
        }
        TLobby__sub_803FD958(l->sub);
        return 0;
    case 0x81:
        TLobby__sub_803FD85C(l->sub);
        l->state = 0;
        return 0;
    default:
        return -1;
    }
}

s32 TLobby__sub_804048E8(void *, s32 *, s16); /* declared here with other parameter types; the definition is s32 (Obj_80403F4C *, PppFrame **, s16) */
s32 TLobby__sub_804066D8(u8 *);
s32 TLobby__sub_80406328(s32 self, s16 type) {
    s32 sv = self;
    void *me = (void *)self;
    s32 ty = type;
    u8 *G;
    u8 *t;
    u8 *p;
    s16 tag = 0x21;
    u8 pad[0x30];
    if (ty == -0x7923) {
        G = lbl_805C0038;
        if (G[0xd4] != 5) {
            (*(s16 *)(G + 0x122))++;
            return -1;
        }
        if (G[0] == 0) {
            (*(s16 *)(G + 0x122))++;
            return -1;
        }
        t = alloc_from_buffer(me, 4);
        p = *(u8 **)t;
        *p++ = 0xFF;
        *p++ = 3;
        write_network_u16_be(p, 0x57);
        if (t == NULL) {
            (*(s16 *)(G + 0x124))++;
            return -1;
        }
        return TLobby__sub_804066D8(t);
    }
    G = lbl_805C0038;
    if (G[0x6c] != 5) {
        (*(s16 *)(G + 0x122))++;
        return -1;
    }
    if (ty == 0x86dd) {
        if (G[0] == 0) {
            (*(s16 *)(G + 0x122))++;
            return -1;
        }
        t = alloc_from_buffer(me, 4);
        p = *(u8 **)t;
        *p++ = 0xFF;
        *p++ = 3;
        write_network_u16_be(p, 0x57);
        if (t == NULL) {
            (*(s16 *)(G + 0x124))++;
            return -1;
        }
        return TLobby__sub_804066D8(t);
    }
    {
        u8 *e = *(u8 **)(G + 0x9c);
        if (lbl_805D7A90 & 2) {
            s16 r;
            if (!(*(s16 *)(e + 0x28) & 4)) goto skip;
            r = TLobby__sub_804048E8(*(void **)(e + 0x98), &sv, e[0x84]);
            switch (r) {
            case 0x40: tag = 0x21; break;
            case 0x80: tag = 0x2d; break;
            case 0x70: tag = 0x2f; break;
            default:
                (*(s16 *)(G + 0x122))++;
                return -1;
            }
        } else {
            s16 r;
            if (!(*(s16 *)(e + 0x74) & 4)) goto skip;
            r = TLobby__sub_804048E8(*(void **)(e + 0x98), &sv, e[0x84]);
            switch (r) {
            case 0x40: tag = 0x21; break;
            case 0x80: tag = 0x2d; break;
            case 0x70: tag = 0x2f; break;
            default:
                (*(s16 *)(G + 0x122))++;
                return -1;
            }
        }
    }
skip:
    {
        void *a = (void *)sv;
        G = lbl_805C0038;
        if (G[0] == 0) {
            (*(s16 *)(G + 0x122))++;
            return -1;
        }
        {
            s16 tg = tag;
            u8 *t2 = alloc_from_buffer(a, 4);
            p = *(u8 **)t2;
            *p++ = 0xFF;
            *p++ = 3;
            write_network_u16_be(p, tg);
            if (t2 == NULL) {
                (*(s16 *)(G + 0x124))++;
                return -1;
            }
            return TLobby__sub_804066D8(t2);
        }
    }
}

s32 TLobby__sub_80406624(s32 a, s32 b, u16 code, void *self) {
    s32 pad[4];
    u16 r30;
    u8 *r29;
    u8 *p;
    u8 *ret;

    if (lbl_805C0038[0] == 0) {
        *(s16 *)(lbl_805C0038 + 0x122) = *(s16 *)(lbl_805C0038 + 0x122) + 1;
        return -1;
    }
    r30 = code;
    r29 = alloc_from_buffer(self, 4);
    p = *(u8 **)r29;
    *p++ = 0xff;
    *p++ = 3;
    write_network_u16_be(p, r30);
    ret = r29;
    if (r29 == 0) {
        *(s16 *)(lbl_805C0038 + 0x124) = *(s16 *)(lbl_805C0038 + 0x124) + 1;
        return -1;
    }
    return TLobby__sub_804066D8(ret);
}

s32 send_network_frame(u32 a, void* b);
inline s32 acfc_804066D8(s32 lcp, u8 *ctx)
{
  s32 r = 1;
  if ((!lcp) && ((*((s16 *) (ctx + 0x50))) & 0x100))
  {
    r = 0;
  }
  return r;
}
#pragma push
#pragma opt_propagation off
s32 TLobby__sub_804066D8(u8 *p)
{
  void get_time_ms(u32 *); /* declared here with other parameter types; the definition is void (s32 *) */
  u8 c0;
  u8 c1;
  u8 *st;
  u8 *ctx;
  s32 crc = 0xffff;
  u32 accm = -1;
  s32 n = 4;
  s32 sz;
  s16 stt;
  s32 padx[2];
  u8 *src;
  u8 *out;
  PppFrame *q;
  u8 *buf;
  PppBuffers *obj;
  u16 tag;
  s32 two;
  unsigned short pad;
  s32 pfc;
  s32 acfc;
  s32 lcp;
  s32 d;
  s32 skip;
  u16 fcs;
  st = *((u8 (*)[]) (&lbl_805C0038));
  ctx = *((u8 **) (st + 0x34));
  *((s32 *) (st + 0x110)) += ((u16) get_field_4(p)) + 2;
  if ((p == ((void *) 0)) || ((*((u16 *) (p + 4))) < 4))
  {
    *((s16 *) (st + 0x122)) += 1;
    return -1;
  }
  src = *((u8 **) p);
  c0 = src[0];
  c1 = src[1];
  tag = read_network_u16_be(src + 2);
  lcp = tag == 0xc021;
  if ((tag != 0xc021) && ((*((s16 *) (ctx + 0x50))) & 4))
  {
    accm = *((u32 *) (ctx + 0x54));
  }
  two = 1;
  pfc = two;
  if ((!lcp) && ((*((s16 *) (ctx + 0x50))) & 0x80))
  {
    pfc = 0;
  }
  if ((pfc == 0) && (tag < 0xff))
  {
    two = 0;
  }
  if (two == 0)
  {
    n = 3;
  }
  if ((*((s16 *) (&lbl_805D7A7A))) != 0)
  {
    acfc = 0;
  }
  else
  {
    acfc = acfc_804066D8(lcp, ctx);
  }
  if (acfc == 0)
  {
    n -= 2;
  }
  skip = 4 - n;
  *((u16 *) (p + 4)) -= skip;
  *((u8 **) p) += skip;
  out = *((u8 **) p);
  if (acfc != 0)
  {
    out[0] = c0;
    out[1] = c1;
    out += 2;
  }
  if (two != 0)
  {
    *out = tag >> 8;
    out++;
  }
  *out = tag;
  /* The game reads obj here before setting it (the headroom of whatever the register holds). */
  sz = obj->headroom;
  obj = &lbl_805C04A8;
  q = obj->frame_out;
  q->data = ((u8 *) q) + ((sz + 3) & (~3));
  buf = q->data;
  if ((*((s16 *) (&lbl_805D7A7A))) != 0)
  {
    NetMemcpy(buf + 0x14, *((u8 **) p), *((u16 *) (p + 4)));
    q->len = *((u16 *) (p + 4));
  }
  else
  {
    *buf = 0x7e;
    buf++;
    *((s32 *) (st + 0x114)) += 1;
    while ((d = get_80405A74((PppFrame **) (&p))) != (-1))
    {
      crc = (u16) ((((u16) crc) >> 8) ^ (*((u16 (*)[]) (&lbl_804FD3A8)))[(((u16) crc) ^ d) & 0xff]);
      if ((((d < 0x20) && (accm & (1 << d))) || (d == 0x7d)) || (d == 0x7e))
      {
        *(buf++) = 0x7d;
        *(buf++) = d ^ 0x20;
      }
      else
      {
        *(buf++) = d;
      }
    }

    crc ^= 0xffff;
    fcs = crc;
    d = fcs & 0xff;
    if ((((d < 0x20) && (accm & (1 << d))) || (d == 0x7d)) || (d == 0x7e))
    {
      *(buf++) = 0x7d;
      *(buf++) = d ^ 0x20;
    }
    else
    {
      *(buf++) = d;
    }
    d = fcs >> 8;
    if ((((d < 0x20) && (accm & (1 << d))) || (d == 0x7d)) || (d == 0x7e))
    {
      *(buf++) = 0x7d;
      *(buf++) = d ^ 0x20;
    }
    else
    {
      *(buf++) = d;
    }
    *(buf++) = 0x7e;
    q->len = buf - q->data;
  }
  stt = *((s16 *) (&lobby_modem_connect_state));
  if ((stt == 7) || (stt == 0))
  {
    return 0;
  }
  get_time_ms(&(*((u32 *) (&lbl_805D7A94))));
  return (s16) send_network_frame(q->len, q->data);
}
#pragma pop

s32 shutdown_network_handle(void) {
    TLobby__sub_803F8A08(&lobby_udp_socket_table);
    lobby_udp_socket_table.count = 0;
    return 0;
}

void init_msg(void *self, s32 arg1) {
    ((NetBufferRef *)self)->value = arg1;
    ((NetBufferRef *)self)->kind = 4;
}

void init_packet_header(void *self, s32 arg1) {
    ((NetBufferRef *)self)->value = arg1;
    ((NetBufferRef *)self)->kind = 3;
}

void set_value_and_enable(void *self, s32 arg1) {
    ((NetBufferRef *)self)->value = arg1;
    ((NetBufferRef *)self)->kind = 1;
}

#pragma push
#pragma opt_common_subs on
#pragma opt_propagation off
void TLobby__sub_80406FD8(void *a, void *b, s32 v) {
    u32 sr24;
    switch (((NetBufferRef *)b)->kind) {
    case 1:
    case 4:
        switch (((NetBufferRef *)a)->kind) {
        case 1:
        case 4:
            NetMemcpy((void *)((NetBufferRef *)a)->value, (void *)((NetBufferRef *)b)->value, v);
            break;
        case 2:
            {
        u32 word = ((NetBufferRef *)a)->value;
        s16 id = (s16)(word >> 24);
        u32 hi;
        u8 *rec;
        u8 *ent;
        u32 t;
        if (network_buffer_pool_state.count < id) {
            return;
        }
        hi = word >> 16;
        rec = (u8 *)network_buffer_pool_state.ents;
        rec += id * (s32)sizeof(NetBufferPoolEntry);
        ent = rec + (s16)(hi & 0xff) * (s32)sizeof(NetBufferSegment);
        t = *(u16 *)(ent + offsetof(NetBufferPoolEntry, segs[0].offset)) + (word & 0xffff) + *(u32 *)(rec + offsetof(NetBufferPoolEntry, buf));
        NetMemcpy((void *)t, (void *)((NetBufferRef *)b)->value, v);
        break;
    }
        case 3:
            NetMemcpy((void *)((NetBufferRef *)a)->value, (void *)((NetBufferRef *)b)->value, v);
            break;
        }
        break;
    case 2:
        switch (((NetBufferRef *)a)->kind) {
        case 1:
        case 4:
            {
        u32 word = ((NetBufferRef *)b)->value;
        s16 id = (s16)(word >> 24);
        u32 hi;
        u8 *rec;
        u8 *ent;
        u32 t;
        if (network_buffer_pool_state.count < id) {
            return;
        }
        hi = word >> 16;
        rec = (u8 *)network_buffer_pool_state.ents;
        rec += id * (s32)sizeof(NetBufferPoolEntry);
        ent = rec + (s16)(hi & 0xff) * (s32)sizeof(NetBufferSegment);
        t = *(u16 *)(ent + offsetof(NetBufferPoolEntry, segs[0].offset)) + (word & 0xffff) + *(u32 *)(rec + offsetof(NetBufferPoolEntry, buf));
        NetMemcpy((void *)((NetBufferRef *)a)->value, (void *)t, v);
        break;
    }
        case 2:
            {
        u32 word = ((NetBufferRef *)b)->value;
        s16 id = (s16)(word >> 24);
        u32 hi;
        u8 *rec;
        u8 *ent;
        u32 t;
        u32 word2;
        s16 id2;
        u32 hi2;
        u8 *rec2;
        u8 *ent2;
        u32 t2;
        if (network_buffer_pool_state.count < id) {
            return;
        }
        word2 = ((NetBufferRef *)a)->value;
        sr24 = word2 >> 24;
        id2 = (s16)sr24;
        rec = (u8 *)network_buffer_pool_state.ents + id * (s32)sizeof(NetBufferPoolEntry);
        hi = word >> 16;
        ent = rec + (s16)(hi & 0xff) * (s32)sizeof(NetBufferSegment);
        t = *(u16 *)(ent + offsetof(NetBufferPoolEntry, segs[0].offset)) + (word & 0xffff) + *(u32 *)(rec + offsetof(NetBufferPoolEntry, buf));
        if (network_buffer_pool_state.count < id2) {
            return;
        }
        rec2 = (u8 *)network_buffer_pool_state.ents + id2 * (s32)sizeof(NetBufferPoolEntry);
        hi2 = word2 >> 16;
        ent2 = rec2 + (s16)(hi2 & 0xff) * (s32)sizeof(NetBufferSegment);
        t2 = *(u16 *)(ent2 + offsetof(NetBufferPoolEntry, segs[0].offset)) + (word2 & 0xffff) + *(u32 *)(rec2 + offsetof(NetBufferPoolEntry, buf));
        NetMemcpy((void *)t2, (void *)t, v);
        break;
    }
        case 3:
            {
        u32 word = ((NetBufferRef *)b)->value;
        s16 id = (s16)(word >> 24);
        u32 hi;
        u8 *rec;
        u8 *ent;
        u32 t;
        if (network_buffer_pool_state.count < id) {
            return;
        }
        hi = word >> 16;
        rec = (u8 *)network_buffer_pool_state.ents;
        rec += id * (s32)sizeof(NetBufferPoolEntry);
        ent = rec + (s16)(hi & 0xff) * (s32)sizeof(NetBufferSegment);
        t = *(u16 *)(ent + offsetof(NetBufferPoolEntry, segs[0].offset)) + (word & 0xffff) + *(u32 *)(rec + offsetof(NetBufferPoolEntry, buf));
        NetMemcpy((void *)((NetBufferRef *)a)->value, (void *)t, v);
        break;
    }
        }
        break;
    case 3:
        switch (((NetBufferRef *)a)->kind) {
        case 1:
        case 4:
            NetMemcpy((void *)((NetBufferRef *)a)->value, (void *)((NetBufferRef *)b)->value, v);
            break;
        case 2:
            {
        u32 word = ((NetBufferRef *)a)->value;
        s16 id = (s16)(word >> 24);
        u32 hi;
        u8 *rec;
        u8 *ent;
        u32 t;
        if (network_buffer_pool_state.count < id) {
            return;
        }
        hi = word >> 16;
        rec = (u8 *)network_buffer_pool_state.ents;
        rec += id * (s32)sizeof(NetBufferPoolEntry);
        ent = rec + (s16)(hi & 0xff) * (s32)sizeof(NetBufferSegment);
        t = *(u16 *)(ent + offsetof(NetBufferPoolEntry, segs[0].offset)) + (word & 0xffff) + *(u32 *)(rec + offsetof(NetBufferPoolEntry, buf));
        NetMemcpy((void *)t, (void *)((NetBufferRef *)b)->value, v);
        break;
    }
        case 3:
            NetMemcpy((void *)((NetBufferRef *)a)->value, (void *)((NetBufferRef *)b)->value, v);
            break;
        }
        break;
    }
}
#pragma pop
#pragma push
#pragma optimization_level 3
s32 reset_socket_table(void) {
    s16 n;
    s16 i;
    NetPacket *p;
    TLobby__sub_803F8A0C(&lobby_udp_socket_table);
    n = lobby_udp_socket_table.count;
    p = lobby_udp_socket_table.packets;
    for (i = 0; i < n; i++, p++) {
        p->in_use = 0;
    }
    return 0;
}
#pragma pop

s32 TLobby__sub_80406B6C(NetBufferRef *o) {
    if (o != 0) {
        switch (o->kind) {
        case 1:
        case 3:
            break;
        case 2:
        case 4:
            if (TLobby__sub_8041579C(o) < 0) {
                return -1;
            }
            return 0;
        }
    }
    return -1;
}

u16 TUdpSocket__sub_80419864();
u16 TLobby__sub_80406BD8(NetPacket *pkt, s16 flag)
{
    u32 sum = 0;
    u8 *ptr;
    s32 count = pkt->fragment_count;
    s32 i;
    s16 carry = 0;
    u8 hdr[2];
    s16 len;
    NetBufferRef *ref;

    *(u16 *)hdr = 0;
    if (flag == 1) {
        while (count != 0) {
            count--;
            ref = &pkt->fragments[count].buffer;
            switch (pkt->fragments[count].buffer.kind) {
            case 1:
            case 4:
                ptr = (u8 *)ref->value;
                break;
            case 2: {
                u32 w = ref->value;
                s16 k = (s16)(w >> 24);
                NetBufferPoolEntry *ent;
                if (network_buffer_pool_state.count < k) {
                    return 0;
                }
                ent = &network_buffer_pool_state.ents[k];
                ptr = (u8 *)(ent->segs[(s16)((w >> 16) & 0xff)].offset + (w & 0xffff) + (u32)ent->buf);
                break;
            }
            case 3:
                ptr = (u8 *)pkt->fragments[count].buffer.value;
                break;
            }
            len = pkt->fragments[count].length;
            if (carry) {
                hdr[1] = *ptr++;
                sum += *(u16 *)hdr;
                len--;
            }
            if (len & 1) {
                hdr[0] = ptr[len - 1];
                hdr[1] = 0;
                carry = 1;
                len--;
            } else {
                *(u16 *)hdr = 0;
                carry = 0;
            }
            len = len >> 1;
            sum += TUdpSocket__sub_80419864(ptr, len);
        }
        if (carry) {
            sum += *(u16 *)hdr;
        }
    } else {
        for (i = 1; i < count; i++) {
            ref = &pkt->fragments[i].buffer;
            switch (pkt->fragments[i].buffer.kind) {
            case 1:
            case 4:
                ptr = (u8 *)ref->value;
                break;
            case 2: {
                u32 w = ref->value;
                s16 k = (s16)(w >> 24);
                NetBufferPoolEntry *ent;
                if (network_buffer_pool_state.count < k) {
                    return 0;
                }
                ent = &network_buffer_pool_state.ents[k];
                ptr = (u8 *)(ent->segs[(s16)((w >> 16) & 0xff)].offset + (w & 0xffff) + (u32)ent->buf);
                break;
            }
            case 3:
                ptr = (u8 *)pkt->fragments[i].buffer.value;
                break;
            }
            len = pkt->fragments[i].length;
            if (carry) {
                hdr[1] = *ptr++;
                sum += *(u16 *)hdr;
                len--;
            }
            if (len & 1) {
                hdr[0] = ptr[len - 1];
                hdr[1] = 0;
                carry = 1;
                len--;
            } else {
                *(u16 *)hdr = 0;
                carry = 0;
            }
            len = len >> 1;
            sum += TUdpSocket__sub_80419864(ptr, len);
        }
        if (carry) {
            sum += *(u16 *)hdr;
        }
    }
    if (sum & 0xffff0000) {
        sum = (sum >> 16) + (sum & 0xffff);
        sum += sum >> 16;
    }
    return (u16)sum;
}

void TLobby__sub_80406EB8(NetBufferRef *ref, s32 n) {
    switch (ref->kind) {
    case 4:
        break;
    case 1:
        ref->value += n;
        break;
    case 2:
        ref->value += n;
        break;
    case 3:
        ref->value += n;
        break;
    }
}

u8 *TLobby__sub_80406F0C(void *self)
{
    u32 w;
    s16 k;
    s16 j;
    u8 *rec;
    u8 *sub;

    switch (((NetBufferRef *)self)->kind) {
    case 1:
    case 4:
        return (u8 *)((NetBufferRef *)self)->value;
    case 2:
        w = ((NetBufferRef *)self)->value;
        k = (s16)(w >> 24);
        if (network_buffer_pool_state.count < k) {
            return 0;
        }
        j = (s16)((w >> 16) & 0xff);
        sub = (u8 *)network_buffer_pool_state.ents + k * (s32)sizeof(NetBufferPoolEntry);
        rec = sub;
        sub = rec + j * (s32)sizeof(NetBufferSegment);
        return (u8 *)(*(u16 *)(sub + offsetof(NetBufferPoolEntry, segs[0].offset)) + (w & 0xffff) + *(u32 *)(rec + offsetof(NetBufferPoolEntry, buf)));
    case 3:
        return (u8 *)((NetBufferRef *)self)->value;
    default:
        return 0;
    }
}

void release_entry(NetPacket *e) {
    s16 i;
    s16 n = lobby_udp_socket_table.count;
    NetPacket *p = lobby_udp_socket_table.packets;
    for (i = 0; i < n; i++, p++) {
        if (p->in_use == 1 && p == e) {
            p->in_use = 0;
            return;
        }
    }
}

NetPacket *alloc_free_entry(void) {
    s16 n = lobby_udp_socket_table.count;
    NetPacket *p = lobby_udp_socket_table.packets;
    s16 i;
    for (i = 0; i < n; i++, p++) {
        if (p->in_use == 0) {
            p->in_use = 1;
            return p;
        }
    }
    return 0;
}

