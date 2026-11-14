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
s32 TLobby__sub_804217E4(void);
s32 TLobby__sub_80421814(void);
s32 TLobby__sub_80421844(s32 timer);
s32 TLobby__sub_80421B3C(s32 a);
s16 TLobby__sub_80423064(s16 idx, s32 op);
#ifdef __cplusplus
}
#endif

#endif
