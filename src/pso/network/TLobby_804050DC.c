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
#include "pso/network/TLobby_80428374.h"
#include "pso/network/PppBuffer.h"
#include "pso/network/text_80421620.h"
/* The object header the stack's records share (laid out like TObject's fields). */
typedef struct Timer_804051CC Timer_804051CC;
typedef struct Lobby_804062A0 Lobby_804062A0;
typedef struct Obj_80405304 Obj_80405304;
s32 reset_socket_table(void);
void run_net_thread_loop(void);
void ppp_input_packet(PppFrame *arg0);

extern s32 lbl_805D7A94;
/* inferred: the PPP FCS-16 lookup table (RFC 1662 fcstab); the receive path checks the FCS against 0xF0B8. */
extern u16 ppp_fcs16_table[];
u8 ppp_rx_buffer[0x200];
NetPacketPool lobby_udp_socket_table;
s32 lbl_805D7AEC;
/* inferred: the receive path's running FCS: reset to 0xFFFF, folded per byte, good at 0xF0B8. */
u16 ppp_rx_fcs;
u32 ppp_rx_escape_pending;
u8 *ppp_rx_end_ptr;
u8 *ppp_rx_read_ptr;
PppFrame *ppp_rx_frame_ptr;
u8 ppp_input_byte;
u8 lobby_ppp_read_buf[4];
s32 lbl_805D7ACC;
void *lobby_timer_list_head;

#include <stddef.h>

typedef struct Obj_80405304 { u8 pad[0x18]; u8 f18; } Obj_80405304;


#include "pso/network/IPv6Send.h"
#include "pso/network/NetStackTypes.h"
#include "pso/network/PppLcp.h"
#include "pso/network/PppIpcp.h"

s32 TLobby__sub_803F79AC(void *);

void net_sleep_ms(int);
void pap_input(PppFsm *self, PppFrame *source);
s32 TLobby__sub_804060B8(u8 *, int, int);

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
            ppp_open_sub();
            unlock_mutex(g->mutex);
            continue;
        }
        net_sleep_ms(g->poll_ms);
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

s32 ppp_poll_input(void);

void process_expired_timers(void) {
    s32 now;
    Timer_804051CC *t;

    lock_mutex(lbl_805C18A0.mutex);
    ppp_poll_input();
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

void lobby_timer_add(N_80405298 *o, s32 v) {
    N_80405298 *p, *n;
    if (o == 0) {
        return;
    }
    o->f4 = v;
    if (lobby_timer_list_head == 0) {
        lobby_timer_list_head = o;
        o->next = 0;
    } else {
        p = lobby_timer_list_head;
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

void lobby_timer_stop(void *arg0) {
    Obj_80405304 *o = (Obj_80405304 *)arg0;
    if (o == NULL || o->f18 != 1) {
        return;
    }
    o->f18 = 0;
}

void lobby_timer_start(u8 *arg0) {
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

s32 TLobby__sub_804053B8(B_80403F4C *record, PppFrame **pp)
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
  u8 *p;
  u16 size;
  u16 rem;
  u8 flags;
  u8 cb;
  u32 pad;
  s32 ret;
  u8 c;
  u32 n;
  ret = ppp_buffer_read(pp, &hdr, 0x14);
  (void) (&pad);
  record->src_port = hdr.h0;
  record->dst_port = hdr.h2;
  record->seq = hdr.h4;
  record->ack = hdr.h8;
  flags = hdr.hd;
  cb = hdr.hc;
  record->urg = flags & 0x20;
  record->ack_flag = flags & 0x10;
  record->psh = flags & 0x8;
  record->rst = flags & 0x4;
  record->syn = flags & 0x2;
  record->fin = flags & 0x1;
  cb = (cb & 0xf0) >> 2;
  record->window = hdr.he;
  record->checksum = hdr.h10;
  record->urgent = hdr.h12;
  record->mss = 0;
  record->option_len = cb - 0x14;
  if ((((u16) ret) < 0x14) || (0x14 > cb))
  {
    return 0;
  }
  if (record->option_len == 0)
  {
    return cb;
  }
  if (record->option_len > (u16)get_field_4(*pp))
  {
    return 0;
  }
  ppp_buffer_read(pp, record->options, record->option_len);
  rem = record->option_len;
  p = record->options;
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
        record->mss = (p[2] << 8) | p[3];
      }
        break;

    }

    rem -= size;
    p += size;
  }

  return cb;
}

