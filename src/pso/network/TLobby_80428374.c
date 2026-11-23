/* The network stack's modem session (a C library, built with GC/1.2.5n): the session record, the dial-script
 * expansion and its quoted-string parser, timed waits on the modem, and the buffer pool's bounds. */
#include "pso/network/NetworkRuntimeSlots.h"
#include "pso/network/NetworkTransport.h"
#include "pso/network/TLobby_80428374.h"
#include "pso/network/ModemRuntime.h"
#include "pso/network/NetworkMessageTransport.h"

#include "types.h"
#include "pso/network/TLobby_803F86BC.h"
#include "pso/network/TLobby_803FAEA0.h"
#include "pso/network/TLobby_803FC178.h"
#include "pso/network/NetStackTypes.h"

/* The script strings are read-only: the short ones are in .sdata2. */
#pragma readonly_strings on

typedef struct RecoveredGlobal_8042839C_lbl_805D0A40 {
    s32 value;
    u8 remaining[0x5C];
} RecoveredGlobal_8042839C_lbl_805D0A40;

#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off

s32 TLobby__sub_803F77E0(void *);
ModemSessionState lobby_net_session_state;
/* The session's and the buffer pool's small state (.sbss 805D7BD0-805D7C30). This compiler lays .sbss out in
 * reverse definition order, so the last address comes first. */
s32 lobby_buffer_pool_state;
s32 lbl_805D7C24;
s32 lbl_805D7C20;
saddr buffer_pool_limit;
uaddr buffer_pool_start;
uaddr lbl_805D7C14;
uaddr lbl_805D7C10;
s32 lbl_805D7C0C;
u32 lbl_805D7C08;
u8 *lbl_805D7C04;
s32 lobby_buffer_pool_alarm_handle;
s32 lbl_805D7BFC;
saddr lobby_buffer_pool_end;
saddr lbl_805D7BF4;
saddr lbl_805D7BF0;
saddr lbl_805D7BEC;
uaddr lobby_buffer_pool_size;
u8 *lobby_second_buffer_pool_base;
u8 *lobby_buffer_pool_base;
s32 lobby_modem_reply_value;
s32 lbl_805D7BD8;
u32 lobby_modem_wait_timeout_ms;
u32 lobby_modem_wait_start_ms;

s32 net_sleep_ms(int);
s16 WaitNstrRecv(u8 *buf, s16 len);
s16 network_input_available(u16 *avail);
s16 recv_network_bytes(u8 *dst, u16 n);
s16 send_network_bytes(void *, s32);


void reset_boot_state(void) {
    TLobby__sub_803F77E0((s32 *)&lobby_net_session_state);
}

LAYOUT_ASSERT(RecoveredGlobal_8042839C_lbl_805D0A40_size, sizeof(RecoveredGlobal_8042839C_lbl_805D0A40) == 0x60);
s32 init_modem_session_config(void) {
    init_modem_buffer_config((void *)&lobby_net_session_state);
    return 0;
}

/* Per script command: its field count, then each field's kind (0 a string, 1 a decimal number). */
typedef struct ModemFieldLayout {
    s32 count;
    s32 kind[4];
} ModemFieldLayout;
const ModemFieldLayout modem_command_layouts[5] = {
    {1, {0, 0, 0, 0}},
    {1, {0, 0, 0, 0}},
    {2, {0, 1, 0, 0}},
    {1, {1, 0, 0, 0}},
    {0, {0, 0, 0, 0}},
};
static const char modem_cmd_TERMINAL[] = "TERMINAL";
static const char modem_cmd_terminal[] = "terminal";
/* Script command names, upper and lower case per command. */
static const char *const modem_command_names[] = {
    "DIAL", "dial", "SEND", "send", "WAIT", "wait", "DELAY", "delay", modem_cmd_TERMINAL, modem_cmd_terminal, NULL,
};
/* The dial script's substitutions: %t phone number, %u user, %p password, %i, and %% for a percent sign. */
const char *const modem_subst_keys[] = {
    "%t", "%u", "%p", "%i", "%%", NULL,
};

