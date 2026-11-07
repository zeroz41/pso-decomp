#include "pso/network/NetworkTransport.h"
#include "pso/unk/TLobby.h"
#include "pso/unk/TLobby_803FAEA0.h"

#include "types.h"
#include "pso/network/NetworkRuntime.h"

struct Self_803FD85C;
struct Tbl_803FD85C {
    u8 pad[0x14];
    void (*f14)(Self_803FD85C *, Tbl_803FD85C *);
    u8 pad18[8];
    void (*f20)(Self_803FD85C *, Tbl_803FD85C *);
};
struct Self_803FD85C {
    u8 f0; u8 f1; u8 f2; u8 f3; u8 f4; u8 f5; u8 f6; u8 f7;
    u8 pad8[8];
    u8 f10[0x1C];
    Tbl_803FD85C *tbl;
    void *f30;
};

struct Info_8040098C { u8 pad[0x1C]; s16 f1C; u8 pad1E[6]; u16 f24; u8 pad26[0x2A]; s16 f50; u8 pad52[6]; u16 f58; };
struct St_8040098C { s8 f0; u8 f1; u8 f2; u8 pad3[0x69]; u8 f6C[0x9C]; s32 f108; s32 f10C; };
struct Self_8040098C { u8 pad[0xC]; St_8040098C *st; u8 pad10[0x20]; Info_8040098C *info; };

struct RecoveredGlobal_803F8AA0_lbl_805BA5C0 {
    s32 value;
    u8 remaining[0x30A8];
};

struct RecoveredGlobal_803F8A0C_lbl_805B9534 {
    s32 value;
    u8 remaining[0x1088];
};

struct RecoveredGlobal_8041552C_lbl_805C1BE0 {
    s32 value;
    u8 remaining[0x14];
};

struct RecoveredGlobal_803FB110_lbl_805BFF68 {
    s32 value;
    u8 remaining[0xCC];
};

struct RecoveredGlobal_804050DC_lbl_805C18A0 {
    s32 value;
    u8 remaining[0xC];
};

struct RecoveredGlobal_803FD520_lbl_805C0310 {
    s16 h0;
    s16 h2;
    s16 h4;
    s16 h6;
    s16 h8;
    u8 padA[2];
    s16 *buf;
    u8 pad10[6];
    s16 h16;
};

struct RecoveredGlobal_803F895C_lbl_805AEEB0 {
    s32 value;
    u8 remaining[0x49C4];
};

struct RecoveredGlobal_803F89A4_lbl_805B52D4 {
    s32 value;
    u8 remaining[0x17C];
};

struct RecoveredGlobal_803F89A4_lbl_805B5454 {
    s32 value;
    u8 remaining[0x64];
};

struct RecoveredGlobal_803F89DC_lbl_805B54BC {
    s32 value;
    u8 remaining[0x3FFC];
};

struct RecoveredGlobal_803F89DC_lbl_805B94BC {
    s32 value;
    u8 remaining[0x74];
};

struct RecoveredGlobal_803F8A28_lbl_805AEEB0 {
    s32 value;
    u8 remaining[0x49C4];
};

struct RecoveredGlobal_803F94A0_lbl_805BF770 {
    s32 value;
    u8 remaining[0x74C];
};

struct RecoveredGlobal_803FC178_lbl_805C02D0 {
    s32 value;
    u8 remaining[0x3C];
};

struct RecoveredGlobal_803FC1A0_lbl_805C02D0 {
    s32 value;
    u8 remaining[0x3C];
};

struct RecoveredGlobal_80401A68_lbl_805C04A8 {
    s32 value;
    u8 remaining[0x2C];
};

struct RecoveredGlobal_80401A90_lbl_805C04A8 {
    s32 value;
    u8 remaining[0x2C];
};

struct RecoveredGlobal_80402B60_lbl_805C0620 {
    s32 value;
    u8 remaining[0x14];
};

struct RecoveredGlobal_80402B88_lbl_805C0620 {
    s32 value;
    u8 remaining[0x14];
};

struct RecoveredGlobal_80403D28_lbl_805C0638 {
    s32 value;
    u8 remaining[0x9C];
};

struct RecoveredGlobal_804050EC_lbl_805C18A0 {
    s32 value;
    u8 remaining[0xC];
};

struct RecoveredGlobal_80405114_lbl_805C18A0 {
    s32 value;
    u8 remaining[0xC];
};

struct RecoveredGlobal_8040EF00_lbl_805C1B60 {
    s32 value;
    u8 remaining[0x14];
};

struct RecoveredGlobal_8040FE40_lbl_805C1B60 {
    s32 value;
    u8 remaining[0x14];
};

struct RecoveredGlobal_8040FE9C_lbl_805C1B60 {
    s32 value;
    u8 remaining[0x14];
};

struct RecoveredGlobal_8041123C_lbl_805C1BB8 {
    union { s32 value; struct { s16 a; s16 b; } ab; };
    s16 c;
    u8 remaining[0x22];
};

struct RecoveredGlobal_804112B8_lbl_805C1BB8 {
    s32 value;
    u8 remaining[0x24];
};

struct RecoveredGlobal_80411ECC_lbl_805C1BB8 {
    s32 value;
    u8 remaining[0x24];
};

struct RecoveredGlobal_8041471C_lbl_805C1BB8 {
    s32 value;
    u8 remaining[0x24];
};

#include <stddef.h>
#include "pso/network/TUdpSocket.h"

struct H_8041A130 { s16 used; u16 type; void (*fn)(s32, s16, s16, s16); };
struct RecoveredGlobal_80419A00_lbl_805C1C50 {
    s32 value;
    s32 queue;
    u8 pad8[0xC];
    H_8041A130 h[3];
    u8 rest[0xCC];
};

struct E_805C1D48 { u8 pad[4]; u16 f4; s16 f6; u8 pad2[0x53C]; };
struct RecoveredGlobal_8041E178_lbl_805C1D48 {
    union { s32 value; E_805C1D48 *p; };
    s16 n;
    u8 remaining[0xA2];
};

struct RecoveredGlobal_803AA0C0_lbl_80556E88 {
    s32 value;
    u8 remaining[0xFC];
};

struct RecoveredGlobal_803F8930_lbl_805B4F84 {
    s32 value;
    u8 remaining[0x34C];
};

struct RecoveredGlobal_803F8B7C_lbl_805BD66C {
    s32 value;
    u8 remaining[0xA00];
};

struct RecoveredFields_80401B8C_arg0 {
    s32 field_0;
    u16 field_4;
};

struct E_8040DDB0 { u8 c0; u8 c1; u8 c2; u8 c3; s16 f4; u8 pad6[0x16]; };
struct RecoveredGlobal_8040DD68_lbl_805C1B38 {
    s16 value;
    u8 pad2[2];
    E_8040DDB0 *ents;
    s16 f8;
    u8 padA[0x1E];
};

struct RecoveredGlobal_8040ED28_lbl_805C1B60 {
    s32 value;
    u8 remaining[0x14];
};

struct RecoveredGlobal_8040ED70_lbl_805C1B60 {
    s32 value;
    u8 remaining[0x14];
};

struct E_8040FF58 { u8 c0; u8 c1; u8 c2; u8 c3; s16 f4; u8 pad6[0x2E]; };
struct RecoveredGlobal_8040FF0C_lbl_805C1B78 {
    s16 value;
    u8 pad2[2];
    E_8040FF58 *ents;
    s32 f8;
    u8 padC[0x34];
};

struct RecoveredGlobal_80415650_lbl_805C1BF8 {
    s16 value;
    u8 remaining[0xE];
};

struct RecoveredGlobal_80419A34_lbl_805C1C50 {
    s32 value;
    u8 remaining[0xF4];
};

struct RecoveredGlobal_80419A7C_lbl_805C1C50 {
    s32 value;
    u8 remaining[0xF4];
};

struct RecoveredGlobal_80409A3C_lbl_805C1C50 {
    s32 value;
    u8 remaining[0xF4];
};

struct RecoveredGlobal_803F88E4_lbl_805AEEB0
{
  s32 value;
  u8 remaining[0x49C4];
};

struct RecoveredFields_803F88E4_arg0
{
  s16 field_0;
  s16 field_2;
  s16 field_4;
  u8 unknown_6[0x2];
  u8 *field_8;
  u8 *field_C;
  u8 *field_10;
  s16 field_14;
  u8 unknown_16[0x2];
  u8 *field_18;
};

struct Inner_80401CAC { u8 pad[4]; u16 f4; };

struct Outer_80401CAC { Inner_80401CAC *p; };

struct Ent_80408718 { s16 f0; u8 pad[0x16]; };

