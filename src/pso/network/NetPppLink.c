/* The PPP link layer (named after NetPppLink.h): its state lobby_net_buffer_desc_b and the framing around it
 * (a C library, built with GC/1.2.5n). */
#include "types.h"
#include "pso/network/TLobby_803FC178.h"
#include "pso/network/TLobby_803FCF44.h"
#include "pso/network/TLobby_804050DC.h"
#include "pso/network/TLobby_8041112C.h"
/* This file's functions. */
s32 clear_socket_slot(s16 i);
#include "pso/network/NetworkRuntime.h"
#include "pso/network/TLobby_804048E8.h"
#include "pso/network/NetworkTransport.h"

#include <stddef.h>
#include "pso/network/NetStackTypes.h"

extern u8 lbl_805C0038[];

void TLobby__sub_803F7980(void *);
void TLobby__sub_803FD0C0(void) {
    PppLink *g = &lobby_net_buffer_desc_b;
    clear_table_entry_locked((s16)(g->id));
    g->id = -1;
    g->count = 0;
    TLobby__sub_803F7980(g);
}

typedef void (*Fn_803FD10C)(void);
s32 TLobby__sub_803FD404(s16 ch, u32 addr);
s32 TLobby__sub_803FD60C();

s16 TLobby__sub_803FD10C(void) {
    Fn_803FD10C fns[11];
    s16 r;
    s16 i;
    s16 *p;

    init_buffer_desc_b(&lobby_net_buffer_desc_b);
    fns[0] = (Fn_803FD10C)TLobby__sub_803FD60C;
    fns[1] = (void (*)())TLobby__sub_803FD5A4;
    fns[2] = (Fn_803FD10C)clear_socket_slot;
    fns[3] = (Fn_803FD10C)get_checked_status_value;
    fns[4] = (Fn_803FD10C)TLobby__sub_803FD4FC;
    fns[5] = (Fn_803FD10C)TLobby__sub_803FD4D8;
    fns[6] = (Fn_803FD10C)TLobby__sub_803FD4B4;
    fns[7] = (Fn_803FD10C)TLobby__sub_803FD490;
    fns[8] = (Fn_803FD10C)TLobby__sub_803FD404;
    fns[9] = (void (*)())TLobby__sub_803FD310;
    fns[10] = (void (*)())TLobby__sub_803FD21C;
    r = TLobby__sub_80409A3C((u8 *)fns, 2);
    if (r < 0) {
        return r;
    }
    lobby_net_buffer_desc_b.id = r;
    lobby_net_buffer_desc_b.protocols[0].used = 0;
    lobby_net_buffer_desc_b.protocols[0].type = 0;
    lobby_net_buffer_desc_b.protocols[1].used = 0;
    lobby_net_buffer_desc_b.protocols[1].type = 0;
    p = lobby_net_buffer_desc_b.used;
    i = 0;
    while (i < lobby_net_buffer_desc_b.count) {
        *p = 0;
        i++;
        p++;
    }
    return r;
}

#pragma push
#pragma optimization_level 3
s32 TLobby__sub_803FD21C(s16 arg0, s32 arg1, s32 arg2, u8 *arg3) {
    s16 len;
    PppFrame *pkt;
    if ((arg0 != 0) && (arg0 != 1)) {
        return -0x112;
    }
    pkt = lbl_805C04A8.ip_out;
    len = TLobby__sub_804098B4(arg3);
    if (lobby_net_buffer_desc_b.size < len) {
        return -0x112;
    }
    lock_mutex(lbl_805C18A0.mutex);
    if ((s16) lobby_modem_connect_state == 4) {
        pkt->data = (u8 *)lbl_805C04A8.ip_out + ((lbl_805C04A8.headroom + 0x83) & 0xFFFFFFFC);
        pkt->len = len;
        TLobby__sub_80409908(pkt->data, arg3);
        TLobby__sub_80406328((s32) pkt, lobby_net_buffer_desc_b.protocols[arg0].type);
    }
    unlock_mutex(lbl_805C18A0.mutex);
    return 0;
}
#pragma pop

