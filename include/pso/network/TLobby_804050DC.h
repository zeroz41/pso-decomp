#ifndef PSO_NETWORK_TLOBBY_804050DC_H
#define PSO_NETWORK_TLOBBY_804050DC_H

#include "types.h"
#include "pso/network/IPv6.h"
#include "pso/network/IPv6Send.h"
#include "pso/network/NetDns.h"
#include "pso/network/NetArp.h"
#include "pso/network/NetIpv4.h"
#include "pso/network/NetEthernet.h"

/* TLobby_804050DC.c: connection records, the DNS resolver tables and socket start-up. */
typedef struct RecoveredGlobal_804050DC_lbl_805C18A0 RecoveredGlobal_804050DC_lbl_805C18A0;
typedef struct RecoveredGlobal_804050EC_lbl_805C18A0 RecoveredGlobal_804050EC_lbl_805C18A0;
typedef struct RecoveredGlobal_80405114_lbl_805C18A0 RecoveredGlobal_80405114_lbl_805C18A0;
typedef struct E_8040DDB0 E_8040DDB0;
typedef struct RecoveredGlobal_8040DD68_lbl_805C1B38 RecoveredGlobal_8040DD68_lbl_805C1B38;
typedef struct N_80405298 N_80405298;
typedef struct In_8040D95C In_8040D95C;
typedef struct Out_8040D95C Out_8040D95C;
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
struct N_80405298 { N_80405298 *next; s32 f4; u8 pad8[0x18 - 8]; u8 b18; };
struct In_8040D95C { s32 type; s32 f4; };
struct Out_8040D95C { s32 type; u32 f4; };
#ifdef __cplusplus
extern "C" {
#endif
s16 run_connect_step(void);
void flush_flags_step(void);
s16 init_net_tables(void);
s32 clear_all_used_records(void);
s32 close_connection_by_index(s16 i);
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
extern NetPacketPool lobby_udp_socket_table;
#ifdef __cplusplus
}
#endif

#endif
