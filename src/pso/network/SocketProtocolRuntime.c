/* The network stack's UDP layer and TCP receive helpers (a C library, built with GC/1.2.5n): UDP control blocks
 * (create, bind, connect, close, input, sendto, ephemeral ports) and the TCP receive-queue, reassembly-range and
 * SACK-list helpers. */
#include "pso/network/NetworkRuntime.h"
#include "pso/network/UdpRuntime.h"
#include "types.h"

typedef struct P_8041FDA0 { s32 a; s32 b; } P_8041FDA0;

typedef struct O_8041FDA0 { u8 pad0[0xF4]; s32 total; s16 n; u8 padFA[2]; P_8041FDA0 items[32]; } O_8041FDA0;

typedef struct P_8041FE44 { u32 a; u32 b; } P_8041FE44;

typedef struct O_8041FE44 { u8 pad0[0x228]; u32 now; u8 pad22C[0x2F8 - 0x22C]; P_8041FE44 items[5]; } O_8041FE44;

typedef struct S_80420BD0 {
    u8 pad0[0x20]; s32 f20; u8 pad24[8]; u8 data2C[8]; u32 f34;
    u8 pad38[0x1FC - 0x38]; s32 f1FC; u8 pad200[4];
    u8 flag : 1; u8 rest : 7;
} S_80420BD0;

typedef struct Item_80420FC8 { s16 len; u8 pad2[2]; u8 data[8]; } Item_80420FC8;

typedef struct Pkt_80420FC8 { u8 pad0[4]; s32 count; s32 len; Item_80420FC8 items[1]; } Pkt_80420FC8;

typedef struct P_8041F66C { s32 a; s32 b; } P_8041F66C;

typedef struct T12_8041F914 { s32 a; s32 b; s16 len; u16 pad; } T12_8041F914;

typedef struct O_8041F66C {
    u8 pad0[0xC8]; u8 fC8[8]; u8 padD0[0xD8 - 0xD0]; s32 fD8; u8 padDC[4]; u32 fE0; u8 padE4[0xF4 - 0xE4];
    s32 total; s16 n; s16 fFA; P_8041F66C items[32]; u8 pad1FC[0x228 - 0x1FC]; s32 now;
    u8 pad22C[0x534 - 0x22C]; u32 f534;
} O_8041F66C;

typedef struct Obj_8041ED8C {
    u8 pad0[6];
    s16 f6;
    u8 pad8[3];
    u8 fB;
    u8 padC[0xC8 - 0xC];
    u8 fC8[8];
    u8 padD0[0xD8 - 0xD0];
    u32 fD8;
    u32 fDC;
    u32 fE0;
    u8 fE4[4];
    u8 fE8;
    u8 padE9[3];
    u32 fEC;
    s32 fF0;
    u8 padF4[0x200 - 0xF4];
    s32 f200;
    u8 f204;
    u8 pad205[0x2D0 - 0x205];
    s32 f2D0;
    u8 pad2D4[0x534 - 0x2D4];
    u32 f534;
    u8 pad538[4];
    u32 f53C;
    u8 pad540[4];
} Obj_8041ED8C;

typedef struct G_8041ED8C { Obj_8041ED8C *p; s16 n; u8 pad[0xA2]; } G_8041ED8C;

typedef struct Buf_8041ED8C { u8 b[8]; } Buf_8041ED8C;

typedef struct Obj_8041F11C {
    u8 pad0[6];
    s16 f6;
    u8 pad8[3];
    u8 fB;
    u8 padC[0xD8 - 0xC];
    u32 fD8;
    u8 padDC[0xE8 - 0xDC];
    u8 fE8;
    u8 padE9[0x200 - 0xE9];
    s32 f200;
    u8 pad204[0x2D0 - 0x204];
    s32 f2D0;
    u8 pad2D4[0x544 - 0x2D4];
} Obj_8041F11C;

typedef struct G_8041F11C { Obj_8041F11C *p; s16 n; u8 pad[0xA2]; } G_8041F11C;

typedef struct Hdr_80420DE4 { u16 src; u16 dst; u16 len; u16 sum; } Hdr_80420DE4;

typedef struct O_80420DE4 { u8 pad0[8]; s32 f8; u8 padC[0xC]; s16 f18; u8 pad1A[2]; u8 f1C[4]; } O_80420DE4;

typedef struct TcpSeqRange { u32 start; u32 end; } TcpSeqRange;

typedef struct TcpSackView { u8 pad0[0xFA]; s16 last_reasm; TcpSeqRange reasm[32]; u8 pad1FC[0x2F8 - 0x1FC]; TcpSeqRange sack[5]; } TcpSackView;

typedef struct Item_8041FFF8 { s16 len; u8 pad2[2]; u8 data[8]; } Item_8041FFF8;

typedef struct Seg_8041FFF8 { u8 b[8]; s16 n; s16 m; void (*p)(s16, s16, s32); u8 e[8]; } Seg_8041FFF8;

typedef struct Obj_8041FFF8 {
    u8 pad0[0x10]; u8 f10[8]; u8 pad18[8]; u32 f20; u32 f24; u32 f28; u8 pad2C[4];
    u32 f30; u32 f34; Item_8041FFF8 items[37]; u8 pad1F4[8]; void (*f1FC)(s16, s16); u8 pad200[4];
    u8 flag : 1; u8 rest204 : 7; u8 pad205[0x530 - 0x205]; u32 f530; u8 pad534[0x544 - 0x534];
} Obj_8041FFF8;

s32 complete_request_callback(s32 idx_, void (*cb)(s16, s16, s32), s16 arg2, s32 *arg3);
s32 set_thread_state_and_resume(s32 idx, void (*cb)(s16, s16), s16 arg2);

void set_value_and_enable(void *self, s32 value);

