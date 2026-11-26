#include "types.h"
#include "pso/network/TLobby.h"
#include "pso/network/NetworkConnect.h"
#include "pso/system/scene/OnlineLobbyScene.h"
#include "pso/unk/text_80145A94.h"
#include "pso/network/PppApi.h"
#include "pso/network/NetStack.h"
#include "pso/network/NetApi.h"
#include "pso/network/NetworkRuntime.h"
#include "pso/network/NetworkTransport.h"
#include "pso/network/NetworkMessageTransport.h"
#include "pso/network/NetworkPacketPool.h"
#include "pso/network/NetDhcp.h"
#include "pso/network/NetArp.h"
#include "pso/network/NetDns.h"
#include "pso/network/NetIpv6Route.h"
#include "pso/network/NetworkInfoLoader.h"
#include "pso/network/ModemSession.h"
#include "pso/unk/text_80145A44.h"
#include "pso/unk/text_803F4D84.h"
#include <string.h>
#include <string.h>
#include "pso/system/memory.h"
#include "pso/ui/keyboard/TKeyBoardControl.h"
#include "pso/system/ControllerInputState.h"
#include "pso/system/ControllerInput.h"
#define PSO_SDK_COMPACT_MATH
#include <dolphin/os.h>
#include "pso/unk/TLobby_800FD78C.h"
#include "pso/unk/text_8014618C.h"
#include "pso/unk/TLobby_80145E40.h"
#undef PSO_SDK_COMPACT_MATH

s32 lobby_local_ip_addr;
s32 lobby_dns_server_addr;
s32 lobby_dns_server_addr2;
s32 lobby_gateway_addr;
s32 lbl_805D56E8;
s32 lobby_dhcp_lease_time;
s32 lobby_dhcp_renew_time;
s32 lobby_dhcp_rebind_time;
s32 connect_pending_flags;
s32 lobby_default_gateway;
uaddr avetcp_work_area;
s32 net_session_mode;
int phone_number_index;
s32 dns_initialized;
s32 lobby_connect_active_flag;
s32 lbl_805D5714;
s32 lbl_805D5718;

extern "C" {
s16 if_config(s16, void *);
}
s32 lobby_net_session_id = -1;

u32 lobby_if_config[7];
u32 dhcp_work_buffer[368];
char lobby_dns_domain[0x100];
AccountEntry lobby_account_entries[3];
NetworkConfig network_config;
__declspec(section ".data") s32 lbl_8050CE0C[2];
char modem_user_name[0x20];
char account_user_copy[0x20];
u8 lbl_8050CE54[0x114];

void init_keyboard_buffer() {
    network_lease_time = 0;
    network_config_open = 0;
    network_info_work = NULL;
    network_info_work = xmalloc(get_network_config_buffer_size(0));
    load_network_info();
}

s32 poll_connect() {
    s32 tries;

    tries = 0;
    for (;;) {
        if (tries > 0x12C) {
            return 0;
        }
        tries += 1;
        send_and_handle();
        if (static_cast<s8>(poll_reset_request()) != 0) {
            return 1;
        }
        if (query_link_status() == 1) {
            return 2;
        }
    }
}


void remove_default_route() {
    if (connect_pending_flags & 2) {
        route4_del(0, 0, lobby_default_gateway);
        connect_pending_flags &= 0xFFFFFFFD;
    }
}

void set_default_gateway(s32 gateway) {
    lobby_default_gateway = gateway;
    connect_pending_flags |= 2;
    route4_add(0, 0, gateway);
}