typedef struct TcpHeaderOut {
    u16 src_port;
    u16 dst_port;
    u32 seq;
    u32 ack;
    u8 data_offset;
    u8 flags;
    u16 window;
    u16 checksum;
    u16 urgent;
    u8 options[0x28];
} TcpHeaderOut;

typedef struct ChecksumObj {
    u8 pad0[0xA];
    u16 count;
} ChecksumObj;

PppFrame *TLobby__sub_8040555C(B_80403F4C *record, PppFrame *frame, u8 *obj) {
    TcpHeaderOut hdr;
    u32 n = 0;
    PppFrame *buf;
    TcpHeaderOut *hp;
    u8 *dst;
    u8 flags;
    u32 len;

    if (record->option_len != 0 && record->option_len <= 0x28) {
        n = record->option_len;
    } else if (record->mss != 0) {
        n = 4;
    }
    buf = alloc_from_buffer(frame, n + 0x14);
    if (buf == NULL) {
        return NULL;
    }
    dst = buf->data;
    hp = &hdr;
    flags = 0;
    hp->src_port = record->src_port;
    hp->dst_port = record->dst_port;
    hp->seq = record->seq;
    hp->ack = record->ack;
    hp->data_offset = (u8)((n + 0x14) << 2);
    if (record->urg) {
        flags |= 0x20;
    }
    if (record->ack_flag) {
        flags |= 0x10;
    }
    if (record->psh) {
        flags |= 0x8;
    }
    if (record->rst) {
        flags |= 0x4;
    }
    if (record->syn) {
        flags |= 0x2;
    }
    if (record->fin) {
        flags |= 0x1;
    }
    hp->flags = flags;
    hp->window = record->window;
    if (obj == NULL) {
        hp->checksum = record->checksum;
    } else {
        hp->checksum = 0;
    }
    hp->urgent = record->urgent;
    len = 0;
    if ((u16)n > len) {
        NetMemcpy(hp->options, record->options, record->option_len);
    }
    len = (u16)(n + 0x14);
    NetMemcpy(dst, hp, len);
    if (obj != NULL) {
        hp->checksum = TLobby__sub_803FE934(obj, buf, ((ChecksumObj *)obj)->count);
    }
    NetMemcpy(dst, hp, len);
    return buf;
}

