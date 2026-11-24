#ifndef PSO_NETWORK_NETWORKMESSAGETRANSPORT_H
#define PSO_NETWORK_NETWORKMESSAGETRANSPORT_H

#include "types.h"

/* The network stack's message transport (NetworkMessageTransport.c, C): the message thread and queues between the
 * Ethernet/PPPoE receive path and the stack, the receive filter and the EXI link status. */

#ifdef __cplusplus
extern "C" {
#endif
struct EthernetReceiveFilter;
struct OSMessageQueue;
void signal_network_message(u8 v);
s16 open_bba_receive_filter(struct EthernetReceiveFilter *filter);
s16 pppoe_terminate_hook(void);
s16 open_pppoe_adapter(u8 *out);
s32 open_ethernet_device(s16 dev);
void dispatch_received_ethernet_frame(struct EthernetReceiveFilter *filter, u8 *frame, s32 length);
void reset_message_thread(void);
void update_exi_status(void);
s16 post_send_message(void *data, u16 len);
s32 post_message(struct OSMessageQueue *queue, u8 *packet, s32 length, s32 by_address);
void message_thread_loop(void);
void clear_message_entry_wrapper(u8 *packet);
u16 recv_pppoe_message(u8 **packet, u16 *len);
s32 queue_timeout_message(s16 channel, u8 *packet, s16 timeout);
s32 get_local_address(s16 channel, void *address);
s32 consume_item_count_by_id(s16 channel, void *address);
s32 add_multicast_address(s16 channel, void *address);
s32 remove_rec_by_handle(s16 channel, u16 ether_type);
s32 open_channel_checked(s16 channel, u16 ether_type);
void forward_to_channel(u8 *frame, s32 length);
u8 *alloc_receive_frame(u16 type, s32 length, u8 status);
s16 query_link_status(void);
s32 AT_SetEtherNegoMode(s32 mode);
#ifdef __cplusplus
}
#endif

#endif