static inline void modem_flush_input(void) {
    u16 avail;
    u8 discard[2];
    while (network_input_available(&avail) == 0 && avail != 0 && recv_network_bytes(discard, 1) == 0) {
    }
}

static inline s16 modem_find_command(u8 *word) {
    s16 k;
    for (k = 0; modem_command_names[k] != NULL; k++) {
        if (NetCompareStrings((const char *)word, modem_command_names[k]) == 0) {
            break;
        }
    }
    if (modem_command_names[k] == NULL) {
        return -1;
    }
    return k / 2;
}

static inline s16 modem_read_line(u8 **src, u8 *dst) {
    u8 *q = *src;
    u8 c;
    if (*q == 0) {
        return 0;
    }
    while ((c = *q++) != 0) {
        if (c == 10) {
            q++;
            break;
        }
        *dst++ = c;
    }
    *dst = 0;
    *src = q - 1;
    return 1;
}

static inline s16 modem_wait_connect(void) {
    s16 ret = 0;
    lobby_modem_connect_state = 9;
    for (;;) {
        if (lobby_modem_connect_state == 2) {
            break;
        }
        if (lobby_modem_abort_flag != 0 || lobby_modem_connect_state != 9) {
            ret = 4;
            break;
        }
        unlock_mutex(lbl_805C18A0.mutex);
        net_sleep_ms(100);
        lock_mutex(lbl_805C18A0.mutex);
    }
    return ret;
}

/* Runs a modem script line by line (DIAL, SEND, WAIT, DELAY, TERMINAL). */
s16 modem_run_script(u8 *script, NetSession *sess) {
    u8 *p;
    s16 nstr;
    s16 nint;
    s16 got;
    u8 *next;
    s16 ret;
    s16 cmd;
    s16 i;

    lobby_net_session_state.subst[0] = sess->phone_number;
    lobby_net_session_state.subst[1] = sess->user;
    lobby_net_session_state.subst[2] = sess->password;
    lobby_net_session_state.subst[4] = "%";
    modem_flush_input();
    p = script;
    for (;;) {
        lobby_net_session_state.fields[3].text = NULL;
        lobby_net_session_state.fields[2].text = NULL;
        lobby_net_session_state.fields[1].text = NULL;
        lobby_net_session_state.fields[0].text = NULL;
        got = modem_read_line(&p, lobby_net_session_state.line);
        if (got == 0) {
            break;
        }
        next = lobby_net_session_state.line;
        if (modem_script_next_token(next, lobby_net_session_state.token, &next) == 0) {
            continue;
        }
        if ((cmd = modem_find_command(lobby_net_session_state.token)) == -1) {
            modem_flush_input();
            return 4;
        }
        nstr = 0;
        nint = 0;
        for (i = 0; i < modem_command_layouts[cmd].count; i++) {
            if (modem_script_next_token(next, lobby_net_session_state.token, &next) == 0) {
                break;
            }
            modem_script_store_field(cmd, i, lobby_net_session_state.token, &nstr, &nint);
        }
        switch (cmd) {
        case 0:
            ret = go_dial(&sess->req);
            break;
        case 1:
            ret = modem_script_send();
            break;
        case 2:
            ret = go_wait(&sess->req);
            break;
        case 3:
            ret = wait_timeout_loop(&sess->req);
            break;
        case 4:
            ret = modem_wait_connect();
            break;
        default:
            ret = 4;
            break;
        }
        if (ret != 0) {
            modem_flush_input();
            return ret;
        }
    }
    modem_flush_input();
    return 0;
}
s16 wait_timeout_loop(ModemRequest *request) {
    s32 start;
    s32 now;
    s16 *p;
    u32 limit;
    s16 ret;
    ret = 0;
    get_time_ms(&start);
    p = lobby_net_session_state.fields[0].number;
    if (p == NULL) {
        limit = request->timeout * 1000;
    } else {
        limit = *p * 1000;
    }
    for (;;) {
        if (lobby_modem_abort_flag != 0) {
            ret = 4;
            break;
        }
        get_time_ms(&now);
        if ((u32)(now - start) > limit) {
            break;
        }
        unlock_mutex(lbl_805C18A0.mutex);
        net_sleep_ms(100);
        lock_mutex(lbl_805C18A0.mutex);
    }
    return ret;
}

