#ifndef PSO_NETWORK_PPP_H
#define PSO_NETWORK_PPP_H

#include "types.h"
#include "pso/network/NetStackTypes.h"
#include "pso/network/NetPppLink.h"
#include "pso/network/NetworkRuntime.h"
#include "pso/network/PppChap.h"
#include "pso/network/PppVj.h"
#include "pso/network/PppMd5.h"

/* Shared by the PPP files split out of Ppp.c: NetPppLink.c, PppFsm.c, PppIpcp.c, PppLcp.c, PppBuffer.c,
 * PppMd5.c, NetByteOrder.c, PppPap.c, PppControl.c and PppVj.c (CHAP is PppChap.c). */
struct PppFsm;
struct PppHeader;
typedef struct PppPapAuthenticationState PppPapAuthenticationState;
struct PppPapAuthenticationState {
    PppFsmProtocol proto;
    PapOptions options;
    u8 peer_id[0x80];
    u8 password[0x80];
};
LAYOUT_ASSERT(PppPapAuthenticationState_size, sizeof(PppPapAuthenticationState) == 0x148);

#ifdef __cplusplus
extern "C" {
#endif
extern PppPapAuthenticationState ppp_pap_authentication_state;
u32 ip_checksum_accumulate(u32 sum, PppFrame* buf, u16 count);
void ppp_link_term(void);
/* Called across the PPP files; each line names its defining file. */
void fsm_init(PppFsm *fsm); /* PppFsm.c */
void fsm_reset(PppFsm *fsm); /* PppFsm.c */
s16 wait_for_ipcp_open(PppFsm *self); /* PppIpcp.c */
struct LcpConfig;
s16 apply_lcp_config_to_sides(PppFsm *state, struct LcpConfig *config); /* PppLcp.c */
s32 ppp_buffer_copy_out(u8 *self_m, void *dst, s32 n); /* PppBuffer.c */

void fsm_restart_timer(PppFsm *fsm);
s16 ipcp_open(PppFsm *fsm);
void ipcp_finish_termination(PppFsm *fsm);
void fsm_lowerdown(PppFsm *fsm);
s16 ppp_begin_connect(s32 ignored, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, char *modem_name, s32 no_modem);
s16 ppp_fsm_send_packet(PppFsm *fsm, u8 code, int reply_identifier, PppFrame *payload);
s16 fsm_send_config_request(PppFsm *fsm);
void fsm_open(PppFsm *fsm);
void ppp_buffer_truncate(PppFrame **o, u16 v);
u16 read_network_u16_be(u8 *p);
u32 read_network_u32_be(u8 *p);
u8 *write_network_u16_be(u8 *p, u16 v);
void ipcp_opening(PppFsm *fsm);
s16 wait_for_connection(PppFsm *c);
s32 pap_set_secret(u8 *source, u8 *pap_password, PppFsm *ppp_fsm);
s16 chap_connect(u8 *chap_name, u8 *chap_secret, s32 timeout);
s16 PP_pap_monitor(void *fsm, u32 timeout);
s16 pap_connect(u8 *peer_id, u8 *pap_password, s32 timeout);
void setup_auth_after_lcp_negotiation(PppFsm *c);
s16 vj_remember_uncompressed(PppVjCompressionState *state, PppFrame **spp);
PppFrame *init_net_buffer_entry(u16 idx);
void append_masked_ipcp_options(uaddr *self, void *opt, s32 mask);
s16 verify_ipcp_config_ack(PppFsm *fsm, PppHeader *msg, PppFrame *expected);
s16 ppp_link_attach_protocol(s16 h, s16 v);
s32 ppp_link_send_packet(s16 ch, s32 mode, s32 addr, u8 *packet);
s32 ppp_link_forward_packet(s16 ch, s32 addr, u8 *packet);
s32 ppp_link_update_multicast(s16 ch);
s32 ppp_link_update_address(s16 ch);
s32 ppp_link_get_address(s16 ch);
s32 ppp_link_get_address_length(s16 ch);
s16 fsm_noop_check(PppFsm *fsm, PppHeader *header, PppFrame *frame);
void fsm_noop_action(PppFsm *fsm);
void ipcp_start_negotiation(PppFsm *fsm);
void lcp_noop_callback(PppFsm *fsm);
void mark_lcp_starting(PppFsm *fsm);
PppFrame *build_avetcp_net_buffer(PppFsm *c);
void fsm_input(PppFsm *fsm, PppFrame *payload);
s16 fsm_read_header(PppHeader *dst, PppFrame **src);
s16 pap_recv_auth_request(PppFsm *fsm, PppHeader *header, PppFrame *payload);
void start_ipcp_after_auth(PppProtoBlocks *blocks);
void init_lcp_protocol(PppProtoBlocks *conn);
PppFrame *ppp_buffer_from_bytes(void *src, u16 n);
void MD5Update(MD5Context *context, u8 *input, u32 inputLen);
void MD5Final(u8 *dst, MD5Context *ctx);
#ifdef __cplusplus
}
#endif

#endif