struct Tbl_80408718 { s16 count; s16 h2; s16 h4; s16 h6; s16 h8; u8 pad[4]; Ent_80408718 *list; };

typedef struct Conn_804004DC {
    u8 state;
    u8 pad[7];
    s16 abort;
    u8 pad2[2];
    u8 *sub;
} Conn_804004DC;

typedef struct Blk_80400BA8 {
    s16 flags;
    u8 pad[2];
    s32 w8;
    s32 wC;
    s32 time;
    s32 w14;
    s32 w18;
} Blk_80400BA8;

typedef struct St_80400BA8 {
    s16 flags;
    u8 pad[2];
    Blk_80400BA8 cur;
    Blk_80400BA8 saved;
    s16 f34;
    u8 pad36[2];
    s16 f38;
    u8 pad3A[0x16];
    s16 f50;
} St_80400BA8;

typedef struct Cfg_804019A8 {
    u8 pad[4];
    s16 flags;
    u8 pad6[6];
    u16 mode;
    u8 padE[0xA];
    u8 b18;
    u8 b19;
} Cfg_804019A8;

typedef struct Names_80403168 {
    u8 pad[0x48];
    u8 a[0x80];
    u8 b[0x80];
} Names_80403168;

typedef struct Ent_804099B4 {
    s16 active;
    u8 pad[0x2E];
} Ent_804099B4;

typedef struct Tbl_804099B4 {
    s16 count;
    Ent_804099B4 *ents;
} Tbl_804099B4;

typedef struct Ent_80409B48 {
    s16 active;
    u8 pad[0x2A];
    s32 (*fn)(s32, s32, s32, s32);
} Ent_80409B48;

typedef struct Tbl_80409B48 {
    s16 count;
    Ent_80409B48 *ents;
} Tbl_80409B48;

typedef struct Ent_80409BD4 {
    s16 active;
    s16 flags;
    u8 pad[0x24];
    s32 (*fn)(s32, s32, s32);
    u8 pad2[0x4];
} Ent_80409BD4;

typedef struct Tbl_80409BD4 {
    s16 count;
    Ent_80409BD4 *ents;
} Tbl_80409BD4;

struct Strm_80405A74 { u8 *p; u16 len; };

typedef struct B_803FADA0 { u8 *buf; u16 len; } B_803FADA0;

typedef struct A_803FADA0 { u8 pad0[4]; u32 a; u32 b; } A_803FADA0;

