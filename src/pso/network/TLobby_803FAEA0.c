/* The network stack's session control (a C library, built with GC/1.2.5n): bringing the stack up and down, the
 * login name, the connection configuration record and its status, PPP authentication and the session timeout. */
#include "types.h"
#include "pso/network/TLobby_803FCF44.h"
#include "pso/network/TLobby_804050DC.h"
#include "pso/network/TLobby_803FC178.h"
#include "pso/network/NetworkRuntime.h"
#include "pso/network/NetworkTransport.h"
#include "pso/network/TLobby_80428374.h"
#include "pso/network/TLobby_803FAEA0.h"

extern RecoveredGlobal_804050DC_lbl_805C18A0 lbl_805C18A0;
extern RecoveredGlobal_803FD520_lbl_805C0310 lobby_net_buffer_desc_b;
s16 TLobby__sub_803FB358(NetLinkStatus *status);
extern u16 ppp_auth_protocol;
void TLobby__sub_803F97E8(int);

u32 lbl_805BFF68[52];
u32 lbl_805C0038[82];
#define lbl_805BFF68 (*(RecoveredGlobal_803FB110_lbl_805BFF68 *)lbl_805BFF68)
#define lbl_805C0038 ((u8 *)lbl_805C0038)

typedef struct LobbyCfg_803FB7A4 {
    u16 flags;
    s16 h2;
    u8 pad4[0x4];
    s32 t8;
    s32 w0C;
    s32 w10;
    u8 pad14[0x4];
    void (*cb)(s16, s32);
    s16 h1C;
    s16 h1E;
    s16 h20;
    u8 pad22[0x42];
    s32 w64;
    s32 w68;
    s32 w6C;
    s32 w70;
    s32 w74;
    s32 w78;
    s16 h7C;
    s16 h7E;
    s16 h80;
    u8 pad82[0x8];
    s16 h8A;
    s16 h8C;
    u8 pad8E[0xA];
    s16 h98;
    s16 h9A;
    s32 w9C;
    u16 uA0;
    u16 uA2;
    s16 hA4;
    u8 padA6[0x2];
    s32 wA8;
    s32 wAC;
    s32 wB0;
    s32 wB4;
    s32 wB8;
    s32 wBC;
    u8 bufC0[0x8];
    u8 bufC8[0x8];
} LobbyCfg_803FB7A4;

typedef struct LobbyPkt_803FB7A4 {
    s32 a;
    u16 b;
    u16 c;
    s32 d;
    u16 e;
    u16 f;
    s32 g;
    s32 h;
} LobbyPkt_803FB7A4;

#define LOBBY_NOTIFY() do { if (g->cb != NULL) { unlock_mutex(lbl_805C18A0.value); g->cb(lbl_805D7A82, 0); lock_mutex(lbl_805C18A0.value); } } while (0)
#define LOBBY_ABORT(code, st) do { lbl_805D7A82 = (code); lobby_modem_connect_state = (st); LOBBY_NOTIFY(); return 0; } while (0)

s32 NetControl(s32 cmd, s32 arg) {
    switch (cmd) {
    case 1:
        TLobby__sub_804050DC(arg);
        return 0;
    }
    return -1;
}

typedef struct LoginCfg_803FAEDC {
    u8 pad[0x14];
    char *user;
    u8 pad18[0x70];
    s16 state;
    s16 mode;
    u8 pad8C[8];
    char *prefix;
} LoginCfg_803FAEDC;
typedef struct H_803FB120 { u8 pad[0x28]; u8 *name; u8 pad2C[0x20]; void *v4C; } H_803FB120;
extern H_803FB120 lobby_net_session_state;

s16 TLobby__sub_803FAEDC(LoginCfg_803FAEDC *cfg) {
    u32 plen;
    u8 *p;
    u8 **pname = &lobby_net_session_state.name;
    u32 len;
    u8 *buf = lobby_net_session_state.name;

    if (cfg->user == NULL) {
        return 1;
    }
    len = NetStringLength((const char*)cfg->user);
    if (cfg->mode == 1 && cfg->prefix != NULL) {
        plen = NetStringLength((const char*)cfg->prefix);
        if (plen + len > 59) {
            return 1;
        }
        NetMemcpy(buf, cfg->prefix, plen);
        p = buf + plen;
        NetMemcpy(p, cfg->user, len);
        p[len] = 0;
    } else {
        if (len > 59) {
            return 1;
        }
        NetMemcpy(buf, cfg->user, len);
        buf[len] = 0;
    }
    if (map_state_to_code((s32)*pname, cfg->state) < 0) {
        return 1;
    }
    return 0;
}