s32 NetCompareStringsCaseInsensitiveN(u8 *a, u8 *b, u32 n);

inline s16 modem_wait_for_string(u8 *s, s16 n, s16 timeout) {
    get_time_ms((s32 *)&lobby_modem_wait_start_ms);
    lobby_modem_wait_timeout_ms = timeout * 1000;
    if (n > lobby_net_session_state.window_len) {
        n = lobby_net_session_state.window_len;
    }
    if (WaitNstrRecv(lobby_net_session_state.window, n) != 0) {
        return -1;
    }
    while (NetCompareStringsCaseInsensitiveN(lobby_net_session_state.window, s, n) != 0) {
        NetMemmove(lobby_net_session_state.window, lobby_net_session_state.window + 1, n - 1);
        if (WaitNstrRecv(lobby_net_session_state.window + n - 1, 1) != 0) {
            return -1;
        }
    }
    return 0;
}

/* The script's "wait" command (index 2 of the command names). */
s16 go_wait(ModemRequest *req) {
    s32 len;
    s32 pos;
    s32 k;
    s16 timeout;

    len = 0;
    pos = 0;
    lobby_net_session_state.expect[0] = 0;
    while (lobby_net_session_state.fields[0].text[pos] != 0) {
        for (k = 0; modem_subst_keys[k] != NULL; k++) {
            if (NetCompareStringsN(modem_subst_keys[k], (const char *)lobby_net_session_state.fields[0].text + pos,
                                   NetStringLength(modem_subst_keys[k])) == 0) {
                break;
            }
        }
        if (modem_subst_keys[k] == NULL) {
            lobby_net_session_state.expect[len] = lobby_net_session_state.fields[0].text[pos];
            pos++;
            len++;
        } else {
            NetAppendString((char *)lobby_net_session_state.expect + len, lobby_net_session_state.subst[k]);
            len += NetStringLength(lobby_net_session_state.subst[k]);
            pos += NetStringLength(modem_subst_keys[k]);
        }
    }
    lobby_net_session_state.expect[len] = 0;
    if (lobby_net_session_state.fields[1].number == NULL) {
        timeout = req->timeout;
    } else {
        timeout = *lobby_net_session_state.fields[1].number;
    }
    if (modem_wait_for_string(lobby_net_session_state.expect, NetStringLength((char *)lobby_net_session_state.expect), timeout) != 0) {
        return 4;
    }
    return 0;
}
s16 modem_script_send(void) {
    const char *const *keys;
    s32 di;
    s32 si;
    s32 j;
    s32 len;
    s16 r;
    u8 c[4];
    u16 avail;

    *lobby_net_session_state.out = 0;
    keys = modem_subst_keys;
    di = 0;
    si = 0;
    while (lobby_net_session_state.fields[0].text[si] != 0) {
        for (j = 0; keys[j] != NULL; j++) {
            len = NetStringLength(keys[j]);
            if (NetCompareStringsN(keys[j], (const char *)lobby_net_session_state.fields[0].text + si, len) == 0) {
                break;
            }
        }
        if (keys[j] == NULL) {
            lobby_net_session_state.out[di] = lobby_net_session_state.fields[0].text[si];
            si++;
            di++;
        } else {
            NetAppendString((char *)(lobby_net_session_state.out + di), lobby_net_session_state.subst[j]);
            di += NetStringLength(lobby_net_session_state.subst[j]);
            si += NetStringLength(keys[j]);
        }
    }
    lobby_net_session_state.out[di] = 0;
    do {
        r = network_input_available(&avail);
        if (r != 0 || avail == 0) {
            break;
        }
        r = recv_network_bytes(c, 1);
    } while (r == 0);
    if (send_network_bytes(lobby_net_session_state.out, (u16)NetStringLength((char *)lobby_net_session_state.out)) != 0) {
        return 4;
    }
    return 0;
}