extern "C" {
u8 *TLobby__sub_803FB110(void);
extern RecoveredGlobal_804050DC_lbl_805C18A0 lbl_805C18A0;
void TLobby__sub_804050DC(s16 arg0);
extern RecoveredGlobal_803FD520_lbl_805C0310 lobby_net_buffer_desc_b;
extern s16 lbl_805D7A7A;
void NetStoreTick(s32 *arg0);
s32 NetMemcmp(void *, void *, int);
void NetMemset(void *, int, int);
void NetMemcpy(void *, void *, int);
void TLobby__sub_803F7678(void);
void TLobby__sub_803FD0C0(void);
s32 TLobby__sub_803FAFDC(void);
s16 TLobby__sub_803FB358(NetLinkStatus *status);
void TLobby__sub_803FD85C(void *);
s32 TLobby__sub_804062A0(s16);
extern s32 lobby_timer_list_head;
s16 reset_network_timer_list(void);
void TLobby__sub_803F8A08(void *);
s32 TLobby__sub_8040799C(s16, void *, void *);
void TLobby__sub_803F8A9C(void *);
extern s16 lobby_handler_table_desc;
s32 NetMemcmp(void * _w0, void * _w1, int _w2);
s32 TLobby__sub_8040FDA0(u32, s16);
extern RecoveredGlobal_8041123C_lbl_805C1BB8 ipv6_address_routing_state;
void NetMemset(void * _w0, int _w1, int _w2);
s32 TLobby__sub_803FE6CC(void *, int, int, void *);
s16 TLobby__sub_8040FCEC(u32);
void TLobby__sub_803F892C(void *);
void TLobby__sub_803F8958(void *);
void TLobby__sub_803F87DC(void *);
void TLobby__sub_803F89D8(void *);
void TLobby__sub_80401CAC(Outer_80401CAC *o, u16 v);
u16 read_network_u16_be(u8 *p);
extern u16 lbl_805D7A78;
u32 TLobby__sub_80402AFC(u8 *p);
u8 *write_network_u16_be(u8 *p, u16 v);
extern Tbl_80408718 lbl_805C1AB0;
s32 TLobby__sub_80405304(void *arg0);
s32 update_connection_state__6TLobbyFi(void *, void *);
void TLobby__sub_803F97E8(int);
void NetMemcpy(void * _w0, void * _w1, int _w2);
s32 TLobby__sub_803FC684(u8 *, u8 *, u8 *);
extern s16 lbl_805D7A7C;
extern s32 lbl_805D7A90;
s16 TLobby__sub_80401BCC(void *, void *, int);
extern u8 lcp_read_value_buffer[4];
extern u8 lobby_read_byte_buffer[1];
s16 TLobby__sub_80403F4C(void *, Strm_80405A74 **);
}
extern u8 lobby_ppp_read_buf;
extern u32 lbl_805BFF68[];
extern s16 lbl_805D7A82;
extern s16 lbl_805D7A84;
extern s16 lbl_805D7A88;
extern s16 lobby_modem_connect_state;
extern s32 lbl_805D7A8C;
s16 NetApplyConnectionConfig(u8 *arg0);
extern "C" {

void TLobby__sub_803F87DC(void * _w0);

typedef struct RecoveredFields_803F88E4_arg0 RecoveredFields_803F88E4_arg0;
typedef struct RecoveredGlobal_803F88E4_lbl_805AEEB0 RecoveredGlobal_803F88E4_lbl_805AEEB0;
typedef char RecoveredGlobal_803F88E4_lbl_805AEEB0_size[((sizeof(RecoveredGlobal_803F88E4_lbl_805AEEB0)) == 0x49C8) ? (1) : (-1)];

void TLobby__sub_803F892C(void * _w0);

#pragma push
#pragma opt_common_subs on
typedef char RecoveredGlobal_803F8930_lbl_805B4F84_size[sizeof(RecoveredGlobal_803F8930_lbl_805B4F84) == 0x350 ? 1 : -1];
#pragma pop

void TLobby__sub_803F8958(void * _w0);

typedef char RecoveredGlobal_803F895C_lbl_805AEEB0_size[sizeof(RecoveredGlobal_803F895C_lbl_805AEEB0) == 0x49C8 ? 1 : -1];

typedef char RecoveredGlobal_803F89A4_lbl_805B52D4_size[sizeof(RecoveredGlobal_803F89A4_lbl_805B52D4) == 0x180 ? 1 : -1];
typedef char RecoveredGlobal_803F89A4_lbl_805B5454_size[sizeof(RecoveredGlobal_803F89A4_lbl_805B5454) == 0x68 ? 1 : -1];

void TLobby__sub_803F89D8(void * _w0);

typedef char RecoveredGlobal_803F89DC_lbl_805B54BC_size[sizeof(RecoveredGlobal_803F89DC_lbl_805B54BC) == 0x4000 ? 1 : -1];
typedef char RecoveredGlobal_803F89DC_lbl_805B94BC_size[sizeof(RecoveredGlobal_803F89DC_lbl_805B94BC) == 0x78 ? 1 : -1];

void TLobby__sub_803F8A08(void * _w0);

typedef char RecoveredGlobal_803F8A0C_lbl_805B9534_size[sizeof(RecoveredGlobal_803F8A0C_lbl_805B9534) == 0x108C ? 1 : -1];

typedef char RecoveredGlobal_803F8A28_lbl_805AEEB0_size[sizeof(RecoveredGlobal_803F8A28_lbl_805AEEB0) == 0x49C8 ? 1 : -1];

void TLobby__sub_803F8A9C(void * _w0);

typedef char RecoveredGlobal_803F8AA0_lbl_805BA5C0_size[sizeof(RecoveredGlobal_803F8AA0_lbl_805BA5C0) == 0x30AC ? 1 : -1];

typedef char RecoveredGlobal_803F8B7C_lbl_805BD66C_size[sizeof(RecoveredGlobal_803F8B7C_lbl_805BD66C) == 0xA04 ? 1 : -1];

typedef char RecoveredGlobal_803F94A0_lbl_805BF770_size[sizeof(RecoveredGlobal_803F94A0_lbl_805BF770) == 0x750 ? 1 : -1];

typedef char RecoveredGlobal_803AA0C0_lbl_80556E88_size[sizeof(RecoveredGlobal_803AA0C0_lbl_80556E88) == 0x100 ? 1 : -1];

typedef char RecoveredGlobal_803FB110_lbl_805BFF68_size[sizeof(RecoveredGlobal_803FB110_lbl_805BFF68) == 0xD0 ? 1 : -1];

u32 lbl_805BFF68[52];
u32 lbl_805C0038[82];
#define lbl_805BFF68 (*(RecoveredGlobal_803FB110_lbl_805BFF68 *)lbl_805BFF68)
#define lbl_805C0038 ((u8 *)lbl_805C0038)

s32 NetControl(s32 cmd, s32 arg) {
    switch (cmd) {
    case 1:
        TLobby__sub_804050DC(arg);
        return 0;
    }
    return -1;
}

/* Connection request at lbl_805BFF68, filled by NetApplyConnectionConfig. */
struct LoginCfg_803FAEDC {
    u16 flags;
    s16 h2;
    s16 h4;
    u8 pad_6[2];
    s32 start_time;
    u8 *wC;
    u8 *w10;
    char *user;
    void (*callback)(s16, s32);
    s16 h1C;
    s16 h1E;
    s16 h20;
    u8 pad_22[0x42];
    char *w64;
    s32 w68;
    s32 w6C;
    s32 w70;
    s32 w74;
    s32 w78;
    s16 h7C;
    s16 h7E;
    s16 h80;
    u8 pad_82[6];
    s16 state;
    s16 mode;
    s16 h8C;
    u8 pad_8E[6];
    char *prefix;
    s16 h98;
    u16 h9A;
    u32 w9C;
    u16 hA0;
    u16 hA2;
    s16 hA4;
    u8 pad_A6[2];
    s32 wA8;
    s32 wAC;
    s32 wB0;
    s32 wB4;
    s32 wB8;
    s32 wBC;
    u8 C0[8];
    u8 C8[8];
};
struct H_803FB120 { u8 pad[0x28]; u8 *name; u8 pad2C[0x20]; void *v4C; };
extern H_803FB120 lobby_net_session_state;

s16 TLobby__sub_803FAEDC(LoginCfg_803FAEDC *cfg) {
    u32 plen;
    u8 *p;
    u8 **pname = &lobby_net_session_state.name;
    u32 len;
    u8 *buf = lobby_net_session_state.name;

    if (cfg->user == NULL) {
        return 1;
    }
    len = NetStringLength((const char*)cfg->user);
    if (cfg->mode == 1 && cfg->prefix != NULL) {
        plen = NetStringLength((const char*)cfg->prefix);
        if (plen + len > 59) {
            return 1;
        }
        NetMemcpy(buf, cfg->prefix, plen);
        p = buf + plen;
        NetMemcpy(p, cfg->user, len);
        p[len] = 0;
    } else {
        if (len > 59) {
            return 1;
        }
        NetMemcpy(buf, cfg->user, len);
        buf[len] = 0;
    }
    if (TLobby::map_state_to_code((s32)*pname, cfg->state) < 0) {
        return 1;
    }
    return 0;
}

s32 TLobby__sub_803FAFDC(void) {
    TLobby::stop_network_thread();
    TLobby::init_net_state_a();
    TLobby::init_net_block_620();
    TLobby__sub_803F7678();
    TLobby::reset_boot_state();
    TLobby__sub_803FD0C0();
    TLobby::init_net_block_18A0();
    TLobby::init_net_state_c();
    return 0;
}

s32 TLobby__sub_803F767C(void);
void TLobby__sub_803F7A90(void);
s16 TLobby__sub_803FD10C(void);
void TLobby__sub_804061FC(int);
extern s16 lbl_805D7A7E;
extern s16 lobby_modem_abort_flag;
struct Sess_803FB01C { u8 pad[0x1C]; u8 buf[0x60]; u8 rest[0x54]; };

s16 TLobby::init_net_session() {
    s16 i;
    s16 ret;
    Sess_803FB01C *p;

    TLobby::init_net_subsystem_block();
    TLobby::run_net_init_step();
    ret = TLobby__sub_803FD10C();
    if (ret < 0) {
        return -1;
    }
    init_modem_session_config();
    TLobby__sub_803F767C();
    TLobby::init_net_block_620_secondary();
    TLobby::init_net_state_b();
    NetMemset(&lbl_805BFF68, 0, sizeof(lbl_805BFF68));
    p = (Sess_803FB01C *)&lbl_805BFF68;
    i = 0;
    while (i < 1) {
        NetMemcpy(p->buf, lobby_net_session_state.v4C, 0x60);
        i++;
        p++;
    }
    lobby_modem_connect_state = 0;
    lbl_805D7A88 = 0;
    lobby_modem_abort_flag = 0;
    lbl_805D7A84 = 0;
    lbl_805D7A82 = 0;
    lbl_805D7A7E = 0;
    if (reset_network_timer_list() == 0) {
        TLobby__sub_804061FC(0);
    }
    TLobby__sub_803F7A90();
    return ret;
}

u8 *TLobby__sub_803FB110(void) {
    return (u8 *)&lbl_805BFF68.value + 0x1C;
}

struct G_803FB120 { u8 pad[0x1C]; u8 buf[0x60]; };
u8 *TLobby::copy_name_buffer(void *src) {
    G_803FB120 *g = (G_803FB120 *)&lbl_805BFF68;
    if (src == 0) {
        NetMemcpy(g->buf, lobby_net_session_state.v4C, 0x60);
    } else {
        NetMemcpy(g->buf, src, 0x60);
    }
    return g->buf;
}

s16 NetGetLinkStatus(NetLinkStatus *status) {
    return TLobby__sub_803FB358(status);
}

s32 NetLinkDisconnect(NetWaitParam *param) {
    NetLinkStatus status;
    s32 t;

    TLobby::lock_mutex(lbl_805C18A0.value);
    lbl_805D7A8C = 0;
    if (lbl_805D7A84 != 0) {
        lobby_modem_abort_flag = 1;
        lobby_modem_connect_state = 6;
    } else {
        lbl_805D7A88 = 0;
        lobby_modem_connect_state = 0;
    }
    TUdpSocket::unlock_mutex(((s32 *)&lbl_805C18A0)[0]);
    if (param == NULL || param->wait == 0) {
        return 0;
    }
    for (t = 0; t < 300000; t += 200) {
        TLobby__sub_803F97E8(200);
        TLobby__sub_803FB358(&status);
        if (status.state == 0) {
            return 0;
        }
    }
    return -1;
}

s32 NetLinkConnect(NetConnectCfg *cfg) {
    NetLinkStatus status;
    s32 t;

    if (cfg == NULL) {
        return -1;
    }
    if (NetApplyConnectionConfig((u8 *)cfg) < 0) {
        return -1;
    }
    if (cfg->wait == 0) {
        return 0;
    }
    for (t = 0; t < 300000; t += 200) {
        TLobby__sub_803F97E8(200);
        TLobby__sub_803FB358(&status);
        switch (status.state) {
        case 4:
            return 0;
        case 8:
            return -2;
        case 5:
            return -3;
        }
    }
    return -1;
}


/* PPP control-protocol automata at lbl_805C0038 + 4 + n * 0x34 (TLobby__sub_803FD85C resets all five);
   automaton 2 (0x6C) and 4 (0xD4) report "opened" (state 5) here. */
struct LcpOpts_803FB358 { u8 pad[8]; u32 w8; u32 wC; u8 pad10[8]; u32 w18; u32 w1C; u8 pad20[0x44]; u32 w64; u32 w68; };
struct IpcpOpts_803FB358 { u8 pad[8]; u32 addr[4]; };
struct Fsm_803FB358 { u8 state; u8 pad1[0x2F]; void *opts; };
struct Ppp_803FB358 { u8 pad[4]; Fsm_803FB358 fsm[5]; };
extern s32 lobby_modem_reply_value;
s16 TLobby__sub_803FB358(NetLinkStatus *status) {
    Ppp_803FB358 *ppp;
    Fsm_803FB358 *ipcp_fsm;
    IpcpOpts_803FB358 *ipcp;
    LcpOpts_803FB358 *lcp;
    u32 a;
    u32 b;

    TLobby::lock_mutex(lbl_805C18A0.value);
    ppp = (Ppp_803FB358 *)lbl_805C0038;
    ipcp_fsm = &ppp->fsm[4];
    ipcp = (IpcpOpts_803FB358 *)ipcp_fsm->opts;
    lcp = (LcpOpts_803FB358 *)ppp->fsm[2].opts;
    if (ppp->fsm[2].state == 5) {
        status->link_up = 1;
    } else {
        status->link_up = 0;
    }
    status->w10 = lcp->w8;
    status->w14 = lcp->wC;
    status->w18 = lcp->w18;
    status->w1C = lcp->w1C;
    status->w20 = lcp->w64;
    status->w24 = lcp->w68;
    if (ipcp_fsm->state == 5) {
        status->ppp_up = 1;
    } else {
        status->ppp_up = 0;
    }
    a = ipcp->addr[0];
    b = ipcp->addr[1];
    NetMemcpy(status->addr[0], &a, 4);
    NetMemcpy(status->addr[1], &b, 4);
    a = ipcp->addr[2];
    b = ipcp->addr[3];
    NetMemcpy(status->addr[2], &a, 4);
    NetMemcpy(status->addr[3], &b, 4);
    status->state = lobby_modem_connect_state;
    status->w8 = lobby_modem_reply_value;
    status->h6 = lbl_805D7A82;
    status->hC = lbl_805D7A84;
    TUdpSocket::unlock_mutex(lbl_805C18A0.value);
    return 0;
}
}

