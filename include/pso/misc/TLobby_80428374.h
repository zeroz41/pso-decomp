#ifndef PSO_MISC_TLOBBY_80428374_H
#define PSO_MISC_TLOBBY_80428374_H

#include "types.h"

struct ModemSessionState {
    char **subst;
    u8 pad04[4];
    char *strbuf;
    u8 pad0C[2];
    s16 strstride;
    u8 **fields;
    u8 pad14[4];
    s16 *ints;
    u8 pad1C[0xC];
    u8 *cmd;
    u8 *out;
    u8 *expect;
    u8 *window;
    u8 *rxbuf;
    u8 pad3C[0xA];
    s16 window_len;
    s16 rxlen;
    u8 pad4A[0x16];
};

struct ModemRequest {
    s16 type;
    s16 has_arg;
    s16 timeout;
    u8 pad06[6];
    char *arg;
};

struct ModemConfig {
    u8 pad00[8];
    s16 numeric_result;
    u8 pad0A[2];
    char *prefix0;
    char *prefix1;
    u8 pad14[8];
    char *result_ok;
    char *result_error;
    char *result_busy;
    char *result_no_dialtone;
    char *result_no_carrier;
    char *result_no_answer;
    u8 pad34[4];
    u8 terminator;
};

extern "C" {
extern ModemSessionState lobby_net_session_state;
s32 TLobby__sub_80428A38(void);
s32 TLobby__sub_80428BB0(ModemRequest *req);
void TLobby__sub_80428DC8(s16 type, s16 index, char *src, s16 *nstr, s16 *nint);
s32 TLobby__sub_804290D4(s16 timeout);
}

s32 init_modem_session_config(void);

#endif
