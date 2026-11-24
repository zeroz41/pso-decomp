#ifndef PSO_NETWORK_NETWORKTRANSPORT_H
#define PSO_NETWORK_NETWORKTRANSPORT_H
#include "types.h"

/* The network stack's transport (NetworkTransport.c, C): the modem/PPPoE send path with its ring buffer and queue
 * thread, and the start-up parameters. */

/* The start-up parameters (AT_SetInitParam) and the sizes derived from them. */
typedef struct NetTransportParams {
    s16 a;
    s16 b;
    u16 player_count;
    u16 room_count;
    s32 e;
    s32 f;
    s32 ring_buffer_size;
    u32 h;
    u32 i;
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
extern s16 net_param_a;
extern s16 net_param_b;
extern u16 net_param_player_count;
extern u16 net_param_room_count;
extern s32 net_param_word_e;
extern s32 net_param_word_f;
extern s32 net_param_ring_buffer_size;
extern u32 net_param_word_h;
extern u32 net_param_word_i;
extern void *net_transport_buffer_ptr_a; /* the UDP control blocks */
extern void *net_transport_buffer_ptr_b; /* the TCP control blocks */

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