s16 NetApplyConnectionConfig(u8 *arg0) {
  u8 *g = (u8 *) &lbl_805BFF68;
  NetStoreTick((s32 *)(arg0 + 0x38));
  TLobby::lock_mutex((int)((void *) ((s32 *)&lbl_805C18A0)[0]));
  if (((s16) lbl_805D7A84) == 0)
  {
    *((u16 *) (((s8 *) g) + 0)) = (u16) (*((u16 *) (((s8 *) arg0) + 0)));
    *((s16 *) (((s8 *) g) + 2)) = (s16) (*((s16 *) (((s8 *) arg0) + 2)));
    lbl_805D7A7C = *((s16 *) (((s8 *) arg0) + 2));
    *((s16 *) (((s8 *) g) + 4)) = (s16) (*((s16 *) (((s8 *) arg0) + 4)));
    *((s32 *) (((s8 *) g) + 0xC)) = (s32) (*((s32 *) (((s8 *) arg0) + 8)));
    *((s32 *) (((s8 *) g) + 0x10)) = (s32) (*((s32 *) (((s8 *) arg0) + 0xC)));
    *((s32 *) (((s8 *) g) + 0x14)) = (s32) (*((s32 *) (((s8 *) arg0) + 0x10)));
    *((s32 *) (((s8 *) g) + 0x18)) = (s32) (*((s32 *) (((s8 *) arg0) + 0x14)));
    NetMemcpy(g + 0x7C, arg0 + 0x18, 0xA);
    NetMemcpy(g + 0x88, arg0 + 0x24, 0x10);
    NetMemcpy(g + 0x98, arg0 + 0x34, 0x10);
    if (((s16) (*((s16 *) (((s8 *) g) + 0x9A)))) == 0)
    {
      *((s16 *) (((s8 *) g) + 0x9A)) = (s16) (*((s16 *) (((s8 *) ((s32 *)&lobby_net_buffer_desc_b)) + 0x14)));
    }
    *((s32 *) (((s8 *) g) + 0xA8)) = (s32) (*((s32 *) (((s8 *) arg0) + 0x44)));
    *((s32 *) (((s8 *) g) + 0xAC)) = (s32) (*((s32 *) (((s8 *) arg0) + 0x48)));
    *((s32 *) (((s8 *) g) + 0xB0)) = (s32) (*((s32 *) (((s8 *) arg0) + 0x4C)));
    *((s32 *) (((s8 *) g) + 0xB4)) = (s32) (*((s32 *) (((s8 *) arg0) + 0x50)));
    *((s32 *) (((s8 *) g) + 0xB8)) = (s32) (*((s32 *) (((s8 *) arg0) + 0x54)));
    *((s32 *) (((s8 *) g) + 0xBC)) = (s32) (*((s32 *) (((s8 *) arg0) + 0x58)));
    NetMemcpy(g + 0xC0, arg0 + 0x5C, 8);
    NetMemcpy(g + 0xC8, arg0 + 0x64, 8);
    lbl_805D7A82 = 0;
    lobby_modem_connect_state = 1;
    lbl_805D7A88 = 1;
    lbl_805D7A90 = (s32) (*((u16 *) (((s8 *) g) + 0)));
    lbl_805D7A8C = *((s32 *) (((s8 *) g) + 0x18));
    if ((*((u16 *) (((s8 *) g) + 0))) & 4)
    {
      lbl_805D7A7A = 1;
    }
    else
    {
      lbl_805D7A7A = 0;
    }
  }
  TUdpSocket::unlock_mutex((int)((void *) ((s32 *)&lbl_805C18A0)[0]));
  return 0;
}
extern "C" {

s16 TLobby::get_remaining(s32 arg0) {
    return lbl_805D7A78 - arg0;
}

typedef char RecoveredGlobal_803FC178_lbl_805C02D0_size[sizeof(RecoveredGlobal_803FC178_lbl_805C02D0) == 0x40 ? 1 : -1];

struct G_803FB634 { u32 pad0; u32 pad4; u32 t8; };
s32 TLobby::is_timed_out() {
    G_803FB634 *g = (G_803FB634 *)&lbl_805BFF68;
    s32 now;
    TLobby::get_time_ms(&now);
    if (lobby_modem_connect_state == 5 || lobby_modem_abort_flag != 0 || (u32)(now - g->t8) > 60000) {
        return 1;
    }
    return 0;
}

extern "C" {

void TLobby__sub_803F8238(void);
void modem_run_script(u32, void *);
s32 TLobby__sub_804037F0(void);

struct Sess_803FB6A0 { u8 pad[0x22]; s16 h22; u8 pad2[0x3C]; u32 w60; u8 pad3[0x6C]; };
struct St_803FB6A0 { u8 busy; u8 pad[3]; u8 state; u8 rest[0x143]; };
struct Sock_803FB6A0 { s32 sock; s32 w4; s16 h8; u8 pad[6]; };

s32 TLobby__sub_803FB6A0(void) {
    St_803FB6A0 *st = (St_803FB6A0 *)lbl_805C0038;
    Sess_803FB6A0 *sess = (Sess_803FB6A0 *)&lbl_805BFF68;
    u8 *state = &st->state;
    update_connection_state__6TLobbyFi(state, &lbl_805BFF68);
    if (*state == 6) {
        while (st->busy != 0) {
            TUdpSocket::unlock_mutex(((Sock_803FB6A0 *)&lbl_805C18A0)->sock);
            TLobby::process_expired_timers();
            TLobby__sub_803F97E8(((Sock_803FB6A0 *)&lbl_805C18A0)->h8);
            TLobby::lock_mutex(((Sock_803FB6A0 *)&lbl_805C18A0)->sock);
        }
    }
    lobby_modem_abort_flag = 0;
    lobby_modem_connect_state = 7;
    TLobby__sub_804037F0();
    if (sess->h22 != 0 && sess->w60 != 0 && NetStringLength((const char*)sess->w60) != 0) {
        modem_run_script(sess->w60, sess);
    }
    if (lbl_805D7A7E != 0) {
        TLobby__sub_803F8238();
        lbl_805D7A7E = 0;
    }
    lbl_805D7A84 = 0;
    lbl_805D7A88 = 0;
    lobby_modem_abort_flag = 0;
    lobby_modem_connect_state = 0;
    return 0;
}

s16 TLobby__sub_80403D28(s32 arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4, s16 arg5, char *arg6, s16 arg7);
s32 TLobby__sub_803F7E50(s32 arg0, s32 arg1, s32 arg2, s32 n, s32 p);
u16 TLobby__sub_803F8090(void);
s16 TLobby__sub_80403C60(u8 *arg0);
s32 TLobby__sub_804038F4(s32 arg0, s32 arg1, s32 arg2);
s32 TLobby__sub_804039C8(s16 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6);
s16 TLobby__sub_80403BA8(u8 *arg0, u8 *arg1, s32 arg2);
s16 TLobby__sub_80403B04(u8 *arg0, u8 *arg1, s32 arg2);
s16 TLobby__sub_80403864(void);
extern s32 lbl_805D7A94;
extern s16 lbl_805D7A80;
extern s32 lbl_805D7AA0;
extern s32 lbl_805D7BD8;

/* Link parameters handed to TLobby__sub_80403C60 (built on the stack). */
struct LinkParams_803FB7A4 {
    s32 w0;
    u16 h4;
    u16 h6;
    u32 w8;
    u16 hC;
    u16 hE;
    u8 *w10;
    u8 *w14;
};

s32 TLobby__sub_803FB7A4(void) {
    LoginCfg_803FAEDC *cfg = (LoginCfg_803FAEDC *)&lbl_805BFF68;
    LinkParams_803FB7A4 params;
    s32 now;
    s32 start;
    u8 *conn;
    s16 i;
    s16 ok;
    u32 timeout;
    s16 ret;
    s16 auth;
    u16 proto;

    lbl_805D7A88 = 0;
    lobby_modem_connect_state = 2;
    TLobby::get_time_ms(&lbl_805D7A94);
    lbl_805D7A84 = 1;
    ret = TLobby__sub_80403D28(0, 0, cfg->h80, cfg->h7E, cfg->h7C, 1, cfg->w64, cfg->flags & 4);
    if (ret != 0 || lobby_modem_abort_flag != 0) {
        if (lobby_modem_abort_flag != 0) {
            lbl_805D7A82 = 13;
        } else {
            lbl_805D7A82 = 1;
        }
        lobby_modem_connect_state = 8;
        if (cfg->callback != NULL) {
            TUdpSocket::unlock_mutex(lbl_805C18A0.value);
            cfg->callback(lbl_805D7A82, 0);
            TLobby::lock_mutex(lbl_805C18A0.value);
        }
        return 0;
    }
    if (!(cfg->flags & 4)) {
        if (cfg->mode == 1) {
            ret = TLobby::send_atx_command_mode(0);
            if (ret != 0) {
                lbl_805D7A82 = 1;
                lobby_modem_connect_state = 8;
                if (cfg->callback != NULL) {
                    TUdpSocket::unlock_mutex(lbl_805C18A0.value);
                    cfg->callback(lbl_805D7A82, 0);
                    TLobby::lock_mutex(lbl_805C18A0.value);
                }
                return 0;
            }
        }
        if (cfg->h1C != 0) {
            ret = TLobby__sub_803F7E50(cfg->w68, cfg->w6C, cfg->w70, cfg->w74, cfg->w78);
        } else {
            ret = TLobby__sub_803F7E50(0, 0, 0, 0, 0);
        }
        if (ret != 0) {
            lbl_805D7A82 = 1;
            lobby_modem_connect_state = 8;
            if (cfg->callback != NULL) {
                TUdpSocket::unlock_mutex(lbl_805C18A0.value);
                cfg->callback(lbl_805D7A82, 0);
                TLobby::lock_mutex(lbl_805C18A0.value);
            }
            return 0;
        }
        if (cfg->flags & 2) {
            lobby_modem_connect_state = 10;
            goto wait_answer;
        }
        if (cfg->h1E != 0) {
            ret = TLobby__sub_803FAEDC(cfg);
            if (ret != 0) {
                lbl_805D7A82 = ret;
                lobby_modem_connect_state = 8;
                if (cfg->callback != NULL) {
                    TUdpSocket::unlock_mutex(lbl_805C18A0.value);
                    cfg->callback(lbl_805D7A82, 0);
                    TLobby::lock_mutex(lbl_805C18A0.value);
                }
                return 0;
            }
        }
    }
    if (cfg->h20 != 0) {
        timeout = cfg->h8C * 1000;
        TLobby::get_time_ms(&start);
        for (;;) {
            if (TLobby__sub_803F8090() != 0) {
                break;
            }
            if (!(cfg->flags & 4)) {
                ret = TLobby::map_state_to_mode_id();
                if (ret >= 0) {
                    if (ret != 0) {
                        lbl_805D7A82 = ret;
                        lobby_modem_connect_state = 8;
                        if (cfg->callback != NULL) {
                            TUdpSocket::unlock_mutex(lbl_805C18A0.value);
                            cfg->callback(lbl_805D7A82, 0);
                            TLobby::lock_mutex(lbl_805C18A0.value);
                        }
                        return 0;
                    }
                    break;
                }
            }
            TLobby::get_time_ms(&now);
            if ((ret = lobby_modem_abort_flag) != 0 || (u32)(now - start) > timeout) {
                if (ret != 0) {
                    lbl_805D7A82 = 13;
                } else {
                    lbl_805D7A82 = 12;
                }
                lobby_modem_connect_state = 8;
                if (cfg->callback != NULL) {
                    TUdpSocket::unlock_mutex(lbl_805C18A0.value);
                    cfg->callback(lbl_805D7A82, 0);
                    TLobby::lock_mutex(lbl_805C18A0.value);
                }
                return 0;
            }
            TUdpSocket::unlock_mutex(lbl_805C18A0.value);
            TLobby__sub_803F97E8(100);
            TLobby::lock_mutex(lbl_805C18A0.value);
        }
    }
wait_answer:
    if (cfg->flags & 2) {
        lobby_modem_connect_state = 10;
        while (lobby_modem_connect_state == 10) {
            TUdpSocket::unlock_mutex(lbl_805C18A0.value);
            TLobby__sub_803F97E8(100);
            TLobby::process_expired_timers();
            TLobby::lock_mutex(lbl_805C18A0.value);
        }
        if (lobby_modem_connect_state != 1) {
            if (cfg->callback != NULL) {
                TUdpSocket::unlock_mutex(lbl_805C18A0.value);
                lbl_805D7A82 = 1;
                cfg->callback(lbl_805D7A82, 0);
                TLobby::lock_mutex(lbl_805C18A0.value);
            }
            return 0;
        }
    }
    TUdpSocket::unlock_mutex(lbl_805C18A0.value);
    TLobby__sub_803F97E8(500);
    TLobby::lock_mutex(lbl_805C18A0.value);
    lobby_modem_connect_state = 3;
    lbl_805D7A80 = 0;
    TLobby::get_time_ms(&cfg->start_time);
    lbl_805D7A78 = 0;
    if (cfg->flags & 4) {
        params.w0 = -1;
        params.h4 = 1;
        auth = 1;
        params.hC = 1454;
        params.hE = 1;
    } else {
        params.w0 = 0xA0000;
        params.h4 = cfg->hA0;
        params.hC = cfg->h9A;
        params.hE = cfg->hA2;
        auth = cfg->hA4;
    }
    params.h6 = cfg->h98;
    params.w8 = cfg->w9C;
    params.w10 = cfg->wC;
    params.w14 = cfg->w10;
    if (TLobby__sub_80403C60((u8 *)&params) != 0) {
        lbl_805D7A82 = 5;
        lobby_modem_connect_state = 8;
        if (cfg->callback != NULL) {
            TUdpSocket::unlock_mutex(lbl_805C18A0.value);
            cfg->callback(lbl_805D7A82, 0);
            TLobby::lock_mutex(lbl_805C18A0.value);
        }
        return 0;
    }
    ret = cfg->h2;
    if (ret == 6 || ret == 0) {
        TLobby__sub_804038F4(0, (s32)cfg->C0, (s32)cfg->C8);
    }
    TLobby__sub_804039C8(auth, cfg->wA8, cfg->wAC, cfg->wB0, cfg->wB4, cfg->wB8, cfg->wBC);
    lbl_805D7AA0 = 0;
    ok = 0;
    switch (cfg->h98 & 0x7F) {
    default:
        ok = 1;
        break;
    case 0:
        if (TLobby__sub_80403BA8(cfg->wC, cfg->w10, 0x80) != 0) {
            if (cfg->callback != NULL) {
                TUdpSocket::unlock_mutex(lbl_805C18A0.value);
                cfg->callback(lbl_805D7A82, 0);
                TLobby::lock_mutex(lbl_805C18A0.value);
            }
            return 0;
        }
        ok = 1;
        break;
    case 2:
        if (TLobby__sub_80403B04(cfg->wC, cfg->w10, 0x82) != 0) {
            if (cfg->callback != NULL) {
                TUdpSocket::unlock_mutex(lbl_805C18A0.value);
                cfg->callback(lbl_805D7A82, 0);
                TLobby::lock_mutex(lbl_805C18A0.value);
            }
            return 0;
        }
        ok = 1;
        break;
    case 4:
        if (lbl_805D7A78 == 0) {
            ok = 1;
            break;
        }
        conn = lbl_805C0038 + 4;
        for (i = 0; i < 2; i++) {
            proto = lbl_805D7A78;
            if (proto == 0x80) {
                ret = TLobby__sub_80403BA8(cfg->wC, cfg->w10, proto);
                if (ret == 0) {
                    ok = 1;
                    break;
                }
                if (ret != -18) {
                    if (cfg->callback != NULL) {
                        TUdpSocket::unlock_mutex(lbl_805C18A0.value);
                        cfg->callback(lbl_805D7A82, 0);
                        TLobby::lock_mutex(lbl_805C18A0.value);
                    }
                    return 0;
                }
            } else if (proto == 0x82) {
                ret = TLobby__sub_80403B04(cfg->wC, cfg->w10, proto);
                if (ret == 0) {
                    ok = 1;
                    break;
                }
                if (ret != -18) {
                    if (cfg->callback != NULL) {
                        TUdpSocket::unlock_mutex(lbl_805C18A0.value);
                        cfg->callback(lbl_805D7A82, 0);
                        TLobby::lock_mutex(lbl_805C18A0.value);
                    }
                    return 0;
                }
            } else {
                lbl_805D7A82 = 6;
                lobby_modem_connect_state = 8;
                if (cfg->callback != NULL) {
                    TUdpSocket::unlock_mutex(lbl_805C18A0.value);
                    cfg->callback(lbl_805D7A82, 0);
                    TLobby::lock_mutex(lbl_805C18A0.value);
                }
                return 0;
            }
            if (TLobby::wait_for_connection(conn) != 0) {
                lbl_805D7A82 = 12;
                lobby_modem_connect_state = 8;
                if (cfg->callback != NULL) {
                    TUdpSocket::unlock_mutex(lbl_805C18A0.value);
                    cfg->callback(lbl_805D7A82, 0);
                    TLobby::lock_mutex(lbl_805C18A0.value);
                }
                return 0;
            }
        }
        break;
    }
    if (ok == 0) {
        lbl_805D7A82 = 6;
        lobby_modem_connect_state = 8;
        if (cfg->callback != NULL) {
            TUdpSocket::unlock_mutex(lbl_805C18A0.value);
            cfg->callback(lbl_805D7A82, 0);
            TLobby::lock_mutex(lbl_805C18A0.value);
        }
        return 0;
    }
    if (TLobby__sub_80403864() != 0) {
        lbl_805D7A82 = 7;
        lobby_modem_connect_state = 8;
        if (cfg->callback != NULL) {
            TUdpSocket::unlock_mutex(lbl_805C18A0.value);
            cfg->callback(lbl_805D7A82, 0);
            TLobby::lock_mutex(lbl_805C18A0.value);
        }
        return 0;
    }
    lobby_modem_connect_state = 4;
    if (cfg->callback != NULL) {
        TUdpSocket::unlock_mutex(lbl_805C18A0.value);
        cfg->callback(0, lbl_805D7BD8);
        TLobby::lock_mutex(lbl_805C18A0.value);
    }
    return 0;
}

}

void TLobby::set_ppp_auth_protocol(u16 v) {
    if (v == 0xC023) {
        lbl_805D7A78 = 0x80;
    } else if (v == 0xC223) {
        lbl_805D7A78 = 0x82;
    } else {
        lbl_805D7A78 = v;
    }
}

typedef char RecoveredGlobal_803FC1A0_lbl_805C02D0_size[sizeof(RecoveredGlobal_803FC1A0_lbl_805C02D0) == 0x40 ? 1 : -1];

s32 TLobby__sub_803FE8BC(u8 *, void *);
typedef struct Hdr_803FC4B4 { u8 type; u8 flag; s16 len; } Hdr_803FC4B4;
struct O_80400ACC;
void TLobby__sub_80400ACC(O_80400ACC *);
struct Outer_80401CAC;
void TLobby__sub_80401CAC(Outer_80401CAC *, u16);
s32 TLobby__sub_80405304(void *);

s32 TLobby__sub_803FC684(u8 *arg0, u8 *arg1, u8 *arg2);

typedef void (*Fn_803FD10C)(void);

typedef char RecoveredGlobal_803FD520_lbl_805C0310_size[sizeof(RecoveredGlobal_803FD520_lbl_805C0310) == 0x18 ? 1 : -1];

struct N_80405298;

#define self ((Self_803FD85C *)arg0)
void TLobby__sub_803FD85C(void *arg0);
#undef self

struct Self_803FDA68;
struct Tbl_803FDA68 {
    u8 pad[0x14];
    void (*f14)(Self_803FDA68 *, Tbl_803FDA68 *);
    u8 pad18[0xC];
    void (*f24)(Self_803FDA68 *, Tbl_803FDA68 *);
    void *(*f28)(Self_803FDA68 *, Tbl_803FDA68 *);
};
struct Self_803FDA68 {
    u8 f0; u8 f1; u8 f2; u8 f3; u8 f4; u8 f5; u8 f6; u8 f7;
    s16 f8; u8 padA[6];
    u8 f10[0x1C];
    Tbl_803FDA68 *tbl;
    void *f30;
};

struct V_803FE600;
struct O_803FE600 {
    u8 b0; u8 b1; u8 b2; u8 b3; u8 b4; u8 b5; u8 b6; u8 b7;
    u8 pad8[0x2C - 8];
    V_803FE600 *p2C;
};
struct V_803FE600 {
    u8 pad[0x14];
    void (*fn)(O_803FE600 *, V_803FE600 *);
};

s32 TLobby__sub_803FE8BC(u8 *dst, void *src);

struct O_80400ACC { u8 b0; u8 b1; u8 b2; u8 pad3[0x108 - 3]; s32 f108; };
void TLobby__sub_80400ACC(O_80400ACC *o);

typedef char RecoveredGlobal_80401A68_lbl_805C04A8_size[sizeof(RecoveredGlobal_80401A68_lbl_805C04A8) == 0x30 ? 1 : -1];

#define rd16_804012E0(src) (TLobby__sub_80401BCC(src, lcp_read_value_buffer, 2) != 2 ? -1 : read_network_u16_be(lcp_read_value_buffer))
#define rd32_804012E0(src) (TLobby__sub_80401BCC(src, lcp_read_value_buffer, 4) != 4 ? 0 : TLobby__sub_80402AFC(lcp_read_value_buffer))
#define rd8_804012E0(src) (TLobby__sub_80401BCC(src, lobby_read_byte_buffer, 1) != 1 ? -1 : (s16)lobby_read_byte_buffer[0])
#define F(t, o) (*(t *)(arg2 + (o)))

typedef char RecoveredGlobal_80401A90_lbl_805C04A8_size[sizeof(RecoveredGlobal_80401A90_lbl_805C04A8) == 0x30 ? 1 : -1];

#pragma opt_propagation off
#pragma opt_propagation reset

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
#define FF_80401FE8(a, b, c, d, x, s, ac) { (a) += F_80401FE8((b), (c), (d)) + (x) + ac; (a) = ROTATE_LEFT_80401FE8((a), (s)); (a) += (b); }
#define GG_80401FE8(a, b, c, d, x, s, ac) { (a) += G_80401FE8((b), (c), (d)) + (x) + ac; (a) = ROTATE_LEFT_80401FE8((a), (s)); (a) += (b); }
#define HH_80401FE8(a, b, c, d, x, s, ac) { (a) += H_80401FE8((b), (c), (d)) + (x) + ac; (a) = ROTATE_LEFT_80401FE8((a), (s)); (a) += (b); }
#define II_80401FE8(a, b, c, d, x, s, ac) { (a) += I_80401FE8((b), (c), (d)) + (x) + ac; (a) = ROTATE_LEFT_80401FE8((a), (s)); (a) += (b); }
#pragma push
#pragma dont_inline off
#pragma inline_depth(4)
#pragma opt_common_subs on
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

typedef char RecoveredGlobal_80402B88_lbl_805C0620_size[sizeof(RecoveredGlobal_80402B88_lbl_805C0620) == 0x18 ? 1 : -1];

typedef char RecoveredGlobal_804050DC_lbl_805C18A0_size[sizeof(RecoveredGlobal_804050DC_lbl_805C18A0) == 0x10 ? 1 : -1];

typedef char RecoveredGlobal_80403D28_lbl_805C0638_size[sizeof(RecoveredGlobal_80403D28_lbl_805C0638) == 0xA0 ? 1 : -1];

#pragma push
#pragma opt_common_subs on
#pragma pop

typedef struct A_80403F4C {
    u8 pad0[0x16];
    u8 count;
    u8 pad17[0x40 - 0x17];
} A_80403F4C;

typedef struct B_80403F4C {
    u8 bytes[0x44];
} B_80403F4C;

typedef struct Ent_80403F4C {
    u8 pad0[8];
    A_80403F4C a;
    B_80403F4C b;
} Ent_80403F4C;

typedef struct Obj_80403F4C {
    u8 pad0[4];
    Ent_80403F4C *ents;
    u8 pad8;
    u8 max;
    u8 padA[2];
    u8 cur;
    u8 flags;
    u8 padE[0x28 - 0xE];
    s32 n28;
    u8 pad2C[4];
    s32 n30;
} Obj_80403F4C;

#define o ((Obj_80403F4C *)ov)
#define pp ((u8 **)spp)
s16 TLobby__sub_80403F4C(void *ov, Strm_80405A74 **spp);
#undef o
#undef pp

typedef char RecoveredGlobal_804050EC_lbl_805C18A0_size[sizeof(RecoveredGlobal_804050EC_lbl_805C18A0) == 0x10 ? 1 : -1];

typedef char RecoveredGlobal_80405114_lbl_805C18A0_size[sizeof(RecoveredGlobal_80405114_lbl_805C18A0) == 0x10 ? 1 : -1];

s32 TLobby__sub_803FB6A0(void);

typedef struct Timer_804051CC {
    struct Timer_804051CC *next;
    u8 pad4[4];
    u32 f8;
    s32 fC;
    void (*f10)(s32);
    s32 f14;
    u8 f18;
} Timer_804051CC;

struct N_80405298 { N_80405298 *next; s32 f4; u8 pad8[0x18 - 8]; u8 b18; };
#define HEAD_80405298 (*(N_80405298 **)&lobby_timer_list_head)

typedef struct Lobby_804062A0 {
    u8 state;
    u8 pad[3];
    u8 sub[0x140];
} Lobby_804062A0;

struct RecoveredFields_80401B8C_arg0;
struct Self_8040098C;
#pragma dont_inline off
#pragma inline_depth(4)
#define FWD_80405A74()                                                       \
    (*(G + 0x13A))++;                                            \
    t = (Strm_80405A74 *)((TLobby *)arg0)->alloc_from_buffer(4); \
    p = t->p;                                                                \
    *p++ = 0xFF;                                                             \
    *p++ = 3;                                                                \
    write_network_u16_be(p, code);                                           \
    u = t;                                                                   \
    if (u == NULL) {                                                         \
        (*(G + 0x142))++;                                        \
        return;                                                              \
    }                                                                        \
    if (TLobby__sub_80401BCC(&u, &lobby_ppp_read_buf, 2) == 2) {                   \
        read_network_u16_be(&lobby_ppp_read_buf);                                 \
    }                                                                        \
    TLobby__sub_803FE6CC(G + 4, 8, 0, u);                                    \
    return;

s32 TLobby__sub_804062A0(s16 arg0);

typedef struct Ent_80407418 {
    s16 active;
    s16 a;
    s16 pad4;
    s16 b;
    u8 pad8[0x18];
} Ent_80407418;

typedef struct Tbl_80407418 {
    s16 pad0;
    s16 count;
    u8 pad4[0x10];
    Ent_80407418 *ents;
} Tbl_80407418;

s32 TLobby__sub_80408388(s16);

struct Conn_8040799C { s32 a; s16 f4; s16 f6; };
struct Peer_8040799C { s16 st; s16 f2; u8 pad4; u8 f5; u8 pad6[2]; Conn_8040799C *conn; u8 addr[6]; u8 name[6]; };
struct Ent_8040799C { s16 f0; s16 f2; s16 f4; s16 f6; u8 pad8[6]; u8 fE; u8 fF; u8 pad10[2]; u8 a12[6]; u8 a18[8]; };
struct Tbl_8040799C { s16 count; s16 h2; s16 h4; s16 h6; s16 h8; s16 hA; s16 hC; u8 padE[2]; Peer_8040799C *list; Ent_8040799C *ents; };
struct Ent_80408428;
struct Ent_80408428 *find_or_add_peer_entry__6TLobbyFsiUcPvUcPvs(s16, s32, u8, void *, u8, void *, s16);

#define TBL ((Tbl_8040799C *)&lbl_805C1AB0)

#pragma push
#pragma dont_inline off
#pragma inline_depth(4)

s32 TLobby__sub_8040799C(s16 arg0, void *arg1, void *arg2);
#pragma pop
#undef TBL

typedef struct Node_804082AC { struct Node_804082AC *next; u8 pad4[2]; u8 f6[0x10]; } Node_804082AC;
typedef struct Ent_804082AC { u8 pad0[0xE]; u8 fE; u8 fF; u8 pad10[2]; u8 f12[6]; u8 f18[4]; Node_804082AC *f1C; } Ent_804082AC;
typedef struct Key_804082AC { u8 pad0[0x10]; void *f10; } Key_804082AC;
typedef struct Pool_804082AC { u8 pad0[8]; s16 f8; } Pool_804082AC;

typedef struct Node_80408388 {
    struct Node_80408388 *next;
    s16 used;
} Node_80408388;

typedef struct Ent_80408388 {
    u8 pad[0x1C];
    Node_80408388 *head;
} Ent_80408388;

typedef struct Tbl_80408388 {
    s16 pad0;
    s16 count;
    u8 pad4[0x10];
    Ent_80408388 *ents;
} Tbl_80408388;

s32 TLobby__sub_80408388(s16 id);

typedef struct Sub_80408428 {
    s32 f0;
    s16 f4;
    s16 f6;
    u8 pad8[4];
    s32 fC;
} Sub_80408428;

typedef struct Ent_80408428 {
    s16 state;
    s16 stamp;
    u8 type4;
    u8 type5;
    u8 pad6[2];
    Sub_80408428 *sub;
    u8 addrC[6];
    u8 addr12[6];
} Ent_80408428;

typedef struct Tbl_80408428 {
    s16 count;
    u8 pad2[8];
    s16 stampA;
    u8 padC[4];
    Ent_80408428 *list;
} Tbl_80408428;

typedef struct Pkt_80408428 {
    u8 pad0[4];
    s32 f4;
    s32 f8;
    s16 fC;
    u8 padE[2];
    u8 f10[4];
} Pkt_80408428;

struct Ent_804086B4;

#pragma push
#pragma inline_depth(4)
#pragma dont_inline off

Ent_80408428 *find_or_add_peer_entry__6TLobbyFsiUcPvUcPvs(s16 arg0, s32 arg1, u8 type, void *addr, u8 type2, void *addr2, s16 state);

#pragma pop
struct Ent_804086B4 { s16 f0; s16 f2; u8 pad[0x14]; };

typedef s32 (*SendFn_80408C24)(s16, u8 *, s16);

struct Tbl_80408F2C;

#pragma push
#pragma dont_inline off
#pragma inline_depth(4)

#pragma pop

typedef char RecoveredGlobal_80409A3C_lbl_805C1C50_size[sizeof(RecoveredGlobal_80409A3C_lbl_805C1C50) == 0xF8 ? 1 : -1];

typedef struct Buf_80408F2C {
    s16 h0;
    s16 h2;
    s16 h4;
    s16 h6;
    s16 h8;
    u8 data[0x5EE];
} Buf_80408F2C;

typedef struct Tbl_80408F2C {
    u8 pad0[4];
    s16 count;
    s16 nbufs;
    u8 pad8[0xC];
    Buf_80408F2C *bufs;
} Tbl_80408F2C;

typedef struct Sock_80409130 { s16 f0; u8 pad2[4]; u16 f6; s16 f8; u8 padA[6]; } Sock_80409130;

#define TBL_804099B4 (*(Tbl_804099B4 *)&lobby_handler_table_desc)

#define TBL_80409B48 (*(Tbl_80409B48 *)&lobby_handler_table_desc)

#define TBL_80409BD4 (*(Tbl_80409BD4 *)&lobby_handler_table_desc)

typedef struct Ent_80409C5C {
    s16 active;
    s16 flags;
    u8 pad[0x20];
    s32 (*fn)(s32, s32);
    u8 pad2[0x8];
} Ent_80409C5C;

typedef struct Tbl_80409C5C {
    s16 count;
    Ent_80409C5C *ents;
} Tbl_80409C5C;

#define TBL_80409C5C (*(Tbl_80409C5C *)&lobby_handler_table_desc)

typedef struct Ent_80409CE0 {
    s16 active;
    s16 flags;
    u8 pad[0x1C];
    s32 (*fn)(s32, s32, s32);
    u8 pad2[0xC];
} Ent_80409CE0;

typedef struct Tbl_80409CE0 {
    s16 count;
    Ent_80409CE0 *ents;
} Tbl_80409CE0;

#define TBL_80409CE0 (*(Tbl_80409CE0 *)&lobby_handler_table_desc)

typedef struct Ent_80409D7C {
    s16 active;
    s16 flags;
    u8 pad[0x18];
    s32 (*fn)(s32, s32, s32);
    u8 pad2[0x10];
} Ent_80409D7C;

typedef struct Tbl_80409D7C {
    s16 count;
    Ent_80409D7C *ents;
} Tbl_80409D7C;

#define TBL_80409D7C (*(Tbl_80409D7C *)&lobby_handler_table_desc)

typedef struct Ent_80409E18 {
    s16 active;
    s16 flags;
    u8 pad[0x14];
    s32 (*fn)(s32, s32);
    u8 pad2[0x14];
} Ent_80409E18;

typedef struct Tbl_80409E18 {
    s16 count;
    Ent_80409E18 *ents;
} Tbl_80409E18;

#define TBL_80409E18 (*(Tbl_80409E18 *)&lobby_handler_table_desc)

typedef struct Ent_80409EB0 {
    s16 active;
    s16 flags;
    u8 pad[0x10];
    s32 (*fn)(s32);
    u8 pad2[0x18];
} Ent_80409EB0;

typedef struct Tbl_80409EB0 {
    s16 count;
    Ent_80409EB0 *ents;
} Tbl_80409EB0;

#define TBL_80409EB0 (*(Tbl_80409EB0 *)&lobby_handler_table_desc)

typedef struct Ent_8040A3C0 {
    s16 active;
    u8 pad[0x3A];
} Ent_8040A3C0;

typedef struct Mgr_8040A3C0 {
    u8 pad[0x40];
    s16 count;
    u8 pad42[2];
    Ent_8040A3C0 *ents;
} Mgr_8040A3C0;

typedef struct Rec_8040AD64 {
    u32 used;
    u8 pad[0x10];
} Rec_8040AD64;

typedef struct Mgr_8040AD64 {
    u8 pad[0x10];
    s16 n;
    u8 pad12[2];
    Rec_8040AD64 *recs;
    s16 f18;
} Mgr_8040AD64;

typedef struct Conn_8040AF48 {
    s16 state;
    u8 pad[0x16];
    s32 timer;
    u8 pad1C[0x100];
} Conn_8040AF48;

typedef struct Mgr_8040AF48 {
    u8 pad[0x30];
    s16 nconns;
    u8 pad32[0xA];
    Conn_8040AF48 *conns;
} Mgr_8040AF48;

#pragma push
#pragma opt_propagation off
#pragma pop

#pragma push
#pragma opt_propagation off
#pragma pop

#pragma dont_inline off
#pragma inline_depth(4)

typedef void (*CbA_8040C540)(s16, s32, s16, s32, s16);
typedef void (*CbB_8040C540)(s16, u32, s16);

typedef char RecoveredGlobal_8040EF00_lbl_805C1B60_size[sizeof(RecoveredGlobal_8040EF00_lbl_805C1B60) == 0x18 ? 1 : -1];

typedef char RecoveredGlobal_8040DD68_lbl_805C1B38_size[sizeof(RecoveredGlobal_8040DD68_lbl_805C1B38) == 0x28 ? 1 : -1];

typedef void (*Handler_8041A130)(s32, s16, s16, s16);

typedef char RecoveredGlobal_8040ED28_lbl_805C1B60_size[sizeof(RecoveredGlobal_8040ED28_lbl_805C1B60) == 0x18 ? 1 : -1];

typedef char RecoveredGlobal_8040ED70_lbl_805C1B60_size[sizeof(RecoveredGlobal_8040ED70_lbl_805C1B60) == 0x18 ? 1 : -1];

#pragma push
#pragma opt_common_subs on
#pragma pop

s16 TLobby__sub_8040FCEC(u32 ip);

s32 TLobby__sub_8040FDA0(u32 arg0, s16 arg1);
}