void TLobby__sub_803F87C8(u8 *arg0);
s32 TLobby__sub_803F87C4(void *);
void TLobby__sub_8041FDA0(O_8041FDA0 *o, s16 idx, s32 a, s32 b);
void TLobby__sub_8041FED4(TcpSackView *tcb);
void NetMemcpy(void *_w0, void *_w1, int _w2);
s32 TLobby__sub_80420BD0(void *arg0, S_80420BD0 *s, s32 arg2);
s32 TLobby__sub_80420D38(u16 arg0, u8 arg1);
s16 dispatch_by_addr_family(void *, void *, void *, s32, s32, int);
s16 TLobby__sub_8040D8F0(void *, void *, int, void *, int);
s16 select_source_address(void *, void *);
s16 TLobby__sub_8040DA54(void *, void *);
s16 is_addr_unspecified(void *);
s16 udp_sendto(s16 id, Pkt_80420FC8 *pkt, NetworkAddress *src, NetworkAddress *dst, u16 port, s32 arg5);
void TLobby__sub_8041F66C(O_8041F66C *o);
void set_slot_state_and_resume(s16, s32, s16);
void TLobby__sub_80406EB8(void *, u32);
void TLobby__sub_80406FD8(void *, void *, u32);
void TLobby__sub_8041A9AC(Obj_8041ED8C *);
extern G_8041ED8C tcp_protocol_state;
s32 TLobby__sub_8041ED8C(Obj_8041ED8C *self, void *data, u32 len, s32 arg3);
s32 TLobby__sub_8041F11C(Obj_8041F11C *self);
s16 compare_sockaddr(void *, void *);
s16 is_multicast_address(void *, s32);
s16 TLobby__sub_80421F10(void *, void *, void *, u16, s32, s16);
s32 udp_input(O_80420DE4 *arg0, NetworkAddress *src, NetworkAddress *dst, s32 arg3);
UdpRuntimeState udp_runtime_state;

s32 TLobby__sub_8041ED8C(Obj_8041ED8C *self, void *data, u32 len, s32 arg3) {
    s16 idx = self - tcp_protocol_state.p;
    s32 m;
    u32 k;
    Buf_8041ED8C src;
    Buf_8041ED8C dst;
    if (self->fE8 != 0) {
        return -4;
    }
    if ((self->f204 >> 6) & 1) {
        return -4;
    }
    self->f200 = arg3;
    NetMemcpy(self->fE4, data, 8);
    self->fEC = len;
    m = 0;
    self->fF0 = m;
    if (self->fD8 == 0) {
        switch (self->f6) {
        case 0:
        case 5:
        case 7:
        case 8:
        case 10:
            self->fE8 = m;
            set_slot_state_and_resume(idx, self->f200, -7);
            while (self->fE8 != 0) {
                self->fE8 = m;
                set_slot_state_and_resume(idx, self->f200, -7);
            }
            return 0;
        case -1:
            self->fE8 = m;
            set_slot_state_and_resume(idx, self->f200, -11);
            while (self->fE8 != 0) {
                self->fE8 = m;
                set_slot_state_and_resume(idx, self->f200, -11);
            }
            return 0;
        default:
            return 0;
        }
    }
    do {
        m = (s32)(self->fD8 > self->fEC ? self->fEC : self->fD8);
        self->fF0 = m;
        NetMemcpy(&src, self->fC8, 8);
        TLobby__sub_80406EB8(&src, self->fDC);
        NetMemcpy(&dst, self->fE4, 8);
        if (self->fDC + m > self->f534) {
            k = self->f534 - self->fDC;
            TLobby__sub_80406FD8(&dst, &src, k);
            TLobby__sub_80406EB8(&dst, k);
            m -= k;
            self->fD8 -= k;
            self->fDC = 0;
            NetMemcpy(&src, self->fC8, 8);
        }
        TLobby__sub_80406FD8(&dst, &src, m);
        self->fD8 -= m;
        self->fDC += m;
        if (self->fDC >= self->f534) {
            self->fDC -= self->f534;
        }
        self->fE8 = 0;
        set_slot_state_and_resume(idx, self->f200, self->fF0);
    } while (self->fE8 != 0 && self->fD8 != 0);
    if (self->f53C == 0) {
        self->fB &= ~1;
    }
    if (self->f6 != -1 && self->f6 != 0) {
        TLobby__sub_8041A9AC(self);
    }
    if (self->fE8 != 0) {
        switch (self->f6) {
        case 0:
        case 5:
        case 7:
        case 8:
        case 10:
            set_slot_state_and_resume(idx, self->f200, -7);
            break;
        case -1:
            set_slot_state_and_resume(idx, self->f200, -11);
            break;
        default:
            return 0;
        }
    }
    if (self->fD8 == 0 && (self->fB & 8) && !(self->fB & 0x20)) {
        NetDispatchSocketEvent((s16)(self - tcp_protocol_state.p), self->f2D0, 3, 3);
        self->fB |= 0x20;
    }
    return 0;
}

s32 TLobby__sub_8041F11C(Obj_8041F11C *self) {
    s16 idx = self - (*(G_8041F11C *)&tcp_protocol_state).p;
    while (self->fE8 != 0) {
        self->fE8 = 0;
        set_slot_state_and_resume(idx, self->f200, -7);
    }
    if (self->fD8 == 0 && !(self->fB & 0x20)) {
        NetDispatchSocketEvent((s16)(self - (*(G_8041F11C *)&tcp_protocol_state).p), self->f2D0, 3, 3);
        self->fB |= 0x20;
    }
    return 0;
}