s32 TLobby__sub_803FAFDC(void) {
    stop_network_thread();
    init_net_state_a();
    init_net_block_620();
    TLobby__sub_803F7678();
    reset_boot_state();
    TLobby__sub_803FD0C0();
    init_net_block_18A0();
    init_net_state_c();
    return 0;
}

s16 TLobby__sub_803FD10C(void);
void TLobby__sub_804061FC(int);
typedef struct Sess_803FB01C { u8 pad[0x1C]; u8 buf[0x60]; u8 rest[0x54]; } Sess_803FB01C;

s16 init_net_session(void) {
    s16 i;
    s16 ret;
    Sess_803FB01C *p;

    init_net_subsystem_block();
    run_net_init_step();
    ret = TLobby__sub_803FD10C();
    if (ret < 0) {
        return -1;
    }
    init_modem_session_config();
    TLobby__sub_803F767C();
    init_net_block_620_secondary();
    init_net_state_b();
    NetMemset(&lbl_805BFF68, 0, sizeof(lbl_805BFF68));
    p = (Sess_803FB01C *)&lbl_805BFF68;
    i = 0;
    while (i < 1) {
        NetMemcpy(p->buf, lobby_net_session_state.v4C, 0x60);
        i++;
        p++;
    }
    lobby_modem_connect_state = 0;
    lbl_805D7A88 = 0;
    lobby_modem_abort_flag = 0;
    lbl_805D7A84 = 0;
    lbl_805D7A82 = 0;
    lbl_805D7A7E = 0;
    if (reset_network_timer_list() == 0) {
        TLobby__sub_804061FC(0);
    }
    start_network_thread();
    return ret;
}

u8 *TLobby__sub_803FB110(void) {
    return (u8 *)&lbl_805BFF68.value + 0x1C;
}

typedef struct G_803FB120 { u8 pad[0x1C]; u8 buf[0x60]; } G_803FB120;
u8 *copy_name_buffer(void *src) {
    G_803FB120 *g = (G_803FB120 *)&lbl_805BFF68;
    if (src == 0) {
        NetMemcpy(g->buf, lobby_net_session_state.v4C, 0x60);
    } else {
        NetMemcpy(g->buf, src, 0x60);
    }
    return g->buf;
}

s16 NetGetLinkStatus(NetLinkStatus *status) {
    return TLobby__sub_803FB358(status);
}

s32 NetLinkDisconnect(NetWaitParam *param) {
    NetLinkStatus status;
    s32 t;

    lock_mutex(lbl_805C18A0.value);
    lbl_805D7A8C = 0;
    if (lbl_805D7A84 != 0) {
        lobby_modem_abort_flag = 1;
        lobby_modem_connect_state = 6;
    } else {
        lbl_805D7A88 = 0;
        lobby_modem_connect_state = 0;
    }
    unlock_mutex(((s32 *)&lbl_805C18A0)[0]);
    if (param == NULL || param->wait == 0) {
        return 0;
    }
    for (t = 0; t < 300000; t += 200) {
        TLobby__sub_803F97E8(200);
        TLobby__sub_803FB358(&status);
        if (status.state == 0) {
            return 0;
        }
    }
    return -1;
}

s32 NetLinkConnect(NetConnectCfg *cfg) {
    NetLinkStatus status;
    s32 t;

    if (cfg == NULL) {
        return -1;
    }
    if (NetApplyConnectionConfig((u8 *)cfg) < 0) {
        return -1;
    }
    if (cfg->wait == 0) {
        return 0;
    }
    for (t = 0; t < 300000; t += 200) {
        TLobby__sub_803F97E8(200);
        TLobby__sub_803FB358(&status);
        switch (status.state) {
        case 4:
            return 0;
        case 8:
            return -2;
        case 5:
            return -3;
        }
    }
    return -1;
}

