#include "pso/network/NetworkRuntime.h"
#include "pso/network/NetworkTransport.h"
#include "pso/unk/TLobby_80428374.h"
#include "pso/network/ModemRuntime.h"
#include "pso/network/NetworkMessageTransport.h"

#include "types.h"
#include "pso/unk/TLobby.h"
#include "pso/network/TUdpSocket.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/unk/TLobby_803FAEA0.h"

#pragma readonly_strings on
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off

struct RecoveredGlobal_8042E768_lbl_805D1D20 {
    s32 value;
    u8 remaining[0x18];
};

struct RecoveredGlobal_80427D0C_lbl_805CFC20 {
    s32 value;
    u8 remaining[0xE1C];
};

struct RecoveredGlobal_80428360_lbl_805CFC20 {
    s16 value;
    u8 remaining[0xE1E];
};

struct RecoveredGlobal_8042DD70_lbl_805D1D20 {
    s32 value;
    u8 remaining[0x18];
};

typedef struct Names_8042E57C {
    char *name[6];
} Names_8042E57C;

typedef struct Names_8042E628 {
    char *name[4];
} Names_8042E628;

typedef struct Names_8042E6C4 {
    char *name[5];
} Names_8042E6C4;

typedef struct Names_8042E7B8 {
    char *name[3];
} Names_8042E7B8;

typedef struct Ent_80426894 {
    s16 count;
    u8 id[6];
} Ent_80426894;

typedef struct Tbl_80426894 {
    u8 pad[6];
    Ent_80426894 ent[6];
} Tbl_80426894;

typedef struct Ent_80425870 {
    s32 used;
    u32 f4;
    u32 base;
} Ent_80425870;

typedef struct Ent_80427C6C {
    u16 pad0;
    u16 id;
    u8 rest[0xE10];
} Ent_80427C6C;

extern u8 lbl_805CF240[0xA0];
extern u8 TLobby__pppoe_message_queue[0xA0];
extern u8 lbl_805CF380[0x48];
extern "C" {
s32 TLobby__sub_803F77E0(void *);
ModemSessionState lobby_net_session_state;
extern u32 lobby_buffer_pool_alarm_handle;
s16 TLobby__sub_803F96AC(void *, void *, void *);
extern s32 lobby_buffer_pool_base;
extern s32 lobby_buffer_pool_size;
extern s32 lbl_805D7BEC;
extern s32 lbl_805D7BF0;
extern s32 lbl_805D7BF4;
extern s32 lobby_buffer_pool_end;
extern s32 lbl_805D7BFC;
extern u8 lbl_805CF380[];
extern u8 TLobby__pppoe_message_queue[];
typedef struct Ent_804267F0 {
    s16 count;
    u8 id[6];
} Ent_804267F0;

typedef struct Tbl_804267F0 {
    u8 pad[6];
    Ent_804267F0 ent[6];
} Tbl_804267F0;

extern u8 lbl_805CF240[];
s32 TLobby__sub_803F97E8(int);
extern void *lbl_805C18A0[];
extern s16 lbl_805D7A86;
extern s16 lbl_805D7A8A;
s16 modem_script_next_token(u8 *src, u8 *dst, u8 **next);
s16 TLobby__sub_804293B0(u8 *buf, s16 len);
s16 TLobby__sub_804036FC(u16 *avail);
s16 TLobby__sub_80403730(u8 *dst, u16 n);
s16 TLobby__sub_804037B0(void *src, u16 len);
extern u32 lbl_805D7BD0;
extern u32 lbl_805D7BD4;
extern s32 lbl_805D7BD8;
extern s32 lbl_805D7BDC;
s32 NetCompareStringsCaseInsensitiveN(u8 *a, u8 *b, u32 n);

#pragma push
#pragma opt_propagation off
#pragma pop

#pragma push
#pragma dont_inline off
#pragma inline_depth(4)
#pragma pop

#define arg0 ((s32)argp)
#undef arg0

#pragma push
#pragma dont_inline on
#pragma pop

typedef char RecoveredGlobal_80427D0C_lbl_805CFC20_size[sizeof(RecoveredGlobal_80427D0C_lbl_805CFC20) == 0xE20 ? 1 : -1];

extern u32 lbl_805D7C04;
extern s32 lbl_805D7C08;
extern s32 lbl_805D7C0C;
extern u32 lbl_805D7C10;
extern u32 lbl_805D7C14;
extern u32 TLobby__buffer_pool_start;
extern s32 TLobby__buffer_pool_limit;
extern s32 lbl_805D7C20;
extern s32 lbl_805D7C24;
extern s32 lobby_buffer_pool_state;

typedef char ModemSessionState_size[sizeof(ModemSessionState) == 0x60 ? 1 : -1];

typedef char RecoveredGlobal_80428360_lbl_805CFC20_size[sizeof(RecoveredGlobal_80428360_lbl_805CFC20) == 0xE20 ? 1 : -1];

void TLobby::reset_boot_state() {
    TLobby__sub_803F77E0(&lobby_net_session_state);
}
}