void NetMemcpy(void* destination, void* source, int size);
#pragma push
#pragma cplusplus off
#pragma pop
#pragma push
#pragma cplusplus off
#pragma dont_inline off
#pragma dont_inline off
s32 TLobby__sub_8041F204(u8 *tbl, u16 x, u8 *self)
{
  void NetMemcpy(void *, const void *, u32);
  s16 idx;
  s16 i;
  u32 n;
  u32 rem;
  u32 n2;
  unsigned int new_var;
  s16 new_var2;
  u32 avail;
  u32 cnt;
  u8 *p;
  u8 buf1c[8];
  u8 buf14[8];
  idx = (s16) ((((s32) self) - ((s32) (*((u32 *) (*((u8 (*)[]) (&tcp_protocol_state))))))) / 1348);
  if (!((self[0x204] >> 6) & 1))
  {
    cnt = *((u32 *) (tbl + 4));
    p = tbl + 0xc;
    rem = 0;
    i = 1;
    while (i < cnt)
    {
      if (((u16) (new_var2 = *((s16 *) (p + 0xc)))) > ((u16) x))
      {
        rem = x;
        break;
      }
      x -= new_var2;
      p += 0xc;
      i++;
    }

    if (i == cnt)
    {
      return 0;
    }
    if (self[0xe8])
    {
      NetMemcpy(buf1c, self + 0xe4, 8);
      p = tbl + (((s16) i) * 12);
      while (i < (*((u32 *) (tbl + 4))))
      {
        NetMemcpy(buf14, p + 0x10, 8);
        if (rem != 0)
        {
          TLobby__sub_80406EB8(buf14, rem);
        }
        n2 = *((s16 *) (p + 0xc));
        n2 -= rem;
        n = (new_var = *((u32 *) (self + 0xec)));
        n -= *((u32 *) (self + 0xf0));
        if (n >= n2)
        {
          n = n2;
          TLobby__sub_80406FD8(buf1c, buf14, n);
          *((u32 *) (self + 0xf0)) += n2;
          *((u32 *) (self + 0xdc)) += n2;
          if ((*((u32 *) (self + 0xdc))) >= (*((u32 *) (self + 0x534))))
          {
            *((u32 *) (self + 0xdc)) -= *((u32 *) (self + 0x534));
          }
          *((u32 *) (self + 0xe0)) += n2;
          if ((*((u32 *) (self + 0xe0))) >= (*((u32 *) (self + 0x534))))
          {
            *((u32 *) (self + 0xe0)) -= *((u32 *) (self + 0x534));
          }
          TLobby__sub_80406EB8(buf1c, n);
          rem = 0;
          p += 0xc;
          i++;
        }
        else
        {
          TLobby__sub_80406FD8(buf1c, buf14, n);
          *((u32 *) (self + 0xf0)) += n;
          *((u32 *) (self + 0xdc)) += n;
          if ((*((u32 *) (self + 0xdc))) >= (*((u32 *) (self + 0x534))))
          {
            *((u32 *) (self + 0xdc)) -= *((u32 *) (self + 0x534));
          }
          *((u32 *) (self + 0xe0)) += n;
          if ((*((u32 *) (self + 0xe0))) >= (*((u32 *) (self + 0x534))))
          {
            *((u32 *) (self + 0xe0)) -= *((u32 *) (self + 0x534));
          }
          rem += n;
        }
        if ((*((u32 *) (self + 0xec))) == (*((u32 *) (self + 0xf0))))
        {
          self[0xe8] = 0;
          set_slot_state_and_resume(idx, *((s32 *) (self + 0x200)), (s16) (*((u32 *) (self + 0xf0))));
          if (!self[0xe8])
          {
            goto zero;
          }
          NetMemcpy(buf1c, self + 0xe4, 8);
          if (i < (*((u32 *) (tbl + 4))))
          {
            continue;
          }
          switch (*((s16 *) (self + 6)))
          {
            case 0:

            case 5:

            case 7:

            case 8:

            case 10:
              self[0xe8] = 0;
              set_slot_state_and_resume(idx, *((s32 *) (self + 0x200)), -7);
              break;

          }

          goto fin;
        }
      }

      self[0xe8] = 0;
      set_slot_state_and_resume(idx, *((s32 *) (self + 0x200)), (s16) (*((u32 *) (self + 0xf0))));
      while (self[0xe8] != 0)
      {
        switch (*((s16 *) (self + 6)))
        {
          case 0:

          case 5:

          case 7:

          case 8:

          case 10:
            self[0xe8] = 0;
            set_slot_state_and_resume(idx, *((s32 *) (self + 0x200)), -7);
            break;

        }

        goto fin;
      }

      goto fin;
    }
    zero:
    NetMemcpy(buf1c, self + 0xc8, 8);

    TLobby__sub_80406EB8(buf1c, *((u32 *) (self + 0xe0)));
    p = tbl + (((s16) i) * 12);
    while (i < (*((u32 *) (tbl + 4))))
    {
      NetMemcpy(buf14, p + 0x10, 8);
      if (rem != 0)
      {
        TLobby__sub_80406EB8(buf14, rem);
      }
      n = (*((s16 *) (p + 0xc))) - rem;
      avail = (*((u32 *) (self + 0x534))) - (*((u32 *) (self + 0xd8)));
      if (n > avail)
      {
        n = avail;
      }
      *((u32 *) (self + 0xd8)) += n;
      if (((*((u32 *) (self + 0xe0))) + n) >= (*((u32 *) (self + 0x534))))
      {
        TLobby__sub_80406FD8(buf1c, buf14, (*((u32 *) (self + 0x534))) - (*((u32 *) (self + 0xe0))));
        NetMemcpy(buf1c, self + 0xc8, 8);
        TLobby__sub_80406EB8(buf14, (*((u32 *) (self + 0x534))) - (*((u32 *) (self + 0xe0))));
        n -= (*((u32 *) (self + 0x534))) - (*((u32 *) (self + 0xe0)));
        *((u32 *) (self + 0xe0)) = 0;
      }
      if (n != 0)
      {
        TLobby__sub_80406FD8(buf1c, buf14, n);
        *((u32 *) (self + 0xe0)) += n;
        TLobby__sub_80406EB8(buf1c, n);
      }
      rem = 0;
      p += 0xc;
      i++;
    }

    fin:
    TLobby__sub_8041F66C((O_8041F66C *) self);

    return 0;
  }
  return -1;
}
#pragma pop

void TLobby__sub_8041F66C(O_8041F66C *o) {
    s16 i;
    s16 cnt;
    s16 j;
    s32 d;
    u8 unused[8];
    if (o->n == -1) {
        return;
    }
    for (i = 0; i <= o->n; i++) {
        if (o->now - o->items[i].b < 0) {
            break;
        }
    }
    if (i <= o->n && o->now - o->items[i].a >= 0) {
        d = o->items[i].b - o->now;
        o->fE0 += d;
        if (o->fE0 >= o->f534) {
            o->fE0 -= o->f534;
        }
        cnt = i + 1;
        o->fD8 += d;
        o->now = o->items[i].b;
    } else {
        cnt = i;
    }
    expire_timeout_entries(o);
    if (cnt <= 0) {
        return;
    }
    o->n -= cnt;
    for (j = 0; j < cnt; j++) {
        o->total -= o->items[j].b - o->items[j].a;
    }
    for (j = 0; j <= o->n; j++) {
        o->items[j] = o->items[j + cnt];
    }
    if (o->n == -1) {
        o->fFA = -1;
    } else {
        o->fFA = 0;
    }
}