void lock_mutex(int mutex);
void unlock_mutex(int mutex);
void NetMemcpy(void* destination, void* source, int size);
#pragma push
#pragma cplusplus off
#pragma dont_inline off
#pragma dont_inline off
s16 TLobby__sub_803FB358(NetLinkStatus *status)
{
  s32 lock_mutex(u32);
  void unlock_mutex(u32);
  void NetMemcpy(void *, const void *, u32);
  u8 *p = (u8 *)status;
  u8 *base = *((u8 (*)[]) ((u8 *) lbl_805C0038));
  u8 *b;
  u32 *new_var;
  u8 *q;
  u8 *a;
  u32 v0;
  u32 v1;
  lock_mutex((*((s32 (*)[]) (&lbl_805C18A0)))[0]);
  base = *((u8 (*)[]) ((u8 *) lbl_805C0038));
  q = base + 0xd4;
  a = *((u8 **) (base + 0x104));
  b = *((u8 **) (base + 0x9c));
  if (base[0x6c] == 5)
  {
    *((s16 *) (p + 0)) = 1;
  }
  else
  {
    *((s16 *) (p + 0)) = 0;
  }
  *((u32 *) (p + 0x10)) = *((u32 *) (b + 0x8));
  *(new_var = (u32 *) (p + 0x14)) = *((u32 *) (b + 0xc));
  *((u32 *) (p + 0x18)) = *((u32 *) (b + 0x18));
  *((u32 *) (p + 0x1c)) = *((u32 *) (b + 0x1c));
  *((u32 *) (p + 0x20)) = *((u32 *) (b + 0x64));
  *((u32 *) (p + 0x24)) = *((u32 *) (b + 0x68));
  if (q[0] == 5)
  {
    *((s16 *) (p + 2)) = 1;
  }
  else
  {
    *((s16 *) (p + 2)) = 0;
  }
  v0 = *((u32 *) (a + 0x8));
  v1 = *((u32 *) (a + 0xc));
  NetMemcpy(p + 0x28, &v0, 4);
  NetMemcpy(p + 0x2c, &v1, 4);
  v0 = *((u32 *) (a + 0x10));
  v1 = *((u32 *) (a + 0x14));
  NetMemcpy(p + 0x30, &v0, 4);
  NetMemcpy(p + 0x34, &v1, 4);
  *((s16 *) (p + 4)) = *((s16 *) (&lobby_modem_connect_state));
  *((s32 *) (p + 8)) = lobby_modem_reply_value;
  *((s16 *) (p + 6)) = *((s16 *) (&lbl_805D7A82));
  *((s16 *) (p + 0xc)) = *((s16 *) (&lbl_805D7A84));
  unlock_mutex((*((s32 (*)[]) (&lbl_805C18A0)))[0]);
  return 0;
}
#pragma pop

