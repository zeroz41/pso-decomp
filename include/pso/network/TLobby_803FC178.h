#ifndef PSO_NETWORK_TLOBBY_803FC178_H
#define PSO_NETWORK_TLOBBY_803FC178_H

#include "types.h"
#include "pso/network/NetStackTypes.h"

/* TLobby_803FC178.c: PPP (LCP/IPCP/CHAP/PAP, MD5), the connection state machine and the stack's buffer streams. */
typedef struct Blk24_8047FE50 Blk24_8047FE50;
typedef struct UnkSumBuf UnkSumBuf;
typedef struct RecoveredGlobal_803FB110_lbl_805BFF68 RecoveredGlobal_803FB110_lbl_805BFF68;
typedef struct RecoveredGlobal_803AA0C0_lbl_80556E88 RecoveredGlobal_803AA0C0_lbl_80556E88;
typedef struct Sub_803FC480 Sub_803FC480;
typedef struct Obj_803FC480 Obj_803FC480;
typedef struct Buf_803FC684 Buf_803FC684;
typedef struct RecoveredGlobal_803F88E4_lbl_805AEEB0 RecoveredGlobal_803F88E4_lbl_805AEEB0;
typedef struct RecoveredFields_803F88E4_arg0 RecoveredFields_803F88E4_arg0;
typedef struct Hdr_803FC4B4 Hdr_803FC4B4;
struct Blk24_8047FE50 { u32 w[6]; };
struct UnkSumBuf { u8 *data; u16 len; };
struct RecoveredGlobal_803FB110_lbl_805BFF68 {
    s32 value;
    u8 remaining[0xCC];
};
struct RecoveredGlobal_803AA0C0_lbl_80556E88 {
    s32 value;
    u8 remaining[0xFC];
};
struct Sub_803FC480 { u8 f0; u8 f1; u8 f2; u8 f3; u8 f4; };
struct Obj_803FC480 { u8 f0; u8 f1; u8 f2; u8 pad3[0x9D]; Sub_803FC480 sub; };
struct Buf_803FC684 { char a[0x80]; char b[0x80]; u8 rest[0x50]; };
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
typedef char RecoveredGlobal_803F88E4_lbl_805AEEB0_size[((sizeof(RecoveredGlobal_803F88E4_lbl_805AEEB0)) == 0x49C8) ? (1) : (-1)];
typedef char RecoveredGlobal_803AA0C0_lbl_80556E88_size[sizeof(RecoveredGlobal_803AA0C0_lbl_80556E88) == 0x100 ? 1 : -1];
typedef char RecoveredGlobal_803FB110_lbl_805BFF68_size[sizeof(RecoveredGlobal_803FB110_lbl_805BFF68) == 0xD0 ? 1 : -1];
struct Hdr_803FC4B4 { u8 type; u8 flag; s16 len; };
#ifdef __cplusplus
extern "C" {
#endif
u8 *alloc_from_buffer(void *self, s16 arg1);
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
extern u8 lbl_805E1170;
extern u32 lbl_8047FE18[9];
extern Blk24_8047FE50 lbl_8047FE50;
extern u8 lbl_805D7AC0[2];
extern u8 lbl_805D7AC4[1];
extern s16 lbl_805D7A7A;
extern u8 lbl_8047FDE0[];
extern u8 lbl_8047FDF0[];
extern s16 lbl_805D7A7E;
extern s32 lobby_timer_list_head;
extern s16 lobby_handler_table_desc;
extern s32 lbl_8047FEB8[];
extern s32 lbl_8047FEC8[];
extern s16 lbl_805D7A7C;
extern s32 lbl_805D7A90;
extern u8 lcp_read_value_buffer[4];
extern u8 lbl_805D7AA8[4];
extern u8 lobby_read_byte_buffer[1];
extern u8 lcp_read_byte_buffer;
extern s16 lobby_modem_connect_state;
extern s16 lbl_805D7A80;
extern s16 lbl_805D7A82;
extern Buf_803FC684 lbl_805C0180;
extern u8 lbl_805E1160;
extern u8 lbl_8047FE08[];
extern s32 lbl_805E1168;
extern u16 lbl_805D7A9A;
extern u8 lbl_805D7A98;
s16 TLobby__sub_803FC1CC(Conn_804004DC *c, s32 timeout);
s32 TLobby__sub_803FC684(u8 *arg0, u8 *arg1, u8 *arg2);
void TLobby__sub_803FC728(Conn_804004DC *c);
s16 TLobby__sub_803FC820(Conn_804004DC *c, u8 *hdr, int v);
void TLobby__sub_803FCC10(void *self_, void *src_, int v);
#ifdef __cplusplus
}
#endif

#endif
