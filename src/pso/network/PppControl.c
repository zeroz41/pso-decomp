/* PPP connection control: the connect records (.bss 805C0638), the calls the session layer (803FB7A4) makes
 * and the modem wrappers (a C library, built with GC/1.2.5n). PppControl is an inferred name. */
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

s32 TLobby__sub_80403DA8();
s32 send_network_frame(u16, u8 *);
extern u8 lbl_805C0038[];

s32 TLobby__sub_804036FC(u8 *arg0) {
    if (TLobby__sub_803F811C((s16 *)arg0) != 0) {
        return -1;
    }
    return 0;
}

s32 TLobby__sub_80403730(u8 *dst, unsigned short n) {
  u8 buf;
  u16 st;
  while (((u16) n) != 0)
  {
    if ((recv_network_frame(1, &buf, &st) != 0) && (st != 1))
    {
      return -1;
    }
    *(dst++) = buf;
    n--;
  }
  return 0;
}

s32 TLobby__sub_804037B0(s32 src, u16 len) {
    if (send_network_frame(len, (u8 *)src) != 0) {
        return -1;
    }
    return 0;
}

void TLobby__sub_804061FC(int);
s32 TLobby__sub_804037F0(void) {
    TLobby__sub_803FD85C(lbl_805C0038 + 0xD4);
    TLobby__sub_803FD85C(lbl_805C0038 + 0x6C);
    TLobby__sub_803FD85C(lbl_805C0038 + 0x38);
    TLobby__sub_803FD85C(lbl_805C0038 + 0xA0);
    TLobby__sub_803FD85C(lbl_805C0038 + 4);
    lbl_805C0038[0] = 0;
    if (reset_network_timer_list() == 0) {
        TLobby__sub_804061FC(0);
    }
    return 0;
}

s32 TLobby__sub_80403864(void) {
    u8 *g = lbl_805C0038;
    u8 *p = g + 0xD4;
    s16 st = lbl_805D7A7C;
    u8 *q;

    if ((st == 6 || st == 0) && TLobby__sub_803FF304(p) != 0) {
        return -0x11;
    }
    q = g + 0x6C;
    if (TLobby__sub_803FF304(q) != 0) {
        return -0x11;
    }
    if (TLobby__sub_803FED78(q) != 0) {
        return -0x11;
    }
    return 0;
}

s32 TLobby__sub_804038F4(s32 arg0, s32 arg1, s32 arg2) {
    u8 *temp_r31;
    u8 *temp_r6;
    s16 clear_flag_bit4(s32 arg0, u8 *arg1);
    s16 NetIPv6CPSetInterfaceIdentifier(u8 *arg0, s32 arg1);

    temp_r6 = lbl_805C0038 + 0xD4;
    temp_r31 = *(u8 **)((s8 *)temp_r6 + 0x30);
    set_flags_and_state((void *)temp_r6);
    if (clear_flag_bit4(arg0, temp_r31) != 0) {
        return -0x11;
    }
    if (clear_flag_bit4(arg0, temp_r31 + 0x34) != 0) {
        return -0x11;
    }
    if (NetIPv6CPSetInterfaceIdentifier(temp_r31, arg1) != 0) {
        return -0x11;
    }
    if (NetIPv6CPSetInterfaceIdentifier(temp_r31 + 0x34, arg2) != 0) {
        return -0x11;
    }
    return 0;
}

s32 TLobby__sub_804039C8(s16 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6) {
    u8 *temp_r31;
    u8 *temp_r10;
    s16 set_socket_flags_by_mode(s16 arg0, u8 *arg1);
    s16 TLobby__sub_803FF2CC(u8 *arg0, s32 arg1);
    s16 set_filter_id(u8 *arg0, s32 arg1);
    s16 set_filter_index(u8 *arg0, s32 arg1);
    s16 set_target_id(u8 *arg0, s32 arg1);
    s16 set_target_index(u8 *arg0, s32 arg1);
    s16 set_target_slot(u8 *arg0, s32 arg1);
    temp_r10 = lbl_805C0038 + 0x6C;
    temp_r31 = *(u8 **)((s8 *)temp_r10 + 0x30);
    set_flags_and_state((void *)temp_r10);
    if (set_socket_flags_by_mode(arg0, temp_r31) != 0) {
        return -0x11;
    }
    if (set_socket_flags_by_mode(arg0, temp_r31 + 0x4C) != 0) {
        return -0x11;
    }
    if (TLobby__sub_803FF2CC(temp_r31, arg1) != 0) {
        return -0x11;
    }
    if (set_target_slot(temp_r31, arg3) != 0) {
        return -0x11;
    }
    if (set_filter_id(temp_r31, arg4) != 0) {
        return -0x11;
    }
    if (set_target_id(temp_r31 + 0x4C, arg2) != 0) {
        return -0x11;
    }
    if (set_filter_index(temp_r31 + 0x4C, arg5) != 0) {
        return -0x11;
    }
    if (set_target_index(temp_r31 + 0x4C, arg6) != 0) {
        return -0x11;
    }
    return 0;
}

