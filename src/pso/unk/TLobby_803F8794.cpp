#include "types.h"
#include "pso/unk/TLobby.h"
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

struct Ent_803F8D84 { s32 active; s32 unk4; u32 key; };

struct Inner_80401CAC { u8 pad[4]; u16 f4; };

struct Outer_80401CAC { Inner_80401CAC *p; };

struct Ent_80408718 { s16 f0; u8 pad[0x16]; };

struct Tbl_80408718 { s16 count; s16 h2; s16 h4; s16 h6; s16 h8; u8 pad[4]; Ent_80408718 *list; };

struct Ent_803F8DBC { s32 active; s32 size; s32 val; };

struct Ent_803F9B48 { s32 active; u32 key; u8 pad[0x328 - 8]; };

struct Cfg_803F87E0 { s32 w[10]; };

struct Obj_803F87E0 {
    s16 x0;
    u8 pad2[2];
    void *x4;
    u8 pad8[4];
    s16 xc;
    u8 pade[2];
    s32 x10;
    s8 x14;
    u8 pad15[3];
    Cfg_803F87E0 cfg;
};

struct Big_803F8AD8 {
    u8 pad0[0xB7A0];
    u8 bufB7A0[0x2FC0];
    u8 bufE760[0x30];
    u8 bufE790[0x10];
    void *funcs[7];
};

struct Desc_803F8AD8 {
    s16 a;
    s16 b;
    s16 c;
    s16 d;
    void *funcs;
    void *x;
    void *y;
    void *z;
};

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

struct Ent_803F8BA4 { u8 pad[0x31C]; s32 size; u8 *buf; u8 pad2[4]; };

struct H_803F8BA4 {
    s16 a;
    s16 b;
    u16 n1;
    u16 n2;
    s32 c;
    s32 d;
    s32 e;
    u32 f;
    u32 g;
};

struct Strm_80405A74 { u8 *p; u16 len; };

typedef struct B_803FADA0 { u8 *buf; u16 len; } B_803FADA0;

typedef struct A_803FADA0 { u8 pad0[4]; u32 a; u32 b; } A_803FADA0;

struct Cfg_803F8868 {
    s16 a0, a2, a4, a6, a8, aA, aC, aE, a10, a12, a14, a16;
    u8 *p18;
    u8 *p1C;
    u8 *p20;
    u8 *p24;
};

