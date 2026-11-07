#include "types.h"
#include "pso/unk/TLobby.h"
#include "pso/network/NetworkRuntime.h"

struct Self_803FD74C;
struct Tbl_803FD74C {
    u8 pad[0x20];
    void (*f20)(Self_803FD74C *);
};
struct Self_803FD74C {
    u8 f0; u8 f1; u8 f2; u8 f3; u8 f4; u8 f5; u8 f6; u8 f7;
    s16 f8; u8 padA[6];
    u8 f10[0x1C];
    Tbl_803FD74C *tbl;
    void *f30;
};

struct Self_803FD85C;
struct B_803FADA0;
struct Hdr_803FC4B4;
struct Tbl_803FD85C {
    u8 pad[0x14];
    void (*f14)(Self_803FD85C *, Tbl_803FD85C *);
    void (*f18)(Self_803FD85C *, Tbl_803FD85C *);
    void (*f1C)(Self_803FD85C *, Tbl_803FD85C *);
    void (*f20)(Self_803FD85C *, Tbl_803FD85C *);
    void (*f24)(Self_803FD85C *, Tbl_803FD85C *);
    B_803FADA0 *(*f28)(Self_803FD85C *, Tbl_803FD85C *);
    s16 (*f2C)(Self_803FD85C *, Hdr_803FC4B4 *, B_803FADA0 *, Tbl_803FD85C *);
    s16 (*f30)(Self_803FD85C *, Hdr_803FC4B4 *, B_803FADA0 *, Tbl_803FD85C *);
    s16 (*f34)(Self_803FD85C *, Hdr_803FC4B4 *, B_803FADA0 *, Tbl_803FD85C *);
    s16 (*f38)(Self_803FD85C *, Hdr_803FC4B4 *, B_803FADA0 *, Tbl_803FD85C *);
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
    u8 *pool;
    s16 block_size;
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
    union { s32 value; u8 *p0; };
    u8 *p4;
    u8 *p8;
    u8 *pC;
    u8 *p10;
    u8 *p14;
    u8 *p18;
    u8 *p1C;
    char *p20;
    u8 pad24[4];
    s16 f28;
    u8 pad2A[8];
    s16 pad_32;
    u8 pad34[2];
    u8 f36;
    u8 f37;
    u16 f38;
    u8 pad3A[6];
};

struct RecoveredGlobal_803FC1A0_lbl_805C02D0 {
    s32 value;
    u8 remaining[0x3C];
};