s32 connect_pppoe(s32 *out_value) {
    NetConnectCfg cfg;
    NetLinkStatus status;
    s16 state;
    s16 reason;
    NetWaitParam stop;
    NetWaitParam stop2;
    s16 id;
    s32 cancel;
    s32 result;

    id = ppp_init();
    connect_pending_flags |= 4;
    lobby_net_session_id = id;
    if (id == -1) {
        return 9;
    }
    cfg.flags = 5;
    cfg.wait = 0;
    cfg.user = network_config.ppp_user;
    cfg.password = network_config.ppp_password;
    cfg.callback = 0;
    cfg.ip_mode = 4;
    cfg.h18 = 6;
    cfg.h1A = 0;
    cfg.h1C = 0;
    cfg.h1E = 3;
    cfg.h20 = 1;
    cfg.req_timeout = 90;
    cfg.h2A = 0;
    cfg.h2C = 20;
    cfg.phone_number = 0;
    cfg.req_type = 0;
    cfg.req_has_arg = 0;
    cfg.prefix = 0;
    cfg.auth_mode = 4;
    cfg.mtu = 1500;
    cfg.start_tick = 0x12345678;
    cfg.no_acfc = 0;
    cfg.no_pfc = 0;
    cfg.vj_disabled = 1;
    cfg.addr_local = 0;
    cfg.addr_peer = 0;
    cfg.dns_local_primary = 0;
    cfg.dns_local_secondary = 0;
    cfg.dns_peer_primary = 0;
    cfg.dns_peer_secondary = 0;
    ppp_get_opt(1, 10);
    ppp_start(&cfg);
    state = -1;
    do {
        cancel = 0;
        if (test_pressed_buttons_packed(&controller_input_state.controllers[0], 2) != 0 ||
            TKeyBoardControl::read_key_checked(0x4C) != 0) {
            cancel = 1;
            result = 0x10;
        }
        if (static_cast<s8>(poll_reset_request()) != 0) {
            cancel = 1;
            result = 0x11;
        }
        if (cancel != 0) {
            stop.wait = 1;
            ppp_stop(&stop);
            lobby_net_session_id = -1;
            return result;
        }
        get_link_state(&state, &reason);
        if (state == 5 || state == 8 || state == 4) {
            break;
        }
        send_and_handle();
    } while (state != 4);
    if (state == 4) {
        ppp_stat(&status);
        lobby_local_ip_addr = status.addr_local;
        *out_value = 0;
        lobby_dns_server_addr = status.dns_local_primary;
        lobby_dns_server_addr2 = status.dns_local_secondary;
        lobby_gateway_addr = status.addr_local;
        return 0;
    }
    stop2.wait = 1;
    ppp_stop(&stop2);
    switch (reason) {
    case 3:
        return 5;
    case 2:
        return 7;
    case 6:
        return 8;
    case 0:
    case 1:
    case 7:
    default:
        return 4;
    }
}


s32 apply_static_network_config(s32 *netmask) {
    lobby_local_ip_addr = network_config.local_ip;
    *netmask = network_config.netmask;
    lobby_gateway_addr = network_config.gateway;
    lobby_dns_server_addr = network_config.dns_server1;
    lobby_dns_server_addr2 = network_config.dns_server2;
    return 0;
}

s32 apply_dhcp_network_config(s32 *netmask) {
    s32 broadcast;

    if (DHCP_init((s16)lobby_net_session_id) != 0) {
        return 0xC;
    }
    connect_pending_flags |= 0x10;
    lobby_connect_active_flag = 1;
    char *name = network_config.dhcp_hostname;
    if (*name != 0 && DHCP_hostname(name) < 0) {
        return 0xC;
    }
    lobby_local_ip_addr = 0;
    lbl_805D56E8 = 0;
    if (dhcp_discover_and_request((s16)lobby_net_session_id, 0, 0, dhcp_work_buffer, &lobby_local_ip_addr, netmask, &broadcast, 3) != 0) {
        return 0xC;
    }
    if (DHCP_get_gateway(dhcp_work_buffer, &lobby_gateway_addr) != 0) {
        return 0xC;
    }
    if (dhcp_get_lease_times(&lobby_dhcp_lease_time, &lobby_dhcp_renew_time, &lobby_dhcp_rebind_time) != 0) {
        return 0xC;
    }
    set_network_lease_time(lobby_dhcp_lease_time);
    return DHCP_get_dns(dhcp_work_buffer, lobby_dns_domain, &lobby_dns_server_addr, &lobby_dns_server_addr2) != 0 ? 0xC : 0;
}

