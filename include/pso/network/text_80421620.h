#ifndef PSO_NETWORK_TEXT_80421620_H
#define PSO_NETWORK_TEXT_80421620_H

#include "pso/network/TcpSendQueue.h"

/* text_80421620.c: stack start-up and shutdown. */
#ifdef __cplusplus
extern "C" {
#endif
s16 init_network_stack(void);
s16 tcp_receive(s32 handle, TcpCompletion callback, s32 length, void *buffer);
s32 cleanup_subsystems(void);
/* Complete a TCB's pending operation: wake the waiting thread or run its callback. */
s32 set_slot_state_and_resume(s16 idx, TcpCompletion cb, s16 state);
s32 set_thread_state_and_resume(s32 idx, TcpCompletion cb, s16 state);
s32 complete_request_callback(s16 handle, TcpSendCallback cb, s16 code, const TcpSendRequest *request);
s32 net_unlock(void);
s32 net_lock(void);
s32 net_unregister_timer(s32 timer);
s32 udp_close(s32 a);
s16 TLobby__sub_80423064(s16 idx, s32 op);
#ifdef __cplusplus
}
#endif

#endif