#pragma push
#pragma dont_inline off
#pragma inline_depth(4)
inline void sack_remove_8041F914(O_8041F66C *o, s16 idx) {
    s16 nn = o->n;
    s16 j;
    if (idx < 0 || nn < 0 || idx > nn) {
        return;
    }
    o->total -= o->items[idx].b - o->items[idx].a;
    for (j = idx; j < o->n; j++) {
        o->items[j] = o->items[j + 1];
    }
    o->n--;
}
#pragma pop

s32 TLobby__sub_8041F914(u8 *tbl, u16 x, O_8041F66C *o, P_8041FDA0 *d)
{
  u32 cnt;
  s32 n;
  volatile unsigned int pad;
  s16 kk;
  u32 rem;
  u32 k;
  s32 sum;
  s32 delta;
  s32 s;
  u32 i;
  u8 buf1[8];
  O_8041F66C *new_var;
  u8 buf2[8];
  u8 *p;
  if (!((((u8 *) o)[0x204] >> 6) & 1))
  {
    rem = 0;
    sum = 0;
    delta = d->b - o->now;
    if (delta <= 0)
    {
      return 0;
    }
    if (((u32) (((*((s32 *) (tbl + 8))) - x) + delta)) > ((u32) (o->f534 - o->fD8)))
    {
      return 0;
    }
    cnt = *((s32 *) (tbl + 4));
    i = 0;
    cnt = cnt;
    for (; i < cnt; i++)
    {
      if (((u16) (*((s16 *) ((tbl + (i * 12)) + 0xc)))) > ((u16) x))
      {
        rem = (u16) x;
        break;
      }
      x -= *((s16 *) ((tbl + (i * 12)) + 0xc));
    }

    if (i == cnt)
    {
      return 0;
    }
    k = o->fE0 + delta;
    if (k > o->f534)
    {
      k -= o->f534;
    }
    NetMemcpy(buf1, o->fC8, 8);
    TLobby__sub_80406EB8(buf1, k);
    for (p = tbl + (i * 12); i < (*((u32 *) (tbl + 4))); p += 12, i++)
    {
      NetMemcpy(buf2, p + 0x10, 8);
      if (rem != 0)
      {
        TLobby__sub_80406EB8(buf2, rem);
      }
      rem = (*((s16 *) (p + 0xc))) - rem;
      if (((u32) rem) > (o->f534 - o->fD8))
      {
        rem = o->f534 - o->fD8;
      }
      sum += rem;
      if ((k + rem) >= o->f534)
      {
        TLobby__sub_80406FD8(buf1, buf2, o->f534 - k);
        NetMemcpy(buf1, o->fC8, 8);
        TLobby__sub_80406EB8(buf2, o->f534 - k);
        rem -= o->f534 - k;
      }
      if (rem)
      {
        TLobby__sub_80406FD8(buf1, buf2, rem);
        TLobby__sub_80406EB8(buf1, (s16) rem);
      }
      rem = 0;
    }

    s = d->b;
    sum += s;
    if (o->n == (-1))
    {
      TLobby__sub_8041FDA0((O_8041FDA0 *) o, 0, s, sum);
      o->fFA = 0;
    }
    else
    {
      if ((s - o->items[0].a) <= 0)
      {
        TLobby__sub_8041FDA0((O_8041FDA0 *) o, 0, s, sum);
        kk = 0;
      }
      else
      {
        O_8041F66C *e = (O_8041F66C *) (((u8 *) o) + 8);
        for (kk = 1; kk <= o->n; e = (O_8041F66C *) (((u8 *) e) + 8), kk++)
        {
          if ((s - e->items[0].a) <= 0)
          {
            n = o->items[kk - 1].b;
            if ((s - n) <= 0)
            {
              delta = sum - n;
              if (delta < 0)
              {
                goto fin;
              }
              o->total += delta;
              o->items[kk - 1].b = sum;
              kk--;
            }
            else
            {
              TLobby__sub_8041FDA0((O_8041FDA0 *) o, kk, s, sum);
            }
            break;
          }
        }

        if (kk == (o->n + 1))
        {
          n = o->items[kk - 1].b;
          if ((s - n) <= 0)
          {
            delta = sum - n;
            if (delta < 0)
            {
              goto fin;
            }
            o->total += delta;
            o->items[kk - 1].b = sum;
            kk--;
          }
          else
          {
            TLobby__sub_8041FDA0((O_8041FDA0 *) o, kk, s, sum);
          }
        }
      }
      o->fFA = kk;
      while (((kk + 1) <= o->n) && ((o->items[kk].b - o->items[kk + 1].a) >= 0))
      {
        if ((o->items[kk].b - o->items[kk + 1].b) >= 0)
        {
          {
            s16 idx = kk + 1;
            s16 nn = o->n;
            s16 j;
            if (!(((idx < 0) || (nn < 0)) || (idx > nn)))
            {
              o->total -= o->items[idx].b - o->items[idx].a;
              for (j = idx; j < o->n; j++)
              {
                o->items[j] = o->items[j + 1];
              }

              o->n--;
            }
          }
        }
        else
        {
          o->total += o->items[kk + 1].b - o->items[kk].b;
          (new_var = o)->items[kk].b = o->items[kk + 1].b;
          {
            s16 idx = kk + 1;
            s16 nn = o->n;
            s16 j;
            if (!(((idx < 0) || (nn < 0)) || (idx > nn)))
            {
              o->total -= o->items[idx].b - o->items[idx].a;
              for (j = idx; j < o->n; j++)
              {
                o->items[j] = o->items[j + 1];
              }

              o->n--;
            }
          }
        }
      }

    }
    fin:
    TLobby__sub_8041FED4((TcpSackView *) o);

    return 0;
  }
  return -1;
}

void TLobby__sub_8041FDA0(O_8041FDA0 *o, s16 idx, s32 a, s32 b) {
    s16 i;
    if (idx < 0) {
        return;
    }
    if (idx > o->n + 1) {
        return;
    }
    if (idx > 0x1F) {
        return;
    }
    if (o->n >= 0x1F) {
        o->n = 0x1E;
    }
    for (i = o->n; i >= idx; i--) {
        o->items[i + 1] = o->items[i];
    }
    o->items[idx].a = a;
    o->items[idx].b = b;
    o->n++;
    o->total += b - a;
}

