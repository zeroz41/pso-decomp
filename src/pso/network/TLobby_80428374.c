/* The network stack's modem session (a C library, built with GC/1.2.5n): the session record, the dial-script
 * expansion and its quoted-string parser, timed waits on the modem, and the buffer pool's bounds. */
#include "pso/network/NetworkRuntime.h"
#include "pso/network/NetworkTransport.h"
#include "pso/network/TLobby_80428374.h"
#include "pso/network/ModemRuntime.h"
#include "pso/network/NetworkMessageTransport.h"

#include "types.h"
#include "pso/network/NetStackTypes.h"

/* The script strings are read-only: the short ones are in .sdata2. */
#pragma readonly_strings on

typedef struct RecoveredGlobal_80428374_lbl_805D0A40 {
    s32 value;
    u8 remaining[0x5C];
} RecoveredGlobal_80428374_lbl_805D0A40;

typedef struct RecoveredGlobal_8042839C_lbl_805D0A40 {
    s32 value;
    u8 remaining[0x5C];
} RecoveredGlobal_8042839C_lbl_805D0A40;

#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off

typedef struct RecoveredGlobal_8042E768_lbl_805D1D20 {
    s32 value;
    u8 remaining[0x18];
} RecoveredGlobal_8042E768_lbl_805D1D20;

typedef struct RecoveredGlobal_80427D0C_lbl_805CFC20 {
    s32 value;
    u8 remaining[0xE1C];
} RecoveredGlobal_80427D0C_lbl_805CFC20;

typedef struct RecoveredGlobal_80428360_lbl_805CFC20 {
    s16 value;
    u8 remaining[0xE1E];
} RecoveredGlobal_80428360_lbl_805CFC20;

typedef struct RecoveredGlobal_8042DD70_lbl_805D1D20 {
    s32 value;
    u8 remaining[0x18];
} RecoveredGlobal_8042DD70_lbl_805D1D20;

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
typedef struct Ent_804267F0 {
    s16 count;
    u8 id[6];
} Ent_804267F0;

typedef struct Tbl_804267F0 {
    u8 pad[6];
    Ent_804267F0 ent[6];
} Tbl_804267F0;

s32 TLobby__sub_803F97E8(int);
extern void *lbl_805C18A0[];
extern s16 lobby_modem_abort_flag;
s32 modem_script_next_token(u8 *src, u8 *dst, u8 **next);
s16 TLobby__sub_804293B0(u8 *buf, s16 len);
s16 TLobby__sub_804036FC(u16 *avail);
s16 TLobby__sub_80403730(u8 *dst, u16 n);
extern u32 lobby_modem_wait_start_ms;
extern u32 lobby_modem_wait_timeout_ms;
u8 *TLobby__sub_803FB110(void);
s16 TLobby__sub_804037B0(void *, s32);

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

typedef char RecoveredGlobal_80428374_lbl_805D0A40_size[sizeof(RecoveredGlobal_80428374_lbl_805D0A40) == 0x60 ? 1 : -1];

typedef char RecoveredGlobal_80428360_lbl_805CFC20_size[sizeof(RecoveredGlobal_80428360_lbl_805CFC20) == 0xE20 ? 1 : -1];

void reset_boot_state(void) {
    TLobby__sub_803F77E0((s32 *)&lobby_net_session_state);
}

