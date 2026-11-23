#ifndef PSO_NETWORK_TEXT_80421620_H
#define PSO_NETWORK_TEXT_80421620_H

#include "pso/network/TcpSendQueue.h"
#include "pso/network/NetworkReceiveCallback.h"
#include "pso/network/NetworkTimer.h"

/* text_80421620.c: stack start-up and shutdown. */
#ifdef __cplusplus
extern "C" {
#endif
struct NetPacket;
s32 raw_socket_deliver(struct NetPacket *pkt, u8 *src, u8 *dst, NetworkReceiveCallback cb, s16 index);
s32 raw_socket_deliver_ipv4(struct NetPacket *pkt, u32 src, u32 dst, NetworkReceiveCallback cb, s16 index);
s16 avetcp_init(void);
s16 tcp_receive(s32 handle, TcpCompletion callback, s32 length, void *buffer);
s32 avetcp_term(void);
/* Complete a TCB's pending operation: wake the waiting thread or run its callback. */
s32 set_slot_state_and_resume(s16 idx, TcpCompletion cb, s16 state);
s32 set_thread_state_and_resume(s32 idx, TcpCompletion cb, s16 state);
s32 complete_request_callback(s16 handle, TcpSendCallback cb, s16 code, const TcpSendRequest *request);
s32 net_unlock(void);
s32 net_lock(void);
s16 net_register_timer(NetTimerCallback callback, s32 interval);
s32 net_unregister_timer(NetTimerCallback timer);
s32 udp_close(s32 a);
s16 if_down(s16 idx, s32 op);
s16 tcp_get_opt(s16 nh, s16 type, u32 *opt);
s32 tcp_delete(s32 a);
s32 tcp_abort(s32 a);
s32 tcp_bind(s32 a, void *addr, u16 port);
s16 tcp_create(void);
#ifdef __cplusplus
}
#endif

#endif
