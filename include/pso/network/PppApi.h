#ifndef PSO_NETWORK_PPPAPI_H
#define PSO_NETWORK_PPPAPI_H

#include "types.h"
#include "pso/network/NetStackTypes.h"
#include "pso/network/PppFsm.h"

/* Connection request of ppp_start (copied field by field into the net_session request by
   NetApplyConnectionConfig). */
typedef struct NetConnectCfg {
    u16 flags;
    s16 ip_mode;        /* ppp_ip_mode: 4 = IPv4 only; 0 or 6 also negotiate IPv6CP */
    s16 wait;
    u8 pad_6[2];
    char *user;
    char *password;
    char *phone_number;
    void *callback;
    s16 h18;
    s16 h1A;
    s16 h1C;
    s16 h1E;
    s16 h20;
    u8 pad_22[2];
    s16 h24;
    s16 h26;
    s16 h28;
    s16 h2A;
    s16 h2C;
    u8 pad_2E[2];
    char *prefix;
    s16 auth_mode;
    s16 mtu;
    s32 start_tick;
    s16 no_acfc;
    s16 no_pfc;
    s16 vj_disabled;
    u8 pad_42[2];
    s32 addr_local;
    s32 addr_peer;
    s32 dns_local_primary;
    s32 dns_local_secondary;
    s32 dns_peer_primary;
    s32 dns_peer_secondary;
    u8 local_interface_id[8];
    u8 peer_interface_id[8];
} NetConnectCfg;

/* Link state filled by ppp_stat (state 0 down, 4 up, 5/8 failed, 6 disconnecting). */
typedef struct NetLinkStatus {
    s16 link_up;
    s16 ppp_up;
    s16 state;
    s16 error;          /* lobby_modem_error */
    u32 result_code;    /* lobby_modem_reply_value: the number in the modem's last numeric reply */
    s16 session_active; /* ppp_session_active */
    u8 padE[2];
    u32 addr_local;     /* IPCP's negotiated addresses */
    u32 addr_peer;
    u32 dns_local_primary;
    u32 dns_local_secondary;
    u32 dns_peer_primary;
    u32 dns_peer_secondary;
    u8 addr[4][4];
} NetLinkStatus;

/* Parameter block of ppp_stop (wait != 0: poll until the link is down). */
typedef struct NetWaitParam {
    s16 wait;
} NetWaitParam;

/* ppp_proto_blocks: the lobby session's PPP protocol control blocks. close_all_connections
   resets the five PppFsm records one at a time and hands them to the connect routines
   (wait_for_connection, apply_lcp_config_to_sides, PP_chap_monitor). ppp_hangup reads
   the busy byte, and the tail carries the byte count and the drop counters. */
struct PppProtoBlocks {
    u8 phase;               /* 0x00: the link phase (RFC 1661): 0 dead, 1 establish, 2 authenticate, 3 network,
                               4 terminate; cleared by close_all_connections */
    u8 next_identifier;     /* 0x01: the identifier of the next request any FSM sends */
    u8 auth_pending;        /* 0x02: 0x10 and 0x20, authentications still running; network starts when both clear */
    u8 pad3;
    PppFsm lcp;             /* 0x04: the connect record the caller passes the LcpConfig at the head of */
    PppFsm pap;             /* 0x38 */
    PppFsm ipcp;            /* 0x6C: its opts points at the IpcpConfig */
    PppFsm chap;            /* 0xA0 */
    PppFsm ipv6cp;          /* 0xD4 */
    s32 network_time;       /* 0x108: the time in seconds the network phase began */
    u8 *pap_peer_id;        /* 0x10C: the peer id PAP accepted */
    s32 tx_bytes;           /* 0x110 */
    s32 tx_packets;         /* 0x114 */
    s16 tx_counts[5];       /* 0x118: frames sent per protocol (PppFsmProtocol.tx_counter_index) */
    s16 tx_drops;           /* 0x122 */
    s16 tx_alloc_drops;     /* 0x124 */
    u8 tail_pad26[0x0A];    /* 0x126 */
    s16 rx_lcp;             /* 0x130 */
    s16 rx_pap;             /* 0x132 */
    s16 rx_ipcp;            /* 0x134 */
    s16 rx_chap;            /* 0x136 */
    s16 rx_ipv6cp;          /* 0x138 */
    s16 rx_drops;           /* 0x13A */
    u8 tail_pad3C[4];       /* 0x13C */
    s16 rx_err_drops;       /* 0x140 */
    s16 rx_alloc_drops;     /* 0x142 */
    u8 tail_pad44[4];       /* 0x144 */
};
LAYOUT_ASSERT(PppProtoBlocks_size_check, sizeof(PppProtoBlocks) == 0x148);
LAYOUT_ASSERT(PppProtoBlocks_tx_bytes_offset, offsetof(PppProtoBlocks, tx_bytes) == 0x110);
LAYOUT_ASSERT(PppProtoBlocks_tx_drops_offset, offsetof(PppProtoBlocks, tx_drops) == 0x122);
LAYOUT_ASSERT(PppProtoBlocks_rx_drops_offset, offsetof(PppProtoBlocks, rx_drops) == 0x13A);
LAYOUT_ASSERT(PppProtoBlocks_rx_err_drops_offset, offsetof(PppProtoBlocks, rx_err_drops) == 0x140);
LAYOUT_ASSERT(PppProtoBlocks_rx_alloc_drops_offset, offsetof(PppProtoBlocks, rx_alloc_drops) == 0x142);

/* PppApi.c: session control (stack up/down, login name, connection configuration, timeout). */
#ifdef __cplusplus
extern "C" {
#endif
s32 ppp_get_opt(s32 cmd, s32 arg);
s32 ppp_term(void);
s16 ppp_init(void);
struct ModemConfig;
struct ModemConfig *ppp_get_modem_property(void);
s16 ppp_get_link_status(NetLinkStatus *status);
u8 *ppp_set_modem_property(void *src);
s16 ppp_stat(NetLinkStatus *status);
s32 ppp_stop(NetWaitParam *param);
s32 ppp_start(NetConnectCfg *cfg);
s16 NetApplyConnectionConfig(NetConnectCfg *config);
s16 get_remaining(s32 elapsed);
s32 is_timed_out(void);
s32 ppp_hangup(void);
s32 ppp_open_sub(void);
void ppp_set_auth(u16 protocol);
extern s16 ppp_session_active;
extern s16 ppp_open_requested;
extern saddr lobby_modem_callback;
void PP_chap_init(PppProtoBlocks *connection);
void init_ipv6cp_protocol(PppProtoBlocks *connection);
extern PppProtoBlocks ppp_proto_blocks;
extern s16 lobby_modem_abort_flag;
extern s32 lobby_modem_reply_value;
#ifdef __cplusplus
}
#endif

#endif
