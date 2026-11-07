#include "pso/network/UdpRuntime.h"
#include "pso/network/SocketEvents.h"
#include "pso/network/NetworkDispatch.h"
#include "pso/unk/TLobby.h"
#include "pso/network/BufferRef.h"
#include "pso/network/IPv6.h"

#include "types.h"
#include "pso/network/NetworkRuntime.h"
#include "pso/network/EthernetReceiveFilter.h"

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
struct Stack_80416008 {
    s32 sp10;
    u8 pad_14[0xC];
    s32 sp20;
    u8 trailing_storage[0x14];
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
struct Ipv6Header {
    union {
        u32 word;
        u16 half;
        u8 version;
    } vtf;
    u16 payload_length;
    u8 next_header;
    u8 hop_limit;
    IPv6Address src;
    IPv6Address dst;
};
struct RecoveredGlobal_8040FF0C_lbl_805C1B78 {
    s16 value;
    u8 pad2[2];
    E_8040FF58 *ents;
    s32 f8;
    u16 traffic_class;
    u8 padE[2];
    u32 flow_label;
    u8 f14;
    u8 pad15[3];
    Ipv6Header hdr;
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

struct Obj_80405304 { u8 pad[0x18]; u8 f18; };

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

struct Hdr_8040B6E4 { u16 id; u8 f2; u8 f3; s16 qd; s16 an; s16 ns; s16 ar; u8 body[4]; };

struct Pkt_8040B6E4 { u8 pad0[2]; s16 len; Hdr_8040B6E4 *hdr; };

struct Q_8040B6E4 { u8 pad0[6]; u16 id; u8 pad8[0x10]; Pkt_8040B6E4 *pkt; };

struct QT_8040B6E4 { s16 type; s16 cls; };

struct Hdr_8040B790 { u16 id; u8 f2; u8 f3; u16 qd; u16 an; s16 ns; s16 ar; u8 body[4]; };

struct Pkt_8040B790 { u8 pad0[2]; s16 len; Hdr_8040B790 *hdr; };

struct Q_8040B790 { u8 pad0[6]; u16 id; u8 pad8[0x10]; Pkt_8040B790 *pkt; };

struct QT_8040B790 { s16 type; s16 cls; };

struct P_8041D2B8 { s32 a; s32 b; s32 c; s32 d; };

struct O_8041D2B8 { u8 pad0[0x238]; s32 f238; u8 pad23C[0x320 - 0x23C]; s16 n; u8 pad322[0xE]; P_8041D2B8 items[32]; };

struct Strm_80405A74 { u8 *p; u16 len; };

typedef struct B_803FADA0 { u8 *buf; u16 len; } B_803FADA0;

typedef struct A_803FADA0 { u8 pad0[4]; u32 a; u32 b; } A_803FADA0;

struct G_8041509C { s16 a; u8 pad[0xA]; s16 c; };

struct Tbl_80409AD8 { s16 count; u8 *list; };

typedef struct Pkt_804081C0 { u8 pad0[4]; s32 f4; s32 f8; s16 fC; u8 padE[2]; u8 f10[8]; } Pkt_804081C0;

typedef struct Pool_804081C0 { u8 pad0[0x24]; u8 *f24; } Pool_804081C0;

typedef struct Out_804081C0 { u8 *f0; u8 *f4; u8 *f8; u8 *fC; u8 *f10; } Out_804081C0;

struct Ent_8040A13C { s16 f0; s16 f2; u8 pad[0x2C]; };

struct G_8040A13C { s16 n; Ent_8040A13C *p; };

struct Ent_8040A19C { s16 f0; s16 f2; u8 pad[0x2C]; };

struct G_8040A19C { s16 n; Ent_8040A19C *p; };

struct Ent_80409F44 { s16 st; s16 pad2; s32 (*f4)(s32); s32 (*f8)(s32); s32 (*fC)(s32); s16 (*f10)(s32); u8 pad14[0x30-0x14]; };

struct Tbl_80409F44 { s16 count; Ent_80409F44 *list; };

#include "pso/network/IPv6Send.h"
#include "pso/network/TUdpSocket.h"

typedef struct T_804179A4 { u8 pad0[3]; u8 f3; u8 pad4[2]; s16 f6; u8 pad8[0xC]; u8 f14[0x10]; } T_804179A4;

struct Seg_804179A4 { s16 len; s16 pad; u8 buf[8]; };

struct Pkt_804179A4 { u8 pad0[4]; u32 n; s32 total; Seg_804179A4 seg[1]; };

struct Na_804179A4 { u8 type; u8 code; s16 cksum; u8 flags; u8 rsv[3]; u8 target[16]; };

struct Cur_804179A4 { u8 pad[8]; };

struct Sock_804179A4 { u8 pad0[0x10]; u8 addr[0x10]; s32 f20; s16 f24; u8 f26; u8 f27; };

struct Q_804179A4 { u8 pad0[3]; u8 f3; s16 f4; u8 pad6[2]; u8 f8[0x28]; s16 f30; u8 pad32[2]; u8 *f34; };

struct E_804179A4 { u8 pad0[3]; u8 f3; s16 f4; s16 f6; s16 f8; s16 fa; u8 fc; u8 pad[3]; Q_804179A4 *f10; s16 f14; u8 f16[0x10]; s16 f26; u8 f28[1]; };

struct E_8041A230 {
    u8 c0;
    u8 c1;
    u8 c2;
    u8 c3;
    s16 f4;
    u8 pad6[2];
    s16 f8;
    u8 padA[0x544 - 0xA];
};

struct G_8041A230 {
    E_8041A230 *ents;
    s16 count;
    s16 avail;
    u8 pad8[8];
    s16 h10;
    s16 h12;
    s16 h14;
    u8 pad16[2];
    u8 tick[6];
    s16 h1E;
    s16 h20;
    s16 h22;
    u8 pad24[0x2C];
    u8 b50;
    u8 b51;
    u8 b52;
    u8 b53;
    u8 b54;
    u8 b55;
    u8 b56;
    u8 b57;
    u8 b58;
    u8 b59;
    u8 b5A;
    u8 b5B;
    s16 s5C;
    s16 s5E;
    s16 s60;
    s16 s62;
    s16 s64;
    s16 s66;
    s16 s68;
    s16 s6A;
    s16 s6C;
    s16 s6E;
    s16 s70;
    s16 s72;
    s16 s74;
    u8 pad76[0x2C];
    u8 bA2;
    u8 padA3[5];
};

extern "C" {
void TLobby__sub_803F8AA0(u8 *arg0);
void TLobby__sub_803F8A0C(u8 *arg0);
extern RecoveredGlobal_8041552C_lbl_805C1BE0 network_loopback_state;
extern RecoveredGlobal_804050DC_lbl_805C18A0 lbl_805C18A0;
void TLobby__sub_804050DC(s16 arg0);
extern s16 lbl_805D7A7A;
void NetIPv6ApplyNeighborDiscoveryDefaults(u8 *arg0);
void TLobby__sub_803F89A4(u8 *arg0);
void TLobby__sub_803FD85C(void *);
s32 TLobby__sub_804062A0(s16);
s32 TLobby__sub_803F79AC(void *);
void TLobby__sub_803F79B0(u8 *arg0);
extern s32 lobby_timer_list_head;
s16 reset_network_timer_list(void);
void TLobby__sub_803F8A08(void *);
extern s16 lobby_udp_socket_table;
s32 TUdpSocket__sub_80407508(void);
void TLobby__sub_804073B8(void);
s32 TLobby__sub_80407C60(s16, s32);
s32 TLobby__sub_80407D98(s16, s32);
s32 TLobby__sub_8040799C(s16, void *, void *);
s16 TLobby__sub_80407F20(s16, s16, s16, s16, s16, s32, s16, s32);
s32 TLobby__sub_8040878C(void);
void TLobby__sub_803F8A9C(void *);
extern s16 lobby_handler_table_desc;
s32 TLobby__sub_80409AA8(void);
s32 TLobby__sub_8040C9E0(u8 *arg0, u8 *arg1);
u16 TLobby__sub_8040D8F0(u8 *arg0, u8 *arg1, s8 arg2, u8 *arg3, s16 arg4);
s32 TLobby__sub_8040DA54(u8 *arg0, u8 *arg1);
s32 TLobby__sub_8040FDA0(u32, s16);
s16 is_addr_unspecified__6TLobbyFPv(u8 *arg0);
extern RecoveredGlobal_8040EF00_lbl_805C1B60 ipv4_address_routing_state;
struct Ipv4Route;
Ipv4Route *TLobby__sub_8040F76C(u32, u32);
s16 TLobby__sub_8040FEE4(s32 arg0, s32 arg1);
extern RecoveredGlobal_8041123C_lbl_805C1BB8 ipv6_address_routing_state;
u8 * TLobby__sub_80413264(void *, s32);
s32 TLobby__sub_80413230(u8 *arg0, s32 arg1);
void TLobby__sub_804136AC(s16 arg0);
void TLobby__sub_804136CC(s16 arg0);
s16 NetIPv6IsLoopback(u8 *arg0);
s16 NetIPv6IsUnspecified(u8 *arg0);
s16 NetIPv6CompareAddresses(s32 arg0, s32 arg1);
s16 TLobby__sub_8041510C(void);
void TLobby__sub_804150EC(void);
void TLobby__sub_8041615C(void);
void NetIPv6TickNeighborCache(void);
void NetIPv6TickNeighborDiscovery(void);
s32 NetIPv6SendUnspecifiedSourceNeighborSolicitation(s32 arg0, s32 arg1);
extern NetworkDispatchState network_dispatch_state;
void TLobby__sub_80419A00(void);
s16 TLobby__sub_8041D368(u8 *arg0);
u8 * TLobby__sub_8041B5C0(void *);
extern RecoveredGlobal_8041E178_lbl_805C1D48 tcp_protocol_state;
s32 TLobby__sub_804112B8(s32 arg0, s32 arg1, s16 arg2);
s32 TLobby__sub_8041123C(s32 arg0, s32 arg1, s16 arg2);
s16 TLobby__sub_8040EF00(s16 arg0);
s32 TLobby__sub_8040FE40(s16 arg0);
void TLobby__sub_803F8930(u8 *arg0);
s32 TLobby__sub_803FE6CC(void *, int, int, void *);
void TLobby__sub_80405328(u8 *arg0);
s16 TLobby__sub_8040FCEC(u32);
s16 TLobby__sub_804136EC(u8 *);
void TLobby__sub_803F892C(void *);
extern RecoveredGlobal_8040DD68_lbl_805C1B38 ipv4_protocol_state;
s32 TLobby__sub_8040DD68(void);
void TLobby__sub_803F8958(void *);
s32 TLobby__sub_8040ED28(void);
s32 TLobby__sub_8040ED70(void);
void TLobby__sub_803F87DC(void *);
extern RecoveredGlobal_8040FF0C_lbl_805C1B78 ipv6_protocol_state;
s32 NetIPv6Shutdown(void);
void TLobby__sub_803F89D8(void *);
extern RecoveredGlobal_80415650_lbl_805C1BF8 network_buffer_pool_state;
s32 TLobby__sub_803F8E9C();
void TLobby__sub_80419A34(void);
s32 TLobby__sub_80419A7C(void);
s16 TLobby__sub_8041579C(void *);
s32 TLobby__sub_8041EB74(u8 *arg0);
s16 TLobby__sub_80409A3C(u8 *arg0, s16 arg1);
s16 TLobby__sub_80415954(NetBufferRef *ref, s32 size, s16 owner);
s32 TLobby__sub_8041ECA4(u8 *arg0);
void TLobby__sub_803FD958(u8 *arg0);
void TLobby__sub_80401CAC(Outer_80401CAC *o, u16 v);
u16 read_network_u16_be(u8 *p);
u32 TLobby__sub_80402AFC(u8 *p);
u8 *write_network_u16_be(u8 *p, u16 v);
extern Tbl_80408718 lbl_805C1AB0;
Ent_80408718 *find_free_peer_entry__6TLobbyFv(void);
s32 TLobby__sub_80405304(void *arg0);
u16 TLobby__sub_80406BD8(void *, s16);
s32 OSDisableInterrupts(void);
s32 OSRestoreInterrupts(s32);
void TLobby__sub_803F97E8(int);
s32 TLobby__sub_803FC684(u8 *, u8 *, u8 *);
extern u8 lbl_805C0038[];
extern s16 lbl_805D7A7C;
s16 TLobby__sub_8040B838(u8 *dst, u8 *src, s16 len);
s16 TLobby__sub_8040DC8C(u8 *arg0, u8 *arg1);
s32 TLobby__sub_804217E4(void);
s32 TLobby__sub_80421814(void);
s32 TLobby__sub_80421B3C(s32);
s16 TLobby__sub_80401BCC(void *, void *, int);
extern u8 lcp_read_value_buffer[4];
extern u8 lobby_read_byte_buffer[1];
s32 TLobby__sub_803FDBF8(void *, Strm_80405A74 *);
void TLobby__sub_8040098C(Self_8040098C *self);
s32 PADRead(void *, Strm_80405A74 *);
s16 TLobby__sub_80403F4C(void *, Strm_80405A74 **);
s16 TLobby__sub_804040E0(void *, Strm_80405A74 **);
s32 TLobby__sub_804060B8(u8 *, s32, int);
extern u8 lobby_ppp_read_buf;
extern u8 ppp_input_byte;
void ppp_input_packet__6TLobbyFPv(Strm_80405A74 *arg0);
s16 NetCompareBitsBackward(u8 *arg0, u8 *arg1, s16 arg2);
s16 NetCompareBitPrefix(u8 *a, u8 *b, s16 bits);
s32 NetIPv6MakeSolicitedNodeMulticastAddress(u8 *arg0, u8 *arg1);
void TLobby__sub_803F8B78(void *);
s32 TLobby__sub_8041509C(void);
s32 TLobby__sub_80409AD8(void);
Pkt_804081C0 *alloc_packet_with_header__6TLobbyFPvPv(Out_804081C0 *arg0, u8 *arg1);
s32 init_ipv6_all_routers_multicast_address(u8 *arg0, s8 arg1);
bool init_ipv6_all_nodes_multicast_address(u8 *arg0, s8 arg1);
s16 TLobby__sub_8041A9AC(int);
struct Tcb_8041D460;
struct Tcb_8041A9AC;
void TLobby__sub_8041D398(Tcb_8041D460 *tp, s32 start, s32 end);
s32 TLobby__sub_8041D460(Tcb_8041D460 *tp, s32 *start, s32 *end);
s32 TLobby__sub_80420410(s32 off, s32 len, NetPacket *m, Tcb_8041A9AC *tp);
struct Tcb_8041B974;
struct TcpHeader_8041B3D4;
void TLobby__sub_8041D0C8(Tcb_8041B974 *tp, u8 *optp, s16 optlen, TcpHeader_8041B3D4 *ti);
void TLobby__sub_8041F204(NetPacket *m, u16 off, Tcb_8041B974 *tp);
void TLobby__sub_8041F914(NetPacket *m, u16 off, Tcb_8041B974 *tp, TcpHeader_8041B3D4 *ti);
void TLobby__sub_8041F11C(Tcb_8041B974 *tp);
void TLobby__sub_80422AB8(s16 listener, s32 arg1, s16 idx, u8 *faddr, u16 lport, u16 fport);
s32 TLobby__sub_8041FFF8(int, int);
s32 TLobby__sub_80420BD0(void *, void *, s32);
s16 tcp_start_send(s16 arg0, u8 *arg1, void (*completion)(s16, s16), u8 arg3);
void TLobby__sub_80406EB8(NetBufferRef *ref, s32 n);
void TLobby__sub_80406FD8(void *, void *, s32);
s16 TLobby__sub_80416F58(u8 *, s32, void *, void *);
s16 TLobby__sub_80417028(IPv6NeighborSolicitation *ns, u8 *src, u8 *dst, s16 iface);
s16 NetIPv6HandleNeighborSolicitation(u8 *arg0, void *arg1, void *arg2, void *arg3);
u16 TLobby__sub_80411040(const IPv6Address *, const IPv6Address *, u8, const NetPacket *, s16);
s16 NetIPv6GetInterfaceLinkLayerAddress(s32 arg0, s16 arg1, s16 arg2);
s32 NetIPv6EmitRouterSolicitation(NetPacket *arg0, NetIPv6SendParameters *arg1, s32 arg2);
extern struct G_80415B38 ipv6_neighbor_discovery_state;
s16 NetIPv6SendNeighborAdvertisement(Pkt_804179A4 *arg0, u8 *arg1, u8 arg2, Sock_804179A4 *arg3, s16 arg4);
s32 NetRegisterTimer(s32 period, s16 locked, NetTimerCallback fn);
void TLobby__sub_8041A3CC(void);
void TLobby__sub_8041A5B4(void);
s32 NetTCPInit(void);
void TLobby__sub_803F9344(s32, void *, s32);
void NetEnqueueProtocolMessage(s32 arg0, s16 arg1, s16 arg2, s16 arg3, u16 arg4);
void TLobby__sub_803F8794(void *);
void TLobby__sub_803F8864(void *);
void TLobby__sub_803F88E0(void *);
void TLobby__sub_803F89A0(void *);
void TLobby__sub_803F8A24(void *);
s32 NetIPv6IsLinkLocal(u8 *arg0);
s32 TLobby__sub_8041549C(s16 arg0);
s32 TLobby__sub_804154C0(s16 arg0);
s32 TLobby__sub_804154E4(s16 arg0);
s32 TLobby__sub_80415508(s16 arg0);
s32 get_adjusted_slot_count__6TLobbyFPv(u8 *arg0);

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

extern s16 lbl_805D7A86;

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
void TLobby__sub_80405298(N_80405298 *o, s32 v);

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

u32 lbl_805C1AD8[6];
#define lbl_805C1AD8 (*(Tbl_80408F2C *)lbl_805C1AD8)

void TLobby__sub_804050DC(s16 arg0) {
    *(s16 *)((s8 *)(&lbl_805C18A0.value) + 8) = arg0;
}

typedef char RecoveredGlobal_804050EC_lbl_805C18A0_size[sizeof(RecoveredGlobal_804050EC_lbl_805C18A0) == 0x10 ? 1 : -1];
void TLobby::init_net_block_18A0() {
    TLobby__sub_803F79AC((void *) (&(*(RecoveredGlobal_804050EC_lbl_805C18A0 *)&lbl_805C18A0).value));
}

typedef char RecoveredGlobal_80405114_lbl_805C18A0_size[sizeof(RecoveredGlobal_80405114_lbl_805C18A0) == 0x10 ? 1 : -1];
s32 TLobby::run_net_init_step() {
    TLobby__sub_803F79B0((u8 *)(&(*(RecoveredGlobal_80405114_lbl_805C18A0 *)&lbl_805C18A0).value));
    return 0;
}

s16 reset_network_timer_list(void) {
    lobby_timer_list_head = 0;
    return 0;
}

struct G_80405150 { s32 p0; s32 p4; s16 h8; };
extern s16 lbl_805D7A84;
extern s16 lbl_805D7A88;
s32 TLobby__sub_803FB6A0(void);
void TLobby__sub_803FB7A4(void);
void TLobby::run_net_thread_loop() {
    G_80405150 *g = (G_80405150 *)&lbl_805C18A0;
    for (;;) {
        if (lbl_805D7A86 != 0) {
            TLobby::lock_mutex(g->p0);
            TLobby__sub_803FB6A0();
            TUdpSocket::unlock_mutex(g->p0);
            continue;
        }
        if (lbl_805D7A88 != 0) {
            TLobby::lock_mutex(g->p0);
            TLobby__sub_803FB7A4();
            TUdpSocket::unlock_mutex(g->p0);
            continue;
        }
        TLobby__sub_803F97E8(g->h8);
        if (lbl_805D7A84 != 0) {
            TLobby::process_expired_timers();
        }
    }
}

typedef struct Timer_804051CC {
    struct Timer_804051CC *next;
    u8 pad4[4];
    u32 f8;
    s32 fC;
    void (*f10)(s32);
    s32 f14;
    u8 f18;
} Timer_804051CC;

s32 TLobby__sub_80405700();

void TLobby::process_expired_timers() {
    s32 now;
    Timer_804051CC *t;

    TLobby::lock_mutex(lbl_805C18A0.value);
    TLobby__sub_80405700();
    TLobby::get_time_ms(&now);
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
    TUdpSocket::unlock_mutex(lbl_805C18A0.value);
}

struct N_80405298 { N_80405298 *next; s32 f4; u8 pad8[0x18 - 8]; u8 b18; };
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
    struct Fields_arg0 { u8 pad_0[4]; u32 field_4; u32 field_8; u8 pad_C[4]; u32 field_10; u8 pad_14[4]; u8 field_18; };
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
            TLobby::get_time_ms((s32 *)((void *) (arg0 + 0xC)));
            if ((u32) ((Fields_arg0*)arg0)->field_10 != 0U) {
                ((Fields_arg0*)arg0)->field_18 = 1U;
            }
        }
    }
}

typedef struct Lobby_804062A0 {
    u8 state;
    u8 pad[3];
    u8 sub[0x140];
} Lobby_804062A0;

struct RecoveredFields_80401B8C_arg0;
struct Self_8040098C;
#pragma dont_inline off
#pragma inline_depth(4)
inline s32 valid_80405A74(Strm_80405A74 **s) {
    s32 r = 0;
    if (s != NULL && *s != NULL) {
        r = 1;
    }
    return r;
}
inline s32 avail_80405A74(Strm_80405A74 **s) {
    s32 r = 0;
    if (valid_80405A74(s) && (*s)->len > 1) {
        r = 1;
    }
    return r;
}
inline s32 get_80405A74(Strm_80405A74 **s) {
    if (avail_80405A74(s)) {
        (*s)->len--;
        return *(*s)->p++;
    }
    if (TLobby__sub_80401BCC(s, &ppp_input_byte, 1) != 1) {
        return -1;
    }
    return (s16)ppp_input_byte;
}
#define FWD_80405A74()                                                       \
    (*(s16 *)(G + 0x13A))++;                                            \
    t = (Strm_80405A74 *)((TLobby *)arg0)->alloc_from_buffer(4); \
    p = t->p;                                                                \
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
void ppp_input_packet__6TLobbyFPv(Strm_80405A74 *arg0) {
    u16 code;
    u8 *G;
    Strm_80405A74 *t;
    u8 *p;
    Strm_80405A74 *u;
    u8 pad[0x24];
    if (arg0 == NULL) {
        return;
    }
    G = lbl_805C0038;
    if (lbl_805D7A7A == 0 && arg0->p[0] == 0xFF && arg0->p[1] == 3 &&
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
        TLobby__sub_804060B8(arg0->p, arg0->len, 0x800);
        return;
    case 0x57:
        if (*(u8 *)((s8 *)G + 0xD4) != 5) {
            (*(s16 *)((s8 *)G + 0x140))++;
            return;
        }
        TLobby__sub_804060B8(arg0->p, arg0->len, -0x7923);
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
        TLobby__sub_804060B8(arg0->p, arg0->len, 0x800);
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
        TLobby__sub_804060B8(arg0->p, arg0->len, 0x800);
        return;
    case 0xC021:
        (*(s16 *)((s8 *)G + 0x130))++;
        TLobby__sub_803FDBF8(G + 4, arg0);
        return;
    case 0xC023:
        if (G[0] != 2 && G[0] != 3) {
            (*(s16 *)((s8 *)G + 0x140))++;
            if (G[0] == 0) {
                TLobby__sub_8040098C((Self_8040098C *)(G + 4));
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
                TLobby__sub_8040098C((Self_8040098C *)(G + 4));
            }
            return;
        }
        (*(s16 *)((s8 *)G + 0x136))++;
        ((TLobby *)(G + 0xA0))->dispatch_received_packet((s32)arg0);
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

struct LobbyNetBufferSlot {
    s16 active;
    u16 type;
};

struct LobbyNetBufferDesc {
    s16 handler;
    LobbyNetBufferSlot slots[2];
    s16 *used;
    u8 *bufs;
    s16 size;
    s16 count;
};

extern LobbyNetBufferDesc lobby_net_buffer_desc_b;
void TLobby__sub_80409818(s32 msg, s16 len, s16 idx, s16 arg3, u16 type);

#pragma push
#pragma opt_common_subs on
s32 TLobby__sub_804060B8(u8 *data, s32 len, int type) {
    s16 slot;
    s16 i;
    s16 j;
    u8 *buf;
    s16 *used;
    s16 n;

    for (i = 0; i < 2; i++) {
        if (lobby_net_buffer_desc_b.slots[i].active != 0 && lobby_net_buffer_desc_b.slots[i].type == (u16)type) {
            slot = i;
            break;
        }
    }
    if (i >= 2) {
        return 0;
    }
    used = lobby_net_buffer_desc_b.used;
    buf = lobby_net_buffer_desc_b.bufs;
    for (j = 0; j < lobby_net_buffer_desc_b.count; j++, used++) {
        if (*used == 0) {
            *used = 1;
            n = (s16)len < lobby_net_buffer_desc_b.size ? (s16)len : lobby_net_buffer_desc_b.size;
            NetMemcpy(buf, data, n);
            TLobby__sub_80409818((s32)buf, n, lobby_net_buffer_desc_b.handler, slot, lobby_net_buffer_desc_b.slots[slot].type);
            return 0;
        }
        buf += lobby_net_buffer_desc_b.size;
    }
    return 0;
}
#pragma pop

void TLobby__sub_8040059C(u8 *arg0);
void TLobby__sub_80402CE0(u8 *arg0);
void TLobby__sub_803FC318(u8 *arg0);
void TLobby__sub_803FEF4C(u8 *arg0);
void TLobby__sub_803F9FAC(u8 *arg0);
extern s32 lbl_805D7ADC;

typedef struct Lobby_804061FC {
    u8 state;
    u8 pad[3];
    u8 sub[0x140];
} Lobby_804061FC;

s32 TLobby__sub_804061FC(s32 arg0) {
    Lobby_804061FC *l;
    u8 *p;

    lbl_805D7ADC = 0;
    l = (Lobby_804061FC *)lbl_805C0038;
    p = lbl_805C0038;
    NetMemset(&lbl_805C0038[0], 0, 0x144);
    l->state = 0;
    TLobby__sub_8040059C(p);
    TLobby__sub_80402CE0(p);
    TLobby__sub_803FC318(p);
    TLobby__sub_803FEF4C(p);
    TLobby__sub_803F9FAC(p);
    if (l->state == 0) {
        l->state = 1;
    }
    TLobby__sub_803FD958(l->sub);
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

s32 TLobby::shutdown_network_handle() {
    TLobby__sub_803F8A08((void *)((void *) (&lobby_udp_socket_table)));
    lobby_udp_socket_table = 0;
    return 0;
}

void TLobby::init_msg(s32 arg1) {
    *(s32 *)&this->m_name = arg1;
    *(s8 *)&this->m_flags = 4;
}

void TLobby::init_packet_header(s32 arg1) {
    *(s32 *)&this->m_name = arg1;
    *(s8 *)&this->m_flags = 3;
}

void TLobby::set_value_and_enable(s32 arg1) {
    *(s32 *)&this->m_name = arg1;
    *(s8 *)&this->m_flags = 1;
}

struct Ent_80406B14 { s16 st; u8 pad[0x9c - 2]; };
struct Tbl_80406B14 { s16 count; Ent_80406B14 *list; };
#pragma push
#pragma optimization_level 3
#pragma opt_unroll_loops off
s32 TLobby::reset_socket_table() {
    s16 n;
    s16 i;
    Ent_80406B14 *p;
    TLobby__sub_803F8A0C((u8 *)&lobby_udp_socket_table);
    n = ((Tbl_80406B14 *)&lobby_udp_socket_table)->count;
    p = ((Tbl_80406B14 *)&lobby_udp_socket_table)->list;
    for (i = 0; i < n; i++, p++) {
        p->st = 0;
    }
    return 0;
}

struct Lobby_80406624 { u8 state; u8 pad[0x121]; s16 f122; s16 f124; };
s32 TLobby__sub_804066D8(Strm_80405A74 *s);

#pragma push
#pragma dont_inline off
#pragma inline_depth(4)
inline void put_ppp_header_80406624(u8 *p, u16 proto) {
    *p++ = 0xFF;
    *p++ = 3;
    write_network_u16_be(p, proto);
}

inline Strm_80405A74 *add_ppp_header_80406624(Strm_80405A74 *pkt, u16 proto) {
    Strm_80405A74 *s;

    s = (Strm_80405A74 *)((TLobby *)pkt)->alloc_from_buffer(4);
    put_ppp_header_80406624(s->p, proto);
    return s;
}

s32 TLobby__sub_80406624(s32 arg0, s32 arg1, u16 proto, Strm_80405A74 *pkt) {
    Lobby_80406624 *l = (Lobby_80406624 *)lbl_805C0038;
    Strm_80405A74 *s;

    if (l->state == 0) {
        l->f122++;
        return -1;
    }
    s = add_ppp_header_80406624(pkt, proto);
    if (s == NULL) {
        l->f124++;
        return -1;
    }
    return TLobby__sub_804066D8(s);
}
#pragma pop
#pragma pop

struct O_80406B6C { u32 w0; u8 b4; };
s32 TLobby__sub_80406B6C(O_80406B6C *o) {
    if (o != 0) {
        switch (o->b4) {
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

struct Ent_804072C4 { s16 st; u8 pad[0x9c - 2]; };
struct Tbl_804072C4 { s16 count; Ent_804072C4 *list; };
void TUdpSocket::release_entry() {
    Ent_804072C4 *e = (Ent_804072C4 *)this;
    s16 i;
    s16 n = ((Tbl_804072C4 *)&lobby_udp_socket_table)->count;
    Ent_804072C4 *p = ((Tbl_804072C4 *)&lobby_udp_socket_table)->list;
    for (i = 0; i < n; i++, p++) {
        if (p->st == 1 && p == e) {
            p->st = 0;
            return;
        }
    }
}

struct Ent_80407310 { s16 st; u8 pad[0x9c - 2]; };
struct Tbl_80407310 { s16 count; Ent_80407310 *list; };
u8 *TLobby::alloc_free_entry() {
    s16 n = ((Tbl_80407310 *)&lobby_udp_socket_table)->count;
    Ent_80407310 *p = ((Tbl_80407310 *)&lobby_udp_socket_table)->list;
    s16 i;
    for (i = 0; i < n; i++, p++) {
        if (p->st == 0) {
            p->st = 1;
            return (u8 *)p;
        }
    }
    return 0;
}

s32 NetUnregisterTimer(void *);
void TLobby__sub_804078B4(void);
s32 TLobby__sub_80407358(void) {
    Tbl_80408718 *g = &lbl_805C1AB0;
    s32 tmp[2];
    TLobby::release_slot_by_id(0x806);
    NetUnregisterTimer((void *)TLobby__sub_804078B4);
    TLobby__sub_803F8A24(g);
    g->count = 0;
    g->h2 = 0;
    g->h4 = 0;
    g->h8 = 0;
    return 0;
}

void TLobby__sub_804073B8(void) {
    TUdpSocket__sub_80407508();
}

s32 TLobby::dispatch_slot_a(s16 arg0, s32 arg1) {
    return TLobby__sub_80407C60(arg0, arg1);
}

s32 TLobby::dispatch_slot_b(s16 arg0, s32 arg1) {
    return TLobby__sub_80407D98(arg0, arg1);
}

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

s32 TLobby__sub_80407418(s16 id) {
    Tbl_80407418 *t = (Tbl_80407418 *)&lbl_805C1AB0;
    Ent_80407418 *e;
    s16 ok;
    s32 tmp[2];

    e = t->ents;
    if (id >= 0 && id < t->count) {
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
    if (e->active == 0) {
        return -2;
    }
    TLobby::call_entry_callback(e->a, e->b);
    TLobby__sub_80408388(id);
    return 0;
}

s32 TLobby::forward_net_op(s16 arg0, u8 *arg1, u8 *arg2) {
    return TLobby__sub_8040799C(arg0, arg1, arg2);
}

s16 TLobby::forward_net_op_5args(s16 arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4, s32 arg5, s16 arg6, s32 arg7) {
    return TLobby__sub_80407F20(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7);
}

struct Node_80407C60 { Node_80407C60 *next; s16 used; u8 addr[4]; };
struct Peer_8040799C;
struct Conn_8040799C { Peer_8040799C *a; s16 f4; s16 f6; s16 f8; u8 padA[2]; u8 *fC; };
struct Peer_8040799C { s16 st; s16 f2; u8 pad4; u8 f5; u8 pad6[2]; Conn_8040799C *conn; u8 addr[6]; u8 name[6]; };
struct Ent_8040799C { s16 f0; s16 f2; s16 f4; s16 f6; s16 f8; s16 fA; s16 fC; u8 fE; u8 fF; s16 f10; u8 a12[6]; u8 a18[4]; Node_80407C60 *head; };
struct Tbl_8040799C { s16 count; s16 h2; s16 h4; s16 h6; s16 h8; s16 hA; s16 hC; u8 padE[2]; Peer_8040799C *list; Ent_8040799C *ents; Node_80407C60 *nodes; Conn_8040799C *bufs; u8 *pool; };
/* ARP header (ethertype 0x806): hardware/protocol type and lengths, then the opcode and the addresses. */
struct Arp_8040799C { u8 hdr[6]; u16 op; u8 body[1]; };
struct Out_8040799C { Arp_8040799C *a; void *b; void *c; void *d; void *e; };
void TLobby__sub_80408060(Peer_8040799C *peer, NetPacket *pkt);
struct Ent_80408428;
struct Ent_80408428 *find_or_add_peer_entry__6TLobbyFsiUcPvUcPvs(s16, s32, u8, void *, u8, void *, s16);

#define TBL ((Tbl_8040799C *)&lbl_805C1AB0)

typedef void (*Handler_8041A130)(s32, s16, s16, s16);
s32 register_protocol_handler__6TLobbyFUsi(u16 type, Handler_8041A130 fn);
s32 TLobby__sub_80407640(void *data, s16 len, s16 id, s32 type);

s32 TUdpSocket__sub_80407508(void) {
    s16 n4;
    Ent_8040799C *e;
    Peer_8040799C *p;
    s16 n2;
    s16 n3;
    s16 n1;
    Node_80407C60 *q;
    Conn_8040799C *b;
    Tbl_8040799C *t = TBL;
    s16 *size;
    u8 *data;

    ((TLobby *)TBL)->init_net_buffer_config();
    for (n1 = t->count, p = t->list; n1 > 0; p++, n1--) {
        NetMemset(p, 0, sizeof(Peer_8040799C));
        p->st = 0;
        p->conn = NULL;
    }
    for (n2 = t->h2, e = t->ents; n2 > 0; e++, n2--) {
        NetMemset(e, 0, sizeof(Ent_8040799C));
    }
    size = &t->h6;
    for (n3 = t->h4, b = t->bufs, data = t->pool; n3 > 0; b++, n3--) {
        NetMemset(b, 0, sizeof(Conn_8040799C));
        b->f8 = *size;
        b->fC = data;
        data += *size;
    }
    for (n4 = t->h8, q = t->nodes; n4 > 0; q++, n4--) {
        NetMemset(q, 0, sizeof(Node_80407C60));
    }
    register_protocol_handler__6TLobbyFUsi(0x806, (Handler_8041A130)TLobby__sub_80407640);
    NetRegisterTimer(60000, 1, (NetTimerCallback)TLobby__sub_804078B4);
    return 0;
}

inline Peer_8040799C *Find_8040799C(Tbl_8040799C *t, u8 k, void *name) {
    s16 n = t->count;
    Peer_8040799C *p = t->list;
    for (; n > 0; n--, p++) {
        if (p->f5 == k && p->st != 0 && NetMemcmp(p->name, name, p->f5) == 0) {
            return p;
        }
    }
    return NULL;
}

inline Ent_8040799C *FindEnt_80407640(Tbl_8040799C *t, s16 id, s16 type) {
    s16 i;
    s16 n;
    Ent_8040799C *e;

    if (id < 0) {
        return NULL;
    }
    e = t->ents;
    n = t->h2;
    for (i = 0; i < n; i++, e++) {
        if (e->f0 == 1 && e->f2 == id && e->f6 == type) {
            return e;
        }
    }
    return NULL;
}

inline s16 Check_80407640(Arp_8040799C *pkt, Ent_8040799C *e) {
    if (NetMemcmp(pkt, &e->fA, 6) == 0 && (pkt->op == 1 || pkt->op == 2)) {
        return 1;
    }
    return -1;
}

s16 TLobby__sub_804082AC(Ent_8040799C *e, Out_8040799C *o, void *out);

#pragma push
#pragma opt_common_subs on
s32 TLobby__sub_80407640(void *data, s16 len, s16 id, s32 type) {
    Tbl_8040799C *t = TBL;
    Arp_8040799C *pkt;
    Ent_8040799C *e;
    Out_8040799C o;
    u8 buf[8];
    Out_8040799C r;
    u8 *q;
    void *s;

    if (len < 8) {
        return -1;
    }
    if (id < 0) {
        return -1;
    }
    e = FindEnt_80407640(t, id, type);
    if (e == NULL) {
        return -1;
    }
    pkt = (Arp_8040799C *)data;
    if (Check_80407640(pkt, e) < 0) {
        return -1;
    }
    o.a = pkt;
    q = pkt->body;
    o.b = q;
    q += e->fE;
    o.c = q;
    q += e->fF;
    o.d = q;
    q += e->fE;
    o.e = q;
    if (Find_8040799C(t, e->fF, o.c) != NULL) {
        find_or_add_peer_entry__6TLobbyFsiUcPvUcPvs(e->f2, e->f4, e->fF, o.c, e->fE, o.b, 2);
    }
    if (pkt->op == 1 && TLobby__sub_804082AC(e, &o, buf) > 0) {
        s = alloc_packet_with_header__6TLobbyFPvPv((Out_804081C0 *)&r, (u8 *)e);
        if (s != NULL) {
            r.a->op = 2;
            NetMemcpy(r.b, buf, e->fE);
            NetMemcpy(r.d, o.b, e->fE);
            NetMemcpy(r.c, o.e, e->fF);
            NetMemcpy(r.e, o.c, e->fF);
            TLobby::call_handler_by_index(e->f2, type, 0, (s32)o.b, (s32)s);
            if (s != NULL) {
                ((TUdpSocket *)s)->release_entry();
            }
        }
    }
    return 0;
}
#pragma pop

#pragma push
#pragma dont_inline off
inline void clear_peer_conn_804078B4(Peer_8040799C *p) {
    if (p->conn != NULL) {
        p->conn->a = 0;
        p->conn->f6 = 0;
        p->conn->f4 = 0;
    }
}

void TLobby__sub_804078B4(void) {
    Peer_8040799C *p;
    s16 n;

    n = TBL->count;
    p = TBL->list;

    for (; n > 0; n--, p++) {
        if (p->st == 0) {
            continue;
        }
        if (p->f2 != 0) {
            p->f2--;
        }
        if (p->f2 != 0 || p->st == 4 || p->st == 8) {
            continue;
        }
        if (p->conn != NULL) {
            clear_peer_conn_804078B4(p);
            p->conn = NULL;
        }
        p->st = 0;
        p->f2 = 0;
        NetMemset(p->addr, 0, 6);
        NetMemset(p->name, 0, 4);
    }
}
#pragma pop

#pragma push
#pragma dont_inline off
#pragma inline_depth(4)
inline Ent_8040799C *Lookup_8040799C(Tbl_8040799C *t, s16 idx) {
    Ent_8040799C *list = t->ents;
    s16 ok;
    if (idx >= 0 && idx < t->h2) {
        ok = 1;
    } else {
        ok = -1;
    }
    if (ok >= 0) {
        return &list[idx];
    }
    return NULL;
}

inline void Clear_8040799C(Peer_8040799C *p) {
    if (p->conn != NULL) {
        p->conn->a = 0;
        p->conn->f6 = 0;
        p->conn->f4 = 0;
    }
}

inline void Send_8040799C(Ent_8040799C *e, void *name) {
    Out_8040799C o;
    void *r = alloc_packet_with_header__6TLobbyFPvPv((Out_804081C0 *)(&o), (u8 *)e);
    if (r != NULL) {
        o.a->op = 1;
        NetMemcpy(o.b, e->a12, e->fE);
        NetMemcpy(o.c, e->a18, e->fF);
        NetMemset(o.d, 0, e->fE);
        NetMemcpy(o.e, name, e->fF);
        TLobby::call_handler_by_index(e->f2, e->f6, 1, 0, (s32)r);
        if (r != NULL) {
            ((TUdpSocket *)r)->release_entry();
        }
    }
}

s32 TLobby__sub_8040799C(s16 idx, void *name, void *arg2) {
    Tbl_8040799C *t = TBL;
    Ent_8040799C *e;
    Peer_8040799C *p;
    s32 ret;
    Peer_8040799C *np;

    e = Lookup_8040799C(t, idx);
    if (e == NULL) {
        return -2;
    }
    ret = 0;
    p = Find_8040799C(t, e->fF, name);
    if (p != NULL) {
        p->f2 = t->hA;
        if (p->st != 1) {
            ret = TLobby::call_handler_by_index(e->f2, e->f4, 0, (s32)p->addr, (s32)arg2);
        } else {
            if (p->conn != NULL) {
                Clear_8040799C(p);
                p->conn = NULL;
            }
            TLobby__sub_80408060(p, (NetPacket *)arg2);
            Send_8040799C(e, name);
            p->f2 = t->hC;
        }
    } else {
        u8 buf[6];
        NetMemset(buf, 0, 6);
        np = (Peer_8040799C *)find_or_add_peer_entry__6TLobbyFsiUcPvUcPvs(e->f2, e->f4, e->fF, name, e->fE, buf, 1);
        TLobby__sub_80408060(np, (NetPacket *)arg2);
        Send_8040799C(e, name);
        np->f2 = t->hC;
    }
    return ret;
}

s32 TLobby__sub_80407C60(s16 idx, s32 addr) {
    Tbl_8040799C *t = TBL;
    Ent_8040799C *e;
    Node_80407C60 *prev;
    Node_80407C60 *p;
    s16 k;

    e = Lookup_8040799C(t, idx);
    if (e == NULL) {
        return -1;
    }
    if (e->f0 == 0) {
        return -1;
    }
    if (e->head == NULL) {
        return -1;
    }
    p = e->head;
    k = 0;
    while (p->next != NULL) {
        k++;
        if (t->h8 <= k) {
            return -1;
        }
        if (NetMemcmp(p->addr, (void *)addr, 4) == 0) {
            if (e->head == p) {
                e->head = p->next;
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

inline Node_80407C60 *AllocNode_80407D98(Tbl_8040799C *t, s16 *count) {
    Node_80407C60 *p = t->nodes;
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

s32 TLobby__sub_80407D98(s16 idx, s32 addr) {
    s16 lim;
    Node_80407C60 *next;
    Node_80407C60 *p;
    Ent_8040799C *e;
    Node_80407C60 *node;
    s16 *max;
    Tbl_8040799C *t = TBL;
    s16 k;

    e = Lookup_8040799C(t, idx);
    if (e == NULL) {
        return -1;
    }
    if (e->f0 == 0) {
        return -1;
    }
    node = AllocNode_80407D98(t, max = &t->h8);
    if (node == NULL) {
        return -1;
    }
    NetMemcpy(node->addr, (void *)addr, 4);
    node->used = 1;
    node->next = NULL;
    if (e->head == NULL) {
        e->head = node;
    } else {
        lim = *max;
        p = e->head;
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

s16 TLobby__sub_8040A044(s16 i, s32 type, s16 len, u8 *addr);
inline Ent_8040799C *find_free_entry(Ent_8040799C *e, s16 n) {
    s16 i;
    for (i = 0; i < n; i++, e++) {
        if (e->f0 == 0) {
            return e;
        }
    }
    return NULL;
}

s16 TLobby__sub_80407F20(s16 iface, s16 a1, s16 a2, s16 a3, s16 len12, s32 src12, s16 len18, s32 src18) {
    Ent_8040799C *ents;
    Ent_8040799C *e;
    s16 h;
    s16 idx;

    if (iface < 0) {
        return -1;
    }
    h = TLobby__sub_8040A044(iface, 0x806, len18, (u8 *)src18);
    if (h < 0) {
        return h;
    }
    ents = TBL->ents;
    e = find_free_entry(ents, TBL->h2);
    if (e == NULL) {
        TLobby::call_entry_callback(iface, h);
        return -0x10D;
    }
    e->f0 = 1;
    idx = e - ents;
    e->f2 = iface;
    e->f4 = a1;
    e->f6 = h;
    e->f8 = idx;
    e->fA = a2;
    e->fC = a3;
    e->fE = len12;
    e->fF = len18;
    e->f10 = 0;
    NetMemcpy(e->a12, (void *)src12, len12);
    NetMemcpy(e->a18, (void *)src18, len18);
    e->head = NULL;
    return idx;
}

void TLobby__sub_80408060(Peer_8040799C *peer, NetPacket *pkt) {
    Conn_8040799C *slot;
    s16 total;
    Conn_8040799C *oldest;
    Conn_8040799C *c;
    s16 n;
    Peer_8040799C *owner;
    s16 i;
    u8 *data;
    NetBufferRef ref;

    total = 0;
    slot = NULL;
    c = TBL->bufs;
    n = TBL->h4;
    oldest = NULL;
    for (; n > 0; c++, n--) {
        if (c->f4 == 0) {
            slot = c;
            break;
        }
        if (oldest == NULL) {
            oldest = c;
        } else if (c->a->f2 < oldest->a->f2) {
            oldest = c;
        }
    }
    if (slot == NULL) {
        owner = oldest->a;
        Clear_8040799C(owner);
        owner->conn = NULL;
        slot = oldest;
    }
    if (slot->f8 < (s16)pkt->total_bytes) {
        return;
    }
    slot->f4 = 1;
    data = slot->fC;
    for (i = pkt->fragment_count; i > 0; i--) {
        ((TLobby *)&ref)->set_value_and_enable((s32)data);
        TLobby__sub_80406FD8(&ref, &pkt->fragments[i - 1].buffer, pkt->fragments[i - 1].length);
        data += pkt->fragments[i - 1].length;
        total += pkt->fragments[i - 1].length;
    }
    slot->f6 = total;
    slot->a = peer;
    peer->conn = slot;
}
#pragma pop
#undef TBL

typedef struct Pool_804082AC { u8 pad0[8]; s16 f8; } Pool_804082AC;

struct Tbl_80408718;
Pkt_804081C0 *alloc_packet_with_header__6TLobbyFPvPv(Out_804081C0 *arg0, u8 *arg1) {
    s16 len;
    Pkt_804081C0 *pkt;
    u8 *buf;
    u16 t;
    u8 *q;
    t = arg1[0xE] * 2 + 8;
    t += arg1[0xF] * 2;
    len = t;
    if ((u32)len > 0x1CU) {
        return NULL;
    }
    pkt = (Pkt_804081C0 *)TLobby::alloc_free_entry();
    if (pkt == NULL) {
        return NULL;
    }
    pkt->f4 = 1;
    pkt->f8 = len;
    buf = (u8 *)&((Pool_804081C0 *)&lbl_805C1AB0)->f24;
    pkt->fC = t;
    ((TLobby *)(pkt->f10))->set_value_and_enable(*(s32 *)buf);
    buf = *(u8 **)buf;
    NetMemset(buf, 0, len);
    NetMemcpy(buf, arg1 + 0xA, 6);
    arg0->f0 = buf;
    q = buf + 8;
    arg0->f4 = q;
    q += arg1[0xE];
    arg0->f8 = q;
    q += arg1[0xF];
    arg0->fC = q;
    q += arg1[0xE];
    arg0->f10 = q;
    return pkt;
}

s16 TLobby__sub_804082AC(Ent_8040799C *e, Out_8040799C *o, void *out) {
    s16 i;
    Node_80407C60 *p;

    if (NetMemcmp(e->a18, o->e, e->fF) == 0) {
        NetMemcpy(out, e->a12, e->fE);
        return 1;
    }
    if (e->head != NULL) {
        p = e->head;
        i = 0;
        while (p != NULL) {
            i++;
            if (lbl_805C1AB0.h8 <= i) {
                return -1;
            }
            if (NetMemcmp(p->addr, o->e, e->fF) == 0) {
                NetMemcpy(out, e->a12, e->fE);
                return 1;
            }
            p = p->next;
        }
    }
    return -1;
}

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

s32 TLobby__sub_80408388(s16 id) {
    Tbl_80408388 *t = (Tbl_80408388 *)&lbl_805C1AB0;
    Ent_80408388 *e;
    Node_80408388 *n;
    Node_80408388 *next;
    s16 ok;

    e = t->ents;
    if (id >= 0 && id < t->count) {
        ok = 1;
    } else {
        ok = -1;
    }
    if (ok >= 0) {
        e = &e[id];
        for (n = e->head; n != NULL; n = next) {
            next = n->next;
            n->next = NULL;
            n->used = 0;
        }
        NetMemset(e, 0, 0x20);
        return 1;
    }
    return -1;
}

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
Ent_804086B4 *find_oldest_peer_entry__6TLobbyFs(s16 key);

#pragma push
#pragma inline_depth(4)
#pragma dont_inline off

inline Ent_80408428 *find_80408428(Tbl_80408428 *t, u8 type, void *addr) {
    s16 n = t->count;
    Ent_80408428 *e = t->list;
    while (n > 0) {
        if (e->type5 == type && e->state != 0 && NetMemcmp(e->addr12, addr, e->type5) == 0) {
            return e;
        }
        n--;
        e++;
    }
    return NULL;
}

inline void detach_80408428(Ent_80408428 *e) {
    if (e->sub != NULL) {
        e->sub->f0 = 0;
        e->sub->f6 = 0;
        e->sub->f4 = 0;
    }
    e->sub = NULL;
}

Ent_80408428 *find_or_add_peer_entry__6TLobbyFsiUcPvUcPvs(s16 arg0, s32 arg1, u8 type, void *addr, u8 type2, void *addr2, s16 state) {
    Tbl_80408428 *t = (Tbl_80408428 *)&lbl_805C1AB0;
    Ent_80408428 *e;
    Pkt_80408428 *p;

    e = find_80408428(t, type, addr);
    if (e != NULL) {
        e->stamp = t->stampA;
        if (addr2 == NULL) {
            return e;
        }
        if (e->state != 1) {
            int n2 = type2;
            if (NetMemcmp(e->addrC, addr2, n2) != 0) {
                NetMemcpy(e->addrC, addr2, n2);
                e->state = state;
            }
            return e;
        }
        NetMemcpy(e->addrC, addr2, type2);
        e->state = state;
        if (e->sub != NULL) {
            p = (Pkt_80408428 *)TLobby::alloc_free_entry();
            if (p != NULL) {
                p->f4 = 1;
                p->f8 = e->sub->f6;
                p->fC = e->sub->f6;
                ((TLobby *)(p->f10))->set_value_and_enable(e->sub->fC);
                TLobby::call_handler_by_index(arg0, arg1, 0, (s32)e->addrC, (s32)p);
                ((TUdpSocket *)p)->release_entry();
            }
        }
        detach_80408428(e);
        return e;
    }
    if (addr2 == NULL) {
        return NULL;
    }
    e = (Ent_80408428 *)find_free_peer_entry__6TLobbyFv();
    if (e == NULL) {
        e = (Ent_80408428 *)find_oldest_peer_entry__6TLobbyFs(4);
        if (e == NULL) {
            e = (Ent_80408428 *)find_oldest_peer_entry__6TLobbyFs(0);
        }
        if (e->sub != NULL) {
            detach_80408428(e);
        }
        e->state = 0;
        e->stamp = 0;
        NetMemset(e->addrC, 0, 6);
        NetMemset(e->addr12, 0, 4);
    }
    if (addr2 != NULL) {
        NetMemcpy(e->addrC, addr2, type2);
    }
    NetMemcpy(e->addr12, addr, type);
    e->type4 = type2;
    e->type5 = type;
    e->state = state;
    e->stamp = t->stampA;
    e->sub = NULL;
    return e;
}

#pragma pop
struct Ent_804086B4 { s16 f0; s16 f2; u8 pad[0x14]; };
struct Tbl_804086B4 { s16 count; u8 pad[0xE]; Ent_804086B4 *list; };
Ent_804086B4 *find_oldest_peer_entry__6TLobbyFs(s16 key) {
    Ent_804086B4 *best = 0;
    Ent_804086B4 *p;
    s16 n = ((Tbl_804086B4 *)&lbl_805C1AB0)->count;
    s32 v;
    p = ((Tbl_804086B4 *)&lbl_805C1AB0)->list;
    for (; n > 0; n--, p++) {
        v = p->f0;
        if ((s16)v != 0 && v != key) {
            if (best == 0) {
                best = p;
            } else if (best->f2 > p->f2) {
                best = p;
            }
        }
    }
    return best;
}

Ent_80408718 *find_free_peer_entry__6TLobbyFv(void) {
    s16 n = lbl_805C1AB0.count;
    Ent_80408718 *e = lbl_805C1AB0.list;
    while (n > 0) {
        if (e->f0 == 0) {
            return e;
        }
        n--;
        e++;
    }
    return NULL;
}

void TLobby::flush_flags_step() {
    TLobby__sub_8040878C();
}

void TLobby::run_connect_step() {
    TLobby::init_net_sockets();
}

typedef void (*Fn_8040881C)(void);
typedef s16 (*Init_8040881C)(s16);

struct Desc_8040881C {
    Init_8040881C fn;
    u8 pad4[0x18];
};

struct Ent_8040881C {
    s16 used;
    s16 id;
    s16 idx;
    u8 pad6[0xA];
};

struct G_8040881C {
    s16 count;
    s16 n2;
    s16 n4;
    s16 n6;
    Desc_8040881C *descs;
    Ent_8040881C *ents;
    void *p10;
    void *p14;
};

s32 TLobby__sub_80408F2C(s16 id, u8 *pkt);
s32 TLobby__sub_80409130(s16 arg0, s16 arg1, s32 arg2);
s32 TLobby__sub_80408FD8(s16 idx, s16 op, u8 *addr);
s32 TLobby__sub_8040920C(s16 idx, u8 *mac);
s32 TLobby__sub_804092FC(s16 idx);
s32 TLobby__sub_8040939C(s16 idx);
s32 TLobby__sub_804093EC(s16 idx);
void TLobby__sub_804094B8(void);
s32 TLobby__sub_8040970C(s16 id, u8 *out);
struct Tbl_80408F2C;
#define LG_8040881C (*(G_8040881C *)&lbl_805C1AD8)
void TLobby__sub_803F8AB8(void *);
s32 TLobby__sub_8040878C(void) {
    s16 n = LG_8040881C.count;
    s16 i = 0;
    Ent_8040881C *e = LG_8040881C.ents;

    for (; i < n; i++, e++) {
        if (e->used != 0) {
            TLobby::clear_table_entry_locked(e->id);
            e->used = 0;
            e->id = 0;
            e->idx = 0;
        }
    }
    LG_8040881C.n2 = 0;
    LG_8040881C.n4 = 0;
    LG_8040881C.n6 = 0;
    TLobby__sub_803F8AB8(&LG_8040881C);
    return 0;
}

s16 TLobby::init_net_sockets() {
    Fn_8040881C fns[11];
    s16 r;
    s16 first;
    s16 cnt;
    s16 i;
    Ent_8040881C *e;
    Desc_8040881C *d;
    Ent_8040881C **pe;

    ((TLobby *)((Desc_803F8AD8 *)&LG_8040881C))->init_net_func_table();
    pe = &LG_8040881C.ents;
    NetMemset(*pe, 0, LG_8040881C.n2 * 0x10);
    NetMemset(LG_8040881C.p10, 0, LG_8040881C.n4 * 0x10);
    NetMemset(LG_8040881C.p14, 0, LG_8040881C.n6 * 0x5F8);
    fns[0] = (Fn_8040881C)TLobby__sub_8040970C;
    fns[1] = TLobby__sub_804094B8;
    fns[2] = (Fn_8040881C)TLobby__sub_804093EC;
    fns[3] = (Fn_8040881C)TLobby__sub_8040939C;
    fns[4] = (Fn_8040881C)TLobby__sub_804092FC;
    fns[5] = (Fn_8040881C)TLobby__sub_8040920C;
    fns[6] = (Fn_8040881C)TLobby__sub_80409130;
    fns[7] = (Fn_8040881C)TLobby__sub_80408FD8;
    fns[8] = (Fn_8040881C)TLobby__sub_80408F2C;
    fns[9] = (Fn_8040881C)TLobby::forward_socket_op_by_handle;
    fns[10] = (Fn_8040881C)TLobby::send_ethernet_frame;
    first = -1;
    cnt = LG_8040881C.count;
    d = LG_8040881C.descs;
    e = *pe;
    i = 0;
    while (i < cnt) {
        if (d->fn != NULL) {
            r = d->fn(i);
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
        e->idx = i;
        d++;
        i++;
        e++;
    }
    return first;
}


struct EtherRxBuffer {
    s16 used;
    s16 iface;
    s16 slot;
    s16 handler;
    s16 len;
    u8 data[0x5EE];
};
struct EtherProtocolBinding {
    s16 used;
    s16 handler;
    s16 iface;
    u16 ether_type;
    u8 pad8[4];
    EtherRxBuffer *buf;
};
struct EtherRxTable {
    u8 pad0[4];
    s16 nbindings;
    s16 nbufs;
    u8 pad8[8];
    EtherProtocolBinding *bindings;
    EtherRxBuffer *bufs;
};

#pragma push
#pragma dont_inline off
#pragma inline_depth(4)
inline EtherProtocolBinding *find_protocol_binding(EtherProtocolBinding *e, s16 n, s16 iface, u16 type) {
    for (; n > 0; n--, e++) {
        if (e->used != 0 && e->iface == iface && e->ether_type == type) {
            return e;
        }
    }
    return NULL;
}

inline EtherRxBuffer *alloc_rx_buffer(EtherRxBuffer *b, s16 n, s16 iface, s16 slot, s16 handler, s16 len) {
    for (; n > 0; n--, b++) {
        if (b->used == 0) {
            b->used = 1;
            b->iface = iface;
            b->slot = slot;
            b->handler = handler;
            b->len = len;
            return b;
        }
    }
    return NULL;
}

u8 *TLobby__sub_804089A8(s16 iface, s16 op, s16 len, u8 *pkt) {
    EtherRxTable *t = (EtherRxTable *)&lbl_805C1AD8;
    EtherProtocolBinding *ents;
    EtherProtocolBinding *e;
    EtherRxBuffer *b;
    s16 slot;
    u16 type;
    EthernetFrameHeader hdr;

    NetMemcpy(hdr.destination, pkt, 6);
    NetMemcpy(hdr.source, pkt + 6, 6);
    NetMemcpy(&hdr.ether_type, pkt + 12, 2);
    if (op == 0) {
        if (len > 0x5EA) {
            return NULL;
        }
        ents = t->bindings;
        e = find_protocol_binding(ents, t->nbindings, iface, hdr.ether_type);
        if (e == NULL) {
            return NULL;
        }
        e->buf = NULL;
        slot = e - ents;
        b = alloc_rx_buffer(t->bufs, t->nbufs, iface, slot, e->handler, len);
        if (b == NULL) {
            return NULL;
        }
        e->buf = b;
        return b->data;
    } else if (op == 1) {
        ents = t->bindings;
        type = hdr.ether_type;
        e = find_protocol_binding(ents, t->nbindings, iface, type);
        if (e == NULL) {
            return NULL;
        }
        b = e->buf;
        slot = e - ents;
        if (b == NULL) {
            return NULL;
        }
        if (b->iface != iface || b->slot != slot || b->handler != e->handler || b->len != len) {
            s32 lvl = OSDisableInterrupts();
            b->used = 0;
            b->iface = 0;
            b->slot = 0;
            b->handler = 0;
            b->len = 0;
            OSRestoreInterrupts(lvl);
            return NULL;
        }
        TLobby__sub_80409818((s32)(b->data + sizeof(EthernetFrameHeader)), b->len - sizeof(EthernetFrameHeader), b->handler, b->slot, type);
        return NULL;
    }
    return NULL;
}
#pragma pop

typedef s32 (*SendFn_80408C24)(s16, u8 *, s16);
typedef void (*CloseFn_80408C24)(s16, u16);
typedef s32 (*McastFn_80408C24)(s16, u8 *);
struct If_80408C24 { u8 pad[8]; CloseFn_80408C24 f8; McastFn_80408C24 fC; McastFn_80408C24 f10; s16 (*f14)(s16, u8 *); SendFn_80408C24 send; };
struct Conn_80408C24 { s16 used; s16 id; s16 handle; u8 mac[6]; u8 *buf; };
struct Ent_80408C24 { s16 used; s16 id; s16 iface; u16 type; s16 f8; u8 padA[2]; s32 fC; };
struct Glob_80408C24 {
    s16 f0;
    s16 nconn;
    s16 nent;
    s16 f6;
    If_80408C24 *ifaces;
    Conn_80408C24 *conns;
    Ent_80408C24 *ents;
};
struct Hdr_80408C24 { u8 dst[6]; u8 src[6]; u16 type; };

s16 TLobby__sub_804098B4(NetPacket *pkt);
s16 TLobby__sub_80409908(u8 *dst, NetPacket *pkt);
u8 *TLobby__sub_8042558C(u32 size);
struct Tbl_80408F2C;

#pragma push
#pragma dont_inline off
#pragma inline_depth(4)
inline Conn_80408C24 *find_conn_80408C24(Glob_80408C24 *g, s16 id) {
    s16 n;
    Conn_80408C24 *c;
    c = g->conns;
    n = g->nconn;
    for (; n > 0; n--, c++) {
        if (c->used != 0 && c->id == id) {
            return c;
        }
    }
    return NULL;
}

s32 TLobby::send_ethernet_frame(s16 idx, s16 mode, u8 *addr, void *pkt) {
    void NetMemset(void *, int, int);
    void NetMemcpy(void *, void *, int);
    Glob_80408C24 *g = (Glob_80408C24 *)&lbl_805C1AD8;
    Hdr_80408C24 hdr;
    Conn_80408C24 *c;
    Ent_80408C24 *e;
    s16 len;
    SendFn_80408C24 fn;

    if (idx < 0 || idx >= g->nent) {
        return -0x111;
    }
    e = g->ents;
    e += idx;
    if (e->used == 0) {
        return -2;
    }
    c = find_conn_80408C24(g, e->id);
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
    c->buf = TLobby__sub_8042558C(0x5EA);
    if (c->buf == NULL) {
        return 0;
    }
    NetMemcpy(hdr.src, c->mac, 6);
    hdr.type = e->type;
    NetMemcpy(c->buf, &hdr, 0xE);
    len = TLobby__sub_804098B4((NetPacket *)pkt);
    if (len > 0x5DC) {
        TLobby::clear_message_entry((s32)c->buf);
        return -2;
    }
    TLobby__sub_80409908(c->buf + 0xE, (NetPacket *)pkt);
    if (len + 0xE < 0x3C) {
        len = 0x2E;
    }
    fn = g->ifaces[e->iface].send;
    if (fn != NULL) {
        fn(c->handle, c->buf, len + 0xE);
    } else {
        TLobby::clear_message_entry((s32)c->buf);
        return -0x111;
    }
    return 0;
}
#pragma pop

typedef char RecoveredGlobal_80409A3C_lbl_805C1C50_size[sizeof(RecoveredGlobal_80409A3C_lbl_805C1C50) == 0xF8 ? 1 : -1];

typedef struct Ent_80408E98 {
    s16 active;
    u8 pad2[4];
    u16 type;
    s16 sock;
    u8 padA[6];
} Ent_80408E98;

typedef struct Tbl_80408E98 {
    u8 pad0[4];
    s16 count;
    u8 pad6[0xA];
    Ent_80408E98 *ents;
} Tbl_80408E98;

#define TBL_80408E98 ((Tbl_80408E98 *)&lbl_805C1AD8)

s32 TLobby::forward_socket_op_by_handle(s16 id, u8 *a, u8 *b) {
    Ent_80408E98 *e;
    s32 sock;

    if (id < 0 || id >= TBL_80408E98->count) {
        return -0x111;
    }
    e = TBL_80408E98->ents;
    e += id;
    if (e->active == 0) {
        return -2;
    }
    switch (e->type) {
    case 0x800:
        sock = e->sock;
        if ((s16)sock >= 0) {
            return TLobby::forward_net_op(sock, a, b);
        }
        return -2;
    default:
        return -2;
    }
}
#undef TBL_80408E98

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

s32 TLobby__sub_80408F2C(s16 id, u8 *pkt) {
    Tbl_80408F2C *t = &lbl_805C1AD8;
    Buf_80408F2C *b;
    u8 *data;
    s16 n;
    s16 i;

    if (id < 0 || id >= t->count) {
        return -0x111;
    }
    b = t->bufs;
    data = pkt - 0xE;
    n = t->nbufs;
    i = 0;
    while (i < n) {
        if (b->data == data) {
            s32 lvl = OSDisableInterrupts();
            b->h0 = 0;
            b->h2 = 0;
            b->h4 = 0;
            b->h6 = 0;
            b->h8 = 0;
            OSRestoreInterrupts(lvl);
            return 0;
        }
        i++;
        b++;
    }
    return -2;
}

s32 TLobby__sub_80408FD8(s16 idx, s16 op, u8 *addr) {
    Glob_80408C24 *g = (Glob_80408C24 *)&lbl_805C1AD8;
    Ent_80408C24 *e;
    If_80408C24 *ifc;
    u16 type;
    u8 mac[6];

    if (idx < 0 || idx >= g->nent) {
        return -0x111;
    }
    e = g->ents;
    e += idx;
    if (e->used == 0) {
        return -2;
    }
    type = e->type;
    if (type == 0x800 || type == 0x86DD) {
        ifc = g->ifaces;
        ifc += e->iface;
        if (ifc->fC == NULL) {
            return -0x111;
        }
        if (type == 0x800) {
            mac[0] = 1;
            mac[1] = 0;
            mac[2] = 5;
            mac[3] = addr[1] & 0x7F;
            mac[4] = addr[2];
            mac[5] = addr[3];
        } else {
            mac[0] = 0x33;
            mac[1] = 0x33;
            mac[2] = addr[12];
            mac[3] = addr[13];
            mac[4] = addr[14];
            mac[5] = addr[15];
        }
        if (op == 1) {
            return ifc->fC(e->iface, mac);
        }
        if (op == 2) {
            return ifc->f10(e->iface, mac);
        }
        return -2;
    }
    return -2;
}

typedef struct Sock_80409130 { s16 f0; u8 pad2[4]; u16 f6; s16 f8; u8 padA[6]; } Sock_80409130;

s32 TLobby__sub_80409130(s16 arg0, s16 arg1, s32 arg2) {
    s32 h;
    Sock_80409130 *e;

    if (arg0 < 0 || arg0 >= lbl_805C1AD8.count) {
        return -0x111;
    }
    e = *(Sock_80409130 **)((s8 *)(&lbl_805C1AD8) + 0x10);
    e += arg0;
    if (e->f0 == 0) {
        return -2;
    }
    switch (e->f6) {
    case 0x800:
        h = e->f8;
        if ((s16)h < 0) {
            return -2;
        }
        if (arg1 == 1) {
            return TLobby::dispatch_slot_b(h, arg2);
        }
        if (arg1 == 2) {
            return TLobby::dispatch_slot_a(h, arg2);
        }
        return -2;
    default:
        return -2;
    case 0x86DD:
        return 0;
    }
}

#pragma push
#pragma dont_inline off
#pragma inline_depth(4)
s32 TLobby__sub_8040920C(s16 idx, u8 *mac) {
    Glob_80408C24 *g = (Glob_80408C24 *)&lbl_805C1AD8;
    Ent_80408C24 *e;
    Conn_80408C24 *c;

    if (idx < 0 || idx >= g->nent) {
        return -0x111;
    }
    e = g->ents;
    e += idx;
    if (e->used == 0) {
        return -2;
    }
    c = find_conn_80408C24(g, e->id);
    if (c == NULL) {
        return -2;
    }
    if (g->ifaces[e->iface].f14 != NULL) {
        NetMemcpy(mac, c->mac, 6);
    } else {
        return -0x111;
    }
    return 0;
}

s32 TLobby__sub_804092FC(s16 idx) {
    Glob_80408C24 *g = (Glob_80408C24 *)&lbl_805C1AD8;
    Ent_80408C24 *e;

    if (idx < 0 || idx >= g->nent) {
        return -0x111;
    }
    e = g->ents;
    e += idx;
    if (e->used == 0) {
        return -2;
    }
    if (find_conn_80408C24(g, e->id) == NULL) {
        return -2;
    }
    return 6;
}
#pragma pop

s32 TLobby__sub_8040939C(s16 idx) {
    Ent_80408C24 *e;

    if (idx < 0 || idx >= ((Glob_80408C24 *)&lbl_805C1AD8)->nent) {
        return -0x111;
    }
    e = ((Glob_80408C24 *)&lbl_805C1AD8)->ents;
    e += idx;
    if (e->used == 0) {
        return -2;
    }
    return 1500;
}

s32 TLobby__sub_804093EC(s16 idx) {
    Glob_80408C24 *g = (Glob_80408C24 *)&lbl_805C1AD8;
    Ent_80408C24 *e;
    CloseFn_80408C24 fn;
    s32 h;

    if (idx < 0 || idx >= g->nent) {
        return -0x111;
    }
    e = g->ents;
    e += idx;
    if (e->used == 0) {
        return -2;
    }
    h = e->f8;
    if ((s16)h >= 0) {
        TLobby__sub_80407418(h);
    }
    fn = g->ifaces[e->iface].f8;
    if (fn != NULL) {
        fn(e->iface, e->type);
    }
    e->used = 0;
    e->id = 0;
    e->iface = 0;
    e->type = 0;
    e->f8 = 0;
    e->fC = 0;
    return 0;
}

#pragma push
#pragma dont_inline off
#pragma inline_depth(4)
s32 TLobby__sub_8040970C(s16 id, u8 *out) {
    Glob_80408C24 *g = (Glob_80408C24 *)&lbl_805C1AD8;
    Conn_80408C24 *c;
    If_80408C24 *ifc;
    u8 mac[6];

    c = find_conn_80408C24(g, id);
    if (c == NULL) {
        return -0x111;
    }
    ifc = g->ifaces;
    ifc += c->handle;
    if (ifc->f14 != NULL) {
        if (ifc->f14(c->handle, mac) != 6) {
            return -0x111;
        }
    } else {
        return -0x111;
    }
    out[0] = mac[0] | 2;
    out[1] = mac[1];
    out[2] = mac[2];
    out[3] = 0xFF;
    out[4] = 0xFE;
    out[5] = mac[3];
    out[6] = mac[4];
    out[7] = mac[5];
    return 0;
}
#pragma pop

typedef struct Ent_80409818 {
    s16 active;
    u8 pad[0x22];
    void (*fn)(s16, s32);
    u8 pad28[0x8];
} Ent_80409818;

typedef struct Tbl_80409818 {
    s16 count;
    Ent_80409818 *ents;
} Tbl_80409818;

#define TBL_80409818 (*(Tbl_80409818 *)&lobby_handler_table_desc)
void TLobby__sub_80409818(s32 msg, s16 len, s16 idx, s16 arg3, u16 type) {
    if (idx < 0 || idx >= TBL_80409818.count) {
        return;
    }
    switch (type) {
    default:
        TBL_80409818.ents[idx].fn(arg3, msg);
        break;
    case 0x800:
    case 0x806:
    case 0x86DD:
        NetEnqueueProtocolMessage(msg, len, idx, arg3, type);
        break;
    }
}

#pragma push
#pragma dont_inline off
#pragma inline_depth(4)
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

s16 TLobby__sub_804098B4(NetPacket *pkt) {
    return packet_length_804098B4(pkt);
}

inline s16 copy_packet_80409908(u8 *dst, NetPacket *pkt) {
    NetBufferRef ref;
    NetPacketFragment *f;
    u8 *p;
    s16 n;
    s16 total = 0;
    n = pkt->fragment_count;
    p = dst;
    f = &pkt->fragments[n] - 1;
    for (; n > 0; n--) {
        ((TLobby *)&ref)->set_value_and_enable((s32)p);
        TLobby__sub_80406FD8(&ref, &pkt->fragments[n - 1].buffer, f->length);
        p += f->length;
        total += f->length;
        f--;
    }
    if (total != (s16)pkt->total_bytes) {
        return total;
    }
    return pkt->total_bytes;
}

s16 TLobby__sub_80409908(u8 *dst, NetPacket *pkt) {
    s16 len = copy_packet_80409908(dst, pkt);
    return len;
}
#pragma pop

#define TBL_804099B4 (*(Tbl_804099B4 *)&lobby_handler_table_desc)
s32 TLobby::clear_table_entry_locked(s16 arg0) {
    s32 ret;
    TLobby::lock_mutex(network_dispatch_state.lock_handle);
    if (arg0 < 0 || arg0 > TBL_804099B4.count) {
        ret = -0x10F;
    } else {
        Ent_804099B4 *e = TBL_804099B4.ents;
        e += arg0;
        NetMemset(e, 0, 0x30);
        ret = 0;
    }
    TUdpSocket::unlock_mutex(network_dispatch_state.lock_handle);
    return ret;
}

s16 TLobby__sub_8040A2BC(Fn_8040881C *fns, s16 kind);
s16 TLobby__sub_80409A3C(u8 *arg0, s16 arg1) {
    s16 temp_r31;
    TLobby::lock_mutex((*(RecoveredGlobal_80409A3C_lbl_805C1C50 *)&network_dispatch_state).value);
    temp_r31 = TLobby__sub_8040A2BC((Fn_8040881C *)arg0, arg1);
    TUdpSocket::unlock_mutex((*(RecoveredGlobal_80409A3C_lbl_805C1C50 *)&network_dispatch_state).value);
    return temp_r31;
}

s32 TLobby__sub_80409AA8(void) {
    TLobby__sub_803F8A9C((void *)((void *) (&lobby_handler_table_desc)));
    lobby_handler_table_desc = 0;
    return 0;
}

struct Rec_8040B33C { u32 f0; u8 addr[0x10]; };
struct A_8040B33C { u8 pad[0x10]; s16 idx; u8 pad2[2]; s16 off; };
struct A_8040A45C { s16 f0; s16 f2; s32 f4; };
struct D_8040A45C;
struct C_8040A45C { s16 f0; u8 pad2[2]; Rec_8040B33C f4; u8 pad18[4]; s32 f1C; C_8040A45C *f20; D_8040A45C *f24; };
struct D_8040A45C { s16 f0; u8 pad2[0x102]; s8 f104; u8 pad105[0xFF]; s16 f204; u8 pad206[2]; C_8040A45C *f208; };
struct E_8040A45C { s16 f0; u8 pad2[0x16]; s32 f18; u8 f1C; u8 pad1D[0xFF]; };
struct Query_8040C09C;
struct Buf_8040AFE0 {
    u8 pad0[2];
    s16 len;
    u8 *data;
};
struct F_8040A45C {
    s16 f0;
    s16 f2;
    s16 f4;
    s16 f6;
    s16 f8;
    s16 fA;
    s32 fC;
    s16 f10;
    s16 f12;
    s16 f14;
    u8 pad16[2];
    Buf_8040AFE0 *f18;
    A_8040A45C *f1C;
    u32 f20;
    u8 pad24[4];
    s32 f28;
    E_8040A45C *f2C;
    u8 pad30[4];
    s32 f34;
    Query_8040C09C *f38;
};

struct G_8040A45C {
    s16 h0;
    u8 pad2[0xA];
    s16 *fC;
    s16 nb;
    u8 pad12[2];
    Rec_8040B33C *b;
    s16 f18;
    s16 lim;
    s16 step;
    u8 pad1E[2];
    s32 base;
    s16 na;
    u8 pad26[2];
    A_8040A45C *a;
    s16 nc;
    s16 nd;
    s16 ne;
    u8 pad32[2];
    C_8040A45C *c;
    D_8040A45C *d;
    E_8040A45C *e;
    s16 nf;
    u8 pad42[2];
    F_8040A45C *f;
};

extern G_8040A45C dns_resolver_state;

#define TBL_80409B48 (*(Tbl_80409B48 *)&lobby_handler_table_desc)

#define T_ (*(Tbl_80409AD8 *)&lobby_handler_table_desc)
s32 TLobby__sub_80409AD8(void) {
    s16 i;
    u8 *p;
    TLobby__sub_803F8AA0((u8 *)&T_);
    p = T_.list;
    i = 0;
    while (i < T_.count) {
        NetMemset(p, 0, 0x30);
        i++;
        p += 0x30;
    }
    return 0;
}

s32 TLobby::call_handler_by_index(s16 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    s32 (*fn)(s32, s32, s32, s32);
    if (arg0 < 0 || arg0 > TBL_80409B48.count) {
        return -0x10F;
    }
    Ent_80409B48 *e = TBL_80409B48.ents;
    e += arg0;
    if (e->active == 0) {
        return -2;
    }
    fn = e->fn;
    if (fn == NULL) {
        return -2;
    }
    return fn(arg1, arg2, arg3, arg4);
}

#define TBL_80409BD4 (*(Tbl_80409BD4 *)&lobby_handler_table_desc)
s32 TLobby::dispatch_handler_by_index(s16 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 (*fn)(s32, s32, s32);
    if (arg0 < 0 || arg0 > TBL_80409BD4.count) {
        return -0x10F;
    }
    Ent_80409BD4 *e = TBL_80409BD4.ents;
    e += arg0;
    if (e->active == 0) {
        return -2;
    }
    fn = e->fn;
    if (fn == NULL) {
        return -2;
    }
    return fn(arg1, arg2, arg3);
}

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

s32 TLobby::dispatch_handler_by_id(s16 arg0, s32 arg1, s32 arg2) {
    s32 (*fn)(s32, s32);

    if (arg0 < 0 || arg0 > TBL_80409C5C.count) {
        return -0x10F;
    }
    Ent_80409C5C *e = TBL_80409C5C.ents;
    e += arg0;
    if (e->active == 0) {
        return -2;
    }
    fn = e->fn;
    if (fn == NULL) {
        return -2;
    }
    return fn(arg1, arg2);
}

typedef struct Ent_80409CE0 {
    s16 active;
    s16 flags;
    u8 pad[0x1C];
    s16 (*fn)(s32, s32, s32);
    u8 pad2[0xC];
} Ent_80409CE0;

typedef struct Tbl_80409CE0 {
    s16 count;
    Ent_80409CE0 *ents;
} Tbl_80409CE0;

#define TBL_80409CE0 (*(Tbl_80409CE0 *)&lobby_handler_table_desc)

s16 TLobby__sub_80409CE0(s16 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s16 (*fn)(s32, s32, s32);

    if (arg0 < 0 || arg0 > TBL_80409CE0.count) {
        return -0x10F;
    }
    Ent_80409CE0 *e = TBL_80409CE0.ents;
    e += arg0;
    if (e->active == 0) {
        return -2;
    }
    if (!(e->flags & 4)) {
        return 0;
    }
    fn = e->fn;
    if (fn == NULL) {
        return -2;
    }
    return fn(arg1, arg2, arg3);
}

typedef struct Ent_80409D7C {
    s16 active;
    s16 flags;
    u8 pad[0x18];
    s16 (*fn)(s32, s32, s32);
    u8 pad2[0x10];
} Ent_80409D7C;

typedef struct Tbl_80409D7C {
    s16 count;
    Ent_80409D7C *ents;
} Tbl_80409D7C;

#define TBL_80409D7C (*(Tbl_80409D7C *)&lobby_handler_table_desc)

s16 TLobby__sub_80409D7C(s16 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s16 (*fn)(s32, s32, s32);

    if (arg0 < 0 || arg0 > TBL_80409D7C.count) {
        return -0x10F;
    }
    Ent_80409D7C *e = TBL_80409D7C.ents;
    e += arg0;
    if (e->active == 0) {
        return -2;
    }
    if (!(e->flags & 4)) {
        return 0;
    }
    fn = e->fn;
    if (fn == NULL) {
        return -2;
    }
    return fn(arg1, arg2, arg3);
}

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

s32 TLobby__sub_80409E18(s16 arg0, s32 arg1, s32 arg2) {
    s32 (*fn)(s32, s32);

    if (arg0 < 0 || arg0 > TBL_80409E18.count) {
        return -0x10F;
    }
    Ent_80409E18 *e = TBL_80409E18.ents;
    e += arg0;
    if (e->active == 0) {
        return -2;
    }
    if (!(e->flags & 4)) {
        return 0;
    }
    fn = e->fn;
    if (fn == NULL) {
        return -2;
    }
    return fn(arg1, arg2);
}

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

s32 TLobby__sub_80409EB0(s16 arg0, s32 arg1) {
    s32 (*fn)(s32);

    if (arg0 < 0 || arg0 > TBL_80409EB0.count) {
        return -0x10F;
    }
    Ent_80409EB0 *e = TBL_80409EB0.ents;
    e += arg0;
    if (e->active == 0) {
        return -2;
    }
    if (!(e->flags & 4)) {
        return 0;
    }
    fn = e->fn;
    if (fn == NULL) {
        return -2;
    }
    return fn(arg1);
}

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

void TLobby__sub_803F86BC(void *);
s32 TLobby__sub_80421844(s32 arg0);

typedef struct Ent_80409FC4 { s16 st; s16 pad2; s32 (*f4)(s32); s32 (*f8)(s32); s32 (*fC)(s16); s32 (*f10)(s32); u8 pad14[0x30-0x14]; } Ent_80409FC4;
typedef struct Tbl_80409FC4 { s16 count; Ent_80409FC4 *list; } Tbl_80409FC4;
typedef struct Ent_8040A630 { s16 f0; u8 pad[0x3A]; } Ent_8040A630;
typedef struct G_8040A630 { u8 pad[0x40]; s16 n; u8 pad2[2]; Ent_8040A630 *p; } G_8040A630;

#pragma push
#pragma opt_propagation off
s16 TLobby::invoke_socket_callback(s16 i, s32 arg) {
    Ent_80409F44 *e;
    if (i < 0 || i > (*(Tbl_80409F44 *)&lobby_handler_table_desc).count) {
        return -0x10F;
    }
    e = (*(Tbl_80409F44 *)&lobby_handler_table_desc).list + i;
    if (e->st == 0) {
        return -2;
    }
    if (e->f10 == 0) {
        return -2;
    }
    return e->f10(arg);
}
#pragma pop

#pragma push
#pragma opt_propagation off
s32 TLobby::call_entry_callback(s16 i, s16 arg) {
    Ent_80409FC4 *e;
    if (i < 0 || i > (*(Tbl_80409FC4 *)&lobby_handler_table_desc).count) {
        return -0x10F;
    }
    e = (*(Tbl_80409FC4 *)&lobby_handler_table_desc).list + i;
    if (e->st == 0) {
        return -2;
    }
    if (e->fC == 0) {
        return -2;
    }
    return e->fC(arg);
}
#pragma pop

typedef struct Ent_8040A044 {
    s16 st;
    s16 f2;
    s16 (*f4)(s16, u8 *);
    s16 (*f8)(s16, s32, s16, u8 *);
    u8 padC[0x30 - 0xC];
} Ent_8040A044;
typedef struct Tbl_8040A044 { s16 count; Ent_8040A044 *list; } Tbl_8040A044;

#pragma push
#pragma opt_propagation off
s16 TLobby__sub_8040A044(s16 i, s32 type, s16 len, u8 *addr) {
    Ent_8040A044 *e;
    s16 (*fn)(s16, s32, s16, u8 *);
    if (i < 0 || i > (*(Tbl_8040A044 *)&lobby_handler_table_desc).count) {
        return -0x10F;
    }
    e = (*(Tbl_8040A044 *)&lobby_handler_table_desc).list + i;
    if (e->st == 0) {
        return -2;
    }
    fn = e->f8;
    if (fn == NULL) {
        return -2;
    }
    return fn(i, type, len, addr);
}

s16 TLobby__sub_8040A0C0(s16 i, u8 *buf) {
    Ent_8040A044 *e;
    s16 (*fn)(s16, u8 *);
    if (i < 0 || i > (*(Tbl_8040A044 *)&lobby_handler_table_desc).count) {
        return -0x10F;
    }
    e = (*(Tbl_8040A044 *)&lobby_handler_table_desc).list + i;
    if (e->st == 0) {
        return -2;
    }
    fn = e->f4;
    if (fn == NULL) {
        return -2;
    }
    return fn(i, buf);
}
#pragma pop

#pragma push
#pragma optimization_level 2
s16 TLobby::is_slot_flag_0x40_set(s16 i) {
    if (i < 0 || i > (*(G_8040A13C *)&lobby_handler_table_desc).n) { return 0; }
    Ent_8040A13C *e = (*(G_8040A13C *)&lobby_handler_table_desc).p;
    if (e[i].f0 == 0) { return 0; }
    if (e[i].f2 & 0x40) { return 1; }
    return 0;
}
#pragma pop

#pragma push
#pragma optimization_level 2
s32 TLobby::is_slot_flag_0x20_set(s16 i) {
    Ent_8040A19C *e;
    if (i < 0 || i > (*(G_8040A19C *)&lobby_handler_table_desc).n) { return 0; }
    e = (*(G_8040A19C *)&lobby_handler_table_desc).p;
    if (*(s16 *)((u8 *)e + i * 0x30) == 0) { return 0; }
    e = (Ent_8040A19C *)((u8 *)e + i * 0x30);
    if (e->f2 & 0x20) { return 1; }
    return 0;
}
#pragma pop

struct Ent_8040A1FC { s16 f0; s16 f2; u8 pad[0x2C]; };
struct G_8040A1FC { s16 n; Ent_8040A1FC *p; };
#pragma push
#pragma optimization_level 2
#pragma dont_inline on
s16 TLobby::is_entry_flag10_set(s16 i) {
    if (i < 0 || i > (*(G_8040A1FC *)&lobby_handler_table_desc).n) { return 0; }
    Ent_8040A1FC *e = (*(G_8040A1FC *)&lobby_handler_table_desc).p;
    if (e[i].f0 == 0) { return 0; }
    if (e[i].f2 & 0x10) { return 1; }
    return 0;
}
#pragma pop

struct Ent_8040A25C { s16 f0; s16 f2; u8 pad[0x2C]; };
struct G_8040A25C { s16 n; Ent_8040A25C *p; };
#pragma push
#pragma optimization_level 2
#pragma dont_inline on
s16 TLobby::is_socket_flag_set(s16 i) {
    if (i < 0 || i > (*(G_8040A25C *)&lobby_handler_table_desc).n) { return 0; }
    Ent_8040A25C *e = (*(G_8040A25C *)&lobby_handler_table_desc).p;
    if (e[i].f0 == 0) { return 0; }
    if (e[i].f2 & 1) { return 1; }
    return 0;
}
#pragma pop

s16 TLobby__sub_8040A2BC(Fn_8040881C *fns, s16 kind) {
    Ent_8040A044 *e;
    s16 i;

    if (fns == NULL || fns[1] == NULL) {
        return -2;
    }
    switch (kind) {
    case 1:
        e = (*(Tbl_8040A044 *)&lobby_handler_table_desc).list;
        if (e->st == 0) {
            NetMemcpy(&e->f4, fns, 0x2C);
            e->f2 = kind;
            e->st = 1;
            return 0;
        }
        return -2;
    default:
        for (i = 1, e = (*(Tbl_8040A044 *)&lobby_handler_table_desc).list + 1; i < (*(Tbl_8040A044 *)&lobby_handler_table_desc).count; i++, e++) {
            if (e->st == 0) {
                NetMemcpy(&e->f4, fns, 0x2C);
                e->f2 = kind;
                e->st = 1;
                return i;
            }
        }
        return -0x10F;
    }
}

s32 TLobby__sub_8040A3C0(void) {
    s32 ret;
    s16 i;
    Mgr_8040A3C0 *m = (Mgr_8040A3C0 *)&dns_resolver_state;
    Ent_8040A3C0 *e;

    ret = TLobby__sub_80421844((s32)((void *)TLobby::tick_connection_timeouts));
    e = m->ents;
    i = 0;
    while (i < m->count) {
        if (e->active != 0) {
            ((TLobby *)e)->close_and_reset_connection();
        }
        i++;
        e++;
    }
    TLobby__sub_803F86BC(m);
    return ret;
}

void TLobby__sub_804218AC(void (*)(void), int);

void TLobby::init_net_tables() {
    G_8040A45C *g = &dns_resolver_state;
    s16 i;

    NetMemset(&g->h0, 0, sizeof(G_8040A45C));
    ((TLobby *)(&g->h0))->init_net_config();
    {
        A_8040A45C *p = g->a;
        i = 0;
        while (i < g->na) {
            p->f0 = 0;
            p->f4 = g->base + g->step * i;
            i++;
            p++;
        }
    }
    {
        Rec_8040B33C *p = g->b;
        i = 0;
        while (i < g->nb) {
            p->f0 = 0;
            i++;
            p++;
        }
    }
    {
        C_8040A45C *p = g->c;
        i = 0;
        while (i < g->nc) {
            p->f0 = 0;
            i++;
            p->f20 = 0;
            p++;
        }
    }
    {
        D_8040A45C *p = g->d;
        i = 0;
        while (i < g->nd) {
            p->f0 = 0;
            i++;
            p->f104 = 0;
            p->f204 = 0;
            p->f208 = 0;
            p++;
        }
    }
    {
        E_8040A45C *p = g->e;
        i = 0;
        while (i < g->ne) {
            p->f0 = 0;
            i++;
            p->f18 = 0;
            p->f1C = 0;
            p++;
        }
    }
    {
        F_8040A45C *p = g->f;
        i = 0;
        while (i < g->nf) {
            p->f2 = i;
            i++;
            p->f0 = 0;
            p->f4 = -1;
            p->f6 = 0;
            p->fC = -1;
            p->f10 = -65;
            p->f12 = 0;
            p->f18 = 0;
            p->f1C = 0;
            p->f34 = 0;
            p->f28 = 0;
            p++;
        }
    }
    TLobby__sub_804218AC(TLobby::tick_connection_timeouts, 1000);
}

#pragma push
#pragma opt_propagation off
s32 TLobby::close_connection_by_index(s16 i) {
    G_8040A630 *g = (G_8040A630 *)&dns_resolver_state;
    if (i < 0 || i > g->n) { return -2; }
    Ent_8040A630 *e = (Ent_8040A630 *)((u8 *)g->p + i * 0x3C);
    if (e->f0 == 0) { return -2; }
    return ((TLobby *)e)->close_and_reset_connection();
}
#pragma pop

struct Req_8040A698 {
    u8 pad0[4];
    void *f4;
    s16 f8;
    u8 padA[2];
    void *fC;
    s16 f10;
    u8 pad12[2];
    u32 f14;
};

struct Ent_8040A698 {
    s16 f0;
    u8 pad2[6];
    s16 f8;
    u8 padA[2];
    u32 fC;
    s16 f10;
    s16 f12;
    u8 pad14[0xC];
    Req_8040A698 req;
};

struct SubA_8040C540;
void TLobby__sub_8040C74C(SubA_8040C540 *);

#pragma push
#pragma opt_propagation off
s16 TLobby__sub_8040A698(s16 idx, void *buf, s16 *len, void *buf2, s16 *len2, u32 mode) {
    G_8040A45C *g = &dns_resolver_state;
    F_8040A45C *f;
    Ent_8040A698 *e;
    Req_8040A698 *req;
    s16 st;

    if (idx < 0 || idx >= g->nf) {
        return -2;
    }
    f = &g->f[idx];
    e = (Ent_8040A698 *)f;
    if (f->f0 == 0) {
        return -2;
    }
    if (e->f8 != 1) {
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
    req = &e->req;
    req->f4 = buf;
    req->f8 = *len;
    req->fC = buf2;
    if (len2 != NULL) {
        req->f10 = *len2;
    } else {
        req->f10 = 0;
    }
    req->f14 = mode;
    if (mode == 0) {
        TLobby__sub_80421814();
        if (e->f10 > 0 || e->f12 > 0) {
            if (e->fC != 0xFFFFFFFF) {
                TLobby__sub_804217E4();
                return -2;
            }
            NetStoreCurrentThread((s32 *)&e->fC);
            TLobby__sub_804217E4();
            NetSuspendCurrentThread();
        } else {
            TLobby__sub_804217E4();
        }
        st = e->f10;
        if (st < 0) {
            return st;
        }
    } else if (mode == 0xFFFFFFFF) {
        st = e->f10;
        if (st > 0 || e->f12 > 0) {
            return -1;
        }
        if (st < 0) {
            return st;
        }
    } else {
        if (e->f10 <= 0 && e->f12 <= 0) {
            ((TLobby *)e)->dispatch_request_callback(1);
        }
        return -1;
    }
    TLobby__sub_8040C74C((SubA_8040C540 *)req);
    if (len2 != NULL) {
        *len2 = req->f10;
    }
    *len = req->f8;
    return 0;
}
#pragma pop

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

s32 TLobby::clear_all_used_records() {
    Mgr_8040AD64 *g = (Mgr_8040AD64 *)&dns_resolver_state;
    s32 cnt;
    s16 i;
    Rec_8040AD64 *r;

    TLobby__sub_80421814();
    g->f18 = 0;
    cnt = 0;
    i = 0;
    r = g->recs;
    while (i < g->n) {
        if (r->used != 0) {
            r->used = 0;
            cnt++;
        }
        i++;
        r++;
    }
    TLobby__sub_804217E4();
    return cnt;
}

#pragma push
#pragma dont_inline off
inline s32 compare_family_addr(u32 family, Rec_8040B33C *a, Rec_8040B33C *b) {
    switch (family) {
    case 4:
        if (b->f0 != 4) {
            return -1;
        }
        return NetMemcmp(a->addr, b->addr, 4);
    case 6:
        if (b->f0 != 6) {
            return -1;
        }
        return NetMemcmp(a->addr, b->addr, 0x10);
    default:
    case 0:
        return -1;
    }
}

s16 TLobby__sub_8040ADE8(Rec_8040B33C *addr) {
    G_8040A45C *g;
    s16 ret;
    s16 i;
    Rec_8040B33C *p;
    Rec_8040B33C *slot;
    u32 family;

    switch (addr->f0) {
    case 4:
    case 6:
        break;
    default:
    case 0:
        return -2;
    }
    TLobby__sub_80421814();
    g = &dns_resolver_state;
    p = g->b;
    slot = NULL;
    for (i = 0; i < g->nb; i++, p++) {
        if (p->f0 == 0) {
            if (slot == NULL) {
                ret = i;
                slot = p;
            }
            continue;
        }
        family = addr->f0;
        if (family != p->f0) {
            continue;
        }
        if (compare_family_addr(family, addr, p) == 0) {
            ret = -2;
            slot = NULL;
            break;
        }
    }
    if (slot != NULL) {
        NetMemcpy(slot, addr, sizeof(Rec_8040B33C));
    } else {
        ret = -2;
    }
    TLobby__sub_804217E4();
    return ret;
}
#pragma pop

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

void TLobby__sub_8040AFE0(void);
void TLobby__sub_8040B3B4(void);
void reset_connection_requests__6TLobbyFPvs(Conn_8040AF48 *, s16);

void TLobby::tick_connection_timeouts() {
    Mgr_8040AF48 *g;
    Conn_8040AF48 *c;
    s16 i;

    TLobby__sub_8040B3B4();
    g = (Mgr_8040AF48 *)&dns_resolver_state;
    c = g->conns;
    i = 0;
    while (i < g->nconns) {
        if (c->state == 1 && c->timer > 0) {
            if (--c->timer <= 0) {
                reset_connection_requests__6TLobbyFPvs(c, 0);
            }
        }
        i++;
        c++;
    }
    TLobby__sub_8040AFE0();
}

struct UdpBuf_8040AFE0 {
    s16 len;
    u8 pad2[2];
    u8 *data;
};

Rec_8040B33C *find_next_active_record__6TLobbyFPv(A_8040B33C *a);
void TLobby__sub_8040BE40(F_8040A45C *req, s16 err, s16 arg);
void TLobby__sub_8040B1C4(F_8040A45C *req);
s16 TUdpSocket__sub_80421BAC(s32 h, u32 *src, u32 *dst, u16 port, u32 *opt, s8 n, UdpBuf_8040AFE0 *bufs);

#pragma push
#pragma dont_inline off
inline void put_tag_8040AFE0(F_8040A45C *req, s16 tag) {
    NetMemcpy(req->f18->data + req->f18->len - 4, &tag, 2);
}

inline s16 send_8040AFE0(F_8040A45C *req, Rec_8040B33C *rec) {
    UdpBuf_8040AFE0 buf;
    s16 r;
    u32 *dst = (u32 *)rec;

    buf.len = req->f18->len;
    buf.data = req->f18->data;
    r = TUdpSocket__sub_80421BAC(req->f4, NULL, dst, 0, NULL, 1, &buf);
    put_tag_8040AFE0(req, 0x1C);
    return r;
}

void TLobby__sub_8040AFE0(void) {
    G_8040A45C *g;
    Rec_8040B33C *rec;
    s16 *nb;
    s16 i;
    F_8040A45C *req;
    s16 r;
    s16 *fc;

    g = &dns_resolver_state;
    nb = &g->nb;
    i = 0;
    req = g->f;
    while (i < g->nf) {
        if (req->f0 == 1 && req->f4 >= 0 && (req->f10 > 0 || req->f12 > 0)) {
            if (--req->fA <= 0) {
                if (req->f10 >= g->lim) {
                    g->f18 = 0;
                    TLobby__sub_8040BE40(req, -0x45, 0);
                } else if (req->f12 != 0) {
                    rec = find_next_active_record__6TLobbyFPv((A_8040B33C *)req);
                    if (rec == NULL) {
                        TLobby__sub_8040BE40(req, -0x44, 0);
                    } else {
                        g->f18 = req->f10 % *nb;
                        fc = g->fC;
                        req->fA = fc[req->f10 / *nb];
                        put_tag_8040AFE0(req, 1);
                        r = send_8040AFE0(req, rec);
                        if (r < 0) {
                            req->fA = 1;
                        }
                        req->f12 = 0;
                        req->f10++;
                    }
                } else {
                    TLobby__sub_8040B1C4(req);
                }
            }
        }
        i++;
        req++;
    }
}
#pragma pop


// Same scan as find_next_active_record (0x8040B33C), inlined here.
inline Rec_8040B33C *next_active_record_8040B1C4(F_8040A45C *req) {
    G_8040A45C *g = &dns_resolver_state;
    s16 t, n, i;
    for (i = 0; i < (n = g->nb); i++) {
        Rec_8040B33C *r = &g->b[(req->f14 + (t = req->f10)) % n];
        if (r->f0 != 0) {
            if (t < g->lim) {
                return r;
            }
            break;
        }
        req->f10 = t + 1;
    }
    return 0;
}

inline s16 send_query_8040B1C4(F_8040A45C *req, Rec_8040B33C *rec) {
    UdpBuf_8040AFE0 buf;

    buf.len = req->f18->len;
    buf.data = req->f18->data;
    return TUdpSocket__sub_80421BAC(req->f4, NULL, (u32 *)rec, 0, NULL, 1, &buf);
}

void TLobby__sub_8040B1C4(F_8040A45C *req) {
    G_8040A45C *g = &dns_resolver_state;
    Rec_8040B33C *rec;
    s16 r;
    s16 *nb;

    if ((rec = next_active_record_8040B1C4(req)) == NULL) {
        TLobby__sub_8040BE40(req, -0x44, 0);
        return;
    }
    nb = &g->nb;
    g->f18 = req->f10 % *nb;
    req->fA = g->fC[req->f10 / *nb];
    r = send_query_8040B1C4(req, rec);
    if (r < 0) {
        req->fA = 1;
        req->f10++;
    } else if (req->f8 == 1 && req->f20 == 0) {
        req->fA = 2;
        req->f12 = 1;
    } else {
        req->f10++;
    }
}

Rec_8040B33C *find_next_active_record__6TLobbyFPv(A_8040B33C *a) {
    G_8040A45C *g = &dns_resolver_state;
    s16 n, t, i;
    for (i = 0; i < (n = g->nb); i++) {
        Rec_8040B33C *r = &g->b[(a->off + (t = a->idx)) % n];
        if (r->f0 != 0) {
            if (t < g->lim) {
                return r;
            }
            break;
        }
        a->idx = t + 1;
    }
    return 0;
}

void TLobby__sub_8040C178(Query_8040C09C *q, s16 arg1);

void TLobby__sub_8040B3B4(void) {
    s16 n;
    s16 j;
    C_8040A45C *prev;
    G_8040A45C *g;
    C_8040A45C *dead;
    s16 i;
    C_8040A45C *c;
    D_8040A45C *q;

    g = &dns_resolver_state;
    for (i = 0, q = g->d; i < g->nd; i++, q++) {
        if (q->f0 != 1) {
            continue;
        }
        if ((n = q->f204) == 0) {
            continue;
        }
        c = q->f208;
        prev = NULL;
        for (j = 0; j < n && c != NULL; j++) {
            if (--c->f1C > 0) {
                prev = c;
                c = c->f20;
            } else {
                dead = c;
                c = c->f20;
                if (prev != NULL) {
                    prev->f20 = c;
                } else {
                    q->f208 = c;
                }
                q->f204--;
                dead->f0 = 0;
                dead->f20 = NULL;
            }
        }
        if (q->f204 <= 0) {
            TLobby__sub_8040C178((Query_8040C09C *)q, 0);
        }
    }
}

typedef struct Ent_8040B654 {
    s16 state;
    u8 pad2[2];
    s16 id;
    u8 pad6[4];
    s16 fA;
    u8 padC[4];
    s16 f10;
    s16 f12;
    u8 pad14[8];
    A_8040A45C *f1C;
    u8 pad20[0x1C];
} Ent_8040B654;

typedef struct Mgr_8040B654 {
    u8 pad[0x40];
    s16 count;
    u8 pad42[2];
    Ent_8040B654 *ents;
} Mgr_8040B654;

struct Conn_8040C540;

#pragma push
#pragma dont_inline off
#pragma inline_depth(1)
inline Ent_8040B654 *find_8040B654(s16 id) {
    Mgr_8040B654 *g = (Mgr_8040B654 *)&dns_resolver_state;
    s16 n;
    Ent_8040B654 *e;
    s16 i;

    e = g->ents;
    n = g->count;
    for (i = 0; i < n; i++, e++) {
        if (e->state == 1 && id == e->id) {
            return e;
        }
    }
    return NULL;
}

s16 TLobby__sub_8040B8BC(F_8040A45C *req);

struct UdpRx_8040B4BC { s16 sock; s16 len; s32 buf; u8 pad8[0x28]; u16 port; };

inline A_8040A45C *alloc_rx_8040B4BC(G_8040A45C *g) {
    s16 i;
    A_8040A45C *a = g->a;
    for (i = 0; i < g->na; i++, a++) {
        if (a->f0 == 0) {
            a->f0 = 1;
            return a;
        }
    }
    return NULL;
}

inline Ent_8040B654 *find_req_8040B4BC(s16 id) {
    Mgr_8040B654 *g = (Mgr_8040B654 *)&dns_resolver_state;
    Ent_8040B654 *e = g->ents;
    s16 i;

    for (i = 0; i < g->count; i++, e++) {
        if (e->state == 1 && id == e->id) {
            return e;
        }
    }
    return NULL;
}

s32 TLobby__sub_8040B4BC(s16 phase, UdpRx_8040B4BC *rx) {
    G_8040A45C *g = &dns_resolver_state;
    Ent_8040B654 *e;
    s16 len;
    A_8040A45C *b;

    if (rx->port != 53) {
        return 1;
    }
    e = find_req_8040B4BC(rx->sock);
    if (e == NULL) {
        return 1;
    }
    if (e->f10 < 0) {
        return 1;
    }
    len = rx->len;
    if (len > g->step) {
        return 1;
    }
    switch (phase) {
    case 0:
        b = alloc_rx_8040B4BC(g);
        e->f1C = b;
        if (b == NULL) {
            return 1;
        }
        rx->buf = e->f1C->f4;
        return 0;
    default:
        e->f1C->f2 = len;
        if (TLobby__sub_8040B8BC((F_8040A45C *)e) < 0) {
            e->f1C->f0 = 0;
            e->f1C = NULL;
            return 1;
        }
        e->f1C->f0 = 0;
        e->f1C = NULL;
        if (e->f12 == 0) {
            e->f10 = 0;
            ((TLobby *)e)->dispatch_request_callback(0);
        }
        return 0;
    }
}

void TLobby::complete_pending_request(s16 id) {
    Ent_8040B654 *e;

    if ((e = find_8040B654(id)) != NULL) {
        e->fA = 1;
        if (e->f10 < 0) {
            ((TLobby *)e)->dispatch_request_callback(0);
        }
    }
}
#pragma pop

#pragma push
#pragma opt_propagation off
s32 TLobby::build_dns_query_aaaa(u8 *name, s16 len) {
    Q_8040B6E4 *q = (Q_8040B6E4 *)this;
    Hdr_8040B6E4 *h;
    u8 *body;
    s16 n;
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
    body += n;
    qt.cls = 1;
    total = n + 0xC;
    NetMemcpy(body, &qt, 4);
    q->pkt->len = total + 4;
    return 0;
}
#pragma pop

#pragma push
#pragma opt_propagation off
s32 TLobby::build_dns_query_a(u8 *name, s16 len) {
    Q_8040B790 *q = (Q_8040B790 *)this;
    Hdr_8040B790 *h;
    u8 *body;
    s16 n;
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
    body += n;
    qt.cls = 1;
    total = n + 0xC;
    NetMemcpy(body, &qt, 4);
    q->pkt->len = total + 4;
    return 0;
}
#pragma pop

void TLobby__sub_8040BE40(F_8040A45C *req, s16 err, s16 arg);


#pragma push
#pragma dont_inline off
inline void reset_requests_8040BE40(E_8040A45C *o, s16 arg) {
    G_8040A45C *g = &dns_resolver_state;
    s16 i;
    F_8040A45C *e;

    o->f0 = 0;
    o->f18 = 0;
    o->f1C = 0;
    i = 0;
    e = g->f;
    while (i < g->nf) {
        if (e->f2C == o) {
            e->f10 = -0x42;
            e->f12 = 0;
            e->f2C = NULL;
            ((TLobby *)e)->dispatch_request_callback(arg);
        }
        i++;
        e++;
    }
}

void TLobby__sub_8040BE40(F_8040A45C *req, s16 err, s16 arg) {
    E_8040A45C *c;
    Query_8040C09C *q;

    switch (req->f8) {
    case 1:
        q = req->f38;
        if (q != NULL) {
            req->f38 = NULL;
            TLobby__sub_8040C178(q, arg);
        }
        break;
    case 12:
        c = req->f2C;
        if (c != NULL) {
            req->f2C = NULL;
            reset_requests_8040BE40(c, arg);
        }
        break;
    }
    req->f10 = err;
    req->f12 = 0;
    ((TLobby *)req)->dispatch_request_callback(arg);
}
#pragma pop

struct N_8040C4B0 { u8 pad0[0x20]; N_8040C4B0 *next; };
struct O_8040C4B0 { u8 pad0[0x204]; s16 count; u8 pad206[2]; N_8040C4B0 *head; };
struct G_8040C4B0 { u8 pad0[0x2C]; s16 lim; };

#pragma dont_inline off
#pragma inline_depth(4)
inline s32 close_8040BF38(u8 *p, s32 id) {
    s32 r;
    if ((s16)id < 0) {
        return 0;
    }
    r = TLobby__sub_80421B3C(id);
    *(s16 *)((s8 *)p + 4) = -1;
    return r;
}
s32 TLobby::close_and_reset_connection() {
    u8 *arg0 = (u8 *)this;
    s16 *temp_r3_2;
    s16 *temp_r3_3;
    s32 temp_r3;
    s32 var_r31;
    var_r31 = close_8040BF38(arg0, *(s16 *)&this->m_flags);
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
    *(s16 *)&this->m_name = 0;
    *(s16 *)&this->m_prev = 0;
    *(s16 *)&this->m_up = -0x41;
    *(s16 *)((s8 *)arg0 + 0x12) = 0;
    if (*(u32 *)&this->m_next != 0xFFFFFFFFU) {
        TLobby::resume_thread((s32)this->m_next);
        *(s32 *)&this->m_next = -1;
    }
    TLobby__sub_804217E4();
    return var_r31;
}

struct O_8040C00C { s16 f0; u8 pad2[0x16]; s32 f18; u8 f1C; };
struct E_8040C00C { u8 pad0[0x10]; s16 f10; s16 f12; u8 pad14[0x18]; O_8040C00C *owner; u8 pad30[0xC]; };
struct G_8040C00C { u8 pad0[0x40]; s16 count; u8 pad42[2]; E_8040C00C *ents; };
struct Conn_8040C540;

#define g ((G_8040C00C *)&dns_resolver_state)
#define o ((O_8040C00C *)o_)
void reset_connection_requests__6TLobbyFPvs(Conn_8040AF48 *o_, s16 arg1) {
    s16 i;
    E_8040C00C *e;

    o->f0 = 0;
    o->f18 = 0;
    o->f1C = 0;
    i = 0;
    e = g->ents;
    while (i < g->count) {
        if (e->owner == o) {
            e->f10 = -0x42;
            e->f12 = 0;
            e->owner = 0;
            ((TLobby *)e)->dispatch_request_callback(arg1);
        }
        i++;
        e++;
    }
}
#undef g
#undef o

struct Node_8040C09C { s16 f0; u8 pad2[0x1A]; s32 f1C; Node_8040C09C *next; };
struct Query_8040C09C { s16 f0; u8 pad2[0x102]; u8 f104; u8 pad105[0xFF]; s16 f204; u8 pad206[2]; Node_8040C09C *f208; };
struct Ent_8040C09C { u8 pad0[0x10]; s16 f10; s16 f12; u8 pad14[0x24]; Query_8040C09C *owner; };
struct G_8040C09C {
    u8 pad0[0x2C];
    s16 nnodes;
    s16 nqueries;
    u8 pad30[8];
    Query_8040C09C *queries;
    u8 pad3C[4];
    s16 nents;
    u8 pad42[2];
    Ent_8040C09C *ents;
};

void TLobby__sub_8040C178(Query_8040C09C *q, s16 arg1);

#define g ((G_8040C09C *)&dns_resolver_state)
Query_8040C09C *TLobby__sub_8040C09C(void) {
    s16 i = 0;
    Query_8040C09C *best = NULL;
    Query_8040C09C *q = g->queries;

    for (; i < g->nqueries; i++, q++) {
        if (q->f0 == 0) {
            q->f0 = 1;
            return q;
        }
        if (best == NULL) {
            best = q;
        } else if (best->f204 != 0 && q->f204 != 0) {
            s32 q_time = q->f208->f1C;
            s32 best_time = best->f208->f1C;
            if (q_time < best_time) {
                best = q;
            }
        } else if (q->f204 != 0) {
            best = q;
        }
    }
    TLobby__sub_8040C178(best, 1);
    best->f0 = 1;
    return best;
}

void TLobby__sub_8040C178(Query_8040C09C *q, s16 arg1) {
    G_8040C09C *state = (G_8040C09C *)&dns_resolver_state;
    s16 i;
    Ent_8040C09C *e;
    Node_8040C09C *n;
    Node_8040C09C *cur;

    q->f0 = 0;
    q->f104 = 0;
    q->f204 = 0;
    n = q->f208;
    i = 0;
    while (n != NULL && i < state->nnodes) {
        cur = n;
        n = n->next;
        i++;
        cur->f0 = 0;
        cur->next = NULL;
    }
    q->f208 = NULL;
    i = 0;
    e = state->ents;
    while (i < state->nents) {
        if (e->owner == q) {
            e->f10 = -0x42;
            e->f12 = 0;
            e->owner = NULL;
            ((TLobby *)e)->dispatch_request_callback(arg1);
        }
        i++;
        e++;
    }
}
#undef g

s16 TLobby__sub_8040C340(D_8040A45C *q, C_8040A45C *node);

C_8040A45C *TLobby__sub_8040C248(D_8040A45C *q) {
    G_8040A45C *g;
    C_8040A45C *best;
    s16 i;
    C_8040A45C *c;

    if (q == NULL) {
        return NULL;
    }
    g = &dns_resolver_state;
    c = g->c;
    best = NULL;
    for (i = 0; i < g->nc; i++, c++) {
        if (c->f0 == 0) {
            c->f0 = 1;
            c->f20 = NULL;
            return c;
        }
        if (c->f24 == q) {
            continue;
        }
        if (best == NULL) {
            best = c;
        } else if (c->f1C < best->f1C) {
            best = c;
        }
    }
    if (best == NULL) {
        return NULL;
    }
    if (TLobby__sub_8040C340(best->f24, best) < 0) {
        return NULL;
    }
    best->f0 = 1;
    best->f20 = NULL;
    return best;
}

s32 append_to_list__6TLobbyFPvPv(O_8040C4B0 *o, N_8040C4B0 *n) {
    s16 i;
    N_8040C4B0 *p;

    if (o == NULL || n == NULL) {
        return -1;
    }
    if (o->head == NULL) {
        o->count = 1;
        o->head = n;
        return 0;
    }
    for (p = o->head, i = 0; i < ((G_8040C4B0 *)&dns_resolver_state)->lim; i++) {
        if (p->next == NULL) {
            o->count++;
            p->next = n;
            return 0;
        }
        p = p->next;
    }
    return -1;
}

typedef void (*CbA_8040C540)(s16, s32, s16, s32, s16);
typedef void (*CbB_8040C540)(s16, u32, s16);

struct SubA_8040C540 {
    u32 f0;
    s32 f4;
    s16 f8;
    u8 padA[2];
    u32 fC;
    s16 f10;
    u8 pad12[2];
    CbA_8040C540 cb;
    D_8040A45C *f18;
};

struct SubB_8040C540 {
    u32 f0;
    s16 f4;
    u8 pad6[2];
    CbB_8040C540 cb;
    u8 *fC;
};

struct Conn_8040C540 {
    s16 f0;
    s16 id;
    u8 pad4[4];
    s16 state;
    u8 padA[2];
    u32 thread;
    s16 err;
    u8 pad12[0xE];
    u8 sub[0x20];
};

void TLobby__sub_8040C74C(SubA_8040C540 *a);
s16 TLobby__sub_8040C8A8(u8 *dst, u8 *src, s16 max);
s16 TLobby__sub_8040C978(u8 *name);

void TLobby::dispatch_request_callback(s16 status) {
    Conn_8040C540 *connection = (Conn_8040C540 *)this;
    SubA_8040C540 *a;
    SubB_8040C540 *b;
    s32 err;

    switch (connection->state) {
    case 1:
        a = (SubA_8040C540 *)connection->sub;
        if ((u32)a->cb == 0xFFFFFFFFU) {
            return;
        }
        if (a->cb == NULL) {
            if (status != 0) {
                TLobby__sub_80421814();
                if (connection->thread != 0xFFFFFFFFU) {
                    TLobby::resume_thread(connection->thread);
                    connection->thread = -1;
                }
                TLobby__sub_804217E4();
                return;
            }
            if (connection->thread != 0xFFFFFFFFU) {
                TLobby::resume_thread(connection->thread);
                connection->thread = -1;
            }
            return;
        }
        err = connection->err;
        if ((s16)err < 0) {
            a->cb(connection->id, a->f4, err, a->fC, 0);
        } else {
            TLobby__sub_8040C74C(a);
            a->cb(connection->id, a->f4, a->f8, a->fC, a->f10);
        }
        a->cb = NULL;
        break;
    case 12:
        b = (SubB_8040C540 *)connection->sub;
        if ((u32)b->cb == 0xFFFFFFFFU) {
            return;
        }
        if (b->cb == NULL) {
            if (status != 0) {
                TLobby__sub_80421814();
                if (connection->thread != 0xFFFFFFFFU) {
                    TLobby::resume_thread(connection->thread);
                    connection->thread = -1;
                }
                TLobby__sub_804217E4();
                return;
            }
            if (connection->thread != 0xFFFFFFFFU) {
                TLobby::resume_thread(connection->thread);
                connection->thread = -1;
            }
            return;
        }
        err = connection->err;
        if ((s16)err < 0) {
            b->cb(connection->id, b->f0, err);
        } else {
            if (b->fC == NULL) {
                b->f4 = -0x42;
            } else if (b->f0 == 0) {
                b->f4 = TLobby__sub_8040C978(b->fC + 0x1C);
            } else {
                b->f4 = TLobby__sub_8040C8A8((u8 *)b->f0, b->fC + 0x1C, b->f4);
            }
            b->cb(connection->id, b->f0, b->f4);
        }
        b->cb = NULL;
        break;
    }
}

#pragma push
#pragma optimization_level 2
#pragma opt_common_subs off
void TLobby__sub_8040C74C(SubA_8040C540 *a) {
    s16 n;
    s8 *s;
    s32 len;
    s16 i;
    D_8040A45C *q;
    s16 cnt;
    u8 *out;
    C_8040A45C *node;

    q = a->f18;
    if (q == NULL) {
        a->f8 = -0x42;
        return;
    }
    s16 max;
    if (q->f104 != 0 && (max = a->f10) != 0) {
        if (a->fC == 0) {
            s = &q->f104;
            n = 0;
            while (n < 0xFF) {
                s8 c = *s++;
                if (c == 0) {
                    n--;
                    break;
                }
                len = c;
                if (n + len + 1 <= 0xFF) {
                    s += len;
                } else {
                    n = 0xFF;
                    break;
                }
                n += len + 1;
            }
            a->f10 = n;
        } else {
            a->f10 = TLobby__sub_8040C8A8((u8 *)a->fC, (u8 *)&q->f104, max);
        }
    } else {
        a->f10 = 0;
    }
    out = (u8 *)a->f4;
    cnt = 0;
    node = q->f208;
    for (i = 0; i < q->f204; i++, node = node->f20) {
        if (a->f0 == 0 || a->f0 == node->f4.f0) {
            cnt++;
            if (out != NULL) {
                NetMemcpy(out, &node->f4, sizeof(Rec_8040B33C));
                out += sizeof(Rec_8040B33C);
                if (cnt >= a->f8) {
                    break;
                }
            }
        }
    }
    a->f8 = cnt;
}
#pragma pop

s16 TLobby__sub_8040B838(u8 *dst, u8 *src, s16 len) {
    u8 *label;
    s16 i;
    u8 n;
    u8 c;
    s16 ret;

    label = dst++;
    n = 0;
    for (i = 0; i < len; i++, dst++, src++) {
        c = *src;
        if (c == '.') {
            *label = n;
            label = dst;
            n = 0;
        } else {
            *dst = c;
            n++;
        }
    }
    if (n != 0) {
        *label = n;
        ret = len + 2;
        *dst = 0;
    } else {
        dst[-1] = 0;
        ret = len + 1;
    }
    return ret;
}

inline s32 compare_rec(Rec_8040B33C *a, Rec_8040B33C *b) {
    switch (a->f0) {
    case 4:
        if (b->f0 != 4) {
            return -1;
        }
        return NetMemcmp(a->addr, b->addr, 4);
    case 6:
        if (b->f0 != 6) {
            return -1;
        }
        return NetMemcmp(a->addr, b->addr, 0x10);
    default:
    case 0:
        return -1;
    }
}

s16 TLobby__sub_8040C340(D_8040A45C *q, C_8040A45C *node) {
    s16 i;
    G_8040A45C *g;
    C_8040A45C *prev;
    C_8040A45C *p;

    if (node == NULL) {
        return -1;
    }
    if (q == NULL) {
        return -1;
    }
    if (q->f0 == 0 || q->f208 == NULL) {
        return -1;
    }
    g = &dns_resolver_state;
    p = q->f208;
    prev = NULL;
    for (i = 0; p != NULL && i < g->nc; i++) {
        if (compare_rec(&p->f4, &node->f4) != 0) {
            prev = p;
        } else {
            q->f204--;
            if (prev == NULL) {
                q->f208 = p->f20;
            } else {
                prev->f20 = p->f20;
            }
            p->f0 = 0;
            p->f20 = NULL;
            return 0;
        }
        p = p->f20;
    }
    return -1;
}


#pragma push
#pragma optimization_level 2
#pragma opt_common_subs off
s16 TLobby__sub_8040C8A8(u8 *dst, u8 *src, s16 max) {
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

#pragma push
#pragma optimization_level 2
#pragma opt_common_subs off
s16 TLobby__sub_8040C978(u8 *name) {
    s32 n;
    s16 len = 0;

    while (len < 0xFF) {
        s8 c = *name++;
        if (c == 0) {
            return --len;
        }
        n = c;
        if (0xFF >= len + n + 1) {
            name += n;
        } else {
            return 0xFF;
        }
        len += n + 1;
    }
    return len;
}
#pragma pop

s32 TLobby__sub_8040C9E0(u8 *arg0, u8 *arg1) {
    struct Fields_arg0 { u8 pad_0[4]; s32 field_4; u8 pad_8[16]; u16 field_18; };
    struct Fields_arg1 { u8 pad_0[4]; u32 field_4; u8 pad_8[16]; u16 field_18; };
    s32 var_r5;
    u8 *var_r3;
    u8 *var_r4;
    switch ((s32) (((Fields_arg0*)arg0)->field_18)) {
    case 1:
        if ((u16) ((Fields_arg1*)arg1)->field_18 != 1) {
            var_r3 = (u8 *)((void *)-1);
            return -1;
        }
        switch (((Fields_arg0*)arg0)->field_4) {
        case 4:
            if ((u32) ((Fields_arg1*)arg1)->field_4 != 4U) {
                var_r3 = (u8 *)((void *)-1);
                return -1;
            }
            var_r3 = (u8 *)(arg0 + 8);
            var_r4 = (u8 *)(arg1 + 8);
            var_r5 = 4;
            return NetMemcmp((void *)(var_r3), (void *)(var_r4), 4);
        case 6:
            if ((u32) ((Fields_arg1*)arg1)->field_4 != 6U) {
                var_r3 = (u8 *)((void *)-1);
                return -1;
            }
            var_r3 = (u8 *)(arg0 + 8);
            var_r4 = (u8 *)(arg1 + 8);
            var_r5 = 0x10;
            return NetMemcmp((void *)(var_r3), (void *)(var_r4), 0x10);
        default:
        case 0:
            var_r3 = (u8 *)((void *)-1);
            return -1;
        }
        break;
    case 28:
        if ((u16) ((Fields_arg1*)arg1)->field_18 != 0x1C) {
            var_r3 = (u8 *)((void *)-1);
            return -1;
        }
        switch (((Fields_arg0*)arg0)->field_4) {
        case 4:
            if ((u32) ((Fields_arg1*)arg1)->field_4 != 4U) {
                var_r3 = (u8 *)((void *)-1);
                return -1;
            }
            var_r3 = (u8 *)(arg0 + 8);
            var_r4 = (u8 *)(arg1 + 8);
            var_r5 = 4;
            return NetMemcmp((void *)(var_r3), (void *)(var_r4), 4);
        case 6:
            if ((u32) ((Fields_arg1*)arg1)->field_4 != 6U) {
                var_r3 = (u8 *)((void *)-1);
                return -1;
            }
            var_r3 = (u8 *)(arg0 + 8);
            var_r4 = (u8 *)(arg1 + 8);
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

struct Ipv4Header {
    u8 version_ihl;
    u8 tos;
    u16 length;
    u16 id;
    u16 fragment;
    u8 ttl;
    u8 protocol;
    u16 checksum;
    u32 src;
    u32 dst;
};
struct Icmp4Header {
    u8 type;
    u8 code;
    u16 checksum;
    u8 rest[4];
};

s16 TUdpSocket__sub_8040CE58(Icmp4Header *icmp, Ipv4Header *ip, s16 len, s16 idx) {
    s16 NetIPv4IsUnspecified(u32 arg0);
    s16 NetIPv4IsLoopback(u32 arg0);
    s16 TLobby__sub_8040FDA0(u32, s16);
    s16 TLobby__sub_8040E780(NetPacket *, u32, u32, s32, s32, s32, s32);
    NetPacket *pkt;
    s16 hlen;
    s16 ret;

    if (NetIPv4IsUnspecified(ip->src) || NetIPv4IsLoopback(ip->src) || TLobby__sub_8040FDA0(ip->src, idx)) {
        return -1;
    }
    if (TLobby__sub_8040FDA0(ip->dst, idx)) {
        return -1;
    }
    pkt = (NetPacket *)TLobby::alloc_free_entry();
    if (pkt == NULL) {
        return -1;
    }
    hlen = (ip->version_ihl & 0xF) << 2;
    len = len < hlen + 8 ? len : hlen + 8;
    pkt->fragment_count = 0;
    pkt->total_bytes = len;
    pkt->fragments[pkt->fragment_count].length = len;
    ((TLobby *)&pkt->fragments[pkt->fragment_count].buffer)->set_value_and_enable((s32)ip);
    pkt->fragment_count++;
    pkt->total_bytes += sizeof(Icmp4Header);
    pkt->fragments[pkt->fragment_count].length = sizeof(Icmp4Header);
    ((TLobby *)&pkt->fragments[pkt->fragment_count].buffer)->set_value_and_enable((s32)icmp);
    pkt->fragment_count++;
    icmp->checksum = 0;
    icmp->checksum = ((TLobby *)pkt)->calc_ip_checksum(1);
    ret = TLobby__sub_8040E780(pkt, ip->src, ip->dst, 0, 0, 0, 1);
    ((TUdpSocket *)pkt)->release_entry();
    return ret;
}

s32 TLobby__sub_8040CFE8(u8 type, u8 code, u32 src, u32 dst, NetPacket *pkt) {
    s16 TLobby__sub_8040E780(NetPacket *, u32, u32, s32, s32, s32, s32);
    NetBufferRef ref;
    Icmp4Header hdr;

    switch (type) {
    case 0:
        ((TLobby *)&ref)->set_value_and_enable((s32)&hdr);
        TLobby__sub_80406FD8(&ref, &pkt->fragments[pkt->fragment_count - 1].buffer, sizeof(hdr));
        TLobby__sub_80406EB8(&pkt->fragments[pkt->fragment_count - 1].buffer, sizeof(hdr));
        pkt->fragments[pkt->fragment_count - 1].length -= sizeof(hdr);
        pkt->fragments[pkt->fragment_count].length = sizeof(hdr);
        ((TLobby *)&pkt->fragments[pkt->fragment_count].buffer)->set_value_and_enable((s32)&hdr);
        pkt->fragment_count++;
        break;
    default:
        return -1;
    }
    hdr.type = type;
    hdr.code = code;
    hdr.checksum = 0;
    hdr.checksum = ((TLobby *)pkt)->calc_ip_checksum(1);
    if (TLobby__sub_8040E780(pkt, dst, src, 0, 0, 0, 1)) {
        return -1;
    }
    return 0;
}

struct Icmp6MessageHeader {
    u8 type;
    u8 code;
    u16 checksum;
};
struct Ipv6SendOptions;

struct Icmp6ErrorInfo {
    u8 type;
    u8 code;
    u16 checksum;
    s32 pointer;
};
struct Ipv6Header_8040D120 {
    u32 version_class_flow;
    u16 payload_length;
    u8 next_header;
    u8 hop_limit;
    IPv6Address src;
    IPv6Address dst;
};
struct UdpHeader {
    u16 src_port;
    u16 dst_port;
    u16 length;
    u16 checksum;
};

s16 NetIPv6HandleIcmpMessage(NetPacket *pkt, u8 *src, u8 *dst, u8 hop_limit, s16 iface) {
    s16 NetIPv6HandleRouterSolicitation(NetPacket *pkt, u8 *src, u8 *dst, s16 iface);
    s16 NetIPv6HandleRouterAdvertisement(NetPacket *pkt, u8 *src, u8 *dst, s16 iface);
    s16 NetIPv6HandleNeighborSolicitation(NetPacket *pkt, u8 *src, u8 *dst, s16 iface);
    s16 NetIPv6HandleNeighborAdvertisement(NetPacket *pkt, u8 *src, u8 *dst, s16 iface);
    s16 NetIPv6HandleRedirect(NetPacket *pkt, u8 *src, u8 *dst, s16 iface);
    s32 TLobby__sub_80411DEC(IPv6Address *addr, s16 mtu);
    void TLobby__sub_80420D38(u16 port, u8 code);
    s16 TLobby__sub_8040D718(u8 type, u8 code, u8 *src, u8 *dst, NetPacket *pkt, s16 idx);
    NetBufferRef ref;
    Ipv6Header_8040D120 ip;
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
    ((TLobby *)&ref)->set_value_and_enable((s32)&icmp);
    TLobby__sub_80406FD8(&ref, &body->buffer, 8);
    switch (icmp.type) {
    case 128:
        reply = (NetPacket *)TLobby::alloc_free_entry();
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
        ((TUdpSocket *)reply)->release_entry();
        return r;
    case 1:
        TLobby__sub_80406EB8(&body->buffer, 8);
        ((TLobby *)&ref)->set_value_and_enable((s32)&ip);
        TLobby__sub_80406FD8(&ref, &body->buffer, sizeof(ip));
        TLobby__sub_80406EB8(&body->buffer, sizeof(ip));
        switch (ip.next_header) {
        case 17:
            ((TLobby *)&ref)->set_value_and_enable((s32)&udp);
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
            ((TLobby *)&ref)->set_value_and_enable((s32)&ip);
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

s16 TLobby__sub_8040D510(Icmp6ErrorInfo *err, u8 *hdr, s16 len, s16 idx) {
    s16 NetIPv6IsMulticast(u8 *addr);
    s16 NetIPv6IsUnspecified(u8 *addr);
    s16 TLobby__sub_80411F1C(u8 *, u8 *, s16);
    s16 TLobby__sub_80413D78(u8 *addr, s16 idx);
    s16 TLobby__sub_80410A98(NetPacket *, u8 *, u8 *, Ipv6SendOptions *, s32);
    u8 *src;
    NetPacket *pkt;
    u8 source[16];
    s32 excess;
    s16 over;
    s16 r;

    if (NetIPv6IsUnspecified(hdr + 8) || NetIPv6IsMulticast(hdr + 8) || TLobby__sub_80413D78(hdr + 8, idx)) {
        return -1;
    }
    if (NetIPv6IsMulticast(hdr + 0x18)) {
        switch (err->type) {
        case 3:
        default:
            return -1;
        case 2:
        case 4:
            r = TLobby__sub_80411F1C(source, hdr + 8, idx);
            if (r < 0) {
                return r;
            }
            break;
        }
    } else {
        NetMemcpy(source, hdr + 0x18, 0x10);
    }
    src = hdr + 8;
    pkt = (NetPacket *)TLobby::alloc_free_entry();
    if (pkt == NULL) {
        return -1;
    }
    pkt->fragment_count = 0;
    pkt->total_bytes = len;
    pkt->fragments[pkt->fragment_count].length = len;
    ((TLobby *)&pkt->fragments[pkt->fragment_count].buffer)->set_value_and_enable((s32)hdr);
    pkt->fragment_count++;
    pkt->total_bytes += sizeof(Icmp6ErrorInfo);
    pkt->fragments[pkt->fragment_count].length = sizeof(Icmp6ErrorInfo);
    ((TLobby *)&pkt->fragments[pkt->fragment_count].buffer)->set_value_and_enable((s32)err);
    pkt->fragment_count++;
    if (pkt->total_bytes + 0x28 > 0x500) {
        over = excess = pkt->total_bytes - 0x4D8;
        if (over > pkt->fragments[0].length) {
            return -1;
        }
        pkt->total_bytes -= over;
        pkt->fragments[0].length -= over;
    }
    err->checksum = 0;
    err->checksum = TLobby__sub_80411040((const IPv6Address *)source, (const IPv6Address *)src, 0x3A, pkt, 1);
    r = TLobby__sub_80410A98(pkt, src, source, NULL, 0x3A);
    ((TUdpSocket *)pkt)->release_entry();
    return r;
}

s16 TLobby__sub_8040D718(u8 type, u8 code, u8 *src, u8 *dst, NetPacket *pkt, s16 idx) {
    s16 NetIPv6IsMulticast(u8 *arg0);
    s16 NetIPv6IsUnspecified(u8 *arg0);
    s16 TLobby__sub_80411F1C(u8 *, u8 *, s16);
    s16 TLobby__sub_80410A98(NetPacket *, u8 *, u8 *, Ipv6SendOptions *, s32);
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
        ((TLobby *)&pkt->fragments[pkt->fragment_count].buffer)->set_value_and_enable((s32)&hdr);
        pkt->fragment_count++;
        break;
    default:
        return -1;
    }
    hdr.type = type;
    hdr.code = code;
    hdr.checksum = 0;
    hdr.checksum = TLobby__sub_80411040((const IPv6Address *)src, (const IPv6Address *)dst, 0x3A, pkt, 1);
    if (TLobby__sub_80410A98(pkt, dst, src, NULL, 0x3A)) {
        return -1;
    }
    return 0;
}

s32 TLobby__sub_8040E780(s32, s32, s32, s32, s32, s32, void *);
s32 TLobby__sub_80410A98(NetPacket *, u8 *, u8 *, Ipv6SendOptions *, s32);

s32 TLobby::dispatch_by_addr_family(s32 arg0, u8 *arg1, u8 *arg2, u8 *arg3, void *arg4, void *arg5) {
    switch (*(s32 *)arg2) {
    case 4:
        return TLobby__sub_8040E780(arg0, *(s32 *)(arg1 + 4), *(s32 *)(arg2 + 4), arg3[0], arg3[1], arg3[2], arg5);
    case 6:
        return TLobby__sub_80410A98((NetPacket *)arg0, arg1 + 4, arg2 + 4, (Ipv6SendOptions *)arg4, (s32)arg5);
    case 0:
    default:
        return -2;
    }
}

u16 TLobby__sub_8040D8F0(u8 *arg0, u8 *arg1, s8 arg2, u8 *pkt, s16 flag) {
    struct Fields_arg0 { s32 field_0; s32 field_4; };
    struct Fields_arg1 { u8 pad_0[4]; s32 field_4; };
    switch (((Fields_arg0*)arg0)->field_0) {
    case 4:
        return TLobby::calc_pseudo_header_checksum(((Fields_arg0*)arg0)->field_4, ((Fields_arg1*)arg1)->field_4, arg2, pkt, flag);
    case 6:
        return TLobby__sub_80411040((const IPv6Address *)((void *) (arg0 + 4)), (const IPv6Address *)((void *) (arg1 + 4)), arg2, (const NetPacket *)(pkt), flag);
    case 0:
    default:
        return 0xFFFEU;
    }
}

struct Ent_8040D95C { u8 pad0[2]; s16 f2; u8 pad4[2]; s16 f6; u8 pad8[4]; s32 fC; };
struct In_8040D95C { s32 type; s32 f4; };
struct Out_8040D95C { s32 type; u32 f4; };
s32 TLobby__sub_8040EF50(void *, s32, s32);
s32 TLobby__sub_80411F1C(u8 *, u8 *, s16);
s32 select_source_address__6TLobbyFPvPv(Out_8040D95C *arg0, In_8040D95C *arg1) {
    Ent_8040D95C *e;
    s16 ok;
    s16 NetIPv6IsUnspecified(u8 *arg0);

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
        e = (Ent_8040D95C *)TLobby__sub_80413264(&arg1->f4, (s32)&arg0->f4);
        if (e == NULL) {
            return -6;
        }
        arg0->type = 6;
        return TLobby__sub_80411F1C((u8 *)&arg0->f4, (u8 *)&arg1->f4, e->f6);
    case 0:
    default:
        return -2;
    }
}

s32 TLobby__sub_8040DA54(u8 *arg0, u8 *arg1) {
    struct Fields_arg0 { s32 field_0; u8 * field_4; };
    struct Fields_arg1 { u8 pad_0[4]; s32 field_4; };
    s32 var_r4;
    u8 *var_r3;
    switch (((Fields_arg0*)arg0)->field_0) {
    case 4:
        var_r3 = (u8 *)(((Fields_arg0*)arg0)->field_4);
        var_r4 = ((Fields_arg1*)arg1)->field_4;
        return TLobby::is_lookup_found((u32)var_r3, (u32)(var_r4));
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
        return TLobby__sub_804136EC(address->address);
    default:
        return -2;
    }
}

s32 TLobby::is_multicast_address(s16 arg1) {
    u8 *arg0 = (u8 *)this;
    struct Fields_arg0 { s32 field_0; u32 field_4; };
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

s16 is_addr_unspecified__6TLobbyFPv(u8 *arg0) {
    struct Fields_arg0 { s32 field_0; u32 field_4; };
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

s16 TLobby::compare_sockaddr(u8 *arg1) {
    u8 *arg0 = (u8 *)this;
    struct Fields_arg0 { s32 field_0; u8 * field_4; };
    struct Fields_arg1 { u32 field_0; u8 * field_4; };
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

typedef char RecoveredGlobal_8040EF00_lbl_805C1B60_size[sizeof(RecoveredGlobal_8040EF00_lbl_805C1B60) == 0x18 ? 1 : -1];

typedef char RecoveredGlobal_8040DD68_lbl_805C1B38_size[sizeof(RecoveredGlobal_8040DD68_lbl_805C1B38) == 0x28 ? 1 : -1];

s16 TLobby__sub_8040DC8C(u8 *arg0, u8 *arg1) {
    s16 temp_r3;
    s16 entry_field_26;
    u32 temp_r5;
    u8 *temp_r3_3;
    u8 *temp_r3_4;
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
        temp_r3_4 = (u8 *)(TLobby__sub_80413264(arg0 + 4, (s32)(arg1 + 4)));
        if (temp_r3_4 == NULL) {
            return -6;
        }
        entry_field_26 = TLobby::get_entry_field_26(*(s16 *)((s8 *)temp_r3_4 + 6));
        if (entry_field_26 < 0x3C) {
            return -6;
        }
        return entry_field_26 - 0x3C;
    case 0:
    default:
        return -2;
    }
}

s32 TLobby__sub_8040DD68(void) {
    TLobby::release_slot_by_id(0x800);
    TLobby__sub_803F892C((void *)((void *) (&ipv4_protocol_state.value)));
    ipv4_protocol_state.value = 0;
    return 0;
}

typedef void (*Handler_8041A130)(s32, s16, s16, s16);
s32 register_protocol_handler__6TLobbyFUsi(u16 type, Handler_8041A130 fn);
void TUdpSocket__sub_8040DE4C(void);
s32 TLobby::init_ipv4_interfaces() {
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
    register_protocol_handler__6TLobbyFUsi(0x800, (Handler_8041A130)TUdpSocket__sub_8040DE4C);
    return 0;
}

typedef char RecoveredGlobal_8040ED28_lbl_805C1B60_size[sizeof(RecoveredGlobal_8040ED28_lbl_805C1B60) == 0x18 ? 1 : -1];

struct PH_8040EC38 { s32 src; s32 dst; u8 zero; s8 proto; u16 len; };
struct P_8040EC38 { u8 pad0[8]; s32 f8; s16 fC; };

u16 TUdpSocket__sub_80419864(void *buf, s16 len);

u16 TLobby::calc_pseudo_header_checksum(s32 src, s32 dst, s8 proto, void *pkt, s16 flag) {
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

u16 TLobby::calc_ip_checksum(s16 b) {
    u32 s = TLobby__sub_80406BD8(this, b);
    s = (s >> 16) + (s & 0xFFFF);
    s += (s >> 16);
    return ~s;
}

s32 TLobby__sub_8040ED28(void) {
    TLobby__sub_803F8958((void *)((void *) (&(*(RecoveredGlobal_8040ED28_lbl_805C1B60 *)&ipv4_address_routing_state).value)));
    *(s16 *)((s8 *)(&(*(RecoveredGlobal_8040ED28_lbl_805C1B60 *)&ipv4_address_routing_state).value) + 0) = 0;
    *(s16 *)((s8 *)(&(*(RecoveredGlobal_8040ED28_lbl_805C1B60 *)&ipv4_address_routing_state).value) + 2) = 0;
    *(s16 *)((s8 *)(&(*(RecoveredGlobal_8040ED28_lbl_805C1B60 *)&ipv4_address_routing_state).value) + 4) = 0;
    return 0;
}

typedef char RecoveredGlobal_8040ED70_lbl_805C1B60_size[sizeof(RecoveredGlobal_8040ED70_lbl_805C1B60) == 0x18 ? 1 : -1];
s32 TLobby__sub_8040ED70(void) {
    ((TLobby *)(&(*(RecoveredGlobal_8040ED70_lbl_805C1B60 *)&ipv4_address_routing_state).value))->init_buffer_descriptor_a();
    NetMemset((void *)((int) (*(s32 *)((s8 *)(&(*(RecoveredGlobal_8040ED70_lbl_805C1B60 *)&ipv4_address_routing_state).value) + 8))), 0, (int)((int) (*(s16 *)((s8 *)(&(*(RecoveredGlobal_8040ED70_lbl_805C1B60 *)&ipv4_address_routing_state).value) + 0) * 0x14)));
    NetMemset((void *)((int) (*(s32 *)((s8 *)(&(*(RecoveredGlobal_8040ED70_lbl_805C1B60 *)&ipv4_address_routing_state).value) + 0xC))), 0, (int)((int) (*(s16 *)((s8 *)(&(*(RecoveredGlobal_8040ED70_lbl_805C1B60 *)&ipv4_address_routing_state).value) + 2) * 0x14)));
    NetMemset((void *)((int) (*(s32 *)((s8 *)(&(*(RecoveredGlobal_8040ED70_lbl_805C1B60 *)&ipv4_address_routing_state).value) + 0x10))), 0, (int)((int) (*(s16 *)((s8 *)(&(*(RecoveredGlobal_8040ED70_lbl_805C1B60 *)&ipv4_address_routing_state).value) + 4) * 0x18)));
    return 0;
}

struct Ipv4Route {
    u16 flags;
    s16 iface;
    u32 dst;
    u32 mask;
    u32 gateway;
    s16 f10;
    s16 type;
};
struct Ipv4Alias {
    s16 f0;
    u8 pad2[2];
    u32 addr;
    u32 broadcast;
    u32 network;
    u32 mask;
    Ipv4Alias *next;
};
struct Ipv4Iface {
    s16 state;
    s16 handle;
    s16 f4;
    u8 pad6[2];
    u32 addr;
    u32 broadcast;
    u32 network;
    u32 mask;
    Ipv4Alias *aliases;
};
struct Ipv4RoutingState {
    s16 nroutes;
    s16 nifaces;
    s16 max_aliases;
    s16 f6;
    Ipv4Route *routes;
    Ipv4Iface *ifaces;
};
struct Ipv4IfaceAddrRecord {
    s32 kind;
    u32 addr;
    u32 mask;
    u32 broadcast;
    u8 pad10[0xC];
};

#pragma push
#pragma dont_inline off
#pragma inline_depth(4)
inline s16 is_iface_destination_8040EDE4(s16 idx, u32 dst) {
    Ipv4Iface *ifc = (Ipv4Iface *)TLobby::get_active_entry_by_index(idx);

    if (ifc == NULL) {
        return 0;
    }
    if (ifc->addr == 0 || dst == 0xFFFFFFFF || dst == ifc->broadcast) {
        return 1;
    }
    return 0;
}

s32 TLobby__sub_8040EDE4(s32 arg0, u32 dst, s16 idx) {
    Ipv4RoutingState *g;
    Ipv4Iface *ifc;

    if (idx < 0 || idx >= (g = (Ipv4RoutingState *)&ipv4_address_routing_state)->nifaces) {
        return -0x109;
    }
    ifc = g->ifaces;
    ifc += idx;
    if (ifc->state != 1) {
        return -6;
    }
    if (dst == 0 || is_iface_destination_8040EDE4(idx, dst)) {
        return TLobby::call_handler_by_index(idx, ifc->handle, 1, (s32)&dst, arg0);
    }
    return TLobby::dispatch_handler_by_index(idx, ifc->handle, (s32)&dst, arg0);
}
#pragma pop

#pragma push
#pragma opt_common_subs on
s16 TLobby__sub_8040EF00(s16 arg0) {
    struct Fields_temp_r3 { s16 field_0; u8 pad_2[2]; s16 field_4; };
    u8 *temp_r3;
    if ((arg0 < 0) || (arg0 >= (s16) *(s16 *)((s8 *)(&ipv4_address_routing_state.value) + 2))) {
        return -0x109;
    }
    temp_r3 = (u8 *)(*(s32 *)((s8 *)(&ipv4_address_routing_state.value) + 0xC) + (arg0 * 0x1C));
    if ((s16) ((Fields_temp_r3*)temp_r3)->field_0 != 1) {
        return -2;
    }
    return ((Fields_temp_r3*)temp_r3)->field_4;
}
#pragma pop

s32 TLobby__sub_8040F00C(s16 idx, NetBufferRef *out, s16 len, s32 arg3) {
    s16 TLobby__sub_80409EB0(s16 arg0, s32 arg1);
    Ipv4RoutingState *g = (Ipv4RoutingState *)&ipv4_address_routing_state;
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
    if (len < sizeof(rec)) {
        return -2;
    }
    rec.kind = 4;
    rec.addr = ifc->addr;
    rec.mask = ifc->mask;
    rec.broadcast = ifc->broadcast;
    ((TLobby *)&ref)->set_value_and_enable((s32)&rec);
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
        ((TLobby *)&ref)->set_value_and_enable((s32)&rec);
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

#pragma push
#pragma dont_inline off
#pragma inline_depth(4)
inline s16 get_iface_addr_8040F1A0(s16 *n, Ipv4Iface **ifaces, u32 *addr) {
    if (*n <= 0) {
        return 0;
    }
    if ((*ifaces)->state != 1) {
        return 0;
    }
    *addr = (*ifaces)->addr;
    return 1;
}

s16 TRKValidMemory32(u32, u32, u32, s16, u8, u16);

inline void remove_host_route_8040F1A0(Ipv4RoutingState *g, u32 dst, u32 gateway) {
    s16 i;
    Ipv4Route *e;

    e = g->routes;

    for (i = 0; i < g->nroutes; i++, e++) {
        if ((e->flags & 1) && e->dst == dst && e->gateway == gateway && (e->type & 1) == 1) {
            e->flags = 0;
            return;
        }
    }
}

s16 TLobby__sub_8040F1A0(s16 idx) {
    Ipv4RoutingState *g = (Ipv4RoutingState *)&ipv4_address_routing_state;
    s16 *pn;
    Ipv4Iface **pifs;
    s16 count;
    Ipv4Iface *ifc;
    Ipv4Alias *alias;
    u32 gateway;

    if (idx < 0 || idx >= *(pn = &g->nifaces)) {
        return -0x109;
    }
    ifc = *(pifs = &g->ifaces);
    ifc += idx;
    if (ifc->state != 1) {
        return 0;
    }
    alias = ifc->aliases;
    count = 0;
    while (alias != NULL && count < g->max_aliases) {
        Ipv4Alias *next;
        if (TLobby::is_socket_flag_set(idx) == 0 && get_iface_addr_8040F1A0(pn, pifs, &gateway)) {
            remove_host_route_8040F1A0(g, alias->addr, gateway);
        }
        TLobby__sub_80409D7C(idx, ifc->handle, 2, (s32)&alias->addr);
        next = alias->next;
        count++;
        alias->f0 = 0;
        alias->addr = 0;
        alias->network = 0;
        alias->broadcast = 0;
        alias->mask = 0;
        alias->next = NULL;
        alias = next;
    }
    if (TLobby::is_socket_flag_set(idx) == 0 && get_iface_addr_8040F1A0(pn, pifs, &gateway)) {
        remove_host_route_8040F1A0(g, ifc->addr, gateway);
    }
    {
        Ipv4Route *e;
        s16 n;
        n = g->nroutes;
        e = g->routes;
        for (; n > 0; n--, e++) {
            if ((e->flags & 1) && e->iface == idx) {
                e->flags = 0;
            }
        }
    }
    TLobby::call_entry_callback(idx, ifc->handle);
    ifc->state = 0;
    ifc->handle = 0;
    ifc->f4 = 0;
    ifc->addr = 0;
    ifc->network = 0;
    ifc->broadcast = 0;
    ifc->mask = 0;
    ifc->aliases = NULL;
    return 0;
}

#pragma opt_common_subs on
s16 TLobby__sub_8040F454(u32 addr, u32 mask, u32 broadcast, s16 idx) {
    Ipv4RoutingState *g = (Ipv4RoutingState *)&ipv4_address_routing_state;
    s16 *pn;
    Ipv4Iface **pifs;
    s16 unspecified;
    Ipv4Iface *ifc;
    s16 r;
    s16 err;
    s16 found;
    u32 gateway;

    if (idx < 0 || idx >= *(pn = &g->nifaces)) {
        return -0x109;
    }
    ifc = *(pifs = &g->ifaces);
    ifc += idx;
    if (ifc->state == 1) {
        return -2;
    }
    ifc->state = 1;
    ifc->handle = TLobby__sub_8040A044(idx, 0x800, 4, (u8 *)&addr);
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
    r = TLobby::invoke_socket_callback(idx, ifc->handle);
    if (r < g->f6) {
        ifc->state = 0;
        return -6;
    }
    ifc->f4 = r;
    found = 0;
    ifc->aliases = NULL;
    gateway = 0xFFFFFFFF;
    if (TLobby::is_socket_flag_set(idx) == 0 && !unspecified) {
        found = get_iface_addr_8040F1A0(pn, pifs, &gateway);
        if (found) {
            r = TRKValidMemory32(addr, 0xFFFFFFFF, gateway, 0, 1, 0);
            if (r < 0) {
                TLobby::call_entry_callback(idx, ifc->handle);
                ifc->state = 0;
                ifc->handle = 0;
                ifc->f4 = 0;
                ifc->addr = 0;
                ifc->network = 0;
                ifc->broadcast = 0;
                ifc->mask = 0;
                return r;
            }
        }
    }
    err = TRKValidMemory32(addr & mask, mask, addr, 0, 1, 0);
    if (err < 0) {
        if (TLobby::is_socket_flag_set(idx) == 0 && gateway != 0xFFFFFFFF && !unspecified) {
            remove_host_route_8040F1A0(g, addr, gateway);
        }
        TLobby::call_entry_callback(idx, ifc->handle);
        ifc->state = 0;
        ifc->handle = 0;
        ifc->f4 = 0;
        ifc->addr = 0;
        ifc->network = 0;
        ifc->broadcast = 0;
        ifc->mask = 0;
        return err;
    }
    return 0;
}
#pragma pop

s32 TLobby::is_lookup_found(u32 arg0, u32 arg1) {
    if (TLobby__sub_8040F76C(arg0, arg1) != NULL) {
        return 1;
    }
    return 0;
}

Ipv4Route *TLobby__sub_8040F76C(u32 dst, u32 gateway) {
    Ipv4RoutingState *g = (Ipv4RoutingState *)&ipv4_address_routing_state;
    s16 n;
    u16 flags;
    s16 i;
    Ipv4Route *e;
    Ipv4Route *host;
    Ipv4Route *net;
    Ipv4Route *def;
    u32 masked;

    host = NULL;
    e = g->routes;
    net = NULL;
    n = g->nroutes;
    def = NULL;
    for (i = 0; i < n; i++, e++) {
        flags = e->flags;
        masked = dst & e->mask;
        if (!(flags & 1)) {
            continue;
        }
        if ((flags & 4) && e->dst == dst) {
            return e;
        }
        if ((flags & 8) && e->type == 1) {
            if (dst == 0xFFFFFFFF || dst == 0) {
                if (e->gateway == gateway) {
                    host = e;
                    continue;
                }
            } else if (e->dst == masked) {
                host = e;
                continue;
            }
        }
        if (flags & 2) {
            if (e->dst == 0) {
                if (def == NULL) {
                    def = e;
                }
            } else if (e->dst == masked && net == NULL) {
                net = e;
            }
        }
    }
    if (host != NULL) {
        return host;
    }
    if (net != NULL) {
        return net;
    }
    if (def != NULL) {
        return def;
    }
    return NULL;
}

s16 TRKValidMemory32(u32, u32, u32, s16, u8, u16);

#pragma push
#pragma opt_common_subs on
s32 TLobby__sub_8040F8A4(u32 dst, u32 gateway, u32 mask, u16 flags, u32 old_gateway) {
    Ipv4RoutingState *g = (Ipv4RoutingState *)&ipv4_address_routing_state;
    s16 i;
    s16 add_host;
    Ipv4Route *e;

    add_host = 0;
    i = 0;
    e = g->routes;
    for (; i < g->nroutes; i++, e++) {
        if (!(e->flags & 1) || e->gateway != old_gateway) {
            continue;
        }
        if (e->dst == 0) {
            flags |= 2;
            add_host = 1;
            continue;
        }
        if (flags & 4) {
            if (!e->flags & 4) {
                continue;
            }
            if (e->dst == dst) {
                e->flags = flags | 0x20;
                e->gateway = gateway;
                return 0;
            }
        } else {
            if (e->flags & 4) {
                continue;
            }
            if ((dst & e->mask) == (e->dst & mask)) {
                e->flags = flags | 0x10;
                e->gateway = gateway;
                return 0;
            }
        }
    }
    if (add_host && TRKValidMemory32(dst, mask, gateway, 1, 2, flags)) {
        return -1;
    }
    return 0;
}
#pragma pop

struct Ent_8040F9CC { u16 flags; u8 pad2[2]; u32 dst; u8 pad8[4]; u32 gateway; u8 pad10[2]; s16 type; };
struct G_8040F9CC { s16 count; u8 pad2[6]; Ent_8040F9CC *ents; };

s32 TLobby__sub_8040F9CC(u32 dst, u32 mask, u32 gateway, s16 flags) {
    G_8040F9CC *g = (G_8040F9CC *)&ipv4_address_routing_state;
    s32 type_bit;
    s16 i;
    s16 n;
    Ent_8040F9CC *e;

    e = g->ents;
    n = g->count;
    type_bit = flags & 1;
    for (i = 0; i < n; i++, e++) {
        if ((e->flags & 1) && e->dst == dst && e->gateway == gateway && type_bit == (e->type & 1)) {
            e->flags = 0;
            return 0;
        }
    }
    return -2;
}

#pragma push
#pragma dont_inline off
#pragma inline_depth(4)
#pragma opt_common_subs on
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

s16 TRKValidMemory32(u32 dst, u32 mask, u32 gateway, s16 f10, u8 type, u16 flags) {
    Ipv4RoutingState *g = (Ipv4RoutingState *)&ipv4_address_routing_state;
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

struct A_RT { u8 pad0[4]; u32 addr; u8 pad8[8]; u32 mask; A_RT *next; };
struct E_RT { s16 state; u8 pad2[6]; u32 addr; u8 padC[8]; u32 mask; A_RT *alias; };
struct G_RT { s16 f0; s16 count; s16 maxalias; u8 pad6[6]; E_RT *ents; };

s16 TLobby__sub_8040FCEC(u32 ip) {
    G_RT *g;
    s16 m;
    s16 n;
    s16 i;
    s16 j;
    E_RT *e;
    A_RT *a;

    g = (G_RT *)&ipv4_address_routing_state;
    e = g->ents;
    i = 0;
    m = g->maxalias;
    n = g->count;

    for (; i < n; i++, e++) {
        if (e->state == 1) {
            if (e->addr == ip) {
                return i;
            }
            for (a = e->alias, j = 0; a != NULL && j < m; j++) {
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

struct Ent_8040FDA0 { s16 state; u8 pad2[6]; u32 f8; u32 fC; u8 pad10[0xC]; };
struct G_8040FDA0 { s16 f0; s16 count; u8 pad4[8]; Ent_8040FDA0 *ents; };

s32 TLobby__sub_8040FDA0(u32 arg0, s16 arg1) {
    Ent_8040FDA0 *e;
    if (arg1 < 0 || arg1 >= ((G_8040FDA0 *)&ipv4_address_routing_state)->count) {
        e = NULL;
    } else {
        e = ((G_8040FDA0 *)&ipv4_address_routing_state)->ents;
        e += arg1;
        if (e->state != 1) {
            e = NULL;
        }
    }
    if (e == NULL) {
        return 0;
    }
    if (e->f8 == 0 || arg0 == 0xFFFFFFFF || arg0 == e->fC) {
        return 1;
    }
    return 0;
}

s16 NetIPv4IsUnspecified(u32 arg0) {
    if (arg0 == 0U) {
        return 1;
    }
    return 0;
}

typedef char RecoveredGlobal_8040FE40_lbl_805C1B60_size[sizeof(RecoveredGlobal_8040FE40_lbl_805C1B60) == 0x18 ? 1 : -1];

typedef char RecoveredGlobal_8040FE9C_lbl_805C1B60_size[sizeof(RecoveredGlobal_8040FE9C_lbl_805C1B60) == 0x18 ? 1 : -1];

#pragma push
#pragma opt_common_subs on
s32 TLobby__sub_8040FE40(s16 arg0) {
    struct Fields_var_r3 { s16 field_0; };
    s16 *var_r3;
    if ((arg0 < 0) || (arg0 >= (s16) *(s16 *)((s8 *)(&(*(RecoveredGlobal_8040FE40_lbl_805C1B60 *)&ipv4_address_routing_state).value) + 2))) {
        var_r3 = (s16 *)(NULL);
    } else {
        var_r3 = (s16 *)(*(s32 *)((s8 *)(&(*(RecoveredGlobal_8040FE40_lbl_805C1B60 *)&ipv4_address_routing_state).value) + 0xC) + (arg0 * 0x1C));
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
s16 *TLobby::get_active_entry_by_index(s16 arg0) {
    s16 *temp_r3;
    if ((arg0 < 0) || (arg0 >= (s16) *(s16 *)((s8 *)(&(*(RecoveredGlobal_8040FE9C_lbl_805C1B60 *)&ipv4_address_routing_state).value) + 2))) {
        return NULL;
    }
    temp_r3 = (s16 *)(*(s32 *)((s8 *)(&(*(RecoveredGlobal_8040FE9C_lbl_805C1B60 *)&ipv4_address_routing_state).value) + 0xC) + (arg0 * 0x1C));
    if ((s16) *temp_r3 != 1) {
        return NULL;
    }
    return temp_r3;
}
#pragma pop

s16 TLobby__sub_8040FEE4(s32 arg0, s32 arg1) {
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

typedef char RecoveredGlobal_8041123C_lbl_805C1BB8_size[sizeof(RecoveredGlobal_8041123C_lbl_805C1BB8) == 0x28 ? 1 : -1];

typedef char RecoveredGlobal_804112B8_lbl_805C1BB8_size[sizeof(RecoveredGlobal_804112B8_lbl_805C1BB8) == 0x28 ? 1 : -1];

typedef char RecoveredGlobal_80411ECC_lbl_805C1BB8_size[sizeof(RecoveredGlobal_80411ECC_lbl_805C1BB8) == 0x28 ? 1 : -1];

typedef char RecoveredGlobal_8040FF0C_lbl_805C1B78_size[sizeof(RecoveredGlobal_8040FF0C_lbl_805C1B78) == 0x40 ? 1 : -1];
s32 NetIPv6Shutdown(void) {
    TLobby::release_slot_by_id(0x86DD);
    TLobby__sub_803F87DC((void *)((void *) (&ipv6_protocol_state.value)));
    ipv6_protocol_state.value = 0;
    return 0;
}

void TLobby__sub_8040FFF8(void);
s32 NetIPv6Init(void) {
    s16 i;
    E_8040FF58 *e;
    RecoveredGlobal_8040FF0C_lbl_805C1B78 *g = &ipv6_protocol_state;

    ((TLobby *)((Obj_803F87E0 *)&g->value))->init_ipv6_interface_config();
    e = g->ents;
    for (i = 0; i < g->value; i++) {
        e->c0 = 0x49;
        e->c1 = 0x50;
        e->c2 = 0x36;
        e->c3 = i;
        e->f4 = 0;
        e++;
    }
    g->f8 = 1;
    register_protocol_handler__6TLobbyFUsi(0x86DD, (Handler_8041A130)TLobby__sub_8040FFF8);
    return 0;
}

s16 TLobby__sub_8040D510(Icmp6ErrorInfo *err, u8 *hdr, s16 len, s16 idx);

s16 TLobby__sub_80410958(u8 *opt, s16 len, u8 *hdr, s16 pktlen, s16 idx) {
    s16 NetIPv6IsMulticast(u8 *arg0);
    Icmp6ErrorInfo err;
    s32 optlen;

    while (len > 0) {
        switch (opt[0]) {
        case 0:
            len -= 1;
            opt += 1;
            continue;
        case 1:
            optlen = opt[1] + 2;
            len -= optlen;
            opt += optlen;
            continue;
        }
        switch (opt[0] & 0xC0) {
        case 0x00:
            optlen = opt[1] + 2;
            len -= optlen;
            opt += optlen;
            continue;
        case 0xC0:
            if (NetIPv6IsMulticast(hdr + 0x18)) {
                return -1;
            }
        case 0x80:
            err.type = 4;
            err.code = 2;
            err.pointer = opt - hdr;
            TLobby__sub_8040D510(&err, hdr, pktlen, idx);
        case 0x40:
        default:
            return -1;
        }
    }
    if (len != 0) {
        return -1;
    }
    return 0;
}

struct Ipv6SendOptions {
    u8 traffic_class;
    u8 pad1[3];
    u32 flow_label;
    u8 hop_limit;
    u8 pad9[3];
};
struct Ipv6Route {
    u8 pad0[2];
    s16 type;
    u8 pad4[2];
    s16 iface;
    u8 pad8[0x10];
    u8 gateway[16];
};

s32 TLobby__sub_80410A98(NetPacket *pkt, u8 *dst, u8 *src, Ipv6SendOptions *opts, s32 next_header) {
    s32 TLobby__sub_80410BA8(void *, void *, s32, void *);
    s32 TLobby__sub_80415D0C(NetPacket *, u8 *, NetIPv6SendParameters *, s32);
    s16 NetIPv6IsMulticast(u8 *arg0);
    s16 TLobby__sub_804136AC(s16 arg0);
    u8 *nexthop;
    Ipv6Route *rt;
    u8 *gateway;
    Ipv6SendOptions defaults;
    NetIPv6SendParameters params;

    rt = (Ipv6Route *)TLobby__sub_80413264(dst, (s32)src);
    if (rt == NULL) {
        return -6;
    }
    if (rt->type == 1) {
        gateway = dst;
    } else {
        gateway = rt->gateway;
    }
    if (opts == NULL) {
        NetMemset(&defaults, 0, sizeof(defaults));
        opts = &defaults;
    }
    nexthop = gateway;
    params.flow_label = opts->flow_label;
    params.traffic_class_bits = opts->traffic_class;
    params.hop_limit = opts->hop_limit;
    params.next_header = next_header;
    NetMemcpy(&params.source, src, sizeof(params.source));
    NetMemcpy(&params.destination, dst, sizeof(params.destination));
    if (!NetIPv6IsMulticast(nexthop) && TLobby__sub_804136AC(rt->iface)) {
        return TLobby__sub_80415D0C(pkt, nexthop, &params, rt->iface);
    }
    return TLobby__sub_80410BA8(pkt, &params, rt->iface, NULL);
}

struct Ipv6FragmentHeader {
    u8 next_header;
    u8 reserved;
    u16 offset_flags;
    u32 ident;
};

#pragma push
#pragma opt_common_subs on

s16 TLobby__sub_80411C44(IPv6Address *addr, s16 idx);
s16 TLobby__sub_80410D6C(NetPacket *pkt, Ipv6Header *hdr, s16 iface, void *opts, u32 room);

#pragma push
#pragma dont_inline off
#pragma inline_depth(4)
inline s16 get_mtu_80410BA8(IPv6Address *dst, s16 iface) {
    return TLobby__sub_80411C44(dst, iface);
}

s16 TLobby__sub_80410BA8(NetPacket *pkt, NetIPv6SendParameters *params, s16 iface, void *opts) {
    s16 NetIPv6IsMulticast(u8 *arg0);
    s16 TLobby__sub_804112B8(s32 packet, s32 dst, s16 iface);
    s16 TLobby__sub_8041123C(s32 packet, s32 opts, s16 iface);
    RecoveredGlobal_8040FF0C_lbl_805C1B78 *g;
    u32 len;
    Ipv6Header *hdr;
    s16 mtu;
    u32 room;

    len = pkt->total_bytes;
    g = &ipv6_protocol_state;
    hdr = &g->hdr;
    if (len == 0) {
        return 0;
    }
    hdr->vtf.word = 0;
    if (params->flow_label != 0) {
        hdr->vtf.word = params->flow_label & 0xFFFFF;
    } else {
        hdr->vtf.word = g->flow_label;
    }
    if (params->traffic_class_bits != 0) {
        hdr->vtf.half |= params->traffic_class_bits & 0xFF0;
    } else {
        hdr->vtf.half |= g->traffic_class;
    }
    hdr->vtf.version = 0x60;
    hdr->payload_length = len;
    hdr->next_header = params->next_header;
    if (params->hop_limit != 0) {
        hdr->hop_limit = params->hop_limit;
    } else {
        hdr->hop_limit = g->f14;
    }
    NetMemcpy(&hdr->src, &params->source, sizeof(hdr->src));
    NetMemcpy(&hdr->dst, &params->destination, sizeof(hdr->dst));
    mtu = get_mtu_80410BA8(&params->destination, iface);
    if (mtu < 0) {
        return mtu;
    }
    room = mtu - sizeof(Ipv6Header);
    g->f8++;
    if (len > room) {
        return TLobby__sub_80410D6C(pkt, hdr, iface, opts, room);
    }
    pkt->total_bytes += sizeof(Ipv6Header);
    pkt->fragments[pkt->fragment_count].length = sizeof(Ipv6Header);
    ((TLobby *)&pkt->fragments[pkt->fragment_count].buffer)->set_value_and_enable((s32)hdr);
    pkt->fragment_count++;
    if (NetIPv6IsMulticast((u8 *)&params->destination)) {
        return TLobby__sub_804112B8((s32)pkt, (s32)&params->destination, iface);
    }
    return TLobby__sub_8041123C((s32)pkt, (s32)opts, iface);
}
#pragma pop

s16 TLobby__sub_80410D6C(NetPacket *pkt, Ipv6Header *hdr, s16 iface, void *opts, u32 room) {
    s16 NetIPv6IsMulticast(u8 *addr);
    s16 TLobby__sub_804112B8(s32 packet, s32 dst, s16 iface);
    s16 TLobby__sub_8041123C(s32 packet, s32 opts, s16 iface);
    NetPacket out;
    Ipv6FragmentHeader fh;
    s16 j;
    s16 i;
    s32 flen;
    s32 offset;
    s16 left;
    NetPacket *frag;
    u32 chunk;
    s16 n;
    s16 ret;
    NetPacketFragment *f;

    if (room < sizeof(fh)) {
        return -6;
    }
    fh.next_header = hdr->next_header;
    fh.reserved = 0;
    chunk = room - sizeof(fh);
    chunk &= 0xFFF8;
    fh.offset_flags = 0;
    offset = 0;
    fh.ident = ipv6_protocol_state.f8;
    hdr->next_header = 44;
    while (pkt->total_bytes != 0) {
        out.total_bytes = 0;
        out.fragment_count = 0;
        for (n = pkt->fragment_count - 1; n >= 0; n--) {
            if (out.total_bytes + (flen = pkt->fragments[n].length) < chunk) {
                out.total_bytes += pkt->fragments[n].length;
                out.fragment_count++;
            } else {
                out.total_bytes = chunk;
                out.fragment_count++;
                break;
            }
        }
        j = out.fragment_count - 1;
        frag = &out;
        i = pkt->fragment_count - 1;
        left = out.total_bytes;
        while (j >= 0 && left > 0) {
            NetMemcpy(&out.fragments[j].buffer, &pkt->fragments[i].buffer, sizeof(NetBufferRef));
            if (left < pkt->fragments[i].length) {
                out.fragments[j].length = left;
                pkt->total_bytes -= left;
                f = (NetPacketFragment *)((u8 *)pkt + i * sizeof(NetPacketFragment));
                f[1].length -= left;
                TLobby__sub_80406EB8(&f[1].buffer, left);
                break;
            }
            out.fragments[j].length = pkt->fragments[i].length;
            left -= pkt->fragments[i].length;
            pkt->total_bytes -= pkt->fragments[i].length;
            pkt->fragments[i].length = 0;
            pkt->fragment_count--;
            j--;
            i--;
        }
        fh.offset_flags = offset & 0xFFF8;
        if (pkt->total_bytes != 0) {
            fh.offset_flags |= 1;
        }
        offset += (s16)out.total_bytes;
        out.total_bytes += sizeof(fh);
        out.fragments[out.fragment_count].length = sizeof(fh);
        ((TLobby *)&out.fragments[out.fragment_count].buffer)->set_value_and_enable((s32)&fh);
        out.fragment_count++;
        hdr->payload_length = out.total_bytes;
        out.total_bytes += sizeof(Ipv6Header);
        out.fragments[out.fragment_count].length = sizeof(Ipv6Header);
        ((TLobby *)&out.fragments[out.fragment_count].buffer)->set_value_and_enable((s32)hdr);
        out.fragment_count++;
        if (NetIPv6IsMulticast(hdr->dst.bytes)) {
            ret = TLobby__sub_804112B8((s32)frag, (s32)&hdr->dst, iface);
        } else {
            ret = TLobby__sub_8041123C((s32)frag, (s32)opts, iface);
        }
        if (ret < 0) {
            break;
        }
    }
    return ret;
}

#pragma pop

struct PH_80411040 { IPv6Address src; IPv6Address dst; u32 len; u8 zero[3]; u8 next_header; };

u16 TLobby__sub_80411040(const IPv6Address *src, const IPv6Address *dst, u8 next_header, const NetPacket *pkt, s16 flag) {
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
    sum += TLobby__sub_80406BD8((void *)pkt, flag);
    sum = (sum >> 16) + (sum & 0xFFFF);
    sum += sum >> 16;
    return ~sum;
}

#pragma push
#pragma opt_common_subs on
void TLobby__sub_80411334(void);
s32 TLobby__sub_8041112C(void) {
    RecoveredGlobal_8041123C_lbl_805C1BB8 *g = &ipv6_address_routing_state;
    NetUnregisterTimer((void *)TLobby__sub_80411334);
    NetUnregisterTimer((void *)TLobby::tick_entry_timers);
    TLobby__sub_803F8864(g);
    g->ab.a = 0;
    g->ab.b = 0;
    g->c = 0;
    return 0;
}

struct G_8041118C {
    s16 n0; s16 n1; s16 n2; u8 pad6[0xE]; s16 n14; u8 pad16[2];
    void *p18; void *p1C; void *p20; void *p24;
};

#define g ((G_8041118C *)&ipv6_address_routing_state)
s32 TUdpSocket__sub_8041118C(void) {
    ((TLobby *)g)->init_udp_socket_config();
    NetMemset(g->p18, 0, g->n0 * 0x2A);
    NetMemset(g->p1C, 0, g->n1 * 0x2A);
    NetMemset(g->p20, 0, g->n2 * 0x2C);
    NetMemset(g->p24, 0, g->n14 * 0x16);
    NetRegisterTimer(0x3E8, (s16)(1), (NetTimerCallback)(TLobby__sub_80411334));
    NetRegisterTimer(0x3E8, (s16)(1), (NetTimerCallback)(TLobby::tick_entry_timers));
    return 0;
}
#undef g

s32 TLobby__sub_8041123C(s32 arg0, s32 arg1, s16 arg2) {
    struct Fields_temp_r3 { s16 field_0; s16 field_2; };
    u8 *temp_r3;
    if ((arg2 < 0) || (arg2 >= (s16) *(s16 *)((s8 *)(&ipv6_address_routing_state.value) + 2))) {
        return -0x10A;
    }
    temp_r3 = (u8 *)(*(s32 *)((s8 *)(&ipv6_address_routing_state.value) + 0x1C) + (arg2 * 0x30));
    if ((s16) ((Fields_temp_r3*)temp_r3)->field_0 != 1) {
        return -6;
    }
    return TLobby::call_handler_by_index(arg2, (s32)((s32) ((Fields_temp_r3*)temp_r3)->field_2), 0, arg1, arg0);
}
#pragma pop

#pragma push
#pragma opt_common_subs on
s32 TLobby__sub_804112B8(s32 arg0, s32 arg1, s16 arg2) {
    struct Fields_temp_r3 { s16 field_0; s16 field_2; };
    u8 *temp_r3;
    if ((arg2 < 0) || (arg2 >= (s16) *(s16 *)((s8 *)(&(*(RecoveredGlobal_804112B8_lbl_805C1BB8 *)&ipv6_address_routing_state).value) + 2))) {
        return -0x10A;
    }
    temp_r3 = (u8 *)(*(s32 *)((s8 *)(&(*(RecoveredGlobal_804112B8_lbl_805C1BB8 *)&ipv6_address_routing_state).value) + 0x1C) + (arg2 * 0x30));
    if ((s16) ((Fields_temp_r3*)temp_r3)->field_0 != 1) {
        return -6;
    }
    return TLobby::call_handler_by_index(arg2, (s32)((s32) ((Fields_temp_r3*)temp_r3)->field_2), 2, arg1, arg0);
}
#pragma pop

struct Ipv6NdAddr {
    s16 in_use;
    u8 addr[16];
    s16 prefix_len;
    s16 state;
    s16 f16;
    s16 f18;
    s16 scope;
    s16 dad_count;
    s16 dad_timer;
    u32 valid_lifetime;
    u32 preferred_lifetime;
    Ipv6NdAddr *next;
};
struct Ipv6NdIface {
    s16 state;
    s16 f2;
    u8 addr[16];
    s16 prefix_len;
    s16 dad_state;
    s16 f18;
    s16 f1A;
    s16 scope;
    s16 dad_count;
    s16 dad_timer;
    s16 rs_count;
    s16 rs_timer;
    s16 mtu;
    void *f28;
    Ipv6NdAddr *addrs;
};
struct Ipv6NdRoute;
struct Ipv6NdState {
    s16 route_count;
    s16 count;
    s16 max_addrs;
    s16 dad_timer_init;
    s16 dad_count_init;
    s16 dad_interval;
    s16 rs_timer_init;
    s16 rs_count_init;
    s16 rs_interval;
    s16 min_mtu;
    u8 pad14[4];
    Ipv6NdRoute *routes;
    Ipv6NdIface *ifaces;
    Ipv6NdAddr *addr_pool;
};
struct Ipv6NdEvent {
    u8 *addr;
    s16 prefix_len;
};
void TLobby__sub_80411334(void) {
    s32 NetIPv6SendUnspecifiedSourceNeighborSolicitation(u8 *, s16);
    s32 NetIPv6SendRouterSolicitation(s16);
    s32 TLobby__sub_80411604(s16, int, void *);
    Ipv6NdState *g = (Ipv6NdState *)&ipv6_address_routing_state;
    s16 i;
    s16 j;
    Ipv6NdIface *ifc;
    Ipv6NdAddr *a;
    Ipv6NdEvent ev;

    ifc = g->ifaces;
    for (i = 0; i < g->count; i++, ifc++) {
        if (ifc->state != 1 || i == 0) {
            continue;
        }
        switch (ifc->dad_state) {
        case 1:
            if (ifc->dad_count > 0) {
                if (ifc->dad_timer > 0) {
                    ifc->dad_timer--;
                } else {
                    NetIPv6SendUnspecifiedSourceNeighborSolicitation(ifc->addr, i);
                    ifc->dad_count--;
                    ifc->dad_timer = g->dad_interval;
                }
            } else {
                if (ifc->f18 == 0) {
                    ifc->dad_state = 4;
                } else {
                    ifc->dad_state = 3;
                }
                ev.addr = ifc->addr;
                ev.prefix_len = ifc->prefix_len;
                TLobby__sub_80411604(i, 0, &ev);
            }
            break;
        }
        if (ifc->rs_count > 0 && ifc->dad_state != 0) {
            if (ifc->rs_timer > 0) {
                ifc->rs_timer--;
            } else {
                NetIPv6SendRouterSolicitation(i);
                ifc->rs_count--;
                ifc->rs_timer = g->rs_interval;
            }
        }
        a = ifc->addrs;
        for (j = 0; a != NULL && j < g->max_addrs; j++) {
            switch (a->state) {
            case 0:
                break;
            case 1:
                if (a->dad_count > 0) {
                    if (a->dad_timer > 0) {
                        a->dad_timer--;
                    } else {
                        NetIPv6SendUnspecifiedSourceNeighborSolicitation(a->addr, i);
                        a->dad_count--;
                        a->dad_timer = g->dad_interval;
                    }
                } else {
                    if (a->f16 == 0) {
                        a->state = 4;
                    } else {
                        a->state = 3;
                    }
                    ev.addr = a->addr;
                    ev.prefix_len = a->prefix_len;
                    TLobby__sub_80411604(i, 0, &ev);
                }
                break;
            case 3:
                if (a->preferred_lifetime != 0xFFFFFFFF && a->preferred_lifetime != 0) {
                    a->preferred_lifetime--;
                    if (a->preferred_lifetime == 0) {
                        a->state = 2;
                    }
                }
                if (a->valid_lifetime != 0xFFFFFFFF && a->valid_lifetime != 0) {
                    a->valid_lifetime--;
                    if (a->valid_lifetime == 0) {
                        a->state = 0;
                    }
                }
                break;
            case 2:
                if (a->valid_lifetime != 0xFFFFFFFF && a->valid_lifetime != 0) {
                    a->valid_lifetime--;
                    if (a->valid_lifetime == 0) {
                        a->state = 0;
                    }
                }
                break;
            case 4:
                break;
            }
            a = a->next;
        }
    }
}

struct Ipv6NdRoute {
    s16 state;
    s16 type;
    u8 pad4[2];
    s16 iface;
    u8 prefix[16];
    u8 gateway[16];
    s16 prefix_len;
};
struct Ipv6NdRouteEvent {
    u8 *addr;
    u8 *router;
};
struct Ipv6NdByteEvent {
    u8 pad0[4];
    u8 value;
};
struct Ipv6NdValueEvent {
    u8 *addr;
    s32 value;
};
struct Ipv6NdPrefixEvent {
    u8 *prefix;
    s16 prefix_len;
    u8 *gateway;
    u8 *router;
};

s32 TLobby__sub_8042325C(s32 a, s32 b, s32 c, s32 (*fn)(s32, s32, s32));
// Prefix information handed to 80412618 (lifetimes per RFC 4862: valid is clamped to 7200 s).
struct Ipv6NdPrefixInfo {
    u8 *prefix;
    s16 prefix_len;
    u32 preferred_lifetime;
    u32 valid_lifetime;
};

s16 TLobby__sub_80412618(Ipv6NdPrefixInfo *info, s16 idx);
s16 TLobby__sub_8041347C(u8 *prefix, s16 bits, u8 *addr, s16 idx, s16 kind, s16 mode);
void TLobby__sub_80414B98(u8 *, s16, u8 *);

#pragma push
#pragma dont_inline off
inline s16 compare_addr_80411604(u8 *a, u8 *b) {
    s32 r = NetMemcmp(a, b, 16);

    if (r < 0) {
        return -1;
    } else if (r > 0) {
        return 1;
    }
    return 0;
}

inline void remove_route_80411604(Ipv6NdState *g, u8 *prefix, s16 len, u8 *gateway) {
    u8 masked[16];
    s16 n;
    Ipv6NdRoute *rt;

    TLobby__sub_80414B98(masked, len, prefix);
    n = g->route_count;
    rt = g->routes;
    for (; n > 0; n--, rt++) {
        if (rt->state == 1 && rt->prefix_len == len) {
            if (compare_addr_80411604(rt->prefix, masked) == 0 && compare_addr_80411604(rt->gateway, gateway) == 0) {
                rt->state = 0;
                return;
            }
        }
    }
}

s32 TLobby__sub_80411604(s16 idx, int kind, void *arg) {
    Ipv6NdState *g = (Ipv6NdState *)&ipv6_address_routing_state;
    Ipv6NdIface *ifc;
    s16 ok;
    s16 i;
    Ipv6NdRoute *rt;
    u8 unspec[16];

    if (idx < 0 || idx >= g->count) {
        return -0x10A;
    }
    ifc = g->ifaces;
    ifc += idx;
    if (ifc->state != 1) {
        return -2;
    }
    ok = 1;
    if (ifc->f28 != NULL) {
        ok = TLobby__sub_8042325C(idx, kind, (s32)arg, (s32 (*)(s32, s32, s32))ifc->f28);
    }
    switch (kind) {
    case 0: {
        Ipv6NdEvent *ev = (Ipv6NdEvent *)arg;
        rt = g->routes;
        for (i = 0; i < g->route_count; i++, rt++) {
            if (rt->state == 1 && rt->type == 0) {
                if (rt->prefix_len == ev->prefix_len) {
                    if (compare_addr_80411604(rt->gateway, ev->addr) == 0) {
                        rt->type = 1;
                    }
                } else if (rt->prefix_len == 128) {
                    if (compare_addr_80411604(rt->prefix, ev->addr) == 0) {
                        rt->type = 1;
                    }
                }
            }
        }
        break;
    }
    case 1:
        if (ifc->dad_timer > 0) {
            ifc->dad_timer = 0;
        }
        break;
    case 2:
        if (ok == 1) {
            TLobby__sub_80412618((Ipv6NdPrefixInfo *)arg, idx);
        }
        break;
    case 3:
        ipv6_protocol_state.f14 = ((Ipv6NdByteEvent *)arg)->value;
        break;
    case 4:
        ifc->mtu = ((Ipv6NdValueEvent *)arg)->value;
        break;
    case 5:
        if (ok == 1) {
            NetMemset(unspec, 0, 16);
            TLobby__sub_8041347C(unspec, 0, ((Ipv6NdRouteEvent *)arg)->addr, idx, 2, 4);
        }
        break;
    case 6:
        if (ok == 1) {
            NetMemset(unspec, 0, 16);
            remove_route_80411604(g, unspec, 0, ((Ipv6NdRouteEvent *)arg)->addr);
        }
        break;
    case 7:
        if (ok == 1) {
            NetMemset(unspec, 0, 16);
            remove_route_80411604(g, unspec, 0, ((Ipv6NdRouteEvent *)arg)->addr);
            TLobby__sub_8041347C(unspec, 0, ((Ipv6NdRouteEvent *)arg)->router, idx, 2, 4);
        }
        break;
    case 8:
        break;
    case 9:
        if (ok == 1) {
            NetMemset(unspec, 0, 16);
            remove_route_80411604(g, unspec, 0, ((Ipv6NdRouteEvent *)arg)->addr);
        }
        break;
    case 10:
        if (ok == 1) {
            Ipv6NdPrefixEvent *ev = (Ipv6NdPrefixEvent *)arg;
            remove_route_80411604(g, ev->prefix, ev->prefix_len, ev->gateway);
            TLobby__sub_8041347C(ev->prefix, 0x80, ev->router, idx, 3, 4);
        }
        break;
    case 11:
    case 12:
        break;
    }
    return 0;
}
#pragma pop

#pragma push
#pragma opt_common_subs on
struct Ent_80411BE8 { s16 f0; u8 pad[0x12]; s16 f14; };
struct G_80411BE8 { u8 pad[0x14]; s16 n; u8 pad2[0xE]; Ent_80411BE8 *p; };

void TLobby::tick_entry_timers() {
    G_80411BE8 *G = (G_80411BE8 *)&ipv6_address_routing_state;
    s16 i;
    Ent_80411BE8 *e = G->p;
    for (i = 0; i < G->n; i++, e++) {
        if (e->f0 == 1) {
            if (e->f14 > 0) {
                e->f14--;
            } else {
                e->f0 = 0;
            }
        }
    }
}

struct Ent_80411DEC { s16 state; IPv6Address addr; s16 mtu; s16 timer; };
struct Iface_80411C44 { u8 pad0[0x26]; s16 mtu; u8 pad28[8]; };
struct G_80411DEC { u8 pad0[0x14]; s16 count; s16 lifetime; u8 pad18[4]; Iface_80411C44 *ifaces; u8 pad20[4]; Ent_80411DEC *ents; };

#pragma push
#pragma dont_inline off
inline s16 is_link_local_80411C44(const IPv6Address *a) {
    u8 b;

    if (a->bytes[0] != 0xFE) {
        return 0;
    }
    b = a->bytes[1];
    if (!(b & 0x80) || (b & 0x40)) {
        return 0;
    }
    return 1;
}

inline s16 compare_addr_80411C44(const IPv6Address *a, const IPv6Address *b) {
    s32 r = NetMemcmp(a, b, sizeof(IPv6Address));

    if (r < 0) {
        return -1;
    } else if (r > 0) {
        return 1;
    }
    return 0;
}

inline Iface_80411C44 *iface_80411C44(G_80411DEC *g, s16 idx) {
    return &g->ifaces[idx];
}

s16 TLobby__sub_80411C44(IPv6Address *addr, s16 idx) {
    G_80411DEC *g = (G_80411DEC *)&ipv6_address_routing_state;
    Iface_80411C44 *ifc = iface_80411C44(g, idx);
    Ent_80411DEC *slot = NULL;
    s16 i;
    Ent_80411DEC *e;
    Ent_80411DEC *oldest = NULL;

    if (is_link_local_80411C44(addr)) {
        return ifc->mtu;
    }
    e = g->ents;
    for (i = 0; i < g->count; i++, e++) {
        if (e->state != 1) {
            if (slot == NULL) {
                slot = e;
            }
        } else {
            if (compare_addr_80411C44(&e->addr, addr) == 0) {
                if (e->mtu > ifc->mtu) {
                    if (ifc->mtu < 40) {
                        return -6;
                    }
                    e->mtu = ifc->mtu;
                }
                e->timer = g->lifetime;
                return e->mtu;
            }
            if (oldest == NULL) {
                oldest = e;
            } else if (e->timer < oldest->timer) {
                oldest = e;
            }
        }
    }
    if (slot == NULL) {
        slot = oldest;
    }
    if (ifc->mtu < 40) {
        return -6;
    }
    slot->state = 1;
    slot->timer = g->lifetime;
    NetMemcpy(&slot->addr, addr, sizeof(IPv6Address));
    slot->mtu = ifc->mtu;
    return slot->mtu;
}
#pragma pop

s32 TLobby__sub_80411DEC(IPv6Address *addr, s16 mtu) {
    G_80411DEC *g = (G_80411DEC *)&ipv6_address_routing_state;
    s16 i;
    Ent_80411DEC *e;

    if (mtu < 40) {
        return -1;
    }
    e = g->ents;
    for (i = 0; i < g->count; i++, e++) {
        if (e->state == 1) {
            s32 r = NetMemcmp(&e->addr, addr, sizeof(IPv6Address));
            s16 c;
            if (r < 0) {
                c = -1;
            } else if (r > 0) {
                c = 1;
            } else {
                c = 0;
            }
            if (c == 0) {
                if (mtu >= 1280 && mtu < e->mtu) {
                    e->mtu = mtu;
                }
                e->timer = g->lifetime;
                return 0;
            }
        }
    }
    return -1;
}

s16 TLobby::get_entry_field_26(s16 arg0) {
    struct Fields_temp_r3 { s16 field_0; u8 pad_2[36]; s16 field_26; };
    u8 *temp_r3;
    if ((arg0 < 0) || (arg0 >= (s16) *(s16 *)((s8 *)(&(*(RecoveredGlobal_80411ECC_lbl_805C1BB8 *)&ipv6_address_routing_state).value) + 2))) {
        return -0x10A;
    }
    temp_r3 = (u8 *)(*(s32 *)((s8 *)(&(*(RecoveredGlobal_80411ECC_lbl_805C1BB8 *)&ipv6_address_routing_state).value) + 0x1C) + (arg0 * 0x30));
    if ((s16) ((Fields_temp_r3*)temp_r3)->field_0 != 1) {
        return -2;
    }
    return ((Fields_temp_r3*)temp_r3)->field_26;
}
#pragma pop

s16 TLobby__sub_80414218(u8 *, u8 *);

struct Ipv6AddrNode {
    s16 f0;
    u8 addr[16];
    s16 f12;
    s16 f14;
    s16 f16;
    s16 f18;
    s16 scope;
    u8 pad1C[0xC];
    Ipv6AddrNode *next;
};
struct Ipv6Iface {
    s16 state;
    s16 f2;
    u8 addr[16];
    s16 f14;
    s16 f16;
    s16 f18;
    s16 f1A;
    s16 scope;
    u8 pad1E[0xA];
    s32 f28;
    Ipv6AddrNode *nodes;
};
struct Ipv6AddressState {
    s16 f0;
    s16 count;
    s16 max_nodes;
    u8 pad6[0x16];
    Ipv6Iface *ifaces;
};

s32 TLobby__sub_80411F1C(u8 *out, u8 *dst, s16 idx) {
    Ipv6AddressState *g = (Ipv6AddressState *)&ipv6_address_routing_state;
    u8 *sel = NULL;
    s16 best = 0;
    s16 scope;
    Ipv6Iface *ifc;
    s16 n;
    Ipv6AddrNode *node;
    s16 score;
    s16 NetIPv6GetAddressScopeClass(u8 *);

    if (idx < 0 || idx >= g->count) {
        return -6;
    }
    ifc = g->ifaces + idx;
    scope = NetIPv6GetAddressScopeClass(dst);
    if (ifc->state == 1) {
        if (ifc->scope == scope) {
            score = TLobby__sub_80414218(ifc->addr, dst);
            if (score > 0) {
                best = score;
                sel = ifc->addr;
            }
        } else {
            best = 0;
            sel = ifc->addr;
        }
        node = ifc->nodes;
        for (n = 0; node != NULL && n < g->max_nodes; n++) {
            if (node->scope == scope) {
                score = TLobby__sub_80414218(node->addr, dst);
                if (score > best) {
                    best = score;
                    sel = node->addr;
                }
            }
            node = node->next;
        }
    }
    if (sel == NULL) {
        return -6;
    }
    NetMemcpy(out, sel, 16);
    return 0;
}

struct Ipv6IfaceAddrRecord {
    s32 kind;
    u8 addr[16];
    s16 f14;
    s16 f16;
    s32 f18;
};

#pragma push
#pragma opt_common_subs on
s32 TLobby__sub_80412058(s16 idx, NetBufferRef *out, s16 len, s32 arg3) {
    s16 TLobby__sub_80409EB0(s16 arg0, s32 arg1);
    Ipv6AddressState *g = (Ipv6AddressState *)&ipv6_address_routing_state;
    s16 n;
    s32 count;
    Ipv6IfaceAddrRecord rec;
    Ipv6Iface *ifc;
    NetBufferRef ref;
    Ipv6AddrNode *node;

    if (idx < 0 || idx >= g->count) {
        return -0x10A;
    }
    ifc = g->ifaces;
    ifc += idx;
    if (ifc->state != 1) {
        return -2;
    }
    if (len < sizeof(rec)) {
        return -2;
    }
    rec.kind = 6;
    NetMemcpy(rec.addr, ifc->addr, sizeof(rec.addr));
    rec.f14 = ifc->f14;
    rec.f16 = ifc->f1A;
    rec.f18 = ifc->f28;
    ((TLobby *)&ref)->set_value_and_enable((s32)&rec);
    TLobby__sub_80406FD8(out, &ref, sizeof(rec));
    TLobby__sub_80406EB8(out, sizeof(rec));
    node = ifc->nodes;
    count = 1;
    n = 0;
    len -= sizeof(rec);
    while (len >= sizeof(rec) && node != NULL && n < g->max_nodes) {
        rec.kind = 6;
        NetMemcpy(rec.addr, node->addr, sizeof(rec.addr));
        rec.f14 = node->f12;
        rec.f16 = node->f18;
        rec.f18 = 0;
        ((TLobby *)&ref)->set_value_and_enable((s32)&rec);
        TLobby__sub_80406FD8(out, &ref, sizeof(rec));
        TLobby__sub_80406EB8(out, sizeof(rec));
        node = node->next;
        count++;
        n++;
        len -= sizeof(rec);
    }
    if (TLobby__sub_80409EB0(idx, ifc->f2) <= 6) {
        TLobby__sub_80409E18(idx, ifc->f2, arg3);
    }
    return count;
}
#pragma pop

struct Ent_80412210 {
    s16 f0;
    s16 f2;
    s16 f4;
    s16 f6;
    u8 f8[16];
    u8 f18[16];
    s16 f28;
};
struct Grp_80412210 {
    s16 f0;
    u8 f2[16];
    s16 f12;
    u8 p14[0x14];
    Grp_80412210 *f28;
};
struct If_80412210 {
    s16 f0;
    s16 f2;
    u8 f4[16];
    s16 f14;
    u8 p16[0x10];
    s16 f26;
    s32 f28;
    Grp_80412210 *f2c;
};
struct G_80412210 {
    s16 f0;
    s16 f2;
    s16 f4;
    u8 p6[0x12];
    Ent_80412210 *table;
    If_80412210 *ifs;
};

void TLobby__sub_80414B98(u8 *, s16, u8 *);

#define G ((G_80412210 *)&ipv6_address_routing_state)

#pragma push
#pragma dont_inline off
#pragma inline_depth(4)
inline s16 cmp_80412210(void *a, void *b) {
    s32 r = NetMemcmp(a, b, 16);
    if (r < 0) {
        return -1;
    }
    if (r > 0) {
        return 1;
    }
    return 0;
}

inline s16 getaddr_80412210(s16 *n, If_80412210 **ifs, void *out) {
    if (*n <= 0) {
        return 0;
    }
    if ((*ifs)->f0 != 1) {
        return 0;
    }
    NetMemcpy(out, (*ifs)->f4, 16);
    return 1;
}

inline void remove_80412210(G_80412210 *g, void *grp, void *src) {
    s16 n = g->f0;
    Ent_80412210 *e = g->table;
    for (; n > 0; n--, e++) {
        if (e->f0 == 1 && e->f28 == 0x80 && cmp_80412210(e->f8, grp) == 0 && cmp_80412210(e->f18, src) == 0) {
            e->f0 = 0;
            return;
        }
    }
}

s16 TLobby__sub_80412210(s16 idx) {
    G_80412210 *g = G;
    u8 d[16];
    u8 c[16];
    u8 b[16];
    u8 a[16];
    s16 *pn;
    If_80412210 **pifs;
    s16 count;
    If_80412210 *ifc;
    Grp_80412210 *grp;

    if (idx < 0 || idx >= *(pn = &g->f2)) {
        return -0x10A;
    }
    ifc = *(pifs = &g->ifs);
    ifc += idx;
    if (ifc->f0 != 1) {
        return 0;
    }
    grp = ifc->f2c;
    count = 0;
    while (grp != NULL && count < g->f4) {
        Grp_80412210 *next;
        if (TLobby::is_socket_flag_set(idx) == 0 && getaddr_80412210(pn, pifs, d)) {
            TLobby__sub_80414B98(b, 0x80, grp->f2);
            remove_80412210(g, b, d);
        }
        TLobby__sub_80409D7C(idx, ifc->f2, 2, (s32)grp->f2);
        NetIPv6MakeSolicitedNodeMulticastAddress(c, grp->f2);
        TLobby__sub_80409CE0(idx, ifc->f2, 2, (s32)c);
        next = grp->f28;
        grp->f0 = 0;
        NetMemset(grp->f2, 0, 16);
        grp->f12 = 0;
        count++;
        grp->f28 = NULL;
        grp = next;
    }
    if (TLobby::is_socket_flag_set(idx) == 0 && getaddr_80412210(pn, pifs, d)) {
        TLobby__sub_80414B98(a, 0x80, ifc->f4);
        remove_80412210(g, a, d);
    }
    {
        Ent_80412210 *e;
        s16 n;
        n = g->f0;
        e = g->table;
        for (; n > 0; n--, e++) {
            if (e->f0 == 1 && e->f6 == idx) {
                e->f0 = 0;
            }
        }
    }
    NetIPv6MakeSolicitedNodeMulticastAddress(c, ifc->f4);
    TLobby__sub_80409CE0(idx, ifc->f2, 2, (s32)c);
    init_ipv6_all_nodes_multicast_address(c, (s8)(2));
    TLobby__sub_80409CE0(idx, ifc->f2, 2, (s32)c);
    init_ipv6_all_nodes_multicast_address(c, (s8)(1));
    TLobby__sub_80409CE0(idx, ifc->f2, 2, (s32)c);
    TLobby::call_entry_callback(idx, ifc->f2);
    ifc->f0 = 0;
    ifc->f2 = 0;
    ifc->f26 = 0;
    NetMemset(ifc->f4, 0, 16);
    ifc->f14 = 0;
    ifc->f2c = NULL;
    ifc->f28 = 0;
    return 0;
}
#pragma pop
#undef G

#pragma push
#pragma dont_inline off
#pragma opt_common_subs on
s16 NetIPv6GetAddressScopeClass(u8 *arg0);

inline s16 get_first_iface_addr_80412618(s16 *count, Ipv6NdIface **ifaces, u8 *out) {
    if (*count <= 0) {
        return 0;
    }
    if ((*ifaces)->state != 1) {
        return 0;
    }
    NetMemcpy(out, (*ifaces)->addr, 16);
    return 1;
}

s16 TLobby__sub_80412618(Ipv6NdPrefixInfo *info, s16 idx) {
    Ipv6NdState *g = (Ipv6NdState *)&ipv6_address_routing_state;
    Ipv6NdIface *ifc;
    Ipv6NdAddr *a;
    Ipv6NdAddr *last;
    Ipv6NdRoute *rt;
    s16 ret;
    s16 i;
    s16 found;
    s16 kind;
    s16 len;
    s16 n;
    s16 rem;
    u8 *prefix;
    u8 mask;
    u8 addr[16];
    u8 router[16];
    u8 mcast[16];

    if (idx <= 0 || idx >= g->count) {
        return -0x10A;
    }
    ifc = g->ifaces;
    ifc += idx;
    if (ifc->state != 1) {
        return -2;
    }
    NetMemset(addr, 0, 8);
    ret = TLobby__sub_8040A0C0(idx, addr + 8);
    if (ret < 0) {
        return ret;
    }
    len = info->prefix_len;
    prefix = info->prefix;
    if (len > 0) {
        n = len / 8;
        NetMemcpy(addr, prefix, n);
        rem = len % 8;
        if (rem != 0) {
            mask = 0xFF >> rem;
            addr[n] = (mask & addr[n]) | (prefix[n] & ~mask);
        }
    }
    if (compare_addr_80411604(addr, ifc->addr) == 0) {
        return 0;
    }
    if (ifc->addrs != NULL) {
        found = 0;
        for (a = ifc->addrs, i = 0; a != NULL && i < g->max_addrs; i++) {
            if (a->f16 == 0) {
                if (compare_addr_80411604(addr, a->addr) == 0) {
                    found = 1;
                }
            } else if (info->prefix_len == a->prefix_len &&
                       NetCompareBitPrefix(info->prefix, a->addr, info->prefix_len) == 0) {
                found = 1;
                if (info->valid_lifetime > 7200 || info->valid_lifetime > a->valid_lifetime) {
                    a->valid_lifetime = info->valid_lifetime;
                    a->preferred_lifetime = info->preferred_lifetime;
                } else if (a->valid_lifetime > 7200 || info->valid_lifetime > a->valid_lifetime) {
                    a->valid_lifetime = 7200;
                }
            }
            a = a->next;
        }
        if (found) {
            return 0;
        }
    }
    a = g->addr_pool;
    for (i = 0; i < g->max_addrs; i++, a++) {
        if (a->in_use == 0) {
            a->in_use = 1;
            break;
        }
    }
    if (i >= g->max_addrs) {
        return -0x10A;
    }
    ret = TLobby__sub_80409D7C(idx, ifc->f2, 1, (s32)addr);
    if (ret < 0) {
        a->in_use = 0;
        return ret;
    }
    NetMemcpy(a->addr, addr, 16);
    a->prefix_len = info->prefix_len;
    a->f16 = 1;
    a->f18 = 0;
    a->scope = NetIPv6GetAddressScopeClass(addr);
    if (TLobby::is_entry_flag10_set(idx)) {
        a->state = 1;
        kind = 0;
        a->dad_count = g->dad_count_init;
        a->dad_timer = g->dad_timer_init;
    } else {
        a->state = 3;
        kind = 1;
        a->dad_count = 0;
        a->dad_timer = 0;
    }
    i = 0;
    a->valid_lifetime = info->valid_lifetime;
    a->preferred_lifetime = info->preferred_lifetime;
    a->next = NULL;
    if (ifc->addrs == NULL) {
        ifc->addrs = a;
    } else {
        for (last = ifc->addrs; i < g->max_addrs; i++) {
            if (last->next == NULL) {
                break;
            }
            last = last->next;
        }
        if (last->next == NULL) {
            last->next = a;
        }
    }
    if (get_first_iface_addr_80412618(&g->count, &g->ifaces, router) &&
        (ret = TLobby__sub_8041347C(addr, 0x80, router, 0, 3, 1)) < 0) {
        goto cleanup;
    }
    rt = (Ipv6NdRoute *)TLobby__sub_80413264(addr, (s32)addr);
    if (rt != NULL && rt->prefix_len == info->prefix_len) {
        if (rt->iface != idx) {
            goto remove_default;
        }
    } else {
        ret = TLobby__sub_8041347C(addr, info->prefix_len, addr, idx, kind, 1);
        if (ret < 0) {
            goto remove_default;
        }
    }
    NetIPv6MakeSolicitedNodeMulticastAddress(mcast, addr);
    ret = TLobby__sub_80409CE0(idx, ifc->f2, 1, (s32)mcast);
    if (ret >= 0) {
        return 0;
    }
    remove_route_80411604(g, addr, info->prefix_len, addr);
remove_default:
    if (TLobby::is_socket_flag_set(idx) == 0) {
        remove_route_80411604(g, addr, 0x80, router);
    }
cleanup:
    TLobby__sub_80409D7C(idx, ifc->f2, 2, (s32)addr);
    if (ifc->addrs == a) {
        ifc->addrs = NULL;
    } else {
        last->next = NULL;
    }
    return ret;
}
s16 TLobby__sub_80412CA4(u8 *addr_in, s16 prefix_len, s16 f1A, s16 idx, s32 callback) {
    Ipv6NdState *g = (Ipv6NdState *)&ipv6_address_routing_state;
    Ipv6NdIface *ifc;
    s16 ret;
    s16 kind;
    s16 mtu;
    s16 n;
    s16 rem;
    u8 mask;
    u8 addr[16];
    u8 router[16];
    u8 mcast[16];

    if (idx < 0 || idx >= g->count) {
        return -0x10A;
    }
    ifc = g->ifaces;
    ifc += idx;
    if (ifc->state == 1) {
        return -2;
    }
    ifc->state = 1;
    NetMemset(addr, 0, 16);
    if (NetCompareBitsBackward(&addr[15], &addr_in[15], 128 - prefix_len) != 0) {
        NetMemcpy(addr, addr_in, 16);
    } else {
        ret = TLobby__sub_8040A0C0(idx, addr + 8);
        if (ret < 0) {
            ifc->state = 0;
            return ret;
        }
        if (prefix_len > 0) {
            n = prefix_len / 8;
            NetMemcpy(addr, addr_in, n);
            rem = prefix_len % 8;
            if (rem != 0) {
                mask = 0xFF >> rem;
                addr[n] = (mask & addr[n]) | (addr_in[n] & ~mask);
            }
        }
    }
    ifc->f2 = TLobby__sub_8040A044(idx, 0x86DD, 16, addr);
    if (ifc->f2 < 0) {
        ifc->state = 0;
        return ifc->f2;
    }
    mtu = TLobby::invoke_socket_callback(idx, ifc->f2);
    if (mtu < g->min_mtu) {
        ifc->state = 0;
        return -6;
    }
    ifc->mtu = mtu;
    NetMemcpy(ifc->addr, addr, 16);
    ifc->prefix_len = prefix_len;
    ifc->f18 = 0;
    ifc->f1A = f1A;
    ifc->scope = NetIPv6GetAddressScopeClass(addr);
    if (TLobby::is_entry_flag10_set(idx)) {
        ifc->dad_state = 1;
        kind = 0;
        ifc->dad_count = g->dad_count_init;
        ifc->dad_timer = g->dad_timer_init;
    } else {
        ifc->dad_state = 4;
        kind = 1;
        ifc->dad_count = 0;
        ifc->dad_timer = 0;
    }
    if (TLobby::is_slot_flag_0x40_set(idx)) {
        ifc->rs_count = g->rs_count_init;
        ifc->rs_timer = g->rs_timer_init;
    } else {
        ifc->rs_count = 0;
        ifc->rs_timer = 0;
    }
    ifc->f28 = (void *)callback;
    ifc->addrs = NULL;
    if (TLobby::is_socket_flag_set(idx) == 0) {
        if (get_first_iface_addr_80412618(&g->count, &g->ifaces, router) &&
            (ret = TLobby__sub_8041347C(addr, 0x80, router, 0, 3, 1)) < 0) {
            goto cleanup;
        }
        ret = TLobby__sub_8041347C(addr, prefix_len, addr, idx, kind, 1);
        if (ret < 0) {
            goto remove_default;
        }
    } else {
        ret = TLobby__sub_8041347C(addr, prefix_len, addr, idx, kind, 1);
        if (ret < 0) {
            goto remove_default;
        }
    }
    init_ipv6_all_nodes_multicast_address(mcast, 1);
    ret = TLobby__sub_80409CE0(idx, ifc->f2, 1, (s32)mcast);
    if (ret >= 0) {
        init_ipv6_all_nodes_multicast_address(mcast, 2);
        ret = TLobby__sub_80409CE0(idx, ifc->f2, 1, (s32)mcast);
        if (ret >= 0) {
            NetIPv6MakeSolicitedNodeMulticastAddress(mcast, addr);
            ret = TLobby__sub_80409CE0(idx, ifc->f2, 1, (s32)mcast);
            if (ret >= 0) {
                return 0;
            }
        }
    }
    remove_route_80411604(g, addr, prefix_len, addr);
remove_default:
    if (TLobby::is_socket_flag_set(idx) == 0) {
        remove_route_80411604(g, addr, 0x80, router);
    }
cleanup:
    TLobby::call_entry_callback(idx, ifc->f2);
    ifc->state = 0;
    ifc->f2 = 0;
    ifc->mtu = 0;
    NetMemset(ifc->addr, 0, 16);
    ifc->prefix_len = 0;
    return ret;
}
#pragma pop

s32 TLobby__sub_80413230(u8 *arg0, s32 arg1) {
    if (TLobby__sub_80413264(arg0, arg1) != NULL) {
        return 1;
    }
    return 0;
}

struct Ipv6PrefixRoute {
    s16 state;
    s16 type;
    u8 pad4[2];
    s16 iface;
    u8 prefix[16];
    u8 gateway[16];
    s16 prefix_len;
};
struct Ipv6RouteTable {
    s16 count;
    u8 pad2[0x16];
    Ipv6PrefixRoute *routes;
};

#pragma push
#pragma dont_inline off
inline s16 is_multicast_80413264(const IPv6Address *a) {
    if (a->bytes[0] == 0xFF) {
        return 1;
    }
    return 0;
}

inline Ipv6PrefixRoute *routes_80413264(Ipv6RouteTable *g) {
    return g->routes;
}

u8 *TLobby__sub_80413264(void *dst, s32 src) {
    s16 NetCompareBitPrefix(u8 *a, u8 *b, s16 bits);
    s16 NetIPv6IsUnspecified(u8 *arg0);
    s16 TLobby__sub_804137FC(u8 *addr, s16 idx);
    Ipv6RouteTable *g = (Ipv6RouteTable *)&ipv6_address_routing_state;
    s16 i;
    Ipv6PrefixRoute *rt;
    Ipv6PrefixRoute *host = NULL;
    Ipv6PrefixRoute *prefix = NULL;
    Ipv6PrefixRoute *deflt = NULL;

    rt = routes_80413264(g);
    for (i = 0; i < g->count; i++, rt++) {
        if (rt->state != 1) {
            continue;
        }
        switch (rt->type) {
        case 3:
            if (NetCompareBitPrefix(rt->prefix, (u8 *)dst, rt->prefix_len) == 0) {
                return (u8 *)rt;
            }
            break;
        case 1:
            if (is_multicast_80413264((IPv6Address *)dst)) {
                if (TLobby__sub_804137FC((u8 *)src, rt->iface) != 0) {
                    host = rt;
                }
            } else if (NetCompareBitPrefix(rt->prefix, (u8 *)dst, rt->prefix_len) == 0) {
                if (is_link_local_80411C44((IPv6Address *)dst)) {
                    if (TLobby__sub_804137FC((u8 *)src, rt->iface) != 0) {
                        host = rt;
                    }
                } else if (host == NULL) {
                    host = rt;
                } else if (rt->prefix_len > host->prefix_len) {
                    host = rt;
                }
            }
            break;
        case 2:
            if (NetIPv6IsUnspecified(rt->prefix)) {
                if (deflt == NULL) {
                    deflt = rt;
                }
            } else if (NetCompareBitPrefix(rt->prefix, (u8 *)dst, rt->prefix_len) == 0) {
                if (prefix == NULL) {
                    prefix = rt;
                } else if (rt->prefix_len > prefix->prefix_len) {
                    prefix = rt;
                }
            }
            break;
        }
    }
    if (host != NULL) {
        return (u8 *)host;
    }
    if (prefix != NULL) {
        return (u8 *)prefix;
    }
    if (deflt != NULL) {
        return (u8 *)deflt;
    }
    return NULL;
}
#pragma pop

#pragma push
#pragma dont_inline off
#pragma inline_depth(4)
inline s16 is_link_local_8041347C(u8 *a) {
    if (a[0] != 0xFE) {
        return 0;
    }
    if (!(a[1] & 0x80) || (a[1] & 0x40)) {
        return 0;
    }
    return 1;
}

s16 TLobby__sub_8041347C(u8 *prefix, s16 bits, u8 *addr, s16 idx, s16 kind, s16 mode) {
    s16 len;
    G_80412210 *g = (G_80412210 *)&ipv6_address_routing_state;
    s16 i;
    Ent_80412210 *e;
    Ent_80412210 *sel;
    u8 key[16];

    if (bits < 0 || bits > 0x80) {
        return -2;
    }
    if (idx < 0 || idx >= g->f2) {
        return -2;
    }
    if (kind != 1 && kind != 2 && kind != 3 && kind != 0) {
        return -2;
    }
    if (mode != 1 && mode != 2 && mode != 3 && mode != 4) {
        return -2;
    }
    TLobby__sub_80414B98(key, bits, prefix);
    e = g->table;
    len = bits;
    sel = NULL;
    for (i = 0; i < g->f0; i++, e++) {
        if (e->f0 == 1) {
            if (e->f28 == len && cmp_80412210(e->f8, key) == 0) {
                if (!is_link_local_8041347C(key) || cmp_80412210(e->f18, addr) == 0) {
                    return -2;
                }
            }
        } else {
            sel = e;
            break;
        }
    }
    if (sel == NULL) {
        return -0x108;
    }
    sel->f0 = 1;
    NetMemcpy(sel->f8, key, 16);
    NetMemcpy(sel->f18, addr, 16);
    sel->f2 = kind;
    sel->f4 = mode;
    sel->f28 = bits;
    sel->f6 = idx;
    return 0;
}
#pragma pop

void TLobby__sub_804136AC(s16 i) {
    TLobby::is_slot_flag_0x20_set(i);
}

void TLobby__sub_804136CC(s16 i) {
    TLobby::is_socket_flag_set(i);
}

#pragma push
#pragma dont_inline off
#pragma inline_depth(4)
inline s16 addr_cmp_804136EC(void *a, void *b) {
    s32 r = NetMemcmp(a, b, 16);
    if (r < 0) {
        return -1;
    }
    if (r > 0) {
        return 1;
    }
    return 0;
}

inline s16 is_multicast_804136EC(u8 *a) {
    if (a[0] == 0xFF) {
        return 1;
    }
    return 0;
}

inline s16 is_link_local_804136EC(u8 *a) {
    u8 b;

    if (a[0] != 0xFE) {
        return 0;
    }
    b = a[1];
    if (!(b & 0x80) || (b & 0x40)) {
        return 0;
    }
    return 1;
}

inline Ipv6Iface *get_iface_804136EC(Ipv6AddressState *g, s16 idx) {
    Ipv6Iface *ifc;

    if (idx < 0 || idx >= g->count) {
        return NULL;
    }
    ifc = g->ifaces;
    ifc += idx;
    if (ifc->state != 1) {
        return NULL;
    }
    return ifc;
}

s16 TLobby__sub_804136EC(u8 *addr) {
    Ipv6AddressState *g = (Ipv6AddressState *)&ipv6_address_routing_state;
    s16 i;
    s16 n;
    Ipv6Iface *ifc;
    Ipv6AddrNode *node;

    i = 0;
    ifc = g->ifaces;
    for (; i < g->count; i++, ifc++) {
        if (ifc->state == 1) {
            if (addr_cmp_804136EC(ifc->addr, addr) == 0) {
                return i;
            }
            node = ifc->nodes;
            for (n = 0; node != NULL && n < g->max_nodes; n++) {
                if (addr_cmp_804136EC(node->addr, addr) == 0) {
                    return i;
                }
                node = node->next;
            }
        }
    }
    return -6;
}

s16 TLobby__sub_804137FC(u8 *addr, s16 idx) {
    Ipv6AddressState *g = (Ipv6AddressState *)&ipv6_address_routing_state;
    Ipv6Iface *ifc;
    s16 n;
    Ipv6AddrNode *node;

    if (idx < 0 || idx >= g->count) {
        return 0;
    }
    ifc = g->ifaces;
    ifc += idx;
    if (ifc->state != 1) {
        return 0;
    }
    if (addr_cmp_804136EC(ifc->addr, addr) == 0) {
        return 1;
    }
    node = ifc->nodes;
    for (n = 0; node != NULL && n < g->max_nodes; n++) {
        if (addr_cmp_804136EC(node->addr, addr) == 0) {
            return 1;
        }
        node = node->next;
    }
    return 0;
}

s16 TLobby__sub_80413934(u8 *addr, s16 idx) {
    Ipv6AddressState *g = (Ipv6AddressState *)&ipv6_address_routing_state;
    Ipv6Iface *ifc;
    s16 n;
    Ipv6AddrNode *node;

    ifc = get_iface_804136EC(g, idx);
    if (ifc == NULL) {
        return 0;
    }
    if (addr_cmp_804136EC(ifc->addr, addr) == 0) {
        if (ifc->f16 < 3) {
            return 0;
        }
        return 1;
    }
    node = ifc->nodes;
    for (n = 0; node != NULL && n < g->max_nodes; n++) {
        if (addr_cmp_804136EC(node->addr, addr) == 0) {
            if (node->f14 < 3) {
                return 0;
            }
            return 1;
        }
        node = node->next;
    }
    return 0;
}
s16 TLobby__sub_80413AA0(u8 *addr, s16 idx) {
    Ipv6AddressState *g = (Ipv6AddressState *)&ipv6_address_routing_state;
    Ipv6Iface *ifc;
    s16 n;
    Ipv6AddrNode *node;

    ifc = get_iface_804136EC(g, idx);
    if (ifc == NULL) {
        return 0;
    }
    if (addr_cmp_804136EC(ifc->addr, addr) == 0) {
        if (ifc->f16 < 2) {
            return 0;
        }
        return 1;
    }
    node = ifc->nodes;
    for (n = 0; node != NULL && n < g->max_nodes; n++) {
        if (addr_cmp_804136EC(node->addr, addr) == 0) {
            if (node->f14 < 2) {
                return 0;
            }
            return 1;
        }
        node = node->next;
    }
    return 0;
}

s16 TLobby__sub_80413C0C(u8 *addr, s16 idx) {
    Ipv6AddressState *g = (Ipv6AddressState *)&ipv6_address_routing_state;
    Ipv6Iface *ifc;
    s16 n;
    Ipv6AddrNode *node;

    ifc = get_iface_804136EC(g, idx);
    if (ifc == NULL) {
        return 0;
    }
    if (addr_cmp_804136EC(ifc->addr, addr) == 0) {
        if (ifc->f16 == 1) {
            return 1;
        }
        return 0;
    }
    node = ifc->nodes;
    for (n = 0; node != NULL && n < g->max_nodes; n++) {
        if (addr_cmp_804136EC(node->addr, addr) == 0) {
            if (node->f14 == 1) {
                return 1;
            }
            return 0;
        }
        node = node->next;
    }
    return 0;
}

s16 TLobby__sub_80413D78(u8 *addr, s16 idx) {
    Ipv6AddressState *g = (Ipv6AddressState *)&ipv6_address_routing_state;
    Ipv6Iface *ifc;
    s16 n;
    Ipv6AddrNode *node;

    if (is_multicast_804136EC(addr)) {
        return 0;
    }
    ifc = get_iface_804136EC(g, idx);
    if (ifc == NULL) {
        return 0;
    }
    if (addr_cmp_804136EC(ifc->addr, addr) == 0) {
        if (!(ifc->f1A & 1)) {
            return 0;
        }
        return 1;
    }
    node = ifc->nodes;
    for (n = 0; node != NULL && n < g->max_nodes; n++) {
        if (addr_cmp_804136EC(node->addr, addr) == 0) {
            if (!(node->f18 & 1)) {
                return 0;
            }
            return 1;
        }
        node = node->next;
    }
    return 0;
}

s16 TLobby__sub_80413F0C(u8 *addr, s16 idx) {
    Ipv6AddressState *g = (Ipv6AddressState *)&ipv6_address_routing_state;
    Ipv6Iface *ifc;
    s16 n;
    Ipv6AddrNode *node;
    u8 solicited[16];

    if (!is_multicast_804136EC(addr)) {
        return 0;
    }
    ifc = get_iface_804136EC(g, idx);
    if (ifc == NULL) {
        return 0;
    }
    NetIPv6MakeSolicitedNodeMulticastAddress(solicited, ifc->addr);
    if (addr_cmp_804136EC(solicited, addr) == 0) {
        return 1;
    }
    node = ifc->nodes;
    for (n = 0; node != NULL && n < g->max_nodes; n++) {
        NetIPv6MakeSolicitedNodeMulticastAddress(solicited, node->addr);
        if (addr_cmp_804136EC(solicited, addr) == 0) {
            return 1;
        }
        node = node->next;
    }
    return 0;
}

inline Ipv6Iface *lookup_iface_804136EC(Ipv6AddressState *g, s16 idx) {
    return get_iface_804136EC(g, idx);
}

s16 TLobby__sub_80414090(u8 *addr, s16 idx) {
    Ipv6AddressState *g = (Ipv6AddressState *)&ipv6_address_routing_state;
    Ipv6Iface *ifc;
    s16 n;
    Ipv6AddrNode *node;

    if (!is_link_local_804136EC(addr)) {
        return 0;
    }
    ifc = lookup_iface_804136EC(g, idx);
    if (ifc == NULL) {
        return 0;
    }
    if (addr_cmp_804136EC(ifc->addr, addr) == 0) {
        return 1;
    }
    node = ifc->nodes;
    for (n = 0; node != NULL && n < g->max_nodes; n++) {
        if (addr_cmp_804136EC(node->addr, addr) == 0) {
            return 1;
        }
        node = node->next;
    }
    return 0;
}
#pragma pop

s16 TLobby__sub_80414218(u8 *a, u8 *b) {
    s16 i;
    s16 bit;
    s16 count = 0;

    for (i = 0; i < 16; i++, a++, b++) {
        for (bit = 0; bit < 8; bit++) {
            switch (bit) {
            case 0:
                if ((*a & 0x80) != (*b & 0x80)) {
                    return count;
                }
                count++;
                break;
            case 1:
                if ((*a & 0x40) != (*b & 0x40)) {
                    return count;
                }
                count++;
                break;
            case 2:
                if ((*a & 0x20) != (*b & 0x20)) {
                    return count;
                }
                count++;
                break;
            case 3:
                if ((*a & 0x10) != (*b & 0x10)) {
                    return count;
                }
                count++;
                break;
            case 4:
                if ((*a & 0x08) != (*b & 0x08)) {
                    return count;
                }
                count++;
                break;
            case 5:
                if ((*a & 0x04) != (*b & 0x04)) {
                    return count;
                }
                count++;
                break;
            case 6:
                if ((*a & 0x02) != (*b & 0x02)) {
                    return count;
                }
                count++;
                break;
            case 7:
                if ((*a & 0x01) != (*b & 0x01)) {
                    return count;
                }
                count++;
                break;
            }
        }
    }
    return count;
}

typedef char RecoveredGlobal_8041471C_lbl_805C1BB8_size[sizeof(RecoveredGlobal_8041471C_lbl_805C1BB8) == 0x28 ? 1 : -1];

struct RecoveredFields_804143BC_arg0 {
    u8 field_0;
    u8 field_1;
};
typedef char RecoveredFields_804143BC_arg0_0_offset[offsetof(RecoveredFields_804143BC_arg0, field_0) == 0x0 ? 1 : -1];
typedef char RecoveredFields_804143BC_arg0_1_offset[offsetof(RecoveredFields_804143BC_arg0, field_1) == 0x1 ? 1 : -1];
#pragma push
#pragma scheduling off
s16 NetIPv6GetAddressScopeClass(u8 *arg0) {
    s16 var_r0;
    s16 var_r0_2;
    s16 var_r0_3;
    s16 var_r0_4;
    s32 var_r3;
    u8 var_r4;
    u8 var_r5;

    var_r5 = ((RecoveredFields_804143BC_arg0 *)arg0)->field_0;
    if (var_r5 != 0xFE) {
        var_r0 = 0;
    } else {
        var_r4 = ((RecoveredFields_804143BC_arg0 *)arg0)->field_1;
        if (!(var_r4 & 0x80) || (var_r4 & 0x40)) {
            var_r0 = 0;
        } else {
            var_r0 = 1;
        }
    }
    if (var_r0 != 0) {
        var_r3 = 2;
        return 2;
    }
    if (var_r5 != 0xFE) {
        var_r0_2 = 0;
    } else {
        var_r4 = ((RecoveredFields_804143BC_arg0 *)arg0)->field_1;
        if (!(var_r4 & 0x80) || !(var_r4 & 0x40)) {
            var_r0_2 = 0;
        } else {
            var_r0_2 = 1;
        }
    }
    if (var_r0_2 != 0) {
        var_r3 = 3;
        return 3;
    }
    if ((s32) (var_r5 & 0xE0) != 0x20) {
        var_r0_3 = 0;
    } else {
        var_r0_3 = 1;
    }
    if (var_r0_3 != 0) {
        var_r3 = 4;
        return 4;
    }
    if (var_r5 == 0xFF) {
        var_r0_4 = 1;
    } else {
        var_r0_4 = 0;
    }
    if (var_r0_4 != 0) {
        switch (((RecoveredFields_804143BC_arg0 *)arg0)->field_1 & 0xF) {
        case 1:
            var_r3 = 1;
            return 1;
        case 2:
            var_r3 = 2;
            return 2;
        case 5:
            var_r3 = 3;
            return 3;
        default:
            var_r3 = 4;
            return 4;
        }
    } else {
        if (NetIPv6IsLoopback(arg0) != 0) {
            var_r3 = 1;
            return 1;
        }
        var_r3 = 0;
        return 0;
    }
}
#pragma pop

typedef struct Ent_80414504 { s16 state; s16 f2; u8 pad[0x2C]; } Ent_80414504;
typedef struct Mgr_80414504 {
    s16 a;
    s16 count;
    u8 pad4[0x18];
    Ent_80414504 *ents;
} Mgr_80414504;

#pragma push
#pragma dont_inline off
#pragma inline_depth(1)
inline Ent_80414504 *find_80414504(s16 id) {
    Mgr_80414504 *g;
    Ent_80414504 *e;

    if (id < 0 || id >= (g = (Mgr_80414504 *)&ipv6_address_routing_state)->count) {
        return NULL;
    }
    e = g->ents;
    e += id;
    if (e->state != 1) {
        return NULL;
    }
    return e;
}

s16 NetIPv6GetInterfaceLinkLayerAddress(s32 arg0, s16 arg1, s16 id) {
    Ent_80414504 *e;
    s16 r;
    s16 TLobby__sub_80409EB0(s16 arg0, s32 arg1);

    e = find_80414504(id);
    if (e == NULL) {
        return -0x10A;
    }
    r = TLobby__sub_80409EB0(id, e->f2);
    if (r < 0) {
        return r;
    }
    if (r > arg1) {
        return -2;
    }
    TLobby__sub_80409E18(id, e->f2, arg0);
    return r;
}
#pragma pop

#pragma push
#pragma dont_inline off
#pragma inline_depth(4)
s16 TLobby__sub_804145D4(u8 *out, s16 idx) {
    Ipv6AddressState *g = (Ipv6AddressState *)&ipv6_address_routing_state;
    Ipv6Iface *ifc;
    s16 n;
    Ipv6AddrNode *node;
    u8 *addr;
    s16 max_nodes;

    ifc = get_iface_804136EC(g, idx);
    if (ifc == NULL) {
        return -0x10A;
    }
    addr = ifc->addr;
    if (is_link_local_804136EC(addr)) {
        NetMemcpy(out, ifc->addr, 16);
        return 0;
    }
    node = ifc->nodes;
    n = 0;
    max_nodes = g->max_nodes;
    for (; node != NULL && n < max_nodes; n++) {
        addr = node->addr;
        if (is_link_local_804136EC(addr)) {
            NetMemcpy(out, node->addr, 16);
            return 0;
        }
        node = node->next;
    }
    return -0x10A;
}
#pragma pop

#pragma push
#pragma opt_common_subs on
s16 *TLobby::get_valid_entry(s16 arg0) {
    s16 *temp_r3;
    if ((arg0 < 0) || (arg0 >= (s16) *(s16 *)((s8 *)(&(*(RecoveredGlobal_8041471C_lbl_805C1BB8 *)&ipv6_address_routing_state).value) + 2))) {
        return NULL;
    }
    temp_r3 = (s16 *)(*(s32 *)((s8 *)(&(*(RecoveredGlobal_8041471C_lbl_805C1BB8 *)&ipv6_address_routing_state).value) + 0x1C) + (arg0 * 0x30));
    if ((s16) *temp_r3 != 1) {
        return NULL;
    }
    return temp_r3;
}
#pragma pop

s32 NetIPv6MakeSolicitedNodeMulticastAddress(u8 *arg0, u8 *arg1) {
    *(u8 *)((s8 *)arg0 + 0) = 0xFF;
    *(s8 *)((s8 *)arg0 + 1) = 2;
    *(s8 *)((s8 *)arg0 + 2) = 0;
    *(s8 *)((s8 *)arg0 + 3) = 0;
    *(s8 *)((s8 *)arg0 + 4) = 0;
    *(s8 *)((s8 *)arg0 + 5) = 0;
    *(s8 *)((s8 *)arg0 + 6) = 0;
    *(s8 *)((s8 *)arg0 + 7) = 0;
    *(s8 *)((s8 *)arg0 + 8) = 0;
    *(s8 *)((s8 *)arg0 + 9) = 0;
    *(s8 *)((s8 *)arg0 + 0xA) = 0;
    *(s8 *)((s8 *)arg0 + 0xB) = 1;
    *(u8 *)((s8 *)arg0 + 0xC) = 0xFF;
    *(u8 *)((s8 *)arg0 + 0xD) = (u8) *(u8 *)((s8 *)arg1 + 0xD);
    *(u8 *)((s8 *)arg0 + 0xE) = (u8) *(u8 *)((s8 *)arg1 + 0xE);
    *(u8 *)((s8 *)arg0 + 0xF) = (u8) *(u8 *)((s8 *)arg1 + 0xF);
    return 0;
}

s32 init_ipv6_all_routers_multicast_address(u8 *address, s8 scope) {
    address[0] = 0xFF;
    address[1] = scope;
    address[2] = 0;
    address[3] = 0;
    address[4] = 0;
    address[5] = 0;
    address[6] = 0;
    address[7] = 0;
    address[8] = 0;
    address[9] = 0;
    address[0xA] = 0;
    address[0xB] = 0;
    address[0xC] = 0;
    address[0xD] = 0;
    address[0xE] = 0;
    address[0xF] = 2;
    return 0;
}

bool init_ipv6_all_nodes_multicast_address(u8 *address, s8 scope) {
    address[0] = 0xFF;
    address[1] = scope;
    address[2] = 0;
    address[3] = 0;
    address[4] = 0;
    address[5] = 0;
    address[6] = 0;
    address[7] = 0;
    address[8] = 0;
    address[9] = 0;
    address[0xA] = 0;
    address[0xB] = 0;
    address[0xC] = 0;
    address[0xD] = 0;
    address[0xE] = 0;
    address[0xF] = 1;
    return 0;
}

s32 NetIPv6IsLinkLocal(u8 *arg0) {
    u8 temp_r3;

    if ((u8) *(u8 *)((s8 *)arg0 + 0) != 0xFE) {
        return 0;
    }
    temp_r3 = *(u8 *)((s8 *)arg0 + 1);
    if (!(temp_r3 & 0x80) || (temp_r3 & 0x40)) {
        return 0;
    }
    return 1;
}

s16 NetIPv6IsLoopback(u8 *arg0) {
    struct Fields_arg0 { u8 field_0; u8 field_1; u8 field_2; u8 field_3; u8 field_4; u8 field_5; u8 field_6; u8 field_7; u8 field_8; u8 field_9; u8 field_A; u8 field_B; u8 field_C; u8 field_D; u8 field_E; u8 field_F; };
    if ((u8) ((Fields_arg0*)arg0)->field_0 != 0) {
        return 0;
    }
    if ((u8) ((Fields_arg0*)arg0)->field_1 != 0) {
        return 0;
    }
    if ((u8) ((Fields_arg0*)arg0)->field_2 != 0) {
        return 0;
    }
    if ((u8) ((Fields_arg0*)arg0)->field_3 != 0) {
        return 0;
    }
    if ((u8) ((Fields_arg0*)arg0)->field_4 != 0) {
        return 0;
    }
    if ((u8) ((Fields_arg0*)arg0)->field_5 != 0) {
        return 0;
    }
    if ((u8) ((Fields_arg0*)arg0)->field_6 != 0) {
        return 0;
    }
    if ((u8) ((Fields_arg0*)arg0)->field_7 != 0) {
        return 0;
    }
    if ((u8) ((Fields_arg0*)arg0)->field_8 != 0) {
        return 0;
    }
    if ((u8) ((Fields_arg0*)arg0)->field_9 != 0) {
        return 0;
    }
    if ((u8) ((Fields_arg0*)arg0)->field_A != 0) {
        return 0;
    }
    if ((u8) ((Fields_arg0*)arg0)->field_B != 0) {
        return 0;
    }
    if ((u8) ((Fields_arg0*)arg0)->field_C != 0) {
        return 0;
    }
    if ((u8) ((Fields_arg0*)arg0)->field_D != 0) {
        return 0;
    }
    if ((u8) ((Fields_arg0*)arg0)->field_E != 0) {
        return 0;
    }
    if ((u8) ((Fields_arg0*)arg0)->field_F == 1) {
        return 1;
    }
    return 0;
}

s32 NetIPv6IsMulticast(u8 *arg0) {
    if ((u8) *arg0 == 0xFF) {
        return 1;
    }
    return 0;
}

s16 NetIPv6IsUnspecified(u8 *arg0) {
    struct Fields_arg0 { u8 field_0; u8 field_1; u8 field_2; u8 field_3; u8 field_4; u8 field_5; u8 field_6; u8 field_7; u8 field_8; u8 field_9; u8 field_A; u8 field_B; u8 field_C; u8 field_D; u8 field_E; u8 field_F; };
    if ((u8) ((Fields_arg0*)arg0)->field_0 != 0) {
        return 0;
    }
    if ((u8) ((Fields_arg0*)arg0)->field_1 != 0) {
        return 0;
    }
    if ((u8) ((Fields_arg0*)arg0)->field_2 != 0) {
        return 0;
    }
    if ((u8) ((Fields_arg0*)arg0)->field_3 != 0) {
        return 0;
    }
    if ((u8) ((Fields_arg0*)arg0)->field_4 != 0) {
        return 0;
    }
    if ((u8) ((Fields_arg0*)arg0)->field_5 != 0) {
        return 0;
    }
    if ((u8) ((Fields_arg0*)arg0)->field_6 != 0) {
        return 0;
    }
    if ((u8) ((Fields_arg0*)arg0)->field_7 != 0) {
        return 0;
    }
    if ((u8) ((Fields_arg0*)arg0)->field_8 != 0) {
        return 0;
    }
    if ((u8) ((Fields_arg0*)arg0)->field_9 != 0) {
        return 0;
    }
    if ((u8) ((Fields_arg0*)arg0)->field_A != 0) {
        return 0;
    }
    if ((u8) ((Fields_arg0*)arg0)->field_B != 0) {
        return 0;
    }
    if ((u8) ((Fields_arg0*)arg0)->field_C != 0) {
        return 0;
    }
    if ((u8) ((Fields_arg0*)arg0)->field_D != 0) {
        return 0;
    }
    if ((u8) ((Fields_arg0*)arg0)->field_E != 0) {
        return 0;
    }
    if ((u8) ((Fields_arg0*)arg0)->field_F != 0) {
        return 0;
    }
    return 1;
}

s16 NetIPv6CompareAddresses(s32 arg0, s32 arg1) {
    s32 temp_r3;
    temp_r3 = NetMemcmp((void *)arg0, (void *)arg1, 0x10);
    if (temp_r3 < 0) {
        return -1;
    }
    if (temp_r3 > 0) {
        return 1;
    }
    return 0;
}

void TLobby__sub_80414B98(u8 *dst, s16 bits, u8 *src) {
    s16 len;
    s16 i;
    s16 rem;
    s16 bytes;

    if (bits < 0 || bits > 0x80) {
        return;
    }
    bytes = (len = bits) / 8;
    rem = len % 8;
    for (i = 0; i < bytes; i++) {
        *dst++ = *src++;
    }
    switch (rem) {
    case 7:
        *dst++ = *src & 0xFE;
        bytes++;
        break;
    case 6:
        *dst++ = *src & 0xFC;
        bytes++;
        break;
    case 5:
        *dst++ = *src & 0xF8;
        bytes++;
        break;
    case 4:
        *dst++ = *src & 0xF0;
        bytes++;
        break;
    case 3:
        *dst++ = *src & 0xE0;
        bytes++;
        break;
    case 2:
        *dst++ = *src & 0xC0;
        bytes++;
        break;
    case 1:
        *dst++ = *src & 0x80;
        bytes++;
        break;
    }
    for (; bytes < 16; bytes++) {
        *dst++ = 0;
    }
}

s16 NetCompareBitsBackward(u8 *arg0, u8 *arg1, s16 arg2) {
    s16 n;
    s16 rem;
    s32 a;
    s32 b;
    if (arg2 <= 0) {
        return 0;
    }
    rem = arg2 % 8;
    n = arg2 / 8;
    while (n > 0) {
        if (*arg0 != *arg1) {
            return *arg0 - *arg1;
        }
        arg0--;
        arg1--;
        n--;
    }
    switch (rem) {
    case 1:
        a = *arg0 & 1;
        b = *arg1 & 1;
        if (a != b) {
            return a - b;
        }
        return 0;
    case 2:
        a = *arg0 & 3;
        b = *arg1 & 3;
        if (a != b) {
            return a - b;
        }
        return 0;
    case 3:
        a = *arg0 & 7;
        b = *arg1 & 7;
        if (a != b) {
            return a - b;
        }
        return 0;
    case 4:
        a = *arg0 & 0xF;
        b = *arg1 & 0xF;
        if (a != b) {
            return a - b;
        }
        return 0;
    case 5:
        a = *arg0 & 0x1F;
        b = *arg1 & 0x1F;
        if (a != b) {
            return a - b;
        }
        return 0;
    case 6:
        a = *arg0 & 0x3F;
        b = *arg1 & 0x3F;
        if (a != b) {
            return a - b;
        }
        return 0;
    case 7:
        a = *arg0 & 0x7F;
        b = *arg1 & 0x7F;
        if (a != b) {
            return a - b;
        }
        return 0;
    }
    return 0;
}

s16 NetCompareBitPrefix(u8 *a, u8 *b, s16 bits) {
    s16 n;
    s16 rem;
    if (bits <= 0) {
        return 0;
    }
    rem = bits % 8;
    n = bits / 8;
    for (; n > 0; n--) {
        if (*a != *b) {
            return *a - *b;
        }
        a++;
        b++;
    }
    switch (rem) {
    case 1:
        if ((*a & 0x80) != (*b & 0x80)) return (*a & 0x80) - (*b & 0x80);
        return 0;
    case 2:
        if ((*a & 0xC0) != (*b & 0xC0)) return (*a & 0xC0) - (*b & 0xC0);
        return 0;
    case 3:
        if ((*a & 0xE0) != (*b & 0xE0)) return (*a & 0xE0) - (*b & 0xE0);
        return 0;
    case 4:
        if ((*a & 0xF0) != (*b & 0xF0)) return (*a & 0xF0) - (*b & 0xF0);
        return 0;
    case 5:
        if ((*a & 0xF8) != (*b & 0xF8)) return (*a & 0xF8) - (*b & 0xF8);
        return 0;
    case 6:
        if ((*a & 0xFC) != (*b & 0xFC)) return (*a & 0xFC) - (*b & 0xFC);
        return 0;
    case 7:
        if ((*a & 0xFE) != (*b & 0xFE)) return (*a & 0xFE) - (*b & 0xFE);
        return 0;
    case 0:
    default:
        return 0;
    }
}

#define G_ (*(G_8041509C *)&network_loopback_state)
s32 TLobby__sub_8041509C(void) {
    u8 unused[8];
    TLobby::clear_table_entry_locked(G_.a);
    G_.a = -1;
    TLobby__sub_803F8B78(&G_);
    G_.c = 0;
    return 0;
}

void TLobby__sub_804150EC(void) {
    TLobby__sub_8041510C();
}

void TLobby__sub_80409818(s32 msg, s16 len, s16 idx, s16 arg3, u16 type);

struct Proto_80415230 { s16 used; u16 type; };
struct G_80415230 {
    s16 handler;
    Proto_80415230 protos[2];
    s16 slot_size;
    s16 slot_count;
    u8 padE[2];
    s16 *slot_used;
    u8 *slots;
};

s32 TLobby__sub_80415230(s16 idx, s16 mode, u8 *addr, NetPacket *pkt);
s32 TLobby__sub_80415320(s16 idx, u8 *addr, NetPacket *pkt);
s32 TLobby__sub_80415410(s16 idx, u8 *pkt);

s16 TLobby__sub_8041510C(void) {
    G_80415230 *g = (G_80415230 *)&network_loopback_state;
    Fn_8040881C fns[11];
    s16 r;
    s16 i;
    s16 *used;

    fns[0] = (Fn_8040881C)TLobby::fill_reply_buffer;
    fns[1] = (Fn_8040881C)TLobby::alloc_conn_slot;
    fns[2] = (Fn_8040881C)TLobby::clear_conn_slot;
    fns[3] = (Fn_8040881C)TLobby::get_slot_offset_or_default;
    fns[4] = (Fn_8040881C)TLobby__sub_80415508;
    fns[5] = (Fn_8040881C)TLobby__sub_804154E4;
    fns[6] = (Fn_8040881C)TLobby__sub_804154C0;
    fns[7] = (Fn_8040881C)TLobby__sub_8041549C;
    fns[8] = (Fn_8040881C)TLobby__sub_80415410;
    fns[9] = (Fn_8040881C)TLobby__sub_80415320;
    fns[10] = (Fn_8040881C)TLobby__sub_80415230;
    r = TLobby__sub_80409A3C((u8 *)fns, 1);
    if (r < 0) {
        return r;
    }
    ((TLobby *)&network_loopback_state)->init_net_recv_desc();
    g->handler = r;
    g->protos[0].used = 0;
    g->protos[0].type = 0;
    g->protos[1].used = 0;
    g->protos[1].type = 0;
    used = g->slot_used;
    for (i = 0; i < g->slot_count; i++, used++) {
        *used = 0;
    }
    return r;
}

#pragma push
#pragma opt_common_subs on
s32 TLobby__sub_80415230(s16 idx, s16 mode, u8 *addr, NetPacket *pkt) {
    G_80415230 *g = (G_80415230 *)&network_loopback_state;
    u8 *slot;
    s16 len;
    s16 i;
    s16 *used;

    if (idx != 0 && idx != 1) {
        return -0x110;
    }
    len = TLobby__sub_804098B4(pkt);
    if (g->slot_size < len) {
        return -0x110;
    }
    used = g->slot_used;
    slot = g->slots;
    for (i = 0; i < g->slot_count; i++, used++) {
        if (*used == 0) {
            *used = 1;
            TLobby__sub_80409908(slot, pkt);
            TLobby__sub_80409818((s32)slot, len, g->handler, idx, g->protos[idx].type);
            return 0;
        }
        slot += g->slot_size;
    }
    return -0x110;
}

s32 TLobby__sub_80415320(s16 idx, u8 *addr, NetPacket *pkt) {
    G_80415230 *g = (G_80415230 *)&network_loopback_state;
    u8 *slot;
    s16 len;
    s16 i;
    s16 *used;

    if (idx != 0 && idx != 1) {
        return -0x110;
    }
    len = TLobby__sub_804098B4(pkt);
    if (g->slot_size < len) {
        return -0x110;
    }
    used = g->slot_used;
    slot = g->slots;
    for (i = 0; i < g->slot_count; i++, used++) {
        if (*used == 0) {
            *used = 1;
            TLobby__sub_80409908(slot, pkt);
            TLobby__sub_80409818((s32)slot, len, g->handler, idx, g->protos[idx].type);
            return 0;
        }
        slot += g->slot_size;
    }
    return -0x110;
}

s32 TLobby__sub_80415410(s16 idx, u8 *pkt) {
    G_80415230 *g = (G_80415230 *)&network_loopback_state;
    s16 i;
    s16 *used;
    u8 *slot;
    s16 size;

    if (idx != 0 && idx != 1) {
        return -0x110;
    }
    used = g->slot_used;
    slot = g->slots;
    size = g->slot_size;
    for (i = 0; i < g->slot_count; i++, used++) {
        if (*used != 0 && slot <= pkt && pkt < slot + size) {
            *used = 0;
            return 0;
        }
        slot += size;
    }
    return -0x110;
}
#pragma pop

s32 TLobby__sub_8041549C(s16 arg0) {
    if ((arg0 != 0) && (arg0 != 1)) {
        return -0x110;
    }
    return 0;
}

s32 TLobby__sub_804154C0(s16 arg0) {
    if ((arg0 != 0) && (arg0 != 1)) {
        return -0x110;
    }
    return 0;
}

s32 TLobby__sub_804154E4(s16 arg0) {
    if ((arg0 != 0) && (arg0 != 1)) {
        return -0x110;
    }
    return 0;
}

s32 TLobby__sub_80415508(s16 arg0) {
    if ((arg0 != 0) && (arg0 != 1)) {
        return -0x110;
    }
    return 0;
}

typedef char RecoveredGlobal_8041552C_lbl_805C1BE0_size[sizeof(RecoveredGlobal_8041552C_lbl_805C1BE0) == 0x18 ? 1 : -1];
s16 TLobby::get_slot_offset_or_default(s16 arg0) {
    if ((arg0 != 0) && (arg0 != 1)) {
        return -0x110;
    }
    return *(s16 *)((s8 *)(&network_loopback_state.value) + 0xA);
}

struct E_80415558 { s16 a; s16 b; };
struct G_80415558 { s16 h; E_80415558 e[2]; };
s32 TLobby::clear_conn_slot(s16 i) {
    if (i != 0 && i != 1) { return -0x110; }
    G_80415558 *g = (G_80415558 *)&network_loopback_state;
    g->e[i].a = 0;
    g->e[i].b = 0;
    return 0;
}

struct E_8041559C { s16 a; s16 b; };
struct G_8041559C { s16 h; E_8041559C e[2]; };
s16 TLobby::alloc_conn_slot(s16 h, s16 v) {
    s16 r;
    G_8041559C *g = (G_8041559C *)&network_loopback_state;
    if (h != g->h) { return -0x110; }
    if (g->e[0].a == 0) {
        r = 0;
    } else if (g->e[1].a == 0) {
        r = 1;
    } else {
        return -0x110;
    }
    g->e[r].a = 1;
    g->e[r].b = v;
    return r;
}

s32 TLobby::fill_reply_buffer(s16 h, u8 *p) {
    if (h != *(s16 *)&network_loopback_state) { return -0x110; }
    p[0] = 0;
    *++p = 0;
    p[1] = 0;
    p[2] = 0;
    p[3] = 0;
    p[4] = 0;
    p[5] = 0;
    p[6] = 1;
    return 0;
}

typedef char RecoveredGlobal_80415650_lbl_805C1BF8_size[sizeof(RecoveredGlobal_80415650_lbl_805C1BF8) == 0x10 ? 1 : -1];
s32 TLobby::reset_net_value() {
    TLobby__sub_803F89D8((void *)((void *) (&network_buffer_pool_state.value)));
    network_buffer_pool_state.value = 0;
    return 0;
}

struct Seg_80415690 {
    s16 owner;
    u16 offset;
    u16 len;
};
struct Ent_80415690 {
    u8 *buf;
    s32 free_segs;
    s32 free_bytes;
    Seg_80415690 segs[8];
};
struct Pool_80415690 {
    s16 count;
    s16 size;
    Ent_80415690 *ents;
    u8 *data;
};

#pragma push
#pragma opt_common_subs on
#pragma pool_data off
s16 TLobby__sub_80415690(void) {
    u8 *buf;
    s16 i;
    Ent_80415690 *e;
    s16 j;

    ((TLobby *)&network_buffer_pool_state)->init_buffer_desc_a();
    buf = ((Pool_80415690 *)&network_buffer_pool_state)->data;
    e = ((Pool_80415690 *)&network_buffer_pool_state)->ents;
    for (i = 0; i < ((Pool_80415690 *)&network_buffer_pool_state)->count; i++, e++) {
        e->buf = buf;
        buf += ((Pool_80415690 *)&network_buffer_pool_state)->size & 0xFFFF;
        e->free_segs = 8;
        e->free_bytes = ((Pool_80415690 *)&network_buffer_pool_state)->size;
        e->segs[0].owner = -1;
        e->segs[0].offset = 0;
        e->segs[0].len = ((Pool_80415690 *)&network_buffer_pool_state)->size;
        for (j = 1; j < 8; j++) {
            e->segs[j].owner = 0;
            e->segs[j].offset = ((Pool_80415690 *)&network_buffer_pool_state)->size;
            e->segs[j].len = 0;
        }
    }
    return 0;
}
#pragma pop

#pragma push
#pragma opt_common_subs on
s16 TLobby__sub_80415954(NetBufferRef *ref, s32 size, s16 owner) {
    Pool_80415690 *pool;
    Ent_80415690 *e;
    u32 p;
    s16 i;
    s16 j;

    if (owner == 1) {
        p = TLobby::alloc_buffer_slot(size);
        if (p == 0) {
            return -1;
        }
        ref->kind = 4;
        ref->value = p;
        return 0;
    }
    if (size < 0x400) {
        size = 0x400;
    }
    pool = (Pool_80415690 *)&network_buffer_pool_state;
    e = pool->ents;
    for (i = 0; i < pool->count; i++, e++) {
        if (e->free_segs == 0 || size > e->free_bytes) {
            continue;
        }
        for (j = 0; j < 8; j++) {
            if (e->segs[j].owner != 0 && e->segs[j].owner == -1 && e->segs[j].len >= (u16)size) {
                ref->value = (i << 24) + (j << 16);
                ref->kind = 2;
                e->segs[j].owner = owner;
                if (j + 1 < 8 && e->segs[j].len - (u16)size != 0 && e->segs[j + 1].owner == 0) {
                    e->segs[j + 1].offset = e->segs[j].offset + size;
                    e->segs[j + 1].len = e->segs[j].len - size;
                    e->segs[j + 1].owner = -1;
                    e->segs[j].len = size;
                }
                e->free_segs--;
                e->free_bytes -= e->segs[j].len;
                return 0;
            }
        }
    }
    return -1;
}
#pragma pop

struct A_80415B38 { s8 c0; s8 c1; s8 c2; s8 c3; u8 pad4[0x30]; s32 off; };
struct C_80415B38 { s8 c0; s8 c1; s8 c2; s8 c3; u8 pad4[2]; s16 f6; u8 pad8[0x1C]; };
struct B_80415B38 {
    s8 c0;
    s8 c1;
    s8 c2;
    s8 c3;
    u8 pad4[4];
    s16 id;
    u8 padA[2];
    u8 flags;
    u8 padD[3];
    A_80415B38 *link;
    u8 pad14[2];
    u8 addr[0x10];
    s16 f26;
    u8 pad28[0x20];
};
struct G_80415B38 {
    s16 na;
    s16 nb;
    s16 nc;
    u8 pad6[2];
    A_80415B38 *a;
    B_80415B38 *b;
    C_80415B38 *c;
    s16 stride;
    u8 pad16[2];
    s32 base;
    u8 pad1C[8];
    s16 maxage;
    u8 pad26[4];
    s16 f2A;
    s16 f2C;
    u8 pad2E[2];
};
extern G_80415B38 ipv6_neighbor_discovery_state;
void NetIPv6ShutdownNeighborDiscovery(void) {
    G_80415B38 *g = &ipv6_neighbor_discovery_state;
    NetUnregisterTimer((void *)NetIPv6TickNeighborDiscovery);
    TLobby__sub_803F88E0(g);
    g->nb = 0;
    g->nc = 0;
}

struct Arg2_80415B38 { u8 *addr; u8 *val; };
typedef struct Ent_80418670 { u8 pad0[3]; u8 f3; u8 pad4[2]; s16 f6; u8 pad8[0xC]; u8 f14[0x10]; } Ent_80418670;
s32 TLobby__sub_80411604(s16, int, void *);
Ent_80418670 *NetIPv6SelectDefaultRouter(void *arg0);

s32 NetIPv6InitNeighborDiscovery(void) {
    s16 n;
    s32 off;
    A_80415B38 *a;
    C_80415B38 *c;
    B_80415B38 *b;
    Ent_80418670 *r;
    G_80415B38 *g;
    s16 stride;
    Arg2_80415B38 a2;
    Arg2_80415B38 a1;

    g = &ipv6_neighbor_discovery_state;
    NetMemset(g, 0, sizeof(G_80415B38));
    ((TLobby *)g)->init_buffer_descriptor_b();
    NetIPv6ApplyNeighborDiscoveryDefaults((u8 *)g);
    n = g->na;
    a = g->a;
    off = g->base;
    stride = g->stride;
    for (; n > 0; n--) {
        a->c0 = 0x50;
        a->c1 = 0x45;
        a->c2 = 0x4E;
        a->off = off;
        off += stride;
        a->c3 = 0;
        a++;
    }
    n = g->nc;
    c = g->c;
    for (; n > 0; n--) {
        c->c0 = 0x44;
        c->c1 = 0x4C;
        c->c2 = 0x45;
        c->c3 = 0;
        c->f6 = 0;
        c++;
    }
    n = g->nb;
    b = g->b;
    for (; n > 0; n--) {
        b->c0 = 0x4E;
        b->c1 = 0x43;
        b->c2 = 0x45;
        b->flags = 0;
        b->link = NULL;
        if (b->link != NULL) {
            b->link->c3 = 0;
            b->link = NULL;
        }
        if (b->flags & 0x80) {
            r = NetIPv6SelectDefaultRouter(b->addr);
            if (r == NULL) {
                a1.addr = b->addr;
                TLobby__sub_80411604(b->id, 6, &a1);
            } else {
                a2.val = r->f14;
                a2.addr = b->addr;
                TLobby__sub_80411604(b->id, 7, &a2);
            }
        }
        b->c3 = 0;
        b->f26 = 0;
        b++;
    }
    NetRegisterTimer(1000, (s16)(1), (NetTimerCallback)(NetIPv6TickNeighborDiscovery));
    return 0;
}

void NetIPv6TickNeighborDiscovery(void) {
    NetIPv6TickNeighborCache();
    TLobby__sub_8041615C();
}

s16 TLobby__sub_80415D0C(NetPacket *pkt, u8 *nexthop, NetIPv6SendParameters *params, s16 idx) {
    s16 NetIPv6IsMulticast(u8 *addr);
    E_804179A4 *NetIPv6FindOrSelectNeighborCacheEntry(void *, int, int);
    Q_804179A4 *NetIPv6SelectPendingPacketSlot(void);
    s16 NetIPv6SendMulticastNeighborProbe(u8 *entry);
    s16 TLobby__sub_80410BA8(void *, void *, s16, void *);
    G_80415B38 *g = &ipv6_neighbor_discovery_state;
    E_804179A4 *e;
    Ent_80418670 *r;
    Arg2_80415B38 a2;
    Arg2_80415B38 a1;
    NetBufferRef ref;
    Arg2_80415B38 b2;
    Arg2_80415B38 b1;

    if (NetIPv6IsMulticast(nexthop)) {
        return -2;
    }
    e = NetIPv6FindOrSelectNeighborCacheEntry(nexthop, 0, 0);
    if (e == NULL) {
        return -0x10E;
    }
    switch (e->f6) {
    case 2:
        switch (e->f4) {
        case 0:
            break;
        case 2:
            e->f8 = idx;
            e->f4 = 3;
            e->fa = g->f2C;
        case 1:
        case 3:
        case 4:
            return TLobby__sub_80410BA8(pkt, params, idx, e->f28);
        }
        break;
    case 0:
    case 1:
    case 3:
        if (e->f10 != NULL) {
            e->f10->f3 = 0;
            e->f10 = NULL;
        }
        if (e->fc & 0x80) {
            r = NetIPv6SelectDefaultRouter(e->f16);
            if (r == NULL) {
                a1.addr = e->f16;
                TLobby__sub_80411604(e->f8, 6, &a1);
            } else {
                a2.val = r->f14;
                a2.addr = e->f16;
                TLobby__sub_80411604(e->f8, 7, &a2);
            }
        }
        e->f3 = 0;
        e->f26 = 0;
        e->f3 = 1;
        e->f8 = idx;
        NetMemcpy(e->f16, nexthop, 0x10);
        e->f4 = 0;
        break;
    default:
        return -0x10E;
    }
    {
        s16 ret;
        u8 *src;
        u32 n;
        Q_804179A4 *q;
        NetPacketFragment *frag;
        if (e->f10 == NULL) {
            e->f10 = NetIPv6SelectPendingPacketSlot();
        }
        q = e->f10;
        n = pkt->fragment_count;
        src = q->f34;
        q->f30 = 0;
        frag = pkt->fragments + n - 1;
        while (n != 0) {
            s16 l = frag->length;
            q->f30 += l;
            if (q->f30 > g->stride) {
                ret = -0x10E;
                goto done;
            }
            ((TLobby *)&ref)->set_value_and_enable((s32)src);
            TLobby__sub_80406FD8(&ref, &pkt->fragments[n - 1].buffer, l);
            src += l;
            frag--;
            n--;
        }
        ret = 0;
done:
        if (ret < 0) {
            if (e->f10 != NULL) {
                e->f10->f3 = 0;
                e->f10 = NULL;
            }
            if (e->fc & 0x80) {
                r = NetIPv6SelectDefaultRouter(e->f16);
                if (r == NULL) {
                    b1.addr = e->f16;
                    TLobby__sub_80411604(e->f8, 6, &b1);
                } else {
                    b2.val = r->f14;
                    b2.addr = e->f16;
                    TLobby__sub_80411604(e->f8, 7, &b2);
                }
            }
            e->f3 = 0;
            e->f26 = 0;
            return ret;
        }
        NetMemcpy(e->f10->f8, params, sizeof(NetIPv6SendParameters));
        e->fa = g->f2A;
        e->f10->f4 = e->fa;
        e->f14 = 0;
        return NetIPv6SendMulticastNeighborProbe((u8 *)e);
    }
}

s32 NetIPv6SendUnspecifiedSourceNeighborSolicitation(s32 arg0, s32 arg1) {
    s32 NetIPv6EmitNeighborSolicitation(NetPacket *, u8 *, NetIPv6SendParameters *, s32, u8 *);
    s16 TLobby__sub_80413D78();
    struct Fields_temp_r3 { u8 pad_0[4]; s32 field_4; s32 field_8; };
    typedef char sp10_offset[(offsetof(Stack_80416008, sp10) == 0x0) ? 1 : -1];
    typedef char sp20_offset[(offsetof(Stack_80416008, sp20) == 0x10) ? 1 : -1];
    Stack_80416008 stack;
    s32 temp_r31;
    u8 *free_entry;
    if (TLobby__sub_80413D78() != 0) {
        return -0x10E;
    }
    free_entry = (u8 *)(TLobby::alloc_free_entry());
    if (free_entry == NULL) {
        return -0x10E;
    }
    ((Fields_temp_r3*)free_entry)->field_4 = 0;
    ((Fields_temp_r3*)free_entry)->field_8 = 0;
    NetMemset((void *) (&stack.sp10), 0, 0x10);
    NetIPv6MakeSolicitedNodeMulticastAddress((u8 *)((void *) (&stack.sp20)), (u8 *)(arg0));
    temp_r31 = NetIPv6EmitNeighborSolicitation((NetPacket *)free_entry, (u8 *)arg0, (NetIPv6SendParameters *)(&stack.sp10), arg1, NULL);
    ((TUdpSocket *)free_entry)->release_entry();
    return temp_r31;
}

s32 NetIPv6SendRouterSolicitation(s32 arg0) {
    s16 TLobby__sub_804145D4(void *, void *);
    u8 address[0x1C];
    u8 addr[0x10];
    s32 temp_r31;
    u8 *free_entry;

    free_entry = (u8 *)(TLobby::alloc_free_entry());
    if (free_entry == NULL) {
        return -0x10E;
    }
    *(s32 *)((s8 *)free_entry + 4) = 0;
    *(s32 *)((s8 *)free_entry + 8) = 0;
    init_ipv6_all_routers_multicast_address((u8 *)(address), (s8)(2));
    if (TLobby__sub_804145D4((void *)addr, (void *)arg0) < 0) {
        NetMemset(addr, 0, 0x10);
    }
    temp_r31 = NetIPv6EmitRouterSolicitation((NetPacket *)(free_entry), (NetIPv6SendParameters *)(addr), (s32)(arg0));
    ((TUdpSocket *)free_entry)->release_entry();
    return temp_r31;
}

typedef struct Rtr_8041615C {
    u8 pad0[3];
    u8 state;
    s16 id;
    s16 f6;
    s16 lifetime;
    u8 padA[0xA];
    u8 addr[0x10];
} Rtr_8041615C;
typedef struct Nbr_8041615C {
    u8 pad0[3];
    u8 state;
    u8 pad4[8];
    u8 flags;
    u8 padD[9];
    u8 addr[0x10];
    u8 pad26[0x22];
} Nbr_8041615C;
typedef struct G_8041615C {
    s16 f0;
    s16 nnbr;
    s16 nrtr;
    u8 pad6[6];
    Nbr_8041615C *nbrs;
    Rtr_8041615C *rtrs;
} G_8041615C;

#pragma push
#pragma dont_inline off
#pragma inline_depth(4)
inline u8 *find_nbr_8041615C(G_8041615C *g, u8 *addr) {
    s16 n = g->nnbr;
    Nbr_8041615C *nb = g->nbrs;
    for (; n > 0; n--, nb++) {
        if (nb->state == 1 && NetMemcmp(nb->addr, addr, 0x10) == 0) {
            return (u8 *)nb;
        }
    }
    return NULL;
}

void TLobby__sub_8041615C(void) {
    G_8041615C *g = (G_8041615C *)&ipv6_neighbor_discovery_state;
    Nbr_8041615C *nb;
    s16 n;
    Rtr_8041615C *r;
    Rtr_8041615C *alive = NULL;
    Rtr_8041615C *expired = NULL;
    Arg2_80415B38 a6;
    Arg2_80415B38 a7;

    n = g->nrtr;
    r = g->rtrs;
    for (; n > 0; n--, r++) {
        if (r->state == 1) {
            if (r->lifetime > 1) {
                r->lifetime--;
                alive = r;
            } else {
                r->state = 0;
                expired = r;
                r->f6 = 0;
            }
        }
    }
    if (expired == NULL) {
        return;
    }
    nb = (Nbr_8041615C *)find_nbr_8041615C(g, expired->addr);
    if (nb != NULL) {
        nb->flags &= ~0x80;
    }
    if (alive != NULL) {
        a7.addr = expired->addr;
        a7.val = alive->addr;
        TLobby__sub_80411604(alive->id, 7, &a7);
    } else {
        a6.addr = expired->addr;
        TLobby__sub_80411604(expired->id, 6, &a6);
    }
}
#pragma pop

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
s32 NetIPv6SendMulticastNeighborProbe(u8 *arg0);
s32 NetIPv6SendUnicastNeighborProbe(u8 *arg0);

void NetIPv6TickNeighborCache(void) {
    Arg_804162A4 a7;
    Arg_804162A4 a6;
    Arg_804162A4 a7b;
    Arg_804162A4 a6b;
    Glob_804162A4 *g = (Glob_804162A4 *)&ipv6_neighbor_discovery_state;
    s16 n;
    Ent_804162A4 *e;
    Ent_80418670 *r;

    n = g->count;
    e = g->ents;
    while (n > 0) {
        if (e->state == 1) {
            if (e->timer > 1) {
                e->timer--;
                if (e->sub != NULL) {
                    e->sub->count--;
                }
            } else {
                switch (e->phase) {
                case 0:
                    if (++e->tries < g->maxTries0) {
                        NetIPv6SendMulticastNeighborProbe((u8 *)e);
                        e->timer = g->delay;
                    } else {
                        if (e->sub != NULL) {
                            e->sub->state = 0;
                            e->sub = NULL;
                        }
                        if (e->flags & 0x80) {
                            r = NetIPv6SelectDefaultRouter(e->name);
                            if (r == NULL) {
                                a6.p = e->name;
                                TLobby__sub_80411604(e->id, 6, &a6);
                            } else {
                                a7.v = (s32)r->f14;
                                a7.p = e->name;
                                TLobby__sub_80411604(e->id, 7, &a7);
                            }
                        }
                        e->state = 0;
                        e->f26 = 0;
                    }
                    break;
                case 1:
                    e->phase = 2;
                    e->timer = g->delay1;
                    break;
                case 2:
                    e->timer = 0;
                    break;
                case 3:
                    NetIPv6SendUnicastNeighborProbe((u8 *)e);
                    e->phase = 4;
                    e->timer = g->delay;
                    e->tries = 0;
                    break;
                case 4:
                    if (++e->tries < g->maxTries1) {
                        NetIPv6SendUnicastNeighborProbe((u8 *)e);
                        e->timer = g->delay;
                    } else {
                        if (e->sub != NULL) {
                            e->sub->state = 0;
                            e->sub = NULL;
                        }
                        if (e->flags & 0x80) {
                            r = NetIPv6SelectDefaultRouter(e->name);
                            if (r == NULL) {
                                a6b.p = e->name;
                                TLobby__sub_80411604(e->id, 6, &a6b);
                            } else {
                                a7b.v = (s32)r->f14;
                                a7b.p = e->name;
                                TLobby__sub_80411604(e->id, 7, &a7b);
                            }
                        }
                        e->state = 0;
                        e->f26 = 0;
                    }
                    break;
                }
            }
        }
        n--;
        e++;
    }
}

struct Redirect_80416508 {
    NetIcmpv6Header header;
    IPv6Address target;
    IPv6Address dest;
};
struct Arg_80416508 {
    u8 *dest;
    s16 id;
    u8 *router;
    u8 *target;
};
#pragma push
#pragma opt_propagation off
s16 NetIPv6HandleRedirect(NetPacket *pkt, u8 *src, void *arg2, s16 iface) {
    NetBufferRef ref;
    Redirect_80416508 msg;
    u8 opts[0x38];
    s16 optlen;
    Arg_80416508 arg;
    u8 *e;
    u8 *dest;
    u8 *target;
    u32 len;
    NetPacketFragment *frag;
    s16 r;
    s16 NetIPv6IsLinkLocal(u8 *arg0);
    s16 NetIPv6IsMulticast(u8 *arg0);
    s16 NetIPv6ParseRedirectOptions(u8 *arg0, s32 n, u8 *arg2, s32 arg3, s16 *arg4, s16 arg5);
    s32 TLobby__sub_80411604(s16, int, void *);

    frag = &pkt->fragments[1];
    optlen = sizeof(opts);
    len = pkt->fragments[1].length;
    if (len < sizeof(Redirect_80416508)) {
        return -1;
    }
    if (NetIPv6IsLinkLocal(src) == 0) {
        return -1;
    }
    ((TLobby *)&ref)->set_value_and_enable((s32)&msg);
    TLobby__sub_80406FD8(&ref, &frag->buffer, sizeof(Redirect_80416508));
    dest = msg.dest.bytes;
    if (NetIPv6IsMulticast(dest) != 0) {
        return -1;
    }
    target = msg.target.bytes;
    if (NetIPv6IsLinkLocal(target) == 0 && NetMemcmp(target, dest, 0x10) != 0) {
        return -1;
    }
    e = TLobby__sub_80413264(dest, (s32)src);
    if (e == NULL || NetMemcmp(e + 0x18, src, 0x10) != 0) {
        return -1;
    }
    len -= sizeof(Redirect_80416508);
    if (len >= 8) {
        TLobby__sub_80406EB8(&frag->buffer, sizeof(Redirect_80416508));
        r = NetIPv6ParseRedirectOptions((u8 *)frag, len, (u8 *)&msg, (s32)opts, &optlen, iface);
        if (r < 0) {
            return r;
        }
    }
    arg.dest = dest;
    arg.id = *(s16 *)(e + 0x28);
    arg.router = e + 0x18;
    arg.target = target;
    TLobby__sub_80411604(iface, 10, &arg);
    return 0;
}
#pragma pop

typedef struct Ent_80416678 { u8 pad0[0xC]; u8 fC; } Ent_80416678;
s32 NetIPv6ParseRedirectOptions(u8 *arg0, s32 n, u8 *arg2, s32 arg3, s16 *arg4, s16 arg5) {
    u8 sp20[8];
    u8 *h;
    s16 len;
    Ent_80416678 *e;
    void TLobby__sub_80406EB8(void *, s32);
    u8 *TLobby__sub_80406F0C(void *);
    void TLobby__sub_80406FD8(void *, void *, s32);
    Ent_80416678 *TLobby__sub_804182DC(void *, void *, s32, s16);

    while (n >= 8) {
        h = TLobby__sub_80406F0C(arg0 + 4);
        if (h[1] == 0) {
            return -0x10E;
        }
        len = h[1] * 8;
        n -= len;
        if (n < 0) {
            return -0x10E;
        }
        switch (h[0]) {
        case 1:
        case 3:
        case 5:
        default:
            TLobby__sub_80406EB8(arg0 + 4, len);
            break;
        case 4:
            *arg4 = (*arg4 < len) ? *arg4 : len;
            ((TLobby *)sp20)->set_value_and_enable(arg3);
            TLobby__sub_80406FD8(sp20, arg0 + 4, *arg4);
            TLobby__sub_80406EB8(arg0 + 4, len);
            break;
        case 2: {
            u8 *p = h + 2;
            s32 l = len - 2;
            e = TLobby__sub_804182DC(arg2 + 8, p, l, arg5);
            if (e != NULL && NetMemcmp(arg2 + 8, arg2 + 0x18, 0x10) != 0) {
                e->fC |= 0x80;
            }
            TLobby__sub_80406EB8(arg0 + 4, len);
            break;
        }
        }
    }
    return 0;
}

struct Msg_80416994 { u8 pad0[4]; u8 flags; u8 pad5[3]; u8 name[0x10]; };
s16 NetIPv6FindTargetLinkLayerAddressOption(u8 *o, s32 len, u8 **out, s16 *outlen);
s16 NetIPv6ApplyNeighborAdvertisement(Msg_80416994 *msg, u8 *name, s16 len, s32 arg3, s32 arg4, s16 id);

s16 NetIPv6HandleNeighborAdvertisement(NetPacket *pkt, u8 *src, u8 *dst, s16 iface) {
    s16 NetIPv6IsMulticast(u8 *addr);
    NetBufferRef ref;
    Msg_80416994 msg;
    u8 *lladdr;
    s16 lladdr_len;
    NetPacketFragment *frag;
    u32 len;
    s16 r;

    frag = &pkt->fragments[1];
    lladdr = NULL;
    lladdr_len = 0;
    len = frag->length;
    if (len < sizeof(Msg_80416994)) {
        return -1;
    }
    ((TLobby *)&ref)->set_value_and_enable((s32)&msg);
    TLobby__sub_80406FD8(&ref, &frag->buffer, sizeof(Msg_80416994));
    if (NetIPv6IsMulticast(msg.name) != 0) {
        return -1;
    }
    len -= sizeof(Msg_80416994);
    if (len >= 8) {
        TLobby__sub_80406EB8(&frag->buffer, sizeof(Msg_80416994));
        r = NetIPv6FindTargetLinkLayerAddressOption((u8 *)frag, len, &lladdr, &lladdr_len);
        if (r < 0) {
            return r;
        }
    }
    if (NetIPv6IsMulticast(dst) != 0 && ((msg.flags & 0x40) || lladdr_len == 0)) {
        return -1;
    }
    return NetIPv6ApplyNeighborAdvertisement(&msg, lladdr, lladdr_len, (s32)src, (s32)dst, iface);
}

u8 *TLobby__sub_80406F0C(void *);

s16 NetIPv6FindTargetLinkLayerAddressOption(u8 *o, s32 len, u8 **out, s16 *outlen) {
    u8 *p;
    s16 sz;

    while (len >= 8) {
        p = TLobby__sub_80406F0C(o + 4);
        if (p[1] == 0) {
            return -0x10E;
        }
        sz = p[1] << 3;
        len -= sz;
        if (len < 0) {
            return -0x10E;
        }
        if ((s32)p[0] != 2) {
            TLobby__sub_80406EB8((NetBufferRef *)(o + 4), sz);
        } else {
            *out = p + 2;
            *outlen = sz - 2;
            TLobby__sub_80406EB8((NetBufferRef *)(o + 4), sz);
        }
    }
    return 0;
}

struct Peer_80416994 { u8 pad0[3]; u8 state; u8 pad4[2]; s16 f6; u8 pad8[0x14 - 0x8]; u8 name[0x10]; };
struct Sub_80416994 { u8 pad0[3]; u8 state; u8 pad4[4]; u8 addr[0x30 - 0x8]; s16 port; u8 pad32[2]; s32 val; };
struct Ent_80416994 {
    u8 pad0[3];
    u8 state;
    s16 phase;
    u8 pad6[2];
    s16 f8;
    s16 timer;
    u8 flags;
    u8 padD[3];
    Sub_80416994 *sub;
    u8 pad14[2];
    u8 name[0x10];
    s16 len;
    u8 data[0x48 - 0x28];
};
struct Glob_80416994 {
    u8 pad0[2];
    s16 count;
    s16 count2;
    u8 pad6[0xC - 6];
    Ent_80416994 *ents;
    Peer_80416994 *peers;
    u8 pad14[0x24 - 0x14];
    s16 delay2;
    s16 delay1;
};
struct Item_80416994 { s16 port; u8 pad2[2]; u8 val[8]; };
struct Pkt_80416994 { u8 pad0[4]; s32 n; s32 port; Item_80416994 items[1]; };
struct Arg_80416994 { u8 *p; s32 v; };

#pragma push
#pragma dont_inline off
#pragma inline_depth(4)
inline Ent_80416994 *FindEnt_80416994(Glob_80416994 *g, void *name) {
    s16 n = g->count;
    Ent_80416994 *e = g->ents;
    for (; n > 0; n--, e++) {
        if (e->state == 1 && NetMemcmp(e->name, name, 0x10) == 0) {
            return e;
        }
    }
    return 0;
}

inline void ClearPeer_80416994(Peer_80416994 *p) {
    p->state = 0;
    p->f6 = 0;
}

inline Peer_80416994 *ScanPeers_80416994(Glob_80416994 *g, void *name) {
    s16 m;
    Peer_80416994 *p;
    Peer_80416994 *hit;
    hit = 0;
    m = g->count2;
    p = g->peers;
    for (; m > 0; m--, p++) {
        if (p->state == 1) {
            if (NetMemcmp(p->name, name, 0x10) == 0) {
                ClearPeer_80416994(p);
            } else {
                hit = p;
            }
        }
    }
    return hit;
}

s16 NetIPv6ApplyNeighborAdvertisement(Msg_80416994 *msg, u8 *name, s16 len, s32 arg3, s32 arg4, s16 id) {
    s16 TLobby__sub_80410BA8(void *, void *, s16, void *);
    s32 TLobby__sub_80411604(s16, int, void *);
    Arg_80416994 a;
    Arg_80416994 b;
    Glob_80416994 *g = (Glob_80416994 *)&ipv6_neighbor_discovery_state;
    Ent_80416994 *e;

    if (TLobby__sub_80413C0C(msg->name, id) != 0) {
        a.p = msg->name;
        TLobby__sub_80411604(id, 1, &a);
        return 0;
    }
    if (TLobby__sub_80413AA0(msg->name, id) != 0) {
        return 0;
    }
    e = FindEnt_80416994(g, msg->name);
    if (e == 0) {
        return 0;
    }
    if ((e->flags ^ msg->flags) & 0x80) {
        if (len == 0 || name == 0 || (e->len == len && NetMemcmp(e->data, name, len) == 0) || (msg->flags & 0x20)) {
            if (msg->flags & 0x80) {
                e->flags |= 0x80;
                a.p = msg->name;
                TLobby__sub_80411604(id, 8, &a);
            } else {
                Peer_80416994 *hit;
                e->flags |= ~0x80;
                hit = ScanPeers_80416994(g, msg->name);
                if (hit == 0) {
                    a.p = msg->name;
                    TLobby__sub_80411604(id, 9, &a);
                } else {
                    b.v = (s32)hit->name;
                    b.p = msg->name;
                    TLobby__sub_80411604(id, 7, &b);
                }
            }
        }
    }
    switch (e->phase) {
    case 0:
        if (len != 0 && name != 0) {
            e->len = ((u32)len > 0x20) ? 0x20 : len;
            NetMemcpy(e->data, name, e->len);
            if (msg->flags & 0x40) {
                e->phase = 1;
                e->timer = g->delay1;
            } else {
                e->phase = 2;
                e->timer = g->delay2;
            }
            e->flags = msg->flags;
            if (e->sub != 0) {
                Pkt_80416994 *pkt = (Pkt_80416994 *)TLobby::alloc_free_entry();
                s16 ret;
                if (pkt == 0) {
                    ret = -0x10E;
                } else {
                    pkt->n = 0;
                    pkt->port = e->sub->port;
                    pkt->items[pkt->n].port = e->sub->port;
                    ((TLobby *)(pkt->items[pkt->n].val))->set_value_and_enable(e->sub->val);
                    pkt->n++;
                    ret = TLobby__sub_80410BA8(pkt, e->sub->addr, e->f8, e->data);
                    ((TUdpSocket *)pkt)->release_entry();
                }
                e->sub->state = 0;
                e->sub = 0;
                return ret;
            }
        }
        break;
    case 1:
        if (len != 0 && name != 0 && (e->len != len || NetMemcmp(e->data, name, len) != 0)) {
            if (msg->flags & 0x20) {
                e->len = ((u32)len > 0x20) ? 0x20 : len;
                NetMemcpy(e->data, name, e->len);
                e->flags = msg->flags;
                if (msg->flags & 0x40) {
                    e->phase = 1;
                    e->timer = g->delay1;
                    break;
                }
            }
            e->phase = 2;
            e->timer = g->delay2;
        }
        break;
    case 2:
    case 3:
    case 4:
        if (len != 0 && name != 0 && (e->len != len || NetMemcmp(e->data, name, len) != 0)) {
            if (msg->flags & 0x20) {
                e->len = ((u32)len > 0x20) ? 0x20 : len;
                NetMemcpy(e->data, name, e->len);
                if (msg->flags & 0x40) {
                    e->phase = 1;
                    e->timer = g->delay1;
                } else {
                    e->phase = 2;
                    e->timer = g->delay2;
                }
                e->flags = msg->flags;
            }
        } else if (msg->flags & 0x40) {
            e->phase = 1;
            e->timer = g->delay1;
            e->flags = msg->flags;
        }
        break;
    }
    return 0;
}
#pragma pop

s16 TLobby__sub_80417294(void *, u32, u8 *, void *);
s16 TLobby__sub_80417494(void *, u8 *, void *);

s16 NetIPv6HandleNeighborSolicitation(u8 *arg0, void *arg1, void *arg2, void *arg3) {
    s16 TLobby__sub_80413F0C(void *, void *);
    void TLobby__sub_80406EB8(void *, int);
    s16 TLobby__sub_80417028(void *, void *, void *, void *);
    s16 NetIPv6IsMulticast(u8 *arg0);
    s16 NetIPv6IsUnspecified(u8 *arg0);
    NetBufferRef sp30;
    IPv6NeighborSolicitation sp18;
    u8 *hdr;
    u32 len;
    s16 r;
    hdr = arg0 + 0x18;
    len = *(s16 *)(arg0 + 0x18);
    if (len < 0x18) {
        return -1;
    }
    if ((s16)NetIPv6IsUnspecified((u8 *)arg1) && TLobby__sub_80413F0C(arg2, arg3) == 0) {
        return -1;
    }
    ((TLobby *)((u8 *)&sp30))->set_value_and_enable((s32)&sp18);
    TLobby__sub_80406FD8(&sp30, hdr + 4, 0x18);
    if ((s16)NetIPv6IsMulticast(sp18.target.bytes)) {
        return -1;
    }
    len -= 0x18;
    if (len >= 8) {
        TLobby__sub_80406EB8(hdr + 4, 24);
        r = TLobby__sub_80416F58(hdr, len, arg1, arg3);
        if (r < 0) {
            return r;
        }
    }
    return TLobby__sub_80417028(&sp18, arg1, arg2, arg3);
}

s16 TLobby__sub_80416F58(u8 *msg, s32 len, void *addr, void *ifindex) {
    void TLobby__sub_80406EB8(void *, int);
    u8 *TLobby__sub_80406F0C(void *);
    s16 NetIPv6IsUnspecified(u8 *arg0);
    Ent_80416678 *TLobby__sub_804182DC(void *, void *, s16, s32);
    u8 *opt;
    s16 size;

    while (len >= 8) {
        opt = TLobby__sub_80406F0C(msg + 4);
        if (opt[1] == 0) {
            return -0x10E;
        }
        size = opt[1] << 3;
        len -= size;
        if (len < 0) {
            return -0x10E;
        }
        if ((s32)opt[0] != 1) {
            TLobby__sub_80406EB8(msg + 4, size);
        } else {
            if (NetIPv6IsUnspecified((u8 *)addr)) {
                return -0x10E;
            }
            {
                u8 *p = opt + 2;
                s16 l = size - 2;
                TLobby__sub_804182DC(addr, p, l, (s32)ifindex);
            }
            TLobby__sub_80406EB8(msg + 4, size);
        }
    }
    return 0;
}

s16 TLobby__sub_80417028(IPv6NeighborSolicitation *ns, u8 *src, u8 *dst, s16 iface) {
    NetSourceLinkLayerOption opt;
    NetIPv6SendParameters params;
    Arg_80416994 a;
    NetPacket *pkt;
    u8 flags;
    s16 len;
    s16 r;
    s16 NetIPv6IsUnspecified(u8 *arg0);
    s16 TLobby__sub_80413C0C(u8 *, s16);
    s16 TLobby__sub_80413AA0(u8 *, s16);
    s32 TLobby__sub_80411604(s16, int, void *);
    s16 NetIPv6IsMulticast(u8 *arg0);

    flags = 0;
    if (TLobby__sub_80413C0C(ns->target.bytes, iface) != 0) {
        a.p = ns->target.bytes;
        TLobby__sub_80411604(iface, 1, &a);
        return 0;
    }
    if (TLobby__sub_80413AA0(ns->target.bytes, iface) == 0) {
        return 0;
    }
    NetMemcpy(params.source.bytes, ns->target.bytes, 0x10);
    pkt = (NetPacket *)TLobby::alloc_free_entry();
    if (pkt == NULL) {
        return -0x10E;
    }
    pkt->fragment_count = 0;
    pkt->total_bytes = 0;
    if (NetIPv6IsUnspecified(src) != 0) {
        init_ipv6_all_nodes_multicast_address(params.destination.bytes, 2);
    } else {
        NetMemcpy(params.destination.bytes, src, 0x10);
    }
    if (NetIPv6IsMulticast(dst) != 0) {
        len = NetIPv6GetInterfaceLinkLayerAddress((s32)opt.address.bytes, sizeof(opt.address), iface);
        if (len > 0) {
            len += 2;
            opt.type = 2;
            opt.length_units = len >> 3;
            pkt->total_bytes += len;
            pkt->fragments[pkt->fragment_count].length = len;
            ((TLobby *)&pkt->fragments[pkt->fragment_count].buffer)->set_value_and_enable((s32)&opt);
            flags |= 0x20;
            pkt->fragment_count++;
        }
    }
    r = NetIPv6SendNeighborAdvertisement((Pkt_804179A4 *)pkt, ns->target.bytes, flags, (Sock_804179A4 *)&params, iface);
    ((TUdpSocket *)pkt)->release_entry();
    return r;
}

s16 NetIPv6HandleRouterAdvertisement(u8 *arg0, u8 *arg1, s32 arg2, void *arg3) {
    u8 sp28[8];
    u8 sp18[16];
    u32 n;
    u8 *p;
    s16 r;
    void TLobby__sub_80406EB8(void *, s32);
    s16 NetIPv6IsLinkLocal(u8 *arg0);

    p = arg0 + 0x18;
    n = *(s16 *)(arg0 + 0x18);
    if (n < 0x10U) {
        return -1;
    }
    r = NetIPv6IsLinkLocal(arg1);
    if (r == 0) {
        return -1;
    }
    ((TLobby *)sp28)->set_value_and_enable((s32)sp18);
    TLobby__sub_80406FD8(sp28, p + 4, 0x10);
    n -= 0x10;
    if (n >= 8U) {
        TLobby__sub_80406EB8(p + 4, 0x10);
        r = TLobby__sub_80417294(p, n, arg1, arg3);
        if (r < 0) {
            return r;
        }
    }
    return TLobby__sub_80417494(sp18, arg1, arg3);
}

typedef struct Hdr_804177A0 {
    s16 len;
    u8 pad[2];
    u8 data[8];
} Hdr_804177A0;
s16 NetIPv6HandleRouterSolicitation(u8 *o, s32 arg1, s32 arg2, s16 arg3) {
    s16 TLobby__sub_80417868(void *, u32, s32, s16);
    u8 b[8];
    u8 a[8];
    s32 pad;
    s32 v;
    Hdr_804177A0 *h = (Hdr_804177A0 *)(o + 0x18);
    u32 len = h->len;
    s16 r;
    void TLobby__sub_80406EB8(void *, s32);

    if (len < 8) {
        return -1;
    }
    ((TLobby *)b)->set_value_and_enable((s32)a);
    TLobby__sub_80406FD8(b, h->data, 8);
    len -= 8;
    if (len >= 8) {
        TLobby__sub_80406EB8(h->data, 8);
        r = TLobby__sub_80417868(h, len, arg1, arg3);
        if (r < 0) {
            return r;
        }
    }
    v = arg1;
    TLobby__sub_80411604(arg3, 0xC, &v);
    return 0;
}

typedef struct Arg_80417D1C { u8 *p; s32 v; } Arg_80417D1C;
s16 TLobby__sub_804137FC(u8 *, s16);

#pragma push
#pragma opt_propagation off
#pragma opt_common_subs on
struct G_80415B38;
#pragma push
#pragma dont_inline off
#pragma inline_depth(4)
s16 TLobby__sub_80417868(NetPacketFragment *frag, s32 len, u8 *src, s16 iface) {
    u8 *lladdr;
    u8 *h;
    s16 n;
    s16 l;
    Nbr_8041615C *nb;
    s16 NetIPv6IsUnspecified(u8 *arg0);
    Ent_80416678 *TLobby__sub_804182DC(void *, void *, s16, s16);

    lladdr = NULL;
    while (len >= 8) {
        h = TLobby__sub_80406F0C(&frag->buffer);
        if (h[1] == 0) {
            return -0x10E;
        }
        n = h[1] << 3;
        len -= n;
        if (len < 0) {
            return -0x10E;
        }
        if ((s32)h[0] != 1) {
            TLobby__sub_80406EB8(&frag->buffer, n);
        } else {
            if (NetIPv6IsUnspecified(src) == 0) {
                lladdr = h + 2;
                l = n - 2;
                TLobby__sub_804182DC(src, lladdr, l, iface);
            }
            TLobby__sub_80406EB8(&frag->buffer, n);
        }
    }
    if (lladdr != NULL) {
        nb = (Nbr_8041615C *)find_nbr_8041615C((G_8041615C *)&ipv6_neighbor_discovery_state, src);
        if (nb != NULL) {
            nb->flags &= ~0x80;
        }
    }
    return 0;
}
#pragma pop

s16 NetIPv6SendNeighborAdvertisement(Pkt_804179A4 *arg0, u8 *address, u8 arg2, Sock_804179A4 *arg3, s16 arg4) {
    Na_804179A4 na;
    Cur_804179A4 cur;
    E_804179A4 *e;
    void *p6;
    s32 TLobby__sub_80406FD8(void *, void *, int);
    s16 TLobby__sub_80410BA8(void *, void *, s16, void *);
    s16 TLobby__sub_80411040(void *, void *, int, void *, int);
    s32 TLobby__sub_80411604(s16, int, void *);
    s16 TLobby__sub_804136AC(s16 arg0);
    s16 TLobby__sub_80413934(void *, s16);
    s16 TLobby__sub_804145D4(void *, s16);
    s16 NetIPv6IsMulticast(u8 *arg0);
    s16 NetIPv6IsUnspecified(u8 *arg0);
    s16 NetIPv6SendMulticastNeighborProbe(u8 *arg0);
    E_804179A4 *NetIPv6FindOrSelectNeighborCacheEntry(void *, int, int);
    T_804179A4 *NetIPv6SelectDefaultRouter(void *arg0);
    Q_804179A4 *NetIPv6SelectPendingPacketSlot(void);
    if (NetIPv6IsMulticast(address) != 0) {
        return -0x10E;
    }
    if (NetIPv6IsUnspecified((u8 *)arg3) != 0) {
        s16 r = TLobby__sub_804145D4(arg3, arg4);
        if (r < 0) {
            return r;
        }
    } else if (TLobby__sub_80413934(arg3, arg4) == 0) {
        return -0x10E;
    }
    arg3->f24 = 0;
    arg3->f20 = 0;
    arg3->f27 = 0x3A;
    arg3->f26 = 0xFF;
    arg0->total += 0x18;
    arg0->seg[arg0->n].len = 0x18;
    ((TLobby *)(arg0->seg[arg0->n].buf))->set_value_and_enable((s32)&na);
    arg0->n++;
    na.type = 0x88;
    na.code = 0;
    na.flags = arg2;
    NetMemset(na.rsv, 0, 3);
    NetMemcpy(na.target, address, 0x10);
    if (NetIPv6IsMulticast(arg3->addr) != 0 || TLobby__sub_804136AC(arg4) == 0) {
        na.flags |= 0xFFBF;
        na.cksum = 0;
        na.cksum = TLobby__sub_80411040(arg3, arg3->addr, arg3->f27, arg0, 1);
        p6 = NULL;
    } else {
        e = NetIPv6FindOrSelectNeighborCacheEntry(arg3->addr, 0, 0);
        if (e == NULL) {
            return -0x10E;
        }
        na.flags |= 0x40;
        na.cksum = 0;
        na.cksum = TLobby__sub_80411040(arg3, arg3->addr, arg3->f27, arg0, 1);
        switch (e->f6) {
        case 1:
            break;
        case 3:
            break;
        case 2:
            p6 = e->f28;
            goto tail;
        }
        {
            s16 ret;
            u8 *src;
            u32 n;
            Q_804179A4 *q;
            void *b[2];
            void *a[2];
            Seg_804179A4 *seg;
            e->f8 = arg4;
            e->f4 = 0;
            e->fa = ((s16 *)&ipv6_neighbor_discovery_state)[0x15];
            e->f14 = 0;
            NetMemcpy(e->f16, arg3->addr, 0x10);
            if (e->f10 == NULL) {
                e->f10 = NetIPv6SelectPendingPacketSlot();
            }
            q = e->f10;
            n = arg0->n;
            src = q->f34;
            q->f30 = 0;
            seg = (Seg_804179A4 *)((u8 *)arg0 + n * 0xC);
            while (n != 0) {
                s16 l = seg->len;
                q->f30 += l;
                if (q->f30 > ((s16 *)&ipv6_neighbor_discovery_state)[0xA]) {
                    ret = -0x10E;
                    goto done;
                }
                ((TLobby *)((u8 *)&cur))->set_value_and_enable((s32)src);
                TLobby__sub_80406FD8(&cur, arg0->seg[n - 1].buf, l);
                src += l;
                seg--;
                n--;
            }
            ret = 0;
done:
            if (ret < 0) {
                if (e->f10 != NULL) {
                    e->f10->f3 = 0;
                    e->f10 = NULL;
                }
                if (e->fc & 0x80) {
                    T_804179A4 *t = NetIPv6SelectDefaultRouter(e->f16);
                    if (t == NULL) {
                        a[0] = e->f16;
                        TLobby__sub_80411604(e->f8, 6, a);
                    } else {
                        b[1] = t->f14;
                        b[0] = e->f16;
                        TLobby__sub_80411604(e->f8, 7, b);
                    }
                }
                e->f3 = 0;
                e->f26 = 0;
                return ret;
            }
            NetMemcpy((u8 *)e->f10 + 8, arg3, 0x28);
            return NetIPv6SendMulticastNeighborProbe((u8 *)e);
        }
    }
tail:
    return TLobby__sub_80410BA8(arg0, arg3, arg4, p6);
}
#pragma pop

s32 NetIPv6SendMulticastNeighborProbe(u8 *arg0) {
    s32 NetIPv6EmitNeighborSolicitation(NetPacket *, u8 *, NetIPv6SendParameters *, s32, u8 *);
    s32 TLobby__sub_804145D4(void *, int);
    u8 sp2C[0x18];
    u8 sp1C[0x10];
    Arg_80417D1C a7;
    Arg_80417D1C a6;
    s32 temp_r31;
    Ent_80418670 *temp_r3_3;
    u8 *free_entry;
    u8 *temp_r3_2;
    u8 *temp_r3_4;

    free_entry = TLobby::alloc_free_entry();
    if (free_entry == NULL) {
        temp_r3_2 = *(u8 **)((s8 *)arg0 + 0x10);
        if (temp_r3_2 != NULL) {
            *(s8 *)((s8 *)temp_r3_2 + 3) = 0;
            *(u8 **)((s8 *)arg0 + 0x10) = NULL;
        }
        if (*(u8 *)((s8 *)arg0 + 0xC) & 0x80) {
            temp_r3_3 = NetIPv6SelectDefaultRouter(arg0 + 0x16);
            if (temp_r3_3 == NULL) {
                a6.p = arg0 + 0x16;
                TLobby__sub_80411604(*(s16 *)((s8 *)arg0 + 8), 6, &a6);
            } else {
                a7.v = (s32)temp_r3_3->f14;
                a7.p = arg0 + 0x16;
                TLobby__sub_80411604(*(s16 *)((s8 *)arg0 + 8), 7, &a7);
            }
        }
        *(s8 *)((s8 *)arg0 + 3) = 0;
        *(s16 *)((s8 *)arg0 + 0x26) = 0;
        return -0x10E;
    }
    *(s32 *)((s8 *)free_entry + 4) = 0;
    *(s32 *)((s8 *)free_entry + 8) = 0;
    temp_r3_4 = *(u8 **)((s8 *)arg0 + 0x10);
    if (temp_r3_4 != NULL && TLobby__sub_804137FC(temp_r3_4 + 8, *(s16 *)((s8 *)arg0 + 8)) != 0) {
        NetMemcpy(sp1C, *(u8 **)((s8 *)arg0 + 0x10) + 8, 0x10);
    } else {
        TLobby__sub_804145D4(sp1C, *(s16 *)((s8 *)arg0 + 8));
    }
    NetIPv6MakeSolicitedNodeMulticastAddress(sp2C, (u8 *)(arg0 + 0x16));
    temp_r31 = NetIPv6EmitNeighborSolicitation((NetPacket *)free_entry, arg0 + 0x16, (NetIPv6SendParameters *)sp1C, *(s16 *)((s8 *)arg0 + 8), NULL);
    ((TUdpSocket *)free_entry)->release_entry();
    return temp_r31;
}

typedef struct Arg_80417E60 { u8 *p; s32 v; } Arg_80417E60;

s32 NetIPv6SendUnicastNeighborProbe(u8 *arg0) {
    s32 NetIPv6EmitNeighborSolicitation(NetPacket *, u8 *, NetIPv6SendParameters *, s32, u8 *);
    s32 TLobby__sub_804145D4(void *, int);
    u8 sp2C[0x18];
    u8 sp1C[0x10];
    Arg_80417E60 a7;
    Arg_80417E60 a6;
    s32 temp_r31;
    Ent_80418670 *temp_r3_3;
    u8 *free_entry;
    u8 *temp_r3_2;
    u8 *temp_r3_4;

    free_entry = TLobby::alloc_free_entry();
    if (free_entry == NULL) {
        temp_r3_2 = *(u8 **)((s8 *)arg0 + 0x10);
        if (temp_r3_2 != NULL) {
            *(s8 *)((s8 *)temp_r3_2 + 3) = 0;
            *(u8 **)((s8 *)arg0 + 0x10) = NULL;
        }
        if (*(u8 *)((s8 *)arg0 + 0xC) & 0x80) {
            temp_r3_3 = NetIPv6SelectDefaultRouter(arg0 + 0x16);
            if (temp_r3_3 == NULL) {
                a6.p = arg0 + 0x16;
                TLobby__sub_80411604(*(s16 *)((s8 *)arg0 + 8), 6, &a6);
            } else {
                a7.v = (s32)temp_r3_3->f14;
                a7.p = arg0 + 0x16;
                TLobby__sub_80411604(*(s16 *)((s8 *)arg0 + 8), 7, &a7);
            }
        }
        *(s8 *)((s8 *)arg0 + 3) = 0;
        *(s16 *)((s8 *)arg0 + 0x26) = 0;
        return -0x10E;
    }
    *(s32 *)((s8 *)free_entry + 4) = 0;
    *(s32 *)((s8 *)free_entry + 8) = 0;
    temp_r3_4 = *(u8 **)((s8 *)arg0 + 0x10);
    if (temp_r3_4 != NULL && TLobby__sub_804137FC(temp_r3_4 + 8, *(s16 *)((s8 *)arg0 + 8)) != 0) {
        NetMemcpy(sp1C, *(u8 **)((s8 *)arg0 + 0x10) + 8, 0x10);
    } else {
        TLobby__sub_804145D4(sp1C, *(s16 *)((s8 *)arg0 + 8));
    }
    NetMemcpy(sp2C, arg0 + 0x16, 0x10);
    temp_r31 = NetIPv6EmitNeighborSolicitation((NetPacket *)free_entry, arg0 + 0x16, (NetIPv6SendParameters *)sp1C, *(s16 *)((s8 *)arg0 + 8), arg0 + 0x28);
    ((TUdpSocket *)free_entry)->release_entry();
    return temp_r31;
}

s16 NetIPv6EmitNeighborSolicitation(NetPacket *net_packet, u8 *target, NetIPv6SendParameters *addr, s16 iface, u8 *link_address) {
    s16 NetIPv6IsMulticast(u8 *);
    s16 NetIPv6IsUnspecified(u8 *);
    s16 TLobby__sub_80410BA8(NetPacket *, NetIPv6SendParameters *, s16, u8 *);
    NetIcmpv6NeighborSolicitation message;
    NetSourceLinkLayerOption option;
    s16 result;
    s16 option_length;
    if (NetIPv6IsMulticast(target) != 0) {
        return -0x10E;
    }
    if (NetIPv6IsMulticast((u8 *)(&addr->destination)) != 0) {
        link_address = NULL;
    }
    if (NetIPv6IsUnspecified((u8 *)(&addr->source)) == 0) {
        result = TLobby__sub_80414090((u8 *)(&addr->source), iface);
        if (result < 0) {
            return result;
        }
        result = NetIPv6GetInterfaceLinkLayerAddress((s32)(&option.address), 0x20, iface);
        if (result > 0) {
            option_length = result + 2;
            option.type = 1;
            option.length_units = (u8)(option_length >> 3);
            net_packet->total_bytes += option_length;
            net_packet->fragments[net_packet->fragment_count].length = option_length;
            ((TLobby *)(&net_packet->fragments[net_packet->fragment_count].buffer))->set_value_and_enable((s32)(&option));
            net_packet->fragment_count += 1;
        }
    }
    addr->traffic_class_bits = 0;
    addr->flow_label = 0;
    addr->next_header = 0x3A;
    addr->hop_limit = 0xFF;
    net_packet->total_bytes += sizeof(message);
    net_packet->fragments[net_packet->fragment_count].length = sizeof(message);
    ((TLobby *)(&net_packet->fragments[net_packet->fragment_count].buffer))->set_value_and_enable((s32)(&message));
    net_packet->fragment_count += 1;
    message.header.type = 0x87;
    message.header.code = 0;
    message.header.reserved = 0;
    NetMemcpy(&message.target, target, sizeof(message.target));
    message.header.checksum = 0;
    message.header.checksum = TLobby__sub_80411040(&addr->source, &addr->destination, addr->next_header, net_packet, 1);
    return TLobby__sub_80410BA8(net_packet, addr, iface, link_address);
}

struct E_804184DC {
    u8 pad0[3];
    u8 used;
    s16 kind;
    s16 state;
    u8 pad8[2];
    s16 age;
    u8 padC[0xA];
    u8 addr[0x10];
    s16 klen;
    u8 key[0x20];
};

#pragma push
#pragma optimization_level 3
#pragma dont_inline on
typedef char Layout_pointer_size[sizeof(void *) == 4 ? 1 : -1];
typedef char Layout_word_size[sizeof(u32) == 4 ? 1 : -1];
typedef char Layout_NetBufferRef_size[sizeof(NetBufferRef) == 8 ? 1 : -1];
typedef char Layout_NetBufferRef_kind[offsetof(NetBufferRef, kind) == 4 ? 1 : -1];
typedef char Layout_NetBufferRef_value[offsetof(NetBufferRef, value) == 0 ? 1 : -1];
typedef char Layout_IPv6Address_size[sizeof(IPv6Address) == 16 ? 1 : -1];
typedef char Layout_IPv6Address_bytes[offsetof(IPv6Address, bytes) == 0 ? 1 : -1];
typedef char Layout_IPv6NeighborSolicitation_size[sizeof(IPv6NeighborSolicitation) == 24 ? 1 : -1];
typedef char Layout_IPv6NeighborSolicitation_header[offsetof(IPv6NeighborSolicitation, header) == 0 ? 1 : -1];
typedef char Layout_IPv6NeighborSolicitation_target[offsetof(IPv6NeighborSolicitation, target) == 8 ? 1 : -1];
typedef char Layout_NetPacketFragment_size[sizeof(NetPacketFragment) == 12 ? 1 : -1];
typedef char Layout_NetPacketFragment_buffer[offsetof(NetPacketFragment, buffer) == 4 ? 1 : -1];
typedef char Layout_NetPacketFragment_length[offsetof(NetPacketFragment, length) == 0 ? 1 : -1];
typedef char Layout_NetPacket_size[sizeof(NetPacket) == 156 ? 1 : -1];
typedef char Layout_NetPacket_fragment_count[offsetof(NetPacket, fragment_count) == 4 ? 1 : -1];
typedef char Layout_NetPacket_fragments[offsetof(NetPacket, fragments) == 12 ? 1 : -1];
typedef char Layout_NetPacket_in_use[offsetof(NetPacket, in_use) == 0 ? 1 : -1];
typedef char Layout_NetPacket_total_bytes[offsetof(NetPacket, total_bytes) == 8 ? 1 : -1];
typedef char Layout_NetIPv6SendParameters_size[sizeof(NetIPv6SendParameters) == 40 ? 1 : -1];
typedef char Layout_NetIPv6SendParameters_destination[offsetof(NetIPv6SendParameters, destination) == 16 ? 1 : -1];
typedef char Layout_NetIPv6SendParameters_flow_label[offsetof(NetIPv6SendParameters, flow_label) == 32 ? 1 : -1];
typedef char Layout_NetIPv6SendParameters_hop_limit[offsetof(NetIPv6SendParameters, hop_limit) == 38 ? 1 : -1];
typedef char Layout_NetIPv6SendParameters_next_header[offsetof(NetIPv6SendParameters, next_header) == 39 ? 1 : -1];
typedef char Layout_NetIPv6SendParameters_source[offsetof(NetIPv6SendParameters, source) == 0 ? 1 : -1];
typedef char Layout_NetIPv6SendParameters_traffic_class_bits[offsetof(NetIPv6SendParameters, traffic_class_bits) == 36 ? 1 : -1];
typedef char Layout_NetLinkLayerAddressBuffer_size[sizeof(NetLinkLayerAddressBuffer) == 32 ? 1 : -1];
typedef char Layout_NetLinkLayerAddressBuffer_bytes[offsetof(NetLinkLayerAddressBuffer, bytes) == 0 ? 1 : -1];
typedef char Layout_NetSourceLinkLayerOption_size[sizeof(NetSourceLinkLayerOption) == 34 ? 1 : -1];
typedef char Layout_NetSourceLinkLayerOption_address[offsetof(NetSourceLinkLayerOption, address) == 2 ? 1 : -1];
typedef char Layout_NetSourceLinkLayerOption_length_units[offsetof(NetSourceLinkLayerOption, length_units) == 1 ? 1 : -1];
typedef char Layout_NetSourceLinkLayerOption_type[offsetof(NetSourceLinkLayerOption, type) == 0 ? 1 : -1];
typedef char Layout_NetIcmpv6Header_size[sizeof(NetIcmpv6Header) == 8 ? 1 : -1];
typedef char Layout_NetIcmpv6Header_checksum[offsetof(NetIcmpv6Header, checksum) == 2 ? 1 : -1];
typedef char Layout_NetIcmpv6Header_code[offsetof(NetIcmpv6Header, code) == 1 ? 1 : -1];
typedef char Layout_NetIcmpv6Header_reserved[offsetof(NetIcmpv6Header, reserved) == 4 ? 1 : -1];
typedef char Layout_NetIcmpv6Header_type[offsetof(NetIcmpv6Header, type) == 0 ? 1 : -1];
typedef char Layout_NetIcmpv6NeighborSolicitation_size[sizeof(NetIcmpv6NeighborSolicitation) == 24 ? 1 : -1];
typedef char Layout_NetIcmpv6NeighborSolicitation_header[offsetof(NetIcmpv6NeighborSolicitation, header) == 0 ? 1 : -1];
typedef char Layout_NetIcmpv6NeighborSolicitation_target[offsetof(NetIcmpv6NeighborSolicitation, target) == 8 ? 1 : -1];
typedef char Layout_NetIcmpv6RouterSolicitation_size[sizeof(NetIcmpv6RouterSolicitation) == 8 ? 1 : -1];
typedef char Layout_NetIcmpv6RouterSolicitation_header[offsetof(NetIcmpv6RouterSolicitation, header) == 0 ? 1 : -1];
s32 NetIPv6EmitRouterSolicitation(NetPacket *net_packet, NetIPv6SendParameters *addr, s32 arg2) {
    s32 TLobby__sub_80410BA8(NetPacket *, NetIPv6SendParameters *, s32, void *);
    s16 NetIPv6GetInterfaceLinkLayerAddress(s32, s16, s32);
    s16 NetIPv6IsMulticast(u8 *);
    s16 NetIPv6IsUnspecified(u8 *);
    NetIcmpv6RouterSolicitation message;
    NetSourceLinkLayerOption option;
    s16 temp_r3;
    s16 temp_r5;
    if ((NetIPv6IsMulticast((u8 *)(&addr->destination))) == 0) {
        return -0x10E;
    }
    if ((NetIPv6IsUnspecified((u8 *)(&addr->source))) == 0) {
        temp_r3 = NetIPv6GetInterfaceLinkLayerAddress((s32)(&option.address), (s16)(0x20), arg2);
        if (temp_r3 > 0) {
            temp_r5 = temp_r3 + 2;
            option.type = 1;
            option.length_units = (u8) (temp_r5 >> 3);
            net_packet->total_bytes += temp_r5;
            net_packet->fragments[net_packet->fragment_count].length = temp_r5;
            ((TLobby *)(&net_packet->fragments[net_packet->fragment_count].buffer))->set_value_and_enable((s32)(&option));
            net_packet->fragment_count += 1;
        }
    }
    addr->traffic_class_bits = 0;
    addr->flow_label = 0;
    addr->next_header = 0x3A;
    addr->hop_limit = 0xFF;
    net_packet->total_bytes += 8;
    net_packet->fragments[net_packet->fragment_count].length = 8;
    ((TLobby *)(&net_packet->fragments[net_packet->fragment_count].buffer))->set_value_and_enable((s32)(&message));
    net_packet->fragment_count += 1;
    message.header.type = 0x85;
    message.header.code = 0;
    message.header.reserved = 0;
    message.header.checksum = 0;
    message.header.checksum = TLobby__sub_80411040((const IPv6Address *)(&addr->source), (const IPv6Address *)(&addr->destination), addr->next_header, (const NetPacket *)(net_packet), (s16)(1));
    return TLobby__sub_80410BA8(net_packet, addr, arg2, NULL);
}
#pragma pop

E_804184DC *NetIPv6FindOrSelectNeighborCacheEntry(u8 *addr, u8 *key, s16 klen) {
    E_804184DC *e;
    s16 n;
    E_804184DC *oldest_b;
    E_804184DC *oldest_a;
    E_804184DC *empty;
    s16 age_b;
    s16 age_a;

    oldest_a = NULL;
    empty = NULL;
    {
        s16 m = ipv6_neighbor_discovery_state.maxage;
        age_b = m;
        age_a = m;
    }
    if (addr == NULL) {
        return NULL;
    }
    n = ipv6_neighbor_discovery_state.nb;
    e = (E_804184DC *)ipv6_neighbor_discovery_state.b;
    while (n > 0) {
        if (e->used != 1) {
            if (empty == NULL) {
                empty = e;
            }
        } else if (NetMemcmp(e->addr, addr, 0x10) == 0) {
            if (klen == 0) {
                if (e->klen != 0) {
                    e->state = 2;
                } else {
                    e->state = 3;
                }
            } else if (e->klen != klen || NetMemcmp(e->key, key, klen) != 0) {
                e->state = 2;
            } else {
                e->state = 3;
            }
            return e;
        } else {
            switch (e->kind) {
            case 2:
                if (e->age < age_a) {
                    oldest_a = e;
                    age_a = e->age;
                }
                break;
            default:
                if (e->age < age_b) {
                    oldest_b = e;
                    age_b = e->age;
                }
                break;
            }
        }
        n--;
        e++;
    }
    if (empty != NULL) {
        empty->state = 0;
        return empty;
    }
    if (oldest_a != NULL) {
        oldest_a->state = 1;
        return oldest_a;
    }
    oldest_b->state = 1;
    return oldest_b;
}

typedef struct G_80418670 { u8 pad0[4]; s16 f4; u8 pad6[0xA]; Ent_80418670 *f10; } G_80418670;

Ent_80418670 *NetIPv6SelectDefaultRouter(void *arg0) {
    s16 n;
    Ent_80418670 *e;
    Ent_80418670 *found;
    Ent_80418670 *best;

    found = NULL;
    best = NULL;
    n = (*(G_80418670 *)&ipv6_neighbor_discovery_state).f4;
    e = (*(G_80418670 *)&ipv6_neighbor_discovery_state).f10;
    while (n > 0) {
        if (e->f3 == 1) {
            if (NetMemcmp(e->f14, arg0, 0x10) == 0) {
                found = e;
                e->f6++;
            } else if (best == NULL) {
                best = e;
            } else if (e->f6 <= best->f6) {
                best = e;
            }
        }
        n--;
        e++;
    }
    if (best == NULL) {
        return found;
    }
    return best;
}

typedef struct Ra_80418734 { u8 pad0[6]; s16 router_lifetime; u32 reachable_time; u32 retrans_timer; } Ra_80418734;
typedef struct Rtr_80418734 { u8 pad0[3]; u8 state; s16 id; s16 f6; s16 lifetime; u8 padA[2]; s32 reachable_time; s32 retrans_timer; u8 addr[0x10]; } Rtr_80418734;
typedef struct G_80418734 { u8 pad0[4]; s16 nrtr; u8 pad6[0xA]; Rtr_80418734 *rtrs; u8 pad14[0x10]; s16 maxage; s16 reachable_time; s16 retrans_timer; s16 f2A; } G_80418734;

s32 TLobby__sub_80418734(u8 *addr, Ra_80418734 *ra, s16 id) {
    G_80418734 *g = (G_80418734 *)&ipv6_neighbor_discovery_state;
    s16 n;
    Rtr_80418734 *e;
    Rtr_80418734 *r;
    Rtr_80418734 *oldest;
    Rtr_80418734 *slot;
    s16 min;

    slot = NULL;
    min = g->maxage;
    n = g->nrtr;
    r = g->rtrs;
    while (n > 0) {
        if (r->state != 1) {
            if (slot == NULL) {
                slot = r;
            }
        } else if (NetMemcmp(r->addr, addr, 0x10) == 0) {
            r->id = id;
            r->lifetime = ra->router_lifetime;
            if (ra->reachable_time != 0) {
                r->reachable_time = ra->reachable_time;
            }
            if (ra->retrans_timer != 0) {
                r->retrans_timer = ra->retrans_timer;
            }
            return 0;
        } else if (r->lifetime < min) {
            oldest = r;
            min = r->lifetime;
        }
        n--;
        r++;
    }
    if (slot != NULL) {
        slot->state = 1;
        e = slot;
    } else if (oldest != NULL) {
        e = oldest;
    } else {
        return -0x10E;
    }
    NetMemcpy(e->addr, addr, 0x10);
    e->id = id;
    e->lifetime = ra->router_lifetime;
    if (ra->reachable_time != 0) {
        e->reachable_time = ra->reachable_time;
        g->reachable_time = e->reachable_time / 1000;
    }
    if (ra->retrans_timer != 0) {
        e->retrans_timer = ra->retrans_timer;
        g->retrans_timer = e->retrans_timer / 1000;
        g->f2A = e->retrans_timer / 1000 + 1;
    }
    return 0;
}

struct Ent_804188E4 { u8 pad0[3]; u8 f3; s16 f4; u8 pad6[0x32]; };
struct Rec_804188E4 { u8 pad0[3]; u8 f3; u8 pad4[0xC]; Ent_804188E4 *f10; u8 pad14[0x34]; };
struct G_804188E4 { s16 n0; s16 n2; u8 pad4[4]; Ent_804188E4 *e8; Rec_804188E4 *rC; u8 pad10[0x14]; s16 f24; };
#pragma push
#pragma dont_inline off
#pragma inline_depth(4)
inline Rec_804188E4 *find_804188E4(G_804188E4 *g, Ent_804188E4 *e) {
    s16 n = g->n2;
    Rec_804188E4 *r = g->rC;
    while (n > 0) {
        if (r->f3 == 1 && r->f10 == e) {
            return r;
        }
        n--;
        r++;
    }
    return NULL;
}

Ent_804188E4 *NetIPv6SelectPendingPacketSlot(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4, Ent_804188E4 *best) {
    Ent_804188E4 *free_;
    G_804188E4 *g = (G_804188E4 *)&ipv6_neighbor_discovery_state;
    s16 v;
    s16 n;
    Ent_804188E4 *e;
    s16 bestv;
    Rec_804188E4 *r;

    bestv = g->f24;
    free_ = NULL;
    n = g->n0;
    e = g->e8;
    while (n > 0) {
        if (e->f3 != 1) {
            if (free_ == NULL) {
                free_ = e;
            }
        } else {
            v = e->f4;
            if (v < bestv) {
                best = e;
                bestv = v;
            }
        }
        n--;
        e++;
    }
    if (free_ != NULL) {
        free_->f3 = 1;
        return free_;
    }
    r = find_804188E4(g, best);
    if (r != NULL) {
        r->f10 = NULL;
    }
    return best;
}

#pragma pop

void NetIPv6ApplyNeighborDiscoveryDefaults(u8 *arg0) {
    if (*(s16 *)((s8 *)arg0 + 0x14) == 0) {
        *(s16 *)((s8 *)arg0 + 0x14) = 0x5DC;
    }
    if (*(s16 *)((s8 *)arg0 + 0x1C) == 0) {
        *(s16 *)((s8 *)arg0 + 0x1C) = 3;
    }
    if (*(s16 *)((s8 *)arg0 + 0x1E) == 0) {
        *(s16 *)((s8 *)arg0 + 0x1E) = 3;
    }
    if (*(s16 *)((s8 *)arg0 + 0x20) == 0) {
        *(s16 *)((s8 *)arg0 + 0x20) = 1;
    }
    if (*(s16 *)((s8 *)arg0 + 0x22) == 0) {
        *(s16 *)((s8 *)arg0 + 0x22) = 3;
    }
    if (*(s16 *)((s8 *)arg0 + 0x24) == 0) {
        *(s16 *)((s8 *)arg0 + 0x24) = 0x1900;
    }
    if (*(s16 *)((s8 *)arg0 + 0x26) == 0) {
        *(s16 *)((s8 *)arg0 + 0x26) = 0x1E;
    }
    if (*(s16 *)((s8 *)arg0 + 0x28) == 0) {
        *(s16 *)((s8 *)arg0 + 0x28) = 1;
    }
    if (*(s16 *)((s8 *)arg0 + 0x2A) == 0) {
        *(s16 *)((s8 *)arg0 + 0x2A) = *(s16 *)((s8 *)arg0 + 0x28) + 1;
    }
    if (*(s16 *)((s8 *)arg0 + 0x2C) == 0) {
        *(s16 *)((s8 *)arg0 + 0x2C) = 6;
    }
}

struct A_80418ACC { s8 c0; s8 c1; s8 c2; s8 c3; s16 f4; u8 pad6[0x2E]; };
struct B_80418ACC { s8 c0; s8 c1; s8 c2; s8 c3; s16 f4; u8 pad6[0x12]; };
struct G_80418ACC {
    s16 na;
    s16 nb;
    u8 pad4[4];
    A_80418ACC *a;
    B_80418ACC *b;
    s32 f10;
    s32 f14;
};
extern G_80418ACC packet_fragment_pool_state;
s32 TLobby__sub_80418A7C(void) {
    G_80418ACC *g = &packet_fragment_pool_state;
    NetUnregisterTimer((void *)TLobby::update_timeout_entries);
    TLobby__sub_803F89A0(g);
    g->na = 0;
    g->nb = 0;
    return 0;
}

s32 TLobby::init_packet_fragment_pools() {
    s16 i;
    A_80418ACC *a;
    B_80418ACC *b;
    G_80418ACC *g = &packet_fragment_pool_state;

    TLobby__sub_803F89A4((u8 *)&packet_fragment_pool_state);
    g->f14 = 0;
    g->f10 = 0;
    a = g->a;
    for (i = 0; i < g->na; i++) {
        NetMemset(a, 0, sizeof(A_80418ACC));
        a->c0 = 0x46;
        a->c1 = 0x50;
        a->c2 = 0x4B;
        a->c3 = i;
        a->f4 = 0;
        a++;
    }
    b = g->b;
    for (i = 0; i < g->nb; i++) {
        NetMemset(b, 0, sizeof(B_80418ACC));
        b->c0 = 0x46;
        b->c1 = 0x52;
        b->c2 = 0x47;
        b->c3 = i;
        b->f4 = 0;
        b++;
    }
    NetRegisterTimer(1000, (s16)(1), (NetTimerCallback)(TLobby::update_timeout_entries));
    return 0;
}

struct E_80418BD8 { u8 pad[0xC]; };
struct A_80418BD8 { u8 pad[4]; u32 n; u8 pad2[8]; E_80418BD8 e[1]; };
s32 TUdpSocket__sub_80418BD8(A_80418BD8 *a) {
    u32 i;
    A_80418BD8 *b = a;
    for (i = 0; i < b->n; i++) {
        TLobby__sub_80406B6C((O_80406B6C *)&b->e[i]);
    }
    return 0;
}

struct N_80419258 { u8 pad0[4]; s16 f4; u8 pad6[2]; O_80406B6C o; u16 f10; u16 f12; N_80419258 *next; };
struct Addr_80419258 { s32 family; u8 data[0x10]; };
struct E_80419258 { u8 pad0[4]; s16 f4; u8 pad6[2]; Addr_80419258 addr; u32 port; u16 f20; u8 f22; u8 f23; s16 f24; u8 pad26[2]; E_80419258 *next; N_80419258 *list; N_80419258 *f30; };
struct G_80419258 { s16 count; s16 sub; u8 pad4[4]; E_80419258 *ents; u8 padC[4]; E_80419258 *head; E_80419258 *tail; };
NetPacket *TLobby__sub_80418D7C(E_80419258 *e, s32 data, u16 len, u16 off, u16 hdrlen, u8 more, s16 iface);
E_80419258 *TLobby__sub_8041955C(u8 *addr, s32 port, u8 ttl);
s32 TLobby__sub_80419470(u8 *addr, u32 id);

NetPacket *TLobby__sub_80418C40(s32 data, u16 len, u16 hdrlen, u8 ttl, u32 id, u8 *addr, u16 off, u8 more, s16 iface) {
    NetPacket *pkt;
    G_80419258 *g = (G_80419258 *)&packet_fragment_pool_state;
    s16 n;
    NetPacket *found;
    E_80419258 *e;

    for (e = g->head, n = 0; e != NULL && n < g->count; e = e->next, n++) {
        if (((TLobby *)&e->addr)->compare_sockaddr(addr) == 0 && e->port == id) {
            found = TLobby__sub_80418D7C(e, data, len, off, hdrlen, more, iface);
            if (found == NULL) {
                return NULL;
            }
            TLobby__sub_80419470(addr, id);
            return found;
        }
    }
    e = TLobby__sub_8041955C(addr, id, ttl);
    if (e == NULL) {
        return NULL;
    }
    pkt = TLobby__sub_80418D7C(e, data, len, off, hdrlen, more, iface);
    if (pkt == NULL) {
        return NULL;
    }
    TLobby__sub_80419470(addr, id);
    return pkt;
}

s16 TLobby__sub_80419374(E_80419258 *e);

void TLobby::update_timeout_entries() {
    G_80419258 *g;
    E_80419258 **head;
    E_80419258 **tail;
    s16 n;
    s16 m;
    N_80419258 *p;
    N_80419258 *q;
    E_80419258 *e;
    E_80419258 *cur;
    E_80419258 *prev;

    g = (G_80419258 *)&packet_fragment_pool_state;
    head = &g->head;
    tail = &g->tail;

    prev = NULL;
    n = 0;
    cur = *head;
    while (cur != NULL && n < g->count) {
        if (cur->f22 != 0) {
            cur->f22--;
        }
        if (cur->f22 != 0) {
            prev = cur;
            cur = cur->next;
        } else {
            TLobby__sub_80419374(cur);
            p = cur->list;
            m = 0;
            while (p != NULL && m < g->sub) {
                q = p;
                p = p->next;
                TLobby__sub_80406B6C(&q->o);
                q->f4 = 0;
                m++;
                q->next = 0;
            }
            if (prev != NULL) {
                prev->next = cur->next;
            } else {
                *head = cur->next;
            }
            if (*tail == cur) {
                *tail = prev;
            }
            e = cur;
            cur = cur->next;
            e->f4 = 0;
            e->next = 0;
            e->f24 = 0;
        }
        n++;
    }
}

struct IcmpError_80419374 {
    u8 type;
    u8 code;
    u16 checksum;
    u32 unused;
};

s16 TLobby__sub_80419374(E_80419258 *e) {
    IcmpError_80419374 v4;
    IcmpError_80419374 v6;
    u8 *data;
    u16 len;
    s16 TUdpSocket__sub_8040CE58(IcmpError_80419374 *icmp, u8 *data, s16 len, s16 id);
    s16 TLobby__sub_8040D510(IcmpError_80419374 *icmp, u8 *data, s16 len, s16 id);

    if (e->list == NULL) {
        return 0;
    }
    if (e->list->f10 != 0) {
        return 0;
    }
    data = TLobby__sub_80406F0C(&e->list->o);
    if (data == NULL) {
        return -1;
    }
    len = e->f20 + e->list->f12;
    switch (e->addr.family) {
    case 4:
        v4.type = 11;
        v4.code = 1;
        v4.unused = 0;
        return TUdpSocket__sub_8040CE58(&v4, data, len, e->f24);
    case 6:
        v6.type = 3;
        v6.code = 1;
        v6.unused = 0;
        return TLobby__sub_8040D510(&v6, data, len, e->f24);
    }
    return -1;
}

s32 TLobby__sub_80419470(u8 *addr, u32 id) {
    G_80419258 *g = (G_80419258 *)&packet_fragment_pool_state;
    E_80419258 **head;
    s16 n;
    E_80419258 *cur;
    E_80419258 *prev;

    if (*(head = &g->head) == NULL) {
        return -1;
    }
    cur = *head;
    prev = NULL;
    n = 0;
    while (cur != NULL && n < g->count) {
        if (((TLobby *)&cur->addr)->compare_sockaddr(addr) == 0 && cur->port == id) {
            E_80419258 **tail;
            if (prev != NULL) {
                prev->next = cur->next;
            } else {
                *head = cur->next;
            }
            if (*(tail = &g->tail) == cur) {
                *tail = prev;
            }
            cur->f4 = 0;
            cur->next = NULL;
            cur->f24 = 0;
            return 0;
        }
        prev = cur;
        cur = cur->next;
        n++;
    }
    return -1;
}

s32 TLobby__sub_8041979C(void);

#pragma push
#pragma dont_inline off
#pragma inline_depth(4)
#pragma opt_common_subs on
inline E_80419258 *alloc_entry_8041955C(G_80419258 *g) {
    E_80419258 *e = ((G_80419258 *)&packet_fragment_pool_state)->ents;
    s16 n = g->count;
    s16 i;

    for (i = 0; i < n; i++, e++) {
        if (e->f4 == 0) {
            e->f4 = 1;
            e->f20 = 0;
            e->port = 0;
            NetMemset(&e->addr, 0, sizeof(e->addr));
            e->f22 = 0;
            e->f23 = 0;
            e->next = NULL;
            e->f30 = NULL;
            e->list = NULL;
            return e;
        }
    }
    return NULL;
}

E_80419258 *TLobby__sub_8041955C(u8 *addr, s32 port, u8 ttl) {
    G_80419258 *g = (G_80419258 *)&packet_fragment_pool_state;
    E_80419258 *e;
    E_80419258 **head;

    e = alloc_entry_8041955C(g);
    if (e == NULL) {
        TLobby__sub_8041979C();
        e = alloc_entry_8041955C(g);
        if (e == NULL) {
            return NULL;
        }
    }
    if (*(head = &g->head) == NULL) {
        g->tail = e;
        *head = e;
    } else {
        g->tail->next = e;
        g->tail = e;
    }
    NetMemcpy(&e->addr, addr, sizeof(e->addr));
    e->port = port;
    e->f23 = 0;
    e->f22 = ttl;
    e->next = NULL;
    e->f30 = NULL;
    e->list = NULL;
    return e;
}
#pragma pop

struct N_804196EC { u8 pad0[4]; s16 f4; u8 pad6[2]; O_80406B6C o; u8 pad10[4]; N_804196EC *next; };
struct E_804196EC { u8 pad0[4]; s16 f4; u8 pad6[0x1E]; s16 f24; u8 pad26[2]; s32 f28; N_804196EC *list; u8 pad30[4]; };
struct G_804196EC { s16 count; u8 pad2[6]; E_804196EC *ents; u8 padC[4]; E_804196EC *p10; E_804196EC *p14; };

s32 TLobby__sub_80406B6C(O_80406B6C *o);

s32 TLobby::reset_other_connection_lists() {
    E_804196EC *self = (E_804196EC *)this;
    G_804196EC *g = (G_804196EC *)&packet_fragment_pool_state;
    N_804196EC *p;
    N_804196EC *cur;
    E_804196EC *e;
    s16 n;

    n = g->count;
    e = g->ents;
    for (; n > 0; n--, e++) {
        if (e->f4 == 1 && e != self) {
            p = e->list;
            while (p != NULL) {
                cur = p;
                p = p->next;
                TLobby__sub_80406B6C(&cur->o);
                cur->f4 = 0;
                cur->next = 0;
            }
            e->f4 = 0;
            e->f28 = 0;
            e->f24 = 0;
        }
    }
    self->f28 = 0;
    g->p10 = self;
    g->p14 = self;
    return 0;
}

struct G_8041979C { s16 count; s16 sub; u8 pad4[4]; E_80419258 *ents; N_80419258 *nodes; E_80419258 *head; E_80419258 *tail; };

s32 TLobby__sub_8041979C(void) {
    G_8041979C *g = (G_8041979C *)&packet_fragment_pool_state;
    E_80419258 *e;
    s16 n;
    s16 m;
    N_80419258 *p;

    n = g->count;
    e = g->ents;
    for (; n > 0; n--, e++) {
        if (e->f4 == 1) {
            e->f4 = 0;
            e->next = NULL;
            e->f24 = 0;
        }
    }
    m = g->sub;
    p = g->nodes;
    for (; m > 0; m--, p++) {
        if (p->f4 == 1) {
            TLobby__sub_80406B6C(&p->o);
            p->f4 = 0;
            p->next = NULL;
        }
    }
    g->head = NULL;
    g->tail = NULL;
    return 0;
}

u16 TUdpSocket__sub_80419864(void *buf, s16 len) {
    union {
        u16 s;
        u8 c[2];
    } su;
    u16 *w;
    u32 sum;
    u32 swapped;

    if (len <= 0) {
        return 0;
    }
    w = (u16 *)buf;
    su.s = 0;
    swapped = 0;
    sum = 0;
    if ((u32)w & 1) {
        su.c[1] = *(u8 *)w;
        w = (u16 *)((u8 *)w + 1);
        len--;
        swapped = 1;
    }
    while (len > 0) {
        if (((u32)w & 0xF) == 0 && len >= 8) {
            break;
        }
        sum += *w++;
        len--;
    }
    if (len > 8) {
        sum += *w;
        for (len--; len > 8; len -= 8) {
            sum += w[4];
            sum += w[1];
            sum += w[2];
            sum += w[3];
            sum += w[8];
            sum += w[5];
            sum += w[6];
            sum += w[7];
            w += 8;
        }
        w++;
    }
    for (; len >= 8; len -= 8) {
        sum += w[0];
        sum += w[1];
        sum += w[2];
        sum += w[3];
        sum += w[4];
        sum += w[5];
        sum += w[6];
        sum += w[7];
        w += 8;
    }
    for (; len > 0; len--) {
        sum += *w++;
    }
    if (swapped) {
        su.c[0] = *(u8 *)w;
        sum += su.s;
        sum = (sum << 8) | (u8)(sum >> 24);
    }
    sum = (sum >> 16) + (sum & 0xFFFF);
    sum += sum >> 16;
    return sum;
}

typedef char NetworkDispatchState_size[sizeof(NetworkDispatchState) == 0xF8 ? 1 : -1];
void TLobby__sub_80419A00(void) {
    NetMemset((void *) (&network_dispatch_state.lock_handle), 0, 0xF4);
    TLobby::cancel_pending_alarms();
}

typedef char RecoveredGlobal_80419A34_lbl_805C1C50_size[sizeof(RecoveredGlobal_80419A34_lbl_805C1C50) == 0xF8 ? 1 : -1];
void TLobby__sub_80419A34(void) {
    NetMemset((void *) (&(*(RecoveredGlobal_80419A34_lbl_805C1C50 *)&network_dispatch_state).value), 0, 0xF4);
    *(s32 *)((s8 *)(&(*(RecoveredGlobal_80419A34_lbl_805C1C50 *)&network_dispatch_state).value) + 0x10) = 0x1E;
    TLobby__sub_803F8E9C();
}

#pragma push
#pragma opt_common_subs on
typedef char RecoveredGlobal_80419A7C_lbl_805C1C50_size[sizeof(RecoveredGlobal_80419A7C_lbl_805C1C50) == 0xF8 ? 1 : -1];
s32 TLobby__sub_80419A7C(void) {
    TLobby::lock_mutex((int)((int) (*(s32 *)((s8 *)(&(*(RecoveredGlobal_80419A7C_lbl_805C1C50 *)&network_dispatch_state).value) + 0))));
    ((TLobby *)(*(s32 *)((s8 *)(&(*(RecoveredGlobal_80419A7C_lbl_805C1C50 *)&network_dispatch_state).value) + 0xC)))->cancel_thread_if_running();
    ((TLobby *)(*(s32 *)((s8 *)(&(*(RecoveredGlobal_80419A7C_lbl_805C1C50 *)&network_dispatch_state).value) + 8)))->cancel_thread_if_running();
    TLobby::deactivate_entry_by_key((u32)((int) (*(s32 *)((s8 *)(&(*(RecoveredGlobal_80419A7C_lbl_805C1C50 *)&network_dispatch_state).value) + 0xC))));
    TLobby::deactivate_entry_by_key((u32)((int) (*(s32 *)((s8 *)(&(*(RecoveredGlobal_80419A7C_lbl_805C1C50 *)&network_dispatch_state).value) + 8))));
    TLobby::clear_slot_for_handle((u32)((int) (*(s32 *)((s8 *)(&(*(RecoveredGlobal_80419A7C_lbl_805C1C50 *)&network_dispatch_state).value) + 4))));
    TUdpSocket::unlock_mutex((int)((int) (*(s32 *)((s8 *)(&(*(RecoveredGlobal_80419A7C_lbl_805C1C50 *)&network_dispatch_state).value) + 0))));
    NetReleaseMutex((int) (*(s32 *)((s8 *)(&(*(RecoveredGlobal_80419A7C_lbl_805C1C50 *)&network_dispatch_state).value) + 0)));
    return 0;
}
#pragma pop

s16 TLobby__sub_803F94F0(s32 *queue);
s16 TLobby__sub_803F96AC(s32 *lock);
s16 TLobby__sub_803F9B94(void (*fn)(void), s32 *thread);
void NetRunProtocolDispatchLoop(void);
void NetRunTimerDispatchLoop(void);

s16 NetInitializeDispatcher(void) {
    s32 *queue;
    s32 *proto_thread;
    s32 *timer_thread;
    void NetResumeThread(s32 thread);

    queue = &network_dispatch_state.queue_handle;
    if (TLobby__sub_803F94F0(queue) < 0) {
        return -0x100;
    }
    if (TLobby__sub_803F96AC(&network_dispatch_state.lock_handle) < 0) {
        TLobby::clear_slot_for_handle(*queue);
        return -0x100;
    }
    proto_thread = &((s32 *)network_dispatch_state.unknown_08)[0];
    if (TLobby__sub_803F9B94(NetRunProtocolDispatchLoop, proto_thread) < 0) {
        TLobby::clear_slot_for_handle(*queue);
        NetReleaseMutex(network_dispatch_state.lock_handle);
        return -0x100;
    }
    timer_thread = &((s32 *)network_dispatch_state.unknown_08)[1];
    if (TLobby__sub_803F9B94(NetRunTimerDispatchLoop, timer_thread) < 0) {
        TLobby::deactivate_entry_by_key(*proto_thread);
        TLobby::clear_slot_for_handle(*queue);
        NetReleaseMutex(network_dispatch_state.lock_handle);
        return -0x100;
    }
    NetResumeThread(*proto_thread);
    NetResumeThread(*timer_thread);
    return 0;
}

void NetYieldOutsideDispatcherThread(void) {
    NetworkDispatchState *g = &network_dispatch_state;
    s32 self;

    NetStoreCurrentThread(&self);
    if (self != ((u32 *)g->unknown_08)[0] && self != ((u32 *)g->unknown_08)[1]) {
        TUdpSocket::unlock_mutex(g->lock_handle);
        NetYieldThread();
        TLobby::lock_mutex(g->lock_handle);
    }
}

#pragma push
#pragma opt_common_subs on
#pragma pool_data off
void NetRunTimerDispatchLoop(void) {
    NetworkDispatchState *g = &network_dispatch_state;
    s32 now;
    s16 i;
    s16 j;
    s16 due;
    u32 next;

    for (;;) {
        TLobby__sub_803F97E8(network_dispatch_state.interval);
        for (i = 0; i < 10; i++) {
            if (g->timers[i].active == 0 || g->timers[i].fn == NULL) {
                continue;
            }
            TLobby::get_time_ms(&now);
            due = 0;
            if (g->timers[i].last < g->timers[i].next) {
                if (g->timers[i].next <= now || now < g->timers[i].last) {
                    due = 1;
                }
            } else if (g->timers[i].next <= now && now < g->timers[i].last) {
                due = 1;
            }
            if (due == 0) {
                continue;
            }
            if (g->timers[i].lock_callback != 0) {
                TLobby::lock_mutex(network_dispatch_state.lock_handle);
            }
            g->timers[i].fn();
            if (g->timers[i].lock_callback != 0) {
                TUdpSocket::unlock_mutex(network_dispatch_state.lock_handle);
            }
            next = now + g->timers[i].period;
            if (g->timers[i].period > network_dispatch_state.interval) {
                for (j = 0; j < 10; j++) {
                    if (i != j && g->timers[j].active != 0 && g->timers[j].next == next &&
                        g->timers[j].period > network_dispatch_state.interval) {
                        next += network_dispatch_state.interval;
                    }
                }
            }
            g->timers[i].last = now;
            g->timers[i].next = next;
        }
    }
}
#pragma pop

s32 NetUnregisterTimer(void *fn) {
    NetworkDispatchState *g = &network_dispatch_state;
    s16 i;

    if (fn == NULL) {
        return -0x100;
    }
    for (i = 0; i < 10; i++) {
        if (network_dispatch_state.timers[i].active != 0 && (void *)network_dispatch_state.timers[i].fn == fn) {
            g->timers[i].active = 0;
            g->timers[i].fn = NULL;
            g->timers[i].lock_callback = 0;
            g->timers[i].period = 0;
            g->timers[i].last = 0;
            g->timers[i].next = 0;
            return 0;
        }
    }
    return -0x100;
}

struct TcpHeader_8041B3D4 {
    u16 src_port;
    u16 dst_port;
    s32 seq;
    s32 ack;
    u8 data_offset;
    u8 flags;
    u16 window;
    u16 checksum;
    u16 urgent;
};

struct E_8041A498;
struct Tcb_8041B774;
void TLobby__sub_8041A498(E_8041A498 *arg0, s16 arg1);
s16 TLobby__sub_8041B3D4(u8 *dst, u8 *src, u16 src_port, u16 dst_port, s32 seq, s32 ack, u8 flags);
s16 TLobby__sub_8041B724(u8 *tcb);
Tcb_8041B774 *TLobby__sub_8041B774(Tcb_8041B774 *lst, u16 *port, u8 *local, u8 *remote);
void set_slot_state_and_resume__6TLobbyFv(s16, s32, s16);
void set_thread_state_and_resume__6TLobbyFv(s16, s32, s16);

struct Tcb_8041B974 {
    u8 pad0[4];
    u16 f4;
    s16 t_state;
    u8 pad8[2];
    u8 fA;
    u8 flags;
    u8 padC;
    u8 dupacks;
    u8 padE[0xCA];
    u32 fD8;
    u8 padDC[0x120];
    s32 f1FC;
    s32 f200;
    u8 pad204[4];
    u32 snd_una;
    u32 snd_nxt;
    u32 snd_up;
    u32 snd_wl1;
    u32 snd_wl2;
    u32 iss;
    u32 snd_wnd;
    u32 rcv_wnd;
    u32 rcv_nxt;
    u32 rcv_up;
    u32 irs;
    u32 rcv_adv;
    u32 snd_max;
    u32 snd_cwnd;
    u32 snd_ssthresh;
    s16 idle;
    s16 rtt;
    u32 rtseq;
    s16 srtt;
    s16 rttvar;
    u32 max_sndwnd;
    u16 rxtcur;
    u8 pad256[2];
    u32 rxtshift;
    s16 timers[4];
    u16 maxseg;
    u8 pad266[2];
    u16 lport;
    u16 fport;
    u8 pad26C[0x10];
    u8 faddr[0x14];
    u8 laddr[0x14];
    u8 pad2A4[0x24];
    s32 f2C8;
    s32 f2CC;
    s32 f2D0;
    s16 f2D4;
    u8 pad2D6[0x1A];
    s32 f2F0;
    u32 f2F4;
    u8 pad2F8[0x2C];
    u32 f324;
    u8 pad328[0x210];
    s16 f538;
    u8 pad53A[2];
    u32 f53C;
    s32 f540;
};
struct G_8041B974 {
    Tcb_8041B974 *tcbs;
    s16 count;
    u8 pad6[0x12];
    u32 iss;
    u8 pad1C[2];
    s16 rexmtthresh;
    u8 pad20[4];
    s16 maxidle;
    u8 pad26[0x7A];
    s16 fA0;
};

struct Seg_8041B974 {
    TcpHeader_8041B3D4 th;
    u32 swap;
    s16 flags;
};

#pragma push
#pragma opt_common_subs on
s32 TLobby__sub_8041B974(NetPacket *m, u8 *src, u8 *dst) {
    Seg_8041B974 seg;
    NetPacketFragment *frag;
    TcpHeader_8041B3D4 *ti;
    u8 *p;
    u8 *optp;
    s16 optlen;
    u16 off;
    u16 tlen;
    s16 tiflags;
    Tcb_8041B974 *tp;
    Tcb_8041B974 *cur;
    Tcb_8041B974 *newtp;
    s16 i;
    s32 todrop;
    s32 dropped;
    s32 needoutput;
    u32 iss;
    s32 ack;
    s32 acked;
    s32 ourfinisacked;
    s32 n;
    u32 onxt;
    u32 win;
    u16 mss;
    u32 cw;
    u16 incr;
    s16 delta;

    frag = &m->fragments[1];
    needoutput = 0;
    iss = 0;
    dropped = 0;
    m->total_bytes -= m->fragments[0].length;
    m->fragments[0].length = 0;
    p = TLobby__sub_80406F0C(&frag->buffer);
    NetMemcpy(&seg.th.src_port, p, 2);
    NetMemcpy(&seg.th.dst_port, p + 2, 2);
    NetMemcpy(&seg.th.seq, p + 4, 4);
    NetMemcpy(&seg.th.ack, p + 8, 4);
    NetMemcpy(&seg.th.data_offset, p + 12, 1);
    NetMemcpy(&seg.th.flags, p + 13, 1);
    NetMemcpy(&seg.th.window, p + 14, 2);
    NetMemcpy(&seg.th.checksum, p + 16, 2);
    NetMemcpy(&seg.th.urgent, p + 18, 2);
    ti = &seg.th;
    tiflags = seg.th.flags;
    seg.flags = tiflags;
    off = seg.th.data_offset >> 2;
    if (m->total_bytes < 20) {
        return -1;
    }
    if (TLobby__sub_8040D8F0(src, dst, 6, (u8 *)m, 0) != 0) {
        goto drop;
    }
    optlen = off - 20;
    if (optlen) {
        optp = TLobby__sub_80406F0C(&frag->buffer) + 20;
    } else {
        optp = NULL;
    }
    if (off < 20 || (u16)m->total_bytes < off) {
        goto drop;
    }
    NetMemcpy(&seg.swap, &ti->seq, 4);
    NetMemcpy(&ti->seq, &seg.swap, 4);
    NetMemcpy(&seg.swap, &ti->ack, 4);
    NetMemcpy(&ti->ack, &seg.swap, 4);
    tlen = m->total_bytes - off;

findpcb:
    cur = (Tcb_8041B974 *)tcp_protocol_state.p;
    tp = NULL;
    for (i = 0; i < tcp_protocol_state.n; cur++, i++) {
        if (cur->f4 != 0 && cur->t_state != 1 && cur->t_state != -1 &&
            ((TLobby *)cur->faddr)->compare_sockaddr(src) == 0 && cur->fport == seg.th.src_port &&
            cur->lport == seg.th.dst_port) {
            tp = cur;
            break;
        }
    }
    if (tp == NULL) {
        cur = (Tcb_8041B974 *)tcp_protocol_state.p;
        for (i = 0; i < tcp_protocol_state.n; cur++, i++) {
            if (cur->f4 != 0 && cur->t_state == 1 && cur->lport == seg.th.dst_port &&
                (((TLobby *)cur->faddr)->compare_sockaddr(src) == 0 || is_addr_unspecified__6TLobbyFPv(cur->faddr)) &&
                (cur->fport == seg.th.src_port || cur->fport == 0)) {
                tp = cur;
                break;
            }
        }
    }
    if (tp == NULL) {
        goto dropwithreset;
    }
    if (!tp->t_state) {
        if (tp->flags & 0x80) {
            goto drop;
        }
        if (tp->fA & 4) {
            goto drop;
        }
    }
    if (tp->t_state != 1) {
        tp->idle = 0;
        tp->timers[2] = tp->f2D4;
    }
    if (optp != NULL && tp->t_state != 1) {
        TLobby__sub_8041D0C8(tp, optp, optlen, ti);
    }
    tp->rcv_wnd = (u16)(tp->rcv_adv - tp->rcv_nxt);

    switch (tp->t_state) {
    case 1:
        if (tiflags & 4) {
            NetDispatchSocketEvent((s16)(tp - (Tcb_8041B974 *)tcp_protocol_state.p), tp->f2D0, 3, 0xA);
            goto drop;
        }
        if (tiflags & 0x10) {
            goto dropwithreset;
        }
        if (!(tiflags & 2)) {
            goto drop;
        }
        if ((s16)((TLobby *)dst)->is_multicast_address(0) == 1) {
            goto drop;
        }
        newtp = (Tcb_8041B974 *)TLobby__sub_8041B774((Tcb_8041B774 *)tp, (u16 *)ti, src, dst);
        if (newtp == NULL) {
            goto drop;
        }
        if (optp != NULL) {
            TLobby__sub_8041D0C8(newtp, optp, optlen, ti);
        }
        if (iss != 0) {
            newtp->iss = iss;
        } else {
            newtp->iss = ((G_8041B974 *)&tcp_protocol_state)->iss;
        }
        ((G_8041B974 *)&tcp_protocol_state)->iss += 0xFA00;
        newtp->irs = seg.th.seq;
        newtp->snd_una = newtp->snd_nxt = newtp->snd_max = newtp->snd_up = newtp->f2F4 = newtp->f324 = newtp->iss;
        newtp->rcv_adv = newtp->rcv_nxt = newtp->irs + 1;
        newtp->flags |= 1;
        newtp->t_state = 3;
        newtp->timers[2] = 150;
        switch (newtp->f540) {
        case 1:
            newtp->snd_cwnd = newtp->maxseg;
            break;
        case 2:
            newtp->snd_cwnd = newtp->maxseg * 2;
            break;
        case 3:
            newtp->snd_cwnd = newtp->maxseg * 4 < (newtp->maxseg * 2 > 4380 ? newtp->maxseg * 2 : 4380)
                                  ? newtp->maxseg * 4
                                  : (newtp->maxseg * 2 > 4380 ? newtp->maxseg * 2 : 4380);
            break;
        default:
            newtp->snd_cwnd = get_adjusted_slot_count__6TLobbyFPv((u8 *)newtp);
            break;
        }
        newtp->f2D0 = tp->f2CC;
        tp->f2CC = 0;
        TLobby__sub_80422AB8((s16)(tp - (Tcb_8041B974 *)tcp_protocol_state.p), tp->f2C8, (s16)(newtp - (Tcb_8041B974 *)tcp_protocol_state.p), newtp->faddr, newtp->lport,
                             newtp->fport);
        tp = newtp;
        goto trimthenstep6;

    case 2:
        if ((ack = tiflags & 0x10) && ((s32)(seg.th.ack - tp->iss) <= 0 || (s32)(seg.th.ack - tp->snd_max) > 0)) {
            NetDispatchSocketEvent((s16)(tp - (Tcb_8041B974 *)tcp_protocol_state.p), tp->f2D0, 3, 0xE);
            goto dropwithreset;
        }
        if (tiflags & 4) {
            NetDispatchSocketEvent((s16)(tp - (Tcb_8041B974 *)tcp_protocol_state.p), tp->f2D0, 3, 0xA);
            if (ack) {
                TLobby__sub_8041A498((E_8041A498 *)tp, 1);
            }
            goto drop;
        }
        if (!(tiflags & 2)) {
            goto drop;
        }
        if (ack) {
            tp->snd_una = seg.th.ack;
            tp->f2F4 = seg.th.ack;
            if ((s32)(tp->snd_nxt - tp->snd_una) < 0) {
                tp->snd_nxt = tp->snd_una;
            }
        }
        tp->timers[0] = 0;
        tp->irs = seg.th.seq;
        tp->rcv_adv = tp->rcv_nxt = tp->irs + 1;
        tp->flags |= 1;
        if (ack && (s32)(tp->snd_una - tp->iss) > 0) {
            NetDispatchSocketEvent((s16)(tp - (Tcb_8041B974 *)tcp_protocol_state.p), tp->f2D0, 3, 1);
            tp->t_state = 4;
            tp->maxseg = TLobby__sub_8041B724((u8 *)tp);
            switch (tp->f540) {
            case 1:
                tp->snd_cwnd = tp->maxseg;
                break;
            case 2:
                tp->snd_cwnd = tp->maxseg * 2;
                break;
            case 3:
                tp->snd_cwnd = tp->maxseg * 4 < (tp->maxseg * 2 > 4380 ? tp->maxseg * 2 : 4380)
                                   ? tp->maxseg * 4
                                   : (tp->maxseg * 2 > 4380 ? tp->maxseg * 2 : 4380);
                break;
            default:
                tp->snd_cwnd = get_adjusted_slot_count__6TLobbyFPv((u8 *)tp);
                break;
            }
            if (tp->rtt != 0) {
                tp->srtt = tp->rtt << 3;
                tp->rttvar = tp->rtt << 1;
                tp->rxtcur = (tp->srtt >> 3) + tp->rttvar;
                if (tp->rxtcur < 2) {
                    tp->rxtcur = 2;
                } else if (tp->rxtcur > 0x80) {
                    tp->rxtcur = 0x80;
                }
                tp->rtt = 0;
            }
        } else {
            tp->t_state = 3;
        }
    trimthenstep6:
        seg.th.seq++;
        if (tlen > tp->rcv_wnd) {
            tlen = tp->rcv_wnd;
            tiflags &= ~1;
        }
        tp->snd_wl1 = seg.th.seq - 1;
        tp->rcv_up = seg.th.seq;
        goto step6;
    }

    todrop = tp->rcv_nxt - seg.th.seq;
    if (todrop > 0) {
        if (tiflags & 2) {
            tiflags &= ~2;
            seg.th.seq++;
            if (seg.th.urgent > 1) {
                seg.th.urgent--;
            } else {
                tiflags &= ~0x20;
            }
            todrop--;
        }
        if (todrop > tlen || (todrop == tlen && !(tiflags & 1))) {
            if ((tiflags & 1) && todrop == tlen + 1) {
                todrop = tlen;
                tiflags &= ~1;
                tp->flags |= 1;
            } else {
                goto dropafterack;
            }
        }
        dropped += todrop;
        seg.th.seq += todrop;
        tlen -= todrop;
        if (seg.th.urgent > (u16)todrop) {
            seg.th.urgent -= todrop;
        } else {
            seg.th.urgent = 0;
            tiflags &= ~0x20;
        }
    }

    todrop = (seg.th.seq + tlen) - (tp->rcv_nxt + tp->rcv_wnd);
    if (todrop > 0) {
        if (todrop >= tlen) {
            if ((tiflags & 2) && tp->t_state == 10 && tp->fD8 == 0 && (s32)(seg.th.seq - tp->rcv_nxt) > 0) {
                iss = tp->rcv_nxt + 0x1F400;
                NetDispatchSocketEvent((s16)(tp - (Tcb_8041B974 *)tcp_protocol_state.p), tp->f2D0, 3, 4);
                tp->flags |= 0x80;
                TLobby__sub_8041B5C0(tp);
                goto findpcb;
            }
            if (tp->rcv_wnd == 0 && seg.th.seq == tp->rcv_nxt) {
                tp->flags |= 1;
            } else {
                goto dropafterack;
            }
        }
        tlen -= todrop;
        tiflags &= ~9;
    }

    if (tiflags & 4) {
        NetDispatchSocketEvent((s16)(tp - (Tcb_8041B974 *)tcp_protocol_state.p), tp->f2D0, 3, 0xA);
        switch (tp->t_state) {
        case 3:
        case 4:
        case 6:
        case 9:
        case 5:
            tp->t_state = 0;
            NetDispatchSocketEvent((s16)(tp - (Tcb_8041B974 *)tcp_protocol_state.p), tp->f2D0, 3, 4);
            set_thread_state_and_resume__6TLobbyFv((s16)(tp - (Tcb_8041B974 *)tcp_protocol_state.p), tp->f1FC, -5);
            set_slot_state_and_resume__6TLobbyFv((s16)(tp - (Tcb_8041B974 *)tcp_protocol_state.p), tp->f200, -5);
            if (TLobby__sub_8041B5C0(tp) != NULL) {
                tp->t_state = -1;
            }
            goto drop;
        case 7:
        case 8:
        case 10:
            NetDispatchSocketEvent((s16)(tp - (Tcb_8041B974 *)tcp_protocol_state.p), tp->f2D0, 3, 4);
            tp->flags |= 0x80;
            TLobby__sub_8041B5C0(tp);
            goto drop;
        }
    }
    if (tiflags & 2) {
        goto dropafterack;
    }
    if (!(tiflags & 0x10)) {
        goto drop;
    }

    switch (tp->t_state) {
    case 3:
        if ((s32)(tp->snd_una - seg.th.ack) > 0 || (s32)(seg.th.ack - tp->snd_max) > 0) {
            goto dropwithreset;
        }
        NetDispatchSocketEvent((s16)(tp - (Tcb_8041B974 *)tcp_protocol_state.p), tp->f2D0, 3, 1);
        tp->t_state = 4;
        tp->maxseg = TLobby__sub_8041B724((u8 *)tp);
        switch (tp->f540) {
        case 1:
            tp->snd_cwnd = tp->maxseg;
            break;
        case 2:
            tp->snd_cwnd = tp->maxseg * 2;
            break;
        case 3:
            tp->snd_cwnd = tp->maxseg * 4 < (tp->maxseg * 2 > 4380 ? tp->maxseg * 2 : 4380)
                               ? tp->maxseg * 4
                               : (tp->maxseg * 2 > 4380 ? tp->maxseg * 2 : 4380);
            break;
        default:
            tp->snd_cwnd = get_adjusted_slot_count__6TLobbyFPv((u8 *)tp);
            break;
        }
        tp->snd_cwnd -= tp->maxseg;
        tp->snd_wl1 = seg.th.seq - 1;
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
        if ((s32)(seg.th.ack - tp->snd_una) <= 0 && tp->snd_una == tp->f2F4) {
            if (tlen == 0 && seg.th.window == tp->snd_wnd) {
                if (tp->timers[0] == 0 || seg.th.ack != tp->snd_una) {
                    tp->dupacks = 0;
                } else if (++tp->dupacks == (u8)((G_8041B974 *)&tcp_protocol_state)->rexmtthresh) {
                    onxt = tp->snd_nxt;
                    win = (tp->snd_wnd < tp->snd_cwnd ? tp->snd_wnd : tp->snd_cwnd) / 2 / tp->maxseg;
                    if (TLobby__sub_8041D368((u8 *)tp) == 0) {
                        tp->f2F4 = tp->snd_nxt;
                        tp->dupacks--;
                        goto recover;
                    }
                    if (win < 2) {
                        win = 2;
                    }
                    tp->snd_ssthresh = win * tp->maxseg;
                    tp->timers[0] = 0;
                    tp->rtt = 0;
                    tp->snd_nxt = seg.th.ack;
                    tp->snd_cwnd = tp->maxseg;
                    TLobby__sub_8041A9AC((int)tp);
                    tp->snd_cwnd = tp->snd_ssthresh + tp->maxseg * tp->dupacks;
                    if ((s32)(onxt - tp->snd_nxt) > 0) {
                        tp->snd_nxt = onxt;
                    }
                    goto drop;
                } else if (tp->dupacks > (u8)((G_8041B974 *)&tcp_protocol_state)->rexmtthresh) {
                    tp->snd_cwnd += tp->maxseg;
                    TLobby__sub_8041A9AC((int)tp);
                    goto drop;
                }
            } else {
                tp->dupacks = 0;
            }
            break;
        }
    recover:
        if ((s32)(tp->snd_una - tp->f2F4) < 0 && (s32)(seg.th.ack - tp->f2F4) < 0) {
            if (tlen == 0 && seg.th.window <= tp->snd_wnd) {
                if (seg.th.ack != tp->snd_una) {
                    acked = seg.th.ack - tp->snd_una;
                    TLobby__sub_8041FFF8(acked, (int)tp);
                    tp->snd_wnd -= acked;
                    if (seg.th.window > tp->snd_wnd) {
                        tp->snd_wnd = seg.th.window;
                    }
                    tp->snd_una = seg.th.ack;
                }
                if (++tp->dupacks == (u8)((G_8041B974 *)&tcp_protocol_state)->rexmtthresh) {
                    mss = tp->maxseg;
                    win = (tp->snd_wnd < tp->snd_cwnd ? tp->snd_wnd : tp->snd_cwnd) / 2 / mss;
                    tp->f2F0 = tp->snd_nxt - tp->snd_una - mss * tp->dupacks - mss;
                    if (tp->f2F0 < 0) {
                        tp->f2F0 = 0;
                    }
                    if (win < 2) {
                        win = 2;
                    }
                    tp->snd_ssthresh = win * tp->maxseg;
                    tp->timers[0] = 0;
                    tp->rtt = 0;
                    tp->snd_cwnd = tp->f2F0 + tp->maxseg;
                    TLobby__sub_8041A9AC((int)tp);
                    tp->snd_cwnd = tp->snd_ssthresh;
                    goto drop;
                } else if (tp->dupacks > (u8)((G_8041B974 *)&tcp_protocol_state)->rexmtthresh) {
                    tp->f2F0 -= tp->maxseg;
                    TLobby__sub_8041A9AC((int)tp);
                    goto drop;
                }
                break;
            }
            if (seg.th.window > tp->snd_wnd) {
                tp->snd_wnd = seg.th.window;
            } else {
                tp->dupacks = 0;
            }
            break;
        }
        ((TLobby *)tp)->reset_slot_index();
        tp->f2F0 = 0;
        tp->f2F4 = seg.th.ack;
        if (tp->dupacks > ((G_8041B974 *)&tcp_protocol_state)->rexmtthresh && tp->snd_cwnd > tp->snd_ssthresh) {
            tp->snd_cwnd = tp->snd_ssthresh;
        }
        tp->dupacks = 0;
        if ((s32)(seg.th.ack - tp->snd_max) > 0) {
            goto dropafterack;
        }
        acked = seg.th.ack - tp->snd_una;
        if (tp->rtt && (s32)(seg.th.ack - tp->rtseq) > 0) {
            if (tp->srtt) {
                delta = tp->rtt - 1 - (tp->srtt >> 3);
                if ((tp->srtt += delta) <= 0) {
                    tp->srtt = 1;
                }
                if (delta < 0) {
                    delta = -delta;
                }
                delta -= tp->rttvar >> 2;
                if ((tp->rttvar += delta) <= 0) {
                    tp->rttvar = 1;
                }
            } else {
                tp->srtt = tp->rtt << 3;
                tp->rttvar = tp->rtt << 1;
            }
            tp->rtt = 0;
        }
        if (acked > 0 && tp->rxtshift != 0) {
            tp->rxtshift = 0;
            tp->rxtcur = (tp->srtt >> 3) + tp->rttvar;
            if (tp->rxtcur < 2) {
                tp->rxtcur = 2;
            } else if (tp->rxtcur > 0x80) {
                tp->rxtcur = 0x80;
            }
        }
        if (seg.th.ack == tp->snd_max) {
            if (tp->timers[0] != 0) {
                tp->timers[0] = 0;
                tp->rxtshift = 0;
            }
            needoutput = 1;
        } else if (tp->timers[1] == 0) {
            tp->timers[0] = tp->rxtcur;
        }
        if (acked == 0) {
            break;
        }
        cw = tp->snd_cwnd;
        incr = tp->maxseg;
        if (cw > tp->snd_ssthresh) {
            incr = (u32)(incr * incr) / cw > 1 ? (u32)(incr * incr) / cw : 1;
        }
        tp->snd_cwnd = (u16)((s32)(cw + incr) < 0xFFFF ? cw + incr : 0xFFFF);
        n = ((TLobby *)tp)->get_score();
        if (acked > n) {
            ourfinisacked = 1;
        } else {
            n = acked;
            ourfinisacked = 0;
        }
        TLobby__sub_8041FFF8(n, (int)tp);
        tp->snd_wnd -= (u16)n;
        tp->snd_una = seg.th.ack;
        if ((s32)(tp->snd_nxt - tp->snd_una) < 0) {
            tp->snd_nxt = tp->snd_una;
        }
        switch (tp->t_state) {
        case 6:
            if (ourfinisacked) {
                if (tp->fA & 4) {
                    tp->timers[3] = ((G_8041B974 *)&tcp_protocol_state)->maxidle;
                }
                tp->t_state = 9;
            }
            break;
        case 7:
            if (ourfinisacked) {
                tp->t_state = 10;
                if ((u32)((TLobby *)tp)->get_score() == 0) {
                    ((TLobby *)tp)->close_if_open();
                }
                if ((u32)((TLobby *)tp)->get_field_d8() == 0) {
                    TLobby__sub_8041EB74((u8 *)tp);
                }
                ((TLobby *)tp)->clear_position();
                tp->timers[3] = 120;
            }
            break;
        case 8:
            if (ourfinisacked) {
                NetDispatchSocketEvent((s16)(tp - (Tcb_8041B974 *)tcp_protocol_state.p), tp->f2D0, 3, 4);
                TLobby__sub_8041B5C0(tp);
                goto drop;
            }
            break;
        case 10:
            tp->timers[3] = 120;
            goto dropafterack;
        }
    }

step6:
    if ((tiflags & 0x10) && ((s32)(tp->snd_wl1 - seg.th.seq) < 0 ||
                             (tp->snd_wl1 == seg.th.seq &&
                              ((s32)(tp->snd_wl2 - seg.th.ack) < 0 || (tp->snd_wl2 == seg.th.ack && seg.th.window > tp->snd_wnd))))) {
        tp->snd_wnd = seg.th.window;
        tp->snd_wl1 = seg.th.seq;
        tp->snd_wl2 = seg.th.ack;
        if (tp->snd_wnd > tp->max_sndwnd) {
            tp->max_sndwnd = tp->snd_wnd;
        }
        needoutput = 1;
    }
    if ((tiflags & 0x20) && seg.th.urgent != 0 && !(tp->flags & 8)) {
        if (seg.th.urgent + ((TLobby *)tp)->get_queue_diff() > 0x10000) {
            seg.th.urgent = 0;
            tiflags &= ~0x20;
        } else if ((s32)(seg.th.seq + seg.th.urgent - tp->rcv_up) > 0) {
            tp->rcv_up = seg.th.seq + seg.th.urgent;
        }
    } else if (tp->rcv_nxt != tp->rcv_up) {
        tp->rcv_up = tp->rcv_nxt;
    }

    if ((tlen != 0 || (tiflags & 1)) && !(tp->flags & 8)) {
        if (seg.th.seq == tp->rcv_nxt && (tp->t_state == 4 || (tp->fA & 0xC))) {
            tiflags = seg.flags & 1;
            tp->rcv_nxt += tlen;
            if (!(tp->fA & 4)) {
                TLobby__sub_8041F204(m, (u16)(off + dropped), tp);
            }
            if (tp->f53C == 0) {
                if (tp->f538 == 0) {
                    tp->f538 = ((G_8041B974 *)&tcp_protocol_state)->fA0 / 100;
                }
            } else {
                tp->flags |= 1;
            }
        } else {
            if ((s32)(seg.th.seq - tp->rcv_nxt) > 0) {
                TLobby__sub_8041F914(m, (u16)(off + dropped), tp, ti);
            }
            tiflags &= ~1;
            tp->flags |= 1;
        }
    } else {
        tiflags &= ~1;
    }

    if (tiflags & 1) {
        NetDispatchSocketEvent((s16)(tp - (Tcb_8041B974 *)tcp_protocol_state.p), tp->f2D0, 3, 2);
        if (!(tp->flags & 8)) {
            TLobby__sub_8041F11C(tp);
            tp->flags |= 1;
            tp->rcv_nxt++;
        }
        tp->flags |= 8;
        switch (tp->t_state) {
        case 3:
        case 4:
            tp->t_state = 5;
            break;
        case 6:
            tp->t_state = 7;
            break;
        case 9:
            tp->t_state = 10;
            if ((u32)((TLobby *)tp)->get_score() == 0) {
                ((TLobby *)tp)->close_if_open();
            }
            if ((u32)((TLobby *)tp)->get_field_d8() == 0) {
                TLobby__sub_8041EB74((u8 *)tp);
            }
            ((TLobby *)tp)->clear_position();
            tp->timers[3] = 120;
            break;
        case 10:
            tp->timers[3] = 120;
            break;
        }
    }
    if (needoutput || (tp->flags & 1)) {
        TLobby__sub_8041A9AC((int)tp);
    }
    return 0;

dropafterack:
    if (tiflags & 4) {
        goto drop;
    }
    tp->flags |= 1;
    TLobby__sub_8041A9AC((int)tp);
    return 0;

dropwithreset:
    if ((tiflags & 4) || (s16)((TLobby *)dst)->is_multicast_address(0) == 1) {
        goto drop;
    }
    if (tiflags & 0x10) {
        if (TLobby__sub_8041B3D4(src, dst, seg.th.dst_port, seg.th.src_port, seg.th.ack, 0, 4) < 0) {
            return -1;
        }
    } else {
        if (tiflags & 2) {
            tlen++;
        }
        if (TLobby__sub_8041B3D4(src, dst, seg.th.dst_port, seg.th.src_port, 0, tlen + seg.th.seq, 0x14) < 0) {
            return -1;
        }
    }
    return 0;

drop:
    return 0;
}
#pragma pop

#pragma push
#pragma opt_common_subs on
#pragma push
#pragma pool_data off
typedef char OriginalBss_805C1AF0_size[(sizeof(G_8040A45C) == 0x48) ? 1 : -1];
typedef char OriginalBss_805C1B38_size[(sizeof(RecoveredGlobal_8040DD68_lbl_805C1B38) == 0x28) ? 1 : -1];
typedef char OriginalBss_805C1B60_size[(sizeof(RecoveredGlobal_8040EF00_lbl_805C1B60) == 0x18) ? 1 : -1];
typedef char OriginalBss_805C1B78_size[(sizeof(RecoveredGlobal_8040FF0C_lbl_805C1B78) == 0x40) ? 1 : -1];
typedef char OriginalBss_805C1BB8_size[(sizeof(RecoveredGlobal_8041123C_lbl_805C1BB8) == 0x28) ? 1 : -1];
typedef char OriginalBss_805C1BE0_size[(sizeof(RecoveredGlobal_8041552C_lbl_805C1BE0) == 0x18) ? 1 : -1];
typedef char OriginalBss_805C1BF8_size[(sizeof(RecoveredGlobal_80415650_lbl_805C1BF8) == 0x10) ? 1 : -1];
typedef char OriginalBss_805C1C08_size[(sizeof(G_80415B38) == 0x30) ? 1 : -1];
G_8040A45C dns_resolver_state;
RecoveredGlobal_8040DD68_lbl_805C1B38 ipv4_protocol_state;
RecoveredGlobal_8040EF00_lbl_805C1B60 ipv4_address_routing_state;
RecoveredGlobal_8040FF0C_lbl_805C1B78 ipv6_protocol_state;
RecoveredGlobal_8041123C_lbl_805C1BB8 ipv6_address_routing_state;
RecoveredGlobal_8041552C_lbl_805C1BE0 network_loopback_state;
RecoveredGlobal_80415650_lbl_805C1BF8 network_buffer_pool_state;
G_80415B38 ipv6_neighbor_discovery_state;

typedef char OriginalBss_805C1C38_size[(sizeof(G_80418ACC) == 0x18) ? 1 : -1];
typedef char OriginalBss_805C1C50_size[(sizeof(NetworkDispatchState) == 0xF8) ? 1 : -1];
typedef char OriginalBss_805C1D48_size[(sizeof(RecoveredGlobal_8041E178_lbl_805C1D48) == 0xA8) ? 1 : -1];
G_80418ACC packet_fragment_pool_state;
NetworkDispatchState network_dispatch_state;
RecoveredGlobal_8041E178_lbl_805C1D48 tcp_protocol_state;

#pragma pop
s32 NetRegisterTimer(s32 period, s16 locked, NetTimerCallback fn) {
    u32 now;
    s32 *pint;
    s16 slot;
    s16 i;
    u32 cur;
    s32 iv;
    s16 j;
    u32 nxt;
    if (fn == NULL) {
        return -0x100;
    }
    pint = &network_dispatch_state.interval;
    if (period < network_dispatch_state.interval) {
        period = network_dispatch_state.interval;
    }
    slot = -1;
    i = 0;
    while (i < 10) {
        if (network_dispatch_state.timers[i].active != 0) {
            if (network_dispatch_state.timers[i].fn == fn) {
                return -0x100;
            }
        } else if (slot < 0) {
            slot = i;
        }
        i++;
    }
    if (slot < 0 || slot >= 10) {
        return -0x100;
    }
    TLobby::get_time_ms((s32 *)&now);
    iv = *pint;
    cur = now;
    nxt = cur + period;
    if (period > iv) {
        j = 0;
        while (j < 10) {
            if (network_dispatch_state.timers[j].active != 0 && network_dispatch_state.timers[j].next == nxt && network_dispatch_state.timers[j].period > iv) {
                nxt += iv;
            }
            j++;
        }
    }
    network_dispatch_state.timers[slot].period = period;
    network_dispatch_state.timers[slot].last = cur;
    network_dispatch_state.timers[slot].next = nxt;
    network_dispatch_state.timers[slot].lock_callback = locked;
    network_dispatch_state.timers[slot].fn = fn;
    network_dispatch_state.timers[slot].active = 1;
    return 0;
}
#pragma pop

void NetEnqueueProtocolMessage(s32 arg0, s16 arg1, s16 arg2, s16 arg3, u16 arg4) {
    NetProtocolMessage message;
    message.first = arg2;
    message.second = arg3;
    message.protocol = arg4;
    message.detail = arg1;
    message.payload = arg0;
    TLobby__sub_803F9344(network_dispatch_state.queue_handle, &message, 0xC);
}

void NetRunProtocolDispatchLoop(void) {
    NetProtocolMessage msg;
    s16 i;

    for (;;) {
        NetReceiveMessage(network_dispatch_state.queue_handle, &msg, sizeof(msg));
        TLobby::lock_mutex(network_dispatch_state.lock_handle);
        for (i = 0; i < 3; i++) {
            if (network_dispatch_state.handlers[i].used != 0 && network_dispatch_state.handlers[i].type == msg.protocol) {
                if (network_dispatch_state.handlers[i].fn != NULL) {
                    network_dispatch_state.handlers[i].fn(msg.payload, msg.detail, msg.first, msg.second);
                }
                break;
            }
        }
        TUdpSocket::unlock_mutex(network_dispatch_state.lock_handle);
        TLobby::dispatch_handler_by_id(msg.first, msg.second, msg.payload);
        NetYieldThread();
    }
}

#pragma push
#pragma opt_common_subs on
s32 NetTCPInit(void) {
    s16 n;
    s16 i;
    E_8041A230 *e;
    ((TLobby *)((u8 *)&tcp_protocol_state))->init_params();
    e = (*(G_8041A230 *)&tcp_protocol_state).ents;
    for (i = 0; i < (n = (*(G_8041A230 *)&tcp_protocol_state).count); i++) {
        e->f8 = -1;
        e->f4 = 0;
        e->c0 = 0x54;
        e->c1 = 0x43;
        e->c2 = 0x42;
        e->c3 = i;
        e++;
    }
    (*(G_8041A230 *)&tcp_protocol_state).avail = n;
    (*(G_8041A230 *)&tcp_protocol_state).h10 = 0;
    NetStoreTick((s32 *)(*(G_8041A230 *)&tcp_protocol_state).tick);
    (*(G_8041A230 *)&tcp_protocol_state).h14 = 0x7FF;
    (*(G_8041A230 *)&tcp_protocol_state).h12 = 0x400;
    (*(G_8041A230 *)&tcp_protocol_state).h22 = 0x3840;
    (*(G_8041A230 *)&tcp_protocol_state).h20 = 0x96;
    (*(G_8041A230 *)&tcp_protocol_state).h1E = 3;
    (*(G_8041A230 *)&tcp_protocol_state).b50 = 0;
    (*(G_8041A230 *)&tcp_protocol_state).b50 |= 1;
    (*(G_8041A230 *)&tcp_protocol_state).bA2 = 2;
    (*(G_8041A230 *)&tcp_protocol_state).b51 = 0x14;
    (*(G_8041A230 *)&tcp_protocol_state).b52 = 0;
    (*(G_8041A230 *)&tcp_protocol_state).b53 = 2;
    (*(G_8041A230 *)&tcp_protocol_state).b54 = 0x12;
    (*(G_8041A230 *)&tcp_protocol_state).b55 = 0x10;
    (*(G_8041A230 *)&tcp_protocol_state).b56 = 0x10;
    (*(G_8041A230 *)&tcp_protocol_state).b57 = 0x11;
    (*(G_8041A230 *)&tcp_protocol_state).b58 = 0x11;
    (*(G_8041A230 *)&tcp_protocol_state).b59 = 0x11;
    (*(G_8041A230 *)&tcp_protocol_state).b5A = 0x10;
    (*(G_8041A230 *)&tcp_protocol_state).b5B = 0x10;
    (*(G_8041A230 *)&tcp_protocol_state).s5C = 1;
    (*(G_8041A230 *)&tcp_protocol_state).s5E = 2;
    (*(G_8041A230 *)&tcp_protocol_state).s60 = 4;
    (*(G_8041A230 *)&tcp_protocol_state).s62 = 8;
    (*(G_8041A230 *)&tcp_protocol_state).s64 = 0x10;
    (*(G_8041A230 *)&tcp_protocol_state).s66 = 0x20;
    (*(G_8041A230 *)&tcp_protocol_state).s68 = 0x40;
    (*(G_8041A230 *)&tcp_protocol_state).s6A = 0x40;
    (*(G_8041A230 *)&tcp_protocol_state).s6C = 0x40;
    (*(G_8041A230 *)&tcp_protocol_state).s6E = 0x40;
    (*(G_8041A230 *)&tcp_protocol_state).s70 = 0x40;
    (*(G_8041A230 *)&tcp_protocol_state).s72 = 0x40;
    (*(G_8041A230 *)&tcp_protocol_state).s74 = 0x40;
    NetRegisterTimer(500, (s16)(1), (NetTimerCallback)(TLobby__sub_8041A5B4));
    NetRegisterTimer(100, (s16)(1), (NetTimerCallback)(TLobby__sub_8041A3CC));
    return 0;
}
#pragma pop

void TLobby::clear_position() {
    u8 *arg0 = (u8 *)this;
    *(s16 *)((s8 *)arg0 + 0x25C) = 0;
    *(s16 *)((s8 *)arg0 + 0x25E) = 0;
    *(s16 *)((s8 *)arg0 + 0x260) = 0;
    *(s16 *)((s8 *)arg0 + 0x262) = 0;
}

struct E_8041A0C0 { u8 pad[0x14]; s16 f14; u16 f16; s32 f18; };
s32 TLobby::release_slot_by_id(u16 a) {
    E_8041A0C0 *g = (E_8041A0C0 *)&network_dispatch_state;
    E_8041A0C0 *p = g;
    s16 i;
    for (i = 0; i < 3; p = (E_8041A0C0 *)((u8 *)p + 8), i++) {
        if (p->f14 != 0 && p->f16 == a) {
            E_8041A0C0 *q = (E_8041A0C0 *)((u8 *)g + i * 8);
            q->f14 = 0;
            q->f16 = 0;
            q->f18 = 0;
            return 0;
        }
    }
    return -0x100;
}

s32 register_protocol_handler__6TLobbyFUsi(u16 type, Handler_8041A130 fn) {
    NetworkDispatchState *g = &network_dispatch_state;
    s16 i;
    s16 freei;

    if (fn == NULL) {
        return -0x100;
    }
    freei = -1;
    for (i = 0; i < 3; i++) {
        if (network_dispatch_state.handlers[i].used != 0) {
            if (network_dispatch_state.handlers[i].type == type) {
                return -0x100;
            }
        } else if (freei < 0) {
            freei = i;
        }
    }
    if (freei < 0 || freei >= 3) {
        return -0x100;
    }
    g->handlers[freei].used = 1;
    g->handlers[freei].type = type;
    g->handlers[freei].fn = fn;
    return 0;
}

struct G_8041A1D8 { u8 pad[4]; s16 n; };
s32 TLobby__sub_8041A1D8(void) {
    NetUnregisterTimer((void *)TLobby__sub_8041A5B4);
    NetUnregisterTimer((void *)TLobby__sub_8041A3CC);
    TLobby__sub_803F8794((void *)&tcp_protocol_state);
    ((G_8041A1D8 *)&tcp_protocol_state)->n = 0;
    return 0;
}

struct Tcb_8041A3CC {
    u8 pad0[4];
    u16 state;
    s16 t_state;
    u8 pad8[3];
    u8 flags;
    u8 force;
    u8 padD[0x1FB];
    u32 snd_una;
    u32 snd_nxt;
    u8 pad210[0x10];
    u32 snd_wnd;
    u8 pad224[4];
    u32 rcv_nxt;
    u8 pad22C[0x10];
    u32 snd_cwnd;
    u32 snd_ssthresh;
    s16 idle;
    s16 rtt;
    u8 pad248[4];
    s16 srtt;
    s16 rttvar;
    u8 pad250[4];
    u16 rxtcur;
    u8 pad256[2];
    u32 rxtshift;
    s16 timers[4];
    u16 maxseg;
    u8 pad266[2];
    u16 f268;
    u16 f26A;
    u8 pad26C[0x10];
    u8 remote[0x14];
    u8 local[0x14];
    u8 pad2A4[0x30];
    s16 f2D4;
    u8 pad2D6[0x16];
    s32 f2EC;
    s32 f2F0;
    u32 f2F4;
    u8 pad2F8[0x240];
    s16 ack_delay;
    u8 pad53A[0xA];
};
struct G_8041A3CC {
    Tcb_8041A3CC *ents;
    s16 count;
    u8 pad6[0x12];
    s32 iss;
    u8 pad1C[4];
    s16 keepintvl;
    s16 keepidle;
    s16 maxidle;
    u8 pad26[0x36];
    s16 backoff[13];
    u8 pad76[0x2A];
    s16 ack_ticks;
};

void TLobby__sub_8041A3CC(void) {
    G_8041A3CC *g = (G_8041A3CC *)&tcp_protocol_state;
    s16 i;
    Tcb_8041A3CC *e;

    e = g->ents;
    for (i = 0; i < g->count; e++, i++) {
        if (e->state != 0 && e->ack_delay != 0) {
            e->ack_delay--;
            if (e->ack_delay == 0) {
                e->ack_delay = g->ack_ticks / 100;
                e->flags |= 1;
                TLobby__sub_8041A9AC((int)e);
            }
        }
    }
}

s32 TLobby__sub_8041A6A4(Tcb_8041A3CC *tcb, s16 timer);

void TLobby__sub_8041A5B4(void) {
    G_8041A3CC *g = (G_8041A3CC *)&tcp_protocol_state;
    Tcb_8041A3CC *e;
    s16 i;
    s16 j;

    i = 0;
    g->maxidle = g->keepintvl << 3;
    e = g->ents;
    for (; i < g->count; e++, i++) {
        if (e->state != 0 && e->state == 1) {
            for (j = 0; j < 4; j++) {
                if (e->timers[j] > 0) {
                    e->timers[j]--;
                    if (e->timers[j] == 0) {
                        TLobby__sub_8041A6A4(e, j);
                    }
                }
            }
            e->idle++;
            if (e->rtt != 0) {
                e->rtt++;
            }
        }
    }
    g->iss += 0xFA00;
}

struct E_8041A498 { u8 pad0[6]; s16 f6; u8 pad8[6]; u8 fE; u8 padF[0x1ED]; s32 f1FC; s32 f200; u8 pad204[0xCC]; s32 f2D0; u8 pad2D4[0x270]; };
void TLobby__sub_8041A498(E_8041A498 *arg0, s16 arg1) {
    s16 idx = arg0 - (E_8041A498 *)tcp_protocol_state.p;

    if (arg0->f6 >= 3) {
        arg0->f6 = 0;
        TLobby__sub_8041A9AC((int)arg0);
    }
    arg0->fE = arg1;
    switch (arg1) {
    case 4:
        set_thread_state_and_resume__6TLobbyFv(idx, arg0->f1FC, -8);
        set_slot_state_and_resume__6TLobbyFv(idx, arg0->f200, -8);
        NetDispatchSocketEvent(idx, arg0->f2D0, 3, 0xB);
        break;
    default:
        set_thread_state_and_resume__6TLobbyFv(idx, arg0->f1FC, -5);
        set_slot_state_and_resume__6TLobbyFv(idx, arg0->f200, -5);
        NetDispatchSocketEvent(idx, arg0->f2D0, 3, 0xA);
        break;
    }
    if (TLobby__sub_8041B5C0(arg0) != 0) {
        arg0->f6 = -1;
    }
}


#pragma push
#pragma opt_common_subs on
s16 TLobby__sub_8041B3D4(u8 *dst, u8 *src, u16 src_port, u16 dst_port, s32 seq, s32 ack, u8 flags) {
    s16 TLobby__sub_8040DA54(u8 *arg0, u8 *arg1);
    s16 dispatch_by_addr_family__6TLobbyFlPUcPUcPUcPvPv(NetPacket *, u8 *, u8 *, u8 *, u8 *, s32);
    TcpHeader_8041B3D4 hdr;
    u8 wire[20];
    u8 opts[16];
    NetPacket *pkt;

    NetMemset(opts, 0, sizeof(opts));
    if (TLobby__sub_8040DA54(dst, src) == 0) {
        return -1;
    }
    hdr.src_port = src_port;
    hdr.dst_port = dst_port;
    hdr.seq = seq;
    hdr.ack = ack;
    hdr.data_offset = 0x50;
    hdr.flags = flags;
    hdr.urgent = 0;
    hdr.checksum = 0;
    hdr.window = 0;
    pkt = (NetPacket *)TLobby::alloc_free_entry();
    if (pkt == NULL) {
        return -0x101;
    }
    pkt->fragment_count = 1;
    pkt->total_bytes = sizeof(wire);
    pkt->fragments[0].length = sizeof(wire);
    NetMemcpy(wire + 0, &hdr.src_port, 2);
    NetMemcpy(wire + 2, &hdr.dst_port, 2);
    NetMemcpy(wire + 4, &hdr.seq, 4);
    NetMemcpy(wire + 8, &hdr.ack, 4);
    NetMemcpy(wire + 12, &hdr.data_offset, 1);
    NetMemcpy(wire + 13, &hdr.flags, 1);
    NetMemcpy(wire + 14, &hdr.window, 2);
    NetMemcpy(wire + 16, &hdr.checksum, 2);
    NetMemcpy(wire + 18, &hdr.urgent, 2);
    ((TLobby *)&pkt->fragments[0].buffer)->set_value_and_enable((s32)wire);
    hdr.checksum = TLobby__sub_8040D8F0(src, dst, 6, (u8 *)pkt, 1);
    NetMemcpy(wire + 16, &hdr.checksum, 2);
    if (dispatch_by_addr_family__6TLobbyFlPUcPUcPUcPvPv(pkt, dst, src, opts + 4, opts + 4, 6) < 0) {
        ((TUdpSocket *)pkt)->release_entry();
        return -1;
    }
    ((TUdpSocket *)pkt)->release_entry();
    return 0;
}
#pragma pop

#pragma push
#pragma opt_common_subs on
s32 TLobby__sub_8041A6A4(Tcb_8041A3CC *tcb, s16 timer) {
    void TLobby__sub_8041B3D4(u8 *, u8 *, u16, u16, u32, u32, s32);
    G_8041A3CC *g = (G_8041A3CC *)&tcp_protocol_state;
    s16 keep;
    s32 win;
    s32 rexmt;
    s32 t;

    switch (timer) {
    case 3:
        if (tcb->t_state != 10 && tcb->idle <= g->maxidle) {
            tcb->timers[3] = g->keepintvl;
        } else {
            TLobby__sub_8041B5C0(tcb);
        }
        break;
    case 0:
        tcb->rxtshift++;
        if (tcb->rxtshift > 12) {
            tcb->rxtshift = 12;
            TLobby__sub_8041A498((E_8041A498 *)tcb, 4);
            break;
        }
        rexmt = (tcb->srtt >> 3) + tcb->rttvar;
        rexmt *= g->backoff[tcb->rxtshift];
        tcb->rxtcur = rexmt;
        if (tcb->rxtcur < 2) {
            tcb->rxtcur = 2;
        } else if (tcb->rxtcur > 128) {
            tcb->rxtcur = 128;
        }
        tcb->timers[0] = tcb->rxtcur;
        if (tcb->rxtshift > 3) {
            tcb->rttvar += tcb->srtt >> 3;
            tcb->srtt = 0;
        }
        ((TLobby *)tcb)->reset_slot_index();
        tcb->f2EC = 0;
        tcb->f2F0 = 0;
        tcb->f2F4 = tcb->snd_una;
        tcb->snd_nxt = tcb->snd_una;
        tcb->rtt = 0;
        win = ((tcb->snd_wnd < tcb->snd_cwnd) ? tcb->snd_wnd : tcb->snd_cwnd) / 2 / tcb->maxseg;
        if (win < 2) {
            win = 2;
        }
        tcb->snd_cwnd = tcb->maxseg;
        tcb->snd_ssthresh = win * tcb->maxseg;
        TLobby__sub_8041A9AC((int)tcb);
        break;
    case 1:
        t = ((tcb->srtt >> 2) + tcb->rttvar) >> 1;
        tcb->timers[1] = t * g->backoff[tcb->rxtshift];
        if (tcb->timers[1] < 10) {
            tcb->timers[1] = 10;
        } else if (tcb->timers[1] > 120) {
            tcb->timers[1] = 120;
        }
        if (tcb->rxtshift < 12) {
            tcb->rxtshift++;
        }
        tcb->force = 1;
        TLobby__sub_8041A9AC((int)tcb);
        tcb->force = 0;
        break;
    case 2:
        if (tcb->t_state < 4) {
            goto drop;
        }
        keep = tcb->f2D4;
        if (keep != 0 && tcb->t_state <= 5) {
            if (tcb->idle >= keep + ((g->maxidle < keep * 8) ? g->maxidle : keep * 8)) {
                goto drop;
            }
            TLobby__sub_8041B3D4(tcb->remote, tcb->local, tcb->f268, tcb->f26A, tcb->snd_una - 1, tcb->rcv_nxt, 16);
            tcb->timers[2] = (g->keepintvl < tcb->f2D4) ? g->keepintvl : tcb->f2D4;
        } else if (keep != 0) {
            tcb->timers[2] = keep;
        } else {
            tcb->timers[2] = g->keepidle;
        }
        break;
    drop:
        TLobby__sub_8041A498((E_8041A498 *)tcb, 4);
        break;
    }
    return 0;
}
#pragma pop

struct SackBlock_8041A9AC {
    u32 start;
    u32 end;
};
/* BSD tcpcb view used by tcp_output (inferred: 0x8041A9AC follows the 4.4BSD tcp_output shape). */
struct Tcb_8041A9AC {
    u8 pad0[6];
    s16 t_state;
    u8 pad8[3];
    u8 flags;
    u8 force;
    u8 padD[0x1F7];
    u8 f204 : 1;
    u8 f204_bits : 7;
    u8 pad205[3];
    u32 snd_una;
    u32 snd_nxt;
    u32 snd_up;
    u8 pad214[0xC];
    u32 snd_wnd;
    u8 pad224[4];
    u32 rcv_nxt;
    u8 pad22C[8];
    u32 rcv_adv;
    u32 snd_max;
    u32 snd_cwnd;
    u32 snd_ssthresh;
    s16 idle;
    s16 rtt;
    u32 rtseq;
    s16 srtt;
    s16 rttvar;
    u32 max_sndwnd;
    s16 rxtcur;
    u8 pad256[2];
    u32 rxtshift;
    s16 timers[4];
    u16 maxseg;
    u8 pad266[2];
    TcpHeader_8041B3D4 tmpl;
    u8 remote[0x14];
    u8 local[0x14];
    u8 pad2A4[0x2C];
    s32 f2D0;
    u8 pad2D4[2];
    u8 f2D6[3];
    u8 pad2D9[3];
    u8 f2DC[0xC];
    u8 f2E8;
    u8 pad2E9[3];
    s32 f2EC;
    s32 f2F0;
    u32 f2F4;
    SackBlock_8041A9AC sack[5];
    u8 pad320[0x210];
    u32 f530;
    u32 f534;
    s16 ack_delay;
    u8 pad53A[6];
    s32 f540;
};
struct G_8041A9AC {
    Tcb_8041A9AC *tcbs;
    u8 pad4[0x24];
    u8 opt[0x28];
    u8 pad50;
    u8 outflags[0xB];
    s16 backoff[13];
    u8 pad76[0x32];
};

#pragma push
#pragma opt_common_subs on
s16 TLobby__sub_8041A9AC(int arg0) {
    Tcb_8041A9AC *tp = (Tcb_8041A9AC *)arg0;
    TcpHeader_8041B3D4 *ti = &tp->tmpl;
    u8 *opt;
    s32 len;
    s32 off;
    s32 flags;
    s32 win;
    s32 sendalot;
    s16 mss;
    G_8041A9AC *g = (G_8041A9AC *)&tcp_protocol_state;
    s32 fin;
    u8 *optp;
    u16 optlen;
    u16 lenidx;
    u16 i;
    s32 sndwin;
    s32 idle;
    NetPacket *m;
    s32 avail;
    s32 adv;
    s32 sack_start;
    s32 sack_end;
    u16 mssopt;
    u32 blk_start;
    u32 blk_end;
    u32 cc;
    u32 startseq;
    u8 sacklen;
    s16 error;

    if (tp->t_state < 0) {
        return -1;
    }
    if (TLobby__sub_8040DA54(tp->remote, tp->local) == 0) {
        NetDispatchSocketEvent((s16)(tp - g->tcbs), tp->f2D0, 3, 0xC);
        return -6;
    }
    mss = TLobby__sub_8040DC8C(tp->remote, tp->local);
    mss = (tp->maxseg < mss) ? tp->maxseg : mss;
    if (mss < 0) {
        return mss;
    }
    idle = (tp->snd_max == tp->snd_una);
    if (tp->snd_max == tp->snd_una && tp->idle >= (u16)tp->rxtcur) {
        switch (tp->f540) {
        case 1:
            tp->snd_cwnd = tp->maxseg;
            break;
        case 2:
            tp->snd_cwnd = tp->maxseg * 2;
            break;
        case 3:
            tp->snd_cwnd = (tp->maxseg * 4 < ((tp->maxseg * 2 > 4380) ? tp->maxseg * 2 : 4380))
                               ? tp->maxseg * 4
                               : ((tp->maxseg * 2 > 4380) ? tp->maxseg * 2 : 4380);
            break;
        default:
            tp->snd_cwnd = get_adjusted_slot_count__6TLobbyFPv((u8 *)tp);
            break;
        }
    }
    opt = g->opt;
again:
    sendalot = 0;
    len = 0;
    if (tp->f2F4 != tp->snd_una) {
        len = TLobby__sub_8041D460((Tcb_8041D460 *)tp, &sack_start, &sack_end);
        if (len != 0) {
            sendalot = 1;
            off = sack_start - tp->snd_una;
        } else {
            off = tp->snd_nxt - tp->snd_una;
        }
    } else {
        off = tp->snd_nxt - tp->snd_una;
    }
    sndwin = tp->snd_wnd;
    flags = g->outflags[tp->t_state];
    if (tp->force) {
        if (sndwin == 0) {
            sndwin = 1;
        } else {
            tp->timers[1] = 0;
            tp->rxtshift = 0;
        }
    }
    if (len == 0) {
        len = (((u32)((TLobby *)tp)->get_score() < (u32)sndwin) ? ((TLobby *)tp)->get_score() : sndwin) - off;
    }
    avail = tp->snd_cwnd - tp->f2F0;
    if (tp->f2F4 == tp->snd_una) {
        avail -= tp->snd_nxt - tp->snd_una;
    }
    if (avail < 0) {
        avail = 0;
    }
    if (len > avail) {
        len = avail;
        sendalot = 0;
    }
    if (off + len < ((TLobby *)tp)->get_score()) {
        flags &= ~1;
    }
    if (len < 0) {
        len = 0;
        if (sndwin == 0) {
            tp->timers[0] = 0;
            tp->snd_nxt = tp->snd_una;
        }
    }
    if ((u32)len > tp->maxseg) {
        len = tp->maxseg;
        sendalot = 1;
    }
    if ((s32)((tp->snd_nxt + len) - (tp->snd_una + ((TLobby *)tp)->get_score())) < 0) {
        flags &= ~1;
    }
    win = ((TLobby *)tp)->get_queue_diff();
    fin = flags & 1;
    if (fin && (!(tp->flags & 0x10) || tp->snd_nxt == tp->snd_una)) {
        goto send;
    }
    if (tp->flags & 1) {
        goto send;
    }
    if (flags & 6) {
        goto send;
    }
    if ((s32)(tp->snd_up - tp->snd_una) > 0) {
        goto send;
    }
    if (len != 0) {
        if ((u32)len == tp->maxseg) {
            goto send;
        }
        if (sendalot) {
            goto send;
        }
        if (tp->f204 == 1) {
            cc = ((TLobby *)tp)->get_score();
        } else {
            cc = ((u32)((TLobby *)tp)->get_score() < tp->f530) ? ((TLobby *)tp)->get_score() : tp->f530;
        }
        if ((idle || (tp->flags & 4)) && len + off >= (s32)cc) {
            goto send;
        }
        if (tp->force) {
            goto send;
        }
        if ((u32)len >= tp->max_sndwnd / 2) {
            goto send;
        }
        if ((s32)(tp->snd_nxt - tp->snd_max) < 0) {
            goto send;
        }
    }
    if (win > 0) {
        adv = win - (s32)(tp->rcv_adv - tp->rcv_nxt);
        if (adv < 0) {
            adv = -adv;
        }
        if ((u32)adv >= (u32)(((tp->maxseg > 40) ? tp->maxseg - 40 : 1) * 2)) {
            goto send;
        }
        if (adv * 2 >= ((TLobby *)tp)->get_field_534()) {
            goto send;
        }
    }
    if ((u32)((TLobby *)tp)->get_score() != 0 && tp->timers[0] == 0 && tp->timers[1] == 0) {
        tp->rxtshift = 0;
        tp->timers[1] = (((tp->srtt >> 2) + tp->rttvar) >> 1) * g->backoff[tp->rxtshift];
        if (tp->timers[1] < 10) {
            tp->timers[1] = 10;
        } else if (tp->timers[1] > 120) {
            tp->timers[1] = 120;
        }
        if (tp->rxtshift < 12) {
            tp->rxtshift++;
        }
    }
    return 0;

send:
    if (fin && (tp->flags & 0x10) && tp->snd_nxt == tp->snd_max) {
        tp->snd_nxt--;
        off--;
    }
    optp = NULL;
    ti->seq = tp->snd_una + off;
    optlen = 0;
    ti->ack = tp->rcv_nxt;
    if (flags & 2) {
        tp->f2EC = 0;
        ((TLobby *)tp)->reset_slot_index();
        opt[0] = 2;
        optp = opt;
        opt[1] = 4;
        mssopt = (tp->f534 < mss) ? tp->f534 : mss;
        NetMemcpy(optp + 2, &mssopt, 2);
        optlen = 4;
        if (tp->f2E8 & 1) {
            opt[4] = 4;
            opt[5] = 2;
            optlen = 8;
            opt[6] = 1;
            opt[7] = 1;
        }
    }
    if ((tp->f2E8 & 2) && tp->sack[0].start != tp->sack[0].end) {
        opt[optlen++] = 1;
        opt[optlen++] = 1;
        opt[optlen] = 5;
        lenidx = optlen + 1;
        optp = opt;
        sacklen = 2;
        optlen += 2;
        for (i = 0; i < 5 && tp->sack[i].start != tp->sack[i].end && optlen + 8 <= 40; i++) {
            blk_start = tp->sack[i].start;
            blk_end = tp->sack[i].end;
            NetMemcpy(optp + optlen, &blk_start, 4);
            optlen += 4;
            NetMemcpy(optp + optlen, &blk_end, 4);
            optlen += 4;
            sacklen += 8;
        }
        opt[lenidx] = sacklen;
    }
    while (optlen % 4 != 0) {
        optp[optlen++] = 1;
    }
    if (len > tp->maxseg - optlen) {
        len = tp->maxseg - optlen;
        flags &= ~1;
        sendalot = 1;
    }
    ti->flags = flags;
    if ((u32)win < (u32)((TLobby *)tp)->get_field_534() / 4 && (u32)win < tp->maxseg) {
        win = 0;
    }
    if (win < (s32)(tp->rcv_adv - tp->rcv_nxt)) {
        win = tp->rcv_adv - tp->rcv_nxt;
    }
    if ((u32)win > tp->f534) {
        win = tp->f534;
    }
    ti->window = win;
    if ((s32)(tp->snd_up - tp->snd_nxt) > 0) {
        ti->urgent = tp->snd_up - tp->snd_nxt;
        flags |= 0x20;
    } else {
        tp->snd_up = tp->snd_una;
    }
    if (len != 0 && off + len == ((TLobby *)tp)->get_score()) {
        flags |= 8;
    }
    ti->checksum = 0;
    ti->flags = flags;
    ti->data_offset = ((optlen + 20) >> 2) << 4;
    m = (NetPacket *)TLobby::alloc_free_entry();
    if (m == NULL) {
        return -0x101;
    }
    m->fragment_count = 0;
    m->total_bytes = 0;
    if (TLobby__sub_80420410(off, len, m, tp) < 0) {
        m->fragment_count = 0;
        m->total_bytes = 0;
    }
    if (optlen != 0) {
        m->total_bytes += optlen;
        m->fragments[m->fragment_count].length = optlen;
        ((TLobby *)&m->fragments[m->fragment_count].buffer)->set_value_and_enable((s32)optp);
        m->fragment_count++;
    }
    m->total_bytes += sizeof(TcpHeader_8041B3D4);
    m->fragments[m->fragment_count].length = sizeof(TcpHeader_8041B3D4);
    ((TLobby *)&m->fragments[m->fragment_count].buffer)->set_value_and_enable((s32)ti);
    m->fragment_count++;
    ti->checksum = TLobby__sub_8040D8F0(tp->local, tp->remote, 6, (u8 *)m, 1);
    if (!tp->force || tp->timers[1] == 0) {
        startseq = tp->snd_nxt;
        if (flags & 2) {
            tp->snd_nxt++;
        }
        if (flags & 1) {
            tp->snd_nxt++;
            tp->flags |= 0x10;
        }
        if (tp->snd_una != tp->f2F4) {
            tp->f2F0 += len;
        }
        if (len > 0) {
            if ((s32)(len + (off + tp->snd_una) - tp->snd_nxt) > 0) {
                tp->snd_nxt += len;
            } else {
                TLobby__sub_8041D398((Tcb_8041D460 *)tp, off + tp->snd_una, len + (off + tp->snd_una));
            }
        }
        if ((s32)(tp->snd_nxt - tp->snd_max) > 0) {
            tp->snd_max = tp->snd_nxt;
            if (tp->rtt == 0) {
                tp->rtt = 1;
                tp->rtseq = startseq;
            }
        }
        if (tp->timers[0] == 0 && tp->snd_nxt != tp->snd_una) {
            tp->timers[0] = tp->rxtcur;
            if (tp->timers[1] != 0) {
                tp->timers[1] = 0;
                tp->rxtshift = 0;
            }
        }
    } else if ((s32)(tp->snd_nxt + len - tp->snd_max) > 0) {
        tp->snd_max = tp->snd_nxt + len;
    }
    error = TLobby::dispatch_by_addr_family((s32)m, tp->remote, tp->local, tp->f2D6, tp->f2DC, (void *)6);
    ((TUdpSocket *)m)->release_entry();
    if (error < 0) {
        return error;
    }
    if (win > 0 && (s32)(tp->rcv_nxt + win - tp->rcv_adv) > 0) {
        tp->rcv_adv = tp->rcv_nxt + win;
    }
    tp->flags &= ~1;
    tp->ack_delay = 0;
    if (sendalot) {
        NetYieldOutsideDispatcherThread();
        goto again;
    }
    return 0;
}
#pragma pop

struct Tcb_8041B724 { u8 pad0[0x264]; u16 maxseg; u8 pad266[0x16]; u8 remote[0x14]; u8 local[0x14]; };

s16 TLobby__sub_8041B724(u8 *tcb) {
    Tcb_8041B724 *tp = (Tcb_8041B724 *)tcb;
    s32 mss = TLobby__sub_8040DC8C(tp->remote, tp->local);

    return tp->maxseg < mss ? tp->maxseg : mss;
}

struct Tcb_8041B774 {
    u8 pad0[4];
    u16 state;
    u8 pad6[2];
    s16 listener;
    u8 padA;
    u8 flags;
    u8 padC[0x258];
    u16 maxseg;
    u8 pad266[2];
    u16 lport;
    u16 f26A;
    u8 pad26C[0x10];
    u8 f27C[0x14];
    u8 laddr[0x14];
    u8 pad2A4[0x20];
    s16 f2C4;
    s16 pending;
    u8 pad2C8[8];
    s32 f2D0;
    u8 pad2D4[2];
    u8 f2D6[3];
    u8 pad2D9[3];
    u8 f2DC[0xC];
    u8 f2E8;
    u8 pad2E9[0x247];
    s32 f530;
    s32 f534;
    u8 pad538[4];
    s32 f53C;
    u32 f540;
};

#pragma push
#pragma pool_data off
Tcb_8041B774 *TLobby__sub_8041B774(Tcb_8041B774 *lst, u16 *port, u8 *local, u8 *remote) {
    s16 TLobby__sub_8041E780(void);
    s16 TLobby__sub_8041ECA4(u8 *);
    s16 TLobby__sub_8041EC14(u8 *);
    s16 is_addr_unspecified__6TLobbyFPv(u8 *);
    Tcb_8041B774 *tcb;
    s16 idx;
    s32 mss;
    s16 seg;

    if (lst->f2C4 <= lst->pending) {
        return NULL;
    }
    idx = TLobby__sub_8041E780();
    if (idx < 0) {
        return NULL;
    }
    tcb = (Tcb_8041B774 *)tcp_protocol_state.p;
    tcb += idx;
    tcb->lport = lst->lport;
    if (lst->f26A == 0) {
        tcb->f26A = *port;
    } else {
        tcb->f26A = lst->f26A;
    }
    if (is_addr_unspecified__6TLobbyFPv(lst->f27C)) {
        NetMemcpy(tcb->f27C, local, sizeof(tcb->f27C));
    } else {
        NetMemcpy(tcb->f27C, lst->f27C, sizeof(tcb->f27C));
    }
    NetMemcpy(tcb->laddr, remote, sizeof(tcb->laddr));
    NetMemcpy(tcb->f2D6, lst->f2D6, sizeof(tcb->f2D6));
    NetMemcpy(tcb->f2DC, lst->f2DC, sizeof(tcb->f2DC));
    mss = TLobby__sub_8040DC8C(tcb->f27C, tcb->laddr);
    seg = tcb->maxseg < mss ? tcb->maxseg : mss;
    if (seg < 0) {
        tcb->state = 0;
        return NULL;
    }
    tcb->f530 = lst->f530;
    tcb->f534 = lst->f534;
    if (TLobby__sub_8041ECA4((u8 *)tcb) < 0) {
        tcb->state = 0;
        return NULL;
    }
    if (TLobby__sub_8041EC14((u8 *)tcb) < 0) {
        ((TLobby *)tcb)->close_if_open();
        tcb->state = 0;
        return NULL;
    }
    tcb->f2D0 = lst->f2D0;
    tcb->listener = lst - (Tcb_8041B774 *)tcp_protocol_state.p;
    lst->pending++;
    tcb->f2E8 = lst->f2E8;
    tcb->f53C = lst->f53C;
    tcb->f540 = lst->f540;
    tcb->flags = lst->flags;
    tcb->maxseg = lst->maxseg;
    return tcb;
}
#pragma pop

void TLobby::insert_item_at(s16 idx, s32 a, s32 b) {
    O_8041D2B8 *o = (O_8041D2B8 *)this;
    s16 i;
    if (idx < 0) {
        return;
    }
    s16 n = o->n;
    if (idx > n + 1) {
        return;
    }
    if (idx > 0x1F) {
        return;
    }
    if (n >= 0x1F) {
        o->n = 0x1E;
    }
    for (i = o->n; i >= idx; i--) {
        o->items[i + 1] = o->items[i];
    }
    o->items[idx].a = a;
    o->items[idx].b = b;
    o->items[idx].c = b;
    o->items[idx].d = o->f238;
    o->n++;
}

s16 TLobby__sub_8041D368(u8 *arg0) {
    struct Fields_arg0 { u8 pad_0[800]; s16 field_320; };
    if ((s16) ((Fields_arg0*)arg0)->field_320 == -1) {
        return 1;
    }
    return 0;
}

void TLobby::reset_slot_index() {
    u8 *arg0 = (u8 *)this;
    *(s16 *)((s8 *)arg0 + 0x320) = -1;
    *(s32 *)((s8 *)arg0 + 0x328) = (s32) *(s32 *)((s8 *)arg0 + 0x324);
}

struct Seg_8041D460 { s32 start; s32 end; s32 edge; s32 stamp; };
struct Tcb_8041D460 {
    u8 pad0[0x238];
    s32 now;
    u8 pad23C[0xB0];
    s32 f2EC;
    u8 pad2F0[0x30];
    s16 n;
    u8 pad322[6];
    s32 edge;
    s32 stamp;
    Seg_8041D460 items[32];
};

#pragma push
#pragma opt_common_subs on
void TLobby__sub_8041D398(Tcb_8041D460 *tp, s32 start, s32 end) {
    s16 i;
    s32 seg;

    tp->f2EC += end - start;
    for (i = 0; i <= tp->n; i++) {
        seg = tp->items[i].start;
        if (start - seg < 0) {
            if (i == 0) {
                if (end - seg <= 0) {
                    if (end - tp->edge >= 0) {
                        tp->edge = end;
                        tp->stamp = tp->now;
                    }
                    return;
                }
                tp->edge = seg;
                tp->stamp = tp->now;
            } else {
                if (end - seg <= 0) {
                    if (end - tp->items[i - 1].edge >= 0) {
                        tp->items[i - 1].edge = end;
                        tp->items[i - 1].stamp = tp->now;
                    }
                    return;
                }
                tp->items[i - 1].edge = seg;
                tp->items[i - 1].stamp = tp->now;
            }
        }
    }
}
#pragma pop

s32 TLobby__sub_8041D460(Tcb_8041D460 *tp, s32 *start, s32 *end) {
    s16 n = tp->n;
    s16 i;

    if (n == -1) {
        *end = 0;
        *start = 0;
        return 0;
    }
    if (tp->edge - tp->items[0].start < 0) {
        *start = tp->edge;
        *end = tp->items[0].start;
        return *end - *start;
    }
    for (i = 0; i < n; i++) {
        if (tp->items[i].edge - tp->items[i + 1].start < 0) {
            *start = tp->items[i].edge;
            *end = tp->items[i + 1].start;
            return *end - *start;
        }
    }
    *end = 0;
    *start = 0;
    return 0;
}

struct A_8041D524 { u8 pad[0x320]; s16 n; u8 pad2[0xA]; s32 v0; u8 pad3[0xC]; s32 v1; };
s32 TLobby__sub_8041D524(A_8041D524 *a, s32 x) {
    s16 n = a->n;
    s16 i;
    if (n == -1) { return 0; }
    if (a->v0 - x < 0) { return 1; }
    for (i = 0; i < n; i++) {
        if (a->v1 - x < 0) { return 1; }
        a = (A_8041D524 *)((u8 *)a + 0x10);
    }
    return 0;
}

struct Th_8041D584 {
    u8 pad0[8];
    s32 ack;
};

struct Sack_8041D584 {
    s32 start;
    s32 end;
};

struct Tcb_8041D584 {
    u8 pad0[0x238];
    s32 now;
    u8 pad23C[0xB0];
    s32 f2EC;
    u8 pad2F0[0x30];
    s16 n;
    u8 pad322[2];
    s32 una;
    s32 edge;
    s32 stamp;
    Seg_8041D460 items[32];
};

#pragma push
#pragma dont_inline off
#pragma opt_common_subs on
inline void remove_8041D584(Tcb_8041D584 *tcb, s16 idx) {
    s16 n = tcb->n;
    s16 i;
    if (n >= 0 && idx >= 0 && idx <= n) {
        for (i = idx; i < tcb->n; i++) {
            tcb->items[i] = tcb->items[i + 1];
        }
        tcb->n--;
    }
}

void TLobby__sub_8041D584(Tcb_8041D584 *tcb, Th_8041D584 *th, Sack_8041D584 *blocks, s16 n) {
    s16 i;
    s16 j;
    s32 d;

    if (th->ack - tcb->una > 0) {
        for (;;) {
            if (tcb->n < 0) {
                break;
            }
            if (th->ack - tcb->edge > 0) {
                tcb->f2EC -= tcb->edge - tcb->una;
                tcb->edge = th->ack;
                if (tcb->f2EC < 0) {
                    tcb->f2EC = 0;
                }
            } else {
                tcb->f2EC -= th->ack - tcb->una;
                if (tcb->f2EC < 0) {
                    tcb->f2EC = 0;
                }
            }
            if (th->ack - tcb->items[0].end >= 0) {
                tcb->edge = tcb->items[0].edge;
                tcb->stamp = tcb->items[0].stamp;
                tcb->una = tcb->items[0].end;
                remove_8041D584(tcb, 0);
                continue;
            }
            if (th->ack - tcb->items[0].start >= 0) {
                tcb->n = -1;
                tcb->edge = tcb->una;
            }
            break;
        }
        tcb->una = th->ack;
    }

    for (i = 0; i < n; i++) {
        s32 end = blocks[i].end;
        s32 start = blocks[i].start;
        Sack_8041D584 *b = &blocks[i];
        if (start - end >= 0) {
            continue;
        }
        if (tcb->n == -1) {
            tcb->edge = th->ack;
            tcb->stamp = tcb->now;
            ((TLobby *)tcb)->insert_item_at(0, b->start, b->end);
            continue;
        }
        if (end - tcb->una <= 0) {
            continue;
        }
        if (start - tcb->una <= 0) {
            tcb->n = -1;
            tcb->edge = tcb->una;
            continue;
        }
        if (start - tcb->items[0].start <= 0) {
            if (start - tcb->edge < 0) {
                tcb->f2EC -= tcb->edge - start;
                tcb->edge = b->start;
                if (tcb->f2EC < 0) {
                    tcb->f2EC = 0;
                }
            }
            ((TLobby *)tcb)->insert_item_at(0, b->start, b->end);
            j = 0;
        } else {
            for (j = 1; j <= tcb->n; j++) {
                if (b->start - tcb->items[j].start > 0) {
                    continue;
                }
                if (b->start - tcb->items[j - 1].end < 0) {
                    if (b->end - tcb->items[j - 1].end < 0) {
                        continue;
                    }
                    if (end - tcb->items[j - 1].edge > 0) {
                        tcb->f2EC -= tcb->items[j - 1].edge - tcb->items[j - 1].end;
                        tcb->items[j - 1].end = b->end;
                        tcb->items[j - 1].edge = b->end;
                        if (tcb->f2EC < 0) {
                            tcb->f2EC = 0;
                        }
                    } else {
                        tcb->f2EC -= end - tcb->items[j - 1].end;
                        tcb->items[j - 1].end = b->end;
                        if (tcb->f2EC < 0) {
                            tcb->f2EC = 0;
                        }
                    }
                    j = j - 1;
                } else {
                    if (start - tcb->items[j - 1].edge < 0) {
                        tcb->f2EC -= tcb->items[j - 1].edge - start;
                        tcb->items[j - 1].edge = b->start;
                        if (tcb->f2EC < 0) {
                            tcb->f2EC = 0;
                        }
                    }
                    ((TLobby *)tcb)->insert_item_at(j, b->start, b->end);
                }
                break;
            }
            if (j == tcb->n + 1) {
                ((TLobby *)tcb)->insert_item_at(j, b->start, b->end);
                continue;
            }
        }
        while (j + 1 <= tcb->n && tcb->items[j].end - tcb->items[j + 1].start >= 0) {
            d = tcb->items[j].end - tcb->items[j + 1].end;
            if (0 <= d) {
                if (tcb->items[j + 1].edge - tcb->items[j].end > 0) {
                    tcb->f2EC -= d;
                    tcb->items[j].edge = tcb->items[j + 1].edge;
                    remove_8041D584(tcb, j + 1);
                    if (tcb->f2EC < 0) {
                        tcb->f2EC = 0;
                    }
                } else {
                    tcb->f2EC -= tcb->items[j + 1].edge - tcb->items[j + 1].end;
                    remove_8041D584(tcb, j + 1);
                    if (tcb->f2EC < 0) {
                        tcb->f2EC = 0;
                    }
                }
            } else {
                tcb->items[j].end = tcb->items[j + 1].end;
                tcb->items[j].edge = tcb->items[j + 1].edge;
                remove_8041D584(tcb, j + 1);
            }
        }
    }
}
#pragma pop

#pragma push
#pragma pool_data off
s16 TLobby::tcp_get_socket_handle(s16 i) {
    s16 r;
    if (i < 0 || i >= tcp_protocol_state.n) {
        r = -4;
    } else if (tcp_protocol_state.p[i].f4 != 1) {
        r = -4;
    } else {
        r = 0;
    }
    if (r < 0) { return -4; }
    return tcp_protocol_state.p[i].f6;
}
#pragma pop

s32 TLobby__sub_8041ED8C(int, void *, void *, void *);

#pragma push
#pragma opt_propagation off
#pragma push
#pragma pool_data off
s32 TLobby__sub_8041DBD4(s16 arg0, s32 arg1, s32 len, s32 arg3) {
    s16 r;
    E_805C1D48 *e;

    if (arg0 < 0 || arg0 >= tcp_protocol_state.n) {
        r = -4;
    } else if (tcp_protocol_state.p[arg0].f4 != 1) {
        r = -4;
    } else {
        r = 0;
    }
    if (r < 0) {
        return -4;
    }
    e = tcp_protocol_state.p;
    e += arg0;
    switch (e->f6) {
    case 0:
    case 4: case 5: case 6: case 7: case 8: case 9: case 10:
        if ((*(u8 *)((s8 *)e + 0xA) & 4) && (*(u8 *)((s8 *)e + 0xCC) == 0 || (u32)((TLobby *)e)->get_field_d8() == 0)) {
            return -4;
        }
        break;
    }
    return TLobby__sub_8041ED8C((int)e, (void *)arg1, (void *)len, (void *)arg3);
}
#pragma pop

#pragma pop

#pragma push
#pragma opt_propagation off
#pragma push
#pragma pool_data off
s16 tcp_start_send(s16 arg0, u8 *arg1, void (*completion)(s16, s16), u8 arg3) {
    s16 r;
    s16 v;
    s16 ret;
    E_805C1D48 *e;
    if (arg0 < 0 || arg0 >= tcp_protocol_state.n) {
        r = -4;
    } else if (tcp_protocol_state.p[arg0].f4 != 1) {
        r = -4;
    } else {
        r = 0;
    }
    if (r < 0) {
        return -4;
    }
    e = tcp_protocol_state.p;
    e += arg0;
    v = e->f6;
    if (v <= 1) {
        return -4;
    }
    if (v < 4) {
        return -4;
    }
    if (v > 5 && (*(u8 *)((s8 *)e + 0xA) & 8)) {
        return -4;
    }
    TLobby__sub_80420BD0(arg1, e, (s32)completion);
    if (arg3 != 0) {
        *(s32 *)((s8 *)e + 0x210) = *(s32 *)((s8 *)e + 0x20C) + *(s32 *)((s8 *)arg1 + 8);
    }
    ret = TLobby__sub_8041A9AC((int)e);
    TLobby__sub_8041FFF8(0, (int)e);
    return ret;
}
#pragma pop

#pragma pop

struct Tcb_8041DE1C {
    u8 pad0[0xB];
    u8 flags;
    u8 padC[0x238];
    s16 f244;
    u8 pad246[0x1A];
    s16 f260;
    u8 pad262[2];
    u16 maxseg;
    u8 pad266[0x6E];
    s16 f2D4;
    u8 pad2D6[0x12];
    u8 f2E8;
    u8 pad2E9[0x247];
    u32 f530;
    u32 f534;
    u8 pad538[4];
    s32 f53C;
    u32 f540;
};

struct G_8041DE1C {
    Tcb_8041DE1C *tcbs;
    s16 count;
    s16 freed;
    u32 f8;
    u32 fC;
};

#pragma push
#pragma pool_data off
s32 TLobby__sub_8041DE1C(s16 i, s16 opt, u32 *val) {
    s16 r;
    G_8041DE1C *g;
    Tcb_8041DE1C *tcb;
    u16 seg;

    if (i < 0 || i >= tcp_protocol_state.n) {
        r = -4;
    } else if (tcp_protocol_state.p[i].f4 != 1) {
        r = -4;
    } else {
        r = 0;
    }
    if (r < 0) {
        return -4;
    }
    g = (G_8041DE1C *)&tcp_protocol_state;
    tcb = g->tcbs;
    tcb += i;
    switch (opt) {
    case 0x8:
        tcb->f2D4 = *val * 2;
        tcb->f260 = tcb->f2D4;
        tcb->f244 = 0;
        break;
    case 0x1001:
        if (*val > g->f8) {
            return -2;
        }
        tcb->f530 = *val;
        break;
    case 0x1002:
        if (*val > g->fC) {
            return -2;
        }
        tcb->f534 = *val;
        break;
    case 0x2001:
        if (*val != 0) {
            tcb->f53C = 1;
        } else {
            tcb->f53C = 0;
        }
        break;
    case 0x2002:
        if (*val != 0) {
            tcb->f2E8 |= 1;
        } else {
            tcb->f2E8 &= ~1;
        }
        break;
    case 0x2004:
        if (*val > 3) {
            return -2;
        }
        tcb->f540 = *val;
        break;
    case 0x2008:
        if (*val != 0) {
            tcb->flags |= 4;
        } else {
            tcb->flags &= ~4;
        }
        break;
    case 0x2010:
        seg = *val;
        if (seg < 40 || seg > tcb->maxseg) {
            return -2;
        }
        tcb->maxseg = seg;
        break;
    case 0x2020:
        if (*val != 0) {
            tcb->flags |= 0x40;
        } else {
            tcb->flags &= ~0x40;
        }
        break;
    default:
        return -2;
    }
    return 0;
}
#pragma pop

#pragma push
#pragma opt_propagation off
#pragma push
#pragma pool_data off
s32 TLobby::get_tcp_stat(s16 arg0, s16 *arg1, s16 *arg2, s32 *arg3, s32 *arg4) {
    s16 r;
    E_805C1D48 *e;

    if (arg0 < 0 || arg0 >= tcp_protocol_state.n) {
        r = -4;
    } else if (tcp_protocol_state.p[arg0].f4 != 1) {
        r = -4;
    } else {
        r = 0;
    }
    if (r < 0) {
        return -4;
    }
    e = tcp_protocol_state.p;
    e += arg0;
    if (arg1 != NULL) {
        *arg1 = e->f6;
    }
    if (arg2 != NULL) {
        if (e->f6 == 1) {
            *arg2 = *(s16 *)((s8 *)e + 0x2C6);
        } else {
            *arg2 = 0;
        }
    }
    if (arg3 != NULL) {
        *arg3 = get_adjusted_slot_count__6TLobbyFPv((u8 *)e);
    }
    if (arg4 != NULL) {
        *arg4 = ((TLobby *)e)->get_field_d8();
    }
    return 0;
}
#pragma pop

#pragma pop

typedef char RecoveredGlobal_8041E178_lbl_805C1D48_size[sizeof(RecoveredGlobal_8041E178_lbl_805C1D48) == 0xA8 ? 1 : -1];
#pragma push
#pragma pool_data off
s32 TLobby::mark_connection_closed(s16 arg0) {
    struct Fields_var_r4 { u8 pad_0[4]; u16 field_4; };
    struct Fields_var_r3 { u8 pad_0[6]; s16 field_6; u8 pad_8[3]; u8 field_B; };
    s32 *var_r3;
    s32 *var_r4;
    s16 var_r0;
    s16 var_r5;
    if ((arg0 < 0) || (var_r4 = &tcp_protocol_state.value, var_r4 = &tcp_protocol_state.value, var_r5 = arg0, ((var_r5 < (s16) *(s16 *)((s8 *)(&tcp_protocol_state.value) + 4)) == 0))) {
        var_r0 = -4;
    } else {
        var_r4 = (s32 *)(*(s32 **)((s8 *)(&tcp_protocol_state.value) + 0));
        var_r4 = (s32 *)((u8 *)var_r4 + (var_r5 * 0x544));
        if ((u16) ((Fields_var_r4*)var_r4)->field_4 != 1) {
            var_r0 = -4;
        } else {
            var_r0 = 0;
        }
    }
    if (var_r0 < 0) {
        var_r3 = (s32 *)((u8 *)((s32 *)-4));
        return -4;
    }
    var_r3 = (s32 *)(&tcp_protocol_state.value);
    var_r3 = (s32 *)(&tcp_protocol_state.value);
    var_r3 = (s32 *)(*(s32 **)((s8 *)(&tcp_protocol_state.value) + 0));
    var_r3 = (s32 *)((u8 *)var_r3 + (arg0 * 0x544));
    ((Fields_var_r3*)var_r3)->field_6 = 0;
    ((Fields_var_r3*)var_r3)->field_B = (u8) (((Fields_var_r3*)var_r3)->field_B | 0x80);
    TLobby__sub_8041B5C0(var_r3);
    var_r3 = (s32 *)(NULL);
    return 0;
}
#pragma pop

#pragma push
#pragma opt_propagation off
#pragma push
#pragma pool_data off
s32 TLobby::abort_tcp_connection(s16 arg0) {
    s16 r;
    E_805C1D48 *e;

    if (arg0 < 0 || arg0 >= tcp_protocol_state.n) {
        r = -4;
    } else if (tcp_protocol_state.p[arg0].f4 != 1) {
        r = -4;
    } else {
        r = 0;
    }
    if (r < 0) {
        return -4;
    }
    e = tcp_protocol_state.p;
    e += arg0;
    if (e->f6 < 4) {
        e->f6 = 0;
    } else {
        e->f6 = 0;
        TLobby__sub_8041A9AC((int)e);
    }
    ((TLobby *)e)->clear_position();
    return 0;
}
#pragma pop

#pragma pop

struct Tcb_8041E2EC { u8 pad0[0x2D6]; u8 f2D6[3]; u8 pad2D9[3]; u8 f2DC[0xC]; u8 pad2E8[0x25C]; };

void TLobby__sub_8041E2EC(s16 idx, u8 *a, u8 *b) {
    Tcb_8041E2EC *e;

    e = (Tcb_8041E2EC *)tcp_protocol_state.p;
    e += idx;
    NetMemcpy(e->f2D6, a, sizeof(e->f2D6));
    NetMemcpy(e->f2DC, b, sizeof(e->f2DC));
}

s16 TLobby__sub_8041B724(u8 *);
u16 TLobby__sub_8041EA14(void);
#pragma push
#pragma opt_propagation off
#pragma push
#pragma pool_data off
s16 TLobby::tcp_connect_start(s16 arg0, s32 arg1, s16 arg2) {
    s16 r;
    E_805C1D48 *e;
    s16 TLobby__sub_8040DA54(u8 *arg0, u8 *arg1);
    s16 is_addr_unspecified__6TLobbyFPv(u8 *arg0);
    s16 select_source_address__6TLobbyFPvPv(void *, void *);
    s16 TLobby__sub_8041A9AC(void *);
    s16 TLobby__sub_8041EC14(u8 *);
    s16 TLobby__sub_8041ECA4(u8 *arg0);
    u16 get_adjusted_slot_count__6TLobbyFPv(u8 *arg0);
    void NetDispatchSocketEvent(s16, s32, s32, s16);

    if (arg0 < 0 || arg0 >= tcp_protocol_state.n) {
        r = -4;
    } else if (tcp_protocol_state.p[arg0].f4 != 1) {
        r = -4;
    } else {
        r = 0;
    }
    if (r < 0) {
        return -4;
    }
    e = tcp_protocol_state.p;
    e += arg0;
    if (TLobby__sub_8040DA54((u8 *)arg1, (u8 *)e + 0x290) == 0) {
        NetDispatchSocketEvent((s16)(e - tcp_protocol_state.p), *(s32 *)((s8 *)e + 0x2D0), 3, 0xC);
        return -6;
    }
    if (is_addr_unspecified__6TLobbyFPv((u8 *)e + 0x290) != 0 && select_source_address__6TLobbyFPvPv((u8 *)e + 0x290, (void *)arg1) < 0) {
        NetDispatchSocketEvent((s16)(e - tcp_protocol_state.p), *(s32 *)((s8 *)e + 0x2D0), 3, 0xC);
        return -6;
    }
    if (*(u16 *)((s8 *)e + 0x268) == 0) {
        *(u16 *)((s8 *)e + 0x268) = TLobby__sub_8041EA14();
    }
    NetMemcpy((u8 *)e + 0x27C, (void *)arg1, 0x14);
    *(s16 *)((s8 *)e + 0x26A) = arg2;
    if (TLobby__sub_8041B724((u8 *)e) < 0) {
        return -6;
    }
    r = TLobby__sub_8041ECA4((u8 *)e);
    if (r < 0) {
        return r;
    }
    r = TLobby__sub_8041EC14((u8 *)e);
    if (r < 0) {
        ((TLobby *)e)->close_if_open();
        return r;
    }
    *(u32 *)((s8 *)e + 0x23C) = get_adjusted_slot_count__6TLobbyFPv((u8 *)e);
    e->f6 = 2;
    *(s16 *)((s8 *)e + 0x260) = 0x96;
    {
        s32 *t = (s32 *)((u8 *)&tcp_protocol_state + 0x18);
        s32 v = *t;
        *(s32 *)((s8 *)e + 0x21C) = v;
        *(s32 *)((s8 *)e + 0x324) = v;
        *(s32 *)((s8 *)e + 0x2F4) = v;
        *(s32 *)((s8 *)e + 0x210) = v;
        *(s32 *)((s8 *)e + 0x238) = v;
        *(s32 *)((s8 *)e + 0x20C) = v;
        *(s32 *)((s8 *)e + 0x208) = v;
        *t += 0xFA00;
    }
    return TLobby__sub_8041A9AC(e);
}
#pragma pop

#pragma pop

struct Tcb_8041E590 { u8 pad0[4]; u16 state; s16 f6; s16 listener; u8 padA[0x2BC]; s16 pending; u8 pad2C8[0x27C]; };

s32 TLobby__sub_8041E590(s16 idx) {
    Tcb_8041E590 *ents;
    s16 l;
    Tcb_8041E590 *t;
    Tcb_8041E590 *e;

    ents = (Tcb_8041E590 *)tcp_protocol_state.p;
    e = ents;
    e += idx;
    if ((l = e->listener) >= 0) {
        t = ents;
        t += l;
        if (t->state == 1) {
            t->pending--;
        }
    }
    e->listener = -1;
    return 0;
}

struct Pair_8041E780 {
    s32 a;
    s32 b;
};
struct Tcb_8041E780 {
    u8 tag[3];
    u8 index;
    u16 state;
    s16 f6;
    s16 listener;
    u8 fA;
    u8 flags;
    u8 padC[0x234];
    s32 f240;
    u8 pad244[8];
    s16 f24C;
    s16 f24E;
    u8 pad250[4];
    u16 f254;
    u8 pad256[6];
    s16 timers[4];
    u16 maxseg;
    u16 f266;
    u16 lport;
    u8 pad26A[0x26];
    u8 laddr[0x14];
    u8 pad2A4[0x22];
    s16 pending;
    u8 pad2C8[8];
    s32 f2D0;
    u8 pad2D4[2];
    u8 f2D6[3];
    u8 pad2D9[3];
    u8 f2DC[0xC];
    u8 f2E8;
    u8 pad2E9[0xF];
    Pair_8041E780 f2F8[5];
    s16 f320;
    u8 pad322[0x20E];
    s32 f530;
    s32 f534;
    s16 ack_delay;
    u8 pad53A[2];
    s32 f53C;
    u32 f540;
};
struct G_8041E780 {
    Tcb_8041E780 *tcbs;
    s16 count;
    s16 freed;
    s32 f8;
    s32 fC;
    u16 port;
    u16 port_min;
    u16 port_max;
    u8 pad16[0x10];
    s16 f26;
    u8 pad28[0x28];
    u8 f50;
    u8 pad51[0x51];
    u8 fA2;
};

#pragma push
#pragma pool_data off
s16 TLobby__sub_8041E5E4(s16 h, u8 *addr, u16 port) {
    s16 r;
    s16 i;
    Tcb_8041E780 *e;
    Tcb_8041E780 *tcb;
    s16 is_addr_unspecified__6TLobbyFPv(u8 *arg0);

    if (h < 0 || h >= tcp_protocol_state.n) {
        r = -4;
    } else if (tcp_protocol_state.p[h].f4 != 1) {
        r = -4;
    } else {
        r = 0;
    }
    if (r < 0) {
        return -4;
    }
    tcb = (Tcb_8041E780 *)tcp_protocol_state.p;
    tcb += h;
    if (tcb->lport != 0) {
        return -3;
    }
    if (NetValidateLocalAddress((NetworkAddress *)addr) < 0) {
        return -6;
    }
    if (port == 0) {
        tcb->lport = TLobby__sub_8041EA14();
    } else {
        e = (Tcb_8041E780 *)tcp_protocol_state.p;
        for (i = 0; i < tcp_protocol_state.n; e++, i++) {
            if (e->state == 0 || e == tcb || e->lport != port) {
                continue;
            }
            if (is_addr_unspecified__6TLobbyFPv(addr) != 0 || is_addr_unspecified__6TLobbyFPv(e->laddr) != 0 ||
                ((TLobby *)e->laddr)->compare_sockaddr(addr) == 0) {
                if (e->f6 == 10 && (e->flags & 0x80)) {
                    TLobby__sub_8041B5C0(e);
                } else {
                    return -3;
                }
            }
        }
        tcb->lport = port;
    }
    NetMemcpy(tcb->laddr, addr, sizeof(tcb->laddr));
    return 0;
}
#pragma pop

void TLobby__sub_8041E8A8(s16 idx);

s16 TLobby__sub_8041E780(void) {
    G_8041E780 *g = (G_8041E780 *)&tcp_protocol_state;
    s16 vidx = 0;
    Tcb_8041E780 *victim = NULL;
    s16 idx;
    s16 n;
    Tcb_8041E780 *tcbs;
    Tcb_8041E780 *t;
    s16 i;

    idx = g->freed;
    n = g->count;
    tcbs = g->tcbs;
    for (i = 0; i < n; i++) {
        idx++;
        if (n <= idx) {
            idx = 0;
        }
        t = tcbs;
        t += idx;
        if (t->state == 0) {
            NetMemset(t, 0, sizeof(Tcb_8041E780));
            TLobby__sub_8041E8A8(idx);
            return idx;
        }
        if (t->f6 == 10 && (t->flags & 0x80)) {
            if (victim != NULL) {
                if (t->timers[3] < victim->timers[3]) {
                    victim = t;
                    vidx = idx;
                }
            } else {
                victim = t;
                vidx = idx;
            }
        }
    }
    if (victim != NULL) {
        TLobby__sub_8041B5C0(victim);
        NetMemset(victim, 0, sizeof(Tcb_8041E780));
        TLobby__sub_8041E8A8(vidx);
        return vidx;
    }
    return -0x103;
}

#pragma push
#pragma pool_data off
void TLobby__sub_8041E8A8(s16 idx) {
    Tcb_8041E780 *t;
    Pair_8041E780 *p;
    s16 i;

    t = ((G_8041E780 *)&tcp_protocol_state)->tcbs;
    t += idx;
    t->tag[0] = 'T';
    t->tag[1] = 'C';
    t->tag[2] = 'B';
    t->index = idx;
    t->state = 1;
    t->f6 = 0;
    t->maxseg = 0x7FFF;
    t->f266 = 0x218;
    t->flags = 0;
    t->fA = 0;
    t->f24C = 0;
    t->f24E = 24;
    t->f254 = 12;
    if (t->f254 < 2) {
        t->f254 = 2;
    } else if (t->f254 > 128) {
        t->f254 = 128;
    }
    t->f240 = 0xFFFF;
    t->listener = -1;
    ((TLobby *)t)->clear_position();
    NetMemset(t->f2D6, 0, sizeof(t->f2D6));
    NetMemset(t->f2DC, 0, sizeof(t->f2DC));
    t->f2E8 = ((G_8041E780 *)&tcp_protocol_state)->f50;
    p = t->f2F8;
    for (i = 0; i < 5; i++, p++) {
        p->b = 0;
        p->a = 0;
    }
    t->f320 = -1;
    t->f530 = ((G_8041E780 *)&tcp_protocol_state)->f8;
    t->f534 = ((G_8041E780 *)&tcp_protocol_state)->fC;
    t->f2D0 = 0;
    t->f53C = ((G_8041E780 *)&tcp_protocol_state)->f26;
    t->ack_delay = 0;
    t->f540 = ((G_8041E780 *)&tcp_protocol_state)->fA2;
}
#pragma pop

#pragma push
#pragma dont_inline off
#pragma inline_depth(4)
#pragma pool_data off
inline s16 port_in_use_8041EA14(u16 port) {
    G_8041E780 *g = (G_8041E780 *)&tcp_protocol_state;
    s16 n;
    s16 i;
    Tcb_8041E780 *t;

    t = g->tcbs;
    n = g->count;
    for (i = 0; i < n; i++, t++) {
        if (t->state == 1 && port == t->lport) {
            return 1;
        }
    }
    return 0;
}

u16 TLobby__sub_8041EA14(void) {
    G_8041E780 *g = (G_8041E780 *)&tcp_protocol_state;
    u16 *port = &g->port;
    s32 tick;
    u16 p;

    p = g->port;
    if (p == 0) {
        NetStoreTick(&tick);
        *port = g->port_min;
        *port |= tick & 0x3FF;
    } else if (p < g->port_max) {
        *port = p + 1;
    } else {
        *port = g->port_min;
    }
    while (port_in_use_8041EA14(p = *port) != 0) {
        if (p < ((G_8041E780 *)&tcp_protocol_state)->port_max) {
            (*port)++;
        } else {
            *port = ((G_8041E780 *)&tcp_protocol_state)->port_min;
        }
    }
    return p;
}
#pragma pop

s16 TLobby::validate_tcp_handle(s16 i) {
    if (i < 0 || i >= tcp_protocol_state.n) { return -4; }
    if (tcp_protocol_state.p[i].f4 != 1) { return -4; }
    return 0;
}

s32 TLobby__sub_8041EB74(u8 *arg0) {
    struct Fields_arg0 { u8 pad_0[204]; u8 field_CC; };
    if ((u8) ((Fields_arg0*)arg0)->field_CC == 0) {
        return -1;
    }
    TLobby__sub_8041579C((void *) (arg0 + 0xD0));
    ((Fields_arg0*)arg0)->field_CC = 0U;
    return 0;
}

s32 TLobby::close_if_open() {
    u8 *arg0 = (u8 *)this;
    if ((u8) *(u8 *)&this->m_down == 0) {
        return -1;
    }
    TLobby__sub_8041579C((void *) (arg0 + 0x18));
    *(u8 *)&this->m_down = 0U;
    return 0;
}

s32 TLobby__sub_8041EC14(u8 *arg0) {
    s32 spC[3];

    if ((u8) *(u8 *)((s8 *)arg0 + 0xCC) == 0) {
        if (TLobby__sub_80415954((NetBufferRef *) (&spC[0]), (int) (*(s32 *)((s8 *)arg0 + 0x534)), 1) < 0) {
            return -0x102;
        }
        ((TLobby *)(arg0 + 0xD0))->init_msg(spC[0]);
        ((TLobby *)(arg0 + 0xC8))->set_value_and_enable(spC[0]);
        goto block_4;
    }
block_4:
    *(s32 *)((s8 *)arg0 + 0xD8) = 0;
    *(s32 *)((s8 *)arg0 + 0xDC) = 0;
    *(s32 *)((s8 *)arg0 + 0xE0) = 0;
    *(s32 *)((s8 *)arg0 + 0xF4) = 0;
    *(s16 *)((s8 *)arg0 + 0xF8) = -1;
    *(s16 *)((s8 *)arg0 + 0xFA) = -1;
    return 0;
}

s32 TLobby__sub_8041ECA4(u8 *arg0) {
  unsigned char new_var;
  s32 spC;
  if (((u8) (*((u8 *) (((s8 *) arg0) + 0x14)))) == 0)
  {
    if (TLobby__sub_80415954((NetBufferRef *) (&spC), (int) (*((s32 *) (((s8 *) arg0) + 0x530))), 1) < 0)
    {
      return -0x102;
    }
    ((TLobby *)(((u8 *) arg0) + 0x18))->init_msg((s32)((int) spC));
    ((TLobby *)(((u8 *) arg0) + 0x10))->set_value_and_enable((s32)((int) spC));
    goto block_4;
  }
  block_4:
  *((s32 *) (((s8 *) arg0) + 0x20)) = 0;
  new_var = 0x24;
  *((s32 *) (((s8 *) arg0) + new_var)) = 0;
  *((s32 *) (((s8 *) arg0) + 0x28)) = 0;
  return 0;
}

s32 TLobby::get_field_534() {
    u8 *arg0 = (u8 *)this;
    return *(s32 *)((s8 *)arg0 + 0x534);
}

s32 TLobby::get_field_d8() {
    u8 *arg0 = (u8 *)this;
    return *(s32 *)((s8 *)arg0 + 0xD8);
}

s32 TLobby::get_score() {
    u8 *arg0 = (u8 *)this;
    if (((u8) *(u8 *)((s8 *)arg0 + 0x204) >> 7U) & 1) {
        return *(s32 *)((s8 *)arg0 + 0x34);
    }
    return *(s32 *)((s8 *)arg0 + 0x20) + *(s32 *)((s8 *)arg0 + 0x34);
}

s32 TLobby::get_queue_diff() {
    u8 *arg0 = (u8 *)this;
    return *(s32 *)((s8 *)arg0 + 0x534) - *(s32 *)((s8 *)arg0 + 0xD8);
}

s32 get_adjusted_slot_count__6TLobbyFPv(u8 *arg0) {
    if (((u8) *(u8 *)((s8 *)arg0 + 0x204) >> 7U) & 1) {
        return *(s32 *)((s8 *)arg0 + 0x530);
    }
    return *(s32 *)((s8 *)arg0 + 0x530) - *(s32 *)((s8 *)arg0 + 0x20);
}

}