s32 TLobby__sub_80403B04(u8 *arg0, u8 *arg1, s32 arg2) {
    u8 *g = lbl_805C0038;
    u8 *c = g + 0xA0;
    s16 r;
    s16 st;
    TLobby__sub_803FC684(arg0, arg1, c);
    r = TLobby__sub_803FC1CC((Conn_804004DC *)c, arg2);
    if (r < 0) {
        if (r == -0x12) {
            return -0x12;
        }
        return -0x11;
    }
    set_flags_and_state((void *)(g + 0x6C));
    st = lbl_805D7A7C;
    if (st == 6 || st == 0) {
        set_flags_and_state((void *)(g + 0xD4));
    }
    return 0;
}

s32 TLobby__sub_80403BA8(u8 *arg0, u8 *arg1, s32 arg2) {
    u8 *g = lbl_805C0038;
    u8 *c = g + 0x38;
    s16 r;
    s16 st;
    if (lbl_805D7A90 & 1) {
        TLobby__sub_80403168(arg0, arg1, c);
        TLobby__sub_803FE658(c);
    }
    r = TLobby__sub_80402BB4(c, arg2);
    if (r < 0) {
        if (r == -0x12) {
            return -0x12;
        }
        return -0x11;
    }
    set_flags_and_state((void *)(g + 0x6C));
    st = lbl_805D7A7C;
    if (st == 6 || st == 0) {
        set_flags_and_state((void *)(g + 0xD4));
    }
    return 0;
}

s32 TLobby__sub_80403C60(u8 *arg0) {
    u8 *temp_r31;
    u8 *var_r3;
    u8 *temp_r3;
    s16 wait_for_connection(int);

    TLobby__sub_803F808C();
    temp_r31 = (u8 *)lbl_805C0038 + 4;
    if (TLobby__sub_80400744((int) (temp_r31), (void *) (arg0)) != 0) {
        return -0x11;
    }
    if (wait_for_connection((int) (temp_r31)) != 0) {
        return -0x11;
    }
    if ((u16) *(u16 *)((s8 *)arg0 + 6) == 4) {
        var_r3 = *(u8 **)((s8 *)temp_r31 + 0x30);
        temp_r3 = var_r3;
        var_r3 += 0x34;
        if (lbl_805D7A90 & 2) {
            var_r3 = temp_r3;
        }
        if (*(u16 *)((s8 *)var_r3 + 0x24) == 0xC023) {
            *(u16 *)((s8 *)arg0 + 6) = 0x80U;
        }
        if (*(u16 *)((s8 *)var_r3 + 0x24) == 0xC223) {
            *(u16 *)((s8 *)arg0 + 6) = 0x82U;
        }
    }
    return 0;
}

/* lbl_805C0638: eight records whose first byte TLobby__sub_80403D28 clears before each connect; nothing else in the game
 * reads or writes them. */
typedef struct ConnectRecord {
    s8 active;
    u8 pad1[0x13];
} ConnectRecord;
typedef char ConnectRecord_size_check[sizeof(ConnectRecord) == 0x14 ? 1 : -1];
extern ConnectRecord lbl_805C0638[8];

s32 TLobby__sub_80403D28(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7) {
    s32 temp_r31;
    lbl_805C0638[0].active = 0;
    lbl_805C0638[1].active = 0;
    lbl_805C0638[2].active = 0;
    lbl_805C0638[3].active = 0;
    lbl_805C0638[4].active = 0;
    lbl_805C0638[5].active = 0;
    lbl_805C0638[6].active = 0;
    lbl_805C0638[7].active = 0;
    temp_r31 = TLobby__sub_80403DA8((void *) (arg1), (void *) (arg2), (void *) (arg3), (void *) (arg4), (void *) (arg5), (void *) (arg6), (void *) (arg7));
    TLobby__sub_804062A0(0x82);
    return temp_r31;
}

s32 TLobby__sub_80403DA8(a, b, c, d, e, f, h)
    s16 a;
    s16 b;
    s16 c;
    s16 d;
    s16 e;
    void *f;
    s16 h;
{
    s32 open_network_transport(void *);
struct {
s32 v[6];
s16 x;
s16 y;
void* z;
} s;
s32 t;
if (a == 0) {
t = 0;
} else if (a == 1) {
t = 1;
} else {
t = 0;
}
s.v[0] = t;
if (b == 0) {
t = 2;
} else if (b == 1) {
t = 1;
} else if (b == 2) {
t = 0;
} else {
t = 2;
}
s.v[1] = t;
if (c == 0) {
t = 0;
} else if (c == 1) {
t = 2;
} else {
t = 0;
}
s.v[2] = t;
s.v[3] = 1;
if (d == 0) {
t = 0;
} else if (d == 1) {
t = 1;
} else if (d == 2) {
t = 2;
} else if (d == 3) {
t = 3;
} else if (d == 4) {
t = 4;
} else if (d == 5) {
t = 5;
} else if (d == 6) {
t = 6;
} else {
t = 2;
}
s.v[4] = t;
if (e == 2) {
t = 0;
} else if (e == 3) {
t = 1;
} else {
t = 1;
}
s.v[5] = t;
s.x = 0;
s.z = f;
if (h != 0) {
s.y = 1;
} else {
s.y = 0;
}
if (open_network_transport(&s) != 0) {
return -1;
}
lbl_805D7A7E = 1;
return 0;
}

ConnectRecord lbl_805C0638[8];
