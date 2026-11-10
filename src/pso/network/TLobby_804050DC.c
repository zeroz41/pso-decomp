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
typedef struct TObjectFields {
    const char *m_name;
    u16 m_flags;
    u16 m_id;
    void *m_prev;
    void *m_next;
    void *m_up;
    void *m_down;
} TObjectFields;
typedef struct Timer_804051CC Timer_804051CC;
typedef struct Lobby_804062A0 Lobby_804062A0;
typedef struct RtEntry_8040F8A4 RtEntry_8040F8A4;
typedef struct Obj_80405304 Obj_80405304;
typedef struct Hdr_8040B6E4 Hdr_8040B6E4;
typedef struct Pkt_8040B6E4 Pkt_8040B6E4;
typedef struct Q_8040B6E4 Q_8040B6E4;
typedef struct QT_8040B6E4 QT_8040B6E4;
typedef struct Hdr_8040B790 Hdr_8040B790;
typedef struct Pkt_8040B790 Pkt_8040B790;
typedef struct Q_8040B790 Q_8040B790;
typedef struct QT_8040B790 QT_8040B790;
typedef struct LobbyHandler LobbyHandler;
typedef struct LobbyHandlerTable LobbyHandlerTable;
typedef struct Hdr_80408C24 Hdr_80408C24;
typedef struct Ent_8040D95C Ent_8040D95C;
typedef struct PH_8040EC38 PH_8040EC38;
typedef struct P_8040EC38 P_8040EC38;
typedef void (*Fn_8040881C)(void);
s32 build_dns_query_a(void *self, u8 *name, s16 len);
s32 build_dns_query_aaaa(void *self, u8 *name, s16 len);
u16 calc_ip_checksum(void *self, s16 b);
u16 calc_pseudo_header_checksum(s32 src, s32 dst, s8 proto, void *pkt, s16 flag);
s32 close_and_reset_connection(void *self);
s32 compare_sockaddr(void *self, u8 *arg1);
void complete_pending_request(s16 id);
s32 dispatch_by_addr_family(s32 arg0, NetworkAddress *arg1, NetworkAddress *arg2, u8 *arg3, void *arg4, void *arg5);
s32 dispatch_handler_by_id(s16 arg0, s32 arg1, s32 arg2);
s32 dispatch_handler_by_index(s16 arg0, s32 arg1, s32 arg2, s32 arg3);
void dispatch_request_callback(void *self, s16 status);
s32 dispatch_slot_a(s16 arg0, s32 arg1);
s32 dispatch_slot_b(s16 arg0, s32 arg1);
s32 forward_net_op(s16 arg0, u8 *arg1, u8 *arg2);
s32 forward_socket_op_by_handle(s16 id, u8 *a, u8 *b);
s16 * get_active_entry_by_index(s16 arg0);
s32 init_ipv4_interfaces(void);
s16 init_net_sockets(void);
s32 init_packet_fragment_pools(void);
s32 is_lookup_found(u32 arg0, u32 arg1);
s32 is_multicast_address(void *self, s16 arg1);
void release_entry(void *self);
s32 reset_socket_table(void);
void run_net_thread_loop(void);
s32 send_ethernet_frame(s16 idx, s16 mode, u8 *addr, void *pkt);
void tick_connection_timeouts(void);
NetPacket *alloc_packet_with_header(ArpFields *f, ArpIface *iface);
s32 append_to_list(DnsHost *o, DnsAddr *n);
ArpEntry *find_free_peer_entry(void);
NetworkAddress *find_next_active_record(DnsQuery *a);
ArpEntry *find_oldest_peer_entry(s16 state);
ArpEntry *find_or_add_peer_entry(s16 handler, s32 socket, u8 plen, void *paddr, u8 hlen, void *haddr, s16 state);
s32 is_addr_unspecified(u8 *arg0);
void ppp_input_packet(PppFrame *arg0);
void reset_connection_requests(DnsPtr *o_, s16 arg1);
s32 select_source_address(Out_8040D95C *arg0, In_8040D95C *arg1);

extern PppFrame *ppp_rx_frame_ptr;
extern s32 lbl_805D7A94;
extern u8 *lbl_805D7ADC;
extern u8 *lbl_805D7AE0;
extern u32 lbl_805D7AE4;
extern u16 lbl_805D7AE8;
extern u16 lbl_804FD3A8[];
extern u8 lbl_805C18B0[];
extern s16 TLobby__sub_804290D4(s32 idx);
s16 NetIPv4AddRoute(u32, u32, u32, s16, u8, u16);

extern void TLobby__sub_8040B1C4(void *);
extern void TLobby__sub_8040BE40(DnsQuery *self, s16 a, s16 b);

struct Self_803FD85C;

#include <stddef.h>

typedef struct RtEntry_8040F8A4 { u16 flags; u8 pad2[2]; u32 id; u32 mask; u32 owner; u8 pad10[4]; } RtEntry_8040F8A4;

typedef struct Obj_80405304 { u8 pad[0x18]; u8 f18; } Obj_80405304;

typedef struct Hdr_8040B6E4 { u16 id; u8 f2; u8 f3; s16 qd; s16 an; s16 ns; s16 ar; u8 body[4]; } Hdr_8040B6E4;

typedef struct Pkt_8040B6E4 { u8 pad0[2]; s16 len; Hdr_8040B6E4 *hdr; } Pkt_8040B6E4;

typedef struct Q_8040B6E4 { u8 pad0[6]; u16 id; u8 pad8[0x10]; Pkt_8040B6E4 *pkt; } Q_8040B6E4;

typedef struct QT_8040B6E4 { s16 type; s16 cls; } QT_8040B6E4;

typedef struct Hdr_8040B790 { u16 id; u8 f2; u8 f3; s16 qd; s16 an; s16 ns; s16 ar; u8 body[4]; } Hdr_8040B790;

typedef struct Pkt_8040B790 { u8 pad0[2]; s16 len; Hdr_8040B790 *hdr; } Pkt_8040B790;

typedef struct Q_8040B790 { u8 pad0[6]; u16 id; u8 pad8[0x10]; Pkt_8040B790 *pkt; } Q_8040B790;

typedef struct QT_8040B790 { s16 type; s16 cls; } QT_8040B790;


/* A link-layer driver, registered by TLobby__sub_8040A2BC from 11 functions: loopback (TLobby__sub_8041510C,
   always entry 0), PPP (TLobby__sub_803FD10C) and Ethernet (init_net_sockets).  Each function is called by one
   dispatcher (named after the slot); op14..op20 only when flags & 4. */
struct LobbyHandler {
    s16 active;
    s16 flags;                                     /* 0x02: as registered: 1 loopback, 2 PPP, 0x7C Ethernet */
    s32 (*get_interface_id)(s16 idx, void *dst);   /* 0x04: TLobby__sub_8040A0C0 */
    s32 (*op08)(s16 idx, u32 a, s32 b, u32 *c);    /* 0x08: TLobby__sub_8040A044 */
    s32 (*op0C)(s32);                              /* 0x0C: call_entry_callback */
    s32 (*op10)(s32);                              /* 0x10: invoke_socket_callback */
    s32 (*op14)(s32);                              /* 0x14: TLobby__sub_80409EB0 */
    s32 (*op18)(s32, s32);                         /* 0x18: TLobby__sub_80409E18 */
    s32 (*op1C)(s32, s32, s32);                    /* 0x1C: TLobby__sub_80409D7C */
    s32 (*op20)(s32, s32, s32);                    /* 0x20: TLobby__sub_80409CE0 */
    s32 (*op24)(s32, s32);                         /* 0x24: dispatch_handler_by_id; TLobby__sub_80409818 calls it
                                                      as void (s16, s32) */
    s32 (*op28)(s32, s32, s32);                    /* 0x28: dispatch_handler_by_index */
    s32 (*output)(s32, s32, s32, s32);             /* 0x2C: call_handler_by_index */
};
typedef char LobbyHandler_size_check[sizeof(LobbyHandler) == 0x30 ? 1 : -1];

typedef struct LobbyHandlerTable { s16 count; LobbyHandler *list; } LobbyHandlerTable;
extern LobbyHandlerTable lobby_handler_table_desc;
typedef char LobbyHandlerTable_size_check[sizeof(LobbyHandlerTable) == 8 ? 1 : -1];

#include "pso/network/IPv6Send.h"
#include "pso/network/NetStackTypes.h"

s32 TLobby__sub_803F79AC(void *);
s32 TUdpSocket__sub_80407508(void);
void TLobby__sub_804073B8(void);
s32 TLobby__sub_80407C60(s16, s32);
s32 TLobby__sub_80407D98(s16, s32);
s16 TLobby__sub_80407F20(s16 a, s16 b, s16 c, s16 d, s16 e, s32 f, s16 g, s32 h);
s32 TLobby__sub_8040878C(void);
s32 TLobby__sub_8040C9E0(DnsAddr *arg0, DnsAddr *arg1);
u16 TLobby__sub_8040D8F0(u8 *arg0, u8 *arg1, s8 arg2, u8 *arg3, s16 arg4);
s32 TLobby__sub_8040DA54(u8 *arg0, u8 *arg1);

u8 * TLobby__sub_8040F76C(u32, u32);
s32 TLobby__sub_8040FEE4(s32 arg0, s32 arg1);
s16 TLobby__sub_80413D78();
s32 TLobby__sub_8040FE40(s16 arg0);
extern RecoveredGlobal_8040DD68_lbl_805C1B38 ipv4_protocol_state;
s32 TLobby__sub_8040ED70(void);
s16 TLobby__sub_8040A2BC(Fn_8040881C *fns, s16 kind);
u16 TLobby__sub_80406BD8(const void *, s16);
s32 OSDisableInterrupts(void);
s32 OSRestoreInterrupts(s32);
void TLobby__sub_803F97E8(int);
extern u8 lbl_805C0038[];
s32 TLobby__sub_8040B838(u8 *dst, u8 *src, s32 max);
s16 TLobby__sub_80401BCC(void *, void *, int);
void TLobby__sub_803FDBF8(u8 *self, void *arg1);
void PADRead(u8 *, PppFrame *); /* declared here with other parameter types; the definition is void (u8 *, s32) */
s16 TLobby__sub_804040E0(void *self, void *arg);
s32 TLobby__sub_804060B8(u8 *, u16, int);
extern u8 ppp_input_byte;
s32 TLobby__sub_80409AD8(void);
s16 TLobby__sub_80413F0C();


struct N_80405298;

struct Self_803FDA68;