void expire_timeout_entries(void *tcb) {
    O_8041FE44 *o = (O_8041FE44 *)tcb;
    s16 i;
    s16 j;
    i = 0;
    while (i < 5) {
        if (o->items[i].a == o->items[i].b) {
            return;
        }
        if ((s32)(o->items[i].b - o->now) <= 0) {
            for (j = i; j < 4; j++) {
                o->items[j] = o->items[j + 1];
            }
            o->items[4].a = 0;
            o->items[4].b = 0;
        } else {
            i++;
        }
    }
}

void TLobby__sub_8041FED4(TcpSackView *tcb) {
    u32 start;
    u32 end;
    s16 i;
    s16 j;
    s16 k;
    if (tcb->last_reasm == -1) {
        return;
    }
    start = tcb->reasm[tcb->last_reasm].start;
    end = tcb->reasm[tcb->last_reasm].end;
    for (i = 4; i > 0; i--) {
        tcb->sack[i] = tcb->sack[i - 1];
    }
    tcb->sack[0].start = start;
    tcb->sack[0].end = end;
    for (i = 4; i > 0; i--) {
        if (tcb->sack[i].start == tcb->sack[i].end) {
            continue;
        }
        for (j = i - 1; j >= 0; j--) {
            if ((s32)(tcb->sack[i].start - tcb->sack[j].start) >= 0 && (s32)(tcb->sack[i].end - tcb->sack[j].end) <= 0) {
                for (k = i; k < 5; k++) {
                    tcb->sack[k] = tcb->sack[k + 1];
                }
                tcb->sack[4].start = 0;
                tcb->sack[4].end = 0;
                break;
            }
        }
    }
}

s32 TLobby__sub_8041FFF8(u32 len, Obj_8041FFF8 *self)
{
  u32 t;
  s16 idx = (s16) (self - ((Obj_8041FFF8 *) tcp_protocol_state.p));
  int pad3;
  Seg_8041FFF8 c;
  u8 b[8];
  int pad2;
  volatile int pad;
  u8 a[8];
  u8 d[8];
  u32 n;
  Item_8041FFF8 *it;
  int new_var2;
  s16 i;
  unsigned int new_var;
  s16 L;
  if (self->flag == 1)
  {
    b[4] = 1;
    n = len;
    a[4] = 1;
    if ((n != 0) && (self->f20 != 0))
    {
      set_value_and_enable(a, (s32) (&c));
      NetMemcpy(b, self->f10, 8);
      if (((s32) self->f24) != 0)
      {
        TLobby__sub_80406EB8(b, self->f24 << 4);
      }
      TLobby__sub_80406FD8(a, b, 16);
      while ((((u32) c.n) <= n) && (self->f20 != 0))
      {
        self->f20--;
        n -= c.n;
        self->f34 -= c.n;
        if (self->f24 < 0x40)
        {
          self->f24 = self->f24 + 1;
        }
        else
        {
          self->f24 = 0;
        }
        if (self->f20 == 0)
        {
          self->f28 = 0;
          self->f24 = 0;
          self->flag = 0;
        }
        complete_request_callback(idx, c.p, 0, (s32 *) (&c));
        t = self->f24;
        new_var2 = t;
        NetMemcpy(b, self->f10, 8);
        if (new_var2 != 0)
        {
          TLobby__sub_80406EB8(b, new_var2 << 4);
        }
        TLobby__sub_80406FD8(a, b, 16);
      }

      if ((n != 0) && (self->f20 != 0))
      {
        L = n;
        self->f34 -= n;
        c.n -= L;
        c.m += L;
        TLobby__sub_80406FD8(b, a, 16);
      }
    }
    return 0;
  }
  if (len != 0)
  {
    if (len <= self->f20)
    {
      self->f20 -= len;
      self->f24 += len;
      if (self->f24 >= self->f530)
      {
        self->f24 -= self->f530;
      }
    }
    else
    {
      n = len - self->f20;
      self->f20 = 0;
      self->f24 = self->f28;
      self->f34 -= n;
      it = self->items;
      for (i = 0; (i < self->f30) && (n != 0); it++, i++)
      {
        if (n >= it->len)
        {
          n -= it->len;
          it->len = 0;
        }
        else
        {
          it->len -= n;
          TLobby__sub_80406EB8(it->data, n);
          n = 0;
        }
      }

    }
  }
  if (self->f34 != 0)
  {
    if (self->f34 > (self->f530 - self->f20))
    {
      return 0;
    }
    NetMemcpy(d, self->f10, 8);
    TLobby__sub_80406EB8(d, self->f28);
    i = 0;
    it = self->items;
    while (i < self->f30)
    {
      if (it->len > 0)
      {
        self->f20 += it->len;
        new_var = it->len;
        n = self->f530 - self->f28;
        if (new_var > n)
        {
          TLobby__sub_80406FD8(d, it->data, n);
          TLobby__sub_80406EB8(it->data, n);
          it->len -= n;
          self->f34 -= n;
          self->f28 = 0;
          NetMemcpy(d, self->f10, 8);
        }
        L = it->len;
        TLobby__sub_80406FD8(d, it->data, L);
        self->f28 += L;
        TLobby__sub_80406EB8(d, L);
        self->f34 -= L;
        it->len = 0;
      }
      it++;
      i++;
    }

    if (self->f34 != 0)
    {
      return 0;
    }
    self->f34 = 0;
    self->f30 = 0;
    return set_thread_state_and_resume(idx, self->f1FC, 0);
  }
  if (!self->f34)
  {
    set_thread_state_and_resume(idx, self->f1FC, 0);
  }
  return 0;
}

