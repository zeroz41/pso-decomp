#ifndef PSO_NETWORK_NETWORKTRANSPORT_H
#define PSO_NETWORK_NETWORKTRANSPORT_H
#include "types.h"

/* The network stack's transport (NetworkTransport.c, C): the modem/PPPoE send path with its ring buffer and queue
 * thread, and the start-up parameters. */

/* The start-up parameters (validate_and_store_net_params) and the sizes derived from them. */
typedef struct NetTransportParams {
    s16 a;
    s16 b;
    u16 player_count;
    u16 room_count;
    s32 e;
    s32 f;
    s32 ring_buffer_size;
    s32 h;
    s32 i;
} NetTransportParams;

#ifdef __cplusplus
extern "C" {
#endif
void init_modem_buffer_config(void* config);
void init_net_buffer_table(void* table);
void init_net_block_620_params(void* params);
void init_buffer_desc_b(void* desc);
void init_net_buffer_desc(void* desc);
void stop_network_thread(void);
void queue_thread_main(void);
s32 write_ring_buffer(u8* src, s32 len);
s32 map_state_to_mode_id(void);
s32 map_state_to_code(s32 address, s16 mode);
s32 send_atx_command_mode(s32 mode);
s32 get_net_params_and_size(NetTransportParams* out);
s32 layout_net_params_buffer(u8* data, s32 size);
s32 validate_and_store_net_params(NetTransportParams* params);
extern s32 lbl_805D4800;
void close_network_transport(void);
s32 TLobby__sub_803F7684(void *lobby);
void start_network_thread(void);
s32 is_transport_connected(void);
s32 recv_network_frame(u16 max_len, void *lobby, u16 *out_len);
void TLobby__sub_803F7678(void);
s32 TLobby__sub_803F767C(void);
void TLobby__sub_803F79B0(u8 *cfg);
void TLobby__sub_803F808C(void);
s32 TLobby__sub_803F811C(s16 *out);
extern u16 net_param_player_count;
extern u16 net_param_room_count;
extern u32 net_transport_buffer_ptr_a;
extern u32 net_transport_buffer_ptr_b;
#ifdef __cplusplus
}
#endif
#endif