/* Builds the dial string from the configured prefix, optional suffix, and script text. */
s16 go_dial(ModemRequest *request) {
    ModemConfig *config;
    ModemSessionState *state;
    u8 **out;
    const char *const *keys;
    ModemFieldSlot **pp;
    s32 dlen;
    s32 k;
    s32 j;
    s32 len;
    s16 r;
    u8 c[4];
    u16 avail;

    state = &lobby_net_session_state;
    config = TLobby__sub_803FB110();
    if (config == NULL) {
        return -3;
    }
    /* The byte offset preserves the retail instruction order when clearing the first byte. */
    out = (u8 **)((u8 *)state + offsetof(ModemSessionState, cmd));
    **out = 0;
    if (request->type == 0) {
        if (config->prefix0 != NULL) {
            NetCopyString((char *)*out, config->prefix0);
        }
    } else {
        if (config->prefix1 != NULL) {
            NetCopyString((char *)*out, config->prefix1);
        }
    }
    if (request->has_arg != 0) {
        NetAppendString((char *)*out, request->arg);
    }
    dlen = NetStringLength((const char *)*out);
    keys = modem_subst_keys;
    pp = &state->fields;
    k = 0;
    while ((*pp)[0].text[k] != 0) {
        for (j = 0; keys[j] != NULL; j++) {
            len = NetStringLength((const char *)keys[j]);
            if (NetCompareStringsN(keys[j], (const char *)(*pp)[0].text + k, len) == 0) {
                break;
            }
        }
        if (keys[j] == NULL) {
            (*out)[dlen] = (*pp)[0].text[k];
            k++;
            dlen++;
        } else {
            NetAppendString((char *)*out + dlen, state->subst[j]);
            dlen += NetStringLength(state->subst[j]);
            k += NetStringLength((const char *)keys[j]);
        }
    }
    if (dlen > 0 && config->terminator != (u8)(*out)[dlen - 1]) {
        (*out)[dlen++] = config->terminator;
    }
    (*out)[dlen] = 0;
    do {
        r = network_input_available(&avail);
        if (r != 0 || avail == 0) {
            break;
        }
        r = recv_network_bytes(c, 1);
    } while (r == 0);
    if (send_network_bytes(*out, (u16)NetStringLength((const char *)*out)) != 0) {
        return 4;
    }
    return TLobby__sub_804290D4(request->timeout);
}

#pragma push
#pragma cplusplus off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma dont_inline off
void modem_script_store_field(s16 type, s16 index, u8 *src, s16 *nstr, s16 *nint) {
    s32 n;
    char *dst;
    s16 i;
    s16 value;
    u8 c;

    if (modem_command_layouts[type].kind[index] == 0) {
        n = *nstr;
        dst = lobby_net_session_state.strbuf + n * lobby_net_session_state.strstride;
        NetCopyString(dst, (const char *)src);
        lobby_net_session_state.fields[index].text = (u8 *)dst;
        *nstr = n + 1;
    }
    if (modem_command_layouts[type].kind[index] == 1) {
        n = *nint;
        i = 0;
        value = 0;
        while ((c = src[i]) != 0) {
            value *= 10;
            value += c - '0';
            i++;
        }
        lobby_net_session_state.ints[n] = value;
        lobby_net_session_state.fields[index].number = &lobby_net_session_state.ints[n];
        *nint = n + 1;
    }
}
#pragma pop