struct RecoveredGlobal_80401A68_lbl_805C04A8 {
    s32 value;
    u8 pad4[0x18];
    B_803FADA0 *f1C;
    u8 pad20[0x10];
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

struct Sub_803FC480 { u8 f0; u8 f1; u8 f2; u8 f3; u8 f4; };

struct Obj_803FC480 { u8 f0; u8 f1; u8 f2; u8 pad3[0x9D]; Sub_803FC480 sub; };

struct Ent_80408718 { s16 f0; u8 pad[0x16]; };

struct Tbl_80408718 { s16 count; s16 h2; s16 h4; s16 h6; s16 h8; u8 pad[4]; Ent_80408718 *list; };

typedef struct Conn_804004DC {
    u8 state;
    u8 id;
    u8 pad2_[1];
    u8 retries;
    u8 pad4[2];
    u8 f6;
    u8 pad7;
    s16 abort;
    u8 pad2[2];
    u8 *sub;
    u8 pad10[0x20];
    void *opts;
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
    u8 pad3A[0x13];
    u8 f4D;
    u8 pad4E[2];
    s16 f50;
    u8 pad52[6];
    s16 f58;
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

struct Sub_803FA664 { u8 pad0[0x28]; s16 h1C; u8 pad2A[0x4C - 0x2A]; u8 peer[0x74 - 0x4C]; s16 h74; };

struct Obj_803FA664 { u8 pad0; u8 b1; u8 pad2[4]; u8 b6; u8 pad7[4]; u8 bB; u8 padC[0x24]; Sub_803FA664 *p30; };

struct Msg_803FA664 { u8 pad0; u8 b1; s16 h2; };

typedef struct B_803FADA0 Ent_80401CE8;

struct RecoveredGlobal_803FD21C_lobby_net_buffer_desc_b {
    s32 value;
    u8 remaining[0x14];
};

struct RecoveredGlobal_803FD310_lobby_net_buffer_desc_b {
    s32 value;
    u8 remaining[0x14];
};

extern "C" {
s32 clear_flag_bit4__6TLobbyFlPUc(s32 arg0, u8 *arg1);
extern RecoveredGlobal_804050DC_lbl_805C18A0 lbl_805C18A0;
extern RecoveredGlobal_803FD520_lbl_805C0310 lobby_net_buffer_desc_b;
extern s16 lbl_805D7A7A;
s32 NetMemcmp(void *, void *, int);
void NetMemset(void *, int, int);
void NetMemcpy(void *, void *, int);
s32 NetIPv6CPSetInterfaceIdentifier(u8 *arg0, s32 arg1);
void TLobby__sub_803FD0C0(void);
s32 TLobby__sub_803F76F0(void *);
extern RecoveredGlobal_803FC178_lbl_805C02D0 lbl_805C02D0;
void TLobby__sub_803FE820(s32 arg0);
s32 set_socket_flags_by_mode__6TLobbyFsPv(s16 arg0, u8 *arg1);
s16 TLobby__sub_803FF304(u8 *arg0);
void TLobby__sub_803FF468(s32 arg0);
void TLobby__sub_803FD85C(void *);
s32 TLobby__sub_803F79BC(void *);
extern RecoveredGlobal_80401A68_lbl_805C04A8 lbl_805C04A8;
s32 TLobby__sub_803F778C(void *);
extern RecoveredGlobal_80402B60_lbl_805C0620 lbl_805C0620;
s32 TLobby__sub_803F811C(s16 *arg0);
s32 TLobby__sub_804036FC(u8 *arg0);
s32 TLobby__sub_80403DA8(s16 a0, s16 a1, s16 a2, s16 a3, s16 a4, char *name, s16 pppoe);
s32 TLobby__sub_804062A0(s16);
extern RecoveredGlobal_80403D28_lbl_805C0638 lbl_805C0638;
s32 TLobby__sub_80403D28(s32 arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4, s16 arg5, char *arg6, s16 arg7);
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
s16 TLobby__sub_803FE6CC(void *, u8, u8, B_803FADA0 *);
s16 TLobby__sub_803FE658(Self_803FD85C *f);
s32 send_network_frame(u16, u8 *);
s32 TLobby__sub_804037B0(s32 arg0, u16 arg1);
void TLobby__sub_80405328(u8 *arg0);
s16 TLobby__sub_8040FCEC(u32);
void TLobby__sub_803F892C(void *);
void TLobby__sub_803F8958(void *);
void TLobby__sub_803F87DC(void *);
void TLobby__sub_803F89D8(void *);
s16 TLobby__sub_80409A3C(u8 *arg0, s16 arg1);
void TLobby__sub_803FD958(u8 *arg0);
void TLobby__sub_80401CAC(Outer_80401CAC *o, u16 v);
u16 read_network_u16_be(u8 *p);
u32 TLobby__sub_80402AFC(u8 *p);
}
u8 *write_network_u32_be(u8 *p, u32 v);
void MD5Transform(u32 *state, u8 *block);
extern "C" {
void TLobby__sub_80405000(u32 arg0);
u8 *write_network_u16_be(u8 *p, u16 v);
extern Tbl_80408718 lbl_805C1AB0;
s32 TLobby__sub_80405304(void *arg0);
extern s32 lbl_8047FEB8[];
extern s32 lbl_8047FEC8[];
void TLobby__sub_803FF384(u8 *arg0);
void TLobby__sub_803F97E8(int);
extern u8 lbl_8047FE3C[];
s32 wait_for_connection__6TLobbyFPv(Conn_804004DC *c);
void NetMemcpy(void * _w0, void * _w1, int _w2);
extern Names_80403168 lbl_805C04D8;
s32 TLobby__sub_80403168(u8 *arg0, u8 *arg1, u8 *arg2);
s16 TLobby__sub_803FC1CC(Conn_804004DC *c, s32 timeout);
s32 TLobby__sub_803FC684(u8 *, u8 *, u8 *);
extern u8 lbl_805C0038[];
extern s16 lbl_805D7A7C;
s32 TLobby__sub_80403B04(u8 *arg0, u8 *arg1, s32 arg2);
s16 TLobby__sub_80402BB4(u8 *, s32);
extern s32 lbl_805D7A90;
extern s32 lbl_805D7AA0;
extern s16 lbl_805D7A80;
extern s16 lbl_805D7A82;
s32 TLobby__sub_80403BA8(u8 *arg0, u8 *arg1, s32 arg2);
s16 TLobby__sub_80401BCC(void *src, void *dst, u16 n);
extern u8 lcp_read_value_buffer[4];
extern u8 lobby_read_byte_buffer[1];
void TLobby__sub_8040098C(Self_8040098C *self);
s16 TLobby__sub_80403F4C(void *, Strm_80405A74 **);
B_803FADA0 *init_net_buffer_entry__6TLobbyFUs(u16);
s32 TLobby__sub_803F812C(u16 arg0, void *arg1, u16 *arg2);
s32 TLobby__sub_80403730(u8 *dst, unsigned short n);
struct Opt_80400338;
void TLobby__sub_80400270(B_803FADA0 **pbuf, Opt_80400338 *opt, s16 mask);
Ent_80401CE8 *init_net_buffer_entry__6TLobbyFUs(u16 idx);
extern u8 lcp_read_byte_buffer;
s32 TLobby__sub_803FF858(Obj_803FA664 *arg0, Msg_803FA664 *arg1, u32 arg2);
s16 TLobby__sub_803FD5A4(s16 h, s16 v);
s32 TLobby__sub_80406328(s32, s16);
s16 TLobby__sub_804098B4(void *);
s32 TLobby__sub_80409908(void *, void *);
extern s16 lbl_805D7A8A;
s32 TLobby__sub_803FD21C(s16 arg0, s32 arg1, s32 arg2, u8 *arg3);
s32 TLobby__sub_803FD310(s16 arg0, s32 arg1, u8 *arg2);
s32 TLobby__sub_803FD490(s16 arg0);
s32 TLobby__sub_803FD4B4(s16 arg0);
s32 TLobby__sub_803FD4D8(s16 arg0);
s32 TLobby__sub_803FD4FC(s16 arg0);
s32 TLobby__sub_803FE844(void);
void TLobby__sub_803FE84C(void);
s32 TLobby__sub_803FF2CC(u8 *arg0, s32 arg1);
void TLobby__sub_803FF374(u8 *arg0);
void TLobby__sub_80400988(void);
void TLobby__sub_80400B98(u8 *arg0);
s32 set_filter_id__6TLobbyFPvi(u8 *arg0, s32 arg1);
s32 set_filter_index__6TLobbyFPvi(u8 *arg0, s32 arg1);
s32 set_target_id__6TLobbyFPvi(u8 *arg0, s32 arg1);
s32 set_target_index__6TLobbyFPvi(u8 *arg0, s32 arg1);
s32 set_target_slot__6TLobbyFPvi(u8 *arg0, s32 arg1);

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

typedef char RecoveredGlobal_803FC178_lbl_805C02D0_size[sizeof(RecoveredGlobal_803FC178_lbl_805C02D0) == 0x40 ? 1 : -1];

void TLobby::init_net_state_a() {
    TLobby__sub_803F76F0((void *) (&lbl_805C02D0.value));
}

typedef char RecoveredGlobal_803FC1A0_lbl_805C02D0_size[sizeof(RecoveredGlobal_803FC1A0_lbl_805C02D0) == 0x40 ? 1 : -1];
s32 TLobby::init_net_state_b() {
    ((TLobby *)(&(*(RecoveredGlobal_803FC1A0_lbl_805C02D0 *)&lbl_805C02D0).value))->init_net_buffer_table();
    return 0;
}

struct Auth_803FC1CC { u8 pad[0xC]; s16 active; };
B_803FADA0 *TLobby__sub_803FCF44(Self_803FD74C *fsm);
s16 TLobby__sub_803FC1CC(Conn_804004DC *c, s32 timeout) {
    Auth_803FC1CC *auth;
    u8 *sub;
    RecoveredGlobal_804050DC_lbl_805C18A0 *g;

    sub = c->sub;
    auth = (Auth_803FC1CC *)c->opts;
    if (lbl_805D7A90 & 2) {
        auth->active = 1;
        TLobby__sub_803FE820((s32)c);
        TLobby__sub_803FE6CC(c, 1, 0, TLobby__sub_803FCF44((Self_803FD74C *)c));
    } else {
        auth->active = 0;
    }
    g = &lbl_805C18A0;
    c->abort = 0;
    while (c->state != 5) {
        if (TLobby::is_timed_out() != 0 || c->abort != 0 || *sub == 4) {
            c->abort = 0;
            if (lbl_805D7A80 != 0) {
                lbl_805D7A82 = 6;
            } else {
                lbl_805D7A82 = 5;
            }
            lbl_805D7A8A = 8;
            return -1;
        }
        if (TLobby::get_remaining(timeout) != 0) {
            return -0x12;
        }
        TUdpSocket::unlock_mutex(g->value);
        TLobby__sub_803F97E8(100);
        TLobby::process_expired_timers();
        TLobby::lock_mutex(g->value);
    }
    c->abort = 0;
    return 0;
}

struct Proto_803FC318 {
    const char *name;
    u16 proto;
    u16 h6;
    u8 b8;
    u8 b9;
    u8 bA;
    u8 bB;
    s32 timeout;
    void (*f10)(void);
    void (*f14)(void);
    void (*f18)(void);
    void (*f1C)(void);
    void (*f20)(void);
    void (*f24)(void);
    B_803FADA0 *(*f28)(Self_803FD74C *);
    s32 (*f2C)(void);
    s32 (*f30)(void);
    s32 (*f34)(void);
    s32 (*f38)(void);
};
struct Buf_803FC684 { char a[0x80]; char b[0x80]; u8 opts[0x14]; Proto_803FC318 proto; };
Buf_803FC684 lbl_805C0180;
RecoveredGlobal_803FC178_lbl_805C02D0 lbl_805C02D0;
struct Self_803FC318;
struct Timer_803FC318 {
    u8 pad0[0x10];
    void (*callback)(Conn_804004DC *);
    Self_803FC318 *arg;
    u8 pad18[4];
};
struct Self_803FC318 {
    u8 f0; u8 f1; u8 f2; u8 f3; u8 f4; u8 f5; u8 f6; u8 f7;
    u8 pad8[4];
    u8 *sub;
    Timer_803FC318 timer;
    Proto_803FC318 *proto;
    void *opts;
};
extern const char lbl_805E1160[5];
void TLobby__sub_803FC728(Conn_804004DC *c);
struct N_80405298;
void TLobby__sub_80405298(N_80405298 *o, s32 v);
extern "C" void TLobby__sub_803FC318(u8 *conn);

void TLobby__sub_803FC318(u8 *conn) {
    Self_803FC318 *fsm = (Self_803FC318 *)(conn + 0xA0);
    Timer_803FC318 *timer;

    if (fsm->opts == NULL) {
        timer = &fsm->timer;
        lbl_805C0180.proto.name = lbl_805E1160;
        lbl_805C0180.proto.proto = 0xC223;
        lbl_805C0180.proto.h6 = 0x70;
        lbl_805C0180.proto.b8 = 3;
        lbl_805C0180.proto.bB = 0;
        lbl_805C0180.proto.b9 = lbl_805C02D0.f36;
        lbl_805C0180.proto.bA = lbl_805C02D0.f37;
        lbl_805C0180.proto.timeout = lbl_805C02D0.f38 * 1000;
        lbl_805C0180.proto.f10 = TLobby__sub_803FE84C;
        lbl_805C0180.proto.f14 = TLobby__sub_803FE84C;
        lbl_805C0180.proto.f18 = TLobby__sub_803FE84C;
        lbl_805C0180.proto.f1C = TLobby__sub_803FE84C;
        lbl_805C0180.proto.f20 = TLobby__sub_803FE84C;
        lbl_805C0180.proto.f24 = TLobby__sub_803FE84C;
        lbl_805C0180.proto.f28 = TLobby__sub_803FCF44;
        lbl_805C0180.proto.f2C = TLobby__sub_803FE844;
        lbl_805C0180.proto.f30 = TLobby__sub_803FE844;
        lbl_805C0180.proto.f34 = TLobby__sub_803FE844;
        lbl_805C0180.proto.f38 = TLobby__sub_803FE844;
        fsm->sub = conn;
        fsm->proto = &lbl_805C0180.proto;
        fsm->opts = lbl_805C0180.opts;
        fsm->f4 = fsm->proto->b9;
        fsm->f7 = fsm->proto->bA;
        fsm->f5 = fsm->proto->bB;
        fsm->f0 = 0;
        fsm->f3 = fsm->f4;
        fsm->f6 = fsm->f7;
        timer->callback = TLobby__sub_803FC728;
        timer->arg = fsm;
        TLobby__sub_80405298((N_80405298 *)timer, fsm->proto->timeout);
    }
}

s32 TLobby::set_active_flag() {
    u8 *arg0 = (u8 *)this;
    *(s8 *)((s8 *)arg0 + 0xA0) = 2;
    *(u8 *)((s8 *)arg0 + 0xA2) = (u8) (*(u8 *)((s8 *)arg0 + 0xA2) | 0x20);
    *(u8 *)((s8 *)arg0 + 2) = (u8) (*(u8 *)((s8 *)arg0 + 2) | 0x20);
    return 0;
}

s32 TLobby::mark_sub_ready() {
    Obj_803FC480 *self = (Obj_803FC480 *)this;
    Sub_803FC480 *s = &self->sub;
    s->f0 = 1;
    s->f2 |= 0x10;
    self->f2 |= 0x10;
    s->f3 = s->f4;
    return 0;
}

s16 TLobby__sub_803FE8BC(u8 *, void *);
typedef struct Hdr_803FC4B4 { u8 type; u8 flag; s16 len; } Hdr_803FC4B4;
void TLobby__sub_803FCC10(Conn_804004DC *c, Hdr_803FC4B4 *hdr, B_803FADA0 *src);
extern "C" s16 TLobby__sub_803FC820(Conn_804004DC *c, Hdr_803FC4B4 *hdr, B_803FADA0 *src);
struct O_80400ACC;
void TLobby__sub_80400ACC(O_80400ACC *);
struct Outer_80401CAC;
void TLobby__sub_80401CAC(Outer_80401CAC *, u16);
s32 TLobby__sub_80405304(void *);

void TLobby::dispatch_received_packet(s32 arg1) {
    u8 *arg0 = (u8 *)this;
    Hdr_803FC4B4 hdr;
    u8 temp_r0;
    u8 temp_r0_2;
    u8 temp_r0_3;
    u8 *temp_r30;
    u8 *temp_r30_2;
    u8 *temp_r30_3;
    u8 *temp_r30_4;

    if (TLobby__sub_803FE8BC((u8 *)&hdr, &arg1) != -1) {
        hdr.len -= 4;
        TLobby__sub_80401CAC((Outer_80401CAC *)&arg1, hdr.len);
        switch (hdr.type) {
        case 1:
            TLobby__sub_803FCC10((Conn_804004DC *)arg0, &hdr, (B_803FADA0 *)arg1);
            return;
        case 2:
            if (TLobby__sub_803FC820((Conn_804004DC *)arg0, &hdr, (B_803FADA0 *)arg1) == 0) {
                if (lbl_805D7A90 & 2) {
                    temp_r30 = (u8 *)(*(u8 **)((s8 *)arg0 + 0xC));
                    TLobby__sub_80405304((void *) ((u8 *)(arg0) + 0x10));
                    temp_r0 = *(u8 *)((s8 *)arg0 + 2) & 0xFFFFFFEF;
                    *(u8 *)((s8 *)arg0 + 2) = temp_r0;
                    if (!(temp_r0 & 0x10)) {
                        *(s8 *)((s8 *)arg0 + 0) = 5;
                    }
                    *(u8 *)((s8 *)temp_r30 + 2) = (u8) (*(u8 *)((s8 *)temp_r30 + 2) & 0xFFFFFFEF);
                    *(u8 *)((s8 *)temp_r30 + 2) = (u8) (*(u8 *)((s8 *)temp_r30 + 2) & 0xFFFFFFDF);
                    TLobby__sub_80400ACC((O_80400ACC *) (temp_r30));
                    return;
                }
                temp_r30_2 = (u8 *)(*(u8 **)((s8 *)arg0 + 0xC));
                TLobby__sub_80405304((void *) ((u8 *)(arg0) + 0x10));
                temp_r0_2 = *(u8 *)((s8 *)arg0 + 2) & 0xFFFFFFDF;
                *(u8 *)((s8 *)arg0 + 2) = temp_r0_2;
                if (!(temp_r0_2 & 0x10)) {
                    *(s8 *)((s8 *)arg0 + 0) = 5;
                }
                *(u8 *)((s8 *)temp_r30_2 + 2) = (u8) (*(u8 *)((s8 *)temp_r30_2 + 2) & 0xFFFFFFDF);
                TLobby__sub_80400ACC((O_80400ACC *) (temp_r30_2));
                return;
            }
            break;
        case 3:
            TLobby__sub_80405304((void *) ((u8 *)(arg0) + 0x10));
            temp_r30_3 = (u8 *)(*(u8 **)((s8 *)arg0 + 0xC));
            TLobby__sub_80405304((void *) ((u8 *)(arg0) + 0x10));
            temp_r0_3 = *(u8 *)((s8 *)arg0 + 2) & 0xFFFFFFEF;
            *(u8 *)((s8 *)arg0 + 2) = temp_r0_3;
            if (!(temp_r0_3 & 0x10)) {
                *(s8 *)((s8 *)arg0 + 0) = 5;
            }
            *(u8 *)((s8 *)temp_r30_3 + 2) = (u8) (*(u8 *)((s8 *)temp_r30_3 + 2) & 0xFFFFFFEF);
            *(u8 *)((s8 *)temp_r30_3 + 2) = (u8) (*(u8 *)((s8 *)temp_r30_3 + 2) & 0xFFFFFFDF);
            TLobby__sub_80400ACC((O_80400ACC *) (temp_r30_3));
            return;
        case 4:
            TLobby__sub_80405304((void *) ((u8 *)(arg0) + 0x10));
            temp_r30_4 = (u8 *)(*(u8 **)((s8 *)arg0 + 0xC));
            TLobby::update_connection_state((int) ((u8 *)(temp_r30_4) + 0xA0));
            TLobby::update_connection_state((int) ((u8 *)(temp_r30_4) + 4));
            *(s16 *)((s8 *)arg0 + 8) = 1;
            lbl_805D7A80 = 1;
            break;
        }
    }
}

s32 TLobby__sub_803FC684(u8 *arg0, u8 *arg1, u8 *arg2) {
    char **p = *(char ***)(arg2 + 0x30);

    if (NetStringLength((const char*)arg0) >= 0x80) {
        arg0[0x7F] = 0;
    }
    if (NetStringLength((const char*)arg1) >= 0x80) {
        arg1[0x7F] = 0;
    }
    NetCopyString((char*)lbl_805C0180.a, (const char*)arg0);
    NetCopyString((char*)lbl_805C0180.b, (const char*)arg1);
    p[0] = lbl_805C0180.a;
    p[1] = lbl_805C0180.b;
    return 0;
}

struct Chap_803FC728 { const char *name; const char *secret; const char *msg; s16 active; u8 id; u8 padF; u16 len; };
struct G_803FC728 { u8 pad0[0x1C]; void *data; };
extern const char lbl_8047FDE0[];
extern const char lbl_8047FDF0[];
B_803FADA0 *TLobby__sub_80401B20(void *src, u16 n);
void TLobby__sub_803FC728(Conn_804004DC *c) {
    B_803FADA0 *buf;
    Chap_803FC728 *chap = (Chap_803FC728 *)c->opts;
    u8 *sub;

    if (chap->active != 0) {
        if (c->retries != 0) {
            chap->msg = lbl_8047FDE0;
            TLobby__sub_803FE658((Self_803FD85C *)c);
            return;
        }
        chap->msg = lbl_8047FDF0;
        sub = c->sub;
        TLobby::update_connection_state((int)(sub + 0xA0));
        TLobby::update_connection_state((int)(sub + 4));
        c->abort = 1;
        return;
    }
    if (c->retries != 0) {
        buf = TLobby__sub_80401B20(((G_803FC728 *)&lbl_805C02D0)->data, chap->len);
        TLobby__sub_803FE6CC(c, 2, chap->id, buf);
        TLobby__sub_80405328((u8 *)c + 0x10);
        c->retries--;
        return;
    }
    sub = c->sub;
    TLobby::update_connection_state((int)(sub + 0xA0));
    TLobby::update_connection_state((int)(sub + 4));
    c->abort = 1;
}

struct Md5Ctx_80401EB8 { u32 state[4]; u32 count[2]; u8 buffer[64]; };
void TLobby__sub_80401EB8(Md5Ctx_80401EB8 *ctx, u8 *input, u32 len);
extern "C" {
void TLobby__sub_80401D2C(u8 *digest, Md5Ctx_80401EB8 *ctx);
const char *TLobby__sub_803F7684(u8 *name);
extern u8 lbl_805D7A98;
extern u16 lbl_805D7A9A;
extern const char lbl_805E1168[7];
extern const char lbl_8047FE08[11];
}

#pragma push
#pragma opt_common_subs on
#pragma dont_inline off
#pragma inline_depth(4)
inline s32 chap_read_byte_slow(B_803FADA0 **src) {
    if (TLobby__sub_80401BCC(src, &lbl_805D7A98, 1) != 1) {
        return -1;
    }
    return (s16)lbl_805D7A98;
}

inline s32 chap_read_byte(B_803FADA0 **src) {
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
    return chap_read_byte_slow(src);
}

s16 TLobby__sub_803FC820(Conn_804004DC *c, Hdr_803FC4B4 *hdr, B_803FADA0 *src) {
    s16 total;
    Chap_803FC728 *chap;
    u8 *name;
    u8 *value;
    s16 n;
    const char *secret;
    s32 i;
    u8 *p;
    s16 m;
    s32 j;
    u8 *q;
    s16 len;
    s32 code;
    s16 ret;
    B_803FADA0 *reply;
    Md5Ctx_80401EB8 ctx;

    name = NULL;
    value = NULL;
    secret = NULL;
    chap = (Chap_803FC728 *)c->opts;

    if (hdr->flag != c->id) {
        return -1;
    }
    total = hdr->len;
    n = chap_read_byte_slow(&src);
    if (n != -1) {
        p = value = lbl_805C02D0.p10;
        for (i = 0; i < n; i++) {
            *p++ = chap_read_byte(&src);
        }
    }
    m = total - n - 1;
    if (m < 0) {
        m = 0;
    }
    if (m >= 0x80) {
        m = 0x7F;
    }
    if (m != 0) {
        q = name = lbl_805C02D0.p4;
        for (j = 0; j < m; j++) {
            *q++ = chap_read_byte(&src);
        }
        *q = 0;
    }
    if (lbl_805D7A90 & 2) {
        secret = TLobby__sub_803F7684(name);
        if (secret == NULL) {
            NetCopyString(lbl_805C02D0.p20, lbl_805E1168);
            reply = TLobby__sub_80401B20(lbl_805C02D0.p20, NetStringLength(lbl_805C02D0.p20));
            TLobby__sub_803FE6CC(c, 4, hdr->flag, reply);
            return -1;
        }
    }
    *lbl_805C02D0.p18 = hdr->flag;
    if (lbl_805D7A90 & 2) {
        NetCopyString((char *)lbl_805C02D0.p18 + 1, secret);
    } else {
        NetCopyString((char *)lbl_805C02D0.p18 + 1, chap->secret);
    }
    if (lbl_805D7A90 & 2) {
        len = NetStringLength(secret);
    } else {
        len = NetStringLength(chap->secret);
    }
    ((TLobby *)&ctx)->init_md5_state();
    TLobby__sub_80401EB8(&ctx, lbl_805C02D0.p18, len + 1);
    TLobby__sub_80401EB8(&ctx, lbl_805C02D0.p8 + 1, lbl_805D7A9A);
    TLobby__sub_80401D2C((u8 *)lbl_805C02D0.p20, &ctx);
    if (NetMemcmp(lbl_805C02D0.p20, value, 0x10) == 0) {
        NetCopyString(lbl_805C02D0.p20, lbl_8047FE08);
        code = 3;
        ret = 0;
    } else if (lbl_805D7A90 & 2) {
        NetCopyString(lbl_805C02D0.p20, lbl_805E1168);
        code = 4;
        ret = -1;
    } else {
        NetCopyString(lbl_805C02D0.p20, lbl_8047FE08);
        code = 3;
        ret = 0;
    }
    reply = TLobby__sub_80401B20(lbl_805C02D0.p20, NetStringLength(lbl_805C02D0.p20));
    TLobby__sub_803FE6CC(c, code, hdr->flag, reply);
    return ret;
}

void TLobby__sub_803FCC10(Conn_804004DC *c, Hdr_803FC4B4 *hdr, B_803FADA0 *src) {
    s16 total = hdr->len;
    u8 *value = NULL;
    Chap_803FC728 *chap = (Chap_803FC728 *)c->opts;
    u8 *p;
    s16 n;
    s32 i;
    u16 m;
    u8 *q;
    s32 j;
    u16 secretLen;
    s32 off;
    u16 nameLen;
    Md5Ctx_80401EB8 ctx;
    u8 *sub;

    n = chap_read_byte_slow(&src);
    if (n != -1) {
        value = lbl_805C02D0.pC;
        for (i = 0, p = value; i < n; i++) {
            *p++ = chap_read_byte(&src);
        }
    }
    m = total - n - 1;
    if (m >= 0x80) {
        m = 0x7F;
    }
    if (m != 0) {
        q = lbl_805C02D0.p0;
        for (j = 0; j < m; j++) {
            *q++ = chap_read_byte(&src);
        }
        *q = 0;
    }
    *lbl_805C02D0.p14 = hdr->flag;
    NetCopyString((char *)lbl_805C02D0.p14 + 1, chap->secret);
    secretLen = NetStringLength(chap->secret);
    nameLen = NetStringLength(chap->name);
    off = secretLen + 1;
    NetMemcpy(lbl_805C02D0.p14 + off, value, n);
    NetMemset(lbl_805C02D0.p1C, 0, lbl_805C02D0.pad_32);
    *lbl_805C02D0.p1C = 0x10;
    ((TLobby *)&ctx)->init_md5_state();
    TLobby__sub_80401EB8(&ctx, lbl_805C02D0.p14, off + n);
    TLobby__sub_80401D2C(lbl_805C02D0.p1C + 1, &ctx);
    NetMemcpy(lbl_805C02D0.p1C + 17, (void *)chap->name, nameLen);
    chap->id = hdr->flag;
    chap->len = nameLen + 17;
    TLobby__sub_803FE6CC(c, 2, chap->id, TLobby__sub_80401B20(lbl_805C02D0.p1C, chap->len));
    TLobby__sub_80405328((u8 *)c + 0x10);
    c->retries--;
    if (c->f6 != 0) {
        c->f6--;
        return;
    }
    sub = c->sub;
    TLobby::update_connection_state((int)(sub + 0xA0));
    TLobby::update_connection_state((int)(sub + 4));
}

B_803FADA0 *TLobby__sub_803FCF44(Self_803FD74C *fsm) {
    Chap_803FC728 *chap = (Chap_803FC728 *)fsm->f30;
    s32 tick;
    char name[] = "avetcp";
    B_803FADA0 *buf;
    u8 *p;
    s16 i;
    s16 len;

    if (chap->name == NULL || chap->secret == NULL) {
        return NULL;
    }
    buf = init_net_buffer_entry__6TLobbyFUs(0);
    if (buf == NULL) {
        return NULL;
    }
    p = buf->buf;
    NetStoreTick(&tick);
    lbl_805D7A9A = (tick & 0x1F) + 0x10;
    *p++ = lbl_805D7A9A;
    NetStoreTick(&tick);
    for (i = 0; i < lbl_805D7A9A; i++) {
        *p++ = tick;
    }
    NetCopyString((char *)p, name);
    buf->len += lbl_805D7A9A + (u16)NetStringLength(name) + 1;
    len = buf->len;
    if (len > lbl_805C02D0.f28) {
        len = lbl_805C02D0.f28;
    }
    NetMemcpy(lbl_805C02D0.p8, buf->buf, len);
    return buf;
}
#pragma pop

s32 TLobby::set_flags_and_state() {
    u8 *arg0 = (u8 *)this;
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
    TLobby::clear_table_entry_locked((s16)(g->h0));
    g->h0 = -1;
    g->h16 = 0;
    TLobby__sub_803F7980(g);
}

typedef void (*Fn_803FD10C)(void);
s32 TLobby__sub_803FD404(s16 slot, u8 *p);
s32 TLobby__sub_803FD60C(s16 id, u8 *p);

s16 TLobby__sub_803FD10C(void) {
    Fn_803FD10C fns[11];
    s16 r;
    s16 i;
    s16 *p;

    ((TLobby *)(&lobby_net_buffer_desc_b))->init_buffer_desc_b();
    fns[0] = (Fn_803FD10C)TLobby__sub_803FD60C;
    fns[1] = (void (*)())TLobby__sub_803FD5A4;
    fns[2] = (Fn_803FD10C)TLobby::clear_socket_slot;
    fns[3] = (Fn_803FD10C)TLobby::get_checked_status_value;
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
#pragma dont_inline on
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
    TLobby::lock_mutex((int)((void *) (((s32 *)&lbl_805C18A0)[0])));
    if ((s16) lbl_805D7A8A == 4) {
        *(s32 *)((s8 *)temp_r31 + 0) = (s32) ((u8 *)(*(u8 **)((s8 *)((s32 *)&lbl_805C04A8) + 0x14)) + ((*(s32 *)((s8 *)((s32 *)&lbl_805C04A8) + 0) + 0x83) & 0xFFFFFFFC));
        *(s16 *)((s8 *)temp_r31 + 4) = temp_r3;
        TLobby__sub_80409908((void *)(*(s32 *)((s8 *)temp_r31 + 0)), (void *)(arg3));
        TLobby__sub_80406328((s32) temp_r31, *(s16 *)((s8 *)((u8 *)(&(*(RecoveredGlobal_803FD21C_lobby_net_buffer_desc_b *)&lobby_net_buffer_desc_b).value) + (arg0 * 4)) + 4));
    }
    TUdpSocket::unlock_mutex((int)((void *) (((s32 *)&lbl_805C18A0)[0])));
    return 0;
}
#pragma pop

#pragma push
#pragma optimization_level 3
#pragma dont_inline on
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
    TLobby::lock_mutex((int)((void *) (((s32 *)&lbl_805C18A0)[0])));
    if ((s16) lbl_805D7A8A == 4) {
        *(s32 *)((s8 *)temp_r31 + 0) = (s32) ((u8 *)(*(u8 **)((s8 *)((s32 *)&lbl_805C04A8) + 0x14)) + ((*(s32 *)((s8 *)((s32 *)&lbl_805C04A8) + 0) + 0x83) & 0xFFFFFFFC));
        *(s16 *)((s8 *)temp_r31 + 4) = temp_r3;
        TLobby__sub_80409908((void *)(*(s32 *)((s8 *)temp_r31 + 0)), (void *)(arg2));
        TLobby__sub_80406328((s32) temp_r31, *(s16 *)((s8 *)((u8 *)(&(*(RecoveredGlobal_803FD310_lobby_net_buffer_desc_b *)&lobby_net_buffer_desc_b).value) + (arg0 * 4)) + 4));
    }
    TUdpSocket::unlock_mutex((int)((void *) (((s32 *)&lbl_805C18A0)[0])));
    return 0;
}
#pragma pop

s32 TLobby__sub_803FD404(s16 slot, u8 *p) {
    RecoveredGlobal_803FD520_lbl_805C0310 *g = &lobby_net_buffer_desc_b;
    s16 i;
    s16 *used;
    u8 *block;
    s16 size;

    if ((slot != 0) && (slot != 1)) {
        return -0x112;
    }
    used = g->buf;
    i = 0;
    block = g->pool;
    size = g->block_size;
    for (; i < g->h16; i++, used++) {
        if (*used != 0 && block <= p && p < block + size) {
            *used = 0;
            return 0;
        }
        block += size;
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
s16 TLobby::get_checked_status_value(s16 arg0) {
    if ((arg0 != 0) && (arg0 != 1)) {
        return -0x112;
    }
    if (lbl_805D7A7A != 0) {
        return 0x5AE;
    }
    return *(s16 *)((s8 *)(&lobby_net_buffer_desc_b.h0) + 0x14);
}

struct E_803FD560 { s16 a; s16 b; };
struct G_803FD560 { s16 id; E_803FD560 e[2]; };
s32 TLobby::clear_socket_slot(s16 i) {
    if (i != 0 && i != 1) {
        return -0x112;
    }
    G_803FD560 *g = (G_803FD560 *)&lobby_net_buffer_desc_b;
    g->e[i].a = 0;
    g->e[i].b = 0;
    return 0;
}

struct N_80405298;
void TLobby__sub_80405298(N_80405298 *o, s32 v);
void update_countdown_state__6TLobbyFPv(void *);

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

struct Opts_803FD60C { u8 pad[8]; u32 f8; u32 fC; };
s32 TLobby__sub_803FD60C(s16 id, u8 *p) {
    Self_803FD74C *ipcp;
    Opts_803FD60C *o;
    u32 a;
    u32 b;

    if (id != lobby_net_buffer_desc_b.h0) {
        return -0x112;
    }
    ipcp = (Self_803FD74C *)(lbl_805C0038 + 0xD4);
    o = (Opts_803FD60C *)ipcp->f30;
    if (ipcp->f0 != 5) {
        return -0x112;
    }
    a = o->f8;
    b = o->fC;
    *p++ = (a >> 24) & 0xFF;
    *p++ = (a >> 16) & 0xFF;
    *p++ = (a >> 8) & 0xFF;
    *p++ = a & 0xFF;
    *p++ = (b >> 24) & 0xFF;
    *p++ = (b >> 16) & 0xFF;
    *p++ = (b >> 8) & 0xFF;
    *p = b & 0xFF;
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
    *(void **)((s8 *)temp_r31 + 0x10) = (void *)update_countdown_state__6TLobbyFPv;
    *(u8 **)((s8 *)temp_r31 + 0x14) = arg0;
    TLobby__sub_80405298((N_80405298 *) (temp_r31), (s32) (*(s32 *)((s8 *)(*(u8 **)((s8 *)arg0 + 0x2C)) + 0xC)));
}

#define self ((Self_803FD74C *)arg0)
void TLobby::update_connection_state(int arg0) {
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
          TLobby__sub_803FE6CC((void *) arg0, 1, 0, (*((B_803FADA0 *(**)(void *, void *)) (((s8 *) temp_r4_3) + 0x28)))(arg0, temp_r4_3));
        }
        *((u8 *) (((s8 *) arg0) + 0)) = 2U;
      }
    }
  }
}