s32 should_try_next_phone_number(u32 result) {
    switch (result) {
    case 0:
    case 1:
    case 2:
    case 5:
    case 6:
    case 8:
    case 11:
    case 16:
    case 17:
        return 0;
    default:
        return 1;
    }
}

int get_phone_number_count(void) { return 3; }

void get_local_ip_address(s32 *out_addr) {
    *out_addr = lobby_if_config[1];
}

int get_post_save_lobby_action(void) { return 0; }

s32 query_task_active() {
    if (lobby_connect_active_flag != 0) {
        return get_task_count();
    }
    return 0;
}

int has_modem_adapter(void) { return TLobby__sub_80145DB4(1); }
int get_link_status_value() { return TLobby__sub_80145DB4(4); }

int get_link_status() {
    NetLinkStatus link;
    if (net_session_mode == 0) {
        if (ppp_stat(&link) < 0) {
            return 0;
        }
        switch (link.state) {
        case 5:
        case 6:
        case 7:
        case 8:
            return 0;
        }
        if (actor_frame_tick % 900 == 0 && (s16)has_modem_adapter() == 0) {
            return 0;
        }
    } else {
        if (actor_frame_tick % 900 == 0 && (s16)get_link_status_value() == 0) {
            return 0;
        }
        if ((connect_pending_flags & 1) && query_link_status() == 0) {
            return 0;
        }
    }
    return 1;
}
void cleanup() {
    if (net_session_mode != 0) {
        disconnect_lan();
    } else {
        disconnect_network();
    }
    if (connect_pending_flags & 8) {
        avetcp_term();
        connect_pending_flags &= 0xFFFFFFF7;
    }
    if ((u32) avetcp_work_area != 0U) {
        xfree((void*)avetcp_work_area);
        avetcp_work_area = 0U;
    }
}
s32 init_network_and_connect() {
    NetTransportParams params;
    s32 size;
    NetSetDefaultThreadPriority(0x10);
    size = AT_GetInitParam(&params);
    params.tcp_socket_count = 1;
    params.tcp_buffer_size = 0x1000;
    params.thread_stack_size = 0x3000;
    AT_SetInitParam(&params);
    avetcp_work_area = (uaddr)xmalloc(size);
    if (avetcp_work_area != 0) {
        AT_SetWorkArea((u8 *)avetcp_work_area, size);
    }
    avetcp_init();
    connect_pending_flags |= 8;
    lobby_connect_active_flag = 0;
    dns_initialized = 0;
    if (net_session_mode != 0) {
        return run_connect_sequence();
    }
    return connect_with_any_phone_number(ppp_init());
}
void disconnect_lan(void) { flush_pending_flags(); }
void flush_pending_flags() {
    NetLinkStatus status;
    NetWaitParam stop;

    connect_pending_flags &= 0xFFFFFFFE;
    teardown_dns();
    if (TLobby__sub_80145EE4() != 0) {
        if (connect_pending_flags & 0x10) {
            DHCP_release((s16) lobby_net_session_id, lobby_local_ip_addr, 3);
            connect_pending_flags &= 0xFFFFFFEF;
            dhcp_stop();
        }
    } else if (is_state_active() != 0) {
        if (lobby_net_session_id != -1) {
            if_down(((s16) lobby_net_session_id), 0);
            stop.wait = 0;
            ppp_stop(&stop);
            do {
                ppp_stat(&status);
                send_and_handle();
            } while (status.state != 0);
        }
        if (connect_pending_flags & 4) {
            ppp_term();
            connect_pending_flags &= 0xFFFFFFFB;
        }
    }
    lobby_net_session_id = -1;
    if (connect_pending_flags & 0x20) {
        loopback_shutdown();
        connect_pending_flags &= 0xFFFFFFDF;
    }
    if (connect_pending_flags & 0x40) {
        dix_term();
        connect_pending_flags &= 0xFFFFFFBF;
    }
    if (connect_pending_flags & 0x80) {
        arp_term();
        connect_pending_flags &= 0xFFFFFF7F;
    }
}

