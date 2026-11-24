/* PPP connection control: the connect records (.bss 805C0638), the calls the session layer (803FB7A4) makes
 * and the modem wrappers (a C library, built with GC/1.2.5n). PppControl is an inferred name. */
#include "types.h"
#include "pso/network/TLobby_803FC178.h"
#include "pso/network/TLobby_803FCF44.h"
#include "pso/network/TLobby_804050DC.h"
#include "pso/network/TLobby_8041112C.h"
#include "pso/network/PppLcp.h"
#include "pso/network/PppIpcp.h"
#include "pso/network/NetworkRuntime.h"
#include "pso/network/TLobby_804048E8.h"
#include "pso/network/NetworkTransport.h"

#include <stddef.h>
#include "pso/network/NetStackTypes.h"
#include "pso/network/TLobby_803FAEA0.h"

s16 configure_and_open_network_transport(int a, int b, int c, int d, int e, char *modem_name, int no_modem);

s32 network_input_available(u8 *out) {
    if (get_transport_input_count((s16 *)out) != 0) {
        return -1;
    }
    return 0;
}

s32 recv_network_bytes(u8 *dst, unsigned short n) {
  u8 buf;
  u16 st;
  while (((u16) n) != 0)
  {
    if ((recv_network_frame(1, &buf, &st) != 0) && (st != 1))
    {
      return -1;
    }
    *(dst++) = buf;
    n--;
  }
  return 0;
}

s32 send_network_bytes(saddr src, u16 len) {
    if (send_network_frame(len, (u8 *)src) != 0) {
        return -1;
    }
    return 0;
}

void ppp_init_protocols(int);
s32 close_all_connections(void) {
    fsm_lowerdown(&ppp_proto_blocks.ipv6cp);
    fsm_lowerdown(&ppp_proto_blocks.ipcp);
    fsm_lowerdown(&ppp_proto_blocks.pap);
    fsm_lowerdown(&ppp_proto_blocks.chap);
    fsm_lowerdown(&ppp_proto_blocks.lcp);
    ppp_proto_blocks.phase = 0;
    if (reset_network_timer_list() == 0) {
        ppp_init_protocols(0);
    }
    return 0;
}

s16 negotiate_ipcp_and_ipv6cp(void) {
    PppProtoBlocks *connection = &ppp_proto_blocks;
    PppFsm *ipv6cp = &connection->ipv6cp;
    s16 st = ppp_ip_mode;
    PppFsm *ipcp;

    if ((st == 6 || st == 0) && ipcp_open(ipv6cp) != 0) {
        return -0x11;
    }
    ipcp = &connection->ipcp;
    if (ipcp_open(ipcp) != 0) {
        return -0x11;
    }
    if (wait_for_ipcp_open(ipcp) != 0) {
        return -0x11;
    }
    return 0;
}

s32 ipv6cp_set_interface_identifiers(s32 ignored, u8 *first_identifier, u8 *second_identifier) {
    PppFsm *fsm_state = &ppp_proto_blocks.ipv6cp;
    Ipv6cpConfig *state = fsm_state->opts;

    PP_doppp_active(fsm_state);
    if (clear_flag_bit4(ignored, &state->local) != 0) {
        return -0x11;
    }
    if (clear_flag_bit4(ignored, &state->peer) != 0) {
        return -0x11;
    }
    if (NetIPv6CPSetInterfaceIdentifier(&state->local, first_identifier) != 0) {
        return -0x11;
    }
    if (NetIPv6CPSetInterfaceIdentifier(&state->peer, second_identifier) != 0) {
        return -0x11;
    }
    return 0;
}

s32 ipcp_configure_all_options(s16 vj_disabled, s32 addr_local, s32 addr_peer, s32 dns_local_primary, s32 dns_local_secondary, s32 dns_peer_primary, s32 dns_peer_secondary) {
    IpcpConfig *ipcp_cfg;
    PppFsm *fsm_state;
    s16 ipcp_set_vj_compression(s16 disabled, IpcpSide *side);
    s16 ipcp_set_local_address(IpcpSide *side, s32 addr);
    s16 ipcp_set_local_secondary_dns(IpcpSide *side, s32 addr);
    s16 ipcp_set_peer_primary_dns(IpcpSide *side, s32 addr);
    s16 ipcp_set_peer_address(IpcpSide *side, s32 addr);
    s16 ipcp_set_peer_secondary_dns(IpcpSide *side, s32 addr);
    s16 ipcp_set_local_primary_dns(IpcpSide *side, s32 addr);
    fsm_state = &ppp_proto_blocks.ipcp;
    ipcp_cfg = fsm_state->opts;
    PP_doppp_active(fsm_state);
    if (ipcp_set_vj_compression(vj_disabled, &ipcp_cfg->local) != 0) {
        return -0x11;
    }
    if (ipcp_set_vj_compression(vj_disabled, &ipcp_cfg->peer) != 0) {
        return -0x11;
    }
    if (ipcp_set_local_address(&ipcp_cfg->local, addr_local) != 0) {
        return -0x11;
    }
    if (ipcp_set_local_primary_dns(&ipcp_cfg->local, dns_local_primary) != 0) {
        return -0x11;
    }
    if (ipcp_set_local_secondary_dns(&ipcp_cfg->local, dns_local_secondary) != 0) {
        return -0x11;
    }
    if (ipcp_set_peer_address(&ipcp_cfg->peer, addr_peer) != 0) {
        return -0x11;
    }
    if (ipcp_set_peer_primary_dns(&ipcp_cfg->peer, dns_peer_primary) != 0) {
        return -0x11;
    }
    if (ipcp_set_peer_secondary_dns(&ipcp_cfg->peer, dns_peer_secondary) != 0) {
        return -0x11;
    }
    return 0;
}

