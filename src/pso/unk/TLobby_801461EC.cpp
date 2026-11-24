#include "types.h"
#include "pso/unk/TLobby.h"
#include "pso/network/TLobby_803FAEA0.h"
#include "pso/network/TLobby_804050DC.h"
#include "pso/network/text_80421620.h"
#include "pso/network/NetworkRuntime.h"
#include "pso/network/NetworkTransport.h"
#include "pso/network/NetworkMessageTransport.h"
#include "pso/network/NetworkPacketPool.h"
#include "pso/network/NetDhcp.h"
#include "pso/network/TLobby_80428374.h"
#include "pso/unk/text_80145A44.h"
#include "pso/unk/text_803F4D84.h"
#include <string.h>
#include <string.h>
#include "pso/system/memory.h"
#include "pso/ui/keyboard/TKeyBoardControl.h"
#include "pso/system/ControllerInputState.h"
#include "pso/system/ControllerInput.h"

struct RecoveredGlobal_8014672C_lbl_8050C0A8 {
    s32 value;
    u8 remaining[0x6D8];
};

extern "C" {
s32 TLobby__sub_80407358();
s32 loopback_shutdown();
void dhcp_stop(void);
s32 DHCP_release(s32 session, s32 ip, s32 retries);
void TLobby__sub_801469B8(void* p);
void *get_account_entry(int idx);
void TLobby__sub_8014715C(void* p, void* q);
s32 dns_term();
saddr lobby_local_ip_addr;
s32 lobby_dns_server_addr;
s32 lobby_dns_server_addr2;
s32 lobby_gateway_addr;
s32 lbl_805D56E8;
s32 lbl_805D56EC;
s32 lbl_805D56F0;
s32 lbl_805D56F4;
s32 connect_pending_flags;
s32 lobby_default_gateway;
uaddr lbl_805D5700;
s32 net_session_mode;
int lbl_805D5708;
s32 lbl_805D570C;
s32 lobby_connect_active_flag;
s32 lbl_805D5714;
s32 lbl_805D5718;
s32 TLobby__sub_8014618C(void);
void TLobby__sub_8014672C(s32 *arg0);
s32 TLobby__sub_80146588(s32 *arg0);
u8 *TLobby__sub_80146D14(void);
char *TLobby__sub_80146D44(void);
char *TLobby__sub_80146D50(s32 idx);
s32 TLobby__sub_801466F4(u32 arg0);
s32 TLobby__sub_80145EE4(void);
s32 TLobby__sub_801465C0(s32 *);
void fn_80147A68(void);
void TLobby__sub_804073B8(void);
s16 init_loopback(void);
s16 if_config(s16, void *);
s32 lobby_net_session_id = -1;
s32 TLobby__sub_801478C4(s32 id);
}
char *get_modem_phone_number(s32 idx);
s32 connect_pppoe(s32 *);
s32 connect_modem(s32 idx, s16 id);
extern s32 actor_frame_tick;

struct Sub_801465C0 {
    u8 pad0[0x1C];
    char name[0x124 - 0x1C];
};

struct PhoneNumber {
    char number[0x20];
};

struct AccountEntry {
    char host[0x80];
    char user[0x20];
    PhoneNumber phone[3]; /* dial-up numbers (get_modem_phone_number, connect_modem) */
    char f100[0x40];
    char f140[0x40];
    char f180[0x40];
    u32 dns1; /* primary DNS server address (set_dns_servers) */
    u32 dns2; /* secondary DNS server address */
    s32 valid;
};
struct Work_80146D7C {
    s32 f0;
    char host[0x80];
    char user[0x20];
    char pass[0x40];
    char dns1[0x40];
    char dns2[0x40];
    u32 f164;
    u32 f168;
    char f16C[0x20];
    char f18C[0x40];
    char f1CC[0x40];
    u8 pad[0x274 - 0x20C];
};
struct Conn_80146D7C {
    s32 f0;
    s32 f4, f8, fC, f10, f14, f18;
    char f1C[0x20];
    char f3C[0x40];
    char f7C[0x80];
    char fFC[0x20];
    u16 f11C;
    s32 f120;
};
struct Info_80146D7C {
    s32 f0;
    s32 f4;
    char f8[0x80];
    char f88[0x20];
    s32 fA8, fAC, fB0, fB4, fB8, fBC;
    s32 fC0;
    char fC4[0x40];
    char f104[0x140];
    u16 f244;
    u8 pad[0x26C - 0x246];
};

