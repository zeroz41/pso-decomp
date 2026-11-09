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

s16 TLobby__sub_803FB358(NetLinkStatus *status);
extern u16 ppp_auth_protocol;
void TLobby__sub_803F97E8(int);

NetSession lbl_805BFF68;
u32 lbl_805C0038[82];
#define lbl_805C0038 ((u8 *)lbl_805C0038)

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

#define LOBBY_NOTIFY() do { if (g->cb != NULL) { unlock_mutex(lbl_805C18A0.mutex); g->cb(lbl_805D7A82, 0); lock_mutex(lbl_805C18A0.mutex); } } while (0)
#define LOBBY_ABORT(code, st) do { lbl_805D7A82 = (code); lobby_modem_connect_state = (st); LOBBY_NOTIFY(); return 0; } while (0)

s32 NetControl(s32 cmd, s32 arg) {
    switch (cmd) {
    case 1:
        TLobby__sub_804050DC(arg);
        return 0;
    }
    return -1;
}

typedef struct H_803FB120 { u8 pad[0x28]; u8 *name; u8 pad2C[0x20]; void *v4C; } H_803FB120;
extern H_803FB120 lobby_net_session_state;

s16 TLobby__sub_803FAEDC(NetSession *cfg) {
    u32 plen;
    u8 *p;
    u8 **pname = &lobby_net_session_state.name;
    u32 len;
    u8 *buf = lobby_net_session_state.name;

    if (cfg->phone_number == NULL) {
        return 1;
    }
    len = NetStringLength((const char*)cfg->phone_number);
    if (cfg->req.has_arg == 1 && cfg->req.arg != NULL) {
        plen = NetStringLength((const char*)cfg->req.arg);
        if (plen + len > 59) {
            return 1;
        }
        NetMemcpy(buf, cfg->req.arg, plen);
        p = buf + plen;
        NetMemcpy(p, cfg->phone_number, len);
        p[len] = 0;
    } else {
        if (len > 59) {
            return 1;
        }
        NetMemcpy(buf, cfg->phone_number, len);
        buf[len] = 0;
    }
    if (map_state_to_code((s32)*pname, cfg->req.type) < 0) {
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

s16 init_net_session(void) {
    s16 i;
    s16 ret;
    NetSession *p;

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
    p = &lbl_805BFF68;
    i = 0;
    while (i < 1) {
        NetMemcpy(&p->modem, lobby_net_session_state.v4C, sizeof(ModemConfig));
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
    return (u8 *)&lbl_805BFF68.modem;
}

u8 *copy_name_buffer(void *src) {
    NetSession *g = &lbl_805BFF68;
    if (src == 0) {
        NetMemcpy(&g->modem, lobby_net_session_state.v4C, sizeof(ModemConfig));
    } else {
        NetMemcpy(&g->modem, src, sizeof(ModemConfig));
    }
    return (u8 *)&g->modem;
}

s16 NetGetLinkStatus(NetLinkStatus *status) {
    return TLobby__sub_803FB358(status);
}

s32 NetLinkDisconnect(NetWaitParam *param) {
    NetLinkStatus status;
    s32 t;

    lock_mutex(lbl_805C18A0.mutex);
    lbl_805D7A8C = 0;
    if (lbl_805D7A84 != 0) {
        lobby_modem_abort_flag = 1;
        lobby_modem_connect_state = 6;
    } else {
        lbl_805D7A88 = 0;
        lobby_modem_connect_state = 0;
    }
    unlock_mutex(lbl_805C18A0.mutex);
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
    if (NetApplyConnectionConfig(cfg) < 0) {
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
  u8 *p = (u8 *)status;
  u8 *base = *((u8 (*)[]) ((u8 *) lbl_805C0038));
  u8 *b;
  u32 *new_var;
  u8 *q;
  u8 *a;
  u32 v0;
  u32 v1;
  lock_mutex(lbl_805C18A0.mutex);
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
  unlock_mutex(lbl_805C18A0.mutex);
  return 0;
}
#pragma pop

/* Copies a connection config block (cfg) into the session state at lbl_805BFF68 when not connected; runs the user callback if flag bit 2 is set. */
s16 NetApplyConnectionConfig(NetConnectCfg *cfg) {
  NetSession *g = &lbl_805BFF68;
  NetStoreTick(&cfg->start_tick);
  lock_mutex(lbl_805C18A0.mutex);
  if (((s16) lbl_805D7A84) == 0)
  {
    g->flags = cfg->flags;
    g->h2 = cfg->h2;
    lbl_805D7A7C = cfg->h2;
    g->h4 = cfg->wait;
    g->user = cfg->wC;
    g->password = cfg->password;
    g->phone_number = cfg->phone_number;
    g->cb = (void (*)(s16, s32))cfg->callback;
    NetMemcpy(&g->h7C, &cfg->h18, 0xA);
    NetMemcpy(&g->req, &cfg->h24, sizeof(ModemRequest));
    NetMemcpy(&g->h98, &cfg->h34, 0x10);
    if (g->mtu == 0)
    {
      g->mtu = lobby_net_buffer_desc_b.size;
    }
    g->wA8 = cfg->w44;
    g->wAC = cfg->w48;
    g->wB0 = cfg->w4C;
    g->wB4 = cfg->w50;
    g->wB8 = cfg->w54;
    g->wBC = cfg->w58;
    NetMemcpy(g->bufC0, cfg->b5C, 8);
    NetMemcpy(g->bufC8, cfg->b64, 8);
    lbl_805D7A82 = 0;
    lobby_modem_connect_state = 1;
    lbl_805D7A88 = 1;
    lbl_805D7A90 = g->flags;
    lbl_805D7A8C = (s32)g->cb;
    if (g->flags & 4)
    {
      lbl_805D7A7A = 1;
    }
    else
    {
      lbl_805D7A7A = 0;
    }
  }
  unlock_mutex(lbl_805C18A0.mutex);
  return 0;
}

s32 is_timed_out(void) {
    NetSession *g = &lbl_805BFF68;
    s32 now;
    get_time_ms(&now);
    if (lobby_modem_connect_state == 5 || lobby_modem_abort_flag != 0 || (u32)(now - g->connect_ms) > 60000) {
        return 1;
    }
    return 0;
}

s32 TLobby__sub_804037F0(void);

typedef struct St_803FB6A0 { u8 busy; u8 pad[3]; u8 state; u8 rest[0x143]; } St_803FB6A0;

s32 TLobby__sub_803FB6A0(void) {
    void update_connection_state(void *state, void *session); /* declared with 2 parameters; the definition is void (int) */
    St_803FB6A0 *st = (St_803FB6A0 *)lbl_805C0038;
    NetSession *sess = &lbl_805BFF68;
    u8 *state = &st->state;
    update_connection_state(state, &lbl_805BFF68);
    if (*state == 6) {
        while (st->busy != 0) {
            unlock_mutex(lbl_805C18A0.mutex);
            process_expired_timers();
            TLobby__sub_803F97E8(lbl_805C18A0.poll_ms);
            lock_mutex(lbl_805C18A0.mutex);
        }
    }
    lobby_modem_abort_flag = 0;
    lobby_modem_connect_state = 7;
    TLobby__sub_804037F0();
    if (sess->modem.h6 != 0 && sess->modem.w44 != NULL && NetStringLength(sess->modem.w44) != 0) {
        modem_run_script((u8 *)sess->modem.w44, sess);
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
    s16 TLobby__sub_80403D28(s32, s32, s32, s32, s32, s32, s32, s32); /* declared s16 here; the definition returns s32 */
    s32 configure_modem_options(s32, s32, s32, s32, s32);
    u16 is_transport_connected(void); /* declared u16 here; the definition returns s32 */
    s16 TLobby__sub_80403C60(void *); /* declared s16 here; the definition is s32 (u8 *) */
    s16 TLobby__sub_80403BA8(s32, s32, s32); /* declared s16 here; the definition is s32 (u8 *, u8 *, s32) */
    s16 TLobby__sub_80403B04(s32, s32, s32); /* declared s16 here; the definition is s32 (u8 *, u8 *, s32) */
    s32 TLobby__sub_804038F4(s32, void *, void *); /* declared here with other parameter types; the definition is s32 (s32, s32, s32) */
    s32 TLobby__sub_804039C8(s32, s32, s32, s32, s32, s32, s32); /* declared here with an s32 1st argument; the definition takes s16 */
    s16 TLobby__sub_80403864(void); /* declared s16 here; the definition returns s32 */
    s16 wait_for_connection(Conn_804004DC *); /* declared s16 here; the definition returns s32 */
    s16 map_state_to_mode_id(void); /* declared s16 here; the definition returns s32 */
    NetSession *g = &lbl_805BFF68;
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
    rc = TLobby__sub_80403D28(0, 0, g->h80, g->h7E, g->h7C, 1, (s32)g->modem.s48, g->flags & 4);
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
        if (g->req.has_arg == 1 && (s16)send_atx_command_mode(0) != 0) {
            LOBBY_ABORT(1, 8);
        }
        if (g->modem.h0 != 0) {
            rc = configure_modem_options(g->modem.w4C, g->modem.w50, g->modem.w54, g->modem.init_count, (s32)g->modem.init_command);
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
        if (g->modem.h2 != 0) {
            ret = TLobby__sub_803FAEDC(g);
            if (ret != 0) {
                LOBBY_ABORT(ret, 8);
            }
        }
    }
    if (g->modem.h4 != 0) {
        timeout = g->req.timeout * 1000;
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
            unlock_mutex(lbl_805C18A0.mutex);
            TLobby__sub_803F97E8(100);
            lock_mutex(lbl_805C18A0.mutex);
        }
    }
L242:
    if (g->flags & 2) {
        lobby_modem_connect_state = 0xa;
        while (lobby_modem_connect_state == 0xa) {
            unlock_mutex(lbl_805C18A0.mutex);
            TLobby__sub_803F97E8(100);
            process_expired_timers();
            lock_mutex(lbl_805C18A0.mutex);
        }
        if (lobby_modem_connect_state != 1) {
            if (g->cb != NULL) {
                unlock_mutex(lbl_805C18A0.mutex);
                lbl_805D7A82 = 1;
                g->cb(lbl_805D7A82, 0);
                lock_mutex(lbl_805C18A0.mutex);
            }
            return 0;
        }
    }
    unlock_mutex(lbl_805C18A0.mutex);
    TLobby__sub_803F97E8(500);
    lock_mutex(lbl_805C18A0.mutex);
    lobby_modem_connect_state = 3;
    lbl_805D7A80 = 0;
    get_time_ms(&g->connect_ms);
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
        pkt.e = g->mtu;
        pkt.f = g->uA2;
        mode = g->hA4;
    }
    pkt.c = g->h98;
    pkt.d = g->start_tick;
    pkt.g = (s32)g->user;
    pkt.h = (s32)g->password;
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
        rc = TLobby__sub_80403BA8((s32)g->user, (s32)g->password, 0x80);
        if (rc != 0) {
            LOBBY_NOTIFY();
            return 0;
        }
        ok = 1;
        break;
    case 2:
        rc = TLobby__sub_80403B04((s32)g->user, (s32)g->password, 0x82);
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
                rc = TLobby__sub_80403BA8((s32)g->user, (s32)g->password, st);
                if (rc == 0) {
                    ok = 1;
                    break;
                }
                if (rc != -18) {
                    LOBBY_NOTIFY();
                    return 0;
                }
            } else if (st == 0x82) {
                rc = TLobby__sub_80403B04((s32)g->user, (s32)g->password, st);
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
        unlock_mutex(lbl_805C18A0.mutex);
        g->cb(0, lbl_805D7BD8);
        lock_mutex(lbl_805C18A0.mutex);
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
