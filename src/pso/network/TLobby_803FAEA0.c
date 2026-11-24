/* The network stack's session control (a C library, built with GC/1.2.5n): bringing the stack up and down, the
 * login name, the connection configuration record and its status, PPP authentication and the session timeout. */
#include "types.h"
#include "pso/network/TLobby_803FCF44.h"
#include "pso/network/TLobby_804050DC.h"
#include "pso/network/TLobby_803FC178.h"
#include "pso/network/NetworkRuntime.h"
#include "pso/network/PppLcp.h"
#include "pso/network/PppIpcp.h"
#include "pso/network/NetworkTransport.h"
#include "pso/network/TLobby_80428374.h"
#include "pso/network/TLobby_803FAEA0.h"
#include "pso/network/NetPppLink.h"

s16 ppp_get_link_status(NetLinkStatus *status);
/* The session's small state (.sbss 805D7A78-805D7A98), in reverse definition order: this compiler lays .sbss out
 * last-defined first. */
s32 ppp_last_io_ms;
s32 lobby_session_flags;
saddr lobby_modem_callback;
s16 lobby_modem_connect_state;
s16 ppp_open_requested;
s16 lobby_modem_abort_flag;
s16 ppp_session_active;
s16 lobby_modem_error;
s16 ppp_auth_failed;
s16 network_transport_open;
s16 ppp_ip_mode;
s16 ppp_use_pppoe;
u16 ppp_auth_protocol;

NetSession net_session;
PppProtoBlocks ppp_proto_blocks;

typedef struct LobbyPkt_803FB7A4 {
    LcpConfig lcp;
    char *user;
    char *password;
} LobbyPkt_803FB7A4;
LAYOUT_ASSERT(LobbyPkt_803FB7A4_size, sizeof(LobbyPkt_803FB7A4) == 0x18);

#define LOBBY_NOTIFY() do { if (g->cb != NULL) { unlock_mutex(net_thread_state.mutex); g->cb(lobby_modem_error, 0); lock_mutex(net_thread_state.mutex); } } while (0)
#define LOBBY_ABORT(code, st) do { lobby_modem_error = (code); lobby_modem_connect_state = (st); LOBBY_NOTIFY(); return 0; } while (0)

s32 ppp_get_opt(s32 cmd, s32 arg) {
    switch (cmd) {
    case 1:
        set_net_poll_interval(arg);
        return 0;
    }
    return -1;
}


s16 ppp_set_dial_string(NetSession *cfg) {
    u32 plen;
    u8 *p;
    u8 **pname = &lobby_net_session_state.cmd;
    u32 len;
    u8 *buf = lobby_net_session_state.cmd;

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
    if (map_state_to_code((const char *)*pname, cfg->req.type) < 0) {
        return 1;
    }
    return 0;
}

s32 ppp_term(void) {
    stop_network_thread();
    init_net_state_a();
    init_net_block_620();
    ppp_term_hook();
    reset_boot_state();
    ppp_link_term();
    init_net_block_18A0();
    init_net_state_c();
    return 0;
}

void ppp_init_protocols(int);

s16 ppp_init(void) {
    s16 i;
    s16 ret;
    NetSession *p;

    init_net_subsystem_block();
    run_net_init_step();
    ret = ppp_link_init();
    if (ret < 0) {
        return -1;
    }
    init_modem_session_config();
    ppp_init_hook();
    init_net_block_620_secondary();
    init_net_state_b();
    NetMemset(&net_session, 0, sizeof(net_session));
    p = &net_session;
    i = 0;
    while (i < 1) {
        NetMemcpy(&p->modem, lobby_net_session_state.config, sizeof(ModemConfig));
        i++;
        p++;
    }
    lobby_modem_connect_state = 0;
    ppp_open_requested = 0;
    lobby_modem_abort_flag = 0;
    ppp_session_active = 0;
    lobby_modem_error = 0;
    network_transport_open = 0;
    if (reset_network_timer_list() == 0) {
        ppp_init_protocols(0);
    }
    start_network_thread();
    return ret;
}

ModemConfig *ppp_get_modem_property(void) {
    return &net_session.modem;
}

u8 *ppp_set_modem_property(void *src) {
    NetSession *g = &net_session;
    if (src == 0) {
        NetMemcpy(&g->modem, lobby_net_session_state.config, sizeof(ModemConfig));
    } else {
        NetMemcpy(&g->modem, src, sizeof(ModemConfig));
    }
    return (u8 *)&g->modem;
}