s32 run_connect_sequence() {
    s32 sp8;
    s32 id;
    s32 r;
    s16 ok;
    connect_pending_flags &= ~1;
    clear_network_lease_time();
    if (network_config.valid != 0) {
        arp_start();
        connect_pending_flags |= 0x80;
        id = dix_init();
        connect_pending_flags |= 0x40;
        r = poll_connect();
        if (r == 0) {
            return 0xF;
        }
        if (r == 1) {
            return 0x11;
        }
        connect_pending_flags |= 1;
        AT_SetEtherNegoMode(4);
        ok = init_loopback();
        connect_pending_flags |= 0x20;
        lobby_connect_active_flag = 0;
        if (ok != 0) {
            return 0xE;
        }
        if (TLobby__sub_80145EE4() != 0) {
            lobby_net_session_id = id;
            r = apply_dhcp_network_config(&sp8);
        } else if (is_state_active() != 0) {
            r = connect_pppoe(&sp8);
        } else {
            lobby_net_session_id = id;
            r = apply_static_network_config(&sp8);
        }
        if (r == 0) {
            lobby_if_config[0] = 4;
            lobby_if_config[1] = lobby_local_ip_addr;
            lobby_if_config[2] = sp8;
            lobby_if_config[3] = 0;
            if (if_config((s16)lobby_net_session_id, lobby_if_config) == 0) {
                set_default_gateway(lobby_gateway_addr);
            } else {
                return 0xD;
            }
            return set_dns_servers();
        }
        return r;
    }
    return 0xE;
}

char *get_dialing_phone_number() { return get_modem_phone_number(phone_number_index); }

char *get_modem_phone_number(s32 idx) {
    return lobby_account_entries[2].phone[idx].number;
}

void set_ppp_password(const char *src) {
    char *password;
    TLobby__sub_8014618C();
    is_state_active();
    password = network_config.ppp_password;
    memset(password, 0, 0x20);
    strncpy(password, src, 0x1F);
}


char *get_ppp_password(void) {
    TLobby__sub_8014618C();
    is_state_active();
    return network_config.ppp_password;
}

char *get_modem_user_name(void) {
    return (char *)&modem_user_name;
}

char *get_account_user_name(s32 idx) {
    return lobby_account_entries[idx].user;
}