#pragma push
#pragma optimization_level 3
s32 TLobby__sub_803FD310(s16 arg0, s32 arg1, u8 *arg2) {
    s16 len;
    PppFrame *pkt;
    if ((arg0 != 0) && (arg0 != 1)) {
        return -0x112;
    }
    pkt = lbl_805C04A8.ip_out;
    len = TLobby__sub_804098B4(arg2);
    if (lobby_net_buffer_desc_b.size < len) {
        return -0x112;
    }
    lock_mutex(lbl_805C18A0.mutex);
    if ((s16) lobby_modem_connect_state == 4) {
        pkt->data = (u8 *)lbl_805C04A8.ip_out + ((lbl_805C04A8.headroom + 0x83) & 0xFFFFFFFC);
        pkt->len = len;
        TLobby__sub_80409908(pkt->data, arg2);
        TLobby__sub_80406328((s32) pkt, lobby_net_buffer_desc_b.protocols[arg0].type);
    }
    unlock_mutex(lbl_805C18A0.mutex);
    return 0;
}
#pragma pop

extern s32 TLobby__sub_803FD404(s16 ch, u32 addr) {
  PppLink *p = &lobby_net_buffer_desc_b;
  s16 new_var;
  s16 size;
  s16 i;
  s16 *used;
  u32 base;
  s16 count;
  if ((ch != 0) && (ch != 1))
  {
    return -0x112;
  }
  used = p->used;
  base = (u32)p->buffers;
  size = p->size;
  count = p->count;
  for (i = 0; i < count; i++, used++)
  {
    if ((((*used) != 0) && (base <= addr)) && (addr < (base + size)))
    {
      *used = 0;
      return 0;
    }
    base += (new_var = size);
  }

  return -0x112;
}

s32 TLobby__sub_803FD490(s16 arg0) {
    if ((arg0 != 0) && (arg0 != 1)) {
        return -0x112;
    }
    return 0;
}

s32 TLobby__sub_803FD4B4(s16 arg0) {
    if ((arg0 != 0) && (arg0 != 1)) {
        return -0x112;
    }
    return 0;
}

s32 TLobby__sub_803FD4D8(s16 arg0) {
    if ((arg0 != 0) && (arg0 != 1)) {
        return -0x112;
    }
    return 0;
}

s32 TLobby__sub_803FD4FC(s16 arg0) {
    if ((arg0 != 0) && (arg0 != 1)) {
        return -0x112;
    }
    return 0;
}

s16 get_checked_status_value(s16 arg0) {
    if ((arg0 != 0) && (arg0 != 1)) {
        return -0x112;
    }
    if (lbl_805D7A7A != 0) {
        return 0x5AE;
    }
    return lobby_net_buffer_desc_b.size;
}

s32 clear_socket_slot(s16 i) {
    PppLink *g;
    if (i != 0 && i != 1) {
        return -0x112;
    }
    g = &lobby_net_buffer_desc_b;
    g->protocols[i].used = 0;
    g->protocols[i].type = 0;
    return 0;
}

s16 TLobby__sub_803FD5A4(s16 h, s16 v) {
    s16 r;
    PppLink *g = &lobby_net_buffer_desc_b;
    if (h != g->id) { return -274; }
    if (g->protocols[0].used == 0) {
        r = 0;
    } else if (g->protocols[1].used == 0) {
        r = 1;
    } else {
        return -274;
    }
    g->protocols[r].used = 1;
    g->protocols[r].type = v;
    return r;
}

typedef struct NetConfigEntry_805BC238 {
    u8 pad0[8];
    u32 unk8;
    u32 unkC;
} NetConfigEntry_805BC238;
s32 TLobby__sub_803FD60C(ch, dst)
    s16 ch;
    u8 *dst;
{
    u8 *q;
    NetConfigEntry_805BC238 *e;
    unsigned short new_var;
    u32 a;
    u32 b;
    u8 *p;
    if (ch != lobby_net_buffer_desc_b.id) {
        return -0x112;
    }
    q = lbl_805C0038 + 0xd4;
    e = *(NetConfigEntry_805BC238 **)(q + 0x30);
    if (*q != 5) {
        return -0x112;
    }
    a = e->unk8;
    b = e->unkC;
    p = dst + 1;
    dst[0] = a >> 24;
    new_var = a;
    p[0] = a >> 16;
    p[1 & 0xFFFFFFFFu] = new_var >> 8;
    p[2] = new_var;
    p[3] = b >> 24;
    p[4] = b >> 16;
    p[5] = b >> 8;
    p[6] = b;
    return 0;
}

PppLink lobby_net_buffer_desc_b;
