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
    if (TLobby__sub_803F811C((s16 *)out) != 0) {
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

void TLobby__sub_804061FC(int);
s32 close_all_connections(void) {
    TLobby__sub_803FD85C(&ppp_proto_blocks.ipv6cp);
    TLobby__sub_803FD85C(&ppp_proto_blocks.ipcp);
    TLobby__sub_803FD85C(&ppp_proto_blocks.pap);
    TLobby__sub_803FD85C(&ppp_proto_blocks.chap);
    TLobby__sub_803FD85C(&ppp_proto_blocks.lcp);
    ppp_proto_blocks.busy = 0;
    if (reset_network_timer_list() == 0) {
        TLobby__sub_804061FC(0);
    }
    return 0;
}

s16 negotiate_ipcp_and_ipv6cp(void) {
    PppProtoBlocks *connection = &ppp_proto_blocks;
    PppFsm *ipv6cp = &connection->ipv6cp;
    s16 st = lbl_805D7A7C;
    PppFsm *ipcp;

    if ((st == 6 || st == 0) && TLobby__sub_803FF304(ipv6cp) != 0) {
        return -0x11;
    }
    ipcp = &connection->ipcp;
    if (TLobby__sub_803FF304(ipcp) != 0) {
        return -0x11;
    }
    if (TLobby__sub_803FED78(ipcp) != 0) {
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
    u8 *fsm_state;
    s16 ipcp_set_vj_compression(s16 disabled, IpcpSide *side);
    s16 ipcp_set_local_address(IpcpSide *side, s32 addr);
    s16 ipcp_set_local_secondary_dns(IpcpSide *side, s32 addr);
    s16 ipcp_set_peer_primary_dns(IpcpSide *side, s32 addr);
    s16 ipcp_set_peer_address(IpcpSide *side, s32 addr);
    s16 ipcp_set_peer_secondary_dns(IpcpSide *side, s32 addr);
    s16 ipcp_set_local_primary_dns(IpcpSide *side, s32 addr);
    fsm_state = (u8 *)&ppp_proto_blocks.ipcp;
    ipcp_cfg = *(IpcpConfig **)((s8 *)fsm_state + 0x30);
    PP_doppp_active((void *)fsm_state);
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
    u8 *g = (u8 *)&ppp_proto_blocks;
    PppFsm *chap = &ppp_proto_blocks.chap;
    s16 r;
    s16 st;
    TLobby__sub_803FC684(chap_name, chap_secret, chap);
    r = PP_chap_monitor(chap, timeout);
    if (r < 0) {
        if (r == -0x12) {
            return -0x12;
        }
        return -0x11;
    }
    PP_doppp_active(g + 0x6C);
    st = lbl_805D7A7C;
    if (st == 6 || st == 0) {
        PP_doppp_active(g + 0xD4);
    }
    return 0;
}

s16 pap_connect(u8 *peer_id, u8 *pap_password, s32 timeout) {
    u8 *g = (u8 *)&ppp_proto_blocks;
    u8 *c = g + 0x38;
    s16 r;
    s16 st;
    if (lbl_805D7A90 & 1) {
        TLobby__sub_80403168(peer_id, pap_password, c);
        TLobby__sub_803FE658((PppFsm *)c);
    }
    r = PP_pap_monitor(c, timeout);
    if (r < 0) {
        if (r == -0x12) {
            return -0x12;
        }
        return -0x11;
    }
    PP_doppp_active(g + 0x6C);
    st = lbl_805D7A7C;
    if (st == 6 || st == 0) {
        PP_doppp_active(g + 0xD4);
    }
    return 0;
}

s16 lcp_connect(LcpConfig *cfg) {
    PppFsm *conn;
    LcpSide *auth_side;
    LcpSide *local_side;

    TLobby__sub_803F808C();
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
        if (lbl_805D7A90 & 2) {
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
    TLobby__sub_804062A0(0x82);
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
    s32 open_network_transport(void *);
    struct {
        s32 v[6];
        s16 x;
        s16 y;
        void* z;
    } cfg_block;
    s32 t;
    if (a == 0) {
        t = 0;
    } else if (a == 1) {
        t = 1;
    } else {
        t = 0;
    }
    cfg_block.v[0] = t;
    if (b == 0) {
        t = 2;
    } else if (b == 1) {
        t = 1;
    } else if (b == 2) {
        t = 0;
    } else {
        t = 2;
    }
    cfg_block.v[1] = t;
    if (c == 0) {
        t = 0;
    } else if (c == 1) {
        t = 2;
    } else {
        t = 0;
    }
    cfg_block.v[2] = t;
    cfg_block.v[3] = 1;
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
    cfg_block.v[4] = t;
    if (e == 2) {
        t = 0;
    } else if (e == 3) {
        t = 1;
    } else {
        t = 1;
    }
    cfg_block.v[5] = t;
    cfg_block.x = 0;
    cfg_block.z = modem_name;
    if (no_modem != 0) {
        cfg_block.y = 1;
    } else {
        cfg_block.y = 0;
    }
    if (open_network_transport(&cfg_block) != 0) {
        return -1;
    }
    lbl_805D7A7E = 1;
    return 0;
}