struct Self_803FDA68;
struct Tbl_803FDA68 {
    u8 pad[0x14];
    void (*f14)(Self_803FDA68 *, Tbl_803FDA68 *);
    u8 pad18[0xC];
    void (*f24)(Self_803FDA68 *, Tbl_803FDA68 *);
    B_803FADA0 *(*f28)(Self_803FDA68 *, Tbl_803FDA68 *);
};
struct Self_803FDA68 {
    u8 f0; u8 f1; u8 f2; u8 f3; u8 f4; u8 f5; u8 f6; u8 f7;
    s16 f8; u8 padA[6];
    u8 f10[0x1C];
    Tbl_803FDA68 *tbl;
    void *f30;
};

void update_countdown_state__6TLobbyFPv(void *arg0) {
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

#pragma push
#pragma opt_common_subs on
#pragma dont_inline off
#pragma auto_inline on
#pragma inline_depth(4)
void TLobby__sub_803FE600(Self_803FD85C *f) {
    f->f0 = (f->f2 & 0xC0) ? 1 : 0;
    f->f3 = f->f4;
    f->f6 = f->f7;
    f->tbl->f14(f, f->tbl);
}

s16 TLobby__sub_803FE658(Self_803FD85C *f) {
    if (f->f3 == 0) {
        return -1;
    }
    f->f3--;
    TLobby__sub_80405328(f->f10);
    return TLobby__sub_803FE6CC(f, 1, 0, f->tbl->f28(f, f->tbl));
}

s16 TLobby__sub_803FE8BC(u8 *dst, void *src) {
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

// Puts a packet's header back in front of its data (name inferred: code-reject path of the fsm input).
inline B_803FADA0 *fsm_prepend_header(B_803FADA0 *m, Hdr_803FC4B4 *hdr) {
    u8 *p;

    m = (B_803FADA0 *)((TLobby *)m)->alloc_from_buffer(4);
    p = m->buf;
    *p++ = hdr->type;
    *p++ = hdr->flag;
    write_network_u16_be(p, hdr->len);
    return m;
}

extern "C" void TLobby__sub_803FDBF8(Self_803FD85C *f, B_803FADA0 *src);

void TLobby__sub_803FDBF8(Self_803FD85C *f, B_803FADA0 *src) {
    Hdr_803FC4B4 hdr;

    if (TLobby__sub_803FE8BC((u8 *)&hdr, &src) != 0) {
        return;
    }
    hdr.len -= 4;
    TLobby__sub_80401CAC((Outer_80401CAC *)&src, hdr.len);
    switch (hdr.type) {
    case 1:
        switch (f->f0) {
        case 5:
            f->tbl->f20(f, f->tbl);
            TLobby__sub_803FE600(f);
        case 1:
            f->tbl->f18(f, f->tbl);
            TLobby__sub_803FE658(f);
        case 2:
        case 4:
            if (f->tbl->f2C(f, &hdr, src, f->tbl) == 0) {
                f->f0 = 4;
            } else {
                f->f0 = 2;
            }
            break;
        case 3:
            if (f->tbl->f2C(f, &hdr, src, f->tbl) == 0) {
                TLobby__sub_80405304(f->f10);
                f->tbl->f1C(f, f->tbl);
                f->f0 = 5;
                lbl_805D7AA0++;
            } else {
                TLobby__sub_80405328(f->f10);
            }
            break;
        case 0:
            TLobby__sub_803FE6CC(f, 6, hdr.flag, NULL);
            break;
        case 6:
            break;
        }
        break;
    case 2:
        switch (f->f0) {
        case 2:
            if (f->tbl->f30(f, &hdr, src, f->tbl) == 0) {
                f->f0 = 3;
            }
            break;
        case 4:
            if (f->tbl->f30(f, &hdr, src, f->tbl) == 0) {
                TLobby__sub_80405304(f->f10);
                f->tbl->f1C(f, f->tbl);
                f->f0 = 5;
                lbl_805D7AA0++;
            }
            break;
        case 5:
            f->tbl->f20(f, f->tbl);
            f->tbl->f18(f, f->tbl);
            TLobby__sub_803FE600(f);
        case 3:
            TLobby__sub_803FE658(f);
            f->f0 = 2;
            break;
        case 0:
        case 1:
            TLobby__sub_803FE6CC(f, 6, hdr.flag, NULL);
            break;
        case 6:
            break;
        }
        break;
    case 3:
        switch (f->f0) {
        case 2:
        case 4:
            if (f->tbl->f34(f, &hdr, src, f->tbl) == 0) {
                TLobby__sub_803FE658(f);
            }
            break;
        case 5:
            f->tbl->f20(f, f->tbl);
            f->tbl->f18(f, f->tbl);
            TLobby__sub_803FE600(f);
        case 3:
            TLobby__sub_803FE658(f);
            f->f0 = 2;
            break;
        case 0:
        case 1:
            TLobby__sub_803FE6CC(f, 6, hdr.flag, NULL);
            break;
        case 6:
            break;
        }
        break;
    case 4:
        switch (f->f0) {
        case 2:
        case 4:
            if (f->tbl->f38(f, &hdr, src, f->tbl) == 0) {
                TLobby__sub_803FE658(f);
            }
            break;
        case 5:
            f->tbl->f20(f, f->tbl);
            f->tbl->f18(f, f->tbl);
            TLobby__sub_803FE600(f);
        case 3:
            TLobby__sub_803FE658(f);
            f->f0 = 2;
            break;
        case 0:
        case 1:
            TLobby__sub_803FE6CC(f, 6, hdr.flag, NULL);
            break;
        case 6:
            break;
        }
        break;
    case 5:
        switch (f->f0) {
        case 5:
            TLobby__sub_803FE6CC(f, 6, hdr.flag, NULL);
            f->tbl->f20(f, f->tbl);
            f->tbl->f24(f, f->tbl);
            TLobby__sub_803FE600(f);
            break;
        case 3:
        case 4:
            f->f0 = 2;
        case 0:
        case 1:
        case 2:
        case 6:
            TLobby__sub_803FE6CC(f, 6, hdr.flag, NULL);
            break;
        }
        break;
    case 6:
        switch (f->f0) {
        case 6:
            TLobby__sub_80405304(f->f10);
            f->tbl->f24(f, f->tbl);
            TLobby__sub_803FE600(f);
            break;
        case 5:
            f->tbl->f20(f, f->tbl);
            TLobby__sub_803FE600(f);
            if (TLobby__sub_803FE658(f) == 0) {
                f->f0 = 2;
            }
            break;
        case 3:
        case 4:
            f->f0 = 2;
            break;
        }
        break;
    case 7:
        f->tbl->f24(f, f->tbl);
        TLobby__sub_803FE600(f);
        break;
    case 9:
        switch (f->f0) {
        case 2:
        case 3:
        case 4:
        case 6:
            break;
        case 5:
            TLobby__sub_803FE6CC(f, 10, hdr.flag, src);
            break;
        case 0:
        case 1:
            TLobby__sub_803FE6CC(f, 6, hdr.flag, NULL);
            break;
        }
        break;
    case 8:
    case 10:
    case 11:
    case 12:
        break;
    default:
        hdr.len += 4;
        src = fsm_prepend_header(src, &hdr);
        TLobby__sub_803FE6CC(f, 7, hdr.flag, src);
        switch (f->f0) {
        case 6:
            break;
        case 2:
        case 3:
        case 4:
        case 5:
            f->f0 = 1;
            break;
        }
        break;
    }
}

struct Link_803FE6CC { u8 f0; u8 next_id; u8 pad2[0x116]; s16 sent[1]; };
struct Opts_803FE6CC { u8 pad0[0x28]; u32 magic; };
s16 TLobby__sub_80406624(s32, s32, u16, B_803FADA0 *);
s16 TLobby__sub_803FE6CC(void *arg0, u8 code, u8 id, B_803FADA0 *buf) {
    Self_803FC318 *fsm = (Self_803FC318 *)arg0;
    Link_803FE6CC *link = (Link_803FE6CC *)fsm->sub;
    Hdr_803FC4B4 hdr;

    if (buf == NULL) {
        buf = lbl_805C04A8.f1C;
        buf->buf = (u8 *)lbl_805C04A8.f1C + ((lbl_805C04A8.value + 0x83) & ~3);
        buf->len = 0;
    }
    switch (code) {
    case 1:
    case 5:
    case 9:
        fsm->f1 = link->next_id;
    case 8:
    case 11:
        hdr.flag = link->next_id++;
        break;
    case 2:
    case 3:
    case 4:
    case 6:
    case 7:
    case 10:
        hdr.flag = id;
        break;
    default:
        return -1;
    }
    switch (code) {
    case 9:
    case 10:
    case 11:
        write_network_u32_be(buf->buf, ((Opts_803FE6CC *)fsm->opts)->magic);
        break;
    }
    hdr.type = code;
    hdr.len = ((TLobby *)buf)->get_field_4() + 4;
    buf = fsm_prepend_header(buf, &hdr);
    if (buf == NULL) {
        return -1;
    }
    link->sent[fsm->proto->b8]++;
    return TLobby__sub_80406624(0, 0, fsm->proto->proto, buf);
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

s32 TLobby::read_2_bytes(void *src) {
    u8 *dst = (u8 *)this;
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

u32 TLobby__sub_803FE9F8(u32 sum, B_803FADA0 *b, u16 n);

u16 TLobby__sub_803FE934(u8 *hdr, B_803FADA0 *b, u16 n) {
    u32 sum = 0;
    int i;

    if (hdr != NULL) {
        for (i = 0; i < 12; i += 2) {
            sum += *hdr++ << 8;
            sum += *hdr++;
        }
    }
    sum = TLobby__sub_803FE9F8(sum, b, n);
    sum = (sum >> 16) + (sum & 0xFFFF);
    sum += sum >> 16;
    return ~sum;
}

u32 TLobby__sub_803FE9F8(u32 sum, B_803FADA0 *b, u16 n) {
    u16 last;
    s32 odd;
    s16 len;
    u8 *p = b->buf;

    len = (b->len < n) ? b->len : n;
    if (len & 1) {
        last = p[len - 1];
        odd = 1;
        len--;
    } else {
        odd = 0;
        last = 0;
    }
    for (len = len >> 1; len > 0; len--) {
        sum += p[0] << 8;
        sum += p[1];
        p += 2;
    }
    if (odd) {
        sum += last << 8;
    }
    return sum;
}

typedef struct A_80403F4C {
    u32 src;
    u32 dst;
    u16 len;
    u16 id;
    u16 frag;
    u16 cksum;
    u8 pad10;
    u8 df;
    u8 mf;
    u8 version;
    u8 tos;
    u8 ttl;
    u8 count;
    u8 optlen;
    u8 opts[0x40 - 0x18];
} A_80403F4C;

struct IpHdr_803FEA88 { u8 ver_ihl; u8 tos; u16 len; u16 id; u16 frag; u8 ttl; u8 proto; u16 cksum; u32 src; u32 dst; };

u32 TLobby__sub_803FEA88(A_80403F4C *out, Strm_80405A74 **src) {
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
    out->count = h.proto;
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


s16 TLobby__sub_803FED78(u8 *conn) {
    Conn_804004DC *v6;
    Conn_804004DC *c;
    RecoveredGlobal_804050DC_lbl_805C18A0 *g;
    u8 *sub;
    s16 status;
    s16 st;
    c = (Conn_804004DC *)conn;
    status = 1;
    sub = c->sub;
    c->abort = 0;
    {
        u8 *p = lbl_805C0038 + 0xD4;
        ((Conn_804004DC *)p)->abort = 0;
        v6 = (Conn_804004DC *)p;
    }
    g = &lbl_805C18A0;
    while (c->state != 5 && lbl_805D7AA0 < 2) {
        if (TLobby::is_timed_out() != 0 || *sub == 4) {
            TLobby::update_connection_state((int)c);
            c->abort = 0;
            v6->abort = 0;
            return -1;
        }
        if (c->abort != 0) {
            break;
        }
        status = ((TLobby *)v6)->check_connection_status();
        TUdpSocket::unlock_mutex(g->value);
        TLobby__sub_803F97E8(100);
        TLobby::process_expired_timers();
        TLobby::lock_mutex(g->value);
    }
    st = lbl_805D7A7C;
    if (st != 6 && st != 0) {
        if (c->abort != 0) {
            v6->abort = 0;
            c->abort = 0;
            return -1;
        }
        v6->abort = 0;
        c->abort = 0;
        return 0;
    }
    g = &lbl_805C18A0;
    while (status > 0) {
        status = ((TLobby *)v6)->check_connection_status();
        TUdpSocket::unlock_mutex(g->value);
        TLobby__sub_803F97E8(100);
        TLobby::process_expired_timers();
        TLobby::lock_mutex(g->value);
    }
    switch (status) {
    case 0:
        c->abort = 0;
        v6->abort = 0;
        return 0;
    case -2:
        if (c->abort == 0) {
            c->abort = 0;
            v6->abort = 0;
            return 0;
        }
        break;
    case -1:
        break;
    }
    TLobby::update_connection_state((int)c);
    v6->abort = 0;
    c->abort = 0;
    return -1;
}

struct Blk_803FF48C { s32 w[9]; };
struct IpcpEntry_803FEF4C;
struct P_803FF48C;
struct IpcpProto_803FEF4C {
    const char *name;
    u16 proto;
    u16 h6;
    u8 b8;
    u8 b9;
    u8 bA;
    u8 bB;
    s32 timeout;
    void (*f10)(IpcpEntry_803FEF4C *);
    void (*f14)(P_803FF48C *);
    void (*f18)(u8 *);
    void (*f1C)(u8 *);
    void (*f20)(IpcpEntry_803FEF4C *);
    void (*f24)(s32);
    B_803FADA0 *(*f28)(Self_803FD74C *);
    s16 (*f2C)(Obj_803FA664 *, Msg_803FA664 *, u32);
    s32 (*f30)(Obj_803FA664 *, Msg_803FA664 *, u32);
    s32 (*f34)(Obj_803FA664 *, Msg_803FA664 *, u32);
    s32 (*f38)(Obj_803FA664 *, Msg_803FA664 *, u32);
};

struct IpcpSide_803FEF4C {
    s16 mask;
    u8 pad2[2];
    Blk_803FF48C a;
    Blk_803FF48C b;
};

struct IpcpOpts_803FEF4C {
    IpcpSide_803FEF4C local;
    IpcpSide_803FEF4C remote;
    u32 list;
};

struct IpcpEntry_803FEF4C {
    u8 pad0[0xC];
    u8 *sub;
    u8 pad10[0x2C - 0x10];
    IpcpProto_803FEF4C *proto;
    IpcpOpts_803FEF4C *opts;
};

struct IpcpState_803FEF4C {
    IpcpProto_803FEF4C proto;
    IpcpOpts_803FEF4C opts;
};

extern IpcpState_803FEF4C lbl_805C0328;
extern const char lbl_805E1170[5];
extern const Blk_803FF48C lbl_8047FE18;
void free_field_98(IpcpEntry_803FEF4C *fsm);
void free_field_98_and_clear(IpcpEntry_803FEF4C *fsm);
void TLobby__sub_803FF48C(P_803FF48C *o);
B_803FADA0 *TLobby__sub_80400174(Self_803FD74C *fsm);
s16 TLobby__sub_803FF9A4(Obj_803FA664 *fsm, Msg_803FA664 *msg, u32 src);
s32 TLobby__sub_803FF698(Obj_803FA664 *fsm, Msg_803FA664 *msg, u32 src);
s32 TLobby__sub_803FF50C(Obj_803FA664 *fsm, Msg_803FA664 *msg, u32 src);

#pragma push
#pragma opt_propagation off
void TLobby__sub_803FEF4C(u8 *conn) {
    const Blk_803FF48C *tbl = &lbl_8047FE18;
    IpcpProto_803FEF4C *proto = &lbl_805C0328.proto;
    IpcpEntry_803FEF4C *e = (IpcpEntry_803FEF4C *)(conn + 0x6C);
    IpcpOpts_803FEF4C *area = &lbl_805C0328.opts;
    proto->name = lbl_805E1170;
    proto->proto = 0x8021;
    proto->h6 = 0xFE;
    proto->b8 = 2;
    proto->b9 = 20;
    proto->bA = 10;
    proto->bB = 10;
    proto->timeout = 3000;
    proto->f10 = free_field_98;
    proto->f14 = TLobby__sub_803FF48C;
    proto->f18 = TLobby__sub_803FF374;
    proto->f1C = TLobby__sub_803FF384;
    proto->f20 = free_field_98_and_clear;
    proto->f24 = TLobby__sub_803FF468;
    proto->f28 = TLobby__sub_80400174;
    proto->f2C = TLobby__sub_803FF9A4;
    proto->f30 = TLobby__sub_803FF858;
    proto->f34 = TLobby__sub_803FF698;
    proto->f38 = TLobby__sub_803FF50C;
    e->sub = conn;
    e->proto = proto;
    e->opts = area;
    area->local.a = *tbl;
    area->local.mask = 6;
    area->remote.a = *tbl;
    area->remote.b = *tbl;
    area->remote.mask = 6;
    TLobby__sub_803FD694((u8 *)e);
}
#pragma pop

s32 set_socket_flags_by_mode__6TLobbyFsPv(s16 arg0, u8 *arg1) {
    struct Fields_arg1 { s16 field_0; u8 pad_2[2]; s16 field_4; u8 pad_6[10]; s16 field_10; s16 field_12; s8 field_14; u8 pad_15[19]; s16 field_28; };
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

s32 set_target_index__6TLobbyFPvi(u8 *arg0, s32 arg1) {
    if (arg1 == -1) {
        *(s32 *)((s8 *)arg0 + 0x1C) = 0;
        *(s16 *)((s8 *)arg0 + 4) = (s16) (*(s16 *)((s8 *)arg0 + 4) & 0xFFFFF7FF);
    } else {
        *(s32 *)((s8 *)arg0 + 0x1C) = arg1;
        *(s16 *)((s8 *)arg0 + 4) = (s16) (*(s16 *)((s8 *)arg0 + 4) | 0x800);
    }
    return 0;
}

s32 set_filter_index__6TLobbyFPvi(u8 *arg0, s32 arg1) {
    if (arg1 == -1) {
        *(s32 *)((s8 *)arg0 + 0x18) = 0;
        *(s16 *)((s8 *)arg0 + 4) = (s16) (*(s16 *)((s8 *)arg0 + 4) & 0xFFFFFDFF);
    } else {
        *(s32 *)((s8 *)arg0 + 0x18) = arg1;
        *(s16 *)((s8 *)arg0 + 4) = (s16) (*(s16 *)((s8 *)arg0 + 4) | 0x200);
    }
    return 0;
}

s32 set_filter_id__6TLobbyFPvi(u8 *arg0, s32 arg1) {
    if (arg1 == -1) {
        *(s32 *)((s8 *)arg0 + 0x1C) = 0;
        *(s16 *)((s8 *)arg0 + 4) = (s16) (*(s16 *)((s8 *)arg0 + 4) & 0xFFFFF7FF);
    } else {
        *(s32 *)((s8 *)arg0 + 0x1C) = arg1;
        *(s16 *)((s8 *)arg0 + 4) = (s16) (*(s16 *)((s8 *)arg0 + 4) | 0x800);
    }
    return 0;
}

s32 set_target_slot__6TLobbyFPvi(u8 *arg0, s32 arg1) {
    if (arg1 == -1) {
        *(s32 *)((s8 *)arg0 + 0x18) = 0;
        *(s16 *)((s8 *)arg0 + 4) = (s16) (*(s16 *)((s8 *)arg0 + 4) & 0xFFFFFDFF);
    } else {
        *(s32 *)((s8 *)arg0 + 0x18) = arg1;
        *(s16 *)((s8 *)arg0 + 4) = (s16) (*(s16 *)((s8 *)arg0 + 4) | 0x200);
    }
    return 0;
}

s32 set_target_id__6TLobbyFPvi(u8 *arg0, s32 arg1) {
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
    struct Fields_arg0 { u8 pad_0[12]; u8 * field_C; };
    ((TLobby *)lobby)->set_flags_and_state();
    if ((u8) *((Fields_arg0*)lobby)->field_C == 3) {
        TLobby__sub_803FD958((u8 *)(lobby));
    }
    return 0;
}

void free_field_98(IpcpEntry_803FEF4C *fsm) {
    TLobby__sub_80405000(fsm->opts->list);
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
        *(s32 *)((s8 *)p + 0x98) = TLobby::init_net_list(a, b);
    }
    TLobby__sub_80405304(arg0 + 0x10);
    *(s8 *)((s8 *)arg0 + 0) = 5;
}

void free_field_98_and_clear(IpcpEntry_803FEF4C *fsm) {
    IpcpOpts_803FEF4C *opts = fsm->opts;
    TLobby__sub_80405000(opts->list);
    opts->list = 0;
}

void TLobby__sub_803FF468(s32 arg0) {
    TLobby__sub_80405304((void *)((void *) (arg0 + 0x10)));
}

union U_803FF48C { s16 h4; Blk_803FF48C src; };
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

struct Opt_80400338 { s16 mask; u8 pad2[2]; u32 f4; u32 f8; s16 fC; s16 fE; u8 f10; u8 pad11[3]; u32 f14; u32 f18; };

s16 TLobby__sub_803FFB84(u32 *src, Sub_803FA664 *opts, Sub_803FA664 *peer, u8 *hdr, s32 reply);

#pragma push
#pragma opt_common_subs on
#pragma dont_inline off
#pragma inline_depth(4)
inline s32 ipcp_is_extended_option(u8 type) {
    s32 result = 0;
    if (type >= 0x80 && type < 0x90) {
        result = 1;
    }
    return result;
}

inline s32 ipcp_option_bit(u8 type) {
    if (type < 8) {
        return type;
    }
    if (ipcp_is_extended_option(type)) {
        return type - 120;
    }
    return 0;
}

inline s32 ipcp_read_byte(u32 *src) {
    if (TLobby__sub_80401BCC(src, &lcp_read_byte_buffer, 1) != 1) {
        return -1;
    }
    return (s16)lcp_read_byte_buffer;
}

s32 TLobby__sub_803FF50C(Obj_803FA664 *fsm, Msg_803FA664 *msg, u32 src) {
    Sub_803FA664 *opts = fsm->p30;
    Sub_803FA664 *peer = opts;
    s32 remaining = msg->h2;
    u8 hdr[2];
    s16 n;
    if (msg->b1 != fsm->b1) {
        return -1;
    }
    while (remaining > 0 && (s16)((TLobby *)hdr)->read_2_bytes(&src) != -1) {
        remaining -= hdr[1];
        if (remaining < 0) {
            return -1;
        }
        if ((opts->h1C & (1 << ipcp_option_bit(hdr[0]))) == 0) {
            return -1;
        }
        n = hdr[1] - 2;
        while (n-- > 0) {
            if (ipcp_read_byte(&src) == -1) {
                return -1;
            }
        }
        opts->h1C &= ~(1 << ipcp_option_bit(hdr[0]));
    }
    return 0;
}

s32 TLobby__sub_803FF698(Obj_803FA664 *fsm, Msg_803FA664 *msg, u32 src) {
    Sub_803FA664 *opts = fsm->p30;
    Sub_803FA664 *peer = opts;
    s32 remaining = msg->h2;
    u8 hdr[2];
    s16 r;
    if (msg->b1 != fsm->b1) {
        return -1;
    }
    while (remaining > 0 && (s16)((TLobby *)hdr)->read_2_bytes(&src) != -1) {
        remaining -= hdr[1];
        if (remaining < 0) {
            return -1;
        }
        if ((opts->h1C & (1 << ipcp_option_bit(hdr[0]))) == 0) {
            opts->h1C |= 1 << ipcp_option_bit(hdr[0]);
        }
        r = TLobby__sub_803FFB84(&src, opts, peer, hdr, 0);
        if (r == -1) {
            return -1;
        }
        if (r == 4) {
            opts->h1C &= ~(1 << ipcp_option_bit(hdr[0]));
        }
    }
    return 0;
}
#pragma pop


#pragma push
#pragma opt_lifetimes off
#pragma opt_dead_assignments off
#pragma push
#pragma dont_inline off
#pragma inline_depth(4)
inline u32 first_803FA664(Sub_803FA664 *s) {
    u32 t;
    u32 v = 0;
    t = v;
    t = ((u32)init_net_buffer_entry__6TLobbyFUs((u16)(0)));
    if (t == 0) {
        return v;
    }
    TLobby__sub_80400270((B_803FADA0 **)&t, (Opt_80400338 *)&s->h1C, s->h1C);
    v = t;
    return v;
}
inline s32 read_803FA664(u32 *p) {
    if (TLobby__sub_80401BCC(p, &lcp_read_byte_buffer, 1) != 1) {
        return -1;
    }
    return (s16)lcp_read_byte_buffer;
}
s32 TLobby__sub_803FF858(Obj_803FA664 *arg0, Msg_803FA664 *arg1, u32 arg2) {
    s16 err;
    s16 a;
    s16 b;
    err = 0;
    if (arg1->b1 != arg0->b1) {
        return -1;
    }
    u32 cur = first_803FA664(arg0->p30);
    if (arg1->h2 != ((TLobby *)cur)->get_field_4()) {
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

struct IpcpOpts_80400174 { u8 pad[0x28]; Opt_80400338 vals; };
void TLobby__sub_80400338(B_803FADA0 **pbuf, Opt_80400338 *opt, s32 type, s32 len, void *src);

#pragma push
#pragma opt_common_subs on
#pragma bool off
#pragma dont_inline off
#pragma inline_depth(4)
s16 TLobby__sub_803FF9A4(Obj_803FA664 *fsm, Msg_803FA664 *msg, u32 src) {
    Sub_803FA664 *opts;
    s32 remaining;
    s16 status;
    s16 r;
    B_803FADA0 *reply;
    u8 hdr[2];
    status = 2;
    opts = fsm->p30;
    remaining = msg->h2;
    reply = NULL;
    opts->h74 = 0;
    while (remaining > 0 && (s16)((TLobby *)hdr)->read_2_bytes(&src) != -1) {
        remaining -= hdr[1];
        if (remaining < 0) {
            return -1;
        }
        r = TLobby__sub_803FFB84(&src, opts, (Sub_803FA664 *)opts->peer, hdr, 1);
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
        if (r != 4) {
            opts->h74 |= 1 << ipcp_option_bit(hdr[0]);
        }
        TLobby__sub_80400338(&reply, (Opt_80400338 *)&opts->h74, hdr[0], hdr[1], &src);
        if (r > 3) {
            TLobby__sub_803FE6CC(fsm, status, msg->b1, reply);
        }
    }
    if (status == 3) {
        if (fsm->b6 != 0) {
            fsm->b6--;
        } else {
            status = 4;
            TLobby__sub_803FE6CC(fsm, 4, msg->b1, reply);
        }
    }
    if (status > 3) {
        return status != 2;
    }
    TLobby__sub_803FE6CC(fsm, status, msg->b1, reply);
    return status != 2;
}
#pragma pop


#pragma push
#pragma dont_inline off
#pragma inline_depth(4)
inline void add_ipcp_options(B_803FADA0 **pbuf, Opt_80400338 *opt, s16 mask) {
    s16 i;
    s32 type = 0;

    if (*pbuf == NULL) {
        *pbuf = init_net_buffer_entry__6TLobbyFUs(type);
        if (*pbuf == NULL) {
            return;
        }
    }
    for (i = 1; i < 32; i++) {
        type = i;
        if (mask & (1 << type)) {
            type = (type < 8) ? type : (type < 32) ? type + 0x78 : 0;
            TLobby__sub_80400338(pbuf, opt, type, lbl_8047FE3C[i], NULL);
        }
    }
}

B_803FADA0 *TLobby__sub_80400174(Self_803FD74C *fsm) {
    IpcpOpts_80400174 *o = (IpcpOpts_80400174 *)fsm->f30;
    B_803FADA0 *buf = NULL;

    buf = init_net_buffer_entry__6TLobbyFUs(0);
    if (buf == NULL) {
        return NULL;
    }
    add_ipcp_options(&buf, &o->vals, o->vals.mask);
    return buf;
}
#pragma pop

void TLobby__sub_80400270(B_803FADA0 **pbuf, Opt_80400338 *opt, s16 mask) {
    s16 i;
    s32 type = 0;

    if (*pbuf == NULL) {
        *pbuf = init_net_buffer_entry__6TLobbyFUs(type);
        if (*pbuf == NULL) {
            return;
        }
    }
    for (i = 1; i < 32; i++) {
        type = i;
        if (mask & (1 << type)) {
            type = (type < 8) ? type : (type < 32) ? type + 0x78 : 0;
            TLobby__sub_80400338(pbuf, opt, type, lbl_8047FE3C[i], NULL);
        }
    }
}

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
        buf = init_net_buffer_entry__6TLobbyFUs(0);
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

s32 wait_for_connection__6TLobbyFPv(Conn_804004DC *c) {
    RecoveredGlobal_804050DC_lbl_805C18A0 *g;
    u8 *sub;
    sub = c->sub;
    g = &lbl_805C18A0;
    c->abort = 0;
    while (c->state != 5) {
        if (TLobby::is_timed_out() != 0 || c->abort != 0 || *sub == 4) {
            TLobby::update_connection_state((int)c);
            c->abort = 0;
            return -1;
        }
        TUdpSocket::unlock_mutex(g->value);
        TLobby__sub_803F97E8(100);
        TLobby::process_expired_timers();
        TLobby::lock_mutex(g->value);
    }
    c->abort = 0;
    return 0;
}

struct LcpEntry_8040059C;
struct LcpProto_8040059C {
    const char *name;
    u16 proto;
    u16 h6;
    u8 b8;
    u8 b9;
    u8 bA;
    u8 bB;
    s32 timeout;
    void (*f10)(void);
    void (*f14)(LcpEntry_8040059C *);
    void (*f18)(u8 *);
    void (*f1C)(Self_8040098C *);
    void (*f20)(LcpEntry_8040059C *);
    void (*f24)(void);
    B_803FADA0 *(*f28)(Self_803FD74C *);
    s16 (*f2C)(Obj_803FA664 *, Msg_803FA664 *, u32);
    s32 (*f30)(Obj_803FA664 *, Msg_803FA664 *, u32);
    s32 (*f34)(Obj_803FA664 *, Msg_803FA664 *, u32);
    s32 (*f38)(Obj_803FA664 *, Msg_803FA664 *, u32);
};

struct LcpVals_8040172C { s16 mask; u16 mru; u32 accm; u16 auth_proto; u8 pad0A[2]; u32 magic; u8 pad10[4]; u8 chap_alg; };

struct LcpSide_8040059C {
    s16 mask;
    u8 pad2[2];
    LcpVals_8040172C want;
    LcpVals_8040172C got;
};

struct LcpOpts_8040059C {
    LcpSide_8040059C local;
    LcpSide_8040059C remote;
};

struct LcpEntry_8040059C {
    u8 pad0[0xC];
    u8 *sub;
    u8 pad10[0x2C - 0x10];
    LcpProto_8040059C *proto;
    LcpOpts_8040059C *opts;
};

struct LcpState_8040059C {
    LcpProto_8040059C proto;
    LcpOpts_8040059C opts;
    u8 pad_a4[4];
};

extern LcpState_8040059C lbl_805C0400;
extern const char lbl_805E1178[4];
extern const LcpVals_8040172C lbl_8047FE50;
void save_timer_state(LcpEntry_8040059C *fsm);
void reset_connection_slot(LcpEntry_8040059C *fsm);
B_803FADA0 *TLobby__sub_8040172C(Self_803FD74C *fsm);
s16 TLobby__sub_804010A0(Obj_803FA664 *fsm, Msg_803FA664 *msg, u32 src);
s32 TLobby__sub_80400F1C(Obj_803FA664 *fsm, Msg_803FA664 *msg, u32 src);
s32 TLobby__sub_80400DA8(Obj_803FA664 *fsm, Msg_803FA664 *msg, u32 src);
s32 TLobby__sub_80400C4C(Obj_803FA664 *fsm, Msg_803FA664 *msg, u32 src);

#pragma push
#pragma opt_propagation off
void TLobby__sub_8040059C(u8 *conn) {
    LcpProto_8040059C *proto = &lbl_805C0400.proto;
    LcpEntry_8040059C *e = (LcpEntry_8040059C *)(conn + 4);
    LcpOpts_8040059C *area = &lbl_805C0400.opts;
    const LcpVals_8040172C *tbl = &lbl_8047FE50;
    proto->name = lbl_805E1178;
    proto->proto = 0xC021;
    proto->h6 = 0xFFE;
    proto->b8 = 0;
    proto->b9 = 20;
    proto->bA = 10;
    proto->bB = 3;
    proto->timeout = 1000;
    proto->f10 = TLobby__sub_80400988;
    proto->f14 = save_timer_state;
    proto->f18 = TLobby__sub_80400B98;
    proto->f1C = TLobby__sub_8040098C;
    proto->f20 = reset_connection_slot;
    proto->f24 = TLobby::queue_command_81;
    proto->f28 = TLobby__sub_8040172C;
    proto->f2C = TLobby__sub_804010A0;
    proto->f30 = TLobby__sub_80400F1C;
    proto->f34 = TLobby__sub_80400DA8;
    proto->f38 = TLobby__sub_80400C4C;
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
#pragma pop

struct LcpCfg_80400744 {
    u32 accm;
    s16 f4;
    s16 auth;
    u32 magic;
    u16 mru;
    s16 fE;
};

s16 TLobby__sub_80400744(LcpEntry_8040059C *fsm, LcpCfg_80400744 *cfg) {
    LcpOpts_8040059C *opts;
    LcpSide_8040059C *ho;
    u16 auth;

    TLobby__sub_803FE600((Self_803FD85C *)fsm);
    ((TLobby *)fsm)->set_flags_and_state();
    *fsm->sub = 1;
    if (*fsm->sub >= 1) {
        opts = fsm->opts;
        if ((s16)cfg->mru >= 0x80 && (s16)cfg->mru <= 0x1000) {
            opts->local.want.mask |= 2;
            opts->local.want.mru = cfg->mru;
        }
        opts->local.want.accm = cfg->accm;
        if (opts->local.want.accm != 0xFFFFFFFF) {
            opts->local.want.mask |= 4;
            opts->local.mask |= 4;
        } else {
            opts->local.want.mask &= ~4;
            opts->local.mask &= ~4;
        }
        auth = cfg->auth;
        if ((auth & 0x80) || auth == 4) {
            ((TLobby *)&opts->remote)->configure_mode_by_type(auth & 0x7F);
            if (lbl_805D7A90 & 2) {
                ((TLobby *)&opts->local)->configure_mode_by_type(cfg->auth & 0x7F);
            }
        } else {
            ((TLobby *)&opts->remote)->configure_mode_by_type(auth);
            ((TLobby *)&opts->local)->configure_mode_by_type(cfg->auth);
        }
        if (cfg->magic != 0) {
            opts->local.want.mask |= 0x20;
        } else {
            opts->local.want.mask &= ~0x20;
        }
        opts->local.want.magic = cfg->magic;
        if (cfg->fE == 0) {
            opts->local.mask |= 0x80;
        } else {
            opts->local.mask &= ~0x80;
        }
        if (cfg->f4 == 0) {
            opts->local.mask |= 0x100;
        } else {
            opts->local.mask &= ~0x100;
        }
        ho = &opts->remote;
        if (cfg->magic != 0) {
            ho->want.mask |= 0x20;
        } else {
            ho->want.mask &= ~0x20;
        }
        ho->want.magic = cfg->magic;
        if (cfg->fE == 0) {
            ho->mask |= 0x80;
        } else {
            ho->mask &= ~0x80;
        }
        if (cfg->f4 == 0) {
            ho->mask |= 0x100;
        } else {
            ho->mask &= ~0x100;
        }
        TLobby__sub_803FD958((u8 *)fsm);
    }
    return 0;
}

void TLobby__sub_80400988(void) {

}

void TLobby__sub_8040098C(Self_8040098C *self) {
    Info_8040098C *info = self->info;
    St_8040098C *st;
    u32 now;

    self->st->f0 = 2;
    self->st->f2 &= ~0x30;
    self->st->f10C = 0;
    if (info->f1C & 8) {
        switch (info->f24) {
        case 0xC023:
            ((TLobby *)((u8 *)self->st))->set_active();
            break;
        case 0xC223:
            ((TLobby *)((Obj_803FC480 *)self->st))->mark_sub_ready();
            ((TLobby *)((u8 *)self->st))->set_active_flag();
            break;
        }
    }
    if (info->f50 & 8) {
        switch (info->f58) {
        case 0xC023:
            ((TLobby *)((u8 *)self->st))->mark_ready();
            break;
        case 0xC223:
            ((TLobby *)((u8 *)self->st))->set_active_flag();
            ((TLobby *)((Obj_803FC480 *)self->st))->mark_sub_ready();
            break;
        }
    }
    st = self->st;
    if (!(st->f2 & 0x30)) {
        st->f0 = 3;
        TLobby::get_time_ms((s32 *)&now);
        st->f108 = (s16)(now / 1000);
        TLobby__sub_803FD958(st->f6C);
    }
}

struct O_80400ACC { u8 b0; u8 b1; u8 b2; u8 pad3[0x108 - 3]; s32 f108; };
void TLobby__sub_80400ACC(O_80400ACC *o) {
    u32 t;
    if ((o->b2 & 0x30) == 0) {
        o->b0 = 3;
        TLobby::get_time_ms((s32 *)&t);
        o->f108 = (s16)(t / 1000);
        TLobby__sub_803FD958((u8 *)o + 0x6C);
    }
}

void reset_connection_slot(LcpEntry_8040059C *fsm) {
    u8 *conn = fsm->sub;
    *conn = 4;
    TLobby__sub_803FD85C(conn + 0x6C);
    ((TLobby *)(conn + 0x38))->reset_connection_state();
}

void TLobby::queue_command_81() {
    TLobby__sub_804062A0(0x81);
}

void TLobby__sub_80400B98(u8 *arg0) {
    **(s8 **)((s8 *)arg0 + 0xC) = 1;
}

typedef char RecoveredGlobal_80401A68_lbl_805C04A8_size[sizeof(RecoveredGlobal_80401A68_lbl_805C04A8) == 0x30 ? 1 : -1];

void save_timer_state(LcpEntry_8040059C *fsm) {
    St_80400BA8 *s;
    s32 t;
    s = (St_80400BA8 *)fsm->opts;
    if (s->cur.flags & 0x20) {
        TLobby::get_time_ms(&t);
        s->cur.time += t;
    }
    s->saved = s->cur;
    s->flags |= s->cur.flags;
    s->f50 = 0;
    s->f34 |= s->f38;
}

struct LcpOpts_8040172C { u8 pad[0x1C]; LcpVals_8040172C vals; };
extern u8 lbl_8047FE68[];
void TLobby__sub_804017D8(B_803FADA0 **pbuf, LcpVals_8040172C *vals, u8 type, u8 len, void *src);

inline void add_lcp_options(B_803FADA0 **pbuf, LcpVals_8040172C *vals, s16 mask) {
    s16 i;

    for (i = 1; i <= 8; i++) {
        if (mask & (1 << i)) {
            TLobby__sub_804017D8(pbuf, vals, i, lbl_8047FE68[i], NULL);
        }
    }
}

#pragma push
s32 TLobby__sub_80400C4C(Obj_803FA664 *fsm, Msg_803FA664 *msg, u32 src) {
    s16 last = 0;
    LcpOpts_8040172C *o = (LcpOpts_8040172C *)fsm->p30;
    s32 left = msg->h2;
    u8 opt[12];
    s16 n;
    u8 len;
    u8 type;

    if (msg->b1 != fsm->b1) {
        return -1;
    }
    while (left > 0 && (s16)((TLobby *)opt)->read_2_bytes(&src) != -1) {
        len = opt[1];
        left -= len;
        if (left < 0) {
            return -1;
        }
        if (opt[0] <= 8 && (opt[0] < last || !(o->vals.mask & (1 << opt[0])))) {
            return -1;
        }
        for (n = len - 2; n-- > 0;) {
            if ((TLobby__sub_80401BCC(&src, lobby_read_byte_buffer, 1) != 1 ? -1 : (s16)lobby_read_byte_buffer[0]) == -1) {
                return -1;
            }
        }
        last = type = opt[0];
        if (type <= 8 && (type != 3 || !(o->vals.mask & (1 << type)))) {
            o->vals.mask &= ~(1 << type);
        }
    }
    return 0;
}
#pragma pop

#pragma push
#pragma opt_common_subs on
s32 TLobby__sub_80400DA8(Obj_803FA664 *fsm, Msg_803FA664 *msg, u32 src) {
    St_80400BA8 *opts = (St_80400BA8 *)fsm->p30;
    St_80400BA8 *peer = opts;
    s32 remaining = msg->h2;
    s16 last = 0;
    u8 hdr[2];
    s16 r;
    if (msg->b1 != fsm->b1) {
        return -1;
    }
    while (remaining > 0 && (s16)((TLobby *)hdr)->read_2_bytes(&src) != -1) {
        remaining -= hdr[1];
        if (remaining < 0) {
            return -1;
        }
        if (hdr[0] <= 8) {
            if (hdr[0] < last || (opts->saved.flags & (1 << hdr[0])) == 0) {
                if (opts->saved.flags & (1 << hdr[0])) {
                    return -1;
                }
                opts->saved.flags |= 1 << hdr[0];
                last = 9;
            } else {
                last = hdr[0];
            }
        }
        r = TLobby::parse_lcp_option((s32)&src, (u8 *)opts, (u8 *)peer, hdr, 0);
        if (r == -1) {
            return -1;
        }
        if (r == 4 && hdr[0] <= 8 && (hdr[0] != 3 || (opts->saved.flags & (1 << hdr[0])) == 0)) {
            opts->saved.flags &= ~(1 << hdr[0]);
        }
    }
    return 0;
}
#pragma pop

#pragma push
#pragma dont_inline off
#pragma inline_depth(4)
inline u32 first_lcp_options(Obj_803FA664 *fsm) {
    LcpOpts_8040172C *o = (LcpOpts_8040172C *)fsm->p30;
    B_803FADA0 *t = NULL;
    t = init_net_buffer_entry__6TLobbyFUs(0);
    if (t == NULL) {
        return 0;
    }
    add_lcp_options(&t, &o->vals, o->vals.mask);
    return (u32)t;
}

inline s32 read_lcp_byte(u32 *p) {
    if (TLobby__sub_80401BCC(p, lobby_read_byte_buffer, 1) != 1) {
        return -1;
    }
    return (s16)lobby_read_byte_buffer[0];
}

s32 TLobby__sub_80400F1C(Obj_803FA664 *fsm, Msg_803FA664 *msg, u32 src) {
    s16 err;
    s16 a;
    s16 b;
    err = 0;
    if (msg->b1 != fsm->b1) {
        return -1;
    }
    u32 cur = first_lcp_options(fsm);
    if (msg->h2 != ((TLobby *)cur)->get_field_4()) {
        err = 1;
    } else {
        while ((a = read_lcp_byte(&cur)) != -1) {
            b = read_lcp_byte(&src);
            if (b == -1 || b != a) {
                err = 1;
                break;
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
#pragma opt_common_subs on
#pragma bool off
#pragma dont_inline off
#pragma inline_depth(4)
s16 TLobby__sub_804010A0(Obj_803FA664 *fsm, Msg_803FA664 *msg, u32 src) {
    St_80400BA8 *opts;
    s32 remaining;
    s16 status;
    s16 r;
    B_803FADA0 *reply;
    u8 hdr[2];
    status = 2;
    opts = (St_80400BA8 *)fsm->p30;
    remaining = msg->h2;
    reply = NULL;
    opts->f50 = 0;
    reply = init_net_buffer_entry__6TLobbyFUs(1);
    if (opts->f4D != 0) {
        opts->f58 = 0;
        opts->f50 |= 8;
    }
    while (remaining > 0 && (s16)((TLobby *)hdr)->read_2_bytes(&src) != -1) {
        remaining -= hdr[1];
        if (remaining < 0) {
            return -1;
        }
        r = TLobby::parse_lcp_option((s32)&src, (u8 *)opts, (u8 *)&opts->f34, hdr, 1);
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
            opts->f50 |= 1 << hdr[0];
        }
        TLobby__sub_804017D8(&reply, (LcpVals_8040172C *)&opts->f50, hdr[0], hdr[1], &src);
        if (r >= 3) {
            TLobby__sub_803FE6CC(fsm, status, msg->b1, reply);
        }
    }
    s16 missing = opts->f38 & ~opts->f50;
    if (status == 3) {
        if (fsm->b6 != 0) {
            add_lcp_options(&reply, (LcpVals_8040172C *)&opts->f50, missing);
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
s16 TLobby::parse_lcp_option(s32 arg0, u8 *arg1, u8 *arg2, u8 *arg3, s16 arg4) {
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
            TLobby::set_ppp_auth_protocol(F(u16, 0x24));
        }
        break;
    case 5:
        F(u32, 0x28) = rd32_804012E0(arg0);
        len -= 4;
        if (F(u32, 0x28) == 0 || *(u32 *)((s8 *)arg1 + 0x5C) == *(u32 *)((s8 *)arg1 + 0x28)) {
            TLobby::get_time_ms(&t);
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
B_803FADA0 *TLobby__sub_8040172C(Self_803FD74C *fsm) {
    LcpOpts_8040172C *o = (LcpOpts_8040172C *)fsm->f30;
    B_803FADA0 *buf = NULL;

    buf = init_net_buffer_entry__6TLobbyFUs(0);
    if (buf == NULL) {
        return NULL;
    }
    add_lcp_options(&buf, &o->vals, o->vals.mask);
    return buf;
}
#pragma pop

void TLobby__sub_804017D8(B_803FADA0 **pbuf, LcpVals_8040172C *vals, u8 type, u8 len, void *src) {
    B_803FADA0 *buf;
    u8 *p;
    u8 *lenp;
    s16 n;
    n = len - 2;
    if (*pbuf == NULL) {
        *pbuf = init_net_buffer_entry__6TLobbyFUs(1);
        if (*pbuf == NULL) {
            return;
        }
    }
    buf = *pbuf;
    p = buf->buf;
    p += buf->len;
    *p++ = type;
    lenp = p;
    *p++ = len;
    switch (type) {
    case 1:
        p = write_network_u16_be(p, vals->mru);
        n -= 2;
        break;
    case 2:
        p = write_network_u32_be(p, vals->accm);
        n -= 4;
        break;
    case 3:
        p = write_network_u16_be(p, vals->auth_proto);
        n -= 2;
        if (vals->auth_proto == 0xC223) {
            *lenp = 5;
            *p++ = vals->chap_alg;
            if (len == 4) {
                len++;
            }
            n = 0;
        }
        if (vals->auth_proto == 0xC023) {
            *lenp = 4;
            if (len == 5) {
                len--;
            }
            n = 0;
        }
        break;
    case 4:
        break;
    case 5:
        p = write_network_u32_be(p, vals->magic);
        n -= 4;
        break;
    case 6:
    case 7:
    case 8:
        break;
    }
    while (n-- > 0) {
        *p++ = TLobby__sub_80401BCC(src, lobby_read_byte_buffer, 1) != 1 ? -1 : (s16)lobby_read_byte_buffer[0];
    }
    buf->len += len;
}

s32 TLobby::configure_mode_by_type(s16 type) {
    Cfg_804019A8 *c = (Cfg_804019A8 *)this;
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

void TLobby::init_net_state_c() {
    TLobby__sub_803F79BC((void *) (&lbl_805C04A8.value));
}

typedef char RecoveredGlobal_80401A90_lbl_805C04A8_size[sizeof(RecoveredGlobal_80401A90_lbl_805C04A8) == 0x30 ? 1 : -1];
s32 TLobby::init_net_subsystem_block() {
    ((TLobby *)(&(*(RecoveredGlobal_80401A90_lbl_805C04A8 *)&lbl_805C04A8).value))->init_net_buffer_desc();
    return 0;
}

s16 TLobby__sub_80401ABC(B_803FADA0 *b, u8 *dst, u16 n) {
    s16 len;

    if (dst == NULL) {
        return 0;
    }
    len = (b->len < n) ? b->len : n;
    NetMemcpy(dst, b->buf, len);
    return len;
}

struct G_80401B20 { s32 f0; s32 f4; s32 f8; B_803FADA0 *pC; };
#pragma opt_propagation off
B_803FADA0 *TLobby__sub_80401B20(void *src, u16 n) {
    G_80401B20 *g = (G_80401B20 *)&lbl_805C04A8;
    B_803FADA0 *t = g->pC;
    B_803FADA0 *e;
    t->buf = (u8 *)t + ((g->f0 + 0x83) & ~3);
    e = t;
    NetMemcpy(e->buf, src, n);
    e->len = n;
    return e;
}
#pragma opt_propagation reset

u8 *TLobby::alloc_from_buffer(s16 arg1) {
    struct RecoveredFields_80401B8C_arg0 *arg0 = (struct RecoveredFields_80401B8C_arg0 *)this;
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

s16 TLobby__sub_80401BCC(void *src, void *dst, u16 n) {
    B_803FADA0 *e;
    B_803FADA0 **pp;
    s16 total;
    s16 len;
    u16 left;
    u8 *out;

    pp = (B_803FADA0 **)src;
    out = (u8 *)dst;
    left = n;
    total = 0;
    if (pp == NULL) {
        return 0;
    }
    while (left != 0 && (e = *pp) != NULL) {
        len = (left < e->len) ? left : e->len;
        if (out != NULL) {
            if (len == 1) {
                *out = *e->buf;
            } else if (len > 1) {
                NetMemcpy(out, e->buf, len);
            }
            out += len;
        }
        total += len;
        e->buf += len;
        left -= len;
        e->len -= len;
        if (e->len == 0) {
            left = 0;
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

u16 TLobby::get_field_4() {
    u8 *arg0 = (u8 *)this;
    return *(u16 *)((s8 *)arg0 + 4);
}

struct G_80401CE8 { s32 f0; u8 *f4; u8 pad8[2]; s16 hA; };
#pragma push
#pragma opt_propagation off
Ent_80401CE8 *init_net_buffer_entry__6TLobbyFUs(u16 idx) {
  G_80401CE8 *g = (G_80401CE8 *)&lbl_805C04A8;
  Ent_80401CE8 *t = (Ent_80401CE8 *) (g->f4 + ((idx * g->hA) * ((((4 & 0xFFFFFFFFu) & 0xFFFFFFFFu) & 0xFFFFFFFFu) & 0xFFFFFFFFu)));
  Ent_80401CE8 *e;
  e = (Ent_80401CE8 *) (g->f4 + ((idx * g->hA) * ((((4 & 0xFFFFFFFFu) & 0xFFFFFFFFu) & 0xFFFFFFFFu) & 0xFFFFFFFFu)));
  e->buf = ((u8 *) t) + ((g->f0 + 0x83) & (~3));
  e->len = 0xFFFFFFFFu * 0;
  return e;
  e = t;
}
#pragma pop


extern u8 lbl_8047FE78[];

#pragma push
#pragma dont_inline off
#pragma inline_depth(4)
inline void Encode_80401D2C(u8 *output, u32 *input, u32 len) {
    u32 i, j;
    for (i = 0, j = 0; j < len; i++, j += 4) {
        output[j] = (u8)(input[i] & 0xFF);
        output[j + 1] = (u8)((input[i] >> 8) & 0xFF);
        output[j + 2] = (u8)((input[i] >> 16) & 0xFF);
        output[j + 3] = (u8)((input[i] >> 24) & 0xFF);
    }
}

void TLobby__sub_80401D2C(u8 *digest, Md5Ctx_80401EB8 *ctx) {
    u8 bits[8];
    u32 index;
    u32 padLen;
    Encode_80401D2C(bits, ctx->count, 8);
    index = (ctx->count[0] >> 3) & 0x3F;
    padLen = (index < 56) ? (56 - index) : (120 - index);
    TLobby__sub_80401EB8(ctx, lbl_8047FE78, padLen);
    TLobby__sub_80401EB8(ctx, bits, 8);
    Encode_80401D2C(digest, ctx->state, 16);
    NetMemset(ctx, 0, sizeof(*ctx));
}
#pragma pop

void TLobby__sub_80401EB8(Md5Ctx_80401EB8 *ctx, u8 *input, u32 len) {
    int space;
    u32 bits = len << 3;
    u32 i;
    u32 index;
    u32 partLen;

    index = (ctx->count[0] >> 3) & 0x3F;
    if ((ctx->count[0] += bits) < bits) {
        ctx->count[1]++;
    }
    ctx->count[1] += len >> 29;
    space = index;
    space = 64 - space;
    partLen = space;
    if (len >= partLen) {
        NetMemcpy(&ctx->buffer[index], input, partLen);
        MD5Transform(ctx->state, ctx->buffer);
        for (i = partLen; i + 63 < len; i += 64) {
            MD5Transform(ctx->state, &input[i]);
        }
        index = 0;
    } else {
        i = 0;
    }
    NetMemcpy(&ctx->buffer[index], &input[i], len - i);
}

void TLobby::init_md5_state() {
    u8 *arg0 = (u8 *)this;
    struct Fields_arg0 { s32 field_0; s32 field_4; s32 field_8; s32 field_C; s32 field_10; s32 field_14; };
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
}
extern u8 lobby_ppp_read_buf;
void MD5Transform(u32 *state, u8 *block);
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

void TLobby::init_net_block_620() {
    TLobby__sub_803F778C((void *) (&lbl_805C0620.value));
}

typedef char RecoveredGlobal_80402B88_lbl_805C0620_size[sizeof(RecoveredGlobal_80402B88_lbl_805C0620) == 0x18 ? 1 : -1];
s32 TLobby::init_net_block_620_secondary() {
    ((TLobby *)(&(*(RecoveredGlobal_80402B88_lbl_805C0620 *)&lbl_805C0620).value))->init_net_block_620_params();
    return 0;
}

s16 TLobby__sub_80402BB4(u8 *arg0, s32 timeout) {
    Conn_804004DC *c = (Conn_804004DC *)arg0;
    RecoveredGlobal_804050DC_lbl_805C18A0 *g;
    u8 *sub;

    sub = c->sub;
    g = &lbl_805C18A0;
    c->abort = 0;
    while (c->state != 5) {
        if (TLobby::is_timed_out() != 0 || c->abort != 0 || *sub == 4) {
            TLobby::update_connection_state((int)c);
            TLobby::update_connection_state((int)(c->sub + 4));
            c->abort = 0;
            if (lbl_805D7A80 != 0) {
                lbl_805D7A82 = 6;
            } else {
                lbl_805D7A82 = 5;
            }
            lbl_805D7A8A = 8;
            return -1;
        }
        if (TLobby::get_remaining(timeout) != 0) {
            TLobby::update_connection_state((int)c);
            TLobby::update_connection_state((int)(c->sub + 4));
            return -0x12;
        }
        TUdpSocket::unlock_mutex(g->value);
        TLobby__sub_803F97E8(100);
        TLobby::process_expired_timers();
        TLobby::lock_mutex(g->value);
    }
    c->abort = 0;
    return 0;
}

extern const char lbl_805E1180[4];
extern "C" void handle_request_timeout__6TLobbyFv(void);
extern "C" B_803FADA0 *TLobby__sub_80403634(Self_803FD74C *fsm);
struct Self_80402CE0;
struct Timer_80402CE0 {
    u8 pad0[0x10];
    void (*callback)(void);
    Self_80402CE0 *arg;
    u8 pad18[4];
};
struct Self_80402CE0 {
    u8 f0; u8 f1; u8 f2; u8 f3; u8 f4; u8 f5; u8 f6; u8 f7;
    u8 pad8[4];
    u8 *sub;
    Timer_80402CE0 timer;
    Proto_803FC318 *proto;
    u8 *opts;
};
extern "C" void TLobby__sub_80402CE0(u8 *conn);

void TLobby__sub_80402CE0(u8 *conn) {
    Names_80403168 *g;
    Proto_803FC318 *p;
    Self_80402CE0 *fsm;
    Timer_80402CE0 *timer;

    g = &lbl_805C04D8;
    p = (Proto_803FC318 *)g;
    fsm = (Self_80402CE0 *)(conn + 0x38);
    if (fsm->opts == NULL) {
        timer = &fsm->timer;
        p->name = lbl_805E1180;
        p->proto = 0xC023;
        p->h6 = 0xE;
        p->b8 = 1;
        p->bB = 0;
        p->b9 = *(u8 *)((u8 *)g + 0x15A);
        p->bA = *(u8 *)((u8 *)g + 0x15B);
        p->timeout = *(u16 *)((u8 *)g + 0x15C) * 1000;
        p->f10 = TLobby__sub_803FE84C;
        p->f14 = TLobby__sub_803FE84C;
        p->f18 = TLobby__sub_803FE84C;
        p->f1C = TLobby__sub_803FE84C;
        p->f20 = TLobby__sub_803FE84C;
        p->f24 = TLobby__sub_803FE84C;
        p->f28 = TLobby__sub_80403634;
        p->f2C = TLobby__sub_803FE844;
        p->f30 = TLobby__sub_803FE844;
        p->f34 = TLobby__sub_803FE844;
        p->f38 = TLobby__sub_803FE844;
        fsm->sub = conn;
        fsm->proto = p;
        fsm->opts = (u8 *)g + 0x3C;
        fsm->f4 = fsm->proto->b9;
        fsm->f7 = fsm->proto->bA;
        fsm->f5 = fsm->proto->bB;
        fsm->f0 = 0;
        fsm->f3 = fsm->f4;
        fsm->f6 = fsm->f7;
        timer->callback = handle_request_timeout__6TLobbyFv;
        timer->arg = fsm;
        TLobby__sub_80405298((N_80405298 *)timer, fsm->proto->timeout);
    }
}

s32 TLobby::mark_ready() {
    u8 *arg0 = (u8 *)this;
    *(s8 *)((s8 *)arg0 + 0x38) = 2;
    *(u8 *)((s8 *)arg0 + 0x3A) = (u8) (*(u8 *)((s8 *)arg0 + 0x3A) | 0x20);
    *(u8 *)((s8 *)arg0 + 2) = (u8) (*(u8 *)((s8 *)arg0 + 2) | 0x20);
    return 0;
}

void TLobby::set_active() {
    u8 *arg0 = (u8 *)this;
    *(s8 *)((s8 *)arg0 + 0x38) = 1;
    *(u8 *)((s8 *)arg0 + 0x3A) = (u8) (*(u8 *)((s8 *)arg0 + 0x3A) | 0x10);
    *(u8 *)((s8 *)arg0 + 2) = (u8) (*(u8 *)((s8 *)arg0 + 2) | 0x10);
    *(u8 *)((s8 *)arg0 + 0x3B) = (u8) *(u8 *)((s8 *)arg0 + 0x3C);
}

typedef char RecoveredGlobal_804050DC_lbl_805C18A0_size[sizeof(RecoveredGlobal_804050DC_lbl_805C18A0) == 0x10 ? 1 : -1];
extern "C" {

s32 TLobby__sub_80403168(u8 *arg0, u8 *arg1, u8 *arg2) {
    Names_80403168 *g;
    u8 **p;
    u32 n;
    u32 m;
    p = *(u8 ***)(arg2 + 0x30);
    g = &lbl_805C04D8;
    n = NetStringLength((const char*)arg0);
    if (n >= 0x80) {
        n = 0x7F;
    }
    NetMemcpy(g->a, arg0, n);
    g->a[n] = 0;
    m = NetStringLength((const char*)arg1);
    if (m >= 0x80) {
        m = 0x7F;
    }
    NetMemcpy(g->b, arg1, m);
    g->b[m] = 0;
    p[0] = g->a;
    p[1] = g->b;
    return 0;
}

void TLobby::reset_connection_state() {
    u8 *arg0 = (u8 *)this;
    struct Fields_arg0 { u8 field_0; u8 pad_1[1]; s8 field_2; u8 pad_3[45]; u32 field_30; };
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

void TLobby::handle_request_timeout() {
    u8 *arg0 = (u8 *)this;
    u8 *temp_r4;
    temp_r4 = (u8 *)(*(u8 **)((s8 *)arg0 + 0x30));
    if ((u8) *(u8 *)((s8 *)arg0 + 3) != 0) {
        *(s32 **)((s8 *)temp_r4 + 8) = lbl_8047FEB8;
        TLobby__sub_803FE658((Self_803FD85C *)arg0);
        return;
    }
    *(s32 **)((s8 *)temp_r4 + 8) = lbl_8047FEC8;
    TLobby::update_connection_state((int) (*(s32 *)((s8 *)arg0 + 0xC) + 4));
    *(s16 *)((s8 *)arg0 + 8) = 1;
}

struct Pap_80403634 { char *name; char *passwd; };
B_803FADA0 *TLobby__sub_80403634(Self_803FD74C *fsm) {
    Pap_80403634 *pap = (Pap_80403634 *)fsm->f30;
    B_803FADA0 *buf;
    u8 *p;
    u32 idlen;
    u32 pwlen;

    if (pap->name == NULL || pap->passwd == NULL) {
        return NULL;
    }
    buf = init_net_buffer_entry__6TLobbyFUs(0);
    if (buf == NULL) {
        return NULL;
    }
    p = buf->buf;
    idlen = NetStringLength(pap->name);
    *p++ = idlen;
    NetMemcpy(p, pap->name, idlen);
    p += idlen;
    pwlen = NetStringLength(pap->passwd);
    *p++ = pwlen;
    NetMemcpy(p, pap->passwd, pwlen);
    buf->len += 2 + idlen + pwlen;
    return buf;
}

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
    if ((TLobby__sub_803F812C(1, &buf, &st) != 0) && (st != 1))
    {
      return -1;
    }
    *(dst++) = buf;
    n--;
  }
  return 0;
}

#pragma push
#pragma opt_common_subs on
s32 TLobby__sub_804037B0(s32 src, u16 len) {
    if (send_network_frame(len, (u8 *)src) != 0) {
        return -1;
    }
    return 0;
}
#pragma pop

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

s16 TLobby__sub_803FED78(u8 *);

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
    s16 clear_flag_bit4__6TLobbyFlPUc(s32 arg0, u8 *arg1);
    s16 NetIPv6CPSetInterfaceIdentifier(u8 *arg0, s32 arg1);
    u8 *temp_r31;
    u8 *temp_r6;

    temp_r6 = lbl_805C0038 + 0xD4;
    temp_r31 = *(u8 **)((s8 *)temp_r6 + 0x30);
    ((TLobby *)temp_r6)->set_flags_and_state();
    if (clear_flag_bit4__6TLobbyFlPUc(arg0, temp_r31) != 0) {
        return -0x11;
    }
    if (clear_flag_bit4__6TLobbyFlPUc(arg0, temp_r31 + 0x34) != 0) {
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
    s16 set_socket_flags_by_mode__6TLobbyFsPv(s16 arg0, u8 *arg1);
    s16 TLobby__sub_803FF2CC(u8 *arg0, s32 arg1);
    s16 set_filter_id__6TLobbyFPvi(u8 *arg0, s32 arg1);
    s16 set_filter_index__6TLobbyFPvi(u8 *arg0, s32 arg1);
    s16 set_target_id__6TLobbyFPvi(u8 *arg0, s32 arg1);
    s16 set_target_index__6TLobbyFPvi(u8 *arg0, s32 arg1);
    s16 set_target_slot__6TLobbyFPvi(u8 *arg0, s32 arg1);
    u8 *temp_r31;
    u8 *temp_r10;
    temp_r10 = lbl_805C0038 + 0x6C;
    temp_r31 = *(u8 **)((s8 *)temp_r10 + 0x30);
    ((TLobby *)temp_r10)->set_flags_and_state();
    if (set_socket_flags_by_mode__6TLobbyFsPv(arg0, temp_r31) != 0) {
        return -0x11;
    }
    if (set_socket_flags_by_mode__6TLobbyFsPv(arg0, temp_r31 + 0x4C) != 0) {
        return -0x11;
    }
    if (TLobby__sub_803FF2CC(temp_r31, arg1) != 0) {
        return -0x11;
    }
    if (set_target_slot__6TLobbyFPvi(temp_r31, arg3) != 0) {
        return -0x11;
    }
    if (set_filter_id__6TLobbyFPvi(temp_r31, arg4) != 0) {
        return -0x11;
    }
    if (set_target_id__6TLobbyFPvi(temp_r31 + 0x4C, arg2) != 0) {
        return -0x11;
    }
    if (set_filter_index__6TLobbyFPvi(temp_r31 + 0x4C, arg5) != 0) {
        return -0x11;
    }
    if (set_target_index__6TLobbyFPvi(temp_r31 + 0x4C, arg6) != 0) {
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
    ((TLobby *)(g + 0x6C))->set_flags_and_state();
    st = lbl_805D7A7C;
    if (st == 6 || st == 0) {
        ((TLobby *)(g + 0xD4))->set_flags_and_state();
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
        TLobby__sub_803FE658((Self_803FD85C *)c);
    }
    r = TLobby__sub_80402BB4(c, arg2);
    if (r < 0) {
        if (r == -0x12) {
            return -0x12;
        }
        return -0x11;
    }
    ((TLobby *)(g + 0x6C))->set_flags_and_state();
    st = lbl_805D7A7C;
    if (st == 6 || st == 0) {
        ((TLobby *)(g + 0xD4))->set_flags_and_state();
    }
    return 0;
}

void TLobby__sub_803F808C(void);

s32 TLobby__sub_80403C60(u8 *arg0) {
    s16 wait_for_connection__6TLobbyFPv(int);
    u8 *temp_r31;
    u8 *var_r3;
    u8 *temp_r3;

    TLobby__sub_803F808C();
    temp_r31 = (u8 *)lbl_805C0038 + 4;
    if (TLobby__sub_80400744((LcpEntry_8040059C *)temp_r31, (LcpCfg_80400744 *)arg0) != 0) {
        return -0x11;
    }
    if (wait_for_connection__6TLobbyFPv((int) (temp_r31)) != 0) {
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

s32 TLobby__sub_80403D28(s32 arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4, s16 arg5, char *arg6, s16 arg7) {
    s32 temp_r31;
    s16 i;
    for (i = 0; i < 8; i++) {
        *(s8 *)((s8 *)(&lbl_805C0638.value) + i * 0x14) = 0;
    }
    temp_r31 = TLobby__sub_80403DA8(arg1, arg2, arg3, arg4, arg5, arg6, arg7);
    TLobby__sub_804062A0(0x82);
    return temp_r31;
}

struct Cfg_80403DA8 {
    s32 f0;
    s32 f4;
    s32 f8;
    s32 fC;
    s32 f10;
    s32 f14;
    s16 f18;
    s16 pppoe;
    char *name;
};

extern "C" {
s32 TLobby__sub_803F8314(Cfg_80403DA8 *cfg);
extern s16 lbl_805D7A7E;
}

s32 TLobby__sub_80403DA8(s16 a0, s16 a1, s16 a2, s16 a3, s16 a4, char *name, s16 pppoe) {
    Cfg_80403DA8 cfg;
    cfg.f0 = (a0 == 0) ? 0 : (a0 == 1) ? 1 : 0;
    cfg.f4 = (a1 == 0) ? 2 : (a1 == 1) ? 1 : (a1 == 2) ? 0 : 2;
    cfg.f8 = (a2 == 0) ? 0 : (a2 == 1) ? 2 : 0;
    cfg.fC = 1;
    cfg.f10 = (a3 == 0) ? 0 : (a3 == 1) ? 1 : (a3 == 2) ? 2 : (a3 == 3) ? 3 : (a3 == 4) ? 4 : (a3 == 5) ? 5 : (a3 == 6) ? 6 : 2;
    cfg.f14 = (a4 == 2) ? 0 : (a4 == 3) ? 1 : 1;
    cfg.f18 = 0;
    cfg.name = name;
    if (pppoe != 0) {
        cfg.pppoe = 1;
    } else {
        cfg.pppoe = 0;
    }
    if (TLobby__sub_803F8314(&cfg) != 0) {
        return -1;
    }
    lbl_805D7A7E = 1;
    return 0;
}

typedef struct B_80403F4C {
    u16 src_port;
    u16 dst_port;
    u32 seq;
    u32 ack;
    u16 window;
    u16 checksum;
    u16 urgent;
    u16 mss;
    u8 pad_14;
    u8 urg;
    u8 ack_flag;
    u8 psh;
    u8 rst;
    u8 syn;
    u8 fin;
    u8 option_len;
    u8 options[0x28];
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
    s32 n2C;
    s32 n30;
    s32 n34;
} Obj_80403F4C;

u32 TLobby__sub_803FEA88(A_80403F4C *out, Strm_80405A74 **src);
void TLobby__sub_804053B8(B_80403F4C *, u8 **);
u8 *TLobby__sub_8040555C(B_80403F4C *, u8 *, s32);
u8 *GXLoadTexObjPreLoaded(A_80403F4C *, u8 *, s32);
#define o ((Obj_80403F4C *)ov)
#define pp ((u8 **)spp)
s16 TLobby__sub_80403F4C(void *ov, Strm_80405A74 **spp) {
    A_80403F4C a;
    B_80403F4C b;
    Ent_80403F4C *e;
    u8 c;

    TLobby__sub_803FEA88(&a, spp);
    TLobby__sub_804053B8(&b, pp);
    c = a.count;
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
    a.count = 6;
    e->a = a;
    e->b = b;
    *pp = TLobby__sub_8040555C(&b, *pp, 0);
    *pp = GXLoadTexObjPreLoaded(&a, *pp, 1);
    o->n28++;
    return ((TLobby *)(*pp))->get_field_4();
}
#undef o
#undef pp

extern u8 lbl_805D7AC0[4];
extern u8 lbl_805D7AC4;

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
    if (TLobby__sub_80401BCC(src, &lbl_805D7AC4, 1) != 1) {
        return -1;
    }
    return (s16)lbl_805D7AC4;
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

s16 TLobby__sub_804040E0(Obj_80403F4C *comp, Strm_80405A74 **src) {
    B_80403F4C *th;
    Ent_80403F4C *cs;
    s16 changes;
    s32 v;
    s16 len;

    comp->n2C++;
    if (((TLobby *)*src)->get_field_4() < 3) {
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
    len = ((TLobby *)*src)->get_field_4() + 40 + cs->a.optlen;
    cs->a.len = len;
    *src = (Strm_80405A74 *)TLobby__sub_8040555C(th, (u8 *)*src, 0);
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
#pragma pop

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
    (*(s16 *)((s8 *)(G) + 0x13A))++;                                            \
    t = (Strm_80405A74 *)((TLobby *)arg0)->alloc_from_buffer(4); \
    p = t->p;                                                                \
    *p++ = 0xFF;                                                             \
    *p++ = 3;                                                                \
    write_network_u16_be(p, code);                                           \
    u = t;                                                                   \
    if (u == NULL) {                                                         \
        (*(s16 *)((s8 *)(G) + 0x142))++;                                        \
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

RecoveredGlobal_803FD520_lbl_805C0310 lobby_net_buffer_desc_b;
IpcpState_803FEF4C lbl_805C0328;
LcpState_8040059C lbl_805C0400;
RecoveredGlobal_80401A68_lbl_805C04A8 lbl_805C04A8;
Names_80403168 lbl_805C04D8;
RecoveredGlobal_80402B60_lbl_805C0620 lbl_805C0620;
RecoveredGlobal_80403D28_lbl_805C0638 lbl_805C0638;
