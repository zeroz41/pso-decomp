#ifndef PSO_NETWORK_NETWORKCONNECT_H
#define PSO_NETWORK_NETWORKCONNECT_H

#include "types.h"

struct PhoneNumber {
    char number[0x20];
};

// A dial-up account; load_network_configs fills three of them, [2] is the modem account.
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

// The account settings init_work reads from the network configuration.
struct AccountConfigRecord {
    s32 f0;
    char host[0x80];
    char user[0x20];
    char phone[3][0x40];
    u32 dns1;
    u32 dns2;
    char f16C[0x20];
    char f18C[0x40];
    char f1CC[0x40];
    u8 pad[0x274 - 0x20C];
};

// The broadband adapter settings init_struct reads from the network configuration.
struct LanConfigRecord {
    s32 f0;
    s32 connection_type; /* 0 DHCP, 1 PPPoE, otherwise a fixed address */
    char ppp_user[0x80];
    char ppp_password[0x20];
    s32 ip_addr;
    s32 netmask;
    s32 fB0;
    s32 dns1;
    s32 dns2;
    s32 gateway;
    s32 fC0;
    char dhcp_hostname[0x40];
    char domain[0x40];
    u8 pad_144[0x100];
    u16 f244;
    u8 pad[0x26C - 0x246];
};

// The broadband connection settings run_connect_sequence brings the adapter up with.
struct NetworkConfig {
    s32 connection_type;
    s32 local_ip;
    s32 netmask;
    s32 fC;
    s32 dns_server1;
    s32 dns_server2;
    s32 gateway;
    char dhcp_hostname[0x20];
    char domain[0x40];
    char ppp_user[0x80];
    char ppp_password[0x20];
    u16 f11C;
    s32 valid; /* 1 once load_network_configs read the settings */
};
LAYOUT_ASSERT(NetworkConfig_size, sizeof(NetworkConfig) == 0x124);

// --- C functions defined in NetworkConnect.cpp ---
extern "C" {
void TLobby__sub_80147978(void);
}
int has_modem_adapter(void);
s32 apply_static_network_config(s32 *netmask);
s32 apply_dhcp_network_config(s32 *netmask);
s32 should_try_next_phone_number(u32 result);
int get_phone_number_count(void);
void get_local_ip_address(s32 *out_addr);
s32 init_network_and_connect(void);
void disconnect_lan(void);
char *get_ppp_password(void);
char *get_modem_user_name(void);
char *get_account_user_name(s32 idx);
void copy_ip_address(u32 *dst, const u32 *src);
s32 disconnect_network(void);
s32 connect_with_any_phone_number(s32 id);
// What follows the online character save: 0 asks the server for the time, 1 and 2
// close the lobby with state 0x13 or 0x14. Always 0 in this build.
int get_post_save_lobby_action();
s32 connect_modem(s32 idx, s16 id);
s32 connect_pppoe(s32 *out_value);
void set_network_lease_time(s32 seconds);
void clear_network_lease_time(void);
AccountEntry *get_account_entry(int idx);
void get_link_state(s16 *state, s16 *reason);
int get_link_status();
char *get_modem_phone_number(s32 idx);
void init_keyboard_buffer();
s32 poll_connect();
void remove_default_route();
void set_default_gateway(s32 gateway);
s32 query_task_active();
int get_link_status_value();
void cleanup();
void flush_pending_flags();
s32 run_connect_sequence();
char *get_dialing_phone_number();
void set_ppp_password(const char *src);
void load_network_configs();
void teardown_dns();
s32 set_dns_servers();
void init_account_entries();
char *get_ppp_password_buffer(void);
// --- end of C functions

extern s32 net_session_mode;

extern s32 lbl_805D5718;
#endif