extern "C" {
void TLobby__sub_803F8AA0(u8 *arg0);
void TLobby__sub_803F8A0C(u8 *arg0);
void TLobby__sub_803F89A4(u8 *arg0);
void TLobby__sub_803F8AB8(void);
s32 NetMemcmp(void *, void *, int);
void NetMemset(void *, int, int);
void NetMemcpy(void *, void *, int);
void TLobby__sub_803FD85C(void *);
s32 TLobby__sub_804062A0(s16);
extern s32 lobby_timer_list_head;
void TLobby__sub_803F8A08(void *);
s32 TLobby__sub_8040799C(s16, void *, void *);
void TLobby__sub_803F8A9C(void *);
extern s16 lobby_handler_table_desc;
s32 NetMemcmp(void * _w0, void * _w1, int _w2);
s32 TLobby__sub_8040FDA0(u32, s16);
extern RecoveredGlobal_8041123C_lbl_805C1BB8 ipv6_address_routing_state;
void NetMemset(void * _w0, int _w1, int _w2);
void TLobby__sub_803F8930(u8 *arg0);
s32 lobby_net_recv_desc_up_cell;
s32 TLobby__sub_803FE6CC(void *, int, int, void *);
s16 TLobby__sub_8040FCEC(u32);
void TLobby__sub_803F892C(void *);
void TLobby__sub_803F8958(void *);
void TLobby__sub_803F87DC(void *);
void TLobby__sub_803F89D8(void *);
extern u16 lobby_entry_pool_count;
extern Ent_803F8D84 *lobby_entry_pool_base;
void TLobby__sub_803F8D84(u32 key);
s32 TLobby__sub_803F8D24(H_803F8BA4 *h);
void TLobby__sub_80401CAC(Outer_80401CAC *o, u16 v);
u16 read_network_u16_be(u8 *p);
u32 TLobby__sub_80402AFC(u8 *p);
u8 *write_network_u16_be(u8 *p, u16 v);
extern Tbl_80408718 lbl_805C1AB0;
s32 TLobby__sub_80405304(void *arg0);
extern u16 lobby_thread_pool_count;
extern Ent_803F9B48 *lobby_thread_pool_base;
s32 TLobby__sub_80426B88(s16 arg0);
void NetMemcpy(void * _w0, void * _w1, int _w2);
s32 TLobby__sub_803FC684(u8 *, u8 *, u8 *);
extern u8 *lobby_buffer_pool_base;
extern u8 *lobby_second_buffer_pool_base;
extern u32 lobby_buffer_pool_size;
extern u8 *lobby_g_pool_base;
extern u32 lobby_g_pool_size;
s16 TLobby__sub_80401BCC(void *, void *, int);
extern u8 lcp_read_value_buffer[4];
extern u8 lobby_read_byte_buffer[1];
s16 TLobby__sub_80403F4C(void *, Strm_80405A74 **);
extern u8 lobby_ppp_read_buf;
void TLobby__sub_803F8794(void *);
void TLobby__sub_803F87C4(void);
void TLobby__sub_803F87C8(u8 *arg0);
void TLobby__sub_803F8864(void *);
void TLobby__sub_803F88E0(void *);
void TLobby__sub_803F89A0(void *);
void TLobby__sub_803F8A24(void *);
void TLobby__sub_803F8B78(void);

u32 lobby_net_config_block[4722];
u32 ipv6_interface_config[10];
u32 lbl_805B38A0[13];
u32 lbl_805B38D4[50];
u32 lbl_805B399C[99];
u32 lbl_805B3B28[36];
u32 lbl_805B3BB8[1267];
u32 lbl_805B4F84[212];
u32 lbl_805B52D4[96];
u32 lbl_805B5454[26];
u32 lbl_805B54BC[4096];
u32 lbl_805B94BC[30];
u32 lbl_805B9534[1059];
u32 lbl_805BA5C0[3115];
u32 lobby_net_recv_desc[641];
#define lobby_net_config_block (*(RecoveredGlobal_803F895C_lbl_805AEEB0 *)lobby_net_config_block)
#define ipv6_interface_config (*(Cfg_803F87E0 *)ipv6_interface_config)
#define lbl_805B38A0 ((u8 *)lbl_805B38A0)
#define lbl_805B4F84 (*(RecoveredGlobal_803F8930_lbl_805B4F84 *)lbl_805B4F84)
#define lbl_805B52D4 (*(RecoveredGlobal_803F89A4_lbl_805B52D4 *)lbl_805B52D4)
#define lbl_805B5454 (*(RecoveredGlobal_803F89A4_lbl_805B5454 *)lbl_805B5454)
#define lbl_805B54BC (*(RecoveredGlobal_803F89DC_lbl_805B54BC *)lbl_805B54BC)
#define lbl_805B94BC (*(RecoveredGlobal_803F89DC_lbl_805B94BC *)lbl_805B94BC)
#define lbl_805B9534 (*(RecoveredGlobal_803F8A0C_lbl_805B9534 *)lbl_805B9534)
#define lbl_805BA5C0 (*(RecoveredGlobal_803F8AA0_lbl_805BA5C0 *)lbl_805BA5C0)
#define lobby_net_recv_desc (*(RecoveredGlobal_803F8B7C_lbl_805BD66C *)lobby_net_recv_desc)

void TLobby__sub_803F8794(void *) {

}

extern s16 net_param_room_count;
extern s32 lbl_805D4800;
extern s32 net_transport_buffer_ptr_b;

void TLobby::init_params() {
    u8 *arg0 = (u8 *)this;
    *(s16 *)&this->m_flags = (s16) net_param_room_count;
    *(s32 *)&this->m_prev = (s32) lbl_805D4800;
    *(s32 *)&this->m_next = (s32) lbl_805D4800;
    *(s16 *)((s8 *)arg0 + 0xA0) = 0x64;
    *(s32 *)&this->m_name = (s32) net_transport_buffer_ptr_b;
}

void TLobby__sub_803F87C4(void) {

}

extern s16 net_param_player_count;
extern s32 net_transport_buffer_ptr_a;

void TLobby__sub_803F87C8(u8 *arg0) {
    *(s16 *)((s8 *)arg0 + 0) = (s16) net_param_player_count;
    *(s32 *)((s8 *)arg0 + 8) = (s32) net_transport_buffer_ptr_a;
}

void TLobby__sub_803F87DC(void * _w0) {

}

void TLobby::init_ipv6_interface_config() {
    Obj_803F87E0 *arg0 = (Obj_803F87E0 *)this;
    arg0->x0 = 1;
    arg0->xc = 0;
    arg0->x10 = 0;
    arg0->x14 = 0x40;
    arg0->x4 = lbl_805B38A0;
    arg0->cfg = ipv6_interface_config;
}

void TLobby__sub_803F8864(void *) {

}

void TLobby::init_udp_socket_config() {
    Cfg_803F8868 *o = (Cfg_803F8868 *)this;
    o->a0 = 0x1A;
    o->a2 = 3;
    o->a4 = 9;
    o->a14 = 9;
    o->a6 = 1;
    o->aA = 1;
    o->a8 = 1;
    o->aC = 1;
    o->a10 = 1;
    o->aE = 2;
    o->a16 = 0x1E;
    o->a12 = 0x500;
    o->p18 = (u8 *)lbl_805B3BB8;
    o->p1C = (u8 *)lbl_805B3B28;
    o->p20 = (u8 *)lbl_805B399C;
    o->p24 = (u8 *)lbl_805B38D4;
}

void TLobby__sub_803F88E0(void *) {

}

typedef struct RecoveredFields_803F88E4_arg0 RecoveredFields_803F88E4_arg0;
typedef struct RecoveredGlobal_803F88E4_lbl_805AEEB0 RecoveredGlobal_803F88E4_lbl_805AEEB0;
typedef char RecoveredGlobal_803F88E4_lbl_805AEEB0_size[((sizeof(RecoveredGlobal_803F88E4_lbl_805AEEB0)) == 0x49C8) ? (1) : (-1)];
void TLobby::init_buffer_descriptor_b() {
    RecoveredFields_803F88E4_arg0 *arg0 = (RecoveredFields_803F88E4_arg0 *)this;
  u8 *new_var;
  arg0->field_0 = 2;
  new_var = (u8 *) (&(*(RecoveredGlobal_803F88E4_lbl_805AEEB0 *)&lobby_net_config_block).value);
  arg0->field_2 = 8;
  arg0->field_4 = 8;
  arg0->field_14 = 0x5DC;
  arg0->field_8 = new_var + 0x6064;
  arg0->field_C = new_var + 0x5E24;
  arg0->field_10 = new_var + 0x5D04;
  arg0->field_18 = ((u8 *) (&(*(RecoveredGlobal_803F88E4_lbl_805AEEB0 *)&lobby_net_config_block).value)) + 0x514C;
}

void TLobby__sub_803F892C(void * _w0) {

}

#pragma push
#pragma opt_common_subs on
typedef char RecoveredGlobal_803F8930_lbl_805B4F84_size[sizeof(RecoveredGlobal_803F8930_lbl_805B4F84) == 0x350 ? 1 : -1];
void TLobby__sub_803F8930(u8 *arg0) {
    *(s16 *)((s8 *)arg0 + 0) = 1;
    *(s8 *)((s8 *)arg0 + 0xA) = 0;
    *(s8 *)((s8 *)arg0 + 0xB) = 0x78;
    *(s32 **)((s8 *)arg0 + 4) = &lbl_805B4F84.value;
}
#pragma pop

void TLobby__sub_803F8958(void * _w0) {

}

typedef char RecoveredGlobal_803F895C_lbl_805AEEB0_size[sizeof(RecoveredGlobal_803F895C_lbl_805AEEB0) == 0x49C8 ? 1 : -1];
void TLobby::init_buffer_descriptor_a() {
    u8 *arg0 = (u8 *)this;
    struct Fields_arg0 { s16 field_0; s16 field_2; s16 field_4; s16 field_6; u8 * field_8; u8 * field_C; u8 * field_10; };
    ((Fields_arg0*)arg0)->field_0 = 0x1A;
    ((Fields_arg0*)arg0)->field_2 = 3;
    ((Fields_arg0*)arg0)->field_4 = 9;
    ((Fields_arg0*)arg0)->field_6 = 0x240;
    ((Fields_arg0*)arg0)->field_8 = (unsigned char *) ((void *) ((u8 *)&lobby_net_config_block.value + 0x621C));
    ((Fields_arg0*)arg0)->field_C = (unsigned char *) ((void *) ((u8 *)&lobby_net_config_block.value + 0x61C8));
    ((Fields_arg0*)arg0)->field_10 = (unsigned char *) ((void *) ((u8 *)&lobby_net_config_block.value + 0x60F0));
}

void TLobby__sub_803F89A0(void *) {

}

typedef char RecoveredGlobal_803F89A4_lbl_805B52D4_size[sizeof(RecoveredGlobal_803F89A4_lbl_805B52D4) == 0x180 ? 1 : -1];
typedef char RecoveredGlobal_803F89A4_lbl_805B5454_size[sizeof(RecoveredGlobal_803F89A4_lbl_805B5454) == 0x68 ? 1 : -1];
void TLobby__sub_803F89A4(u8 *arg0) {
    struct Fields_arg0 { s16 field_0; s16 field_2; s16 field_4; u8 pad_6[2]; s32 * field_8; s32 * field_C; };
    ((Fields_arg0*)arg0)->field_0 = 2;
    ((Fields_arg0*)arg0)->field_2 = 0x10;
    ((Fields_arg0*)arg0)->field_4 = 8;
    ((Fields_arg0*)arg0)->field_8 = &lbl_805B5454.value;
    ((Fields_arg0*)arg0)->field_C = &lbl_805B52D4.value;
}

void TLobby__sub_803F89D8(void * _w0) {

}

typedef char RecoveredGlobal_803F89DC_lbl_805B54BC_size[sizeof(RecoveredGlobal_803F89DC_lbl_805B54BC) == 0x4000 ? 1 : -1];
typedef char RecoveredGlobal_803F89DC_lbl_805B94BC_size[sizeof(RecoveredGlobal_803F89DC_lbl_805B94BC) == 0x78 ? 1 : -1];
void TLobby::init_buffer_desc_a() {
    u8 *arg0 = (u8 *)this;
    struct Fields_arg0 { s16 field_0; s16 field_2; s32 * field_4; s32 * field_8; };
    ((Fields_arg0*)arg0)->field_0 = 2;
    ((Fields_arg0*)arg0)->field_2 = 0x2000;
    ((Fields_arg0*)arg0)->field_4 = &lbl_805B94BC.value;
    ((Fields_arg0*)arg0)->field_8 = &lbl_805B54BC.value;
}

void TLobby__sub_803F8A08(void * _w0) {

}

typedef char RecoveredGlobal_803F8A0C_lbl_805B9534_size[sizeof(RecoveredGlobal_803F8A0C_lbl_805B9534) == 0x108C ? 1 : -1];
void TLobby__sub_803F8A0C(u8 *arg0) {
    *(s16 *)((s8 *)arg0 + 0) = 5;
    *(s32 **)((s8 *)arg0 + 4) = &lbl_805B9534.value;
}

void TLobby__sub_803F8A24(void *) {

}

typedef char RecoveredGlobal_803F8A28_lbl_805AEEB0_size[sizeof(RecoveredGlobal_803F8A28_lbl_805AEEB0) == 0x49C8 ? 1 : -1];
void TLobby::init_net_buffer_config() {
    u8 *arg0 = (u8 *)this;
    struct Fields_arg0 { s16 field_0; s16 field_2; s16 field_4; s16 field_6; s16 field_8; s16 field_A; s16 field_C; u8 pad_E[2]; u8 * field_10; u8 * field_14; u8 * field_18; u8 * field_1C; u8 * field_20; u8 * field_24; };
    ((Fields_arg0*)arg0)->field_0 = 8;
    ((Fields_arg0*)arg0)->field_2 = 3;
    ((Fields_arg0*)arg0)->field_4 = 2;
    ((Fields_arg0*)arg0)->field_6 = 0x5DC;
    ((Fields_arg0*)arg0)->field_8 = 9;
    ((Fields_arg0*)arg0)->field_A = 0x14;
    ((Fields_arg0*)arg0)->field_C = 3;
    ((Fields_arg0*)arg0)->field_10 = (u8 *)(&(*(RecoveredGlobal_803F8A28_lbl_805AEEB0 *)&lobby_net_config_block).value) + 0xB650;
    ((Fields_arg0*)arg0)->field_14 = (u8 *)(&(*(RecoveredGlobal_803F8A28_lbl_805AEEB0 *)&lobby_net_config_block).value) + 0xB5F0;
    ((Fields_arg0*)arg0)->field_1C = (u8 *)(&(*(RecoveredGlobal_803F8A28_lbl_805AEEB0 *)&lobby_net_config_block).value) + 0xB5D0;
    ((Fields_arg0*)arg0)->field_18 = (u8 *)(&(*(RecoveredGlobal_803F8A28_lbl_805AEEB0 *)&lobby_net_config_block).value) + 0xB564;
    ((Fields_arg0*)arg0)->field_20 = (u8 *)(&(*(RecoveredGlobal_803F8A28_lbl_805AEEB0 *)&lobby_net_config_block).value) + 0xA9AC;
    ((Fields_arg0*)arg0)->field_24 = (u8 *)(&(*(RecoveredGlobal_803F8A28_lbl_805AEEB0 *)&lobby_net_config_block).value) + 0xA990;
}

void TLobby__sub_803F8A9C(void * _w0) {

}

typedef char RecoveredGlobal_803F8AA0_lbl_805BA5C0_size[sizeof(RecoveredGlobal_803F8AA0_lbl_805BA5C0) == 0x30AC ? 1 : -1];
void TLobby__sub_803F8AA0(u8 *arg0) {
    *(s16 *)((s8 *)arg0 + 0) = 3;
    *(s32 **)((s8 *)arg0 + 4) = &lbl_805BA5C0.value;
}

void TLobby__sub_803F8AB8(void) {
    TLobby::reset_message_thread();
}

void TLobby::init_net_func_table() {
    Desc_803F8AD8 *arg0 = (Desc_803F8AD8 *)this;
    Big_803F8AD8 *g = (Big_803F8AD8 *)&lobby_net_config_block;
    g->funcs[0] = (void *)TLobby__sub_80426B88;
    g->funcs[1] = (void *)TLobby::open_channel_checked;
    g->funcs[2] = (void *)TLobby::remove_rec_by_handle;
    g->funcs[3] = (void *)TLobby::add_multicast_address;
    g->funcs[4] = (void *)TLobby::consume_item_count_by_id;
    g->funcs[5] = (void *)TLobby::get_local_address;
    g->funcs[6] = (void *)TLobby::queue_timeout_message;
    arg0->a = 1;
    arg0->b = 1;
    arg0->c = 3;
    arg0->d = 8;
    arg0->funcs = g->funcs;
    arg0->x = g->bufE790;
    arg0->y = g->bufE760;
    arg0->z = g->bufB7A0;
}

void TLobby__sub_803F8B78(void) {

}

typedef char RecoveredGlobal_803F8B7C_lbl_805BD66C_size[sizeof(RecoveredGlobal_803F8B7C_lbl_805BD66C) == 0xA04 ? 1 : -1];
void TLobby::init_net_recv_desc() {
    u8 *arg0 = (u8 *)this;
    *(s16 *)((s8 *)arg0 + 0xA) = 0x500;
    *(s16 *)&this->m_next = 2;
    *(s32 * *)&this->m_up = &lobby_net_recv_desc_up_cell;
    *(s32 * *)&this->m_down = &lobby_net_recv_desc.value;
}

u8 *TLobby::layout_buffers(u8 *p, u8 *end) {
    H_803F8BA4 *h = (H_803F8BA4 *)this;
    Ent_803F8DBC *e;
    Ent_803F8BA4 *f;
    s32 i;
    u16 n = h->n2;
    lobby_thread_pool_count = 2;
    lobby_entry_pool_count = n * 2;
    if (h->a != 0) {
        lobby_thread_pool_count += 1;
    }
    if (h->b != 0) {
        lobby_thread_pool_count += 2;
    }
    *(u8 **)&lobby_entry_pool_base = p;
    p += lobby_entry_pool_count * 12;
    if (p > end) {
        return NULL;
    }
    e = *(Ent_803F8DBC **)&lobby_entry_pool_base;
    for (i = 0; i < lobby_entry_pool_count; i++, e++) {
        e->active = 0;
        e->size = h->c;
        e->val = (s32)p;
        p += h->c;
        if (p > end) {
            return NULL;
        }
    }
    *(u8 **)&lobby_thread_pool_base = p;
    p += lobby_thread_pool_count * 0x328;
    if (p > end) {
        return NULL;
    }
    f = *(Ent_803F8BA4 **)&lobby_thread_pool_base;
    for (i = 0; i < lobby_thread_pool_count; i++, f++) {
        f->size = h->d;
        f->buf = p;
        p += h->d;
        if (p > end) {
            return NULL;
        }
    }
    if (h->f != 0) {
        lobby_buffer_pool_base = p;
        p += h->f;
        if (p > end) {
            return NULL;
        }
        lobby_second_buffer_pool_base = p;
        p += h->f;
        if (p > end) {
            return NULL;
        }
        lobby_buffer_pool_size = h->f;
    }
    if (h->g != 0) {
        lobby_g_pool_base = p;
        p += h->g;
        if (p > end) {
            return NULL;
        }
        lobby_g_pool_size = h->g;
    }
    return p;
}

s32 TLobby__sub_803F8D24(H_803F8BA4 *h) {
    s32 n = 2;
    s32 size;
    if (h->a != 0) {
        n = 3;
    }
    if (h->b != 0) {
        n += 2;
    }
    size = (h->d + 0x328) * n;
    size += (h->c + 12) * h->n2 * 2;
    size += h->f * 2;
    size += h->g;
    return size;
}

void TLobby__sub_803F8D84(u32 key) {
    Ent_803F8D84 *e = lobby_entry_pool_base;
    s32 i;
    for (i = 0; i < lobby_entry_pool_count; i++) {
        if (e->key == key) {
            e->active = 0;
            return;
        }
        e++;
    }
}

s32 TLobby::alloc_buffer_slot(s32 size) {
    Ent_803F8DBC *e = (*(Ent_803F8DBC * *)&lobby_entry_pool_base);
    s32 i;
    s32 r = 0;
    for (i = 0; i < lobby_entry_pool_count; i++) {
        if (e->active == 0 && e->size >= size) {
            e->active = size;
            r = e->val;
            break;
        }
        e++;
    }
    return r;
}

typedef char RecoveredGlobal_803F94A0_lbl_805BF770_size[sizeof(RecoveredGlobal_803F94A0_lbl_805BF770) == 0x750 ? 1 : -1];

typedef char RecoveredGlobal_803AA0C0_lbl_80556E88_size[sizeof(RecoveredGlobal_803AA0C0_lbl_80556E88) == 0x100 ? 1 : -1];

typedef char RecoveredGlobal_803FB110_lbl_805BFF68_size[sizeof(RecoveredGlobal_803FB110_lbl_805BFF68) == 0xD0 ? 1 : -1];

typedef char RecoveredGlobal_803FC178_lbl_805C02D0_size[sizeof(RecoveredGlobal_803FC178_lbl_805C02D0) == 0x40 ? 1 : -1];

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

}
