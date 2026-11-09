/* The network stack's session/state layer, second file (a C library, built with GC/1.2.5n): the PPP state
 * machines and their option handling. */
#include "types.h"
#include "pso/network/TLobby_803FC178.h"
#include "pso/network/TLobby_803FCF44.h"
#include "pso/network/TLobby_804050DC.h"
#include "pso/network/TLobby_8041112C.h"
typedef struct Obj_803FEF4C Obj_803FEF4C;
typedef struct Bits_803FF698 Bits_803FF698;
typedef struct Self_803FF698 Self_803FF698;
typedef struct Src_803FC178 Src_803FC178;
typedef struct St_8040098C St_8040098C;
typedef struct RecoveredGlobal_80401A90_lbl_805C04A8 RecoveredGlobal_80401A90_lbl_805C04A8;
typedef struct RecoveredGlobal_80402B88_lbl_805C0620 RecoveredGlobal_80402B88_lbl_805C0620;
typedef struct Ent_80400744 Ent_80400744;
typedef struct Self_80400744 Self_80400744;
typedef struct Msg_80400744 Msg_80400744;
typedef struct RecoveredFields_80401B8C_arg0 RecoveredFields_80401B8C_arg0;
typedef struct RecoveredGlobal_803FD21C_lobby_net_buffer_desc_b RecoveredGlobal_803FD21C_lobby_net_buffer_desc_b;
typedef struct RecoveredGlobal_803FD310_lobby_net_buffer_desc_b RecoveredGlobal_803FD310_lobby_net_buffer_desc_b;
typedef struct E_803FD560 E_803FD560;
typedef struct G_803FD560 G_803FD560;
typedef struct P_803FF48C P_803FF48C;
typedef struct Q_803FF48C Q_803FF48C;
typedef struct Opt_80400338 Opt_80400338;
typedef struct G_80401B20 G_80401B20;
typedef struct G_80401CE8 G_80401CE8;
/* This file's functions. */
u8 * alloc_from_buffer(void *self, s16 arg1);
s32 clear_socket_slot(s16 i);
s32 configure_mode_by_type(void *self, s16 type);
void dispatch_received_packet(void *self, s32 arg1);
void free_field_98(void *self);
void free_field_98_and_clear(void *self);
s16 get_checked_status_value(s16 arg0);
u16 get_field_4(void *self);
void handle_request_timeout(void *self);
void init_md5_state(void *self);
void init_net_block_620(void);
s32 init_net_block_620_secondary(void);
void init_net_state_a(void);
s32 init_net_state_b(void);
void init_net_state_c(void);
s32 init_net_subsystem_block(void);
s32 mark_ready(void *self);
s32 mark_sub_ready(void *obj);
s16 parse_lcp_option(s32 arg0, u8 *arg1, u8 *arg2, u8 *arg3, s16 arg4);
void queue_command_81(void);
s32 read_2_bytes(void *self, void *src);
void reset_connection_slot(void *self);
void reset_connection_state(void *self);
void save_timer_state(void *self);
void set_active(void *self);
s32 set_active_flag(void *self);
s32 set_flags_and_state(void *self);
void update_connection_state(int arg0);
void MD5Transform(u32 *state, u8 *block);
u8 *write_network_u32_be(u8 *p, u32 v);
#include "pso/network/NetworkRuntime.h"
#include "pso/network/TLobby_804048E8.h"
extern s32 is_timed_out(void);
extern void set_ppp_auth_protocol(u16 protocol);
#include "pso/network/NetworkTransport.h"

struct Obj_803FEF4C {
    u32 w0;
    u16 h4;
    s16 h6;
    u8 b8;
    u8 b9;
    u8 bA;
    u8 bB;
    s32 wC;
    void *fn[11];
};

typedef struct IpcpState {
    Obj_803FEF4C proto;
    u8 data[0xD8 - sizeof(Obj_803FEF4C)];
} IpcpState;

typedef struct LcpState {
    Obj_803FEF4C proto;
    u8 data[0xA8 - sizeof(Obj_803FEF4C)];
} LcpState;

extern IpcpState lbl_805C0328;
struct Blk36_8047FE18 { u32 w[9]; };

struct Self_803FD74C;

struct Self_803FD85C;

struct Bits_803FF698 { u8 pad[0x28]; s16 f28; };
struct Self_803FF698 { u8 f0; u8 f1; u8 pad2[0x2E]; Bits_803FF698 *f30; };
struct Src_803FC178 { u32 f0; u32 f4; u16 f8; u16 fA; u16 fC; u16 fE; u8 pad10; u8 f11; u8 f12; u8 f13; u8 f14; u8 f15; u8 f16; u8 f17; u8 f18[0x2C]; };

/* LCP option values; mask has bit N set for option type N. */
typedef struct LcpVals {
    s16 mask;
    u16 mru;
    u32 accm;
    u16 auth_proto;
    u8 pad0A[2];
    s32 magic;
    u8 pad10[4];
    u8 chap_alg;
    u8 f15;
    u8 pad16[2];
} LcpVals;
typedef char LcpVals_size_check[sizeof(LcpVals) == 0x18 ? 1 : -1];

/* One side of the LCP negotiation: the options wanted and the ones agreed. */
typedef struct LcpSide {
    s16 mask;
    u8 pad2[2];
    LcpVals want;
    LcpVals got;
} LcpSide;
typedef char LcpSide_size_check[sizeof(LcpSide) == 0x34 ? 1 : -1];

/* The LCP options object (fsm->p30, lbl_805C0400's opts). */
typedef struct LcpOpts {
    LcpSide local;
    LcpSide remote;
} LcpOpts;
typedef char LcpOpts_size_check[sizeof(LcpOpts) == 0x68 ? 1 : -1];
struct St_8040098C { s8 f0; u8 f1; u8 f2; u8 pad3[0x69]; u8 f6C[0x9C]; s32 f108; s32 f10C; };

struct RecoveredGlobal_80401A90_lbl_805C04A8 {
    s32 value;
    u8 remaining[0x2C];
};

struct RecoveredGlobal_80402B88_lbl_805C0620 {
    s32 value;
    u8 remaining[0x14];
};

#include <stddef.h>
#include "pso/network/NetStackTypes.h"

typedef struct Ent_80400744 { s16 f0; s16 f2; s16 f4; s16 f6; u32 f8; u32 fC; u32 f10; } Ent_80400744;
struct Self_80400744 { u8 pad[0xC]; u8 *f0C; u8 pad10[0x20]; Ent_80400744 *f30; };
struct Msg_80400744 { u32 f0; s16 f4; u16 f6; u32 f8; u16 fC; s16 fE; };

struct RecoveredFields_80401B8C_arg0 {
    s32 field_0;
    u16 field_4;
};

typedef struct Cfg_804019A8 {
    u8 pad[4];
    s16 flags;
    u8 pad6[6];
    u16 mode;
    u8 padE[0xA];
    u8 b18;
    u8 b19;
} Cfg_804019A8;

struct RecoveredGlobal_803FD21C_lobby_net_buffer_desc_b {
    s32 value;
    u8 remaining[0x14];
};

struct RecoveredGlobal_803FD310_lobby_net_buffer_desc_b {
    s32 value;
    u8 remaining[0x14];
};

extern RecoveredGlobal_804050DC_lbl_805C18A0 lbl_805C18A0;
extern RecoveredGlobal_803FD520_lbl_805C0310 lobby_net_buffer_desc_b;
s32 TLobby__sub_803F79BC(void *);
s32 TLobby__sub_803F778C(void *);
s32 TLobby__sub_804036FC(u8 *arg0);
s32 TLobby__sub_80403DA8();
void TLobby__sub_803F8A08(void *);
void TLobby__sub_803F8A9C(void *);
s32 send_network_frame(u16, u8 *);
s32 TLobby__sub_804037B0(s32 arg0, u16 arg1);
void TLobby__sub_803F892C(void *);
void TLobby__sub_803F8958(void *);
void TLobby__sub_803F87DC(void *);
extern Tbl_80408718 lbl_805C1AB0;
void TLobby__sub_803F97E8(int);
extern u8 lbl_805C0038[];
s16 TLobby__sub_80401BCC(void *self, void *dst, u16 n);
s32 TLobby__sub_80403730(u8 *dst, unsigned short n);

extern s16 get_remaining(s32 x);

struct Buf_803FC684;
struct N_80405298;

struct O_80400ACC;
struct Outer_80401CAC;

struct Ent_80401B20;
inline s32 chap_rbs_803FC820(B_803FADA0 **src) {
    if (TLobby__sub_80401BCC(src, &lbl_805D7A98, 1) != 1) {
        return -1;
    }
    return (s16)lbl_805D7A98;
}
inline s32 chap_rb_803FC820(B_803FADA0 **src) {
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
        return *(*src)->buf++;
    }
    return chap_rbs_803FC820(src);
}