AccountEntry *get_account_entry(int idx) { return &lobby_account_entries[idx]; }
void load_network_configs() {
    AccountConfigRecord w;
    LanConfigRecord info;

    if (is_network_info_loaded() == 1) {
        lbl_8050CE0C[1] = 1;
    } else {
        lbl_8050CE0C[1] = 0;
    }
    if (init_work(1, (u8 *)&w) == 0) {
        strncpy(lobby_account_entries[0].host, w.host, 0x7F);
        strncpy(lobby_account_entries[0].user, w.user, 0x1F);
        strncpy(lobby_account_entries[0].phone[0].number, w.phone[0], 0x1F);
        strncpy(lobby_account_entries[0].phone[1].number, w.phone[1], 0x1F);
        strncpy(lobby_account_entries[0].phone[2].number, w.phone[2], 0x1F);
        strncpy(lobby_account_entries[0].f100, w.f16C, 0x3F);
        strncpy(lobby_account_entries[0].f140, w.f18C, 0x3F);
        strncpy(lobby_account_entries[0].f180, w.f1CC, 0x3F);
        copy_ip_address(&lobby_account_entries[0].dns1, &w.dns1);
        copy_ip_address(&lobby_account_entries[0].dns2, &w.dns2);
        lobby_account_entries[0].valid = 1;
    } else {
        lobby_account_entries[0].valid = 0;
    }
    if (init_work(2, (u8 *)&w) == 0) {
        strncpy(lobby_account_entries[1].host, w.host, 0x7F);
        strncpy(lobby_account_entries[1].user, w.user, 0x1F);
        strncpy(lobby_account_entries[1].phone[0].number, w.phone[0], 0x1F);
        strncpy(lobby_account_entries[1].phone[1].number, w.phone[1], 0x1F);
        strncpy(lobby_account_entries[1].phone[2].number, w.phone[2], 0x1F);
        strncpy(lobby_account_entries[1].f100, w.f16C, 0x3F);
        strncpy(lobby_account_entries[1].f140, w.f18C, 0x3F);
        strncpy(lobby_account_entries[1].f180, w.f1CC, 0x3F);
        copy_ip_address(&lobby_account_entries[1].dns1, &w.dns1);
        copy_ip_address(&lobby_account_entries[1].dns2, &w.dns2);
        lobby_account_entries[1].valid = 1;
    } else {
        lobby_account_entries[1].valid = 0;
    }
    if (init_work(0, (u8 *)&w) == 0) {
        strncpy(lobby_account_entries[2].host, w.host, 0x7F);
        strncpy(lobby_account_entries[2].user, w.user, 0x1F);
        strncpy(lobby_account_entries[2].phone[0].number, w.phone[0], 0x1F);
        strncpy(lobby_account_entries[2].phone[1].number, w.phone[1], 0x1F);
        strncpy(lobby_account_entries[2].phone[2].number, w.phone[2], 0x1F);
        strncpy(lobby_account_entries[2].f100, w.f16C, 0x3F);
        strncpy(lobby_account_entries[2].f140, w.f18C, 0x3F);
        strncpy(lobby_account_entries[2].f180, w.f1CC, 0x3F);
        copy_ip_address(&lobby_account_entries[2].dns1, &w.dns1);
        copy_ip_address(&lobby_account_entries[2].dns2, &w.dns2);
        lobby_account_entries[2].valid = 1;
    } else {
        lobby_account_entries[2].valid = 0;
    }
    network_config.valid = 0;
    if (net_session_mode == 1 && init_struct((u8 *)&info) == 0) {
        network_config.connection_type = info.connection_type;
        network_config.local_ip = info.ip_addr;
        network_config.netmask = info.netmask;
        network_config.fC = info.fB0;
        network_config.dns_server1 = info.dns1;
        network_config.dns_server2 = info.dns2;
        network_config.gateway = info.gateway;
        strncpy(network_config.ppp_user, info.ppp_user, 0x7F);
        strncpy(network_config.ppp_password, info.ppp_password, 0x1F);
        strncpy(network_config.dhcp_hostname, info.dhcp_hostname, 0x1F);
        strncpy(network_config.domain, info.f104, 0x3F);
        network_config.f11C = info.f244;
        network_config.valid = 1;
    }
}
void copy_ip_address(u32 *dst, const u32 *src) { *dst = *src; }
void teardown_dns() {
    if (dns_initialized != 0) {
        dns_clear_server();
        dns_term();
        dns_initialized = 0;
    }
}


struct PppPasswordBuffer { s32 value; u8 remaining[0x94]; };
extern PppPasswordBuffer ppp_password_buffer;

s32 set_dns_servers() {
    NetworkAddress req;
    s16 r1;
    s16 r2;
    if (dns_init() == 0) {
        dns_initialized = 1;
        req.family = 4;
        req.ipv4 = lobby_dns_server_addr;
        if (lobby_account_entries[2].dns1 != 0) {
            req.ipv4 = lobby_account_entries[2].dns1;
        }
        r1 = dns_set_server(&req);
        req.ipv4 = lobby_dns_server_addr2;
        if (lobby_account_entries[2].dns2 != 0) {
            req.ipv4 = lobby_account_entries[2].dns2;
        }
        r2 = dns_set_server(&req);
        OSReport(" pri_dns on ==> %d\n", r1);
        OSReport(" sec_dns on ==> %d\n", r2);
        if (r1 == 0 || r2 == 0) {
            return 0;
        }
        return 0xB;
    }
    return 0xB;
}

s32 disconnect_network(void) {
    NetWaitParam stop;

    if (lobby_net_session_id != -1) {
        if_down((s16) lobby_net_session_id, 0);
        stop.wait = 1;
        ppp_stop(&stop);
    }
    remove_default_route();
    if (connect_pending_flags & 4) {
        ppp_term();
        connect_pending_flags &= 0xFFFFFFFB;
    }
    teardown_dns();
    lobby_net_session_id = -1;
    return 0;
}

