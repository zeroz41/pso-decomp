#ifndef PSO_NETWORK_TEXT_80421620_H
#define PSO_NETWORK_TEXT_80421620_H

#include "types.h"

/* text_80421620.c: stack start-up and shutdown. */
#ifdef __cplusplus
extern "C" {
#endif
s16 init_network_stack(void);
s32 cleanup_subsystems(void);
/* Complete a TCB's pending operation: wake the waiting thread or run its callback. */
s32 set_slot_state_and_resume(s32 idx, void (*cb)(s16, s16), s16 state);
s32 set_thread_state_and_resume(s32 idx, void (*cb)(s16, s16), s16 state);
s32 complete_request_callback(s32 idx, void (*cb)(s16, s16, s32), s16 code, s32 *extra);
extern volatile s32 dhcp_error;
extern u8 lbl_805D7B1C[6];
extern s16 dhcp_socket;
extern u32 dhcp_lease_time;
extern u32 dhcp_renewal_time;
extern u32 dhcp_rebinding_time;
extern s16 dhcp_iface;
extern s32 lbl_805D7B14;
extern s32 dhcp_max_retries;
extern s32 dhcp_reply_received;
s32 TLobby__sub_804217E4(void);
s32 TLobby__sub_80421814(void);
s32 TLobby__sub_80421844(s32 timer);
s32 TLobby__sub_80421B3C(s32 a);
s16 TLobby__sub_80423064(s16 idx, s32 op);
extern u8 dhcp_hostname[0x2C];
extern u32 lbl_805D7B58;
extern u32 dhcp_last_tick_ms;
extern volatile s32 dhcp_state;
extern u32 lbl_805D7B28;
extern u32 dhcp_elapsed_ms;
extern u32 dhcp_lease_elapsed;
extern volatile s32 dhcp_step;
extern s32 *lbl_805D7B40;
extern s32 *lbl_805D7B44;
extern s32 *lbl_805D7B48;
extern u32 lbl_805D7B4C;
extern u32 lbl_805D7B50;
#ifdef __cplusplus
}
#endif

#endif
