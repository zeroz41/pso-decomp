#include "pso/network/UdpRuntime.h"
#include "pso/network/SocketEvents.h"
#include "pso/network/NetworkDispatch.h"
#include "pso/network/NetworkRuntime.h"
#include "pso/network/TLobby_804050DC.h"
#include "pso/network/TLobby_803FC178.h"
#include "pso/network/NetworkPacketPool.h"
#include "pso/network/netcfg.h"
#include "pso/network/BufferRef.h"
#include "pso/network/IPv6.h"

#include "types.h"
/* The object header the stack's records share (laid out like TObject's fields). */
typedef struct TObjectFields {
    const char *m_name;
    u16 m_flags;
    u16 m_id;
    void *m_prev;
    void *m_next;
    void *m_up;
    void *m_down;
} TObjectFields;
typedef struct Ent_804099B4 Ent_804099B4;
typedef struct Tbl_804099B4 Tbl_804099B4;
typedef struct Ent_80409B48 Ent_80409B48;
typedef struct Tbl_80409B48 Tbl_80409B48;
typedef struct Ent_80409BD4 Ent_80409BD4;
typedef struct Tbl_80409BD4 Tbl_80409BD4;
typedef struct Pkt_804081C0 Pkt_804081C0;
typedef struct Pool_804081C0 Pool_804081C0;
typedef struct Out_804081C0 Out_804081C0;
typedef struct T_804179A4 T_804179A4;
typedef struct Timer_804051CC Timer_804051CC;
typedef struct Lobby_804062A0 Lobby_804062A0;
typedef struct Ent_80407418 Ent_80407418;
typedef struct Tbl_80407418 Tbl_80407418;
typedef struct Node_804082AC Node_804082AC;
typedef struct Ent_804082AC Ent_804082AC;
typedef struct Key_804082AC Key_804082AC;
typedef struct Node_80408388 Node_80408388;
typedef struct Ent_80408388 Ent_80408388;
typedef struct Tbl_80408388 Tbl_80408388;
typedef struct Sub_80408428 Sub_80408428;
typedef struct Ent_80408428 Ent_80408428;
typedef struct Tbl_80408428 Tbl_80408428;
typedef struct Pkt_80408428 Pkt_80408428;
typedef struct Ent_80408E98 Ent_80408E98;
typedef struct Tbl_80408E98 Tbl_80408E98;
typedef struct Buf_80408F2C Buf_80408F2C;
typedef struct Tbl_80408F2C Tbl_80408F2C;
typedef struct Sock_80409130 Sock_80409130;
typedef struct Ent_8040920C Ent_8040920C;
typedef struct Rec_8040920C Rec_8040920C;
typedef struct Tbl_8040920C Tbl_8040920C;
typedef struct Ent_80409C5C Ent_80409C5C;
typedef struct Tbl_80409C5C Tbl_80409C5C;
typedef struct Ent_80409CE0 Ent_80409CE0;
typedef struct Tbl_80409CE0 Tbl_80409CE0;
typedef struct Ent_80409D7C Ent_80409D7C;
typedef struct Tbl_80409D7C Tbl_80409D7C;
typedef struct Ent_80409E18 Ent_80409E18;
typedef struct Tbl_80409E18 Tbl_80409E18;
typedef struct Ent_80409EB0 Ent_80409EB0;
typedef struct Tbl_80409EB0 Tbl_80409EB0;
typedef struct Ent_8040A3C0 Ent_8040A3C0;
typedef struct Mgr_8040A3C0 Mgr_8040A3C0;
typedef struct Ent_80409FC4 Ent_80409FC4;
typedef struct Tbl_80409FC4 Tbl_80409FC4;
typedef struct Ent_8040A630 Ent_8040A630;
typedef struct G_8040A630 G_8040A630;
typedef struct Rec_8040AD64 Rec_8040AD64;
typedef struct Mgr_8040AD64 Mgr_8040AD64;
typedef struct Conn_8040AF48 Conn_8040AF48;
typedef struct Mgr_8040AF48 Mgr_8040AF48;
typedef struct Ent_8040B654 Ent_8040B654;
typedef struct Mgr_8040B654 Mgr_8040B654;
typedef struct Ent_80414504 Ent_80414504;
typedef struct Mgr_80414504 Mgr_80414504;
typedef struct Ent_80418670 Ent_80418670;
typedef struct Sub_804162A4 Sub_804162A4;
typedef struct Ent_804162A4 Ent_804162A4;
typedef struct Glob_804162A4 Glob_804162A4;
typedef struct Arg_804162A4 Arg_804162A4;
typedef struct Ent_80416678 Ent_80416678;
typedef struct Hdr_804177A0 Hdr_804177A0;
typedef struct Arg_80417D1C Arg_80417D1C;
typedef struct Arg_80417E60 Arg_80417E60;
typedef struct G_80418670 G_80418670;
typedef struct PppRx PppRx;
typedef struct DnsHdr_804050DC DnsHdr_804050DC;
typedef struct DnsRec_804050DC DnsRec_804050DC;
typedef struct DnsBase_804050DC DnsBase_804050DC;
typedef struct Self_803FD85C Self_803FD85C;
typedef struct Tbl_803FD85C Tbl_803FD85C;
typedef struct Info_8040098C Info_8040098C;
typedef struct St_8040098C St_8040098C;
typedef struct Self_8040098C Self_8040098C;
typedef struct RecoveredGlobal_8041552C_lbl_805C1BE0 RecoveredGlobal_8041552C_lbl_805C1BE0;
typedef struct RecoveredGlobal_804050DC_lbl_805C18A0 RecoveredGlobal_804050DC_lbl_805C18A0;
typedef struct RecoveredGlobal_804050EC_lbl_805C18A0 RecoveredGlobal_804050EC_lbl_805C18A0;
typedef struct RecoveredGlobal_80405114_lbl_805C18A0 RecoveredGlobal_80405114_lbl_805C18A0;
typedef struct RecoveredGlobal_8040EF00_lbl_805C1B60 RecoveredGlobal_8040EF00_lbl_805C1B60;
typedef struct RecoveredGlobal_8040FE40_lbl_805C1B60 RecoveredGlobal_8040FE40_lbl_805C1B60;
typedef struct RecoveredGlobal_8040FE9C_lbl_805C1B60 RecoveredGlobal_8040FE9C_lbl_805C1B60;
typedef struct RecoveredGlobal_8041123C_lbl_805C1BB8 RecoveredGlobal_8041123C_lbl_805C1BB8;
typedef struct RecoveredGlobal_804112B8_lbl_805C1BB8 RecoveredGlobal_804112B8_lbl_805C1BB8;
typedef struct RecoveredGlobal_80411ECC_lbl_805C1BB8 RecoveredGlobal_80411ECC_lbl_805C1BB8;
typedef struct RecoveredGlobal_8041471C_lbl_805C1BB8 RecoveredGlobal_8041471C_lbl_805C1BB8;
typedef struct Stack_80416008 Stack_80416008;
typedef struct RtEntry_8040F8A4 RtEntry_8040F8A4;
typedef struct RtTbl_8040F8A4 RtTbl_8040F8A4;
typedef struct E_8040DDB0 E_8040DDB0;
typedef struct RecoveredGlobal_8040DD68_lbl_805C1B38 RecoveredGlobal_8040DD68_lbl_805C1B38;
typedef struct RecoveredGlobal_8040ED28_lbl_805C1B60 RecoveredGlobal_8040ED28_lbl_805C1B60;
typedef struct RecoveredGlobal_8040ED70_lbl_805C1B60 RecoveredGlobal_8040ED70_lbl_805C1B60;
typedef struct E_8040FF58 E_8040FF58;
typedef struct RecoveredGlobal_8040FF0C_lbl_805C1B78 RecoveredGlobal_8040FF0C_lbl_805C1B78;
typedef struct RecoveredGlobal_80415650_lbl_805C1BF8 RecoveredGlobal_80415650_lbl_805C1BF8;
typedef struct RecoveredGlobal_80409A3C_lbl_805C1C50 RecoveredGlobal_80409A3C_lbl_805C1C50;
typedef struct Inner_80401CAC Inner_80401CAC;
typedef struct Outer_80401CAC Outer_80401CAC;
typedef struct Ent_80408718 Ent_80408718;
typedef struct Tbl_80408718 Tbl_80408718;
typedef struct Obj_80405304 Obj_80405304;
typedef struct Cfg_803F87E0 Cfg_803F87E0;
typedef struct Obj_803F87E0 Obj_803F87E0;
typedef struct Desc_803F8AD8 Desc_803F8AD8;
typedef struct Ent_804099B4 Ent_804099B4;
typedef struct Tbl_804099B4 Tbl_804099B4;
typedef struct Ent_80409B48 Ent_80409B48;
typedef struct Tbl_80409B48 Tbl_80409B48;
typedef struct Ent_80409BD4 Ent_80409BD4;
typedef struct Tbl_80409BD4 Tbl_80409BD4;
typedef struct Hdr_8040B6E4 Hdr_8040B6E4;
typedef struct Pkt_8040B6E4 Pkt_8040B6E4;
typedef struct Q_8040B6E4 Q_8040B6E4;
typedef struct QT_8040B6E4 QT_8040B6E4;
typedef struct Hdr_8040B790 Hdr_8040B790;
typedef struct Pkt_8040B790 Pkt_8040B790;
typedef struct Q_8040B790 Q_8040B790;
typedef struct QT_8040B790 QT_8040B790;
typedef struct Strm_80405A74 Strm_80405A74;
typedef struct G_8041509C G_8041509C;
typedef struct Tbl_80409AD8 Tbl_80409AD8;
typedef struct Pkt_804081C0 Pkt_804081C0;
typedef struct Pool_804081C0 Pool_804081C0;
typedef struct Out_804081C0 Out_804081C0;
typedef struct Pkt_80407640 Pkt_80407640;
typedef struct Hit_80407640 Hit_80407640;
typedef struct Peer_80407640 Peer_80407640;
typedef struct Tbl_80407640 Tbl_80407640;
typedef struct Ent_804082AC Ent_804082AC;
typedef struct Key_804082AC Key_804082AC;
typedef struct Ent_8040A13C Ent_8040A13C;
typedef struct G_8040A13C G_8040A13C;
typedef struct Ent_8040A19C Ent_8040A19C;
typedef struct G_8040A19C G_8040A19C;
typedef struct Ent_80409F44 Ent_80409F44;
typedef struct Tbl_80409F44 Tbl_80409F44;
typedef struct T_804179A4 T_804179A4;
typedef struct Seg_804179A4 Seg_804179A4;
typedef struct Pkt_804179A4 Pkt_804179A4;
typedef struct Na_804179A4 Na_804179A4;
typedef struct Cur_804179A4 Cur_804179A4;
typedef struct Sock_804179A4 Sock_804179A4;
typedef struct Q_804179A4 Q_804179A4;
typedef struct E_804179A4 E_804179A4;
typedef struct Req_8040F00C Req_8040F00C;
typedef struct NbPoolView NbPoolView;
typedef struct N_80405298 N_80405298;
typedef struct Self_803FDA68 Self_803FDA68;
typedef struct Tbl_803FDA68 Tbl_803FDA68;
typedef struct V_803FE600 V_803FE600;
typedef struct O_803FE600 O_803FE600;
typedef struct Ent_804089A8 Ent_804089A8;
typedef struct Slot_804089A8 Slot_804089A8;
typedef struct Tbl_804089A8 Tbl_804089A8;
typedef struct G_80405150 G_80405150;
typedef struct Timer_804051CC Timer_804051CC;
typedef struct Lobby_804062A0 Lobby_804062A0;
typedef struct Ent_80406B14 Ent_80406B14;
typedef struct Tbl_80406B14 Tbl_80406B14;
typedef struct O_80406B6C O_80406B6C;
typedef struct Ent_804072C4 Ent_804072C4;
typedef struct Tbl_804072C4 Tbl_804072C4;
typedef struct Ent_80407310 Ent_80407310;
typedef struct Tbl_80407310 Tbl_80407310;
typedef struct Ent_80407418 Ent_80407418;
typedef struct Tbl_80407418 Tbl_80407418;
typedef struct Ent_80408428 Ent_80408428;
typedef struct Conn_8040799C Conn_8040799C;
typedef struct Peer_8040799C Peer_8040799C;
typedef struct Ent_8040799C Ent_8040799C;
typedef struct Tbl_8040799C Tbl_8040799C;
typedef struct Out_8040799C Out_8040799C;
typedef struct Node_804082AC Node_804082AC;
typedef struct Node_80408388 Node_80408388;
typedef struct Ent_80408388 Ent_80408388;
typedef struct Tbl_80408388 Tbl_80408388;
typedef struct Sub_80408428 Sub_80408428;
typedef struct Tbl_80408428 Tbl_80408428;
typedef struct Pkt_80408428 Pkt_80408428;
typedef struct Ent_804086B4 Ent_804086B4;
typedef struct Tbl_804086B4 Tbl_804086B4;
typedef struct Desc_8040881C Desc_8040881C;
typedef struct Ent_8040881C Ent_8040881C;
typedef struct G_8040881C G_8040881C;
typedef struct Fn_80408FD8 Fn_80408FD8;
typedef struct Ent_80408FD8 Ent_80408FD8;
typedef struct Tbl_80408FD8 Tbl_80408FD8;
typedef struct Tbl_80408F2C Tbl_80408F2C;
typedef struct If_80408C24 If_80408C24;
typedef struct Conn_80408C24 Conn_80408C24;
typedef struct Ent_80408C24 Ent_80408C24;
typedef struct Glob_80408C24 Glob_80408C24;
typedef struct Hdr_80408C24 Hdr_80408C24;
typedef struct Ent_80408E98 Ent_80408E98;
typedef struct Tbl_80408E98 Tbl_80408E98;
typedef struct Buf_80408F2C Buf_80408F2C;
typedef struct Ent_804094B8 Ent_804094B8;
typedef struct Sock_80409130 Sock_80409130;
typedef struct Ent_8040920C Ent_8040920C;
typedef struct Rec_8040920C Rec_8040920C;
typedef struct Tbl_8040920C Tbl_8040920C;
typedef struct Rec_8040B33C Rec_8040B33C;
typedef struct A_8040B33C A_8040B33C;
typedef struct A_8040A45C A_8040A45C;
typedef struct C_8040A45C C_8040A45C;
typedef struct D_8040A45C D_8040A45C;
typedef struct E_8040A45C E_8040A45C;
typedef struct F_8040A45C F_8040A45C;
typedef struct G_8040A45C G_8040A45C;
typedef struct Ent_80409C5C Ent_80409C5C;
typedef struct Tbl_80409C5C Tbl_80409C5C;
typedef struct Ent_80409CE0 Ent_80409CE0;
typedef struct Tbl_80409CE0 Tbl_80409CE0;
typedef struct Ent_80409D7C Ent_80409D7C;
typedef struct Tbl_80409D7C Tbl_80409D7C;
typedef struct Ent_80409E18 Ent_80409E18;
typedef struct Tbl_80409E18 Tbl_80409E18;
typedef struct Ent_80409EB0 Ent_80409EB0;
typedef struct Tbl_80409EB0 Tbl_80409EB0;
typedef struct Ent_8040A3C0 Ent_8040A3C0;
typedef struct Mgr_8040A3C0 Mgr_8040A3C0;
typedef struct Ent_80409FC4 Ent_80409FC4;
typedef struct Tbl_80409FC4 Tbl_80409FC4;
typedef struct Ent_8040A630 Ent_8040A630;
typedef struct G_8040A630 G_8040A630;
typedef struct Ent_8040A1FC Ent_8040A1FC;
typedef struct G_8040A1FC G_8040A1FC;
typedef struct Ent_8040A25C Ent_8040A25C;
typedef struct G_8040A25C G_8040A25C;
typedef struct Rec_8040AD64 Rec_8040AD64;
typedef struct Mgr_8040AD64 Mgr_8040AD64;
typedef struct Conn_8040AF48 Conn_8040AF48;
typedef struct Mgr_8040AF48 Mgr_8040AF48;
typedef struct Node_8040B3B4 Node_8040B3B4;
typedef struct Ent_8040B3B4 Ent_8040B3B4;
typedef struct Base_8040B3B4 Base_8040B3B4;
typedef struct Ent_8040B654 Ent_8040B654;
typedef struct Mgr_8040B654 Mgr_8040B654;
typedef struct Conn_8040C540 Conn_8040C540;
typedef struct Rec_8040BA38 Rec_8040BA38;
typedef struct Hdr_8040BA38 Hdr_8040BA38;
typedef struct O_8040C4B0 O_8040C4B0;
typedef struct N_8040C4B0 N_8040C4B0;
typedef struct G_8040C4B0 G_8040C4B0;
typedef struct O_8040C00C O_8040C00C;
typedef struct E_8040C00C E_8040C00C;
typedef struct G_8040C00C G_8040C00C;
typedef struct SubA_8040C540 SubA_8040C540;
typedef struct SubB_8040C540 SubB_8040C540;
typedef struct Ent_8040D95C Ent_8040D95C;
typedef struct In_8040D95C In_8040D95C;
typedef struct Out_8040D95C Out_8040D95C;
typedef struct PH_8040EC38 PH_8040EC38;
typedef struct P_8040EC38 P_8040EC38;
typedef struct A_8040F1A0 A_8040F1A0;
typedef struct Nd_8040F1A0 Nd_8040F1A0;
typedef struct B_8040F1A0 B_8040F1A0;
typedef struct G_8040F1A0 G_8040F1A0;
typedef struct A_RT A_RT;
typedef struct E_RT E_RT;
typedef struct G_RT G_RT;
typedef struct Ent_8040FDA0 Ent_8040FDA0;
typedef struct G_8040FDA0 G_8040FDA0;
typedef struct G_8041118C G_8041118C;
typedef struct Ent_80411BE8 Ent_80411BE8;
typedef struct G_80411BE8 G_80411BE8;
typedef struct Ent_80412210 Ent_80412210;
typedef struct Grp_80412210 Grp_80412210;
typedef struct If_80412210 If_80412210;
typedef struct G_80412210 G_80412210;
typedef struct Ent_8041347C Ent_8041347C;
typedef struct G_8041347C G_8041347C;
typedef struct RecoveredFields_804143BC_arg0 RecoveredFields_804143BC_arg0;
typedef struct Ent_80414504 Ent_80414504;
typedef struct Mgr_80414504 Mgr_80414504;
typedef struct E_80415558 E_80415558;
typedef struct G_80415558 G_80415558;
typedef struct E_8041559C E_8041559C;
typedef struct G_8041559C G_8041559C;
typedef struct A_80415B38 A_80415B38;
typedef struct C_80415B38 C_80415B38;
typedef struct B_80415B38 B_80415B38;
typedef struct G_80415B38 G_80415B38;
typedef struct Arg2_80415B38 Arg2_80415B38;
typedef struct Ent_80418670 Ent_80418670;
typedef struct Sub_804162A4 Sub_804162A4;
typedef struct Ent_804162A4 Ent_804162A4;
typedef struct Glob_804162A4 Glob_804162A4;
typedef struct Arg_804162A4 Arg_804162A4;
typedef struct Ent_80416678 Ent_80416678;
typedef struct Peer_80416994 Peer_80416994;
typedef struct Sub_80416994 Sub_80416994;
typedef struct Ent_80416994 Ent_80416994;
typedef struct Glob_80416994 Glob_80416994;
typedef struct Msg_80416994 Msg_80416994;
typedef struct Item_80416994 Item_80416994;
typedef struct Pkt_80416994 Pkt_80416994;
typedef struct Arg_80416994 Arg_80416994;
typedef struct PeerU_80417494 PeerU_80417494;
typedef struct Buf_80417494 Buf_80417494;
typedef struct Arg3_80417494 Arg3_80417494;
typedef struct Hdr_804177A0 Hdr_804177A0;
typedef struct Arg_80417D1C Arg_80417D1C;
typedef struct Arg_80417E60 Arg_80417E60;
typedef struct E_804184DC E_804184DC;
typedef struct G_80418670 G_80418670;
typedef struct Ent_804188E4 Ent_804188E4;
typedef struct Rec_804188E4 Rec_804188E4;
typedef struct G_804188E4 G_804188E4;
typedef struct A_80418ACC A_80418ACC;
typedef struct B_80418ACC B_80418ACC;
typedef struct G_80418ACC G_80418ACC;
typedef struct E_80418BD8 E_80418BD8;
typedef struct A_80418BD8 A_80418BD8;
typedef struct N_80419258 N_80419258;
typedef struct E_80419258 E_80419258;
typedef struct G_80419258 G_80419258;
typedef struct N_804196EC N_804196EC;
typedef struct E_804196EC E_804196EC;
typedef struct G_804196EC G_804196EC;
typedef void (*Fn_8040881C)(void);
typedef s16 (*Init_8040881C)(s16);
typedef s32 (*SendFn_80408C24)(s16, u8 *, s16);
typedef void (*CbA_8040C540)(s16, s32, s16, s32, s16);
typedef void (*CbB_8040C540)(s16, u32, s16);
typedef void (*Handler_8041A130)(s32, s16, s16, s16);
s16 alloc_conn_slot(s16 h, s16 v);
u8 * alloc_free_entry(void);
s32 build_dns_query_a(void *self, u8 *name, s16 len);
s32 build_dns_query_aaaa(void *self, u8 *name, s16 len);
u16 calc_ip_checksum(void *self, s16 b);
u16 calc_pseudo_header_checksum(s32 src, s32 dst, s8 proto, void *pkt, s16 flag);
s32 call_entry_callback(s16 i, s32 arg);
s32 call_handler_by_index(s16 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
s32 clear_all_used_records(void);
s32 clear_conn_slot(s16 i);
s32 clear_table_entry_locked(s16 arg0);
s32 close_and_reset_connection(void *self);
s32 close_connection_by_index(s16 i);
s32 compare_sockaddr(void *self, u8 *arg1);
void complete_pending_request(s16 id);
s32 dispatch_by_addr_family(s32 arg0, u8 *arg1, u8 *arg2, u8 *arg3, void *arg4, void *arg5);
s32 dispatch_handler_by_id(s16 arg0, s32 arg1, s32 arg2);
s32 dispatch_handler_by_index(s16 arg0, s32 arg1, s32 arg2, s32 arg3);
void dispatch_request_callback(void *self, s16 status);
s32 dispatch_slot_a(s16 arg0, s32 arg1);
s32 dispatch_slot_b(s16 arg0, s32 arg1);
s32 fill_reply_buffer(s16 h, u8 *p);
void flush_flags_step(void);
s32 forward_net_op(s16 arg0, u8 *arg1, u8 *arg2);
s32 forward_socket_op_by_handle(s16 id, u8 *a, u8 *b);
s16 * get_active_entry_by_index(s16 arg0);
s16 get_entry_field_26(s16 arg0);
s16 get_slot_offset_or_default(s16 arg0);
s16 * get_valid_entry(s16 arg0);
s32 init_ipv4_interfaces(void);
void init_msg(void *self, s32 arg1);
void init_net_block_18A0(void);
s16 init_net_sockets(void);
s16 init_net_tables(void);
s32 init_packet_fragment_pools(void);
void init_packet_header(void *self, s32 arg1);
s32 invoke_socket_callback(s16 i, s32 arg);
s32 is_entry_flag10_set(s16 i);
s32 is_lookup_found(u32 arg0, u32 arg1);
s32 is_multicast_address(void *self, s16 arg1);
s32 is_slot_flag_0x20_set(s16 i);
s32 is_slot_flag_0x40_set(s16 i);
void process_expired_timers(void);
void release_entry(void *self);
s32 release_slot_by_id(u16 a);
s32 reset_net_value(void);
s32 reset_other_connection_lists(void *obj);
s32 reset_socket_table(void);
s16 run_connect_step(void);
s32 run_net_init_step(void);
void run_net_thread_loop(void);
s32 send_ethernet_frame(s16 idx, s16 mode, u8 *addr, void *pkt);
void set_value_and_enable(void *self, s32 arg1);
s32 shutdown_network_handle(void);
void tick_connection_timeouts(void);
void tick_entry_timers(void);
void update_timeout_entries(void);
Pkt_804081C0 *alloc_packet_with_header(Out_804081C0 *arg0, u8 *arg1);
s32 append_to_list(O_8040C4B0 *o, N_8040C4B0 *n);
Ent_80408718 *find_free_peer_entry(void);
Rec_8040B33C *find_next_active_record(A_8040B33C *a);
Ent_804086B4 *find_oldest_peer_entry(s16 key);
Ent_80408428 *find_or_add_peer_entry(s16 arg0, s32 arg1, u8 type, void *addr, u8 type2, void *addr2, s16 state);
s32 is_addr_unspecified(u8 *arg0);
s32 is_socket_flag_set(s16 i);
void ppp_input_packet(Strm_80405A74 *arg0);
s32 register_protocol_handler(u16 type, Handler_8041A130 fn);
void reset_connection_requests(Conn_8040AF48 *o_, s16 arg1);
s32 select_source_address(Out_8040D95C *arg0, In_8040D95C *arg1);

typedef struct PppRx { u8 *data; u16 len; } PppRx;
extern PppRx *ppp_rx_frame_ptr;
extern s16 lobby_modem_connect_state;
extern s32 lbl_805D7A8C;
extern s32 lbl_805D7A94;
extern u8 *lbl_805D7ADC;
extern u8 *lbl_805D7AE0;
extern u32 lbl_805D7AE4;
extern u16 lbl_805D7AE8;
extern u16 lbl_804FD3A8[];
extern u8 lbl_805C18B0[];
extern u8 lbl_805C04A8[];
extern s32 recv_network_frame(u16 arg0, void *arg1, u16 *arg2);
extern s32 is_transport_connected(void);
extern s16 TLobby__sub_804290D4(s32 idx);
extern s32 TLobby__sub_8040A044(s16, u32, s32, u32 *);
s16 TRKValidMemory32(u32, u32, u32, s16, u8, u16);


extern s32 TUdpSocket__sub_80421BAC(s16, s32, s32, s32, s32, s32, void *);
extern void TLobby__sub_8040B1C4(void *);
extern void TLobby__sub_8040BE40(u8 *self, s16 a, s16 b);
struct DnsHdr_804050DC { s16 h0; s16 h2; u32 h4; };
struct DnsRec_804050DC {
    s16 state; u8 pad2[2]; s16 f4; u8 pad6[4]; s16 fA; u8 padC[4];
    s16 f10; s16 f12; u8 pad14[4]; DnsHdr_804050DC *hdr; u8 pad1C[0x20];
};
struct DnsBase_804050DC {
    u8 pad0[0xC]; s16 *tbl; s16 div; u8 pad12[6]; s16 f18; s16 f1A;
    u8 pad1C[0x24]; s16 lim; u8 pad42[2]; DnsRec_804050DC *ents;
};

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

typedef struct Info_8040098C { u8 pad[0x1C]; s16 f1C; u8 pad1E[6]; u16 f24; u8 pad26[0x2A]; s16 f50; u8 pad52[6]; u16 f58; } Info_8040098C;
struct St_8040098C { s8 f0; u8 f1; u8 f2; u8 pad3[0x69]; u8 f6C[0x9C]; s32 f108; s32 f10C; };
struct Self_8040098C { u8 pad[0xC]; St_8040098C *st; u8 pad10[0x20]; Info_8040098C *info; };

struct RecoveredGlobal_8041552C_lbl_805C1BE0 {
    s32 value;
    u8 remaining[0x14];
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

typedef struct RtEntry_8040F8A4 { u16 flags; u8 pad2[2]; u32 id; u32 mask; u32 owner; u8 pad10[4]; } RtEntry_8040F8A4;
struct RtTbl_8040F8A4 { s16 count; u8 pad2[6]; RtEntry_8040F8A4 *entries; };

typedef struct E_8040DDB0 { u8 c0; u8 c1; u8 c2; u8 c3; s16 f4; u8 pad6[0x16]; } E_8040DDB0;
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

typedef struct E_8040FF58 { u8 c0; u8 c1; u8 c2; u8 c3; s16 f4; u8 pad6[0x2E]; } E_8040FF58;
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

struct RecoveredGlobal_80409A3C_lbl_805C1C50 {
    s32 value;
    u8 remaining[0xF4];
};

typedef struct Inner_80401CAC { u8 pad[4]; u16 f4; } Inner_80401CAC;

typedef struct Outer_80401CAC { Inner_80401CAC *p; } Outer_80401CAC;

typedef struct Ent_80408718 { s16 f0; u8 pad[0x16]; } Ent_80408718;

typedef struct Tbl_80408718 { s16 count; s16 h2; s16 h4; s16 h6; s16 h8; u8 pad[4]; Ent_80408718 *list; u8 tail[0x14]; } Tbl_80408718;

typedef struct Obj_80405304 { u8 pad[0x18]; u8 f18; } Obj_80405304;

typedef struct Cfg_803F87E0 { s32 w[10]; } Cfg_803F87E0;

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

struct Ent_804099B4 {
    s16 active;
    u8 pad[0x2E];
};

struct Tbl_804099B4 {
    s16 count;
    Ent_804099B4 *ents;
};

struct Ent_80409B48 {
    s16 active;
    u8 pad[0x2A];
    s32 (*fn)(s32, s32, s32, s32);
};

struct Tbl_80409B48 {
    s16 count;
    Ent_80409B48 *ents;
};

struct Ent_80409BD4 {
    s16 active;
    s16 flags;
    u8 pad[0x24];
    s32 (*fn)(s32, s32, s32);
    u8 pad2[0x4];
};

struct Tbl_80409BD4 {
    s16 count;
    Ent_80409BD4 *ents;
};

typedef struct Hdr_8040B6E4 { u16 id; u8 f2; u8 f3; s16 qd; s16 an; s16 ns; s16 ar; u8 body[4]; } Hdr_8040B6E4;

typedef struct Pkt_8040B6E4 { u8 pad0[2]; s16 len; Hdr_8040B6E4 *hdr; } Pkt_8040B6E4;

typedef struct Q_8040B6E4 { u8 pad0[6]; u16 id; u8 pad8[0x10]; Pkt_8040B6E4 *pkt; } Q_8040B6E4;

typedef struct QT_8040B6E4 { s16 type; s16 cls; } QT_8040B6E4;

typedef struct Hdr_8040B790 { u16 id; u8 f2; u8 f3; s16 qd; s16 an; s16 ns; s16 ar; u8 body[4]; } Hdr_8040B790;

typedef struct Pkt_8040B790 { u8 pad0[2]; s16 len; Hdr_8040B790 *hdr; } Pkt_8040B790;

typedef struct Q_8040B790 { u8 pad0[6]; u16 id; u8 pad8[0x10]; Pkt_8040B790 *pkt; } Q_8040B790;

typedef struct QT_8040B790 { s16 type; s16 cls; } QT_8040B790;

typedef struct Strm_80405A74 { u8 *p; u16 len; } Strm_80405A74;

typedef struct G_8041509C { s16 a; u8 pad[0xA]; s16 c; } G_8041509C;

typedef struct Tbl_80409AD8 { s16 count; u8 *list; } Tbl_80409AD8;

typedef struct Pkt_804081C0 { u8 pad0[4]; s32 f4; s32 f8; s16 fC; u8 padE[2]; u8 f10[8]; } Pkt_804081C0;

typedef struct Pool_804081C0 { u8 pad0[0x24]; u8 *f24; } Pool_804081C0;

typedef struct Out_804081C0 { u8 *f0; u8 *f4; u8 *f8; u8 *fC; u8 *f10; } Out_804081C0;

typedef struct Pkt_80407640 { u8 pad0[6]; u16 f6; } Pkt_80407640;
struct Hit_80407640 { s16 used; s16 f2; s16 f4; s16 f6; u8 pad8[2]; u8 fA[4]; u8 fE; u8 fF; u8 pad10[0x10]; };
struct Peer_80407640 { s16 used; u8 pad2[3]; u8 f5; u8 pad6[0xC]; u8 name[6]; };
struct Tbl_80407640 { s16 npeer; s16 nhit; u8 pad4[0xC]; Peer_80407640 *peers; Hit_80407640 *hits; };
struct Ent_804082AC;
struct Key_804082AC;

typedef struct Ent_8040A13C { s16 f0; s16 f2; u8 pad[0x2C]; } Ent_8040A13C;

typedef struct G_8040A13C { s16 n; Ent_8040A13C *p; } G_8040A13C;

typedef struct Ent_8040A19C { s16 f0; s16 f2; u8 pad[0x2C]; } Ent_8040A19C;

typedef struct G_8040A19C { s16 n; Ent_8040A19C *p; } G_8040A19C;

typedef struct Ent_80409F44 { s16 st; s16 pad2; s32 (*f4)(s32); s32 (*f8)(s32); s32 (*fC)(s32); s32 (*f10)(s32); u8 pad14[0x30-0x14]; } Ent_80409F44;

typedef struct Tbl_80409F44 { s16 count; Ent_80409F44 *list; } Tbl_80409F44;

#include "pso/network/IPv6Send.h"
#include "pso/network/NetStackTypes.h"

typedef struct T_804179A4 { u8 pad0[3]; u8 f3; u8 pad4[2]; s16 f6; u8 pad8[0xC]; u8 f14[0x10]; } T_804179A4;

typedef struct Seg_804179A4 { s16 len; s16 pad; u8 buf[8]; } Seg_804179A4;

typedef struct Pkt_804179A4 { u8 pad0[4]; u32 n; s32 total; Seg_804179A4 seg[1]; } Pkt_804179A4;

typedef struct Na_804179A4 { u8 type; u8 code; s16 cksum; u8 flags; u8 rsv[3]; u8 target[16]; } Na_804179A4;

typedef struct Cur_804179A4 { u8 pad[8]; } Cur_804179A4;

typedef struct Sock_804179A4 { u8 pad0[0x10]; u8 addr[0x10]; s32 f20; s16 f24; u8 f26; u8 f27; } Sock_804179A4;

typedef struct Q_804179A4 { u8 pad0[3]; u8 f3; u8 pad4[0x2C]; s16 f30; u8 pad32[2]; u8 *f34; } Q_804179A4;

typedef struct E_804179A4 { u8 pad0[3]; u8 f3; s16 f4; s16 f6; s16 f8; s16 fa; u8 fc; u8 pad[3]; Q_804179A4 *f10; s16 f14; u8 f16[0x10]; s16 f26; u8 f28[1]; } E_804179A4;

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
s16 TLobby__sub_80407F20(s16 a, s16 b, s16 c, s16 d, s16 e, s32 f, s16 g, s32 h);
s32 TLobby__sub_8040878C(void);
void TLobby__sub_803F8A9C(void *);
extern s16 lobby_handler_table_desc;
s32 TLobby__sub_80409AA8(void);
s32 TLobby__sub_8040C9E0(u8 *arg0, u8 *arg1);
u16 TLobby__sub_8040D8F0(u8 *arg0, u8 *arg1, s8 arg2, u8 *arg3, s16 arg4);
s32 TLobby__sub_8040DA54(u8 *arg0, u8 *arg1);
s32 TLobby__sub_8040FDA0(u32, s16);
extern RecoveredGlobal_8040EF00_lbl_805C1B60 ipv4_address_routing_state;

struct Req_8040F00C {
    u8 head[8];
    u32 flags;
    u32 a;
    u32 b;
    u32 c;
    u8 pad[0xc];
};
u8 * TLobby__sub_8040F76C(u32, u32);
s32 TLobby__sub_8040FEE4(s32 arg0, s32 arg1);
extern RecoveredGlobal_8041123C_lbl_805C1BB8 ipv6_address_routing_state;
u8 * TLobby__sub_80413264(void *, s32);
s32 TLobby__sub_80413230(u8 *arg0, s32 arg1);
s32 TLobby__sub_804136AC(s16 i);
void TLobby__sub_804136CC(s16 arg0);
s16 NetIPv6IsLoopback(u8 *arg0);
s32 NetIPv6IsUnspecified(u8 *arg0);
s32 NetIPv6CompareAddresses(s32 arg0, s32 arg1);
s16 TLobby__sub_8041510C(void);
void TLobby__sub_804150EC(void);
void TLobby__sub_8041615C(void);
void NetIPv6TickNeighborCache(void);
void NetIPv6TickNeighborDiscovery(void);
s16 TLobby__sub_80413D78();
s16 NetIPv6EmitNeighborSolicitation(int arg0, void *arg1, void *arg2, s16 arg3, int arg4);
s32 NetIPv6SendUnspecifiedSourceNeighborSolicitation(s32 arg0, s16 arg1);
extern NetworkDispatchState network_dispatch_state;
s32 TLobby__sub_804112B8(s32 arg0, s32 arg1, s16 arg2);
s32 TLobby__sub_8041123C(s32 arg0, s32 arg1, s16 arg2);
s32 TLobby__sub_8040FE40(s16 arg0);
void TLobby__sub_803F8930(u8 *arg0);
s32 TLobby__sub_803FE6CC(void *, int, int, void *);
void TLobby__sub_80405328(u8 *arg0);
s16 TLobby__sub_8040FCEC(u32);
s32 TLobby__sub_804136EC(void *);
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
struct NbPoolView {
    s16 count;
    u8 *ents;
};
#define NBP ((NbPoolView *)&network_buffer_pool_state)
s16 TLobby__sub_8041579C(void *);
s16 TLobby__sub_8040A2BC(void *, s16);
s16 TLobby__sub_80409A3C(u8 *arg0, s16 arg1);
s16 TLobby__sub_80415954(void *out_, int handle, s16 flag);
void TLobby__sub_803FD958(u8 *arg0);
void TLobby__sub_80401CAC(Outer_80401CAC *o, u16 v);
u16 read_network_u16_be(u8 *p);
u8 *write_network_u16_be(u8 *p, u16 v);
extern Tbl_80408718 lbl_805C1AB0;
s32 TLobby__sub_80405304(void *arg0);
u16 TLobby__sub_80406BD8(void *, s16);
s32 OSDisableInterrupts(void);
s32 OSRestoreInterrupts(s32);
void TLobby__sub_803F97E8(int);
extern u8 lbl_805C0038[];
extern s32 lbl_805D7A90;
extern s16 lbl_805D7A7C;
s32 TLobby__sub_8040B838(u8 *dst, u8 *src, s32 max);
s16 TLobby__sub_8040DC8C(u8 *arg0, u8 *arg1);
s32 TLobby__sub_804217E4(void);
s32 TLobby__sub_80421814(void);
s32 TLobby__sub_80421B3C(s32);
s16 TLobby__sub_80401BCC(void *, void *, int);
s32 TLobby__sub_803FDBF8(void *, Strm_80405A74 *);
void TLobby__sub_8040098C(Self_8040098C *self);
s32 PADRead(void *, Strm_80405A74 *);
s16 TLobby__sub_80403F4C(void *, Strm_80405A74 **);
s16 TLobby__sub_804040E0(void *, Strm_80405A74 **);
s32 TLobby__sub_804060B8(u8 *, u16, int);
extern u8 lobby_ppp_read_buf;
extern u8 ppp_input_byte;
s32 NetCompareBitsBackward(u8 *arg0, u8 *arg1, s16 arg2);
s32 NetCompareBitPrefix(u8 *a, u8 *b, s16 bits);
s32 NetIPv6MakeSolicitedNodeMulticastAddress(u8 *arg0, u8 *arg1);
void TLobby__sub_803F8B78(void *cfg);
s32 TLobby__sub_8041509C(void);
s32 TLobby__sub_80409AD8(void);
s32 init_ipv6_all_routers_multicast_address(u8 *arg0, s8 arg1);
u8 init_ipv6_all_nodes_multicast_address(u8 *arg0, s8 arg1);
void TLobby__sub_80406EB8();
void TLobby__sub_80406FD8(void *, void *, s32);
s16 TLobby__sub_80413F0C();
s16 TLobby__sub_80416F58(u8 *self, s32 n, void *out, void *arg_);
s16 TLobby__sub_80417028(void *, void *, void *, void *);
s16 NetIPv6HandleNeighborSolicitation(u8 *arg0, void *arg1, void *arg2, void *arg3);
s16 TLobby__sub_80410BA8(void *self, void *a, s16 c, void *d);
u16 TLobby__sub_80411040(const struct IPv6Address * p_, const struct IPv6Address * q_, u8 c, const struct NetPacket * d_, s16 e);
s32 NetIPv6EmitRouterSolicitation(NetPacket *arg0, NetIPv6SendParameters *arg1, s32 arg2);
s16 NetIPv6GetInterfaceLinkLayerAddress(s32 arg0, s16 arg1, s16 arg2);
extern struct G_80415B38 ipv6_neighbor_discovery_state;
s16 NetIPv6SendNeighborAdvertisement(Pkt_804179A4 *arg0, u8 *arg1, u8 arg2, Sock_804179A4 *arg3, s16 arg4);
s32 NetRegisterTimer(s32 period, s16 locked, NetTimerCallback fn);
void TLobby__sub_803F8864(void *);
void TLobby__sub_803F88E0(void *);
void TLobby__sub_803F89A0(void *);
void TLobby__sub_803F8A24(void *);
s32 NetIPv6IsLinkLocal(u8 *arg0);
s32 TLobby__sub_8041549C(s16 arg0);
s32 TLobby__sub_804154C0(s16 arg0);
s32 TLobby__sub_804154E4(s16 arg0);
s32 TLobby__sub_80415508(s16 arg0);

void TLobby__sub_803F87DC(void * _w0);

void TLobby__sub_803F892C(void * _w0);

void TLobby__sub_803F8958(void * _w0);

void TLobby__sub_803F89D8(void * _w0);

void TLobby__sub_803F8A08(void * _w0);

void TLobby__sub_803F8A9C(void * _w0);

extern s16 lobby_modem_abort_flag;
struct Outer_80401CAC;
void TLobby__sub_80401CAC(Outer_80401CAC *, u16);
s32 TLobby__sub_80405304(void *);

struct N_80405298;
void TLobby__sub_80405298(N_80405298 *o, s32 v);

void TLobby__sub_803FD85C(void *arg0);

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

#pragma opt_propagation off
#pragma opt_propagation reset

s16 TLobby__sub_80403F4C(void *ov, Strm_80405A74 **spp);

typedef struct Ent_804089A8 { s16 used; s16 f2; s16 f4; u16 f6; s16 f8; u8 padA[2]; void *slot; } Ent_804089A8;
struct Slot_804089A8 { s16 used; s16 x; s16 idx; s16 f2; s16 b; u8 pad[0xE]; u8 buf[1]; };
struct Tbl_804089A8 { u8 pad0[4]; s16 n; s16 m; u8 pad8[8]; Ent_804089A8 *ents; Slot_804089A8 *slots; };
void TLobby__sub_80409818(s32, s16, s16, s16, u16);

extern u8 lbl_805C18B0[];
extern u32 lbl_805C1AD8[6];
#define lbl_805C1AD8 (*(Tbl_80408F2C *)lbl_805C1AD8)

void TLobby__sub_804050DC(s16 arg0) {
    *(s16 *)((s8 *)(&lbl_805C18A0.value) + 8) = arg0;
}
void init_net_block_18A0(void) {
    TLobby__sub_803F79AC((void *) (&(*(RecoveredGlobal_804050EC_lbl_805C18A0 *)&lbl_805C18A0).value));
}
s32 run_net_init_step(void) {
    TLobby__sub_803F79B0((u8 *)(&(*(RecoveredGlobal_80405114_lbl_805C18A0 *)&lbl_805C18A0).value));
    return 0;
}

s16 reset_network_timer_list(void) {
    lobby_timer_list_head = 0;
    return 0;
}

typedef struct G_80405150 { s32 p0; s32 p4; s16 h8; } G_80405150;
extern s16 lbl_805D7A84;
extern s16 lbl_805D7A88;
s32 TLobby__sub_803FB6A0(void);
void TLobby__sub_803FB7A4(void);
void run_net_thread_loop(void) {
    G_80405150 *g = (G_80405150 *)&lbl_805C18A0;
    for (;;) {
        if (lobby_modem_abort_flag != 0) {
            lock_mutex(g->p0);
            TLobby__sub_803FB6A0();
            unlock_mutex(g->p0);
            continue;
        }
        if (lbl_805D7A88 != 0) {
            lock_mutex(g->p0);
            TLobby__sub_803FB7A4();
            unlock_mutex(g->p0);
            continue;
        }
        TLobby__sub_803F97E8(g->h8);
        if (lbl_805D7A84 != 0) {
            process_expired_timers();
        }
    }
}

struct Timer_804051CC {
    struct Timer_804051CC *next;
    u8 pad4[4];
    u32 f8;
    s32 fC;
    void (*f10)(s32);
    s32 f14;
    u8 f18;
};

s32 TLobby__sub_80405700();

void process_expired_timers(void) {
    s32 now;
    Timer_804051CC *t;

    lock_mutex(lbl_805C18A0.value);
    TLobby__sub_80405700();
    get_time_ms(&now);
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
    unlock_mutex(lbl_805C18A0.value);
}

typedef struct N_80405298 { N_80405298 *next; s32 f4; u8 pad8[0x18 - 8]; u8 b18; } N_80405298;
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
    typedef struct Fields_arg0 { u8 pad_0[4]; u32 field_4; u32 field_8; u8 pad_C[4]; u32 field_10; u8 pad_14[4]; u8 field_18; } Fields_arg0;
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
            get_time_ms((s32 *)((void *) (arg0 + 0xC)));
            if ((u32) ((Fields_arg0*)arg0)->field_10 != 0U) {
                ((Fields_arg0*)arg0)->field_18 = 1U;
            }
        }
    }
}