#pragma push
#pragma opt_propagation off
s32 TLobby__sub_80420410(s32 arg0, s32 arg1, Pkt_80420FC8 *pkt, Obj_8041FFF8 *o) {
    u8 d[16];
    Buf_8041ED8C c;
    Buf_8041ED8C b;
    Buf_8041ED8C a;
    Buf_8041ED8C tmp;
    u32 n;
    s32 m;
    s32 start;
    s32 cnt;
    s32 g;
    s32 i;
    s32 k;
    s32 lo;
    s32 j;
    s32 hi;
    u32 t;
    u32 off;
    u32 r31v;
    Item_8041FFF8 *it;
    Item_80420FC8 *pa;
    Item_80420FC8 *pb;
    Pkt_80420FC8 *qa;
    Pkt_80420FC8 *qb;
    Item_80420FC8 *slot;

    if (o->flag == 1) {
        a.b[4] = 1;
        n = arg1;
        b.b[4] = 1;
        c.b[4] = 1;
        if ((u32)arg1 == 0) {
            goto neg1;
        }
        if (o->f20 == 0) {
            goto neg1;
        }
        set_value_and_enable(&a, (s32)d);
        m = o->f24;
        NetMemcpy(&c, o->f10, 8);
        if (m != 0) {
            TLobby__sub_80406EB8(&c, m << 4);
        }
        TLobby__sub_80406FD8(&a, &c, 16);
        if ((u32)arg0 != 0) {
            while ((u32)*(s16 *)(d + 8) <= (u32)arg0) {
                arg0 -= *(s16 *)(d + 8);
                if (m < 64) {
                    m++;
                } else {
                    m = 0;
                }
                NetMemcpy(&c, o->f10, 8);
                if (m != 0) {
                    TLobby__sub_80406EB8(&c, m << 4);
                }
                TLobby__sub_80406FD8(&a, &c, 16);
            }
            NetMemcpy(&b, d, 8);
            *(s16 *)(d + 8) -= (s16)arg0;
            TLobby__sub_80406EB8(&b, *(s16 *)(d + 10));
            TLobby__sub_80406EB8(&b, arg0);
        } else {
            NetMemcpy(&b, d, 8);
            TLobby__sub_80406EB8(&b, *(s16 *)(d + 10));
        }
        start = pkt->count;
        while (n != 0) {
            pa = &pkt->items[pkt->count];
            if (n >= (u32)*(s16 *)(d + 8)) {
                pa->len = *(s16 *)(d + 8);
                pkt->len += *(s16 *)(d + 8);
                n -= *(s16 *)(d + 8);
            } else {
                pa->len = n;
                pkt->len += n;
                n = 0;
            }
            NetMemcpy(pa->data, &b, 8);
            pkt->count++;
            if (n != 0) {
                if (m < 64) {
                    m++;
                } else {
                    m = 0;
                }
                NetMemcpy(&c, o->f10, 8);
                if (m != 0) {
                    TLobby__sub_80406EB8(&c, m << 4);
                }
                TLobby__sub_80406FD8(&a, &c, 16);
                NetMemcpy(&b, d, 8);
            }
        }
        cnt = pkt->count - start;
        hi = (cnt - 2) / 2;
        lo = (cnt + 1) / 2;
        qb = (Pkt_80420FC8 *)((u8 *)pkt + lo * 12);
        qa = (Pkt_80420FC8 *)((u8 *)pkt + hi * 12);
        for (; hi >= 0 && lo < cnt; hi--, lo++) {
            NetMemcpy(&tmp, qb->items[0].data, 8);
            NetMemcpy(qb->items[0].data, qa->items[0].data, 8);
            NetMemcpy(qa->items[0].data, &tmp, 4);
            j = qb->items[0].len;
            qb->items[0].len = qa->items[0].len;
            qa->items[0].len = j;
            qb = (Pkt_80420FC8 *)((u8 *)qb + 12);
            qa = (Pkt_80420FC8 *)((u8 *)qa - 12);
        }
        return 0;
neg1:
        return -1;
    }

    off = (u16)arg0;
    g = -1;
    r31v = off + o->f24;
    k = 0;
    if ((u32)arg0 >= o->f20 + o->f34) {
        return -1;
    }
    if ((u32)arg0 < o->f20) {
        if ((u32)(arg1 + arg0) > o->f20) {
            goto adj;
        }
        if (o->f24 + arg0 < o->f530) {
            if (arg1 + (o->f24 + arg0) <= o->f530) {
                pkt->count = 1;
                NetMemcpy(pkt->items[0].data, o->f10, 8);
                TLobby__sub_80406EB8(pkt->items[0].data, r31v);
                pkt->items[0].len = arg1;
            } else {
                pkt->count = 2;
                NetMemcpy(pkt->items[0].data, o->f10, 8);
                NetMemcpy(pkt->items[1].data, o->f10, 8);
                TLobby__sub_80406EB8(pkt->items[1].data, r31v);
                t = o->f530 - r31v;
                pkt->items[1].len = t;
                pkt->items[0].len = arg1 - t;
            }
        } else {
            pkt->count = 1;
            NetMemcpy(pkt->items[0].data, o->f10, 8);
            TLobby__sub_80406EB8(pkt->items[0].data, r31v - o->f530);
            pkt->items[0].len = arg1;
        }
        pkt->len = arg1;
        return 0;
adj:
        arg1 -= o->f20 - off;
        goto tail;
    }
    arg0 -= o->f20;
    it = o->items;
    for (i = 0; (u32)i < o->f30; it++, i++) {
        if ((u32)arg0 < (u32)(s32)it->len) {
            pkt->count = 1;
            k = i;
            off = (u16)arg0;
            NetMemcpy(pkt->items[0].data, it->data, 8);
            TLobby__sub_80406EB8(pkt->items[0].data, off);
            pkt->len = arg1;
            pkt->items[0].len = arg1;
            if ((u32)(arg1 + arg0) <= (u32)(s32)it->len) {
                pkt->len = arg1;
                pkt->items[0].len = arg1;
                return 0;
            }
            m = it->len - off;
            pkt->len = m;
            pkt->items[0].len = m;
            i++;
            while ((u32)i < o->f30) {
                cnt = i - k;
                qa = (Pkt_80420FC8 *)((u8 *)pkt + (cnt - 1) * 12);
                qb = (Pkt_80420FC8 *)((u8 *)pkt + cnt * 12);
                for (j = cnt; j > 0; j--) {
                    NetMemcpy(qb->items[0].data, qa->items[0].data, 8);
                    qb->items[0].len = qa->items[0].len;
                    qa = (Pkt_80420FC8 *)((u8 *)qa - 12);
                    qb = (Pkt_80420FC8 *)((u8 *)qb - 12);
                }
                pkt->count++;
                it++;
                NetMemcpy(pkt->items[0].data, it->data, 8);
                arg1 -= m;
                if (arg1 <= (s32)it->len) {
                    pkt->items[0].len = arg1;
                    pkt->len += arg1;
                    return 0;
                }
                pkt->items[0].len = it->len;
                i++;
                pkt->len += it->len;
                m = it->len;
            }
            pkt->len = 0;
            pkt->items[0].len = 0;
            pkt->items[1].len = 0;
            return 0;
        }
        arg0 -= it->len;
    }
    return 0;
tail:
    i = 0;
    it = &o->items[i];
    for (; (u32)i < o->f30; it++, i++) {
        if ((u32)arg1 <= (u32)(s32)it->len) {
            pkt->count = 1;
            NetMemcpy(pkt->items[0].data, it->data, 8);
            pkt->len = arg1;
            pkt->items[0].len = arg1;
            k = 1;
            break;
        }
        arg1 -= it->len;
    }
    qa = (Pkt_80420FC8 *)((u8 *)pkt + k * 12);
    it--;
    i--;
    while (i > -1) {
        pkt->count++;
        NetMemcpy(qa->items[0].data, it->data, 8);
        k++;
        m = it->len;
        it--;
        i--;
        qa->items[0].len = m;
        pkt->len += m;
        qa = (Pkt_80420FC8 *)((u8 *)qa + 12);
    }
    slot = &pkt->items[k];
    if (g < 0) {
        t = off + o->f24;
        if (t < o->f530) {
            if (o->f24 + o->f20 <= o->f530) {
                pkt->count++;
                NetMemcpy(slot->data, o->f10, 8);
                TLobby__sub_80406EB8(slot->data, t);
                slot->len = o->f20 - off;
            } else {
                pkt->count += 2;
                NetMemcpy(slot->data, o->f10, 8);
                NetMemcpy(slot[1].data, o->f10, 8);
                TLobby__sub_80406EB8(slot[1].data, t);
                slot[1].len = o->f530 - t;
                slot->len = o->f20 - off - (s16)slot[1].len;
            }
        } else {
            pkt->count++;
            NetMemcpy(slot->data, o->f10, 8);
            TLobby__sub_80406EB8(slot->data, t - o->f530);
            slot->len = o->f20 - off;
        }
        pkt->len += o->f20 - off;
    } else {
        pkt->count++;
        NetMemcpy(slot->data, o->items[g].data, 4);
        TLobby__sub_80406EB8(slot->data, off);
        m = *(s16 *)((u8 *)o + 0x2c) - off;
        slot->len = m;
        pkt->len += (s16)m;
    }
    return 0;
}
#pragma pop
s32 TLobby__sub_80420BD0(void *arg0, S_80420BD0 *s, s32 arg2) {
    u32 v;
    if (s->flag == 1) {
        if (s->flag) {
            v = s->f34;
        } else {
            v = s->f20 + s->f34;
        }
        if (v != 0) {
            return -1;
        }
    }
    s->f1FC = arg2;
    NetMemcpy(s->data2C, arg0, 0x9C);
    s->flag = 0;
    return 0;
}

