#ifndef PSO_NETWORK_NETAPI_H
#define PSO_NETWORK_NETAPI_H

#include "pso/network/TcpSendQueue.h"
#include "pso/network/NetworkReceiveCallback.h"
#include "pso/network/NetworkTimer.h"

/* NetApi.c: stack start-up and shutdown. */
#ifdef __cplusplus
extern "C" {
#endif
struct NetPacket;

/* if_config's request: an address to bring an interface up with. */
typedef struct IfConfigRequest {
    s32 family; /* 4: AT_IP4_IfUp, 6: bring_up_ipv6_interface */
    union {
        struct {
            u32 addr;
            u32 mask;
            u32 broadcast;
        } ipv4;
        struct {
            u8 addr[16];
            s16 prefix_len;
            s16 flags;
            Ipv6EventCallback callback;
        } ipv6;
    };
    u8 pad1C[4];
} IfConfigRequest;

s32 raw_socket_deliver(struct NetPacket *pkt, u8 *src, u8 *dst, NetworkReceiveCallback cb, s16 index);
s32 raw_socket_deliver_ipv4(struct NetPacket *pkt, u32 src, u32 dst, NetworkReceiveCallback cb, s16 index);
s16 avetcp_init(void);
s16 tcp_receive(s32 handle, TcpCompletion callback, s32 length, void *buffer);
s32 avetcp_term(void);
s16 invoke_routing_event_callback(s16 iface, s32 event, void *data, Ipv6EventCallback fn);
/* Complete a TCB's pending operation: wake the waiting thread or run its callback. */
s32 set_slot_state_and_resume(s16 idx, TcpCompletion cb, s16 state);
s32 set_thread_state_and_resume(s32 idx, TcpCompletion cb, s16 state);
s32 complete_request_callback(s16 handle, TcpSendCallback cb, s16 code, const TcpSendRequest *request);
s32 unlock_at_sem(void);
s32 lock_at_sem(void);
s16 set_at_timer(NetTimerCallback callback, s32 interval);
s32 reset_at_timer(NetTimerCallback timer);
s32 udp_close(s32 nh);
s16 if_down(s16 idx, s32 op);
s32 route4_del(saddr dst, saddr mask, saddr gateway);
s32 route4_add(saddr dst, saddr mask, saddr gateway);
s16 tcp_get_opt(s16 nh, s16 type, u32 *opt);
s32 tcp_delete(s32 nh);
s32 tcp_abort(s32 nh);
s32 tcp_bind(s32 nh, void *addr, u16 port);
s16 tcp_create(void);
s16 if_get(s16 iface, void *hdr_src, s32 len, void *buf);
#ifdef __cplusplus
}
#endif

#endif