s16 modem_script_next_token(u8 *src, u8 *dst, u8 **next) {
    s16 n;
    u8 *p;
    u8 c;
    s32 escape;
    s32 hex;
    s32 value;

    p = src;
    n = 0;
    while (*p++ == 32) {
        n++;
    }
    src += n;
    if (*src == 0) {
        return 0;
    }
    if (*src == 34) {
        escape = 0;
        hex = 0;
        value = 0;
        src++;
        while ((c = *src++) != 0 && c != 10) {
            if (hex != 0) {
                if (c >= 48 && c <= 57) {
                    value = value * 16 + (c - '0');
                    if (--hex == 0) {
                        *dst++ = c;
                    }
                } else if (c >= 97 && c <= 102) {
                    value = value * 16 + (c - '0' + 10);
                    if (--hex == 0) {
                        *dst++ = c;
                    }
                } else {
                    hex = 0;
                }
            } else if (escape != 0) {
                if (c == 114) {
                    *dst++ = '\r';
                } else if (c == 110) {
                    *dst++ = '\n';
                } else if (c == 92) {
                    *dst++ = '\\';
                } else if (c == 34) {
                    *dst++ = '"';
                } else if (c == 120) {
                    hex = 2;
                    value = 0;
                }
                escape = 0;
            } else if (c == 92) {
                escape = 1;
            } else if (c == 34) {
                src++;
                break;
            } else {
                *dst++ = c;
            }
        }
    } else {
        while ((c = *src++) != 0 && c != 10) {
            if (c == 32 || c == 44 || c == 34) {
                break;
            }
            *dst++ = c;
        }
    }
    n = 0;
    *dst = 0;
    src--;
    p = src;
    while (*p++ == 32) {
        n++;
    }
    src += n;
    if (*src == 44) {
        src++;
    }
    *next = src;
    return 1;
}

s16 TLobby__sub_804290D4(s32 idx) {
    s16 *lenp;
    u8 **bufp;
    ModemConfig *config;
    ModemSessionState *state;
    s32 c;
    u8 *q;
    u8 *p;
    u8 *buf;
    s32 n;
    u8 ch;

    config = TLobby__sub_803FB110();
    if (config == NULL) {
        return 1;
    }
    get_time_ms((s32 *)&lobby_modem_wait_start_ms);
    if ((s16)idx == 0x7fff) {
        lobby_modem_wait_timeout_ms = -1;
    } else {
        lobby_modem_wait_timeout_ms = (s16)idx * 1000;
    }
    state = &lobby_net_session_state;
    bufp = &state->rxbuf;
    lenp = &state->rxlen;
    NetMemset(*bufp, 0, *lenp);
    for (;;) {
        NetMemmove(*bufp, *bufp + 1, *lenp - 1);
        if (WaitNstrRecv(*bufp + *lenp - 1, 1) != 0) {
            return 4;
        }
        n = NetStringLength(config->result_ok);
        if (NetCompareStringsCaseInsensitiveN(*bufp + *lenp - n, (u8 *)config->result_ok, n) == 0) {
            goto L122;
        }
        n = NetStringLength(config->result_error);
        if (NetCompareStringsCaseInsensitiveN(*bufp + *lenp - n, (u8 *)config->result_error, n) == 0) {
            return 2;
        }
        n = NetStringLength(config->result_busy);
        if (NetCompareStringsCaseInsensitiveN(*bufp + *lenp - n, (u8 *)config->result_busy, n) == 0) {
            return 2;
        }
        n = NetStringLength(config->result_no_dialtone);
        if (NetCompareStringsCaseInsensitiveN(*bufp + *lenp - n, (u8 *)config->result_no_dialtone, n) == 0) {
            return 2;
        }
        n = NetStringLength(config->result_no_carrier);
        if (NetCompareStringsCaseInsensitiveN(*bufp + *lenp - n, (u8 *)config->result_no_carrier, n) == 0) {
            return 3;
        }
        n = NetStringLength(config->result_no_answer);
        if (NetCompareStringsCaseInsensitiveN(*bufp + *lenp - n, (u8 *)config->result_no_answer, n) == 0) {
            return 3;
        }
    }

L122:
    if (config->numeric_result == 0) {
        goto done;
    }
    lobby_modem_reply_value = 0;
    for (idx = 0; idx < *lenp - 1; idx++) {
        if (WaitNstrRecv(*bufp + idx, 1) != 0) {
            return 4;
        }
        if ((*bufp)[idx] == config->terminator) {
            break;
        }
    }

    (*bufp)[idx] = 0;
    p = buf = *bufp;
    n = 0;
    while ((ch = *p++) == (u8)' ') {
        n++;
    }
    q = buf + (s16)n;
    for (;;) {
        c = *q++;
        if (c < '0' || c > '9') {
            break;
        }
        lobby_modem_reply_value = c - '0' + lobby_modem_reply_value * 10;
    }

done:
    lbl_805D7BD8 = lobby_modem_reply_value;
    return 0;
}