/* Copies a connection config block (cfg) into the session state at lbl_805BFF68 when not connected; runs the user callback if flag bit 2 is set. */
s16 NetApplyConnectionConfig(u8 *cfg) {
  u8 *g = (u8 *) &lbl_805BFF68;
  NetStoreTick((s32 *)(cfg + 0x38));
  lock_mutex((int)((void *) ((s32 *)&lbl_805C18A0)[0]));
  if (((s16) lbl_805D7A84) == 0)
  {
    *((u16 *) (((s8 *) g) + 0)) = (u16) (*((u16 *) (((s8 *) cfg) + 0)));
    *((s16 *) (((s8 *) g) + 2)) = (s16) (*((s16 *) (((s8 *) cfg) + 2)));
    lbl_805D7A7C = *((s16 *) (((s8 *) cfg) + 2));
    *((s16 *) (((s8 *) g) + 4)) = (s16) (*((s16 *) (((s8 *) cfg) + 4)));
    *((s32 *) (((s8 *) g) + 0xC)) = (s32) (*((s32 *) (((s8 *) cfg) + 8)));
    *((s32 *) (((s8 *) g) + 0x10)) = (s32) (*((s32 *) (((s8 *) cfg) + 0xC)));
    *((s32 *) (((s8 *) g) + 0x14)) = (s32) (*((s32 *) (((s8 *) cfg) + 0x10)));
    *((s32 *) (((s8 *) g) + 0x18)) = (s32) (*((s32 *) (((s8 *) cfg) + 0x14)));
    NetMemcpy(g + 0x7C, cfg + 0x18, 0xA);
    NetMemcpy(g + 0x88, cfg + 0x24, 0x10);
    NetMemcpy(g + 0x98, cfg + 0x34, 0x10);
    if (((s16) (*((s16 *) (((s8 *) g) + 0x9A)))) == 0)
    {
      *((s16 *) (((s8 *) g) + 0x9A)) = (s16) (*((s16 *) (((s8 *) ((s32 *)&lobby_net_buffer_desc_b)) + 0x14)));
    }
    *((s32 *) (((s8 *) g) + 0xA8)) = (s32) (*((s32 *) (((s8 *) cfg) + 0x44)));
    *((s32 *) (((s8 *) g) + 0xAC)) = (s32) (*((s32 *) (((s8 *) cfg) + 0x48)));
    *((s32 *) (((s8 *) g) + 0xB0)) = (s32) (*((s32 *) (((s8 *) cfg) + 0x4C)));
    *((s32 *) (((s8 *) g) + 0xB4)) = (s32) (*((s32 *) (((s8 *) cfg) + 0x50)));
    *((s32 *) (((s8 *) g) + 0xB8)) = (s32) (*((s32 *) (((s8 *) cfg) + 0x54)));
    *((s32 *) (((s8 *) g) + 0xBC)) = (s32) (*((s32 *) (((s8 *) cfg) + 0x58)));
    NetMemcpy(g + 0xC0, cfg + 0x5C, 8);
    NetMemcpy(g + 0xC8, cfg + 0x64, 8);
    lbl_805D7A82 = 0;
    lobby_modem_connect_state = 1;
    lbl_805D7A88 = 1;
    lbl_805D7A90 = (s32) (*((u16 *) (((s8 *) g) + 0)));
    lbl_805D7A8C = *((s32 *) (((s8 *) g) + 0x18));
    if ((*((u16 *) (((s8 *) g) + 0))) & 4)
    {
      lbl_805D7A7A = 1;
    }
    else
    {
      lbl_805D7A7A = 0;
    }
  }
  unlock_mutex((int)((void *) ((s32 *)&lbl_805C18A0)[0]));
  return 0;
}

typedef struct G_803FB634 { u32 pad0; u32 pad4; u32 t8; } G_803FB634;
s32 is_timed_out(void) {
    G_803FB634 *g = (G_803FB634 *)&lbl_805BFF68;
    s32 now;
    get_time_ms(&now);
    if (lobby_modem_connect_state == 5 || lobby_modem_abort_flag != 0 || (u32)(now - g->t8) > 60000) {
        return 1;
    }
    return 0;
}

s32 TLobby__sub_804037F0(void);

typedef struct Sess_803FB6A0 { u8 pad[0x22]; s16 h22; u8 pad2[0x3C]; u32 w60; u8 pad3[0x6C]; } Sess_803FB6A0;
typedef struct St_803FB6A0 { u8 busy; u8 pad[3]; u8 state; u8 rest[0x143]; } St_803FB6A0;
typedef struct Sock_803FB6A0 { s32 sock; s32 w4; s16 h8; u8 pad[6]; } Sock_803FB6A0;

s32 TLobby__sub_803FB6A0(void) {
    s32 update_connection_state(void *state, void *session);
    St_803FB6A0 *st = (St_803FB6A0 *)lbl_805C0038;
    Sess_803FB6A0 *sess = (Sess_803FB6A0 *)&lbl_805BFF68;
    u8 *state = &st->state;
    update_connection_state(state, &lbl_805BFF68);
    if (*state == 6) {
        while (st->busy != 0) {
            unlock_mutex(((Sock_803FB6A0 *)&lbl_805C18A0)->sock);
            process_expired_timers();
            TLobby__sub_803F97E8(((Sock_803FB6A0 *)&lbl_805C18A0)->h8);
            lock_mutex(((Sock_803FB6A0 *)&lbl_805C18A0)->sock);
        }
    }
    lobby_modem_abort_flag = 0;
    lobby_modem_connect_state = 7;
    TLobby__sub_804037F0();
    if (sess->h22 != 0 && sess->w60 != 0 && NetStringLength((const char*)sess->w60) != 0) {
        modem_run_script((u8 *)sess->w60, (ModemScriptSession *)sess);
    }
    if (lbl_805D7A7E != 0) {
        close_network_transport();
        lbl_805D7A7E = 0;
    }
    lbl_805D7A84 = 0;
    lbl_805D7A88 = 0;
    lobby_modem_abort_flag = 0;
    lobby_modem_connect_state = 0;
    return 0;
}

