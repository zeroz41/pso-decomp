#ifndef PSO_NETWORK_TLOBBY_804050DC_H
#define PSO_NETWORK_TLOBBY_804050DC_H

#include "types.h"
#include "pso/network/IPv6.h"
#include "pso/network/IPv6Send.h"

/* TLobby_804050DC.c: connection records, the DNS resolver tables and socket start-up. */
typedef struct Buf_80408F2C Buf_80408F2C;
typedef struct Tbl_80408F2C Tbl_80408F2C;
typedef struct RecoveredGlobal_804050DC_lbl_805C18A0 RecoveredGlobal_804050DC_lbl_805C18A0;
typedef struct RecoveredGlobal_804050EC_lbl_805C18A0 RecoveredGlobal_804050EC_lbl_805C18A0;
typedef struct RecoveredGlobal_80405114_lbl_805C18A0 RecoveredGlobal_80405114_lbl_805C18A0;
typedef struct E_8040DDB0 E_8040DDB0;
typedef struct RecoveredGlobal_8040DD68_lbl_805C1B38 RecoveredGlobal_8040DD68_lbl_805C1B38;
typedef struct E_8040FF58 E_8040FF58;
typedef struct RecoveredGlobal_8040FF0C_lbl_805C1B78 RecoveredGlobal_8040FF0C_lbl_805C1B78;
typedef struct RecoveredGlobal_80409A3C_lbl_805C1C50 RecoveredGlobal_80409A3C_lbl_805C1C50;
typedef struct Ent_80408718 Ent_80408718;
typedef struct Tbl_80408718 Tbl_80408718;
typedef struct N_80405298 N_80405298;
typedef struct O_80406B6C O_80406B6C;
typedef struct Ent_804086B4 Ent_804086B4;
typedef struct Rec_8040B33C Rec_8040B33C;
typedef struct A_8040A45C A_8040A45C;
typedef struct C_8040A45C C_8040A45C;
typedef struct D_8040A45C D_8040A45C;
typedef struct E_8040A45C E_8040A45C;
typedef struct F_8040A45C F_8040A45C;
typedef struct G_8040A45C G_8040A45C;
typedef struct In_8040D95C In_8040D95C;
typedef struct Out_8040D95C Out_8040D95C;
struct Buf_80408F2C {
    s16 h0;
    s16 h2;
    s16 h4;
    s16 h6;
    s16 h8;
    u8 data[0x5EE];
};
struct Tbl_80408F2C {
    u8 pad0[4];
    s16 count;
    s16 nbufs;
    u8 pad8[0xC];
    Buf_80408F2C *bufs;
};
struct RecoveredGlobal_804050DC_lbl_805C18A0 {
    s32 value;
    u8 remaining[0xC];
};
struct RecoveredGlobal_804050EC_lbl_805C18A0 {
    s32 value;
    u8 remaining[0xC];
};
struct RecoveredGlobal_80405114_lbl_805C18A0 {
    s32 value;
    u8 remaining[0xC];
};
struct E_8040DDB0 { u8 c0; u8 c1; u8 c2; u8 c3; s16 f4; u8 pad6[0x16]; };
struct RecoveredGlobal_8040DD68_lbl_805C1B38 {
    s16 value;
    u8 pad2[2];
    E_8040DDB0 *ents;
    s16 f8;
    u8 padA[0x1E];
};
struct E_8040FF58 { u8 c0; u8 c1; u8 c2; u8 c3; s16 f4; u8 pad6[0x2E]; };
struct RecoveredGlobal_8040FF0C_lbl_805C1B78 {
    s16 value;
    u8 pad2[2];
    E_8040FF58 *ents;
    s32 f8;
    u8 padC[0x34];
};
struct RecoveredGlobal_80409A3C_lbl_805C1C50 {
    s32 value;
    u8 remaining[0xF4];
};
struct Ent_80408718 { s16 f0; u8 pad[0x16]; };
struct Tbl_80408718 { s16 count; s16 h2; s16 h4; s16 h6; s16 h8; u8 pad[4]; Ent_80408718 *list; u8 tail[0x14]; };
struct N_80405298 { N_80405298 *next; s32 f4; u8 pad8[0x18 - 8]; u8 b18; };
struct O_80406B6C { u32 w0; u8 b4; };
struct Ent_804086B4 { s16 f0; s16 f2; u8 pad[0x14]; };
struct Rec_8040B33C { u32 f0; u8 pad[0x10]; };
struct A_8040A45C { s16 f0; u8 pad2[2]; s32 f4; };
struct C_8040A45C { s16 f0; u8 pad2[0x1E]; s32 f20; u8 pad24[4]; };
struct D_8040A45C { s16 f0; u8 pad2[0x102]; u8 f104; u8 pad105[0xFF]; s16 f204; u8 pad206[2]; s32 f208; };
struct E_8040A45C { s16 f0; u8 pad2[0x16]; s32 f18; u8 f1C; u8 pad1D[0xFF]; };
struct F_8040A45C {
    s16 f0;
    s16 f2;
    s16 f4;
    s16 f6;
    u8 pad8[4];
    s32 fC;
    s16 f10;
    s16 f12;
    u8 pad14[4];
    s32 f18;
    s32 f1C;
    u8 pad20[8];
    s32 f28;
    u8 pad2C[8];
    s32 f34;
    u8 pad38[4];
};
struct G_8040A45C {
    s16 h0;
    u8 pad2[0xE];
    s16 nb;
    u8 pad12[2];
    Rec_8040B33C *b;
    u8 pad18[2];
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
struct In_8040D95C { s32 type; s32 f4; };
struct Out_8040D95C { s32 type; u32 f4; };
typedef s16 (*Init_8040881C)(s16);
typedef s32 (*SendFn_80408C24)(s16, u8 *, s16);
typedef void (*CbA_8040C540)(s16, s32, s16, s32, s16);
typedef void (*CbB_8040C540)(s16, u32, s16);
#ifdef __cplusplus
extern "C" {
#endif
s16 run_connect_step(void);
void flush_flags_step(void);
s16 init_net_tables(void);
s32 clear_all_used_records(void);
s32 close_connection_by_index(s16 i);
extern RecoveredGlobal_8040FF0C_lbl_805C1B78 ipv6_protocol_state;
extern u32 lbl_805C1AD8[6];
extern G_8040A45C dns_resolver_state;
u8 *alloc_free_entry(void);
s32 call_entry_callback(s16 i, s32 arg);
s32 call_handler_by_index(s16 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
s32 clear_table_entry_locked(s16 arg0);
void init_msg(void *self, s32 arg1);
void init_net_block_18A0(void);
void init_packet_header(void *self, s32 arg1);
s32 invoke_socket_callback(s16 i, s32 arg);
s32 is_entry_flag10_set(s16 i);
s32 is_slot_flag_0x20_set(s16 i);
s32 is_slot_flag_0x40_set(s16 i);
void process_expired_timers(void);
s32 run_net_init_step(void);
void set_value_and_enable(void *self, s32 arg1);
s32 shutdown_network_handle(void);
s32 is_socket_flag_set(s16 i);
s32 TLobby__sub_8040A044(s16 idx, u32 a, s32 b, u32 *c);
void TLobby__sub_804050DC(s16 arg0);
s32 TLobby__sub_804062A0(s16 arg0);
s16 reset_network_timer_list(void);
s32 TLobby__sub_8040799C(s16 idx, void *name, void *arg2);
s32 TLobby__sub_80409AA8(void);
s32 TLobby__sub_8040FDA0(u32 arg0, s16 arg1);
void TLobby__sub_80405328(u8 *arg0);
s16 TLobby__sub_8040FCEC(u32 ip);
s32 TLobby__sub_8040DD68(void);
s32 TLobby__sub_8040ED28(void);
s32 NetIPv6Shutdown(void);
s16 TLobby__sub_80409A3C(u8 *arg0, s16 arg1);
s32 TLobby__sub_80405304(void *arg0);
s16 TLobby__sub_8040DC8C(u8 *arg0, u8 *arg1);
void TLobby__sub_80406FD8(void *a, void *b, s32 v);
s16 TLobby__sub_80410BA8(void *self, void *a, s16 c, void *d);
u16 TLobby__sub_80411040(const struct IPv6Address *src, const struct IPv6Address *dst, u8 next_header, const struct NetPacket *pkt, s16 flag);
void TLobby__sub_80405298(N_80405298 *o, s32 v);
void TLobby__sub_80409818(s32 msg, s16 len, s16 idx, s16 arg3, u16 type);
s32 TLobby__sub_80408388(s16 id);
s16 TLobby__sub_804098B4(void *pkt);
s32 TLobby__sub_80409908(void *self, void *arr_);
u8 *TLobby__sub_80406F0C(void *self);
s32 TLobby__sub_80406328(s32 self, s16 type);
#ifdef __cplusplus
}
#endif

#endif