s16 WaitNstrRecv(u8 *buf, s16 len) {
    u16 avail;
    s32 now;
    s32 start;
    s32 n;
    s32 remaining;

    remaining = len;
    while (remaining > 0) {
        network_input_available(&avail);
        if ((n = avail) != 0U) {
            if (remaining < n) {
                n = remaining;
            }
            if (recv_network_bytes(buf, n) == 0) {
                buf += n;
                remaining -= n;
                continue;
            }
        }
        get_time_ms(&now);
        if (lobby_modem_abort_flag != 0 || lobby_modem_wait_timeout_ms == 0) {
            lobby_modem_wait_timeout_ms = 0;
            return -1;
        }
        if (lobby_modem_wait_timeout_ms != 0xFFFFFFFF && (u32)(now - lobby_modem_wait_start_ms) > lobby_modem_wait_timeout_ms) {
            lobby_modem_wait_timeout_ms = 0;
            return -1;
        }
        unlock_mutex(lbl_805C18A0.mutex);
        net_sleep_ms(100);
        lock_mutex(lbl_805C18A0.mutex);
    }
    return 0;
}

void cancel_alarm_b(void) {
    NetReleaseMutex(lobby_buffer_pool_alarm_handle);
}

s16 init_buffer_pool(void) {
    lbl_805D7BEC = (saddr)lobby_buffer_pool_base;
    lbl_805D7BF0 = (saddr)lobby_buffer_pool_base;
    lbl_805D7BF4 = (saddr)lobby_buffer_pool_base;
    lobby_buffer_pool_end = (saddr)(lobby_buffer_pool_base + lobby_buffer_pool_size);
    lbl_805D7BFC = lobby_buffer_pool_size;
    if (TLobby__sub_803F96AC(&lobby_buffer_pool_alarm_handle) < 0) {
        return -1;
    }
    reset_buffer_pool();
    return 0;
}

void reset_buffer_pool(void) {
    lbl_805D7C0C = 0;
    lbl_805D7C24 = 0;
    lobby_buffer_pool_state = 0;
    if (lbl_805D7C04 != NULL) {
        lbl_805D7C10 = (uaddr)lbl_805D7C04;
        lbl_805D7C14 = (uaddr)lbl_805D7C04;
        buffer_pool_start = (uaddr)lbl_805D7C04;
        buffer_pool_limit = (saddr)(lbl_805D7C04 + lbl_805D7C08);
        lbl_805D7C20 = lbl_805D7C08;
        return;
    }
    lbl_805D7C10 = 0U;
    lbl_805D7C14 = 0U;
    buffer_pool_start = 0U;
    buffer_pool_limit = 0;
    lbl_805D7C20 = 0;
}