typedef char RecoveredGlobal_8042839C_lbl_805D0A40_size[sizeof(RecoveredGlobal_8042839C_lbl_805D0A40) == 0x60 ? 1 : -1];
s32 init_modem_session_config(void) {
    init_modem_buffer_config((void *) (&(*(RecoveredGlobal_8042839C_lbl_805D0A40 *)&lobby_net_session_state).value));
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
extern s16 lobby_modem_connect_state;
s32 wait_timeout_loop(void *params);

static inline void modem_flush_input(void) {
    u16 avail;
    u8 discard[2];
    while (TLobby__sub_804036FC(&avail) == 0 && avail != 0 && TLobby__sub_80403730(discard, 1) == 0) {
    }
}

typedef struct ModemPoolView {
    ModemFieldLayout layouts[5];
    u8 pad64[0x18];
    char *names[11];
} ModemPoolView;

static inline s16 modem_find_command(u8 *word, ModemFieldLayout *tbl) {
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
        unlock_mutex((s32)lbl_805C18A0[0]);
        TLobby__sub_803F97E8(100);
        lock_mutex((s32)lbl_805C18A0[0]);
    }
    return ret;
}

/* Runs a modem script line by line (DIAL, SEND, WAIT, DELAY, TERMINAL). */
s16 modem_run_script(u8 *script, ModemScriptSession *sess) {
    s16 modem_script_next_token(u8 *, u8 *, u8 **);
    s16 modem_script_send(void);
    s16 modem_script_dial(u8 *);
    s16 wait_timeout_loop(void *);
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
        if ((cmd = modem_find_command(lobby_net_session_state.token, modem_command_layouts)) == -1) {
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
            ret = modem_script_dial((u8 *)&sess->req);
            break;
        case 1:
            ret = modem_script_send();
            break;
        case 2:
            ret = modem_script_wait(&sess->req);
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
s32 wait_timeout_loop(void *params) {
    u8 *params_u8 = (u8 *)params;
    s32 start;
    s32 now;
    s16 *p;
    u32 limit;
    s32 ret;
    ret = 0;
    get_time_ms(&start);
    p = **(s16 ***)((s8 *)&lobby_net_session_state + 0x10);
    if (p == NULL) {
        limit = *(s16 *)(params_u8 + 4) * 1000;
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
        unlock_mutex((int)lbl_805C18A0[0]);
        TLobby__sub_803F97E8(100);
        lock_mutex((int)lbl_805C18A0[0]);
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

/* The script's "wait" command (index 2 of the command names). */
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
s32 modem_script_send(void) {
    u8 *base;
    u8 ***pp;
    u8 **out;
    u8 **keys;
    s32 di;
    s32 si;
    s32 j;
    s32 len;
    s16 r;
    u8 c[4];
    u16 avail;

    base = (u8 *)&lobby_net_session_state;
    out = (u8 **)(base + 0x2c);
    **out = 0;
    keys = (u8 **)modem_subst_keys;
    pp = (u8 ***)(base + 0x10);
    di = 0;
    si = 0;
    while ((*pp)[0][si] != 0) {
        for (j = 0; keys[j] != NULL; j++) {
            len = NetStringLength((char *)keys[j]);
            if (NetCompareStringsN((char *)keys[j], (char *)((*pp)[0] + si), len) == 0) {
                break;
            }
        }
        if (keys[j] == NULL) {
            (*out)[di] = (*pp)[0][si];
            si++;
            di++;
        } else {
            NetAppendString((char *)(*out + di), (char *)(*(u8 ***)base)[j]);
            di += NetStringLength((char *)(*(u8 ***)base)[j]);
            si += NetStringLength((char *)keys[j]);
        }
    }
    (*out)[di] = 0;
    do {
        r = TLobby__sub_804036FC(&avail);
        if (r != 0 || avail == 0) {
            break;
        }
        r = TLobby__sub_80403730(c, 1);
    } while (r == 0);
    if (TLobby__sub_804037B0(*out, (u16)NetStringLength((char *)*out)) != 0) {
        return 4;
    }
    return 0;
}

u8 *TLobby__sub_803FB110(void);
s32 TLobby__sub_804290D4(s32 idx);
/* Builds the dial string from the session settings (prefix, number from the profile, optional suffix) and starts the call; request: s16 +0 = use second number, s16 +2 = has suffix, s16 +4 = script index, +0xC = suffix string (layout partly guessed). */
s32 modem_script_dial(u8 *request) {
    u8 *p;
    u8 *base;
    char **out;
    char **keys;
    char ***pp;
    s32 dlen;
    s32 k;
    s32 j;
    s32 len;
    s16 r;
    u8 c[4];
    u16 avail;

    base = (u8 *)&lobby_net_session_state;
    p = TLobby__sub_803FB110();
    if (p == NULL) {
        return -3;
    }
    out = &((char **)base)[10];
    **out = 0;
    if (*(s16 *)request == 0) {
        if (*(void **)(p + 0xc) != NULL) {
            NetCopyString(*out, (const char *)(*(void **)(p + 0xc)));
        }
    } else {
        if (*(void **)(p + 0x10) != NULL) {
            NetCopyString(*out, (const char *)(*(void **)(p + 0x10)));
        }
    }
    if (*(s16 *)(request + 2) != 0) {
        NetAppendString(*out, *(const char **)(request + 0xc));
    }
    dlen = NetStringLength((const char *)*out);
    keys = (char **)modem_subst_keys;
    pp = (char ***)(base + 0x10);
    k = 0;
    while ((u8)(*pp)[0][k] != 0) {
        for (j = 0; keys[j] != NULL; j++) {
            len = NetStringLength((const char *)keys[j]);
            if (NetCompareStringsN(keys[j], (*pp)[0] + k, len) == 0) {
                break;
            }
        }
        if (keys[j] == NULL) {
            (*out)[dlen] = (*pp)[0][k];
            k++;
            dlen++;
        } else {
            NetAppendString(*out + dlen, (*(char ***)base)[j]);
            dlen += NetStringLength((const char *)(*(char ***)base)[j]);
            k += NetStringLength((const char *)keys[j]);
        }
    }
    if (dlen > 0 && *(u8 *)(p + 0x38) != (u8)(*out)[dlen - 1]) {
        (*out)[dlen++] = *(u8 *)(p + 0x38);
    }
    (*out)[dlen] = 0;
    do {
        r = TLobby__sub_804036FC(&avail);
        if (r != 0 || avail == 0) {
            break;
        }
        r = TLobby__sub_80403730(c, 1);
    } while (r == 0);
    if (TLobby__sub_804037B0(*out, (u16)NetStringLength((const char *)*out)) != 0) {
        return 4;
    }
    return TLobby__sub_804290D4(*(s16 *)(request + 4));
}

char* NetCopyString(char* destination, const char* source);
#pragma push
#pragma cplusplus off
#pragma pop
#pragma push
#pragma cplusplus off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma dont_inline off
void modem_script_store_field(s16 type, s16 index, u8 *src, s16 *nstr, s16 *nint) {
    void NetCopyString(void *, u8 *);
    s32 n;
    u8 *dst;
    s16 i;
    s16 value;
    u8 c;

    if (modem_command_layouts[type].kind[index] == 0) {
        n = *nstr;
        dst = (u8 *)lobby_net_session_state.strbuf + n * lobby_net_session_state.strstride;
        NetCopyString(dst, src);
        lobby_net_session_state.fields[index] = dst;
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
#pragma pop

s32 modem_script_next_token(u8 *src, u8 *dst, u8 **next) {
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

extern s32 lobby_modem_reply_value;
extern s32 lbl_805D7BD8;
s32 NetCompareStringsCaseInsensitiveN(u8 *a, u8 *b, u32 n);
s32 TLobby__sub_804290D4(s32 idx) {
    s16 *lenp;
    u8 **bufp;
    u8 *base;
    u8 *sym;
    s32 c;
    u8 *q;
    u8 *p;
    u8 *buf;
    s32 n;
    u8 ch;

    base = TLobby__sub_803FB110();
    if (base == NULL) {
        return 1;
    }
    get_time_ms((s32 *)&lobby_modem_wait_start_ms);
    if ((s16)idx == 0x7fff) {
        lobby_modem_wait_timeout_ms = -1;
    } else {
        lobby_modem_wait_timeout_ms = (s16)idx * 1000;
    }
    sym = (u8 *)&lobby_net_session_state;
    bufp = (u8 **)(sym + 0x38);
    lenp = (s16 *)(sym + 0x48);
    NetMemset(*bufp, 0, *lenp);
    for (;;) {
        NetMemmove(*bufp, *bufp + 1, *lenp - 1);
        if (TLobby__sub_804293B0(*bufp + *lenp - 1, 1) != 0) {
            return 4;
        }
        n = NetStringLength((const char *)*(u8 **)(base + 0x1c));
        if (NetCompareStringsCaseInsensitiveN(*bufp + *lenp - n, *(u8 **)(base + 0x1c), n) == 0) {
            goto L122;
        }
        n = NetStringLength((const char *)*(u8 **)(base + 0x20));
        if (NetCompareStringsCaseInsensitiveN(*bufp + *lenp - n, *(u8 **)(base + 0x20), n) == 0) {
            return 2;
        }
        n = NetStringLength((const char *)*(u8 **)(base + 0x24));
        if (NetCompareStringsCaseInsensitiveN(*bufp + *lenp - n, *(u8 **)(base + 0x24), n) == 0) {
            return 2;
        }
        n = NetStringLength((const char *)*(u8 **)(base + 0x28));
        if (NetCompareStringsCaseInsensitiveN(*bufp + *lenp - n, *(u8 **)(base + 0x28), n) == 0) {
            return 2;
        }
        n = NetStringLength((const char *)*(u8 **)(base + 0x2c));
        if (NetCompareStringsCaseInsensitiveN(*bufp + *lenp - n, *(u8 **)(base + 0x2c), n) == 0) {
            return 3;
        }
        n = NetStringLength((const char *)*(u8 **)(base + 0x30));
        if (NetCompareStringsCaseInsensitiveN(*bufp + *lenp - n, *(u8 **)(base + 0x30), n) == 0) {
            return 3;
        }
    }

L122:
    if (*(s16 *)(base + 8) == 0) {
        goto done;
    }
    lobby_modem_reply_value = 0;
    for (idx = 0; idx < *lenp - 1; idx++) {
        if (TLobby__sub_804293B0(*bufp + idx, 1) != 0) {
            return 4;
        }
        if ((*bufp)[idx] == base[0x38]) {
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
        get_time_ms(&now);
        if (lobby_modem_abort_flag != 0 || lobby_modem_wait_timeout_ms == 0) {
            lobby_modem_wait_timeout_ms = 0;
            return -1;
        }
        if (lobby_modem_wait_timeout_ms != 0xFFFFFFFF && (u32)(now - lobby_modem_wait_start_ms) > lobby_modem_wait_timeout_ms) {
            lobby_modem_wait_timeout_ms = 0;
            return -1;
        }
        unlock_mutex((int)lbl_805C18A0[0]);
        TLobby__sub_803F97E8(100);
        lock_mutex((int)lbl_805C18A0[0]);
    }
    return 0;
}

void cancel_alarm_b(void) {
    NetReleaseMutex(lobby_buffer_pool_alarm_handle);
}

s32 init_buffer_pool(void) {
    lbl_805D7BEC = lobby_buffer_pool_base;
    lbl_805D7BF0 = lobby_buffer_pool_base;
    lbl_805D7BF4 = lobby_buffer_pool_base;
    lobby_buffer_pool_end = lobby_buffer_pool_base + lobby_buffer_pool_size;
    lbl_805D7BFC = lobby_buffer_pool_size;
    if (TLobby__sub_803F96AC(&lobby_buffer_pool_alarm_handle, (void *)lobby_buffer_pool_base, (void *)lobby_buffer_pool_size) < 0) {
        return -1;
    }
    reset_buffer_pool();
    return 0;
}

void reset_buffer_pool(void) {
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