inline s32 rd_803FCC10(UnkSumBuf **pp) {
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
extern u32 lbl_805E1158;
extern u16 lbl_805E115C;
extern u8 lbl_805E115E;
void *TLobby__sub_803FCF44(Conn_804004DC *c)
{
  PppChap *chap = c->opts;
  s32 tick;
  char name[] = "avetcp";
  B_803FADA0 *buf;
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
  p = buf->buf;
  NetStoreTick(&tick);
  *(u16 *)&lbl_805D7A9A = (tick & 0x1F) + 0x10;
  *p++ = *(u16 *)&lbl_805D7A9A;
  NetStoreTick(&tick);
  for (i = 0; i < *(u16 *)&lbl_805D7A9A; i++)
  {
    *p++ = tick;
  }
  NetCopyString((char *)p, name);
  buf->len += *(u16 *)&lbl_805D7A9A + (u16)NetStringLength(name) + 1;
  len = buf->len;
  lim = lbl_805C02D0.f28;
  n = len;
  if ((s16)len > lim)
  {
    n = lim;
  }
  NetMemcpy(lbl_805C02D0.p8, buf->buf, n);
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

void TLobby__sub_803F7980(void *);
void TLobby__sub_803FD0C0(void) {
    RecoveredGlobal_803FD520_lbl_805C0310 *g = &lobby_net_buffer_desc_b;
    clear_table_entry_locked((s16)(g->h0));
    g->h0 = -1;
    g->h16 = 0;
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

    init_buffer_desc_b((void *)(&lobby_net_buffer_desc_b));
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
    lobby_net_buffer_desc_b.h0 = r;
    lobby_net_buffer_desc_b.h2 = 0;
    lobby_net_buffer_desc_b.h4 = 0;
    lobby_net_buffer_desc_b.h6 = 0;
    lobby_net_buffer_desc_b.h8 = 0;
    p = lobby_net_buffer_desc_b.buf;
    i = 0;
    while (i < lobby_net_buffer_desc_b.h16) {
        *p = 0;
        i++;
        p++;
    }
    return r;
}

#pragma push
#pragma optimization_level 3
typedef char RecoveredGlobal_803FD21C_lobby_net_buffer_desc_b_size[sizeof(RecoveredGlobal_803FD21C_lobby_net_buffer_desc_b) == 0x18 ? 1 : -1];
s32 TLobby__sub_803FD21C(s16 arg0, s32 arg1, s32 arg2, u8 *arg3) {
    s16 temp_r3;
    u8 *temp_r31;
    if ((arg0 != 0) && (arg0 != 1)) {
        return -0x112;
    }
    temp_r31 = (u8 *)(*(u8 **)((s8 *)((s32 *)&lbl_805C04A8) + 0x14));
    temp_r3 = TLobby__sub_804098B4(arg3);
    if ((s16) *(s16 *)((s8 *)(&(*(RecoveredGlobal_803FD21C_lobby_net_buffer_desc_b *)&lobby_net_buffer_desc_b).value) + 0x14) < temp_r3) {
        return -0x112;
    }
    lock_mutex((int)((void *) (((s32 *)&lbl_805C18A0)[0])));
    if ((s16) lobby_modem_connect_state == 4) {
        *(s32 *)((s8 *)temp_r31 + 0) = (s32) ((u8 *)(*(u8 **)((s8 *)((s32 *)&lbl_805C04A8) + 0x14)) + ((*(s32 *)((s8 *)((s32 *)&lbl_805C04A8) + 0) + 0x83) & 0xFFFFFFFC));
        *(s16 *)((s8 *)temp_r31 + 4) = temp_r3;
        TLobby__sub_80409908((void *)(*(s32 *)((s8 *)temp_r31 + 0)), (void *)(arg3));
        TLobby__sub_80406328((s32) temp_r31, *(s16 *)((s8 *)((u8 *)(&(*(RecoveredGlobal_803FD21C_lobby_net_buffer_desc_b *)&lobby_net_buffer_desc_b).value) + (arg0 * 4)) + 4));
    }
    unlock_mutex((int)((void *) (((s32 *)&lbl_805C18A0)[0])));
    return 0;
}
#pragma pop

#pragma push
#pragma optimization_level 3
typedef char RecoveredGlobal_803FD310_lobby_net_buffer_desc_b_size[sizeof(RecoveredGlobal_803FD310_lobby_net_buffer_desc_b) == 0x18 ? 1 : -1];
s32 TLobby__sub_803FD310(s16 arg0, s32 arg1, u8 *arg2) {
    s16 temp_r3;
    u8 *temp_r31;
    if ((arg0 != 0) && (arg0 != 1)) {
        return -0x112;
    }
    temp_r31 = (u8 *)(*(u8 **)((s8 *)((s32 *)&lbl_805C04A8) + 0x14));
    temp_r3 = TLobby__sub_804098B4(arg2);
    if ((s16) *(s16 *)((s8 *)(&(*(RecoveredGlobal_803FD310_lobby_net_buffer_desc_b *)&lobby_net_buffer_desc_b).value) + 0x14) < temp_r3) {
        return -0x112;
    }
    lock_mutex((int)((void *) (((s32 *)&lbl_805C18A0)[0])));
    if ((s16) lobby_modem_connect_state == 4) {
        *(s32 *)((s8 *)temp_r31 + 0) = (s32) ((u8 *)(*(u8 **)((s8 *)((s32 *)&lbl_805C04A8) + 0x14)) + ((*(s32 *)((s8 *)((s32 *)&lbl_805C04A8) + 0) + 0x83) & 0xFFFFFFFC));
        *(s16 *)((s8 *)temp_r31 + 4) = temp_r3;
        TLobby__sub_80409908((void *)(*(s32 *)((s8 *)temp_r31 + 0)), (void *)(arg2));
        TLobby__sub_80406328((s32) temp_r31, *(s16 *)((s8 *)((u8 *)(&(*(RecoveredGlobal_803FD310_lobby_net_buffer_desc_b *)&lobby_net_buffer_desc_b).value) + (arg0 * 4)) + 4));
    }
    unlock_mutex((int)((void *) (((s32 *)&lbl_805C18A0)[0])));
    return 0;
}
#pragma pop

extern s32 TLobby__sub_803FD404(s16 ch, u32 addr) {
  p803FB184_Unk805BC510 *p = &(*(p803FB184_Unk805BC510*)&lobby_net_buffer_desc_b);
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
  used = p->unkC;
  base = p->unk10;
  size = p->unk14;
  count = p->unk16;
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

typedef char RecoveredGlobal_803FD520_lbl_805C0310_size[sizeof(RecoveredGlobal_803FD520_lbl_805C0310) == 0x18 ? 1 : -1];
s16 get_checked_status_value(s16 arg0) {
    if ((arg0 != 0) && (arg0 != 1)) {
        return -0x112;
    }
    if (lbl_805D7A7A != 0) {
        return 0x5AE;
    }
    return *(s16 *)((s8 *)(&lobby_net_buffer_desc_b.h0) + 0x14);
}

typedef struct E_803FD560 { s16 a; s16 b; } E_803FD560;
struct G_803FD560 { s16 id; E_803FD560 e[2]; };
s32 clear_socket_slot(s16 i) {
    G_803FD560 *g;
    if (i != 0 && i != 1) {
        return -0x112;
    }
    g = (G_803FD560 *)&lobby_net_buffer_desc_b;
    g->e[i].a = 0;
    g->e[i].b = 0;
    return 0;
}

void update_countdown_state(void *);

s16 TLobby__sub_803FD5A4(s16 h, s16 v) {
    s16 r;
    G_803FD560 *g = ((G_803FD560 *)&lobby_net_buffer_desc_b);
    if (h != g->id) { return -274; }
    if (g->e[0].a == 0) {
        r = 0;
    } else if (g->e[1].a == 0) {
        r = 1;
    } else {
        return -274;
    }
    g->e[r].a = 1;
    g->e[r].b = v;
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
    if (ch != *(s16 *)&lobby_net_buffer_desc_b) {
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

void TLobby__sub_803FD694(u8 *arg0) {
    s8 var_r0;
    u8 *temp_r31;
    u8 *temp_r4;

    temp_r31 = (u8 *)(arg0 + 0x10);
    *(u8 *)((s8 *)arg0 + 4) = (u8) *(u8 *)((s8 *)(*(u8 **)((s8 *)arg0 + 0x2C)) + 9);
    *(u8 *)((s8 *)arg0 + 7) = (u8) *(u8 *)((s8 *)(*(u8 **)((s8 *)arg0 + 0x2C)) + 0xA);
    *(u8 *)((s8 *)arg0 + 5) = (u8) *(u8 *)((s8 *)(*(u8 **)((s8 *)arg0 + 0x2C)) + 0xB);
    if (*(u8 *)((s8 *)arg0 + 2) & 0xC0) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    *(s8 *)((s8 *)arg0 + 0) = var_r0;
    *(u8 *)((s8 *)arg0 + 3) = (u8) *(u8 *)((s8 *)arg0 + 4);
    *(u8 *)((s8 *)arg0 + 6) = (u8) *(u8 *)((s8 *)arg0 + 7);
    temp_r4 = (u8 *)(*(u8 **)((s8 *)arg0 + 0x2C));
    (*(s32 (**)(void *, void *))((s8 *)temp_r4 + 0x14))(arg0, temp_r4);
    *(void **)((s8 *)temp_r31 + 0x10) = (void *)update_countdown_state;
    *(u8 **)((s8 *)temp_r31 + 0x14) = arg0;
    TLobby__sub_80405298((N_80405298 *) (temp_r31), (s32) (*(s32 *)((s8 *)(*(u8 **)((s8 *)arg0 + 0x2C)) + 0xC)));
}

#define self ((Self_803FD74C *)arg0)
void update_connection_state(int arg0) {
    if (self->f30 == 0) {
        return;
    }
    switch (self->f0) {
    case 5:
        self->tbl->f20(self);
    case 4:
        self->f3 = self->f5;
        if (self->f3 != 0) {
            self->f3--;
            TLobby__sub_80405328(self->f10);
            TLobby__sub_803FE6CC(self, 5, 0, 0);
        }
        self->f0 = 6;
        break;
    case 2:
    case 3:
        self->f3 = 0;
        self->f0 = 6;
        break;
    case 1:
        if (lbl_805D7A90 & 2) {
            if (self->f3 != 0) {
            self->f3--;
            TLobby__sub_80405328(self->f10);
            TLobby__sub_803FE6CC(self, 5, 0, 0);
        }
        }
        self->f0 = 0;
        break;
    case 6:
        break;
    }
}
#undef self

#define self ((Self_803FD85C *)arg0)
void TLobby__sub_803FD85C(void *arg0) {
    if (self->f30 != NULL) {
        switch (self->f0) {
        case 2:
        case 3:
        case 4:
            TLobby__sub_80405304(self->f10);
            self->f0 = (self->f2 & 0xC0) ? 1 : 0;
            self->f3 = self->f4;
            self->f6 = self->f7;
            self->tbl->f14(self, self->tbl);
            break;
        case 5:
            self->tbl->f20(self, self->tbl);
        case 6:
            self->f0 = (self->f2 & 0xC0) ? 1 : 0;
            self->f3 = self->f4;
            self->f6 = self->f7;
            self->tbl->f14(self, self->tbl);
            break;
        }
    }
}
#undef self

void TLobby__sub_803FD958(u8 *arg0) {
  u8 temp_r0;
  u8 temp_r3;
  u8 var_r0;
  int new_var;
  u8 *temp_r4;
  u8 *temp_r4_2;
  u8 *temp_r4_3;
  if ((((u32) (*((u32 *) (((s8 *) arg0) + 0x30)))) != 0U) && ((*((u8 *) (((s8 *) arg0) + 2))) & 0xC0))
  {
    temp_r0 = *((u8 *) (((s8 *) arg0) + 0));
    if (((s32) temp_r0) != 6)
    {
      if ((((s32) temp_r0) < 6) && (((s32) temp_r0) < 2))
      {
        if (((s32) temp_r0) < 0)
        {
          return;
          if (((!temp_r0) && (!temp_r0)) && (!temp_r0))
          {
          }
        }
        goto block_7;
      }
    }
    else
    {
      new_var = 0x18;
      block_7:
      temp_r4 = (u8 *) (*((u8 **) (((s8 *) arg0) + 0x2C)));
      (*((s32 (**)(void *, void *)) (((s8 *) temp_r4) + new_var)))(arg0, temp_r4);
      if ((*((u8 *) (((s8 *) arg0) + 2))) & 0xC0)
      {
        var_r0 = 1;
      }
      else
      {
        var_r0 = 0;
      }
      *((u8 *) (((s8 *) arg0) + 0)) = var_r0;
      *((u8 *) (((s8 *) arg0) + 3)) = (u8) (*((u8 *) (((s8 *) arg0) + 4)));
      *((u8 *) (((s8 *) arg0) + 6)) = (u8) (*((u8 *) (((s8 *) arg0) + 7)));
      temp_r4_2 = (u8 *) (*((u8 **) (((s8 *) arg0) + 0x2C)));
      (*((s32 (**)(void *, void *)) (((s8 *) temp_r4_2) + 0x14)))(arg0, temp_r4_2);
      if ((*((u8 *) (((s8 *) arg0) + 2))) & 0x80)
      {
        temp_r3 = *((u8 *) (((s8 *) arg0) + 3));
        if (temp_r3 != 0)
        {
          *((u8 *) (((s8 *) arg0) + 3)) = (u8) (temp_r3 - 1);
          TLobby__sub_80405328((u8 *)((void *) (((u8 *) arg0) + 0x10)));
          temp_r4_3 = (u8 *) (*((u8 **) (((s8 *) arg0) + 0x2C)));
          TLobby__sub_803FE6CC((void *) arg0, 1, 0, (void *) (*((s32 (**)(void *, void *)) (((s8 *) temp_r4_3) + 0x28)))(arg0, temp_r4_3));
        }
        *((u8 *) (((s8 *) arg0) + 0)) = 2U;
      }
    }
  }
}

struct Self_803FDA68;

void update_countdown_state(void *arg0) {
    Self_803FDA68 *self = (Self_803FDA68 *)arg0;
    switch (self->f0) {
    case 2:
    case 3:
    case 4:
        if (self->f3 != 0) {
            if (self->f3 > 0) {
                self->f3--;
                TLobby__sub_80405328(self->f10);
                TLobby__sub_803FE6CC(self, 1, 0, self->tbl->f28(self, self->tbl));
            }
            if (self->f0 == 3) {
                self->f0 = 2;
            }
        } else {
            self->f0 = (self->f2 & 0xC0) ? 1 : 0;
            self->f3 = self->f4;
            self->f6 = self->f7;
            self->tbl->f14(self, self->tbl);
            self->f8 = 1;
        }
        break;
    case 6:
        if (self->f3 != 0) {
            if (self->f3 > 0) {
                self->f3--;
                TLobby__sub_80405328(self->f10);
                TLobby__sub_803FE6CC(self, 5, 0, 0);
            }
        } else {
            self->tbl->f24(self, self->tbl);
            self->f0 = (self->f2 & 0xC0) ? 1 : 0;
            self->f3 = self->f4;
            self->f6 = self->f7;
            self->tbl->f14(self, self->tbl);
            self->f8 = 1;
        }
        break;
    }
}

static inline s16 read_packet_header(Hdr_803FC4B4 *dst, void *src, s32 with_ext) {
    u8 ext[8];
    u8 buf[4];
    if (dst == 0) {
        return -1;
    }
    if (TLobby__sub_80401BCC(src, buf, 4) < 4) {
        return -1;
    }
    dst->type = buf[0];
    dst->flag = buf[1];
    dst->len = read_network_u16_be(buf + 2);
    if (with_ext && TLobby__sub_80401BCC(src, ext, 8) < 8) {
        return -1;
    }
    return 0;
}

#pragma push
#pragma opt_common_subs on
#pragma dont_inline off
#pragma inline_depth(4)
void TLobby__sub_803FDBF8(u8 *self, void *arg1)
{
    s16 TLobby__sub_803FE6CC();
    extern s32 lbl_805D7AA0;
    Hdr_803FC4B4 hdr;
    s16 rc;
    u8 *newbuf;
    u8 *dp;

    rc = read_packet_header(&hdr, &arg1, 0);
    if (rc != 0) {
        return;
    }
    hdr.len -= 4;
    TLobby__sub_80401CAC((Outer_80401CAC *)&arg1, hdr.len);
    switch (hdr.type) {
    case 1:
        switch (self[0]) {
        case 5:
            (*(void (**)(void *))(*(u8 **)(self + 0x2c) + 0x20))(self);
            self[0] = ((self[2] & 0xC0) != 0) ? 1 : 0;
            self[3] = self[4];
            self[6] = self[7];
            (*(void (**)(void *))(*(u8 **)(self + 0x2c) + 0x14))(self);
        case 1:
            (*(void (**)(void *))(*(u8 **)(self + 0x2c) + 0x18))(self);
            if (self[3] != 0) {
                self[3]--;
                TLobby__sub_80405328(self + 0x10);
                TLobby__sub_803FE6CC(self, 1, 0, (*(void *(**)(void *))(*(u8 **)(self + 0x2c) + 0x28))(self));
            }
        case 2:
        case 4:
            if ((*(s16 (**)(void *, void *, void *))(*(u8 **)(self + 0x2c) + 0x2c))(self, &hdr, arg1) == 0) {
                self[0] = 4;
            } else {
                self[0] = 2;
            }
            break;
        case 3:
            if ((*(s16 (**)(void *, void *, void *))(*(u8 **)(self + 0x2c) + 0x2c))(self, &hdr, arg1) == 0) {
                TLobby__sub_80405304(self + 0x10);
                (*(void (**)(void *))(*(u8 **)(self + 0x2c) + 0x1c))(self);
                self[0] = 5;
                lbl_805D7AA0++;
            } else {
                TLobby__sub_80405328(self + 0x10);
            }
            break;
        case 0:
            TLobby__sub_803FE6CC(self, 6, hdr.flag, 0);
            break;
        case 6:
            break;
        }
        break;
    case 2:
        switch (self[0]) {
        case 2:
            if ((*(s16 (**)(void *, void *, void *))(*(u8 **)(self + 0x2c) + 0x30))(self, &hdr, arg1) == 0) {
                self[0] = 3;
            }
            break;
        case 4:
            if ((*(s16 (**)(void *, void *, void *))(*(u8 **)(self + 0x2c) + 0x30))(self, &hdr, arg1) == 0) {
                TLobby__sub_80405304(self + 0x10);
                (*(void (**)(void *))(*(u8 **)(self + 0x2c) + 0x1c))(self);
                self[0] = 5;
                lbl_805D7AA0++;
            }
            break;
        case 5:
            (*(void (**)(void *))(*(u8 **)(self + 0x2c) + 0x20))(self);
            (*(void (**)(void *))(*(u8 **)(self + 0x2c) + 0x18))(self);
            self[0] = ((self[2] & 0xC0) != 0) ? 1 : 0;
            self[3] = self[4];
            self[6] = self[7];
            (*(void (**)(void *))(*(u8 **)(self + 0x2c) + 0x14))(self);
        case 3:
            if (self[3] != 0) {
                self[3]--;
                TLobby__sub_80405328(self + 0x10);
                TLobby__sub_803FE6CC(self, 1, 0, (*(void *(**)(void *))(*(u8 **)(self + 0x2c) + 0x28))(self));
            }
            self[0] = 2;
            break;
        case 0:
        case 1:
            TLobby__sub_803FE6CC(self, 6, hdr.flag, 0);
            break;
        case 6:
            break;
        }
        break;
    case 3:
        switch (self[0]) {
        case 2:
        case 4:
            if ((*(s16 (**)(void *, void *, void *))(*(u8 **)(self + 0x2c) + 0x34))(self, &hdr, arg1) == 0) {
                if (self[3] != 0) {
                    self[3]--;
                    TLobby__sub_80405328(self + 0x10);
                    TLobby__sub_803FE6CC(self, 1, 0, (*(void *(**)(void *))(*(u8 **)(self + 0x2c) + 0x28))(self));
                }
            }
            break;
        case 5:
            (*(void (**)(void *))(*(u8 **)(self + 0x2c) + 0x20))(self);
            (*(void (**)(void *))(*(u8 **)(self + 0x2c) + 0x18))(self);
            self[0] = ((self[2] & 0xC0) != 0) ? 1 : 0;
            self[3] = self[4];
            self[6] = self[7];
            (*(void (**)(void *))(*(u8 **)(self + 0x2c) + 0x14))(self);
        case 3:
            if (self[3] != 0) {
                self[3]--;
                TLobby__sub_80405328(self + 0x10);
                TLobby__sub_803FE6CC(self, 1, 0, (*(void *(**)(void *))(*(u8 **)(self + 0x2c) + 0x28))(self));
            }
            self[0] = 2;
            break;
        case 0:
        case 1:
            TLobby__sub_803FE6CC(self, 6, hdr.flag, 0);
            break;
        case 6:
            break;
        }
        break;
    case 4:
        switch (self[0]) {
        case 2:
        case 4:
            if ((*(s16 (**)(void *, void *, void *))(*(u8 **)(self + 0x2c) + 0x38))(self, &hdr, arg1) == 0) {
                if (self[3] != 0) {
                    self[3]--;
                    TLobby__sub_80405328(self + 0x10);
                    TLobby__sub_803FE6CC(self, 1, 0, (*(void *(**)(void *))(*(u8 **)(self + 0x2c) + 0x28))(self));
                }
            }
            break;
        case 5:
            (*(void (**)(void *))(*(u8 **)(self + 0x2c) + 0x20))(self);
            (*(void (**)(void *))(*(u8 **)(self + 0x2c) + 0x18))(self);
            self[0] = ((self[2] & 0xC0) != 0) ? 1 : 0;
            self[3] = self[4];
            self[6] = self[7];
            (*(void (**)(void *))(*(u8 **)(self + 0x2c) + 0x14))(self);
        case 3:
            if (self[3] != 0) {
                self[3]--;
                TLobby__sub_80405328(self + 0x10);
                TLobby__sub_803FE6CC(self, 1, 0, (*(void *(**)(void *))(*(u8 **)(self + 0x2c) + 0x28))(self));
            }
            self[0] = 2;
            break;
        case 0:
        case 1:
            TLobby__sub_803FE6CC(self, 6, hdr.flag, 0);
            break;
        case 6:
            break;
        }
        break;
    case 5:
        switch (self[0]) {
        case 5:
            TLobby__sub_803FE6CC(self, 6, hdr.flag, 0);
            (*(void (**)(void *))(*(u8 **)(self + 0x2c) + 0x20))(self);
            (*(void (**)(void *))(*(u8 **)(self + 0x2c) + 0x24))(self);
            self[0] = ((self[2] & 0xC0) != 0) ? 1 : 0;
            self[3] = self[4];
            self[6] = self[7];
            (*(void (**)(void *))(*(u8 **)(self + 0x2c) + 0x14))(self);
            break;
        case 3:
        case 4:
            self[0] = 2;
        case 0:
        case 1:
        case 2:
        case 6:
            TLobby__sub_803FE6CC(self, 6, hdr.flag, 0);
            break;
        }
        break;
    case 6:
        switch (self[0]) {
        case 6:
            TLobby__sub_80405304(self + 0x10);
            (*(void (**)(void *))(*(u8 **)(self + 0x2c) + 0x24))(self);
            self[0] = ((self[2] & 0xC0) != 0) ? 1 : 0;
            self[3] = self[4];
            self[6] = self[7];
            (*(void (**)(void *))(*(u8 **)(self + 0x2c) + 0x14))(self);
            break;
        case 5:
            (*(void (**)(void *))(*(u8 **)(self + 0x2c) + 0x20))(self);
            self[0] = ((self[2] & 0xC0) != 0) ? 1 : 0;
            self[3] = self[4];
            self[6] = self[7];
            (*(void (**)(void *))(*(u8 **)(self + 0x2c) + 0x14))(self);
            if (self[3] == 0) {
                rc = -1;
            } else {
                self[3]--;
                TLobby__sub_80405328(self + 0x10);
                rc = TLobby__sub_803FE6CC(self, 1, 0, (*(void *(**)(void *))(*(u8 **)(self + 0x2c) + 0x28))(self));
            }
            if (rc == 0) {
                self[0] = 2;
            }
            break;
        case 3:
        case 4:
            self[0] = 2;
            break;
        }
        break;
    case 7:
        (*(void (**)(void *))(*(u8 **)(self + 0x2c) + 0x24))(self);
        self[0] = ((self[2] & 0xC0) != 0) ? 1 : 0;
        self[3] = self[4];
        self[6] = self[7];
        (*(void (**)(void *))(*(u8 **)(self + 0x2c) + 0x14))(self);
        break;
    case 9:
        switch (self[0]) {
        case 5:
            TLobby__sub_803FE6CC(self, 10, hdr.flag, arg1);
            break;
        case 2:
        case 3:
        case 4:
            break;
        case 0:
        case 1:
            TLobby__sub_803FE6CC(self, 6, hdr.flag, 0);
            break;
        case 6:
            break;
        }
        break;
    case 8:
    case 10:
    case 11:
    case 12:
        break;
    case 0:
    default:
        hdr.len += 4;
        newbuf = alloc_from_buffer(arg1, 4);
        dp = *(u8 **)newbuf;
        *dp++ = hdr.type;
        *dp++ = hdr.flag;
        write_network_u16_be(dp, hdr.len);
        arg1 = newbuf;
        TLobby__sub_803FE6CC(self, 7, hdr.flag, arg1);
        switch (self[0]) {
        case 6:
            break;
        case 2:
        case 3:
        case 4:
        case 5:
            self[0] = 1;
            break;
        }
        break;
    }
}
#pragma pop
struct V_803FE600;
void TLobby__sub_803FE600(O_803FE600 *o) {
    o->b0 = (o->b2 & 0xC0) ? 1 : 0;
    o->b3 = o->b4;
    o->b6 = o->b7;
    o->p2C->fn(o, o->p2C);
}

s32 TLobby__sub_803FE658(u8 *arg0) {
    typedef struct Fields_arg0 { u8 pad_0[3]; u8 field_3; u8 pad_4[40]; u8 * field_2C; } Fields_arg0;
    u8 temp_r3;
    u8 *temp_r4;
    temp_r3 = ((Fields_arg0*)arg0)->field_3;
    if (temp_r3 == 0) {
        return -1;
    }
    ((Fields_arg0*)arg0)->field_3 = (u8) (temp_r3 - 1);
    TLobby__sub_80405328((u8 *)((void *) (arg0 + 0x10)));
    temp_r4 = (u8 *)(((Fields_arg0*)arg0)->field_2C);
    return TLobby__sub_803FE6CC((void *) (arg0), 1, 0, (void *) ((*(s32 (**)(void *, void *))((s8 *)temp_r4 + 0x28))(arg0, temp_r4)));
}

extern s32 TLobby__sub_80406624(s32, s32, u16, UnkSumBuf *);
#pragma push
#pragma opt_lifetimes off
extern s32 TLobby__sub_803FE6CC(void *self, int a, int b, void *c)
{
  RecoveredGlobal_80401A68_lbl_805C04A8 *new_var;
  u8 *new_var2;
  UnkSumBuf *buf;
  u8 *r31 = *((u8 **) (((u8 *) self) + 0xc));
  s32 cmd;
  u8 *new_var3;
  s32 r27;
  u16 n;
  if ((buf = (UnkSumBuf *) c) == 0)
  {
    UnkSumBuf *q = *((UnkSumBuf **) (((u8 *) (&lbl_805C04A8)) + 0x1c));
    q->data = ((u8 *) q) + (((*(new_var = &lbl_805C04A8)).value + 0x83) & (~3));
    q->len = 0;
    buf = q;
  }
  switch (cmd = (u8) a)
  {
    case 1:

    case 5:

    case 9:
      ((u8 *) self)[1] = r31[1];

    case 8:

    case 11:
      r27 = r31[1];
      r31[1] = r27 + 1;
      break;

    case 2:

    case 3:

    case 4:

    case 6:

    case 7:

    case 10:
      r27 = b;
      break;

    default:
      return -1;

  }

  switch (cmd)
  {
    case 9:
    case 10:
    case 11:
      write_network_u32_be(buf->data, *((u32 *) ((*((u8 **) (((u8 *) self) + 0x30))) + 0x28)));
      break;
  }
  n = get_field_4((void *) buf) + 4;
  {
    UnkSumBuf *out = (UnkSumBuf *) alloc_from_buffer((0, (void *) buf), 4);
    u8 *dp = out->data;
    *dp++ = a;
    *dp++ = r27;
    write_network_u16_be(dp, n);
    buf = out;
  }
  if (buf == 0)
  {
    return -1;
  }
  {
    u8 *r7 = r31 + ((*((u8 **) (((u8 *) self) + 0x2c)))[8] << 1);
    s16 v = *((s16 *) (r7 + 0x118));
    *((s16 *) (r7 + 0x118)) = v + 1;
  }
  return TLobby__sub_80406624(0, 0, (*((UnkSumBuf **) (((u8 *) self) + 0x2c)))->len, buf);
}
#pragma pop
void TLobby__sub_803FE820(s32 arg0) {
    TLobby__sub_80405328((u8 *)((void *) (arg0 + 0x10)));
}

s32 TLobby__sub_803FE844(void) {
    return 0;
}

void TLobby__sub_803FE84C(void) {

}

s32 read_2_bytes(void *self, void *src) {
    u8 *dst = (u8 *)self;
    u8 buf[2];
    if (dst == 0) {
        return -1;
    }
    if (TLobby__sub_80401BCC(src, buf, 2) < 2) {
        return -1;
    }
    dst[0] = buf[0];
    dst[1] = buf[1];
    return 0;
}

s32 TLobby__sub_803FE8BC(u8 *dst, void *src) {
    u8 buf[4];
    if (dst == 0) {
        return -1;
    }
    if (TLobby__sub_80401BCC(src, buf, 4) < 4) {
        return -1;
    }
    dst[0] = buf[0];
    dst[1] = buf[1];
    *(u16 *)(dst + 2) = read_network_u16_be(buf + 2);
    return 0;
}

extern u16 TLobby__sub_803FE934(u8* p, UnkSumBuf *buf, u16 count) {
    u32 sum = 0;
    s32 i;
    if (p != NULL) {
        i = 6; while (i--) { sum += *p++ << 8; sum += *p++; }
    }
    sum = TLobby__sub_803FE9F8(sum, buf, count);
    sum = (sum >> 16) + (sum & 0xFFFF);
    sum += sum >> 16;
    return ~sum & 0xFFFF;
}

extern u32 TLobby__sub_803FE9F8(u32 sum, UnkSumBuf* buf, u16 count) {
    s16 n;
    u16 last;
    s32 odd;
    s16 half;
    s16 i;
    u8* data;
    data = buf->data;
    n = buf->len < count ? buf->len : count;
    if (n & 1) {
        odd = 1;
        last = data[n - 1];
        n--;
    } else {
        odd = 0;
        last = 0;
    }
    half = n >> 1;
    for (i = half; i > 0; i--) {
        sum += data[0] << 8;
        sum += data[1];
        data += 2;
    }
    if (odd) {
        sum += last << 8;
    }
    return sum;
}

typedef struct IpHdr_803FEA88 { u8 ver_ihl; u8 tos; u16 len; u16 id; u16 frag; u8 ttl; u8 proto; u16 cksum; u32 src; u32 dst; } IpHdr_803FEA88;
typedef char IpHdr_803FEA88_size_check[sizeof(IpHdr_803FEA88) == 0x14 ? 1 : -1];
s32 TLobby__sub_803FEA88(A_80403F4C *out, Strm_80405A74 **src) {
    Strm_80405A74 *e = *src;
    IpHdr_803FEA88 h;
    u32 hl;
    u16 frag;
    u32 optlen;
    IpHdr_803FEA88 *raw;

    raw = &h;
    if (TLobby__sub_80401BCC(src, raw, 20) != 20) {
        return 0xFFFF;
    }
    out->version = (h.ver_ihl >> 4) & 0xF;
    out->tos = h.tos;
    out->len = h.len;
    out->id = h.id;
    frag = h.frag;
    out->frag = (frag & 0x1FFF) << 3;
    if (frag & 0x2000) {
        out->mf = 1;
    } else {
        out->mf = 0;
    }
    if (frag & 0x4000) {
        out->df = 1;
    } else {
        out->df = 0;
    }
    out->ttl = h.ttl;
    out->proto = h.proto;
    out->cksum = h.cksum;
    out->src = h.src;
    out->dst = h.dst;
    if (out->len - 20 < e->len) {
        e->len = out->len - 20;
    }
    hl = (h.ver_ihl & 0xF) * 4;
    if (hl < 20) {
        out->optlen = 0;
        return 0xFFFF;
    }
    optlen = hl - 20;
    out->optlen = optlen;
    if (out->optlen != 0 && TLobby__sub_80401BCC(src, out->opts, out->optlen) < out->optlen) {
        return 0xFFFF;
    }
    return hl;
}

u8 *GXLoadTexObjPreLoaded(A_80403F4C *arg0, u8 *arg1, s32 arg2) {
    Src_803FC178 *src = (Src_803FC178 *)arg0;
    u16 n;
    u8 buf[0x40];
    u8 *hdr = buf;
    u8 *data;
    u32 sum;
    u16 f;
    u32 tmp;
    u8 pad[0x8];

    tmp = src->f17 + 0x14;
    n = tmp;
    if (n > 0x40) {
        n = 0x40;
    }
    arg1 = alloc_from_buffer((void *)arg1, n);
    data = *(u8 **)arg1;

    hdr[0] = (src->f13 << 4) | (n >> 2);
    hdr[1] = src->f14;
    *(u16 *)&hdr[2] = src->f8;
    *(u16 *)&hdr[4] = src->fA;
    f = (s32)src->fC >> 3;
    if (src->f11 != 0) {
        f |= 0x4000;
    }
    if (src->f12 != 0) {
        f |= 0x2000;
    }
    *(u16 *)&hdr[6] = f;
    hdr[8] = src->f15;
    hdr[9] = src->f16;
    if ((u16)arg2 != 0) {
        *(u16 *)&hdr[10] = src->fE;
    } else {
        *(u16 *)&hdr[10] = 0;
    }
    *(u32 *)&hdr[12] = src->f0;
    *(u32 *)&hdr[16] = src->f4;

    if (src->f17 != 0) {
        NetMemcpy(hdr + 0x14, src->f18, (src->f17 < 0x2C) ? src->f17 : 0x2C);
    }
    {
        u32 m = (u16)n;
        NetMemcpy(data, hdr, m);
        if ((u16)arg2 == 0) {
            sum = TLobby__sub_803FE9F8(0, (UnkSumBuf *)arg1, n);
            sum = (sum >> 16) + (sum & 0xFFFF);
            sum = (sum >> 16) + sum;
            *(u16 *)&hdr[10] = ~sum;
        }
        NetMemcpy(data, hdr, m);
    }
    return arg1;
}

extern s32 lbl_805D7AA0;
s16 TLobby__sub_803FED78(u8 *self) {
    u8 *p;
    u32 *pd;
    u8 *obj;
    s16 st;
    s16 *ps;
    s16 check_connection_status(void *);
    st = 1;
    obj = *(u8 **)(self + 0xc);
    *(s16 *)(self + 8) = 0;
    ps = (s16 *)(lbl_805C0038 + 0xd4);
    ps[4] = 0;
    p = (u8 *)ps;
    pd = (u32 *)&lbl_805C18A0;
    goto test;
    while (1) {
        if (is_timed_out() != 0 || obj[0] == 4) {
            update_connection_state((int)(self));
            *(s16 *)(self + 8) = 0;
            *(s16 *)(p + 8) = 0;
            return -1;
        }
        if (*(s16 *)(self + 8) != 0) goto after;
        st = check_connection_status((void *)p);
        unlock_mutex(pd[0]);
        TLobby__sub_803F97E8(0x64);
        process_expired_timers();
        lock_mutex(pd[0]);
test:
        if (self[0] == 5) goto after;
        if (lbl_805D7AA0 >= 2) goto after;
    }
after:
    if (lbl_805D7A7C != 6 && (s16)(s32)lbl_805D7A7C) {
        if (*(s16 *)(self + 8) != 0) {
            *(s16 *)(p + 8) = 0;
            *(s16 *)(self + 8) = 0;
            return -1;
        }
        *(s16 *)(p + 8) = 0;
        *(s16 *)(self + 8) = 0;
        return 0;
    }
    pd = (u32 *)&lbl_805C18A0;
    while (st > 0) {
        st = check_connection_status((void *)p);
        unlock_mutex(pd[0]);
        TLobby__sub_803F97E8(0x64);
        process_expired_timers();
        lock_mutex(pd[0]);
    }
    switch (st) {
    case 0:
        *(s16 *)(self + 8) = 0;
        *(s16 *)(p + 8) = 0;
        return 0;
    case -2:
        if (*(s16 *)(self + 8) == 0) {
            *(s16 *)(self + 8) = 0;
            *(s16 *)(p + 8) = 0;
            return 0;
        }
        break;
    }
    update_connection_state((int)(self));
    *(s16 *)(p + 8) = 0;
    *(s16 *)(self + 8) = 0;
    return -1;
}

struct P_803FF48C;
void TLobby__sub_803FF48C(P_803FF48C *);
extern s32 TLobby__sub_803FF50C(Self_803FF698 *self, u8 *item, s32 arg);
extern s32 TLobby__sub_803FF698(Self_803FF698 *self, u8 *item, s32 arg);
extern s32 TLobby__sub_803FF9A4(void *self, u8 *src, u32 bits);
extern B_803FADA0 *TLobby__sub_80400174(void *self);
void TLobby__sub_803FEF4C(u8 *self) {
    struct Blk36_8047FE18 *src = (struct Blk36_8047FE18 *)lbl_8047FE18;
    u8 *o = (u8 *)&lbl_805C0328;
    u8 *sub;
    u8 *p;
    *(u32 *)o = (u32)&lbl_805E1170;
    sub = self + 0x6c;
    p = o + 0x3c;
    *(u16 *)(o + 0x4) = 0x8021;
    *(s16 *)(o + 0x6) = 0xfe;
    o[0x8] = 2;
    o[0x9] = 0x14;
    o[0xa] = 10;
    o[0xb] = 10;
    *(u32 *)(o + 0xc) = 0xbb8;
    *(void **)(o + 0x10) = (void *)free_field_98;
    *(void **)(o + 0x14) = (void *)TLobby__sub_803FF48C;
    *(void **)(o + 0x18) = (void *)TLobby__sub_803FF374;
    *(void **)(o + 0x1c) = (void *)TLobby__sub_803FF384;
    *(void **)(o + 0x20) = (void *)free_field_98_and_clear;
    *(void **)(o + 0x24) = (void *)TLobby__sub_803FF468;
    *(void **)(o + 0x28) = (void *)TLobby__sub_80400174;
    *(void **)(o + 0x2c) = (void *)TLobby__sub_803FF9A4;
    *(void **)(o + 0x30) = (void *)TLobby__sub_803FF858;
    *(void **)(o + 0x34) = (void *)TLobby__sub_803FF698;
    *(void **)(o + 0x38) = (void *)TLobby__sub_803FF50C;
    *(u8 **)(sub + 0xc) = self;
    *(u8 **)(sub + 0x2c) = o;
    *(u8 **)(sub + 0x30) = p;
    *(struct Blk36_8047FE18 *)(o + 0x40) = *src;
    *(s16 *)(o + 0x3c) = 6;
    *(struct Blk36_8047FE18 *)(o + 0x8c) = *src;
    *(struct Blk36_8047FE18 *)(p + 0x74) = *src;
    *(s16 *)(p + 0x4c) = 6;
    TLobby__sub_803FD694(sub);
}

s32 set_socket_flags_by_mode(s16 arg0, u8 *arg1) {
    typedef struct Fields_arg1 { s16 field_0; u8 pad_2[2]; s16 field_4; u8 pad_6[10]; s16 field_10; s16 field_12; s8 field_14; u8 pad_15[19]; s16 field_28; } Fields_arg1;
    if (arg0 == 0) {
        ((Fields_arg1*)arg1)->field_10 = 0x2D;
        ((Fields_arg1*)arg1)->field_12 = 0x10;
        ((Fields_arg1*)arg1)->field_14 = 1;
        ((Fields_arg1*)arg1)->field_4 = (s16) (((Fields_arg1*)arg1)->field_4 | 4);
        ((Fields_arg1*)arg1)->field_28 = (s16) (((Fields_arg1*)arg1)->field_28 | 4);
        ((Fields_arg1*)arg1)->field_0 = (s16) (((Fields_arg1*)arg1)->field_0 | 4);
    } else if (arg0 != 0) {
        ((Fields_arg1*)arg1)->field_4 = (s16) (((Fields_arg1*)arg1)->field_4 & 0xFFFFFFFB);
        ((Fields_arg1*)arg1)->field_0 = (s16) (((Fields_arg1*)arg1)->field_0 & 0xFFFFFFFB);
        ((Fields_arg1*)arg1)->field_28 = (s16) (((Fields_arg1*)arg1)->field_28 & 0xFFFFFFFB);
    }
    return 0;
}

s32 set_target_index(u8 *arg0, s32 arg1) {
    if (arg1 == -1) {
        *(s32 *)((s8 *)arg0 + 0x1C) = 0;
        *(s16 *)((s8 *)arg0 + 4) = (s16) (*(s16 *)((s8 *)arg0 + 4) & 0xFFFFF7FF);
    } else {
        *(s32 *)((s8 *)arg0 + 0x1C) = arg1;
        *(s16 *)((s8 *)arg0 + 4) = (s16) (*(s16 *)((s8 *)arg0 + 4) | 0x800);
    }
    return 0;
}

s32 set_filter_index(u8 *arg0, s32 arg1) {
    if (arg1 == -1) {
        *(s32 *)((s8 *)arg0 + 0x18) = 0;
        *(s16 *)((s8 *)arg0 + 4) = (s16) (*(s16 *)((s8 *)arg0 + 4) & 0xFFFFFDFF);
    } else {
        *(s32 *)((s8 *)arg0 + 0x18) = arg1;
        *(s16 *)((s8 *)arg0 + 4) = (s16) (*(s16 *)((s8 *)arg0 + 4) | 0x200);
    }
    return 0;
}

s32 set_filter_id(u8 *arg0, s32 arg1) {
    if (arg1 == -1) {
        *(s32 *)((s8 *)arg0 + 0x1C) = 0;
        *(s16 *)((s8 *)arg0 + 4) = (s16) (*(s16 *)((s8 *)arg0 + 4) & 0xFFFFF7FF);
    } else {
        *(s32 *)((s8 *)arg0 + 0x1C) = arg1;
        *(s16 *)((s8 *)arg0 + 4) = (s16) (*(s16 *)((s8 *)arg0 + 4) | 0x800);
    }
    return 0;
}

s32 set_target_slot(u8 *arg0, s32 arg1) {
    if (arg1 == -1) {
        *(s32 *)((s8 *)arg0 + 0x18) = 0;
        *(s16 *)((s8 *)arg0 + 4) = (s16) (*(s16 *)((s8 *)arg0 + 4) & 0xFFFFFDFF);
    } else {
        *(s32 *)((s8 *)arg0 + 0x18) = arg1;
        *(s16 *)((s8 *)arg0 + 4) = (s16) (*(s16 *)((s8 *)arg0 + 4) | 0x200);
    }
    return 0;
}

s32 set_target_id(u8 *arg0, s32 arg1) {
    if (arg1 == -1) {
        *(s32 *)((s8 *)arg0 + 8) = 0;
        *(s16 *)((s8 *)arg0 + 4) = (s16) (*(s16 *)((s8 *)arg0 + 4) & 0xFFFFFFF7);
    } else {
        *(s32 *)((s8 *)arg0 + 8) = arg1;
        *(s16 *)((s8 *)arg0 + 4) = (s16) (*(s16 *)((s8 *)arg0 + 4) | 8);
    }
    return 0;
}

s32 TLobby__sub_803FF2CC(u8 *arg0, s32 arg1) {
    if (arg1 == -1) {
        *(s32 *)((s8 *)arg0 + 8) = 0;
        *(s16 *)((s8 *)arg0 + 4) = (s16) (*(s16 *)((s8 *)arg0 + 4) & 0xFFFFFFF7);
    } else {
        *(s32 *)((s8 *)arg0 + 8) = arg1;
        *(s16 *)((s8 *)arg0 + 4) = (s16) (*(s16 *)((s8 *)arg0 + 4) | 8);
    }
    return 0;
}

s16 TLobby__sub_803FF304(u8 *lobby) {
    typedef struct Fields_arg0 { u8 pad_0[12]; u8 * field_C; } Fields_arg0;
    set_flags_and_state((void *)lobby);
    if ((u8) *((Fields_arg0*)lobby)->field_C == 3) {
        TLobby__sub_803FD958((u8 *)(lobby));
    }
    return 0;
}

void free_field_98(void *self) {
    u8 *arg0 = (u8 *)self;
    typedef struct Fields_arg0 { u8 pad_0[48]; u8 * field_30; } Fields_arg0;
    TLobby__sub_80405000((u32)(*(u32 *)((s8 *)(((Fields_arg0*)arg0)->field_30) + 0x98)));
}

void TLobby__sub_803FF374(u8 *arg0) {
    *(s8 *)((s8 *)arg0 + 0xA) = 0;
    *(s8 *)((s8 *)arg0 + 0xB) = 0;
}

void TLobby__sub_803FF384(u8 *arg0) {
    u8 *p;
    s16 a;
    s16 b;
    a = 0;
    b = 0;
    p = *(u8 **)((s8 *)arg0 + 0x30);
    TLobby__sub_80405000(*(u32 *)((s8 *)p + 0x98));
    *(s32 *)((s8 *)p + 0x98) = 0;
    if (*(s16 *)((s8 *)p + 0x28) & 4) {
        a = *(s16 *)((s8 *)p + 0x36);
    }
    if (*(s16 *)((s8 *)p + 0x74) & 4) {
        b = *(s16 *)((s8 *)p + 0x82);
    }
    if (a != 0 || b != 0) {
        *(s32 *)((s8 *)p + 0x98) = init_net_list(a, b);
    }
    TLobby__sub_80405304(arg0 + 0x10);
    *(s8 *)((s8 *)arg0 + 0) = 5;
}

void free_field_98_and_clear(void *self) {
    u8 *arg0 = (u8 *)self;
    u8 *temp_r31;
    temp_r31 = (u8 *)(*(u8 **)((s8 *)arg0 + 0x30));
    TLobby__sub_80405000((u32)((u32)((int) (*(s32 *)((s8 *)temp_r31 + 0x98)))));
    *(s32 *)((s8 *)temp_r31 + 0x98) = 0;
}

void TLobby__sub_803FF468(s32 arg0) {
    TLobby__sub_80405304((void *)((void *) (arg0 + 0x10)));
}

struct Q_803FF48C {
    s16 h0; s16 h2;
    U_803FF48C u;
    Blk_803FF48C dst;
    s16 h4C; s16 h4E; s16 h50; s16 h52;
    s32 w54;
    u8 pad58[0x74 - 0x58];
    s16 h74;
};
struct P_803FF48C { u8 pad[0x30]; Q_803FF48C *q; };
void TLobby__sub_803FF48C(P_803FF48C *o) {
    Q_803FF48C *q = o->q;
    q->dst = q->u.src;
    q->dst.w[2] = q->w54;
    q->h0 = q->h0 | q->u.h4;
    q->h74 = 0;
    q->h4C = q->h4C | q->h50;
}

inline u32 optbit_803FF50C(u32 bit) {
    s32 f;
    if (bit < 8) {
        return bit;
    }
    f = 0;
    if (bit >= 0x80 && bit < 0x90) {
        f = 1;
    }
    if (f) {
        bit -= 0x78;
    } else {
        bit = 0;
    }
    return bit;
}
#pragma push
#pragma dont_inline off
#pragma inline_depth(4)
extern s32 TLobby__sub_803FF50C(Self_803FF698 *self, u8 *item, s32 arg) {
    Bits_803FF698 *bits = self->f30;
    s32 count = *(s16 *)(item + 2);
    s16 k;
    s32 r;
    u32 bit;
    s32 len;
    s32 pad;
    u8 hdr[2];

    if (item[1] != self->f1) {
        return -1;
    }
    while (count > 0 && (s16)read_2_bytes((void *)hdr, &arg) != -1) {
        len = hdr[1];
        count -= len;
        if (count < 0) {
            return -1;
        }
        bit = optbit_803FF50C(hdr[0]);
        if (!(bits->f28 & (1 << bit))) {
            return -1;
        }
        for (k = len - 2; k-- > 0;) {
            r = (TLobby__sub_80401BCC(&arg, &lcp_read_byte_buffer, 1) != 1) ? -1 : (s16)lcp_read_byte_buffer;
            if (r == -1) {
                return -1;
            }
        }
        bit = optbit_803FF50C(hdr[0]);
        bits->f28 &= ~(1 << bit);
    }
    return 0;
}
#pragma pop
#pragma push
#pragma dont_inline off
#pragma inline_depth(4)
#pragma opt_common_subs on
extern s32 TLobby__sub_803FF698(Self_803FF698 *self, u8 *item, s32 arg) {
    Bits_803FF698 *bits;
    u8 *p;
    s32 count;
    u8 *m;
    s16 r;
    u32 bit;
    s32 f;
    u8 hdr[2];
    m = (u8 *)self->f30;
    count = *(s16 *)(item + 2);
    bits = (Bits_803FF698 *)m;
    p = m;
    if (item[1] != self->f1) {
        return -1;
    }
    while (count > 0 && (s16)read_2_bytes((void *)hdr, &arg) != -1) {
        count -= hdr[1];
        if (count < 0) {
            return -1;
        }
        if (hdr[0] < 8) { bit = hdr[0]; } else { f = 0; if (hdr[0] >= 0x80 && hdr[0] < 0x90) { f = 1; } if (f) { bit = hdr[0] - 0x78; } else { bit = 0; } }
        if (!(bits->f28 & (1 << bit))) {
            bit = optbit_803FF50C(hdr[0]);
            bits->f28 |= 1 << bit;
        }
        r = TLobby__sub_803FFB84(&arg, bits, p, hdr, 0);
        if (r == -1) {
            return -1;
        }
        if (r == 4) {
            bit = optbit_803FF50C(hdr[0]);
            bits->f28 &= ~(1 << bit);
        }
    }
    return 0;
}
#pragma pop
typedef struct Opt_80400338 { u8 pad0[4]; u32 f4; u32 f8; s16 fC; s16 fE; u8 f10; u8 pad11[3]; u32 f14; u32 f18; } Opt_80400338;

#pragma push
#pragma opt_lifetimes off
#pragma opt_dead_assignments off
#pragma push
#pragma dont_inline off
#pragma inline_depth(4)
inline u32 first_803FA664(Sub_803FF858 *s) {
    u32 t;
    u32 v = 0;
    t = v;
    t = ((u32)init_net_buffer_entry((u16)(0)));
    if (t == 0) {
        return v;
    }
    TLobby__sub_80400270(&t, &s->h1C, s->h1C);
    v = t;
    return v;
}
inline s32 read_803FA664(u32 *p) {
    if (TLobby__sub_80401BCC(p, &lcp_read_byte_buffer, 1) != 1) {
        return -1;
    }
    return (s16)lcp_read_byte_buffer;
}
s32 TLobby__sub_803FF858(Obj_803FF858 *arg0, Msg_803FA664 *arg1, u32 arg2) {
    u32 cur;
    s16 err;
    s16 a;
    s16 b;
    err = 0;
    if (arg1->b1 != arg0->b1) {
        return -1;
    }
    cur = first_803FA664(arg0->p30);
    if (arg1->h2 != get_field_4((void *)cur)) {
        err = 1;
    } else {
        while ((a = read_803FA664(&cur)) != -1) {
            b = read_803FA664(&arg2);
            if (b == -1 || b != a) {
                err = 1;
                break;
            }
        }
    }
    if (err != 0) {
        return -1;
    }
    arg0->bB++;
    return 0;
}
#pragma pop
#pragma pop

extern s32 TLobby__sub_803FF9A4(void *self, u8 *src, u32 bits)
{
  u32 sh;
  void *buf;
  unsigned int new_var;
  u8 *base;
  s32 n;
  s16 r;
  u8 hdr[2];
  s16 k;
  s16 res;
  s32 TLobby__sub_803FE6CC(void *, u8, u8, void *); /* declared here with other parameter types; the definition is s32 (void *, int, int, void *) */
  void TLobby__sub_80400338(B_803FADA0 **pbuf, Opt_80400338 *opt, s32 type, s32 len, void *src);
  base = *((u8 **) (((u8 *) self) + 0x30));
  n = *((s16 *) (src + 2));
  k = 2;
  buf = 0;
  *((s16 *) (base + 0x74)) = 0;
  while ((n > 0) && (((s16) read_2_bytes((void *) hdr, &bits)) != (-1)))
  {
    n -= hdr[1];
    if (n < 0)
    {
      return -1;
    }
    res = TLobby__sub_803FFB84(&bits, base, base + 0x4c, hdr, 1);
    if (res == (-1))
    {
      return -1;
    }
    if (res < k)
    {
      continue;
    }
    if (res > k)
    {
      buf = 0;
      k = res;
    }
    if (res != 4)
    {
      sh = (hdr[0] < 8) ? (hdr[0]) : ((((new_var = hdr[0]) >= 0x80) && (new_var < 0x90)) ? (new_var - 0x78) : (0));
      *((s16 *) (base + 0x74)) |= 1 << sh;
    }
    TLobby__sub_80400338((B_803FADA0 **) (&buf), (Opt_80400338 *) (base + 0x74), hdr[0], hdr[1], &bits);
    if (res > 3)
    {
      TLobby__sub_803FE6CC(self, k, src[1], buf);
    }
  }

  if (k == 3)
  {
    if (((u8 *) self)[6] != 0)
    {
      ((u8 *) self)[6]--;
    }
    else
    {
      k = 4;
      TLobby__sub_803FE6CC(self, 4, src[1], buf);
    }
  }
  if (k > 3)
  {
    return (s16) (2 != k);
  }
  TLobby__sub_803FE6CC(self, k, src[1], buf);
  return (s16) (2 != k);
}
s16 TLobby__sub_803FFB84(void *self, void *p, void *a, u8 *hdr, s16 c)
{
  s16 len;
  s16 res;
  s16 new_var;
  s16 ch;
  u8 new_var2;
  res = 2;
  new_var2 = hdr[0];
  len = hdr[1] - 2;
  switch (hdr[0])
  {
    case 1:
      *((u32 *) (((s8 *) a) + 0x2c)) = (TLobby__sub_80401BCC(self, lbl_805D7AA8, 4) != 4) ? (0) : (TLobby__sub_80402AFC(lbl_805D7AA8));
      *((u32 *) (((s8 *) a) + 0x30)) = (TLobby__sub_80401BCC(self, lbl_805D7AA8, 4) != 4) ? (0) : (TLobby__sub_80402AFC(lbl_805D7AA8));
      len -= 8;
      if (c == 0)
    {
      if ((*((s32 *) (((s8 *) p) + 0x54))) != 0)
      {
        *((s32 *) (((s8 *) p) + 0x30)) = *((s32 *) (((s8 *) p) + 0x54));
      }
      if ((*((s32 *) (((s8 *) p) + 0x8))) != 0)
      {
        *((s32 *) (((s8 *) p) + 0x2c)) = *((s32 *) (((s8 *) p) + 0x8));
      }
    }
    else
    {
      s32 y = *((s32 *) (((s8 *) p) + 0x54));
      s32 x = *((s32 *) (((s8 *) p) + 0x78));
      if (x == y)
      {
        if (y == 0)
        {
          res = 4;
        }
      }
      else
        if (y == 0)
      {
        *((s32 *) (((s8 *) p) + 0x30)) = x;
      }
      else
      {
        *((s32 *) (((s8 *) p) + 0x78)) = y;
        res = 3;
      }
      x = *((s32 *) (((s8 *) p) + 0x7c));
      y = *((s32 *) (((s8 *) p) + 0x8));
      if (x == y)
      {
        if (y == 0)
        {
          res = 4;
        }
      }
      else
        if (y == 0)
      {
        *((s32 *) (((s8 *) p) + 0x2c)) = x;
      }
      else
      {
        *((s32 *) (((s8 *) p) + 0x7c)) = y;
        res = 3;
      }
    }
      break;

    case 2:
      *((s16 *) (((s8 *) a) + 0x34)) = (s16) ((TLobby__sub_80401BCC(self, lbl_805D7AA8, 2) != 2) ? (-1) : (read_network_u16_be(lbl_805D7AA8)));
      len -= 2;
      if (!((*((s16 *) a)) & 4))
    {
      if ((*((s16 *) (((s8 *) a) + 0x34))) == 0x2d)
      {
        ch = (TLobby__sub_80401BCC(self, &lcp_read_byte_buffer, 1) != 1) ? (-1) : ((s16) lcp_read_byte_buffer);
        if (ch == (-1))
        {
          return -1;
        }
        *((s16 *) (((s8 *) a) + 0x36)) = ch + 1;
        ch = (TLobby__sub_80401BCC(self, &lcp_read_byte_buffer, 1) != 1) ? (-1) : ((s16) lcp_read_byte_buffer);
        if (ch == (-1))
        {
          return -1;
        }
        *((u8 *) (((s8 *) a) + 0x38)) = ch;
      }
      *((s16 *) (((s8 *) a) + 0x28)) = (*((s16 *) (((s8 *) a) + 4))) | 4;
      res = 4;
    }
    else
    {
      switch (*((s16 *) (((s8 *) a) + 0x34)))
      {
        case 0x2d:
        {
          ch = (TLobby__sub_80401BCC(self, &lcp_read_byte_buffer, 1) != 1) ? (-1) : ((s16) lcp_read_byte_buffer);
          if (ch == (-1))
          {
            return -1;
          }
          new_var = (*((s16 *) (((s8 *) a) + 0x36)) = ch + 1);
          if (new_var < 1)
          {
            *((s16 *) (((s8 *) a) + 0x36)) = 1;
            res = 3;
          }
          else
            if ((*((s16 *) (((s8 *) a) + 0x36))) > 0x10)
          {
            *((s16 *) (((s8 *) a) + 0x36)) = 0x10;
            res = 3;
          }
          ch = (TLobby__sub_80401BCC(self, &lcp_read_byte_buffer, 1) != 1) ? (-1) : ((s16) lcp_read_byte_buffer);
          if (ch == (-1))
          {
            return -1;
          }
          *((u8 *) (((s8 *) a) + 0x38)) = ch;
          if (((u8) ch) > 1)
          {
            *((u8 *) (((s8 *) a) + 0x38)) = 1;
            res = 3;
          }
          len -= 2;
        }
          break;

        default:
        {
          if ((*((s16 *) (((s8 *) a) + 4))) & 4)
          {
            *((s16 *) (((s8 *) a) + 0x34)) = *((s16 *) (((s8 *) a) + 0x10));
            *((s16 *) (((s8 *) a) + 0x36)) = *((s16 *) (((s8 *) a) + 0x12));
            *((u8 *) (((s8 *) a) + 0x38)) = *((u8 *) (((s8 *) a) + 0x14));
          }
          else
          {
            *((s16 *) (((s8 *) a) + 0x34)) = 0x2d;
            *((s16 *) (((s8 *) a) + 0x36)) = 0x10;
            *((u8 *) (((s8 *) a) + 0x38)) = 1;
          }
          res = 3;
        }

      }

    }
      break;

    case 3:
      *((u32 *) (((s8 *) a) + 0x2c)) = (TLobby__sub_80401BCC(self, lbl_805D7AA8, 4) != 4) ? (0) : (TLobby__sub_80402AFC(lbl_805D7AA8));
      len -= 4;
      if (c == 0)
    {
      *((s32 *) (((s8 *) p) + 0x8)) = *((s32 *) (((s8 *) a) + 0x2c));
      *((s32 *) (((s8 *) p) + 0x58)) = *((s32 *) (((s8 *) a) + 0x2c));
    }
    else
      if ((*((s32 *) (((s8 *) a) + 0x2c))) != 0)
    {
      *((s32 *) (((s8 *) p) + 0x54)) = *((s32 *) (((s8 *) a) + 0x2c));
      *((s32 *) (((s8 *) p) + 0xc)) = *((s32 *) (((s8 *) a) + 0x2c));
    }
    else
    {
      *((s32 *) (((s8 *) p) + 0x78)) = *((s32 *) (((s8 *) p) + 0x54));
      res = 3;
    }
      break;

    case 0x81:
      *((u32 *) (((s8 *) a) + 0x3c)) = (TLobby__sub_80401BCC(self, lbl_805D7AA8, 4) != 4) ? (0) : (TLobby__sub_80402AFC(lbl_805D7AA8));
      len -= 4;
      if (c == 0)
    {
      *((s32 *) (((s8 *) p) + 0x18)) = *((s32 *) (((s8 *) a) + 0x3c));
      *((s32 *) (((s8 *) p) + 0x6c)) = *((s32 *) (((s8 *) a) + 0x3c));
    }
    else
      if ((*((s32 *) (((s8 *) a) + 0x3c))) != 0)
    {
      *((s32 *) (((s8 *) p) + 0x64)) = *((s32 *) (((s8 *) a) + 0x3c));
      *((s32 *) (((s8 *) p) + 0x20)) = *((s32 *) (((s8 *) a) + 0x3c));
    }
    else
    {
      *((s32 *) (((s8 *) p) + 0x88)) = *((s32 *) (((s8 *) p) + 0x64));
      res = 3;
    }
      break;

    case 0x83:
      *((u32 *) (((s8 *) a) + 0x40)) = (TLobby__sub_80401BCC(self, lbl_805D7AA8, 4) != 4) ? (0) : (TLobby__sub_80402AFC(lbl_805D7AA8));
      len -= 4;
      if (c == 0)
    {
      *((s32 *) (((s8 *) p) + 0x1c)) = *((s32 *) (((s8 *) a) + 0x40));
      *((s32 *) (((s8 *) p) + 0x70)) = *((s32 *) (((s8 *) a) + 0x40));
    }
    else
      if ((*((s32 *) (((s8 *) a) + 0x40))) != 0)
    {
      *((s32 *) (((s8 *) p) + 0x68)) = *((s32 *) (((s8 *) a) + 0x40));
      *((s32 *) (((s8 *) p) + 0x24)) = *((s32 *) (((s8 *) a) + 0x40));
    }
    else
    {
      *((s32 *) (((s8 *) p) + 0x8c)) = *((s32 *) (((s8 *) p) + 0x68));
      res = 3;
    }
      break;

    default:
      res = 4;
      break;

  }

  if (!((*((s16 *) a)) & (1 << ((hdr[0] < 8) ? (hdr[0]) : (((new_var2 >= 0x80) && (new_var2 < 0x90)) ? (new_var2 - 0x78) : (0))))))
  {
    res = 4;
  }
  if (len < 0)
  {
    return -1;
  }
  if ((c == 0) && (len > 0))
  {
    while ((len--) > 0)
    {
      if (((TLobby__sub_80401BCC(self, &lcp_read_byte_buffer, 1) != 1) ? (-1) : ((s16) lcp_read_byte_buffer)) == (-1))
      {
        return -1;
      }
    }

  }
  return res;
}

void TLobby__sub_80400338(B_803FADA0 **pbuf, Opt_80400338 *opt, s32 type, s32 len, void *src);
extern B_803FADA0 *TLobby__sub_80400174(void *self) {
    B_803FADA0 *blk;
    s16 i;
    s16 flags;
    u8 *p;
    u8 *base;
    extern u8 lbl_8047FE3C[];
    base = *(u8 **)((u8 *)self + 0x30);
    blk = 0;

    blk = init_net_buffer_entry(0);
    if (blk == 0) {
        return 0;
    }
    flags = *(s16 *)(base + 0x28);
    if (blk == 0) {
        blk = init_net_buffer_entry(0);
        if (blk == 0) {
            goto done;
        }
    }
    p = lbl_8047FE3C + 1;
    for (i = 1; i < 0x20; i++) {
        if (flags & (1 << i)) {
            TLobby__sub_80400338(&blk, (Opt_80400338 *)(base + 0x28), (i < 8) ? i : ((i < 0x20) ? i + 0x78 : 0), *p, 0);
        }
        p++;
    }
done:
    return blk;
}

struct Opt_80400338;
extern u8 lbl_8047FE3C[];
inline s32 optnum_80400270(s32 bit) {
    if (bit < 8) {
        return bit;
    }
    if (bit < 0x20) {
        bit += 0x78;
        return bit;
    }
    return 0;
}
#pragma push
#pragma dont_inline off
#pragma inline_depth(4)
void TLobby__sub_80400270(u32 *self, void *opt, s32 mask)
{
  s16 new_var;
  s16 i;
  s32 m;
  if ((*self) == 0)
  {
    *self = (u32) init_net_buffer_entry(0);
    if ((*self) == 0)
    {
      return;
    }
  }
  m = (new_var = (s16) mask);
  for (i = 1; i < 0x20; i++)
  {
    if (m & (1 << i))
    {
      TLobby__sub_80400338((B_803FADA0 **) self, (Opt_80400338 *) opt, optnum_80400270(i), lbl_8047FE3C[i], 0);
    }
  }

}
#pragma pop
void TLobby__sub_80400338(B_803FADA0 **pbuf, Opt_80400338 *opt, s32 type, s32 len, void *src) {
    B_803FADA0 *buf;
    s16 n;
    u8 *p;
    u8 *q;
    s16 k;

    n = len - 2;
    if (*pbuf != NULL) {
        buf = *pbuf;
    } else {
        buf = init_net_buffer_entry(0);
        if (buf == NULL) {
            return;
        }
        *pbuf = buf;
    }
    p = buf->buf + buf->len;
    p[0] = type;
    p[1] = len;
    p += 2;
    switch (type) {
    case 1:
        p = write_network_u32_be(write_network_u32_be(p, opt->f4), opt->f8);
        n -= 8;
        break;
    case 2:
        k = opt->fC;
        if (k == 0x2D) {
            p = write_network_u16_be(p, k);
            *p++ = opt->fE - 1;
            n -= 4;
            *p++ = opt->f10;
        }
        break;
    case 3:
        p = write_network_u32_be(p, opt->f4);
        n -= 4;
        break;
    case 0x81:
        p = write_network_u32_be(p, opt->f14);
        n -= 4;
        break;
    case 0x83:
        p = write_network_u32_be(p, opt->f18);
        n -= 4;
        break;
    }
    while (n-- > 0) {
        *p++ = TLobby__sub_80401BCC(src, &lcp_read_byte_buffer, 1) != 1 ? -1 : (s16)lcp_read_byte_buffer;
    }
    buf->len += len;
}

s32 wait_for_connection(Conn_804004DC *c) {
    RecoveredGlobal_804050DC_lbl_805C18A0 *g;
    u8 *sub;
    sub = c->sub;
    g = &lbl_805C18A0;
    c->abort = 0;
    while (c->state != 5) {
        if (is_timed_out() != 0 || c->abort != 0 || *sub == 4) {
            update_connection_state((int)c);
            c->abort = 0;
            return -1;
        }
        unlock_mutex(g->value);
        TLobby__sub_803F97E8(100);
        process_expired_timers();
        lock_mutex(g->value);
    }
    c->abort = 0;
    return 0;
}

extern u8 lbl_805E1178;
extern LcpState lbl_805C0400;
extern s32 TLobby__sub_8040172C(Conn_804004DC *c);
extern s32 TLobby__sub_80400C4C(Conn_804004DC *fsm, Msg_803FA664 *msg, s32 src);
extern s32 TLobby__sub_80400DA8(Conn_804004DC *fsm, Msg_803FA664 *msg, s32 src);
s16 TLobby__sub_804010A0(Obj_803FF858 *fsm, Msg_803FA664 *msg, u32 src);
s32 TLobby__sub_80400F1C(Obj_803FF858 *arg0, Msg_803FA664 *arg1, u32 arg2);
typedef struct LcpProto_8040059C {
    const char *name;
    u16 proto;
    u16 h6;
    u8 b8;
    u8 b9;
    u8 bA;
    u8 bB;
    s32 timeout;
    void *f10;
    void *f14;
    void *f18;
    void *f1C;
    void *f20;
    void *f24;
    void *f28;
    void *f2C;
    void *f30;
    void *f34;
    void *f38;
} LcpProto_8040059C;
typedef struct LcpState_8040059C { LcpProto_8040059C proto; LcpOpts opts; u8 pad_a4[4]; } LcpState_8040059C;
typedef char LcpState_8040059C_size_check[sizeof(LcpState_8040059C) == 0xA8 ? 1 : -1];

void TLobby__sub_8040059C(u8 *conn)
{
  LcpProto_8040059C *proto = &((LcpState_8040059C *)&lbl_805C0400)->proto;
  Conn_804004DC *e = (Conn_804004DC *)(conn + 4);
  LcpOpts *area = &((LcpState_8040059C *)&lbl_805C0400)->opts;
  const LcpVals *tbl = (const LcpVals *)&lbl_8047FE50;
  proto->name = (const char *)&lbl_805E1178;
  proto->proto = 0xC021;
  proto->h6 = 0xFFE;
  proto->b8 = 0;
  proto->b9 = 20;
  proto->bA = 10;
  proto->bB = 3;
  proto->timeout = 1000;
  proto->f10 = (void *)TLobby__sub_80400988;
  proto->f14 = (void *)save_timer_state;
  proto->f18 = (void *)TLobby__sub_80400B98;
  proto->f1C = (void *)TLobby__sub_8040098C;
  proto->f20 = (void *)reset_connection_slot;
  proto->f24 = (void *)queue_command_81;
  proto->f28 = (void *)TLobby__sub_8040172C;
  proto->f2C = (void *)TLobby__sub_804010A0;
  proto->f30 = (void *)TLobby__sub_80400F1C;
  proto->f34 = (void *)TLobby__sub_80400DA8;
  proto->f38 = (void *)TLobby__sub_80400C4C;
  e->sub = conn;
  e->proto = proto;
  e->opts = area;
  area->local.want = *tbl;
  area->local.mask = 0x1AE;
  area->remote.want = *tbl;
  area->remote.got = *tbl;
  area->remote.mask = 0x1AE;
  TLobby__sub_803FD694((u8 *)e);
}

extern s16 TLobby__sub_80400744(int a0, void *a1) {
    s32 pad[2];
    s32 *pp;
    void *self = (void *)a0;
    Msg_80400744 *msg = (Msg_80400744 *)a1;
    Ent_80400744 *p;
    Ent_80400744 *q;
    Self_80400744 *s = (Self_80400744 *)self;
    Ent_80400744 *t;
    u16 m6;
    u32 id;
    s32 sid;
    u32 v;
    u32 w;
    pp = pad;

    TLobby__sub_803FE600((O_803FE600 *)self);
    set_flags_and_state(self);
    *s->f0C = 1;
    if (*s->f0C >= 1) {
        id = msg->fC;
        p = t = s->f30;
        sid = (s16)id;
        if (sid >= 0x80 && sid <= 0x1000) {
            t->f4 |= 2;
            t->f6 = (u16)id;
        }
        p->f8 = msg->f0;
        if (p->f8 != 0xffffffff) {
            p->f4 |= 4;
            p->f0 |= 4;
        } else {
            p->f4 &= ~4;
            p->f0 &= ~4;
        }
        m6 = msg->f6;
        if ((m6 & 0x80) || m6 == 4) {
            configure_mode_by_type((void *)((u8 *)p + 0x34), m6 & 0x7f);
            if (lbl_805D7A90 & 2) {
                configure_mode_by_type((void *)p, msg->f6 & 0x7f);
            }
        } else {
            configure_mode_by_type((void *)((u8 *)p + 0x34), m6);
            configure_mode_by_type((void *)p, (s16)msg->f6);
        }
        v = msg->f8;
        if (v != 0) {
            p->f4 |= 0x20;
        } else {
            p->f4 &= ~0x20;
        }
        p->f10 = v;
        if (msg->fE == 0) {
            p->f0 |= 0x80;
        } else {
            p->f0 &= ~0x80;
        }
        if (msg->f4 == 0) {
            p->f0 |= 0x100;
        } else {
            p->f0 &= ~0x100;
        }
        q = (Ent_80400744 *)((u8 *)p + 0x34);
        w = msg->f8;
        if (w != 0) {
            q->f4 |= 0x20;
        } else {
            q->f4 &= ~0x20;
        }
        q->f10 = w;
        q = (Ent_80400744 *)((u8 *)p + 0x34);
        if (msg->fE == 0) {
            q->f0 |= 0x80;
        } else {
            q->f0 &= ~0x80;
        }
        q = (Ent_80400744 *)((u8 *)p + 0x34);
        if (msg->f4 == 0) {
            q->f0 |= 0x100;
        } else {
            q->f0 &= ~0x100;
        }
        TLobby__sub_803FD958((u8 *)self);
    }
    return 0;
}

void TLobby__sub_80400988(void) {

}

void TLobby__sub_8040098C(Conn_804004DC *c) {
    LcpOpts *info = c->opts;
    St_8040098C *st;
    u32 now;

    ((St_8040098C *)c->sub)->f0 = 2;
    ((St_8040098C *)c->sub)->f2 &= ~0x30;
    ((St_8040098C *)c->sub)->f10C = 0;
    if (info->local.got.mask & 8) {
        switch (info->local.got.auth_proto) {
        case 0xC023:
            set_active(c->sub);
            break;
        case 0xC223:
            mark_sub_ready(c->sub);
            set_active_flag(c->sub);
            break;
        }
    }
    if (info->remote.got.mask & 8) {
        switch (info->remote.got.auth_proto) {
        case 0xC023:
            mark_ready(c->sub);
            break;
        case 0xC223:
            set_active_flag(c->sub);
            mark_sub_ready(c->sub);
            break;
        }
    }
    st = (St_8040098C *)c->sub;
    if (!(st->f2 & 0x30)) {
        st->f0 = 3;
        get_time_ms((s32 *)&now);
        st->f108 = (s16)(now / 1000);
        TLobby__sub_803FD958(st->f6C);
    }
}

void TLobby__sub_80400ACC(O_80400ACC *o) {
    u32 t;
    if ((o->b2 & 0x30) == 0) {
        o->b0 = 3;
        get_time_ms((s32 *)&t);
        o->f108 = (s16)(t / 1000);
        TLobby__sub_803FD958((u8 *)o + 0x6C);
    }
}

void reset_connection_slot(void *self) {
    u8 *arg0 = (u8 *)self;
    typedef struct Fields_arg0 { u8 pad_0[12]; s8 * field_C; } Fields_arg0;
    s8 *temp_r31;
    temp_r31 = (s8 *)(((Fields_arg0*)arg0)->field_C);
    *temp_r31 = 4;
    TLobby__sub_803FD85C(temp_r31 + 0x6C);
    reset_connection_state((void *)(temp_r31 + 0x38));
}

void queue_command_81(void) {
    TLobby__sub_804062A0(0x81);
}

void TLobby__sub_80400B98(u8 *arg0) {
    **(s8 **)((s8 *)arg0 + 0xC) = 1;
}

typedef char RecoveredGlobal_80401A68_lbl_805C04A8_size[sizeof(RecoveredGlobal_80401A68_lbl_805C04A8) == 0x30 ? 1 : -1];

void save_timer_state(void *self) {
    LcpOpts *s;
    s32 t;
    s = ((Conn_804004DC *)self)->opts;
    if (s->local.want.mask & 0x20) {
        get_time_ms(&t);
        s->local.want.magic += t;
    }
    s->local.got = s->local.want;
    s->local.mask |= s->local.want.mask;
    s->remote.got.mask = 0;
    s->remote.mask |= s->remote.want.mask;
}

extern s32 TLobby__sub_80400C4C(Conn_804004DC *fsm, Msg_803FA664 *msg, s32 src) {
    s16 last = 0;
    LcpOpts *o = fsm->opts;
    s32 left = msg->h2;
    u8 opt[12];
    s16 n;
    u8 len;
    u8 type;

    if (msg->b1 != fsm->id) {
        return -1;
    }
    while (left > 0 && (s16)read_2_bytes((opt), &src) != -1) {
        len = opt[1];
        left -= len;
        if (left < 0) {
            return -1;
        }
        if (opt[0] <= 8 && (opt[0] < last || !(o->local.got.mask & (1 << opt[0])))) {
            return -1;
        }
        for (n = len - 2; n-- > 0;) {
            if ((TLobby__sub_80401BCC(&src, lobby_read_byte_buffer, 1) != 1 ? -1 : (s16)lobby_read_byte_buffer[0]) == -1) {
                return -1;
            }
        }
        last = type = opt[0];
        if (type <= 8 && (type != 3 || !(o->local.got.mask & (1 << type)))) {
            o->local.got.mask &= ~(1 << type);
        }
    }
    return 0;
}

#pragma push
#pragma opt_common_subs on
extern s32 TLobby__sub_80400DA8(Conn_804004DC *fsm, Msg_803FA664 *msg, s32 src) {
    LcpOpts *opts = fsm->opts;
    LcpSide *local = &opts->local;
    s32 remaining = msg->h2;
    s16 last = 0;
    u8 hdr[2];
    s16 r;
    if (msg->b1 != fsm->id) {
        return -1;
    }
    while (remaining > 0 && (s16)read_2_bytes((hdr), &src) != -1) {
        remaining -= hdr[1];
        if (remaining < 0) {
            return -1;
        }
        if (hdr[0] <= 8) {
            if (hdr[0] < last || (opts->local.got.mask & (1 << hdr[0])) == 0) {
                if (opts->local.got.mask & (1 << hdr[0])) {
                    return -1;
                }
                opts->local.got.mask |= 1 << hdr[0];
                last = 9;
            } else {
                last = hdr[0];
            }
        }
        r = parse_lcp_option((s32)&src, (u8 *)opts, (u8 *)local, hdr, 0);
        if (r == -1) {
            return -1;
        }
        if (r == 4 && hdr[0] <= 8 && (hdr[0] != 3 || (opts->local.got.mask & (1 << hdr[0])) == 0)) {
            opts->local.got.mask &= ~(1 << hdr[0]);
        }
    }
    return 0;
}
#pragma pop
extern u8 lbl_8047FE68[];
extern void TLobby__sub_804017D8(u32 *self_m, void *src, u8 idx, u8 val, s32 *flag);
inline void loop_8040172C(u32 *self, void *src, s16 mask) {
    s16 i;
    i = 1;
    while (i <= 8) {
        if (mask & (1 << i)) {
            TLobby__sub_804017D8(self, src, i, lbl_8047FE68[i], 0);
        }
        i++;
    }
}
inline s32 read_80400F1C(u32 *p) {
    if (TLobby__sub_80401BCC(p, lobby_read_byte_buffer, 1) != 1) {
        return -1;
    }
    return (s16)lobby_read_byte_buffer[0];
}
#pragma push
#pragma dont_inline off
#pragma inline_depth(4)
inline u32 first2_80400F1C(Obj_803FF858 *fsm) {
    u8 *o = (u8 *)fsm->p30;
    u32 t = 0;
    t = (u32)init_net_buffer_entry(0);
    if (t == 0) {
        return 0;
    }
    loop_8040172C(&t, o + 0x1c, *(s16 *)(o + 0x1c));
    return t;
}
s32 TLobby__sub_80400F1C(Obj_803FF858 *arg0, Msg_803FA664 *arg1, u32 arg2) {
    s16 err;
    s16 a;
    s16 b;
    err = 0;
    if (arg1->b1 != arg0->b1) {
        return -1;
    }
    {
        u32 cur = first2_80400F1C(arg0);
        if (arg1->h2 != get_field_4((void *)cur)) {
            err = 1;
        } else {
            while ((a = read_80400F1C(&cur)) != -1) {
                b = read_80400F1C(&arg2);
                if (b == -1 || b != a) {
                    err = 1;
                    break;
                }
            }
        }
    }
    if (err != 0) {
        return -1;
    }
    return 0;
}
#pragma pop

#pragma push
#pragma dont_inline off
#pragma inline_depth(4)
inline void add_lcp_options(B_803FADA0 **pbuf, s16 *vals, s16 mask) {
    s16 i;

    for (i = 1; i <= 8; i++) {
        if (mask & (1 << i)) {
            TLobby__sub_804017D8((u32 *)pbuf, vals, i, lbl_8047FE68[i], NULL);
        }
    }
}

s16 TLobby__sub_804010A0(Obj_803FF858 *fsm, Msg_803FA664 *msg, u32 src) {
    LcpOpts *opts;
    s32 remaining;
    s16 status;
    s16 r;
    B_803FADA0 *reply;
    u8 hdr[2];
    s16 missing;
    s32 TLobby__sub_803FE6CC(void *, u8, u8, void *); /* declared here with other parameter types; the definition is s32 (void *, int, int, void *) */

    status = 2;
    opts = (LcpOpts *)fsm->p30;
    remaining = msg->h2;
    reply = NULL;
    opts->remote.got.mask = 0;
    reply = init_net_buffer_entry(1);
    if (opts->remote.want.f15 != 0) {
        opts->remote.got.auth_proto = 0;
        opts->remote.got.mask |= 8;
    }
    while (remaining > 0 && (s16)read_2_bytes(hdr, &src) != -1) {
        remaining -= hdr[1];
        if (remaining < 0) {
            return -1;
        }
        r = parse_lcp_option((s32)&src, (u8 *)opts, (u8 *)&opts->remote, hdr, 1);
        if (r == -1) {
            return -1;
        }
        if (r < status) {
            continue;
        }
        if (r > status) {
            reply = NULL;
            status = r;
        }
        if (r != 4 && hdr[0] <= 8) {
            opts->remote.got.mask |= 1 << hdr[0];
        }
        TLobby__sub_804017D8((u32 *)&reply, &opts->remote.got.mask, hdr[0], hdr[1], (s32 *)&src);
        if (r >= 3) {
            TLobby__sub_803FE6CC(fsm, status, msg->b1, reply);
        }
    }
    missing = opts->remote.want.mask & ~opts->remote.got.mask;
    if (status == 3) {
        if (fsm->b6 != 0) {
            add_lcp_options(&reply, &opts->remote.got.mask, missing);
            fsm->b6--;
        } else {
            status = 4;
            TLobby__sub_803FE6CC(fsm, 4, msg->b1, reply);
        }
    }
    if (status >= 3) {
        return status != 2;
    }
    TLobby__sub_803FE6CC(fsm, status, msg->b1, reply);
    return status != 2;
}
#pragma pop

#define rd16_804012E0(src) (TLobby__sub_80401BCC((void *)(src), lcp_read_value_buffer, 2) != 2 ? -1 : read_network_u16_be(lcp_read_value_buffer))
#define rd32_804012E0(src) (TLobby__sub_80401BCC((void *)(src), lcp_read_value_buffer, 4) != 4 ? 0 : TLobby__sub_80402AFC(lcp_read_value_buffer))
#define rd8_804012E0(src) (TLobby__sub_80401BCC((void *)(src), lobby_read_byte_buffer, 1) != 1 ? -1 : (s16)lobby_read_byte_buffer[0])
#define F(t, o) (*(t *)((s8 *)(arg2) + (o)))
s16 parse_lcp_option(s32 arg0, u8 *arg1, u8 *arg2, u8 *arg3, s16 arg4) {
    s16 len;
    s16 res;
    s32 t;
    s16 lim;
    res = 2;
    len = arg3[1] - 2;
    switch (arg3[0]) {
    case 1:
        F(s16, 0x1E) = rd16_804012E0(arg0);
        len -= 2;
        if (F(s16, 0x1E) < 0x80) {
            F(s16, 0x1E) = 0x80;
            res = 3;
        } else if (F(s16, 0x1E) > 0x1000) {
            F(s16, 0x1E) = 0x1000;
            res = 3;
        }
        if (arg4 != 0 && (F(s16, 4) & 2) && F(s16, 0x1E) > (lim = F(s16, 6))) {
            F(s16, 0x1E) = lim;
            res = 3;
        }
        break;
    case 2:
        F(u32, 0x20) = rd32_804012E0(arg0);
        len -= 4;
        if (lbl_805D7A7A != 0) {
            res = 4;
        } else if (arg4 == 0 || (F(s16, 4) & 4)) {
            u32 v = F(u32, 0x20) | F(u32, 8);
            if (F(u32, 0x20) != v) {
                F(u32, 0x20) = v;
                res = 3;
            }
        }
        break;
    case 3:
        F(u16, 0x24) = rd16_804012E0(arg0);
        len -= 2;
        if (F(u16, 0x24) == 0xC223) {
            F(s8, 0x30) = rd8_804012E0(arg0);
            len -= 1;
        }
        if (F(u8, 0x19) != 0) {
            u16 v = F(u16, 0x24);
            if (v == 0xC023 || (v == 0xC223 && (s32)F(u8, 0x30) == 5)) {
                F(u16, 0xC) = v;
                F(u8, 0x18) = F(u8, 0x30);
            } else {
                F(u16, 0x24) = 0xC023;
                F(s8, 0x30) = 0;
                res = 3;
                arg3[1] = 4;
                while (len > 0) {
                    len--;
                    if (rd8_804012E0(arg0) == -1) {
                        return -1;
                    }
                }
            }
        } else {
            u16 a = F(u16, 0x24);
            u16 b = F(u16, 0xC);
            if (a != b || (a == 0xC223 && F(s8, 0x30) != F(s8, 0x18))) {
                F(u16, 0x24) = b;
                res = 3;
                F(u8, 0x30) = F(u8, 0x18);
            }
        }
        if (res == 2) {
            set_ppp_auth_protocol(F(u16, 0x24));
        }
        break;
    case 5:
        F(u32, 0x28) = rd32_804012E0(arg0);
        len -= 4;
        if (F(u32, 0x28) == 0 || *(u32 *)((s8 *)arg1 + 0x5C) == *(u32 *)((s8 *)arg1 + 0x28)) {
            get_time_ms(&t);
            res = 3;
            F(u32, 0x28) += t;
        }
        break;
    case 7:
        if (!(F(s16, 0) & 0x80)) {
            res = 4;
        }
        break;
    case 8:
        if (lbl_805D7A7A != 0) {
            res = 4;
        } else if (!(F(s16, 0) & 0x100)) {
            res = 4;
        }
        break;
    case 0:
        res = 4;
        break;
    default:
        res = 4;
        break;
    }
    if (arg3[0] > 8 || !(F(s16, 0) & (1 << arg3[0]))) {
        res = 4;
    }
    if (len < 0) {
        return -1;
    }
    if (arg4 == 0 && len > 0) {
        while (len-- > 0) {
            if (rd8_804012E0(arg0) == -1) {
                return -1;
            }
        }
    }
    return res;
}

#pragma push
#pragma dont_inline off
#pragma inline_depth(4)
s32 TLobby__sub_8040172C(Conn_804004DC *c) {
    u32 obj;
    LcpOpts *s;
    s = c->opts;
    obj = 0;
    obj = (u32)init_net_buffer_entry(0);
    if (obj == 0) {
        return 0;
    }
    loop_8040172C(&obj, &s->local.got, s->local.got.mask);
    return obj;
}
#pragma pop

extern void TLobby__sub_804017D8(u32 *self_m, void *src, u8 idx, u8 val, s32 *flag) {
p803FE518_UnkBuf803FF344 *p;
p803FE518_UnkSrc803FE518 *s;
u8 *out;
u8 *cnt;
int c;
s16 rem;
rem = ((u8) val) - 2;
if ((*((p803FE518_UnkBuf803FF344 **) self_m)) == ((void *) 0))
{
*((p803FE518_UnkBuf803FF344 **) self_m) = (p803FE518_UnkBuf803FF344 *)(((void*)init_net_buffer_entry((u16)(1))));
if ((*((p803FE518_UnkBuf803FF344 **) self_m)) == ((void *) 0))
{
return;
}
}
p = *((p803FE518_UnkBuf803FF344 **) self_m);
s = (p803FE518_UnkSrc803FE518 *)(src);
out = p->data;
out = out + p->len;
*(out++) = idx;
cnt = out;
*(out++) = val;
switch (idx)
{
case 1:
out = write_network_u16_be((u8 *)(out), (u16)(s->w2));
rem -= 2;
break;
case 2:
out = write_network_u32_be((u8 *)(out), (u32)(s->w4));
rem -= 4;
break;
case 3:
out = write_network_u16_be((u8 *)(out), (u16)(s->h8));
rem -= 2;
if (s->h8 == 0xc223)
{
*cnt = 5;
*(out++) = s->b14;
if (val == 4)
{
val++;
}
rem = 0;
}
if (s->h8 == 0xc023)
{
*cnt = 4;
if (val == 5)
{
val--;
}
rem = 0;
}
break;
case 5:
out = write_network_u32_be((u8 *)(out), (u32)(s->wc));
rem -= 4;
break;
case 4:
case 6:
case 7:
case 8:
break;
}
while ((rem--) > 0)
{
if (((s16) (TLobby__sub_80401BCC((void *)((u8 *) flag), (void *)(&(*(u8*)&lobby_read_byte_buffer)), (int)(1)))) != 1)
{
c = -1;
}
else
{
c = (s16) (*(u8*)&lobby_read_byte_buffer);
}
*(out++) = c;
}
p->len += val;
}

s32 configure_mode_by_type(void *self, s16 type) {
    Cfg_804019A8 *c = (Cfg_804019A8 *)self;
    if (type == 0) {
        c->flags |= 8;
        c->mode = 0xC023;
    } else if (type == 1) {
        c->flags &= ~8;
        c->b19 = 0;
    } else if (type == 2) {
        c->flags |= 8;
        c->mode = 0xC223;
        c->b18 = 5;
        c->b19 = 0;
    } else if (type == 4) {
        c->flags |= 8;
        c->mode = 0xC223;
        c->b18 = 5;
        c->b19 = 1;
    } else {
        return 1;
    }
    return 0;
}

void init_net_state_c(void) {
    TLobby__sub_803F79BC((void *) (&lbl_805C04A8.value));
}

typedef char RecoveredGlobal_80401A90_lbl_805C04A8_size[sizeof(RecoveredGlobal_80401A90_lbl_805C04A8) == 0x30 ? 1 : -1];
s32 init_net_subsystem_block(void) {
    init_net_buffer_desc((void *)(&(*(RecoveredGlobal_80401A90_lbl_805C04A8 *)&lbl_805C04A8).value));
    return 0;
}

s32 TLobby__sub_80401ABC(u8* self_m, void* dst, s32 n)
{
    void NetMemcpy(void*, const void*, s16);
    s32 m; u16 cap; u32 t;

    if (dst == NULL) {
        return 0;
    }
    cap = *(u16*)(self_m + 4);
    t = (cap < (u16)n) ? cap : n;
    m = t;
    NetMemcpy(dst, *(void**)self_m, m);
    return m;
}

struct G_80401B20 { s32 f0; s32 f4; s32 f8; Ent_80401B20 *pC; };
#pragma opt_propagation off
Ent_80401B20 *TLobby__sub_80401B20(void *src, u16 n) {
    G_80401B20 *g = (G_80401B20 *)&lbl_805C04A8;
    Ent_80401B20 *t = g->pC;
    Ent_80401B20 *e;
    t->p0 = (u8 *)t + ((g->f0 + 0x83) & ~3);
    e = t;
    NetMemcpy(e->p0, src, n);
    e->h4 = n;
    return e;
}
#pragma opt_propagation reset

u8 *alloc_from_buffer(void *self, s16 arg1) {
    struct RecoveredFields_80401B8C_arg0 *arg0 = (struct RecoveredFields_80401B8C_arg0 *)self;
    s32 temp_r6;
    if (arg0 != NULL) {
        temp_r6 = arg0->field_0;
        if ((s32) (temp_r6 - (u32)(((u8 *)(arg0) + 8))) >= arg1) {
            arg0->field_0 = temp_r6 - arg1;
            arg0->field_4 += arg1;
            return (unsigned char *) (arg0);
        }
    }
    return NULL;
}

extern s16 TLobby__sub_80401BCC(void *self, void *dst, u16 n) {
    Strm_80405A74 *p;
    s16 m;
    s16 total = 0;

    if (self == 0) {
        return 0;
    }
    while (n != 0 && (p = *(Strm_80405A74 **)self) != 0) {
        m = (n < p->len) ? n : p->len;
        if (dst != 0) {
            if (m == 1) {
                ((u8 *)dst)[0] = p->p[0];
            } else if (m > 1) {
                NetMemcpy(dst, p->p, m);
            }
            dst = (u8 *)dst + m;
        }
        p->p += m;
        total += m;
        n -= m;
        p->len -= m;
        if (p->len == 0) {
            n = 0;
        }
    }
    return total;
}

void TLobby__sub_80401CAC(Outer_80401CAC *o, u16 v) {
    if (o == NULL || o->p == NULL) return;
    if (v == 0) return;
    if (o->p->f4 < v) return;
    o->p->f4 = v;
}

u16 get_field_4(void *self) {
    u8 *arg0 = (u8 *)self;
    return *(u16 *)((s8 *)arg0 + 4);
}

typedef struct G_80401CE8 { s32 f0; u8 *f4; u8 pad8[2]; s16 hA; } G_80401CE8;
#pragma push
#pragma opt_propagation off
B_803FADA0 *init_net_buffer_entry(u16 idx) {
  G_80401CE8 *g = (G_80401CE8 *)&lbl_805C04A8;
  B_803FADA0 *t = (B_803FADA0 *) (g->f4 + ((idx * g->hA) * ((((4 & 0xFFFFFFFFu) & 0xFFFFFFFFu) & 0xFFFFFFFFu) & 0xFFFFFFFFu)));
  B_803FADA0 *e;
  e = (B_803FADA0 *) (g->f4 + ((idx * g->hA) * ((((4 & 0xFFFFFFFFu) & 0xFFFFFFFFu) & 0xFFFFFFFFu) & 0xFFFFFFFFu)));
  e->buf = ((u8 *) t) + ((g->f0 + 0x83) & (~3));
  e->len = 0xFFFFFFFFu * 0;
  return e;
  e = t;
}
#pragma pop

extern u8 lbl_8047FE78[];
#pragma push
#pragma opt_propagation off
extern void TLobby__sub_80401D2C(u8 *dst, u32 *self_m) {
  u8 buf[8];
  u32 x;
  u32 n;
  u32 *s = self_m;
  u32 *new_var;
  buf[0] = self_m[4];
  new_var = &self_m[5];
  buf[1] = self_m[4] >> 8;
  buf[2] = self_m[4] >> 16;
  buf[3] = self_m[4] >> 24;
  buf[4] = *new_var;
  buf[5] = (*new_var) >> 8;
  buf[6] = (*new_var) >> 16;
  buf[7] = (*new_var) >> 24;
  x = (self_m[4] >> 3) & 0x3f;
  n = (x < 0x38) ? (0x38 - x) : (0x78 - x);
  TLobby__sub_80401EB8((u8*)((u8 *) s), (u8*)((*(u8(*)[])&lbl_8047FE78)), (u32)(n));
  TLobby__sub_80401EB8((u8*)((u8 *) s), (u8*)(buf), (u32)(8));
  dst[0] = self_m[0];
  dst[1] = self_m[0] >> 8;
  dst[2] = self_m[0] >> 16;
  dst[3] = (0, self_m[0] >> 24);
  dst[4] = self_m[1];
  dst[5] = self_m[1] >> 8;
  dst[6] = self_m[1] >> 16;
  dst[7] = self_m[1] >> 24;
  dst[8] = self_m[2];
  dst[9] = self_m[2] >> 8;
  dst[10] = self_m[2] >> 16;
  dst[11] = self_m[2] >> 24;
  dst[12] = self_m[3];
  dst[13] = self_m[3] >> 8;
  dst[14] = self_m[3] >> 16;
  dst[15] = self_m[3] >> 24;
  NetMemset((void *)((u8 *) self_m), (int)(0), (int)(0x58));
}
#pragma pop

void TLobby__sub_80401EB8(u8* self_m, u8* src, u32 len)
{
    u32 sum;
    u32 lo;
    u32 bits;
    u32 avail;
    u32 idx;
    u32 i;

    lo = *(u32*)(self_m + 0x10);
    bits = len << 3;
    sum = lo + bits;
    idx = (lo >> 3) & 0x3f;
    *(u32*)(self_m + 0x10) = sum;
    if (sum < bits) {
        *(u32*)(self_m + 0x14) += 1;
    }
    avail = 0x40 - idx;
    *(u32*)(self_m + 0x14) += len >> 29;
    i = avail;
    if (len >= avail) {
        NetMemcpy((void *)(self_m + 0x18 + idx), (void *)(src), (int)(i));
        MD5Transform((u32*)(self_m), (u8*)(self_m + 0x18));
        for (; i + 0x3f < len; i += 0x40) {
            MD5Transform((u32*)(self_m), (u8*)(src + i));
        }
        idx = 0;
    } else {
        i = 0;
    }
    NetMemcpy((void *)(self_m + 0x18 + idx), (void *)(src + i), (int)(len - i));
}

void init_md5_state(void *self) {
    u8 *arg0 = (u8 *)self;
    typedef struct Fields_arg0 { s32 field_0; s32 field_4; s32 field_8; s32 field_C; s32 field_10; s32 field_14; } Fields_arg0;
    ((Fields_arg0*)arg0)->field_14 = 0;
    ((Fields_arg0*)arg0)->field_10 = 0;
    ((Fields_arg0*)arg0)->field_0 = 0x67452301;
    ((Fields_arg0*)arg0)->field_4 = 0xEFCDAB89;
    ((Fields_arg0*)arg0)->field_8 = 0x98BADCFE;
    ((Fields_arg0*)arg0)->field_C = 0x10325476;
}

typedef char RecoveredGlobal_80402B60_lbl_805C0620_size[sizeof(RecoveredGlobal_80402B60_lbl_805C0620) == 0x18 ? 1 : -1];

#define S11_80401FE8 7
#define S12_80401FE8 12
#define S13_80401FE8 17
#define S14_80401FE8 22
#define S21_80401FE8 5
#define S22_80401FE8 9
#define S23_80401FE8 14
#define S24_80401FE8 20
#define S31_80401FE8 4
#define S32_80401FE8 11
#define S33_80401FE8 16
#define S34_80401FE8 23
#define S41_80401FE8 6
#define S42_80401FE8 10
#define S43_80401FE8 15
#define S44_80401FE8 21
#define F_80401FE8(x, y, z) (((x) & (y)) | ((~x) & (z)))
#define G_80401FE8(x, y, z) (((x) & (z)) | ((y) & (~z)))
#define H_80401FE8(x, y, z) ((x) ^ (y) ^ (z))
#define I_80401FE8(x, y, z) ((y) ^ ((x) | (~z)))
#define ROTATE_LEFT_80401FE8(x, n) (((x) << (n)) | ((x) >> (32 - (n))))
#define FF_80401FE8(a, b, c, d, x, s, ac) { (a) += F_80401FE8((b), (c), (d)) + (x) + (u32)(ac); (a) = ROTATE_LEFT_80401FE8((a), (s)); (a) += (b); }
#define GG_80401FE8(a, b, c, d, x, s, ac) { (a) += G_80401FE8((b), (c), (d)) + (x) + (u32)(ac); (a) = ROTATE_LEFT_80401FE8((a), (s)); (a) += (b); }
#define HH_80401FE8(a, b, c, d, x, s, ac) { (a) += H_80401FE8((b), (c), (d)) + (x) + (u32)(ac); (a) = ROTATE_LEFT_80401FE8((a), (s)); (a) += (b); }
#define II_80401FE8(a, b, c, d, x, s, ac) { (a) += I_80401FE8((b), (c), (d)) + (x) + (u32)(ac); (a) = ROTATE_LEFT_80401FE8((a), (s)); (a) += (b); }
#pragma push
#pragma dont_inline off
#pragma inline_depth(4)
#pragma opt_common_subs on
inline void Decode_80401FE8(u32 *output, u8 *input, u32 len) {
    u32 i, j;
    for (i = 0, j = 0; j < len; i++, j += 4) {
        output[i] = ((u32)input[j]) | (((u32)input[j + 1]) << 8) | (((u32)input[j + 2]) << 16) | (((u32)input[j + 3]) << 24);
    }
}
void MD5Transform(u32 *state, u8 *block) {
    u32 a = state[0], b = state[1], c = state[2], d = state[3], x[16];
    Decode_80401FE8(x, block, 64);
    FF_80401FE8(a, b, c, d, x[0], S11_80401FE8, 0xd76aa478);
    FF_80401FE8(d, a, b, c, x[1], S12_80401FE8, 0xe8c7b756);
    FF_80401FE8(c, d, a, b, x[2], S13_80401FE8, 0x242070db);
    FF_80401FE8(b, c, d, a, x[3], S14_80401FE8, 0xc1bdceee);
    FF_80401FE8(a, b, c, d, x[4], S11_80401FE8, 0xf57c0faf);
    FF_80401FE8(d, a, b, c, x[5], S12_80401FE8, 0x4787c62a);
    FF_80401FE8(c, d, a, b, x[6], S13_80401FE8, 0xa8304613);
    FF_80401FE8(b, c, d, a, x[7], S14_80401FE8, 0xfd469501);
    FF_80401FE8(a, b, c, d, x[8], S11_80401FE8, 0x698098d8);
    FF_80401FE8(d, a, b, c, x[9], S12_80401FE8, 0x8b44f7af);
    FF_80401FE8(c, d, a, b, x[10], S13_80401FE8, 0xffff5bb1);
    FF_80401FE8(b, c, d, a, x[11], S14_80401FE8, 0x895cd7be);
    FF_80401FE8(a, b, c, d, x[12], S11_80401FE8, 0x6b901122);
    FF_80401FE8(d, a, b, c, x[13], S12_80401FE8, 0xfd987193);
    FF_80401FE8(c, d, a, b, x[14], S13_80401FE8, 0xa679438e);
    FF_80401FE8(b, c, d, a, x[15], S14_80401FE8, 0x49b40821);
    GG_80401FE8(a, b, c, d, x[1], S21_80401FE8, 0xf61e2562);
    GG_80401FE8(d, a, b, c, x[6], S22_80401FE8, 0xc040b340);
    GG_80401FE8(c, d, a, b, x[11], S23_80401FE8, 0x265e5a51);
    GG_80401FE8(b, c, d, a, x[0], S24_80401FE8, 0xe9b6c7aa);
    GG_80401FE8(a, b, c, d, x[5], S21_80401FE8, 0xd62f105d);
    GG_80401FE8(d, a, b, c, x[10], S22_80401FE8, 0x2441453);
    GG_80401FE8(c, d, a, b, x[15], S23_80401FE8, 0xd8a1e681);
    GG_80401FE8(b, c, d, a, x[4], S24_80401FE8, 0xe7d3fbc8);
    GG_80401FE8(a, b, c, d, x[9], S21_80401FE8, 0x21e1cde6);
    GG_80401FE8(d, a, b, c, x[14], S22_80401FE8, 0xc33707d6);
    GG_80401FE8(c, d, a, b, x[3], S23_80401FE8, 0xf4d50d87);
    GG_80401FE8(b, c, d, a, x[8], S24_80401FE8, 0x455a14ed);
    GG_80401FE8(a, b, c, d, x[13], S21_80401FE8, 0xa9e3e905);
    GG_80401FE8(d, a, b, c, x[2], S22_80401FE8, 0xfcefa3f8);
    GG_80401FE8(c, d, a, b, x[7], S23_80401FE8, 0x676f02d9);
    GG_80401FE8(b, c, d, a, x[12], S24_80401FE8, 0x8d2a4c8a);
    HH_80401FE8(a, b, c, d, x[5], S31_80401FE8, 0xfffa3942);
    HH_80401FE8(d, a, b, c, x[8], S32_80401FE8, 0x8771f681);
    HH_80401FE8(c, d, a, b, x[11], S33_80401FE8, 0x6d9d6122);
    HH_80401FE8(b, c, d, a, x[14], S34_80401FE8, 0xfde5380c);
    HH_80401FE8(a, b, c, d, x[1], S31_80401FE8, 0xa4beea44);
    HH_80401FE8(d, a, b, c, x[4], S32_80401FE8, 0x4bdecfa9);
    HH_80401FE8(c, d, a, b, x[7], S33_80401FE8, 0xf6bb4b60);
    HH_80401FE8(b, c, d, a, x[10], S34_80401FE8, 0xbebfbc70);
    HH_80401FE8(a, b, c, d, x[13], S31_80401FE8, 0x289b7ec6);
    HH_80401FE8(d, a, b, c, x[0], S32_80401FE8, 0xeaa127fa);
    HH_80401FE8(c, d, a, b, x[3], S33_80401FE8, 0xd4ef3085);
    HH_80401FE8(b, c, d, a, x[6], S34_80401FE8, 0x4881d05);
    HH_80401FE8(a, b, c, d, x[9], S31_80401FE8, 0xd9d4d039);
    HH_80401FE8(d, a, b, c, x[12], S32_80401FE8, 0xe6db99e5);
    HH_80401FE8(c, d, a, b, x[15], S33_80401FE8, 0x1fa27cf8);
    HH_80401FE8(b, c, d, a, x[2], S34_80401FE8, 0xc4ac5665);
    II_80401FE8(a, b, c, d, x[0], S41_80401FE8, 0xf4292244);
    II_80401FE8(d, a, b, c, x[7], S42_80401FE8, 0x432aff97);
    II_80401FE8(c, d, a, b, x[14], S43_80401FE8, 0xab9423a7);
    II_80401FE8(b, c, d, a, x[5], S44_80401FE8, 0xfc93a039);
    II_80401FE8(a, b, c, d, x[12], S41_80401FE8, 0x655b59c3);
    II_80401FE8(d, a, b, c, x[3], S42_80401FE8, 0x8f0ccc92);
    II_80401FE8(c, d, a, b, x[10], S43_80401FE8, 0xffeff47d);
    II_80401FE8(b, c, d, a, x[1], S44_80401FE8, 0x85845dd1);
    II_80401FE8(a, b, c, d, x[8], S41_80401FE8, 0x6fa87e4f);
    II_80401FE8(d, a, b, c, x[15], S42_80401FE8, 0xfe2ce6e0);
    II_80401FE8(c, d, a, b, x[6], S43_80401FE8, 0xa3014314);
    II_80401FE8(b, c, d, a, x[13], S44_80401FE8, 0x4e0811a1);
    II_80401FE8(a, b, c, d, x[4], S41_80401FE8, 0xf7537e82);
    II_80401FE8(d, a, b, c, x[11], S42_80401FE8, 0xbd3af235);
    II_80401FE8(c, d, a, b, x[2], S43_80401FE8, 0x2ad7d2bb);
    II_80401FE8(b, c, d, a, x[9], S44_80401FE8, 0xeb86d391);
    state[0] += a;
    state[1] += b;
    state[2] += c;
    state[3] += d;
    NetMemset(x, 0, sizeof(x));
}
#pragma pop
#undef S11_80401FE8
#undef S12_80401FE8
#undef S13_80401FE8
#undef S14_80401FE8
#undef S21_80401FE8
#undef S22_80401FE8
#undef S23_80401FE8
#undef S24_80401FE8
#undef S31_80401FE8
#undef S32_80401FE8
#undef S33_80401FE8
#undef S34_80401FE8
#undef S41_80401FE8
#undef S42_80401FE8
#undef S43_80401FE8
#undef S44_80401FE8
#undef FF_80401FE8
#undef GG_80401FE8
#undef HH_80401FE8
#undef II_80401FE8
#undef ROTATE_LEFT_80401FE8
#undef F_80401FE8
#undef G_80401FE8
#undef H_80401FE8
#undef I_80401FE8

u16 read_network_u16_be(u8 *p) {
    u16 v = *p++;
    v <<= 8;
    v |= *p;
    return v;
}

u32 TLobby__sub_80402AFC(u8 *p) {
    u32 v = *p++;
    v <<= 8;
    v |= *p++;
    v <<= 8;
    v |= *p++;
    v <<= 8;
    v |= *p;
    return v;
}

u8 *write_network_u16_be(u8 *p, u16 v) {
    *p++ = v >> 8;
    *p++ = v;
    return p;
}

u8 *write_network_u32_be(u8 *p, u32 v) {
    *p++ = v >> 24;
    *p++ = v >> 16;
    *p++ = v >> 8;
    *p++ = v;
    return p;
}

void init_net_block_620(void) {
    TLobby__sub_803F778C((void *) (&lbl_805C0620.value));
}

typedef char RecoveredGlobal_80402B88_lbl_805C0620_size[sizeof(RecoveredGlobal_80402B88_lbl_805C0620) == 0x18 ? 1 : -1];
s32 init_net_block_620_secondary(void) {
    init_net_block_620_params((void *)(&(*(RecoveredGlobal_80402B88_lbl_805C0620 *)&lbl_805C0620).value));
    return 0;
}

extern s16 TLobby__sub_80402BB4(void *arg0, u32 timeout) {
    Conn_804004DC *c = (Conn_804004DC *)arg0;
    RecoveredGlobal_804050DC_lbl_805C18A0 *g;
    u8 *sub;

    sub = c->sub;
    g = &lbl_805C18A0;
    c->abort = 0;
    while (c->state != 5) {
        if (is_timed_out() != 0 || c->abort != 0 || *sub == 4) {
            update_connection_state((int)c);
            update_connection_state((int)(c->sub + 4));
            c->abort = 0;
            if (lbl_805D7A80 != 0) {
                lbl_805D7A82 = 6;
            } else {
                lbl_805D7A82 = 5;
            }
            lobby_modem_connect_state = 8;
            return -1;
        }
        if (get_remaining(timeout) != 0) {
            update_connection_state((int)c);
            update_connection_state((int)(c->sub + 4));
            return -0x12;
        }
        unlock_mutex(g->value);
        TLobby__sub_803F97E8(100);
        process_expired_timers();
        lock_mutex(g->value);
    }
    c->abort = 0;
    return 0;
}

extern s32 TLobby__sub_80403634(u8 *self_m);
extern u8 lbl_805E1180;
extern void TLobby__sub_80402CE0(u8 *arg0) {
    struct P_80402CE0 {
        void *name;
        u16 proto;
        u16 h6;
        u8 b8;
        u8 b9;
        u8 bA;
        u8 bB;
        s32 timeout;
        void *f10;
        void *f14;
        void *f18;
        void *f1C;
        void *f20;
        void *f24;
        void *f28;
        void *f2C;
        void *f30;
        void *f34;
        void *f38;
    };
    struct S_80402CE0;
    struct T_80402CE0 {
        u8 pad0[0x10];
        void *callback;
        struct S_80402CE0 *arg;
        u8 pad18[4];
    };
    struct S_80402CE0 {
        u8 f0; u8 f1; u8 f2; u8 f3; u8 f4; u8 f5; u8 f6; u8 f7;
        u8 pad8[4];
        u8 *sub;
        struct T_80402CE0 timer;
        struct P_80402CE0 *proto;
        u8 *opts;
    };
    u8 *g;
    struct P_80402CE0 *p;
    struct S_80402CE0 *fsm;
    struct T_80402CE0 *timer;

    g = (u8 *)&lbl_805C04D8;
    p = (struct P_80402CE0 *)g;
    fsm = (struct S_80402CE0 *)(arg0 + 0x38);
    if (fsm->opts == NULL) {
        timer = &fsm->timer;
        p->name = (void *)&lbl_805E1180;
        p->proto = 0xC023;
        p->h6 = 0xE;
        p->b8 = 1;
        p->bB = 0;
        p->b9 = g[0x15A];
        p->bA = g[0x15B];
        p->timeout = *(u16 *)(g + 0x15C) * 1000;
        p->f10 = (void *)TLobby__sub_803FE84C;
        p->f14 = (void *)TLobby__sub_803FE84C;
        p->f18 = (void *)TLobby__sub_803FE84C;
        p->f1C = (void *)TLobby__sub_803FE84C;
        p->f20 = (void *)TLobby__sub_803FE84C;
        p->f24 = (void *)TLobby__sub_803FE84C;
        p->f28 = (void *)TLobby__sub_80403634;
        p->f2C = (void *)TLobby__sub_803FE844;
        p->f30 = (void *)TLobby__sub_803FE844;
        p->f34 = (void *)TLobby__sub_803FE844;
        p->f38 = (void *)TLobby__sub_803FE844;
        fsm->sub = arg0;
        fsm->proto = p;
        fsm->opts = g + 0x3C;
        fsm->f4 = fsm->proto->b9;
        fsm->f7 = fsm->proto->bA;
        fsm->f5 = fsm->proto->bB;
        fsm->f0 = 0;
        fsm->f3 = fsm->f4;
        fsm->f6 = fsm->f7;
        timer->callback = (void *)handle_request_timeout;
        timer->arg = fsm;
        TLobby__sub_80405298((N_80405298 *)timer, fsm->proto->timeout);
    }
}

s32 mark_ready(void *self) {
    u8 *arg0 = (u8 *)self;
    *(s8 *)((s8 *)arg0 + 0x38) = 2;
    *(u8 *)((s8 *)arg0 + 0x3A) = (u8) (*(u8 *)((s8 *)arg0 + 0x3A) | 0x20);
    *(u8 *)((s8 *)arg0 + 2) = (u8) (*(u8 *)((s8 *)arg0 + 2) | 0x20);
    return 0;
}

void set_active(void *self) {
    u8 *arg0 = (u8 *)self;
    *(s8 *)((s8 *)arg0 + 0x38) = 1;
    *(u8 *)((s8 *)arg0 + 0x3A) = (u8) (*(u8 *)((s8 *)arg0 + 0x3A) | 0x10);
    *(u8 *)((s8 *)arg0 + 2) = (u8) (*(u8 *)((s8 *)arg0 + 2) | 0x10);
    *(u8 *)((s8 *)arg0 + 0x3B) = (u8) *(u8 *)((s8 *)arg0 + 0x3C);
}

extern u8 lbl_805D7AB8[8];
static inline s16 read_text_field(u8 *self, Hdr_803FC4B4 *hdr, s32 src) {
    s32 ret;
    u8 **pdst;
    s32 rv;
    s16 fld;
    s16 n;
    u8 *obj;
    obj = *(u8 **)(self + 0x30);
    if (hdr->flag != self[1]) {
        return -1;
    }
    n = (TLobby__sub_80401BCC(&src, lbl_805D7AB8, 1) != 1) ? -1 : (s16)lbl_805D7AB8[0];
    if (n != -1) {
        if (n != 0) {
            fld = (s16)get_field_4((void *)src);
            pdst = (u8 **)((u8 *)&lbl_805C0620 + 8);
            rv = TLobby__sub_80401ABC((u8 *)src, *pdst, n);
            (*pdst)[(s16)rv] = 0;
            *(u8 **)(obj + 8) = *pdst;
            ret = 1;
            if ((s16)rv < n || n < fld) {
            } else {
                ret = rv;
            }
            return ret;
        }
        return 0;
    }
    return -1;
}

#pragma push
#pragma dont_inline off
#pragma inline_depth(4)
void PADRead(u8 *self, s32 arg1)
{
  u8 *new_var;
  Hdr_803FC4B4 hdr;
  u8 *f30;
  u8 *p;
  extern s16 TLobby__sub_803FE8BC(u8 *, s32 *);
  extern s16 TLobby__sub_80403308(u8 *, u8 *, UnkSumBuf *);
  f30 = *((u8 **) (self + 0x30));
  if (TLobby__sub_803FE8BC((u8 *) (&hdr), &arg1))
  {
    return;
  }
  hdr.len -= 4;
  new_var = self;
  TLobby__sub_80401CAC((Outer_80401CAC *) (&arg1), hdr.len);
  switch (hdr.type)
  {
    case 1:
      if (TLobby__sub_80403308(new_var, (u8 *) (&hdr), (UnkSumBuf *) arg1))
    {
      return;
    }
      p = *((u8 **) (new_var + 0xC));
      self[2] &= ~0x10;
      if (!(self[2] & 0x30))
    {
      self[0] = 5;
    }
      TLobby__sub_80405304(new_var + 0x10);
      p[2] &= ~0x10;
      TLobby__sub_80400ACC((O_80400ACC *) p);
      return;

    case 2:
      if (read_text_field(new_var, &hdr, arg1) != 0)
    {
      return;
    }
      p = *((u8 **) (self + 0xC));
      self[2] &= ~0x20;
      if (!(self[2] & 0x30))
    {
      self[0] = 5;
    }
      TLobby__sub_80405304(0x10 + self);
      p[2] &= ~0x20;
      TLobby__sub_80400ACC((O_80400ACC *) p);
      return;

    case 3:
      if (read_text_field(self, &hdr, arg1) != 0)
    {
      return;
    }
      TLobby__sub_80405304(new_var + 0x10);
      *((s32 *) f30) = 0;
      *((s32 *) (f30 + 4)) = 0;
      *((s16 *) (new_var + 8)) = 1;
      self[0] = 0;
      lbl_805D7A80 = 1;
      return;

  }

}
#pragma pop
typedef char RecoveredGlobal_804050DC_lbl_805C18A0_size[sizeof(RecoveredGlobal_804050DC_lbl_805C18A0) == 0x10 ? 1 : -1];

s32 TLobby__sub_80403168(u8 *arg0, u8 *arg1, u8 *arg2) {
    Names_80403168 *g;
    u8 **p;
    u32 n;
    u32 m;
    p = *(u8 ***)(arg2 + 0x30);
    g = &lbl_805C04D8;
    n = NetStringLength((const char *)((void *)(arg0)));
    if (n >= 0x80) {
        n = 0x7F;
    }
    NetMemcpy(g->a, arg0, n);
    g->a[n] = 0;
    m = NetStringLength((const char *)((void *)(arg1)));
    if (m >= 0x80) {
        m = 0x7F;
    }
    NetMemcpy(g->b, arg1, m);
    g->b[m] = 0;
    p[0] = g->a;
    p[1] = g->b;
    return 0;
}

void reset_connection_state(void *self) {
    u8 *arg0 = (u8 *)self;
    typedef struct Fields_arg0 { u8 field_0; u8 pad_1[1]; s8 field_2; u8 pad_3[45]; u32 field_30; } Fields_arg0;
    u8 temp_r0;
    if ((u32) ((Fields_arg0*)arg0)->field_30 != 0U) {
        ((Fields_arg0*)arg0)->field_2 = 0;
        temp_r0 = ((Fields_arg0*)arg0)->field_0;
        if ((s32) temp_r0 != 2) {
            if ((s32) temp_r0 < 2) {
                if ((s32) temp_r0 != 0) {
                    if ((s32) temp_r0 < 0) {
                        return;
                    }
                    goto block_10;
                }
            } else if ((s32) temp_r0 < 7) {
                if ((s32) temp_r0 < 5) {
                    return;
                }
                goto block_10;
            }
        } else {
            TLobby__sub_80405304((void *)((void *) ((u8 *)(arg0) + 0x10)));
block_10:
            ((Fields_arg0*)arg0)->field_0 = 0U;
        }
    }
}

void handle_request_timeout(void *self) {
    u8 *arg0 = (u8 *)self;
    u8 *temp_r4;
    temp_r4 = (u8 *)(*(u8 **)((s8 *)arg0 + 0x30));
    if ((u8) *(u8 *)((s8 *)arg0 + 3) != 0) {
        *(s32 **)((s8 *)temp_r4 + 8) = lbl_8047FEB8;
        TLobby__sub_803FE658((u8 *)((void *) (arg0)));
        return;
    }
    *(s32 **)((s8 *)temp_r4 + 8) = lbl_8047FEC8;
    update_connection_state((int) (*(s32 *)((s8 *)arg0 + 0xC) + 4));
    *(s16 *)((s8 *)arg0 + 8) = 1;
}

extern u8 lbl_8047FEE0[];
extern u8 lbl_8047FEEC[];
#pragma push
#pragma dont_inline off
#pragma inline_depth(4)
inline s32 valid_80403308(UnkSumBuf **s) {
    s32 r = 0;
    if (s != NULL && *s != NULL) {
        r = 1;
    }
    return r;
}
inline s32 avail_80403308(UnkSumBuf **s) {
    s32 r = 0;
    if (valid_80403308(s) && (*s)->len > 1) {
        r = 1;
    }
    return r;
}
inline s32 get_80403308(UnkSumBuf **s) {
    if (avail_80403308(s)) {
        (*s)->len--;
        return *(*s)->data++;
    }
    if (TLobby__sub_80401BCC(s, lbl_805D7AB8, 1) != 1) {
        return -1;
    }
    return (s16)lbl_805D7AB8[0];
}
extern s16 TLobby__sub_80403308(u8 *self, u8 *src, UnkSumBuf *val) {
    s32 TLobby__sub_803FE6CC(void *, u8, u8, void *); /* declared here with other parameter types; the definition is s32 (void *, int, int, void *) */
    u8 *p1 = 0;
    u8 *p2 = 0;
    s16 ch;
    s16 res;
    s32 t;
    s16 st;
    u8 *ptr;
    s16 n;
    u8 *ent;

    ch = (TLobby__sub_80401BCC(&val, lbl_805D7AB8, 1) != 1) ? -1 : (s16)lbl_805D7AB8[0];
    if (ch != -1) {
        s16 cnt;
        u8 *out;
        p1 = (u8 *)lbl_805C0620.value;
        out = p1;
        for (cnt = ch; cnt-- > 0;) {
            *out++ = get_80403308(&val);
        }
        *out = 0;
    }

    ch = (TLobby__sub_80401BCC(&val, lbl_805D7AB8, 1) != 1) ? -1 : (s16)lbl_805D7AB8[0];
    if (ch != -1) {
        s16 cnt;
        u8 *out;
        p2 = *(u8 **)((u8 *)&lbl_805C0620 + 4);
        out = p2;
        for (cnt = ch; cnt-- > 0;) {
            *out++ = get_80403308(&val);
        }
        *out = 0;
    }

    if (lbl_805D7A90 & 2) {
        t = TLobby__sub_803F7684(p1);
        if (t == 0) {
            res = -1;
        } else if (NetCompareStrings((const char *)(p2), (const char *)t) != 0) {
            res = -1;
        } else {
            goto zero;
        }
    } else {
zero:
        res = 0;
    }

    if (res == 0) {
        *(u8 **)(*(u8 **)(self + 0xc) + 0x10c) = p1;
        ptr = lbl_8047FEE0;
        st = 2;
    } else {
        ptr = lbl_8047FEEC;
        st = 3;
    }
    n = (s16)NetStringLength((const char *)(ptr));
    ent = (u8 *)TLobby__sub_80401B20(ptr, n);
    *(*(u8 **)ent) = (u8)(n - 1);
    TLobby__sub_803FE6CC(self, st, src[1], ent);

    if (st == 3) {
        if (self[6] != 0) {
            self[6]--;
        } else {
            update_connection_state((int)(*(u8 **)(self + 0xc) + 4));
        }
    }
    return st != 2;
}
#pragma pop

#pragma push
#pragma opt_common_subs on
s32 TLobby__sub_80403634(u8 *self_m)
{
  u8 *blk;
  u32 *p;
  u8 *buf;
  s32 n1;
  s32 n2;
  s32 len;
  u16 old;
  p = *((u32 **) (self_m + 0x30));
  if ((p[0] == 0) || (p[1] == 0))
  {
    return 0;
  }
  blk = ((void*)init_net_buffer_entry((u16)(0)));
  if (blk == ((void *) 0))
  {
    return 0;
  }
  buf = *((u8 **) blk);
  n1 = NetStringLength((const char *)((void*)((void *) p[0])));
  *(buf++) = n1;
  NetMemcpy((void *)(buf), (void *)((void *) p[0]), (int)(n1));
  buf += n1;
  n2 = NetStringLength((const char *)((void*)((void *) p[1])));
  *(buf++) = n2;
  NetMemcpy((void *)(buf), (void *)((void *) p[1]), (int)(n2));
  old = *((u16 *) (blk + 4));
  len = n1 + n2;
  if ((!len) && (!len))
  {
  }
  len += old;
  *((u16 *) (blk + 4)) = len + 2;
  return (s32) blk;
}
#pragma pop

s32 TLobby__sub_804036FC(u8 *arg0) {
    if (TLobby__sub_803F811C((s16 *)arg0) != 0) {
        return -1;
    }
    return 0;
}

typedef char RecoveredGlobal_80403D28_lbl_805C0638_size[sizeof(RecoveredGlobal_80403D28_lbl_805C0638) == 0xA0 ? 1 : -1];

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

s32 TLobby__sub_80403D28(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7) {
    s32 temp_r31;
    *(s8 *)((s8 *)(&lbl_805C0638.value) + 0) = 0;
    *(s8 *)((s8 *)(&lbl_805C0638.value) + 0x14) = 0;
    *(s8 *)((s8 *)(&lbl_805C0638.value) + 0x28) = 0;
    *(s8 *)((s8 *)(&lbl_805C0638.value) + 0x3C) = 0;
    *(s8 *)((s8 *)(&lbl_805C0638.value) + 0x50) = 0;
    *(s8 *)((s8 *)(&lbl_805C0638.value) + 0x64) = 0;
    *(s8 *)((s8 *)(&lbl_805C0638.value) + 0x78) = 0;
    *(s8 *)((s8 *)(&lbl_805C0638.value) + 0x8C) = 0;
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

void TLobby__sub_804053B8(B_80403F4C *, u8 **);
u8 *TLobby__sub_8040555C(B_80403F4C *, u8 *, s32);
#define o ((Obj_80403F4C *)ov)
#define pp ((u8 **)spp)
s16 TLobby__sub_80403F4C(void *ov, Strm_80405A74 **spp) {
    A_80403F4C a;
    B_80403F4C b;
    Ent_80403F4C *e;
    u8 c;

    TLobby__sub_803FEA88(&a, spp);
    TLobby__sub_804053B8(&b, pp);
    c = a.proto;
    if (c > o->max) {
        o->n30++;
        if (o == NULL) {
            return 0;
        }
        o->flags |= 1;
        return 0;
    }
    e = &o->ents[c];
    o->cur = c;
    o->flags &= ~1;
    a.proto = 6;
    e->a = a;
    e->b = b;
    *pp = TLobby__sub_8040555C(&b, *pp, 0);
    *pp = GXLoadTexObjPreLoaded(&a, *pp, 1);
    o->n28++;
    return get_field_4((void *)(*pp));
}

#pragma push
#pragma dont_inline off
#pragma inline_depth(4)
inline s32 vj_buffer_valid(Strm_80405A74 **src) {
    s32 valid = 0;
    if (src != NULL && *src != NULL) {
        valid = 1;
    }
    return valid;
}
inline s32 vj_read_byte(Strm_80405A74 **src) {
    if (TLobby__sub_80401BCC(src, lbl_805D7AC4, 1) != 1) {
        return -1;
    }
    return (s16)lbl_805D7AC4[0];
}
inline s32 vj_next_byte(Strm_80405A74 **src) {
    s32 fast = 0;
    if (vj_buffer_valid(src) && (*src)->len > 1) {
        fast = 1;
    }
    if (fast) {
        (*src)->len--;
        return *(*src)->p++;
    }
    return vj_read_byte(src);
}
inline s32 vj_read_u16(Strm_80405A74 **src) {
    if (TLobby__sub_80401BCC(src, lbl_805D7AC0, 2) != 2) {
        return -1;
    }
    return read_network_u16_be(lbl_805D7AC0);
}
#define comp ((Obj_80403F4C *)self)
#define src ((Strm_80405A74 **)arg)
s16 TLobby__sub_804040E0(void *self, void *arg) {
    B_80403F4C *th;
    Ent_80403F4C *cs;
    s16 changes;
    s32 v;
    s16 len;

    comp->n2C++;
    if (get_field_4(*src) < 3) {
        comp->n30++;
        return 0;
    }
    changes = vj_next_byte(src);
    if (changes & 0x40) {
        v = vj_next_byte(src);
        if (v < 0 || v > comp->max) {
            goto bad;
        }
        comp->flags &= ~1;
        comp->cur = v;
    } else if (comp->flags & 1) {
        comp->n34++;
        return 0;
    }
    if (comp->cur > comp->max) {
        comp->n34++;
        return 0;
    }
    th = &(cs = &comp->ents[comp->cur])->b;
    v = vj_read_u16(src);
    if (v == -1) {
        goto bad;
    }
    th->checksum = v;
    th->psh = (changes & 0x10) ? 1 : 0;
    switch (changes & 0xF) {
    case 0xB: {
        s16 i = cs->a.len;
        i -= cs->a.optlen + 40;
        th->ack += i;
        th->seq += i;
        break;
    }
    case 0xF:
        th->seq += cs->a.len - (cs->a.optlen + 40);
        break;
    default:
        if (changes & 1) {
            th->urg = 1;
            v = vj_next_byte(src);
            if (v == 0) {
                v = vj_read_u16(src);
            }
            if (v == -1) {
                goto bad;
            }
            th->urgent = v;
        } else {
            th->urg = 0;
        }
        if (changes & 2) {
            v = vj_next_byte(src);
            if (v == 0) {
                v = vj_read_u16(src);
            }
            if (v == -1) {
                goto bad;
            }
            th->window += (s16)v;
        }
        if (changes & 4) {
            v = vj_next_byte(src);
            if (v == 0) {
                v = vj_read_u16(src);
            }
            if (v == -1) {
                goto bad;
            }
            th->ack += v;
        }
        if (changes & 8) {
            v = vj_next_byte(src);
            if (v == 0) {
                v = vj_read_u16(src);
            }
            if (v == -1) {
                goto bad;
            }
            th->seq += v;
        }
        break;
    }
    if (changes & 0x20) {
        v = vj_next_byte(src);
        if (v == 0) {
            v = vj_read_u16(src);
        }
        if (v == -1) {
            goto bad;
        }
        cs->a.id += v;
    } else {
        cs->a.id++;
    }
    len = get_field_4(*src) + 40 + cs->a.optlen;
    cs->a.len = len;
    *src = (Strm_80405A74 *)TLobby__sub_8040555C((B_80403F4C *)th, (u8 *)*src, 0);
    *src = (Strm_80405A74 *)GXLoadTexObjPreLoaded(&cs->a, (u8 *)*src, 0);
    return len;

bad:
    comp->n30++;
    if (comp == NULL) {
        return 0;
    }
    comp->flags |= 1;
    return 0;
}
#undef comp
#undef src
#pragma pop

#undef o
#undef pp

struct RecoveredFields_80401B8C_arg0;

struct Ent_804086B4;

typedef char RecoveredFields_804143BC_arg0_0_offset[offsetof(RecoveredFields_804143BC_arg0, field_0) == 0x0 ? 1 : -1];
typedef char RecoveredFields_804143BC_arg0_1_offset[offsetof(RecoveredFields_804143BC_arg0, field_1) == 0x1 ? 1 : -1];

RecoveredGlobal_80403D28_lbl_805C0638 lbl_805C0638;
RecoveredGlobal_80402B60_lbl_805C0620 lbl_805C0620;
Names_80403168 lbl_805C04D8;
RecoveredGlobal_80401A68_lbl_805C04A8 lbl_805C04A8;
LcpState lbl_805C0400;
IpcpState lbl_805C0328;
RecoveredGlobal_803FD520_lbl_805C0310 lobby_net_buffer_desc_b;