extern s32 TLobby__sub_804053B8(void *self, u8 **pp)
{
  struct Hdr_804053B8
  {
    u16 h0;
    u16 h2;
    u32 h4;
    u32 h8;
    u8 hc;
    u8 hd;
    u16 he;
    u16 h10;
    u16 h12;
  } hdr;
  u8 *b = (u8 *) self;
  u8 *p;
  u16 size;
  u16 rem;
  u8 flags;
  u8 cb;
  u32 pad;
  s32 ret;
  u8 c;
  u32 n;
  ret = TLobby__sub_80401BCC(pp, &hdr, 0x14);
  (void) (&pad);
  *((u16 *) b) = hdr.h0;
  *((u16 *) (b + 0x2)) = hdr.h2;
  *((u32 *) (b + 0x4)) = hdr.h4;
  *((u32 *) (b + 0x8)) = hdr.h8;
  flags = hdr.hd;
  cb = hdr.hc;
  b[0x15] = flags & 0x20;
  b[0x16] = flags & 0x10;
  b[0x17] = flags & 0x8;
  b[0x18] = flags & 0x4;
  b[0x19] = flags & 0x2;
  b[0x1a] = flags & 0x1;
  cb = (cb & 0xf0) >> 2;
  *((u16 *) (b + 0xc)) = hdr.he;
  *((u16 *) (b + 0xe)) = hdr.h10;
  *((u16 *) (b + 0x10)) = hdr.h12;
  *((u16 *) (b + 0x12)) = 0;
  b[0x1b] = cb - 0x14;
  if ((((u16) ret) < 0x14) || (0x14 > cb))
  {
    return 0;
  }
  if (b[0x1b] == 0)
  {
    return cb;
  }
  if (b[0x1b] > get_field_4((void *) (*pp)))
  {
    return 0;
  }
  TLobby__sub_80401BCC(pp, b + 0x1c, b[0x1b]);
  rem = b[0x1b];
  p = b + 0x1c;
  while (rem != 0)
  {
    c = p[0];
    if (c == 0)
    {
      break;
    }
    if (c == 1)
    {
      size = 1;
    }
    else
    {
      n = p[1];
      size = n;
      if (n == 0)
        break;
    }
    switch (c)
    {
      case 2:
        if (size == 4)
      {
        *((u16 *) (b + 0x12)) = (p[2] << 8) | p[3];
      }
        break;

    }

    rem -= size;
    p += size;
  }

  return cb;
}

extern u16 TLobby__sub_803FE934(u8 *obj, u8 *buf, u16 n);
extern void NetMemcpy(void *_w0, void *_w1, int _w2);
extern u16 TLobby__sub_803FE934(u8 *obj, u8 *buf, u16 n);
extern void NetMemcpy(void *_w0, void *_w1, int _w2);
extern u8 *TLobby__sub_8040555C(u8 *self, void *lobby, u8 *obj) {
    u8 hdr[0x3c];
    u32 n = 0;
    u8 *buf;
    u8 *hp;
    u8 *dst;
    u8 flags;
    u32 len;

    if (self[0x1b] != 0 && self[0x1b] <= 0x28) {
        n = self[0x1b];
    } else if (*(u16 *)(self + 0x12) != 0) {
        n = 4;
    }
    buf = alloc_from_buffer(lobby, n + 0x14);
    if (buf == NULL) {
        return NULL;
    }
    dst = *(u8 **)buf;
    hp = hdr;
    flags = 0;
    *(u16 *)(hp + 0) = *(u16 *)(self + 0);
    *(u16 *)(hp + 2) = *(u16 *)(self + 2);
    *(u32 *)(hp + 4) = *(u32 *)(self + 4);
    *(u32 *)(hp + 8) = *(u32 *)(self + 8);
    hp[0xc] = (u8)((n + 0x14) << 2);
    if (self[0x15]) {
        flags |= 0x20;
    }
    if (self[0x16]) {
        flags |= 0x10;
    }
    if (self[0x17]) {
        flags |= 0x8;
    }
    if (self[0x18]) {
        flags |= 0x4;
    }
    if (self[0x19]) {
        flags |= 0x2;
    }
    if (self[0x1a]) {
        flags |= 0x1;
    }
    hp[0xd] = flags;
    *(u16 *)(hp + 0xe) = *(u16 *)(self + 0xc);
    if (obj == NULL) {
        *(u16 *)(hp + 0x10) = *(u16 *)(self + 0xe);
    } else {
        *(u16 *)(hp + 0x10) = 0;
    }
    *(u16 *)(hp + 0x12) = *(u16 *)(self + 0x10);
    len = 0;
    if ((u16)n > len) {
        NetMemcpy(hp + 0x14, self + 0x1c, self[0x1b]);
    }
    len = (u16)(n + 0x14);
    NetMemcpy(dst, hp, len);
    if (obj != NULL) {
        *(u16 *)(hp + 0x10) = TLobby__sub_803FE934(obj, buf, *(u16 *)(obj + 0xa));
    }
    NetMemcpy(dst, hp, len);
    return buf;
}

