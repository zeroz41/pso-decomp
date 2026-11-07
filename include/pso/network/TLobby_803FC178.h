#ifndef PSO_NETWORK_TLOBBY_803FC178_H
#define PSO_NETWORK_TLOBBY_803FC178_H

#include "types.h"

/* TLobby_803FC178.c: PPP (LCP/IPCP/CHAP/PAP, MD5), the connection state machine and the stack's buffer streams. */
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
#ifdef __cplusplus
}
#endif

#endif
