#ifndef PSO_NETWORK_TLOBBY_80428374_H
#define PSO_NETWORK_TLOBBY_80428374_H

#include "types.h"

typedef struct ModemSessionState {
    char **subst;
    u8 pad04[4];
    char *strbuf;
    u8 pad0C[2];
    s16 strstride;
    u8 **fields;
    u8 pad14[4];
    s16 *ints;
    u8 pad1C[4];
    u8 *line;   // current script line (inferred)
    u8 *token;  // current parsed token (inferred)
    u8 *cmd;
    u8 *out;
    u8 *expect;
    u8 *window;
    u8 *rxbuf;
    u8 pad3C[0xA];
    s16 window_len;
    s16 rxlen;
    u8 pad4A[0x16];
} ModemSessionState;

typedef struct ModemRequest {
    s16 type;
    s16 has_arg;
    s16 timeout;
    u8 pad06[6];
    char *arg;
} ModemRequest;

typedef struct ModemConfig {
    s16 h0;
    s16 h2;
    s16 h4;
    s16 h6;
    s16 numeric_result;
    u8 pad0A[2];
    char *prefix0;
    char *prefix1;
    s32 w14;
    s32 w18;
    char *result_ok;
    char *result_error;
    char *result_busy;
    char *result_no_dialtone;
    char *result_no_carrier;
    char *result_no_answer;
    s32 w34;
    u8 terminator;
    u8 pad39[3];
    s32 w3C;
    s32 w40;
    s32 w44;
    char *s48;
    s32 w4C;
    s32 w50;
    s32 w54;
    s32 init_count;
    char *init_command; /* "AT+MS=V34\r" by default (connect_modem) */
} ModemConfig;

// Modem dial-script session; the script substitutes %t, %u and %p with
// these strings (field names inferred from the substitution keys).
typedef struct ModemScriptSession {
    u8 pad00[0xC];
    char *user;
    char *password;
    char *phone_number;
    u8 pad18[0x70];
    ModemRequest req;
} ModemScriptSession;

/* TLobby_80428374.c: the modem session (dial-script expansion, timed waits) and the buffer pool's bounds. */
#ifdef __cplusplus
extern "C" {
#endif
s32 init_modem_session_config(void);
s16 modem_run_script(u8 *script, ModemScriptSession *sess);
s16 modem_script_wait(ModemRequest *req);
s32 modem_script_send(void);
s32 modem_script_dial(u8 *request);
void modem_script_store_field(s16 type, s16 index, u8 *src, s16 *nstr, s16 *nint);
s32 TLobby__sub_804290D4(s32 idx);
void reset_boot_state(void);
s32 wait_timeout_loop(void *params);
void cancel_alarm_b(void);
s32 init_buffer_pool(void);
void reset_buffer_pool(void);
#ifdef __cplusplus
}
#endif

#endif