typedef char RecoveredGlobal_8040FE40_lbl_805C1B60_size[sizeof(RecoveredGlobal_8040FE40_lbl_805C1B60) == 0x18 ? 1 : -1];

typedef char RecoveredGlobal_8040FE9C_lbl_805C1B60_size[sizeof(RecoveredGlobal_8040FE9C_lbl_805C1B60) == 0x18 ? 1 : -1];

#pragma push
#pragma opt_common_subs on
#pragma pop

#pragma push
#pragma opt_common_subs on
#pragma pop

typedef char RecoveredGlobal_8041123C_lbl_805C1BB8_size[sizeof(RecoveredGlobal_8041123C_lbl_805C1BB8) == 0x28 ? 1 : -1];

typedef char RecoveredGlobal_804112B8_lbl_805C1BB8_size[sizeof(RecoveredGlobal_804112B8_lbl_805C1BB8) == 0x28 ? 1 : -1];

typedef char RecoveredGlobal_80411ECC_lbl_805C1BB8_size[sizeof(RecoveredGlobal_80411ECC_lbl_805C1BB8) == 0x28 ? 1 : -1];

typedef char RecoveredGlobal_8040FF0C_lbl_805C1B78_size[sizeof(RecoveredGlobal_8040FF0C_lbl_805C1B78) == 0x40 ? 1 : -1];