extern "C" {
void fn_80147A60(int a0);
s16 DHCP_init(s16);
int TLobby__sub_80145E40(void);
int TLobby__sub_80146724(void);
int TLobby__sub_80146740(void);
int TLobby__sub_8014677C(void);
s32 load_network_info(void);
s32 TLobby__sub_80145DB4(s32 arg0);
s32 TLobby__sub_80147284();
s32 route4_del(saddr, saddr, saddr);
s32 route4_add(saddr, saddr, saddr);

    extern void *lbl_805D56C8;
    extern short lbl_805D56CE;
    extern int keyboard_buffer_cursor;
u32 lbl_8050C0A8[7];
u32 lbl_8050C0C4[368];
u32 lbl_8050C684[64];
AccountEntry lobby_account_entries[3]; /* cleared by TLobby::init_account_entries, filled by load_network_configs; [2] is the modem account */
u32 lbl_8050CCE8[73];
__declspec(section ".data") s32 lbl_8050CE0C[2];
}
s32 init_struct(u8 *arg0);
s32 init_work(s32 arg0, u8 *arg1);
s32 get_network_config_buffer_size(s32 mode);
char lbl_8050CE14[0x20];
char lbl_8050CE34[0x20];
u8 lbl_8050CE54[0x114];
#define lbl_8050C0A8 (*(RecoveredGlobal_8014672C_lbl_8050C0A8 *)lbl_8050C0A8)

void TLobby::init_keyboard_buffer() {
    keyboard_buffer_cursor = 0;
    lbl_805D56CE = 0;
    lbl_805D56C8 = NULL;
    lbl_805D56C8 = xmalloc(get_network_config_buffer_size(0));
    load_network_info();
}

s32 TLobby::poll_connect() {
    s32 var_r31;

    var_r31 = 0;
loop_1:
    if (var_r31 > 0x12C) {
        return 0;
    }
    var_r31 += 1;
    TLobby::send_and_handle();
    if (static_cast<s8>(func_801A5E54()) != 0) {
        return 1;
    }
    if (query_link_status() == 1) {
        return 2;
    }
    goto loop_1;
}


void TLobby::remove_default_route() {
    if (connect_pending_flags & 2) {
        route4_del(0, 0, lobby_default_gateway);
        connect_pending_flags &= 0xFFFFFFFD;
    }
}

void TLobby::set_default_gateway(s32 gateway) {
    lobby_default_gateway = gateway;
    connect_pending_flags |= 2;
    route4_add(0, 0, gateway);
}