struct V_803FE600;


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
    lbl_805D7ADC = lbl_805C18B0;
    ppp_rx_frame_ptr = 0;
    lbl_805D7AE8 = 0xffff;
    lbl_805D7AE4 = 0;
    lbl_805D7AE0 = lbl_805C18B0;
  }
  base = &lbl_805C04A8;
  for (;;)
  {
    if (lbl_805D7ADC == lbl_805D7AE0)
    {
      if ((recv_network_frame(0x200, lbl_805C18B0, &st) != 0) || (st < 1))
      {
        goto tail;
      }
      lbl_805D7ADC = lbl_805C18B0;
      lbl_805D7AE0 = lbl_805C18B0 + st;
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
        id2 = (s16)(word2 >> 24);
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
u16 TLobby__sub_80406BD8(const void *arg_, s16 flag)
{
  s32 count = *((s32 *) (((u8 *) arg_) + offsetof(NetPacket, fragment_count)));
  u32 sum = 0;
  u8 *new_var;
  s16 carry = 0;
  u8 hdr[2];
  *((u16 *) hdr) = 0;
  if (flag == 1)
  {
    u8 *e;
    e = (u8 *) arg_;
    e += count * (s32)sizeof(NetPacketFragment);
    while (count != 0)
    {
      u8 *ptr;
      u8 type = *((u8 *) (e + offsetof(NetPacketFragment, buffer.kind)));
      u8 *w = e + offsetof(NetPacketFragment, buffer);
      s16 len;
      count--;
      e -= sizeof(NetPacketFragment);
      switch (type)
      {
        case 1:

        case 4:
          ptr = *((u8 **) w);
          break;

        case 2:
        {
          u32 word = *((u32 *) w);
          s16 id = (s16) (word >> 24);
          u8 *rec;
          if (network_buffer_pool_state.count < id)
          {
            return 0;
          }
          rec = (u8 *)network_buffer_pool_state.ents;
          rec = rec + (id * (s32)sizeof(NetBufferPoolEntry));
          {
            u32 t = (*((u32 *) (rec + offsetof(NetBufferPoolEntry, buf)))) + (word & 0xffff);
            t = (*((u16 *) ((rec + (((s16) ((word >> 16) & 0xff)) * (s32)sizeof(NetBufferSegment))) + offsetof(NetBufferPoolEntry, segs[0].offset)))) + t;
            ptr = (u8 *) t;
          }
          break;
        }

        new_var = e;
        case 3:
          ptr = *((u8 **) (new_var + sizeof(NetPacketFragment) + offsetof(NetPacketFragment, buffer)));
          break;

        default:
          break;

      }

      len = *((s16 *) (e + sizeof(NetPacketFragment) + offsetof(NetPacketFragment, length)));
      if (carry)
      {
        hdr[1] = *(ptr++);
        sum += *((u16 *) hdr);
        len--;
      }
      if (len & 1)
      {
        hdr[0] = ptr[len + (-1)];
        hdr[1] = 0;
        carry = 1;
        len--;
      }
      else
      {
        *((u16 *) hdr) = 0;
        carry = 0;
      }
      len = (s16) (((s32) len) >> 1);
      sum += TUdpSocket__sub_80419864(ptr, len);
    }

    if (carry)
    {
      sum += *((u16 *) hdr);
    }
  }
  else
  {
    u8 *e = ((u8 *) arg_) + offsetof(NetPacket, fragments);
    s32 i;
    for (i = 1; i < count; e += sizeof(NetPacketFragment), i++)
    {
      u8 *w = e + sizeof(NetPacketFragment) + offsetof(NetPacketFragment, buffer);
      u8 *ptr;
      s16 len;
      switch (*((u8 *) (e + sizeof(NetPacketFragment) + offsetof(NetPacketFragment, buffer.kind))))
      {
        case 1:

        case 4:
          ptr = *((u8 **) w);
          break;

        case 2:
        {
          u32 word = *((u32 *) w);
          s16 id = (s16) (word >> 24);
          u8 *rec;
          if (network_buffer_pool_state.count < id)
          {
            return 0;
          }
          rec = (u8 *)network_buffer_pool_state.ents;
          rec = rec + (id * (s32)sizeof(NetBufferPoolEntry));
          {
            u32 t = (*((u32 *) (rec + offsetof(NetBufferPoolEntry, buf)))) + (word & 0xffff);
            t = (*((u16 *) ((rec + (((s16) ((word >> 16) & 0xff)) * (s32)sizeof(NetBufferSegment))) + offsetof(NetBufferPoolEntry, segs[0].offset)))) + t;
            ptr = (u8 *) t;
          }
          break;
        }

        case 3:
          ptr = *((u8 **) (e + sizeof(NetPacketFragment) + offsetof(NetPacketFragment, buffer)));
          break;

        default:
          break;

      }

      len = *((s16 *) (e + sizeof(NetPacketFragment) + offsetof(NetPacketFragment, length)));
      if (carry)
      {
        hdr[1] = *(ptr++);
        sum += *((u16 *) hdr);
        len--;
      }
      if (len & 1)
      {
        hdr[0] = ptr[len - 1];
        hdr[1] = 0;
        carry = 1;
        len--;
      }
      else
      {
        *((u16 *) hdr) = 0;
        carry = 0;
      }
      len = (s16) (((s32) len) >> 1);
      sum += TUdpSocket__sub_80419864(ptr, len);
    }

    if (carry)
    {
      sum += *((u16 *) hdr);
    }
  }
  if (sum & 0xffff0000)
  {
    sum = (sum >> 16) + (sum & 0xffff);
    sum += sum >> 16;
  }
  return (u16) sum;
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

void release_entry(void *self) {
    NetPacket *e = (NetPacket *)self;
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

u8 *alloc_free_entry(void) {
    s16 n = lobby_udp_socket_table.count;
    NetPacket *p = lobby_udp_socket_table.packets;
    s16 i;
    for (i = 0; i < n; i++, p++) {
        if (p->in_use == 0) {
            p->in_use = 1;
            return (u8 *)p;
        }
    }
    return 0;
}

s32 NetUnregisterTimer(void* p);
void TLobby__sub_804078B4(void);
s32 TLobby__sub_80407358(void) {
    ArpState *g = &lbl_805C1AB0;
    s32 tmp[2];
    release_slot_by_id(0x806);
    NetUnregisterTimer((void *)TLobby__sub_804078B4);
    TLobby__sub_803F8A24(g);
    g->nentries = 0;
    g->nifaces = 0;
    g->nholds = 0;
    g->naliases = 0;
    return 0;
}

void TLobby__sub_804073B8(void) {
    TUdpSocket__sub_80407508();
}

s32 dispatch_slot_a(s16 arg0, s32 arg1) {
    return TLobby__sub_80407C60(arg0, arg1);
}

s32 dispatch_slot_b(s16 arg0, s32 arg1) {
    return TLobby__sub_80407D98(arg0, arg1);
}

s32 TLobby__sub_80407418(s16 id) {
    ArpState *t = &lbl_805C1AB0;
    ArpIface *e;
    s16 ok;
    s32 tmp[2];

    e = t->ifaces;
    if (id >= 0 && id < t->nifaces) {
        ok = 1;
    } else {
        ok = -1;
    }
    if (ok >= 0) {
        e = &e[id];
    } else {
        e = NULL;
    }
    if (e == NULL) {
        return -2;
    }
    if (e->used == 0) {
        return -2;
    }
    call_entry_callback(e->handler, e->arp_socket);
    TLobby__sub_80408388(id);
    return 0;
}

s32 forward_net_op(s16 arg0, u8 *arg1, u8 *arg2) {
    return TLobby__sub_8040799C(arg0, arg1, arg2);
}

void forward_net_op_5args(s16 arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4, s32 arg5, s8 arg6, s32 arg7) {
    s16 TLobby__sub_80407F20(s16, s16, s16, s16, s16, s32, s8, s32);
    TLobby__sub_80407F20(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7);
}

extern s32 TLobby__sub_80407640(void *pkt, s16 a, s16 b, s16 c);
s32 TUdpSocket__sub_80407508(void)
{
    ArpState *tbl = &lbl_805C1AB0;
    s16 *step;
    ArpEntry *p;
    s16 j;
    ArpIface *p2;
    s16 i;
    ArpHold *q;
    s16 k;
    ArpAlias *p4;
    long sum;

    init_net_buffer_config(&lbl_805C1AB0);
    i = tbl->nentries;
    p = tbl->entries;
    for (; i > 0; i--) {
        NetMemset(p, 0, sizeof(ArpEntry));
        p->state = 0;
        p->hold = NULL;
        p++;
    }
    j = tbl->nifaces;
    p2 = tbl->ifaces;
    for (; j > 0; j--) {
        NetMemset(p2, 0, sizeof(ArpIface));
        p2++;
    }
    k = tbl->nholds;
    step = &tbl->hold_size;
    q = tbl->holds;
    sum = (long)tbl->hold_buffers;
    for (; k > 0; k--) {
        NetMemset(q, 0, sizeof(ArpHold));
        q->cap = *step;
        q->data = sum;
        q++;
        sum += *step;
    }
    j = tbl->naliases;
    p4 = tbl->aliases;
    for (; j > 0; j--) {
        NetMemset(p4, 0, sizeof(ArpAlias));
        p4++;
    }
    register_protocol_handler(0x806, (NetProtocolHandler)TLobby__sub_80407640);
    NetRegisterTimer(60000, 1, TLobby__sub_804078B4);
    return 0;
}

s32 TLobby__sub_804082AC(ArpIface *iface, ArpFields *f, void *haddr);
inline ArpIface *FindHit_80407640(ArpState *t, s16 b, s16 c) {
    ArpIface *hit;
    s16 i;
    s16 n;
    if (b < 0) {
        return NULL;
    }
    hit = t->ifaces;
    n = t->nifaces;
    for (i = 0; i < n; i++, hit++) {
        if (hit->used == 1 && hit->handler == b && hit->arp_socket == c) {
            return hit;
        }
    }
    return NULL;
}

inline s16 CheckPkt_80407640(ArpHeader *pkt, ArpIface *hit) {
    if (NetMemcmp(pkt, &hit->htype, 6) == 0) {
        if (pkt->op == 1 || pkt->op == 2) {
            return 1;
        }
    }
    return -1;
}

inline ArpEntry *FindPeer_80407640(ArpEntry *peer, s16 n, u8 ff, u8 *p2) {
    for (; n > 0; n--, peer++) {
        if (peer->plen == ff && peer->state != 0 && NetMemcmp(peer->paddr, p2, peer->plen) == 0) {
            return peer;
        }
    }
    return 0;
}
#pragma push
#pragma opt_common_subs on
extern s32 TLobby__sub_80407640(void *pkt, s16 a, s16 b, s16 c)
{
  s32 call_handler_by_index(s16 arg0, s16 arg1, s32 arg2, s32 arg3, s32 arg4); /* declared here with an s16 2nd argument; the definition takes s32 */
  s16 TLobby__sub_804082AC(ArpIface *, ArpFields *, void *); /* declared here with an s16 result; the definition returns s32 */
  ArpState *t = &lbl_805C1AB0;
  ArpHeader *pp;
  ArpIface *hit;
  ArpEntry *peer;
  u8 *p2;
  ArpFields in;
  u8 buf[8];
  ArpFields out;
  NetPacket *r;
  if (a < 8) {
    return -1;
  }
  if (b < 0) {
    return -1;
  }
  hit = FindHit_80407640(t, b, c);
  if (hit == NULL) {
    return -1;
  }
  pp = (ArpHeader *) pkt;
  if (CheckPkt_80407640(pp, hit) < 0) {
    return -1;
  }
  in.hdr = pp;
  p2 = (u8 *)pp + sizeof(ArpHeader);
  in.sha = p2;
  p2 += hit->hlen;
  in.spa = p2;
  p2 += hit->plen;
  in.tha = p2;
  p2 += hit->hlen;
  in.tpa = p2;
  peer = FindPeer_80407640(t->entries, t->nentries, hit->plen, in.spa);
  if (peer != NULL) {
    find_or_add_peer_entry(hit->handler, hit->socket, hit->plen, in.spa, hit->hlen, in.sha, 2);
  }
  if (pp->op == 1) {
    if (TLobby__sub_804082AC(hit, &in, buf) > 0) {
      r = alloc_packet_with_header(&out, hit);
      if (r != NULL) {
        out.hdr->op = 2;
        NetMemcpy(out.sha, buf, hit->hlen);
        NetMemcpy(out.tha, in.sha, hit->hlen);
        NetMemcpy(out.spa, in.tpa, hit->plen);
        NetMemcpy(out.tpa, in.spa, hit->plen);
        call_handler_by_index(hit->handler, c, 0, (s32)in.sha, (s32)r);
        if (r != NULL) {
          release_entry((void *)r);
        }
      }
    }
  }
  return 0;
}
#pragma pop
void TLobby__sub_804078B4(void) {
    ArpEntry* p;
    s16 n;
    n = lbl_805C1AB0.nentries;
    p = lbl_805C1AB0.entries;
    for (; n > 0; n--, p++) {
        if (p->state != 0) {
            if (p->timer != 0) {
                p->timer--;
            }
            if (p->timer == 0 && p->state != 4 && p->state != 8) {
                if (p->hold != NULL) {
                    if (p->hold != NULL) {
                        p->hold->entry = NULL;
                        p->hold->len = 0;
                        p->hold->used = 0;
                    }
                    p->hold = NULL;
                }
                p->state = 0;
                p->timer = 0;
                NetMemset(p->haddr, 0, sizeof(p->haddr));
                NetMemset(p->paddr, 0, sizeof(p->paddr));
            }
        }
    }
}

void TLobby__sub_80408060(ArpEntry *entry, NetPacket *pkt);

inline ArpIface *Lookup_8040799C(ArpState *t, s16 idx) {
    ArpIface *list = t->ifaces;
    s16 ok;
    if (idx >= 0 && idx < t->nifaces) {
        ok = 1;
    } else {
        ok = -1;
    }
    if (ok >= 0) {
        return &list[idx];
    }
    return NULL;
}

inline ArpEntry *Find_8040799C(ArpState *t, u8 k, void *name) {
    s16 n = t->nentries;
    ArpEntry *p = t->entries;
    for (; n > 0; n--, p++) {
        if (p->plen == k && p->state != 0 && NetMemcmp(p->paddr, name, p->plen) == 0) {
            return p;
        }
    }
    return NULL;
}

inline void Clear_8040799C(ArpEntry *p) {
    if (p->hold != NULL) {
        p->hold->entry = NULL;
        p->hold->len = 0;
        p->hold->used = 0;
    }
}

inline void Send_8040799C(ArpIface *e, void *name) {
    ArpFields o;
    NetPacket *r = alloc_packet_with_header(&o, e);
    if (r != NULL) {
        o.hdr->op = 1;
        NetMemcpy(o.sha, e->haddr, e->hlen);
        NetMemcpy(o.spa, e->paddr, e->plen);
        NetMemset(o.tha, 0, e->hlen);
        NetMemcpy(o.tpa, name, e->plen);
        call_handler_by_index(e->handler, e->arp_socket, 1, 0, (s32)r);
        if (r != NULL) {
            release_entry((void *)r);
        }
    }
}

s32 TLobby__sub_8040799C(s16 idx, void *name, void *arg2) {
    ArpState *t = &lbl_805C1AB0;
    ArpIface *e;
    ArpEntry *p;
    s32 ret;
    ArpEntry *np;

    e = Lookup_8040799C(t, idx);
    if (e == NULL) {
        return -2;
    }
    ret = 0;
    p = Find_8040799C(t, e->plen, name);
    if (p != NULL) {
        p->timer = t->timeout;
        if (p->state != 1) {
            ret = call_handler_by_index(e->handler, e->socket, 0, (s32)p->haddr, (s32)arg2);
        } else {
            if (p->hold != NULL) {
                Clear_8040799C(p);
                p->hold = NULL;
            }
            TLobby__sub_80408060(p, arg2);
            Send_8040799C(e, name);
            p->timer = t->retry;
        }
    } else {
        u8 buf[6];
        NetMemset(buf, 0, 6);
        np = find_or_add_peer_entry(e->handler, e->socket, e->plen, name, e->hlen, buf, 1);
        TLobby__sub_80408060(np, arg2);
        Send_8040799C(e, name);
        np->timer = t->retry;
    }
    return ret;
}

s32 TLobby__sub_80407C60(s16 id, s32 key) {
    ArpState *tbl = &lbl_805C1AB0;
    ArpIface *base = tbl->ifaces;
    s16 ok;
    ArpIface *e;
    ArpAlias *p;
    ArpAlias *prev;
    s16 i;
    u8 pad[8];
    if (id >= 0 && id < tbl->nifaces) {
        ok = 1;
    } else {
        ok = -1;
    }
    if (ok >= 0) {
        e = base + id;
    } else {
        e = NULL;
    }
    if (e == NULL) {
        return -1;
    }
    if (e->used == 0) {
        return -1;
    }
    if (e->aliases == NULL) {
        return -1;
    }
    p = e->aliases;
    i = 0;
    while (p->next != NULL) {
        i++;
        if (tbl->naliases <= i) {
            return -1;
        }
        if (NetMemcmp(p->addr, (void *)key, 4) == 0) {
            if (e->aliases == p) {
                e->aliases = p->next;
            } else {
                prev->next = p->next;
            }
            p->next = NULL;
            p->used = 0;
            return 0;
        }
        prev = p;
        p = p->next;
    }
    return -1;
}

inline ArpIface *lookup2_80407D98(ArpState *t, s16 idx) {
    ArpIface *list = t->ifaces;
    s16 ok;
    if (idx >= 0 && idx < t->nifaces) {
        ok = 1;
    } else {
        ok = -1;
    }
    if (ok >= 0) {
        return list + idx;
    }
    return NULL;
}
inline ArpAlias *alloc2_80407D98(ArpState *t, s16 *count) {
    ArpAlias *p = t->aliases;
    s16 n = *count;
    for (; n > 0; n--, p++) {
        if (p->used == 0) {
            p->used = 1;
            p->next = NULL;
            NetMemset(p->addr, 0, 4);
            return p;
        }
    }
    return NULL;
}
static s32 TLobby__sub_80407D98(s16 id, s32 pkey) {
    s16 lim;
    ArpAlias *next;
    ArpAlias *p;
    ArpIface *e;
    ArpAlias *node;
    s16 *max;
    ArpState *t = &lbl_805C1AB0;
    s16 k;

    e = lookup2_80407D98(t, id);
    if (e == NULL) {
        return -1;
    }
    if (e->used == 0) {
        return -1;
    }
    node = alloc2_80407D98(t, max = &t->naliases);
    if (node == NULL) {
        return -1;
    }
    NetMemcpy(node->addr, (void *)pkey, 4);
    node->used = 1;
    node->next = NULL;
    if (e->aliases == NULL) {
        e->aliases = node;
    } else {
        lim = *max;
        p = e->aliases;
        k = 0;
        while ((next = p->next) != NULL) {
            k++;
            if (lim <= k) {
                return -1;
            }
            p = next;
        }
        p->next = node;
    }
    return 0;
}

inline ArpIface *findfree_80407F20(ArpIface *base) {
    ArpIface *p;
    s16 i;
    p = base;
    for (i = 0; i < lbl_805C1AB0.nifaces; i++, p++) {
        if (p->used == 0) {
            return p;
        }
    }
    return NULL;
}

s16 TLobby__sub_80407F20(s16 a, s16 b, s16 c, s16 d, s16 e, s32 f, s16 g, s32 h)
{
    ArpIface *base;
    ArpIface *slot;
    s16 res;
    s16 idx;
    s16 TLobby__sub_8040A044(s16, u32, s16, u32 *); /* declared here with an s16 result and 3rd argument; the definition is s32 (s16, u32, s32, u32 *) */
    s32 call_entry_callback(s16, s16); /* declared here with an s16 2nd argument; the definition takes s32 */

    if (a < 0) {
        return -1;
    }
    res = TLobby__sub_8040A044(a, 0x806, g, (u32 *)h);
    if (res < 0) {
        return res;
    }
    base = lbl_805C1AB0.ifaces;
    slot = findfree_80407F20(base);
    if (slot == NULL) {
        call_entry_callback(a, res);
        return -0x10d;
    }
    slot->used = 1;
    idx = (s16)(slot - base);
    slot->handler = a;
    slot->socket = b;
    slot->arp_socket = res;
    slot->index = idx;
    slot->htype = c;
    slot->ptype = d;
    slot->hlen = e;
    slot->plen = g;
    slot->f10 = 0;
    NetMemcpy(slot->haddr, (void *)f, e);
    NetMemcpy(slot->paddr, (void *)h, g);
    slot->aliases = NULL;
    return idx;
}
extern void TLobby__sub_80408060(ArpEntry *entry, NetPacket *pkt) {
u8 tmp[0x8];
ArpHold *found;
s16 sum = 0;
ArpHold *best = NULL;
ArpHold *e = lbl_805C1AB0.holds;
s16 n = lbl_805C1AB0.nholds;
found = NULL;
while (n > 0)
{
if (e->used == 0)
{
found = e;
break;
}
if (best == NULL)
{
best = e;
}
else
if (e->entry->timer < best->entry->timer)
{
best = e;
}
e++;
n--;
}
if (found == NULL)
{
ArpEntry *o_m = best->entry;
if (o_m->hold != NULL)
{
o_m->hold->entry = NULL;
o_m->hold->len = 0;
o_m->hold->used = 0;
}
o_m->hold = NULL;
found = best;
}
if (found->cap < ((s16) pkt->total_bytes))
{
return;
}
{
NetPacketFragment *p;
s16 k;
s32 src;
found->used = 1;
k = (s16) pkt->fragment_count;
src = found->data;
p = pkt->fragments + k - 1;
while (k > 0)
{
set_value_and_enable(tmp, src);
TLobby__sub_80406FD8((void *)(tmp), (void *)&pkt->fragments[k - 1].buffer, (s32)p->length);
src += p->length;
sum += p->length;
p--;
k--;
}
}
found->len = sum;
found->entry = entry;
entry->hold = found;
}

NetPacket *alloc_packet_with_header(ArpFields *f, ArpIface *iface) {
    s16 len;
    NetPacket *pkt;
    u8 *buf;
    u16 t;
    u8 *q;
    t = iface->hlen * 2 + 8;
    t += iface->plen * 2;
    len = t;
    if ((u32)len > 0x1CU) {
        return NULL;
    }
    pkt = (NetPacket *)alloc_free_entry();
    if (pkt == NULL) {
        return NULL;
    }
    pkt->fragment_count = 1;
    pkt->total_bytes = len;
    buf = (u8 *)&lbl_805C1AB0.packet;
    pkt->fragments[0].length = t;
    set_value_and_enable(&pkt->fragments[0].buffer, (s32)*(u8 **)buf);
    buf = *(u8 **)buf;
    NetMemset(buf, 0, len);
    NetMemcpy(buf, &iface->htype, 6);
    f->hdr = (ArpHeader *)buf;
    q = buf + sizeof(ArpHeader);
    f->sha = q;
    q += iface->hlen;
    f->spa = q;
    q += iface->plen;
    f->tha = q;
    q += iface->hlen;
    f->tpa = q;
    return pkt;
}

s32 TLobby__sub_804082AC(ArpIface *iface, ArpFields *f, void *haddr) {
    s16 i;
    ArpAlias *p;

    if (NetMemcmp(iface->paddr, f->tpa, iface->plen) == 0) {
        NetMemcpy(haddr, iface->haddr, iface->hlen);
        return 1;
    }
    if (iface->aliases != NULL) {
        p = iface->aliases;
        i = 0;
        while (p != NULL) {
            i++;
            if (lbl_805C1AB0.naliases <= i) {
                return -1;
            }
            if (NetMemcmp(p->addr, f->tpa, iface->plen) == 0) {
                NetMemcpy(haddr, iface->haddr, iface->hlen);
                return 1;
            }
            p = p->next;
        }
    }
    return -1;
}

s32 TLobby__sub_80408388(s16 id) {
    ArpState *t = &lbl_805C1AB0;
    ArpIface *e;
    ArpAlias *n;
    ArpAlias *next;
    s16 ok;

    e = t->ifaces;
    if (id >= 0 && id < t->nifaces) {
        ok = 1;
    } else {
        ok = -1;
    }
    if (ok >= 0) {
        e = &e[id];
        for (n = e->aliases; n != NULL; n = next) {
            next = n->next;
            n->next = NULL;
            n->used = 0;
        }
        NetMemset(e, 0, sizeof(ArpIface));
        return 1;
    }
    return -1;
}

inline ArpEntry *find_80408428(ArpState *t, u8 plen, void *paddr) {
    s16 n = t->nentries;
    ArpEntry *e = t->entries;
    while (n > 0) {
        if (e->plen == plen && e->state != 0 && NetMemcmp(e->paddr, paddr, e->plen) == 0) {
            return e;
        }
        n--;
        e++;
    }
    return NULL;
}

inline void detach_80408428(ArpEntry *e) {
    if (e->hold != NULL) {
        e->hold->entry = NULL;
        e->hold->len = 0;
        e->hold->used = 0;
    }
    e->hold = NULL;
}

ArpEntry *find_or_add_peer_entry(s16 handler, s32 socket, u8 plen, void *paddr, u8 hlen, void *haddr, s16 state) {
    ArpState *t = &lbl_805C1AB0;
    ArpEntry *e;
    NetPacket *p;

    e = find_80408428(t, plen, paddr);
    if (e != NULL) {
        e->timer = t->timeout;
        if (haddr == NULL) {
            return e;
        }
        if (e->state != 1) {
            int n2 = hlen;
            if (NetMemcmp(e->haddr, haddr, n2) != 0) {
                NetMemcpy(e->haddr, haddr, n2);
                e->state = state;
            }
            return e;
        }
        NetMemcpy(e->haddr, haddr, hlen);
        e->state = state;
        if (e->hold != NULL) {
            p = (NetPacket *)alloc_free_entry();
            if (p != NULL) {
                p->fragment_count = 1;
                p->total_bytes = e->hold->len;
                p->fragments[0].length = e->hold->len;
                set_value_and_enable(&p->fragments[0].buffer, e->hold->data);
                call_handler_by_index(handler, socket, 0, (s32)e->haddr, (s32)p);
                release_entry((void *)p);
            }
        }
        detach_80408428(e);
        return e;
    }
    if (haddr == NULL) {
        return NULL;
    }
    e = find_free_peer_entry();
    if (e == NULL) {
        e = find_oldest_peer_entry(4);
        if (e == NULL) {
            e = find_oldest_peer_entry(0);
        }
        if (e->hold != NULL) {
            detach_80408428(e);
        }
        e->state = 0;
        e->timer = 0;
        NetMemset(e->haddr, 0, sizeof(e->haddr));
        NetMemset(e->paddr, 0, sizeof(e->paddr));
    }
    if (haddr != NULL) {
        NetMemcpy(e->haddr, haddr, hlen);
    }
    NetMemcpy(e->paddr, paddr, plen);
    e->hlen = hlen;
    e->plen = plen;
    e->state = state;
    e->timer = t->timeout;
    e->hold = NULL;
    return e;
}

ArpEntry *find_oldest_peer_entry(s16 state) {
    ArpEntry *best = 0;
    ArpEntry *p;
    s16 n = lbl_805C1AB0.nentries;
    s32 v;
    p = lbl_805C1AB0.entries;
    for (; n > 0; n--, p++) {
        v = p->state;
        if ((s16)v != 0 && v != state) {
            if (best == 0) {
                best = p;
            } else if (best->timer > p->timer) {
                best = p;
            }
        }
    }
    return best;
}

ArpEntry *find_free_peer_entry(void) {
    s16 n = lbl_805C1AB0.nentries;
    ArpEntry *e = lbl_805C1AB0.entries;
    while (n > 0) {
        if (e->state == 0) {
            return e;
        }
        n--;
        e++;
    }
    return NULL;
}

void flush_flags_step(void) {
    TLobby__sub_8040878C();
}

s16 run_connect_step(void) {
    return init_net_sockets();
}

s32 TLobby__sub_8040878C(void) {
    EthernetState *tbl = (0, (void *)&lbl_805C1AD8);
    s16 n;
    s16 i;
    EthLink *ent;
    i = 0;
    n = tbl->ndrivers;
    ent = tbl->links;
    for (; i < n; i++, ent++) {
        if (ent->used != 0) {
            clear_table_entry_locked(ent->id);
            ent->used = 0;
            ent->id = 0;
            ent->dev = 0;
        }
    }
    tbl->nlinks = 0;
    tbl->nsockets = 0;
    tbl->nslots = 0;
    TLobby__sub_803F8AB8(tbl);
    return 0;
}


s32 TLobby__sub_80408F2C(s16 id, u8 *pkt);
s32 TLobby__sub_80409130(s16 arg0, s16 arg1, s32 arg2);
s32 TLobby__sub_80408FD8(s16 idx, s16 mode, u8 *data);
s32 TLobby__sub_8040920C(s16 id, u8 *dst);
s32 TLobby__sub_804092FC(s16 idx);
s32 TLobby__sub_8040939C();
s32 TLobby__sub_804093EC(s16 idx);
s16 TLobby__sub_804094B8(s16 a, u16 b, s16 c, void *k);
s32 TLobby__sub_8040970C(s16 idx, u8 *dst);
s16 init_net_sockets(void) {
    Fn_8040881C fns[11];
    s16 r;
    s16 first;
    s16 cnt;
    s16 i;
    EthLink *e;
    EthDriver *d;
    EthLink **pe;

    init_net_func_table(&lbl_805C1AD8);
    pe = &lbl_805C1AD8.links;
    NetMemset(*pe, 0, lbl_805C1AD8.nlinks * sizeof(EthLink));
    NetMemset(lbl_805C1AD8.sockets, 0, lbl_805C1AD8.nsockets * sizeof(EthSocket));
    NetMemset(lbl_805C1AD8.slots, 0, lbl_805C1AD8.nslots * sizeof(EthFrameSlot));
    fns[0] = (Fn_8040881C)TLobby__sub_8040970C;
    fns[1] = (Fn_8040881C)TLobby__sub_804094B8;
    fns[2] = (Fn_8040881C)TLobby__sub_804093EC;
    fns[3] = (Fn_8040881C)TLobby__sub_8040939C;
    fns[4] = (Fn_8040881C)TLobby__sub_804092FC;
    fns[5] = (Fn_8040881C)TLobby__sub_8040920C;
    fns[6] = (Fn_8040881C)TLobby__sub_80409130;
    fns[7] = (Fn_8040881C)TLobby__sub_80408FD8;
    fns[8] = (Fn_8040881C)TLobby__sub_80408F2C;
    fns[9] = (Fn_8040881C)forward_socket_op_by_handle;
    fns[10] = (Fn_8040881C)send_ethernet_frame;
    first = -1;
    cnt = lbl_805C1AD8.ndrivers;
    d = lbl_805C1AD8.drivers;
    e = *pe;
    i = 0;
    while (i < cnt) {
        if (d->init != NULL) {
            r = d->init(i);
            if (r < 0) {
                return r;
            }
        } else {
            return -0x111;
        }
        r = TLobby__sub_80409A3C((u8 *)fns, 0x7C);
        if (r < 0) {
            return r;
        }
        if (first < 0) {
            first = r;
        }
        e->used = 1;
        e->id = r;
        e->dev = i;
        d++;
        i++;
        e++;
    }
    return first;
}

inline EthSocket *find_804089A8(EthSocket *ent, s16 n, s16 dev, u16 type) {
    for (; n > 0; n--, ent++) {
        if (ent->used != 0 && ent->dev == dev && ent->type == type) {
            return ent;
        }
    }
    return 0;
}
s32 TLobby__sub_804089A8(s16 dev, s16 mode, s16 b, void *pkt) {
    EthernetState *tbl = &lbl_805C1AD8;
    EthSocket *ent;
    EthSocket *base;
    EthFrameSlot *slot;
    s16 n;
    s16 link;
    s16 idx;
    u16 key;
    u8 buf[14];
    NetMemcpy(buf, pkt, 6);
    NetMemcpy(buf + 6, (u8 *)pkt + 6, 6);
    NetMemcpy(buf + 12, (u8 *)pkt + 0xc, 2);
    if (mode == 0) {
        if (b > 0x5ea) {
            return 0;
        }
        base = tbl->sockets;
        ent = find_804089A8(base, tbl->nsockets, dev, *(u16 *)(buf + 12));
        if (ent == 0) {
            return 0;
        }
        ent->slot = 0;
        idx = ent - base;
        link = ent->link;
        n = tbl->nslots;
        slot = tbl->slots;
        for (; n > 0; n--, slot++) {
            if (slot->used == 0) {
                slot->used = 1;
                slot->dev = dev;
                slot->socket = idx;
                slot->link = link;
                slot->len = b;
                goto foundslot;
            }
        }
        slot = 0;
    foundslot:
        if (slot == 0) {
            return 0;
        }
        ent->slot = slot;
        return (s32)slot->frame;
    }
    if (mode == 1) {
        key = *(u16 *)(buf + 12);
        base = tbl->sockets;
        ent = find_804089A8(base, tbl->nsockets, dev, key);
        if (ent == 0) {
            return 0;
        }
        slot = ent->slot;
        idx = ent - base;
        if (slot == 0) {
            return 0;
        }
        if (slot->dev != dev || slot->socket != idx || slot->link != ent->link || slot->len != b) {
            s32 lvl = OSDisableInterrupts();
            slot->used = 0;
            slot->dev = 0;
            slot->socket = 0;
            slot->link = 0;
            slot->len = 0;
            OSRestoreInterrupts(lvl);
            return 0;
        } else {
            TLobby__sub_80409818((s32)(slot->frame + 0xE), slot->len - 0xe, slot->link, slot->socket, key);
            return 0;
        }
    }
    return 0;
}

struct Hdr_80408C24 { u8 dst[6]; u8 src[6]; u16 type; };

u8 *TLobby__sub_8042558C(u32 size);

inline EthLink *find_conn_80408C24(EthernetState *g, s16 id) {
    EthLink *c = g->links;
    s16 n = g->nlinks;
    for (; n > 0; n--, c++) {
        if (c->used != 0 && c->id == id) {
            return c;
        }
    }
    return NULL;
}

s32 send_ethernet_frame(s16 idx, s16 mode, u8 *addr, void *pkt) {
    EthernetState *g;
    Hdr_80408C24 hdr;
    EthLink *c;
    EthSocket *e;
    s16 len;
    s32 (*fn)(s16, s32, s16);
    g = &lbl_805C1AD8;

    if (idx < 0 || idx >= g->nsockets) {
        return -0x111;
    }
    e = g->sockets;
    e += idx;
    if (e->used == 0) {
        return -2;
    }
    c = find_conn_80408C24(g, e->link);
    if (c == NULL) {
        return -2;
    }
    switch (mode) {
    case 0:
        NetMemcpy(hdr.dst, addr, 6);
        break;
    case 1:
        NetMemset(hdr.dst, 0xFF, 6);
        break;
    case 2:
        if (e->type == 0x800) {
            hdr.dst[0] = 1;
            hdr.dst[1] = 0;
            hdr.dst[2] = 5;
            hdr.dst[3] = addr[1] & 0x7F;
            hdr.dst[4] = addr[2];
            hdr.dst[5] = addr[3];
        } else if (e->type == 0x86DD) {
            hdr.dst[0] = 0x33;
            hdr.dst[1] = 0x33;
            hdr.dst[2] = addr[12];
            hdr.dst[3] = addr[13];
            hdr.dst[4] = addr[14];
            hdr.dst[5] = addr[15];
        } else {
            return -2;
        }
        break;
    default:
        return -2;
    }
    c->frame = TLobby__sub_8042558C(0x5EA);
    if (c->frame == NULL) {
        return 0;
    }
    NetMemcpy(hdr.src, c->mac, 6);
    hdr.type = e->type;
    NetMemcpy(c->frame, &hdr, 0xE);
    len = TLobby__sub_804098B4(pkt);
    if (len > 0x5DC) {
        clear_message_entry((s32)c->frame);
        return -2;
    }
    TLobby__sub_80409908(c->frame + 0xE, pkt);
    if (len + 0xE < 0x3C) {
        len = 0x2E;
    }
    fn = g->drivers[e->dev].send;
    if (fn != NULL) {
        fn(c->dev, (s32)c->frame, len + 0xE);
    } else {
        clear_message_entry((s32)c->frame);
        return -0x111;
    }
    return 0;
}

s32 forward_socket_op_by_handle(s16 id, u8 *a, u8 *b) {
    EthSocket *e;
    s32 sock;

    if (id < 0 || id >= lbl_805C1AD8.nsockets) {
        return -0x111;
    }
    e = lbl_805C1AD8.sockets;
    e += id;
    if (e->used == 0) {
        return -2;
    }
    switch (e->type) {
    case 0x800:
        sock = e->iface;
        if ((s16)sock >= 0) {
            return forward_net_op(sock, a, b);
        }
        return -2;
    default:
        return -2;
    }
}

s32 TLobby__sub_80408F2C(s16 id, u8 *pkt) {
    EthernetState *t = &lbl_805C1AD8;
    EthFrameSlot *b;
    u8 *data;
    s16 n;
    s16 i;

    if (id < 0 || id >= t->nsockets) {
        return -0x111;
    }
    b = t->slots;
    data = pkt - 0xE;
    n = t->nslots;
    i = 0;
    while (i < n) {
        if (b->frame == data) {
            s32 lvl = OSDisableInterrupts();
            b->used = 0;
            b->dev = 0;
            b->socket = 0;
            b->link = 0;
            b->len = 0;
            OSRestoreInterrupts(lvl);
            return 0;
        }
        i++;
        b++;
    }
    return -2;
}

s32 TLobby__sub_80408FD8(s16 idx, s16 mode, u8 *data) {
    EthernetState *tbl = &lbl_805C1AD8;
    EthSocket *e;
    EthDriver *fn;
    u8 buf[6];
    u16 flags;

    if (idx < 0 || idx >= tbl->nsockets) {
        return -0x111;
    }
    e = tbl->sockets;
    e += idx;
    if (e->used == 0) {
        return -2;
    }
    flags = e->type;
    if (flags == 0x800 || flags == 0x86dd) {
        fn = tbl->drivers;
        fn += e->dev;
        if (fn->add_multicast == NULL) {
            return -0x111;
        }
        if (flags == 0x800) {
            buf[0] = 1;
            buf[1] = 0;
            buf[2] = 5;
            buf[3] = data[1] & 0x7F;
            buf[4] = data[2];
            buf[5] = data[3];
        } else {
            buf[0] = 0x33;
            buf[1] = 0x33;
            buf[2] = data[0xC];
            buf[3] = data[0xD];
            buf[4] = data[0xE];
            buf[5] = data[0xF];
        }
        if (mode == 1) {
            return fn->add_multicast(e->dev, buf);
        }
        if (mode == 2) {
            return fn->remove_multicast(e->dev, buf);
        }
        return -2;
    }
    return -2;
}


s32 TLobby__sub_80409130(s16 arg0, s16 arg1, s32 arg2) {
    s32 h;
    EthSocket *e;

    if (arg0 < 0 || arg0 >= lbl_805C1AD8.nsockets) {
        return -0x111;
    }
    e = lbl_805C1AD8.sockets;
    e += arg0;
    if (e->used == 0) {
        return -2;
    }
    switch (e->type) {
    case 0x800:
        h = e->iface;
        if ((s16)h < 0) {
            return -2;
        }
        if (arg1 == 1) {
            return dispatch_slot_b(h, arg2);
        }
        if (arg1 == 2) {
            return dispatch_slot_a(h, arg2);
        }
        return -2;
    default:
        return -2;
    case 0x86DD:
        return 0;
    }
}

inline EthLink *find_8040920C(EthernetState *t, s16 id) {
    EthLink *p;
    s16 n;
    p = t->links;
    for (n = t->nlinks; n > 0; n--, p++) {
        if (p->used != 0 && p->id == id) {
            return p;
        }
    }
    return NULL;
}

s32 TLobby__sub_8040920C(s16 id, u8 *dst) {
    EthernetState *t = &lbl_805C1AD8;
    EthLink *p;
    EthSocket *e;
    EthDriver *r;

    if (id < 0 || id >= t->nsockets) {
        return -0x111;
    }
    e = t->sockets;
    e += id;
    if (e->used == 0) {
        return -2;
    }
    p = find_8040920C(t, e->link);
    if (p == NULL) {
        return -2;
    }
    r = t->drivers;
    r += e->dev;
    if (r->get_address != NULL) {
        NetMemcpy(dst, p->mac, 6);
    } else {
        return -0x111;
    }
    return 0;
}
s32 TLobby__sub_804092FC(s16 idx) {
    EthernetState *tbl = &lbl_805C1AD8;
    EthSocket *e;
    EthLink *p;
    s16 n;
    s16 id;
    if (idx < 0 || idx >= tbl->nsockets) {
        return -0x111;
    }
    e = tbl->sockets;
    e += idx;
    if (e->used == 0) {
        return -2;
    }
    id = e->link;
    p = tbl->links;
    for (n = tbl->nlinks; n > 0; n--, p++) {
        if (p->used == 0) {
            continue;
        }
        if (p->id != id) {
            continue;
        }
        (void)p;
        goto found;
    }
    p = NULL;
found:
    if (p == NULL) {
        return -2;
    }
    return 6;
}

s32 TLobby__sub_8040939C(idx)
    s16 idx;
{
    EthSocket *e;
    if (idx < 0 || idx >= lbl_805C1AD8.nsockets) {
        return -0x111;
    }
    e = lbl_805C1AD8.sockets;
    e += idx;
    if (e->used == 0) {
        return -2;
    }
    return 0x5dc;
}

s32 TLobby__sub_804093EC(s16 idx) {
    EthernetState *tbl = &lbl_805C1AD8;
    EthSocket *e;
    EthDriver *ent;
    s32 (*cb)(s16, u16);
    s32 v;

    if (idx < 0 || idx >= tbl->nsockets) {
        return -0x111;
    }
    e = tbl->sockets;
    e += idx;
    if (e->used == 0) {
        return -2;
    }
    v = e->iface;
    if ((s16)v >= 0) {
        TLobby__sub_80407418((s16)v);
    }
    ent = tbl->drivers;
    ent += e->dev;
    if ((cb = ent->close) != NULL) {
        cb(e->dev, e->type);
    }
    e->used = 0;
    e->link = 0;
    e->dev = 0;
    e->type = 0;
    e->iface = 0;
    e->slot = 0;
    return 0;
}

inline EthLink *find1_804094B8(EthernetState *g, s16 a) {
    EthLink *p = g->links;
    s16 n = g->nlinks;
    for (; n > 0; n--, p++) {
        if (p->used != 0 && p->id == a) {
            return p;
        }
    }
    return 0;
}
inline EthSocket *find2_804094B8(EthSocket *p, s16 n, s16 dev, u16 b) {
    for (; n > 0; n--, p++) {
        if (p->used != 0 && p->dev == dev && p->type == b) {
            return p;
        }
    }
    return 0;
}

#pragma push
#pragma opt_propagation off
extern s16 TLobby__sub_804094B8(s16 a, u16 b, s16 c, void *k)
{
  EthernetState *g = &lbl_805C1AD8;
  EthLink *p1;
  EthSocket *p3;
  s16 new_var;
  s16 n;
  EthSocket **pl;
  s16 idx;
  s16 ret;
  s16 err;
  EthDriver *cb;
  s16 forward_net_op_5args(s16, s16, s16, u16, s16, s32, s16, s32); /* declared s16 here; the definition is void (s16, s16, s16, s16, s16, s32, s8, s32) */
  p1 = find1_804094B8(g, a);
  if (p1 == ((void *) 0))
  {
    return -0x111;
  }
  if (((b != 0x800) && (b != 0x86dd)) && (b != 0x806))
  {
    return -2;
  }
  pl = &g->sockets;
  n = g->nsockets;
  p3 = *pl;
  if (find2_804094B8(p3, n, p1->dev, b) != ((void *) 0))
  {
    return -2;
  }
  for (; n > 0; n--, p3++)
  {
    if (p3->used == 0)
    {
      if (cb->open)
      {
        goto found;
      }
      else
      {
        goto found;
      }
    }
  }

  p3 = (void *) 0;
  found:
  if (p3 == ((void *) 0))
  {
    return -0x111;
  }

  p3->used = 1;
  p3->type = b;
  p3->link = a;
  p3->dev = p1->dev;
  idx = p3 - (*pl);
  cb = g->drivers;
  cb += p1->dev;
  if (cb->open != ((void *) 0))
  {
    new_var = idx;
    ret = cb->open(p1->dev, b);
    if (ret < 0)
    {
      err = ret;
      goto fail;
    }
    if (cb->get_address != ((void *) 0))
    {
      err = cb->get_address(p1->dev, p1->mac);
      if (err != 6)
      {
        goto fail;
      }
    }
    else
    {
      err = -0x111;
      goto fail;
    }
  }
  else
  {
    err = -0x111;
    goto fail;
  }
  switch (b)
  {
    case 0x800:
      ret = forward_net_op_5args(a, idx, 1, b, 6, (s32) p1->mac, c, (s32) k);
      if (ret < 0)
    {
      err = ret;
      goto fail;
    }
      p3->iface = ret;
      break;

    default:
      p3->iface = -1;
      break;

  }

  return new_var;
  fail:
  p3->used = 0;

  p3->type = 0;
  return err;
}
#pragma pop
inline EthLink *find_8040970C(s16 idx) {
    EthLink *p = lbl_805C1AD8.links;
    s16 n;

    for (n = lbl_805C1AD8.nlinks; n > 0; n--, p++) {
        if (p->used != 0 && p->id == idx) {
            return p;
        }
    }
    return NULL;
}

extern s32 TLobby__sub_8040970C(s16 idx, u8 *dst) {
    EthernetState *tbl;
    EthLink *p;
    u8 buf[6];
    s16 ret;
    s16 (*fn)(s16, void *);

    tbl = &lbl_805C1AD8;
    p = find_8040970C(idx);
    if (p == NULL) {
        return -0x111;
    }
    fn = tbl->drivers[p->dev].get_address;
    if (fn != NULL) {
        ret = fn(p->dev, buf);
        if (ret != 6) {
            return -0x111;
        }
    } else {
        return -0x111;
    }
    dst[0] = buf[0] | 2;
    dst[1] = buf[1];
    dst[2] = buf[2];
    dst[3] = 0xff;
    dst[4] = 0xfe;
    dst[5] = buf[3];
    dst[6] = buf[4];
    dst[7] = buf[5];
    return 0;
}

void TLobby__sub_80409818(s32 msg, s16 len, s16 idx, s16 arg3, u16 type) {
    void NetEnqueueProtocolMessage(s32 msg, s16 len, s16 idx, s16 arg3, u16 type);
    if (idx < 0 || idx >= lobby_handler_table_desc.count) {
        return;
    }
    switch (type) {
    default:
        ((void (*)(s16, s32))lobby_handler_table_desc.list[idx].op24)(arg3, msg);
        break;
    case 0x800:
    case 0x806:
    case 0x86DD:
        NetEnqueueProtocolMessage(msg, len, idx, arg3, type);
        break;
    }
}

inline s16 packet_length_804098B4(NetPacket *pkt) {
    NetPacketFragment *f;
    s16 n;
    s16 total = 0;
    n = pkt->fragment_count;
    f = &pkt->fragments[n] - 1;
    for (; n > 0; n--) {
        total += f->length;
        f--;
    }
    if (total != (s16)pkt->total_bytes) {
        return total;
    }
    return pkt->total_bytes;
}
s16 TLobby__sub_804098B4(void *pkt) {
    return packet_length_804098B4(pkt);
}

inline s32 calc_80409908(void *self, u8 *arr) {
    u8 tmp[0x10];
    u8 *p;
    s32 acc;
    s16 n;
    s32 sum;
    sum = 0;
    n = (s16)*(s32 *)(arr + 4);
    acc = (s32)self;
    p = arr + n * 12;
    while (n > 0) {
        set_value_and_enable(tmp, acc);
        TLobby__sub_80406FD8(tmp, arr + (n - 1) * 12 + 0x10, *(s16 *)p);
        acc += *(s16 *)p;
        sum += *(s16 *)p;
        p -= 12;
        n--;
    }
    if ((s16)sum != (s16)*(s32 *)(arr + 8)) return sum;
    return (s16)*(s32 *)(arr + 8);
}

s32 TLobby__sub_80409908(void *self, void *arr_) {
    return calc_80409908(self, arr_);
}
s32 clear_table_entry_locked(s16 arg0) {
    s32 ret;
    lock_mutex(network_dispatch_state.lock_handle);
    if (arg0 < 0 || arg0 > lobby_handler_table_desc.count) {
        ret = -0x10F;
    } else {
        LobbyHandler *e = lobby_handler_table_desc.list;
        e += arg0;
        NetMemset(e, 0, sizeof(LobbyHandler));
        ret = 0;
    }
    unlock_mutex(network_dispatch_state.lock_handle);
    return ret;
}

s16 TLobby__sub_80409A3C(u8 *arg0, s16 arg1) {
    s16 temp_r31;
    lock_mutex(network_dispatch_state.lock_handle);
    temp_r31 = TLobby__sub_8040A2BC((Fn_8040881C *)(arg0), arg1);
    unlock_mutex(network_dispatch_state.lock_handle);
    return temp_r31;
}

s32 TLobby__sub_80409AA8(void) {
    TLobby__sub_803F8A9C(&lobby_handler_table_desc);
    lobby_handler_table_desc.count = 0;
    return 0;
}


s32 TLobby__sub_80409AD8(void) {
    s16 i;
    u8 *p;
    TLobby__sub_803F8AA0((u8 *)&lobby_handler_table_desc);
    p = (u8 *)lobby_handler_table_desc.list;
    i = 0;
    while (i < lobby_handler_table_desc.count) {
        NetMemset(p, 0, 0x30);
        i++;
        p += 0x30;
    }
    return 0;
}

s32 call_handler_by_index(s16 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    LobbyHandler *e;
    s32 (*fn)(s32, s32, s32, s32);
    if (arg0 < 0 || arg0 > lobby_handler_table_desc.count) {
        return -0x10F;
    }
    e = lobby_handler_table_desc.list;
    e += arg0;
    if (e->active == 0) {
        return -2;
    }
    fn = e->output;
    if (fn == NULL) {
        return -2;
    }
    return fn(arg1, arg2, arg3, arg4);
}

s32 dispatch_handler_by_index(s16 arg0, s32 arg1, s32 arg2, s32 arg3) {
    LobbyHandler *e;
    s32 (*fn)(s32, s32, s32);
    if (arg0 < 0 || arg0 > lobby_handler_table_desc.count) {
        return -0x10F;
    }
    e = lobby_handler_table_desc.list;
    e += arg0;
    if (e->active == 0) {
        return -2;
    }
    fn = e->op28;
    if (fn == NULL) {
        return -2;
    }
    return fn(arg1, arg2, arg3);
}


s32 dispatch_handler_by_id(s16 arg0, s32 arg1, s32 arg2) {
    LobbyHandler *e;
    s32 (*fn)(s32, s32);

    if (arg0 < 0 || arg0 > lobby_handler_table_desc.count) {
        return -0x10F;
    }
    e = lobby_handler_table_desc.list;
    e += arg0;
    if (e->active == 0) {
        return -2;
    }
    fn = e->op24;
    if (fn == NULL) {
        return -2;
    }
    return fn(arg1, arg2);
}


s32 TLobby__sub_80409CE0(s16 arg0, s32 arg1, s32 arg2, s32 arg3) {
    LobbyHandler *e;
    s32 (*fn)(s32, s32, s32);

    if (arg0 < 0 || arg0 > lobby_handler_table_desc.count) {
        return -0x10F;
    }
    e = lobby_handler_table_desc.list;
    e += arg0;
    if (e->active == 0) {
        return -2;
    }
    if (!(e->flags & 4)) {
        return 0;
    }
    fn = e->op20;
    if (fn == NULL) {
        return -2;
    }
    return fn(arg1, arg2, arg3);
}


s32 TLobby__sub_80409D7C(s16 arg0, s32 arg1, s32 arg2, s32 arg3) {
    LobbyHandler *e;
    s32 (*fn)(s32, s32, s32);

    if (arg0 < 0 || arg0 > lobby_handler_table_desc.count) {
        return -0x10F;
    }
    e = lobby_handler_table_desc.list;
    e += arg0;
    if (e->active == 0) {
        return -2;
    }
    if (!(e->flags & 4)) {
        return 0;
    }
    fn = e->op1C;
    if (fn == NULL) {
        return -2;
    }
    return fn(arg1, arg2, arg3);
}


s32 TLobby__sub_80409E18(s16 arg0, s32 arg1, s32 arg2) {
    LobbyHandler *e;
    s32 (*fn)(s32, s32);

    if (arg0 < 0 || arg0 > lobby_handler_table_desc.count) {
        return -0x10F;
    }
    e = lobby_handler_table_desc.list;
    e += arg0;
    if (e->active == 0) {
        return -2;
    }
    if (!(e->flags & 4)) {
        return 0;
    }
    fn = e->op18;
    if (fn == NULL) {
        return -2;
    }
    return fn(arg1, arg2);
}


s32 TLobby__sub_80409EB0(s16 arg0, s32 arg1) {
    LobbyHandler *e;
    s32 (*fn)(s32);

    if (arg0 < 0 || arg0 > lobby_handler_table_desc.count) {
        return -0x10F;
    }
    e = lobby_handler_table_desc.list;
    e += arg0;
    if (e->active == 0) {
        return -2;
    }
    if (!(e->flags & 4)) {
        return 0;
    }
    fn = e->op14;
    if (fn == NULL) {
        return -2;
    }
    return fn(arg1);
}


#pragma push
#pragma opt_propagation off
s32 invoke_socket_callback(s16 i, s32 arg) {
    LobbyHandler *e;
    if (i < 0 || i > lobby_handler_table_desc.count) {
        return -0x10F;
    }
    e = lobby_handler_table_desc.list + i;
    if (e->active == 0) {
        return -2;
    }
    if (e->op10 == 0) {
        return -2;
    }
    return e->op10(arg);
}
#pragma pop

#pragma push
#pragma opt_propagation off
s32 call_entry_callback(s16 i, s32 arg) {
    LobbyHandler *e;
    if (i < 0 || i > lobby_handler_table_desc.count) {
        return -0x10F;
    }
    e = lobby_handler_table_desc.list + i;
    if (e->active == 0) {
        return -2;
    }
    if (e->op0C == 0) {
        return -2;
    }
    return e->op0C(arg);
}
#pragma pop

s32 TLobby__sub_8040A044(s16 idx, u32 a, s32 b, u32 *c) {
    LobbyHandler *e;
    if (idx < 0 || idx > lobby_handler_table_desc.count) {
        return -0x10F;
    }
    e = lobby_handler_table_desc.list;
    e += idx;
    if (e->active == 0) {
        return -2;
    }
    if (e->op08 == 0) {
        return -2;
    }
    return e->op08(idx, a, b, c);
}

s32 TLobby__sub_8040A0C0(s16 idx, void *a)
{
    LobbyHandler *e;

    if (idx < 0 || idx > lobby_handler_table_desc.count) {
        return -0x10f;
    }
    e = lobby_handler_table_desc.list;
    e += idx;
    if (e->active == 0) {
        return -2;
    }
    if (e->get_interface_id == NULL) {
        return -2;
    }
    return e->get_interface_id(idx, a);
}

#pragma push
#pragma optimization_level 2
s32 is_slot_flag_0x40_set(s16 i) {
    LobbyHandler *e;
    if (i < 0 || i > lobby_handler_table_desc.count) { return 0; }
    e = lobby_handler_table_desc.list;
    if (e[i].active == 0) { return 0; }
    if (e[i].flags & 0x40) { return 1; }
    return 0;
}
#pragma pop

#pragma push
#pragma optimization_level 2
s32 is_slot_flag_0x20_set(s16 i) {
    LobbyHandler *e;
    if (i < 0 || i > lobby_handler_table_desc.count) { return 0; }
    e = lobby_handler_table_desc.list;
    if (e[i].active == 0) { return 0; }
    if (e[i].flags & 0x20) { return 1; }
    return 0;
}
#pragma pop

#pragma push
#pragma optimization_level 2
s32 is_entry_flag10_set(s16 i) {
    LobbyHandler *e;
    if (i < 0 || i > lobby_handler_table_desc.count) { return 0; }
    e = lobby_handler_table_desc.list;
    if (e[i].active == 0) { return 0; }
    if (e[i].flags & 0x10) { return 1; }
    return 0;
}
#pragma pop

#pragma push
#pragma optimization_level 2
s32 is_socket_flag_set(s16 i) {
    LobbyHandler *e;
    if (i < 0 || i > lobby_handler_table_desc.count) { return 0; }
    e = lobby_handler_table_desc.list;
    if (e[i].active == 0) { return 0; }
    if (e[i].flags & 1) { return 1; }
    return 0;
}
#pragma pop

extern s16 TLobby__sub_8040A2BC(Fn_8040881C *fns, s16 kind) {
    LobbyHandler *e;
    s16 i;

    if (fns == NULL || fns[1] == NULL) {
        return -2;
    }
    switch (kind) {
    case 1:
        e = lobby_handler_table_desc.list;
        if (e->active == 0) {
            NetMemcpy(&e->get_interface_id, fns, 11 * sizeof(Fn_8040881C));
            e->flags = kind;
            e->active = 1;
            return 0;
        }
        return -2;
    default:
        for (i = 1, e = lobby_handler_table_desc.list + 1; i < lobby_handler_table_desc.count; i++, e++) {
            if (e->active == 0) {
                NetMemcpy(&e->get_interface_id, fns, 11 * sizeof(Fn_8040881C));
                e->flags = kind;
                e->active = 1;
                return i;
            }
        }
        return -0x10F;
    }
}

s32 TLobby__sub_8040A3C0(void) {
    s32 ret;
    s16 i;
    DnsResolverState *m = (DnsResolverState *)&dns_resolver_state;
    DnsQuery *e;

    ret = TLobby__sub_80421844((s32)((void *)tick_connection_timeouts));
    e = m->queries;
    i = 0;
    while (i < m->nqueries) {
        if (e->active != 0) {
            close_and_reset_connection((void *)e);
        }
        i++;
        e++;
    }
    TLobby__sub_803F86BC(m);
    return ret;
}

s16 TLobby__sub_804218AC(void (*)(void), int);

s16 init_net_tables(void) {
    DnsResolverState *g = &dns_resolver_state;
    s16 i;

    NetMemset(g, 0, sizeof(DnsResolverState));
    init_net_config(g);
    {
        DnsBuffer *p = g->buffers;
        i = 0;
        while (i < g->nbuffers) {
            p->used = 0;
            p->data = g->buffer_base + g->buffer_size * i;
            i++;
            p++;
        }
    }
    {
        NetworkAddress *p = g->servers;
        i = 0;
        while (i < g->nservers) {
            p->family = 0;
            i++;
            p++;
        }
    }
    {
        DnsAddr *p = g->addrs;
        i = 0;
        while (i < g->naddrs) {
            p->used = 0;
            i++;
            p->next = 0;
            p++;
        }
    }
    {
        DnsHost *p = g->hosts;
        i = 0;
        while (i < g->nhosts) {
            p->state = 0;
            i++;
            p->cname[0] = 0;
            p->naddrs = 0;
            p->addrs = 0;
            p++;
        }
    }
    {
        DnsPtr *p = g->ptrs;
        i = 0;
        while (i < g->nptrs) {
            p->state = 0;
            i++;
            p->ttl = 0;
            p->name[0] = 0;
            p++;
        }
    }
    {
        DnsQuery *p = g->queries;
        i = 0;
        while (i < g->nqueries) {
            p->index = i;
            i++;
            p->active = 0;
            p->socket = -1;
            p->id = 0;
            p->waiter = -1;
            p->status = -65;
            p->outstanding = 0;
            p->msg = 0;
            p->reply = 0;
            p->req.lookup.cb = 0;
            p->req.ptr.cb = 0;
            p++;
        }
    }
    return TLobby__sub_804218AC(tick_connection_timeouts, 1000);
}

#pragma push
#pragma opt_propagation off
s32 close_connection_by_index(s16 i) {
    DnsResolverState *g = (DnsResolverState *)&dns_resolver_state;
    DnsQuery *e;
    if (i < 0 || i > g->nqueries) { return -2; }
    e = (DnsQuery *)((u8 *)g->queries + i * 0x3C);
    if (e->active == 0) { return -2; }
    return close_and_reset_connection((void *)e);
}
#pragma pop

extern void TLobby__sub_8040C74C(DnsLookupRequest *p);
#pragma push
#pragma opt_propagation off
extern s16 TLobby__sub_8040A698(s16 idx, void *buf, s16 *len, void *buf2, s16 *len2, u32 mode) {
    DnsResolverState *g = &dns_resolver_state;
    DnsQuery *f;
    DnsQuery *e;
    DnsLookupRequest *req;
    s16 st;

    if (idx < 0 || idx >= g->nqueries) {
        return -2;
    }
    f = &g->queries[idx];
    e = (DnsQuery *)f;
    if (f->active == 0) {
        return -2;
    }
    if (e->kind != 1) {
        return -2;
    }
    if (len == NULL) {
        return -2;
    }
    if (buf != NULL && *len <= 0) {
        return -2;
    }
    if (buf2 != NULL && (len2 == NULL || *len2 < 0)) {
        return -2;
    }
    req = &e->req.lookup;
    req->addrs = buf;
    req->naddrs = *len;
    req->cname = buf2;
    if (len2 != NULL) {
        req->cname_len = *len2;
    } else {
        req->cname_len = 0;
    }
    req->cb = (DnsLookupCallback)mode;
    if (mode == 0) {
        TLobby__sub_80421814();
        if (e->status > 0 || e->outstanding > 0) {
            if (e->waiter != 0xFFFFFFFF) {
                TLobby__sub_804217E4();
                return -2;
            }
            NetStoreCurrentThread((s32 *)&e->waiter);
            TLobby__sub_804217E4();
            NetSuspendCurrentThread();
        } else {
            TLobby__sub_804217E4();
        }
        st = e->status;
        if (st < 0) {
            return st;
        }
    } else if (mode == 0xFFFFFFFF) {
        st = e->status;
        if (st > 0 || e->outstanding > 0) {
            return -1;
        }
        if (st < 0) {
            return st;
        }
    } else {
        if (e->status <= 0 && e->outstanding <= 0) {
            dispatch_request_callback((void *)e, 1);
        }
        return -1;
    }
    TLobby__sub_8040C74C(req);
    if (len2 != NULL) {
        *len2 = req->cname_len;
    }
    *len = req->naddrs;
    return 0;
}
#pragma pop

s16 TUdpSocket__sub_80421DEC(s16 a, void* b, void* c, u16 d, void* e, void* f);
s32 TLobby__sub_8040B4BC(s16 mode, UdpDatagram *req);
DnsHost *TLobby__sub_8040C09C(void);
static inline DnsHost *find_host_8040A8B0(DnsResolverState *base, u8 *self, s32 len) {
    DnsHost *p = base->hosts;
    s16 j;
    for (j = 0; j < base->nhosts; j++, p++) {
        if (p->state == 1 && NetMemcmp(p->name, self, len) == 0) {
            return p;
        }
    }
    return NULL;
}
static inline DnsBuffer *grab_slot_8040A8B0(DnsResolverState *base) {
    DnsBuffer *p = base->buffers;
    s16 i;
    for (i = 0; i < base->nbuffers; i++, p++) {
        if (p->used == 0) {
            p->used = 1;
            return p;
        }
    }
    return NULL;
}
static inline NetworkAddress *probe_8040A8B0(DnsResolverState *b, DnsQuery *e) {
    s16 i;
    NetworkAddress *ent;
    s16 n;
    for (i = 0; i < (n = b->nservers); i++) {
        ent = &b->servers[(e->server + e->status) % n];
        if (ent->family != 0) {
            if (e->status < b->max_tries) {
                return ent;
            }
            break;
        }
        e->status = e->status + 1;
    }
    return NULL;
}
#pragma push
#pragma opt_propagation off
#pragma opt_common_subs off
s32 TLobby__sub_8040A8B0(u8 *self, s16 idx, s32 type)
{
  s16 TUdpSocket__sub_80421BAC(s32, void *, void *, u16, void *, s8, send_buffs *); /* declared here with other parameter types; the definition is s16 (s32, u32 *, u32 *, u16, u32 *, s8, send_buffs *) */
  DnsResolverState *base = &dns_resolver_state;
  DnsLookupRequest *t;
  u32 ty;
  DnsHost *p;
  DnsBuffer *m;
  DnsQuery *e;
  s16 i;
  s16 j;
  if (self == ((void *) 0))
  {
    return -2;
  }
  if ((idx <= 0) || (idx > base->max_name))
  {
    return -2;
  }
  switch (type)
  {
    case 0:

    case 4:

    case 6:
      break;

    default:
      return -2;

  }

  if (((s32) self[idx - 1]) == '.')
  {
    idx--;
  }
  TLobby__sub_80421814();
  e = base->queries;
  for (i = 0; i < base->nqueries; i++, e++)
  {
    if (e->active == 0)
    {
      e->active = 1;
      break;
    }
  }

  TLobby__sub_804217E4();
  if (i == base->nqueries)
  {
    e = (void *) 0;
  }
  if (e == ((void *) 0))
  {
    return -0x40;
  }
  e->kind = 1;
  {
    long long len = idx;
    e->req.lookup.family = type;
    t = &e->req.lookup;
    p = find_host_8040A8B0(base, self, len);
    if (p != ((void *) 0))
    {
      e->status = 0;
      t->host = p;
      ty = t->family;
      if (ty == 0)
      {
        if (p->naddrs > 0)
        {
          return e->index;
        }
      }
      else
      {
        DnsAddr *node;
        for (node = p->addrs; node != ((void *) 0); node = node->next)
        {
          if (node->addr.family == ty)
          {
            return e->index;
          }
        }

      }
    }
    m = grab_slot_8040A8B0(base);
    e->msg = m;
    if (m == ((void *) 0))
    {
      close_and_reset_connection(e);
      return -0x43;
    }
    e->id = base->next_id++;
    e->timer = base->timeouts[0];
    e->server = base->server;
    e->status = 0;
    base = (DnsResolverState *) probe_8040A8B0(base, e);
    if (base == ((void *) 0))
    {
      close_and_reset_connection(e);
      return -0x44;
    }
    e->socket = TUdpSocket__sub_80421DEC(0, 0, 0, 0x35, complete_pending_request, TLobby__sub_8040B4BC);
    i = e->socket;
    if (i < 0)
    {
      close_and_reset_connection(e);
      return i;
    }
    if (t->host == ((void *) 0))
    {
      p = TLobby__sub_8040C09C();
      p->name_len = idx;
      NetMemcpy(p->name, self, len);
      t->host = p;
    }
    switch (t->family)
    {
      case 0:
      {
        send_buffs buf;
        build_dns_query_aaaa(e, self, idx);
        buf.len = e->msg->len;
        buf.buff = e->msg->data;
        i = TUdpSocket__sub_80421BAC(e->socket, (void *) 0, base, 0, (void *) 0, 1, &buf);
        if (i < 0)
        {
          e->timer = 1;
          e->status = e->status + 1;
        }
        else
        {
          e->timer = 2;
          e->outstanding = 1;
        }
        break;
      }

      case 4:
      {
        send_buffs buf;
        build_dns_query_a(e, self, idx);
        buf.len = e->msg->len;
        buf.buff = e->msg->data;
        i = TUdpSocket__sub_80421BAC(e->socket, (void *) 0, base, 0, (void *) 0, 1, &buf);
        if (i < 0)
        {
          e->timer = 1;
          e->status = e->status + 1;
        }
        break;
      }

      case 6:
      {
        send_buffs buf;
        build_dns_query_aaaa(e, self, idx);
        buf.len = e->msg->len;
        buf.buff = e->msg->data;
        i = TUdpSocket__sub_80421BAC(e->socket, (void *) 0, base, 0, (void *) 0, 1, &buf);
        if (i < 0)
        {
          e->timer = 1;
          e->status = e->status + 1;
        }
        break;
      }

    }

    {
      u32 pad[4];
    }
  }
  return e->index;
}
#pragma pop


s32 clear_all_used_records(void) {
    DnsResolverState *g = (DnsResolverState *)&dns_resolver_state;
    s32 cnt;
    s16 i;
    NetworkAddress *r;

    TLobby__sub_80421814();
    g->server = 0;
    cnt = 0;
    i = 0;
    r = g->servers;
    while (i < g->nservers) {
        if (r->family != 0) {
            r->family = 0;
            cnt++;
        }
        i++;
        r++;
    }
    TLobby__sub_804217E4();
    return cnt;
}

inline s32 cmpfam_8040ADE8(u32 family, u8 *a, u8 *b) {
    switch (family) {
    case 4:
        if (*(u32 *)b != 4) {
            return -1;
        }
        return NetMemcmp(a + 4, b + 4, 4);
    case 6:
        if (*(u32 *)b != 6) {
            return -1;
        }
        return NetMemcmp(a + 4, b + 4, 0x10);
    default:
    case 0:
        return -1;
    }
}
extern s16 TLobby__sub_8040ADE8(u8 *self) {
    u8 *g;
    s16 ret;
    s16 i;
    u8 *p;
    u8 *slot;
    u32 family;

    switch (*(u32 *)self) {
    case 4:
    case 6:
        break;
    default:
    case 0:
        return -2;
    }
    TLobby__sub_80421814();
    g = (u8 *)&dns_resolver_state;
    p = *(u8 **)(g + 0x14);
    slot = NULL;
    for (i = 0; i < *(s16 *)(g + 0x10); i++, p += 0x14) {
        if (*(u32 *)p == 0) {
            if (slot == NULL) {
                ret = i;
                slot = p;
            }
            continue;
        }
        family = *(u32 *)self;
        if (family != *(u32 *)p) {
            continue;
        }
        if (cmpfam_8040ADE8(family, self, p) == 0) {
            ret = -2;
            slot = NULL;
            break;
        }
    }
    if (slot != NULL) {
        NetMemcpy(slot, self, 0x14);
    } else {
        ret = -2;
    }
    TLobby__sub_804217E4();
    return ret;
}


extern void TLobby__sub_8040C178(DnsHost *self, s32 x);
void TLobby__sub_8040AFE0(void);
void TLobby__sub_8040B3B4(void);

void tick_connection_timeouts(void) {
    DnsResolverState *g;
    DnsPtr *c;
    s16 i;

    TLobby__sub_8040B3B4();
    g = (DnsResolverState *)&dns_resolver_state;
    c = g->ptrs;
    i = 0;
    while (i < g->nptrs) {
        if (c->state == 1 && c->ttl > 0) {
            if (--c->ttl <= 0) {
                reset_connection_requests(c, 0);
            }
        }
        i++;
        c++;
    }
    TLobby__sub_8040AFE0();
}

extern void TLobby__sub_8040AFE0(void)
{
    s16 TUdpSocket__sub_80421BAC(s32, s32, s32, u16, s32, s8, void *); /* declared here with other parameter types; the definition is s16 (s32, u32 *, u32 *, u16, u32 *, s8, send_buffs *) */
    DnsResolverState *base = (DnsResolverState *)&dns_resolver_state;
    s32 found;
    s16 *dp;
    s16 cnt;
    DnsQuery *e;
    s16 buf[8];
    send_buffs tmp;
    s16 val;
    s16 ret;
    s32 f2;
    s32 f3;

    dp = &base->nservers;
    for (cnt = 0, e = base->queries; cnt < base->nqueries; cnt++, e++) {
        if (e->active != 1) continue;
        if (e->socket < 0) continue;
        if (!(e->status > 0 || e->outstanding > 0)) continue;
        if (--e->timer > 0) continue;
        if (e->status >= base->max_tries) {
            base->server = 0;
            TLobby__sub_8040BE40(e, -0x45, 0);
            continue;
        }
        if (e->outstanding != 0) {
            found = (s32)find_next_active_record((DnsQuery *)e);
            if (found == 0) {
                TLobby__sub_8040BE40(e, -0x44, 0);
                continue;
            }
            base->server = e->status % *dp;
            e->timer = base->timeouts[e->status / *dp];
            buf[0] = 1;
            NetMemcpy((u8 *)e->msg->data + e->msg->len - 4, &buf[0], 2);
            f2 = found;
            tmp.len = e->msg->len;
            tmp.buff = e->msg->data;
            ret = TUdpSocket__sub_80421BAC(e->socket, 0, f2, 0, 0, 1, &tmp);
            val = 0x1c;
            NetMemcpy((u8 *)e->msg->data + e->msg->len - 4, &val, 2);
            if (ret < 0) {
                e->timer = 1;
            }
            e->outstanding = 0;
            e->status = e->status + 1;
        } else {
            TLobby__sub_8040B1C4(e);
        }
    }
}

inline NetworkAddress *fnar_8040B1C4(DnsResolverState *g, DnsQuery *a) {
    s16 t, n, i;
    for (i = 0; i < (n = g->nservers); i++) {
        NetworkAddress *r = &g->servers[(a->server + (t = a->status)) % n];
        if (r->family != 0) {
            if (t < g->max_tries) {
                return r;
            }
            break;
        }
        a->status = t + 1;
    }
    return 0;
}

extern void TLobby__sub_8040B1C4(void *arg)
{
    s16 TUdpSocket__sub_80421BAC(s32, s32, s32, u16, s32, s8, void *); /* declared here with other parameter types; the definition is s16 (s32, u32 *, u32 *, u16, u32 *, s8, send_buffs *) */
    DnsQuery *e = (DnsQuery *)arg;
    DnsResolverState *base;
    NetworkAddress *found;
    u8 y[4];
    send_buffs tmp;
    u8 x[4];
    s16 ret;
    s16 *dp;

    base = (DnsResolverState *)&dns_resolver_state;
    if ((found = fnar_8040B1C4((DnsResolverState *)base, (DnsQuery *)e)) == NULL) {
        TLobby__sub_8040BE40(e, -0x44, 0);
        return;
    }
    dp = &base->nservers;
    base->server = e->status % *dp;
    e->timer = base->timeouts[e->status / *dp];
    tmp.len = e->msg->len;
    tmp.buff = e->msg->data;
    ret = TUdpSocket__sub_80421BAC(e->socket, 0, (s32)found, 0, 0, 1, &tmp);
    if (ret < 0) {
        e->timer = 1;
        e->status = e->status + 1;
        return;
    }
    if (*(s16 *)((u8 *)e + 8) == 1 && *(u32 *)((u8 *)e + 0x20) == 0) {
        e->timer = 2;
        e->outstanding = 1;
        return;
    }
    e->status = e->status + 1;
}

NetworkAddress *find_next_active_record(DnsQuery *a) {
    DnsResolverState *g = &dns_resolver_state;
    s16 n, t, i;
    for (i = 0; i < (n = g->nservers); i++) {
        NetworkAddress *r = &g->servers[(a->server + (t = a->status)) % n];
        if (r->family != 0) {
            if (t < g->max_tries) {
                return r;
            }
            break;
        }
        a->status = t + 1;
    }
    return 0;
}

extern void TLobby__sub_8040B3B4(void) {
    s16 i;
    s16 n;
    s16 count;
    DnsAddr *prev;
    DnsAddr *removed;
    DnsAddr *node;
    DnsResolverState *base;
    DnsHost *e;

    base = (DnsResolverState *)&dns_resolver_state;
    e = base->hosts;
    i = 0;
    while (i < base->nhosts) {
        if (e->state == 1 && (n = e->naddrs) != 0) {
            prev = NULL;
            node = e->addrs;
            count = 0;
            while (count < n && node != NULL) {
                if (--node->ttl > 0) {
                    prev = node;
                    node = node->next;
                } else {
                    removed = node;
                    node = node->next;
                    if (prev != NULL) {
                        prev->next = node;
                    } else {
                        e->addrs = node;
                    }
                    e->naddrs--;
                    removed->used = 0;
                    removed->next = NULL;
                }
                count++;
            }
            if (e->naddrs <= 0) {
                TLobby__sub_8040C178(e, 0);
            }
        }
        i++;
        e++;
    }
}

extern s32 TLobby__sub_8040B8BC(DnsQuery *self);
inline DnsQuery *find_8040B4BC(DnsResolverState *base, UdpDatagram *req) {
    s16 count;
    s16 key;
    s16 i;
    DnsQuery *e;
    i = 0;
    key = req->socket;
    e = base->queries;
    count = base->nqueries;
    while (i < count) {
        if (e->active == 1 && key == e->socket) {
            return e;
        }
        i++;
        e++;
    }
    return NULL;
}
inline DnsBuffer *slot_8040B4BC(DnsResolverState *base) {
    s16 i;
    s16 count;
    DnsBuffer *s;
    i = 0;
    s = base->buffers;
    count = base->nbuffers;
    for (; i < count; i++, s++) {
        if (s->used == 0) {
            s->used = 1;
            return s;
        }
    }
    return NULL;
}

s32 TLobby__sub_8040B4BC(s16 mode, UdpDatagram *req)
{
  DnsResolverState *base = &dns_resolver_state;
  DnsQuery *e;
  s16 new_var;
  DnsBuffer *s;
  s32 pad[2];
  s16 TLobby__sub_8040B8BC(DnsQuery *); /* declared s16 here; the definition returns s32 */
  if (req->port != 0x35)
  {
    return 1;
  }
  e = find_8040B4BC(base, req);
  if (e == ((void *) 0))
  {
    return 1;
  }
  if (e->status < 0)
  {
    return 1;
  }
  new_var = req->len;
  if (new_var > base->buffer_size)
  {
    return 1;
  }
  switch (mode)
  {
    case 0:
      s = slot_8040B4BC(base);
      e->reply = s;
      if (s == ((void *) 0))
    {
      return 1;
    }
      req->buf = e->reply->data;
      return 0;

  }

  e->reply->len = new_var;
  if (TLobby__sub_8040B8BC(e) < 0)
  {
    e->reply->used = 0;
    e->reply = (void *) 0;
    return 1;
  }
  e->reply->used = 0;
  e->reply = (void *) 0;
  if (e->outstanding == 0)
  {
    e->status = 0;
    dispatch_request_callback((void *) e, 0);
  }
  return 0;
}


inline DnsQuery *find_8040B654(s16 id) {
    DnsResolverState *g = (DnsResolverState *)&dns_resolver_state;
    s16 n;
    DnsQuery *e;
    s16 i;

    e = g->queries;
    n = g->nqueries;
    for (i = 0; i < n; i++, e++) {
        if (e->active == 1 && id == e->socket) {
            return e;
        }
    }
    return NULL;
}

void complete_pending_request(s16 id) {
    DnsQuery *e;

    if ((e = find_8040B654(id)) != NULL) {
        e->timer = 1;
        if (e->status < 0) {
            dispatch_request_callback((void *)e, 0);
        }
    }
}

#pragma push
#pragma opt_propagation off
s32 build_dns_query_aaaa(void *self, u8 *name, s16 len) {
    s32 TLobby__sub_8040B838(u8 *dst, u8 *src, s16 len);
    Q_8040B6E4 *q = (Q_8040B6E4 *)self;
    Hdr_8040B6E4 *h;
    u8 *body;
    s32 n;
    s16 total;
    QT_8040B6E4 qt;
    h = q->pkt->hdr;
    h->id = q->id;
    body = h->body;
    h->f2 = 1;
    h->f3 = 0;
    h->qd = 1;
    h->an = 0;
    h->ns = 0;
    h->ar = 0;
    n = TLobby__sub_8040B838(body, name, len);
    qt.type = 0x1C;
    body += (s16)n;
    qt.cls = 1;
    total = n + 0xC;
    NetMemcpy(body, &qt, 4);
    q->pkt->len = total + 4;
    return 0;
}
#pragma pop

#pragma push
#pragma opt_propagation off
s32 build_dns_query_a(void *self, u8 *name, s16 len) {
    s32 TLobby__sub_8040B838(u8 *dst, u8 *src, s16 len);
    Q_8040B790 *q = (Q_8040B790 *)self;
    Hdr_8040B790 *h;
    u8 *body;
    s32 n;
    s16 total;
    QT_8040B790 qt;
    h = q->pkt->hdr;
    h->id = q->id;
    body = h->body;
    h->f2 = 1;
    h->f3 = 0;
    h->qd = 1;
    h->an = 0;
    h->ns = 0;
    h->ar = 0;
    n = TLobby__sub_8040B838(body, name, len);
    qt.type = 1;
    body += (s16)n;
    qt.cls = 1;
    total = n + 0xC;
    NetMemcpy(body, &qt, 4);
    q->pkt->len = total + 4;
    return 0;
}
#pragma pop

s32 TLobby__sub_8040B838(u8 *dst, u8 *src, s32 max)
{
    s8 c;
    s16 i;
    u8 n;
    u8 *len;
    s32 ret;
    len = dst;
    n = 0;
    i = 0;
    dst++;
    while (i < (s16)max) {
        c = *src;
        if (c == '.') {
            *len = n;
            len = dst;
            n = 0;
        } else {
            *dst = c;
            n++;
        }
        i++;
        dst++;
        src++;
    }
    if (n != 0) {
        *len = n;
        *dst = 0;
        ret = max + 2;
    } else {
        dst[-1] = 0;
        ret = max + 1;
    }
    return ret;
}

extern DnsAddr *TLobby__sub_8040C248(DnsHost *self);
extern s32 TLobby__sub_8040BD40(DnsQuery *self, u8 *p, s32 n, u8 *dst);
extern s32 TLobby__sub_8040BA38(DnsQuery *self, u8 *p, s32 n);
#pragma push
#pragma opt_propagation off
s32 TLobby__sub_8040B8BC(DnsQuery *self)
{
  volatile u32 pad[2];
  s32 len;
  DnsQuery *s;
  DnsBuffer *p;
  u8 *hdr;
  u8 *new_var;
  u16 cnt;
  s16 n;
  u16 t;
  u8 *cur;
  s32 op;
  s32 r;
  s = self;
  p = s->reply;
  hdr = p->data;
  len = p->len;
  if ((*((u16 *) hdr)) != (u16) s->id)
  {
    return -1;
  }
  if (!(hdr[2] & 0x80))
  {
    return -1;
  }
  op = hdr[3] & 0xF;
  switch (op)
  {
    case 1:
      TLobby__sub_8040BE40(s, -0x46, 0);
      return -1;

    case 3:
      TLobby__sub_8040BE40(s, -0x47, 0);
      return -1;

    case 2:

    case 4:

    case 5:

    default:
      s->timer = 1;
      return -1;

    case 0:
      if ((*((u16 *) (hdr + 6))) == 0)
    {
      s->timer = 1;
      return -1;
    }
      break;

  }

  cur = hdr + 0xc;
  len -= 0xc;
  t = *((u16 *) (hdr + 4));
  if (t != 0)
  {
    n = t;
    while (n > 0)
    {
      new_var = cur;
      r = TLobby__sub_8040BD40(s, new_var, len, 0) + 4;
      len -= r;
      cur += (s16) r;
      n--;
    }

  }
  cnt = *((u16 *) (hdr + 6));
  if (cnt != 0)
  {
    while (((s16) cnt) > 0)
    {
      r = TLobby__sub_8040BA38(s, cur, len);
      len -= r;
      cur += (s16) r;
      cnt--;
    }

  }
  return 0;
}
#pragma pop
inline DnsAddr *find_8040BA38(DnsHost *obj, DnsAddr *rec) {
    DnsAddr *node;
    s16 cnt;
    if (obj == 0 || rec == 0) {
        return 0;
    }
    for (node = obj->addrs, cnt = 0; node != 0 && cnt < dns_resolver_state.naddrs; node = node->next, cnt++) {
        if (TLobby__sub_8040C9E0(node, rec) == 0) {
            return node;
        }
    }
    return 0;
}
extern s32 TLobby__sub_8040BA38(DnsQuery *self, u8 *p, s32 n)
{
  s32 ret;
  s32 l;
  DnsRrHeader hdr;
  u8 *new_var;
  DnsAddr rec;
  s16 limit;
  DnsAddr *found;
  u8 *new_var2;
  ret = TLobby__sub_8040BD40(self, p, n, 0);
  p += (s16) ret;
  if (limit < (((s16) ret) + 10))
  {
    limit = n;
    return n;
  }
  NetMemcpy(&hdr, p, 10);
  ret += 10;
  l = hdr.rdlength;
  if (limit < (((s16) ret) + ((s16) l)))
  {
    return n;
  }
  ret += l;
  switch (hdr.rclass)
  {
    case 1:
      switch (hdr.type)
    {
      new_var2 = p;
      case 1:
      {
        DnsHost *obj;
        obj = self->req.lookup.host;
        if (obj == 0)
        {
          break;
        }
        rec.rtype = 1;
        rec.addr.family = 4;
        NetMemcpy(rec.addr.address, new_var2 + 10, 4);
        if ((found = find_8040BA38(obj, &rec)) == 0)
        {
          found = TLobby__sub_8040C248(obj);
          if (found == 0)
          {
            break;
          }
          found->used = 1;
          found->rtype = 1;
          found->addr.family = 4;
          new_var = new_var2;
          NetMemcpy(found->addr.address, new_var + 10, 4);
          found->host = obj;
          append_to_list(obj, found);
        }
        found->ttl = hdr.ttl;
        break;
      }

      case 5:
      {
        DnsHost *o = self->req.lookup.host;
        if ((o != 0) && (((s8) o->cname[0]) == 0))
        {
          TLobby__sub_8040BD40(self, new_var2 + 10, l, o->cname);
        }
        break;
      }
        if (!found)
      {
      }

      case 0x1c:
      {
        DnsHost *obj;
        obj = self->req.lookup.host;
        if (obj == 0)
        {
          break;
        }
        rec.rtype = 0x1c;
        rec.addr.family = 6;
        NetMemcpy(rec.addr.address, p + 10, 0x10);
        if ((found = find_8040BA38(obj, &rec)) == 0)
        {
          found = TLobby__sub_8040C248(obj);
          if (found == 0)
          {
            break;
          }
          found->used = 1;
          found->rtype = 0x1c;
          found->addr.family = 6;
          NetMemcpy(found->addr.address, new_var + 10, 0x10);
          found->host = obj;
          append_to_list(obj, found);
        }
        found->ttl = hdr.ttl;
        break;
      }

      case 0xc:
      {
        DnsPtr *o = self->req.ptr.entry;
        if (o != 0)
        {
          o->ttl = hdr.ttl;
          TLobby__sub_8040BD40(self, p + 10, l, o->name);
        }
        break;
      }

    }

      break;

  }

  end:
  return ret;

}
extern s32 TLobby__sub_8040BD40(DnsQuery *self, u8 *p, s32 n, u8 *dst)
{
  s16 new_var2;
  u8 c2;
  u8 c;
  int new_var3;
  u8 *q;
  s32 len;
  s32 count = 0;
  int new_var;
  new_var2 = (s16) n;
  while (((s16) count) < new_var2)
  {
    c = *p;
    if (!c)
    {
      count++;
      break;
    }
    if (c & 0xC0)
    {
      q = self->reply->data;
      q += (u16) (((new_var = c & (~0xC0)) << 8) | p[1]);
      new_var3 = 0;
      c2 = *q;
      p = q;
      while (c2 != new_var3)
      {
        if (dst != 0)
        {
          len = (c2 & 0xFF) + 1;
          NetMemcpy(dst, p, len);
          dst += len;
        }
        p += c2 + 1;
        c2 = *p;
      }

      count += 2;
      break;
    }
    if (dst != 0)
    {
      len = c + 1;
      NetMemcpy(dst, p, len);
      dst += len;
    }
    count = c;
    p += count + 1;
    count += c + 1;
  }

  return count;
}

inline void cancel_8040BE40(DnsPtr *o, s16 b) {
    DnsResolverState *base = &dns_resolver_state;
    s16 i;
    DnsQuery *e;
    i = 0;
    e = base->queries;
    while (i < base->nqueries) {
        if (e->req.ptr.entry == o) {
            e->status = -0x42;
            e->outstanding = 0;
            e->req.ptr.entry = NULL;
            dispatch_request_callback(e, b);
        }
        i++;
        e++;
    }
}
extern void TLobby__sub_8040BE40(DnsQuery *self, s16 a, s16 b)
{
    void TLobby__sub_8040C178(DnsHost *self, s16 x); /* declared here with an s16 2nd argument; the definition takes s32 */
    DnsPtr *o;
    DnsHost *p;
    switch (self->kind) {
    case 1:
        p = self->req.lookup.host;
        if (p != NULL) {
            self->req.lookup.host = NULL;
            TLobby__sub_8040C178(p, b);
        }
        break;
    case 12:
        o = self->req.ptr.entry;
        if (o != NULL) {
            self->req.ptr.entry = NULL;
            o->state = 0;
            o->ttl = 0;
            o->name[0] = 0;
            cancel_8040BE40(o, b);
        }
        break;
    }
    self->status = a;
    self->outstanding = 0;
    dispatch_request_callback(self, b);
}

inline s32 close_8040BF38(u8 *p, s32 id) {
    s32 r;
    if ((s16)id < 0) {
        return 0;
    }
    r = TLobby__sub_80421B3C(id);
    *(s16 *)((s8 *)p + 4) = -1;
    return r;
}
s32 close_and_reset_connection(void *self) {
    u8 *arg0 = (u8 *)self;
    s16 *temp_r3_2;
    s16 *temp_r3_3;
    s32 temp_r3;
    s32 var_r31;
    var_r31 = close_8040BF38(arg0, *(s16 *)&((TObjectFields *)self)->m_flags);
    TLobby__sub_80421814();
    temp_r3_2 = (s16 *)(*(s16 **)((s8 *)arg0 + 0x18));
    if (temp_r3_2 != NULL) {
        *(s16 *)((s8 *)temp_r3_2 + 0) = 0;
        *(s16 **)((s8 *)arg0 + 0x18) = NULL;
    }
    temp_r3_3 = (s16 *)(*(s16 **)((s8 *)arg0 + 0x1C));
    if (temp_r3_3 != NULL) {
        *(s16 *)((s8 *)temp_r3_3 + 0) = 0;
        *(s16 **)((s8 *)arg0 + 0x1C) = NULL;
    }
    *(s32 *)((s8 *)arg0 + 0x34) = 0;
    *(s32 *)((s8 *)arg0 + 0x28) = 0;
    *(s32 *)((s8 *)arg0 + 0x38) = 0;
    *(s32 *)((s8 *)arg0 + 0x2C) = 0;
    *(s16 *)&((TObjectFields *)self)->m_name = 0;
    *(s16 *)&((TObjectFields *)self)->m_prev = 0;
    *(s16 *)&((TObjectFields *)self)->m_up = -0x41;
    *(s16 *)((s8 *)arg0 + 0x12) = 0;
    if (*(u32 *)&((TObjectFields *)self)->m_next != 0xFFFFFFFFU) {
        resume_thread((s32)((TObjectFields *)self)->m_next);
        *(s32 *)&((TObjectFields *)self)->m_next = -1;
    }
    TLobby__sub_804217E4();
    return var_r31;
}


void reset_connection_requests(DnsPtr *o, s16 arg1) {
    s16 i;
    DnsQuery *e;

    o->state = 0;
    o->ttl = 0;
    o->name[0] = 0;
    i = 0;
    e = dns_resolver_state.queries;
    while (i < dns_resolver_state.nqueries) {
        if (e->req.ptr.entry == o) {
            e->status = -0x42;
            e->outstanding = 0;
            e->req.ptr.entry = 0;
            dispatch_request_callback((void *)e, arg1);
        }
        i++;
        e++;
    }
}

DnsHost *TLobby__sub_8040C09C(void) {
    DnsResolverState *dns = &dns_resolver_state;
    DnsHost *p = dns->hosts;
    DnsHost *found = NULL;
    s16 count = dns->nhosts;
    s16 i;

    for (i = 0; i < count; i++, p++) {
        if (p->state == 0) {
            p->state = 1;
            return p;
        } else if (found == NULL) {
            found = p;
        } else if (found->naddrs != 0 && p->naddrs != 0) {
            if (p->addrs->ttl < found->addrs->ttl) {
                found = p;
            }
        } else if (p->naddrs != 0) {
            found = p;
        }
    }
    TLobby__sub_8040C178(found, 1);
    found->state = 1;
    return found;
}

void TLobby__sub_8040C178(DnsHost *self, s32 x)
{
    void dispatch_request_callback(void* p, s32 x); /* declared here with an s32 2nd argument; the definition takes s16 */
  DnsResolverState *base;
  DnsAddr *e;
  s16 j;
  DnsAddr *p;
  DnsHost *new_var;
  DnsQuery *q;
  self->state = 0;
  j = 0;
  base = &dns_resolver_state;
  self->cname[0] = 0;
  self->naddrs = 0;
  p = self->addrs;
  while ((p != ((void *) 0)) && (j < base->naddrs))
  {
    e = p;
    p = e->next;
    j++;
    e->used = 0;
    e->next = (void *) 0;
  }

  (new_var = self)->addrs = (void *) 0;
  q = base->queries;
  for (j = 0; j < base->nqueries; j++, q++)
  {
    if (q->req.lookup.host == new_var)
    {
      q->status = -0x42;
      q->outstanding = 0;
      q->req.lookup.host = (void *) 0;
      dispatch_request_callback(q, x);
    }
  }

}

extern s32 TLobby__sub_8040C340(DnsHost *self_m, DnsAddr *arg);
extern DnsAddr *TLobby__sub_8040C248(DnsHost *self)
{
    s16 n;
    s16 i;
    DnsAddr *best;
    DnsAddr *e;
    s16 TLobby__sub_8040C340(DnsHost *, DnsAddr *); /* declared s16 here; the definition returns s32 */
    if (self == NULL) {
        return NULL;
    }
    e = dns_resolver_state.addrs;
    n = dns_resolver_state.naddrs;
    best = NULL;
    for (i = 0; i < n; i++, e++) {
        if (e->used == 0) {
            e->used = 1;
            e->next = NULL;
            return e;
        }
        if (e->host != self) {
            if (best == NULL) {
                best = e;
            } else if (e->ttl < best->ttl) {
                best = e;
            }
        }
    }
    if (best == NULL) {
        return NULL;
    }
    if (TLobby__sub_8040C340(best->host, best) < 0) {
        return NULL;
    }
    best->used = 1;
    best->next = NULL;
    return best;
}

extern s32 TLobby__sub_8040C340(DnsHost *self_m, DnsAddr *arg) {
DnsResolverState *tbl;
DnsAddr *node;
DnsAddr *prev;
u8 *key;
s16 i;
s32 r;
if (arg == ((void *) 0))
{
return -1;
}
if (self_m == ((void *) 0))
{
return -1;
}
if ((self_m->state == 0) || (self_m->addrs == ((void *) 0)))
{
return -1;
}
node = self_m->addrs;
tbl = &dns_resolver_state;
key = arg->addr.address;
prev = (DnsAddr *)((void *) 0);
for (i = 0; (node != ((void *) 0)) && (i < tbl->naddrs); node = node->next, (unsigned long long) (i++))
{
switch ((s32) node->addr.family)
{
case 4:
if (arg->addr.family != 4)
{
r = -1;
}
else
{
r = NetMemcmp((void *)(node->addr.address), (void *)(key), (int)(4));
}
break;
case 6:
if (arg->addr.family != 6)
{
r = -1;
}
else
{
r = NetMemcmp((void *)(node->addr.address), (void *)(key), (int)(0x10));
}
break;
case 0:
default:
r = -1;
break;
}
if (r != 0)
{
prev = node;
}
else
{
self_m->naddrs--;
if (prev == ((void *) 0))
{
self_m->addrs = node->next;
}
else
{
prev->next = node->next;
}
node->used = 0;
node->next = (DnsAddr *)((void *) 0);
return 0;
}
}
return -1;
}


s32 append_to_list(DnsHost *o, DnsAddr *n) {
    s16 i;
    DnsAddr *p;

    if (o == NULL || n == NULL) {
        return -1;
    }
    if (o->addrs == NULL) {
        o->naddrs = 1;
        o->addrs = n;
        return 0;
    }
    for (p = o->addrs, i = 0; i < ((DnsResolverState *)&dns_resolver_state)->naddrs; i++) {
        if (p->next == NULL) {
            o->naddrs++;
            p->next = n;
            return 0;
        }
        p = p->next;
    }
    return -1;
}


s16 TLobby__sub_8040C8A8(u8 *, u8 *, s16);
s16 TLobby__sub_8040C978(void *);

void dispatch_request_callback(void *self, s16 status) {
    DnsQuery *connection = (DnsQuery *)self;
    DnsLookupRequest *a;
    DnsPtrRequest *b;
    s32 err;

    switch (connection->kind) {
    case 1:
        a = &connection->req.lookup;
        if ((u32)a->cb == 0xFFFFFFFFU) {
            return;
        }
        if (a->cb == NULL) {
            if (status != 0) {
                TLobby__sub_80421814();
                if (connection->waiter != 0xFFFFFFFFU) {
                    resume_thread(connection->waiter);
                    connection->waiter = -1;
                }
                TLobby__sub_804217E4();
                return;
            }
            if (connection->waiter != 0xFFFFFFFFU) {
                resume_thread(connection->waiter);
                connection->waiter = -1;
            }
            return;
        }
        err = connection->status;
        if ((s16)err < 0) {
            a->cb(connection->index, a->addrs, err, a->cname, 0);
        } else {
            TLobby__sub_8040C74C(a);
            a->cb(connection->index, a->addrs, a->naddrs, a->cname, a->cname_len);
        }
        a->cb = NULL;
        break;
    case 12:
        b = &connection->req.ptr;
        if ((u32)b->cb == 0xFFFFFFFFU) {
            return;
        }
        if (b->cb == NULL) {
            if (status != 0) {
                TLobby__sub_80421814();
                if (connection->waiter != 0xFFFFFFFFU) {
                    resume_thread(connection->waiter);
                    connection->waiter = -1;
                }
                TLobby__sub_804217E4();
                return;
            }
            if (connection->waiter != 0xFFFFFFFFU) {
                resume_thread(connection->waiter);
                connection->waiter = -1;
            }
            return;
        }
        err = connection->status;
        if ((s16)err < 0) {
            b->cb(connection->index, b->name, err);
        } else {
            if (b->entry == NULL) {
                b->len = -0x42;
            } else if (b->name == NULL) {
                b->len = TLobby__sub_8040C978(b->entry->name);
            } else {
                b->len = TLobby__sub_8040C8A8(b->name, b->entry->name, b->len);
            }
            b->cb(connection->index, b->name, b->len);
        }
        b->cb = NULL;
        break;
    }
}

void TLobby__sub_8040C74C(DnsLookupRequest *self) {
    s16 n;
    s8 *s;
    s32 len;
    s16 j;
    DnsHost *obj;
    s16 cnt;
    NetworkAddress *cur;
    DnsAddr *ent;
    s16 v;

    obj = self->host;
    if (obj == NULL) {
        self->naddrs = -0x42;
        return;
    }
    if ((s8)obj->cname[0] != 0 && (v = self->cname_len) != 0) {
        if (self->cname == NULL) {
            s = (s8 *)obj->cname;
            n = 0;
            while (n < 0xff) {
                s8 c = *s++;
                if (c == 0) {
                    n--;
                    break;
                }
                len = c;
                if (n + len + 1 <= 0xff) {
                    s += len;
                } else {
                    n = 0xff;
                    break;
                }
                n += len + 1;
            }
            self->cname_len = n;
        } else {
            self->cname_len = TLobby__sub_8040C8A8(self->cname, obj->cname, v);
        }
    } else {
        self->cname_len = 0;
    }
    cur = self->addrs;
    cnt = 0;
    ent = obj->addrs;
    for (j = 0; j < obj->naddrs; j++, ent = ent->next) {
        if (self->family == 0 || self->family == ent->addr.family) {
            cnt++;
            if (cur != NULL) {
                NetMemcpy(cur, &ent->addr, sizeof(NetworkAddress));
                cur++;
                if (cnt >= self->naddrs) {
                    break;
                }
            }
        }
    }
    self->naddrs = cnt;
}

#pragma push
#pragma optimization_level 2
#pragma opt_common_subs off
extern s16 TLobby__sub_8040C8A8(u8 *dst, u8 *src, s16 max) {
    s32 limit = max;
    s32 n;
    s16 len = 0;

    while (len < limit) {
        s8 c = *src++;
        if (c == 0) {
            *dst = 0;
            return --len;
        }
        n = c;
        if (limit >= len + n + 1) {
            NetMemcpy(dst, src, n);
            dst += n;
            *dst = '.';
            src += n;
            dst++;
        } else {
            NetMemcpy(dst, src, limit - len);
            return max;
        }
        len += n + 1;
    }
    return len;
}
#pragma pop

s16 TLobby__sub_8040C978(void *arg)
{
  int new_var;
  u8 *s;
  s16 i;
  s8 c;
  s8 n;
  i = 0;
  s = (u8 *) arg;
  while (i < 0xff)
  {
    c = *(s++);
    if (c == 0)
    {
      return --i;
    }
    n = c;
    new_var = n;
    if (((((s32) i) + new_var) + 1) <= 0xff)
    {
      s += new_var;
    }
    else
    {
      return 0xff;
    }
    i = new_var + i;
    i++;
  }

  return i;
}

s32 TLobby__sub_8040C9E0(DnsAddr *arg0, DnsAddr *arg1) {
    s32 var_r5;
    u8 *var_r3;
    u8 *var_r4;
    switch ((s32) (arg0->rtype)) {
    case 1:
        if ((u16) arg1->rtype != 1) {
            var_r3 = (u8 *)((void *)-1);
            return -1;
        }
        switch ((s32) arg0->addr.family) {
        case 4:
            if ((u32) arg1->addr.family != 4U) {
                var_r3 = (u8 *)((void *)-1);
                return -1;
            }
            var_r3 = arg0->addr.address;
            var_r4 = arg1->addr.address;
            var_r5 = 4;
            return NetMemcmp((void *)(var_r3), (void *)(var_r4), 4);
        case 6:
            if ((u32) arg1->addr.family != 6U) {
                var_r3 = (u8 *)((void *)-1);
                return -1;
            }
            var_r3 = arg0->addr.address;
            var_r4 = arg1->addr.address;
            var_r5 = 0x10;
            return NetMemcmp((void *)(var_r3), (void *)(var_r4), 0x10);
        default:
        case 0:
            var_r3 = (u8 *)((void *)-1);
            return -1;
        }
        break;
    case 28:
        if ((u16) arg1->rtype != 0x1C) {
            var_r3 = (u8 *)((void *)-1);
            return -1;
        }
        switch ((s32) arg0->addr.family) {
        case 4:
            if ((u32) arg1->addr.family != 4U) {
                var_r3 = (u8 *)((void *)-1);
                return -1;
            }
            var_r3 = arg0->addr.address;
            var_r4 = arg1->addr.address;
            var_r5 = 4;
            return NetMemcmp((void *)(var_r3), (void *)(var_r4), 4);
        case 6:
            if ((u32) arg1->addr.family != 6U) {
                var_r3 = (u8 *)((void *)-1);
                return -1;
            }
            var_r3 = arg0->addr.address;
            var_r4 = arg1->addr.address;
            var_r5 = 0x10;
            return NetMemcmp((void *)(var_r3), (void *)(var_r4), 0x10);
        default:
        case 0:
            var_r3 = (u8 *)((void *)-1);
            return -1;
        }
        break;
    default:
        var_r3 = (u8 *)((void *)-1);
        return -1;
    }
}

s16 TLobby__sub_8040CB44(u8 *self, u32 d, u32 c)
{
  s16 TLobby__sub_8040CFE8(u8 type, u8 code, u32 src, u32 dst, NetPacket *pkt);
  s32 TLobby__sub_8040F8A4(u32, void *, u32, u32, u32);
  u8 *p;
  u8 stream[0xc];
  u8 hdr[8];
  u32 *new_var;
  u8 ip[24];
  u8 udp[8];
  u8 addr[4];
  u8 pad[12];
  u8 *q;
  s16 r;
  u32 i;
  u8 *rec;
  u8 *out;
  unsigned int a;
  u32 net;
  u32 mask;
  rec = self + 0x18;
  set_value_and_enable(stream, (s32) hdr);
  TLobby__sub_80406FD8(stream, rec + 4, 8);
  if (calc_ip_checksum(self, 0) != 0)
  {
    return -1;
  }
  switch (hdr[0])
  {
    case 0:

    case 4:

    case 11:

    case 12:

    case 13:

    case 14:

    case 17:

    case 18:
      break;

    case 8:
      out = alloc_free_entry();
      if (out == ((void *) 0))
    {
      return -0x101;
    }
      *((s32 *) (out + 4)) = (*((s32 *) (self + 4))) - 1;
      *((s32 *) (out + 8)) = (*((s32 *) (self + 8))) - (*((s16 *) (self + 0xc)));
      p = self + (*((s32 *) (self + 4))) * 12;
      for (i = 0, q = out; i < (*((u32 *) (out + 4))); i++)
    {
      *((s16 *) (q + 0xc)) = *((s16 *) p);
      NetMemcpy(q + 0x10, (p -= 12) + 16, 8);
      q += 12;
    }

      r = TLobby__sub_8040CFE8(0, 0, c, d, (NetPacket *)(out));
      if (r < 0)
    {
      release_entry(out);
      return r;
    }
      release_entry(out);
      return 0;

    case 3:
      TLobby__sub_80406EB8((NetBufferRef *)(rec + 4), 8);
      set_value_and_enable(stream, (s32) ip);
      TLobby__sub_80406FD8(stream, rec + 4, 20);
      TLobby__sub_80406EB8((NetBufferRef *)(rec + 4), (ip[0] & 0xf) << 2);
      switch (ip[9])
    {
      case 6:
        break;

      case 17:
        set_value_and_enable(stream, (s32) udp);
        TLobby__sub_80406FD8(stream, rec + 4, 8);
        TLobby__sub_80420D38(*((u16 *) udp), hdr[1]);
        break;

    }

      return 0;

    case 5:
      TLobby__sub_80406EB8((NetBufferRef *)(rec + 4), 8);
      set_value_and_enable(stream, (s32) ip);
      TLobby__sub_80406FD8(stream, rec + 4, 20);
      switch (hdr[1])
    {
      case 0:

      case 2:
        NetMemcpy(addr, hdr + 4, 4);
        a = *((u32 *) (ip + 16));
        net = ((a & 0x80000000) == 0) ? (a & 0xFF000000) : (((a & 0xC0000000) == 0x80000000) ? (a & 0xFFFF0000) : (((a & 0xE0000000) == 0xC0000000) ? (a & 0xFFFFFF00) : (0)));
        new_var = (u32 *) addr;
        mask = ((a & 0x80000000) == 0) ? (0xFF000000) : (((a & 0xC0000000) == 0x80000000) ? (0xFFFF0000) : (((a & 0xE0000000) == 0xC0000000) ? (0xFFFFFF00) : (0)));
        TLobby__sub_8040F8A4(net, (void *) (*new_var), mask, 2, d);
        break;

      case 1:

      case 3:
        NetMemcpy(addr, hdr + 4, 4);
        TLobby__sub_8040F8A4(*((u32 *) (ip + 16)), (void *) (*((u32 *) addr)), -1, 6, d);
        break;

    }

      return 0;

    default:
      return -1;

  }

  return 0;
}

s32 TUdpSocket__sub_8040CE58(u8 *p, u8 *b, s16 x, s16 id)
{
  s32 TLobby__sub_8040E780(u8 *rec, u32 dst, u32 src, u8 ttl, u8 tos, u8 df, void *proto); /* declared s32 here; the definition returns s16 */
  u8 *h;
  s32 lim;
  s32 r;
  s16 NetIPv4IsUnspecified(u32); /* declared s16 here; the definition returns s32 */
  s16 NetIPv4IsLoopback(s32); /* declared s16 here; the definition returns s32 */
  s16 TLobby__sub_8040FDA0(u32, s16); /* declared s16 here; the definition returns s32 */
  if ((NetIPv4IsUnspecified(*((u32 *) (b + 0xc))) || NetIPv4IsLoopback(*((s32 *) (b + 0xc)))) || (TLobby__sub_8040FDA0(*((u32 *) (b + 0xc)), id) != 0))
  {
    return -1;
  }
  if (TLobby__sub_8040FDA0(*((u32 *) (b + 0x10)), id))
  {
    return -1;
  }
  h = alloc_free_entry();
  if (h == ((void *) 0))
  {
    return -1;
  }
  lim = (s16) ((b[0] << 2) & 0x3C);
  lim = lim + 8;
  x = (x < lim) ? (x) : (lim);
  *((s32 *) (h + 4)) = 0;
  *((s32 *) (h + 8)) = x;
  ((struct 
  {
    s16 v;
    u8 pad[10];
  } *) (h + 0xc))[*((s32 *) (h + 4))].v = x;
  set_value_and_enable(&(h + 0x10)[(*((s32 *) (h + 4))) * 12], (s32) b);
  *((s32 *) (h + 4)) += 1;
  *((s32 *) (h + 8)) += 8;
  ((struct 
  {
    s16 v;
    u8 pad[10];
  } *) (h + 0xc))[*((s32 *) (h + 4))].v = 8;
  set_value_and_enable(&(h + 0x10)[(*((s32 *) (h + 4))) * 12], (s32) p);
  *((s32 *) (h + 4)) += 1;
  *((u16 *) (p + 2)) = 0;
  *((u16 *) (p + 2)) = calc_ip_checksum(h, 1);
  r = TLobby__sub_8040E780(h, *((u32 *) (b + 0xc)), *((u32 *) (b + 0x10)), 0, 0, 0, (void *) 1);
  release_entry(h);
  return r;
}

typedef struct Icmp4Header {
    u8 type;
    u8 code;
    u16 checksum;
    u8 rest[4];
} Icmp4Header;
typedef char Icmp4Header_size_check[sizeof(Icmp4Header) == 8 ? 1 : -1];
s16 TLobby__sub_8040CFE8(u8 type, u8 code, u32 src, u32 dst, NetPacket *pkt) {
    s16 TLobby__sub_8040E780(u8 *rec, u32 dst, u32 src, u8 ttl, u8 tos, u8 df, void *proto);
    NetBufferRef ref;
    Icmp4Header hdr;

    switch (type) {
    case 0:
        set_value_and_enable((&ref), (s32)&hdr);
        TLobby__sub_80406FD8(&ref, &pkt->fragments[pkt->fragment_count - 1].buffer, sizeof(hdr));
        TLobby__sub_80406EB8(&pkt->fragments[pkt->fragment_count - 1].buffer, sizeof(hdr));
        pkt->fragments[pkt->fragment_count - 1].length -= sizeof(hdr);
        pkt->fragments[pkt->fragment_count].length = sizeof(hdr);
        set_value_and_enable((&pkt->fragments[pkt->fragment_count].buffer), (s32)&hdr);
        pkt->fragment_count++;
        break;
    default:
        return -1;
    }
    hdr.type = type;
    hdr.code = code;
    hdr.checksum = 0;
    hdr.checksum = calc_ip_checksum((pkt), 1);
    if (TLobby__sub_8040E780((u8 *)pkt, dst, src, 0, 0, 0, (void *)1)) {
        return -1;
    }
    return 0;
}

/* Defined K&R with an s16 mtu (TLobby_8041112C.c). */
s32 TLobby__sub_80411DEC(IPv6Address *addr, s16 mtu);
extern s16 TLobby__sub_8040D718(u8 type, u8 code, u8 *src, u8 *dst, NetPacket *pkt, s16 idx);
typedef struct Icmp6ErrorInfo {
    u8 type;
    u8 code;
    u16 checksum;
    s32 pointer;
} Icmp6ErrorInfo;
typedef char Icmp6ErrorInfo_size_check[sizeof(Icmp6ErrorInfo) == 8 ? 1 : -1];
typedef struct UdpHeader {
    u16 src_port;
    u16 dst_port;
    u16 length;
    u16 checksum;
} UdpHeader;
typedef char UdpHeader_size_check[sizeof(UdpHeader) == 8 ? 1 : -1];
extern s16 NetIPv6HandleIcmpMessage(NetPacket *pkt, u8 *src, u8 *dst, u8 hop_limit, s16 iface) {
    /* The handlers are defined in TLobby_8041112C.c with their own parameter types (s32/void * for some
       arguments); this caller declares them with an s16 iface. */
    s16 NetIPv6HandleRouterSolicitation(NetPacket *pkt, u8 *src, u8 *dst, s16 iface);
    s16 NetIPv6HandleRouterAdvertisement(NetPacket *pkt, u8 *src, u8 *dst, s16 iface);
    s16 NetIPv6HandleNeighborSolicitation(NetPacket *pkt, u8 *src, u8 *dst, s16 iface);
    s16 NetIPv6HandleNeighborAdvertisement(NetPacket *pkt, u8 *src, u8 *dst, s16 iface);
    s16 NetIPv6HandleRedirect(NetPacket *pkt, u8 *src, u8 *dst, s16 iface);
    NetBufferRef ref;
    Ipv6Header ip;
    Icmp6ErrorInfo icmp;
    UdpHeader udp;
    NetPacketFragment *from;
    NetBufferRef *buf;
    s32 mtu;
    s16 r;
    u32 i;
    NetPacketFragment *body;
    NetPacket *reply;

    if (TLobby__sub_80411040((const IPv6Address *)src, (const IPv6Address *)dst, 0x3A, pkt, 0)) {
        return -1;
    }
    body = &pkt->fragments[1];
    set_value_and_enable((&ref), (s32)&icmp);
    TLobby__sub_80406FD8(&ref, &body->buffer, 8);
    switch (icmp.type) {
    case 128:
        reply = (NetPacket *)alloc_free_entry();
        if (reply == NULL) {
            return -257;
        }
        reply->fragment_count = pkt->fragment_count - 1;
        reply->total_bytes = pkt->total_bytes - pkt->fragments[0].length;
        from = &pkt->fragments[pkt->fragment_count] - 1;
        for (i = 0; i < reply->fragment_count; i++) {
            reply->fragments[i].length = from->length;
            buf = &from->buffer;
            from--;
            NetMemcpy(&reply->fragments[i].buffer, buf, 8);
        }
        r = TLobby__sub_8040D718(0x81, 0, dst, src, reply, iface);
        release_entry(reply);
        return r;
    case 1:
        TLobby__sub_80406EB8(&body->buffer, 8);
        set_value_and_enable((&ref), (s32)&ip);
        TLobby__sub_80406FD8(&ref, &body->buffer, sizeof(ip));
        TLobby__sub_80406EB8(&body->buffer, sizeof(ip));
        switch (ip.next_header) {
        case 17:
            set_value_and_enable((&ref), (s32)&udp);
            TLobby__sub_80406FD8(&ref, &body->buffer, sizeof(udp));
            TLobby__sub_80420D38(udp.src_port, icmp.code);
            break;
        case 6:
            break;
        }
        return 0;
    case 2:
        mtu = icmp.pointer;
        if (mtu > 0 && mtu < 0x8000) {
            TLobby__sub_80406EB8(&body->buffer, 8);
            set_value_and_enable((&ref), (s32)&ip);
            TLobby__sub_80406FD8(&ref, &body->buffer, sizeof(ip));
            TLobby__sub_80411DEC(&ip.dst, mtu);
        }
        return 0;
    case 133:
        if (hop_limit != 255) {
            return -1;
        }
        switch (icmp.code) {
        case 0:
            r = NetIPv6HandleRouterSolicitation(pkt, src, dst, iface);
            if (r < 0) {
                return r;
            }
            break;
        }
        return 0;
    case 134:
        if (hop_limit != 255) {
            return -1;
        }
        switch (icmp.code) {
        case 0:
            r = NetIPv6HandleRouterAdvertisement(pkt, src, dst, iface);
            if (r < 0) {
                return r;
            }
            break;
        }
        return 0;
    case 135:
        if (hop_limit != 255) {
            return -1;
        }
        switch (icmp.code) {
        case 0:
            r = NetIPv6HandleNeighborSolicitation(pkt, src, dst, iface);
            if (r < 0) {
                return r;
            }
            break;
        }
        return 0;
    case 136:
        if (hop_limit != 255) {
            return -1;
        }
        switch (icmp.code) {
        case 0:
            r = NetIPv6HandleNeighborAdvertisement(pkt, src, dst, iface);
            if (r < 0) {
                return r;
            }
            break;
        }
        return 0;
    case 137:
        if (hop_limit != 255) {
            return -1;
        }
        switch (icmp.code) {
        case 0:
            r = NetIPv6HandleRedirect(pkt, src, dst, iface);
            if (r < 0) {
                return r;
            }
            break;
        }
        return 0;
    case 3:
    case 4:
    case 129:
        break;
    default:
        return 0;
    }
    return 0;
}

s16 TLobby__sub_8040D510(void *a, u8 *src, s16 c, s16 flag) {
    s16 NetIPv6IsUnspecified(u8 *); /* declared s16 here; the definition returns s32 */
    s16 NetIPv6IsMulticast(u8 *); /* declared s16 here; the definition returns s32 */
    s16 TLobby__sub_80413D78(void *, s16);
    s16 TLobby__sub_80411F1C(void *, void *, s16); /* declared s16 here; the definition returns s32 */
    s16 TLobby__sub_80410A98(s32, void *, void *, void *, void *); /* declared s16 here; the definition returns s32 */
    u8 buf[0x10];
    u8 *p;
    u8 *rec;
    s16 r;
    s16 t;
    s16 d;
    s32 len;

    if (NetIPv6IsUnspecified(src + 8) != 0 || NetIPv6IsMulticast(src + 8) != 0 ||
        TLobby__sub_80413D78(src + 8, flag) != 0) {
        return -1;
    }
    if (NetIPv6IsMulticast(src + 0x18) != 0) {
        switch (((u8 *)a)[0]) {
        case 2:
        case 4:
            break;
        default:
            return -1;
        }
        t = TLobby__sub_80411F1C(buf, src + 8, flag);
        if (t < 0) {
            return t;
        }
    } else {
        NetMemcpy(buf, src + 0x18, 0x10);
    }
    p = src + 8;
    rec = (u8 *)alloc_free_entry();
    if (rec == NULL) {
        return -1;
    }
    *(s32 *)(rec + 4) = 0;
    *(s32 *)(rec + 8) = c;
    ((struct { s16 len; u8 pad[10]; } *)(rec + 0xc))[*(s32 *)(rec + 4)].len = c;
    set_value_and_enable(rec + 0x10 + *(s32 *)(rec + 4) * 0xc, (s32)src);
    *(s32 *)(rec + 4) += 1;
    *(s32 *)(rec + 8) += 8;
    ((struct { s16 len; u8 pad[10]; } *)(rec + 0xc))[*(s32 *)(rec + 4)].len = 8;
    set_value_and_enable(rec + 0x10 + *(s32 *)(rec + 4) * 0xc, (s32)a);
    *(s32 *)(rec + 4) += 1;
    if (*(u32 *)(rec + 8) + 0x28 > 0x500) {
        d = len = *(u32 *)(rec + 8) - 0x4d8;
        if (d > *(s16 *)(rec + 0xc)) {
            return -1;
        }
        *(u32 *)(rec + 8) -= d;
        *(s16 *)(rec + 0xc) -= d;
    }
    *(s16 *)((u8 *)a + 2) = 0;
    *(s16 *)((u8 *)a + 2) = TLobby__sub_80411040((const IPv6Address *)buf, (const IPv6Address *)p, 0x3a, (const NetPacket *)rec, 1);
    r = TLobby__sub_80410A98((s32)rec, p, buf, 0, (void *)0x3a);
    release_entry(rec);
    return r;
}

typedef struct Icmp6MessageHeader {
    u8 type;
    u8 code;
    u16 checksum;
} Icmp6MessageHeader;
typedef char Icmp6MessageHeader_size_check[sizeof(Icmp6MessageHeader) == 4 ? 1 : -1];
extern s16 TLobby__sub_8040D718(u8 type, u8 code, u8 *src, u8 *dst, NetPacket *pkt, s16 idx) {
    s16 NetIPv6IsMulticast(u8 *arg0); /* declared s16 here; the definition returns s32 */
    s16 NetIPv6IsUnspecified(u8 *arg0); /* declared s16 here; the definition returns s32 */
    s16 TLobby__sub_80411F1C(void *, void *, s16); /* declared s16 here; the definition returns s32 */
    s16 TLobby__sub_80410A98(s32, void *, void *, void *, void *); /* declared s16 here; the definition returns s32 */
    Icmp6MessageHeader hdr;
    s16 r;

    if (NetIPv6IsMulticast(src) || NetIPv6IsUnspecified(src)) {
        r = TLobby__sub_80411F1C(src, dst, idx);
        if (r < 0) {
            return r;
        }
    }
    switch (type) {
    case 0x81:
        TLobby__sub_80406EB8(&pkt->fragments[pkt->fragment_count - 1].buffer, sizeof(hdr));
        pkt->fragments[pkt->fragment_count - 1].length -= sizeof(hdr);
        pkt->fragments[pkt->fragment_count].length = sizeof(hdr);
        set_value_and_enable((&pkt->fragments[pkt->fragment_count].buffer), (s32)&hdr);
        pkt->fragment_count++;
        break;
    default:
        return -1;
    }
    hdr.type = type;
    hdr.code = code;
    hdr.checksum = 0;
    hdr.checksum = TLobby__sub_80411040((const IPv6Address *)src, (const IPv6Address *)dst, 0x3A, pkt, 1);
    if (TLobby__sub_80410A98((s32)pkt, dst, src, NULL, (void *)0x3A)) {
        return -1;
    }
    return 0;
}

s32 TLobby__sub_80410A98(s32, void *, void *, void *, void *);

s32 dispatch_by_addr_family(s32 arg0, NetworkAddress *arg1, NetworkAddress *arg2, u8 *arg3, void *arg4, void *arg5) {
    s32 TLobby__sub_8040E780(u8 *rec, u32 dst, u32 src, u8 ttl, u8 tos, u8 df, void *proto); /* declared s32 here; the definition returns s16 */
    switch (arg2->family) {
    case 4:
        return TLobby__sub_8040E780((u8 *)arg0, arg1->ipv4, arg2->ipv4, arg3[0], arg3[1], arg3[2], arg5);
    case 6:
        return TLobby__sub_80410A98(arg0, arg1->address, arg2->address, arg4, arg5);
    case 0:
    default:
        return -2;
    }
}

u16 TLobby__sub_8040D8F0(u8 *arg0, u8 *arg1, s8 arg2, u8 *pkt, s16 flag) {
    typedef struct Fields_arg0 { s32 field_0; s32 field_4; } Fields_arg0;
    typedef struct Fields_arg1 { u8 pad_0[4]; s32 field_4; } Fields_arg1;
    switch (((Fields_arg0*)arg0)->field_0) {
    case 4:
        return calc_pseudo_header_checksum(((Fields_arg0*)arg0)->field_4, ((Fields_arg1*)arg1)->field_4, arg2, pkt, flag);
    case 6:
        return TLobby__sub_80411040((const IPv6Address *)((void *) (arg0 + 4)), (const IPv6Address *)((void *) (arg1 + 4)), arg2, (const NetPacket *)(pkt), flag);
    case 0:
    default:
        return 0xFFFEU;
    }
}

typedef struct Ent_8040D95C { u8 pad0[2]; s16 f2; u8 pad4[2]; s16 f6; u8 pad8[4]; s32 fC; } Ent_8040D95C;
s32 TLobby__sub_8040EF50(u32 *out, u32 mask, s16 c);
s32 select_source_address(Out_8040D95C *arg0, In_8040D95C *arg1) {
    Ent_8040D95C *e;
    s16 ok;
    s16 NetIPv6IsUnspecified(u8 *arg0); /* declared s16 here; the definition returns s32 */

    switch (arg1->type) {
    case 4:
        {
        u32 v = arg0->f4;
        if (v != 0) {
            return 0;
        }
        e = (Ent_8040D95C *)TLobby__sub_8040F76C(arg1->f4, v);
        if (e == NULL) {
            return -6;
        }
        arg0->type = 4;
        return TLobby__sub_8040EF50(&arg0->f4, e->fC, e->f2);
        }
    case 6:
        ok = NetIPv6IsUnspecified((u8 *)&arg0->f4);
        if (ok == 0) {
            return 0;
        }
        {
        Ipv6Route *rt = TLobby__sub_80413264(&arg1->f4, &arg0->f4);
        if (rt == NULL) {
            return -6;
        }
        arg0->type = 6;
        return TLobby__sub_80411F1C(&arg0->f4, &arg1->f4, rt->iface);
        }
    case 0:
    default:
        return -2;
    }
}

s32 TLobby__sub_8040DA54(u8 *arg0, u8 *arg1) {
    typedef struct Fields_arg0 { s32 field_0; u8 * field_4; } Fields_arg0;
    typedef struct Fields_arg1 { u8 pad_0[4]; s32 field_4; } Fields_arg1;
    s32 var_r4;
    u8 *var_r3;
    switch (((Fields_arg0*)arg0)->field_0) {
    case 4:
        var_r3 = (u8 *)(((Fields_arg0*)arg0)->field_4);
        var_r4 = ((Fields_arg1*)arg1)->field_4;
        return is_lookup_found((u32)var_r3, (u32)(var_r4));
    case 6:
        var_r3 = (u8 *)(arg0 + 4);
        var_r4 = (long) (arg1 + 4);
        return TLobby__sub_80413230((u8 *)(var_r3), (s32)(var_r4));
    default:
    case 0:
        var_r3 = (u8 *)((void *)-2);
        return -2;
    }
}

s16 NetValidateLocalAddress(NetworkAddress* address) {
    s16 TLobby__sub_804136EC(s32);
    u32 ip;
    switch ((s32)address->family) {
    case 0:
        return 0;
    case 4:
        ip = address->ipv4;
        if (ip != 0) {
            return TLobby__sub_8040FCEC(ip);
        }
        return 0;
    case 6:
        return TLobby__sub_804136EC((s32)address->address);
    default:
        return -2;
    }
}

s32 is_multicast_address(void *self, s16 arg1) {
    u8 *arg0 = (u8 *)self;
    typedef struct Fields_arg0 { s32 field_0; u32 field_4; } Fields_arg0;
    switch (((Fields_arg0*)arg0)->field_0) {
    case 4:
        return TLobby__sub_8040FDA0(((Fields_arg0*)arg0)->field_4, arg1);
    case 6:
        return NetIPv6IsMulticast((u8 *)(arg0 + 4));
    case 0:
    default:
        return 0;
    }
}

s32 is_addr_unspecified(u8 *arg0) {
    typedef struct Fields_arg0 { s32 field_0; u32 field_4; } Fields_arg0;
    switch (((Fields_arg0*)arg0)->field_0) {
    case 0:
        return 1;
    case 4:
        return NetIPv4IsUnspecified((u32)(((Fields_arg0*)arg0)->field_4));
    case 6:
        return NetIPv6IsUnspecified((u8 *)(arg0 + 4));
    default:
        return 0;
    }
}

s32 compare_sockaddr(void *self, u8 *arg1) {
    u8 *arg0 = (u8 *)self;
    typedef struct Fields_arg0 { s32 field_0; u8 * field_4; } Fields_arg0;
    typedef struct Fields_arg1 { u32 field_0; u8 * field_4; } Fields_arg1;
    u8 *var_r3;
    u8 *var_r4;
    switch (((Fields_arg0*)arg0)->field_0) {
    case 4:
        if ((u32) ((Fields_arg1*)arg1)->field_0 != 4U) {
            var_r3 = (u8 *)((void *)-1);
            return -1;
        }
        var_r3 = (u8 *)(((Fields_arg0*)arg0)->field_4);
        var_r4 = (u8 *)(((Fields_arg1*)arg1)->field_4);
        return TLobby__sub_8040FEE4((s32)(var_r3), (s32)(var_r4));
    case 6:
        if ((u32) ((Fields_arg1*)arg1)->field_0 != 6U) {
            var_r3 = (u8 *)((void *)-1);
            return -1;
        }
        var_r3 = (u8 *)(arg0 + 4);
        var_r4 = (u8 *)(arg1 + 4);
        return NetIPv6CompareAddresses((s32)(var_r3), (s32)(var_r4));
    default:
    case 0:
        var_r3 = (u8 *)((void *)-1);
        return -1;
    }
}

s16 TLobby__sub_8040DC8C(u8 *arg0, u8 *arg1) {
    s16 TLobby__sub_8040EF00(s16); /* declared s16 here; the definition returns s32 */
    s16 temp_r3;
    s16 mtu;
    u32 temp_r5;
    u8 *temp_r3_3;
    Ipv6Route *temp_r3_4;
    temp_r5 = *(u32 *)((s8 *)arg0 + 0);
    if ((u32) *(u32 *)((s8 *)arg1 + 0) != temp_r5) {
        return -2;
    }
    switch ((s32) temp_r5) {
    case 4:
        temp_r3_3 = (u8 *)(TLobby__sub_8040F76C(*(s32 *)((s8 *)arg0 + 4), *(s32 *)((s8 *)arg1 + 4)));
        if (temp_r3_3 == NULL) {
            return -6;
        }
        temp_r3 = TLobby__sub_8040EF00(*(s16 *)((s8 *)temp_r3_3 + 2));
        if (temp_r3 < 0x28) {
            return -6;
        }
        return temp_r3 - 0x28;
    case 6:
        temp_r3_4 = TLobby__sub_80413264(arg0 + 4, arg1 + 4);
        if (temp_r3_4 == NULL) {
            return -6;
        }
        mtu = get_iface_mtu(temp_r3_4->iface);
        if (mtu < 0x3C) {
            return -6;
        }
        return mtu - 0x3C;
    case 0:
    default:
        return -2;
    }
}

s32 TLobby__sub_8040DD68(void) {
    release_slot_by_id(0x800);
    TLobby__sub_803F892C((void *)((void *) (&ipv4_protocol_state.value)));
    ipv4_protocol_state.value = 0;
    return 0;
}

s32 TUdpSocket__sub_8040DE4C(u8 *ip, s16 x, s16 id);
s32 init_ipv4_interfaces(void) {
    s16 i;
    E_8040DDB0 *e;
    RecoveredGlobal_8040DD68_lbl_805C1B38 *g = &ipv4_protocol_state;

    TLobby__sub_803F8930((u8 *)&g->value);
    e = g->ents;
    for (i = 0; i < g->value; i++) {
        e->c0 = 0x49;
        e->c1 = 0x50;
        e->c2 = 0x34;
        e->c3 = i;
        e->f4 = 0;
        e++;
    }
    g->f8 = 1;
    register_protocol_handler(0x800, (NetProtocolHandler)TUdpSocket__sub_8040DE4C);
    return 0;
}

s32 TUdpSocket__sub_8040DE4C(u8 *ip, s16 x, s16 id)
{
  u8 *p;
  u8 *g;
  u8 hl;
  s16 r;
  s16 n;
  s16 found;
  s16 i;
  u32 tl;
  s32 rr;
  u32 fl;
  int new_var2;
  unsigned char mf;
  u32 s;
  s16 TUdpSocket__sub_8040E354(u8 *, u32, u8 *, s16, s16); /* declared with 5 parameters; the definition is s16 (u8 *, u32, u8 *, s32) */
  s16 TLobby__sub_8040FDA0(u32, s16); /* declared s16 here; the definition returns s32 */
  s16 TLobby__sub_8040FE40(s16); /* declared s16 here; the definition returns s32 */
  s32 TLobby__sub_80418C40(u8* self, void* p1, s16 p2, u8 p3, u32 p4, void* p5, u16 p6, u8 p7, s16 p8);
  s16 TLobby__sub_8041B974(void *, void *, void *); /* declared s16 here; the definition is s32 (u8 *, u8 *, u8 *) */
  s16 udp_input(void *, void *, void *, s16); /* declared s16 here; the definition is s32 (O_80420DE4 *, NetworkAddress *, NetworkAddress *, s32) */
  s32 TLobby__sub_80421AD8(u8 *, u32, u32, u32, s16); /* declared here with other parameter types; the definition is s32 (u8 *, s32, s32, u32, s32) */
  u16 TUdpSocket__sub_80419864(void *, s16);
  struct 
  {
    s32 t;
    u32 a;
    u8 pad[0xC];
  } src;
  struct 
  {
    s32 t;
    u32 a;
    u8 pad[0xC];
  } dst;
  struct 
  {
    u8 type;
    u8 code;
    s32 w;
  } ic;
  u8 padx[12];
  if (x < 5)
  {
    return -1;
  }
  if (get_active_entry_by_index(id) == 0)
  {
    return -1;
  }
  src.t = 4;
  NetMemcpy(&src.a, ip + 12, 4);
  dst.t = 4;
  NetMemcpy(&dst.a, ip + 16, 4);
  hl = (ip[0] << 2) & 0x3C;
  tl = *((u16 *) (ip + 2));
  n = tl - hl;
  if (hl < 20)
  {
    return -1;
  }
  if ((ip[0] >> 4) != 4)
  {
    return -1;
  }
  s = TUdpSocket__sub_80419864(ip, (s16) (hl >> 1));
  s = (s >> 16) + (s & 0xFFFF);
  s += s >> 16;
  if (((u16) (~s)) != 0)
  {
    return -1;
  }
  if (tl < hl)
  {
    return -1;
  }
  if (id != 0)
  {
    if (TLobby__sub_8040FCEC(dst.a) < 0)
    {
      if (TLobby__sub_8040FDA0(dst.a, id) == 0)
      {
        if (TLobby__sub_8040FE40(id) != 0)
        {
          r = TUdpSocket__sub_8040E354((u8 *) dst.a, src.a, ip, x, id);
          if (0 > r)
          {
            return -1;
          }
          return -1;
        }
      }
    }
  }
  fl = *((u16 *) (ip + 6));
  if (fl & (~0x4000))
  {
    mf = (fl & 0x2000) ? (1) : (0);
    ip = (u8 *) TLobby__sub_80418C40(ip, (void *) hl, n, ip[8], *((u16 *) (ip + 4)), &src, fl & 0x1FFF, mf, id);
    if (ip == 0)
    {
      return 0;
    }
    n = 1;
  }
  else
  {
    ip = alloc_free_entry();
    if (ip == 0)
    {
      return -257;
    }
    *((s32 *) (ip + 4)) = (new_var2 = 0);
    *((s32 *) (ip + 8)) = tl;
    ((struct 
    {
      s16 v;
      u8 pad[10];
    } *) (ip + 0xc))[*((s32 *) (ip + 4))].v = hl;
    set_value_and_enable((ip + 0x10) + ((*((s32 *) (ip + 4))) * 12), (s32) ip);
    *((s32 *) (ip + 4)) += 1;
    ((struct 
    {
      s16 v;
      u8 pad[10];
    } *) (ip + 0xc))[*((s32 *) (ip + 4))].v = n;
    set_value_and_enable((ip + 0x10) + ((*((s32 *) (ip + 4))) * 12), (s32) (ip + hl));
    *((s32 *) (ip + 4)) += 1;
    n = 0;
  }
  switch (ip[9])
  {
    case 1:
      found = 1;
      r = TLobby__sub_8040CB44(ip, src.a, dst.a);
      if (r < 0)
    {
      if (n == 1)
      {
        TUdpSocket__sub_80418BD8((NetPacket *) ip);
      }
      release_entry(ip);
      return -1;
    }
      if (n == 1)
    {
      TUdpSocket__sub_80418BD8((NetPacket *) ip);
    }
      release_entry(ip);
      break;

    case 6:
      r = TLobby__sub_8041B974(ip, &src, &dst);
      if (r < 0)
    {
      if (n == 1)
      {
        TUdpSocket__sub_80418BD8((NetPacket *) ip);
      }
      release_entry(ip);
      return -1;
    }
      if (n == 1)
    {
      TUdpSocket__sub_80418BD8((NetPacket *) ip);
    }
      release_entry(ip);
      return 0;

    case 17:
      r = udp_input(ip, &src, &dst, id);
      if (r < 0)
    {
      switch (r)
      {
        case -2:
          ic.type = 3;
          ic.code = 3;
          ic.w = 0;
          rr = TUdpSocket__sub_8040CE58((u8 *) (&ic), ip, x, id);
          if (n == 1)
        {
          TUdpSocket__sub_80418BD8((NetPacket *) ip);
        }
          release_entry(ip);
          return rr;

        default:
          if (n == 1)
        {
          TUdpSocket__sub_80418BD8((NetPacket *) ip);
        }
          release_entry(ip);
          return -1;

      }

    }
      if (n == 1)
    {
      TUdpSocket__sub_80418BD8((NetPacket *) ip);
    }
      release_entry(ip);
      return 0;

    default:
      found = 0;
      break;

  }

  g = (u8 *) (&ipv4_protocol_state);
  p = *((u8 **) (g + 4));
  for (i = 0; i < (*((s16 *) g)); i++)
  {
    if ((*((u16 *) (p + 4))) == 1)
    {
      if (((*((u32 *) (p + 8))) == 0) || ((*((u32 *) (p + 8))) == src.a))
      {
        if ((*((u8 *) (p + 24))) == ip[9])
        {
          if ((*((u32 *) (p + 16))) != 0)
          {
            TLobby__sub_80421AD8(ip, src.a, dst.a, *((u32 *) (p + 16)), i);
            found = 1;
          }
        }
      }
    }
    p += 28;
  }

  if (found == 1)
  {
    if (n == 1)
    {
      TUdpSocket__sub_80418BD8((NetPacket *) ip);
    }
    release_entry(ip);
    return 0;
  }
  ic.type = 3;
  ic.code = 2;
  ic.w = 0;
  TUdpSocket__sub_8040CE58((u8 *) (&ic), ip, x, id);
  if (n == 1)
  {
    TUdpSocket__sub_80418BD8((NetPacket *) ip);
  }
  release_entry(ip);
  return -1;
}

s16 TUdpSocket__sub_8040E354(u8 *self, u32 key, u8 *pkt, s32 total)
{
  s16 TLobby__sub_8040EDE4(void *, u32, s16);
  s16 TLobby__sub_8040EF00(s16);
  u16 TUdpSocket__sub_80419864(void *, s16);
  s16 cnt8;
  u8 *rt;
  u32 s;
  u8 hdr;
  int fl;
  s16 off;
  s16 mtu;
  s16 ifidx;
  u8 *target;
  u8 *rec;
  u16 flagsHi;
  s16 units;
  s32 frag;
  s16 cnt;
  s16 rem;
  s32 hl;
  s32 df;
  u8 *payload;
  u16 t46;
  u16 t44;
  u16 g1[2];
  s16 t36;
  u16 t34;
  s16 r;
  u8 g2[10];
  s16 len;
  hdr = (pkt[0] << 2) & 0x3C;
  if (hdr == 20)
  {
    len = total - 20;
  }
  else
  {
    len = total - hdr;
  }
  if (len <= 0)
  {
    return -1;
  }
  NetMemcpy(&t46, pkt + 6, 2);
  frag = t46;
  flagsHi = frag & (~0x1FFF);
  t46 = flagsHi;
  df = frag & 0x4000;
  off = frag & 0xFF;
  if (((u8) (pkt[8] - 1)) < 1)
  {
    return -1;
  }
  pkt[8] = pkt[8] - 1;
  rt = TLobby__sub_8040F76C((u32) self, key);
  if (rt == 0)
  {
    return -6;
  }
  ifidx = *((s16 *) (rt + 2));
  if ((*((s16 *) (rt + 18))) == 1)
  {
    target = self;
  }
  else
  {
    target = *((u8 **) (rt + 12));
  }
  mtu = TLobby__sub_8040EF00(ifidx);
  if (mtu < 0)
  {
    return mtu;
  }
  if (mtu < (hdr + len))
  {
    if (df & 0xFF)
    {
      return -1;
    }
    rec = alloc_free_entry();
    if (rec == 0)
    {
      return -257;
    }
    rem = len;
    payload = pkt + hdr;
    units = (mtu - hdr) / 8;
    do
    {
      if (mtu > (rem + (hl = hdr)))
      {
        t46 = flagsHi;
        cnt8 = rem % 8;
        cnt = rem / 8;
        mtu = rem;
      }
      else
      {
        t46 |= 0x2000;
        cnt = units;
        cnt8 = 0;
      }
      t36 = off;
      t36 |= t46;
      NetMemcpy(pkt + 6, &t36, 2);
      fl = cnt8 + (cnt << 3);
      t34 = hl + fl;
      NetMemcpy(pkt + 2, &t34, 2);
      NetMemset(pkt + 10, 0, 2);
      s = TUdpSocket__sub_80419864(pkt, hl / 2);
      s = (s >> 16) + (s & 0xFFFF);
      s += s >> 16;
      t44 = ~s;
      NetMemcpy(pkt + 10, &t44, 2);
      *((s32 *) (rec + 4)) = 0;
      *((s32 *) (rec + 8)) = (u16) fl;
      *((s16 *) ((rec + ((*((s32 *) (rec + 4))) * 12)) + 12)) = fl;
      set_value_and_enable((rec + 0x10) + ((*((s32 *) (rec + 4))) * 12), (s32) payload);
      *((s32 *) (rec + 4)) += 1;
      *((s32 *) (rec + 8)) += hdr;
      *((s16 *) ((rec + ((*((s32 *) (rec + 4))) * 12)) + 12)) = hdr;
      set_value_and_enable((rec + 0x10) + ((*((s32 *) (rec + 4))) * 12), (s32) pkt);
      *((s32 *) (rec + 4)) += 1;
      r = TLobby__sub_8040EDE4(rec, (u32) target, ifidx);
      if (r < 0)
      {
        release_entry(rec);
        break;
      }
      off += cnt;
      payload += cnt << 3;
      hdr = 20;
      if (mtu == rem)
      {
        rem = 0;
      }
      else
      {
        rem = rem - fl;
      }
    }
    while (rem > 0);
    release_entry(rec);
  }
  else
  {
    NetMemset(pkt + 10, 0, 2);
    s = TUdpSocket__sub_80419864(pkt, hdr / 2);
    s = (s >> 16) + (s & 0xFFFF);
    s += s >> 16;
    t44 = ~s;
    NetMemcpy(pkt + 10, &t44, 2);
    rec = alloc_free_entry();
    if (rec == 0)
    {
      return -257;
    }
    *((s32 *) (rec + 4)) = 0;
    *((s32 *) (rec + 8)) = len;
    ((struct 
    {
      s16 v;
      u8 pad[10];
    } *) (rec + 0xc))[*((s32 *) (rec + 4))].v = len;
    set_value_and_enable((rec + 0x10) + ((*((s32 *) (rec + 4))) * 12), (s32) (pkt + hdr));
    *((s32 *) (rec + 4)) += 1;
    *((s32 *) (rec + 8)) += hdr;
    ((struct 
    {
      s16 v;
      u8 pad[10];
    } *) (rec + 0xc))[*((s32 *) (rec + 4))].v = hdr;
    set_value_and_enable((rec + 0x10) + ((*((s32 *) (rec + 4))) * 12), (s32) pkt);
    *((s32 *) (rec + 4)) += 1;
    r = TLobby__sub_8040EDE4(rec, (u32) target, ifidx);
    release_entry(rec);
  }
  return r;
}

#pragma push
#pragma opt_common_subs on
s16 TLobby__sub_8040E780(u8 *rec, u32 dst, u32 src, u8 ttl, u8 tos, u8 df, void *proto)
{
  s16 tot;
  u8 *g;
  u8 *ent;
  u8 *ip;
  u8 *target;
  s16 ifidx;
  s16 mtu;
  s32 idx;
  s16 chunk;
  s32 units;
  s16 rem;
  s32 off;
  s16 last;
  s32 k;
  s32 i2;
  u8 *data;
  u8 *p;
  u8 *q;
  s32 j;
  s16 *lp;
  s16 r;
  u8 *new_var;
  u32 s;
  s16 TLobby__sub_8040EF50(u32 *, u32, s16); /* declared s16 here; the definition returns s32 */
  s16 TLobby__sub_8040FDA0(u32, s16); /* declared s16 here; the definition returns s32 */
  s16 TLobby__sub_8040EF00(s16); /* declared s16 here; the definition returns s32 */
  s16 TLobby__sub_8040EDE4(void *, u32, s16); /* declared s16 here; the definition returns s32 */
  struct 
  {
    s64 a;
    u8 b[0x98];
  } loc;
  g = (u8 *) (&ipv4_protocol_state);
  ent = TLobby__sub_8040F76C(dst, src);
  if ((ent == 0) != 0)
  {
    return -6;
  }
  if (src == 0)
  {
    r = TLobby__sub_8040EF50(&src, *((u32 *) (ent + 12)), *((s16 *) (ent + 2)));
    if (r < 0)
    {
      return r;
    }
  }
  if (TLobby__sub_8040FDA0(src, *((s16 *) (ent + 2))) != 0)
  {
    r = TLobby__sub_8040EF50(&src, *((u32 *) (ent + 12)), *((s16 *) (ent + 2)));
    if (r < 0)
    {
      return r;
    }
  }
  ifidx = *((s16 *) (ent + 2));
  if ((*((s16 *) (ent + 18))) == 1)
  {
    target = (u8 *) dst;
  }
  else
  {
    target = *((u8 **) (ent + 12));
  }
  g[12] = 0x40;
  ip = g + 12;
  g[12] |= 5;
  if (tos != 0)
  {
    ip[1] = tos;
  }
  else
  {
    ip[1] = g[10];
  }
  if (ttl != 0)
  {
    ip[8] = ttl;
  }
  else
  {
    ip[8] = g[11];
  }
  tot = *((s32 *) (rec + 8));
  if (tot == 0)
  {
    return 0;
  }
  tot = tot + 20;
  *((s16 *) (ip + 2)) = tot;
  *((u16 *) (g + 8)) += 1;
  ip[9] = (u8) ((s32) proto);
  *((u16 *) (ip + 4)) = *((u16 *) (g + 8));
  NetMemcpy(ip + 12, &src, 4);
  NetMemcpy(ip + 16, &dst, 4);
  mtu = TLobby__sub_8040EF00(ifidx);
  if (mtu < 0)
  {
    return mtu;
  }
  if (tot <= mtu)
  {
    *((u16 *) (ip + 6)) = 0;
    if (df != 0)
    {
      *((u16 *) (ip + 6)) = 0x4000;
    }
    *((u16 *) (ip + 10)) = 0;
    if (!j)
    {
    }
    s = TUdpSocket__sub_80419864(ip, 10);
    s = (s >> 16) + (s & 0xFFFF);
    s += s >> 16;
    *((u16 *) (ip + 10)) = ~s;
    *((s32 *) (rec + 8)) += 20;
    ((struct 
    {
      s16 v;
      u8 pad[10];
    } *) (rec + 0xc))[*((s32 *) (rec + 4))].v = 20;
    set_value_and_enable((rec + 0x10) + ((*((s32 *) (rec + 4))) * 12), (s32) ip);
    *((s32 *) (rec + 4)) += 1;
    return TLobby__sub_8040EDE4(rec, (u32) target, ifidx);
  }
  off = 0;
  if (df != 0)
  {
    return -2;
  }
  chunk = (mtu - 20) / 8;
  chunk *= 8;
  units = chunk / 8;
  *((u16 *) (ip + 6)) = 0;
  ent = (u8 *) (&loc);
  do
  {
    *((s32 *) (ent + 4)) = 0;
    *((s32 *) (ent + 8)) = 0;
    rem = chunk;
    k = 0;
    j = (idx = (*((s32 *) (rec + 4))) - 1);
    p = rec + (j * 12);
    while ((rem > 0) && (j >= 0))
    {
      k++;
      p -= 12;
      rem -= *((s16 *) (p + 24));
      j--;
    }

    i2 = idx;
    j = (s16) k;
    j = j - 1;
    rem = chunk;
    last = 0;
    while ((rem > 0) && (j >= 0))
    {
      p = rec + (i2 * 12);
      q = ent + (((((((((((j * 12) & 0xFFFFFFFFFFFFFFFF) & 0xFFFFFFFFFFFFFFFF) & 0xFFFFFFFFFFFFFFFF) & 0xFFFFFFFFFFFFFFFF) & 0xFFFFFFFFFFFFFFFF) & 0xFFFFFFFFFFFFFFFF) & 0xFFFFFFFFFFFFFFFF) & 0xFFFFFFFFFFFFFFFF) & 0xFFFFFFFFFFFFFFFF) & 0xFFFFFFFFFFFFFFFF);
      data = p + 16;
      NetMemcpy(q + 16, data, 8);
      new_var = p + 12;
      lp = (s16 *) new_var;
      if ((*((s16 *) new_var)) > rem)
      {
        *((s16 *) (q + 12)) = rem;
        *((s32 *) (ent + 8)) += rem;
        *lp -= rem;
        *((s32 *) (rec + 8)) -= rem;
        TLobby__sub_80406EB8((NetBufferRef *)(data), rem);
        rem = 0;
      }
      else
      {
        *((s16 *) (q + 12)) = *((s16 *) new_var);
        *((s32 *) (ent + 8)) += *lp;
        *((s32 *) (rec + 8)) -= *lp;
        rem -= *lp;
        if (i2 == 0)
        {
          rem = *lp;
          last = 1;
          j--;
          i2--;
        }
        else
        {
          *((s32 *) (rec + 4)) -= 1;
          i2--;
          j--;
        }
      }
      *((s32 *) (ent + 4)) += 1;
    }

    if (last == 1)
    {
      *((u16 *) (ip + 6)) = 0;
    }
    else
    {
      *((u16 *) (ip + 6)) = 0x2000;
    }
    *((u16 *) (ip + 6)) |= off;
    *((u16 *) (ip + 2)) = (*((s32 *) (ent + 8))) + 20;
    *((u16 *) (ip + 10)) = 0;
    s = TUdpSocket__sub_80419864(ip, 10);
    s = (s >> 16) + (s & 0xFFFF);
    s += s >> 16;
    *((u16 *) (ip + 10)) = ~s;
    *((s32 *) (ent + 8)) += 20;
    *((s16 *) ((ent + ((*((s32 *) (ent + 4))) * 12)) + 12)) = 20;
    set_value_and_enable((ent + 0x10) + ((*((s32 *) (ent + 4))) * 12), (s32) ip);
    *((s32 *) (ent + 4)) += 1;
    r = TLobby__sub_8040EDE4(ent, (u32) target, ifidx);
    if (r < 0)
    {
      return r;
    }
    off += units;
  }
  while (last != 1);
  return 0;
}
#pragma pop
typedef struct PH_8040EC38 { s32 src; s32 dst; u8 zero; s8 proto; u16 len; } PH_8040EC38;
struct P_8040EC38 { u8 pad0[8]; s32 f8; s16 fC; };

u16 calc_pseudo_header_checksum(s32 src, s32 dst, s8 proto, void *pkt, s16 flag) {
    PH_8040EC38 ph;
    u32 sum;

    ph.src = src;
    ph.dst = dst;
    ph.zero = 0;
    ph.proto = proto;
    if (flag == 0) {
        ph.len = ((P_8040EC38 *)pkt)->f8 - ((P_8040EC38 *)pkt)->fC;
    } else {
        ph.len = ((P_8040EC38 *)pkt)->f8;
    }
    sum = TUdpSocket__sub_80419864(&ph, 6);
    sum += TLobby__sub_80406BD8(pkt, flag);
    sum = (sum >> 16) + (sum & 0xFFFF);
    sum += sum >> 16;
    return ~sum;
}

u16 calc_ip_checksum(void *self, s16 b) {
    u32 s = TLobby__sub_80406BD8(self, b);
    s = (s >> 16) + (s & 0xFFFF);
    s += (s >> 16);
    return ~s;
}

s32 TLobby__sub_8040ED28(void) {
    TLobby__sub_803F8958((void *)&ipv4_address_routing_state);
    ipv4_address_routing_state.nroutes = 0;
    ipv4_address_routing_state.nifaces = 0;
    ipv4_address_routing_state.max_aliases = 0;
    return 0;
}
s32 TLobby__sub_8040ED70(void) {
    init_buffer_descriptor_a(&ipv4_address_routing_state);
    NetMemset(ipv4_address_routing_state.routes, 0, ipv4_address_routing_state.nroutes * sizeof(Ipv4Route));
    /* Sized with Ipv4Route (0x14 bytes), not Ipv4Iface (0x1C): the last 8 bytes of each entry are not cleared. */
    NetMemset(ipv4_address_routing_state.ifaces, 0, ipv4_address_routing_state.nifaces * sizeof(Ipv4Route));
    NetMemset(ipv4_address_routing_state.alias_pool, 0, ipv4_address_routing_state.max_aliases * sizeof(Ipv4Alias));
    return 0;
}

inline s16 chk_8040EDE4(s16 id, u32 k) {
    s16 *p;
    p = get_active_entry_by_index(id);
    if (p == NULL) {
        return 0;
    }
    if (*(u32 *)((s8 *)p + 8) == 0 || k == 0xFFFFFFFF || k == *(u32 *)((s8 *)p + 0xC)) {
        return 1;
    }
    return 0;
}

extern s32 TLobby__sub_8040EDE4(void *self, u32 key, s16 id) {
    s16 *e;

    if (id < 0 || id >= ipv4_address_routing_state.nifaces) {
        return -0x109;
    }
    e = (s16 *)ipv4_address_routing_state.ifaces;
    e += id * 14;
    if (e[0] != 1) {
        return -6;
    }
    if (key == 0 || chk_8040EDE4(id, key)) {
        return call_handler_by_index(id, e[1], 1, (s32)&key, (s32)self);
    }
    return dispatch_handler_by_index(id, e[1], (s32)&key, (s32)self);
}
#pragma push
#pragma opt_common_subs on
s32 TLobby__sub_8040EF00(s16 arg0) {
    typedef struct Fields_temp_r3 { s16 field_0; u8 pad_2[2]; s16 field_4; } Fields_temp_r3;
    u8 *temp_r3;
    if ((arg0 < 0) || (arg0 >= ipv4_address_routing_state.nifaces)) {
        return -0x109;
    }
    temp_r3 = (u8 *)&ipv4_address_routing_state.ifaces[arg0];
    if ((s16) ((Fields_temp_r3*)temp_r3)->field_0 != 1) {
        return -2;
    }
    return ((Fields_temp_r3*)temp_r3)->field_4;
}
#pragma pop


inline s16 getfirst_8040F1A0(s16 *pn, Ipv4Iface **pb, u32 *out) {
    if (*pn <= 0) {
        return 0;
    }
    if ((*pb)->state != 1) {
        return 0;
    }
    *out = (*pb)->addr;
    return 1;
}

inline void drop_8040F1A0(Ipv4RoutingState *g, u32 k1, u32 k2) {
    s16 i;
    Ipv4Route *e;
    e = g->routes;
    for (i = 0; i < g->nroutes; i++, e++) {
            if ((e->flags & 1) && e->dst == k1 && e->gateway == k2 && (e->type & 1) == 1) {
            e->flags = 0;
            break;
        }
    }
}

extern s32 TLobby__sub_8040EF50(u32 *out, u32 mask, s16 c)
{
  s16 n;
  u32 new_var;
  u8 *tbl;
  u8 *new_var2;
  u8 *e;
  s16 i;
  u8 *node;
  u32 m;
  tbl = (u8 *) (&ipv4_address_routing_state);
  if ((c < 0) || (c >= (*((s16 *) (tbl + 0x2)))))
  {
    return -6;
  }
  e = (new_var2 = *((u8 **) (tbl + 0xc)));
  e += c * 0x1c;
  if ((*((s16 *) e)) == 1)
  {
    u32 a = *((u32 *) (e + 0x8));
    m = *((u32 *) (e + 0x14));
    if ((m & a) == (m & mask))
    {
      *out = a;
      return 0;
    }
    node = *((u8 **) (e + 0x18));
    n = *((s16 *) (tbl + 0x4));
    for (i = 0; (node != ((void *) 0)) && (i < n); i++)
    {
      m = *((u32 *) (0x10 + node));
      new_var = *((u32 *) (node + 0x4));
      if ((m & new_var) == (m & mask))
      {
        *out = new_var;
        return 0;
      }
      node = *((u8 **) (node + 0x14));
    }

  }
  return -6;
}

typedef struct Ipv4IfaceAddrRecord {
    s32 kind;
    u32 addr;
    u32 mask;
    u32 broadcast;
    u8 pad10[0xC];
} Ipv4IfaceAddrRecord;
typedef char Ipv4IfaceAddrRecord_size_check[sizeof(Ipv4IfaceAddrRecord) == 0x1C ? 1 : -1];
extern s32 TLobby__sub_8040F00C(s16 idx, NetBufferRef *out, s16 len, s32 arg3) {
    s16 TLobby__sub_80409EB0(s16 arg0, s32 arg1); /* declared s16 here; the definition returns s32 */
    Ipv4RoutingState *g = &ipv4_address_routing_state;
    Ipv4Iface *ifc;
    s16 n;
    s32 count;
    Ipv4Alias *alias;
    Ipv4IfaceAddrRecord rec;
    NetBufferRef ref;

    if (idx < 0 || idx >= g->nifaces) {
        return -0x109;
    }
    ifc = g->ifaces;
    ifc += idx;
    if (ifc->state != 1) {
        return -2;
    }
    if ((u32)len < sizeof(rec)) {
        return -2;
    }
    rec.kind = 4;
    rec.addr = ifc->addr;
    rec.mask = ifc->mask;
    rec.broadcast = ifc->broadcast;
    set_value_and_enable((&ref), (s32)&rec);
    TLobby__sub_80406FD8(out, &ref, sizeof(rec));
    TLobby__sub_80406EB8(out, sizeof(rec));
    alias = ifc->aliases;
    count = 1;
    n = 0;
    len -= sizeof(rec);
    while (len >= sizeof(rec) && alias != NULL && n < g->max_aliases) {
        rec.kind = 4;
        rec.addr = alias->addr;
        rec.mask = alias->mask;
        rec.broadcast = alias->broadcast;
        set_value_and_enable((&ref), (s32)&rec);
        TLobby__sub_80406FD8(out, &ref, sizeof(rec));
        TLobby__sub_80406EB8(out, sizeof(rec));
        alias = alias->next;
        count++;
        n++;
        len -= sizeof(rec);
    }
    if (TLobby__sub_80409EB0(idx, ifc->handle) <= 6) {
        TLobby__sub_80409E18(idx, ifc->handle, arg3);
    }
    return count;
}

extern s32 TLobby__sub_8040F1A0(s16 id) {
    Ipv4RoutingState *g;
    s16 *pn;
    Ipv4Iface **pb;
    s16 cnt;
    Ipv4Iface *b;
    Ipv4Alias *nd;
    u32 addr;
    s16 is_socket_flag_set(s16); /* declared s16 here; the definition returns s32 */
    g = &ipv4_address_routing_state;

    if (id < 0 || id >= *(pn = &g->nifaces)) {
        return -0x109;
    }
    b = *(pb = &g->ifaces);
    b += id;
    if (b->state != 1) {
        return 0;
    }
    nd = b->aliases;
    cnt = 0;
    while (nd != NULL && cnt < g->max_aliases) {
        if (is_socket_flag_set(id) == 0 && getfirst_8040F1A0(pn, pb, &addr)) {
            drop_8040F1A0(g, nd->addr, addr);
        }
        TLobby__sub_80409D7C(id, b->handle, 2, (s32)&nd->addr);
        {
            Ipv4Alias *next = nd->next;
            nd->f0 = 0;
            nd->addr = 0;
            nd->network = 0;
            nd->broadcast = 0;
            nd->mask = 0;
            nd->next = NULL;
            cnt++;
            nd = next;
        }
    }
    if (is_socket_flag_set(id) == 0 && getfirst_8040F1A0(pn, pb, &addr)) {
        drop_8040F1A0(g, b->addr, addr);
    }
    {
        Ipv4Route *e;
        s16 n;
        n = g->nroutes;
        e = g->routes;
        for (; n > 0; n--, e++) {
            if ((e->flags & 1) && e->iface == id) {
                e->flags = 0;
            }
        }
    }
    call_entry_callback(id, b->handle);
    b->state = 0;
    b->handle = 0;
    b->mtu = 0;
    b->addr = 0;
    b->network = 0;
    b->broadcast = 0;
    b->mask = 0;
    b->aliases = NULL;
    return 0;
}

#pragma push
#pragma opt_common_subs on
extern s16 TLobby__sub_8040F454(u32 addr, u32 mask, u32 broadcast, s16 idx) {
    Ipv4RoutingState *g = &ipv4_address_routing_state;
    s16 *pn;
    Ipv4Iface **pifs;
    s16 unspecified;
    Ipv4Iface *ifc;
    s16 r;
    s16 err;
    s16 found;
    u32 gateway;
    s16 is_socket_flag_set(s16); /* declared s16 here; the definition returns s32 */
    s16 invoke_socket_callback(s16, s32); /* declared s16 here; the definition returns s32 */
    s16 TLobby__sub_8040A044(s16, u32, s32, u32 *); /* declared s16 here; the definition returns s32 */

    if (idx < 0 || idx >= *(pn = &g->nifaces)) {
        return -0x109;
    }
    ifc = *(pifs = &g->ifaces);
    ifc += idx;
    if (ifc->state == 1) {
        return -2;
    }
    ifc->state = 1;
    ifc->handle = TLobby__sub_8040A044(idx, 0x800, 4, &addr);
    if (ifc->handle < 0) {
        ifc->state = 0;
        return ifc->handle;
    }
    if (addr == 0 && mask == 0xFFFFFFFF) {
        unspecified = 1;
    } else {
        unspecified = 0;
    }
    ifc->addr = addr;
    ifc->network = addr & mask;
    if (broadcast != 0) {
        ifc->broadcast = broadcast;
    } else {
        ifc->broadcast = ifc->network | ~mask;
    }
    ifc->mask = mask;
    r = invoke_socket_callback(idx, ifc->handle);
    if (r < g->min_mtu) {
        ifc->state = 0;
        return -6;
    }
    ifc->mtu = r;
    found = 0;
    ifc->aliases = NULL;
    gateway = 0xFFFFFFFF;
    if (is_socket_flag_set(idx) == 0 && !unspecified) {
        found = getfirst_8040F1A0(pn, pifs, &gateway);
        if (found) {
            found = NetIPv4AddRoute(addr, 0xFFFFFFFF, gateway, 0, 1, 0);
            if (found < 0) {
                call_entry_callback(idx, ifc->handle);
                ifc->state = 0;
                ifc->handle = 0;
                ifc->mtu = 0;
                ifc->addr = 0;
                ifc->network = 0;
                ifc->broadcast = 0;
                ifc->mask = 0;
                return found;
            }
        }
    }
    err = NetIPv4AddRoute(addr & mask, mask, addr, 0, 1, 0);
    if (err < 0) {
        if (is_socket_flag_set(idx) == 0 && gateway != 0xFFFFFFFF && !unspecified) {
            drop_8040F1A0(g, addr, gateway);
        }
        call_entry_callback(idx, ifc->handle);
        ifc->state = 0;
        ifc->handle = 0;
        ifc->mtu = 0;
        ifc->addr = 0;
        ifc->network = 0;
        ifc->broadcast = 0;
        ifc->mask = 0;
        return err;
    }
    return 0;
}
#pragma pop
s32 is_lookup_found(u32 arg0, u32 arg1) {
    if (TLobby__sub_8040F76C(arg0, arg1) != NULL) {
        return 1;
    }
    return 0;
}

u8 * TLobby__sub_8040F76C(a0, a1)
u32 a0;
u32 a1;
{
    u32 t;
    u16 flags;
    s16 i;
    u8 *e;
    u8 *m1;
    u8 *m2;
    u8 *m3;

    m1 = NULL;
    m2 = NULL;
    m3 = NULL;
    e = (u8 *)ipv4_address_routing_state.routes;
    for (i = 0; i < ipv4_address_routing_state.nroutes; i++, e += 0x14) {
        flags = *(u16 *)e;
        t = a0 & *(u32 *)(e + 8);
        if (!(flags & 1)) {
            continue;
        }
        if ((flags & 4) && *(u32 *)(e + 4) == a0) {
            return e;
        }
        if ((flags & 8) && *(s16 *)(e + 0x12) == 1) {
            if (a0 == 0xFFFFFFFF || a0 == 0) {
                if (*(u32 *)(e + 0xC) == a1) {
                    m1 = e;
                    continue;
                }
            } else if (*(u32 *)(e + 4) == t) {
                m1 = e;
                continue;
            }
        }
        if (!(flags & 2)) {
            continue;
        }
        if (*(u32 *)(e + 4) == 0) {
            if (m3 == NULL) {
                m3 = e;
            }
        } else if (*(u32 *)(e + 4) == t) {
            if (m2 == NULL) {
                m2 = e;
            }
        }
    }
    if (m1 != NULL) {
        return m1;
    }
    if (m2 != NULL) {
        return m2;
    }
    if (m3 != NULL) {
        return m3;
    }
    return NULL;
}

extern s32 TLobby__sub_8040F8A4(u32 a1, void *a2, u32 a3, u32 a4, u32 a5)
{
  Ipv4RoutingState *tbl = &ipv4_address_routing_state;
  u32 new_var;
  u16 f;
  s16 i;
  s16 found = 0;
  RtEntry_8040F8A4 *e;
  s16 NetIPv4AddRoute(void *, void *, void *, int, int, int); /* declared here with other parameter types; the definition is s16 (u32, u32, u32, s16, u8, u16) */
  for (i = 0, e = (RtEntry_8040F8A4 *)tbl->routes; i < tbl->nroutes; i++, e++)
  {
    if (!(e->flags & 1))
    {
      continue;
    }
    if (e->owner != a5)
    {
      continue;
    }
    new_var = e->id;
    if (new_var == 0)
    {
      a4 |= 2;
      found = 1;
      continue;
    }
    f = (u16) a4;
    if (a4 & 4)
    {
      if (((!e->flags) & 4) || (new_var != a1))
      {
        continue;
      }
      e->flags = f | 0x20;
      e->owner = (u32) a2;
      return 0;
    }
    if (e->flags & 4)
    {
      continue;
    }
    if ((a1 & e->mask) != (new_var & a3))
    {
      continue;
    }
    e->flags = f | 0x10;
    e->owner = (u32) a2;
    return 0;
  }

  if (found != 0)
  {
    if (NetIPv4AddRoute((void *) a1, (void *) a3, a2, 1, 2, a4) != 0)
    {
      return -1;
    }
  }
  return 0;
}

extern s32 TLobby__sub_8040F9CC(void *a, void *unused, void *b, s32 flag) {
    Ipv4RoutingState *tbl = &ipv4_address_routing_state;
    Unk805BDD60Entry *e = (Unk805BDD60Entry *)tbl->routes;
    s16 i;
    u8 f = (u8)flag & 1;
    for (i = 0; i < tbl->nroutes; i++, e++) {
        if (!(e->flags & 1)) {
            continue;
        }
        if (e->f4 != (u32)a) {
            continue;
        }
        if (e->fC != (u32)b) {
            continue;
        }
        if (f != (e->f12 & 1)) {
            continue;
        }
        e->flags = 0;
        return 0;
    }
    return -2;
}

inline s16 trk_find1(u8 *p, s16 cntB, s16 cntC, u32 a)
{
    u8 *node;
    s16 i;
    s16 j;

    for (i = 0; i < cntB; i++, p += 0x1c) {
        if (*(s16 *)p == 1) {
            if (*(u32 *)(p + 8) == a) {
                return i;
            }
            node = *(u8 **)(p + 0x18);
            j = 0;
            while (node != 0 && j < cntC) {
                if (*(u32 *)(node + 4) == a) {
                    return i;
                }
                node = *(u8 **)(node + 0x14);
                j++;
            }
        }
    }
    return -1;
}

inline s16 trk_find2(u8 *p, s16 cntB, s16 cntC, u32 a)
{
    u8 *node;
    s16 i;
    s16 j;

    for (i = 0; i < cntB; i++, p += 0x1c) {
        if (*(s16 *)p == 1) {
            if (*(u32 *)(p + 0x10) == (*(u32 *)(p + 0x14) & a)) {
                return i;
            }
            node = *(u8 **)(p + 0x18);
            j = 0;
            while (node != 0 && j < cntC) {
                if (*(u32 *)(node + 0xC) == (*(u32 *)(node + 0x10) & a)) {
                    return i;
                }
                node = *(u8 **)(node + 0x14);
                j++;
            }
        }
    }
    return -1;
}

inline s16 find_iface_by_addr_8040FA48(Ipv4Iface *ifaces, s16 n, s16 m, u32 addr) {
    s16 i;
    s16 j;
    Ipv4Iface *ifc;
    Ipv4Alias *a;

    ifc = ifaces;

    for (i = 0; i < n; i++, ifc++) {
        if (ifc->state == 1) {
            if (ifc->addr == addr) {
                return i;
            }
            for (a = ifc->aliases, j = 0; a != NULL && j < m; j++) {
                if (a->addr == addr) {
                    return i;
                }
                a = a->next;
            }
        }
    }
    return -1;
}
inline s16 find_iface_by_network_8040FA48(Ipv4Iface *ifaces, s16 n, s16 m, u32 addr) {
    s16 i;
    s16 j;
    Ipv4Iface *ifc;
    Ipv4Alias *a;

    ifc = ifaces;

    for (i = 0; i < n; i++, ifc++) {
        if (ifc->state == 1) {
            if (ifc->network == (ifc->mask & addr)) {
                return i;
            }
            for (a = ifc->aliases, j = 0; a != NULL && j < m; j++) {
                if (a->network == (a->mask & addr)) {
                    return i;
                }
                a = a->next;
            }
        }
    }
    return -1;
}
inline Ipv4Iface *get_ifaces_8040FA48(Ipv4RoutingState *g) {
    return g->ifaces;
}
#pragma push
#pragma opt_common_subs on
s16 NetIPv4AddRoute(u32 dst, u32 mask, u32 gateway, s16 f10, u8 type, u16 flags) {
    Ipv4RoutingState *g = &ipv4_address_routing_state;
    Ipv4Iface *ifaces;
    s16 m;
    s16 n;
    s16 idx;
    s16 i;
    Ipv4Route *e;
    Ipv4Route *slot;

    ifaces = get_ifaces_8040FA48(g);
    m = g->max_aliases;
    n = g->nifaces;
    idx = find_iface_by_addr_8040FA48(ifaces, n, m, gateway);
    if (idx < 0) {
        idx = find_iface_by_network_8040FA48(ifaces, n, m, gateway);
        if (idx < 0) {
            return -2;
        }
    }
    e = g->routes;
    slot = NULL;
    for (i = 0; i < g->nroutes; i++, e++) {
        if (e->flags & 1) {
            if (e->dst == dst && (dst != 0 || mask != 0 || gateway != 0 || type != 1)) {
                return -2;
            }
        } else {
            slot = e;
            break;
        }
    }
    if (slot == NULL) {
        return -0x107;
    }
    slot->dst = dst;
    slot->gateway = gateway;
    slot->type = type;
    slot->f10 = f10;
    slot->iface = idx;
    switch (type) {
    case 1:
        if (mask == 0xFFFFFFFF) {
            slot->flags = 0xD;
        } else {
            slot->flags = 9;
        }
        slot->mask = mask;
        break;
    case 2:
        slot->flags = flags | 1;
        if (flags & 4) {
            slot->mask = 0xFFFFFFFF;
        } else {
            slot->mask = mask;
        }
        break;
    case 3:
        slot->flags = 0xB;
        slot->mask = mask;
        break;
    default:
        if (mask == 0xFFFFFFFF) {
            slot->flags = 0xF;
        } else {
            slot->flags = 0xB;
        }
        slot->mask = mask;
        break;
    }
    return 0;
}
#pragma pop


s16 TLobby__sub_8040FCEC(u32 ip) {
    Ipv4RoutingState *g;
    s16 m;
    s16 n;
    s16 i;
    s16 j;
    Ipv4Iface *e;
    Ipv4Alias *a;

    g = &ipv4_address_routing_state;
    e = g->ifaces;
    i = 0;
    m = g->max_aliases;
    n = g->nifaces;

    for (; i < n; i++, e++) {
        if (e->state == 1) {
            if (e->addr == ip) {
                return i;
            }
            for (a = e->aliases, j = 0; a != NULL && j < m; j++) {
                if (a->addr == ip) {
                    return i;
                }
                a = a->next;
            }
        }
    }
    return -1;
}

s32 NetIPv4IsLoopback(s32 arg0) {
    if ((u32) ((arg0 & 0xFF000000) + 0x81000000) == 0U) {
        return 1;
    }
    return 0;
}


s32 TLobby__sub_8040FDA0(u32 arg0, s16 arg1) {
    Ipv4Iface *e;
    if (arg1 < 0 || arg1 >= ipv4_address_routing_state.nifaces) {
        e = NULL;
    } else {
        e = ipv4_address_routing_state.ifaces;
        e += arg1;
        if (e->state != 1) {
            e = NULL;
        }
    }
    if (e == NULL) {
        return 0;
    }
    if (e->addr == 0 || arg0 == 0xFFFFFFFF || arg0 == e->broadcast) {
        return 1;
    }
    return 0;
}

s32 NetIPv4IsUnspecified(u32 arg0) {
    if (arg0 == 0U) {
        return 1;
    }
    return 0;
}

#pragma push
#pragma opt_common_subs on
s32 TLobby__sub_8040FE40(s16 arg0) {
    typedef struct Fields_var_r3 { s16 field_0; } Fields_var_r3;
    s16 *var_r3;
    if ((arg0 < 0) || (arg0 >= ipv4_address_routing_state.nifaces)) {
        var_r3 = (s16 *)(NULL);
    } else {
        var_r3 = (s16 *)&ipv4_address_routing_state.ifaces[arg0];
        if ((s16) ((Fields_var_r3*)var_r3)->field_0 != 1) {
            var_r3 = (s16 *)(NULL);
        }
    }
    if (var_r3 != NULL) {
        return 1;
    }
    return 0;
}
#pragma pop

#pragma push
#pragma opt_common_subs on
s16 *get_active_entry_by_index(s16 arg0) {
    s16 *temp_r3;
    if ((arg0 < 0) || (arg0 >= ipv4_address_routing_state.nifaces)) {
        return NULL;
    }
    temp_r3 = (s16 *)&ipv4_address_routing_state.ifaces[arg0];
    if ((s16) *temp_r3 != 1) {
        return NULL;
    }
    return temp_r3;
}
#pragma pop

s32 TLobby__sub_8040FEE4(s32 arg0, s32 arg1) {
    s32 temp_r0;
    temp_r0 = arg0 - arg1;
    if (temp_r0 < 0) {
        return -1;
    }
    if (temp_r0 > 0) {
        return 1;
    }
    return 0;
}
s32 NetIPv6Shutdown(void) {
    release_slot_by_id(0x86DD);
    TLobby__sub_803F87DC(&ipv6_protocol_state);
    ipv6_protocol_state.nsockets = 0;
    return 0;
}

s32 TLobby__sub_8040FFF8(u8 *ip, int len, s16 id);
s32 NetIPv6Init(void) {
    s16 i;
    Ipv6RawSocket *e;
    Ipv6ProtocolState *g = &ipv6_protocol_state;

    init_ipv6_interface_config(g);
    e = g->sockets;
    for (i = 0; i < g->nsockets; i++) {
        e->tag[0] = 'I';
        e->tag[1] = 'P';
        e->tag[2] = '6';
        e->index = i;
        e->used = 0;
        e++;
    }
    g->ident = 1;
    register_protocol_handler(0x86DD, (NetProtocolHandler)TLobby__sub_8040FFF8);
    return 0;
}

inline s16 opts_8040FFF8(u8 *p, s16 rem, u8 *ip, s16 m, s16 id) {
    s16 TLobby__sub_80410958(u8 *, s16, u8 *, s16, s16);
    s16 n;
    u8 *d;
    d = p + 2;
    n = ((p[1] + 1) << 3) - 2;
    if (n > rem) {
        return -1;
    }
    if (TLobby__sub_80410958(d, n, ip, m, id) < 0) {
        return -1;
    }
    return 0;
}

struct IC_8040FFF8 { u8 type; u8 code; s32 w; };
inline u8 *frag_8040FFF8(u8 *ip, u8 *p, s32 rem, s16 m, s16 id, void *sa, struct IC_8040FFF8 *ic) {
    s32 TLobby__sub_80418C40(u8 *, u8 *, s16, u8, u32, void *, u16, u8, s16);
    u32 fl;
    u32 mf;
    u32 off;
    fl = *((u16 *) (p + 2));
    mf = fl & 1;
    off = (fl >> 3) & 0x1FFF;
    if (((u8) fl & 1) && (((rem - 8) & 7) != 0)) {
        if (off == 0) {
            ic->type = 4;
            ic->code = 0;
            ic->w = 4;
            TLobby__sub_8040D510(ic, ip, m, id);
        }
        return 0;
    }
    return (u8 *) TLobby__sub_80418C40(ip, (u8 *) (m - (rem - 8)), rem - 8, 60, *((u32 *) (p + 4)), sa, off, mf, id);
}
inline s32 min_8040FFF8(s32 a, s32 b) {
    if (a < b) {
        return a;
    }
    return b;
}

inline u8 *buildrec_8040FFF8(u8 *ip, s16 m, u8 *p, s32 rem) {
    u8 *rec = alloc_free_entry();
    if (rec == 0) {
        return 0;
    }
    *(s32 *)(rec + 4) = 0;
    *(s32 *)(rec + 8) = m;
    ((struct { u16 v; u8 pad[10]; } *)(rec + 0xc))[*(s32 *)(rec + 4)].v = m - rem;
    set_value_and_enable(rec + 0x10 + *(s32 *)(rec + 4) * 12, (s32)ip);
    *(s32 *)(rec + 4) += 1;
    ((struct { u16 v; u8 pad[10]; } *)(rec + 0xc))[*(s32 *)(rec + 4)].v = rem;
    set_value_and_enable(rec + 0x10 + *(s32 *)(rec + 4) * 12, (s32)p);
    *(s32 *)(rec + 4) += 1;
    return rec;
}

#pragma push
#pragma opt_loop_invariants off
s32 TLobby__sub_8040FFF8(u8 *ip, int len, s16 id)
{
  s16 TLobby__sub_8040D510(void *, u8 *, s32, s16); /* declared here with an s32 3rd argument; the definition takes s16 */
  s16 TLobby__sub_804105E0(u8 *, u8 *, s16, s16); /* declared s16 here; the definition returns s32 */
  s16 TLobby__sub_804136CC(s16); /* declared s16 here; the definition returns void */
  s16 TLobby__sub_804136EC(void *); /* declared s16 here; the definition returns s32 */
  s16 NetIPv6IsMulticast(u8 *); /* declared s16 here; the definition returns s32 */
  s16 NetIPv6IsUnspecified(u8 *); /* declared s16 here; the definition returns s32 */
  s16 NetIPv6CompareAddresses(void *, void *); /* declared s16 here; the definition is s32 (s32, s32) */
  s16 TLobby__sub_8041B974(void *, void *, void *); /* declared s16 here; the definition is s32 (u8 *, u8 *, u8 *) */
  s16 udp_input(void *, void *, void *, s16); /* declared s16 here; the definition is s32 (O_80420DE4 *, NetworkAddress *, NetworkAddress *, s32) */
  s32 TLobby__sub_80421938(void *, void *, void *, u32, s16); /* declared here with other parameter types; the definition is s32 (O_80421938 *, void *, void *, void *, s32) */
  struct 
  {
    s32 t;
    u8 a[16];
  } sa;
  struct 
  {
    s32 t;
    u8 a[16];
  } da;
  struct 
  {
    u8 type;
    u8 code;
    s32 w;
  } ic44;
  struct 
  {
    u8 type;
    u8 code;
    s32 w;
  } ic36;
  struct IC_8040FFF8 ic28;
  u8 *p;
  u8 *new_var2;
  u8 *rec;
  s16 m;
  Ipv6RawSocket *ent;
  s16 i;
  s32 rem;
  u8 *new_var4;
  u8 *new_var3;
  s16 new_var;
  s16 res;
  u8 *last;
  s16 reasm;
  Ipv6ProtocolState *g;
  u8 *src;
  u8 nh;
  s16 r;
  s16 found;
  u8 *dst;
  new_var = id;
  if (((s16) len) < 40)
  {
    goto ret;
  }
  if (get_valid_entry(new_var) == 0)
  {
    goto ret;
  }
  if ((ip[0] & 0xF0) != 0x60)
  {
    return -1;
  }
  m = min_8040FFF8((*((u16 *) (ip + 4))) + 40, (s16) len);
  if (TLobby__sub_804136CC(new_var) == 0)
  {
    if (TLobby__sub_804136EC(ip + 24) < ((char) 0))
    {
      if (NetIPv6IsMulticast(ip + 24) == 0)
      {
        if (TLobby__sub_804105E0(ip, ip, m, new_var) == 0)
        {
          return 0;
        }
        return -1;
      }
    }
  }
  sa.t = 6;
  new_var3 = ip + 8;
  src = sa.a;
  NetMemcpy(src, new_var3, 16);
  da.t = 6;
  dst = da.a;
  NetMemcpy(dst, ip + 24, 16);
  nh = ip[6];
  rem = m - 40;
  new_var2 = ip;
  p = new_var2 + 40;
  last = new_var2 + 6;
  reasm = 0;
  new_var4 = dst;
  found = 0;
  for (;;)
  {
    if (nh == 59)
    {
      return 0;
    }
    if (((s16) rem) < 8)
    {
      ic44.type = 4;
      ic44.code = 1;
      ic44.w = last - new_var2;
      TLobby__sub_8040D510(&ic44, new_var2, m, new_var);
      goto ret;
    }
    switch (nh)
    {
      case 0:
        if (m != (((s16) rem) + 40))
      {
        ic36.type = 4;
        ic36.code = 1;
        ic36.w = last - new_var2;
        TLobby__sub_8040D510(&ic36, new_var2, m, new_var);
        res = -1;
      }
      else
      {
        res = opts_8040FFF8(p, rem, new_var2, m, new_var);
      }
        if (res < 0)
      {
        goto ret;
      }
        goto adv;

      case 1:

      case 4:

      case 50:

      case 51:

      case 44:
        rec = frag_8040FFF8(new_var2, p, rem, m, new_var, &sa, &ic28);
        if (rec == 0)
      {
        return -1;
      }
        nh = p[0];
        reasm = 1;
        goto payload;

      case 60:
        res = opts_8040FFF8(p, rem, new_var2, m, new_var);
        if (res < 0)
      {
        goto ret;
      }

      case 43:
        adv:
      last = p;

        nh = p[0];
        rem -= (p[1] + 1) << 3;
        p += (p[1] + 1) << 3;
        continue;

      case 10:

      case 20:

      case 30:

      case 40:
        break;

    }

    break;
  }

  payload:
  if (reasm == 0)
  {
    rec = buildrec_8040FFF8(new_var2, m, p, rem);
    if (rec == 0)
    {
      return -257;
    }
  }

  switch (nh)
  {
    case 58:
      r = NetIPv6HandleIcmpMessage((NetPacket *)(rec), src, dst, new_var2[7], new_var);
      if (r < 0)
    {
      goto fail;
    }
      found = 1;
      break;

    case 6:
      r = TLobby__sub_8041B974(rec, &sa, &da);
      if (r < 0)
    {
      goto fail;
    }
      goto ok;

    case 17:
      r = udp_input(rec, &sa, &da, new_var);
      if (r >= 0)
    {
      goto ok;
    }
      switch (r)
    {
      case -2:
        ic44.type = 1;
        ic44.code = 4;
        ic44.w = 0;
        TLobby__sub_8040D510(&ic44, new_var2, m, new_var);
        goto fail;

      default:
        goto fail;

    }

    default:
      break;

  }

  g = &ipv6_protocol_state;
  ent = g->sockets;
  for (i = 0; i < g->nsockets; i++)
  {
    if (((ent->used == 1) && (ent->proto == nh)) && (ent->owner != 0))
    {
      if ((NetIPv6IsUnspecified(ent->local) != 0) || (NetIPv6CompareAddresses(ent->local, src) == 0))
      {
        if ((NetIPv6IsUnspecified(ent->remote) != 0) || (NetIPv6CompareAddresses(ent->remote, new_var4) == 0))
        {
          TLobby__sub_80421938(rec, src, dst, ent->owner, i);
          found = 1;
        }
      }
    }
    ent++;
  }

  if (found == 1)
  {
    ok:
    if (reasm == 1)
    {
      TUdpSocket__sub_80418BD8((NetPacket *) rec);
    }

    release_entry(rec);
    return 0;
  }
  if (reasm != 1)
  {
    ic44.type = 4;
    ic44.code = 1;
    ic44.w = last - new_var2;
    TLobby__sub_8040D510(&ic44, new_var2, m, new_var);
  }
  fail:
  if (reasm == 1)
  {
    TUdpSocket__sub_80418BD8((NetPacket *) rec);
  }

  release_entry(rec);
  ret:
  return -1;

}
#pragma pop

extern s32 TLobby__sub_80410958(u8* p, s16 n, u8* self, s16 c, s16 d);
static inline s16 chk_804105E0(u8 *p, s16 lim, s16 ctx, s16 l, s16 rem, u8 *q, u8 *prev) {
    s16 TLobby__sub_80410958(u8 *, s16, u8 *, s16, s16);
    u8 err4[8];
    s32 n;
    u8 *d;
    if (l != rem + 0x28) {
        err4[0] = 4;
        err4[1] = 1;
        *(s32 *)(err4 + 4) = prev - p;
        TLobby__sub_8040D510(err4, p, lim, ctx);
        return -1;
    }
    d = q + 2;
    n = ((q[1] + 1) << 3) - 2;
    if ((s16)n > rem) {
        return -1;
    }
    if (TLobby__sub_80410958(d, n, p, lim, ctx) < 0) {
        return -1;
    }
    return 0;
}
#pragma push
#pragma opt_common_subs on
#pragma opt_propagation off
extern s32 TLobby__sub_804105E0(u8 *self, u8 *p, s16 lim, s16 ctx)
{
  s32 TLobby__sub_80410BA8(void *, void *, s16, void *); /* declared s32 here; the definition returns s16 */
  s32 TLobby__sub_80415D0C(u8 *a, u8 *b, u8 *c, s16 d); /* declared s32 here; the definition is s16 (NetPacket *, u8 *, NetIPv6SendParameters *, s16) */
  s16 NetIPv6IsMulticast(u8 *); /* declared s16 here; the definition returns s32 */
  s16 TLobby__sub_804136AC(s16); /* declared s16 here; the definition returns s32 */
  u8 loc[8];
  u8 out2[0x10];
  u8 out1[0x10];
  u8 err[8];
  s32 tot;
  u8 *e;
  s16 rem;
  u8 *q;
  Ipv6Route *hit;
  u8 *new_var;
  u8 *prev;
  s16 l;
  s16 flag;
  s16 h6;
  u16 flags;
  u8 state;
  u8 *dst;
  s32 adv;
  s32 r21;
  l = lim;
  tot = l - 0x28;
  new_var = &loc[6];
  rem = tot;
  q = p + 0x28;
  prev = p + 6;
  flag = 0;
  *((s32 *) loc) = *((s32 *) self);
  *((u16 *) (loc + 4)) = *((u16 *) self);
  loc[7] = self[6];
  state = self[7];
  loc[6] = state;
  state = self[6];
  while (rem >= 8)
  {
    switch (state)
    {
      case 0:
        if (chk_804105E0(p, lim, ctx, l, rem, q, prev) < 0)
      {
        return -1;
      }
        prev = q;
        state = q[0];
        adv = (q[1] + 1) << 3;
        rem -= adv;
        q += adv;
        break;

      case 0x2c:
        flags = (*((u16 *) (q + 2))) & 0xFFF8;
        flag = 1;

      default:
        rem = 0;
        break;

    }

  }

  if (((*new_var) == 0) || ((--loc[6]) == 0))
  {
    if ((flag == 0) || (flags == 0))
    {
      err[0] = 3;
      err[1] = 0;
      *((s32 *) (err + 4)) = 0;
      TLobby__sub_8040D510(err, p, lim, ctx);
    }
    return -1;
  }
  hit = TLobby__sub_80413264(self + 0x18, self + 8);
  if (hit == ((void *) 0))
  {
    if ((flag == 0) || (flags == 0))
    {
      err[0] = 1;
      err[1] = 0;
      *((s32 *) (err + 4)) = 0;
      TLobby__sub_8040D510(err, p, lim, ctx);
    }
    return -1;
  }
  switch (hit->type)
  {
    case 1:
      dst = self + 0x18;
      break;

    case 2:

    case 3:
      dst = hit->gateway;
      break;

  }

  if (lim > (h6 = get_iface_mtu(hit->iface)))
  {
    if ((flag == 0) || (flags == 0))
    {
      err[0] = 2;
      err[1] = 0;
      *((s32 *) (err + 4)) = h6;
      TLobby__sub_8040D510(err, p, lim, ctx);
    }
    return -1;
  }
  e = alloc_free_entry();
  if (e == ((void *) 0))
  {
    return -1;
  }
  *((s32 *) (e + 4)) = 0;
  *((s32 *) (e + 8)) = tot;
  ((struct 
  {
    s16 v;
    u8 pad[10];
  } *) (e + 0xc))[*((s32 *) (e + 4))].v = (s16) tot;
  set_value_and_enable((void *) ((e + ((*((s32 *) (e + 4))) * 12)) + 0x10), (s32) (p + 0x28));
  *((s32 *) (e + 4)) = (*((s32 *) (e + 4))) + 1;
  NetMemcpy(out1, self + 8, 0x10);
  NetMemcpy(out2, self + 0x18, 0x10);
  if ((NetIPv6IsMulticast(dst) == 0) && (TLobby__sub_804136AC(hit->iface) != 0))
  {
    r21 = TLobby__sub_80415D0C(e, dst, out1, hit->iface);
  }
  else
  {
    r21 = TLobby__sub_80410BA8(e, out1, hit->iface, 0);
  }
  release_entry((void *) e);
  return r21;
}
#pragma pop
s32 TLobby__sub_80410958(u8* p, s16 n, u8* self, s16 c, s16 d) {
    s16 NetIPv6IsMulticast(void*);
    u8* cur = p;
    s32 len;

    while (n > 0) {
        switch (*cur) {
        case 0:
            n--;
            cur++;
            break;
        case 1:
            len = cur[1] + 2;
            n -= len;
            cur += len;
            break;
        default:
            switch (*cur & 0xC0) {
            case 0x00:
                len = cur[1] + 2;
                n -= len;
                cur += len;
                break;
            case 0xC0:
                if (NetIPv6IsMulticast(self + 0x18)) {
                    return -1;
                }
                /* fallthrough */
            case 0x80: {
                struct {
                    u8 a;
                    u8 b;
                    u8 pad[2];
                    u32 c;
                } msg;

                msg.a = 4;
                msg.b = 2;
                msg.c = cur - self;
                TLobby__sub_8040D510(&msg, self, c, d);
            }
            case 0x40:
            default:
                return -1;
            }
            break;
        }
    }
    if (n != 0) {
        return -1;
    }
    return 0;
}

s32 TLobby__sub_80410A98(s32 arg0, void *arg1, void *arg2, void *arg3, void *arg4)
{
    s32 TLobby__sub_80410BA8(void *, void *, s16, void *); /* declared s32 here; the definition returns s16 */
  u8 tmp[12];
  volatile struct 
  {
    s32 x;
    s16 h;
    u8 y;
    u8 d;
  } rec;
  u8 *new_var;
  u8 buf2[16];
  u8 buf1[16];
  Ipv6Route *p;
  u8 *q;
  s16 NetIPv6IsMulticast(u8 *); /* declared s16 here; the definition returns s32 */
  s16 TLobby__sub_804136AC(s16); /* declared s16 here; the definition returns s32 */
  s32 TLobby__sub_80415D0C(NetPacket *, u8 *, NetIPv6SendParameters *, s16); /* declared s32 here; the definition returns s16 */
  p = TLobby__sub_80413264(arg1, arg2);
  if (p == ((void *) 0))
  {
    return -6;
  }
  if (p->type == 1)
  {
    q = (u8 *) arg1;
  }
  else
  {
    q = p->gateway;
  }
  if (arg3 == ((void *) 0))
  {
    NetMemset(tmp, 0, 0xc);
    arg3 = tmp;
  }
  rec.x = *((s32 *) (((u8 *) arg3) + 4));
  new_var = q;
  rec.h = ((u8 *) arg3)[0];
  rec.y = ((u8 *) arg3)[8];
  rec.d = (u8) ((s32) arg4);
  NetMemcpy(buf1, arg2, 0x10);
  NetMemcpy(buf2, arg1, 0x10);
  if ((!NetIPv6IsMulticast(q)) && TLobby__sub_804136AC(p->iface))
  {
    return TLobby__sub_80415D0C((NetPacket *) arg0, new_var, (NetIPv6SendParameters *) buf1, p->iface);
  }
  return TLobby__sub_80410BA8((void *) arg0, buf1, p->iface, (void *) 0);
}

s16 TLobby__sub_80410D6C(u8 *ctx, u8 *hdr, s16 a5, s32 a6, u32 len);
s16 TLobby__sub_80410BA8(void *self, void *a, s16 c, void *d)
{
  s16 TLobby__sub_804112B8(s32, s32, s16); /* declared s16 here; the definition returns s32 */
  s16 TLobby__sub_8041123C(s32, s32, s16); /* declared s16 here; the definition returns s32 */
  s16 NetIPv6IsMulticast(void *); /* declared s16 here; the definition is s32 (u8 *) */
  Ipv6ProtocolState *base = &ipv6_protocol_state;
  s32 new_var;
  u32 used = ((NetPacket *) self)->total_bytes;
  Ipv6Header *slot = &base->hdr;
  s32 n;
  s32 off;
  s16 ret;
  s32 pad2[2];
  if (used == 0)
  {
    return 0;
  }
  slot->version_class_flow = 0;
  if (((NetIPv6SendParameters *) a)->flow_label)
  {
    slot->version_class_flow = (((NetIPv6SendParameters *) a)->flow_label) & 0xFFFFF;
  }
  else
  {
    slot->version_class_flow = base->flow_label;
  }
  if (((NetIPv6SendParameters *) a)->traffic_class_bits)
  {
    *((u16 *) slot) |= (((NetIPv6SendParameters *) a)->traffic_class_bits) & 0xFF0;
  }
  else
  {
    *((u16 *) slot) |= base->traffic_class;
  }
  *((u8 *) slot) = 0x60;
  slot->payload_length = used;
  slot->next_header = ((NetIPv6SendParameters *) a)->next_header;
  if (((NetIPv6SendParameters *) a)->hop_limit)
  {
    slot->hop_limit = ((NetIPv6SendParameters *) a)->hop_limit;
  }
  else
  {
    slot->hop_limit = base->hop_limit;
  }
  NetMemcpy(&slot->src, &((NetIPv6SendParameters *) a)->source, sizeof(IPv6Address));
  NetMemcpy(&slot->dst, &((NetIPv6SendParameters *) a)->destination, sizeof(IPv6Address));
  ret = TLobby__sub_80411C44(((NetIPv6SendParameters *) a)->destination.bytes, c);
  if (ret < 0)
  {
    return ret;
  }
  n = ret - (s32)sizeof(Ipv6Header);
  base->ident += 1;
  new_var = n;
  if (used > ((u32) n))
  {
    return TLobby__sub_80410D6C((u8 *) self, (u8 *) slot, c, (s32) d, new_var);
  }
  ((NetPacket *) self)->total_bytes += sizeof(Ipv6Header);
  ((NetPacketFragment *) (((u8 *) self) + offsetof(NetPacket, fragments)))[((NetPacket *) self)->fragment_count].length = sizeof(Ipv6Header);
  off = ((NetPacket *) self)->fragment_count * (s32)sizeof(NetPacketFragment);
  set_value_and_enable((((u8 *) self) + off) + offsetof(NetPacket, fragments[0].buffer), (s32) slot);
  ((NetPacket *) self)->fragment_count += 1;
  if (NetIPv6IsMulticast(&((NetIPv6SendParameters *) a)->destination))
  {
    return TLobby__sub_804112B8((s32) self, (s32) &((NetIPv6SendParameters *) a)->destination, c);
  }
  return TLobby__sub_8041123C((s32) self, (s32) d, c);
}

#pragma push
#pragma opt_common_subs on
extern s16 TLobby__sub_80410D6C(u8 *ctx, u8 *hdr, s16 a5, s32 a6, u32 len)
{
    s16 NetIPv6IsMulticast(u8 *); /* declared s16 here; the definition returns s32 */
    s16 TLobby__sub_804112B8(s32, s32, s16); /* declared s16 here; the definition returns s32 */
    s16 TLobby__sub_8041123C(s32, s32, s16); /* declared s16 here; the definition returns s32 */
    NetPacket iov;
    Ipv6FragmentHeader fh;
    s16 i;
    s16 k;
    s16 j;
    s32 off;
    s16 rem;
    NetPacket *iovp;
    u32 limit;
    NetPacket *pc;
    s32 flen;
    s16 r;

    pc = (NetPacket *)ctx;
    if (len < 8) {
        return -6;
    }
    fh.next_header = hdr[offsetof(Ipv6Header, next_header)];
    fh.reserved = 0;
    fh.offset_flags = 0;
    fh.ident = ipv6_protocol_state.ident;
    hdr[offsetof(Ipv6Header, next_header)] = 0x2c;
    limit = len - 8;
    limit &= 0xFFF8;
    iovp = &iov;
    off = 0;
    while (pc->total_bytes != 0) {
        iov.total_bytes = 0;
        iov.fragment_count = 0;
        for (i = pc->fragment_count - 1; i >= 0; i--) {
            if (iov.total_bytes + (flen = pc->fragments[i].length) < limit) {
                iov.total_bytes += pc->fragments[i].length;
                iov.fragment_count++;
            } else {
                iov.total_bytes = limit;
                iov.fragment_count++;
                break;
            }
        }
        k = iov.fragment_count - 1;
        j = pc->fragment_count - 1;
        rem = iov.total_bytes;
        while (k >= 0 && rem > 0) {
            NetMemcpy(&iovp->fragments[k].buffer, &pc->fragments[j].buffer, sizeof(NetBufferRef));
            if (rem < pc->fragments[j].length) {
                iovp->fragments[k].length = rem;
                pc->total_bytes -= rem;
                pc->fragments[j].length -= rem;
                TLobby__sub_80406EB8(&pc->fragments[j].buffer, rem);
                break;
            }
            iovp->fragments[k].length = pc->fragments[j].length;
            rem -= pc->fragments[j].length;
            pc->total_bytes -= pc->fragments[j].length;
            pc->fragments[j].length = 0;
            pc->fragment_count--;
            k--;
            j--;
        }
        fh.offset_flags = off & 0xFFF8;
        if (pc->total_bytes != 0) {
            fh.offset_flags |= 1;
        }
        off += (s16)iov.total_bytes;
        iov.total_bytes += 8;
        iovp->fragments[iov.fragment_count].length = 8;
        set_value_and_enable(&iovp->fragments[iov.fragment_count].buffer, (s32)&fh);
        iov.fragment_count++;
        *(u16 *)(hdr + offsetof(Ipv6Header, payload_length)) = iov.total_bytes;
        iov.total_bytes += 40;
        iovp->fragments[iov.fragment_count].length = 40;
        set_value_and_enable(&iovp->fragments[iov.fragment_count].buffer, (s32)hdr);
        iov.fragment_count++;
        if (NetIPv6IsMulticast(hdr + offsetof(Ipv6Header, dst))) {
            r = TLobby__sub_804112B8((s32)iovp, (s32)(hdr + offsetof(Ipv6Header, dst)), a5);
        } else {
            r = TLobby__sub_8041123C((s32)iovp, a6, a5);
        }
        if (r < 0) {
            break;
        }
    }
    return r;
}
#pragma pop

typedef struct PH_80411040 { IPv6Address src; IPv6Address dst; u32 len; u8 zero[3]; u8 next_header; } PH_80411040;
typedef char PH_80411040_size_check[sizeof(PH_80411040) == 0x28 ? 1 : -1];
extern u16 TLobby__sub_80411040(const struct IPv6Address *src, const struct IPv6Address *dst, u8 next_header, const struct NetPacket *pkt, s16 flag) {
    PH_80411040 ph;
    u32 sum;

    NetMemcpy(&ph.src, (void *)src, sizeof(IPv6Address));
    NetMemcpy(&ph.dst, (void *)dst, sizeof(IPv6Address));
    ph.zero[0] = 0;
    ph.zero[1] = 0;
    ph.zero[2] = 0;
    ph.next_header = next_header;
    if (flag == 0) {
        ph.len = (u16)(pkt->total_bytes - pkt->fragments[0].length);
    } else {
        ph.len = (u16)pkt->total_bytes;
    }
    sum = TUdpSocket__sub_80419864(&ph, sizeof(ph) / 2);
    sum += TLobby__sub_80406BD8(pkt, flag);
    sum = (sum >> 16) + (sum & 0xFFFF);
    sum += sum >> 16;
    return ~sum;
}

Ipv6ProtocolState ipv6_protocol_state;
Ipv4RoutingState ipv4_address_routing_state;
RecoveredGlobal_8040DD68_lbl_805C1B38 ipv4_protocol_state;
DnsResolverState dns_resolver_state;
EthernetState lbl_805C1AD8;