#pragma push
#pragma opt_common_subs on

struct G_8041118C {
    s16 n0; s16 n1; s16 n2; u8 pad6[0xE]; s16 n14; u8 pad16[2];
    void *p18; void *p1C; void *p20; void *p24;
};

#define g ((G_8041118C *)&ipv6_address_routing_state)
#undef g

#pragma pop

#pragma push
#pragma opt_common_subs on
#pragma pop

#pragma push
#pragma opt_common_subs on

#pragma pop

typedef char RecoveredGlobal_8041471C_lbl_805C1BB8_size[sizeof(RecoveredGlobal_8041471C_lbl_805C1BB8) == 0x28 ? 1 : -1];

struct RecoveredFields_804143BC_arg0 {
    u8 field_0;
    u8 field_1;
};
typedef char RecoveredFields_804143BC_arg0_0_offset[offsetof(RecoveredFields_804143BC_arg0, field_0) == 0x0 ? 1 : -1];
typedef char RecoveredFields_804143BC_arg0_1_offset[offsetof(RecoveredFields_804143BC_arg0, field_1) == 0x1 ? 1 : -1];
#pragma push
#pragma scheduling off
#pragma pop

#pragma push
#pragma opt_common_subs on
#pragma pop

typedef char RecoveredGlobal_8041552C_lbl_805C1BE0_size[sizeof(RecoveredGlobal_8041552C_lbl_805C1BE0) == 0x18 ? 1 : -1];