void get_link_state(s16 *state, s16 *reason) {
    NetLinkStatus status;
    if (ppp_stat(&status) < 0) {
        status.state = 0;
    }
    *state = status.state;
    *reason = status.error;
}

/* Modem dial-up connection to phone number idx of the modem account (AT+MS=V34 init command,
   or the one stored by TLobby__sub_803F5524). */
s32 connect_modem(s32 idx, s16 id) {
    NetConnectCfg cfg;
    ModemConfig modem;
    NetLinkStatus status;
    NetLinkStatus final_status;
    char dial_prefix[0x20];
    char response[0x100];
    char command[0x100];
    s16 state;
    s16 reason;
    NetWaitParam stop;
    s32 cancel;
    s32 result;
    s32 countdown;
    s32 len;
    s32 n;

    if (TLobby__sub_80145DB4(1) == 0) {
        return 6;
    }
    if (lobby_account_entries[2].valid == 0) {
        return 1;
    }
    if (lbl_8050CE0C[1] == 0) {
        return 1;
    }
    if (lobby_account_entries[2].phone[idx].number[0] == 0) {
        return 3;
    }
    lobby_net_session_id = id;
    if (id == -1) {
        return 2;
    }
    modem.send_init = 1;
    modem.dial = 1;
    modem.wait_connect = 1;
    modem.hangup = 0;
    modem.numeric_result = 0;
    modem.tone_dial_command = 0;
    modem.pulse_dial_command = 0;
    modem.answer_command = 0;
    modem.ok_response = 0;
    modem.connect_response = 0;
    modem.busy_response = 0;
    modem.error_response = 0;
    modem.delayed_response = 0;
    modem.no_carrier_response = 0;
    modem.no_dialtone_response = 0;
    modem.ring_response = 0;
    modem.terminator = '\r';
    modem.init_script = 0;
    modem.dial_script = 0;
    modem.hangup_script = 0;
    modem.modem_name = "B5";
    len = strlen("AT+MS=V34");
    memset(command, 0, sizeof(command));
    strncpy(command, "AT+MS=V34", len);
    command[len] = '\r';
    command[len + 1] = '\0';
    modem.init_count = 1;
    modem.init_command = command;
    memset(response, 0, sizeof(response));
    switch (TLobby__sub_803F5524(response, sizeof(response))) {
    case 0:
        memset(command, 0, sizeof(command));
        n = strlen(response);
        if (n < 254) {
            if (n != 0) {
                strncpy(command, response, n);
                command[n] = '\r';
                command[n + 1] = '\0';
                modem.init_count = 1;
                modem.init_command = command;
            } else {
                len = strlen("AT+MS=V34");
                memset(command, 0, sizeof(command));
                strncpy(command, "AT+MS=V34", len);
                command[len] = '\r';
                command[len + 1] = '\0';
                modem.init_count = 1;
                modem.init_command = command;
            }
        }
        break;
    case -1:
    case -2:
    case -3:
    case -5:
        return 9;
    case -4:
    default:
        break;
    }
    modem.ms_mode = 2;
    modem.error_correction = 0;
    modem.compression = 0;
    ppp_set_modem_property(&modem);
    cfg.flags = 1;
    cfg.wait = 0;
    cfg.user = lobby_account_entries[2].host;
    if (*get_modem_user_name() == 0) {
        cfg.password = get_ppp_password_buffer();
    } else {
        cfg.password = modem_user_name;
    }
    cfg.phone_number = get_modem_phone_number(idx);
    cfg.callback = 0;
    cfg.ip_mode = 4;
    cfg.h18 = 6;
    cfg.h1A = 0;
    cfg.h1C = 0;
    cfg.h1E = 3;
    cfg.h20 = 1;
    if (TLobby::is_status_zero() != 0) {
        cfg.req_type = 0;
    } else {
        cfg.req_type = 1;
    }
    cfg.req_timeout = 90;
    cfg.h2A = 0;
    cfg.h2C = 20;
    if (read_dial_prefix(dial_prefix) != 0) {
        cfg.req_has_arg = 1;
        cfg.prefix = dial_prefix;
    } else {
        cfg.req_has_arg = 0;
        cfg.prefix = 0;
    }
    cfg.auth_mode = 4;
    cfg.mtu = 1500;
    cfg.start_tick = 0x12345678;
    cfg.no_acfc = 0;
    cfg.no_pfc = 0;
    cfg.vj_disabled = 1;
    cfg.addr_local = 0;
    cfg.addr_peer = 0;
    cfg.dns_local_primary = 0;
    cfg.dns_local_secondary = 0;
    cfg.dns_peer_primary = 0;
    cfg.dns_peer_secondary = 0;
    ppp_start(&cfg);
    connect_pending_flags |= 4;
    state = -1;
    cancel = 0;
    result = 0x10;
    countdown = 0;
    do {
        if (countdown == 0) {
            if (test_pressed_buttons_packed(&controller_input_state.controllers[0], 2) != 0 ||
                TKeyBoardControl::read_key_checked(0x4C) != 0) {
                cancel = 1;
                result = 0x10;
            }
            if (static_cast<s8>(poll_reset_request()) != 0) {
                cancel = 1;
                result = 0x11;
            }
        } else {
            countdown--;
        }
        get_link_state(&state, &reason);
        if (state == 5 || state == 8 || state == 4) {
            break;
        }
        if (cancel != 0) {
            break;
        }
        send_and_handle();
    } while (state != 4);
    if (state == 4 && cancel == 0) {
        ppp_stat(&status);
        lobby_if_config[0] = 4;
        lobby_if_config[1] = status.addr_local;
        lobby_if_config[2] = 0;
        lobby_if_config[3] = 0;
        if_config((s16)lobby_net_session_id, lobby_if_config);
        set_default_gateway(status.addr_local);
        lobby_dns_server_addr = status.dns_local_primary;
        lobby_dns_server_addr2 = status.dns_local_secondary;
        return set_dns_servers();
    }
    lobby_net_session_id = -1;
    stop.wait = 0;
    ppp_stop(&stop);
    do {
        ppp_stat(&final_status);
        send_and_handle();
    } while (final_status.state != 0);
    if (cancel != 0) {
        return result;
    }
    switch (reason) {
    case 3:
        return 5;
    case 2:
        return 7;
    case 6:
        return 8;
    case 0:
    case 1:
    case 7:
    default:
        return 4;
    }
}


