#ifndef PSO_NETWORK_TLOBBY_803FC178_H
#define PSO_NETWORK_TLOBBY_803FC178_H

#include "types.h"
#include "pso/network/NetStackTypes.h"
#include "pso/network/PppMd5.h"
#include "pso/network/PppFsm.h"

/* TLobby_803FC178.c: PPP (LCP/IPCP/CHAP/PAP, MD5), the connection state machine and the stack's buffer streams. */
typedef struct RecoveredGlobal_803AA0C0_lbl_80556E88 RecoveredGlobal_803AA0C0_lbl_80556E88;
typedef struct PppChapAuthenticationState PppChapAuthenticationState;
typedef struct RecoveredGlobal_803F88E4_lbl_805AEEB0 RecoveredGlobal_803F88E4_lbl_805AEEB0;
typedef struct RecoveredFields_803F88E4_arg0 RecoveredFields_803F88E4_arg0;
typedef struct PppHeader PppHeader;
struct RecoveredGlobal_803AA0C0_lbl_80556E88 {
    s32 value;
    u8 remaining[0xFC];
};
struct PppChapAuthenticationState {
    char peer_id[0x80];
    char secret[0x80];
    PppChap options;
    PppFsmProtocol proto;
};
LAYOUT_ASSERT(PppChapAuthenticationState_size, sizeof(PppChapAuthenticationState) == 0x150);
struct RecoveredGlobal_803F88E4_lbl_805AEEB0
{
  s32 value;
  u8 remaining[0x49C4];
};
struct RecoveredFields_803F88E4_arg0
{
  s16 field_0;
  s16 field_2;
  s16 field_4;
  u8 unknown_6[0x2];
  u8 *field_8;
  u8 *field_C;
  u8 *field_10;
  s16 field_14;
  u8 unknown_16[0x2];
  u8 *field_18;
};
LAYOUT_ASSERT(RecoveredGlobal_803F88E4_lbl_805AEEB0_size, (sizeof(RecoveredGlobal_803F88E4_lbl_805AEEB0)) == 0x49C8);
LAYOUT_ASSERT(RecoveredGlobal_803AA0C0_lbl_80556E88_size, sizeof(RecoveredGlobal_803AA0C0_lbl_80556E88) == 0x100);
/* A PPP control packet header (RFC 1661): code, identifier and length. */
struct PppHeader { u8 code; u8 id; s16 len; };
LAYOUT_ASSERT(PppHeader_size_check, sizeof(PppHeader) == 4);

/* Maps PPP configure option types to the negotiation bitmap. */
static inline u32 ppp_configure_option_bit(u32 bit) {
    s32 f;
    if (bit < 8) {
        return bit;
    }
    f = 0;
    if (bit >= 0x80 && bit < 0x90) {
        f = 1;
    }
    if (f) {
        bit -= 0x78;
    } else {
        bit = 0;
    }
    return bit;
}

#ifdef __cplusplus
extern "C" {
#endif
s32 clear_socket_slot(s16 i);
s32 configure_mode_by_type(void *self, s16 type);
void chap_input(PppFsm *fsm, PppFrame *source);
void free_field_98(PppFsm *self);
void free_field_98_and_clear(PppFsm *self);
s16 get_checked_status_value(s16 ch);
void handle_request_timeout(PppFsm *fsm);
void init_md5_state(MD5Context *ctx);
void init_net_block_620(void);
s32 init_net_block_620_secondary(void);
void init_net_state_a(void);
s32 init_net_state_b(void);
void init_net_state_c(void);
s32 init_net_subsystem_block(void);
s32 mark_ready(PppProtoBlocks *blocks);
s32 mark_sub_ready(PppProtoBlocks *blocks);
void queue_command_81(PppFsm *fsm);
s32 read_2_bytes(void *self, void *src);
void reset_connection_slot(PppFsm *self);
void PP_pap_down(PppFsm *fsm);
void pap_init(PppProtoBlocks *blocks);
void reset_lcp_options(PppFsm *self);
void set_active(PppProtoBlocks *blocks);
s32 set_active_flag(PppProtoBlocks *blocks);
s32 PP_doppp_active(PppFsm *fsm);
void update_connection_state(PppFsm *fsm);
struct LcpConfig;
s16 lcp_connect(struct LcpConfig *cfg);
s32 ipv6cp_set_interface_identifiers(s32 ignored, u8 *first_identifier, u8 *second_identifier);
s32 ipcp_configure_all_options(s16 vj_disabled, s32 addr_local, s32 addr_peer, s32 dns_local_primary,
                               s32 dns_local_secondary, s32 dns_peer_primary, s32 dns_peer_secondary);
s16 negotiate_ipcp_and_ipv6cp(void);
void MD5Transform(u32 *state, u8 *block);
u8 *write_network_u32_be(u8 *p, u32 v);
extern u8 vj_u16_buffer[2];
extern u8 vj_byte_buffer[1];
extern s16 ppp_use_pppoe;
extern s16 network_transport_open;
extern PppFsmTimer *lobby_timer_list_head;
extern s16 ppp_ip_mode;
extern s32 lobby_session_flags;
extern u8 lcp_read_value_buffer[4];
extern u8 lobby_read_byte_buffer[1];
extern u8 lcp_read_byte_buffer;
extern s16 lobby_modem_connect_state;
extern s16 ppp_auth_failed;
extern s16 lobby_modem_error;
extern PppChapAuthenticationState ppp_chap_authentication_state;
extern const char chap_protocol_name[5];
extern const char chap_failure_message[7];
extern s32 ppp_opened_count; /* PppFsm.c */
extern u16 chap_challenge_length;
extern u8 chap_read_byte_buffer;
s16 PP_chap_monitor(PppFsm *c, s32 timeout);
s32 TLobby__sub_803FC684(u8 *source, u8 *chap_secret, PppFsm *fsm);
void TLobby__sub_803FC728(PppFsm *c);
s16 chap_recv_response(PppFsm *fsm, PppHeader *header, PppFrame *source);
void chap_recv_challenge(PppFsm *connection, PppHeader *header, PppFrame *source);
#ifdef __cplusplus
}
#endif

#endif