typedef char RecoveredGlobal_80415650_lbl_805C1BF8_size[sizeof(RecoveredGlobal_80415650_lbl_805C1BF8) == 0x10 ? 1 : -1];

typedef struct Ent_80418670 { u8 pad0[3]; u8 f3; u8 pad4[2]; s16 f6; u8 pad8[0xC]; u8 f14[0x10]; } Ent_80418670;

typedef struct Sub_804162A4 { u8 pad0[3]; u8 state; s16 count; } Sub_804162A4;
typedef struct Ent_804162A4 {
    u8 pad0[3];
    u8 state;
    s16 phase;
    u8 pad6[2];
    s16 id;
    s16 timer;
    u8 flags;
    u8 padD[3];
    Sub_804162A4 *sub;
    s16 tries;
    u8 name[0x10];
    s16 f26;
    u8 pad28[0x20];
} Ent_804162A4;
typedef struct Glob_804162A4 {
    u8 pad0[2];
    s16 count;
    u8 pad4[8];
    Ent_804162A4 *ents;
    u8 pad10[0xC];
    s16 maxTries0;
    s16 maxTries1;
    u8 pad20[4];
    s16 delay1;
    u8 pad26[2];
    s16 delay;
} Glob_804162A4;
typedef struct Arg_804162A4 { u8 *p; s32 v; } Arg_804162A4;