s32 connect_with_any_phone_number(s32 id) {
    s32 count;
    s32 result;
    char name[0x81];
    result = 4;
    count = get_phone_number_count();
    for (phone_number_index = 0; phone_number_index < count; phone_number_index++) {
        memset(name, 0, sizeof(name));
        strncpy(name, get_modem_phone_number(phone_number_index), sizeof(name));
        if (name[0] != 0) {
            result = connect_modem(phone_number_index, id);
            if (should_try_next_phone_number(result) == 0) {
                return result;
            }
        }
    }
    return result;
}

void TLobby__sub_80147978(void) {  }
void init_account_entries() {
    memset(&lobby_account_entries[0], 0, sizeof(AccountEntry));
    memset(&lobby_account_entries[1], 0, sizeof(AccountEntry));
    memset(&lobby_account_entries[2], 0, sizeof(AccountEntry));
    lobby_account_entries[0].valid = 0;
    lobby_account_entries[1].valid = 0;
    lobby_account_entries[2].valid = 0;
    lbl_805D5714 = 0;
    net_session_mode = 0;
    connect_pending_flags = 0;
    if (TLobby__sub_8014618C() != 0) {
        net_session_mode = 1;
    }
    load_network_configs();
    memset(modem_user_name, 0, 0x20);
    strncpy(modem_user_name, lobby_account_entries[2].user, 0x1F);
    memset(account_user_copy, 0, 0x20);
    strncpy(account_user_copy, lobby_account_entries[0].user, 0x1F);
}

void set_network_lease_time(s32 seconds) { network_lease_time = seconds; }

void clear_network_lease_time(void) { network_lease_time = 0; }
char *get_ppp_password_buffer(void) {
    return (char *)&ppp_password_buffer.value;
}
