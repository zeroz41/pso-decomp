#ifndef PSO_NETWORK_NETWORKMESSAGETRANSPORT_H
#define PSO_NETWORK_NETWORKMESSAGETRANSPORT_H

#include "types.h"

/* The network stack's message transport (NetworkMessageTransport.c, C): the message thread and queues between the
 * Ethernet/PPPoE receive path and the stack, the receive filter and the EXI link status. */

#ifdef __cplusplus
extern "C" {
#endif
void TLobby__sub_80425D88(u8 v);
s16 TLobby__sub_804262CC(void *argp);
s32 TLobby__sub_80426440(void);
s32 TLobby__sub_80426660(u8 *arg0);
s32 TLobby__sub_80426B88(s16 arg0);
void dispatch_received_ethernet_frame(void *q, void *a, void *b);
void reset_message_thread(void);
void update_exi_status(void);
s16 post_send_message(void *data, u16 len);
s32 post_message(void *queue, s32 address, s32 arg, s32 by_address);
void message_thread_loop(void);
void clear_message_entry_wrapper(s32 id);
u16 recv_pppoe_message(s32 *id, u16 *len);
s32 queue_timeout_message(s16 channel, s32 id, s16 timeout);
s32 get_local_address(s16 channel, void *address);
s32 consume_item_count_by_id(s16 channel, void *address);
s32 add_multicast_address(s16 channel, void *address);
s32 remove_rec_by_handle(s16 channel, u16 ether_type);
s32 open_channel_checked(s16 channel, u16 ether_type);
void forward_to_channel(void *frame, void *b);
s16 query_link_status(void);
s32 set_connect_mode(s32 mode);
#ifdef __cplusplus
}
#endif

#endif