s16 ppp_stat(NetLinkStatus *status) {
    return ppp_get_link_status(status);
}

s32 ppp_stop(NetWaitParam *param) {
    NetLinkStatus status;
    s32 t;

    lock_mutex(net_thread_state.mutex);
    lobby_modem_callback = 0;
    if (ppp_session_active != 0) {
        lobby_modem_abort_flag = 1;
        lobby_modem_connect_state = 6;
    } else {
        ppp_open_requested = 0;
        lobby_modem_connect_state = 0;
    }
    unlock_mutex(net_thread_state.mutex);
    if (param == NULL || param->wait == 0) {
        return 0;
    }
    for (t = 0; t < 300000; t += 200) {
        net_sleep_ms(200);
        ppp_get_link_status(&status);
        if (status.state == 0) {
            return 0;
        }
    }
    return -1;
}

s32 ppp_start(NetConnectCfg *cfg) {
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
        net_sleep_ms(200);
        ppp_get_link_status(&status);
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

void NetMemcpy(void* destination, void* source, int size);
#pragma push
#pragma cplusplus off
#pragma dont_inline off
#pragma dont_inline off
s16 ppp_get_link_status(NetLinkStatus *status)
{
  u8 *base;
  IpcpConfig *b;
  u32 *new_var;
  PppFsm *q;
  Ipv6cpConfig *a;
  u32 v0;
  u32 v1;
  lock_mutex(net_thread_state.mutex);
  base = (u8 *)&ppp_proto_blocks;
  /* The byte offset keeps the block address load after the mutex call. */
  q = (PppFsm *)(base + offsetof(PppProtoBlocks, ipv6cp));
  a = q->opts;
  b = ((PppProtoBlocks *)base)->ipcp.opts;
  if (((PppProtoBlocks *)base)->ipcp.state == 5)
  {
    status->link_up = 1;
  }
  else
  {
    status->link_up = 0;
  }
  status->addr_local = b->local.want.our_addr;
  *(new_var = &status->addr_peer) = b->local.want.his_addr;
  status->dns_local_primary = b->local.want.dns[0];
  status->dns_local_secondary = b->local.want.dns[1];
  status->dns_peer_primary = b->peer.want.dns[0];
  status->dns_peer_secondary = b->peer.want.dns[1];
  if (q->state == 5)
  {
    status->ppp_up = 1;
  }
  else
  {
    status->ppp_up = 0;
  }
  v0 = a->local.current.words[0];
  v1 = a->local.current.words[1];
  NetMemcpy(status->addr[0], &v0, 4);
  NetMemcpy(status->addr[1], &v1, 4);
  v0 = a->local.current.words[2];
  v1 = a->local.current.words[3];
  NetMemcpy(status->addr[2], &v0, 4);
  NetMemcpy(status->addr[3], &v1, 4);
  status->state = lobby_modem_connect_state;
  status->result_code = lobby_modem_reply_value;
  status->error = lobby_modem_error;
  status->session_active = ppp_session_active;
  unlock_mutex(net_thread_state.mutex);
  return 0;
}
#pragma pop

/* Copies a connection config block (cfg) into the session state at net_session when not connected; runs the user callback if flag bit 2 is set. */
s16 NetApplyConnectionConfig(NetConnectCfg *cfg) {
  NetSession *g = &net_session;
  NetStoreTick(&cfg->start_tick);
  lock_mutex(net_thread_state.mutex);
  if (((s16) ppp_session_active) == 0)
  {
    g->flags = cfg->flags;
    g->ip_mode = cfg->ip_mode;
    ppp_ip_mode = cfg->ip_mode;
    g->wait = cfg->wait;
    g->user = cfg->user;
    g->password = cfg->password;
    g->phone_number = cfg->phone_number;
    g->cb = (void (*)(s16, s32))cfg->callback;
    NetMemcpy(&g->h7C, &cfg->h18, 0xA);
    NetMemcpy(&g->req, &cfg->h24, sizeof(ModemRequest));
    NetMemcpy(&g->auth_mode, &cfg->auth_mode, 0x10);
    if (g->mtu == 0)
    {
      g->mtu = lobby_net_buffer_desc_b.size;
    }
    g->addr_local = cfg->addr_local;
    g->addr_peer = cfg->addr_peer;
    g->dns_local_primary = cfg->dns_local_primary;
    g->dns_local_secondary = cfg->dns_local_secondary;
    g->dns_peer_primary = cfg->dns_peer_primary;
    g->dns_peer_secondary = cfg->dns_peer_secondary;
    NetMemcpy(g->local_interface_id, cfg->local_interface_id, 8);
    NetMemcpy(g->peer_interface_id, cfg->peer_interface_id, 8);
    lobby_modem_error = 0;
    lobby_modem_connect_state = 1;
    ppp_open_requested = 1;
    lobby_session_flags = g->flags;
    lobby_modem_callback = (saddr)g->cb;
    if (g->flags & 4)
    {
      ppp_use_pppoe = 1;
    }
    else
    {
      ppp_use_pppoe = 0;
    }
  }
  unlock_mutex(net_thread_state.mutex);
  return 0;
}

s32 is_timed_out(void) {
    NetSession *g = &net_session;
    s32 now;
    get_time_ms(&now);
    if (lobby_modem_connect_state == 5 || lobby_modem_abort_flag != 0 || (u32)(now - g->connect_ms) > 60000) {
        return 1;
    }
    return 0;
}


s32 ppp_hangup(void) {
    PppProtoBlocks *blocks = &ppp_proto_blocks;
    NetSession *sess = &net_session;
    PppFsm *lcp = &blocks->lcp;
    update_connection_state(lcp);
    if (lcp->state == 6) {
        while (blocks->phase != 0) {
            unlock_mutex(net_thread_state.mutex);
            process_expired_timers();
            net_sleep_ms(net_thread_state.poll_ms);
            lock_mutex(net_thread_state.mutex);
        }
    }
    lobby_modem_abort_flag = 0;
    lobby_modem_connect_state = 7;
    close_all_connections();
    if (sess->modem.hangup != 0 && sess->modem.hangup_script != NULL && NetStringLength(sess->modem.hangup_script) != 0) {
        modem_run_script((u8 *)sess->modem.hangup_script, sess);
    }
    if (network_transport_open != 0) {
        close_network_transport();
        network_transport_open = 0;
    }
    ppp_session_active = 0;
    ppp_open_requested = 0;
    lobby_modem_abort_flag = 0;
    lobby_modem_connect_state = 0;
    return 0;
}

s32 ppp_open_sub(void) {
    extern s32 lbl_805D7BD8;
    NetSession *g = &net_session;
    LobbyPkt_803FB7A4 pkt;
    s16 r29;
    s16 ok;
    s16 mode;
    s32 timeout;
    s32 t1;
    s32 t0;
    s16 rc;
    s16 ret;
    s32 flag;
    s16 h2;

    ppp_open_requested = 0;
    lobby_modem_connect_state = 2;
    get_time_ms(&ppp_last_io_ms);
    ppp_session_active = 1;
    rc = ppp_begin_connect(0, 0, g->h80, g->h7E, g->h7C, 1, g->modem.modem_name, g->flags & 4);
    if (rc != 0 || lobby_modem_abort_flag != 0) {
        if (lobby_modem_abort_flag != 0) {
            lobby_modem_error = 0xd;
        } else {
            lobby_modem_error = 1;
        }
        lobby_modem_connect_state = 8;
        LOBBY_NOTIFY();
        return 0;
    }
    if (!(g->flags & 4)) {
        if (g->req.has_arg == 1 && (s16)send_atx_command_mode(0) != 0) {
            LOBBY_ABORT(1, 8);
        }
        if (g->modem.send_init != 0) {
            rc = configure_modem_options(g->modem.ms_mode, g->modem.error_correction, g->modem.compression, g->modem.init_count, g->modem.init_command);
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
        if (g->modem.dial != 0) {
            ret = ppp_set_dial_string(g);
            if (ret != 0) {
                LOBBY_ABORT(ret, 8);
            }
        }
    }
    if (g->modem.wait_connect != 0) {
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
                    lobby_modem_error = 0xd;
                } else {
                    lobby_modem_error = 0xc;
                }
                lobby_modem_connect_state = 8;
                LOBBY_NOTIFY();
                return 0;
            }
            unlock_mutex(net_thread_state.mutex);
            net_sleep_ms(100);
            lock_mutex(net_thread_state.mutex);
        }
    }
