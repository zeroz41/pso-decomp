#ifndef PSO_NETWORK_TLOBBY_803FCF44_H
#define PSO_NETWORK_TLOBBY_803FCF44_H

#include "types.h"
#include "pso/network/NetStackTypes.h"
#include "pso/network/NetPppLink.h"
#include "pso/network/NetworkRuntime.h"
#include "pso/network/TLobby_803FC178.h"
#include "pso/network/TLobby_804048E8.h"
#include "pso/network/PppMd5.h"

/* Shared by the PPP files split out of TLobby_803FCF44.c: NetPppLink.c, PppFsm.c, PppIpcp.c, PppLcp.c, PppBuffer.c,
 * PppMd5.c, NetByteOrder.c, PppPap.c, PppControl.c and PppVj.c (CHAP is TLobby_803FC178.c). */
struct PppFsm;
struct PppHeader;
typedef struct O_80400ACC O_80400ACC;
typedef struct PppPapAuthenticationState PppPapAuthenticationState;
struct O_80400ACC { u8 b0; u8 b1; u8 b2; u8 pad3[0x108 - 3]; s32 f108; };
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
u32 TLobby__sub_803FE9F8(u32 sum, PppFrame* buf, u16 count);
void TLobby__sub_803FD0C0(void);
/* Called across the PPP files; each line names its defining file. */
void TLobby__sub_803FD694(PppFsm *fsm); /* PppFsm.c */
void TLobby__sub_803FE600(PppFsm *fsm); /* PppFsm.c */
s16 TLobby__sub_803FED78(PppFsm *self); /* PppIpcp.c */
struct LcpConfig;
s16 apply_lcp_config_to_sides(PppFsm *state, struct LcpConfig *config); /* PppLcp.c */
s32 TLobby__sub_80401ABC(u8 *self_m, void *dst, s32 n); /* PppBuffer.c */

void TLobby__sub_803FE820(saddr arg0);
s16 TLobby__sub_803FF304(PppFsm *fsm);
void TLobby__sub_803FF468(PppFsm *arg0);
void TLobby__sub_803FD85C(void *arg0);
s16 ppp_begin_connect(s32 ignored, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, char *modem_name, s32 no_modem);
s16 ppp_fsm_send_packet(PppFsm *fsm, u8 code, int reply_identifier, PppFrame *payload);
s16 TLobby__sub_803FE658(PppFsm *fsm);
void TLobby__sub_803FD958(u8 *arg0);
void TLobby__sub_80401CAC(PppFrame **o, u16 v);
u16 read_network_u16_be(u8 *p);
u32 TLobby__sub_80402AFC(u8 *p);
u8 *write_network_u16_be(u8 *p, u16 v);
void ipcp_opening(PppFsm *arg0);
s16 wait_for_connection(PppFsm *c);
s32 TLobby__sub_80403168(u8 *source, u8 *pap_password, u8 *ppp_fsm);
s16 chap_connect(u8 *chap_name, u8 *chap_secret, s32 timeout);
s16 PP_pap_monitor(void *arg0, u32 timeout);
s16 pap_connect(u8 *peer_id, u8 *pap_password, s32 timeout);
void setup_auth_after_lcp_negotiation(PppFsm *c);
s16 TLobby__sub_80403F4C(PppVjCompressionState *state, PppFrame **spp);
PppFrame *init_net_buffer_entry(u16 idx);
void append_masked_ipcp_options(uaddr *self, void *opt, s32 mask);
s16 TLobby__sub_803FF858(PppFsm *fsm, PppHeader *msg, PppFrame *expected);
s16 TLobby__sub_803FD5A4(s16 h, s16 v);
s32 TLobby__sub_803FD21C(s16 arg0, s32 arg1, s32 arg2, u8 *arr_);
s32 TLobby__sub_803FD310(s16 arg0, s32 arg1, u8 *arr_);
s32 TLobby__sub_803FD490(s16 arg0);
s32 TLobby__sub_803FD4B4(s16 arg0);
s32 TLobby__sub_803FD4D8(s16 arg0);
s32 TLobby__sub_803FD4FC(s16 arg0);
s16 TLobby__sub_803FE844(PppFsm *fsm, PppHeader *header, PppFrame *frame);
void TLobby__sub_803FE84C(PppFsm *fsm);
void TLobby__sub_803FF374(PppFsm *arg0);
void lcp_noop_callback(PppFsm *fsm);
void mark_lcp_starting(PppFsm *arg0);
PppFrame *build_avetcp_net_buffer(PppFsm *c);
void TLobby__sub_803FDBF8(PppFsm *fsm, PppFrame *payload);
s16 TLobby__sub_803FE8BC(PppHeader *dst, PppFrame **src);
s16 pap_recv_auth_request(PppFsm *fsm, PppHeader *header, PppFrame *payload);
void start_ipcp_after_auth(O_80400ACC *o);
PppFrame *TLobby__sub_80401B20(void *src, u16 n);
void MD5Update(MD5Context *context, u8 *input, u32 inputLen);
void MD5Final(u8 *dst, MD5Context *ctx);
#ifdef __cplusplus
}
#endif

#endif
