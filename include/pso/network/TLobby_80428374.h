#ifndef PSO_NETWORK_TLOBBY_80428374_H
#define PSO_NETWORK_TLOBBY_80428374_H

#include "types.h"
#include <stddef.h>

typedef union ModemFieldSlot {
    u8 *text;
    s16 *number;
} ModemFieldSlot;

typedef struct ModemSessionState {
    const char **subst;
    s16 subst_count;
    u8 pad06[2];
    char *strbuf;
    s16 strbuf_count;
    s16 strstride;
    ModemFieldSlot *fields;
    s16 field_count;
    u8 pad16[2];
    s16 *ints;
    s16 int_count;
    u8 pad1E[2];
    u8 *line;   // current script line (inferred)
    u8 *token;  // current parsed token (inferred)
    u8 *cmd;
    u8 *out;
    u8 *expect;
    u8 *window;
    u8 *rxbuf;
    s16 line_len;
    s16 token_len;
    s16 cmd_len;
    s16 out_len;
    s16 expect_len;
    s16 window_len;
    s16 rxlen;
    u8 pad4A[2];
    struct ModemConfig *config; /* the defaults copied into each session's modem settings */
    u8 pad50[0x10];
} ModemSessionState;
LAYOUT_ASSERT(ModemFieldSlot_size, sizeof(ModemFieldSlot) == 4);
LAYOUT_ASSERT(ModemSessionState_size, sizeof(ModemSessionState) == 0x60);
LAYOUT_ASSERT(ModemSessionState_fields_offset, offsetof(ModemSessionState, fields) == 0x10);
LAYOUT_ASSERT(ModemSessionState_line_offset, offsetof(ModemSessionState, line) == 0x20);
LAYOUT_ASSERT(ModemSessionState_config_offset, offsetof(ModemSessionState, config) == 0x4C);
/* The modem script interpreter's state (TLobby_80428374.c); init_modem_buffer_config sets its buffers. */
extern ModemSessionState lobby_net_session_state;

typedef struct ModemRequest {
    s16 type;
    s16 has_arg;
    s16 timeout;
    u8 pad06[6];
    char *arg;
} ModemRequest;
LAYOUT_ASSERT(ModemRequest_size, sizeof(ModemRequest) == 0x10);
LAYOUT_ASSERT(ModemRequest_timeout_offset, offsetof(ModemRequest, timeout) == 4);

typedef struct ModemConfig {
    s16 send_init;      /* set: send the init options (configure_modem_options) */
    s16 dial;           /* set: dial phone_number after the request's prefix */
    s16 wait_connect;   /* set: wait up to the request's timeout for the line to connect */
    s16 hangup;         /* set: run hangup_script after hanging up */
    s16 numeric_result;
    u8 pad0A[2];
    const char *tone_dial_command;  /* "ATDT" */
    const char *pulse_dial_command; /* "ATDP" */
    const char *answer_command;     /* "ATA" */
    const char *ok_response;
    const char *connect_response;
    const char *busy_response;
    const char *error_response;
    const char *delayed_response;
    const char *no_carrier_response;
    const char *no_dialtone_response;
    const char *ring_response;
    u8 terminator;
    u8 pad39[3];
    const char *init_script;
    const char *dial_script;
    char *hangup_script; /* the script run after hanging up (TLobby__sub_803FB6A0), when hangup is set */
    char *s48;
    s32 ms_mode;          /* configure_modem_options' arguments */
    s32 error_correction;
    s32 compression;
    s32 init_count;
    char *init_command; /* "AT+MS=V34\r" by default (connect_modem) */
} ModemConfig;

/* The session (net_session, TLobby_803FAEA0.c): NetApplyConnectionConfig copies the connection request (NetConnectCfg)
 * into it and ppp_open_sub connects with it. A dial script substitutes %t, %u and %p with phone_number, user and
 * password. */
typedef struct NetSession {
    u16 flags;                  /* NetConnectCfg.flags; bit 2: no modem */
    s16 ip_mode;                /* 0x02: NetConnectCfg.ip_mode */
    s16 wait;                   /* 0x04: NetConnectCfg.wait */
    u8 pad6[2];
    s32 connect_ms;             /* 0x08: when PPP started (state 3); is_timed_out gives up 60 s later */
    char *user;                 /* 0x0C */
    char *password;             /* 0x10 */
    char *phone_number;         /* 0x14 */
    void (*cb)(s16, s32);       /* 0x18: status callback */
    ModemConfig modem;          /* 0x1C: a copy of the default (ppp_init, copy_name_buffer) */
    s16 h7C;                    /* 0x7C: NetConnectCfg.h18 .. h20 */
    s16 h7E;
    s16 h80;
    s16 h82;
    s16 h84;
    u8 pad86[2];
    ModemRequest req;           /* 0x88: NetConnectCfg.h24 .. prefix */
    s16 auth_mode;                  /* 0x98: NetConnectCfg.auth_mode .. vj_disabled; the low 7 bits select the authentication */
    s16 mtu;                    /* 0x9A: 0 = the default (lobby_net_buffer_desc_b) */
    s32 start_tick;             /* 0x9C */
    u16 no_acfc;
    u16 no_pfc;
    s16 vj_disabled;
    u8 padA6[2];
    s32 addr_local;                 /* 0xA8: ipcp_configure_all_options' addresses, from NetConnectCfg */
    s32 addr_peer;
    s32 dns_local_primary;
    s32 dns_local_secondary;
    s32 dns_peer_primary;
    s32 dns_peer_secondary;
    u8 local_interface_id[8];      /* 0xC0: the IPv6CP interface identifiers */
    u8 peer_interface_id[8];
} NetSession;
LAYOUT_ASSERT(NetSession_size_check, sizeof(NetSession) == 0xD0);
LAYOUT_ASSERT(NetSession_modem_offset, offsetof(NetSession, modem) == 0x1C);
LAYOUT_ASSERT(NetSession_request_offset, offsetof(NetSession, req) == 0x88);
LAYOUT_ASSERT(NetSession_auth_offset, offsetof(NetSession, auth_mode) == 0x98);
LAYOUT_ASSERT(ModemConfig_size, sizeof(ModemConfig) == 0x60);

/* TLobby_80428374.c: the modem session (dial-script expansion, timed waits) and the buffer pool's bounds. */
#ifdef __cplusplus
extern "C" {
#endif
s32 init_modem_session_config(void);
s16 modem_run_script(u8 *script, NetSession *sess);
s16 go_wait(ModemRequest *req);
s16 modem_script_send(void);
s16 go_dial(ModemRequest *request);
s16 modem_script_next_token(u8 *src, u8 *dst, u8 **next);
void modem_script_store_field(s16 type, s16 index, u8 *src, s16 *nstr, s16 *nint);
s16 TLobby__sub_804290D4(s32 idx);
void reset_boot_state(void);
s16 wait_timeout_loop(ModemRequest *request);
void cancel_alarm_b(void);
s16 init_buffer_pool(void);
void reset_buffer_pool(void);
#ifdef __cplusplus
}
#endif

#endif