s32 reset_stack_module(void) {
    TLobby__sub_803F87C4(&udp_runtime_state.count);
    udp_runtime_state.count = 0;
    return 0;
}
s32 init_ucb_entries(void) {
    s16 i;
    UdpControlBlock *e;

    TLobby__sub_803F87C8((u8 *)&udp_runtime_state);
    e = udp_runtime_state.entries;
    i = 0;
    while (i < udp_runtime_state.count) {
        e->signature[0] = 0x55;
        e->signature[1] = 0x43;
        e->signature[2] = 0x42;
        e->index = i;
        e->active = 0;
        i++;
        e++;
    }
    udp_runtime_state.ephemeralPort = 0;
    udp_runtime_state.ephemeralPortEnd = 0x7FF;
    udp_runtime_state.ephemeralPortStart = 0x400;
    return 0;
}
s32 TLobby__sub_80420D38(u16 arg0, u8 arg1) {
    s16 i;
    UdpControlBlock *e;
    UdpRuntimeState *g = &udp_runtime_state;
    for (i = 0, e = g->entries; i < g->count; i++, e++) {
        if (e->active != 0 && e->localPort == arg0) {
            s16 f = 0;
            if ((u8)(arg1 - 2) <= 1) {
                f = 0x81;
            } else if (arg1 <= 1) {
                f = 0x80;
            }
            if (f != 0) {
                NetDispatchSocketEvent(i, e->eventCallback, 2, f);
            }
            break;
        }
    }
    return 0;
}
#pragma push
#pragma dont_inline off
#pragma inline_depth(4)
inline void add_item_80420FC8(Pkt_80420FC8 *pkt, void *data, s32 len) {
    s32 n = pkt->count;
    s32 off = pkt->len;
    pkt->items[n].len = len;
    pkt->len = off + len;
    set_value_and_enable(pkt->items[n].data, (s32)data);
    pkt->count++;
}

s32 udp_input(O_80420DE4 *arg0, NetworkAddress *src, NetworkAddress *dst, s32 arg3) {
    u8 sp20[8];
    Hdr_80420DE4 hdr;
    UdpRuntimeState *g;
    s16 i;
    s16 *plen;
    UdpControlBlock *e;
    plen = &arg0->f18;
    set_value_and_enable(sp20, (s32)&hdr);
    TLobby__sub_80406FD8(sp20, plen + 2, 8);
    if (hdr.sum != 0 && (u16)TLobby__sub_8040D8F0(src, dst, 0x11, arg0, 0) != 0) {
        return -1;
    }
    g = &udp_runtime_state;
    e = g->entries;
    i = 0;
    while (i < g->count) {
        if (e->active == 0) {
            goto next;
        }
        if (is_addr_unspecified(&e->remoteAddress) != 0) {
            if (e->remoteAddress.family != 0 && e->remoteAddress.family != src->family) {
                goto next;
            }
        } else if (compare_sockaddr(&e->remoteAddress, src) != 0) {
            goto next;
        }
        if (is_addr_unspecified(&e->localAddress) != 0) {
            if (e->localAddress.family != 0 && e->localAddress.family != dst->family) {
                goto next;
            }
        } else if (compare_sockaddr(&e->localAddress, dst) != 0) {
            goto next;
        }
        if (e->remotePort != 0 && e->remotePort != hdr.src) {
            goto next;
        }
        if (e->localPort != hdr.dst) {
            goto next;
        }
        arg0->f8 -= 8;
        *plen -= 8;
        TLobby__sub_80406EB8(plen + 2, 8);
        if (TLobby__sub_80421F10(arg0, src, dst, hdr.src, e->receiveCallback, i) != 0) {
            return -1;
        }
        return 0;
    next:
        i++;
        e++;
    }
    if (is_multicast_address(dst, arg3) == 1) {
        return 0;
    }
    return -2;
}