#pragma push
#pragma opt_common_subs on
s32 ppp_poll_input(void)
{
  PppFrame *frame;
  u32 b;
  u16 id;
  u8 c;
  u16 st;
  u16 n;
  PppBuffers *base;
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
      ppp_rx_frame_ptr = (frame = base->frame_in);
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
  if (ppp_rx_read_ptr == 0)
  {
    ppp_rx_read_ptr = ppp_rx_buffer;
    ppp_rx_frame_ptr = 0;
    ppp_rx_fcs = 0xffff;
    ppp_rx_escape_pending = 0;
    ppp_rx_end_ptr = ppp_rx_buffer;
  }
  base = &lbl_805C04A8;
  for (;;)
  {
    if (ppp_rx_read_ptr == ppp_rx_end_ptr)
    {
      if ((recv_network_frame(sizeof(ppp_rx_buffer), ppp_rx_buffer, &st) != 0) || (st < 1))
      {
        goto tail;
      }
      ppp_rx_read_ptr = ppp_rx_buffer;
      ppp_rx_end_ptr = ppp_rx_buffer + st;
    }
    c = *(ppp_rx_read_ptr++);
    if (c == 0x7e)
    {
      if (((ppp_rx_frame_ptr != 0) && (ppp_rx_frame_ptr->len < 0x800)) && (ppp_rx_fcs == 0xf0b8))
      {
        n = get_field_4(ppp_rx_frame_ptr) - 2;
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
      ppp_rx_escape_pending |= 1;
      continue;
    }
    if (ppp_rx_frame_ptr == 0)
    {
      ppp_rx_frame_ptr = (frame = base->frame_in);
      ppp_rx_frame_ptr->data = ((u8 *) frame) + ((base->headroom + 0x83) & (~3));
      ppp_rx_frame_ptr->len = 0;
      ppp_rx_escape_pending = 0;
      ppp_rx_fcs = 0xffff;
    }
    if (ppp_rx_escape_pending & 1)
    {
      ppp_rx_escape_pending &= ~1;
      c ^= 0x20;
    }
    if (ppp_rx_frame_ptr->len >= 0x800)
    {
      continue;
    }
    ppp_rx_frame_ptr->data[ppp_rx_frame_ptr->len++] = c;
    ppp_rx_fcs = (ppp_rx_fcs >> 8) ^ ppp_fcs16_table[(ppp_rx_fcs ^ c) & 0xff];
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
    if (ppp_buffer_read(s, &ppp_input_byte, 1) != 1) {
        return -1;
    }
    return (s16)ppp_input_byte;
}
#define FWD_80405A74()                                                       \
    G->rx_drops++;                                                           \
    t = alloc_from_buffer(arg0, 4);                                          \
    p = t->data;                                                             \
    *p++ = 0xFF;                                                             \
    *p++ = 3;                                                                \
    write_network_u16_be(p, code);                                           \
    u = t;                                                                   \
    if (u == NULL) {                                                         \
        G->rx_alloc_drops++;                                                 \
        return;                                                              \
    }                                                                        \
    if (ppp_buffer_read(&u, lobby_ppp_read_buf, 2) == 2) {                   \
        read_network_u16_be(lobby_ppp_read_buf);                             \
    }                                                                        \
    ppp_fsm_send_packet(&G->lcp, 8, 0, u);                                   \
    return;
void ppp_input_packet(PppFrame *arg0) {
    u16 code;
    PppProtoBlocks *G;
    PppFrame *t;
    u8 *p;
    PppFrame *u;
    u8 pad[0x24];
    if (arg0 == NULL) {
        return;
    }
    G = &ppp_proto_blocks;
    if (lbl_805D7A7A == 0 && arg0->data[0] == 0xFF && arg0->data[1] == 3 &&
        ppp_buffer_read(&arg0, lobby_ppp_read_buf, 2) == 2) {
        read_network_u16_be(lobby_ppp_read_buf);
    }
    code = (u16)get_80405A74(&arg0);
    if (!(code & 1)) {
        code = (code << 8) | get_80405A74(&arg0);
    }
    switch (code) {
    case 0x21:
        if (G->ipcp.state != 5) {
            G->rx_err_drops++;
            return;
        }
        TLobby__sub_804060B8(arg0->data, arg0->len, 0x800);
        return;
    case 0x57:
        if (G->ipv6cp.state != 5) {
            G->rx_err_drops++;
            return;
        }
        TLobby__sub_804060B8(arg0->data, arg0->len, -0x7923);
        return;
    case 0x2D:
        if (G->ipcp.state != 5) {
            G->rx_err_drops++;
            return;
        }
        if (!(((IpcpConfig *)G->ipcp.opts)->local.got.flags & 4)) {
            G->rx_err_drops++;
            return;
        }
        if (TLobby__sub_804040E0(((IpcpConfig *)G->ipcp.opts)->net_list, &arg0) <= 0) {
            G->rx_err_drops++;
            return;
        }
        TLobby__sub_804060B8(arg0->data, arg0->len, 0x800);
        return;
    case 0x2F:
        if (G->ipcp.state != 5) {
            G->rx_err_drops++;
            return;
        }
        if (!(((IpcpConfig *)G->ipcp.opts)->local.got.flags & 4)) {
            G->rx_err_drops++;
            return;
        }
        if (TLobby__sub_80403F4C(((IpcpConfig *)G->ipcp.opts)->net_list, &arg0) <= 0) {
            G->rx_err_drops++;
            return;
        }
        TLobby__sub_804060B8(arg0->data, arg0->len, 0x800);
        return;
    case 0xC021:
        G->rx_lcp++;
        TLobby__sub_803FDBF8(&G->lcp, arg0);
        return;
    case 0xC023:
        if (G->busy != 2 && G->busy != 3) {
            G->rx_err_drops++;
            if (G->busy == 0) {
                setup_auth_after_lcp_negotiation(&G->lcp);
            }
            return;
        }
        G->rx_pap++;
        pap_input(&G->pap, arg0);
        return;
    case 0xC223:
        if (G->busy != 2 && G->busy != 3) {
            G->rx_err_drops++;
            if (G->busy == 0) {
                setup_auth_after_lcp_negotiation(&G->lcp);
            }
            return;
        }
        G->rx_chap++;
        chap_input(&G->chap, arg0);
        return;
    case 0x8021:
        if (G->busy != 3) {
            G->rx_err_drops++;
            return;
        }
        G->rx_ipcp++;
        TLobby__sub_803FDBF8(&G->ipcp, arg0);
        return;
    case 0x8057:
        if (G->busy != 3) {
            G->rx_err_drops++;
            return;
        }
        if (lbl_805D7A7C != 6 && (s16)(s32)lbl_805D7A7C) {
            FWD_80405A74()
        }
        G->rx_ipv6cp++;
        TLobby__sub_803FDBF8(&G->ipv6cp, arg0);
        return;
    default:
        FWD_80405A74()
    }
}

#pragma push
#pragma opt_common_subs on
s32 TLobby__sub_804060B8(u8 *src, int len, int id) {
    s16 i;
    s16 idx;
    s16 n;
    s16 *lim;
    s16 j;
    s16 *flags;
    u8 *dst;
    s16 stride;

    for (i = 0; i < 2; i++) {
        if (lobby_net_buffer_desc_b.protocols[i].used != 0 && lobby_net_buffer_desc_b.protocols[i].type == (u16)id) {
            idx = i;
            break;
        }
    }
    if (i >= 2) {
        return 0;
    }
    lim = &lobby_net_buffer_desc_b.size;
    flags = lobby_net_buffer_desc_b.used;
    dst = lobby_net_buffer_desc_b.buffers;
    stride = lim[0];
    for (j = 0; j < lobby_net_buffer_desc_b.count; j++) {
        if (*flags == 0) {
            *flags = 1;
            n = ((s16)len < *lim) ? (s16)len : *lim;
            NetMemcpy(dst, src, n);
            TLobby__sub_80409818((saddr)dst, n, lobby_net_buffer_desc_b.id, idx, lobby_net_buffer_desc_b.protocols[idx].type);
            return 0;
        }
        flags++;
        dst += stride;
    }
    return 0;
}
#pragma pop
void init_lcp_protocol(u8 *conn);
void pap_init(u8 *arg0);
s32 TLobby__sub_804061FC(void)
{
  u8 *p;
  s32 z;
  u8 *new_var;
  u8 *q;
  z = 0;
  ppp_rx_read_ptr = (u8 *) z;
  /* CodeWarrior keeps the original register order when using the first member. */
  p = &ppp_proto_blocks.busy;
  q = p;
  new_var = q;
  NetMemset((PppProtoBlocks *)q, 0, 0x144);
  p[0] = z;
  init_lcp_protocol((u8 *)(PppProtoBlocks *)new_var);
  pap_init((u8 *)(PppProtoBlocks *)new_var);
  TLobby__sub_803FC318((PppProtoBlocks *)new_var);
  TLobby__sub_803FEF4C((PppProtoBlocks *)new_var);
  TLobby__sub_803F9FAC((PppProtoBlocks *)new_var);
  if (p[0] == 0)
  {
    p[0] = 1;
  }
  TLobby__sub_803FD958((u8 *)&((PppProtoBlocks *)p)->lcp);
  return 0;
}

s32 TLobby__sub_804062A0(s16 arg0) {
    Lobby_804062A0 *l = (Lobby_804062A0 *)&ppp_proto_blocks;

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

s16 ppp_output_frame(PppFrame *);
s16 TLobby__sub_80406328(saddr self, s16 type) {
    PppFrame *sv = (PppFrame *)self;
    PppFrame *me = (PppFrame *)self;
    s32 ty = type;
    PppProtoBlocks *G;
    PppFrame *t;
    u8 *p;
    s16 tag = 0x21;
    u8 pad[0x30];
    if (ty == -0x7923) {
        G = &ppp_proto_blocks;
        if (G->ipv6cp.state != 5) {
            G->tx_drops++;
            return -1;
        }
        if (G->busy == 0) {
            G->tx_drops++;
            return -1;
        }
        t = alloc_from_buffer(me, 4);
        p = t->data;
        *p++ = 0xFF;
        *p++ = 3;
        write_network_u16_be(p, 0x57);
        if (t == NULL) {
            G->tx_alloc_drops++;
            return -1;
        }
        return ppp_output_frame(t);
    }
    G = &ppp_proto_blocks;
    if (G->ipcp.state != 5) {
        G->tx_drops++;
        return -1;
    }
    if (ty == 0x86dd) {
        if (G->busy == 0) {
            G->tx_drops++;
            return -1;
        }
        t = alloc_from_buffer(me, 4);
        p = t->data;
        *p++ = 0xFF;
        *p++ = 3;
        write_network_u16_be(p, 0x57);
        if (t == NULL) {
            G->tx_alloc_drops++;
            return -1;
        }
        return ppp_output_frame(t);
    }
    {
        IpcpConfig *e = G->ipcp.opts;
        if (lbl_805D7A90 & 2) {
            s16 r;
            if (!(e->local.got.flags & 4)) goto skip;
            r = TLobby__sub_804048E8(e->net_list, &sv, e->peer.got.vj_comp_slot);
            switch (r) {
            case 0x40: tag = 0x21; break;
            case 0x80: tag = 0x2d; break;
            case 0x70: tag = 0x2f; break;
            default:
                G->tx_drops++;
                return -1;
            }
        } else {
            s16 r;
            if (!(e->peer.got.flags & 4)) goto skip;
            r = TLobby__sub_804048E8(e->net_list, &sv, e->peer.got.vj_comp_slot);
            switch (r) {
            case 0x40: tag = 0x21; break;
            case 0x80: tag = 0x2d; break;
            case 0x70: tag = 0x2f; break;
            default:
                G->tx_drops++;
                return -1;
            }
        }
    }
skip:
    {
        PppFrame *a = sv;
        G = &ppp_proto_blocks;
        if (G->busy == 0) {
            G->tx_drops++;
            return -1;
        }
        {
            s16 tg = tag;
            PppFrame *t2 = alloc_from_buffer(a, 4);
            p = t2->data;
            *p++ = 0xFF;
            *p++ = 3;
            write_network_u16_be(p, tg);
            if (t2 == NULL) {
                G->tx_alloc_drops++;
                return -1;
            }
            return ppp_output_frame(t2);
        }
    }
}

s16 TLobby__sub_80406624(s32 a, s32 b, u16 code, PppFrame *self) {
    s32 pad[4];
    u16 r30;
    PppFrame *r29;
    u8 *p;
    PppFrame *ret;

    if (ppp_proto_blocks.busy == 0) {
        ppp_proto_blocks.tx_drops = ppp_proto_blocks.tx_drops + 1;
        return -1;
    }
    r30 = code;
    r29 = alloc_from_buffer(self, 4);
    p = r29->data;
    *p++ = 0xff;
    *p++ = 3;
    write_network_u16_be(p, r30);
    ret = r29;
    if (r29 == 0) {
        ppp_proto_blocks.tx_alloc_drops = ppp_proto_blocks.tx_alloc_drops + 1;
        return -1;
    }
    return ppp_output_frame(ret);
}

/* 1 while the address and control fields (LCP_OPT_ACFC) or the high protocol byte (LCP_OPT_PFC) must be sent:
   always for LCP frames, otherwise until the peer has agreed to the compression option. */
inline s32 ppp_keep_field(s32 is_lcp, LcpOpts *opts, s32 opt) {
    s32 r = 1;
    if (!is_lcp && (opts->remote.got.mask & opt)) {
        r = 0;
    }
    return r;
}

inline s32 ppp_protocol_field_is_two_bytes(s32 is_lcp, LcpOpts *opts, u16 proto) {
    s32 r = 1;
    if (ppp_keep_field(is_lcp, opts, LCP_OPT_PFC) == 0 && proto < 0xff) {
        r = 0;
    }
    return r;
}

#pragma push
#pragma opt_propagation off
s16 ppp_output_frame(PppFrame *p) {
    PppFrame *frame;
    u8 *out;
    u8 *hdr;
    LcpOpts *opts;
    PppBuffers *bufs;
    u16 fcs;
    s32 crc = 0xffff;
    u8 *src;
    u8 ctrl;
    u8 addr;
    s32 two;
    s32 is_lcp;
    s16 state;
    u32 accm = -1;
    s32 n = 4;
    PppProtoBlocks *ppp;
    s32 sz;
    u16 proto;
    s32 c;
    s32 pfc;
    s32 skip;
    s32 acfc;

    ppp = &ppp_proto_blocks;
    opts = ppp->lcp.opts;
    ppp->tx_bytes += (u16)get_field_4(p) + 2;
    if (p == NULL || p->len < 4) {
        ppp->tx_drops += 1;
        return -1;
    }
    src = p->data;
    addr = src[0];
    ctrl = src[1];
    proto = read_network_u16_be(src + 2);
    is_lcp = proto == 0xc021;
    if (proto != 0xc021 && (opts->remote.got.mask & LCP_OPT_ACCM)) {
        accm = opts->remote.got.accm;
    }
    two = ppp_protocol_field_is_two_bytes(is_lcp, opts, proto);
    if (two == 0) {
        n = 3;
    }
    if (lbl_805D7A7A != 0) {
        acfc = 0;
    } else {
        acfc = ppp_keep_field(is_lcp, opts, LCP_OPT_ACFC);
    }
    if (acfc == 0) {
        n -= 2;
    }
    skip = 4 - n;
    p->len -= skip;
    p->data += skip;
    hdr = p->data;
    if (acfc != 0) {
        hdr[0] = addr;
        hdr[1] = ctrl;
        hdr += 2;
    }
    if (two != 0) {
        *hdr++ = proto >> 8;
    }
    *hdr++ = proto;
    bufs = &lbl_805C04A8;
    frame = bufs->frame_out;
    frame->data = (u8 *)frame + ((bufs->headroom + 3) & ~3);
    out = frame->data;
    if (lbl_805D7A7A != 0) {
        NetMemcpy(out + 0x14, p->data, p->len);
        frame->len = p->len;
    } else {
        *out++ = 0x7e;
        ppp->tx_packets += 1;
        while ((c = get_80405A74(&p)) != -1) {
            crc = (u16)(((u16)crc >> 8) ^ ppp_fcs16_table[((u16)crc ^ c) & 0xff]);
            if ((c < 0x20 && (accm & (1 << c))) || c == 0x7d || c == 0x7e) {
                *out++ = 0x7d;
                *out++ = c ^ 0x20;
            } else {
                *out++ = c;
            }
        }

        crc ^= 0xffff;
        fcs = crc;
        c = fcs & 0xff;
        if ((c < 0x20 && (accm & (1 << c))) || c == 0x7d || c == 0x7e) {
            *out++ = 0x7d;
            *out++ = c ^ 0x20;
        } else {
            *out++ = c;
        }
        c = fcs >> 8;
        if ((c < 0x20 && (accm & (1 << c))) || c == 0x7d || c == 0x7e) {
            *out++ = 0x7d;
            *out++ = c ^ 0x20;
        } else {
            *out++ = c;
        }
        *out++ = 0x7e;
        frame->len = out - frame->data;
    }
    state = lobby_modem_connect_state;
    if (state == 7 || state == 0) {
        return 0;
    }
    get_time_ms(&lbl_805D7A94);
    return send_network_frame(frame->len, frame->data);
}
#pragma pop

s32 shutdown_network_handle(void) {
    TLobby__sub_803F8A08(&lobby_udp_socket_table);
    lobby_udp_socket_table.count = 0;
    return 0;
}

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

#pragma push
#pragma opt_lifetimes off
u16 packet_ones_complement_sum(NetPacket *pkt, s16 flag)
{
    NetPacketFragment *e;
    u32 sum;
    u8 *ptr;
    s32 count;
    s32 i;
    s16 carry;
    u8 hdr[2];

    count = pkt->fragment_count;
    sum = 0;
    carry = 0;
    *(u16 *)hdr = 0;
    if (flag == 1) {
        e = pkt->fragments + count - 1;
        while (count != 0) {
            u8 kind = e->buffer.kind;
            u32 *w = &e->buffer.value;
            s16 len;
            e--;
            count--;
            switch (kind) {
            case 1:
            case 4:
                ptr = (u8 *)*w;
                break;
            case 2: {
                u32 word = *w;
                s16 k = (s16)(word >> 24);
                NetBufferPoolEntry *ent;
                u16 seg;
                if (network_buffer_pool_state.count < k) {
                    return 0;
                }
                ent = network_buffer_pool_state.ents;
                ent = ent + k;
                seg = ent->segs[(s16)((len = word >> 16) & 0xff)].offset;
                {
                    u32 t = (u32)ent->buf;
                    t = (word & 0xffff) + t;
                    t = seg + t;
                    ptr = (u8 *)t;
                }
                break;
            }
            case 3:
                ptr = (u8 *)e[1].buffer.value;
                break;
            }
            len = e[1].length;
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
            sum += ones_complement_sum(ptr, len);
        }
        if (carry) {
            sum += *(u16 *)hdr;
        }
    } else {
        e = pkt->fragments;
        for (i = 1; i < count; e++, i++) {
            u32 *w = &e[1].buffer.value;
            s16 len;
            switch (e[1].buffer.kind) {
            case 1:
            case 4:
                ptr = (u8 *)*w;
                break;
            case 2: {
                u32 word = *w;
                s16 k = (s16)(word >> 24);
                NetBufferPoolEntry *ent;
                u16 seg;
                if (network_buffer_pool_state.count < k) {
                    return 0;
                }
                ent = network_buffer_pool_state.ents;
                ent = ent + k;
                {
                    u32 t = (u32)ent->buf;
                    seg = ent->segs[(s16)((len = word >> 16) & 0xff)].offset;
                    t = (word & 0xffff) + t;
                    t = seg + t;
                    ptr = (u8 *)t;
                }
                break;
            }
            case 3:
                ptr = (u8 *)e[1].buffer.value;
                break;
            }
            len = e[1].length;
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
            sum += ones_complement_sum(ptr, len);
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
#pragma pop

void netbuf_ref_advance(NetBufferRef *ref, s32 n) {
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

u8 *netbuf_ref_data(void *self)
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

void init_msg(NetBufferRef *ref, s32 value) {
    ref->value = value;
    ref->kind = 4;
}

void init_packet_header(NetBufferRef *ref, s32 value) {
    ref->value = value;
    ref->kind = 3;
}

void set_value_and_enable(NetBufferRef *ref, s32 value) {
    ref->value = value;
    ref->kind = 1;
}

#pragma push
#pragma opt_common_subs on
#pragma opt_propagation off
void netbuf_copy_by_ref(void *a, void *b, s32 v) {
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
        u32 word2;
        s16 id = (s16)(word >> 24);
        s16 cnt = network_buffer_pool_state.count;
        NetBufferPoolEntry *ents;
        u32 hi;
        u8 *ent;
        u32 t;
        s16 id2;
        u32 raw;
        u8 *rec;
        u32 t2;
        if (cnt < id) {
            return;
        }
        hi = word >> 16;
        word2 = ((NetBufferRef *)a)->value;
        ents = network_buffer_pool_state.ents;
        rec = (u8 *)&ents[id];
        raw = word2 >> 24;
        ent = rec + (s16)(hi & 0xff) * (s32)sizeof(NetBufferSegment);
        id2 = (s16)raw;
        t = *(u16 *)(ent + offsetof(NetBufferPoolEntry, segs[0].offset)) + (word & 0xffff) + *(u32 *)(rec + offsetof(NetBufferPoolEntry, buf));
        if (cnt < id2) {
            return;
        }
        hi = word2 >> 16;
        rec = (u8 *)&ents[id2];
        ent = rec + (s16)(hi & 0xff) * (s32)sizeof(NetBufferSegment);
        t2 = *(u16 *)(ent + offsetof(NetBufferPoolEntry, segs[0].offset)) + (word2 & 0xffff) + *(u32 *)(rec + offsetof(NetBufferPoolEntry, buf));
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