s16 chap_connect(u8 *chap_name, u8 *chap_secret, s32 timeout) {
    PppProtoBlocks *g = &ppp_proto_blocks;
    PppFsm *chap = &ppp_proto_blocks.chap;
    s16 r;
    s16 st;
    chap_set_secret(chap_name, chap_secret, chap);
    r = PP_chap_monitor(chap, timeout);
    if (r < 0) {
        if (r == -0x12) {
            return -0x12;
        }
        return -0x11;
    }
    PP_doppp_active(&g->ipcp);
    st = ppp_ip_mode;
    if (st == 6 || st == 0) {
        PP_doppp_active(&g->ipv6cp);
    }
    return 0;
}

s16 pap_connect(u8 *peer_id, u8 *pap_password, s32 timeout) {
    PppProtoBlocks *g = &ppp_proto_blocks;
    PppFsm *c = &g->pap;
    s16 r;
    s16 st;
    if (lobby_session_flags & 1) {
        pap_set_secret(peer_id, pap_password, c);
        fsm_send_config_request(c);
    }
    r = PP_pap_monitor(c, timeout);
    if (r < 0) {
        if (r == -0x12) {
            return -0x12;
        }
        return -0x11;
    }
    PP_doppp_active(&g->ipcp);
    st = ppp_ip_mode;
    if (st == 6 || st == 0) {
        PP_doppp_active(&g->ipv6cp);
    }
    return 0;
}

s16 lcp_connect(LcpConfig *cfg) {
    PppFsm *conn;
    LcpSide *auth_side;
    LcpSide *local_side;

    lcp_connect_hook();
    conn = &ppp_proto_blocks.lcp;
    if (apply_lcp_config_to_sides(conn, cfg) != 0) {
        return -0x11;
    }
    if (wait_for_connection(conn) != 0) {
        return -0x11;
    }
    if (cfg->auth_mode == 4) {
        auth_side = conn->opts;
        local_side = auth_side;
        auth_side += 1;
        if (lobby_session_flags & 2) {
            auth_side = local_side;
        }
        if (auth_side->got.auth_proto == 0xC023) {
            cfg->auth_mode = 0x80;
        }
        if (auth_side->got.auth_proto == 0xC223) {
            cfg->auth_mode = 0x82;
        }
    }
    return 0;
}

/* ppp_connect_records: eight records whose first byte ppp_begin_connect clears before each connect; nothing else in the game
 * reads or writes them. */
typedef struct ConnectRecord {
    s8 active;
    u8 pad1[0x13];
} ConnectRecord;
LAYOUT_ASSERT(ConnectRecord_size_check, sizeof(ConnectRecord) == 0x14);
ConnectRecord ppp_connect_records[8];

s16 ppp_begin_connect(s32 ignored, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, char *modem_name, s32 no_modem) {
    s16 transport_rc;
    ppp_connect_records[0].active = 0;
    ppp_connect_records[1].active = 0;
    ppp_connect_records[2].active = 0;
    ppp_connect_records[3].active = 0;
    ppp_connect_records[4].active = 0;
    ppp_connect_records[5].active = 0;
    ppp_connect_records[6].active = 0;
    ppp_connect_records[7].active = 0;
    transport_rc = configure_and_open_network_transport(arg1, arg2, arg3, arg4, arg5, modem_name, no_modem);
    ppp_link_event(0x82);
    return transport_rc;
}

s16 configure_and_open_network_transport(a, b, c, d, e, modem_name, no_modem)
    s16 a;
    s16 b;
    s16 c;
    s16 d;
    s16 e;
    char *modem_name;
    s16 no_modem;
{
    NetTransportOpenCfg cfg_block;
    s32 t;
    if (a == 0) {
        t = 0;
    } else if (a == 1) {
        t = 1;
    } else {
        t = 0;
    }
    cfg_block.settings[0] = t;
    if (b == 0) {
        t = 2;
    } else if (b == 1) {
        t = 1;
    } else if (b == 2) {
        t = 0;
    } else {
        t = 2;
    }
    cfg_block.settings[1] = t;
    if (c == 0) {
        t = 0;
    } else if (c == 1) {
        t = 2;
    } else {
        t = 0;
    }
    cfg_block.settings[2] = t;
    cfg_block.settings[3] = 1;
    if (d == 0) {
        t = 0;
    } else if (d == 1) {
        t = 1;
    } else if (d == 2) {
        t = 2;
    } else if (d == 3) {
        t = 3;
    } else if (d == 4) {
        t = 4;
    } else if (d == 5) {
        t = 5;
    } else if (d == 6) {
        t = 6;
    } else {
        t = 2;
    }
    cfg_block.settings[4] = t;
    if (e == 2) {
        t = 0;
    } else if (e == 3) {
        t = 1;
    } else {
        t = 1;
    }
    cfg_block.settings[5] = t;
    cfg_block.reserved = 0;
    cfg_block.modem_name = modem_name;
    if (no_modem != 0) {
        cfg_block.use_pppoe = 1;
    } else {
        cfg_block.use_pppoe = 0;
    }
    if (open_network_transport(&cfg_block) != 0) {
        return -1;
    }
    network_transport_open = 1;
    return 0;
}