typedef struct Ent_80416678 { u8 pad0[0xC]; u8 fC; } Ent_80416678;

#pragma push
#pragma dont_inline off
#pragma inline_depth(4)

#pragma pop

typedef struct Hdr_804177A0 {
    s16 len;
    u8 pad[2];
    u8 data[8];
} Hdr_804177A0;

typedef struct Arg_80417D1C { u8 *p; s32 v; } Arg_80417D1C;

typedef struct Arg_80417E60 { u8 *p; s32 v; } Arg_80417E60;

typedef struct G_80418670 { u8 pad0[4]; s16 f4; u8 pad6[0xA]; Ent_80418670 *f10; } G_80418670;

#pragma push
#pragma dont_inline off
#pragma inline_depth(4)

#pragma pop

typedef char RecoveredGlobal_80419A00_lbl_805C1C50_size[sizeof(RecoveredGlobal_80419A00_lbl_805C1C50) == 0xF8 ? 1 : -1];

typedef char RecoveredGlobal_80419A34_lbl_805C1C50_size[sizeof(RecoveredGlobal_80419A34_lbl_805C1C50) == 0xF8 ? 1 : -1];

#pragma push
#pragma opt_common_subs on
typedef char RecoveredGlobal_80419A7C_lbl_805C1C50_size[sizeof(RecoveredGlobal_80419A7C_lbl_805C1C50) == 0xF8 ? 1 : -1];
#pragma pop

#pragma push
#pragma opt_propagation off
#pragma pop

#pragma push
#pragma opt_propagation off
#pragma pop

typedef char RecoveredGlobal_8041E178_lbl_805C1D48_size[sizeof(RecoveredGlobal_8041E178_lbl_805C1D48) == 0xA8 ? 1 : -1];

#pragma push
#pragma opt_propagation off
#pragma pop

#pragma push
#pragma opt_propagation off
#pragma pop