void get_link_state(s16 *state, s16 *reason);

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
    cfg.wC = (char *)&lbl_8050CCE8 + 0x7C;
    cfg.password = (char *)&lbl_8050CCE8 + 0xFC;
    cfg.callback = 0;
    cfg.h2 = 4;
    cfg.h18 = 6;
    cfg.h1A = 0;
    cfg.h1C = 0;
    cfg.h1E = 3;
    cfg.h20 = 1;
    cfg.h28 = 90;
    cfg.h2A = 0;
    cfg.h2C = 20;
    cfg.phone_number = 0;
    cfg.h24 = 0;
    cfg.h26 = 0;
    cfg.prefix = 0;
    cfg.h34 = 4;
    cfg.mtu = 1500;
    cfg.start_tick = 0x12345678;
    cfg.h3C = 0;
    cfg.h3E = 0;
    cfg.h40 = 1;
    cfg.w44 = 0;
    cfg.w48 = 0;
    cfg.w4C = 0;
    cfg.w50 = 0;
    cfg.w54 = 0;
    cfg.w58 = 0;
    NetControl(1, 10);
    ppp_start(&cfg);
    state = -1;
    do {
        cancel = 0;
        if (test_pressed_buttons_packed(&controller_input_state.controllers[0], 2) != 0 ||
            TKeyBoardControl::read_key_checked(0x4C) != 0) {
            cancel = 1;
            result = 0x10;
        }
        if (static_cast<s8>(func_801A5E54()) != 0) {
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
        TLobby::send_and_handle();
    } while (state != 4);
    if (state == 4) {
        NetGetLinkStatus(&status);
        lobby_local_ip_addr = status.w10;
        *out_value = 0;
        lobby_dns_server_addr = status.w18;
        lobby_dns_server_addr2 = status.w1C;
        lobby_gateway_addr = status.w10;
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


s32 TLobby__sub_80146588(s32 *arg0) {
    lobby_local_ip_addr = *(s32 *)((s8 *)&lbl_8050CCE8 + 4);
    *(s32 *)((s8 *)arg0 + 0) = *(s32 *)((s8 *)&lbl_8050CCE8 + 8);
    lobby_gateway_addr = *(s32 *)((s8 *)&lbl_8050CCE8 + 0x18);
    lobby_dns_server_addr = *(s32 *)((s8 *)&lbl_8050CCE8 + 0x10);
    lobby_dns_server_addr2 = *(s32 *)((s8 *)&lbl_8050CCE8 + 0x14);
    return 0;
}

s32 TLobby__sub_801465C0(s32 *netmask) {
    s32 broadcast;

    if (DHCP_init((s16)lobby_net_session_id) != 0) {
        return 0xC;
    }
    Sub_801465C0 *sub = (Sub_801465C0 *)&lbl_8050CCE8;
    connect_pending_flags |= 0x10;
    lobby_connect_active_flag = 1;
    char *name = sub->name;
    if (*name != 0 && DHCP_hostname(name) < 0) {
        return 0xC;
    }
    lobby_local_ip_addr = 0;
    lbl_805D56E8 = 0;
    if (dhcp_discover_and_request((s16)lobby_net_session_id, 0, 0, lbl_8050C0C4, &lobby_local_ip_addr, netmask, &broadcast, 3) != 0) {
        return 0xC;
    }
    if (DHCP_get_gateway(lbl_8050C0C4, &lobby_gateway_addr) != 0) {
        return 0xC;
    }
    if (TLobby__sub_8042474C(&lbl_805D56EC, &lbl_805D56F0, &lbl_805D56F4) != 0) {
        return 0xC;
    }
    fn_80147A60(lbl_805D56EC);
    return DHCP_get_dns(lbl_8050C0C4, (char *)lbl_8050C684, &lobby_dns_server_addr, &lobby_dns_server_addr2) != 0 ? 0xC : 0;
}

s32 TLobby__sub_801466F4(u32 arg0) {
    switch (arg0) {
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

int TLobby__sub_80146724(void) { return 3; }

LAYOUT_ASSERT(RecoveredGlobal_8014672C_lbl_8050C0A8_size, sizeof(RecoveredGlobal_8014672C_lbl_8050C0A8) == 0x6DC);
void TLobby__sub_8014672C(s32 *arg0) {
    *(s32 *)((s8 *)arg0 + 0) = *(s32 *)((s8 *)&lbl_8050C0A8.value + 4);
}

int TLobby__sub_80146740(void) { return 0; }

s32 TLobby::query_task_active() {
    if ((s32) lobby_connect_active_flag != 0) {
        return get_task_count();
    }
    return 0;
}

int TLobby__sub_8014677C(void) { return TLobby__sub_80145DB4(1); }
int TLobby::get_link_status_value() { return TLobby__sub_80145DB4(4); }

int get_link_status() {
    NetLinkStatus link;
    if (net_session_mode == 0) {
        if (NetGetLinkStatus(&link) < 0) {
            return 0;
        }
        switch (link.state) {
        case 5:
        case 6:
        case 7:
        case 8:
            return 0;
        }
        if (actor_frame_tick % 900 == 0 && (s16)TLobby__sub_8014677C() == 0) {
            return 0;
        }
    } else {
        if (actor_frame_tick % 900 == 0 && (s16)TLobby::get_link_status_value() == 0) {
            return 0;
        }
        if ((connect_pending_flags & 1) && query_link_status() == 0) {
            return 0;
        }
    }
    return 1;
}
void TLobby::cleanup() {
    if ((s32) net_session_mode != 0) {
        TLobby__sub_801469B8(this);
    } else {
        TLobby__sub_80147284();
    }
    if (connect_pending_flags & 8) {
        avetcp_term();
        connect_pending_flags &= 0xFFFFFFF7;
    }
    if ((u32) lbl_805D5700 != 0U) {
        xfree((void*)lbl_805D5700);
        lbl_805D5700 = 0U;
    }
}
extern "C" {
s32 TLobby__sub_80146908() {
    NetTransportParams params;
    s32 size;
    NetSetDefaultThreadPriority(0x10);
    size = AT_GetInitParam(&params);
    params.room_count = 1;
    params.e = 0x1000;
    params.f = 0x3000;
    AT_SetInitParam(&params);
    lbl_805D5700 = (uaddr)xmalloc(size);
    if (lbl_805D5700 != 0) {
        AT_SetWorkArea((u8 *)lbl_805D5700, size);
    }
    avetcp_init();
    connect_pending_flags |= 8;
    lobby_connect_active_flag = 0;
    lbl_805D570C = 0;
    if (net_session_mode != 0) {
        return TLobby::run_connect_sequence();
    }
    return TLobby__sub_801478C4(ppp_init());
}
void TLobby__sub_801469B8(void* p) { TLobby::flush_pending_flags(); }
}
void TLobby::flush_pending_flags() {
    NetLinkStatus status;
    NetWaitParam stop;

    connect_pending_flags &= 0xFFFFFFFE;
    TLobby::teardown_boss2();
    if (TLobby__sub_80145EE4() != 0) {
        if (connect_pending_flags & 0x10) {
            DHCP_release((s16) lobby_net_session_id, lobby_local_ip_addr, 3);
            connect_pending_flags &= 0xFFFFFFEF;
            dhcp_stop();
        }
    } else if (TLobby::is_state_active() != 0) {
        if ((s32) lobby_net_session_id != -1) {
            if_down(((s16) lobby_net_session_id), 0);
            stop.wait = 0;
            ppp_stop(&stop);
            do {
                NetGetLinkStatus(&status);
                TLobby::send_and_handle();
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
        flush_flags_step();
        connect_pending_flags &= 0xFFFFFFBF;
    }
    if (connect_pending_flags & 0x80) {
        TLobby__sub_80407358();
        connect_pending_flags &= 0xFFFFFF7F;
    }
}

s32 TLobby::run_connect_sequence() {
    s32 sp8;
    s32 id;
    s32 r;
    s16 ok;
    connect_pending_flags &= ~1;
    fn_80147A68();
    if (*(s32 *)((u8 *)&lbl_8050CCE8 + 0x120) != 0) {
        TLobby__sub_804073B8();
        connect_pending_flags |= 0x80;
        id = run_connect_step();
        connect_pending_flags |= 0x40;
        r = TLobby::poll_connect();
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
            r = TLobby__sub_801465C0(&sp8);
        } else if (TLobby::is_state_active() != 0) {
            r = connect_pppoe(&sp8);
        } else {
            lobby_net_session_id = id;
            r = TLobby__sub_80146588(&sp8);
        }
        if (r == 0) {
            s32 *m = (s32 *)&lbl_8050C0A8;
            m[0] = 4;
            m[1] = lobby_local_ip_addr;
            m[2] = sp8;
            m[3] = 0;
            if (if_config((s16)lobby_net_session_id, &lbl_8050C0A8) == 0) {
                TLobby::set_default_gateway(lobby_gateway_addr);
            } else {
                return 0xD;
            }
            return TLobby::set_dns_servers();
        }
        return r;
    }
    return 0xE;
}

void TLobby::call_146CA0_with_5708() { get_modem_phone_number(lbl_805D5708); }

char *get_modem_phone_number(s32 idx) {
    return lobby_account_entries[2].phone[idx].number;
}

void TLobby::set_ppp_password(const char *src) {
    u8 *temp_r31;
    TLobby__sub_8014618C();
    TLobby::is_state_active();
    temp_r31 = (u8 *)&lbl_8050CCE8 + 0xFC;
    memset(temp_r31, 0, 0x20);
    strncpy((char *)temp_r31, src, 0x1F);
}


u8 *TLobby__sub_80146D14(void) {
    TLobby__sub_8014618C();
    TLobby::is_state_active();
    return (u8 *)&lbl_8050CCE8 + 0xFC;
}

char *TLobby__sub_80146D44(void) {
    return (char *)&lbl_8050CE14;
}

char *TLobby__sub_80146D50(s32 idx) {
    return lobby_account_entries[idx].user;
}

void *get_account_entry(int idx) { return &lobby_account_entries[idx]; }
#define C_80146D7C (*(Conn_80146D7C *)&lbl_8050CCE8)
void TLobby::load_network_configs() {
    Work_80146D7C w;
    Info_80146D7C info;

    if (TLobby__sub_80145E40() == 1) {
        lbl_8050CE0C[1] = 1;
    } else {
        lbl_8050CE0C[1] = 0;
    }
    if (init_work(1, (u8 *)&w) == 0) {
        strncpy(lobby_account_entries[0].host, w.host, 0x7F);
        strncpy(lobby_account_entries[0].user, w.user, 0x1F);
        strncpy(lobby_account_entries[0].phone[0].number, w.pass, 0x1F);
        strncpy(lobby_account_entries[0].phone[1].number, w.dns1, 0x1F);
        strncpy(lobby_account_entries[0].phone[2].number, w.dns2, 0x1F);
        strncpy(lobby_account_entries[0].f100, w.f16C, 0x3F);
        strncpy(lobby_account_entries[0].f140, w.f18C, 0x3F);
        strncpy(lobby_account_entries[0].f180, w.f1CC, 0x3F);
        TLobby__sub_8014715C(&lobby_account_entries[0].dns1, &w.f164);
        TLobby__sub_8014715C(&lobby_account_entries[0].dns2, &w.f168);
        lobby_account_entries[0].valid = 1;
    } else {
        lobby_account_entries[0].valid = 0;
    }
    if (init_work(2, (u8 *)&w) == 0) {
        strncpy(lobby_account_entries[1].host, w.host, 0x7F);
        strncpy(lobby_account_entries[1].user, w.user, 0x1F);
        strncpy(lobby_account_entries[1].phone[0].number, w.pass, 0x1F);
        strncpy(lobby_account_entries[1].phone[1].number, w.dns1, 0x1F);
        strncpy(lobby_account_entries[1].phone[2].number, w.dns2, 0x1F);
        strncpy(lobby_account_entries[1].f100, w.f16C, 0x3F);
        strncpy(lobby_account_entries[1].f140, w.f18C, 0x3F);
        strncpy(lobby_account_entries[1].f180, w.f1CC, 0x3F);
        TLobby__sub_8014715C(&lobby_account_entries[1].dns1, &w.f164);
        TLobby__sub_8014715C(&lobby_account_entries[1].dns2, &w.f168);
        lobby_account_entries[1].valid = 1;
    } else {
        lobby_account_entries[1].valid = 0;
    }
    if (init_work(0, (u8 *)&w) == 0) {
        strncpy(lobby_account_entries[2].host, w.host, 0x7F);
        strncpy(lobby_account_entries[2].user, w.user, 0x1F);
        strncpy(lobby_account_entries[2].phone[0].number, w.pass, 0x1F);
        strncpy(lobby_account_entries[2].phone[1].number, w.dns1, 0x1F);
        strncpy(lobby_account_entries[2].phone[2].number, w.dns2, 0x1F);
        strncpy(lobby_account_entries[2].f100, w.f16C, 0x3F);
        strncpy(lobby_account_entries[2].f140, w.f18C, 0x3F);
        strncpy(lobby_account_entries[2].f180, w.f1CC, 0x3F);
        TLobby__sub_8014715C(&lobby_account_entries[2].dns1, &w.f164);
        TLobby__sub_8014715C(&lobby_account_entries[2].dns2, &w.f168);
        lobby_account_entries[2].valid = 1;
    } else {
        lobby_account_entries[2].valid = 0;
    }
    C_80146D7C.f120 = 0;
    if (net_session_mode == 1 && init_struct((u8 *)&info) == 0) {
        C_80146D7C.f0 = info.f4;
        C_80146D7C.f4 = info.fA8;
        C_80146D7C.f8 = info.fAC;
        C_80146D7C.fC = info.fB0;
        C_80146D7C.f10 = info.fB4;
        C_80146D7C.f14 = info.fB8;
        C_80146D7C.f18 = info.fBC;
        strncpy(C_80146D7C.f7C, info.f8, 0x7F);
        strncpy(C_80146D7C.fFC, info.f88, 0x1F);
        strncpy(C_80146D7C.f1C, info.fC4, 0x1F);
        strncpy(C_80146D7C.f3C, info.f104, 0x3F);
        C_80146D7C.f11C = info.f244;
        C_80146D7C.f120 = 1;
    }
}
#undef A_80146D7C
#undef C_80146D7C
void TLobby__sub_8014715C(void* p, void* q) { *(u32*)((char*)p + 0x0) = *(u32*)((char*)q + 0x0); }
void TLobby::teardown_boss2() {
    if ((s32) lbl_805D570C != 0) {
        clear_all_used_records();
        dns_term();
        lbl_805D570C = 0;
    }
}

#undef lbl_8050C0A8

struct Req_801471A0 { s32 type; u32 addr; u8 pad[0x18]; };

struct PppPasswordBuffer { s32 value; u8 remaining[0x94]; };
extern PppPasswordBuffer ppp_password_buffer;
char *get_ppp_password_buffer(void);
extern "C" {
void OSReport(const char *, ...);
s16 TLobby__sub_8040ADE8(Req_801471A0 *);
s32 TLobby__sub_80147284(void);
void TLobby__sub_80147978(void);


s32 TLobby::set_dns_servers() {
    Req_801471A0 req;
    s16 r1;
    s16 r2;
    if (init_net_tables() == 0) {
        lbl_805D570C = 1;
        req.type = 4;
        req.addr = lobby_dns_server_addr;
        if (lobby_account_entries[2].dns1 != 0) {
            req.addr = lobby_account_entries[2].dns1;
        }
        r1 = TLobby__sub_8040ADE8(&req);
        req.addr = lobby_dns_server_addr2;
        if (lobby_account_entries[2].dns2 != 0) {
            req.addr = lobby_account_entries[2].dns2;
        }
        r2 = TLobby__sub_8040ADE8(&req);
        OSReport(" pri_dns on ==> %d\n", r1);
        OSReport(" sec_dns on ==> %d\n", r2);
        if (r1 == 0 || r2 == 0) {
            return 0;
        }
        return 0xB;
    }
    return 0xB;
}

s32 TLobby__sub_80147284(void) {
    NetWaitParam stop;

    if ((s32) lobby_net_session_id != -1) {
        if_down((s16) lobby_net_session_id, 0);
        stop.wait = 1;
        ppp_stop(&stop);
    }
    TLobby::remove_default_route();
    if (connect_pending_flags & 4) {
        ppp_term();
        connect_pending_flags &= 0xFFFFFFFB;
    }
    TLobby::teardown_boss2();
    lobby_net_session_id = -1;
    return 0;
}
}

void get_link_state(s16 *state, s16 *reason) {
    NetLinkStatus status;
    if (NetGetLinkStatus(&status) < 0) {
        status.state = 0;
    }
    *state = status.state;
    *reason = status.h6;
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
    modem.h0 = 1;
    modem.h2 = 1;
    modem.h4 = 1;
    modem.h6 = 0;
    modem.numeric_result = 0;
    modem.prefix0 = 0;
    modem.prefix1 = 0;
    modem.w14 = 0;
    modem.w18 = 0;
    modem.result_ok = 0;
    modem.result_error = 0;
    modem.result_busy = 0;
    modem.result_no_dialtone = 0;
    modem.result_no_carrier = 0;
    modem.result_no_answer = 0;
    modem.w34 = 0;
    modem.terminator = '\r';
    modem.w3C = 0;
    modem.w40 = 0;
    modem.w44 = 0;
    modem.s48 = "B5";
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
    modem.w4C = 2;
    modem.w50 = 0;
    modem.w54 = 0;
    copy_name_buffer(&modem);
    cfg.flags = 1;
    cfg.wait = 0;
    cfg.wC = lobby_account_entries[2].host;
    if (*TLobby__sub_80146D44() == 0) {
        cfg.password = get_ppp_password_buffer();
    } else {
        cfg.password = lbl_8050CE14;
    }
    cfg.phone_number = get_modem_phone_number(idx);
    cfg.callback = 0;
    cfg.h2 = 4;
    cfg.h18 = 6;
    cfg.h1A = 0;
    cfg.h1C = 0;
    cfg.h1E = 3;
    cfg.h20 = 1;
    if (TLobby::is_status_zero() != 0) {
        cfg.h24 = 0;
    } else {
        cfg.h24 = 1;
    }
    cfg.h28 = 90;
    cfg.h2A = 0;
    cfg.h2C = 20;
    if (fn_80145A44(dial_prefix) != 0) {
        cfg.h26 = 1;
        cfg.prefix = dial_prefix;
    } else {
        cfg.h26 = 0;
        cfg.prefix = 0;
    }
    cfg.h34 = 4;
    cfg.mtu = 1500;
    cfg.start_tick = 0x12345678;
    cfg.h3C = 0;
    cfg.h3E = 0;
    cfg.h40 = 1;
    cfg.w44 = 0;
    cfg.w48 = 0;
    cfg.w4C = 0;
    cfg.w50 = 0;
    cfg.w54 = 0;
    cfg.w58 = 0;
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
            if (static_cast<s8>(func_801A5E54()) != 0) {
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
        TLobby::send_and_handle();
    } while (state != 4);
    if (state == 4 && cancel == 0) {
        NetGetLinkStatus(&status);
        lbl_8050C0A8[0] = 4;
        lbl_8050C0A8[1] = status.w10;
        lbl_8050C0A8[2] = 0;
        lbl_8050C0A8[3] = 0;
        if_config((s16)lobby_net_session_id, lbl_8050C0A8);
        TLobby::set_default_gateway(status.w10);
        lobby_dns_server_addr = status.w18;
        lobby_dns_server_addr2 = status.w1C;
        return TLobby::set_dns_servers();
    }
    lobby_net_session_id = -1;
    stop.wait = 0;
    ppp_stop(&stop);
    do {
        NetGetLinkStatus(&final_status);
        TLobby::send_and_handle();
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


s32 TLobby__sub_801478C4(s32 id) {
    s32 count;
    s32 result;
    char name[0x81];
    result = 4;
    count = TLobby__sub_80146724();
    for (lbl_805D5708 = 0; lbl_805D5708 < count; lbl_805D5708++) {
        memset(name, 0, sizeof(name));
        strncpy(name, get_modem_phone_number(lbl_805D5708), sizeof(name));
        if (name[0] != 0) {
            result = connect_modem(lbl_805D5708, id);
            if (TLobby__sub_801466F4(result) == 0) {
                return result;
            }
        }
    }
    return result;
}

void TLobby__sub_80147978(void) {  }
void TLobby::init_account_entries() {
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
    TLobby::load_network_configs();
    memset(lbl_8050CE14, 0, 0x20);
    strncpy(lbl_8050CE14, lobby_account_entries[2].user, 0x1F);
    memset(lbl_8050CE34, 0, 0x20);
    strncpy(lbl_8050CE34, lobby_account_entries[0].user, 0x1F);
}

void fn_80147A60(int a0) { keyboard_buffer_cursor = a0; }

void fn_80147A68(void) { keyboard_buffer_cursor = 0; }
char *get_ppp_password_buffer(void) {
    return (char *)&ppp_password_buffer.value;
}