#pragma push
#pragma opt_common_subs on
s32 TLobby__sub_80405700()
{
  PppRx *frame;
  u32 b;
  u16 id;
  u8 c;
  PppRx **new_var;
  u16 st;
  u16 n;
  u8 *base;
  u16 is_transport_connected(void);
  if (lobby_modem_connect_state == 10)
  {
    if (TLobby__sub_804290D4(0x7fff) == 0)
    {
      lobby_modem_connect_state = 1;
    }
    return 0;
  }
  if (lbl_805D7A7A != 0)
  {
    u8 *base = lbl_805C04A8;
    for (;;)
    {
      new_var = (PppRx **) (base + 0x18);
      ppp_rx_frame_ptr = (frame = *new_var);
      ppp_rx_frame_ptr->data = ((u8 *) frame) + (((*((s32 *) base)) + 0x83) & (~3));
      ppp_rx_frame_ptr->len = 0;
      if ((recv_network_frame(0x5d6, ppp_rx_frame_ptr->data, &ppp_rx_frame_ptr->len) != 0) || (ppp_rx_frame_ptr->len < 1))
      {
        break;
      }
      get_time_ms(&lbl_805D7A94);
      frame = ppp_rx_frame_ptr;
      b = (frame->data[0] & 0xFFFFFFFFFFFFFFFFu);
      id = b;
      if (!(b & 1))
      {
        id = (b << 8) | frame->data[1];
      }
      ppp_input_packet((Strm_80405A74 *) frame);
      if (((id != 0x21) && (id != 0x2d)) && (id != 0x2f))
      {
        break;
      }
    }

    if ((lobby_modem_connect_state == 4) && (is_transport_connected() == 0))
    {
      lobby_modem_connect_state = 5;
    }
    return 0;
  }
  if (lbl_805D7ADC == 0)
  {
    lbl_805D7ADC = lbl_805C18B0;
    ppp_rx_frame_ptr = 0;
    lbl_805D7AE8 = 0xffff;
    lbl_805D7AE4 = 0;
    lbl_805D7AE0 = lbl_805C18B0;
  }
  base = lbl_805C04A8;
  for (;;)
  {
    if (lbl_805D7ADC == lbl_805D7AE0)
    {
      if ((recv_network_frame(0x200, lbl_805C18B0, &st) != 0) || (st < 1))
      {
        goto tail;
      }
      lbl_805D7ADC = lbl_805C18B0;
      lbl_805D7AE0 = lbl_805C18B0 + st;
    }
    c = *(lbl_805D7ADC++);
    if (c == 0x7e)
    {
      if (((ppp_rx_frame_ptr != 0) && (ppp_rx_frame_ptr->len < 0x800)) && (lbl_805D7AE8 == 0xf0b8))
      {
        n = get_field_4((void *) ppp_rx_frame_ptr) - 2;
        TLobby__sub_80401CAC((Outer_80401CAC *) (&ppp_rx_frame_ptr), n);
        get_time_ms(&lbl_805D7A94);
        ppp_input_packet((Strm_80405A74 *) ppp_rx_frame_ptr);
        ppp_rx_frame_ptr = 0;
        return 1;
      }
      ppp_rx_frame_ptr = 0;
      continue;
    }
    if ((c == 0x7d) != 0U)
    {
      lbl_805D7AE4 |= 1;
      continue;
    }
    if (ppp_rx_frame_ptr == 0)
    {
      ppp_rx_frame_ptr = (frame = *((PppRx **) (base + 0x18)));
      ppp_rx_frame_ptr->data = ((u8 *) frame) + (((*((s32 *) base)) + 0x83) & (~3));
      ppp_rx_frame_ptr->len = 0;
      lbl_805D7AE4 = 0;
      lbl_805D7AE8 = 0xffff;
    }
    if (lbl_805D7AE4 & 1)
    {
      lbl_805D7AE4 &= ~1;
      c ^= 0x20;
    }
    if (ppp_rx_frame_ptr->len >= 0x800)
    {
      continue;
    }
    ppp_rx_frame_ptr->data[ppp_rx_frame_ptr->len++] = c;
    lbl_805D7AE8 = (lbl_805D7AE8 >> 8) ^ lbl_804FD3A8[(lbl_805D7AE8 ^ c) & 0xff];
  }

  tail:
  if ((((u16) (lobby_modem_connect_state - 3)) <= 1) && (is_transport_connected() == 0))
  {
    if ((((u32) lbl_805D7A8C) != 0) && (lobby_modem_connect_state == 4))
    {
      unlock_mutex((int) (*((u32 *) (&lbl_805C18A0))));
      ((void (*)(s32, s32)) lbl_805D7A8C)(-1, 0);
      lock_mutex((int) (*((u32 *) (&lbl_805C18A0))));
    }
    lobby_modem_connect_state = 5;
  }

  return 0;
}
#pragma pop
struct Lobby_804062A0 {
    u8 state;
    u8 pad[3];
    u8 sub[0x140];
};
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
    t = (Strm_80405A74 *)alloc_from_buffer((void *)arg0, 4); \
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
void ppp_input_packet(Strm_80405A74 *arg0) {
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
        dispatch_received_packet((void *)(G + 0xA0), (s32)arg0);
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

extern p803FB184_Unk805BC510 lobby_net_buffer_desc_b;
extern p803FB184_Unk805BC510 lobby_net_buffer_desc_b;
extern p803FB184_Unk805BC510 lobby_net_buffer_desc_b;
extern p803FB184_Unk805BC510 lobby_net_buffer_desc_b;
extern p803FB184_Unk805BC510 lobby_net_buffer_desc_b;
#pragma push
#pragma opt_common_subs on
s32 TLobby__sub_804060B8(u8 *src, u16 len, int id) {
    int i;
    int idx;
    s32 n;
    s32 t;
    s16 *lim;
    s16 j;
    s16 *flags;
    u8 *dst;
    s16 stride;
    s32 TLobby__sub_80409818(void *, s32, s16, s32, u16);
    void NetMemcpy(void *, void *, s16);

    for (i = 0; (s16)i < 2; i++) {
        if (lobby_net_buffer_desc_b.unk2[i].unk0 != 0 && (u16)lobby_net_buffer_desc_b.unk2[i].unk2 == (u16)id) {
            idx = i;
            break;
        }
    }
    if ((s16)i >= 2) {
        return 0;
    }
    lim = &lobby_net_buffer_desc_b.unk14;
    flags = lobby_net_buffer_desc_b.unkC;
    dst = (u8 *)lobby_net_buffer_desc_b.unk10;
    stride = lim[0];
    for (j = 0; j < lobby_net_buffer_desc_b.unk16; j++) {
        if (*flags == 0) {
            *flags = 1;
            if ((s16)len < *lim) {
                t = (s16)len;
            } else {
                t = *lim;
            }
            n = t;
            NetMemcpy(dst, src, n);
            TLobby__sub_80409818(dst, n, lobby_net_buffer_desc_b.unk0, idx, lobby_net_buffer_desc_b.unk2[(s16)idx].unk2);
            return 0;
        }
        flags++;
        dst += stride;
    }
    return 0;
}
#pragma pop
void NetMemset(void* destination, int value, int size);
#pragma push
#pragma cplusplus off
void TLobby__sub_8040059C(void* self);
void TLobby__sub_80402CE0(void* self);
void TLobby__sub_803FC318(void* self);
void TLobby__sub_803FEF4C(void* self);
void TLobby__sub_803F9FAC(void* self);
#pragma pop
#pragma push
#pragma cplusplus off
#pragma dont_inline off
#pragma inline_depth(4)
#pragma dont_inline off
s32 TLobby__sub_804061FC(void)
{
  void NetMemset(void *, s32, u32);
  void TLobby__sub_803FD958(void *);
  u8 *p;
  s32 z;
  u8 *new_var;
  u8 *q;
  z = 0;
  lbl_805D7ADC = (u8 *) z;
  p = lbl_805C0038;
  q = p;
  new_var = q;
  NetMemset(q, 0, 0x144);
  p[0] = z;
  TLobby__sub_8040059C(new_var);
  TLobby__sub_80402CE0(new_var);
  TLobby__sub_803FC318(new_var);
  TLobby__sub_803FEF4C(new_var);
  TLobby__sub_803F9FAC(new_var);
  if (p[0] == 0)
  {
    p[0] = 1;
  }
  TLobby__sub_803FD958(p + 4);
  return 0;
}
#pragma pop

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

s16 TLobby__sub_804048E8(void *, s32 *, u8);
s32 TLobby__sub_804066D8(u8 *);
s16 TLobby__sub_804048E8(void *, s32 *, u8);
s32 TLobby__sub_804066D8(u8 *);
s32 TLobby__sub_80406328(s32 self, s16 type) {
    s32 sv = self;
    void *me = (void *)self;
    s32 ty = type;
    u8 *G;
    u8 *t;
    u8 *p;
    s16 tag = 0x21;
    u8 pad[0x30];
    if (ty == -0x7923) {
        G = lbl_805C0038;
        if (G[0xd4] != 5) {
            (*(s16 *)(G + 0x122))++;
            return -1;
        }
        if (G[0] == 0) {
            (*(s16 *)(G + 0x122))++;
            return -1;
        }
        t = alloc_from_buffer(me, 4);
        p = *(u8 **)t;
        *p++ = 0xFF;
        *p++ = 3;
        write_network_u16_be(p, 0x57);
        if (t == NULL) {
            (*(s16 *)(G + 0x124))++;
            return -1;
        }
        return TLobby__sub_804066D8(t);
    }
    G = lbl_805C0038;
    if (G[0x6c] != 5) {
        (*(s16 *)(G + 0x122))++;
        return -1;
    }
    if (ty == 0x86dd) {
        if (G[0] == 0) {
            (*(s16 *)(G + 0x122))++;
            return -1;
        }
        t = alloc_from_buffer(me, 4);
        p = *(u8 **)t;
        *p++ = 0xFF;
        *p++ = 3;
        write_network_u16_be(p, 0x57);
        if (t == NULL) {
            (*(s16 *)(G + 0x124))++;
            return -1;
        }
        return TLobby__sub_804066D8(t);
    }
    {
        u8 *e = *(u8 **)(G + 0x9c);
        if (lbl_805D7A90 & 2) {
            s16 r;
            if (!(*(s16 *)(e + 0x28) & 4)) goto skip;
            r = TLobby__sub_804048E8(*(void **)(e + 0x98), &sv, e[0x84]);
            switch (r) {
            case 0x40: tag = 0x21; break;
            case 0x80: tag = 0x2d; break;
            case 0x70: tag = 0x2f; break;
            default:
                (*(s16 *)(G + 0x122))++;
                return -1;
            }
        } else {
            s16 r;
            if (!(*(s16 *)(e + 0x74) & 4)) goto skip;
            r = TLobby__sub_804048E8(*(void **)(e + 0x98), &sv, e[0x84]);
            switch (r) {
            case 0x40: tag = 0x21; break;
            case 0x80: tag = 0x2d; break;
            case 0x70: tag = 0x2f; break;
            default:
                (*(s16 *)(G + 0x122))++;
                return -1;
            }
        }
    }
skip:
    {
        void *a = (void *)sv;
        G = lbl_805C0038;
        if (G[0] == 0) {
            (*(s16 *)(G + 0x122))++;
            return -1;
        }
        {
            s16 tg = tag;
            u8 *t2 = alloc_from_buffer(a, 4);
            p = *(u8 **)t2;
            *p++ = 0xFF;
            *p++ = 3;
            write_network_u16_be(p, tg);
            if (t2 == NULL) {
                (*(s16 *)(G + 0x124))++;
                return -1;
            }
            return TLobby__sub_804066D8(t2);
        }
    }
}

#pragma push
#pragma use_lmw_stmw off
s32 TLobby__sub_80406624(s32 a, s32 b, u16 code, void *self) {
    s32 pad[4];
    u16 r30;
    u8 *r29;
    u8 *p;
    u8 *ret;

    if (lbl_805C0038[0] == 0) {
        *(s16 *)(lbl_805C0038 + 0x122) = *(s16 *)(lbl_805C0038 + 0x122) + 1;
        return -1;
    }
    r30 = code;
    r29 = alloc_from_buffer(self, 4);
    p = *(u8 **)r29;
    *p++ = 0xff;
    *p++ = 3;
    write_network_u16_be(p, r30);
    ret = r29;
    if (r29 == 0) {
        *(s16 *)(lbl_805C0038 + 0x124) = *(s16 *)(lbl_805C0038 + 0x124) + 1;
        return -1;
    }
    return TLobby__sub_804066D8(ret);
}
#pragma pop

void NetMemcpy(void* destination, void* source, int size);
void get_time_ms(s32* out);
u16 get_field_4(void *self);
#pragma push
#pragma cplusplus off
s32 send_network_frame(u32 a, void* b);
#pragma pop
#pragma push
#pragma cplusplus off
#pragma dont_inline off
#pragma inline_depth(4)
#pragma dont_inline off
#pragma opt_propagation off
#pragma opt_lifetimes off
inline s32 acfc_804066D8(s32 lcp, u8 *ctx)
{
  s32 r = 1;
  if ((!lcp) && ((*((s16 *) (ctx + 0x50))) & 0x100))
  {
    r = 0;
  }
  return r;
}
s32 TLobby__sub_804066D8(u8 *p)
{
  void NetMemcpy(void *, const void *, u32);
  u16 read_network_u16_be(u8 *);
  s32 TLobby__sub_80401BCC(u8 *, void *, s32);
  void get_time_ms(u32 *);
  u16 get_field_4(void *);
  u8 c0;
  u8 c1;
  u8 *st;
  u8 *ctx;
  s32 crc = 0xffff;
  u32 accm = -1;
  s32 n = 4;
  s32 sz;
  s16 stt;
  s32 padx[2];
  u8 *src;
  u8 *out;
  u8 *q;
  u8 *buf;
  u8 *obj;
  u16 tag;
  s32 two;
  unsigned short pad;
  s32 pfc;
  s32 acfc;
  s32 lcp;
  s32 d;
  s32 skip;
  u16 fcs;
  st = *((u8 (*)[]) (&lbl_805C0038));
  ctx = *((u8 **) (st + 0x34));
  *((s32 *) (st + 0x110)) += ((u16) get_field_4(p)) + 2;
  if ((p == ((void *) 0)) || ((*((u16 *) (p + 4))) < 4))
  {
    *((s16 *) (st + 0x122)) += 1;
    return -1;
  }
  src = *((u8 **) p);
  c0 = src[0];
  c1 = src[1];
  tag = read_network_u16_be(src + 2);
  lcp = tag == 0xc021;
  if ((tag != 0xc021) && ((*((s16 *) (ctx + 0x50))) & 4))
  {
    accm = *((u32 *) (ctx + 0x54));
  }
  two = 1;
  pfc = two;
  if ((!lcp) && ((*((s16 *) (ctx + 0x50))) & 0x80))
  {
    pfc = 0;
  }
  if ((pfc == 0) && (tag < 0xff))
  {
    two = 0;
  }
  if (two == 0)
  {
    n = 3;
  }
  if ((*((s16 *) (&lbl_805D7A7A))) != 0)
  {
    acfc = 0;
  }
  else
  {
    acfc = acfc_804066D8(lcp, ctx);
  }
  if (acfc == 0)
  {
    n -= 2;
  }
  skip = 4 - n;
  *((u16 *) (p + 4)) -= skip;
  *((u8 **) p) += skip;
  out = *((u8 **) p);
  if (acfc != 0)
  {
    out[0] = c0;
    out[1] = c1;
    out += 2;
  }
  if (two != 0)
  {
    *out = tag >> 8;
    out++;
  }
  *out = tag;
  sz = *((s32 *) obj);
  obj = *((u8 (*)[]) (&lbl_805C04A8));
  q = *((u8 **) (obj + 0x10));
  *((u8 **) q) = q + ((sz + 3) & (~3));
  buf = *((u8 **) q);
  if ((*((s16 *) (&lbl_805D7A7A))) != 0)
  {
    NetMemcpy(buf + 0x14, *((u8 **) p), *((u16 *) (p + 4)));
    *((u16 *) (q + 4)) = *((u16 *) (p + 4));
  }
  else
  {
    *buf = 0x7e;
    buf++;
    *((s32 *) (st + 0x114)) += 1;
    while ((d = get_80405A74((Strm_80405A74 **) (&p))) != (-1))
    {
      crc = (u16) ((((u16) crc) >> 8) ^ (*((u16 (*)[]) (&lbl_804FD3A8)))[(((u16) crc) ^ d) & 0xff]);
      if ((((d < 0x20) && (accm & (1 << d))) || (d == 0x7d)) || (d == 0x7e))
      {
        *(buf++) = 0x7d;
        *(buf++) = d ^ 0x20;
      }
      else
      {
        *(buf++) = d;
      }
    }

    crc ^= 0xffff;
    fcs = crc;
    d = fcs & 0xff;
    if ((((d < 0x20) && (accm & (1 << d))) || (d == 0x7d)) || (d == 0x7e))
    {
      *(buf++) = 0x7d;
      *(buf++) = d ^ 0x20;
    }
    else
    {
      *(buf++) = d;
    }
    d = fcs >> 8;
    if ((((d < 0x20) && (accm & (1 << d))) || (d == 0x7d)) || (d == 0x7e))
    {
      *(buf++) = 0x7d;
      *(buf++) = d ^ 0x20;
    }
    else
    {
      *(buf++) = d;
    }
    *(buf++) = 0x7e;
    *((u16 *) (q + 4)) = buf - (*((u8 **) q));
  }
  stt = *((s16 *) (&lobby_modem_connect_state));
  if ((stt == 7) || (stt == 0))
  {
    return 0;
  }
  get_time_ms(&(*((u32 *) (&lbl_805D7A94))));
  return (s16) send_network_frame(*((u16 *) (q + 4)), *((u8 **) q));
}
#pragma pop

s32 shutdown_network_handle(void) {
    TLobby__sub_803F8A08((void *)((void *) (&lobby_udp_socket_table)));
    lobby_udp_socket_table = 0;
    return 0;
}

void init_msg(void *self, s32 arg1) {
    *(s32 *)&((TObjectFields *)self)->m_name = arg1;
    *(s8 *)&((TObjectFields *)self)->m_flags = 4;
}

void init_packet_header(void *self, s32 arg1) {
    *(s32 *)&((TObjectFields *)self)->m_name = arg1;
    *(s8 *)&((TObjectFields *)self)->m_flags = 3;
}

void set_value_and_enable(void *self, s32 arg1) {
    *(s32 *)&((TObjectFields *)self)->m_name = arg1;
    *(s8 *)&((TObjectFields *)self)->m_flags = 1;
}

#pragma push
#pragma opt_common_subs on
#pragma opt_propagation off
void TLobby__sub_80406FD8(void *a, void *b, s32 v) {
    switch (*((u8 *)b + 4)) {
    case 1:
    case 4:
        switch (*((u8 *)a + 4)) {
        case 1:
        case 4:
            NetMemcpy(*(void **)a, *(void **)b, v);
            break;
        case 2:
            {
        u32 word = *(u32 *)a;
        s16 id = (s16)(word >> 24);
        u32 hi;
        u8 *rec;
        u8 *ent;
        u32 t;
        if (NBP->count < id) {
            return;
        }
        hi = word >> 16;
        rec = NBP->ents;
        rec += id * 0x3c;
        ent = rec + (s16)(hi & 0xff) * 6;
        t = *(u16 *)(ent + 0xe) + (word & 0xffff) + *(u32 *)rec;
        NetMemcpy((void *)t, *(void **)b, v);
        break;
    }
        case 3:
            NetMemcpy(*(void **)a, *(void **)b, v);
            break;
        }
        break;
    case 2:
        switch (*((u8 *)a + 4)) {
        case 1:
        case 4:
            {
        u32 word = *(u32 *)b;
        s16 id = (s16)(word >> 24);
        u32 hi;
        u8 *rec;
        u8 *ent;
        u32 t;
        if (NBP->count < id) {
            return;
        }
        hi = word >> 16;
        rec = NBP->ents;
        rec += id * 0x3c;
        ent = rec + (s16)(hi & 0xff) * 6;
        t = *(u16 *)(ent + 0xe) + (word & 0xffff) + *(u32 *)rec;
        NetMemcpy(*(void **)a, (void *)t, v);
        break;
    }
        case 2:
            {
        u32 word = *(u32 *)b;
        s16 id = (s16)(word >> 24);
        u32 hi;
        u8 *rec;
        u8 *ent;
        u32 t;
        u32 word2;
        s16 id2;
        u32 hi2;
        u8 *rec2;
        u8 *ent2;
        u32 t2;
        if (NBP->count < id) {
            return;
        }
        word2 = *(u32 *)a;
        id2 = (s16)(word2 >> 24);
        rec = NBP->ents + id * 0x3c;
        hi = word >> 16;
        ent = rec + (s16)(hi & 0xff) * 6;
        t = *(u16 *)(ent + 0xe) + (word & 0xffff) + *(u32 *)rec;
        if (NBP->count < id2) {
            return;
        }
        rec2 = NBP->ents + id2 * 0x3c;
        hi2 = word2 >> 16;
        ent2 = rec2 + (s16)(hi2 & 0xff) * 6;
        t2 = *(u16 *)(ent2 + 0xe) + (word2 & 0xffff) + *(u32 *)rec2;
        NetMemcpy((void *)t2, (void *)t, v);
        break;
    }
        case 3:
            {
        u32 word = *(u32 *)b;
        s16 id = (s16)(word >> 24);
        u32 hi;
        u8 *rec;
        u8 *ent;
        u32 t;
        if (NBP->count < id) {
            return;
        }
        hi = word >> 16;
        rec = NBP->ents;
        rec += id * 0x3c;
        ent = rec + (s16)(hi & 0xff) * 6;
        t = *(u16 *)(ent + 0xe) + (word & 0xffff) + *(u32 *)rec;
        NetMemcpy(*(void **)a, (void *)t, v);
        break;
    }
        }
        break;
    case 3:
        switch (*((u8 *)a + 4)) {
        case 1:
        case 4:
            NetMemcpy(*(void **)a, *(void **)b, v);
            break;
        case 2:
            {
        u32 word = *(u32 *)a;
        s16 id = (s16)(word >> 24);
        u32 hi;
        u8 *rec;
        u8 *ent;
        u32 t;
        if (NBP->count < id) {
            return;
        }
        hi = word >> 16;
        rec = NBP->ents;
        rec += id * 0x3c;
        ent = rec + (s16)(hi & 0xff) * 6;
        t = *(u16 *)(ent + 0xe) + (word & 0xffff) + *(u32 *)rec;
        NetMemcpy((void *)t, *(void **)b, v);
        break;
    }
        case 3:
            NetMemcpy(*(void **)a, *(void **)b, v);
            break;
        }
        break;
    }
}
#pragma pop
typedef struct Ent_80406B14 { s16 st; u8 pad[0x9c - 2]; } Ent_80406B14;
struct Tbl_80406B14 { s16 count; Ent_80406B14 *list; };
#pragma push
#pragma optimization_level 3
#pragma opt_unroll_loops off
s32 reset_socket_table(void) {
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
#pragma pop

typedef struct O_80406B6C { u32 w0; u8 b4; } O_80406B6C;
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

u16 TUdpSocket__sub_80419864();
u16 TLobby__sub_80406BD8(void *arg_, s16 flag)
{
  s32 count = *((s32 *) (((u8 *) arg_) + 4));
  u32 sum = 0;
  u8 *new_var;
  s16 carry = 0;
  u8 hdr[2];
  *((u16 *) hdr) = 0;
  if (flag == 1)
  {
    u8 *e;
    e = (u8 *) arg_;
    e += count * 12;
    while (count != 0)
    {
      u8 *ptr;
      u8 type = *((u8 *) (e + 8));
      u8 *w = e + 4;
      s16 len;
      count--;
      e -= 12;
      switch (type)
      {
        case 1:

        case 4:
          ptr = *((u8 **) w);
          break;

        case 2:
        {
          u32 word = *((u32 *) w);
          s16 id = (s16) (word >> 24);
          u8 *rec;
          if (NBP->count < id)
          {
            return 0;
          }
          rec = NBP->ents;
          rec = rec + (id * 0x3c);
          {
            u32 t = (*((u32 *) rec)) + (word & 0xffff);
            t = (*((u16 *) ((rec + (((s16) ((word >> 16) & 0xff)) * 6)) + 0xe))) + t;
            ptr = (u8 *) t;
          }
          break;
        }

        new_var = e;
        case 3:
          ptr = *((u8 **) (new_var + 16));
          break;

        default:
          break;

      }

      len = *((s16 *) (e + 12));
      if (carry)
      {
        hdr[1] = *(ptr++);
        sum += *((u16 *) hdr);
        len--;
      }
      if (len & 1)
      {
        hdr[0] = ptr[len + (-1)];
        hdr[1] = 0;
        carry = 1;
        len--;
      }
      else
      {
        *((u16 *) hdr) = 0;
        carry = 0;
      }
      len = (s16) (((s32) len) >> 1);
      sum += TUdpSocket__sub_80419864(ptr, len);
    }

    if (carry)
    {
      sum += *((u16 *) hdr);
    }
  }
  else
  {
    u8 *e = ((u8 *) arg_) + 12;
    s32 i;
    for (i = 1; i < count; e += 12, i++)
    {
      u8 *w = e + 0x10;
      u8 *ptr;
      s16 len;
      switch (*((u8 *) (e + 0x14)))
      {
        case 1:

        case 4:
          ptr = *((u8 **) w);
          break;

        case 2:
        {
          u32 word = *((u32 *) w);
          s16 id = (s16) (word >> 24);
          u8 *rec;
          if (NBP->count < id)
          {
            return 0;
          }
          rec = NBP->ents;
          rec = rec + (id * 0x3c);
          {
            u32 t = (*((u32 *) rec)) + (word & 0xffff);
            t = (*((u16 *) ((rec + (((s16) ((word >> 16) & 0xff)) * 6)) + 0xe))) + t;
            ptr = (u8 *) t;
          }
          break;
        }

        case 3:
          ptr = *((u8 **) (e + 0x10));
          break;

        default:
          break;

      }

      len = *((s16 *) (e + 12));
      if (carry)
      {
        hdr[1] = *(ptr++);
        sum += *((u16 *) hdr);
        len--;
      }
      if (len & 1)
      {
        hdr[0] = ptr[len - 1];
        hdr[1] = 0;
        carry = 1;
        len--;
      }
      else
      {
        *((u16 *) hdr) = 0;
        carry = 0;
      }
      len = (s16) (((s32) len) >> 1);
      sum += TUdpSocket__sub_80419864(ptr, len);
    }

    if (carry)
    {
      sum += *((u16 *) hdr);
    }
  }
  if (sum & 0xffff0000)
  {
    sum = (sum >> 16) + (sum & 0xffff);
    sum += sum >> 16;
  }
  return (u16) sum;
}

void TLobby__sub_80406EB8(u8* self, s32 delta)
{
    switch (self[0x4]) {
        case 1:
        *(s32*)self += delta;
        break;
        case 2:
        *(s32*)self += delta;
        break;
        case 3:
        *(s32*)self += delta;
        break;
        case 4:
        break;
    }
}

u8 *TLobby__sub_80406F0C(void *self)
{
    u32 w;
    s16 k;
    s16 j;
    u8 *rec;
    u8 *sub;

    switch (((u8 *)self)[4]) {
    case 1:
    case 4:
        return *(u8 **)self;
    case 2:
        w = *(u32 *)self;
        k = (s16)(w >> 24);
        if (*(s16 *)((u8 *)&network_buffer_pool_state) < k) {
            return 0;
        }
        j = (s16)((w >> 16) & 0xff);
        sub = *(u8 **)(((u8 *)&network_buffer_pool_state) + 4) + k * 0x3c;
        rec = sub;
        sub = rec + j * 6;
        return (u8 *)(*(u16 *)(sub + 0xe) + (w & 0xffff) + *(u32 *)rec);
    case 3:
        return *(u8 **)self;
    default:
        return 0;
    }
}

typedef struct Ent_804072C4 { s16 st; u8 pad[0x9c - 2]; } Ent_804072C4;
struct Tbl_804072C4 { s16 count; Ent_804072C4 *list; };
void release_entry(void *self) {
    Ent_804072C4 *e = (Ent_804072C4 *)self;
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

typedef struct Ent_80407310 { s16 st; u8 pad[0x9c - 2]; } Ent_80407310;
struct Tbl_80407310 { s16 count; Ent_80407310 *list; };
u8 *alloc_free_entry(void) {
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

s32 NetUnregisterTimer(void* p);
void TLobby__sub_804078B4(void);
s32 TLobby__sub_80407358(void) {
    Tbl_80408718 *g = &lbl_805C1AB0;
    s32 tmp[2];
    release_slot_by_id(0x806);
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

s32 dispatch_slot_a(s16 arg0, s32 arg1) {
    return TLobby__sub_80407C60(arg0, arg1);
}

s32 dispatch_slot_b(s16 arg0, s32 arg1) {
    return TLobby__sub_80407D98(arg0, arg1);
}

struct Ent_80407418 {
    s16 active;
    s16 a;
    s16 pad4;
    s16 b;
    u8 pad8[0x18];
};

struct Tbl_80407418 {
    s16 pad0;
    s16 count;
    u8 pad4[0x10];
    Ent_80407418 *ents;
};

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
    call_entry_callback(e->a, e->b);
    TLobby__sub_80408388(id);
    return 0;
}

s32 forward_net_op(s16 arg0, u8 *arg1, u8 *arg2) {
    return TLobby__sub_8040799C(arg0, arg1, arg2);
}

void forward_net_op_5args(s16 arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4, s32 arg5, s8 arg6, s32 arg7) {
    s16 TLobby__sub_80407F20(s16, s16, s16, s16, s16, s32, s8, s32);
    TLobby__sub_80407F20(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7);
}

void forward_net_op_5args(s16 arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4, s32 arg5, s8 arg6, s32 arg7);
void init_net_buffer_config(NetBufferCfg *cfg);
#pragma push
#pragma cplusplus off
extern s32 TLobby__sub_80407640(void *pkt, s16 a, s16 b, s16 c);
#pragma pop
#pragma push
#pragma cplusplus off
#pragma dont_inline off
#pragma inline_depth(4)
#pragma dont_inline off
s32 TUdpSocket__sub_80407508(void)
{
    void init_net_buffer_config(void*);
    void TLobby__sub_80407640();
    void TLobby__sub_804078B4();
    void register_protocol_handler();
    void NetRegisterTimer();
    p803FE518_Unk805BDDE0* tbl = (p803FE518_Unk805BDDE0*)(*(u8(*)[])&lbl_805C1AB0);
    s16* step;
    u8* p;
    s16 j;
    u8* p2;
    s16 i;
    u8* q;
    s16 k;
    u8* p4;
    long sum;

    init_net_buffer_config((*(u8(*)[])&lbl_805C1AB0));
    i = tbl->unk0;
    p = (u8*)tbl->unk10;
    for (; i > 0; i--) {
        NetMemset((void*)(p), (int)(0), (int)(0x18));
        (*(s16 *)((u8 *)p + 0)) = 0;
        (*(s32 *)((u8 *)p + 8)) = 0;
        p += 0x18;
    }
    j = tbl->unk2[0].unk0;
    p2 = (u8*)tbl->unk14;
    for (; j > 0; j--) {
        NetMemset((void*)(p2), (int)(0), (int)(0x20));
        p2 += 0x20;
    }
    k = tbl->unk2[0].unk2;
    step = &tbl->unk2[1].unk0;
    q = (u8*)tbl->unk1C;
    sum = tbl->unk20;
    for (; k > 0; k--) {
        NetMemset((void*)(q), (int)(0), (int)(0x10));
        (*(s16 *)((u8 *)q + 8)) = *step;
        (*(s32 *)((u8 *)q + 0xC)) = sum;
        q += 0x10;
        sum += *step;
    }
    j = tbl->unk2[1].unk2;
    p4 = (u8*)tbl->unk18;
    for (; j > 0; j--) {
        NetMemset((void*)(p4), (int)(0), (int)(0xC));
        p4 += 0xC;
    }
    register_protocol_handler(0x806, TLobby__sub_80407640);
    NetRegisterTimer(60000, 1, TLobby__sub_804078B4);
    return 0;
}
#pragma pop

s32 TLobby__sub_804082AC(Ent_804082AC *, Key_804082AC *, void *);
struct Ent_80408428;
#pragma push
#pragma dont_inline off
#pragma inline_depth(4)
inline Hit_80407640 *FindHit_80407640(Tbl_80407640 *t, s16 b, s16 c) {
    Hit_80407640 *hit;
    s16 i;
    s16 n;
    if (b < 0) {
        return NULL;
    }
    hit = t->hits;
    n = t->nhit;
    for (i = 0; i < n; i++, hit++) {
        if (hit->used == 1 && hit->f2 == b && hit->f6 == c) {
            return hit;
        }
    }
    return NULL;
}

inline s16 CheckPkt_80407640(Pkt_80407640 *pkt, Hit_80407640 *hit) {
    if (NetMemcmp(pkt, hit->fA, 6) == 0) {
        if (pkt->f6 == 1 || pkt->f6 == 2) {
            return 1;
        }
    }
    return -1;
}
#pragma pop

#pragma push
#pragma dont_inline off
#pragma inline_depth(4)
inline Peer_80407640 *FindPeer_80407640(Peer_80407640 *peer, s16 n, u8 ff, u8 *p2) {
    for (; n > 0; n--, peer++) {
        if (peer->f5 == ff && peer->used != 0 && NetMemcmp(peer->name, p2, peer->f5) == 0) {
            return peer;
        }
    }
    return 0;
}
#pragma pop
#pragma push
#pragma opt_common_subs on
extern s32 TLobby__sub_80407640(void *pkt, s16 a, s16 b, s16 c)
{
  s32 call_handler_by_index(s16 arg0, s16 arg1, s32 arg2, s32 arg3, s32 arg4);
  s16 TLobby__sub_804082AC(Ent_804082AC *, Key_804082AC *, void *);
  struct Ent_80408428 *find_or_add_peer_entry(s16, s32, u8, void *, u8, void *, s16);
  Tbl_80407640 *t = (Tbl_80407640 *)&lbl_805C1AB0;
  Pkt_80407640 *pp;
  Hit_80407640 *hit;
  Peer_80407640 *peer;
  u8 *p2;
  u8 *pos[5];
  u8 buf[8];
  Out_804081C0 out;
  Pkt_804081C0 *r;
  if (a < 8) {
    return -1;
  }
  if (b < 0) {
    return -1;
  }
  hit = FindHit_80407640(t, b, c);
  if (hit == NULL) {
    return -1;
  }
  pp = (Pkt_80407640 *) pkt;
  if (CheckPkt_80407640(pp, hit) < 0) {
    return -1;
  }
  pos[0] = (u8 *)pp;
  p2 = (u8 *)pp + 8;
  pos[1] = p2;
  p2 += hit->fE;
  pos[2] = p2;
  p2 += hit->fF;
  pos[3] = p2;
  p2 += hit->fE;
  pos[4] = p2;
  peer = FindPeer_80407640(t->peers, t->npeer, hit->fF, pos[2]);
  if (peer != NULL) {
    find_or_add_peer_entry(hit->f2, hit->f4, hit->fF, pos[2], hit->fE, pos[1], 2);
  }
  if (pp->f6 == 1) {
    if (TLobby__sub_804082AC((Ent_804082AC *)hit, (Key_804082AC *)pos, buf) > 0) {
      r = alloc_packet_with_header(&out, (u8 *)hit);
      if (r != NULL) {
        ((Pkt_80407640 *)out.f0)->f6 = 2;
        NetMemcpy(out.f4, buf, hit->fE);
        NetMemcpy(out.fC, pos[1], hit->fE);
        NetMemcpy(out.f8, pos[4], hit->fF);
        NetMemcpy(out.f10, pos[2], hit->fF);
        call_handler_by_index(hit->f2, c, 0, (s32)pos[1], (s32)r);
        if (r != NULL) {
          release_entry((void *)r);
        }
      }
    }
  }
  return 0;
}
#pragma pop
#pragma push
#pragma cplusplus off
#pragma pop
#pragma push
#pragma use_lmw_stmw off
void TLobby__sub_804078B4(void) {
    typedef struct Unk805BDCB0Rec {
        s16 type;
        s16 timer;
        u8 unk4[4];
        p803FE518_U7Slot* slot;
        u8 unkC[6];
        u8 unk12[4];
    } Unk805BDCB0Rec;
    Unk805BDCB0Rec* p;
    s16 n;
    n = *(s16*)(*(u8(*)[])&lbl_805C1AB0);
    p = *(Unk805BDCB0Rec**)((*(u8(*)[])&lbl_805C1AB0) + 0x10);
    for (; n > 0; n--, p++) {
        if (p->type != 0) {
            if (p->timer != 0) {
                p->timer--;
            }
            if (p->timer == 0 && p->type != 4 && p->type != 8) {
                if (p->slot != NULL) {
                    if (p->slot != NULL) {
                        p->slot->obj = NULL;
                        p->slot->size = 0;
                        p->slot->used = 0;
                    }
                    p->slot = NULL;
                }
                p->type = 0;
                p->timer = 0;
                NetMemset((void*)(p->unkC), (int)(0), (int)(6));
                NetMemset((void*)(p->unk12), (int)(0), (int)(4));
            }
        }
    }
}
#pragma pop

typedef struct Conn_8040799C { s32 a; s16 f4; s16 f6; } Conn_8040799C;
struct Peer_8040799C { s16 st; s16 f2; u8 pad4; u8 f5; u8 pad6[2]; Conn_8040799C *conn; u8 addr[6]; u8 name[6]; };
struct Ent_8040799C { s16 f0; s16 f2; s16 f4; s16 f6; u8 pad8[6]; u8 fE; u8 fF; u8 pad10[2]; u8 a12[6]; u8 a18[8]; };
struct Tbl_8040799C { s16 count; s16 h2; s16 h4; s16 h6; s16 h8; s16 hA; s16 hC; u8 padE[2]; Peer_8040799C *list; Ent_8040799C *ents; };
struct Out_8040799C { Conn_8040799C *a; void *b; void *c; void *d; void *e; };
void TLobby__sub_80408060(void *, void *);
struct Ent_80408428;

#define TBL ((Tbl_8040799C *)&lbl_805C1AB0)

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

inline void Clear_8040799C(Peer_8040799C *p) {
    if (p->conn != NULL) {
        p->conn->a = 0;
        p->conn->f6 = 0;
        p->conn->f4 = 0;
    }
}

inline void Send_8040799C(Ent_8040799C *e, void *name) {
    Out_8040799C o;
    void *r = alloc_packet_with_header((Out_804081C0 *)(&o), (u8 *)e);
    if (r != NULL) {
        o.a->f6 = 1;
        NetMemcpy(o.b, e->a12, e->fE);
        NetMemcpy(o.c, e->a18, e->fF);
        NetMemset(o.d, 0, e->fE);
        NetMemcpy(o.e, name, e->fF);
        call_handler_by_index(e->f2, e->f6, 1, 0, (s32)r);
        if (r != NULL) {
            release_entry((void *)r);
        }
    }
}

s32 TLobby__sub_8040799C(s16 idx, void *name, void *arg2) {
    struct Ent_80408428 *find_or_add_peer_entry(s16, s32, u8, void *, u8, void *, s16);
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
            ret = call_handler_by_index(e->f2, e->f4, 0, (s32)p->addr, (s32)arg2);
        } else {
            if (p->conn != NULL) {
                Clear_8040799C(p);
                p->conn = NULL;
            }
            TLobby__sub_80408060(p, arg2);
            Send_8040799C(e, name);
            p->f2 = t->hC;
        }
    } else {
        u8 buf[6];
        NetMemset(buf, 0, 6);
        np = (Peer_8040799C *)find_or_add_peer_entry(e->f2, e->f4, e->fF, name, e->fE, buf, 1);
        TLobby__sub_80408060(np, arg2);
        Send_8040799C(e, name);
        np->f2 = t->hC;
    }
    return ret;
}

typedef struct NetBlockTable_805BDCB0 {
    s16 unk0;
    struct {
        s16 unk0;
        s16 unk2;
    } unk2[2];
    s16 unkA;
    s16 unkC;
    s16 *unk10;
    u32 unk14;
    u32 unk18;
    u32 unk1C;
    u32 unk20;
} NetBlockTable_805BDCB0;
s32 TLobby__sub_80407C60(s16 id, s32 key) {
    NetBlockTable_805BDCB0 *tbl = (NetBlockTable_805BDCB0 *)&lbl_805C1AB0;
    u8 *base = (u8 *)tbl->unk14;
    s16 ok;
    u8 *e;
    u8 *p;
    u8 *prev;
    s16 i;
    u8 pad[8];
    if (id >= 0 && id < tbl->unk2[0].unk0) {
        ok = 1;
    } else {
        ok = -1;
    }
    if (ok >= 0) {
        e = base + id * 0x20;
    } else {
        e = NULL;
    }
    if (e == NULL) {
        return -1;
    }
    if (*(s16 *)e == 0) {
        return -1;
    }
    if (*(u8 **)(e + 0x1c) == NULL) {
        return -1;
    }
    p = *(u8 **)(e + 0x1c);
    i = 0;
    while (*(u32 *)p != 0) {
        i++;
        if (tbl->unk2[1].unk2 <= i) {
            return -1;
        }
        if (NetMemcmp(p + 6, (void *)key, 4) == 0) {
            if (*(u8 **)(e + 0x1c) == p) {
                *(u8 **)(e + 0x1c) = *(u8 **)p;
            } else {
                *(u8 **)prev = *(u8 **)p;
            }
            *(u8 **)p = NULL;
            *(s16 *)(p + 4) = 0;
            return 0;
        }
        prev = p;
        p = *(u8 **)p;
    }
    return -1;
}
#pragma pop

#pragma push
#pragma dont_inline off
#pragma inline_depth(4)
inline s16 valid_80407D98(NetBlockTable_805BDCB0 *tbl, s16 id) {
    if (id >= 0 && id < tbl->unk2[0].unk0) {
        return 1;
    }
    return -1;
}
inline u8 *entry_80407D98(NetBlockTable_805BDCB0 *tbl, s16 id) {
    u8 *base = (u8 *)tbl->unk14;
    if (valid_80407D98(tbl, id) >= 0) {
        return base + id * 0x20;
    }
    return NULL;
}
inline u8 *alloc_80407D98(NetBlockTable_805BDCB0 *tbl) {
    u8 *p = (u8 *)tbl->unk18;
    s16 n;

    for (n = tbl->unk2[1].unk2; n > 0; n--, p += 0xc) {
        if (*(s16 *)(p + 4) == 0) {
            *(s16 *)(p + 4) = 1;
            *(u8 **)p = NULL;
            NetMemset(p + 6, 0, 4);
            return p;
        }
    }
    return NULL;
}
inline u8 *lookup2_80407D98(NetBlockTable_805BDCB0 *t, s16 idx) {
    u8 *list = (u8 *)t->unk14;
    s16 ok;
    if (idx >= 0 && idx < t->unk2[0].unk0) {
        ok = 1;
    } else {
        ok = -1;
    }
    if (ok >= 0) {
        return list + idx * 0x20;
    }
    return NULL;
}
inline u8 *alloc2_80407D98(NetBlockTable_805BDCB0 *t, s16 *count) {
    u8 *p = (u8 *)t->unk18;
    s16 n = *count;
    for (; n > 0; n--, p += 0xc) {
        if (*(s16 *)(p + 4) == 0) {
            *(s16 *)(p + 4) = 1;
            *(u8 **)p = NULL;
            NetMemset(p + 6, 0, 4);
            return p;
        }
    }
    return NULL;
}
static s32 TLobby__sub_80407D98(s16 id, s32 pkey) {
    s16 lim;
    u8 *next;
    u8 *p;
    u8 *e;
    u8 *node;
    s16 *max;
    NetBlockTable_805BDCB0 *t = (NetBlockTable_805BDCB0 *)&lbl_805C1AB0;
    s16 k;

    e = lookup2_80407D98(t, id);
    if (e == NULL) {
        return -1;
    }
    if (*(s16 *)e == 0) {
        return -1;
    }
    node = alloc2_80407D98(t, max = &t->unk2[1].unk2);
    if (node == NULL) {
        return -1;
    }
    NetMemcpy(node + 6, (void *)pkey, 4);
    *(s16 *)(node + 4) = 1;
    *(u8 **)node = NULL;
    if (*(u8 **)(e + 0x1c) == NULL) {
        *(u8 **)(e + 0x1c) = node;
    } else {
        lim = *max;
        p = *(u8 **)(e + 0x1c);
        k = 0;
        while ((next = *(u8 **)p) != NULL) {
            k++;
            if (lim <= k) {
                return -1;
            }
            p = next;
        }
        *(u8 **)p = node;
    }
    return 0;
}
#pragma pop

#pragma push
#pragma dont_inline off
#pragma inline_depth(4)
inline u8 *findfree_80407F20(u8 *base) {
    u8 *p;
    s16 i;
    p = base;
    for (i = 0; i < *(s16 *)((u8 *)&lbl_805C1AB0 + 0x2); i++, p += 0x20) {
        if (*(s16 *)p == 0) {
            return p;
        }
    }
    return NULL;
}
#pragma pop

#pragma push
#pragma dont_inline off
#pragma inline_depth(4)
s16 TLobby__sub_80407F20(s16 a, s16 b, s16 c, s16 d, s16 e, s32 f, s16 g, s32 h)
{
    u8 *base;
    u8 *slot;
    s16 res;
    s16 idx;
    s16 TLobby__sub_8040A044(s16, u32, s16, u32 *);
    s32 call_entry_callback(s16, s16);

    if (a < 0) {
        return -1;
    }
    res = TLobby__sub_8040A044(a, 0x806, g, (u32 *)h);
    if (res < 0) {
        return res;
    }
    base = *(u8 **)((u8 *)&lbl_805C1AB0 + 0x14);
    slot = findfree_80407F20(base);
    if (slot == NULL) {
        call_entry_callback(a, res);
        return -0x10d;
    }
    *(s16 *)slot = 1;
    idx = (s16)((slot - base) / 0x20);
    *(s16 *)(slot + 0x2) = a;
    *(s16 *)(slot + 0x4) = b;
    *(s16 *)(slot + 0x6) = res;
    *(s16 *)(slot + 0x8) = idx;
    *(s16 *)(slot + 0xa) = c;
    *(s16 *)(slot + 0xc) = d;
    *(u8 *)(slot + 0xe) = e;
    *(u8 *)(slot + 0xf) = g;
    *(s16 *)(slot + 0x10) = 0;
    NetMemcpy(slot + 0x12, (void *)f, e);
    NetMemcpy(slot + 0x18, (void *)h, g);
    *(s32 *)(slot + 0x1c) = 0;
    return idx;
}
#pragma pop
extern Tbl_80408718 lbl_805C1AB0;
extern void TLobby__sub_80406FD8(void *, void *, s32);
extern Tbl_80408718 lbl_805C1AB0;
extern void TLobby__sub_80406FD8(void *, void *, s32);
extern Tbl_80408718 lbl_805C1AB0;
extern void TLobby__sub_80406FD8(void *, void *, s32);
extern Tbl_80408718 lbl_805C1AB0;
extern void TLobby__sub_80406FD8(void *, void *, s32);
extern Tbl_80408718 lbl_805C1AB0;
extern void TLobby__sub_80406FD8(void *, void *, s32);
#pragma push
#pragma dont_inline off
extern void TLobby__sub_80408060(void * self_, void * arr_) {
u8 tmp[0x8];
p803FE518_U7Slot *found;
s16 sum = 0;
p803FE518_U7Slot *best = (p803FE518_U7Slot *)((void *) 0);
p803FE518_U7Slot *e = *((p803FE518_U7Slot **) ((*(u8(*)[])&lbl_805C1AB0) + 0x1c));
s16 n = *((s16 *) ((*(u8(*)[])&lbl_805C1AB0) + 0x4));
found = (p803FE518_U7Slot *)((void *) 0);
while (n > 0)
{
if (e->used == 0)
{
found = e;
break;
}
if (best == ((void *) 0))
{
best = e;
}
else
if (e->obj->key < best->obj->key)
{
best = e;
}
e++;
n--;
}
if (found == ((void *) 0))
{
p803FE518_U7Obj *o_m = best->obj;
if (o_m->slot != ((void *) 0))
{
o_m->slot->obj = (p803FE518_U7Obj *)((void *) 0);
o_m->slot->size = 0;
o_m->slot->used = 0;
}
o_m->slot = (p803FE518_U7Slot *)((void *) 0);
found = best;
}
if (found->cap < ((s16) (*((u32 *) (((u8 *)arr_) + 8)))))
{
return;
}
{
u8 *p;
s16 k;
s32 src;
found->used = 1;
k = (s16) (*((u32 *) (((u8 *)arr_) + 4)));
src = found->data;
p = ((u8 *)arr_) + (k * 0xc);
while (k > 0)
{
set_value_and_enable(tmp, src);
TLobby__sub_80406FD8((void *)(tmp), (void *)((((u8 *)arr_) + ((k - 1) * 0xc)) + 0x10), (s32)(*((s16 *) p)));
src += *((s16 *) p);
sum += *((s16 *) p);
p -= 0xc;
k--;
}
}
found->size = sum;
found->obj = ((p803FE518_U7Obj *)self_);
((p803FE518_U7Obj *)self_)->slot = found;
}
#pragma pop

#undef TBL

typedef struct Node_804082AC { struct Node_804082AC *next; u8 pad4[2]; u8 f6[0x10]; } Node_804082AC;
struct Ent_804082AC { u8 pad0[0xE]; u8 fE; u8 fF; u8 pad10[2]; u8 f12[6]; u8 f18[4]; Node_804082AC *f1C; };
struct Key_804082AC { u8 pad0[0x10]; void *f10; };

struct Tbl_80408718;
Pkt_804081C0 *alloc_packet_with_header(Out_804081C0 *arg0, u8 *arg1) {
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
    pkt = (Pkt_804081C0 *)alloc_free_entry();
    if (pkt == NULL) {
        return NULL;
    }
    pkt->f4 = 1;
    pkt->f8 = len;
    buf = (u8 *)&((Pool_804081C0 *)&lbl_805C1AB0)->f24;
    pkt->fC = t;
    set_value_and_enable((void *)(pkt->f10), *(s32 *)buf);
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

s32 TLobby__sub_804082AC(Ent_804082AC *arg0, Key_804082AC *arg1, void *arg2) {
    s16 i;
    Node_804082AC *p;

    if (NetMemcmp(arg0->f18, arg1->f10, arg0->fF) == 0) {
        NetMemcpy(arg2, arg0->f12, arg0->fE);
        return 1;
    }
    if (arg0->f1C != NULL) {
        p = arg0->f1C;
        i = 0;
        while (p != NULL) {
            i++;
            if (lbl_805C1AB0.h8 <= i) {
                return -1;
            }
            if (NetMemcmp(p->f6, arg1->f10, arg0->fF) == 0) {
                NetMemcpy(arg2, arg0->f12, arg0->fE);
                return 1;
            }
            p = p->next;
        }
    }
    return -1;
}

struct Node_80408388 {
    struct Node_80408388 *next;
    s16 used;
};

struct Ent_80408388 {
    u8 pad[0x1C];
    Node_80408388 *head;
};

struct Tbl_80408388 {
    s16 pad0;
    s16 count;
    u8 pad4[0x10];
    Ent_80408388 *ents;
};

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

struct Sub_80408428 {
    s32 f0;
    s16 f4;
    s16 f6;
    u8 pad8[4];
    s32 fC;
};

struct Ent_80408428 {
    s16 state;
    s16 stamp;
    u8 type4;
    u8 type5;
    u8 pad6[2];
    Sub_80408428 *sub;
    u8 addrC[6];
    u8 addr12[6];
};

struct Tbl_80408428 {
    s16 count;
    u8 pad2[8];
    s16 stampA;
    u8 padC[4];
    Ent_80408428 *list;
};

struct Pkt_80408428 {
    u8 pad0[4];
    s32 f4;
    s32 f8;
    s16 fC;
    u8 padE[2];
    u8 f10[4];
};

struct Ent_804086B4;

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

Ent_80408428 *find_or_add_peer_entry(s16 arg0, s32 arg1, u8 type, void *addr, u8 type2, void *addr2, s16 state) {
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
            p = (Pkt_80408428 *)alloc_free_entry();
            if (p != NULL) {
                p->f4 = 1;
                p->f8 = e->sub->f6;
                p->fC = e->sub->f6;
                set_value_and_enable((void *)(p->f10), e->sub->fC);
                call_handler_by_index(arg0, arg1, 0, (s32)e->addrC, (s32)p);
                release_entry((void *)p);
            }
        }
        detach_80408428(e);
        return e;
    }
    if (addr2 == NULL) {
        return NULL;
    }
    e = (Ent_80408428 *)find_free_peer_entry();
    if (e == NULL) {
        e = (Ent_80408428 *)find_oldest_peer_entry(4);
        if (e == NULL) {
            e = (Ent_80408428 *)find_oldest_peer_entry(0);
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
Ent_804086B4 *find_oldest_peer_entry(s16 key) {
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

Ent_80408718 *find_free_peer_entry(void) {
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

void flush_flags_step(void) {
    TLobby__sub_8040878C();
}

s16 run_connect_step(void) {
    return init_net_sockets();
}

typedef struct NetTableEntry_805BDCD8 {
    s16 used;
    s16 id;
    s16 unk4;
    u8 pad6[0xA];
} NetTableEntry_805BDCD8;
typedef struct NetTable_805BDCD8 {
    s16 count;
    s16 unk2;
    s16 unk4;
    s16 unk6;
    u8 pad8[4];
    NetTableEntry_805BDCD8 *entries;
} NetTable_805BDCD8;
s32 TLobby__sub_8040878C(void) {
    NetTable_805BDCD8 *tbl = (0, (void *)&lbl_805C1AD8);
    s16 n;
    s16 i;
    NetTableEntry_805BDCD8 *ent;
    i = 0;
    n = tbl->count;
    ent = tbl->entries;
    for (; i < n; i++, ent++) {
        if (ent->used != 0) {
            clear_table_entry_locked(ent->id);
            ent->used = 0;
            ent->id = 0;
            ent->unk4 = 0;
        }
    }
    tbl->unk2 = 0;
    tbl->unk4 = 0;
    tbl->unk6 = 0;
    TLobby__sub_803F8AB8(tbl);
    return 0;
}

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

typedef struct Fn_80408FD8 { u8 pad0[0xC]; s32 (*f0C)(s16, u8 *); s32 (*f10)(s16, u8 *); u8 pad14[8]; } Fn_80408FD8;
struct Ent_80408FD8 { s16 f0; u8 pad2[2]; s16 f4; u16 f6; u8 pad8[8]; };
struct Tbl_80408FD8 { u8 pad0[4]; s16 count; u8 pad6[2]; Fn_80408FD8 *fns; u8 pad0C[4]; Ent_80408FD8 *ents; };

s32 TLobby__sub_80408F2C(s16 id, u8 *pkt);
s32 TLobby__sub_80409130(s16 arg0, s16 arg1, s32 arg2);
s32 TLobby__sub_80408FD8(s16 idx, s16 mode, u8 *data);
s32 TLobby__sub_8040920C(s16 id, u8 *dst);
s32 TLobby__sub_804092FC(s16 idx);
s32 TLobby__sub_8040939C();
s32 TLobby__sub_804093EC(s16 idx);
s16 TLobby__sub_804094B8(s16 a, u16 b, s16 c, void *k);
s32 TLobby__sub_8040970C(s16 idx, u8 *dst);
struct Tbl_80408F2C;
#define LG_8040881C (*(G_8040881C *)&lbl_805C1AD8)
s16 init_net_sockets(void) {
    Fn_8040881C fns[11];
    s16 r;
    s16 first;
    s16 cnt;
    s16 i;
    Ent_8040881C *e;
    Desc_8040881C *d;
    Ent_8040881C **pe;

    init_net_func_table((NetFuncTableCfg *)((Desc_803F8AD8 *)&LG_8040881C));
    pe = &LG_8040881C.ents;
    NetMemset(*pe, 0, LG_8040881C.n2 * 0x10);
    NetMemset(LG_8040881C.p10, 0, LG_8040881C.n4 * 0x10);
    NetMemset(LG_8040881C.p14, 0, LG_8040881C.n6 * 0x5F8);
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

#pragma push
#pragma dont_inline off
#pragma inline_depth(4)
inline Ent_804089A8 *find_804089A8(Ent_804089A8 *ent, s16 n, s16 x, u16 key) {
    for (; n > 0; n--, ent++) {
        if (ent->used != 0 && ent->f4 == x && ent->f6 == key) {
            return ent;
        }
    }
    return 0;
}
#pragma pop
s32 TLobby__sub_804089A8(s16 x, s16 mode, s16 b, void *pkt) {
    Tbl_804089A8 *tbl = (Tbl_804089A8 *)&lbl_805C1AD8;
    Ent_804089A8 *ent;
    Ent_804089A8 *base;
    Slot_804089A8 *slot;
    s16 n;
    s16 f2;
    s16 idx;
    u16 key;
    u8 buf[14];
    void TLobby__sub_80409818(s32, s16, s16, s16, u16);
    NetMemcpy(buf, pkt, 6);
    NetMemcpy(buf + 6, (u8 *)pkt + 6, 6);
    NetMemcpy(buf + 12, (u8 *)pkt + 0xc, 2);
    if (mode == 0) {
        if (b > 0x5ea) {
            return 0;
        }
        base = tbl->ents;
        ent = find_804089A8(base, tbl->n, x, *(u16 *)(buf + 12));
        if (ent == 0) {
            return 0;
        }
        ent->slot = 0;
        idx = ent - base;
        f2 = ent->f2;
        n = tbl->m;
        slot = tbl->slots;
        for (; n > 0; n--, slot = (Slot_804089A8 *)((u8 *)slot + 0x5f8)) {
            if (slot->used == 0) {
                slot->used = 1;
                slot->x = x;
                slot->idx = idx;
                slot->f2 = f2;
                slot->b = b;
                goto foundslot;
            }
        }
        slot = 0;
    foundslot:
        if (slot == 0) {
            return 0;
        }
        ent->slot = slot;
        return (s32)slot + 0xa;
    }
    if (mode == 1) {
        key = *(u16 *)(buf + 12);
        base = tbl->ents;
        ent = find_804089A8(base, tbl->n, x, key);
        if (ent == 0) {
            return 0;
        }
        slot = (Slot_804089A8 *)ent->slot;
        idx = ent - base;
        if (slot == 0) {
            return 0;
        }
        if (slot->x != x || slot->idx != idx || slot->f2 != ent->f2 || slot->b != b) {
            s32 lvl = OSDisableInterrupts();
            slot->used = 0;
            slot->x = 0;
            slot->idx = 0;
            slot->f2 = 0;
            slot->b = 0;
            OSRestoreInterrupts(lvl);
            return 0;
        } else {
            TLobby__sub_80409818((s32)((u8 *)slot + 0x18), slot->b - 0xe, slot->f2, slot->idx, key);
            return 0;
        }
    }
    return 0;
}

struct If_80408C24 { u8 pad[0x18]; SendFn_80408C24 send; };
struct Conn_80408C24 { s16 used; s16 id; s16 handle; u8 mac[6]; u8 *buf; };
struct Ent_80408C24 { s16 used; s16 id; s16 iface; u16 type; u8 pad[8]; };
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

s16 TLobby__sub_804098B4(void *);
s32 TLobby__sub_80409908(void *, void *);
u8 *TLobby__sub_8042558C(u32 size);
struct Tbl_80408F2C;

#pragma push
#pragma dont_inline off
#pragma inline_depth(4)
inline Conn_80408C24 *find_conn_80408C24(Glob_80408C24 *g, s16 id) {
    Conn_80408C24 *c = g->conns;
    s16 n = g->nconn;
    for (; n > 0; n--, c++) {
        if (c->used != 0 && c->id == id) {
            return c;
        }
    }
    return NULL;
}

s32 send_ethernet_frame(s16 idx, s16 mode, u8 *addr, void *pkt) {
    Glob_80408C24 *g;
    Hdr_80408C24 hdr;
    Conn_80408C24 *c;
    Ent_80408C24 *e;
    s16 len;
    SendFn_80408C24 fn;
    void NetMemset(void *, int, int);
    void NetMemcpy(void *, void *, int);
    g = (Glob_80408C24 *)&lbl_805C1AD8;

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
    len = TLobby__sub_804098B4(pkt);
    if (len > 0x5DC) {
        clear_message_entry((s32)c->buf);
        return -2;
    }
    TLobby__sub_80409908(c->buf + 0xE, pkt);
    if (len + 0xE < 0x3C) {
        len = 0x2E;
    }
    fn = g->ifaces[e->iface].send;
    if (fn != NULL) {
        fn(c->handle, c->buf, len + 0xE);
    } else {
        clear_message_entry((s32)c->buf);
        return -0x111;
    }
    return 0;
}
#pragma pop

struct Ent_80408E98 {
    s16 active;
    u8 pad2[4];
    u16 type;
    s16 sock;
    u8 padA[6];
};

struct Tbl_80408E98 {
    u8 pad0[4];
    s16 count;
    u8 pad6[0xA];
    Ent_80408E98 *ents;
};

#define TBL_80408E98 ((Tbl_80408E98 *)&lbl_805C1AD8)

s32 forward_socket_op_by_handle(s16 id, u8 *a, u8 *b) {
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
            return forward_net_op(sock, a, b);
        }
        return -2;
    default:
        return -2;
    }
}
#undef TBL_80408E98

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

s32 TLobby__sub_80408FD8(s16 idx, s16 mode, u8 *data) {
    Tbl_80408FD8 *tbl = (Tbl_80408FD8 *)&lbl_805C1AD8;
    Ent_80408FD8 *e;
    Fn_80408FD8 *fn;
    u8 buf[6];
    u16 flags;

    if (idx < 0 || idx >= tbl->count) {
        return -0x111;
    }
    e = tbl->ents;
    e += idx;
    if (e->f0 == 0) {
        return -2;
    }
    flags = e->f6;
    if (flags == 0x800 || flags == 0x86dd) {
        fn = tbl->fns;
        fn += e->f4;
        if (fn->f0C == NULL) {
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
            return fn->f0C(e->f4, buf);
        }
        if (mode == 2) {
            return fn->f10(e->f4, buf);
        }
        return -2;
    }
    return -2;
}

typedef struct Ent_804094B8 { s16 used; s16 f2; s16 f4; u16 f6; s16 f8; u8 padA[6]; } Ent_804094B8;

typedef struct Sock_80409130 { s16 f0; u8 pad2[4]; u16 f6; s16 f8; u8 padA[6]; } Sock_80409130;

typedef struct Ent_8040920C { s16 active; s16 key; s16 idx; u8 pad6[0xA]; } Ent_8040920C;

typedef struct Rec_8040920C { u8 pad0[0x14]; s32 f14; u8 pad18[4]; } Rec_8040920C;

struct Tbl_8040920C {
    u8 pad0[2];
    s16 nbufs;
    s16 count;
    Rec_8040920C *recs;
    Ent_8040920C *list;
    Ent_8040920C *ents;
};

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

#pragma push
#pragma dont_inline off
#pragma inline_depth(4)
inline Ent_8040920C *find_8040920C(Tbl_8040920C *t, s16 key) {
    Ent_8040920C *p;
    s16 n;
    p = t->list;
    for (n = t->nbufs; n > 0; n--, p++) {
        if (p->active != 0 && p->key == key) {
            return p;
        }
    }
    return NULL;
}
#pragma pop

#pragma push
#pragma dont_inline off
#pragma inline_depth(4)
s32 TLobby__sub_8040920C(s16 id, u8 *dst) {
    Tbl_8040920C *t = (Tbl_8040920C *)&lbl_805C1AD8;
    Ent_8040920C *p;
    Ent_8040920C *e;
    u8 *r;

    if (id < 0 || id >= t->count) {
        return -0x111;
    }
    e = t->ents;
    e += id;
    if (e->active == 0) {
        return -2;
    }
    p = find_8040920C(t, e->key);
    if (p == NULL) {
        return -2;
    }
    r = (u8 *)t->recs;
    r += e->idx * 0x1c;
    if (*(u32 *)(r + 0x14) != 0) {
        NetMemcpy(dst, (u8 *)p + 6, 6);
    } else {
        return -0x111;
    }
    return 0;
}
#pragma pop
s32 TLobby__sub_804092FC(s16 idx) {
    u8 *tbl = (u8 *)&lbl_805C1AD8;
    u8 *e;
    u8 *p;
    s16 n;
    s16 id;
    if (idx < 0 || idx >= *(s16 *)(tbl + 4)) {
        return -0x111;
    }
    e = *(u8 **)(tbl + 0x10);
    e += idx * 16;
    if (*(s16 *)e == 0) {
        return -2;
    }
    id = *(s16 *)(e + 2);
    p = *(u8 **)(tbl + 0xc);
    for (n = *(s16 *)(tbl + 2); n > 0; n--, p += 0x10) {
        if (*(s16 *)p == 0) {
            continue;
        }
        if (*(s16 *)(p + 2) != id) {
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
    u8 *e;
    if (idx < 0 || idx >= ((s16 *)&lbl_805C1AD8)[2]) {
        return -0x111;
    }
    e = *(u8 **)((u8 *)&lbl_805C1AD8 + 0x10);
    e += idx * 16;
    if (*(s16 *)e == 0) {
        return -2;
    }
    return 0x5dc;
}

#pragma push
#pragma use_lmw_stmw off
#pragma dont_inline on
s32 TLobby__sub_804093EC(s16 idx) {
    u8 *tbl = (u8 *)&lbl_805C1AD8;
    u8 *e;
    u8 *ent;
    void (*cb)(s16, u16);
    s32 v;

    if (idx < 0 || idx >= *(s16 *)(tbl + 4)) {
        return -0x111;
    }
    e = *(u8 **)(tbl + 0x10);
    e += idx << 4;
    if (*(s16 *)e == 0) {
        return -2;
    }
    v = *(s16 *)(e + 8);
    if ((s16)v >= 0) {
        TLobby__sub_80407418((s16)v);
    }
    ent = *(u8 **)(tbl + 8);
    ent += *(s16 *)(e + 4) * 0x1c;
    if ((cb = *(void (**)(s16, u16))(ent + 8)) != NULL) {
        cb(*(s16 *)(e + 4), *(u16 *)(e + 6));
    }
    *(s16 *)e = 0;
    *(s16 *)(e + 2) = 0;
    *(s16 *)(e + 4) = 0;
    *(s16 *)(e + 6) = 0;
    *(s16 *)(e + 8) = 0;
    *(s32 *)(e + 0xc) = 0;
    return 0;
}
#pragma pop

typedef struct Cb_804094B8 { void *f0; s16 (*open)(s16, u16); u8 pad8[0xC]; s16 (*getaddr)(s16, void *); u8 pad18[4]; } Cb_804094B8;
typedef struct G_804094B8 { s16 f0; s16 n1; s16 n2; s16 f6; Cb_804094B8 *cbs; Ent_804094B8 *list1; Ent_804094B8 *list2; } G_804094B8;

#pragma push
#pragma dont_inline off
#pragma inline_depth(4)
inline Ent_804094B8 *find1_804094B8(G_804094B8 *g, s16 a) {
    Ent_804094B8 *p = g->list1;
    s16 n = g->n1;
    for (; n > 0; n--, p++) {
        if (p->used != 0 && p->f2 == a) {
            return p;
        }
    }
    return 0;
}
inline Ent_804094B8 *find2_804094B8(Ent_804094B8 *p, s16 n, s16 f4, u16 b) {
    for (; n > 0; n--, p++) {
        if (p->used != 0 && p->f4 == f4 && p->f6 == b) {
            return p;
        }
    }
    return 0;
}
#pragma pop

#pragma push
#pragma opt_propagation off
extern s16 TLobby__sub_804094B8(s16 a, u16 b, s16 c, void *k)
{
  G_804094B8 *g = (G_804094B8 *) (&lbl_805C1AD8);
  Ent_804094B8 *p1;
  Ent_804094B8 *p3;
  s16 new_var;
  s16 n;
  Ent_804094B8 **pl;
  s16 idx;
  s16 ret;
  s16 err;
  Cb_804094B8 *cb;
  s16 forward_net_op_5args(s16, s16, s16, u16, s16, s32, s16, s32);
  p1 = find1_804094B8(g, a);
  if (p1 == ((void *) 0))
  {
    return -0x111;
  }
  if (((b != 0x800) && (b != 0x86dd)) && (b != 0x806))
  {
    return -2;
  }
  pl = &g->list2;
  n = g->n2;
  p3 = *pl;
  if (find2_804094B8(p3, n, p1->f4, b) != ((void *) 0))
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
  p3->f6 = b;
  p3->f2 = a;
  p3->f4 = p1->f4;
  idx = p3 - (*pl);
  cb = g->cbs;
  cb += p1->f4;
  if (cb->open != ((void *) 0))
  {
    new_var = idx;
    ret = cb->open(p1->f4, b);
    if (ret < 0)
    {
      err = ret;
      goto fail;
    }
    if (cb->getaddr != ((void *) 0))
    {
      err = cb->getaddr(p1->f4, ((u8 *) p1) + 6);
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
      ret = forward_net_op_5args(a, idx, 1, b, 6, (s32) (((u8 *) p1) + 6), c, (s32) k);
      if (ret < 0)
    {
      err = ret;
      goto fail;
    }
      p3->f8 = ret;
      break;

    default:
      p3->f8 = -1;
      break;

  }

  return new_var;
  fail:
  p3->used = 0;

  p3->f6 = 0;
  return err;
}
#pragma pop
#pragma push
#pragma dont_inline off
#pragma inline_depth(4)
inline u8 *find_8040970C(s16 idx) {
    u8 *tbl = (u8 *)&lbl_805C1AD8;
    u8 *p = *(u8 **)(tbl + 0xC);
    s16 n;

    for (n = *(s16 *)(tbl + 2); n > 0; n--, p += 0x10) {
        if (*(s16 *)p != 0 && *(s16 *)(p + 2) == idx) {
            return p;
        }
    }
    return NULL;
}

extern s32 TLobby__sub_8040970C(s16 idx, u8 *dst) {
    struct Ent { u8 pad[0x14]; s16 (*f)(s16, u8 *); u8 rest[4]; };
    u8 *tbl;
    u8 *p;
    u8 buf[6];
    s16 ret;
    s16 (*fn)(s16, u8 *);

    tbl = (u8 *)&lbl_805C1AD8;
    p = find_8040970C(idx);
    if (p == NULL) {
        return -0x111;
    }
    fn = (*(struct Ent **)(tbl + 8))[*(s16 *)(p + 4)].f;
    if (fn != NULL) {
        ret = fn(*(s16 *)(p + 4), buf);
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
    void NetEnqueueProtocolMessage(s32 msg, s16 len, s16 idx, s16 arg3, u16 type);
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
#undef TBL_80409818

#pragma push
#pragma cplusplus off
#pragma dont_inline off
#pragma inline_depth(4)
#pragma dont_inline off
s16 TLobby__sub_804098B4(void *self_)
{
  s16 sum = 0;
  s16 n = (s16) (*((u32 *) (((u8 *) self_) + 0x4)));
  u8 *p = ((u8 *) self_) + (n * 0xc);
  while (n > 0)
  {
    sum += *((s16 *) p);
    p -= 0xc;
    n--;
  }

  if (sum == ((s16) (*((u32 *) (((u8 *) self_) + 0x8)))))
  {
    goto eq;
  }
  if (sum)
  {
    goto done;
  }
  else
  {
    goto done;
  }
  eq:
  sum = (s16) (*((u32 *) (((u8 *) self_) + 0x8)));

  done:
  return sum;

}
#pragma pop

#pragma push
#pragma dont_inline off
#pragma inline_depth(4)
inline s32 calc_80409908(void *self, u8 *arr) {
    u8 tmp[0x10];
    u8 *p;
    s32 acc;
    s16 n;
    s32 sum;
    sum = 0;
    n = (s16)*(s32 *)(arr + 4);
    acc = (s32)self;
    p = arr + n * 12;
    while (n > 0) {
        set_value_and_enable(tmp, acc);
        TLobby__sub_80406FD8(tmp, arr + (n - 1) * 12 + 0x10, *(s16 *)p);
        acc += *(s16 *)p;
        sum += *(s16 *)p;
        p -= 12;
        n--;
    }
    if ((s16)sum != (s16)*(s32 *)(arr + 8)) return sum;
    return (s16)*(s32 *)(arr + 8);
}
#pragma pop

#pragma push
#pragma dont_inline off
#pragma inline_depth(4)
s32 TLobby__sub_80409908(void *self, void *arr_) {
    return calc_80409908(self, arr_);
}
#pragma pop
#define TBL_804099B4 (*(Tbl_804099B4 *)&lobby_handler_table_desc)
s32 clear_table_entry_locked(s16 arg0) {
    s32 ret;
    lock_mutex(network_dispatch_state.lock_handle);
    if (arg0 < 0 || arg0 > TBL_804099B4.count) {
        ret = -0x10F;
    } else {
        Ent_804099B4 *e = TBL_804099B4.ents;
        e += arg0;
        NetMemset(e, 0, 0x30);
        ret = 0;
    }
    unlock_mutex(network_dispatch_state.lock_handle);
    return ret;
}

s16 TLobby__sub_80409A3C(u8 *arg0, s16 arg1) {
    s16 temp_r31;
    lock_mutex((*(RecoveredGlobal_80409A3C_lbl_805C1C50 *)&network_dispatch_state).value);
    temp_r31 = TLobby__sub_8040A2BC(arg0, arg1);
    unlock_mutex((*(RecoveredGlobal_80409A3C_lbl_805C1C50 *)&network_dispatch_state).value);
    return temp_r31;
}

s32 TLobby__sub_80409AA8(void) {
    TLobby__sub_803F8A9C((void *)((void *) (&lobby_handler_table_desc)));
    lobby_handler_table_desc = 0;
    return 0;
}

typedef struct Rec_8040B33C { u32 f0; u8 pad[0x10]; } Rec_8040B33C;
struct A_8040B33C { u8 pad[0x10]; s16 idx; u8 pad2[2]; s16 off; };
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

s32 call_handler_by_index(s16 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    Ent_80409B48 *e;
    s32 (*fn)(s32, s32, s32, s32);
    if (arg0 < 0 || arg0 > TBL_80409B48.count) {
        return -0x10F;
    }
    e = TBL_80409B48.ents;
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
s32 dispatch_handler_by_index(s16 arg0, s32 arg1, s32 arg2, s32 arg3) {
    Ent_80409BD4 *e;
    s32 (*fn)(s32, s32, s32);
    if (arg0 < 0 || arg0 > TBL_80409BD4.count) {
        return -0x10F;
    }
    e = TBL_80409BD4.ents;
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

struct Ent_80409C5C {
    s16 active;
    s16 flags;
    u8 pad[0x20];
    s32 (*fn)(s32, s32);
    u8 pad2[0x8];
};

struct Tbl_80409C5C {
    s16 count;
    Ent_80409C5C *ents;
};

#define TBL_80409C5C (*(Tbl_80409C5C *)&lobby_handler_table_desc)

s32 dispatch_handler_by_id(s16 arg0, s32 arg1, s32 arg2) {
    Ent_80409C5C *e;
    s32 (*fn)(s32, s32);

    if (arg0 < 0 || arg0 > TBL_80409C5C.count) {
        return -0x10F;
    }
    e = TBL_80409C5C.ents;
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

struct Ent_80409CE0 {
    s16 active;
    s16 flags;
    u8 pad[0x1C];
    s32 (*fn)(s32, s32, s32);
    u8 pad2[0xC];
};

struct Tbl_80409CE0 {
    s16 count;
    Ent_80409CE0 *ents;
};

#define TBL_80409CE0 (*(Tbl_80409CE0 *)&lobby_handler_table_desc)

s32 TLobby__sub_80409CE0(s16 arg0, s32 arg1, s32 arg2, s32 arg3) {
    Ent_80409CE0 *e;
    s32 (*fn)(s32, s32, s32);

    if (arg0 < 0 || arg0 > TBL_80409CE0.count) {
        return -0x10F;
    }
    e = TBL_80409CE0.ents;
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

struct Ent_80409D7C {
    s16 active;
    s16 flags;
    u8 pad[0x18];
    s32 (*fn)(s32, s32, s32);
    u8 pad2[0x10];
};

struct Tbl_80409D7C {
    s16 count;
    Ent_80409D7C *ents;
};

#define TBL_80409D7C (*(Tbl_80409D7C *)&lobby_handler_table_desc)

s32 TLobby__sub_80409D7C(s16 arg0, s32 arg1, s32 arg2, s32 arg3) {
    Ent_80409D7C *e;
    s32 (*fn)(s32, s32, s32);

    if (arg0 < 0 || arg0 > TBL_80409D7C.count) {
        return -0x10F;
    }
    e = TBL_80409D7C.ents;
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

struct Ent_80409E18 {
    s16 active;
    s16 flags;
    u8 pad[0x14];
    s32 (*fn)(s32, s32);
    u8 pad2[0x14];
};

struct Tbl_80409E18 {
    s16 count;
    Ent_80409E18 *ents;
};

#define TBL_80409E18 (*(Tbl_80409E18 *)&lobby_handler_table_desc)

s32 TLobby__sub_80409E18(s16 arg0, s32 arg1, s32 arg2) {
    Ent_80409E18 *e;
    s32 (*fn)(s32, s32);

    if (arg0 < 0 || arg0 > TBL_80409E18.count) {
        return -0x10F;
    }
    e = TBL_80409E18.ents;
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

struct Ent_80409EB0 {
    s16 active;
    s16 flags;
    u8 pad[0x10];
    s32 (*fn)(s32);
    u8 pad2[0x18];
};

struct Tbl_80409EB0 {
    s16 count;
    Ent_80409EB0 *ents;
};

#define TBL_80409EB0 (*(Tbl_80409EB0 *)&lobby_handler_table_desc)

s32 TLobby__sub_80409EB0(s16 arg0, s32 arg1) {
    Ent_80409EB0 *e;
    s32 (*fn)(s32);

    if (arg0 < 0 || arg0 > TBL_80409EB0.count) {
        return -0x10F;
    }
    e = TBL_80409EB0.ents;
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

struct Ent_8040A3C0 {
    s16 active;
    u8 pad[0x3A];
};

struct Mgr_8040A3C0 {
    u8 pad[0x40];
    s16 count;
    u8 pad42[2];
    Ent_8040A3C0 *ents;
};

void TLobby__sub_803F86BC(void *);
s32 TLobby__sub_80421844(s32 arg0);

typedef struct Ent_80409FC4 { s16 st; s16 pad2; s32 (*f4)(s32); s32 (*f8)(s32); s32 (*fC)(s32); s32 (*f10)(s32); u8 pad14[0x30-0x14]; } Ent_80409FC4;
struct Tbl_80409FC4 { s16 count; Ent_80409FC4 *list; };
struct Ent_8040A630 { s16 f0; u8 pad[0x3A]; };
struct G_8040A630 { u8 pad[0x40]; s16 n; u8 pad2[2]; Ent_8040A630 *p; };

#pragma push
#pragma opt_propagation off
s32 invoke_socket_callback(s16 i, s32 arg) {
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
s32 call_entry_callback(s16 i, s32 arg) {
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

s32 TLobby__sub_8040A044(s16 idx, u32 a, s32 b, u32 *c) {
    Ent_80409F44 *e;
    if (idx < 0 || idx > (*(Tbl_80409F44 *)&lobby_handler_table_desc).count) {
        return -0x10F;
    }
    e = (*(Tbl_80409F44 *)&lobby_handler_table_desc).list;
    e = (Ent_80409F44 *)((u8 *)e + idx * 0x30);
    if (e->st == 0) {
        return -2;
    }
    if (e->f8 == 0) {
        return -2;
    }
    return ((s32 (*)(s16, u32, s32, u32 *))e->f8)(idx, a, b, c);
}

#pragma push
#pragma cplusplus off
#pragma pop
#pragma push
#pragma cplusplus off
#pragma dont_inline off
#pragma inline_depth(4)
#pragma dont_inline off
s32 TLobby__sub_8040A0C0(s16 idx, void *a)
{
    u8* item;
    void* fn;

    if (idx < 0 || idx > (*(p803FE518_Unk805D3D38*)&lobby_handler_table_desc).unk0) {
        return -0x10f;
    }
    item = (*(p803FE518_Unk805D3D38*)&lobby_handler_table_desc).unk4;
    item += idx * 0x30;
    if (*(s16*)item == 0) {
        return -2;
    }
    fn = *(void**)(item + 0x4);
    if (fn == NULL) {
        return -2;
    }
    return ((s32 (*)(s16, void *))fn)(idx, a);
}
#pragma pop

#pragma push
#pragma optimization_level 2
s32 is_slot_flag_0x40_set(s16 i) {
    Ent_8040A13C *e;
    if (i < 0 || i > (*(G_8040A13C *)&lobby_handler_table_desc).n) { return 0; }
    e = (*(G_8040A13C *)&lobby_handler_table_desc).p;
    if (e[i].f0 == 0) { return 0; }
    if (e[i].f2 & 0x40) { return 1; }
    return 0;
}
#pragma pop

#pragma push
#pragma optimization_level 2
s32 is_slot_flag_0x20_set(s16 i) {
    Ent_8040A19C *e;
    if (i < 0 || i > (*(G_8040A19C *)&lobby_handler_table_desc).n) { return 0; }
    e = (*(G_8040A19C *)&lobby_handler_table_desc).p;
    if (*(s16 *)((u8 *)e + i * 0x30) == 0) { return 0; }
    e = (Ent_8040A19C *)((u8 *)e + i * 0x30);
    if (e->f2 & 0x20) { return 1; }
    return 0;
}
#pragma pop

typedef struct Ent_8040A1FC { s16 f0; s16 f2; u8 pad[0x2C]; } Ent_8040A1FC;
struct G_8040A1FC { s16 n; Ent_8040A1FC *p; };
#pragma push
#pragma optimization_level 2
#pragma dont_inline on
s32 is_entry_flag10_set(s16 i) {
    Ent_8040A1FC *e;
    if (i < 0 || i > (*(G_8040A1FC *)&lobby_handler_table_desc).n) { return 0; }
    e = (*(G_8040A1FC *)&lobby_handler_table_desc).p;
    if (e[i].f0 == 0) { return 0; }
    if (e[i].f2 & 0x10) { return 1; }
    return 0;
}
#pragma pop

typedef struct Ent_8040A25C { s16 f0; s16 f2; u8 pad[0x2C]; } Ent_8040A25C;
struct G_8040A25C { s16 n; Ent_8040A25C *p; };
#pragma push
#pragma optimization_level 2
#pragma dont_inline on
s32 is_socket_flag_set(s16 i) {
    Ent_8040A25C *e;
    if (i < 0 || i > (*(G_8040A25C *)&lobby_handler_table_desc).n) { return 0; }
    e = (*(G_8040A25C *)&lobby_handler_table_desc).p;
    if (e[i].f0 == 0) { return 0; }
    if (e[i].f2 & 1) { return 1; }
    return 0;
}
#pragma pop

extern s16 TLobby__sub_8040A2BC(void *obj, s16 type) {
    if (obj == NULL || *(u32 *)((u8 *)obj + 0x4) == 0) {
        return -2;
    }
    switch (type) {
    case 1: {
        u8 *slot = *(u8 **)((u8 *)&lobby_handler_table_desc + 0x4);
        if (*(s16 *)slot == 0) {
            NetMemcpy(slot + 0x4, obj, 0x2c);
            *(s16 *)(slot + 0x2) = type;
            *(s16 *)slot = 1;
            return 0;
        }
        return -2;
    }
    default: {
        u8 *slot = *(u8 **)((u8 *)&lobby_handler_table_desc + 0x4) + 0x30;
        s16 i;
        for (i = 1; i < lobby_handler_table_desc; i++, slot += 0x30) {
            if (*(s16 *)slot == 0) {
                NetMemcpy(slot + 0x4, obj, 0x2c);
                *(s16 *)(slot + 0x2) = type;
                *(s16 *)slot = 1;
                return i;
            }
        }
        return -0x10f;
    }
    }
}

s32 TLobby__sub_8040A3C0(void) {
    s32 ret;
    s16 i;
    Mgr_8040A3C0 *m = (Mgr_8040A3C0 *)&dns_resolver_state;
    Ent_8040A3C0 *e;

    ret = TLobby__sub_80421844((s32)((void *)tick_connection_timeouts));
    e = m->ents;
    i = 0;
    while (i < m->count) {
        if (e->active != 0) {
            close_and_reset_connection((void *)e);
        }
        i++;
        e++;
    }
    TLobby__sub_803F86BC(m);
    return ret;
}

s16 TLobby__sub_804218AC(void (*)(void), int);

s16 init_net_tables(void) {
    G_8040A45C *g = &dns_resolver_state;
    s16 i;

    NetMemset(&g->h0, 0, sizeof(G_8040A45C));
    init_net_config((NetConfig *)(&g->h0));
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
    return TLobby__sub_804218AC(tick_connection_timeouts, 1000);
}

#pragma push
#pragma opt_propagation off
s32 close_connection_by_index(s16 i) {
    G_8040A630 *g = (G_8040A630 *)&dns_resolver_state;
    Ent_8040A630 *e;
    if (i < 0 || i > g->n) { return -2; }
    e = (Ent_8040A630 *)((u8 *)g->p + i * 0x3C);
    if (e->f0 == 0) { return -2; }
    return close_and_reset_connection((void *)e);
}
#pragma pop

extern void NetStoreCurrentThread(s32 *arg0);
extern void NetSuspendCurrentThread(void);
extern void TLobby__sub_8040C74C(void *p);
extern void NetStoreCurrentThread(s32 *arg0);
extern void NetSuspendCurrentThread(void);
extern void TLobby__sub_8040C74C(void *p);
typedef struct Req_8040A698 {
    u8 pad0[4];
    void *f4;
    s16 f8;
    u8 padA[2];
    void *fC;
    s16 f10;
    u8 pad12[2];
    u32 f14;
} Req_8040A698;
typedef struct Ent_8040A698 {
    s16 f0;
    u8 pad2[6];
    s16 f8;
    u8 padA[2];
    u32 fC;
    s16 f10;
    s16 f12;
    u8 pad14[0xC];
    Req_8040A698 req;
} Ent_8040A698;
#pragma push
#pragma opt_propagation off
extern s16 TLobby__sub_8040A698(s16 idx, void *buf, s16 *len, void *buf2, s16 *len2, u32 mode) {
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
            dispatch_request_callback((void *)e, 1);
        }
        return -1;
    }
    TLobby__sub_8040C74C((void *)req);
    if (len2 != NULL) {
        *len2 = req->f10;
    }
    *len = req->f8;
    return 0;
}
#pragma pop

s32 NetMemcmp(void* left, void* right, int size);
#pragma push
#pragma cplusplus off
s16 TUdpSocket__sub_80421DEC(s16 a, void* b, void* c, u16 d, void* e, void* f);
s32 TLobby__sub_8040B4BC(s16 mode, u8 *req);
u8* TLobby__sub_8040C09C(void);
#pragma pop
#pragma push
#pragma cplusplus off
#pragma dont_inline off
#pragma inline_depth(4)
#pragma dont_inline off
#pragma push
#pragma dont_inline off
#pragma inline_depth(4)
static inline u8 *find_host_8040A8B0(p803FE518_Unk805BDCF0 *base, u8 *self, s32 len) {
    u8 *p = (u8 *)base->unk38;
    s16 j;
    for (j = 0; j < base->unk2e; j++, p += 0x20c) {
        if ((*(s16 *)((u8 *)p + 0)) == 1 && NetMemcmp(p + 2, self, len) == 0) {
            return p;
        }
    }
    return NULL;
}
static inline u8 *grab_slot_8040A8B0(p803FE518_Unk805BDCF0 *base) {
    u8 *p = base->unk28;
    s16 i;
    for (i = 0; i < base->unk24; i++, p += 8) {
        if ((*(s16 *)((u8 *)p + 0)) == 0) {
            (*(s16 *)((u8 *)p + 0)) = 1;
            return p;
        }
    }
    return NULL;
}
typedef struct DnsReq_8040A8B0 {
    u8 pad0[0x10];
    s16 tries;
    s16 pad12;
    s16 start;
} DnsReq_8040A8B0;
static inline u8 *probe_8040A8B0(p803FE518_Unk805BDCF0 *b, DnsReq_8040A8B0 *e) {
    s16 i;
    u8 *ent;
    s16 n;
    for (i = 0; i < (n = b->unk10); i++) {
        ent = b->unk14 + ((e->start + e->tries) % n) * 0x14;
        if ((*(u32 *)((u8 *)ent + 0)) != 0) {
            if (e->tries < b->unk1a) {
                return ent;
            }
            break;
        }
        e->tries = e->tries + 1;
    }
    return NULL;
}
#pragma pop
#pragma push
#pragma opt_common_subs on
#pragma opt_propagation off
#pragma opt_common_subs off
s32 TLobby__sub_8040A8B0(u8 *self, s16 idx, s32 type)
{
  s16 TUdpSocket__sub_80421BAC(s16, void *, void *, u16, void *, s32, s16 *);
  s32 TLobby__sub_8040B4BC(s16, u8 *);
  void build_dns_query_aaaa(u8 *, u8 *, s16);
  void build_dns_query_a(u8 *, u8 *, s16);
  void NetMemcpy(void *, const void *, u32);
  s32 NetMemcmp(const void *, const void *, u32);
  void TLobby__sub_80421814(void);
  s32 close_and_reset_connection(void *);
  p803FE518_Unk805BDCF0 *base = (p803FE518_Unk805BDCF0 *) (*((u8 (*)[]) (&dns_resolver_state)));
  u8 *t;
  u32 ty;
  u8 *p;
  u8 *e;
  s16 i;
  s16 j;
  if (self == ((void *) 0))
  {
    return -2;
  }
  if ((idx <= 0) || (idx > (*((s16 *) (((u8 *) base) + 0x4)))))
  {
    return -2;
  }
  switch (type)
  {
    case 0:

    case 4:

    case 6:
      break;

    default:
      return -2;

  }

  if (((s32) self[idx - 1]) == '.')
  {
    idx--;
  }
  TLobby__sub_80421814();
  e = base->unk44;
  for (i = 0; i < base->unk40; i++, e += 0x3c)
  {
    if ((*((s16 *) (((u8 *) e) + 0))) == 0)
    {
      *((s16 *) (((u8 *) e) + 0)) = 1;
      break;
    }
  }

  TLobby__sub_804217E4();
  if (i == base->unk40)
  {
    e = (void *) 0;
  }
  if (e == ((void *) 0))
  {
    return -0x40;
  }
  *((s16 *) (((u8 *) e) + 0x8)) = 1;
  {
    long long len = idx;
    *((s32 *) (((u8 *) e) + 0x20)) = type;
    t = e + 0x20;
    p = find_host_8040A8B0(base, self, len);
    if (p != ((void *) 0))
    {
      *((s16 *) (((u8 *) e) + 0x10)) = 0;
      *((u8 **) (((u8 *) t) + 0x18)) = p;
      ty = *((s32 *) (((u8 *) t) + 0));
      if (ty == 0)
      {
        if ((*((s16 *) (((u8 *) p) + 0x204))) > 0)
        {
          return *((s16 *) (((u8 *) e) + 0x2));
        }
      }
      else
      {
        u8 *node;
        for (node = *((u8 **) (((u8 *) p) + 0x208)); node != ((void *) 0); node = *((u8 **) (((u8 *) node) + 0x20)))
        {
          if ((*((u32 *) (((u8 *) node) + 0x4))) == ty)
          {
            return *((s16 *) (((u8 *) e) + 0x2));
          }
        }

      }
    }
    p = grab_slot_8040A8B0(base);
    *((u8 **) (((u8 *) e) + 0x18)) = p;
    if (p == ((void *) 0))
    {
      close_and_reset_connection(e);
      return -0x43;
    }
    *((s16 *) (((u8 *) e) + 0x6)) = (*((s16 *) (((u8 *) base) + 0x0)))++;
    *((s16 *) (((u8 *) e) + 0xa)) = base->unkC[0];
    *((s16 *) (((u8 *) e) + 0x14)) = base->unk18;
    *((s16 *) (((u8 *) e) + 0x10)) = 0;
    base = (p803FE518_Unk805BDCF0 *) probe_8040A8B0(base, (DnsReq_8040A8B0 *) e);
    if (base == ((void *) 0))
    {
      close_and_reset_connection(e);
      return -0x44;
    }
    *((s16 *) (((u8 *) e) + 0x4)) = TUdpSocket__sub_80421DEC(0, 0, 0, 0x35, complete_pending_request, TLobby__sub_8040B4BC);
    i = *((s16 *) (((u8 *) e) + 0x4));
    if (i < 0)
    {
      close_and_reset_connection(e);
      return i;
    }
    if ((*((u8 **) (((u8 *) t) + 0x18))) == ((void *) 0))
    {
      p = TLobby__sub_8040C09C();
      *((s16 *) (((u8 *) p) + 0x102)) = idx;
      NetMemcpy(p + 2, self, len);
      *((u8 **) (((u8 *) t) + 0x18)) = p;
    }
    switch (*((s32 *) (((u8 *) t) + 0)))
    {
      case 0:
      {
        struct 
        {
          s16 a;
          s16 pad;
          u32 b;
        } buf;
        build_dns_query_aaaa(e, self, idx);
        buf.a = *((s16 *) (((u8 *) (*((u8 **) (((u8 *) e) + 0x18)))) + 0x2));
        buf.b = *((u32 *) (((u8 *) (*((u8 **) (((u8 *) e) + 0x18)))) + 0x4));
        i = TUdpSocket__sub_80421BAC(*((s16 *) (((u8 *) e) + 0x4)), (void *) 0, base, 0, (void *) 0, 1, (s16 *) (&buf));
        if (i < 0)
        {
          *((s16 *) (((u8 *) e) + 0xa)) = 1;
          *((s16 *) (((u8 *) e) + 0x10)) = (*((s16 *) (((u8 *) e) + 0x10))) + 1;
        }
        else
        {
          *((s16 *) (((u8 *) e) + 0xa)) = 2;
          *((s16 *) (((u8 *) e) + 0x12)) = 1;
        }
        break;
      }

      case 4:
      {
        struct 
        {
          s16 a;
          s16 pad;
          u32 b;
        } buf;
        build_dns_query_a(e, self, idx);
        buf.a = *((s16 *) (((u8 *) (*((u8 **) (((u8 *) e) + 0x18)))) + 0x2));
        buf.b = *((u32 *) (((u8 *) (*((u8 **) (((u8 *) e) + 0x18)))) + 0x4));
        i = TUdpSocket__sub_80421BAC(*((s16 *) (((u8 *) e) + 0x4)), (void *) 0, base, 0, (void *) 0, 1, (s16 *) (&buf));
        if (i < 0)
        {
          *((s16 *) (((u8 *) e) + 0xa)) = 1;
          *((s16 *) (((u8 *) e) + 0x10)) = (*((s16 *) (((u8 *) e) + 0x10))) + 1;
        }
        break;
      }

      case 6:
      {
        struct 
        {
          s16 a;
          s16 pad;
          u32 b;
        } buf;
        build_dns_query_aaaa(e, self, idx);
        buf.a = *((s16 *) (((u8 *) (*((u8 **) (((u8 *) e) + 0x18)))) + 0x2));
        buf.b = *((u32 *) (((u8 *) (*((u8 **) (((u8 *) e) + 0x18)))) + 0x4));
        i = TUdpSocket__sub_80421BAC(*((s16 *) (((u8 *) e) + 0x4)), (void *) 0, base, 0, (void *) 0, 1, (s16 *) (&buf));
        if (i < 0)
        {
          *((s16 *) (((u8 *) e) + 0xa)) = 1;
          *((s16 *) (((u8 *) e) + 0x10)) = (*((s16 *) (((u8 *) e) + 0x10))) + 1;
        }
        break;
      }

    }

    {
      u32 pad[4];
    }
  }
  return *((s16 *) (((u8 *) e) + 0x2));
}
#pragma pop
#pragma pop

struct Rec_8040AD64 {
    u32 used;
    u8 pad[0x10];
};

struct Mgr_8040AD64 {
    u8 pad[0x10];
    s16 n;
    u8 pad12[2];
    Rec_8040AD64 *recs;
    s16 f18;
};

s32 clear_all_used_records(void) {
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
#pragma inline_depth(4)
inline s32 cmpfam_8040ADE8(u32 family, u8 *a, u8 *b) {
    switch (family) {
    case 4:
        if (*(u32 *)b != 4) {
            return -1;
        }
        return NetMemcmp(a + 4, b + 4, 4);
    case 6:
        if (*(u32 *)b != 6) {
            return -1;
        }
        return NetMemcmp(a + 4, b + 4, 0x10);
    default:
    case 0:
        return -1;
    }
}
extern s16 TLobby__sub_8040ADE8(u8 *self) {
    u8 *g;
    s16 ret;
    s16 i;
    u8 *p;
    u8 *slot;
    u32 family;

    switch (*(u32 *)self) {
    case 4:
    case 6:
        break;
    default:
    case 0:
        return -2;
    }
    TLobby__sub_80421814();
    g = (u8 *)&dns_resolver_state;
    p = *(u8 **)(g + 0x14);
    slot = NULL;
    for (i = 0; i < *(s16 *)(g + 0x10); i++, p += 0x14) {
        if (*(u32 *)p == 0) {
            if (slot == NULL) {
                ret = i;
                slot = p;
            }
            continue;
        }
        family = *(u32 *)self;
        if (family != *(u32 *)p) {
            continue;
        }
        if (cmpfam_8040ADE8(family, self, p) == 0) {
            ret = -2;
            slot = NULL;
            break;
        }
    }
    if (slot != NULL) {
        NetMemcpy(slot, self, 0x14);
    } else {
        ret = -2;
    }
    TLobby__sub_804217E4();
    return ret;
}
#pragma pop

struct Conn_8040AF48 {
    s16 state;
    u8 pad[0x16];
    s32 timer;
    u8 pad1C[0x100];
};

struct Mgr_8040AF48 {
    u8 pad[0x30];
    s16 nconns;
    u8 pad32[0xA];
    Conn_8040AF48 *conns;
};

struct Node_8040B3B4 {
    s16 f0;
    u8 pad2[0x1A];
    s32 refs;
    Node_8040B3B4 *next;
};

struct Ent_8040B3B4 {
    s16 state;
    u8 pad2[0x202];
    s16 n;
    Node_8040B3B4 *list;
    u8 pad20C[0x0];
};

struct Base_8040B3B4 {
    u8 pad[0x2E];
    s16 nents;
    u8 pad30[0x8];
    Ent_8040B3B4 *ents;
};

extern void TLobby__sub_8040C178(u8 *self, s32 x);
void TLobby__sub_8040AFE0(void);
void TLobby__sub_8040B3B4(void);

void tick_connection_timeouts(void) {
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
                reset_connection_requests(c, 0);
            }
        }
        i++;
        c++;
    }
    TLobby__sub_8040AFE0();
}

extern void TLobby__sub_8040AFE0(void)
{
    s16 TUdpSocket__sub_80421BAC(s16, s32, s32, s32, s32, s32, void *);
    DnsBase_804050DC *base = (DnsBase_804050DC *)&dns_resolver_state;
    s32 found;
    s16 *dp;
    s16 cnt;
    DnsRec_804050DC *e;
    s16 buf[8];
    struct { s16 a; s16 pad; u32 c; } tmp;
    s16 val;
    s16 ret;
    s32 f2;
    s32 f3;

    dp = &base->div;
    for (cnt = 0, e = base->ents; cnt < base->lim; cnt++, e++) {
        if (e->state != 1) continue;
        if (e->f4 < 0) continue;
        if (!(e->f10 > 0 || e->f12 > 0)) continue;
        if (--e->fA > 0) continue;
        if (e->f10 >= base->f1A) {
            base->f18 = 0;
            TLobby__sub_8040BE40((u8 *)e, -0x45, 0);
            continue;
        }
        if (e->f12 != 0) {
            found = (s32)find_next_active_record((A_8040B33C *)e);
            if (found == 0) {
                TLobby__sub_8040BE40((u8 *)e, -0x44, 0);
                continue;
            }
            base->f18 = e->f10 % *dp;
            e->fA = base->tbl[e->f10 / *dp];
            buf[0] = 1;
            NetMemcpy((u8 *)e->hdr->h4 + e->hdr->h2 - 4, &buf[0], 2);
            f2 = found;
            tmp.a = e->hdr->h2;
            tmp.c = e->hdr->h4;
            ret = TUdpSocket__sub_80421BAC(e->f4, 0, f2, 0, 0, 1, &tmp);
            val = 0x1c;
            NetMemcpy((u8 *)e->hdr->h4 + e->hdr->h2 - 4, &val, 2);
            if (ret < 0) {
                e->fA = 1;
            }
            e->f12 = 0;
            e->f10 = e->f10 + 1;
        } else {
            TLobby__sub_8040B1C4(e);
        }
    }
}

#pragma push
#pragma dont_inline off
#pragma inline_depth(4)
inline Rec_8040B33C *fnar_8040B1C4(G_8040A45C *g, A_8040B33C *a) {
    s16 t, n, i;
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
#pragma pop

extern void TLobby__sub_8040B1C4(void *arg)
{
    s16 TUdpSocket__sub_80421BAC(s16, s32, s32, s32, s32, s32, void *);
    DnsRec_804050DC *e = (DnsRec_804050DC *)arg;
    DnsBase_804050DC *base;
    Rec_8040B33C *found;
    u8 y[4];
    struct { s16 a; s16 pad; u32 c; } tmp;
    u8 x[4];
    s16 ret;
    s16 *dp;

    base = (DnsBase_804050DC *)&dns_resolver_state;
    if ((found = fnar_8040B1C4((G_8040A45C *)base, (A_8040B33C *)e)) == NULL) {
        TLobby__sub_8040BE40((u8 *)e, -0x44, 0);
        return;
    }
    dp = &base->div;
    base->f18 = e->f10 % *dp;
    e->fA = base->tbl[e->f10 / *dp];
    tmp.a = e->hdr->h2;
    tmp.c = e->hdr->h4;
    ret = TUdpSocket__sub_80421BAC(e->f4, 0, (s32)found, 0, 0, 1, &tmp);
    if (ret < 0) {
        e->fA = 1;
        e->f10 = e->f10 + 1;
        return;
    }
    if (*(s16 *)((u8 *)e + 8) == 1 && *(u32 *)((u8 *)e + 0x20) == 0) {
        e->fA = 2;
        e->f12 = 1;
        return;
    }
    e->f10 = e->f10 + 1;
}

Rec_8040B33C *find_next_active_record(A_8040B33C *a) {
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

extern void TLobby__sub_8040B3B4(void) {
    s16 i;
    s16 n;
    s16 count;
    Node_8040B3B4 *prev;
    Node_8040B3B4 *removed;
    Node_8040B3B4 *node;
    Base_8040B3B4 *base;
    Ent_8040B3B4 *e;

    base = (Base_8040B3B4 *)&dns_resolver_state;
    e = base->ents;
    i = 0;
    while (i < base->nents) {
        if (e->state == 1 && (n = e->n) != 0) {
            prev = NULL;
            node = e->list;
            count = 0;
            while (count < n && node != NULL) {
                if (--node->refs > 0) {
                    prev = node;
                    node = node->next;
                } else {
                    removed = node;
                    node = node->next;
                    if (prev != NULL) {
                        prev->next = node;
                    } else {
                        e->list = node;
                    }
                    e->n--;
                    removed->f0 = 0;
                    removed->next = NULL;
                }
                count++;
            }
            if (e->n <= 0) {
                TLobby__sub_8040C178((u8 *)e, 0);
            }
        }
        i++;
        e = (Ent_8040B3B4 *)((u8 *)e + 0x20C);
    }
}

extern s32 TLobby__sub_8040B8BC(u8 *self);
extern s32 TLobby__sub_8040B8BC(u8 *self);
extern s32 TLobby__sub_8040B8BC(u8 *self);
#pragma push
#pragma dont_inline off
#pragma inline_depth(4)
inline u8 *find_8040B4BC(u8 *base, u8 *req) {
    s16 count;
    s16 key;
    s16 i;
    u8 *e;
    i = 0;
    key = *(s16 *)req;
    e = *(u8 **)(base + 0x44);
    count = *(s16 *)(base + 0x40);
    while (i < count) {
        if (*(s16 *)e == 1 && key == *(s16 *)(e + 4)) {
            return e;
        }
        i++;
        e += 0x3c;
    }
    return NULL;
}
inline u8 *slot_8040B4BC(u8 *base) {
    s16 i;
    s16 count;
    u8 *s;
    i = 0;
    s = *(u8 **)(base + 0x28);
    count = *(s16 *)(base + 0x24);
    for (; i < count; i++, s += 8) {
        if (*(s16 *)s == 0) {
            *(s16 *)s = 1;
            return s;
        }
    }
    return NULL;
}
#pragma pop

#pragma push
#pragma dont_inline off
#pragma inline_depth(4)
s32 TLobby__sub_8040B4BC(s16 mode, u8 *req)
{
  u8 *base = (u8 *) (&dns_resolver_state);
  u8 *e;
  s16 new_var;
  u8 *s;
  s32 pad[2];
  s16 TLobby__sub_8040B8BC(u8 *);
  if ((*((u16 *) (req + 0x30))) != 0x35)
  {
    return 1;
  }
  e = find_8040B4BC(base, req);
  if (e == ((void *) 0))
  {
    return 1;
  }
  if ((*((s16 *) (e + 0x10))) < 0)
  {
    return 1;
  }
  new_var = *((s16 *) (req + 2));
  if (new_var > (*((s16 *) (base + 0x1c))))
  {
    return 1;
  }
  switch (mode)
  {
    case 0:
      s = slot_8040B4BC(base);
      *((u8 **) (e + 0x1c)) = s;
      if (s == ((void *) 0))
    {
      return 1;
    }
      *((u32 *) (req + 4)) = *((u32 *) ((*((u8 **) (e + 0x1c))) + 4));
      return 0;

  }

  *((s16 *) ((*((u8 **) (e + 0x1c))) + 2)) = new_var;
  if (TLobby__sub_8040B8BC(e) < 0)
  {
    *((s16 *) (*((u8 **) (e + 0x1c)))) = 0;
    *((u8 **) (e + 0x1c)) = (void *) 0;
    return 1;
  }
  *((s16 *) (*((u8 **) (e + 0x1c)))) = 0;
  *((u8 **) (e + 0x1c)) = (void *) 0;
  if ((*((s16 *) (e + 0x12))) == 0)
  {
    *((s16 *) (e + 0x10)) = 0;
    dispatch_request_callback((void *) e, 0);
  }
  return 0;
}
#pragma pop
struct Ent_8040B654 {
    s16 state;
    u8 pad2[2];
    s16 id;
    u8 pad6[4];
    s16 fA;
    u8 padC[4];
    s16 f10;
    u8 pad12[0x2A];
};

struct Mgr_8040B654 {
    u8 pad[0x40];
    s16 count;
    u8 pad42[2];
    Ent_8040B654 *ents;
};

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

void complete_pending_request(s16 id) {
    Ent_8040B654 *e;

    if ((e = find_8040B654(id)) != NULL) {
        e->fA = 1;
        if (e->f10 < 0) {
            dispatch_request_callback((void *)e, 0);
        }
    }
}
#pragma pop

#pragma push
#pragma opt_propagation off
s32 build_dns_query_aaaa(void *self, u8 *name, s16 len) {
    s32 TLobby__sub_8040B838(u8 *dst, u8 *src, s16 len);
    Q_8040B6E4 *q = (Q_8040B6E4 *)self;
    Hdr_8040B6E4 *h;
    u8 *body;
    s32 n;
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
    body += (s16)n;
    qt.cls = 1;
    total = n + 0xC;
    NetMemcpy(body, &qt, 4);
    q->pkt->len = total + 4;
    return 0;
}
#pragma pop

#pragma push
#pragma opt_propagation off
s32 build_dns_query_a(void *self, u8 *name, s16 len) {
    s32 TLobby__sub_8040B838(u8 *dst, u8 *src, s16 len);
    Q_8040B790 *q = (Q_8040B790 *)self;
    Hdr_8040B790 *h;
    u8 *body;
    s32 n;
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
    body += (s16)n;
    qt.cls = 1;
    total = n + 0xC;
    NetMemcpy(body, &qt, 4);
    q->pkt->len = total + 4;
    return 0;
}
#pragma pop

s32 TLobby__sub_8040B838(u8 *dst, u8 *src, s32 max)
{
    s8 c;
    s16 i;
    u8 n;
    u8 *len;
    s32 ret;
    len = dst;
    n = 0;
    i = 0;
    dst++;
    while (i < (s16)max) {
        c = *src;
        if (c == '.') {
            *len = n;
            len = dst;
            n = 0;
        } else {
            *dst = c;
            n++;
        }
        i++;
        dst++;
        src++;
    }
    if (n != 0) {
        *len = n;
        *dst = 0;
        ret = max + 2;
    } else {
        dst[-1] = 0;
        ret = max + 1;
    }
    return ret;
}

typedef struct Rec_8040BA38 { s32 pad0; u32 size; u8 data[0x10]; s16 type; u8 pad2e[0xe]; } Rec_8040BA38;
struct Hdr_8040BA38 { u16 kind; u16 sub; s32 x; u16 len; };
struct O_8040C4B0;
struct N_8040C4B0;
extern u8 *TLobby__sub_8040C248(u8 *self);
extern s32 TLobby__sub_8040C9E0(u8 *arg0, u8 *arg1);
extern void TLobby__sub_8040BE40(u8 *self, s16 a, s16 b);
extern s32 TLobby__sub_8040BD40(u8 *self, u8 *p, s32 n, u8 *dst);
extern s32 TLobby__sub_8040BA38(u8 *self, u8 *p, s32 n);
extern void TLobby__sub_8040BE40(u8 *self, s16 a, s16 b);
extern s32 TLobby__sub_8040BD40(u8 *self, u8 *p, s32 n, u8 *dst);
extern s32 TLobby__sub_8040BA38(u8 *self, u8 *p, s32 n);
#pragma push
#pragma opt_propagation off
s32 TLobby__sub_8040B8BC(u8 *self)
{
  volatile u32 pad[2];
  s32 len;
  u8 *s;
  u8 *p;
  u8 *hdr;
  u8 *new_var;
  u16 cnt;
  s16 n;
  u16 t;
  u8 *cur;
  s32 op;
  s32 r;
  s = self;
  p = *((u8 **) (s + 0x1c));
  hdr = *((u8 **) (p + 4));
  len = *((s16 *) (p + 2));
  if ((*((u16 *) hdr)) != (*((u16 *) (s + 6))))
  {
    return -1;
  }
  if (!(hdr[2] & 0x80))
  {
    return -1;
  }
  op = hdr[3] & 0xF;
  switch (op)
  {
    case 1:
      TLobby__sub_8040BE40(s, -0x46, 0);
      return -1;

    case 3:
      TLobby__sub_8040BE40(s, -0x47, 0);
      return -1;

    case 2:

    case 4:

    case 5:

    default:
      *((s16 *) (s + 0xa)) = 1;
      return -1;

    case 0:
      if ((*((u16 *) (hdr + 6))) == 0)
    {
      *((s16 *) (s + 0xa)) = 1;
      return -1;
    }
      break;

  }

  cur = hdr + 0xc;
  len -= 0xc;
  t = *((u16 *) (hdr + 4));
  if (t != 0)
  {
    n = t;
    while (n > 0)
    {
      new_var = cur;
      r = TLobby__sub_8040BD40(s, new_var, len, 0) + 4;
      len -= r;
      cur += (s16) r;
      n--;
    }

  }
  cnt = *((u16 *) (hdr + 6));
  if (cnt != 0)
  {
    while (((s16) cnt) > 0)
    {
      r = TLobby__sub_8040BA38(s, cur, len);
      len -= r;
      cur += (s16) r;
      cnt--;
    }

  }
  return 0;
}
#pragma pop
#pragma push
#pragma opt_lifetimes off
#pragma push
#pragma dont_inline off
#pragma inline_depth(4)
inline p803FE518_UnkNode8040A3C0 *find_8040BA38(u8 *obj, Rec_8040BA38 *rec) {
    p803FE518_UnkNode8040A3C0 *node;
    s16 cnt;
    if (obj == 0 || rec == 0) {
        return 0;
    }
    for (node = ((p803FE518_Unk8040A3C0 *)obj)->unk208, cnt = 0; node != 0 && cnt < ((s16 *)&dns_resolver_state)[22]; node = node->next, cnt++) {
        if (TLobby__sub_8040C9E0((u8 *)node, (u8 *)rec) == 0) {
            return node;
        }
    }
    return 0;
}
#pragma pop
extern s32 TLobby__sub_8040BA38(u8 *self, u8 *p, s32 n)
{
  s32 ret;
  s32 l;
  Hdr_8040BA38 hdr;
  u8 *new_var;
  Rec_8040BA38 rec;
  s16 limit;
  p803FE518_UnkNode8040A3C0 *found;
  u8 *new_var2;
  ret = TLobby__sub_8040BD40(self, p, n, 0);
  p += (s16) ret;
  if (limit < (((s16) ret) + 10))
  {
    limit = n;
    return n;
  }
  NetMemcpy(&hdr, p, 10);
  ret += 10;
  l = hdr.len;
  if (limit < (((s16) ret) + ((s16) l)))
  {
    return n;
  }
  ret += l;
  switch (hdr.sub)
  {
    case 1:
      switch (hdr.kind)
    {
      new_var2 = p;
      case 1:
      {
        u8 *obj;
        obj = *((u8 **) (self + 0x38));
        if (obj == 0)
        {
          break;
        }
        rec.type = 1;
        rec.size = 4;
        NetMemcpy(rec.data, new_var2 + 10, 4);
        if ((found = find_8040BA38(obj, &rec)) == 0)
        {
          found = (p803FE518_UnkNode8040A3C0 *) TLobby__sub_8040C248(obj);
          if (found == 0)
          {
            break;
          }
          found->unk0 = 1;
          found->unk18 = 1;
          found->unk4 = 4;
          new_var = new_var2;
          NetMemcpy(found->unk8, new_var + 10, 4);
          found->unk24 = obj;
          append_to_list((O_8040C4B0 *) obj, (N_8040C4B0 *) found);
        }
        found->unk1c = hdr.x;
        break;
      }

      case 5:
      {
        u8 *o = *((u8 **) (self + 0x38));
        if ((o != 0) && (((s8) o[0x104]) == 0))
        {
          TLobby__sub_8040BD40(self, new_var2 + 10, l, o + 0x104);
        }
        break;
      }
        if (!found)
      {
      }

      case 0x1c:
      {
        u8 *obj;
        obj = *((u8 **) (self + 0x38));
        if (obj == 0)
        {
          break;
        }
        rec.type = 0x1c;
        rec.size = 6;
        NetMemcpy(rec.data, p + 10, 0x10);
        if ((found = find_8040BA38(obj, &rec)) == 0)
        {
          found = (p803FE518_UnkNode8040A3C0 *) TLobby__sub_8040C248(obj);
          if (found == 0)
          {
            break;
          }
          found->unk0 = 1;
          found->unk18 = 0x1c;
          found->unk4 = 6;
          NetMemcpy(found->unk8, new_var + 10, 0x10);
          found->unk24 = obj;
          append_to_list((O_8040C4B0 *) obj, (N_8040C4B0 *) found);
        }
        found->unk1c = hdr.x;
        break;
      }

      case 0xc:
      {
        u8 *o = *((u8 **) (self + 0x2c));
        if (o != 0)
        {
          *((s32 *) (o + 0x18)) = hdr.x;
          TLobby__sub_8040BD40(self, p + 10, l, o + 0x1c);
        }
        break;
      }

    }

      break;

  }

  end:
  return ret;

}
#pragma pop
extern s32 TLobby__sub_8040BD40(u8 *self, u8 *p, s32 n, u8 *dst)
{
  s16 new_var2;
  u8 c2;
  u8 c;
  int new_var3;
  u8 *q;
  s32 len;
  s32 count = 0;
  int new_var;
  new_var2 = (s16) n;
  while (((s16) count) < new_var2)
  {
    c = *p;
    if (!c)
    {
      count++;
      break;
    }
    if (c & 0xC0)
    {
      q = *((u8 **) ((*((u8 **) (self + 0x1c))) + 4));
      q += (u16) (((new_var = c & (~0xC0)) << 8) | p[1]);
      new_var3 = 0;
      c2 = *q;
      p = q;
      while (c2 != new_var3)
      {
        if (dst != 0)
        {
          len = (c2 & 0xFF) + 1;
          NetMemcpy(dst, p, len);
          dst += len;
        }
        p += c2 + 1;
        c2 = *p;
      }

      count += 2;
      break;
    }
    if (dst != 0)
    {
      len = c + 1;
      NetMemcpy(dst, p, len);
      dst += len;
    }
    count = c;
    p += count + 1;
    count += c + 1;
  }

  return count;
}

extern void TLobby__sub_8040C178(u8 *self, s32 x);
extern G_8040A45C dns_resolver_state;
#pragma push
#pragma optimize_for_size off
extern void TLobby__sub_8040C178(u8 *self, s32 x);
extern G_8040A45C dns_resolver_state;
#pragma push
#pragma dont_inline off
#pragma inline_depth(4)
inline void cancel_8040BE40(u8 *o, s16 b) {
    void dispatch_request_callback(void *p, s16 x);
    u8 *base = (u8 *)&dns_resolver_state;
    s16 i;
    u8 *e;
    i = 0;
    e = *(u8 **)(base + 0x44);
    while (i < *(s16 *)(base + 0x40)) {
        if (*(u8 **)(e + 0x2c) == o) {
            *(s16 *)(e + 0x10) = -0x42;
            *(s16 *)(e + 0x12) = 0;
            *(u8 **)(e + 0x2c) = NULL;
            dispatch_request_callback(e, b);
        }
        i++;
        e += 0x3c;
    }
}
#pragma pop
#pragma push
#pragma dont_inline off
#pragma inline_depth(4)
extern void TLobby__sub_8040BE40(u8 *self, s16 a, s16 b)
{
    void TLobby__sub_8040C178(u8 *self, s16 x);
    void dispatch_request_callback(void *p, s16 x);
    u8 *o;
    u8 *p;
    switch (*(s16 *)(self + 8)) {
    case 1:
        p = *(u8 **)(self + 0x38);
        if (p != NULL) {
            *(u8 **)(self + 0x38) = NULL;
            TLobby__sub_8040C178(p, b);
        }
        break;
    case 12:
        o = *(u8 **)(self + 0x2c);
        if (o != NULL) {
            *(u8 **)(self + 0x2c) = NULL;
            *(s16 *)(o + 0) = 0;
            *(s32 *)(o + 0x18) = 0;
            *(u8 *)(o + 0x1c) = 0;
            cancel_8040BE40(o, b);
        }
        break;
    }
    *(s16 *)(self + 0x10) = a;
    *(s16 *)(self + 0x12) = 0;
    dispatch_request_callback(self, b);
}
#pragma pop
#pragma pop

typedef struct N_8040C4B0 { u8 pad0[0x20]; N_8040C4B0 *next; } N_8040C4B0;
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
s32 close_and_reset_connection(void *self) {
    u8 *arg0 = (u8 *)self;
    s16 *temp_r3_2;
    s16 *temp_r3_3;
    s32 temp_r3;
    s32 var_r31;
    var_r31 = close_8040BF38(arg0, *(s16 *)&((TObjectFields *)self)->m_flags);
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
    *(s16 *)&((TObjectFields *)self)->m_name = 0;
    *(s16 *)&((TObjectFields *)self)->m_prev = 0;
    *(s16 *)&((TObjectFields *)self)->m_up = -0x41;
    *(s16 *)((s8 *)arg0 + 0x12) = 0;
    if (*(u32 *)&((TObjectFields *)self)->m_next != 0xFFFFFFFFU) {
        resume_thread((s32)((TObjectFields *)self)->m_next);
        *(s32 *)&((TObjectFields *)self)->m_next = -1;
    }
    TLobby__sub_804217E4();
    return var_r31;
}

typedef struct O_8040C00C { s16 f0; u8 pad2[0x16]; s32 f18; u8 f1C; } O_8040C00C;
struct E_8040C00C { u8 pad0[0x10]; s16 f10; s16 f12; u8 pad14[0x18]; O_8040C00C *owner; u8 pad30[0xC]; };
struct G_8040C00C { u8 pad0[0x40]; s16 count; u8 pad42[2]; E_8040C00C *ents; };
struct Conn_8040C540;

#define g ((G_8040C00C *)&dns_resolver_state)
#define o ((O_8040C00C *)o_)
void reset_connection_requests(Conn_8040AF48 *o_, s16 arg1) {
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
            dispatch_request_callback((void *)e, arg1);
        }
        i++;
        e++;
    }
}

extern void TLobby__sub_8040C178(u8* self, s32 x);
extern G_8040A45C dns_resolver_state;
extern void TLobby__sub_8040C178(u8* self, s32 x);
extern G_8040A45C dns_resolver_state;
extern void TLobby__sub_8040C178(u8* self, s32 x);
extern G_8040A45C dns_resolver_state;
extern void TLobby__sub_8040C178(u8* self, s32 x);
extern G_8040A45C dns_resolver_state;
extern void TLobby__sub_8040C178(u8* self, s32 x);
extern G_8040A45C dns_resolver_state;
extern void TLobby__sub_8040C178(u8* self, s32 x);
extern G_8040A45C dns_resolver_state;
#pragma push
#pragma cplusplus off
#pragma dont_inline off
u8* TLobby__sub_8040C09C(void) {
    G_8040A45C *dns = &dns_resolver_state;
    u8 *p = (u8 *)dns->d;
    u8 *found = NULL;
    s16 count = dns->nd;
    s16 i;

    for (i = 0; i < count; i++, p += 0x20c) {
        if ((*(s16 *)((u8 *)p + 0)) == 0) {
            (*(s16 *)((u8 *)p + 0)) = 1;
            return p;
        } else if (found == NULL) {
            found = p;
        } else if ((*(s16 *)((u8 *)found + 0x204)) != 0 && (*(s16 *)((u8 *)p + 0x204)) != 0) {
            if ((*(s32 *)((u8 *)((*(u8 **)((u8 *)(p) + (0x208)))) + (0x1c))) < (*(s32 *)((u8 *)((*(u8 **)((u8 *)(found) + (0x208)))) + (0x1c)))) {
                found = p;
            }
        } else if ((*(s16 *)((u8 *)p + 0x204)) != 0) {
            found = p;
        }
    }
    TLobby__sub_8040C178(found, 1);
    (*(s16 *)((u8 *)found + 0)) = 1;
    return found;
}
#pragma pop

#pragma cplusplus off
void TLobby__sub_8040C178(u8 *self, s32 x)
{
    void dispatch_request_callback(void* p, s32 x);
  p803FE518_Unk805BDCF0 *base;
  u8 *e;
  s16 j;
  u8 *p;
  u8 *new_var;
  *((s16 *) (((u8 *) self) + 0)) = 0;
  j = 0;
  base = (p803FE518_Unk805BDCF0 *) ((u8*)&dns_resolver_state);
  *(self + 0x104) = 0;
  *((s16 *) (((u8 *) self) + 0x204)) = 0;
  p = *((u8 **) (((u8 *) self) + 0x208));
  while ((p != ((void *) 0)) && (j < base->unk2c))
  {
    e = p;
    p = *((u8 **) (((u8 *) e) + 0x20));
    j++;
    *((s16 *) (((u8 *) e) + 0)) = 0;
    *((u8 **) (((u8 *) e) + 0x20)) = (void *) 0;
  }

  *((u8 **) (((u8 *) (new_var = self)) + 0x208)) = (void *) 0;
  e = (u8 *) base->unk44;
  for (j = 0; j < base->unk40; j++, e += 0x3c)
  {
    if ((*((s32 *) (((u8 *) e) + 0x38))) == ((u32) new_var))
    {
      *((s16 *) (((u8 *) e) + 0x10)) = -0x42;
      p = (u8 *) e;
      *((s16 *) (p + 0x12)) = 0;
      *((s32 *) (p + 0x38)) = 0;
      dispatch_request_callback(e, x);
    }
  }

}
#pragma cplusplus reset

extern s32 TLobby__sub_8040C340(p803FE518_Unk8040A3C0 *self_m, p803FE518_UnkArg8040B34C *arg);
extern u8 *TLobby__sub_8040C248(u8 *self)
{
    s16 n;
    s16 i;
    u8 *best;
    u8 *e;
    s16 TLobby__sub_8040C340(p803FE518_Unk8040A3C0 *, p803FE518_UnkArg8040B34C *);
    if (self == NULL) {
        return NULL;
    }
    e = *(u8 **)((u8 *)&dns_resolver_state + 0x34);
    n = *(s16 *)((u8 *)&dns_resolver_state + 0x2c);
    best = NULL;
    for (i = 0; i < n; i++, e += 0x28) {
        if (*(s16 *)e == 0) {
            *(s16 *)e = 1;
            *(s32 *)(e + 0x20) = 0;
            return e;
        }
        if (*(u8 **)(e + 0x24) != self) {
            if (best == NULL) {
                best = e;
            } else if (*(s32 *)(e + 0x1c) < *(s32 *)(best + 0x1c)) {
                best = e;
            }
        }
    }
    if (best == NULL) {
        return NULL;
    }
    if (TLobby__sub_8040C340((p803FE518_Unk8040A3C0 *)*(u8 **)(best + 0x24), (p803FE518_UnkArg8040B34C *)best) < 0) {
        return NULL;
    }
    *(s16 *)best = 1;
    *(s32 *)(best + 0x20) = 0;
    return best;
}

extern s32 NetMemcmp(void * _w0, void * _w1, int _w2);
extern s32 NetMemcmp(void *_w0, void *_w1, int _w2);
extern s32 NetMemcmp(void *_w0, void *_w1, int _w2);
extern G_8040A45C dns_resolver_state;
extern s32 NetMemcmp(void *_w0, void *_w1, int _w2);
extern G_8040A45C dns_resolver_state;
extern s32 NetMemcmp(void *_w0, void *_w1, int _w2);
extern G_8040A45C dns_resolver_state;
extern s32 NetMemcmp(void *_w0, void *_w1, int _w2);
extern G_8040A45C dns_resolver_state;
#pragma push
#pragma dont_inline off
extern s32 TLobby__sub_8040C340(p803FE518_Unk8040A3C0 *self_m, p803FE518_UnkArg8040B34C *arg) {
u8 *tbl;
p803FE518_UnkNode8040A3C0 *node;
p803FE518_UnkNode8040A3C0 *prev;
u8 *key;
s16 i;
s32 r;
if (arg == ((void *) 0))
{
return -1;
}
if (self_m == ((void *) 0))
{
return -1;
}
if ((self_m->unk0 == 0) || (self_m->unk208 == ((void *) 0)))
{
return -1;
}
node = self_m->unk208;
tbl = (u8 *) (*(u8(*)[])&dns_resolver_state);
key = ((u8 *) arg) + 8;
prev = (p803FE518_UnkNode8040A3C0 *)((void *) 0);
for (i = 0; (node != ((void *) 0)) && (i < (*((s16 *) (tbl + 0x2c)))); node = node->next, (unsigned long long) (i++))
{
switch (*((s32 *) (((u8 *) node) + 4)))
{
case 4:
if (arg->type != 4)
{
r = -1;
}
else
{
r = NetMemcmp((void *)(((u8 *) node) + 8), (void *)(key), (int)(4));
}
break;
case 6:
if (arg->type != 6)
{
r = -1;
}
else
{
r = NetMemcmp((void *)(((u8 *) node) + 8), (void *)(key), (int)(0x10));
}
break;
case 0:
default:
r = -1;
break;
}
if (r != 0)
{
prev = node;
}
else
{
self_m->unk204--;
if (prev == ((void *) 0))
{
self_m->unk208 = node->next;
}
else
{
prev->next = node->next;
}
node->unk0 = 0;
node->next = (p803FE518_UnkNode8040A3C0 *)((void *) 0);
return 0;
}
}
return -1;
}
#pragma pop

#undef g
#undef o

s32 append_to_list(O_8040C4B0 *o, N_8040C4B0 *n) {
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

struct SubA_8040C540 {
    u32 f0;
    s32 f4;
    s16 f8;
    u8 padA[2];
    s32 fC;
    s16 f10;
    u8 pad12[2];
    CbA_8040C540 cb;
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

void TLobby__sub_8040C74C(void *);
s16 TLobby__sub_8040C8A8(u8 *, u8 *, s16);
s16 TLobby__sub_8040C978(void *);

void dispatch_request_callback(void *self, s16 status) {
    Conn_8040C540 *connection = (Conn_8040C540 *)self;
    s16 TLobby__sub_8040C8A8(u32, void *, s16);
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
                    resume_thread(connection->thread);
                    connection->thread = -1;
                }
                TLobby__sub_804217E4();
                return;
            }
            if (connection->thread != 0xFFFFFFFFU) {
                resume_thread(connection->thread);
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
                    resume_thread(connection->thread);
                    connection->thread = -1;
                }
                TLobby__sub_804217E4();
                return;
            }
            if (connection->thread != 0xFFFFFFFFU) {
                resume_thread(connection->thread);
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
                b->f4 = TLobby__sub_8040C8A8(b->f0, b->fC + 0x1C, b->f4);
            }
            b->cb(connection->id, b->f0, b->f4);
        }
        b->cb = NULL;
        break;
    }
}

void TLobby__sub_8040C74C(void *self) {
    s16 n;
    s8 *s;
    s32 len;
    s16 j;
    u8 *obj;
    s16 cnt;
    u8 *cur;
    u8 *ent;
    s16 v;

    obj = *(u8 **)((u8 *)self + 0x18);
    if (obj == NULL) {
        ((s16 *)self)[4] = -0x42;
        return;
    }
    if (*(s8 *)(obj + 0x104) != 0 && (v = *(s16 *)((u8 *)self + 0x10)) != 0) {
        if (*(u8 **)((u8 *)self + 0xc) == NULL) {
            s = (s8 *)(obj + 0x104);
            n = 0;
            while (n < 0xff) {
                s8 c = *s++;
                if (c == 0) {
                    n--;
                    break;
                }
                len = c;
                if (n + len + 1 <= 0xff) {
                    s += len;
                } else {
                    n = 0xff;
                    break;
                }
                n += len + 1;
            }
            *(s16 *)((u8 *)self + 0x10) = n;
        } else {
            *(s16 *)((u8 *)self + 0x10) = TLobby__sub_8040C8A8((u8 *)*(u32 *)((u8 *)self + 0xc), obj + 0x104, v);
        }
    } else {
        *(s16 *)((u8 *)self + 0x10) = 0;
    }
    cur = *(u8 **)((u8 *)self + 4);
    cnt = 0;
    ent = *(u8 **)(obj + 0x208);
    for (j = 0; j < *(s16 *)(obj + 0x204); j++, ent = *(u8 **)(ent + 0x20)) {
        if (*(u8 **)self == NULL || *(u8 **)self == *(u8 **)(ent + 4)) {
            cnt++;
            if (cur != NULL) {
                NetMemcpy(cur, ent + 4, 0x14);
                cur += 0x14;
                if (cnt >= ((s16 *)self)[4]) {
                    break;
                }
            }
        }
    }
    ((s16 *)self)[4] = cnt;
}

void NetMemcpy(void *, void *, int);
void NetMemcpy(void *, void *, int);
void NetMemcpy(void *, void *, int);
#pragma push
#pragma optimization_level 2
#pragma opt_common_subs off
extern s16 TLobby__sub_8040C8A8(u8 *dst, u8 *src, s16 max) {
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

s16 TLobby__sub_8040C978(void *arg)
{
  int new_var;
  u8 *s;
  s16 i;
  s8 c;
  s8 n;
  i = 0;
  s = (u8 *) arg;
  while (i < 0xff)
  {
    c = *(s++);
    if (c == 0)
    {
      return --i;
    }
    n = c;
    new_var = n;
    if (((((s32) i) + new_var) + 1) <= 0xff)
    {
      s += new_var;
    }
    else
    {
      return 0xff;
    }
    i = new_var + i;
    i++;
  }

  return i;
}

s32 TLobby__sub_8040C9E0(u8 *arg0, u8 *arg1) {
    typedef struct Fields_arg0 { u8 pad_0[4]; s32 field_4; u8 pad_8[16]; u16 field_18; } Fields_arg0;
    typedef struct Fields_arg1 { u8 pad_0[4]; u32 field_4; u8 pad_8[16]; u16 field_18; } Fields_arg1;
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

#pragma push
#pragma cplusplus off
#pragma pop
#pragma push
#pragma cplusplus off
#pragma dont_inline off
#pragma inline_depth(4)
#pragma optimize_for_size off
#pragma dont_inline off
s16 TLobby__sub_8040CB44(u8 *self, u32 d, u32 c)
{
  s16 TLobby__sub_8040CFE8(u8, u8, u32, u32, u8 *);
  s32 TLobby__sub_8040F8A4(u32, void *, u32, u32, u32);
  void TLobby__sub_80420D38(u16, u8);
  void TLobby__sub_80406FD8(void *, void *, s32);
  u8 *p;
  u8 stream[0xc];
  u8 hdr[8];
  u32 *new_var;
  u8 ip[24];
  u8 udp[8];
  u8 addr[4];
  u8 pad[12];
  u8 *q;
  s16 r;
  u32 i;
  u8 *rec;
  u8 *out;
  unsigned int a;
  u32 net;
  u32 mask;
  rec = self + 0x18;
  set_value_and_enable(stream, (s32) hdr);
  TLobby__sub_80406FD8(stream, rec + 4, 8);
  if (calc_ip_checksum(self, 0) != 0)
  {
    return -1;
  }
  switch (hdr[0])
  {
    case 0:

    case 4:

    case 11:

    case 12:

    case 13:

    case 14:

    case 17:

    case 18:
      break;

    case 8:
      out = alloc_free_entry();
      if (out == ((void *) 0))
    {
      return -0x101;
    }
      *((s32 *) (out + 4)) = (*((s32 *) (self + 4))) - 1;
      *((s32 *) (out + 8)) = (*((s32 *) (self + 8))) - (*((s16 *) (self + 0xc)));
      p = self + (*((s32 *) (self + 4))) * 12;
      for (i = 0, q = out; i < (*((u32 *) (out + 4))); i++)
    {
      *((s16 *) (q + 0xc)) = *((s16 *) p);
      NetMemcpy(q + 0x10, (p -= 12) + 16, 8);
      q += 12;
    }

      r = TLobby__sub_8040CFE8(0, 0, c, d, out);
      if (r < 0)
    {
      release_entry(out);
      return r;
    }
      release_entry(out);
      return 0;

    case 3:
      TLobby__sub_80406EB8(rec + 4, 8);
      set_value_and_enable(stream, (s32) ip);
      TLobby__sub_80406FD8(stream, rec + 4, 20);
      TLobby__sub_80406EB8(rec + 4, (ip[0] & 0xf) << 2);
      switch (ip[9])
    {
      case 6:
        break;

      case 17:
        set_value_and_enable(stream, (s32) udp);
        TLobby__sub_80406FD8(stream, rec + 4, 8);
        TLobby__sub_80420D38(*((u16 *) udp), hdr[1]);
        break;

    }

      return 0;

    case 5:
      TLobby__sub_80406EB8(rec + 4, 8);
      set_value_and_enable(stream, (s32) ip);
      TLobby__sub_80406FD8(stream, rec + 4, 20);
      switch (hdr[1])
    {
      case 0:

      case 2:
        NetMemcpy(addr, hdr + 4, 4);
        a = *((u32 *) (ip + 16));
        net = ((a & 0x80000000) == 0) ? (a & 0xFF000000) : (((a & 0xC0000000) == 0x80000000) ? (a & 0xFFFF0000) : (((a & 0xE0000000) == 0xC0000000) ? (a & 0xFFFFFF00) : (0)));
        new_var = (u32 *) addr;
        mask = ((a & 0x80000000) == 0) ? (0xFF000000) : (((a & 0xC0000000) == 0x80000000) ? (0xFFFF0000) : (((a & 0xE0000000) == 0xC0000000) ? (0xFFFFFF00) : (0)));
        TLobby__sub_8040F8A4(net, (void *) (*new_var), mask, 2, d);
        break;

      case 1:

      case 3:
        NetMemcpy(addr, hdr + 4, 4);
        TLobby__sub_8040F8A4(*((u32 *) (ip + 16)), (void *) (*((u32 *) addr)), -1, 6, d);
        break;

    }

      return 0;

    default:
      return -1;

  }

  return 0;
}
#pragma pop

s32 TUdpSocket__sub_8040CE58(u8 *p, u8 *b, s16 x, s16 id)
{
  s32 TLobby__sub_8040E780(s32, s32, s32, s32, s32, s32, void *);
  u8 *h;
  s32 lim;
  s32 r;
  s16 NetIPv4IsUnspecified(u32);
  s16 NetIPv4IsLoopback(s32);
  s16 TLobby__sub_8040FDA0(u32, s16);
  if ((NetIPv4IsUnspecified(*((u32 *) (b + 0xc))) || NetIPv4IsLoopback(*((s32 *) (b + 0xc)))) || (TLobby__sub_8040FDA0(*((u32 *) (b + 0xc)), id) != 0))
  {
    return -1;
  }
  if (TLobby__sub_8040FDA0(*((u32 *) (b + 0x10)), id))
  {
    return -1;
  }
  h = alloc_free_entry();
  if (h == ((void *) 0))
  {
    return -1;
  }
  lim = (s16) ((b[0] << 2) & 0x3C);
  lim = lim + 8;
  x = (x < lim) ? (x) : (lim);
  *((s32 *) (h + 4)) = 0;
  *((s32 *) (h + 8)) = x;
  ((struct 
  {
    s16 v;
    u8 pad[10];
  } *) (h + 0xc))[*((s32 *) (h + 4))].v = x;
  set_value_and_enable(&(h + 0x10)[(*((s32 *) (h + 4))) * 12], (s32) b);
  *((s32 *) (h + 4)) += 1;
  *((s32 *) (h + 8)) += 8;
  ((struct 
  {
    s16 v;
    u8 pad[10];
  } *) (h + 0xc))[*((s32 *) (h + 4))].v = 8;
  set_value_and_enable(&(h + 0x10)[(*((s32 *) (h + 4))) * 12], (s32) p);
  *((s32 *) (h + 4)) += 1;
  *((u16 *) (p + 2)) = 0;
  *((u16 *) (p + 2)) = calc_ip_checksum(h, 1);
  r = TLobby__sub_8040E780((s32) h, *((s32 *) (b + 0xc)), *((s32 *) (b + 0x10)), 0, 0, 0, (void *) 1);
  release_entry(h);
  return r;
}

extern s32 TLobby__sub_8040CFE8(u8 a, u8 b, u32 c, u32 d, u8 *tbl) {
    s64 tmp;
    struct {
        u8 t;
        u8 m;
        s16 v;
    } buf;
    s16 r;
    void TLobby__sub_80406EB8(void *, s32);
    s16 TLobby__sub_8040E780(s32, u32, u32, s32, s32, s32, void *);

    switch (a) {
    case 0:
        set_value_and_enable((void *)&tmp, (s32)&buf);
        TLobby__sub_80406FD8(&tmp, tbl + 0x10 + (*(s32 *)(tbl + 4) - 1) * 0xc, 8);
        TLobby__sub_80406EB8(tbl + 0x10 + (*(s32 *)(tbl + 4) - 1) * 0xc, 8);
        *(s16 *)(tbl + *(s32 *)(tbl + 4) * 0xc) -= 8;
        ((struct { u16 len; u8 pad[10]; } *)(tbl + 0xc))[*(s32 *)(tbl + 4)].len = 8;
        set_value_and_enable((void *)(tbl + 0x10 + *(s32 *)(tbl + 4) * 0xc), (s32)&buf);
        *(s32 *)(tbl + 4) += 1;
        break;
    default:
        return -1;
    }
    buf.t = a;
    buf.m = b;
    buf.v = 0;
    buf.v = calc_ip_checksum((void *)tbl, 1);
    r = TLobby__sub_8040E780((s32)tbl, d, c, 0, 0, 0, (void *)1);
    if (r != 0) {
        return -1;
    }
    return 0;
}

s16 NetIPv6HandleRouterSolicitation(u8 *o, s32 arg1, s32 arg2, s32 arg3);
s16 NetIPv6HandleRouterAdvertisement(u8 *arg0, u8 *arg1, s32 arg2, void *arg3);
s16 NetIPv6HandleNeighborSolicitation(u8 *arg0, void *arg1, void *arg2, void *arg3);
s16 NetIPv6HandleNeighborAdvertisement(u8 *arg0, void *arg1, void *arg2, s16 arg3);
s16 NetIPv6HandleRedirect(u8 *arg0, u8 *arg1, void *arg2, s32 arg3);
s16 NetIPv6HandleRouterSolicitation(u8 *o, s32 arg1, s32 arg2, s32 arg3);
s16 NetIPv6HandleRouterAdvertisement(u8 *arg0, u8 *arg1, s32 arg2, void *arg3);
s16 NetIPv6HandleNeighborSolicitation(u8 *arg0, void *arg1, void *arg2, void *arg3);
s16 NetIPv6HandleNeighborAdvertisement(u8 *arg0, void *arg1, void *arg2, s16 arg3);
s16 NetIPv6HandleRedirect(u8 *arg0, u8 *arg1, void *arg2, s32 arg3);
extern s32 TLobby__sub_80411DEC(void *self, s32 idx);
extern s16 TLobby__sub_8040D718(u8 a, u8 b, void *dst, void *p6, void *self, s16 p8);
extern s16 TLobby__sub_8040D718(u8 a, u8 b, void *dst, void *p6, void *self, s16 p8);
extern s16 NetIPv6HandleIcmpMessage(u8 *pkt, u8 *src, u8 *dst, u8 hop_limit, s16 iface) {
    s16 NetIPv6HandleRouterSolicitation(u8 *, u8 *, u8 *, s16);
    s16 NetIPv6HandleRouterAdvertisement(u8 *, u8 *, u8 *, s16);
    s16 NetIPv6HandleNeighborSolicitation(u8 *, u8 *, u8 *, s16);
    s16 NetIPv6HandleNeighborAdvertisement(u8 *, u8 *, u8 *, s16);
    s16 NetIPv6HandleRedirect(u8 *, u8 *, u8 *, s16);
    s32 TLobby__sub_80411DEC(u8 *addr, s16 mtu);
    u8 ref[8];
    struct { u8 pad0[6]; u8 next_header; u8 pad7[0x11]; u8 dst[0x10]; } ip;
    struct { u8 type; u8 code; u16 checksum; s32 pointer; } icmp;
    struct { u16 src_port; u16 dst_port; u16 len; u16 sum; } udp;
    u8 *from;
    u8 *buf;
    s32 mtu;
    s16 r;
    u32 i;
    u8 *body;
    u8 *reply;

    if (TLobby__sub_80411040((const IPv6Address *)src, (const IPv6Address *)dst, 0x3A, (const NetPacket *)pkt, 0)) {
        return -1;
    }
    body = pkt + 0x18;
    set_value_and_enable((void *)ref, (s32)&icmp);
    TLobby__sub_80406FD8(ref, body + 4, 8);
    switch (icmp.type) {
    case 128:
        reply = alloc_free_entry();
        if (reply == NULL) {
            return -257;
        }
        *(s32 *)(reply + 4) = *(s32 *)(pkt + 4) - 1;
        *(u32 *)(reply + 8) = *(u32 *)(pkt + 8) - *(s16 *)(pkt + 0xc);
        from = pkt + 0xc + *(s32 *)(pkt + 4) * 0xc - 0xc;
        for (i = 0; i < *(s32 *)(reply + 4); i++) {
            *(s16 *)(reply + 0xc + i * 0xc) = *(s16 *)from;
            buf = from + 4;
            from -= 0xc;
            NetMemcpy(reply + 0x10 + i * 0xc, buf, 8);
        }
        r = TLobby__sub_8040D718(0x81, 0, dst, src, reply, iface);
        release_entry(reply);
        return r;
    case 1:
        TLobby__sub_80406EB8(body + 4, 8);
        set_value_and_enable((void *)ref, (s32)&ip);
        TLobby__sub_80406FD8(ref, body + 4, sizeof(ip));
        TLobby__sub_80406EB8(body + 4, sizeof(ip));
        switch (ip.next_header) {
        case 17:
            set_value_and_enable((void *)ref, (s32)&udp);
            TLobby__sub_80406FD8(ref, body + 4, sizeof(udp));
            TLobby__sub_80420D38(udp.src_port, icmp.code);
            break;
        case 6:
            break;
        }
        return 0;
    case 2:
        mtu = icmp.pointer;
        if (mtu > 0 && mtu < 0x8000) {
            TLobby__sub_80406EB8(body + 4, 8);
            set_value_and_enable((void *)ref, (s32)&ip);
            TLobby__sub_80406FD8(ref, body + 4, sizeof(ip));
            TLobby__sub_80411DEC(ip.dst, mtu);
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

extern s32 TLobby__sub_80411F1C(void *, void *, s16);
extern s32 TLobby__sub_80410A98(s32, void *, void *, void *, void *);
extern s32 TLobby__sub_80411F1C(void *, void *, s16);
extern s32 TLobby__sub_80410A98(s32, void *, void *, void *, void *);
extern s32 TLobby__sub_80410A98(s32, void *, void *, void *, void *);
s16 TLobby__sub_8040D510(void *a, u8 *src, s16 c, s16 flag) {
    s16 NetIPv6IsUnspecified(void *);
    s16 NetIPv6IsMulticast(void *);
    s16 TLobby__sub_80413D78(void *, s16);
    s16 TLobby__sub_80411F1C(void *, void *, s16);
    s16 TLobby__sub_80410A98(s32, void *, void *, void *, void *);
    u8 buf[0x10];
    u8 *p;
    u8 *rec;
    s16 r;
    s16 t;
    s16 d;
    s32 len;

    if (NetIPv6IsUnspecified(src + 8) != 0 || NetIPv6IsMulticast(src + 8) != 0 ||
        TLobby__sub_80413D78(src + 8, flag) != 0) {
        return -1;
    }
    if (NetIPv6IsMulticast(src + 0x18) != 0) {
        switch (((u8 *)a)[0]) {
        case 2:
        case 4:
            break;
        default:
            return -1;
        }
        t = TLobby__sub_80411F1C(buf, src + 8, flag);
        if (t < 0) {
            return t;
        }
    } else {
        NetMemcpy(buf, src + 0x18, 0x10);
    }
    p = src + 8;
    rec = (u8 *)alloc_free_entry();
    if (rec == NULL) {
        return -1;
    }
    *(s32 *)(rec + 4) = 0;
    *(s32 *)(rec + 8) = c;
    ((struct { s16 len; u8 pad[10]; } *)(rec + 0xc))[*(s32 *)(rec + 4)].len = c;
    set_value_and_enable(rec + 0x10 + *(s32 *)(rec + 4) * 0xc, (s32)src);
    *(s32 *)(rec + 4) += 1;
    *(s32 *)(rec + 8) += 8;
    ((struct { s16 len; u8 pad[10]; } *)(rec + 0xc))[*(s32 *)(rec + 4)].len = 8;
    set_value_and_enable(rec + 0x10 + *(s32 *)(rec + 4) * 0xc, (s32)a);
    *(s32 *)(rec + 4) += 1;
    if (*(u32 *)(rec + 8) + 0x28 > 0x500) {
        d = len = *(u32 *)(rec + 8) - 0x4d8;
        if (d > *(s16 *)(rec + 0xc)) {
            return -1;
        }
        *(u32 *)(rec + 8) -= d;
        *(s16 *)(rec + 0xc) -= d;
    }
    *(s16 *)((u8 *)a + 2) = 0;
    *(s16 *)((u8 *)a + 2) = TLobby__sub_80411040((const IPv6Address *)buf, (const IPv6Address *)p, 0x3a, (const NetPacket *)rec, 1);
    r = TLobby__sub_80410A98((s32)rec, p, buf, 0, (void *)0x3a);
    release_entry(rec);
    return r;
}

extern s32 TLobby__sub_80411F1C(void *, void *, s16);
extern s32 TLobby__sub_80410A98(s32, void *, void *, void *, void *);
extern s32 TLobby__sub_80411F1C(void *, void *, s16);
extern s32 TLobby__sub_80410A98(s32, void *, void *, void *, void *);
extern s16 TLobby__sub_8040D718(u8 a, u8 b, void *dst, void *p6, void *self, s16 p8) {
    s16 r;
    s32 cnt;
    volatile struct { u8 a; u8 b; u16 v; } rec;

    extern void TLobby__sub_80406EB8(void *, int);
    extern s16 NetIPv6IsMulticast(u8 *);
    extern s16 NetIPv6IsUnspecified(u8 *);
    extern s16 TLobby__sub_80411F1C(void *, void *, s16);
    extern s16 TLobby__sub_80410A98(s32, void *, void *, void *, void *);
    if (NetIPv6IsMulticast((u8 *)dst) != 0 || NetIPv6IsUnspecified((u8 *)dst) != 0) {
        r = TLobby__sub_80411F1C(dst, p6, p8);
        if (r < 0) {
            return r;
        }
    }
    switch ((s32)a) {
    case 0x81:
        cnt = *(s32 *)((u8 *)self + 4);
        TLobby__sub_80406EB8((u8 *)self + 0x10 + (cnt - 1) * 0xc, 4);
        cnt = *(s32 *)((u8 *)self + 4);
        *(s16 *)((u8 *)self + cnt * 0xc) -= 4;
        cnt = *(s32 *)((u8 *)self + 4);
        ((struct { s16 v; u8 pad[10]; } *)((u8 *)self + 0xc))[cnt].v = 4;
        cnt = *(s32 *)((u8 *)self + 4);
        set_value_and_enable((void *)((u8 *)self + 0x10 + cnt * 0xc), (s32)&rec);
        *(s32 *)((u8 *)self + 4) += 1;
        break;
    default:
        return -1;
    }
    rec.a = a;
    rec.b = b;
    rec.v = 0;
    rec.v = TLobby__sub_80411040((const IPv6Address *)dst, (const IPv6Address *)p6, 0x3a, (const NetPacket *)self, 1);
    if (TLobby__sub_80410A98((s32)self, p6, dst, 0, (void *)0x3a) != 0) {
        return -1;
    }
    return 0;
}

s32 TLobby__sub_80410A98(s32, void *, void *, void *, void *);

s32 dispatch_by_addr_family(s32 arg0, u8 *arg1, u8 *arg2, u8 *arg3, void *arg4, void *arg5) {
    s32 TLobby__sub_8040E780(s32, s32, s32, s32, s32, s32, void *);
    switch (*(s32 *)arg2) {
    case 4:
        return TLobby__sub_8040E780(arg0, *(s32 *)(arg1 + 4), *(s32 *)(arg2 + 4), arg3[0], arg3[1], arg3[2], arg5);
    case 6:
        return TLobby__sub_80410A98(arg0, arg1 + 4, arg2 + 4, arg4, arg5);
    case 0:
    default:
        return -2;
    }
}

u16 TLobby__sub_8040D8F0(u8 *arg0, u8 *arg1, s8 arg2, u8 *pkt, s16 flag) {
    typedef struct Fields_arg0 { s32 field_0; s32 field_4; } Fields_arg0;
    typedef struct Fields_arg1 { u8 pad_0[4]; s32 field_4; } Fields_arg1;
    switch (((Fields_arg0*)arg0)->field_0) {
    case 4:
        return calc_pseudo_header_checksum(((Fields_arg0*)arg0)->field_4, ((Fields_arg1*)arg1)->field_4, arg2, pkt, flag);
    case 6:
        return TLobby__sub_80411040((const IPv6Address *)((void *) (arg0 + 4)), (const IPv6Address *)((void *) (arg1 + 4)), arg2, (const NetPacket *)(pkt), flag);
    case 0:
    default:
        return 0xFFFEU;
    }
}

typedef struct Ent_8040D95C { u8 pad0[2]; s16 f2; u8 pad4[2]; s16 f6; u8 pad8[4]; s32 fC; } Ent_8040D95C;
struct In_8040D95C { s32 type; s32 f4; };
struct Out_8040D95C { s32 type; u32 f4; };
s32 TLobby__sub_8040EF50(u32 *out, u32 mask, s16 c);
s32 TLobby__sub_80411F1C(void *arg0, void *arg1, s16 arg2);
s32 select_source_address(Out_8040D95C *arg0, In_8040D95C *arg1) {
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
        return TLobby__sub_80411F1C(&arg0->f4, &arg1->f4, e->f6);
    case 0:
    default:
        return -2;
    }
}

s32 TLobby__sub_8040DA54(u8 *arg0, u8 *arg1) {
    typedef struct Fields_arg0 { s32 field_0; u8 * field_4; } Fields_arg0;
    typedef struct Fields_arg1 { u8 pad_0[4]; s32 field_4; } Fields_arg1;
    s32 var_r4;
    u8 *var_r3;
    switch (((Fields_arg0*)arg0)->field_0) {
    case 4:
        var_r3 = (u8 *)(((Fields_arg0*)arg0)->field_4);
        var_r4 = ((Fields_arg1*)arg1)->field_4;
        return is_lookup_found((u32)var_r3, (u32)(var_r4));
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
    s16 TLobby__sub_804136EC(s32);
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
        return TLobby__sub_804136EC((s32)address->address);
    default:
        return -2;
    }
}

s32 is_multicast_address(void *self, s16 arg1) {
    u8 *arg0 = (u8 *)self;
    typedef struct Fields_arg0 { s32 field_0; u32 field_4; } Fields_arg0;
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

s32 is_addr_unspecified(u8 *arg0) {
    typedef struct Fields_arg0 { s32 field_0; u32 field_4; } Fields_arg0;
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

s32 compare_sockaddr(void *self, u8 *arg1) {
    u8 *arg0 = (u8 *)self;
    typedef struct Fields_arg0 { s32 field_0; u8 * field_4; } Fields_arg0;
    typedef struct Fields_arg1 { u32 field_0; u8 * field_4; } Fields_arg1;
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

s16 TLobby__sub_8040DC8C(u8 *arg0, u8 *arg1) {
    s16 TLobby__sub_8040EF00(s16);
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
        entry_field_26 = get_entry_field_26(*(s16 *)((s8 *)temp_r3_4 + 6));
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
    release_slot_by_id(0x800);
    TLobby__sub_803F892C((void *)((void *) (&ipv4_protocol_state.value)));
    ipv4_protocol_state.value = 0;
    return 0;
}

s32 TUdpSocket__sub_8040DE4C(u8 *ip, s16 x, s16 id);
s32 init_ipv4_interfaces(void) {
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
    register_protocol_handler(0x800, (Handler_8041A130)TUdpSocket__sub_8040DE4C);
    return 0;
}

s32 TUdpSocket__sub_8040DE4C(u8 *ip, s16 x, s16 id)
{
  u8 *p;
  u8 *g;
  u8 hl;
  s16 r;
  s16 n;
  s16 found;
  s16 i;
  u32 tl;
  s32 rr;
  u32 fl;
  int new_var2;
  unsigned char mf;
  u32 s;
  s16 TUdpSocket__sub_8040E354(u8 *, u32, u8 *, s16, s16);
  s16 TLobby__sub_8040FDA0(u32, s16);
  s16 TLobby__sub_8040FE40(s16);
  s32 TLobby__sub_80418C40(u8 *, void *, s16, u8, u32, void *, u16, s32, s16);
  s16 TLobby__sub_8041B974(void *, void *, void *);
  s16 udp_input(void *, void *, void *, s16);
  void TLobby__sub_80421AD8(void *, u32, u32, u32, s16);
  s16 TLobby__sub_8040CB44(u8 *, u32, u32);
  s32 TUdpSocket__sub_8040CE58(u8 *, u8 *, s16, s16);
  u16 TUdpSocket__sub_80419864(void *, s16);
  s32 TUdpSocket__sub_80418BD8(A_80418BD8 *);
  struct 
  {
    s32 t;
    u32 a;
    u8 pad[0xC];
  } src;
  struct 
  {
    s32 t;
    u32 a;
    u8 pad[0xC];
  } dst;
  struct 
  {
    u8 type;
    u8 code;
    s32 w;
  } ic;
  u8 padx[12];
  if (x < 5)
  {
    return -1;
  }
  if (get_active_entry_by_index(id) == 0)
  {
    return -1;
  }
  src.t = 4;
  NetMemcpy(&src.a, ip + 12, 4);
  dst.t = 4;
  NetMemcpy(&dst.a, ip + 16, 4);
  hl = (ip[0] << 2) & 0x3C;
  tl = *((u16 *) (ip + 2));
  n = tl - hl;
  if (hl < 20)
  {
    return -1;
  }
  if ((ip[0] >> 4) != 4)
  {
    return -1;
  }
  s = TUdpSocket__sub_80419864(ip, (s16) (hl >> 1));
  s = (s >> 16) + (s & 0xFFFF);
  s += s >> 16;
  if (((u16) (~s)) != 0)
  {
    return -1;
  }
  if (tl < hl)
  {
    return -1;
  }
  if (id != 0)
  {
    if (TLobby__sub_8040FCEC(dst.a) < 0)
    {
      if (TLobby__sub_8040FDA0(dst.a, id) == 0)
      {
        if (TLobby__sub_8040FE40(id) != 0)
        {
          r = TUdpSocket__sub_8040E354((u8 *) dst.a, src.a, ip, x, id);
          if (0 > r)
          {
            return -1;
          }
          return -1;
        }
      }
    }
  }
  fl = *((u16 *) (ip + 6));
  if (fl & (~0x4000))
  {
    mf = (fl & 0x2000) ? (1) : (0);
    ip = (u8 *) TLobby__sub_80418C40(ip, (void *) hl, n, ip[8], *((u16 *) (ip + 4)), &src, fl & 0x1FFF, mf, id);
    if (ip == 0)
    {
      return 0;
    }
    n = 1;
  }
  else
  {
    ip = alloc_free_entry();
    if (ip == 0)
    {
      return -257;
    }
    *((s32 *) (ip + 4)) = (new_var2 = 0);
    *((s32 *) (ip + 8)) = tl;
    ((struct 
    {
      s16 v;
      u8 pad[10];
    } *) (ip + 0xc))[*((s32 *) (ip + 4))].v = hl;
    set_value_and_enable((ip + 0x10) + ((*((s32 *) (ip + 4))) * 12), (s32) ip);
    *((s32 *) (ip + 4)) += 1;
    ((struct 
    {
      s16 v;
      u8 pad[10];
    } *) (ip + 0xc))[*((s32 *) (ip + 4))].v = n;
    set_value_and_enable((ip + 0x10) + ((*((s32 *) (ip + 4))) * 12), (s32) (ip + hl));
    *((s32 *) (ip + 4)) += 1;
    n = 0;
  }
  switch (ip[9])
  {
    case 1:
      found = 1;
      r = TLobby__sub_8040CB44(ip, src.a, dst.a);
      if (r < 0)
    {
      if (n == 1)
      {
        TUdpSocket__sub_80418BD8((A_80418BD8 *) ip);
      }
      release_entry(ip);
      return -1;
    }
      if (n == 1)
    {
      TUdpSocket__sub_80418BD8((A_80418BD8 *) ip);
    }
      release_entry(ip);
      break;

    case 6:
      r = TLobby__sub_8041B974(ip, &src, &dst);
      if (r < 0)
    {
      if (n == 1)
      {
        TUdpSocket__sub_80418BD8((A_80418BD8 *) ip);
      }
      release_entry(ip);
      return -1;
    }
      if (n == 1)
    {
      TUdpSocket__sub_80418BD8((A_80418BD8 *) ip);
    }
      release_entry(ip);
      return 0;

    case 17:
      r = udp_input(ip, &src, &dst, id);
      if (r < 0)
    {
      switch (r)
      {
        case -2:
          ic.type = 3;
          ic.code = 3;
          ic.w = 0;
          rr = TUdpSocket__sub_8040CE58((u8 *) (&ic), ip, x, id);
          if (n == 1)
        {
          TUdpSocket__sub_80418BD8((A_80418BD8 *) ip);
        }
          release_entry(ip);
          return rr;

        default:
          if (n == 1)
        {
          TUdpSocket__sub_80418BD8((A_80418BD8 *) ip);
        }
          release_entry(ip);
          return -1;

      }

    }
      if (n == 1)
    {
      TUdpSocket__sub_80418BD8((A_80418BD8 *) ip);
    }
      release_entry(ip);
      return 0;

    default:
      found = 0;
      break;

  }

  g = (u8 *) (&ipv4_protocol_state);
  p = *((u8 **) (g + 4));
  for (i = 0; i < (*((s16 *) g)); i++)
  {
    if ((*((u16 *) (p + 4))) == 1)
    {
      if (((*((u32 *) (p + 8))) == 0) || ((*((u32 *) (p + 8))) == src.a))
      {
        if ((*((u8 *) (p + 24))) == ip[9])
        {
          if ((*((u32 *) (p + 16))) != 0)
          {
            TLobby__sub_80421AD8(ip, src.a, dst.a, *((u32 *) (p + 16)), i);
            found = 1;
          }
        }
      }
    }
    p += 28;
  }

  if (found == 1)
  {
    if (n == 1)
    {
      TUdpSocket__sub_80418BD8((A_80418BD8 *) ip);
    }
    release_entry(ip);
    return 0;
  }
  ic.type = 3;
  ic.code = 2;
  ic.w = 0;
  TUdpSocket__sub_8040CE58((u8 *) (&ic), ip, x, id);
  if (n == 1)
  {
    TUdpSocket__sub_80418BD8((A_80418BD8 *) ip);
  }
  release_entry(ip);
  return -1;
}

s16 TUdpSocket__sub_8040E354(u8 *self, u32 key, u8 *pkt, s32 total)
{
  s16 TLobby__sub_8040EDE4(void *, u32, s16);
  s16 TLobby__sub_8040EF00(s16);
  u16 TUdpSocket__sub_80419864(void *, s16);
  s16 cnt8;
  u8 *rt;
  u32 s;
  u8 hdr;
  int fl;
  s16 off;
  s16 mtu;
  s16 ifidx;
  u8 *target;
  u8 *rec;
  u16 flagsHi;
  s16 units;
  s32 frag;
  s16 cnt;
  s16 rem;
  s32 hl;
  s32 df;
  u8 *payload;
  u16 t46;
  u16 t44;
  u16 g1[2];
  s16 t36;
  u16 t34;
  s16 r;
  u8 g2[10];
  s16 len;
  hdr = (pkt[0] << 2) & 0x3C;
  if (hdr == 20)
  {
    len = total - 20;
  }
  else
  {
    len = total - hdr;
  }
  if (len <= 0)
  {
    return -1;
  }
  NetMemcpy(&t46, pkt + 6, 2);
  frag = t46;
  flagsHi = frag & (~0x1FFF);
  t46 = flagsHi;
  df = frag & 0x4000;
  off = frag & 0xFF;
  if (((u8) (pkt[8] - 1)) < 1)
  {
    return -1;
  }
  pkt[8] = pkt[8] - 1;
  rt = TLobby__sub_8040F76C((u32) self, key);
  if (rt == 0)
  {
    return -6;
  }
  ifidx = *((s16 *) (rt + 2));
  if ((*((s16 *) (rt + 18))) == 1)
  {
    target = self;
  }
  else
  {
    target = *((u8 **) (rt + 12));
  }
  mtu = TLobby__sub_8040EF00(ifidx);
  if (mtu < 0)
  {
    return mtu;
  }
  if (mtu < (hdr + len))
  {
    if (df & 0xFF)
    {
      return -1;
    }
    rec = alloc_free_entry();
    if (rec == 0)
    {
      return -257;
    }
    rem = len;
    payload = pkt + hdr;
    units = (mtu - hdr) / 8;
    do
    {
      if (mtu > (rem + (hl = hdr)))
      {
        t46 = flagsHi;
        cnt8 = rem % 8;
        cnt = rem / 8;
        mtu = rem;
      }
      else
      {
        t46 |= 0x2000;
        cnt = units;
        cnt8 = 0;
      }
      t36 = off;
      t36 |= t46;
      NetMemcpy(pkt + 6, &t36, 2);
      fl = cnt8 + (cnt << 3);
      t34 = hl + fl;
      NetMemcpy(pkt + 2, &t34, 2);
      NetMemset(pkt + 10, 0, 2);
      s = TUdpSocket__sub_80419864(pkt, hl / 2);
      s = (s >> 16) + (s & 0xFFFF);
      s += s >> 16;
      t44 = ~s;
      NetMemcpy(pkt + 10, &t44, 2);
      *((s32 *) (rec + 4)) = 0;
      *((s32 *) (rec + 8)) = (u16) fl;
      *((s16 *) ((rec + ((*((s32 *) (rec + 4))) * 12)) + 12)) = fl;
      set_value_and_enable((rec + 0x10) + ((*((s32 *) (rec + 4))) * 12), (s32) payload);
      *((s32 *) (rec + 4)) += 1;
      *((s32 *) (rec + 8)) += hdr;
      *((s16 *) ((rec + ((*((s32 *) (rec + 4))) * 12)) + 12)) = hdr;
      set_value_and_enable((rec + 0x10) + ((*((s32 *) (rec + 4))) * 12), (s32) pkt);
      *((s32 *) (rec + 4)) += 1;
      r = TLobby__sub_8040EDE4(rec, (u32) target, ifidx);
      if (r < 0)
      {
        release_entry(rec);
        break;
      }
      off += cnt;
      payload += cnt << 3;
      hdr = 20;
      if (mtu == rem)
      {
        rem = 0;
      }
      else
      {
        rem = rem - fl;
      }
    }
    while (rem > 0);
    release_entry(rec);
  }
  else
  {
    NetMemset(pkt + 10, 0, 2);
    s = TUdpSocket__sub_80419864(pkt, hdr / 2);
    s = (s >> 16) + (s & 0xFFFF);
    s += s >> 16;
    t44 = ~s;
    NetMemcpy(pkt + 10, &t44, 2);
    rec = alloc_free_entry();
    if (rec == 0)
    {
      return -257;
    }
    *((s32 *) (rec + 4)) = 0;
    *((s32 *) (rec + 8)) = len;
    ((struct 
    {
      s16 v;
      u8 pad[10];
    } *) (rec + 0xc))[*((s32 *) (rec + 4))].v = len;
    set_value_and_enable((rec + 0x10) + ((*((s32 *) (rec + 4))) * 12), (s32) (pkt + hdr));
    *((s32 *) (rec + 4)) += 1;
    *((s32 *) (rec + 8)) += hdr;
    ((struct 
    {
      s16 v;
      u8 pad[10];
    } *) (rec + 0xc))[*((s32 *) (rec + 4))].v = hdr;
    set_value_and_enable((rec + 0x10) + ((*((s32 *) (rec + 4))) * 12), (s32) pkt);
    *((s32 *) (rec + 4)) += 1;
    r = TLobby__sub_8040EDE4(rec, (u32) target, ifidx);
    release_entry(rec);
  }
  return r;
}

#pragma push
#pragma opt_common_subs on
s16 TLobby__sub_8040E780(u8 *rec, u32 dst, u32 src, u8 ttl, u8 tos, u8 df, void *proto)
{
  s16 tot;
  u8 *g;
  u8 *ent;
  u8 *ip;
  u8 *target;
  s16 ifidx;
  s16 mtu;
  s32 idx;
  s16 chunk;
  s32 units;
  s16 rem;
  s32 off;
  s16 last;
  s32 k;
  s32 i2;
  u8 *data;
  u8 *p;
  u8 *q;
  s32 j;
  s16 *lp;
  s16 r;
  u8 *new_var;
  u32 s;
  s16 TLobby__sub_8040EF50(u32 *, u32, s16);
  s16 TLobby__sub_8040FDA0(u32, s16);
  s16 TLobby__sub_8040EF00(s16);
  s16 TLobby__sub_8040EDE4(void *, u32, s16);
  u16 TUdpSocket__sub_80419864(void *, s16);
  void TLobby__sub_80406EB8(void *, s32);
  struct 
  {
    s64 a;
    u8 b[0x98];
  } loc;
  g = (u8 *) (&ipv4_protocol_state);
  ent = TLobby__sub_8040F76C(dst, src);
  if ((ent == 0) != 0)
  {
    return -6;
  }
  if (src == 0)
  {
    r = TLobby__sub_8040EF50(&src, *((u32 *) (ent + 12)), *((s16 *) (ent + 2)));
    if (r < 0)
    {
      return r;
    }
  }
  if (TLobby__sub_8040FDA0(src, *((s16 *) (ent + 2))) != 0)
  {
    r = TLobby__sub_8040EF50(&src, *((u32 *) (ent + 12)), *((s16 *) (ent + 2)));
    if (r < 0)
    {
      return r;
    }
  }
  ifidx = *((s16 *) (ent + 2));
  if ((*((s16 *) (ent + 18))) == 1)
  {
    target = (u8 *) dst;
  }
  else
  {
    target = *((u8 **) (ent + 12));
  }
  g[12] = 0x40;
  ip = g + 12;
  g[12] |= 5;
  if (tos != 0)
  {
    ip[1] = tos;
  }
  else
  {
    ip[1] = g[10];
  }
  if (ttl != 0)
  {
    ip[8] = ttl;
  }
  else
  {
    ip[8] = g[11];
  }
  tot = *((s32 *) (rec + 8));
  if (tot == 0)
  {
    return 0;
  }
  tot = tot + 20;
  *((s16 *) (ip + 2)) = tot;
  *((u16 *) (g + 8)) += 1;
  ip[9] = (u8) ((s32) proto);
  *((u16 *) (ip + 4)) = *((u16 *) (g + 8));
  NetMemcpy(ip + 12, &src, 4);
  NetMemcpy(ip + 16, &dst, 4);
  mtu = TLobby__sub_8040EF00(ifidx);
  if (mtu < 0)
  {
    return mtu;
  }
  if (tot <= mtu)
  {
    *((u16 *) (ip + 6)) = 0;
    if (df != 0)
    {
      *((u16 *) (ip + 6)) = 0x4000;
    }
    *((u16 *) (ip + 10)) = 0;
    if (!j)
    {
    }
    s = TUdpSocket__sub_80419864(ip, 10);
    s = (s >> 16) + (s & 0xFFFF);
    s += s >> 16;
    *((u16 *) (ip + 10)) = ~s;
    *((s32 *) (rec + 8)) += 20;
    ((struct 
    {
      s16 v;
      u8 pad[10];
    } *) (rec + 0xc))[*((s32 *) (rec + 4))].v = 20;
    set_value_and_enable((rec + 0x10) + ((*((s32 *) (rec + 4))) * 12), (s32) ip);
    *((s32 *) (rec + 4)) += 1;
    return TLobby__sub_8040EDE4(rec, (u32) target, ifidx);
  }
  off = 0;
  if (df != 0)
  {
    return -2;
  }
  chunk = (mtu - 20) / 8;
  chunk *= 8;
  units = chunk / 8;
  *((u16 *) (ip + 6)) = 0;
  ent = (u8 *) (&loc);
  do
  {
    *((s32 *) (ent + 4)) = 0;
    *((s32 *) (ent + 8)) = 0;
    rem = chunk;
    k = 0;
    j = (idx = (*((s32 *) (rec + 4))) - 1);
    p = rec + (j * 12);
    while ((rem > 0) && (j >= 0))
    {
      k++;
      p -= 12;
      rem -= *((s16 *) (p + 24));
      j--;
    }

    i2 = idx;
    j = (s16) k;
    j = j - 1;
    rem = chunk;
    last = 0;
    while ((rem > 0) && (j >= 0))
    {
      p = rec + (i2 * 12);
      q = ent + (((((((((((j * 12) & 0xFFFFFFFFFFFFFFFF) & 0xFFFFFFFFFFFFFFFF) & 0xFFFFFFFFFFFFFFFF) & 0xFFFFFFFFFFFFFFFF) & 0xFFFFFFFFFFFFFFFF) & 0xFFFFFFFFFFFFFFFF) & 0xFFFFFFFFFFFFFFFF) & 0xFFFFFFFFFFFFFFFF) & 0xFFFFFFFFFFFFFFFF) & 0xFFFFFFFFFFFFFFFF);
      data = p + 16;
      NetMemcpy(q + 16, data, 8);
      new_var = p + 12;
      lp = (s16 *) new_var;
      if ((*((s16 *) new_var)) > rem)
      {
        *((s16 *) (q + 12)) = rem;
        *((s32 *) (ent + 8)) += rem;
        *lp -= rem;
        *((s32 *) (rec + 8)) -= rem;
        TLobby__sub_80406EB8(data, rem);
        rem = 0;
      }
      else
      {
        *((s16 *) (q + 12)) = *((s16 *) new_var);
        *((s32 *) (ent + 8)) += *lp;
        *((s32 *) (rec + 8)) -= *lp;
        rem -= *lp;
        if (i2 == 0)
        {
          rem = *lp;
          last = 1;
          j--;
          i2--;
        }
        else
        {
          *((s32 *) (rec + 4)) -= 1;
          i2--;
          j--;
        }
      }
      *((s32 *) (ent + 4)) += 1;
    }

    if (last == 1)
    {
      *((u16 *) (ip + 6)) = 0;
    }
    else
    {
      *((u16 *) (ip + 6)) = 0x2000;
    }
    *((u16 *) (ip + 6)) |= off;
    *((u16 *) (ip + 2)) = (*((s32 *) (ent + 8))) + 20;
    *((u16 *) (ip + 10)) = 0;
    s = TUdpSocket__sub_80419864(ip, 10);
    s = (s >> 16) + (s & 0xFFFF);
    s += s >> 16;
    *((u16 *) (ip + 10)) = ~s;
    *((s32 *) (ent + 8)) += 20;
    *((s16 *) ((ent + ((*((s32 *) (ent + 4))) * 12)) + 12)) = 20;
    set_value_and_enable((ent + 0x10) + ((*((s32 *) (ent + 4))) * 12), (s32) ip);
    *((s32 *) (ent + 4)) += 1;
    r = TLobby__sub_8040EDE4(ent, (u32) target, ifidx);
    if (r < 0)
    {
      return r;
    }
    off += units;
  }
  while (last != 1);
  return 0;
}
#pragma pop
typedef struct PH_8040EC38 { s32 src; s32 dst; u8 zero; s8 proto; u16 len; } PH_8040EC38;
struct P_8040EC38 { u8 pad0[8]; s32 f8; s16 fC; };

u16 TUdpSocket__sub_80419864();

u16 calc_pseudo_header_checksum(s32 src, s32 dst, s8 proto, void *pkt, s16 flag) {
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

u16 calc_ip_checksum(void *self, s16 b) {
    u32 s = TLobby__sub_80406BD8(self, b);
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
s32 TLobby__sub_8040ED70(void) {
    init_buffer_descriptor_a((NetBufDescA *)(&(*(RecoveredGlobal_8040ED70_lbl_805C1B60 *)&ipv4_address_routing_state).value));
    NetMemset((void *)((int) (*(s32 *)((s8 *)(&(*(RecoveredGlobal_8040ED70_lbl_805C1B60 *)&ipv4_address_routing_state).value) + 8))), 0, (int)((int) (*(s16 *)((s8 *)(&(*(RecoveredGlobal_8040ED70_lbl_805C1B60 *)&ipv4_address_routing_state).value) + 0) * 0x14)));
    NetMemset((void *)((int) (*(s32 *)((s8 *)(&(*(RecoveredGlobal_8040ED70_lbl_805C1B60 *)&ipv4_address_routing_state).value) + 0xC))), 0, (int)((int) (*(s16 *)((s8 *)(&(*(RecoveredGlobal_8040ED70_lbl_805C1B60 *)&ipv4_address_routing_state).value) + 2) * 0x14)));
    NetMemset((void *)((int) (*(s32 *)((s8 *)(&(*(RecoveredGlobal_8040ED70_lbl_805C1B60 *)&ipv4_address_routing_state).value) + 0x10))), 0, (int)((int) (*(s16 *)((s8 *)(&(*(RecoveredGlobal_8040ED70_lbl_805C1B60 *)&ipv4_address_routing_state).value) + 4) * 0x18)));
    return 0;
}

#pragma push
#pragma dont_inline off
#pragma inline_depth(4)
inline s16 chk_8040EDE4(s16 id, u32 k) {
    s16 *p;
    p = get_active_entry_by_index(id);
    if (p == NULL) {
        return 0;
    }
    if (*(u32 *)((s8 *)p + 8) == 0 || k == 0xFFFFFFFF || k == *(u32 *)((s8 *)p + 0xC)) {
        return 1;
    }
    return 0;
}
#pragma pop

#pragma push
#pragma dont_inline off
#pragma inline_depth(4)
extern s32 TLobby__sub_8040EDE4(void *self, u32 key, s16 id) {
    s16 *e;

    if (id < 0 || id >= *(s16 *)((u8 *)&ipv4_address_routing_state + 2)) {
        return -0x109;
    }
    e = *(s16 **)((u8 *)&ipv4_address_routing_state + 0xC);
    e += id * 14;
    if (e[0] != 1) {
        return -6;
    }
    if (key == 0 || chk_8040EDE4(id, key)) {
        return call_handler_by_index(id, e[1], 1, (s32)&key, (s32)self);
    }
    return dispatch_handler_by_index(id, e[1], (s32)&key, (s32)self);
}
#pragma pop
#pragma push
#pragma opt_common_subs on
s32 TLobby__sub_8040EF00(s16 arg0) {
    typedef struct Fields_temp_r3 { s16 field_0; u8 pad_2[2]; s16 field_4; } Fields_temp_r3;
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

typedef struct A_8040F1A0 { u16 flags; s16 id; u32 f4; u32 f8; u32 fc; u16 f10; s16 f12; } A_8040F1A0;
struct Nd_8040F1A0 { s16 f0; s16 f2; u32 f4; u32 f8; u32 fc; u32 f10; Nd_8040F1A0 *next; };
struct B_8040F1A0 { s16 flags; s16 f2; s16 f4; s16 f6; u32 f8; u32 fc; u32 f10; u32 f14; Nd_8040F1A0 *nodes; };
struct G_8040F1A0 { s16 nA; s16 nB; s16 nC; s16 f6; A_8040F1A0 *a; B_8040F1A0 *b; };

inline s16 getfirst_8040F1A0(s16 *pn, B_8040F1A0 **pb, u32 *out) {
    if (*pn <= 0) {
        return 0;
    }
    if ((*pb)->flags != 1) {
        return 0;
    }
    *out = (*pb)->f8;
    return 1;
}

inline void drop_8040F1A0(G_8040F1A0 *g, u32 k1, u32 k2) {
    s16 i;
    A_8040F1A0 *e;
    e = g->a;
    for (i = 0; i < g->nA; i++, e++) {
            if ((e->flags & 1) && e->f4 == k1 && e->fc == k2 && (e->f12 & 1) == 1) {
            e->flags = 0;
            break;
        }
    }
}

extern s32 TLobby__sub_8040EF50(u32 *out, u32 mask, s16 c)
{
  s16 n;
  u32 new_var;
  u8 *tbl;
  u8 *new_var2;
  u8 *e;
  s16 i;
  u8 *node;
  u32 m;
  tbl = (u8 *) (&ipv4_address_routing_state);
  if ((c < 0) || (c >= (*((s16 *) (tbl + 0x2)))))
  {
    return -6;
  }
  e = (new_var2 = *((u8 **) (tbl + 0xc)));
  e += c * 0x1c;
  if ((*((s16 *) e)) == 1)
  {
    u32 a = *((u32 *) (e + 0x8));
    m = *((u32 *) (e + 0x14));
    if ((m & a) == (m & mask))
    {
      *out = a;
      return 0;
    }
    node = *((u8 **) (e + 0x18));
    n = *((s16 *) (tbl + 0x4));
    for (i = 0; (node != ((void *) 0)) && (i < n); i++)
    {
      m = *((u32 *) (0x10 + node));
      new_var = *((u32 *) (node + 0x4));
      if ((m & new_var) == (m & mask))
      {
        *out = new_var;
        return 0;
      }
      node = *((u8 **) (node + 0x14));
    }

  }
  return -6;
}

#pragma push
#pragma opt_loop_invariants off
extern s32 TLobby__sub_8040F00C(s16 id, u8 *out, s16 len, s32 arg) {
    u8 *tbl;
    Req_8040F00C s;
    u8 *e;
    s32 k;
    s32 count;
    u8 *node;
    s16 r;
    extern void TLobby__sub_80406EB8(void *, int);
    extern void set_value_and_enable(void *, s32);
    tbl = (u8 *)&ipv4_address_routing_state;

    if (id < 0 || id >= *(s16 *)(tbl + 2)) {
        return -0x109;
    }
    e = *(u8 **)(tbl + 0xc);
    e += id * 0x1c;
    if (*(s16 *)e != 1) {
        return -2;
    }
    if ((u32)len < 0x1c) {
        return -2;
    }
    s.flags = 4;
    s.a = *(u32 *)(e + 0x8);
    s.b = *(u32 *)(e + 0x14);
    s.c = *(u32 *)(e + 0xc);
    set_value_and_enable(s.head, (s32)&s.flags);
    TLobby__sub_80406FD8(out, s.head, 0x1c);
    TLobby__sub_80406EB8(out, 0x1c);
    node = *(u8 **)(e + 0x18);
    count = 1;
    k = 0;
    len -= 0x1c;
    while ((u32)len >= 0x1c && node != 0 && (s16)k < *(s16 *)(tbl + 4)) {
        s.flags = 4;
        s.a = *(u32 *)(node + 0x4);
        s.b = *(u32 *)(node + 0x10);
        s.c = *(u32 *)(node + 0x8);
        set_value_and_enable(s.head, (s32)&s.flags);
        TLobby__sub_80406FD8(out, s.head, 0x1c);
        TLobby__sub_80406EB8(out, 0x1c);
        node = *(u8 **)(node + 0x14);
        count++;
        k++;
        len -= 0x1c;
    }
    r = TLobby__sub_80409EB0(id, *(s16 *)(e + 0x2));
    if (r <= 6) {
        TLobby__sub_80409E18(id, *(s16 *)(e + 0x2), arg);
    }
    return count;
}
#pragma pop

extern s32 TLobby__sub_8040F1A0(s16 id) {
    G_8040F1A0 *g;
    s16 *pn;
    B_8040F1A0 **pb;
    s16 cnt;
    B_8040F1A0 *b;
    Nd_8040F1A0 *nd;
    u32 addr;
    s16 is_socket_flag_set(s16);
    g = (G_8040F1A0 *)&ipv4_address_routing_state;

    if (id < 0 || id >= *(pn = &g->nB)) {
        return -0x109;
    }
    b = *(pb = &g->b);
    b += id;
    if (b->flags != 1) {
        return 0;
    }
    nd = b->nodes;
    cnt = 0;
    while (nd != NULL && cnt < g->nC) {
        if (is_socket_flag_set(id) == 0 && getfirst_8040F1A0(pn, pb, &addr)) {
            drop_8040F1A0(g, nd->f4, addr);
        }
        TLobby__sub_80409D7C(id, b->f2, 2, (s32)&nd->f4);
        {
            Nd_8040F1A0 *next = nd->next;
            nd->f0 = 0;
            nd->f4 = 0;
            nd->fc = 0;
            nd->f8 = 0;
            nd->f10 = 0;
            nd->next = NULL;
            cnt++;
            nd = next;
        }
    }
    if (is_socket_flag_set(id) == 0 && getfirst_8040F1A0(pn, pb, &addr)) {
        drop_8040F1A0(g, b->f8, addr);
    }
    {
        A_8040F1A0 *e;
        s16 n;
        n = g->nA;
        e = g->a;
        for (; n > 0; n--, e++) {
            if ((e->flags & 1) && e->id == id) {
                e->flags = 0;
            }
        }
    }
    call_entry_callback(id, b->f2);
    b->flags = 0;
    b->f2 = 0;
    b->f4 = 0;
    b->f8 = 0;
    b->f10 = 0;
    b->fc = 0;
    b->f14 = 0;
    b->nodes = NULL;
    return 0;
}

#pragma push
#pragma opt_common_subs on
extern s16 TLobby__sub_8040F454(u32 addr, u32 mask, u32 broadcast, s16 idx) {
    G_8040F1A0 *g = (G_8040F1A0 *)&ipv4_address_routing_state;
    s16 *pn;
    B_8040F1A0 **pifs;
    s16 unspecified;
    B_8040F1A0 *ifc;
    s16 r;
    s16 err;
    s16 found;
    u32 gateway;
    s16 is_socket_flag_set(s16);
    s16 invoke_socket_callback(s16, s32);
    s16 TLobby__sub_8040A044(s16, u32, s32, u32 *);

    if (idx < 0 || idx >= *(pn = &g->nB)) {
        return -0x109;
    }
    ifc = *(pifs = &g->b);
    ifc += idx;
    if (ifc->flags == 1) {
        return -2;
    }
    ifc->flags = 1;
    ifc->f2 = TLobby__sub_8040A044(idx, 0x800, 4, &addr);
    if (ifc->f2 < 0) {
        ifc->flags = 0;
        return ifc->f2;
    }
    if (addr == 0 && mask == 0xFFFFFFFF) {
        unspecified = 1;
    } else {
        unspecified = 0;
    }
    ifc->f8 = addr;
    ifc->f10 = addr & mask;
    if (broadcast != 0) {
        ifc->fc = broadcast;
    } else {
        ifc->fc = ifc->f10 | ~mask;
    }
    ifc->f14 = mask;
    r = invoke_socket_callback(idx, ifc->f2);
    if (r < g->f6) {
        ifc->flags = 0;
        return -6;
    }
    ifc->f4 = r;
    found = 0;
    ifc->nodes = NULL;
    gateway = 0xFFFFFFFF;
    if (is_socket_flag_set(idx) == 0 && !unspecified) {
        found = getfirst_8040F1A0(pn, pifs, &gateway);
        if (found) {
            found = TRKValidMemory32(addr, 0xFFFFFFFF, gateway, 0, 1, 0);
            if (found < 0) {
                call_entry_callback(idx, ifc->f2);
                ifc->flags = 0;
                ifc->f2 = 0;
                ifc->f4 = 0;
                ifc->f8 = 0;
                ifc->f10 = 0;
                ifc->fc = 0;
                ifc->f14 = 0;
                return found;
            }
        }
    }
    err = TRKValidMemory32(addr & mask, mask, addr, 0, 1, 0);
    if (err < 0) {
        if (is_socket_flag_set(idx) == 0 && gateway != 0xFFFFFFFF && !unspecified) {
            drop_8040F1A0(g, addr, gateway);
        }
        call_entry_callback(idx, ifc->f2);
        ifc->flags = 0;
        ifc->f2 = 0;
        ifc->f4 = 0;
        ifc->f8 = 0;
        ifc->f10 = 0;
        ifc->fc = 0;
        ifc->f14 = 0;
        return err;
    }
    return 0;
}
#pragma pop
s32 is_lookup_found(u32 arg0, u32 arg1) {
    if (TLobby__sub_8040F76C(arg0, arg1) != NULL) {
        return 1;
    }
    return 0;
}

u8 * TLobby__sub_8040F76C(a0, a1)
u32 a0;
u32 a1;
{
    u32 t;
    u16 flags;
    s16 i;
    u8 *e;
    u8 *m1;
    u8 *m2;
    u8 *m3;

    m1 = NULL;
    m2 = NULL;
    m3 = NULL;
    e = *(u8 **)((s8 *)&ipv4_address_routing_state + 8);
    for (i = 0; i < *(s16 *)&ipv4_address_routing_state; i++, e += 0x14) {
        flags = *(u16 *)e;
        t = a0 & *(u32 *)(e + 8);
        if (!(flags & 1)) {
            continue;
        }
        if ((flags & 4) && *(u32 *)(e + 4) == a0) {
            return e;
        }
        if ((flags & 8) && *(s16 *)(e + 0x12) == 1) {
            if (a0 == 0xFFFFFFFF || a0 == 0) {
                if (*(u32 *)(e + 0xC) == a1) {
                    m1 = e;
                    continue;
                }
            } else if (*(u32 *)(e + 4) == t) {
                m1 = e;
                continue;
            }
        }
        if (!(flags & 2)) {
            continue;
        }
        if (*(u32 *)(e + 4) == 0) {
            if (m3 == NULL) {
                m3 = e;
            }
        } else if (*(u32 *)(e + 4) == t) {
            if (m2 == NULL) {
                m2 = e;
            }
        }
    }
    if (m1 != NULL) {
        return m1;
    }
    if (m2 != NULL) {
        return m2;
    }
    if (m3 != NULL) {
        return m3;
    }
    return NULL;
}

s16 TRKValidMemory32(u32, u32, u32, s16, u8, u16);
s16 TRKValidMemory32(u32, u32, u32, s16, u8, u16);
extern s32 TLobby__sub_8040F8A4(u32 a1, void *a2, u32 a3, u32 a4, u32 a5)
{
  RtTbl_8040F8A4 *tbl = (RtTbl_8040F8A4 *) (&ipv4_address_routing_state);
  u32 new_var;
  u16 f;
  s16 i;
  s16 found = 0;
  RtEntry_8040F8A4 *e;
  s16 TRKValidMemory32(void *, void *, void *, int, int, int);
  for (i = 0, e = tbl->entries; i < tbl->count; i++, e++)
  {
    if (!(e->flags & 1))
    {
      continue;
    }
    if (e->owner != a5)
    {
      continue;
    }
    new_var = e->id;
    if (new_var == 0)
    {
      a4 |= 2;
      found = 1;
      continue;
    }
    f = (u16) a4;
    if (a4 & 4)
    {
      if (((!e->flags) & 4) || (new_var != a1))
      {
        continue;
      }
      e->flags = f | 0x20;
      e->owner = (u32) a2;
      return 0;
    }
    if (e->flags & 4)
    {
      continue;
    }
    if ((a1 & e->mask) != (new_var & a3))
    {
      continue;
    }
    e->flags = f | 0x10;
    e->owner = (u32) a2;
    return 0;
  }

  if (found != 0)
  {
    if (TRKValidMemory32((void *) a1, (void *) a3, a2, 1, 2, a4) != 0)
    {
      return -1;
    }
  }
  return 0;
}

extern s32 TLobby__sub_8040F9CC(void *a, void *unused, void *b, s32 flag) {
    p8040B8B4_Unk805BDD60 *tbl = (p8040B8B4_Unk805BDD60 *)&ipv4_address_routing_state;
    Unk805BDD60Entry *e = tbl->entriesA;
    s16 i;
    u8 f = (u8)flag & 1;
    for (i = 0; i < tbl->countA; i++, e++) {
        if (!(e->flags & 1)) {
            continue;
        }
        if (e->f4 != (u32)a) {
            continue;
        }
        if (e->fC != (u32)b) {
            continue;
        }
        if (f != (e->f12 & 1)) {
            continue;
        }
        e->flags = 0;
        return 0;
    }
    return -2;
}

#pragma push
#pragma dont_inline off
#pragma inline_depth(4)
inline s16 trk_find1(u8 *p, s16 cntB, s16 cntC, u32 a)
{
    u8 *node;
    s16 i;
    s16 j;

    for (i = 0; i < cntB; i++, p += 0x1c) {
        if (*(s16 *)p == 1) {
            if (*(u32 *)(p + 8) == a) {
                return i;
            }
            node = *(u8 **)(p + 0x18);
            j = 0;
            while (node != 0 && j < cntC) {
                if (*(u32 *)(node + 4) == a) {
                    return i;
                }
                node = *(u8 **)(node + 0x14);
                j++;
            }
        }
    }
    return -1;
}

inline s16 trk_find2(u8 *p, s16 cntB, s16 cntC, u32 a)
{
    u8 *node;
    s16 i;
    s16 j;

    for (i = 0; i < cntB; i++, p += 0x1c) {
        if (*(s16 *)p == 1) {
            if (*(u32 *)(p + 0x10) == (*(u32 *)(p + 0x14) & a)) {
                return i;
            }
            node = *(u8 **)(p + 0x18);
            j = 0;
            while (node != 0 && j < cntC) {
                if (*(u32 *)(node + 0xC) == (*(u32 *)(node + 0x10) & a)) {
                    return i;
                }
                node = *(u8 **)(node + 0x14);
                j++;
            }
        }
    }
    return -1;
}

#pragma pop

#pragma push
#pragma dont_inline off
#pragma inline_depth(4)
#pragma opt_common_subs on
typedef struct Rt_TRK { s16 nroutes; s16 nifaces; s16 max_aliases; s16 pad6; u8 *routes; u8 *ifaces; } Rt_TRK;
inline u8 *getif_TRK(Rt_TRK *g) {
    return g->ifaces;
}

inline s16 byaddr_TRK(u8 *ifaces, s16 n, s16 m, u32 addr) {
    s16 i;
    s16 j;
    u8 *ifc;
    u8 *a;

    ifc = ifaces;

    for (i = 0; i < n; i++, ifc += 0x1c) {
        if (*(s16 *)ifc == 1) {
            if (*(u32 *)(ifc + 8) == addr) {
                return i;
            }
            for (a = *(u8 **)(ifc + 0x18), j = 0; a != NULL && j < m; j++) {
                if (*(u32 *)(a + 4) == addr) {
                    return i;
                }
                a = *(u8 **)(a + 0x14);
            }
        }
    }
    return -1;
}

inline s16 bynet_TRK(u8 *ifaces, s16 n, s16 m, u32 addr) {
    s16 i;
    s16 j;
    u8 *ifc;
    u8 *a;

    ifc = ifaces;

    for (i = 0; i < n; i++, ifc += 0x1c) {
        if (*(s16 *)ifc == 1) {
            if (*(u32 *)(ifc + 0x10) == (*(u32 *)(ifc + 0x14) & addr)) {
                return i;
            }
            for (a = *(u8 **)(ifc + 0x18), j = 0; a != NULL && j < m; j++) {
                if (*(u32 *)(a + 0xC) == (*(u32 *)(a + 0x10) & addr)) {
                    return i;
                }
                a = *(u8 **)(a + 0x14);
            }
        }
    }
    return -1;
}

s16 TRKValidMemory32(u32 dst, u32 mask, u32 gateway, s16 f10, u8 type, u16 flags)
{
    Rt_TRK *g = (Rt_TRK *)&ipv4_address_routing_state;
    u8 *ents;
    s16 m;
    s16 n;
    s16 idx;
    s16 i;
    u8 *e;
    u8 *slot;

    ents = getif_TRK(g);
    m = g->max_aliases;
    n = g->nifaces;
    idx = byaddr_TRK(ents, n, m, gateway);
    if (idx < 0) {
        idx = bynet_TRK(ents, n, m, gateway);
        if (idx < 0) {
            return -2;
        }
    }
    e = g->routes;
    slot = 0;
    for (i = 0; i < g->nroutes; i++, e += 0x14) {
        if (*(u16 *)e & 1) {
            if (*(u32 *)(e + 4) == dst && (dst != 0 || mask != 0 || gateway != 0 || type != 1)) {
                return -2;
            }
        } else {
            slot = e;
            break;
        }
    }
    if (slot == 0) {
        return -0x107;
    }
    *(u32 *)(slot + 4) = dst;
    *(u32 *)(slot + 0xC) = gateway;
    *(u16 *)(slot + 0x12) = type;
    *(s16 *)(slot + 0x10) = f10;
    *(s16 *)(slot + 2) = idx;
    switch (type) {
    case 1:
        if (mask == 0xFFFFFFFF) {
            *(u16 *)slot = 0xD;
        } else {
            *(u16 *)slot = 9;
        }
        *(u32 *)(slot + 8) = mask;
        break;
    case 2:
        *(u16 *)slot = flags | 1;
        if (flags & 4) {
            *(u32 *)(slot + 8) = 0xFFFFFFFF;
        } else {
            *(u32 *)(slot + 8) = mask;
        }
        break;
    case 3:
        *(u16 *)slot = 0xB;
        *(u32 *)(slot + 8) = mask;
        break;
    default:
        if (mask == 0xFFFFFFFF) {
            *(u16 *)slot = 0xF;
        } else {
            *(u16 *)slot = 0xB;
        }
        *(u32 *)(slot + 8) = mask;
        break;
    }
    return 0;
}
#pragma pop

typedef struct A_RT { u8 pad0[4]; u32 addr; u8 pad8[8]; u32 mask; A_RT *next; } A_RT;
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

typedef struct Ent_8040FDA0 { s16 state; u8 pad2[6]; u32 f8; u32 fC; u8 pad10[0xC]; } Ent_8040FDA0;
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

s32 NetIPv4IsUnspecified(u32 arg0) {
    if (arg0 == 0U) {
        return 1;
    }
    return 0;
}

#pragma push
#pragma opt_common_subs on
s32 TLobby__sub_8040FE40(s16 arg0) {
    typedef struct Fields_var_r3 { s16 field_0; } Fields_var_r3;
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
s16 *get_active_entry_by_index(s16 arg0) {
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

s32 TLobby__sub_8040FEE4(s32 arg0, s32 arg1) {
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
s32 NetIPv6Shutdown(void) {
    release_slot_by_id(0x86DD);
    TLobby__sub_803F87DC((void *)((void *) (&ipv6_protocol_state.value)));
    ipv6_protocol_state.value = 0;
    return 0;
}

s32 TLobby__sub_8040FFF8(u8 *ip, int len, s16 id);
s32 NetIPv6Init(void) {
    s16 i;
    E_8040FF58 *e;
    RecoveredGlobal_8040FF0C_lbl_805C1B78 *g = &ipv6_protocol_state;

    init_ipv6_interface_config((NetIpv6IfCfg *)((Obj_803F87E0 *)&g->value));
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
    register_protocol_handler(0x86DD, (Handler_8041A130)TLobby__sub_8040FFF8);
    return 0;
}

#pragma push
#pragma dont_inline off
#pragma inline_depth(4)
inline s16 opts_8040FFF8(u8 *p, s16 rem, u8 *ip, s16 m, s16 id) {
    s16 TLobby__sub_80410958(u8 *, s16, u8 *, s16, s16);
    s16 n;
    u8 *d;
    d = p + 2;
    n = ((p[1] + 1) << 3) - 2;
    if (n > rem) {
        return -1;
    }
    if (TLobby__sub_80410958(d, n, ip, m, id) < 0) {
        return -1;
    }
    return 0;
}

struct IC_8040FFF8 { u8 type; u8 code; s32 w; };
inline u8 *frag_8040FFF8(u8 *ip, u8 *p, s32 rem, s16 m, s16 id, void *sa, struct IC_8040FFF8 *ic) {
    s32 TLobby__sub_8040D510(void *, u8 *, s32, s16);
    s32 TLobby__sub_80418C40(u8 *, u8 *, s16, u8, u32, void *, u16, u8, s16);
    u32 fl;
    u32 mf;
    u32 off;
    fl = *((u16 *) (p + 2));
    mf = fl & 1;
    off = (fl >> 3) & 0x1FFF;
    if (((u8) fl & 1) && (((rem - 8) & 7) != 0)) {
        if (off == 0) {
            ic->type = 4;
            ic->code = 0;
            ic->w = 4;
            TLobby__sub_8040D510(ic, ip, m, id);
        }
        return 0;
    }
    return (u8 *) TLobby__sub_80418C40(ip, (u8 *) (m - (rem - 8)), rem - 8, 60, *((u32 *) (p + 4)), sa, off, mf, id);
}
inline s32 min_8040FFF8(s32 a, s32 b) {
    if (a < b) {
        return a;
    }
    return b;
}

inline u8 *buildrec_8040FFF8(u8 *ip, s16 m, u8 *p, s32 rem) {
    u8 *rec = alloc_free_entry();
    if (rec == 0) {
        return 0;
    }
    *(s32 *)(rec + 4) = 0;
    *(s32 *)(rec + 8) = m;
    ((struct { u16 v; u8 pad[10]; } *)(rec + 0xc))[*(s32 *)(rec + 4)].v = m - rem;
    set_value_and_enable(rec + 0x10 + *(s32 *)(rec + 4) * 12, (s32)ip);
    *(s32 *)(rec + 4) += 1;
    ((struct { u16 v; u8 pad[10]; } *)(rec + 0xc))[*(s32 *)(rec + 4)].v = rem;
    set_value_and_enable(rec + 0x10 + *(s32 *)(rec + 4) * 12, (s32)p);
    *(s32 *)(rec + 4) += 1;
    return rec;
}

#pragma push
#pragma opt_loop_invariants off
s32 TLobby__sub_8040FFF8(u8 *ip, int len, s16 id)
{
  s32 TLobby__sub_8040D510(void *, u8 *, s32, s16);
  s16 TLobby__sub_804105E0(u8 *, u8 *, s16, s16);
  s32 TLobby__sub_80418C40(u8 *, u8 *, s16, u8, u32, void *, u16, u8, s16);
  s16 TLobby__sub_804136CC(s16);
  s16 TLobby__sub_804136EC(void *);
  s16 NetIPv6IsMulticast(void *);
  s16 NetIPv6IsUnspecified(void *);
  s16 NetIPv6CompareAddresses(void *, void *);
  s16 NetIPv6HandleIcmpMessage(u8 *, u8 *, u8 *, u8, s16);
  s16 TLobby__sub_8041B974(void *, void *, void *);
  s16 udp_input(void *, void *, void *, s16);
  void TLobby__sub_80421938(void *, void *, void *, u32, s16);
  s32 TUdpSocket__sub_80418BD8(A_80418BD8 *);
  struct 
  {
    s32 t;
    u8 a[16];
  } sa;
  struct 
  {
    s32 t;
    u8 a[16];
  } da;
  struct 
  {
    u8 type;
    u8 code;
    s32 w;
  } ic44;
  struct 
  {
    u8 type;
    u8 code;
    s32 w;
  } ic36;
  struct IC_8040FFF8 ic28;
  u8 *p;
  u8 *new_var2;
  u8 *rec;
  s16 m;
  u8 *ent;
  s16 i;
  s32 rem;
  u8 *new_var4;
  u8 *new_var3;
  s16 new_var;
  s16 res;
  u8 *last;
  s16 reasm;
  u8 *g;
  u8 *src;
  u8 nh;
  s16 r;
  s16 found;
  u8 *dst;
  new_var = id;
  if (((s16) len) < 40)
  {
    goto ret;
  }
  if (get_valid_entry(new_var) == 0)
  {
    goto ret;
  }
  if ((ip[0] & 0xF0) != 0x60)
  {
    return -1;
  }
  m = min_8040FFF8((*((u16 *) (ip + 4))) + 40, (s16) len);
  if (TLobby__sub_804136CC(new_var) == 0)
  {
    if (TLobby__sub_804136EC(ip + 24) < ((char) 0))
    {
      if (NetIPv6IsMulticast(ip + 24) == 0)
      {
        if (TLobby__sub_804105E0(ip, ip, m, new_var) == 0)
        {
          return 0;
        }
        return -1;
      }
    }
  }
  sa.t = 6;
  new_var3 = ip + 8;
  src = sa.a;
  NetMemcpy(src, new_var3, 16);
  da.t = 6;
  dst = da.a;
  NetMemcpy(dst, ip + 24, 16);
  nh = ip[6];
  rem = m - 40;
  new_var2 = ip;
  p = new_var2 + 40;
  last = new_var2 + 6;
  reasm = 0;
  new_var4 = dst;
  found = 0;
  for (;;)
  {
    if (nh == 59)
    {
      return 0;
    }
    if (((s16) rem) < 8)
    {
      ic44.type = 4;
      ic44.code = 1;
      ic44.w = last - new_var2;
      TLobby__sub_8040D510(&ic44, new_var2, m, new_var);
      goto ret;
    }
    switch (nh)
    {
      case 0:
        if (m != (((s16) rem) + 40))
      {
        ic36.type = 4;
        ic36.code = 1;
        ic36.w = last - new_var2;
        TLobby__sub_8040D510(&ic36, new_var2, m, new_var);
        res = -1;
      }
      else
      {
        res = opts_8040FFF8(p, rem, new_var2, m, new_var);
      }
        if (res < 0)
      {
        goto ret;
      }
        goto adv;

      case 1:

      case 4:

      case 50:

      case 51:

      case 44:
        rec = frag_8040FFF8(new_var2, p, rem, m, new_var, &sa, &ic28);
        if (rec == 0)
      {
        return -1;
      }
        nh = p[0];
        reasm = 1;
        goto payload;

      case 60:
        res = opts_8040FFF8(p, rem, new_var2, m, new_var);
        if (res < 0)
      {
        goto ret;
      }

      case 43:
        adv:
      last = p;

        nh = p[0];
        rem -= (p[1] + 1) << 3;
        p += (p[1] + 1) << 3;
        continue;

      case 10:

      case 20:

      case 30:

      case 40:
        break;

    }

    break;
  }

  payload:
  if (reasm == 0)
  {
    rec = buildrec_8040FFF8(new_var2, m, p, rem);
    if (rec == 0)
    {
      return -257;
    }
  }

  switch (nh)
  {
    case 58:
      r = NetIPv6HandleIcmpMessage(rec, src, dst, new_var2[7], new_var);
      if (r < 0)
    {
      goto fail;
    }
      found = 1;
      break;

    case 6:
      r = TLobby__sub_8041B974(rec, &sa, &da);
      if (r < 0)
    {
      goto fail;
    }
      goto ok;

    case 17:
      r = udp_input(rec, &sa, &da, new_var);
      if (r >= 0)
    {
      goto ok;
    }
      switch (r)
    {
      case -2:
        ic44.type = 1;
        ic44.code = 4;
        ic44.w = 0;
        TLobby__sub_8040D510(&ic44, new_var2, m, new_var);
        goto fail;

      default:
        goto fail;

    }


    default:
      break;

  }

  g = (u8 *) (&ipv6_protocol_state);
  ent = *((u8 **) (g + 4));
  for (i = 0; i < (*((s16 *) g)); i++)
  {
    if ((((*((u16 *) (ent + 4))) == 1) && (ent[48] == nh)) && ((*((u32 *) (ent + 40))) != 0))
    {
      if ((NetIPv6IsUnspecified(ent + 6) != 0) || (NetIPv6CompareAddresses(ent + 6, src) == 0))
      {
        if ((NetIPv6IsUnspecified(ent + 22) != 0) || (NetIPv6CompareAddresses(ent + 22, new_var4) == 0))
        {
          TLobby__sub_80421938(rec, src, dst, *((u32 *) (ent + 40)), i);
          found = 1;
        }
      }
    }
    ent += 52;
  }

  if (found == 1)
  {
    ok:
    if (reasm == 1)
    {
      TUdpSocket__sub_80418BD8((A_80418BD8 *) rec);
    }

    release_entry(rec);
    return 0;
  }
  if (reasm != 1)
  {
    ic44.type = 4;
    ic44.code = 1;
    ic44.w = last - new_var2;
    TLobby__sub_8040D510(&ic44, new_var2, m, new_var);
  }
  fail:
  if (reasm == 1)
  {
    TUdpSocket__sub_80418BD8((A_80418BD8 *) rec);
  }

  release_entry(rec);
  ret:
  return -1;

}
#pragma pop
#pragma pop

extern s32 TLobby__sub_80410958(u8* p, s16 n, u8* self, s16 c, s16 d);
extern s32 TLobby__sub_80410958(u8* p, s16 n, u8* self, s16 c, s16 d);
#pragma push
#pragma dont_inline off
#pragma inline_depth(4)
static inline s16 chk_804105E0(u8 *p, s16 lim, s16 ctx, s16 l, s16 rem, u8 *q, u8 *prev) {
    s16 TLobby__sub_80410958(u8 *, s16, u8 *, s16, s16);
    u8 err4[8];
    s32 n;
    u8 *d;
    if (l != rem + 0x28) {
        err4[0] = 4;
        err4[1] = 1;
        *(s32 *)(err4 + 4) = prev - p;
        TLobby__sub_8040D510(err4, p, lim, ctx);
        return -1;
    }
    d = q + 2;
    n = ((q[1] + 1) << 3) - 2;
    if ((s16)n > rem) {
        return -1;
    }
    if (TLobby__sub_80410958(d, n, p, lim, ctx) < 0) {
        return -1;
    }
    return 0;
}
#pragma pop
#pragma push
#pragma opt_common_subs on
#pragma opt_propagation off
extern s32 TLobby__sub_804105E0(u8 *self, u8 *p, s16 lim, s16 ctx)
{
  s32 TLobby__sub_80410BA8(void *, void *, s16, void *);
  s32 TLobby__sub_80415D0C(u8 *a, u8 *b, u8 *c, s16 d);
  s16 NetIPv6IsMulticast(void *);
  s16 TLobby__sub_804136AC(s16);
  u8 loc[8];
  u8 out2[0x10];
  u8 out1[0x10];
  u8 err[8];
  s32 tot;
  u8 *e;
  s16 rem;
  u8 *q;
  u8 *hit;
  u8 *new_var;
  u8 *prev;
  s16 l;
  s16 flag;
  s16 h6;
  u16 flags;
  u8 state;
  u8 *dst;
  s32 adv;
  s32 r21;
  l = lim;
  tot = l - 0x28;
  new_var = &loc[6];
  rem = tot;
  q = p + 0x28;
  prev = p + 6;
  flag = 0;
  *((s32 *) loc) = *((s32 *) self);
  *((u16 *) (loc + 4)) = *((u16 *) self);
  loc[7] = self[6];
  state = self[7];
  loc[6] = state;
  state = self[6];
  while (rem >= 8)
  {
    switch (state)
    {
      case 0:
        if (chk_804105E0(p, lim, ctx, l, rem, q, prev) < 0)
      {
        return -1;
      }
        prev = q;
        state = q[0];
        adv = (q[1] + 1) << 3;
        rem -= adv;
        q += adv;
        break;

      case 0x2c:
        flags = (*((u16 *) (q + 2))) & 0xFFF8;
        flag = 1;

      default:
        rem = 0;
        break;

    }

  }

  if (((*new_var) == 0) || ((--loc[6]) == 0))
  {
    if ((flag == 0) || (flags == 0))
    {
      err[0] = 3;
      err[1] = 0;
      *((s32 *) (err + 4)) = 0;
      TLobby__sub_8040D510(err, p, lim, ctx);
    }
    return -1;
  }
  hit = TLobby__sub_80413264(self + 0x18, (s32) (self + 8));
  if (hit == ((void *) 0))
  {
    if ((flag == 0) || (flags == 0))
    {
      err[0] = 1;
      err[1] = 0;
      *((s32 *) (err + 4)) = 0;
      TLobby__sub_8040D510(err, p, lim, ctx);
    }
    return -1;
  }
  switch (*((s16 *) (hit + 2)))
  {
    case 1:
      dst = self + 0x18;
      break;

    case 2:

    case 3:
      dst = hit + 0x18;
      break;

  }

  if (lim > (h6 = get_entry_field_26(*((s16 *) (hit + 6)))))
  {
    if ((flag == 0) || (flags == 0))
    {
      err[0] = 2;
      err[1] = 0;
      *((s32 *) (err + 4)) = h6;
      TLobby__sub_8040D510(err, p, lim, ctx);
    }
    return -1;
  }
  e = alloc_free_entry();
  if (e == ((void *) 0))
  {
    return -1;
  }
  *((s32 *) (e + 4)) = 0;
  *((s32 *) (e + 8)) = tot;
  ((struct 
  {
    s16 v;
    u8 pad[10];
  } *) (e + 0xc))[*((s32 *) (e + 4))].v = (s16) tot;
  set_value_and_enable((void *) ((e + ((*((s32 *) (e + 4))) * 12)) + 0x10), (s32) (p + 0x28));
  *((s32 *) (e + 4)) = (*((s32 *) (e + 4))) + 1;
  NetMemcpy(out1, self + 8, 0x10);
  NetMemcpy(out2, self + 0x18, 0x10);
  if ((NetIPv6IsMulticast(dst) == 0) && (TLobby__sub_804136AC(*((s16 *) (hit + 6))) != 0))
  {
    r21 = TLobby__sub_80415D0C(e, dst, out1, *((s16 *) (hit + 6)));
  }
  else
  {
    r21 = TLobby__sub_80410BA8(e, out1, *((s16 *) (hit + 6)), 0);
  }
  release_entry((void *) e);
  return r21;
}
#pragma pop
s32 NetIPv6IsMulticast(u8* address);
#pragma push
#pragma cplusplus off
#pragma dont_inline off
#pragma inline_depth(4)
#pragma optimize_for_size off
#pragma dont_inline off
s32 TLobby__sub_80410958(u8* p, s16 n, u8* self, s16 c, s16 d) {
    s16 NetIPv6IsMulticast(void*);
    s32 TLobby__sub_8040D510(void*, u8*, s16, s16);
    u8* cur = p;
    s32 len;

    while (n > 0) {
        switch (*cur) {
        case 0:
            n--;
            cur++;
            break;
        case 1:
            len = cur[1] + 2;
            n -= len;
            cur += len;
            break;
        default:
            switch (*cur & 0xC0) {
            case 0x00:
                len = cur[1] + 2;
                n -= len;
                cur += len;
                break;
            case 0xC0:
                if (NetIPv6IsMulticast(self + 0x18)) {
                    return -1;
                }
                /* fallthrough */
            case 0x80: {
                struct {
                    u8 a;
                    u8 b;
                    u8 pad[2];
                    u32 c;
                } msg;

                msg.a = 4;
                msg.b = 2;
                msg.c = cur - self;
                TLobby__sub_8040D510(&msg, self, c, d);
            }
            case 0x40:
            default:
                return -1;
            }
            break;
        }
    }
    if (n != 0) {
        return -1;
    }
    return 0;
}
#pragma pop

extern s16 TLobby__sub_80415D0C(Pkt_804179A4 *a, u8 *b, Sock_804179A4 *c, s16 d);
extern s16 TLobby__sub_80415D0C(Pkt_804179A4 *a, u8 *b, Sock_804179A4 *c, s16 d);
extern s16 TLobby__sub_80415D0C(Pkt_804179A4 *a, u8 *b, Sock_804179A4 *c, s16 d);
s32 TLobby__sub_80410A98(s32 arg0, void *arg1, void *arg2, void *arg3, void *arg4)
{
    s32 TLobby__sub_80410BA8(void *, void *, s16, void *);
  u8 tmp[12];
  volatile struct 
  {
    s32 x;
    s16 h;
    u8 y;
    u8 d;
  } rec;
  u8 *new_var;
  u8 buf2[16];
  u8 buf1[16];
  u8 *p;
  u8 *q;
  s16 NetIPv6IsMulticast(u8 *);
  s16 TLobby__sub_804136AC(s16);
  s32 TLobby__sub_80415D0C(Pkt_804179A4 *, u8 *, Sock_804179A4 *, s16);
  p = (u8 *) TLobby__sub_80413264(arg1, (s32) arg2);
  if (p == ((void *) 0))
  {
    return -6;
  }
  if ((*((s16 *) (p + 2))) == 1)
  {
    q = (u8 *) arg1;
  }
  else
  {
    q = p + 0x18;
  }
  if (arg3 == ((void *) 0))
  {
    NetMemset(tmp, 0, 0xc);
    arg3 = tmp;
  }
  rec.x = *((s32 *) (((u8 *) arg3) + 4));
  new_var = q;
  rec.h = ((u8 *) arg3)[0];
  rec.y = ((u8 *) arg3)[8];
  rec.d = (u8) ((s32) arg4);
  NetMemcpy(buf1, arg2, 0x10);
  NetMemcpy(buf2, arg1, 0x10);
  if ((!NetIPv6IsMulticast(q)) && TLobby__sub_804136AC(*((s16 *) (p + 6))))
  {
    return TLobby__sub_80415D0C((Pkt_804179A4 *) arg0, new_var, (Sock_804179A4 *) buf1, *((s16 *) (p + 6)));
  }
  return TLobby__sub_80410BA8((void *) arg0, buf1, *((s16 *) (p + 6)), (void *) 0);
}

s16 TLobby__sub_80411C44(u8 *self, s16 idx);
s16 TLobby__sub_80410D6C(u8 *ctx, u8 *hdr, s16 a5, s32 a6, u32 len);
s16 TLobby__sub_80410BA8(void *self, void *a, s16 c, void *d)
{
  s16 TLobby__sub_804112B8(s32, s32, s16);
  s16 TLobby__sub_8041123C(s32, s32, s16);
  s16 NetIPv6IsMulticast(void *);
  u8 *base = (u8 *) (&ipv6_protocol_state);
  s32 new_var;
  u32 used = *((u32 *) (((u8 *) self) + 8));
  u8 *slot = base + 0x18;
  s32 n;
  s32 off;
  s16 ret;
  s32 pad2[2];
  if (used == 0)
  {
    return 0;
  }
  *((u32 *) slot) = 0;
  if (*((u32 *) (((u8 *) a) + 0x20)))
  {
    *((u32 *) slot) = (*((u32 *) (((u8 *) a) + 0x20))) & 0xFFFFF;
  }
  else
  {
    *((u32 *) slot) = *((u32 *) (base + 0x10));
  }
  if (*((u16 *) (((u8 *) a) + 0x24)))
  {
    *((u16 *) slot) |= (*((u16 *) (((u8 *) a) + 0x24))) & 0xFF0;
  }
  else
  {
    *((u16 *) slot) |= *((u16 *) (base + 0xc));
  }
  *((u8 *) slot) = 0x60;
  *((u16 *) (slot + 4)) = used;
  *((u8 *) (slot + 6)) = ((u8 *) a)[0x27];
  if (((u8 *) a)[0x26])
  {
    *((u8 *) (slot + 7)) = ((u8 *) a)[0x26];
  }
  else
  {
    *((u8 *) (slot + 7)) = base[0x14];
  }
  NetMemcpy(slot + 8, a, 16);
  NetMemcpy(slot + 0x18, ((u8 *) a) + 0x10, 16);
  ret = TLobby__sub_80411C44(((u8 *) a) + 0x10, c);
  if (ret < 0)
  {
    return ret;
  }
  n = ret - 0x28;
  *((u32 *) (base + 8)) += 1;
  new_var = n;
  if (used > ((u32) n))
  {
    return TLobby__sub_80410D6C((u8 *) self, slot, c, (s32) d, new_var);
  }
  *((u32 *) (((u8 *) self) + 8)) += 0x28;
  ((struct 
  {
    u16 v;
    u8 pad[10];
  } *) (((u8 *) self) + 0xc))[*((s32 *) (((u8 *) self) + 4))].v = 0x28;
  off = (*((s32 *) (((u8 *) self) + 4))) * 12;
  set_value_and_enable((((u8 *) self) + off) + 0x10, (s32) slot);
  *((s32 *) (((u8 *) self) + 4)) += 1;
  if (NetIPv6IsMulticast(((u8 *) a) + 0x10))
  {
    return TLobby__sub_804112B8((s32) self, (s32) (((u8 *) a) + 0x10), c);
  }
  return TLobby__sub_8041123C((s32) self, (s32) d, c);
}

#pragma push
#pragma opt_common_subs on
extern s16 TLobby__sub_80410D6C(u8 *ctx, u8 *hdr, s16 a5, s32 a6, u32 len)
{
    s16 NetIPv6IsMulticast(void *);
    s16 TLobby__sub_804112B8(s32, s32, s16);
    s16 TLobby__sub_8041123C(s32, s32, s16);
    typedef struct {
        u32 f0;
        s32 n;
        u32 total;
        struct {
            s16 len;
            u8 pad[2];
            u8 data[8];
        } ent[12];
    } Pkt;
    Pkt iov;
    u8 fh[8];
    s16 i;
    s16 k;
    s16 j;
    s32 off;
    s16 rem;
    Pkt *iovp;
    u32 limit;
    Pkt *pc;
    s32 flen;
    u8 *e;
    s16 r;

    pc = (Pkt *)ctx;
    if (len < 8) {
        return -6;
    }
    fh[0] = hdr[6];
    fh[1] = 0;
    *(u16 *)(fh + 2) = 0;
    *(u32 *)(fh + 4) = *(u32 *)((u8 *)&ipv6_protocol_state + 8);
    hdr[6] = 0x2c;
    limit = len - 8;
    limit &= 0xFFF8;
    iovp = &iov;
    off = 0;
    while (pc->total != 0) {
        iov.total = 0;
        iov.n = 0;
        for (i = pc->n - 1; i >= 0; i--) {
            if (iov.total + (flen = pc->ent[i].len) < limit) {
                iov.total += pc->ent[i].len;
                iov.n++;
            } else {
                iov.total = limit;
                iov.n++;
                break;
            }
        }
        k = iov.n - 1;
        j = pc->n - 1;
        rem = iov.total;
        while (k >= 0 && rem > 0) {
            NetMemcpy(iovp->ent[k].data, pc->ent[j].data, 8);
            if (rem < pc->ent[j].len) {
                iovp->ent[k].len = rem;
                pc->total -= rem;
                e = (u8 *)pc + j * 12;
                *(s16 *)(e + 12) -= rem;
                TLobby__sub_80406EB8(e + 16, rem);
                break;
            }
            iovp->ent[k].len = pc->ent[j].len;
            rem -= pc->ent[j].len;
            pc->total -= pc->ent[j].len;
            pc->ent[j].len = 0;
            pc->n--;
            k--;
            j--;
        }
        *(u16 *)(fh + 2) = off & 0xFFF8;
        if (pc->total != 0) {
            *(u16 *)(fh + 2) |= 1;
        }
        off += (s16)iov.total;
        iov.total += 8;
        iovp->ent[iov.n].len = 8;
        set_value_and_enable(iovp->ent[iov.n].data, (s32)fh);
        iov.n++;
        *(u16 *)(hdr + 4) = iov.total;
        iov.total += 40;
        iovp->ent[iov.n].len = 40;
        set_value_and_enable(iovp->ent[iov.n].data, (s32)hdr);
        iov.n++;
        if (NetIPv6IsMulticast(hdr + 24)) {
            r = TLobby__sub_804112B8((s32)iovp, (s32)(hdr + 24), a5);
        } else {
            r = TLobby__sub_8041123C((s32)iovp, a6, a5);
        }
        if (r < 0) {
            break;
        }
    }
    return r;
}
#pragma pop

extern u16 TLobby__sub_80406BD8(void *, s16);
extern void NetMemcpy(void *, void *, int);
extern u16 TUdpSocket__sub_80419864();
#pragma push
#pragma dont_inline off
#pragma inline_depth(4)
extern u16 TLobby__sub_80411040(const struct IPv6Address * p_, const struct IPv6Address * q_, u8 c, const struct NetPacket * d_, s16 e) {
  struct 
  {
    u8 a[0x10];
    u8 b[0x10];
    u32 len;
    u8 f[4];
  } hdr;
  u32 sum;
  NetMemcpy(hdr.a, ((void *)p_), 0x10);
  NetMemcpy(hdr.b, ((void *)q_), 0x10);
  hdr.f[0] = 0;
  hdr.f[1] = 0;
  hdr.f[2] = 0;
  hdr.f[3] = c;
  if (e == 0)
  {
    hdr.len = (u16) ((*((u32 *) (((u8 *) ((void *)d_)) + 0x8))) - (*((s16 *) (((u8 *) ((void *)d_)) + 0xc))));
  }
  else
  {
    hdr.len = (u16) (*((u32 *) (((u8 *) ((void *)d_)) + 0x8)));
  }
  sum = (u16) TUdpSocket__sub_80419864(hdr.a, 0x14);
  sum += (u16) TLobby__sub_80406BD8(((void *)d_), e);
  sum = (sum >> 16) + (sum & 0xffff);
  sum = sum + (sum >> 16);
  return ~sum;
}
#pragma pop

RecoveredGlobal_8040FF0C_lbl_805C1B78 ipv6_protocol_state;
RecoveredGlobal_8040EF00_lbl_805C1B60 ipv4_address_routing_state;
RecoveredGlobal_8040DD68_lbl_805C1B38 ipv4_protocol_state;
G_8040A45C dns_resolver_state;
#undef lbl_805C1AD8
u32 lbl_805C1AD8[6];