s32 TLobby__sub_803FB7A4(void) {
    extern s32 lbl_805D7A94;
    extern s16 lbl_805D7A80;
    extern s32 lbl_805D7AA0;
    extern s32 lbl_805D7BD8;
    s16 TLobby__sub_80403D28(s32, s32, s16, s16, s16, s32, s32, s32);
    s32 configure_modem_options(s32, s32, s32, s32, s32);
    u16 is_transport_connected(void);
    s16 TLobby__sub_80403C60(void *);
    s16 TLobby__sub_80403BA8(s32, s32, s32);
    s16 TLobby__sub_80403B04(s32, s32, s32);
    s32 TLobby__sub_804038F4(s32, void *, void *);
    s32 TLobby__sub_804039C8(s32, s32, s32, s32, s32, s32, s32);
    s16 TLobby__sub_80403864(void);
    s16 wait_for_connection(void *);
    s16 map_state_to_mode_id(void);
    LobbyCfg_803FB7A4 *g = (LobbyCfg_803FB7A4 *)&lbl_805BFF68;
    LobbyPkt_803FB7A4 pkt;
    s16 r29;
    s16 ok;
    s32 mode;
    s32 timeout;
    s32 t1;
    s32 t0;
    s16 rc;
    s16 ret;
    s32 flag;
    s16 h2;

    lbl_805D7A88 = 0;
    lobby_modem_connect_state = 2;
    get_time_ms(&lbl_805D7A94);
    lbl_805D7A84 = 1;
    rc = TLobby__sub_80403D28(0, 0, g->h80, g->h7E, g->h7C, 1, g->w64, g->flags & 4);
    if (rc != 0 || lobby_modem_abort_flag != 0) {
        if (lobby_modem_abort_flag != 0) {
            lbl_805D7A82 = 0xd;
        } else {
            lbl_805D7A82 = 1;
        }
        lobby_modem_connect_state = 8;
        LOBBY_NOTIFY();
        return 0;
    }
    if (!(g->flags & 4)) {
        if (g->h8A == 1 && (s16)send_atx_command_mode(0) != 0) {
            LOBBY_ABORT(1, 8);
        }
        if (g->h1C != 0) {
            rc = configure_modem_options(g->w68, g->w6C, g->w70, g->w74, g->w78);
        } else {
            rc = configure_modem_options(0, 0, 0, 0, 0);
        }
        if (rc != 0) {
            LOBBY_ABORT(1, 8);
        }
        if (g->flags & 2) {
            lobby_modem_connect_state = 0xa;
            goto L242;
        }
        if (g->h1E != 0) {
            ret = TLobby__sub_803FAEDC((LoginCfg_803FAEDC *)g);
            if (ret != 0) {
                LOBBY_ABORT(ret, 8);
            }
        }
    }
    if (g->h20 != 0) {
        timeout = g->h8C * 1000;
        get_time_ms(&t0);
        for (;;) {
            if (is_transport_connected() != 0) {
                break;
            }
            if (!(g->flags & 4)) {
                ret = map_state_to_mode_id();
                if (ret >= 0) {
                    if (ret == 0) {
                        break;
                    }
                    LOBBY_ABORT(ret, 8);
                }
            }
            get_time_ms(&t1);
            flag = lobby_modem_abort_flag;
            if ((s16)flag != 0 || (u32)(t1 - t0) > (u32)timeout) {
                if ((s16)flag != 0) {
                    lbl_805D7A82 = 0xd;
                } else {
                    lbl_805D7A82 = 0xc;
                }
                lobby_modem_connect_state = 8;
                LOBBY_NOTIFY();
                return 0;
            }
            unlock_mutex(lbl_805C18A0.value);
            TLobby__sub_803F97E8(100);
            lock_mutex(lbl_805C18A0.value);
        }
    }
L242:
    if (g->flags & 2) {
        lobby_modem_connect_state = 0xa;
        while (lobby_modem_connect_state == 0xa) {
            unlock_mutex(lbl_805C18A0.value);
            TLobby__sub_803F97E8(100);
            process_expired_timers();
            lock_mutex(lbl_805C18A0.value);
        }
        if (lobby_modem_connect_state != 1) {
            if (g->cb != NULL) {
                unlock_mutex(lbl_805C18A0.value);
                lbl_805D7A82 = 1;
                g->cb(lbl_805D7A82, 0);
                lock_mutex(lbl_805C18A0.value);
            }
            return 0;
        }
    }
    unlock_mutex(lbl_805C18A0.value);
    TLobby__sub_803F97E8(500);
    lock_mutex(lbl_805C18A0.value);
    lobby_modem_connect_state = 3;
    lbl_805D7A80 = 0;
    get_time_ms(&g->t8);
    ppp_auth_protocol = 0;
    if (g->flags & 4) {
        pkt.a = -1;
        pkt.b = 1;
        pkt.e = 0x5AE;
        mode = 1;
        pkt.f = 1;
    } else {
        pkt.a = 0xA0000;
        pkt.b = g->uA0;
        pkt.e = g->h9A;
        pkt.f = g->uA2;
        mode = g->hA4;
    }
    pkt.c = g->h98;
    pkt.d = g->w9C;
    pkt.g = g->w0C;
    pkt.h = g->w10;
    if (TLobby__sub_80403C60(&pkt) != 0) {
        LOBBY_ABORT(5, 8);
    }
    h2 = g->h2;
    if (h2 == 6 || h2 == 0) {
        TLobby__sub_804038F4(0, g->bufC0, g->bufC8);
    }
    TLobby__sub_804039C8(mode, g->wA8, g->wAC, g->wB0, g->wB4, g->wB8, g->wBC);
    lbl_805D7AA0 = 0;
    ok = 0;
    switch (g->h98 & 0x7f) {
    default:
        ok = 1;
        break;
    case 0:
        rc = TLobby__sub_80403BA8(g->w0C, g->w10, 0x80);
        if (rc != 0) {
            LOBBY_NOTIFY();
            return 0;
        }
        ok = 1;
        break;
    case 2:
        rc = TLobby__sub_80403B04(g->w0C, g->w10, 0x82);
        if (rc != 0) {
            LOBBY_NOTIFY();
            return 0;
        }
        ok = 1;
        break;
    case 4:
        if (ppp_auth_protocol == 0) {
            ok = 1;
            break;
        }
        for (r29 = 0; r29 < 2; r29++) {
            u16 st = ppp_auth_protocol;
            if (st == 0x80) {
                rc = TLobby__sub_80403BA8(g->w0C, g->w10, st);
                if (rc == 0) {
                    ok = 1;
                    break;
                }
                if (rc != -18) {
                    LOBBY_NOTIFY();
                    return 0;
                }
            } else if (st == 0x82) {
                rc = TLobby__sub_80403B04(g->w0C, g->w10, st);
                if (rc == 0) {
                    ok = 1;
                    break;
                }
                if (rc != -18) {
                    LOBBY_NOTIFY();
                    return 0;
                }
            } else {
                LOBBY_ABORT(6, 8);
            }
            if (wait_for_connection((void *)(lbl_805C0038 + 4)) != 0) {
                LOBBY_ABORT(0xc, 8);
            }
        }
        break;
    }
    if (ok == 0) {
        LOBBY_ABORT(6, 8);
    }
    if (TLobby__sub_80403864() != 0) {
        LOBBY_ABORT(7, 8);
    }
    lobby_modem_connect_state = 4;
    if (g->cb != NULL) {
        unlock_mutex(lbl_805C18A0.value);
        g->cb(0, lbl_805D7BD8);
        lock_mutex(lbl_805C18A0.value);
    }
    return 0;
}

s32 get_remaining(s32 elapsed) {
    return ppp_auth_protocol - elapsed;
}

/* Stores the PPP auth protocol: 0xC023 (PAP) -> 0x80, 0xC223 (CHAP) -> 0x82, else the raw value. */
void set_ppp_auth_protocol(u16 v) {
    if (v == 0xC023) {
        ppp_auth_protocol = 0x80;
    } else if (v == 0xC223) {
        ppp_auth_protocol = 0x82;
    } else {
        ppp_auth_protocol = v;
    }
}