s16 udp_sendto(s16 id, Pkt_80420FC8 *pkt, NetworkAddress *src, NetworkAddress *dst, u16 port, s32 arg5) {
    s16 r;
    UdpControlBlock *e;
    if (id < 0 || id >= udp_runtime_state.count) {
        return -4;
    }
    e = udp_runtime_state.entries;
    e += id;
    if (e->active == 0) {
        return -4;
    }
    if (is_addr_unspecified(&e->remoteAddress) == 0) {
        dst = &e->remoteAddress;
    }
    if (e->localAddress.family != 0) {
        src = &e->localAddress;
    }
    if (src->family != 0 && src->family != dst->family) {
        return -2;
    }
    if (e->remotePort != 0) {
        e->destinationPort = e->remotePort;
    } else {
        e->destinationPort = port;
    }
    if (TLobby__sub_8040DA54(dst, src) == 0) {
        NetDispatchSocketEvent(id, e->eventCallback, 2, 0x80);
        return -6;
    }
    r = select_source_address(src, dst);
    if (r < 0) {
        return r;
    }
    e->length = pkt->len + 8;
    add_item_80420FC8(pkt, &e->sourcePort, 8);
    e->checksum = 0;
    e->checksum = TLobby__sub_8040D8F0(src, dst, 0x11, pkt, 1);
    return dispatch_by_addr_family(pkt, dst, src, arg5 + 4, arg5 + 4, 0x11);
}
#pragma pop

s32 NetUdpClose(s16 id) {
    UdpControlBlock* entry;
    if (id < 0 || id >= udp_runtime_state.count) return -4;
    entry = udp_runtime_state.entries;
    entry += id;
    if (!entry->active) return -4;
    NetDispatchSocketEvent(id, entry->eventCallback, 2, 0xFF);
    entry->active = 0;
    return 0;
}
s16 NetUdpConnect(s16 id, NetworkAddress* remoteAddress, s32 port, s32 eventCallback, u32 receiveCallback) {
    UdpControlBlock* entry;
    if (id < 0 || id >= udp_runtime_state.count) return -4;
    entry = udp_runtime_state.entries;
    entry += id;
    if (!entry->active) return -4;
    if (entry->receiveCallback != 0) return -4;
    if (remoteAddress->family != 0) {
        NetMemcpy(&entry->remoteAddress, remoteAddress, sizeof(NetworkAddress));
    } else {
        NetMemset(&entry->remoteAddress, 0, sizeof(NetworkAddress));
    }
    entry->remotePort = port;
    entry->destinationPort = port;
    entry->eventCallback = eventCallback;
    entry->receiveCallback = receiveCallback;
    return 0;
}

s16 NetUdpBind(s16 id, NetworkAddress* localAddress, s32 port) {
    UdpControlBlock* entry;
    if (id < 0 || id >= udp_runtime_state.count) return -4;
    if (localAddress != NULL && NetValidateLocalAddress(localAddress) < 0) return -4;
    entry = udp_runtime_state.entries;
    entry += id;
    if (!entry->active) return -4;
    if ((u16)port != 0) {
        s16 index = 0;
        UdpControlBlock* other = udp_runtime_state.entries;
        for (; index < udp_runtime_state.count; index++, other++) {
            if (other->active && other->localPort == (u16)port) return -3;
        }
    }
    if (localAddress->family != 0) {
        NetMemcpy(&entry->localAddress, localAddress, sizeof(NetworkAddress));
    } else {
        NetMemset(&entry->localAddress, 0, sizeof(NetworkAddress));
    }
        if ((u16)(s16)port != 0) {
        entry->localPort = port;
    } else {
        entry->localPort = NetUdpAllocateEphemeralPort();
    }
    entry->sourcePort = entry->localPort;
    return 0;
}

#pragma push
#pragma opt_dead_assignments off
s16 NetUdpCreate(void) {
    s16 index = 0;
    UdpControlBlock* entry = udp_runtime_state.entries;
    for (; index < udp_runtime_state.count; index++, entry++) {
        if (!entry->active) {
            entry->signature[0] = 'U';
            entry->signature[1] = 'C';
            entry->signature[2] = 'B';
            entry->index = index;
            entry->active = 1;
            entry->sourcePort = 0;
            entry->destinationPort = 0;
            entry->length = 0;
            entry->checksum = 0;
            entry->localPort = 0;
            entry->remotePort = 0;
            NetMemset(&entry->remoteAddress, 0, sizeof(NetworkAddress));
            NetMemset(&entry->localAddress, 0, sizeof(NetworkAddress));
            entry->receiveCallback = 0;
            entry->eventCallback = 0;
            return index;
        }
    }
    return -0x104;
}

#pragma pop

#pragma push
#pragma dont_inline off
#pragma inline_depth(4)
inline s16 IsUdpPortInUse(u16 port) {
    s16 index = 0;
    UdpControlBlock* entry = udp_runtime_state.entries;
    for (; index < udp_runtime_state.count; index++, entry++) {
        if (entry->active == 1 && port == entry->localPort) return 1;
    }
    return 0;
}

u16 NetUdpAllocateEphemeralPort(void) {
    if (!udp_runtime_state.ephemeralPort) {
        s32 tick;
        NetStoreTick(&tick);
        udp_runtime_state.ephemeralPort = udp_runtime_state.ephemeralPortStart;
        udp_runtime_state.ephemeralPort |= tick & 0x3FF;
    } else if (udp_runtime_state.ephemeralPort < udp_runtime_state.ephemeralPortEnd) {
        udp_runtime_state.ephemeralPort++;
    } else {
        udp_runtime_state.ephemeralPort = udp_runtime_state.ephemeralPortStart;
    }
    while (IsUdpPortInUse(udp_runtime_state.ephemeralPort)) {
        if (udp_runtime_state.ephemeralPort < udp_runtime_state.ephemeralPortEnd) {
            udp_runtime_state.ephemeralPort++;
        } else {
            udp_runtime_state.ephemeralPort = udp_runtime_state.ephemeralPortStart;
        }
    }
    return udp_runtime_state.ephemeralPort;
}
#pragma pop