s32 init_modem_session_config(void) {
    init_modem_buffer_config(&lobby_net_session_state);
    return 0;
}

// Per script command: how many fields it has, then each field's kind
// (0 a string, 1 a decimal number).
struct ModemFieldLayout {
    s32 count;
    s32 kind[4];
};

static const ModemFieldLayout modem_command_layouts[5] = {
    {1, {0, 0, 0, 0}},
    {1, {0, 0, 0, 0}},
    {2, {0, 1, 0, 0}},
    {1, {1, 0, 0, 0}},
    {0, {0, 0, 0, 0}},
};

// Script command names, upper and lower case per command.
static const char *const modem_command_names[] = {
    "DIAL", "dial", "SEND", "send", "WAIT", "wait", "DELAY", "delay", "TERMINAL", "terminal", NULL,
};

// Substitution keys of a script line (ModemSessionState::subst holds the values).
static const char *const modem_subst_keys[] = {"%t", "%u", "%p", "%i", "%%", NULL};

static inline void modem_flush_input(void) {
    u16 avail;
    u8 discard[2];
    while (TLobby__sub_804036FC(&avail) == 0 && avail != 0 && TLobby__sub_80403730(discard, 1) == 0) {
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
    lbl_805D7A8A = 9;
    for (;;) {
        if (lbl_805D7A8A == 2) {
            break;
        }
        if (lbl_805D7A86 != 0 || lbl_805D7A8A != 9) {
            ret = 4;
            break;
        }
        TUdpSocket::unlock_mutex((int)lbl_805C18A0[0]);
        TLobby__sub_803F97E8(100);
        TLobby::lock_mutex((int)lbl_805C18A0[0]);
    }
    return ret;
}

// Runs a modem script line by line (the commands of modem_command_names).
s16 modem_run_script(u8 *script, ModemScriptSession *sess) {
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
        lobby_net_session_state.fields[3] = NULL;
        lobby_net_session_state.fields[2] = NULL;
        lobby_net_session_state.fields[1] = NULL;
        lobby_net_session_state.fields[0] = NULL;
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
            modem_script_store_field(cmd, i, (char *)lobby_net_session_state.token, &nstr, &nint);
        }
        switch (cmd) {
        case 0:
            ret = modem_script_dial(&sess->req);
            break;
        case 1:
            ret = modem_script_send();
            break;
        case 2:
            ret = modem_script_wait(&sess->req);
            break;
        case 3:
            ret = ((TLobby *)&sess->req)->wait_timeout_loop();
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

s16 TLobby::wait_timeout_loop() {
    u8 *arg0 = (u8 *)this;
    s32 start;
    s32 now;
    s16 *p;
    u32 limit;
    s16 ret;
    ret = 0;
    TLobby::get_time_ms(&start);
    p = (s16 *)lobby_net_session_state.fields[0];
    if (p == NULL) {
        limit = *(s16 *)(arg0 + 4) * 1000;
    } else {
        limit = *p * 1000;
    }
    for (;;) {
        if (lbl_805D7A86 != 0) {
            ret = 4;
            break;
        }
        TLobby::get_time_ms(&now);
        if ((u32)(now - start) > limit) {
            break;
        }
        TUdpSocket::unlock_mutex((int)lbl_805C18A0[0]);
        TLobby__sub_803F97E8(100);
        TLobby::lock_mutex((int)lbl_805C18A0[0]);
    }
    return ret;
}

inline s16 modem_wait_for_string(u8 *s, s16 n, s16 timeout) {
    TLobby::get_time_ms((s32 *)&lbl_805D7BD0);
    lbl_805D7BD4 = timeout * 1000;
    if (n > lobby_net_session_state.window_len) {
        n = lobby_net_session_state.window_len;
    }
    if (TLobby__sub_804293B0(lobby_net_session_state.window, n) != 0) {
        return -1;
    }
    while (NetCompareStringsCaseInsensitiveN(lobby_net_session_state.window, s, n) != 0) {
        NetMemmove(lobby_net_session_state.window, lobby_net_session_state.window + 1, n - 1);
        if (TLobby__sub_804293B0(lobby_net_session_state.window + n - 1, 1) != 0) {
            return -1;
        }
    }
    return 0;
}

// The script's "wait" command (index 2 of modem_command_names).
s16 modem_script_wait(ModemRequest *req) {
    s32 len;
    s32 pos;
    s32 k;
    s16 timeout;

    len = 0;
    pos = 0;
    lobby_net_session_state.expect[0] = 0;
    while (lobby_net_session_state.fields[0][pos] != 0) {
        for (k = 0; modem_subst_keys[k] != NULL; k++) {
            if (NetCompareStringsN(modem_subst_keys[k], (const char *)lobby_net_session_state.fields[0] + pos,
                                     NetStringLength(modem_subst_keys[k])) == 0) {
                break;
            }
        }
        if (modem_subst_keys[k] == NULL) {
            lobby_net_session_state.expect[len] = lobby_net_session_state.fields[0][pos];
            pos++;
            len++;
        } else {
            NetAppendString((char *)lobby_net_session_state.expect + len, lobby_net_session_state.subst[k]);
            len += NetStringLength(lobby_net_session_state.subst[k]);
            pos += NetStringLength(modem_subst_keys[k]);
        }
    }
    lobby_net_session_state.expect[len] = 0;
    if (lobby_net_session_state.fields[1] == NULL) {
        timeout = req->timeout;
    } else {
        timeout = *(s16 *)lobby_net_session_state.fields[1];
    }
    if (modem_wait_for_string(lobby_net_session_state.expect, NetStringLength((char *)lobby_net_session_state.expect), timeout) != 0) {
        return 4;
    }
    return 0;
}

// The script's "send" command (index 1 of modem_command_names).
s16 modem_script_send(void) {
    s32 out;
    s32 pos;
    s32 k;
    u8 discard[4];
    u16 avail;

    out = 0;
    pos = 0;
    lobby_net_session_state.out[0] = 0;
    while (lobby_net_session_state.fields[0][pos] != 0) {
        for (k = 0; modem_subst_keys[k] != NULL; k++) {
            if (NetCompareStringsN(modem_subst_keys[k], (const char *)lobby_net_session_state.fields[0] + pos,
                                     NetStringLength(modem_subst_keys[k])) == 0) {
                break;
            }
        }
        if (modem_subst_keys[k] == NULL) {
            lobby_net_session_state.out[out] = lobby_net_session_state.fields[0][pos];
            pos++;
            out++;
        } else {
            NetAppendString((char *)lobby_net_session_state.out + out, lobby_net_session_state.subst[k]);
            out += NetStringLength(lobby_net_session_state.subst[k]);
            pos += NetStringLength(modem_subst_keys[k]);
        }
    }
    lobby_net_session_state.out[out] = 0;
    while (TLobby__sub_804036FC(&avail) == 0 && avail != 0 && TLobby__sub_80403730(discard, 1) == 0) {
    }
    if (TLobby__sub_804037B0(lobby_net_session_state.out, NetStringLength((char *)lobby_net_session_state.out)) != 0) {
        return 4;
    }
    return 0;
}

// The script's "dial" command (index 0 of modem_command_names).
s16 modem_script_dial(ModemRequest *req) {
    ModemConfig *cfg;
    s32 len;
    s32 pos;
    s32 k;
    u8 discard[4];
    u16 avail;

    cfg = (ModemConfig *)TLobby__sub_803FB110();
    if (cfg == NULL) {
        return -3;
    }
    lobby_net_session_state.cmd[0] = 0;
    if (req->type == 0) {
        if (cfg->prefix0 != NULL) {
            NetCopyString((char *)lobby_net_session_state.cmd, cfg->prefix0);
        }
    } else if (cfg->prefix1 != NULL) {
        NetCopyString((char *)lobby_net_session_state.cmd, cfg->prefix1);
    }
    if (req->has_arg != 0) {
        NetAppendString((char *)lobby_net_session_state.cmd, req->arg);
    }
    len = NetStringLength((char *)lobby_net_session_state.cmd);
    pos = 0;
    while (lobby_net_session_state.fields[0][pos] != 0) {
        for (k = 0; modem_subst_keys[k] != NULL; k++) {
            if (NetCompareStringsN(modem_subst_keys[k], (const char *)lobby_net_session_state.fields[0] + pos,
                                     NetStringLength(modem_subst_keys[k])) == 0) {
                break;
            }
        }
        if (modem_subst_keys[k] == NULL) {
            lobby_net_session_state.cmd[len] = lobby_net_session_state.fields[0][pos];
            pos++;
            len++;
        } else {
            NetAppendString((char *)lobby_net_session_state.cmd + len, lobby_net_session_state.subst[k]);
            len += NetStringLength(lobby_net_session_state.subst[k]);
            pos += NetStringLength(modem_subst_keys[k]);
        }
    }
    if (len > 0 && cfg->terminator != lobby_net_session_state.cmd[len - 1]) {
        lobby_net_session_state.cmd[len++] = cfg->terminator;
    }
    lobby_net_session_state.cmd[len] = 0;
    while (TLobby__sub_804036FC(&avail) == 0 && avail != 0 && TLobby__sub_80403730(discard, 1) == 0) {
    }
    if (TLobby__sub_804037B0(lobby_net_session_state.cmd, NetStringLength((char *)lobby_net_session_state.cmd)) != 0) {
        return 4;
    }
    return TLobby__sub_804290D4(req->timeout);
}

// Stores a parsed argument as a string or number field by the command's layout;
// name inferred from that behaviour.
void modem_script_store_field(s16 type, s16 index, char *src, s16 *nstr, s16 *nint) {
    s32 n;
    char *dst;
    s16 i;
    s16 value;
    u8 c;

    if (modem_command_layouts[type].kind[index] == 0) {
        n = *nstr;
        dst = lobby_net_session_state.strbuf + n * lobby_net_session_state.strstride;
        NetCopyString(dst, src);
        lobby_net_session_state.fields[index] = (u8 *)dst;
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
        lobby_net_session_state.fields[index] = (u8 *)&lobby_net_session_state.ints[n];
        *nint = n + 1;
    }
}

// Copies the next argument of a script line (a quoted string with \r \n \\ \" \x
// escapes, or a bare word) to dst; name inferred from that behaviour.
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

inline u8 *modem_skip_spaces(u8 *s) {
    s16 n = 0;
    u8 *p = s;
    while (*p++ == 0x20U) {
        n++;
    }
    return s + n;
}

s16 TLobby__sub_804290D4(s16 timeout) {
    ModemConfig *cfg;
    s32 i;
    u8 *q;
    u8 c;
    s32 len;

    cfg = (ModemConfig *)TLobby__sub_803FB110();
    if (cfg == NULL) {
        return 1;
    }
    TLobby::get_time_ms((s32 *)&lbl_805D7BD0);
    if (timeout == 0x7FFF) {
        lbl_805D7BD4 = 0xFFFFFFFF;
    } else {
        lbl_805D7BD4 = timeout * 1000;
    }
    NetMemset(lobby_net_session_state.rxbuf, 0, lobby_net_session_state.rxlen);
    for (;;) {
        NetMemmove(lobby_net_session_state.rxbuf, lobby_net_session_state.rxbuf + 1, lobby_net_session_state.rxlen - 1);
        if (TLobby__sub_804293B0(lobby_net_session_state.rxbuf + lobby_net_session_state.rxlen - 1, 1) != 0) {
            return 4;
        }
        len = NetStringLength(cfg->result_ok);
        if (NetCompareStringsCaseInsensitiveN(lobby_net_session_state.rxbuf + lobby_net_session_state.rxlen - len, (u8 *)cfg->result_ok, len) == 0) {
            break;
        }
        len = NetStringLength(cfg->result_error);
        if (NetCompareStringsCaseInsensitiveN(lobby_net_session_state.rxbuf + lobby_net_session_state.rxlen - len, (u8 *)cfg->result_error, len) == 0) {
            return 2;
        }
        len = NetStringLength(cfg->result_busy);
        if (NetCompareStringsCaseInsensitiveN(lobby_net_session_state.rxbuf + lobby_net_session_state.rxlen - len, (u8 *)cfg->result_busy, len) == 0) {
            return 2;
        }
        len = NetStringLength(cfg->result_no_dialtone);
        if (NetCompareStringsCaseInsensitiveN(lobby_net_session_state.rxbuf + lobby_net_session_state.rxlen - len, (u8 *)cfg->result_no_dialtone, len) == 0) {
            return 2;
        }
        len = NetStringLength(cfg->result_no_carrier);
        if (NetCompareStringsCaseInsensitiveN(lobby_net_session_state.rxbuf + lobby_net_session_state.rxlen - len, (u8 *)cfg->result_no_carrier, len) == 0) {
            return 3;
        }
        len = NetStringLength(cfg->result_no_answer);
        if (NetCompareStringsCaseInsensitiveN(lobby_net_session_state.rxbuf + lobby_net_session_state.rxlen - len, (u8 *)cfg->result_no_answer, len) == 0) {
            return 3;
        }
    }
    if (cfg->numeric_result != 0) {
        lbl_805D7BDC = 0;
        for (i = 0; i < lobby_net_session_state.rxlen - 1; i++) {
            if (TLobby__sub_804293B0(lobby_net_session_state.rxbuf + i, 1) != 0) {
                return 4;
            }
            if (cfg->terminator == lobby_net_session_state.rxbuf[i]) {
                break;
            }
        }
        lobby_net_session_state.rxbuf[i] = 0;
        q = modem_skip_spaces(lobby_net_session_state.rxbuf);
        for (;;) {
            c = *q++;
            if (c < '0' || c > '9') {
                break;
            }
            lbl_805D7BDC = lbl_805D7BDC * 10 + (c - '0');
        }
    }
    lbl_805D7BD8 = lbl_805D7BDC;
    return 0;
}

s16 TLobby__sub_804293B0(u8 *buf, s16 len) {
    u16 avail;
    s32 now;
    s32 start;
    s32 n;
    s32 remaining;

    remaining = len;
    while (remaining > 0) {
        TLobby__sub_804036FC(&avail);
        if ((n = avail) != 0U) {
            if (remaining < n) {
                n = remaining;
            }
            if (TLobby__sub_80403730(buf, n) == 0) {
                buf += n;
                remaining -= n;
                continue;
            }
        }
        TLobby::get_time_ms(&now);
        if (lbl_805D7A86 != 0 || lbl_805D7BD4 == 0) {
            lbl_805D7BD4 = 0;
            return -1;
        }
        if (lbl_805D7BD4 != 0xFFFFFFFF && (u32)(now - lbl_805D7BD0) > lbl_805D7BD4) {
            lbl_805D7BD4 = 0;
            return -1;
        }
        TUdpSocket::unlock_mutex((int)lbl_805C18A0[0]);
        TLobby__sub_803F97E8(100);
        TLobby::lock_mutex((int)lbl_805C18A0[0]);
    }
    return 0;
}

void TLobby::cancel_alarm_b() {
    NetReleaseMutex(lobby_buffer_pool_alarm_handle);
}

s32 TLobby::init_buffer_pool() {
    lbl_805D7BEC = lobby_buffer_pool_base;
    lbl_805D7BF0 = lobby_buffer_pool_base;
    lbl_805D7BF4 = lobby_buffer_pool_base;
    lobby_buffer_pool_end = lobby_buffer_pool_base + lobby_buffer_pool_size;
    lbl_805D7BFC = lobby_buffer_pool_size;
    if (TLobby__sub_803F96AC(&lobby_buffer_pool_alarm_handle, (void *)lobby_buffer_pool_base, (void *)lobby_buffer_pool_size) < 0) {
        return -1;
    }
    TLobby::reset_buffer_pool();
    return 0;
}

void TLobby::reset_buffer_pool() {
    lbl_805D7C0C = 0;
    lbl_805D7C24 = 0;
    lobby_buffer_pool_state = 0;
    if ((u32) lbl_805D7C04 != 0U) {
        lbl_805D7C10 = lbl_805D7C04;
        lbl_805D7C14 = lbl_805D7C04;
        TLobby__buffer_pool_start = lbl_805D7C04;
        TLobby__buffer_pool_limit = lbl_805D7C04 + lbl_805D7C08;
        lbl_805D7C20 = lbl_805D7C08;
        return;
    }
    lbl_805D7C10 = 0U;
    lbl_805D7C14 = 0U;
    TLobby__buffer_pool_start = 0U;
    TLobby__buffer_pool_limit = 0;
    lbl_805D7C20 = 0;
}

#pragma push
#pragma opt_common_subs off
typedef char RecoveredGlobal_8042DD70_lbl_805D1D20_size[sizeof(RecoveredGlobal_8042DD70_lbl_805D1D20) == 0x1C ? 1 : -1];
#pragma pop

typedef char RecoveredGlobal_8042E768_lbl_805D1D20_size[sizeof(RecoveredGlobal_8042E768_lbl_805D1D20) == 0x1C ? 1 : -1];
