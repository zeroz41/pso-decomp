#ifndef PSO_NETWORK_TLOBBY_803FAEA0_H
#define PSO_NETWORK_TLOBBY_803FAEA0_H

#include "types.h"

/* Connection request of NetLinkConnect (copied field by field into the lbl_805BFF68 request by
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

/* Parameter block of NetLinkDisconnect (wait != 0: poll until the link is down). */
typedef struct NetWaitParam {
    s16 wait;
} NetWaitParam;

/* TLobby_803FAEA0.c: session control (stack up/down, login name, connection configuration, timeout). */
#ifdef __cplusplus
extern "C" {
#endif
s32 NetControl(s32 cmd, s32 arg);
s32 TLobby__sub_803FAFDC(void);
s16 init_net_session(void);
u8 *TLobby__sub_803FB110(void);
s16 TLobby__sub_803FB358(NetLinkStatus *status);
u8 *copy_name_buffer(void *src);
s16 NetGetLinkStatus(NetLinkStatus *status);
s32 NetLinkDisconnect(NetWaitParam *param);
s32 NetLinkConnect(NetConnectCfg *cfg);
s16 NetApplyConnectionConfig(NetConnectCfg *config);
s32 get_remaining(s32 arg0);
s32 is_timed_out(void);
s32 TLobby__sub_803FB6A0(void);
void set_ppp_auth_protocol(u16 protocol);
extern s16 lbl_805D7A84;
extern s16 lbl_805D7A88;
extern s32 lbl_805D7A8C;
extern s16 lobby_modem_abort_flag;
extern s32 lobby_modem_reply_value;
#ifdef __cplusplus
}
#endif

#endif
