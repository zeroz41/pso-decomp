#ifndef PSO_NETWORK_TLOBBY_803FAEA0_H
#define PSO_NETWORK_TLOBBY_803FAEA0_H

#include "types.h"
#include "pso/network/NetStackTypes.h"
#include "pso/network/PppFsm.h"

/* Connection request of ppp_start (copied field by field into the lbl_805BFF68 request by
   NetApplyConnectionConfig). */
typedef struct NetConnectCfg {
    u16 flags;
    s16 h2;
    s16 wait;
    u8 pad_6[2];
    char *wC;
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
    s16 h34;
    s16 mtu;
    s32 start_tick;
    s16 h3C;
    s16 h3E;
    s16 h40;
    u8 pad_42[2];
    s32 w44;
    s32 w48;
    s32 w4C;
    s32 w50;
    s32 w54;
    s32 w58;
    u8 b5C[8];
    u8 b64[8];
} NetConnectCfg;

/* Link state filled by NetGetLinkStatus (state 0 down, 4 up, 5/8 failed, 6 disconnecting). */
typedef struct NetLinkStatus {
    s16 link_up;
    s16 ppp_up;
    s16 state;
    s16 h6;
    u32 w8;
    s16 hC;
    u8 padE[2];
    u32 w10;
    u32 w14;
    u32 w18;
    u32 w1C;
    u32 w20;
    u32 w24;
    u8 addr[4][4];
} NetLinkStatus;

/* Parameter block of ppp_stop (wait != 0: poll until the link is down). */
typedef struct NetWaitParam {
    s16 wait;
} NetWaitParam;

/* ppp_proto_blocks: the lobby session's PPP protocol control blocks. close_all_connections
   resets the five PppFsm records one at a time and hands them to the connect routines
   (wait_for_connection, apply_lcp_config_to_sides, PP_chap_monitor). TLobby__sub_803FB6A0 reads
   the busy byte, and the tail carries the byte count and the drop counters. */
typedef struct PppProtoBlocks {
    u8 busy;                /* 0x00: cleared by close_all_connections, set when the blocks are initialized */
    u8 pad1[3];
    PppFsm lcp;             /* 0x04: the connect record the caller passes the LcpConfig at the head of */
    PppFsm pap;             /* 0x38 */
    PppFsm ipcp;            /* 0x6C: its opts points at the IpcpConfig */
    PppFsm chap;            /* 0xA0 */
    PppFsm ipv6cp;          /* 0xD4 */
    u8 tail_pad0[8];        /* 0x108 */
    s32 tx_bytes;           /* 0x110 */
    s32 tx_packets;         /* 0x114 */
    u8 tail_pad18[0xA];     /* 0x118 */
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
} PppProtoBlocks;
LAYOUT_ASSERT(PppProtoBlocks_size_check, sizeof(PppProtoBlocks) == 0x148);
LAYOUT_ASSERT(PppProtoBlocks_tx_bytes_offset, offsetof(PppProtoBlocks, tx_bytes) == 0x110);
LAYOUT_ASSERT(PppProtoBlocks_tx_drops_offset, offsetof(PppProtoBlocks, tx_drops) == 0x122);
LAYOUT_ASSERT(PppProtoBlocks_rx_drops_offset, offsetof(PppProtoBlocks, rx_drops) == 0x13A);
LAYOUT_ASSERT(PppProtoBlocks_rx_err_drops_offset, offsetof(PppProtoBlocks, rx_err_drops) == 0x140);
LAYOUT_ASSERT(PppProtoBlocks_rx_alloc_drops_offset, offsetof(PppProtoBlocks, rx_alloc_drops) == 0x142);

/* TLobby_803FAEA0.c: session control (stack up/down, login name, connection configuration, timeout). */
#ifdef __cplusplus
extern "C" {
#endif
s32 NetControl(s32 cmd, s32 arg);
s32 ppp_term(void);
s16 ppp_init(void);
struct ModemConfig;
struct ModemConfig *TLobby__sub_803FB110(void);
s16 TLobby__sub_803FB358(NetLinkStatus *status);
u8 *copy_name_buffer(void *src);
s16 NetGetLinkStatus(NetLinkStatus *status);
s32 ppp_stop(NetWaitParam *param);
s32 ppp_start(NetConnectCfg *cfg);
s16 NetApplyConnectionConfig(NetConnectCfg *config);
s16 get_remaining(s32 elapsed);
s32 is_timed_out(void);
s32 TLobby__sub_803FB6A0(void);
s32 ppp_open_sub(void);
void ppp_set_auth(u16 protocol);
extern s16 lbl_805D7A84;
extern s16 lbl_805D7A88;
extern saddr lbl_805D7A8C;
void TLobby__sub_803FC318(PppProtoBlocks *connection);
void TLobby__sub_803F9FAC(PppProtoBlocks *connection);
extern PppProtoBlocks ppp_proto_blocks;
extern s16 lobby_modem_abort_flag;
extern s32 lobby_modem_reply_value;
#ifdef __cplusplus
}
#endif

#endif
