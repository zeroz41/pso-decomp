#ifndef PSO_NETWORK_NETWORKTRANSPORT_H
#define PSO_NETWORK_NETWORKTRANSPORT_H
#include "types.h"

/* The network stack's transport (NetworkTransport.c, C): the modem/PPPoE send path with its ring buffer and queue
 * thread, and the start-up parameters. */

/* The start-up parameters (AT_SetInitParam) and the sizes derived from them. */
typedef struct NetTransportParams {
    s16 with_ethernet;      /* nonzero: reserve the Ethernet message thread */
    s16 with_ppp;           /* nonzero: reserve the PPP and modem queue threads and the send ring */
    u16 udp_socket_count;   /* 0x44 bytes each */
    u16 tcp_socket_count;   /* 0x544 bytes each, plus a send and a receive buffer */
    s32 tcp_buffer_size;    /* each TCP socket's send and receive buffer: 0x400..0xFFFF */
    s32 thread_stack_size;
    s32 ring_buffer_size;   /* the PPP send ring */
    u32 buffer_pool_size;   /* each half of the modem buffer pool */
    u32 modem_ring_size;
} NetTransportParams;

/* open_network_transport's request (configure_and_open_network_transport). */
typedef struct NetTransportOpenCfg {
    s32 settings[6];  /* mapped from configure_and_open_network_transport's arguments; open_network_transport does not read them */
    s16 reserved;     /* always 0 */
    s16 use_pppoe;    /* nonzero: open the PPPoE transport instead of dialling the modem */
    char *modem_name; /* MDMInit's argument; NULL uses "00" */
} NetTransportOpenCfg;

#ifdef __cplusplus
extern "C" {
#endif
/* The start-up and shutdown hooks and the peer-secret lookup (NetAuthSecrets.c). */
void ppp_term_hook(void);
s32 ppp_init_hook(void);
/* inferred: returns the secret ppp_auth_secrets holds for a peer name, or NULL */
const char *ppp_find_auth_secret(const char *name);

struct ModemSessionState;
void init_modem_buffer_config(struct ModemSessionState *state);
s32 open_network_transport(NetTransportOpenCfg *cfg);
struct PppAuthState;
struct PppPapState;
struct PppBuffers;
void init_net_buffer_table(struct PppAuthState *auth);
void init_net_block_620_params(struct PppPapState *pap);
void init_net_buffer_desc(struct PppBuffers *bufs);
void stop_network_thread(void);
void queue_thread_main(void);
s32 write_ring_buffer(u8* src, s32 len);
s16 map_state_to_mode_id(void);
s32 map_state_to_code(const char *number, s16 mode);
s32 configure_modem_options(s32 ms_mode, s32 error_correction, s32 compression, s32 count, char *commands);
s32 send_atx_command_mode(s32 mode);
s32 AT_GetInitParam(NetTransportParams* out);
s32 AT_SetWorkArea(u8* data, s32 size);
s32 AT_SetInitParam(NetTransportParams* params);
void close_network_transport(void);
void start_network_thread(void);
u16 is_transport_connected(void);
s32 recv_network_frame(u16 max_len, void *lobby, u16 *out_len);
s32 send_network_frame(u16 len, u8 *src);
struct NetThreadState;
void init_thread_poll_config(struct NetThreadState *t);
void lcp_connect_hook(void);
s32 get_transport_input_count(s16 *out);
/* The stored start-up parameters (NetConfig.c), one per NetTransportParams field. */
extern s16 net_param_with_ethernet;
extern s16 net_param_with_ppp;
extern u16 net_param_udp_socket_count;
extern u16 net_param_tcp_socket_count;
extern s32 net_param_tcp_buffer_size;
extern s32 net_param_thread_stack_size;
extern s32 net_param_ring_buffer_size;
extern u32 net_param_buffer_pool_size;
extern u32 net_param_modem_ring_size;
extern void *net_udp_socket_storage; /* the UDP control blocks */
extern void *net_tcp_socket_storage; /* the TCP control blocks */

/* Empty in this build; each layer's term step still hands over its configuration record. */
void term_ppp_auth_config(void *cfg);
void term_pap_config(void *cfg);
void term_modem_session_config(void *cfg);
void term_ppp_link_config(void *cfg);
void term_net_thread_config(void *cfg);
void term_ppp_buffers_config(void *cfg);

#ifdef __cplusplus
}
#endif
#endif