L242:
    if (g->flags & 2) {
        lobby_modem_connect_state = 0xa;
        while (lobby_modem_connect_state == 0xa) {
            unlock_mutex(net_thread_state.mutex);
            net_sleep_ms(100);
            process_expired_timers();
            lock_mutex(net_thread_state.mutex);
        }
        if (lobby_modem_connect_state != 1) {
            if (g->cb != NULL) {
                unlock_mutex(net_thread_state.mutex);
                lobby_modem_error = 1;
                g->cb(lobby_modem_error, 0);
                lock_mutex(net_thread_state.mutex);
            }
            return 0;
        }
    }
    unlock_mutex(net_thread_state.mutex);
    net_sleep_ms(500);
    lock_mutex(net_thread_state.mutex);
    lobby_modem_connect_state = 3;
    ppp_auth_failed = 0;
    get_time_ms(&g->connect_ms);
    ppp_auth_protocol = 0;
    if (g->flags & 4) {
        pkt.lcp.accm = -1;
        pkt.lcp.no_acfc = 1;
        pkt.lcp.mru = 0x5AE;
        mode = 1;
        pkt.lcp.no_pfc = 1;
    } else {
        pkt.lcp.accm = 0xA0000;
        /* These session inputs are loaded as unsigned halfwords. */
        pkt.lcp.no_acfc_u = g->no_acfc;
        pkt.lcp.mru = g->mtu;
        pkt.lcp.no_pfc_u = g->no_pfc;
        mode = g->vj_disabled;
    }
    pkt.lcp.auth_mode = g->auth_mode;
    pkt.lcp.magic = g->start_tick;
    pkt.user = g->user;
    pkt.password = g->password;
    if (lcp_connect(&pkt.lcp) != 0) {
        LOBBY_ABORT(5, 8);
    }
    h2 = g->ip_mode;
    if (h2 == 6 || h2 == 0) {
        ipv6cp_set_interface_identifiers(0, g->local_interface_id, g->peer_interface_id);
    }
    ipcp_configure_all_options(mode, g->addr_local, g->addr_peer, g->dns_local_primary, g->dns_local_secondary, g->dns_peer_primary, g->dns_peer_secondary);
    ppp_opened_count = 0;
    ok = 0;
    switch (g->auth_mode & 0x7f) {
    default:
        ok = 1;
        break;
    case 0:
        rc = pap_connect((u8 *)g->user, (u8 *)g->password, 0x80);
        if (rc != 0) {
            LOBBY_NOTIFY();
            return 0;
        }
        ok = 1;
        break;
    case 2:
        rc = chap_connect((u8 *)g->user, (u8 *)g->password, 0x82);
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
                rc = pap_connect((u8 *)g->user, (u8 *)g->password, st);
                if (rc == 0) {
                    ok = 1;
                    break;
                }
                if (rc != -18) {
                    LOBBY_NOTIFY();
                    return 0;
                }
            } else if (st == 0x82) {
                rc = chap_connect((u8 *)g->user, (u8 *)g->password, st);
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
            if (wait_for_connection(&ppp_proto_blocks.lcp) != 0) {
                LOBBY_ABORT(0xc, 8);
            }
        }
        break;
    }
    if (ok == 0) {
        LOBBY_ABORT(6, 8);
    }
    if (negotiate_ipcp_and_ipv6cp() != 0) {
        LOBBY_ABORT(7, 8);
    }
    lobby_modem_connect_state = 4;
    if (g->cb != NULL) {
        unlock_mutex(net_thread_state.mutex);
        g->cb(0, lbl_805D7BD8);
        lock_mutex(net_thread_state.mutex);
    }
    return 0;
}

s16 get_remaining(s32 elapsed) {
    return ppp_auth_protocol - elapsed;
}

/* Stores the PPP auth protocol: 0xC023 (PAP) -> 0x80, 0xC223 (CHAP) -> 0x82, else the raw value. */
void ppp_set_auth(u16 protocol) {
    if (protocol == 0xC023) {
        ppp_auth_protocol = 0x80;
    } else if (protocol == 0xC223) {
        ppp_auth_protocol = 0x82;
    } else {
        ppp_auth_protocol = protocol;
    }
}
