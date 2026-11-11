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
typedef struct Hdr_80408C24 Hdr_80408C24;
s16 forward_socket_op_by_handle(s16 id, u8 *a, u8 *b);
s16 init_net_sockets(void);
s32 send_ethernet_frame(s16 idx, s16 mode, u8 *addr, void *pkt);

#include <stddef.h>


#include "pso/network/IPv6Send.h"
#include "pso/network/NetStackTypes.h"

s32 TLobby__sub_8040878C(void);

s32 OSDisableInterrupts(void);
s32 OSRestoreInterrupts(s32);

/* Inline the helpers below; this applies to the rest of the file. */
#pragma dont_inline off
#pragma inline_depth(4)

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

s16 forward_socket_op_by_handle(s16 id, u8 *a, u8 *b) {
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

EthernetState lbl_805C1AD8;
